$vswherePath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
if (-not (Test-Path $vswherePath)) {
    throw "Unable to find vswhere.exe. Is VS 2017 15.3 or later installed? Use $PSScriptRoot\Install-VS.ps1 to acquire VS with the required components."
    exit 1
}

$workloadsRequired = & "$PSScriptRoot\Get-RequiredWorkloads.ps1"

$vswhereArgs = & "$PSScriptRoot\Get-VSWhereBaseArgs.ps1"
$vswhereArgs += '-latest'
$workloadsRequired |% {
    $vswhereArgs += '-requires',$_
}
Write-Verbose "`"$vswherePath`" $vswhereArgs"
$output = & $vswherePath $vswhereArgs
if ($lastexitcode -eq 87) {
    $vswhere = [xml]'<instances />'
} else {
    $vswhere = [xml]$output
}
if ($vswhere.instances.length -eq 0) {
    throw "No VS installation detected that has all the required workloads installed ($workloadsRequired). Use $PSScriptRoot\Install-VS.ps1 to acquire VS with the required components."
    exit 2
}

Write-Output $vswhere.instances.instance.installationPath
