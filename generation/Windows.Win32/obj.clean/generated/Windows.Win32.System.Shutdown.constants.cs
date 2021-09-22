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


namespace Windows.Win32.System.Shutdown
{
    public static partial class Apis
    {
        public const uint MAX_REASON_NAME_LEN = 64;

        public const uint MAX_REASON_DESC_LEN = 256;

        public const uint MAX_REASON_BUGID_LEN = 32;

        public const uint MAX_REASON_COMMENT_LEN = 512;

        public const uint SHUTDOWN_TYPE_LEN = 32;

        public const uint POLICY_SHOWREASONUI_NEVER = 0;

        public const uint POLICY_SHOWREASONUI_ALWAYS = 1;

        public const uint POLICY_SHOWREASONUI_WORKSTATIONONLY = 2;

        public const uint POLICY_SHOWREASONUI_SERVERONLY = 3;

        public const uint SNAPSHOT_POLICY_NEVER = 0;

        public const uint SNAPSHOT_POLICY_ALWAYS = 1;

        public const uint SNAPSHOT_POLICY_UNPLANNED = 2;

        public const uint MAX_NUM_REASONS = 256;

    }
}
