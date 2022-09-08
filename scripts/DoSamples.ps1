param
(
    [switch]$skipInstallTools
)

. $PSScriptRoot\CommonUtils.ps1

if (!$skipInstallTools)
{
    Install-BuildTools
}

Write-Host "*** Building samples..." -ForegroundColor Blue

& "$PSScriptRoot\UpdateGlobalJsonWinmdGeneratorVersion.ps1"

$cppSampleProj = "$rootDir\sources\GeneratorSdk\samples\CppProjectForScraping\CppProjectForScraping.vcxproj"

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=Win32 /t:rebuild "-bl:$PSScriptRoot\..\bin\logs\samples_cppSample_win32.binlog"
ThrowOnNativeProcessError

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=x64 /t:rebuild "-bl:$PSScriptRoot\..\bin\logs\samples_cppSample_x64.binlog"
ThrowOnNativeProcessError

msbuild $cppSampleProj /p:Configuration=Release /p:Platform=ARM64 /t:rebuild "-bl:$PSScriptRoot\..\bin\logs\samples_cppSample_arm64.binlog"
ThrowOnNativeProcessError

dotnet clean "$PSScriptRoot\..\sources\GeneratorSdk\samples"
ThrowOnNativeProcessError

dotnet build "$PSScriptRoot\..\sources\GeneratorSdk\samples" -c Release "-bl:$PSScriptRoot\..\bin\logs\samples.binlog"
ThrowOnNativeProcessError
