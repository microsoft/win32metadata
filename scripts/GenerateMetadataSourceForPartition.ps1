
param
(
    [string]
    $artifactsDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..\artifacts"),

    [string]
    $version,

    [string]
    $partitionName,

    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [string]
    $indent = "",

    [switch]
    $isExternal
)

if (($arch -eq "x64") -or ($arch -eq "arm64"))
{
    $bitness = 64
}
else
{
    $bitness = 32
}

. "$PSScriptRoot\CommonUtils.ps1"

if (!$version)
{
    $version = $defaultWinSDKNugetVersion
}

if ($isExternal)
{
    $generationDir = "$rootDir\external"
    $scraperDir = "$generationDir\scraper"
    $emitterDir = "$generationDir\emitter"
    $partitionsDir = "$scraperDir\Partitions"
}

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"

$libMappingOutputFileName = Get-LibMappingsFile $version
if (!(Test-Path $libMappingOutputFileName))
{
    Write-Error "$libMappingOutputFileName not found. Please create it using CreateProcLibMappings.ps1."
    exit -1
}

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

$baseGenerateDir = "$scraperDir"
$partitionGenerateDir = "$partitionsDir\$partitionName"
if (!(Test-Path $partitionGenerateDir))
{
    Write-Error "Partition dir $partitionGenerateDir not found."
    exit -1
}

$generationOutArtifactsDir = "$baseGenerateDir\obj\$arch"
Create-Directory $generationOutArtifactsDir

$generatorOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$partitionName.generation.output.txt"

$withSetLastErrorRsp = "$baseGenerateDir\WithSetLastError.rsp"
$supportedOSRsp = "$baseGenerateDir\supportedOS.rsp"

$baseSettingsRsp = "$baseGenerateDir\baseSettings.rsp"
$baseSettingsBitnessRsp = "$baseGenerateDir\baseSettings.$bitness.rsp"
$baseSettingsArchRsp = "$baseGenerateDir\baseSettings.$arch.rsp"
$partitionSettingsRsp = "$partitionGenerateDir\settings.rsp"
if (!(Test-Path $partitionSettingsRsp))
{
    Write-Error "Partition settings $partitionSettingsRsp not found."
    exit -1
}

$baseRemapRsp = "$baseGenerateDir\baseRemap.rsp"
$autoTypesRemapRsp = "$baseGenerateDir\obj\$arch\autoTypes.generated.rsp"
$functionPointerFixupsRsp = "$baseGenerateDir\obj\$arch\functionPointerFixups.generated.rsp"

$fixedSettingsRsp = "$generationOutArtifactsDir\$partitionName.fixedSettings.rsp"

Copy-Item $partitionSettingsRsp -Destination $fixedSettingsRsp

$includePath = (Get-ChildItem -Path "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\Include").FullName.Replace('\', '/')
$generatedSourceDir = "$emitterDir\generated\$arch"
[hashtable]$textToReplaceTable = @{ "<IncludeRoot>" = $includePath; "<RepoRoot>" = $rootDir; "<PartitionName>" = $partitionName; "<PartitionDir>" = $partitionGenerateDir; "<GeneratedSourceDir>" = $generatedSourceDir}

if ($isExternal)
{
    . "$PSScriptRoot\ExternalPackageUtils.ps1"
    $latestVersion = Get-ExternalPackageVersion $artifactsDir $partitionName
    $externalPackagePath = "$nugetDestPackagesDir\$partitionName.$latestVersion".Replace('\', '/')
    $textToReplaceTable["<ExternalPackageDir>"] = $externalPackagePath
}

Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Output "$($indent)$partitionName..."
Write-Output "$($indent)$toolsDir\ClangSharpPInvokeGenerator.exe @$baseSettingsRsp @$baseSettingsBitnessRsp @$baseSettingsArchRsp @$withSetLastErrorRsp @$supportedOSRsp @$fixedSettingsRsp @$baseRemapRsp @$autoTypesRemapRsp @$functionPointerFixupsRsp @$libMappingOutputFileName > $generatorOutput"

& $toolsDir\ClangSharpPInvokeGenerator.exe "@$baseSettingsRsp" "@$baseSettingsBitnessRsp" "@$baseSettingsArchRsp" "@$withSetLastErrorRsp" "@$supportedOSRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$autoTypesRemapRsp" "@$functionPointerFixupsRsp" "@$libMappingOutputFileName" > $generatorOutput
if ($LASTEXITCODE -lt 0)
{
    Write-Error "$($indent)ClangSharpPInvokeGenerator.exe failed, full output at $generatorOutput`:"
    $errText = (Get-ChildItem $generatorOutput | select-string "Error: ") -join "`r`n"
    Write-Error $errText

    exit $LastExitCode
}

$possibleRemapsOutput = Join-Path -Path $generationOutArtifactsDir -ChildPath "$partitionName.possibleremaps.output.txt"
& $PSScriptRoot\DisplayPossibleMappings.ps1 -generatorResults $generatorOutput -remapsFile $possibleRemapsOutput

$from = Get-Content -Path $possibleRemapsOutput
if (![string]::IsNullOrEmpty($from))
{
    Add-Content -Path $baseRemapRsp -Value $from
    Write-Output "$($indent)Added remaps to $baseRemapRsp"
}

$stopwatch.Stop()
$totalTime = $stopwatch.Elapsed.ToString("c")
Write-Output "$($indent)Took $totalTime"
