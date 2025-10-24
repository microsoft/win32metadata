param
(
    [Parameter(Mandatory = $true)]
    [string]
    $inputFileName,

    [Parameter(Mandatory = $true)]
    [string]
    $outputFileName
)

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
$parenBlob = "\((?:[^()]*\([^()]*\)[^()]*|[^()]*)\)"
$attributeListPattern = [Regex]::new("\[(((?:,\s*)?(in|out|string|retval|unique|defaultvalue$parenBlob|size_is$parenBlob|iid_is$parenBlob|length_is$parenBlob))+)\]")
$attributePattern = [Regex]::new("(in|out|string|retval|unique|defaultvalue$parenBlob|size_is$parenBlob|iid_is$parenBlob|length_is$parenBlob)")

$stream = [System.IO.StreamWriter] $outputFileName

foreach ($line in (Get-Content $inputFileName)) {
    # Skip lines that already have annotations and ignore cpp_quote and #pragma.
    if ($line.Contains("annotation (") -or $line.Contains("annotation(") -or $line.Contains("cpp_quote(") -or $line.StartsWith("#pragma")) {
        $stream.WriteLine($line)

        continue
    }

    # Merge multiple adjacent MIDL attribute lists into one so all annotations are consolidated into one annotation attribute per parameter.
    if ($attributeListPattern.Matches($line).Count -gt 1) {
        $line = $line -replace "\]\s*\[", ", "
    }

    # Convert MIDL attributes to SAL annotations.
    $startAt = 0
    while ($attributeListPattern.IsMatch($line, $startAt)) {
        $match = $attributeListPattern.Match($line, $startAt)
        $attributeList = $match.Groups[1].Value
        $attributeListIndex = $match.Groups[0].Index + $match.Groups[0].Length

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
            $annotationAttribute = "[annotation(""$annotation"")]"

            $line = $line.Substring(0, $attributeListIndex) + $annotationAttribute + $line.Substring($attributeListIndex)

            $startAt = $attributeListIndex + $annotationAttribute.Length
        } else {
            $startAt = $attributeListIndex 
        }
    }

    $stream.WriteLine($line)
}

$stream.Close()
