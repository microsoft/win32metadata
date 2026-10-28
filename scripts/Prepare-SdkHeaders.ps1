#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$Recipe,
    [string]$SourceRoot = "$PSScriptRoot\..\generation\WinSDK\RecompiledIdlHeaders",
    [string]$SdkPackageRoot,
    [string]$MidlPreprocessorPath,
    [string]$OutputRoot = "$PSScriptRoot\..\artifacts\prepared-sdk"
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repoRoot = [IO.Path]::GetFullPath("$PSScriptRoot\..")

function Get-Sha256([string]$Path) {
    (Get-FileHash -LiteralPath $Path -Algorithm SHA256).Hash
}

function Get-TextHash([string]$Text) {
    [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::UTF8.GetBytes($Text)))
}

function Assert-OrdinaryPath([string]$Path) {
    $current = [IO.Path]::GetFullPath($Path)
    while ($current) {
        if (Test-Path -LiteralPath $current) {
            if ((Get-Item -LiteralPath $current -Force).Attributes -band [IO.FileAttributes]::ReparsePoint) {
                throw "Reparse points are not permitted in a prepared-header path: $current"
            }
        }
        $current = [IO.Path]::GetDirectoryName($current)
    }
}

function Get-DirectoryState([string]$Path) {
    $entries = @(Get-ChildItem -LiteralPath $Path -Recurse -Force)
    foreach ($entry in $entries) {
        if ($entry.Attributes -band [IO.FileAttributes]::ReparsePoint) {
            throw "Reparse points are not permitted in the header tree: $($entry.FullName)"
        }
    }
    $files = @($entries | Where-Object { !$_.PSIsContainer } | ForEach-Object {
        [pscustomobject]@{
            path = [IO.Path]::GetRelativePath($Path, $_.FullName)
            sha256 = Get-Sha256 $_.FullName
        }
    } | Sort-Object -Property path -CaseSensitive)
    [pscustomobject]@{
        files = $files
        sha256 = Get-TextHash (($files | ForEach-Object { "$($_.path)`t$($_.sha256)" }) -join "`n")
    }
}

