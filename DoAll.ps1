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

# The libMapings.rsp is checked in as an optimization, but this
# this will regenerate it if it's not there
Invoke-PrepLibMappingsFile

if ($arch -eq "crossarch")
{
    $arches = @("x64", "x86", "arm64")

    foreach ($archItem in $arches)
    {
        .\scripts\GenerateMetadataSource.ps1 -arch $archItem
        if ($LastExitCode -lt 0)
        {
            exit $LastExitCode
        }
    }
}
else
{
    .\scripts\GenerateMetadataSource.ps1 -arch $arch
    if ($LastExitCode -lt 0)
    {
        exit $LastExitCode
    }
}

.\scripts\BuildMetadataBin.ps1 -arch $arch
if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}

if (!$ExcludePackages)
{
    dotnet pack .\sources\packages.proj -c Release

    .\scripts\UpdateGlobalJsonWinmdGeneratorVersion.ps1

    dotnet pack .\sources\msbuild\samples\diasdk -c Release

    dotnet build .\sources\msbuild\samples -c Release
}

if ($arch -eq "crossarch")
{
    .\scripts\TestWinmdBinary.ps1
    if ($LastExitCode -lt 0)
    {
        exit $LastExitCode
    }
}
