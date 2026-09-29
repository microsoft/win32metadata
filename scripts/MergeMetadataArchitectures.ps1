param
(
    [string]
    $InputRoot = "$PSScriptRoot\..\generation\WinSDK\obj\arch-inputs",

    [string]
    $OutputWinmd = "$PSScriptRoot\..\bin\Windows.Win32.winmd",

    [string]
    $OutputRdl = "$PSScriptRoot\..\generation\WinSDK\obj\winmd\rdl",

    [string]
    $AssemblyVersion,

    [switch]
    $SkipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools
}

$tool = Join-Path $rootDir "bin\GeneratorSdk\tools\win-x64\win32metadata-tools.exe"
if (!(Test-Path $tool))
{
    throw "WinmdGenerator tool was not found at $tool."
}

$inputRootPath = [System.IO.Path]::GetFullPath($InputRoot)
$outputWinmdPath = [System.IO.Path]::GetFullPath($OutputWinmd)
$outputRdlPath = [System.IO.Path]::GetFullPath($OutputRdl)
if (!$AssemblyVersion)
{
    $AssemblyVersion = nbgv get-version -v AssemblyVersion
}

if (Test-Path $outputRdlPath)
{
    throw "The output RDL path already exists: $outputRdlPath"
}
if (Test-Path $outputWinmdPath)
{
    throw "The output WinMD already exists: $outputWinmdPath"
}

$arguments = @("merge-arch")
foreach ($arch in @("x64", "x86", "arm64"))
{
    $artifactRoot = Join-Path $inputRootPath "generated_$arch"
    $rdl = Join-Path $artifactRoot "rdl"
    $winmd = Join-Path $artifactRoot "Windows.Win32.$arch.winmd"
    if (!(Test-Path $rdl -PathType Container))
    {
        throw "The $arch RDL artifact was not found at $rdl."
    }
    if (!(Test-Path $winmd -PathType Leaf))
    {
        throw "The $arch WinMD artifact was not found at $winmd."
    }

    $arguments += @("--arch", $arch, "--rdl", $rdl, "--winmd", $winmd)
}

$arguments += @(
    "--namespace", "Windows.Win32",
    "--assembly-name", "Windows.Win32",
    "--assembly-version", $AssemblyVersion,
    "--output-rdl", $outputRdlPath,
    "--output-winmd", $outputWinmdPath
)

& $tool @arguments
ThrowOnNativeProcessError

Write-Host "Merged WinMD: $outputWinmdPath"