function Resolve-Child([string]$Root, [string]$RelativePath) {
    if ([IO.Path]::IsPathRooted($RelativePath)) {
        throw "Recipe paths must be relative: $RelativePath"
    }
    $path = [IO.Path]::GetFullPath([IO.Path]::Combine($Root, $RelativePath))
    if (!$path.StartsWith("$Root\", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Recipe path escapes its root: $RelativePath"
    }
    Assert-OrdinaryPath $path
    $path
}

function Invoke-HeaderPatch($Patch, [string]$Root) {
    if ((Get-Sha256 $Patch.fullPath) -ne $Patch.sha256) {
        throw "A pinned SDK patch changed during preparation: $($Patch.path)"
    }
    $arguments = @('-c', 'core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol',
        '-C', $repoRoot, 'apply', '--unsafe-paths', '-p1', "--directory=$Root", '--whitespace=error-all')
    $output = & git @arguments --check -- $Patch.fullPath 2>&1
    if ($LASTEXITCODE -ne 0) {
        throw "Patch preflight failed for $($Patch.path):`n$($output -join "`n")"
    }
    $output = & git @arguments -- $Patch.fullPath 2>&1
    if ($LASTEXITCODE -ne 0) {
        throw "Patch failed for $($Patch.path):`n$($output -join "`n")"
    }
}

function Invoke-PreparedMidl([string]$Staging) {
    $raw = "$Staging\midl\source"
    $sal = "$Staging\midl\sal"
    $generated = "$Staging\midl\generated"
    foreach ($directory in @($raw, $sal, $generated)) {
        [IO.Directory]::CreateDirectory($directory) | Out-Null
    }
    foreach ($input in $midlInputs) {
        $target = Resolve-Child $raw $input.path
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        [IO.File]::Copy($input.fullPath, $target)
        if ((Get-Sha256 $target) -ne $input.sha256) {
            throw "A pinned MIDL input changed while being copied: $($input.path)"
        }
    }
    foreach ($patch in @($patches | Where-Object isMidlInput)) {
        Invoke-HeaderPatch $patch $raw
    }
    foreach ($input in $midlInputs) {
        $target = Resolve-Child $sal $input.path
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        if ([IO.Path]::GetExtension($input.path) -eq '.idl') {
            & "$PSScriptRoot\ConvertMidlAttributesToSalAnnotations.ps1" (Resolve-Child $raw $input.path) $target
        }
        else {
            [IO.File]::Copy((Resolve-Child $raw $input.path), $target)
        }
    }

    . "$PSScriptRoot\MidlHeaderUtils.ps1"
    $includes = @($midlInputs | ForEach-Object { [IO.Path]::GetDirectoryName((Resolve-Child $sal $_.path)) } |
        Sort-Object -Unique)
    $environment = @{}
    foreach ($name in @('PATH', 'INCLUDE', 'LIB', 'LIBPATH', 'CL', '_CL_', 'TEMP', 'TMP', 'VSLANG')) {
        $environment[$name] = [Environment]::GetEnvironmentVariable($name, 'Process')
    }
    $commands = @()
    $usedInputs = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
    Push-Location $generated
    try {
        foreach ($name in @('INCLUDE', 'LIB', 'LIBPATH', 'CL', '_CL_')) {
            [Environment]::SetEnvironmentVariable($name, '', 'Process')
        }
        $env:PATH = "$([IO.Path]::GetDirectoryName($MidlPreprocessorPath));$([IO.Path]::GetDirectoryName($midlCompiler));$env:SystemRoot\System32;$env:SystemRoot"
        $env:TEMP = $generated
        $env:TMP = $generated
        $env:VSLANG = '1033'
        if ((Get-Command cl.exe -CommandType Application).Source -ne $MidlPreprocessorPath) {
            throw 'MIDL did not resolve the pinned C preprocessor.'
        }
        foreach ($output in $config.midl.outputs) {
            $header = Resolve-Child $generated $output.path
            [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($header)) | Out-Null
            $arguments = @(Get-MidlHeaderArguments -InputFile (Resolve-Child $sal $output.source) `
                -OutputDirectory $generated -OutputHeader $header -IncludeDirectories $includes -ClosedPreprocessing)
            $log = "$generated\$([IO.Path]::GetFileNameWithoutExtension($output.source)).log"
            & $midlCompiler @arguments *> $log
            $exitCode = $LASTEXITCODE
            $text = [IO.File]::ReadAllText($log)
            $diagnostics = Assert-MidlHeaderResult $output.source $exitCode $text $header
            if ($diagnostics.nonBlockingErrorCount) {
                Write-Warning "Non-blocking MIDL2337 diagnostics for $($output.source): count $($diagnostics.nonBlockingErrorCount); native exit 0; complete header verified. Raw diagnostics:`n$($diagnostics.nonBlockingErrors -join "`n")"
            }
            $commands += [pscustomobject][ordered]@{
                source = $output.source
                header = $output.path
                arguments = @($arguments | ForEach-Object { $_.Replace($Staging, '<prepared>', [StringComparison]::OrdinalIgnoreCase) })
                warnings = @([regex]::Matches($text, '(?im)^.*\bwarning\s+MIDL\d+.*$') |
                    ForEach-Object { $_.Value.Replace($Staging, '<prepared>', [StringComparison]::OrdinalIgnoreCase) })
                exitCode = $exitCode
                logSha256 = Get-Sha256 $log
                nonBlockingErrorCount = $diagnostics.nonBlockingErrorCount
                nonBlockingErrorCounts = $diagnostics.nonBlockingErrorCounts
                nonBlockingErrors = $diagnostics.nonBlockingErrors
                headerSha256 = Get-Sha256 $header
            }
        }
        $declaredPaths = [Collections.Generic.Dictionary[string, string]]::new([StringComparer]::OrdinalIgnoreCase)
        foreach ($input in $midlInputs) {
            $declaredPaths.Add((Resolve-Child $sal $input.path), $input.path)
        }
        foreach ($file in @(Get-ChildItem -LiteralPath $generated -Filter '*.tmp' -File)) {
            foreach ($match in [regex]::Matches([IO.File]::ReadAllText($file.FullName), '(?m)^\s*#line\s+\d+\s+"([^"]+)"')) {
                $path = $match.Groups[1].Value.Replace('\\', '\')
                $relative = $null
                if (!$declaredPaths.TryGetValue($path, [ref]$relative)) {
                    throw "MIDL preprocessing read an unpinned input: $path"
                }
                $usedInputs.Add($relative) | Out-Null
            }
            Remove-Item -LiteralPath $file.FullName
        }
        if (!$usedInputs.SetEquals([string[]]$midlInputs.path)) {
            throw 'The declared MIDL input closure does not match the actual preprocessed inputs.'
        }
        [IO.File]::WriteAllText("$Staging\midl\commands.json", ($commands | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
        $nonBlockingErrors = @($commands | Where-Object nonBlockingErrorCount -GT 0 |
            Select-Object source, nonBlockingErrorCount, nonBlockingErrorCounts, nonBlockingErrors, exitCode, logSha256, headerSha256)
        $nonBlockingCount = [int]($commands | Measure-Object -Property nonBlockingErrorCount -Sum).Sum
        [IO.File]::WriteAllText("$Staging\midl\categorized-diagnostics.json",
            (@{ count = $nonBlockingCount; counts = @{ MIDL2337 = $nonBlockingCount }; commands = $nonBlockingErrors } | ConvertTo-Json -Depth 8),
            [Text.UTF8Encoding]::new($false))
        [IO.File]::WriteAllText("$Staging\midl\preprocessed-inputs.json",
            (@($usedInputs | Sort-Object -CaseSensitive) | ConvertTo-Json), [Text.UTF8Encoding]::new($false))
    }
    finally {
        foreach ($name in $environment.Keys) {
            [Environment]::SetEnvironmentVariable($name, $environment[$name], 'Process')
        }
        Pop-Location
    }
}

function Find-PreparedMidl([string]$Identity) {
    foreach ($candidate in @(Get-ChildItem -LiteralPath $OutputRoot -Directory |
        Where-Object Name -Match '^[A-Fa-f0-9]{64}$' | Sort-Object Name)) {
        $path = "$($candidate.FullName)\manifest.json"
        Assert-OrdinaryPath $path
        if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
            throw "Incomplete published header cache: $($candidate.FullName)"
        }
        $manifest = Get-Content -LiteralPath $path -Raw | ConvertFrom-Json
        if ($null -eq $manifest.PSObject.Properties['midlIdentity'] -or $manifest.midlIdentity -ne $Identity) {
            continue
        }
        $midl = "$($candidate.FullName)\midl"
        Assert-OrdinaryPath $midl
        if ($manifest.schemaVersion -ne 1 -or $manifest.identity -ne $candidate.Name -or
            $null -eq $manifest.PSObject.Properties['midlProducerIdentity'] -or
            $manifest.midlProducerIdentity -cnotmatch '^[A-F0-9]{64}$' -or
            !(Test-Path -LiteralPath $midl -PathType Container)) {
            throw "Incomplete published MIDL cache: $($candidate.FullName)"
        }
        if ($manifest.midlSha256 -ne (Get-DirectoryState $midl).sha256) {
            throw "Published MIDL cache was modified: $($candidate.FullName)."
        }
        return [pscustomobject]@{
            path = $midl
            sha256 = $manifest.midlSha256
            preparedIdentity = $manifest.identity
            producerIdentity = $manifest.midlProducerIdentity
        }
    }
}

$Recipe = [IO.Path]::GetFullPath($Recipe)
$SourceRoot = [IO.Path]::GetFullPath($SourceRoot).TrimEnd('\')
$OutputRoot = [IO.Path]::GetFullPath($OutputRoot).TrimEnd('\')
Assert-OrdinaryPath $Recipe
Assert-OrdinaryPath $SourceRoot
Assert-OrdinaryPath $OutputRoot
if ($OutputRoot -eq $SourceRoot -or $OutputRoot.StartsWith("$SourceRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SourceRoot.StartsWith("$OutputRoot\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'The source and prepared-header roots must not overlap.'
}
if (!(Test-Path -LiteralPath $SourceRoot -PathType Container)) {
    throw "Missing post-MIDL source tree: $SourceRoot"
}

$recipeSha256 = Get-Sha256 $Recipe
$preparationSha256 = Get-Sha256 $PSCommandPath
$config = Get-Content -LiteralPath $Recipe -Raw | ConvertFrom-Json
if ($config.schemaVersion -ne 1 -or $config.sourceStage -ne 'post-midl') {
    throw 'Only schema 1 post-MIDL mirror recipes are supported; pre-MIDL patches require an explicit pinned MIDL closure.'
}
if (!$SdkPackageRoot) {
    $propsPath = "$repoRoot\obj\BuildTools\BuildTools.proj.nuget.g.props"
    if (!(Test-Path -LiteralPath $propsPath)) {
        throw 'Build BuildTools first to resolve the pinned SDK package.'
    }
    [xml]$props = Get-Content -LiteralPath $propsPath -Raw
    $SdkPackageRoot = $props.SelectSingleNode("//*[local-name()='PkgMicrosoft_Windows_SDK_CPP']").InnerText
}
$SdkPackageRoot = [IO.Path]::GetFullPath($SdkPackageRoot).TrimEnd('\')
Assert-OrdinaryPath $SdkPackageRoot
[xml]$nuspec = Get-Content -LiteralPath "$SdkPackageRoot\microsoft.windows.sdk.cpp.nuspec" -Raw
$version = $nuspec.SelectSingleNode("//*[local-name()='metadata']/*[local-name()='version']").InnerText
if ($version -ne $config.sdkPackageVersion) {
    throw "SDK package mismatch: expected $($config.sdkPackageVersion), found $version."
}

if ($config.sourceGitTree) {
    $expectedSource = [IO.Path]::GetFullPath("$repoRoot\generation\WinSDK\RecompiledIdlHeaders").TrimEnd('\')
    if ($SourceRoot -ne $expectedSource) {
        throw 'A Git-pinned mirror recipe must use this worktree''s RecompiledIdlHeaders.'
    }
    $tree = & git -C $repoRoot rev-parse 'HEAD:generation/WinSDK/RecompiledIdlHeaders'
    if ($LASTEXITCODE -ne 0 -or $tree -ne $config.sourceGitTree) {
        throw "Post-MIDL mirror Git identity does not match the recipe: $tree"
    }
    & git -C $repoRoot diff --quiet HEAD -- 'generation/WinSDK/RecompiledIdlHeaders'
    if ($LASTEXITCODE -ne 0) {
        throw 'The checked-in SDK mirror has local changes; prepare from the pinned bytes instead.'
    }
    $extra = & git -C $repoRoot ls-files --others --exclude-standard -- 'generation/WinSDK/RecompiledIdlHeaders'
    if ($LASTEXITCODE -ne 0 -or $extra) {
        throw 'The checked-in SDK mirror contains untracked files.'
    }
}

$recipeRoot = [IO.Path]::GetDirectoryName($Recipe)
$retainedHeaders = @()
foreach ($header in $config.headers) {
    $source = Resolve-Child $SourceRoot $header.path
    if ((Get-Sha256 $source) -ne $header.sourceSha256) {
        throw "Post-MIDL preimage mismatch: $($header.path)"
    }
    if ($null -ne $header.PSObject.Properties['sourceKind']) {
        if ($header.sourceKind -cne 'retained' -or
            [IO.Path]::GetExtension($header.path) -cne '.h' -or
            $null -ne $header.PSObject.Properties['sdkPath'] -or
            $null -ne $header.PSObject.Properties['sdkSha256'] -or
            $null -eq $header.PSObject.Properties['retentionReason'] -or
            [string]::IsNullOrWhiteSpace($header.retentionReason)) {
            throw "A retained header requires an explicit reason and source hash, without a selected SDK binding: $($header.path)"
        }
        $retainedHeaders += [pscustomobject]@{
            path = $header.path; sourceSha256 = $header.sourceSha256; retentionReason = $header.retentionReason
        }
    }
    else {
        $sdk = Resolve-Child $SdkPackageRoot $header.sdkPath
        if ((Get-Sha256 $sdk) -ne $header.sdkSha256) {
            throw "Selected SDK input mismatch: $($header.sdkPath)"
        }
    }
}
$midlInputs = @()
$midlTools = @()
$midlScripts = @()
$hasMidl = $null -ne $config.PSObject.Properties['midl']
if ($hasMidl) {
    $midlInputs = @($config.midl.inputs | ForEach-Object {
        if ([IO.Path]::GetExtension($_.path) -notin @('.idl', '.acf', '.h')) {
            throw "Unsupported MIDL input: $($_.path)"
        }
        Resolve-Child $SourceRoot $_.path | Out-Null
        if ($null -ne $_.PSObject.Properties['sourceSha256']) {
            if ($_.path -cne 'shared\win32metadata_annotations.h' -or
                $null -ne $_.PSObject.Properties['sdkPath'] -or $null -ne $_.PSObject.Properties['sdkSha256']) {
                throw 'Only the canonical repository annotation header may be a source-pinned MIDL input, without an SDK binding.'
            }
            $path = Resolve-Child $SourceRoot $_.path
            if ((Get-Sha256 $path) -ne $_.sourceSha256) {
                throw "Selected repository MIDL input mismatch: $($_.path)"
            }
            return [pscustomobject]@{
                path = $_.path; fullPath = $path; sdkPath = $null; sourceKind = 'repository'; sha256 = $_.sourceSha256
            }
        }
        $path = Resolve-Child $SdkPackageRoot $_.sdkPath
        if ((Get-Sha256 $path) -ne $_.sdkSha256) {
            throw "Selected SDK MIDL input mismatch: $($_.sdkPath)"
        }
        [pscustomobject]@{ path = $_.path; fullPath = $path; sdkPath = $_.sdkPath; sourceKind = 'sdk'; sha256 = $_.sdkSha256 }
    })
    if (!$midlInputs.Count -or @($midlInputs.path | Sort-Object -Unique).Count -ne $midlInputs.Count) {
        throw 'The MIDL input closure must be nonempty and contain no duplicate paths.'
    }
    foreach ($output in $config.midl.outputs) {
        $header = @($config.headers | Where-Object path -eq $output.path)
        $input = @($midlInputs | Where-Object path -eq $output.source)
        if ($header.Count -ne 1 -or $input.Count -ne 1 -or $input[0].sourceKind -ne 'sdk' -or
            [IO.Path]::GetExtension($output.source) -ne '.idl' -or
            $header[0].sdkPath -ne $input[0].sdkPath -or $header[0].sdkSha256 -ne $input[0].sha256) {
            throw "A MIDL output must bind one admitted header to its exact SDK IDL: $($output.path)"
        }
    }
    if (!$config.midl.outputs.Count -or
        @($config.midl.outputs.path | Sort-Object -Unique).Count -ne $config.midl.outputs.Count) {
        throw 'MIDL outputs must be nonempty and contain no duplicate headers.'
    }
    foreach ($header in $config.headers | Where-Object {
        $null -eq $_.PSObject.Properties['sourceKind'] -and
        [IO.Path]::GetExtension($_.sdkPath) -eq '.idl' -and $_.sdkPath -in $midlInputs.sdkPath
    }) {
        if (@($config.midl.outputs | Where-Object path -eq $header.path).Count -ne 1) {
            throw "A header in the admitted MIDL input closure must have one pinned MIDL output: $($header.path)"
        }
    }
    $midlTools = @($config.midl.tools | ForEach-Object {
        $path = Resolve-Child $SdkPackageRoot $_.sdkPath
        if ((Get-Sha256 $path) -ne $_.sha256) {
            throw "Selected SDK MIDL compiler mismatch: $($_.sdkPath)"
        }
        [pscustomobject]@{ path = $path; sha256 = $_.sha256 }
    })
    if (($midlTools.path | ForEach-Object { [IO.Path]::GetFileName($_) } | Sort-Object) -join ',' -ne 'midl.exe,midlc.exe' -or
        @($midlTools.path | ForEach-Object { [IO.Path]::GetDirectoryName($_) } | Sort-Object -Unique).Count -ne 1) {
        throw 'Pin both midl.exe and midlc.exe from the same selected SDK compiler directory.'
    }
    $midlCompiler = ($midlTools | Where-Object { [IO.Path]::GetFileName($_.path) -eq 'midl.exe' }).path
    if (!$MidlPreprocessorPath) {
        . "$PSScriptRoot\CommonUtils.ps1"
        $MidlPreprocessorPath = Join-Path (Get-VcDirPath -Arch x64 -HostArch x64) 'cl.exe'
    }
    $MidlPreprocessorPath = [IO.Path]::GetFullPath($MidlPreprocessorPath)
    Assert-OrdinaryPath $MidlPreprocessorPath
    if ([IO.Path]::GetFileName($MidlPreprocessorPath) -ne 'cl.exe') {
        throw 'The selected MIDL preprocessor must be cl.exe.'
    }
    $midlTools += @($MidlPreprocessorPath, (Join-Path ([IO.Path]::GetDirectoryName($MidlPreprocessorPath)) 'c1.dll')) |
        ForEach-Object { [pscustomobject]@{ path = $_; sha256 = Get-Sha256 $_ } }
    $midlScripts = @('MidlHeaderUtils.ps1', 'ConvertMidlAttributesToSalAnnotations.ps1') | ForEach-Object {
        [pscustomobject]@{ path = "$PSScriptRoot\$_"; sha256 = Get-Sha256 "$PSScriptRoot\$_" }
    }
}
$patchedArtifacts = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
$patches = @($config.patches | ForEach-Object {
    $path = Resolve-Child $recipeRoot $_
    if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Missing patch: $path"
    }
    $text = [IO.File]::ReadAllText($path)
    if ($text -match '(?m)^(?:old mode|new mode|new file mode|deleted file mode|rename |copy |GIT binary patch|(?:---|\+\+\+) /dev/null)') {
        throw "A header patch must not change file identity or mode: $_"
    }
    $fileHeaders = [regex]::Matches($text, '(?m)^(---|\+\+\+) ([^\r\n]+)')
    if ($fileHeaders.Count -ne 2) {
        throw "A patch must contain exactly one SDK artifact's old/new pair: $_"
    }
    $before = $fileHeaders[0]
    $after = $fileHeaders[1]
    if ($before.Groups[1].Value -ne '---' -or $after.Groups[1].Value -ne '+++' -or
        !$before.Groups[2].Value.StartsWith('a/', [StringComparison]::Ordinal) -or
        !$after.Groups[2].Value.StartsWith('b/', [StringComparison]::Ordinal)) {
        throw "Patch targets must be SDK-relative artifact paths: $_"
    }
    $oldPath = $before.Groups[2].Value.Substring(2)
    $newPath = $after.Groups[2].Value.Substring(2)
    if ($oldPath -cne $newPath) {
        throw "A patch must modify one admitted SDK artifact without changing its identity: $_"
    }
    $artifact = $newPath.Replace('/', '\')
    $input = @($midlInputs | Where-Object path -eq $artifact)
    $isIdl = $input.Count -eq 1 -and [IO.Path]::GetExtension($artifact) -eq '.idl'
    if ($isIdl) {
        $sdk = $input[0].fullPath
    }
    else {
        $headers = @($config.headers | Where-Object path -eq $artifact)
        if ($headers.Count -ne 1) {
            throw "A patch must target one admitted SDK artifact: $_"
        }
        $header = $headers[0]
        if ($artifact -in @($retainedHeaders | ForEach-Object path)) {
            $sdk = Resolve-Child $SourceRoot $header.path
            if ($input.Count) {
                throw "A retained compatibility header cannot substitute for a selected SDK MIDL input: $artifact"
            }
        }
        else {
            $sdk = Resolve-Child $SdkPackageRoot $header.sdkPath
            if ([IO.Path]::GetExtension($header.sdkPath) -eq '.idl' -or
                ($hasMidl -and $artifact -in $config.midl.outputs.path)) {
                throw "A regenerated header patch belongs before MIDL, on its admitted SDK IDL artifact: $_"
            }
            if ($header.sourceSha256 -ne $header.sdkSha256) {
                throw "A direct SDK header patch requires the pristine SDK preimage: $_"
            }
            if ($input.Count -eq 1 -and ($input[0].sourceKind -ne 'sdk' -or
                $input[0].fullPath -ne $sdk -or $input[0].sha256 -ne $header.sdkSha256)) {
                throw "A patched header shared with MIDL must bind the same pristine SDK input: $artifact"
            }
        }
    }
    if (!$sdk.EndsWith("\$artifact", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Patch target does not match its canonical SDK artifact: $_"
    }
    if (!$patchedArtifacts.Add($sdk)) {
        throw "An SDK artifact is patched more than once; consolidate its deltas into one patch: $artifact"
    }
    if ($_ -cne "$artifact.patch") {
        throw "A patch must be named after its SDK artifact: $artifact.patch"
    }
    $statistics = @(& git -C $repoRoot apply -p1 --numstat -- $path)
    if ($LASTEXITCODE -ne 0 -or $statistics.Count -ne 1) {
        throw "Invalid or empty patch: $_"
    }
    foreach ($statistic in $statistics) {
        if ($statistic -notmatch '^\d+\t\d+\t(.+)$' -or
            $Matches[1].Replace('/', '\') -cne $artifact) {
            throw "Patch changes a path other than its admitted SDK artifact: $statistic"
        }
    }
    [pscustomobject]@{
        path = $_; fullPath = $path; sha256 = Get-Sha256 $path; isIdl = $isIdl; isMidlInput = $input.Count -eq 1
    }
})
[IO.Directory]::CreateDirectory($OutputRoot) | Out-Null
$lock = [IO.File]::Open("$OutputRoot\prepare.lock", [IO.FileMode]::OpenOrCreate, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
$staging = $null
$publicationFailed = $false
try {
    $sourceState = Get-DirectoryState $SourceRoot
    $identity = Get-TextHash ($recipeSha256 + $preparationSha256 + $sourceState.sha256 +
        (($patches | ForEach-Object { "$($_.path):$($_.sha256)" }) -join "`n") +
        (($midlTools + $midlScripts | ForEach-Object { "$($_.path):$($_.sha256)" }) -join "`n"))
    $midlIdentity = $null
    if ($hasMidl) {
        $midlIdentity = Get-TextHash (([ordered]@{
            schemaVersion = 1
            sdkPackageVersion = $version
            preparationSha256 = $preparationSha256
            configuration = $config.midl
            patches = @($patches | Where-Object isMidlInput | Select-Object path, sha256)
            tools = $midlTools
            scripts = $midlScripts
        } | ConvertTo-Json -Depth 10 -Compress))
    }
    $destination = "$OutputRoot\$identity"
    $manifestPath = "$destination\manifest.json"
    Assert-OrdinaryPath $manifestPath
    Assert-OrdinaryPath "$destination\headers"
    if (Test-Path -LiteralPath $destination) {
        if (!(Test-Path -LiteralPath $manifestPath -PathType Leaf)) {
            throw "Incomplete published header cache: $destination"
        }
        $manifest = Get-Content -LiteralPath $manifestPath -Raw | ConvertFrom-Json
        $actual = Get-DirectoryState "$destination\headers"
        if ($manifest.identity -ne $identity -or $manifest.preparedSha256 -ne $actual.sha256) {
            throw "Published header cache was modified: $destination. Do not repair a tree that a scraper may be reading."
        }
        if ($hasMidl) {
            Assert-OrdinaryPath "$destination\midl"
            if ($manifest.midlSha256 -ne (Get-DirectoryState "$destination\midl").sha256) {
                throw "Published MIDL cache was modified: $destination."
            }
        }
        return [pscustomobject]@{
            IncludeRoot = "$destination\headers"; Manifest = $manifestPath; Identity = $identity
            Reused = $true; MidlReused = $hasMidl
        }
    }

    $staging = "$OutputRoot\staging-$([Guid]::NewGuid().ToString('N'))"
    [IO.Directory]::CreateDirectory("$staging\headers") | Out-Null
    foreach ($file in $sourceState.files) {
        $target = [IO.Path]::Combine("$staging\headers", $file.path)
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        [IO.File]::Copy([IO.Path]::Combine($SourceRoot, $file.path), $target)
    }
    if ((Get-DirectoryState "$staging\headers").sha256 -ne $sourceState.sha256) {
        throw 'The source header tree changed while it was being copied.'
    }
    foreach ($patch in @($patches | Where-Object { !$_.isIdl })) {
        Invoke-HeaderPatch $patch "$staging\headers"
    }
    $reusedMidl = $null
    if ($hasMidl) {
        $reusedMidl = Find-PreparedMidl $midlIdentity
        if ($reusedMidl) {
            Copy-Item -LiteralPath $reusedMidl.path -Destination "$staging\midl" -Recurse
            if ((Get-DirectoryState "$staging\midl").sha256 -ne $reusedMidl.sha256) {
                throw 'The published MIDL cache changed while it was being copied.'
            }
        }
        else {
            Invoke-PreparedMidl $staging
        }
        foreach ($output in $config.midl.outputs) {
            [IO.File]::Copy((Resolve-Child "$staging\midl\generated" $output.path),
                (Resolve-Child "$staging\headers" $output.path), $true)
        }
    }
    if ((Get-DirectoryState $SourceRoot).sha256 -ne $sourceState.sha256) {
        throw 'The source header tree changed during preparation.'
    }
    foreach ($input in $midlInputs) {
        if ((Get-Sha256 $input.fullPath) -ne $input.sha256) {
            throw "A pinned MIDL input changed during preparation: $($input.path)"
        }
    }
    foreach ($tool in @($midlTools + $midlScripts)) {
        if ((Get-Sha256 $tool.path) -ne $tool.sha256) {
            throw "A MIDL tool or SAL converter changed during preparation: $($tool.path)"
        }
    }
    foreach ($patch in $patches) {
        if ((Get-Sha256 $patch.fullPath) -ne $patch.sha256) {
            throw "A pinned SDK patch changed during preparation: $($patch.path)"
        }
    }
    if ((Get-Sha256 $Recipe) -ne $recipeSha256 -or (Get-Sha256 $PSCommandPath) -ne $preparationSha256) {
        throw 'The SDK recipe or preparation script changed during preparation.'
    }
    $prepared = Get-DirectoryState "$staging\headers"
    $manifest = [ordered]@{
        schemaVersion = 1
        identity = $identity
        sdkPackageVersion = $version
        sourceStage = $config.sourceStage
        sourceGitTree = $config.sourceGitTree
        sourceSha256 = $sourceState.sha256
        retainedHeaders = $retainedHeaders
        recipeSha256 = $recipeSha256
        preparationSha256 = $preparationSha256
        patches = @($patches | Select-Object path, sha256)
        preparedSha256 = $prepared.sha256
        files = $prepared.files
    }
    if ($hasMidl) {
        $manifest.midlIdentity = $midlIdentity
        $manifest.midlReusedFrom = if ($reusedMidl) { $reusedMidl.preparedIdentity } else { $null }
        $manifest.midlProducerIdentity = if ($reusedMidl) { $reusedMidl.producerIdentity } else { $identity }
        $manifest.midlInputs = @($midlInputs | Select-Object path, sourceKind, sdkPath, sha256)
        $manifest.midlTools = $midlTools
        $manifest.midlScripts = $midlScripts
        $manifest.midlSha256 = (Get-DirectoryState "$staging\midl").sha256
        $diagnostics = Get-Content -LiteralPath "$staging\midl\categorized-diagnostics.json" -Raw | ConvertFrom-Json
        $manifest.midlNonBlockingErrorCount = $diagnostics.count
        $manifest.midlNonBlockingErrorCounts = $diagnostics.counts
    }
    [IO.File]::WriteAllText("$staging\manifest.json", ($manifest | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
    try {
        [IO.Directory]::Move($staging, $destination)
    }
    catch {
        $publicationFailed = $true
        $publicationError = $_
        $failure = $_.Exception.GetBaseException()
        $diagnostic = [ordered]@{
            status = 'failed-unpublished'
            identity = $identity
            staging = $staging
            destination = $destination
            exceptionType = $failure.GetType().FullName
            hResult = '0x{0:X8}' -f $failure.HResult
            message = $failure.Message
            processId = $PID
            processCurrentDirectory = [Environment]::CurrentDirectory
            powerShellLocation = (Get-Location).Path
        }
        try {
            $diagnostic.sourceAttributes = [IO.File]::GetAttributes($staging).ToString()
            $diagnostic.parentAttributes = [IO.File]::GetAttributes($OutputRoot).ToString()
            $diagnostic.destinationExists = [IO.Directory]::Exists($destination)
            [IO.File]::WriteAllText("$staging\publication-failure.json",
                ($diagnostic | ConvertTo-Json -Depth 4), [Text.UTF8Encoding]::new($false))
        }
        catch {
            Write-Warning "Could not write atomic-publication diagnostics: $($_.Exception.Message)"
        }
        Write-Warning "Atomic publication failed ($($diagnostic.hResult)); unpublished diagnostic tree retained at $staging. It is not a valid prepared-header cache."
        throw $publicationError
    }
    $staging = $null
    [pscustomobject]@{
        IncludeRoot = "$destination\headers"; Manifest = $manifestPath; Identity = $identity
        Reused = $false; MidlReused = [bool]$reusedMidl
    }
}
finally {
    try {
        if ($staging -and !$publicationFailed -and (Test-Path -LiteralPath $staging)) {
            Remove-Item -LiteralPath $staging -Recurse -Force
        }
    }
    finally {
        $lock.Dispose()
    }
}
