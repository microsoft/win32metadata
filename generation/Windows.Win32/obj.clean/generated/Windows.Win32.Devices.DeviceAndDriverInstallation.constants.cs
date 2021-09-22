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


namespace Windows.Win32.Devices.DeviceAndDriverInstallation
{
    public static partial class Apis
    {
        public const uint CM_PROB_NOT_CONFIGURED = 0x00000001;

        public const uint CM_PROB_DEVLOADER_FAILED = 0x00000002;

        public const uint CM_PROB_OUT_OF_MEMORY = 0x00000003;

        public const uint CM_PROB_ENTRY_IS_WRONG_TYPE = 0x00000004;

        public const uint CM_PROB_LACKED_ARBITRATOR = 0x00000005;

        public const uint CM_PROB_BOOT_CONFIG_CONFLICT = 0x00000006;

        public const uint CM_PROB_FAILED_FILTER = 0x00000007;

        public const uint CM_PROB_DEVLOADER_NOT_FOUND = 0x00000008;

        public const uint CM_PROB_INVALID_DATA = 0x00000009;

        public const uint CM_PROB_FAILED_START = 0x0000000A;

        public const uint CM_PROB_LIAR = 0x0000000B;

        public const uint CM_PROB_NORMAL_CONFLICT = 0x0000000C;

        public const uint CM_PROB_NOT_VERIFIED = 0x0000000D;

        public const uint CM_PROB_NEED_RESTART = 0x0000000E;

        public const uint CM_PROB_REENUMERATION = 0x0000000F;

        public const uint CM_PROB_PARTIAL_LOG_CONF = 0x00000010;

        public const uint CM_PROB_UNKNOWN_RESOURCE = 0x00000011;

        public const uint CM_PROB_REINSTALL = 0x00000012;

        public const uint CM_PROB_REGISTRY = 0x00000013;

        public const uint CM_PROB_VXDLDR = 0x00000014;

        public const uint CM_PROB_WILL_BE_REMOVED = 0x00000015;

        public const uint CM_PROB_DISABLED = 0x00000016;

        public const uint CM_PROB_DEVLOADER_NOT_READY = 0x00000017;

        public const uint CM_PROB_DEVICE_NOT_THERE = 0x00000018;

        public const uint CM_PROB_MOVED = 0x00000019;

        public const uint CM_PROB_TOO_EARLY = 0x0000001A;

        public const uint CM_PROB_NO_VALID_LOG_CONF = 0x0000001B;

        public const uint CM_PROB_FAILED_INSTALL = 0x0000001C;

        public const uint CM_PROB_HARDWARE_DISABLED = 0x0000001D;

        public const uint CM_PROB_CANT_SHARE_IRQ = 0x0000001E;

        public const uint CM_PROB_FAILED_ADD = 0x0000001F;

        public const uint CM_PROB_DISABLED_SERVICE = 0x00000020;

        public const uint CM_PROB_TRANSLATION_FAILED = 0x00000021;

        public const uint CM_PROB_NO_SOFTCONFIG = 0x00000022;

        public const uint CM_PROB_BIOS_TABLE = 0x00000023;

        public const uint CM_PROB_IRQ_TRANSLATION_FAILED = 0x00000024;

        public const uint CM_PROB_FAILED_DRIVER_ENTRY = 0x00000025;

        public const uint CM_PROB_DRIVER_FAILED_PRIOR_UNLOAD = 0x00000026;

        public const uint CM_PROB_DRIVER_FAILED_LOAD = 0x00000027;

        public const uint CM_PROB_DRIVER_SERVICE_KEY_INVALID = 0x00000028;

        public const uint CM_PROB_LEGACY_SERVICE_NO_DEVICES = 0x00000029;

        public const uint CM_PROB_DUPLICATE_DEVICE = 0x0000002A;

        public const uint CM_PROB_FAILED_POST_START = 0x0000002B;

        public const uint CM_PROB_HALTED = 0x0000002C;

        public const uint CM_PROB_PHANTOM = 0x0000002D;

        public const uint CM_PROB_SYSTEM_SHUTDOWN = 0x0000002E;

        public const uint CM_PROB_HELD_FOR_EJECT = 0x0000002F;

        public const uint CM_PROB_DRIVER_BLOCKED = 0x00000030;

        public const uint CM_PROB_REGISTRY_TOO_LARGE = 0x00000031;

        public const uint CM_PROB_SETPROPERTIES_FAILED = 0x00000032;

        public const uint CM_PROB_WAITING_ON_DEPENDENCY = 0x00000033;

        public const uint CM_PROB_UNSIGNED_DRIVER = 0x00000034;

        public const uint CM_PROB_USED_BY_DEBUGGER = 0x00000035;

        public const uint CM_PROB_DEVICE_RESET = 0x00000036;

        public const uint CM_PROB_CONSOLE_LOCKED = 0x00000037;

        public const uint CM_PROB_NEED_CLASS_CONFIG = 0x00000038;

        public const uint CM_PROB_GUEST_ASSIGNMENT_FAILED = 0x00000039;

        public const uint NUM_CM_PROB_V1 = 0x00000025;

        public const uint NUM_CM_PROB_V2 = 0x00000032;

        public const uint NUM_CM_PROB_V3 = 0x00000033;

        public const uint NUM_CM_PROB_V4 = 0x00000034;

        public const uint NUM_CM_PROB_V5 = 0x00000035;

        public const uint NUM_CM_PROB_V6 = 0x00000036;

        public const uint NUM_CM_PROB_V7 = 0x00000037;

        public const uint NUM_CM_PROB_V8 = 0x00000039;

        public const uint NUM_CM_PROB_V9 = 0x0000003A;

        public const uint DN_ROOT_ENUMERATED = 0x00000001;

        public const uint DN_DRIVER_LOADED = 0x00000002;

        public const uint DN_ENUM_LOADED = 0x00000004;

        public const uint DN_STARTED = 0x00000008;

        public const uint DN_MANUAL = 0x00000010;

        public const uint DN_NEED_TO_ENUM = 0x00000020;

        public const uint DN_NOT_FIRST_TIME = 0x00000040;

        public const uint DN_HARDWARE_ENUM = 0x00000080;

        public const uint DN_LIAR = 0x00000100;

        public const uint DN_HAS_MARK = 0x00000200;

        public const uint DN_HAS_PROBLEM = 0x00000400;

        public const uint DN_FILTERED = 0x00000800;

        public const uint DN_MOVED = 0x00001000;

        public const uint DN_DISABLEABLE = 0x00002000;

        public const uint DN_REMOVABLE = 0x00004000;

        public const uint DN_PRIVATE_PROBLEM = 0x00008000;

        public const uint DN_MF_PARENT = 0x00010000;

        public const uint DN_MF_CHILD = 0x00020000;

        public const uint DN_WILL_BE_REMOVED = 0x00040000;

        public const uint DN_NOT_FIRST_TIMEE = 0x00080000;

        public const uint DN_STOP_FREE_RES = 0x00100000;

        public const uint DN_REBAL_CANDIDATE = 0x00200000;

        public const uint DN_BAD_PARTIAL = 0x00400000;

        public const uint DN_NT_ENUMERATOR = 0x00800000;

        public const uint DN_NT_DRIVER = 0x01000000;

        public const uint DN_NEEDS_LOCKING = 0x02000000;

        public const uint DN_ARM_WAKEUP = 0x04000000;

        public const uint DN_APM_ENUMERATOR = 0x08000000;

        public const uint DN_APM_DRIVER = 0x10000000;

        public const uint DN_SILENT_INSTALL = 0x20000000;

        public const uint DN_NO_SHOW_IN_DM = 0x40000000;

        public const uint DN_BOOT_LOG_PROB = 0x80000000;

        public const uint LCPRI_FORCECONFIG = 0x00000000;

        public const uint LCPRI_BOOTCONFIG = 0x00000001;

        public const uint LCPRI_DESIRED = 0x00002000;

        public const uint LCPRI_NORMAL = 0x00003000;

        public const uint LCPRI_LASTBESTCONFIG = 0x00003FFF;

        public const uint LCPRI_SUBOPTIMAL = 0x00005000;

        public const uint LCPRI_LASTSOFTCONFIG = 0x00007FFF;

        public const uint LCPRI_RESTART = 0x00008000;

        public const uint LCPRI_REBOOT = 0x00009000;

        public const uint LCPRI_POWEROFF = 0x0000A000;

        public const uint LCPRI_HARDRECONFIG = 0x0000C000;

        public const uint LCPRI_HARDWIRED = 0x0000E000;

        public const uint LCPRI_IMPOSSIBLE = 0x0000F000;

        public const uint LCPRI_DISABLED = 0x0000FFFF;

        public const uint MAX_LCPRI = 0x0000FFFF;

        public const uint CM_DEVICE_PANEL_SIDE_UNKNOWN = 0x00000000;

        public const uint CM_DEVICE_PANEL_SIDE_TOP = 0x00000001;

        public const uint CM_DEVICE_PANEL_SIDE_BOTTOM = 0x00000002;

