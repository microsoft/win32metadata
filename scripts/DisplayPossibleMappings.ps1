
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $generatorResults,

    [Parameter(Mandatory=$true)]
    [string]
    $remapsFile,

    [Parameter(Mandatory=$true)]
    [hashtable]
    $excludedItems
)

if (Test-Path -path $remapsFile)
{
    Remove-Item $remapsFile
}

$stream = [System.IO.StreamWriter] $remapsFile

$txtGenResults = Get-Content -path $generatorResults -Raw
$patternPotentialRemap = [Regex]::new('Potential remap: ([^\s]+)')
$remapMatches = $patternPotentialRemap.Matches($txtGenResults)
$count = 0

foreach ($match in $remapMatches)
{
    $name = $match.Groups[1].Value.Split('=')[0]
    if ($excludedItems.ContainsKey($name))
    {
        continue
    }

    $stream.WriteLine($match.Groups[1].Value)
    $count++
}

$stream.Close()

if ($count -ne 0)
{
    Write-Host "$count remaps emitted at: $remapsFile"
}
