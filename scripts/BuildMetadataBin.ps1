param
(
    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch",

    [switch]$SkipConstants = $false,

    [switch]$SkipBinary = $false
)

$scraperArch = $arch
if ($arch -eq "crossarch")
{
    $scraperArch = "x64"
}

. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

$assemblyVersion = nbgv get-version -v AssemblyVersion

& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1 -arch $scraperArch

$constantsScraperPathBin = "$metadataToolsBin\ConstantsScraper.dll"
$clangSharpSourceToWinmdBin = "$metadataToolsBin\ClangSharpSourceToWinmd.dll"

$metadataInteropPath = "$sourcesDir\Win32MetadataInterop"
$metadataInteropBin = "$metadataInteropPath\bin\Release\netstandard2.1\Windows.Win32.Interop.dll"

Copy-Item $metadataInteropBin $binDir

$remapFileName = "$emitterDir\remap.rsp"
$emitterGeneratedDir = "$emitterDir\generated\$scraperArch"
$enumsRemapFileName = "$emitterGeneratedDir\enumsRemap.rsp"
$autoTypesFileName = "$emitterDir\autoTypes.rsp"
$requiredNamespacesForNames = "$emitterDir\requiredNamespacesForNames.rsp"
$functionPointerFixupsRsp = "$emitterGeneratedDir\functionPointerFixups.generated.rsp"
$enumsMakeFlagsRsp = "$emitterGeneratedDir\enumsMakeFlags.generated.rsp"

$constantsScraperRsp = "$scraperDir\ConstantsScraper.rsp"
$constantsHeaderTxt = "$scraperDir\ConstantsHeader.txt"
$enumsJson = "$scraperDir\enums.json"


if (!$SkipConstants)
{
    Write-Output "`n"
    Write-Output "`e[36m*** Scraping constants and enums...`e[0m"
    Write-Output "Calling: dotnet $constantsScraperPathBin --repoRoot $rootDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName"

    & dotnet $constantsScraperPathBin --repoRoot $rootDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName
    if ($LastExitCode -ne 0)
    {
        Write-Error "Failed to scrape constants."
        exit $LastExitCode
    }
}

if (!$SkipBinary)
{
    $outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

    Write-Output "`n"
    Write-Output "`e[36m*** Creating $outputWinmdFileName...`e[0m"
    Write-Output "Calling: dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --arch $arch --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp"

    & dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --arch $arch --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp
    if ($LastExitCode -ne 0)
    {
        Write-Error "Failed to build .winmd."
        exit $LastExitCode
    }

    Write-Output "`n`e[32mGenerating .winmd succeeded`e[0m"
}
