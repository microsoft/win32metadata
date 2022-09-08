# Converts idl attributes into SAL annotation attributes
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $inputFileName,

    [Parameter(Mandatory=$true)]
    [string]
    $outputFileName
)

if (!(Test-Path -path $inputFileName))
{
    Write-Error "Couldn't find $inputFileName."
    exit -1
}

if (Test-Path -path $outputFileName)
{
    Remove-Item $outputFileName
}

$srcLines = Get-Content -path $inputFileName
$attrListFinderPattern = [Regex]::new('\[(((?:,\s*)?(in|out|string|retval|unique|defaultvalue\([^\)]+\)|size_is\([^\)]+\)|iid_is\([^\)]+\)|length_is\([^\)]+\)))+)\]')
$attrItemPattern = [Regex]::new('(in|out|string|retval|unique|defaultvalue\([^\)]+\)|size_is\([^\)]+\)|length_is\([^\)]+\)|iid_is\([^\)]+\))')
$stream = [System.IO.StreamWriter] $outputFileName
foreach ($line in $srcLines)
{
    # Skip lines that look like this so we don't re-do annotations that already exist, and so
    # we don't mess up cpp quotes or pragmas
    if (!$line.Contains("annotation (") -and !$line.Contains("annotation(") -and !$line.Contains("cpp_quote(") -and !$line.StartsWith("#pragma"))
    {
        # Keep track of where we need to look next in the line
        $beginLookAt = 0

        # Look for an attribute list
        while ($attrListFinderPattern.IsMatch($line, $beginLookAt))
        {
            $match = $attrListFinderPattern.Match($line, $beginLookAt)
            $attrList = $match.Groups[1].Value
            $in = $false
            $out = $false
            $isComPtr = $false
            $retval = $false
            $optional = $false
            $size_is = $null
            $length_is = $null
            $params = $null

            # Pull out each item from the attribute list
            foreach ($itemMatch in $attrItemPattern.Matches($attrList))
            {
                $part = $itemMatch.Groups[1].Value
                if ($part -eq "in")
                {
                    $in = $true
                }
                elseif ($part -eq "out")
                {
                    $out = $true
                }
                elseif ($part.StartsWith("iid_is"))
                {
                    $isComPtr = $true
                }
                elseif ($part -eq "retval")
                {
                    $retval = $true
                }
                elseif ($part -eq "optional")
                {
                    $optional = $true
                }
                elseif ($part.StartsWith("size_is"))
                {
                    $size_is = $part.Substring("size_is(".Length);
                    $size_is = $size_is.Substring(0, $size_is.Length - 1);

                    # Fix some badly formed attributes
                    $size_is = $size_is.Replace(",", "").Trim()
                }
                elseif ($part.StartsWith("length_is"))
                {
                    $length_is = $part.Substring("length_is(".Length);
                    $length_is = $length_is.Substring(0, $length_is.Length - 1);

                    # Fix some badly formed attributes
                    $length_is = $length_is.Replace(",", "").Trim()
                }
            }

            # If it doesn't have in or out, it's not a parameter and we don't want to do anything
            if (!$in -and !$out)
            {
                break
            }

            $annotation = $null
            $ptrOp = $null
            if ($in -and $out)
            {
                $annotation = "_Inout_"
                $ptrOp = "updates_"
            }
            elseif ($in)
            {
                $annotation = "_In_"
                $ptrOp = "reads_"
            }
            elseif ($out)
            {
                $annotation = "_Out_"
                $ptrOp = "writes_"
            }

            if ($size_is)
            {
                $annotation += $ptrOp
                $params = "($size_is"
                if ($length_is -and $out)
                {
                    $annotation += "to_"
                    $params += ",$length_is"
                }

                $params += ")"
            }

            if ($optional)
            {
                $annotation += "opt_"
            }

            if ($params)
            {
                $annotation += $params
            }

            $outComPtr = $out -and $isComPtr

            # Overwrite everything with just _COM_Outptr_ or _Out_retval_ if we can
            if ($outComPtr)
            {
                $annotation = "_COM_Outptr_"

                if ($retval)
                {
                    $annotation += "retval_"
                }
            }
            elseif ($out -and $retval)
            {
                $annotation = "_Out_retval_"
            }

            if ($annotation)
            {
                $annotationAttr = "[annotation(""$annotation"")]"

                # Insert the new annotation attribute into the string without losing the original attribute list
                $line = $line.Substring(0, $match.Groups[0].Index + $match.Groups[0].Length) + $annotationAttr + $line.Substring($match.Groups[0].Index + $match.Groups[0].Length)

                # Next time start looking beyond what we just inserted in case there are more attribute
                # lists in this line
                $beginLookAt = $match.Groups[0].Index + $match.Groups[0].Length + $annotationAttr.Length
            }
            else
            {
                break
            }
        }
    }

    $stream.WriteLine($line)
}
$stream.Close()
