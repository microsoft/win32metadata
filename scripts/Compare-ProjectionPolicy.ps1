#requires -Version 7.0
<#
Dot-source alongside Test-PowerbaseLogical/Compare-PowrprofEvidence. Before/After
are Effective-Method contracts (including previously verified const encoding);
OldMethod/NewMethod and snapshots are the corresponding unmodified decoder rows.
ValidationIssues must come from that capture. This is an additional classifier,
not a replacement for dependency, annotation, native ABI, or raw comparison.

New-ProjectionPolicyEvidence retains independently captured native AST and source
bytes. Pass the manifest-pinned capture hash, not a hash invented from metadata.
Every rule use records policy/approval, exact paths, source/AST and definitions.
No input contracts or files are changed by Compare-ProjectionPolicy.
#>
. "$PSScriptRoot\Compare-NativeImprovements.ps1"
$projectionPolicyFile=Join-Path $PSScriptRoot 'ProjectionPolicy.psd1'
$projectionPolicy=Import-PowerShellDataFile $projectionPolicyFile

function New-ProjectionPolicyEvidence {
    param([string]$CapturePath,[string]$CaptureSha256,[string]$SdkRoot,[string]$SdkVersion,
        [ValidateSet('x64','x86','arm64')][string]$Architecture,[string]$OutputDirectory)
    if((Get-FileHash -LiteralPath $CapturePath).Hash -cne $CaptureSha256){throw 'Native capture hash mismatch.'}
    New-Item -ItemType Directory -Force -Path $OutputDirectory | Out-Null
    $capture=Get-Content -LiteralPath $CapturePath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $sources=@()
    foreach($path in @($capture.header)+@('shared\guiddef.h','um\winnt.h','um\winreg.h','shared\minwindef.h' |
        ForEach-Object {Join-Path $SdkRoot $_})){
        $hash=(Get-FileHash -LiteralPath $path).Hash
        $copy=Join-Path $OutputDirectory "$hash.h"
        if(-not (Test-Path -LiteralPath $copy)){Copy-Item -LiteralPath $path -Destination $copy}
        $sources+=@(@{origin=[IO.Path]::GetFullPath($path);path=$copy;sha256=$hash})
    }
    $copy=Join-Path $OutputDirectory "$CaptureSha256.json"
    if(-not (Test-Path -LiteralPath $copy)){Copy-Item -LiteralPath $CapturePath -Destination $copy}
    @{schemaVersion=1;architecture=$Architecture;sdkVersion=$SdkVersion;sdkRoot=[IO.Path]::GetFullPath($SdkRoot);
        capture=@{path=$copy;sha256=$CaptureSha256;origin=$CapturePath};sources=$sources}
}

function Read-ProjectionNative($Evidence) {
    if($Evidence.schemaVersion -ne 1 -or $Evidence.architecture -cnotin @('x64','x86','arm64') -or
        [string]::IsNullOrWhiteSpace($Evidence.sdkVersion) -or
        -not (Test-Path -LiteralPath $Evidence.capture.path -PathType Leaf) -or
        (Get-FileHash -LiteralPath $Evidence.capture.path).Hash -cne $Evidence.capture.sha256){throw 'Missing or changed native projection evidence.'}
    $native=Get-Content -LiteralPath $Evidence.capture.path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $target=@{x64='x86_64';x86='i686';arm64='aarch64'}[$Evidence.architecture]
    if($native.hasErrors -or $native.arguments -cnotcontains "--target=$target-pc-windows-msvc"){throw 'Native target/errors invalidate projection evidence.'}
    return $native
}

function Get-ProjectionSource($Source,$Evidence,[string]$SdkFile='') {
    $found=@($Evidence.sources | Where-Object origin -CEQ $Source.file)
    if($found.Count -ne 1 -or $Source.line -lt 1 -or
        ($SdkFile -and $Source.file -cne (Join-Path $Evidence.sdkRoot $SdkFile))){throw 'Missing or wrong SDK source identity.'}
    $file=$found[0]
    if((Get-FileHash -LiteralPath $file.path).Hash -cne $file.sha256){throw 'Projection source bytes changed.'}
    $lines=[IO.File]::ReadAllLines($file.path)
    if($Source.line -gt $lines.Length){throw 'Native source location exceeds retained bytes.'}
    return @{origin=$file.origin;path=$file.path;sha256=$file.sha256;line=$Source.line;quote=$lines[$Source.line-1]}
}

