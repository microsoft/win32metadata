$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$winmdGeneratorSdkDir = Join-Path $rootDir "sources\msbuild"
$globalJson = Join-Path $rootDir "global.json"
$winmdGeneratorSdkVersion = nbgv get-version -v NuGetPackageVersion -p $winmdGeneratorSdkDir
$json = Get-Content $globalJson -raw | ConvertFrom-Json
$json."msbuild-sdks"."Microsoft.Windows.WinmdGenerator" = $winmdGeneratorSdkVersion
$json | ConvertTo-Json | Out-File $globalJson
Write-Host "Updated $globalJson to use $winmdGeneratorSdkVersion for WinmdGenerator SDK"

