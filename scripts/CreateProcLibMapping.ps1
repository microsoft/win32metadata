
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $libPath,

    [Parameter(Mandatory=$true)]
    [string]
    $outputFileName
)

if (!(Test-Path -path $libPath))
{
    Write-Output "Error: Couldn't find $libPath."
    exit -1
}

if (Test-Path -path $outputFileName)
{
    Remove-Item $outputFileName
}

$headersFromDumpBinFileName = New-TemporaryFile

$dumpbinPath = Join-Path -Path $PSScriptRoot -ChildPath "..\tools\dumpbin.exe"
& $dumpbinPath -headers $libPath > $headersFromDumpBinFileName

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
