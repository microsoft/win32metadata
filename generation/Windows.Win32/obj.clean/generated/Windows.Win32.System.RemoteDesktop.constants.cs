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


namespace Windows.Win32.System.RemoteDesktop
{
    public static partial class Apis
    {
        public const uint WTS_DOMAIN_LENGTH = 255;

        public const uint WTS_USERNAME_LENGTH = 255;

        public const uint WTS_PASSWORD_LENGTH = 255;

        public const uint WTS_DIRECTORY_LENGTH = 256;

        public const uint WTS_INITIALPROGRAM_LENGTH = 256;

        public const uint WTS_PROTOCOL_NAME_LENGTH = 8;

        public const uint WTS_DRIVER_NAME_LENGTH = 8;

        public const uint WTS_DEVICE_NAME_LENGTH = 19;

        public const uint WTS_IMEFILENAME_LENGTH = 32;

        public const uint WTS_CLIENTNAME_LENGTH = 20;

        public const uint WTS_CLIENTADDRESS_LENGTH = 30;

        public const uint WTS_CLIENT_PRODUCT_ID_LENGTH = 32;

        public const uint WTS_MAX_PROTOCOL_CACHE = 4;

        public const uint WTS_MAX_CACHE_RESERVED = 20;

        public const uint WTS_MAX_RESERVED = 100;

        public const uint WTS_MAX_COUNTERS = 100;

        public const uint WTS_MAX_DISPLAY_IOCTL_DATA = 256;

        public const uint WTS_PERF_DISABLE_NOTHING = 0x00000000;

        public const uint WTS_PERF_DISABLE_WALLPAPER = 0x00000001;

        public const uint WTS_PERF_DISABLE_FULLWINDOWDRAG = 0x00000002;

        public const uint WTS_PERF_DISABLE_MENUANIMATIONS = 0x00000004;

        public const uint WTS_PERF_DISABLE_THEMING = 0x00000008;

        public const uint WTS_PERF_ENABLE_ENHANCED_GRAPHICS = 0x00000010;

        public const uint WTS_PERF_DISABLE_CURSOR_SHADOW = 0x00000020;

        public const uint WTS_PERF_DISABLE_CURSORSETTINGS = 0x00000040;

        public const uint WTS_PERF_ENABLE_FONT_SMOOTHING = 0x00000080;

        public const uint WTS_PERF_ENABLE_DESKTOP_COMPOSITION = 0x00000100;

        public const uint WTS_VALUE_TYPE_ULONG = 1;

        public const uint WTS_VALUE_TYPE_STRING = 2;

        public const uint WTS_VALUE_TYPE_BINARY = 3;

        public const uint WTS_VALUE_TYPE_GUID = 4;

        public const uint WTS_KEY_EXCHANGE_ALG_RSA = 1;

        public const uint WTS_KEY_EXCHANGE_ALG_DH = 2;

        public const uint WTS_LICENSE_PROTOCOL_VERSION = 0x00010000;

        public const uint WTS_LICENSE_PREAMBLE_VERSION = 0x03;

        public const uint SINGLE_SESSION = 0x1;

        public const uint FORCE_REJOIN = 0x2;

        public const uint FORCE_REJOIN_IN_CLUSTERMODE = 0x3;

        public const uint RESERVED_FOR_LEGACY = 0x4;

        public const uint KEEP_EXISTING_SESSIONS = 0x8;

        public const uint CHANNEL_EVENT_INITIALIZED = 0;

        public const uint CHANNEL_EVENT_CONNECTED = 1;

        public const uint CHANNEL_EVENT_V1_CONNECTED = 2;

        public const uint CHANNEL_EVENT_DISCONNECTED = 3;

        public const uint CHANNEL_EVENT_TERMINATED = 4;

        public const uint CHANNEL_EVENT_DATA_RECEIVED = 10;

        public const uint CHANNEL_EVENT_WRITE_COMPLETE = 11;

        public const uint CHANNEL_EVENT_WRITE_CANCELLED = 12;

