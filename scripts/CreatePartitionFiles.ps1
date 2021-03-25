param
(
    [string]
    $artifactsDir,

    [string]
    $version,

    [Parameter(Mandatory=$true)]
    [string]
    $funcCsvFileName
)

if (!(Test-Path -path $funcCsvFileName))
{
    Write-Output "Error: Couldn't find csv file $funcCsvFileName."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"

if (!$version)
{
    $version = $defaultWinSDKNugetVersion
}

if (!$artifactsDir)
{
    $artifactsDir = "$rootDir\artifacts"
}

$excludedPartitions = @("battery", "ADAM", "alljoyn", "display", "dxmath", "gdiplus", "mediastreaming", "tracelogging", "wmi_v2" )

$parts = $version.Split('.')
$sdkVersion = "$($parts[0]).$($parts[1]).$($parts[2]).0"
$incDirectory = "$artifactsDir\InstalledPackages\Microsoft.Windows.SDK.CPP.$version\c\Include\$sdkVersion"

if (!(Test-Path -path $incDirectory))
{
    Write-Output "Error: Couldn't find include dir $incDirectory."
    exit -1
}

$headersToTechMap = @{}
$funcData = Import-Csv $funcCsvFileName -Delimiter `t
foreach ($item in $funcData)
{
    if (![string]::IsNullOrEmpty($item.TechRoot))
    {
        $headersToTechMap[$item.Header] = $item.TechRoot
    }
}

$headersMap = @{}
foreach ($header in Get-ChildItem "$incDirectory\*.h" -r)
{
    $relativePath = $header.FullName.Substring($incDirectory.Length + 1).Replace('\', '/')
    $headersMap[$header.Name] = $relativePath
}

$traverseHeaders = @{}

function WritePartionFilesForConfig($techConfigFile)
{
    $config = get-content $techConfigFile -raw | convertfrom-json
    if ($config.headers.length -eq 0)
    {
        return
    }

    $partName = $config.tech

    if ($partName -in $excludedPartitions)
    {
        return
    }

    if ([string]::IsNullOrEmpty($partName))
    {
        return
    }

    $partDir = "$partitionsDir\$partName"
    Create-Directory($partDir)

    $cppPath = "$partDir\main.cpp"
    if (Test-Path $cppPath)
    {
        Write-Output "Skipping $cppPath as it already exists"
    }
    else
    {
        $stream = [System.IO.StreamWriter] $cppPath
        $cppIntro = @"
#define SECURITY_WIN32 // For sspi.h
#define QCC_OS_GROUP_WINDOWS

#include "intrinfix.h"

#include "windows.fixed.h"
#include <sdkddkver.h>

"@

        $stream.WriteLine($cppIntro)

        foreach ($headerName in $config.headers)
        {
            if ($headersMap.ContainsKey($headerName))
            {
                $stream.WriteLine("#include <$headerName>")
            }
        }
    
        $stream.Close()

        Write-Output "Wrote $cppPath"
    }

    $settingsPath = "$partDir\settings.rsp"
    if (Test-Path $settingsPath)
    {
        Write-Output "Skipping $settingsPath as it already exists"
    }
    else
    {
        $stream = [System.IO.StreamWriter] $settingsPath
        $settingsStandardText = @"
--file
<RepoRoot>\generation\Partitions\<PartitionName>\main.cpp
--output
<RepoRoot>\sources\Win32MetadataSource\generated\<PartitionName>.cs
--include-directory
<RepoRoot>\generation
<IncludeRoot>/shared
<IncludeRoot>/um
<IncludeRoot>/winrt
--traverse
"@
        $stream.WriteLine($settingsStandardText)
        $headerCount = 0
        foreach ($headerName in $config.headers)
        {
            if ($headersMap.ContainsKey($headerName))
            {
                $headerTech = $headersToTechMap[$headerName]
                if ($headerTech -eq $partName)
                {
                    $relativePath = $headersMap[$headerName]
                    $stream.WriteLine("<IncludeRoot>/$relativePath")
                    $traverseHeaders[$headerName] = 1;
                    $headerCount++
                }
            }
        }
    
        $stream.Close()

        Write-Output "Wrote $settingsPath"

        if ($headerCount -eq 0)
        {
            Remove-item $partDir -recurse
            Write-Output "Deleted $partDir because there were no headers to traverse"
        }
    }
}

foreach ($techConfigFile in ls "$sdkApiPath\sdk-api-src\content\config.json" -r)
{
    WritePartionFilesForConfig($techConfigFile)
}
