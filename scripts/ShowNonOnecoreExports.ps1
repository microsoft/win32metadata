
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $libPath
)

$dumpbinPath = Join-Path -Path $PSScriptRoot -ChildPath "..\tools\dumpbin.exe"

function Get-ExportedFuncFromLib
{
    param
    (
        [Parameter(Mandatory=$true)]
        [string]
        $libFileName
    )

    $dict = @{}

    $tempOutput = New-TemporaryFile
    & $dumpbinPath -headers $libFileName > $tempOutput
    $textContent = Get-Content -path $tempOutput -Raw
    Remove-Item $tempOutput

    $pattern = [Regex]::new('DLL name     : ([^.]+)[^\n]+\n  Symbol name  : ([^\s]+)')
    $matches = $pattern.Matches($textContent)
    foreach ($match in $matches)
    {
        $dll = $match.Groups[1].Value
        $procName = $match.Groups[2].Value
        $dict.Add($procName, $dll)
    }

    return $dict
}

$onecoreFuncs = Get-ExportedFuncFromLib -libFileName "$libPath\onecoreuap.lib"
$libs = get-childitem -path "$libPath\*.lib" -Exclude onecore*.lib
foreach ($lib in $libs)
{
    Write-Host "Looking at $lib..."
    $libFuncs = Get-ExportedFuncFromLib -libFileName $lib.FullName
    foreach ($key in $libFuncs.Keys)
    {
        if (!$onecoreFuncs.ContainsKey($key))
        {
            Write-Host "$key = $($libFuncs[$key])"
        }
    }
}