        public const uint CM_DEVICE_PANEL_SIDE_LEFT = 0x00000003;

        public const uint CM_DEVICE_PANEL_SIDE_RIGHT = 0x00000004;

        public const uint CM_DEVICE_PANEL_SIDE_FRONT = 0x00000005;

        public const uint CM_DEVICE_PANEL_SIDE_BACK = 0x00000006;

        public const uint CM_DEVICE_PANEL_EDGE_UNKNOWN = 0x00000000;

        public const uint CM_DEVICE_PANEL_EDGE_TOP = 0x00000001;

        public const uint CM_DEVICE_PANEL_EDGE_BOTTOM = 0x00000002;

        public const uint CM_DEVICE_PANEL_EDGE_LEFT = 0x00000003;

        public const uint CM_DEVICE_PANEL_EDGE_RIGHT = 0x00000004;

        public const uint CM_DEVICE_PANEL_SHAPE_UNKNOWN = 0x00000000;

        public const uint CM_DEVICE_PANEL_SHAPE_RECTANGLE = 0x00000001;

        public const uint CM_DEVICE_PANEL_SHAPE_OVAL = 0x00000002;

        public const uint CM_DEVICE_PANEL_ORIENTATION_HORIZONTAL = 0x00000000;

        public const uint CM_DEVICE_PANEL_ORIENTATION_VERTICAL = 0x00000001;

        public const uint CM_DEVICE_PANEL_JOINT_TYPE_UNKNOWN = 0x00000000;

        public const uint CM_DEVICE_PANEL_JOINT_TYPE_PLANAR = 0x00000001;

        public const uint CM_DEVICE_PANEL_JOINT_TYPE_HINGE = 0x00000002;

        public const uint CM_DEVICE_PANEL_JOINT_TYPE_PIVOT = 0x00000003;

        public const uint CM_DEVICE_PANEL_JOINT_TYPE_SWIVEL = 0x00000004;

        public const uint LINE_LEN = 256;

        public const uint MAX_INF_STRING_LENGTH = 4096;

        public const uint MAX_INF_SECTION_NAME_LENGTH = 255;

        public const uint MAX_TITLE_LEN = 60;

        public const uint MAX_INSTRUCTION_LEN = 256;

        public const uint MAX_LABEL_LEN = 30;

        public const uint MAX_SERVICE_NAME_LEN = 256;

        public const uint MAX_SUBTITLE_LEN = 256;

        public const uint SP_MAX_MACHINENAME_LENGTH = MAX_PATH + 3;

        public const uint SP_ALTPLATFORM_FLAGS_VERSION_RANGE = 0x0001;

        public const uint SP_ALTPLATFORM_FLAGS_SUITE_MASK = 0x0002;

        public const uint INF_STYLE_CACHE_ENABLE = 0x00000010;

        public const uint INF_STYLE_CACHE_DISABLE = 0x00000020;

        public const uint INF_STYLE_CACHE_IGNORE = 0x00000040;

        public const int DIRID_ABSOLUTE = -1;

        public const uint DIRID_ABSOLUTE_16BIT = 0xffff;

        public const uint DIRID_NULL = 0;

        public const uint DIRID_SRCPATH = 1;

        public const uint DIRID_WINDOWS = 10;

        public const uint DIRID_SYSTEM = 11;

        public const uint DIRID_DRIVERS = 12;

        public const uint DIRID_DRIVER_STORE = 13;

        public const uint DIRID_INF = 17;

        public const uint DIRID_HELP = 18;

        public const uint DIRID_FONTS = 20;

        public const uint DIRID_VIEWERS = 21;

        public const uint DIRID_COLOR = 23;

        public const uint DIRID_APPS = 24;

        public const uint DIRID_SHARED = 25;

        public const uint DIRID_BOOT = 30;

        public const uint DIRID_SYSTEM16 = 50;

        public const uint DIRID_SPOOL = 51;

        public const uint DIRID_SPOOLDRIVERS = 52;

        public const uint DIRID_USERPROFILE = 53;

        public const uint DIRID_LOADER = 54;

        public const uint DIRID_PRINTPROCESSOR = 55;

        public const uint DIRID_COMMON_STARTMENU = 16406;

        public const uint DIRID_COMMON_PROGRAMS = 16407;

        public const uint DIRID_COMMON_STARTUP = 16408;

        public const uint DIRID_COMMON_DESKTOPDIRECTORY = 16409;

        public const uint DIRID_COMMON_FAVORITES = 16415;

        public const uint DIRID_COMMON_APPDATA = 16419;

        public const uint DIRID_PROGRAM_FILES = 16422;

        public const uint DIRID_SYSTEM_X86 = 16425;

        public const uint DIRID_PROGRAM_FILES_X86 = 16426;

        public const uint DIRID_PROGRAM_FILES_COMMON = 16427;

        public const uint DIRID_PROGRAM_FILES_COMMONX86 = 16428;

        public const uint DIRID_COMMON_TEMPLATES = 16429;

        public const uint DIRID_COMMON_DOCUMENTS = 16430;

        public const uint DIRID_USER = 0x8000;

        public const uint SPFILENOTIFY_STARTQUEUE = 0x00000001;

        public const uint SPFILENOTIFY_ENDQUEUE = 0x00000002;

        public const uint SPFILENOTIFY_STARTSUBQUEUE = 0x00000003;

        public const uint SPFILENOTIFY_ENDSUBQUEUE = 0x00000004;

        public const uint SPFILENOTIFY_STARTDELETE = 0x00000005;

        public const uint SPFILENOTIFY_ENDDELETE = 0x00000006;

        public const uint SPFILENOTIFY_DELETEERROR = 0x00000007;

        public const uint SPFILENOTIFY_STARTRENAME = 0x00000008;

        public const uint SPFILENOTIFY_ENDRENAME = 0x00000009;

        public const uint SPFILENOTIFY_RENAMEERROR = 0x0000000a;

        public const uint SPFILENOTIFY_STARTCOPY = 0x0000000b;

        public const uint SPFILENOTIFY_ENDCOPY = 0x0000000c;

        public const uint SPFILENOTIFY_COPYERROR = 0x0000000d;

        public const uint SPFILENOTIFY_NEEDMEDIA = 0x0000000e;

        public const uint SPFILENOTIFY_QUEUESCAN = 0x0000000f;

        public const uint SPFILENOTIFY_CABINETINFO = 0x00000010;

        public const uint SPFILENOTIFY_FILEINCABINET = 0x00000011;

        public const uint SPFILENOTIFY_NEEDNEWCABINET = 0x00000012;

        public const uint SPFILENOTIFY_FILEEXTRACTED = 0x00000013;

        public const uint SPFILENOTIFY_FILEOPDELAYED = 0x00000014;

        public const uint SPFILENOTIFY_STARTBACKUP = 0x00000015;

        public const uint SPFILENOTIFY_BACKUPERROR = 0x00000016;

        public const uint SPFILENOTIFY_ENDBACKUP = 0x00000017;

        public const uint SPFILENOTIFY_QUEUESCAN_EX = 0x00000018;

        public const uint SPFILENOTIFY_STARTREGISTRATION = 0x00000019;

        public const uint SPFILENOTIFY_ENDREGISTRATION = 0x00000020;

        public const uint SPFILENOTIFY_QUEUESCAN_SIGNERINFO = 0x00000040;

        public const uint SPFILENOTIFY_LANGMISMATCH = 0x00010000;

        public const uint SPFILENOTIFY_TARGETEXISTS = 0x00020000;

        public const uint SPFILENOTIFY_TARGETNEWER = 0x00040000;

        public const uint FILEOP_RENAME = 1;

        public const uint FILEOP_BACKUP = 3;

        public const uint FILEOP_ABORT = 0;

        public const uint FILEOP_DOIT = 1;

        public const uint FILEOP_SKIP = 2;

        public const uint FILEOP_NEWPATH = 4;

        public const uint COPYFLG_WARN_IF_SKIP = 0x00000001;

        public const uint COPYFLG_NOSKIP = 0x00000002;

        public const uint COPYFLG_NOVERSIONCHECK = 0x00000004;

        public const uint COPYFLG_FORCE_FILE_IN_USE = 0x00000008;

        public const uint COPYFLG_NO_OVERWRITE = 0x00000010;

        public const uint COPYFLG_NO_VERSION_DIALOG = 0x00000020;

        public const uint COPYFLG_OVERWRITE_OLDER_ONLY = 0x00000040;

        public const uint COPYFLG_PROTECTED_WINDOWS_DRIVER_FILE = 0x00000100;

        public const uint COPYFLG_REPLACEONLY = 0x00000400;

        public const uint COPYFLG_NODECOMP = 0x00000800;

        public const uint COPYFLG_REPLACE_BOOT_FILE = 0x00001000;

        public const uint COPYFLG_NOPRUNE = 0x00002000;

        public const uint COPYFLG_IN_USE_TRY_RENAME = 0x00004000;

