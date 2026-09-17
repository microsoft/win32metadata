[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [switch]$RequireEquivalent,
    [Parameter(DontShow)][switch]$FunctionsOnly
)

$ErrorActionPreference='Stop'
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
$contracts=Join-Path $evidence 'contracts'
$output=Join-Path $evidence 'logical'
if (-not $FunctionsOnly) { New-Item -ItemType Directory -Force -Path $output | Out-Null }
$methods=@('CallNtPowerInformation','GetPwrCapabilities','PowerDeterminePlatformRoleEx',
    'PowerRegisterSuspendResumeNotification','PowerUnregisterSuspendResumeNotification')
$ownerTypes=@('HPOWERNOTIFY','POWER_PLATFORM_ROLE_VERSION','REGISTER_NOTIFICATION_FLAGS')
$issues=[Collections.Generic.List[object]]::new()
$namespaceMappings=[Collections.Generic.List[object]]::new()
$enumConsumptions=[Collections.Generic.List[object]]::new()
$usagePolicies=[Collections.Generic.List[object]]::new()

function Save-Json($Value,[string]$Path) {
    ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 $Path
}
function Read-Contract([string]$Name) {
    $file=Join-Path $contracts "$Name.json"
    if (-not (Test-Path $file)) { throw "Missing serialization audit input $file. Run Compare-PowerbaseEvidence.ps1 first." }
    return Get-Content $file -Raw | ConvertFrom-Json -AsHashtable -Depth 100
}
function Get-Definition($Snapshot,[string]$Name) {
    $found=@($Snapshot.declarations | Where-Object { $_.qualifiedName -ceq $Name -or $_.name -ceq $Name })
    if ($found.Count -eq 1) { return $found[0] }
    return $null
}
function Stable-TypeName($Type,$Snapshot,[string]$Stage,[string]$Use) {
    $definition=Get-Definition $Snapshot $Type.fullName
    if ($definition) { return $definition.name }
    if ($Type.fullName -like 'System.*') { return $Type.fullName }
    $issues.Add([ordered]@{stage=$Stage;use=$Use;kind='unresolved-type';target=$Type.fullName;scope=$Type.scope})
    return "UNRESOLVED:$($Type.fullName)"
}
function Convert-Type($Type,$Snapshot,[string]$Stage,[string]$Use) {
    if ($null -eq $Type) { return $null }
    switch ($Type.kind) {
        'primitive' { return [ordered]@{kind='primitive';name=$Type.name} }
        'type' { return [ordered]@{kind='named';name=Stable-TypeName $Type $Snapshot $Stage $Use;signatureTypeKind=$Type.signatureTypeKind} }
        'pointer' { return [ordered]@{kind='pointer';element=Convert-Type $Type.elementType $Snapshot $Stage $Use} }
        'modified' { return [ordered]@{kind='modified';required=$Type.required;modifier=Stable-TypeName $Type.modifier $Snapshot $Stage $Use;element=Convert-Type $Type.elementType $Snapshot $Stage $Use} }
        default {
            $copy=[ordered]@{}
            foreach($key in @($Type.Keys | Sort-Object -CaseSensitive)) {
                if($key -eq 'evidence'){continue}
                $value=$Type[$key]
                if($value -is [Collections.IDictionary] -and $value.Contains('kind')) {
                    $copy[$key]=Convert-Type $value $Snapshot $Stage $Use
                } elseif($value -is [array]) {
                    $copy[$key]=@($value | ForEach-Object { if($_ -is [Collections.IDictionary] -and $_.Contains('kind')){Convert-Type $_ $Snapshot $Stage $Use}else{$_} })
                } else { $copy[$key]=$value }
            }
            if ($Type.kind -ceq 'array' -and $Type.rank -eq 1 -and
                $Type.sizes -is [array] -and $Type.sizes.Count -eq 1 -and $Type.sizes[0] -gt 0 -and
                $Type.lowerBounds -is [array] -and $Type.lowerBounds.Count -eq 0) {
                $copy.lowerBounds=@(0)
            }
            return $copy
        }
    }
}
function Enum-Shape($Definition,$Snapshot,[string]$Stage) {
    if (-not $Definition -or $Definition.baseType.fullName -cne 'System.Enum') { throw 'Enum shape requires an actual emitted enum definition.' }
    $storage=@($Definition.fields | Where-Object name -CEQ 'value__')
    if($storage.Count -ne 1){throw "Invalid enum storage for $($Definition.qualifiedName)"}
    $values=@($Definition.fields | Where-Object name -CNE 'value__' | Sort-Object name -CaseSensitive | ForEach-Object {
        [ordered]@{name=$_.name;flags=$_.attributes.value;type=Convert-Type $_.type $Snapshot $Stage "$($Definition.name).$($_.name)";
            constant=if($_.constant){[ordered]@{type=$_.constant.typeCode;value=$_.constant.value}}else{$null};
            offset=$_.offset;marshalling=$_.marshalling;
            attributes=Effective-Attributes $_.customAttributes $Snapshot $Stage "$($Definition.name).$($_.name)"}
    })
    [ordered]@{name=$Definition.name;typeFlags=($Definition.attributes.value -band (-bnot 0x100000));layout=$Definition.layout;
        storage=Convert-Type $storage[0].type $Snapshot $Stage $Definition.name;
        storageFieldFlags=$storage[0].attributes.value;storageMarshalling=$storage[0].marshalling;
        storageAttributes=Effective-Attributes $storage[0].customAttributes $Snapshot $Stage "$($Definition.name).value__";
        members=$values;flags=(@($Definition.customAttributes | Where-Object {$_.constructor.declaringType.fullName -eq 'System.FlagsAttribute'}).Count -eq 1);
        scoped=(@($Definition.customAttributes | Where-Object {$_.constructor.declaringType.name -eq 'ScopedEnumAttribute'}).Count -eq 1)}
}
function Attribute-Schema($Definition,$Snapshot,[string]$Stage) {
    if(-not $Definition){return $null}
    $schema=Schema-Value $Definition $Snapshot $Stage $Definition.name
    if ($Definition.baseType.fullName -ceq 'System.Attribute') {
        $schema.attributes=$schema.attributes -band (-bnot 0x20000)
        foreach ($constructor in @($schema.methods | Where-Object name -CEQ '.ctor')) {
            foreach ($parameter in $constructor.parameters) { $parameter.Remove('name') }
        }
    }
    return $schema
}
function Attribute-Usage($Definition) {
            $found=@($Definition.customAttributes | Where-Object {$_.constructor.declaringType.fullName -ceq 'System.AttributeUsageAttribute'})
            if($found.Count -gt 1){throw "Conflicting AttributeUsage on $($Definition.name)"}
            $usage=[ordered]@{targets=32767;allowMultiple=$false;inherited=$true;explicit=($found.Count -eq 1)}
            if($found.Count -eq 1){
                $usage.targets=[int]$found[0].fixedArguments[0].value
                foreach($argument in $found[0].namedArguments){
                    switch -CaseSensitive ($argument.name){
                        'AllowMultiple' {$usage.allowMultiple=[bool]$argument.value}
                        'Inherited' {$usage.inherited=[bool]$argument.value}
                        default {throw "Unsupported AttributeUsage argument: $($argument.name)"}
                    }
                }
            }
            return $usage
        }
