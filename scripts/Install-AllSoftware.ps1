# 1. Make sure the Microsoft App Installer is installed:
#    https://www.microsoft.com/p/app-installer/9nblggh4nns1
# 2. Run this script as administrator. If running scripts is blocked, you can temporarily unblock them by running
#    Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process

function Check-IsElevated
 {
    $id = [System.Security.Principal.WindowsIdentity]::GetCurrent()
    $p = New-Object System.Security.Principal.WindowsPrincipal($id)
    if ($p.IsInRole([System.Security.Principal.WindowsBuiltInRole]::Administrator)) {
        return $true
    }
    else {
        return $false
    }
 }

$policy = Get-ExecutionPolicy
if ($policy -ne "Unrestricted"){
    throw "Please set the execution policy to Unrestricted. You can temporarily unblock them by running
    Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process"
}
elseif (-not(Check-IsElevated)){
    throw "Please run this script as an administrator"
}
else {
    Write-Host "Installing apps"
    $apps = @(
    @{packageID = "icsharpcode.ILSpy" },
    @{packageID = "Microsoft.DotNet.SDK.6" },
    @{packageID = "Microsoft.VisualStudioCode" }
    );
    Foreach ($app in $apps) {
        $listApp = winget list --exact -q $app.packageIDs
        if (![String]::Join("", $listApp).Contains($app.packageID)) {
            Write-Host "Installing: $($app.packageID)"
            winget install -h $app.packageID -s winget
        }
        else {
            Write-Host "Skipping: $($app.packageID) (already installed)"
        }
    }
    & "$PSScriptRoot\Get-VSPath.ps1" | Out-Null
}
