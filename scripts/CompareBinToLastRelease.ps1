[CmdletBinding()]
param (
    [switch]
    $SkipInstallTools,

    [string]
    $UpdateDifferencesWithComment
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

$utilsArgs = @('compare', '--first', $previousReleaseWinmd, '--second', $winmdPath, '--knownDiffsFile', $changesSinceLastRelease)
if ($UpdateDifferencesWithComment)
{
    $utilsArgs += '--updateKnownDiffsComment', $UpdateDifferencesWithComment
}

Write-Verbose "Calling: dotnet $utilsArgs"

& dotnet $winmdUtilsPathBin $utilsArgs
if ($LastExitCode -lt 0)
{
    if (!$SuppressSuggestionToCallScript.IsPresent)
    {
        Write-Error "If all the differences are expected, please update the expected differences list:`n.\scripts\UpdateChangesSinceLastRelease.ps1 '<add a reason here>'"
    }

    exit -1
}
