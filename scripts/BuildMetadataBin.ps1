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

$metadataInteropBin = "$PSScriptRoot\..\bin\Release\netstandard2.1\Windows.Win32.Interop.dll"

Copy-Item $metadataInteropBin $binDir

$arch = "crossarch"

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Output "`n"
Write-Output "`e[36m*** Creating $outputWinmdFileName...`e[0m"

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

dotnet build "$windowsWin32ProjectRoot" -c $configuration -t:EmitWinmd -p:WinmdVersion=$assemblyVersion -p:OutputWinmd=$outputWinmdFileName -p:SkipScraping=$skipScraping
ThrowOnNativeProcessError
