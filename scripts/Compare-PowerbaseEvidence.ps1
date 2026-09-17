[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [switch]$RequireExactEquality
)

$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$reader = Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
$evidence = [IO.Path]::GetFullPath($EvidenceDirectory)
$output = Join-Path $evidence 'comparison'
$contracts = Join-Path $evidence 'contracts'
New-Item -ItemType Directory -Force -Path $output, $contracts, (Join-Path $output 'symbols') | Out-Null
$functions = @('CallNtPowerInformation','GetPwrCapabilities','PowerDeterminePlatformRoleEx',
    'PowerRegisterSuspendResumeNotification','PowerUnregisterSuspendResumeNotification')
$types = @('HPOWERNOTIFY','PHPOWERNOTIFY','POWER_PLATFORM_ROLE_VERSION','REGISTER_NOTIFICATION_FLAGS')
$members = @('POWER_PLATFORM_ROLE_CURRENT_VERSION','POWER_PLATFORM_ROLE_V1','POWER_PLATFORM_ROLE_V2',
    'DEVICE_NOTIFY_SERVICE_HANDLE','DEVICE_NOTIFY_CALLBACK','DEVICE_NOTIFY_WINDOW_HANDLE','DEVICE_NOTIFY_ALL_INTERFACE_CLASSES')
$queries = $functions + $types + $members
$queryArgs = @($queries | ForEach-Object { '--root'; $_ })

function Write-Json($Value, [string]$Path) {
    ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 $Path
}

function Read-Snapshot([string]$Winmd, [string]$Name, [bool]$All=$false) {
    $path = Join-Path $contracts "$Name.json"
    $args = @($reader,'contracts','--winmd',$Winmd,'--output',$path)
    if (-not $All) { $args += $queryArgs }
    & dotnet @args *> (Join-Path $contracts "$Name.log")
    if ($LASTEXITCODE -ne 0) { throw "Metadata decoder failed for $Name; see $contracts\$Name.log" }
    $snapshot = Get-Content $path -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    if ($snapshot.source.sha256 -cne (Get-FileHash $Winmd).Hash) { throw "Snapshot source hash mismatch: $Name" }
    return $snapshot
}

function Get-Facts($Value) {
    if ($Value -is [Collections.IDictionary]) {
        $result = [ordered]@{}
        foreach ($key in @($Value.Keys | Sort-Object -CaseSensitive)) {
            if ($key -ne 'evidence') { $result[$key] = Get-Facts $Value[$key] }
        }
        return $result
    }
    if ($Value -is [array]) { return ,@($Value | ForEach-Object { Get-Facts $_ }) }
    return $Value
}

function Get-Differences($First, $Second, [string]$Path='') {
    if ($First -is [Collections.IDictionary] -and $Second -is [Collections.IDictionary]) {
        foreach ($key in @(@($First.Keys) + @($Second.Keys) | Sort-Object -CaseSensitive -Unique)) {
            $childPath = $Path + '/' + $key.Replace('~','~0').Replace('/','~1')
            if (-not $First.Contains($key) -or -not $Second.Contains($key)) {
                [ordered]@{path=$childPath;firstPresent=$First.Contains($key);secondPresent=$Second.Contains($key);first=$First[$key];second=$Second[$key]}
            } else { Get-Differences $First[$key] $Second[$key] $childPath }
        }
    } elseif ($First -is [array] -and $Second -is [array]) {
        for ($i=0; $i -lt [Math]::Max($First.Count,$Second.Count); $i++) {
            if ($i -ge $First.Count -or $i -ge $Second.Count) {
                [ordered]@{path="$Path/$i";firstPresent=($i -lt $First.Count);secondPresent=($i -lt $Second.Count);first=$(if($i -lt $First.Count){$First[$i]});second=$(if($i -lt $Second.Count){$Second[$i]})}
            } else { Get-Differences $First[$i] $Second[$i] "$Path/$i" }
        }
    } elseif ((ConvertTo-Json -InputObject $First -Depth 100 -Compress) -cne (ConvertTo-Json -InputObject $Second -Depth 100 -Compress)) {
        [ordered]@{path=$Path;firstPresent=$true;secondPresent=$true;first=$First;second=$Second}
    }
}

