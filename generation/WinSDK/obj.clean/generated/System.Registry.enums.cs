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


using static Windows.Win32.System.Registry.Apis;

namespace Windows.Win32.System.Registry
{
    public enum REG_SAVE_FORMAT : uint
    {
        REG_STANDARD_FORMAT = 1,
        REG_LATEST_FORMAT = 2,
        REG_NO_COMPRESSION = 4,
    }

    public enum REG_RESTORE_KEY_FLAGS
    {
        REG_FORCE_RESTORE = 0x00000008,
        REG_WHOLE_HIVE_VOLATILE = 0x00000001,
    }

    [Flags]
    public enum REG_NOTIFY_FILTER : uint
    {
        REG_NOTIFY_CHANGE_NAME = 0x00000001,
        REG_NOTIFY_CHANGE_ATTRIBUTES = 0x00000002,
        REG_NOTIFY_CHANGE_LAST_SET = 0x00000004,
        REG_NOTIFY_CHANGE_SECURITY = 0x00000008,
        REG_NOTIFY_THREAD_AGNOSTIC = 0x10000000,
    }

    [Flags]
    public enum RRF_RT : uint
    {
        RRF_RT_ANY = 65535,
        RRF_RT_DWORD = 24,
        RRF_RT_QWORD = 72,
        RRF_RT_REG_BINARY = 8,
        RRF_RT_REG_DWORD = 16,
        RRF_RT_REG_EXPAND_SZ = 4,
        RRF_RT_REG_MULTI_SZ = 32,
        RRF_RT_REG_NONE = 1,
        RRF_RT_REG_QWORD = 64,
        RRF_RT_REG_SZ = 2,
    }

}
