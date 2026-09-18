[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$ToolPath,
    [Parameter(Mandatory)][string]$ToolSha256,
    [Parameter(Mandatory)][string]$ToolSourceCommit,
    [Parameter(Mandatory)][string]$DocumentationEvidence,
    [Parameter(Mandatory)][string]$PowerbaseEvidenceDirectory
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
if(Test-Path $evidence){throw "Evidence directory exists: $evidence"}
if((Get-FileHash $ToolPath).Hash -cne $ToolSha256.ToUpperInvariant()){throw 'Consumer hash mismatch.'}
git -C $root merge-base --is-ancestor $ToolSourceCommit HEAD
if($LASTEXITCODE -ne 0){throw 'Required consumer source commit is not integrated.'}
git -C $root diff --quiet $ToolSourceCommit -- tools\rust
if($LASTEXITCODE -ne 0){throw 'Local tool source differs from the selected immutable consumer.'}
New-Item -ItemType Directory -Path (Join-Path $evidence 'inputs'),(Join-Path $evidence 'contracts') -Force | Out-Null
$packages=if($env:NUGET_PACKAGES){$env:NUGET_PACKAGES}else{Join-Path $HOME '.nuget\packages'}
$sdk=Join-Path $packages 'microsoft.windows.sdk.cpp\10.0.26100.7705\c\Include\10.0.26100.0'
$libs=Join-Path $packages 'microsoft.windows.sdk.cpp.x64\10.0.26100.7705\c\um\x64'
$libclang=Join-Path $packages 'libclang.runtime.win-x64\22.1.8\runtimes\win-x64\native\libclang.dll'
$patch=Join-Path $root 'generation\WinSDK\patches\post-midl\powrprof.h.win32metadata.patch'
$header=Join-Path $sdk 'um\powrprof.h'
$tool=Join-Path $evidence 'inputs\win32metadata-tools.exe'
$reader=Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
function Identity([string]$Path){[ordered]@{path=[IO.Path]::GetFullPath($Path);bytes=(Get-Item $Path).Length;sha256=(Get-FileHash $Path).Hash}}
function Save($Value,[string]$Path){ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 $Path}
$implementationPaths=@(
    $PSCommandPath,"$PSScriptRoot\Compare-PowrprofEvidence.ps1","$PSScriptRoot\Test-PowerbaseLogical.ps1",
    "$PSScriptRoot\Generate-Win32ErrorHeader.ps1","$PSScriptRoot\Generate-PowrprofRegistryHeader.ps1",
    "$PSScriptRoot\Compare-NativeImprovements.ps1",
    (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs'),(Join-Path $root 'tests\PowerbasePilot\shared.cpp'),
    (Join-Path $root 'tests\PowerbasePilot\Test-NativeImprovements.ps1'),
    (Join-Path $root 'sources\WinmdUtils\Program.cs'),
    (Join-Path $root 'generation\WinSDK\AdditionalHeaders\win32metadata_annotations.h')
)+@(Get-ChildItem (Join-Path $root 'tests\PowrprofPilot') -File | Where-Object Extension -in @('.ps1','.cpp','.cs') | ForEach-Object FullName)
$implementationPaths+=@(Get-ChildItem (Join-Path $root 'sources\MetadataUtils') -File -Recurse -Filter '*.cs' |
    Where-Object FullName -notmatch '\\(?:bin|obj)\\' | ForEach-Object FullName)
$manifest=[ordered]@{status='running';scope='powrprof.h direct declarations only; Foundation/Registry source-backed dependency bridges';
    sourceCommit=$ToolSourceCommit;repositoryHead=(& git -C $root rev-parse HEAD);tool=(Identity $ToolPath);
    sdk='10.0.26100.7705';header=(Identity $header);patch=(Identity $patch);compiler=(Identity $libclang);
    resourceDirectory=[IO.Path]::GetFullPath($ResourceDirectory);
    documentation=(Identity $DocumentationEvidence);commands=[Collections.Generic.List[object]]::new();
    recordedPowerbaseEvidence=[IO.Path]::GetFullPath($PowerbaseEvidenceDirectory);
    fullLibraryInputs=@(Get-ChildItem $libs -Filter '*.lib' -File | Sort-Object Name | ForEach-Object {Identity $_.FullName});
    implementation=@($implementationPaths | Sort-Object -Unique | ForEach-Object {Identity $_});
    packages=@(@('microsoft.windows.sdk.cpp','microsoft.windows.sdk.cpp.x64') | ForEach-Object {
        Identity (Join-Path $packages "$_\10.0.26100.7705\$_.10.0.26100.7705.nupkg")
    });
    componentGuards=[Collections.Generic.List[object]]::new();macroChecks=[Collections.Generic.List[object]]::new()}
function Run([string]$Exe,[string[]]$Arguments,[string]$Log,[string]$Directory=$root){
    $entry=[ordered]@{executable=$Exe;arguments=$Arguments;workingDirectory=$Directory;log=$Log;stderr="$Log.stderr"}
    $manifest.commands.Add($entry)
    Push-Location $Directory
    try{& $Exe @Arguments 1> $Log 2> "$Log.stderr";$entry.exitCode=$LASTEXITCODE}
    finally{Pop-Location}
    if($entry.exitCode -ne 0){throw "Command failed ($($entry.exitCode)): $Log.stderr"}
}
function Scrape([string]$Directory,[string]$Tu,[string]$Scope,[string]$Namespace,[string]$Overlay){
    New-Item -ItemType Directory -Force -Path $Directory | Out-Null
    $arguments=@('scrape','--partition',$Tu,'--include',$Overlay,
        '--include',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),'--include',(Join-Path $root 'generation\WinSDK\inc'),
        '--include',$sdk,'--lib',$libs,'--scope','__powrprof_pilot_no_directory_scope__','--scope-header',$Scope,
        '--namespace',$Namespace,'--arch','x64','--arch','x86','--arch','arm64','--assembly-name','Windows.Win32',
        '--output',(Join-Path $Directory 'Windows.Win32.winmd'),'--obj',(Join-Path $Directory 'obj'))
    Run $tool $arguments (Join-Path $Directory 'generation.log')
}
function Decode([string]$File,[string]$Name){
    $path=Join-Path $evidence "contracts\$Name.json"
    Run 'dotnet' @($reader,'contracts','--winmd',$File,'--output',$path) "$path.log"
    return Get-Content $path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
}
$priorClang=$env:LIBCLANG_PATH;$priorResource=$env:CLANG_RESOURCE_DIR
try{
    Copy-Item $ToolPath $tool
    Copy-Item $patch (Join-Path $evidence 'inputs\powrprof.h.win32metadata.patch')
    Copy-Item $DocumentationEvidence (Join-Path $evidence 'inputs\documentation-evidence.json')
    foreach($implementation in $manifest.implementation){
        $relative=[IO.Path]::GetRelativePath($root,$implementation.path)
        $copy=Join-Path $evidence "inputs\implementation\$relative"
        New-Item -ItemType Directory -Path (Split-Path $copy) -Force | Out-Null
        Copy-Item $implementation.path $copy
    }
    foreach($name in @('Cargo.toml','Cargo.lock')){Copy-Item (Join-Path $root "tools\rust\$name") (Join-Path $evidence "inputs\$name")}
    $env:LIBCLANG_PATH=Split-Path $libclang;$env:CLANG_RESOURCE_DIR=$ResourceDirectory
    Run 'dotnet' @('build',(Join-Path $root 'sources\WinmdUtils\WinmdUtils.csproj'),'-c','Release','--verbosity','quiet') (Join-Path $evidence 'build-reader.log')
    & (Join-Path $root 'tests\PowrprofPilot\Get-PowrprofInventory.ps1') -OutputDirectory (Join-Path $evidence 'inventory') -ResourceDirectory $ResourceDirectory
    $inventory=Get-Content (Join-Path $evidence 'inventory\inventory.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $manifest['baseline']=$inventory.baseline
    Copy-Item $inventory.baseline.path (Join-Path $evidence 'inputs\legacy.Windows.Win32.winmd')
    Copy-Item (Join-Path $evidence 'inventory\reference.json') (Join-Path $evidence 'contracts\reference.json')
    foreach($variant in @('control','candidate')){
        $directory=Join-Path $evidence $variant
        $overlay=Join-Path $directory 'headers'
        New-Item -ItemType Directory -Force -Path (Join-Path $overlay 'um') | Out-Null
        Copy-Item $header (Join-Path $overlay 'um\powrprof.h')
        if($variant -eq 'candidate'){
            Run 'git' @('apply','-p4',$patch) (Join-Path $directory 'patch-apply.log') $overlay
            $applied=Identity (Join-Path $overlay 'um\powrprof.h')
            Run 'git' @('apply','--reverse','-p4',$patch) (Join-Path $directory 'patch-reverse.log') $overlay
            if((Get-FileHash (Join-Path $overlay 'um\powrprof.h')).Hash -cne $manifest.header.sha256){throw 'Patch reversal did not restore source bytes.'}
            Run 'git' @('apply','-p4',$patch) (Join-Path $directory 'patch-reapply.log') $overlay
            if((Get-FileHash (Join-Path $overlay 'um\powrprof.h')).Hash -cne $applied.sha256){throw 'Patch reapplication changed.'}
            $manifest['candidateHeader']=$applied
            $originalDefines=@([regex]::Matches([IO.File]::ReadAllText($header),'(?m)^\s*#\s*(?:define|undef)\b[^\r\n]*') | ForEach-Object Value)
            $candidateDefines=@([regex]::Matches([IO.File]::ReadAllText($applied.path),'(?m)^\s*#\s*(?:define|undef)\b[^\r\n]*') | ForEach-Object Value)
            if(($originalDefines -join "`n") -cne ($candidateDefines -join "`n")){throw 'Native macro definitions changed.'}
            $manifest['nativeMacroPreservation']=[ordered]@{directives=$originalDefines.Count;result='All original define/undef lines byte-identical.'}
        }
        Scrape $directory (Join-Path $root 'tests\PowrprofPilot\main.cpp') 'powrprof' 'Windows.Win32.System.Power' $overlay
    }
    $foundation=Join-Path $evidence 'foundation'
    $shared=& "$PSScriptRoot\Generate-Win32ErrorHeader.ps1" -SdkInclude $sdk -Libclang $libclang -ResourceDirectory $ResourceDirectory -OutputDirectory $foundation
    $registry=Join-Path $evidence 'registry'
    $registrySource=& "$PSScriptRoot\Generate-PowrprofRegistryHeader.ps1" -SdkInclude $sdk -Libclang $libclang -ResourceDirectory $ResourceDirectory -OutputDirectory $registry
    Scrape $foundation (Join-Path $root 'tests\PowerbasePilot\shared.cpp') 'win32_error_metadata' 'Windows.Win32.Foundation' (Join-Path $foundation 'generated')
    Scrape $registry (Join-Path $root 'tests\PowrprofPilot\registry.cpp') 'registry_metadata' 'Windows.Win32.System.Registry' (Join-Path $registry 'generated')
    foreach($directory in @($foundation,$registry,(Join-Path $evidence 'control'),(Join-Path $evidence 'candidate'))){
        $x64=Identity (Join-Path $directory 'obj\Windows.Win32.x64.winmd')
        $merged=Identity (Join-Path $directory 'Windows.Win32.winmd')
        if($x64.sha256 -cne $merged.sha256){throw "Cannot reuse merged RDL as x64 for architecture-dependent component: $directory"}
        $manifest.componentGuards.Add([ordered]@{directory=$directory;x64=$x64;merged=$merged;result='byte-identical before composition'})
    }
    foreach($architecture in @('x64','x86','arm64','merged')){
        $rdl=if($architecture -in @('x64','merged')){'rdl'}else{$architecture}
        foreach($component in @(@{name='foundation';directory=$foundation;enum='WIN32_ERROR';count=3378},@{name='registry';directory=$registry;enum='REG_SAM_FLAGS';count=13})){
            $file=if($architecture -eq 'merged'){Join-Path $component.directory 'Windows.Win32.winmd'}else{Join-Path $component.directory "obj\Windows.Win32.$architecture.winmd"}
            $snapshot=Decode $file "$($component.name)-$architecture"
            $types=@($snapshot.declarations | Where-Object {$_.name -notin @('Apis','<Module>') -and $_.namespace -cne 'Windows.Win32.Foundation.Metadata'})
            $namespace=if($component.name -eq 'foundation'){'Windows.Win32.Foundation'}else{'Windows.Win32.System.Registry'}
            $apiMembers=@($snapshot.declarations | Where-Object name -CEQ 'Apis' | ForEach-Object {@($_.methods)+@($_.fields)})
            if($types.Count -ne 1 -or $types[0].name -cne $component.enum -or $types[0].namespace -cne $namespace -or
                $types[0].fields.Count -ne (1+$component.count) -or $apiMembers.Count -ne 0){throw 'Shared component leaks roots or omits enum members.'}
            $attributes=@($types[0].customAttributes | ForEach-Object {$_.constructor.declaringType.fullName})
            if(($component.name -eq 'foundation' -and $attributes.Count -ne 0) -or
                ($component.name -eq 'registry' -and ($attributes.Count -ne 1 -or $attributes[0] -cne 'System.FlagsAttribute'))){
                throw 'Shared enum flags contract mismatch.'
            }
            $storage=@($types[0].fields | Where-Object name -CEQ 'value__')[0]
            if($storage.type.name -cne 'UInt32' -or $storage.attributes.value -ne 1542){throw 'Shared enum storage contract mismatch.'}
            $sourceMembers=if($component.name -eq 'registry'){$registrySource.members}else{
                Get-Content (Join-Path $foundation 'members.json') -Raw | ConvertFrom-Json -AsHashtable
            }
            $expectedValues=@{}
            foreach($member in $sourceMembers){$expectedValues[$member.name]=[uint32]$member.value}
            foreach($member in $types[0].fields | Where-Object name -CNE 'value__'){
                if(-not $expectedValues.ContainsKey($member.name) -or $member.attributes.value -ne 32854 -or
                    $member.constant.typeCode -cne 'UInt32' -or [uint32]$member.constant.value -ne $expectedValues[$member.name]){
                    throw "Shared enum literal contract mismatch: $($member.name)"
                }
            }
        }
        foreach($variant in @('control','candidate')){
            $directory=Join-Path $evidence $variant
            $file=if($architecture -eq 'merged'){Join-Path $directory 'Windows.Win32.winmd'}else{Join-Path $directory "obj\Windows.Win32.$architecture.winmd"}
            New-Item -ItemType Directory -Force -Path (Join-Path $directory 'uncomposed') | Out-Null
            Copy-Item $file (Join-Path $directory "uncomposed\Windows.Win32.$architecture.winmd")
            Run $tool @('compile','--input',(Join-Path $foundation "obj\$rdl"),'--input',(Join-Path $registry "obj\$rdl"),
                '--input',(Join-Path $directory "obj\$rdl"),'--assembly-name','Windows.Win32','--output',$file) (Join-Path $directory "compose-$architecture.log")
            $snapshot=Decode $file "$variant-$architecture"
            $apis=@($snapshot.declarations | Where-Object name -ceq 'Apis')
            $functions=@($apis | ForEach-Object {$_.methods})
            if(@(Compare-Object @($inventory.functions.name) @($functions.name)).Count){throw 'Direct function inventory changed or transitive API root leaked.'}
            $constants=@($apis | ForEach-Object {$_.fields})
            if(@(Compare-Object @($inventory.macros.name) @($constants.name)).Count){throw 'Direct constants changed or helper/transitive constant leaked.'}
            foreach($function in $functions){
                if($function.namespace -cne 'Windows.Win32.System.Power' -or $function.import.module -ine 'POWRPROF.dll'){
                    throw "Incorrect root namespace/import: $($function.name)"
                }
            }
            $nativeArch=if($architecture -eq 'merged'){'x64'}else{$architecture}
            $macroProbe=Get-Content (Join-Path $evidence "inventory\macro-values-$nativeArch.json") -Raw | ConvertFrom-Json -AsHashtable -Depth 100
            $macroValues=@($macroProbe.ownedDeclarations | Where-Object name -CEQ 'PowrprofMacroValues')[0]
            foreach($macro in $inventory.macros){
                $fields=@($apis | ForEach-Object {$_.fields} | Where-Object name -CEQ $macro.name)
                $value=@($macroValues.members | Where-Object name -CEQ "V_$($macro.name)")[0]
                $native=@($macroProbe.ownedDeclarations | Where-Object name -CEQ "T_$($macro.name)")[0]
                $storage=switch -CaseSensitive ($native.type.canonical){
                    'const int' {'Int32'}
                    'const unsigned int' {'UInt32'}
                    default {throw "Unreviewed native macro type: $($native.type.canonical)"}
                }
                if($fields.Count -ne 1 -or $fields[0].attributes.value -ne 32854 -or
                    $fields[0].constant.typeCode -cne $storage -or [uint64]$fields[0].constant.value -ne $value.unsignedValue){
                    throw "Direct macro value/storage mismatch: $variant/$architecture/$($macro.name)"
                }
                $manifest.macroChecks.Add([ordered]@{variant=$variant;architecture=$architecture;symbol=$macro.name;
                    nativeType=$native.type.canonical;storage=$storage;value=$value.unsignedValue;result='source value and native storage match'})
            }
            $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
            foreach($type in $snapshot.declarations){if(-not $seen.Add($type.qualifiedName)){throw "Duplicate metadata type: $($type.qualifiedName)"}}
        }
    }
    & (Join-Path $root 'tests\PowrprofPilot\Test-PowrprofNative.ps1') -SdkInclude $sdk -CandidateInclude (Join-Path $evidence 'candidate\headers\um') `
        -Libclang $libclang -ResourceDirectory $ResourceDirectory -OutputDirectory (Join-Path $evidence 'native')
    & "$PSScriptRoot\Compare-PowrprofEvidence.ps1" -EvidenceDirectory $evidence
    & (Join-Path $root 'tests\PowrprofPilot\Test-PowrprofAnnotations.ps1') -EvidenceDirectory $evidence
    & (Join-Path $root 'tests\PowrprofPilot\Test-PowrprofLogical.ps1') -EvidenceDirectory $evidence
    & (Join-Path $root 'tests\PowerbasePilot\Test-NativeImprovements.ps1') *> (Join-Path $evidence 'native-improvement-regressions.log')
    & (Join-Path $root 'tests\PowrprofPilot\Test-RecordedPowerbaseImprovements.ps1') `
        -PowerbaseEvidenceDirectory $PowerbaseEvidenceDirectory -OutputDirectory (Join-Path $evidence 'recorded-powerbase-reclassification')
    Save $manifest (Join-Path $evidence 'manifest.json')
    & (Join-Path $root 'tests\PowrprofPilot\Test-PowrprofNegative.ps1') -EvidenceDirectory $evidence
    foreach($implementation in $manifest.implementation){
        if((Get-FileHash $implementation.path).Hash -cne $implementation.sha256){throw "Implementation changed during run: $($implementation.path)"}
    }
    if((Get-FileHash $patch).Hash -cne $manifest.patch.sha256){throw 'Patch changed during run.'}
    $manifest['sourceConsistency']='All executed implementation sources and the patch remained byte-identical throughout this run.'
    $manifest.status='generated and compared; see explicit symbol verdicts, not a blanket equivalence pass'
}catch{
    $manifest.status='blocked'
    $manifest['failure']=$_.Exception.Message
    throw
}finally{
    $manifest['files']=@(Get-ChildItem $evidence -File -Recurse | Where-Object Name -ne manifest.json | Sort-Object FullName | ForEach-Object {Identity $_.FullName})
    Save $manifest (Join-Path $evidence 'manifest.json')
    $env:LIBCLANG_PATH=$priorClang;$env:CLANG_RESOURCE_DIR=$priorResource
}
