param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Packing Docs..." -ForegroundColor Blue

dotnet pack "$PSScriptRoot\..\apidocs\Microsoft.Windows.SDK.Win32Docs" -c Release --no-build -p:BuildProjectReferences=false

ThrowOnNativeProcessError