param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [string]
    $publishNugetVersion,

    [bool]
    $exitAfterFindVersion = $false,

    [bool]
    $keepProcessingOnFailure = $false,

    [string]
    $patch = ""
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Generating source files: $arch`e[0m"

Install-BuildTools

$version = $defaultWinSDKNugetVersion

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

# Clean up directory where generated source files go
Create-Directory $sdkGeneratedSourceDir
Remove-Item "$sdkGeneratedSourceDir\*.cs"

Invoke-RecompileMidlHeaders

& $PSScriptRoot\CreateScraperRspForAutoTypes.ps1 -arch $arch
& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1 -arch $arch

$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

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

    $out1 = "`n$using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_..."
    $out2 = & $using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -version $using:version -partitionName $_ -indent "`n  "
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

exit 0
