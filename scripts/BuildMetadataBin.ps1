param
(
    [switch]
    $skipInstallTools,

    [switch]
    $Clean,

    [switch]
    $Debug,

    [ValidateSet("crossarch", "x64", "x86", "arm64")]
    [string]
    $arch = "crossarch"
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

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Host "`n"
Write-Host "*** Creating $outputWinmdFileName..." -ForegroundColor Blue

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
$targetArchitectures = if ($arch -eq "crossarch") { "x64;x86;arm64" } else { $arch }
& dotnet build "$windowsWin32ProjectRoot" -c $configuration -t:EmitWinmd -p:WinmdVersion=$assemblyVersion -p:OutputWinmd=$outputWinmdFileName -p:TargetArchitectures=$targetArchitectures "-bl:$logFile" --no-restore
ThrowOnNativeProcessError