        public const uint CHANNEL_RC_OK = 0;

        public const uint CHANNEL_RC_ALREADY_INITIALIZED = 1;

        public const uint CHANNEL_RC_NOT_INITIALIZED = 2;

        public const uint CHANNEL_RC_ALREADY_CONNECTED = 3;

        public const uint CHANNEL_RC_NOT_CONNECTED = 4;

        public const uint CHANNEL_RC_TOO_MANY_CHANNELS = 5;

        public const uint CHANNEL_RC_BAD_CHANNEL = 6;

        public const uint CHANNEL_RC_BAD_CHANNEL_HANDLE = 7;

        public const uint CHANNEL_RC_NO_BUFFER = 8;

        public const uint CHANNEL_RC_BAD_INIT_HANDLE = 9;

        public const uint CHANNEL_RC_NOT_OPEN = 10;

        public const uint CHANNEL_RC_BAD_PROC = 11;

        public const uint CHANNEL_RC_NO_MEMORY = 12;

        public const uint CHANNEL_RC_UNKNOWN_CHANNEL_NAME = 13;

        public const uint CHANNEL_RC_ALREADY_OPEN = 14;

        public const uint CHANNEL_RC_NOT_IN_VIRTUALCHANNELENTRY = 15;

        public const uint CHANNEL_RC_NULL_DATA = 16;

        public const uint CHANNEL_RC_ZERO_LENGTH = 17;

        public const uint CHANNEL_RC_INVALID_INSTANCE = 18;

        public const uint CHANNEL_RC_UNSUPPORTED_VERSION = 19;

        public const uint CHANNEL_RC_INITIALIZATION_ERROR = 20;

        public const uint VIRTUAL_CHANNEL_VERSION_WIN2000 = 1;

        public const uint CHANNEL_CHUNK_LENGTH = 1600;

        public const uint CHANNEL_BUFFER_SIZE = 65535;

        public const uint CHANNEL_FLAG_FIRST = 0x01;

        public const uint CHANNEL_FLAG_LAST = 0x02;

        public const uint CHANNEL_FLAG_MIDDLE = 0;

        public const uint CHANNEL_FLAG_FAIL = 0x100;

        public const uint CHANNEL_OPTION_INITIALIZED = 0x80000000;

        public const uint CHANNEL_OPTION_ENCRYPT_RDP = 0x40000000;

        public const uint CHANNEL_OPTION_ENCRYPT_SC = 0x20000000;

        public const uint CHANNEL_OPTION_ENCRYPT_CS = 0x10000000;

        public const uint CHANNEL_OPTION_PRI_HIGH = 0x08000000;

        public const uint CHANNEL_OPTION_PRI_MED = 0x04000000;

        public const uint CHANNEL_OPTION_PRI_LOW = 0x02000000;

        public const uint CHANNEL_OPTION_COMPRESS_RDP = 0x00800000;

        public const uint CHANNEL_OPTION_COMPRESS = 0x00400000;

        public const uint CHANNEL_OPTION_SHOW_PROTOCOL = 0x00200000;

        public const uint CHANNEL_OPTION_REMOTE_CONTROL_PERSISTENT = 0x00100000;

        public const uint CHANNEL_MAX_COUNT = 30;

        public const uint CHANNEL_NAME_LEN = 7;

        public const uint MAX_POLICY_ATTRIBUTES = 20;

        public const uint WTS_CURRENT_SESSION = 0xFFFFFFFF;

        public const uint USERNAME_LENGTH = 20;

        public const uint CLIENTNAME_LENGTH = 20;

        public const uint CLIENTADDRESS_LENGTH = 30;

        public const uint WTS_WSD_LOGOFF = 0x00000001;

        public const uint WTS_WSD_SHUTDOWN = 0x00000002;

        public const uint WTS_WSD_REBOOT = 0x00000004;

        public const uint WTS_WSD_POWEROFF = 0x00000008;

        public const uint WTS_WSD_FASTREBOOT = 0x00000010;

