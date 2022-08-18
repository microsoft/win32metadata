param
(
    [string]
    $ReasonForAddedDifferences
)

. "$PSScriptRoot\CommonUtils.ps1"

$compareOutput = Join-Path $env:TEMP "winmdchanges.txt"

& "$PSScriptRoot\CompareBinToLastRelease.ps1" -SkipInstallTools -SuppressSuggestionToCallScript 1> $compareOutput

if ($LastExitCode -lt 0)
{
    $changesSinceLastRelease = Get-ChangesSinceLastReleaseFile
    
    $commentLine = "# $ReasonForAddedDifferences"
    Add-Content $changesSinceLastRelease -Value $commentLine

    $lines = (Get-Content $compareOutput) | where-object {$_ -notmatch "\(informational only\)" } | where-object {$_ -ne ""}
    Add-Content $changesSinceLastRelease $lines

    Write-Host "New differences added to $changesSinceLastRelease."
}
else 
{
    Write-Host "No differences found, so $changesSinceLastRelease not updated."
}
