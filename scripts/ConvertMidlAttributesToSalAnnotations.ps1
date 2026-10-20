param
(
    [Parameter(Mandatory = $true)]
    [string]
    $inputFileName,

    [Parameter(Mandatory = $true)]
    [string]
    $outputFileName
)

$ErrorActionPreference = "Stop"

if (!(Test-Path $inputFileName)) {
    Write-Error "Couldn't find $inputFileName."
    exit -1
}

if (Test-Path $outputFileName) {
    Remove-Item $outputFileName
}

# Function to parse and validate size/length expressions from MIDL attributes
function SALParseSize {
    param(
        [string]$attribute,
        [string]$prefix
    )
    
    $extracted = $attribute.Substring("${prefix}(".Length);
    $extracted = $extracted.Substring(0, $extracted.Length - 1);
    $extracted = $extracted.Trim(", ")
    
    # If the string still has an internal comma, that means it's more complex than SAL can handle, omit it.
    # Also if there are parens but they're not at the front, that's someone using a macro inside the annotation
    # which the winmd tooling cannot currently handle. Skip.
    if ($extracted.Contains(",")) { 
        return $null 
    } elseif ($extracted.IndexOf("(") -gt 0) {
        return $null
    } elseif ($extracted.IndexOf("(") -eq 0) {
        # Strip any cast prefix like (ULONG) off the front since the tooling can't parse that.
        $castPrefixEnd = $extracted.IndexOf(")") + 1
        $extracted = $extracted.Substring($castPrefixEnd)
    }
    
    return $extracted
}

# Some SAL annotations can have parens in them like size_is((ULONG)cMembers). Allow strings like "(...)" or "((type)...)"
$parenBlob = "\((?:\([^()]*\)[^()]*|[^()]*)\)"
$attributeListPattern = [Regex]::new("\[(((?:,\s*)?(in|out|string|retval|unique|defaultvalue$parenBlob|size_is$parenBlob|iid_is$parenBlob|length_is$parenBlob))+)\]")
$attributePattern = [Regex]::new("(in|out|string|retval|unique|defaultvalue$parenBlob|size_is$parenBlob|iid_is$parenBlob|length_is$parenBlob)")
$adjacentAttributeLists = [Regex]::new("(?<left>$attributeListPattern)\s*(?<right>$attributeListPattern)")
$annotationPattern = '\[annotation\s*\(\s*"(?<value>(?:\\.|[^"\\])*)"\s*\)\s*\]'
$annotationBeforeNative = [Regex]::new("(?<annotation>$annotationPattern)\s*(?<native>$attributeListPattern)")
$adjacentAnnotations = [Regex]::new("(?<left>$annotationPattern)\s*(?<right>$annotationPattern)")

function Test-NativeLocalAttribute([string]$text) {
    return $text -match '[\[,]\s*local\s*(?=,|\])'
}

function Get-RemoteInterfaceRanges([string]$text) {
    $code = [regex]::Replace($text,
        '/\*[\s\S]*?\*/|//[^\r\n]*|"(?:\\[\s\S]|[^"\\])*"|(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*',
        { param($match) [regex]::Replace($match.Value, '[^\r\n]', ' ') })
    $braces = [System.Collections.Generic.Stack[int]]::new()
    $ends = @{}
    for ($i = 0; $i -lt $code.Length; $i++) {
        if ($code[$i] -eq '{') {
            $braces.Push($i)
        } elseif ($code[$i] -eq '}' -and $braces.Count -gt 0) {
            $ends[$braces.Pop()] = $i
        }
    }
    $ranges = foreach ($match in [regex]::Matches($code,
        '\b(?:interface|dispinterface)\s+[A-Za-z_]\w*\s*(?::[^;{]+)?\s*\{')) {
        $begin = $match.Index + $match.Length - 1
        if (!$ends.ContainsKey($begin)) {
            throw "Cannot bind the native IDL interface body at offset $($match.Index) in $inputFileName."
        }
        $previous = if ($match.Index -eq 0) { -1 } else {
            $code.LastIndexOfAny([char[]]';{}', $match.Index - 1)
        }
        if (!(Test-NativeLocalAttribute $code.Substring($previous + 1, $match.Index - $previous - 1))) {
            [pscustomobject]@{ Begin = $begin; End = $ends[$begin] }
        }
    }
    return [pscustomobject]@{ Code = $code; Ranges = @($ranges) }
}

$lines = foreach ($line in (Get-Content $inputFileName)) {
    # Quoted C++ text is not an IDL parameter declaration.
    if ($line.TrimStart() -match '^(?:cpp_quote|midl_echo)\b|^#') {
        $line
        continue
    }

    while ($annotationBeforeNative.IsMatch($line)) {
        $line = $annotationBeforeNative.Replace($line, {
            param($match)
            $match.Groups['native'].Value + $match.Groups['annotation'].Value
        })
    }
    # Merge multiple adjacent MIDL attribute lists into one so all annotations are consolidated into one annotation attribute per parameter.
    while ($adjacentAttributeLists.IsMatch($line)) {
        $line = $adjacentAttributeLists.Replace($line, {
            param($match)
            $left = $match.Groups['left'].Value
            $left.Substring(0, $left.Length - 1) + ", " + $match.Groups['right'].Value.Substring(1)
        })
    }
    while ($adjacentAnnotations.IsMatch($line)) {
        $line = $adjacentAnnotations.Replace($line, {
            param($match)
            $left = [regex]::Match($match.Groups['left'].Value, $annotationPattern).Groups['value'].Value
            $right = [regex]::Match($match.Groups['right'].Value, $annotationPattern).Groups['value'].Value
            '[annotation("' + $left + ' ' + $right + '")]'
        })
    }
    $line
}