function Get-ProjectionNativeDeclaration($Native,[string]$Name,[string]$Kind) {
    $found=@(@($Native.ownedDeclarations)+@($Native.dependencyDeclarations) |
        Where-Object {$_['name'] -ceq $Name -and $_['kind'] -ceq $Kind -and $_.source.file})
    if($found.Count -ne 1){throw "Missing/ambiguous native declaration: $Name"}
    return $found[0]
}

function Get-ProjectionDefinition($Snapshot,$Type,[string]$Name) {
    if($Type.kind -cne 'type' -or $Type.name -cne $Name -or $Type.signatureTypeKind -ne 17 -or $Type.scope -or
        $Type.fullName -cne "$($Type.namespace).$Name" -or $Type.namespace -cnotlike 'Windows.Win32.*'){throw "Wrong native metadata identity: $Name"}
    $found=@($Snapshot.declarations | Where-Object qualifiedName -CEQ $Type.fullName)
    if($found.Count -ne 1 -or $found[0].name -cne $Name){throw "Missing/ambiguous metadata definition: $Name"}
    return $found[0]
}

function Test-ProjectionRecord($Definition,[bool]$Typedef) {
    if($Definition.baseType.fullName -cne 'System.ValueType' -or
        ($Definition.attributes.value -band (-bnot 0x100000)) -ne 265 -or
        $Definition.layout.isDefault -ne $true -or $Definition.layout.size -ne 0 -or
        $Definition.layout.packingSize -ne 0 -or $Definition.declaringType){return $false}
    foreach($key in @('security','genericParameters','interfaces','methodImplementations','methods','properties','events')){
        if($Definition[$key].Count){return $false}
    }
    $attributes=@($Definition.customAttributes)
    if(-not $Typedef){return $attributes.Count -eq 0}
    return $attributes.Count -eq 1 -and
        $attributes[0].constructor.declaringType.fullName -ceq 'Windows.Win32.Foundation.Metadata.NativeTypedefAttribute' -and
        $attributes[0].fixedArguments.Count -eq 0 -and $attributes[0].namedArguments.Count -eq 0
}

function Test-ProjectionField($Field,[string]$Name,[int]$Offset) {
    return $Field.name -ceq $Name -and $Field.attributes.value -eq 6 -and
        $Field.offset -in @(-1,$Offset) -and -not $Field.constant -and -not $Field.marshalling -and
        $Field.customAttributes.Count -eq 0
}

function Get-ProjectionLeaf($Type,[switch]$Raw) {
    $pointer=0;$arrays=@();$path='';$mods=@()
    $element=if($Raw){'elementType'}else{'element'}
    while($Type.kind -cin @('pointer','modified','array')){
        switch -CaseSensitive ($Type.kind){
            'pointer' {$pointer++;$path+="/$element";$Type=$Type[$element]}
            'modified' {
                $modifier=if($Raw){$Type.modifier.fullName}else{$Type.modifier}
                if($modifier -cne 'System.Runtime.CompilerServices.IsConst' -or $Type.required -ne $true){throw 'Unapproved type modifier.'}
                $mods+=@(@{depth=$pointer;arrays=$arrays.Count})
                $path+="/$element";$Type=$Type[$element]
            }
            'array' {
                if($Type.rank -ne 1 -or $Type.sizes.Count -ne 1 -or $Type.sizes[0] -le 0 -or
                    ($Type.lowerBounds.Count -gt 0 -and ($Type.lowerBounds.Count -ne 1 -or $Type.lowerBounds[0] -ne 0))){
                    throw 'Unproven array extent.'}
                $arrays+=@([int]$Type.sizes[0]);$path+='/elementType';$Type=$Type.elementType
            }
        }
    }
    @{type=$Type;depth=$pointer;arrays=$arrays;modifiers=$mods;path=$path}
}

