[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SdkInclude,
    [Parameter(Mandatory)][string]$CandidateInclude,
    [Parameter(Mandatory)][string]$Libclang,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)

$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$fixture = Join-Path $root 'tests\PowerbasePilot'
if (-not ('PowerbaseNativeProbe' -as [type])) {
    Add-Type -Path (Join-Path $fixture 'NativeProbe.cs')
}
New-Item -ItemType Directory -Force -Path $OutputDirectory | Out-Null
$initialized = $false

function ConvertTo-NativeContract($Value) {
    if ($null -eq $Value) { return $null }
    if ($Value -is [Collections.IDictionary]) {
        $result = [ordered]@{}
        foreach ($key in @($Value.Keys | Sort-Object)) {
            # Annotation transport and source relocation are the only excluded AST facts.
            if ($key -notin @('source', 'annotations')) {
                $result[$key] = ConvertTo-NativeContract $Value[$key]
            }
        }
        return $result
    }
    if ($Value -is [array]) {
        $result = @($Value | ForEach-Object { ConvertTo-NativeContract $_ })
        return ,$result
    }
    return $Value
}

function Get-NativeSnapshot([string]$Arch, [string]$Mode, [string]$Variant, [bool]$HeaderFirst) {
    $triple = @{ x64 = 'x86_64-pc-windows-msvc'; x86 = 'i686-pc-windows-msvc'; arm64 = 'aarch64-pc-windows-msvc' }[$Arch]
    $language = if ($Mode -eq 'c') { @('-x', 'c', '-std=c17') } else { @('-x', 'c++', '-std=c++17') }
    $arguments = @("--target=$triple") + $language + @(
        '-fms-compatibility', '-ferror-limit=0', '-D_COM_NO_STANDARD_GUIDS_=1',
        '-resource-dir', $ResourceDirectory
    )
    if ($Mode -eq 'metadata') { $arguments += '-DWIN32METADATA=1' }
    if ($HeaderFirst) { $arguments += @('-DNOUSER=1', '-DWIN32_LEAN_AND_MEAN=1') }
    if ($Variant -eq 'candidate') { $arguments += @('-isystem', $CandidateInclude) }
    $arguments += @('-isystem', (Join-Path $root 'generation\WinSDK\AdditionalHeaders'),
        '-isystem', (Join-Path $root 'generation\WinSDK\inc'))
    foreach ($part in @('shared', 'um', 'ucrt', 'winrt')) {
        $arguments += @('-isystem', (Join-Path $SdkInclude $part))
    }
    $header = if ($Variant -eq 'candidate') { Join-Path $CandidateInclude 'powerbase.h' } else { Join-Path $SdkInclude 'um\powerbase.h' }
    $source = Join-Path $fixture 'main.cpp'
    if (-not $script:initialized) {
        $snapshot = [PowerbaseNativeProbe]::Capture($Libclang, $source, $header, $arguments)
        $script:initialized = $true
    } else {
        $snapshot = [PowerbaseNativeProbe]::Capture($source, $header, $arguments)
    }
    $suffix = if ($HeaderFirst) { '-header-first' } else { '' }
    $path = Join-Path $OutputDirectory "$Arch-$Mode-$Variant$suffix.json"
    $snapshot | ConvertTo-Json -Depth 90 | Set-Content -Encoding utf8 $path
    if ($snapshot.hasErrors) {
        throw "Native $Arch/$Mode/$Variant$suffix parse failed; diagnostics: $path"
    }
    if ($Mode -eq 'metadata' -and -not $HeaderFirst) {
        $macro = [PowerbaseNativeProbe]::Capture((Join-Path $fixture 'macros.cpp'), $header, $arguments)
        $macro | ConvertTo-Json -Depth 90 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory "$Arch-$Variant-macros.json")
        if ($macro.hasErrors) { throw "Macro restoration or unchanged declaration assertions failed for $Arch/$Variant." }
    }
    return $snapshot
}

$checks = [Collections.Generic.List[object]]::new()
foreach ($arch in @('x64', 'x86', 'arm64')) {
    foreach ($mode in @('c', 'cpp', 'metadata')) {
        foreach ($headerFirst in @($false, $true)) {
            $before = Get-NativeSnapshot $arch $mode 'control' $headerFirst
            $after = Get-NativeSnapshot $arch $mode 'candidate' $headerFirst
            $original = @{}
            foreach ($item in $before.ownedDeclarations) { $original["$($item['kind']):$($item['name'])"] = $item }
            $expectedNativeCount = if ($headerFirst) { 7 } else { 5 }
            if ($original.Count -ne $expectedNativeCount) { throw "Native inventory changed: expected $expectedNativeCount, got $($original.Count) for $arch/$mode." }
            $candidate = @{}
            foreach ($item in $after.ownedDeclarations) { $candidate["$($item['kind']):$($item['name'])"] = $item }
            $added = @($candidate.Keys | Where-Object { -not $original.ContainsKey($_) } | Sort-Object)
            $expectedAdded = if ($mode -eq 'metadata') { @('EnumDecl:POWER_PLATFORM_ROLE_VERSION', 'EnumDecl:REGISTER_NOTIFICATION_FLAGS') } else { @() }
            if (($added -join ',') -cne ($expectedAdded -join ',')) { throw "Unexpected added native declarations: $($added -join ', ')" }
            foreach ($key in $original.Keys) {
                if (-not $candidate.ContainsKey($key)) { throw "Missing native declaration $key for $arch/$mode." }
                $old = ConvertTo-NativeContract $original[$key] | ConvertTo-Json -Depth 80 -Compress
                $new = ConvertTo-NativeContract $candidate[$key] | ConvertTo-Json -Depth 80 -Compress
                if ($old -cne $new) { throw "Native declaration changed: $key ($arch/$mode/header-first=$headerFirst)." }
                $checks.Add([ordered]@{ architecture=$arch; mode=$mode; headerFirst=$headerFirst; symbol=$key; result='unchanged' })
            }
            $dependencyBefore = ConvertTo-NativeContract $before.dependencyDeclarations | ConvertTo-Json -Depth 80 -Compress
            $dependencyAfter = ConvertTo-NativeContract $after.dependencyDeclarations | ConvertTo-Json -Depth 80 -Compress
            if ($dependencyBefore -cne $dependencyAfter) { throw "Native dependency type/layout closure changed for $arch/$mode/header-first=$headerFirst." }
        }
    }
}
$checks | ConvertTo-Json -Depth 10 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory 'checks.json')
Write-Host "Native ABI/source checks passed: $($checks.Count) declarations, C/C++/metadata, x64/x86/ARM64, both typedef ownership contexts."
