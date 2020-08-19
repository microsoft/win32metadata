
param
(
    [string]
    $artifactsDir,

    [bool]
    $downloadDefaultCppNugets = $true
)

function Create-Directory([string[]] $Path) 
{
    if (!(Test-Path -Path $Path)) 
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
    }
}

function Download-Nupkg
{
    Param ([string] $name, [string] $version, [string] $outputDir)

    $url = "https://www.nuget.org/api/v2/package/$name/$version"
    $output = "$outputDir\$name.$version.nupkg"

    $wc = New-Object System.Net.WebClient
    $wc.DownloadFile($url, $output)
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

if (!$artifactsDir)
{
    $artifactsDir = Join-Path -Path $env:TEMP "win32metdata_artifacts"
    Create-Directory $artifactsDir
}

$nugetSrcPackagesDir = Join-Path -Path $artifactsDir "NuGetPackages"
Create-Directory $nugetSrcPackagesDir

$cppPkg = Get-ChildItem -path $nugetSrcPackagesDir -Include Microsoft.Windows.SDK.CPP.10.*.nupkg -recurse
if (!$cppPkg)
{
    if (!$downloadDefaultCppNugets)
    {
        Write-Host "Error: Couldn't find cpp package in $nugetSrcPackagesDir. Call script with downloadDefaultCppNugets = 1 to download default packages."
        exit -1
    }
    else
    {
        $version = "10.0.18362.3-preview"

        Write-Host "No cpp nuget packages found at $nugetSrcPackagesDir. Downloading $version from nuget.org..."

        Download-Nupkg "Microsoft.Windows.SDK.CPP" $version $nugetSrcPackagesDir
        Download-Nupkg "Microsoft.Windows.SDK.CPP.x64" $version $nugetSrcPackagesDir
        $cppPkg = Get-ChildItem -path $nugetSrcPackagesDir -Include Microsoft.Windows.SDK.CPP.10.*.nupkg -recurse
    }
}
else
{
    $prefix = "Microsoft.Windows.SDK.CPP."
    $suffix = ".nupkg"
    $version = $cppPkg.Name.Substring($prefix.Length, $cppPkg.Name.Length - $prefix.Length - $suffix.Length)
}

# Write variable in the Azure DevOps pipeline for use in subsequent tasks
Write-Host "##vso[task.setvariable variable=PrepOutput.NugetVersion;]$version"

$x64Pkg = Get-ChildItem -path "$nugetSrcPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version.nupkg"
if (!$x64Pkg)
{
    Write-Host "Error: Couldn't find cpp x64 package: $x64Pkg."
    exit -1
}

$toolsDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..\tools")

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"
Create-Directory $nugetDestPackagesDir
& $toolsDir\nuget.exe install Microsoft.Windows.SDK.CPP.x64 -version $version -source $nugetSrcPackagesDir -OutputDirectory $nugetDestPackagesDir

$generationOutArtifactsDir = "$artifactsDir\output"
Create-Directory $generationOutArtifactsDir

$libMappingOutputFileName = Join-Path -Path $generationOutArtifactsDir -ChildPath "libMappings.rsp"

Write-Host "Creating lib mapping file: $libMappingOutputFileName"
$onecoreLibPath = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version\c\um\x64\OneCore.lib"
& $PSScriptRoot\CreateProcLibMapping.ps1 -onecoreLibPath $onecoreLibPath -outputFileName $libMappingOutputFileName

$repoRoot = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")

$generateDir = "$repoRoot\generation"
$generatorOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "generation.output.txt"

Copy-Item "$generateDir\settings.rsp" -Destination $generationOutArtifactsDir
$fixedSettingsRsp = Join-Path -Path $generationOutArtifactsDir -ChildPath "settings.rsp"

$includePath = (Get-ChildItem -Path "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\Include").FullName.Replace('\', '/')
[hashtable]$textToReplaceTable = @{ "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0" = $includePath; "D:\repos\win32metadata" = $repoRoot }
Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Host "Creating metdata .cs file. Log output: $generatorOutput"
Write-Host "Calling: $toolsDir\ClangSharpPInvokeGenerator.exe @$generateDir\remap.rsp @$fixedSettingsRsp @$libMappingOutputFileName 2>&1 > $generatorOutput"

$oldLoc = Get-Location
Set-Location $toolsDir
& $toolsDir\ClangSharpPInvokeGenerator.exe "@$generateDir\remap.rsp" "@$fixedSettingsRsp" "@$libMappingOutputFileName" 2>&1 > $generatorOutput
Set-Location $oldLoc

$missedFuncsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "missedfuncs.output.txt"
& $PSScriptRoot\CheckMissedFuncs.ps1 -generatorResults $generatorOutput -mappingFile $libMappingOutputFileName -missedFuncsFile $missedFuncsOutput

