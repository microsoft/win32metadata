
$projectionProj = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32\CsWin32.csproj"
& dotnet build $projectionProj -c Release

$csWin32exe = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32\bin\Release\netcoreapp3.1\CsWin32.exe"
$metadataDll = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\Win32MetadataLib\bin\Release\netstandard2.0\Win32MetadataLib.dll"
$riaaMappings = Join-Path -Path $PSScriptRoot -ChildPath "..\generation\CsWin32\RIAAMappings.txt"
$projectedOutputDir = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\CsWin32ProjectionLib"

& $csWin32exe $metadataDll $riaaMappings $projectedOutputDir

$projectionLibProj = Join-Path -Path $projectedOutputDir "CsWin32ProjectionLib.csproj"
& dotnet build $projectionLibProj -c Release
