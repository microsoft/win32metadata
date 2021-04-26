param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [switch] $isExternal = $false
)

. "$PSScriptRoot\CommonUtils.ps1"

if ($isExternal)
{
    $generationDir = "$rootDir\external"
    $scraperDir = "$generationDir\scraper"
    $emitterDir = "$generationDir\emitter"
}

$autoTypesRsp = "$emitterDir\functionPointerFixups.csv"

$scraperObjDir = "$scraperDir\obj\$arch"
Create-Directory $scraperObjDir

$emitterGeneratedDir = "$emitterDir\generated\$arch"
Create-Directory $emitterGeneratedDir

$outputScraperRspFileName = "$scraperObjDir\functionPointerFixups.generated.rsp"
$outputEmitterRspFileName = "$emitterGeneratedDir\functionPointerFixups.generated.rsp"

$functionFixups = Import-Csv $autoTypesRsp -Delimiter ',' -Header @('DeclaredCallback', 'CallbackPointerTypedef', 'OrigDeclIsPointer')

$emitterRspReducePointerLevelSection = [System.IO.StringWriter]::new()
$scraperRspRemapSection = [System.IO.StringWriter]::new()
$scraperRspExcludeSection = [System.IO.StringWriter]::new()

foreach ($functionFixup in $functionFixups)
{
    $origDeclIsPointer = $functionFixup.OrigDeclIsPointer -eq "true"

    if (![string]::IsNullOrEmpty($functionFixup.CallbackPointerTypedef))
    {
        $scraperRspExcludeSection.WriteLine($functionFixup.CallbackPointerTypedef)
        $scraperRspRemapSection.WriteLine("$($functionFixup.DeclaredCallback)=$($functionFixup.CallbackPointerTypedef)")

        if (!$origDeclIsPointer)
        {
            $emitterRspReducePointerLevelSection.WriteLine($functionFixup.CallbackPointerTypedef)
        }
    }
    else 
    {
        if (!$origDeclIsPointer)
        {
            $emitterRspReducePointerLevelSection.WriteLine($functionFixup.DeclaredCallback)
        }
    }
}

$outputScraperRsp = [System.IO.StreamWriter] $outputScraperRspFileName
$scraperRspExcludeSection = $scraperRspExcludeSection.ToString()
if (![string]::IsNullOrEmpty($scraperRspExcludeSection))
{
    $outputScraperRsp.WriteLine("--exclude")
    $outputScraperRsp.Write($scraperRspExcludeSection)
}

$scraperRspRemapSection = $scraperRspRemapSection.ToString()
if (![string]::IsNullOrEmpty($scraperRspRemapSection))
{
    $outputScraperRsp.WriteLine("--remap")
    $outputScraperRsp.Write($scraperRspRemapSection)
}
$outputScraperRsp.Close();

$outputEmitterRsp = [System.IO.StreamWriter] $outputEmitterRspFileName
$emitterRspReducePointerLevelSection = $emitterRspReducePointerLevelSection.ToString()
if (![string]::IsNullOrEmpty($emitterRspReducePointerLevelSection))
{
    $outputEmitterRsp.WriteLine("--reducePointerLevel")
    $outputEmitterRsp.Write($emitterRspReducePointerLevelSection)
}
$outputEmitterRsp.Close();
