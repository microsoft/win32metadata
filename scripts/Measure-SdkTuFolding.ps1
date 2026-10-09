[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$TestExecutable,
    [Parameter(Mandatory)][string]$BuildEvidence,
    [Parameter(Mandatory)][string]$OutputRoot
)

$ErrorActionPreference = "Stop"
$root = Split-Path $PSScriptRoot
$TestExecutable = (Resolve-Path -LiteralPath $TestExecutable).Path
$BuildEvidence = (Resolve-Path -LiteralPath $BuildEvidence).Path
$OutputRoot = [System.IO.Path]::GetFullPath($OutputRoot)
if (Test-Path -LiteralPath $OutputRoot) { throw "OutputRoot must be fresh." }
New-Item -ItemType Directory -Path $OutputRoot | Out-Null
$binding = Get-Content -LiteralPath $BuildEvidence -Raw | ConvertFrom-Json
if ($binding.testExecutableSha256 -cne (Get-FileHash -LiteralPath $TestExecutable).Hash) {
    throw "Test executable does not match source-bound build evidence."
}
foreach ($source in $binding.sourceHashes | Where-Object { $_.Path.EndsWith(".rs") }) {
    if ($source.Hash -cne (Get-FileHash -LiteralPath $source.Path).Hash) {
        throw "Rust source changed after the bound build: $($source.Path)"
    }
}
Copy-Item -LiteralPath $BuildEvidence -Destination (Join-Path $OutputRoot "build-evidence.json")
$hashes = foreach ($path in $TestExecutable,$PSCommandPath,
    (Join-Path $root "tools\rust\src\scrape.rs"),
    (Join-Path $root "tools\rust\src\scrape\tests\sdk_folding.rs")) {
    Get-FileHash -LiteralPath $path | Select-Object Path,Hash
}
$hashes | ConvertTo-Json | Set-Content (Join-Path $OutputRoot "source-binary-hashes.json")
$runs = [System.Collections.Generic.List[object]]::new()
$baselineBytes = $null
$baselineInventory = $null
$baselineInputs = $null
$baselineArguments = $null
try {
    foreach ($pair in 1..3) {
        $order = if ($pair -eq 2) { @("folded","split") } else { @("split","folded") }
        foreach ($mode in $order) {
            $output = Join-Path $OutputRoot "$pair-$mode"
            $info = [System.Diagnostics.ProcessStartInfo]::new()
            $info.FileName = $TestExecutable
            $info.UseShellExecute = $false
            $info.RedirectStandardOutput = $true
            $info.RedirectStandardError = $true
            foreach ($argument in "--exact","scrape::tests::sdk_folding::sdk_split_and_folded_x64",
                "--ignored","--nocapture","--test-threads=1") {
                $info.ArgumentList.Add($argument)
            }
            $info.Environment["WIN32METADATA_FOLDING_OUTPUT"] = $output
            $info.Environment["WIN32METADATA_FOLDING_MODE"] = $mode
            $info.Environment["WIN32METADATA_FOLDING_ORDER"] = "split-first"
            $info.Environment["WINDOWS_CLANG_TIMINGS"] = "1"
            $process = [System.Diagnostics.Process]::new()
            $process.StartInfo = $info
            $wall = [System.Diagnostics.Stopwatch]::StartNew()
            try {
                if (!$process.Start()) { throw "Could not start $mode." }
                $stdout = $process.StandardOutput.ReadToEndAsync()
                $stderr = $process.StandardError.ReadToEndAsync()
                $peakWorkingSet = 0L
                $peakPagedMemory = 0L
                while (!$process.WaitForExit(50)) {
                    try {
                        $process.Refresh()
                        $peakWorkingSet = [Math]::Max($peakWorkingSet,$process.PeakWorkingSet64)
                        $peakPagedMemory = [Math]::Max($peakPagedMemory,$process.PeakPagedMemorySize64)
                    }
                    catch [System.InvalidOperationException] {
                        if (!$process.HasExited) { throw }
                    }
                }
                $process.WaitForExit()
                $wall.Stop()
                [System.IO.File]::WriteAllText("$output.stdout.log", $stdout.GetAwaiter().GetResult())
                [System.IO.File]::WriteAllText("$output.stderr.log", $stderr.GetAwaiter().GetResult())
                if ($process.ExitCode -ne 0) { throw "$mode failed; see $output.stderr.log" }
                $image = Join-Path $output "$mode\SdkFolding.winmd"
                $bytes = [System.IO.File]::ReadAllBytes($image)
                $inventory = [System.IO.File]::ReadAllText((Join-Path $output "$mode\inventory.rdl"))
                $inputs = [System.IO.File]::ReadAllText((Join-Path $output "inputs.tsv"))
                $arguments = [System.IO.File]::ReadAllText((Join-Path $output "arguments.txt"))
                if ($null -eq $baselineBytes) {
                    $baselineBytes = $bytes
                    $baselineInventory = $inventory
                    $baselineInputs = $inputs
                    $baselineArguments = $arguments
                }
                if (![System.Linq.Enumerable]::SequenceEqual[byte]($baselineBytes,$bytes) -or
                    $inventory -cne $baselineInventory -or $inputs -cne $baselineInputs -or
                    $arguments -cne $baselineArguments) {
                    throw "Complete image/inventory or frozen inputs changed in pair $pair $mode."
                }
                $contract = Get-Content -LiteralPath (Join-Path $output "$mode\readfile-contract.txt") -Raw
                if (!$contract.Contains("emitted_buffer_flags`tParamAttributes(18)")) {
                    throw "ReadFile flags changed in pair $pair $mode."
                }
                $timing = @{}
                Get-Content (Join-Path $output "$mode\measurement.tsv") | ForEach-Object {
                    $key,$value = $_ -split "`t",2
                    $timing[$key] = $value
                }
                $run = [pscustomobject]@{
                    pair = $pair
                    mode = $mode
                    command = @($TestExecutable) + @($info.ArgumentList)
                    environment = [ordered]@{
                        WIN32METADATA_FOLDING_MODE = $mode
                        WIN32METADATA_FOLDING_ORDER = "split-first"
                        WIN32METADATA_FOLDING_OUTPUT = $output
                        WINDOWS_CLANG_TIMINGS = "1"
                        CLANG_RESOURCE_DIR = $info.Environment["CLANG_RESOURCE_DIR"]
                        LIBCLANG_PATH = $info.Environment["LIBCLANG_PATH"]
                    }
                    output = $output
                    pipelineSeconds = [double]::Parse($timing.pipeline_seconds,
                        [System.Globalization.CultureInfo]::InvariantCulture)
                    wholeProcessSeconds = $wall.Elapsed.TotalSeconds
                    observedPeakWorkingSetBytes = $peakWorkingSet
                    observedPeakPagedMemoryBytes = $peakPagedMemory
                    memoryScope = "Observed lower bound from OS cumulative peak counters sampled every 50ms. Whole fresh process including native probe/readback; not pipeline-only or aggregate child memory."
                    imageSha256 = (Get-FileHash -LiteralPath $image).Hash
                    completeImageAndRdlEqual = $true
                }
                $runs.Add($run)
                Write-Output ($run | ConvertTo-Json -Compress -Depth 5)
            }
            finally { $process.Dispose() }
        }
    }
    $summary = foreach ($mode in "split","folded") {
        $values = @($runs | Where-Object mode -CEQ $mode |
            Select-Object -ExpandProperty pipelineSeconds | Sort-Object)
        [pscustomobject]@{ mode=$mode; medianSeconds=$values[1]; minSeconds=$values[0]; maxSeconds=$values[2] }
    }
    $summary | ConvertTo-Json | Set-Content (Join-Path $OutputRoot "summary.json")
    $summary | Format-Table
}
finally {
    $runs | ConvertTo-Json -Depth 6 | Set-Content (Join-Path $OutputRoot "runs.json")
}
