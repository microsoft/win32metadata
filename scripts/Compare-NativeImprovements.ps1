#requires -Version 7.0
<#
.SYNOPSIS
Classifies a bounded set of method-contract improvements without normalizing differences.
.DESCRIPTION
Dot-source this file, then call Compare-NativeImprovements with OldMethod/NewMethod
from Effective-Method and OldTypes/NewTypes from Capture-Effective.types (see
Test-PowerbaseLogical.ps1). Pass ValidationIssues from effective-contract capture,
including unresolved attribute definitions/associations; pass @() only when that
capture succeeded without issues. Inputs are dictionaries, not raw snapshots.
No input is changed and no files are written. All paths are JSON pointers relative
to the method. Type/schema differences MUST still be compared separately.

Evidence is an independently captured, verified native/doc ledger, NOT an approval:
  kind = 'native-method'; method; architecture = 'x86'|'x64'|'arm64';
  pointerWidthBits = 32|64; nativeCallingConvention = clang's 1|2;
  metadataCallingConvention = the import flags & 0x700; source;
  parameters = @(@{ index; name; identity; pointerDepth; widthBits; direction;
                    source }); handles = @(...); directions = @(...);
  lifecycles = @(...).
Parameter pointerDepth includes the intrinsic native pointer inside a handle.
Calling-convention values are retained separately: Winapi (0x100) is not silently
equated with Cdecl (0x200) or StdCall (0x300) in either metadata input.
For callbacks use kind='native-callback', method='Invoke', owner=<native typedef
name>, and the same convention fields. OldTypes/NewTypes[owner] must include
methods=@(effective methods), not just Effective-Type: Invoke membership and the
owner's unchanged UnmanagedFunctionPointerAttribute are checked. Do not synthesize
an import on Invoke. All other owner contracts/methods must remain unchanged.

Each source locator has kind='source'|'documentation', path, sha256, line, endLine,
and quote (a nonempty exact excerpt in that line range). Documentation also needs
an authoritative https://learn.microsoft.com URL. Retained bytes, bounds and quote
are checked on every call; paths must identify retained evidence, not live URLs.
This helper verifies provenance/bindings, not C parsing or documentation extraction:
callers must derive typed facts independently, never from candidate metadata.

A handle record has kind='native-handle', identity, widthBits, pointerDepth=1,
canonical='void *'|'opaque *', source (ABI evidence), and aliasChain:
  @(@{ name; target; pointerDepth (ADDED at this alias); source }, ...).
The chain starts at identity and terminates at 'void' or an opaque tag, adding
exactly one pointer. designation={kind='handle-identity';identity;
mechanism='documented-handle'|'DECLARE_HANDLE';source} independently establishes
that this pointer alias is a HANDLE, not an arbitrary pointer typedef.
An absent FieldLayout offset (-1) is accepted only for the sole public instance
Value field of a sealed sequential wrapper with default size/packing layout.
The raw -1 is retained; explicit nonzero offsets never qualify.

A direction record has kind='sal-direction', method, index, direction, source.
It must agree with the native direction. To correct native/header direction
using authoritative documentation, use kind='documented-direction', method,
index, nativeDirection, direction, source (docs). nativeDirection must agree with
the ledger; the quote must include the parameter and [in], [out], or [in, out].
The original native direction remains in the explanation, never overwritten.
Direction-only corrections also allow unchanged native record pointers and
scalar ABI representations. Scalar parameters additionally supply canonical
(the probed C canonical spelling, e.g. 'long long' for x64 LPARAM). Metadata scalar
width/signedness must agree; named scalar typedefs must resolve to a single
NativeTypedef field. This does NOT accept IntPtr-to-LPARAM type substitutions.
For record pointers only, a single added, well-formed type-level
SupportedOSPlatformAttribute may remain outside this method gate. Its difference
is retained in separatelyReportedTypeDifferences, NOT explained or approved here.
All remaining definition properties, including fields, layout, marshalling,
ownership and other attributes, must match exactly. Changed/removed availability
attributes do not qualify; the caller must still classify type availability.
Source
quotes must contain the parameter and _In_/_Out_/_Inout_ (optionally _opt_) SAL;
documentation quotes must identify the parameter and retain the verified fact.
A lifecycle record has kind='producer-lifecycle', method, index, identity, closer,
producingSlots=@(index), allocation='unconditional-on-success', condition=$null,
source (docs). These lifecycle fields are exhaustive.
Only an ADDED RAIIFree on that exact Out handle slot can be explained. Conditional
allocations, type-wide closers, invalid sentinels and closer replacements cannot.

