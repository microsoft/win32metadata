function Get-WindowsRsArgumentValues {
    param([string[]]$Arguments, [string]$Name)
    for ($i = 0; $i -lt $Arguments.Count; $i++) {
        if ($Arguments[$i] -ceq $Name) {
            if (++$i -ge $Arguments.Count -or $Arguments[$i].StartsWith("--")) {
                throw "Missing value for '$Name'."
            }
            $Arguments[$i]
        }
    }
}

function Assert-WindowsRsOmittedDeclaration {
    param($Declaration)
    if (!$Declaration -or $Declaration.PSObject.Properties.Name -cnotcontains "kind" -or
        $Declaration.origin.tu -isnot [string] -or
        ($Declaration.origin.local -isnot [int] -and $Declaration.origin.local -isnot [long]) -or
        $Declaration.origin.local -lt 0 -or $Declaration.origin.local -gt [uint32]::MaxValue -or
        ($null -ne $Declaration.kind -and $Declaration.kind -isnot [string]) -or
        $Declaration.name -isnot [string] -or $Declaration.namespace -isnot [string] -or
        $Declaration.source.file -isnot [string] -or
        ($Declaration.source.offset -isnot [int] -and $Declaration.source.offset -isnot [long]) -or
        $Declaration.source.offset -lt 0 -or $Declaration.source.offset -gt [uint32]::MaxValue -or
        $Declaration.methods -isnot [array] -or
        @($Declaration.methods | Where-Object { $_ -isnot [string] }).Count) {
        throw "Invalid omitted declaration in SDK enum diagnostics."
    }
}

function Test-WindowsRsOmittedDeclarationEqual {
    param($Left, $Right)
    if ($Left.origin.tu -cne $Right.origin.tu -or $Left.origin.local -ne $Right.origin.local -or
        $Left.kind -cne $Right.kind -or $Left.name -cne $Right.name -or
        $Left.source.file -cne $Right.source.file -or $Left.source.offset -ne $Right.source.offset -or
        $Left.namespace -cne $Right.namespace -or $Left.methods.Count -ne $Right.methods.Count) {
        return $false
    }
    for ($i = 0; $i -lt $Left.methods.Count; $i++) {
        if ($Left.methods[$i] -cne $Right.methods[$i]) { return $false }
    }
    return $true
}

