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


namespace Windows.Win32.System.WindowsProgramming
{
    public static partial class Apis
    {
        public const uint WLDP_LOCKDOWN_UNDEFINED = 0x00000000;

        public const uint WLDP_LOCKDOWN_DEFINED_FLAG = 0x80000000;

        public const uint WLDP_LOCKDOWN_CONFIG_CI_FLAG = 0x00000001;

        public const uint WLDP_LOCKDOWN_CONFIG_CI_AUDIT_FLAG = 0x00000002;

        public const uint WLDP_LOCKDOWN_UMCIENFORCE_FLAG = 0x00000004;

        public const uint WLDP_LOCKDOWN_AUDIT_FLAG = 0x00000008;

        public const uint WLDP_LOCKDOWN_EXCLUSION_FLAG = 0x00000010;

        public const uint WLDP_HOST_INFORMATION_REVISION = 0x00000001;

        public const uint WLDP_FLAGS_SKIPSIGNATUREVALIDATION = 0x00000100;

        public const uint MAX_TDI_ENTITIES = 4096;

        public const uint INFO_CLASS_GENERIC = 0x100;

        public const uint INFO_CLASS_PROTOCOL = 0x200;

        public const uint INFO_CLASS_IMPLEMENTATION = 0x300;

        public const uint INFO_TYPE_PROVIDER = 0x100;

        public const uint INFO_TYPE_ADDRESS_OBJECT = 0x200;

        public const uint INFO_TYPE_CONNECTION = 0x300;

        public const uint ENTITY_LIST_ID = 0;

        public const int INVALID_ENTITY_INSTANCE = -1;

        public const uint CONTEXT_SIZE = 16;

        public const uint ENTITY_TYPE_ID = 1;

        public const uint CO_TL_NBF = 0x400;

        public const uint CO_TL_SPX = 0x402;

        public const uint CO_TL_TCP = 0x404;

        public const uint CO_TL_SPP = 0x406;

        public const uint CL_TL_NBF = 0x401;

        public const uint CL_TL_UDP = 0x403;

        public const uint ER_ICMP = 0x380;

        public const uint CL_NL_IPX = 0x301;

        public const uint CL_NL_IP = 0x303;

        public const uint AT_ARP = 0x280;

        public const uint AT_NULL = 0x282;

        public const uint IF_GENERIC = 0x200;

        public const uint IF_MIB = 0x202;

