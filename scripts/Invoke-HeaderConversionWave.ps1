#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$WaveManifest,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [switch]$PlanOnly
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repo = [IO.Path]::GetFullPath("$PSScriptRoot\..").TrimEnd('\')
$WaveManifest = [IO.Path]::GetFullPath($WaveManifest)
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\')

function Get-WaveHash([string]$Path) {
    (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash
}

function Write-WaveJson([string]$Path, $Value) {
    [IO.File]::WriteAllText($Path, ($Value | ConvertTo-Json -Depth 12), [Text.UTF8Encoding]::new($false))
}

function Get-WaveFiles([string]$Root) {
    @(Get-ChildItem -LiteralPath $Root -Recurse -File | Sort-Object FullName | ForEach-Object {
        [pscustomobject]@{
            path = [IO.Path]::GetRelativePath($Root, $_.FullName)
            sha256 = Get-WaveHash $_.FullName
            bytes = $_.Length
        }
    })
}

function Assert-WaveOutput([string]$Output, [string[]]$ProtectedPaths) {
    if (!$Output.StartsWith("$repo\artifacts\", [StringComparison]::OrdinalIgnoreCase)) {
        throw 'Conversion-wave output must be a new directory under this worktree artifacts root.'
    }
    if (Test-Path -LiteralPath $Output) {
        throw 'Use a new conversion-wave output directory; prior evidence is never overwritten.'
    }
    foreach ($path in $ProtectedPaths) {
        $full = [IO.Path]::GetFullPath($path).TrimEnd('\')
        if ($Output.Equals($full, [StringComparison]::OrdinalIgnoreCase) -or
            $Output.StartsWith("$full\", [StringComparison]::OrdinalIgnoreCase) -or
            $full.StartsWith("$Output\", [StringComparison]::OrdinalIgnoreCase)) {
            throw "Conversion-wave output overlaps protected evidence: $full"
        }
    }
}

function Get-WaveCommands([string]$Output, [string]$Tools, [string]$Baseline, [int]$ShardSize, [string]$Blockers) {
    $obj = "$Output\obj"
    $image = "$Output\image\Windows.Win32.winmd"
    $common = @('build', "$repo\generation\WinSDK", '-c', 'Release', '--no-restore', '--verbosity', 'minimal', '-m:1', '-p:MaxProcessors=2',
        "-p:ObjDir=$obj", "-p:SdkHeaderOutputRoot=$Output\prepared-sdk",
        "-p:ToolsBinDir=$Tools", "-p:TaskBinDir=$Tools", "-p:LocalTaskBinDir=$Tools",
        "-p:Win32WinmdBinDir=$Output\image", "-p:OutputWinmd=$image", '-p:ScanArch=crossarch')
    $review = @("$Tools\WinmdUtils.dll", 'review-batch',
        '--comparisonLog', "$Output\comparison.log", '--first', $Baseline, '--second', $image,
        '--outputDirectory', "$Output\review", '--generatedDirectory', "$obj\generated",
        '--scratchDirectory', "$obj\scratch", '--boundary', "$Output\producer-boundary.json",
        '--purpose', 'conversion-wave', '--shardSize', $ShardSize.ToString([Globalization.CultureInfo]::InvariantCulture))
    if ($Blockers) {
        $review += '--blockers', $Blockers
    }
    @(
        [pscustomobject]@{ stage = 'headers'; log = "$Output\headers.log"; arguments = @($common + '-t:ScrapeHeaders') }
        [pscustomobject]@{ stage = 'constants'; log = "$Output\constants.log"; arguments = @($common + '-t:ScrapeConstants') }
        [pscustomobject]@{ stage = 'emit'; log = "$Output\emit.log"; arguments = @($common + '-t:EmitWinmd') }
        [pscustomobject]@{ stage = 'integrity'; log = "$Output\integrity.log"; arguments = @('vstest', "$Tools\Windows.Win32.Tests.dll",
            "/Logger:trx;LogFileName=integrity.trx", "/ResultsDirectory:$Output\integrity") }
        [pscustomobject]@{ stage = 'compare'; log = "$Output\comparison.log"; arguments = @("$Tools\WinmdUtils.dll", 'compare', '--first', $Baseline, '--second', $image) }
        [pscustomobject]@{ stage = 'review'; log = "$Output\review.log"; arguments = $review }
    )
}

function Assert-WaveProducer([string]$ExpectedCommit) {
    $head = & git -C $repo rev-parse HEAD
    if ($LASTEXITCODE -ne 0 -or $head -cne $ExpectedCommit) {
        throw 'The integrated source-wave producer commit changed.'
    }
    $dirty = & git -C $repo status --porcelain --untracked-files=normal
    if ($LASTEXITCODE -ne 0 -or $dirty) {
        throw 'Commit the coherent additive source/tool integration before executing its aggregate producer.'
    }
}

$wave = Get-Content -LiteralPath $WaveManifest -Raw | ConvertFrom-Json
if ($wave.schemaVersion -ne 1 -or $wave.purpose -cne 'conversion-wave') {
    throw 'Expected a version1 conversion-wave readiness manifest.'
}
$baseline = [IO.Path]::GetFullPath($wave.baselineWinmd)
if ((Get-WaveHash $baseline) -cne $wave.baselineWinmdSha256) {
    throw 'The exact frozen OLD image binding changed.'
}
$tools = [IO.Path]::GetFullPath($wave.toolsDirectory)
$protected = @($baseline, $WaveManifest, $tools) + @($wave.protectedPaths)
Assert-WaveOutput $OutputDirectory $protected
if ($wave.shardSize -lt 500 -or $wave.shardSize -gt 1000) {
    throw 'Review shard size must be between500 and1000 raw differences.'
}
$commands = @(Get-WaveCommands $OutputDirectory $tools $baseline $wave.shardSize $wave.blockers)
$plan = [ordered]@{
    purpose = 'conversion-wave'
    waveManifest = $WaveManifest
    waveManifestSha256 = Get-WaveHash $WaveManifest
    sourceReady = $wave.sourceReady
    sourceCommit = $wave.sourceCommit
    sourceInputs = $wave.sourceInputs
    baselineWinmd = $baseline
    baselineWinmdSha256 = $wave.baselineWinmdSha256
    toolsDirectory = $tools
    commands = $commands
    nativeSourcesReusedFromFrozenImage = 0
    sourceIntegrationPolicy = 'Exact coherent additive deltas only; never ancestor/coalesced file replacement. Per-packet API admission is not a source-production prerequisite.'
    comparisonPolicy = 'Complete raw unsuppressed OLD-to-NEW comparison. Difference exit-1 requires family review, not a waiver or image acceptance.'
    protectedPaths = $protected
    status = if ($PlanOnly) { 'plan-only-no-producer-executed' } else { 'awaiting-execution' }
}
if ($PlanOnly) {
    [IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
    Write-WaveJson "$OutputDirectory\pipeline-plan.json" $plan
    [pscustomobject]@{ Plan = "$OutputDirectory\pipeline-plan.json"; SourceReady = $wave.sourceReady; ProducerExecuted = $false }
    return
}
if (!$wave.sourceReady -or !$wave.sourceInputs.Count) {
    throw 'Wait for source-wave readiness and its coherent integrated source manifest; a staged plan is not a new image.'
}
Assert-WaveProducer $wave.sourceCommit
if ($wave.sourceInputs | Where-Object { $_.integrationMode -cne 'additive-delta' }) {
    throw 'Every source input must identify an additive-delta integration, not ancestor or whole-file adoption.'
}
$runtimeManifest = [IO.Path]::GetFullPath($wave.runtimeManifest)
if ((Get-WaveHash $runtimeManifest) -cne $wave.runtimeManifestSha256) {
    throw 'The qualified NEW private runtime manifest changed.'
}
$runtime = Get-Content -LiteralPath $runtimeManifest -Raw | ConvertFrom-Json
$runtimeInputs = @($runtime.files) + @($runtime.debugFiles)
foreach ($file in $runtimeInputs) {
    $path = [IO.Path]::GetFullPath((Join-Path $tools $file.path))
    if (!$path.StartsWith("$($tools.TrimEnd('\'))\", [StringComparison]::OrdinalIgnoreCase) -or
        (Get-WaveHash $path) -cne $file.sha256) {
        throw "A private runtime input does not match its NEW qualified manifest: $path"
    }
}
foreach ($name in @('MetadataTasks.dll', 'Win32MetadataScraper.dll', 'ConstantsScraper.dll',
    'ClangSharpSourceToWinmd.dll', 'WinmdUtils.dll', 'Windows.Win32.Tests.dll', 'TestCommon.dll')) {
    if (@($runtime.files | Where-Object path -CEQ $name).Count -ne 1) {
        throw "The qualified private runtime is missing a required pipeline assembly: $name"
    }
}
foreach ($name in @('InterfacesToVerify.json', 'duplicateImportsAllowList.rsp', 'duplicateConstantsAllowList.rsp',
    'emptyDelegatesAllowList.rsp', 'pointersToDelegatesAllowList.rsp', 'suggestedRemappingsAllowList.rsp')) {
    if (!(Test-Path -LiteralPath "$tools\assets\$name")) {
        throw "The private integrity-test asset is missing: $name"
    }
}
[IO.Directory]::CreateDirectory("$OutputDirectory\image") | Out-Null
Write-WaveJson "$OutputDirectory\pipeline-plan.json" $plan
$results = [Collections.Generic.List[object]]::new()
$savedImage = $env:WIN32_METADATA_TEST_WINMD
$savedProject = $env:WIN32_METADATA_TEST_PROJECT
$completed = $false
try {
    . "$PSScriptRoot\CommonUtils.ps1"
    Install-VsDevShell
    foreach ($command in $commands) {
        Assert-WaveProducer $wave.sourceCommit
        if ($command.stage -eq 'review') {
            $preparedRoot = (Get-Content -LiteralPath "$OutputDirectory\obj\prepared-sdk.txt" -Raw).Trim()
            $preparedManifest = Join-Path (Split-Path -Parent $preparedRoot) 'manifest.json'
            $generated = Get-WaveFiles "$OutputDirectory\obj\generated"
            Write-WaveJson "$OutputDirectory\compiler-inputs.json" $generated
            $boundary = [ordered]@{
                purpose = 'conversion-wave'
                producerCompleted = $true
                sourceCommit = $wave.sourceCommit
                waveManifestSha256 = Get-WaveHash $WaveManifest
                runtimeManifestSha256 = Get-WaveHash $runtimeManifest
                oldWinmdSha256 = Get-WaveHash $baseline
                newWinmdSha256 = Get-WaveHash "$OutputDirectory\image\Windows.Win32.winmd"
                comparisonLogSha256 = Get-WaveHash "$OutputDirectory\comparison.log"
                compilerInputsSha256 = Get-WaveHash "$OutputDirectory\compiler-inputs.json"
                preparedManifestSha256 = Get-WaveHash $preparedManifest
                freshAggregateSources = $true
                oldNativeJobSourcesReused = 0
                stageResults = $results.ToArray()
                imageAcceptance = $false
            }
            Write-WaveJson "$OutputDirectory\producer-boundary.json" $boundary
        }
        if ($command.stage -eq 'integrity') {
            $env:WIN32_METADATA_TEST_WINMD = "$OutputDirectory\image\Windows.Win32.winmd"
            $env:WIN32_METADATA_TEST_PROJECT = "$repo\generation\WinSDK"
        }
        $started = [DateTime]::UtcNow.ToString('o')
        $log = $command.log
        & dotnet @($command.arguments) *> $log
        $exit = $LASTEXITCODE
        $rawLines = @()
        if ($command.stage -eq 'compare') {
            $rawLines = @([IO.File]::ReadAllLines($log))
        }
        $differences = $command.stage -eq 'compare' -and $exit -eq -1 -and
            $rawLines.Count -gt 1 -and $rawLines[0] -ceq 'Unknown differences found:'
        $result = [pscustomobject]@{
            stage = $command.stage; arguments = $command.arguments
            startedUtc = $started; completedUtc = [DateTime]::UtcNow.ToString('o')
            exitCode = $exit; log = $log; logSha256 = Get-WaveHash $log
            rawDifferences = if ($differences) { $rawLines.Count - 1 } else { 0 }
        }
        $results.Add($result)
        Write-WaveJson "$OutputDirectory\stage-results.json" $results.ToArray()
        if ($exit -ne 0 -and !$differences) {
            throw "New conversion-wave stage '$($command.stage)' failed; freeze this boundary and inspect $log. Do not replay frozen producers."
        }
        if ($command.stage -eq 'compare' -and !$differences -and
            ($rawLines.Count -ne 1 -or $rawLines[0] -cne 'No unknown differences found.')) {
            throw 'The unsuppressed comparison did not produce a complete success or differences report.'
        }
        if ($command.stage -eq 'integrity') {
            [xml]$trx = Get-Content -LiteralPath "$OutputDirectory\integrity\integrity.trx" -Raw
            $counters = $trx.TestRun.ResultSummary.Counters
            if ([int]$counters.executed -lt 1 -or [int]$counters.failed -ne 0 -or
                [int]$counters.passed -ne [int]$counters.total) {
                throw 'Actual image integrity must execute a nonzero complete suite with no failures or skips.'
            }
        }
    }
    Assert-WaveProducer $wave.sourceCommit
    $completed = $true
}
finally {
    $env:WIN32_METADATA_TEST_WINMD = $savedImage
    $env:WIN32_METADATA_TEST_PROJECT = $savedProject
    Write-WaveJson "$OutputDirectory\terminal-status.json" ([ordered]@{
        purpose = 'conversion-wave'
        sourceCommit = $wave.sourceCommit
        completedThroughSharding = $completed
        stageResults = $results.ToArray()
        imageAcceptance = $false
        sourceOrEodCredit = 0
        retryAuthorized = $false
        files = Get-WaveFiles $OutputDirectory
    })
    Get-ChildItem -LiteralPath $OutputDirectory -Recurse -File | ForEach-Object { $_.IsReadOnly = $true }
}
[pscustomobject]@{
    Boundary = "$OutputDirectory\producer-boundary.json"
    Review = "$OutputDirectory\review\manifest.json"
    Status = 'new-image-awaiting-parallel-family-review'
    ImageAccepted = $false
}
