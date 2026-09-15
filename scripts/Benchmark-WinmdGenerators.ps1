[CmdletBinding()]
param(
    [string]$LegacyRevision = "b34ca8cf14aac48d10c563a8c0a83d6a5684b556",
    [string]$OutputDirectory = "$PSScriptRoot\..\bin\benchmarks\winmd-generators",
    [string]$RustExecutable,
    [switch]$SkipSetup,
    [switch]$KeepLegacyWorktree
)

$ErrorActionPreference = "Stop"
$root = [System.IO.Path]::GetFullPath((Join-Path $PSScriptRoot ".."))
$output = [System.IO.Path]::GetFullPath($OutputDirectory)
$legacy = Join-Path $env:TEMP "win32metadata-generator-benchmark-legacy-$PID"
$partitions = @("Audio", "Direct3D9", "Mf", "Shell", "WinSock")

function Invoke-Native {
    param(
        [string]$FilePath,
        [string[]]$ArgumentList,
        [string]$WorkingDirectory
    )

    Push-Location $WorkingDirectory
    try {
        & $FilePath @ArgumentList
        if ($LASTEXITCODE -ne 0) {
            throw "'$FilePath' exited with code $LASTEXITCODE."
        }
    }
    finally {
        Pop-Location
    }
}

function ConvertTo-SingleQuoted {
    param([string]$Value)
    "'" + $Value.Replace("'", "''") + "'"
}

function Measure-ProcessTree {
    param(
        [string]$Name,
        [string]$WorkingDirectory,
        [string]$Command,
        [string]$LogPath
    )

    $runner = Join-Path $output "$Name.runner.ps1"
    $runnerText = @"
`$ErrorActionPreference = "Stop"
Set-Location $(ConvertTo-SingleQuoted $WorkingDirectory)
& {
$Command
} *>&1 | Tee-Object -FilePath $(ConvertTo-SingleQuoted $LogPath)
if (`$LASTEXITCODE -ne 0) { exit `$LASTEXITCODE }
"@
    [System.IO.File]::WriteAllText($runner, $runnerText)

    $stopwatch = [System.Diagnostics.Stopwatch]::StartNew()
    $process = Start-Process pwsh -ArgumentList @("-NoProfile", "-File", $runner) -PassThru
    $peakTree = [uint64]0
    $peakProcess = [uint64]0

    while (!$process.HasExited) {
        $rows = @(Get-CimInstance Win32_Process |
            Select-Object ProcessId, ParentProcessId, WorkingSetSize)
        $ids = [System.Collections.Generic.HashSet[uint32]]::new()
        [void]$ids.Add([uint32]$process.Id)
        do {
            $count = $ids.Count
            foreach ($row in $rows) {
                if ($ids.Contains([uint32]$row.ParentProcessId)) {
                    [void]$ids.Add([uint32]$row.ProcessId)
                }
            }
        } while ($ids.Count -ne $count)

        [uint64]$tree = 0
        foreach ($row in $rows) {
            if ($ids.Contains([uint32]$row.ProcessId)) {
                $workingSet = [uint64]$row.WorkingSetSize
                $tree += $workingSet
                if ($workingSet -gt $peakProcess) {
                    $peakProcess = $workingSet
                }
            }
        }
        if ($tree -gt $peakTree) {
            $peakTree = $tree
        }
        Start-Sleep -Milliseconds 250
        $process.Refresh()
    }

    $process.WaitForExit()
    $stopwatch.Stop()
    if ($process.ExitCode -ne 0) {
        throw "$Name failed with exit code $($process.ExitCode). See $LogPath."
    }

    [pscustomobject]@{
        name = $Name
        seconds = [math]::Round($stopwatch.Elapsed.TotalSeconds, 3)
        peakTreeWorkingSetBytes = $peakTree
        peakSingleProcessWorkingSetBytes = $peakProcess
        log = $LogPath
    }
}

New-Item -ItemType Directory -Force -Path $output | Out-Null

try {
    if (!$SkipSetup) {
        Invoke-Native git @("worktree", "add", "--detach", $legacy, $LegacyRevision) $root

        Invoke-Native dotnet @(
            "restore", "BuildTools\BuildTools.proj",
            "--configfile", "nuget.Config", "--verbosity", "quiet"
        ) $legacy
        Invoke-Native dotnet @(
            "build", "BuildTools", "-c", "Release",
            "--no-restore", "--verbosity", "minimal"
        ) $legacy
        Invoke-Native dotnet @(
            "restore", "generation\WinSDK\Windows.Win32.proj",
            "--configfile", "nuget.Config", "--verbosity", "quiet"
        ) $legacy

        if (!$RustExecutable) {
            Invoke-Native cargo @(
                "build", "--release", "--locked",
                "--manifest-path", "tools\rust\Cargo.toml"
            ) $root
        }
    }
    elseif (!(Test-Path $legacy)) {
        throw "-SkipSetup requires the legacy worktree at '$legacy'."
    }

    $encodedPartitions = $partitions -join "%2C"
    $legacyLog = Join-Path $output "legacy.log"
    $legacyCommand = @"
& dotnet build generation\WinSDK\Windows.Win32.proj -c Release -t:ScrapeHeaders '-p:PartitionFilter=$encodedPartitions' -p:ScanArch=crossarch --no-restore --verbosity minimal
"@

    $rustLog = Join-Path $output "rust.log"
    $rustOutput = Join-Path $output "rust-five-partitions.winmd"
    $partitionExpression = ($partitions | ForEach-Object { ConvertTo-SingleQuoted $_ }) -join ", "
    $toolArgument = if ($RustExecutable) {
        "-ToolPath $(ConvertTo-SingleQuoted ([System.IO.Path]::GetFullPath($RustExecutable)))"
    } else {
        ""
    }
    $rustCommand = @"
& .\scripts\Generate-WindowsRsWinmd.ps1 -Partition @($partitionExpression) -Architecture @('x64', 'x86', 'arm64') -OutputWinmd $(ConvertTo-SingleQuoted $rustOutput) -SkipBuild $toolArgument
"@

    $results = @(
        Measure-ProcessTree "legacy" $legacy $legacyCommand $legacyLog
        Measure-ProcessTree "rust" $root $rustCommand $rustLog
    )

    $report = [pscustomobject]@{
        timestampUtc = [DateTime]::UtcNow.ToString("o")
        machine = [pscustomobject]@{
            processorCount = [Environment]::ProcessorCount
            totalPhysicalMemoryBytes = (Get-CimInstance Win32_ComputerSystem).TotalPhysicalMemory
        }
        legacyRevision = $LegacyRevision
        currentRevision = (git -C $root rev-parse HEAD)
        partitions = $partitions
        architectures = @("x64", "x86", "arm64")
        results = $results
        caveat = "Legacy measures header scraping. Rust measures header scraping, RDL compilation, and WinMD architecture merge because it has no scrape-only entry point."
    }

    $json = Join-Path $output "results.json"
    [System.IO.File]::WriteAllText($json, ($report | ConvertTo-Json -Depth 6))
    $results | Format-Table name, seconds,
        @{Label="Peak tree GB"; Expression={[math]::Round($_.peakTreeWorkingSetBytes / 1GB, 2)}},
        @{Label="Peak process GB"; Expression={[math]::Round($_.peakSingleProcessWorkingSetBytes / 1GB, 2)}}
    Write-Host "Results: $json"
}
finally {
    if (!$KeepLegacyWorktree -and (Test-Path $legacy)) {
        Invoke-Native git @("worktree", "remove", "--force", $legacy) $root
    }
}
