
. "$PSScriptRoot\CommonUtils.ps1"

dotnet clean "$windowsWin32ProjectRoot"

if (Test-Path "$rootDir\obj")
{
    remove-item "$rootDir\obj" -force -recurse
}