        public const uint DELFLG_IN_USE = 0x00000001;

        public const uint DELFLG_IN_USE1 = 0x00010000;

        public const uint SPREG_SUCCESS = 0x00000000;

        public const uint SPREG_LOADLIBRARY = 0x00000001;

        public const uint SPREG_GETPROCADDR = 0x00000002;

        public const uint SPREG_REGSVR = 0x00000003;

        public const uint SPREG_DLLINSTALL = 0x00000004;

        public const uint SPREG_TIMEOUT = 0x00000005;

        public const uint SPREG_UNKNOWN = 0xFFFFFFFF;

        public const uint SPINT_ACTIVE = 0x00000001;

        public const uint SPINT_DEFAULT = 0x00000002;

        public const uint SPINT_REMOVED = 0x00000004;

        public const uint DIF_SELECTDEVICE = 0x00000001;

        public const uint DIF_INSTALLDEVICE = 0x00000002;

        public const uint DIF_ASSIGNRESOURCES = 0x00000003;

        public const uint DIF_PROPERTIES = 0x00000004;

        public const uint DIF_REMOVE = 0x00000005;

        public const uint DIF_FIRSTTIMESETUP = 0x00000006;

        public const uint DIF_FOUNDDEVICE = 0x00000007;

        public const uint DIF_SELECTCLASSDRIVERS = 0x00000008;

        public const uint DIF_VALIDATECLASSDRIVERS = 0x00000009;

        public const uint DIF_INSTALLCLASSDRIVERS = 0x0000000A;

        public const uint DIF_CALCDISKSPACE = 0x0000000B;

        public const uint DIF_DESTROYPRIVATEDATA = 0x0000000C;

        public const uint DIF_VALIDATEDRIVER = 0x0000000D;

        public const uint DIF_DETECT = 0x0000000F;

        public const uint DIF_INSTALLWIZARD = 0x00000010;

        public const uint DIF_DESTROYWIZARDDATA = 0x00000011;

        public const uint DIF_PROPERTYCHANGE = 0x00000012;

        public const uint DIF_ENABLECLASS = 0x00000013;

        public const uint DIF_DETECTVERIFY = 0x00000014;

        public const uint DIF_INSTALLDEVICEFILES = 0x00000015;

        public const uint DIF_UNREMOVE = 0x00000016;

        public const uint DIF_SELECTBESTCOMPATDRV = 0x00000017;

        public const uint DIF_ALLOW_INSTALL = 0x00000018;

        public const uint DIF_REGISTERDEVICE = 0x00000019;

        public const uint DIF_NEWDEVICEWIZARD_PRESELECT = 0x0000001A;

        public const uint DIF_NEWDEVICEWIZARD_SELECT = 0x0000001B;

        public const uint DIF_NEWDEVICEWIZARD_PREANALYZE = 0x0000001C;

        public const uint DIF_NEWDEVICEWIZARD_POSTANALYZE = 0x0000001D;

        public const uint DIF_NEWDEVICEWIZARD_FINISHINSTALL = 0x0000001E;

        public const uint DIF_UNUSED1 = 0x0000001F;

        public const uint DIF_INSTALLINTERFACES = 0x00000020;

        public const uint DIF_DETECTCANCEL = 0x00000021;

        public const uint DIF_REGISTER_COINSTALLERS = 0x00000022;

        public const uint DIF_ADDPROPERTYPAGE_ADVANCED = 0x00000023;

        public const uint DIF_ADDPROPERTYPAGE_BASIC = 0x00000024;

        public const uint DIF_RESERVED1 = 0x00000025;

        public const uint DIF_TROUBLESHOOTER = 0x00000026;

        public const uint DIF_POWERMESSAGEWAKE = 0x00000027;

        public const uint DIF_ADDREMOTEPROPERTYPAGE_ADVANCED = 0x00000028;

        public const uint DIF_UPDATEDRIVER_UI = 0x00000029;

        public const uint DIF_FINISHINSTALL_ACTION = 0x0000002A;

        public const uint DIF_RESERVED2 = 0x00000030;

        public const uint DIF_MOVEDEVICE = 0x0000000E;

        public const int DI_SHOWOEM = 0x00000001;

        public const int DI_SHOWCOMPAT = 0x00000002;

        public const int DI_SHOWCLASS = 0x00000004;

        public const int DI_SHOWALL = 0x00000007;

        public const int DI_NOVCP = 0x00000008;

        public const int DI_DIDCOMPAT = 0x00000010;

        public const int DI_DIDCLASS = 0x00000020;

        public const int DI_AUTOASSIGNRES = 0x00000040;

        public const int DI_NEEDRESTART = 0x00000080;

        public const int DI_NEEDREBOOT = 0x00000100;

        public const int DI_NOBROWSE = 0x00000200;

        public const int DI_MULTMFGS = 0x00000400;

        public const int DI_DISABLED = 0x00000800;

        public const int DI_GENERALPAGE_ADDED = 0x00001000;

        public const int DI_RESOURCEPAGE_ADDED = 0x00002000;

        public const int DI_PROPERTIES_CHANGE = 0x00004000;

        public const int DI_INF_IS_SORTED = 0x00008000;

        public const int DI_ENUMSINGLEINF = 0x00010000;

        public const int DI_DONOTCALLCONFIGMG = 0x00020000;

        public const int DI_INSTALLDISABLED = 0x00040000;

        public const int DI_COMPAT_FROM_CLASS = 0x00080000;

        public const int DI_CLASSINSTALLPARAMS = 0x00100000;

        public const int DI_NODI_DEFAULTACTION = 0x00200000;

        public const int DI_QUIETINSTALL = 0x00800000;

        public const int DI_NOFILECOPY = 0x01000000;

        public const int DI_FORCECOPY = 0x02000000;

        public const int DI_DRIVERPAGE_ADDED = 0x04000000;

        public const int DI_USECI_SELECTSTRINGS = 0x08000000;

        public const int DI_OVERRIDE_INFFLAGS = 0x10000000;

        public const int DI_PROPS_NOCHANGEUSAGE = 0x20000000;

        public const int DI_NOSELECTICONS = 0x40000000;

        public const int DI_NOWRITE_IDS = unchecked((int)0x80000000);

        public const int DI_FLAGSEX_RESERVED2 = 0x00000001;

        public const int DI_FLAGSEX_RESERVED3 = 0x00000002;

        public const int DI_FLAGSEX_CI_FAILED = 0x00000004;

        public const int DI_FLAGSEX_FINISHINSTALL_ACTION = 0x00000008;

        public const int DI_FLAGSEX_DIDINFOLIST = 0x00000010;

        public const int DI_FLAGSEX_DIDCOMPATINFO = 0x00000020;

        public const int DI_FLAGSEX_FILTERCLASSES = 0x00000040;

        public const int DI_FLAGSEX_SETFAILEDINSTALL = 0x00000080;

        public const int DI_FLAGSEX_DEVICECHANGE = 0x00000100;

        public const int DI_FLAGSEX_ALWAYSWRITEIDS = 0x00000200;

        public const int DI_FLAGSEX_PROPCHANGE_PENDING = 0x00000400;

        public const int DI_FLAGSEX_ALLOWEXCLUDEDDRVS = 0x00000800;

        public const int DI_FLAGSEX_NOUIONQUERYREMOVE = 0x00001000;

        public const int DI_FLAGSEX_USECLASSFORCOMPAT = 0x00002000;

        public const int DI_FLAGSEX_RESERVED4 = 0x00004000;

        public const int DI_FLAGSEX_NO_DRVREG_MODIFY = 0x00008000;

        public const int DI_FLAGSEX_IN_SYSTEM_SETUP = 0x00010000;

        public const int DI_FLAGSEX_INET_DRIVER = 0x00020000;

        public const int DI_FLAGSEX_APPENDDRIVERLIST = 0x00040000;

        public const int DI_FLAGSEX_PREINSTALLBACKUP = 0x00080000;

        public const int DI_FLAGSEX_BACKUPONREPLACE = 0x00100000;

        public const int DI_FLAGSEX_DRIVERLIST_FROM_URL = 0x00200000;

        public const int DI_FLAGSEX_RESERVED1 = 0x00400000;

        public const int DI_FLAGSEX_EXCLUDE_OLD_INET_DRIVERS = 0x00800000;

        public const int DI_FLAGSEX_POWERPAGE_ADDED = 0x01000000;

        public const int DI_FLAGSEX_FILTERSIMILARDRIVERS = 0x02000000;

        public const int DI_FLAGSEX_INSTALLEDDRIVER = 0x04000000;

        public const int DI_FLAGSEX_NO_CLASSLIST_NODE_MERGE = 0x08000000;

        public const int DI_FLAGSEX_ALTPLATFORM_DRVSEARCH = 0x10000000;

        public const int DI_FLAGSEX_RESTART_DEVICE_ONLY = 0x20000000;

        public const int DI_FLAGSEX_RECURSIVESEARCH = 0x40000000;

        public const int DI_FLAGSEX_SEARCH_PUBLISHED_INFS = unchecked((int)0x80000000);

