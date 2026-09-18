[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SdkInclude,
    [Parameter(Mandatory)][string]$Libclang,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
if(Test-Path $OutputDirectory){throw "Registry bridge output exists: $OutputDirectory"}
New-Item -ItemType Directory -Path (Join-Path $OutputDirectory 'generated') -Force | Out-Null
if(-not ('PowerbaseNativeProbe' -as [type])){Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs')}
$source=Join-Path $SdkInclude 'um\winnt.h'
$sourceHash=(Get-FileHash $source).Hash
$definitions=@(Select-String -LiteralPath $source -Pattern '^#define (KEY_\w+)\s+' | ForEach-Object {
    [ordered]@{name=$_.Matches[0].Groups[1].Value;source=$source;line=$_.LineNumber;text=$_.Line}
})
if($definitions.Count -ne 13){throw "Selected SDK KEY_ family changed: $($definitions.Count); review the complete group."}
$probe=Join-Path $OutputDirectory 'values.cpp'
$lines=@('#include <windows.h>','enum RegistryValues : unsigned long {')+
    @($definitions | ForEach-Object {"    V_$($_.name) = static_cast<unsigned long>($($_.name)),"})+@('};')+
    @($definitions | ForEach-Object {"constexpr auto T_$($_.name) = $($_.name);"})
[IO.File]::WriteAllLines($probe,$lines,[Text.UTF8Encoding]::new($false))
$manifest=[ordered]@{classification='source-backed pilot dependency bridge, not Registry API/header migration';
    source=$source;sourceSha256=$sourceHash;compilerSha256=(Get-FileHash $Libclang).Hash;
    implementationSha256=(Get-FileHash $PSCommandPath).Hash;probes=[Collections.Generic.List[object]]::new()}
function Probe([string]$File,[string]$Header,[string]$Arch,[bool]$Metadata,[string]$Label){
    $triple=@{x64='x86_64-pc-windows-msvc';x86='i686-pc-windows-msvc';arm64='aarch64-pc-windows-msvc'}[$Arch]
    $arguments=@("--target=$triple",'-x','c++','-std=c++17','-fms-compatibility','-ferror-limit=0',
        '-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',$ResourceDirectory)
    if($Metadata){$arguments+='-DWIN32METADATA=1'}
    foreach($include in @((Join-Path $root 'generation\WinSDK\AdditionalHeaders'),(Join-Path $root 'generation\WinSDK\inc'))){$arguments+=@('-isystem',$include)}
    foreach($part in @('shared','um','ucrt','winrt')){$arguments+=@('-isystem',(Join-Path $SdkInclude $part))}
    $snapshot=[PowerbaseNativeProbe]::Capture($Libclang,$File,$Header,$arguments)
    $path=Join-Path $OutputDirectory "$Label-$Arch.json"
    $snapshot | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 $path
    $manifest.probes.Add([ordered]@{path=$path;sha256=(Get-FileHash $path).Hash;arguments=$arguments})
    if($snapshot.hasErrors){throw "Registry source probe failed: $path"}
    return $snapshot
}
$members=@()
foreach($arch in @('x64','x86','arm64')){
    $snapshot=Probe $probe $probe $arch $false 'values'
    $enum=@($snapshot.ownedDeclarations | Where-Object {$_['name'] -ceq 'RegistryValues'})[0]
    $current=@(foreach($definition in $definitions){
        $member=@($enum.members | Where-Object {$_['name'] -ceq "V_$($definition.name)"})[0]
        $native=@($snapshot.ownedDeclarations | Where-Object {$_['name'] -ceq "T_$($definition.name)"})[0]
        [ordered]@{name=$definition.name;value=[uint32]$member.unsignedValue;nativeType=$native.type;source=$definition}
    })
    if($arch -eq 'x64'){$members=$current}
    elseif(($members|ConvertTo-Json -Depth 30 -Compress) -cne ($current|ConvertTo-Json -Depth 30 -Compress)){throw 'Registry values/native types differ by architecture.'}
}
$header=Join-Path $OutputDirectory 'generated\registry_metadata.h'
$lines=@('#pragma once','#ifdef WIN32METADATA')
foreach($member in $members){$lines+="static_assert(static_cast<unsigned long>($($member.name)) == $($member.value)UL, `"source value`");"}
foreach($member in $members){$lines+="#pragma push_macro(`"$($member.name)`")";$lines+="#undef $($member.name)"}
$lines+='enum [[clang::flag_enum]] REG_SAM_FLAGS : unsigned long {'
foreach($member in $members){$lines+="    $($member.name) = $($member.value)UL,"}
$lines+='};'
foreach($member in $members){$lines+="#pragma pop_macro(`"$($member.name)`")"}
$lines+='#endif'
[IO.File]::WriteAllLines($header,$lines,[Text.UTF8Encoding]::new($false))
$verify=Join-Path $OutputDirectory 'verify.cpp'
$lines=@('#include <windows.h>')
foreach($member in $members){$lines+="typedef decltype($($member.name)) Before_$($member.name);"}
$lines+='#include "generated\registry_metadata.h"'
foreach($member in $members){
    $lines+="static_assert(__is_same(decltype($($member.name)), Before_$($member.name)), `"restored native type`");"
    $lines+="static_assert(static_cast<unsigned long>($($member.name)) == $($member.value)UL, `"restored value`");"
}
[IO.File]::WriteAllLines($verify,$lines,[Text.UTF8Encoding]::new($false))
foreach($arch in @('x64','x86','arm64')){
    foreach($metadata in @($false,$true)){
        $snapshot=Probe $verify $header $arch $metadata "restoration-$metadata"
        if(@($snapshot.ownedDeclarations).Count -ne [int]$metadata){throw 'Unexpected declarations in Registry bridge.'}
    }
}
if((Get-FileHash $source).Hash -cne $sourceHash){throw 'SDK source changed during generation.'}
$manifest.members=$members
$manifest.header=[ordered]@{path=$header;sha256=(Get-FileHash $header).Hash}
$manifest.status='13 source-derived members; all architecture/native macro checks passed'
$manifest | ConvertTo-Json -Depth 40 | Set-Content -Encoding utf8 (Join-Path $OutputDirectory 'manifest.json')
return $manifest
