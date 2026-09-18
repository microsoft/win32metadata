[CmdletBinding()]
param(
    [Parameter(Mandatory)]
    [ValidateSet('bootstrap', 'refresh', 'discover', 'verify', 'status', 'resume', 'retry', 'accept', 'export', 'self-test')]
    [string]$Command,
    [string]$StateDirectory,
    [string]$EvidenceDirectory,
    [string]$ToolPath,
    [string]$ResourceDirectory,
    [ValidateRange(1, 16)][int]$Limit = 1,
    [string]$Partition,
    [string]$Reason,
    [string]$Disposition,
    [string]$OutputDirectory
)
$ErrorActionPreference = 'Stop'
$root = [IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$arguments = @('run', '--project', (Join-Path $root 'tools\AnnotationRollout'), '-c', 'Release', '--', $Command)
if ($Command -ne 'self-test') {
    if (-not $StateDirectory) { throw 'StateDirectory is required.' }
    $arguments += @('--state', [IO.Path]::GetFullPath($StateDirectory))
}
switch ($Command) {
    'bootstrap' {
        foreach ($value in @($EvidenceDirectory, $ToolPath, $ResourceDirectory)) {
            if (-not $value) { throw 'Bootstrap requires EvidenceDirectory, ToolPath and ResourceDirectory.' }
        }
        $arguments += @('--root', $root, '--evidence', [IO.Path]::GetFullPath($EvidenceDirectory),
            '--tool', [IO.Path]::GetFullPath($ToolPath), '--resource', [IO.Path]::GetFullPath($ResourceDirectory))
    }
    'discover' { $arguments += @('--limit', "$Limit") }
    'refresh' { $arguments += @('--evidence', $EvidenceDirectory) }
    'retry' { $arguments += @('--partition', $Partition, '--reason', $Reason) }
    'accept' { $arguments += @('--disposition', $Disposition) }
    'export' { $arguments += @('--output', $OutputDirectory) }
}
& dotnet @arguments
if ($LASTEXITCODE -ne 0) { throw "Annotation rollout $Command failed ($LASTEXITCODE)." }
