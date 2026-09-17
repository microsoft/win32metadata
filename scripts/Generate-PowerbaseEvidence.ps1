<#
.SYNOPSIS
    Reproduces a pinned, single-header powerbase control and candidate.
.DESCRIPTION
    This generates evidence, not a declaration of legacy equivalence. The native
    and semantic gates are separate. Existing evidence directories are never reused.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [string]$ResourceDirectory,
    [string]$ReferenceEvidence,
    [string]$ToolPath,
    [string]$ToolSha256,
    [string]$ToolSourceRoot
)

$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$evidence = [IO.Path]::GetFullPath($EvidenceDirectory)
if (Test-Path $evidence) { throw "Evidence directory already exists: $evidence. Use a fresh directory." }
$packages = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $HOME '.nuget\packages' }
$sdkVersion = '10.0.26100.7705'
$releaseVersion = '70.0.11-preview'
$sdkPackage = Join-Path $packages "microsoft.windows.sdk.cpp\$sdkVersion"
$libPackage = Join-Path $packages "microsoft.windows.sdk.cpp.x64\$sdkVersion"
$releasePackage = Join-Path $packages "microsoft.windows.sdk.win32metadata\$releaseVersion"
$sdk = Join-Path $sdkPackage 'c\Include\10.0.26100.0'
$originalHeader = Join-Path $sdk 'um\powerbase.h'
$originalWinmd = Join-Path $releasePackage 'Windows.Win32.winmd'
$library = Join-Path $libPackage 'c\um\x64\PowrProf.Lib'
$patch = Join-Path $root 'generation\WinSDK\patches\post-midl\powerbase.h.win32metadata.patch'
$vocabulary = Join-Path $root 'generation\WinSDK\AdditionalHeaders\win32metadata_annotations.h'
$sal = Join-Path $root 'generation\WinSDK\inc\sal.h'
$tu = Join-Path $root 'tests\PowerbasePilot\main.cpp'
$namespacePolicy = Join-Path $root 'generation\WinSDK\Partitions\Power\settings.rsp'
$namespaceMatch = [regex]::Matches([IO.File]::ReadAllText($namespacePolicy), '(?m)^--namespace\r?\n([^\r\n]+)\r?$')
if ($namespaceMatch.Count -ne 1) { throw 'Canonical Power partition must define exactly one namespace.' }
$namespace = $namespaceMatch[0].Groups[1].Value.Trim()
$externalTool = [bool]$ToolPath
if (($ToolPath -or $ToolSha256 -or $ToolSourceRoot) -and -not ($ToolPath -and $ToolSha256 -and $ToolSourceRoot)) {
    throw 'An explicitly supplied consumer requires ToolPath, ToolSha256, and ToolSourceRoot together.'
}
$toolRoot = if ($externalTool) { [IO.Path]::GetFullPath($ToolSourceRoot) } else { $root }
$cargoManifest = Join-Path $toolRoot 'tools\rust\Cargo.toml'
$cargoLock = Join-Path $toolRoot 'tools\rust\Cargo.lock'
$tool = if ($externalTool) { [IO.Path]::GetFullPath($ToolPath) } else { Join-Path $root 'tools\rust\target\release\win32metadata-tools.exe' }
$libclang = Join-Path $packages 'libclang.runtime.win-x64\22.1.8\runtimes\win-x64\native\libclang.dll'
$requiredBase = 'b7ead1e6847d4c81f8e5b8b14a51350055f0d31a'

