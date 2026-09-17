[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)

$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..'))
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
$manifestPath=Join-Path $evidence 'manifest.json'
$manifest=Get-Content $manifestPath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$tool=Join-Path $evidence 'inputs\win32metadata-tools.exe'
if((Get-FileHash $tool).Hash -cne $manifest.tool.sha256){throw 'Archived consumer hash mismatch.'}
$sdk=Split-Path (Split-Path $manifest.nativeHeader.path)
$libclang=@($manifest.inputs | Where-Object {$_.path -like '*\libclang.dll'})[0].path
$library=@($manifest.inputs | Where-Object {$_.path -like '*\PowrProf.Lib'})[0].path
$shared=Join-Path $evidence 'shared-prerequisite'
$reader=Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
$previousLibclang=$env:LIBCLANG_PATH
$previousResource=$env:CLANG_RESOURCE_DIR
$expectedMethods=@('CallNtPowerInformation','GetPwrCapabilities','PowerDeterminePlatformRoleEx',
    'PowerRegisterSuspendResumeNotification','PowerUnregisterSuspendResumeNotification')
$composition=[ordered]@{
    classification='explicit source-backed pilot prerequisite/bridge; not migrated shipped SDK annotations'
    namespace='Windows.Win32.Foundation';type='WIN32_ERROR';commands=[Collections.Generic.List[object]]::new()
    contracts=[Collections.Generic.List[object]]::new();status='generating'
}
function Invoke-Tool([string[]]$Arguments,[string]$Log){
    $entry=[ordered]@{executable=$tool;arguments=$Arguments;log=$Log;errorLog="$Log.stderr";workingDirectory=$root}
    $composition.commands.Add($entry)
    & $tool @Arguments 1> $Log 2> "$Log.stderr"
    $entry.exitCode=$LASTEXITCODE
    if($LASTEXITCODE -ne 0){throw "Shared composition tool failed: $Log.stderr"}
}
function Assert-Emitted([string]$File,[bool]$FoundationOnly,[string]$SnapshotPath){
    & dotnet $reader contracts --winmd $File --output $SnapshotPath 1> "$SnapshotPath.log" 2> "$SnapshotPath.stderr"
    if($LASTEXITCODE -ne 0){throw "Cannot decode composed metadata: $File"}
    $snapshot=Get-Content $SnapshotPath -Raw | ConvertFrom-Json -AsHashtable -Depth 100
    $enums=@($snapshot.declarations | Where-Object qualifiedName -CEQ 'Windows.Win32.Foundation.WIN32_ERROR')
    if($enums.Count -ne 1){throw 'Shared Foundation enum must resolve exactly once in the emitted image.'}
    $enum=$enums[0]
    $storage=@($enum.fields | Where-Object name -CEQ 'value__')
    $members=@($enum.fields | Where-Object name -CNE 'value__')
    if($storage.Count -ne 1 -or $storage[0].type.name -cne 'UInt32' -or $storage[0].attributes.value -ne 1542){
        throw 'Shared enum storage/visibility flags differ from the required contract.'
    }
    if($members.Count -ne $expectedValues.Count){throw 'Shared enum does not contain the complete compiler-evaluated member set.'}
    foreach($member in $members){
        if(-not $expectedValues.ContainsKey($member.name) -or
            [uint32]$member.constant.value -ne $expectedValues[$member.name] -or
            $member.constant.typeCode -cne 'UInt32' -or $member.attributes.value -ne 32854){
            throw "Emitted shared enum contract mismatch: $($member.name)"
        }
    }
    $apiTypes=@($snapshot.declarations | Where-Object {
        $_.name -notin @('Apis','<Module>') -and $_.namespace -cne 'Windows.Win32.Foundation.Metadata'
    })
    $apis=@($snapshot.declarations | Where-Object name -CEQ 'Apis')
    $methods=@($apis | ForEach-Object {$_.methods})
    if($FoundationOnly){
        if($apiTypes.Count -ne 1 -or $apiTypes[0].qualifiedName -cne $enum.qualifiedName -or
            $methods.Count -ne 0 -or @($apis | ForEach-Object {$_.fields}).Count -ne 0){
            throw 'Foundation scrape exposed helper constants/types or unrelated APIs.'
        }
    }else{
        if(@(Compare-Object $expectedMethods @($methods.name)).Count -ne 0 -or
            @($methods | Where-Object namespace -CNE 'Windows.Win32.System.Power').Count -ne 0){
            throw 'Composed API roots do not come exclusively from the Power component.'
        }
        $seen=[Collections.Generic.HashSet[string]]::new([StringComparer]::Ordinal)
        foreach($type in $snapshot.declarations){
            if(-not $seen.Add($type.qualifiedName)){throw "Duplicate metadata definition: $($type.qualifiedName)"}
            if(@($type.fields | Where-Object name -CEQ 'POWER_PLATFORM_ROLE_CURRENT_VERSION').Count -ne 0){throw 'Removed synthetic version alias reappeared.'}
        }
    }
    $composition.contracts.Add([ordered]@{file=$File;sha256=(Get-FileHash $File).Hash;foundationOnly=$FoundationOnly;
        enum=$enum.qualifiedName;members=$members.Count;storage='UInt32';functions=$methods.Count;snapshot=$SnapshotPath})
}
try{
    $env:LIBCLANG_PATH=Split-Path $libclang
    $env:CLANG_RESOURCE_DIR=$manifest.resourceDirectory
    $generated=& "$PSScriptRoot\Generate-Win32ErrorHeader.ps1" -SdkInclude $sdk -Libclang $libclang `
        -ResourceDirectory $manifest.resourceDirectory -OutputDirectory $shared
    $composition.sourceManifest=Join-Path $shared 'manifest.json'
    $composition.generatedHeader=$generated.header
    $expectedValues=[Collections.Generic.Dictionary[string,uint32]]::new([StringComparer]::Ordinal)
    foreach($member in (Get-Content (Join-Path $shared 'members.json') -Raw | ConvertFrom-Json)){
        $expectedValues.Add($member.name,[uint32]$member.value)
    }
    $arguments=@('scrape','--partition',(Join-Path $root 'tests\PowerbasePilot\shared.cpp'),
        '--include',(Join-Path $shared 'generated'),
        '--include',(Join-Path $root 'generation\WinSDK\AdditionalHeaders'),
        '--include',(Join-Path $root 'generation\WinSDK\inc'),'--include',$sdk,'--lib',$library,
        '--scope','__powerbase_pilot_no_directory_scope__','--scope-header','win32_error_metadata',
        '--namespace','Windows.Win32.Foundation','--arch','x64','--arch','x86','--arch','arm64',
        '--assembly-name','Windows.Win32','--output',(Join-Path $shared 'Windows.Win32.winmd'),
        '--obj',(Join-Path $shared 'obj'))
    Invoke-Tool $arguments (Join-Path $shared 'generation.log')
    foreach($architecture in @('x64','x86','arm64','merged')){
        $file=if($architecture -ceq 'merged'){Join-Path $shared 'Windows.Win32.winmd'}else{Join-Path $shared "obj\Windows.Win32.$architecture.winmd"}
        Assert-Emitted $file $true (Join-Path $shared "$architecture-contract.json")
    }
    $composition['x64MergedReuse']=[Collections.Generic.List[object]]::new()
    foreach($component in @($shared,(Join-Path $evidence 'control'),(Join-Path $evidence 'candidate'))){
        $x64=Join-Path $component 'obj\Windows.Win32.x64.winmd'
        $merged=Join-Path $component 'Windows.Win32.winmd'
        $x64Hash=(Get-FileHash $x64).Hash
        $mergedHash=(Get-FileHash $merged).Hash
        if($x64Hash -cne $mergedHash){throw "Cannot reuse merged RDL as x64 for architecture-dependent component: $component"}
        $composition.x64MergedReuse.Add([ordered]@{component=$component;x64=$x64;merged=$merged;
            x64Sha256=$x64Hash;mergedSha256=$mergedHash;
            reason='Original component WinMDs are byte-identical before composition; merged RDL reuse is valid only for this observed invariant.'})
    }
    foreach($variant in @('control','candidate')){
        $variantRoot=Join-Path $evidence $variant
        $raw=Join-Path $variantRoot 'power-only'
        New-Item -ItemType Directory -Path $raw | Out-Null
        foreach($architecture in @('x64','x86','arm64','merged')){
            $file=if($architecture -ceq 'merged'){Join-Path $variantRoot 'Windows.Win32.winmd'}else{Join-Path $variantRoot "obj\Windows.Win32.$architecture.winmd"}
            $preserved=Join-Path $raw "Windows.Win32.$architecture.winmd"
            Copy-Item $file $preserved
            $manifest.inputs+=@([ordered]@{path=$preserved;bytes=(Get-Item $preserved).Length;sha256=(Get-FileHash $preserved).Hash})
            $rdl=if($architecture -cin @('merged','x64')){'rdl'}else{$architecture}
            Invoke-Tool @('compile','--input',(Join-Path $shared "obj\$rdl"),
                '--input',(Join-Path $variantRoot "obj\$rdl"),'--assembly-name','Windows.Win32','--output',$file) `
                (Join-Path $variantRoot "compose-$architecture.log")
            Assert-Emitted $file $false (Join-Path $variantRoot "$architecture-composed-contract.json")
            foreach($identity in $manifest.inputs | Where-Object path -CEQ $file){
                $identity.bytes=(Get-Item $file).Length
                $identity.sha256=(Get-FileHash $file).Hash
            }
        }
    }
    $composition.status='source-backed Foundation enum and Power roots composed in the same metadata images'
    $manifest.status='composed; logical equivalence not yet evaluated'
}catch{
    $composition.status='failed'
    $composition.error=$_.Exception.Message
    $manifest.status='shared prerequisite failed'
    throw
}finally{
    $manifest['sharedPrerequisite']=$composition
    $manifest | ConvertTo-Json -Depth 100 | Set-Content -Encoding utf8 $manifestPath
    $env:LIBCLANG_PATH=$previousLibclang
    $env:CLANG_RESOURCE_DIR=$previousResource
}
Write-Host "Composed complete source-backed WIN32_ERROR prerequisite: $($expectedValues.Count) members, all architectures."