Returns classification=equal|expected-improvement|unexplained, differences (every
raw difference with its classification), explainedPaths, explanations, remaining,
and issues. Invalid/missing definitions fail even for equal inputs. Rules are
atomic per method: an unexplained mutation prevents all acceptance in that method.
Named enum-member references resolve only to an actual enum whose shape.name
matches that reference; enum definitions and inline enum contracts stay checked.
No schema-wide, type-wide, or general projection compatibility is claimed.
#>

function Get-NativeImprovementDifferences {
    param($Old, $New, [string]$Path = '')
    if ($Old -is [Collections.IDictionary] -and $New -is [Collections.IDictionary]) {
        foreach ($key in @(@($Old.Keys) + @($New.Keys) | Sort-Object -Unique -CaseSensitive)) {
            $segment = ([string]$key).Replace('~', '~0').Replace('/', '~1')
            $oldPresent = $Old.Contains($key); $newPresent = $New.Contains($key)
            if (-not $oldPresent -or -not $newPresent) {
                [ordered]@{path="$Path/$segment"; old=$Old[$key]; new=$New[$key]; oldPresent=$oldPresent; newPresent=$newPresent}
            } else { Get-NativeImprovementDifferences $Old[$key] $New[$key] "$Path/$segment" }
        }
    } elseif ($Old -is [array] -and $New -is [array]) {
        for ($i = 0; $i -lt [Math]::Max($Old.Count, $New.Count); $i++) {
            if ($i -ge $Old.Count -or $i -ge $New.Count) {
                [ordered]@{path="$Path/$i"; old=if($i -lt $Old.Count){$Old[$i]}else{$null};
                    new=if($i -lt $New.Count){$New[$i]}else{$null};
                    oldPresent=($i -lt $Old.Count); newPresent=($i -lt $New.Count)}
            } else { Get-NativeImprovementDifferences $Old[$i] $New[$i] "$Path/$i" }
        }
    } elseif ((ConvertTo-Json -InputObject $Old -Compress -Depth 100) -cne
              (ConvertTo-Json -InputObject $New -Compress -Depth 100)) {
        [ordered]@{path=$Path; old=$Old; new=$New; oldPresent=$true; newPresent=$true}
    }
}

function Test-NativeImprovementSource {
    param($Source, [switch]$Documentation)
    if ($Source -isnot [Collections.IDictionary] -or
        $Source.kind -cnotin @('source', 'documentation') -or
        ($Documentation -and $Source.kind -cne 'documentation') -or
        $Source.path -isnot [string] -or [string]::IsNullOrWhiteSpace($Source.path) -or
        $Source.sha256 -isnot [string] -or $Source.sha256 -cnotmatch '^[a-fA-F0-9]{64}$' -or
        ($Source.line -isnot [int] -and $Source.line -isnot [long]) -or
        ($Source.endLine -isnot [int] -and $Source.endLine -isnot [long]) -or
        $Source.line -lt 1 -or $Source.endLine -lt $Source.line -or
        $Source.quote -isnot [string] -or [string]::IsNullOrWhiteSpace($Source.quote)) { return $false }
    if ($Source.kind -ceq 'documentation') {
        $uri = $null
        if (-not [Uri]::TryCreate($Source.url, [UriKind]::Absolute, [ref]$uri) -or
            $uri.Scheme -cne 'https' -or $uri.Host -cne 'learn.microsoft.com' -or
            -not [string]::IsNullOrEmpty($uri.UserInfo)) { return $false }
    }
    if (-not (Test-Path -LiteralPath $Source.path -PathType Leaf)) { return $false }
    if ((Get-FileHash -LiteralPath $Source.path -Algorithm SHA256).Hash -ine $Source.sha256) { return $false }
    $lines = [IO.File]::ReadAllLines([IO.Path]::GetFullPath($Source.path))
    if ($Source.endLine -gt $lines.Length) { return $false }
    return (($lines[($Source.line - 1)..($Source.endLine - 1)] -join "`n").Contains($Source.quote))
}

function Test-NativeImprovementKeys {
    param($Value, [string[]]$Keys)
    if ($Value -isnot [Collections.IDictionary] -or $Value.Count -ne $Keys.Count) { return $false }
    foreach ($key in $Keys) { if (-not $Value.Contains($key)) { return $false } }
    return $true
}

