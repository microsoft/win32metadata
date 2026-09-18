[CmdletBinding()]
param(
    [Parameter(Mandatory)][string]$OutputDirectory,
    [Parameter(Mandatory)][string]$ResourceDirectory
)

$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$output=[IO.Path]::GetFullPath($OutputDirectory)
if(Test-Path $output){throw "Inventory already exists: $output"}
New-Item -ItemType Directory -Path $output | Out-Null
$packages=if($env:NUGET_PACKAGES){$env:NUGET_PACKAGES}else{Join-Path $HOME '.nuget\packages'}
$sdk=Join-Path $packages 'microsoft.windows.sdk.cpp\10.0.26100.7705\c\Include\10.0.26100.0'
$header=Join-Path $sdk 'um\powrprof.h'
$checkedIn=Join-Path $root 'generation\WinSDK\RecompiledIdlHeaders\um\powrprof.h'
$libclang=Join-Path $packages 'libclang.runtime.win-x64\22.1.8\runtimes\win-x64\native\libclang.dll'
$resource=[IO.Path]::GetFullPath($ResourceDirectory)
if((Get-FileHash $header).Hash -cne (Get-FileHash $checkedIn).Hash){throw 'SDK and repository powrprof.h differ.'}
function Save($Value,[string]$Name){ConvertTo-Json -InputObject $Value -Depth 100 | Set-Content -Encoding utf8 (Join-Path $output $Name)}
if(-not ('PowerbaseNativeProbe' -as [type])){Add-Type -Path (Join-Path $root 'tests\PowerbasePilot\NativeProbe.cs')}
$text=[IO.File]::ReadAllText($header)
$functions=@([regex]::Matches($text,'STDAPI_\((?<return>[^\)]+)\)\s*(?<name>\w+)\s*\(') | ForEach-Object {
    [ordered]@{name=$_.Groups['name'].Value;returnType=$_.Groups['return'].Value;line=1+($text.Substring(0,$_.Index).Split("`n").Length-1)}
})
$macros=@([regex]::Matches($text,'(?m)^#define\s+(?<name>\w+)(?<value>[^\r\n]*)') | Where-Object {$_.Groups['name'].Value -cne '_POWRPROF_H_'} | ForEach-Object {
    [ordered]@{name=$_.Groups['name'].Value;expression=$_.Groups['value'].Value.Trim();line=1+($text.Substring(0,$_.Index).Split("`n").Length-1)}
})
$probe=Join-Path $output 'macro-values.cpp'
$probeLines=@('#include <windows.h>','#include <powrprof.h>','enum PowrprofMacroValues : unsigned long long {')+
    @($macros | ForEach-Object {"    V_$($_.name) = static_cast<unsigned long long>($($_.name)),"})+@('};')+
    @($macros | ForEach-Object {"constexpr auto T_$($_.name) = $($_.name);"})
[IO.File]::WriteAllLines($probe,$probeLines,[Text.UTF8Encoding]::new($false))
$architectures=@{}
foreach($architecture in @('x64','x86','arm64')){
    $triple=@{x64='x86_64-pc-windows-msvc';x86='i686-pc-windows-msvc';arm64='aarch64-pc-windows-msvc'}[$architecture]
    $arguments=@("--target=$triple",'-x','c++','-std=c++17','-fms-compatibility','-ferror-limit=0','-D_COM_NO_STANDARD_GUIDS_=1','-resource-dir',$resource)
    foreach($include in @((Join-Path $root 'generation\WinSDK\AdditionalHeaders'),(Join-Path $root 'generation\WinSDK\inc'))){$arguments+=@('-isystem',$include)}
    foreach($part in @('shared','um','ucrt','winrt')){$arguments+=@('-isystem',(Join-Path $sdk $part))}
    $native=[PowerbaseNativeProbe]::Capture($libclang,(Join-Path $PSScriptRoot 'main.cpp'),$header,$arguments)
    Save $native "native-$architecture.json"
    if($native.hasErrors){throw "Native inventory failed on $architecture"}
    $values=[PowerbaseNativeProbe]::Capture($libclang,$probe,$probe,$arguments)
    Save $values "macro-values-$architecture.json"
    if($values.hasErrors){throw "Macro evaluation failed on $architecture"}
    $architectures[$architecture]=$native
}
$owned=@($architectures.x64.ownedDeclarations)
$names=@($owned.name | Select-Object -Unique)+@($macros.name)+@($owned | ForEach-Object {$_.members.name})
$baseline=Join-Path $packages 'microsoft.windows.sdk.win32metadata\70.0.11-preview\Windows.Win32.winmd'
$reader=Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
$arguments=@($reader,'contracts','--winmd',$baseline,'--output',(Join-Path $output 'reference.json'))
foreach($name in $names | Where-Object {$_} | Select-Object -Unique){$arguments+=@('--root',$name)}
& dotnet @arguments *> (Join-Path $output 'reference.log')
if($LASTEXITCODE -ne 0){throw 'Published metadata inventory failed.'}
$legacy='5c5efbc01d4c87f6830ec304d42777991d533154'
$legacyEnums=git -C $root show "${legacy}:generation/WinSDK/enums.json"
if($LASTEXITCODE -ne 0){throw 'Cannot read pinned legacy enum obligations.'}
$groups=($legacyEnums | ConvertFrom-Json -Depth 100).items
$relevant=@($groups | Where-Object {
    @($_.uses | Where-Object {($_.method -and $_.method -cin $names) -or ($_.struct -and $_.struct -cin $names)}).Count -gt 0 -or
    $_.autoPopulate.header -ieq 'powrprof.h' -or @($_.members | Where-Object name -CIn $macros.name).Count -gt 0
} | ForEach-Object {
    $item=$_ | ConvertTo-Json -Depth 100 | ConvertFrom-Json -AsHashtable -Depth 100
    $item.uses=@($item.uses | Where-Object {($_.method -and $_.method -cin $names) -or ($_.struct -and $_.struct -cin $names)})
    $item
})
Save $relevant 'legacy-enum-obligations.json'
$legacyOs=git -C $root show "${legacy}:generation/WinSDK/supportedOS.rsp"
if($LASTEXITCODE -ne 0){throw 'Cannot read pinned legacy OS obligations.'}
$legacyLastError=git -C $root show "${legacy}:generation/WinSDK/WithSetLastError.rsp"
if($LASTEXITCODE -ne 0){throw 'Cannot read pinned legacy last-error obligations.'}
$os=@($legacyOs | Where-Object {($_ -split '=')[0] -cin $names})
$lastError=@($legacyLastError | Where-Object {$_ -cin $names})
Save ([ordered]@{sourceCommit=$legacy;classification='one-time migration evidence only, not production generator inputs';supportedOS=$os;setLastError=$lastError}) 'legacy-obligations.json'
$inventory=[ordered]@{
    header=[ordered]@{path=$header;sha256=(Get-FileHash $header).Hash}
    sdk='10.0.26100.7705';libclang=[ordered]@{path=$libclang;sha256=(Get-FileHash $libclang).Hash}
    resourceDirectory=$resource;baseline=[ordered]@{path=$baseline;sha256=(Get-FileHash $baseline).Hash}
    functions=$functions;macros=$macros;nativeDeclarationCounts=@($owned | Group-Object {$_['kind']} | Select-Object Name,Count)
    directDeclarations=$owned;dependencyDeclarations=$architectures.x64.dependencyDeclarations
}
Save $inventory 'inventory.json'
$inventory.nativeDeclarationCounts | Format-Table
Write-Host "$($functions.Count) direct functions; $($macros.Count) public macro definitions; inventory $output"
