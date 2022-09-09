$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$toolsDir = "$rootDir\tools"
$binDir = "$rootDir\bin"
$sourcesDir = "$rootDir\sources"
$sdkApiPath = "$rootDir\ext\sdk-api"
$windowsWin32ProjectRoot = "$rootDir\generation\WinSDK"
$sdkGeneratedSourceDir = "$windowsWin32ProjectRoot\obj\generated"
$recompiledIdlHeadersDir = "$windowsWin32ProjectRoot\RecompiledIdlHeaders"
$metadataToolsBin = "$binDir\release\net6.0"

# [VS 1673159]
# Temporarily disable strict mode to address bug introduced
# in Visual Studio 17.1.0 that impacts vsdevshell launch
#
# Set-StrictMode -Version Latest

$ErrorActionPreference = "Stop"

# This messes up parallel loops
#$PSDefaultParameterValues['*:ErrorAction']='Stop'

function ThrowOnNativeProcessError
{
    if (-not $?)
    {
        $var = $?
        throw "Call to process exited with error"
    }
}

if (Test-Path -Path $binDir -PathType leaf)
{
    Remove-Item $binDir
}

if (!(Test-Path -Path $binDir))
{
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
}

function Create-Directory([string[]] $Path)
{
    if (!(Test-Path -Path $Path))
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
    }
}

function Remove-Directory([string[]] $Path)
{
    if ((Test-Path -Path $Path))
    {
        Remove-Item $Path -Recurse
    }
}

function Install-BuildTools
{
    Param([switch]$Clean)

    & "$PSScriptRoot\Install-DotNetTool" -Name nbgv

    if ($Clean.IsPresent)
    {
        & dotnet clean "$rootDir\buildtools"
    }

    & dotnet build "$rootDir\buildtools" -c Release "-bl:$PSScriptRoot\..\bin\logs\buildtools.binlog"
    ThrowOnNativeProcessError

    Install-VsDevShell
}

function Replace-Text
{
    Param ([string] $path, [hashtable] $items)

    $content = Get-Content -path $path -Encoding UTF8
    foreach ($key in $items.Keys)
    {
        $content = $content.Replace($key, $items[$key]);
    }

    Set-Content -path $path -Encoding UTF8 -value $content
}

function Get-LibMappingsFile
{
    $libMappingOutputFileName = Join-Path -Path $windowsWin32ProjectRoot -ChildPath "libMappings.rsp"

    return $libMappingOutputFileName
}

function Get-ChangesSinceLastReleaseFile
{
    return Join-Path $PSScriptRoot "ChangesSinceLastRelease.txt"
}

function Get-NugetPropsProperty
{
    Param ([string] $name, [string]$projectName)

    $projNameOnly = Split-Path -Path $projectName -LeafBase

    $ns = @{xlmns = "http://schemas.microsoft.com/developer/msbuild/2003"}
    $xpath = "//xlmns:$name"
    $item = Select-Xml -Path "$rootDir\obj\$projNameOnly\$projectName.nuget.g.props" -XPath $xpath -Namespace $ns
    return $item.node.InnerXml
}

function Get-BuildToolsNugetPropsProperty
{
    Param ([string] $name)

    return Get-NugetPropsProperty -name $name -projectName "BuildTools.proj"
}

function Get-WinSdkCppPkgPath
{
    return Get-BuildToolsNugetPropsProperty("PkgMicrosoft_Windows_SDK_CPP")
}

function Get-WinSdkCppX64PkgPath
{
    return Get-BuildToolsNugetPropsProperty("PkgMicrosoft_Windows_SDK_CPP_x64")
}

function Get-Win32MetadataLastReleaseWinmdPath
{
    $dir = Get-BuildToolsNugetPropsProperty("PkgMicrosoft_Windows_SDK_Win32Metadata")
    return Join-Path $dir "Windows.Win32.winmd"
}

function Invoke-PrepLibMappingsFile
{
    $libMappingOutputFileName = Get-LibMappingsFile
    if (!(Test-Path $libMappingOutputFileName))
    {
        $libPkgPath = Get-WinSdkCppX64PkgPath
        $libDirectory = "$libPkgPath\c\um\x64"

        Write-Host "Creating lib mapping file: $libMappingOutputFileName using $libDirectory"

        & $PSScriptRoot\CreateProcLibMappingForAllLibs.ps1 -libDirectory $libDirectory -outputFileName $libMappingOutputFileName
    }
}

function Invoke-RecompileMidlHeaders
{
    if (!(Test-Path $recompiledIdlHeadersDir))
    {
        $zipFile = "$scraperDir\RecompiledIdlHeaders.zip"
        if (Test-Path $zipFile)
        {
            Write-Host "Unzipping recompiled headers from $zipFile..."
            Expand-Archive $zipFile -DestinationPath $artifactsDir
            return
        }

        & $PSScriptRoot\RecompileIdlFilesForScraping.ps1 -sdkBinDir $sdkBinDir -includeDir $recompiledIdlHeadersDir

        Write-Host "Compressing headers to $zipFile..."
        Compress-Archive -Path $recompiledIdlHeadersDir -DestinationPath $zipFile
    }
}

function Get-VcDirPath
{
    param ($Arch = 'x64', $HostArch = 'x64')

    $installDir = & "$PSScriptRoot\Get-VSPath.ps1"
    try
    {
        $path = join-path $installDir 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt'
        if (test-path $path)
        {
            $version = Get-Content -raw $path
            if ($version)
            {
                $version = $version.Trim()
                $path = join-path $installDir "VC\Tools\MSVC\$version\bin\Host$HostArch\$Arch"
                return $path
            }
        }

        return $null
    }
    finally
    {
        # This doesn't need anything, but putting the script in a try block leads to it aborting
        # when a child script throws.
    }
}

function Install-VsDevShell
{
    if (!$env:VSINSTALLDIR)
    {
        $currentDir = Get-Location
        $installDir = & "$PSScriptRoot\Get-VSPath.ps1"
        $vsInstallScript = Join-Path $installDir "Common7\Tools\Launch-VsDevShell.ps1"

        & $vsInstallScript

        Set-Location $currentDir
    }
}

function Get-OutputWinmdFileName
{
    param ($Arch = 'x64')

    if ($Arch -ne "crossarch")
    {
        $path = "$binDir\Windows.Win32.$Arch.winmd"
    }
    else
    {
        $path = "$binDir\Windows.Win32.winmd"
    }

    return $path
}

function Download-Nupkg
{
    Param ([string] $name, [string] $version, [string] $outputDir)

    $url = "https://www.nuget.org/api/v2/package/$name/$version"
    $output = "$outputDir\$name.$version.nupkg"

    $wc = New-Object System.Net.WebClient
    $wc.DownloadFile($url, $output)
}

function Get-ExcludedItems
{
    param ([string[]]$rspFiles)
    [hashtable]$excludedItems = @{}

    $inExcluded = $false
    foreach ($rsp in $rspFiles)
    {
        foreach ($line in Get-Content $rsp)
        {
            if ($line.StartsWith('--'))
            {
                $inExcluded = $line -eq "--exclude"
            }
            else
            {
                if ($inExcluded)
                {
                    $excludedItems[$line] = $true
                }
            }
        }
    }

    return $excludedItems
}
