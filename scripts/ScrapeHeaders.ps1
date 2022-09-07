param
(
    [switch]$Clean,

    [string]$Partition
)

. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

if ($Clean.IsPresent)
{
    .\scripts\CleanOutputs.ps1
}

$params = @('build', $windowsWin32ProjectRoot, '-c:Release', '-t:ScrapeHeaders')
if ($Partition)
{
    $params += "-p:PartitionFilter=$Partition"
}

& dotnet $params

ThrowOnNativeProcessError
