[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$OriginalEvidenceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string]$OriginalManifestSha256='0B85C3F8C0C566315E419E0F7E94C4294912E27019EFC2A201232B9762444568'
)
$ErrorActionPreference='Stop'
$repo=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$original=[IO.Path]::GetFullPath($OriginalEvidenceDirectory)
$destination=[IO.Path]::GetFullPath($OutputDirectory)
if(Test-Path -LiteralPath $destination){throw 'COM replay requires a fresh directory.'}
function Identity([string]$Path){@{path=[IO.Path]::GetFullPath($Path);sha256=(Get-FileHash -LiteralPath $Path).Hash;bytes=(Get-Item -LiteralPath $Path).Length}}
function Check($File){if((Get-FileHash -LiteralPath $File.path).Hash -cne $File.sha256){throw "Evidence drift: $($File.path)"}}
$priorManifest=Identity (Join-Path $original 'manifest.json')
if($priorManifest.sha256 -cne $OriginalManifestSha256){throw 'Wrong original evidence manifest.'}
$prior=Get-Content $priorManifest.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
foreach($file in @($prior.artifacts)+@($prior.implementation)+@($prior.compiler,$prior.reference,$prior.candidateHeader)){Check $file}
New-Item -ItemType Directory -Path $destination | Out-Null
foreach($part in @('inputs','native','contracts','comparison','tests')){New-Item -ItemType Directory -Path (Join-Path $destination $part) | Out-Null}
$implementation=@(
    'scripts\Compare-ComProjectionPolicy.ps1','scripts\Compare-ProjectionPolicy.ps1','scripts\ProjectionPolicy.psd1',
    'scripts\Compare-NativeImprovements.ps1','scripts\Test-PowerbaseLogical.ps1',
    'tests\ComProjectionPolicy\ComNativeProbe.cs','tests\ComProjectionPolicy\Replay-ComProjectionPolicy.ps1',
    'tests\ComProjectionPolicy\Test-ComProjectionPolicy.ps1' | ForEach-Object {Identity (Join-Path $repo $_)})
$frozen=@(
    'scripts\Compare-ProjectionPolicy.ps1','scripts\ProjectionPolicy.psd1','scripts\Replay-PowrprofProjectionPolicy.ps1',
    'tests\PowrprofPilot\Test-ProjectionPolicy.ps1','tests\PowrprofPilot\PROJECTION-POLICY.md',
    'tests\PowerbasePilot\NativeProbe.cs','scripts\Compare-PowrprofEvidence.ps1',
    'tests\PowrprofPilot\REPORT.md','generation\WinSDK\patches\post-midl\powrprof.h.win32metadata.patch',
    'generation\WinSDK\patches\post-midl\powerbase.h.win32metadata.patch' | ForEach-Object {Identity (Join-Path $repo $_)})
