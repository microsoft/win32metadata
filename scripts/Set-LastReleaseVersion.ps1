[CmdletBinding()]
Param(
    [Parameter(Mandatory=$true)]
    [string]$LastReleaseVersion
)

$dirBuildPropsFile = Join-Path $PSScriptRoot "..\Directory.Build.Props"

Write-Verbose "Updating $dirBuildPropsFile..."

$dirBuildPropsXml = New-Object xml
$dirBuildPropsXml.PreserveWhitespace = $true
$dirBuildPropsXml.Load($dirBuildPropsFile)

$dirBuildPropsXml.Project.PropertyGroup.LastWin32MetadataReleaseVersion = $LastReleaseVersion
$dirBuildPropsXml.Save($dirBuildPropsFile)

. "$PSScriptRoot\CommonUtils.ps1"
$changesFile = Get-ChangesSinceLastReleaseFile
Write-Verbose "Clearing contents of $changesFile..."

Clear-Content -Path $changesFile