        public const uint IOCTL_TDI_TL_IO_CONTROL_ENDPOINT = ((FILE_DEVICE_TRANSPORT) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((14) << 2) | (METHOD_BUFFERED);

        public const uint DCI_VERSION = 0x0100;

        public const uint DCICREATEPRIMARYSURFACE = 1;

        public const uint DCICREATEOFFSCREENSURFACE = 2;

        public const uint DCICREATEOVERLAYSURFACE = 3;

        public const uint DCIENUMSURFACE = 4;

        public const uint DCIESCAPE = 5;

        public const uint DCI_OK = 0;

        public const int DCI_FAIL_GENERIC = -1;

        public const int DCI_FAIL_UNSUPPORTEDVERSION = -2;

        public const int DCI_FAIL_INVALIDSURFACE = -3;

        public const int DCI_FAIL_UNSUPPORTED = -4;

        public const int DCI_ERR_CURRENTLYNOTAVAIL = -5;

        public const int DCI_ERR_INVALIDRECT = -6;

        public const int DCI_ERR_UNSUPPORTEDFORMAT = -7;

        public const int DCI_ERR_UNSUPPORTEDMASK = -8;

        public const int DCI_ERR_TOOBIGHEIGHT = -9;

        public const int DCI_ERR_TOOBIGWIDTH = -10;

        public const int DCI_ERR_TOOBIGSIZE = -11;

        public const int DCI_ERR_OUTOFMEMORY = -12;

        public const int DCI_ERR_INVALIDPOSITION = -13;

        public const int DCI_ERR_INVALIDSTRETCH = -14;

        public const int DCI_ERR_INVALIDCLIPLIST = -15;

        public const int DCI_ERR_SURFACEISOBSCURED = -16;

        public const int DCI_ERR_XALIGN = -17;

        public const int DCI_ERR_YALIGN = -18;

        public const int DCI_ERR_XYALIGN = -19;

        public const int DCI_ERR_WIDTHALIGN = -20;

        public const int DCI_ERR_HEIGHTALIGN = -21;

        public const uint DCI_STATUS_POINTERCHANGED = 1;

        public const uint DCI_STATUS_STRIDECHANGED = 2;

        public const uint DCI_STATUS_FORMATCHANGED = 4;

        public const uint DCI_STATUS_SURFACEINFOCHANGED = 8;

        public const uint DCI_STATUS_CHROMAKEYCHANGED = 16;

        public const uint DCI_STATUS_WASSTILLDRAWING = 32;

        public const uint DCI_SURFACE_TYPE = 0x0000000F;

        public const uint DCI_PRIMARY = 0x00000000;

        public const uint DCI_OFFSCREEN = 0x00000001;

        public const uint DCI_OVERLAY = 0x00000002;

        public const uint DCI_VISIBLE = 0x00000010;

        public const uint DCI_CHROMAKEY = 0x00000020;

        public const uint DCI_1632_ACCESS = 0x00000040;

        public const uint DCI_DWORDSIZE = 0x00000080;

        public const uint DCI_DWORDALIGN = 0x00000100;

        public const uint DCI_WRITEONLY = 0x00000200;

        public const uint DCI_ASYNC = 0x00000400;

        public const uint DCI_CAN_STRETCHX = 0x00001000;

        public const uint DCI_CAN_STRETCHY = 0x00002000;

        public const uint DCI_CAN_STRETCHXN = 0x00004000;

        public const uint DCI_CAN_STRETCHYN = 0x00008000;

        public const uint DCI_CANOVERLAY = 0x00010000;

        public const uint FILE_FLAG_OPEN_REQUIRING_OPLOCK = 0x00040000;

        public const uint PROGRESS_CONTINUE = 0;

        public const uint PROGRESS_CANCEL = 1;

        public const uint PROGRESS_STOP = 2;

        public const uint PROGRESS_QUIET = 3;

        public const uint COPY_FILE_FAIL_IF_EXISTS = 0x00000001;

        public const uint COPY_FILE_RESTARTABLE = 0x00000002;

        public const uint COPY_FILE_OPEN_SOURCE_FOR_WRITE = 0x00000004;

        public const uint COPY_FILE_ALLOW_DECRYPTED_DESTINATION = 0x00000008;

        public const uint COPY_FILE_COPY_SYMLINK = 0x00000800;

        public const uint COPY_FILE_NO_BUFFERING = 0x00001000;

        public const uint COPY_FILE_REQUEST_SECURITY_PRIVILEGES = 0x00002000;

        public const uint COPY_FILE_RESUME_FROM_PAUSE = 0x00004000;

        public const uint COPY_FILE_NO_OFFLOAD = 0x00040000;

        public const uint COPY_FILE_IGNORE_EDP_BLOCK = 0x00400000;

        public const uint COPY_FILE_IGNORE_SOURCE_ENCRYPTION = 0x00800000;

        public const uint COPY_FILE_DONT_REQUEST_DEST_WRITE_DAC = 0x02000000;

        public const uint COPY_FILE_REQUEST_COMPRESSED_TRAFFIC = 0x10000000;

        public const uint COPY_FILE_OPEN_AND_COPY_REPARSE_POINT = 0x00200000;

        public const uint COPY_FILE_DIRECTORY = 0x00000080;

        public const uint COPY_FILE_SKIP_ALTERNATE_STREAMS = 0x00008000;

        public const uint COPY_FILE_DISABLE_PRE_ALLOCATION = 0x04000000;

        public const uint COPY_FILE_ENABLE_LOW_FREE_SPACE_MODE = 0x08000000;

        public const uint PIPE_ACCESS_INBOUND = 0x00000001;

        public const uint PIPE_ACCESS_OUTBOUND = 0x00000002;

        public const uint PIPE_ACCESS_DUPLEX = 0x00000003;

        public const uint PIPE_ACCEPT_REMOTE_CLIENTS = 0x00000000;

        public const uint PIPE_REJECT_REMOTE_CLIENTS = 0x00000008;

        public const uint PIPE_UNLIMITED_INSTANCES = 255;

        public const uint FAIL_FAST_GENERATE_EXCEPTION_ADDRESS = 0x1;

        public const uint FAIL_FAST_NO_HARD_ERROR_DLG = 0x2;

        public const uint DTR_CONTROL_DISABLE = 0x00;

        public const uint DTR_CONTROL_ENABLE = 0x01;

        public const uint DTR_CONTROL_HANDSHAKE = 0x02;

        public const uint RTS_CONTROL_DISABLE = 0x00;

        public const uint RTS_CONTROL_ENABLE = 0x01;

        public const uint RTS_CONTROL_HANDSHAKE = 0x02;

        public const uint RTS_CONTROL_TOGGLE = 0x03;

        public const uint GMEM_NOCOMPACT = 0x0010;

        public const uint GMEM_NODISCARD = 0x0020;

        public const uint GMEM_MODIFY = 0x0080;

        public const uint GMEM_DISCARDABLE = 0x0100;

        public const uint GMEM_NOT_BANKED = 0x1000;

        public const uint GMEM_SHARE = 0x2000;

        public const uint GMEM_DDESHARE = 0x2000;

        public const uint GMEM_NOTIFY = 0x4000;

        public const uint GMEM_VALID_FLAGS = 0x7F72;

        public const uint GMEM_INVALID_HANDLE = 0x8000;

        public const uint GMEM_DISCARDED = 0x4000;

        public const uint GMEM_LOCKCOUNT = 0x00FF;

        public const uint VOLUME_NAME_DOS = 0x0;

        public const uint VOLUME_NAME_GUID = 0x1;

        public const uint VOLUME_NAME_NT = 0x2;

        public const uint VOLUME_NAME_NONE = 0x4;

        public const uint DRIVE_UNKNOWN = 0;

        public const uint DRIVE_NO_ROOT_DIR = 1;

        public const uint DRIVE_REMOVABLE = 2;

        public const uint DRIVE_FIXED = 3;

        public const uint DRIVE_REMOTE = 4;

        public const uint DRIVE_CDROM = 5;

        public const uint DRIVE_RAMDISK = 6;

        public const uint FILE_TYPE_UNKNOWN = 0x0000;

        public const uint FILE_TYPE_DISK = 0x0001;

        public const uint FILE_TYPE_CHAR = 0x0002;

        public const uint FILE_TYPE_PIPE = 0x0003;

        public const uint FILE_TYPE_REMOTE = 0x8000;

        public const uint NOPARITY = 0;

        public const uint ODDPARITY = 1;

        public const uint EVENPARITY = 2;

        public const uint MARKPARITY = 3;

        public const uint SPACEPARITY = 4;

        public const uint ONESTOPBIT = 0;

        public const uint ONE5STOPBITS = 1;

        public const uint TWOSTOPBITS = 2;

        public const uint IGNORE = 0;

        public const uint INFINITE = 0xFFFFFFFF;

        public const uint CBR_110 = 110;

        public const uint CBR_300 = 300;

        public const uint CBR_600 = 600;

        public const uint CBR_1200 = 1200;

        public const uint CBR_2400 = 2400;

        public const uint CBR_4800 = 4800;

        public const uint CBR_9600 = 9600;

        public const uint CBR_14400 = 14400;

        public const uint CBR_19200 = 19200;

        public const uint CBR_38400 = 38400;

        public const uint CBR_56000 = 56000;

        public const uint CBR_57600 = 57600;

        public const uint CBR_115200 = 115200;

        public const uint CBR_128000 = 128000;

        public const uint CBR_256000 = 256000;

        public const uint CE_TXFULL = 0x0100;

        public const uint CE_PTO = 0x0200;

        public const uint CE_IOE = 0x0400;

        public const uint CE_DNS = 0x0800;

        public const uint CE_OOP = 0x1000;

        public const uint CE_MODE = 0x8000;

        public const int IE_BADID = -1;

        public const int IE_OPEN = -2;

        public const int IE_NOPEN = -3;

        public const int IE_MEMORY = -4;

        public const int IE_DEFAULT = -5;

        public const int IE_HARDWARE = -10;

        public const int IE_BYTESIZE = -11;

        public const int IE_BAUDRATE = -12;

        public const uint RESETDEV = 7;

        public const uint LPTx = 0x80;

        public const uint S_QUEUEEMPTY = 0;

        public const uint S_THRESHOLD = 1;

        public const uint S_ALLTHRESHOLD = 2;

        public const uint S_NORMAL = 0;

        public const uint S_LEGATO = 1;

        public const uint S_STACCATO = 2;

        public const uint S_PERIOD512 = 0;

        public const uint S_PERIOD1024 = 1;

        public const uint S_PERIOD2048 = 2;

        public const uint S_PERIODVOICE = 3;

        public const uint S_WHITE512 = 4;

        public const uint S_WHITE1024 = 5;

        public const uint S_WHITE2048 = 6;

        public const uint S_WHITEVOICE = 7;

        public const int S_SERDVNA = -1;

        public const int S_SEROFM = -2;

        public const int S_SERMACT = -3;

        public const int S_SERQFUL = -4;

        public const int S_SERBDNT = -5;

        public const int S_SERDLN = -6;

        public const int S_SERDCC = -7;

        public const int S_SERDTP = -8;

        public const int S_SERDVL = -9;

        public const int S_SERDMD = -10;

        public const int S_SERDSH = -11;

        public const int S_SERDPT = -12;

        public const int S_SERDFQ = -13;

        public const int S_SERDDR = -14;

        public const int S_SERDSR = -15;

        public const int S_SERDST = -16;

        public const uint NMPWAIT_NOWAIT = 0x00000001;

        public const uint OFS_MAXPATHNAME = 128;

        public const uint MAXINTATOM = 0xC000;

        public const uint SCS_32BIT_BINARY = 0;

        public const uint SCS_DOS_BINARY = 1;

        public const uint SCS_WOW_BINARY = 2;

        public const uint SCS_PIF_BINARY = 3;

        public const uint SCS_POSIX_BINARY = 4;

        public const uint SCS_OS216_BINARY = 5;

        public const uint SCS_64BIT_BINARY = 6;

        public const uint FIBER_FLAG_FLOAT_SWITCH = 0x1;

        public const uint FILE_SKIP_COMPLETION_PORT_ON_SUCCESS = 0x1;

        public const uint FILE_SKIP_SET_EVENT_ON_HANDLE = 0x2;

        public const uint HINSTANCE_ERROR = 32;

        public const uint FORMAT_MESSAGE_MAX_WIDTH_MASK = 0x000000FF;

        public const uint FILE_ENCRYPTABLE = 0;

        public const uint FILE_IS_ENCRYPTED = 1;

        public const uint FILE_SYSTEM_ATTR = 2;

        public const uint FILE_ROOT_DIR = 3;

        public const uint FILE_SYSTEM_DIR = 4;

        public const uint FILE_UNKNOWN = 5;

        public const uint FILE_SYSTEM_NOT_SUPPORT = 6;

        public const uint FILE_USER_DISALLOWED = 7;

        public const uint FILE_READ_ONLY = 8;

        public const uint FILE_DIR_DISALLOWED = 9;

        public const uint EFS_USE_RECOVERY_KEYS = 0x1;

        public const uint CREATE_FOR_IMPORT = 1;

        public const uint CREATE_FOR_DIR = 2;

        public const uint OVERWRITE_HIDDEN = 4;

        public const uint EFSRPC_SECURE_ONLY = 8;

        public const uint EFS_DROP_ALTERNATE_STREAMS = 0x10;

        public const uint BACKUP_INVALID = 0x00000000;

        public const uint BACKUP_GHOSTED_FILE_EXTENTS = 0x0000000b;

        public const uint STREAM_NORMAL_ATTRIBUTE = 0x00000000;

        public const uint STREAM_MODIFIED_WHEN_READ = 0x00000001;

        public const uint STREAM_CONTAINS_SECURITY = 0x00000002;

        public const uint STREAM_CONTAINS_PROPERTIES = 0x00000004;

        public const uint STREAM_SPARSE_ATTRIBUTE = 0x00000008;

        public const uint STREAM_CONTAINS_GHOSTED_FILE_EXTENTS = 0x00000010;

        public const uint SHUTDOWN_NORETRY = 0x00000001;

        public const uint PROTECTION_LEVEL_SAME = 0xFFFFFFFF;

        public const uint PROC_THREAD_ATTRIBUTE_NUMBER = 0x0000FFFF;

        public const uint PROC_THREAD_ATTRIBUTE_THREAD = 0x00010000;

        public const uint PROC_THREAD_ATTRIBUTE_INPUT = 0x00020000;

        public const uint PROC_THREAD_ATTRIBUTE_ADDITIVE = 0x00040000;

        public const uint PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE = 0x01;

        public const uint PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE = 0x02;

        public const uint PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE = 0x04;

        public const uint PROCESS_CREATION_CHILD_PROCESS_RESTRICTED = 0x01;

        public const uint PROCESS_CREATION_CHILD_PROCESS_OVERRIDE = 0x02;

        public const uint PROCESS_CREATION_CHILD_PROCESS_RESTRICTED_UNLESS_SECURE = 0x04;

        public const uint PROCESS_CREATION_ALL_APPLICATION_PACKAGES_OPT_OUT = 0x01;

        public const uint PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_ENABLE_PROCESS_TREE = 0x01;

        public const uint PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_DISABLE_PROCESS_TREE = 0x02;

        public const uint PROCESS_CREATION_DESKTOP_APP_BREAKAWAY_OVERRIDE = 0x04;

        public const uint ATOM_FLAG_GLOBAL = 0x2;

        public const uint BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE = 0x1;

        public const uint BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE = 0x10000;

        public const uint BASE_SEARCH_PATH_PERMANENT = 0x8000;

        public const int COPYFILE2_MESSAGE_COPY_OFFLOAD = 0x00000001;

        public const uint EVENTLOG_FULL_INFO = 0;

        public const uint OPERATION_API_VERSION = 1;

        public const uint MAX_COMPUTERNAME_LENGTH = 15;

        public const uint LOGON32_PROVIDER_WINNT35 = 1;

        public const uint LOGON32_PROVIDER_VIRTUAL = 4;

        public const uint LOGON_ZERO_PASSWORD_BUFFER = 0x80000000;

        public const uint HW_PROFILE_GUIDLEN = 39;

        public const uint DOCKINFO_UNDOCKED = 0x1;

        public const uint DOCKINFO_DOCKED = 0x2;

        public const uint DOCKINFO_USER_SUPPLIED = 0x4;

        public const uint TC_NORMAL = 0;

        public const uint TC_HARDERR = 1;

        public const uint TC_GP_TRAP = 2;

        public const uint TC_SIGNAL = 3;

        public const uint AC_LINE_OFFLINE = 0x00;

        public const uint AC_LINE_ONLINE = 0x01;

        public const uint AC_LINE_BACKUP_POWER = 0x02;

        public const uint AC_LINE_UNKNOWN = 0xFF;

        public const uint BATTERY_FLAG_HIGH = 0x01;

        public const uint BATTERY_FLAG_LOW = 0x02;

        public const uint BATTERY_FLAG_CRITICAL = 0x04;

        public const uint BATTERY_FLAG_CHARGING = 0x08;

        public const uint BATTERY_FLAG_NO_BATTERY = 0x80;

        public const uint BATTERY_FLAG_UNKNOWN = 0xFF;

        public const uint BATTERY_PERCENTAGE_UNKNOWN = 0xFF;

        public const uint SYSTEM_STATUS_FLAG_POWER_SAVING_ON = 0x01;

        public const uint BATTERY_LIFE_UNKNOWN = 0xFFFFFFFF;

        public const uint ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID = 0x00000001;

        public const uint ACTCTX_FLAG_LANGID_VALID = 0x00000002;

        public const uint ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID = 0x00000004;

        public const uint ACTCTX_FLAG_RESOURCE_NAME_VALID = 0x00000008;

        public const uint ACTCTX_FLAG_SET_PROCESS_DEFAULT = 0x00000010;

        public const uint ACTCTX_FLAG_APPLICATION_NAME_VALID = 0x00000020;

        public const uint ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF = 0x00000040;

        public const uint ACTCTX_FLAG_HMODULE_VALID = 0x00000080;

        public const uint DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION = 0x00000001;

        public const uint FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX = 0x00000001;

        public const uint FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS = 0x00000002;

        public const uint FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA = 0x00000004;

        public const uint ACTIVATION_CONTEXT_BASIC_INFORMATION_DEFINED = 1;

        public const uint QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX = 0x00000004;

        public const uint QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE = 0x00000008;

        public const uint QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS = 0x00000010;

        public const uint QUERY_ACTCTX_FLAG_NO_ADDREF = 0x80000000;

        public const uint RESTART_MAX_CMD_LINE = 1024;

        public const uint RECOVERY_DEFAULT_PING_INTERVAL = 5000;

        public const uint FILE_RENAME_FLAG_REPLACE_IF_EXISTS = 0x00000001;

        public const uint FILE_RENAME_FLAG_POSIX_SEMANTICS = 0x00000002;

        public const uint FILE_RENAME_FLAG_SUPPRESS_PIN_STATE_INHERITANCE = 0x00000004;

        public const uint FILE_DISPOSITION_FLAG_DO_NOT_DELETE = 0x00000000;

        public const uint FILE_DISPOSITION_FLAG_DELETE = 0x00000001;

        public const uint FILE_DISPOSITION_FLAG_POSIX_SEMANTICS = 0x00000002;

        public const uint FILE_DISPOSITION_FLAG_FORCE_IMAGE_SECTION_CHECK = 0x00000004;

        public const uint FILE_DISPOSITION_FLAG_ON_CLOSE = 0x00000008;

        public const uint FILE_DISPOSITION_FLAG_IGNORE_READONLY_ATTRIBUTE = 0x00000010;

        public const uint STORAGE_INFO_FLAGS_ALIGNED_DEVICE = 0x00000001;

        public const uint STORAGE_INFO_FLAGS_PARTITION_ALIGNED_ON_DEVICE = 0x00000002;

        public const uint STORAGE_INFO_OFFSET_UNKNOWN = 0xffffffff;

        public const uint REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK = 0x00000001;

        public const uint REMOTE_PROTOCOL_INFO_FLAG_OFFLINE = 0x00000002;

        public const uint REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE = 0x00000004;

        public const uint RPI_FLAG_SMB2_SHARECAP_TIMEWARP = 0x00000002;

        public const uint RPI_FLAG_SMB2_SHARECAP_DFS = 0x00000008;

        public const uint RPI_FLAG_SMB2_SHARECAP_CONTINUOUS_AVAILABILITY = 0x00000010;

        public const uint RPI_FLAG_SMB2_SHARECAP_SCALEOUT = 0x00000020;

        public const uint RPI_FLAG_SMB2_SHARECAP_CLUSTER = 0x00000040;

        public const uint RPI_SMB2_FLAG_SERVERCAP_DFS = 0x00000001;

        public const uint RPI_SMB2_FLAG_SERVERCAP_LEASING = 0x00000002;

        public const uint RPI_SMB2_FLAG_SERVERCAP_LARGEMTU = 0x00000004;

        public const uint RPI_SMB2_FLAG_SERVERCAP_MULTICHANNEL = 0x00000008;

        public const uint RPI_SMB2_FLAG_SERVERCAP_PERSISTENT_HANDLES = 0x00000010;

        public const uint RPI_SMB2_FLAG_SERVERCAP_DIRECTORY_LEASING = 0x00000020;

        public const uint MICROSOFT_WINBASE_H_DEFINE_INTERLOCKED_CPLUSPLUS_OVERLOADS = 0;

        public const uint CODEINTEGRITY_OPTION_ENABLED = 0x01;

        public const uint CODEINTEGRITY_OPTION_TESTSIGN = 0x02;

        public const uint CODEINTEGRITY_OPTION_UMCI_ENABLED = 0x04;

        public const uint CODEINTEGRITY_OPTION_UMCI_AUDITMODE_ENABLED = 0x08;

        public const uint CODEINTEGRITY_OPTION_UMCI_EXCLUSIONPATHS_ENABLED = 0x10;

        public const uint CODEINTEGRITY_OPTION_TEST_BUILD = 0x20;

        public const uint CODEINTEGRITY_OPTION_PREPRODUCTION_BUILD = 0x40;

        public const uint CODEINTEGRITY_OPTION_DEBUGMODE_ENABLED = 0x80;

        public const uint CODEINTEGRITY_OPTION_FLIGHT_BUILD = 0x100;

        public const uint CODEINTEGRITY_OPTION_FLIGHTING_ENABLED = 0x200;

        public const uint CODEINTEGRITY_OPTION_HVCI_KMCI_ENABLED = 0x400;

        public const uint CODEINTEGRITY_OPTION_HVCI_KMCI_AUDITMODE_ENABLED = 0x800;

        public const uint CODEINTEGRITY_OPTION_HVCI_KMCI_STRICTMODE_ENABLED = 0x1000;

        public const uint CODEINTEGRITY_OPTION_HVCI_IUM_ENABLED = 0x2000;

        public const uint FILE_MAXIMUM_DISPOSITION = 0x00000005;

        public const uint FILE_DIRECTORY_FILE = 0x00000001;

        public const uint FILE_WRITE_THROUGH = 0x00000002;

        public const uint FILE_SEQUENTIAL_ONLY = 0x00000004;

        public const uint FILE_NO_INTERMEDIATE_BUFFERING = 0x00000008;

        public const uint FILE_SYNCHRONOUS_IO_ALERT = 0x00000010;

        public const uint FILE_SYNCHRONOUS_IO_NONALERT = 0x00000020;

        public const uint FILE_NON_DIRECTORY_FILE = 0x00000040;

        public const uint FILE_CREATE_TREE_CONNECTION = 0x00000080;

        public const uint FILE_COMPLETE_IF_OPLOCKED = 0x00000100;

        public const uint FILE_NO_EA_KNOWLEDGE = 0x00000200;

        public const uint FILE_OPEN_REMOTE_INSTANCE = 0x00000400;

        public const uint FILE_RANDOM_ACCESS = 0x00000800;

        public const uint FILE_DELETE_ON_CLOSE = 0x00001000;

        public const uint FILE_OPEN_BY_FILE_ID = 0x00002000;

        public const uint FILE_OPEN_FOR_BACKUP_INTENT = 0x00004000;

        public const uint FILE_NO_COMPRESSION = 0x00008000;

        public const uint FILE_OPEN_REQUIRING_OPLOCK = 0x00010000;

        public const uint FILE_RESERVE_OPFILTER = 0x00100000;

        public const uint FILE_OPEN_REPARSE_POINT = 0x00200000;

        public const uint FILE_OPEN_NO_RECALL = 0x00400000;

        public const uint FILE_OPEN_FOR_FREE_SPACE_QUERY = 0x00800000;

        public const uint FILE_VALID_OPTION_FLAGS = 0x00ffffff;

        public const uint FILE_VALID_PIPE_OPTION_FLAGS = 0x00000032;

        public const uint FILE_VALID_MAILSLOT_OPTION_FLAGS = 0x00000032;

        public const uint FILE_VALID_SET_FLAGS = 0x00000036;

        public const uint FILE_SUPERSEDED = 0x00000000;

        public const uint FILE_OPENED = 0x00000001;

        public const uint FILE_CREATED = 0x00000002;

        public const uint FILE_OVERWRITTEN = 0x00000003;

        public const uint FILE_EXISTS = 0x00000004;

        public const uint FILE_DOES_NOT_EXIST = 0x00000005;

        public const uint WINWATCHNOTIFY_START = 0;

        public const uint WINWATCHNOTIFY_STOP = 1;

        public const uint WINWATCHNOTIFY_DESTROY = 2;

        public const uint WINWATCHNOTIFY_CHANGING = 3;

        public const uint WINWATCHNOTIFY_CHANGED = 4;

        [NativeTypeName("HRESULT")]
        public const int S_ASYNCHRONOUS = 0x401e8;

        public const uint RSC_FLAG_INF = 1;

        public const uint RSC_FLAG_SKIPDISKSPACECHECK = 2;

        public const uint RSC_FLAG_QUIET = 4;

        public const uint RSC_FLAG_NGCONV = 8;

        public const uint RSC_FLAG_UPDHLPDLLS = 16;

        public const uint RSC_FLAG_DELAYREGISTEROCX = 512;

        public const uint RSC_FLAG_SETUPAPI = 1024;

        public const uint ALINF_QUIET = 4;

        public const uint ALINF_NGCONV = 8;

        public const uint ALINF_UPDHLPDLLS = 16;

        public const uint ALINF_BKINSTALL = 32;

        public const uint ALINF_ROLLBACK = 64;

        public const uint ALINF_CHECKBKDATA = 128;

        public const uint ALINF_ROLLBKDOALL = 256;

        public const uint ALINF_DELAYREGISTEROCX = 512;

        public const uint AIF_WARNIFSKIP = 0x00000001;

        public const uint AIF_NOSKIP = 0x00000002;

        public const uint AIF_NOVERSIONCHECK = 0x00000004;

        public const uint AIF_FORCE_FILE_IN_USE = 0x00000008;

        public const uint AIF_NOOVERWRITE = 0x00000010;

        public const uint AIF_NO_VERSION_DIALOG = 0x00000020;

        public const uint AIF_REPLACEONLY = 0x00000400;

        public const uint AIF_NOLANGUAGECHECK = 0x10000000;

        public const uint AIF_QUIET = 0x20000000;

        public const uint IE4_RESTORE = 0x00000001;

        public const uint IE4_BACKNEW = 0x00000002;

        public const uint IE4_NODELETENEW = 0x00000004;

        public const uint IE4_NOMESSAGES = 0x00000008;

        public const uint IE4_NOPROGRESS = 0x00000010;

        public const uint IE4_NOENUMKEY = 0x00000020;

        public const uint IE4_NO_CRC_MAPPING = 0x00000040;

        public const uint IE4_REGSECTION = 0x00000080;

        public const uint IE4_FRDOALL = 0x00000100;

        public const uint IE4_UPDREFCNT = 0x00000200;

        public const uint IE4_USEREFCNT = 0x00000400;

        public const uint IE4_EXTRAINCREFCNT = 0x00000800;

        public const uint IE4_REMOVREGBKDATA = 0x00001000;

        public const uint AADBE_ADD_ENTRY = 0x01;

        public const uint AADBE_DEL_ENTRY = 0x02;

        public const uint ADN_DEL_IF_EMPTY = 0x00000001;

        public const uint ADN_DONT_DEL_SUBDIRS = 0x00000002;

        public const uint ADN_DONT_DEL_DIR = 0x00000004;

        public const uint ADN_DEL_UNC_PATHS = 0x00000008;

        public const uint LIS_QUIET = 0x0001;

        public const uint LIS_NOGRPCONV = 0x0002;

        public const uint RUNCMDS_QUIET = 0x00000001;

        public const uint RUNCMDS_NOWAIT = 0x00000002;

        public const uint RUNCMDS_DELAYPOSTCMD = 0x00000004;

        public const uint IME_MAXPROCESS = 32;

        public const uint CP_HWND = 0;

        public const uint CP_OPEN = 1;

        public const uint CP_DIRECT = 2;

        public const uint CP_LEVEL = 3;

        public const uint VK_DBE_ALPHANUMERIC = 0x0f0;

        public const uint VK_DBE_KATAKANA = 0x0f1;

        public const uint VK_DBE_HIRAGANA = 0x0f2;

        public const uint VK_DBE_SBCSCHAR = 0x0f3;

        public const uint VK_DBE_DBCSCHAR = 0x0f4;

        public const uint VK_DBE_ROMAN = 0x0f5;

        public const uint VK_DBE_NOROMAN = 0x0f6;

        public const uint VK_DBE_ENTERWORDREGISTERMODE = 0x0f7;

        public const uint VK_DBE_ENTERIMECONFIGMODE = 0x0f8;

        public const uint VK_DBE_FLUSHSTRING = 0x0f9;

        public const uint VK_DBE_CODEINPUT = 0x0fa;

        public const uint VK_DBE_NOCODEINPUT = 0x0fb;

        public const uint VK_DBE_DETERMINESTRING = 0x0fc;

        public const uint VK_DBE_ENTERDLGCONVERSIONMODE = 0x0fd;

        public const uint MCW_DEFAULT = 0x00;

        public const uint MCW_RECT = 0x01;

        public const uint MCW_WINDOW = 0x02;

        public const uint MCW_SCREEN = 0x04;

        public const uint MCW_VERTICAL = 0x08;

        public const uint MCW_HIDDEN = 0x10;

        public const uint IME_MODE_ALPHANUMERIC = 0x0001;

        public const uint IME_MODE_SBCSCHAR = 0x0002;

        public const uint IME_MODE_KATAKANA = 0x0002;

        public const uint IME_MODE_HIRAGANA = 0x0004;

        public const uint IME_MODE_HANJACONVERT = 0x0004;

        public const uint IME_MODE_DBCSCHAR = 0x0010;

        public const uint IME_MODE_ROMAN = 0x0020;

        public const uint IME_MODE_NOROMAN = 0x0040;

        public const uint IME_MODE_CODEINPUT = 0x0080;

        public const uint IME_MODE_NOCODEINPUT = 0x0100;

        public const uint IME_GETIMECAPS = 0x03;

        public const uint IME_SETOPEN = 0x04;

        public const uint IME_GETOPEN = 0x05;

        public const uint IME_GETVERSION = 0x07;

        public const uint IME_SETCONVERSIONWINDOW = 0x08;

        public const uint IME_SETCONVERSIONMODE = 0x10;

        public const uint IME_GETCONVERSIONMODE = 0x11;

        public const uint IME_SET_MODE = 0x12;

        public const uint IME_SENDVKEY = 0x13;

        public const uint IME_ENTERWORDREGISTERMODE = 0x18;

        public const uint IME_SETCONVERSIONFONTEX = 0x19;

        public const uint IME_BANJAtoJUNJA = 0x13;

        public const uint IME_JUNJAtoBANJA = 0x14;

        public const uint IME_JOHABtoKS = 0x15;

        public const uint IME_KStoJOHAB = 0x16;

        public const uint IMEA_INIT = 0x01;

        public const uint IMEA_NEXT = 0x02;

        public const uint IMEA_PREV = 0x03;

        public const uint IME_REQUEST_CONVERT = 0x01;

        public const uint IME_ENABLE_CONVERT = 0x02;

        public const uint INTERIM_WINDOW = 0x00;

        public const uint MODE_WINDOW = 0x01;

        public const uint HANJA_WINDOW = 0x02;

        public const uint IME_RS_ERROR = 0x01;

        public const uint IME_RS_NOIME = 0x02;

        public const uint IME_RS_TOOLONG = 0x05;

        public const uint IME_RS_ILLEGAL = 0x06;

        public const uint IME_RS_NOTFOUND = 0x07;

        public const uint IME_RS_NOROOM = 0x0a;

        public const uint IME_RS_DISKERROR = 0x0e;

        public const uint IME_RS_INVALID = 0x11;

        public const uint IME_RS_NEST = 0x12;

        public const uint IME_RS_SYSTEMMODAL = 0x13;

        public const uint WM_IME_REPORT = 0x0280;

        public const uint IR_STRINGSTART = 0x100;

        public const uint IR_STRINGEND = 0x101;

        public const uint IR_OPENCONVERT = 0x120;

        public const uint IR_CHANGECONVERT = 0x121;

        public const uint IR_CLOSECONVERT = 0x122;

        public const uint IR_FULLCONVERT = 0x123;

        public const uint IR_IMESELECT = 0x130;

        public const uint IR_STRING = 0x140;

        public const uint IR_DBCSCHAR = 0x160;

        public const uint IR_UNDETERMINE = 0x170;

        public const uint IR_STRINGEX = 0x180;

        public const uint IR_MODEINFO = 0x190;

        public const uint WM_WNT_CONVERTREQUESTEX = 0x0109;

        public const uint WM_CONVERTREQUEST = 0x010A;

        public const uint WM_CONVERTRESULT = 0x010B;

        public const uint WM_INTERIM = 0x010C;

        public const uint WM_IMEKEYDOWN = 0x290;

        public const uint WM_IMEKEYUP = 0x291;

        public static readonly Guid IID_IDirectDrawKernel__scanned__ = new Guid(0x8D56C120,0x6A08,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 );

        public static readonly Guid IID_IDirectDrawSurfaceKernel__scanned__ = new Guid(0x60755DA0,0x6A40,0x11D0,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8 );

        public const int DDKERNELCAPS_SKIPFIELDS = 0x00000001;

        public const int DDKERNELCAPS_AUTOFLIP = 0x00000002;

        public const int DDKERNELCAPS_SETSTATE = 0x00000004;

        public const int DDKERNELCAPS_LOCK = 0x00000008;

        public const int DDKERNELCAPS_FLIPVIDEOPORT = 0x00000010;

        public const int DDKERNELCAPS_FLIPOVERLAY = 0x00000020;

        public const int DDKERNELCAPS_CAPTURE_SYSMEM = 0x00000040;

        public const int DDKERNELCAPS_CAPTURE_NONLOCALVIDMEM = 0x00000080;

        public const int DDKERNELCAPS_FIELDPOLARITY = 0x00000100;

        public const int DDKERNELCAPS_CAPTURE_INVERTED = 0x00000200;

        public const int DDIRQ_DISPLAY_VSYNC = 0x00000001;

        public const int DDIRQ_RESERVED1 = 0x00000002;

        public const int DDIRQ_VPORT0_VSYNC = 0x00000004;

        public const int DDIRQ_VPORT0_LINE = 0x00000008;

        public const int DDIRQ_VPORT1_VSYNC = 0x00000010;

        public const int DDIRQ_VPORT1_LINE = 0x00000020;

        public const int DDIRQ_VPORT2_VSYNC = 0x00000040;

        public const int DDIRQ_VPORT2_LINE = 0x00000080;

        public const int DDIRQ_VPORT3_VSYNC = 0x00000100;

        public const int DDIRQ_VPORT3_LINE = 0x00000200;

        public const int DDIRQ_VPORT4_VSYNC = 0x00000400;

        public const int DDIRQ_VPORT4_LINE = 0x00000800;

        public const int DDIRQ_VPORT5_VSYNC = 0x00001000;

        public const int DDIRQ_VPORT5_LINE = 0x00002000;

        public const int DDIRQ_VPORT6_VSYNC = 0x00004000;

        public const int DDIRQ_VPORT6_LINE = 0x00008000;

        public const int DDIRQ_VPORT7_VSYNC = 0x00010000;

        public const int DDIRQ_VPORT7_LINE = 0x00020000;

        public const int DDIRQ_VPORT8_VSYNC = 0x00040000;

        public const int DDIRQ_VPORT8_LINE = 0x00080000;

        public const int DDIRQ_VPORT9_VSYNC = 0x00010000;

        public const int DDIRQ_VPORT9_LINE = 0x00020000;

    }
}
