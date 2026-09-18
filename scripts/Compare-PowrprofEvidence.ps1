[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [Parameter(DontShow)][switch]$DefinitionsOnly
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
. "$PSScriptRoot\Test-PowerbaseLogical.ps1" -EvidenceDirectory $evidence -FunctionsOnly
. "$PSScriptRoot\Compare-NativeImprovements.ps1"
. (Join-Path $root 'tests\PowrprofPilot\NativeImprovementEvidence.ps1')
$reportDirectory=Join-Path $evidence 'comparison'
New-Item -ItemType Directory -Path $reportDirectory -Force | Out-Null
$inventory=Get-Content (Join-Path $evidence 'inventory\inventory.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$reference=Read-Contract 'reference'
$methods=@($inventory.functions.name)
$originalEnumShape=${function:Enum-Shape}
$enumCache=@{}
$originalEffectiveSlot=${function:Effective-Slot}
$aliasBindings=[Collections.Generic.List[object]]::new()
function Effective-Slot($Type,$Attributes,$Snapshot,[string]$Stage,[string]$Use){
    $associations=@($Attributes | Where-Object {$_.constructor.declaringType.name -ceq 'AssociatedEnumAttribute'})
    if($associations.Count -eq 1 -and $Type.kind -ceq 'type'){
        $current=$Type
        $chain=[Collections.Generic.List[object]]::new()
        $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
        while($current.kind -ceq 'type' -and $seen.Add($current.fullName)){
            $definition=Get-Definition $Snapshot $current.fullName
            if(-not $definition){break}
            $native=@(@($inventory.directDeclarations)+@($inventory.dependencyDeclarations) | Where-Object {
                $_.kind -ceq 'TypedefDecl' -and $_.name -ceq $definition.name
            })
            $custom=@($definition.customAttributes.constructor.declaringType.name)
            if($definition.baseType.fullName -cne 'System.ValueType' -or $definition.fields.Count -ne 1 -or
                $definition.fields[0].name -cne 'Value' -or $custom.Count -ne 1 -or $custom[0] -cne 'NativeTypedefAttribute' -or
                ($definition.attributes.value -band 0x118) -ne 0x108 -or $definition.layout.packingSize -ne 0 -or
                $definition.fields[0].customAttributes.Count -ne 0 -or $definition.fields[0].marshalling -or
                $definition.fields[0].constant -or ($definition.fields[0].attributes.value -band 0x10) -ne 0 -or
                $definition.layout.size -ne 0 -or $native.Count -ne 1 -or $native[0].underlyingType.size -ne 4 -or
                $native[0].underlyingType.canonical -cne 'unsigned long'){break}
            $chain.Add([ordered]@{type=$definition.qualifiedName;source=$native[0].source;nativeStorage=$native[0].underlyingType;
                sourceSha256=(Get-FileHash $native[0].source.file).Hash;
                metadataField=$definition.fields[0].type})
            $current=$definition.fields[0].type
        }
        if($chain.Count -gt 0 -and $current.kind -ceq 'primitive' -and $current.name -ceq 'UInt32'){
            $slot=& $originalEffectiveSlot $current $Attributes $Snapshot $Stage $Use
            $aliasBindings.Add([ordered]@{stage=$Stage;use=$Use;originalType=$Type;chain=$chain.ToArray();
                primitiveStorage=$current;purpose='only AssociatedEnum storage validation; native typedef/raw/type contracts retained'})
            return $slot
        }
    }
    return & $originalEffectiveSlot $Type $Attributes $Snapshot $Stage $Use
}
function Enum-Shape($Definition,$Snapshot,[string]$Stage){
    $key="$Stage/$($Definition.qualifiedName)"
    if(-not $enumCache.ContainsKey($key)){
        $shape=& $originalEnumShape $Definition $Snapshot $Stage
        $bytes=[Text.Encoding]::UTF8.GetBytes((ConvertTo-Json -InputObject $shape.members -Depth 100 -Compress))
        $shape.members=[ordered]@{count=$shape.members.Count;sha256=[Convert]::ToHexString([Security.Cryptography.SHA256]::HashData($bytes))}
        $enumCache[$key]=$shape
    }
    return $enumCache[$key]
}
function Raw-Value($Value){
    if($null -eq $Value){return $null}
    if($Value -is [Collections.IDictionary]){
        $copy=[ordered]@{}
        foreach($key in @($Value.Keys | Sort-Object -CaseSensitive)){if($key -cne 'evidence'){$copy[$key]=Raw-Value $Value[$key]}}
        return $copy
    }
    if($Value -is [array]){return ,@($Value | ForEach-Object {Raw-Value $_})}
    return $Value
}
function Full-Type($Type,$Snapshot,[string]$Stage){
    $result=Effective-Type $Type $Snapshot $Stage
    $members=[ordered]@{}
    foreach($method in $Type.methods){
        if($members.Contains($method.name)){throw "Overloaded type member requires explicit signature identity: $($Type.name).$($method.name)"}
        $members[$method.name]=Effective-Method $method $Snapshot $Stage
    }
    $result['methods']=$members
    return $result
}
function Find-Method($Snapshot,[string]$Name){
    $found=@($Snapshot.declarations | Where-Object name -CEQ 'Apis' | ForEach-Object {$_.methods} | Where-Object name -CEQ $Name)
    if($found.Count -ne 1){throw "Missing/duplicate exported method $Name"}
    return $found[0]
}
function Normalize-ConstEncoding($Before,$After,$Native){
    $proof=[Collections.Generic.List[object]]::new()
    for($index=0;$index -lt $Native.parameters.Count;$index++){
        $source=$Native.parameters[$index]
        if($source.type.canonical -cnotmatch '^const [^*]+\s+\*$'){continue}
        $old=$Before.parameters[$index].contract
        $new=$After.parameters[$index].contract
        $oldConst=@($old.attributes | Where-Object name -CEQ 'ConstAttribute')
        $newConst=@($new.attributes | Where-Object name -CEQ 'ConstAttribute')
        if($oldConst.Count -ne 1 -or $oldConst[0].fixed.Count -ne 0 -or $oldConst[0].named.Count -ne 0 -or
            $newConst.Count -ne 0 -or $old.type.kind -cne 'pointer' -or $old.type.element.kind -cnotin @('named','primitive') -or
            $new.type.kind -cne 'modified' -or $new.type.modifier -cne 'System.Runtime.CompilerServices.IsConst' -or
            $new.type.required -ne $true -or $new.type.element.kind -cne 'pointer' -or
            $new.type.element.element.kind -cnotin @('named','primitive')){continue}
        $proof.Add([ordered]@{parameter=$index;source=$source.source;nativeType=$source.type;
            sourceSha256=(Get-FileHash $source.source.file).Hash;
            oldEncoding=$oldConst[0];newEncoding=$new.type;
            rule='single native const-pointee pointer only; pointee identity remains compared separately'})
        $new.type=$new.type.element
        $new.attributes=@(@($new.attributes)+@($oldConst[0]) | Sort-Object {ConvertTo-Json -InputObject $_ -Compress -Depth 80})
    }
    return $proof.ToArray()
}
function Get-ErrorAssociationImprovement($Before,$After,$Native,$Snapshot,$Documentation){
    $docs=@($Documentation.additionalTypeAndVersionChecks | Where-Object {
        $_.symbols -ccontains $Native.name -and @($_.facts | Where-Object {$_ -cmatch '\bsystem error code\b'}).Count -gt 0
    })
    $docs+=@($Documentation.statusReturnConventions | Where-Object {
        $_.symbol -ceq $Native.name -and $_.section -ceq 'Return value' -and
        $_.quote -ceq 'Returns ERROR_SUCCESS (zero) if the call was successful, and a nonzero value if the call failed.'
    })
    if($docs.Count -ne 1 -or $Native.returnType.canonical -cne 'unsigned long' -or $Native.returnType.size -ne 4 -or
        $Before.return.type.kind -cne 'primitive' -or $Before.return.type.name -cne 'UInt32' -or $After.return.type.kind -cne 'enum'){return}
    $definition=Get-Definition $Snapshot 'Windows.Win32.Foundation.WIN32_ERROR'
    if(-not $definition -or $definition.qualifiedName -cne 'Windows.Win32.Foundation.WIN32_ERROR'){return}
    $contract=$After.return.type.contract
    $expected=Enum-Shape (Get-Definition $reference 'WIN32_ERROR') $reference 'reference'
    if($contract.name -cne 'WIN32_ERROR' -or $contract.storage.name -cne 'UInt32' -or $contract.members.count -ne 3378 -or
        @(Diff-Facts $expected $contract).Count -ne 0){return}
    $method=Find-Method $Snapshot $Native.name
    $return=@($method.parameters | Where-Object sequence -eq 0)[0]
    $association=@($return.customAttributes | Where-Object {$_.constructor.declaringType.name -ceq 'AssociatedEnumAttribute'})
    if($association.Count -ne 1 -or $association[0].fixedArguments[0].value -cne 'WIN32_ERROR'){return}
    $paths=@(Diff-Facts $Before.return.type $After.return.type '/return/type' | ForEach-Object path)
    [ordered]@{kind='documented Windows error-status return enrichment';symbol=$Native.name;paths=$paths;
        nativeReturn=$Native.returnType;nativeSource=$Native.source;nativeSourceHash=(Get-FileHash $Native.source.file).Hash;
        documentation=$docs[0];binding=$definition.qualifiedName;completeEnumContract=$contract;
        candidateImageHash=$Snapshot.source.sha256;
        verdict='expected improvement, not equality';scope='Only unchanged native UInt32 return plus real complete in-image enum; unrelated differences remain.'}
}
function Add-TypeReferences($Value,$Queue){
    if($Value -is [Collections.IDictionary]){
        if($Value.kind -ceq 'named' -and $Value.name -cnotlike 'System.*'){$Queue.Enqueue($Value.name)}
        elseif($Value.kind -ceq 'enum'){$Queue.Enqueue($Value.contract.name)}
        foreach($key in $Value.Keys){Add-TypeReferences $Value[$key] $Queue}
    }elseif($Value -is [array]){foreach($item in $Value){Add-TypeReferences $item $Queue}}
}
function Method-TypeClosure($Method,$Snapshot,[string]$Stage){
    $types=@{}
    $pending=[Collections.Generic.Queue[string]]::new()
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    Add-TypeReferences $Method $pending
    while($pending.Count){
        $name=$pending.Dequeue()
        if(-not $seen.Add($name)){continue}
        $definition=Get-Definition $Snapshot $name
        if(-not $definition){continue}
        $types[$name]=Effective-Type $definition $Snapshot $Stage
        Add-TypeReferences $types[$name] $pending
    }
    return $types
}
function Type-AvailabilityImprovement($Before,$After,$Type,$NativeCapture,$Documentation){
    $docs=@($Documentation.recordAndEnumAvailability | Where-Object symbol -CEQ $Type.name)
    $source=@($NativeCapture.ownedDeclarations | Where-Object {$_['kind'] -ceq 'TypedefDecl' -and $_['name'] -ceq $Type.name})
    if($docs.Count -ne 1 -or $source.Count -ne 1){return}
    $old=@($Before.attributes | Where-Object name -CEQ 'SupportedOSPlatformAttribute')
    $new=@($After.attributes | Where-Object name -CEQ 'SupportedOSPlatformAttribute')
    if($old.Count -ne 0 -or $new.Count -ne 1 -or $new[0].fixed.Count -ne 1 -or $new[0].named.Count -ne 0 -or
        $new[0].fixed[0].type.kind -cne 'primitive' -or $new[0].fixed[0].type.name -cne 'String'){return}
    $platform=$new[0].fixed[0].value
    $expected=@{'Windows XP'='windows5.1.2600';'Windows Vista'='windows6.0.6000';'Windows 8'='windows8.0';'Windows 8.1'='windows8.1'}[$docs[0].minimumClient]
    if($platform -cne $expected -or $source[0].annotations -cnotcontains "win32metadata:supported_os=$platform"){return}
    $others=@($After.attributes | Where-Object name -CNE 'SupportedOSPlatformAttribute')
    if(@(Diff-Facts $Before.attributes $others).Count){return}
    [ordered]@{kind='documented type availability enrichment';paths=@(Diff-Facts $Before.attributes $After.attributes '/attributes' | ForEach-Object path);
        source=$source[0].source;sourceHash=(Get-FileHash $source[0].source.file).Hash;documentation=$docs[0];
        platform=$platform;scope='Actual added type annotation only; all other type differences remain.'}
}
function Macro-Contract($Field,$Snapshot,[string]$Stage){
    if(-not $Field){return $null}
    [ordered]@{name=$Field.name;namespace=$Field.namespace;qualifiedName=$Field.qualifiedName;
        flags=$Field.attributes.value;type=(Convert-Type $Field.type $Snapshot $Stage $Field.name);
        constant=(Raw-Value $Field.constant);offset=$Field.offset;marshalling=$Field.marshalling;
        attributes=(Effective-Attributes $Field.customAttributes $Snapshot $Stage $Field.name)}
}
function Member-Contract($Field,$Snapshot,[string]$Stage){
    if(-not $Field){return $null}
    [ordered]@{name=$Field.name;flags=$Field.attributes.value;
        type=(Convert-Type $Field.type $Snapshot $Stage $Field.name);offset=$Field.offset;
        constant=(Raw-Value $Field.constant);marshalling=$Field.marshalling;
        attributes=(Effective-Attributes $Field.customAttributes $Snapshot $Stage $Field.name)}
}
function Constant-StorageImprovement($Before,$After,$Proof,$Macro){
    if(-not $Before -or -not $After -or $Proof.type.canonical -cne 'const int' -or $Proof.type.size -ne 4 -or
        $Before.constant.typeCode -cne 'UInt32' -or $After.constant.typeCode -cne 'Int32' -or
        $Before.constant.value -ne $After.constant.value -or $After.constant.value -lt 0 -or
        $After.constant.value -gt [int]::MaxValue -or $Before.type.kind -cne 'primitive' -or
        $Before.type.name -cne 'UInt32' -or $After.type.kind -cne 'primitive' -or $After.type.name -cne 'Int32'){return}
    [ordered]@{kind='compiler-proven native constant signedness';paths=@('/type/name','/constant/typeCode');
        native=$Proof;source=$Macro;scope='Same nonnegative value and 32-bit width; only storage signedness is explained.'}
}
if($DefinitionsOnly){return}
$documentation=Get-Content (Join-Path $evidence 'inputs\documentation-evidence.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$documentation.statusReturnConventions=@(& (Join-Path $root 'tests\PowrprofPilot\ReturnEvidence.ps1'))
$rows=[Collections.Generic.List[object]]::new()
$stages=[Collections.Generic.List[object]]::new()
foreach($variant in @('control','candidate')){
    foreach($architecture in @('merged','x64','x86','arm64')){
        $stage="$variant-$architecture"
        $snapshot=Read-Contract $stage
        $nativeArchitecture=if($architecture -ceq 'merged'){'x64'}else{$architecture}
        $nativeCapture=Get-Content (Join-Path $evidence "native\$nativeArchitecture-metadata-control.json") -Raw |
            ConvertFrom-Json -AsHashtable -Depth 100
        $nativeCandidate=Get-Content (Join-Path $evidence "native\$nativeArchitecture-metadata-candidate.json") -Raw |
            ConvertFrom-Json -AsHashtable -Depth 100
        $methodRows=[Collections.Generic.List[object]]::new()
        foreach($name in $methods){
            $old=Find-Method $reference $name
            $new=Find-Method $snapshot $name
            $first=Effective-Method $old $reference 'reference'
            $second=Effective-Method $new $snapshot $stage
            $native=@($inventory.directDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq $name})[0]
            $constEncoding=@(Normalize-ConstEncoding $first $second $native)
            $diff=@(Diff-Facts $first $second)
            $improvements=@(Get-ErrorAssociationImprovement $first $second $native $snapshot $documentation)
            $nativeClassification=$null
            if($name -ceq 'ReadGlobalPwrPolicy'){
                $ledger=New-NativeMethodEvidence $nativeCapture $name $nativeArchitecture (Join-Path $evidence 'improvement-inputs')
                $nativeClassification=Compare-NativeImprovements -OldMethod $first -NewMethod $second `
                    -OldTypes (Method-TypeClosure $first $reference 'reference') -NewTypes (Method-TypeClosure $second $snapshot $stage) `
                    -ValidationIssues @($issues | Where-Object stage -CEQ $stage) -Evidence $ledger
                if($nativeClassification.classification -ceq 'expected-improvement'){
                    $improvements+=@([ordered]@{kind='documentation-backed native direction correction';paths=$nativeClassification.explainedPaths;
                        evidence=$ledger;classification=$nativeClassification})
                }
            }
            $acceptedPaths=@($improvements | ForEach-Object {$_.paths})
            $unexplained=@($diff | Where-Object {$acceptedPaths -cnotcontains $_.path})
            $row=[ordered]@{kind='function';name=$name;source=@($inventory.functions | Where-Object name -CEQ $name)[0];
                verdict=if($diff.Count -eq 0){'equal'}elseif($unexplained.Count -eq 0){'expected improvement'}else{'unexplained/review-required'};
                representationEquivalences=$constEncoding;
                nativeClassification=$nativeClassification;
                expectedImprovements=$improvements;unexplainedDifferences=$unexplained;
                effectiveDifferences=$diff;rawDifferences=@(Diff-Facts (Raw-Value $old) (Raw-Value $new))}
            $methodRows.Add($row)
            if($stage -ceq 'candidate-merged'){$rows.Add($row)}
        }
        Save-Json $methodRows.ToArray() (Join-Path $reportDirectory "$stage-functions.json")
        $typeRows=[Collections.Generic.List[object]]::new()
        foreach($type in $snapshot.declarations | Where-Object {$_.name -notin @('Apis','<Module>')}){
            $old=Get-Definition $reference $type.name
            $isVocabulary=$type.namespace -ceq 'Windows.Win32.Foundation.Metadata'
            $diff=@()
            $usageCompatible=$false
            $typeImprovements=@()
            if($old){
                if($isVocabulary){
                    $first=Attribute-Schema $old $reference 'reference';$second=Attribute-Schema $type $snapshot $stage
                    $diff=@(Diff-Facts $first $second)
                    if($diff.Count){
                        $first.customAttributes=@($first.customAttributes | Where-Object name -CNE 'System.AttributeUsageAttribute')
                        $second.customAttributes=@($second.customAttributes | Where-Object name -CNE 'System.AttributeUsageAttribute')
                        if(@(Diff-Facts $first $second).Count -eq 0){$usageCompatible=Current-UsageCompatible $old $type $snapshot $stage}
                    }
                }else{
                    $first=Full-Type $old $reference 'reference';$second=Full-Type $type $snapshot $stage
                    $diff=@(Diff-Facts $first $second)
                    if($variant -ceq 'candidate'){$typeImprovements=@(Type-AvailabilityImprovement $first $second $type $nativeCandidate $documentation)}
                }
            }
            $typeAcceptedPaths=@($typeImprovements | ForEach-Object {$_.paths})
            $typeRows.Add([ordered]@{kind=if($isVocabulary){'vocabulary'}else{'type'};name=$type.name;qualifiedName=$type.qualifiedName;
                referencePresent=($null -ne $old);effectiveDifferences=$diff;currentUsesCompatible=$usageCompatible;
                expectedImprovements=$typeImprovements;unexplainedDifferences=@($diff | Where-Object {$typeAcceptedPaths -cnotcontains $_.path});
                rawDifferences=@(Diff-Facts (Raw-Value $old) (Raw-Value $type))})
        }
        Save-Json $typeRows.ToArray() (Join-Path $reportDirectory "$stage-types.json")
        $stages.Add([ordered]@{stage=$stage;hash=$snapshot.source.sha256;equalFunctions=@($methodRows | Where-Object verdict -CEQ 'equal').Count;
            improvedFunctions=@($methodRows | Where-Object verdict -CEQ 'expected improvement').Count;
            functionsWithExpectedImprovements=@($methodRows | Where-Object {$_.expectedImprovements.Count -gt 0}).Count;
            reviewFunctions=@($methodRows | Where-Object verdict -CEQ 'unexplained/review-required').Count;
            unresolved=@($issues | Where-Object stage -CEQ $stage).Count})
        if($stage -ceq 'candidate-merged'){
            $rdl=[IO.File]::ReadAllText((Join-Path $evidence 'candidate\obj\rdl\powrprof.rdl'))
            foreach($declaration in $inventory.directDeclarations | Where-Object {$_['kind'] -cne 'FunctionDecl'}){
                $name=$declaration.name.TrimStart('_')
                $type=Get-Definition $snapshot $name
                $old=Get-Definition $reference $name
                $typeRow=@($typeRows | Where-Object name -CEQ $name)
                $alias=-not $type -and [regex]::IsMatch($rdl,"(?m)^\s*type $([regex]::Escape($name))\s*=")
                $verdict=if($alias){'native pointer alias lowered at uses'}
                    elseif(-not $type){'missing symbol'}
                    elseif(-not $old){'source-available addition; review required'}
                    elseif($typeRow[0].effectiveDifferences.Count -eq 0){'equal'}
                    elseif($typeRow[0].unexplainedDifferences.Count -eq 0){'expected improvement'}
                    else{'unexplained/review-required'}
                $rows.Add([ordered]@{kind=$declaration.kind;name=$declaration.name;metadataName=$name;source=$declaration.source;verdict=$verdict;
                    expectedImprovements=if($typeRow){$typeRow[0].expectedImprovements}else{@()};
                    differences=if($typeRow){$typeRow[0].effectiveDifferences}else{@()}})
                foreach($member in @($declaration.fields)+@($declaration.members) | Where-Object {$_}){
                    $newField=@($type.fields | Where-Object name -CEQ $member.name)
                    $oldField=@($old.fields | Where-Object name -CEQ $member.name)
                    $diff=@(Diff-Facts (Raw-Value $oldField) (Raw-Value $newField))
                    $effective=@(Diff-Facts (Member-Contract $oldField[0] $reference 'reference') (Member-Contract $newField[0] $snapshot $stage))
                    $rows.Add([ordered]@{kind='native member';name="$name.$($member.name)";source=$member.source;
                        verdict=if($newField.Count -ne 1){'missing symbol'}elseif(-not $oldField.Count){'source-available addition; review required'}elseif($effective.Count -eq 0){'equal'}else{'unexplained/review-required'};
                        effectiveDifferences=$effective;rawDifferences=$diff})
                }
            }
            $macroProbe=Get-Content (Join-Path $evidence 'inventory\macro-values-x64.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
            foreach($macro in $inventory.macros){
                $new=@($snapshot.declarations | ForEach-Object {$_.fields} | Where-Object name -CEQ $macro.name)
                $old=@($reference.declarations | ForEach-Object {$_.fields} | Where-Object name -CEQ $macro.name)
                $diff=@(Diff-Facts (Raw-Value $old) (Raw-Value $new))
                $first=Macro-Contract $old[0] $reference 'reference';$second=Macro-Contract $new[0] $snapshot $stage
                $effective=@(Diff-Facts $first $second)
                $proof=@($macroProbe.ownedDeclarations | Where-Object {$_['name'] -ceq "T_$($macro.name)"})[0]
                $improvements=@(Constant-StorageImprovement $first $second $proof $macro)
                $accepted=@($improvements | ForEach-Object {$_.paths})
                $remaining=@($effective | Where-Object {$accepted -cnotcontains $_.path})
                $rows.Add([ordered]@{kind='macro';name=$macro.name;source=$macro;verdict=if($new.Count -ne 1){'missing symbol'}
                    elseif($old.Count -eq 0){'source-available addition; review required'}elseif($effective.Count -eq 0){'equal'}
                    elseif($remaining.Count -eq 0){'expected improvement'}else{'unexplained/review-required'};
                    expectedImprovements=$improvements;unexplainedDifferences=$remaining;effectiveDifferences=$effective;rawDifferences=$diff})
            }
        }
    }
}
if($rows.Count -ne 230){throw "Direct source ledger count changed: $($rows.Count), expected 230."}
$missing=@($rows | Where-Object verdict -CEQ 'missing symbol')
Save-Json $rows.ToArray() (Join-Path $reportDirectory 'all-direct-symbols.json')
Save-Json ([ordered]@{stages=$stages.ToArray();issues=$issues.ToArray();enumBindings=$enumConsumptions.ToArray();
    scalarAliasStorageBindings=$aliasBindings.ToArray();
    currentUseAttributePolicies=$usagePolicies.ToArray();enumContractHashes=$enumCache;
    rules=@('All direct source declarations, record/enum members and public macros are enumerated. Pointer aliases lower at uses and require generated RDL evidence.',
    'Callback method contracts including Invoke are compared, not just delegate type flags.',
    'Complete enum member contracts are hashed after full decoding; raw complete member tables remain in all contract snapshots.',
    'Exact/raw differences remain intact. No native handle, lifecycle, SAL, scalar signedness, source availability or new annotation is silently normalized.')}) (Join-Path $reportDirectory 'verdict.json')
$lines=@('# powrprof.h complete direct-symbol audit','','This is an evidence report, not a blanket equivalence claim.','',
    '| Stage | Equal methods | Improved-only methods | Methods with accepted improvements | Review-required methods | Unresolved references |','| --- | --- | --- | --- | --- | --- |')
foreach($stage in $stages){$lines+="| $($stage.stage) | $($stage.equalFunctions) | $($stage.improvedFunctions) | $($stage.functionsWithExpectedImprovements) | $($stage.reviewFunctions) | $($stage.unresolved) |"}
$lines+=@('','## Direct symbol ledger','','Every row links to exact facts in `all-direct-symbols.json`. Native tags and their typedef declarators are separate source declarations, not duplicate API claims.','',
    '| Kind | Symbol | Verdict |','| --- | --- | --- |')
foreach($row in $rows){$lines+="| $($row.kind) | $($row.name) | $($row.verdict) |"}
$lines | Set-Content -Encoding utf8 (Join-Path $reportDirectory 'REPORT.md')
if($missing.Count){throw "$($missing.Count) directly owned symbols are missing; see all-direct-symbols.json."}
if(@($issues | Where-Object {$_.stage -clike 'candidate-*'}).Count){throw 'Unresolved candidate contracts remain; see verdict.json.'}
Write-Host "Complete direct-symbol audit: $($rows.Count) rows; exact disagreements preserved."
