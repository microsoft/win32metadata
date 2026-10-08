<#
.SYNOPSIS
    Generates a WinMD from the prepared SDK headers with windows-rs.

.PARAMETER Partition
    Optional partition names under generation\WinSDK\Partitions for a focused run.
    By default, uses the upstream aggregate + satellite SDK header manifest.

.PARAMETER Architecture
    Target architectures to scrape and merge. Defaults to x64, x86, and arm64.

.PARAMETER ArchitectureJobs
    Maximum concurrent architecture workers, including extraction. Defaults to three.

.PARAMETER UsePartitionAuthority
    Generate one aggregate plus one satellite input, plus the two PSAPI compile variants,
    and route them with the checked-in logical partition traversal policy.
    This is the default for production generation.

.PARAMETER RawSdk
    Use the pinned raw NuGet SDK headers without preparation or partition authority.

.PARAMETER ExtractionCoverage
    Write an x64 canonical traversal-root provenance report and stop before RDL/WinMD output.
    Requires UsePartitionAuthority.

.PARAMETER OutputWinmd
    Output WinMD path.

.PARAMETER Namespace
    Root namespace for the selected partitions. Defaults to Windows.Win32.

.PARAMETER SkipBuild
    Use the previously built Rust executable.
#>
[CmdletBinding()]
param (
    [string[]]$Partition = @(),

    [ValidateSet("x64", "arm64", "x86")]
    [string[]]$Architecture = @("x64", "x86", "arm64"),

    [ValidateRange(1, 2147483647)]
    [int]$ArchitectureJobs = 3,

    [switch]$UsePartitionAuthority,

    [switch]$RawSdk,

    [string]$ExtractionCoverage,

    [string]$OutputWinmd = "$PSScriptRoot\..\bin\Windows.Win32.winmd",

    [ValidateNotNullOrEmpty()]
    [string]$Namespace = "Windows.Win32",

    [switch]$SkipBuild
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"
if ($RawSdk -and ($UsePartitionAuthority -or $Partition.Count)) {
    throw "-RawSdk cannot be combined with -UsePartitionAuthority or -Partition."
}
if ($UsePartitionAuthority -and $Partition.Count) {
    throw "-UsePartitionAuthority cannot be combined with -Partition."
}
$authority = if ($PSBoundParameters.ContainsKey("UsePartitionAuthority")) {
    [bool]$UsePartitionAuthority
} else {
    !$RawSdk -and !$Partition.Count
}
$tool = Join-Path $rootDir "bin\GeneratorSdk\tools\win-x64\win32metadata-tools.exe"
$namespaceRoutes = Join-Path $windowsWin32ProjectRoot "requiredNamespacesForNames.rsp"
$outputPath = [System.IO.Path]::GetFullPath($OutputWinmd)
$coveragePath = if ($ExtractionCoverage) {
    [System.IO.Path]::GetFullPath($ExtractionCoverage)
} else {
    $null
}
$outputStem = [System.IO.Path]::GetFileNameWithoutExtension($outputPath)
$objDir = Join-Path $windowsWin32ProjectRoot "obj\windows-rs\$outputStem"

if (!(Test-Path "$rootDir\obj\BuildTools.proj\BuildTools.proj.nuget.g.props"))
{
    & dotnet restore "$rootDir\BuildTools\BuildTools.proj" --configfile "$rootDir\nuget.Config" --verbosity quiet
    ThrowOnNativeProcessError
}

$sdkPackageRoot = Get-WinSdkCppPkgPath
$headerRoot = Join-Path $sdkPackageRoot "c\include\$(Get-WinSdkHeaderVersion)"
$useCheckedInPartitionInputs = $authority -or $Partition.Count -ne 0
$includePaths = @(
    if ($useCheckedInPartitionInputs) {
        $recompiledIdlHeadersDir
        Join-Path $windowsWin32ProjectRoot "AdditionalHeaders\cpdk"
    }
    Join-Path $windowsWin32ProjectRoot "AdditionalHeaders"
    Join-Path $windowsWin32ProjectRoot "Partitions\Com.StructuredStorage"
    Join-Path $windowsWin32ProjectRoot "inc"
    $headerRoot
)

if (!(Test-Path $headerRoot))
{
    throw "Pinned SDK headers were not found at $headerRoot. Restore BuildTools.proj first."
}

if (!$SkipBuild.IsPresent)
{
    & "$PSScriptRoot\Build-Win32MetadataTools.ps1" -OutputDir (Split-Path $tool)
}
elseif (!(Test-Path $tool))
{
    throw "Staged windows-rs metadata tool was not found at '$tool'. Run without -SkipBuild first."
}

$sdkLibRoot = if ($coveragePath) {
    $null
} else {
    Join-Path (Get-WinSdkCppX64PkgPath) "c\um\x64"
}
$assemblyVersion = if ($coveragePath) {
    $null
} else {
    nbgv get-version -v AssemblyVersion
}
$scopeHeaders = @(
    "activation.h", "CoreWindow.h", "corewindow.h", "DocumentSource.h", "documentsource.h",
    "EventToken.h", "eventtoken.h", "hstring.h", "inspectable.h", "manual.h",
    "MemoryBuffer.h", "memorybuffer.h", "midlbase.h", "rdpappcontainerclient.h", "roapi.h",
    "robuffer.h", "roerrorapi.h", "rometadata.h", "rometadataresolution.h",
    "roparameterizediid.h", "roregistrationapi.h", "shcore.h", "WeakReference.h",
    "weakreference.h", "webapplication.h", "windows.graphics.effects.interop.h",
    "windows.graphics.interop.h", "windows.ui.composition.interop.h", "winstring.h",
    "Wsdevlicensing.h", "wsdevlicensing.h"
)

if ($authority -and $Namespace -ne "Windows.Win32") {
    throw "-UsePartitionAuthority requires -Namespace Windows.Win32."
}
if ($coveragePath -and !$authority) {
    throw "-ExtractionCoverage requires -UsePartitionAuthority."
}
if ($coveragePath -and ($Architecture.Count -ne 1 -or $Architecture[0] -ne "x64")) {
    throw "-ExtractionCoverage requires exactly -Architecture x64."
}
$useSdkHeaderManifest = $Partition.Count -eq 0
if ($authority)
{
    Write-Host "Generating aggregate + satellite + PSAPI variant inputs with checked-in logical partition authority for $($Architecture -join ', ')"
}
elseif ($useSdkHeaderManifest)
{
    Write-Host "Generating the upstream aggregate + satellite SDK inputs for $($Architecture -join ', ')"
}
else
{
    Write-Host "Generating $($Partition.Count) selected partition manifest(s) for $($Architecture -join ', ')"
}

$arguments = @(
    "scrape",
    "--namespace", $Namespace,
    "--architecture-jobs", "$ArchitectureJobs",
    "--obj", $objDir
)

if ($coveragePath) {
    $arguments += @("--extraction-coverage", $coveragePath)
}
else {
    $arguments += @(
        "--lib", $sdkLibRoot,
        "--assembly-name", $outputStem,
        "--assembly-version", $assemblyVersion,
        "--output", $outputPath
    )
}

foreach ($include in $includePaths)
{
    $arguments += @("--include", $include)
}

if ($authority)
{
    $arguments += @(
        "--win32-sdk",
        "--partition-policy-root", (Join-Path $windowsWin32ProjectRoot "Partitions"),
        "--namespace-routes", $namespaceRoutes
    )
}
elseif ($useSdkHeaderManifest)
{
    $arguments += "--win32-sdk"
    foreach ($header in $scopeHeaders)
    {
        $arguments += @("--scope-header", $header)
    }
}
else
{
    foreach ($name in $Partition)
    {
        $main = Join-Path $windowsWin32ProjectRoot "Partitions\$name\main.cpp"
        if (!(Test-Path $main))
        {
            throw "Partition '$name' was not found at $main."
        }
        $arguments += @("--partition", $main)
    }
    $arguments += @("--namespace-routes", $namespaceRoutes)
}

foreach ($arch in $Architecture)
{
    $arguments += @("--arch", $arch)
}

if (!(Test-Path $tool))
{
    throw "windows-rs metadata tool was not found at $tool."
}

if ($useCheckedInPartitionInputs) {
    & "$PSScriptRoot\Prepare-WindowsRsHeaders.ps1" -ToolPath $tool -ToolArguments $arguments
    ThrowOnNativeProcessError
}
else {
    & $tool @arguments
    ThrowOnNativeProcessError
}

if ($coveragePath) {
    Write-Host "Generated extraction coverage report: $coveragePath"
}
else {
    Write-Host "Generated WinMD: $outputPath"
}
