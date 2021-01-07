param
(
    [string]
    $assemblyVersion,

    [string]
    $metadataSourcePath
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
}

if (!$metadataSourcePath)
{
    $metadataSourcePath = "$sourcesDir\Win32MetadataSource"
}

$clangSharpSourceToWinmdPath = "$sourcesDir\ClangSharpSourceToWinmd"
$clangSharpSourceToWinmdProj = "$clangSharpSourceToWinmdPath\ClangSharpSourceToWinmd.csproj"
$clangSharpSourceToWinmdBin = "$clangSharpSourceToWinmdPath\bin\Release\netcoreapp3.1\ClangSharpSourceToWinmd.dll"
& dotnet build $clangSharpSourceToWinmdProj -c Release

$metadataInteropPath = "$sourcesDir\Win32MetadataInterop"
$metadataInteropProj = "$metadataInteropPath\Win32MetadataInterop.csproj"
$metadataInteropBin = "$metadataInteropPath\bin\Release\netstandard2.1\Windows.Win32.Interop.dll"
& dotnet build $metadataInteropProj -c Release

Copy-Item $metadataInteropBin $binDir

$outputWinmdFileName = "$binDir\Windows.Win32.winmd"
$remapFileName = "$metadataSourcePath\remap.rsp"

Write-Output "`n"
Write-Output "Creating $outputWinmdFileName..."
Write-Output "Calling: dotnet $clangSharpSourceToWinmdBin --sourceDir $metadataSourcePath --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName"

& dotnet $clangSharpSourceToWinmdBin --sourceDir $metadataSourcePath --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName
