$defaultWinSDKNugetVersion = "10.0.19041.5"

$rootDir = [System.IO.Path]::GetFullPath("$PSScriptRoot\..")
$toolsDir = "$rootDir\tools"
$binDir = "$rootDir\bin"
$sourcesDir = "$rootDir\sources"
$generationDir = "$rootDir\generation"
$scraperDir = "$generationDir\scraper"
$emitterDir = "$generationDir\emitter"
$partitionsDir = "$scraperDir\Partitions"
$sdkApiPath = "$rootDir\ext\sdk-api"
$sdkGeneratedSourceDir = "$emitterDir\generated"
$artifactsDir = "$scraperDir\obj"
$recompiledIdlHeadersDir = "$artifactsDir\RecompiledIdlHeaders"
$metadataToolsBin = "$binDir\release\net5.0"

if (Test-Path -Path $binDir -PathType leaf)
{
    Remove-Item $binDir
}

if (!(Test-Path -Path $binDir))
{
    New-Item -ItemType Directory -Force -Path $binDir | Out-Null
}

function Create-Directory([string[]] $Path)
{
    if (!(Test-Path -Path $Path))
    {
        New-Item -Path $Path -Force -ItemType "Directory" | Out-Null
    }
}

function Remove-Directory([string[]] $Path)
{
    if ((Test-Path -Path $Path))
    {
        Remove-Item $Path -Recurse
    }
}

function Install-DotNetTool
{
    Param ([string] $Name, [string] $Version = '')

    if ($Version -ne '')
    {
        $installed = & dotnet tool list -g | select-string -Pattern "$Name\s+$Version" -Raw
        if (($installed -eq $null) -or !$installed.Length)
        {
            & dotnet tool update --global $Name --version $Version
        }
    }
    else
    {
        $installed = & dotnet tool list -g | select-string -Pattern "$Name" -Raw
        if (($installed -eq $null) -or !$installed.Length)
        {
            & dotnet tool update --global $Name
        }
    }
}

function Install-BuildTools
{
    Install-DotNetTool -Name ClangSharpPInvokeGenerator -Version 11.0.0-beta3
    Install-DotNetTool -Name nbgv

    & dotnet build "$rootDir\buildtools" -c Release

    Update-VsInstallDir
}

function Replace-Text
{
    Param ([string] $path, [hashtable] $items)

    $content = Get-Content -path $path -Encoding UTF8
    foreach ($key in $items.Keys)
    {
        $content = $content.Replace($key, $items[$key]);
    }

    Set-Content -path $path -Encoding UTF8 -value $content
}

function Get-LibMappingsFile
{
    $libMappingOutputFileName = Join-Path -Path $scraperDir -ChildPath "libMappings.rsp"

    return $libMappingOutputFileName
}

function Get-BuildToolsNugetProps
{
    [xml]$buildNugetProps = Get-Content -path "$rootDir\obj\BuildTools\BuildTools.proj.nuget.g.props"
    return $buildNugetProps;
}

function Get-WinSdkCppPkgPath
{
    [xml]$buildNugetProps = Get-BuildToolsNugetProps
    return $buildNugetProps.Project.PropertyGroup.PkgMicrosoft_Windows_SDK_CPP.InnerText;
}

function Get-WinSdkCppX64PkgPath
{
    [xml]$buildNugetProps = Get-BuildToolsNugetProps
    return $buildNugetProps.Project.PropertyGroup.PkgMicrosoft_Windows_SDK_CPP_x64.InnerText;
}

function Invoke-PrepLibMappingsFile
{
    $libMappingOutputFileName = Get-LibMappingsFile
    if (!(Test-Path $libMappingOutputFileName))
    {
        Write-Output "Creating lib mapping file: $libMappingOutputFileName"

        $libPkgPath = Get-WinSdkCppX64PkgPath
        $libDirectory = "$libPkgPath\c\um\x64"
        & $PSScriptRoot\CreateProcLibMappingForAllLibs.ps1 -libDirectory $libDirectory -outputFileName $libMappingOutputFileName
    }
}

