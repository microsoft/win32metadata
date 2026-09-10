<#
.SYNOPSIS
    Generates a WinMD directly from selected SDK-header partitions with windows-rs.

.PARAMETER Partition
    Partition names under generation\WinSDK\Partitions. Defaults to every partition.

.PARAMETER Architecture
    Target architectures to scrape and merge. Defaults to x64, x86, and arm64.

.PARAMETER OutputWinmd
    Output WinMD path.

.PARAMETER SkipBuild
    Use the previously built Rust executable.
#>
[CmdletBinding()]
param (
    [string[]]$Partition = @(),

    [ValidateSet("x64", "arm64", "x86")]
    [string[]]$Architecture = @("x64", "x86", "arm64"),

    [string]$OutputWinmd = "$PSScriptRoot\..\bin\Windows.Win32.winmd",

    [switch]$SkipBuild
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"
$manifest = Join-Path $rootDir "tools\rust\Cargo.toml"
$tool = Join-Path $rootDir "tools\rust\target\release\win32metadata-tools.exe"
$headerRoot = Join-Path $windowsWin32ProjectRoot "RecompiledIdlHeaders"
$localIncludes = Join-Path $windowsWin32ProjectRoot "inc"
$outputPath = [System.IO.Path]::GetFullPath($OutputWinmd)
$outputStem = [System.IO.Path]::GetFileNameWithoutExtension($outputPath)
$objDir = Join-Path $windowsWin32ProjectRoot "obj\windows-rs\$outputStem"

if (!(Test-Path $headerRoot))
{
    throw "Patched SDK headers were not found at $headerRoot. Run scripts\RecompileIdlFilesForScraping.ps1 first."
}

if (!$SkipBuild.IsPresent)
{
    & cargo build --release --locked --manifest-path $manifest
    ThrowOnNativeProcessError
}

if (!(Test-Path "$rootDir\obj\BuildTools.proj\BuildTools.proj.nuget.g.props"))
{
    & dotnet restore "$rootDir\BuildTools\BuildTools.proj" --configfile "$rootDir\nuget.Config" --verbosity quiet
    ThrowOnNativeProcessError
}

$sdkLibRoot = Join-Path (Get-WinSdkCppX64PkgPath) "c\um\x64"

if ($Partition.Count -eq 0)
{
    $Partition = Get-ChildItem (Join-Path $windowsWin32ProjectRoot "Partitions") -Directory |
        Where-Object { Test-Path (Join-Path $_.FullName "main.cpp") } |
        Sort-Object Name |
        Select-Object -ExpandProperty Name
}

Write-Host "Generating $($Partition.Count) partition(s) for $($Architecture -join ', ')"

$arguments = @(
    "scrape",
    "--include", $localIncludes,
    "--include", $headerRoot,
    "--lib", $sdkLibRoot,
    "--output", $outputPath,
    "--obj", $objDir
)

foreach ($name in $Partition)
{
    $main = Join-Path $windowsWin32ProjectRoot "Partitions\$name\main.cpp"
    if (!(Test-Path $main))
    {
        throw "Partition '$name' was not found at $main."
    }
    $arguments += @("--partition", $main)
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
