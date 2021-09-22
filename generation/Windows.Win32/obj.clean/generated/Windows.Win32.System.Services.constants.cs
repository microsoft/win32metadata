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


namespace Windows.Win32.System.Services
{
    public static partial class Apis
    {
        public const uint SERVICE_NO_CHANGE = 0xffffffff;

        public const uint SERVICE_CONTROL_STOP = 0x00000001;

        public const uint SERVICE_CONTROL_PAUSE = 0x00000002;

        public const uint SERVICE_CONTROL_CONTINUE = 0x00000003;

        public const uint SERVICE_CONTROL_INTERROGATE = 0x00000004;

        public const uint SERVICE_CONTROL_SHUTDOWN = 0x00000005;

        public const uint SERVICE_CONTROL_PARAMCHANGE = 0x00000006;

        public const uint SERVICE_CONTROL_NETBINDADD = 0x00000007;

        public const uint SERVICE_CONTROL_NETBINDREMOVE = 0x00000008;

        public const uint SERVICE_CONTROL_NETBINDENABLE = 0x00000009;

        public const uint SERVICE_CONTROL_NETBINDDISABLE = 0x0000000A;

        public const uint SERVICE_CONTROL_DEVICEEVENT = 0x0000000B;

        public const uint SERVICE_CONTROL_HARDWAREPROFILECHANGE = 0x0000000C;

        public const uint SERVICE_CONTROL_POWEREVENT = 0x0000000D;

        public const uint SERVICE_CONTROL_SESSIONCHANGE = 0x0000000E;

        public const uint SERVICE_CONTROL_PRESHUTDOWN = 0x0000000F;

        public const uint SERVICE_CONTROL_TIMECHANGE = 0x00000010;

        public const uint SERVICE_CONTROL_TRIGGEREVENT = 0x00000020;

        public const uint SERVICE_CONTROL_LOWRESOURCES = 0x00000060;

        public const uint SERVICE_CONTROL_SYSTEMLOWRESOURCES = 0x00000061;

        public const uint SERVICE_ACCEPT_STOP = 0x00000001;

        public const uint SERVICE_ACCEPT_PAUSE_CONTINUE = 0x00000002;

        public const uint SERVICE_ACCEPT_SHUTDOWN = 0x00000004;

        public const uint SERVICE_ACCEPT_PARAMCHANGE = 0x00000008;

        public const uint SERVICE_ACCEPT_NETBINDCHANGE = 0x00000010;

        public const uint SERVICE_ACCEPT_HARDWAREPROFILECHANGE = 0x00000020;

        public const uint SERVICE_ACCEPT_POWEREVENT = 0x00000040;

        public const uint SERVICE_ACCEPT_SESSIONCHANGE = 0x00000080;

        public const uint SERVICE_ACCEPT_PRESHUTDOWN = 0x00000100;

        public const uint SERVICE_ACCEPT_TIMECHANGE = 0x00000200;

        public const uint SERVICE_ACCEPT_TRIGGEREVENT = 0x00000400;

        public const uint SERVICE_ACCEPT_USER_LOGOFF = 0x00000800;

        public const uint SERVICE_ACCEPT_LOWRESOURCES = 0x00002000;

        public const uint SERVICE_ACCEPT_SYSTEMLOWRESOURCES = 0x00004000;

        public const uint SC_MANAGER_CONNECT = 0x0001;

        public const uint SC_MANAGER_CREATE_SERVICE = 0x0002;

        public const uint SC_MANAGER_ENUMERATE_SERVICE = 0x0004;

        public const uint SC_MANAGER_LOCK = 0x0008;

        public const uint SC_MANAGER_QUERY_LOCK_STATUS = 0x0010;

        public const uint SC_MANAGER_MODIFY_BOOT_CONFIG = 0x0020;

        public const uint SERVICE_QUERY_CONFIG = 0x0001;

        public const uint SERVICE_CHANGE_CONFIG = 0x0002;

        public const uint SERVICE_QUERY_STATUS = 0x0004;

        public const uint SERVICE_ENUMERATE_DEPENDENTS = 0x0008;

        public const uint SERVICE_START = 0x0010;

        public const uint SERVICE_STOP = 0x0020;

        public const uint SERVICE_PAUSE_CONTINUE = 0x0040;

        public const uint SERVICE_INTERROGATE = 0x0080;

        public const uint SERVICE_USER_DEFINED_CONTROL = 0x0100;

        public const uint SERVICE_NOTIFY_STATUS_CHANGE_1 = 1;

