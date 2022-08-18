[CmdletBinding()]
param (
    [switch]
    $SkipInstallTools,

    [switch]
    $SuppressSuggestionToCallScript
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools | Write-Host
}

$winmdPath = Get-OutputWinmdFileName -arch "crossarch"
$previousReleaseWinmd = Get-Win32MetadataLastReleaseWinmdPath
$winmdUtilsPathBin = Join-Path $metadataToolsBin "WinmdUtils.dll"
$changesSinceLastRelease = Get-ChangesSinceLastReleaseFile

Write-Verbose "Comparing $winmdPath to previous release $previousReleaseWinmd..."
Write-Verbose "Calling: dotnet $winmdUtilsPathBin compare --first $previousReleaseWinmd --second $winmdPath --changeExemptionsFile $changesSinceLastRelease"
& dotnet $winmdUtilsPathBin compare --first $previousReleaseWinmd --second $winmdPath --changeExemptionsFile $changesSinceLastRelease
if ($LastExitCode -lt 0)
{
    if (!$SuppressSuggestionToCallScript.IsPresent)
    {
        Write-Error "If all the differences are expected, please update the expected differences list:`n.\scripts\UpdateChangesSinceLastRelease.ps1 '<add a reason here>'"
    }

    exit -1
}
