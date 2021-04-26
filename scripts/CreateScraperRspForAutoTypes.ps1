param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [switch] $isExternal = $false
)

. "$PSScriptRoot\CommonUtils.ps1"

if ($isExternal)
{
    $generationDir = "$rootDir\external"
    $scraperDir = "$generationDir\scraper"
    $emitterDir = "$generationDir\emitter"
}

$autoTypesRsp = "$emitterDir\autoTypes.rsp"

$scraperObjDir = "$scraperDir\obj\$arch"
Create-Directory $scraperObjDir
$outputFileName = "$scraperObjDir\autoTypes.generated.rsp"

$autoTypes = Import-Csv $autoTypesRsp -Delimiter ',' -Header @('Namespace', 'TypeName', 'RawType', 'CloseApi')

[hashtable]$typesToExclude = @{}

$stream = [System.IO.StreamWriter] $outputFileName
if ($autoTypes.Count -gt 0)
{
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
}

if ($typesToExclude.Count -gt 0)
{
    $stream.WriteLine("--exclude")
    foreach ($exclude in $typesToExclude.Keys)
    {
        $stream.WriteLine($exclude)
    }
}
$stream.Close()

