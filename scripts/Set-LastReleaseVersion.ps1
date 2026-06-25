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

