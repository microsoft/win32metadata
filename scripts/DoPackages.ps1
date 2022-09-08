param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Packing packages..." -ForegroundColor Blue

dotnet pack "$PSScriptRoot\..\sources\packages.proj" -c Release
ThrowOnNativeProcessError

& "$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

dotnet clean "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release
dotnet pack "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release
ThrowOnNativeProcessError
