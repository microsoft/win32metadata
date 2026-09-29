<#
.SYNOPSIS
    Benchmarks complete unpatched and patched Windows metadata generation.

.DESCRIPTION
    Builds the native tool once, prepares a clean SDK header tree before the
    patched tree, and measures individual and combined architecture generation.
    Results, producer logs, output hashes, and metadata row counts are written
    under OutputRoot.
#>
[CmdletBinding()]
param(
    [ValidateSet("unpatched", "patched", "both")]
    [string]$Variant = "both",

    [ValidateSet("x64", "x86", "arm64")]
    [string[]]$Architecture = @("x64", "x86", "arm64"),

    [string[]]$Partition = @(),

    [string]$OutputRoot = "",

    [switch]$SkipBuild,

    [switch]$SkipHeaderPreparation,

    [switch]$SkipIndividual,

    [switch]$SkipCombined
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"

Add-Type @"
using System;
using System.Runtime.InteropServices;
public static class Win32MetadataSystemTimes
{
    [StructLayout(LayoutKind.Sequential)]
    public struct FileTime
    {
        public uint Low;
        public uint High;
        public ulong Value => ((ulong)High << 32) | Low;
    }

    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool GetSystemTimes(
        out FileTime idle,
        out FileTime kernel,
        out FileTime user);
}
"@
Add-Type -AssemblyName System.Reflection.Metadata

function Get-SystemCpuTicks {
    $idle = [Win32MetadataSystemTimes+FileTime]::new()
    $kernel = [Win32MetadataSystemTimes+FileTime]::new()
    $user = [Win32MetadataSystemTimes+FileTime]::new()
    if (![Win32MetadataSystemTimes]::GetSystemTimes(
        [ref]$idle,
        [ref]$kernel,
        [ref]$user)) {
        throw "GetSystemTimes failed."
    }

    [pscustomobject]@{
        idle = $idle.Value
        kernel = $kernel.Value
        user = $user.Value
    }
}

function Invoke-MeasuredProcess {
    param(
        [Parameter(Mandatory)]
        [string]$FilePath,

        [Parameter(Mandatory)]
        [string[]]$ArgumentList,

        [Parameter(Mandatory)]
        [string]$LogPrefix,

        [hashtable]$Environment = @{}
    )

    $stdoutPath = "$LogPrefix.stdout.log"
    $stderrPath = "$LogPrefix.stderr.log"
    New-Item -ItemType Directory -Force -Path (Split-Path $LogPrefix) | Out-Null

    $startCpu = Get-SystemCpuTicks
    $started = Get-Date
    $stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
    $startInfo = [System.Diagnostics.ProcessStartInfo]::new()
    $startInfo.FileName = $FilePath
    $startInfo.UseShellExecute = $false
    $startInfo.CreateNoWindow = $true
    $startInfo.RedirectStandardOutput = $true
    $startInfo.RedirectStandardError = $true
    foreach ($argument in $ArgumentList) {
        $startInfo.ArgumentList.Add($argument)
    }
    foreach ($entry in $Environment.GetEnumerator()) {
        $startInfo.Environment[$entry.Key] = $entry.Value
    }

    $process = [System.Diagnostics.Process]::new()
    $process.StartInfo = $startInfo
    if (!$process.Start()) {
        throw "Failed to start '$FilePath'."
    }

    $stdoutTask = $process.StandardOutput.ReadToEndAsync()
    $stderrTask = $process.StandardError.ReadToEndAsync()
    $process.WaitForExit()
    $stdout = $stdoutTask.GetAwaiter().GetResult()
    $stderr = $stderrTask.GetAwaiter().GetResult()
    $stopwatch.Stop()
    $finished = Get-Date
    $endCpu = Get-SystemCpuTicks

    [System.IO.File]::WriteAllText($stdoutPath, $stdout)
    [System.IO.File]::WriteAllText($stderrPath, $stderr)

    $busyTicks =
        ($endCpu.kernel - $startCpu.kernel) +
        ($endCpu.user - $startCpu.user) -
        ($endCpu.idle - $startCpu.idle)
    $measurement = [pscustomobject]@{
        started = $started.ToString("o")
        finished = $finished.ToString("o")
        wallSeconds = [Math]::Round($stopwatch.Elapsed.TotalSeconds, 3)
        processCpuSeconds = [Math]::Round($process.TotalProcessorTime.TotalSeconds, 3)
        aggregateSystemCpuSeconds = [Math]::Round($busyTicks / 10000000, 3)
        exitCode = $process.ExitCode
        stdoutLog = $stdoutPath
        stderrLog = $stderrPath
        stdout = $stdout
        stderr = $stderr
    }
    $process.Dispose()
    $measurement
}

function Get-ProducerMetricLines {
    param(
        [string]$Text
    )

    @($Text -split "\r?\n" | Where-Object {
        $_ -match "(?i)\b(phase|input|header|cursor|fact|probe|synthetic|retry|retries|declaration|metadata)\b"
    })
}

function Get-WinmdSummary {
    param(
        [Parameter(Mandatory)]
        [string]$Path
    )

    $stream = [System.IO.File]::OpenRead($Path)
    try {
        $peReader = [System.Reflection.PortableExecutable.PEReader]::new($stream)
        $metadataReader = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($peReader)
        [pscustomobject]@{
            path = [System.IO.Path]::GetFullPath($Path)
            bytes = $stream.Length
            sha256 = (Get-FileHash $Path -Algorithm SHA256).Hash
            typeDefinitions = $metadataReader.TypeDefinitions.Count
            methodDefinitions = $metadataReader.MethodDefinitions.Count
            fieldDefinitions = $metadataReader.FieldDefinitions.Count
            customAttributes = $metadataReader.CustomAttributes.Count
        }
    }
    finally {
        if ($peReader) {
            $peReader.Dispose()
        }
        $stream.Dispose()
    }
}

function New-SyntheticPartitions {
    param(
        [Parameter(Mandatory)]
        [string[]]$SourcePaths,

        [Parameter(Mandatory)]
        [string]$Destination
    )

    New-Item -ItemType Directory -Force -Path $Destination | Out-Null
    @($SourcePaths | ForEach-Object {
        $sourcePath = [System.IO.Path]::GetFullPath($_)
        $partitionName = Split-Path (Split-Path $sourcePath -Parent) -Leaf
        $partitionDirectory = Join-Path $Destination $partitionName
        New-Item -ItemType Directory -Force -Path $partitionDirectory | Out-Null
        $wrapper = Join-Path $partitionDirectory "main.cpp"
        $content = @"
#include <win32metadata_annotations.h>
#include "$sourcePath"
"@
        [System.IO.File]::WriteAllText(
            $wrapper,
            $content,
            [System.Text.UTF8Encoding]::new($false))
        $wrapper
    })
}

if (!$OutputRoot) {
    $timestamp = Get-Date -Format "yyyyMMdd-HHmmss"
    $OutputRoot = Join-Path $rootDir "obj\WindowsRsBenchmarks\$timestamp"
}
$OutputRoot = [System.IO.Path]::GetFullPath($OutputRoot)
New-Item -ItemType Directory -Force -Path $OutputRoot | Out-Null

Install-BuildTools

$toolDir = Join-Path $rootDir "bin\GeneratorSdk\tools\win-x64"
$tool = Join-Path $toolDir "win32metadata-tools.exe"
$requestedVariants = if ($Variant -eq "both") { @("unpatched", "patched") } else { @($Variant) }
$results = [ordered]@{
    started = (Get-Date).ToString("o")
    logicalProcessors = [Environment]::ProcessorCount
    requestedVariants = [string[]]$requestedVariants
    requestedArchitectures = [string[]]$Architecture
    build = $null
    variants = @()
}

if (!$SkipBuild) {
    $build = Invoke-MeasuredProcess `
        -FilePath (Join-Path $PSHOME "pwsh.exe") `
        -ArgumentList @(
            "-NoProfile",
            "-File", (Join-Path $PSScriptRoot "Build-Win32MetadataTools.ps1"),
            "-OutputDir", $toolDir
        ) `
        -LogPrefix (Join-Path $OutputRoot "build")
    if ($build.exitCode -ne 0) {
        throw "Native tool build failed. See '$($build.stderrLog)'."
    }
    $results.build = $build | Select-Object * -ExcludeProperty stdout, stderr
}
elseif (!(Test-Path $tool)) {
    throw "The staged native tool was not found at '$tool'."
}

$usePartitionRoot = $Partition.Count -eq 0
if ($usePartitionRoot) {
    $Partition = Get-ChildItem (Join-Path $windowsWin32ProjectRoot "Partitions") -Directory |
        Where-Object { Test-Path (Join-Path $_.FullName "main.cpp") } |
        Sort-Object Name |
        Select-Object -ExpandProperty Name
}

$partitionPaths = foreach ($name in $Partition) {
    $path = Join-Path $windowsWin32ProjectRoot "Partitions\$name\main.cpp"
    if (!(Test-Path $path)) {
        throw "Partition '$name' was not found at '$path'."
    }
    $path
}

$scopeHeaders = @(
    "activation.h", "CoreWindow.h", "corewindow.h", "DocumentSource.h", "documentsource.h",
    "EventToken.h", "eventtoken.h", "hstring.h", "inspectable.h", "manual.h",
    "MemoryBuffer.h", "memorybuffer.h", "midlbase.h", "rdpappcontainerclient.h", "roapi.h",
    "robuffer.h", "roerrorapi.h", "rometadata.h", "rometadataresolution.h",
    "roparameterizediid.h", "roregistrationapi.h", "shcore.h", "WeakReference.h",
    "weakreference.h", "webapplication.h", "windows.graphics.effects.interop.h",
    "windows.graphics.interop.h", "windows.ui.composition.interop.h", "winstring.h",
    "Wsdevlicensing.h", "wsdevlicensing.h"
)
$includePaths = @(
    (Join-Path $windowsWin32ProjectRoot "AdditionalHeaders"),
    (Join-Path $windowsWin32ProjectRoot "Partitions\Com.StructuredStorage"),
    (Join-Path $windowsWin32ProjectRoot "inc"),
    $recompiledIdlHeadersDir
)
$sdkLibRoot = Join-Path (Get-WinSdkCppX64PkgPath) "c\um\x64"
$assemblyVersion = nbgv get-version -v AssemblyVersion
$variants = if ($Variant -eq "both") { @("unpatched", "patched") } else { @($Variant) }

foreach ($currentVariant in $variants) {
    $variantRoot = Join-Path $OutputRoot $currentVariant
    New-Item -ItemType Directory -Force -Path $variantRoot | Out-Null

    $headerPreparation = $null
    if (!$SkipHeaderPreparation) {
        $headerArguments = @(
            "-NoProfile",
            "-File", (Join-Path $PSScriptRoot "RecompileIdlFilesForScraping.ps1"),
            "-SkipInstallTools"
        )
        if ($currentVariant -eq "unpatched") {
            $headerArguments += "-SkipSDKPatches"
        }
        $headerPreparation = Invoke-MeasuredProcess `
            -FilePath (Join-Path $PSHOME "pwsh.exe") `
            -ArgumentList $headerArguments `
            -LogPrefix (Join-Path $variantRoot "header-preparation")
        if ($headerPreparation.exitCode -ne 0) {
            throw "$currentVariant header preparation failed. See '$($headerPreparation.stderrLog)'."
        }
    }

    $headers = Get-ChildItem $recompiledIdlHeadersDir -File -Recurse
    $generationPartitions = $partitionPaths
    if ($currentVariant -eq "unpatched") {
        $generationPartitions = New-SyntheticPartitions `
            -SourcePaths $partitionPaths `
            -Destination (Join-Path $variantRoot "synthetic-partitions")
    }
    $syntheticTranslationUnits = if ($currentVariant -eq "unpatched") {
        $generationPartitions.Count
    }
    else {
        0
    }
    $variantResult = [ordered]@{
        variant = $currentVariant
        patchCount = if ($currentVariant -eq "patched") {
            @(Get-ChildItem (Join-Path $windowsWin32ProjectRoot "patches") -File -Recurse -Filter "*.patch").Count
        }
        else {
            0
        }
        partitionCount = $partitionPaths.Count
        syntheticTranslationUnits = $syntheticTranslationUnits
        headerCount = @($headers | Where-Object Extension -eq ".h").Count
        inputFileCount = $headers.Count
        inputBytes = ($headers | Measure-Object Length -Sum).Sum
        headerPreparation = if ($headerPreparation) {
            $headerPreparation | Select-Object * -ExcludeProperty stdout, stderr
        }
        else {
            $null
        }
        generations = @()
    }

    $runs = @()
    if (!$SkipIndividual) {
        foreach ($arch in $Architecture) {
            $runs += [pscustomobject]@{
                name = $arch
                architectures = @($arch)
            }
        }
    }
    if (!$SkipCombined) {
        $runs += [pscustomobject]@{
            name = "combined"
            architectures = $Architecture
        }
    }

    foreach ($run in $runs) {
        $runRoot = Join-Path $variantRoot $run.name
        $output = Join-Path $runRoot "Windows.Win32.winmd"
        $arguments = @("scrape")
        if ($usePartitionRoot) {
            $partitionRoot = if ($currentVariant -eq "unpatched") {
                Join-Path $variantRoot "synthetic-partitions"
            }
            else {
                Join-Path $windowsWin32ProjectRoot "Partitions"
            }
            $arguments += @("--partition-root", $partitionRoot)
        }
        else {
            foreach ($path in $generationPartitions) {
                $arguments += @("--partition", $path)
            }
        }
        foreach ($path in $includePaths) {
            $arguments += @("--include", $path)
        }
        $arguments += @("--lib", $sdkLibRoot)
        foreach ($arch in $run.architectures) {
            $arguments += @("--arch", $arch)
        }
        foreach ($scopeHeader in $scopeHeaders) {
            $arguments += @("--scope-header", $scopeHeader)
        }
        $arguments += @(
            "--namespace", "Windows.Win32",
            "--assembly-name", "Windows.Win32",
            "--assembly-version", $assemblyVersion,
            "--obj", (Join-Path $runRoot "obj"),
            "--output", $output
        )

        $measurement = Invoke-MeasuredProcess `
            -FilePath $tool `
            -ArgumentList $arguments `
            -Environment @{ LIBCLANG_PATH = $toolDir } `
            -LogPrefix (Join-Path $runRoot "generation")
        if ($measurement.exitCode -ne 0) {
            throw "$currentVariant $($run.name) generation failed. See '$($measurement.stderrLog)'."
        }

        $variantResult.generations += [pscustomobject]@{
            name = $run.name
            architectures = $run.architectures
            timing = $measurement | Select-Object * -ExcludeProperty stdout, stderr
            producerMetrics = [string[]](Get-ProducerMetricLines ($measurement.stdout + "`n" + $measurement.stderr))
            output = Get-WinmdSummary $output
        }
    }

    $results.variants += [pscustomobject]$variantResult
    [System.IO.File]::WriteAllText(
        (Join-Path $OutputRoot "results.json"),
        ($results | ConvertTo-Json -Depth 8))
}

$results.finished = (Get-Date).ToString("o")
[System.IO.File]::WriteAllText(
    (Join-Path $OutputRoot "results.json"),
    ($results | ConvertTo-Json -Depth 8))

$results.variants |
    ForEach-Object {
        $variantResultItem = $_
        foreach ($generation in $variantResultItem.generations) {
            [pscustomobject]@{
                variant = $variantResultItem.variant
                run = $generation.name
                wallSeconds = $generation.timing.wallSeconds
                processCpuSeconds = $generation.timing.processCpuSeconds
                sha256 = $generation.output.sha256
                types = $generation.output.typeDefinitions
                methods = $generation.output.methodDefinitions
                fields = $generation.output.fieldDefinitions
            }
        }
    } |
    Format-Table -AutoSize

Write-Host "Benchmark results: $(Join-Path $OutputRoot 'results.json')"
