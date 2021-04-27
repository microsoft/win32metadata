param
(
    [string]
    $assemblyVersion,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch",

    [switch]$SkipConstants = $false,

    [switch]$SkipBinary = $false,

    [switch]$externalOnly = $false
)

$scraperArch = $arch
if ($arch -eq "crossarch")
{
    $scraperArch = "x64"
}

. "$PSScriptRoot\CommonUtils.ps1"

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

if (!$SkipBinary)
{
    $outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch
}

if (!$externalOnly)
{
    if (!$SkipConstants)
    {
        Write-Output "`n"
        Write-Output "Scraping constants and enums..."
        Write-Output "Calling: dotnet $constantsScraperPathBin --generationDir $generationDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName"

        & dotnet $constantsScraperPathBin --generationDir $generationDir --arch $scraperArch --enumsJson $enumsJson --headerTextFile $constantsHeaderTxt @$constantsScraperRsp @$requiredNamespacesForNames @$remapFileName
        if ($LastExitCode -ne 0)
        {
            Write-Error "Failed to scrape constants."
            exit $LastExitCode
        }
    }

    if (!$SkipBinary)
    {
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
    }
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
$emitterGeneratedDir = "$emitterDir\generated\$scraperArch"
$enumsRemapFileName = "$emitterGeneratedDir\enumsRemap.rsp"
$autoTypesFileName = "$emitterDir\autoTypes.rsp"
$functionPointerFixupsRsp = "$emitterGeneratedDir\functionPointerFixups.generated.rsp"

$constantsScraperRsp = "$scraperDir\ConstantsScraper.rsp"
$enumsJson = "$scraperDir\enums.json"

$partitionNames = Get-ChildItem -Directory $partitionsDir | Select-Object -ExpandProperty Name

$partitionNames | ForEach-Object -Parallel {
    # Reimport CommonUtils.ps1 to get access to Get-ExternalPackageVersion in this scope
    . "$using:PSScriptRoot\CommonUtils.ps1"

    $assemblyVersion = Get-ExternalPackageVersion $defaultArtifactsDir $_
    $externalPackageDir = "$defaultArtifactsDir\InstalledPackages\$_.$assemblyVersion"
    $enumsMakeFlagsRsp = "$using:emitterGeneratedDir\enumsMakeFlags.$_.rsp"

    if (!$using:SkipConstants)
    {
        Write-Output "`n"
        Write-Output "Scraping constants and enums..."
        Write-Output "Calling: dotnet $using:constantsScraperPathBin --generationDir $using:generationDir --externalPackageDir $externalPackageDir --outputNamespace "$_" --arch $using:scraperArch --enumsJson $using:enumsJson --headerTextFile $using:constantsHeaderTxt @$using:constantsScraperRsp @$using:requiredNamespacesForNames @$using:remapFileName"

        & dotnet $using:constantsScraperPathBin --generationDir $using:generationDir --externalPackageDir $externalPackageDir --outputNamespace "$_" --arch $using:scraperArch --enumsJson $using:enumsJson --headerTextFile $using:constantsHeaderTxt @$using:constantsScraperRsp @$using:requiredNamespacesForNames @$using:remapFileName
        if ($LastExitCode -ne 0)
        {
            Write-Error "Failed to scrape constants."
            exit $LastExitCode
        }
    }

    if (!$using:SkipBinary)
    {
        Write-Output "`n"
        Write-Output "Creating "$binDir\$_.winmd"..."
        Write-Output "Calling: dotnet $using:clangSharpSourceToWinmdBin --sourceDir $using:emitterDir --arch $using:arch --interopFileName $using:metadataInteropBin --baseMetadataFileName $using:outputWinmdFileName --outputNamespace "$_" --outputFileName "$using:binDir\$_.winmd" --version "$assemblyVersion" @$using:remapFileName @$using:requiredNamespacesForNames @$using:autoTypesFileName @$using:enumsRemapFileName @$using:functionPointerFixupsRsp @$enumsMakeFlagsRsp"

        & dotnet $using:clangSharpSourceToWinmdBin --sourceDir $using:emitterDir --arch $using:arch --interopFileName $using:metadataInteropBin --baseMetadataFileName $using:outputWinmdFileName --outputNamespace "$_" --outputFileName "$using:binDir\$_.winmd" --version "$assemblyVersion" @$using:remapFileName @$using:requiredNamespacesForNames @$using:autoTypesFileName @$using:enumsRemapFileName @$using:functionPointerFixupsRsp @$enumsMakeFlagsRsp
        if ($LastExitCode -ne 0)
        {
            Write-Error "Failed to build .winmd."
            exit $LastExitCode
        }

        Write-Output "`n`e[32mGenerating .winmd succeeded`e[0m"
    }
} -ThrottleLimit $throttleCount
