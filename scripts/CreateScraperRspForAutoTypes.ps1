param
(
    [ValidateSet("x64", "x86", "arm64")]
    [string]
    $arch = "x64",

    [string]
    $autoTypesPath,

    [string]
    $scraperDir,

    [string]
    $outputFileName
)

if (!$outputFileName)
{
    $changedFileName = [System.IO.Path]::GetFileNameWithoutExtension($autoTypesPath) + ".generated.rsp"

    $scraperObjDir = "$scraperDir\obj\$arch"
    $outputFileName = "$scraperObjDir\$changedFileName"
}

$dir = [System.IO.Path]::GetDirectoryName($outputFileName)
New-Item -Path $dir -Force -ItemType "Directory" | Out-Null



$autoTypes = Get-Content $autoTypesPath -raw | ConvertFrom-Json

[hashtable]$typesToExclude = @{}

$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--remap")
foreach ($autoType in $autoTypes)
{
    [string]$type = $autoType.ValueType

    if ($type -eq "DECLARE_HANDLE")
    {
        [string]$typeName = $autoType.Name
        $handleStructName = $typeName + "__"
        $typesToExclude[$handleStructName] = 0

        $stream.WriteLine("$typeName=IntPtr")
        $stream.WriteLine("$handleStructName*=$typeName")
    }
    elseif ($type -eq "AllJoynHandle")
    {
        [string]$typeName = $autoType.Name
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

#Write-Host "Wrote $outputFileName"