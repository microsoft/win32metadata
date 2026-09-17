[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$EvidenceDirectory,
    [string]$ResourceDirectory,
    [string]$ReferenceEvidence,
    [string]$ToolPath,
    [string]$ToolSha256,
    [string]$ToolSourceRoot
)

$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
& dotnet build (Join-Path $root 'sources\WinmdUtils\WinmdUtils.csproj') -c Release --verbosity quiet
if($LASTEXITCODE -ne 0){throw 'Failed to build metadata contract reader.'}
& "$PSScriptRoot\Generate-PowerbaseEvidence.ps1" -EvidenceDirectory $evidence `
    -ResourceDirectory $ResourceDirectory -ReferenceEvidence $ReferenceEvidence `
    -ToolPath $ToolPath -ToolSha256 $ToolSha256 -ToolSourceRoot $ToolSourceRoot
$manifest=Get-Content (Join-Path $evidence 'manifest.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$header=$manifest.nativeHeader.path
$sdk=Split-Path (Split-Path $header)
$candidate=Join-Path $evidence 'candidate\headers\um'
$libclang=@($manifest.inputs | Where-Object {$_.path -like '*\libclang.dll'})[0].path
$nativeArgs=@{
    SdkInclude=$sdk; CandidateInclude=$candidate; Libclang=$libclang; ResourceDirectory=$manifest.resourceDirectory
}
$manifest['verificationImplementation']=@(
    $paths=@(
        'scripts\Test-PowerbasePilot.ps1','scripts\Test-PowerbaseNative.ps1',
        'scripts\Compare-PowerbaseEvidence.ps1','scripts\Test-PowerbaseLogical.ps1',
        'tests\PowerbasePilot\NativeProbe.cs','tests\PowerbasePilot\macros.cpp',
        'tests\PowerbasePilot\Test-NativeNegative.ps1','tests\PowerbasePilot\Test-MetadataNegative.ps1',
        'sources\MetadataUtils\WinmdContractSnapshot.cs','sources\MetadataUtils\ContractTypeProvider.cs',
        'sources\MetadataUtils\ContractAttributeDecoder.cs','sources\MetadataUtils\ContractMarshalling.cs',
        'sources\WinmdUtils\Program.cs'
    )
    foreach($relative in $paths){
        $path=Join-Path $root $relative
        [ordered]@{path=$relative;sha256=(Get-FileHash $path).Hash}
    }
)
try {
    & "$PSScriptRoot\Test-PowerbaseNative.ps1" @nativeArgs -OutputDirectory (Join-Path $evidence 'native')
    & "$PSScriptRoot\Compare-PowerbaseEvidence.ps1" -EvidenceDirectory $evidence
    & "$PSScriptRoot\Test-PowerbaseLogical.ps1" -EvidenceDirectory $evidence
    & (Join-Path $root 'tests\PowerbasePilot\Test-NativeNegative.ps1') @nativeArgs -OutputDirectory (Join-Path $evidence 'negative-native')
    & (Join-Path $root 'tests\PowerbasePilot\Test-MetadataNegative.ps1') -EvidenceDirectory $evidence
    $logical=Get-Content (Join-Path $evidence 'logical\verdict.json') -Raw | ConvertFrom-Json
    $manifest['verification']=[ordered]@{
        nativeContracts='passed'; nativeMutation='rejected'; metadataMutations='all three rejected'
        logicalEquivalence=$logical.equivalent
        scope='only powerbase.h and explicitly inventoried dependencies; not full SDK'
    }
    $manifest['status']=if($logical.equivalent){'verified logical equivalence'}else{'verified evidence; unresolved logical differences'}
} catch {
    $manifest['status']='verification failed'
    $manifest['verificationError']=$_.Exception.Message
    throw
} finally {
    $manifest['verificationFiles']=@(
        foreach($directory in @('native','comparison','logical','negative-native','negative-metadata')){
            $path=Join-Path $evidence $directory
            if(Test-Path $path){
                Get-ChildItem $path -Recurse -File | Sort-Object FullName | ForEach-Object {
                    [ordered]@{path=$_.FullName;bytes=$_.Length;sha256=(Get-FileHash $_.FullName).Hash}
                }
            }
        }
    )
    $manifest | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 (Join-Path $evidence 'manifest.json')
}
if(-not $logical.equivalent){throw "Pilot evidence is complete, but logical equivalence is not established. See $evidence\logical\REPORT.md."}
Write-Host "Verified powerbase-only logical equivalence: $evidence"
