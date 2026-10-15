#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$Recipe,
    [string]$SourceRoot = "$PSScriptRoot\..\generation\WinSDK\RecompiledIdlHeaders",
    [string]$SdkPackageRoot,
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

$config = Get-Content -LiteralPath $Recipe -Raw | ConvertFrom-Json
if ($config.schemaVersion -ne 1 -or $config.sourceStage -ne 'post-midl') {
    throw 'Only schema 1 post-MIDL mirror recipes are supported. Apply pre-MIDL changes before compiling their IDL closure.'
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
foreach ($header in $config.headers) {
    $source = Resolve-Child $SourceRoot $header.path
    if ((Get-Sha256 $source) -ne $header.sourceSha256) {
        throw "Post-MIDL preimage mismatch: $($header.path)"
    }
    $sdk = Resolve-Child $SdkPackageRoot $header.sdkPath
    if ((Get-Sha256 $sdk) -ne $header.sdkSha256) {
        throw "Selected SDK input mismatch: $($header.sdkPath)"
    }
}
$patches = @($config.patches | ForEach-Object {
    if (!$_.StartsWith('post-midl\', [StringComparison]::Ordinal)) {
        throw "Patch is on the wrong side of the MIDL boundary: $_"
    }
    $path = Resolve-Child $recipeRoot $_
    if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Missing patch: $path"
    }
    $text = [IO.File]::ReadAllText($path)
    if ($text -match '(?m)^(?:old mode|new mode|new file mode|deleted file mode|rename |copy |GIT binary patch|(?:---|\+\+\+) /dev/null)') {
        throw "A header patch must not change file identity or mode: $_"
    }
    $fileHeaders = [regex]::Matches($text, '(?m)^(---|\+\+\+) ([^\r\n]+)')
    if (!$fileHeaders.Count -or $fileHeaders.Count % 2) {
        throw "A patch must contain complete old/new header pairs: $_"
    }
    for ($index = 0; $index -lt $fileHeaders.Count; $index += 2) {
        $before = $fileHeaders[$index]
        $after = $fileHeaders[$index + 1]
        $oldPrefix = 'a/generation/WinSDK/RecompiledIdlHeaders/'
        $newPrefix = 'b/generation/WinSDK/RecompiledIdlHeaders/'
        if ($before.Groups[1].Value -ne '---' -or $after.Groups[1].Value -ne '+++' -or
            !$before.Groups[2].Value.StartsWith($oldPrefix, [StringComparison]::Ordinal) -or
            !$after.Groups[2].Value.StartsWith($newPrefix, [StringComparison]::Ordinal)) {
            throw "Patch headers are not rooted in the admitted SDK mirror: $_"
        }
        $oldPath = $before.Groups[2].Value.Substring($oldPrefix.Length)
        $newPath = $after.Groups[2].Value.Substring($newPrefix.Length)
        if ($oldPath -cne $newPath -or $newPath.Replace('/', '\') -notin @($config.headers.path)) {
            throw "A patch must modify one admitted header without changing its identity: $_"
        }
    }
    $statistics = @(& git -C $repoRoot apply -p4 --numstat -- $path)
    if ($LASTEXITCODE -ne 0 -or !$statistics.Count) {
        throw "Invalid or empty patch: $_"
    }
    foreach ($statistic in $statistics) {
        if ($statistic -notmatch '^\d+\t\d+\t(.+)$' -or
            $Matches[1].Replace('/', '\') -notin @($config.headers.path)) {
            throw "Patch changes a path outside its reviewed header set: $statistic"
        }
    }
    [pscustomobject]@{ path = $_; fullPath = $path; sha256 = Get-Sha256 $path }
})
if (@($patches.path | Sort-Object -Unique).Count -ne $patches.Count) {
    throw 'A patch is listed more than once.'
}

[IO.Directory]::CreateDirectory($OutputRoot) | Out-Null
$lock = [IO.File]::Open("$OutputRoot\prepare.lock", [IO.FileMode]::OpenOrCreate, [IO.FileAccess]::ReadWrite, [IO.FileShare]::None)
$staging = $null
try {
    $sourceState = Get-DirectoryState $SourceRoot
    $identity = Get-TextHash ((Get-Sha256 $Recipe) + (Get-Sha256 $PSCommandPath) + $sourceState.sha256 +
        (($patches | ForEach-Object { "$($_.path):$($_.sha256)" }) -join "`n"))
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
        return [pscustomobject]@{ IncludeRoot = "$destination\headers"; Manifest = $manifestPath; Identity = $identity; Reused = $true }
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
    foreach ($patch in $patches) {
        $arguments = @('-C', $repoRoot, 'apply', '--unsafe-paths', '-p4', "--directory=$staging\headers", '--whitespace=error-all')
        $output = & git @arguments --check -- $patch.fullPath 2>&1
        if ($LASTEXITCODE -ne 0) {
            throw "Patch preflight failed for $($patch.path):`n$($output -join "`n")"
        }
        $output = & git @arguments -- $patch.fullPath 2>&1
        if ($LASTEXITCODE -ne 0) {
            throw "Patch failed for $($patch.path):`n$($output -join "`n")"
        }
    }
    if ((Get-DirectoryState $SourceRoot).sha256 -ne $sourceState.sha256) {
        throw 'The source header tree changed during preparation.'
    }
    $prepared = Get-DirectoryState "$staging\headers"
    $manifest = [ordered]@{
        schemaVersion = 1
        identity = $identity
        sdkPackageVersion = $version
        sourceStage = $config.sourceStage
        sourceGitTree = $config.sourceGitTree
        sourceSha256 = $sourceState.sha256
        recipeSha256 = Get-Sha256 $Recipe
        preparationSha256 = Get-Sha256 $PSCommandPath
        patches = @($patches | Select-Object path, sha256)
        preparedSha256 = $prepared.sha256
        files = $prepared.files
    }
    [IO.File]::WriteAllText("$staging\manifest.json", ($manifest | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
    [IO.Directory]::Move($staging, $destination)
    $staging = $null
    [pscustomobject]@{ IncludeRoot = "$destination\headers"; Manifest = $manifestPath; Identity = $identity; Reused = $false }
}
finally {
    if ($staging -and (Test-Path -LiteralPath $staging)) {
        Remove-Item -LiteralPath $staging -Recurse -Force
    }
    $lock.Dispose()
}
