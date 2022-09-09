[CmdletBinding()]
Param(
    [int]$NewMajorVersion = 0
)

function Get-Version([string]$fullVersion)
{
    $null = $fullVersion -match "(\d+)\.(\d+)(-.+)?"
    return $matches[1], $matches[2], $matches[3]
}

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$rootVersionJsonFile = Join-Path $rootDir "version.json"

# Update main version
$versionJson = Get-Content $rootVersionJsonFile -raw | ConvertFrom-Json
$currentVersion = $versionJson."version"
$currentMajor, $currentMinor, $currentSuffix = Get-Version $currentVersion

if ($NewMajorVersion -eq 0)
{
    $NewMajorVersion = ($currentMajor -as [int]) + 1
}

$newVersion = "$NewMajorVersion.$currentMinor$($currentSuffix)"
$versionJson."version" = $newVersion

$versionJson | ConvertTo-Json | Out-File $rootVersionJsonFile

Write-Host "Set version in $rootVersionJsonFile from $currentVersion to $newVersion"

# Update SDK version
$sdkVersionJsonFile = Join-Path $rootDir "sources\GeneratorSdk\version.json"

$versionJson = Get-Content $sdkVersionJsonFile -raw | ConvertFrom-Json
$currentVersion = $versionJson."version"
$currentMajor, $currentMinor, $currentSuffix = Get-Version $currentVersion
$currentMinor = $NewMajorVersion
$newVersion = "$currentMajor.$currentMinor$($currentSuffix)"
$versionJson."version" = $newVersion

$versionJson | ConvertTo-Json | Out-File $sdkVersionJsonFile
Write-Host "Set version in $sdkVersionJsonFile from $currentVersion to $newVersion"
