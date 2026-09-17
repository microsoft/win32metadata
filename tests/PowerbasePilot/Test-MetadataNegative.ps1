[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory
)

$ErrorActionPreference = 'Stop'
$repo = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$evidence = [IO.Path]::GetFullPath($EvidenceDirectory)
$manifest = Get-Content (Join-Path $evidence 'manifest.json') -Raw | ConvertFrom-Json -Depth 100
$candidateCommand = @($manifest.commands | Where-Object {
    $_.arguments[0] -eq 'scrape' -and $_.log -like '*candidate\generation.log'
})
if ($candidateCommand.Count -ne 1 -or $candidateCommand[0].exitCode -ne 0) {
    throw 'Negative tests require a successfully generated pinned candidate command.'
}
$command = $candidateCommand[0]
$tool = $command.executable
if ((Get-FileHash $tool).Hash -cne $manifest.tool.sha256) { throw 'Generator changed since positive evidence was recorded.' }
$reader = Join-Path $repo 'bin\Release\net10.0\WinmdUtils.dll'
$output = Join-Path $evidence 'negative-metadata'
if (Test-Path $output) { throw "Negative evidence directory already exists: $output" }
New-Item -ItemType Directory -Path $output | Out-Null
$headerPath = Join-Path $evidence 'candidate\headers\um\powerbase.h'
$source = [IO.File]::ReadAllText($headerPath)

function Read-MethodContract([string]$Winmd, [string]$Method, [string]$Path) {
    & dotnet $reader contracts --winmd $Winmd --output $Path --root $Method --require-roots *> "$Path.log"
    if ($LASTEXITCODE -ne 0) { throw "Failed to decode negative-test method $Method." }
    $snapshot = Get-Content $Path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $methods = @($snapshot.declarations | ForEach-Object { $_.methods } | Where-Object name -CEQ $Method)
    if ($methods.Count -ne 1) { throw "Expected exactly one $Method contract." }
    return $methods[0]
}

function Assert-PilotParameter($Method, [string]$Case) {
    if ($Case -eq 'enum-association') {
        $parameter = @($Method.parameters | Where-Object sequence -eq 1)[0]
        $attributes = @($parameter.customAttributes | Where-Object { $_.constructor.declaringType.name -eq 'AssociatedEnumAttribute' })
        if ($attributes.Count -ne 1 -or $attributes[0].fixedArguments[0].value -cne 'POWER_PLATFORM_ROLE_VERSION') {
            throw 'PowerDeterminePlatformRoleEx.Version must retain its POWER_PLATFORM_ROLE_VERSION association.'
        }
    } else {
        $parameter = @($Method.parameters | Where-Object sequence -eq 2)[0]
        $attributes = @($parameter.customAttributes | Where-Object { $_.constructor.declaringType.name -eq 'MemorySizeAttribute' })
        if ($attributes.Count -ne 1) { throw 'CallNtPowerInformation.InputBuffer must have a byte-count contract, not an element-count contract.' }
        $bytes = @($attributes[0].namedArguments | Where-Object name -eq 'BytesParamIndex')
        if ($bytes.Count -ne 1 -or $bytes[0].value -ne 2) { throw 'CallNtPowerInformation.InputBuffer must use byte count parameter index 2.' }
    }
}