function Get-NativeImprovementType {
    param($Type)
    $depth = 0
    while ($Type.kind -ceq 'pointer') {
        if (-not (Test-NativeImprovementKeys $Type @('kind', 'element'))) { return $null }
        $depth++; $Type = $Type.element
    }
    if ($Type.kind -ceq 'primitive' -and (Test-NativeImprovementKeys $Type @('kind', 'name'))) {
        return @{kind='primitive'; identity=$Type.name; depth=$depth}
    }
    if ($Type.kind -ceq 'named' -and $Type.signatureTypeKind -eq 17 -and
        (Test-NativeImprovementKeys $Type @('kind', 'name', 'signatureTypeKind'))) {
        return @{kind='named'; identity=$Type.name; depth=$depth}
    }
    return $null
}

function Test-NativeImprovementHandle {
    param($Proof, $Definition, [int]$PointerWidthBits)
    if ($Proof.kind -cne 'native-handle' -or $Proof.widthBits -ne $PointerWidthBits -or
        $Proof.pointerDepth -ne 1 -or $Proof.canonical -cnotin @('void *', 'opaque *') -or
        -not (Test-NativeImprovementSource $Proof.source) -or $Proof.source.kind -cne 'source' -or
        $Proof.aliasChain -isnot [array] -or $Proof.aliasChain.Count -eq 0) { return $false }
    $designation = $Proof.designation
    if ($designation.kind -cne 'handle-identity' -or $designation.identity -cne $Proof.identity -or
        $designation.mechanism -cnotin @('documented-handle', 'DECLARE_HANDLE') -or
        -not (Test-NativeImprovementSource $designation.source)) { return $false }
    if (($designation.mechanism -ceq 'documented-handle' -and $designation.source.kind -cne 'documentation') -or
        ($designation.mechanism -ceq 'DECLARE_HANDLE' -and $designation.source.kind -cne 'source')) { return $false }
    if (-not $designation.source.quote.Contains($Proof.identity) -or
        ($designation.mechanism -ceq 'documented-handle' -and $designation.source.quote -notmatch '\bhandle\b') -or
        ($designation.mechanism -ceq 'DECLARE_HANDLE' -and
         $designation.source.quote -cnotmatch "DECLARE_HANDLE\s*\(\s*$([regex]::Escape($Proof.identity))\s*\)")) { return $false }
    $next = $Proof.identity; $depth = 0
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($alias in $Proof.aliasChain) {
        if ($alias.name -cne $next -or -not $seen.Add($alias.name) -or
            $alias.target -isnot [string] -or [string]::IsNullOrWhiteSpace($alias.target) -or
            $alias.pointerDepth -notin @(0, 1) -or
            -not (Test-NativeImprovementSource $alias.source) -or $alias.source.kind -cne 'source') { return $false }
        $next = $alias.target; $depth += $alias.pointerDepth
    }
    if ($depth -ne 1 -or $seen.Contains($next) -or
        ($Proof.canonical -ceq 'void *' -and $next -cne 'void') -or
        ($Proof.canonical -ceq 'opaque *' -and $next -cnotmatch '^struct [A-Za-z_][A-Za-z0-9_]*$')) { return $false }
    if ($Definition.kind -cne 'type' -or $Definition.name -cne $Proof.identity -or
        $Definition.base.name -cne 'System.ValueType' -or
        $Definition.fields -isnot [array] -or $Definition.fields.Count -ne 1 -or
        @($Definition.attributes | Where-Object name -CEQ 'NativeTypedefAttribute').Count -ne 1 -or
        $Definition.layout.size -notin @($null, 0, ($PointerWidthBits / 8)) -or
        $Definition.layout.packingSize -notin @($null, 0, ($PointerWidthBits / 8))) { return $false }
    $implicitOffset = $Definition.fields[0].offset -eq -1 -and
        ($Definition.flags -band 0x118) -eq 0x108 -and
        $Definition.layout.isDefault -eq $true -and $Definition.layout.size -eq 0 -and
        $Definition.layout.packingSize -eq 0 -and $Definition.fields[0].name -ceq 'Value' -and
        $Definition.fields[0].flags -eq 6
    if ($Definition.fields[0].offset -notin @($null,0) -and -not $implicitOffset) { return $false }
    $storage = Get-NativeImprovementType $Definition.fields[0].type
    return ($null -ne $storage -and $storage.kind -ceq 'primitive' -and
        (($storage.identity -cin @('IntPtr', 'UIntPtr') -and $storage.depth -eq 0) -or
         ($storage.identity -ceq 'Void' -and $storage.depth -eq 1)))
}

