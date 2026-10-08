param()

$ErrorActionPreference = "Stop"
. "$PSScriptRoot\Save-WindowsRsInputFingerprint.ps1"
$repo = [IO.Path]::GetFullPath("$PSScriptRoot\..")
$fixture = Join-Path $repo "obj\WindowsRsInputFingerprintTests\fixture with spaces-$([Guid]::NewGuid().ToString('N'))"
$originalResourceOverride = $env:CLANG_RESOURCE_DIR
$originalCulture = [Globalization.CultureInfo]::CurrentCulture
$script:assertions = 0
$script:evaluationText = $null

function Assert([bool]$Condition, [string]$Message) {
    if (!$Condition) { throw $Message }
    $script:assertions++
}

function Write-Fixture([string]$Path, [string]$Text) {
    New-Item -ItemType Directory -Path (Split-Path $Path) -Force | Out-Null
    [IO.File]::WriteAllText($Path, $Text)
}

function Expect-Failure([scriptblock]$Run, [string]$Pattern) {
    $errorText = $null
    try { & $Run | Out-Null } catch { $errorText = $_.Exception.Message }
    Assert ($errorText -and $errorText -match $Pattern) "Expected '$Pattern', got '$errorText'."
}

# No builds, Cargo, restores, network, or real checkout mutations in these fixtures.
function git {
    $global:LASTEXITCODE = 0
    if ($args -contains "rev-parse") { return ("a" * 40) }
    if ($args -contains "status") { return }
    throw "Unexpected git operation in fingerprint fixture."
}
function dotnet {
    Assert ($args -contains "msbuild" -and !($args -match '^-t:')) "Fingerprint collection attempted a build target."
    $global:LASTEXITCODE = 0
    $script:evaluationText
}

function Save-Fixture([string]$Name, [string]$Stage = "After") {
    $output = Join-Path $fixture "$Name.json"
    Save-WindowsRsInputFingerprint -Root $fixture -Phase $Stage -Output $output -Log (Join-Path $fixture "generation.log")
    Get-Content -LiteralPath $output -Raw | ConvertFrom-Json -AsHashtable
}

