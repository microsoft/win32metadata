<#
.SYNOPSIS
    Copies the pristine SDK mirror and applies sorted post-MIDL patches, without MIDL rewriting.
.DESCRIPTION
    Only obj\RecompiledIdlHeaders is recreated. A content-verified tree is reused.
    When ToolPath is supplied, the preparation lock is held until generation finishes.
    VerifyOutput checks the recorded preparation and WinMD without repairing either.
#>
[CmdletBinding(PositionalBinding = $false)]
param(
    [string]$WinSdkRoot = "$PSScriptRoot\..\generation\WinSDK",
    [string]$ToolPath,
    [string]$VerifyOutput,
    [switch]$Clean,
    [string]$CleanObjectDirectory,
    [string]$CleanOutput,
    [ValidateRange(0, 86400)]
    [int]$LockTimeoutSeconds = 21600,
    [Parameter(ValueFromRemainingArguments = $true)]
    [string[]]$ToolArguments = @()
)

$ErrorActionPreference = "Stop"
$PSNativeCommandUseErrorActionPreference = $false
$sdkRoot = [System.IO.Path]::GetFullPath($WinSdkRoot)
$source = Join-Path $sdkRoot "RecompiledIdlHeaders"
$patches = Join-Path $sdkRoot "patches\post-midl"
$obj = Join-Path $sdkRoot "obj"
$destination = Join-Path $obj "RecompiledIdlHeaders"
$manifestPath = Join-Path $obj "windows-rs-headers.json"

function Assert-RegularDirectory {
    param([string]$Path)
    if (Test-Path -LiteralPath $Path) {
        $item = Get-Item -LiteralPath $Path -Force
        if (!$item.PSIsContainer -or ($item.Attributes -band [System.IO.FileAttributes]::ReparsePoint)) {
            throw "Expected a regular directory, not a file or reparse point: '$Path'."
        }
    }
}

function Get-TreeRecords {
    param([string]$Path, [string]$Filter = "*")
    Assert-RegularDirectory $Path
    if (!(Test-Path -LiteralPath $Path)) { return }
    $items = @(Get-ChildItem -LiteralPath $Path -Recurse -Force)
    foreach ($item in $items) {
        if ($item.Attributes -band [System.IO.FileAttributes]::ReparsePoint) {
            throw "Header preparation does not follow reparse points: '$($item.FullName)'."
        }
    }
    foreach ($file in ($items | Where-Object { !$_.PSIsContainer -and $_.Name -like $Filter } | Sort-Object FullName)) {
        [ordered]@{
            path = [System.IO.Path]::GetRelativePath($Path, $file.FullName)
            length = $file.Length
            sha256 = (Get-FileHash -LiteralPath $file.FullName -Algorithm SHA256).Hash
        }
    }
}

function Get-RecordsHash {
    param([object[]]$Records)
    $text = ConvertTo-Json -InputObject @($Records) -Depth 8 -Compress
    return [Convert]::ToHexString([System.Security.Cryptography.SHA256]::HashData(
        [System.Text.Encoding]::UTF8.GetBytes($text)))
}

function Get-ArgumentValues {
    param([string[]]$Arguments, [string]$Name)
    for ($i = 0; $i -lt $Arguments.Count; $i++) {
        if ($Arguments[$i] -ceq $Name) {
            if (++$i -ge $Arguments.Count) { throw "Missing value for '$Name'." }
            $Arguments[$i]
        }
    }
}

