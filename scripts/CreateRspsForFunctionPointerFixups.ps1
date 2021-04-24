param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64"
)

. "$PSScriptRoot\CommonUtils.ps1"

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

$outputScraperRspText = "--exclude`r`n$($scraperRspExcludeSection.ToString())--remap`r`n$($scraperRspRemapSection.ToString())"
[System.IO.File]::WriteAllText($outputScraperRspFileName, $outputScraperRspText)

$outputEmitterRspText = "--reducePointerLevel`r`n$($emitterRspReducePointerLevelSection.ToString())"
[System.IO.File]::WriteAllText($outputEmitterRspFileName, $outputEmitterRspText)
