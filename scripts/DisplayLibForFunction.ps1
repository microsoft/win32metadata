
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $libDir,

    [Parameter(Mandatory=$true)]
    [string]
    $funcName
)

if (!(Test-Path -path $libDir))
{
    Write-Host "Error: Couldn't find $libDir."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"

$headersFromDumpBinFileName = New-TemporaryFile

$dumpbinPath = "$toolsDir\dumpbin.exe"

foreach ($libPath in Get-ChildItem "$libDir\*.lib" | select -ExpandProperty FullName)
{
    & $dumpbinPath -headers $libPath > $headersFromDumpBinFileName
    $obj = Get-ChildItem $headersFromDumpBinFileName | sls "Symbol name  : $funcName"
    if ($obj)
    {
        Write-Host "Function found in $libPath"
        break
    }
}
