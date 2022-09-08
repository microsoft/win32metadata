param
(
    [Parameter(Mandatory=$true)]
    [string]
    $techRootToNamespaceMappingsFileName
)

if (!(Test-Path -path $techRootToNamespaceMappingsFileName))
{
    Write-Error "Couldn't find csv file $techRootToNamespaceMappingsFileName."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"

$techRootToNamespaceCsv = Import-Csv $techRootToNamespaceMappingsFileName -Delimiter ',' -Header @('TechRoot', 'Namespace') | Sort-Object
[hashtable]$namespaces = @{}
foreach ($item in ($techRootToNamespaceCsv | Sort-Object))
{
    $namespace = $item.Namespace
    $fullNamespace = "Windows.Win32.$namespace"
    $namespaces[$fullNamespace] = 1;
}

$outputFileName = "$PSScriptRoot\..\generation\header.txt"

$stream = [System.IO.StreamWriter] $outputFileName

$stream.WriteLine("// Copyright © Microsoft")
$stream.WriteLine("using Windows.Win32.Interop;")
$stream.WriteLine()

$sortedKeys = $namespaces.Keys | Sort-Object
foreach ($namespace in $sortedKeys)
{
    $stream.WriteLine("using $namespace;")
}

$stream.WriteLine("using IServiceProvider = Windows.Win32.System.Com.IServiceProvider;")

$stream.Close()
