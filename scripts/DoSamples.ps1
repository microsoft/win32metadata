param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Output "`e[36m*** Building samples...`e[0m"

& "$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

$cppSampleProj = "$rootDir\sources\GeneratorSdk\samples\CppProjectForScraping\CppProjectForScraping.vcxproj"

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=Win32 /t:rebuild
ThrowOnNativeProcessError

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=x64 /t:rebuild
ThrowOnNativeProcessError

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=ARM64 /t:rebuild
ThrowOnNativeProcessError

dotnet clean "$PSScriptRoot\..\sources\GeneratorSdk\samples"
ThrowOnNativeProcessError

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples" -c Release
ThrowOnNativeProcessError