function Current-UsageCompatible($Old,$New,$Snapshot,[string]$Stage) {
            $oldUsage=Attribute-Usage $Old
            $newUsage=Attribute-Usage $New
            $uses=[Collections.Generic.List[object]]::new()
            foreach($type in $Snapshot.declarations){
                $targets=@([ordered]@{name=$type.qualifiedName;attributes=$type.customAttributes;
                    mask=if($type.baseType.fullName -ceq 'System.ValueType'){8}else{0};
                    inheritanceIrrelevant=($type.baseType.fullName -ceq 'System.ValueType' -and ($type.attributes.value -band 0x100) -ne 0)})
                foreach($method in $type.methods){
                    $targets+=@([ordered]@{name=$method.qualifiedName;attributes=$method.customAttributes;mask=64;
                        inheritanceIrrelevant=(($method.attributes.value -band 0x10) -ne 0 -and $null -ne $method.import)})
                    foreach($parameter in $method.parameters){
                        $targets+=@([ordered]@{name="$($method.qualifiedName):$($parameter.sequence)";attributes=$parameter.customAttributes;
                            mask=if($parameter.sequence -eq 0){8192}else{2048};inheritanceIrrelevant=$false})
                    }
                }
                foreach($field in $type.fields){
                    $targets+=@([ordered]@{name=$field.qualifiedName;attributes=$field.customAttributes;mask=256;inheritanceIrrelevant=$false})
                }
                foreach($target in $targets){
                    $count=@($target.attributes | Where-Object {$_.constructor.declaringType.fullName -ceq $New.qualifiedName}).Count
                    if($count -eq 0){continue}
                    $valid=$target.mask -ne 0 -and ($oldUsage.targets -band $target.mask) -ne 0 -and
                        ($newUsage.targets -band $target.mask) -ne 0 -and
                        ($count -eq 1 -or ($oldUsage.allowMultiple -and $newUsage.allowMultiple)) -and $target.inheritanceIrrelevant
                    $uses.Add([ordered]@{target=$target.name;targetMask=$target.mask;count=$count;
                        inheritanceIrrelevant=$target.inheritanceIrrelevant;valid=$valid})
                }
            }
            $valid=$uses.Count -gt 0 -and @($uses | Where-Object {-not $_.valid}).Count -eq 0
            $usagePolicies.Add([ordered]@{stage=$Stage;attribute=$New.qualifiedName;reference=$oldUsage;candidate=$newUsage;
                uses=$uses.ToArray();currentUsesCompatible=$valid;generalPolicyEquivalent=$false})
            return $valid
        }
