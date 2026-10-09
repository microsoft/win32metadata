param
(
    [switch]$skipInstallTools,
    [switch]$skipNativeToolsBuild
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Packing packages..." -ForegroundColor Blue

$packArgs = @("pack", "$PSScriptRoot\..\sources\packages.proj", "-c", "Release")
if ($skipNativeToolsBuild) {
    $packArgs += "-p:SkipNativeToolsBuild=true"
}
dotnet @packArgs
ThrowOnNativeProcessError

Install-BuildTools
