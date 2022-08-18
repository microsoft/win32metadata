param
(
    [switch]$SkipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Output "`e[36m*** Running metadata utils tests...`e[0m"

dotnet test "$PSScriptRoot\..\tests\MetadataUtils.Tests" -c Release
ThrowOnNativeProcessError

& $PSScriptRoot\TestWinmdBinary.ps1 -SkipInstallTools

