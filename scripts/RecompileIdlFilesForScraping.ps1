. "$PSScriptRoot\CommonUtils.ps1"

if (Test-Path $recompiledIdlHeadersDir)
{
    Remove-Item $recompiledIdlHeadersDir -recurse
}

Create-Directory $recompiledIdlHeadersDir

$cppPkgPath = Get-WinSdkCppPkgPath
$sdkIncludeDir = (Get-ChildItem -Path "$cppPkgPath\c\include").FullName

if (!(Test-Path -path $sdkIncludeDir))
{
    Write-Error "Couldn't find $sdkIncludeDir."
    exit -1
}

Write-Host "Copying headers from Win SDK...$sdkIncludeDir to $recompiledIdlHeadersDir"
copy-item -Path "$sdkIncludeDir\um" -destination "$recompiledIdlHeadersDir" -recurse
copy-item -Path "$sdkIncludeDir\shared" -destination "$recompiledIdlHeadersDir" -recurse
copy-item -Path "$sdkIncludeDir\winrt" -destination "$recompiledIdlHeadersDir" -recurse
copy-item -Path "$sdkIncludeDir\ucrt" -destination "$recompiledIdlHeadersDir" -recurse

$d3dPkgPath = Get-BuildToolsNugetPropsProperty("PkgMicrosoft_Direct3D_D3D12")
$d3dIncludeDir = Join-Path $d3dPkgPath "build/native/include/"
Write-Host "Updating to latest Direct3D headers...$d3dIncludeDir to $recompiledIdlHeadersDir"
copy-item -Path "$d3dIncludeDir\*.*" -destination "$recompiledIdlHeadersDir\um" -Exclude dxgiformat.* -recurse
copy-item -Path "$d3dIncludeDir\dxgiformat.*" -destination "$recompiledIdlHeadersDir\shared" -recurse

Write-Host "Recompiling midl headers with SAL annotations in $recompiledIdlHeadersDir"

$version = [System.IO.Path]::GetFileName($cppPkgPath)
$sdkParts = $version.Split('.')
$sdkVersion = "$($sdkParts[0]).$($sdkParts[1]).$($sdkParts[2]).0"

$sdkBinDir = "$cppPkgPath\c\bin\$sdkVersion\x86"

if (!(Test-Path -path $sdkBinDir))
{
    Write-Error "Couldn't find $sdkBinDir."
    exit -1
}

$scratchDir = "$rootDir\obj\RecompileIdlScratch"
if (Test-Path -path $scratchDir)
{
    Remove-Item $scratchDir -r
}

Create-Directory $scratchDir

$midl = "$sdkBinDir\midl.exe"

$vcDirPath = Get-VcDirPath -Arch x86 -HostArch x86
if (!$env:Path.Contains($vcDirPath))
{
    $env:Path += ";$vcDirPath"
}

$excludedHeaders = @("cellularapi_oem", "certbcli", "microsoft.diagnostics.appanalysis", "PortableDeviceConnectImports", "wincrypt", "dxgicommon", "dxgitype" )
$extraIncPath = "$PSScriptRoot\inc"

$throttleCount = [System.Environment]::ProcessorCount / 2
if ($throttleCount -lt 2)
{
    $throttleCount = 2
}

Write-Host "Updating annotations in idl files..."

$idlFiles = Get-ChildItem "$sdkIncludeDir\um\*.idl","$sdkIncludeDir\shared\*.idl"
$foundIdlFiles = [System.Collections.ArrayList]@()
foreach ($idlFile in $idlFiles)
{
    if ($idlFile.BaseName -in $excludedHeaders)
    {
        continue
    }

    $origHeader = [io.path]::ChangeExtension($idlFile.FullName, "h")

    if (!(Test-Path -Path $origHeader))
    {
        continue
    }

    if ((select-string $origHeader -Quiet -pattern 'File created by MIDL compiler' -SimpleMatch) -eq $false)
    {
        continue
    }

    #if (!$idlFile.FullName.Contains("mfvirtualcamera"))
    #{
    #    continue
    #}

    $fixedIdlFile =  "$scratchDir\$($idlFile.Name)"
    & $PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1 -inputFileName $idlFile.FullName -outputFileName $fixedIdlFile

    [void]$foundIdlFiles.Add($idlFile)
}

$ErrorActionPreference = "Continue"
$foundIdlFiles | ForEach-Object -Parallel {
    $idlFile = $_

    $origHeader = [io.path]::ChangeExtension($idlFile.FullName, "h")

    $fixedIdlFile =  "$using:scratchDir\$($idlFile.Name)"

    $inputFileName = $fixedIdlFile.ToLowerInvariant()
    $outputHeader = "$using:scratchDir\$($idlFile.BaseName).h".ToLowerInvariant()
    $outputLog = "$using:scratchDir\$($idlFile.BaseName).txt"
    & "$using:midl" $inputFileName /out $using:scratchDir /header $outputHeader /no_warn /DUNICODE /D_UNICODE /DWINVER=0x0A00 -D_APISET_MINWIN_VERSION=0x010F /DNTDDI_VERSION=0x0A00000B /DBUILD_UMS_ENABLED=0 /DBUILD_WOW64_ENABLED=0 /DBUILD_ARM64X_ENABLED=0 /DEXECUTABLE_WRITES_SUPPORT=0 -D_USE_DECLSPECS_FOR_SAL=1 -D_CONTROL_FLOW_GUARD_SVCTAB=1 -DMIDL_PASS=1 /Di386 /D_X86_ /D_WCHAR_T_DEFINED /no_stamp /nologo  /no_settings_comment /lcid 1033 -sal /win32 -target NT100 /Zp8 /I$using:scratchDir /I$using:sdkIncludeDir\um /I$using:sdkIncludeDir\shared /I$using:sdkIncludeDir\winrt /I$using:extraIncPath 3>&1 2>&1 > $outputLog
    if ($LASTEXITCODE -ne 0)
    {
        $outText = "Failed for $($idlFile.FullName)`r`n"
        $outText += Get-Content -Path $outputLog -Raw
        Write-Error $outText
    }
    else
    {
        Write-Host "Compiled $($idlFile.Name)"

        # This line gets pulled out in the Windows build of the header. We need to do the same or it won't compile
        if ($idlFile.BaseName -eq "d3d10_1")
        {
            (Get-Content -path $outputHeader -Raw).Replace("#include ""d3d10.h""`r`n","") | Set-Content -Path $outputHeader
        }

        Copy-Item -Path $outputHeader -Destination $origHeader
    }
} -ThrottleLimit $throttleCount
$ErrorActionPreference = "Stop"
