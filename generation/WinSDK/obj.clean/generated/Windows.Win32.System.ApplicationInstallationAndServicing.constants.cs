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


namespace Windows.Win32.System.ApplicationInstallationAndServicing
{
    public static partial class Apis
    {
        public const uint LOGTOKEN_TYPE_MASK = 3;

        public const uint LOGTOKEN_UNSPECIFIED = 0;

        public const uint LOGTOKEN_NO_LOG = 1;

        public const uint LOGTOKEN_SETUPAPI_APPLOG = 2;

        public const uint LOGTOKEN_SETUPAPI_DEVLOG = 3;

        public const uint TXTLOG_SETUPAPI_DEVLOG = 0x00000001;

        public const uint TXTLOG_SETUPAPI_CMDLINE = 0x00000002;

        public const uint TXTLOG_SETUPAPI_BITS = 0x00000003;

        public const uint TXTLOG_ERROR = 0x1;

        public const uint TXTLOG_WARNING = 0x2;

        public const uint TXTLOG_SYSTEM_STATE_CHANGE = 0x3;

        public const uint TXTLOG_SUMMARY = 0x4;

        public const uint TXTLOG_DETAILS = 0x5;

        public const uint TXTLOG_VERBOSE = 0x6;

        public const uint TXTLOG_VERY_VERBOSE = 0x7;

        public const uint TXTLOG_RESERVED_FLAGS = 0x0000FFF0;

        public const uint TXTLOG_TIMESTAMP = 0x00010000;

        public const uint TXTLOG_DEPTH_INCR = 0x00020000;

        public const uint TXTLOG_DEPTH_DECR = 0x00040000;

        public const uint TXTLOG_TAB_1 = 0x00080000;

        public const uint TXTLOG_FLUSH_FILE = 0x00100000;

        public const uint TXTLOG_DEVINST = 0x00000001;

        public const uint TXTLOG_INF = 0x00000002;

        public const uint TXTLOG_FILEQ = 0x00000004;

        public const uint TXTLOG_COPYFILES = 0x00000008;

        public const uint TXTLOG_SIGVERIF = 0x00000020;

        public const uint TXTLOG_BACKUP = 0x00000080;

        public const uint TXTLOG_UI = 0x00000100;

        public const uint TXTLOG_UTIL = 0x00000200;

        public const uint TXTLOG_INFDB = 0x00000400;

        public const uint TXTLOG_DRVSETUP = 0x00400000;

        public const uint TXTLOG_POLICY = 0x00800000;

        public const uint TXTLOG_NEWDEV = 0x01000000;

        public const uint TXTLOG_UMPNPMGR = 0x02000000;

        public const uint TXTLOG_DRIVER_STORE = 0x04000000;

        public const uint TXTLOG_SETUP = 0x08000000;

        public const uint TXTLOG_CMI = 0x10000000;

        public const uint TXTLOG_DEVMGR = 0x20000000;

        public const uint TXTLOG_INSTALLER = 0x40000000;

        public const uint TXTLOG_VENDOR = 0x80000000;

        public static readonly Guid CLSID_EvalCom2__scanned__ = new Guid(0x6e5e1910, 0x8053, 0x4660, 0xb7, 0x95, 0x6b, 0x61, 0x2e, 0x29, 0xbc, 0x58);

        public static readonly Guid IID_IValidate__scanned__ = new Guid(0xe482e5c6, 0xe31e, 0x4143, 0xa2, 0xe6, 0xdb, 0xc3, 0xd8, 0xe4, 0xb8, 0xd3);

        public const uint _WIN32_MSM = 100;

        public static readonly Guid LIBID_MsmMergeTypeLib__scanned__ = new Guid(0x0ADDA82F,0x2C26,0x11D2, 0xAD,0x65,0x00,0xA0,0xC9,0xAF,0x11,0xA6);

        public static readonly Guid CLSID_MsmMerge__scanned__ = new Guid(0x0ADDA830,0x2C26,0x11D2, 0xAD,0x65,0x00,0xA0,0xC9,0xAF,0x11,0xA6);

        public static readonly Guid IID_IMsmMerge2__scanned__ = new Guid(0x351A72AB, 0x21CB, 0x47AB, 0xB7, 0xAA, 0xC4, 0xD7, 0xB0, 0x2E, 0xA3, 0x05);

        public static readonly Guid IID_IMsmConfigurableItem__scanned__ = new Guid(0x4D6E6284, 0xD21D, 0x401E, 0x84, 0xF6, 0x90, 0x9E, 0x00, 0xB5, 0x0F, 0x71);

