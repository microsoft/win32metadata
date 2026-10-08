<#
.SYNOPSIS
    Preserves hash-only CI input inventories without running or changing generation.
.DESCRIPTION
    Before records checkout inputs. After also evaluates the restored project and
    inventories available runtime, SDK, import and Cargo dependency inputs. These
    are snapshots, not a file-read trace. Native log statements and the successful
    generation receipt are kept separate from configured/available inputs.
    Every invocation creates a new manifest; partial manifests survive errors.
#>
[CmdletBinding()]
param(
    [ValidateSet("Before", "After")]
    [string]$Phase = "After",
    [string]$RepositoryRoot = "$PSScriptRoot\..",
    [string]$OutputPath,
    [string]$GenerationLog
)

function Get-FingerprintFile {
    param([string]$Path)
    $path = [IO.Path]::GetFullPath($Path)
    $item = Get-Item -LiteralPath $path -Force -ErrorAction Stop
    if ($item.PSIsContainer -or ($item.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Expected a regular fingerprint input file: '$path'."
    }
    $length = $item.Length
    $stamp = $item.LastWriteTimeUtc
    $hash = (Get-FileHash -LiteralPath $path -Algorithm SHA256 -ErrorAction Stop).Hash
    $item.Refresh()
    if (!$item.Exists -or $length -ne $item.Length -or $stamp -ne $item.LastWriteTimeUtc) {
        throw "Fingerprint input changed while hashing: '$path'."
    }
    [ordered]@{ path = $path; length = $length; sha256 = $hash }
}

function Get-FingerprintTree {
    param([string]$Path, [string]$Filter = "*", [switch]$TopLevel, [string[]]$Extensions = @())
    $root = Get-Item -LiteralPath $Path -Force -ErrorAction Stop
    if (!$root.PSIsContainer -or ($root.Attributes -band [IO.FileAttributes]::ReparsePoint)) {
        throw "Expected a regular fingerprint input directory: '$Path'."
    }
    $items = @(Get-ChildItem -LiteralPath $root.FullName -Force -Recurse:(!$TopLevel) -ErrorAction Stop)
    if (@($items | Where-Object { $_.Attributes -band [IO.FileAttributes]::ReparsePoint }).Count) {
        throw "Fingerprint inventories do not follow reparse points: '$Path'."
    }
    [string[]]$paths = @($items | Where-Object {
        !$_.PSIsContainer -and $_.Name -like $Filter -and (!$Extensions.Count -or $_.Extension -in $Extensions)
    } |
        ForEach-Object FullName)
    [Array]::Sort($paths, [StringComparer]::Ordinal)
    foreach ($file in $paths) {
        $record = Get-FingerprintFile $file
        $record["relativePath"] = [IO.Path]::GetRelativePath($root.FullName, $file)
        $record
    }
}

function Get-FingerprintArgumentValues {
    param([string[]]$Arguments, [string]$Name)
    for ($i = 0; $i -lt $Arguments.Count; $i++) {
        if ($Arguments[$i] -ceq $Name) {
            if (++$i -ge $Arguments.Count -or $Arguments[$i].StartsWith("--")) {
                throw "Missing recorded value for '$Name'."
            }
            $Arguments[$i]
        }
    }
}

function Get-FingerprintNativeLog {
    param([string]$Path)
    if (!$Path) { throw "After collection requires -GenerationLog." }
    $record = Get-FingerprintFile $Path
    $statements = [Collections.Generic.List[object]]::new()
    $runtimes = [Collections.Generic.List[object]]::new()
    $captures = [Collections.Generic.List[object]]::new()
    $runs = [Collections.Generic.List[object]]::new()
    $facts = [Collections.Generic.List[object]]::new()
    $lineNumber = 0
    foreach ($line in Get-Content -LiteralPath $Path) {
        $lineNumber++
        # Accept raw Tee output and downloaded Actions logs, including MSBuild node prefixes.
        $text = $line -replace '^(?:[^\t]*\t[^\t]*\t\d{4}-\S+\s+)?\s*(?:\d+>)?\s*', ''
        if ($text -cmatch '^Using libclang (.+) from (.+) \((.+)\)$') {
            $runtimes.Add([ordered]@{ line = $lineNumber; version = $Matches[1]; directory = $Matches[2]; source = $Matches[3] })
        } elseif ($text -cmatch '^Using annotation contract (.+) and SAL contract (.+)$') {
            $captures.Add([ordered]@{ line = $lineNumber; annotation = $Matches[1]; sal = $Matches[2] })
        } elseif ($text -cmatch '^Scraping (\d+) logical partition\(s\) as (\d+) translation unit\(s\) for (.+) into (.+)$') {
            $runs.Add([ordered]@{
                line = $lineNumber; partitions = [int]$Matches[1]; translationUnits = [int]$Matches[2]
                architectures = @($Matches[3].Split(",") | ForEach-Object Trim); rdlDirectory = $Matches[4]
            })
        } elseif ($text -cmatch '^Extracted (\d+) facts for (x64|x86|arm64) in ([0-9.]+)s$') {
            $facts.Add([ordered]@{ line = $lineNumber; count = [long]$Matches[1]; architecture = $Matches[2]; seconds = $Matches[3] })
        } elseif ($text -cnotmatch '^Architecture worker limit: \d+$') {
            continue
        }
        $statements.Add([ordered]@{ line = $lineNumber; text = $text })
    }
    [ordered]@{
        log = $record
        evidence = "Native-reported statements, not a file-read trace or proof of post-run bytes at load time."
        statements = $statements.ToArray(); runtimes = $runtimes.ToArray(); captures = $captures.ToArray()
        runs = $runs.ToArray(); extractedFacts = $facts.ToArray()
    }
}

function Get-FingerprintPolicyInputs {
    param([string]$Root)
    $directories = [Collections.Generic.SortedDictionary[string, string]]::new([StringComparer]::Ordinal)
    foreach ($directory in Get-ChildItem -LiteralPath $Root -Directory -Force -ErrorAction Stop) {
        if (Test-Path -LiteralPath (Join-Path $directory.FullName "main.cpp") -PathType Leaf) {
            $directories[$directory.Name] = $directory.FullName
        }
    }
    if (!$directories.Count) { throw "No active policy main.cpp inputs in '$Root'." }
    # Inventory order is ordinal, not a claim about the native traversal order.
    foreach ($entry in $directories.GetEnumerator()) {
        [ordered]@{
            name = $entry.Key
            main = Get-FingerprintFile (Join-Path $entry.Value "main.cpp")
            settings = Get-FingerprintFile (Join-Path $entry.Value "settings.rsp")
        }
    }
}

function Get-FingerprintResourceCandidates {
    param([string]$LibClangPath, [string]$ToolPath, [string]$ObjectPath, [string]$ResourceOverride, [string]$Version)
    # Keep libclang.rs::clang_resource_dir order, including invalid candidates before fallback.
    [ordered]@{ source = "LIBCLANG_PATH"; path = Join-Path $LibClangPath "clang-resource\$Version" }
    [ordered]@{ source = "generator executable"; path = Join-Path (Split-Path $ToolPath) "clang-resource\$Version" }
    if ($ResourceOverride) {
        $path = [IO.Path]::GetFullPath($ResourceOverride)
        $directory = [IO.DirectoryInfo]::new($path)
        if ($directory.Name -ceq "include") { $path = $directory.Parent.FullName }
        [ordered]@{ source = "CLANG_RESOURCE_DIR"; path = $path }
    }
    [ordered]@{ source = "object cache"; path = Join-Path $ObjectPath "clang-resource\$Version" }
}

function Get-FingerprintDependencyPaths {
    param([string]$DepInfo)
    $first = Get-Content -LiteralPath $DepInfo -TotalCount 1 -ErrorAction Stop
    # rustc dep-info escapes spaces; a Windows drive colon is not followed by whitespace.
    $parts = $first -split ':\s+', 2
    if ($parts.Count -ne 2 -or !$parts[1].Trim()) { throw "Malformed Rust dep-info: '$DepInfo'." }
    foreach ($match in [regex]::Matches($parts[1], '(?:\\ |[^\s])+')) {
        $path = $match.Value.Replace('\ ', ' ')
        if (![IO.Path]::IsPathFullyQualified($path)) { throw "Non-absolute Rust dependency in '$DepInfo': '$path'." }
        [IO.Path]::GetFullPath($path)
    }
}

function Add-FingerprintGroup {
    param([System.Collections.IDictionary]$Manifest, [string]$Name, [scriptblock]$Read)
    $records = [Collections.Generic.List[object]]::new()
    try {
        & $Read | ForEach-Object { $records.Add($_) }
    }
    catch {
        $Manifest.errors.Add("$Name`: $($_.Exception.Message)")
    }
    finally {
        $Manifest.groups[$Name] = $records.ToArray()
    }
}

function Get-FingerprintCargoInputs {
    param([string]$ManifestPath)
    $cargoRoot = Split-Path $ManifestPath
    $lock = Get-Content -LiteralPath (Join-Path $cargoRoot "Cargo.lock") -Raw -ErrorAction Stop
    foreach ($name in @("windows-clang", "windows-default", "windows-metadata", "windows-rdl")) {
        $package = @([regex]::Matches($lock, '(?ms)^\[\[package\]\]\r?\n(.*?)(?=^\[\[package\]\]|\z)') |
            Where-Object { $_.Groups[1].Value -match ('(?m)^name = "' + [regex]::Escape($name) + '"\r?$') })
        if ($package.Count -ne 1 -or $package[0].Value -notmatch '(?m)^source = "git\+[^"\r\n]+#([0-9a-f]{40})"\r?$') {
            throw "Expected one locked Git source for '$name'; cannot identify configured native inputs."
        }
        $revision = $Matches[1]
        $pattern = $name.Replace("-", "_") + "-*.d"
        [string[]]$depFiles = @(Get-ChildItem -LiteralPath (Join-Path $cargoRoot "target\release\deps") -Filter $pattern -File -ErrorAction Stop |
            ForEach-Object FullName)
        [Array]::Sort($depFiles, [StringComparer]::Ordinal)
        $matching = [Collections.Generic.SortedDictionary[string, object]]::new([StringComparer]::Ordinal)
        foreach ($dep in $depFiles) {
            $paths = @(Get-FingerprintDependencyPaths $dep)
            $ancestor = Split-Path $paths[0]
            while ($ancestor -and !(Test-Path -LiteralPath (Join-Path $ancestor ".git"))) {
                $ancestor = Split-Path $ancestor
            }
            if (!$ancestor) { continue }
            $head = & git -C $ancestor rev-parse HEAD
            if ($LASTEXITCODE -ne 0) { throw "Cannot resolve native dependency checkout '$ancestor'." }
            if ($head -cne $revision) { continue }
            $crate = Split-Path $paths[0]
            while ($crate -and !(Test-Path -LiteralPath (Join-Path $crate "Cargo.toml") -PathType Leaf)) {
                $crate = Split-Path $crate
            }
            if (!$crate) { throw "Missing manifest for configured native dependency '$name'." }
            $crateText = Get-Content -LiteralPath (Join-Path $crate "Cargo.toml") -Raw
            if ($crateText -notmatch ('(?m)^name\s*=\s*"' + [regex]::Escape($name) + '"\s*$')) {
                throw "Native dependency '$name' does not match the discovered crate manifest '$crate'."
            }
            [string[]]$paths = @($paths | Select-Object -Unique)
            [Array]::Sort($paths, [StringComparer]::Ordinal)
            $matching[$dep] = [ordered]@{
                depInfo = Get-FingerprintFile $dep
                checkout = $ancestor
                commit = $head
                crateManifest = Get-FingerprintFile (Join-Path $crate "Cargo.toml")
                checkoutManifest = Get-FingerprintFile (Join-Path $ancestor "Cargo.toml")
                files = @($paths | ForEach-Object { Get-FingerprintFile $_ })
            }
        }
        if (!$matching.Count) { throw "No built dep-info for configured '$name' revision $revision." }
        [ordered]@{
            package = $name
            lockedRevision = $revision
            evidence = "Available dep-info matching the configured checkout; not proof of the linked artifact or runtime reads."
            candidates = @($matching.Values)
        }
    }
}

function Save-WindowsRsInputFingerprint {
    param([string]$Root, [string]$Phase, [string]$Output, [string]$Log)
    $ErrorActionPreference = "Stop"
    $PSNativeCommandUseErrorActionPreference = $false
    $Root = [IO.Path]::GetFullPath($Root)
    $Output = [IO.Path]::GetFullPath($Output)
    New-Item -ItemType Directory -Path (Split-Path $Output) -Force | Out-Null
    # CreateNew prevents re-running CI collection from overwriting earlier/sealed evidence.
    $stream = [IO.File]::Open($Output, [IO.FileMode]::CreateNew, [IO.FileAccess]::Write, [IO.FileShare]::Read)
    $manifest = [ordered]@{
        schema = 2
        phase = $Phase
        repository = $Root
        classification = "Hash-only available-input inventory; not a file-read trace."
        limitations = @(
            "Before runs before provisioning; runtime/SDK inventories are collected After, not at load time.",
            "Project evaluation is configuration, not a replay of command-line property overrides.",
            "Library inventories include available archives, not the native canonical selected-library subset.",
            "Resource lookup is derived for explicit non-x64 resource-dir arguments; x64 default Clang lookup is not observed.",
            "Native log lines report paths; only the successful generation receipt binds an executed tool hash."
        )
        gaps = @(
            "Five in-memory TU source bytes, ordered header lists and final extract argument vectors need a native hook at Input::new and the call to extract.",
            "Loaded DLL module path and selected resource directory are not emitted; reported libclang directory and derived resource candidates are not module-load proof.",
            "Implicit compiler include roots/macros are not observed and are not inferred from package versions or environment dumps.",
            "Selected archive/read subset and the in-memory symbol-to-library map are not emitted; available files under passed --lib roots are not a consumption trace."
        )
        groups = [ordered]@{}
        errors = [Collections.Generic.List[string]]::new()
    }
    try {
        Add-FingerprintGroup $manifest "checkout" {
            $head = & git -C $Root rev-parse HEAD
            if ($LASTEXITCODE -ne 0) { throw "Cannot read checkout commit." }
            $dirty = @(& git -C $Root status --porcelain --untracked-files=no)
            if ($LASTEXITCODE -ne 0) { throw "Cannot read checkout status." }
            [ordered]@{ commit = $head; trackedChanges = $dirty }
        }
        Add-FingerprintGroup $manifest "configuredSource" {
            foreach ($relative in @(
                "tools\rust\Cargo.toml", "tools\rust\Cargo.lock", "rust-toolchain.toml", "eng\Versions.props",
                "generation\WinSDK\Windows.Win32.proj", "sources\GeneratorSdk\sdk\sdk.props",
                "sources\GeneratorSdk\sdk\sdk.targets", "scripts\BuildMetadataBin.ps1",
                "scripts\Build-Win32MetadataTools.ps1", "scripts\Prepare-WindowsRsHeaders.ps1",
                "scripts\Prepare-ClangResourceHeaders.ps1", "scripts\ClangResourceManifest.ps1",
                "scripts\Save-WindowsRsInputFingerprint.ps1", ".github\workflows\pr-validation.yml")) {
                Get-FingerprintFile (Join-Path $Root $relative)
            }
            Get-FingerprintTree (Join-Path $Root "tools\rust\src")
        }
        if ($Phase -eq "After") {
            Add-FingerprintGroup $manifest "nativeReportedPaths" { Get-FingerprintNativeLog $Log }
            $nativeLog = $manifest.groups.nativeReportedPaths | Select-Object -First 1
            Add-FingerprintGroup $manifest "nativeRuntimeBindings" {
                foreach ($runtime in $nativeLog.runtimes) {
                    [ordered]@{
                        reportedAtLine = $runtime.line; reportedVersion = $runtime.version; reportedDirectory = $runtime.directory
                        dllAtReportedDirectory = Get-FingerprintFile (Join-Path $runtime.directory "libclang.dll")
                        loadedModulePathObserved = $false
                    }
                }
            }
            Add-FingerprintGroup $manifest "captureHeaderBindings" {
                foreach ($capture in $nativeLog.captures) {
                    [ordered]@{
                        reportedAtLine = $capture.line
                        annotation = Get-FingerprintFile $capture.annotation
                        sal = Get-FingerprintFile $capture.sal
                        evidence = "Paths reported by the native run; byte hashes sampled afterward."
                    }
                }
            }
            $evaluation = $null
            Add-FingerprintGroup $manifest "projectEvaluation" {
                $properties = "Win32MetadataToolsExe,Win32MetadataToolsManifest,Win32MetadataToolsCommand,LibClangPath,WinmdObjDir,OutputWinmd,TargetArchitectures,WinmdArchitectureJobs,WinmdUseSdkHeaderManifest,WinmdUsePartitionAuthority,WinmdRootNamespace,WinmdAssemblyName,WinmdVersion"
                $items = "WinmdIncludeDir,ImportLibs,Partition,WinmdPartitionRoot,WinmdPartitionPolicyRoot,WinmdNamespaceRoutes,WinmdScope,WinmdScopeHeader"
                $text = & dotnet msbuild (Join-Path $Root "generation\WinSDK\Windows.Win32.proj") -nologo "-getProperty:$properties" "-getItem:$items" | Out-String
                if ($LASTEXITCODE -ne 0) { throw "Restored project evaluation failed." }
                $text | ConvertFrom-Json -AsHashtable
            }
            if ($manifest.groups.projectEvaluation.Count -eq 1) {
                $evaluation = $manifest.groups.projectEvaluation[0]
                $properties = $evaluation.Properties
                foreach ($name in @("Win32MetadataToolsExe", "Win32MetadataToolsManifest", "LibClangPath", "WinmdObjDir", "OutputWinmd")) {
                    if (!$properties[$name] -or ![IO.Path]::IsPathFullyQualified($properties[$name])) {
                        throw "Missing or non-absolute evaluated property '$name'."
                    }
                }
                $preparationPath = Join-Path $Root "generation\WinSDK\obj\windows-rs-headers.json"
                $invocation = $null
                $prepared = $null
                Add-FingerprintGroup $manifest "generationProvenance" {
                    foreach ($path in @($preparationPath, "$($properties.OutputWinmd).provenance.json")) {
                        if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
                            [ordered]@{ path = $path; state = "not-produced"; consumedSelectionProven = $false }
                            continue
                        }
                        $record = [ordered]@{ file = Get-FingerprintFile $path }
                        $receipt = Get-Content -LiteralPath $path -Raw | ConvertFrom-Json -AsHashtable
                        if ($receipt.schema -ne 1) { throw "Unsupported or malformed generation provenance: '$path'." }
                        if ($path -ceq $preparationPath) {
                            $record["kind"] = "preparation"
                            $record["summary"] = [ordered]@{
                                sourceRoot = $receipt.sourceRoot; preparedRoot = $receipt.preparedRoot
                                inputSha256 = $receipt.inputSha256; preparedSha256 = $receipt.preparedSha256
                                preparedFileCount = $receipt.prepared.Count
                            }
                        } else {
                            if (!$receipt.arguments -or $receipt.arguments[0] -cne "scrape") { throw "Missing scrape arguments in '$path'." }
                            foreach ($inputName in @("tool", "preparation", "output")) {
                                $hashName = "$($inputName)Sha256"
                                if (!$receipt[$inputName] -or $receipt[$hashName] -cnotmatch '^[0-9A-F]{64}$') { throw "Missing $inputName binding in '$path'." }
                                $actual = Get-FingerprintFile $receipt[$inputName]
                                if ($actual.sha256 -cne $receipt[$hashName]) { throw "Generation provenance $inputName bytes changed: '$($actual.path)'." }
                            }
                            $record["kind"] = "generation"
                            $record["receipt"] = $receipt
                            $record["toolHashMatchesSuccessfulInvocationReceipt"] = $true
                        }
                        $record
                    }
                }
                $invocation = ($manifest.groups.generationProvenance | Where-Object kind -eq "generation" | Select-Object -First 1).receipt
                $prepared = $manifest.groups.generationProvenance | Where-Object kind -eq "preparation" | Select-Object -First 1
                $inputSource = if ($invocation) { "successful generation receipt arguments" } else { "project evaluation; invocation not proven" }
                $includePaths = if ($invocation) { @(Get-FingerprintArgumentValues $invocation.arguments "--include") } else { @($evaluation.Items.WinmdIncludeDir.FullPath) }
                $importPaths = if ($invocation) { @(Get-FingerprintArgumentValues $invocation.arguments "--lib") } else { @($evaluation.Items.ImportLibs.FullPath) }
                $architectures = if ($invocation) { @(Get-FingerprintArgumentValues $invocation.arguments "--arch") } else { @($properties.TargetArchitectures.Split(";")) }
                $objectPath = $properties.WinmdObjDir
                if ($invocation) {
                    $objects = @(Get-FingerprintArgumentValues $invocation.arguments "--obj")
                    if ($objects.Count -ne 1) { throw "Expected one recorded --obj for ordinary stage receipts." }
                    $objectPath = $objects[0]
                }
                Add-FingerprintGroup $manifest "passedOptionsAndTranslationUnits" {
                    [ordered]@{
                        source = $inputSource; architectureOrder = $architectures
                        toolArguments = if ($invocation) { $invocation.arguments } else { $null }
                        reportedNativeRuns = @($nativeLog.runs)
                        actualTuContentsAndHeaderLists = "not-observed: native inputs are in memory; no reconstructed source hashes"
                        finalCompilerOptionsAndDefines = "not-observed: tool arguments are not final per-architecture extract arguments"
                    }
                }
                Add-FingerprintGroup $manifest "configuredToolAndRuntime" {
                    Get-FingerprintFile $properties.Win32MetadataToolsExe
                    Get-FingerprintFile (Join-Path $properties.LibClangPath "libclang.dll")
                }
                Add-FingerprintGroup $manifest "resourceCandidates" {
                    . (Join-Path $Root "scripts\ClangResourceManifest.ps1")
                    $selected = $false
                    foreach ($candidate in @(Get-FingerprintResourceCandidates $properties.LibClangPath $properties.Win32MetadataToolsExe $properties.WinmdObjDir $env:CLANG_RESOURCE_DIR $ClangResourceVersion)) {
                        $exists = Test-Path -LiteralPath $candidate.path
                        $valid = $false
                        $reason = $null
                        if ($exists) {
                            try { $valid = Test-ClangResourceTree -Root $candidate.path -RequirePackagedManifest -ThrowOnError }
                            catch { $reason = $_.Exception.Message }
                        }
                        $firstValid = !$selected -and $valid
                        if ($firstValid) { $selected = $true }
                        [ordered]@{
                            source = $candidate.source; path = $candidate.path; exists = $exists
                            valid = $valid; rejection = $reason; derivedFirstValid = $firstValid
                            selectedDirectoryObserved = $false
                            files = @(if ($exists) { Get-FingerprintTree $candidate.path })
                        }
                    }
                    if (!$selected) { throw "No valid resource candidate under native lookup precedence." }
                }
                Add-FingerprintGroup $manifest "availableImportArchives" {
                    if (!$importPaths.Count) { throw "No recorded or evaluated ImportLibs inputs." }
                    $order = 0
                    foreach ($path in $importPaths) {
                        $files = @(if (Test-Path -LiteralPath $path -PathType Container) {
                            Get-FingerprintTree $path "*.lib" -TopLevel
                        } else { Get-FingerprintFile $path })
                        if (!$files.Count) { throw "No import archives available at '$path'." }
                        [ordered]@{
                            order = $order++; configuredPath = $path; source = $inputSource
                            archiveCount = $files.Count; files = @($files)
                            consumedArchiveSubset = "not-observed; no fixed historical library count or invented selection map"
                        }
                    }
                }
                Add-FingerprintGroup $manifest "availableIncludeInputs" {
                    if (!$includePaths.Count) { throw "No recorded or evaluated include inputs." }
                    $order = 0
                    foreach ($path in $includePaths) {
                        if ($prepared -and [IO.Path]::GetFullPath($path) -ieq $prepared.summary.preparedRoot) {
                            [ordered]@{
                                order = $order++; configuredPath = $path; source = $inputSource
                                preparedManifest = $prepared.file; preparedSha256 = $prepared.summary.preparedSha256
                                fileCount = $prepared.summary.preparedFileCount
                                evidence = "Reuses existing prepared-file manifest; this collector does not repeat preparation verification."
                            }
                        } else {
                            $files = @(Get-FingerprintTree $path)
                            [ordered]@{ order = $order++; configuredPath = $path; source = $inputSource; fileCount = $files.Count; files = $files }
                        }
                    }
                }
                Add-FingerprintGroup $manifest "configuredPartitionAndRoutingInputs" {
                    foreach ($kind in @("Partition", "WinmdPartitionRoot", "WinmdPartitionPolicyRoot", "WinmdNamespaceRoutes")) {
                        $option = @{ Partition = "--partition"; WinmdPartitionRoot = "--partition-root"; WinmdPartitionPolicyRoot = "--partition-policy-root"; WinmdNamespaceRoutes = "--namespace-routes" }[$kind]
                        $paths = if ($invocation) { @(Get-FingerprintArgumentValues $invocation.arguments $option) } else { @($evaluation.Items[$kind].FullPath) }
                        foreach ($path in $paths) {
                            if ($kind -eq "WinmdPartitionPolicyRoot") {
                                $policies = @(Get-FingerprintPolicyInputs $path)
                                [ordered]@{
                                    item = $kind; path = $path; source = $inputSource; activePolicyCount = $policies.Count; policies = $policies
                                    selection = "Snapshot of immediate main.cpp/settings.rsp inputs under the native load_active rule, not proof of reads."
                                }
                                continue
                            }
                            $files = if (Test-Path -LiteralPath $path -PathType Container) {
                                @(Get-FingerprintTree $path)
                            } else { @(Get-FingerprintFile $path) }
                            [ordered]@{ item = $kind; path = $path; source = $inputSource; files = @($files) }
                        }
                    }
                }
                Add-FingerprintGroup $manifest "configuredNativeDependencies" {
                    Get-FingerprintCargoInputs $properties.Win32MetadataToolsManifest
                }
                Add-FingerprintGroup $manifest "ordinaryStageReceipts" {
                    foreach ($architecture in $architectures) {
                        if ($architecture -cnotin @("x64", "x86", "arm64")) { throw "Unexpected recorded architecture '$architecture'." }
                        $path = Join-Path $objectPath "Windows.Win32.$architecture.winmd"
                        if (Test-Path -LiteralPath $path -PathType Leaf) {
                            [ordered]@{ stage = "ordinary-premerge"; architecture = $architecture; source = $inputSource; file = Get-FingerprintFile $path }
                        } elseif ($invocation) {
                            throw "Successful generation is missing ordinary premerge image '$path'."
                        } else {
                            [ordered]@{ stage = "ordinary-premerge"; architecture = $architecture; path = $path; state = "not-produced-or-not-at-evaluated-path" }
                        }
                    }
                    $path = $properties.OutputWinmd
                    if (Test-Path -LiteralPath $path -PathType Leaf) {
                        [ordered]@{ stage = "final"; file = Get-FingerprintFile $path; successfulInvocationBound = [bool]$invocation }
                    } else { [ordered]@{ stage = "final"; path = $path; state = "not-produced" } }
                }
                Add-FingerprintGroup $manifest "availableGeneratedInputArtifacts" {
                    $files = @(if (Test-Path -LiteralPath $objectPath -PathType Container) {
                        Get-FingerprintTree $objectPath -Extensions @(".cpp", ".h", ".hpp", ".json", ".tsv", ".rsp", ".txt")
                    })
                    [ordered]@{
                        root = $objectPath; files = $files
                        evidence = "Existing on-disk generated source/header-list/report artifacts only; not reconstructed in-memory TUs or an asserted selection map."
                    }
                }
            }
            Add-FingerprintGroup $manifest "invocationBuildLogs" {
                $files = @(Get-FingerprintTree (Join-Path $Root "bin\logs") "BuildMetadataBin_*.binlog" -TopLevel)
                [ordered]@{
                    evidence = "Existing MSBuild binary logs can establish invocation/options; hashes alone are not a decoded invocation."
                    state = if ($files.Count) { "available" } else { "not-produced" }
                    files = $files
                }
            }
        }
    }
    catch {
        $manifest.errors.Add($_.Exception.Message)
    }
    finally {
        $manifest["complete"] = $manifest.errors.Count -eq 0
        $bytes = [Text.Encoding]::UTF8.GetBytes(($manifest | ConvertTo-Json -Depth 32) + "`n")
        try { $stream.Write($bytes, 0, $bytes.Length) } finally { $stream.Dispose() }
    }
    if ($manifest.errors.Count) { throw "Input fingerprint incomplete; preserved '$Output': $($manifest.errors -join '; ')" }
    Write-Host "Preserved $Phase input fingerprint: $Output"
}

if ($MyInvocation.InvocationName -ne ".") {
    if (!$OutputPath) { throw "-OutputPath is required." }
    Save-WindowsRsInputFingerprint -Root $RepositoryRoot -Phase $Phase -Output $OutputPath -Log $GenerationLog
}
