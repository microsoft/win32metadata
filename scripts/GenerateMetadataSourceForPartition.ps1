
param
(
    [string]
    $partitionName,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch",

    [string]
    $indent = "",

    [switch]$parallel
)

if ($arch -eq "crossarch")
{
    Write-Output "Scraping $($indent)$partitionName for all architectures..."

    if ($parallel)
    {
        $throttleCount = [System.Environment]::ProcessorCount / 2
        if ($throttleCount -lt 2)
        {
            $throttleCount = 2
        }
    }
    else
    {
        $throttleCount = 1
    }

    $errObj = new-object psobject
    Add-Member -InputObject $errObj -MemberType NoteProperty -Name ErrorCode -Value 0

    "x64", "x86", "arm64" | ForEach-Object -Parallel { 
        $out = & $using:PSCommandPath -partitionName $using:partitionName -arch $_ -indent "`n  "
        Write-Output "$out"

        if ($LastExitCode -lt 0)
        {
            Write-Error "Partition $_ failed for $_."
            $localObj.ErrorCode = $LastExitCode
        }
    } -ThrottleLimit $throttleCount

    if ($errObj.ErrorCode -ne 0)
    {
        exit $errObj.ErrorCode
    }

    exit 0
}

if (($arch -eq "x64") -or ($arch -eq "arm64"))
{
    $bitness = 64
}
else
{
    $bitness = 32
}

. "$PSScriptRoot\CommonUtils.ps1"

$libMappingOutputFileName = Get-LibMappingsFile
if (!(Test-Path $libMappingOutputFileName))
{
    Write-Error "$libMappingOutputFileName not found. Please create it using Invoke-PrepLibMappingsFile in CommonUtils.ps1."
    exit -1
}

$stopwatch =  [system.diagnostics.stopwatch]::StartNew()

$baseGenerateDir = "$rootDir\generation\scraper"
$partitionGenerateDir = "$baseGenerateDir\partitions\$partitionName"
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
$headerFile = "$baseGenerateDir\header.txt"
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

$includePath = $recompiledIdlHeadersDir
$generatedSourceDir = "$rootDir\generation\emitter\generated\$arch"
[hashtable]$textToReplaceTable = @{ "<IncludeRoot>" = $includePath; "<RepoRoot>" = $rootDir; "<PartitionName>" = $partitionName; "<PartitionDir>" = $partitionGenerateDir; "<GeneratedSourceDir>" = $generatedSourceDir}
Replace-Text $fixedSettingsRsp $textToReplaceTable

Write-Output "$($indent)$partitionName for $arch..."
Write-Output "$($indent)ClangSharpPInvokeGenerator @$baseSettingsRsp --headerFile $headerFile @$baseSettingsBitnessRsp @$baseSettingsArchRsp @$withSetLastErrorRsp @$supportedOSRsp @$fixedSettingsRsp @$baseRemapRsp @$autoTypesRemapRsp @$functionPointerFixupsRsp @$libMappingOutputFileName > $generatorOutput"

& ClangSharpPInvokeGenerator "@$baseSettingsRsp" --headerFile "$headerFile" "@$baseSettingsBitnessRsp" "@$baseSettingsArchRsp" "@$withSetLastErrorRsp" "@$supportedOSRsp" "@$fixedSettingsRsp" "@$baseRemapRsp" "@$autoTypesRemapRsp" "@$functionPointerFixupsRsp" "@$libMappingOutputFileName" > $generatorOutput
if ($LASTEXITCODE -lt 0)
{
    Write-Error "$($indent)ClangSharpPInvokeGenerator failed, full output at $generatorOutput`:"
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
