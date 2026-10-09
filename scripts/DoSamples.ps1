param
(
    [switch]$skipInstallTools
)

Write-Host "*** Testing the packaged WinmdGenerator sample..." -ForegroundColor Blue

& "$PSScriptRoot\Test-GeneratorSdkPackage.ps1"
