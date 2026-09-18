[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)
$ErrorActionPreference='Stop'
$repo=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
. (Join-Path $repo 'scripts\Compare-ComProjectionPolicy.ps1')
$reference=Get-Content (Join-Path $EvidenceDirectory 'contracts\reference.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$candidate=Get-Content (Join-Path $EvidenceDirectory 'contracts\candidate-x64.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$contexts=Get-Content (Join-Path $EvidenceDirectory 'native\contexts.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$owner='Windows.Win32.Media.MediaFoundation.IMFASFMutualExclusion'
$results=[Collections.Generic.List[object]]::new()
function Clone($Value){ConvertTo-Json -InputObject $Value -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100}
function Copy-Snapshot($Snapshot){
    $copy=@{};foreach($key in $Snapshot.Keys){$copy[$key]=$Snapshot[$key]}
    $copy.declarations=@($Snapshot.declarations | ForEach-Object {
        if($_.name -cin @('GUID','IMFASFMutualExclusion','IUnknown')){Clone $_}else{$_}
    })
    return $copy
}
function Mutate-Capture($Case,[string]$Kind,[scriptblock]$Edit){
    $identity=$Case.evidence[$Kind]
    $capture=Get-Content $identity.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    & $Edit $capture
    $path=Join-Path $EvidenceDirectory "tests\$($Case.name)-$Kind.json"
    Save-Json $capture $path
    $Case.evidence[$Kind]=@{path=$path;sha256=(Get-FileHash $path).Hash;origin='deliberately mutated native fixture, not a new compiler observation'}
}
function Attribute([string]$Name,$Fixed=@(),$Named=@()){
    @{constructor=@{declaringType=@{kind='type';name=$Name;fullName="Windows.Win32.Foundation.Metadata.$Name"}};
        fixedArguments=$Fixed;namedArguments=$Named}
}
function Check-Case([string]$Name,[scriptblock]$Edit,[int]$Explanations=0,[string]$RequiredRemaining=''){
    $c=@{name=$Name;old=(Copy-Snapshot $reference);new=(Copy-Snapshot $candidate);
        evidence=(Clone $contexts.x64);owner=$owner;method='GetType'}
    & $Edit $c
    $fingerprint=ConvertTo-Json -InputObject @($c.old,$c.new) -Depth 100 -Compress
    $r=Compare-ComProjectionPolicy -OldSnapshot $c.old -NewSnapshot $c.new -InterfaceName $c.owner -MethodName $c.method -Evidence $c.evidence
    if($r.explanations.Count -ne $Explanations -or $r.classification -cne 'review-required'){
        throw "$Name expected $Explanations explanations and retained review; got $($r.explanations.Count): $(ConvertTo-Json $r.rejections -Compress -Depth 8)"}
    if($Explanations -eq 0 -and -not $r.rejections.Count -and -not $r.bindingIssues.Count){throw "No concrete rejection for $Name"}
    if($RequiredRemaining -and -not @($r.remaining | Where-Object path -CLike $RequiredRemaining).Count){
        throw "Unrelated difference disappeared: $Name/$RequiredRemaining"}
    if((ConvertTo-Json -InputObject @($c.old,$c.new) -Depth 100 -Compress) -cne $fingerprint){throw 'Adapter changed snapshot inputs.'}
    $results.Add(@{name=$Name;result='passed';explanations=$r.explanations.Count;remaining=$r.remaining;rejections=$r.rejections;
        contextDifferences=$r.contextDifferences.Count;bindingIssues=$r.bindingIssues})
}
Check-Case 'actual-SDK-COM-GetType' {} 1 '/return/type/name'
Check-Case 'actual-reference-SetType-unsupported' {param($c) $c.method='SetType'}
Check-Case 'actual-inherited-GetStreamType-unsupported' {param($c) $c.owner='Windows.Win32.Media.MediaFoundation.IMFASFStreamConfig';$c.method='GetStreamType'}
foreach($mutation in @('wrong-guid-type','wrong-guid-layout','wrong-guid-member','wrong-guid-array','wrong-guid-field-flags','wrong-guid-source','wrong-guid-assembly','missing-guid',
    'missing-interface','duplicate-interface','missing-method','duplicate-method','reordered-member','changed-iid','changed-base',
    'duplicate-base','missing-base','base-iid','base-slots','interface-flags','missing-iid-attribute-definition','wrong-iid-provider',
    'wrong-iid-constructor','wrong-vtable-slot','wrong-vtable-order','wrong-this','wrong-cpp-convention','wrong-vtable-convention',
    'nonvirtual','nonpure','static','variadic','cpp-depth','vtable-depth','native-return','native-base','cpp-parameter-name',
    'metadata-depth','metadata-array','metadata-const','metadata-count','optional','direction','wrong-metadata-calling-convention','metadata-static',
    'missing-associated-enum','native-reference','missing-capture','changed-source','wrong-native-architecture')){
    Check-Case $mutation {
        param($c)
        $type=Get-ComIdentity $c.new $owner;$m=Get-ComMember $type 'GetType';$guid=Get-Definition $c.new 'GUID'
        switch($mutation){
            'wrong-guid-type' {
                $guid.name='OTHER16';$guid.qualifiedName="$($guid.namespace).OTHER16"
                $m.signature.parameterTypes[0].elementType.name='OTHER16';$m.signature.parameterTypes[0].elementType.fullName=$guid.qualifiedName
            }
            'wrong-guid-layout' {$guid.layout.packingSize=1}
            'wrong-guid-member' {$guid.fields[1].offset=8}
            'wrong-guid-array' {$guid.fields[3].type.sizes=@(16)}
            'wrong-guid-field-flags' {$guid.fields[1].attributes.value=22}
            'wrong-guid-source' {Mutate-Capture $c 'capture' {param($n) (Get-ProjectionNativeDeclaration $n 'GUID' 'TypedefDecl').source.file='C:\not-the-SDK\guiddef.h'}}
            'wrong-guid-assembly' {(Get-ComMember (Get-ComIdentity $c.old $owner) 'GetType').signature.parameterTypes[0].elementType.scope.identity.name='NotTheRuntime'}
            'missing-guid' {$c.new.declarations=@($c.new.declarations | Where-Object name -CNE 'GUID')}
            'missing-interface' {$c.new.declarations=@($c.new.declarations | Where-Object qualifiedName -CNE $owner)}
            'duplicate-interface' {$c.new.declarations+=@(Clone $type)}
            'missing-method' {$type.methods=@($type.methods | Where-Object name -CNE 'GetType')}
            'duplicate-method' {$type.methods+=@(Clone $m)}
            'reordered-member' {$first=$type.methods[0];$type.methods[0]=$type.methods[1];$type.methods[1]=$first}
            'changed-iid' {$type.customAttributes[0].fixedArguments[0].value++}
            'changed-base' {$type.interfaces[0].type.name='NotIUnknown'}
            'duplicate-base' {$type.interfaces+=@(Clone $type.interfaces[0])}
            'missing-base' {$c.new.declarations=@($c.new.declarations | Where-Object name -CNE 'IUnknown')}
            'base-iid' {(Get-Definition $c.new 'IUnknown').customAttributes[0].fixedArguments[0].value++}
            'base-slots' {(Get-Definition $c.new 'IUnknown').methods[0].signature.requiredParameterCount=0}
            'interface-flags' {$type.attributes.value=265}
            'missing-iid-attribute-definition' {$c.old.declarations=@($c.old.declarations | Where-Object qualifiedName -CNE 'Windows.Win32.Foundation.Metadata.GuidAttribute')}
            'wrong-iid-provider' {$type.customAttributes[0].constructor.declaringType.scope.identity.name='OtherWindows'}
            'wrong-iid-constructor' {$type.customAttributes[0].constructor.signature.parameterTypes[0].name='UInt64'}
            'wrong-vtable-slot' {Mutate-Capture $c 'comVtable' {param($n) (Get-ComNative $n 'IMFASFMutualExclusionVtbl').fields[3].offsetBits=0}}
            'wrong-vtable-order' {Mutate-Capture $c 'comVtable' {param($n) $d=Get-ComNative $n 'IMFASFMutualExclusionVtbl';$f=$d.fields[3];$d.fields[3]=$d.fields[4];$d.fields[4]=$f}}
            'wrong-this' {Mutate-Capture $c 'comVtable' {param($n) (Get-ComNative $n 'IMFASFMutualExclusionVtbl').fields[3].parameterTypes[0].canonical='IUnknown *'}}
            'wrong-cpp-convention' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].callingConvention=2}}
            'wrong-vtable-convention' {Mutate-Capture $c 'comVtable' {param($n) (Get-ComNative $n 'IMFASFMutualExclusionVtbl').fields[3].callingConvention=2}}
            'nonvirtual' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].virtual=$false}}
            'nonpure' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].pure=$false}}
            'static' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].static=$true}}
            'variadic' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].variadic=$true}}
            'cpp-depth' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].parameterTypes[0].canonical='_GUID **'}}
            'vtable-depth' {Mutate-Capture $c 'comVtable' {param($n) (Get-ComNative $n 'IMFASFMutualExclusionVtbl').fields[3].parameterTypes[1].canonical='_GUID **'}}
            'native-return' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].returnType.size=8}}
            'native-base' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').bases[0].type.canonical='IMFAttributes'}}
            'cpp-parameter-name' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].parameters[0].name='another'}}
            'metadata-depth' {$m.signature.parameterTypes[0]=@{kind='pointer';elementType=$m.signature.parameterTypes[0]}}
            'metadata-array' {$m.signature.parameterTypes[0]=@{kind='array';rank=1;sizes=@(2);lowerBounds=@(0);elementType=$m.signature.parameterTypes[0]}}
            'metadata-const' {$m.parameters[0].customAttributes+=@((Attribute 'ConstAttribute'))}
            'metadata-count' {$m.signature.requiredParameterCount=2}
            'optional' {$m.parameters[0].attributes.value=18}
            'direction' {$m.parameters[0].attributes.value=1}
            'wrong-metadata-calling-convention' {$m.signature.callingConvention='StdCall'}
            'metadata-static' {$m.signature.hasThis=$false}
            'missing-associated-enum' {$m.parameters[0].customAttributes+=@((Attribute 'AssociatedEnumAttribute' @(@{type=@{kind='primitive';name='String'};value='MISSING_ENUM'})))}
            'native-reference' {Mutate-Capture $c 'comCpp' {param($n) (Get-ComNative $n 'IMFASFMutualExclusion').methods[0].parameterTypes[0].kind='LValueReference'}}
            'missing-capture' {$c.evidence.comCpp.path=Join-Path $EvidenceDirectory 'missing.json'}
            'changed-source' {$c.evidence.sources[0].sha256='0'*64}
            'wrong-native-architecture' {$c.evidence.architecture='x86'}
        }
    }
}
foreach($mutation in @('count','lifetime','wrong-closer','unrelated-method-attribute','return-flags','return-depth')){
    Check-Case "preserved-$mutation" {
        param($c)
        $m=Get-ComMember (Get-ComIdentity $c.new $owner) 'GetType'
        switch($mutation){
            'count' {$m.parameters[0].customAttributes+=@((Attribute 'NativeArrayInfoAttribute' @() @(@{kind='field';name='CountConst';type=@{kind='primitive';name='Int32'};value=2})))}
            'lifetime' {$m.parameters[0].customAttributes+=@((Attribute 'MemorySizeAttribute' @(@{type=@{kind='primitive';name='Int32'};value=4})))}
            'wrong-closer' {$m.parameters[0].customAttributes+=@((Attribute 'RAIIFreeAttribute' @(@{type=@{kind='primitive';name='String'};value='WrongFree'})))}
            'unrelated-method-attribute' {$m.customAttributes+=@((Attribute 'SupportedOSPlatformAttribute' @(@{type=@{kind='primitive';name='String'};value='windows99.0'})))}
            'return-flags' {$m.parameters+=@(@{sequence=0;name='';attributes=@{value=16};customAttributes=@()})}
            'return-depth' {$m.signature.returnType=@{kind='pointer';elementType=$m.signature.returnType}}
        }
    } 1 $(if($mutation -ceq 'return-flags'){'/returnFlags'}elseif($mutation -ceq 'return-depth'){'/return/type/*'}elseif($mutation -ceq 'unrelated-method-attribute'){'/attributes/*'}else{'/parameters/0/contract/attributes/*'})
}
Save-Json $results.ToArray() (Join-Path $EvidenceDirectory 'tests\checks.json')
Write-Host "$($results.Count) COM projection boundary checks passed; real GetType explanation retains return/interface residuals."
