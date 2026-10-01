<#
.SYNOPSIS
    Generates a WinMD from the pinned raw Windows SDK headers with windows-rs.

.PARAMETER Partition
    Optional partition names under generation\WinSDK\Partitions for a focused run.
    By default, uses the upstream aggregate + satellite SDK header manifest.

.PARAMETER Architecture
    Target architectures to scrape and merge. Defaults to x64, x86, and arm64.

.PARAMETER UsePartitionAuthority
    Generate from every checked-in WinSDK partition translation unit and settings file.

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

    [switch]$UsePartitionAuthority,

    [string]$OutputWinmd = "$PSScriptRoot\..\bin\Windows.Win32.winmd",

    [ValidateNotNullOrEmpty()]
    [string]$Namespace = "Windows.Win32",

    [switch]$SkipBuild
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"
$tool = Join-Path $rootDir "bin\GeneratorSdk\tools\win-x64\win32metadata-tools.exe"
$outputPath = [System.IO.Path]::GetFullPath($OutputWinmd)
$outputStem = [System.IO.Path]::GetFileNameWithoutExtension($outputPath)
$objDir = Join-Path $windowsWin32ProjectRoot "obj\windows-rs\$outputStem"

if (!(Test-Path "$rootDir\obj\BuildTools.proj\BuildTools.proj.nuget.g.props"))
{
    & dotnet restore "$rootDir\BuildTools\BuildTools.proj" --configfile "$rootDir\nuget.Config" --verbosity quiet
    ThrowOnNativeProcessError
}

$sdkPackageRoot = Get-WinSdkCppPkgPath
$headerRoot = Join-Path $sdkPackageRoot "c\include\$(Get-WinSdkHeaderVersion)"
$includePaths = @(
    if ($UsePartitionAuthority.IsPresent) {
        Join-Path $windowsWin32ProjectRoot "RecompiledIdlHeaders"
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

$sdkLibRoot = Join-Path (Get-WinSdkCppX64PkgPath) "c\um\x64"
$assemblyVersion = nbgv get-version -v AssemblyVersion
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

if ($UsePartitionAuthority.IsPresent -and $Partition.Count -ne 0) {
    throw "-UsePartitionAuthority cannot be combined with -Partition."
}
$useSdkHeaderManifest = $Partition.Count -eq 0 -and !$UsePartitionAuthority.IsPresent
if ($UsePartitionAuthority.IsPresent)
{
    Write-Host "Generating all checked-in partition translation units for $($Architecture -join ', ')"
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
    "--lib", $sdkLibRoot,
    "--namespace", $Namespace,
    "--assembly-name", $outputStem,
    "--assembly-version", $assemblyVersion,
    "--output", $outputPath,
    "--obj", $objDir
)

foreach ($include in $includePaths)
{
    $arguments += @("--include", $include)
}

if ($UsePartitionAuthority.IsPresent)
{
    $arguments += @(
        "--win32-sdk",
        "--partition-root", (Join-Path $windowsWin32ProjectRoot "Partitions")
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
}

foreach ($arch in $Architecture)
{
    $arguments += @("--arch", $arch)
}

if (!(Test-Path $tool))
{
    throw "windows-rs metadata tool was not found at $tool."
}

& $tool @arguments
ThrowOnNativeProcessError

Write-Host "Generated WinMD: $outputPath"
