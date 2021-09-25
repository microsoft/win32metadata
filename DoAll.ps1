param
(
    [switch]$Clean,

    [switch]$ExcludePackages,

    [switch]$SkipInstallTools,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch"
)

if (!$SkipInstallTools.IsPresent)
{
    . .\scripts\CommonUtils.ps1

    Install-BuildTools
}

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

.\scripts\BuildMetadataBin.ps1 -arch $arch -SkipInstallTools

if (!$ExcludePackages)
{
    .\scripts\DoPackages.ps1 -SkipInstallTools
}

if ($arch -eq "crossarch")
{
    .\scripts\TestWinmdBinary.ps1 -SkipInstallTools
}