$cases = @(
    @{name='enum-association';method='PowerDeterminePlatformRoleEx';before='_In_ _Win32_AssociatedEnum_(POWER_PLATFORM_ROLE_VERSION) ULONG Version';after='_In_ ULONG Version';expected='*must retain its POWER_PLATFORM_ROLE_VERSION association*'},
    @{name='byte-count-index';method='CallNtPowerInformation';before='_In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer';after='_In_reads_bytes_opt_(OutputBufferLength) PVOID InputBuffer';expected='*must use byte count parameter index 2*'},
    @{name='bytes-to-elements';method='CallNtPowerInformation';before='_In_reads_bytes_opt_(InputBufferLength) PVOID InputBuffer';after='_In_reads_opt_(InputBufferLength) PVOID InputBuffer';expected='*must have a byte-count contract*'}
)
$results = [Collections.Generic.List[object]]::new()
$previousLibclang = $env:LIBCLANG_PATH
$previousResource = $env:CLANG_RESOURCE_DIR
try {
    $env:LIBCLANG_PATH = $command.libclangPath
    $env:CLANG_RESOURCE_DIR = $manifest.resourceDirectory
    foreach ($case in $cases) {
        $caseRoot = Join-Path $output $case.name
        $headers = Join-Path $caseRoot 'headers'
        New-Item -ItemType Directory -Path $headers -Force | Out-Null
        if ([regex]::Matches($source,[regex]::Escape($case.before)).Count -ne 1) { throw "Mutation must match exactly once: $($case.name)" }
        [IO.File]::WriteAllText((Join-Path $headers 'powerbase.h'), $source.Replace($case.before,$case.after), [Text.UTF8Encoding]::new($false))
        $positive = Read-MethodContract (Join-Path $evidence 'candidate\Windows.Win32.winmd') $case.method (Join-Path $caseRoot 'positive.json')
        Assert-PilotParameter $positive $case.name
        $args = [Collections.Generic.List[string]]::new()
        for ($i=0; $i -lt $command.arguments.Count; $i++) {
            $arg = $command.arguments[$i]
            if ($arg -eq '--arch') { $i++; continue }
            if ($arg -eq '--output') { $args.Add($arg); $args.Add((Join-Path $caseRoot 'Windows.Win32.winmd')); $i++; continue }
            if ($arg -eq '--obj') { $args.Add($arg); $args.Add((Join-Path $caseRoot 'obj')); $i++; continue }
            if ($arg -eq '--include' -and [IO.Path]::GetFullPath($command.arguments[$i+1]) -ieq [IO.Path]::GetFullPath((Split-Path $headerPath))) {
                $args.Add($arg); $args.Add($headers); $i++; continue
            }
            $args.Add($arg)
        }
        $args.Add('--arch'); $args.Add('x64')
        & $tool @args *> (Join-Path $caseRoot 'generation.log')
        if ($LASTEXITCODE -ne 0) { throw "Negative mutation did not reach metadata comparison: $($case.name)." }
        $negative = Read-MethodContract (Join-Path $caseRoot 'Windows.Win32.winmd') $case.method (Join-Path $caseRoot 'negative.json')
        $failure = $null
        try { Assert-PilotParameter $negative $case.name } catch { $failure=$_.Exception.Message }
        if ($failure -notlike $case.expected) { throw "Mutation did not fail the intended contract: $($case.name). Actual: $failure" }
        & dotnet $reader compare-contracts --first (Join-Path $caseRoot 'positive.json') --second (Join-Path $caseRoot 'negative.json') --output (Join-Path $caseRoot 'diff.json') *> (Join-Path $caseRoot 'diff.log')
        if ($LASTEXITCODE -ne 1) { throw "General semantic comparer failed to reject mutation $($case.name)." }
        $results.Add([ordered]@{case=$case.name;mutationBefore=$case.before;mutationAfter=$case.after;result='rejected';
            diagnostic=$failure;generatorHash=(Get-FileHash $tool).Hash;headerHash=(Get-FileHash (Join-Path $headers 'powerbase.h')).Hash;
            winmdHash=(Get-FileHash (Join-Path $caseRoot 'Windows.Win32.winmd')).Hash;arguments=$args.ToArray()})
    }
} finally {
    $results.ToArray() | ConvertTo-Json -Depth 20 | Set-Content -Encoding utf8 (Join-Path $output 'results.json')
    $env:LIBCLANG_PATH = $previousLibclang
    $env:CLANG_RESOURCE_DIR = $previousResource
}
Write-Host 'All three source-to-WinMD metadata mutations were rejected by the intended contract gates.'
