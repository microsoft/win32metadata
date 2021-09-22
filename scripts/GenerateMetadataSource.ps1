param
(
    [ValidateSet("x64", "x86", "arm64", "crossarch")]
    [string]
    $arch = "crossarch",

    [switch]
    $scrapeConstants
)

. "$PSScriptRoot\CommonUtils.ps1"

Write-Output "`e[36m*** Generating source files: $arch`e[0m"

Install-BuildTools

if ($scrapeConstants)
{
    $target = "ScrapeConstants"
}
else
{
    $target = "ScrapeHeaders"
}

dotnet build "$windowsWin32ProjectRoot" -c Release -p:ScanArch=$arch -t:$target

