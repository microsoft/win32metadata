<#
.SYNOPSIS
    Installs VS or modifies an existing installation such that it includes all the required components to build this repo.
.PARAMETER VSInstallPath
    The path to the VS install to modify. This should be the root path (not including the Common7 directory).
    Should not be used in combination with -Nickname. If neither is specified, the 'latest' install of VS is modified.
.PARAMETER Nickname
    The nickname of the install to modify.
    Should not be used in combination with -VSInstallPath. If neither is specified, the 'latest' install of VS is modified.
#>
[CmdletBinding(SupportsShouldProcess=$true,ConfirmImpact='Low')]
Param(
    [Parameter()]
    [string]$VSInstallPath,
    [Parameter()]
    [string]$Nickname
)

if ($VSInstallPath -and $Nickname) {
    throw "Do not specify both -VSInstallPath and -Nickname parameters."
}

# PowerShell completion likes to add a trailing backslash, but this breaks what we do later.
$VSInstallPath = $VSInstallPath.TrimEnd('\')

# Docs for VS installer command line: https://docs.microsoft.com/en-us/visualstudio/install/use-command-line-parameters-to-install-visual-studio

$installerArgs = @()

$vsInstallerPath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vs_installer.exe"
if (!(Test-Path $vsInstallerPath)) {
    $vsInstallerPath = "$env:TEMP\vs_enterprise.exe"
    (New-Object System.Net.WebClient).DownloadFile("https://aka.ms/vs/17/release/vs_enterprise.exe", $vsInstallerPath)
}

$vswherePath = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
if (Test-Path $vswherePath) {
    $vswhereArgs = & "$PSScriptRoot\Get-VSWhereBaseArgs.ps1"
    if (-not ($VSInstallPath -or $Nickname)) {
        $vswhereArgs += '-latest'
    }
    $installs = [xml](& $vswherePath $vswhereArgs)
    if ($VSInstallPath) {
        $vsInstallInstance = $installs.instances.instance |? { $_.installationPath -eq $VSInstallPath }
        if (!$vsInstallInstance) { throw "No VS instance found with path `"$VSInstallPath`"." }
    } elseif ($Nickname) {
        $vsInstallInstance = $installs.instances.instance |? { $_.properties.nickname -eq $Nickname }
        if (!$vsInstallInstance) { throw "No VS instance found with nickname `"$NickName`"." }
    } else {
        $vsInstallInstance = $installs.instances.instance
    }

    $vsInstallPath = $vsInstallInstance.installationPath
}

if ($vsInstallPath) {
    # Modify an existing install
    $installerArgs += 'modify'
    $installerArgs += '--installPath',$vsInstallPath
}

$workloadsRequired = & "$PSScriptRoot\Get-RequiredWorkloads.ps1"
$installerArgs += $workloadsRequired |% { '--add', $_ }

& $vsInstallerPath $installerArgs