        public const uint ENABLECLASS_QUERY = 0;

        public const uint ENABLECLASS_SUCCESS = 1;

        public const uint ENABLECLASS_FAILURE = 2;

        public const uint DICS_ENABLE = 0x00000001;

        public const uint DICS_DISABLE = 0x00000002;

        public const uint DICS_PROPCHANGE = 0x00000003;

        public const uint DICS_START = 0x00000004;

        public const uint DICS_STOP = 0x00000005;

        public const uint DICS_FLAG_GLOBAL = 0x00000001;

        public const uint DICS_FLAG_CONFIGSPECIFIC = 0x00000002;

        public const uint DICS_FLAG_CONFIGGENERAL = 0x00000004;

        public const uint DI_REMOVEDEVICE_GLOBAL = 0x00000001;

        public const uint DI_REMOVEDEVICE_CONFIGSPECIFIC = 0x00000002;

        public const uint DI_UNREMOVEDEVICE_CONFIGSPECIFIC = 0x00000002;

        public const uint MAX_INSTALLWIZARD_DYNAPAGES = 20;

        public const uint NDW_INSTALLFLAG_DIDFACTDEFS = 0x00000001;

        public const uint NDW_INSTALLFLAG_HARDWAREALLREADYIN = 0x00000002;

        public const uint NDW_INSTALLFLAG_NEEDSHUTDOWN = 0x00000200;

        public const uint NDW_INSTALLFLAG_EXPRESSINTRO = 0x00000400;

        public const uint NDW_INSTALLFLAG_SKIPISDEVINSTALLED = 0x00000800;

        public const uint NDW_INSTALLFLAG_NODETECTEDDEVS = 0x00001000;

        public const uint NDW_INSTALLFLAG_INSTALLSPECIFIC = 0x00002000;

        public const uint NDW_INSTALLFLAG_SKIPCLASSLIST = 0x00004000;

        public const uint NDW_INSTALLFLAG_CI_PICKED_OEM = 0x00008000;

        public const uint NDW_INSTALLFLAG_PCMCIAMODE = 0x00010000;

        public const uint NDW_INSTALLFLAG_PCMCIADEVICE = 0x00020000;

        public const uint NDW_INSTALLFLAG_USERCANCEL = 0x00040000;

        public const uint NDW_INSTALLFLAG_KNOWNCLASS = 0x00080000;

        public const uint DYNAWIZ_FLAG_PAGESADDED = 0x00000001;

        public const uint DYNAWIZ_FLAG_ANALYZE_HANDLECONFLICT = 0x00000008;

        public const uint DYNAWIZ_FLAG_INSTALLDET_NEXT = 0x00000002;

        public const uint DYNAWIZ_FLAG_INSTALLDET_PREV = 0x00000004;

        public const uint MIN_IDD_DYNAWIZ_RESOURCE_ID = 10000;

        public const uint MAX_IDD_DYNAWIZ_RESOURCE_ID = 11000;

        public const uint IDD_DYNAWIZ_FIRSTPAGE = 10000;

        public const uint IDD_DYNAWIZ_SELECT_PREVPAGE = 10001;

        public const uint IDD_DYNAWIZ_SELECT_NEXTPAGE = 10002;

        public const uint IDD_DYNAWIZ_ANALYZE_PREVPAGE = 10003;

        public const uint IDD_DYNAWIZ_ANALYZE_NEXTPAGE = 10004;

        public const uint IDD_DYNAWIZ_SELECTDEV_PAGE = 10009;

        public const uint IDD_DYNAWIZ_ANALYZEDEV_PAGE = 10010;

        public const uint IDD_DYNAWIZ_INSTALLDETECTEDDEVS_PAGE = 10011;

        public const uint IDD_DYNAWIZ_SELECTCLASS_PAGE = 10012;

        public const uint IDD_DYNAWIZ_INSTALLDETECTED_PREVPAGE = 10006;

        public const uint IDD_DYNAWIZ_INSTALLDETECTED_NEXTPAGE = 10007;

        public const uint IDD_DYNAWIZ_INSTALLDETECTED_NODEVS = 10008;

        public const uint DNF_DUPDESC = 0x00000001;

        public const uint DNF_OLDDRIVER = 0x00000002;

        public const uint DNF_EXCLUDEFROMLIST = 0x00000004;

        public const uint DNF_NODRIVER = 0x00000008;

        public const uint DNF_LEGACYINF = 0x00000010;

        public const uint DNF_CLASS_DRIVER = 0x00000020;

        public const uint DNF_COMPATIBLE_DRIVER = 0x00000040;

        public const uint DNF_INET_DRIVER = 0x00000080;

        public const uint DNF_UNUSED1 = 0x00000100;

        public const uint DNF_UNUSED2 = 0x00000200;

        public const uint DNF_OLD_INET_DRIVER = 0x00000400;

        public const uint DNF_BAD_DRIVER = 0x00000800;

        public const uint DNF_DUPPROVIDER = 0x00001000;

        public const uint DNF_INF_IS_SIGNED = 0x00002000;

        public const uint DNF_OEM_F6_INF = 0x00004000;

        public const uint DNF_DUPDRIVERVER = 0x00008000;

        public const uint DNF_BASIC_DRIVER = 0x00010000;

        public const uint DNF_AUTHENTICODE_SIGNED = 0x00020000;

        public const uint DNF_INSTALLEDDRIVER = 0x00040000;

        public const uint DNF_ALWAYSEXCLUDEFROMLIST = 0x00080000;

        public const uint DNF_INBOX_DRIVER = 0x00100000;

        public const uint DNF_REQUESTADDITIONALSOFTWARE = 0x00200000;

        public const uint DNF_UNUSED_22 = 0x00400000;

        public const uint DNF_UNUSED_23 = 0x00800000;

        public const uint DNF_UNUSED_24 = 0x01000000;

        public const uint DNF_UNUSED_25 = 0x02000000;

        public const uint DNF_UNUSED_26 = 0x04000000;

        public const uint DNF_UNUSED_27 = 0x08000000;

        public const uint DNF_UNUSED_28 = 0x10000000;

        public const uint DNF_UNUSED_29 = 0x20000000;

        public const uint DNF_UNUSED_30 = 0x40000000;

        public const uint DNF_UNUSED_31 = 0x80000000;

        public const uint DRIVER_HARDWAREID_RANK = 0x00000FFF;

        public const uint DRIVER_HARDWAREID_MASK = 0x80000FFF;

        public const uint DRIVER_UNTRUSTED_RANK = 0x80000000;

        public const uint DRIVER_W9X_SUSPECT_RANK = 0xC0000000;

        public const uint DRIVER_COMPATID_RANK = 0x00003FFF;

        public const uint DRIVER_UNTRUSTED_HARDWAREID_RANK = 0x00008FFF;

        public const uint DRIVER_UNTRUSTED_COMPATID_RANK = 0x0000BFFF;

        public const uint DRIVER_W9X_SUSPECT_HARDWAREID_RANK = 0x0000CFFF;

        public const uint DRIVER_W9X_SUSPECT_COMPATID_RANK = 0x0000FFFF;

        public const uint SPPSR_SELECT_DEVICE_RESOURCES = 1;

        public const uint SPPSR_ENUM_BASIC_DEVICE_PROPERTIES = 2;

        public const uint SPPSR_ENUM_ADV_DEVICE_PROPERTIES = 3;

        public const uint INFINFO_INF_SPEC_IS_HINF = 1;

        public const uint INFINFO_INF_NAME_IS_ABSOLUTE = 2;

        public const uint INFINFO_DEFAULT_SEARCH = 3;

        public const uint INFINFO_REVERSE_DEFAULT_SEARCH = 4;

        public const uint INFINFO_INF_PATH_LIST_SEARCH = 5;

        public const uint FILE_COMPRESSION_NONE = 0;

        public const uint FILE_COMPRESSION_WINLZA = 1;

        public const uint FILE_COMPRESSION_MSZIP = 2;

        public const uint FILE_COMPRESSION_NTCAB = 3;

        public const uint SRCLIST_TEMPORARY = 0x00000001;

        public const uint SRCLIST_NOBROWSE = 0x00000002;

        public const uint SRCLIST_SYSTEM = 0x00000010;

        public const uint SRCLIST_USER = 0x00000020;

        public const uint SRCLIST_SYSIFADMIN = 0x00000040;

        public const uint SRCLIST_SUBDIRS = 0x00000100;

        public const uint SRCLIST_APPEND = 0x00000200;

        public const uint SRCLIST_NOSTRIPPLATFORM = 0x00000400;

        public const uint IDF_NOBROWSE = 0x00000001;

        public const uint IDF_NOSKIP = 0x00000002;

        public const uint IDF_NODETAILS = 0x00000004;

        public const uint IDF_NOCOMPRESSED = 0x00000008;

        public const uint IDF_CHECKFIRST = 0x00000100;

        public const uint IDF_NOBEEP = 0x00000200;

        public const uint IDF_NOFOREGROUND = 0x00000400;

