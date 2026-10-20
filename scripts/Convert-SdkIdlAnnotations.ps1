#Requires -Version 7.0

<#
.PARAMETER SharedSalBootstrap
Adds the native sal.h bootstrap used by the selected shared SAL vocabulary policy.
Existing includes are preserved; this does not activate or qualify the parser.
.PARAMETER AllowCompleteInterfaceParameterCarriers
Enables Optional/ComOutPtr parameter drafts using the selected vocabulary.
Complete top-level interfaces need no trailing cpp_quote region. Native IDL and
quoted-native conditional frames must match. Short Interface::parameter selectors
must identify one actual non-property method parameter. Existing method/return
placement and the default authoring behavior are unchanged.
.PARAMETER PatchedIdl
Converts an existing original-IDL source from compiler metadata carriers to
selector-bound cpp_quote comments. PristineIdl is required to restore the exact
native SAL annotation of each affected declaration. Logical enum groups remain
compiled. This mode does not compile, prepare an SDK, or change the input files.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory, ParameterSetName = 'Author')][string]$InputMap,
    [Parameter(Mandatory, ParameterSetName = 'Author')][string]$SdkIncludeRoot,
    [Parameter(Mandatory, ParameterSetName = 'Author')][string]$OutputDirectory,
    [string[]]$Original,
    [string]$SdkProjectRoot = "$PSScriptRoot\..\generation\WinSDK",
    [switch]$Apply,
    [string]$AnnotationHeader = "$PSScriptRoot\..\generation\WinSDK\RecompiledIdlHeaders\shared\win32metadata_annotations.h",
    [switch]$SharedSalBootstrap,
    [switch]$AllowCompleteInterfaceParameterCarriers,
    [Parameter(Mandatory, ParameterSetName = 'Transport')][string]$PatchedIdl,
    [Parameter(Mandatory, ParameterSetName = 'Transport')][string]$PristineIdl,
    [Parameter(Mandatory, ParameterSetName = 'Transport')][string]$TransportOutput
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
if ($PSCmdlet.ParameterSetName -eq 'Author') {
$SdkIncludeRoot = [IO.Path]::GetFullPath($SdkIncludeRoot).TrimEnd('\')
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\')
$SdkProjectRoot = [IO.Path]::GetFullPath($SdkProjectRoot).TrimEnd('\')
if ($OutputDirectory -eq $SdkIncludeRoot -or
    $OutputDirectory.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SdkIncludeRoot.StartsWith("$OutputDirectory\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'IDL authoring output must not overlap the installed SDK.'
}
if ($SdkProjectRoot -eq $SdkIncludeRoot -or
    $SdkProjectRoot.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SdkIncludeRoot.StartsWith("$SdkProjectRoot\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'Parser activation must not modify the installed SDK.'
}
if (Test-Path -LiteralPath $OutputDirectory) {
    throw "Use a new output directory; do not overwrite an existing authoring result: $OutputDirectory"
}
}

function Resolve-Input([string]$Relative) {
    if ([IO.Path]::IsPathRooted($Relative) -or [IO.Path]::GetExtension($Relative) -ne '.idl') {
        throw "An original owner must be an SDK-relative shipped IDL: $Relative"
    }
    $path = [IO.Path]::GetFullPath([IO.Path]::Combine($SdkIncludeRoot, $Relative))
    if (!$path.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Original IDL escapes the SDK include root: $Relative"
    }
    if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Missing original shipped IDL: $Relative"
    }
    $path
}

function Get-Hash([byte[]]$Bytes) {
    [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData($Bytes))
}

function Get-CodeMask([string]$Text) {
    [regex]::Replace($Text, '(?s)/\*.*?\*/|//[^\r\n]*|"(?:\\.|[^"\\])*"|''(?:\\.|[^''\\])*''', {
        param($match)
        [regex]::Replace($match.Value, '[^\r\n]', ' ')
    })
}

function Get-AttributeStart([string]$Mask, [int]$Offset, [Collections.Generic.HashSet[string]]$AttributeMacros) {
    $start = $Offset
    while ($true) {
        $cursor = $start - 1
        while ($cursor -ge 0 -and [char]::IsWhiteSpace($Mask[$cursor])) { $cursor-- }
        if ($cursor -lt 0 -or $Mask[$cursor] -notin @(']', ')')) { break }
        $close = $Mask[$cursor]
        $open = if ($close -eq ']') { '[' } else { '(' }
        $depth = 1
        $cursor--
        while ($cursor -ge 0 -and $depth -gt 0) {
            if ($Mask[$cursor] -eq $close) { $depth++ }
            if ($Mask[$cursor] -eq $open) { $depth-- }
            $cursor--
        }
        if ($depth -ne 0) { throw "Unbalanced IDL attributes before byte $Offset" }
        if ($close -eq ')') {
            while ($cursor -ge 0 -and [char]::IsWhiteSpace($Mask[$cursor])) { $cursor-- }
            $end = $cursor + 1
            while ($cursor -ge 0 -and $Mask[$cursor] -match '[A-Za-z_0-9]') { $cursor-- }
            if (!$AttributeMacros.Contains($Mask.Substring($cursor + 1, $end - $cursor - 1))) { break }
        }
        $start = $cursor + 1
    }
    $line = $Mask.LastIndexOf("`n", [Math]::Max(0, $start - 1)) + 1
    if ($Mask.Substring($line, $start - $line).Trim().Length -eq 0) { return $line }
    $start
}

function Find-QuotedFunction([string]$Text, [string]$Mask, [object[]]$Quotes, [string]$Name) {
    $returnType = '(?:(?:SH)?STDAPI(?:_\([A-Za-z_]\w*\))?|(?:EXTERN_C\s+)?(?:HRESULT|DWORD)\s+(?:STDAPICALLTYPE|STDMETHODCALLTYPE|WINAPI))'
    for ($i = 0; $i -lt $Quotes.Count; $i++) {
        $quote = $Quotes[$i]
        if ($Mask.Substring($quote.Index, $quote.Length) -notmatch '^\s*cpp_quote\s*\(') { continue }
        $body = $quote.Groups['code'].Value
        $nameMatch = [regex]::Match($body, "(?<![A-Za-z_0-9])$([regex]::Escape($Name))\s*\(")
        if (!$nameMatch.Success) { continue }
        $prefix = $body.Substring(0, $nameMatch.Index)
        $prefixQuote = $i
        while ($prefix -notmatch "^\s*$returnType\s+$" -and $prefixQuote -gt 0) {
            $previous = $Quotes[$prefixQuote - 1]
            $next = $Quotes[$prefixQuote]
            if ($Text.Substring($previous.Index + $previous.Length, $next.Index - $previous.Index - $previous.Length) -notmatch '^\s*$' -or
                $Mask.Substring($previous.Index, $previous.Length) -notmatch '^\s*cpp_quote\s*\(' -or
                $prefix -match '[;{}()]') { break }
            $prefix = $previous.Groups['code'].Value + ' ' + $prefix
            $prefixQuote--
        }
        if ($prefix -notmatch "^\s*$returnType\s+$") { continue }
        $prototype = $body.Substring($nameMatch.Index)
        $last = $quote
        $j = $i + 1
        while ($true) {
            $code = Get-CodeMask ($prototype.Replace('\"', '"'))
            $depth = 0
            $close = -1
            for ($cursor = $code.IndexOf('('); $cursor -ge 0 -and $cursor -lt $code.Length; $cursor++) {
                if ($code[$cursor] -eq '(') { $depth++ }
                elseif ($code[$cursor] -eq ')') {
                    $depth--
                    if (!$depth) { $close = $cursor; break }
                }
            }
            if ($close -ge 0) {
                if ($code.Substring($close + 1) -match '^\s*;') {
                    $rawClose = $close
                    foreach ($escapedQuote in [regex]::Matches($prototype, '\\"')) {
                        if ($escapedQuote.Index -le $rawClose) { $rawClose++ }
                    }
                    [pscustomobject]@{
                        name = $Name
                        offset = $quote.Groups['code'].Index + $nameMatch.Index
                        afterParametersOffset = $last.Groups['code'].Index + $rawClose -
                            ($prototype.Length - $last.Groups['code'].Length) + 1
                        start = $Quotes[$prefixQuote].Index
                        end = $last.Index + $last.Length
                    }
                }
                break
            }
            if ($j -ge $Quotes.Count) { break }
            $next = $Quotes[$j]
            if ($Text.Substring($last.Index + $last.Length, $next.Index - $last.Index - $last.Length) -notmatch '^\s*$' -or
                $Mask.Substring($next.Index, $next.Length) -notmatch '^\s*cpp_quote\s*\(') { break }
            $prototype += "`n" + $next.Groups['code'].Value
            $last = $next
            $j++
        }
    }
}

function Get-ClosingDelimiter([string]$Mask, [int]$Start, [char]$Open, [char]$Close) {
    $depth = 1
    for ($cursor = $Start + 1; $cursor -lt $Mask.Length; $cursor++) {
        if ($Mask[$cursor] -eq $Open) { $depth++ }
        elseif ($Mask[$cursor] -eq $Close) {
            $depth--
            if (!$depth) { return $cursor }
        }
    }
    -1
}

function Get-IdlAnnotationInsertion([string]$Text, [string]$Mask, [int]$Start, [int]$End) {
    $declaration = $Mask.Substring($Start, $End - $Start)
    $annotations = @([regex]::Matches($Text.Substring($Start, $End - $Start),
        '\bannotation\s*\(\s*"(?<value>(?:\\.|[^"\\])*)"\s*\)') |
        Where-Object { $Mask.Substring($Start + $_.Index, 'annotation'.Length) -ceq 'annotation' })
    $annotation = if ($annotations.Count -eq 1) { $annotations[0].Groups['value'] }
    [pscustomobject]@{
        insertionOffset = if ($annotation) { $Start + $annotation.Index + $annotation.Length }
            else { $Start + [regex]::Match($declaration, '\S').Index }
        annotationCount = $annotations.Count
        appendToAnnotation = $null -ne $annotation
        nativeRetval = $declaration -match '\[[^\]]*\bretval\b[^\]]*\]' -or
            ($annotation -and $annotation.Value -match '\b_(?:Out|COM_Outptr)_retval_')
    }
}

function Find-IdlField([string]$Text, [string]$Mask, [string]$Name) {
    $parts = $Name -split '::'
    if ($parts.Count -ne 2) { return }
    foreach ($record in [regex]::Matches($Mask,
        '\b(?:(?<typedef>typedef)(?:\s|\[[^\]]*\])+)?struct\s+(?:(?<tag>[A-Za-z_]\w*)\s*)?\{')) {
        $open = $record.Index + $record.Length - 1
        $close = Get-ClosingDelimiter $Mask $open '{' '}'
        if ($close -lt 0) { continue }
        $alias = [regex]::Match($Mask.Substring($close + 1), '^\s*(?<name>[A-Za-z_]\w*)\s*;')
        if ($record.Groups['tag'].Value -cne $parts[0] -and
            !($record.Groups['typedef'].Success -and $alias.Success -and $alias.Groups['name'].Value -ceq $parts[0])) { continue }
        $depth = 0
        $start = $open + 1
        for ($cursor = $start; $cursor -lt $close; $cursor++) {
            if ($Mask[$cursor] -eq '{') { $depth++ }
            elseif ($Mask[$cursor] -eq '}') { $depth-- }
            elseif ($Mask[$cursor] -eq ';' -and !$depth) {
                $declaration = $Mask.Substring($start, $cursor - $start)
                $field = [regex]::Match($declaration,
                    "\b(?<name>$([regex]::Escape($parts[1])))\s*(?:\[[^\]]*\]\s*)*$")
                if ($field.Success) {
                    $placement = Get-IdlAnnotationInsertion $Text $Mask $start $cursor
                    $nativeOwner = if ($record.Groups['tag'].Success) { $record.Groups['tag'].Value } else { '' }
                    [pscustomobject]@{
                        offset = $start + $field.Groups['name'].Index; start = $start; end = $cursor
                        nativeQualifiedName = "${nativeOwner}::$($parts[1])"
                        insertionOffset = $placement.insertionOffset
                        annotationCount = $placement.annotationCount
                        appendToAnnotation = $placement.appendToAnnotation
                    }
                }
                $start = $cursor + 1
            }
        }
    }
}

function Find-IdlMethod([string]$Text, [string]$Mask, [object[]]$Definitions, [string]$Name) {
    $parts = $Name -split '::'
    if ($parts.Count -notin @(2, 3)) { return }
    $methodPattern = if ($parts.Count -eq 3 -and $parts[1] -ceq '*') { '[A-Za-z_]\w*' }
        else { [regex]::Escape($parts[1]) }
    foreach ($definition in @($Definitions | Where-Object { $_.Groups['name'].Value -ceq $parts[0] })) {
        $open = $definition.Index + $definition.Length - 1
        $close = Get-ClosingDelimiter $Mask $open '{' '}'
        if ($close -lt 0) { continue }
        $terminator = [regex]::Match($Mask.Substring($close + 1), '^\s*;')
        $end = $close + 1
        if ($terminator.Success) { $end += $terminator.Length }
        $lineEnd = $Text.IndexOf("`n", $end)
        if ($lineEnd -lt 0) { $lineEnd = $Text.Length }
        if ($Mask.Substring($end, $lineEnd - $end).Trim()) { continue }
        $body = $Mask.Substring($open + 1, $close - $open - 1)
        foreach ($method in [regex]::Matches($body, "\b(?<name>$methodPattern)\s*\(")) {
            $methodOffset = $open + 1 + $method.Index
            $preceding = $Mask.Substring($open + 1, $methodOffset - $open - 1)
            if ([regex]::Matches($preceding, '\{').Count -ne [regex]::Matches($preceding, '\}').Count -or
                $preceding -notmatch '[A-Za-z_]\w*\s+$') { continue }
            $parametersOpen = $methodOffset + $method.Length - 1
            $parametersClose = Get-ClosingDelimiter $Mask $parametersOpen '(' ')'
            if ($parametersClose -lt 0 -or $parametersClose -ge $close -or
                $Mask.Substring($parametersClose + 1, $close - $parametersClose - 1) -notmatch '^\s*;') { continue }
            $methodName = "$($parts[0])::$($method.Groups['name'].Value)"
            $attributes = Get-CodeMask $Text.Substring($open + 1, $methodOffset - $open - 1)
            $attributes = [regex]::Replace($attributes, '(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*', ' ')
            $attributes = $attributes.Substring($attributes.LastIndexOf(';') + 1)
            $property = $attributes -cmatch '\b(?:propget|propput|propputref)\b'
            if ($parts.Count -eq 2) {
                [pscustomobject]@{
                    offset = $methodOffset; start = $methodOffset; end = $parametersClose + 1
                    insertionOffset = [Math]::Min($Text.Length, $lineEnd + 1)
                    needsNewline = $lineEnd -eq $Text.Length
                    nativeRetval = $false
                    methodQualifiedName = $methodName; isProperty = $property
                }
                continue
            }
            $round = 0
            $square = 0
            $start = $parametersOpen + 1
            for ($cursor = $start; $cursor -le $parametersClose; $cursor++) {
                $character = $Mask[$cursor]
                if ($cursor -eq $parametersClose -or ($character -eq ',' -and !$round -and !$square)) {
                    $parameter = $Mask.Substring($start, $cursor - $start)
                    $match = [regex]::Match($parameter,
                        "\b(?<name>$([regex]::Escape($parts[2])))\s*(?:\[[^\]]*\]\s*)*$")
                    if ($match.Success) {
                        $placement = Get-IdlAnnotationInsertion $Text $Mask $start $cursor
                        [pscustomobject]@{
                            offset = $start + $match.Groups['name'].Index; start = $start; end = $cursor
                            insertionOffset = $placement.insertionOffset
                            needsNewline = $false
                            annotationCount = $placement.annotationCount
                            appendToAnnotation = $placement.appendToAnnotation
                            nativeRetval = $placement.nativeRetval
                            methodQualifiedName = $methodName; isProperty = $property
                        }
                    }
                    $start = $cursor + 1
                    continue
                }
                if ($character -eq '(') { $round++ }
                elseif ($character -eq ')') { $round-- }
                elseif ($character -eq '[') { $square++ }
                elseif ($character -eq ']') { $square-- }
            }
        }
    }
}

function Find-AssociationTarget([string]$Text, [string]$Mask, [object[]]$Quotes, [object[]]$Definitions, [string]$Name) {
    $parts = $Name -split '::'
    if ($parts.Count -eq 2) {
        foreach ($field in @(Find-IdlField $Text $Mask $Name)) {
            $field | Add-Member NoteProperty kind 'FieldDecl'
            $field | Add-Member NoteProperty sourceForm 'native-idl-field-or-interface-parameter'
            $field
        }
        foreach ($function in @(Find-QuotedFunction $Text $Mask $Quotes $parts[0])) {
            $quote = @($Quotes | Where-Object { $_.Index -eq $function.start -and $_.Index + $_.Length -eq $function.end })
            if ($quote.Count -ne 1 -or $quote[0].Groups['code'].Value.Contains('\"')) { continue }
            $body = $quote[0].Groups['code']
            $code = Get-CodeMask $body.Value
            $nameOffset = $function.offset - $body.Index
            $open = $code.IndexOf('(', $nameOffset)
            if ($open -lt 0) { continue }
            $close = Get-ClosingDelimiter $code $open '(' ')'
            if ($close -lt 0 -or $code.Substring($close + 1) -notmatch '^\s*;\s*$') { continue }
            $round = 0
            $square = 0
            $start = $open + 1
            for ($cursor = $start; $cursor -le $close; $cursor++) {
                $character = $code[$cursor]
                if ($cursor -eq $close -or ($character -eq ',' -and !$round -and !$square)) {
                    $parameter = $code.Substring($start, $cursor - $start)
                    $match = [regex]::Match($parameter, "\b(?<name>$([regex]::Escape($parts[1])))\s*(?:\[[^\]]*\]\s*)*$")
                    if ($match.Success) {
                        [pscustomobject]@{
                            kind = 'ParmVarDecl'; sourceForm = 'quoted-native-function-parameter'; nativeQualifiedName = $Name
                            offset = $body.Index + $start + $match.Groups['name'].Index
                            start = $body.Index + $start; end = $body.Index + $cursor
                            insertionOffset = $body.Index + $start + [regex]::Match($parameter, '\S').Index
                            annotationCount = 0; appendToAnnotation = $false
                        }
                    }
                    $start = $cursor + 1
                    continue
                }
                if ($character -eq '(') { $round++ }
                elseif ($character -eq ')') { $round-- }
                elseif ($character -eq '[') { $square++ }
                elseif ($character -eq ']') { $square-- }
            }
        }
    }
    elseif ($parts.Count -eq 3) {
        $return = $parts[-1] -ceq 'return'
        $targetName = if ($return) { $parts[0..1] -join '::' } else { $Name }
        foreach ($method in @(Find-IdlMethod $Text $Mask $Definitions $targetName)) {
            $method | Add-Member NoteProperty kind $(if ($return) { 'CXXMethodDecl' } else { 'ParmVarDecl' })
            $method | Add-Member NoteProperty sourceForm $(if ($return) { 'native-idl-interface-return' } else { 'native-idl-field-or-interface-parameter' })
            $method | Add-Member NoteProperty nativeQualifiedName $targetName
            $method
        }
    }
}

function Get-ParameterOverride([object]$Fact) {
    if ($Fact.category -cne 'declaration-attribute-override' -or $Fact.value -isnot [string]) { return }
    $payload = [regex]::Match($Fact.value,
        '^(?<target>[A-Za-z_]\w*(?:::[A-Za-z_]\w*){1,2})=\[(?<remove>-)?(?<name>Optional|ComOutPtr)\]$')
    if (!$payload.Success -or $payload.Groups['target'].Value -cne $Fact.symbol) { return }
    $value = if ($payload.Groups['remove'].Success) { 'false' } else { 'true' }
    [pscustomobject]@{ name = $payload.Groups['name'].Value; macro = "_Win32_$($payload.Groups['name'].Value)_($value)" }
}

function Get-BraceScopes([string]$Mask) {
    $scopes = [Collections.Generic.List[object]]::new()
    $stack = [Collections.Generic.Stack[object]]::new()
    $balanced = $true
    foreach ($brace in [regex]::Matches($Mask, '[{}]')) {
        if ($brace.Value -ceq '{') {
            $declaration = [regex]::Match($Mask.Substring(0, $brace.Index),
                '\b(?<kind>library|module)\s+(?<name>[A-Za-z_]\w*)\s*$')
            $scope = [pscustomobject]@{ start = $brace.Index; end = $Mask.Length
                kind = $(if ($declaration.Success) { $declaration.Groups['kind'].Value } else { 'opaque' })
                name = $declaration.Groups['name'].Value }
            $scopes.Add($scope)
            $stack.Push($scope)
        }
        elseif ($stack.Count) { $stack.Pop().end = $brace.Index }
        else { $balanced = $false }
    }
    [pscustomobject]@{ balanced = $balanced -and !$stack.Count; scopes = @($scopes) }
}

function Get-NativeQuoteDirectiveMask([string]$Mask, [object[]]$Quotes) {
    $result = [Text.StringBuilder]::new([regex]::Replace($Mask, '[^\r\n]', ' '))
    foreach ($quote in $Quotes) {
        $code = $quote.Groups['code'].Value
        if ($Mask.Substring($quote.Index, $quote.Length) -notmatch '^\s*cpp_quote\s*\(' -or
            $code -notmatch '^\s*#') { continue }
        for ($index = 0; $index -lt $code.Length; $index++) { $result[$quote.Index + $index] = $code[$index] }
    }
    $result.ToString()
}

function Get-IdlConditionalFrame([string]$Mask, [int]$Offset) {
    $stack = [Collections.Generic.List[int]]::new()
    foreach ($directive in [regex]::Matches($Mask.Substring(0, $Offset),
        '(?m)^[ \t]*#[ \t]*(?<kind>if|ifdef|ifndef|elif|else|endif)\b')) {
        switch ($directive.Groups['kind'].Value) {
            { $_ -cin @('if', 'ifdef', 'ifndef') } { $stack.Add($directive.Index) }
            { $_ -cin @('elif', 'else') } {
                if (!$stack.Count) { throw 'Unbalanced original IDL conditional.' }
                $stack[$stack.Count - 1] = $directive.Index
            }
            'endif' {
                if (!$stack.Count) { throw 'Unbalanced original IDL conditional.' }
                $stack.RemoveAt($stack.Count - 1)
            }
        }
    }
    $stack -join '|'
}

function Find-ExistingTrailingQuoteRegion([string]$Mask, [string]$DirectiveMask, [string]$QuoteRegionMask,
    [object[]]$Quotes, [object]$Method) {
    $frame = Get-IdlConditionalFrame $DirectiveMask $Method.offset
    $nativeMask = Get-NativeQuoteDirectiveMask $Mask $Quotes
    $nativeFrame = Get-IdlConditionalFrame $nativeMask $Method.offset
    foreach ($quote in $Quotes) {
        if ($quote.Index -lt $Method.insertionOffset -or
            $Mask.Substring($quote.Index, $quote.Length) -notmatch '^\s*cpp_quote\s*\(' -or
            $QuoteRegionMask.Substring($quote.Index) -notmatch '^[\s;]*$') { continue }
        $prefix = $Mask.Substring(0, $quote.Index)
        if ([regex]::Matches($prefix, '\{').Count -ne [regex]::Matches($prefix, '\}').Count -or
            (Get-IdlConditionalFrame $DirectiveMask $quote.Index) -cne $frame -or
            (Get-IdlConditionalFrame $nativeMask $quote.Index) -cne $nativeFrame) { continue }
        return $quote.Index
    }
}

function Find-CompleteInterfaceParameterRegion([string]$Mask, [string]$DirectiveMask,
    [object[]]$Quotes, [object]$Method, [int]$ParameterOffset, [int]$CandidateOffset = -1) {
    $offset = if ($CandidateOffset -ge 0) { $CandidateOffset } else { $Method.insertionOffset }
    if (!(Get-BraceScopes $Mask.Substring(0, $offset)).balanced) { return }
    $nativeMask = Get-NativeQuoteDirectiveMask $Mask $Quotes
    if ((Get-IdlConditionalFrame $DirectiveMask $ParameterOffset) -cne (Get-IdlConditionalFrame $DirectiveMask $offset) -or
        (Get-IdlConditionalFrame $nativeMask $ParameterOffset) -cne (Get-IdlConditionalFrame $nativeMask $offset)) { return }
    $native = [Text.StringBuilder]::new()
    foreach ($quote in $Quotes) {
        if ($quote.Index -ge $offset) { break }
        if ($Mask.Substring($quote.Index, $quote.Length) -notmatch '^\s*cpp_quote\s*\(') { continue }
        [void]$native.AppendLine([regex]::Replace($quote.Groups['code'].Value, '\\(["\\])', '$1'))
    }
    $nativeCode = Get-CodeMask $native.ToString()
    $nativeCode = [regex]::Replace($nativeCode, '(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*', ' ')
    if (!(Get-BraceScopes $nativeCode).balanced) { return }
    $offset
}

function Write-Patch([string]$Before, [string]$After, [string]$Relative, [string]$Destination) {
    $start = [Diagnostics.ProcessStartInfo]::new('git')
    $start.UseShellExecute = $false
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    foreach ($argument in @('-c', 'core.autocrlf=false', 'diff', '--no-index', '--no-ext-diff', '--no-color', '--', $Before, $After)) {
        $start.ArgumentList.Add($argument)
    }
    $process = [Diagnostics.Process]::Start($start)
    $errorTask = $process.StandardError.ReadToEndAsync()
    $bytes = [IO.MemoryStream]::new()
    $process.StandardOutput.BaseStream.CopyTo($bytes)
    $process.WaitForExit()
    if ($process.ExitCode -ne 1) {
        throw "Expected a nonempty original-IDL diff (exit $($process.ExitCode)): $($errorTask.GetAwaiter().GetResult())"
    }
    $target = $Relative.Replace('\', '/')
    $patch = [Text.Encoding]::Latin1.GetString($bytes.ToArray())
    $patch = [regex]::Replace($patch, '(?m)^diff --git [^\r\n]+', "diff --git a/$target b/$target")
    $patch = [regex]::Replace($patch, '(?m)^--- [^\r\n]+', "--- a/$target")
    $patch = [regex]::Replace($patch, '(?m)^\+\+\+ [^\r\n]+', "+++ b/$target")
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($Destination)) | Out-Null
    [IO.File]::WriteAllBytes($Destination, [Text.Encoding]::Latin1.GetBytes($patch))
    $process.Dispose()
    $bytes.Dispose()
}

function Get-RspValues([string]$Text, [string]$Option) {
    $active = $false
    foreach ($line in [regex]::Split($Text, '\r\n|\n|\r')) {
        $value = $line.Trim().TrimStart([char]0xFEFF)
        if ($value.StartsWith('--', [StringComparison]::Ordinal)) {
            $active = $value -ceq $Option
        }
        elseif ($active -and $value -and !$value.StartsWith('#', [StringComparison]::Ordinal)) {
            $value
        }
    }
}

function Get-TransportMacro([string]$Text, [int]$Offset) {
    $match = [regex]::Match($Text.Substring($Offset), '^_Win32_(?<name>[A-Za-z0-9_]+)_(?<call>\()?', 'Singleline')
    if (!$match.Success) { throw "Invalid metadata macro at offset $Offset" }
    $length = $match.Length
    $arguments = ''
    if ($match.Groups['call'].Success) {
        $open = $Offset + $length - 1
        $depth = 1; $quote = [char]0; $close = -1
        for ($i = $open + 1; $i -lt $Text.Length; $i++) {
            $c = $Text[$i]
            if ($quote -ne [char]0) {
                if ($c -eq '\') { $i++ }
                elseif ($c -eq $quote) { $quote = [char]0 }
            }
            elseif ($c -in @('"', "'")) { $quote = $c }
            elseif ($c -eq '(') { $depth++ }
            elseif ($c -eq ')') {
                $depth--
                if (!$depth) { $close = $i; break }
            }
        }
        if ($close -lt 0) { throw "Unclosed metadata macro at offset $Offset" }
        $arguments = $Text.Substring($open + 1, $close - $open - 1)
        $length = $close - $Offset + 1
    }
    [pscustomobject]@{ name = $match.Groups['name'].Value; arguments = $arguments; length = $length }
}

function Convert-TransportPayload([string]$Macro, [string]$Header) {
    $value = Get-TransportMacro $Macro 0
    if ($value.length -ne $Macro.Length) { throw "Expected exactly one metadata fact: $Macro" }
    if ($value.name.StartsWith('SupportedOS_', [StringComparison]::Ordinal)) {
        $version = $value.name.Substring('SupportedOS_'.Length)
        $definition = [regex]::Match($Header,
            '(?m)^#define _WIN32META_OS_VERSION_' + [regex]::Escape($version) + ' "SupportedOSPlatform\(\\"([^"\\]+)\\"\)"')
        if (!$definition.Success) { throw "Unknown SupportedOS metadata: $Macro" }
        return 'SupportedOSPlatform("' + $definition.Groups[1].Value + '")'
    }
    $name = if ($value.name -ceq 'Retval') { 'RetVal' } else { $value.name }
    if ($name -cnotin @('PreserveResult', 'RetVal', 'Retained', 'Reserved', 'ContainsInteriorPointers',
        'AlsoUsableFor', 'Optional', 'ComOutPtr', 'AssociatedConstant', 'SetLastError', 'ImportLibrary',
        'RAIIFree', 'AssociatedEnum')) { throw "Unsupported original-IDL metadata: $Macro" }
    $arguments = $value.arguments.Trim()
    if ($name -ceq 'AssociatedEnum') { $arguments = $arguments -creplace '^enum\s+', '' }
    if ($name -ceq 'RAIIFree' -and $arguments -cnotmatch '^[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*(?:\s*,\s*-?\d+)*$') {
        throw "RAIIFree requires a native cleanup name and decimal invalids: $Macro"
    }
    if ($name -ceq 'RAIIFree') {
        foreach ($invalid in @(($arguments -split ',') | Select-Object -Skip 1)) {
            $parsed = 0L
            if (![long]::TryParse($invalid.Trim(), [Globalization.NumberStyles]::AllowLeadingSign,
                [Globalization.CultureInfo]::InvariantCulture, [ref]$parsed)) {
                throw "RAIIFree invalid value is outside signed Int64: $Macro"
            }
        }
    }
    if ($arguments) { "$name($arguments)" } else { $name }
}

function New-TransportComment([string]$Kind, [string]$Target, [string]$Payload) {
    if ($Target -cnotmatch '^[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*$' -or $Payload.Contains('*/')) {
        throw "Invalid structured metadata target/payload: $Kind $Target => $Payload"
    }
    $comment = "/* Win32Metadata: $Kind ::$Target => $Payload */"
    'cpp_quote("' + $comment.Replace('\', '\\').Replace('"', '\"') + '")'
}

function Get-TransportTargets([string]$Text) {
    $mask = Get-CodeMask $Text
    $mutable = [Text.StringBuilder]::new($mask)
    foreach ($m in [regex]::Matches($mask, '_Win32_')) {
        $macro = Get-TransportMacro $Text $m.Index
        for ($i = $m.Index; $i -lt $m.Index + $macro.length; $i++) {
            if ($mutable[$i] -notin @("`r", "`n")) { $mutable[$i] = ' ' }
        }
    }
    $mask = $mutable.ToString()
    $mask = [regex]::Replace($mask, '(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*', {
        param($m) [regex]::Replace($m.Value, '[^\r\n]', ' ')
    })
    $records = [Collections.Generic.List[object]]::new()
    foreach ($m in [regex]::Matches($mask,
        '\b(?:(?<kind>interface|struct|class|enum)\s*(?<tag>[A-Za-z_]\w*)?|' +
        'MIDL_INTERFACE\s*\(\s*\)\s*(?<tag>[A-Za-z_]\w*))\s*(?::[^{;]+)?\{')) {
        $open = $m.Index + $m.Length - 1
        $close = Get-ClosingDelimiter $mask $open '{' '}'
        if ($close -lt 0) { throw "Unclosed native declaration at $($m.Index)" }
        $name = $m.Groups['tag'].Value
        $prefix = $mask.Substring([Math]::Max(0, $m.Index - 80), [Math]::Min(80, $m.Index))
        $alias = [regex]::Match($mask.Substring($close + 1), '^\s*(?<name>[A-Za-z_]\w*)\s*[,;]')
        if ($alias.Success -and $prefix -match '\btypedef\s*$') { $name = $alias.Groups['name'].Value }
        $recordStart = $m.Index
        $typedef = [regex]::Match($prefix, '\btypedef\s*$')
        if ($typedef.Success) { $recordStart = $m.Index - ($prefix.Length - $typedef.Index) }
        $recordStart = Get-AttributeStart $mask $recordStart ([Collections.Generic.HashSet[string]]::new())
        $isObject = $m.Groups['kind'].Value -cne 'interface' -or $m.Value.Contains(':') -or
            $mask.Substring($recordStart, $m.Index - $recordStart) -cmatch '\bobject\b'
        $records.Add([pscustomobject]@{
            name = $name; kind = $m.Groups['kind'].Value; start = $recordStart; open = $open; end = $close; isObject = $isObject
        })
    }
    $targets = [Collections.Generic.List[object]]::new()
    foreach ($m in [regex]::Matches($mask, '\b(?<name>[A-Za-z_]\w*)\s*\(')) {
        $name = $m.Groups['name'].Value
        if ($name -cin @('if','for','while','switch','sizeof','catch','annotation','size_is','length_is','iid_is','switch_is','range','id','uuid','helpstring',
            'call_as','cpp_quote','MIDL_INTERFACE','__declspec','__attribute__') -or $name.StartsWith('_')) { continue }
        $open = $m.Index + $m.Length - 1
        $close = Get-ClosingDelimiter $mask $open '(' ')'
        if ($close -lt 0) { continue }
        $tail = [regex]::Match($mask.Substring($close + 1), '^\s*(?:=\s*0\s*)?(?:;|\{)')
        if (!$tail.Success) { continue }
        $owner = @($records | Where-Object { $_.open -lt $m.Index -and $_.end -gt $close } |
            Sort-Object open -Descending | Select-Object -First 1)
        if ($owner.Count -and $owner[0].kind -ceq 'enum') { continue }
        $start = [Math]::Max($mask.LastIndexOf(';', [Math]::Max(0, $m.Index - 1)),
            $mask.LastIndexOf('}', [Math]::Max(0, $m.Index - 1))) + 1
        if ($owner.Count) { $start = [Math]::Max($start, $owner[0].open + 1) }
        $prefix = $mask.Substring($start, $m.Index - $start)
        if ($prefix.Trim() -ceq 'return') { continue }
        if ($prefix -notmatch '[A-Za-z_]\w*\s+$' -and $prefix -notmatch '\)\s*$') { continue }
        $nativeName = $name
        if ($prefix -cmatch '\bpropget\b') { $nativeName = "get_$name" }
        elseif ($prefix -cmatch '\bpropputref\b') { $nativeName = "putref_$name" }
        elseif ($prefix -cmatch '\bpropput\b') { $nativeName = "put_$name" }
        $isMethod = $owner.Count -and $owner[0].isObject
        $qualified = if ($isMethod -and $owner[0].name) { "$($owner[0].name)::$nativeName" } else { $nativeName }
        $kind = if ($isMethod) { 'method' } else { 'function' }
        $insertion = if ($owner.Count) { $owner[0].start } else { $start }
        $trailingInsertion = $insertion
        if ($owner.Count) {
            $trailingInsertion = $owner[0].end + 1
            $semicolon = [regex]::Match($Text.Substring($trailingInsertion), '^[ \t]*;')
            $trailingInsertion += $semicolon.Length
        }
        $targets.Add([pscustomobject]@{ kind = $kind; name = $qualified; start = $start; end = $close + 1 + $tail.Length
            insertion = $insertion; trailingInsertion = $trailingInsertion; nativeName = $name })
        $round = 0; $square = 0; $parameterStart = $open + 1
        for ($i = $parameterStart; $i -le $close; $i++) {
            $c = $mask[$i]
            if ($i -eq $close -or ($c -eq ',' -and !$round -and !$square)) {
                $part = $mask.Substring($parameterStart, $i - $parameterStart)
                $parameter = [regex]::Match($part, '(?<name>[A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$')
                if ($parameter.Success -and $parameter.Groups['name'].Value -cne 'void') {
                    $targets.Add([pscustomobject]@{ kind = 'parameter'
                        name = "$qualified::$($parameter.Groups['name'].Value)"
                        start = $parameterStart; end = $i; insertion = $insertion; trailingInsertion = $trailingInsertion
                        nativeName = $parameter.Groups['name'].Value })
                }
                $parameterStart = $i + 1
                continue
            }
            if ($c -eq '(') { $round++ }; if ($c -eq ')') { $round-- }
            if ($c -eq '[') { $square++ }; if ($c -eq ']') { $square-- }
        }
    }
    foreach ($record in $records) {
        if (!$record.name -or $record.kind -ceq 'enum') { continue }
        $start = $record.open + 1; $depth = 0
        for ($i = $start; $i -lt $record.end; $i++) {
            if ($mask[$i] -eq '{') { $depth++ }
            elseif ($mask[$i] -eq '}') { $depth-- }
            elseif ($mask[$i] -eq ';' -and !$depth) {
                $part = $mask.Substring($start, $i - $start)
                if ($part -notmatch '\)\s*(?:=\s*0\s*)?$') {
                    $field = [regex]::Match($part, '(?<name>[A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*$')
                    if ($field.Success) {
                        $targets.Add([pscustomobject]@{ kind = 'field'; name = "$($record.name)::$($field.Groups['name'].Value)"
                            start = $start; end = $i; insertion = $record.start
                            trailingInsertion = $record.end + 1 + [regex]::Match($Text.Substring($record.end + 1), '^[ \t]*;').Length
                            nativeName = $field.Groups['name'].Value })
                    }
                }
                $start = $i + 1
            }
        }
    }
    @($targets)
}

function Convert-IdlMetadataTransport([string]$Text, [string]$Pristine, [string]$Header) {
    $newline = [regex]::Match($Text, '\r\n|\n|\r').Value
    if (!$newline) { $newline = "`r`n" }
    $edits = [Collections.Generic.List[object]]::new()
    $comments = [Collections.Generic.List[object]]::new()
    $mask = Get-CodeMask $Text
    $carrierPattern = '(?m)^[ \t]*_Win32_Annotate(?<kind>Interface|Method|Parameter|Field)_\('
    foreach ($m in [regex]::Matches($Text, $carrierPattern)) {
        $offset = $Text.IndexOf('_Win32_', $m.Index)
        if ($mask.Substring($offset, '_Win32_'.Length) -cne '_Win32_') { continue }
        $macro = Get-TransportMacro $Text $offset
        $args = $macro.arguments
        $parts = [regex]::Match($args, '^\s*(?<target>[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*,\s*(?:(?<parameter>[A-Za-z_]\w*)\s*,\s*)?(?<macro>_Win32_.+)\s*$', 'Singleline')
        if (!$parts.Success) { throw "Invalid synthetic carrier at $offset" }
        $kind = $m.Groups['kind'].Value.ToLowerInvariant()
        $target = $parts.Groups['target'].Value
        if ($kind -ceq 'parameter') { $target += '::' + $parts.Groups['parameter'].Value }
        $payload = Convert-TransportPayload $parts.Groups['macro'].Value.Trim() $Header
        if ($kind -ceq 'method' -and $payload -match '^(?:AssociatedEnum|RAIIFree)\(') { $kind = 'return' }
        $comment = New-TransportComment $kind $target $payload
        $edits.Add([pscustomobject]@{ offset = $offset; length = $macro.length; text = $comment })
    }
    $quotes = @([regex]::Matches($Text,
        '(?m)^[ \t]*(?:cpp_quote\s*\(\s*|#pragma\s+midl_echo\s*\(\s*)"(?<code>(?:\\.|[^"\\\r\n])*)"\s*\)') |
        Where-Object { $mask.Substring($_.Index, $_.Length) -match '^\s*(?:cpp_quote|#pragma)' })
    $nativeDirectives = Get-NativeQuoteDirectiveMask $mask $quotes
    $annotations = @([regex]::Matches($Text, '\bannotation\s*\(\s*"(?<value>(?:\\.|[^"\\])*)"\s*\)') |
        Where-Object { $mask.Substring($_.Index, 'annotation'.Length) -ceq 'annotation' -and
            $_.Groups['value'].Value -match '_Win32_' })
    $targets = if ($annotations.Count) { @(Get-TransportTargets $Text) } else { @() }
    $originalTargets = if ($annotations.Count) { @(Get-TransportTargets $Pristine) } else { @() }
    foreach ($annotation in $annotations) {
        $target = @($targets | Where-Object { $_.start -le $annotation.Index -and $_.end -gt $annotation.Index } |
            Sort-Object @{ Expression = { $_.end - $_.start } } | Select-Object -First 1)
        if ($target.Count -ne 1) { throw "No native target for metadata annotation at $($annotation.Index)" }
        $target = $target[0]
        $insertion = $target.insertion
        $frame = Get-IdlConditionalFrame $mask $annotation.Index
        $nativeFrame = Get-IdlConditionalFrame $nativeDirectives $annotation.Index
        if ($frame -cne (Get-IdlConditionalFrame $mask $insertion) -or
            $nativeFrame -cne (Get-IdlConditionalFrame $nativeDirectives $insertion)) {
            $insertion = $target.trailingInsertion
        }
        if ($frame -cne (Get-IdlConditionalFrame $mask $insertion)) {
            throw "Metadata placement would cross a native conditional for $($target.name)"
        }
        if ($nativeFrame -cne (Get-IdlConditionalFrame $nativeDirectives $insertion)) {
            throw "Metadata placement would cross a quoted native conditional for $($target.name)"
        }
        $targetName = $target.name
        if ($target.kind -ceq 'field') {
            $recordName = ($target.name -split '::')[0]
            $emptyTag = [regex]::IsMatch($Text, '(?m)^\s*cpp_quote\("#define ' +
                [regex]::Escape($recordName) + '\s*"\)')
            if ($emptyTag) {
                $aliases = @([regex]::Matches($Pristine,
                    '\btypedef\s+struct\s+' + [regex]::Escape($recordName) + '\s+(?<alias>[A-Za-z_]\w*)\s*;'))
                if ($aliases.Count -ne 1) { throw "Erased native record tag requires one original typedef: $recordName" }
                $targetName = $aliases[0].Groups['alias'].Value + '::' + $target.nativeName
            }
        }
        foreach ($m in [regex]::Matches($annotation.Groups['value'].Value, '_Win32_')) {
            $macro = Get-TransportMacro $annotation.Groups['value'].Value $m.Index
            $payload = Convert-TransportPayload $annotation.Groups['value'].Value.Substring($m.Index, $macro.length) $Header
            $comments.Add([pscustomobject]@{ offset = $insertion
                text = New-TransportComment $target.kind $targetName $payload })
        }
        $native = @($originalTargets | Where-Object { $_.name -ceq $target.name -and $_.kind -ceq $target.kind })
        if ($native.Count -ne 1) { throw "Expected one pristine native target for $($target.name), found $($native.Count)" }
        $originalDeclaration = $Pristine.Substring($native[0].start, $native[0].end - $native[0].start)
        $originalAnnotations = @([regex]::Matches($originalDeclaration, '\bannotation\s*\(\s*"(?:\\.|[^"\\])*"\s*\)'))
        $replacement = if ($originalAnnotations.Count -eq 1) { $originalAnnotations[0].Value }
            elseif (!$originalAnnotations.Count) { '' } else { throw "Ambiguous pristine SAL for $($target.name)" }
        $start = $annotation.Index; $length = $annotation.Length
        if (!$replacement) {
            $before = $Text.Substring(0, $start)
            $after = $Text.Substring($start + $length)
            if ($before -match '\[\s*$' -and $after -match '^\s*\]') {
                $open = [regex]::Match($before, '\[\s*$')
                $close = [regex]::Match($after, '^\s*\][ \t]*')
                $start = $open.Index; $length += $annotation.Index - $start + $close.Length
            }
            elseif ($before -match ',\s*$') {
                $comma = [regex]::Match($before, ',\s*$')
                $start = $comma.Index; $length += $annotation.Index - $start
            }
            elseif ($after -match '^\s*,[ \t]*') {
                $length += [regex]::Match($after, '^\s*,[ \t]*').Length
            }
            else { throw "Cannot remove metadata-only IDL annotation at $start" }
            $lineStart = $Text.LastIndexOf("`n", [Math]::Max(0, $start - 1)) + 1
            $lineEnd = $Text.IndexOf("`n", $start + $length)
            if ($lineEnd -lt 0) { $lineEnd = $Text.Length }
            if ($Text.Substring($lineStart, $start - $lineStart) -match '^[ \t]*$' -and
                $Text.Substring($start + $length, $lineEnd - $start - $length) -match '^[ \t\r]*$') {
                $start = $lineStart
                $length = [Math]::Min($Text.Length, $lineEnd + 1) - $lineStart
            }
        }
        $edits.Add([pscustomobject]@{ offset = $start; length = $length; text = $replacement })
    }
    foreach ($group in @($comments | Group-Object offset)) {
        $offset = [int]$group.Name
        $prefix = $Text.Substring(0, $offset)
        $line = $prefix.LastIndexOf("`n") + 1
        if ($prefix.Substring($line) -match '^\s*$') { $offset = $line }
        if ($Text.Substring($offset) -match '^\r?\n') {
            $offset += [regex]::Match($Text.Substring($offset), '^\r?\n').Length
        }
        $separator = if ($offset -gt 0 -and $Text[$offset - 1] -notin @("`r", "`n")) { $newline } else { '' }
        $edits.Add([pscustomobject]@{ offset = $offset; length = 0
            text = $separator + (($group.Group | ForEach-Object text) -join $newline) + $newline })
    }
    $projection = [Text.StringBuilder]::new()
    $quoteRanges = [Collections.Generic.List[object]]::new()
    foreach ($quote in $quotes) {
        $code = [regex]::Replace($quote.Groups['code'].Value, '\\(["\\])', '$1')
        $quoteRanges.Add([pscustomobject]@{ quote = $quote; start = $projection.Length; end = $projection.Length + $code.Length; code = $code })
        [void]$projection.Append($code).Append("`n")
    }
    $projected = $projection.ToString()
    $hasQuotedMetadata = @($quoteRanges | Where-Object { $_.code -match '_Win32_' -and
        $_.code -notmatch '^\s*_Win32_(?:FlagsEnum|Enum)_\(' }).Count -gt 0
    $quotedTargets = if ($hasQuotedMetadata) { @(Get-TransportTargets $projected) } else { @() }
    foreach ($range in $quoteRanges) {
        $code = $range.code
        $codeMask = Get-CodeMask $code
        if ($code -match '^\s*_Win32_(?:FlagsEnum|Enum)_\(') { continue }
        $quotedCarrier = [regex]::Match($code, '^\s*_Win32_Annotate(?<kind>Interface|Method|Parameter|Field)_\(')
        if ($quotedCarrier.Success) {
            $macro = Get-TransportMacro $code $code.IndexOf('_Win32_')
            $parts = [regex]::Match($macro.arguments, '^\s*(?<target>[A-Za-z_]\w*(?:::[A-Za-z_]\w*)*)\s*,\s*(?:(?<parameter>[A-Za-z_]\w*)\s*,\s*)?(?<macro>_Win32_.+)\s*$', 'Singleline')
            if (!$parts.Success) { throw "Invalid quoted synthetic carrier: $code" }
            $kind = $quotedCarrier.Groups['kind'].Value.ToLowerInvariant()
            $target = $parts.Groups['target'].Value
            if ($kind -ceq 'parameter') { $target += '::' + $parts.Groups['parameter'].Value }
            $payload = Convert-TransportPayload $parts.Groups['macro'].Value.Trim() $Header
            if ($kind -ceq 'method' -and $payload -match '^(?:AssociatedEnum|RAIIFree)\(') { $kind = 'return' }
            $quoted = $range.quote
            $edits.Add([pscustomobject]@{ offset = $quoted.Index; length = $quoted.Length
                text = New-TransportComment $kind $target $payload })
            continue
        }
        $changes = [Collections.Generic.List[object]]::new()
        $facts = [Collections.Generic.List[string]]::new()
        foreach ($m in [regex]::Matches($codeMask, '_Win32_')) {
            $macro = Get-TransportMacro $code $m.Index
            if ($macro.name -cin @('Enum', 'FlagsEnum')) { continue }
            $offset = $range.start + $m.Index
            $target = @($quotedTargets | Where-Object { $_.start -le $offset -and $_.end -gt $offset } |
                Sort-Object @{ Expression = { $_.end - $_.start } } | Select-Object -First 1)
            if ($target.Count -ne 1) { throw "No quoted native target for $($macro.name) at $offset" }
            $target = $target[0]
            $kind = $target.kind
            if ($kind -cin @('function', 'method') -and $macro.name -cin @('AssociatedEnum', 'RAIIFree')) { $kind = 'return' }
            $payload = Convert-TransportPayload $code.Substring($m.Index, $macro.length) $Header
            $facts.Add((New-TransportComment $kind $target.name $payload))
            $offset = $m.Index; $length = $macro.length
            if ($offset + $length -lt $code.Length -and $code[$offset + $length] -eq ' ') { $length++ }
            elseif ($offset -gt 0 -and $code[$offset - 1] -eq ' ' -and
                $offset + $length -lt $code.Length -and $code[$offset + $length] -eq ';') {
                $offset--; $length++
            }
            $changes.Add([pscustomobject]@{ offset = $offset; length = $length })
        }
        if (!$changes.Count) { continue }
        foreach ($change in @($changes | Sort-Object offset -Descending)) {
            $code = $code.Remove($change.offset, $change.length)
        }
        $quoted = $range.quote
        $edits.Add([pscustomobject]@{ offset = $quoted.Groups['code'].Index
            length = $quoted.Groups['code'].Length; text = $code.Replace('\', '\\').Replace('"', '\"') })
        $edits.Add([pscustomobject]@{ offset = $quoted.Index + $quoted.Length; length = 0
            text = $newline + ($facts -join $newline) })
    }
    $after = $Text
    foreach ($edit in @($edits | Sort-Object offset -Descending -Stable)) {
        $after = $after.Remove($edit.offset, $edit.length).Insert($edit.offset, $edit.text)
    }
    $after
}

if ($PSCmdlet.ParameterSetName -eq 'Transport') {
    if ([IO.Path]::GetExtension($PatchedIdl) -notin @('.idl', '.odl') -or
        [IO.Path]::GetExtension($PristineIdl) -notin @('.idl', '.odl')) {
        throw 'Transport conversion requires original IDL inputs, not generated headers.'
    }
    if (Test-Path -LiteralPath $TransportOutput) {
        throw "Transport output must be a new private file: $TransportOutput"
    }
    $before = [IO.File]::ReadAllBytes([IO.Path]::GetFullPath($PatchedIdl))
    $originalBytes = [IO.File]::ReadAllBytes([IO.Path]::GetFullPath($PristineIdl))
    foreach ($bytes in @($before, $originalBytes)) {
        if ($bytes -contains 0 -or ($bytes.Length -ge 2 -and
            (($bytes[0] -eq 255 -and $bytes[1] -eq 254) -or ($bytes[0] -eq 254 -and $bytes[1] -eq 255)))) {
            throw 'UTF-16/NUL IDL requires an explicit encoding-aware owner review.'
        }
    }
    $converted = Convert-IdlMetadataTransport ([Text.Encoding]::Latin1.GetString($before)) `
        ([Text.Encoding]::Latin1.GetString($originalBytes)) ([IO.File]::ReadAllText($AnnotationHeader))
    [IO.File]::WriteAllBytes([IO.Path]::GetFullPath($TransportOutput), [Text.Encoding]::Latin1.GetBytes($converted))
    return
}

$map = Get-Content -LiteralPath $InputMap -Raw | ConvertFrom-Json
if ($map.schemaVersion -ne 1 -or $null -eq $map.PSObject.Properties['owners']) {
    throw 'Expected schema 1 with an explicit reserved owners array.'
}
$owners = @($map.owners | Where-Object { !$Original -or $_.original -in $Original })
if (!$owners.Count -or ($Original -and @($Original | Where-Object { $_ -notin $owners.original }).Count)) {
    throw 'The requested original IDL owners must all exist in the reserved input map.'
}
if (@($owners.original | Sort-Object -Unique).Count -ne $owners.Count) {
    throw 'An original IDL may occur only once in a batch.'
}
$macros = @{}
$annotationText = [IO.File]::ReadAllText([IO.Path]::GetFullPath($AnnotationHeader))
foreach ($match in [regex]::Matches($annotationText, '(?m)^#define _WIN32META_OS_VERSION_(\w+) "SupportedOSPlatform\(\\"([^"\\]+)\\"\)"')) {
    $macro = "_Win32_SupportedOS_$($match.Groups[1].Value)_"
    if ($annotationText -notmatch "(?m)^#define $([regex]::Escape($macro)) ") {
        throw "The canonical OS payload has no public macro: $macro"
    }
    $macros[$match.Groups[2].Value] = $macro
}
if (!$macros.Count) { throw 'No canonical public SupportedOS vocabulary was found.' }
$parameterMacros = @{}
foreach ($name in @('Optional', 'ComOutPtr')) {
    $parameterMacros[$name] = [regex]::IsMatch($annotationText, "(?m)^#define _Win32_${name}_\(")
}
$globalSettings = Join-Path $SdkProjectRoot 'scraper.settings.rsp'
$enumRemaps = @(if (Test-Path -LiteralPath $globalSettings -PathType Leaf) {
    Get-RspValues ([IO.File]::ReadAllText($globalSettings)) '--remap'
})

$results = [Collections.Generic.List[object]]::new()
$plans = [Collections.Generic.List[object]]::new()
foreach ($owner in $owners) {
    $relative = $owner.original.Replace('/', '\')
    $path = Resolve-Input $relative
    $bytes = [IO.File]::ReadAllBytes($path)
    if ($null -ne $owner.PSObject.Properties['sourceSha256'] -and $owner.sourceSha256 -cne (Get-Hash $bytes)) {
        throw "Original IDL preimage mismatch: $relative"
    }
    if (($bytes.Length -ge 2 -and $bytes[0] -eq 255 -and $bytes[1] -eq 254) -or
        ($bytes.Length -ge 2 -and $bytes[0] -eq 254 -and $bytes[1] -eq 255) -or $bytes -contains 0) {
        throw "UTF-16/NUL IDL requires an explicit encoding-aware owner review: $relative"
    }
    $text = [Text.Encoding]::Latin1.GetString($bytes)
    $bom = if ($bytes.Length -ge 3 -and $bytes[0] -eq 239 -and $bytes[1] -eq 187 -and $bytes[2] -eq 191) { 3 } else { 0 }
    $mask = (' ' * $bom) + (Get-CodeMask $text.Substring($bom))
    $macroDefinitions = [Collections.Generic.Dictionary[string, bool]]::new([StringComparer]::Ordinal)
    foreach ($definition in [regex]::Matches($mask,
        '(?m)^[ \t]*#[ \t]*define[ \t]+(?<name>[A-Za-z_]\w*)(?<parameters>\([^\r\n)]*\))?(?<body>(?:[^\r\n]*\\\r?\n)*[^\r\n]*)')) {
        $name = $definition.Groups['name'].Value
        $body = $definition.Groups['body'].Value -replace '\\\r?\n', ''
        if (!$macroDefinitions.ContainsKey($name)) { $macroDefinitions.Add($name, $true) }
        $macroDefinitions[$name] = $macroDefinitions[$name] -and $definition.Groups['parameters'].Success -and
            [regex]::IsMatch($body, '^\s*\[.*\]\s*$', 'Singleline')
    }
    $attributeMacros = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($name in $macroDefinitions.Keys) {
        if ($macroDefinitions[$name]) {
            $attributeMacros.Add($name) | Out-Null
        }
    }
    $directiveMask = $mask
    # Directives are declaration boundaries, not whitespace before an attribute list.
    $mask = [regex]::Replace($mask, '(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*', {
        param($match)
        [regex]::Replace($match.Value, '[^\r\n]', ';')
    })
    $definitions = @([regex]::Matches($mask, '\binterface\s+(?<name>[A-Za-z_]\w*)\s*:\s*[A-Za-z_]\w*(?:\s*::\s*[A-Za-z_]\w*)*\s*\{'))
    $quotes = @([regex]::Matches($text, '(?m)^[ \t]*cpp_quote\s*\(\s*"(?<code>(?:\\.|[^"\\\r\n])*)"\s*\)'))
    $quoteRegionMask = [regex]::Replace($mask, '(?m)^[ \t]*cpp_quote\s*\([ \t]*\)', {
        param($match)
        ' ' * $match.Length
    })
    $insertions = [Collections.Generic.List[object]]::new()
    $dispositions = [Collections.Generic.List[object]]::new()
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $newline = [regex]::Match($text, '\r\n|\n|\r').Value
    if (!$newline) { $newline = "`r`n" }
    foreach ($fact in @($owner.facts)) {
        if (!$seen.Add("$($fact.category)|$($fact.symbol)")) {
            throw "Duplicate fact identity in $relative`: $($fact.category)/$($fact.symbol)"
        }
        $payload = [regex]::Match($fact.value, '^([A-Za-z_]\w*)=SupportedOSPlatform\("([^"]+)"\)$')
        $declarations = @($definitions | Where-Object { $_.Groups['name'].Value -ceq $fact.symbol })
        $functions = @(Find-QuotedFunction $text $mask $quotes $fact.symbol)
        $reason = $null
        $parameterOverride = if ($AllowCompleteInterfaceParameterCarriers) { Get-ParameterOverride $fact }
        if ($parameterOverride) {
            $parts = $fact.symbol -split '::'
            $targets = @(Find-AssociationTarget $text $mask $quotes $definitions $fact.symbol)
            if ($parts.Count -eq 2) {
                $targets += @(foreach ($parameter in @(Find-IdlMethod $text $mask $definitions "$($parts[0])::*::$($parts[1])")) {
                    $parameter | Add-Member NoteProperty kind 'ParmVarDecl'
                    $parameter | Add-Member NoteProperty sourceForm 'native-idl-field-or-interface-parameter'
                    $parameter | Add-Member NoteProperty nativeQualifiedName "$($parameter.methodQualifiedName)::$($parts[1])"
                    $parameter
                })
            }
            if (!$parameterMacros[$parameterOverride.name]) {
                $reason = 'parameter-override-not-in-selected-annotation-vocabulary'
            }
            elseif ($targets.Count -ne 1 -or $targets[0].kind -cne 'ParmVarDecl') {
                $reason = "requires-one-original-native-parameter-found-$($targets.Count)"
            }
            elseif ($targets[0].sourceForm -cne 'quoted-native-function-parameter' -and $targets[0].isProperty) {
                $reason = 'requires-actual-native-property-method-identity'
            }
            $nativeParts = if (!$reason) { $targets[0].nativeQualifiedName -split '::' }
            $methods = @(if (!$reason -and $nativeParts.Count -eq 3) {
                Find-IdlMethod $text $mask $definitions ($nativeParts[0..1] -join '::')
            })
            if (!$reason -and $nativeParts.Count -eq 3 -and $methods.Count -ne 1) {
                $reason = "requires-one-original-interface-method-found-$($methods.Count)"
            }
            $carrierOffset = if (!$reason -and $nativeParts.Count -eq 3) {
                Find-ExistingTrailingQuoteRegion $mask $directiveMask $quoteRegionMask $quotes $methods[0]
            }
            if (!$reason -and $null -ne $carrierOffset) {
                $carrierOffset = Find-CompleteInterfaceParameterRegion $mask $directiveMask $quotes $methods[0] $targets[0].offset $carrierOffset
            }
            $newCarrierRegion = $false
            if (!$reason -and $nativeParts.Count -eq 3 -and $null -eq $carrierOffset) {
                $carrierOffset = Find-CompleteInterfaceParameterRegion $mask $directiveMask $quotes $methods[0] $targets[0].offset
                $newCarrierRegion = $null -ne $carrierOffset
            }
            if (!$reason -and $nativeParts.Count -eq 3 -and $null -eq $carrierOffset) {
                $reason = 'requires-complete-interface-parameter-carrier-in-matching-global-conditional-scope'
            }
            if ($reason) {
                $dispositions.Add([ordered]@{ fact = $fact; disposition = 'retained-legacy'; reason = $reason })
                continue
            }
            $target = $targets[0]
            $macro = $parameterOverride.macro
            $insertion = if ($target.sourceForm -ceq 'quoted-native-function-parameter') {
                [pscustomobject]@{ offset = $target.insertionOffset; text = "$macro " }
            }
            else {
                [pscustomobject]@{
                    offset = $carrierOffset
                    text = $(if ($newCarrierRegion -and $methods[0].needsNewline) { $newline }) +
                        "_Win32_AnnotateParameter_($($nativeParts[0..1] -join '::'), $($nativeParts[2]), $macro)$newline"
                }
            }
            $insertions.Add($insertion)
            $dispositions.Add([ordered]@{
                fact = $fact; disposition = 'authored-original-idl'; macro = $macro
                declaration = [ordered]@{
                    name = $parts[-1]; qualifiedName = $fact.symbol; nativeQualifiedName = $target.nativeQualifiedName
                    kind = 'ParmVarDecl'; sourceForm = $target.sourceForm; file = $relative
                    line = 1 + [regex]::Matches($text.Substring(0, $target.offset), '\n').Count
                    offset = $target.offset; start = $target.start; end = $target.end
                    isDefinition = $false; sourceSha256 = Get-Hash $bytes
                }
            })
            continue
        }
        if ($fact.category -ceq 'associated-enum-use') {
            $association = [regex]::Match($fact.value,
                '^([^=]+)=\[AssociatedEnum\("(?<enum>[A-Za-z_]\w*)"\)\]$')
            $parts = $fact.symbol -split '::'
            $targets = @(if ($parts.Count -eq 2) { Find-IdlField $text $mask $fact.symbol }
                elseif ($parts.Count -eq 3) { Find-IdlMethod $text $mask $definitions $fact.symbol })
            if (!$association.Success -or $association.Groups[1].Value -cne $fact.symbol) {
                $reason = 'unsupported-or-inconsistent-associated-enum-payload'
            }
            elseif ($targets.Count -ne 1) { $reason = "requires-one-original-field-or-method-parameter-found-$($targets.Count)" }
            elseif ($targets[0].annotationCount -gt 1) {
                $reason = "requires-one-existing-native-annotation-found-$($targets[0].annotationCount)"
            }
            $enumName = $association.Groups['enum'].Value
            $generatedTagPattern = '^(__MIDL___MIDL_itf_' +
                [regex]::Escape([IO.Path]::GetFileNameWithoutExtension($relative)) +
                '_[0-9_]+)=' + [regex]::Escape($enumName) + '$'
            $generatedTags = @($enumRemaps | ForEach-Object {
                $match = [regex]::Match($_, $generatedTagPattern)
                if ($match.Success) { $match.Groups[1].Value }
            })
            if ($generatedTags.Count -gt 1) { $reason = 'ambiguous-existing-same-original-generated-enum-remaps' }
            if ($reason) {
                $dispositions.Add([ordered]@{ fact = $fact; disposition = 'retained-legacy'; reason = $reason })
                continue
            }
            $target = $targets[0]
            $enumType = if ($generatedTags.Count -eq 1) { "enum $($generatedTags[0])" } else { $enumName }
            $macro = "_Win32_AssociatedEnum_($enumType)"
            $annotation = if ($target.appendToAnnotation) { " $macro" } else { "[annotation(`"$macro`")] " }
            $insertions.Add([pscustomobject]@{ offset = $target.insertionOffset; text = $annotation })
            $dispositions.Add([ordered]@{
                fact = $fact; disposition = 'authored-original-idl'; macro = $macro
                declaration = [ordered]@{
                    name = $parts[-1]; qualifiedName = $fact.symbol
                    kind = if ($parts.Count -eq 2) { 'FieldDecl' } else { 'ParmVarDecl' }
                    sourceForm = 'native-idl-field-or-interface-parameter'; file = $relative
                    nativeQualifiedName = if ($parts.Count -eq 2) { $target.nativeQualifiedName } else { $fact.symbol }
                    enumNativeType = $enumType
                    line = 1 + [regex]::Matches($text.Substring(0, $target.offset), '\n').Count
                    offset = $target.offset; start = $target.start; end = $target.end
                    isDefinition = $false; sourceSha256 = Get-Hash $bytes
                }
            })
            continue
        }
        $methodAnnotation = if ($fact.category -ceq 'declaration-attribute-override' -and
            $fact.value -ceq "$($fact.symbol)=[RetVal]") { '_Win32_Retval_' }
        elseif ($fact.category -ceq 'declaration-attribute-override' -and
            $fact.value -cin @("$($fact.symbol)=[CanReturnMultipleSuccessValues]", "$($fact.symbol)=[CanReturnErrorsAsSuccess]")) {
            '_Win32_PreserveResult_'
        }
        if ($methodAnnotation) {
            $parts = $fact.symbol -split '::'
            $expectedParts = if ($methodAnnotation -ceq '_Win32_Retval_') { 3 } else { 2 }
            $methods = @(Find-IdlMethod $text $mask $definitions $fact.symbol)
            if ($parts.Count -ne $expectedParts -or $methods.Count -ne 1) {
                $dispositions.Add([ordered]@{
                    fact = $fact; disposition = 'retained-legacy'
                    reason = "requires-one-original-interface-method-or-parameter-found-$($methods.Count)"
                })
                continue
            }
            $method = $methods[0]
            if ($method.nativeRetval) {
                $dispositions.Add([ordered]@{
                    fact = $fact; disposition = 'retained-legacy'
                    reason = 'native-retval-already-present-no-new-source-conversion-credit'
                })
                continue
            }
            if ($expectedParts -eq 3 -and $method.annotationCount -gt 1) {
                $dispositions.Add([ordered]@{
                    fact = $fact; disposition = 'retained-legacy'
                    reason = "requires-one-existing-native-parameter-annotation-found-$($method.annotationCount)"
                })
                continue
            }
            $annotation = if ($expectedParts -eq 3) {
                    if ($method.appendToAnnotation) { " $methodAnnotation" } else { "[annotation(`"$methodAnnotation`")] " }
                }
                else {
                    $(if ($method.needsNewline) { $newline }) +
                        "_Win32_AnnotateMethod_($($fact.symbol), $methodAnnotation)$newline"
                }
            $insertions.Add([pscustomobject]@{ offset = $method.insertionOffset; text = $annotation })
            $dispositions.Add([ordered]@{
                fact = $fact; disposition = 'authored-original-idl'; macro = $methodAnnotation
                declaration = [ordered]@{
                    name = $parts[-1]; qualifiedName = $fact.symbol
                    kind = if ($expectedParts -eq 3) { 'ParmVarDecl' } else { 'CXXMethodDecl' }
                    sourceForm = 'native-idl-interface-member'; file = $relative
                    line = 1 + [regex]::Matches($text.Substring(0, $method.offset), '\n').Count
                    offset = $method.offset; start = $method.start; end = $method.end
                    isDefinition = $false; sourceSha256 = Get-Hash $bytes
                }
            })
            continue
        }
        $macro = $null
        if ($fact.category -ceq 'setLastError' -and $fact.value -ceq $fact.symbol -and
            $functions.Count -eq 1 -and !$declarations.Count) { $macro = '_Win32_SetLastError_' }
        elseif ($fact.category -ne 'supportedOS') { $reason = 'not-an-interface-SupportedOS-fact-native-function-or-method-review-required' }
        elseif (!$payload.Success -or $payload.Groups[1].Value -cne $fact.symbol) { $reason = 'unsupported-or-inconsistent-authored-payload' }
        elseif (!$macros.ContainsKey($payload.Groups[2].Value)) { $reason = 'payload-not-in-reviewed-public-OS-vocabulary' }
        elseif ($declarations.Count + $functions.Count -ne 1) { $reason = "requires-one-original-interface-or-quoted-function-found-$($declarations.Count + $functions.Count)" }
        elseif ($declarations.Count -and $text -match "_Win32_AnnotateInterface_\s*\(\s*$([regex]::Escape($fact.symbol))\s*,") { $reason = 'existing-interface-carrier-requires-cumulative-review' }
        if ($reason) {
            $dispositions.Add([ordered]@{ fact = $fact; disposition = 'retained-legacy'; reason = $reason })
            continue
        }
        if (!$macro) { $macro = $macros[$payload.Groups[2].Value] }
        if ($functions.Count) {
            $function = $functions[0]
            $insertion = $null
            foreach ($candidate in @(
                [pscustomobject]@{ offset = $function.offset; text = "$macro "; placement = 'before-function-name' },
                [pscustomobject]@{ offset = $function.afterParametersOffset; text = " $macro"; placement = 'after-parameter-list' }
            )) {
                $lineEnd = $text.IndexOf("`n", $candidate.offset)
                if ($lineEnd -lt 0) { $lineEnd = $text.Length }
                if ($text.Substring($candidate.offset, $lineEnd - $candidate.offset).TrimEnd("`r") -match '[ \t]$') { continue }
                $insertion = $candidate
                break
            }
            if (!$insertion) {
                $dispositions.Add([ordered]@{
                    fact = $fact; disposition = 'retained-legacy'
                    reason = 'native-prototype-insertion-lines-have-existing-trailing-whitespace-strict-text-patch-review-required'
                })
                continue
            }
            $insertions.Add($insertion)
            $dispositions.Add([ordered]@{
                fact = $fact; disposition = 'authored-original-idl'; macro = $macro
                declaration = [ordered]@{
                    name = $fact.symbol; qualifiedName = $fact.symbol; kind = 'FunctionDecl'
                    sourceForm = 'cpp_quote-prototype'; file = $relative
                    annotationPlacement = $insertion.placement
                    line = 1 + [regex]::Matches($text.Substring(0, $function.offset), '\n').Count
                    offset = $function.offset; start = $function.start; end = $function.end
                    isDefinition = $false; sourceSha256 = Get-Hash $bytes
                }
            })
            continue
        }
        $definition = $declarations[0]
        $offset = Get-AttributeStart $mask $definition.Index $attributeMacros
        $prefix = if ($offset -gt 0 -and $text[$offset - 1] -notin @("`n", "`r")) { $newline } else { '' }
        $insertions.Add([pscustomobject]@{ offset = $offset; text = "${prefix}_Win32_AnnotateInterface_($($fact.symbol), $macro)$newline" })
        $dispositions.Add([ordered]@{
            fact = $fact; disposition = 'authored-original-idl'; macro = $macro
            declaration = [ordered]@{
                name = $fact.symbol; qualifiedName = $fact.symbol; kind = 'InterfaceDecl'; file = $relative
                line = 1 + [regex]::Matches($text.Substring(0, $definition.Index), '\n').Count
                offset = $definition.Index; start = $offset; end = $definition.Index + $definition.Length
                isDefinition = $true; sourceSha256 = Get-Hash $bytes
            }
        })
    }
    if ($insertions.Count) {
        $first = [regex]::Match($mask.Substring($bom), '\S')
        if (!$first.Success) { throw "An admitted IDL has no source tokens: $relative" }
        $bootstrap = $first.Index + $bom
        $line = $text.LastIndexOf("`n", [Math]::Max(0, $bootstrap - 1)) + 1
        if ($line -lt $bom) { $line = $bom }
        $hasIdlSal = $text.Substring($line) -match '^#\s*include\s*[<"]sal\.h[>"]'
        if ($SharedSalBootstrap) {
            $hasIdlSal = @([regex]::Matches($text.Substring($bom), '(?m)^[ \t]*#\s*include\s*[<"]sal\.h[>"]') |
                Where-Object { $directiveMask.Substring($bom + $_.Index, $_.Length) -match '^[ \t]*#' }).Count -gt 0
        }
        $bootstrapText = if (!$hasIdlSal) { "#include <sal.h>$newline" } else { '' }
        if ($SharedSalBootstrap -and !@($quotes | Where-Object {
            $mask.Substring($_.Index, $_.Length) -match '^\s*cpp_quote\s*\(' -and
                [regex]::Replace($_.Groups['code'].Value, '\\(["\\])', '$1') -match '^\s*#\s*include\s*[<"]sal\.h[>"]\s*$'
        }).Count) {
            $bootstrapText += "cpp_quote(`"#include <sal.h>`")$newline"
        }
        if ($bootstrapText) {
            $insertions.Add([pscustomobject]@{ offset = $line; text = $bootstrapText })
        }
    }
    $after = $text
    foreach ($insertion in @($insertions | Sort-Object offset -Descending -Stable)) {
        $after = $after.Insert($insertion.offset, $insertion.text)
    }
    if ($insertions.Count) {
        $after = Convert-IdlMetadataTransport $after $text $annotationText
    }
    $plans.Add([ordered]@{ relative = $relative; path = $path; before = $bytes; after = [Text.Encoding]::Latin1.GetBytes($after); insertions = @($insertions) })
    $results.Add([ordered]@{
        original = $relative; generatedHeaders = @($owner.generatedHeaders); partitionCandidates = @($owner.partitionCandidates)
        sourceSha256 = Get-Hash $bytes; patchedSha256 = Get-Hash ([Text.Encoding]::Latin1.GetBytes($after))
        changed = $insertions.Count -gt 0; dispositions = @($dispositions); insertions = @($insertions)
    })
}

$activation = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::OrdinalIgnoreCase)
$unresolvedActivation = [Collections.Generic.List[object]]::new()
$recipePath = Join-Path $SdkProjectRoot 'patches\SdkHeaders.json'
$admittedOutputs = @()
if (Test-Path -LiteralPath $recipePath -PathType Leaf) {
    $recipe = Get-Content -LiteralPath $recipePath -Raw | ConvertFrom-Json
    if ($recipe.schemaVersion -ne 1) { throw 'Normal parser activation requires a schema-1 SDK recipe.' }
    if ($null -ne $recipe.PSObject.Properties['midl']) {
        $admittedOutputs = @($recipe.midl.outputs)
    }
}
foreach ($owner in @($results | Where-Object changed)) {
    foreach ($header in $owner.generatedHeaders) {
        if ([IO.Path]::IsPathRooted($header) -or $header -match '(^|[\\/])\.\.([\\/]|$)' -or
            [IO.Path]::GetExtension($header) -ne '.h') {
            throw "Invalid generated-header owner route: $header"
        }
        if (!@($admittedOutputs | Where-Object { $_.source -ieq $owner.original -and $_.path -ieq $header }).Count) {
            $unresolvedActivation.Add([ordered]@{ original = $owner.original; header = $header; reason = 'original-output-not-admitted-to-recipe' })
            continue
        }
        $matched = $false
        foreach ($name in $owner.partitionCandidates) {
            if ($name -notmatch '^[A-Za-z0-9_.-]+$') { throw "Invalid normal partition name: $name" }
            $directory = Join-Path $SdkProjectRoot "Partitions\$name"
            $settings = Join-Path $directory 'settings.rsp'
            if (!(Test-Path -LiteralPath "$directory\main.cpp" -PathType Leaf) -or
                !(Test-Path -LiteralPath $settings -PathType Leaf)) { continue }
            $before = [IO.File]::ReadAllBytes($settings)
            $content = [Text.UTF8Encoding]::new($false, $true).GetString($before)
            $traverses = @(Get-RspValues $content '--traverse')
            $owns = @($traverses | Where-Object {
                $pattern = $_.Replace('/', '\')
                $pattern.StartsWith('<IncludeRoot>\', [StringComparison]::OrdinalIgnoreCase) -and
                    [Management.Automation.WildcardPattern]::new($pattern.Substring(14),
                        [Management.Automation.WildcardOptions]::IgnoreCase).IsMatch($header.Replace('/', '\'))
            }).Count -gt 0
            if (!$owns) { continue }
            $matched = $true
            if ($activation.ContainsKey($name)) { continue }
            $enabled = @(Get-RspValues $content '--config') -ccontains 'parse-win32-annotations'
            $after = $before
            if (!$enabled) {
                $newline = [regex]::Match($content, '\r\n|\n|\r').Value
                if (!$newline) { $newline = "`r`n" }
                $separator = if ($content.Length -and $content[-1] -notin @("`r", "`n")) { $newline } else { '' }
                $suffix = [Text.Encoding]::UTF8.GetBytes("${separator}--config${newline}parse-win32-annotations${newline}")
                $after = [byte[]]::new($before.Length + $suffix.Length)
                $before.CopyTo($after, 0)
                $suffix.CopyTo($after, $before.Length)
            }
            $activation.Add($name, [ordered]@{
                partition = $name; settings = $settings; enabled = $enabled
                before = $before; after = $after; preimageSha256 = Get-Hash $before; resultSha256 = Get-Hash $after
            })
        }
        if (!$matched) {
            $unresolvedActivation.Add([ordered]@{
                original = $owner.original; header = $header; reason = 'no-configured-normal-traverse-owner'
            })
        }
    }
}
if ($Apply) {
    if (!$activation.Count -or $unresolvedActivation.Count) {
        throw 'Apply requires recipe-admitted originals and actual configured normal traverse owners; no speculative settings or namespace will be created.'
    }
    foreach ($item in $activation.Values) {
        if ((Get-Hash ([IO.File]::ReadAllBytes($item.settings))) -cne $item.preimageSha256) {
            throw "Normal partition settings changed during planning: $($item.settings)"
        }
    }
    foreach ($item in $activation.Values) {
        if (!$item.enabled) {
            [IO.File]::WriteAllBytes($item.settings, $item.after)
            $item.enabled = $true
        }
    }
}

[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
foreach ($plan in $plans) {
    if (!$plan.insertions.Count) { continue }
    $target = Join-Path "$OutputDirectory\source" $plan.relative
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
    [IO.File]::WriteAllBytes($target, $plan.after)
    Write-Patch $plan.path $target $plan.relative (Join-Path "$OutputDirectory\patches" "$($plan.relative).patch")
}
$all = @($results | ForEach-Object dispositions)
$report = [ordered]@{
    schemaVersion = 1; kind = 'original-idl-authoring-not-compile-or-full-sdk-acceptance'
    metadataTransport = 'selector-bound-cpp-quote-comments'
    inputMapSha256 = Get-Hash ([IO.File]::ReadAllBytes([IO.Path]::GetFullPath($InputMap)))
    sdkIncludeRoot = $SdkIncludeRoot
    bootstrapPolicy = if ($SharedSalBootstrap) { 'shared-sal' } else { 'existing-idl-sal' }
    parameterCarrierPolicy = if ($AllowCompleteInterfaceParameterCarriers) { 'complete-top-level-interface' } else { 'unchanged-default' }
    originalIdlsPatched = @($results | Where-Object changed | ForEach-Object original)
    candidateGeneratedHeaders = @($results | Where-Object changed | ForEach-Object generatedHeaders | Sort-Object -Unique)
    authoredFacts = @($all | Where-Object disposition -eq 'authored-original-idl').Count
    retainedLegacyFacts = @($all | Where-Object disposition -eq 'retained-legacy').Count
    normalParserActivation = [ordered]@{
        applied = [bool]$Apply
        ready = $activation.Count -gt 0 -and !$unresolvedActivation.Count -and
            !@($activation.Values | Where-Object { !$_.enabled }).Count
        unresolved = @($unresolvedActivation)
        partitions = @($activation.Values | ForEach-Object {
            [ordered]@{
                partition = $_.partition; settings = $_.settings; enabled = $_.enabled
                preimageSha256 = $_.preimageSha256; resultSha256 = $_.resultSha256
            }
        })
    }
    owners = @($results)
}
[IO.File]::WriteAllText("$OutputDirectory\report.json", ($report | ConvertTo-Json -Depth 20), [Text.UTF8Encoding]::new($false))
[pscustomobject]@{
    Report = "$OutputDirectory\report.json"; OriginalIdls = $report.originalIdlsPatched.Count
    CandidateGeneratedHeaders = $report.candidateGeneratedHeaders.Count
    AuthoredFacts = $report.authoredFacts; RetainedLegacyFacts = $report.retainedLegacyFacts
}
