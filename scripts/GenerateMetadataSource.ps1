
param
(
    [string]
    $artifactsDir,

    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

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

    [bool]
    $keepProcessingOnFailure = $false,

    [string]
    $patch = "",

    [switch]
    $externalOnly
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$pipelineRunName)
{
    $pipelineRunName = $defaultWinSDKNugetVersion.Substring("10.0.".Length) + ".branchname.date-time"
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
    $artifactsDir = $defaultArtifactsDir
}

Create-Directory $artifactsDir

Write-Output "`e[36m*** Generating source files: $arch`e[0m"

Write-Output "Making sure cpp NuGet packages are installed..."

$nugetSrcPackagesDir = Join-Path -Path $artifactsDir "NuGetPackages"
Create-Directory $nugetSrcPackagesDir

$parts = $pipelineRunName.Split(".")
$build = $parts[0]
$qfe = $parts[1]
$branch = $parts[2].Replace("_", "-")
$potentialVersions = "10.0.$build.$qfe-preview.$branch", "10.0.$build.$qfe-preview", "10.0.$build.*"
$version = $null

if ($downloadNugetVersion)
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

    Write-Output "No cpp nuget package found at $nugetSrcPackagesDir. Downloading $version from nuget.org..."

    Download-Nupkg "Microsoft.Windows.SDK.CPP" $version $nugetSrcPackagesDir
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

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"
Create-Directory $nugetDestPackagesDir
& $toolsDir\nuget.exe install Microsoft.Windows.SDK.CPP -version $version -source $nugetSrcPackagesDir -OutputDirectory $nugetDestPackagesDir

# Restore all of the external NuGet packages
& $toolsDir\nuget.exe restore "$rootDir\external\scraper\packages.config" -PackagesDirectory $nugetDestPackagesDir

# Clean up directory where generated source files go
Create-Directory $sdkGeneratedSourceDir
Remove-Item "$sdkGeneratedSourceDir\*.cs"

Invoke-RecompileMidlHeaders $artifactsDir $version

& $PSScriptRoot\CreateScraperRspForAutoTypes.ps1 -arch $arch
& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1 -arch $arch

$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

if (!$externalOnly)
{
    $partitionNames = Get-ChildItem $partitionsDir | Select-Object -ExpandProperty Name

    $stopwatch =  [system.diagnostics.stopwatch]::StartNew()

    Write-Output "`nProcessing each partition...using $throttleCount parallel script(s)"

    $errObj = new-object psobject
    Add-Member -InputObject $errObj -MemberType NoteProperty -Name ErrorCode -Value 0

    $partitionNames | ForEach-Object -Parallel {
        $localObj = $using:errObj
        if (($keepProcessingOnFailure -eq $false) -and ($localObj.ErrorCode -ne 0))
        {
            continue
        }

        $out1 = "`n$using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir..."
        $out2 = & $using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir -indent "`n  "
        Write-Output "$out1$out2"

        if ($LastExitCode -lt 0)
        {
            Write-Error "Partition $_ failed."
            $localObj.ErrorCode = $LastExitCode
        }
    
    } -ThrottleLimit $throttleCount

    if ($errObj.ErrorCode -ne 0)
    {
        Write-Error "Failed to scrape one or more partitions."
        exit $errObj.ErrorCode
    }

    $stopwatch.Stop()
    $totalTime = $stopwatch.Elapsed.ToString("c")

    Write-Output "Total time taken for all partitions: $totalTime"

    Write-Output "`n`e[32mGenerating source files succeeded`e[0m"
}

$generationDir = "$rootDir\external"
$scraperDir = "$generationDir\scraper"
$emitterDir = "$generationDir\emitter"
$partitionsDir = "$scraperDir\Partitions"

# Clean up directory where generated source files go
$externalGeneratedSourceDir = "$emitterDir\generated"
Create-Directory $externalGeneratedSourceDir
Remove-Item "$externalGeneratedSourceDir\*.cs"

& $PSScriptRoot\CreateScraperRspForAutoTypes.ps1 -arch $arch -isExternal
& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1 -arch $arch -isExternal

$partitionNames = Get-ChildItem $partitionsDir | Select-Object -ExpandProperty Name

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

Write-Output "`nProcessing each external partition...using $throttleCount parallel script(s)"

$errObj = new-object psobject
Add-Member -InputObject $errObj -MemberType NoteProperty -Name ErrorCode -Value 0

$partitionNames | ForEach-Object -Parallel {
    $localObj = $using:errObj
    if (($keepProcessingOnFailure -eq $false) -and ($localObj.ErrorCode -ne 0))
    {
        continue
    }

    $out1 = "`n$using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir -isExternal..."
    $out2 = & $using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_ -artifactsDir $using:artifactsDir -indent "`n  " -isExternal
    Write-Output "$out1$out2"

    if ($LastExitCode -lt 0)
    {
        Write-Error "Partition $_ failed."
        $localObj.ErrorCode = $LastExitCode
    }
    
} -ThrottleLimit $throttleCount

if ($errObj.ErrorCode -ne 0)
{
    Write-Error "Failed to scrape one or more external partitions."
    exit $errObj.ErrorCode
}

$stopwatch.Stop()
$totalTime = $stopwatch.Elapsed.ToString("c")

Write-Output "Total time taken for all external partitions: $totalTime"

Write-Output "`n`e[32mGenerating external source files succeeded`e[0m"

exit 0
