
param
(
    [string]
    $artifactsDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..\artifacts"),

    [string]
    $version,

    [string]
    $libName
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$version)
{
    $version = $defaultWinSDKNugetVersion
}

$generationOutArtifactsDir = "$artifactsDir\output"
Create-Directory $generationOutArtifactsDir

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"

$libMappingOutputFileName = Join-Path -Path $generationOutArtifactsDir -ChildPath "$libName.libMappings.rsp"

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

Write-Host "Creating metadata source for $libName.lib..."
if (!(Test-Path -Path $libMappingOutputFileName))
{
    Write-Host "Creating lib mapping file: $libMappingOutputFileName"
    $libPath = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version\c\um\x64\$libName.lib"
    & $PSScriptRoot\CreateProcLibMapping.ps1 -libPath $libPath -outputFileName $libMappingOutputFileName
}

$baseGenerateDir = "$rootDir\generation"
$libGenerateDir = "$rootDir\generation\ImportLibs\$libName"
$generatorOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$libName.generation.output.txt"

$withSetLastErrorRsp = "$baseGenerateDir\WithSetLastError.rsp"

$baseSettingsRsp = "$baseGenerateDir\baseSettings.rsp"
$libSettingsRsp = "$libGenerateDir\settings.rsp"

$baseRemapRsp = "$baseGenerateDir\baseRemap.rsp"
$libRemapRsp = "$libGenerateDir\remap.rsp"

$fixedSettingsRsp = "$generationOutArtifactsDir\$libName.fixedSettings.rsp"

Copy-Item $libSettingsRsp -Destination $fixedSettingsRsp

$includePath = (Get-ChildItem -Path "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\Include").FullName.Replace('\', '/')
[hashtable]$textToReplaceTable = @{ "C:/Program Files (x86)/Windows Kits/10/Include/10.0.19041.0" = $includePath; "D:\repos\win32metadata" = $rootDir }
Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Host "Creating metdata .cs file. Log output: $generatorOutput"
Write-Host "Calling: $toolsDir\ClangSharpPInvokeGenerator.exe @$baseSettingsRsp "@$withSetLastErrorRsp" @$fixedSettingsRsp @$baseRemapRsp @$libRemapRsp @$libMappingOutputFileName > $generatorOutput"

& $toolsDir\ClangSharpPInvokeGenerator.exe "@$baseSettingsRsp" "@$withSetLastErrorRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$libRemapRsp" "@$libMappingOutputFileName" > $generatorOutput
if ($LASTEXITCODE -lt 0)
{
    Write-Error "ClangSharpPInvokeGenerator.exe failed:"
    Get-ChildItem $generatorOutput | select-string "Error: "
}

#$missedFuncsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$libName.missedfuncs.output.txt"
#$visitedFuncsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$libName.visitedfuncs.output.txt"
#& $PSScriptRoot\CheckMissedFuncs.ps1 -generatorResults $generatorOutput -mappingFile $libMappingOutputFileName -visitedFuncsFile $visitedFuncsOutput -missedFuncsFile $missedFuncsOutput

$possibleRemapsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$libName.possibleremaps.output.txt"
& $PSScriptRoot\DisplayPossibleMappings.ps1 -generatorResults $generatorOutput -remapsFile $possibleRemapsOutput

$stopwatch.Stop()
$totalTime = $stopwatch.Elapsed.ToString("c")
Write-Host "Took $totalTime"
