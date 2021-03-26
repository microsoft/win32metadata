param
(
    [switch]$Clean
)

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

.\scripts\GenerateMetadataSource.ps1
if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}

.\scripts\BuildMetadataBin.ps1
if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}

.\scripts\TestWinmdBinary.ps1
if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}
