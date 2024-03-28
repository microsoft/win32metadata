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

dotnet clean "$PSScriptRoot\..\apidocs\ApiDocs.sln" -c Release

dotnet build "$PSScriptRoot\..\apidocs\ApiDocs.sln" -c Release

ThrowOnNativeProcessError