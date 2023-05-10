
param
(
    [string]
    $outputFileName
)

if (!$outputFileName)
{
    $outputFileName = "$PSScriptRoot\..\generation\WithSetLastError.rsp"
}

. "$PSScriptRoot\CommonUtils.ps1"

$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--with-setlasterror")

# Makes it easier (faster) for debugging to try it on just one file
# $funcs = ls "$MicrosoftDocsSdkApiPath\nf-fileapi-createfilew.md" -r | sls "nf-errhandlingapi-getlasterror" | select -u -exp Path | Get-ChildItem | sls -pattern "UID: NF:" | %{$_.line.split('.')[1]} | Sort-Object

$funcs = ls "$MicrosoftDocsSdkApiPath\nf-*" -r | sls "nf-errhandlingapi-getlasterror" | select -u -exp Path | Get-ChildItem | sls -pattern "UID: NF:" | %{$_.line.split('.')[1]} | Sort-Object -Unique

foreach ($func in $funcs)
{
    $stream.WriteLine($func)
}

$stream.Close()

