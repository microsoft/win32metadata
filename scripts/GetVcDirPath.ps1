param ($Arch = 'x64', $HostArch = 'x64')

try {
    $installDir = & "$PSScriptRoot\Get-VSPath.ps1"
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

    return $null
} finally {
    # This doesn't need anything, but putting the script in a try block leads to it aborting
    # when a child script throws.
}
