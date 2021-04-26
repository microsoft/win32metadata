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
    param ([string]$artifactsDir, [string]$version)

    $generationOutArtifactsDir = "$artifactsDir\output"
    Create-Directory $generationOutArtifactsDir

    $libMappingOutputFileName = Join-Path -Path $generationOutArtifactsDir -ChildPath "$version.libMappings.rsp"

    return $libMappingOutputFileName
}

function Invoke-PrepLibMappingsFile
{
    param ([string]$artifactsDir, [string]$version)

    $libMappingOutputFileName = Get-LibMappingsFile $artifactsDir $version
    
    if (!(Test-Path $libMappingOutputFileName))
    {
        Write-Output "Creating lib mapping file: $libMappingOutputFileName"
        $libDirectory = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version\c\um\x64"
        & $PSScriptRoot\CreateProcLibMappingForAllLibs.ps1 -libDirectory $libDirectory -outputFileName $libMappingOutputFileName
    }
}

function Invoke-RecompileMidlHeaders
{
    param ([string]$artifactsDir, [string]$version)

    $headersDir = "$artifactsDir\output\$version\headers"

    if (!(Test-Path $headersDir))
    {
        Write-Output "Recompiling midl headers with SAL annotations to $headersDir"
        
        $sdkParts = $version.Split('.')
        $sdkVersion = "$($sdkParts[0]).$($sdkParts[1]).$($sdkParts[2]).0"
        $sdkIncludeDir = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\include\$sdkVersion"
        $sdkBinDir = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\bin\$sdkVersion\x86"
        & $PSScriptRoot\RecompileIdlFilesForScraping.ps1 -sdkBinDir $sdkBinDir -includeDir $sdkIncludeDir -outputDir $headersDir
    }
}

function Get-VcDirPath
{
    param ($Arch = 'x64', $HostArch = 'x64')

    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    $installDir = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if ($installDir) 
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
    }

    return null
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

function Get-ExternalPackageVersion([string] $artifactsDir, [string] $packageName)
{

    $packagePaths = Get-ChildItem -Directory -Path "$artifactsDir\InstalledPackages\$packageName.*"
    $installedVersions = $packagePaths | ForEach-Object { [version]$_.Name.Substring("$packageName.".Length) }
    [string]$latestVersion = $installedVersions | Sort-Object -Bottom 1

    return $latestVersion
}
   
$defaultWinSDKNugetVersion = "10.0.19041.5"

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$toolsDir = "$rootDir\tools"
$binDir = "$rootDir\bin"
$sourcesDir = "$rootDir\sources"
$generationDir = "$rootDir\generation"
$scraperDir = "$generationDir\scraper"
$emitterDir = "$generationDir\emitter"
$partitionsDir = "$scraperDir\Partitions"
$sdkApiPath = "$rootDir\ext\sdk-api"
$sdkGeneratedSourceDir = "$emitterDir\generated"
$defaultArtifactsDir = "$rootDir\artifacts"

if (Test-Path -Path $binDir -PathType leaf)
{
    Remove-Item $binDir
}

if (!(Test-Path -Path $binDir))
{
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
}
