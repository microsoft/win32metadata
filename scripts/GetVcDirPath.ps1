param ($Arch = 'x64', $HostArch = 'x64')

$vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
$installDir = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
if ($installDir) 
{
    $path = join-path $installDir 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt'
    if (test-path $path) 
    {
        $version = Get-Content -raw $path
        if ($version) 
        {
            $version = $version.Trim()
            $path = join-path $installDir "VC\Tools\MSVC\$version\bin\Host$HostArch\$Arch"
            return $path
        }
    }
}

return $null
