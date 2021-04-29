function Get-ExternalPackageVersion
{
    param([string] $artifactsDir, [string] $packageName)

    $packagePaths = Get-ChildItem -Directory -Path "$artifactsDir\InstalledPackages\$packageName.*"
    $installedVersions = $packagePaths | ForEach-Object { [version]$_.Name.Substring("$packageName.".Length) }
    [string]$latestVersion = $installedVersions | Sort-Object -Bottom 1

    return $latestVersion
}