function Test-NativeImprovementScalar {
    param([string]$Name, $Native, [int]$PointerWidthBits)
    $width = 0; $spellings = @()
    switch -CaseSensitive ($Name) {
        'SByte'  { $width=8;  $spellings=@('signed char') }
        'Byte'   { $width=8;  $spellings=@('unsigned char') }
        'Int16'  { $width=16; $spellings=@('short') }
        'UInt16' { $width=16; $spellings=@('unsigned short') }
        'Int32'  { $width=32; $spellings=@('int','long') }
        'UInt32' { $width=32; $spellings=@('unsigned int','unsigned long') }
        'Int64'  { $width=64; $spellings=@('long long') }
        'UInt64' { $width=64; $spellings=@('unsigned long long') }
        'IntPtr' { $width=$PointerWidthBits; $spellings=if($width -eq 32){@('int','long')}else{@('long long')} }
        'UIntPtr'{ $width=$PointerWidthBits; $spellings=if($width -eq 32){@('unsigned int','unsigned long')}else{@('unsigned long long')} }
    }
    return $width -gt 0 -and $Native.pointerDepth -eq 0 -and
        $Native.widthBits -eq $width -and $spellings -ccontains $Native.canonical
}

function Test-NativeImprovementRecordContext {
    param($Old, $New)
    if (@(Get-NativeImprovementDifferences $Old $New).Count -eq 0) { return $true }
    if ($Old.attributes -isnot [array] -or $New.attributes -isnot [array] -or
        @($Old.attributes | Where-Object name -CEQ 'SupportedOSPlatformAttribute').Count -ne 0) { return $false }
    $added = @($New.attributes | Where-Object name -CEQ 'SupportedOSPlatformAttribute')
    if ($added.Count -ne 1 -or $added[0].fixed -isnot [array] -or $added[0].fixed.Count -ne 1 -or
        $added[0].fixed[0].value -isnot [string] -or
        $added[0].fixed[0].value -cnotmatch '^windows[0-9]+(?:\.[0-9]+){1,3}$') { return $false }
    $expected = @{name='SupportedOSPlatformAttribute';fixed=@(@{type=@{kind='primitive';name='String'};
        value=$added[0].fixed[0].value});named=@()}
    if (@(Get-NativeImprovementDifferences $added[0] $expected).Count -ne 0) { return $false }
    $context = @{}
    foreach ($key in $New.Keys) { $context[$key] = $New[$key] }
    $context.attributes = @($New.attributes | Where-Object name -CNE 'SupportedOSPlatformAttribute')
    return @(Get-NativeImprovementDifferences $Old $context).Count -eq 0
}

function Test-NativeImprovementUnchangedAbi {
    param($OldType, $NewType, $OldTypes, $NewTypes, $Native, [int]$PointerWidthBits)
    if (@(Get-NativeImprovementDifferences $OldType $NewType).Count -ne 0) { return $false }
    $type = Get-NativeImprovementType $NewType
    if ($null -eq $type) { return $false }
    if ($type.kind -ceq 'named') {
        if ($type.identity -cne $Native.identity -or -not $OldTypes.Contains($type.identity) -or
            -not $NewTypes.Contains($type.identity)) { return $false }
        $definition = $NewTypes[$type.identity]
        if ($definition.base.name -cne 'System.ValueType') { return $false }
        if ($type.depth -in @(1,2)) {
            return $Native.pointerDepth -eq $type.depth -and $Native.widthBits -eq $PointerWidthBits -and
                (Test-NativeImprovementRecordContext $OldTypes[$type.identity] $definition)
        }
        if (@(Get-NativeImprovementDifferences $OldTypes[$type.identity] $definition).Count -ne 0) { return $false }
        if ($type.depth -ne 0 -or $definition.fields -isnot [array] -or $definition.fields.Count -ne 1 -or
            $definition.fields[0].name -cne 'Value' -or
            @($definition.attributes | Where-Object name -CEQ 'NativeTypedefAttribute').Count -ne 1 -or
            $definition.fields[0].offset -notin @($null,0) -or
            $definition.layout.size -notin @($null,0,($Native.widthBits / 8))) { return $false }
        $type = Get-NativeImprovementType $definition.fields[0].type
    }
    if ($null -eq $type -or $type.kind -cne 'primitive') { return $false }
    if ($type.depth -eq 0) { return Test-NativeImprovementScalar $type.identity $Native $PointerWidthBits }
    return $type.identity -ceq 'Void' -and $Native.identity -ceq 'void' -and
        $type.depth -in @(1,2) -and $Native.pointerDepth -eq $type.depth -and $Native.widthBits -eq $PointerWidthBits
}

