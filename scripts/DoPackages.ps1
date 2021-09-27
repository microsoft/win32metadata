param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

dotnet pack "$PSScriptRoot\..\sources\packages.proj" -c Release
ThrowOnNativeProcessError

& "$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

dotnet clean "$PSScriptRoot\..\sources\GeneratorSdk\samples"
ThrowOnNativeProcessError

dotnet pack "$PSScriptRoot\..\sources\GeneratorSdk\samples\diasdk" -c Release
ThrowOnNativeProcessError

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples" -c Release
ThrowOnNativeProcessError
