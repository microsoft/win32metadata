
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $sdkVer,

    [Parameter(Mandatory=$true)]
    [string]
    $outputFileName
)

$onecoreLibPath = "C:\Program Files (x86)\Windows Kits\10\Lib\10.0.$sdkVer.0\um\x64\OneCore.Lib"
if (!(Test-Path -path $onecoreLibPath))
{
    Write-Host "Error: Couldn't find $onecoreLibPath. Is the $sdkVer SDK installed?"
    exit -1
}

if (Test-Path -path $outputFileName)
{
    Remove-Item $outputFileName
}

$headersFromDumpBinFileName = New-TemporaryFile

$dumpbinPath = Join-Path -Path $PSScriptRoot -ChildPath "..\tools\dumpbin.exe"
& $dumpbinPath -headers $onecoreLibPath > $headersFromDumpBinFileName

$txtContent = Get-Content -path $headersFromDumpBinFileName -Raw

$pattern = [Regex]::new('DLL name     : ([^.]+)[^\n]+\n  Symbol name  : ([^\s]+)')
$matches = $pattern.Matches($txtContent)
$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--with-librarypath")
foreach ($match in $matches)
{
    $dll = $match.Groups[1].Value
    $procName = $match.Groups[2].Value
    $stream.WriteLine("$procName=$dll")
}
$stream.Close()
