param
(
    [switch]$Clean,

    [string]$Partition,

    [switch]$Debug
)

. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

if ($Debug)
{
    $configuration = "Debug"
}
else
{
    $configuration = "Release"
}

$params = @('build', $windowsWin32ProjectRoot, "-c:$configuration", '-t:ScrapeHeaders')
if ($Partition)
{
    $params += "-p:PartitionFilter=$Partition"
}

& dotnet $params

ThrowOnNativeProcessError
