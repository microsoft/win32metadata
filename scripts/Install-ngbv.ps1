# Centralized script to install the nbgv tool using the Install-DotNetTool.ps1 script.
# When switching to a newer version of nbgv tool, update the version number in this script
# and make sure the Azure Artificats feed: https://pkgs.dev.azure.com/shine-oss/Win32Metadata/_packaging/Win32Metadata-Dependencies/nuget/v3/index.json
# has the new version available.
Param ([string] $NuGetConfigFile)

if (-not $NuGetConfigFile) {
    throw "NuGetConfigFile is null. NuGetConfigFile must be a valid file path to a NuGet.config file."
}

& "$PSScriptRoot\Install-DotNetTool.ps1" -Name nbgv -Version 3.7.115 -NuGetConfigFile $NuGetConfigFile
