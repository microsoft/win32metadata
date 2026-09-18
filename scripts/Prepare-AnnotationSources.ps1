[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$Partition,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [string]$CacheDirectory = "$PSScriptRoot\..\generation\WinSDK\obj\annotation-sources"
)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$cache = [IO.Path]::GetFullPath($CacheDirectory)
$relativeCache = [IO.Path]::GetRelativePath($root, $cache)
if ($relativeCache -eq '..' -or $relativeCache.StartsWith('..\') -or [IO.Path]::IsPathRooted($relativeCache)) {
    throw 'Source cache must be inside this worktree so patch application cannot escape it.'
}
$main = Join-Path $root "generation\WinSDK\Partitions\$Partition\main.cpp"
if (-not (Test-Path $main)) { throw "Unknown canonical partition: $Partition" }
. "$PSScriptRoot\WinSdkMidlConfig.ps1"
$pins = Get-Content (Join-Path $root 'generation\WinSDK\rollout\pins.json') -Raw | ConvertFrom-Json
$packages = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $HOME '.nuget\packages' }
$sdk = Join-Path $packages "microsoft.windows.sdk.cpp\$($pins.sdkVersion)\c\Include\$($pins.sdkIncludeVersion)"
$sdkBin = Join-Path $packages "microsoft.windows.sdk.cpp\$($pins.sdkVersion)\c\bin\$($pins.sdkIncludeVersion)\x86"
$midl = Join-Path $sdkBin 'midl.exe'
$libclang = Join-Path $packages "libclang.runtime.win-x64\$($pins.libclangVersion)\runtimes\win-x64\native\libclang.dll"
$project = [xml](Get-Content (Join-Path $root 'BuildTools\BuildTools.proj') -Raw)
$d3dVersion = @($project.Project.ItemGroup.PackageReference | Where-Object Include -EQ 'Microsoft.Direct3D.D3D12')[0].Version
$d3d = Join-Path $packages "microsoft.direct3d.d3d12\$d3dVersion\build\native\include"
$vs = & "$PSScriptRoot\Get-VSPath.ps1"
$vcVersion = (Get-Content (Join-Path $vs 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt') -Raw).Trim()
$vcRoot = Join-Path $vs "VC\Tools\MSVC\$vcVersion"
$compilerInclude = Join-Path $vcRoot 'include'
$cpp = Join-Path $vcRoot 'bin\Hostx86\x86\cl.exe'
foreach ($path in @($sdk,$d3d,$midl,$libclang,$cpp,$compilerInclude,$ResourceDirectory)) {
    if (-not (Test-Path $path)) { throw "Missing preparation prerequisite: $path. Restore BuildTools or install the selected compiler before retrying." }
}
if ((Get-FileHash $libclang).Hash -cne $pins.libclangSha256) { throw 'libclang pin mismatch.' }
function Fact([string]$Path) {
    [ordered]@{path=[IO.Path]::GetFullPath($Path);sha256=(Get-FileHash $Path).Hash;bytes=(Get-Item $Path).Length}
}
function Files([string]$Directory) {
    @(Get-ChildItem $Directory -File -Recurse | Sort-Object FullName | ForEach-Object { Fact $_.FullName })
}
function Save($Value,[string]$Path) {
    ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 $Path
}
function Verify($Facts) {
    foreach ($file in $Facts) {
        if (-not (Test-Path $file.path) -or (Get-FileHash $file.path).Hash -cne $file.sha256) { throw "Source/cache drift: $($file.path)" }
    }
}
function Key($Inputs,[string]$Options) {
    $text=$Options+"`n"+(@($Inputs | Sort-Object path | ForEach-Object { "$($_.path)`t$($_.sha256)" }) -join "`n")
    [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($text)))
}
function Cache([string]$Kind,$Inputs,[string]$Options,[scriptblock]$Build) {
    $recipeKey=Key $Inputs ($Options + "`n" + $Build.ToString())
    $directory=Join-Path $cache "$Kind\$recipeKey"
    $manifest=Join-Path $directory 'cache.json'
    if (Test-Path $manifest) {
        $saved=Get-Content $manifest -Raw | ConvertFrom-Json -Depth 100
        Verify $saved.inputs
        Verify $saved.outputs
        $actual=@(Get-ChildItem $directory -File -Recurse | Where-Object FullName -NE $manifest | ForEach-Object FullName | Sort-Object)
        $expected=@($saved.outputs.path | Sort-Object)
        if (@(Compare-Object $actual $expected).Count) { throw "Source cache file census changed: $directory" }
        Write-Host "Reusing $Kind source cache: $directory"
        return $directory
    }
    if (Test-Path $directory) { throw "Incomplete source cache retained at $directory; inspect failure evidence before retrying with a new cache directory." }
    New-Item -ItemType Directory -Path $directory -Force | Out-Null
    & $Build $directory
    Verify $Inputs
    $record=[ordered]@{schemaVersion=1;kind=$Kind;options=$Options;inputs=$Inputs;outputs=(Files $directory)}
    $temporary=Join-Path $directory 'cache.json.tmp'
    Save $record $temporary
    Move-Item $temporary $manifest
    return $directory
}
function Run([string]$Executable,[string[]]$Arguments,[string]$Directory,[string]$Log) {
    Push-Location $Directory
    try { & $Executable @Arguments *> $Log; $code=$LASTEXITCODE }
    finally { Pop-Location }
    Save ([ordered]@{executable=$Executable;arguments=$Arguments;directory=$Directory;exitCode=$code}) "$Log.command.json"
    if ($code -ne 0) { throw "Source preparation failed ($code): $Log" }
}
function IncludeDirs([string[]]$Roots) {
    @((Join-Path $root 'generation\WinSDK\inc')) +
        @($Roots | ForEach-Object { $provider=$_; 'shared','um','ucrt','winrt' | ForEach-Object { Join-Path $provider $_ } } |
            Where-Object { Test-Path $_ }) + @($compilerInclude)
}
function CaptureIncludes([string[]]$Roots,[string]$Architecture) {
    $target=switch ($Architecture) {
        'x64' { 'x86_64-pc-windows-msvc' }
        'x86' { 'i686-pc-windows-msvc' }
        'arm64' { 'aarch64-pc-windows-msvc' }
        default { throw "Unsupported preparation architecture: $Architecture" }
    }
    $arguments=@("--target=$target",'-x','c++','-std=c++17','-fms-compatibility','-ferror-limit=0',
        '-DWIN32METADATA=1','-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',(Split-Path $ResourceDirectory))
    foreach ($include in IncludeDirs $Roots) { $arguments+=@('-isystem',$include) }
    [PowerbaseNativeProbe]::Capture($libclang,$main,$main,$arguments)
}
$architectures=@('x64','x86','arm64')
$includeRecipe=${function:IncludeDirs}.ToString()+${function:CaptureIncludes}.ToString()
$implementation=@("$PSScriptRoot\RecompileIdlFilesForScraping.ps1","$PSScriptRoot\CommonUtils.ps1",
    "$PSScriptRoot\ApplySDKPatches.ps1","$PSScriptRoot\WinSdkMidlConfig.ps1","$PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1",
    (Join-Path $root 'BuildTools\BuildTools.proj'))
$baseInputs=@($implementation | ForEach-Object { Fact $_ }) + (Files $sdk) + (Files $d3d) +
    (Files (Join-Path $root 'generation\WinSDK\AdditionalHeaders')) +
    (Files (Join-Path $root 'generation\WinSDK\RecompiledIdlHeaders'))
$prePatches=Join-Path $root 'generation\WinSDK\patches\pre-midl'
if (Test-Path $prePatches) { $baseInputs+=Files $prePatches }
$baseCache=Cache 'base' $baseInputs 'production copy, overrides, pre-MIDL patches and compatibility restores; no MIDL compile or post-MIDL patches' {
    param($directory)
    Run 'pwsh' @('-NoProfile','-File',"$PSScriptRoot\RecompileIdlFilesForScraping.ps1",
        '-OutputDirectory',(Join-Path $directory 'headers'),'-SkipMidl','-SkipPostMidlPatches') $root (Join-Path $directory 'prepare.log')
}
$baseRoot=Join-Path $baseCache 'headers'
$idlInputs=@((Fact (Join-Path $baseCache 'cache.json')),(Fact "$PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1"),
    (Fact "$PSScriptRoot\WinSdkMidlConfig.ps1"))
$idlCache=Cache 'idl' $idlInputs 'production IDL-to-SAL conversion, no native compilation' {
    param($directory)
    $converted=Join-Path $directory 'converted'
    New-Item -ItemType Directory -Path $converted | Out-Null
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    $excluded=Get-WinSdkMidlExclusions
    foreach ($idl in Get-ChildItem "$baseRoot\um\*.idl","$baseRoot\shared\*.idl" -Exclude $excluded | Sort-Object FullName) {
        if (-not $seen.Add($idl.Name)) { throw "Ambiguous converted IDL basename: $($idl.Name)" }
        & "$PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1" $idl.FullName (Join-Path $converted $idl.Name)
    }
}
$convertedRoot=Join-Path $idlCache 'converted'
$compilerFacts=@((Fact $midl),(Fact $cpp),(Fact $libclang)) + (Files $compilerInclude) + (Files $ResourceDirectory)
$partitionInputs=@((Fact (Join-Path $baseCache 'cache.json')),(Fact (Join-Path $idlCache 'cache.json')),
    (Fact (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs'))) + $compilerFacts + (Files (Join-Path $root 'generation\WinSDK\inc'))
$partitionInputs+=Files (Split-Path $main)
if (-not ('PowerbaseNativeProbe' -as [type])) { Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs') }
$previousPath=$env:PATH
$env:PATH="$(Split-Path $cpp);$previousPath"
try {
    $partitionCache=Cache 'partitions' $partitionInputs "canonical partition $Partition; active x64/x86/arm64 include union for provider preparation, not semantic acceptance; $includeRecipe" {
        param($directory)
        $generated=Join-Path $directory 'headers'
        foreach ($part in @('um','shared','ucrt','winrt')) { New-Item -ItemType Directory -Path (Join-Path $generated $part) -Force | Out-Null }
        $done=[Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
        $round=0
        do {
            $round++
            $pending=@()
            $captures=@{}
            foreach ($architecture in $architectures) {
                $capture=CaptureIncludes @($generated,$baseRoot) $architecture
                Save $capture (Join-Path $directory "include-discovery-$round-$architecture.json")
                $captures[$architecture]=$capture
                foreach ($included in $capture.includedFiles) {
                    $relative=[IO.Path]::GetRelativePath($baseRoot,$included)
                    if ($relative.StartsWith('..') -or [IO.Path]::IsPathRooted($relative)) { continue }
                    $idl=[IO.Path]::ChangeExtension($relative,'idl')
                    $name=[IO.Path]::GetFileName($idl)
                    if ($name -in (Get-WinSdkMidlExclusions) -or -not (Test-Path (Join-Path $convertedRoot $name))) { continue }
                    if (-not (Select-String 'File created by MIDL compiler' $included -Quiet -SimpleMatch)) { continue }
                    if ($done.Add($relative)) { $pending+=@([ordered]@{header=$relative;idl=$name}) }
                }
            }
            foreach ($item in $pending) {
                $headerInputs=@((Fact (Join-Path $convertedRoot $item.idl)),(Fact (Join-Path $idlCache 'cache.json')),
                    (Fact (Join-Path $baseCache 'cache.json')),(Fact "$PSScriptRoot\WinSdkMidlConfig.ps1")) + $compilerFacts
                $headerCache=Cache 'midl' $headerInputs "production MIDL $($item.header)" {
                    param($headerDirectory)
                    $output=Join-Path $headerDirectory ([IO.Path]::GetFileName($item.header))
                    $arguments=Get-WinSdkMidlArguments -InputFile (Join-Path $convertedRoot $item.idl) -OutputHeader $output `
                        -OutputDirectory $headerDirectory -ConvertedIdlDirectory $convertedRoot -HeaderRoot $baseRoot
                    Run $midl $arguments $headerDirectory (Join-Path $headerDirectory 'midl.log')
                    if (Select-String 'midl : error' (Join-Path $headerDirectory 'midl.log') -Quiet -SimpleMatch) { throw 'MIDL reported errors despite its process result.' }
                    if ($item.idl -ieq 'd3d10_1.idl') {
                        [IO.File]::WriteAllText($output,[IO.File]::ReadAllText($output).Replace("#include `"d3d10.h`"`r`n",''),[Text.UTF8Encoding]::new($false))
                    }
                }
                Copy-Item (Join-Path $headerCache ([IO.Path]::GetFileName($item.header))) (Join-Path $generated $item.header)
            }
        } while ($pending.Count -gt 0)
        Save ([ordered]@{partition=$Partition;architectures=$architectures;generatedHeaders=@($done | Sort-Object);includeRounds=$round;
            discoveryHasErrors=@($captures.Values | Where-Object hasErrors).Count -gt 0;
            scope='active canonical architecture provider closure only; compiler diagnostics and alternate source conditions remain unaccepted'}) (Join-Path $directory 'preparation.json')
    }
} finally { $env:PATH=$previousPath }
$generatedRoot=Join-Path $partitionCache 'headers'
$preparation=Get-Content (Join-Path $partitionCache 'preparation.json') -Raw | ConvertFrom-Json
$selected=[Collections.Generic.Dictionary[string,string]]::new([StringComparer]::OrdinalIgnoreCase)
foreach ($architecture in $architectures) {
    $capture=Get-Content (Join-Path $partitionCache "include-discovery-$($preparation.includeRounds)-$architecture.json") -Raw | ConvertFrom-Json -Depth 100
    foreach ($included in $capture.includedFiles) {
        foreach ($provider in @($generatedRoot,$baseRoot)) {
            $relative=[IO.Path]::GetRelativePath($provider,$included)
            if (-not $relative.StartsWith('..') -and -not [IO.Path]::IsPathRooted($relative)) { $selected[$relative]=$included; break }
        }
    }
}
$patches=@()
foreach ($patch in Get-ChildItem (Join-Path $root 'generation\WinSDK\patches\post-midl') -File -Filter '*.patch' | Sort-Object Name) {
    $targets=@(Select-String '^\+\+\+ b/generation/WinSDK/RecompiledIdlHeaders/(.+)$' $patch.FullName |
        ForEach-Object { $_.Matches[0].Groups[1].Value.Replace('/','\') } | Sort-Object -Unique)
    if ($targets.Count -ne 1) { throw "Expected one consolidated target per header patch: $($patch.FullName)" }
    if ($selected.ContainsKey($targets[0])) { $patches+=@([ordered]@{patch=$patch.FullName;target=$targets[0];source=$selected[$targets[0]]}) }
}
$candidateInputs=@((Fact (Join-Path $partitionCache 'cache.json'))) +
    @($patches | ForEach-Object { Fact $_.patch; Fact $_.source })
$candidateCache=Cache 'candidates' $candidateInputs "production post-MIDL patches consumed by $Partition; $includeRecipe" {
    param($directory)
    $overlay=Join-Path $directory 'headers'
    foreach ($part in @('um','shared','ucrt','winrt')) { New-Item -ItemType Directory -Path (Join-Path $overlay $part) -Force | Out-Null }
    foreach ($entry in $patches) {
        $destination=Join-Path $overlay $entry.target
        New-Item -ItemType Directory -Path (Split-Path $destination) -Force | Out-Null
        Copy-Item $entry.source $destination
        $relative=[IO.Path]::GetRelativePath($root,$overlay).Replace('\','/')
        Run 'git' @('-C',$root,'apply','-p4',"--directory=$relative",$entry.patch) $root (Join-Path $directory "$([IO.Path]::GetFileName($entry.patch)).log")
    }
    if ($patches.Count) {
        foreach ($architecture in $architectures) {
            $capture=CaptureIncludes @($overlay,$generatedRoot,$baseRoot) $architecture
            Save $capture (Join-Path $directory "include-discovery-$architecture.json")
            foreach ($included in $capture.includedFiles) {
                $relative=[IO.Path]::GetRelativePath($baseRoot,$included)
                if ($relative.StartsWith('..') -or [IO.Path]::IsPathRooted($relative)) { continue }
                $name=[IO.Path]::ChangeExtension([IO.Path]::GetFileName($relative),'idl')
                if ($name -notin (Get-WinSdkMidlExclusions) -and (Test-Path (Join-Path $convertedRoot $name)) -and
                    (Select-String 'File created by MIDL compiler' $included -Quiet -SimpleMatch)) {
                    throw "Candidate introduces unprepared MIDL provider $relative ($architecture); extend the canonical preparation closure before generation."
                }
            }
        }
    }
}
$candidateRoot=Join-Path $candidateCache 'headers'
$providerInputs=@((Fact (Join-Path $baseCache 'cache.json')),(Fact (Join-Path $idlCache 'cache.json')),
    (Fact (Join-Path $partitionCache 'cache.json')),(Fact (Join-Path $candidateCache 'cache.json')))
$pendingInputs=[Collections.Generic.Queue[object]]::new()
foreach ($inputFact in $providerInputs) { $pendingInputs.Enqueue($inputFact) }
$inputClosure=[Collections.Generic.Dictionary[string,object]]::new([StringComparer]::OrdinalIgnoreCase)
while ($pendingInputs.Count) {
    $inputFact=$pendingInputs.Dequeue()
    if ($inputClosure.ContainsKey($inputFact.path)) {
        if ($inputClosure[$inputFact.path].sha256 -cne $inputFact.sha256) { throw "Incompatible preparation input pins: $($inputFact.path)" }
        continue
    }
    $inputClosure.Add($inputFact.path,$inputFact)
    if ([IO.Path]::GetFileName($inputFact.path) -eq 'cache.json') {
        $record=Get-Content $inputFact.path -Raw | ConvertFrom-Json -Depth 100
        foreach ($dependency in $record.inputs) { $pendingInputs.Enqueue($dependency) }
    }
}
$providerInputs=@($inputClosure.Values | Sort-Object path)
$providerKey=Key $providerInputs "$Partition/provider-schema-3"
$providerRoot=Join-Path $cache "providers\$providerKey"
New-Item -ItemType Directory -Path $providerRoot -Force | Out-Null
foreach ($variant in @('control','candidate')) {
    $roots=@([ordered]@{id='prepared-base';path=$baseRoot;role='prepared-sdk'},
        [ordered]@{id='prepared-midl';path=$generatedRoot;role='prepared-midl'},
        [ordered]@{id='compiler-msvc';path=$compilerInclude;role='compiler-support'})
    $includeRoots=@($generatedRoot,$baseRoot)
    if ($variant -eq 'candidate') {
        $roots+=@([ordered]@{id='prepared-patch';path=$candidateRoot;role='prepared-patch'})
        $includeRoots=@($candidateRoot)+$includeRoots
    }
    $manifest=Join-Path $providerRoot "$variant.json"
    if (-not (Test-Path $manifest)) {
        $temporary="$manifest.tmp"
        Save ([ordered]@{schemaVersion=3;repository=$root;variant=$variant;partition=$Partition;closureArchitectures=$architectures;includeDirectories=(IncludeDirs $includeRoots);
            roots=$roots;preparationInputs=$providerInputs;preparedFiles=@($roots | ForEach-Object { Files $_.path })}) $temporary
        Move-Item $temporary $manifest
    }
    Write-Output $manifest
}