function Get-ProjectionGuidProof($OldRaw,$NewRaw,$Before,$After,$Source,$Native,$Evidence,$Snapshot) {
    $a=Get-ProjectionLeaf $Before;$b=Get-ProjectionLeaf $After
    $ra=Get-ProjectionLeaf $OldRaw -Raw;$rb=Get-ProjectionLeaf $NewRaw -Raw
    if($a.type.kind -cne 'named' -or $a.type.name -cne 'System.Guid' -or $b.type.kind -cne 'named' -or
        $b.type.name -cne 'GUID' -or $a.type.signatureTypeKind -ne 17 -or $b.type.signatureTypeKind -ne 17){return}
    $assembly=$ra.type.scope.identity
    $tokens=@{netstandard='CC7B13FFCD2DDD51';mscorlib='B77A5C561934E089';'System.Runtime'='B03F5F7F11D50A3A'}
    if($ra.type.fullName -cne 'System.Guid' -or $ra.type.name -cne 'Guid' -or $ra.type.namespace -cne 'System' -or
        $ra.type.signatureTypeKind -ne 17 -or $ra.type.scope.kind -cne 'assembly' -or
        -not $tokens.ContainsKey($assembly.name) -or $assembly.publicKeyOrToken -cne $tokens[$assembly.name]){
        throw 'Not the managed System.Guid identity.'}
    foreach($leaf in @($b,$ra,$rb)){
        if($leaf.depth -ne $a.depth -or @(Get-NativeImprovementDifferences $leaf.arrays $a.arrays).Count){throw 'GUID pointer/array shape differs.'}
    }
    $typeDiff=@(Get-NativeImprovementDifferences $Before $After)
    if($typeDiff.Count -ne 1 -or $typeDiff[0].path -cne "$($a.path)/name"){throw 'GUID rule cannot hide another type change.'}
    $canonical=$Source.type.canonical
    $expected='^(const )?_GUID\s*'+('\s*\*' * $a.depth)
    foreach($size in $a.arrays){$expected+='\['+$size+'\]'}
    if($canonical -cnotmatch ($expected+'$') -or ($a.depth -and $a.arrays.Count) -or
        ($a.depth -and ($Source.type.size -ne $(if($Evidence.architecture -ceq 'x86'){4}else{8}) -or
            $Source.type.alignment -ne $Source.type.size))){throw 'GUID native ABI mismatch.'}
    if(($canonical.StartsWith('const ')) -ne ($rb.modifiers.Count -eq 1) -or
        ($rb.modifiers.Count -and $rb.modifiers[0].depth -ne 0)){throw 'GUID native const level differs.'}
    $size=16;foreach($count in $a.arrays){$size*=$count}
    if(-not $a.depth -and ($Source.type.size -ne $size -or $Source.type.alignment -ne 4)){throw 'GUID native aggregate width mismatch.'}
    $typedef=Get-ProjectionNativeDeclaration $Native 'GUID' 'TypedefDecl'
    $record=Get-ProjectionNativeDeclaration $Native '_GUID' 'StructDecl'
    $tdSource=Get-ProjectionSource $typedef.source $Evidence 'shared\guiddef.h'
    $recordSource=Get-ProjectionSource $record.source $Evidence 'shared\guiddef.h'
    if($tdSource.quote -cnotmatch '}\s*GUID;' -or $recordSource.quote -cnotmatch 'typedef struct _GUID\s*\{' -or
        $typedef.underlyingType.canonical -cne '_GUID' -or $record.type.size -ne 16 -or $record.type.alignment -ne 4 -or
        $typedef.underlyingType.size -ne 16 -or $typedef.underlyingType.alignment -ne 4 -or $record.fields.Count -ne 4){
        throw 'Native GUID identity/layout is not the SDK contract.'}
    $definition=Get-ProjectionDefinition $Snapshot $rb.type 'GUID'
    if(-not (Test-ProjectionRecord $definition $false) -or $definition.fields.Count -ne 4){throw 'GUID definition contract changed.'}
    $names=@('Data1','Data2','Data3','Data4');$canonicalTypes=@('unsigned long','unsigned short','unsigned short','unsigned char[8]')
    $metadataTypes=@('UInt32','UInt16','UInt16','Byte');$offsets=@(0,4,6,8);$widths=@(4,2,2,8);$alignments=@(4,2,2,1)
    for($i=0;$i -lt 4;$i++){
        $field=$record.fields[$i];$md=$definition.fields[$i]
        $fieldSource=Get-ProjectionSource $field.source $Evidence 'shared\guiddef.h'
        if($field.name -cne $names[$i] -or $field.type.canonical -cne $canonicalTypes[$i] -or
            $field.type.size -ne $widths[$i] -or $field.type.alignment -ne $alignments[$i] -or
            $field.offsetBits -ne 8*$offsets[$i] -or $field.bitWidth -ne -1 -or
            $fieldSource.quote -cnotmatch "\b$($names[$i])\b" -or -not (Test-ProjectionField $md $names[$i] $offsets[$i])){
            throw 'GUID member layout/contract differs.'}
        $type=$md.type
        if($i -eq 3){
            $leaf=Get-ProjectionLeaf $type -Raw
            if($leaf.depth -ne 0 -or $leaf.arrays.Count -ne 1 -or $leaf.arrays[0] -ne 8 -or $leaf.modifiers.Count){throw 'GUID Data4 is not eight bytes.'}
            $type=$leaf.type
        }
        if($type.kind -cne 'primitive' -or $type.name -cne $metadataTypes[$i]){throw 'GUID member type differs.'}
    }
    @{paths=@("$($a.path)/name");nativeTypedef=$typedef;nativeRecord=$record;definition=$definition;
        sources=@($tdSource,$recordSource);managedIdentity=$ra.type;nativeUse=$Source.type}
}

