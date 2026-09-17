[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [Parameter(Mandatory)][string]$OutputPath
)

$ErrorActionPreference='Stop'
$repository=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
. (Join-Path $repository 'scripts\Test-PowerbaseLogical.ps1') -EvidenceDirectory $EvidenceDirectory -FunctionsOnly
$fixture=Read-Contract 'reference'
$results=[Collections.Generic.List[object]]::new()

function Copy-Value($Value) {
    ConvertTo-Json -InputObject $Value -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100
}
function Require([bool]$Condition,[string]$Message) {
    if(-not $Condition){throw $Message}
}
function Test-Case([string]$Name,[scriptblock]$Action) {
    $issues.Clear()
    & $Action
    $results.Add([ordered]@{name=$Name;result='passed'})
}
function Assert-Changed($First,$Second,[string]$Message) {
    Require (@(Diff-Facts $First $Second).Count -gt 0) $Message
}
function Find-Method($Snapshot,[string]$Name) {
    @($Snapshot.declarations | ForEach-Object {$_.methods} | Where-Object name -CEQ $Name)[0]
}

Test-Case 'self equality' {
    $before=Capture-Effective $fixture 'unit-reference'
    $after=Capture-Effective (Copy-Value $fixture) 'unit-copy'
    Require (@(Diff-Facts $before $after).Count -eq 0) 'Identical effective contracts differed.'
    Require ($issues.Count -eq 0) 'Reference fixture has unresolved contracts.'
}
Test-Case 'unique namespace-only schema mapping' {
    $renamed=(ConvertTo-Json -InputObject $fixture -Depth 100).Replace('Windows.Win32.','Pilot.Renamed.') |
        ConvertFrom-Json -AsHashtable -Depth 100
    Require (@(Diff-Facts (Capture-Effective $fixture 'unit-reference') (Capture-Effective $renamed 'unit-renamed')).Count -eq 0) 'Rename-only contracts changed.'
    foreach($definition in $renamed.declarations | Where-Object {$_.name -like '*Attribute'}) {
        $before=Attribute-Schema (Get-Definition $fixture $definition.name) $fixture 'unit-reference'
        $after=Attribute-Schema $definition $renamed 'unit-renamed'
        Require (@(Diff-Facts $before $after).Count -eq 0) "Rename-only attribute schema changed: $($definition.name)"
    }
    Require ($issues.Count -eq 0) 'Rename-only mapping produced unresolved references.'
}
Test-Case 'documentation is excluded, raw fixture is unchanged' {
    $method=Copy-Value (Find-Method $fixture 'GetPwrCapabilities')
    $before=Effective-Method $method $fixture 'unit'
    $method.customAttributes=@($method.customAttributes | Where-Object {$_.constructor.declaringType.name -ne 'DocumentationAttribute'})
    Require (@(Diff-Facts $before (Effective-Method $method $fixture 'unit')).Count -eq 0) 'Documentation removal changed behavior.'
}
Test-Case 'managed attribute AutoClass does not change positional decoding' {
    $definition=Get-Definition $fixture 'MemorySizeAttribute'
    $changed=Copy-Value $definition
    $changed.attributes.value=$changed.attributes.value -bxor 0x20000
    Require (@(Diff-Facts (Attribute-Schema $definition $fixture 'unit') (Attribute-Schema $changed $fixture 'unit')).Count -eq 0) 'Metadata attribute AutoClass affected decoding.'
    Assert-Changed (Effective-Type $definition $fixture 'unit') (Effective-Type $changed $fixture 'unit') 'AutoClass normalization leaked into native type comparison.'
}
Test-Case 'attribute constructor parameter labels are not native API names' {
    $definition=Get-Definition $fixture 'RAIIFreeAttribute'
    $changed=Copy-Value $definition
    $changed.methods[0].parameters[0].name='different-positional-label'
    Require (@(Diff-Facts (Attribute-Schema $definition $fixture 'unit') (Attribute-Schema $changed $fixture 'unit')).Count -eq 0) 'Positional attribute parameter label affected decoding.'
    $method=Find-Method $fixture 'GetPwrCapabilities'
    $changedMethod=Copy-Value $method
    ($changedMethod.parameters | Where-Object sequence -eq 1).name='different-native-name'
    Assert-Changed (Effective-Method $method $fixture 'unit') (Effective-Method $changedMethod $fixture 'unit') 'Native API parameter name was incorrectly erased.'
}
Test-Case 'fixed array zero-default encoding preserves bounds and size contracts' {
    $definition=Get-Definition $fixture 'SYSTEM_POWER_CAPABILITIES'
    $array=($definition.fields | Where-Object name -CEQ 'spare3').type
    $omitted=Copy-Value $array
    $omitted.lowerBounds=@()
    Require (@(Diff-Facts (Convert-Type $array $fixture 'unit' 'spare3') (Convert-Type $omitted $fixture 'unit' 'spare3')).Count -eq 0) 'Omitted zero lower bound changed a fixed array.'
    $changed=Copy-Value $array
    $changed.lowerBounds=@(1)
    Assert-Changed (Convert-Type $array $fixture 'unit' 'spare3') (Convert-Type $changed $fixture 'unit' 'spare3') 'Nonzero native lower bound was erased.'
    $changed=Copy-Value $array
    $changed.sizes[0]++
    Assert-Changed (Convert-Type $array $fixture 'unit' 'spare3') (Convert-Type $changed $fixture 'unit' 'spare3') 'Native array extent was erased.'
}
Test-Case 'current attribute policy rejects invalid targets repetition and inheritance' {
    $old=Get-Definition $fixture 'NativeTypedefAttribute'
    $new=Copy-Value $old
    $new.customAttributes=@()
    Require (Current-UsageCompatible $old $new $fixture 'unit') 'Current sealed native typedef uses should remain valid.'
    $wrongMask=Copy-Value $old
    $wrongMask.customAttributes[0].fixedArguments[0].value=64
    Require (-not (Current-UsageCompatible $wrongMask $new $fixture 'unit')) 'Disallowed native struct placement was accepted.'
    $repeated=Copy-Value $fixture
    $type=Get-Definition $repeated 'BOOLEAN'
    $attribute=@($type.customAttributes | Where-Object {$_.constructor.declaringType.name -eq 'NativeTypedefAttribute'})[0]
    $type.customAttributes+=@($attribute)
    Require (-not (Current-UsageCompatible $old $new $repeated 'unit')) 'Invalid repeated native typedef attribute was accepted.'
    $inheritable=Copy-Value $fixture
    (Get-Definition $inheritable 'BOOLEAN').attributes.value=(Get-Definition $inheritable 'BOOLEAN').attributes.value -band (-bnot 0x100)
    Require (-not (Current-UsageCompatible $old $new $inheritable 'unit')) 'Unproven inheritance behavior was accepted.'
}

