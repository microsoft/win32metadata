function Get-MidlHeaderArguments {
    param(
        [Parameter(Mandatory)][string]$InputFile,
        [Parameter(Mandatory)][string]$OutputDirectory,
        [Parameter(Mandatory)][string]$OutputHeader,
        [Parameter(Mandatory)][string[]]$IncludeDirectories,
        [switch]$ClosedPreprocessing
    )

    # Match the original recompiled mirror's compiler input and header spellings.
    $InputFile = $InputFile.ToLowerInvariant()
    $OutputHeader = $OutputHeader.ToLowerInvariant()
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

function Assert-MidlHeaderResult([string]$Source, [int]$ExitCode, [string]$Text, [string]$Header) {
    $diagnostics = @(Get-MidlErrorDiagnostics $Text)
    $nonBlockingCount = 0
    $blocking = @($diagnostics | Where-Object {
        $markers = [regex]::Matches($_,
            '(?i)\bfatal\s+error\b|\bmidl\s*:\s*error\b(?!\s+(?:MIDL|C)\d+\b)|\berror\s+(?:MIDL|C)\d+\b')
        $otherErrors = @($markers | Where-Object { $_.Value -notmatch '^(?i)error\s+MIDL2337$' })
        if (!$markers.Count -or $otherErrors.Count) {
            $true
        }
        else {
            $nonBlockingCount += $markers.Count
            $false
        }
    })
    if ($ExitCode -ne 0 -or $blocking.Count) {
        throw "MIDL failed for $Source (exit $ExitCode):`n$Text"
    }
    if (!(Test-Path -LiteralPath $Header -PathType Leaf) -or !(Get-Item -LiteralPath $Header).Length) {
        throw "MIDL did not produce its complete admitted header for ${Source}: $Header`n$Text"
    }
    $headerText = [IO.File]::ReadAllText($Header)
    $body = [regex]::Replace($headerText, '(?s)/\*.*?\*/|(?m)//[^\r\n]*', '')
    $guard = [regex]::Match($body, '(?m)^\s*#ifndef\s+(__[A-Za-z0-9_]+_h__)\s*$')
    if (!$headerText.Contains('File created by MIDL compiler') -or !$guard.Success -or
        $body -cnotmatch "(?m)^\s*#define\s+$([regex]::Escape($guard.Groups[1].Value))\s*$" -or
        $body -cnotmatch '#ifdef\s+__cplusplus\s+extern\s+"C"\s*\{\s*#endif' -or
        $body -cnotmatch '#ifdef\s+__cplusplus\s*\}\s*#endif\s*#endif\s*$') {
        throw "MIDL produced an incomplete admitted header for ${Source}: $Header`n$Text"
    }
    [pscustomobject]@{
        nonBlockingErrorCount = $nonBlockingCount
        nonBlockingErrorCounts = [ordered]@{ MIDL2337 = $nonBlockingCount }
        nonBlockingErrors = $diagnostics
    }
}
