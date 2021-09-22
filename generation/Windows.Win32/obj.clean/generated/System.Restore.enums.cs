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


using static Windows.Win32.System.Restore.Apis;

namespace Windows.Win32.System.Restore
{
    public enum RESTOREPOINTINFO_TYPE : uint
    {
        APPLICATION_INSTALL = 0,
        APPLICATION_UNINSTALL = 1,
        DEVICE_DRIVER_INSTALL = 10,
        MODIFY_SETTINGS = 12,
        CANCELLED_OPERATION = 13,
    }

    public enum RESTOREPOINTINFO_EVENT_TYPE : uint
    {
        BEGIN_NESTED_SYSTEM_CHANGE = 102,
        BEGIN_SYSTEM_CHANGE = 100,
        END_NESTED_SYSTEM_CHANGE = 103,
        END_SYSTEM_CHANGE = 101,
    }

}
