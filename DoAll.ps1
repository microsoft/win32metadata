param
(
    [switch]$Clean,

    [switch]$ExcludePackages,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch"
)

. .\scripts\CommonUtils.ps1

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

Install-BuildTools

.\scripts\BuildMetadataBin.ps1 -arch $arch

if (!$ExcludePackages)
{
    .\scripts\DoPackages.ps1
}

if ($arch -eq "crossarch")
{
    .\scripts\TestWinmdBinary.ps1
}
