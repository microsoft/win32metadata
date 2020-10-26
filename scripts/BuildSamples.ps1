
$binProj = Join-Path -Path $PSScriptRoot -ChildPath "..\tests\SampleCsWin32App\SampleCsWin32App.csproj"
& dotnet build $binProj -c Release

$binProj = Join-Path -Path $PSScriptRoot -ChildPath "..\tests\SampleD3DApp\SampleD3DApp.csproj"
& dotnet build $binProj -c Release