        public const uint MAX_ELAPSED_TIME_LENGTH = 15;

        public const uint MAX_DATE_TIME_LENGTH = 56;

        public const uint WINSTATIONNAME_LENGTH = 32;

        public const uint DOMAIN_LENGTH = 17;

        public const uint WTS_DRIVE_LENGTH = 3;

        public const uint WTS_LISTENER_NAME_LENGTH = 32;

        public const uint WTS_COMMENT_LENGTH = 60;

        public const uint WTS_LISTENER_CREATE = 0x00000001;

        public const uint WTS_LISTENER_UPDATE = 0x00000010;

        public const uint WTS_SECURITY_QUERY_INFORMATION = 0x00000001;

        public const uint WTS_SECURITY_SET_INFORMATION = 0x00000002;

        public const uint WTS_SECURITY_RESET = 0x00000004;

        public const uint WTS_SECURITY_VIRTUAL_CHANNELS = 0x00000008;

        public const uint WTS_SECURITY_REMOTE_CONTROL = 0x00000010;

        public const uint WTS_SECURITY_LOGON = 0x00000020;

        public const uint WTS_SECURITY_LOGOFF = 0x00000040;

        public const uint WTS_SECURITY_MESSAGE = 0x00000080;

        public const uint WTS_SECURITY_CONNECT = 0x00000100;

        public const uint WTS_SECURITY_DISCONNECT = 0x00000200;

        public const uint WTS_PROTOCOL_TYPE_CONSOLE = 0;

        public const uint WTS_PROTOCOL_TYPE_ICA = 1;

        public const uint WTS_PROTOCOL_TYPE_RDP = 2;

        public const uint WTS_SESSIONSTATE_UNKNOWN = 0xFFFFFFFF;

        public const uint WTS_SESSIONSTATE_LOCK = 0x00000000;

        public const uint WTS_SESSIONSTATE_UNLOCK = 0x00000001;

        public const uint PRODUCTINFO_COMPANYNAME_LENGTH = 256;

        public const uint PRODUCTINFO_PRODUCTID_LENGTH = 4;

        public const uint VALIDATIONINFORMATION_LICENSE_LENGTH = 16384;

        public const uint VALIDATIONINFORMATION_HARDWAREID_LENGTH = 20;

        public const uint WTS_EVENT_NONE = 0x00000000;

        public const uint WTS_EVENT_CREATE = 0x00000001;

        public const uint WTS_EVENT_DELETE = 0x00000002;

        public const uint WTS_EVENT_RENAME = 0x00000004;

        public const uint WTS_EVENT_CONNECT = 0x00000008;

        public const uint WTS_EVENT_DISCONNECT = 0x00000010;

        public const uint WTS_EVENT_LOGON = 0x00000020;

        public const uint WTS_EVENT_LOGOFF = 0x00000040;

        public const uint WTS_EVENT_STATECHANGE = 0x00000080;

        public const uint WTS_EVENT_LICENSE = 0x00000100;

        public const uint WTS_EVENT_ALL = 0x7fffffff;

        public const uint WTS_EVENT_FLUSH = 0x80000000;

        public const uint REMOTECONTROL_KBDSHIFT_HOTKEY = 0x1;

        public const uint REMOTECONTROL_KBDCTRL_HOTKEY = 0x2;

        public const uint REMOTECONTROL_KBDALT_HOTKEY = 0x4;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC = 0x00000001;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC_PRI_LOW = 0x00000000;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC_PRI_MED = 0x00000002;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC_PRI_HIGH = 0x00000004;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC_PRI_REAL = 0x00000006;

        public const uint WTS_CHANNEL_OPTION_DYNAMIC_NO_COMPRESS = 0x00000008;

        public const uint NOTIFY_FOR_ALL_SESSIONS = 1;

        public const uint NOTIFY_FOR_THIS_SESSION = 0;

        public const uint WTS_PROCESS_INFO_LEVEL_0 = 0;

