param(
    [Parameter(Mandatory = $true)]
    [string]$OutputDir
)

$ErrorActionPreference = "Stop"
. "$PSScriptRoot\ClangResourceManifest.ps1"

$version = $ClangResourceVersion
$commit = $ClangResourceCommit
$destination = Join-Path $OutputDir "clang-resource\$version"

if (Test-ClangResourceTree -Root $destination -RequirePackagedManifest) {
    Write-Host "Using staged Clang $version resource headers in $destination"
    return
}

$cache = Join-Path $env:TEMP "win32metadata-clang-$version-$commit"
$cacheIsValid = $false
if (Test-Path $cache) {
    $cacheHead = git -C $cache rev-parse HEAD 2>$null
    $cacheIsValid = $LASTEXITCODE -eq 0 -and
        $cacheHead -ceq $commit -and
        (Test-ClangResourceTree -Root $cache -HeaderDirectory "clang\lib\Headers")
}
if (!$cacheIsValid) {
    if (Test-Path $cache) {
        Remove-Item $cache -Recurse -Force
    }

    New-Item -ItemType Directory -Force -Path $cache | Out-Null
    git -C $cache init --quiet
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to initialize the Clang resource-header cache."
    }
    git -C $cache config core.longpaths true
    git -C $cache config core.autocrlf false
    git -C $cache remote add origin https://github.com/llvm/llvm-project
    git -C $cache sparse-checkout init --no-cone
    @(
        "/clang/lib/Headers/"
        "/LICENSE.TXT"
    ) | Set-Content (Join-Path $cache ".git\info\sparse-checkout")
    git -C $cache fetch --quiet --depth 1 --filter=blob:none origin $commit
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to fetch llvm-project commit $commit."
    }
    git -C $cache checkout --quiet --detach FETCH_HEAD
    if ($LASTEXITCODE -ne 0) {
        throw "llvm-project commit $commit did not provide the Clang $version resource headers."
    }
    Test-ClangResourceTree -Root $cache -HeaderDirectory "clang\lib\Headers" -ThrowOnError | Out-Null
}

$staging = "$destination.staging-$PID"
Remove-Item $staging -Recurse -Force -ErrorAction SilentlyContinue
New-Item -ItemType Directory -Force -Path (Join-Path $staging "include") | Out-Null
Copy-Item (Join-Path $cache "clang\lib\Headers\*") (Join-Path $staging "include") -Recurse -Force
Copy-Item (Join-Path $cache "LICENSE.TXT") (Join-Path $staging "LICENSE.TXT") -Force
Copy-Item $ClangResourceManifest (Join-Path $staging "manifest.tsv") -Force

try {
    Test-ClangResourceTree -Root $staging -RequirePackagedManifest -ThrowOnError | Out-Null
}
catch {
    Remove-Item $staging -Recurse -Force
    throw
}
if (Test-Path $destination) {
    Remove-Item $destination -Recurse -Force
}
Move-Item $staging $destination
Write-Host "Staged Clang $version resource headers from llvm-project $commit in $destination"
