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


namespace Windows.Win32.NetworkManagement.WindowsConnectionManager
{
    public static partial class Apis
    {
        public const uint WCM_API_VERSION_1_0 = 0x00000001;

        public const uint WCM_UNKNOWN_DATAPLAN_STATUS = 0xFFFFFFFF;

        public const uint WCM_MAX_PROFILE_NAME = 256;

        public const uint NET_INTERFACE_FLAG_NONE = 0x00000000;

        public const uint NET_INTERFACE_FLAG_CONNECT_IF_NEEDED = 0x00000001;

    }
}
