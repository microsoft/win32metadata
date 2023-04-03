$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$winmdGeneratorSdkDir = Join-Path $rootDir "sources\GeneratorSdk"
$globalJson = Join-Path $rootDir "global.json"
$samplesGlobalJson = Join-Path $winmdGeneratorSdkDir "samples\global.json"

$winmdGeneratorSdkVersion = nbgv get-version -v NuGetPackageVersion -p $winmdGeneratorSdkDir
$json = Get-Content $globalJson -raw | ConvertFrom-Json
$json."msbuild-sdks"."Microsoft.Windows.WinmdGenerator" = $winmdGeneratorSdkVersion
$json | ConvertTo-Json | Out-File $samplesGlobalJson
Write-Host "Updated $samplesGlobalJson to use $winmdGeneratorSdkVersion for WinmdGenerator SDK"

$sdkMetadataPackageVersion = nbgv get-version -v NuGetPackageVersion -p $rootDir
$diaSdkPackageNuspec = Join-Path $winmdGeneratorSdkDir "\samples\DiaSdk\Microsoft.Dia.Win32Metadata.nuspec"
(Get-Content $diaSdkPackageNuspec) -Replace "<dependency id=""Microsoft.Windows.SDK.Win32Metadata"".*",
                                            "<dependency id=""Microsoft.Windows.SDK.Win32Metadata"" version=""$sdkMetadataPackageVersion"" />" |
Set-Content $diaSdkPackageNuspec
Write-Host "Updated $diaSdkPackageNuspec to use $sdkMetadataPackageVersion for Win32Metadata dependency"

