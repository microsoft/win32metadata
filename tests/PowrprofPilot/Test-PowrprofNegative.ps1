[CmdletBinding()]
param([Parameter(Mandatory)][string]$EvidenceDirectory)
$ErrorActionPreference='Stop'
$root=[IO.Path]::GetFullPath((Join-Path $PSScriptRoot '..\..'))
$evidence=[IO.Path]::GetFullPath($EvidenceDirectory)
$manifest=Get-Content (Join-Path $evidence 'manifest.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$tool=Join-Path $evidence 'inputs\win32metadata-tools.exe'
if((Get-FileHash $tool).Hash -cne $manifest.tool.sha256){throw 'Negative-test consumer hash mismatch.'}
$reader=Join-Path $root 'bin\Release\net10.0\WinmdUtils.dll'
$positive=Get-Content (Join-Path $evidence 'contracts\candidate-x64.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
$command=@($manifest.commands | Where-Object {$_.arguments[0] -ceq 'scrape' -and $_.arguments -contains (Join-Path $evidence 'candidate\headers')})
if($command.Count -ne 1){throw 'Expected one recorded positive candidate invocation.'}
$header=[IO.File]::ReadAllText((Join-Path $evidence 'candidate\headers\um\powrprof.h'))
$out=Join-Path $evidence 'negative'
New-Item -ItemType Directory -Path $out | Out-Null
$cases=@(
    @{name='removed-return-association';method='PowerReadFriendlyName';old="_Win32_AssociatedEnum_(WIN32_ERROR)`r`nSTDAPI_(DWORD)`r`nPowerReadFriendlyName";new="STDAPI_(DWORD)`r`nPowerReadFriendlyName"},
    @{name='wrong-byte-count-index';method='PowerWritePossibleValue';old='_In_reads_bytes_(BufferSize) UCHAR *Buffer';new='_In_reads_bytes_(PossibleSettingIndex) UCHAR *Buffer'},
    @{name='byte-count-to-elements';method='PWRSCHEMESENUMPROC_V2';callback=$true;old='_In_reads_bytes_(NameSize) LPWSTR Name';new='_In_reads_(NameSize) LPWSTR Name'},
    @{name='native-width-change';method='DevicePowerEnumDevices';old='_In_ ULONG  QueryIndex';new='_In_ ULONGLONG  QueryIndex'}
)
. (Join-Path $root 'scripts\Test-PowerbaseLogical.ps1') -EvidenceDirectory $evidence -FunctionsOnly
$checks=[Collections.Generic.List[object]]::new()
Save-Json $checks.ToArray() (Join-Path $out 'checks.json')
$previousClang=$env:LIBCLANG_PATH;$previousResource=$env:CLANG_RESOURCE_DIR
try{
    $env:LIBCLANG_PATH=Split-Path $manifest.compiler.path
    $env:CLANG_RESOURCE_DIR=$manifest.resourceDirectory
    foreach($case in $cases){
        $directory=Join-Path $out $case.name
        New-Item -ItemType Directory -Path (Join-Path $directory 'headers\um') -Force | Out-Null
        $pattern='(?s)'+[regex]::Escape($case.method)+'\s*\(.*?\);'
        if($case.name -eq 'removed-return-association'){
            if(-not $header.Contains($case.old)){throw 'Mutation context missing.'}
            $changed=$header.Replace($case.old,$case.new)
        }else{
            $match=[regex]::Match($header,$pattern)
            if(-not $match.Success -or -not $match.Value.Contains($case.old)){throw "Mutation context missing: $($case.name)"}
            $changed=$header.Substring(0,$match.Index)+$match.Value.Replace($case.old,$case.new)+$header.Substring($match.Index+$match.Length)
        }
        [IO.File]::WriteAllText((Join-Path $directory 'headers\um\powrprof.h'),$changed,[Text.UTF8Encoding]::new($false))
        $arguments=[Collections.Generic.List[string]]::new()
        for($i=0;$i -lt $command[0].arguments.Count;$i++){
            $value=$command[0].arguments[$i]
            if($value -eq '--arch'){$i++;continue}
            if($value -eq '--include' -and $command[0].arguments[$i+1] -ceq (Join-Path $evidence 'candidate\headers')){
                $arguments.Add($value);$arguments.Add((Join-Path $directory 'headers'));$i++;continue
            }
            if($value -in @('--output','--obj')){
                $arguments.Add($value);$arguments.Add((Join-Path $directory $(if($value -eq '--output'){'Windows.Win32.winmd'}else{'obj'})));$i++;continue
            }
            $arguments.Add($value)
        }
        $arguments.Add('--arch');$arguments.Add('x64')
        & $tool @arguments 1> (Join-Path $directory 'generation.log') 2> (Join-Path $directory 'generation.stderr')
        if($LASTEXITCODE -ne 0){throw "Mutation did not reach contract gate: $($case.name)"}
        & $tool compile --input (Join-Path $evidence 'foundation\obj\rdl') --input (Join-Path $evidence 'registry\obj\rdl') `
            --input (Join-Path $directory 'obj\rdl') --assembly-name Windows.Win32 --output (Join-Path $directory 'Windows.Win32.winmd') *> (Join-Path $directory 'composition.log')
        if($LASTEXITCODE -ne 0){throw "Mutation composition failed: $($case.name)"}
        & dotnet $reader contracts --winmd (Join-Path $directory 'Windows.Win32.winmd') --output (Join-Path $directory 'contracts.json') *> (Join-Path $directory 'decode.log')
        if($LASTEXITCODE -ne 0){throw "Mutation decoding failed: $($case.name)"}
        $negative=Get-Content (Join-Path $directory 'contracts.json') -Raw | ConvertFrom-Json -AsHashtable -Depth 100
        if($case.callback){
            $old=@((Get-Definition $positive $case.method).methods | Where-Object name -CEQ 'Invoke')[0]
            $new=@((Get-Definition $negative $case.method).methods | Where-Object name -CEQ 'Invoke')[0]
        }else{
            $old=@($positive.declarations | ForEach-Object {$_.methods} | Where-Object name -CEQ $case.method)[0]
            $new=@($negative.declarations | ForEach-Object {$_.methods} | Where-Object name -CEQ $case.method)[0]
        }
        $differences=@(Diff-Facts (Effective-Method $old $positive 'positive') (Effective-Method $new $negative 'negative'))
        Save-Json $differences (Join-Path $directory 'differences.json')
        if($differences.Count -eq 0){
            $checks.Add([ordered]@{case=$case.name;method=$case.method;result='FAILED: mutation ignored';differences=0;
                outputHash=(Get-FileHash (Join-Path $directory 'Windows.Win32.winmd')).Hash})
            Save-Json $checks.ToArray() (Join-Path $out 'checks.json')
            throw "Mutation was ignored: $($case.name)"
        }
        $intended=switch($case.name){
            'removed-return-association' {@($differences | Where-Object path -like '/return/type*').Count -gt 0}
            'wrong-byte-count-index' {@($differences | Where-Object path -like '/parameters/5/contract/attributes*').Count -gt 0}
            'byte-count-to-elements' {@($differences | Where-Object path -like '/parameters/2/contract/attributes*').Count -gt 0}
            'native-width-change' {@($differences | Where-Object path -like '/parameters/0/contract/type*').Count -gt 0}
        }
        if(-not $intended){throw "Mutation only changed unrelated contracts: $($case.name)"}
        if($case.name -eq 'native-width-change'){
            $sdk=Split-Path (Split-Path $manifest.header.path)
            $failure=$null
            try{
                & (Join-Path $PSScriptRoot 'Test-PowrprofNative.ps1') -SdkInclude $sdk -CandidateInclude (Join-Path $directory 'headers\um') `
                    -Libclang $manifest.compiler.path -ResourceDirectory $manifest.resourceDirectory -OutputDirectory (Join-Path $directory 'native')
            }catch{
                if($_.Exception.Message -notlike 'Native ABI changed:*FunctionDecl:DevicePowerEnumDevices'){throw}
                $failure=$_.Exception.Message
            }
            if(-not $failure){throw 'Native ABI checker accepted widened ULONG.'}
            $failure | Set-Content -Encoding utf8 (Join-Path $directory 'native-rejection.txt')
        }
        $checks.Add([ordered]@{case=$case.name;method=$case.method;result='compiled then rejected';differences=$differences.Count;
            outputHash=(Get-FileHash (Join-Path $directory 'Windows.Win32.winmd')).Hash})
        Save-Json $checks.ToArray() (Join-Path $out 'checks.json')
    }
}finally{$env:LIBCLANG_PATH=$previousClang;$env:CLANG_RESOURCE_DIR=$previousResource}
Save-Json $checks.ToArray() (Join-Path $out 'checks.json')
Write-Host 'Four actual header mutations compiled and were rejected by contract comparison.'
