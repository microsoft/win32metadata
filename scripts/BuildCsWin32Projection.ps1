
$projectionProj = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32\CsWin32.csproj"
& dotnet build $projectionProj -c Release

$csWin32exe = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32\bin\Release\netcoreapp3.1\CsWin32.exe"
$metadataWinmd = Join-Path -Path $PSScriptRoot -ChildPath "..\bin\Microsoft.Windows.SdK.Win32Metadata.winmd"
$riaaMappings = Join-Path -Path $PSScriptRoot -ChildPath "..\generation\CsWin32\RIAAMappings.txt"
$projectedOutputDir = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32ProjectionLib"

& $csWin32exe $metadataDll $riaaMappings $projectedOutputDir

$projectionLibProj = Join-Path -Path $projectedOutputDir "CsWin32ProjectionLib.csproj"
& dotnet build $projectionLibProj -c Release