function Get-Entity($Snapshot, [string]$Kind, [string]$Name) {
    $items = @(switch ($Kind) {
        'function' { @($Snapshot.declarations | ForEach-Object { $_.methods } | Where-Object name -CEQ $Name) }
        'type' { @($Snapshot.declarations | Where-Object name -CEQ $Name) }
        'member' { @($Snapshot.declarations | ForEach-Object { $_.fields } | Where-Object name -CEQ $Name) }
    })
    return ,(Get-Facts $items)
}

function Format-Type($Type) {
    if ($null -eq $Type) { return '?' }
    switch ($Type.kind) {
        'primitive' { return $Type.name }
        'type' { return $Type.fullName }
        'pointer' { return (Format-Type $Type.elementType) + '*' }
        'modified' { return "$(if($Type.required){'modreq'}else{'modopt'})($($Type.modifier.fullName)) " + (Format-Type $Type.elementType) }
        default { return ConvertTo-Json -InputObject $Type -Depth 30 -Compress }
    }
}

function Format-Attributes($Attributes) {
    return @($Attributes | Where-Object { $null -ne $_ -and $_.constructor } | ForEach-Object {
        $values = @(@($_.fixedArguments | ForEach-Object { ConvertTo-Json -InputObject $_.value -Compress -Depth 20 }) +
            @($_.namedArguments | ForEach-Object { "$($_.name)=$(ConvertTo-Json -InputObject $_.value -Compress -Depth 20)" }))
        "$($_.constructor.declaringType.fullName)($($values -join ', '))"
    }) -join '; '
}

function Format-Entity($Items) {
    if ($Items.Count -eq 0) { return '**absent**' }
    return @($Items | ForEach-Object {
        $item = $_
        if ($item.kind -eq 'method') {
            $parameters = @()
            for ($i=0; $i -lt $item.signature.parameterTypes.Count; $i++) {
                $row = @($item.parameters | Where-Object sequence -eq ($i+1))
                $parameters += "$(Format-Type $item.signature.parameterTypes[$i]) $($row.name) [$($row.attributes.names)] $(Format-Attributes @($row | ForEach-Object {$_.customAttributes}))"
            }
            "$($item.qualifiedName)($($parameters -join '; ')) -> $(Format-Type $item.signature.returnType); return attributes: $(Format-Attributes @($item.parameters | Where-Object sequence -eq 0 | ForEach-Object {$_.customAttributes})); import $($item.import.module)!$($item.import.name) [$($item.import.attributes.names)]; $(Format-Attributes $item.customAttributes)"
        } elseif ($item.kind -eq 'field') {
            "$($item.qualifiedName): $(Format-Type $item.type); constant $(ConvertTo-Json -InputObject $item.constant -Compress -Depth 10); $(Format-Attributes $item.customAttributes)"
        } else {
            $storage = @($item.fields | Where-Object name -in @('Value','value__') | ForEach-Object { "$($_.name): $(Format-Type $_.type)" })
            "$($item.qualifiedName) [$($item.attributes.names)]; $($storage -join ', '); fields=$($item.fields.Count); layout=$(ConvertTo-Json -InputObject $item.layout -Compress); $(Format-Attributes $item.customAttributes)"
        }
    }) -join '<br>'
}

function Escape-Cell([string]$Text) { return $Text.Replace('|','\|').Replace("`r",'').Replace("`n",'<br>') }

