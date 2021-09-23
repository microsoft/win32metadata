using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


using static Windows.Win32.System.ApplicationInstallationAndServicing.Apis;

namespace Windows.Win32.System.ApplicationInstallationAndServicing
{
    public enum MSIASSEMBLYINFO : uint
    {
        MSIASSEMBLYINFO_NETASSEMBLY = 0,
        MSIASSEMBLYINFO_WIN32ASSEMBLY = 1,
    }

    public enum IASSEMBLYCACHE_UNINSTALL_DISPOSITION : uint
    {
        IASSEMBLYCACHE_UNINSTALL_DISPOSITION_UNINSTALLED = 1,
        IASSEMBLYCACHE_UNINSTALL_DISPOSITION_STILL_IN_USE = 2,
        IASSEMBLYCACHE_UNINSTALL_DISPOSITION_ALREADY_UNINSTALLED = 3,
        IASSEMBLYCACHE_UNINSTALL_DISPOSITION_DELETE_PENDING = 4,
    }

    [Flags]
    public enum QUERYASMINFO_FLAGS : uint
    {
        QUERYASMINFO_FLAG_VALIDATE = 0x1,
    }

}
