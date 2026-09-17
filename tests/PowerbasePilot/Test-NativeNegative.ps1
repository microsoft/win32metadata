[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SdkInclude,
    [Parameter(Mandatory)][string]$CandidateInclude,
    [Parameter(Mandatory)][string]$Libclang,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)

$ErrorActionPreference = 'Stop'
if (Test-Path $OutputDirectory) { throw "Negative-test output already exists: $OutputDirectory" }
$headers = Join-Path $OutputDirectory 'headers'
New-Item -ItemType Directory -Force -Path $headers | Out-Null
$source = [IO.File]::ReadAllText((Join-Path $CandidateInclude 'powerbase.h'))
$before = '_In_ _Win32_AssociatedEnum_(POWER_PLATFORM_ROLE_VERSION) ULONG Version'
$after = '_In_ _Win32_AssociatedEnum_(POWER_PLATFORM_ROLE_VERSION) ULONGLONG Version'
if ([regex]::Matches($source, [regex]::Escape($before)).Count -ne 1) {
    throw 'Native negative mutation must match exactly one declaration.'
}
$mutated = Join-Path $headers 'powerbase.h'
[IO.File]::WriteAllText($mutated, $source.Replace($before, $after), [Text.UTF8Encoding]::new($false))
$failure = $null
try {
    & (Join-Path $PSScriptRoot '..\..\scripts\Test-PowerbaseNative.ps1') `
        -SdkInclude $SdkInclude -CandidateInclude $headers -Libclang $Libclang `
        -ResourceDirectory $ResourceDirectory -OutputDirectory (Join-Path $OutputDirectory 'native')
} catch {
    $failure = $_.Exception.Message
}
if ($failure -notlike 'Native declaration changed: FunctionDecl:PowerDeterminePlatformRoleEx*') {
    throw "Native type mutation was not rejected by the intended contract gate. Actual: $failure"
}
[ordered]@{
    case='native ULONG parameter widened to ULONGLONG'
    mutationBefore=$before; mutationAfter=$after
    mutatedHeaderSha256=(Get-FileHash $mutated).Hash
    result='rejected by native contract comparison'; diagnostic=$failure
} | ConvertTo-Json | Set-Content -Encoding utf8 (Join-Path $OutputDirectory 'result.json')
Write-Host 'Native negative control rejected the changed parameter type.'
