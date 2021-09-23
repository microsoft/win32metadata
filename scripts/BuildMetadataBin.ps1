param
(
    [switch]
    $assetsScrapedSeparately
)

. "$PSScriptRoot\CommonUtils.ps1"

Install-BuildTools

$assemblyVersion = nbgv get-version -v AssemblyVersion

$metadataInteropBin = "$PSScriptRoot\..\bin\Release\netstandard2.1\Windows.Win32.Interop.dll"

Copy-Item $metadataInteropBin $binDir

$arch = "crossarch"

$outputWinmdFileName = Get-OutputWinmdFileName -Arch $arch

Write-Output "`n"
Write-Output "`e[36m*** Creating $outputWinmdFileName...`e[0m"

if ($assetsScrapedSeparately)
{
    $scannedHeadersMarker = "$windowsWin32ProjectRoot\obj\generated\scannedheaders.x64.txt"
    $scannedHeadersMarkerCrossarch = "$windowsWin32ProjectRoot\obj\generated\scannedheaders.crossarch.txt"
    if ((Test-Path $scannedHeadersMarker) -and !(Test-Path $scannedHeadersMarkerCrossarch))
    {
        Copy-Item $scannedHeadersMarker $scannedHeadersMarkerCrossarch
    }
}

dotnet build "$windowsWin32ProjectRoot" -c Release -t:EmitWinmd -p:WinmdVersion=$assemblyVersion -p:OutputWinmd=$outputWinmdFileName