function Get-ProjectionStringProof($OldRaw,$NewRaw,$Before,$After,$Source,$Native,$Evidence,$OldSnapshot,$NewSnapshot) {
    if($Before.type.kind -cne 'named' -or $Before.type.name -cne 'PWSTR' -or $After.type.kind -cne 'named' -or
        $After.type.name -cne 'PCWSTR' -or $Before.type.signatureTypeKind -ne 17 -or $After.type.signatureTypeKind -ne 17){return}
    $oldConst=@($Before.attributes | Where-Object name -CEQ 'ConstAttribute')
    $other=@($Before.attributes | Where-Object name -CNE 'ConstAttribute')
    if($oldConst.Count -ne 1 -or $oldConst[0].fixed.Count -or $oldConst[0].named.Count -or
        -not (Test-NativeImprovementKeys $oldConst[0] @('name','fixed','named')) -or
        -not (Test-NativeImprovementKeys $Before @('type','attributes')) -or
        -not (Test-NativeImprovementKeys $After @('type','attributes')) -or
        -not (Test-NativeImprovementKeys $Before.type @('kind','name','signatureTypeKind')) -or
        -not (Test-NativeImprovementKeys $After.type @('kind','name','signatureTypeKind')) -or
        @(Get-NativeImprovementDifferences $other $After.attributes).Count){throw 'Const string attributes are not the same-level contract.'}
    if($Source.type.canonical -cne 'const wchar_t *' -or $Source.type.spelling -cnotin @('LPCWSTR','PCWSTR','const WCHAR *','const wchar_t *') -or
        $Source.type.size -ne $(if($Evidence.architecture -ceq 'x86'){4}else{8}) -or
        $Source.type.alignment -ne $Source.type.size){throw 'Not a native const UTF-16 pointer.'}
    $mutable=Get-ProjectionDefinition $OldSnapshot $OldRaw 'PWSTR'
    $constant=Get-ProjectionDefinition $NewSnapshot $NewRaw 'PCWSTR'
    foreach($definition in @($mutable,$constant)){
        if(-not (Test-ProjectionRecord $definition $true) -or $definition.fields.Count -ne 1 -or
            -not (Test-ProjectionField $definition.fields[0] 'Value' 0)){throw 'String wrapper contract changed.'}
    }
    $a=Get-ProjectionLeaf $mutable.fields[0].type -Raw;$b=Get-ProjectionLeaf $constant.fields[0].type -Raw
    if($a.depth -ne 1 -or $b.depth -ne 1 -or $a.arrays.Count -or $b.arrays.Count -or $a.modifiers.Count -or
        $b.modifiers.Count -ne 1 -or $b.modifiers[0].depth -ne 0 -or
        $a.type.kind -cne 'primitive' -or $a.type.name -cnotin @('Char','UInt16') -or
        $b.type.kind -cne 'primitive' -or $b.type.name -cnotin @('Char','UInt16')){throw 'Wrong UTF-16 width or const level.'}
    $sources=@();$declarations=@()
    foreach($name in @('LPWSTR','LPCWSTR','WCHAR')){
        $d=Get-ProjectionNativeDeclaration $Native $name 'TypedefDecl'
        $s=Get-ProjectionSource $d.source $Evidence 'um\winnt.h'
        $pattern=@{LPWSTR='typedef _Null_terminated_ WCHAR \*NWPSTR, \*LPWSTR, \*PWSTR;';
            LPCWSTR='typedef _Null_terminated_ CONST WCHAR \*LPCWSTR, \*PCWSTR;';WCHAR='typedef wchar_t WCHAR;'}[$name]
        $canonical=@{LPWSTR='wchar_t *';LPCWSTR='const wchar_t *';WCHAR='wchar_t'}[$name]
        if($s.quote -cnotmatch $pattern -or $d.underlyingType.canonical -cne $canonical -or
            $d.underlyingType.size -ne $(if($name -ceq 'WCHAR'){2}elseif($Evidence.architecture -ceq 'x86'){4}else{8}) -or
            $d.underlyingType.alignment -ne $d.underlyingType.size){
            throw 'Native UTF-16 typedef chain changed.'}
        $sources+=@($s);$declarations+=@($d)
    }
    @{paths=@(Get-NativeImprovementDifferences $Before $After | ForEach-Object path);
        definitions=@($mutable,$constant);nativeDeclarations=$declarations;sources=$sources;nativeUse=$Source.type}
}