        public const uint SERVICE_NOTIFY_STATUS_CHANGE_2 = 2;

        public const uint SERVICE_STOP_REASON_FLAG_MIN = 0x00000000;

        public const uint SERVICE_STOP_REASON_FLAG_UNPLANNED = 0x10000000;

        public const uint SERVICE_STOP_REASON_FLAG_CUSTOM = 0x20000000;

        public const uint SERVICE_STOP_REASON_FLAG_PLANNED = 0x40000000;

        public const uint SERVICE_STOP_REASON_FLAG_MAX = 0x80000000;

        public const uint SERVICE_STOP_REASON_MAJOR_MIN = 0x00000000;

        public const uint SERVICE_STOP_REASON_MAJOR_OTHER = 0x00010000;

        public const uint SERVICE_STOP_REASON_MAJOR_HARDWARE = 0x00020000;

        public const uint SERVICE_STOP_REASON_MAJOR_OPERATINGSYSTEM = 0x00030000;

        public const uint SERVICE_STOP_REASON_MAJOR_SOFTWARE = 0x00040000;

        public const uint SERVICE_STOP_REASON_MAJOR_APPLICATION = 0x00050000;

        public const uint SERVICE_STOP_REASON_MAJOR_NONE = 0x00060000;

        public const uint SERVICE_STOP_REASON_MAJOR_MAX = 0x00070000;

        public const uint SERVICE_STOP_REASON_MAJOR_MIN_CUSTOM = 0x00400000;

        public const uint SERVICE_STOP_REASON_MAJOR_MAX_CUSTOM = 0x00ff0000;

        public const uint SERVICE_STOP_REASON_MINOR_MIN = 0x00000000;

        public const uint SERVICE_STOP_REASON_MINOR_OTHER = 0x00000001;

        public const uint SERVICE_STOP_REASON_MINOR_MAINTENANCE = 0x00000002;

        public const uint SERVICE_STOP_REASON_MINOR_INSTALLATION = 0x00000003;

        public const uint SERVICE_STOP_REASON_MINOR_UPGRADE = 0x00000004;

        public const uint SERVICE_STOP_REASON_MINOR_RECONFIG = 0x00000005;

        public const uint SERVICE_STOP_REASON_MINOR_HUNG = 0x00000006;

        public const uint SERVICE_STOP_REASON_MINOR_UNSTABLE = 0x00000007;

        public const uint SERVICE_STOP_REASON_MINOR_DISK = 0x00000008;

        public const uint SERVICE_STOP_REASON_MINOR_NETWORKCARD = 0x00000009;

        public const uint SERVICE_STOP_REASON_MINOR_ENVIRONMENT = 0x0000000a;

        public const uint SERVICE_STOP_REASON_MINOR_HARDWARE_DRIVER = 0x0000000b;

        public const uint SERVICE_STOP_REASON_MINOR_OTHERDRIVER = 0x0000000c;

        public const uint SERVICE_STOP_REASON_MINOR_SERVICEPACK = 0x0000000d;

        public const uint SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE = 0x0000000e;

        public const uint SERVICE_STOP_REASON_MINOR_SECURITYFIX = 0x0000000f;

        public const uint SERVICE_STOP_REASON_MINOR_SECURITY = 0x00000010;

        public const uint SERVICE_STOP_REASON_MINOR_NETWORK_CONNECTIVITY = 0x00000011;

        public const uint SERVICE_STOP_REASON_MINOR_WMI = 0x00000012;

        public const uint SERVICE_STOP_REASON_MINOR_SERVICEPACK_UNINSTALL = 0x00000013;

        public const uint SERVICE_STOP_REASON_MINOR_SOFTWARE_UPDATE_UNINSTALL = 0x00000014;

        public const uint SERVICE_STOP_REASON_MINOR_SECURITYFIX_UNINSTALL = 0x00000015;

        public const uint SERVICE_STOP_REASON_MINOR_MMC = 0x00000016;

        public const uint SERVICE_STOP_REASON_MINOR_NONE = 0x00000017;

        public const uint SERVICE_STOP_REASON_MINOR_MEMOTYLIMIT = 0x00000018;

        public const uint SERVICE_STOP_REASON_MINOR_MAX = 0x00000019;

        public const uint SERVICE_STOP_REASON_MINOR_MIN_CUSTOM = 0x00000100;

        public const uint SERVICE_STOP_REASON_MINOR_MAX_CUSTOM = 0x0000FFFF;

