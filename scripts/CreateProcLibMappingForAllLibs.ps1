
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $libDirectory,

    [Parameter(Mandatory=$true)]
    [string]
    $outputFileName
)

if (!(Test-Path -path $libDirectory))
{
    Write-Output "Error: Couldn't find $libDirectory."
    exit -1
}

$funcLibMappings = [ordered]@{}
$libsVisited = @{}

function AddLibToMappings([string] $libName)
{
    if ($libsVisited.ContainsKey($libName))
    {
        return
    }

    $libsVisited[$libName] = 1

    $libPath = "$libDirectory\$libName"
    $headersFromDumpBinFileName = New-TemporaryFile

    $dumpbinPath = Join-Path -Path $PSScriptRoot -ChildPath "..\tools\dumpbin.exe"
    & $dumpbinPath -headers $libPath > $headersFromDumpBinFileName

    $txtContent = Get-Content -path $headersFromDumpBinFileName -Raw

    Remove-Item $headersFromDumpBinFileName

    $pattern = [Regex]::new('DLL name     : ([^.]+)[^\n]+\n  Symbol name  : ([^\s]+)')
    $matches = $pattern.Matches($txtContent)
    $count = 0
    foreach ($match in $matches)
    {
        $dll = $match.Groups[1].Value
        $procName = $match.Groups[2].Value
        if (!$funcLibMappings.Contains($procName))
        {
            $funcLibMappings[$procName] = $dll
            $count++
        }
    }

    Write-Output "$($libName): $count item(s) found"
}

# Do these first as other libs may claim funcs in them, but we want to prioritize these first
AddLibToMappings("onecoreuap.lib")
AddLibToMappings("kernel32.lib")

foreach ($lib in Get-ChildItem "$libDirectory\*.lib")
{
    AddLibToMappings($lib.Name)
}

$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--with-librarypath")
foreach ($key in $funcLibMappings.Keys)
{
    $procName = $key
    $dll = $funcLibMappings[$key]
    $stream.WriteLine("$procName=$dll")
}
$stream.Close()
