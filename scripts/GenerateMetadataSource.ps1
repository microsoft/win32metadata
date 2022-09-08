param
(
    [ValidateSet("x64", "x86", "arm64", "crossarch")]
    [string]
    $arch = "crossarch",

    [switch]
    $scrapeConstants
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Host "*** Generating source files: $arch" -ForegroundColor Blue

Install-BuildTools

if ($scrapeConstants)
{
    $target = "ScrapeConstants"
}
else
{
    $target = "ScrapeHeaders"
}

dotnet build "$windowsWin32ProjectRoot" -c Release -p:ScanArch=$arch -t:$target "-bl:$PSScriptRoot\..\bin\logs\GenerateMetadataSources.binlog"
ThrowOnNativeProcessError
