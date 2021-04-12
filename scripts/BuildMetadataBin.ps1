param
(
    [string]
    $assemblyVersion,

    [switch]
    $externalOnly
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Building .winmd`e[0m"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
}

& $PSScriptRoot\CreateRspsForFunctionPointerFixups.ps1

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
$enumsRemapFileName = "$emitterDir\generated\enumsRemap.rsp"
$autoTypesFileName = "$emitterDir\autoTypes.rsp"
$requiredNamespacesForNames = "$emitterDir\requiredNamespacesForNames.rsp"
$functionPointerFixupsRsp = "$emitterDir\functionPointerFixups.generated.rsp"
$enumsMakeFlagsRsp = "$emitterDir\enumsMakeFlags.generated.rsp"

$constantsScraperRsp = "$scraperDir\ConstantsScraper.rsp"
$constantsHeaderTxt = "$scraperDir\ConstantsHeader.txt"
$manualEnumsJson = "$scraperDir\manualEnums.json"
$enumsJson = "$scraperDir\enums.json"

if (!$externalOnly)
{
    Write-Output "`n"
    Write-Output "Scraping constants and enums..."
    Write-Output "Calling: dotnet $constantsScraperPathBin --repoRoot $rootDir --enumsJson $manualEnumsJson --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName"

    & dotnet $constantsScraperPathBin --repoRoot $rootDir --enumsJson $manualEnumsJson --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName
    if ($LastExitCode -ne 0)
    {
        Write-Error "Failed to scrape constants."
        exit $LastExitCode
    }

    Write-Output "`n"
    Write-Output "Creating $outputWinmdFileName..."
    Write-Output "Calling: dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp"

    & dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName @$enumsRemapFileName @$functionPointerFixupsRsp @$enumsMakeFlagsRsp
    if ($LastExitCode -ne 0)
    {
        Write-Error "Failed to build .winmd."
        exit $LastExitCode
    }

    Write-Output "`n`e[32mGenerating .winmd succeeded`e[0m"
}

# Generate external winmd binaries in parallel
$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

Write-Output "`nProcessing each external partition...using $throttleCount parallel script(s)"

$generationDir = "$rootDir\external"
$scraperDir = "$generationDir\scraper"
$emitterDir = "$generationDir\emitter"
$partitionsDir = "$scraperDir\Partitions"

$remapFileName = "$emitterDir\remap.rsp"
$autoTypesFileName = "$emitterDir\autoTypes.rsp"
$functionPointerFixupsRsp = "$emitterDir\functionPointerFixups.generated.rsp"

$partitionNames = Get-ChildItem -Directory $partitionsDir | Select-Object -ExpandProperty Name

$partitionNames | ForEach-Object -Parallel {
    # Reimport CommonUtils.ps1 to get access to Get-ExternalPackageVersion in this scope
    . "$using:PSScriptRoot\CommonUtils.ps1"

    $assemblyVersion = Get-ExternalPackageVersion $defaultArtifactsDir $_

    Write-Output "`n"
    Write-Output "Creating "$binDir\$_.winmd"..."
    Write-Output "Calling: dotnet $using:clangSharpSourceToWinmdBin --sourceDir $using:emitterDir --interopFileName $using:metadataInteropBin --baseMetadataFileName $using:outputWinmdFileName --outputNamespace "$_" --outputFileName "$using:binDir\$_.winmd" --version "$assemblyVersion" @$using:remapFileName @$using:requiredNamespacesForNames @$using:autoTypesFileName @$using:enumsRemapFileName @$using:functionPointerFixupsRsp @$using:enumsMakeFlagsRsp"

    & dotnet $using:clangSharpSourceToWinmdBin --sourceDir $using:emitterDir --interopFileName $using:metadataInteropBin --baseMetadataFileName $using:outputWinmdFileName --outputNamespace "$_" --outputFileName "$using:binDir\$_.winmd" --version "$assemblyVersion" @$using:remapFileName @$using:requiredNamespacesForNames @$using:autoTypesFileName @$using:enumsRemapFileName @$using:functionPointerFixupsRsp @$using:enumsMakeFlagsRsp
    if ($LastExitCode -ne 0)
    {
        Write-Error "Failed to build .winmd."
        exit $LastExitCode
    }

    Write-Output "`n`e[32mGenerating .winmd succeeded`e[0m"
} -ThrottleLimit $throttleCount