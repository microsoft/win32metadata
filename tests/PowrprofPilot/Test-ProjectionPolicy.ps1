[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
. (Join-Path $root 'scripts\Compare-PowrprofEvidence.ps1') -EvidenceDirectory $EvidenceDirectory -DefinitionsOnly
. (Join-Path $root 'scripts\Compare-ProjectionPolicy.ps1')
$candidate=Read-Contract 'candidate-x64'
$contexts=Get-Content (Join-Path $EvidenceDirectory 'policy\native-contexts.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$results=[Collections.Generic.List[object]]::new()
function Clone($Value){ConvertTo-Json -InputObject $Value -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100}
function Copy-Snapshot($Snapshot){
    $copy=@{};foreach($key in $Snapshot.Keys){$copy[$key]=$Snapshot[$key]}
    $copy.declarations=@($Snapshot.declarations | ForEach-Object {
        if($_.name -cin @('GUID','PWSTR','PCWSTR','REGSAM','ACCESS_MASK')){Clone $_}else{$_}
    })
    return $copy
}
function Change-Native($Case,[scriptblock]$Edit){
    $capture=Read-ProjectionNative $Case.evidence
    & $Edit $capture
    $path=Join-Path $EvidenceDirectory "policy\$($Case.name)-native.json"
    Save-Json $capture $path
    $Case.evidence.capture=@{path=$path;sha256=(Get-FileHash $path).Hash;origin='deliberately mutated test capture, not actual compiler evidence'}
}
function Check([string]$Name,[string]$Method,[scriptblock]$Edit,[string]$Expected='review-required',[int]$Uses=-1){
    $rawOld=Clone (Find-Method $reference $Method);$rawNew=Clone (Find-Method $candidate $Method)
    $before=Effective-Method $rawOld $reference "old-$Name";$after=Effective-Method $rawNew $candidate "new-$Name"
    $source=@($inventory.directDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq $Method})[0]
    $null=@(Normalize-ConstEncoding $before $after $source)
    $case=@{name=$Name;before=$before;after=$after;rawOld=$rawOld;rawNew=$rawNew;
        oldSnapshot=(Copy-Snapshot $reference);newSnapshot=(Copy-Snapshot $candidate);evidence=(Clone $contexts.x64);issues=@()}
    & $Edit $case
    $fingerprint=ConvertTo-Json -InputObject @($case.before,$case.after,$case.rawOld,$case.rawNew) -Compress -Depth 100
    $result=Compare-ProjectionPolicy -Before $case.before -After $case.after -OldMethod $case.rawOld -NewMethod $case.rawNew `
        -OldSnapshot $case.oldSnapshot -NewSnapshot $case.newSnapshot -Evidence $case.evidence -ValidationIssues $case.issues
    if($result.classification -cne $Expected -or ($Uses -ge 0 -and $result.explanations.Count -ne $Uses)){
        throw "$Name expected $Expected/$Uses uses; got $($result.classification)/$($result.explanations.Count): $(ConvertTo-Json $result.rejected -Compress -Depth 8)"}
    if((ConvertTo-Json -InputObject @($case.before,$case.after,$case.rawOld,$case.rawNew) -Compress -Depth 100) -cne $fingerprint){
        throw "Policy modified input contracts: $Name"}
    if($Expected -ceq 'review-required' -and -not $result.remaining.Count -and -not $result.rejected.Count){throw 'Negative result has no retained failure.'}
    $results.Add(@{name=$Name;result='passed';classification=$result.classification;uses=$result.explanations.Count;
        remaining=$result.remaining;rejections=$result.rejected})
}
Check 'actual-guid-pointers' 'PowerReadFriendlyName' {} 'projection-equivalent' 3
Check 'actual-guid-double-pointer' 'PowerDuplicateScheme' {} 'projection-equivalent' 2
Check 'actual-const-strings' 'WritePwrScheme' {} 'projection-equivalent' 2
Check 'actual-guid-and-const-string' 'PowerImportPowerScheme' {} 'projection-equivalent' 2
Check 'actual-regsam-user' 'PowerOpenUserPowerKey' {} 'expected-improvement' 1
Check 'actual-regsam-system' 'PowerOpenSystemPowerKey' {} 'expected-improvement' 1
foreach($mutation in @('missing-definition','wrong-record-name','wrong-managed-assembly','wrong-guid-field-width','wrong-field-offset',
    'wrong-field-flags','wrong-array-extent','extra-field','wrong-layout','type-ownership','pointer-depth','raw-pointer-depth','array-shape',
    'native-width','native-layout','native-alignment','native-const','missing-evidence','changed-source','wrong-calling-convention','missing-association','missing-other-reference')){
    Check "guid-$mutation" 'PowerReadFriendlyName' {
        param($c)
        $d=Get-Definition $c.newSnapshot 'GUID'
        switch($mutation){
            'missing-definition' {$c.newSnapshot.declarations=@($c.newSnapshot.declarations | Where-Object name -CNE 'GUID')}
            'wrong-record-name' {$d.name='OTHER_GUID'}
            'wrong-managed-assembly' {$c.rawOld.signature.parameterTypes[1].elementType.scope.identity.name='NotTheRuntime'}
            'wrong-guid-field-width' {$d.fields[0].type.name='UInt64'}
            'wrong-field-offset' {$d.fields[1].offset=5}
            'wrong-field-flags' {$d.fields[1].attributes.value=22}
            'wrong-array-extent' {$d.fields[3].type.sizes=@(16)}
            'extra-field' {$d.fields+=@(Clone $d.fields[0])}
            'wrong-layout' {$d.layout.packingSize=1}
            'type-ownership' {$d.customAttributes+=@(@{constructor=@{declaringType=@{fullName='Windows.Win32.Foundation.Metadata.RAIIFreeAttribute'}};fixedArguments=@(@{value='LocalFree'})})}
            'pointer-depth' {$c.after.parameters[1].contract.type=@{kind='pointer';element=$c.after.parameters[1].contract.type}}
            'raw-pointer-depth' {$c.rawNew.signature.parameterTypes[1]=@{kind='pointer';elementType=$c.rawNew.signature.parameterTypes[1]}}
            'array-shape' {$c.after.parameters[1].contract.type=@{kind='array';rank=1;sizes=@(2);lowerBounds=@(0);elementType=$c.after.parameters[1].contract.type}}
            'native-width' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'PowerReadFriendlyName' 'FunctionDecl').parameters[1].type.size=4}}
            'native-layout' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n '_GUID' 'StructDecl').fields[1].offsetBits=40}}
            'native-alignment' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n '_GUID' 'StructDecl').fields[1].type.alignment=4}}
            'native-const' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'PowerReadFriendlyName' 'FunctionDecl').parameters[1].type.canonical='_GUID *'}}
            'missing-evidence' {$c.evidence=$null}
            'changed-source' {$c.evidence.sources[0].sha256='0'*64}
            'wrong-calling-convention' {$c.after.import.attributes.value=$c.after.import.attributes.value -bxor 0x300}
            'missing-association' {$c.newSnapshot.declarations=@($c.newSnapshot.declarations | Where-Object name -CNE 'WIN32_ERROR')}
            'missing-other-reference' {$c.newSnapshot.declarations=@($c.newSnapshot.declarations | Where-Object name -CNE 'HKEY')}
        }
    }
}
foreach($mutation in @('missing-const','const-with-argument','extra-indirection','wrong-utf16-width','const-at-wrong-level','optional-const-modifier',
    'mutable-native','wrong-native-width','wrapper-extra-field','wrapper-closer','wrong-wrapper-name','changed-unrelated-attribute',
    'extra-type-contract','extra-slot-contract','extra-const-contract','native-alignment','wrong-native-alias')){
    Check "string-$mutation" 'WritePwrScheme' {
        param($c)
        $d=Get-Definition $c.newSnapshot 'PCWSTR'
        switch($mutation){
            'missing-const' {$c.before.parameters[1].contract.attributes=@()}
            'const-with-argument' {$c.before.parameters[1].contract.attributes[0].fixed=@(@{value=1})}
            'extra-indirection' {$c.after.parameters[1].contract.type=@{kind='pointer';element=$c.after.parameters[1].contract.type}}
            'wrong-utf16-width' {$d.fields[0].type.elementType.elementType.name='Byte'}
            'const-at-wrong-level' {$t=$d.fields[0].type;$pointer=$t.elementType;$t.elementType=$pointer.elementType;$pointer.elementType=$t;$d.fields[0].type=$pointer}
            'optional-const-modifier' {$d.fields[0].type.required=$false}
            'mutable-native' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'WritePwrScheme' 'FunctionDecl').parameters[1].type.canonical='wchar_t *'}}
            'wrong-native-width' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'WCHAR' 'TypedefDecl').underlyingType.size=4}}
            'wrapper-extra-field' {$d.fields+=@(Clone $d.fields[0])}
            'wrapper-closer' {$d.customAttributes+=@(@{constructor=@{declaringType=@{fullName='Windows.Win32.Foundation.Metadata.RAIIFreeAttribute'}};fixedArguments=@(@{value='LocalFree'})})}
            'wrong-wrapper-name' {$c.after.parameters[1].contract.type.name='OtherWideString'}
            'changed-unrelated-attribute' {$c.after.parameters[1].contract.attributes+=@(@{name='NativeArrayInfoAttribute';fixed=@();named=@(@{name='CountParamIndex';value=0})})}
            'extra-type-contract' {$c.after.parameters[1].contract.type['unrelated']='must remain'}
            'extra-slot-contract' {$c.after.parameters[1].contract['unrelated']='must remain'}
            'extra-const-contract' {$c.before.parameters[1].contract.attributes[0]['unrelated']='must remain'}
            'native-alignment' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'WCHAR' 'TypedefDecl').underlyingType.alignment=4}}
            'wrong-native-alias' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'WritePwrScheme' 'FunctionDecl').parameters[1].type.spelling='UnprovenStringAlias'}}
        }
    }
}
foreach($mutation in @('missing-regsam','missing-access','cycle','signed-storage','wide-storage','native-signedness','native-width',
    'wrong-alias-source','no-marker','extra-field','nonzero-offset','ownership','pointer-instead','wrong-alias-identity','native-alignment','extra-type-contract')){
    Check "regsam-$mutation" 'PowerOpenUserPowerKey' {
        param($c)
        $d=Get-Definition $c.newSnapshot 'REGSAM';$a=Get-Definition $c.newSnapshot 'ACCESS_MASK'
        switch($mutation){
            'missing-regsam' {$c.newSnapshot.declarations=@($c.newSnapshot.declarations | Where-Object name -CNE 'REGSAM')}
            'missing-access' {$c.newSnapshot.declarations=@($c.newSnapshot.declarations | Where-Object name -CNE 'ACCESS_MASK')}
            'cycle' {$a.fields[0].type=Clone $d.fields[0].type}
            'signed-storage' {$a.fields[0].type.name='Int32'}
            'wide-storage' {$a.fields[0].type.name='UInt64'}
            'native-signedness' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'REGSAM' 'TypedefDecl').underlyingType.canonical='long'}}
            'native-width' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'PowerOpenUserPowerKey' 'FunctionDecl').parameters[1].type.size=8}}
            'wrong-alias-source' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'REGSAM' 'TypedefDecl').underlyingType.spelling='SOMETHING_ELSE'}}
            'no-marker' {$d.customAttributes=@()}
            'extra-field' {$d.fields+=@(Clone $d.fields[0])}
            'nonzero-offset' {$d.fields[0].offset=4}
            'ownership' {$d.fields[0].customAttributes=@(@{constructor=@{declaringType=@{fullName='Windows.Win32.Foundation.Metadata.RAIIFreeAttribute'}}})}
            'pointer-instead' {$c.after.parameters[1].contract.type=@{kind='pointer';element=$c.after.parameters[1].contract.type}}
            'wrong-alias-identity' {$c.after.parameters[1].contract.type.name='ANOTHER_ACCESS_MASK'}
            'native-alignment' {Change-Native $c {param($n) (Get-ProjectionNativeDeclaration $n 'ACCESS_MASK' 'TypedefDecl').underlyingType.alignment=8}}
            'extra-type-contract' {$c.after.parameters[1].contract.type['unrelated']='must remain'}
        }
    }
}
foreach($mutation in @('optional','direction','count','ownership','closer','return','import','os','parameter-name','validation-issue','enum-value')){
    Check "unrelated-$mutation" 'PowerReadFriendlyName' {
        param($c)
        switch($mutation){
            'optional' {$c.after.parameters[1].flags=$c.after.parameters[1].flags -bxor 16}
            'direction' {$c.after.parameters[1].flags=$c.after.parameters[1].flags -bxor 2}
            'count' {$c.after.parameters[4].contract.attributes+=@(@{name='NativeArrayInfoAttribute';fixed=@();named=@(@{name='CountParamIndex';value=1})})}
            'ownership' {$c.after.parameters[1].contract.attributes+=@(@{name='RAIIFreeAttribute';fixed=@(@{value='LocalFree'});named=@()})}
            'closer' {$c.after.parameters[1].contract.attributes+=@(@{name='RAIIFreeAttribute';fixed=@(@{value='WrongFree'});named=@()})}
            'return' {$c.after.returnFlags=1}
            'import' {$c.after.import.moduleName='wrong.dll'}
            'os' {$c.after.attributes+=@(@{name='SupportedOSPlatformAttribute';fixed=@(@{value='windows99.0'});named=@()})}
            'parameter-name' {$c.after.parameters[1].name='Unrelated'}
            'validation-issue' {$c.issues=@(@{kind='unresolved-associated-enum';target='Missing'})}
            'enum-value' {$c.after.return.type.contract.members.sha256='changed literal values'}
        }
    }
}
Save-Json $results.ToArray() (Join-Path $EvidenceDirectory 'policy\regression-checks.json')
Write-Host "$($results.Count) projection-policy boundary checks passed; real positive uses and deliberate negative mutations are distinguished."
