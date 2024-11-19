Param ([string] $Name, [string] $Version = '', [string] $NuGetConfigFile)

if (-not $NuGetConfigFile) {
    throw "NuGetConfigFile is null. NuGetConfigFile must be a valid file path to a NuGet.config file."
}

if (-not (Test-Path -Path $NuGetConfigFile -PathType Leaf)) {
	throw "NuGetConfigFile file wasn't found at supplied path. NuGetConfigFile must be a valid file path to a NuGet.config file."
}

if ($Version -ne '')
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name\s+$Version"
    if ($null -eq $installed)
    {
        & dotnet tool update --global $Name --version $Version --configfile $NuGetConfigFile
    }
}
else
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name"
    if ($null -eq $installed)
    {
        & dotnet tool update --global $Name --configfile $NuGetConfigFile
    }
}