try {
    foreach ($path in @(
        "tools\rust\Cargo.toml", "rust-toolchain.toml", "eng\Versions.props", "generation\WinSDK\Windows.Win32.proj",
        "sources\GeneratorSdk\sdk\sdk.props", "sources\GeneratorSdk\sdk\sdk.targets",
        "scripts\BuildMetadataBin.ps1", "scripts\Build-Win32MetadataTools.ps1", "scripts\Prepare-WindowsRsHeaders.ps1",
        "scripts\Prepare-ClangResourceHeaders.ps1", "scripts\Save-WindowsRsInputFingerprint.ps1",
        ".github\workflows\pr-validation.yml", "tools\rust\src\scrape.rs")) {
        Write-Fixture (Join-Path $fixture $path) "fixture $path"
    }
    $libDir = Join-Path $fixture "runtime"
    $toolDir = Join-Path $fixture "tool"
    $tool = Join-Path $toolDir "win32metadata-tools.exe"
    Write-Fixture $tool "native tool fixture"
    Write-Fixture (Join-Path $libDir "libclang.dll") "runtime fixture"
    $env:CLANG_RESOURCE_DIR = Join-Path $fixture "override\include"
    $resourceRoots = @((Join-Path $libDir "clang-resource\22.1.8"), (Join-Path $toolDir "clang-resource\22.1.8"), (Split-Path $env:CLANG_RESOURCE_DIR))
    foreach ($root in $resourceRoots) {
        Write-Fixture (Join-Path $root "include\stddef.h") "resource fixture"
        Write-Fixture (Join-Path $root "LICENSE.TXT") "license fixture"
    }
    $resourceManifest = "# version`t22.1.8`n# llvm-project-commit`tca7933e47d3a3451d81e72ac174dcb5aa28b59d1`n# sha256`tsize`tpath`n"
    foreach ($relative in @("LICENSE.TXT", "include\stddef.h")) {
        $file = Get-FingerprintFile (Join-Path $resourceRoots[0] $relative)
        $resourceManifest += "$($file.sha256)`t$($file.length)`t$($relative.Replace('\', '/'))`n"
    }
    foreach ($root in $resourceRoots) { Write-Fixture (Join-Path $root "manifest.tsv") $resourceManifest }
    $pinnedManifest = Join-Path $fixture "resource-manifest.tsv"
    Write-Fixture $pinnedManifest $resourceManifest
    Write-Fixture (Join-Path $fixture "scripts\ClangResourceManifest.ps1") @"
. '$PSScriptRoot\ClangResourceManifest.ps1'
`$ClangResourceManifest = '$pinnedManifest'
"@

    $include = Join-Path $fixture "includes"
    Write-Fixture (Join-Path $include "z.h") "last"
    Write-Fixture (Join-Path $include "A.h") "first"
    Write-Fixture (Join-Path $include "annotations.h") "annotation fixture"
    Write-Fixture (Join-Path $include "sal.h") "SAL fixture"
    $imports = @((Join-Path $fixture "libs first"), (Join-Path $fixture "libs second"))
    Write-Fixture (Join-Path $imports[0] "same.lib") "first library"
    Write-Fixture (Join-Path $imports[1] "same.lib") "second library"
    $policy = Join-Path $fixture "policy"
    foreach ($name in @("ActiveB", "ActiveA")) {
        Write-Fixture (Join-Path $policy "$name\main.cpp") "policy source $name"
        Write-Fixture (Join-Path $policy "$name\settings.rsp") "policy settings $name"
    }
    Write-Fixture (Join-Path $policy "Inactive\settings.rsp") "not an active policy"
    $route = Join-Path $fixture "routes.rsp"
    Write-Fixture $route "route fixture"

    $native = Join-Path $fixture "native checkout"
    New-Item -ItemType Directory -Path (Join-Path $native ".git") -Force | Out-Null
    Write-Fixture (Join-Path $native "Cargo.toml") "[workspace]"
    $lock = "# fixture lock`n"
    foreach ($package in @("windows-clang", "windows-default", "windows-metadata", "windows-rdl")) {
        $lock += "[[package]]`nname = `"$package`"`nsource = `"git+https://example.invalid/native#$('a' * 40)`"`n"
        $input = Join-Path $native "$package\lib.rs"
        $embedded = Join-Path $native "$package\embedded.winmd"
        Write-Fixture (Join-Path $native "$package\Cargo.toml") "[package]`nname = `"$package`""
        Write-Fixture $input "$package fixture"
        Write-Fixture $embedded "$package embedded fixture"
        $dep = Join-Path $fixture "tools\rust\target\release\deps\$($package.Replace('-', '_'))-fixture.d"
        Write-Fixture $dep "$($dep.Replace(' ', '\ ')): $($input.Replace(' ', '\ ')) $($embedded.Replace(' ', '\ '))`n"
    }
    Write-Fixture (Join-Path $fixture "tools\rust\Cargo.lock") $lock
    Write-Fixture (Join-Path $fixture "bin\logs\BuildMetadataBin_fixture.binlog") "invocation log fixture"
    Write-Fixture (Join-Path $fixture "generation.log") @"
Using libclang clang version 22.1.8 from $libDir (LIBCLANG_PATH)
Using annotation contract $include\annotations.h and SAL contract $include\sal.h
Architecture worker limit: 3
Scraping 2 logical partition(s) as 5 translation unit(s) for x64, x86, arm64 into $fixture\objects\rdl
Build, test, package`tBuild metadata binary`t2026-10-08T02:28:28.0676210Z   Extracted 579230 facts for arm64 in 3.45s
Extracted 578970 facts for x64 in 1.23s
1> Extracted 578897 facts for x86 in 2.34s
UNRELATED_ENVIRONMENT=fixture-secret-not-for-the-manifest
"@
    $evaluation = @{
        Properties = @{
            Win32MetadataToolsExe = $tool; LibClangPath = $libDir
            Win32MetadataToolsManifest = Join-Path $fixture "tools\rust\Cargo.toml"
            WinmdObjDir = Join-Path $fixture "objects"
            OutputWinmd = Join-Path $fixture "output.winmd"
            TargetArchitectures = "x64;x86;arm64"; WinmdArchitectureJobs = "3"
        }
        Items = @{
            WinmdIncludeDir = @(@{ FullPath = $include })
            ImportLibs = @($imports | ForEach-Object { @{ FullPath = $_ } })
            Partition = @(); WinmdPartitionRoot = @()
            WinmdPartitionPolicyRoot = @(@{ FullPath = $policy })
            WinmdNamespaceRoutes = @(@{ FullPath = $route })
        }
    }
    $script:evaluationText = $evaluation | ConvertTo-Json -Depth 8
    $before = Save-Fixture "before" "Before"
    Assert ($before.complete -and !$before.groups.Contains("projectEvaluation")) "Before inventory unexpectedly requires provisioned tools."
    $first = Save-Fixture "first"
    $second = Save-Fixture "second"
    Assert ($first.complete) "Fixture inventory was not complete."
    Assert ((Get-Content (Join-Path $fixture "first.json") -Raw) -ceq (Get-Content (Join-Path $fixture "second.json") -Raw)) "Identical input manifests were not deterministic."
    Assert (($first.groups.availableIncludeInputs[0].files.relativePath -join ";") -ceq "A.h;annotations.h;sal.h;z.h") "Tree inventory is not in ordinal path order."
    Assert ($first.groups.availableImportArchives.Count -eq 2) "Same-name import archives were collapsed."
    Assert ($first.groups.availableImportArchives[0].files[0].sha256 -cne $first.groups.availableImportArchives[1].files[0].sha256) "Different same-name archive bytes were lost."
    Assert ($first.groups.availableImportArchives[0].configuredPath -ceq $imports[0]) "Configured search order was lost."
    Assert ($first.groups.resourceCandidates[0].derivedFirstValid -and !$first.groups.resourceCandidates[2].derivedFirstValid) "Resource environment override incorrectly outranked libclang-adjacent resources."
    Assert ($first.groups.resourceCandidates[2].path -ceq (Split-Path $env:CLANG_RESOURCE_DIR)) "Resource include suffix was not normalized."
    $trailingSeparator = @(Get-FingerprintResourceCandidates $libDir $tool (Join-Path $fixture "objects") "$env:CLANG_RESOURCE_DIR\" "22.1.8")
    Assert ($trailingSeparator[2].path -ceq (Split-Path $env:CLANG_RESOURCE_DIR)) "Trailing resource include separator changed native resolution."
    Assert ($first.groups.configuredNativeDependencies.Count -eq 4) "Configured native dependencies were omitted."
    Assert ($first.groups.configuredNativeDependencies[0].candidates[0].files.Count -eq 2) "Dep-info paths with spaces or embedded references were lost."
    Assert ($first.groups.nativeReportedPaths[0].statements.Count -eq 7) "Native-reported evidence was lost."
    Assert ((@($first.groups.nativeReportedPaths[0].extractedFacts | ForEach-Object { "$($_.architecture)=$($_.count)" }) -join ";") -ceq "arm64=579230;x64=578970;x86=578897") "Per-architecture fact counts were confused with completion order."
    Assert ($first.groups.nativeReportedPaths[0].runs[0].translationUnits -eq 5) "Printed five-TU identity was lost."
    Assert ($first.groups.captureHeaderBindings[0].annotation.sha256 -ceq (Get-FingerprintFile (Join-Path $include "annotations.h")).sha256) "Actual reported annotation header was not bound."
    Assert ($first.groups.nativeRuntimeBindings[0].dllAtReportedDirectory.sha256 -ceq (Get-FingerprintFile (Join-Path $libDir "libclang.dll")).sha256) "Reported runtime directory bytes were not bound."
    Assert (!$first.groups.nativeRuntimeBindings[0].loadedModulePathObserved) "A reported directory was promoted to loaded-module proof."
    $policyInputs = @($first.groups.configuredPartitionAndRoutingInputs | Where-Object item -eq "WinmdPartitionPolicyRoot")[0]
    Assert ($policyInputs.activePolicyCount -eq 2 -and ($policyInputs.policies.name -join ";") -ceq "ActiveA;ActiveB") "Policy main/settings bindings included inactive directories or fixed a historical count."
    Assert ($first.groups.availableImportArchives[0].archiveCount -eq 1) "Archive inventory count was hardcoded."
    Assert ($first.groups.passedOptionsAndTranslationUnits[0].actualTuContentsAndHeaderLists.StartsWith("not-observed")) "TU content identities were reconstructed or fabricated."
    Assert (($first.limitations -join " ").Contains("not observed") -and $first.classification.Contains("not a file-read trace")) "Available inventories were presented as proven consumption."
    Assert (!(Get-Content (Join-Path $fixture "first.json") -Raw).Contains("fixture-secret")) "Unrelated log content leaked into the manifest."
    Assert ($first.groups.generationProvenance[0].state -ceq "not-produced") "Failed/unfinished generation provenance was fabricated."
    [Globalization.CultureInfo]::CurrentCulture = [Globalization.CultureInfo]::GetCultureInfo("tr-TR")
    $null = Save-Fixture "culture"
    Assert ((Get-Content (Join-Path $fixture "first.json") -Raw) -ceq (Get-Content (Join-Path $fixture "culture.json") -Raw)) "Inventory ordering depended on culture."
    [Globalization.CultureInfo]::CurrentCulture = $originalCulture

    Write-Fixture (Join-Path $include "A.h") "mutated byte contents"
    $mutated = Save-Fixture "mutation"
    Assert ($first.groups.availableIncludeInputs[0].files[0].sha256 -cne $mutated.groups.availableIncludeInputs[0].files[0].sha256) "Byte mutation was not detected."
    Write-Fixture (Join-Path $resourceRoots[0] "include\stddef.h") "invalid first candidate"
    $fallback = Save-Fixture "fallback"
    Assert (!$fallback.groups.resourceCandidates[0].valid -and $fallback.groups.resourceCandidates[1].derivedFirstValid) "Invalid earlier resources prevented native-order fallback."
    Assert (![string]::IsNullOrEmpty($fallback.groups.resourceCandidates[0].rejection)) "Rejected resource candidate reason was omitted."
    foreach ($root in $resourceRoots[1..2]) { Write-Fixture (Join-Path $root "include\stddef.h") "invalid resource bytes" }
    Expect-Failure { Save-Fixture "no-valid-resources" } "No valid resource candidate"
    $partial = Get-Content (Join-Path $fixture "no-valid-resources.json") -Raw | ConvertFrom-Json
    Assert (!$partial.complete -and $partial.groups.resourceCandidates.Count -eq 4) "Resource resolution failure lost rejected/missing candidates."
    foreach ($root in $resourceRoots[1..2]) { Write-Fixture (Join-Path $root "include\stddef.h") "resource fixture" }

    $preparation = Join-Path $fixture "generation\WinSDK\obj\windows-rs-headers.json"
    $preparedRoot = Join-Path $fixture "prepared"
    Write-Fixture (Join-Path $preparedRoot "fixture.h") "prepared fixture"
    $preparedFile = Get-FingerprintFile (Join-Path $preparedRoot "fixture.h")
    Write-Fixture $preparation (@{
        schema = 1; preparedRoot = $preparedRoot; preparedSha256 = ("b" * 64)
        prepared = @(@{ path = "fixture.h"; length = $preparedFile.length; sha256 = $preparedFile.sha256 })
    } | ConvertTo-Json -Depth 5)
    $output = Join-Path $fixture "output.winmd"
    Write-Fixture $output "output fixture"
    foreach ($architecture in @("x64", "x86", "arm64")) {
        Write-Fixture (Join-Path $fixture "objects\Windows.Win32.$architecture.winmd") "$architecture ordinary image"
    }
    Write-Fixture (Join-Path $fixture "objects\available-header-list.tsv") "already emitted fixture header list"
    $receipt = @{
        schema = 1; tool = $tool; toolSha256 = (Get-FingerprintFile $tool).sha256
        preparation = $preparation; preparationSha256 = (Get-FingerprintFile $preparation).sha256
        output = $output; outputSha256 = (Get-FingerprintFile $output).sha256
        arguments = @(
            "scrape", "--include", $preparedRoot, "--include", $include, "--lib", $imports[0], "--lib", $imports[1],
            "--partition-policy-root", $policy, "--namespace-routes", $route, "--obj", (Join-Path $fixture "objects"),
            "--arch", "x64", "--arch", "x86", "--arch", "arm64"
        )
    }
    Write-Fixture "$output.provenance.json" ($receipt | ConvertTo-Json -Depth 4)
    $bound = Save-Fixture "receipt-bound"
    Assert ($bound.groups.generationProvenance[1].toolHashMatchesSuccessfulInvocationReceipt) "Successful invocation tool binding was not verified."
    Assert ($bound.groups.availableIncludeInputs[0].preparedManifest.sha256 -ceq (Get-FingerprintFile $preparation).sha256) "Prepared include tree did not reuse the existing manifest."
    Assert (!$bound.groups.availableIncludeInputs[0].Contains("files")) "Prepared file inventory was duplicated."
    Assert (($bound.groups.passedOptionsAndTranslationUnits[0].toolArguments -join "|") -ceq ($receipt.arguments -join "|")) "Actual receipt arguments were replaced by evaluated defaults."
    Assert (@($bound.groups.ordinaryStageReceipts | Where-Object stage -eq "ordinary-premerge").Count -eq 3) "Ordinary premerge image hashes were not retained."
    Assert ($bound.groups.availableGeneratedInputArtifacts[0].files[0].relativePath -ceq "available-header-list.tsv") "Available emitted header-list binding was lost."
    Remove-Item -LiteralPath (Join-Path $fixture "objects\Windows.Win32.x86.winmd")
    Expect-Failure { Save-Fixture "missing-premerge" } "missing ordinary premerge"
    $partial = Get-Content (Join-Path $fixture "missing-premerge.json") -Raw | ConvertFrom-Json
    Assert ($partial.groups.ordinaryStageReceipts[0].architecture -ceq "x64") "Missing premerge image discarded an existing stage hash."
    Write-Fixture (Join-Path $fixture "objects\Windows.Win32.x86.winmd") "x86 ordinary image"
    Write-Fixture $tool "changed executable bytes"
    Expect-Failure { Save-Fixture "stale-receipt" } "tool bytes changed"
    Write-Fixture $tool "native tool fixture"
    Remove-Item -LiteralPath $preparation, $output, "$output.provenance.json"
    $sealedHash = (Get-FileHash (Join-Path $fixture "first.json")).Hash
    Expect-Failure { Save-Fixture "first" } "already exists|exist"
    Assert ((Get-FileHash (Join-Path $fixture "first.json")).Hash -ceq $sealedHash) "Existing evidence was overwritten."

    Remove-Item -LiteralPath (Join-Path $libDir "libclang.dll")
    Expect-Failure { Save-Fixture "missing-runtime" } "configuredToolAndRuntime"
    $partial = Get-Content (Join-Path $fixture "missing-runtime.json") -Raw | ConvertFrom-Json
    Assert (!$partial.complete -and $partial.groups.configuredToolAndRuntime.Count -eq 1) "Failure did not preserve partial runtime records."
    Assert ($partial.groups.availableImportArchives.Count -eq 2) "One missing input suppressed independent inventories."
    Write-Fixture (Join-Path $libDir "libclang.dll") "runtime fixture"
    Remove-Item -LiteralPath (Join-Path $imports[1] "same.lib")
    Expect-Failure { Save-Fixture "missing-import" } "No import archives"
    Write-Fixture (Join-Path $imports[1] "same.lib") "second library"
    Write-Fixture (Join-Path $fixture "output.winmd.provenance.json") '{"schema": 1}'
    Expect-Failure { Save-Fixture "malformed-provenance" } "Missing scrape arguments"
    Remove-Item -LiteralPath (Join-Path $fixture "output.winmd.provenance.json")
    $dep = Join-Path $fixture "tools\rust\target\release\deps\windows_clang-fixture.d"
    Write-Fixture $dep "malformed dep-info"
    Expect-Failure { Save-Fixture "malformed-dependency" } "Malformed Rust dep-info"
    $script:evaluationText = "{malformed json"
    Expect-Failure { Save-Fixture "malformed-evaluation" } "projectEvaluation"
    $partial = Get-Content (Join-Path $fixture "malformed-evaluation.json") -Raw | ConvertFrom-Json
    Assert (!$partial.complete -and $partial.groups.nativeReportedPaths.Count -eq 1) "Evaluation failure lost native log evidence."
    $workflow = Get-Content -LiteralPath (Join-Path $repo ".github\workflows\pr-validation.yml") -Raw
    Assert ($workflow -match 'timeout-minutes: 360') "The normal CI timeout changed."
    Assert ($workflow -match 'BuildMetadataBin\.ps1 \*>&1 \| Tee-Object') "Fingerprinting replaced the normal build command."
    Assert ($workflow -match '(?s)name: Preserve configured and available generation input fingerprints\s+if: always\(\)') "Failed generation no longer collects fingerprints."
    Assert ($workflow -match '(?s)name: Upload input fingerprints\s+if: always\(\)') "Failed generation no longer uploads fingerprints."

    $steps = @([regex]::Matches($workflow, '(?ms)^      - (?<body>.*?)(?=^      - |\z)') | ForEach-Object {
        $body = $_.Groups["body"].Value
        [pscustomobject]@{
            Name = [regex]::Match($body, '^name: ([^\r\n]+)').Groups[1].Value
            Id = [regex]::Match($body, '(?m)^        id: (\S+)\r?$').Groups[1].Value
            Condition = [regex]::Match($body, '(?m)^        if: ([^\r\n]+)').Groups[1].Value
            ContinueOnError = [regex]::IsMatch($body, '(?m)^        continue-on-error: true\r?$')
            Body = $body
        }
    })
    $fingerprintIds = @("fingerprint_tests", "fingerprint_before", "fingerprint_after", "fingerprint_upload")
    $productNames = @(
        "Build metadata binary", "Verify prepared input and generated output provenance",
        "Test header preparation and patched generation", "Package", "Test packaged WinmdGenerator SDK",
        "Build samples", "Run strict metadata tests"
    )
    foreach ($id in $fingerprintIds) {
        $step = @($steps | Where-Object Id -ceq $id)
        Assert ($step.Count -eq 1 -and $step[0].ContinueOnError) "Fingerprint step '$id' can still block product execution."
    }
    foreach ($name in $productNames) {
        $step = @($steps | Where-Object Name -ceq $name)
        Assert ($step.Count -eq 1 -and !$step[0].ContinueOnError -and !$step[0].Condition) "Product gate '$name' was changed or waived."
    }
    Assert (@($steps | Where-Object { $_.ContinueOnError -and $_.Id -cnotin $fingerprintIds }).Count -eq 0) "A non-fingerprint step gained continue-on-error."
    $terminal = @($steps | Where-Object Id -ceq "fingerprint_gate")
    Assert ($terminal.Count -eq 1 -and $terminal[0] -eq $steps[-1] -and $terminal[0].Condition -ceq "always()" -and !$terminal[0].ContinueOnError) "Fingerprint error enforcement is not terminal, unconditional, and fatal."
    $terminalRun = [regex]::Match($terminal[0].Body, '(?ms)^        run: \|\r?\n(.*)\z').Groups[1].Value -replace '(?m)^          ', ''
    $references = @([regex]::Matches($terminalRun, '\$\{\{\s*steps\.([a-z_]+)\.outcome\s*\}\}') | ForEach-Object { $_.Groups[1].Value })
    Assert (($references -join ";") -ceq ($fingerprintIds -join ";")) "Terminal enforcement must inspect exactly the original fingerprint outcomes."
    Assert ($terminalRun -notmatch '\.conclusion') "Post-continue-on-error conclusions would conceal collector failures."

    function Invoke-TerminalFixture([hashtable]$Outcomes) {
        # Execute the actual workflow check, substituting only the runner's enum outcomes.
        $body = [regex]::Replace($terminalRun, '\$\{\{\s*steps\.([a-z_]+)\.outcome\s*\}\}', {
            param($match)
            [string]$Outcomes[$match.Groups[1].Value]
        })
        try { & ([scriptblock]::Create($body)); return $null }
        catch { return $_.Exception.Message }
    }

    function Invoke-WorkflowGateFixture([hashtable]$RequestedOutcomes) {
        $normalFailure = $false
        $outcomes = @{}
        $ran = @{}
        foreach ($step in $steps | Where-Object { $_.Id -cin $fingerprintIds -or $_.Name -cin $productNames }) {
            $key = if ($step.Id -cin $fingerprintIds) { $step.Id } else { $step.Name }
            # Model Actions' default success() gate using conclusions, not raw outcomes.
            $attempted = $step.Condition -ceq "always()" -or !$normalFailure
            $ran[$key] = $attempted
            $outcome = if (!$attempted) { "skipped" } elseif ($RequestedOutcomes.ContainsKey($key)) {
                $RequestedOutcomes[$key]
            } else { "success" }
            $outcomes[$key] = $outcome
            if ($outcome -ceq "failure" -and !$step.ContinueOnError) { $normalFailure = $true }
        }
        $errorText = Invoke-TerminalFixture $outcomes
        [pscustomobject]@{ Ran = $ran; Outcomes = $outcomes; ProductFailure = $normalFailure; TerminalError = $errorText }
    }

    # Every combination includes fixture-test, Before, After and upload failures.
    for ($mask = 0; $mask -lt 16; $mask++) {
        $requested = @{}
        for ($i = 0; $i -lt $fingerprintIds.Count; $i++) {
            $requested[$fingerprintIds[$i]] = if ($mask -band (1 -shl $i)) { "failure" } else { "success" }
        }
        $result = Invoke-WorkflowGateFixture $requested
        Assert (@($productNames | Where-Object { !$result.Ran[$_] }).Count -eq 0) "Fingerprint failure combination $mask skipped product steps."
        Assert (!$result.ProductFailure) "Fingerprint failure combination $mask changed a product result."
        Assert ((![string]::IsNullOrEmpty($result.TerminalError)) -eq ($mask -ne 0)) "Fingerprint failure combination $mask was hidden at the terminal gate."
        foreach ($id in $fingerprintIds | Where-Object { $requested[$_] -ceq "failure" }) {
            Assert ($result.TerminalError.Contains($id)) "Terminal gate omitted failed step '$id'."
        }
    }
    Assert (!$partial.complete) "The partial-capture fixture unexpectedly succeeded."
    $partialResult = Invoke-WorkflowGateFixture @{ fingerprint_after = "failure" }
    Assert ($partialResult.Ran["Package"] -and $partialResult.Ran["Run strict metadata tests"] -and $partialResult.TerminalError.Contains("fingerprint_after")) "Partial capture blocked product gates or concealed its error."
    foreach ($failedProduct in @("Build metadata binary", "Package", "Run strict metadata tests")) {
        foreach ($captureFailed in @($false, $true)) {
            $result = Invoke-WorkflowGateFixture @{
                $failedProduct = "failure"
                fingerprint_after = $(if ($captureFailed) { "failure" } else { "success" })
            }
            Assert ($result.ProductFailure) "Existing product failure '$failedProduct' was waived."
            Assert ($result.Ran.fingerprint_after -and $result.Ran.fingerprint_upload) "Product failure '$failedProduct' prevented always-run evidence preservation."
            Assert ((![string]::IsNullOrEmpty($result.TerminalError)) -eq $captureFailed) "The fingerprint gate improperly incorporated product failure '$failedProduct'."
        }
    }
    $skipped = @{}
    foreach ($id in $fingerprintIds) { $skipped[$id] = "skipped" }
    Assert ([string]::IsNullOrEmpty((Invoke-TerminalFixture $skipped))) "Unattempted fingerprint steps were treated as failed attempts."

    Write-Host "PASS: $script:assertions fingerprint assertions; isolated fixtures only."
}
finally {
    $env:CLANG_RESOURCE_DIR = $originalResourceOverride
    [Globalization.CultureInfo]::CurrentCulture = $originalCulture
    if (Test-Path -LiteralPath $fixture) { Remove-Item -LiteralPath $fixture -Recurse -Force }
}