function Schema-Value($Value,$Snapshot,[string]$Stage,[string]$Use) {
    if ($null -eq $Value) { return $null }
    if ($Value -is [Collections.IDictionary]) {
        if ($Value.kind -in @('primitive','pointer','modified') -or ($Value.kind -eq 'type' -and $Value.fullName)) {
            return Convert-Type $Value $Snapshot $Stage $Use
        }
        $copy=[ordered]@{}
        foreach($key in @($Value.Keys | Sort-Object -CaseSensitive)) {
            if($key -in @('evidence','namespace','qualifiedName','designation')){continue}
            if($key -eq 'customAttributes') {
                $copy[$key]=Effective-Attributes $Value[$key] $Snapshot $Stage $Use
            } elseif($key -in @('attributes','implementationAttributes') -and $Value[$key] -is [Collections.IDictionary]) {
                $flags=$Value[$key].value
                if($key -eq 'attributes' -and $Value.kind -eq 'type'){$flags=$flags -band (-bnot 0x100000)}
                $copy[$key]=$flags
            } else {
                $copy[$key]=Schema-Value $Value[$key] $Snapshot $Stage $Use
            }
        }
        return $copy
    }
    if ($Value -is [array]) {
        return ,@($Value | ForEach-Object { Schema-Value $_ $Snapshot $Stage $Use })
    }
    return $Value
}
function Effective-Attributes($Attributes,$Snapshot,[string]$Stage,[string]$Use,[bool]$ConsumeEnum=$false) {
    $result=@(
        foreach($attribute in $Attributes) {
            if(-not $attribute){continue}
            $name=$attribute.constructor.declaringType.name
            if($name -eq 'DocumentationAttribute'){continue}
            if($ConsumeEnum -and $name -eq 'AssociatedEnumAttribute'){continue}
            $definition=Get-Definition $Snapshot $attribute.constructor.declaringType.fullName
            if(-not $definition -and $attribute.constructor.declaringType.fullName -notlike 'System.*') {
                $issues.Add([ordered]@{stage=$Stage;use=$Use;kind='unresolved-attribute-definition';target=$attribute.constructor.declaringType.fullName})
            }
            [ordered]@{name=if($definition){$definition.name}else{$attribute.constructor.declaringType.fullName};
                fixed=@($attribute.fixedArguments | ForEach-Object {[ordered]@{type=Convert-Type $_.type $Snapshot $Stage $Use;value=$_.value}});
                named=@($attribute.namedArguments | Sort-Object name -CaseSensitive | ForEach-Object {[ordered]@{kind=$_.kind;name=$_.name;type=Convert-Type $_.type $Snapshot $Stage $Use;value=$_.value}})}
        }
    )
    return ,@($result | Sort-Object {ConvertTo-Json -InputObject $_ -Compress -Depth 80})
}
function Effective-Slot($Type,$Attributes,$Snapshot,[string]$Stage,[string]$Use) {
    $associations=@($Attributes | Where-Object {$_ -and $_.constructor.declaringType.name -eq 'AssociatedEnumAttribute'})
    $definition=if($Type.kind -eq 'type'){Get-Definition $Snapshot $Type.fullName}else{$null}
    $typedEnum=$definition -and $definition.baseType.fullName -eq 'System.Enum'
    $enum=$null
    if($typedEnum){$enum=$definition}
    if($associations.Count -gt 0) {
        if($associations.Count -ne 1){throw "Conflicting enum associations on $Use"}
        if(-not (Get-Definition $Snapshot $associations[0].constructor.declaringType.fullName)) {
            $issues.Add([ordered]@{stage=$Stage;use=$Use;kind='unresolved-attribute-definition';target=$associations[0].constructor.declaringType.fullName})
        }
        $target=$associations[0].fixedArguments[0].value
        $enum=Get-Definition $Snapshot $target
        if(-not $enum -or $enum.baseType.fullName -ne 'System.Enum') {
            $issues.Add([ordered]@{stage=$Stage;use=$Use;kind='unresolved-associated-enum';target=$target})
            $enum=$null
        } else {
            $shape=Enum-Shape $enum $Snapshot $Stage
            $native=Convert-Type $Type $Snapshot $Stage $Use
            $storageMatches=(ConvertTo-Json -InputObject $native -Compress -Depth 50) -ceq (ConvertTo-Json -InputObject $shape.storage -Compress -Depth 50)
            if(-not $storageMatches) {
                $issues.Add([ordered]@{stage=$Stage;use=$Use;kind='associated-enum-storage-mismatch';native=$native;enumStorage=$shape.storage;target=$target})
                $enum=$null
            } else {
                $enumConsumptions.Add([ordered]@{stage=$Stage;use=$Use;nativeStorage=$native;target=$enum.qualifiedName;members=$shape.members;result='resolved-storage-checked'})
            }
        }
    }
    if($enum) {
        $effective=[ordered]@{kind='enum';contract=Enum-Shape $enum $Snapshot $Stage}
    } else {
        $effective=Convert-Type $Type $Snapshot $Stage $Use
    }
    [ordered]@{type=$effective;attributes=Effective-Attributes $Attributes $Snapshot $Stage $Use ([bool]$enum)}
}
function Effective-Method($Method,$Snapshot,[string]$Stage) {
    $parameters=@(
        for($index=0;$index -lt $Method.signature.parameterTypes.Count;$index++) {
            $row=@($Method.parameters | Where-Object sequence -eq ($index+1))
            if($row.Count -gt 1){throw "Duplicate parameter row on $($Method.name)"}
            $slot=Effective-Slot $Method.signature.parameterTypes[$index] @($row | ForEach-Object {$_.customAttributes}) $Snapshot $Stage "$($Method.name).parameter[$index]"
            [ordered]@{index=$index;name=if($row){$row[0].name}else{''};flags=if($row){$row[0].attributes.value}else{0};
                marshalling=if($row){$row[0].marshalling}else{$null};constant=if($row){$row[0].constant}else{$null};contract=$slot}
        }
    )
    $return=@($Method.parameters | Where-Object sequence -eq 0)
    [ordered]@{name=$Method.name;signatureHeader=$Method.signature.header;methodFlags=$Method.attributes.value;
        implementationFlags=$Method.implementationAttributes.value;import=$Method.import;
        parameters=$parameters;return=Effective-Slot $Method.signature.returnType @($return | ForEach-Object {$_.customAttributes}) $Snapshot $Stage "$($Method.name).return";
        returnFlags=if($return){$return[0].attributes.value}else{0};returnMarshalling=if($return){$return[0].marshalling}else{$null};
        attributes=Effective-Attributes $Method.customAttributes $Snapshot $Stage $Method.name}
}
function Effective-Type($Definition,$Snapshot,[string]$Stage) {
    if($Definition.baseType.fullName -eq 'System.Enum') {
        return [ordered]@{kind='enum';shape=Enum-Shape $Definition $Snapshot $Stage;attributes=Effective-Attributes @($Definition.customAttributes | Where-Object {$_.constructor.declaringType.fullName -ne 'System.FlagsAttribute'}) $Snapshot $Stage $Definition.name}
    }
    $fields=@($Definition.fields | ForEach-Object {
        [ordered]@{name=$_.name;flags=$_.attributes.value;type=Convert-Type $_.type $Snapshot $Stage "$($Definition.name).$($_.name)";
            offset=$_.offset;constant=if($_.constant){[ordered]@{type=$_.constant.typeCode;value=$_.constant.value}}else{$null};
            marshalling=$_.marshalling;attributes=Effective-Attributes $_.customAttributes $Snapshot $Stage "$($Definition.name).$($_.name)"}
    })
    [ordered]@{kind='type';name=$Definition.name;base=Convert-Type $Definition.baseType $Snapshot $Stage $Definition.name;
        # BeforeFieldInit is a managed initialization flag, not a native layout contract.
        flags=($Definition.attributes.value -band (-bnot 0x100000));layout=$Definition.layout;fields=$fields;
        attributes=Effective-Attributes $Definition.customAttributes $Snapshot $Stage $Definition.name}
}
function Capture-Effective($Snapshot,[string]$Stage) {
    $functionContracts=[ordered]@{}
    foreach($name in $methods) {
        $found=@($Snapshot.declarations | ForEach-Object {$_.methods} | Where-Object name -CEQ $name)
        if($found.Count -ne 1){throw "Expected exactly one method $name in $Stage."}
        $functionContracts[$name]=Effective-Method $found[0] $Snapshot $Stage
    }
    $typeContracts=[ordered]@{}
    foreach($type in $Snapshot.declarations | Sort-Object name -CaseSensitive) {
        if($type.name -eq 'Apis' -or $type.name -like '*Attribute'){continue}
        if($typeContracts.Contains($type.name)){throw "Ambiguous type name $($type.name) in $Stage; explicit identity mapping required."}
        $typeContracts[$type.name]=Effective-Type $type $Snapshot $Stage
    }
    [ordered]@{methods=$functionContracts;types=$typeContracts}
}
function Diff-Facts($First,$Second,[string]$Path='') {
    if($First -is [Collections.IDictionary] -and $Second -is [Collections.IDictionary]) {
        foreach($key in @(@($First.Keys)+@($Second.Keys)|Sort-Object -Unique -CaseSensitive)){
            if(-not $First.Contains($key) -or -not $Second.Contains($key)){
                [ordered]@{path="$Path/$key";first=$First[$key];second=$Second[$key];firstPresent=$First.Contains($key);secondPresent=$Second.Contains($key)}
            }else{Diff-Facts $First[$key] $Second[$key] "$Path/$key"}
        }
    }elseif($First -is [array] -and $Second -is [array]){
        for($i=0;$i -lt [Math]::Max($First.Count,$Second.Count);$i++){
            if($i -ge $First.Count -or $i -ge $Second.Count){
                [ordered]@{path="$Path/$i";first=if($i -lt $First.Count){$First[$i]}else{$null};second=if($i -lt $Second.Count){$Second[$i]}else{$null};firstPresent=($i -lt $First.Count);secondPresent=($i -lt $Second.Count)}
            }else{Diff-Facts $First[$i] $Second[$i] "$Path/$i"}
        }
    }elseif((ConvertTo-Json -InputObject $First -Compress -Depth 100) -cne (ConvertTo-Json -InputObject $Second -Compress -Depth 100)){
        [ordered]@{path=$Path;first=$First;second=$Second;firstPresent=$true;secondPresent=$true}
    }
}

