#requires -Version 7.0
<#
COM context adapter v1. Imports the unchanged v1 projection proof routines.
Compare-ComProjectionPolicy selects exact raw interface/member identities itself;
it never accepts a renamed imported-function fixture. Evidence contains the
ordinary ProjectionPolicy native/source ledger plus comCpp/comVtable native-only
capture identities. Those captures must use the original TU bytes and arguments.
Only direct, pure-virtual IUnknown-derived interfaces are supported in v1.
Reference parameters, overloaded members and other inheritance stay unresolved.
Rule explanations can coexist with unrelated return/interface/dependency issues:
they never turn the whole method or interface into an equivalence claim.
#>
. "$PSScriptRoot\Test-PowerbaseLogical.ps1" -EvidenceDirectory $(if($EvidenceDirectory){$EvidenceDirectory}else{$PSScriptRoot}) -FunctionsOnly
. "$PSScriptRoot\Compare-ProjectionPolicy.ps1"

function Get-ComRaw($Value) {
    if($Value -is [Collections.IDictionary]){
        $copy=[ordered]@{}
        foreach($key in @($Value.Keys | Sort-Object -CaseSensitive)){if($key -cne 'evidence'){$copy[$key]=Get-ComRaw $Value[$key]}}
        return $copy
    }
    if($Value -is [array]){return ,@($Value | ForEach-Object {Get-ComRaw $_})}
    return $Value
}
function Get-ComIdentity($Snapshot,[string]$Name) {
    $found=@($Snapshot.declarations | Where-Object qualifiedName -CEQ $Name)
    if($found.Count -ne 1){throw "Missing/ambiguous interface identity: $Name"}
    return $found[0]
}
function Get-ComMember($Type,[string]$Name) {
    $found=@($Type.methods | Where-Object name -CEQ $Name)
    if($found.Count -ne 1 -or $found[0].qualifiedName -cne "$($Type.qualifiedName).$Name"){
        throw "Missing/ambiguous interface method: $($Type.qualifiedName).$Name"}
    return $found[0]
}
function Read-ComCapture($Identity,$Evidence,[string]$Mode) {
    if(-not (Test-Path -LiteralPath $Identity.path -PathType Leaf) -or
        (Get-FileHash -LiteralPath $Identity.path).Hash -cne $Identity.sha256){throw 'Native COM capture missing or changed.'}
    $capture=Get-Content -LiteralPath $Identity.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $target=@{x64='x86_64';x86='i686';arm64='aarch64'}[$Evidence.architecture]
    if($capture.schema -cne 'native-com-context/v1' -or $capture.hasErrors -or
        $capture.arguments -cnotcontains "--target=$target-pc-windows-msvc" -or
        (($capture.arguments -ccontains '-DCINTERFACE=1') -ne ($Mode -ceq 'vtable'))){throw 'Native COM target or language context differs.'}
    return $capture
}
function Get-ComNative($Capture,[string]$Name) {
    $found=@($Capture.declarations | Where-Object name -CEQ $Name)
    if($found.Count -ne 1){throw "Missing/ambiguous native COM declaration: $Name"}
    return $found[0]
}
function Get-ComGuid($Type,$Snapshot) {
    $attrs=@($Type.customAttributes | Where-Object {$_.constructor.declaringType.name -ceq 'GuidAttribute'})
    if($attrs.Count -ne 1){throw 'COM identity requires exactly one GuidAttribute.'}
    $a=$attrs[0]
    $provider=$a.constructor.declaringType
    if($provider.fullName -cnotin @('Windows.Win32.Foundation.Metadata.GuidAttribute','Windows.Foundation.Metadata.GuidAttribute') -or
        $a.fixedArguments.Count -ne 11 -or $a.namedArguments.Count -or $a.constructor.name -cne '.ctor' -or
        $a.constructor.signature.header -ne 32 -or $a.constructor.signature.requiredParameterCount -ne 11 -or
        $a.constructor.signature.parameterTypes.Count -ne 11 -or
        $a.constructor.signature.returnType.kind -cne 'primitive' -or $a.constructor.signature.returnType.name -cne 'Void'){
        throw 'Unrecognized COM IID encoding.'}
    if($provider.fullName -ceq 'Windows.Win32.Foundation.Metadata.GuidAttribute' -and
        ($provider.scope -or -not (Get-Definition $Snapshot $provider.fullName))){throw 'COM IID attribute definition missing.'}
    if($provider.fullName -ceq 'Windows.Foundation.Metadata.GuidAttribute' -and
        ($provider.scope.kind -cne 'assembly' -or $provider.scope.identity.name -cne 'Windows' -or
         $provider.scope.identity.version -cne '255.255.255.255' -or $provider.scope.identity.publicKeyOrToken -cne '')){
        throw 'Unrecognized external IID provider identity.'}
    $types=@('UInt32','UInt16','UInt16')+@('Byte')*8
    for($i=0;$i -lt 11;$i++){
        if($a.fixedArguments[$i].type.kind -cne 'primitive' -or $a.fixedArguments[$i].type.name -cne $types[$i] -or
            $a.constructor.signature.parameterTypes[$i].kind -cne 'primitive' -or
            $a.constructor.signature.parameterTypes[$i].name -cne $types[$i]){
            throw 'Invalid COM IID argument type.'}
    }
    $v=@($a.fixedArguments | ForEach-Object {$_.value})
    $text=('{0:x8}-{1:x4}-{2:x4}-{3:x2}{4:x2}-{5:x2}{6:x2}{7:x2}{8:x2}{9:x2}{10:x2}' -f $v)
    return ([Guid]::ParseExact($text,'D')).ToString('D')
}
function Get-ComNativeIid($Type,$Evidence) {
    $source=Get-ProjectionSource $Type.extentStart $Evidence
    $match=[regex]::Match($source.quote,'MIDL_INTERFACE\("([0-9a-fA-F-]{36})"\)')
    if(-not $match.Success){throw 'Native IID is not retained at the interface declaration.'}
    @{iid=([Guid]::ParseExact($match.Groups[1].Value,'D')).ToString('D');source=$source}
}
function Test-ComNativeTypeEqual($First,$Second) {
    foreach($key in @('canonical','kind','size','alignment')){if($First[$key] -cne $Second[$key]){return $false}}
    return $true
}
function Get-ComContextProof($OldType,$NewType,$OldMethod,$NewMethod,$OldSnapshot,$NewSnapshot,$Evidence) {
    $cpp=Read-ComCapture $Evidence.comCpp $Evidence 'cpp'
    $c=Read-ComCapture $Evidence.comVtable $Evidence 'vtable'
    $native=Get-ComNative $cpp $NewType.name
    $vtable=Get-ComNative $c "$($NewType.name)Vtbl"
    $instance=Get-ComNative $c $NewType.name
    $base=Get-ComNative $cpp 'IUnknown'
    $pointer=if($Evidence.architecture -ceq 'x86'){4}else{8}
    $convention=if($Evidence.architecture -ceq 'x86'){2}else{1}
    if($native.bases.Count -ne 1 -or $native.bases[0].type.canonical -cne 'IUnknown' -or $base.bases.Count){
        throw 'Unsupported inheritance: v1 requires direct IUnknown and no other base.'}
    $iid=Get-ComNativeIid $native $Evidence
    $baseIid=Get-ComNativeIid $base $Evidence
    if($baseIid.iid -cne '00000000-0000-0000-c000-000000000046' -or
        (Get-ComGuid $OldType $OldSnapshot) -cne $iid.iid -or (Get-ComGuid $NewType $NewSnapshot) -cne $iid.iid){
        throw 'Native/reference/candidate interface IID differs.'}
    foreach($type in @($OldType,$NewType)){
        if($type.attributes.value -ne 161 -or $type.baseType -or $type.declaringType -or
            $type.interfaces.Count -ne 1 -or $type.interfaces[0].type.name -cne 'IUnknown' -or $type.interfaces[0].type.scope -or
            $type.fields.Count -or $type.genericParameters.Count -or $type.properties.Count -or $type.events.Count -or
            $type.methodImplementations.Count){throw 'Unsupported metadata interface structure.'}
        $snapshot=if([object]::ReferenceEquals($type,$OldType)){$OldSnapshot}else{$NewSnapshot}
        $baseDefinition=Get-ComIdentity $snapshot $type.interfaces[0].type.fullName
        if((Get-ComGuid $baseDefinition $snapshot) -cne $baseIid.iid -or $baseDefinition.attributes.value -ne 161 -or
            $baseDefinition.interfaces.Count -or $baseDefinition.baseType -or
            @(Get-NativeImprovementDifferences @($baseDefinition.methods.name) @('QueryInterface','AddRef','Release')).Count){
            throw 'IUnknown metadata identity or slot prefix differs.'}
    }
    if($OldType.qualifiedName -cne $NewType.qualifiedName -or $OldType.name -cne $native.name -or
        $native.type.size -ne $pointer -or $native.type.alignment -ne $pointer -or $native.fields.Count -or
        $instance.type.size -ne $pointer -or $instance.fields.Count -ne 1 -or $instance.fields[0].name -cne 'lpVtbl' -or
        $instance.fields[0].offsetBits -ne 0 -or $instance.fields[0].type.canonical -cne "$($native.name)Vtbl *"){
        throw 'COM interface/native object layout identity differs.'}
    $names=@($native.methods | ForEach-Object {$_.name})
    if(@($names | Sort-Object -Unique -CaseSensitive).Count -ne $names.Count -or
        @(Get-NativeImprovementDifferences @($OldType.methods.name) $names).Count -or
        @(Get-NativeImprovementDifferences @($NewType.methods.name) $names).Count -or
        @($base.methods.name).Count -ne 3 -or
        @(Get-NativeImprovementDifferences @($base.methods.name) @('QueryInterface','AddRef','Release')).Count){
        throw 'Overload, missing member or reordered interface slot.'}
    $slots=@($base.methods)+@($native.methods)
    if($vtable.fields.Count -ne $slots.Count -or $vtable.type.size -ne $slots.Count*$pointer -or
        $vtable.type.alignment -ne $pointer){throw 'Native vtable width or length differs.'}
    $slotProof=@()
    for($i=0;$i -lt $slots.Count;$i++){
        $method=$slots[$i];$field=$vtable.fields[$i]
        if($method.name -cne $field.name -or $field.offsetBits -ne $i*$pointer*8 -or $field.type.size -ne $pointer -or
            $field.type.alignment -ne $pointer -or $method.virtual -ne $true -or $method.pure -ne $true -or
            $method.static -ne $false -or $method.const -ne $false -or $method.access -ne 1 -or
            $method.variadic -ne $false -or $field.variadic -ne $false -or
            $method.callingConvention -ne $convention -or $field.callingConvention -ne $convention -or
            $field.parameterTypes.Count -ne $method.parameterTypes.Count+1 -or
            $field.parameterTypes[0].canonical -cne "$($native.name) *" -or $field.parameterTypes[0].size -ne $pointer -or
            -not (Test-ComNativeTypeEqual $method.returnType $field.returnType)){
            throw "Native COM slot/convention mismatch at $i."}
        for($p=0;$p -lt $method.parameterTypes.Count;$p++){
            if(-not (Test-ComNativeTypeEqual $method.parameterTypes[$p] $field.parameterTypes[$p+1])){
                throw "C++ and explicit-This native parameter ABI differs at $i/$p."}
        }
        foreach($typeAndSnapshot in @(@($OldType,$OldSnapshot),@($NewType,$NewSnapshot))){
            $type=$typeAndSnapshot[0]
            if($i -lt 3){$type=Get-ComIdentity $typeAndSnapshot[1] $type.interfaces[0].type.fullName}
            $md=$type.methods[$(if($i -lt 3){$i}else{$i-3})]
                if($md.qualifiedName -cne "$($type.qualifiedName).$($method.name)" -or $md.import -or
                    $md.attributes.value -ne 1478 -or $md.signature.header -ne 32 -or $md.signature.hasThis -ne $true -or
                    $md.signature.explicitThis -ne $false -or $md.signature.callingConvention -cne 'Default' -or
                    $md.signature.genericParameterCount -ne 0 -or $md.genericParameters.Count -or
                    $md.signature.requiredParameterCount -ne $method.parameterTypes.Count -or
                    $md.signature.parameterTypes.Count -ne $method.parameterTypes.Count){
                    throw "Metadata member/vtable identity differs at $i."}
        }
        $slotProof+=@(@{slot=$i;name=$method.name;offsetBits=$field.offsetBits;convention=$convention;
            cppSignature=$method.type;explicitThisSignature=$field.type})
    }
    $selected=@($native.methods | Where-Object name -CEQ $OldMethod.name)
    if($selected.Count -ne 1 -or $OldMethod.name -cne $NewMethod.name){throw 'Missing/ambiguous native method.'}
    $selected=$selected[0]
    if($selected.parameterTypes.Count -ne $selected.parameters.Count -or
        @($selected.parameterTypes | Where-Object {$_.canonical -match '&' -or $_.kind -cin @('LValueReference','RValueReference')}).Count -or
        $selected.returnType.kind -cin @('LValueReference','RValueReference')){
        throw 'Unsupported native-reference parameter/return; not rewritten to a pointer.'}
    if($selected.returnType.spelling -cne 'HRESULT' -or $selected.returnType.canonical -cne 'long' -or
        $selected.returnType.size -ne 4 -or $selected.returnType.alignment -ne 4){throw 'Unsupported native COM return ABI.'}
    @{interface=$native.name;qualifiedName=$NewType.qualifiedName;iid=$iid;baseIid=$baseIid;slots=$slotProof;
        selectedSlot=3+[array]::IndexOf($names,$selected.name);nativeMethod=$selected;
        nativeReturn=$selected.returnType;returnProjection='Not normalized; raw/effective return and binding issues remain.'}
}

