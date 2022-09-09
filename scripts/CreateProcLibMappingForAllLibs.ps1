
. $PSScriptRoot\CommonUtils.ps1

$outputFileName = Join-Path -Path $windowsWin32ProjectRoot -ChildPath "libMappings.rsp"
$inputFileName = Join-Path -Path $windowsWin32ProjectRoot -ChildPath "libMappings.old.rsp"

if (!(Test-Path $inputFileName))
{
    Copy-Item $outputFileName $inputFileName
}

$libPkgPath = Get-WinSdkCppX64PkgPath
$libDirectory = "$libPkgPath\c\um\x64"

if (!(Test-Path -path $libDirectory))
{
    Write-Error "Couldn't find $libDirectory."
    exit -1
}

# Send these in first because we want to preference what they say over other libs
$libArg = "$libDirectory\onecoreuap.lib $libDirectory\kernel32.lib $libDirectory\d3d10.lib"

dotnet $metadataToolsBin\WinmdUtils.dll createLibRsp --lib $libDirectory\onecoreuap.lib $libDirectory\kernel32.lib $libDirectory\d3d10.lib --libDir $libDirectory --exclude ServiceMain DllMain GetDeviceID --inputRsp $inputFileName --outputRsp $outputFileName
ThrowOnNativeProcessError
