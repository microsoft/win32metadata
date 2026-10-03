<#
.SYNOPSIS
    Compares WinMD namespace, type-name, API, and metadata-table coverage.

.DESCRIPTION
    Treats Microsoft.Windows.SDK.Win32Metadata 71.0.26-preview as a validation
    oracle by default. Its extracted Windows.Win32.winmd SHA256 and assembly
    identity are pinned so the gate cannot drift. The report identifies namespace
    and unique short type-name recall without generating production mapping data.
#>
[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [string]$Baseline,

    [Parameter(Mandatory)]
    [string]$Candidate,

    [string]$Output,

    [string]$ExpectedBaselineSha256 =
        "0C0E5F11543FD654F9FAD44C1952494BF407D6B067D93C2E5EEF4FCF5D42EDDE",

    [string]$ExpectedBaselineAssemblyName = "Windows.Win32.winmd",

    [string]$ExpectedBaselineAssemblyVersion = "0.0.0.0"
)

$ErrorActionPreference = "Stop"
Add-Type -AssemblyName System.Reflection.Metadata

function Get-WinmdCoverage {
    param(
        [Parameter(Mandatory)]
        [string]$Path
    )

    $resolved = (Resolve-Path $Path).Path
    $stream = [System.IO.File]::OpenRead($resolved)
    try {
        $peReader = [System.Reflection.PortableExecutable.PEReader]::new($stream)
        $reader = [System.Reflection.Metadata.PEReaderExtensions]::GetMetadataReader($peReader)
        $assembly = $reader.GetAssemblyDefinition()
        $namespaces = @{}
        $shortNames = [System.Collections.Generic.HashSet[string]]::new(
            [System.StringComparer]::Ordinal)
        $apiMethods = 0
        $apiFields = 0

        foreach ($handle in $reader.TypeDefinitions) {
            $type = $reader.GetTypeDefinition($handle)
            $name = $reader.GetString($type.Name)
            if ($name -eq "<Module>") {
                continue
            }
            $namespace = $reader.GetString($type.Namespace)
            if ($name -eq "Apis") {
                $apiMethods += $type.GetMethods().Count
                $apiFields += $type.GetFields().Count
            }
            if (!$namespace) {
                continue
            }
            if (!$namespaces.ContainsKey($namespace)) {
                $namespaces[$namespace] = [System.Collections.Generic.HashSet[string]]::new(
                    [System.StringComparer]::Ordinal)
            }
            $null = $namespaces[$namespace].Add($name)
            if ($name -ne "Apis") {
                $null = $shortNames.Add($name)
            }
        }

        [pscustomobject]@{
            path = $resolved
            bytes = $stream.Length
            sha256 = (Get-FileHash $resolved -Algorithm SHA256).Hash
            assemblyName = $reader.GetString($assembly.Name)
            assemblyVersion = $assembly.Version.ToString()
            namespaceCount = $namespaces.Count
            namespaces = $namespaces
            uniqueShortNames = $shortNames
            uniqueShortNameCount = $shortNames.Count
            apiMethods = $apiMethods
            apiFields = $apiFields
            tables = [pscustomobject]@{
                typeDefinitions = $reader.TypeDefinitions.Count
                methodDefinitions = $reader.MethodDefinitions.Count
                fieldDefinitions = $reader.FieldDefinitions.Count
                customAttributes = $reader.CustomAttributes.Count
            }
        }
    }
    finally {
        if ($peReader) {
            $peReader.Dispose()
        }
        $stream.Dispose()
    }
}

function Get-SortedDifference {
    param(
        [Parameter(Mandatory)]
        [AllowEmptyCollection()]
        [System.Collections.Generic.HashSet[string]]$Left,

        [Parameter(Mandatory)]
        [AllowEmptyCollection()]
        [System.Collections.Generic.HashSet[string]]$Right
    )

    @($Left | Where-Object { !$Right.Contains($_) } | Sort-Object)
}

