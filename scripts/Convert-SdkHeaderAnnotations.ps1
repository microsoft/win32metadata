#Requires -Version 7.0

<#
.SYNOPSIS
Moves compiler-bound availability and last-error facts into original SDK header patches.
.DESCRIPTION
Declaration maps bind pristine selected-SDK bytes. Existing uniquely admitted patches
are strictly applied in isolation first; only unchanged native declaration spans are
eligible for further authoring. The result is one cumulative patch against the SDK
original. Unbound variants, changed spans and unsupported macro expansions retain
their exact sidecar facts. Changed headers include ordinary sal.h themselves.
#>

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
$patchWhitespace = 'core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol'
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
        $includeDirs = [Collections.Generic.List[string]]::new()
        $includeDirs.Add("$sdk\inc")
        $includeDirs.Add($ToolsetInclude)
        $defaults = @("$mirror\shared", "$mirror\um", "$mirror\winrt", "$mirror\ucrt")
        $traverse = $false
        foreach ($line in [IO.File]::ReadAllLines($settingsPath)) {
            $value = $line.Trim()
            if ($value.StartsWith('--')) {
                $traverse = $value -eq '--traverse'
            }
            elseif ($traverse -and $value -and !$value.StartsWith('#')) {
                $parent = [IO.Path]::GetDirectoryName($value.Replace('/', '\'))
                if ($parent -and $parent -notin $defaults -and $parent -notin $includeDirs) {
                    $includeDirs.Add($parent)
                }
            }
        }
        $includeDirs.AddRange([string[]]$defaults)
        foreach ($arch in @('x86', 'x64', 'arm64')) {
            $mapPath = "$OutputDirectory\$name.$arch.declarations.json"
            $rspPath = "$OutputDirectory\$name.$arch.rsp"
            $lines = @('--file', "$sdk\Partitions\$name\main.cpp", '--namespace', 'BulkMapping',
                '--output', "$OutputDirectory\unused.cs", '--declaration-map', $mapPath,
                '--include-directory') + $includeDirs.ToArray() + @("--additional=--target=$($targets[$arch])")
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
$wantedSymbols = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
foreach ($owner in $inventory.readyOriginalOwners | Where-Object original -in $Original) {
    foreach ($category in @('supportedOS', 'setLastError')) {
        foreach ($fact in $owner.$category) {
            $wantedSymbols.Add($fact.symbol) | Out-Null
        }
    }
}
$mapped = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::Ordinal)
$declarationOwners = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::Ordinal)
foreach ($mapPath in $DeclarationMaps) {
    $map = Get-Content -LiteralPath $mapPath -Raw | ConvertFrom-Json
    if ($map.schemaVersion -ne 1) {
        throw "Unsupported declaration map: $mapPath"
    }
    foreach ($declaration in $map.declarations) {
        if (!$wantedSymbols.Contains($declaration.name)) {
            continue
        }
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
        if ($declaration.qualifiedName -ceq $declaration.name -and
            ($declaration.kind -eq 'CXCursor_FunctionDecl' -or $declaration.isDefinition)) {
            if (!$declarationOwners.ContainsKey($declaration.name)) {
                $declarationOwners[$declaration.name] = [Collections.Generic.HashSet[string]]::new([StringComparer]::OrdinalIgnoreCase)
            }
            $declarationOwners[$declaration.name].Add($relative) | Out-Null
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

function Get-AuthoredOffset([int]$Offset, [Collections.Generic.List[int]]$Starts, [hashtable]$Lines) {
    $index = $Starts.BinarySearch($Offset)
    if ($index -lt 0) {
        $index = -$index - 2
    }
    if (!$Lines.ContainsKey($index)) {
        return -1
    }
    return [int]$Lines[$index] + $Offset - $Starts[$index]
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
    $existingPatch = "$sdk\patches\$owner.patch"
    $patchAdmissions = @($recipe.patches | Where-Object { $_ -ieq "$owner.patch" })
    $hasPatch = Test-Path -LiteralPath $existingPatch
    if ($patchAdmissions.Count -gt 1 -or [bool]$patchAdmissions.Count -ne $hasPatch) {
        throw "Existing patch and its unique recipe admission must agree: $owner"
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
    $authorText = $text
    $existingPatchHash = $null
    $lineMap = @{}
    $lineStarts = [Collections.Generic.List[int]]::new()
    $lineStarts.Add(0)
    foreach ($newline in [regex]::Matches($text, "`n")) {
        $lineStarts.Add($newline.Index + 1)
    }
    if ($hasPatch) {
        $admissions = @($recipe.headers | Where-Object path -eq $owner)
        if ($admissions.Count -ne 1 -or $admissions[0].sourceSha256 -ne $hash -or
            $admissions[0].sdkSha256 -ne $hash) {
            throw "Existing header admission does not match the original bytes: $owner"
        }
        $existingPatchHash = (Get-FileHash -LiteralPath $existingPatch -Algorithm SHA256).Hash
        $verified = "$OutputDirectory\existing"
        [IO.Directory]::CreateDirectory("$verified\$([IO.Path]::GetDirectoryName($owner))") | Out-Null
        [IO.File]::WriteAllBytes("$verified\$owner", $before)
        & git -C $verified init --quiet
        if ($LASTEXITCODE -ne 0) {
            throw "Cannot initialize isolated existing-patch verification: $owner"
        }
        $statistics = @(& git -C $verified apply --numstat -- $existingPatch)
        if ($LASTEXITCODE -ne 0 -or $statistics.Count -ne 1 -or
            ($statistics[0] -split "`t")[-1] -cne $owner.Replace('\', '/')) {
            throw "A cumulative owner patch must change only its admitted original: $owner"
        }
        & git -c $patchWhitespace -C $verified apply --whitespace=error-all -- $existingPatch
        if ($LASTEXITCODE -ne 0) {
            throw "Existing cumulative patch failed strict selected-SDK application: $owner"
        }
        $authorText = [Text.Encoding]::Latin1.GetString([IO.File]::ReadAllBytes("$verified\$owner"))
        $pristinePath = "$OutputDirectory\pristine\$owner"
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($pristinePath)) | Out-Null
        [IO.File]::WriteAllBytes($pristinePath, $before)
        $changes = @(& git -c core.autocrlf=false --no-pager diff --no-index --no-ext-diff --no-color --unified=0 -- $pristinePath "$verified\$owner")
        if ($LASTEXITCODE -ne 1) {
            throw "Expected a nonempty verified cumulative patch: $owner"
        }
        # Native map offsets survive only in byte-identical spans of the verified patch.
        $oldLines = [regex]::Split($text, '(?<=\n)')
        $newLines = [regex]::Split($authorText, '(?<=\n)')
        $newStarts = [Collections.Generic.List[int]]::new()
        $offset = 0
        foreach ($line in $newLines) {
            $newStarts.Add($offset)
            $offset += $line.Length
        }
        $oldLine = 0
        $newLine = 0
        foreach ($change in $changes) {
            if ($change -notmatch '^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@') {
                continue
            }
            $oldCount = if (!$Matches.ContainsKey(2)) { 1 } else { [int]$Matches[2] }
            $newCount = if (!$Matches.ContainsKey(4)) { 1 } else { [int]$Matches[4] }
            $oldStart = [int]$Matches[1] - [int]($oldCount -ne 0)
            $newStart = [int]$Matches[3] - [int]($newCount -ne 0)
            while ($oldLine -lt $oldStart) {
                if ($oldLines[$oldLine] -cne $newLines[$newLine]) {
                    throw "Existing patch line mapping is not byte-identical: $owner"
                }
                $lineMap[$oldLine++] = $newStarts[$newLine++]
            }
            if ($newLine -ne $newStart) {
                throw "Existing patch hunk coordinates are inconsistent: $owner"
            }
            $oldLine += $oldCount
            $newLine += $newCount
        }
        while ($oldLine -lt $oldLines.Count) {
            if ($newLine -ge $newLines.Count -or $oldLines[$oldLine] -cne $newLines[$newLine]) {
                throw "Existing patch tail mapping is not byte-identical: $owner"
            }
            $lineMap[$oldLine++] = $newStarts[$newLine++]
        }
    }
    else {
        for ($index = 0; $index -lt $lineStarts.Count; $index++) {
            $lineMap[$index] = $lineStarts[$index]
        }
    }
    $masked = [regex]::Replace($text, '(?s)/\*.*?\*/|//[^\r\n]*|"(?:\\.|[^"\\])*"|''(?:\\.|[^''\\])*''',
        { param($match) [regex]::Replace($match.Value, '[^\r\n]', ' ') })
    $eol = if ($text.Contains("`r`n")) { "`r`n" } else { "`n" }
    $insertions = @{}
    $recordNames = @{}
    $inlineOffsets = [Collections.Generic.HashSet[int]]::new()
    foreach ($category in @('supportedOS', 'setLastError')) {
        foreach ($fact in $candidates[0].$category) {
            $row = [ordered]@{ original = $owner; category = $category; symbol = $fact.symbol
                value = $fact.value; status = 'retained'; reason = ''; declarationCount = 0; annotationCount = 0 }
            if (@($sidecarLines[$category] | Where-Object { $_ -ceq $fact.value }).Count -ne 1) {
                throw "Expected one exact retained sidecar fact: $($fact.value)"
            }
            if (!$candidates[0].partitionCandidates.Count) {
                $row.reason = 'no-configured-owning-partition'
                $rows.Add([pscustomobject]$row)
                continue
            }
            $key = "$($owner.ToLowerInvariant())|$($fact.symbol)"
            $locations = @(if ($mapped.ContainsKey($key)) { $mapped[$key].ToArray() })
            if (!$locations.Count) {
                $row.reason = 'no-parsed-declaration'
                $rows.Add([pscustomobject]$row)
                continue
            }
            $recordDefinitions = @($locations | Where-Object {
                $_.declaration.kind -in @('CXCursor_StructDecl', 'CXCursor_ClassDecl') -and $_.declaration.isDefinition
            })
            if (@($locations | Where-Object sha256 -ne $hash).Count) {
                throw "Stale parsed source bytes: $owner"
            }
            $isRecord = $recordDefinitions.Count -gt 0
            $recordReferences = @()
            if ($isRecord) {
                if ($category -ne 'supportedOS' -or
                    @($locations | Where-Object { $_.declaration.kind -eq 'CXCursor_FunctionDecl' }).Count) {
                    $row.reason = 'record-requires-unambiguous-supportedOS-fact'
                    $rows.Add([pscustomobject]$row)
                    continue
                }
                $recordReferences = @($locations | Where-Object {
                    $_.declaration.kind -in @('CXCursor_StructDecl', 'CXCursor_ClassDecl') -and !$_.declaration.isDefinition
                })
                $locations = $recordDefinitions
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
                $nameOffset = [int]$decl.spellingOffset
                if ((!$isRecord -and ($decl.kind -ne 'CXCursor_FunctionDecl' -or $decl.isDefinition -or
                        $decl.offset -ne $decl.spellingOffset)) -or !$decl.id -or
                    $decl.qualifiedName -cne $fact.symbol -or
                    $decl.file -ine $decl.spellingFile -or
                    $decl.file -ine $decl.startFile -or $decl.file -ine $decl.endFile -or
                    $decl.start -gt $nameOffset -or $decl.end -le $nameOffset -or $decl.end -gt $text.Length -or
                    $nameOffset + $fact.symbol.Length -gt $text.Length -or
                    $text.Substring($nameOffset, $fact.symbol.Length) -cne $fact.symbol) {
                    $row.reason = 'macro-definition-or-non-global-declaration'
                    continue
                }
                $lineStart = $text.LastIndexOf("`n", [int]$decl.start) + 1
                $prefix = $text.Substring($lineStart, [int]$decl.start - $lineStart)
                $nativePrefix = $text.Substring([int]$decl.start, $nameOffset - [int]$decl.start)
                $returnMacro = !$isRecord -and $nativePrefix -cmatch
                    '^(?:WINOLEAPI|COMBASEAPI)(?:_[ \t]*\([A-Za-z_][A-Za-z_0-9 \t:*]*\))?[ \t\r\n]*$' -and
                    $masked.Substring($nameOffset + $fact.symbol.Length) -match '^\s*\('
                if (!$isRecord -and !$returnMacro) {
                    $returnType = [regex]::Match($decl.type, '^\s*(?:const\s+|volatile\s+)*([A-Za-z_]\w*)').Groups[1].Value
                    if (!$returnType -or $nativePrefix -cnotmatch ('\b' + [regex]::Escape($returnType) + '\b')) {
                        $row.reason = 'unsupported-function-declaration-macro'
                        continue
                    }
                }
                if (!$returnMacro -and $prefix -notmatch '^[ \t]*$' -and
                    ($isRecord -or $prefix -notmatch '^[ \t]*EXTERN_C[ \t]+$')) {
                    $row.reason = 'declaration-start-shares-source-line'
                    continue
                }
                if ($isRecord) {
                    $declarationPrefix = $masked.Substring([int]$decl.start, $nameOffset - [int]$decl.start)
                    if ($declarationPrefix -notmatch '^(?:struct|class|interface)\s+(?:(?:DX_DECLARE_INTERFACE|DWRITE_DECLARE_INTERFACE|DECLSPEC_UUID)\s*\([^)]*\)\s*)?$' -and
                        $declarationPrefix -notmatch '^(?:DECLARE_INTERFACE(?:_IID)?_|DECLARE_MAPI_INTERFACE_)\s*\(\s*$') {
                        $row.reason = 'unsupported-record-declaration-macro'
                        continue
                    }
                }
                $authoredStart = Get-AuthoredOffset ([int]$decl.start) $lineStarts $lineMap
                $authoredEnd = Get-AuthoredOffset ([int]$decl.end - 1) $lineStarts $lineMap
                $nativeLength = [int]$decl.end - [int]$decl.start
                if ($authoredStart -lt 0 -or $authoredEnd -lt 0 -or
                    $authoredEnd + 1 - $authoredStart -ne $nativeLength -or
                    $authorText.Substring($authoredStart, $nativeLength) -cne
                        $text.Substring([int]$decl.start, $nativeLength)) {
                    $row.reason = 'native-declaration-span-changed-by-existing-patch'
                    continue
                }
                $insertionOffset = if ($returnMacro) {
                    Get-AuthoredOffset $nameOffset $lineStarts $lineMap
                } else { $authoredStart }
                $pending.Add([pscustomobject]@{ offset = $insertionOffset; macro = $macro; indent = $prefix
                    inline = $returnMacro
                    recordTag = if ($decl.kind -eq 'CXCursor_ClassDecl') { 'class' } else { 'struct' } })
            }
            $row.declarationCount = $locations.Count
            $symbolPattern = [regex]::Escape($fact.symbol)
            $occurrences = if ($isRecord) {
                @([regex]::Matches($masked,
                    '\b[A-Za-z_]\w*\s*\(\s*(?<name>' + $symbolPattern + ')\b|' +
                    '\b(?:struct|class|interface)\s+(?:[A-Za-z_]\w*\s*\([^)]*\)\s*)*' +
                    '(?<name>' + $symbolPattern + ')\b(?:\s*:\s*[^;{]*)?\s*\{') |
                    ForEach-Object { [pscustomobject]@{ Index = $_.Groups['name'].Index } } |
                    Sort-Object Index -Unique)
            } else {
                @([regex]::Matches($masked, '\b' + $symbolPattern + '\s*\('))
            }
            $boundOffsets = @($locations | ForEach-Object {
                if ($isRecord) { [int]$_.declaration.spellingOffset } else { [int]$_.declaration.offset }
            })
            if ($isRecord) {
                $referenceOffsets = [Collections.Generic.HashSet[int]]::new()
                foreach ($reference in $recordReferences) {
                    $decl = $reference.declaration
                    if ($reference.sha256 -ne $hash) {
                        throw "Stale parsed source bytes: $owner"
                    }
                    $nameOffset = [int]$decl.spellingOffset
                    if ($decl.id -cne $locations[0].declaration.id -or
                        $decl.kind -ne $locations[0].declaration.kind -or $decl.qualifiedName -cne $fact.symbol -or
                        $decl.file -ine $decl.spellingFile -or
                        $decl.file -ine $decl.startFile -or $decl.file -ine $decl.endFile -or
                        $decl.start -lt 0 -or $decl.end -ne $decl.start -or $decl.start -gt $nameOffset -or
                        $nameOffset + $fact.symbol.Length -gt $text.Length) {
                        continue
                    }
                    $lineStart = $masked.LastIndexOf("`n", [int]$decl.start) + 1
                    if ($masked.Substring($lineStart, [int]$decl.start - $lineStart) -notmatch '^[ \t]*$' -or
                        $masked.Substring([int]$decl.start, $nameOffset - [int]$decl.start) -notmatch
                            '^DECLARE_MAPI_INTERFACE_PTR[ \t]*\([ \t]*$' -or
                        $masked.Substring($nameOffset) -cnotmatch
                            ('^' + $symbolPattern + '[ \t]*,[ \t]*[A-Za-z_]\w*[ \t]*\)[ \t]*;[ \t]*(?:\r?\n|$)')) {
                        continue
                    }
                    $referenceOffsets.Add($nameOffset) | Out-Null
                }
                $occurrences = @($occurrences | Where-Object { !$referenceOffsets.Contains($_.Index) })
            }
            if (@($occurrences | Where-Object { $_.Index -notin $boundOffsets }).Count) {
                $row.reason = 'unparsed-declaration-or-reference'
            }
            if ($isRecord -and @($occurrences).Count -ne $locations.Count) {
                $row.reason = 'incomplete-record-source-coverage'
            }
            if ($declarationOwners.ContainsKey($fact.symbol) -and
                @($declarationOwners[$fact.symbol] | Where-Object { $_ -ine $owner }).Count) {
                $row.reason = 'additional-declaration-owner'
            }
            if (!$row.reason -and $parseFailures.Count) {
                $row.reason = 'incomplete-configuration-coverage'
            }
            if ($pending.Count -eq $locations.Count -and !$row.reason) {
                foreach ($insertion in $pending) {
                    if (!$insertions.ContainsKey($insertion.offset)) {
                        $insertions[$insertion.offset] = [Collections.Generic.SortedSet[string]]::new([StringComparer]::Ordinal)
                    }
                    $insertions[$insertion.offset].Add($insertion.macro) | Out-Null
                    if ($insertion.inline) {
                        $inlineOffsets.Add($insertion.offset) | Out-Null
                    }
                    if ($isRecord) {
                        $recordNames[$insertion.offset] = [pscustomobject]@{ name = $fact.symbol; tag = $insertion.recordTag }
                    }
                }
                $row.annotationCount = $pending.Count
                $row.status = 'converted'
                $remove[$category].Add($fact.value) | Out-Null
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
    $after = $authorText
    foreach ($offset in @($insertions.Keys | Sort-Object -Descending)) {
        $lineStart = $authorText.LastIndexOf("`n", $offset) + 1
        $indent = $authorText.Substring($lineStart, $offset - $lineStart)
        $prefix = if ($recordNames.ContainsKey($offset)) {
            $record = $recordNames[$offset]
            '#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus)' + $eol + $indent +
                'typedef ' + ($insertions[$offset] -join ' ') + " $($record.tag) $($record.name) $($record.name);" + $eol + $indent +
                '#endif' + $eol + $indent
        } elseif ($inlineOffsets.Contains($offset) -or $indent -match '^[ \t]*EXTERN_C[ \t]+$') {
            ($insertions[$offset] -join ' ') + ' '
        } else {
            ($insertions[$offset] -join ($eol + $indent)) + $eol + $indent
        }
        $after = $after.Insert($offset, $prefix)
    }
    if ($after -notmatch '(?m)^\s*#include\s*[<"]sal\.h[>"]') {
        $guard = [regex]::Match($after, '(?m)^#ifndef[ \t]+(\w+)[ \t]*\r?\n#define[ \t]+\1[ \t]*\r?\n')
        $offset = if ($guard.Success) { $guard.Index + $guard.Length }
            elseif ($before.Length -ge 3 -and $before[0] -eq 239 -and $before[1] -eq 187 -and $before[2] -eq 191) { 3 }
            else { 0 }
        $after = $after.Insert($offset, "#include <sal.h>" + $eol)
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
    & git -c $patchWhitespace -C $repo apply --check --unsafe-paths -p1 "--directory=$include" --whitespace=error-all -- $patchPath
    if ($LASTEXITCODE -ne 0) {
        throw "Original SDK patch preflight failed: $owner"
    }
    $patches.Add([pscustomobject]@{ original = $owner; patch = $patchPath; sha256 = $hash
        existingPatchSha256 = $existingPatchHash
        authoredInputSha256 = [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData([Text.Encoding]::Latin1.GetBytes($authorText))) })
}

$summary = [ordered]@{
    schemaVersion = 1
    applied = [bool]$Apply
    originals = @($patches | ForEach-Object original)
    counts = [ordered]@{
        converted = @($rows | Where-Object status -eq 'converted').Count
        retained = @($rows | Where-Object status -eq 'retained').Count
        annotations = [int]($rows | Measure-Object annotationCount -Sum).Sum
        unknown = @($rows | Where-Object reason -eq 'no-parsed-declaration').Count
    }
    parseFailures = $parseFailures.ToArray()
    sourceBindings = @($patches | Select-Object original, sha256, existingPatchSha256, authoredInputSha256)
    facts = $rows.ToArray()
}
if ($Apply) {
    foreach ($patch in $patches) {
        $target = "$sdk\patches\$($patch.original).patch"
        if ($patch.existingPatchSha256 -and
            (Get-FileHash -LiteralPath $target -Algorithm SHA256).Hash -ne $patch.existingPatchSha256) {
            throw "Existing cumulative patch changed during authoring: $($patch.original)"
        }
        [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
        [IO.File]::Copy($patch.patch, $target, [bool]$patch.existingPatchSha256)
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
        if ("$($patch.original).patch" -notin $recipe.patches) {
            $recipe.patches += "$($patch.original).patch"
        }
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
