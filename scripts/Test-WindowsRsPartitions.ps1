<#
.SYNOPSIS
    Preflights WinSDK partitions independently with the Rust metadata pipeline.

.DESCRIPTION
    Runs one isolated process per partition, scraping x64, x86, and arm64 and
    compiling the resulting RDL into a WinMD. Independent partitions run with
    bounded concurrency so one failure does not hide failures in later partitions.

.PARAMETER Partition
    Partition names under generation\WinSDK\Partitions. Defaults to all partitions.

.PARAMETER ThrottleLimit
    Maximum number of partition processes. Defaults to at most eight.

.PARAMETER SkipBuild
    Uses the existing release build of win32metadata-tools.

.PARAMETER Clean
    Removes the previous preflight output before starting.
#>
[CmdletBinding()]
param(
    [string[]]$Partition = @(),
    [ValidateRange(1, 64)]
    [int]$ThrottleLimit = [Math]::Min([Environment]::ProcessorCount, 8),
    [switch]$SkipBuild,
    [switch]$Clean
)

. "$PSScriptRoot\CommonUtils.ps1"

$ErrorActionPreference = "Stop"
$tool = Join-Path $rootDir "bin\GeneratorSdk\tools\win-x64\win32metadata-tools.exe"
$headerRoot = $recompiledIdlHeadersDir
$localIncludes = Join-Path $windowsWin32ProjectRoot "inc"
$outputRoot = Join-Path $windowsWin32ProjectRoot "obj\partition-preflight"
$workRoot = Join-Path $outputRoot "work"
$logRoot = Join-Path $outputRoot "logs"

if ($Clean -and (Test-Path $outputRoot)) {
    Remove-Item $outputRoot -Recurse -Force
}
New-Item -ItemType Directory -Force -Path $workRoot, $logRoot | Out-Null

if (!$SkipBuild) {
    & "$PSScriptRoot\Build-Win32MetadataTools.ps1" -OutputDir (Split-Path $tool)
}
if (!(Test-Path $tool)) {
    throw "Staged windows-rs metadata tool was not found at '$tool'. Run without -SkipBuild first."
}

if ($Partition.Count -eq 0) {
    $Partition = Get-ChildItem (Join-Path $windowsWin32ProjectRoot "Partitions") -Directory |
        Where-Object { Test-Path (Join-Path $_.FullName "main.cpp") } |
        Sort-Object Name |
        Select-Object -ExpandProperty Name
}

$partitionPaths = foreach ($name in $Partition) {
    $main = Join-Path $windowsWin32ProjectRoot "Partitions\$name\main.cpp"
    if (!(Test-Path $main)) {
        throw "Partition '$name' was not found at '$main'."
    }
    [pscustomobject]@{ Name = $name; Main = $main }
}

Write-Host "Preflighting $($partitionPaths.Count) partition(s) for x64, x86, and arm64"
Write-Host "Throttle: $ThrottleLimit"

$started = Get-Date
$results = @($partitionPaths | ForEach-Object -ThrottleLimit $ThrottleLimit -Parallel {
    $item = $_
    $tool = $using:tool
    $localIncludes = $using:localIncludes
    $headerRoot = $using:headerRoot
    $workRoot = $using:workRoot
    $logRoot = $using:logRoot

    $jobRoot = Join-Path $workRoot $item.Name
    $output = Join-Path $jobRoot "$($item.Name).winmd"
    $log = Join-Path $logRoot "$($item.Name).log"
    New-Item -ItemType Directory -Force -Path $jobRoot | Out-Null

    $stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
    $messages = @(& $tool scrape `
        --include $localIncludes `
        --include $headerRoot `
        --partition $item.Main `
        --arch x64 --arch x86 --arch arm64 `
        --output $output `
        --obj $jobRoot 2>&1 | ForEach-Object { $_.ToString() })
    $exitCode = $LASTEXITCODE
    $stopwatch.Stop()
    [System.IO.File]::WriteAllLines($log, $messages)

    if ($exitCode -eq 0) {
        Remove-Item $jobRoot -Recurse -Force
    }

    [pscustomobject]@{
        partition = $item.Name
        success = $exitCode -eq 0
        exitCode = $exitCode
        seconds = [Math]::Round($stopwatch.Elapsed.TotalSeconds, 3)
        log = $log
        evidence = if ($exitCode -eq 0) { $null } else { $jobRoot }
        error = if ($exitCode -eq 0) { $null } else {
            ($messages | Select-Object -Last 10) -join [Environment]::NewLine
        }
    }
})

$finished = Get-Date
$json = Join-Path $outputRoot "results.json"
$csv = Join-Path $outputRoot "results.csv"
$summary = [pscustomobject]@{
    started = $started.ToString("o")
    finished = $finished.ToString("o")
    elapsedSeconds = [Math]::Round(($finished - $started).TotalSeconds, 3)
    throttleLimit = $ThrottleLimit
    architectures = @("x64", "x86", "arm64")
    passed = @($results | Where-Object success).Count
    failed = @($results | Where-Object { !$_.success }).Count
    results = $results
}
[System.IO.File]::WriteAllText($json, ($summary | ConvertTo-Json -Depth 5))
$results | Export-Csv $csv -NoTypeInformation

$results |
    Sort-Object success, partition |
    Format-Table partition, success, seconds, log -AutoSize
Write-Host "Passed: $($summary.passed); failed: $($summary.failed)"
Write-Host "Results: $json"

if ($summary.failed -ne 0) {
    exit 1
}
