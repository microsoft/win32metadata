#requires -Version 7.0
[CmdletBinding()]
param()

$ErrorActionPreference = 'Stop'
. (Join-Path $PSScriptRoot '..\..\scripts\Compare-NativeImprovements.ps1')

<#
Retained UNIT FIXTURE excerpts, not a new SDK capture or downloaded documentation.
The contracts model the actual Powerbase pattern; live proofs must supply their
own independently captured source/doc ledgers. Keeping these excerpts in this
file makes hash/location tampering tests deterministic without creating files.

typedef void *PVOID;
typedef PVOID HPOWERNOTIFY;
typedef PVOID HANDLE;
DWORD WINAPI PowerRegisterSuspendResumeNotification(_In_ DWORD Flags, _In_ HANDLE Recipient, _Out_ PHPOWERNOTIFY RegistrationHandle);
DWORD WINAPI PowerUnregisterSuspendResumeNotification(_Inout_ HPOWERNOTIFY Handle);
DWORD WINAPI PowerDuplicateScheme(_Inout_ GUID **DestinationSchemeGuid);
DWORD WINAPI PowerImportPowerScheme(_Inout_ GUID **DestinationSchemeGuid);
BOOLEAN WINAPI ReadGlobalPwrPolicy(_In_ PGLOBAL_POWER_POLICY pGlobalPowerPolicy);
ReadGlobalPwrPolicy: [out] pGlobalPowerPolicy receives the global power policy.
ReadGlobalPwrPolicy: [in] pGlobalPowerPolicy identifies the global power policy.
ReadGlobalPwrPolicy: [in] pGlobalPowerPolicy; [out] differentParameter.
typedef BOOLEAN (CALLBACK PWRSCHEMESENUMPROC_V2)(_Inout_opt_ LPARAM Context);
typedef BOOLEAN (CALLBACK PWRSCHEMESENUMPROC_V2)(_Inout_opt_ LPARAM Other, _In_opt_ LPARAM Context);
PowerRegisterSuspendResumeNotification returns an HPOWERNOTIFY registration handle in RegistrationHandle. Release it using PowerUnregisterSuspendResumeNotification.
HANDLE is a native handle type.
_Inout_ HPOWERNOTIFY Handle
PowerDuplicateScheme and PowerImportPowerScheme conditionally allocate GUID** output storage, released using LocalFree.
#>

$fixturePath = $PSCommandPath
$fixtureLines = [IO.File]::ReadAllLines($fixturePath)
$fixtureHash = (Get-FileHash -LiteralPath $fixturePath -Algorithm SHA256).Hash
$passed = [Collections.Generic.List[string]]::new()

