
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $generatorResults,

    [Parameter(Mandatory=$true)]
    [string]
    $mappingFile,

    [Parameter(Mandatory=$true)]
    [string]
    $visitedFuncsFile,

    [Parameter(Mandatory=$true)]
    [string]
    $missedFuncsFile
)

$onecoreFuncs = [System.Collections.Generic.HashSet[String]] @()

$txtMappings = Get-Content -path $mappingFile -Raw
$patternFuncLib = [Regex]::new('([^\s]+)=([^\s]+)')
$funcLibMatches = $patternFuncLib.Matches($txtMappings)
foreach ($match in $funcLibMatches)
{
    $ret = $onecoreFuncs.Add($match.Groups[1].Value)
}

$onecoreFuncsCount = $onecoreFuncs.Count

$txtGenResults = Get-Content -path $generatorResults -Raw
$patternFuncVisited = [Regex]::new('Func with lib path visited: ([^\s]+)')
$funcVisitedMatches = $patternFuncVisited.Matches($txtGenResults)

$stream = [System.IO.StreamWriter] $visitedFuncsFile
foreach ($match in $funcVisitedMatches)
{
    $funcName = $match.Groups[1].Value
    $ret = $onecoreFuncs.Remove($funcName)
}
$stream.Close()

$onecoreFuncsNotVisitedCount = $onecoreFuncs.Count
$onecoreFuncsVisitedCount = $onecoreFuncsCount - $onecoreFuncsNotVisitedCount
$percentVisited = $onecoreFuncsVisitedCount * 100 / $onecoreFuncsCount

Write-Output "$onecoreFuncsVisitedCount out of $onecoreFuncsCount APIs emitted ($percentVisited)"

if (Test-Path -path $missedFuncsFile)
{
    Remove-Item $missedFuncsFile
}

$stream = [System.IO.StreamWriter] $missedFuncsFile
foreach ($name in $onecoreFuncs)
{
    $stream.WriteLine($name)
}
$stream.Close()

Write-Output "Funcs not emitted at: $missedFuncsFile"
