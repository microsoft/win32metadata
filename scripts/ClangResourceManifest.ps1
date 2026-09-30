$ClangResourceVersion = "22.1.8"
$ClangResourceCommit = "ca7933e47d3a3451d81e72ac174dcb5aa28b59d1"
$ClangResourceManifest = Join-Path $PSScriptRoot "..\tools\rust\src\clang-resource-manifest.tsv"

function Get-ClangResourceManifestEntries {
    $lines = [System.IO.File]::ReadAllLines((Resolve-Path $ClangResourceManifest))
    if ($lines[0] -cne "# version`t$ClangResourceVersion" -or
        $lines[1] -cne "# llvm-project-commit`t$ClangResourceCommit" -or
        $lines[2] -cne "# sha256`tsize`tpath") {
        throw "The Clang resource manifest metadata does not match the pinned version and commit."
    }

    return @($lines[3..($lines.Length - 1)] | ForEach-Object {
        $fields = $_ -split "`t", 3
        if ($fields.Count -ne 3 -or $fields[0] -notmatch "^[0-9A-F]{64}$") {
            throw "Invalid Clang resource manifest entry: $_"
        }
        [pscustomobject]@{
            Hash = $fields[0]
            Size = [long]$fields[1]
            Path = $fields[2]
        }
    })
}

function Test-ClangResourceTree {
    param(
        [Parameter(Mandatory = $true)]
        [string]$Root,
        [string]$HeaderDirectory = "include",
        [switch]$RequirePackagedManifest
    )

    if (!(Test-Path $Root -PathType Container)) {
        return $false
    }

    if ($RequirePackagedManifest) {
        $packagedManifest = Join-Path $Root "manifest.tsv"
        if (!(Test-Path $packagedManifest -PathType Leaf) -or
            (Get-FileHash $packagedManifest -Algorithm SHA256).Hash -cne
                (Get-FileHash $ClangResourceManifest -Algorithm SHA256).Hash) {
            return $false
        }
    }

    $entries = Get-ClangResourceManifestEntries
    $resolvedRoot = (Resolve-Path $Root).Path
    $resolvedHeaders = Join-Path $resolvedRoot $HeaderDirectory
    if (!(Test-Path $resolvedHeaders -PathType Container) -or
        !(Test-Path (Join-Path $resolvedRoot "LICENSE.TXT") -PathType Leaf)) {
        return $false
    }
    if ($RequirePackagedManifest) {
        $actualPaths = @(Get-ChildItem $resolvedRoot -File -Recurse |
            Where-Object { $_.FullName -cne (Join-Path $resolvedRoot "manifest.tsv") } |
            ForEach-Object { $_.FullName.Substring($resolvedRoot.Length + 1).Replace("\", "/") })
    }
    else {
        $actualPaths = @(Get-ChildItem $resolvedHeaders -File -Recurse |
            ForEach-Object { $_.FullName.Substring($resolvedRoot.Length + 1).Replace("\", "/") })
        $actualPaths += "LICENSE.TXT"
    }
    $expectedPaths = @($entries | ForEach-Object {
        if ($_.Path.StartsWith("include/")) {
            "$($HeaderDirectory.Replace('\', '/').TrimEnd('/'))/$($_.Path.Substring(8))"
        }
        else {
            $_.Path
        }
    })
    if (@(Compare-Object $expectedPaths $actualPaths -CaseSensitive).Count -ne 0) {
        return $false
    }

    foreach ($entry in $entries) {
        $relativePath = if ($entry.Path.StartsWith("include/")) {
            Join-Path $HeaderDirectory $entry.Path.Substring(8)
        }
        else {
            $entry.Path
        }
        $file = Join-Path $Root $relativePath
        if (!(Test-Path $file -PathType Leaf) -or
            (Get-Item $file).Length -ne $entry.Size -or
            (Get-FileHash $file -Algorithm SHA256).Hash -cne $entry.Hash) {
            return $false
        }
    }

    return $true
}
