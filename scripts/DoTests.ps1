param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Output "`e[36m*** Running tests...`e[0m"

dotnet test "$PSScriptRoot\..\tests\MetadataUtils.Tests" -c Release
ThrowOnNativeProcessError

& $PSScriptRoot\TestWinmdBinary.ps1
