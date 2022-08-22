# 1. Make sure the Microsoft App Installer is installed:
#    https://www.microsoft.com/p/app-installer/9nblggh4nns1
# 2. Run this script as administrator. If running scripts is blocked, you can temporarily unblock them by running 
#    Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process

Write-Output "Installing apps"
$apps = @(
	@{packageID = "icsharpcode.ILSpy" },
	@{packageID = "Microsoft.DotNet.SDK.6" },
   	@{packageID = "Microsoft.VisualStudioCode" }
);
Foreach ($app in $apps) {
    $listApp = winget list --exact -q $app.packageIDs
    if (![String]::Join("", $listApp).Contains($app.packageID)) {
        Write-Output "Installing: $($app.packageID)"
        winget install -h $app.packageID -s winget 
    }
    else {
        Write-Output "Skipping: $($app.packageID) (already installed)"
    }
}

& "$PSScriptRoot\Get-VSPath.ps1" | Out-Null 