function Require([bool]$Condition, [string]$Message) {
    if (-not $Condition) { throw $Message }
}
function Copy-Value($Value) {
    ConvertTo-Json -InputObject $Value -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100
}
function Test-Case([string]$Name, [scriptblock]$Action) {
    & $Action
    $passed.Add($Name)
}
function Source([string]$Quote, [switch]$Documentation) {
    $line = [Array]::IndexOf($fixtureLines, $Quote) + 1
    Require ($line -gt 0) "Missing retained unit excerpt: $Quote"
    $result = @{kind=if($Documentation){'documentation'}else{'source'};
        path=$fixturePath;sha256=$fixtureHash;line=$line;endLine=$line;quote=$Quote}
    if ($Documentation) {
        $result.url = 'https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-powerregistersuspendresumenotification'
    }
    return $result
}
function Primitive([string]$Name) { @{kind='primitive';name=$Name} }
function Pointer($Element) { @{kind='pointer';element=$Element} }
function Named([string]$Name) { @{kind='named';name=$Name;signatureTypeKind=17} }
function Raii([string]$Closer) {
    @{name='RAIIFreeAttribute';fixed=@(@{type=(Primitive 'String');value=$Closer});named=@()}
}
function Handle-Definition([string]$Name) {
    @{kind='type';name=$Name;base=@{kind='named';name='System.ValueType';signatureTypeKind=18};
        flags=0x100109;layout=@{isDefault=$true;packingSize=0;size=0};
        fields=@(@{name='Value';flags=6;type=(Pointer (Primitive 'Void'));offset=$null;constant=$null;marshalling=$null;attributes=@()});
        attributes=@(@{name='NativeTypedefAttribute';fixed=@();named=@()})}
}
function Handle-Evidence([string]$Name, [int]$Width) {
    $declaration = Source "typedef PVOID $Name;"
    $designation = if($Name -ceq 'HPOWERNOTIFY'){
        Source 'PowerRegisterSuspendResumeNotification returns an HPOWERNOTIFY registration handle in RegistrationHandle. Release it using PowerUnregisterSuspendResumeNotification.' -Documentation
    }else{ Source 'HANDLE is a native handle type.' -Documentation }
    @{kind='native-handle';identity=$Name;pointerDepth=1;widthBits=$Width;canonical='void *';source=$declaration;
        designation=@{kind='handle-identity';identity=$Name;mechanism='documented-handle';source=$designation};
        aliasChain=@(@{name=$Name;target='PVOID';pointerDepth=0;source=$declaration},
                     @{name='PVOID';target='void';pointerDepth=1;source=(Source 'typedef void *PVOID;')})}
}
function Fixture([string]$Architecture = 'x64') {
    $width = if($Architecture -ceq 'x86'){32}else{64}
    $source = Source 'DWORD WINAPI PowerRegisterSuspendResumeNotification(_In_ DWORD Flags, _In_ HANDLE Recipient, _Out_ PHPOWERNOTIFY RegistrationHandle);'
    $types = @{HPOWERNOTIFY=(Handle-Definition 'HPOWERNOTIFY');HANDLE=(Handle-Definition 'HANDLE');
        REGISTER_NOTIFICATION_FLAGS=@{kind='enum';shape=@{name='REGISTER_NOTIFICATION_FLAGS';storage=(Primitive 'UInt32');
            flags=$true;scoped=$true;members=@(@{name='DEVICE_NOTIFY_CALLBACK';constant=@{type='UInt32';value=2}})} }}
    $method = @{name='PowerRegisterSuspendResumeNotification';signatureHeader=@{rawValue=0};methodFlags=0x2096;
        implementationFlags=0x80;import=@{module='POWRPROF.dll';name='PowerRegisterSuspendResumeNotification';attributes=@{value=0x100;names='CallingConventionWinApi'}};
        parameters=@(
            @{index=0;name='Flags';flags=1;marshalling=$null;constant=$null;contract=@{type=@{kind='enum';contract=$types.REGISTER_NOTIFICATION_FLAGS.shape};attributes=@()}},
            @{index=1;name='Recipient';flags=1;marshalling=$null;constant=$null;contract=@{type=(Named 'HANDLE');attributes=@()}},
            @{index=2;name='RegistrationHandle';flags=2;marshalling=$null;constant=$null;contract=@{type=(Pointer (Pointer (Primitive 'Void')));attributes=@()}}
        );return=@{type=(Primitive 'UInt32');attributes=@()};returnFlags=0;returnMarshalling=$null;attributes=@()}
    $new = Copy-Value $method
    $new.parameters[2].contract.type = Pointer (Named 'HPOWERNOTIFY')
    $new.parameters[2].contract.attributes = @((Raii 'PowerUnregisterSuspendResumeNotification'))
    $oldTypes = Copy-Value $types
    $oldTypes.HPOWERNOTIFY.fields[0].type = Primitive 'IntPtr'
    $oldTypes.HPOWERNOTIFY.attributes += @((Raii 'UnregisterPowerSettingNotification'))
    $evidence = @{kind='native-method';method=$method.name;architecture=$Architecture;pointerWidthBits=$width;
        nativeCallingConvention=if($Architecture -ceq 'x86'){2}else{1};metadataCallingConvention=0x100;source=$source;
        parameters=@(
            @{index=0;name='Flags';identity='DWORD';pointerDepth=0;widthBits=32;direction='In';source=$source},
            @{index=1;name='Recipient';identity='HANDLE';pointerDepth=1;widthBits=$width;direction='In';source=$source},
            @{index=2;name='RegistrationHandle';identity='HPOWERNOTIFY';pointerDepth=2;widthBits=$width;direction='Out';source=$source}
        );handles=@((Handle-Evidence 'HPOWERNOTIFY' $width),(Handle-Evidence 'HANDLE' $width));directions=@();
        lifecycles=@(@{kind='producer-lifecycle';method=$method.name;index=2;identity='HPOWERNOTIFY';
            closer='PowerUnregisterSuspendResumeNotification';producingSlots=@(2);allocation='unconditional-on-success';condition=$null;
            source=(Source 'PowerRegisterSuspendResumeNotification returns an HPOWERNOTIFY registration handle in RegistrationHandle. Release it using PowerUnregisterSuspendResumeNotification.' -Documentation)})}
    @{OldMethod=$method;NewMethod=$new;OldTypes=$oldTypes;NewTypes=$types;ValidationIssues=@();Evidence=$evidence}
}
function Direction-Fixture {
    $fixture = Fixture
    $source = Source 'DWORD WINAPI PowerUnregisterSuspendResumeNotification(_Inout_ HPOWERNOTIFY Handle);'
    foreach ($method in @($fixture.OldMethod, $fixture.NewMethod)) {
        $method.name = 'PowerUnregisterSuspendResumeNotification'
        $method.import.name = $method.name
        $method.parameters = @(@{index=0;name='Handle';flags=1;marshalling=$null;constant=$null;
            contract=@{type=(Named 'HPOWERNOTIFY');attributes=@()}})
    }
    $fixture.NewMethod.parameters[0].flags = 3
    $fixture.Evidence.method = $fixture.NewMethod.name
    $fixture.Evidence.source = $source
    $fixture.Evidence.parameters = @(@{index=0;name='Handle';identity='HPOWERNOTIFY';pointerDepth=1;widthBits=64;direction='InOut';source=$source})
    $fixture.Evidence.lifecycles = @()
    $fixture.Evidence.directions = @(@{kind='sal-direction';method=$fixture.NewMethod.name;index=0;direction='InOut';source=(Source '_Inout_ HPOWERNOTIFY Handle')})
    return $fixture
}
function Documented-Direction-Fixture {
    $fixture = Fixture
    $source = Source 'BOOLEAN WINAPI ReadGlobalPwrPolicy(_In_ PGLOBAL_POWER_POLICY pGlobalPowerPolicy);'
    foreach ($method in @($fixture.OldMethod,$fixture.NewMethod)) {
        $method.name = 'ReadGlobalPwrPolicy'; $method.import.name = $method.name
        $method.return.type = Primitive 'Byte'
        $method.parameters = @(@{index=0;name='pGlobalPowerPolicy';flags=1;marshalling=$null;constant=$null;
            contract=@{type=(Pointer (Named 'GLOBAL_POWER_POLICY'));attributes=@()}})
    }
    $definition = @{kind='type';name='GLOBAL_POWER_POLICY';base=(Named 'System.ValueType');
        flags=0x100109;layout=@{isDefault=$true;packingSize=0;size=0};attributes=@();
        fields=@(@{name='revision';flags=6;type=(Primitive 'UInt32');offset=$null;constant=$null;marshalling=$null;attributes=@()})}
    $fixture.OldTypes.GLOBAL_POWER_POLICY = $definition
    $fixture.NewTypes.GLOBAL_POWER_POLICY = Copy-Value $definition
    $fixture.NewMethod.parameters[0].flags = 2
    $fixture.Evidence.method = 'ReadGlobalPwrPolicy'
    $fixture.Evidence.source = $source
    $fixture.Evidence.parameters = @(@{index=0;name='pGlobalPowerPolicy';identity='GLOBAL_POWER_POLICY';
        pointerDepth=1;widthBits=64;direction='In';source=$source})
    $fixture.Evidence.handles = @(); $fixture.Evidence.lifecycles = @()
    $fixture.Evidence.directions = @(@{kind='documented-direction';method='ReadGlobalPwrPolicy';index=0;
        nativeDirection='In';direction='Out';source=(Source 'ReadGlobalPwrPolicy: [out] pGlobalPowerPolicy receives the global power policy.' -Documentation)})
    $fixture.Evidence.directions[0].source.url = 'https://learn.microsoft.com/en-us/windows/win32/api/powrprof/nf-powrprof-readglobalpwrpolicy'
    return $fixture
}
function Callback-Fixture([string]$Architecture = 'x64', [switch]$Primitive) {
    $fixture = Fixture $Architecture
    $width = $fixture.Evidence.pointerWidthBits
    $source = Source 'typedef BOOLEAN (CALLBACK PWRSCHEMESENUMPROC_V2)(_Inout_opt_ LPARAM Context);'
    $definition = Handle-Definition 'LPARAM'
    $definition.fields[0].type = Primitive 'IntPtr'
    $fixture.OldTypes.LPARAM = $definition
    $fixture.NewTypes.LPARAM = Copy-Value $definition
    foreach ($method in @($fixture.OldMethod,$fixture.NewMethod)) {
        $method.name = 'Invoke'; $method.import = $null; $method.methodFlags = 0x1C6
        $method.signatureHeader = @{rawValue=0x20}
        $method.return.type = Primitive 'Byte'
        $method.parameters = @(@{index=0;name='Context';flags=17;marshalling=$null;constant=$null;
            contract=@{type=if($Primitive){Primitive 'IntPtr'}else{Named 'LPARAM'};attributes=@()}})
    }
    $fixture.NewMethod.parameters[0].flags = 19
    foreach ($pair in @(@{types=$fixture.OldTypes;method=$fixture.OldMethod},@{types=$fixture.NewTypes;method=$fixture.NewMethod})) {
        $pair.types.PWRSCHEMESENUMPROC_V2 = @{kind='type';name='PWRSCHEMESENUMPROC_V2';
            base=@{kind='named';name='System.MulticastDelegate';signatureTypeKind=18};flags=0x101;layout=@{isDefault=$true;packingSize=0;size=0};
            fields=@();methods=@($pair.method);attributes=@(@{name='System.Runtime.InteropServices.UnmanagedFunctionPointerAttribute';
                fixed=@(@{type=(Primitive 'Int32');value=3});named=@()})}
    }
    $fixture.Evidence.kind = 'native-callback'
    $fixture.Evidence.owner = 'PWRSCHEMESENUMPROC_V2'
    $fixture.Evidence.method = 'Invoke'
    $fixture.Evidence.metadataCallingConvention = 0x300
    $fixture.Evidence.source = $source
    $fixture.Evidence.parameters = @(@{index=0;name='Context';identity='LPARAM';pointerDepth=0;widthBits=$width;
        canonical=if($width -eq 32){'long'}else{'long long'};direction='InOut';source=$source})
    $fixture.Evidence.handles = @(); $fixture.Evidence.lifecycles = @()
    $fixture.Evidence.directions = @(@{kind='sal-direction';method='Invoke';index=0;direction='InOut';source=$source})
    return $fixture
}
function Assert-Accepted($Fixture, [string[]]$Rules) {
    $before = ConvertTo-Json -InputObject $Fixture -Compress -Depth 100
    $raw = @(Get-NativeImprovementDifferences $Fixture.OldMethod $Fixture.NewMethod)
    $result = Compare-NativeImprovements @Fixture
    Require ($result.classification -ceq 'expected-improvement') "Expected improvement rejected: $(ConvertTo-Json $result -Compress -Depth 30)"
    Require ($result.remaining.Count -eq 0 -and $result.issues.Count -eq 0) 'Accepted an incomplete explanation.'
    Require ($result.differences.Count -eq $raw.Count -and $raw.Count -gt 0) 'Raw differences disappeared.'
    Require (@(Get-NativeImprovementDifferences @($raw | ForEach-Object path) $result.explainedPaths).Count -eq 0) "Explained paths were not the exact raw paths: expected $(ConvertTo-Json -InputObject @($raw | ForEach-Object path) -Compress), actual $(ConvertTo-Json -InputObject $result.explainedPaths -Compress)."
    foreach ($i in 0..($raw.Count - 1)) {
        $reported = Copy-Value $result.differences[$i]
        $reported.Remove('classification')
        Require (@(Get-NativeImprovementDifferences $raw[$i] $reported).Count -eq 0) 'Raw difference values/presence changed.'
        Require ($result.differences[$i].classification -ceq 'expected-improvement') 'Per-path classification is missing.'
    }
    Require (@(Get-NativeImprovementDifferences @($Rules | Sort-Object) @($result.explanations.rule | Sort-Object)).Count -eq 0) 'Unexpected rules applied.'
    Require ($before -ceq (ConvertTo-Json -InputObject $Fixture -Compress -Depth 100)) 'Classifier modified its inputs.'
}
function Assert-Rejected($Fixture, [string]$Path = '') {
    $raw = @(Get-NativeImprovementDifferences $Fixture.OldMethod $Fixture.NewMethod)
    $result = Compare-NativeImprovements @Fixture
    Require ($result.classification -ceq 'unexplained') "Unintended acceptance: $(ConvertTo-Json $result -Compress -Depth 30)"
    Require ($result.explainedPaths.Count -eq 0 -and $result.explanations.Count -eq 0) 'Invalid context partially accepted.'
    Require ($result.remaining.Count -eq $raw.Count -and $result.differences.Count -eq $raw.Count) 'Unexplained paths were suppressed.'
    if ($Path) { Require ($result.remaining.path -ccontains $Path) "Missing unexplained path: $Path" }
}

