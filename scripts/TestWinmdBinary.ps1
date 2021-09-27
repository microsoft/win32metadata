param
(
    [string]
    $winmdPath,

    [switch]
    $skipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$skipInstallTools.IsPresent)
{
    Install-BuildTools
}

Write-Output "`e[36m*** Running tests on .winmd`e[0m"

$windowsWin32TestsDir = "$rootDir\tests\Windows.Win32.Tests"
dotnet test $windowsWin32TestsDir -c:Release
ThrowOnNativeProcessError

if (!$winmdPath)
{
    $winmdPath = Get-OutputWinmdFileName -arch "crossarch"
}

$baselineWinmd = "$PSScriptRoot\BaselineWinmd\Windows.Win32.winmd"
$winmdUtilsPathBin = "$metadataToolsBin\WinmdUtils.dll"

Write-Output "`n"
Write-Output "Comparing $winmdPath against baseline $baselineWinmd..."
Write-Output "Calling: dotnet $winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath"
& dotnet $winmdUtilsPathBin compare --first $baselineWinmd --second $winmdPath
if ($LastExitCode -lt 0)
{
    Write-Output "If all the differences are expected, please update the baseline by doing this:`ncopy $winmdPath $baselineWinmd"
    exit -1
}

Write-Output "`n`e[32mTesting .winmd succeeded`e[0m"