        public const uint WTS_PROCESS_INFO_LEVEL_1 = 1;

        public const uint PLUGIN_CAPABILITY_EXTERNAL_REDIRECTION = 0x1;

        public const uint MaxFQDN_Len = 256;

        public const uint MaxNetBiosName_Len = 16;

        public const uint MaxNumOfExposed_IPs = 12;

        public const uint MaxUserName_Len = 104;

        public const uint MaxDomainName_Len = 256;

        public const uint MaxFarm_Len = 256;

        public const uint MaxAppName_Len = 256;

        public const uint WKS_FLAG_CLEAR_CREDS_ON_LAST_RESOURCE = 1;

        public const uint WKS_FLAG_PASSWORD_ENCRYPTED = 2;

        public const uint WKS_FLAG_CREDS_AUTHENTICATED = 4;

        public const uint SB_SYNCH_CONFLICT_MAX_WRITE_ATTEMPTS = 100;

        public const uint ACQUIRE_TARGET_LOCK_TIMEOUT = 300000;

        public const uint RENDER_HINT_CLEAR = 0x0;

        public const uint RENDER_HINT_VIDEO = 0x1;

        public const uint RENDER_HINT_MAPPEDWINDOW = 0x2;

        public const uint TS_VC_LISTENER_STATIC_CHANNEL = 0x00000001;

        public const uint WRdsGraphicsChannels_LossyChannelMaxMessageSize = 988;

        public const uint RFX_RDP_MSG_PREFIX = 0x00;

        public const uint RFX_GFX_MSG_PREFIX = 0x30;

        public const uint RFX_GFX_MSG_PREFIX_MASK = 0x30;

        public const uint RFX_GFX_MAX_SUPPORTED_MONITORS = 16;

        public const uint RFX_CLIENT_ID_LENGTH = 32;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_CONNECT = 701;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_DISCONNECT = 702;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_RECONNECT = 703;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_DELETE_SAVED_CREDENTIALS = 704;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_UPDATE_SESSION_DISPLAYSETTINGS = 705;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_ATTACH_EVENT = 706;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_DETACH_EVENT = 707;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_SETTINGS = 710;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_ACTIONS = 711;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_TOUCH_POINTER = 712;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_SET_RDPPROPERTY = 720;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_GET_RDPPROPERTY = 721;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_APPLY_SETTINGS = 722;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_RETRIEVE_SETTINGS = 723;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_SUSPEND_SCREEN_UPDATES = 730;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_RESUME_SCREEN_UPDATES = 731;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_EXECUTE_REMOTE_ACTION = 732;

        public const uint DISPID_METHOD_REMOTEDESKTOPCLIENT_GET_SNAPSHOT = 733;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_TOUCHPOINTER_ENABLED = 740;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_TOUCHPOINTER_EVENTSENABLED = 741;

        public const uint DISPID_PROP_REMOTEDESKTOPCLIENT_TOUCHPOINTER_POINTERSPEED = 742;

        public const uint DISPID_AX_CONNECTING = 750;

        public const uint DISPID_AX_CONNECTED = 751;

        public const uint DISPID_AX_LOGINCOMPLETED = 752;

        public const uint DISPID_AX_DISCONNECTED = 753;

        public const uint DISPID_AX_STATUSCHANGED = 754;

        public const uint DISPID_AX_AUTORECONNECTING = 755;

        public const uint DISPID_AX_AUTORECONNECTED = 756;

        public const uint DISPID_AX_DIALOGDISPLAYING = 757;

        public const uint DISPID_AX_DIALOGDISMISSED = 758;

        public const uint DISPID_AX_NETWORKSTATUSCHANGED = 759;

        public const uint DISPID_AX_ADMINMESSAGERECEIVED = 760;

        public const uint DISPID_AX_KEYCOMBINATIONPRESSED = 761;

        public const uint DISPID_AX_REMOTEDESKTOPSIZECHANGED = 762;

        public const uint DISPID_AX_TOUCHPOINTERCURSORMOVED = 800;

    }
}
