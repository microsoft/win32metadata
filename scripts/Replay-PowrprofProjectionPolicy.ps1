[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$OriginalEvidenceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string]$OriginalManifestSha256='1B151DD2D1AECE78629FAEF513EC4B4BE350CD4654F88677E20FB3850DFBA8FD'
)
$ErrorActionPreference='Stop'
$repo=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$original=[IO.Path]::GetFullPath($OriginalEvidenceDirectory)
$destination=[IO.Path]::GetFullPath($OutputDirectory)
if(Test-Path -LiteralPath $destination){throw 'Policy replay requires a fresh directory.'}
function Identity([string]$Path){
    @{path=[IO.Path]::GetFullPath($Path);sha256=(Get-FileHash -LiteralPath $Path).Hash;bytes=(Get-Item -LiteralPath $Path).Length}
}
function Check-Identity($File){
    if((Get-FileHash -LiteralPath $File.path).Hash -cne $File.sha256){throw "Evidence drift: $($File.path)"}
}
$priorManifest=Identity (Join-Path $original 'manifest.json')
if($priorManifest.sha256 -cne $OriginalManifestSha256){throw 'Original manifest pin does not match.'}
$prior=Get-Content -LiteralPath $priorManifest.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
foreach($file in $prior.files){Check-Identity $file}
Check-Identity $prior.baseline
New-Item -ItemType Directory -Path $destination | Out-Null
$implementation=@(
    'scripts\ProjectionPolicy.psd1','scripts\Compare-ProjectionPolicy.ps1','scripts\Replay-PowrprofProjectionPolicy.ps1',
    'scripts\Compare-PowrprofEvidence.ps1','scripts\Test-PowerbaseLogical.ps1','scripts\Compare-NativeImprovements.ps1',
    'tests\PowrprofPilot\Test-ProjectionPolicy.ps1','tests\PowrprofPilot\NativeImprovementEvidence.ps1',
    'tests\PowerbasePilot\Test-NativeImprovements.ps1' |
    ForEach-Object {Identity (Join-Path $repo $_)})