        public const uint IDF_WARNIFSKIP = 0x00000800;

        public const uint IDF_NOREMOVABLEMEDIAPROMPT = 0x00001000;

        public const uint IDF_USEDISKNAMEASPROMPT = 0x00002000;

        public const uint IDF_OEMDISK = 0x80000000;

        public const uint DPROMPT_SUCCESS = 0;

        public const uint DPROMPT_CANCEL = 1;

        public const uint DPROMPT_SKIPFILE = 2;

        public const uint DPROMPT_BUFFERTOOSMALL = 3;

        public const uint DPROMPT_OUTOFMEMORY = 4;

        public const uint SETDIRID_NOT_FULL_PATH = 0x00000001;

        public const uint SRCINFO_PATH = 1;

        public const uint SRCINFO_TAGFILE = 2;

        public const uint SRCINFO_DESCRIPTION = 3;

        public const uint SRCINFO_FLAGS = 4;

        public const uint SRCINFO_TAGFILE2 = 5;

        public const uint SRC_FLAGS_CABFILE = 0x0010;

        public const uint SP_FLAG_CABINETCONTINUATION = 0x0000800;

        public const uint SP_BACKUP_BACKUPPASS = 0x00000001;

        public const uint SP_BACKUP_DEMANDPASS = 0x00000002;

        public const uint SP_BACKUP_SPECIAL = 0x00000004;

        public const uint SP_BACKUP_BOOTFILE = 0x00000008;

        public const uint SPQ_SCAN_FILE_PRESENCE = 0x00000001;

        public const uint SPQ_SCAN_FILE_VALIDITY = 0x00000002;

        public const uint SPQ_SCAN_USE_CALLBACK = 0x00000004;

        public const uint SPQ_SCAN_USE_CALLBACKEX = 0x00000008;

        public const uint SPQ_SCAN_INFORM_USER = 0x00000010;

        public const uint SPQ_SCAN_PRUNE_COPY_QUEUE = 0x00000020;

        public const uint SPQ_SCAN_USE_CALLBACK_SIGNERINFO = 0x00000040;

        public const uint SPQ_SCAN_PRUNE_DELREN = 0x00000080;

        public const uint SPQ_SCAN_FILE_PRESENCE_WITHOUT_SOURCE = 0x00000100;

        public const uint SPQ_SCAN_FILE_COMPARISON = 0x00000200;

        public const uint SPQ_SCAN_ACTIVATE_DRP = 0x00000400;

        public const uint SPQ_DELAYED_COPY = 0x00000001;

        public const uint SPQ_FLAG_BACKUP_AWARE = 0x00000001;

        public const uint SPQ_FLAG_ABORT_IF_UNSIGNED = 0x00000002;

        public const uint SPQ_FLAG_FILES_MODIFIED = 0x00000004;

        public const uint SPQ_FLAG_DO_SHUFFLEMOVE = 0x00000008;

        public const uint SPQ_FLAG_VALID = 0x0000000F;

        public const uint SPOST_MAX = 3;

        public const uint SUOI_FORCEDELETE = 0x00000001;

        public const uint SUOI_INTERNAL1 = 0x00000002;

        public const uint SPDSL_IGNORE_DISK = 0x00000001;

        public const uint SPDSL_DISALLOW_NEGATIVE_ADJUST = 0x00000002;

        public const uint SPFILEQ_FILE_IN_USE = 0x00000001;

        public const uint SPFILEQ_REBOOT_RECOMMENDED = 0x00000002;

        public const uint SPFILEQ_REBOOT_IN_PROGRESS = 0x00000004;

        public const uint FLG_ADDREG_DELREG_BIT = 0x00008000;

        public const uint FLG_ADDREG_BINVALUETYPE = 0x00000001;

        public const uint FLG_ADDREG_NOCLOBBER = 0x00000002;

        public const uint FLG_ADDREG_DELVAL = 0x00000004;

        public const uint FLG_ADDREG_APPEND = 0x00000008;

        public const uint FLG_ADDREG_KEYONLY = 0x00000010;

        public const uint FLG_ADDREG_OVERWRITEONLY = 0x00000020;

        public const uint FLG_ADDREG_64BITKEY = 0x00001000;

        public const uint FLG_ADDREG_KEYONLY_COMMON = 0x00002000;

        public const uint FLG_ADDREG_32BITKEY = 0x00004000;

        public const uint FLG_ADDREG_TYPE_SZ = 0x00000000;

        public const uint FLG_ADDREG_TYPE_MULTI_SZ = 0x00010000;

        public const uint FLG_ADDREG_TYPE_EXPAND_SZ = 0x00020000;

        public const uint FLG_DELREG_VALUE = 0x00000000;

        public const uint FLG_DELREG_OPERATION_MASK = 0x000000FE;

        public const uint FLG_BITREG_CLEARBITS = 0x00000000;

        public const uint FLG_BITREG_SETBITS = 0x00000001;

        public const uint FLG_BITREG_64BITKEY = 0x00001000;

        public const uint FLG_BITREG_32BITKEY = 0x00004000;

        public const uint FLG_INI2REG_64BITKEY = 0x00001000;

        public const uint FLG_INI2REG_32BITKEY = 0x00004000;

        public const uint FLG_REGSVR_DLLREGISTER = 0x00000001;

        public const uint FLG_REGSVR_DLLINSTALL = 0x00000002;

        public const uint FLG_PROFITEM_CURRENTUSER = 0x00000001;

        public const uint FLG_PROFITEM_DELETE = 0x00000002;

        public const uint FLG_PROFITEM_GROUP = 0x00000004;

        public const uint FLG_PROFITEM_CSIDL = 0x00000008;

        public const uint FLG_ADDPROPERTY_NOCLOBBER = 0x00000001;

        public const uint FLG_ADDPROPERTY_OVERWRITEONLY = 0x00000002;

        public const uint FLG_ADDPROPERTY_APPEND = 0x00000004;

        public const uint FLG_ADDPROPERTY_OR = 0x00000008;

        public const uint FLG_ADDPROPERTY_AND = 0x00000010;

        public const uint FLG_DELPROPERTY_MULTI_SZ_DELSTRING = 0x00000001;

        public const uint SPINST_LOGCONFIG = 0x00000001;

        public const uint SPINST_INIFILES = 0x00000002;

        public const uint SPINST_REGISTRY = 0x00000004;

        public const uint SPINST_INI2REG = 0x00000008;

        public const uint SPINST_FILES = 0x00000010;

        public const uint SPINST_BITREG = 0x00000020;

        public const uint SPINST_REGSVR = 0x00000040;

        public const uint SPINST_UNREGSVR = 0x00000080;

        public const uint SPINST_PROFILEITEMS = 0x00000100;

        public const uint SPINST_COPYINF = 0x00000200;

        public const uint SPINST_PROPERTIES = 0x00000400;

        public const uint SPINST_ALL = 0x000007ff;

        public const uint SPINST_SINGLESECTION = 0x00010000;

        public const uint SPINST_LOGCONFIG_IS_FORCED = 0x00020000;

        public const uint SPINST_LOGCONFIGS_ARE_OVERRIDES = 0x00040000;

        public const uint SPINST_REGISTERCALLBACKAWARE = 0x00080000;

        public const uint SPINST_DEVICEINSTALL = 0x00100000;

        public const uint SPSVCINST_TAGTOFRONT = 0x00000001;

        public const uint SPSVCINST_ASSOCSERVICE = 0x00000002;

        public const uint SPSVCINST_DELETEEVENTLOGENTRY = 0x00000004;

        public const uint SPSVCINST_NOCLOBBER_DISPLAYNAME = 0x00000008;

        public const uint SPSVCINST_NOCLOBBER_STARTTYPE = 0x00000010;

        public const uint SPSVCINST_NOCLOBBER_ERRORCONTROL = 0x00000020;

        public const uint SPSVCINST_NOCLOBBER_LOADORDERGROUP = 0x00000040;

        public const uint SPSVCINST_NOCLOBBER_DEPENDENCIES = 0x00000080;

        public const uint SPSVCINST_NOCLOBBER_DESCRIPTION = 0x00000100;

        public const uint SPSVCINST_STOPSERVICE = 0x00000200;

        public const uint SPSVCINST_CLOBBER_SECURITY = 0x00000400;

        public const uint SPSVCINST_STARTSERVICE = 0x00000800;

        public const uint SPSVCINST_NOCLOBBER_REQUIREDPRIVILEGES = 0x00001000;

        public const uint SPSVCINST_NOCLOBBER_TRIGGERS = 0x00002000;

        public const uint SPSVCINST_NOCLOBBER_SERVICESIDTYPE = 0x00004000;

        public const uint SPSVCINST_NOCLOBBER_DELAYEDAUTOSTART = 0x00008000;

        public const uint SPFILELOG_SYSTEMLOG = 0x00000001;

        public const uint SPFILELOG_FORCENEW = 0x00000002;

        public const uint SPFILELOG_QUERYONLY = 0x00000004;

