param
(
    [string]
    $assemblyVersion
)

. "$PSScriptRoot\CommonUtils.ps1"

if (!$assemblyVersion)
{
    $assemblyVersion = $defaultWinSDKNugetVersion
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

$remapFileName = "$emitterDir\remap.rsp"
$autoTypesFileName = "$emitterDir\autoTypes.rsp"
$requiredNamespacesForNames = "$emitterDir\requiredNamespacesForNames.rsp"

Write-Output "`n"
Write-Output "Creating $outputWinmdFileName..."
Write-Output "Calling: dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName"

& dotnet $clangSharpSourceToWinmdBin --sourceDir $emitterDir --interopFileName $metadataInteropBin --outputFileName $outputWinmdFileName --version $assemblyVersion @$remapFileName @$requiredNamespacesForNames @$autoTypesFileName