function Compare-ComProjectionPolicy {
    param($OldSnapshot,$NewSnapshot,[string]$InterfaceName,[string]$MethodName,$Evidence)
    $accepted=[Collections.Generic.List[object]]::new();$rejected=[Collections.Generic.List[object]]::new()
    $issues=[Collections.Generic.List[object]]::new()
    $raw=@();$differences=@();$contextDifferences=@();$context=$null;$before=$null;$after=$null
    try{
        $oldType=Get-ComIdentity $OldSnapshot $InterfaceName;$newType=Get-ComIdentity $NewSnapshot $InterfaceName
        $old=Get-ComMember $oldType $MethodName;$new=Get-ComMember $newType $MethodName
        $raw=@(Get-NativeImprovementDifferences (Get-ComRaw $old) (Get-ComRaw $new))
        $before=Effective-Method $old $OldSnapshot 'reference'
        $after=Effective-Method $new $NewSnapshot 'candidate'
        $differences=@(Get-NativeImprovementDifferences $before $after)
        $oldContext=Get-ComRaw $oldType;$newContext=Get-ComRaw $newType
        $oldContext.Remove('methods');$newContext.Remove('methods')
        $contextDifferences=@(Get-NativeImprovementDifferences $oldContext $newContext)
        $context=Get-ComContextProof $oldType $newType $old $new $OldSnapshot $NewSnapshot $Evidence
        $native=Read-ProjectionNative $Evidence
        for($i=0;$i -lt $context.nativeMethod.parameters.Count;$i++){
            $source=$context.nativeMethod.parameters[$i]
            $sourceProof=Get-ProjectionSource $source.source $Evidence
            $a=$before.parameters[$i];$b=$after.parameters[$i]
            if($a.name -cne $source.name -or $b.name -cne $source.name -or
                $a.index -ne $i -or $b.index -ne $i -or
                $sourceProof.quote -cnotmatch ("\b"+[regex]::Escape($source.name)+"\b")){
                throw 'Native COM parameter identity mismatch.'}
            $sal=[regex]::Match($sourceProof.quote,'_(Inout|In|Out)(?:_opt)?_')
            if(-not $sal.Success){throw 'Unsupported/unproven COM SAL direction.'}
            $direction=@{In=1;Out=2;Inout=3}[$sal.Groups[1].Value]
            $optional=$sal.Value.Contains('_opt_')
            if(($a.flags -band 3) -ne $direction -or ($b.flags -band 3) -ne $direction -or
                (($a.flags -band 16) -ne 0) -ne $optional -or (($b.flags -band 16) -ne 0) -ne $optional){
                throw 'Native COM direction/optionality differs.'}
            $slotIssues=@($issues | Where-Object {$_.use -ceq "$MethodName.parameter[$i]"})
            if($slotIssues.Count){throw 'Unresolved metadata references at projection slot.'}
            if($source.type.canonical -cmatch '^_GUID\s*\*+$' -and
                @(@($a.contract.attributes)+@($b.contract.attributes) | Where-Object name -CEQ 'ConstAttribute').Count){
                throw 'Native mutable GUID pointer cannot acquire const through projection.'}
            foreach($rule in @('Guid','ConstString','Regsam')){
                try{
                    $proof=switch -CaseSensitive ($rule){
                        'Guid' {Get-ProjectionGuidProof $old.signature.parameterTypes[$i] $new.signature.parameterTypes[$i] $a.contract.type $b.contract.type $source $native $Evidence $NewSnapshot}
                        'ConstString' {Get-ProjectionStringProof $old.signature.parameterTypes[$i] $new.signature.parameterTypes[$i] $a.contract $b.contract $source $native $Evidence $OldSnapshot $NewSnapshot}
                        'Regsam' {Get-ProjectionRegsamProof $old.signature.parameterTypes[$i] $new.signature.parameterTypes[$i] $a.contract.type $b.contract.type $source $native $Evidence $NewSnapshot}
                    }
                    if($proof){
                        $prefix="/parameters/$i/contract";if($rule -cne 'ConstString'){$prefix+='/type'}
                        $paths=@($proof.paths | ForEach-Object {"$prefix$_"})
                        if(@($paths | Where-Object {$_ -cnotin $differences.path}).Count){throw 'Rule path does not identify an actual difference.'}
                        $accepted.Add(@{ruleId=$projectionPolicy.Rules[$rule].Id;classification=$projectionPolicy.Rules[$rule].Classification;
                            approval=$projectionPolicy.Approval;interface=$InterfaceName;iid=$context.iid.iid;member=$MethodName;
                            slot=$context.selectedSlot;parameter=$i;paths=$paths;source=$sourceProof;evidence=$proof})
                    }
                }catch{$rejected.Add(@{ruleId=$projectionPolicy.Rules[$rule].Id;parameter=$i;reason=$_.Exception.Message})}
            }
        }
    }catch{$accepted.Clear();$rejected.Add(@{ruleId='com-context/v1';reason=$_.Exception.Message})}
    $paths=@($accepted | ForEach-Object {$_.paths})
    $remaining=@($differences | Where-Object {$_.path -cnotin $paths})
    $unresolved=$remaining.Count -gt 0 -or $contextDifferences.Count -gt 0 -or $rejected.Count -gt 0 -or $issues.Count -gt 0
    @{adapter='com-method-context/v1';policyId=$projectionPolicy.Id;policyVersion=$projectionPolicy.Version;
        approval=$projectionPolicy.Approval;interface=$InterfaceName;member=$MethodName;context=$context;
        rawDifferences=$raw;effectiveDifferences=$differences;remaining=$remaining;contextDifferences=$contextDifferences;
        bindingIssues=$issues.ToArray();explanations=$accepted.ToArray();explainedPaths=$paths;rejections=$rejected.ToArray();
        classification=if($unresolved){'review-required'}elseif(@($accepted | Where-Object classification -CEQ 'expected-improvement').Count){
            'expected-improvement'}elseif($paths.Count){'projection-equivalent'}else{'equal'};
        scope='Exact COM member/slot proof only. Interface, return, inheritance and dependency obligations are never closed by a parameter rule.'}
}
