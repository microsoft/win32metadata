function Get-WinSdkMidlExclusions {
    @('cellularapi_oem', 'certbcli', 'dxgicommon', 'dxgitype',
        'microsoft.diagnostics.appanalysis', 'PortableDeviceConnectImports', 'wincrypt') |
        ForEach-Object { "$_.idl" }
}

function Get-WinSdkMidlArguments {
    param(
        [Parameter(Mandatory)][string]$InputFile,
        [Parameter(Mandatory)][string]$OutputHeader,
        [Parameter(Mandatory)][string]$OutputDirectory,
        [Parameter(Mandatory)][string]$ConvertedIdlDirectory,
        [Parameter(Mandatory)][string]$HeaderRoot
    )
    @($InputFile, '/out', $OutputDirectory, '/header', $OutputHeader, '/no_warn',
        '/DUNICODE', '/D_UNICODE', '/DWINVER=0x0A00', '/D_APISET_MINWIN_VERSION=0x010F', '/DNTDDI_VERSION=0x0A00000C',
        '/DBUILD_UMS_ENABLED=0', '/DBUILD_WOW64_ENABLED=0', '/DBUILD_ARM64X_ENABLED=0', '/DEXECUTABLE_WRITES_SUPPORT=0',
        '/D_USE_DECLSPECS_FOR_SAL=1', '/D_CONTROL_FLOW_GUARD_SVCTAB=1', '/DMIDL_PASS=1', '/D_AMD64_', '/D_WIN64', '/D_WCHAR_T_DEFINED',
        '/no_stamp', '/nologo', '/no_settings_comment', '/lcid', '1033', '/sal', '/amd64', '/target', 'NT100', '/Zp8',
        '/I', $ConvertedIdlDirectory, '/I', (Join-Path $HeaderRoot 'um'),
        '/I', (Join-Path $HeaderRoot 'shared'), '/I', (Join-Path $HeaderRoot 'winrt'),
        '/I', (Join-Path $PSScriptRoot 'inc'))
}