function Get-ProjectionRegsamProof($OldRaw,$NewRaw,$Before,$After,$Source,$Native,$Evidence,$Snapshot) {
    if($Before.kind -cne 'primitive' -or $Before.name -cne 'UInt32' -or $After.kind -cne 'named' -or
        $After.name -cne 'REGSAM' -or $After.signatureTypeKind -ne 17){return}
    if(-not (Test-NativeImprovementKeys $Before @('kind','name')) -or
        -not (Test-NativeImprovementKeys $After @('kind','name','signatureTypeKind'))){throw 'REGSAM type contains an unrelated contract.'}
    if($OldRaw.kind -cne 'primitive' -or $OldRaw.name -cne 'UInt32' -or $Source.type.spelling -cne 'REGSAM' -or
        $Source.type.canonical -cne 'unsigned long' -or $Source.type.size -ne 4 -or
        $Source.type.alignment -ne 4){throw 'Not a native UInt32 REGSAM scalar.'}
    $regsam=Get-ProjectionDefinition $Snapshot $NewRaw 'REGSAM'
    if($regsam.fields.Count -ne 1){throw 'Invalid REGSAM wrapper.'}
    $access=Get-ProjectionDefinition $Snapshot $regsam.fields[0].type 'ACCESS_MASK'
    foreach($d in @($regsam,$access)){
        if(-not (Test-ProjectionRecord $d $true) -or $d.fields.Count -ne 1 -or
            -not (Test-ProjectionField $d.fields[0] 'Value' 0)){throw 'Scalar wrapper carries another contract.'}
    }
    if($access.fields[0].type.kind -cne 'primitive' -or $access.fields[0].type.name -cne 'UInt32'){throw 'REGSAM chain is cyclic or not UInt32.'}
    $sources=@();$declarations=@()
    foreach($name in @('REGSAM','ACCESS_MASK','DWORD')){
        $d=Get-ProjectionNativeDeclaration $Native $name 'TypedefDecl'
        $file=@{REGSAM='um\winreg.h';ACCESS_MASK='um\winnt.h';DWORD='shared\minwindef.h'}[$name]
        $target=@{REGSAM='ACCESS_MASK';ACCESS_MASK='DWORD';DWORD='unsigned long'}[$name]
        $s=Get-ProjectionSource $d.source $Evidence $file
        if($d.underlyingType.canonical -cne 'unsigned long' -or $d.underlyingType.size -ne 4 -or
            $d.underlyingType.alignment -ne 4 -or
            $d.underlyingType.spelling -cne $target -or $s.quote -cnotmatch "typedef\s+$target\s+$name\s*;"){
            throw 'Native REGSAM alias chain changed.'}
        $sources+=@($s);$declarations+=@($d)
    }
    @{paths=@(Get-NativeImprovementDifferences $Before $After | ForEach-Object path);
        definitions=@($regsam,$access);nativeDeclarations=$declarations;sources=$sources;nativeUse=$Source.type}
}