        public const uint SERVICE_CONTROL_STATUS_REASON_INFO = 1;

        public const uint SERVICE_SID_TYPE_NONE = 0x00000000;

        public const uint SERVICE_SID_TYPE_UNRESTRICTED = 0x00000001;

        public const uint SERVICE_TRIGGER_TYPE_CUSTOM_SYSTEM_STATE_CHANGE = 7;

        public const uint SERVICE_TRIGGER_TYPE_AGGREGATE = 30;

        public const uint SERVICE_START_REASON_DEMAND = 0x00000001;

        public const uint SERVICE_START_REASON_AUTO = 0x00000002;

        public const uint SERVICE_START_REASON_TRIGGER = 0x00000004;

        public const uint SERVICE_START_REASON_RESTART_ON_FAILURE = 0x00000008;

        public const uint SERVICE_START_REASON_DELAYEDAUTO = 0x00000010;

        public const uint SERVICE_DYNAMIC_INFORMATION_LEVEL_START_REASON = 1;

        public const uint SERVICE_LAUNCH_PROTECTED_NONE = 0;

        public const uint SERVICE_LAUNCH_PROTECTED_WINDOWS = 1;

        public const uint SERVICE_LAUNCH_PROTECTED_WINDOWS_LIGHT = 2;

        public const uint SERVICE_LAUNCH_PROTECTED_ANTIMALWARE_LIGHT = 3;

        public static readonly Guid NETWORK_MANAGER_FIRST_IP_ADDRESS_ARRIVAL_GUID__scanned__ = new Guid(0x4f27f2de,    0x14e2,    0x430b,    0xa5, 0x49, 0x7c, 0xd4, 0x8c, 0xbc, 0x82, 0x45  );

        public static readonly Guid NETWORK_MANAGER_LAST_IP_ADDRESS_REMOVAL_GUID__scanned__ = new Guid(0xcc4ba62a,    0x162e,    0x4648,    0x84, 0x7a, 0xb6, 0xbd, 0xf9, 0x93, 0xe3, 0x35  );

        public static readonly Guid DOMAIN_JOIN_GUID__scanned__ = new Guid(0x1ce20aba,    0x9851,    0x4421,    0x94, 0x30, 0x1d, 0xde, 0xb7, 0x66, 0xe8, 0x09  );

        public static readonly Guid DOMAIN_LEAVE_GUID__scanned__ = new Guid(0xddaf516e,    0x58c2,    0x4866,    0x95, 0x74, 0xc3, 0xb6, 0x15, 0xd4, 0x2e, 0xa1  );

        public static readonly Guid FIREWALL_PORT_OPEN_GUID__scanned__ = new Guid(0xb7569e07,    0x8421,    0x4ee0,    0xad, 0x10, 0x86, 0x91, 0x5a, 0xfd, 0xad, 0x09  );

        public static readonly Guid FIREWALL_PORT_CLOSE_GUID__scanned__ = new Guid(0xa144ed38,    0x8e12,    0x4de4,    0x9d, 0x96, 0xe6, 0x47, 0x40, 0xb1, 0xa5, 0x24  );

        public static readonly Guid MACHINE_POLICY_PRESENT_GUID__scanned__ = new Guid(0x659FCAE6,    0x5BDB,    0x4DA9,    0xB1, 0xFF, 0xCA, 0x2A, 0x17, 0x8D, 0x46, 0xE0  );

        public static readonly Guid USER_POLICY_PRESENT_GUID__scanned__ = new Guid(0x54FB46C8,    0xF089,    0x464C,    0xB1, 0xFD, 0x59, 0xD1, 0xB6, 0x2C, 0x3B, 0x50  );

        public static readonly Guid RPC_INTERFACE_EVENT_GUID__scanned__ = new Guid(0xbc90d167,    0x9470,    0x4139,    0xa9, 0xba, 0xbe, 0x0b, 0xbb, 0xf5, 0xb7, 0x4d  );

        public static readonly Guid NAMED_PIPE_EVENT_GUID__scanned__ = new Guid(0x1f81d131,    0x3fac,    0x4537,    0x9e, 0x0c, 0x7e, 0x7b, 0x0c, 0x2f, 0x4b, 0x55  );

        public static readonly Guid CUSTOM_SYSTEM_STATE_CHANGE_EVENT_GUID__scanned__ = new Guid(0x2d7a2816,    0x0c5e,    0x45fc,    0x9c, 0xe7, 0x57, 0x0e, 0x5e, 0xcd, 0xe9, 0xc9  );

    }
}
