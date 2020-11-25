function Create-Directory([string[]] $Path) 
{
    if (!(Test-Path -Path $Path)) 
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
    }
}

function Replace-Text
{
    Param ([string] $path, [hashtable] $items)

    $content = Get-Content -path $path -Encoding UTF8
    foreach ($key in $items.Keys)
    {
        $content = $content.Replace($key, $items[$key]);
    }
    
    Set-Content -path $path -Encoding UTF8 -value $content
}

$defaultWinSDKNugetVersion = "10.0.19041.5"

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$toolsDir = "$rootDir\tools"
$binDir = "$rootDir\bin"
$sourcesDir = "$rootDir\sources"
$importLibsDir = "$rootDir\generation\ImportLibs"
$sdkApiPath = "$rootDir\ext\sdk-api"

if (Test-Path -Path $binDir -PathType leaf)
{
    Remove-Item $binDir
}

if (!(Test-Path -Path $binDir))
{
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
}