function Test-NativeImprovementCallback {
    param($OldMethod, $NewMethod, $OldTypes, $NewTypes, $Evidence)
    if ($Evidence.owner -isnot [string] -or [string]::IsNullOrWhiteSpace($Evidence.owner) -or
        $NewMethod.name -cne 'Invoke' -or $null -ne $OldMethod.import -or $null -ne $NewMethod.import -or
        -not $OldTypes.Contains($Evidence.owner) -or -not $NewTypes.Contains($Evidence.owner)) { return $false }
    $contexts = @()
    foreach ($pair in @(@{types=$OldTypes;method=$OldMethod},@{types=$NewTypes;method=$NewMethod})) {
        $owner = $pair.types[$Evidence.owner]
        if ($owner.kind -cne 'type' -or $owner.name -cne $Evidence.owner -or
            $owner.base.name -cne 'System.MulticastDelegate' -or $owner.methods -isnot [array]) { return $false }
        $invoke = @($owner.methods | Where-Object name -CEQ 'Invoke')
        if ($invoke.Count -ne 1 -or @(Get-NativeImprovementDifferences $invoke[0] $pair.method).Count -ne 0) { return $false }
        $attributes = @($owner.attributes | Where-Object {
            $_.name -cin @('UnmanagedFunctionPointerAttribute','System.Runtime.InteropServices.UnmanagedFunctionPointerAttribute')
        })
        if ($attributes.Count -ne 1 -or $attributes[0].fixed -isnot [array] -or
            $attributes[0].fixed.Count -ne 1 -or
            $attributes[0].fixed[0].type.name -cnotin @('Int32','System.Runtime.InteropServices.CallingConvention') -or
            $attributes[0].fixed[0].value -notin @(1,2,3) -or
            ($attributes[0].fixed[0].value * 0x100) -ne $Evidence.metadataCallingConvention) { return $false }
        $context = @{}
        foreach ($key in $owner.Keys) { $context[$key] = $owner[$key] }
        $context.methods = @($owner.methods | Where-Object name -CNE 'Invoke')
        $contexts += @($context)
    }
    return @(Get-NativeImprovementDifferences $contexts[0] $contexts[1]).Count -eq 0
}

function Get-NativeImprovementDefinitionIssues {
    param($Value, $Types, [string]$Path, $Visited)
    if ($null -eq $Visited) { $Visited = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal) }
    if ($Value -is [Collections.IDictionary]) {
        if ($Value.kind -ceq 'named' -and $Value.name -cnotlike 'System.*') {
            $definition = if ($Value.name -and $Types.Contains($Value.name)) { $Types[$Value.name] } else { $null }
            if (-not $Value.name -or -not $Types.Contains($Value.name) -or
                -not (($definition.kind -ceq 'type' -and $definition.name -ceq $Value.name) -or
                      ($definition.kind -ceq 'enum' -and $definition.shape.name -ceq $Value.name))) {
                [ordered]@{path=$Path; reason='missing-definition'; target=$Value.name}
            } elseif ($Visited.Add($Value.name)) {
                Get-NativeImprovementDefinitionIssues $definition $Types "$Path/definition" $Visited
            }
        }
        if ($Value.kind -ceq 'enum') {
            $shape = if ($Value.Contains('contract') -and -not $Value.Contains('shape')) { $Value.contract }
                elseif ($Value.Contains('shape') -and -not $Value.Contains('contract')) { $Value.shape }
                else { $null }
            $name = $shape.name
            if (-not $name -or -not $Types.Contains($name) -or $Types[$name].kind -cne 'enum' -or
                $Types[$name].shape.name -cne $name) {
                [ordered]@{path=$Path; reason='missing-enum-definition'; target=$name}
            } elseif (@(Get-NativeImprovementDifferences $shape $Types[$name].shape).Count -ne 0) {
                [ordered]@{path=$Path; reason='enum-definition-mismatch'; target=$name}
            }
        }
        if ($Value.name -ceq 'AssociatedEnumAttribute') {
            $target = if ($Value.fixed -is [array] -and $Value.fixed.Count -eq 1) { $Value.fixed[0].value } else { $null }
            # Effective-Slot consumes valid, storage-checked associations. Remaining
            # associations are never treated as successful resolution here.
            [ordered]@{path=$Path; reason=if($target -and $Types.Contains($target)){'unconsumed-enum-association'}else{'missing-association-target-definition'}; target=$target}
        }
        foreach ($key in $Value.Keys) {
            Get-NativeImprovementDefinitionIssues $Value[$key] $Types "$Path/$(([string]$key).Replace('~','~0').Replace('/','~1'))" $Visited
        }
    } elseif ($Value -is [array]) {
        for ($i = 0; $i -lt $Value.Count; $i++) { Get-NativeImprovementDefinitionIssues $Value[$i] $Types "$Path/$i" $Visited }
    } elseif ($Value -is [string] -and $Value.StartsWith('UNRESOLVED:', [StringComparison]::Ordinal)) {
        [ordered]@{path=$Path; reason='unresolved-reference'; target=$Value}
    }
}

