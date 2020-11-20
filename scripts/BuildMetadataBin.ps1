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
    $metadataSourcePath = "$PSScriptRoot\..\sources\Win32MetadataSource"
}

$clangSharpSourceToWinmdPath = "$PSScriptRoot\..\sources\ClangSharpSourceToWinmd"
$clangSharpSourceToWinmdProj = "$clangSharpSourceToWinmdPath\ClangSharpSourceToWinmd.csproj"
$clangSharpSourceToWinmdBin = "$clangSharpSourceToWinmdPath\bin\Release\netcoreapp3.1\ClangSharpSourceToWinmd.dll"
& dotnet build $clangSharpSourceToWinmdProj -c Release

$metadataInteropPath = "$PSScriptRoot\..\sources\Win32MetadataInterop"
$metadataInteropProj = "$metadataInteropPath\Win32MetadataInterop.csproj"
$metadataInteropBin = "$metadataInteropPath\bin\Release\netstandard2.1\Microsoft.Windows.Sdk.Win32Metadata.Interop.dll"
& dotnet build $metadataInteropProj -c Release

$outputWinmdFileName = "$PSScriptRoot\..\bin\Microsoft.Windows.SdK.Win32Metadata.winmd"

Write-Host
Write-Host "Creating $outputWinmdFileName..."
Write-Host "Calling: dotnet $clangSharpSourceToWinmdBin $metadataSourcePath $metadataInteropBin $outputWinmdFileName $assemblyVersion"

& dotnet $clangSharpSourceToWinmdBin $metadataSourcePath $metadataInteropBin $outputWinmdFileName $assemblyVersion
