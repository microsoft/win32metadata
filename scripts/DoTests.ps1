param
(
    [switch]$SkipInstallTools
)

. "$PSScriptRoot\CommonUtils.ps1"

Push-Location $rootDir
try
{
    $pythonCommand = Get-Command python -CommandType Application -ErrorAction Stop | Select-Object -First 1

    if (!$SkipInstallTools)
    {
        Install-BuildTools
    }

    Write-Host "*** Running metadata utils tests..." -ForegroundColor Blue

    dotnet test "$rootDir\tests\MetadataUtils.Tests" -c Release
    ThrowOnNativeProcessError

    Write-Host "*** Running emitter tests..." -ForegroundColor Blue

    dotnet test "$rootDir\tests\ClangSharpSourceToWinmdTests" -c Release
    ThrowOnNativeProcessError

    Write-Host "*** Running SDK annotation coverage auditor tests..." -ForegroundColor Blue

    & $pythonCommand -m unittest discover -s tests\SdkAnnotationCoverage.Tests -p "test_*.py"
    ThrowOnNativeProcessError

    Write-Host "*** Running scraper discovery tests..." -ForegroundColor Blue

    dotnet test "$rootDir\tests\Win32MetadataScraperTests" -c Release
    ThrowOnNativeProcessError

    & "$PSScriptRoot\TestWinmdBinary.ps1" -SkipInstallTools
}
finally
{
    Pop-Location
}