$baselineCoverage = Get-WinmdCoverage $Baseline
$candidateCoverage = Get-WinmdCoverage $Candidate
if ($ExpectedBaselineSha256 -and
    $baselineCoverage.sha256 -ne $ExpectedBaselineSha256.ToUpperInvariant()) {
    throw "Baseline SHA256 is $($baselineCoverage.sha256), expected $ExpectedBaselineSha256."
}
if ($ExpectedBaselineAssemblyName -and
    $baselineCoverage.assemblyName -ne $ExpectedBaselineAssemblyName) {
    throw "Baseline assembly name is '$($baselineCoverage.assemblyName)', expected '$ExpectedBaselineAssemblyName'."
}
if ($ExpectedBaselineAssemblyVersion -and
    $baselineCoverage.assemblyVersion -ne $ExpectedBaselineAssemblyVersion) {
    throw "Baseline assembly version is '$($baselineCoverage.assemblyVersion)', expected '$ExpectedBaselineAssemblyVersion'."
}
$missingNamespaces = @(
    $baselineCoverage.namespaces.Keys |
        Where-Object { !$candidateCoverage.namespaces.ContainsKey($_) } |
        Sort-Object
)
$newNamespaces = @(
    $candidateCoverage.namespaces.Keys |
        Where-Object { !$baselineCoverage.namespaces.ContainsKey($_) } |
        Sort-Object
)
$missingShortNames = Get-SortedDifference `
    -Left $baselineCoverage.uniqueShortNames `
    -Right $candidateCoverage.uniqueShortNames
$newShortNames = Get-SortedDifference `
    -Left $candidateCoverage.uniqueShortNames `
    -Right $baselineCoverage.uniqueShortNames

$namespaceRecall = foreach ($namespace in ($baselineCoverage.namespaces.Keys | Sort-Object)) {
    $baselineNames = $baselineCoverage.namespaces[$namespace]
    $candidateNames = [System.Collections.Generic.HashSet[string]]::new(
        [System.StringComparer]::Ordinal)
    if ($candidateCoverage.namespaces.ContainsKey($namespace)) {
        $candidateNames = $candidateCoverage.namespaces[$namespace]
    }
    $missing = Get-SortedDifference -Left $baselineNames -Right $candidateNames
    [pscustomobject]@{
        namespace = $namespace
        baseline = $baselineNames.Count
        candidate = $candidateNames.Count
        matched = $baselineNames.Count - $missing.Count
        recall = if ($baselineNames.Count) {
            [Math]::Round(($baselineNames.Count - $missing.Count) / $baselineNames.Count, 6)
        }
        else {
            1
        }
        missing = $missing
    }
}

function Select-SerializableCoverage {
    param(
        [Parameter(Mandatory)]
        $Coverage
    )

    [pscustomobject]@{
        path = $Coverage.path
        bytes = $Coverage.bytes
        sha256 = $Coverage.sha256
        assemblyName = $Coverage.assemblyName
        assemblyVersion = $Coverage.assemblyVersion
        namespaceCount = $Coverage.namespaceCount
        uniqueShortNameCount = $Coverage.uniqueShortNameCount
        apiMethods = $Coverage.apiMethods
        apiFields = $Coverage.apiFields
        tables = $Coverage.tables
    }
}

$report = [pscustomobject]@{
    authoritativeReference = [pscustomobject]@{
        packageId = "Microsoft.Windows.SDK.Win32Metadata"
        packageVersion = "71.0.26-preview"
        packageSha256 = "758EFE32666596B8596C58A8C46631DA23757A914713B4E88403BBFA5110CB38"
        winmdSha256 = "0C0E5F11543FD654F9FAD44C1952494BF407D6B067D93C2E5EEF4FCF5D42EDDE"
    }
    baseline = Select-SerializableCoverage $baselineCoverage
    candidate = Select-SerializableCoverage $candidateCoverage
    comparison = [pscustomobject]@{
        missingNamespaces = $missingNamespaces
        newNamespaces = $newNamespaces
        missingUniqueShortNames = $missingShortNames
        newUniqueShortNames = $newShortNames
        uniqueShortNameRecall = if ($baselineCoverage.uniqueShortNameCount) {
            [Math]::Round(
                ($baselineCoverage.uniqueShortNameCount - $missingShortNames.Count) /
                    $baselineCoverage.uniqueShortNameCount,
                6)
        }
        else {
            1
        }
        namespaceRecall = @($namespaceRecall)
    }
}

$json = $report | ConvertTo-Json -Depth 8
if ($Output) {
    $outputPath = [System.IO.Path]::GetFullPath($Output)
    New-Item -ItemType Directory -Force -Path (Split-Path $outputPath) | Out-Null
    [System.IO.File]::WriteAllText($outputPath, $json)
}
$json
