<#
.SYNOPSIS
    Shows a unified diff of the current build's winmd API surface against the last release.

.DESCRIPTION
    Uses WinmdUtils to decompile both the current build's winmd and the last released
    winmd to sorted C# declarations, then displays a unified diff of the changes.

    This is a local development helper for reviewing API changes before submitting a PR.
    The CI pipeline automatically diffs against the target branch (main) and posts
    a PR comment showing only the changes introduced by the PR.

.PARAMETER SkipInstallTools
    Skip building the build tools (assumes they are already built).

.EXAMPLE
    .\scripts\DiffWinmdToBaseline.ps1
    # Shows the full API diff against the last release

.EXAMPLE
    .\scripts\DiffWinmdToBaseline.ps1 -SkipInstallTools | Out-File diff.patch
    # Save the diff to a file for review
#>
[CmdletBinding()]
param (
    [switch]$SkipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools | Write-Host
}

$winmdPath = Get-OutputWinmdFileName -arch "crossarch"
$previousReleaseWinmd = Get-Win32MetadataLastReleaseWinmdPath
$winmdUtilsPathBin = Join-Path $metadataToolsBin "WinmdUtils.dll"

if (!(Test-Path $winmdPath))
{
    Write-Error "Current build winmd not found at $winmdPath. Run a build first."
    exit 1
}

if (!(Test-Path $previousReleaseWinmd))
{
    Write-Error "Previous release winmd not found at $previousReleaseWinmd. Run 'dotnet restore buildtools' first."
    exit 1
}

$tempDir = Join-Path ([System.IO.Path]::GetTempPath()) "win32metadata-diff"
New-Item -ItemType Directory -Force -Path $tempDir | Out-Null

$baselineDump = Join-Path $tempDir "baseline.cs"
$currentDump = Join-Path $tempDir "current.cs"

Write-Host "Dumping baseline winmd..." -ForegroundColor Blue
& dotnet $winmdUtilsPathBin dump --winmd $previousReleaseWinmd --output $baselineDump
if ($LastExitCode -ne 0) { Write-Error "Failed to dump baseline winmd"; exit 1 }

Write-Host "Dumping current winmd..." -ForegroundColor Blue
& dotnet $winmdUtilsPathBin dump --winmd $winmdPath --output $currentDump
if ($LastExitCode -ne 0) { Write-Error "Failed to dump current winmd"; exit 1 }

Write-Host "`nAPI Diff (baseline -> current):" -ForegroundColor Green
Write-Host "═══════════════════════════════════════════════════════════════" -ForegroundColor Green

# Use git diff for nice colored unified diff output
& git diff --no-index --stat $baselineDump $currentDump
Write-Host ""
& git diff --no-index $baselineDump $currentDump

$exitCode = $LastExitCode

# Clean up
Remove-Item $tempDir -Recurse -Force -ErrorAction SilentlyContinue

if ($exitCode -eq 0)
{
    Write-Host "`nNo API differences found." -ForegroundColor Green
}
else
{
    Write-Host "`nDifferences shown above." -ForegroundColor Yellow
}
