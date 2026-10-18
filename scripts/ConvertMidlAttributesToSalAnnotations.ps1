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

$stream = [System.IO.StreamWriter] $outputFileName

foreach ($line in (Get-Content $inputFileName)) {
    # Quoted C++ text is not an IDL parameter declaration.
    if ($line.TrimStart().StartsWith("cpp_quote(") -or $line.TrimStart().StartsWith("#pragma")) {
        $stream.WriteLine($line)

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

    # Convert MIDL attributes to SAL annotations.
    $startAt = 0
    while ($attributeListPattern.IsMatch($line, $startAt)) {
        $match = $attributeListPattern.Match($line, $startAt)
        $attributeList = $match.Groups[1].Value
        $attributeListIndex = $match.Groups[0].Index + $match.Groups[0].Length
        $existingAnnotation = [regex]::Match($line.Substring($attributeListIndex), "^\s*$annotationPattern")
        if ($existingAnnotation.Success -and
            $existingAnnotation.Groups['value'].Value -match '_(?:In|Out|Inout|COM_Outptr)[A-Za-z0-9_]*(?:\(|$|\s)') {
            $startAt = $attributeListIndex + $existingAnnotation.Length
            continue
        }

        $in = $false
        $out = $false
        $isComPtr = $false
        $retval = $false
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
            } elseif ($attribute -eq "retval") {
                $retval = $true
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

        # Overwrite the annotation with _COM_Outptr_ or _Out_retval_ if possible.
        if ($out -and $isComPtr) {
            $annotation = "_COM_Outptr_"

            if ($retval) {
                $annotation += "retval_"
            }
        } elseif ($out -and $retval) {
            $annotation = "_Out_retval_"
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

            $startAt = $attributeListIndex + $annotationAttribute.Length
        } else {
            $startAt = $attributeListIndex 
        }
    }

    $stream.WriteLine($line)
}

$stream.Close()
