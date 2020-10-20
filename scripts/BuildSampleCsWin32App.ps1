
$binProj = Join-Path -Path $PSScriptRoot -ChildPath "..\tests\SampleCsWin32App\SampleCsWin32App.csproj"
& dotnet build $binProj -c Release
