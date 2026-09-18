[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SdkInclude,
    [Parameter(Mandatory)][string]$CandidateInclude,
    [Parameter(Mandatory)][string]$Libclang,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
if(Test-Path $OutputDirectory){throw "Native evidence exists: $OutputDirectory"}
New-Item -ItemType Directory -Path $OutputDirectory | Out-Null
if(-not ('PowerbaseNativeProbe' -as [type])){Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs')}
function Native-Value($Value){
    if($null -eq $Value){return $null}
    if($Value -is [Collections.IDictionary]){
        $copy=[ordered]@{}
        foreach($key in @($Value.Keys | Sort-Object -CaseSensitive)){
            if($key -notin @('source','annotations')){$copy[$key]=Native-Value $Value[$key]}
        }
        return $copy
    }
    if($Value -is [array]){return ,@($Value | ForEach-Object {Native-Value $_})}
    return $Value
}
$checks=[Collections.Generic.List[object]]::new()
foreach($architecture in @('x64','x86','arm64')){
    foreach($mode in @('c','cpp','metadata')){
        $snapshots=@{}
        foreach($variant in @('control','candidate')){
            $triple=@{x64='x86_64-pc-windows-msvc';x86='i686-pc-windows-msvc';arm64='aarch64-pc-windows-msvc'}[$architecture]
            $arguments=@("--target=$triple",'-x',$(if($mode -eq 'c'){'c'}else{'c++'}),$(if($mode -eq 'c'){'-std=c17'}else{'-std=c++17'}),
                '-fms-compatibility','-ferror-limit=0','-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',$ResourceDirectory)
            if($mode -eq 'metadata'){$arguments+='-DWIN32METADATA=1'}
            $header=Join-Path $SdkInclude 'um\powrprof.h'
            if($variant -eq 'candidate'){
                $arguments+=@('-isystem',$CandidateInclude)
                $header=Join-Path $CandidateInclude 'powrprof.h'
            }
            foreach($include in @((Join-Path $root 'generation\WinSDK\AdditionalHeaders'),(Join-Path $root 'generation\WinSDK\inc'))){$arguments+=@('-isystem',$include)}
            foreach($part in @('shared','um','ucrt','winrt')){$arguments+=@('-isystem',(Join-Path $SdkInclude $part))}
            $snapshot=[PowerbaseNativeProbe]::Capture($Libclang,(Join-Path $PSScriptRoot 'main.cpp'),$header,$arguments)
            $snapshot | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory "$architecture-$mode-$variant.json")
            if($snapshot.hasErrors){throw "Native parse failed: $architecture/$mode/$variant"}
            $snapshots[$variant]=$snapshot
        }
        $before=@{};$after=@{}
        foreach($declaration in $snapshots.control.ownedDeclarations){$before["$($declaration['kind']):$($declaration['name'])"]=$declaration}
        foreach($declaration in $snapshots.candidate.ownedDeclarations){$after["$($declaration['kind']):$($declaration['name'])"]=$declaration}
        if(@(Compare-Object @($before.Keys) @($after.Keys)).Count){throw "Native root inventory changed: $architecture/$mode"}
        foreach($key in $before.Keys){
            $first=Native-Value $before[$key] | ConvertTo-Json -Depth 100 -Compress
            $second=Native-Value $after[$key] | ConvertTo-Json -Depth 100 -Compress
            if($first -cne $second){throw "Native ABI changed: $architecture/$mode/$key"}
            $checks.Add([ordered]@{architecture=$architecture;mode=$mode;symbol=$key;result='unchanged'})
        }
        $first=Native-Value $snapshots.control.dependencyDeclarations | ConvertTo-Json -Depth 100 -Compress
        $second=Native-Value $snapshots.candidate.dependencyDeclarations | ConvertTo-Json -Depth 100 -Compress
        if($first -cne $second){throw "Native dependency closure changed: $architecture/$mode"}
    }
}
$checks.ToArray() | ConvertTo-Json -Depth 10 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory 'checks.json')
Write-Host "$($checks.Count) direct declaration ABI checks passed, including complete callback signatures."