$images=@()
foreach($command in $prior.commands | Where-Object {$_.arguments -ccontains '--winmd'}){
    $args=$command.arguments
    $image=Identity $args[[array]::IndexOf($args,'--winmd')+1]
    $decode=Identity $args[[array]::IndexOf($args,'--output')+1]
    $snapshot=Get-Content -LiteralPath $decode.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    if($snapshot.source.sha256 -cne $image.sha256){throw 'Decoded image identity mismatch.'}
    $images+=@(@{image=$image;decode=$decode})
}
if($images.Count -ne 16){throw 'Original image census changed.'}
foreach($part in @('contracts','inventory','native','inputs','policy','comparison')){
    New-Item -ItemType Directory -Path (Join-Path $destination $part) | Out-Null
}
foreach($relative in @('contracts\reference.json','inventory\inventory.json')){
    Copy-Item -LiteralPath (Join-Path $original $relative) -Destination (Join-Path $destination $relative)
}
$sdkRoot=Split-Path (Split-Path $prior.header.path)
$contexts=@{}
foreach($arch in @('x64','x86','arm64')){
    $path=Join-Path $original "native\$arch-metadata-candidate.json"
    $pin=@($prior.files | Where-Object path -CEQ $path)
    if($pin.Count -ne 1){throw 'Native capture is absent from original manifest.'}
    . "$PSScriptRoot\Compare-ProjectionPolicy.ps1"
    $contexts[$arch]=New-ProjectionPolicyEvidence -CapturePath $path -CaptureSha256 $pin[0].sha256 `
        -SdkRoot $sdkRoot -SdkVersion $prior.sdk -Architecture $arch -OutputDirectory (Join-Path $destination 'inputs')
}
foreach($arch in @('x64','x86','arm64','merged')){
    Copy-Item -LiteralPath (Join-Path $original "contracts\candidate-$arch.json") -Destination (Join-Path $destination "contracts\candidate-$arch.json")
}
. "$PSScriptRoot\Compare-PowrprofEvidence.ps1" -EvidenceDirectory $destination -DefinitionsOnly
. "$PSScriptRoot\Compare-ProjectionPolicy.ps1"
$rows=[Collections.Generic.List[object]]::new();$summaries=@()
$priorObligations=Get-Content (Join-Path $original 'comparison\all-direct-symbols.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
Save-Json @($priorObligations | Where-Object kind -CNE 'function') (Join-Path $destination 'policy\unchanged-non-method-obligations.json')
foreach($arch in @('x64','x86','arm64','merged')){
    $stage="candidate-$arch"
    $snapshot=Read-Contract $stage
    if($arch -ceq 'merged' -and $snapshot.source.sha256 -cne (Read-Contract 'candidate-x64').source.sha256){
        throw 'Merged native x64 evidence reuse requires exact original image equality.'}
    $context=$contexts[$(if($arch -ceq 'merged'){'x64'}else{$arch})]
    $oldRows=Get-Content (Join-Path $original "comparison\$stage-functions.json") -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    if($oldRows.Count -ne $methods.Count -or @($oldRows.name | Sort-Object -Unique -CaseSensitive).Count -ne $methods.Count){throw 'Original method census differs.'}
    $stageRows=@()
    foreach($name in $methods){
        $previous=@($oldRows | Where-Object name -CEQ $name)
        if($previous.Count -ne 1){throw "Original method missing: $name"}
        $previous=$previous[0]
        $rawOld=Find-Method $reference $name;$rawNew=Find-Method $snapshot $name
        $before=Effective-Method $rawOld $reference 'reference';$after=Effective-Method $rawNew $snapshot $stage
        $native=@($inventory.directDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq $name})[0]
        $constProof=@(Normalize-ConstEncoding $before $after $native)
        $diff=@(Diff-Facts $before $after)
        $raw=@(Diff-Facts (Raw-Value $rawOld) (Raw-Value $rawNew))
        if(@(Diff-Facts $diff $previous.effectiveDifferences).Count -or @(Diff-Facts $raw $previous.rawDifferences).Count){
            throw "Replay changed the original raw/effective differences: $stage/$name"}
        $result=Compare-ProjectionPolicy -Before $before -After $after -OldMethod $rawOld -NewMethod $rawNew `
            -OldSnapshot $reference -NewSnapshot $snapshot -Evidence $context -ValidationIssues @($issues)
        $oldPaths=@($previous.expectedImprovements | ForEach-Object {$_.paths})
        $allPaths=@($result.explainedPaths)+$oldPaths
        $remaining=@($diff | Where-Object {$_.path -cnotin $allPaths})
        $hasImprovement=$previous.expectedImprovements.Count -gt 0 -or
            @($result.explanations | Where-Object classification -CEQ 'expected-improvement').Count -gt 0
        $classification=if($remaining.Count -or $result.rejected.Count){'review-required'}elseif($diff.Count -eq 0){'equal'}
            elseif($hasImprovement){'expected-improvement'}else{'projection-equivalent'}
        $row=[ordered]@{stage=$stage;name=$name;previousVerdict=$previous.verdict;classification=$classification;
            previousExpectedImprovements=$previous.expectedImprovements;previousConstEncoding=$constProof;
            projectionPolicy=$result;remaining=$remaining;effectiveDifferences=$diff;rawDifferences=$raw}
        $rows.Add($row);$stageRows+=@($row)
    }
    Save-Json $stageRows (Join-Path $destination "policy\$stage-methods.json")
    $summaries+=@(@{stage=$stage;methods=$stageRows.Count;equal=@($stageRows | Where-Object classification -CEQ 'equal').Count;
        equivalent=@($stageRows | Where-Object classification -CEQ 'projection-equivalent').Count;
        improved=@($stageRows | Where-Object classification -CEQ 'expected-improvement').Count;
        review=@($stageRows | Where-Object classification -CEQ 'review-required').Count;
        previousResiduals=@($stageRows | Where-Object previousVerdict -CEQ 'unexplained/review-required').Count;
        ruleUses=@($stageRows | ForEach-Object {$_.projectionPolicy.explanations} | Group-Object {$_['ruleId']} | Select-Object Name,Count)})
    $ruleIds=@($projectionPolicy.Rules.Values | ForEach-Object {$_.Id})
    if($summaries[-1].ruleUses.Count -ne $ruleIds.Count -or
        @($summaries[-1].ruleUses | Where-Object {$_.Name -cnotin $ruleIds -or $_.Count -le 0}).Count){
        throw 'Rule-use summary lost an approved rule identity.'}
}
Save-Json $contexts (Join-Path $destination 'policy\native-contexts.json')
Save-Json $summaries (Join-Path $destination 'policy\summary.json')
& pwsh -NoProfile -File (Join-Path $repo 'tests\PowrprofPilot\Test-ProjectionPolicy.ps1') -EvidenceDirectory $destination `
    *> (Join-Path $destination 'policy\regressions.log')
if($LASTEXITCODE -ne 0){throw "Projection boundary tests failed; see $destination\policy\regressions.log"}
& pwsh -NoProfile -File (Join-Path $repo 'tests\PowerbasePilot\Test-NativeImprovements.ps1') `
    *> (Join-Path $destination 'policy\native-improvement-regressions.log')
if($LASTEXITCODE -ne 0){throw "Native improvement regressions failed; see $destination\policy\native-improvement-regressions.log"}
foreach($file in @($prior.files)+$implementation){Check-Identity $file}
Check-Identity $priorManifest
Check-Identity $prior.baseline
if(@($summaries | Where-Object {$_.review -or $_.methods -ne 73 -or $_.previousResiduals -ne 48}).Count -or $issues.Count){
    throw 'Complete method replay did not close exactly the prior 48 residual rows.'}
$manifest=[ordered]@{status='verified method-policy replay; non-method obligations unchanged';policy=$projectionPolicy;
    repositoryHead=(git -C $repo rev-parse HEAD);originalManifest=$priorManifest;originalArtifactCount=$prior.files.Count;
    implementationState='Exact source bytes below were verified before commit; immutable commit is supplied by the final handoff.';
    originalPilotCommit='4eb2583e06e41560a05a048c1dabb05c230ea32c';generation='unchanged; no generation or metadata rewriting';
    tool=$prior.tool;baseline=$prior.baseline;sdk=$prior.sdk;images=$images;implementation=$implementation;
    nativeContexts=$contexts;summary=$summaries;unchangedObligations=@($priorObligations | Where-Object kind -CNE 'function' |
        Group-Object {$_['verdict']} | Select-Object Name,Count);sourceConsistency='All input and executed source fingerprints unchanged.';
    artifacts=@(Get-ChildItem -LiteralPath $destination -File -Recurse | ForEach-Object {Identity $_.FullName})}
Save-Json $manifest (Join-Path $destination 'manifest.json')
$summaries | ForEach-Object {[pscustomobject]$_} | Format-Table stage,methods,equal,equivalent,improved,review,previousResiduals
Write-Host "Verified policy $($projectionPolicy.Version); original evidence untouched; $($rows.Count) method comparisons."
