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


namespace Windows.Win32.Devices.AllJoyn
{
    public static partial class Apis
    {
        public const uint QCC_TRUE = 1;

        public const uint QCC_FALSE = 0;

        public const uint ALLJOYN_MESSAGE_FLAG_NO_REPLY_EXPECTED = 0x01;

        public const uint ALLJOYN_MESSAGE_FLAG_AUTO_START = 0x02;

        public const uint ALLJOYN_MESSAGE_FLAG_ALLOW_REMOTE_MSG = 0x04;

        public const uint ALLJOYN_MESSAGE_FLAG_SESSIONLESS = 0x10;

        public const uint ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST = 0x20;

        public const uint ALLJOYN_MESSAGE_FLAG_ENCRYPTED = 0x80;

        public const uint ALLJOYN_TRAFFIC_TYPE_MESSAGES = 0x01;

        public const uint ALLJOYN_TRAFFIC_TYPE_RAW_UNRELIABLE = 0x02;

        public const uint ALLJOYN_TRAFFIC_TYPE_RAW_RELIABLE = 0x04;

        public const uint ALLJOYN_PROXIMITY_ANY = 0xFF;

        public const uint ALLJOYN_PROXIMITY_PHYSICAL = 0x01;

        public const uint ALLJOYN_PROXIMITY_NETWORK = 0x02;

        public const uint ALLJOYN_READ_READY = 0x1;

        public const uint ALLJOYN_WRITE_READY = 0x2;

        public const uint ALLJOYN_DISCONNECTED = 0x4;

    }
}
