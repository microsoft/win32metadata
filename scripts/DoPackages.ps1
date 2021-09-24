$ErrorActionPreference = "Stop"
. $PSScriptRoot\CommonUtils.ps1

dotnet pack "$PSScriptRoot\..\sources\packages.proj" -c Release
ThrowOnNativeProcessError

& "$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

dotnet pack "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release
ThrowOnNativeProcessError

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples" -c Release
ThrowOnNativeProcessError