        public static readonly Guid IID_IEnumMsmConfigurableItem__scanned__ = new Guid(0x832C6969, 0x4826, 0x4C24, 0xA3, 0x97, 0xB7, 0x00, 0x2D, 0x81, 0x96, 0xE6);

        public static readonly Guid IID_IMsmConfigurableItems__scanned__ = new Guid(0x55BF723C, 0x9A0D, 0x463E, 0xB4, 0x2B, 0xB4, 0xFB, 0xC7, 0xBE, 0x3C, 0x7C);

        public static readonly Guid IID_IMsmConfigureModule__scanned__ = new Guid(0xAC013209, 0x18A7, 0x4851, 0x8A, 0x21, 0x23, 0x53, 0x44, 0x3D, 0x70, 0xA0);

        public static readonly Guid CLSID_MsmMerge2__scanned__ = new Guid(0xF94985D5,0x29F9,0x4743, 0x98,0x05,0x99,0xBC,0x3F,0x35,0xB6,0x78);

        public const uint NTDDI_WIN2K = 0x05000000;

        public const uint NTDDI_WINXP = 0x05010000;

        public const uint NTDDI_WINXPSP2 = 0x05010200;

        public const uint NTDDI_WS03SP1 = 0x05020100;

        public const uint NTDDI_VISTA = 0x06000000;

        public const uint NTDDI_VISTASP1 = 0x06000100;

        public const uint NTDDI_WIN7 = 0x06010000;

        public const uint NTDDI_WIN8 = 0x06020000;

        public const uint NTDDI_WINBLUE = 0x06030000;

        public const uint NTDDI_WINTHRESHOLD = 0x06040000;

        public const uint MAX_GUID_CHARS = 38;

        public const uint MAX_FEATURE_CHARS = 38;

        public const uint MSI_INVALID_HASH_IS_FATAL = 0x1;

        public const uint ERROR_ROLLBACK_DISABLED = 1653;

        public const uint MSI_NULL_INTEGER = 0x80000000;

        public const int INSTALLMESSAGE_TYPEMASK = unchecked((int)0xFF000000);

        public const uint STREAM_FORMAT_COMPLIB_MODULE = 0;

        public const uint STREAM_FORMAT_COMPLIB_MANIFEST = 1;

        public const uint STREAM_FORMAT_WIN32_MODULE = 2;

        public const uint STREAM_FORMAT_WIN32_MANIFEST = 4;

        public const uint IASSEMBLYCACHEITEM_COMMIT_FLAG_REFRESH = 0x00000001;

        public const uint ASSEMBLYINFO_FLAG_INSTALLED = 0x00000001;

        public const uint ASSEMBLYINFO_FLAG_PAYLOADRESIDENT = 0x00000002;

        public const uint IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_INSTALLED = 1;

        public const uint IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_REFRESHED = 2;

        public const uint IASSEMBLYCACHEITEM_COMMIT_DISPOSITION_ALREADY_INSTALLED = 3;

        public static readonly Guid FUSION_REFCOUNT_UNINSTALL_SUBKEY_GUID__scanned__ = new Guid(0x8cedc215, 0xac4b, 0x488b, 0x93, 0xc0, 0xa5, 0x0a, 0x49, 0xcb, 0x2f, 0xb8);

        public static readonly Guid FUSION_REFCOUNT_FILEPATH_GUID__scanned__ = new Guid(0xb02f9d65, 0xfb77, 0x4f7a, 0xaf, 0xa5, 0xb3, 0x91, 0x30, 0x9f, 0x11, 0xc9);

        public static readonly Guid FUSION_REFCOUNT_OPAQUE_STRING_GUID__scanned__ = new Guid(0x2ec93463, 0xb0c3, 0x45e1, 0x83, 0x64, 0x32, 0x7e, 0x96, 0xae, 0xa8, 0x56);

        public const uint SFC_DISABLE_NORMAL = 0;

        public const uint SFC_DISABLE_ASK = 1;

        public const uint SFC_DISABLE_ONCE = 2;

        public const uint SFC_DISABLE_SETUP = 3;

        public const uint SFC_DISABLE_NOPOPUPS = 4;

        public const uint SFC_SCAN_NORMAL = 0;

        public const uint SFC_SCAN_ALWAYS = 1;

        public const uint SFC_SCAN_ONCE = 2;

        public const uint SFC_SCAN_IMMEDIATE = 3;

        public const uint SFC_QUOTA_DEFAULT = 50;

    }
}
