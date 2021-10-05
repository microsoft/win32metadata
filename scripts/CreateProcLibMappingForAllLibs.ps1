
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

    $pattern = [Regex]::new('DLL name     : (\S+)\s+Symbol name  : (?:_([^\s@]+)@\d+|#?(\S+))')
    $matches = $pattern.Matches($txtContent)
    $count = 0

    foreach ($match in $matches)
    {
        $dll = $match.Groups[1].Value
        $dll = [System.IO.Path]::GetFileNameWithoutExtension($dll)

        if ($match.Groups[2].Success)
        {
            $procName = $match.Groups[2].Value
        }
        elseif ($match.Groups[3].Success)
        {
            $procName = $match.Groups[3].Value
        }
        else
        {
            Write-Output "No proc name captured for $match"
            continue
        }

        if ($procName -eq "RtlCompareMemory")
        {
            Write-Output "RtlCompareMemory in $libPath = $dll"
        }

        if ($funcLibMappings.Contains($procName))
        {
            # Don't overwrite a value with an API set
            if ($dll.StartsWith("api-ms") -or $dll.StartsWith("ext-ms"))
            {
                if ($procName -eq "RtlCompareMemory")
                {
                    Write-Output "RtlCompareMemory: dll 1 = $dll"
                }

                continue
            }

            $oldValue = $funcLibMappings[$procName]
            if ($procName -eq "RtlCompareMemory")
            {
                Write-Output "RtlCompareMemory: oldValue = $oldValue"
            }

            # If the new is in the old list, continue
            if ($dll -in $oldValue.Split(','))
            {
                if ($procName -eq "RtlCompareMemory")
                {
                    Write-Output "RtlCompareMemory: dll 2 = $dll in $oldValue"
                }

                continue
            }

            # If the old value doesn't start with api-set...
            if (!$oldValue.StartsWith("api-ms") -and !$oldValue.StartsWith("ext-ms"))
            {
                # We have multiple libs claiming the same function
                $funcLibMappings.Remove($procName)
                $dll = $oldValue + "," + $dll

                if ($procName -eq "RtlCompareMemory")
                {
                    Write-Output "RtlCompareMemory: new dll = $dll, oldValue = $oldValue"
                }
            }
        }

        if (!$funcLibMappings.Contains($procName))
        {
            $count++
        }

        $funcLibMappings[$procName] = $dll
        if ($procName -eq "RtlCompareMemory")
        {
            Write-Output "RtlCompareMemory now = $dll"
        }
    }

    Write-Output "$($libName): $count item(s) found"
}

# Do these first as other libs may claim funcs in them, but we want to prioritize these first
AddLibToMappings("onecoreuap.lib")
AddLibToMappings("kernel32.lib")
AddLibToMappings("d3d10.lib")

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