if ($FunctionsOnly) { return }

$reference=Read-Contract 'reference'
$referenceEffective=Capture-Effective $reference 'reference'
Save-Json $referenceEffective (Join-Path $output 'reference-effective.json')
$comparisons=[Collections.Generic.List[object]]::new()
foreach($variant in @('control','candidate')){
    foreach($architecture in @('merged','x64','x86','arm64')){
        $stage="$variant-$architecture"
        $snapshot=Read-Contract $stage
        $effective=Capture-Effective $snapshot $stage
        Save-Json $effective (Join-Path $output "$stage-effective.json")
        $diff=@(Diff-Facts $referenceEffective $effective)
        Save-Json $diff (Join-Path $output "reference-to-$stage.json")
        foreach($type in $snapshot.declarations | Where-Object {$_.name -ne 'Apis'}){
            $old=Get-Definition $reference $type.name
            if(-not $old){continue}
            $oldSchema=if($old.name -like '*Attribute'){Attribute-Schema $old $reference 'reference'}else{Effective-Type $old $reference 'reference'}
            $newSchema=if($type.name -like '*Attribute'){Attribute-Schema $type $snapshot $stage}else{Effective-Type $type $snapshot $stage}
            $schemaDiff=@(Diff-Facts $oldSchema $newSchema)
            $currentUsesCompatible=$false
            if($schemaDiff.Count -gt 0 -and $type.baseType.fullName -ceq 'System.Attribute'){
                $oldWithoutUsage=[ordered]@{};foreach($key in $oldSchema.Keys){$oldWithoutUsage[$key]=$oldSchema[$key]}
                $newWithoutUsage=[ordered]@{};foreach($key in $newSchema.Keys){$newWithoutUsage[$key]=$newSchema[$key]}
                $oldWithoutUsage.customAttributes=@($oldSchema.customAttributes | Where-Object name -CNE 'System.AttributeUsageAttribute')
                $newWithoutUsage.customAttributes=@($newSchema.customAttributes | Where-Object name -CNE 'System.AttributeUsageAttribute')
                if(@(Diff-Facts $oldWithoutUsage $newWithoutUsage).Count -eq 0){
                    $currentUsesCompatible=Current-UsageCompatible $old $type $snapshot $stage
                }
            }
            $namespaceMappings.Add([ordered]@{stage=$stage;name=$type.name;reference=$old.qualifiedName;candidate=$type.qualifiedName;
                schemasMatch=($schemaDiff.Count -eq 0);currentUsesCompatible=$currentUsesCompatible;schemaDifferences=$schemaDiff})
        }
        $comparisons.Add([ordered]@{stage=$stage;effectiveDifferences=$diff.Count;referenceHash=$reference.source.sha256;candidateHash=$snapshot.source.sha256})
    }
}
$candidateIssues=@($issues | Where-Object stage -like 'candidate-*')
$candidateDiffs=@($comparisons | Where-Object {$_.stage -like 'candidate-*' -and $_.effectiveDifferences -ne 0})
$unmatchedSchemas=@($namespaceMappings | Where-Object {$_.stage -like 'candidate-*' -and -not $_.schemasMatch -and -not $_.currentUsesCompatible})
$equivalent=$candidateIssues.Count -eq 0 -and $candidateDiffs.Count -eq 0 -and $unmatchedSchemas.Count -eq 0
$verdict=[ordered]@{equivalent=$equivalent;comparisons=$comparisons.ToArray();issues=$issues.ToArray();
    namespaceMappings=$namespaceMappings.ToArray();enumConsumptions=$enumConsumptions.ToArray();
    currentUseAttributePolicies=$usagePolicies.ToArray();
    rules=@(
        'Namespaces pair only unique declaration names. Full source namespaces and schema differences are recorded; unmatched native schemas prevent equivalence. AttributeUsage-only differences require the explicit current-use checks below, not schema-wide compatibility.',
        'DocumentationAttribute, assembly/module identity, source tokens/blobs and BeforeFieldInit are not native behavior. Raw serialization audit preserves them.',
        'Only on managed System.Attribute-derived vocabulary classes, AutoClass and positional constructor parameter labels do not change attribute decoding. Native API parameters, native string-format flags, named fields/properties, AttributeUsage and multiplicity are not excluded.',
        'For closed rank-one fixed arrays with a positive encoded size, an omitted lower bound means zero (ECMA-335 II.23.2.13). Element type, rank, size and nonzero bounds remain compared.',
        'AttributeUsage-only differences permit current-use equivalence only when typed schemas/arguments otherwise match, both masks allow each realized placement/count, and each use is on a sealed native struct or static PInvoke. General target/inheritance/repetition policy remains unproven and recorded.',
        'An integer+AssociatedEnum slot is consumed only when exactly one emitted enum resolves and its primitive storage matches the original slot; complete member names/types/values and flags/scoped semantics remain compared.',
        'No primitive-vs-native-typedef, pointer modifier, ownership, invalid-value, parameter direction, byte-count, OS or enum membership difference is erased.',
        'No unresolved Windows.Win32 API/attribute reference is accepted as an external framework type.'
    )}
