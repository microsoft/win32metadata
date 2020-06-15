
$binProj = Join-Path -Path $PSScriptRoot -ChildPath "..\sources\Win32MetadataLib\Win32MetadataLib.csproj"
& dotnet build $binProj -c Release