Test-Case 'equal contracts need no improvement evidence and are not improvements' {
    $fixture = Fixture
    $fixture.NewMethod = Copy-Value $fixture.OldMethod
    $fixture.Evidence = $null
    $result = Compare-NativeImprovements @fixture
    Require ($result.classification -ceq 'equal' -and $result.differences.Count -eq 0 -and
        $result.explainedPaths.Count -eq 0 -and $result.remaining.Count -eq 0) 'Equality misclassified.'
}
foreach ($architecture in @('x86', 'x64', 'arm64')) {
    Test-Case "Powerbase typed output and exclusive producer closer ($architecture)" {
        Assert-Accepted (Fixture $architecture) @('native-handle-identity','documented-producer-lifecycle')
    }
    Test-Case "actual sequential HPOWERNOTIFY absent FieldLayout shape ($architecture)" {
        $fixture = Fixture $architecture
        $fixture.NewTypes.HPOWERNOTIFY.flags = 265
        $fixture.NewTypes.HPOWERNOTIFY.fields[0].offset = -1
        Assert-Accepted $fixture @('native-handle-identity','documented-producer-lifecycle')
        Require ($fixture.NewTypes.HPOWERNOTIFY.fields[0].offset -eq -1) 'Absent offset was normalized.'
    }
}
foreach ($mutation in @('explicit-offset','other-negative-offset','explicit-layout','auto-layout','nondefault-layout',
    'nonzero-size','nonzero-packing','static-field','extra-field','unsealed')) {
    Test-Case "absent FieldLayout does not excuse $mutation" {
        $fixture = Fixture
        $fixture.NewTypes.HPOWERNOTIFY.flags = 265
        $fixture.NewTypes.HPOWERNOTIFY.fields[0].offset = -1
        switch ($mutation) {
            'explicit-offset' { $fixture.NewTypes.HPOWERNOTIFY.fields[0].offset = 8 }
            'other-negative-offset' { $fixture.NewTypes.HPOWERNOTIFY.fields[0].offset = -2 }
            'explicit-layout' { $fixture.NewTypes.HPOWERNOTIFY.flags = 273 }
            'auto-layout' { $fixture.NewTypes.HPOWERNOTIFY.flags = 257 }
            'nondefault-layout' { $fixture.NewTypes.HPOWERNOTIFY.layout.isDefault = $false }
            'nonzero-size' { $fixture.NewTypes.HPOWERNOTIFY.layout.size = 8 }
            'nonzero-packing' { $fixture.NewTypes.HPOWERNOTIFY.layout.packingSize = 8 }
            'static-field' { $fixture.NewTypes.HPOWERNOTIFY.fields[0].flags = 22 }
            'extra-field' { $fixture.NewTypes.HPOWERNOTIFY.fields += @(Copy-Value $fixture.NewTypes.HPOWERNOTIFY.fields[0]) }
            'unsealed' { $fixture.NewTypes.HPOWERNOTIFY.flags = 9 }
        }
        Assert-Rejected $fixture
    }
}
Test-Case 'native handle typing without lifecycle normalization' {
    $fixture = Fixture
    $fixture.NewMethod.parameters[2].contract.attributes = @()
    $fixture.Evidence.lifecycles = @()
    Assert-Accepted $fixture @('native-handle-identity')
}
Test-Case 'void pointer becomes the exact native HANDLE input' {
    $fixture = Fixture
    $fixture.NewMethod.parameters[2] = Copy-Value $fixture.OldMethod.parameters[2]
    $fixture.OldMethod.parameters[1].contract.type = Pointer (Primitive 'Void')
    $fixture.Evidence.lifecycles = @()
    Assert-Accepted $fixture @('native-handle-identity')
}
Test-Case 'source-backed unregister In to InOut correction' {
    Assert-Accepted (Direction-Fixture) @('native-sal-direction')
}
Test-Case 'source-backed SAL plus native identity compose on exact paths' {
    $fixture = Direction-Fixture
    $fixture.OldMethod.parameters[0].contract.type = Pointer (Primitive 'Void')
    Assert-Accepted $fixture @('native-handle-identity','native-sal-direction')
}
Test-Case 'ReadGlobalPwrPolicy explicit docs override native In without erasing the disagreement' {
    $fixture = Documented-Direction-Fixture
    Assert-Accepted $fixture @('documented-direction-correction')
    $result = Compare-NativeImprovements @fixture
    Require ($result.explanations[0].native.direction -ceq 'In' -and
        $result.explanations[0].evidence.nativeDirection -ceq 'In' -and
        $result.explanations[0].evidence.direction -ceq 'Out') 'Native/documented direction conflict was hidden.'
}
Test-Case 'record availability remains separate from ReadGlobalPwrPolicy direction' {
    $fixture = Documented-Direction-Fixture
    $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes = @(@{name='SupportedOSPlatformAttribute';
        fixed=@(@{type=(Primitive 'String');value='windows5.1.2600'});named=@()})
    $raw = @(Get-NativeImprovementDifferences $fixture.OldTypes.GLOBAL_POWER_POLICY $fixture.NewTypes.GLOBAL_POWER_POLICY)
    Assert-Accepted $fixture @('documented-direction-correction')
    $result = Compare-NativeImprovements @fixture
    Require ($result.explainedPaths.Count -eq 1 -and $result.explainedPaths[0] -ceq '/parameters/0/flags') 'Type availability was accepted as a method improvement.'
    $separate = $result.explanations[0].separatelyReportedTypeDifferences
    Require ($separate.Count -eq 1 -and $separate[0].type -ceq 'GLOBAL_POWER_POLICY' -and
        $separate[0].classification -ceq 'outside-method-scope' -and
        @(Get-NativeImprovementDifferences $raw $separate[0].differences).Count -eq 0) 'Raw type availability difference was lost.'
}
foreach ($mutation in @('layout','field-type','field-offset','field-marshalling','type-ownership','unknown-type-attribute',
    'field-attribute','type-flags','malformed-availability','duplicate-availability','changed-availability','removed-availability')) {
    Test-Case "record availability does not excuse $mutation" {
        $fixture = Documented-Direction-Fixture
        $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes = @(@{name='SupportedOSPlatformAttribute';
            fixed=@(@{type=(Primitive 'String');value='windows5.1.2600'});named=@()})
        switch ($mutation) {
            'layout' { $fixture.NewTypes.GLOBAL_POWER_POLICY.layout.packingSize = 1 }
            'field-type' { $fixture.NewTypes.GLOBAL_POWER_POLICY.fields[0].type = Primitive 'UInt64' }
            'field-offset' { $fixture.NewTypes.GLOBAL_POWER_POLICY.fields[0].offset = 8 }
            'field-marshalling' { $fixture.NewTypes.GLOBAL_POWER_POLICY.fields[0].marshalling = @{descriptor='injected'} }
            'type-ownership' { $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes += @((Raii 'LocalFree')) }
            'unknown-type-attribute' { $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes += @(@{name='OtherAttribute';fixed=@();named=@()}) }
            'field-attribute' { $fixture.NewTypes.GLOBAL_POWER_POLICY.fields[0].attributes = @((Raii 'LocalFree')) }
            'type-flags' { $fixture.NewTypes.GLOBAL_POWER_POLICY.flags = 0 }
            'malformed-availability' { $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes[0].fixed[0].type = Primitive 'Int32' }
            'duplicate-availability' { $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes += @(Copy-Value $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes[0]) }
            'changed-availability' {
                $fixture.OldTypes.GLOBAL_POWER_POLICY.attributes = @(Copy-Value $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes[0])
                $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes[0].fixed[0].value = 'windows6.0.6000'
            }
            'removed-availability' {
                $fixture.OldTypes.GLOBAL_POWER_POLICY.attributes = @(Copy-Value $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes[0])
                $fixture.NewTypes.GLOBAL_POWER_POLICY.attributes = @()
            }
        }
        Assert-Rejected $fixture '/parameters/0/flags'
    }
}
foreach ($architecture in @('x86','x64','arm64')) {
    Test-Case "callback source-backed optional LPARAM InOut correction ($architecture)" {
        Assert-Accepted (Callback-Fixture $architecture) @('native-sal-direction')
    }
    Test-Case "callback unchanged primitive intptr direction correction ($architecture)" {
        Assert-Accepted (Callback-Fixture $architecture -Primitive) @('native-sal-direction')
    }
}
Test-Case 'lifecycle-only improvement requires the same native handle proof' {
    $fixture = Fixture
    $fixture.OldMethod.parameters[2].contract.type = Copy-Value $fixture.NewMethod.parameters[2].contract.type
    Assert-Accepted $fixture @('documented-producer-lifecycle')
}
Test-Case 'type-wide legacy closer and representation differences remain outside scope' {
    $fixture = Fixture
    $raw = @(Get-NativeImprovementDifferences $fixture.OldTypes $fixture.NewTypes)
    Assert-Accepted $fixture @('native-handle-identity','documented-producer-lifecycle')
    Require ($raw.Count -gt 0) 'Fixture lost its actual type-wide disagreement.'
    $result = Compare-NativeImprovements @fixture
    Require ($result.scope -clike '*no type/schema-wide*') 'Overclaimed schema compatibility.'
    Require (@($result.explainedPaths | Where-Object {$_ -cnotlike '/parameters/2/contract/*'}).Count -eq 0) 'Consumed a type-wide difference.'
}

