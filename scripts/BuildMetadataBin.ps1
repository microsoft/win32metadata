param
(
    [string]
    $assemblyVersion,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "x64"
)

$scraperArch = $arch
if ($arch -eq "crossarch")
{
    $scraperArch = "x64"
}

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Building .winmd`e[0m"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
}

& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1 -arch $scraperArch

$constantsScraperPath = "$sourcesDir\ConstantsScraper"
$constantsScraperProj = "$constantsScraperPath\ConstantsScraper.csproj"
$constantsScraperPathBin = "$constantsScraperPath\bin\Release\netcoreapp3.1\ConstantsScraper.dll"
& dotnet build $constantsScraperProj -c Release
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}

$clangSharpSourceToWinmdPath = "$sourcesDir\ClangSharpSourceToWinmd"
$clangSharpSourceToWinmdProj = "$clangSharpSourceToWinmdPath\ClangSharpSourceToWinmd.csproj"
$clangSharpSourceToWinmdBin = "$clangSharpSourceToWinmdPath\bin\Release\netcoreapp3.1\ClangSharpSourceToWinmd.dll"
& dotnet build $clangSharpSourceToWinmdProj -c Release
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}

$metadataInteropPath = "$sourcesDir\Win32MetadataInterop"
$metadataInteropProj = "$metadataInteropPath\Win32MetadataInterop.csproj"
$metadataInteropBin = "$metadataInteropPath\bin\Release\netstandard2.1\Windows.Win32.Interop.dll"
& dotnet build $metadataInteropProj -c Release
if ($LastExitCode -ne 0)
{
    exit $LastExitCode
}

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


Write-Output "`n"
Write-Output "Scraping constants and enums..."
Write-Output "Calling: dotnet $constantsScraperPathBin --repoRoot $rootDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName"

& dotnet $constantsScraperPathBin --repoRoot $rootDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName
if ($LastExitCode -ne 0)
{
    Write-Error "Failed to scrape constants."
    exit $LastExitCode
}

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Output "`n"
Write-Output "Creating $outputWinmdFileName..."
Write-Output "Calling: dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --arch $arch --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp"

& dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --arch $arch --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp
if ($LastExitCode -ne 0)
{
    Write-Error "Failed to build .winmd."
    exit $LastExitCode
}

Write-Output "`n`e[32mGenerating .winmd succeeded`e[0m"
