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


namespace Windows.Win32.System.Restore
{
    public static partial class Apis
    {
        public const uint MIN_EVENT = 100;

        public const uint BEGIN_NESTED_SYSTEM_CHANGE_NORP = 104;

        public const uint MAX_EVENT = 104;

        public const uint MIN_RPT = 0;

        public const uint DESKTOP_SETTING = 2;

        public const uint ACCESSIBILITY_SETTING = 3;

        public const uint OE_SETTING = 4;

        public const uint APPLICATION_RUN = 5;

        public const uint RESTORE = 6;

        public const uint CHECKPOINT = 7;

        public const uint WINDOWS_SHUTDOWN = 8;

        public const uint WINDOWS_BOOT = 9;

        public const uint FIRSTRUN = 11;

        public const uint BACKUP_RECOVERY = 14;

        public const uint BACKUP = 15;

        public const uint MANUAL_CHECKPOINT = 16;

        public const uint WINDOWS_UPDATE = 17;

        public const uint CRITICAL_UPDATE = 18;

        public const uint MAX_RPT = 18;

        public const uint MAX_DESC = 64;

        public const uint MAX_DESC_W = 256;

    }
}
