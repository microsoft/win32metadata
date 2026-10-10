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
    $receipt
}
