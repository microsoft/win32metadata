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

    dotnet test "$rootDir\tests\MetadataUtils.Tests" -c Release --logger "console;verbosity=detailed" --logger "trx;LogFilePrefix=MetadataUtils.Tests" --results-directory "$binDir\logs\tests"
    ThrowOnNativeProcessError

    Write-Host "*** Running emitter tests..." -ForegroundColor Blue

    dotnet test "$rootDir\tests\ClangSharpSourceToWinmdTests" -c Release --logger "console;verbosity=detailed" --logger "trx;LogFilePrefix=ClangSharpSourceToWinmdTests" --results-directory "$binDir\logs\tests"
    ThrowOnNativeProcessError

    Write-Host "*** Running SDK annotation coverage auditor tests..." -ForegroundColor Blue

    & $pythonCommand -m unittest discover -s tests\SdkAnnotationCoverage.Tests -p "test_*.py"
    ThrowOnNativeProcessError

    Write-Host "*** Running scraper discovery tests..." -ForegroundColor Blue

    dotnet test "$rootDir\tests\Win32MetadataScraperTests" -c Release --logger "console;verbosity=detailed" --logger "trx;LogFilePrefix=Win32MetadataScraperTests" --results-directory "$binDir\logs\tests"
    ThrowOnNativeProcessError

    & "$PSScriptRoot\TestWinmdBinary.ps1" -SkipInstallTools
}
finally
{
    Pop-Location
}
