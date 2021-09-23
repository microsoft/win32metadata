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


namespace Windows.Win32.System.RemoteManagement
{
    public static partial class Apis
    {
        public const uint WSMAN_FLAG_REQUESTED_API_VERSION_1_0 = 0x0;

        public const uint WSMAN_FLAG_REQUESTED_API_VERSION_1_1 = 0x1;

        public const uint WSMAN_OPERATION_INFOV1 = 0x00000000;

        public const uint WSMAN_OPERATION_INFOV2 = 0xaabbccdd;

        public const uint WSMAN_DEFAULT_TIMEOUT_MS = 60000;

        public const uint WSMAN_FLAG_RECEIVE_RESULT_NO_MORE_DATA = 1;

        public const uint WSMAN_FLAG_RECEIVE_FLUSH = 2;

        public const uint WSMAN_FLAG_RECEIVE_RESULT_DATA_BOUNDARY = 4;

        public const uint WSMAN_PLUGIN_PARAMS_MAX_ENVELOPE_SIZE = 1;

        public const uint WSMAN_PLUGIN_PARAMS_TIMEOUT = 2;

        public const uint WSMAN_PLUGIN_PARAMS_REMAINING_RESULT_SIZE = 3;

        public const uint WSMAN_PLUGIN_PARAMS_LARGEST_RESULT_SIZE = 4;

        public const uint WSMAN_PLUGIN_PARAMS_GET_REQUESTED_LOCALE = 5;

        public const uint WSMAN_PLUGIN_PARAMS_GET_REQUESTED_DATA_LOCALE = 6;

        public const uint WSMAN_PLUGIN_PARAMS_SHAREDHOST = 1;

        public const uint WSMAN_PLUGIN_PARAMS_RUNAS_USER = 2;

        public const uint WSMAN_PLUGIN_PARAMS_AUTORESTART = 3;

        public const uint WSMAN_PLUGIN_PARAMS_HOSTIDLETIMEOUTSECONDS = 4;

        public const uint WSMAN_PLUGIN_PARAMS_NAME = 5;

        public const uint WSMAN_PLUGIN_STARTUP_REQUEST_RECEIVED = 0x0;

        public const uint WSMAN_PLUGIN_STARTUP_AUTORESTARTED_REBOOT = 0x1;

        public const uint WSMAN_PLUGIN_STARTUP_AUTORESTARTED_CRASH = 0x2;

        public const uint WSMAN_PLUGIN_SHUTDOWN_SYSTEM = 1;

        public const uint WSMAN_PLUGIN_SHUTDOWN_SERVICE = 2;

        public const uint WSMAN_PLUGIN_SHUTDOWN_IISHOST = 3;

        public const uint WSMAN_PLUGIN_SHUTDOWN_IDLETIMEOUT_ELAPSED = 4;

        public const uint WSMAN_FLAG_SEND_NO_MORE_DATA = 1;

    }
}