function Assert-ProjectionReferences($Method,$Snapshot) {
    $definitions=@{}
    foreach($definition in $Snapshot.declarations){
        if($definitions.ContainsKey($definition.qualifiedName)){throw 'Duplicate metadata identity.'}
        $definitions[$definition.qualifiedName]=$definition
    }
    $queue=[Collections.Generic.Queue[object]]::new();$queue.Enqueue($Method)
    $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    while($queue.Count){
        $value=$queue.Dequeue()
        if($value -is [Collections.IDictionary]){
            if($value.kind -ceq 'type' -and $value.fullName -and $value.fullName -cnotlike 'System.*'){
                if(-not $definitions.ContainsKey($value.fullName)){throw "Unresolved metadata identity: $($value.fullName)"}
                if($seen.Add($value.fullName)){
                    $d=$definitions[$value.fullName]
                    $queue.Enqueue($d.baseType);$queue.Enqueue($d.customAttributes)
                    $queue.Enqueue($(if($d.baseType.fullName -ceq 'System.Enum'){@($d.fields | Where-Object name -CEQ 'value__')}else{$d.fields}))
                }
            }
            if($value.constructor.declaringType.name -ceq 'AssociatedEnumAttribute'){
                $name=$value.fixedArguments[0].value
                $found=@($Snapshot.declarations | Where-Object {$_.name -ceq $name -or $_.qualifiedName -ceq $name})
                if($found.Count -ne 1 -or $found[0].baseType.fullName -cne 'System.Enum'){throw "Unresolved association: $name"}
            }
            foreach($key in $value.Keys){if($key -cne 'evidence'){$queue.Enqueue($value[$key])}}
        }elseif($value -is [array]){foreach($item in $value){$queue.Enqueue($item)}}
    }
}