. (Join-Path $repo 'scripts\Compare-ComProjectionPolicy.ps1')
$images=@()
foreach($command in $prior.commands | Where-Object {$_.arguments -ccontains 'contracts'}){
    $args=$command.arguments
    $image=Identity $args[[array]::IndexOf($args,'--winmd')+1]
    $decode=Identity $args[[array]::IndexOf($args,'--output')+1]
    $snapshot=Get-Content $decode.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    if($snapshot.source.sha256 -cne $image.sha256){throw 'Original decoded image mismatch.'}
    $images+=@(@{image=$image;decode=$decode})
}
if($images.Count -ne 8){throw 'Original candidate/control image census differs.'}
$candidate=Get-Content (Join-Path $original 'candidate\contracts-x64.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$ownership=Get-Content (Join-Path $original 'candidate\native-x64-cpp.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$ownedNames=@($ownership.ownedDeclarations | Where-Object {$_.source.file -ceq $prior.candidateHeader.path} |
    ForEach-Object {$_.name} | Sort-Object -Unique -CaseSensitive)
$discovered=@()
foreach($type in $candidate.declarations | Where-Object {($_.attributes.value -band 0x20) -ne 0 -and $_.name -cin $ownedNames}){
    foreach($method in $type.methods){
        if((ConvertTo-Json -InputObject $method.signature -Compress -Depth 40) -cmatch '"name":"GUID"'){
            $discovered+=@(@{interface=$type.qualifiedName;name=$type.name;method=$method.name})
        }
    }
}
if($discovered.Count -eq 0){throw 'No actual GUID-bearing COM methods discovered.'}
$interfaces=@($discovered.name | Sort-Object -Unique -CaseSensitive)
Save-Json $discovered (Join-Path $destination 'comparison\discovery.json')
$reader=Join-Path $repo 'bin\Release\net10.0\WinmdUtils.dll'
$readerIdentity=Identity $reader
$referencePath=Join-Path $destination 'contracts\reference.json'
$decodeArgs=@($reader,'contracts','--winmd',$prior.reference.path,'--output',$referencePath)
foreach($name in $interfaces){$decodeArgs+=@('--root',$name)}
& dotnet @decodeArgs *> (Join-Path $destination 'contracts\reference.log')
if($LASTEXITCODE){throw 'Published reference decode failed.'}
$reference=Get-Content $referencePath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
if($reference.source.sha256 -cne $prior.reference.sha256){throw 'Reference identity differs.'}
$sdkRoot=Split-Path (Split-Path $prior.stockHeader.path)
$contexts=@{};$nativeCommands=@()
Add-Type -Path (Join-Path $PSScriptRoot 'ComNativeProbe.cs')
foreach($arch in @('x64','x86','arm64')){
    $capturePath=Join-Path $original "candidate\native-$arch-cpp.json"
    $capturePin=@($prior.artifacts | Where-Object {$_['path'] -ceq $capturePath})
    if($capturePin.Count -ne 1){throw 'Native source capture missing from manifest.'}
    $context=New-ProjectionPolicyEvidence -CapturePath $capturePath -CaptureSha256 $capturePin[0].sha256 `
        -SdkRoot $sdkRoot -SdkVersion '10.0.26100.7705' -Architecture $arch -OutputDirectory (Join-Path $destination 'inputs')
    foreach($mode in @('cpp','c-vtable')){
        $previousPath=Join-Path $original "candidate\native-$arch-$mode.json"
        $previous=Get-Content $previousPath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
        $tu=Join-Path $original 'inputs\native.cpp'
        if((Get-FileHash $tu).Hash -cne (Get-FileHash $previous.file).Hash){throw 'Original TU and retained source bytes differ.'}
        $names=@($interfaces)+@($interfaces | ForEach-Object {"${_}Vtbl"})+@('IUnknown','IUnknownVtbl')
        $capture=[ComProjectionNativeProbe]::Capture($prior.compiler.path,$tu,[string[]]$previous.arguments,[string[]]$names)
        $path=Join-Path $destination "native\$arch-$mode.json"
        Save-Json $capture $path
        if($capture.hasErrors -or $capture.declarations.Count -eq 0){throw 'Native-only COM capture failed or empty.'}
        $context[$(if($mode -ceq 'cpp'){'comCpp'}else{'comVtable'})]=Identity $path
        $nativeCommands+=@(@{api='ComProjectionNativeProbe.Capture';compiler=$prior.compiler;file=(Identity $tu);
            originalFile=$previous.file;arguments=$previous.arguments;selectedNames=$names;
            originalCapture=(Identity $previousPath);output=(Identity $path);purpose='native-only context; no metadata generation'})
    }
    $cpp=Read-ComCapture $context.comCpp $context 'cpp'
    foreach($source in @($cpp.declarations | ForEach-Object {$_.source.file} | Sort-Object -Unique -CaseSensitive)){
        if($source -cnotin $context.sources.origin){
            $pin=Identity $source;$copy=Join-Path $destination "inputs\$($pin.sha256).h"
            Copy-Item -LiteralPath $source -Destination $copy
            $context.sources+=@(@{origin=$source;path=$copy;sha256=$pin.sha256})
        }
    }
    $contexts[$arch]=$context
}
Save-Json $contexts (Join-Path $destination 'native\contexts.json')
$rows=@();$stageSummaries=@()
foreach($arch in @('x64','x86','arm64','merged')){
    $path=Join-Path $original "candidate\contracts-$arch.json"
    $snapshot=Get-Content $path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    if($arch -ceq 'merged' -and $snapshot.source.sha256 -cne $candidate.source.sha256){
        throw 'Merged context reuse requires actual candidate image byte identity.'}
    Copy-Item -LiteralPath $path -Destination (Join-Path $destination "contracts\candidate-$arch.json")
    $context=$contexts[$(if($arch -ceq 'merged'){'x64'}else{$arch})]
    $stage=@()
    foreach($method in $discovered){
        $result=Compare-ComProjectionPolicy -OldSnapshot $reference -NewSnapshot $snapshot `
            -InterfaceName $method.interface -MethodName $method.method -Evidence $context
        $result['architecture']=$arch;$result['referenceImageHash']=$reference.source.sha256;$result['candidateImageHash']=$snapshot.source.sha256
        $stage+=@($result);$rows+=@($result)
    }
    Save-Json $stage (Join-Path $destination "comparison\$arch-methods.json")
    $stageSummaries+=@(@{architecture=$arch;discovered=$stage.Count;contextValidated=@($stage | Where-Object {$_.context}).Count;
        methodsWithExplanations=@($stage | Where-Object {$_.explanations.Count}).Count;
        explainedPaths=@($stage | ForEach-Object {$_.explainedPaths}).Count;
        fullyEquivalent=@($stage | Where-Object classification -CNE 'review-required').Count;
        reviewRequired=@($stage | Where-Object classification -CEQ 'review-required').Count})
}
Save-Json $stageSummaries (Join-Path $destination 'comparison\summary.json')
if($discovered.Count -ne 5 -or @($stageSummaries | Where-Object {
    $_.discovered -ne 5 -or $_.contextValidated -ne 1 -or $_.methodsWithExplanations -ne 1 -or
    $_.explainedPaths -ne 1 -or $_.fullyEquivalent -ne 0 -or $_.reviewRequired -ne 5
}).Count){throw 'The bounded real wmcontainer COM replay differs from its verified coverage/limits.'}
& pwsh -NoProfile -File (Join-Path $PSScriptRoot 'Test-ComProjectionPolicy.ps1') -EvidenceDirectory $destination `
    *> (Join-Path $destination 'tests\regressions.log')
if($LASTEXITCODE){throw "COM boundaries failed; see $destination\tests\regressions.log"}
foreach($file in @($prior.artifacts)+@($prior.implementation)+$implementation+$frozen+@($priorManifest,$prior.compiler,$prior.reference,$readerIdentity)){Check $file}
$manifest=@{status='verified bounded COM parameter explanations; method/interface residuals remain';adapter='com-method-context/v1';
    repositoryHead=(git -C $repo rev-parse HEAD);originalManifest=$priorManifest;originalArtifacts=$prior.artifacts.Count;
    policy=$projectionPolicy;implementation=$implementation;frozenSources=$frozen;headerProvider=$prior.headerProvider;
    header=$prior.candidateHeader;images=$images;reference=$prior.reference;reader=$readerIdentity;
    referenceCommand=@{executable='dotnet';arguments=$decodeArgs;output=(Identity $referencePath)};
    nativeCommands=$nativeCommands;contexts=$contexts;summary=$stageSummaries;
    limits='Direct IUnknown inheritance only; no native references, overloads, new semantic exceptions, return/context normalization or whole-header closure.';
    sourceConsistency='All original artifacts, original test sources, prior policy files and executed sources unchanged.';
    artifacts=@(Get-ChildItem $destination -Recurse -File | ForEach-Object {Identity $_.FullName})}
Save-Json $manifest (Join-Path $destination 'manifest.json')
$stageSummaries | ForEach-Object {[pscustomobject]$_} | Format-Table
Write-Host "Replayed $($rows.Count) actual COM methods. Rule explanations and unresolved method/context obligations remain separate."