function Get-ReferenceProblems($Snapshot) {
    $defined = @{}
    foreach ($type in $Snapshot.declarations) { $defined[$type.qualifiedName] = $type }
    $problems = [Collections.Generic.List[object]]::new()
    $seen = @{}
    function Visit-Reference($Value, [string]$Path) {
        if ($Value -is [Collections.IDictionary]) {
            if ($Value.kind -eq 'type' -and $Value.Contains('fullName') -and $Value.fullName -like 'Windows.Win32.*' -and -not $defined.ContainsKey($Value.fullName)) {
                $external = $Value.scope -and $Value.scope.kind -eq 'assembly' -and $Value.scope.identity.name -cne $Snapshot.assembly.name
                if (-not $external) {
                    $key = "type:$($Value.fullName)"
                    if (-not $seen.ContainsKey($key)) {
                        $seen[$key]=$true
                        $problems.Add([ordered]@{kind='unresolved-local-type';target=$Value.fullName;firstUse=$Path;scope=$Value.scope;rawResolutionScope=$Value.evidence.resolutionScope})
                    }
                }
            }
            if ($Value.Contains('constructor') -and $Value.constructor.declaringType.name -eq 'AssociatedEnumAttribute') {
                $target = $Value.fixedArguments[0].value
                $matches = @($Snapshot.declarations | Where-Object { ($_.name -ceq $target -or $_.qualifiedName -ceq $target) -and $_.baseType.fullName -eq 'System.Enum' })
                if ($matches.Count -ne 1) {
                    $problems.Add([ordered]@{kind='unresolved-or-ambiguous-associated-enum';target=$target;firstUse=$Path;matches=@($matches.qualifiedName)})
                }
            }
            foreach ($key in $Value.Keys) {
                if ($key -ne 'evidence') { Visit-Reference $Value[$key] "$Path/$key" }
            }
        } elseif ($Value -is [array]) {
            for ($i=0; $i -lt $Value.Count; $i++) { Visit-Reference $Value[$i] "$Path/$i" }
        }
    }
    Visit-Reference $Snapshot.declarations '/declarations'
    return ,$problems.ToArray()
}

$reference = Read-Snapshot (Join-Path $evidence 'reference\Windows.Win32.winmd') 'reference'
$snapshots = @{ reference=$reference }
$comparisonRuns = [Collections.Generic.List[object]]::new()
$bindings = [ordered]@{}
foreach ($variant in @('control','candidate')) {
    foreach ($architecture in @('merged','x64','x86','arm64')) {
        $name = "$variant-$architecture"
        $winmd = if ($architecture -eq 'merged') { Join-Path $evidence "$variant\Windows.Win32.winmd" } else { Join-Path $evidence "$variant\obj\Windows.Win32.$architecture.winmd" }
        $snapshot = Read-Snapshot $winmd $name
        $snapshots[$name] = $snapshot
        $bindings[$name] = Get-ReferenceProblems $snapshot
        $diffPath = Join-Path $output "reference-to-$name.json"
        & dotnet $reader compare-contracts --first (Join-Path $contracts 'reference.json') --second (Join-Path $contracts "$name.json") --output $diffPath *> (Join-Path $output "reference-to-$name.log")
        if ($LASTEXITCODE -notin @(0,1)) { throw "Semantic comparison failed to run: $name" }
        $diff = Get-Content $diffPath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
        $comparisonRuns.Add([ordered]@{variant=$variant;architecture=$architecture;equal=$diff.equal;differences=$diff.differences.Count;unresolvedReferences=$bindings[$name].Count})
    }
}

$allCandidate = Read-Snapshot (Join-Path $evidence 'candidate\Windows.Win32.winmd') 'candidate-all' $true
$selectedNames = @($snapshots['candidate-merged'].declarations.qualifiedName)
$unreached = @($allCandidate.declarations | Where-Object { $_.qualifiedName -notin $selectedNames -and
    -not ($_.name -eq '<Module>' -and $_.fields.Count -eq 0 -and $_.methods.Count -eq 0) })
Write-Json $bindings (Join-Path $output 'reference-resolution.json')
Write-Json $unreached (Join-Path $output 'unreached-emitted-definitions.json')

