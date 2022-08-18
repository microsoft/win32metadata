param
(
    [switch]
    $SkipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$SkipInstallTools.IsPresent)
{
    Install-BuildTools
}

Write-Output "`e[36m*** Running tests on .winmd`e[0m"

$windowsWin32TestsDir = "$rootDir\tests\Windows.Win32.Tests"
dotnet test $windowsWin32TestsDir -c:Release
ThrowOnNativeProcessError

Write-Output "`n`e[32mTesting .winmd succeeded`e[0m"

Write-Output "`e[36m*** Comparing .winmd to last release`e[0m"

& "$PSScriptRoot\CompareBinToLastRelease.ps1" -SkipInstallTools

if ($LastExitCode -lt 0)
{
    exit -1
}

Write-Output "`n`e[32mComparing .winmd to last release succeeded`e[0m"

exit 0
