[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$SdkInclude,
    [Parameter(Mandatory)][string]$Libclang,
    [Parameter(Mandatory)][string]$ResourceDirectory,
    [Parameter(Mandatory)][string]$OutputDirectory
)

$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$output=[IO.Path]::GetFullPath($OutputDirectory)
if(Test-Path $output){throw "Shared prerequisite output already exists: $output"}
New-Item -ItemType Directory -Path $output | Out-Null
if(-not ('PowerbaseNativeProbe' -as [type])){Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs')}
$sdk=[IO.Path]::GetFullPath($SdkInclude)
$sources=@((Join-Path $sdk 'shared\winerror.h'),(Join-Path $sdk 'um\setupapi.h'),(Join-Path $sdk 'um\winnt.h'))
$sourceIdentities=@($sources | ForEach-Object {[ordered]@{path=$_;sha256=(Get-FileHash $_).Hash}})
$definitions=[Collections.Generic.Dictionary[string,object]]::new([StringComparer]::Ordinal)
foreach($source in $sources[0..1]){
    foreach($line in Select-String -LiteralPath $source -Pattern '^\s*#\s*define\s+(?<name>[A-Za-z_]\w*)\b(?<body>.*)$'){
        $match=$line.Matches[0]
        $name=$match.Groups['name'].Value
        $selected=if($source -ceq $sources[0]){
            $name -cmatch '^(ERROR_|DNS_ERROR_|APPMODEL_ERROR_)' -or $name -ceq 'NO_ERROR'
        }else{$name -cmatch '^ERROR_'}
        if(-not $selected){continue}
        if($definitions.ContainsKey($name)){throw "Ambiguous source macro definition: $name"}
        $definitions.Add($name,[ordered]@{name=$name;file=$source;line=$line.LineNumber;body=$match.Groups['body'].Value.Trim()})
    }
}
[string[]]$names=@($definitions.Keys)
[Array]::Sort($names,[StringComparer]::Ordinal)
$probe=Join-Path $output 'values.cpp'
$lines=[Collections.Generic.List[string]]::new()
$lines.Add('#include <windows.h>')
$lines.Add('#include <setupapi.h>')
$lines.Add('enum SharedErrorValues : unsigned long {')
foreach($name in $names){$lines.Add("    V_$name = static_cast<unsigned long>($name),")}
$lines.Add('};')
foreach($name in $names){$lines.Add("const auto T_$name = $name;")}
[IO.File]::WriteAllLines($probe,$lines,[Text.UTF8Encoding]::new($false))

$manifest=[ordered]@{
    status='evaluating source';classification='source-backed pilot prerequisite/bridge, not shipped SDK-header annotation migration'
    selection='winerror.h ERROR_/DNS_ERROR_/APPMODEL_ERROR_ and NO_ERROR; setupapi.h ERROR_; exclude compiler-typed HRESULT'
    sources=$sourceIdentities;rawCandidateCount=$names.Count;architectures=@('x64','x86','arm64')
    compiler=(Get-FileHash $Libclang).Hash;implementation=(Get-FileHash $PSCommandPath).Hash
    probes=[Collections.Generic.List[object]]::new()
}
function Capture-Probe([string]$File,[string]$Header,[string]$Architecture,[bool]$Metadata,[string]$Label){
    $triple=@{x64='x86_64-pc-windows-msvc';x86='i686-pc-windows-msvc';arm64='aarch64-pc-windows-msvc'}[$Architecture]
    $arguments=@("--target=$triple",'-x','c++','-std=c++17','-fms-compatibility','-ferror-limit=0',
        '-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',$ResourceDirectory,
        '-isystem',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),
        '-isystem',(Join-Path $root 'generation\WinSDK\inc'))
    if($Metadata){$arguments+='-DWIN32METADATA=1'}
    foreach($part in @('shared','um','ucrt','winrt')){$arguments+=@('-isystem',(Join-Path $sdk $part))}
    $snapshot=[PowerbaseNativeProbe]::Capture($Libclang,$File,$Header,$arguments)
    $path=Join-Path $output "$Label-$Architecture.json"
    $snapshot | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 $path
    $manifest.probes.Add([ordered]@{file=$File;header=$Header;arguments=$arguments;snapshot=$path;sha256=(Get-FileHash $path).Hash})
    if($snapshot.hasErrors){throw "Shared source probe failed: $path"}
    return $snapshot
}
try{
    $selectedByArchitecture=@{}
    $excluded=[Collections.Generic.List[object]]::new()
    foreach($architecture in $manifest.architectures){
        $snapshot=Capture-Probe $probe $probe $architecture $true 'values'
        $enum=@($snapshot.ownedDeclarations | Where-Object {$_.name -ceq 'SharedErrorValues'})[0]
        if($enum.underlyingType.size -ne 4 -or $enum.underlyingType.canonical -cne 'unsigned long'){throw 'Shared enum requires native unsigned 32-bit storage.'}
        $types=@{}
        foreach($declaration in $snapshot.ownedDeclarations){
            if($declaration.name -clike 'T_*'){$types[$declaration.name.Substring(2)]=$declaration.type}
        }
        $values=[Collections.Generic.Dictionary[string,object]]::new([StringComparer]::Ordinal)
        foreach($member in $enum.members){
            $name=$member.name.Substring(2)
            $type=$types[$name]
            if($type.spelling -ceq 'const HRESULT'){
                if($architecture -ceq 'x64'){$excluded.Add([ordered]@{source=$definitions[$name];nativeType=$type;reason='native HRESULT, not Win32 error status'})}
                continue
            }
            if($type.size -ne 4 -or $type.canonical -cnotmatch '^const (unsigned )?(long|int)$'){
                throw "Unsupported native error constant type for $name`: $($type | ConvertTo-Json -Compress)"
            }
            $values.Add($name,[ordered]@{name=$name;value=[uint32]$member.unsignedValue;nativeType=$type;source=$definitions[$name]})
        }
        if($enum.members.Count -ne $names.Count){throw "Missing compiler-evaluated source constants on $architecture."}
        $selectedByArchitecture[$architecture]=$values
        if($architecture -cne 'x64'){
            $first=$selectedByArchitecture['x64']
            if($first.Count -ne $values.Count){throw 'Shared error selection differs by architecture.'}
            foreach($name in $first.Keys){
                if(-not $values.ContainsKey($name) -or $first[$name].value -ne $values[$name].value -or
                    $first[$name].nativeType.canonical -cne $values[$name].nativeType.canonical){
                    throw "Shared error contract differs by architecture: $name"
                }
            }
        }
    }
    $values=$selectedByArchitecture['x64']
    [string[]]$selectedNames=@($values.Keys)
    [Array]::Sort($selectedNames,[StringComparer]::Ordinal)
    $generated=Join-Path $output 'generated'
    New-Item -ItemType Directory -Path $generated | Out-Null
    $header=Join-Path $generated 'win32_error_metadata.h'
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add('#pragma once')
    $lines.Add('#ifdef WIN32METADATA')
    $lines.Add('static_assert(sizeof(unsigned long) == 4, "WIN32_ERROR storage");')
    foreach($name in $selectedNames){
        $literal='0x{0:X8}UL' -f $values[$name].value
        $lines.Add("static_assert(static_cast<unsigned long>($name) == $literal, `"$name source value`");")
    }
    foreach($name in $selectedNames){
        $lines.Add("#pragma push_macro(`"$name`")")
        $lines.Add("#undef $name")
    }
    $lines.Add('enum WIN32_ERROR : unsigned long {')
    foreach($name in $selectedNames){$lines.Add(('    {0} = 0x{1:X8}UL,' -f $name,$values[$name].value))}
    $lines.Add('};')
    for($index=$selectedNames.Count-1;$index -ge 0;$index--){$lines.Add("#pragma pop_macro(`"$($selectedNames[$index])`")")}
    $lines.Add('#endif')
    [IO.File]::WriteAllLines($header,$lines,[Text.UTF8Encoding]::new($false))

    $verification=Join-Path $output 'verify.cpp'
    $lines=[Collections.Generic.List[string]]::new()
    $lines.Add('#include <windows.h>')
    $lines.Add('#include <setupapi.h>')
    foreach($name in $selectedNames){$lines.Add("typedef decltype($name) Before_$name;")}
    $lines.Add('#include "generated\win32_error_metadata.h"')
    foreach($name in $selectedNames){
        $literal='0x{0:X8}UL' -f $values[$name].value
        $lines.Add("static_assert(__is_same(decltype($name), Before_$name), `"$name native type`");")
        $lines.Add("static_assert(static_cast<unsigned long>($name) == $literal, `"$name restored value`");")
    }
    [IO.File]::WriteAllLines($verification,$lines,[Text.UTF8Encoding]::new($false))
    foreach($architecture in $manifest.architectures){
        foreach($metadata in @($false,$true)){
            $label=if($metadata){'restoration-metadata'}else{'restoration-native'}
            $snapshot=Capture-Probe $verification $header $architecture $metadata $label
            $owned=@($snapshot.ownedDeclarations)
            if(-not $metadata -and $owned.Count -ne 0){throw 'Shared header changes native declarations with annotations disabled.'}
            if($metadata -and ($owned.Count -ne 1 -or $owned[0].name -cne 'WIN32_ERROR' -or $owned[0].members.Count -ne $values.Count)){
                throw 'Shared header does not declare exactly the complete metadata-only enum.'
            }
        }
    }
    foreach($identity in $sourceIdentities){
        if((Get-FileHash $identity.path).Hash -cne $identity.sha256){throw "SDK source changed during generation: $($identity.path)"}
    }
    $selectedRecords=@($selectedNames | ForEach-Object {$values[$_]})
    $selectedRecords | ConvertTo-Json -Depth 30 | Set-Content -Encoding utf8 (Join-Path $output 'members.json')
    $excluded.ToArray() | ConvertTo-Json -Depth 30 | Set-Content -Encoding utf8 (Join-Path $output 'excluded-hresult.json')
    $manifest.header=[ordered]@{path=$header;bytes=(Get-Item $header).Length;sha256=(Get-FileHash $header).Hash}
    $manifest.memberCount=$values.Count
    $manifest.excludedHresultCount=$excluded.Count
    $manifest.sourceMemberCounts=@($selectedRecords | ForEach-Object {[pscustomobject]$_.source} | Group-Object file | ForEach-Object {[ordered]@{file=$_.Name;count=$_.Count}})
    $manifest.status='source-generated; all architectures agree; native macro types/values restored'
}catch{
    $manifest.status='failed'
    $manifest.error=$_.Exception.Message
    throw
}finally{
    $manifest | ConvertTo-Json -Depth 40 | Set-Content -Encoding utf8 (Join-Path $output 'manifest.json')
}
Write-Host "Generated source-backed shared bridge: $($manifest.memberCount) members, $($manifest.excludedHresultCount) HRESULT exclusions."
return $manifest
