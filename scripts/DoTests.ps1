param
(
    [switch]$SkipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Running metadata utils tests..." -ForegroundColor Blue

dotnet test "$PSScriptRoot\..\tests\MetadataUtils.Tests" -c Release
ThrowOnNativeProcessError

& $PSScriptRoot\TestWinmdBinary.ps1 -SkipInstallTools
