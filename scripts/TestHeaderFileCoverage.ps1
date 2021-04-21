. "$PSScriptRoot\CommonUtils.ps1"

function SearchHeaderFile([string]$name) {
    Get-ChildItem -Recurse -Filter settings.rsp $partitionsDir | Select-String $name
}

Write-Output "Scanning header files..."

$sdkIncludePath = "$defaultArtifactsDir/InstalledPackages/Microsoft.Windows.SDK.CPP.$defaultWinSDKNugetVersion/c/Include/*/"
$headerFiles = Get-ChildItem -Recurse -Filter *.h "$sdkIncludePath/um", "$sdkIncludePath/shared"
$missingHeaderFiles = $headerFiles | Where-Object { (SearchHeaderFile $_.Name).Matches.Count -eq 0 } | Sort-Object FullName

Write-Output "Scanning completed."

if ($missingHeaderFiles.Count -gt 0) {
    Write-Output "The below header files are not included in any partition:"

    Write-Output $missingHeaderFiles.FullName
} else {
    Write-Output "All header files are included in partitions."
}