function Get-Identity([string]$Path) {
    if (-not (Test-Path -LiteralPath $Path -PathType Leaf)) { throw "Missing pinned input: $Path" }
    [ordered]@{ path=[IO.Path]::GetFullPath($Path); bytes=(Get-Item -LiteralPath $Path).Length; sha256=(Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash }
}

$referenceIdentity = Get-Identity $originalWinmd
$headerIdentity = Get-Identity $originalHeader
if ($referenceIdentity.sha256 -cne '6AEC29BE3359468D9EBA03C3AE932591B39960F1812B6D25D33C0D9F14A6D665') {
    throw 'Published reference does not match the approved 70.0.11-preview artifact.'
}
if ($headerIdentity.sha256 -cne '66082F57FF576850899FA3DEB4779C0B762163A70946D0BE4DF78F3A2A506FB2') {
    throw 'Selected SDK powerbase.h differs from the inventoried input; review the pilot before updating its pin.'
}
git -C $root merge-base --is-ancestor $requiredBase HEAD
if ($LASTEXITCODE -ne 0) { throw "Current branch does not contain required tooling baseline $requiredBase." }

New-Item -ItemType Directory -Path $evidence | Out-Null
$commands = [Collections.Generic.List[object]]::new()
$manifest = [ordered]@{
    schemaVersion=1; status='generating'; scope='powerbase.h only; not a full-SDK validation'
    requiredToolingBase=$requiredBase; repositoryHead=(& git -C $root rev-parse HEAD)
    toolSourceRoot=$toolRoot; toolSourceHead=(& git -C $toolRoot rev-parse HEAD)
    toolSelection=if($externalTool){'explicit SHA-checked owner-supplied binary; no repository pin changes'}else{'repository-local locked build'}
    sdkVersion=$sdkVersion; releaseVersion=$releaseVersion
    architectures=@('x64','x86','arm64'); namespace=$namespace; namespacePolicy=$namespacePolicy
    reference=$referenceIdentity; nativeHeader=$headerIdentity
    inputs=[Collections.Generic.List[object]]::new(); commands=$commands
    nativeNormalization=@('source locations', 'annotation transport only')
    metadataNormalization=@('none at generation stage')
    scopeErrors=[Collections.Generic.List[object]]::new()
}

function Invoke-Recorded([string]$Executable, [string[]]$Arguments, [string]$Log, [string]$WorkingDirectory=$root) {
    Push-Location $WorkingDirectory
    try {
        $entry = [ordered]@{
            executable=$Executable; arguments=$Arguments; workingDirectory=$WorkingDirectory
            libclangPath=$env:LIBCLANG_PATH; clangResourceDirectory=$env:CLANG_RESOURCE_DIR; log=$Log; errorLog="$Log.stderr"
        }
        $commands.Add($entry)
        & $Executable @Arguments 1> $Log 2> "$Log.stderr"
        $entry.exitCode = $LASTEXITCODE
        if ($LASTEXITCODE -ne 0) { throw "$Executable failed ($LASTEXITCODE). See $Log" }
    } finally { Pop-Location }
}

function Assert-PilotRdlScope([string]$VariantRoot, [string]$Variant) {
    $expectedOwned = @(
        'extern fn:CallNtPowerInformation', 'extern fn:GetPwrCapabilities',
        'extern fn:PowerDeterminePlatformRoleEx', 'extern fn:PowerRegisterSuspendResumeNotification',
        'extern fn:PowerUnregisterSuspendResumeNotification'
    )
    if ($Variant -eq 'candidate') {
        $expectedOwned += @('enum:POWER_PLATFORM_ROLE_VERSION', 'enum:REGISTER_NOTIFICATION_FLAGS')
    }
    $expectedOwned = @($expectedOwned | Sort-Object)
    if (-not ('PowerbaseNativeProbe' -as [type])) {
        Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs')
    }
    foreach ($directory in @('rdl','x86','arm64')) {
        $triple = @{ rdl='x86_64-pc-windows-msvc'; x86='i686-pc-windows-msvc'; arm64='aarch64-pc-windows-msvc' }[$directory]
        $nativeArgs = @("--target=$triple",'-x','c++','-std=c++17','-fms-compatibility',
            '-ferror-limit=0','-DWIN32METADATA=1','-D_COM_NO_STANDARD_GUIDS_=1',
            '-resource-dir',$env:CLANG_RESOURCE_DIR,
            '-isystem',(Join-Path $VariantRoot 'headers\um'),
            '-isystem',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),
            '-isystem',(Join-Path $root 'generation\WinSDK\inc'))
        foreach ($part in @('shared','um','ucrt','winrt')) { $nativeArgs += @('-isystem',(Join-Path $sdk $part)) }
        $native = [PowerbaseNativeProbe]::Capture($libclang, $tu, (Join-Path $VariantRoot 'headers\um\powerbase.h'), $nativeArgs)
        $native | ConvertTo-Json -Depth 90 | Set-Content -Encoding utf8 (Join-Path $VariantRoot "$directory-native-source-scope.json")
        if ($native.hasErrors) { throw "Source scope probe failed for $Variant/$directory." }
        $sourceDefinitions = @{}
        foreach ($definition in @($native.ownedDeclarations) + @($native.dependencyDeclarations) +
            @($native.annotationDependencyDeclarations) + @($native.macroDerivedDependencyDeclarations)) {
            $headerName = [IO.Path]::GetFileNameWithoutExtension($definition['source']['file'])
            $key = "$headerName`:$($definition['name'])"
            if (-not $sourceDefinitions.ContainsKey($key)) { $sourceDefinitions[$key] = @() }
            $sourceDefinitions[$key] += $definition
        }
        $inventory = @(
            Get-ChildItem (Join-Path $VariantRoot "obj\$directory") -Filter '*.rdl' -File |
                Sort-Object Name | ForEach-Object {
                    $file = $_
                    $text = [IO.File]::ReadAllText($file.FullName)
                    foreach ($match in [regex]::Matches($text, '(?m)^\s*(?:extern(?:\s+"(?<abi>[^"]+)")?\s+fn|(?<kind>struct|enum|type|const|interface|union))\s+(?<name>\w+)')) {
                        $kind = if ($match.Groups['kind'].Success) { $match.Groups['kind'].Value } else { 'extern fn' }
                        [ordered]@{ header=$file.BaseName; kind=$kind; name=$match.Groups['name'].Value; abi=$match.Groups['abi'].Value }
                    }
                }
        )
        $inventory | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $VariantRoot "$directory-inventory.json")
        $actualOwned = @($inventory | Where-Object header -eq 'powerbase' | ForEach-Object { "$($_.kind):$($_.name)" } | Sort-Object)
        if (($actualOwned -join "`n") -cne ($expectedOwned -join "`n")) {
            throw "Header owner inventory mismatch for $Variant/$directory. See $VariantRoot\$directory-inventory.json."
        }
        $ledger = @(
            foreach ($declaration in $inventory) {
                $key = "$($declaration.header):$($declaration.name)"
                if (-not $sourceDefinitions.ContainsKey($key)) {
                    throw "Emitted $key has no defining-source path through a native or annotation dependency. See $VariantRoot\$directory-inventory.json."
                }
                [ordered]@{ declaration=$declaration; nativeDefinitions=$sourceDefinitions[$key];
                    macroTypedefBindings=@($native.macroTypedefSourceBindings | Where-Object { $_.macroTokens[0] -ceq $declaration.name }) }
            }
        )
        $ledger | ConvertTo-Json -Depth 90 | Set-Content -Encoding utf8 (Join-Path $VariantRoot "$directory-source-ledger.json")
    }
}

