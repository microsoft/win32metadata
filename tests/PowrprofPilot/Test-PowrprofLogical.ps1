[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
. (Join-Path $root 'scripts\Compare-PowrprofEvidence.ps1') -EvidenceDirectory $EvidenceDirectory -DefinitionsOnly
$fixture=Read-Contract 'candidate-x64'
$originalInventory=$inventory
$results=[Collections.Generic.List[object]]::new()
function Clone($Value){ConvertTo-Json -InputObject $Value -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100}
foreach($mutation in @('valid','cycle','unresolved-link','extra-field','missing-marker','pointer-leaf','wrong-signedness','wrong-width','no-source','missing-target')){
    $snapshot=Clone $fixture
    $inventory=Clone $originalInventory
    $regsam=Get-Definition $snapshot 'REGSAM'
    $access=Get-Definition $snapshot 'ACCESS_MASK'
    switch($mutation){
        'cycle' {$access.fields[0].type=Clone $regsam.fields[0].type}
        'unresolved-link' {$regsam.fields[0].type.fullName='Missing.ACCESS_MASK'}
        'extra-field' {$regsam.fields+=@(Clone $regsam.fields[0])}
        'missing-marker' {$regsam.customAttributes=@()}
        'pointer-leaf' {$access.fields[0].type=@{kind='pointer';elementType=@{kind='primitive';name='Void'}}}
        'wrong-signedness' {$access.fields[0].type.name='Int32'}
        'wrong-width' {($inventory.dependencyDeclarations | Where-Object name -CEQ 'REGSAM').underlyingType.size=8}
        'no-source' {$inventory.dependencyDeclarations=@($inventory.dependencyDeclarations | Where-Object name -CNE 'REGSAM')}
        'missing-target' {$snapshot.declarations=@($snapshot.declarations | Where-Object name -CNE 'REG_SAM_FLAGS')}
    }
    $method=Find-Method $snapshot 'PowerSettingAccessCheckEx'
    $parameter=@($method.parameters | Where-Object sequence -eq 3)[0]
    $issues.Clear()
    $slot=Effective-Slot $method.signature.parameterTypes[2] $parameter.customAttributes $snapshot "test-$mutation" 'AccessType'
    if($mutation -eq 'valid'){
        if($issues.Count -ne 0 -or $slot.type.kind -cne 'enum'){throw 'Valid source-backed alias storage rejected.'}
    }elseif($issues.Count -eq 0){throw "Unsafe alias storage accepted: $mutation"}
    $results.Add([ordered]@{name="alias-$mutation";result='passed'})
}
$inventory=$originalInventory
$old=Effective-Method (Find-Method $reference 'PowerReadFriendlyName') $reference 'reference'
$new=Effective-Method (Find-Method $fixture 'PowerReadFriendlyName') $fixture 'candidate-x64'
$native=@($inventory.directDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq 'PowerReadFriendlyName'})[0]
foreach($mutation in @('real-const-encoding','dropped-const','wrong-level','optional-modifier','unqualified-native','double-pointer','changed-identity')){
    $before=Clone $old;$after=Clone $new;$source=Clone $native
    switch($mutation){
        'dropped-const' {$after.parameters[1].contract.type=$after.parameters[1].contract.type.element}
        'wrong-level' {
            $qualified=$after.parameters[1].contract.type
            $leaf=$qualified.element.element
            $qualified.element=$leaf
            $after.parameters[1].contract.type=@{kind='pointer';element=$qualified}
        }
        'optional-modifier' {$after.parameters[1].contract.type.required=$false}
        'unqualified-native' {$source.parameters[1].type.canonical='_GUID *'}
        'double-pointer' {$source.parameters[1].type.canonical='const _GUID **'}
        'changed-identity' {$after.parameters[1].contract.type.element.element.name='UnrelatedType'}
    }
    $proof=@(Normalize-ConstEncoding $before $after $source)
    $differences=@(Diff-Facts $before $after)
    if($mutation -eq 'real-const-encoding'){
        if($proof.Count -ne 3 -or $differences.Count -ne 3 -or
            @($differences | Where-Object path -notlike '/parameters/*/contract/type/element/name').Count){
            throw 'Exact native const-level normalization did not preserve GUID identity differences.'
        }
    }elseif($mutation -eq 'changed-identity'){
        if(-not @($differences | Where-Object {$_.path -ceq '/parameters/1/contract/type/element/name' -and $_.second -ceq 'UnrelatedType'}).Count){
            throw 'Const normalization concealed a pointee identity change.'
        }
    }elseif($proof.Count -ne 2 -or $differences.Count -le 3){throw "Unsafe const normalization accepted: $mutation"}
    $results.Add([ordered]@{name="const-$mutation";result='passed';retainedDifferences=$differences.Count})
}
$documentation=Get-Content (Join-Path $EvidenceDirectory 'inputs\documentation-evidence.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$documentation.statusReturnConventions=@(& (Join-Path $PSScriptRoot 'ReturnEvidence.ps1'))
$source=@($inventory.directDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq 'PowerReplaceDefaultPowerSchemes'})[0]
$old=Effective-Method (Find-Method $reference $source.name) $reference 'reference'
$new=Effective-Method (Find-Method $fixture $source.name) $fixture 'candidate-x64'
foreach($mutation in @('documented-status','missing-evidence','wrong-section','reversed-success','native-width','native-signedness',
    'missing-definition','missing-association','wrong-storage','changed-members','unintended-change')){
    $before=Clone $old;$after=Clone $new;$native=Clone $source;$docs=Clone $documentation;$snapshot=Clone $fixture
    switch($mutation){
        'missing-evidence' {$docs.statusReturnConventions=@()}
        'wrong-section' {$docs.statusReturnConventions[0].section='Remarks'}
        'reversed-success' {$docs.statusReturnConventions[0].quote='Nonzero means success; zero means failure.'}
        'native-width' {$native.returnType.size=8}
        'native-signedness' {$native.returnType.canonical='long'}
        'missing-definition' {$snapshot.declarations=@($snapshot.declarations | Where-Object name -CNE 'WIN32_ERROR')}
        'missing-association' {(Find-Method $snapshot $source.name).parameters=@()}
        'wrong-storage' {$after.return.type.contract.storage.name='UInt64'}
        'changed-members' {$after.return.type.contract.members.sha256='not-the-complete-native-enum'}
        'unintended-change' {$after.import.attributes.value=$after.import.attributes.value -bxor 0x40}
    }
    $accepted=@(Get-ErrorAssociationImprovement $before $after $native $snapshot $docs)
    if($mutation -in @('documented-status','unintended-change')){
        if($accepted.Count -ne 1){throw 'Valid documented status enrichment was not recognized.'}
        $remaining=@(Diff-Facts $before $after | Where-Object {$accepted[0].paths -cnotcontains $_.path})
        if(($mutation -eq 'documented-status' -and $remaining.Count -ne 0) -or
            ($mutation -eq 'unintended-change' -and $remaining.Count -eq 0)){throw 'Status enrichment concealed an unrelated change.'}
    }elseif($accepted.Count){throw "Unsafe status enrichment accepted: $mutation"}
    $results.Add([ordered]@{name="status-$mutation";result='passed'})
}
$candidateNative=Get-Content (Join-Path $EvidenceDirectory 'native\x64-metadata-candidate.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$type=Get-Definition $fixture 'GLOBAL_POWER_POLICY'
$old=Full-Type (Get-Definition $reference 'GLOBAL_POWER_POLICY') $reference 'reference'
$new=Full-Type $type $fixture 'candidate-x64'
foreach($mutation in @('type-availability','wrong-platform','missing-documentation','missing-annotation','wrong-argument-type','unintended-layout')){
    $before=Clone $old;$after=Clone $new;$native=Clone $candidateNative;$docs=Clone $documentation
    switch($mutation){
        'wrong-platform' {$after.attributes[0].fixed[0].value='windows6.0.6000'}
        'missing-documentation' {$docs.recordAndEnumAvailability=@()}
        'missing-annotation' {($native.ownedDeclarations | Where-Object name -CEQ 'GLOBAL_POWER_POLICY').annotations=@()}
        'wrong-argument-type' {$after.attributes[0].fixed[0].type.name='Int32'}
        'unintended-layout' {$after.layout.size=1}
    }
    $accepted=@(Type-AvailabilityImprovement $before $after $type $native $docs)
    if($mutation -in @('type-availability','unintended-layout')){
        if($accepted.Count -ne 1){throw 'Actual documented type availability enrichment was rejected.'}
        $remaining=@(Diff-Facts $before $after | Where-Object {$accepted[0].paths -cnotcontains $_.path})
        if(($mutation -eq 'type-availability' -and $remaining.Count -ne 0) -or
            ($mutation -eq 'unintended-layout' -and $remaining.Count -eq 0)){throw 'Type availability concealed layout differences.'}
    }elseif($accepted.Count){throw "Unsafe availability enrichment accepted: $mutation"}
    $results.Add([ordered]@{name="availability-$mutation";result='passed'})
}
$macroName='EnableSysTrayBatteryMeter'
$probe=Get-Content (Join-Path $EvidenceDirectory 'inventory\macro-values-x64.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$native=@($probe.ownedDeclarations | Where-Object name -CEQ "T_$macroName")[0]
$macro=@($inventory.macros | Where-Object name -CEQ $macroName)[0]
$old=Macro-Contract @($reference.declarations | ForEach-Object {$_.fields} | Where-Object name -CEQ $macroName)[0] $reference 'reference'
$new=Macro-Contract @($fixture.declarations | ForEach-Object {$_.fields} | Where-Object name -CEQ $macroName)[0] $fixture 'candidate-x64'
foreach($mutation in @('native-signedness','changed-value','wrong-source-type','wrong-width','missing-source','changed-flags')){
    $before=Clone $old;$after=Clone $new;$source=Clone $native
    switch($mutation){
        'changed-value' {$after.constant.value=2}
        'wrong-source-type' {$source.type.canonical='const unsigned int'}
        'wrong-width' {$source.type.size=8}
        'missing-source' {$source=$null}
        'changed-flags' {$after.flags=$after.flags -bxor 0x10}
    }
    $accepted=@(Constant-StorageImprovement $before $after $source $macro)
    if($mutation -in @('native-signedness','changed-flags')){
        if($accepted.Count -ne 1){throw 'Native constant signedness was not recognized.'}
        $remaining=@(Diff-Facts $before $after | Where-Object {$accepted[0].paths -cnotcontains $_.path})
        if($mutation -eq 'changed-flags' -and -not @($remaining | Where-Object path -CEQ '/flags').Count){
            throw 'Signedness classification concealed changed field flags.'
        }
    }elseif($accepted.Count){throw "Unsafe constant signedness accepted: $mutation"}
    $results.Add([ordered]@{name="constant-$mutation";result='passed'})
}
foreach($name in @('PWRSCHEMESENUMPROC','PWRSCHEMESENUMPROC_V1','PDEVICE_NOTIFY_CALLBACK_ROUTINE')){
    $before=Full-Type (Get-Definition $reference $name) $reference 'reference'
    $after=Full-Type (Get-Definition $fixture $name) $fixture 'candidate-x64'
    if(-not $before.methods.Contains('Invoke') -or -not $after.methods.Contains('Invoke')){throw "Callback Invoke missing: $name"}
    $differences=@(Diff-Facts $before $after)
    if(@($differences | Where-Object path -match '^/methods/\d+/').Count){throw 'Callback collection order affected member identity.'}
    if(-not @($differences | Where-Object path -CEQ '/methods/.ctor').Count){throw 'Missing delegate constructor was hidden.'}
    $direct=@(Diff-Facts $before.methods.Invoke $after.methods.Invoke '/methods/Invoke')
    $reported=@($differences | Where-Object path -like '/methods/Invoke/*')
    if(@(Diff-Facts $direct $reported).Count){throw 'Callback Invoke was compared against a different method.'}
    $results.Add([ordered]@{name="callback-identity-$name";result='passed';invokeDifferences=$direct.Count})
}
$results.ToArray() | ConvertTo-Json -Depth 10 | Set-Content -Encoding utf8 (Join-Path $EvidenceDirectory 'alias-regression-checks.json')
Write-Host "$($results.Count) source-backed comparison-boundary checks passed."
