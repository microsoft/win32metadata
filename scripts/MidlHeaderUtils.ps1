function Get-MidlHeaderArguments {
    param(
        [Parameter(Mandatory)][string]$InputFile,
        [Parameter(Mandatory)][string]$OutputDirectory,
        [Parameter(Mandatory)][string]$OutputHeader,
        [Parameter(Mandatory)][string[]]$IncludeDirectories,
        [switch]$ClosedPreprocessing
    )

    $arguments = @(
        $InputFile, '/out', $OutputDirectory, '/header', $OutputHeader,
        '/DUNICODE', '/D_UNICODE', '/DWINVER=0x0A00', '/D_APISET_MINWIN_VERSION=0x010F',
        '/DNTDDI_VERSION=0x0A00000C', '/DBUILD_UMS_ENABLED=0', '/DBUILD_WOW64_ENABLED=0',
        '/DBUILD_ARM64X_ENABLED=0', '/DEXECUTABLE_WRITES_SUPPORT=0',
        '/D_USE_DECLSPECS_FOR_SAL=1', '/D_CONTROL_FLOW_GUARD_SVCTAB=1', '/DMIDL_PASS=1',
        '/D_AMD64_', '/D_WIN64', '/D_WCHAR_T_DEFINED', '/no_stamp', '/nologo',
        '/no_settings_comment', '/lcid', '1033', '/sal', '/amd64', '/target', 'NT100', '/Zp8'
    )
    foreach ($directory in $IncludeDirectories) {
        $arguments += '/I', $directory
    }
    if ($ClosedPreprocessing) {
        $cppArguments = @('/nologo', '/E', '/TC', '/X') +
            @($arguments | Where-Object { $_.StartsWith('/D', [StringComparison]::Ordinal) }) +
            @($IncludeDirectories | ForEach-Object { "/I`"$_`"" })
        $arguments += '/cpp_cmd', 'cl.exe', '/cpp_opt', ($cppArguments -join ' '), '/savePP'
    }
    $arguments
}

function Get-MidlErrorDiagnostics([string]$Text) {
    [regex]::Matches($Text,
        '(?im)^.*(?:\b(?:fatal\s+)?error\s+(?:MIDL|C)\d+\b|\bfatal\s+error\b|\bmidl\s*:\s*error\b).*$') |
        ForEach-Object { $_.Value.TrimEnd() }
}

function Assert-PropsysMidlBaselineDiagnostic([string]$Source, [int]$ExitCode, [string]$Text) {
    $errors = @(Get-MidlErrorDiagnostics $Text)
    if ($Source -cne 'um\propsys.idl' -or $ExitCode -ne 0 -or $errors.Count -ne 1 -or
        $errors[0].Trim() -cne ': error MIDL2337 : unsatisfied forward declaration : tagSERIALIZEDPROPSTORAGE') {
        throw "Not the admitted pristine Propsys MIDL diagnostic (source $Source, exit $ExitCode):`n$Text"
    }
}

function Get-PropsysMidlBaselineProfile([string]$SdkPackageRoot, [string]$MidlCompiler,
    [string]$MidlPreprocessorPath) {
    $SdkPackageRoot = [IO.Path]::GetFullPath($SdkPackageRoot).TrimEnd('\')
    $original = "$SdkPackageRoot\c\include\10.0.26100.0\um\propsys.idl"
    [xml]$nuspec = [IO.File]::ReadAllText("$SdkPackageRoot\microsoft.windows.sdk.cpp.nuspec")
    if ($nuspec.SelectSingleNode("//*[local-name()='metadata']/*[local-name()='version']").InnerText -cne
        '10.0.26100.7705' -or
        [IO.Path]::GetFullPath($MidlCompiler) -ne "$SdkPackageRoot\c\bin\10.0.26100.0\x64\midl.exe") {
        throw 'The Propsys baseline is restricted to the selected 10.0.26100.7705 SDK compiler profile.'
    }
    $files = @(
        @{ role = 'original-idl'; path = $original; sha256 = '1D53E43BDC74CD3884B637B8BA30E2FB6D87F9557904A1AF69C46F75182A41E2' },
        @{ role = 'midl'; path = $MidlCompiler; sha256 = '53CCBCBC2FF14B2D08D029AD07B3D1AA4FF3B103F712199A15248A6CCCF6D2A3' },
        @{ role = 'midlc'; path = "$(Split-Path $MidlCompiler)\midlc.exe"; sha256 = 'D12AFF8A74397601041BEC46552FC8DEE1206DAA97E39600E72A7B1B1A5EF6AB' },
        @{ role = 'cl'; path = $MidlPreprocessorPath; sha256 = (Get-FileHash -LiteralPath $MidlPreprocessorPath).Hash },
        @{ role = 'c1'; path = "$(Split-Path $MidlPreprocessorPath)\c1.dll"
            sha256 = (Get-FileHash -LiteralPath "$(Split-Path $MidlPreprocessorPath)\c1.dll").Hash }
    )
    foreach ($file in $files) {
        if ((Get-FileHash -LiteralPath $file.path -Algorithm SHA256).Hash -cne $file.sha256) {
            throw "The Propsys baseline profile changed: $($file.role)."
        }
    }
    [ordered]@{
        sdkPackageVersion = '10.0.26100.7705'
        files = @($files | ForEach-Object { [ordered]@{ role = $_.role; path = $_.path; sha256 = $_.sha256 } })
    }
}

function Get-PropsysMidlNativeContract([string]$Header) {
    if (!(Test-Path -LiteralPath $Header -PathType Leaf) -or (Get-Item -LiteralPath $Header).Length -lt 177929) {
        throw 'The Propsys baseline requires a complete, nonempty native header.'
    }
    $text = [regex]::Replace([IO.File]::ReadAllText($Header), '(?s)/\*.*?\*/|(?m)//[^\r\n]*', '')
    if ($text -cnotmatch '#ifndef\s+__propsys_h__\b' -or
        $text -cnotmatch '#ifdef\s+__cplusplus\s*\}\s*#endif\s*#endif\s*$' -or
        $text -cmatch '\bstruct\s+tagSERIALIZEDPROPSTORAGE\s*\{') {
        throw 'The Propsys header lost its complete native guard or opaque type contract.'
    }
    $patterns = @(
        @{ count = 1; pattern = '\btypedef\s+struct\s+tagSERIALIZEDPROPSTORAGE\s+SERIALIZEDPROPSTORAGE\s*;' },
        @{ count = 1; pattern = '\btypedef\s+SERIALIZEDPROPSTORAGE\s+__unaligned\s*\*\s*PUSERIALIZEDPROPSTORAGE\s*;' },
        @{ count = 1; pattern = '\btypedef\s+const\s+SERIALIZEDPROPSTORAGE\s+__unaligned\s*\*\s*PCUSERIALIZEDPROPSTORAGE\s*;' }
    )
    foreach ($method in @('SetPropertyStorage', 'GetPropertyStorage', 'GetPropertyStorageBuffer')) {
        $patterns += @{ count = 1; pattern = "(?s)\bvirtual\s+HRESULT\s+STDMETHODCALLTYPE\s+$method\s*\(.*?\)\s*=\s*0\s*;" }
        $patterns += @{ count = $(if ($method -eq 'GetPropertyStorageBuffer') { 1 } else { 2 })
            pattern = "(?s)\bHRESULT\s*\(\s*STDMETHODCALLTYPE\s*\*$method\s*\)\s*\(.*?\)\s*;" }
    }
    foreach ($function in @('PSGetPropertyFromPropertyStorage', 'PSGetNamedPropertyFromPropertyStorage')) {
        $patterns += @{ count = 1; pattern = "(?s)\bPSSTDAPI\s+$function\s*\(.*?\)\s*;" }
    }
    $contract = @(foreach ($pattern in $patterns) {
        $matches = [regex]::Matches($text, $pattern.pattern)
        if ($matches.Count -ne $pattern.count) {
            throw "The Propsys header lost a native opaque-type declaration or pointer/buffer API: $($pattern.pattern)"
        }
        $matches | ForEach-Object {
            $declaration = $_.Value -replace '\s', ''
            if ($pattern.pattern.Contains('GetPropertyStorageBuffer')) {
                # The existing SAL converter materializes the original IDL's [in] DWORD cb.
                $declaration = $declaration -creplace '(?<=,)_In_(?=DWORDcb[,)])', ''
            }
            $declaration
        }
    })
    $interfaces = [regex]::Matches($text, 'MIDL_INTERFACE\("[0-9A-Fa-f-]+"\)\s+\w+\s*:\s*public\s+\w+')
    if (!$interfaces.Count) { throw 'The Propsys header contains no native interface contracts.' }
    $contract += @($interfaces | ForEach-Object { $_.Value -replace '\s', '' })
    $contract -join "`n"
}

function New-PristinePropsysMidlBaseline([string]$SdkPackageRoot, [string]$MidlCompiler,
    [string]$MidlPreprocessorPath, [string]$Directory) {
    $SdkPackageRoot = [IO.Path]::GetFullPath($SdkPackageRoot).TrimEnd('\')
    $profile = Get-PropsysMidlBaselineProfile $SdkPackageRoot $MidlCompiler $MidlPreprocessorPath
    if (Test-Path -LiteralPath $Directory) { throw 'A pristine Propsys control requires a fresh output directory.' }
    [IO.Directory]::CreateDirectory($Directory) | Out-Null
    $include = "$SdkPackageRoot\c\include\10.0.26100.0"
    $header = "$Directory\propsys.h"
    $log = "$Directory\midl.log"
    $arguments = @(Get-MidlHeaderArguments -InputFile "$include\um\propsys.idl" `
        -OutputDirectory $Directory -OutputHeader $header -IncludeDirectories @("$include\shared", "$include\um") `
        -ClosedPreprocessing)
    $environment = @{}
    foreach ($name in @('PATH', 'INCLUDE', 'LIB', 'LIBPATH', 'CL', '_CL_', 'TEMP', 'TMP', 'VSLANG')) {
        $environment[$name] = [Environment]::GetEnvironmentVariable($name, 'Process')
    }
    Push-Location $Directory
    try {
        foreach ($name in @('INCLUDE', 'LIB', 'LIBPATH', 'CL', '_CL_')) {
            [Environment]::SetEnvironmentVariable($name, '', 'Process')
        }
        $env:PATH = "$(Split-Path $MidlPreprocessorPath);$(Split-Path $MidlCompiler);$env:SystemRoot\System32;$env:SystemRoot"
        $env:TEMP = $Directory
        $env:TMP = $Directory
        $env:VSLANG = '1033'
        if ((Get-Command cl.exe -CommandType Application).Source -ne $MidlPreprocessorPath) {
            throw 'The pristine Propsys control did not resolve the pinned C preprocessor.'
        }
        & $MidlCompiler @arguments *> $log
        $exitCode = $LASTEXITCODE
    }
    finally {
        foreach ($name in $environment.Keys) {
            [Environment]::SetEnvironmentVariable($name, $environment[$name], 'Process')
        }
        Pop-Location
    }
    Assert-PropsysMidlBaselineDiagnostic 'um\propsys.idl' $exitCode ([IO.File]::ReadAllText($log))
    if ((Get-FileHash -LiteralPath $header).Hash -cne
        '156FD0D406830642EAA5EDAB11783236893BAF4E5210271B26609E37F5F2997B') {
        throw 'The pristine Propsys control differs from the qualified complete native header.'
    }
    $inputs = [Collections.Generic.Dictionary[string, string]]::new([StringComparer]::OrdinalIgnoreCase)
    foreach ($file in @(Get-ChildItem -LiteralPath $Directory -Filter '*.tmp' -File)) {
        foreach ($match in [regex]::Matches([IO.File]::ReadAllText($file.FullName), '(?m)^\s*#line\s+\d+\s+"([^"]+)"')) {
            $path = [IO.Path]::GetFullPath($match.Groups[1].Value.Replace('\\', '\'))
            if (!$path.StartsWith("$include\", [StringComparison]::OrdinalIgnoreCase)) {
                throw "The pristine Propsys control read a non-SDK input: $path"
            }
            if (!$inputs.ContainsKey($path)) { $inputs.Add($path, (Get-FileHash -LiteralPath $path).Hash) }
        }
    }
    if (!$inputs.ContainsKey("$include\um\propsys.idl")) {
        throw 'The pristine Propsys control did not preserve its actual preprocessed source inputs.'
    }
    $receipt = [ordered]@{
        source = 'um\propsys.idl'
        classification = 'pre-existing-clean-sdk-error'
        profile = $profile
        exitCode = $exitCode
        baselineErrorCount = 1
        diagnostics = @(Get-MidlErrorDiagnostics ([IO.File]::ReadAllText($log)))
        arguments = @($arguments | ForEach-Object { $_.Replace($Directory, '<pristine-control>') })
        log = 'midl.log'
        logSha256 = (Get-FileHash -LiteralPath $log).Hash
        header = 'propsys.h'
        headerSha256 = (Get-FileHash -LiteralPath $header).Hash
        nativeContract = Get-PropsysMidlNativeContract $header
        inputs = @($inputs.Keys | Sort-Object -CaseSensitive | ForEach-Object {
            [ordered]@{ sdkPath = [IO.Path]::GetRelativePath($SdkPackageRoot, $_); sha256 = $inputs[$_] }
        })
    }
    $path = "$Directory\control.json"
    [IO.File]::WriteAllText($path, ($receipt | ConvertTo-Json -Depth 8), [Text.UTF8Encoding]::new($false))
    $path
}

function Assert-PropsysMidlBaseline([string]$Source, [int]$ExitCode, [string]$Text, [string]$Header,
    [string]$Control, [string]$SdkPackageRoot, [string]$MidlCompiler, [string]$MidlPreprocessorPath) {
    Assert-PropsysMidlBaselineDiagnostic $Source $ExitCode $Text
    $profile = Get-PropsysMidlBaselineProfile $SdkPackageRoot $MidlCompiler $MidlPreprocessorPath
    $baseline = Get-Content -LiteralPath $Control -Raw | ConvertFrom-Json
    if ($baseline.source -cne $Source -or $baseline.classification -cne 'pre-existing-clean-sdk-error' -or
        $baseline.baselineErrorCount -ne 1 -or
        ($baseline.profile | ConvertTo-Json -Depth 8 -Compress) -cne ($profile | ConvertTo-Json -Depth 8 -Compress)) {
        throw 'The pristine Propsys control does not bind the selected native source/tool profile.'
    }
    $directory = [IO.Path]::GetDirectoryName($Control)
    if ($baseline.log -cne 'midl.log' -or $baseline.header -cne 'propsys.h' -or
        (Get-FileHash -LiteralPath "$directory\midl.log").Hash -cne $baseline.logSha256 -or
        $baseline.headerSha256 -cne '156FD0D406830642EAA5EDAB11783236893BAF4E5210271B26609E37F5F2997B' -or
        (Get-FileHash -LiteralPath "$directory\propsys.h").Hash -cne $baseline.headerSha256) {
        throw 'The pristine Propsys control log/header evidence changed.'
    }
    Assert-PropsysMidlBaselineDiagnostic $baseline.source $baseline.exitCode ([IO.File]::ReadAllText("$directory\midl.log"))
    if (($baseline.diagnostics -join "`n") -cne
        (@(Get-MidlErrorDiagnostics ([IO.File]::ReadAllText("$directory\midl.log"))) -join "`n")) {
        throw 'The pristine Propsys diagnostic receipt does not match its raw log.'
    }
    $expectedArguments = @(Get-MidlHeaderArguments -InputFile "$SdkPackageRoot\c\include\10.0.26100.0\um\propsys.idl" `
        -OutputDirectory $directory -OutputHeader "$directory\propsys.h" `
        -IncludeDirectories @("$SdkPackageRoot\c\include\10.0.26100.0\shared", "$SdkPackageRoot\c\include\10.0.26100.0\um") `
        -ClosedPreprocessing | ForEach-Object { $_.Replace($directory, '<pristine-control>') })
    if (($baseline.arguments -join "`n") -cne ($expectedArguments -join "`n")) {
        throw 'The pristine Propsys invocation does not match the selected compiler profile.'
    }
    foreach ($input in $baseline.inputs) {
        if ([IO.Path]::IsPathRooted($input.sdkPath) -or $input.sdkPath -match '(^|\\)\.\.(\\|$)' -or
            (Get-FileHash -LiteralPath (Join-Path $SdkPackageRoot $input.sdkPath)).Hash -cne $input.sha256) {
            throw 'A pristine Propsys preprocessed SDK input changed.'
        }
    }
    if (@($baseline.inputs | Where-Object sdkPath -CEQ 'c\include\10.0.26100.0\um\propsys.idl').Count -ne 1 -or
        $baseline.nativeContract -cne (Get-PropsysMidlNativeContract "$directory\propsys.h")) {
        throw 'The pristine Propsys receipt lost its native source or declaration evidence.'
    }
    $nativeContract = Get-PropsysMidlNativeContract $Header
    if ($baseline.nativeContract -cne $nativeContract) {
        $differences = @(Compare-Object ($baseline.nativeContract -split "`n") ($nativeContract -split "`n") |
            Select-Object -First 8 | ForEach-Object { "$($_.SideIndicator) $($_.InputObject)" })
        throw "The generated Propsys header changed a native opaque-type or pointer/buffer contract:`n$($differences -join "`n")"
    }
}