function Compare-NativeImprovements {
    [CmdletBinding()]
    param(
        [Parameter(Mandatory)][Collections.IDictionary]$OldMethod,
        [Parameter(Mandatory)][Collections.IDictionary]$NewMethod,
        [Parameter(Mandatory)][AllowEmptyCollection()][Collections.IDictionary]$OldTypes,
        [Parameter(Mandatory)][AllowEmptyCollection()][Collections.IDictionary]$NewTypes,
        [Parameter(Mandatory)][AllowEmptyCollection()][object[]]$ValidationIssues,
        [AllowNull()][Collections.IDictionary]$Evidence
    )
    $differences = @(Get-NativeImprovementDifferences $OldMethod $NewMethod)
    $issues = [Collections.Generic.List[object]]::new()
    foreach ($issue in $ValidationIssues) {
        $issues.Add(@{path='';reason='effective-contract-validation';evidence=$issue})
    }
    foreach ($issue in @(Get-NativeImprovementDefinitionIssues $OldMethod $OldTypes '/old') +
                        @(Get-NativeImprovementDefinitionIssues $NewMethod $NewTypes '/new')) { $issues.Add($issue) }
    $proposals = [Collections.Generic.List[object]]::new()
    $covered = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    if ($differences.Count -gt 0) {
        $sourceSymbol = if ($Evidence.kind -ceq 'native-callback') { $Evidence.owner } else { $NewMethod.name }
        $validEvidence = $null -ne $Evidence -and $Evidence.kind -cin @('native-method','native-callback') -and
            $Evidence.method -ceq $NewMethod.name -and $OldMethod.name -ceq $NewMethod.name -and
            $Evidence.architecture -cin @('x86', 'x64', 'arm64') -and
            $Evidence.pointerWidthBits -eq $(if($Evidence.architecture -ceq 'x86'){32}else{64}) -and
            (Test-NativeImprovementSource $Evidence.source) -and $Evidence.source.kind -ceq 'source' -and
            $sourceSymbol -is [string] -and -not [string]::IsNullOrWhiteSpace($sourceSymbol) -and
            $Evidence.source.quote -cmatch "(?<!\w)$([regex]::Escape($sourceSymbol))(?!\w)" -and
            $Evidence.parameters -is [array] -and $NewMethod.parameters -is [array] -and
            $OldMethod.parameters -is [array] -and
            $Evidence.parameters.Count -eq $NewMethod.parameters.Count -and
            $OldMethod.parameters.Count -eq $NewMethod.parameters.Count
        if ($validEvidence) {
            $convention = $Evidence.metadataCallingConvention
            $expectedNative = if($Evidence.architecture -ceq 'x86' -and $convention -in @(0x100,0x300)){2}else{1}
            $validEvidence = $convention -in @(0x100,0x200,0x300) -and
                $Evidence.nativeCallingConvention -eq $expectedNative
            if ($validEvidence -and $Evidence.kind -ceq 'native-callback') {
                $validEvidence = Test-NativeImprovementCallback $OldMethod $NewMethod $OldTypes $NewTypes $Evidence
            } elseif ($validEvidence) {
                $validEvidence = $null -ne $OldMethod.import.attributes.value -and $null -ne $NewMethod.import.attributes.value -and
                    ($OldMethod.import.attributes.value -band 0x700) -eq $convention -and
                    ($NewMethod.import.attributes.value -band 0x700) -eq $convention
            }
        }
        if (-not $validEvidence) {
            $issues.Add(@{path='';reason='missing-invalid-or-mismatched-native-evidence'})
        } else {
            for ($i = 0; $i -lt $NewMethod.parameters.Count; $i++) {
                $old = $OldMethod.parameters[$i]; $new = $NewMethod.parameters[$i]
                $native = @($Evidence.parameters | Where-Object { $_.index -ceq $i })
                $prefix = "/parameters/$i"
                if ($native.Count -ne 1 -or $old.index -cne $i -or $new.index -cne $i -or
                    $new.name -isnot [string] -or [string]::IsNullOrWhiteSpace($new.name) -or
                    $native[0].name -cne $new.name -or $old.name -cne $new.name -or
                    -not (Test-NativeImprovementSource $native[0].source) -or $native[0].source.kind -cne 'source' -or
                    -not $native[0].source.quote.Contains($new.name)) {
                    $issues.Add(@{path=$prefix;reason='missing-or-mismatched-native-parameter'}); continue
                }
                $native = $native[0]
                $oldType = Get-NativeImprovementType $old.contract.type
                $newType = Get-NativeImprovementType $new.contract.type
                $direction = if ($native.direction -cin @('In','Out','InOut')) { @{In=1;Out=2;InOut=3}[$native.direction] } else { $null }
                $proofs = @($Evidence.handles | Where-Object { $_.identity -ceq $native.identity })
                $handleMatches = $null -ne $newType -and $newType.kind -ceq 'named' -and
                    $newType.identity -ceq $native.identity -and $newType.depth -in @(0,1) -and
                    $proofs.Count -eq 1 -and $NewTypes.Contains($newType.identity) -and
                    (Test-NativeImprovementHandle $proofs[0] $NewTypes[$newType.identity] $Evidence.pointerWidthBits) -and
                    $native.pointerDepth -eq ($newType.depth + 1) -and
                    $native.widthBits -eq $Evidence.pointerWidthBits -and
                    $null -ne $direction -and ($new.flags -band 3) -eq $direction
                $typeChanges = @(Get-NativeImprovementDifferences $old.contract.type $new.contract.type "$prefix/contract/type")
                if ($typeChanges.Count -gt 0 -and $handleMatches -and $oldType.kind -ceq 'primitive' -and
                    $oldType.identity -ceq 'Void' -and $oldType.depth -in @(1,2) -and
                    $oldType.depth -eq $native.pointerDepth) {
                    $paths = @($typeChanges | ForEach-Object path)
                    $proposals.Add(@{rule='native-handle-identity';paths=$paths;native=$native;handle=$proofs[0]})
                    foreach ($path in $paths) { $null = $covered.Add($path) }
                }
                $directionProofs = @($Evidence.directions | Where-Object { $_.method -ceq $NewMethod.name -and $_.index -ceq $i })
                if ($old.flags -ne $new.flags -and $null -ne $direction -and $directionProofs.Count -eq 1 -and
                    ($old.flags -band (-bnot 3)) -eq ($new.flags -band (-bnot 3))) {
                    $proof = $directionProofs[0]
                    $desired = if ($proof.direction -cin @('In','Out','InOut')) { @{In=1;Out=2;InOut=3}[$proof.direction] } else { $null }
                    $sal = if ($null -ne $desired) { @{In='In';Out='Out';InOut='Inout'}[$proof.direction] } else { '' }
                    $validDirection = $null -ne $desired -and ($new.flags -band 3) -eq $desired -and
                        (Test-NativeImprovementSource $proof.source) -and $proof.source.quote.Contains($new.name)
                    $parameterPattern = "\b$([regex]::Escape($new.name))\b"
                    $rule = 'native-sal-direction'
                    if ($validDirection -and $proof.kind -ceq 'sal-direction') {
                        $validDirection = $proof.direction -ceq $native.direction -and
                            ($proof.source.kind -ceq 'documentation' -or
                                $proof.source.quote -cmatch "(?<!\w)_$($sal)(?:_opt)?_(?!\w)[^,;()]*$parameterPattern")
                    } elseif ($validDirection -and $proof.kind -ceq 'documented-direction') {
                        $marker = @{In='\[in\]';Out='\[out\]';InOut='\[in,\s*out\]'}[$proof.direction]
                        $nativeSal = @{In='In';Out='Out';InOut='Inout'}[$native.direction]
                        $validDirection = $proof.nativeDirection -ceq $native.direction -and
                            $proof.direction -cne $native.direction -and $proof.source.kind -ceq 'documentation' -and
                            $proof.source.quote -match "$marker\s*(?:<[^>]+>\s*)*$parameterPattern" -and
                            $native.source.quote -cmatch "(?<!\w)_$($nativeSal)(?:_opt)?_(?!\w)[^,;()]*$parameterPattern"
                        $rule = 'documented-direction-correction'
                    } else { $validDirection = $false }
                    if ($validDirection -and ($handleMatches -or
                        (Test-NativeImprovementUnchangedAbi $old.contract.type $new.contract.type $OldTypes $NewTypes $native $Evidence.pointerWidthBits))) {
                        $path = "$prefix/flags"
                        $typeDifferences = @()
                        if ($newType.kind -ceq 'named' -and $newType.depth -in @(1,2) -and
                            $OldTypes.Contains($newType.identity) -and $NewTypes.Contains($newType.identity)) {
                            $typeDifferences = @(Get-NativeImprovementDifferences $OldTypes[$newType.identity] $NewTypes[$newType.identity])
                        }
                        $proposals.Add(@{rule=$rule;paths=@($path);native=$native;evidence=$proof;
                            separatelyReportedTypeDifferences=@(if($typeDifferences.Count){
                                @{type=$newType.identity;classification='outside-method-scope';differences=$typeDifferences}
                            })})
                        $null = $covered.Add($path)
                    }
                }
                $oldAttributes = $old.contract.attributes; $newAttributes = $new.contract.attributes
                $newClosers = @($newAttributes | Where-Object name -CEQ 'RAIIFreeAttribute')
                $lifecycle = @($Evidence.lifecycles | Where-Object { $_.method -ceq $NewMethod.name -and $_.index -ceq $i })
                if ($handleMatches -and $direction -eq 2 -and
                    $oldAttributes -is [array] -and $newAttributes -is [array] -and
                    @($oldAttributes | Where-Object name -CEQ 'RAIIFreeAttribute').Count -eq 0 -and
                    $newClosers.Count -eq 1 -and $lifecycle.Count -eq 1) {
                    $life = $lifecycle[0]; $attribute = $newClosers[0]
                    $remainingAttributes = @($newAttributes | Where-Object name -CNE 'RAIIFreeAttribute')
                    $expectedAttribute = @{name='RAIIFreeAttribute';fixed=@(@{type=@{kind='primitive';name='String'};value=$life.closer});named=@()}
                    if ((Test-NativeImprovementKeys $life @('kind','method','index','identity','closer','producingSlots','allocation','condition','source')) -and
                        $life.kind -ceq 'producer-lifecycle' -and $life.identity -ceq $native.identity -and
                        $life.closer -is [string] -and $life.closer -cmatch '^[A-Za-z_][A-Za-z0-9_]*$' -and
                        $life.allocation -ceq 'unconditional-on-success' -and $null -eq $life.condition -and $life.producingSlots -is [array] -and
                        $life.producingSlots.Count -eq 1 -and $life.producingSlots[0] -ceq $i -and
                        (Test-NativeImprovementSource $life.source -Documentation) -and
                        $life.source.quote.Contains($life.closer) -and $life.source.quote.Contains($life.method) -and
                        @(Get-NativeImprovementDifferences $attribute $expectedAttribute).Count -eq 0 -and
                        @(Get-NativeImprovementDifferences $oldAttributes $remainingAttributes).Count -eq 0) {
                        $paths = @(Get-NativeImprovementDifferences $oldAttributes $newAttributes "$prefix/contract/attributes" | ForEach-Object path)
                        $proposals.Add(@{rule='documented-producer-lifecycle';paths=$paths;native=$native;evidence=$life})
                        foreach ($path in $paths) { $null = $covered.Add($path) }
                    }
                }
            }
        }
    }
    $uncovered = @($differences | Where-Object { -not $covered.Contains($_.path) })
    $accepted = $issues.Count -eq 0 -and $differences.Count -gt 0 -and $uncovered.Count -eq 0
    if (-not $accepted -and $proposals.Count -gt 0) {
        $issues.Add(@{path='';reason='unexplained-change-or-invalid-context-prevents-method-acceptance'})
    }
    foreach ($difference in $differences) {
        $difference.classification = if($accepted){'expected-improvement'}else{'unexplained'}
    }
    [ordered]@{
        classification=if($accepted){'expected-improvement'}elseif($differences.Count -eq 0 -and $issues.Count -eq 0){'equal'}else{'unexplained'}
        scope='method-only; no type/schema-wide compatibility claim'
        differences=$differences
        explainedPaths=@(if($accepted){$differences | ForEach-Object path})
        explanations=@(if($accepted){$proposals.ToArray()})
        remaining=@(if(-not $accepted){$differences})
        issues=$issues.ToArray()
    }
}