        public const uint SPFILELOG_OEMFILE = 0x00000001;

        public const uint LogSevInformation = 0x00000000;

        public const uint LogSevWarning = 0x00000001;

        public const uint LogSevError = 0x00000002;

        public const uint LogSevFatalError = 0x00000003;

        public const uint LogSevMaximum = 0x00000004;

        public const uint DICD_GENERATE_ID = 0x00000001;

        public const uint DICD_INHERIT_CLASSDRVS = 0x00000002;

        public const uint DIOD_INHERIT_CLASSDRVS = 0x00000002;

        public const uint DIOD_CANCEL_REMOVE = 0x00000004;

        public const uint DIODI_NO_ADD = 0x00000001;

        public const uint SPRDI_FIND_DUPS = 0x00000001;

        public const uint SPDIT_NODRIVER = 0x00000000;

        public const uint DIGCF_DEFAULT = 0x00000001;

        public const uint DIGCF_PRESENT = 0x00000002;

        public const uint DIGCF_ALLCLASSES = 0x00000004;

        public const uint DIGCF_PROFILE = 0x00000008;

        public const uint DIGCF_DEVICEINTERFACE = 0x00000010;

        public const uint DIBCI_NOINSTALLCLASS = 0x00000001;

        public const uint DIBCI_NODISPLAYCLASS = 0x00000002;

        public const uint DIOCR_INSTALLER = 0x00000001;

        public const uint DIOCR_INTERFACE = 0x00000002;

        public const uint DIREG_DEV = 0x00000001;

        public const uint DIREG_DRV = 0x00000002;

        public const uint DIREG_BOTH = 0x00000004;

        public const uint DICLASSPROP_INSTALLER = 0x00000001;

        public const uint DICLASSPROP_INTERFACE = 0x00000002;

        public const uint SPDRP_DEVICEDESC = 0x00000000;

        public const uint SPDRP_HARDWAREID = 0x00000001;

        public const uint SPDRP_COMPATIBLEIDS = 0x00000002;

        public const uint SPDRP_UNUSED0 = 0x00000003;

        public const uint SPDRP_SERVICE = 0x00000004;

        public const uint SPDRP_UNUSED1 = 0x00000005;

        public const uint SPDRP_UNUSED2 = 0x00000006;

        public const uint SPDRP_CLASS = 0x00000007;

        public const uint SPDRP_CLASSGUID = 0x00000008;

        public const uint SPDRP_DRIVER = 0x00000009;

        public const uint SPDRP_CONFIGFLAGS = 0x0000000A;

        public const uint SPDRP_MFG = 0x0000000B;

        public const uint SPDRP_FRIENDLYNAME = 0x0000000C;

        public const uint SPDRP_LOCATION_INFORMATION = 0x0000000D;

        public const uint SPDRP_PHYSICAL_DEVICE_OBJECT_NAME = 0x0000000E;

        public const uint SPDRP_CAPABILITIES = 0x0000000F;

        public const uint SPDRP_UI_NUMBER = 0x00000010;

        public const uint SPDRP_UPPERFILTERS = 0x00000011;

        public const uint SPDRP_LOWERFILTERS = 0x00000012;

        public const uint SPDRP_BUSTYPEGUID = 0x00000013;

        public const uint SPDRP_LEGACYBUSTYPE = 0x00000014;

        public const uint SPDRP_BUSNUMBER = 0x00000015;

        public const uint SPDRP_ENUMERATOR_NAME = 0x00000016;

        public const uint SPDRP_SECURITY = 0x00000017;

        public const uint SPDRP_SECURITY_SDS = 0x00000018;

        public const uint SPDRP_DEVTYPE = 0x00000019;

        public const uint SPDRP_EXCLUSIVE = 0x0000001A;

        public const uint SPDRP_CHARACTERISTICS = 0x0000001B;

        public const uint SPDRP_ADDRESS = 0x0000001C;

        public const uint SPDRP_UI_NUMBER_DESC_FORMAT = 0X0000001D;

        public const uint SPDRP_DEVICE_POWER_DATA = 0x0000001E;

        public const uint SPDRP_REMOVAL_POLICY = 0x0000001F;

        public const uint SPDRP_REMOVAL_POLICY_HW_DEFAULT = 0x00000020;

        public const uint SPDRP_REMOVAL_POLICY_OVERRIDE = 0x00000021;

        public const uint SPDRP_INSTALL_STATE = 0x00000022;

        public const uint SPDRP_LOCATION_PATHS = 0x00000023;

        public const uint SPDRP_BASE_CONTAINERID = 0x00000024;

        public const uint SPDRP_MAXIMUM_PROPERTY = 0x00000025;

        public const uint SPCRP_UPPERFILTERS = 0x00000011;

        public const uint SPCRP_LOWERFILTERS = 0x00000012;

        public const uint SPCRP_SECURITY = 0x00000017;

        public const uint SPCRP_SECURITY_SDS = 0x00000018;

        public const uint SPCRP_DEVTYPE = 0x00000019;

        public const uint SPCRP_EXCLUSIVE = 0x0000001A;

        public const uint SPCRP_CHARACTERISTICS = 0x0000001B;

        public const uint SPCRP_MAXIMUM_PROPERTY = 0x0000001C;

        public const uint DMI_MASK = 0x00000001;

        public const uint DMI_BKCOLOR = 0x00000002;

        public const uint DMI_USERECT = 0x00000004;

        public const uint DIGCDP_FLAG_BASIC = 0x00000001;

        public const uint DIGCDP_FLAG_ADVANCED = 0x00000002;

        public const uint DIGCDP_FLAG_REMOTE_BASIC = 0x00000003;

        public const uint DIGCDP_FLAG_REMOTE_ADVANCED = 0x00000004;

        public const uint IDI_RESOURCEFIRST = 159;

        public const uint IDI_RESOURCE = 159;

        public const uint IDI_RESOURCELAST = 161;

        public const uint IDI_RESOURCEOVERLAYFIRST = 161;

        public const uint IDI_RESOURCEOVERLAYLAST = 161;

        public const uint IDI_CONFLICT = 161;

        public const uint IDI_CLASSICON_OVERLAYFIRST = 500;

        public const uint IDI_CLASSICON_OVERLAYLAST = 502;

        public const uint IDI_PROBLEM_OVL = 500;

        public const uint IDI_DISABLED_OVL = 501;

        public const uint IDI_FORCED_OVL = 502;

        public const uint SPWPT_SELECTDEVICE = 0x00000001;

        public const uint SPWP_USE_DEVINFO_DATA = 0x00000001;

        public const uint SIGNERSCORE_UNKNOWN = 0xFF000000;

        public const uint SIGNERSCORE_W9X_SUSPECT = 0xC0000000;

        public const uint SIGNERSCORE_UNSIGNED = 0x80000000;

        public const uint SIGNERSCORE_AUTHENTICODE = 0x0F000000;

        public const uint SIGNERSCORE_WHQL = 0x0D000005;

        public const uint SIGNERSCORE_UNCLASSIFIED = 0x0D000004;

        public const uint SIGNERSCORE_INBOX = 0x0D000003;

        public const uint SIGNERSCORE_LOGO_STANDARD = 0x0D000002;

        public const uint SIGNERSCORE_LOGO_PREMIUM = 0x0D000001;

        public const uint SIGNERSCORE_MASK = 0xFF000000;

        public const uint SIGNERSCORE_SIGNED_MASK = 0xF0000000;

        public const uint DICUSTOMDEVPROP_MERGE_MULTISZ = 0x00000001;

        public const uint SCWMI_CLOBBER_SECURITY = 0x00000001;

        public const uint MAX_DEVICE_ID_LEN = 200;

        public const uint MAX_GUID_STRING_LEN = 39;

        public const uint MAX_CLASS_NAME_LEN = 32;

        public const uint MAX_PROFILE_LEN = 80;

        public const uint MAX_CONFIG_VALUE = 9999;

        public const uint MAX_INSTANCE_VALUE = 9999;

        public const uint MAX_MEM_REGISTERS = 9;

        public const uint MAX_IO_PORTS = 20;

        public const uint MAX_IRQS = 7;

        public const uint MAX_DMA_CHANNELS = 7;

        public const uint DWORD_MAX = 0xffffffff;

        public const uint CONFIGMG_VERSION = 0x0400;

        public const uint CM_CDMASK_DEVINST = 0x00000001;

        public const uint CM_CDMASK_RESDES = 0x00000002;

        public const uint CM_CDMASK_FLAGS = 0x00000004;

        public const uint CM_CDMASK_DESCRIPTION = 0x00000008;

        public const uint CM_CDMASK_VALID = 0x0000000F;

        public const uint CM_CDFLAGS_DRIVER = 0x00000001;

        public const uint CM_CDFLAGS_ROOT_OWNED = 0x00000002;

        public const uint CM_CDFLAGS_RESERVED = 0x00000004;

        public const uint IO_ALIAS_10_BIT_DECODE = 0x00000004;

