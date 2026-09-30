param(
    [Parameter(Mandatory = $true)]
    [string]$OutputDir
)

$ErrorActionPreference = "Stop"
$version = "22.1.8"
$commit = "ca7933e47d3a3451d81e72ac174dcb5aa28b59d1"
$destination = Join-Path $OutputDir "clang-resource\$version"
$destinationHeader = Join-Path $destination "include\intrin.h"

if (Test-Path $destinationHeader) {
    Write-Host "Using staged Clang $version resource headers in $destination"
    return
}

$cache = Join-Path $env:TEMP "win32metadata-clang-$version-$commit"
$cacheHeader = Join-Path $cache "clang\lib\Headers\intrin.h"
if (!(Test-Path $cacheHeader)) {
    if (Test-Path $cache) {
        Remove-Item $cache -Recurse -Force
    }

    New-Item -ItemType Directory -Force -Path $cache | Out-Null
    git -C $cache init --quiet
    if ($LASTEXITCODE -ne 0) {
        throw "Failed to initialize the Clang resource-header cache."
    }
    git -C $cache config core.longpaths true
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
    if ($LASTEXITCODE -ne 0 -or !(Test-Path $cacheHeader)) {
        throw "llvm-project commit $commit did not provide the Clang $version resource headers."
    }
}

if (Test-Path $destination) {
    Remove-Item $destination -Recurse -Force
}
New-Item -ItemType Directory -Force -Path (Join-Path $destination "include") | Out-Null
Copy-Item (Join-Path $cache "clang\lib\Headers\*") (Join-Path $destination "include") -Recurse -Force
Copy-Item (Join-Path $cache "LICENSE.TXT") (Join-Path $destination "LICENSE.TXT") -Force

if (!(Test-Path $destinationHeader)) {
    throw "Failed to stage the Clang $version resource headers in '$destination'."
}
Write-Host "Staged Clang $version resource headers from llvm-project $commit in $destination"
