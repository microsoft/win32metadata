<#
.SYNOPSIS
Build Windows metadata using the existing default compilation path.
.PARAMETER UseOriginalCompilation
Opt into one complete original source/profile per logical partition. Requires prepared policy inputs.
.PARAMETER NativeJobs
Per-architecture original-TU worker limit, multiplied by ArchitectureJobs. Synthetic probes are separate.
#>
param
(
    [switch]
    $skipInstallTools,

    [switch]
    $Clean,

    [switch]
    $Debug,

    [switch]
    $RawSdk,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch",

    [ValidateRange(1, 2147483647)]
    [int]
    $ArchitectureJobs = 3,

    [ValidateRange(1, 2147483647)]
    [int]
    $NativeJobs = 1,

    [switch]
    $UseOriginalCompilation
)

if ($RawSdk -and $UseOriginalCompilation) {
    throw "-UseOriginalCompilation requires partition-policy inputs and cannot be combined with -RawSdk."
}

. "$PSScriptRoot\CommonUtils.ps1"
. "$PSScriptRoot\WindowsRsGenerationProvenance.ps1"

if ($Clean.IsPresent)
{
    & $PSScriptRoot\CleanOutputs.ps1
}

if (!$skipInstallTools.IsPresent)
{
    Install-BuildTools
}

$assemblyVersion = nbgv get-version -v AssemblyVersion

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Host "`n"
Write-Host "*** Creating $outputWinmdFileName..." -ForegroundColor Blue

if ($Debug)
{
    $configuration = "Debug"
}
else
{
    $configuration = "Release"
}

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")

# Explicitly restore the Win32Metadata project to avoid issues restore happening during build
& dotnet restore "$windowsWin32ProjectRoot" --configfile "$rootDir\nuget.Config"
ThrowOnNativeProcessError

$timestamp = Get-Date -Format "yyyyMMddHHmmss"
$logFile = "$PSScriptRoot\..\bin\logs\BuildMetadataBin_$timestamp.binlog"
$buildArgs = @(
    "build",
    $windowsWin32ProjectRoot,
    "-c", $configuration,
    "-t:EmitWinmd",
    "-p:WinmdVersion=$assemblyVersion",
    "-p:OutputWinmd=$outputWinmdFileName",
    "-p:WinmdArchitectureJobs=$ArchitectureJobs",
    "-p:WinmdNativeJobs=$NativeJobs",
    "-bl:$logFile",
    "--no-restore"
)
if ($arch -ne "crossarch")
{
    $buildArgs += "-p:TargetArchitectures=$arch"
}
if ($RawSdk) {
    $buildArgs += "-p:WinmdUsePartitionAuthority=false"
}
if ($UseOriginalCompilation) {
    $buildArgs += "-p:WinmdUseOriginalCompilation=true"
}
& dotnet @buildArgs
ThrowOnNativeProcessError
if (!$RawSdk) {
    $architectures = if ($arch -eq "crossarch") { @("x64", "x86", "arm64") } else { @($arch) }
    $diagnostics = Get-WindowsRsEnumDiagnostics -OutputPath $outputWinmdFileName -Architectures $architectures
    $status = if ($diagnostics.partial) { "PARTIAL SDK" } else { "complete SDK" }
    Write-Host "Generated $status WinMD: $outputWinmdFileName"
    Write-Host "Enum omission entries: $($diagnostics.omissionCount); full report: $($diagnostics.path)"
}