$priorLibclang = $env:LIBCLANG_PATH
$priorResource = $env:CLANG_RESOURCE_DIR
try {
    foreach ($inputPath in @(
        $originalWinmd, $originalHeader, $library, $patch, $vocabulary, $sal, $tu, $namespacePolicy, $cargoManifest,
        $cargoLock, $libclang,
        (Join-Path $sdkPackage "microsoft.windows.sdk.cpp.$sdkVersion.nupkg"),
        (Join-Path $libPackage "microsoft.windows.sdk.cpp.x64.$sdkVersion.nupkg"),
        (Join-Path $releasePackage "microsoft.windows.sdk.win32metadata.$releaseVersion.nupkg")
    )) { $manifest.inputs.Add((Get-Identity $inputPath)) }
    $manifest.rustc = & rustc -Vv
    $manifest.dotnet = & dotnet --version
    $manifest.wrapperSourceFiles = @(Get-ChildItem (Join-Path $toolRoot 'tools\rust\src') -Filter '*.rs' -File |
        Sort-Object Name | ForEach-Object { Get-Identity $_.FullName })
    $manifest.runner = Get-Identity $PSCommandPath
    if (-not $externalTool) {
        Invoke-Recorded 'cargo' @('build','--release','--locked','--manifest-path',$cargoManifest,
            '--target-dir',(Join-Path $root 'tools\rust\target'),'--quiet') (Join-Path $evidence 'build-rust.log')
    } elseif ((Get-Identity $tool).sha256 -cne $ToolSha256.ToUpperInvariant()) {
        throw 'Owner-supplied consumer binary does not match the explicitly approved hash.'
    }
    $manifest.tool = Get-Identity $tool
    Invoke-Recorded 'cargo' @('metadata','--locked','--manifest-path',$cargoManifest,'--format-version','1') (Join-Path $evidence 'cargo-metadata.json')
    $cargo = Get-Content (Join-Path $evidence 'cargo-metadata.json') -Raw | ConvertFrom-Json
    $manifest.windowsRs = @($cargo.packages | Where-Object { $_.name -in @('windows-clang','windows-rdl','windows-metadata') } |
        Select-Object name,version,source,manifest_path)
    if ($manifest.windowsRs.Count -ne 3 -or @($manifest.windowsRs | Where-Object { -not $_.source }).Count -ne 0) {
        throw 'All three windows-rs crates must have recorded immutable sources; local path overrides are not accepted for final evidence.'
    }
    $sources = @($manifest.windowsRs.source | Select-Object -Unique)
    if ($sources.Count -ne 1) { throw 'windows-rs crates are not pinned to the same source revision.' }
    $defaults = @($cargo.packages | Where-Object name -eq 'windows-default')
    if ($defaults.Count -ne 1 -or $defaults[0].source -cne $sources[0]) {
        throw 'Bundled metadata reference package does not share the recorded windows-rs pin.'
    }
    $defaultRoot = Split-Path $defaults[0].manifest_path
    $manifest.bundledReferences = @(
        (Get-Identity (Join-Path $defaultRoot 'Windows.winmd')),
        (Get-Identity (Join-Path $defaultRoot 'Windows.Win32.winmd'))
    )
    $manifest.bundledReferenceUse = 'Clang resolution_default and RDL reference_default; all emitted pilot API definitions must also be accounted for in source-owned/dependency RDL. These references are not the legacy comparison baseline.'
    $env:LIBCLANG_PATH = Split-Path $libclang
    if ($ResourceDirectory) {
        $env:CLANG_RESOURCE_DIR = [IO.Path]::GetFullPath($ResourceDirectory)
    } else {
        $env:CLANG_RESOURCE_DIR = $null
    }
    Invoke-Recorded $tool @('libclang') (Join-Path $evidence 'libclang.log')
    New-Item -ItemType Directory -Path (Join-Path $evidence 'inputs'), (Join-Path $evidence 'reference') | Out-Null
    Copy-Item $originalWinmd (Join-Path $evidence 'reference\Windows.Win32.winmd')
    Copy-Item $tool (Join-Path $evidence 'inputs\win32metadata-tools.exe')
    Copy-Item $cargoManifest (Join-Path $evidence 'inputs\Cargo.toml')
    Copy-Item $cargoLock (Join-Path $evidence 'inputs\Cargo.lock')
    Copy-Item $patch (Join-Path $evidence 'inputs\powerbase.h.win32metadata.patch')
    Copy-Item $vocabulary (Join-Path $evidence 'inputs\win32metadata_annotations.h')
    Copy-Item $sal (Join-Path $evidence 'inputs\sal.h')
    Copy-Item $tu (Join-Path $evidence 'inputs\main.cpp')
    Copy-Item $namespacePolicy (Join-Path $evidence 'inputs\Power.settings.rsp')
    if ($ReferenceEvidence) {
        $manifest.inputs.Add((Get-Identity $ReferenceEvidence))
        Copy-Item $ReferenceEvidence (Join-Path $evidence 'inputs\reference-provenance.json')
    }
    foreach ($variant in @('control','candidate')) {
        $variantRoot = Join-Path $evidence $variant
        $headers = Join-Path $variantRoot 'headers'
        New-Item -ItemType Directory -Path (Join-Path $headers 'um') -Force | Out-Null
        Copy-Item $originalHeader (Join-Path $headers 'um\powerbase.h')
        if ($variant -eq 'candidate') {
            Invoke-Recorded 'git' @('apply','-p4',$patch) (Join-Path $variantRoot 'patch-apply.log') $headers
            $applied = Get-Identity (Join-Path $headers 'um\powerbase.h')
            Invoke-Recorded 'git' @('apply','--reverse','-p4',$patch) (Join-Path $variantRoot 'patch-reverse.log') $headers
            if ((Get-Identity (Join-Path $headers 'um\powerbase.h')).sha256 -cne $headerIdentity.sha256) {
                throw 'Reverse patch application did not restore the exact SDK bytes.'
            }
            Invoke-Recorded 'git' @('apply','-p4',$patch) (Join-Path $variantRoot 'patch-reapply.log') $headers
            if ((Get-Identity (Join-Path $headers 'um\powerbase.h')).sha256 -cne $applied.sha256) {
                throw 'Patch reapplication was not deterministic.'
            }
            $manifest.candidateHeader = $applied
        }
        $args = @(
            'scrape','--partition',$tu,'--include',(Join-Path $headers 'um'),
            '--include',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),
            '--include',(Join-Path $root 'generation\WinSDK\inc'),'--include',$sdk,
            '--lib',$library,'--scope','__powerbase_pilot_no_directory_scope__','--scope-header','powerbase',
            '--namespace',$namespace,
            '--arch','x64','--arch','x86','--arch','arm64','--assembly-name','Windows.Win32',
            '--output',(Join-Path $variantRoot 'Windows.Win32.winmd'),'--obj',(Join-Path $variantRoot 'obj')
        )
        Invoke-Recorded $tool $args (Join-Path $variantRoot 'generation.log')
        if (-not $env:CLANG_RESOURCE_DIR) {
            $env:CLANG_RESOURCE_DIR = Join-Path $variantRoot 'obj\target\windows-clang\clang-resource\22.1.8\include'
            if (-not (Test-Path $env:CLANG_RESOURCE_DIR -PathType Container)) { throw 'Generated clang resource directory was not found.' }
        }
        try {
            Assert-PilotRdlScope $variantRoot $variant
        } catch {
            $manifest.scopeErrors.Add([ordered]@{variant=$variant;error=$_.Exception.Message})
        }
        foreach ($output in @('Windows.Win32.winmd','obj\Windows.Win32.x64.winmd','obj\Windows.Win32.x86.winmd','obj\Windows.Win32.arm64.winmd')) {
            $manifest.inputs.Add((Get-Identity (Join-Path $variantRoot $output)))
        }
    }
    $manifest.resourceDirectory = $env:CLANG_RESOURCE_DIR
    $manifest.resourceFiles = @(Get-ChildItem -LiteralPath $env:CLANG_RESOURCE_DIR -File -Recurse | Sort-Object FullName | ForEach-Object { Get-Identity $_.FullName })
    foreach ($inputIdentity in @($manifest.wrapperSourceFiles) + @($manifest.inputs | Where-Object { $_.path -in @($cargoManifest, $cargoLock) }) + @($manifest.tool)) {
        if ((Get-Identity $inputIdentity.path).sha256 -cne $inputIdentity.sha256) {
            throw "Tool input changed during evidence generation: $($inputIdentity.path)"
        }
        if ($manifest.scopeErrors.Count -ne 0) {
            throw "Generation completed, but source/ownership gates failed: $($manifest.scopeErrors | ConvertTo-Json -Compress). Both variants are retained."
        }
    }
    $manifest.status = 'generated; semantic equivalence not yet evaluated'
} catch {
    $manifest.status = 'failed'
    $manifest.error = $_.Exception.Message
    throw
} finally {
    $manifest | ConvertTo-Json -Depth 50 | Set-Content -Encoding utf8 (Join-Path $evidence 'manifest.json')
    $env:LIBCLANG_PATH = $priorLibclang
    $env:CLANG_RESOURCE_DIR = $priorResource
}
Write-Host "Generated powerbase evidence: $evidence (not an equivalence verdict)."