        public const uint IO_ALIAS_12_BIT_DECODE = 0x00000010;

        public const uint IO_ALIAS_16_BIT_DECODE = 0x00000000;

        public const uint IO_ALIAS_POSITIVE_DECODE = 0x000000FF;

        public const uint IOA_Local = 0xff;

        public const uint CM_RESDES_WIDTH_DEFAULT = 0x00000000;

        public const uint CM_RESDES_WIDTH_32 = 0x00000001;

        public const uint CM_RESDES_WIDTH_64 = 0x00000002;

        public const uint CM_RESDES_WIDTH_BITS = 0x00000003;

        public const uint PCD_MAX_MEMORY = 2;

        public const uint PCD_MAX_IO = 2;

        public const uint CM_HWPI_NOT_DOCKABLE = 0x00000000;

        public const uint CM_HWPI_UNDOCKED = 0x00000001;

        public const uint CM_HWPI_DOCKED = 0x00000002;

        public const uint ResType_All = 0x00000000;

        public const uint ResType_None = 0x00000000;

        public const uint ResType_Mem = 0x00000001;

        public const uint ResType_IO = 0x00000002;

        public const uint ResType_DMA = 0x00000003;

        public const uint ResType_IRQ = 0x00000004;

        public const uint ResType_DoNotUse = 0x00000005;

        public const uint ResType_BusNumber = 0x00000006;

        public const uint ResType_MemLarge = 0x00000007;

        public const uint ResType_MAX = 0x00000007;

        public const uint ResType_Ignored_Bit = 0x00008000;

        public const uint ResType_ClassSpecific = 0x0000FFFF;

        public const uint ResType_Reserved = 0x00008000;

        public const uint ResType_DevicePrivate = 0x00008001;

        public const uint ResType_PcCardConfig = 0x00008002;

        public const uint ResType_MfCardConfig = 0x00008003;

        public const uint ResType_Connection = 0x00008004;

        public const uint CM_ADD_RANGE_ADDIFCONFLICT = 0x00000000;

        public const uint CM_ADD_RANGE_DONOTADDIFCONFLICT = 0x00000001;

        public const uint CM_ADD_RANGE_BITS = 0x00000001;

        public const uint BASIC_LOG_CONF = 0x00000000;

        public const uint FILTERED_LOG_CONF = 0x00000001;

        public const uint ALLOC_LOG_CONF = 0x00000002;

        public const uint BOOT_LOG_CONF = 0x00000003;

        public const uint FORCED_LOG_CONF = 0x00000004;

        public const uint OVERRIDE_LOG_CONF = 0x00000005;

        public const uint NUM_LOG_CONF = 0x00000006;

        public const uint LOG_CONF_BITS = 0x00000007;

        public const uint PRIORITY_EQUAL_FIRST = 0x00000008;

        public const uint PRIORITY_EQUAL_LAST = 0x00000000;

        public const uint PRIORITY_BIT = 0x00000008;

        public const uint RegDisposition_OpenAlways = 0x00000000;

        public const uint RegDisposition_OpenExisting = 0x00000001;

        public const uint RegDisposition_Bits = 0x00000001;

        public const uint CM_ADD_ID_HARDWARE = 0x00000000;

        public const uint CM_ADD_ID_COMPATIBLE = 0x00000001;

        public const uint CM_ADD_ID_BITS = 0x00000001;

        public const uint CM_CREATE_DEVNODE_NORMAL = 0x00000000;

        public const uint CM_CREATE_DEVNODE_NO_WAIT_INSTALL = 0x00000001;

        public const uint CM_CREATE_DEVNODE_PHANTOM = 0x00000002;

        public const uint CM_CREATE_DEVNODE_GENERATE_ID = 0x00000004;

        public const uint CM_CREATE_DEVNODE_DO_NOT_INSTALL = 0x00000008;

        public const uint CM_CREATE_DEVNODE_BITS = 0x0000000F;

        public const uint CM_DELETE_CLASS_ONLY = 0x00000000;

        public const uint CM_DELETE_CLASS_SUBKEYS = 0x00000001;

        public const uint CM_DELETE_CLASS_INTERFACE = 0x00000002;

        public const uint CM_DELETE_CLASS_BITS = 0x00000003;

        public const uint CM_ENUMERATE_CLASSES_INSTALLER = 0x00000000;

        public const uint CM_ENUMERATE_CLASSES_INTERFACE = 0x00000001;

        public const uint CM_ENUMERATE_CLASSES_BITS = 0x00000001;

        public const uint CM_DETECT_NEW_PROFILE = 0x00000001;

        public const uint CM_DETECT_CRASHED = 0x00000002;

        public const uint CM_DETECT_HWPROF_FIRST_BOOT = 0x00000004;

        public const uint CM_DETECT_RUN = 0x80000000;

        public const uint CM_DETECT_BITS = 0x80000007;

        public const uint CM_DISABLE_POLITE = 0x00000000;

        public const uint CM_DISABLE_ABSOLUTE = 0x00000001;

        public const uint CM_DISABLE_HARDWARE = 0x00000002;

        public const uint CM_DISABLE_UI_NOT_OK = 0x00000004;

        public const uint CM_DISABLE_PERSIST = 0x00000008;

        public const uint CM_DISABLE_BITS = 0x0000000F;

        public const uint CM_GETIDLIST_FILTER_NONE = 0x00000000;

        public const uint CM_GETIDLIST_FILTER_ENUMERATOR = 0x00000001;

        public const uint CM_GETIDLIST_FILTER_SERVICE = 0x00000002;

        public const uint CM_GETIDLIST_FILTER_EJECTRELATIONS = 0x00000004;

        public const uint CM_GETIDLIST_FILTER_REMOVALRELATIONS = 0x00000008;

        public const uint CM_GETIDLIST_FILTER_POWERRELATIONS = 0x00000010;

        public const uint CM_GETIDLIST_FILTER_BUSRELATIONS = 0x00000020;

        public const uint CM_GETIDLIST_DONOTGENERATE = 0x10000040;

        public const uint CM_GETIDLIST_FILTER_BITS = 0x1000007F;

        public const uint CM_GETIDLIST_FILTER_TRANSPORTRELATIONS = 0x00000080;

        public const uint CM_GETIDLIST_FILTER_PRESENT = 0x00000100;

        public const uint CM_GETIDLIST_FILTER_CLASS = 0x00000200;

        public const uint CM_GET_DEVICE_INTERFACE_LIST_PRESENT = 0x00000000;

        public const uint CM_GET_DEVICE_INTERFACE_LIST_ALL_DEVICES = 0x00000001;

        public const uint CM_GET_DEVICE_INTERFACE_LIST_BITS = 0x00000001;

        public const uint CM_DRP_DEVICEDESC = 0x00000001;

        public const uint CM_DRP_HARDWAREID = 0x00000002;

        public const uint CM_DRP_COMPATIBLEIDS = 0x00000003;

        public const uint CM_DRP_UNUSED0 = 0x00000004;

        public const uint CM_DRP_SERVICE = 0x00000005;

        public const uint CM_DRP_UNUSED1 = 0x00000006;

        public const uint CM_DRP_UNUSED2 = 0x00000007;

        public const uint CM_DRP_CLASS = 0x00000008;

        public const uint CM_DRP_CLASSGUID = 0x00000009;

        public const uint CM_DRP_DRIVER = 0x0000000A;

        public const uint CM_DRP_CONFIGFLAGS = 0x0000000B;

        public const uint CM_DRP_MFG = 0x0000000C;

        public const uint CM_DRP_FRIENDLYNAME = 0x0000000D;

        public const uint CM_DRP_LOCATION_INFORMATION = 0x0000000E;

        public const uint CM_DRP_PHYSICAL_DEVICE_OBJECT_NAME = 0x0000000F;

        public const uint CM_DRP_CAPABILITIES = 0x00000010;

        public const uint CM_DRP_UI_NUMBER = 0x00000011;

        public const uint CM_DRP_UPPERFILTERS = 0x00000012;

        public const uint CM_DRP_LOWERFILTERS = 0x00000013;

        public const uint CM_DRP_BUSTYPEGUID = 0x00000014;

        public const uint CM_DRP_LEGACYBUSTYPE = 0x00000015;

        public const uint CM_DRP_BUSNUMBER = 0x00000016;

        public const uint CM_DRP_ENUMERATOR_NAME = 0x00000017;

        public const uint CM_DRP_SECURITY = 0x00000018;

        public const uint CM_DRP_SECURITY_SDS = 0x00000019;

        public const uint CM_DRP_DEVTYPE = 0x0000001A;

        public const uint CM_DRP_EXCLUSIVE = 0x0000001B;

        public const uint CM_DRP_CHARACTERISTICS = 0x0000001C;

        public const uint CM_DRP_ADDRESS = 0x0000001D;

        public const uint CM_DRP_UI_NUMBER_DESC_FORMAT = 0x0000001E;

        public const uint CM_DRP_DEVICE_POWER_DATA = 0x0000001F;

        public const uint CM_DRP_REMOVAL_POLICY = 0x00000020;