if ($VerifyOutput -and ($ToolPath -or $ToolArguments.Count)) {
    throw "-VerifyOutput cannot be combined with a tool invocation."
}
if ($Clean -and ($VerifyOutput -or $ToolPath -or $ToolArguments.Count)) {
    throw "-Clean cannot be combined with verification or generation."
}
if ($Clean) {
    if (!$CleanObjectDirectory -or !$CleanOutput) { throw "-Clean requires -CleanObjectDirectory and -CleanOutput." }
    $CleanObjectDirectory = [System.IO.Path]::GetFullPath($CleanObjectDirectory)
    $CleanOutput = [System.IO.Path]::GetFullPath($CleanOutput)
    if (!$CleanObjectDirectory.StartsWith("$obj\", [StringComparison]::OrdinalIgnoreCase) -or
        $CleanObjectDirectory -ieq $destination -or
        $CleanObjectDirectory.StartsWith("$destination\", [StringComparison]::OrdinalIgnoreCase) -or
        $destination.StartsWith("$CleanObjectDirectory\", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Clean object directory must be a separate generated child of '$obj', not '$CleanObjectDirectory'."
    }
}
elseif ($CleanObjectDirectory -or $CleanOutput) {
    throw "Clean paths require -Clean."
}
if ($ToolArguments.Count -and !$ToolPath) { throw "Tool arguments require -ToolPath." }
if ($ToolPath -and ($ToolArguments.Count -eq 0 -or $ToolArguments[0] -cne "scrape")) {
    throw "Header preparation wraps the scrape command only."
}
foreach ($directory in @($sdkRoot, $source, $obj, $destination, (Split-Path $patches), $patches)) {
    Assert-RegularDirectory $directory
}
if (!(Test-Path -LiteralPath $source -PathType Container)) {
    throw "Checked-in pristine SDK mirror is missing: '$source'."
}
if ($ToolPath) {
    $ToolPath = (Resolve-Path -LiteralPath $ToolPath).ProviderPath
    $includes = @(Get-ArgumentValues $ToolArguments "--include")
    if (!$includes.Count -or [System.IO.Path]::GetFullPath($includes[0]) -ine $destination) {
        throw "The first include root must be the prepared tree '$destination'."
    }
}
New-Item -ItemType Directory -Path $obj -Force | Out-Null
$lock = $null
$timer = [System.Diagnostics.Stopwatch]::StartNew()
try {
    while (!$lock) {
        try {
            $lock = [System.IO.File]::Open((Join-Path $obj "windows-rs-headers.lock"),
                [System.IO.FileMode]::OpenOrCreate, [System.IO.FileAccess]::ReadWrite, [System.IO.FileShare]::None)
        }
        catch [System.IO.IOException] {
            if (($_.Exception.HResult -band 0xffff) -notin @(32, 33)) { throw }
            if ($timer.Elapsed.TotalSeconds -ge $LockTimeoutSeconds) {
                throw "Timed out waiting for header preparation/generation to release '$destination'."
            }
            if ($timer.Elapsed.TotalSeconds -lt 0.2) {
                Write-Host "Waiting for the header preparation/generation lock: $destination"
            }
            Start-Sleep -Milliseconds 200
        }
    }

    if ($Clean) {
        foreach ($directory in @($destination, $CleanObjectDirectory)) {
            Get-TreeRecords $directory | Out-Null
        }
        foreach ($directory in @($destination, $CleanObjectDirectory)) {
            if (Test-Path -LiteralPath $directory) { Remove-Item -LiteralPath $directory -Recurse -Force }
        }
        foreach ($file in @($manifestPath, $CleanOutput, "$CleanOutput.provenance.json")) {
            if (Test-Path -LiteralPath $file -PathType Leaf) { Remove-Item -LiteralPath $file -Force }
        }
        Write-Host "Cleaned generated headers, native objects and '$CleanOutput'."
        return
    }

    $sourceFiles = @(Get-TreeRecords $source)
    if (!$sourceFiles.Count) { throw "Pristine SDK mirror is empty: '$source'." }
    $patchFiles = @(Get-TreeRecords $patches "*.patch")
    $recipe = @(
        foreach ($script in @($PSCommandPath, (Join-Path $PSScriptRoot "ApplySDKPatches.ps1"))) {
            [ordered]@{ path = [System.IO.Path]::GetFileName($script); sha256 = (Get-FileHash -LiteralPath $script).Hash }
        }
    )
    $inputs = [ordered]@{ source = $sourceFiles; patches = $patchFiles; recipe = $recipe }
    $inputHash = Get-RecordsHash @($inputs)
    $preparedFiles = @(Get-TreeRecords $destination)
    $manifest = if (Test-Path -LiteralPath $manifestPath) {
        Get-Content -LiteralPath $manifestPath -Raw | ConvertFrom-Json -AsHashtable
    }
    $reuse = $manifest -and $manifest.schema -eq 1 -and
        $manifest.sourceRoot -ieq $source -and $manifest.preparedRoot -ieq $destination -and
        $manifest.inputSha256 -ceq $inputHash -and
        $manifest.preparedSha256 -ceq (Get-RecordsHash $preparedFiles)
    if (!$reuse) {
        if ($VerifyOutput) { throw "Prepared header provenance is missing or stale: '$manifestPath'." }
        if (Test-Path -LiteralPath $manifestPath) { Remove-Item -LiteralPath $manifestPath -Force }
        # This fixed, validated child is the only directory owned by preparation.
        if (Test-Path -LiteralPath $destination) { Remove-Item -LiteralPath $destination -Recurse -Force }
        New-Item -ItemType Directory -Path $destination | Out-Null
        Get-ChildItem -LiteralPath $source -Force | Copy-Item -Destination $destination -Recurse -Force
        & "$PSScriptRoot\ApplySDKPatches.ps1" -Phase post-midl -WinSdkRoot $sdkRoot
        if ((Get-RecordsHash @([ordered]@{
            source = @(Get-TreeRecords $source)
            patches = @(Get-TreeRecords $patches "*.patch")
            recipe = $recipe
        })) -cne $inputHash) {
            throw "Source headers or patches changed during preparation. No reusable manifest was written."
        }
        $preparedFiles = @(Get-TreeRecords $destination)
        $manifest = [ordered]@{
            schema = 1
            sourceRoot = $source
            preparedRoot = $destination
            patchCount = $patchFiles.Count
            inputSha256 = $inputHash
            preparedSha256 = Get-RecordsHash $preparedFiles
            inputs = $inputs
            prepared = $preparedFiles
        }
        $manifest | ConvertTo-Json -Depth 12 | Set-Content -LiteralPath $manifestPath -Encoding utf8
        Write-Host "Prepared $($preparedFiles.Count) headers/files with $($patchFiles.Count) post-MIDL patches: $destination"
    }
    else {
        Write-Host "Reusing verified headers ($($patchFiles.Count) post-MIDL patches): $destination"
    }

    if ($ToolPath) {
        $outputs = @(Get-ArgumentValues $ToolArguments "--output")
        if ($outputs.Count -gt 1) { throw "Expected at most one --output argument." }
        $output = if ($outputs.Count) { [System.IO.Path]::GetFullPath($outputs[0]) }
        $receiptPath = if ($output) { "$output.provenance.json" }
        if ($receiptPath -and (Test-Path -LiteralPath $receiptPath)) {
            Remove-Item -LiteralPath $receiptPath -Force
        }
        if ($output -and (Test-Path -LiteralPath $output -PathType Leaf)) {
            Remove-Item -LiteralPath $output -Force
        }
        $toolHash = (Get-FileHash -LiteralPath $ToolPath).Hash
        $preparationHash = (Get-FileHash -LiteralPath $manifestPath).Hash
        & $ToolPath @ToolArguments
        if ($LASTEXITCODE -ne 0) {
            $nativeExitCode = $LASTEXITCODE
            Write-Error "windows-rs generation failed with exit code $nativeExitCode." -ErrorAction Continue
            exit $nativeExitCode
        }
        if ($output) {
            if (!(Test-Path -LiteralPath $output -PathType Leaf)) { throw "Generator did not produce '$output'." }
            if ((Get-RecordsHash @(Get-TreeRecords $destination)) -cne $manifest.preparedSha256) {
                throw "Prepared headers changed during generation; no output provenance was written."
            }
            [ordered]@{
                schema = 1
                output = $output
                outputSha256 = (Get-FileHash -LiteralPath $output).Hash
                tool = $ToolPath
                toolSha256 = $toolHash
                preparation = $manifestPath
                preparationSha256 = $preparationHash
                arguments = $ToolArguments
            } | ConvertTo-Json -Depth 8 | Set-Content -LiteralPath $receiptPath -Encoding utf8
        }
    }
    if ($VerifyOutput) {
        $output = [System.IO.Path]::GetFullPath($VerifyOutput)
        $receipt = Get-Content -LiteralPath "$output.provenance.json" -Raw | ConvertFrom-Json
        $includes = @(Get-ArgumentValues $receipt.arguments "--include")
        if ($receipt.schema -ne 1 -or $receipt.output -ine $output -or
            $receipt.outputSha256 -cne (Get-FileHash -LiteralPath $output).Hash -or
            $receipt.preparation -ine $manifestPath -or
            $receipt.preparationSha256 -cne (Get-FileHash -LiteralPath $manifestPath).Hash -or
            $receipt.toolSha256 -cne (Get-FileHash -LiteralPath $receipt.tool).Hash -or
            !$includes.Count -or [System.IO.Path]::GetFullPath($includes[0]) -ine $destination) {
            throw "Generation provenance does not match the prepared inputs/tool/output: '$output'."
        }
        Write-Host "Verified generated output $output ($($receipt.outputSha256)); patch count: $($manifest.patchCount)."
    }
}
finally {
    if ($lock) { $lock.Dispose() }
}