$rows = [Collections.Generic.List[object]]::new()
$index=0
foreach ($spec in @(@{kind='function';names=$functions},@{kind='type';names=$types},@{kind='member';names=$members})) {
    foreach ($name in $spec.names) {
        $old = Get-Entity $reference $spec.kind $name
        $control = Get-Entity $snapshots['control-merged'] $spec.kind $name
        $candidate = Get-Entity $snapshots['candidate-merged'] $spec.kind $name
        $differences = @(Get-Differences $old $candidate)
        $controlDifferences = @(Get-Differences $control $candidate)
        $record = [ordered]@{kind=$spec.kind;name=$name;reference=$old;control=$control;candidate=$candidate;
            referenceToCandidate=$differences;controlToCandidate=$controlDifferences}
        $file = ('{0:D2}.json' -f $index++)
        Write-Json $record (Join-Path $output "symbols\$file")
        $rows.Add([ordered]@{kind=$spec.kind;name=$name;reference=Format-Entity $old;control=Format-Entity $control;
            candidate=Format-Entity $candidate;differences=$differences.Count;record="symbols/$file"})
    }
}

$dependencyNames = @(@($reference.declarations.name) + @($snapshots['control-merged'].declarations.name) +
    @($snapshots['candidate-merged'].declarations.name) | Where-Object { $_ -notin $types -and $_ -ne 'Apis' } | Sort-Object -Unique)
$dependencyRows = @(
    foreach ($name in $dependencyNames) {
        $old = Get-Entity $reference 'type' $name
        $control = Get-Entity $snapshots['control-merged'] 'type' $name
        $candidate = Get-Entity $snapshots['candidate-merged'] 'type' $name
        [ordered]@{name=$name;reference=$old;control=$control;candidate=$candidate;referenceToCandidate=@(Get-Differences $old $candidate)}
    }
)
Write-Json $dependencyRows (Join-Path $output 'dependency-contracts.json')
Write-Json $rows.ToArray() (Join-Path $output 'symbol-table.json')
$dependencyReport=[Collections.Generic.List[string]]::new()
$dependencyReport.Add('# Complete dependency field and enum-member inventory')
$dependencyReport.Add('')
$dependencyReport.Add('Each type is a dependency, not an additional powerbase-owned declaration. All fields and enum members from the union of the three snapshots are listed, including missing rows. Type contracts and attributes remain in dependency-contracts.json.')
foreach($dependency in $dependencyRows) {
    $dependencyReport.Add('')
    $dependencyReport.Add("## $($dependency.name)")
    $dependencyReport.Add('')
    $dependencyReport.Add('| Field/member | Published reference | Control | Candidate |')
    $dependencyReport.Add('| --- | --- | --- | --- |')
    $fieldNames=@(@($dependency.reference | ForEach-Object {$_.fields.name})+
        @($dependency.control | ForEach-Object {$_.fields.name})+
        @($dependency.candidate | ForEach-Object {$_.fields.name}) | Sort-Object -CaseSensitive -Unique)
    foreach($fieldName in $fieldNames) {
        $oldFields=@($dependency.reference | ForEach-Object {$_.fields} | Where-Object name -CEQ $fieldName)
        $controlFields=@($dependency.control | ForEach-Object {$_.fields} | Where-Object name -CEQ $fieldName)
        $candidateFields=@($dependency.candidate | ForEach-Object {$_.fields} | Where-Object name -CEQ $fieldName)
        $dependencyReport.Add("| $fieldName | $(Escape-Cell (Format-Entity $oldFields)) | $(Escape-Cell (Format-Entity $controlFields)) | $(Escape-Cell (Format-Entity $candidateFields)) |")
    }
}
[IO.File]::WriteAllLines((Join-Path $output 'DEPENDENCIES.md'),$dependencyReport,[Text.UTF8Encoding]::new($false))
$exactlyEqual = @($comparisonRuns | Where-Object { -not $_.equal -or $_.unresolvedReferences -ne 0 }).Count -eq 0 -and $unreached.Count -eq 0
$verdict = [ordered]@{exactlyEqual=$exactlyEqual;logicalEquivalence='not established by this serialization audit';comparisonRuns=$comparisonRuns.ToArray();unreachedDefinitions=$unreached.Count;
    comparedOwnerAndConditionalAliasRows=$rows.Count;dependencyTypeNames=$dependencyNames;readerSha256=(Get-FileHash $reader).Hash;
    normalization=@('metadata source hashes and designated evidence properties only; original scopes retained in raw JSON');
    pairing='Short symbol names pair records for display only; full namespaces/signatures/attributes remain compared.';
    unresolvedReferences=$bindings;knownAbsentAlias='PHPOWERNOTIFY is absent from both reference and candidate; native pointer-alias proof is separate.'}
