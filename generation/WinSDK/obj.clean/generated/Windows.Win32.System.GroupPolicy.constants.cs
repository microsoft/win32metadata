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


namespace Windows.Win32.System.GroupPolicy
{
    public static partial class Apis
    {
        public const uint GPM_USE_PDC = 0;

        public const uint GPM_USE_ANYDC = 1;

        public const uint GPM_DONOTUSE_W2KDC = 2;

        public const uint GPM_DONOT_VALIDATEDC = 1;

        public const uint GPM_MIGRATIONTABLE_ONLY = 0x1;

        public const uint GPM_PROCESS_SECURITY = 0x2;

        public const uint RSOP_NO_COMPUTER = 0x10000;

        public const uint RSOP_NO_USER = 0x20000;

        public const uint RSOP_PLANNING_ASSUME_SLOW_LINK = 0x1;

        public const uint RSOP_PLANNING_ASSUME_LOOPBACK_MERGE = 0x2;

        public const uint RSOP_PLANNING_ASSUME_LOOPBACK_REPLACE = 0x4;

        public const uint RSOP_PLANNING_ASSUME_USER_WQLFILTER_TRUE = 0x8;

        public const uint RSOP_PLANNING_ASSUME_COMP_WQLFILTER_TRUE = 0x10;

        public const uint PI_NOUI = 0x00000001;

        public const uint PI_APPLYPOLICY = 0x00000002;

        public const uint PT_TEMPORARY = 0x00000001;

        public const uint PT_ROAMING = 0x00000002;

        public const uint PT_MANDATORY = 0x00000004;

        public const uint PT_ROAMING_PREEXISTING = 0x00000008;

        public const uint RP_FORCE = 1;

        public const uint RP_SYNC = 2;

        public const uint GPC_BLOCK_POLICY = 0x00000001;

        public const uint GPO_FLAG_DISABLE = 0x00000001;

        public const uint GPO_FLAG_FORCE = 0x00000002;

        public const uint GPO_LIST_FLAG_MACHINE = 0x00000001;

        public const uint GPO_LIST_FLAG_SITEONLY = 0x00000002;

        public const uint GPO_LIST_FLAG_NO_WMIFILTERS = 0x00000004;

        public const uint GPO_LIST_FLAG_NO_SECURITYFILTERS = 0x00000008;

        public const uint GPO_INFO_FLAG_MACHINE = 0x00000001;

        public const uint GPO_INFO_FLAG_BACKGROUND = 0x00000010;

        public const uint GPO_INFO_FLAG_SLOWLINK = 0x00000020;

        public const uint GPO_INFO_FLAG_VERBOSE = 0x00000040;

        public const uint GPO_INFO_FLAG_NOCHANGES = 0x00000080;

        public const uint GPO_INFO_FLAG_LINKTRANSITION = 0x00000100;

        public const uint GPO_INFO_FLAG_LOGRSOP_TRANSITION = 0x00000200;

        public const uint GPO_INFO_FLAG_FORCED_REFRESH = 0x00000400;

        public const uint GPO_INFO_FLAG_SAFEMODE_BOOT = 0x00000800;

        public const uint GPO_INFO_FLAG_ASYNC_FOREGROUND = 0x00001000;

        public const uint FLAG_NO_GPO_FILTER = 0x80000000;

        public const uint FLAG_NO_CSE_INVOKE = 0x40000000;

        public const uint FLAG_ASSUME_SLOW_LINK = 0x20000000;

        public const uint FLAG_LOOPBACK_MERGE = 0x10000000;

        public const uint FLAG_LOOPBACK_REPLACE = 0x08000000;

        public const uint FLAG_ASSUME_USER_WQLFILTER_TRUE = 0x04000000;

        public const uint FLAG_ASSUME_COMP_WQLFILTER_TRUE = 0x02000000;

        public const uint FLAG_PLANNING_MODE = 0x01000000;

        public const uint FLAG_NO_USER = 0x00000001;

        public const uint FLAG_NO_COMPUTER = 0x00000002;

        public const uint FLAG_FORCE_CREATENAMESPACE = 0x00000004;

        public const uint RSOP_USER_ACCESS_DENIED = 0x00000001;

        public const uint RSOP_COMPUTER_ACCESS_DENIED = 0x00000002;

        public const uint RSOP_TEMPNAMESPACE_EXISTS = 0x00000004;

        public const uint LOCALSTATE_ASSIGNED = 0x1;

        public const uint LOCALSTATE_PUBLISHED = 0x2;

