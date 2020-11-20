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

$clangSharpSourceToWinmdPath = "$PSScriptRoot\..\sources\ClangSharpSourceToWinmd"
$clangSharpSourceToWinmdProj = "$clangSharpSourceToWinmdPath\ClangSharpSourceToWinmd.csproj"
$clangSharpSourceToWinmdBin = "$clangSharpSourceToWinmdPath\bin\Release\netcoreapp3.1\ClangSharpSourceToWinmd.dll"
& dotnet build $clangSharpSourceToWinmdProj -c Release

$metadataInteropPath = "$PSScriptRoot\..\sources\Win32MetadataInterop"
$metadataInteropProj = "$metadataInteropPath\Win32MetadataInterop.csproj"
$metadataInteropBin = "$metadataInteropPath\bin\Release\netstandard2.1\Microsoft.Windows.Sdk.Win32Metadata.Interop.dll"
& dotnet build $metadataInteropProj -c Release

$metadataSourcePath = "$PSScriptRoot\..\sources\Win32MetadataLib"
$outputWinmdFileName = "$PSScriptRoot\..\bin\Microsoft.Windows.SdK.Win32Metadata.winmd"

Write-Host
Write-Host "Creating $outputWinmdFileName..."
Write-Host "Calling: dotnet $clangSharpSourceToWinmdBin $metadataSourcePath $metadataInteropBin $outputWinmdFileName $assemblyVersion"

& dotnet $clangSharpSourceToWinmdBin $metadataSourcePath $metadataInteropBin $outputWinmdFileName $assemblyVersion
