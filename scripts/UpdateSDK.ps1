[CmdletBinding()]
Param(
    [Parameter(Mandatory=$true)]
    [string]$Version,

    [Parameter(Mandatory=$false)]
    [string]$NuGetSource = "https://api.nuget.org/v3/index.json",
    
    [Parameter(Mandatory=$false)]
    [switch]$Strict
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

# Restore packages from the specified source
Write-Host "Restoring packages from $NuGetSource..."
dotnet restore $buildToolsProj -s $NuGetSource
if ($LASTEXITCODE -ne 0) {
    throw "Failed to restore package version $Version from $NuGetSource. Ensure the exact version exists."
}

if ($Strict) {
    Write-Host "Strict mode enabled - verified exact version $Version is available"
}

Write-Host "Rebuilding $buildToolsProj..."
dotnet build $buildToolsProj -t:Clean --no-restore
if ($LASTEXITCODE -ne 0) {
    throw "Build failed. Check that version $Version is available."
}

Write-Host "Recompiling IDL files for scraping..."
. "$PSScriptRoot\RecompileIdlFilesForScraping.ps1"

Write-Host "Creating libMappings.rsp..."
. "$PSScriptRoot\CreateProcLibMappingForAllLibs.ps1"
Remove-Item (Join-Path $windowsWin32ProjectRoot libMappings.old.rsp)

Write-Host "Review libMappings.rsp for manual entries that were removed during the update."