foreach($mutation in @('remove-member','change-value','change-flags','change-storage','member-attribute')) {
    Test-Case "enum $mutation is substantive" {
        $definition=Get-Definition $fixture 'REGISTER_NOTIFICATION_FLAGS'
        $changed=Copy-Value $definition
        switch($mutation) {
            'remove-member' {$changed.fields=@($changed.fields | Where-Object name -ne 'DEVICE_NOTIFY_CALLBACK')}
            'change-value' {($changed.fields | Where-Object name -eq 'DEVICE_NOTIFY_CALLBACK').constant.value=77}
            'change-flags' {$changed.customAttributes=@($changed.customAttributes | Where-Object {$_.constructor.declaringType.fullName -ne 'System.FlagsAttribute'})}
            'change-storage' {($changed.fields | Where-Object name -eq 'value__').type.name='Int32'}
            'member-attribute' {
                ($changed.fields | Where-Object name -eq 'DEVICE_NOTIFY_CALLBACK').customAttributes=@(
                    @{constructor=@{declaringType=@{name='ObsoleteAttribute';fullName='System.ObsoleteAttribute'}};fixedArguments=@();namedArguments=@()})
            }
        }
        Assert-Changed (Effective-Type $definition $fixture 'unit') (Effective-Type $changed $fixture 'unit') "Enum mutation was ignored: $mutation"
    }
}
foreach($mutation in @('packing','field-offset','field-type','typedef-identity','ownership')) {
    Test-Case "native schema $mutation is substantive" {
        $definition=Get-Definition $fixture 'HPOWERNOTIFY'
        $changed=Copy-Value $definition
        switch($mutation) {
            'packing' {$changed.layout.packingSize=1}
            'field-offset' {$changed.fields[0].offset=8}
            'field-type' {$changed.fields[0].type=@{kind='primitive';name='UInt32'}}
            'typedef-identity' {$changed.customAttributes=@($changed.customAttributes | Where-Object {$_.constructor.declaringType.name -ne 'NativeTypedefAttribute'})}
            'ownership' {$changed.customAttributes=@($changed.customAttributes | Where-Object {$_.constructor.declaringType.name -ne 'RAIIFreeAttribute'})}
        }
        Assert-Changed (Effective-Type $definition $fixture 'unit') (Effective-Type $changed $fixture 'unit') "Native schema mutation was ignored: $mutation"
    }
}
foreach($mutation in @('constructor-return','constructor-direction','field-type','type-flags','usage')) {
    Test-Case "attribute schema $mutation is substantive" {
        $definition=Get-Definition $fixture 'MemorySizeAttribute'
        $changed=Copy-Value $definition
        switch($mutation) {
            'constructor-return' {$changed.methods[0].signature.returnType.name='UInt32'}
            'constructor-direction' {$changed.methods[0].parameters=@(@{sequence=1;name='injected';attributes=@{value=2};customAttributes=@()})}
            'field-type' {$changed.fields[0].type.name='Int32'}
            'type-flags' {$changed.attributes.value=$changed.attributes.value -bxor 0x100}
            'usage' {$changed.customAttributes=@(@{constructor=@{declaringType=@{name='AttributeUsageAttribute';fullName='System.AttributeUsageAttribute'}};fixedArguments=@(@{type=@{kind='primitive';name='Int32'};value=8});namedArguments=@()})}
        }
        Assert-Changed (Attribute-Schema $definition $fixture 'unit') (Attribute-Schema $changed $fixture 'unit') "Attribute schema mutation was ignored: $mutation"
    }
}
foreach($mutation in @('direction','byte-index','optional','constness','native-typedef')) {
    Test-Case "function $mutation is substantive" {
        $method=Find-Method $fixture 'CallNtPowerInformation'
        $changed=Copy-Value $method
        $input=@($changed.parameters | Where-Object sequence -eq 2)[0]
        switch($mutation) {
            'direction' {$input.attributes.value=$input.attributes.value -bxor 3}
            'byte-index' {($input.customAttributes | Where-Object {$_.constructor.declaringType.name -eq 'MemorySizeAttribute'}).namedArguments[0].value=4}
            'optional' {$input.attributes.value=$input.attributes.value -bxor 16}
            'constness' {$changed.signature.parameterTypes[1]=@{kind='modified';required=$true;modifier=@{fullName='System.Runtime.CompilerServices.IsConst'};elementType=$changed.signature.parameterTypes[1]}}
            'native-typedef' {$changed.signature.returnType=@{kind='primitive';name='Int32'}}
        }
        Assert-Changed (Effective-Method $method $fixture 'unit') (Effective-Method $changed $fixture 'unit') "Function mutation was ignored: $mutation"
    }
}

