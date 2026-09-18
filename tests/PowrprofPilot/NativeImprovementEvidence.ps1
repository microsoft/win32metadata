<#
Retained documentation excerpts, retrieved 2026-09-18. Comparison evidence only.
https://learn.microsoft.com/en-us/windows/win32/api/powrprof/nf-powrprof-readglobalpwrpolicy
[out] pGlobalPowerPolicy
A pointer to a GLOBAL_POWER_POLICY structure that receives the information.

https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-powerunregistersuspendresumenotification
PowerUnregisterSuspendResumeNotification
Cancels a registration to receive notification when the system is suspended or resumed.
DWORD PowerUnregisterSuspendResumeNotification(
  [in, out] HPOWERNOTIFY RegistrationHandle
);
A handle to a registration obtained by calling the PowerRegisterSuspendResumeNotification function.
#>
$nativeDocumentationPath=$PSCommandPath
function New-NativeLocator($Source,[string]$OutputDirectory,[switch]$Method){
    $hash=(Get-FileHash $Source.file).Hash
    $copy=Join-Path $OutputDirectory "$hash.h"
    if(-not (Test-Path $copy)){Copy-Item $Source.file $copy}
    $lines=[IO.File]::ReadAllLines($copy)
    $end=[int]$Source.line
    if($Method){
        while($end -lt $lines.Length -and $lines[$end-1] -notmatch '\)\s*;'){$end++}
        if($end -eq $lines.Length){throw 'Native method extent was not found.'}
    }
    [ordered]@{kind='source';path=$copy;sha256=$hash;line=[int]$Source.line;endLine=$end;
        quote=($lines[($Source.line-1)..($end-1)] -join "`n");origin=$Source.file}
}
function New-NativeDocLocator([string]$Kind,[string]$OutputDirectory){
    $hash=(Get-FileHash $nativeDocumentationPath).Hash
    $copy=Join-Path $OutputDirectory "$hash.ps1"
    if(-not (Test-Path $copy)){Copy-Item $nativeDocumentationPath $copy}
    $lines=[IO.File]::ReadAllLines($copy)
    $start=if($Kind -eq 'policy'){[Array]::IndexOf($lines,'[out] pGlobalPowerPolicy')+1}
        else{[Array]::IndexOf($lines,'PowerUnregisterSuspendResumeNotification')+1}
    $end=if($Kind -eq 'policy'){$start+1}else{$start+6}
    [ordered]@{kind='documentation';path=$copy;sha256=$hash;line=$start;endLine=$end;
        quote=($lines[($start-1)..($end-1)] -join "`n");
        url=if($Kind -eq 'policy'){'https://learn.microsoft.com/en-us/windows/win32/api/powrprof/nf-powrprof-readglobalpwrpolicy'}
            else{'https://learn.microsoft.com/en-us/windows/win32/api/powerbase/nf-powerbase-powerunregistersuspendresumenotification'}}
}
function New-NativeMethodEvidence($Capture,[string]$Name,[string]$Architecture,[string]$OutputDirectory){
    New-Item -ItemType Directory -Path $OutputDirectory -Force | Out-Null
    $native=@($Capture.ownedDeclarations | Where-Object {$_['kind'] -ceq 'FunctionDecl' -and $_['name'] -ceq $Name})[0]
    if(-not $native){throw "Native method evidence missing: $Name"}
    $width=if($Architecture -eq 'x86'){32}else{64}
    $parameters=@(
        for($index=0;$index -lt $native.parameters.Count;$index++){
            $parameter=$native.parameters[$index]
            $source=New-NativeLocator $parameter.source $OutputDirectory
            $match=[regex]::Match($source.quote,'_(Inout|In|Out)(?:_opt)?_')
            if(-not $match.Success){throw "Unreviewed SAL evidence: $Name/$($parameter.name)"}
            $direction=@{In='In';Out='Out';Inout='InOut'}[$match.Groups[1].Value]
            $identity=$parameter.type.spelling
            if($Name -eq 'ReadGlobalPwrPolicy'){$identity='GLOBAL_POWER_POLICY'}
            elseif($identity -ceq 'PHPOWERNOTIFY'){$identity='HPOWERNOTIFY'}
            [ordered]@{index=$index;name=$parameter.name;identity=$identity;
                pointerDepth=([regex]::Matches($parameter.type.canonical,'\*')).Count;
                widthBits=8*$parameter.type.size;canonical=$parameter.type.canonical;direction=$direction;source=$source}
        }
    )
    $result=[ordered]@{kind='native-method';method=$Name;architecture=$Architecture;pointerWidthBits=$width;
        nativeCallingConvention=$native.callingConvention;metadataCallingConvention=0x100;
        source=(New-NativeLocator $native.source $OutputDirectory -Method);parameters=$parameters;
        handles=@();directions=@();lifecycles=@()}
    if($Name -eq 'ReadGlobalPwrPolicy'){
        $result.directions=@([ordered]@{kind='documented-direction';method=$Name;index=0;
            nativeDirection='In';direction='Out';source=(New-NativeDocLocator 'policy' $OutputDirectory)})
        return $result
    }
    $declarations=@($Capture.ownedDeclarations)+@($Capture.dependencyDeclarations)+@($Capture.annotationDependencyDeclarations)+@($Capture.macroDerivedDependencyDeclarations)
    $handle=@($declarations | Where-Object {$_['kind'] -ceq 'TypedefDecl' -and $_['name'] -ceq 'HPOWERNOTIFY'})[0]
    $pvoid=@($declarations | Where-Object {$_['kind'] -ceq 'TypedefDecl' -and $_['name'] -ceq 'PVOID'})[0]
    if($handle.underlyingType.spelling -cne 'PVOID' -or $handle.underlyingType.canonical -cne 'void *' -or
        $handle.underlyingType.size*8 -ne $width -or $pvoid.underlyingType.canonical -cne 'void *'){throw 'Native handle alias proof changed.'}
    $handleSource=New-NativeLocator $handle.source $OutputDirectory
    $docs=New-NativeDocLocator 'registration' $OutputDirectory
    $result.handles=@([ordered]@{kind='native-handle';identity='HPOWERNOTIFY';widthBits=$width;pointerDepth=1;canonical='void *';
        source=$handleSource;designation=@{kind='handle-identity';identity='HPOWERNOTIFY';mechanism='documented-handle';source=$docs};
        aliasChain=@(@{name='HPOWERNOTIFY';target='PVOID';pointerDepth=0;source=$handleSource},
            @{name='PVOID';target='void';pointerDepth=1;source=(New-NativeLocator $pvoid.source $OutputDirectory)})})
    if($Name -eq 'PowerRegisterSuspendResumeNotification'){
        $result.lifecycles=@([ordered]@{kind='producer-lifecycle';method=$Name;index=2;identity='HPOWERNOTIFY';
            closer='PowerUnregisterSuspendResumeNotification';producingSlots=@(2);allocation='unconditional-on-success';condition=$null;source=$docs})
    }elseif($Name -eq 'PowerUnregisterSuspendResumeNotification'){
        $result.directions=@([ordered]@{kind='sal-direction';method=$Name;index=0;direction='InOut';source=$parameters[0].source})
    }else{throw "Unreviewed method evidence requested: $Name"}
    return $result
}