        public const uint CM_DRP_REMOVAL_POLICY_HW_DEFAULT = 0x00000021;

        public const uint CM_DRP_REMOVAL_POLICY_OVERRIDE = 0x00000022;

        public const uint CM_DRP_INSTALL_STATE = 0x00000023;

        public const uint CM_DRP_LOCATION_PATHS = 0x00000024;

        public const uint CM_DRP_BASE_CONTAINERID = 0x00000025;

        public const uint CM_DRP_MIN = 0x00000001;

        public const uint CM_DRP_MAX = 0x00000025;

        public const uint CM_DEVCAP_LOCKSUPPORTED = 0x00000001;

        public const uint CM_DEVCAP_EJECTSUPPORTED = 0x00000002;

        public const uint CM_DEVCAP_REMOVABLE = 0x00000004;

        public const uint CM_DEVCAP_DOCKDEVICE = 0x00000008;

        public const uint CM_DEVCAP_UNIQUEID = 0x00000010;

        public const uint CM_DEVCAP_SILENTINSTALL = 0x00000020;

        public const uint CM_DEVCAP_RAWDEVICEOK = 0x00000040;

        public const uint CM_DEVCAP_SURPRISEREMOVALOK = 0x00000080;

        public const uint CM_DEVCAP_HARDWAREDISABLED = 0x00000100;

        public const uint CM_DEVCAP_NONDYNAMIC = 0x00000200;

        public const uint CM_DEVCAP_SECUREDEVICE = 0x00000400;

        public const uint CM_REMOVAL_POLICY_EXPECT_NO_REMOVAL = 1;

        public const uint CM_REMOVAL_POLICY_EXPECT_ORDERLY_REMOVAL = 2;

        public const uint CM_REMOVAL_POLICY_EXPECT_SURPRISE_REMOVAL = 3;

        public const uint CM_INSTALL_STATE_INSTALLED = 0;

        public const uint CM_INSTALL_STATE_NEEDS_REINSTALL = 1;

        public const uint CM_INSTALL_STATE_FAILED_INSTALL = 2;

        public const uint CM_INSTALL_STATE_FINISH_INSTALL = 3;

        public const uint CM_LOCATE_DEVNODE_NORMAL = 0x00000000;

        public const uint CM_LOCATE_DEVNODE_PHANTOM = 0x00000001;

        public const uint CM_LOCATE_DEVNODE_CANCELREMOVE = 0x00000002;

        public const uint CM_LOCATE_DEVNODE_NOVALIDATION = 0x00000004;

        public const uint CM_LOCATE_DEVNODE_BITS = 0x00000007;

        public const uint CM_OPEN_CLASS_KEY_INSTALLER = 0x00000000;

        public const uint CM_OPEN_CLASS_KEY_INTERFACE = 0x00000001;

        public const uint CM_OPEN_CLASS_KEY_BITS = 0x00000001;

        public const uint CM_REMOVE_UI_OK = 0x00000000;

        public const uint CM_REMOVE_UI_NOT_OK = 0x00000001;

        public const uint CM_REMOVE_NO_RESTART = 0x00000002;

        public const uint CM_REMOVE_BITS = 0x00000003;

        public const uint CM_REENUMERATE_NORMAL = 0x00000000;

        public const uint CM_REENUMERATE_SYNCHRONOUS = 0x00000001;

        public const uint CM_REENUMERATE_RETRY_INSTALLATION = 0x00000002;

        public const uint CM_REENUMERATE_ASYNCHRONOUS = 0x00000004;

        public const uint CM_REENUMERATE_BITS = 0x00000007;

        public const uint CM_REGISTER_DEVICE_DRIVER_STATIC = 0x00000000;

        public const uint CM_REGISTER_DEVICE_DRIVER_DISABLEABLE = 0x00000001;

        public const uint CM_REGISTER_DEVICE_DRIVER_REMOVABLE = 0x00000002;

        public const uint CM_REGISTER_DEVICE_DRIVER_BITS = 0x00000003;

        public const uint CM_REGISTRY_HARDWARE = 0x00000000;

        public const uint CM_REGISTRY_SOFTWARE = 0x00000001;

        public const uint CM_REGISTRY_USER = 0x00000100;

        public const uint CM_REGISTRY_CONFIG = 0x00000200;

        public const uint CM_REGISTRY_BITS = 0x00000301;

        public const uint CM_SET_DEVNODE_PROBLEM_NORMAL = 0x00000000;

        public const uint CM_SET_DEVNODE_PROBLEM_OVERRIDE = 0x00000001;

        public const uint CM_SET_DEVNODE_PROBLEM_BITS = 0x00000001;

        public const uint CM_SET_HW_PROF_FLAGS_UI_NOT_OK = 0x00000001;

        public const uint CM_SET_HW_PROF_FLAGS_BITS = 0x00000001;

        public const uint CM_SETUP_DEVNODE_READY = 0x00000000;

        public const uint CM_SETUP_DOWNLOAD = 0x00000001;

        public const uint CM_SETUP_WRITE_LOG_CONFS = 0x00000002;

        public const uint CM_SETUP_PROP_CHANGE = 0x00000003;

        public const uint CM_SETUP_DEVNODE_RESET = 0x00000004;

        public const uint CM_SETUP_DEVNODE_CONFIG = 0x00000005;

        public const uint CM_SETUP_DEVNODE_CONFIG_CLASS = 0x00000006;

        public const uint CM_SETUP_DEVNODE_CONFIG_EXTENSIONS = 0x00000007;

        public const uint CM_SETUP_DEVNODE_CONFIG_RESET = 0x00000008;

        public const uint CM_SETUP_BITS = 0x0000000F;

        public const uint CM_QUERY_ARBITRATOR_RAW = 0x00000000;

        public const uint CM_QUERY_ARBITRATOR_TRANSLATED = 0x00000001;

        public const uint CM_QUERY_ARBITRATOR_BITS = 0x00000001;

        public const uint CM_CUSTOMDEVPROP_MERGE_MULTISZ = 0x00000001;

        public const uint CM_CUSTOMDEVPROP_BITS = 0x00000001;

        public const uint CM_NAME_ATTRIBUTE_NAME_RETRIEVED_FROM_DEVICE = 0x1;

        public const uint CM_NAME_ATTRIBUTE_USER_ASSIGNED_NAME = 0x2;

        public const uint CM_CLASS_PROPERTY_INSTALLER = 0x00000000;

        public const uint CM_CLASS_PROPERTY_INTERFACE = 0x00000001;

        public const uint CM_CLASS_PROPERTY_BITS = 0x00000001;

        public const uint CM_NOTIFY_FILTER_FLAG_ALL_INTERFACE_CLASSES = 0x00000001;

        public const uint CM_NOTIFY_FILTER_FLAG_ALL_DEVICE_INSTANCES = 0x00000002;

        public const uint CM_GLOBAL_STATE_CAN_DO_UI = 0x00000001;

        public const uint CM_GLOBAL_STATE_ON_BIG_STACK = 0x00000002;

        public const uint CM_GLOBAL_STATE_SERVICES_AVAILABLE = 0x00000004;

        public const uint CM_GLOBAL_STATE_SHUTTING_DOWN = 0x00000008;

        public const uint CM_GLOBAL_STATE_DETECTION_PENDING = 0x00000010;

        public const uint CM_GLOBAL_STATE_REBOOT_REQUIRED = 0x00000020;

        public const uint INSTALLFLAG_FORCE = 0x00000001;

        public const uint INSTALLFLAG_READONLY = 0x00000002;

        public const uint INSTALLFLAG_NONINTERACTIVE = 0x00000004;

        public const uint INSTALLFLAG_BITS = 0x00000007;

        public const uint DIIDFLAG_SHOWSEARCHUI = 0x00000001;

        public const uint DIIDFLAG_NOFINISHINSTALLUI = 0x00000002;

        public const uint DIIDFLAG_INSTALLNULLDRIVER = 0x00000004;

        public const uint DIIDFLAG_INSTALLCOPYINFDRIVERS = 0x00000008;

        public const uint DIIDFLAG_BITS = 0x0000000F;

        public const uint DIIRFLAG_INF_ALREADY_COPIED = 0x00000001;

        public const uint DIIRFLAG_FORCE_INF = 0x00000002;

        public const uint DIIRFLAG_HW_USING_THE_INF = 0x00000004;

        public const uint DIIRFLAG_HOTPATCH = 0x00000008;

        public const uint DIIRFLAG_NOBACKUP = 0x00000010;

        public const uint DIIRFLAG_PRE_CONFIGURE_INF = 0x00000020;

        public const uint DIIRFLAG_INSTALL_AS_SET = 0x00000040;

        public const uint DIURFLAG_NO_REMOVE_INF = 0x00000001;

        public const uint DIURFLAG_RESERVED = 0x00000002;

        public const uint ROLLBACK_FLAG_NO_UI = 0x00000001;

        public const uint ROLLBACK_BITS = 0x00000001;

    }
}
