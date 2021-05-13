param
(
    [string]
    $winmdPath
)

. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

Write-Output "`e[36m*** Running tests on .winmd`e[0m"

if (!$winmdPath)
{
    $winmdPath = Get-OutputWinmdFileName -arch "crossarch"
}

$baselineWinmd = "$PSScriptRoot\BaselineWinmd\Windows.Win32.winmd"

$winmdUtilsPathBin = "$metadataToolsBin\WinmdUtils.dll"

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
Write-Output "Calling: dotnet $winmdUtilsPathBin showEmptyDelegates --winmd $winmdPath @$allowedEmptyDelegatesFileName"
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
Write-Output "Comparing $winmdPath against baseline $baselineWinmd..."
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
