
param
(
    [string]
    $artifactsDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..\artifacts"),

    [string]
    $version,

    [string]
    $partitionName
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$version)
{
    $version = $defaultWinSDKNugetVersion
}

$generationOutArtifactsDir = "$artifactsDir\output"
Create-Directory $generationOutArtifactsDir

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"

$libMappingOutputFileName = Join-Path -Path $generationOutArtifactsDir -ChildPath "$version.libMappings.rsp"

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

Write-Output "Creating metadata source for $partitionName..."
if (!(Test-Path $libMappingOutputFileName))
{
    Write-Output "Creating lib mapping file: $libMappingOutputFileName"
    $libDirectory = "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.x64.$version\c\um\x64"
    & $PSScriptRoot\CreateProcLibMappingForAllLibs.ps1 -libDirectory $libDirectory -outputFileName $libMappingOutputFileName
}
else
{
    Write-Output "Skipping creating of lib mappings as $libMappingOutputFileName already exists."
}

$baseGenerateDir = "$rootDir\generation"
$partitionGenerateDir = "$rootDir\generation\Partitions\$partitionName"
if (!(Test-Path $partitionGenerateDir))
{
    Write-Error "Partition dir $partitionGenerateDir not found."
    exit -1
}

$generatorOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$partitionName.generation.output.txt"

$withSetLastErrorRsp = "$baseGenerateDir\WithSetLastError.rsp"

$baseSettingsRsp = "$baseGenerateDir\baseSettings.rsp"
$partitionSettingsRsp = "$partitionGenerateDir\settings.rsp"
if (!(Test-Path $partitionSettingsRsp))
{
    Write-Error "Partition settings $partitionSettingsRsp not found."
    exit -1
}

$baseRemapRsp = "$baseGenerateDir\baseRemap.rsp"
#$partitionRemapRsp = "$partitionGenerateDir\remap.rsp"

$fixedSettingsRsp = "$generationOutArtifactsDir\$partitionName.fixedSettings.rsp"

Copy-Item $partitionSettingsRsp -Destination $fixedSettingsRsp

$includePath = (Get-ChildItem -Path "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\Include").FullName.Replace('\', '/')
[hashtable]$textToReplaceTable = @{ "<IncludeRoot>" = $includePath; "<RepoRoot>" = $rootDir; "<PartitionName>" = $partitionName }
Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Output "Creating metadata .cs file. Log output: $generatorOutput"
Write-Output "Calling: $toolsDir\ClangSharpPInvokeGenerator.exe "@$baseSettingsRsp" "@$withSetLastErrorRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$libMappingOutputFileName" > $generatorOutput"

& $toolsDir\ClangSharpPInvokeGenerator.exe "@$baseSettingsRsp" "@$withSetLastErrorRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$libMappingOutputFileName" > $generatorOutput
if ($LASTEXITCODE -lt 0)
{
    Write-Error "ClangSharpPInvokeGenerator.exe failed:"
    Get-ChildItem $generatorOutput | select-string "Error: "
}

$possibleRemapsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$partitionName.possibleremaps.output.txt"
& $PSScriptRoot\DisplayPossibleMappings.ps1 -generatorResults $generatorOutput -remapsFile $possibleRemapsOutput

$from = Get-Content -Path $possibleRemapsOutput
if (![string]::IsNullOrEmpty($from))
{
    Add-Content -Path $baseRemapRsp -Value $from
    Write-Output "Added remaps to $baseRemapRsp"
}

$stopwatch.Stop()
$totalTime = $stopwatch.Elapsed.ToString("c")
Write-Output "Took $totalTime"
