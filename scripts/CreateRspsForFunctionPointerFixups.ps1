. "$PSScriptRoot\CommonUtils.ps1"

$autoTypesRsp = "$emitterDir\functionPointerFixups.csv"
$outputScraperRspFileName = "$scraperDir\functionPointerFixups.generated.rsp"
$outputEmitterRspFileName = "$emitterDir\functionPointerFixups.generated.rsp"

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
