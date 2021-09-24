. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

dotnet build "$windowsWin32ProjectRoot" -c Release -t:ScrapeHeaders

if ($LastExitCode -lt 0)
{
    exit $LastExitCode
}