foreach ($mutation in @('identity','indirection','storage-width','native-width','calling-convention',
    'native-calling-convention','closer','missing-evidence','missing-source','missing-location',
    'tampered-hash','tampered-quote','non-authoritative-url','missing-handle-designation',
    'broken-alias-chain','missing-alias-source','sentinel','optional','return-type','byte-count',
    'type-modifier','unrelated-attribute','duplicate-native-slot','nonexclusive-producer',
    'conditional-handle','extra-condition','wrong-direction','replace-existing-closer','type-wide-closer',
    'missing-lifecycle-docs','closer-absent-from-quote','enum-value','enum-association','wrong-method-source',
    'wrong-parameter-source')) {
    Test-Case "reject $mutation" {
        $fixture = Fixture
        switch ($mutation) {
            'identity' { $fixture.NewMethod.parameters[2].contract.type = Pointer (Named 'HANDLE') }
            'indirection' { $fixture.NewMethod.parameters[2].contract.type = Pointer $fixture.NewMethod.parameters[2].contract.type }
            'storage-width' { $fixture.NewTypes.HPOWERNOTIFY.fields[0].type = Primitive 'UInt32' }
            'native-width' { $fixture.Evidence.parameters[2].widthBits = 32 }
            'calling-convention' { $fixture.NewMethod.import.attributes.value = 0x200 }
            'native-calling-convention' { $fixture.Evidence.nativeCallingConvention = 2 }
            'closer' { $fixture.NewMethod.parameters[2].contract.attributes[0].fixed[0].value = 'UnregisterPowerSettingNotification' }
            'missing-evidence' { $fixture.Evidence = $null }
            'missing-source' { $fixture.Evidence.Remove('source') }
            'wrong-method-source' { $fixture.Evidence.source = Source 'typedef PVOID HPOWERNOTIFY;' }
            'wrong-parameter-source' { $fixture.Evidence.parameters[2].source = Source 'typedef PVOID HPOWERNOTIFY;' }
            'missing-location' { $fixture.Evidence.source.Remove('line') }
            'tampered-hash' { $fixture.Evidence.source.sha256 = '0' * 64 }
            'tampered-quote' { $fixture.Evidence.source.quote = 'not the retained declaration' }
            'non-authoritative-url' { $fixture.Evidence.lifecycles[0].source.url = 'https://example.invalid/approved' }
            'missing-handle-designation' { $fixture.Evidence.handles[0].Remove('designation') }
            'broken-alias-chain' { $fixture.Evidence.handles[0].aliasChain[1].name = 'NOT_PVOID' }
            'missing-alias-source' { $fixture.Evidence.handles[0].aliasChain[0].Remove('source') }
            'sentinel' { $fixture.NewMethod.parameters[2].contract.attributes += @(@{name='InvalidHandleValueAttribute';fixed=@(@{value=-1});named=@()}) }
            'optional' { $fixture.NewMethod.parameters[2].flags = 18 }
            'return-type' { $fixture.NewMethod.return.type = Primitive 'Int32' }
            'byte-count' { $fixture.NewMethod.parameters[2].contract.attributes += @(@{name='MemorySizeAttribute';fixed=@();named=@(@{name='BytesParamIndex';value=0})}) }
            'type-modifier' { $fixture.NewMethod.parameters[2].contract.type.element['modifier'] = 'const' }
            'unrelated-attribute' { $fixture.NewMethod.attributes += @(@{name='UnintendedAttribute';fixed=@();named=@()}) }
            'duplicate-native-slot' { $fixture.Evidence.parameters[1] = Copy-Value $fixture.Evidence.parameters[2] }
            'nonexclusive-producer' { $fixture.Evidence.lifecycles[0].producingSlots = @(1,2) }
            'conditional-handle' { $fixture.Evidence.lifecycles[0].allocation = 'conditional' }
            'extra-condition' { $fixture.Evidence.lifecycles[0].condition = 'only if caller storage is null' }
            'wrong-direction' { $fixture.NewMethod.parameters[2].flags = 1 }
            'replace-existing-closer' { $fixture.OldMethod.parameters[2].contract.attributes = @((Raii 'UnregisterPowerSettingNotification')) }
            'type-wide-closer' { $fixture.NewMethod.attributes = @((Raii 'PowerUnregisterSuspendResumeNotification')) }
            'missing-lifecycle-docs' { $fixture.Evidence.lifecycles[0].source = $fixture.Evidence.source }
            'closer-absent-from-quote' { $fixture.Evidence.lifecycles[0].source = Source 'HANDLE is a native handle type.' -Documentation }
            'enum-value' {
                $fixture.NewMethod.parameters[0].contract.type.contract.members[0].constant.value = 99
                $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS.shape.members[0].constant.value = 99
            }
            'enum-association' {
                $fixture.NewMethod.parameters[0].contract.attributes = @(@{name='AssociatedEnumAttribute';fixed=@(@{type=(Primitive 'String');value='HPOWERNOTIFY'});named=@()})
            }
        }
        Assert-Rejected $fixture
    }
}
Test-Case 'missing named handle definition fails' {
    $fixture = Fixture
    $fixture.NewTypes.Remove('HPOWERNOTIFY')
    Assert-Rejected $fixture
}
Test-Case 'missing transitive field definition fails even for equal methods' {
    $fixture = Fixture
    $fixture.NewMethod = Copy-Value $fixture.OldMethod
    $fixture.NewTypes.HANDLE.fields[0].type = Named 'MISSING_NATIVE_TYPE'
    Assert-Rejected $fixture
}
Test-Case 'upstream missing attribute definition prevents acceptance' {
    $fixture = Fixture
    $fixture.ValidationIssues = @(@{stage='candidate';use='RegistrationHandle';kind='unresolved-attribute-definition';target='RAIIFreeAttribute'})
    Assert-Rejected $fixture
}
Test-Case 'missing consumed enum definition fails even when methods are equal' {
    $fixture = Fixture
    $fixture.NewMethod = Copy-Value $fixture.OldMethod
    $fixture.NewTypes.Remove('REGISTER_NOTIFICATION_FLAGS')
    Assert-Rejected $fixture
}
Test-Case 'actual named enum member self-reference resolves through enum shape' {
    $fixture = Fixture
    foreach ($shape in @($fixture.OldTypes.REGISTER_NOTIFICATION_FLAGS.shape,
                         $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS.shape,
                         $fixture.OldMethod.parameters[0].contract.type.contract,
                         $fixture.NewMethod.parameters[0].contract.type.contract)) {
        $shape.members[0].type = Named 'REGISTER_NOTIFICATION_FLAGS'
    }
    Assert-Accepted $fixture @('native-handle-identity','documented-producer-lifecycle')
    $fixture.NewMethod = Copy-Value $fixture.OldMethod
    $result = Compare-NativeImprovements @fixture
    Require ($result.classification -ceq 'equal' -and $result.issues.Count -eq 0) 'Genuine enum-member reference was reported missing.'
}
foreach ($mutation in @('missing-definition','mismatched-shape-name','wrong-definition-kind','missing-member-target')) {
    Test-Case "named enum member rejects $mutation" {
        $fixture = Fixture
        foreach ($shape in @($fixture.OldTypes.REGISTER_NOTIFICATION_FLAGS.shape,
                             $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS.shape,
                             $fixture.OldMethod.parameters[0].contract.type.contract,
                             $fixture.NewMethod.parameters[0].contract.type.contract)) {
            $shape.members[0].type = Named 'REGISTER_NOTIFICATION_FLAGS'
        }
        switch ($mutation) {
            'missing-definition' { $fixture.NewTypes.Remove('REGISTER_NOTIFICATION_FLAGS') }
            'mismatched-shape-name' { $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS.shape.name = 'DIFFERENT_ENUM' }
            'wrong-definition-kind' { $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS = @{kind='type';name='REGISTER_NOTIFICATION_FLAGS'} }
            'missing-member-target' {
                $fixture.NewTypes.REGISTER_NOTIFICATION_FLAGS.shape.members[0].type = Named 'MISSING_ENUM'
                $fixture.NewMethod.parameters[0].contract.type.contract.members[0].type = Named 'MISSING_ENUM'
            }
        }
        Assert-Rejected $fixture
    }
}
Test-Case 'missing association target definition cannot be erased' {
    $fixture = Fixture
    $fixture.NewMethod.parameters[0].contract.type = Primitive 'UInt32'
    $fixture.NewMethod.parameters[0].contract.attributes = @(@{name='AssociatedEnumAttribute';
        fixed=@(@{type=(Primitive 'String');value='MISSING_ENUM'});named=@()})
    $result = Compare-NativeImprovements @fixture
    Require ($result.issues.reason -ccontains 'missing-association-target-definition') 'Missing association target was not diagnosed.'
    Assert-Rejected $fixture '/parameters/0/contract/attributes/0'
}
foreach ($mutation in @('missing-direction-evidence','wrong-direction-evidence','optionality-with-direction','unrelated-mutation-with-direction','wrong-sal-quote')) {
    Test-Case "SAL rejects $mutation" {
        $fixture = Direction-Fixture
        switch ($mutation) {
            'missing-direction-evidence' { $fixture.Evidence.directions = @() }
            'wrong-direction-evidence' { $fixture.Evidence.directions[0].direction = 'Out' }
            'optionality-with-direction' { $fixture.NewMethod.parameters[0].flags = 19 }
            'unrelated-mutation-with-direction' { $fixture.NewMethod.returnFlags = 2 }
            'wrong-sal-quote' { $fixture.Evidence.directions[0].source = Source 'typedef PVOID HPOWERNOTIFY;' }
        }
        Assert-Rejected $fixture '/parameters/0/flags'
    }
}
foreach ($mutation in @('implicit-doc-override','missing-native-direction','false-native-direction','wrong-doc-marker',
    'source-instead-of-doc','wrong-record-identity','wrong-native-depth','wrong-native-width','changed-definition','changed-other-contract','different-doc-parameter')) {
    Test-Case "documentation correction rejects $mutation" {
        $fixture = Documented-Direction-Fixture
        switch ($mutation) {
            'implicit-doc-override' { $fixture.Evidence.directions[0].kind = 'sal-direction' }
            'missing-native-direction' { $fixture.Evidence.directions[0].Remove('nativeDirection') }
            'false-native-direction' { $fixture.Evidence.directions[0].nativeDirection = 'InOut' }
            'wrong-doc-marker' { $fixture.Evidence.directions[0].source = Source 'ReadGlobalPwrPolicy: [in] pGlobalPowerPolicy identifies the global power policy.' -Documentation }
            'different-doc-parameter' { $fixture.Evidence.directions[0].source = Source 'ReadGlobalPwrPolicy: [in] pGlobalPowerPolicy; [out] differentParameter.' -Documentation }
            'source-instead-of-doc' { $fixture.Evidence.directions[0].source = $fixture.Evidence.source }
            'wrong-record-identity' { $fixture.Evidence.parameters[0].identity = 'POWER_POLICY' }
            'wrong-native-depth' { $fixture.Evidence.parameters[0].pointerDepth = 2 }
            'wrong-native-width' { $fixture.Evidence.parameters[0].widthBits = 32 }
            'changed-definition' { $fixture.NewTypes.GLOBAL_POWER_POLICY.fields[0].type = Primitive 'UInt64' }
            'changed-other-contract' { $fixture.NewMethod.parameters[0].contract.attributes = @((Raii 'LocalFree')) }
        }
        Assert-Rejected $fixture '/parameters/0/flags'
    }
}
foreach ($mutation in @('wrong-owner','missing-owner','missing-invoke-membership','different-invoke','wrong-convention',
    'missing-convention','wrong-native-convention','changed-owner-context','changed-other-method',
    'missing-native-canonical','wrong-native-signedness','wrong-scalar-width','wrong-native-pointer-depth',
    'optional-flag-change','intptr-to-named-alias','different-sal-parameter')) {
    Test-Case "callback correction rejects $mutation" {
        $fixture = Callback-Fixture
        switch ($mutation) {
            'wrong-owner' { $fixture.Evidence.owner = 'PWRSCHEMESENUMPROC_V1' }
            'missing-owner' { $fixture.NewTypes.Remove('PWRSCHEMESENUMPROC_V2') }
            'missing-invoke-membership' { $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.methods = @() }
            'different-invoke' {
                $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.methods = @(Copy-Value $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.methods)
                $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.methods[0].parameters[0].name = 'Other'
            }
            'wrong-convention' { $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.attributes[0].fixed[0].value = 2 }
            'missing-convention' { $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.attributes = @() }
            'wrong-native-convention' { $fixture.Evidence.nativeCallingConvention = 2 }
            'changed-owner-context' { $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.flags = 1 }
            'changed-other-method' { $fixture.NewTypes.PWRSCHEMESENUMPROC_V2.methods += @(@{name='.ctor';parameters=@()}) }
            'missing-native-canonical' { $fixture.Evidence.parameters[0].Remove('canonical') }
            'wrong-native-signedness' { $fixture.Evidence.parameters[0].canonical = 'unsigned long long' }
            'wrong-scalar-width' { $fixture.NewTypes.LPARAM.fields[0].type = Primitive 'UInt32' }
            'wrong-native-pointer-depth' { $fixture.Evidence.parameters[0].pointerDepth = 1 }
            'optional-flag-change' { $fixture.NewMethod.parameters[0].flags = 3 }
            'intptr-to-named-alias' { $fixture.OldMethod.parameters[0].contract.type = Primitive 'IntPtr' }
            'different-sal-parameter' {
                $fixture.Evidence.directions[0].source = Source 'typedef BOOLEAN (CALLBACK PWRSCHEMESENUMPROC_V2)(_Inout_opt_ LPARAM Other, _In_opt_ LPARAM Context);'
            }
        }
        Assert-Rejected $fixture '/parameters/0/flags'
    }
}
foreach ($methodName in @('PowerDuplicateScheme','PowerImportPowerScheme')) {
    foreach ($allocation in @('conditional','unconditional-on-success')) {
        Test-Case "$methodName GUID double-pointer is not an unconditional handle ($allocation)" {
            $fixture = Fixture
            foreach ($method in @($fixture.OldMethod,$fixture.NewMethod)) {
                $method.name = $methodName; $method.import.name = $methodName
                $method.parameters = @(@{index=0;name='DestinationSchemeGuid';flags=3;marshalling=$null;constant=$null;
                    contract=@{type=(Pointer (Pointer (Named 'GUID')));attributes=@()}})
            }
            $fixture.NewMethod.parameters[0].contract.attributes = @((Raii 'LocalFree'))
            $fixture.OldTypes.GUID = @{kind='type';name='GUID';fields=@(@{name='Data1';type=(Primitive 'UInt32')})}
            $fixture.NewTypes.GUID = Copy-Value $fixture.OldTypes.GUID
            $fixture.Evidence.method = $methodName
            $fixture.Evidence.source = Source "DWORD WINAPI $methodName(_Inout_ GUID **DestinationSchemeGuid);"
            $fixture.Evidence.parameters = @(@{index=0;name='DestinationSchemeGuid';identity='GUID';pointerDepth=2;widthBits=64;direction='InOut';source=$fixture.Evidence.source})
            $fixture.Evidence.lifecycles = @(@{kind='producer-lifecycle';method=$methodName;index=0;identity='GUID';closer='LocalFree';
                producingSlots=@(0);allocation=$allocation;condition=$null;
                source=(Source 'PowerDuplicateScheme and PowerImportPowerScheme conditionally allocate GUID** output storage, released using LocalFree.' -Documentation)})
            Assert-Rejected $fixture '/parameters/0/contract/attributes/0'
        }
    }
}
Test-Case 'extra unrelated field remains an exact escaped raw difference' {
    $fixture = Fixture
    $fixture.NewMethod['unrelated/key~'] = @{value=17}
    Assert-Rejected $fixture '/unrelated~1key~0'
}
Test-Case 'bare approval text cannot serve as a typed evidence ledger' {
    $fixture = Fixture
    $fixture.Evidence = @{approval='expected improvement'}
    Assert-Rejected $fixture
}

Write-Host "$($passed.Count) native-improvement checks passed. All fixtures are local/in-memory; no metadata, caches, or existing proof artifacts were changed."
