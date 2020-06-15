
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
foreach ($match in $funcVisitedMatches)
{
    $ret = $onecoreFuncs.Remove($match.Groups[1].Value)
}

$onecoreFuncsNotVisitedCount = $onecoreFuncs.Count
$onecoreFuncsVisitedCount = $onecoreFuncsCount - $onecoreFuncsNotVisitedCount
$percentVisited = $onecoreFuncsVisitedCount * 100 / $onecoreFuncsCount

Write-Host "$onecoreFuncsVisitedCount out of $onecoreFuncsCount APIs emitted ($percentVisited)"

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

Write-Host "Funcs not emitted at: $missedFuncsFile"
