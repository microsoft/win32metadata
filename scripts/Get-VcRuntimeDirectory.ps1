param
(
    [Parameter(Mandatory = $true)]
    [string]$NativeDirectory,
    [string]$RuntimeDirectory
)

$ErrorActionPreference = 'Stop'

function Get-NativeBinaryInfo([string]$Path)
{
    $reader = [System.IO.BinaryReader]::new([System.IO.File]::OpenRead($Path))
    try
    {
        if ($reader.BaseStream.Length -lt 64 -or $reader.ReadUInt16() -ne 0x5a4d)
        {
            throw "Not a PE binary: $Path"
        }

        $reader.BaseStream.Position = 0x3c
        $peOffset = $reader.ReadUInt32()
        if ($peOffset + 28 -gt $reader.BaseStream.Length)
        {
            throw "Invalid PE header: $Path"
        }

        $reader.BaseStream.Position = $peOffset
        if ($reader.ReadUInt32() -ne 0x00004550 -or $reader.ReadUInt16() -ne 0x8664)
        {
            throw "Expected an x64 PE binary: $Path"
        }

        $reader.BaseStream.Position = $peOffset + 24
        if ($reader.ReadUInt16() -ne 0x20b)
        {
            throw "Expected a PE32+ binary: $Path"
        }

        $major = $reader.ReadByte()
        $minor = $reader.ReadByte()
        return [version]"$major.$minor"
    }
    finally
    {
        $reader.Dispose()
    }
}

if (!$RuntimeDirectory)
{
    $redistRoot = $env:VCToolsRedistDir
    if (!$redistRoot)
    {
        $vsPath = & "$PSScriptRoot\Get-VSPath.ps1"
        $versionPath = Join-Path $vsPath 'VC\Auxiliary\Build\Microsoft.VCRedistVersion.default.txt'
        $redistVersion = (Get-Content -LiteralPath $versionPath -Raw).Trim()
        $redistRoot = Join-Path $vsPath "VC\Redist\MSVC\$redistVersion"
    }

    $crtDirectories = @(Get-ChildItem -LiteralPath (Join-Path $redistRoot 'x64') -Directory -Filter 'Microsoft.VC*.CRT')
    if ($crtDirectories.Count -ne 1)
    {
        throw "Expected one x64 CRT redistributable directory under '$redistRoot'. Set VcRuntimeDirectory to the desired Microsoft.VC*.CRT directory."
    }

    $RuntimeDirectory = $crtDirectories[0].FullName
}

$RuntimeDirectory = (Get-Item -LiteralPath $RuntimeDirectory).FullName.TrimEnd('\')
if ((Split-Path $RuntimeDirectory -Leaf) -notmatch '^Microsoft\.VC[0-9]+\.CRT$')
{
    throw "VcRuntimeDirectory must select a Visual Studio Microsoft.VC*.CRT redistributable directory, not a compiler or system directory."
}

foreach ($name in @('MSVCP140.dll', 'VCRUNTIME140.dll', 'VCRUNTIME140_1.dll'))
{
    if (!(Test-Path -LiteralPath (Join-Path $RuntimeDirectory $name) -PathType Leaf))
    {
        throw "Missing required VC runtime file '$name' in '$RuntimeDirectory'."
    }
}

$minimumVersion = [version]'14.0'
foreach ($name in @('libclang.dll', 'libClangSharp.dll'))
{
    $linkerVersion = Get-NativeBinaryInfo (Join-Path $NativeDirectory $name)
    if ($linkerVersion -gt $minimumVersion)
    {
        $minimumVersion = $linkerVersion
    }
}

foreach ($dll in Get-ChildItem -LiteralPath $RuntimeDirectory -File -Filter '*.dll')
{
    $null = Get-NativeBinaryInfo $dll.FullName
    $info = [System.Diagnostics.FileVersionInfo]::GetVersionInfo($dll.FullName)
    if (!$info.FileVersion)
    {
        throw "VC runtime file '$($dll.FullName)' has no file version."
    }

    $version = [version]"$($info.FileMajorPart).$($info.FileMinorPart).$($info.FileBuildPart).$($info.FilePrivatePart)"
    if ($version -lt $minimumVersion)
    {
        throw "VC runtime '$($dll.FullName)' ($version) is older than the native libraries' recorded linker version ($minimumVersion). Use a newer Visual Studio redistributable or set VcRuntimeDirectory explicitly."
    }
}

Write-Output $RuntimeDirectory
