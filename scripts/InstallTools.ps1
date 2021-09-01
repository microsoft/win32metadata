function Install-DotNetTool
{
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
}

Install-DotNetTool -Name ClangSharpPInvokeGenerator -Version 11.0.0-beta3
