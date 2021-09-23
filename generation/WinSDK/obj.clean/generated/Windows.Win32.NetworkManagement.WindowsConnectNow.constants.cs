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


namespace Windows.Win32.NetworkManagement.WindowsConnectNow
{
    public static partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int WCN_E_PEER_NOT_FOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x3C01));

        [NativeTypeName("HRESULT")]
        public const int WCN_E_AUTHENTICATION_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x3C02));

        [NativeTypeName("HRESULT")]
        public const int WCN_E_CONNECTION_REJECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x3C03));

        [NativeTypeName("HRESULT")]
        public const int WCN_E_SESSION_TIMEDOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x3C04));

        [NativeTypeName("HRESULT")]
        public const int WCN_E_PROTOCOL_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x3C05));

        public const uint WCN_VALUE_DT_CATEGORY_COMPUTER = 0x1;

        public const uint WCN_VALUE_DT_CATEGORY_INPUT_DEVICE = 0x2;

        public const uint WCN_VALUE_DT_CATEGORY_PRINTER = 0x3;

        public const uint WCN_VALUE_DT_CATEGORY_CAMERA = 0x4;

        public const uint WCN_VALUE_DT_CATEGORY_STORAGE = 0x5;

        public const uint WCN_VALUE_DT_CATEGORY_NETWORK_INFRASTRUCTURE = 0x6;

        public const uint WCN_VALUE_DT_CATEGORY_DISPLAY = 0x7;

        public const uint WCN_VALUE_DT_CATEGORY_MULTIMEDIA_DEVICE = 0x8;

        public const uint WCN_VALUE_DT_CATEGORY_GAMING_DEVICE = 0x9;

        public const uint WCN_VALUE_DT_CATEGORY_TELEPHONE = 0xa;

        public const uint WCN_VALUE_DT_CATEGORY_AUDIO_DEVICE = 0xb;

        public const uint WCN_VALUE_DT_CATEGORY_OTHER = 0xff;

        public const uint WCN_VALUE_DT_SUBTYPE_WIFI_OUI = 0x50f204;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__PC = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__SERVER = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__MEDIACENTER = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__ULTRAMOBILEPC = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__NOTEBOOK = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__DESKTOP = 0x6;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__MID = 0x7;

        public const uint WCN_VALUE_DT_SUBTYPE_COMPUTER__NETBOOK = 0x8;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__KEYBOARD = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__MOUSE = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__JOYSTICK = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__TRACKBALL = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__GAMECONTROLLER = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__REMOTE = 0x6;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__TOUCHSCREEN = 0x7;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__BIOMETRICREADER = 0x8;

        public const uint WCN_VALUE_DT_SUBTYPE_INPUT_DEVICE__BARCODEREADER = 0x9;

        public const uint WCN_VALUE_DT_SUBTYPE_PRINTER__PRINTER = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_PRINTER__SCANNER = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_PRINTER__FAX = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_PRINTER__COPIER = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_PRINTER__ALLINONE = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_CAMERA__STILL_CAMERA = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_CAMERA__VIDEO_CAMERA = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_CAMERA__WEB_CAMERA = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_CAMERA__SECURITY_CAMERA = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_STORAGE__NAS = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE__AP = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE__ROUTER = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE__SWITCH = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE__GATEWAY = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_NETWORK_INFRASTRUCUTURE__BRIDGE = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_DISPLAY__TELEVISION = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_DISPLAY__PICTURE_FRAME = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_DISPLAY__PROJECTOR = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_DISPLAY__MONITOR = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__DAR = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__PVR = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__MCX = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__SETTOPBOX = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__MEDIA_SERVER_ADAPT_EXT = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_MULTIMEDIA_DEVICE__PVP = 0x6;

        public const uint WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE__XBOX = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE__XBOX360 = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE__PLAYSTATION = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE__CONSOLE_ADAPT = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_GAMING_DEVICE__PORTABLE = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_TELEPHONE__WINDOWS_MOBILE = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_TELEPHONE__PHONE_SINGLEMODE = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_TELEPHONE__PHONE_DUALMODE = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_TELEPHONE__SMARTPHONE_SINGLEMODE = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_TELEPHONE__SMARTPHONE_DUALMODE = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__TUNER_RECEIVER = 0x1;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__SPEAKERS = 0x2;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__PMP = 0x3;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__HEADSET = 0x4;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__HEADPHONES = 0x5;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__MICROPHONE = 0x6;

        public const uint WCN_VALUE_DT_SUBTYPE_AUDIO_DEVICE__HOMETHEATER = 0x7;

        public const uint WCN_API_MAX_BUFFER_SIZE = 2096;

        public const uint WCN_MICROSOFT_VENDOR_ID = 311;

        public const uint WCN_NO_SUBTYPE = 0xfffffffe;

        public const uint WCN_FLAG_DISCOVERY_VE = 0x1;

        public const uint WCN_FLAG_AUTHENTICATED_VE = 0x2;

        public const uint WCN_FLAG_ENCRYPTED_VE = 0x4;

    }
}
