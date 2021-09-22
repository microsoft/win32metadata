
dotnet pack "$PSScriptRoot\..\sources\packages.proj" -c Release

"$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

dotnet pack "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples" -c Release
