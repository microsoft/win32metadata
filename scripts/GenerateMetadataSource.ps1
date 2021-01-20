
param
(
    [string]
    $artifactsDir,

    [string]
    $pipelineRunName,

    [bool]
    $downloadDefaultCppNugets = $true,

    [string]
    $downloadNugetVersion,

    [string]
    $publishNugetVersion,

    [bool]
    $exitAfterFindVersion = $false,

    [string]
    $patch = ""
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$pipelineRunName)
{
    $pipelineRunName = $defaultWinSDKNugetVersion.Substring("10.0.".Length) + ".branchname.date-time"
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
    $artifactsDir = "$rootDir\artifacts"
    Create-Directory $artifactsDir
}

Write-Output "Making sure cpp NuGet packages are installed..."

$nugetSrcPackagesDir = Join-Path -Path $artifactsDir "NuGetPackages"
Create-Directory $nugetSrcPackagesDir

$parts = $pipelineRunName.Split(".")
$build = $parts[0]
$qfe = $parts[1]
$branch = $parts[2].Replace("_", "-")
$potentialVersions = "10.0.$build.$qfe-preview.$branch", "10.0.$build.$qfe-preview", "10.0.$build.*"
$version = $null

if ($null -ne $downloadNugetVersion)
{
    $potentialVersions = $downloadNugetVersion
}

foreach ($ver in $potentialVersions)
{
    Write-Output "Looking for: $nugetSrcPackagesDir\Microsoft.Windows.SDK.CPP.$ver.nupkg..."
    $cppPkg = Get-ChildItem -path $nugetSrcPackagesDir -Include Microsoft.Windows.SDK.CPP.$ver.nupkg -recurse
    if ($cppPkg)
    {
        $version = $cppPkg.BaseName.Substring("Microsoft.Windows.SDK.CPP.".Length)
        Write-Output "Found NuGet package, version: $version"
        break;
    }
}

if (!$version)
{
    if ($downloadNugetVersion)
    {
        $version = $downloadNugetVersion
    }
    else 
    {
        if (!$downloadDefaultCppNugets)
        {
            Write-Output "Error: Couldn't find cpp package in $nugetSrcPackagesDir. Call script with downloadDefaultCppNugets = 1 to download default packages."
            exit -1
        }

        $version = $defaultWinSDKNugetVersion
    }

    Write-Output "No cpp nuget packages found at $nugetSrcPackagesDir. Downloading $version from nuget.org..."

    Download-Nupkg "Microsoft.Windows.SDK.CPP" $version $nugetSrcPackagesDir
    Download-Nupkg "Microsoft.Windows.SDK.CPP.x64" $version $nugetSrcPackagesDir
}

$nugetSrcPackagesDir = Join-Path -Path $artifactsDir "NuGetPackages"
Create-Directory $nugetSrcPackagesDir

if (!$publishNugetVersion)
{
    $publishNugetVersion = $version

    # patch is an auto-increment counter specific to the pipeline name.
    # If it's set...
    if ($patch -ne "")
    {
        # If this is a preview build, just append the patch to the end of the version
        if ($version.Contains("-preview"))
        {
            $publishNugetVersion = "$version.$patch"
        }
        # If this isn't a preview build, we want to replace the build QFE with the patch
        else
        {
            $buildParts = $version.Split("{.}")
            $qfePart = $buildParts[3]
            $qfeParts = $qfePart.Split("{-}")
            $qfe = $qfeOverride
            if ($qfeParts.Length -eq 2)
            {
                $qfeExtra = $qfeParts[1]
                $qfe = "$qfe-$qfeExtra"
            }
        
            $buildParts[3] = $patch
    
            $publishNugetVersion = [string]::Join(".", $buildParts)
        }
    }
}

# Write variable in the Azure DevOps pipeline for use in subsequent tasks
Write-Output "##vso[task.setvariable variable=PrepOutput.NugetVersion;]$publishNugetVersion"

if ($exitAfterFindVersion)
{
    exit 0
}

$x64Pkg = Get-ChildItem -path "$nugetSrcPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version.nupkg"
if (!$x64Pkg)
{
    Write-Output "Error: Couldn't find cpp x64 package: $x64Pkg."
    exit -1
}

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"
Create-Directory $nugetDestPackagesDir
& $toolsDir\nuget.exe install Microsoft.Windows.SDK.CPP.x64 -version $version -source $nugetSrcPackagesDir -OutputDirectory $nugetDestPackagesDir

# Clean up directory where generated source files go
Create-Directory $sdkGeneratedSourceDir
Remove-Item "$sdkGeneratedSourceDir\*.cs"

Invoke-PrepLibMappingsFile $artifactsDir $version

$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

$partitionNames = Get-ChildItem $partitionsDir | Select-Object -ExpandProperty Name

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

Write-Output "`nProcessing each partition...using $throttleCount parallel script(s)"

$partitionNames | ForEach-Object -Parallel {
    $out1 = "`n$using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir..."
    $out2 = & $using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir -indent "`n  "
    Write-Output "$out1$out2"
} -ThrottleLimit $throttleCount

$stopwatch.Stop()
$totalTime = $stopwatch.Elapsed.ToString("c")

Write-Output "Total time taken for all partitions: $totalTime"

exit 0