Save-Json $verdict (Join-Path $output 'verdict.json')
$report=[Collections.Generic.List[string]]::new()
$report.Add('# Effective powerbase contract report')
$report.Add('')
$report.Add("**Logical equivalence: $equivalent.** Raw serialization facts remain in ../comparison. Missing definitions, storage or behavior differences are not accepted by this view.")
$report.Add('')
$report.Add('| Stage | Effective differences |')
$report.Add('| --- | --- |')
foreach($comparison in $comparisons){$report.Add("| $($comparison.stage) | $($comparison.effectiveDifferences) |")}
$report.Add('')
$report.Add('## Explicit rules')
$report.Add('')
foreach($rule in $verdict.rules){$report.Add("- $rule")}
$report.Add('')
$report.Add('## Candidate merged differences')
$report.Add('')
$report.Add('| Path | Published reference | Candidate |')
$report.Add('| --- | --- | --- |')
$mergedDiff=Get-Content (Join-Path $output 'reference-to-candidate-merged.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
foreach($difference in $mergedDiff){
    $before=(ConvertTo-Json -InputObject $difference.first -Compress -Depth 100).Replace('|','\|')
    $after=(ConvertTo-Json -InputObject $difference.second -Compress -Depth 100).Replace('|','\|')
    $report.Add("| $($difference.path) | $before | $after |")
}
$report.Add('')
$report.Add('The enum consumer exercised each valid association through metadata target lookup and exact storage checking; `enumConsumptions` records the resulting member/value tables. Source-to-WinMD negative tests separately prove that missing associations and changed count semantics are rejected. This is not a claim that a third-party projection generator has been tested.')
[IO.File]::WriteAllLines((Join-Path $output 'REPORT.md'),$report,[Text.UTF8Encoding]::new($false))
Write-Host "Effective contract comparison complete. Equivalent=$equivalent; candidate issues=$($candidateIssues.Count); candidate stages with differences=$($candidateDiffs.Count)."
if($RequireEquivalent -and -not $equivalent){throw "Logical equivalence not established; see $output\verdict.json."}
