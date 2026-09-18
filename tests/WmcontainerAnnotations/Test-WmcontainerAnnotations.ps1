[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [Parameter(Mandatory)][string]$ToolPath,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [ValidateSet('x64','x86','arm64')][string[]]$Architecture = @('x64','x86','arm64')
)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$evidence = [IO.Path]::GetFullPath($EvidenceDirectory)
$pins = Get-Content (Join-Path $root 'generation\WinSDK\rollout\pins.json') -Raw | ConvertFrom-Json
$packages = if ($env:NUGET_PACKAGES) { $env:NUGET_PACKAGES } else { Join-Path $HOME '.nuget\packages' }
$sdk = Join-Path $packages "microsoft.windows.sdk.cpp\$($pins.sdkVersion)\c\Include\$($pins.sdkIncludeVersion)"
$libs = Join-Path $packages "microsoft.windows.sdk.cpp.x64\$($pins.sdkVersion)\c\um\x64"
$libclang = Join-Path $packages "libclang.runtime.win-x64\$($pins.libclangVersion)\runtimes\win-x64\native\libclang.dll"
$reference = Join-Path $packages "microsoft.windows.sdk.win32metadata\$($pins.referenceVersion)\Windows.Win32.winmd"
$header = Join-Path $sdk 'um\wmcontainer.h'
$patch = Join-Path $root 'generation\WinSDK\patches\post-midl\wmcontainer.h.win32metadata.patch'
$reader = Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
if (Test-Path $evidence) { throw "Evidence directory already exists: $evidence" }
if ((Get-FileHash $ToolPath).Hash -cne $pins.toolSha256) { throw 'Generator hash mismatch.' }
if ((Get-FileHash $libclang).Hash -cne $pins.libclangSha256) { throw 'libclang hash mismatch.' }
if ((Get-FileHash $reference).Hash -cne $pins.referenceSha256) { throw 'Published reference hash mismatch.' }
if (-not (Test-Path $reader)) { throw 'Build sources\WinmdUtils before running this test.' }
if (-not ('PowerbaseNativeProbe' -as [type])) { Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs') }
New-Item -ItemType Directory -Path (Join-Path $evidence 'inputs') -Force | Out-Null
function Identity([string]$Path) {
    [ordered]@{path=[IO.Path]::GetFullPath($Path);sha256=(Get-FileHash $Path).Hash;bytes=(Get-Item $Path).Length}
}
function Save($Value, [string]$Path) {
    ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 $Path
}
$manifest = [ordered]@{
    status='running'
    scope='wmcontainer.h forward enum association preflight; not complete header or partition equivalence'
    sourceCommit=(& git -C $root rev-parse HEAD)
    patch=(Identity $patch)
    stockHeader=(Identity $header)
    tool=(Identity $ToolPath)
    compiler=(Identity $libclang)
    reference=(Identity $reference)
    resourceDirectory=[IO.Path]::GetFullPath($ResourceDirectory)
    architectures=$Architecture
    commands=[Collections.Generic.List[object]]::new()
    nativeChecks=[Collections.Generic.List[object]]::new()
    metadataChecks=[Collections.Generic.List[object]]::new()
    implementation=@(Get-ChildItem $PSScriptRoot -File | Sort-Object Name | ForEach-Object { Identity $_.FullName })
    documentation=@(
        'https://learn.microsoft.com/en-us/windows/win32/api/wmcontainer/nf-wmcontainer-imfasfsplitter-getnextsample',
        'https://learn.microsoft.com/en-us/windows/win32/api/wmcontainer/ne-wmcontainer-asf_statusflags'
    )
}
function Run([string]$Executable, [string[]]$Arguments, [string]$Log, [string]$Directory=$root) {
    $entry=[ordered]@{executable=$Executable;arguments=$Arguments;directory=$Directory;log=$Log}
    $manifest.commands.Add($entry)
    Push-Location $Directory
    try { & $Executable @Arguments *> $Log; $entry.exitCode=$LASTEXITCODE }
    finally { Pop-Location }
    if ($entry.exitCode -ne 0) { throw "Command failed ($($entry.exitCode)): $Log" }
}
function Decode([string]$Winmd, [string]$Path) {
    Run 'dotnet' @($reader,'contracts','--winmd',$Winmd,'--output',$Path) "$Path.log"
    return Get-Content $Path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
}
function Get-SplitterParameter($Snapshot) {
    $types=@($Snapshot.declarations | Where-Object name -CEQ 'IMFASFSplitter')
    if ($types.Count -ne 1) { throw 'Expected one IMFASFSplitter definition.' }
    $methods=@($types[0].methods | Where-Object name -CEQ 'GetNextSample')
    if ($methods.Count -ne 1) { throw 'Expected one IMFASFSplitter.GetNextSample method.' }
    $parameters=@($methods[0].parameters | Where-Object name -CEQ 'pdwStatusFlags')
    if ($parameters.Count -ne 1) { throw 'Expected one pdwStatusFlags parameter.' }
    return $parameters[0]
}
function Assert-Association($Snapshot) {
    $parameter=Get-SplitterParameter $Snapshot
    $attributes=@($parameter.customAttributes | Where-Object { $_.constructor.declaringType.name -ceq 'AssociatedEnumAttribute' })
    if ($attributes.Count -ne 1 -or $attributes[0].fixedArguments[0].value -cne 'ASF_STATUSFLAGS') {
        throw 'pdwStatusFlags must retain its ASF_STATUSFLAGS association.'
    }
    $enums=@($Snapshot.declarations | Where-Object name -CEQ 'ASF_STATUSFLAGS')
    if ($enums.Count -ne 1) { throw 'Associated enum must resolve to one actual definition.' }
    $type=@($Snapshot.declarations | Where-Object name -CEQ 'IMFASFSplitter')[0]
    $method=@($type.methods | Where-Object name -CEQ 'GetNextSample')[0]
    $nativeType=$method.signature.parameterTypes[0]
    if ($nativeType.kind -cne 'pointer' -or $nativeType.elementType.kind -cne 'primitive' -or $nativeType.elementType.name -cne 'UInt32' -or
        $parameter.sequence -ne 1 -or $parameter.attributes.value -ne 2) {
        throw 'pdwStatusFlags must remain an Out UInt32 pointer, not an enum-typed parameter.'
    }
    $values=@{}
    foreach ($field in $enums[0].fields | Where-Object name -CNE 'value__') { $values[$field.name]=$field.constant.value }
    if ($values.Count -ne 2 -or $values.ASF_STATUSFLAGS_INCOMPLETE -ne 1 -or $values.ASF_STATUSFLAGS_NONFATAL_ERROR -ne 2) {
        throw 'Associated enum values differ from native source.'
    }
}
$previousClang=$env:LIBCLANG_PATH
$previousResource=$env:CLANG_RESOURCE_DIR
$previousPath=$env:PATH
try {
    $env:LIBCLANG_PATH=Split-Path $libclang
    $env:CLANG_RESOURCE_DIR=$ResourceDirectory
    $tool=Join-Path $evidence 'inputs\win32metadata-tools.exe'
    Copy-Item $ToolPath $tool
    Copy-Item $patch (Join-Path $evidence 'inputs\wmcontainer.h.win32metadata.patch')
    foreach ($file in $manifest.implementation) { Copy-Item $file.path (Join-Path $evidence "inputs\$([IO.Path]::GetFileName($file.path))") }
    Copy-Item (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs') (Join-Path $evidence 'inputs\NativeProbe.cs')
    $manifest['importLibraries']=@(Get-ChildItem $libs -File -Filter '*.lib' | Sort-Object Name | ForEach-Object { Identity $_.FullName })
    $midlDirectory=Join-Path $evidence 'midl'
    New-Item -ItemType Directory -Path $midlDirectory -Force | Out-Null
    $sourceIdl=Join-Path $sdk 'um\wmcontainer.idl'
    $convertedIdl=Join-Path $midlDirectory 'wmcontainer.idl'
    & (Join-Path $root 'scripts\ConvertMidlAttributesToSalAnnotations.ps1') $sourceIdl $convertedIdl
    $midl=Join-Path $packages "microsoft.windows.sdk.cpp\$($pins.sdkVersion)\c\bin\$($pins.sdkIncludeVersion)\x86\midl.exe"
    $visualStudio=& (Join-Path $root 'scripts\Get-VSPath.ps1')
    $vcVersion=(Get-Content (Join-Path $visualStudio 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt') -Raw).Trim()
    $cpp=Join-Path $visualStudio "VC\Tools\MSVC\$vcVersion\bin\Hostx86\x86\cl.exe"
    $env:PATH="$(Split-Path $cpp);$previousPath"
    $generatedHeader=Join-Path $midlDirectory 'wmcontainer.h'
    $midlArguments=@($convertedIdl,'/out',$midlDirectory,'/header',$generatedHeader,'/no_warn',
        '/DUNICODE','/D_UNICODE','/DWINVER=0x0A00','/D_APISET_MINWIN_VERSION=0x010F','/DNTDDI_VERSION=0x0A00000C',
        '/DBUILD_UMS_ENABLED=0','/DBUILD_WOW64_ENABLED=0','/DBUILD_ARM64X_ENABLED=0','/DEXECUTABLE_WRITES_SUPPORT=0',
        '/D_USE_DECLSPECS_FOR_SAL=1','/D_CONTROL_FLOW_GUARD_SVCTAB=1','/DMIDL_PASS=1','/D_AMD64_','/D_WIN64','/D_WCHAR_T_DEFINED',
        '/no_stamp','/nologo','/no_settings_comment','/lcid','1033','/sal','/amd64','/target','NT100','/Zp8')
    foreach ($include in @($midlDirectory,(Join-Path $sdk 'um'),(Join-Path $sdk 'shared'),(Join-Path $sdk 'winrt'),(Join-Path $root 'scripts\inc'))) {
        $midlArguments+=@('/I',$include)
    }
    Run $midl $midlArguments (Join-Path $midlDirectory 'generation.log') $midlDirectory
    if (Select-String 'midl : error' (Join-Path $midlDirectory 'generation.log') -Quiet -SimpleMatch) { throw 'Targeted MIDL generation reported errors.' }
    $manifest['headerProvider']=[ordered]@{
        kind='selected SDK IDL regenerated with the production MIDL/SAL options'
        sourceIdl=(Identity $sourceIdl)
        convertedIdl=(Identity $convertedIdl)
        converter=(Identity (Join-Path $root 'scripts\ConvertMidlAttributesToSalAnnotations.ps1'))
        midl=(Identity $midl)
        preprocessor=(Identity $cpp)
        generatedHeader=(Identity $generatedHeader)
        limitation='Only the target IDL is converted; imported dependency headers are stock SDK, not a full regenerated partition.'
    }
    $manifest.headerProvider['processedInputs']=@(
        Get-Content (Join-Path $midlDirectory 'generation.log') |
            Where-Object { $_ -match '^64 bit Processing (.+)$' } |
            ForEach-Object { Identity $Matches[1] }
    )
    $header=$generatedHeader
    foreach ($variant in @('control','candidate')) {
        $directory=Join-Path $evidence $variant
        $overlay=Join-Path $directory 'headers'
        New-Item -ItemType Directory -Path (Join-Path $overlay 'um') -Force | Out-Null
        $variantHeader=Join-Path $overlay 'um\wmcontainer.h'
        Copy-Item $header $variantHeader
        if ($variant -eq 'candidate') {
            Run 'git' @('apply','-p4',$patch) (Join-Path $directory 'patch-apply.log') $overlay
            $candidateHash=(Get-FileHash $variantHeader).Hash
            Run 'git' @('apply','--reverse','-p4',$patch) (Join-Path $directory 'patch-reverse.log') $overlay
            if ((Get-FileHash $variantHeader).Hash -cne $manifest.headerProvider.generatedHeader.sha256) { throw 'Reversal did not restore exact source bytes.' }
            Run 'git' @('apply','-p4',$patch) (Join-Path $directory 'patch-reapply.log') $overlay
            if ((Get-FileHash $variantHeader).Hash -cne $candidateHash) { throw 'Reapplication was not deterministic.' }
            $manifest['candidateHeader']=Identity $variantHeader
            $candidateSource=[IO.File]::ReadAllText($variantHeader)
            $association='_Out_ _Win32_AssociatedEnum_(ASF_STATUSFLAGS) DWORD *pdwStatusFlags,'
            if ([regex]::Matches($candidateSource,[regex]::Escape($association)).Count -ne 2) { throw 'Expected precisely the C++ and C vtable associations.' }
            $withoutAnnotations=$candidateSource.Replace($association,'_Out_  DWORD *pdwStatusFlags,') -replace '(?m)^#include <win32metadata_annotations.h>\r?\n',''
            if ($withoutAnnotations -cne [IO.File]::ReadAllText($header)) { throw 'Patch changes native source beyond the two associations and vocabulary include.' }
            $manifest['nativeSourcePreservation']='Removing precisely the two annotations and vocabulary include restores the complete generated header byte-for-byte.'
        }
        foreach ($arch in $Architecture) {
            $triple=@{x64='x86_64-pc-windows-msvc';x86='i686-pc-windows-msvc';arm64='aarch64-pc-windows-msvc'}[$arch]
            foreach ($mode in @('c','cpp','c-vtable','metadata','metadata-c-vtable')) {
                $arguments=@("--target=$triple",'-x',$(if ($mode -eq 'c') {'c'} else {'c++'}),
                    $(if ($mode -eq 'c') {'-std=c17'} else {'-std=c++17'}),'-fms-compatibility','-ferror-limit=0',
                    '-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',$ResourceDirectory)
                if ($mode -like 'metadata*') { $arguments+='-DWIN32METADATA=1' }
                if ($mode -like '*c-vtable') { $arguments+='-DCINTERFACE=1' }
                foreach ($include in @((Join-Path $overlay 'um'),(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),(Join-Path $root 'generation\WinSDK\inc'))) {
                    $arguments+=@('-isystem',$include)
                }
                foreach ($part in @('shared','um','ucrt','winrt')) { $arguments+=@('-isystem',(Join-Path $sdk $part)) }
                $tu=Join-Path $PSScriptRoot $(if ($mode -eq 'c') {'native.c'} else {'native.cpp'})
                $capture=[PowerbaseNativeProbe]::Capture($libclang,$tu,$variantHeader,$arguments)
                Save $capture (Join-Path $directory "native-$arch-$mode.json")
                if ($capture.hasErrors) { throw "Native signature assertions failed: $variant/$arch/$mode" }
                $manifest.nativeChecks.Add([ordered]@{variant=$variant;architecture=$arch;mode=$mode;result='native signatures and enum constants preserved'})
            }
        }
        $arguments=@('scrape','--partition',(Join-Path $PSScriptRoot 'main.cpp'),'--include',$overlay,
            '--include',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),'--include',(Join-Path $root 'generation\WinSDK\inc'),
            '--include',$sdk,'--lib',$libs,'--scope','__wmcontainer_no_directory_scope__','--scope-header','wmcontainer',
            '--namespace','Windows.Win32.Media.MediaFoundation','--assembly-name','Windows.Win32',
            '--output',(Join-Path $directory 'Windows.Win32.winmd'),'--obj',(Join-Path $directory 'obj'))
        foreach ($arch in $Architecture) { $arguments+=@('--arch',$arch) }
        Run $tool $arguments (Join-Path $directory 'generation.log')
        foreach ($arch in @($Architecture)+@('merged')) {
            $winmd=if ($arch -eq 'merged') { Join-Path $directory 'Windows.Win32.winmd' } else { Join-Path $directory "obj\Windows.Win32.$arch.winmd" }
            $snapshot=Decode $winmd (Join-Path $directory "contracts-$arch.json")
            if ($variant -eq 'candidate') {
                Assert-Association $snapshot
                $manifest.metadataChecks.Add([ordered]@{variant=$variant;result='forward association resolves to actual enum and preserves Out UInt32 pointer';architecture=$arch})
            }
        }
    }
    foreach ($arch in @($Architecture)+@('merged')) {
        $first=Join-Path $evidence "control\contracts-$arch.json"
        $second=Join-Path $evidence "candidate\contracts-$arch.json"
        $output=Join-Path $evidence "raw-contract-diff-$arch.json"
        & dotnet $reader compare-contracts --first $first --second $second --output $output *> "$output.log"
        if ($LASTEXITCODE -ne 1) { throw 'Expected the single annotation addition in the complete raw contract diff.' }
        $diff=Get-Content $output -Raw | ConvertFrom-Json -AsHashtable -Depth 100
        if ($diff.differences.Count -ne 1 -or $diff.differences[0].firstPresent -or -not $diff.differences[0].secondPresent -or
            $diff.differences[0].path -notmatch '^/declarations/\d+/methods/\d+/parameters/0/customAttributes/0$' -or
            $diff.differences[0].second.constructor.declaringType.name -cne 'AssociatedEnumAttribute' -or
            $diff.differences[0].second.fixedArguments[0].value -cne 'ASF_STATUSFLAGS') {
            throw "Unexpected changes outside the single intended association: $output"
        }
    }
    $control=Get-Content (Join-Path $evidence 'control\contracts-merged.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $failure=$null
    try { Assert-Association $control } catch { $failure=$_.Exception.Message }
    if ($failure -cne 'pdwStatusFlags must retain its ASF_STATUSFLAGS association.') {
        throw "Unannotated source did not fail the intended negative control: $failure"
    }
    $manifest['negativeControl']=[ordered]@{variant='control';result='rejected';diagnostic=$failure}
    $negativeDirectory=Join-Path $evidence 'negative-native'
    New-Item -ItemType Directory -Path $negativeDirectory -Force | Out-Null
    $negativeHeader=Join-Path $negativeDirectory 'wmcontainer.h'
    $negativeSource=$candidateSource.Replace($association,$association.Replace('DWORD *','ULONGLONG *'))
    [IO.File]::WriteAllText($negativeHeader,$negativeSource,[Text.UTF8Encoding]::new($false))
    $negativeArgs=@('--target=x86_64-pc-windows-msvc','-x','c++','-std=c++17','-fms-compatibility','-ferror-limit=0',
        '-D_COM_NO_STANDARD_GUIDS_=1','-DWIN32METADATA=1','-resource-dir',$ResourceDirectory,'-isystem',$negativeDirectory)
    foreach ($include in @((Join-Path $root 'generation\WinSDK\AdditionalHeaders'),(Join-Path $root 'generation\WinSDK\inc'))) { $negativeArgs+=@('-isystem',$include) }
    foreach ($part in @('shared','um','ucrt','winrt')) { $negativeArgs+=@('-isystem',(Join-Path $sdk $part)) }
    $negativeCapture=[PowerbaseNativeProbe]::Capture($libclang,(Join-Path $PSScriptRoot 'native.cpp'),$negativeHeader,$negativeArgs)
    Save $negativeCapture (Join-Path $negativeDirectory 'capture.json')
    $errors=@($negativeCapture.diagnostics | Where-Object severity -ge 3)
    if (-not $negativeCapture.hasErrors -or $errors.Count -ne 1 -or $errors[0].text -notmatch 'static assertion failed.*__is_same') {
        throw 'Native widening mutation must fail exactly the intended signature assertion.'
    }
    $manifest['negativeNativeControl']=[ordered]@{mutation='DWORD* to ULONGLONG*';result='rejected by native signature assertion';diagnostic=$errors[0].text}
    foreach ($file in $manifest.implementation) {
        if ((Get-FileHash $file.path).Hash -cne $file.sha256) { throw "Implementation changed during evidence collection: $($file.path)" }
    }
    if ((Get-FileHash $patch).Hash -cne $manifest.patch.sha256) { throw 'Patch changed during evidence collection.' }
    $manifest.status='targeted native and forward-association gates passed; complete header obligations remain open'
} catch {
    $manifest.status='blocked'
    $manifest['failure']=$_.Exception.Message
    throw
} finally {
    $env:LIBCLANG_PATH=$previousClang
    $env:CLANG_RESOURCE_DIR=$previousResource
    $env:PATH=$previousPath
    $manifest['artifacts']=@(Get-ChildItem $evidence -File -Recurse | Where-Object Name -ne 'manifest.json' | Sort-Object FullName | ForEach-Object { Identity $_.FullName })
    Save $manifest (Join-Path $evidence 'manifest.json')
}
Write-Host $manifest.status
