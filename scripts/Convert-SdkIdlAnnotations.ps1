#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$InputMap,
    [Parameter(Mandatory)][string]$SdkIncludeRoot,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string[]]$Original,
    [string]$SdkProjectRoot = "$PSScriptRoot\..\generation\WinSDK",
    [switch]$Apply,
    [string]$AnnotationHeader = "$PSScriptRoot\..\generation\WinSDK\RecompiledIdlHeaders\shared\win32metadata_annotations.h"
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$SdkIncludeRoot = [IO.Path]::GetFullPath($SdkIncludeRoot).TrimEnd('\')
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\')
$SdkProjectRoot = [IO.Path]::GetFullPath($SdkProjectRoot).TrimEnd('\')
if ($OutputDirectory -eq $SdkIncludeRoot -or
    $OutputDirectory.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SdkIncludeRoot.StartsWith("$OutputDirectory\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'IDL authoring output must not overlap the installed SDK.'
}
if ($SdkProjectRoot -eq $SdkIncludeRoot -or
    $SdkProjectRoot.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SdkIncludeRoot.StartsWith("$SdkProjectRoot\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'Parser activation must not modify the installed SDK.'
}
if (Test-Path -LiteralPath $OutputDirectory) {
    throw "Use a new output directory; do not overwrite an existing authoring result: $OutputDirectory"
}

function Resolve-Input([string]$Relative) {
    if ([IO.Path]::IsPathRooted($Relative) -or [IO.Path]::GetExtension($Relative) -ne '.idl') {
        throw "An original owner must be an SDK-relative shipped IDL: $Relative"
    }
    $path = [IO.Path]::GetFullPath([IO.Path]::Combine($SdkIncludeRoot, $Relative))
    if (!$path.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase)) {
        throw "Original IDL escapes the SDK include root: $Relative"
    }
    if (!(Test-Path -LiteralPath $path -PathType Leaf)) {
        throw "Missing original shipped IDL: $Relative"
    }
    $path
}

function Get-Hash([byte[]]$Bytes) {
    [Convert]::ToHexString([Security.Cryptography.SHA256]::HashData($Bytes))
}

function Get-CodeMask([string]$Text) {
    [regex]::Replace($Text, '(?s)/\*.*?\*/|//[^\r\n]*|"(?:\\.|[^"\\])*"|''(?:\\.|[^''\\])*''', {
        param($match)
        [regex]::Replace($match.Value, '[^\r\n]', ' ')
    })
}

function Get-AttributeStart([string]$Mask, [int]$Offset, [Collections.Generic.HashSet[string]]$AttributeMacros) {
    $start = $Offset
    while ($true) {
        $cursor = $start - 1
        while ($cursor -ge 0 -and [char]::IsWhiteSpace($Mask[$cursor])) { $cursor-- }
        if ($cursor -lt 0 -or $Mask[$cursor] -notin @(']', ')')) { break }
        $close = $Mask[$cursor]
        $open = if ($close -eq ']') { '[' } else { '(' }
        $depth = 1
        $cursor--
        while ($cursor -ge 0 -and $depth -gt 0) {
            if ($Mask[$cursor] -eq $close) { $depth++ }
            if ($Mask[$cursor] -eq $open) { $depth-- }
            $cursor--
        }
        if ($depth -ne 0) { throw "Unbalanced IDL attributes before byte $Offset" }
        if ($close -eq ')') {
            while ($cursor -ge 0 -and [char]::IsWhiteSpace($Mask[$cursor])) { $cursor-- }
            $end = $cursor + 1
            while ($cursor -ge 0 -and $Mask[$cursor] -match '[A-Za-z_0-9]') { $cursor-- }
            if (!$AttributeMacros.Contains($Mask.Substring($cursor + 1, $end - $cursor - 1))) { break }
        }
        $start = $cursor + 1
    }
    $line = $Mask.LastIndexOf("`n", [Math]::Max(0, $start - 1)) + 1
    if ($Mask.Substring($line, $start - $line).Trim().Length -eq 0) { return $line }
    $start
}

function Write-Patch([string]$Before, [string]$After, [string]$Relative, [string]$Destination) {
    $start = [Diagnostics.ProcessStartInfo]::new('git')
    $start.UseShellExecute = $false
    $start.RedirectStandardOutput = $true
    $start.RedirectStandardError = $true
    foreach ($argument in @('-c', 'core.autocrlf=false', 'diff', '--no-index', '--no-ext-diff', '--no-color', '--', $Before, $After)) {
        $start.ArgumentList.Add($argument)
    }
    $process = [Diagnostics.Process]::Start($start)
    $errorTask = $process.StandardError.ReadToEndAsync()
    $bytes = [IO.MemoryStream]::new()
    $process.StandardOutput.BaseStream.CopyTo($bytes)
    $process.WaitForExit()
    if ($process.ExitCode -ne 1) {
        throw "Expected a nonempty original-IDL diff (exit $($process.ExitCode)): $($errorTask.GetAwaiter().GetResult())"
    }
    $target = $Relative.Replace('\', '/')
    $patch = [Text.Encoding]::Latin1.GetString($bytes.ToArray())
    $patch = [regex]::Replace($patch, '(?m)^diff --git [^\r\n]+', "diff --git a/$target b/$target")
    $patch = [regex]::Replace($patch, '(?m)^--- [^\r\n]+', "--- a/$target")
    $patch = [regex]::Replace($patch, '(?m)^\+\+\+ [^\r\n]+', "+++ b/$target")
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($Destination)) | Out-Null
    [IO.File]::WriteAllBytes($Destination, [Text.Encoding]::Latin1.GetBytes($patch))
    $process.Dispose()
    $bytes.Dispose()
}

function Get-RspValues([string]$Text, [string]$Option) {
    $active = $false
    foreach ($line in [regex]::Split($Text, '\r\n|\n|\r')) {
        $value = $line.Trim().TrimStart([char]0xFEFF)
        if ($value.StartsWith('--', [StringComparison]::Ordinal)) {
            $active = $value -ceq $Option
        }
        elseif ($active -and $value -and !$value.StartsWith('#', [StringComparison]::Ordinal)) {
            $value
        }
    }
}

$map = Get-Content -LiteralPath $InputMap -Raw | ConvertFrom-Json
if ($map.schemaVersion -ne 1 -or $null -eq $map.PSObject.Properties['owners']) {
    throw 'Expected schema 1 with an explicit reserved owners array.'
}
$owners = @($map.owners | Where-Object { !$Original -or $_.original -in $Original })
if (!$owners.Count -or ($Original -and @($Original | Where-Object { $_ -notin $owners.original }).Count)) {
    throw 'The requested original IDL owners must all exist in the reserved input map.'
}
if (@($owners.original | Sort-Object -Unique).Count -ne $owners.Count) {
    throw 'An original IDL may occur only once in a batch.'
}
$macros = @{}
$annotationText = [IO.File]::ReadAllText([IO.Path]::GetFullPath($AnnotationHeader))
foreach ($match in [regex]::Matches($annotationText, '(?m)^#define _WIN32META_OS_VERSION_(\w+) "SupportedOSPlatform\(\\"([^"\\]+)\\"\)"')) {
    $macro = "_Win32_SupportedOS_$($match.Groups[1].Value)_"
    if ($annotationText -notmatch "(?m)^#define $([regex]::Escape($macro)) ") {
        throw "The canonical OS payload has no public macro: $macro"
    }
    $macros[$match.Groups[2].Value] = $macro
}
if (!$macros.Count) { throw 'No canonical public SupportedOS vocabulary was found.' }

$results = [Collections.Generic.List[object]]::new()
$plans = [Collections.Generic.List[object]]::new()
foreach ($owner in $owners) {
    $relative = $owner.original.Replace('/', '\')
    $path = Resolve-Input $relative
    $bytes = [IO.File]::ReadAllBytes($path)
    if ($null -ne $owner.PSObject.Properties['sourceSha256'] -and $owner.sourceSha256 -cne (Get-Hash $bytes)) {
        throw "Original IDL preimage mismatch: $relative"
    }
    if (($bytes.Length -ge 2 -and $bytes[0] -eq 255 -and $bytes[1] -eq 254) -or
        ($bytes.Length -ge 2 -and $bytes[0] -eq 254 -and $bytes[1] -eq 255) -or $bytes -contains 0) {
        throw "UTF-16/NUL IDL requires an explicit encoding-aware owner review: $relative"
    }
    $text = [Text.Encoding]::Latin1.GetString($bytes)
    $bom = if ($bytes.Length -ge 3 -and $bytes[0] -eq 239 -and $bytes[1] -eq 187 -and $bytes[2] -eq 191) { 3 } else { 0 }
    $mask = (' ' * $bom) + (Get-CodeMask $text.Substring($bom))
    $macroDefinitions = [Collections.Generic.Dictionary[string, bool]]::new([StringComparer]::Ordinal)
    foreach ($definition in [regex]::Matches($mask,
        '(?m)^[ \t]*#[ \t]*define[ \t]+(?<name>[A-Za-z_]\w*)(?<parameters>\([^\r\n)]*\))?(?<body>(?:[^\r\n]*\\\r?\n)*[^\r\n]*)')) {
        $name = $definition.Groups['name'].Value
        $body = $definition.Groups['body'].Value -replace '\\\r?\n', ''
        if (!$macroDefinitions.ContainsKey($name)) { $macroDefinitions.Add($name, $true) }
        $macroDefinitions[$name] = $macroDefinitions[$name] -and $definition.Groups['parameters'].Success -and
            [regex]::IsMatch($body, '^\s*\[.*\]\s*$', 'Singleline')
    }
    $attributeMacros = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    foreach ($name in $macroDefinitions.Keys) {
        if ($macroDefinitions[$name]) {
            $attributeMacros.Add($name) | Out-Null
        }
    }
    # Directives are declaration boundaries, not whitespace before an attribute list.
    $mask = [regex]::Replace($mask, '(?m)^[ \t]*#(?:[^\r\n]*\\\r?\n)*[^\r\n]*', {
        param($match)
        [regex]::Replace($match.Value, '[^\r\n]', ';')
    })
    $definitions = @([regex]::Matches($mask, '\binterface\s+(?<name>[A-Za-z_]\w*)\s*:\s*[A-Za-z_]\w*(?:\s*::\s*[A-Za-z_]\w*)*\s*\{'))
    $insertions = [Collections.Generic.List[object]]::new()
    $dispositions = [Collections.Generic.List[object]]::new()
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $newline = [regex]::Match($text, '\r\n|\n|\r').Value
    if (!$newline) { $newline = "`r`n" }
    foreach ($fact in @($owner.facts)) {
        if (!$seen.Add("$($fact.category)|$($fact.symbol)")) {
            throw "Duplicate fact identity in $relative`: $($fact.category)/$($fact.symbol)"
        }
        $payload = [regex]::Match($fact.value, '^([A-Za-z_]\w*)=SupportedOSPlatform\("([^"]+)"\)$')
        $declarations = @($definitions | Where-Object { $_.Groups['name'].Value -ceq $fact.symbol })
        $reason = $null
        if ($fact.category -ne 'supportedOS') { $reason = 'not-an-interface-SupportedOS-fact-native-function-or-method-review-required' }
        elseif (!$payload.Success -or $payload.Groups[1].Value -cne $fact.symbol) { $reason = 'unsupported-or-inconsistent-authored-payload' }
        elseif (!$macros.ContainsKey($payload.Groups[2].Value)) { $reason = 'payload-not-in-reviewed-public-OS-vocabulary' }
        elseif ($declarations.Count -ne 1) { $reason = "requires-one-original-interface-definition-found-$($declarations.Count)" }
        elseif ($text -match "_Win32_AnnotateInterface_\s*\(\s*$([regex]::Escape($fact.symbol))\s*,") { $reason = 'existing-interface-carrier-requires-cumulative-review' }
        if ($reason) {
            $dispositions.Add([ordered]@{ fact = $fact; disposition = 'retained-legacy'; reason = $reason })
            continue
        }
        $definition = $declarations[0]
        $offset = Get-AttributeStart $mask $definition.Index $attributeMacros
        $macro = $macros[$payload.Groups[2].Value]
        $prefix = if ($offset -gt 0 -and $text[$offset - 1] -notin @("`n", "`r")) { $newline } else { '' }
        $insertions.Add([pscustomobject]@{ offset = $offset; text = "${prefix}_Win32_AnnotateInterface_($($fact.symbol), $macro)$newline" })
        $dispositions.Add([ordered]@{
            fact = $fact; disposition = 'authored-original-idl'; macro = $macro
            declaration = [ordered]@{
                name = $fact.symbol; qualifiedName = $fact.symbol; kind = 'InterfaceDecl'; file = $relative
                line = 1 + [regex]::Matches($text.Substring(0, $definition.Index), '\n').Count
                offset = $definition.Index; start = $offset; end = $definition.Index + $definition.Length
                isDefinition = $true; sourceSha256 = Get-Hash $bytes
            }
        })
    }
    if ($insertions.Count) {
        $first = [regex]::Match($mask.Substring($bom), '\S')
        if (!$first.Success) { throw "An admitted IDL has no source tokens: $relative" }
        $bootstrap = $first.Index + $bom
        $line = $text.LastIndexOf("`n", [Math]::Max(0, $bootstrap - 1)) + 1
        if ($line -lt $bom) { $line = $bom }
        if ($text.Substring($line) -notmatch '^#\s*include\s*[<"]sal\.h[>"]') {
            $insertions.Add([pscustomobject]@{ offset = $line; text = "#include <sal.h>$newline" })
        }
    }
    $after = $text
    foreach ($insertion in @($insertions | Sort-Object offset -Descending -Stable)) {
        $after = $after.Insert($insertion.offset, $insertion.text)
    }
    $plans.Add([ordered]@{ relative = $relative; path = $path; before = $bytes; after = [Text.Encoding]::Latin1.GetBytes($after); insertions = @($insertions) })
    $results.Add([ordered]@{
        original = $relative; generatedHeaders = @($owner.generatedHeaders); partitionCandidates = @($owner.partitionCandidates)
        sourceSha256 = Get-Hash $bytes; patchedSha256 = Get-Hash ([Text.Encoding]::Latin1.GetBytes($after))
        changed = $insertions.Count -gt 0; dispositions = @($dispositions); insertions = @($insertions)
    })
}

$activation = [Collections.Generic.Dictionary[string, object]]::new([StringComparer]::OrdinalIgnoreCase)
$unresolvedActivation = [Collections.Generic.List[object]]::new()
$recipePath = Join-Path $SdkProjectRoot 'patches\SdkHeaders.json'
$admittedOutputs = @()
if (Test-Path -LiteralPath $recipePath -PathType Leaf) {
    $recipe = Get-Content -LiteralPath $recipePath -Raw | ConvertFrom-Json
    if ($recipe.schemaVersion -ne 1) { throw 'Normal parser activation requires a schema-1 SDK recipe.' }
    if ($null -ne $recipe.PSObject.Properties['midl']) {
        $admittedOutputs = @($recipe.midl.outputs)
    }
}
foreach ($owner in @($results | Where-Object changed)) {
    foreach ($header in $owner.generatedHeaders) {
        if ([IO.Path]::IsPathRooted($header) -or $header -match '(^|[\\/])\.\.([\\/]|$)' -or
            [IO.Path]::GetExtension($header) -ne '.h') {
            throw "Invalid generated-header owner route: $header"
        }
        if (!@($admittedOutputs | Where-Object { $_.source -ieq $owner.original -and $_.path -ieq $header }).Count) {
            $unresolvedActivation.Add([ordered]@{ original = $owner.original; header = $header; reason = 'original-output-not-admitted-to-recipe' })
            continue
        }
        $matched = $false
        foreach ($name in $owner.partitionCandidates) {
            if ($name -notmatch '^[A-Za-z0-9_.-]+$') { throw "Invalid normal partition name: $name" }
            $directory = Join-Path $SdkProjectRoot "Partitions\$name"
            $settings = Join-Path $directory 'settings.rsp'
            if (!(Test-Path -LiteralPath "$directory\main.cpp" -PathType Leaf) -or
                !(Test-Path -LiteralPath $settings -PathType Leaf)) { continue }
            $before = [IO.File]::ReadAllBytes($settings)
            $content = [Text.UTF8Encoding]::new($false, $true).GetString($before)
            $traverses = @(Get-RspValues $content '--traverse')
            $owns = @($traverses | Where-Object {
                $pattern = $_.Replace('/', '\')
                $pattern.StartsWith('<IncludeRoot>\', [StringComparison]::OrdinalIgnoreCase) -and
                    [Management.Automation.WildcardPattern]::new($pattern.Substring(14),
                        [Management.Automation.WildcardOptions]::IgnoreCase).IsMatch($header.Replace('/', '\'))
            }).Count -gt 0
            if (!$owns) { continue }
            $matched = $true
            if ($activation.ContainsKey($name)) { continue }
            $enabled = @(Get-RspValues $content '--config') -ccontains 'parse-win32-annotations'
            $after = $before
            if (!$enabled) {
                $newline = [regex]::Match($content, '\r\n|\n|\r').Value
                if (!$newline) { $newline = "`r`n" }
                $separator = if ($content.Length -and $content[-1] -notin @("`r", "`n")) { $newline } else { '' }
                $suffix = [Text.Encoding]::UTF8.GetBytes("${separator}--config${newline}parse-win32-annotations${newline}")
                $after = [byte[]]::new($before.Length + $suffix.Length)
                $before.CopyTo($after, 0)
                $suffix.CopyTo($after, $before.Length)
            }
            $activation.Add($name, [ordered]@{
                partition = $name; settings = $settings; enabled = $enabled
                before = $before; after = $after; preimageSha256 = Get-Hash $before; resultSha256 = Get-Hash $after
            })
        }
        if (!$matched) {
            $unresolvedActivation.Add([ordered]@{
                original = $owner.original; header = $header; reason = 'no-configured-normal-traverse-owner'
            })
        }
    }
}
if ($Apply) {
    if (!$activation.Count -or $unresolvedActivation.Count) {
        throw 'Apply requires recipe-admitted originals and actual configured normal traverse owners; no speculative settings or namespace will be created.'
    }
    foreach ($item in $activation.Values) {
        if ((Get-Hash ([IO.File]::ReadAllBytes($item.settings))) -cne $item.preimageSha256) {
            throw "Normal partition settings changed during planning: $($item.settings)"
        }
    }
    foreach ($item in $activation.Values) {
        if (!$item.enabled) {
            [IO.File]::WriteAllBytes($item.settings, $item.after)
            $item.enabled = $true
        }
    }
}

[IO.Directory]::CreateDirectory($OutputDirectory) | Out-Null
foreach ($plan in $plans) {
    if (!$plan.insertions.Count) { continue }
    $target = Join-Path "$OutputDirectory\source" $plan.relative
    [IO.Directory]::CreateDirectory([IO.Path]::GetDirectoryName($target)) | Out-Null
    [IO.File]::WriteAllBytes($target, $plan.after)
    Write-Patch $plan.path $target $plan.relative (Join-Path "$OutputDirectory\patches" "$($plan.relative).patch")
}
$all = @($results | ForEach-Object dispositions)
$report = [ordered]@{
    schemaVersion = 1; kind = 'original-idl-authoring-not-compile-or-full-sdk-acceptance'
    inputMapSha256 = Get-Hash ([IO.File]::ReadAllBytes([IO.Path]::GetFullPath($InputMap)))
    sdkIncludeRoot = $SdkIncludeRoot
    originalIdlsPatched = @($results | Where-Object changed | ForEach-Object original)
    candidateGeneratedHeaders = @($results | Where-Object changed | ForEach-Object generatedHeaders | Sort-Object -Unique)
    authoredFacts = @($all | Where-Object disposition -eq 'authored-original-idl').Count
    retainedLegacyFacts = @($all | Where-Object disposition -eq 'retained-legacy').Count
    normalParserActivation = [ordered]@{
        applied = [bool]$Apply
        ready = $activation.Count -gt 0 -and !$unresolvedActivation.Count -and
            !@($activation.Values | Where-Object { !$_.enabled }).Count
        unresolved = @($unresolvedActivation)
        partitions = @($activation.Values | ForEach-Object {
            [ordered]@{
                partition = $_.partition; settings = $_.settings; enabled = $_.enabled
                preimageSha256 = $_.preimageSha256; resultSha256 = $_.resultSha256
            }
        })
    }
    owners = @($results)
}
[IO.File]::WriteAllText("$OutputDirectory\report.json", ($report | ConvertTo-Json -Depth 20), [Text.UTF8Encoding]::new($false))
[pscustomobject]@{
    Report = "$OutputDirectory\report.json"; OriginalIdls = $report.originalIdlsPatched.Count
    CandidateGeneratedHeaders = $report.candidateGeneratedHeaders.Count
    AuthoredFacts = $report.authoredFacts; RetainedLegacyFacts = $report.retainedLegacyFacts
}
