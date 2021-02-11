
param
(
    [string]
    $artifactsDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..\artifacts"),

    [string]
    $version,

    [string]
    $partitionName,

    [string]
    $indent = ""
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$version)
{
    $version = $defaultWinSDKNugetVersion
}

$nugetDestPackagesDir = Join-Path -Path $artifactsDir "InstalledPackages"

$libMappingOutputFileName = Get-LibMappingsFile $artifactsDir $version

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

$baseGenerateDir = "$rootDir\generation"
$partitionGenerateDir = "$rootDir\generation\Partitions\$partitionName"
if (!(Test-Path $partitionGenerateDir))
{
    Write-Error "Partition dir $partitionGenerateDir not found."
    exit -1
}

$generationOutArtifactsDir = "$artifactsDir\output"

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

$fixedSettingsRsp = "$generationOutArtifactsDir\$partitionName.fixedSettings.rsp"

Copy-Item $partitionSettingsRsp -Destination $fixedSettingsRsp

$includePath = (Get-ChildItem -Path "$nugetDestPackagesDir\Microsoft.Windows.SDK.CPP.$version\c\Include").FullName.Replace('\', '/')
[hashtable]$textToReplaceTable = @{ "<IncludeRoot>" = $includePath; "<RepoRoot>" = $rootDir; "<PartitionName>" = $partitionName }
Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Output "$($indent)$partitionName..."
Write-Output "$($indent)$toolsDir\ClangSharpPInvokeGenerator.exe @$baseSettingsRsp @$withSetLastErrorRsp @$fixedSettingsRsp @$baseRemapRsp @$libMappingOutputFileName > $generatorOutput"

& $toolsDir\ClangSharpPInvokeGenerator.exe "@$baseSettingsRsp" "@$withSetLastErrorRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$libMappingOutputFileName" > $generatorOutput
if ($LASTEXITCODE -lt 0)
{
    Write-Error "$($indent)ClangSharpPInvokeGenerator.exe failed, full output at $generatorOutput`:"
    $errText = (Get-ChildItem $generatorOutput | select-string "Error: ") -join "`r`n"
    Write-Error $errText
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
