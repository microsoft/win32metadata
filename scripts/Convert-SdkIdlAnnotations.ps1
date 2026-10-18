#Requires -Version 7.0

[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$InputMap,
    [Parameter(Mandatory)][string]$SdkIncludeRoot,
    [Parameter(Mandatory)][string]$OutputDirectory,
    [string[]]$Original,
    [string]$AnnotationHeader = "$PSScriptRoot\..\generation\WinSDK\RecompiledIdlHeaders\shared\win32metadata_annotations.h"
)

$ErrorActionPreference = 'Stop'
Set-StrictMode -Version Latest
$SdkIncludeRoot = [IO.Path]::GetFullPath($SdkIncludeRoot).TrimEnd('\')
$OutputDirectory = [IO.Path]::GetFullPath($OutputDirectory).TrimEnd('\')
if ($OutputDirectory -eq $SdkIncludeRoot -or
    $OutputDirectory.StartsWith("$SdkIncludeRoot\", [StringComparison]::OrdinalIgnoreCase) -or
    $SdkIncludeRoot.StartsWith("$OutputDirectory\", [StringComparison]::OrdinalIgnoreCase)) {
    throw 'IDL authoring output must not overlap the installed SDK.'
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

function Get-AttributeStart([string]$Mask, [int]$Offset) {
    $start = $Offset
    while ($true) {
        $cursor = $start - 1
        while ($cursor -ge 0 -and [char]::IsWhiteSpace($Mask[$cursor])) { $cursor-- }
        if ($cursor -lt 0 -or $Mask[$cursor] -ne ']') { break }
        $depth = 1
        $cursor--
        while ($cursor -ge 0 -and $depth -gt 0) {
            if ($Mask[$cursor] -eq ']') { $depth++ }
            if ($Mask[$cursor] -eq '[') { $depth-- }
            $cursor--
        }
        if ($depth -ne 0) { throw "Unbalanced IDL attributes before byte $Offset" }
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
        $offset = Get-AttributeStart $mask $definition.Index
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
    distinctGeneratedHeadersAffected = @($results | Where-Object changed | ForEach-Object generatedHeaders | Sort-Object -Unique)
    authoredFacts = @($all | Where-Object disposition -eq 'authored-original-idl').Count
    retainedLegacyFacts = @($all | Where-Object disposition -eq 'retained-legacy').Count
    owners = @($results)
}
[IO.File]::WriteAllText("$OutputDirectory\report.json", ($report | ConvertTo-Json -Depth 20), [Text.UTF8Encoding]::new($false))
[pscustomobject]@{
    Report = "$OutputDirectory\report.json"; OriginalIdls = $report.originalIdlsPatched.Count
    GeneratedHeadersAffected = $report.distinctGeneratedHeadersAffected.Count
    AuthoredFacts = $report.authoredFacts; RetainedLegacyFacts = $report.retainedLegacyFacts
}
