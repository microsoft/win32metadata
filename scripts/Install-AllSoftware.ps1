# 1. Make sure the Microsoft App Installer is installed:
#    https://www.microsoft.com/en-us/p/app-installer/9nblggh4nns1
# 2. Run this script as administrator. If running scripts is blocked, you can temporarily unblock them by running 
	Set-ExecutionPolicy -ExecutionPolicy Unrestricted -Scope Process

Write-Output "Installing apps"
$apps = @(
	@{name = "GitHub.GitLFS" },
	@{name = "icsharpcode.ILSpy" },
	@{name = "Microsoft.DotNet.SDK.6" },
   	@{name = "Microsoft.VisualStudioCode" }
);
Foreach ($app in $apps) {
    $listApp = winget list --exact -q $app.names
    if (![String]::Join("", $listApp).Contains($app.name)) {
        Write-host "Installing: " $app.name
        winget install -e -h --accept-source-agreements --accept-package-agreements --id $app.name 
    }
    else {
        Write-host "Skipping: " $app.name " (already installed)"
    }
}

& "$PSScriptRoot\scripts\Get-VSPath.ps1" | Out-Null 