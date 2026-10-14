#Requires -Version 7.0

[CmdletBinding()]
param(
    [string]$BaselineDirectory = "$PSScriptRoot\..\artifacts\winhttp-migration\old",
    [string]$OutputDirectory = "$PSScriptRoot\..\artifacts\winhttp-migration\new",
    [string]$SelectionDirectory,
    [switch]$ToolingControl,
    [string]$ToolingControlDirectory
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repo = [IO.Path]::GetFullPath("$PSScriptRoot\..").TrimEnd('\')
$BaselineDirectory = [IO.Path]::GetFullPath($BaselineDirectory).TrimEnd('\')
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\')
if (!$SelectionDirectory) {
    $SelectionDirectory = "$OutputDirectory\selection"
}
$SelectionDirectory = [IO.Path]::GetFullPath($SelectionDirectory).TrimEnd('\')
foreach ($path in @($BaselineDirectory, $OutputDirectory, $SelectionDirectory)) {
    if (!$path.StartsWith("$repo\artifacts\", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Migration artifacts must stay in this worktree's artifacts directory: $path"
    }
}
if (Test-Path -LiteralPath $OutputDirectory) {
    throw "Use a new output directory; published consumer fixtures must not be overwritten: $OutputDirectory"
}
if (!$ToolingControl -and (Test-Path -LiteralPath $SelectionDirectory)) {
    throw 'Use a fresh selection directory; prior aggregate discoveries must not become scraper inputs.'
}
foreach ($path in @($SelectionDirectory, $OutputDirectory)) {
    if ($BaselineDirectory -eq $path -or
        $path.StartsWith("$BaselineDirectory\", [StringComparison]::OrdinalIgnoreCase) -or
        $BaselineDirectory.StartsWith("$path\", [StringComparison]::OrdinalIgnoreCase)) {
        throw 'Migration output must not overlap the frozen baseline.'
    }
}

function Get-Sha256([string]$Path) {
    (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash
}

function Invoke-Dotnet([string[]]$Arguments, [string]$Log) {
    & dotnet @Arguments *> $Log
    if ($LASTEXITCODE -ne 0) {
        throw "dotnet failed; see $Log`n$((Get-Content -LiteralPath $Log -Tail 35) -join "`n")"
    }
}

function Get-PointerReductions([IO.FileInfo[]]$Remaps) {
    $reduce = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $preserve = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($file in $Remaps) {
        foreach ($line in [IO.File]::ReadLines($file.FullName)) {
            if ($line.StartsWith('REDUCE_PTR_LEVEL:', [StringComparison]::Ordinal)) {
                $reduce.Add($line.Substring('REDUCE_PTR_LEVEL:'.Length)) | Out-Null
            }
            elseif ($line.StartsWith('PRESERVE_PTR_LEVEL:', [StringComparison]::Ordinal)) {
                $preserve.Add($line.Substring('PRESERVE_PTR_LEVEL:'.Length)) | Out-Null
            }
        }
    }
    $reduce.ExceptWith($preserve)
    return ,$reduce
}

function Get-SelectedInputs([string]$Obj, [string[]]$Overlays) {
    $paths = @($Overlays | ForEach-Object { "$Obj\generated\$_" })
    $paths += "$Obj\generated\scraper.autoRemaps.generated.rsp", "$Obj\generated\emitter.autoFnPtr.crossarch.generated.rsp"
    $paths += @(Get-ChildItem "$Obj\scratch" -Recurse -Filter '*.remaps' -File | ForEach-Object { $_.FullName })
    @($paths | Sort-Object -CaseSensitive | ForEach-Object {
        [ordered]@{ path = [IO.Path]::GetRelativePath($Obj, $_); sha256 = Get-Sha256 $_ }
    })
}

$sourceCommit = & git -C $repo rev-parse HEAD
if ($LASTEXITCODE -ne 0) {
    throw 'The producer commit could not be resolved.'
}
function Assert-CommittedProducer {
    $currentCommit = & git -C $repo rev-parse HEAD
    if ($LASTEXITCODE -ne 0 -or $currentCommit -cne $sourceCommit) {
        throw 'The producer commit changed during image generation.'
    }
    & git -C $repo diff --quiet HEAD
    if ($LASTEXITCODE -ne 0) {
        throw 'Commit producer inputs before publishing an immutable migration image.'
    }
    $untracked = & git -C $repo ls-files --others --exclude-standard
    if ($LASTEXITCODE -ne 0 -or $untracked) {
        throw 'Untracked producer inputs must be committed before image generation.'
    }
}
Assert-CommittedProducer

$provenancePath = "$BaselineDirectory\provenance.json"
$baseline = Get-Content -LiteralPath $provenancePath -Raw | ConvertFrom-Json
if ($baseline.toolingCommit -ne 'b5b7b26ed09d648766f07449af48c64ef0e99d13' -or
    $baseline.sdkPackageVersion -ne '10.0.26100.7705') {
    throw 'The OLD fixture must come from the supported tooling base and selected SDK.'
}
if ((Get-Sha256 "$BaselineDirectory\Windows.Win32.winmd") -ne $baseline.winmdSha256) {
    throw 'The OLD winmd no longer matches its frozen provenance.'
}
$oldGenerated = "$BaselineDirectory\obj\generated"
$actualFiles = @(Get-ChildItem -LiteralPath $oldGenerated -Recurse -File)
if ($actualFiles.Count -ne $baseline.generatedFiles.Count) {
    throw 'The complete OLD generated-source closure is required.'
}
foreach ($file in $baseline.generatedFiles) {
    if ((Get-Sha256 "$oldGenerated\$($file.path)") -ne $file.sha256) {
        throw "The OLD generated-source snapshot was modified: $($file.path)"
    }
}
$toolFiles = @($baseline.toolFiles | ForEach-Object {
    [ordered]@{ path = $_.path; sha256 = Get-Sha256 "$repo\$($_.path)" }
})
$toolingChanged = @($baseline.toolFiles | Where-Object {
    $expected = $_
    @($toolFiles | Where-Object { $_.path -eq $expected.path -and $_.sha256 -eq $expected.sha256 }).Count -ne 1
}).Count -ne 0
if ($toolingChanged -and !$ToolingControl) {
    if (!$ToolingControlDirectory) {
        throw 'Changed tooling requires a separately emitted frozen-input tooling control.'
    }
    $ToolingControlDirectory = [IO.Path]::GetFullPath($ToolingControlDirectory)
    if (!$ToolingControlDirectory.StartsWith("$repo\artifacts\", [StringComparison]::OrdinalIgnoreCase)) {
        throw 'The tooling control must be in this worktree.'
    }
    $control = Get-Content -LiteralPath "$ToolingControlDirectory\provenance.json" -Raw | ConvertFrom-Json
    if ($control.kind -ne 'tooling-control' -or $control.oldWinmdSha256 -ne $baseline.winmdSha256 -or
        $control.baselineProvenanceSha256 -ne (Get-Sha256 $provenancePath) -or
        $control.newWinmdSha256 -ne (Get-Sha256 "$ToolingControlDirectory\Windows.Win32.winmd")) {
        throw 'The tooling control does not bind this frozen OLD fixture.'
    }
    foreach ($file in $toolFiles) {
        if (@($control.toolFiles | Where-Object { $_.path -eq $file.path -and $_.sha256 -eq $file.sha256 }).Count -ne 1) {
            throw "The current tools differ from the verified tooling-control producer: $($file.path)"
        }
    }
}

[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
[IO.Directory]::CreateDirectory($SelectionDirectory) | Out-Null
Push-Location $repo
try {
    . "$PSScriptRoot\CommonUtils.ps1"
    Install-VsDevShell
    if ($ToolingControl) {
        [IO.Directory]::CreateDirectory("$OutputDirectory\obj") | Out-Null
        Copy-Item -LiteralPath $oldGenerated -Destination "$OutputDirectory\obj" -Recurse
        $generated = "$OutputDirectory\obj\generated"
        $archive = "$OutputDirectory\inputs.zip"
        & git archive --format=zip "--output=$archive" $baseline.toolingCommit -- `
            'generation/WinSDK/emitter.settings.rsp' 'generation/WinSDK/requiredNamespacesForNames.rsp' `
            'generation/WinSDK/documentationMappings.rsp' 'generation/WinSDK/autoTypes.json'
        if ($LASTEXITCODE -ne 0) {
            throw 'Could not materialize the pinned OLD emitter inputs.'
        }
        Expand-Archive -LiteralPath $archive -DestinationPath "$OutputDirectory\inputs"
        $inputs = "$OutputDirectory\inputs\generation\WinSDK"
        $winmd = "$OutputDirectory\Windows.Win32.winmd"
        $arguments = @("$repo\bin\Release\net10.0\ClangSharpSourceToWinmd.dll",
            '--sourceDir', $generated, '--arch', 'crossarch', '--version', '1.0.0.0', '--outputFileName', $winmd,
            '--autoTypes', "$inputs\autoTypes.json",
            "@$inputs\emitter.settings.rsp", "@$inputs\requiredNamespacesForNames.rsp", "@$inputs\documentationMappings.rsp",
            "@$generated\emitter.functionPointerFixups.generated.rsp", "@$generated\emitter.autoFnPtr.crossarch.generated.rsp",
            "@$generated\enumsMakeFlags.generated.rsp", "@$generated\enumsRemap.rsp")
        Invoke-Dotnet $arguments "$OutputDirectory\emit.log"
        Invoke-Dotnet @("$repo\bin\Release\net10.0\WinmdUtils.dll", 'compare',
            '--first', "$BaselineDirectory\Windows.Win32.winmd", '--second', $winmd) "$OutputDirectory\comparison.log"
        Assert-CommittedProducer
        $receipt = [ordered]@{
            kind = 'tooling-control'
            baselineToolingCommit = $baseline.toolingCommit
            sdkPackageVersion = $baseline.sdkPackageVersion
            baselineProvenanceSha256 = Get-Sha256 $provenancePath
            oldWinmdSha256 = $baseline.winmdSha256
            newWinmdSha256 = Get-Sha256 $winmd
            sourceCommit = $sourceCommit
            toolFiles = $toolFiles
            frozenEmitterInputs = @(Get-ChildItem -LiteralPath $inputs -File | ForEach-Object {
                [ordered]@{ path = $_.Name; sha256 = Get-Sha256 $_.FullName }
            })
        }
        [IO.File]::WriteAllText("$OutputDirectory\provenance.json", ($receipt | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
        return [pscustomobject]@{ Winmd = $winmd; Sha256 = $receipt.newWinmdSha256; Provenance = "$OutputDirectory\provenance.json" }
    }
    $selectedObj = "$SelectionDirectory\obj"
    $overlays = @('x86\WinHttp.cs', 'x64\WinHttp.cs', 'arm64\WinHttp.cs', 'common\HttpServer.cs')
    $scrapeArguments = @('build', 'generation\WinSDK', '-c', 'Release', '-t:ScrapeHeaders',
        "-p:ObjDir=$selectedObj", '-p:PartitionFilter=WinHttp%3BHttpServer', '-p:MaxProcessors=2',
        '-p:ScanArch=crossarch', '--no-restore', '--verbosity', 'minimal')
    Invoke-Dotnet $scrapeArguments "$OutputDirectory\scrape.log"
    $includeRoot = (Get-Content -LiteralPath "$selectedObj\prepared-sdk.txt" -Raw).Trim()
    $firstInputs = Get-SelectedInputs $selectedObj $overlays
    [IO.File]::WriteAllText("$OutputDirectory\first-selection.json", ($firstInputs | ConvertTo-Json -Depth 3),
        [Text.UTF8Encoding]::new($false))
    foreach ($entry in $firstInputs) {
        $target = "$OutputDirectory\first-selection\$($entry.path)"
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        [IO.File]::Copy("$selectedObj\$($entry.path)", $target)
    }
    $scrapeMarker = "$selectedObj\generated\scannedheaders.crossarch.txt"
    if (Test-Path -LiteralPath $scrapeMarker) {
        Remove-Item -LiteralPath $scrapeMarker
    }
    Invoke-Dotnet $scrapeArguments "$OutputDirectory\repeat-scrape.log"
    $repeatedInputs = Get-SelectedInputs $selectedObj $overlays
    [IO.File]::WriteAllText("$OutputDirectory\repeated-selection.json", ($repeatedInputs | ConvertTo-Json -Depth 3),
        [Text.UTF8Encoding]::new($false))
    if (($firstInputs | ConvertTo-Json -Depth 3) -cne ($repeatedInputs | ConvertTo-Json -Depth 3)) {
        throw 'A repeated normal SDK scrape changed selected declarations or pointer discoveries.'
    }
    if ((Get-Content -LiteralPath "$selectedObj\prepared-sdk.txt" -Raw).Trim() -cne $includeRoot) {
        throw 'The selected scrape changed its pinned prepared-header root.'
    }

    $obj = "$OutputDirectory\obj"
    [IO.Directory]::CreateDirectory($obj) | Out-Null
    Copy-Item -LiteralPath $oldGenerated -Destination $obj -Recurse
    $generated = "$obj\generated"
    foreach ($path in $overlays) {
        [IO.File]::Copy("$selectedObj\generated\$path", "$generated\$path", $true)
    }
    foreach ($name in @('filtered.headers.generated.rsp', 'filtered.constants.generated.rsp', 'filtered.emitter.generated.rsp')) {
        if (Test-Path -LiteralPath "$selectedObj\generated\$name") {
            [IO.File]::Copy("$selectedObj\generated\$name", "$generated\$name", $true)
        }
        elseif (Test-Path -LiteralPath "$generated\$name") {
            throw "The selected build lost a filtered response file: $name"
        }
    }

    $baselineRemaps = @(Get-ChildItem "$BaselineDirectory\obj\scratch" -Recurse -Filter '*.remaps' -File)
    $baselineReductions = Get-PointerReductions $baselineRemaps
    $frozenReductions = @([IO.File]::ReadAllLines("$oldGenerated\emitter.autoFnPtr.crossarch.generated.rsp"))
    if ($frozenReductions[0] -ne '--reducePointerLevel' -or
        !$baselineReductions.SetEquals([string[]]($frozenReductions | Select-Object -Skip 1))) {
        throw 'The baseline discovery inputs do not reproduce the frozen complete pointer-fixup response file.'
    }
    $remaps = @($baselineRemaps | Where-Object { $_.BaseName -notin @('WinHttp', 'HttpServer') })
    $remaps += @(Get-ChildItem "$selectedObj\scratch" -Recurse -Filter '*.remaps' -File)
    $reduce = Get-PointerReductions $remaps
    [IO.File]::WriteAllLines("$generated\emitter.autoFnPtr.crossarch.generated.rsp",
        [string[]](@('--reducePointerLevel') + @($reduce | Sort-Object)), [Text.UTF8Encoding]::new($false))

    $mapping = [IO.File]::ReadAllText("$oldGenerated\traversedFileToNamespace.rsp")
    $oldRoot = "$repo\generation\WinSDK\RecompiledIdlHeaders"
    if (!$mapping.Contains($oldRoot)) {
        throw 'The frozen traversal map is not rooted in this baseline worktree.'
    }
    [IO.File]::WriteAllText("$generated\traversedFileToNamespace.rsp",
        $mapping.Replace($oldRoot, $includeRoot), [Text.UTF8Encoding]::new($false))
    $project = "$repo\generation\WinSDK"
    $constantArguments = @("$repo\bin\Release\net10.0\ConstantsScraper.dll",
        '--headerTextFile', "$generated\ConstantsScraper.header.generated.txt",
        '--scraperOutputDir', $generated,
        "@$project\ConstantsScraper.settings.rsp", "@$project\requiredNamespacesForNames.rsp",
        "@$repo\sources\GeneratorSdk\tools\assets\scraper\baseSettings.ConstantsScraper.rsp",
        "@$generated\traversedFileToNamespace.rsp", '--enumsJson', "$project\enums.json")
    if (Test-Path -LiteralPath "$generated\filtered.constants.generated.rsp") {
        $constantArguments += "@$generated\filtered.constants.generated.rsp"
    }
    Invoke-Dotnet $constantArguments "$OutputDirectory\constants.log"
    [IO.File]::WriteAllText("$generated\constants.scraped.txt", '')
    [IO.File]::WriteAllText("$obj\prepared-sdk.txt", $includeRoot)

    $winmd = "$OutputDirectory\Windows.Win32.winmd"
    Invoke-Dotnet @('build', 'generation\WinSDK', '-c', 'Release', '-t:EmitWinmd',
        "-p:ObjDir=$obj", "-p:OutputWinmd=$winmd", '-p:SkipScraping=true',
        '--no-restore', '--verbosity', 'minimal') "$OutputDirectory\emit.log"
    Invoke-Dotnet @("$repo\bin\Release\net10.0\WinmdUtils.dll", 'compare',
        '--first', "$BaselineDirectory\Windows.Win32.winmd", '--second', $winmd,
        '--knownDiffsFile', "$project\patches\WinHttp.expected-differences.txt") "$OutputDirectory\comparison.log"
    Assert-CommittedProducer
    $receipt = [ordered]@{
        kind = 'winhttp-migration'
        baselineToolingCommit = $baseline.toolingCommit
        sdkPackageVersion = $baseline.sdkPackageVersion
        baselineProvenanceSha256 = Get-Sha256 $provenancePath
        oldWinmdSha256 = $baseline.winmdSha256
        newWinmdSha256 = Get-Sha256 $winmd
        preparedIncludeRoot = $includeRoot
        preparedManifestSha256 = Get-Sha256 ([IO.Path]::Combine([IO.Path]::GetDirectoryName($includeRoot), 'manifest.json'))
        overlaidHeaderSources = $overlays
        repeatedSelectionInputs = $repeatedInputs
        sourceCommit = $sourceCommit
        toolFiles = $toolFiles
        toolingControl = $ToolingControlDirectory
        expectedDifferencesSha256 = Get-Sha256 "$project\patches\WinHttp.expected-differences.txt"
        generatedFiles = @(Get-ChildItem -LiteralPath $generated -Recurse -File | ForEach-Object {
            [ordered]@{ path = [IO.Path]::GetRelativePath($generated, $_.FullName); sha256 = Get-Sha256 $_.FullName }
        })
        pointerDiscoveryInputs = @($remaps | ForEach-Object {
            [ordered]@{ path = [IO.Path]::GetRelativePath($repo, $_.FullName); sha256 = Get-Sha256 $_.FullName }
        })
    }
    [IO.File]::WriteAllText("$OutputDirectory\provenance.json", ($receipt | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
    [pscustomobject]@{ Winmd = $winmd; Sha256 = $receipt.newWinmdSha256; Provenance = "$OutputDirectory\provenance.json" }
}
finally {
    Pop-Location
}