Test-Case 'association requires a fully resolved matching enum, not just transport' {
    $snapshot=Copy-Value $fixture
    $attributeDefinition=@{
        name='AssociatedEnumAttribute';qualifiedName='Unit.Metadata.AssociatedEnumAttribute'
        baseType=@{kind='type';fullName='System.Attribute'}
    }
    $snapshot.declarations+=@($attributeDefinition)
    $attribute=@{
        constructor=@{declaringType=@{name='AssociatedEnumAttribute';fullName=$attributeDefinition.qualifiedName}}
        fixedArguments=@(@{type=@{kind='primitive';name='String'};value='POWER_PLATFORM_ROLE_VERSION'});namedArguments=@()
    }
    $native=@{kind='primitive';name='UInt32'}
    $definition=Get-Definition $snapshot 'POWER_PLATFORM_ROLE_VERSION'
    $typed=@{kind='type';fullName=$definition.qualifiedName}
    $legacy=Effective-Slot $typed @() $snapshot 'unit' 'Version'
    $associated=Effective-Slot $native @($attribute) $snapshot 'unit' 'Version'
    Require (@(Diff-Facts $legacy $associated).Count -eq 0) 'Valid typed-enum/native-association equivalence failed.'
    Require ($issues.Count -eq 0) 'Valid enum association was not resolved.'
    Assert-Changed $legacy (Effective-Slot $native @() $snapshot 'unit' 'Version') 'Removing association was ignored.'
    $snapshot.declarations=@($snapshot.declarations | Where-Object name -ne 'POWER_PLATFORM_ROLE_VERSION')
    $null=Effective-Slot $native @($attribute) $snapshot 'unit' 'Version'
    Require (@($issues | Where-Object kind -eq 'unresolved-associated-enum').Count -eq 1) 'Dangling enum association was accepted.'
}
Test-Case 'ambiguous enum binding is rejected' {
    $snapshot=Copy-Value $fixture
    $duplicate=Copy-Value (Get-Definition $snapshot 'POWER_PLATFORM_ROLE_VERSION')
    $duplicate.qualifiedName='Ambiguous.POWER_PLATFORM_ROLE_VERSION'
    $snapshot.declarations+=@($duplicate)
    Require ($null -eq (Get-Definition $snapshot 'POWER_PLATFORM_ROLE_VERSION')) 'Ambiguous enum names resolved arbitrarily.'
}

$results.ToArray() | ConvertTo-Json -Depth 10 | Set-Content -Encoding utf8 $OutputPath
Write-Host "$($results.Count) logical-comparator checks passed. Fixtures are in-memory only; no emitted metadata is synthesized."