function Get-WindowsRsEnumDiagnostics {
    param([string]$OutputPath, [string[]]$Architectures = @())
    $path = [IO.Path]::GetFullPath($OutputPath) + ".enum-diagnostics.json"
    $report = Get-Content -LiteralPath $path -Raw -ErrorAction Stop | ConvertFrom-Json
    if (($report.schema -isnot [int] -and $report.schema -isnot [long]) -or
        $report.schema -ne 1 -or $report.partial -isnot [bool] -or
        ($report.omissionCount -isnot [int] -and $report.omissionCount -isnot [long]) -or
        $report.architectures -isnot [array] -or !$report.architectures.Count) {
        throw "Invalid SDK enum diagnostic report: '$path'."
    }
    $seen = [Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
    $count = 0L
    $partial = $false
    foreach ($architecture in $report.architectures) {
        if ($architecture.arch -cnotin @("x64", "x86", "arm64") -or
            !$seen.Add($architecture.arch) -or $architecture.partial -isnot [bool] -or
            $architecture.omissions -isnot [array] -or
            ($architecture.omissionCount -isnot [int] -and $architecture.omissionCount -isnot [long]) -or
            $architecture.omissionCount -ne $architecture.omissions.Count -or
            $architecture.partial -ne ($architecture.omissionCount -gt 0)) {
            throw "Invalid architecture entry in SDK enum diagnostics: '$path'."
        }
        foreach ($omission in $architecture.omissions) {
            if ($omission.cause -cnotin @("ConflictingDeclarations", "ExcludedDependency") -or
                $omission.reason -isnot [string] -or $omission.dependencyChain -isnot [array] -or
                !$omission.dependencyChain.Count) {
                throw "Invalid omission entry in SDK enum diagnostics: '$path'."
            }
            Assert-WindowsRsOmittedDeclaration $omission.declaration
            foreach ($declaration in $omission.dependencyChain) {
                Assert-WindowsRsOmittedDeclaration $declaration
            }
            if (!(Test-WindowsRsOmittedDeclarationEqual $omission.declaration $omission.dependencyChain[0]) -or
                $omission.dependencyChain[-1].kind -cne "Enum") {
                throw "SDK enum dependency chain must begin with its omitted declaration and end with an enum: '$path'."
            }
        }
        $count += $architecture.omissionCount
        $partial = $partial -or $architecture.partial
    }
    if ($report.omissionCount -ne $count -or $report.partial -ne $partial -or
        ($Architectures.Count -and (Compare-Object @($seen | Sort-Object) @($Architectures | Sort-Object) -CaseSensitive))) {
        throw "SDK enum diagnostic totals or architecture scope do not match: '$path'."
    }
    [pscustomobject]@{
        path = $path
        sha256 = (Get-FileHash -LiteralPath $path -ErrorAction Stop).Hash
        partial = $report.partial
        omissionCount = $report.omissionCount
    }
}

function Get-WindowsRsGenerationProvenance {
    param(
        [string]$OutputPath,
        [string]$PreparationPath,
        [string]$PreparedRoot,
        [switch]$VerifyCiInvocation
    )
    $output = [IO.Path]::GetFullPath($OutputPath)
    $receipt = Get-Content -LiteralPath "$output.provenance.json" -Raw -ErrorAction Stop | ConvertFrom-Json
    $includes = @(Get-WindowsRsArgumentValues $receipt.arguments "--include")
    if ($receipt.schema -ne 1 -or $receipt.output -ine $output -or
        !$receipt.arguments.Count -or $receipt.arguments[0] -cne "scrape" -or
        $receipt.outputSha256 -cne (Get-FileHash -LiteralPath $output -ErrorAction Stop).Hash -or
        $receipt.preparation -ine [IO.Path]::GetFullPath($PreparationPath) -or
        $receipt.preparationSha256 -cne (Get-FileHash -LiteralPath $PreparationPath -ErrorAction Stop).Hash -or
        $receipt.toolSha256 -cne (Get-FileHash -LiteralPath $receipt.tool -ErrorAction Stop).Hash -or
        !$includes.Count -or [IO.Path]::GetFullPath($includes[0]) -ine [IO.Path]::GetFullPath($PreparedRoot)) {
        throw "Generation provenance does not match the prepared inputs/tool/output: '$output'."
    }
    if ($VerifyCiInvocation) {
        foreach ($option in @("--original-compilation", "--win32-sdk")) {
            if (@($receipt.arguments | Where-Object { $_ -ceq $option }).Count -ne 1) {
                throw "CI generation requires exactly one $option."
            }
        }
        foreach ($option in @("--architecture-jobs", "--native-jobs")) {
            $values = @(Get-WindowsRsArgumentValues $receipt.arguments $option)
            if ($values.Count -ne 1 -or $values[0] -cne "1") {
                throw "CI generation requires exactly one $option with positive value 1."
            }
        }
        foreach ($option in @("--partition-policy-root", "--namespace-routes")) {
            $values = @(Get-WindowsRsArgumentValues $receipt.arguments $option)
            if ($values.Count -ne 1 -or [string]::IsNullOrWhiteSpace($values[0])) {
                throw "CI generation requires exactly one $option with a value."
            }
        }
        $architectures = @(Get-WindowsRsArgumentValues $receipt.arguments "--arch")
        if (($architectures -join ";") -cne "x64;x86;arm64") {
            throw "CI generation architecture scope must be exactly x64;x86;arm64."
        }
    }
    if ($receipt.arguments -ccontains "--win32-sdk" -and
        @(Get-WindowsRsArgumentValues $receipt.arguments "--partition-policy-root").Count) {
        $architectures = @(Get-WindowsRsArgumentValues $receipt.arguments "--arch")
        if (!$architectures.Count) { $architectures = @("x64") }
        $diagnostics = Get-WindowsRsEnumDiagnostics -OutputPath $output -Architectures $architectures
        $status = if ($diagnostics.partial) { "partial" } else { "complete" }
        if (!$receipt.enumDiagnostics -or
            $receipt.enumDiagnostics.path -ine $diagnostics.path -or
            $receipt.enumDiagnostics.sha256 -cne $diagnostics.sha256 -or
            $receipt.enumDiagnostics.partial -isnot [bool] -or
            $receipt.enumDiagnostics.partial -ne $diagnostics.partial -or
            ($receipt.enumDiagnostics.omissionCount -isnot [int] -and $receipt.enumDiagnostics.omissionCount -isnot [long]) -or
            $receipt.enumDiagnostics.omissionCount -ne $diagnostics.omissionCount -or
            $receipt.metadataStatus -cne $status) {
            throw "Generation provenance does not match SDK enum diagnostics: '$output'."
        }
    }
    $receipt
}