        public const uint LOCALSTATE_UNINSTALL_UNMANAGED = 0x4;

        public const uint LOCALSTATE_POLICYREMOVE_ORPHAN = 0x8;

        public const uint LOCALSTATE_POLICYREMOVE_UNINSTALL = 0x10;

        public const uint LOCALSTATE_ORPHANED = 0x20;

        public const uint LOCALSTATE_UNINSTALLED = 0x40;

        public const uint MANAGED_APPS_USERAPPLICATIONS = 0x1;

        public const uint MANAGED_APPS_FROMCATEGORY = 0x2;

        public const uint MANAGED_APPS_INFOLEVEL_DEFAULT = 0x10000;

        public const uint MANAGED_APPTYPE_WINDOWSINSTALLER = 0x1;

        public const uint MANAGED_APPTYPE_SETUPEXE = 0x2;

        public const uint MANAGED_APPTYPE_UNSUPPORTED = 0x3;

        public static readonly Guid CLSID_GPESnapIn__scanned__ = new Guid(0x8fc0b734, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid NODEID_Machine__scanned__ = new Guid(0x8fc0b737, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid NODEID_MachineSWSettings__scanned__ = new Guid(0x8fc0b73a, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid NODEID_User__scanned__ = new Guid(0x8fc0b738, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid NODEID_UserSWSettings__scanned__ = new Guid(0x8fc0b73c, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid IID_IGPEInformation__scanned__ = new Guid(0x8fc0b735, 0xa0e1, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid CLSID_GroupPolicyObject__scanned__ = new Guid(0xea502722, 0xa23d, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid IID_IGroupPolicyObject__scanned__ = new Guid(0xea502723, 0xa23d, 0x11d1, 0xa7, 0xd3, 0x0, 0x0, 0xf8, 0x75, 0x71, 0xe3);

        public static readonly Guid CLSID_RSOPSnapIn__scanned__ = new Guid(0x6dc3804b, 0x7212, 0x458d, 0xad, 0xb0, 0x9a, 0x07, 0xe2, 0xae, 0x1f, 0xa2);

        public static readonly Guid NODEID_RSOPMachine__scanned__ = new Guid(0xbd4c1a2e, 0x0b7a, 0x4a62, 0xa6, 0xb0, 0xc0, 0x57, 0x75, 0x39, 0xc9, 0x7e);

        public static readonly Guid NODEID_RSOPMachineSWSettings__scanned__ = new Guid(0x6a76273e, 0xeb8e, 0x45db, 0x94, 0xc5, 0x25, 0x66, 0x3a, 0x5f, 0x2c, 0x1a);

        public static readonly Guid NODEID_RSOPUser__scanned__ = new Guid(0xab87364f, 0x0cec, 0x4cd8, 0x9b, 0xf8, 0x89, 0x8f, 0x34, 0x62, 0x8f, 0xb8);

        public static readonly Guid NODEID_RSOPUserSWSettings__scanned__ = new Guid(0xe52c5ce3, 0xfd27, 0x4402, 0x84, 0xde, 0xd9, 0xa5, 0xf2, 0x85, 0x89, 0x10);

        public static readonly Guid IID_IRSOPInformation__scanned__ = new Guid(0x9a5a81b5, 0xd9c7, 0x49ef, 0x9d, 0x11, 0xdd, 0xf5, 0x09, 0x68, 0xc4, 0x8d);

        public const uint GPO_SECTION_ROOT = 0;

        public const uint GPO_SECTION_USER = 1;

        public const uint GPO_SECTION_MACHINE = 2;

        public const uint GPO_OPEN_LOAD_REGISTRY = 0x00000001;

        public const uint GPO_OPEN_READ_ONLY = 0x00000002;

        public const uint GPO_OPTION_DISABLE_USER = 0x00000001;

        public const uint GPO_OPTION_DISABLE_MACHINE = 0x00000002;

        public const uint RSOP_INFO_FLAG_DIAGNOSTIC_MODE = 0x00000001;

        public const uint GPO_BROWSE_DISABLENEW = 0x00000001;

        public const uint GPO_BROWSE_NOCOMPUTERS = 0x00000002;

        public const uint GPO_BROWSE_NODSGPOS = 0x00000004;

        public const uint GPO_BROWSE_OPENBUTTON = 0x00000008;

        public const uint GPO_BROWSE_INITTOALL = 0x00000010;

        public const uint GPO_BROWSE_NOUSERGPOS = 0x00000020;

        public const uint GPO_BROWSE_SENDAPPLYONEDIT = 0x00000040;

    }
}
