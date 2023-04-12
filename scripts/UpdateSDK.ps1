[CmdletBinding()]
Param(
    [Parameter(Mandatory=$true)]
    [string]$Version
)

. "$PSScriptRoot\CommonUtils.ps1"

$buildToolsProj = Resolve-Path (Join-Path $PSScriptRoot "..\BuildTools\BuildTools.proj")

Write-Host "Updating $buildToolsProj..."
(Get-Content $buildToolsProj) -replace
"<PackageReference Include=""Microsoft.Windows.SDK.CPP"".*",
"<PackageReference Include=""Microsoft.Windows.SDK.CPP"" Version=""$Version"" GeneratePathProperty=""true""/>" -replace
"<PackageReference Include=""Microsoft.Windows.SDK.CPP.x64"".*",
"<PackageReference Include=""Microsoft.Windows.SDK.CPP.x64"" Version=""$Version"" GeneratePathProperty=""true""/>" |
Set-Content $buildToolsProj

Write-Host "Rebuilding $buildToolsProj..."
dotnet build $buildToolsProj -t:Clean

Write-Host "Recompiling IDL files for scraping..."
. "$PSScriptRoot\RecompileIdlFilesForScraping.ps1"

Write-Host "Creating libMappings.rsp..."
. "$PSScriptRoot\CreateProcLibMappingForAllLibs.ps1"
Remove-Item (Join-Path $windowsWin32ProjectRoot libMappings.old.rsp)

Write-Host "Review libMappings.rsp for manual entries that were removed during the update."