. "$PSScriptRoot\CommonUtils.ps1"

$autoTypesRsp = "$emitterDir\autoTypes.rsp"
$outputFileName = "$scraperDir\autoTypes.generated.rsp"

$autoTypes = Import-Csv $autoTypesRsp -Delimiter ',' -Header @('Namespace', 'TypeName', 'RawType', 'CloseApi')

[hashtable]$typesToExclude = @{}

$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--remap")
foreach ($autoType in $autoTypes)
{
    [string]$rawType = $autoType.RawType

    if ($rawType -eq "DECLARE_HANDLE")
    {
        [string]$typeName = $autoType.TypeName
        $handleStructName = $typeName + "__"
        $typesToExclude[$handleStructName] = 0

        $stream.WriteLine("$typeName=IntPtr")
        $stream.WriteLine("$handleStructName*=$typeName")
    }
    elseif ($rawType -eq "AllJoynHandle")
    {
        [string]$typeName = $autoType.TypeName
        $handleStructName = "_" + $typeName + "_handle"
        $typesToExclude[$handleStructName] = 0

        $stream.WriteLine("$typeName=IntPtr")
        $stream.WriteLine("$handleStructName*=$typeName")
    }
}

$stream.WriteLine("--exclude")
foreach ($exclude in $typesToExclude.Keys)
{
    $stream.WriteLine($exclude)
}
$stream.Close()

