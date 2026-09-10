param(
    [switch]$UpdateGolden
)

$ErrorActionPreference = "Stop"
$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$sample = Join-Path $root "tests\GeneratorSdkPackageTests\sample"
$expected = Join-Path $root "tests\GeneratorSdkPackageTests\expected\SampleWinmd.apidump.cs"
$actual = Join-Path $root "obj\GeneratorSdkPackageTests\SampleWinmd.apidump.cs"
$packages = Join-Path $root "obj\GeneratorSdkPackageTests\packages"

dotnet pack (Join-Path $root "sources\GeneratorSdk\nuget\BuildSdk.proj") -c Release
if ($LASTEXITCODE -ne 0) {
    throw "Failed to pack Microsoft.Windows.WinmdGenerator."
}

$nupkg = Get-ChildItem (Join-Path $root "bin\Packages\Release\NuGet\Microsoft.Windows.WinmdGenerator.*.nupkg") |
    Sort-Object LastWriteTimeUtc -Descending |
    Select-Object -First 1
if (!$nupkg) {
    throw "The Microsoft.Windows.WinmdGenerator package was not produced."
}

$version = $nupkg.BaseName.Substring("Microsoft.Windows.WinmdGenerator.".Length)
$globalJson = @{
    "msbuild-sdks" = @{
        "Microsoft.Windows.WinmdGenerator" = $version
    }
} | ConvertTo-Json -Depth 4
[System.IO.File]::WriteAllText((Join-Path $sample "global.json"), $globalJson)

if (Test-Path $packages) {
    Remove-Item $packages -Recurse -Force
}
$env:NUGET_PACKAGES = $packages

dotnet build (Join-Path $sample "SampleWinmd.proj") -c Release "-p:RestoreConfigFile=$(Join-Path $sample 'NuGet.config')"
if ($LASTEXITCODE -ne 0) {
    throw "The consuming WinmdGenerator project failed."
}

dotnet build (Join-Path $root "sources\WinmdUtils\WinmdUtils.csproj") -c Release
if ($LASTEXITCODE -ne 0) {
    throw "Failed to build WinmdUtils."
}

New-Item -ItemType Directory -Force -Path (Split-Path $actual) | Out-Null
$winmd = Join-Path $sample "bin\SampleWinmd.winmd"
$assembly = [System.Reflection.AssemblyName]::GetAssemblyName($winmd)
if ($assembly.Name -ne "Sample.Metadata" -or $assembly.Version.ToString() -ne "1.2.3.4") {
    throw "Generated assembly identity was '$($assembly.Name), $($assembly.Version)'."
}

$winmdUtils = Join-Path $root "bin\Release\net10.0\WinmdUtils.dll"
dotnet $winmdUtils dump --winmd $winmd --output $actual
if ($LASTEXITCODE -ne 0) {
    throw "Failed to dump the generated WinMD."
}

if ($UpdateGolden) {
    New-Item -ItemType Directory -Force -Path (Split-Path $expected) | Out-Null
    Copy-Item $actual $expected -Force
    Write-Host "Updated $expected"
    exit 0
}

if (!(Test-Path $expected)) {
    throw "Golden file is missing. Run with -UpdateGolden after reviewing the generated dump."
}

$expectedText = [System.IO.File]::ReadAllText($expected).Replace("`r`n", "`n")
$actualText = [System.IO.File]::ReadAllText($actual).Replace("`r`n", "`n")
if ($expectedText -cne $actualText) {
    git --no-pager diff --no-index -- $expected $actual
    throw "Generated WinMD API dump does not match the golden file."
}

Write-Host "WinmdGenerator package integration test passed."
