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


using static Windows.Win32.Devices.DeviceAndDriverInstallation.Apis;

namespace Windows.Win32.Devices.DeviceAndDriverInstallation
{
    [Flags]
    public enum SP_COPY_STYLE : uint
    {
        SP_COPY_DELETESOURCE = 0x0000001,
        SP_COPY_REPLACEONLY = 0x0000002,
        SP_COPY_NEWER_OR_SAME = SP_COPY_NEWER,
        SP_COPY_NEWER_ONLY = 0x0010000,
        SP_COPY_NOOVERWRITE = 0x0000008,
        SP_COPY_NODECOMP = 0x0000010,
        SP_COPY_LANGUAGEAWARE = 0x0000020,
        SP_COPY_SOURCE_ABSOLUTE = 0x0000040,
        SP_COPY_SOURCEPATH_ABSOLUTE = 0x0000080,
        SP_COPY_FORCE_IN_USE = 0x0000200,
        SP_COPY_IN_USE_NEEDS_REBOOT = 0x0000100,
        SP_COPY_NOSKIP = 0x0000400,
        SP_COPY_FORCE_NOOVERWRITE = 0x0001000,
        SP_COPY_FORCE_NEWER = 0x0002000,
        SP_COPY_WARNIFSKIP = 0x0004000,
        SP_COPY_NOBROWSE = 0x0008000,
        SP_COPY_NEWER = 0x0000004,
        SP_COPY_RESERVED = 0x0020000,
        SP_COPY_OEMINF_CATALOG_ONLY = 0x0040000,
        SP_COPY_REPLACE_BOOT_FILE = 0x0080000,
        SP_COPY_NOPRUNE = 0x0100000,
        SP_COPY_OEM_F6_INF = 0x0200000,
        SP_COPY_ALREADYDECOMP = 0x0400000,
        SP_COPY_WINDOWS_SIGNED = 0x1000000,
        SP_COPY_PNPLOCKED = 0x2000000,
        SP_COPY_IN_USE_TRY_RENAME = 0x4000000,
        SP_COPY_INBOX_INF = 0x8000000,
        SP_COPY_HARDLINK = 0x10000000,
    }

    public enum SETUP_FILE_OPERATION : uint
    {
        FILEOP_DELETE = 2,
        FILEOP_COPY = 0,
    }

    public enum OEM_SOURCE_MEDIA_TYPE : uint
    {
        SPOST_NONE = 0,
        SPOST_PATH = 1,
        SPOST_URL = 2,
    }

    public enum SETUP_DI_BUILD_DRIVER_DRIVER_TYPE : uint
    {
        SPDIT_CLASSDRIVER = 0x00000001,
        SPDIT_COMPATDRIVER = 0x00000002,
    }

    public enum SP_INF_STYLE : uint
    {
        INF_STYLE_NONE = 0x00000000,
        INF_STYLE_OLDNT = 0x00000001,
        INF_STYLE_WIN4 = 0x00000002,
    }

}
