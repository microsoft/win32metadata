
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $generatorResults,

    [Parameter(Mandatory=$true)]
    [string]
    $remapsFile
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
    $stream.WriteLine($match.Groups[1].Value)    
    $count++
}

$stream.Close()

if ($count -ne 0)
{
    Write-Output "$count remaps emitted at: $remapsFile"
}
