param(
    [string]$OutputDir = (Join-Path $PSScriptRoot "..\bin\GeneratorSdk\tools\win-x64")
)

$ErrorActionPreference = "Stop"
$root = Resolve-Path (Join-Path $PSScriptRoot "..")
$manifest = Join-Path $root "tools\rust\Cargo.toml"
$targetDir = Join-Path $root "tools\rust\target\release"

cargo build --release --locked --manifest-path $manifest
if ($LASTEXITCODE -ne 0) {
    throw "Failed to build win32metadata-tools."
}

$tool = Join-Path $targetDir "win32metadata-tools.exe"
$libclangInfo = & $tool libclang
if ($LASTEXITCODE -ne 0) {
    throw "Failed to provision libclang."
}

$directoryLine = $libclangInfo | Where-Object { $_ -match "^Directory:\s+" } | Select-Object -First 1
if (!$directoryLine) {
    throw "win32metadata-tools did not report the libclang directory."
}

$libclangDir = ($directoryLine -replace "^Directory:\s+", "").Trim()
$libclang = Join-Path $libclangDir "libclang.dll"
if (!(Test-Path $libclang)) {
    throw "libclang.dll was not found at '$libclang'."
}

New-Item -ItemType Directory -Force -Path $OutputDir | Out-Null
Copy-Item $tool (Join-Path $OutputDir "win32metadata-tools.exe") -Force
Copy-Item $libclang (Join-Path $OutputDir "libclang.dll") -Force

Write-Host "Staged WinmdGenerator native tools in $OutputDir"