function Invoke-RecompileMidlHeaders
{
    if (!(Test-Path $recompiledIdlHeadersDir))
    {
        $zipFile = "$scraperDir\RecompiledIdlHeaders.zip"
        if (Test-Path $zipFile)
        {
            Write-Output "Unzipping recompiled headers from $zipFile..."
            Expand-Archive $zipFile -DestinationPath $artifactsDir
            return
        }

        Create-Directory $recompiledIdlHeadersDir

        $cppPkgPath = Get-WinSdkCppPkgPath
        $sdkIncludeDir = (Get-ChildItem -Path "$cppPkgPath\c\include").FullName

        Write-Output "Copying headers from Win SDK...$sdkIncludeDir to $recompiledIdlHeadersDir"
        copy-item -Path "$sdkIncludeDir\um" -destination "$recompiledIdlHeadersDir" -recurse
        copy-item -Path "$sdkIncludeDir\shared" -destination "$recompiledIdlHeadersDir" -recurse
        copy-item -Path "$sdkIncludeDir\winrt" -destination "$recompiledIdlHeadersDir" -recurse

        Write-Output "Recompiling midl headers with SAL annotations in $recompiledIdlHeadersDir"

        $version = $defaultWinSDKNugetVersion
        $sdkParts = $version.Split('.')
        $sdkVersion = "$($sdkParts[0]).$($sdkParts[1]).$($sdkParts[2]).0"

        $sdkBinDir = "$cppPkgPath\c\bin\$sdkVersion\x86"
        & $PSScriptRoot\RecompileIdlFilesForScraping.ps1 -sdkBinDir $sdkBinDir -includeDir $recompiledIdlHeadersDir

        Write-Output "Compressing headers to $zipFile..."
        Compress-Archive -Path $recompiledIdlHeadersDir -DestinationPath $zipFile
    }
}

function Get-VcDirPath
{
    param ($Arch = 'x64', $HostArch = 'x64')

    $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
    $installDir = & $vswhere -latest -products * -requires Microsoft.VisualStudio.Component.VC.Tools.x86.x64 -property installationPath
    if ($installDir)
    {
        $path = join-path $installDir 'VC\Auxiliary\Build\Microsoft.VCToolsVersion.default.txt'
        if (test-path $path)
        {
            $version = Get-Content -raw $path
            if ($version)
            {
                $version = $version.Trim()
                $path = join-path $installDir "VC\Tools\MSVC\$version\bin\Host$HostArch\$Arch"
                return $path
            }
        }
    }

    return $null
}

function Update-VsInstallDir
{
    if (!$env:VSINSTALLDIR)
    {
        $vswhere = "${env:ProgramFiles(x86)}\Microsoft Visual Studio\Installer\vswhere.exe"
        $env:VSINSTALLDIR = & $vswhere -latest -property installationPath
    }
}

function Get-OutputWinmdFileName
{
    param ($Arch = 'x64')

    if ($Arch -ne "crossarch")
    {
        $path = "$binDir\Windows.Win32.$Arch.winmd"
    }
    else
    {
        $path = "$binDir\Windows.Win32.winmd"
    }

    return $path
}

function Download-Nupkg
{
    Param ([string] $name, [string] $version, [string] $outputDir)

    $url = "https://www.nuget.org/api/v2/package/$name/$version"
    $output = "$outputDir\$name.$version.nupkg"

    $wc = New-Object System.Net.WebClient
    $wc.DownloadFile($url, $output)
}

function Get-ExcludedItems
{
    param ([string[]]$rspFiles)
    [hashtable]$excludedItems = @{}

    $inExcluded = $false
    foreach ($rsp in $rspFiles)
    {
        foreach ($line in Get-Content $rsp)
        {
            if ($line.StartsWith('--'))
            {
                $inExcluded = $line -eq "--exclude"
            }
            else
            {
                if ($inExcluded)
                {
                    $excludedItems[$line] = $true
                }
            }
        }
    }

    return $excludedItems
}
