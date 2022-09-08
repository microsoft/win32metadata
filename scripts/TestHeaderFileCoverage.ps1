. "$PSScriptRoot\CommonUtils.ps1"

$partitionsDir = "$windowsWin32ProjectRoot\Partitions"

function GetTraverseHash()
{
    $ret = [System.Collections.Generic.HashSet[string]]::new()

    $selStringRet = Get-ChildItem -Recurse -Filter settings.rsp $partitionsDir | Select-String -pattern "<IncludeRoot>(.+)"
    foreach ($match in $selStringRet.Matches)
    {
        $file = $match.Groups[1].Value.Replace('\', '/').ToLowerInvariant()
        $ret.Add($file)
    }

    return $ret
}

function GetUnconveredFilesMap()
{
    $ret = [ordered]@{}
    $items = Import-Csv "$PSScriptRoot\HeaderFileCoverageExceptions.csv" -Delimiter ','
    foreach ($item in $items)
    {
        if ($item.Skipping -ne "true")
        {
            $ret[$item.File] = $item.Reason
        }
        else
        {
            $ret[$item.File] = "skipping"
        }
    }

    return $ret
}

$traverseFiles = GetTraverseHash
$uncoveredFilesMap = GetUnconveredFilesMap

Write-Host "Scanning header files..."

$sdkIncludePath = $recompiledIdlHeadersDir
$headerFiles = Get-ChildItem -Recurse -Filter *.h "$sdkIncludePath/shared", "$sdkIncludePath/um"
$total = 0
$traversed = 0
$finalList = [ordered]@{}

foreach ($file in $headerFiles)
{
    $selStringRet = $file.FullName | select-string -pattern "\\(shared|um)\\.+"
    $total++

    $nameToCheck = $selStringRet.Matches[0].Groups[0].Value.ToLowerInvariant().Replace('\', '/')
    if (!$traverseFiles.Contains($nameToCheck))
    {
        $reason = $uncoveredFilesMap[$nameToCheck]
        if ($reason -eq "skipping")
        {
            $traversed++

            continue
        }

        #Write-Host "reason = $reason"

        if (!$reason)
        {
            $reason = "Unknown: not found in exceptions list."
        }

        $finalList[$nameToCheck] = $reason
    }
    else
    {
        $traversed++
    }
}

if ($finalList.Count -gt 0)
{
    Write-Host "The below header files are not included in any partition:"
    foreach ($item in $finalList.Keys)
    {
        $reason = $finalList[$item]
        Write-Host "$item - $reason"
    }
}

$percent = ($traversed/$total).ToString("P")
Write-Host "$traversed/$total covered by partitions or exceptions ($percent)"