Write-Json $verdict (Join-Path $output 'verdict.json')

$report = [Collections.Generic.List[string]]::new()
$report.Add('# powerbase.h semantic comparison')
$report.Add('')
$report.Add("**Exact metadata-contract equality: $exactlyEqual. Logical equivalence is evaluated separately.** This serialization audit preserves every difference; namespace partitioning, documentation, and assembly versions are not automatically functional gaps.")
$report.Add('')
$report.Add('Scope: five functions, two conditional native aliases, two synthetic groups, and all seven proposed members. A missing symbol stays visible. Dependencies and every field/enum member are retained in `dependency-contracts.json`; the full row-level comparisons are the `reference-to-*.json` files.')
$report.Add('')
$report.Add('| Kind | Symbol | Published reference | Rust control | Candidate | Exact differences |')
$report.Add('| --- | --- | --- | --- | --- | --- |')
foreach ($row in $rows) {
    $report.Add("| $($row.kind) | $($row.name) | $(Escape-Cell $row.reference) | $(Escape-Cell $row.control) | $(Escape-Cell $row.candidate) | [$($row.differences) facts]($($row.record)) |")
}
$report.Add('')
$report.Add('## Architecture results')
$report.Add('')
$report.Add('| Variant | Architecture | Exact semantic equality | Different facts | Unresolved local/enum references |')
$report.Add('| --- | --- | --- | --- | --- |')
foreach ($run in $comparisonRuns) { $report.Add("| $($run.variant) | $($run.architecture) | $($run.equal) | $($run.differences) | $($run.unresolvedReferences) |") }
$report.Add('')
$report.Add('## Dependency ledger')
$report.Add('')
$report.Add('The source-backed native/annotation ledgers are in each variant directory. The dependency contracts below include complete type flags, layout, fields, enum membership, attributes, and references, not just names.')
$report.Add('Every dependency field and enum member is also listed in the readable [complete dependency table](DEPENDENCIES.md).')
$report.Add('')
$report.Add('| Dependency | Reference declarations / fields | Control declarations / fields | Candidate declarations / fields |')
$report.Add('| --- | --- | --- | --- |')
foreach ($item in $dependencyRows) {
    $report.Add("| $($item.name) | $($item.reference.Count) / $(@($item.reference | ForEach-Object {$_.fields}).Count) | $($item.control.Count) / $(@($item.control | ForEach-Object {$_.fields}).Count) | $($item.candidate.Count) / $(@($item.candidate | ForEach-Object {$_.fields}).Count) |")
}
$report.Add('')
$report.Add('`reference-resolution.json` identifies unresolved same-assembly type uses and unresolved/ambiguous enum strings. Well-known framework types are not mistaken for this header''s API declarations. No Windows.Win32 API definition is copied from the reference to make a binding appear valid.')
$report.Add('')
$report.Add('Only source identity and designated forensic evidence are excluded from exact comparisons. Display pairing by short name does not normalize namespaces. Native/header equality, transport assertions, negative tests, documented lifecycle corrections, and SDK availability are separate evidence and do not automatically approve any difference listed here.')
[IO.File]::WriteAllLines((Join-Path $output 'REPORT.md'), $report, [Text.UTF8Encoding]::new($false))
Write-Host "Complete serialization audit written to $output. ExactlyEqual=$exactlyEqual"
if ($RequireExactEquality -and -not $exactlyEqual) { throw "Raw metadata contracts differ; see $output\verdict.json. Logical equivalence is a separate gate." }
