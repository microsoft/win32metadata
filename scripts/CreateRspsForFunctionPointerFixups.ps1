param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [string]
    $functionPointerFixupsPath,

    [string]
    $scraperDir,

    [string]
    $outputScraperRspFileName,

    [string]
    $emitterDir,

    [string]
    $outputEmitterRspFileName
)

#. "$PSScriptRoot\CommonUtils.ps1"

#$autoTypesRsp = "$emitterDir\functionPointerFixups.csv"
$changedFileName = [System.IO.Path]::GetFileNameWithoutExtension($functionPointerFixupsPath) + ".generated.rsp"

if (!$outputScraperRspFileName)
{
    $scraperObjDir = "$scraperDir\obj\$arch"
    $outputScraperRspFileName = "$scraperObjDir\$changedFileName"
}

$dir = [System.IO.Path]::GetDirectoryName($outputScraperRspFileName)
New-Item -Path $dir -Force -ItemType "Directory" | Out-Null

if (!$outputEmitterRspFileName)
{
    $emitterGeneratedDir = "$emitterDir\generated\$arch"
    $outputEmitterRspFileName = "$emitterGeneratedDir\$changedFileName"
}

$dir = [System.IO.Path]::GetDirectoryName($outputEmitterRspFileName)
New-Item -Path $dir -Force -ItemType "Directory" | Out-Null

$functionFixups = Get-Content $functionPointerFixupsPath -raw | ConvertFrom-Json

$emitterRspReducePointerLevelSection = [System.IO.StringWriter]::new()
$scraperRspRemapSection = [System.IO.StringWriter]::new()
$scraperRspExcludeSection = [System.IO.StringWriter]::new()

foreach ($functionFixup in $functionFixups)
{
    $origDeclIsPointer = $functionFixup.alreadyPointer -eq $true

    if ($null -ne $functionFixup.pointerType)
    {
        $scraperRspExcludeSection.WriteLine($functionFixup.pointerType)
        $scraperRspRemapSection.WriteLine("$($functionFixup.name)=$($functionFixup.pointerType)")

        if (!$origDeclIsPointer)
        {
            $emitterRspReducePointerLevelSection.WriteLine($functionFixup.pointerType)
        }
    }
    else 
    {
        if (!$origDeclIsPointer)
        {
            $emitterRspReducePointerLevelSection.WriteLine($functionFixup.name)
        }
    }
}

$outputScraperRspText = "--exclude`r`n$($scraperRspExcludeSection.ToString())--remap`r`n$($scraperRspRemapSection.ToString())"
[System.IO.File]::WriteAllText($outputScraperRspFileName, $outputScraperRspText)
#Write-Host "Wrote $outputScraperRspFileName"

$outputEmitterRspText = "--reducePointerLevel`r`n$($emitterRspReducePointerLevelSection.ToString())"
[System.IO.File]::WriteAllText($outputEmitterRspFileName, $outputEmitterRspText)
#Write-Host "Wrote $outputEmitterRspFileName"
