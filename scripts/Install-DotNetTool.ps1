Param ([string] $Name, [string] $Version = '')

if ($Version -ne '')
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name\s+$Version"
    if ($installed -eq $null)
    {
        & dotnet tool update --global $Name --version $Version
    }
}
else
{
    $installed = & dotnet tool list -g | select-string -Pattern "$Name"
    if ($installed -eq $null)
    {
        & dotnet tool update --global $Name
    }
}
