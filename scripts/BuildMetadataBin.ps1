param
(
    [switch]
    $assetsScrapedSeparately,

    [switch]
    $skipInstallTools,

    [switch]
    $Clean,

    [switch]
    $Debug
)

. "$PSScriptRoot\CommonUtils.ps1"

if ($Clean.IsPresent)
{
    & $PSScriptRoot\CleanOutputs.ps1
}

if (!$skipInstallTools.IsPresent)
{
    Install-BuildTools
}

$assemblyVersion = nbgv get-version -v AssemblyVersion

$arch = "crossarch"

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Host "`n"
Write-Host "*** Creating $outputWinmdFileName..." -ForegroundColor Blue

$skipScraping = "false"

if ($assetsScrapedSeparately)
{
    $skipScraping = "true"
}

if ($Debug)
{
    $configuration = "Debug"
}
else
{
    $configuration = "Release"
}

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")

# Explicitly restore the Win32Metadata project to avoid issues restore happening during build
& dotnet restore "$windowsWin32ProjectRoot" --configfile "$rootDir\nuget.Config"

$timestamp = Get-Date -Format "yyyyMMddHHmmss"
$logFile = "$PSScriptRoot\..\bin\logs\BuildMetadataBin_$timestamp.binlog"
& dotnet build "$windowsWin32ProjectRoot" -c $configuration -t:EmitWinmd -p:WinmdVersion=$assemblyVersion -p:OutputWinmd=$outputWinmdFileName -p:SkipScraping=$skipScraping "-bl:$logFile" --no-restore
ThrowOnNativeProcessError
