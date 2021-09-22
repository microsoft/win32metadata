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


namespace Windows.Win32.NetworkManagement.WNet
{
    public static partial class Apis
    {
        public const uint WNGETCON_CONNECTED = 0x00000000;

        public const uint WNGETCON_DISCONNECTED = 0x00000001;

        public const uint WNNC_SPEC_VERSION = 0x00000001;

        public const uint WNNC_SPEC_VERSION51 = 0x00050001;

        public const uint WNNC_NET_TYPE = 0x00000002;

        public const uint WNNC_NET_NONE = 0x00000000;

        public const uint WNNC_DRIVER_VERSION = 0x00000003;

        public const uint WNNC_USER = 0x00000004;

        public const uint WNNC_USR_GETUSER = 0x00000001;

        public const uint WNNC_CONNECTION = 0x00000006;

        public const uint WNNC_CON_ADDCONNECTION = 0x00000001;

        public const uint WNNC_CON_CANCELCONNECTION = 0x00000002;

        public const uint WNNC_CON_GETCONNECTIONS = 0x00000004;

        public const uint WNNC_CON_ADDCONNECTION3 = 0x00000008;

        public const uint WNNC_CON_ADDCONNECTION4 = 0x00000010;

        public const uint WNNC_CON_GETPERFORMANCE = 0x00000040;

        public const uint WNNC_CON_DEFER = 0x00000080;

        public const uint WNNC_DIALOG = 0x00000008;

        public const uint WNNC_DLG_DEVICEMODE = 0x00000001;

        public const uint WNNC_DLG_PROPERTYDIALOG = 0x00000020;

        public const uint WNNC_DLG_SEARCHDIALOG = 0x00000040;

        public const uint WNNC_DLG_FORMATNETWORKNAME = 0x00000080;

        public const uint WNNC_DLG_PERMISSIONEDITOR = 0x00000100;

        public const uint WNNC_DLG_GETRESOURCEPARENT = 0x00000200;

        public const uint WNNC_DLG_GETRESOURCEINFORMATION = 0x00000800;

        public const uint WNNC_ADMIN = 0x00000009;

        public const uint WNNC_ADM_GETDIRECTORYTYPE = 0x00000001;

        public const uint WNNC_ADM_DIRECTORYNOTIFY = 0x00000002;

        public const uint WNNC_ENUMERATION = 0x0000000B;

        public const uint WNNC_ENUM_GLOBAL = 0x00000001;

        public const uint WNNC_ENUM_LOCAL = 0x00000002;

        public const uint WNNC_ENUM_CONTEXT = 0x00000004;

        public const uint WNNC_ENUM_SHAREABLE = 0x00000008;

        public const uint WNNC_START = 0x0000000C;

        public const uint WNNC_WAIT_FOR_START = 0x00000001;

        public const uint WNNC_CONNECTION_FLAGS = 0x0000000D;

        public const uint WNTYPE_DRIVE = 1;

        public const uint WNTYPE_FILE = 2;

        public const uint WNTYPE_PRINTER = 3;

        public const uint WNTYPE_COMM = 4;

        public const uint WNSRCH_REFRESH_FIRST_LEVEL = 0x00000001;

        public const uint WNDT_NORMAL = 0;

        public const uint WNDT_NETWORK = 1;

        public const uint WN_NETWORK_CLASS = 0x00000001;

        public const uint WN_CREDENTIAL_CLASS = 0x00000002;

        public const uint WN_PRIMARY_AUTHENT_CLASS = 0x00000004;

        public const uint WN_SERVICE_CLASS = 0x00000008;

        public const uint WN_VALID_LOGON_ACCOUNT = 0x00000001;

        public const uint WN_NT_PASSWORD_CHANGED = 0x00000002;

        public const uint NOTIFY_PRE = 0x00000001;

        public const uint NOTIFY_POST = 0x00000002;

        public const uint WNPERMC_PERM = 0x00000001;

        public const uint WNPERMC_AUDIT = 0x00000002;

        public const uint WNPERMC_OWNER = 0x00000004;

        public const uint RESOURCE_RECENT = 0x00000004;

        public const uint RESOURCETYPE_RESERVED = 0x00000008;

        public const uint RESOURCETYPE_UNKNOWN = 0xFFFFFFFF;

        public const uint RESOURCEUSAGE_NOLOCALDEVICE = 0x00000004;

        public const uint RESOURCEUSAGE_SIBLING = 0x00000008;

        public const uint RESOURCEUSAGE_RESERVED = 0x80000000;

        public const uint RESOURCEDISPLAYTYPE_NETWORK = 0x00000006;

        public const uint RESOURCEDISPLAYTYPE_ROOT = 0x00000007;

        public const uint RESOURCEDISPLAYTYPE_SHAREADMIN = 0x00000008;

        public const uint RESOURCEDISPLAYTYPE_DIRECTORY = 0x00000009;

        public const uint RESOURCEDISPLAYTYPE_NDSCONTAINER = 0x0000000B;

        public const uint NETPROPERTY_PERSISTENT = 1;

        public const uint CONNECT_NEED_DRIVE = 0x00000020;

        public const uint CONNECT_REFCOUNT = 0x00000040;

        public const uint CONNECT_LOCALDRIVE = 0x00000100;

        public const uint CONNECT_CURRENT_MEDIA = 0x00000200;

        public const uint CONNECT_RESERVED = 0xFF000000;

        public const uint CONNECT_CRED_RESET = 0x00002000;

        public const uint CONNECT_REQUIRE_INTEGRITY = 0x00004000;

        public const uint CONNECT_REQUIRE_PRIVACY = 0x00008000;

        public const uint CONNECT_WRITE_THROUGH_SEMANTICS = 0x00010000;

        public const uint CONNECT_COMPRESS_NETWORK_TRAFFIC = 0x00020000;

        public const uint WNFMT_INENUM = 0x10;

        public const uint WNFMT_CONNECTION = 0x20;

        public const uint WNCON_FORNETCARD = 0x00000001;

        public const uint WNCON_NOTROUTED = 0x00000002;

        public const uint WNCON_SLOWLINK = 0x00000004;

        public const uint WNCON_DYNAMIC = 0x00000008;

    }
}
