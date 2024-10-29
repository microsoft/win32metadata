Param ([string] $Name, [string] $Version = '', [string] $NuGetConfigFile)

if (-not $NuGetConfigFile -or -not (Test-Path -Path $NuGetConfigFile -PathType Leaf)) {
    throw "NuGetConfigFile is either null or not a valid file path."
}

if ($Version -ne '')
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name\s+$Version"
    if ($installed -eq $null)
    {
        & dotnet tool update --global $Name --version $Version --configfile $NuGetConfigFile
    }
}
else
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name"
    if ($installed -eq $null)
    {
        & dotnet tool update --global $Name --configfile $NuGetConfigFile
    }
}
