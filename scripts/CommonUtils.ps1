function Create-Directory([string[]] $Path) 
{
    if (!(Test-Path -Path $Path)) 
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
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
    
    Write-Output "Creating metadata source for $partitionName..."
    if (!(Test-Path $libMappingOutputFileName))
    {
        Write-Output "Creating lib mapping file: $libMappingOutputFileName"
        $libDirectory = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version\c\um\x64"
        & $PSScriptRoot\CreateProcLibMappingForAllLibs.ps1 -libDirectory $libDirectory -outputFileName $libMappingOutputFileName
    }
}
    
$defaultWinSDKNugetVersion = "10.0.19041.5"

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$toolsDir = "$rootDir\tools"
$binDir = "$rootDir\bin"
$outputWinmdFileName = "$binDir\Windows.Win32.winmd"
$sourcesDir = "$rootDir\sources"
$partitionsDir = "$rootDir\generation\Partitions"
$sdkApiPath = "$rootDir\ext\sdk-api"
$sdkGeneratedSourceDir = "$sourcesDir\Win32MetadataSource\generated"

if (Test-Path -Path $binDir -PathType leaf)
{
    Remove-Item $binDir
}

if (!(Test-Path -Path $binDir))
{
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
}
