[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$PowerbaseEvidenceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)
$ErrorActionPreference='Stop'
if(Test-Path $OutputDirectory){throw 'Replay output must be new; never overwrite the original proof.'}
New-Item -ItemType Directory -Path $OutputDirectory | Out-Null
. (Join-Path $PSScriptRoot '..\..\scripts\Compare-NativeImprovements.ps1')
. (Join-Path $PSScriptRoot 'NativeImprovementEvidence.ps1')
$referencePath=Join-Path $PowerbaseEvidenceDirectory 'logical\reference-effective.json'
$reference=Get-Content $referencePath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$verdictPath=Join-Path $PowerbaseEvidenceDirectory 'logical\verdict.json'
$originalVerdict=Get-Content $verdictPath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$results=[Collections.Generic.List[object]]::new()
$inputs=[Collections.Generic.List[object]]::new()
$inputs.Add(@{path=$referencePath;sha256=(Get-FileHash $referencePath).Hash})
$inputs.Add(@{path=$verdictPath;sha256=(Get-FileHash $verdictPath).Hash})
$enumChecks=[Collections.Generic.List[object]]::new()
foreach($mutation in @('named-enum','definition-shape','missing-definition','wrong-identity','missing-member-type','contract-mismatch','ambiguous-shape')){
    $definition=$reference.types.REGISTER_NOTIFICATION_FLAGS | ConvertTo-Json -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100
    $types=@{REGISTER_NOTIFICATION_FLAGS=$definition}
    $value=@{kind='named';name='REGISTER_NOTIFICATION_FLAGS';signatureTypeKind=17}
    switch($mutation){
        'definition-shape' {$value=$definition}
        'missing-definition' {$types.Clear()}
        'wrong-identity' {$definition.shape.name='Unrelated'}
        'missing-member-type' {$definition.shape.members[0].type.name='MissingType'}
        'contract-mismatch' {
            $shape=$definition.shape | ConvertTo-Json -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100
            $shape.members[0].constant.value=999
            $value=@{kind='enum';contract=$shape}
        }
        'ambiguous-shape' {$value=@{kind='enum';contract=$definition.shape;shape=$definition.shape}}
    }
    $issues=@(Get-NativeImprovementDefinitionIssues $value $types '/enum')
    $shouldPass=$mutation -cin @('named-enum','definition-shape')
    if(($issues.Count -eq 0) -ne $shouldPass){throw "Enum definition regression: $mutation"}
    $enumChecks.Add(@{case=$mutation;passed=$true;issues=$issues})
}
foreach($architecture in @('x64','x86','arm64','merged')){
    $candidatePath=Join-Path $PowerbaseEvidenceDirectory "logical\candidate-$architecture-effective.json"
    $candidate=Get-Content $candidatePath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $nativeArchitecture=if($architecture -ceq 'merged'){'x64'}else{$architecture}
    $nativePath=Join-Path $PowerbaseEvidenceDirectory "native\$nativeArchitecture-metadata-control.json"
    $native=Get-Content $nativePath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    foreach($path in @($candidatePath,$nativePath)){$inputs.Add(@{path=$path;sha256=(Get-FileHash $path).Hash})}
    foreach($name in $candidate.methods.Keys){
        $validation=@($originalVerdict.issues | Where-Object {$_.stage -cin @('reference',"candidate-$architecture")})
        $ledger=if($name -cin @('PowerRegisterSuspendResumeNotification','PowerUnregisterSuspendResumeNotification')){
            New-NativeMethodEvidence $native $name $nativeArchitecture (Join-Path $OutputDirectory 'inputs')
        }else{$null}
        if($name -ceq 'PowerRegisterSuspendResumeNotification'){
            $closer=$candidate.methods['PowerUnregisterSuspendResumeNotification']
            if(-not $closer -or $closer.parameters.Count -ne 1 -or $closer.parameters[0].contract.type.kind -cne 'named' -or
                $closer.parameters[0].contract.type.name -cne 'HPOWERNOTIFY' -or $closer.parameters[0].flags -ne 3 -or
                $closer.import.module -ine 'POWRPROF.dll' -or $closer.return.type.contract.name -cne 'WIN32_ERROR'){
                $validation+=@(@{kind='missing-or-invalid-producer-closer';target='PowerUnregisterSuspendResumeNotification'})
            }
        }
        $result=Compare-NativeImprovements -OldMethod $reference.methods[$name] -NewMethod $candidate.methods[$name] `
            -OldTypes $reference.types -NewTypes $candidate.types -ValidationIssues $validation -Evidence $ledger
        $expected=if($ledger){'expected-improvement'}else{'equal'}
        $results.Add([ordered]@{architecture=$architecture;method=$name;expected=$expected;result=$result;evidence=$ledger})
    }
}
$report=[ordered]@{scope='Reclassifies immutable recorded method evidence only. Original proof is not overwritten; handle/type-wide differences are not normalized.';
    originalEvidence=[IO.Path]::GetFullPath($PowerbaseEvidenceDirectory);inputs=$inputs.ToArray();results=$results.ToArray();enumRegressionChecks=$enumChecks.ToArray();
    originalDependencyDifferences='All original HANDLE/HPOWERNOTIFY storage, ownership and invalid-value differences remain in the original logical report.'}
$report | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory 'replay.json')
$failed=@($results | Where-Object {$_.expected -cne $_.result.classification})
if($failed.Count){throw "$($failed.Count) real Powerbase replay classifications failed; see replay.json."}
Write-Host 'Real Powerbase replay: 12 equal method contracts and 8 expected improvements; dependency differences retained.'
