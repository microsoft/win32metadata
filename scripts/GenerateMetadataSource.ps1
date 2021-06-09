param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [bool]
    $exitAfterFindVersion = $false,

    [bool]
    $keepProcessingOnFailure = $false
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Generating source files: $arch`e[0m"

Install-BuildTools

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
Write-Output "ClangSharpPInvokeGenerator resolved to $((Get-Command ClangSharpPInvokeGenerator).Path)"

$errObj = new-object psobject
Add-Member -InputObject $errObj -MemberType NoteProperty -Name ErrorCode -Value 0

$partitionNames | ForEach-Object -Parallel {
    $localObj = $using:errObj
    if (($keepProcessingOnFailure -eq $false) -and ($localObj.ErrorCode -ne 0))
    {
        continue
    }

    $out1 = "`n$using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -partitionName $_..."
    $out2 = & $using:PSScriptRoot\GenerateMetadataSourceForPartition.ps1 -arch $using:arch -partitionName $_ -indent "`n  "
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
