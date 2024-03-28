param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Building Docs..." -ForegroundColor Blue

dotnet clean "$PSScriptRoot\..\apidocs" -c Release

dotnet build "$PSScriptRoot\..\apidocs" -c Release

ThrowOnNativeProcessError