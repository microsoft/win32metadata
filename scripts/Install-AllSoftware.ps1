# 1. Make sure the Microsoft App Installer is installed:
#    https://www.microsoft.com/p/app-installer/9nblggh4nns1

Write-Output "Installing apps"
$apps = @(
	@{packageID = "icsharpcode.ILSpy" },
	@{packageID = "Microsoft.DotNet.SDK.6" },
   	@{packageID = "Microsoft.VisualStudioCode" }
);
Foreach ($app in $apps) {
    $listApp = winget list --exact -q $app.packageIDs
    if (![String]::Join("", $listApp).Contains($app.packageID)) {
        Write-output "Installing: " $app.packageID
        winget install -h $app.packageID -s winget 
    }
    else {
        Write-output "Skipping: " $app.packageID " (already installed)"
    }
}

& "$PSScriptRoot\Get-VSPath.ps1" | Out-Null 