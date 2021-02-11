
param
(
    [Parameter(Mandatory=$true)]
    [string]
    $sdkBinDir,

    [Parameter(Mandatory=$true)]
    [string]
    $includeDir,

    [Parameter(Mandatory=$true)]
    [string]
    $outputDir
)

if (!(Test-Path -path $sdkBinDir))
{
    Write-Output "Error: Couldn't find $sdkBinDir."
    exit -1
}

if (!(Test-Path -path $includeDir))
{
    Write-Output "Error: Couldn't find $includeDir."
    exit -1
}

. "$PSScriptRoot\CommonUtils.ps1"

if (Test-Path -path $outputDir)
{
    Remove-Item $outputDir -r
}

$scratchDir = "$outputDir\scratch"

Create-Directory $outputDir
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

Write-Output "Updating annotations in idl files..."

$idlFiles = Get-ChildItem "$includeDir\um\*.idl","$includeDir\shared\*.idl"
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

    $fixedIdlFile =  "$outputDir\$($idlFile.Name)"
    & $PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1 -inputFileName $idlFile.FullName -outputFileName $fixedIdlFile

    [void]$foundIdlFiles.Add($idlFile)
}

$foundIdlFiles | ForEach-Object -Parallel {
    $idlFile = $_
 
    $origHeader = [io.path]::ChangeExtension($idlFile.FullName, "h")
    $savedOrigHeader = [io.path]::ChangeExtension($idlFile.FullName, "orig.h")
    if (!(Test-Path -Path $savedOrigHeader))
    {
        Copy-Item -Path $origHeader -Destination $savedOrigHeader
    }

    $fixedIdlFile =  "$using:outputDir\$($idlFile.Name)"

    $inputFileName = $fixedIdlFile.ToLowerInvariant()
    $outputHeader = "$using:outputDir\$($idlFile.BaseName).h".ToLowerInvariant()
    $outputLog = "$using:scratchDir\$($idlFile.BaseName).txt"
    & "$using:midl" $inputFileName /out $using:scratchDir /header $outputHeader /no_warn /DUNICODE /D_UNICODE /DWINVER=0x0A00 -D_APISET_MINWIN_VERSION=0x010F /DNTDDI_VERSION=0x0A00000B /DBUILD_UMS_ENABLED=0 /DBUILD_WOW64_ENABLED=0 /DBUILD_ARM64X_ENABLED=0 /DEXECUTABLE_WRITES_SUPPORT=0 -D_USE_DECLSPECS_FOR_SAL=1 -D_CONTROL_FLOW_GUARD_SVCTAB=1  /Di386 /D_X86_ /D_WCHAR_T_DEFINED /no_stamp /nologo  /no_settings_comment /lcid 1033 -sal /win32 -target NT100 /Zp8 /I$using:outputDir /I$using:includeDir\um /I$using:includeDir\shared /I$using:includeDir\winrt /I$using:extraIncPath 3>&1 2>&1 > $outputLog
    if ($LASTEXITCODE -ne 0)
    {
        $outText = "Failed for $($idlFile.FullName)`r`n"
        $outText += Get-Content -Path $outputLog -Raw
        Write-Error $outText
    }
    else 
    {
        Write-Output "Compiled $($idlFile.Name)"

        # This line gets pulled out in the Windows build of the header. We need to do the same or it won't compile
        if ($idlFile.BaseName -eq "d3d10_1")
        {
            (Get-Content -path $outputHeader -Raw).Replace("#include ""d3d10.h""`r`n","") | Set-Content -Path $outputHeader
        }

        Copy-Item -Path $outputHeader -Destination $origHeader
    }
} -ThrottleLimit $throttleCount
