#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$OwnerMap,
    [string[]]$DeclarationMaps = @(),
    [string[]]$Partition = @(),
    [string]$ToolsetInclude,
    [Parameter(Mandatory)]
    [string[]]$Original,
    [Parameter(Mandatory)]
    [string]$OutputDirectory,
    [switch]$Apply
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$repo = [IO.Path]::GetFullPath("$PSScriptRoot\..")
$sdk = "$repo\generation\WinSDK"
$mirror = "$sdk\RecompiledIdlHeaders"
$recipePath = "$sdk\patches\SdkHeaders.json"
$inventory = Get-Content -LiteralPath $OwnerMap -Raw | ConvertFrom-Json
$recipe = Get-Content -LiteralPath $recipePath -Raw | ConvertFrom-Json
if ($inventory.schemaVersion -ne 1 -or $recipe.sdkPackageVersion -ne $inventory.snapshot.sdkPackageVersion) {
    throw 'The owner inventory and selected SDK recipe must agree.'
}
$package = [IO.Path]::GetFullPath($inventory.snapshot.sdkPackageRoot)
$include = "$package\c\include\$($inventory.snapshot.sdkIncludeVersion)"
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory)
if (!$OutputDirectory.StartsWith("$repo\artifacts\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'Bulk authoring outputs must stay in this worktree''s artifacts directory.'
}
if (@($Original | Sort-Object -Unique).Count -ne $Original.Count) {
    throw 'Select each original owner only once.'
}
if (Test-Path -LiteralPath $OutputDirectory) {
    throw "Use a fresh output directory: $OutputDirectory"
}
[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
$osMacros = @{}
$annotationHeader = [IO.File]::ReadAllText("$mirror\shared\win32metadata_annotations.h")
foreach ($match in [regex]::Matches($annotationHeader,
    '(?m)^#define _WIN32META_OS_VERSION_(\w+)\s+"SupportedOSPlatform\(\\"([^"]+)\\"\)"')) {
    if (!$annotationHeader.Contains("#define _Win32_SupportedOS_$($match.Groups[1].Value)_ ")) {
        throw "The canonical version lacks a public annotation macro: $($match.Groups[1].Value)"
    }
    $osMacros[$match.Groups[2].Value] = "_Win32_SupportedOS_$($match.Groups[1].Value)_"
}
if (!$osMacros.Count) {
    throw 'The canonical SupportedOS macro table was not found.'
}
$parseFailures = [Collections.Generic.List[object]]::new()
if ($Partition.Count) {
    $scraper = "$repo\bin\Release\net10.0\win-x64\Win32MetadataScraper.dll"
    if (!(Test-Path -LiteralPath $scraper)) {
        throw 'Build Win32MetadataScraper in Release before exporting declaration maps.'
    }
    if (!$ToolsetInclude) {
        $vcBin = & "$PSScriptRoot\GetVcDirPath.ps1" -Arch x64 -HostArch x64
        $ToolsetInclude = [IO.Path]::GetFullPath("$vcBin\..\..\..\include")
    }
    if (!(Test-Path -LiteralPath "$ToolsetInclude\vcruntime.h")) {
        throw "Missing explicit MSVC include root: $ToolsetInclude"
    }
    $base = "$repo\sources\GeneratorSdk\tools\assets\scraper"
    $targets = @{ x86 = 'i686-pc-windows-msvc'; x64 = 'x86_64-pc-windows-msvc'; arm64 = 'aarch64-pc-windows-msvc' }
    foreach ($name in $Partition) {
        if ($name -notmatch '^[A-Za-z0-9_.-]+$' -or !(Test-Path -LiteralPath "$sdk\Partitions\$name\main.cpp")) {
            throw "Unknown SDK partition: $name"
        }
        $settingsPath = "$OutputDirectory\$name.settings.rsp"
        [IO.File]::WriteAllText($settingsPath,
            [IO.File]::ReadAllText("$sdk\Partitions\$name\settings.rsp").Replace('<IncludeRoot>', $mirror))
        foreach ($arch in @('x86', 'x64', 'arm64')) {
            $mapPath = "$OutputDirectory\$name.$arch.declarations.json"
            $rspPath = "$OutputDirectory\$name.$arch.rsp"
            $lines = @('--file', "$sdk\Partitions\$name\main.cpp", '--namespace', 'BulkMapping',
                '--output', "$OutputDirectory\unused.cs", '--declaration-map', $mapPath,
                '--include-directory', "$sdk\inc", "$mirror\shared", "$mirror\um", "$mirror\winrt",
                "$mirror\ucrt", $ToolsetInclude, "--additional=--target=$($targets[$arch])")
            [IO.File]::WriteAllLines($rspPath, $lines)
            $log = "$OutputDirectory\$name.$arch.log"
            & dotnet $scraper "$OutputDirectory\unused.remaps" "@$base\baseSettings.rsp" `
                "@$base\baseSettings.$arch.rsp" "@$settingsPath" "@$rspPath" *> $log
            if ($LASTEXITCODE -ne 0) {
                $parseFailures.Add([pscustomobject]@{ partition = $name; architecture = $arch; log = $log })
                Write-Warning "Declaration parse failed: $name/$arch; see $log"
            }
            else {
                $DeclarationMaps += $mapPath
            }
        }
    }
}
if (!$DeclarationMaps.Count) {
    throw 'No successful declaration maps were supplied or produced.'
}
$mapped = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::Ordinal)
$functionOwners = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::Ordinal)
foreach ($mapPath in $DeclarationMaps) {
    $map = Get-Content -LiteralPath $mapPath -Raw | ConvertFrom-Json
    if ($map.schemaVersion -ne 1) {
        throw "Unsupported declaration map: $mapPath"
    }
    foreach ($declaration in $map.declarations) {
        $relative = [IO.Path]::GetRelativePath($mirror, $declaration.file)
        if ($relative.StartsWith('..') -or [IO.Path]::IsPathRooted($relative)) {
            continue
        }
        $key = "$($relative.ToLowerInvariant())|$($declaration.name)"
        if (!$mapped.ContainsKey($key)) {
            $mapped[$key] = [Collections.Generic.List[object]]::new()
        }
        $mapped[$key].Add([pscustomobject]@{
            declaration = $declaration
            sha256 = $map.files.($declaration.file)
            partition = $map.partition
        })
        if ($declaration.qualifiedName -ceq $declaration.name) {
            if (!$functionOwners.ContainsKey($declaration.name)) {
                $functionOwners[$declaration.name] = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
            }
            $functionOwners[$declaration.name].Add($relative) | Out-Null
        }
    }
}
$rows = [Collections.Generic.List[object]]::new()
$patches = [Collections.Generic.List[object]]::new()
$remove = @{ supportedOS = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    setLastError = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal) }
$sidecars = @{ supportedOS = "$sdk\supportedOS.rsp"; setLastError = "$sdk\WithSetLastError.rsp" }
$sidecarLines = @{}
foreach ($category in $sidecars.Keys) {
    $sidecarLines[$category] = [IO.File]::ReadAllLines($sidecars[$category])
}

foreach ($owner in $Original) {
    if ([IO.Path]::IsPathRooted($owner) -or $owner.Split('\') -contains '..' -or
        [IO.Path]::GetExtension($owner) -ne '.h') {
        throw "An original must be an SDK-relative native header: $owner"
    }
    $candidates = @($inventory.readyOriginalOwners | Where-Object original -eq $owner)
    if ($candidates.Count -ne 1) {
        throw "Expected one explicitly available original owner: $owner"
    }
    if (@($recipe.patches | Where-Object { $_ -ieq "$owner.patch" }).Count -or
        (Test-Path -LiteralPath "$sdk\patches\$owner.patch")) {
        throw "An existing original patch must be coordinated, not overwritten: $owner"
    }
    $source = "$include\$owner"
    $mirrorPath = "$mirror\$owner"
    $before = [IO.File]::ReadAllBytes($source)
    $hash = (Get-FileHash -LiteralPath $source -Algorithm SHA256).Hash
    if ((Get-FileHash -LiteralPath $mirrorPath -Algorithm SHA256).Hash -ne $hash) {
        throw "The declaration map must bind the pristine selected-SDK bytes: $owner"
    }
    # Latin-1 is a byte-preserving view; annotation insertions are ASCII only.
    $text = [Text.Encoding]::Latin1.GetString($before)
    if ($text.Contains('File created by MIDL compiler')) {
        throw "Generated headers are not native authoring inputs: $owner"
    }
    $masked = [regex]::Replace($text, '(?s)/\*.*?\*/|//[^\r\n]*|"(?:\\.|[^"\\])*"|''(?:\\.|[^''\\])*''',
        { param($match) [regex]::Replace($match.Value, '[^\r\n]', ' ') })
    $eol = if ($text.Contains("`r`n")) { "`r`n" } else { "`n" }
    $insertions = @{}
    foreach ($category in @('supportedOS', 'setLastError')) {
        foreach ($fact in $candidates[0].$category) {
            $row = [ordered]@{ original = $owner; category = $category; symbol = $fact.symbol
                value = $fact.value; status = 'retained'; reason = ''; declarationCount = 0; annotationCount = 0 }
            if (@($sidecarLines[$category] | Where-Object { $_ -ceq $fact.value }).Count -ne 1) {
                throw "Expected one exact retained sidecar fact: $($fact.value)"
            }
            $key = "$($owner.ToLowerInvariant())|$($fact.symbol)"
            $locations = @(if ($mapped.ContainsKey($key)) { $mapped[$key].ToArray() })
            if (!$locations.Count) {
                $row.reason = 'no-parsed-declaration'
                $rows.Add([pscustomobject]$row)
                continue
            }
            $locations = @($locations | Group-Object { "$($_.declaration.file)|$($_.declaration.offset)|$($_.declaration.id)" } |
                ForEach-Object { $_.Group[0] })
            if (@($locations | ForEach-Object { $_.declaration.id } | Sort-Object -Unique).Count -ne 1) {
                $row.reason = 'ambiguous-declaration-identity'
                $rows.Add([pscustomobject]$row)
                continue
            }
            $macro = '_Win32_SetLastError_'
            if ($category -eq 'supportedOS') {
                if ($fact.value -notmatch '=SupportedOSPlatform\("([^"]+)"\)$' -or !$osMacros.ContainsKey($Matches[1])) {
                    throw "No canonical SupportedOS spelling for: $($fact.value)"
                }
                $macro = $osMacros[$Matches[1]]
            }
            $pending = [Collections.Generic.List[object]]::new()
            foreach ($location in $locations) {
                $decl = $location.declaration
                if ($location.sha256 -ne $hash) {
                    throw "Stale parsed source bytes: $owner"
                }
                if ($decl.kind -ne 'CXCursor_FunctionDecl' -or !$decl.id -or
                    $decl.qualifiedName -cne $fact.symbol -or $decl.isDefinition -or
                    $decl.file -ine $decl.spellingFile -or $decl.offset -ne $decl.spellingOffset -or
                    $decl.file -ine $decl.startFile -or $decl.file -ine $decl.endFile -or
                    $decl.start -gt $decl.offset -or $decl.end -le $decl.offset -or $decl.end -gt $text.Length -or
                    $text.Substring([int]$decl.offset, $fact.symbol.Length) -cne $fact.symbol) {
                    $row.reason = 'macro-definition-or-non-global-declaration'
                    continue
                }
                $lineStart = $text.LastIndexOf("`n", [int]$decl.start) + 1
                $prefix = $text.Substring($lineStart, [int]$decl.start - $lineStart)
                if ($prefix -notmatch '^[ \t]*$') {
                    $row.reason = 'declaration-start-shares-source-line'
                    continue
                }
                $pending.Add([pscustomobject]@{ offset = [int]$decl.start; macro = $macro; indent = $prefix })
            }
            $row.declarationCount = $locations.Count
            $occurrences = @([regex]::Matches($masked, '\b' + [regex]::Escape($fact.symbol) + '\s*\('))
            $boundOffsets = @($locations | ForEach-Object { [int]$_.declaration.offset })
            if (@($occurrences | Where-Object { $_.Index -notin $boundOffsets }).Count) {
                $row.reason = 'unparsed-declaration-or-reference'
            }
            if ($functionOwners.ContainsKey($fact.symbol) -and
                @($functionOwners[$fact.symbol] | Where-Object { $_ -ine $owner }).Count) {
                $row.reason = 'additional-declaration-owner'
            }
            if ($pending.Count -eq $locations.Count) {
                foreach ($insertion in $pending) {
                    if (!$insertions.ContainsKey($insertion.offset)) {
                        $insertions[$insertion.offset] = [Collections.Generic.SortedSet[string]]::new([StringComparer]::Ordinal)
                    }
                    $insertions[$insertion.offset].Add($insertion.macro) | Out-Null
                }
                $row.annotationCount = $pending.Count
                if (!$row.reason) {
                    if ($parseFailures.Count) {
                        $row.reason = 'incomplete-configuration-coverage'
                    }
                }
                if (!$row.reason) {
                    $row.status = 'converted'
                    $remove[$category].Add($fact.value) | Out-Null
                }
            }
            elseif (!$row.reason) {
                $row.reason = 'incomplete-declaration-coverage'
            }
            $rows.Add([pscustomobject]$row)
        }
    }
    if (!$insertions.Count) {
        continue
    }
    $after = $text
    foreach ($offset in @($insertions.Keys | Sort-Object -Descending)) {
        $lineStart = $text.LastIndexOf("`n", $offset) + 1
        $indent = $text.Substring($lineStart, $offset - $lineStart)
        $prefix = ($insertions[$offset] -join ($eol + $indent)) + $eol + $indent
        $after = $after.Insert($offset, $prefix)
    }
    $beforePath = "$OutputDirectory\before\$owner"
    $afterPath = "$OutputDirectory\after\$owner"
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($beforePath)) | Out-Null
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($afterPath)) | Out-Null
    [IO.File]::WriteAllBytes($beforePath, $before)
    [IO.File]::WriteAllBytes($afterPath, [Text.Encoding]::Latin1.GetBytes($after))
    $patchPath = "$OutputDirectory\patches\$owner.patch"
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($patchPath)) | Out-Null
    & git -c core.autocrlf=false --no-pager diff --no-index --no-ext-diff "--output=$patchPath" -- $beforePath $afterPath
    if ($LASTEXITCODE -ne 1) {
        throw "Expected a nonempty annotation-only diff: $owner"
    }
    $unixOwner = $owner.Replace('\', '/')
    $diff = [Text.Encoding]::Latin1.GetString([IO.File]::ReadAllBytes($patchPath))
    $diff = [regex]::Replace($diff, '\Adiff --git [^\n]*', "diff --git a/$unixOwner b/$unixOwner")
    $diff = [regex]::Replace($diff, '(?m)^--- [^\n]*', "--- a/$unixOwner")
    $diff = [regex]::Replace($diff, '(?m)^\+\+\+ [^\n]*', "+++ b/$unixOwner")
    [IO.File]::WriteAllBytes($patchPath, [Text.Encoding]::Latin1.GetBytes($diff))
    & git -C $repo apply --check --unsafe-paths -p1 "--directory=$include" --whitespace=error-all -- $patchPath
    if ($LASTEXITCODE -ne 0) {
        throw "Original SDK patch preflight failed: $owner"
    }
    $patches.Add([pscustomobject]@{ original = $owner; patch = $patchPath; sha256 = $hash })
}

$summary = [ordered]@{
    schemaVersion = 1
    applied = [bool]$Apply
    originals = @($patches.original)
    counts = [ordered]@{
        converted = @($rows | Where-Object status -eq 'converted').Count
        retained = @($rows | Where-Object status -eq 'retained').Count
        annotations = [int]($rows | Measure-Object annotationCount -Sum).Sum
        unknown = @($rows | Where-Object reason -eq 'no-parsed-declaration').Count
    }
    parseFailures = $parseFailures.ToArray()
    facts = $rows.ToArray()
}
if ($Apply) {
    foreach ($patch in $patches) {
        $target = "$sdk\patches\$($patch.original).patch"
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        [IO.File]::Copy($patch.patch, $target)
        $existing = @($recipe.headers | Where-Object path -eq $patch.original)
        if (!$existing.Count) {
            $recipe.headers += [pscustomobject]@{
                path = $patch.original; sourceSha256 = $patch.sha256
                sdkPath = "c\include\$($inventory.snapshot.sdkIncludeVersion)\$($patch.original)"
                sdkSha256 = $patch.sha256
            }
        }
        elseif ($existing.Count -ne 1 -or $existing[0].sourceSha256 -ne $patch.sha256 -or
            $existing[0].sdkSha256 -ne $patch.sha256) {
            throw "Existing header admission does not match the original bytes: $($patch.original)"
        }
        $recipe.patches += "$($patch.original).patch"
        $owner = @($inventory.readyOriginalOwners | Where-Object original -eq $patch.original)[0]
        foreach ($name in $owner.partitionCandidates) {
            if ($name -notin $recipe.partitions) {
                $recipe.partitions += $name
            }
            $settings = "$sdk\Partitions\$name\settings.rsp"
            $content = [IO.File]::ReadAllText($settings)
            if ($content -notmatch '(?m)^parse-win32-annotations\s*$') {
                $lineEnd = if ($content.Contains("`r`n")) { "`r`n" } else { "`n" }
                [IO.File]::WriteAllText($settings, $content.TrimEnd("`r", "`n") + $lineEnd +
                    '--config' + $lineEnd + 'parse-win32-annotations' + $lineEnd, [Text.UTF8Encoding]::new($false))
            }
        }
    }
    [IO.File]::WriteAllText($recipePath, ($recipe | ConvertTo-Json -Depth 20) + "`r`n", [Text.UTF8Encoding]::new($false))
    foreach ($category in $sidecars.Keys) {
        $originalText = [IO.File]::ReadAllText($sidecars[$category])
        $lineEnd = if ($originalText.Contains("`r`n")) { "`r`n" } else { "`n" }
        $kept = @($sidecarLines[$category] | Where-Object { !$remove[$category].Contains($_) })
        [IO.File]::WriteAllText($sidecars[$category], ($kept -join $lineEnd) + $lineEnd, [Text.UTF8Encoding]::new($false))
    }
}
[IO.File]::WriteAllText("$OutputDirectory\report.json", ($summary | ConvertTo-Json -Depth 12), [Text.UTF8Encoding]::new($false))
$summary.counts | ConvertTo-Json -Compress