$source = [string]::Join("`n", @($lines))
$native = Get-RemoteInterfaceRanges $source
$stream = [System.IO.StreamWriter] $outputFileName
$offset = 0
foreach ($line in $lines) {
    $originalLength = $line.Length
    $inserted = 0
    if ($line.TrimStart() -match '^(?:cpp_quote|midl_echo)\b|^#') {
        $stream.WriteLine($line)
        $offset += $originalLength + 1
        continue
    }
    # Convert MIDL attributes to SAL annotations.
    $startAt = 0
    while ($attributeListPattern.IsMatch($line, $startAt)) {
        $match = $attributeListPattern.Match($line, $startAt)
        $attributeList = $match.Groups[1].Value
        $attributeListIndex = $match.Groups[0].Index + $match.Groups[0].Length
        $nativeOffset = $offset + $match.Index - $inserted
        $remote = @($native.Ranges | Where-Object { $nativeOffset -gt $_.Begin -and $nativeOffset -lt $_.End })
        if ($remote.Count -gt 0) {
            $previous = $native.Code.LastIndexOfAny([char[]]';{}', $nativeOffset - 1)
            if (!(Test-NativeLocalAttribute $native.Code.Substring($previous + 1, $nativeOffset - $previous - 1))) {
                # /sal derives remote RPC counts/directions; annotation would override it and cause MIDL2495.
                $startAt = $attributeListIndex
                continue
            }
        }
        $existingAnnotation = [regex]::Match($line.Substring($attributeListIndex), "^\s*$annotationPattern")
        if ($existingAnnotation.Success -and
            $existingAnnotation.Groups['value'].Value -match '_(?:In|Out|Inout|COM_Outptr)[A-Za-z0-9_]*(?:\(|$|\s)') {
            $startAt = $attributeListIndex + $existingAnnotation.Length
            continue
        }

        $in = $false
        $out = $false
        $isComPtr = $false
        $optional = $false
        $size_is = $null
        $length_is = $null
        $parameters = $null

        Write-Verbose "Found attribute: $attributeList"

        # Process each attribute.
        foreach ($match in $attributePattern.Matches($attributeList)) {
            $attribute = $match.Groups[1].Value
            if ($attribute -eq "in") {
                $in = $true
            } elseif ($attribute -eq "out") {
                $out = $true
            } elseif ($attribute.StartsWith("iid_is")) {
                $isComPtr = $true
            } elseif ($attribute -eq "optional") {
                $optional = $true
            } elseif ($attribute.StartsWith("size_is")) {
                $size_is = SALParseSize $attribute "size_is"
            } elseif ($attribute.StartsWith("length_is")) {
                $length_is = SALParseSize $attribute "length_is"
            }
        }

        # Skip matches that aren't parameters.
        if (!$in -and !$out) {
            $startAt = $attributeListIndex

            continue
        }

        # MIDL derives pointer optionality from its native type and pointer defaults.
        if ($in -and !$out -and !$existingAnnotation.Success -and
            $attributeList -match '^\s*(?:in|unique)(?:\s*,\s*(?:in|unique))*\s*$' -and
            $line.Substring($attributeListIndex) -match '^\s*[\w:]+(?:\s+[\w:]+)*\s*\*') {
            $startAt = $attributeListIndex
            continue
        }

        $annotation = $null

        $pointerOperation = $null
        if ($in -and $out) {
            $annotation = "_Inout_"
            $pointerOperation = "updates_"
        } elseif ($in) {
            $annotation = "_In_"
            $pointerOperation = "reads_"
        } elseif ($out) {
            $annotation = "_Out_"
            $pointerOperation = "writes_"
        }

        if ($size_is) {
            $annotation += $pointerOperation
            $parameters = "($size_is"
            if ($length_is -and $out) {
                $annotation += "to_"
                $parameters += ",$length_is"
            }
            $parameters += ")"
        }

        if ($optional) {
            $annotation += "opt_"
        }

        if ($parameters) {
            $annotation += $parameters
        }

        # [retval] remains in MIDL's native comment; SDK SAL has no _Out_retval_ macro.
        if ($out -and $isComPtr) {
            $annotation = "_COM_Outptr_"
        }

        # Insert the annotation attribute into the line after the original attribute list.
        if ($annotation) {
            if ($existingAnnotation.Success) {
                # MIDL emits only the last annotation attribute; keep SAL and metadata in one payload.
                $annotation += " " + $existingAnnotation.Groups['value'].Value
            }
            $annotationAttribute = "[annotation(""$annotation"")]"

            $line = $line.Substring(0, $attributeListIndex) + $annotationAttribute +
                $line.Substring($attributeListIndex + $existingAnnotation.Length)
            $inserted += $annotationAttribute.Length - $existingAnnotation.Length

            $startAt = $attributeListIndex + $annotationAttribute.Length
        } else {
            $startAt = $attributeListIndex 
        }
    }

    $stream.WriteLine($line)
    $offset += $originalLength + 1
}

$stream.Close()
