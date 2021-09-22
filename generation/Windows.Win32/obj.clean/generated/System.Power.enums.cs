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


using static Windows.Win32.System.Power.Apis;

namespace Windows.Win32.System.Power
{
    public enum POWER_PLATFORM_ROLE_VERSION : uint
    {
        POWER_PLATFORM_ROLE_V1 = 0x00000001,
        POWER_PLATFORM_ROLE_V2 = 0x00000002,
    }

    public enum POWER_SETTING_REGISTER_NOTIFICATION_FLAGS : uint
    {
        DEVICE_NOTIFY_SERVICE_HANDLE = 1,
        DEVICE_NOTIFY_CALLBACK = 2,
        DEVICE_NOTIFY_WINDOW_HANDLE = 0,
    }

    [Flags]
    public enum EXECUTION_STATE : uint
    {
        ES_AWAYMODE_REQUIRED = 64,
        ES_CONTINUOUS = 2147483648,
        ES_DISPLAY_REQUIRED = 2,
        ES_SYSTEM_REQUIRED = 1,
        ES_USER_PRESENT = 4,
    }

    [Flags]
    public enum POWER_ACTION_POLICY_EVENT_CODE : uint
    {
        POWER_FORCE_TRIGGER_RESET = 2147483648,
        POWER_LEVEL_USER_NOTIFY_EXEC = 4,
        POWER_LEVEL_USER_NOTIFY_SOUND = 2,
        POWER_LEVEL_USER_NOTIFY_TEXT = 1,
        POWER_USER_NOTIFY_BUTTON = 8,
        POWER_USER_NOTIFY_SHUTDOWN = 16,
    }

}
