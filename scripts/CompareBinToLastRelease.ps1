[CmdletBinding()]
param (
    [switch]
    $SkipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools | Write-Host
}

$winmdPath = Get-OutputWinmdFileName -arch "crossarch"
$previousReleaseWinmd = Get-Win32MetadataLastReleaseWinmdPath
$winmdUtilsPathBin = Join-Path $metadataToolsBin "WinmdUtils.dll"

Write-Verbose "Comparing $winmdPath to previous release $previousReleaseWinmd..."

$utilsArgs = @('compare', '--first', $previousReleaseWinmd, '--second', $winmdPath)

Write-Verbose "Calling: dotnet $utilsArgs"

& dotnet $winmdUtilsPathBin $utilsArgs
if ($LastExitCode -lt 0)
{
    exit -1
}
