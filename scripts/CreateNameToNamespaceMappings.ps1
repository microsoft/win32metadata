param
(
    [Parameter(Mandatory=$true)]
    [string]
    $apiCsvFileName,

    [Parameter(Mandatory=$true)]
    [string]
    $techRootToNamespaceMappingsFileName
)

if (!(Test-Path -path $apiCsvFileName))
{
    Write-Error "Couldn't find csv file $apiCsvFileName."
    exit -1
}

if (!(Test-Path -path $techRootToNamespaceMappingsFileName))
{
    Write-Error "Couldn't find csv file $techRootToNamespaceMappingsFileName."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"

$techRootToNamespaceCsv = Import-Csv $techRootToNamespaceMappingsFileName -Delimiter ',' -Header @('TechRoot', 'Namespace')
[hashtable]$techRootsToNamespaces = @{}
foreach ($item in $techRootToNamespaceCsv)
{
    $namespace = $item.Namespace
    $techRootsToNamespaces[$item.TechRoot] = "Windows.Win32.$namespace"
}

$outputFileName = "$PSScriptRoot\..\sources\Win32MetadataSource\requiredNamespacesForNames.rsp"

$apiCsv = Import-Csv $apiCsvFileName -Delimiter ','
$stream = [System.IO.StreamWriter] $outputFileName
$stream.WriteLine("--requiredNamespaceForName")
foreach ($item in $apiCsv)
{
    $name = $item.Title
    $techRoot = $item.TechRoot

    if (!$techRootsToNamespaces.Contains($techRoot))
    {
        Write-Error "Failed to find mapping for $n, techroot = $techRoot"
        continue
    }

    $namespace = $techRootsToNamespaces[$techRoot]

    $stream.WriteLine("$name=$namespace")
}
$stream.Close()
