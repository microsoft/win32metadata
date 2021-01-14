param
(
    [string]
    $assemblyVersion,

    [string]
    $winmdPath
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
}

if (!$winmdPath)
{
    $winmdPath = $outputWinmdFileName
}

function FindBestBaselineWinmd
{
    param([int] $buildNumber)

    $bestDir = ""
    $versionNames = get-childitem $PSScriptRoot\BaselineWinmd
    foreach ($versionDir in $versionNames)
    {
        $baselineVersion = [int]($versionDir.Name.Split(".")[2])
        if ($baselineVersion -gt $buildNumber)
        {
            break
        }

        $bestDir = $versionDir.Name
    }

    return $bestDir
}

$buildNumber = [int]($assemblyVersion.Split(".")[2])
$baselineWinmdDir = FindBestBaselineWinmd $buildNumber
if ($baselineWinmdDir -eq "")
{
    Write-Output "Failed to find a baseline winmd to compare against."
    exit 0
}

$baselineWinmd = "$PSScriptRoot\BaselineWinmd\$baselineWinmdDir\Windows.Win32.winmd"

$winmdUtilsPath = "$sourcesDir\WinmdUtils"
$winmdUtilsPathProj = "$winmdUtilsPath\WinmdUtils.csproj"
$winmdUtilsPathBin = "$winmdUtilsPath\bin\Release\netcoreapp3.1\WinmdUtils.dll"
& dotnet build $winmdUtilsPathProj -c Release

Write-Output "`n"
Write-Output "Comparing $outputWinmdFileName against baseline $baselineWinmd..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showMissingImports --first $baselineWinmd --second $winmdPath"
& dotnet $winmdUtilsPathBin showMissingImports --first $baselineWinmd --second $winmdPath

Write-Output "`nLooking for duplicate imports in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateImports --winmd $winmdPath"
& dotnet $winmdUtilsPathBin showDuplicateImports --winmd $winmdPath

Write-Output "`nLooking for duplicate types in $outputWinmdFileName..."
Write-Output "Calling: dotnet $winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath"
& dotnet $winmdUtilsPathBin showDuplicateTypes --winmd $winmdPath

