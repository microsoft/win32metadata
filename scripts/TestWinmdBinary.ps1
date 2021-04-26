param
(
    [string]
    $assemblyVersion,

    [string]
    $winmdPath
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Running tests on .winmd`e[0m"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
}

if (!$winmdPath)
{
    $winmdPath = Get-OutputWinmdFileName -arch "crossarch"
}

function FindBestBaselineWinmd
{
    param([int] $buildNumber)

    $bestDir = ""
    $versionNames = get-childitem $PSScriptRoot\BaselineWinmd
    foreach ($versionDir in $versionNames)
    {
        $baselineVersion = [int]($versionDir.Name.Split(".")[2])
        if ($baselineVersion -gt $buildNumber)
        {
            break
        }

        $bestDir = $versionDir.Name
    }

    return $bestDir
}

$buildNumber = [int]($assemblyVersion.Split(".")[2])
$baselineWinmdDir = FindBestBaselineWinmd $buildNumber
if ($baselineWinmdDir -eq "")
{
    Write-Output "Failed to find a baseline winmd to compare against."
    exit 0
}

$baselineWinmd = "$PSScriptRoot\BaselineWinmd\$baselineWinmdDir\Windows.Win32.winmd"

$winmdUtilsPath = "$sourcesDir\WinmdUtils"
$winmdUtilsPathProj = "$winmdUtilsPath\WinmdUtils.csproj"
$winmdUtilsPathBin = "$winmdUtilsPath\bin\Release\netcoreapp3.1\WinmdUtils.dll"
& dotnet build $winmdUtilsPathProj -c Release
if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}

$failed = $false

Write-Output "`nLooking for duplicate imports in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateImports --winmd $winmdPath"
& dotnet $winmdUtilsPathBin showDuplicateImports --winmd $winmdPath
if (!$failed -and $LastExitCode -lt 0)
{
    $failed = $true
}

Write-Output "`nLooking for duplicate types in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath"
& dotnet $winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath
if (!$failed -and $LastExitCode -lt 0)
{
    $failed = $true
}

Write-Output "`nLooking for duplicate constants in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath"
& dotnet $winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath
if (!$failed -and $LastExitCode -lt 0)
{
    $failed = $true
}

$allowedEmptyDelegatesFileName = "$rootDir\tests\emptyDelegatesAllowList.rsp"
Write-Output "`nLooking for empty delegates in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath @$allowedEmptyDelegatesFileName"
& dotnet $winmdUtilsPathBin showEmptyDelegates --winmd $winmdPath @$allowedEmptyDelegatesFileName
if (!$failed -and $LastExitCode -lt 0)
{
    $failed = $true
}

$pointersToDelegatesAllowListFileName = "$rootDir\tests\pointersToDelegatesAllowList.rsp"
Write-Output "`nLooking for pointers to delegates in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showPointersToDelegates --winmd $winmdPath @$pointersToDelegatesAllowListFileName"
& dotnet $winmdUtilsPathBin showPointersToDelegates --winmd $winmdPath @$pointersToDelegatesAllowListFileName
if (!$failed -and $LastExitCode -lt 0)
{
    $failed = $true
}

Write-Output "`n"
Write-Output "Comparing $outputWinmdFileName against baseline $baselineWinmd..."
Write-Output "Calling: dotnet $winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath"
& dotnet $winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath
if (!$failed -and $LastExitCode -lt 0)
{
    Write-Output "If all the differences are expected, please update the baseline by doing this:`ncopy $winmdPath $baselineWinmd"
    $failed = $true
}

if ($failed)
{
    exit -1
}

Write-Output "`n`e[32mTesting .winmd succeeded`e[0m"

# Test external winmd binaries in parallel
$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

Write-Output "`Running tests on each external .winmd...using $throttleCount parallel script(s)"

$generationDir = "$rootDir\external"
$scraperDir = "$generationDir\scraper"
$partitionsDir = "$scraperDir\Partitions"
$externalBaselineDir = "$PSScriptRoot\BaselineWinmd\external"

$partitionNames = Get-ChildItem -Directory $partitionsDir | Select-Object -ExpandProperty Name

$partitionNames | ForEach-Object -Parallel {
    Write-Output "`e[36m*** Running tests on $_.winmd`e[0m"

    $winmdPath = "$using:binDir\$_.winmd"
    $baselineWinmd = "$using:externalBaselineDir\$_.winmd"

    $failed = $false

    Write-Output "`nLooking for duplicate imports in $_.winmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin showDuplicateImports --winmd $winmdPath"
    & dotnet $using:winmdUtilsPathBin showDuplicateImports --winmd $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        $failed = $true
    }
    
    Write-Output "`nLooking for duplicate types in $_.winmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath"
    & dotnet $using:winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        $failed = $true
    }
    
    Write-Output "`nLooking for duplicate constants in $_.winmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath"
    & dotnet $using:winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        $failed = $true
    }
    
    Write-Output "`nLooking for empty delegates in $_.winmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin showDuplicateConstants --winmd $winmdPath"
    & dotnet $using:winmdUtilsPathBin showEmptyDelegates --winmd $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        $failed = $true
    }
    
    Write-Output "`nLooking for pointers to delegates in $_.winmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin showPointersToDelegates --winmd $winmdPath"
    & dotnet $using:winmdUtilsPathBin showPointersToDelegates --winmd $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        $failed = $true
    }
    
    Write-Output "`n"
    Write-Output "Comparing $winmdPath against baseline $baselineWinmd..."
    Write-Output "Calling: dotnet $using:winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath"
    & dotnet $using:winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath
    if (!$failed -and $LastExitCode -lt 0)
    {
        Write-Output "If all the differences are expected, please update the baseline by doing this:`ncopy $winmdPath $baselineWinmd"
        $failed = $true
    }
    
    if ($failed)
    {
        exit -1
    }
        
    Write-Output "`n`e[32mTesting $_.winmd succeeded`e[0m"
} -ThrottleLimit $throttleCount