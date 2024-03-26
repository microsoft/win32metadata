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

& "$PSScriptRoot\UpdateSampleDependencies.ps1"

dotnet clean "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release


& "C:\Program Files\Microsoft Visual Studio\2022\Enterprise\Common7\Tools\VsDevCmd.bat"

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release

dir -S "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk"

Get-Content "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk\obj\dia2.idl"

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release

dotnet pack "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release
ThrowOnNativeProcessError
