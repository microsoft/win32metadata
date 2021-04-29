. "$PSScriptRoot\CommonUtils.ps1"

$artifactsDir = $defaultArtifactsDir

$nugetSrcPackagesDir = Join-Path -Path $artifactsDir "NuGetPackages"
Create-Directory $nugetSrcPackagesDir

$version = $defaultWinSDKNugetVersion

$nugetPackageFile = "$nugetSrcPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version.nupkg"

if (!(Test-Path -Path $nugetPackageFile))
{
    Write-Output "Downloading package Microsoft.Windows.SDK.CPP.x64 $version..."
    Download-Nupkg "Microsoft.Windows.SDK.CPP.x64" $version $nugetSrcPackagesDir
}

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"
Create-Directory $nugetDestPackagesDir
& $toolsDir\nuget.exe install Microsoft.Windows.SDK.CPP.x64 -version $version -source $nugetSrcPackagesDir -OutputDirectory $nugetDestPackagesDir

Invoke-PrepLibMappingsFile $version
