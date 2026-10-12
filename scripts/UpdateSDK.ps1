[CmdletBinding()]
Param(
    [Parameter(Mandatory=$true)]
    [string]$Version
)

. "$PSScriptRoot\CommonUtils.ps1"

$propsPath = Resolve-Path (Join-Path $PSScriptRoot "..\eng\Versions.props")
$buildToolsProj = Resolve-Path (Join-Path $PSScriptRoot "..\BuildTools\BuildTools.proj")
$versionParts = $Version.Split(".")
if ($versionParts.Count -ne 4) {
    throw "SDK package version '$Version' must contain four numeric components."
}
$headerVersion = "$($versionParts[0]).$($versionParts[1]).$($versionParts[2]).0"

Write-Host "Updating authoritative SDK versions in $propsPath..."
$props = [System.IO.File]::ReadAllText($propsPath)
$props = [regex]::Replace(
    $props,
    "<WindowsSdkCppPackageVersion>[^<]+</WindowsSdkCppPackageVersion>",
    "<WindowsSdkCppPackageVersion>$Version</WindowsSdkCppPackageVersion>")
$props = [regex]::Replace(
    $props,
    "<WindowsSdkHeaderVersion>[^<]+</WindowsSdkHeaderVersion>",
    "<WindowsSdkHeaderVersion>$headerVersion</WindowsSdkHeaderVersion>")
[System.IO.File]::WriteAllText($propsPath, $props, [System.Text.UTF8Encoding]::new($false))

Write-Host "Rebuilding $buildToolsProj..."
dotnet build $buildToolsProj -t:Clean
ThrowOnNativeProcessError
dotnet restore $buildToolsProj --configfile (Join-Path $rootDir "nuget.Config")
ThrowOnNativeProcessError

$sdkRoot = Get-WinSdkCppPkgPath
$headerRoot = Join-Path $sdkRoot "c\include\$headerVersion"
if (!(Test-Path $headerRoot)) {
    throw "Microsoft.Windows.SDK.CPP $Version did not contain the expected header root '$headerRoot'."
}

Write-Host "Recompiling IDL files for scraping..."
. "$PSScriptRoot\RecompileIdlFilesForScraping.ps1"

Write-Host "SDK update complete. Import-library mappings are read directly by the Rust generator."