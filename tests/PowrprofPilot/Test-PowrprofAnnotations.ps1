[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)
$ErrorActionPreference='Stop'
$checks=[Collections.Generic.List[object]]::new()
function Check([string]$Stage,[string]$Symbol,[string]$Contract,[bool]$Passed,$Expected,$Actual){
    $checks.Add([ordered]@{stage=$Stage;symbol=$Symbol;contract=$Contract;passed=$Passed;expected=$Expected;actual=$Actual})
}
function Attributes($Target,[string]$Name){
    return @($Target.customAttributes | Where-Object {$_.constructor.declaringType.name -ceq $Name})
}
function Annotation($Target,[string]$Value,[string]$Stage,[string]$Symbol){
    if($Value.StartsWith('win32metadata:supported_os=')){
        $expected=$Value.Substring('win32metadata:supported_os='.Length)
        $actual=@(Attributes $Target 'SupportedOSPlatformAttribute')
        Check $Stage $Symbol 'supported OS' ($actual.Count -eq 1 -and $actual[0].fixedArguments[0].value -ceq $expected) $expected $actual
    }elseif($Value.StartsWith('win32metadata:associated_enum=')){
        $expected=$Value.Substring('win32metadata:associated_enum='.Length)
        $actual=@(Attributes $Target 'AssociatedEnumAttribute')
        Check $Stage $Symbol 'associated enum' ($actual.Count -eq 1 -and $actual[0].fixedArguments[0].value -ceq $expected) $expected $actual
    }elseif($Value -ceq 'win32metadata:set_last_error'){
        Check $Stage $Symbol 'SetLastError' (($Target.import.attributes.value -band 0x40) -eq 0x40) $true $Target.import
    }else{throw "Unverified source annotation: $Value"}
}
function Native-Const($NativeType,$MetadataType,[string]$Stage,[string]$Symbol){
    if($NativeType.canonical -notmatch '\bconst\b'){
        $current=$MetadataType;$invented=$false
        while($current){
            if($current.kind -ceq 'modified' -and $current.modifier.fullName -ceq 'System.Runtime.CompilerServices.IsConst'){$invented=$true}
            $current=$current.elementType
        }
        Check $Stage $Symbol 'no SAL-fabricated native const' (-not $invented) $NativeType $MetadataType
    }elseif($NativeType.canonical -cmatch '^const [^*]+\s+\*$' -and $MetadataType.kind -cin @('pointer','modified')){
        $passed=$MetadataType.kind -ceq 'modified' -and $MetadataType.required -eq $true -and
            $MetadataType.modifier.fullName -ceq 'System.Runtime.CompilerServices.IsConst' -and
            $MetadataType.elementType.kind -ceq 'pointer' -and $MetadataType.elementType.elementType.kind -cin @('type','primitive')
        Check $Stage $Symbol 'retain native const at single-pointee level' $passed $NativeType $MetadataType
    }
}
foreach($architecture in @('x64','x86','arm64','merged')){
    $nativeArchitecture=if($architecture -eq 'merged'){'x64'}else{$architecture}
    $native=Get-Content (Join-Path $EvidenceDirectory "native\$nativeArchitecture-metadata-candidate.json") -Raw |
        ConvertFrom-Json -AsHashtable -Depth 100
    foreach($variant in @('control','candidate')){
        $stage="$variant-$architecture"
        $snapshot=Get-Content (Join-Path $EvidenceDirectory "contracts\$stage.json") -Raw | ConvertFrom-Json -AsHashtable -Depth 100
        $types=@{};$methods=@{}
        foreach($type in $snapshot.declarations){
            $types[$type.name]=$type
            if($type.name -ceq 'Apis'){foreach($method in $type.methods){$methods[$method.name]=$method}}
        }
        foreach($function in $native.ownedDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl'}){
            for($index=0;$index -lt $function.parameters.Count;$index++){
                Native-Const $function.parameters[$index].type $methods[$function.name].signature.parameterTypes[$index] `
                    $stage "$($function.name)/$($function.parameters[$index].name)"
            }
        }
        if($variant -eq 'candidate'){
            foreach($declaration in $native.ownedDeclarations){
                $target=if($declaration.kind -ceq 'FunctionDecl'){$methods[$declaration.name]}else{$types[$declaration.name.TrimStart('_')]}
                foreach($annotation in $declaration.annotations){
                    if($annotation.StartsWith('win32metadata:associated_enum=')){
                        $method=if($declaration.kind -ceq 'FunctionDecl'){$target}else{@($target.methods | Where-Object name -CEQ 'Invoke')[0]}
                        $slot=@($method.parameters | Where-Object sequence -eq 0)[0]
                        Annotation $slot $annotation $stage "$($declaration.name)/return"
                    }else{Annotation $target $annotation $stage $declaration.name}
                }
                for($index=0;$index -lt $declaration.parameters.Count;$index++){
                    foreach($annotation in $declaration.parameters[$index].annotations){
                        $slot=@($target.parameters | Where-Object sequence -eq ($index+1))[0]
                        Annotation $slot $annotation $stage "$($declaration.name)/$($declaration.parameters[$index].name)"
                    }
                }
            }
            $alias=$types['PDEVICE_NOTIFY_CALLBACK_ROUTINE']
            Annotation $alias 'win32metadata:supported_os=windows8.0' $stage $alias.name
            $invoke=@($alias.methods | Where-Object name -CEQ 'Invoke')[0]
            Annotation @($invoke.parameters | Where-Object sequence -eq 0)[0] 'win32metadata:associated_enum=WIN32_ERROR' $stage "$($alias.name)/return"
        }
        foreach($name in @('PWRSCHEMESENUMPROC','PWRSCHEMESENUMPROC_V1','PWRSCHEMESENUMPROC_V2',
            'DEVICE_NOTIFY_CALLBACK_ROUTINE','PDEVICE_NOTIFY_CALLBACK_ROUTINE')){
            $type=$types[$name]
            $invoke=@($type.methods | Where-Object name -CEQ 'Invoke')[0]
            $nativeCallback=@($native.ownedDeclarations | Where-Object {$_['name'] -ceq $name})[0]
            $flags=if($name -like 'PWRSCHEMES*'){@(1,1,1,1,1,1,19)}else{@(17,1,1)}
            for($index=0;$index -lt $flags.Count;$index++){
                $slot=@($invoke.parameters | Where-Object sequence -eq ($index+1))[0]
                Check $stage "$name/parameter$index" 'native SAL direction and optionality' `
                    ($null -ne $slot -and $slot.attributes.value -eq $flags[$index]) $flags[$index] $slot.attributes
                Native-Const $nativeCallback.callbackSignature.parameterTypes[$index] $invoke.signature.parameterTypes[$index] `
                    $stage "$name/parameter$index"
            }
            if($name -like 'PWRSCHEMES*'){
                foreach($index in @(2,4)){
                    $slot=@($invoke.parameters | Where-Object sequence -eq ($index+1))[0]
                    $memory=@(Attributes $slot 'MemorySizeAttribute')
                    $passed=$memory.Count -eq 1 -and $memory[0].fixedArguments.Count -eq 0 -and
                        $memory[0].namedArguments.Count -eq 1 -and $memory[0].namedArguments[0].name -ceq 'BytesParamIndex' -and
                        $memory[0].namedArguments[0].value -eq ($index-1)
                    Check $stage "$name/parameter$index" 'native SAL byte count' $passed ($index-1) $memory
                }
            }
        }
    }
}
$checks.ToArray() | ConvertTo-Json -Depth 30 | Set-Content -Encoding utf8 (Join-Path $EvidenceDirectory 'annotation-contract-checks.json')
$failures=@($checks | Where-Object passed -eq $false)
if($failures.Count){throw "$($failures.Count) source-to-metadata annotation/SAL checks failed; see annotation-contract-checks.json."}
Write-Host "$($checks.Count) actual source-to-metadata annotation/SAL checks passed."
