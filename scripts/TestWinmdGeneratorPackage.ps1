#Requires -Version 7.0
param
(
    [string]$PackagePath
)

$ErrorActionPreference = 'Stop'
$root = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
if (!$PackagePath)
{
    $version = & nbgv get-version -v NuGetPackageVersion -p "$root\sources\GeneratorSdk"
    if ($LASTEXITCODE -ne 0)
    {
        throw 'Unable to determine the just-built WinmdGenerator package version.'
    }

    $PackagePath = "$root\bin\Packages\Release\NuGet\Microsoft.Windows.WinmdGenerator.$version.nupkg"
}

if (!(Test-Path -LiteralPath $PackagePath -PathType Leaf))
{
    throw "Build the WinmdGenerator package first (dotnet pack sources\GeneratorSdk\nuget\BuildSdk.proj -c Release). Missing package: $PackagePath"
}

$previousPackage = $env:WINMD_GENERATOR_PACKAGE_PATH
try
{
    $env:WINMD_GENERATOR_PACKAGE_PATH = (Resolve-Path -LiteralPath $PackagePath).Path
    Write-Host "*** Testing WinmdGenerator package: $env:WINMD_GENERATOR_PACKAGE_PATH" -ForegroundColor Blue
    & dotnet test "$root\tests\WinmdGenerator.IntegrationTests" -c Release --logger trx "--results-directory=$root\bin\logs\WinmdGeneratorIntegration"
    if ($LASTEXITCODE -ne 0)
    {
        throw 'WinmdGenerator package integration tests failed.'
    }
}
finally
{
    $env:WINMD_GENERATOR_PACKAGE_PATH = $previousPackage
}