function Compare-ProjectionPolicy {
    param($Before,$After,$OldMethod,$NewMethod,$OldSnapshot,$NewSnapshot,$Evidence,[AllowEmptyCollection()][object[]]$ValidationIssues)
    $differences=@(Get-NativeImprovementDifferences $Before $After)
    $accepted=[Collections.Generic.List[object]]::new();$rejected=[Collections.Generic.List[object]]::new()
    try {
        if(-not $PSBoundParameters.ContainsKey('ValidationIssues') -or $ValidationIssues.Count){throw 'Unresolved comparison contracts.'}
        Assert-ProjectionReferences $OldMethod $OldSnapshot
        Assert-ProjectionReferences $NewMethod $NewSnapshot
        $native=Read-ProjectionNative $Evidence
        $method=Get-ProjectionNativeDeclaration $native $Before.name 'FunctionDecl'
        if($Before.name -cne $After.name -or $OldMethod.name -cne $Before.name -or $NewMethod.name -cne $Before.name -or
            $method.parameters.Count -ne $Before.parameters.Count -or $method.parameters.Count -ne $After.parameters.Count -or
            $Before.signatureHeader -ne $After.signatureHeader -or
            $method.callingConvention -ne $(if($Evidence.architecture -ceq 'x86'){2}else{1}) -or
            ($Before.import.attributes.value -band 0x700) -ne 0x100 -or ($After.import.attributes.value -band 0x700) -ne 0x100){
            throw 'Method identity, parameter count, or calling convention differs.'}
        $methodSource=Get-ProjectionSource $method.source $Evidence
        if($methodSource.quote -cnotmatch ("\b"+[regex]::Escape($method.name)+"\s*\(")){throw 'Native method locator mismatch.'}
        for($i=0;$i -lt $method.parameters.Count;$i++){
            $source=$method.parameters[$i];$use=Get-ProjectionSource $source.source $Evidence
            if($Before.parameters[$i].name -cne $source.name -or $After.parameters[$i].name -cne $source.name -or
                $use.quote -cnotmatch ("\b"+[regex]::Escape($source.name)+"\b")){throw 'Native parameter identity mismatch.'}
            $old=$Before.parameters[$i].contract;$new=$After.parameters[$i].contract
            $rawOld=$OldMethod.signature.parameterTypes[$i];$rawNew=$NewMethod.signature.parameterTypes[$i]
            foreach($rule in @('Guid','ConstString','Regsam')){
                try {
                    $proof=switch -CaseSensitive ($rule){
                        'Guid' {Get-ProjectionGuidProof $rawOld $rawNew $old.type $new.type $source $native $Evidence $NewSnapshot}
                        'ConstString' {Get-ProjectionStringProof $rawOld $rawNew $old $new $source $native $Evidence $OldSnapshot $NewSnapshot}
                        'Regsam' {Get-ProjectionRegsamProof $rawOld $rawNew $old.type $new.type $source $native $Evidence $NewSnapshot}
                    }
                    if($proof){
                        $prefix="/parameters/$i/contract";if($rule -cne 'ConstString'){$prefix+='/type'}
                        $paths=@($proof.paths | ForEach-Object {"$prefix$_"})
                        if(@($paths | Where-Object {$_ -cnotin $differences.path}).Count){throw 'Explained path is not an actual difference.'}
                        $accepted.Add([ordered]@{ruleId=$projectionPolicy.Rules[$rule].Id;policyVersion=$projectionPolicy.Version;
                            classification=$projectionPolicy.Rules[$rule].Classification;approval=$projectionPolicy.Approval;
                            target=$method.name;parameter=$i;paths=$paths;source=$use;evidence=$proof;
                            nativeCapture=$Evidence.capture;architecture=$Evidence.architecture})
                    }
                } catch { $rejected.Add(@{ruleId=$projectionPolicy.Rules[$rule].Id;parameter=$i;reason=$_.Exception.Message}) }
            }
        }
    } catch {$accepted.Clear();$rejected.Add(@{ruleId='context';reason=$_.Exception.Message})}
    $paths=@($accepted | ForEach-Object {$_.paths})
    $remaining=@($differences | Where-Object {$_.path -cnotin $paths})
    [ordered]@{policyId=$projectionPolicy.Id;policyVersion=$projectionPolicy.Version;policySha256=(Get-FileHash $projectionPolicyFile).Hash;
        approval=$projectionPolicy.Approval;explanations=$accepted.ToArray();explainedPaths=$paths;differences=$differences;
        remaining=$remaining;rejected=$rejected.ToArray();
        classification=if($remaining.Count -or $rejected.Count){'review-required'}elseif(@($accepted | Where-Object classification -CEQ 'expected-improvement').Count){
            'expected-improvement'}elseif($paths.Count){'projection-equivalent'}else{'equal'}}
}
