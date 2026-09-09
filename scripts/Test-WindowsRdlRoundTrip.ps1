<#
.SYNOPSIS
    Round-trips a WinMD through windows-rdl for compatibility evaluation.

.DESCRIPTION
    Builds the pinned Rust wrapper, writes canonical RDL from the input WinMD,
    and compiles that RDL back into a second WinMD. This is a non-shipping
    fidelity harness for the windows-rs pipeline migration.

.PARAMETER InputWinmd
    WinMD to round-trip.

.PARAMETER OutputDirectory
    Directory for the generated RDL and rebuilt WinMD.

.PARAMETER ReferenceWinmd
    Additional WinMD references needed to resolve external types or attributes.
#>
[CmdletBinding()]
param (
    [Parameter(Mandatory = $true)]
    [string]$InputWinmd,

    [string]$OutputDirectory = "$PSScriptRoot\..\obj\windows-rdl-roundtrip",

    [string[]]$ReferenceWinmd = @()
)

$ErrorActionPreference = "Stop"

$inputPath = (Resolve-Path $InputWinmd).Path
$outputPath = [System.IO.Path]::GetFullPath($OutputDirectory)
$manifestPath = Join-Path $PSScriptRoot "..\tools\rust\Cargo.toml"
$rdlPath = Join-Path $outputPath "roundtrip.rdl"
$winmdPath = Join-Path $outputPath "roundtrip.winmd"

New-Item -ItemType Directory -Force -Path $outputPath | Out-Null

$arguments = @(
    "run",
    "--quiet",
    "--locked",
    "--manifest-path", $manifestPath,
    "--",
    "roundtrip",
    "--input", $inputPath,
    "--rdl-output", $rdlPath,
    "--winmd-output", $winmdPath
)

foreach ($reference in $ReferenceWinmd)
{
    $arguments += @("--reference", (Resolve-Path $reference).Path)
}

& cargo @arguments
if ($LASTEXITCODE -ne 0)
{
    throw "windows-rdl round-trip failed with exit code $LASTEXITCODE"
}

Write-Host "RDL: $rdlPath"
Write-Host "Rebuilt WinMD: $winmdPath"
