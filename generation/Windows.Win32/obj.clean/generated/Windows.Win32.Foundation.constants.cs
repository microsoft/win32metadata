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


namespace Windows.Win32.Foundation
{
    public static partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int E_NOTIMPL = unchecked((int)0x80004001);

        [NativeTypeName("HRESULT")]
        public const int E_OUTOFMEMORY = unchecked((int)0x8007000E);

        [NativeTypeName("HRESULT")]
        public const int E_INVALIDARG = unchecked((int)0x80070057);

        [NativeTypeName("HRESULT")]
        public const int E_FAIL = unchecked((int)0x80004005);

        public const uint STRICT = 1;

        public const uint MAX_PATH = 260;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_0 = 0x00000000;

        public const uint FACILTIY_MUI_ERROR_CODE = 0xB;

        public const uint STATUS_SEVERITY_SUCCESS = 0x0;

        public const uint STATUS_SEVERITY_INFORMATIONAL = 0x1;

        public const uint STATUS_SEVERITY_WARNING = 0x2;

        public const uint STATUS_SEVERITY_ERROR = 0x3;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SUCCESS = 0x00000000;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_1 = 0x00000001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_2 = 0x00000002;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_3 = 0x00000003;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_63 = 0x0000003F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABANDONED = 0x00000080;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABANDONED_WAIT_0 = 0x00000080;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABANDONED_WAIT_63 = 0x000000BF;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER_APC = 0x000000C0;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_COMPLETE = 0x000000FF;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KERNEL_APC = 0x00000100;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALERTED = 0x00000101;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TIMEOUT = 0x00000102;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PENDING = 0x00000103;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE = 0x00000104;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MORE_ENTRIES = 0x00000105;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_ALL_ASSIGNED = 0x00000106;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SOME_NOT_MAPPED = 0x00000107;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPLOCK_BREAK_IN_PROGRESS = 0x00000108;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLUME_MOUNTED = 0x00000109;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RXACT_COMMITTED = 0x0000010A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOTIFY_CLEANUP = 0x0000010B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOTIFY_ENUM_DIR = 0x0000010C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_QUOTAS_FOR_ACCOUNT = 0x0000010D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED = 0x0000010E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGE_FAULT_TRANSITION = 0x00000110;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGE_FAULT_DEMAND_ZERO = 0x00000111;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGE_FAULT_COPY_ON_WRITE = 0x00000112;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGE_FAULT_GUARD_PAGE = 0x00000113;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGE_FAULT_PAGING_FILE = 0x00000114;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CACHE_PAGE_LOCKED = 0x00000115;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRASH_DUMP = 0x00000116;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BUFFER_ALL_ZEROS = 0x00000117;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE_OBJECT = 0x00000118;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_REQUIREMENTS_CHANGED = 0x00000119;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSLATION_COMPLETE = 0x00000120;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY = 0x00000121;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOTHING_TO_TERMINATE = 0x00000122;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCESS_NOT_IN_JOB = 0x00000123;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCESS_IN_JOB = 0x00000124;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLSNAP_HIBERNATE_READY = 0x00000125;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY = 0x00000126;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERRUPT_VECTOR_ALREADY_CONNECTED = 0x00000127;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERRUPT_STILL_CONNECTED = 0x00000128;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCESS_CLONED = 0x00000129;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_LOCKED_WITH_ONLY_READERS = 0x0000012A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_LOCKED_WITH_WRITERS = 0x0000012B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VALID_IMAGE_HASH = 0x0000012C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VALID_CATALOG_HASH = 0x0000012D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VALID_STRONG_CODE_HASH = 0x0000012E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GHOSTED = 0x0000012F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_OVERWRITTEN = 0x00000130;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCEMANAGER_READ_ONLY = 0x00000202;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RING_PREVIOUSLY_EMPTY = 0x00000210;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RING_PREVIOUSLY_FULL = 0x00000211;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RING_PREVIOUSLY_ABOVE_QUOTA = 0x00000212;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RING_NEWLY_EMPTY = 0x00000213;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RING_SIGNAL_OPPOSITE_ENDPOINT = 0x00000214;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPLOCK_SWITCHED_TO_NEW_HANDLE = 0x00000215;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPLOCK_HANDLE_CLOSED = 0x00000216;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAIT_FOR_OPLOCK = 0x00000367;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE_GLOBAL = 0x00000368;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_EXCEPTION_HANDLED = 0x00010001;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_CONTINUE = 0x00010002;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_IO_COMPLETE = 0x001C0001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NAME_EXISTS = 0x40000000;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_WAS_SUSPENDED = 0x40000001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WORKING_SET_LIMIT_RANGE = 0x40000002;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_NOT_AT_BASE = 0x40000003;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RXACT_STATE_CREATED = 0x40000004;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SEGMENT_NOTIFICATION = 0x40000005;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOCAL_USER_SESSION_KEY = 0x40000006;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_CURRENT_DIRECTORY = 0x40000007;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERIAL_MORE_WRITES = 0x40000008;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REGISTRY_RECOVERED = 0x40000009;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_READ_RECOVERY_FROM_BACKUP = 0x4000000A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_WRITE_RECOVERY = 0x4000000B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERIAL_COUNTER_TIMEOUT = 0x4000000C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NULL_LM_PASSWORD = 0x4000000D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_MACHINE_TYPE_MISMATCH = 0x4000000E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECEIVE_PARTIAL = 0x4000000F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECEIVE_EXPEDITED = 0x40000010;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECEIVE_PARTIAL_EXPEDITED = 0x40000011;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVENT_DONE = 0x40000012;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVENT_PENDING = 0x40000013;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CHECKING_FILE_SYSTEM = 0x40000014;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FATAL_APP_EXIT = 0x40000015;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PREDEFINED_HANDLE = 0x40000016;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAS_UNLOCKED = 0x40000017;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVICE_NOTIFICATION = 0x40000018;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAS_LOCKED = 0x40000019;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_HARD_ERROR = 0x4000001A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_WIN32 = 0x4000001B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_UNSIMULATE = 0x4000001C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_CONTINUE = 0x4000001D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_SINGLE_STEP = 0x4000001E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_BREAKPOINT = 0x4000001F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_EXCEPTION_CONTINUE = 0x40000020;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_EXCEPTION_LASTCHANCE = 0x40000021;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_EXCEPTION_CHAIN = 0x40000022;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE = 0x40000023;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_YIELD_PERFORMED = 0x40000024;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TIMER_RESUME_IGNORED = 0x40000025;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ARBITRATION_UNHANDLED = 0x40000026;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CARDBUS_NOT_SUPPORTED = 0x40000027;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_CREATEWX86TIB = 0x40000028;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MP_PROCESSOR_MISMATCH = 0x40000029;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HIBERNATED = 0x4000002A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESUME_HIBERNATION = 0x4000002B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FIRMWARE_UPDATED = 0x4000002C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVERS_LEAKING_LOCKED_PAGES = 0x4000002D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MESSAGE_RETRIEVED = 0x4000002E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_POWERSTATE_TRANSITION = 0x4000002F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALPC_CHECK_COMPLETION_LIST = 0x40000030;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_POWERSTATE_COMPLEX_TRANSITION = 0x40000031;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_AUDIT_BY_POLICY = 0x40000032;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABANDON_HIBERFILE = 0x40000033;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BIZRULES_NOT_ENABLED = 0x40000034;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_READ_FROM_COPY = 0x40000035;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_AT_DIFFERENT_BASE = 0x40000036;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PATCH_DEFERRED = 0x40000037;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_REPLY_LATER = 0x40010001;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_UNABLE_TO_PROVIDE_HANDLE = 0x40010002;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_TERMINATE_THREAD = 0x40010003;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_TERMINATE_PROCESS = 0x40010004;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_CONTROL_C = 0x40010005;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_PRINTEXCEPTION_C = 0x40010006;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_RIPEXCEPTION = 0x40010007;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_CONTROL_BREAK = 0x40010008;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_COMMAND_EXCEPTION = 0x40010009;

        [NativeTypeName("NTSTATUS")]
        public const int DBG_PRINTEXCEPTION_WIDE_C = 0x4001000A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HEURISTIC_DAMAGE_POSSIBLE = 0x40190001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GUARD_PAGE_VIOLATION = unchecked((int)0x80000001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATATYPE_MISALIGNMENT = unchecked((int)0x80000002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BREAKPOINT = unchecked((int)0x80000003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SINGLE_STEP = unchecked((int)0x80000004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BUFFER_OVERFLOW = unchecked((int)0x80000005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MORE_FILES = unchecked((int)0x80000006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAKE_SYSTEM_DEBUGGER = unchecked((int)0x80000007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HANDLES_CLOSED = unchecked((int)0x8000000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_INHERITANCE = unchecked((int)0x8000000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GUID_SUBSTITUTION_MADE = unchecked((int)0x8000000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PARTIAL_COPY = unchecked((int)0x8000000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_PAPER_EMPTY = unchecked((int)0x8000000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_POWERED_OFF = unchecked((int)0x8000000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_OFF_LINE = unchecked((int)0x80000010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_BUSY = unchecked((int)0x80000011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MORE_EAS = unchecked((int)0x80000012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_EA_NAME = unchecked((int)0x80000013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EA_LIST_INCONSISTENT = unchecked((int)0x80000014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_EA_FLAG = unchecked((int)0x80000015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VERIFY_REQUIRED = unchecked((int)0x80000016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EXTRANEOUS_INFORMATION = unchecked((int)0x80000017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RXACT_COMMIT_NECESSARY = unchecked((int)0x80000018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MORE_ENTRIES = unchecked((int)0x8000001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILEMARK_DETECTED = unchecked((int)0x8000001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEDIA_CHANGED = unchecked((int)0x8000001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BUS_RESET = unchecked((int)0x8000001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_END_OF_MEDIA = unchecked((int)0x8000001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BEGINNING_OF_MEDIA = unchecked((int)0x8000001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEDIA_CHECK = unchecked((int)0x80000020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SETMARK_DETECTED = unchecked((int)0x80000021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_DATA_DETECTED = unchecked((int)0x80000022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REDIRECTOR_HAS_OPEN_HANDLES = unchecked((int)0x80000023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_HAS_OPEN_HANDLES = unchecked((int)0x80000024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_DISCONNECTED = unchecked((int)0x80000025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LONGJUMP = unchecked((int)0x80000026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLEANER_CARTRIDGE_INSTALLED = unchecked((int)0x80000027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLUGPLAY_QUERY_VETOED = unchecked((int)0x80000028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNWIND_CONSOLIDATE = unchecked((int)0x80000029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REGISTRY_HIVE_RECOVERED = unchecked((int)0x8000002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DLL_MIGHT_BE_INSECURE = unchecked((int)0x8000002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DLL_MIGHT_BE_INCOMPATIBLE = unchecked((int)0x8000002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STOPPED_ON_SYMLINK = unchecked((int)0x8000002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_GRANT_REQUESTED_OPLOCK = unchecked((int)0x8000002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_ACE_CONDITION = unchecked((int)0x8000002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_SUPPORT_IN_PROGRESS = unchecked((int)0x80000030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_POWER_CYCLE_REQUIRED = unchecked((int)0x80000031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_WORK_DONE = unchecked((int)0x80000032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RETURN_ADDRESS_HIJACK_ATTEMPT = unchecked((int)0x80000033);

        [NativeTypeName("NTSTATUS")]
        public const int DBG_EXCEPTION_NOT_HANDLED = unchecked((int)0x80010001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_ALREADY_UP = unchecked((int)0x80130001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_ALREADY_DOWN = unchecked((int)0x80130002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETWORK_ALREADY_ONLINE = unchecked((int)0x80130003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE = unchecked((int)0x80130004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_ALREADY_MEMBER = unchecked((int)0x80130005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_BUFFER_TOO_SMALL = unchecked((int)0x801C0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_PARTIAL_METADATA = unchecked((int)0x80210001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TRANSIENT_STATE = unchecked((int)0x80210002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROPERTY_BLOB_CHECKSUM_MISMATCH = unchecked((int)0x8000CF00);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNSUCCESSFUL = unchecked((int)0xC0000001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_IMPLEMENTED = unchecked((int)0xC0000002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_INFO_CLASS = unchecked((int)0xC0000003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INFO_LENGTH_MISMATCH = unchecked((int)0xC0000004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_VIOLATION = unchecked((int)0xC0000005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IN_PAGE_ERROR = unchecked((int)0xC0000006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGEFILE_QUOTA = unchecked((int)0xC0000007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_HANDLE = unchecked((int)0xC0000008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_INITIAL_STACK = unchecked((int)0xC0000009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_INITIAL_PC = unchecked((int)0xC000000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_CID = unchecked((int)0xC000000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TIMER_NOT_CANCELED = unchecked((int)0xC000000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER = unchecked((int)0xC000000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_DEVICE = unchecked((int)0xC000000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_FILE = unchecked((int)0xC000000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DEVICE_REQUEST = unchecked((int)0xC0000010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_END_OF_FILE = unchecked((int)0xC0000011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_VOLUME = unchecked((int)0xC0000012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MEDIA_IN_DEVICE = unchecked((int)0xC0000013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNRECOGNIZED_MEDIA = unchecked((int)0xC0000014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NONEXISTENT_SECTOR = unchecked((int)0xC0000015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MORE_PROCESSING_REQUIRED = unchecked((int)0xC0000016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MEMORY = unchecked((int)0xC0000017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONFLICTING_ADDRESSES = unchecked((int)0xC0000018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_MAPPED_VIEW = unchecked((int)0xC0000019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNABLE_TO_FREE_VM = unchecked((int)0xC000001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNABLE_TO_DELETE_SECTION = unchecked((int)0xC000001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SYSTEM_SERVICE = unchecked((int)0xC000001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_INSTRUCTION = unchecked((int)0xC000001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LOCK_SEQUENCE = unchecked((int)0xC000001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_VIEW_SIZE = unchecked((int)0xC000001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_FILE_FOR_SECTION = unchecked((int)0xC0000020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_COMMITTED = unchecked((int)0xC0000021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BUFFER_TOO_SMALL = unchecked((int)0xC0000023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_TYPE_MISMATCH = unchecked((int)0xC0000024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NONCONTINUABLE_EXCEPTION = unchecked((int)0xC0000025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DISPOSITION = unchecked((int)0xC0000026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNWIND = unchecked((int)0xC0000027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_STACK = unchecked((int)0xC0000028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_UNWIND_TARGET = unchecked((int)0xC0000029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_LOCKED = unchecked((int)0xC000002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PARITY_ERROR = unchecked((int)0xC000002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNABLE_TO_DECOMMIT_VM = unchecked((int)0xC000002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_COMMITTED = unchecked((int)0xC000002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PORT_ATTRIBUTES = unchecked((int)0xC000002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_MESSAGE_TOO_LONG = unchecked((int)0xC000002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_MIX = unchecked((int)0xC0000030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_QUOTA_LOWER = unchecked((int)0xC0000031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_CORRUPT_ERROR = unchecked((int)0xC0000032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NAME_INVALID = unchecked((int)0xC0000033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NAME_NOT_FOUND = unchecked((int)0xC0000034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NAME_COLLISION = unchecked((int)0xC0000035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_DO_NOT_DISTURB = unchecked((int)0xC0000036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_DISCONNECTED = unchecked((int)0xC0000037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_ALREADY_ATTACHED = unchecked((int)0xC0000038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_PATH_INVALID = unchecked((int)0xC0000039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_PATH_NOT_FOUND = unchecked((int)0xC000003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_PATH_SYNTAX_BAD = unchecked((int)0xC000003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_OVERRUN = unchecked((int)0xC000003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_LATE_ERROR = unchecked((int)0xC000003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_ERROR = unchecked((int)0xC000003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRC_ERROR = unchecked((int)0xC000003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECTION_TOO_BIG = unchecked((int)0xC0000040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_CONNECTION_REFUSED = unchecked((int)0xC0000041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PORT_HANDLE = unchecked((int)0xC0000042);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHARING_VIOLATION = unchecked((int)0xC0000043);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUOTA_EXCEEDED = unchecked((int)0xC0000044);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PAGE_PROTECTION = unchecked((int)0xC0000045);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUTANT_NOT_OWNED = unchecked((int)0xC0000046);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SEMAPHORE_LIMIT_EXCEEDED = unchecked((int)0xC0000047);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_ALREADY_SET = unchecked((int)0xC0000048);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECTION_NOT_IMAGE = unchecked((int)0xC0000049);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SUSPEND_COUNT_EXCEEDED = unchecked((int)0xC000004A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_IS_TERMINATING = unchecked((int)0xC000004B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_WORKING_SET_LIMIT = unchecked((int)0xC000004C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INCOMPATIBLE_FILE_MAP = unchecked((int)0xC000004D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECTION_PROTECTION = unchecked((int)0xC000004E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EAS_NOT_SUPPORTED = unchecked((int)0xC000004F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EA_TOO_LARGE = unchecked((int)0xC0000050);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NONEXISTENT_EA_ENTRY = unchecked((int)0xC0000051);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_EAS_ON_FILE = unchecked((int)0xC0000052);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EA_CORRUPT_ERROR = unchecked((int)0xC0000053);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_LOCK_CONFLICT = unchecked((int)0xC0000054);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOCK_NOT_GRANTED = unchecked((int)0xC0000055);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DELETE_PENDING = unchecked((int)0xC0000056);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTL_FILE_NOT_SUPPORTED = unchecked((int)0xC0000057);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNKNOWN_REVISION = unchecked((int)0xC0000058);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REVISION_MISMATCH = unchecked((int)0xC0000059);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_OWNER = unchecked((int)0xC000005A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PRIMARY_GROUP = unchecked((int)0xC000005B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_IMPERSONATION_TOKEN = unchecked((int)0xC000005C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_DISABLE_MANDATORY = unchecked((int)0xC000005D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_LOGON_SERVERS = unchecked((int)0xC000005E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_PRIVILEGE = unchecked((int)0xC0000060);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRIVILEGE_NOT_HELD = unchecked((int)0xC0000061);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ACCOUNT_NAME = unchecked((int)0xC0000062);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER_EXISTS = unchecked((int)0xC0000063);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GROUP_EXISTS = unchecked((int)0xC0000065);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_GROUP = unchecked((int)0xC0000066);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMBER_IN_GROUP = unchecked((int)0xC0000067);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMBER_NOT_IN_GROUP = unchecked((int)0xC0000068);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LAST_ADMIN = unchecked((int)0xC0000069);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILL_FORMED_PASSWORD = unchecked((int)0xC000006B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PASSWORD_RESTRICTION = unchecked((int)0xC000006C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LOGON_HOURS = unchecked((int)0xC000006F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_WORKSTATION = unchecked((int)0xC0000070);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NONE_MAPPED = unchecked((int)0xC0000073);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_LUIDS_REQUESTED = unchecked((int)0xC0000074);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LUIDS_EXHAUSTED = unchecked((int)0xC0000075);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SUB_AUTHORITY = unchecked((int)0xC0000076);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ACL = unchecked((int)0xC0000077);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SID = unchecked((int)0xC0000078);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SECURITY_DESCR = unchecked((int)0xC0000079);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCEDURE_NOT_FOUND = unchecked((int)0xC000007A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_FORMAT = unchecked((int)0xC000007B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TOKEN = unchecked((int)0xC000007C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_INHERITANCE_ACL = unchecked((int)0xC000007D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RANGE_NOT_LOCKED = unchecked((int)0xC000007E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_FULL = unchecked((int)0xC000007F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_DISABLED = unchecked((int)0xC0000080);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_NOT_DISABLED = unchecked((int)0xC0000081);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_GUIDS_REQUESTED = unchecked((int)0xC0000082);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GUIDS_EXHAUSTED = unchecked((int)0xC0000083);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ID_AUTHORITY = unchecked((int)0xC0000084);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AGENTS_EXHAUSTED = unchecked((int)0xC0000085);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_VOLUME_LABEL = unchecked((int)0xC0000086);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECTION_NOT_EXTENDED = unchecked((int)0xC0000087);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_MAPPED_DATA = unchecked((int)0xC0000088);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_DATA_NOT_FOUND = unchecked((int)0xC0000089);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_TYPE_NOT_FOUND = unchecked((int)0xC000008A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_NAME_NOT_FOUND = unchecked((int)0xC000008B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ARRAY_BOUNDS_EXCEEDED = unchecked((int)0xC000008C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_DENORMAL_OPERAND = unchecked((int)0xC000008D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_DIVIDE_BY_ZERO = unchecked((int)0xC000008E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_INEXACT_RESULT = unchecked((int)0xC000008F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_INVALID_OPERATION = unchecked((int)0xC0000090);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_OVERFLOW = unchecked((int)0xC0000091);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_STACK_CHECK = unchecked((int)0xC0000092);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_UNDERFLOW = unchecked((int)0xC0000093);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTEGER_DIVIDE_BY_ZERO = unchecked((int)0xC0000094);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTEGER_OVERFLOW = unchecked((int)0xC0000095);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRIVILEGED_INSTRUCTION = unchecked((int)0xC0000096);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_PAGING_FILES = unchecked((int)0xC0000097);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_INVALID = unchecked((int)0xC0000098);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALLOTTED_SPACE_EXCEEDED = unchecked((int)0xC0000099);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFFICIENT_RESOURCES = unchecked((int)0xC000009A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DFS_EXIT_PATH_FOUND = unchecked((int)0xC000009B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_DATA_ERROR = unchecked((int)0xC000009C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_NOT_CONNECTED = unchecked((int)0xC000009D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_POWER_FAILURE = unchecked((int)0xC000009E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FREE_VM_NOT_AT_BASE = unchecked((int)0xC000009F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMORY_NOT_ALLOCATED = unchecked((int)0xC00000A0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WORKING_SET_QUOTA = unchecked((int)0xC00000A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEDIA_WRITE_PROTECTED = unchecked((int)0xC00000A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_NOT_READY = unchecked((int)0xC00000A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_GROUP_ATTRIBUTES = unchecked((int)0xC00000A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_IMPERSONATION_LEVEL = unchecked((int)0xC00000A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_OPEN_ANONYMOUS = unchecked((int)0xC00000A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_VALIDATION_CLASS = unchecked((int)0xC00000A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_TOKEN_TYPE = unchecked((int)0xC00000A8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_MASTER_BOOT_RECORD = unchecked((int)0xC00000A9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSTRUCTION_MISALIGNMENT = unchecked((int)0xC00000AA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSTANCE_NOT_AVAILABLE = unchecked((int)0xC00000AB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_NOT_AVAILABLE = unchecked((int)0xC00000AC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PIPE_STATE = unchecked((int)0xC00000AD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_BUSY = unchecked((int)0xC00000AE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_FUNCTION = unchecked((int)0xC00000AF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_DISCONNECTED = unchecked((int)0xC00000B0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_CLOSING = unchecked((int)0xC00000B1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_CONNECTED = unchecked((int)0xC00000B2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_LISTENING = unchecked((int)0xC00000B3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_READ_MODE = unchecked((int)0xC00000B4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_TIMEOUT = unchecked((int)0xC00000B5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_FORCED_CLOSED = unchecked((int)0xC00000B6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROFILING_NOT_STARTED = unchecked((int)0xC00000B7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROFILING_NOT_STOPPED = unchecked((int)0xC00000B8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COULD_NOT_INTERPRET = unchecked((int)0xC00000B9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_IS_A_DIRECTORY = unchecked((int)0xC00000BA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SUPPORTED = unchecked((int)0xC00000BB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_NOT_LISTENING = unchecked((int)0xC00000BC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DUPLICATE_NAME = unchecked((int)0xC00000BD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_NETWORK_PATH = unchecked((int)0xC00000BE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_BUSY = unchecked((int)0xC00000BF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_DOES_NOT_EXIST = unchecked((int)0xC00000C0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_COMMANDS = unchecked((int)0xC00000C1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADAPTER_HARDWARE_ERROR = unchecked((int)0xC00000C2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_NETWORK_RESPONSE = unchecked((int)0xC00000C3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNEXPECTED_NETWORK_ERROR = unchecked((int)0xC00000C4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_REMOTE_ADAPTER = unchecked((int)0xC00000C5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRINT_QUEUE_FULL = unchecked((int)0xC00000C6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SPOOL_SPACE = unchecked((int)0xC00000C7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRINT_CANCELLED = unchecked((int)0xC00000C8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_NAME_DELETED = unchecked((int)0xC00000C9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_ACCESS_DENIED = unchecked((int)0xC00000CA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_DEVICE_TYPE = unchecked((int)0xC00000CB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_NETWORK_NAME = unchecked((int)0xC00000CC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_NAMES = unchecked((int)0xC00000CD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_SESSIONS = unchecked((int)0xC00000CE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHARING_PAUSED = unchecked((int)0xC00000CF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REQUEST_NOT_ACCEPTED = unchecked((int)0xC00000D0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REDIRECTOR_PAUSED = unchecked((int)0xC00000D1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NET_WRITE_FAULT = unchecked((int)0xC00000D2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROFILING_AT_LIMIT = unchecked((int)0xC00000D3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SAME_DEVICE = unchecked((int)0xC00000D4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_RENAMED = unchecked((int)0xC00000D5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTUAL_CIRCUIT_CLOSED = unchecked((int)0xC00000D6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SECURITY_ON_OBJECT = unchecked((int)0xC00000D7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_WAIT = unchecked((int)0xC00000D8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_EMPTY = unchecked((int)0xC00000D9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_ACCESS_DOMAIN_INFO = unchecked((int)0xC00000DA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_TERMINATE_SELF = unchecked((int)0xC00000DB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SERVER_STATE = unchecked((int)0xC00000DC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DOMAIN_STATE = unchecked((int)0xC00000DD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DOMAIN_ROLE = unchecked((int)0xC00000DE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_DOMAIN = unchecked((int)0xC00000DF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOMAIN_EXISTS = unchecked((int)0xC00000E0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOMAIN_LIMIT_EXCEEDED = unchecked((int)0xC00000E1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPLOCK_NOT_GRANTED = unchecked((int)0xC00000E2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_OPLOCK_PROTOCOL = unchecked((int)0xC00000E3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERNAL_DB_CORRUPTION = unchecked((int)0xC00000E4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERNAL_ERROR = unchecked((int)0xC00000E5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GENERIC_NOT_MAPPED = unchecked((int)0xC00000E6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_DESCRIPTOR_FORMAT = unchecked((int)0xC00000E7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_USER_BUFFER = unchecked((int)0xC00000E8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNEXPECTED_IO_ERROR = unchecked((int)0xC00000E9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNEXPECTED_MM_CREATE_ERR = unchecked((int)0xC00000EA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNEXPECTED_MM_MAP_ERROR = unchecked((int)0xC00000EB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNEXPECTED_MM_EXTEND_ERR = unchecked((int)0xC00000EC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_LOGON_PROCESS = unchecked((int)0xC00000ED);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_SESSION_EXISTS = unchecked((int)0xC00000EE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_1 = unchecked((int)0xC00000EF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_2 = unchecked((int)0xC00000F0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_3 = unchecked((int)0xC00000F1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_4 = unchecked((int)0xC00000F2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_5 = unchecked((int)0xC00000F3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_6 = unchecked((int)0xC00000F4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_7 = unchecked((int)0xC00000F5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_8 = unchecked((int)0xC00000F6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_9 = unchecked((int)0xC00000F7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_10 = unchecked((int)0xC00000F8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_11 = unchecked((int)0xC00000F9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PARAMETER_12 = unchecked((int)0xC00000FA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REDIRECTOR_NOT_STARTED = unchecked((int)0xC00000FB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REDIRECTOR_STARTED = unchecked((int)0xC00000FC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STACK_OVERFLOW = unchecked((int)0xC00000FD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_PACKAGE = unchecked((int)0xC00000FE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_FUNCTION_TABLE = unchecked((int)0xC00000FF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VARIABLE_NOT_FOUND = unchecked((int)0xC0000100);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DIRECTORY_NOT_EMPTY = unchecked((int)0xC0000101);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_CORRUPT_ERROR = unchecked((int)0xC0000102);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_DIRECTORY = unchecked((int)0xC0000103);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_LOGON_SESSION_STATE = unchecked((int)0xC0000104);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_SESSION_COLLISION = unchecked((int)0xC0000105);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NAME_TOO_LONG = unchecked((int)0xC0000106);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILES_OPEN = unchecked((int)0xC0000107);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_IN_USE = unchecked((int)0xC0000108);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MESSAGE_NOT_FOUND = unchecked((int)0xC0000109);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCESS_IS_TERMINATING = unchecked((int)0xC000010A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LOGON_TYPE = unchecked((int)0xC000010B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_GUID_TRANSLATION = unchecked((int)0xC000010C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_IMPERSONATE = unchecked((int)0xC000010D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_ALREADY_LOADED = unchecked((int)0xC000010E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_NOT_PRESENT = unchecked((int)0xC000010F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_LID_NOT_EXIST = unchecked((int)0xC0000110);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_LID_ALREADY_OWNED = unchecked((int)0xC0000111);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_NOT_LID_OWNER = unchecked((int)0xC0000112);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_INVALID_COMMAND = unchecked((int)0xC0000113);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_INVALID_LID = unchecked((int)0xC0000114);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_SELECTOR_NOT_AVAILABLE = unchecked((int)0xC0000115);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ABIOS_INVALID_SELECTOR = unchecked((int)0xC0000116);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_LDT = unchecked((int)0xC0000117);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LDT_SIZE = unchecked((int)0xC0000118);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LDT_OFFSET = unchecked((int)0xC0000119);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LDT_DESCRIPTOR = unchecked((int)0xC000011A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_NE_FORMAT = unchecked((int)0xC000011B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RXACT_INVALID_STATE = unchecked((int)0xC000011C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RXACT_COMMIT_FAILURE = unchecked((int)0xC000011D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MAPPED_FILE_SIZE_ZERO = unchecked((int)0xC000011E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_OPENED_FILES = unchecked((int)0xC000011F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANCELLED = unchecked((int)0xC0000120);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_DELETE = unchecked((int)0xC0000121);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_COMPUTER_NAME = unchecked((int)0xC0000122);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_DELETED = unchecked((int)0xC0000123);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPECIAL_ACCOUNT = unchecked((int)0xC0000124);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPECIAL_GROUP = unchecked((int)0xC0000125);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPECIAL_USER = unchecked((int)0xC0000126);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMBERS_PRIMARY_GROUP = unchecked((int)0xC0000127);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_CLOSED = unchecked((int)0xC0000128);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_THREADS = unchecked((int)0xC0000129);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_NOT_IN_PROCESS = unchecked((int)0xC000012A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOKEN_ALREADY_IN_USE = unchecked((int)0xC000012B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGEFILE_QUOTA_EXCEEDED = unchecked((int)0xC000012C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMMITMENT_LIMIT = unchecked((int)0xC000012D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_LE_FORMAT = unchecked((int)0xC000012E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_NOT_MZ = unchecked((int)0xC000012F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_PROTECT = unchecked((int)0xC0000130);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_WIN_16 = unchecked((int)0xC0000131);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_SERVER_CONFLICT = unchecked((int)0xC0000132);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TIME_DIFFERENCE_AT_DC = unchecked((int)0xC0000133);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYNCHRONIZATION_REQUIRED = unchecked((int)0xC0000134);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DLL_NOT_FOUND = unchecked((int)0xC0000135);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPEN_FAILED = unchecked((int)0xC0000136);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_PRIVILEGE_FAILED = unchecked((int)0xC0000137);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ORDINAL_NOT_FOUND = unchecked((int)0xC0000138);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENTRYPOINT_NOT_FOUND = unchecked((int)0xC0000139);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTROL_C_EXIT = unchecked((int)0xC000013A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOCAL_DISCONNECT = unchecked((int)0xC000013B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_DISCONNECT = unchecked((int)0xC000013C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_RESOURCES = unchecked((int)0xC000013D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LINK_FAILED = unchecked((int)0xC000013E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LINK_TIMEOUT = unchecked((int)0xC000013F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_CONNECTION = unchecked((int)0xC0000140);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ADDRESS = unchecked((int)0xC0000141);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DLL_INIT_FAILED = unchecked((int)0xC0000142);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MISSING_SYSTEMFILE = unchecked((int)0xC0000143);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNHANDLED_EXCEPTION = unchecked((int)0xC0000144);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_INIT_FAILURE = unchecked((int)0xC0000145);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PAGEFILE_CREATE_FAILED = unchecked((int)0xC0000146);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_PAGEFILE = unchecked((int)0xC0000147);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LEVEL = unchecked((int)0xC0000148);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_PASSWORD_CORE = unchecked((int)0xC0000149);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_FLOAT_CONTEXT = unchecked((int)0xC000014A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PIPE_BROKEN = unchecked((int)0xC000014B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REGISTRY_CORRUPT = unchecked((int)0xC000014C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REGISTRY_IO_FAILED = unchecked((int)0xC000014D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_EVENT_PAIR = unchecked((int)0xC000014E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNRECOGNIZED_VOLUME = unchecked((int)0xC000014F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERIAL_NO_DEVICE_INITED = unchecked((int)0xC0000150);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_ALIAS = unchecked((int)0xC0000151);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMBER_NOT_IN_ALIAS = unchecked((int)0xC0000152);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MEMBER_IN_ALIAS = unchecked((int)0xC0000153);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALIAS_EXISTS = unchecked((int)0xC0000154);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGON_NOT_GRANTED = unchecked((int)0xC0000155);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_SECRETS = unchecked((int)0xC0000156);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECRET_TOO_LONG = unchecked((int)0xC0000157);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERNAL_DB_ERROR = unchecked((int)0xC0000158);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FULLSCREEN_MODE = unchecked((int)0xC0000159);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_CONTEXT_IDS = unchecked((int)0xC000015A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_REGISTRY_FILE = unchecked((int)0xC000015C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NT_CROSS_ENCRYPTION_REQUIRED = unchecked((int)0xC000015D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOMAIN_CTRLR_CONFIG_ERROR = unchecked((int)0xC000015E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_MISSING_MEMBER = unchecked((int)0xC000015F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILL_FORMED_SERVICE_ENTRY = unchecked((int)0xC0000160);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_CHARACTER = unchecked((int)0xC0000161);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNMAPPABLE_CHARACTER = unchecked((int)0xC0000162);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNDEFINED_CHARACTER = unchecked((int)0xC0000163);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOPPY_VOLUME = unchecked((int)0xC0000164);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOPPY_ID_MARK_NOT_FOUND = unchecked((int)0xC0000165);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOPPY_WRONG_CYLINDER = unchecked((int)0xC0000166);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOPPY_UNKNOWN_ERROR = unchecked((int)0xC0000167);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOPPY_BAD_REGISTERS = unchecked((int)0xC0000168);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_RECALIBRATE_FAILED = unchecked((int)0xC0000169);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_OPERATION_FAILED = unchecked((int)0xC000016A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_RESET_FAILED = unchecked((int)0xC000016B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHARED_IRQ_BUSY = unchecked((int)0xC000016C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_ORPHANING = unchecked((int)0xC000016D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT = unchecked((int)0xC000016E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PARTITION_FAILURE = unchecked((int)0xC0000172);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_BLOCK_LENGTH = unchecked((int)0xC0000173);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_NOT_PARTITIONED = unchecked((int)0xC0000174);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNABLE_TO_LOCK_MEDIA = unchecked((int)0xC0000175);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNABLE_TO_UNLOAD_MEDIA = unchecked((int)0xC0000176);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EOM_OVERFLOW = unchecked((int)0xC0000177);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MEDIA = unchecked((int)0xC0000178);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SUCH_MEMBER = unchecked((int)0xC000017A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_MEMBER = unchecked((int)0xC000017B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KEY_DELETED = unchecked((int)0xC000017C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_LOG_SPACE = unchecked((int)0xC000017D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_SIDS = unchecked((int)0xC000017E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LM_CROSS_ENCRYPTION_REQUIRED = unchecked((int)0xC000017F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KEY_HAS_CHILDREN = unchecked((int)0xC0000180);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CHILD_MUST_BE_VOLATILE = unchecked((int)0xC0000181);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_CONFIGURATION_ERROR = unchecked((int)0xC0000182);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_INTERNAL_ERROR = unchecked((int)0xC0000183);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DEVICE_STATE = unchecked((int)0xC0000184);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_DEVICE_ERROR = unchecked((int)0xC0000185);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_PROTOCOL_ERROR = unchecked((int)0xC0000186);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BACKUP_CONTROLLER = unchecked((int)0xC0000187);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_FILE_FULL = unchecked((int)0xC0000188);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_LATE = unchecked((int)0xC0000189);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TRUST_LSA_SECRET = unchecked((int)0xC000018A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TRUST_SAM_ACCOUNT = unchecked((int)0xC000018B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRUSTED_DOMAIN_FAILURE = unchecked((int)0xC000018C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRUSTED_RELATIONSHIP_FAILURE = unchecked((int)0xC000018D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVENTLOG_FILE_CORRUPT = unchecked((int)0xC000018E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVENTLOG_CANT_START = unchecked((int)0xC000018F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRUST_FAILURE = unchecked((int)0xC0000190);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUTANT_LIMIT_EXCEEDED = unchecked((int)0xC0000191);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETLOGON_NOT_STARTED = unchecked((int)0xC0000192);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_POSSIBLE_DEADLOCK = unchecked((int)0xC0000194);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_CREDENTIAL_CONFLICT = unchecked((int)0xC0000195);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_SESSION_LIMIT = unchecked((int)0xC0000196);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVENTLOG_FILE_CHANGED = unchecked((int)0xC0000197);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT = unchecked((int)0xC0000198);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT = unchecked((int)0xC0000199);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOLOGON_SERVER_TRUST_ACCOUNT = unchecked((int)0xC000019A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOMAIN_TRUST_INCONSISTENT = unchecked((int)0xC000019B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FS_DRIVER_REQUIRED = unchecked((int)0xC000019C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_ALREADY_LOADED_AS_DLL = unchecked((int)0xC000019D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING = unchecked((int)0xC000019E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHORT_NAMES_NOT_ENABLED_ON_VOLUME = unchecked((int)0xC000019F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECURITY_STREAM_IS_INCONSISTENT = unchecked((int)0xC00001A0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LOCK_RANGE = unchecked((int)0xC00001A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ACE_CONDITION = unchecked((int)0xC00001A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_SUBSYSTEM_NOT_PRESENT = unchecked((int)0xC00001A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOTIFICATION_GUID_ALREADY_DEFINED = unchecked((int)0xC00001A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_EXCEPTION_HANDLER = unchecked((int)0xC00001A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DUPLICATE_PRIVILEGES = unchecked((int)0xC00001A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_ALLOWED_ON_SYSTEM_FILE = unchecked((int)0xC00001A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPAIR_NEEDED = unchecked((int)0xC00001A8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUOTA_NOT_ENABLED = unchecked((int)0xC00001A9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_APPLICATION_PACKAGE = unchecked((int)0xC00001AA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_METADATA_OPTIMIZATION_IN_PROGRESS = unchecked((int)0xC00001AB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SAME_OBJECT = unchecked((int)0xC00001AC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FATAL_MEMORY_EXHAUSTION = unchecked((int)0xC00001AD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ERROR_PROCESS_NOT_IN_JOB = unchecked((int)0xC00001AE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CPU_SET_INVALID = unchecked((int)0xC00001AF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_DEVICE_INVALID_DATA = unchecked((int)0xC00001B0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_UNALIGNED_WRITE = unchecked((int)0xC00001B1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTROL_STACK_VIOLATION = unchecked((int)0xC00001B2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_OPEN_RESTRICTION = unchecked((int)0xC0000201);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_USER_SESSION_KEY = unchecked((int)0xC0000202);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER_SESSION_DELETED = unchecked((int)0xC0000203);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_LANG_NOT_FOUND = unchecked((int)0xC0000204);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFF_SERVER_RESOURCES = unchecked((int)0xC0000205);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_BUFFER_SIZE = unchecked((int)0xC0000206);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ADDRESS_COMPONENT = unchecked((int)0xC0000207);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_ADDRESS_WILDCARD = unchecked((int)0xC0000208);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_ADDRESSES = unchecked((int)0xC0000209);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADDRESS_ALREADY_EXISTS = unchecked((int)0xC000020A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADDRESS_CLOSED = unchecked((int)0xC000020B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_DISCONNECTED = unchecked((int)0xC000020C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_RESET = unchecked((int)0xC000020D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_NODES = unchecked((int)0xC000020E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_ABORTED = unchecked((int)0xC000020F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_TIMED_OUT = unchecked((int)0xC0000210);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NO_RELEASE = unchecked((int)0xC0000211);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NO_MATCH = unchecked((int)0xC0000212);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_RESPONDED = unchecked((int)0xC0000213);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_INVALID_ID = unchecked((int)0xC0000214);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_INVALID_TYPE = unchecked((int)0xC0000215);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SERVER_SESSION = unchecked((int)0xC0000216);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_CLIENT_SESSION = unchecked((int)0xC0000217);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_LOAD_REGISTRY_FILE = unchecked((int)0xC0000218);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEBUG_ATTACH_FAILED = unchecked((int)0xC0000219);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_PROCESS_TERMINATED = unchecked((int)0xC000021A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_NOT_ACCEPTED = unchecked((int)0xC000021B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_BROWSER_SERVERS_FOUND = unchecked((int)0xC000021C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VDM_HARD_ERROR = unchecked((int)0xC000021D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_CANCEL_TIMEOUT = unchecked((int)0xC000021E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPLY_MESSAGE_MISMATCH = unchecked((int)0xC000021F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MAPPED_ALIGNMENT = unchecked((int)0xC0000220);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_CHECKSUM_MISMATCH = unchecked((int)0xC0000221);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOST_WRITEBEHIND_DATA = unchecked((int)0xC0000222);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIENT_SERVER_PARAMETERS_INVALID = unchecked((int)0xC0000223);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_FOUND = unchecked((int)0xC0000225);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_TINY_STREAM = unchecked((int)0xC0000226);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECOVERY_FAILURE = unchecked((int)0xC0000227);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STACK_OVERFLOW_READ = unchecked((int)0xC0000228);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FAIL_CHECK = unchecked((int)0xC0000229);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DUPLICATE_OBJECTID = unchecked((int)0xC000022A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECTID_EXISTS = unchecked((int)0xC000022B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONVERT_TO_LARGE = unchecked((int)0xC000022C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RETRY = unchecked((int)0xC000022D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FOUND_OUT_OF_SCOPE = unchecked((int)0xC000022E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALLOCATE_BUCKET = unchecked((int)0xC000022F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROPSET_NOT_FOUND = unchecked((int)0xC0000230);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MARSHALL_OVERFLOW = unchecked((int)0xC0000231);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_VARIANT = unchecked((int)0xC0000232);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DOMAIN_CONTROLLER_NOT_FOUND = unchecked((int)0xC0000233);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HANDLE_NOT_CLOSABLE = unchecked((int)0xC0000235);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_REFUSED = unchecked((int)0xC0000236);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRACEFUL_DISCONNECT = unchecked((int)0xC0000237);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADDRESS_ALREADY_ASSOCIATED = unchecked((int)0xC0000238);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADDRESS_NOT_ASSOCIATED = unchecked((int)0xC0000239);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_INVALID = unchecked((int)0xC000023A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_ACTIVE = unchecked((int)0xC000023B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_UNREACHABLE = unchecked((int)0xC000023C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HOST_UNREACHABLE = unchecked((int)0xC000023D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROTOCOL_UNREACHABLE = unchecked((int)0xC000023E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_UNREACHABLE = unchecked((int)0xC000023F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REQUEST_ABORTED = unchecked((int)0xC0000240);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_ABORTED = unchecked((int)0xC0000241);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_COMPRESSION_BUFFER = unchecked((int)0xC0000242);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER_MAPPED_FILE = unchecked((int)0xC0000243);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUDIT_FAILED = unchecked((int)0xC0000244);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TIMER_RESOLUTION_NOT_SET = unchecked((int)0xC0000245);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONNECTION_COUNT_LIMIT = unchecked((int)0xC0000246);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGIN_TIME_RESTRICTION = unchecked((int)0xC0000247);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOGIN_WKSTA_RESTRICTION = unchecked((int)0xC0000248);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_MP_UP_MISMATCH = unchecked((int)0xC0000249);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFFICIENT_LOGON_INFO = unchecked((int)0xC0000250);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_DLL_ENTRYPOINT = unchecked((int)0xC0000251);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_SERVICE_ENTRYPOINT = unchecked((int)0xC0000252);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPC_REPLY_LOST = unchecked((int)0xC0000253);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IP_ADDRESS_CONFLICT1 = unchecked((int)0xC0000254);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IP_ADDRESS_CONFLICT2 = unchecked((int)0xC0000255);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REGISTRY_QUOTA_LIMIT = unchecked((int)0xC0000256);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PATH_NOT_COVERED = unchecked((int)0xC0000257);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_CALLBACK_ACTIVE = unchecked((int)0xC0000258);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LICENSE_QUOTA_EXCEEDED = unchecked((int)0xC0000259);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PWD_TOO_SHORT = unchecked((int)0xC000025A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PWD_TOO_RECENT = unchecked((int)0xC000025B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PWD_HISTORY_CONFLICT = unchecked((int)0xC000025C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLUGPLAY_NO_DEVICE = unchecked((int)0xC000025E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNSUPPORTED_COMPRESSION = unchecked((int)0xC000025F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_HW_PROFILE = unchecked((int)0xC0000260);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PLUGPLAY_DEVICE_PATH = unchecked((int)0xC0000261);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_ORDINAL_NOT_FOUND = unchecked((int)0xC0000262);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_ENTRYPOINT_NOT_FOUND = unchecked((int)0xC0000263);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_NOT_OWNED = unchecked((int)0xC0000264);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_LINKS = unchecked((int)0xC0000265);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUOTA_LIST_INCONSISTENT = unchecked((int)0xC0000266);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_IS_OFFLINE = unchecked((int)0xC0000267);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EVALUATION_EXPIRATION = unchecked((int)0xC0000268);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_DLL_RELOCATION = unchecked((int)0xC0000269);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LICENSE_VIOLATION = unchecked((int)0xC000026A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DLL_INIT_FAILED_LOGOFF = unchecked((int)0xC000026B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_UNABLE_TO_LOAD = unchecked((int)0xC000026C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DFS_UNAVAILABLE = unchecked((int)0xC000026D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLUME_DISMOUNTED = unchecked((int)0xC000026E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_INTERNAL_ERROR = unchecked((int)0xC000026F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WX86_FLOAT_STACK_CHECK = unchecked((int)0xC0000270);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VALIDATE_CONTINUE = unchecked((int)0xC0000271);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MATCH = unchecked((int)0xC0000272);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_MORE_MATCHES = unchecked((int)0xC0000273);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_REPARSE_POINT = unchecked((int)0xC0000275);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_REPARSE_TAG_INVALID = unchecked((int)0xC0000276);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_REPARSE_TAG_MISMATCH = unchecked((int)0xC0000277);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_REPARSE_DATA_INVALID = unchecked((int)0xC0000278);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_REPARSE_TAG_NOT_HANDLED = unchecked((int)0xC0000279);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PWD_TOO_LONG = unchecked((int)0xC000027A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STOWED_EXCEPTION = unchecked((int)0xC000027B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTEXT_STOWED_EXCEPTION = unchecked((int)0xC000027C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE_POINT_NOT_RESOLVED = unchecked((int)0xC0000280);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DIRECTORY_IS_A_REPARSE_POINT = unchecked((int)0xC0000281);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RANGE_LIST_CONFLICT = unchecked((int)0xC0000282);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SOURCE_ELEMENT_EMPTY = unchecked((int)0xC0000283);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DESTINATION_ELEMENT_FULL = unchecked((int)0xC0000284);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ILLEGAL_ELEMENT_ADDRESS = unchecked((int)0xC0000285);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MAGAZINE_NOT_PRESENT = unchecked((int)0xC0000286);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REINITIALIZATION_NEEDED = unchecked((int)0xC0000287);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_REQUIRES_CLEANING = unchecked((int)0x80000288);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_DOOR_OPEN = unchecked((int)0x80000289);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCRYPTION_FAILED = unchecked((int)0xC000028A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DECRYPTION_FAILED = unchecked((int)0xC000028B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RANGE_NOT_FOUND = unchecked((int)0xC000028C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_RECOVERY_POLICY = unchecked((int)0xC000028D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_EFS = unchecked((int)0xC000028E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_EFS = unchecked((int)0xC000028F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_USER_KEYS = unchecked((int)0xC0000290);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_NOT_ENCRYPTED = unchecked((int)0xC0000291);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_EXPORT_FORMAT = unchecked((int)0xC0000292);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_ENCRYPTED = unchecked((int)0xC0000293);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WAKE_SYSTEM = 0x40000294;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_GUID_NOT_FOUND = unchecked((int)0xC0000295);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_INSTANCE_NOT_FOUND = unchecked((int)0xC0000296);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_ITEMID_NOT_FOUND = unchecked((int)0xC0000297);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_TRY_AGAIN = unchecked((int)0xC0000298);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHARED_POLICY = unchecked((int)0xC0000299);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_POLICY_OBJECT_NOT_FOUND = unchecked((int)0xC000029A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_POLICY_ONLY_IN_DS = unchecked((int)0xC000029B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLUME_NOT_UPGRADED = unchecked((int)0xC000029C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_STORAGE_NOT_ACTIVE = unchecked((int)0xC000029D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_STORAGE_MEDIA_ERROR = unchecked((int)0xC000029E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TRACKING_SERVICE = unchecked((int)0xC000029F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_SID_MISMATCH = unchecked((int)0xC00002A0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_ATTRIBUTE_OR_VALUE = unchecked((int)0xC00002A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_INVALID_ATTRIBUTE_SYNTAX = unchecked((int)0xC00002A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED = unchecked((int)0xC00002A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS = unchecked((int)0xC00002A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_BUSY = unchecked((int)0xC00002A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_UNAVAILABLE = unchecked((int)0xC00002A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_RIDS_ALLOCATED = unchecked((int)0xC00002A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_MORE_RIDS = unchecked((int)0xC00002A8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_INCORRECT_ROLE_OWNER = unchecked((int)0xC00002A9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_RIDMGR_INIT_ERROR = unchecked((int)0xC00002AA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_OBJ_CLASS_VIOLATION = unchecked((int)0xC00002AB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CANT_ON_NON_LEAF = unchecked((int)0xC00002AC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CANT_ON_RDN = unchecked((int)0xC00002AD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CANT_MOD_OBJ_CLASS = unchecked((int)0xC00002AE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CROSS_DOM_MOVE_FAILED = unchecked((int)0xC00002AF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GC_NOT_AVAILABLE = unchecked((int)0xC00002B0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DIRECTORY_SERVICE_REQUIRED = unchecked((int)0xC00002B1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE_ATTRIBUTE_CONFLICT = unchecked((int)0xC00002B2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_ENABLE_DENY_ONLY = unchecked((int)0xC00002B3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_MULTIPLE_FAULTS = unchecked((int)0xC00002B4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOAT_MULTIPLE_TRAPS = unchecked((int)0xC00002B5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_REMOVED = unchecked((int)0xC00002B6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_JOURNAL_DELETE_IN_PROGRESS = unchecked((int)0xC00002B7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_JOURNAL_NOT_ACTIVE = unchecked((int)0xC00002B8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOINTERFACE = unchecked((int)0xC00002B9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_RIDMGR_DISABLED = unchecked((int)0xC00002BA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_ADMIN_LIMIT_EXCEEDED = unchecked((int)0xC00002C1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_FAILED_SLEEP = unchecked((int)0xC00002C2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUTUAL_AUTHENTICATION_FAILED = unchecked((int)0xC00002C3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_SYSTEM_FILE = unchecked((int)0xC00002C4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATATYPE_MISALIGNMENT_ERROR = unchecked((int)0xC00002C5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_READ_ONLY = unchecked((int)0xC00002C6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_SET_FAILURE = unchecked((int)0xC00002C7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMMITMENT_MINIMUM = unchecked((int)0xC00002C8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REG_NAT_CONSUMPTION = unchecked((int)0xC00002C9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSPORT_FULL = unchecked((int)0xC00002CA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_SAM_INIT_FAILURE = unchecked((int)0xC00002CB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ONLY_IF_CONNECTED = unchecked((int)0xC00002CC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_SENSITIVE_GROUP_VIOLATION = unchecked((int)0xC00002CD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_RESTART_ENUMERATION = unchecked((int)0xC00002CE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_JOURNAL_ENTRY_DELETED = unchecked((int)0xC00002CF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CANT_MOD_PRIMARYGROUPID = unchecked((int)0xC00002D0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_IMAGE_BAD_SIGNATURE = unchecked((int)0xC00002D1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_REBOOT_REQUIRED = unchecked((int)0xC00002D2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_POWER_STATE_INVALID = unchecked((int)0xC00002D3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_INVALID_GROUP_TYPE = unchecked((int)0xC00002D4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN = unchecked((int)0xC00002D5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN = unchecked((int)0xC00002D6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER = unchecked((int)0xC00002D7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER = unchecked((int)0xC00002D8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER = unchecked((int)0xC00002D9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER = unchecked((int)0xC00002DA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER = unchecked((int)0xC00002DB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_HAVE_PRIMARY_MEMBERS = unchecked((int)0xC00002DC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_NOT_SUPPORTED = unchecked((int)0xC00002DD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFFICIENT_POWER = unchecked((int)0xC00002DE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SAM_NEED_BOOTKEY_PASSWORD = unchecked((int)0xC00002DF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SAM_NEED_BOOTKEY_FLOPPY = unchecked((int)0xC00002E0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_CANT_START = unchecked((int)0xC00002E1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_INIT_FAILURE = unchecked((int)0xC00002E2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SAM_INIT_FAILURE = unchecked((int)0xC00002E3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GC_REQUIRED = unchecked((int)0xC00002E4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY = unchecked((int)0xC00002E5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS = unchecked((int)0xC00002E6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED = unchecked((int)0xC00002E7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MULTIPLE_FAULT_VIOLATION = unchecked((int)0xC00002E8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CURRENT_DOMAIN_NOT_ALLOWED = unchecked((int)0xC00002E9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_MAKE = unchecked((int)0xC00002EA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_SHUTDOWN = unchecked((int)0xC00002EB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_INIT_FAILURE_CONSOLE = unchecked((int)0xC00002EC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_SAM_INIT_FAILURE_CONSOLE = unchecked((int)0xC00002ED);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNFINISHED_CONTEXT_DELETED = unchecked((int)0xC00002EE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TGT_REPLY = unchecked((int)0xC00002EF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECTID_NOT_FOUND = unchecked((int)0xC00002F0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_IP_ADDRESSES = unchecked((int)0xC00002F1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_CREDENTIAL_HANDLE = unchecked((int)0xC00002F2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRYPTO_SYSTEM_INVALID = unchecked((int)0xC00002F3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MAX_REFERRALS_EXCEEDED = unchecked((int)0xC00002F4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUST_BE_KDC = unchecked((int)0xC00002F5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STRONG_CRYPTO_NOT_SUPPORTED = unchecked((int)0xC00002F6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_PRINCIPALS = unchecked((int)0xC00002F7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_PA_DATA = unchecked((int)0xC00002F8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PKINIT_NAME_MISMATCH = unchecked((int)0xC00002F9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_LOGON_REQUIRED = unchecked((int)0xC00002FA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KDC_INVALID_REQUEST = unchecked((int)0xC00002FB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KDC_UNABLE_TO_REFER = unchecked((int)0xC00002FC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KDC_UNKNOWN_ETYPE = unchecked((int)0xC00002FD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHUTDOWN_IN_PROGRESS = unchecked((int)0xC00002FE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_SHUTDOWN_IN_PROGRESS = unchecked((int)0xC00002FF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SUPPORTED_ON_SBS = unchecked((int)0xC0000300);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_GUID_DISCONNECTED = unchecked((int)0xC0000301);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_ALREADY_DISABLED = unchecked((int)0xC0000302);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WMI_ALREADY_ENABLED = unchecked((int)0xC0000303);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MFT_TOO_FRAGMENTED = unchecked((int)0xC0000304);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COPY_PROTECTION_FAILURE = unchecked((int)0xC0000305);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_AUTHENTICATION_FAILURE = unchecked((int)0xC0000306);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_KEY_NOT_PRESENT = unchecked((int)0xC0000307);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_KEY_NOT_ESTABLISHED = unchecked((int)0xC0000308);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_SCRAMBLED_SECTOR = unchecked((int)0xC0000309);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_REGION_MISMATCH = unchecked((int)0xC000030A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSS_RESETS_EXHAUSTED = unchecked((int)0xC000030B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PASSWORD_CHANGE_REQUIRED = unchecked((int)0xC000030C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOST_MODE_LOGON_RESTRICTION = unchecked((int)0xC000030D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PKINIT_FAILURE = unchecked((int)0xC0000320);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_SUBSYSTEM_FAILURE = unchecked((int)0xC0000321);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_KERB_KEY = unchecked((int)0xC0000322);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HOST_DOWN = unchecked((int)0xC0000350);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNSUPPORTED_PREAUTH = unchecked((int)0xC0000351);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EFS_ALG_BLOB_TOO_BIG = unchecked((int)0xC0000352);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_NOT_SET = unchecked((int)0xC0000353);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEBUGGER_INACTIVE = unchecked((int)0xC0000354);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_VERSION_CHECK_FAILURE = unchecked((int)0xC0000355);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUDITING_DISABLED = unchecked((int)0xC0000356);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PRENT4_MACHINE_ACCOUNT = unchecked((int)0xC0000357);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER = unchecked((int)0xC0000358);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_WIN_32 = unchecked((int)0xC0000359);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_WIN_64 = unchecked((int)0xC000035A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_BINDINGS = unchecked((int)0xC000035B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_SESSION_EXPIRED = unchecked((int)0xC000035C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPHELP_BLOCK = unchecked((int)0xC000035D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALL_SIDS_FILTERED = unchecked((int)0xC000035E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SAFE_MODE_DRIVER = unchecked((int)0xC000035F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT = unchecked((int)0xC0000361);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DISABLED_BY_POLICY_PATH = unchecked((int)0xC0000362);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER = unchecked((int)0xC0000363);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DISABLED_BY_POLICY_OTHER = unchecked((int)0xC0000364);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FAILED_DRIVER_ENTRY = unchecked((int)0xC0000365);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_ENUMERATION_ERROR = unchecked((int)0xC0000366);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MOUNT_POINT_NOT_RESOLVED = unchecked((int)0xC0000368);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_DEVICE_OBJECT_PARAMETER = unchecked((int)0xC0000369);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MCA_OCCURED = unchecked((int)0xC000036A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_BLOCKED_CRITICAL = unchecked((int)0xC000036B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_BLOCKED = unchecked((int)0xC000036C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_DATABASE_ERROR = unchecked((int)0xC000036D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_HIVE_TOO_LARGE = unchecked((int)0xC000036E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMPORT_OF_NON_DLL = unchecked((int)0xC000036F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_SHUTTING_DOWN = 0x40000370;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SECRETS = unchecked((int)0xC0000371);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY = unchecked((int)0xC0000372);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FAILED_STACK_SWITCH = unchecked((int)0xC0000373);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HEAP_CORRUPTION = unchecked((int)0xC0000374);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_WRONG_PIN = unchecked((int)0xC0000380);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_CARD_BLOCKED = unchecked((int)0xC0000381);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED = unchecked((int)0xC0000382);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_NO_CARD = unchecked((int)0xC0000383);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_NO_KEY_CONTAINER = unchecked((int)0xC0000384);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_NO_CERTIFICATE = unchecked((int)0xC0000385);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_NO_KEYSET = unchecked((int)0xC0000386);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_IO_ERROR = unchecked((int)0xC0000387);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_CERT_REVOKED = unchecked((int)0xC0000389);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ISSUING_CA_UNTRUSTED = unchecked((int)0xC000038A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REVOCATION_OFFLINE_C = unchecked((int)0xC000038B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PKINIT_CLIENT_FAILURE = unchecked((int)0xC000038C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_CERT_EXPIRED = unchecked((int)0xC000038D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_FAILED_PRIOR_UNLOAD = unchecked((int)0xC000038E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMARTCARD_SILENT_CONTEXT = unchecked((int)0xC000038F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PER_USER_TRUST_QUOTA_EXCEEDED = unchecked((int)0xC0000401);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED = unchecked((int)0xC0000402);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED = unchecked((int)0xC0000403);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_NAME_NOT_UNIQUE = unchecked((int)0xC0000404);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_DUPLICATE_ID_FOUND = unchecked((int)0xC0000405);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_GROUP_CONVERSION_ERROR = unchecked((int)0xC0000406);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLSNAP_PREPARE_HIBERNATE = unchecked((int)0xC0000407);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_USER2USER_REQUIRED = unchecked((int)0xC0000408);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STACK_BUFFER_OVERRUN = unchecked((int)0xC0000409);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_S4U_PROT_SUPPORT = unchecked((int)0xC000040A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CROSSREALM_DELEGATION_FAILURE = unchecked((int)0xC000040B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REVOCATION_OFFLINE_KDC = unchecked((int)0xC000040C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ISSUING_CA_UNTRUSTED_KDC = unchecked((int)0xC000040D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KDC_CERT_EXPIRED = unchecked((int)0xC000040E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KDC_CERT_REVOKED = unchecked((int)0xC000040F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PARAMETER_QUOTA_EXCEEDED = unchecked((int)0xC0000410);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HIBERNATION_FAILURE = unchecked((int)0xC0000411);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DELAY_LOAD_FAILED = unchecked((int)0xC0000412);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VDM_DISALLOWED = unchecked((int)0xC0000414);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HUNG_DISPLAY_DRIVER_THREAD = unchecked((int)0xC0000415);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE = unchecked((int)0xC0000416);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_CRUNTIME_PARAMETER = unchecked((int)0xC0000417);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NTLM_BLOCKED = unchecked((int)0xC0000418);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_SRC_SID_EXISTS_IN_FOREST = unchecked((int)0xC0000419);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_DOMAIN_NAME_EXISTS_IN_FOREST = unchecked((int)0xC000041A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_FLAT_NAME_EXISTS_IN_FOREST = unchecked((int)0xC000041B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_USER_PRINCIPAL_NAME = unchecked((int)0xC000041C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FATAL_USER_CALLBACK_EXCEPTION = unchecked((int)0xC000041D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ASSERTION_FAILURE = unchecked((int)0xC0000420);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VERIFIER_STOP = unchecked((int)0xC0000421);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_POP_STACK = unchecked((int)0xC0000423);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INCOMPATIBLE_DRIVER_BLOCKED = unchecked((int)0xC0000424);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HIVE_UNLOADED = unchecked((int)0xC0000425);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMPRESSION_DISABLED = unchecked((int)0xC0000426);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_LIMITATION = unchecked((int)0xC0000427);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IMAGE_HASH = unchecked((int)0xC0000428);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_CAPABLE = unchecked((int)0xC0000429);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REQUEST_OUT_OF_SEQUENCE = unchecked((int)0xC000042A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMPLEMENTATION_LIMIT = unchecked((int)0xC000042B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ELEVATION_REQUIRED = unchecked((int)0xC000042C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SECURITY_CONTEXT = unchecked((int)0xC000042D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PKU2U_CERT_FAILURE = unchecked((int)0xC000042F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BEYOND_VDL = unchecked((int)0xC0000432);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCOUNTERED_WRITE_IN_PROGRESS = unchecked((int)0xC0000433);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PTE_CHANGED = unchecked((int)0xC0000434);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PURGE_FAILED = unchecked((int)0xC0000435);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRED_REQUIRES_CONFIRMATION = unchecked((int)0xC0000440);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CS_ENCRYPTION_INVALID_SERVER_RESPONSE = unchecked((int)0xC0000441);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CS_ENCRYPTION_UNSUPPORTED_SERVER = unchecked((int)0xC0000442);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE = unchecked((int)0xC0000443);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CS_ENCRYPTION_NEW_ENCRYPTED_FILE = unchecked((int)0xC0000444);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CS_ENCRYPTION_FILE_NOT_CSE = unchecked((int)0xC0000445);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_LABEL = unchecked((int)0xC0000446);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DRIVER_PROCESS_TERMINATED = unchecked((int)0xC0000450);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AMBIGUOUS_SYSTEM_DEVICE = unchecked((int)0xC0000451);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_DEVICE_NOT_FOUND = unchecked((int)0xC0000452);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESTART_BOOT_APPLICATION = unchecked((int)0xC0000453);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INSUFFICIENT_NVRAM_RESOURCES = unchecked((int)0xC0000454);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SESSION = unchecked((int)0xC0000455);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_ALREADY_IN_SESSION = unchecked((int)0xC0000456);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_NOT_IN_SESSION = unchecked((int)0xC0000457);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_WEIGHT = unchecked((int)0xC0000458);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REQUEST_PAUSED = unchecked((int)0xC0000459);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_RANGES_PROCESSED = unchecked((int)0xC0000460);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_RESOURCES_EXHAUSTED = unchecked((int)0xC0000461);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NEEDS_REMEDIATION = unchecked((int)0xC0000462);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_FEATURE_NOT_SUPPORTED = unchecked((int)0xC0000463);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_UNREACHABLE = unchecked((int)0xC0000464);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_TOKEN = unchecked((int)0xC0000465);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVER_UNAVAILABLE = unchecked((int)0xC0000466);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_NOT_AVAILABLE = unchecked((int)0xC0000467);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_INSUFFICIENT_RESOURCES = unchecked((int)0xC0000468);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PACKAGE_UPDATING = unchecked((int)0xC0000469);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_READ_FROM_COPY = unchecked((int)0xC000046A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_WRITE_FAILURE = unchecked((int)0xC000046B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_DI_SCAN_REQUIRED = unchecked((int)0xC000046C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NOT_EXTERNALLY_BACKED = unchecked((int)0xC000046D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EXTERNAL_BACKING_PROVIDER_UNKNOWN = unchecked((int)0xC000046E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMPRESSION_NOT_BENEFICIAL = unchecked((int)0xC000046F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_CHECKSUM_ERROR = unchecked((int)0xC0000470);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERMIXED_KERNEL_EA_OPERATION = unchecked((int)0xC0000471);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRIM_READ_ZERO_NOT_SUPPORTED = unchecked((int)0xC0000472);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TOO_MANY_SEGMENT_DESCRIPTORS = unchecked((int)0xC0000473);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_OFFSET_ALIGNMENT = unchecked((int)0xC0000474);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_FIELD_IN_PARAMETER_LIST = unchecked((int)0xC0000475);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPERATION_IN_PROGRESS = unchecked((int)0xC0000476);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_INITIATOR_TARGET_PATH = unchecked((int)0xC0000477);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SCRUB_DATA_DISABLED = unchecked((int)0xC0000478);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_REDUNDANT_STORAGE = unchecked((int)0xC0000479);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESIDENT_FILE_NOT_SUPPORTED = unchecked((int)0xC000047A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMPRESSED_FILE_NOT_SUPPORTED = unchecked((int)0xC000047B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DIRECTORY_NOT_SUPPORTED = unchecked((int)0xC000047C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_OPERATION_TIMEOUT = unchecked((int)0xC000047D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_NEEDS_REMEDIATION = unchecked((int)0xC000047E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPX_INTEGRITY_FAILURE_CLR_NGEN = unchecked((int)0xC000047F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SHARE_UNAVAILABLE = unchecked((int)0xC0000480);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APISET_NOT_HOSTED = unchecked((int)0xC0000481);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APISET_NOT_PRESENT = unchecked((int)0xC0000482);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_HARDWARE_ERROR = unchecked((int)0xC0000483);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FIRMWARE_SLOT_INVALID = unchecked((int)0xC0000484);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FIRMWARE_IMAGE_INVALID = unchecked((int)0xC0000485);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_TOPOLOGY_ID_MISMATCH = unchecked((int)0xC0000486);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WIM_NOT_BOOTABLE = unchecked((int)0xC0000487);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BLOCKED_BY_PARENTAL_CONTROLS = unchecked((int)0xC0000488);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NEEDS_REGISTRATION = unchecked((int)0xC0000489);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUOTA_ACTIVITY = unchecked((int)0xC000048A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_INVOKE_INLINE = unchecked((int)0xC000048B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BLOCK_TOO_MANY_REFERENCES = unchecked((int)0xC000048C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MARKED_TO_DISALLOW_WRITES = unchecked((int)0xC000048D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NETWORK_ACCESS_DENIED_EDP = unchecked((int)0xC000048E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCLAVE_FAILURE = unchecked((int)0xC000048F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_NO_COMPAT_DRIVERS = unchecked((int)0xC0000490);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_DRIVER_PACKAGE_NOT_FOUND = unchecked((int)0xC0000491);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_DRIVER_CONFIGURATION_NOT_FOUND = unchecked((int)0xC0000492);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_DRIVER_CONFIGURATION_INCOMPLETE = unchecked((int)0xC0000493);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_FUNCTION_DRIVER_REQUIRED = unchecked((int)0xC0000494);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_DEVICE_CONFIGURATION_PENDING = unchecked((int)0xC0000495);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_HINT_NAME_BUFFER_TOO_SMALL = unchecked((int)0xC0000496);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PACKAGE_NOT_AVAILABLE = unchecked((int)0xC0000497);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_IN_MAINTENANCE = unchecked((int)0xC0000499);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SUPPORTED_ON_DAX = unchecked((int)0xC000049A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FREE_SPACE_TOO_FRAGMENTED = unchecked((int)0xC000049B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DAX_MAPPING_EXISTS = unchecked((int)0xC000049C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CHILD_PROCESS_BLOCKED = unchecked((int)0xC000049D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_LOST_DATA_PERSISTENCE = unchecked((int)0xC000049E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VRF_CFG_AND_IO_ENABLED = unchecked((int)0xC000049F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PARTITION_TERMINATING = unchecked((int)0xC00004A0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EXTERNAL_SYSKEY_NOT_SUPPORTED = unchecked((int)0xC00004A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCLAVE_VIOLATION = unchecked((int)0xC00004A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_PROTECTED_UNDER_DPL = unchecked((int)0xC00004A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLUME_NOT_CLUSTER_ALIGNED = unchecked((int)0xC00004A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_PHYSICALLY_ALIGNED_FREE_SPACE_FOUND = unchecked((int)0xC00004A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPX_FILE_NOT_ENCRYPTED = unchecked((int)0xC00004A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RWRAW_ENCRYPTED_FILE_NOT_ENCRYPTED = unchecked((int)0xC00004A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILEOFFSET = unchecked((int)0xC00004A8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RWRAW_ENCRYPTED_INVALID_EDATAINFO_FILERANGE = unchecked((int)0xC00004A9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RWRAW_ENCRYPTED_INVALID_EDATAINFO_PARAMETER = unchecked((int)0xC00004AA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FT_READ_FAILURE = unchecked((int)0xC00004AB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PATCH_CONFLICT = unchecked((int)0xC00004AC);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_RESERVE_ID_INVALID = unchecked((int)0xC00004AD);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_RESERVE_DOES_NOT_EXIST = unchecked((int)0xC00004AE);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_RESERVE_ALREADY_EXISTS = unchecked((int)0xC00004AF);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STORAGE_RESERVE_NOT_EMPTY = unchecked((int)0xC00004B0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_DAX_VOLUME = unchecked((int)0xC00004B1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_DAX_MAPPABLE = unchecked((int)0xC00004B2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CASE_DIFFERING_NAMES_IN_DIR = unchecked((int)0xC00004B3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_NOT_SUPPORTED = unchecked((int)0xC00004B4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SUPPORTED_WITH_BTT = unchecked((int)0xC00004B5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCRYPTION_DISABLED = unchecked((int)0xC00004B6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCRYPTING_METADATA_DISALLOWED = unchecked((int)0xC00004B7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_CLEAR_ENCRYPTION_FLAG = unchecked((int)0xC00004B8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNSATISFIED_DEPENDENCIES = unchecked((int)0xC00004B9);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CASE_SENSITIVE_PATH = unchecked((int)0xC00004BA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_TASK_NAME = unchecked((int)0xC0000500);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_TASK_INDEX = unchecked((int)0xC0000501);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_ALREADY_IN_TASK = unchecked((int)0xC0000502);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_BYPASS = unchecked((int)0xC0000503);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_UNDEFINED_SCOPE = unchecked((int)0xC0000504);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_CAP = unchecked((int)0xC0000505);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_GUI_PROCESS = unchecked((int)0xC0000506);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_HUNG = unchecked((int)0xC0000507);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTAINER_ASSIGNED = unchecked((int)0xC0000508);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_JOB_NO_CONTAINER = unchecked((int)0xC0000509);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DEVICE_UNRESPONSIVE = unchecked((int)0xC000050A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REPARSE_POINT_ENCOUNTERED = unchecked((int)0xC000050B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ATTRIBUTE_NOT_PRESENT = unchecked((int)0xC000050C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_TIERED_VOLUME = unchecked((int)0xC000050D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_HAS_STREAM_ID = unchecked((int)0xC000050E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_JOB_NOT_EMPTY = unchecked((int)0xC000050F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_INITIALIZED = unchecked((int)0xC0000510);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCLAVE_NOT_TERMINATED = unchecked((int)0xC0000511);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCLAVE_IS_TERMINATING = unchecked((int)0xC0000512);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMB1_NOT_AVAILABLE = unchecked((int)0xC0000513);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMR_GARBAGE_COLLECTION_REQUIRED = unchecked((int)0xC0000514);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INTERRUPTED = unchecked((int)0xC0000515);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREAD_NOT_RUNNING = unchecked((int)0xC0000516);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FAIL_FAST_EXCEPTION = unchecked((int)0xC0000602);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_CERT_REVOKED = unchecked((int)0xC0000603);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DYNAMIC_CODE_BLOCKED = unchecked((int)0xC0000604);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IMAGE_CERT_EXPIRED = unchecked((int)0xC0000605);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STRICT_CFG_VIOLATION = unchecked((int)0xC0000606);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SET_CONTEXT_DENIED = unchecked((int)0xC000060A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CROSS_PARTITION_VIOLATION = unchecked((int)0xC000060B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_CLOSED = unchecked((int)0xC0000700);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MESSAGE_LOST = unchecked((int)0xC0000701);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_MESSAGE = unchecked((int)0xC0000702);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REQUEST_CANCELED = unchecked((int)0xC0000703);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECURSIVE_DISPATCH = unchecked((int)0xC0000704);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPC_RECEIVE_BUFFER_EXPECTED = unchecked((int)0xC0000705);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPC_INVALID_CONNECTION_USAGE = unchecked((int)0xC0000706);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPC_REQUESTS_NOT_ALLOWED = unchecked((int)0xC0000707);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_IN_USE = unchecked((int)0xC0000708);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HARDWARE_MEMORY_ERROR = unchecked((int)0xC0000709);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_HANDLE_EXCEPTION = unchecked((int)0xC000070A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_SET_EVENT_ON_COMPLETION_FAILED = unchecked((int)0xC000070B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_RELEASE_SEMAPHORE_ON_COMPLETION_FAILED = unchecked((int)0xC000070C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_RELEASE_MUTEX_ON_COMPLETION_FAILED = unchecked((int)0xC000070D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_FREE_LIBRARY_ON_COMPLETION_FAILED = unchecked((int)0xC000070E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_THREADPOOL_RELEASED_DURING_OPERATION = unchecked((int)0xC000070F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_WHILE_IMPERSONATING = unchecked((int)0xC0000710);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APC_RETURNED_WHILE_IMPERSONATING = unchecked((int)0xC0000711);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROCESS_IS_PROTECTED = unchecked((int)0xC0000712);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MCA_EXCEPTION = unchecked((int)0xC0000713);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CERTIFICATE_MAPPING_NOT_UNIQUE = unchecked((int)0xC0000714);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYMLINK_CLASS_DISABLED = unchecked((int)0xC0000715);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_IDN_NORMALIZATION = unchecked((int)0xC0000716);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_UNICODE_TRANSLATION = unchecked((int)0xC0000717);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ALREADY_REGISTERED = unchecked((int)0xC0000718);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTEXT_MISMATCH = unchecked((int)0xC0000719);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PORT_ALREADY_HAS_COMPLETION_LIST = unchecked((int)0xC000071A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_THREAD_PRIORITY = unchecked((int)0xC000071B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_THREAD = unchecked((int)0xC000071C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_TRANSACTION = unchecked((int)0xC000071D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_LDR_LOCK = unchecked((int)0xC000071E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_LANG = unchecked((int)0xC000071F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_PRI_BACK = unchecked((int)0xC0000720);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CALLBACK_RETURNED_THREAD_AFFINITY = unchecked((int)0xC0000721);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPC_HANDLE_COUNT_EXCEEDED = unchecked((int)0xC0000722);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EXECUTABLE_MEMORY_WRITE = unchecked((int)0xC0000723);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_KERNEL_EXECUTABLE_MEMORY_WRITE = unchecked((int)0xC0000724);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ATTACHED_EXECUTABLE_MEMORY_WRITE = unchecked((int)0xC0000725);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRIGGERED_EXECUTABLE_MEMORY_WRITE = unchecked((int)0xC0000726);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_REPAIR_DISABLED = unchecked((int)0xC0000800);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_DOMAIN_RENAME_IN_PROGRESS = unchecked((int)0xC0000801);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_QUOTA_EXCEEDED = unchecked((int)0xC0000802);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DATA_LOST_REPAIR = unchecked((int)0x80000803);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CONTENT_BLOCKED = unchecked((int)0xC0000804);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_CLUSTERS = unchecked((int)0xC0000805);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLUME_DIRTY = unchecked((int)0xC0000806);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_REPAIR_REDIRECTED = 0x40000807;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DISK_REPAIR_UNSUCCESSFUL = unchecked((int)0xC0000808);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_OVERFULL = unchecked((int)0xC0000809);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_CORRUPTED = unchecked((int)0xC000080A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_UNAVAILABLE = unchecked((int)0xC000080B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_DELETED_FULL = unchecked((int)0xC000080C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_CLEARED = unchecked((int)0xC000080D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ORPHAN_NAME_EXHAUSTED = unchecked((int)0xC000080E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROACTIVE_SCAN_IN_PROGRESS = unchecked((int)0xC000080F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENCRYPTED_IO_NOT_POSSIBLE = unchecked((int)0xC0000810);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CORRUPT_LOG_UPLEVEL_RECORDS = unchecked((int)0xC0000811);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_CHECKED_OUT = unchecked((int)0xC0000901);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CHECKOUT_REQUIRED = unchecked((int)0xC0000902);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_FILE_TYPE = unchecked((int)0xC0000903);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_TOO_LARGE = unchecked((int)0xC0000904);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FORMS_AUTH_REQUIRED = unchecked((int)0xC0000905);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRUS_INFECTED = unchecked((int)0xC0000906);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRUS_DELETED = unchecked((int)0xC0000907);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_MCFG_TABLE = unchecked((int)0xC0000908);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_BREAK_OPLOCK = unchecked((int)0xC0000909);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_KEY = unchecked((int)0xC000090A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BAD_DATA = unchecked((int)0xC000090B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_KEY = unchecked((int)0xC000090C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_HANDLE_REVOKED = unchecked((int)0xC0000910);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WOW_ASSERTION = unchecked((int)0xC0009898);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_SIGNATURE = unchecked((int)0xC000A000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HMAC_NOT_SUPPORTED = unchecked((int)0xC000A001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUTH_TAG_MISMATCH = unchecked((int)0xC000A002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_STATE_TRANSITION = unchecked((int)0xC000A003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_KERNEL_INFO_VERSION = unchecked((int)0xC000A004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PEP_INFO_VERSION = unchecked((int)0xC000A005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HANDLE_REVOKED = unchecked((int)0xC000A006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EOF_ON_GHOSTED_RANGE = unchecked((int)0xC000A007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CC_NEEDS_CALLBACK_SECTION_DRAIN = unchecked((int)0xC000A008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_QUEUE_OVERFLOW = unchecked((int)0xC000A010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ND_QUEUE_OVERFLOW = unchecked((int)0xC000A011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HOPLIMIT_EXCEEDED = unchecked((int)0xC000A012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PROTOCOL_NOT_SUPPORTED = unchecked((int)0xC000A013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FASTPATH_REJECTED = unchecked((int)0xC000A014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED = unchecked((int)0xC000A080);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR = unchecked((int)0xC000A081);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR = unchecked((int)0xC000A082);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_XML_PARSE_ERROR = unchecked((int)0xC000A083);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_XMLDSIG_ERROR = unchecked((int)0xC000A084);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WRONG_COMPARTMENT = unchecked((int)0xC000A085);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUTHIP_FAILURE = unchecked((int)0xC000A086);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS = unchecked((int)0xC000A087);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DS_OID_NOT_FOUND = unchecked((int)0xC000A088);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INCORRECT_ACCOUNT_TYPE = unchecked((int)0xC000A089);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HASH_NOT_SUPPORTED = unchecked((int)0xC000A100);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HASH_NOT_PRESENT = unchecked((int)0xC000A101);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECONDARY_IC_PROVIDER_NOT_REGISTERED = unchecked((int)0xC000A121);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_CLIENT_INFORMATION_INVALID = unchecked((int)0xC000A122);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_VERSION_NOT_SUPPORTED = unchecked((int)0xC000A123);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_INVALID_REGISTRATION_PACKET = unchecked((int)0xC000A124);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_OPERATION_DENIED = unchecked((int)0xC000A125);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_INCOMPATIBLE_CONNECT_MODE = unchecked((int)0xC000A126);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GPIO_INTERRUPT_ALREADY_UNMASKED = unchecked((int)0x8000A127);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_SWITCH_RUNLEVEL = unchecked((int)0xC000A141);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_RUNLEVEL_SETTING = unchecked((int)0xC000A142);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RUNLEVEL_SWITCH_TIMEOUT = unchecked((int)0xC000A143);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SERVICES_FAILED_AUTOSTART = 0x4000A144;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RUNLEVEL_SWITCH_AGENT_TIMEOUT = unchecked((int)0xC000A145);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RUNLEVEL_SWITCH_IN_PROGRESS = unchecked((int)0xC000A146);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_APPCONTAINER = unchecked((int)0xC000A200);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SUPPORTED_IN_APPCONTAINER = unchecked((int)0xC000A201);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_PACKAGE_SID_LENGTH = unchecked((int)0xC000A202);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LPAC_ACCESS_DENIED = unchecked((int)0xC000A203);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADMINLESS_ACCESS_DENIED = unchecked((int)0xC000A204);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_DATA_NOT_FOUND = unchecked((int)0xC000A281);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_DATA_EXPIRED = unchecked((int)0xC000A282);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_DATA_CORRUPT = unchecked((int)0xC000A283);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_DATA_LIMIT_EXCEEDED = unchecked((int)0xC000A284);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APP_DATA_REBOOT_REQUIRED = unchecked((int)0xC000A285);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OFFLOAD_READ_FLT_NOT_SUPPORTED = unchecked((int)0xC000A2A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OFFLOAD_WRITE_FLT_NOT_SUPPORTED = unchecked((int)0xC000A2A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OFFLOAD_READ_FILE_NOT_SUPPORTED = unchecked((int)0xC000A2A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OFFLOAD_WRITE_FILE_NOT_SUPPORTED = unchecked((int)0xC000A2A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WOF_WIM_HEADER_CORRUPT = unchecked((int)0xC000A2A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WOF_WIM_RESOURCE_TABLE_CORRUPT = unchecked((int)0xC000A2A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_WOF_FILE_RESOURCE_TABLE_CORRUPT = unchecked((int)0xC000A2A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CIMFS_IMAGE_CORRUPT = unchecked((int)0xC000C001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_VIRTUALIZATION_UNAVAILABLE = unchecked((int)0xC000CE01);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_VIRTUALIZATION_METADATA_CORRUPT = unchecked((int)0xC000CE02);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_VIRTUALIZATION_BUSY = unchecked((int)0xC000CE03);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_VIRTUALIZATION_PROVIDER_UNKNOWN = unchecked((int)0xC000CE04);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SYSTEM_VIRTUALIZATION_INVALID_OPERATION = unchecked((int)0xC000CE05);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_SYNC_ROOT_METADATA_CORRUPT = unchecked((int)0xC000CF00);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROVIDER_NOT_RUNNING = unchecked((int)0xC000CF01);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_METADATA_CORRUPT = unchecked((int)0xC000CF02);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_METADATA_TOO_LARGE = unchecked((int)0xC000CF03);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROPERTY_BLOB_TOO_LARGE = unchecked((int)0x8000CF04);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_TOO_MANY_PROPERTY_BLOBS = unchecked((int)0x8000CF05);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROPERTY_VERSION_NOT_SUPPORTED = unchecked((int)0xC000CF06);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_CLOUD_FILE = unchecked((int)0xC000CF07);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_NOT_IN_SYNC = unchecked((int)0xC000CF08);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_ALREADY_CONNECTED = unchecked((int)0xC000CF09);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_NOT_SUPPORTED = unchecked((int)0xC000CF0A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_INVALID_REQUEST = unchecked((int)0xC000CF0B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_READ_ONLY_VOLUME = unchecked((int)0xC000CF0C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_CONNECTED_PROVIDER_ONLY = unchecked((int)0xC000CF0D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_VALIDATION_FAILED = unchecked((int)0xC000CF0E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_AUTHENTICATION_FAILED = unchecked((int)0xC000CF0F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_INSUFFICIENT_RESOURCES = unchecked((int)0xC000CF10);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_NETWORK_UNAVAILABLE = unchecked((int)0xC000CF11);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_UNSUCCESSFUL = unchecked((int)0xC000CF12);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_NOT_UNDER_SYNC_ROOT = unchecked((int)0xC000CF13);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_IN_USE = unchecked((int)0xC000CF14);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PINNED = unchecked((int)0xC000CF15);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_REQUEST_ABORTED = unchecked((int)0xC000CF16);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROPERTY_CORRUPT = unchecked((int)0xC000CF17);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_ACCESS_DENIED = unchecked((int)0xC000CF18);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_INCOMPATIBLE_HARDLINKS = unchecked((int)0xC000CF19);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROPERTY_LOCK_CONFLICT = unchecked((int)0xC000CF1A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_REQUEST_CANCELED = unchecked((int)0xC000CF1B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_PROVIDER_TERMINATED = unchecked((int)0xC000CF1D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_A_CLOUD_SYNC_ROOT = unchecked((int)0xC000CF1E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_REQUEST_TIMEOUT = unchecked((int)0xC000CF1F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLOUD_FILE_DEHYDRATION_DISALLOWED = unchecked((int)0xC000CF20);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_IN_PROGRESS = unchecked((int)0xC000F500);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_USER_SECTION_NOT_SUPPORTED = unchecked((int)0xC000F501);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_MODIFY_NOT_SUPPORTED = unchecked((int)0xC000F502);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_IO_NOT_COORDINATED = unchecked((int)0xC000F503);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_UNEXPECTED_ERROR = unchecked((int)0xC000F504);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_SNAP_INVALID_PARAMETER = unchecked((int)0xC000F505);

        [NativeTypeName("NTSTATUS")]
        public const int DBG_NO_STATE_CHANGE = unchecked((int)0xC0010001);

        [NativeTypeName("NTSTATUS")]
        public const int DBG_APP_NOT_IDLE = unchecked((int)0xC0010002);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_STRING_BINDING = unchecked((int)0xC0020001);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_WRONG_KIND_OF_BINDING = unchecked((int)0xC0020002);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_BINDING = unchecked((int)0xC0020003);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PROTSEQ_NOT_SUPPORTED = unchecked((int)0xC0020004);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_RPC_PROTSEQ = unchecked((int)0xC0020005);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_STRING_UUID = unchecked((int)0xC0020006);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_ENDPOINT_FORMAT = unchecked((int)0xC0020007);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_NET_ADDR = unchecked((int)0xC0020008);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_ENDPOINT_FOUND = unchecked((int)0xC0020009);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_TIMEOUT = unchecked((int)0xC002000A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_OBJECT_NOT_FOUND = unchecked((int)0xC002000B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ALREADY_REGISTERED = unchecked((int)0xC002000C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_TYPE_ALREADY_REGISTERED = unchecked((int)0xC002000D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ALREADY_LISTENING = unchecked((int)0xC002000E);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_PROTSEQS_REGISTERED = unchecked((int)0xC002000F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NOT_LISTENING = unchecked((int)0xC0020010);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_MGR_TYPE = unchecked((int)0xC0020011);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_IF = unchecked((int)0xC0020012);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_BINDINGS = unchecked((int)0xC0020013);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_PROTSEQS = unchecked((int)0xC0020014);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CANT_CREATE_ENDPOINT = unchecked((int)0xC0020015);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_OUT_OF_RESOURCES = unchecked((int)0xC0020016);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SERVER_UNAVAILABLE = unchecked((int)0xC0020017);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SERVER_TOO_BUSY = unchecked((int)0xC0020018);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_NETWORK_OPTIONS = unchecked((int)0xC0020019);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_CALL_ACTIVE = unchecked((int)0xC002001A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CALL_FAILED = unchecked((int)0xC002001B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CALL_FAILED_DNE = unchecked((int)0xC002001C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PROTOCOL_ERROR = unchecked((int)0xC002001D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNSUPPORTED_TRANS_SYN = unchecked((int)0xC002001F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNSUPPORTED_TYPE = unchecked((int)0xC0020021);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_TAG = unchecked((int)0xC0020022);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_BOUND = unchecked((int)0xC0020023);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_ENTRY_NAME = unchecked((int)0xC0020024);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_NAME_SYNTAX = unchecked((int)0xC0020025);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNSUPPORTED_NAME_SYNTAX = unchecked((int)0xC0020026);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UUID_NO_ADDRESS = unchecked((int)0xC0020028);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_DUPLICATE_ENDPOINT = unchecked((int)0xC0020029);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_AUTHN_TYPE = unchecked((int)0xC002002A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_MAX_CALLS_TOO_SMALL = unchecked((int)0xC002002B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_STRING_TOO_LONG = unchecked((int)0xC002002C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PROTSEQ_NOT_FOUND = unchecked((int)0xC002002D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PROCNUM_OUT_OF_RANGE = unchecked((int)0xC002002E);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_BINDING_HAS_NO_AUTH = unchecked((int)0xC002002F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_AUTHN_SERVICE = unchecked((int)0xC0020030);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_AUTHN_LEVEL = unchecked((int)0xC0020031);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_AUTH_IDENTITY = unchecked((int)0xC0020032);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNKNOWN_AUTHZ_SERVICE = unchecked((int)0xC0020033);

        [NativeTypeName("NTSTATUS")]
        public const int EPT_NT_INVALID_ENTRY = unchecked((int)0xC0020034);

        [NativeTypeName("NTSTATUS")]
        public const int EPT_NT_CANT_PERFORM_OP = unchecked((int)0xC0020035);

        [NativeTypeName("NTSTATUS")]
        public const int EPT_NT_NOT_REGISTERED = unchecked((int)0xC0020036);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NOTHING_TO_EXPORT = unchecked((int)0xC0020037);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INCOMPLETE_NAME = unchecked((int)0xC0020038);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_VERS_OPTION = unchecked((int)0xC0020039);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_MORE_MEMBERS = unchecked((int)0xC002003A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NOT_ALL_OBJS_UNEXPORTED = unchecked((int)0xC002003B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INTERFACE_NOT_FOUND = unchecked((int)0xC002003C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ENTRY_ALREADY_EXISTS = unchecked((int)0xC002003D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ENTRY_NOT_FOUND = unchecked((int)0xC002003E);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NAME_SERVICE_UNAVAILABLE = unchecked((int)0xC002003F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_NAF_ID = unchecked((int)0xC0020040);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CANNOT_SUPPORT = unchecked((int)0xC0020041);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_CONTEXT_AVAILABLE = unchecked((int)0xC0020042);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INTERNAL_ERROR = unchecked((int)0xC0020043);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ZERO_DIVIDE = unchecked((int)0xC0020044);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ADDRESS_ERROR = unchecked((int)0xC0020045);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_FP_DIV_ZERO = unchecked((int)0xC0020046);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_FP_UNDERFLOW = unchecked((int)0xC0020047);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_FP_OVERFLOW = unchecked((int)0xC0020048);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_MORE_ENTRIES = unchecked((int)0xC0030001);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_CHAR_TRANS_OPEN_FAIL = unchecked((int)0xC0030002);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_CHAR_TRANS_SHORT_FILE = unchecked((int)0xC0030003);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_IN_NULL_CONTEXT = unchecked((int)0xC0030004);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_CONTEXT_MISMATCH = unchecked((int)0xC0030005);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_CONTEXT_DAMAGED = unchecked((int)0xC0030006);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_HANDLES_MISMATCH = unchecked((int)0xC0030007);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SS_CANNOT_GET_CALL_HANDLE = unchecked((int)0xC0030008);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NULL_REF_POINTER = unchecked((int)0xC0030009);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_ENUM_VALUE_OUT_OF_RANGE = unchecked((int)0xC003000A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_BYTE_COUNT_TOO_SMALL = unchecked((int)0xC003000B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_BAD_STUB_DATA = unchecked((int)0xC003000C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CALL_IN_PROGRESS = unchecked((int)0xC0020049);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_MORE_BINDINGS = unchecked((int)0xC002004A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_GROUP_MEMBER_NOT_FOUND = unchecked((int)0xC002004B);

        [NativeTypeName("NTSTATUS")]
        public const int EPT_NT_CANT_CREATE = unchecked((int)0xC002004C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_OBJECT = unchecked((int)0xC002004D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_INTERFACES = unchecked((int)0xC002004F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_CALL_CANCELLED = unchecked((int)0xC0020050);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_BINDING_INCOMPLETE = unchecked((int)0xC0020051);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_COMM_FAILURE = unchecked((int)0xC0020052);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UNSUPPORTED_AUTHN_LEVEL = unchecked((int)0xC0020053);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NO_PRINC_NAME = unchecked((int)0xC0020054);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NOT_RPC_ERROR = unchecked((int)0xC0020055);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_UUID_LOCAL_ONLY = 0x40020056;

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SEC_PKG_ERROR = unchecked((int)0xC0020057);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_NOT_CANCELLED = unchecked((int)0xC0020058);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_ES_ACTION = unchecked((int)0xC0030059);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_WRONG_ES_VERSION = unchecked((int)0xC003005A);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_WRONG_STUB_VERSION = unchecked((int)0xC003005B);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_PIPE_OBJECT = unchecked((int)0xC003005C);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_PIPE_OPERATION = unchecked((int)0xC003005D);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_WRONG_PIPE_VERSION = unchecked((int)0xC003005E);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PIPE_CLOSED = unchecked((int)0xC003005F);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PIPE_DISCIPLINE_ERROR = unchecked((int)0xC0030060);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PIPE_EMPTY = unchecked((int)0xC0030061);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_ASYNC_HANDLE = unchecked((int)0xC0020062);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_INVALID_ASYNC_CALL = unchecked((int)0xC0020063);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_PROXY_ACCESS_DENIED = unchecked((int)0xC0020064);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_COOKIE_AUTH_FAILED = unchecked((int)0xC0020065);

        [NativeTypeName("NTSTATUS")]
        public const int RPC_NT_SEND_INCOMPLETE = 0x400200AF;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_OPCODE = unchecked((int)0xC0140001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_STACK_OVERFLOW = unchecked((int)0xC0140002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_ASSERT_FAILED = unchecked((int)0xC0140003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_INDEX = unchecked((int)0xC0140004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_ARGUMENT = unchecked((int)0xC0140005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_FATAL = unchecked((int)0xC0140006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_SUPERNAME = unchecked((int)0xC0140007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_ARGTYPE = unchecked((int)0xC0140008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_OBJTYPE = unchecked((int)0xC0140009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_TARGETTYPE = unchecked((int)0xC014000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INCORRECT_ARGUMENT_COUNT = unchecked((int)0xC014000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_ADDRESS_NOT_MAPPED = unchecked((int)0xC014000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_EVENTTYPE = unchecked((int)0xC014000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_HANDLER_COLLISION = unchecked((int)0xC014000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_DATA = unchecked((int)0xC014000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_REGION = unchecked((int)0xC0140010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_ACCESS_SIZE = unchecked((int)0xC0140011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_ACQUIRE_GLOBAL_LOCK = unchecked((int)0xC0140012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_ALREADY_INITIALIZED = unchecked((int)0xC0140013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_NOT_INITIALIZED = unchecked((int)0xC0140014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_MUTEX_LEVEL = unchecked((int)0xC0140015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_MUTEX_NOT_OWNED = unchecked((int)0xC0140016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_MUTEX_NOT_OWNER = unchecked((int)0xC0140017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_RS_ACCESS = unchecked((int)0xC0140018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_INVALID_TABLE = unchecked((int)0xC0140019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_REG_HANDLER_FAILED = unchecked((int)0xC0140020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ACPI_POWER_REQUEST_FAILED = unchecked((int)0xC0140021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WINSTATION_NAME_INVALID = unchecked((int)0xC00A0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_INVALID_PD = unchecked((int)0xC00A0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_PD_NOT_FOUND = unchecked((int)0xC00A0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CDM_CONNECT = 0x400A0004;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CDM_DISCONNECT = 0x400A0005;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CLOSE_PENDING = unchecked((int)0xC00A0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_NO_OUTBUF = unchecked((int)0xC00A0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_INF_NOT_FOUND = unchecked((int)0xC00A0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_INVALID_MODEMNAME = unchecked((int)0xC00A0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_RESPONSE_ERROR = unchecked((int)0xC00A000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_RESPONSE_TIMEOUT = unchecked((int)0xC00A000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_RESPONSE_NO_CARRIER = unchecked((int)0xC00A000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_RESPONSE_NO_DIALTONE = unchecked((int)0xC00A000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_RESPONSE_BUSY = unchecked((int)0xC00A000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_MODEM_RESPONSE_VOICE = unchecked((int)0xC00A000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_TD_ERROR = unchecked((int)0xC00A0010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_LICENSE_CLIENT_INVALID = unchecked((int)0xC00A0012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_LICENSE_NOT_AVAILABLE = unchecked((int)0xC00A0013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_LICENSE_EXPIRED = unchecked((int)0xC00A0014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WINSTATION_NOT_FOUND = unchecked((int)0xC00A0015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WINSTATION_NAME_COLLISION = unchecked((int)0xC00A0016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WINSTATION_BUSY = unchecked((int)0xC00A0017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_BAD_VIDEO_MODE = unchecked((int)0xC00A0018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_GRAPHICS_INVALID = unchecked((int)0xC00A0022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_NOT_CONSOLE = unchecked((int)0xC00A0024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CLIENT_QUERY_TIMEOUT = unchecked((int)0xC00A0026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CONSOLE_DISCONNECT = unchecked((int)0xC00A0027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CONSOLE_CONNECT = unchecked((int)0xC00A0028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SHADOW_DENIED = unchecked((int)0xC00A002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WINSTATION_ACCESS_DENIED = unchecked((int)0xC00A002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_INVALID_WD = unchecked((int)0xC00A002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_WD_NOT_FOUND = unchecked((int)0xC00A002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SHADOW_INVALID = unchecked((int)0xC00A0030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SHADOW_DISABLED = unchecked((int)0xC00A0031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RDP_PROTOCOL_ERROR = unchecked((int)0xC00A0032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CLIENT_LICENSE_NOT_SET = unchecked((int)0xC00A0033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_CLIENT_LICENSE_IN_USE = unchecked((int)0xC00A0034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SHADOW_ENDED_BY_MODE_CHANGE = unchecked((int)0xC00A0035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SHADOW_NOT_RUNNING = unchecked((int)0xC00A0036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_LOGON_DISABLED = unchecked((int)0xC00A0037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTX_SECURITY_LAYER_ERROR = unchecked((int)0xC00A0038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TS_INCOMPATIBLE_SESSIONS = unchecked((int)0xC00A0039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TS_VIDEO_SUBSYSTEM_ERROR = unchecked((int)0xC00A003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_BAD_MPS_TABLE = unchecked((int)0xC0040035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_TRANSLATION_FAILED = unchecked((int)0xC0040036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_IRQ_TRANSLATION_FAILED = unchecked((int)0xC0040037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PNP_INVALID_ID = unchecked((int)0xC0040038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_REISSUE_AS_CACHED = unchecked((int)0xC0040039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_FILE_NOT_FOUND = unchecked((int)0xC00B0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_INVALID_FILE = unchecked((int)0xC00B0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_INVALID_RC_CONFIG = unchecked((int)0xC00B0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_INVALID_LOCALE_NAME = unchecked((int)0xC00B0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_INVALID_ULTIMATEFALLBACK_NAME = unchecked((int)0xC00B0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MUI_FILE_NOT_LOADED = unchecked((int)0xC00B0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCE_ENUM_USER_STOP = unchecked((int)0xC00B0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NO_HANDLER_DEFINED = unchecked((int)0xC01C0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_CONTEXT_ALREADY_DEFINED = unchecked((int)0xC01C0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INVALID_ASYNCHRONOUS_REQUEST = unchecked((int)0xC01C0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_DISALLOW_FAST_IO = unchecked((int)0xC01C0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INVALID_NAME_REQUEST = unchecked((int)0xC01C0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NOT_SAFE_TO_POST_OPERATION = unchecked((int)0xC01C0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NOT_INITIALIZED = unchecked((int)0xC01C0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_FILTER_NOT_READY = unchecked((int)0xC01C0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_POST_OPERATION_CLEANUP = unchecked((int)0xC01C0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INTERNAL_ERROR = unchecked((int)0xC01C000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_DELETING_OBJECT = unchecked((int)0xC01C000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_MUST_BE_NONPAGED_POOL = unchecked((int)0xC01C000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_DUPLICATE_ENTRY = unchecked((int)0xC01C000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_CBDQ_DISABLED = unchecked((int)0xC01C000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_DO_NOT_ATTACH = unchecked((int)0xC01C000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_DO_NOT_DETACH = unchecked((int)0xC01C0010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INSTANCE_ALTITUDE_COLLISION = unchecked((int)0xC01C0011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INSTANCE_NAME_COLLISION = unchecked((int)0xC01C0012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_FILTER_NOT_FOUND = unchecked((int)0xC01C0013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_VOLUME_NOT_FOUND = unchecked((int)0xC01C0014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INSTANCE_NOT_FOUND = unchecked((int)0xC01C0015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_CONTEXT_ALLOCATION_NOT_FOUND = unchecked((int)0xC01C0016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_INVALID_CONTEXT_REGISTRATION = unchecked((int)0xC01C0017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NAME_CACHE_MISS = unchecked((int)0xC01C0018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NO_DEVICE_OBJECT = unchecked((int)0xC01C0019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_VOLUME_ALREADY_MOUNTED = unchecked((int)0xC01C001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_ALREADY_ENLISTED = unchecked((int)0xC01C001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_CONTEXT_ALREADY_LINKED = unchecked((int)0xC01C001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_NO_WAITER_FOR_REPLY = unchecked((int)0xC01C0020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLT_REGISTRATION_BUSY = unchecked((int)0xC01C0023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_SECTION_NOT_FOUND = unchecked((int)0xC0150001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_CANT_GEN_ACTCTX = unchecked((int)0xC0150002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_INVALID_ACTCTXDATA_FORMAT = unchecked((int)0xC0150003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_ASSEMBLY_NOT_FOUND = unchecked((int)0xC0150004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_MANIFEST_FORMAT_ERROR = unchecked((int)0xC0150005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_MANIFEST_PARSE_ERROR = unchecked((int)0xC0150006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_ACTIVATION_CONTEXT_DISABLED = unchecked((int)0xC0150007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_KEY_NOT_FOUND = unchecked((int)0xC0150008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_VERSION_CONFLICT = unchecked((int)0xC0150009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_WRONG_SECTION_TYPE = unchecked((int)0xC015000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_THREAD_QUERIES_DISABLED = unchecked((int)0xC015000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_ASSEMBLY_MISSING = unchecked((int)0xC015000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_RELEASE_ACTIVATION_CONTEXT = 0x4015000D;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_PROCESS_DEFAULT_ALREADY_SET = unchecked((int)0xC015000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_EARLY_DEACTIVATION = unchecked((int)0xC015000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_INVALID_DEACTIVATION = unchecked((int)0xC0150010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_MULTIPLE_DEACTIVATION = unchecked((int)0xC0150011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY = unchecked((int)0xC0150012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_PROCESS_TERMINATION_REQUESTED = unchecked((int)0xC0150013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_CORRUPT_ACTIVATION_STACK = unchecked((int)0xC0150014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_CORRUPTION = unchecked((int)0xC0150015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE = unchecked((int)0xC0150016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME = unchecked((int)0xC0150017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_IDENTITY_DUPLICATE_ATTRIBUTE = unchecked((int)0xC0150018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_IDENTITY_PARSE_ERROR = unchecked((int)0xC0150019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_COMPONENT_STORE_CORRUPT = unchecked((int)0xC015001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_FILE_HASH_MISMATCH = unchecked((int)0xC015001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT = unchecked((int)0xC015001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_IDENTITIES_DIFFERENT = unchecked((int)0xC015001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT = unchecked((int)0xC015001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_FILE_NOT_PART_OF_ASSEMBLY = unchecked((int)0xC015001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ADVANCED_INSTALLER_FAILED = unchecked((int)0xC0150020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_XML_ENCODING_MISMATCH = unchecked((int)0xC0150021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_MANIFEST_TOO_BIG = unchecked((int)0xC0150022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_SETTING_NOT_REGISTERED = unchecked((int)0xC0150023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_TRANSACTION_CLOSURE_INCOMPLETE = unchecked((int)0xC0150024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMI_PRIMITIVE_INSTALLER_FAILED = unchecked((int)0xC0150025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GENERIC_COMMAND_FAILED = unchecked((int)0xC0150026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SXS_FILE_HASH_MISSING = unchecked((int)0xC0150027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_INVALID_NODE = unchecked((int)0xC0130001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_EXISTS = unchecked((int)0xC0130002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_JOIN_IN_PROGRESS = unchecked((int)0xC0130003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_NOT_FOUND = unchecked((int)0xC0130004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_LOCAL_NODE_NOT_FOUND = unchecked((int)0xC0130005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETWORK_EXISTS = unchecked((int)0xC0130006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETWORK_NOT_FOUND = unchecked((int)0xC0130007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETINTERFACE_EXISTS = unchecked((int)0xC0130008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETINTERFACE_NOT_FOUND = unchecked((int)0xC0130009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_INVALID_REQUEST = unchecked((int)0xC013000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_INVALID_NETWORK_PROVIDER = unchecked((int)0xC013000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_DOWN = unchecked((int)0xC013000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_UNREACHABLE = unchecked((int)0xC013000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_NOT_MEMBER = unchecked((int)0xC013000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_JOIN_NOT_IN_PROGRESS = unchecked((int)0xC013000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_INVALID_NETWORK = unchecked((int)0xC0130010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NO_NET_ADAPTERS = unchecked((int)0xC0130011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_UP = unchecked((int)0xC0130012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_PAUSED = unchecked((int)0xC0130013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NODE_NOT_PAUSED = unchecked((int)0xC0130014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NO_SECURITY_CONTEXT = unchecked((int)0xC0130015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NETWORK_NOT_INTERNAL = unchecked((int)0xC0130016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_POISONED = unchecked((int)0xC0130017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_NON_CSV_PATH = unchecked((int)0xC0130018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_VOLUME_NOT_LOCAL = unchecked((int)0xC0130019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_READ_OPLOCK_BREAK_IN_PROGRESS = unchecked((int)0xC0130020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_AUTO_PAUSE_ERROR = unchecked((int)0xC0130021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_REDIRECTED = unchecked((int)0xC0130022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_NOT_REDIRECTED = unchecked((int)0xC0130023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_VOLUME_DRAINING = unchecked((int)0xC0130024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_SNAPSHOT_CREATION_IN_PROGRESS = unchecked((int)0xC0130025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_VOLUME_DRAINING_SUCCEEDED_DOWNLEVEL = unchecked((int)0xC0130026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_NO_SNAPSHOTS = unchecked((int)0xC0130027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CSV_IO_PAUSE_TIMEOUT = unchecked((int)0xC0130028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_INVALID_HANDLE = unchecked((int)0xC0130029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CSV_SUPPORTED_ONLY_ON_COORDINATOR = unchecked((int)0xC0130030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLUSTER_CAM_TICKET_REPLAY_DETECTED = unchecked((int)0xC0130031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONAL_CONFLICT = unchecked((int)0xC0190001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INVALID_TRANSACTION = unchecked((int)0xC0190002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_ACTIVE = unchecked((int)0xC0190003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TM_INITIALIZATION_FAILED = unchecked((int)0xC0190004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RM_NOT_ACTIVE = unchecked((int)0xC0190005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RM_METADATA_CORRUPT = unchecked((int)0xC0190006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_JOINED = unchecked((int)0xC0190007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_DIRECTORY_NOT_RM = unchecked((int)0xC0190008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COULD_NOT_RESIZE_LOG = unchecked((int)0x80190009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONS_UNSUPPORTED_REMOTE = unchecked((int)0xC019000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_RESIZE_INVALID_SIZE = unchecked((int)0xC019000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_REMOTE_FILE_VERSION_MISMATCH = unchecked((int)0xC019000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRM_PROTOCOL_ALREADY_EXISTS = unchecked((int)0xC019000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_PROPAGATION_FAILED = unchecked((int)0xC0190010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CRM_PROTOCOL_NOT_FOUND = unchecked((int)0xC0190011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_SUPERIOR_EXISTS = unchecked((int)0xC0190012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_REQUEST_NOT_VALID = unchecked((int)0xC0190013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_REQUESTED = unchecked((int)0xC0190014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_ALREADY_ABORTED = unchecked((int)0xC0190015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_ALREADY_COMMITTED = unchecked((int)0xC0190016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_INVALID_MARSHALL_BUFFER = unchecked((int)0xC0190017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CURRENT_TRANSACTION_NOT_VALID = unchecked((int)0xC0190018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_GROWTH_FAILED = unchecked((int)0xC0190019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OBJECT_NO_LONGER_EXISTS = unchecked((int)0xC0190021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STREAM_MINIVERSION_NOT_FOUND = unchecked((int)0xC0190022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_STREAM_MINIVERSION_NOT_VALID = unchecked((int)0xC0190023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION = unchecked((int)0xC0190024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT = unchecked((int)0xC0190025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_CREATE_MORE_STREAM_MINIVERSIONS = unchecked((int)0xC0190026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HANDLE_NO_LONGER_VALID = unchecked((int)0xC0190028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_TXF_METADATA = unchecked((int)0x80190029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CORRUPTION_DETECTED = unchecked((int)0xC0190030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_RECOVER_WITH_HANDLE_OPEN = unchecked((int)0x80190031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RM_DISCONNECTED = unchecked((int)0xC0190032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENLISTMENT_NOT_SUPERIOR = unchecked((int)0xC0190033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RECOVERY_NOT_NEEDED = 0x40190034;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RM_ALREADY_STARTED = 0x40190035;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FILE_IDENTITY_NOT_PERSISTENT = unchecked((int)0xC0190036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_BREAK_TRANSACTIONAL_DEPENDENCY = unchecked((int)0xC0190037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANT_CROSS_RM_BOUNDARY = unchecked((int)0xC0190038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TXF_DIR_NOT_EMPTY = unchecked((int)0xC0190039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_INDOUBT_TRANSACTIONS_EXIST = unchecked((int)0xC019003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TM_VOLATILE = unchecked((int)0xC019003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ROLLBACK_TIMER_EXPIRED = unchecked((int)0xC019003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TXF_ATTRIBUTE_CORRUPT = unchecked((int)0xC019003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EFS_NOT_ALLOWED_IN_TRANSACTION = unchecked((int)0xC019003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONAL_OPEN_NOT_ALLOWED = unchecked((int)0xC019003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE = unchecked((int)0xC0190040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TXF_METADATA_ALREADY_PRESENT = unchecked((int)0x80190041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_SCOPE_CALLBACKS_NOT_SET = unchecked((int)0x80190042);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_REQUIRED_PROMOTION = unchecked((int)0xC0190043);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_EXECUTE_FILE_IN_TRANSACTION = unchecked((int)0xC0190044);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONS_NOT_FROZEN = unchecked((int)0xC0190045);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_FREEZE_IN_PROGRESS = unchecked((int)0xC0190046);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NOT_SNAPSHOT_VOLUME = unchecked((int)0xC0190047);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_SAVEPOINT_WITH_OPEN_FILES = unchecked((int)0xC0190048);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPARSE_NOT_ALLOWED_IN_TRANSACTION = unchecked((int)0xC0190049);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TM_IDENTITY_MISMATCH = unchecked((int)0xC019004A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FLOATED_SECTION = unchecked((int)0xC019004B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_ACCEPT_TRANSACTED_WORK = unchecked((int)0xC019004C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CANNOT_ABORT_TRANSACTIONS = unchecked((int)0xC019004D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_FOUND = unchecked((int)0xC019004E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RESOURCEMANAGER_NOT_FOUND = unchecked((int)0xC019004F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_ENLISTMENT_NOT_FOUND = unchecked((int)0xC0190050);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONMANAGER_NOT_FOUND = unchecked((int)0xC0190051);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONMANAGER_NOT_ONLINE = unchecked((int)0xC0190052);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION = unchecked((int)0xC0190053);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_ROOT = unchecked((int)0xC0190054);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_OBJECT_EXPIRED = unchecked((int)0xC0190055);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION = unchecked((int)0xC0190056);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_RESPONSE_NOT_ENLISTED = unchecked((int)0xC0190057);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_RECORD_TOO_LONG = unchecked((int)0xC0190058);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_LINK_TRACKING_IN_TRANSACTION = unchecked((int)0xC0190059);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_OPERATION_NOT_SUPPORTED_IN_TRANSACTION = unchecked((int)0xC019005A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_INTEGRITY_VIOLATED = unchecked((int)0xC019005B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTIONMANAGER_IDENTITY_MISMATCH = unchecked((int)0xC019005C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT = unchecked((int)0xC019005D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_MUST_WRITETHROUGH = unchecked((int)0xC019005E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NO_SUPERIOR = unchecked((int)0xC019005F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_EXPIRED_HANDLE = unchecked((int)0xC0190060);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TRANSACTION_NOT_ENLISTED = unchecked((int)0xC0190061);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_SECTOR_INVALID = unchecked((int)0xC01A0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_SECTOR_PARITY_INVALID = unchecked((int)0xC01A0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_SECTOR_REMAPPED = unchecked((int)0xC01A0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_BLOCK_INCOMPLETE = unchecked((int)0xC01A0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_INVALID_RANGE = unchecked((int)0xC01A0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_BLOCKS_EXHAUSTED = unchecked((int)0xC01A0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_READ_CONTEXT_INVALID = unchecked((int)0xC01A0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_RESTART_INVALID = unchecked((int)0xC01A0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_BLOCK_VERSION = unchecked((int)0xC01A0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_BLOCK_INVALID = unchecked((int)0xC01A000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_READ_MODE_INVALID = unchecked((int)0xC01A000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_NO_RESTART = 0x401A000C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_METADATA_CORRUPT = unchecked((int)0xC01A000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_METADATA_INVALID = unchecked((int)0xC01A000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_METADATA_INCONSISTENT = unchecked((int)0xC01A000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_RESERVATION_INVALID = unchecked((int)0xC01A0010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CANT_DELETE = unchecked((int)0xC01A0011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CONTAINER_LIMIT_EXCEEDED = unchecked((int)0xC01A0012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_START_OF_LOG = unchecked((int)0xC01A0013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_POLICY_ALREADY_INSTALLED = unchecked((int)0xC01A0014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_POLICY_NOT_INSTALLED = unchecked((int)0xC01A0015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_POLICY_INVALID = unchecked((int)0xC01A0016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_POLICY_CONFLICT = unchecked((int)0xC01A0017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_PINNED_ARCHIVE_TAIL = unchecked((int)0xC01A0018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_RECORD_NONEXISTENT = unchecked((int)0xC01A0019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_RECORDS_RESERVED_INVALID = unchecked((int)0xC01A001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_SPACE_RESERVED_INVALID = unchecked((int)0xC01A001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_TAIL_INVALID = unchecked((int)0xC01A001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_FULL = unchecked((int)0xC01A001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_MULTIPLEXED = unchecked((int)0xC01A001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_DEDICATED = unchecked((int)0xC01A001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_ARCHIVE_NOT_IN_PROGRESS = unchecked((int)0xC01A0020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_ARCHIVE_IN_PROGRESS = unchecked((int)0xC01A0021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_EPHEMERAL = unchecked((int)0xC01A0022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_NOT_ENOUGH_CONTAINERS = unchecked((int)0xC01A0023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CLIENT_ALREADY_REGISTERED = unchecked((int)0xC01A0024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CLIENT_NOT_REGISTERED = unchecked((int)0xC01A0025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_FULL_HANDLER_IN_PROGRESS = unchecked((int)0xC01A0026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CONTAINER_READ_FAILED = unchecked((int)0xC01A0027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CONTAINER_WRITE_FAILED = unchecked((int)0xC01A0028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CONTAINER_OPEN_FAILED = unchecked((int)0xC01A0029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_CONTAINER_STATE_INVALID = unchecked((int)0xC01A002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_STATE_INVALID = unchecked((int)0xC01A002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_PINNED = unchecked((int)0xC01A002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_METADATA_FLUSH_FAILED = unchecked((int)0xC01A002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_INCONSISTENT_SECURITY = unchecked((int)0xC01A002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_APPENDED_FLUSH_FAILED = unchecked((int)0xC01A002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_LOG_PINNED_RESERVATION = unchecked((int)0xC01A0030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD = unchecked((int)0xC01B00EA);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIDEO_HUNG_DISPLAY_DRIVER_THREAD_RECOVERED = unchecked((int)0x801B00EB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIDEO_DRIVER_DEBUG_REPORT_REQUEST = 0x401B00EC;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_NO_DESCRIPTOR = unchecked((int)0xC01D0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT = unchecked((int)0xC01D0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_DESCRIPTOR_CHECKSUM = unchecked((int)0xC01D0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_STANDARD_TIMING_BLOCK = unchecked((int)0xC01D0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED = unchecked((int)0xC01D0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK = unchecked((int)0xC01D0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK = unchecked((int)0xC01D0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_NO_MORE_DESCRIPTOR_DATA = unchecked((int)0xC01D0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_DETAILED_TIMING_BLOCK = unchecked((int)0xC01D0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_MONITOR_INVALID_MANUFACTURE_DATE = unchecked((int)0xC01D000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER = unchecked((int)0xC01E0000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INSUFFICIENT_DMA_BUFFER = unchecked((int)0xC01E0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_DISPLAY_ADAPTER = unchecked((int)0xC01E0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ADAPTER_WAS_RESET = unchecked((int)0xC01E0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_DRIVER_MODEL = unchecked((int)0xC01E0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_MODE_CHANGED = unchecked((int)0xC01E0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_OCCLUDED = unchecked((int)0xC01E0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_DENIED = unchecked((int)0xC01E0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANNOTCOLORCONVERT = unchecked((int)0xC01E0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DRIVER_MISMATCH = unchecked((int)0xC01E0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PARTIAL_DATA_POPULATED = 0x401E000A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_REDIRECTION_DISABLED = unchecked((int)0xC01E000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_UNOCCLUDED = unchecked((int)0xC01E000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_WINDOWDC_NOT_AVAILABLE = unchecked((int)0xC01E000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_WINDOWLESS_PRESENT_DISABLED = unchecked((int)0xC01E000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_INVALID_WINDOW = unchecked((int)0xC01E000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PRESENT_BUFFER_NOT_BOUND = unchecked((int)0xC01E0010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VAIL_STATE_CHANGED = unchecked((int)0xC01E0011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INDIRECT_DISPLAY_ABANDON_SWAPCHAIN = unchecked((int)0xC01E0012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INDIRECT_DISPLAY_DEVICE_STOPPED = unchecked((int)0xC01E0013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_VIDEO_MEMORY = unchecked((int)0xC01E0100);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANT_LOCK_MEMORY = unchecked((int)0xC01E0101);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ALLOCATION_BUSY = unchecked((int)0xC01E0102);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TOO_MANY_REFERENCES = unchecked((int)0xC01E0103);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TRY_AGAIN_LATER = unchecked((int)0xC01E0104);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TRY_AGAIN_NOW = unchecked((int)0xC01E0105);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ALLOCATION_INVALID = unchecked((int)0xC01E0106);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE = unchecked((int)0xC01E0107);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED = unchecked((int)0xC01E0108);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION = unchecked((int)0xC01E0109);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_ALLOCATION_USAGE = unchecked((int)0xC01E0110);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION = unchecked((int)0xC01E0111);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ALLOCATION_CLOSED = unchecked((int)0xC01E0112);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_ALLOCATION_INSTANCE = unchecked((int)0xC01E0113);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_ALLOCATION_HANDLE = unchecked((int)0xC01E0114);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_WRONG_ALLOCATION_DEVICE = unchecked((int)0xC01E0115);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ALLOCATION_CONTENT_LOST = unchecked((int)0xC01E0116);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_GPU_EXCEPTION_ON_DEVICE = unchecked((int)0xC01E0200);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SKIP_ALLOCATION_PREPARATION = 0x401E0201;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY = unchecked((int)0xC01E0300);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED = unchecked((int)0xC01E0301);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED = unchecked((int)0xC01E0302);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN = unchecked((int)0xC01E0303);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE = unchecked((int)0xC01E0304);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET = unchecked((int)0xC01E0305);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED = unchecked((int)0xC01E0306);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MODE_NOT_PINNED = 0x401E0307;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_SOURCEMODESET = unchecked((int)0xC01E0308);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_TARGETMODESET = unchecked((int)0xC01E0309);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_FREQUENCY = unchecked((int)0xC01E030A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_ACTIVE_REGION = unchecked((int)0xC01E030B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_TOTAL_REGION = unchecked((int)0xC01E030C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE = unchecked((int)0xC01E0310);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE = unchecked((int)0xC01E0311);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET = unchecked((int)0xC01E0312);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY = unchecked((int)0xC01E0313);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MODE_ALREADY_IN_MODESET = unchecked((int)0xC01E0314);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET = unchecked((int)0xC01E0315);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET = unchecked((int)0xC01E0316);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SOURCE_ALREADY_IN_SET = unchecked((int)0xC01E0317);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TARGET_ALREADY_IN_SET = unchecked((int)0xC01E0318);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_PRESENT_PATH = unchecked((int)0xC01E0319);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY = unchecked((int)0xC01E031A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET = unchecked((int)0xC01E031B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE = unchecked((int)0xC01E031C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET = unchecked((int)0xC01E031D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_PREFERRED_MODE = 0x401E031E;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET = unchecked((int)0xC01E031F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_STALE_MODESET = unchecked((int)0xC01E0320);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_SOURCEMODESET = unchecked((int)0xC01E0321);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_SOURCE_MODE = unchecked((int)0xC01E0322);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN = unchecked((int)0xC01E0323);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MODE_ID_MUST_BE_UNIQUE = unchecked((int)0xC01E0324);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION = unchecked((int)0xC01E0325);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES = unchecked((int)0xC01E0326);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PATH_NOT_IN_TOPOLOGY = unchecked((int)0xC01E0327);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE = unchecked((int)0xC01E0328);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET = unchecked((int)0xC01E0329);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITORDESCRIPTORSET = unchecked((int)0xC01E032A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITORDESCRIPTOR = unchecked((int)0xC01E032B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET = unchecked((int)0xC01E032C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET = unchecked((int)0xC01E032D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE = unchecked((int)0xC01E032E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE = unchecked((int)0xC01E032F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_RESOURCES_NOT_RELATED = unchecked((int)0xC01E0330);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE = unchecked((int)0xC01E0331);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE = unchecked((int)0xC01E0332);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET = unchecked((int)0xC01E0333);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER = unchecked((int)0xC01E0334);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_VIDPNMGR = unchecked((int)0xC01E0335);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_ACTIVE_VIDPN = unchecked((int)0xC01E0336);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_STALE_VIDPN_TOPOLOGY = unchecked((int)0xC01E0337);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITOR_NOT_CONNECTED = unchecked((int)0xC01E0338);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY = unchecked((int)0xC01E0339);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE = unchecked((int)0xC01E033A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VISIBLEREGION_SIZE = unchecked((int)0xC01E033B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_STRIDE = unchecked((int)0xC01E033C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PIXELFORMAT = unchecked((int)0xC01E033D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_COLORBASIS = unchecked((int)0xC01E033E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PIXELVALUEACCESSMODE = unchecked((int)0xC01E033F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TARGET_NOT_IN_TOPOLOGY = unchecked((int)0xC01E0340);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT = unchecked((int)0xC01E0341);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE = unchecked((int)0xC01E0342);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN = unchecked((int)0xC01E0343);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL = unchecked((int)0xC01E0344);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION = unchecked((int)0xC01E0345);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED = unchecked((int)0xC01E0346);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_GAMMA_RAMP = unchecked((int)0xC01E0347);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED = unchecked((int)0xC01E0348);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED = unchecked((int)0xC01E0349);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MODE_NOT_IN_MODESET = unchecked((int)0xC01E034A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DATASET_IS_EMPTY = 0x401E034B;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET = 0x401E034C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON = unchecked((int)0xC01E034D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PATH_CONTENT_TYPE = unchecked((int)0xC01E034E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_COPYPROTECTION_TYPE = unchecked((int)0xC01E034F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS = unchecked((int)0xC01E0350);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED = 0x401E0351;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_SCANLINE_ORDERING = unchecked((int)0xC01E0352);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED = unchecked((int)0xC01E0353);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS = unchecked((int)0xC01E0354);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT = unchecked((int)0xC01E0355);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM = unchecked((int)0xC01E0356);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN = unchecked((int)0xC01E0357);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT = unchecked((int)0xC01E0358);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MAX_NUM_PATHS_REACHED = unchecked((int)0xC01E0359);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION = unchecked((int)0xC01E035A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_CLIENT_TYPE = unchecked((int)0xC01E035B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CLIENTVIDPN_NOT_SET = unchecked((int)0xC01E035C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED = unchecked((int)0xC01E0400);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED = unchecked((int)0xC01E0401);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_UNKNOWN_CHILD_STATUS = 0x401E042F;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NOT_A_LINKED_ADAPTER = unchecked((int)0xC01E0430);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_LEADLINK_NOT_ENUMERATED = unchecked((int)0xC01E0431);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CHAINLINKS_NOT_ENUMERATED = unchecked((int)0xC01E0432);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ADAPTER_CHAIN_NOT_READY = unchecked((int)0xC01E0433);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CHAINLINKS_NOT_STARTED = unchecked((int)0xC01E0434);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_CHAINLINKS_NOT_POWERED_ON = unchecked((int)0xC01E0435);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE = unchecked((int)0xC01E0436);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_LEADLINK_START_DEFERRED = 0x401E0437;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NOT_POST_DEVICE_DRIVER = unchecked((int)0xC01E0438);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_POLLING_TOO_FREQUENTLY = 0x401E0439;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_START_DEFERRED = 0x401E043A;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED = unchecked((int)0xC01E043B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DEPENDABLE_CHILD_STATUS = 0x401E043C;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_NOT_SUPPORTED = unchecked((int)0xC01E0500);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_COPP_NOT_SUPPORTED = unchecked((int)0xC01E0501);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_UAB_NOT_SUPPORTED = unchecked((int)0xC01E0502);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS = unchecked((int)0xC01E0503);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_NO_PROTECTED_OUTPUTS_EXIST = unchecked((int)0xC01E0505);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INTERNAL_ERROR = unchecked((int)0xC01E050B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INVALID_HANDLE = unchecked((int)0xC01E050C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH = unchecked((int)0xC01E050E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_SPANNING_MODE_ENABLED = unchecked((int)0xC01E050F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_THEATER_MODE_ENABLED = unchecked((int)0xC01E0510);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PVP_HFS_FAILED = unchecked((int)0xC01E0511);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INVALID_SRM = unchecked((int)0xC01E0512);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP = unchecked((int)0xC01E0513);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP = unchecked((int)0xC01E0514);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA = unchecked((int)0xC01E0515);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_HDCP_SRM_NEVER_SET = unchecked((int)0xC01E0516);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_RESOLUTION_TOO_HIGH = unchecked((int)0xC01E0517);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE = unchecked((int)0xC01E0518);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_NO_LONGER_EXISTS = unchecked((int)0xC01E051A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS = unchecked((int)0xC01E051C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST = unchecked((int)0xC01E051D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR = unchecked((int)0xC01E051E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_PROTECTED_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS = unchecked((int)0xC01E051F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED = unchecked((int)0xC01E0520);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST = unchecked((int)0xC01E0521);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_I2C_NOT_SUPPORTED = unchecked((int)0xC01E0580);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST = unchecked((int)0xC01E0581);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA = unchecked((int)0xC01E0582);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_I2C_ERROR_RECEIVING_DATA = unchecked((int)0xC01E0583);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED = unchecked((int)0xC01E0584);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_INVALID_DATA = unchecked((int)0xC01E0585);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE = unchecked((int)0xC01E0586);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_INVALID_CAPABILITIES_STRING = unchecked((int)0xC01E0587);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MCA_INTERNAL_ERROR = unchecked((int)0xC01E0588);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND = unchecked((int)0xC01E0589);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH = unchecked((int)0xC01E058A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM = unchecked((int)0xC01E058B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE = unchecked((int)0xC01E058C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MONITOR_NO_LONGER_EXISTS = unchecked((int)0xC01E058D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED = unchecked((int)0xC01E05E0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME = unchecked((int)0xC01E05E1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP = unchecked((int)0xC01E05E2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED = unchecked((int)0xC01E05E3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INVALID_POINTER = unchecked((int)0xC01E05E4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE = unchecked((int)0xC01E05E5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL = unchecked((int)0xC01E05E6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_INTERNAL_ERROR = unchecked((int)0xC01E05E7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS = unchecked((int)0xC01E05E8);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_LOCKED_VOLUME = unchecked((int)0xC0210000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_ENCRYPTED = unchecked((int)0xC0210001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_BAD_INFORMATION = unchecked((int)0xC0210002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TOO_SMALL = unchecked((int)0xC0210003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FAILED_WRONG_FS = unchecked((int)0xC0210004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_BAD_PARTITION_SIZE = unchecked((int)0xC0210005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FS_NOT_EXTENDED = unchecked((int)0xC0210006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FS_MOUNTED = unchecked((int)0xC0210007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NO_LICENSE = unchecked((int)0xC0210008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_ACTION_NOT_ALLOWED = unchecked((int)0xC0210009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_BAD_DATA = unchecked((int)0xC021000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_VOLUME_NOT_BOUND = unchecked((int)0xC021000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_DATA_VOLUME = unchecked((int)0xC021000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_CONV_READ_ERROR = unchecked((int)0xC021000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_CONV_WRITE_ERROR = unchecked((int)0xC021000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_OVERLAPPED_UPDATE = unchecked((int)0xC021000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FAILED_SECTOR_SIZE = unchecked((int)0xC0210010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FAILED_AUTHENTICATION = unchecked((int)0xC0210011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_OS_VOLUME = unchecked((int)0xC0210012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_KEYFILE_NOT_FOUND = unchecked((int)0xC0210013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_KEYFILE_INVALID = unchecked((int)0xC0210014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_KEYFILE_NO_VMK = unchecked((int)0xC0210015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TPM_DISABLED = unchecked((int)0xC0210016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TPM_SRK_AUTH_NOT_ZERO = unchecked((int)0xC0210017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TPM_INVALID_PCR = unchecked((int)0xC0210018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_TPM_NO_VMK = unchecked((int)0xC0210019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_PIN_INVALID = unchecked((int)0xC021001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_AUTH_INVALID_APPLICATION = unchecked((int)0xC021001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_AUTH_INVALID_CONFIG = unchecked((int)0xC021001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_DEBUGGER_ENABLED = unchecked((int)0xC021001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_DRY_RUN_FAILED = unchecked((int)0xC021001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_BAD_METADATA_POINTER = unchecked((int)0xC021001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_OLD_METADATA_COPY = unchecked((int)0xC0210020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_REBOOT_REQUIRED = unchecked((int)0xC0210021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_RAW_ACCESS = unchecked((int)0xC0210022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_RAW_BLOCKED = unchecked((int)0xC0210023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NO_AUTOUNLOCK_MASTER_KEY = unchecked((int)0xC0210024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_MOR_FAILED = unchecked((int)0xC0210025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NO_FEATURE_LICENSE = unchecked((int)0xC0210026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_POLICY_USER_DISABLE_RDV_NOT_ALLOWED = unchecked((int)0xC0210027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_CONV_RECOVERY_FAILED = unchecked((int)0xC0210028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_VIRTUALIZED_SPACE_TOO_BIG = unchecked((int)0xC0210029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_INVALID_DATUM_TYPE = unchecked((int)0xC021002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_VOLUME_TOO_SMALL = unchecked((int)0xC0210030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_ENH_PIN_INVALID = unchecked((int)0xC0210031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE = unchecked((int)0xC0210032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_WIPE_NOT_ALLOWED_ON_TP_STORAGE = unchecked((int)0xC0210033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_ALLOWED_ON_CSV_STACK = unchecked((int)0xC0210034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_ALLOWED_ON_CLUSTER = unchecked((int)0xC0210035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING = unchecked((int)0xC0210036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_WIPE_CANCEL_NOT_APPLICABLE = unchecked((int)0xC0210037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_EDRIVE_DRY_RUN_FAILED = unchecked((int)0xC0210038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_SECUREBOOT_DISABLED = unchecked((int)0xC0210039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_SECUREBOOT_CONFIG_CHANGE = unchecked((int)0xC021003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_DEVICE_LOCKEDOUT = unchecked((int)0xC021003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT = unchecked((int)0xC021003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_NOT_DE_VOLUME = unchecked((int)0xC021003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_PROTECTION_DISABLED = unchecked((int)0xC021003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_PROTECTION_CANNOT_BE_DISABLED = unchecked((int)0xC021003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FVE_OSV_KSR_NOT_ALLOWED = unchecked((int)0xC0210040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CALLOUT_NOT_FOUND = unchecked((int)0xC0220001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CONDITION_NOT_FOUND = unchecked((int)0xC0220002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_FILTER_NOT_FOUND = unchecked((int)0xC0220003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_LAYER_NOT_FOUND = unchecked((int)0xC0220004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_PROVIDER_NOT_FOUND = unchecked((int)0xC0220005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_PROVIDER_CONTEXT_NOT_FOUND = unchecked((int)0xC0220006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_SUBLAYER_NOT_FOUND = unchecked((int)0xC0220007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NOT_FOUND = unchecked((int)0xC0220008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_ALREADY_EXISTS = unchecked((int)0xC0220009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_IN_USE = unchecked((int)0xC022000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_DYNAMIC_SESSION_IN_PROGRESS = unchecked((int)0xC022000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_WRONG_SESSION = unchecked((int)0xC022000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NO_TXN_IN_PROGRESS = unchecked((int)0xC022000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TXN_IN_PROGRESS = unchecked((int)0xC022000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TXN_ABORTED = unchecked((int)0xC022000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_SESSION_ABORTED = unchecked((int)0xC0220010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_TXN = unchecked((int)0xC0220011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TIMEOUT = unchecked((int)0xC0220012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NET_EVENTS_DISABLED = unchecked((int)0xC0220013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_LAYER = unchecked((int)0xC0220014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_KM_CLIENTS_ONLY = unchecked((int)0xC0220015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_LIFETIME_MISMATCH = unchecked((int)0xC0220016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_BUILTIN_OBJECT = unchecked((int)0xC0220017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TOO_MANY_CALLOUTS = unchecked((int)0xC0220018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NOTIFICATION_DROPPED = unchecked((int)0xC0220019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TRAFFIC_MISMATCH = unchecked((int)0xC022001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_SA_STATE = unchecked((int)0xC022001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NULL_POINTER = unchecked((int)0xC022001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_ENUMERATOR = unchecked((int)0xC022001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_FLAGS = unchecked((int)0xC022001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_NET_MASK = unchecked((int)0xC022001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_RANGE = unchecked((int)0xC0220020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_INTERVAL = unchecked((int)0xC0220021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_ZERO_LENGTH_ARRAY = unchecked((int)0xC0220022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NULL_DISPLAY_NAME = unchecked((int)0xC0220023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_ACTION_TYPE = unchecked((int)0xC0220024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_WEIGHT = unchecked((int)0xC0220025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_MATCH_TYPE_MISMATCH = unchecked((int)0xC0220026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TYPE_MISMATCH = unchecked((int)0xC0220027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_OUT_OF_BOUNDS = unchecked((int)0xC0220028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_RESERVED = unchecked((int)0xC0220029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_DUPLICATE_CONDITION = unchecked((int)0xC022002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_DUPLICATE_KEYMOD = unchecked((int)0xC022002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_ACTION_INCOMPATIBLE_WITH_LAYER = unchecked((int)0xC022002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_ACTION_INCOMPATIBLE_WITH_SUBLAYER = unchecked((int)0xC022002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_LAYER = unchecked((int)0xC022002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CONTEXT_INCOMPATIBLE_WITH_CALLOUT = unchecked((int)0xC022002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_AUTH_METHOD = unchecked((int)0xC0220030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_DH_GROUP = unchecked((int)0xC0220031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_EM_NOT_SUPPORTED = unchecked((int)0xC0220032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_NEVER_MATCH = unchecked((int)0xC0220033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_PROVIDER_CONTEXT_MISMATCH = unchecked((int)0xC0220034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_PARAMETER = unchecked((int)0xC0220035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TOO_MANY_SUBLAYERS = unchecked((int)0xC0220036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CALLOUT_NOTIFICATION_FAILED = unchecked((int)0xC0220037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_AUTH_TRANSFORM = unchecked((int)0xC0220038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_CIPHER_TRANSFORM = unchecked((int)0xC0220039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INCOMPATIBLE_CIPHER_TRANSFORM = unchecked((int)0xC022003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_TRANSFORM_COMBINATION = unchecked((int)0xC022003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_DUPLICATE_AUTH_METHOD = unchecked((int)0xC022003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_TUNNEL_ENDPOINT = unchecked((int)0xC022003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_L2_DRIVER_NOT_READY = unchecked((int)0xC022003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_KEY_DICTATOR_ALREADY_REGISTERED = unchecked((int)0xC022003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_KEY_DICTATION_INVALID_KEYING_MATERIAL = unchecked((int)0xC0220040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CONNECTIONS_DISABLED = unchecked((int)0xC0220041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INVALID_DNS_NAME = unchecked((int)0xC0220042);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_STILL_ON = unchecked((int)0xC0220043);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_IKEEXT_NOT_RUNNING = unchecked((int)0xC0220044);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_TCPIP_NOT_READY = unchecked((int)0xC0220100);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INJECT_HANDLE_CLOSING = unchecked((int)0xC0220101);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_INJECT_HANDLE_STALE = unchecked((int)0xC0220102);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_CANNOT_PEND = unchecked((int)0xC0220103);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_FWP_DROP_NOICMP = unchecked((int)0xC0220104);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_CLOSING = unchecked((int)0xC0230002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_BAD_VERSION = unchecked((int)0xC0230004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_BAD_CHARACTERISTICS = unchecked((int)0xC0230005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_ADAPTER_NOT_FOUND = unchecked((int)0xC0230006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_OPEN_FAILED = unchecked((int)0xC0230007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DEVICE_FAILED = unchecked((int)0xC0230008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_MULTICAST_FULL = unchecked((int)0xC0230009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_MULTICAST_EXISTS = unchecked((int)0xC023000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_MULTICAST_NOT_FOUND = unchecked((int)0xC023000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_REQUEST_ABORTED = unchecked((int)0xC023000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_RESET_IN_PROGRESS = unchecked((int)0xC023000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_NOT_SUPPORTED = unchecked((int)0xC02300BB);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_PACKET = unchecked((int)0xC023000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_ADAPTER_NOT_READY = unchecked((int)0xC0230011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_LENGTH = unchecked((int)0xC0230014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_DATA = unchecked((int)0xC0230015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_BUFFER_TOO_SHORT = unchecked((int)0xC0230016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_OID = unchecked((int)0xC0230017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_ADAPTER_REMOVED = unchecked((int)0xC0230018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_UNSUPPORTED_MEDIA = unchecked((int)0xC0230019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_GROUP_ADDRESS_IN_USE = unchecked((int)0xC023001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_FILE_NOT_FOUND = unchecked((int)0xC023001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_ERROR_READING_FILE = unchecked((int)0xC023001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_ALREADY_MAPPED = unchecked((int)0xC023001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_RESOURCE_CONFLICT = unchecked((int)0xC023001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_MEDIA_DISCONNECTED = unchecked((int)0xC023001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_ADDRESS = unchecked((int)0xC0230022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_DEVICE_REQUEST = unchecked((int)0xC0230010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_PAUSED = unchecked((int)0xC023002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INTERFACE_NOT_FOUND = unchecked((int)0xC023002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_UNSUPPORTED_REVISION = unchecked((int)0xC023002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_PORT = unchecked((int)0xC023002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INVALID_PORT_STATE = unchecked((int)0xC023002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_LOW_POWER_STATE = unchecked((int)0xC023002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_REINIT_REQUIRED = unchecked((int)0xC0230030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_NO_QUEUES = unchecked((int)0xC0230031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_AUTO_CONFIG_ENABLED = unchecked((int)0xC0232000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_MEDIA_IN_USE = unchecked((int)0xC0232001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_POWER_STATE_INVALID = unchecked((int)0xC0232002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_PM_WOL_PATTERN_LIST_FULL = unchecked((int)0xC0232003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL = unchecked((int)0xC0232004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_AP_CHANNEL_CURRENTLY_NOT_AVAILABLE = unchecked((int)0xC0232005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_AP_BAND_CURRENTLY_NOT_AVAILABLE = unchecked((int)0xC0232006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_AP_CHANNEL_NOT_ALLOWED = unchecked((int)0xC0232007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_DOT11_AP_BAND_NOT_ALLOWED = unchecked((int)0xC0232008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_INDICATION_REQUIRED = 0x40230001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_OFFLOAD_POLICY = unchecked((int)0xC023100F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_OFFLOAD_CONNECTION_REJECTED = unchecked((int)0xC0231012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NDIS_OFFLOAD_PATH_REJECTED = unchecked((int)0xC0231013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_ERROR_MASK = unchecked((int)0xC0290000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUTHFAIL = unchecked((int)0xC0290001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BADINDEX = unchecked((int)0xC0290002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_PARAMETER = unchecked((int)0xC0290003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUDITFAILURE = unchecked((int)0xC0290004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_CLEAR_DISABLED = unchecked((int)0xC0290005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DEACTIVATED = unchecked((int)0xC0290006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DISABLED = unchecked((int)0xC0290007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DISABLED_CMD = unchecked((int)0xC0290008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_FAIL = unchecked((int)0xC0290009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_ORDINAL = unchecked((int)0xC029000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INSTALL_DISABLED = unchecked((int)0xC029000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_KEYHANDLE = unchecked((int)0xC029000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_KEYNOTFOUND = unchecked((int)0xC029000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INAPPROPRIATE_ENC = unchecked((int)0xC029000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MIGRATEFAIL = unchecked((int)0xC029000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_PCR_INFO = unchecked((int)0xC0290010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOSPACE = unchecked((int)0xC0290011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOSRK = unchecked((int)0xC0290012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOTSEALED_BLOB = unchecked((int)0xC0290013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_OWNER_SET = unchecked((int)0xC0290014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_RESOURCES = unchecked((int)0xC0290015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_SHORTRANDOM = unchecked((int)0xC0290016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_SIZE = unchecked((int)0xC0290017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_WRONGPCRVAL = unchecked((int)0xC0290018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_PARAM_SIZE = unchecked((int)0xC0290019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_SHA_THREAD = unchecked((int)0xC029001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_SHA_ERROR = unchecked((int)0xC029001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_FAILEDSELFTEST = unchecked((int)0xC029001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUTH2FAIL = unchecked((int)0xC029001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BADTAG = unchecked((int)0xC029001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_IOERROR = unchecked((int)0xC029001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_ENCRYPT_ERROR = unchecked((int)0xC0290020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DECRYPT_ERROR = unchecked((int)0xC0290021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_AUTHHANDLE = unchecked((int)0xC0290022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NO_ENDORSEMENT = unchecked((int)0xC0290023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_KEYUSAGE = unchecked((int)0xC0290024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_WRONG_ENTITYTYPE = unchecked((int)0xC0290025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_POSTINIT = unchecked((int)0xC0290026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INAPPROPRIATE_SIG = unchecked((int)0xC0290027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_KEY_PROPERTY = unchecked((int)0xC0290028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_MIGRATION = unchecked((int)0xC0290029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_SCHEME = unchecked((int)0xC029002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_DATASIZE = unchecked((int)0xC029002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_MODE = unchecked((int)0xC029002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_PRESENCE = unchecked((int)0xC029002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_VERSION = unchecked((int)0xC029002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NO_WRAP_TRANSPORT = unchecked((int)0xC029002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUDITFAIL_UNSUCCESSFUL = unchecked((int)0xC0290030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUDITFAIL_SUCCESSFUL = unchecked((int)0xC0290031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOTRESETABLE = unchecked((int)0xC0290032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOTLOCAL = unchecked((int)0xC0290033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_TYPE = unchecked((int)0xC0290034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_RESOURCE = unchecked((int)0xC0290035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOTFIPS = unchecked((int)0xC0290036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_FAMILY = unchecked((int)0xC0290037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NO_NV_PERMISSION = unchecked((int)0xC0290038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_REQUIRES_SIGN = unchecked((int)0xC0290039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_KEY_NOTSUPPORTED = unchecked((int)0xC029003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AUTH_CONFLICT = unchecked((int)0xC029003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_AREA_LOCKED = unchecked((int)0xC029003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_LOCALITY = unchecked((int)0xC029003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_READ_ONLY = unchecked((int)0xC029003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_PER_NOWRITE = unchecked((int)0xC029003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_FAMILYCOUNT = unchecked((int)0xC0290040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_WRITE_LOCKED = unchecked((int)0xC0290041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_ATTRIBUTES = unchecked((int)0xC0290042);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_STRUCTURE = unchecked((int)0xC0290043);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_KEY_OWNER_CONTROL = unchecked((int)0xC0290044);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_COUNTER = unchecked((int)0xC0290045);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOT_FULLWRITE = unchecked((int)0xC0290046);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_CONTEXT_GAP = unchecked((int)0xC0290047);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MAXNVWRITES = unchecked((int)0xC0290048);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOOPERATOR = unchecked((int)0xC0290049);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_RESOURCEMISSING = unchecked((int)0xC029004A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DELEGATE_LOCK = unchecked((int)0xC029004B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DELEGATE_FAMILY = unchecked((int)0xC029004C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DELEGATE_ADMIN = unchecked((int)0xC029004D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_TRANSPORT_NOTEXCLUSIVE = unchecked((int)0xC029004E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_OWNER_CONTROL = unchecked((int)0xC029004F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_RESOURCES = unchecked((int)0xC0290050);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_INPUT_DATA0 = unchecked((int)0xC0290051);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_INPUT_DATA1 = unchecked((int)0xC0290052);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_ISSUER_SETTINGS = unchecked((int)0xC0290053);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_TPM_SETTINGS = unchecked((int)0xC0290054);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_STAGE = unchecked((int)0xC0290055);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_ISSUER_VALIDITY = unchecked((int)0xC0290056);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DAA_WRONG_W = unchecked((int)0xC0290057);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_HANDLE = unchecked((int)0xC0290058);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_DELEGATE = unchecked((int)0xC0290059);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BADCONTEXT = unchecked((int)0xC029005A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_TOOMANYCONTEXTS = unchecked((int)0xC029005B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MA_TICKET_SIGNATURE = unchecked((int)0xC029005C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MA_DESTINATION = unchecked((int)0xC029005D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MA_SOURCE = unchecked((int)0xC029005E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_MA_AUTHORITY = unchecked((int)0xC029005F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_PERMANENTEK = unchecked((int)0xC0290061);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_BAD_SIGNATURE = unchecked((int)0xC0290062);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOCONTEXTSPACE = unchecked((int)0xC0290063);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_ASYMMETRIC = unchecked((int)0xC0290081);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_ATTRIBUTES = unchecked((int)0xC0290082);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_HASH = unchecked((int)0xC0290083);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_VALUE = unchecked((int)0xC0290084);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_HIERARCHY = unchecked((int)0xC0290085);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_KEY_SIZE = unchecked((int)0xC0290087);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_MGF = unchecked((int)0xC0290088);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_MODE = unchecked((int)0xC0290089);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_TYPE = unchecked((int)0xC029008A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_HANDLE = unchecked((int)0xC029008B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_KDF = unchecked((int)0xC029008C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_RANGE = unchecked((int)0xC029008D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTH_FAIL = unchecked((int)0xC029008E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NONCE = unchecked((int)0xC029008F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_PP = unchecked((int)0xC0290090);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SCHEME = unchecked((int)0xC0290092);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SIZE = unchecked((int)0xC0290095);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SYMMETRIC = unchecked((int)0xC0290096);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_TAG = unchecked((int)0xC0290097);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SELECTOR = unchecked((int)0xC0290098);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_INSUFFICIENT = unchecked((int)0xC029009A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SIGNATURE = unchecked((int)0xC029009B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_KEY = unchecked((int)0xC029009C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_POLICY_FAIL = unchecked((int)0xC029009D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_INTEGRITY = unchecked((int)0xC029009F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_TICKET = unchecked((int)0xC02900A0);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_RESERVED_BITS = unchecked((int)0xC02900A1);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_BAD_AUTH = unchecked((int)0xC02900A2);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_EXPIRED = unchecked((int)0xC02900A3);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_POLICY_CC = unchecked((int)0xC02900A4);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_BINDING = unchecked((int)0xC02900A5);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_CURVE = unchecked((int)0xC02900A6);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_ECC_POINT = unchecked((int)0xC02900A7);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_INITIALIZE = unchecked((int)0xC0290100);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_FAILURE = unchecked((int)0xC0290101);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SEQUENCE = unchecked((int)0xC0290103);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_PRIVATE = unchecked((int)0xC029010B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_HMAC = unchecked((int)0xC0290119);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_DISABLED = unchecked((int)0xC0290120);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_EXCLUSIVE = unchecked((int)0xC0290121);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_ECC_CURVE = unchecked((int)0xC0290123);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTH_TYPE = unchecked((int)0xC0290124);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTH_MISSING = unchecked((int)0xC0290125);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_POLICY = unchecked((int)0xC0290126);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_PCR = unchecked((int)0xC0290127);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_PCR_CHANGED = unchecked((int)0xC0290128);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_UPGRADE = unchecked((int)0xC029012D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_TOO_MANY_CONTEXTS = unchecked((int)0xC029012E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTH_UNAVAILABLE = unchecked((int)0xC029012F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_REBOOT = unchecked((int)0xC0290130);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_UNBALANCED = unchecked((int)0xC0290131);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_COMMAND_SIZE = unchecked((int)0xC0290142);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_COMMAND_CODE = unchecked((int)0xC0290143);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTHSIZE = unchecked((int)0xC0290144);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_AUTH_CONTEXT = unchecked((int)0xC0290145);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_RANGE = unchecked((int)0xC0290146);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_SIZE = unchecked((int)0xC0290147);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_LOCKED = unchecked((int)0xC0290148);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_AUTHORIZATION = unchecked((int)0xC0290149);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_UNINITIALIZED = unchecked((int)0xC029014A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_SPACE = unchecked((int)0xC029014B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NV_DEFINED = unchecked((int)0xC029014C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_BAD_CONTEXT = unchecked((int)0xC0290150);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_CPHASH = unchecked((int)0xC0290151);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_PARENT = unchecked((int)0xC0290152);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NEEDS_TEST = unchecked((int)0xC0290153);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_NO_RESULT = unchecked((int)0xC0290154);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_20_E_SENSITIVE = unchecked((int)0xC0290155);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_COMMAND_BLOCKED = unchecked((int)0xC0290400);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INVALID_HANDLE = unchecked((int)0xC0290401);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DUPLICATE_VHANDLE = unchecked((int)0xC0290402);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_EMBEDDED_COMMAND_BLOCKED = unchecked((int)0xC0290403);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_EMBEDDED_COMMAND_UNSUPPORTED = unchecked((int)0xC0290404);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_RETRY = unchecked((int)0xC0290800);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NEEDS_SELFTEST = unchecked((int)0xC0290801);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DOING_SELFTEST = unchecked((int)0xC0290802);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_DEFEND_LOCK_RUNNING = unchecked((int)0xC0290803);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_COMMAND_CANCELED = unchecked((int)0xC0291001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_TOO_MANY_CONTEXTS = unchecked((int)0xC0291002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_NOT_FOUND = unchecked((int)0xC0291003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_ACCESS_DENIED = unchecked((int)0xC0291004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_INSUFFICIENT_BUFFER = unchecked((int)0xC0291005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_PPI_FUNCTION_UNSUPPORTED = unchecked((int)0xC0291006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_ERROR_MASK = unchecked((int)0xC0292000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_DEVICE_NOT_READY = unchecked((int)0xC0292001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_INVALID_HANDLE = unchecked((int)0xC0292002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_INVALID_PARAMETER = unchecked((int)0xC0292003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_FLAG_NOT_SUPPORTED = unchecked((int)0xC0292004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_NOT_SUPPORTED = unchecked((int)0xC0292005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_BUFFER_TOO_SMALL = unchecked((int)0xC0292006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_INTERNAL_ERROR = unchecked((int)0xC0292007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_AUTHENTICATION_FAILED = unchecked((int)0xC0292008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_AUTHENTICATION_IGNORED = unchecked((int)0xC0292009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_POLICY_NOT_FOUND = unchecked((int)0xC029200A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_PROFILE_NOT_FOUND = unchecked((int)0xC029200B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_VALIDATION_FAILED = unchecked((int)0xC029200C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_DEVICE_NOT_FOUND = unchecked((int)0xC029200D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_WRONG_PARENT = unchecked((int)0xC029200E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_NOT_LOADED = unchecked((int)0xC029200F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_NO_KEY_CERTIFICATION = unchecked((int)0xC0292010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_NOT_FINALIZED = unchecked((int)0xC0292011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_ATTESTATION_CHALLENGE_NOT_SET = unchecked((int)0xC0292012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_NOT_PCR_BOUND = unchecked((int)0xC0292013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_ALREADY_FINALIZED = unchecked((int)0xC0292014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_USAGE_POLICY_NOT_SUPPORTED = unchecked((int)0xC0292015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_USAGE_POLICY_INVALID = unchecked((int)0xC0292016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_SOFT_KEY_ERROR = unchecked((int)0xC0292017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_NOT_AUTHENTICATED = unchecked((int)0xC0292018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_NOT_AIK = unchecked((int)0xC0292019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_NOT_SIGNING_KEY = unchecked((int)0xC029201A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_LOCKED_OUT = unchecked((int)0xC029201B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_CLAIM_TYPE_NOT_SUPPORTED = unchecked((int)0xC029201C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_TPM_VERSION_NOT_SUPPORTED = unchecked((int)0xC029201D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_BUFFER_LENGTH_MISMATCH = unchecked((int)0xC029201E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_IFX_RSA_KEY_CREATION_BLOCKED = unchecked((int)0xC029201F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_TICKET_MISSING = unchecked((int)0xC0292020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_RAW_POLICY_NOT_SUPPORTED = unchecked((int)0xC0292021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_KEY_HANDLE_INVALIDATED = unchecked((int)0xC0292022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PCP_UNSUPPORTED_PSS_SALT = 0x40292023;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_CONTEXT_CONTINUE = 0x00293000;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_CONTEXT_COMPLETE = 0x00293001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_NO_RESULT = unchecked((int)0xC0293002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_PCR_READ_INCOMPLETE = unchecked((int)0xC0293003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_INVALID_CONTEXT = unchecked((int)0xC0293004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RTPM_UNSUPPORTED_CMD = unchecked((int)0xC0293005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_TPM_ZERO_EXHAUST_ENABLED = unchecked((int)0xC0294000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_HYPERCALL_CODE = unchecked((int)0xC0350002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_HYPERCALL_INPUT = unchecked((int)0xC0350003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_ALIGNMENT = unchecked((int)0xC0350004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_PARAMETER = unchecked((int)0xC0350005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_ACCESS_DENIED = unchecked((int)0xC0350006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_PARTITION_STATE = unchecked((int)0xC0350007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_OPERATION_DENIED = unchecked((int)0xC0350008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_UNKNOWN_PROPERTY = unchecked((int)0xC0350009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_PROPERTY_VALUE_OUT_OF_RANGE = unchecked((int)0xC035000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_MEMORY = unchecked((int)0xC035000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_PARTITION_TOO_DEEP = unchecked((int)0xC035000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_PARTITION_ID = unchecked((int)0xC035000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_VP_INDEX = unchecked((int)0xC035000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_PORT_ID = unchecked((int)0xC0350011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_CONNECTION_ID = unchecked((int)0xC0350012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_BUFFERS = unchecked((int)0xC0350013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NOT_ACKNOWLEDGED = unchecked((int)0xC0350014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_VP_STATE = unchecked((int)0xC0350015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_ACKNOWLEDGED = unchecked((int)0xC0350016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_SAVE_RESTORE_STATE = unchecked((int)0xC0350017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_SYNIC_STATE = unchecked((int)0xC0350018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_OBJECT_IN_USE = unchecked((int)0xC0350019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_PROXIMITY_DOMAIN_INFO = unchecked((int)0xC035001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NO_DATA = unchecked((int)0xC035001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INACTIVE = unchecked((int)0xC035001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NO_RESOURCES = unchecked((int)0xC035001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_FEATURE_UNAVAILABLE = unchecked((int)0xC035001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_BUFFER = unchecked((int)0xC0350033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_DEVICE_DOMAINS = unchecked((int)0xC0350038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_CPUID_FEATURE_VALIDATION_ERROR = unchecked((int)0xC035003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_CPUID_XSAVE_FEATURE_VALIDATION_ERROR = unchecked((int)0xC035003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_PROCESSOR_STARTUP_TIMEOUT = unchecked((int)0xC035003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_SMX_ENABLED = unchecked((int)0xC035003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_LP_INDEX = unchecked((int)0xC0350041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_REGISTER_VALUE = unchecked((int)0xC0350050);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_VTL_STATE = unchecked((int)0xC0350051);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NX_NOT_DETECTED = unchecked((int)0xC0350055);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_DEVICE_ID = unchecked((int)0xC0350057);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_DEVICE_STATE = unchecked((int)0xC0350058);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_PENDING_PAGE_REQUESTS = 0x00350059;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_PAGE_REQUEST_INVALID = unchecked((int)0xC0350060);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_CPU_GROUP_ID = unchecked((int)0xC035006F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INVALID_CPU_GROUP_STATE = unchecked((int)0xC0350070);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_OPERATION_FAILED = unchecked((int)0xC0350071);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NOT_ALLOWED_WITH_NESTED_VIRT_ACTIVE = unchecked((int)0xC0350072);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_ROOT_MEMORY = unchecked((int)0xC0350073);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_EVENT_BUFFER_ALREADY_FREED = unchecked((int)0xC0350074);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_INSUFFICIENT_CONTIGUOUS_MEMORY = unchecked((int)0xC0350075);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HV_NOT_PRESENT = unchecked((int)0xC0351000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_DUPLICATE_HANDLER = unchecked((int)0xC0370001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_TOO_MANY_HANDLERS = unchecked((int)0xC0370002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_QUEUE_FULL = unchecked((int)0xC0370003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_HANDLER_NOT_PRESENT = unchecked((int)0xC0370004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_OBJECT_NAME = unchecked((int)0xC0370005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_PARTITION_NAME_TOO_LONG = unchecked((int)0xC0370006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MESSAGE_QUEUE_NAME_TOO_LONG = unchecked((int)0xC0370007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_PARTITION_ALREADY_EXISTS = unchecked((int)0xC0370008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_PARTITION_DOES_NOT_EXIST = unchecked((int)0xC0370009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_PARTITION_NAME_NOT_FOUND = unchecked((int)0xC037000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MESSAGE_QUEUE_ALREADY_EXISTS = unchecked((int)0xC037000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT = unchecked((int)0xC037000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MB_STILL_REFERENCED = unchecked((int)0xC037000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_CHILD_GPA_PAGE_SET_CORRUPTED = unchecked((int)0xC037000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_NUMA_SETTINGS = unchecked((int)0xC037000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_NUMA_NODE_INDEX = unchecked((int)0xC0370010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED = unchecked((int)0xC0370011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_MEMORY_BLOCK_HANDLE = unchecked((int)0xC0370012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_PAGE_RANGE_OVERFLOW = unchecked((int)0xC0370013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_MESSAGE_QUEUE_HANDLE = unchecked((int)0xC0370014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_GPA_RANGE_HANDLE = unchecked((int)0xC0370015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE = unchecked((int)0xC0370016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED = unchecked((int)0xC0370017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_PPM_HANDLE = unchecked((int)0xC0370018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MBPS_ARE_LOCKED = unchecked((int)0xC0370019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MESSAGE_QUEUE_CLOSED = unchecked((int)0xC037001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED = unchecked((int)0xC037001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_STOP_PENDING = unchecked((int)0xC037001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_PROCESSOR_STATE = unchecked((int)0xC037001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT = unchecked((int)0xC037001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_KM_INTERFACE_ALREADY_INITIALIZED = unchecked((int)0xC037001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MB_PROPERTY_ALREADY_SET_RESET = unchecked((int)0xC0370020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MMIO_RANGE_DESTROYED = unchecked((int)0xC0370021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_INVALID_CHILD_GPA_PAGE_SET = unchecked((int)0xC0370022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_RESERVE_PAGE_SET_IS_BEING_USED = unchecked((int)0xC0370023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_RESERVE_PAGE_SET_TOO_SMALL = unchecked((int)0xC0370024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE = unchecked((int)0xC0370025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_MBP_COUNT_EXCEEDED_LIMIT = unchecked((int)0xC0370026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_SAVED_STATE_CORRUPT = unchecked((int)0xC0370027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_SAVED_STATE_UNRECOGNIZED_ITEM = unchecked((int)0xC0370028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_SAVED_STATE_INCOMPATIBLE = unchecked((int)0xC0370029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_VTL_ACCESS_DENIED = unchecked((int)0xC037002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED = unchecked((int)0x80370001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_BAD_SPI = unchecked((int)0xC0360001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_SA_LIFETIME_EXPIRED = unchecked((int)0xC0360002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_WRONG_SA = unchecked((int)0xC0360003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_REPLAY_CHECK_FAILED = unchecked((int)0xC0360004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_INVALID_PACKET = unchecked((int)0xC0360005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_INTEGRITY_CHECK_FAILED = unchecked((int)0xC0360006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_CLEAR_TEXT_DROP = unchecked((int)0xC0360007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_AUTH_FIREWALL_DROP = unchecked((int)0xC0360008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_THROTTLE_DROP = unchecked((int)0xC0360009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_BLOCK = unchecked((int)0xC0368000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_RECEIVED_MULTICAST = unchecked((int)0xC0368001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_INVALID_PACKET = unchecked((int)0xC0368002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_STATE_LOOKUP_FAILED = unchecked((int)0xC0368003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_MAX_ENTRIES = unchecked((int)0xC0368004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_KEYMOD_NOT_ALLOWED = unchecked((int)0xC0368005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES = unchecked((int)0xC0368006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_INCOMPLETE_REGENERATION = unchecked((int)0x80380001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_INCOMPLETE_DISK_MIGRATION = unchecked((int)0x80380002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DATABASE_FULL = unchecked((int)0xC0380001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_CONFIGURATION_CORRUPTED = unchecked((int)0xC0380002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC = unchecked((int)0xC0380003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_CONFIG_UPDATE_FAILED = unchecked((int)0xC0380004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME = unchecked((int)0xC0380005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_DUPLICATE = unchecked((int)0xC0380006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_DYNAMIC = unchecked((int)0xC0380007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_ID_INVALID = unchecked((int)0xC0380008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_INVALID = unchecked((int)0xC0380009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAST_VOTER = unchecked((int)0xC038000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_INVALID = unchecked((int)0xC038000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS = unchecked((int)0xC038000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED = unchecked((int)0xC038000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL = unchecked((int)0xC038000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS = unchecked((int)0xC038000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS = unchecked((int)0xC0380010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_MISSING = unchecked((int)0xC0380011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_NOT_EMPTY = unchecked((int)0xC0380012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_NOT_ENOUGH_SPACE = unchecked((int)0xC0380013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_REVECTORING_FAILED = unchecked((int)0xC0380014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_SECTOR_SIZE_INVALID = unchecked((int)0xC0380015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_SET_NOT_CONTAINED = unchecked((int)0xC0380016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS = unchecked((int)0xC0380017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES = unchecked((int)0xC0380018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED = unchecked((int)0xC0380019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_ALREADY_USED = unchecked((int)0xC038001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_NOT_CONTIGUOUS = unchecked((int)0xC038001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION = unchecked((int)0xC038001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED = unchecked((int)0xC038001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION = unchecked((int)0xC038001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH = unchecked((int)0xC038001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED = unchecked((int)0xC0380020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_INTERLEAVE_LENGTH_INVALID = unchecked((int)0xC0380021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MAXIMUM_REGISTERED_USERS = unchecked((int)0xC0380022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_IN_SYNC = unchecked((int)0xC0380023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_INDEX_DUPLICATE = unchecked((int)0xC0380024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_INDEX_INVALID = unchecked((int)0xC0380025);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_MISSING = unchecked((int)0xC0380026);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_NOT_DETACHED = unchecked((int)0xC0380027);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MEMBER_REGENERATING = unchecked((int)0xC0380028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_ALL_DISKS_FAILED = unchecked((int)0xC0380029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NO_REGISTERED_USERS = unchecked((int)0xC038002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NO_SUCH_USER = unchecked((int)0xC038002B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NOTIFICATION_RESET = unchecked((int)0xC038002C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_MEMBERS_INVALID = unchecked((int)0xC038002D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_PLEXES_INVALID = unchecked((int)0xC038002E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_DUPLICATE = unchecked((int)0xC038002F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_ID_INVALID = unchecked((int)0xC0380030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_INVALID = unchecked((int)0xC0380031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_NAME_INVALID = unchecked((int)0xC0380032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_OFFLINE = unchecked((int)0xC0380033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_HAS_QUORUM = unchecked((int)0xC0380034);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_WITHOUT_QUORUM = unchecked((int)0xC0380035);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PARTITION_STYLE_INVALID = unchecked((int)0xC0380036);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PARTITION_UPDATE_FAILED = unchecked((int)0xC0380037);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_IN_SYNC = unchecked((int)0xC0380038);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_INDEX_DUPLICATE = unchecked((int)0xC0380039);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_INDEX_INVALID = unchecked((int)0xC038003A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_LAST_ACTIVE = unchecked((int)0xC038003B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_MISSING = unchecked((int)0xC038003C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_REGENERATING = unchecked((int)0xC038003D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_TYPE_INVALID = unchecked((int)0xC038003E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_NOT_RAID5 = unchecked((int)0xC038003F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_NOT_SIMPLE = unchecked((int)0xC0380040);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_STRUCTURE_SIZE_INVALID = unchecked((int)0xC0380041);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS = unchecked((int)0xC0380042);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_TRANSACTION_IN_PROGRESS = unchecked((int)0xC0380043);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE = unchecked((int)0xC0380044);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_CONTAINS_MISSING_DISK = unchecked((int)0xC0380045);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_ID_INVALID = unchecked((int)0xC0380046);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_LENGTH_INVALID = unchecked((int)0xC0380047);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE = unchecked((int)0xC0380048);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_NOT_MIRRORED = unchecked((int)0xC0380049);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_NOT_RETAINED = unchecked((int)0xC038004A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_OFFLINE = unchecked((int)0xC038004B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_RETAINED = unchecked((int)0xC038004C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_EXTENTS_INVALID = unchecked((int)0xC038004D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_DIFFERENT_SECTOR_SIZE = unchecked((int)0xC038004E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_BAD_BOOT_DISK = unchecked((int)0xC038004F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_CONFIG_OFFLINE = unchecked((int)0xC0380050);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_CONFIG_ONLINE = unchecked((int)0xC0380051);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NOT_PRIMARY_PACK = unchecked((int)0xC0380052);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PACK_LOG_UPDATE_FAILED = unchecked((int)0xC0380053);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID = unchecked((int)0xC0380054);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID = unchecked((int)0xC0380055);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_VOLUME_MIRRORED = unchecked((int)0xC0380056);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PLEX_NOT_SIMPLE_SPANNED = unchecked((int)0xC0380057);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NO_VALID_LOG_COPIES = unchecked((int)0xC0380058);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_PRIMARY_PACK_PRESENT = unchecked((int)0xC0380059);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_NUMBER_OF_DISKS_INVALID = unchecked((int)0xC038005A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_MIRROR_NOT_SUPPORTED = unchecked((int)0xC038005B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLMGR_RAID5_NOT_SUPPORTED = unchecked((int)0xC038005C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BCD_NOT_ALL_ENTRIES_IMPORTED = unchecked((int)0x80390001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BCD_TOO_MANY_ELEMENTS = unchecked((int)0xC0390002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED = unchecked((int)0x80390003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_DRIVE_FOOTER_MISSING = unchecked((int)0xC03A0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH = unchecked((int)0xC03A0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_DRIVE_FOOTER_CORRUPT = unchecked((int)0xC03A0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_FORMAT_UNKNOWN = unchecked((int)0xC03A0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_FORMAT_UNSUPPORTED_VERSION = unchecked((int)0xC03A0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH = unchecked((int)0xC03A0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION = unchecked((int)0xC03A0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_SPARSE_HEADER_CORRUPT = unchecked((int)0xC03A0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_BLOCK_ALLOCATION_FAILURE = unchecked((int)0xC03A0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT = unchecked((int)0xC03A000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_BLOCK_SIZE = unchecked((int)0xC03A000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_BITMAP_MISMATCH = unchecked((int)0xC03A000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_PARENT_VHD_NOT_FOUND = unchecked((int)0xC03A000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_CHILD_PARENT_ID_MISMATCH = unchecked((int)0xC03A000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH = unchecked((int)0xC03A000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_METADATA_READ_FAILURE = unchecked((int)0xC03A0010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_METADATA_WRITE_FAILURE = unchecked((int)0xC03A0011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_SIZE = unchecked((int)0xC03A0012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_FILE_SIZE = unchecked((int)0xC03A0013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTDISK_PROVIDER_NOT_FOUND = unchecked((int)0xC03A0014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTDISK_NOT_VIRTUAL_DISK = unchecked((int)0xC03A0015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_PARENT_VHD_ACCESS_DENIED = unchecked((int)0xC03A0016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_CHILD_PARENT_SIZE_MISMATCH = unchecked((int)0xC03A0017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED = unchecked((int)0xC03A0018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT = unchecked((int)0xC03A0019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTUAL_DISK_LIMITATION = unchecked((int)0xC03A001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_TYPE = unchecked((int)0xC03A001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_STATE = unchecked((int)0xC03A001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE = unchecked((int)0xC03A001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTDISK_DISK_ALREADY_OWNED = unchecked((int)0xC03A001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VIRTDISK_DISK_ONLINE_AND_WRITABLE = unchecked((int)0xC03A001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTLOG_TRACKING_NOT_INITIALIZED = unchecked((int)0xC03A0020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTLOG_LOGFILE_SIZE_EXCEEDED_MAXSIZE = unchecked((int)0xC03A0021);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTLOG_VHD_CHANGED_OFFLINE = unchecked((int)0xC03A0022);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTLOG_INVALID_TRACKING_STATE = unchecked((int)0xC03A0023);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CTLOG_INCONSISTENT_TRACKING_FILE = unchecked((int)0xC03A0024);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_METADATA_FULL = unchecked((int)0xC03A0028);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_INVALID_CHANGE_TRACKING_ID = unchecked((int)0xC03A0029);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_CHANGE_TRACKING_DISABLED = unchecked((int)0xC03A002A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_MISSING_CHANGE_TRACKING_INFORMATION = unchecked((int)0xC03A0030);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_RESIZE_WOULD_TRUNCATE_DATA = unchecked((int)0xC03A0031);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_COULD_NOT_COMPUTE_MINIMUM_VIRTUAL_SIZE = unchecked((int)0xC03A0032);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_ALREADY_AT_OR_BELOW_MINIMUM_VIRTUAL_SIZE = unchecked((int)0xC03A0033);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUERY_STORAGE_ERROR = unchecked((int)0x803A0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_GDI_HANDLE_LEAK = unchecked((int)0x803F0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_KEY_NOT_FOUND = unchecked((int)0xC0400001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_DUPLICATE_KEY = unchecked((int)0xC0400002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_BLOB_FULL = unchecked((int)0xC0400003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_STORE_FULL = unchecked((int)0xC0400004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_FILE_BLOCKED = unchecked((int)0xC0400005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RKF_ACTIVE_KEY = unchecked((int)0xC0400006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RDBSS_RESTART_OPERATION = unchecked((int)0xC0410001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RDBSS_CONTINUE_OPERATION = unchecked((int)0xC0410002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RDBSS_POST_OPERATION = unchecked((int)0xC0410003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_RDBSS_RETRY_LOOKUP = unchecked((int)0xC0410004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INVALID_HANDLE = unchecked((int)0xC0420001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_READ_NOT_PERMITTED = unchecked((int)0xC0420002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_WRITE_NOT_PERMITTED = unchecked((int)0xC0420003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INVALID_PDU = unchecked((int)0xC0420004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INSUFFICIENT_AUTHENTICATION = unchecked((int)0xC0420005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_REQUEST_NOT_SUPPORTED = unchecked((int)0xC0420006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INVALID_OFFSET = unchecked((int)0xC0420007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INSUFFICIENT_AUTHORIZATION = unchecked((int)0xC0420008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_PREPARE_QUEUE_FULL = unchecked((int)0xC0420009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_ATTRIBUTE_NOT_FOUND = unchecked((int)0xC042000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_ATTRIBUTE_NOT_LONG = unchecked((int)0xC042000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE = unchecked((int)0xC042000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH = unchecked((int)0xC042000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_UNLIKELY = unchecked((int)0xC042000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INSUFFICIENT_ENCRYPTION = unchecked((int)0xC042000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_UNSUPPORTED_GROUP_TYPE = unchecked((int)0xC0420010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_INSUFFICIENT_RESOURCES = unchecked((int)0xC0420011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_BTH_ATT_UNKNOWN_ERROR = unchecked((int)0xC0421000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_ROLLBACK_DETECTED = unchecked((int)0xC0430001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_VIOLATION = unchecked((int)0xC0430002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_INVALID_POLICY = unchecked((int)0xC0430003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_PUBLISHER_NOT_FOUND = unchecked((int)0xC0430004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_NOT_SIGNED = unchecked((int)0xC0430005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_NOT_ENABLED = unchecked((int)0x80430006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_FILE_REPLACED = unchecked((int)0xC0430007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_NOT_AUTHORIZED = unchecked((int)0xC0430008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_UNKNOWN = unchecked((int)0xC0430009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_MISSING_ANTIROLLBACKVERSION = unchecked((int)0xC043000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_PLATFORM_ID_MISMATCH = unchecked((int)0xC043000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_ROLLBACK_DETECTED = unchecked((int)0xC043000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_POLICY_UPGRADE_MISMATCH = unchecked((int)0xC043000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_REQUIRED_POLICY_FILE_MISSING = unchecked((int)0xC043000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_NOT_BASE_POLICY = unchecked((int)0xC043000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECUREBOOT_NOT_SUPPLEMENTAL_POLICY = unchecked((int)0xC0430010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_NOT_AUTHORIZED = unchecked((int)0xC0EB0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_INVALID = unchecked((int)0xC0EB0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_FILE_NOT_AUTHORIZED = unchecked((int)0xC0EB0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_CATALOG_NOT_AUTHORIZED = unchecked((int)0xC0EB0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_BINARY_ID_NOT_FOUND = unchecked((int)0xC0EB0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_NOT_ACTIVE = unchecked((int)0xC0EB0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_PLATFORM_MANIFEST_NOT_SIGNED = unchecked((int)0xC0EB0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_ROLLBACK_DETECTED = unchecked((int)0xC0E90001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_POLICY_VIOLATION = unchecked((int)0xC0E90002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_INVALID_POLICY = unchecked((int)0xC0E90003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_POLICY_NOT_SIGNED = unchecked((int)0xC0E90004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_TOO_MANY_POLICIES = unchecked((int)0xC0E90005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SYSTEM_INTEGRITY_SUPPLEMENTAL_POLICY_NOT_AUTHORIZED = unchecked((int)0xC0E90006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_NO_APPLICABLE_APP_LICENSES_FOUND = unchecked((int)0xC0EA0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_NOT_FOUND = unchecked((int)0xC0EA0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_DEVICE_LICENSE_MISSING = unchecked((int)0xC0EA0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_INVALID_SIGNATURE = unchecked((int)0xC0EA0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_KEYHOLDER_LICENSE_MISSING_OR_INVALID = unchecked((int)0xC0EA0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_EXPIRED = unchecked((int)0xC0EA0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_SIGNED_BY_UNKNOWN_SOURCE = unchecked((int)0xC0EA0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_NOT_SIGNED = unchecked((int)0xC0EA0008);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_HARDWARE_ID_OUT_OF_TOLERANCE = unchecked((int)0xC0EA0009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_CLIP_LICENSE_DEVICE_ID_MISMATCH = unchecked((int)0xC0EA000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_AUDIO_ENGINE_NODE_NOT_FOUND = unchecked((int)0xC0440001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HDAUDIO_EMPTY_CONNECTION_LIST = unchecked((int)0xC0440002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED = unchecked((int)0xC0440003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HDAUDIO_NO_LOGICAL_DEVICES_CREATED = unchecked((int)0xC0440004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_HDAUDIO_NULL_LINKED_LIST_ENTRY = unchecked((int)0xC0440005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_REPAIRED = 0x00E70000;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_PAUSE = 0x00E70001;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_COMPLETE = 0x00E70002;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_REDIRECT = 0x00E70003;

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_FAULT_DOMAIN_TYPE_INVALID = unchecked((int)0xC0E70001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_RESILIENCY_TYPE_INVALID = unchecked((int)0xC0E70003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_SECTOR_SIZE_INVALID = unchecked((int)0xC0E70004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_REDUNDANCY_INVALID = unchecked((int)0xC0E70006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_NUMBER_OF_DATA_COPIES_INVALID = unchecked((int)0xC0E70007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_INTERLEAVE_LENGTH_INVALID = unchecked((int)0xC0E70009);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_NUMBER_OF_COLUMNS_INVALID = unchecked((int)0xC0E7000A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_NOT_ENOUGH_DRIVES = unchecked((int)0xC0E7000B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_EXTENDED_ERROR = unchecked((int)0xC0E7000C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_PROVISIONING_TYPE_INVALID = unchecked((int)0xC0E7000D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_ALLOCATION_SIZE_INVALID = unchecked((int)0xC0E7000E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_ENCLOSURE_AWARE_INVALID = unchecked((int)0xC0E7000F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_WRITE_CACHE_SIZE_INVALID = unchecked((int)0xC0E70010);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_NUMBER_OF_GROUPS_INVALID = unchecked((int)0xC0E70011);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_OPERATIONAL_STATE_INVALID = unchecked((int)0xC0E70012);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_UPDATE_COLUMN_STATE = unchecked((int)0xC0E70013);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_MAP_REQUIRED = unchecked((int)0xC0E70014);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_UNSUPPORTED_VERSION = unchecked((int)0xC0E70015);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_CORRUPT_METADATA = unchecked((int)0xC0E70016);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRT_FULL = unchecked((int)0xC0E70017);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_INCONSISTENCY = unchecked((int)0xC0E70018);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_LOG_NOT_READY = unchecked((int)0xC0E70019);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_NO_REDUNDANCY = unchecked((int)0xC0E7001A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_NOT_READY = unchecked((int)0xC0E7001B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_SPLIT = unchecked((int)0xC0E7001C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_DRIVE_LOST_DATA = unchecked((int)0xC0E7001D);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_ENTRY_INCOMPLETE = unchecked((int)0xC0E7001E);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_ENTRY_INVALID = unchecked((int)0xC0E7001F);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SPACES_MARK_DIRTY = unchecked((int)0xC0E70020);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLSNAP_BOOTFILE_NOT_VALID = unchecked((int)0xC0500003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VOLSNAP_ACTIVATION_TIMEOUT = unchecked((int)0xC0500004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_IO_PREEMPTED = unchecked((int)0xC0510001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_ERROR_STORED = unchecked((int)0xC05C0000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_ERROR_NOT_AVAILABLE = unchecked((int)0xC05CFF00);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_AVAILABLE = unchecked((int)0xC05CFF01);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED = unchecked((int)0xC05CFF02);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED = unchecked((int)0xC05CFF03);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED = unchecked((int)0xC05CFF04);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED = unchecked((int)0xC05CFF05);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED = unchecked((int)0xC05CFF06);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_RESERVATION_CONFLICT = unchecked((int)0xC05CFF07);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_WRONG_FILE_TYPE = unchecked((int)0xC05CFF08);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_VERSION_MISMATCH = unchecked((int)0xC05CFF09);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHD_SHARED = unchecked((int)0xC05CFF0A);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SVHDX_NO_INITIATOR = unchecked((int)0xC05CFF0B);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VHDSET_BACKING_STORAGE_NOT_FOUND = unchecked((int)0xC05CFF0C);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMB_NO_PREAUTH_INTEGRITY_HASH_OVERLAP = unchecked((int)0xC05D0000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMB_BAD_CLUSTER_DIALECT = unchecked((int)0xC05D0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SMB_GUEST_LOGON_BLOCKED = unchecked((int)0xC05D0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_SECCORE_INVALID_COMMAND = unchecked((int)0xC0E80000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VSM_NOT_INITIALIZED = unchecked((int)0xC0450000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_VSM_DMA_PROTECTION_NOT_IN_USE = unchecked((int)0xC0450001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_CONDITION_NOT_SATISFIED = unchecked((int)0xC0EC0000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_HANDLE_INVALIDATED = unchecked((int)0xC0EC0001);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_INVALID_HOST_GENERATION = unchecked((int)0xC0EC0002);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_UNEXPECTED_PROCESS_REGISTRATION = unchecked((int)0xC0EC0003);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_INVALID_HOST_STATE = unchecked((int)0xC0EC0004);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_NO_DONOR = unchecked((int)0xC0EC0005);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_HOST_ID_MISMATCH = unchecked((int)0xC0EC0006);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_APPEXEC_UNKNOWN_USER = unchecked((int)0xC0EC0007);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUIC_HANDSHAKE_FAILURE = unchecked((int)0xC0240000);

        [NativeTypeName("NTSTATUS")]
        public const int STATUS_QUIC_VER_NEG_FAILURE = unchecked((int)0xC0240001);

        public const uint WINVER = 0x0500;

        public const uint APP_LOCAL_DEVICE_ID_SIZE = 32;

        public const uint DM_UPDATE = 1;

        public const uint DM_COPY = 2;

        public const uint DM_PROMPT = 4;

        public const uint DM_MODIFY = 8;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_OK = 0x00000000;

        public const int RPC_X_NO_MORE_ENTRIES = 1772;

        public const int RPC_X_SS_CHAR_TRANS_OPEN_FAIL = 1773;

        public const int RPC_X_SS_CHAR_TRANS_SHORT_FILE = 1774;

        public const int RPC_X_SS_IN_NULL_CONTEXT = 1775;

        public const int RPC_X_SS_CONTEXT_DAMAGED = 1777;

        public const int RPC_X_SS_HANDLES_MISMATCH = 1778;

        public const int RPC_X_SS_CANNOT_GET_CALL_HANDLE = 1779;

        public const int RPC_X_NULL_REF_POINTER = 1780;

        public const int RPC_X_ENUM_VALUE_OUT_OF_RANGE = 1781;

        public const int RPC_X_BYTE_COUNT_TOO_SMALL = 1782;

        public const int RPC_X_BAD_STUB_DATA = 1783;

        public const int RPC_X_INVALID_ES_ACTION = 1827;

        public const int RPC_X_WRONG_ES_VERSION = 1828;

        public const int RPC_X_WRONG_STUB_VERSION = 1829;

        public const int RPC_X_INVALID_PIPE_OBJECT = 1830;

        public const int RPC_X_WRONG_PIPE_ORDER = 1831;

        public const int RPC_X_WRONG_PIPE_VERSION = 1832;

        public const int OR_INVALID_OXID = 1910;

        public const int OR_INVALID_OID = 1911;

        public const int OR_INVALID_SET = 1912;

        public const int RPC_X_PIPE_CLOSED = 1916;

        public const int RPC_X_PIPE_DISCIPLINE_ERROR = 1917;

        public const int RPC_X_PIPE_EMPTY = 1918;

        public const int PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED = 4050;

        public const int PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO = 4051;

        public const int PEERDIST_ERROR_MISSING_DATA = 4052;

        public const int PEERDIST_ERROR_NO_MORE = 4053;

        public const int PEERDIST_ERROR_NOT_INITIALIZED = 4054;

        public const int PEERDIST_ERROR_ALREADY_INITIALIZED = 4055;

        public const int PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS = 4056;

        public const int PEERDIST_ERROR_INVALIDATED = 4057;

        public const int PEERDIST_ERROR_ALREADY_EXISTS = 4058;

        public const int PEERDIST_ERROR_OPERATION_NOTFOUND = 4059;

        public const int PEERDIST_ERROR_ALREADY_COMPLETED = 4060;

        public const int PEERDIST_ERROR_OUT_OF_BOUNDS = 4061;

        public const int PEERDIST_ERROR_VERSION_UNSUPPORTED = 4062;

        public const int PEERDIST_ERROR_INVALID_CONFIGURATION = 4063;

        public const int PEERDIST_ERROR_NOT_LICENSED = 4064;

        public const int PEERDIST_ERROR_SERVICE_UNAVAILABLE = 4065;

        public const int PEERDIST_ERROR_TRUST_FAILURE = 4066;

        public const int SCHED_E_SERVICE_NOT_LOCALSYSTEM = 6200;

        public const int FRS_ERR_INVALID_API_SEQUENCE = 8001;

        public const int FRS_ERR_STARTING_SERVICE = 8002;

        public const int FRS_ERR_STOPPING_SERVICE = 8003;

        public const int FRS_ERR_INTERNAL_API = 8004;

        public const int FRS_ERR_INTERNAL = 8005;

        public const int FRS_ERR_SERVICE_COMM = 8006;

        public const int FRS_ERR_INSUFFICIENT_PRIV = 8007;

        public const int FRS_ERR_AUTHENTICATION = 8008;

        public const int FRS_ERR_PARENT_INSUFFICIENT_PRIV = 8009;

        public const int FRS_ERR_PARENT_AUTHENTICATION = 8010;

        public const int FRS_ERR_CHILD_TO_PARENT_COMM = 8011;

        public const int FRS_ERR_PARENT_TO_CHILD_COMM = 8012;

        public const int FRS_ERR_SYSVOL_POPULATE = 8013;

        public const int FRS_ERR_SYSVOL_POPULATE_TIMEOUT = 8014;

        public const int FRS_ERR_SYSVOL_IS_BUSY = 8015;

        public const int FRS_ERR_SYSVOL_DEMOTE = 8016;

        public const int FRS_ERR_INVALID_SERVICE_PARAMETER = 8017;

        public const int DNS_INFO_NO_RECORDS = 9501;

        public const int DNS_REQUEST_PENDING = 9506;

        public const int DNS_STATUS_FQDN = 9557;

        public const int DNS_STATUS_DOTTED_NAME = 9558;

        public const int DNS_STATUS_SINGLE_PART_NAME = 9559;

        public const int DNS_WARNING_PTR_CREATE_FAILED = 9715;

        public const int DNS_WARNING_DOMAIN_UNDELETED = 9716;

        public const int DNS_INFO_AXFR_COMPLETE = 9751;

        public const int DNS_INFO_ADDED_LOCAL_WINS = 9753;

        public const int DNS_STATUS_CONTINUE_NEEDED = 9801;

        public const int WARNING_IPSEC_MM_POLICY_PRUNED = 13024;

        public const int WARNING_IPSEC_QM_POLICY_PRUNED = 13025;

        public const int APPMODEL_ERROR_NO_PACKAGE = 15700;

        public const int APPMODEL_ERROR_PACKAGE_RUNTIME_CORRUPT = 15701;

        public const int APPMODEL_ERROR_PACKAGE_IDENTITY_CORRUPT = 15702;

        public const int APPMODEL_ERROR_NO_APPLICATION = 15703;

        public const int APPMODEL_ERROR_DYNAMIC_PROPERTY_READ_FAILED = 15704;

        public const int APPMODEL_ERROR_DYNAMIC_PROPERTY_INVALID = 15705;

        public const int APPMODEL_ERROR_PACKAGE_NOT_AVAILABLE = 15706;

        public const int APPMODEL_ERROR_NO_MUTABLE_DIRECTORY = 15707;

        public const int STORE_ERROR_UNLICENSED = 15861;

        public const int STORE_ERROR_UNLICENSED_USER = 15862;

        public const int STORE_ERROR_PENDING_COM_TRANSACTION = 15863;

        public const int STORE_ERROR_LICENSE_REVOKED = 15864;

        public const uint SEVERITY_SUCCESS = 0;

        public const uint SEVERITY_ERROR = 1;

        public const uint NOERROR = 0;

        [NativeTypeName("HRESULT")]
        public const int E_UNEXPECTED = unchecked((int)0x8000FFFF);

        [NativeTypeName("HRESULT")]
        public const int E_NOINTERFACE = unchecked((int)0x80004002);

        [NativeTypeName("HRESULT")]
        public const int E_POINTER = unchecked((int)0x80004003);

        [NativeTypeName("HRESULT")]
        public const int E_HANDLE = unchecked((int)0x80070006);

        [NativeTypeName("HRESULT")]
        public const int E_ABORT = unchecked((int)0x80004004);

        [NativeTypeName("HRESULT")]
        public const int E_ACCESSDENIED = unchecked((int)0x80070005);

        [NativeTypeName("HRESULT")]
        public const int E_BOUNDS = unchecked((int)0x8000000B);

        [NativeTypeName("HRESULT")]
        public const int E_CHANGED_STATE = unchecked((int)0x8000000C);

        [NativeTypeName("HRESULT")]
        public const int E_ILLEGAL_STATE_CHANGE = unchecked((int)0x8000000D);

        [NativeTypeName("HRESULT")]
        public const int E_ILLEGAL_METHOD_CALL = unchecked((int)0x8000000E);

        [NativeTypeName("HRESULT")]
        public const int RO_E_METADATA_NAME_NOT_FOUND = unchecked((int)0x8000000F);

        [NativeTypeName("HRESULT")]
        public const int RO_E_METADATA_NAME_IS_NAMESPACE = unchecked((int)0x80000010);

        [NativeTypeName("HRESULT")]
        public const int RO_E_METADATA_INVALID_TYPE_FORMAT = unchecked((int)0x80000011);

        [NativeTypeName("HRESULT")]
        public const int RO_E_INVALID_METADATA_FILE = unchecked((int)0x80000012);

        [NativeTypeName("HRESULT")]
        public const int RO_E_CLOSED = unchecked((int)0x80000013);

        [NativeTypeName("HRESULT")]
        public const int RO_E_EXCLUSIVE_WRITE = unchecked((int)0x80000014);

        [NativeTypeName("HRESULT")]
        public const int RO_E_CHANGE_NOTIFICATION_IN_PROGRESS = unchecked((int)0x80000015);

        [NativeTypeName("HRESULT")]
        public const int RO_E_ERROR_STRING_NOT_FOUND = unchecked((int)0x80000016);

        [NativeTypeName("HRESULT")]
        public const int E_STRING_NOT_NULL_TERMINATED = unchecked((int)0x80000017);

        [NativeTypeName("HRESULT")]
        public const int E_ILLEGAL_DELEGATE_ASSIGNMENT = unchecked((int)0x80000018);

        [NativeTypeName("HRESULT")]
        public const int E_ASYNC_OPERATION_NOT_STARTED = unchecked((int)0x80000019);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_EXITING = unchecked((int)0x8000001A);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_VIEW_EXITING = unchecked((int)0x8000001B);

        [NativeTypeName("HRESULT")]
        public const int RO_E_MUST_BE_AGILE = unchecked((int)0x8000001C);

        [NativeTypeName("HRESULT")]
        public const int RO_E_UNSUPPORTED_FROM_MTA = unchecked((int)0x8000001D);

        [NativeTypeName("HRESULT")]
        public const int RO_E_COMMITTED = unchecked((int)0x8000001E);

        [NativeTypeName("HRESULT")]
        public const int RO_E_BLOCKED_CROSS_ASTA_CALL = unchecked((int)0x8000001F);

        [NativeTypeName("HRESULT")]
        public const int RO_E_CANNOT_ACTIVATE_FULL_TRUST_SERVER = unchecked((int)0x80000020);

        [NativeTypeName("HRESULT")]
        public const int RO_E_CANNOT_ACTIVATE_UNIVERSAL_APPLICATION_SERVER = unchecked((int)0x80000021);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_TLS = unchecked((int)0x80004006);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_SHARED_ALLOCATOR = unchecked((int)0x80004007);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_MEMORY_ALLOCATOR = unchecked((int)0x80004008);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_CLASS_CACHE = unchecked((int)0x80004009);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_RPC_CHANNEL = unchecked((int)0x8000400A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_TLS_SET_CHANNEL_CONTROL = unchecked((int)0x8000400B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_TLS_CHANNEL_CONTROL = unchecked((int)0x8000400C);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_UNACCEPTED_USER_ALLOCATOR = unchecked((int)0x8000400D);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_SCM_MUTEX_EXISTS = unchecked((int)0x8000400E);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_SCM_FILE_MAPPING_EXISTS = unchecked((int)0x8000400F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_SCM_MAP_VIEW_OF_FILE = unchecked((int)0x80004010);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_SCM_EXEC_FAILURE = unchecked((int)0x80004011);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INIT_ONLY_SINGLE_THREADED = unchecked((int)0x80004012);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CANT_REMOTE = unchecked((int)0x80004013);

        [NativeTypeName("HRESULT")]
        public const int CO_E_BAD_SERVER_NAME = unchecked((int)0x80004014);

        [NativeTypeName("HRESULT")]
        public const int CO_E_WRONG_SERVER_IDENTITY = unchecked((int)0x80004015);

        [NativeTypeName("HRESULT")]
        public const int CO_E_OLE1DDE_DISABLED = unchecked((int)0x80004016);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RUNAS_SYNTAX = unchecked((int)0x80004017);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CREATEPROCESS_FAILURE = unchecked((int)0x80004018);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RUNAS_CREATEPROCESS_FAILURE = unchecked((int)0x80004019);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RUNAS_LOGON_FAILURE = unchecked((int)0x8000401A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_LAUNCH_PERMSSION_DENIED = unchecked((int)0x8000401B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_START_SERVICE_FAILURE = unchecked((int)0x8000401C);

        [NativeTypeName("HRESULT")]
        public const int CO_E_REMOTE_COMMUNICATION_FAILURE = unchecked((int)0x8000401D);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_START_TIMEOUT = unchecked((int)0x8000401E);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CLSREG_INCONSISTENT = unchecked((int)0x8000401F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_IIDREG_INCONSISTENT = unchecked((int)0x80004020);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOT_SUPPORTED = unchecked((int)0x80004021);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RELOAD_DLL = unchecked((int)0x80004022);

        [NativeTypeName("HRESULT")]
        public const int CO_E_MSI_ERROR = unchecked((int)0x80004023);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT = unchecked((int)0x80004024);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_PAUSED = unchecked((int)0x80004025);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_NOT_PAUSED = unchecked((int)0x80004026);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CLASS_DISABLED = unchecked((int)0x80004027);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CLRNOTAVAILABLE = unchecked((int)0x80004028);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ASYNC_WORK_REJECTED = unchecked((int)0x80004029);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_INIT_TIMEOUT = unchecked((int)0x8000402A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NO_SECCTX_IN_ACTIVATE = unchecked((int)0x8000402B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_TRACKER_CONFIG = unchecked((int)0x80004030);

        [NativeTypeName("HRESULT")]
        public const int CO_E_THREADPOOL_CONFIG = unchecked((int)0x80004031);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SXS_CONFIG = unchecked((int)0x80004032);

        [NativeTypeName("HRESULT")]
        public const int CO_E_MALFORMED_SPN = unchecked((int)0x80004033);

        [NativeTypeName("HRESULT")]
        public const int CO_E_UNREVOKED_REGISTRATION_ON_APARTMENT_SHUTDOWN = unchecked((int)0x80004034);

        [NativeTypeName("HRESULT")]
        public const int CO_E_PREMATURE_STUB_RUNDOWN = unchecked((int)0x80004035);

        [NativeTypeName("HRESULT")]
        public const int S_OK = 0;

        [NativeTypeName("HRESULT")]
        public const int S_FALSE = 1;

        [NativeTypeName("HRESULT")]
        public const int OLE_E_FIRST = unchecked((int)0x80040000);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_LAST = unchecked((int)0x800400FF);

        [NativeTypeName("HRESULT")]
        public const int OLE_S_FIRST = 0x00040000;

        [NativeTypeName("HRESULT")]
        public const int OLE_S_LAST = 0x000400FF;

        [NativeTypeName("HRESULT")]
        public const int OLE_E_OLEVERB = unchecked((int)0x80040000);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_ADVF = unchecked((int)0x80040001);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_ENUM_NOMORE = unchecked((int)0x80040002);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_ADVISENOTSUPPORTED = unchecked((int)0x80040003);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_NOCONNECTION = unchecked((int)0x80040004);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_NOTRUNNING = unchecked((int)0x80040005);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_NOCACHE = unchecked((int)0x80040006);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_BLANK = unchecked((int)0x80040007);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_CLASSDIFF = unchecked((int)0x80040008);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_CANT_GETMONIKER = unchecked((int)0x80040009);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_CANT_BINDTOSOURCE = unchecked((int)0x8004000A);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_STATIC = unchecked((int)0x8004000B);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_PROMPTSAVECANCELLED = unchecked((int)0x8004000C);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_INVALIDRECT = unchecked((int)0x8004000D);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_WRONGCOMPOBJ = unchecked((int)0x8004000E);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_INVALIDHWND = unchecked((int)0x8004000F);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_NOT_INPLACEACTIVE = unchecked((int)0x80040010);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_CANTCONVERT = unchecked((int)0x80040011);

        [NativeTypeName("HRESULT")]
        public const int OLE_E_NOSTORAGE = unchecked((int)0x80040012);

        [NativeTypeName("HRESULT")]
        public const int DV_E_FORMATETC = unchecked((int)0x80040064);

        [NativeTypeName("HRESULT")]
        public const int DV_E_DVTARGETDEVICE = unchecked((int)0x80040065);

        [NativeTypeName("HRESULT")]
        public const int DV_E_STGMEDIUM = unchecked((int)0x80040066);

        [NativeTypeName("HRESULT")]
        public const int DV_E_STATDATA = unchecked((int)0x80040067);

        [NativeTypeName("HRESULT")]
        public const int DV_E_LINDEX = unchecked((int)0x80040068);

        [NativeTypeName("HRESULT")]
        public const int DV_E_TYMED = unchecked((int)0x80040069);

        [NativeTypeName("HRESULT")]
        public const int DV_E_CLIPFORMAT = unchecked((int)0x8004006A);

        [NativeTypeName("HRESULT")]
        public const int DV_E_DVASPECT = unchecked((int)0x8004006B);

        [NativeTypeName("HRESULT")]
        public const int DV_E_DVTARGETDEVICE_SIZE = unchecked((int)0x8004006C);

        [NativeTypeName("HRESULT")]
        public const int DV_E_NOIVIEWOBJECT = unchecked((int)0x8004006D);

        public const int DRAGDROP_E_FIRST = unchecked((int)0x80040100);

        public const int DRAGDROP_E_LAST = unchecked((int)0x8004010F);

        public const int DRAGDROP_S_FIRST = 0x00040100;

        public const int DRAGDROP_S_LAST = 0x0004010F;

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_E_NOTREGISTERED = unchecked((int)0x80040100);

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_E_ALREADYREGISTERED = unchecked((int)0x80040101);

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_E_INVALIDHWND = unchecked((int)0x80040102);

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_E_CONCURRENT_DRAG_ATTEMPTED = unchecked((int)0x80040103);

        public const int CLASSFACTORY_E_FIRST = unchecked((int)0x80040110);

        public const int CLASSFACTORY_E_LAST = unchecked((int)0x8004011F);

        public const int CLASSFACTORY_S_FIRST = 0x00040110;

        public const int CLASSFACTORY_S_LAST = 0x0004011F;

        [NativeTypeName("HRESULT")]
        public const int CLASS_E_NOAGGREGATION = unchecked((int)0x80040110);

        [NativeTypeName("HRESULT")]
        public const int CLASS_E_CLASSNOTAVAILABLE = unchecked((int)0x80040111);

        [NativeTypeName("HRESULT")]
        public const int CLASS_E_NOTLICENSED = unchecked((int)0x80040112);

        public const int MARSHAL_E_FIRST = unchecked((int)0x80040120);

        public const int MARSHAL_E_LAST = unchecked((int)0x8004012F);

        public const int MARSHAL_S_FIRST = 0x00040120;

        public const int MARSHAL_S_LAST = 0x0004012F;

        public const int DATA_E_FIRST = unchecked((int)0x80040130);

        public const int DATA_E_LAST = unchecked((int)0x8004013F);

        public const int DATA_S_FIRST = 0x00040130;

        public const int DATA_S_LAST = 0x0004013F;

        public const int VIEW_E_FIRST = unchecked((int)0x80040140);

        public const int VIEW_E_LAST = unchecked((int)0x8004014F);

        public const int VIEW_S_FIRST = 0x00040140;

        public const int VIEW_S_LAST = 0x0004014F;

        [NativeTypeName("HRESULT")]
        public const int VIEW_E_DRAW = unchecked((int)0x80040140);

        public const int REGDB_E_FIRST = unchecked((int)0x80040150);

        public const int REGDB_E_LAST = unchecked((int)0x8004015F);

        public const int REGDB_S_FIRST = 0x00040150;

        public const int REGDB_S_LAST = 0x0004015F;

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_READREGDB = unchecked((int)0x80040150);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_WRITEREGDB = unchecked((int)0x80040151);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_KEYMISSING = unchecked((int)0x80040152);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_INVALIDVALUE = unchecked((int)0x80040153);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_CLASSNOTREG = unchecked((int)0x80040154);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_IIDNOTREG = unchecked((int)0x80040155);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_BADTHREADINGMODEL = unchecked((int)0x80040156);

        [NativeTypeName("HRESULT")]
        public const int REGDB_E_PACKAGEPOLICYVIOLATION = unchecked((int)0x80040157);

        public const int CAT_E_FIRST = unchecked((int)0x80040160);

        public const int CAT_E_LAST = unchecked((int)0x80040161);

        [NativeTypeName("HRESULT")]
        public const int CAT_E_CATIDNOEXIST = unchecked((int)0x80040160);

        [NativeTypeName("HRESULT")]
        public const int CAT_E_NODESCRIPTION = unchecked((int)0x80040161);

        public const int CS_E_FIRST = unchecked((int)0x80040164);

        public const int CS_E_LAST = unchecked((int)0x8004016F);

        [NativeTypeName("HRESULT")]
        public const int CS_E_PACKAGE_NOTFOUND = unchecked((int)0x80040164);

        [NativeTypeName("HRESULT")]
        public const int CS_E_NOT_DELETABLE = unchecked((int)0x80040165);

        [NativeTypeName("HRESULT")]
        public const int CS_E_CLASS_NOTFOUND = unchecked((int)0x80040166);

        [NativeTypeName("HRESULT")]
        public const int CS_E_INVALID_VERSION = unchecked((int)0x80040167);

        [NativeTypeName("HRESULT")]
        public const int CS_E_NO_CLASSSTORE = unchecked((int)0x80040168);

        [NativeTypeName("HRESULT")]
        public const int CS_E_OBJECT_NOTFOUND = unchecked((int)0x80040169);

        [NativeTypeName("HRESULT")]
        public const int CS_E_OBJECT_ALREADY_EXISTS = unchecked((int)0x8004016A);

        [NativeTypeName("HRESULT")]
        public const int CS_E_INVALID_PATH = unchecked((int)0x8004016B);

        [NativeTypeName("HRESULT")]
        public const int CS_E_NETWORK_ERROR = unchecked((int)0x8004016C);

        [NativeTypeName("HRESULT")]
        public const int CS_E_ADMIN_LIMIT_EXCEEDED = unchecked((int)0x8004016D);

        [NativeTypeName("HRESULT")]
        public const int CS_E_SCHEMA_MISMATCH = unchecked((int)0x8004016E);

        [NativeTypeName("HRESULT")]
        public const int CS_E_INTERNAL_ERROR = unchecked((int)0x8004016F);

        public const int CACHE_E_FIRST = unchecked((int)0x80040170);

        public const int CACHE_E_LAST = unchecked((int)0x8004017F);

        public const int CACHE_S_FIRST = 0x00040170;

        public const int CACHE_S_LAST = 0x0004017F;

        [NativeTypeName("HRESULT")]
        public const int CACHE_E_NOCACHE_UPDATED = unchecked((int)0x80040170);

        public const int OLEOBJ_E_FIRST = unchecked((int)0x80040180);

        public const int OLEOBJ_E_LAST = unchecked((int)0x8004018F);

        public const int OLEOBJ_S_FIRST = 0x00040180;

        public const int OLEOBJ_S_LAST = 0x0004018F;

        [NativeTypeName("HRESULT")]
        public const int OLEOBJ_E_NOVERBS = unchecked((int)0x80040180);

        [NativeTypeName("HRESULT")]
        public const int OLEOBJ_E_INVALIDVERB = unchecked((int)0x80040181);

        public const int CLIENTSITE_E_FIRST = unchecked((int)0x80040190);

        public const int CLIENTSITE_E_LAST = unchecked((int)0x8004019F);

        public const int CLIENTSITE_S_FIRST = 0x00040190;

        public const int CLIENTSITE_S_LAST = 0x0004019F;

        [NativeTypeName("HRESULT")]
        public const int INPLACE_E_NOTUNDOABLE = unchecked((int)0x800401A0);

        [NativeTypeName("HRESULT")]
        public const int INPLACE_E_NOTOOLSPACE = unchecked((int)0x800401A1);

        public const int INPLACE_E_FIRST = unchecked((int)0x800401A0);

        public const int INPLACE_E_LAST = unchecked((int)0x800401AF);

        public const int INPLACE_S_FIRST = 0x000401A0;

        public const int INPLACE_S_LAST = 0x000401AF;

        public const int ENUM_E_FIRST = unchecked((int)0x800401B0);

        public const int ENUM_E_LAST = unchecked((int)0x800401BF);

        public const int ENUM_S_FIRST = 0x000401B0;

        public const int ENUM_S_LAST = 0x000401BF;

        public const int CONVERT10_E_FIRST = unchecked((int)0x800401C0);

        public const int CONVERT10_E_LAST = unchecked((int)0x800401CF);

        public const int CONVERT10_S_FIRST = 0x000401C0;

        public const int CONVERT10_S_LAST = 0x000401CF;

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_OLESTREAM_GET = unchecked((int)0x800401C0);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_OLESTREAM_PUT = unchecked((int)0x800401C1);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_OLESTREAM_FMT = unchecked((int)0x800401C2);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_OLESTREAM_BITMAP_TO_DIB = unchecked((int)0x800401C3);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_STG_FMT = unchecked((int)0x800401C4);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_STG_NO_STD_STREAM = unchecked((int)0x800401C5);

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_E_STG_DIB_TO_BITMAP = unchecked((int)0x800401C6);

        public const int CLIPBRD_E_FIRST = unchecked((int)0x800401D0);

        public const int CLIPBRD_E_LAST = unchecked((int)0x800401DF);

        public const int CLIPBRD_S_FIRST = 0x000401D0;

        public const int CLIPBRD_S_LAST = 0x000401DF;

        [NativeTypeName("HRESULT")]
        public const int CLIPBRD_E_CANT_OPEN = unchecked((int)0x800401D0);

        [NativeTypeName("HRESULT")]
        public const int CLIPBRD_E_CANT_EMPTY = unchecked((int)0x800401D1);

        [NativeTypeName("HRESULT")]
        public const int CLIPBRD_E_CANT_SET = unchecked((int)0x800401D2);

        [NativeTypeName("HRESULT")]
        public const int CLIPBRD_E_BAD_DATA = unchecked((int)0x800401D3);

        [NativeTypeName("HRESULT")]
        public const int CLIPBRD_E_CANT_CLOSE = unchecked((int)0x800401D4);

        public const int MK_E_FIRST = unchecked((int)0x800401E0);

        public const int MK_E_LAST = unchecked((int)0x800401EF);

        public const int MK_S_FIRST = 0x000401E0;

        public const int MK_S_LAST = 0x000401EF;

        [NativeTypeName("HRESULT")]
        public const int MK_E_CONNECTMANUALLY = unchecked((int)0x800401E0);

        [NativeTypeName("HRESULT")]
        public const int MK_E_EXCEEDEDDEADLINE = unchecked((int)0x800401E1);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NEEDGENERIC = unchecked((int)0x800401E2);

        [NativeTypeName("HRESULT")]
        public const int MK_E_UNAVAILABLE = unchecked((int)0x800401E3);

        [NativeTypeName("HRESULT")]
        public const int MK_E_SYNTAX = unchecked((int)0x800401E4);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOOBJECT = unchecked((int)0x800401E5);

        [NativeTypeName("HRESULT")]
        public const int MK_E_INVALIDEXTENSION = unchecked((int)0x800401E6);

        [NativeTypeName("HRESULT")]
        public const int MK_E_INTERMEDIATEINTERFACENOTSUPPORTED = unchecked((int)0x800401E7);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOTBINDABLE = unchecked((int)0x800401E8);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOTBOUND = unchecked((int)0x800401E9);

        [NativeTypeName("HRESULT")]
        public const int MK_E_CANTOPENFILE = unchecked((int)0x800401EA);

        [NativeTypeName("HRESULT")]
        public const int MK_E_MUSTBOTHERUSER = unchecked((int)0x800401EB);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOINVERSE = unchecked((int)0x800401EC);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOSTORAGE = unchecked((int)0x800401ED);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NOPREFIX = unchecked((int)0x800401EE);

        [NativeTypeName("HRESULT")]
        public const int MK_E_ENUMERATION_FAILED = unchecked((int)0x800401EF);

        public const int CO_E_FIRST = unchecked((int)0x800401F0);

        public const int CO_E_LAST = unchecked((int)0x800401FF);

        public const int CO_S_FIRST = 0x000401F0;

        public const int CO_S_LAST = 0x000401FF;

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOTINITIALIZED = unchecked((int)0x800401F0);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ALREADYINITIALIZED = unchecked((int)0x800401F1);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CANTDETERMINECLASS = unchecked((int)0x800401F2);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CLASSSTRING = unchecked((int)0x800401F3);

        [NativeTypeName("HRESULT")]
        public const int CO_E_IIDSTRING = unchecked((int)0x800401F4);

        [NativeTypeName("HRESULT")]
        public const int CO_E_APPNOTFOUND = unchecked((int)0x800401F5);

        [NativeTypeName("HRESULT")]
        public const int CO_E_APPSINGLEUSE = unchecked((int)0x800401F6);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ERRORINAPP = unchecked((int)0x800401F7);

        [NativeTypeName("HRESULT")]
        public const int CO_E_DLLNOTFOUND = unchecked((int)0x800401F8);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ERRORINDLL = unchecked((int)0x800401F9);

        [NativeTypeName("HRESULT")]
        public const int CO_E_WRONGOSFORAPP = unchecked((int)0x800401FA);

        [NativeTypeName("HRESULT")]
        public const int CO_E_OBJNOTREG = unchecked((int)0x800401FB);

        [NativeTypeName("HRESULT")]
        public const int CO_E_OBJISREG = unchecked((int)0x800401FC);

        [NativeTypeName("HRESULT")]
        public const int CO_E_OBJNOTCONNECTED = unchecked((int)0x800401FD);

        [NativeTypeName("HRESULT")]
        public const int CO_E_APPDIDNTREG = unchecked((int)0x800401FE);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RELEASED = unchecked((int)0x800401FF);

        public const int EVENT_E_FIRST = unchecked((int)0x80040200);

        public const int EVENT_E_LAST = unchecked((int)0x8004021F);

        public const int EVENT_S_FIRST = 0x00040200;

        public const int EVENT_S_LAST = 0x0004021F;

        [NativeTypeName("HRESULT")]
        public const int EVENT_S_SOME_SUBSCRIBERS_FAILED = 0x00040200;

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_ALL_SUBSCRIBERS_FAILED = unchecked((int)0x80040201);

        [NativeTypeName("HRESULT")]
        public const int EVENT_S_NOSUBSCRIBERS = 0x00040202;

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_QUERYSYNTAX = unchecked((int)0x80040203);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_QUERYFIELD = unchecked((int)0x80040204);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_INTERNALEXCEPTION = unchecked((int)0x80040205);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_INTERNALERROR = unchecked((int)0x80040206);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_INVALID_PER_USER_SID = unchecked((int)0x80040207);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_USER_EXCEPTION = unchecked((int)0x80040208);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_TOO_MANY_METHODS = unchecked((int)0x80040209);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_MISSING_EVENTCLASS = unchecked((int)0x8004020A);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_NOT_ALL_REMOVED = unchecked((int)0x8004020B);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_COMPLUS_NOT_INSTALLED = unchecked((int)0x8004020C);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT = unchecked((int)0x8004020D);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT = unchecked((int)0x8004020E);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_INVALID_EVENT_CLASS_PARTITION = unchecked((int)0x8004020F);

        [NativeTypeName("HRESULT")]
        public const int EVENT_E_PER_USER_SID_NOT_LOGGED_ON = unchecked((int)0x80040210);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_PROPERTY = unchecked((int)0x80040241);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_NO_DEFAULT_TABLET = unchecked((int)0x80040212);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_UNKNOWN_PROPERTY = unchecked((int)0x8004021B);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_INPUT_RECT = unchecked((int)0x80040219);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_STROKE = unchecked((int)0x80040222);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INITIALIZE_FAIL = unchecked((int)0x80040223);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_NOT_RELEVANT = unchecked((int)0x80040232);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_PACKET_DESCRIPTION = unchecked((int)0x80040233);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_RECOGNIZER_NOT_REGISTERED = unchecked((int)0x80040235);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_RIGHTS = unchecked((int)0x80040236);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_OUT_OF_ORDER_CALL = unchecked((int)0x80040237);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_QUEUE_FULL = unchecked((int)0x80040238);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_CONFIGURATION = unchecked((int)0x80040239);

        [NativeTypeName("HRESULT")]
        public const int TPC_E_INVALID_DATA_FROM_RECOGNIZER = unchecked((int)0x8004023A);

        [NativeTypeName("HRESULT")]
        public const int TPC_S_TRUNCATED = 0x00040252;

        [NativeTypeName("HRESULT")]
        public const int TPC_S_INTERRUPTED = 0x00040253;

        [NativeTypeName("HRESULT")]
        public const int TPC_S_NO_DATA_TO_PROCESS = 0x00040254;

        public const uint XACT_E_FIRST = 0x8004D000;

        public const uint XACT_E_LAST = 0x8004D02B;

        public const uint XACT_S_FIRST = 0x0004D000;

        public const uint XACT_S_LAST = 0x0004D010;

        [NativeTypeName("HRESULT")]
        public const int XACT_E_ALREADYOTHERSINGLEPHASE = unchecked((int)0x8004D000);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_CANTRETAIN = unchecked((int)0x8004D001);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_COMMITFAILED = unchecked((int)0x8004D002);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_COMMITPREVENTED = unchecked((int)0x8004D003);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_HEURISTICABORT = unchecked((int)0x8004D004);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_HEURISTICCOMMIT = unchecked((int)0x8004D005);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_HEURISTICDAMAGE = unchecked((int)0x8004D006);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_HEURISTICDANGER = unchecked((int)0x8004D007);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_ISOLATIONLEVEL = unchecked((int)0x8004D008);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOASYNC = unchecked((int)0x8004D009);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOENLIST = unchecked((int)0x8004D00A);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOISORETAIN = unchecked((int)0x8004D00B);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NORESOURCE = unchecked((int)0x8004D00C);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOTCURRENT = unchecked((int)0x8004D00D);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOTRANSACTION = unchecked((int)0x8004D00E);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOTSUPPORTED = unchecked((int)0x8004D00F);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_UNKNOWNRMGRID = unchecked((int)0x8004D010);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_WRONGSTATE = unchecked((int)0x8004D011);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_WRONGUOW = unchecked((int)0x8004D012);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_XTIONEXISTS = unchecked((int)0x8004D013);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOIMPORTOBJECT = unchecked((int)0x8004D014);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_INVALIDCOOKIE = unchecked((int)0x8004D015);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_INDOUBT = unchecked((int)0x8004D016);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NOTIMEOUT = unchecked((int)0x8004D017);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_ALREADYINPROGRESS = unchecked((int)0x8004D018);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_ABORTED = unchecked((int)0x8004D019);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_LOGFULL = unchecked((int)0x8004D01A);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TMNOTAVAILABLE = unchecked((int)0x8004D01B);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_CONNECTION_DOWN = unchecked((int)0x8004D01C);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_CONNECTION_DENIED = unchecked((int)0x8004D01D);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_REENLISTTIMEOUT = unchecked((int)0x8004D01E);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TIP_CONNECT_FAILED = unchecked((int)0x8004D01F);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TIP_PROTOCOL_ERROR = unchecked((int)0x8004D020);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TIP_PULL_FAILED = unchecked((int)0x8004D021);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_DEST_TMNOTAVAILABLE = unchecked((int)0x8004D022);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TIP_DISABLED = unchecked((int)0x8004D023);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_NETWORK_TX_DISABLED = unchecked((int)0x8004D024);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_PARTNER_NETWORK_TX_DISABLED = unchecked((int)0x8004D025);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_XA_TX_DISABLED = unchecked((int)0x8004D026);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_UNABLE_TO_READ_DTC_CONFIG = unchecked((int)0x8004D027);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_UNABLE_TO_LOAD_DTC_PROXY = unchecked((int)0x8004D028);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_ABORTING = unchecked((int)0x8004D029);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_PUSH_COMM_FAILURE = unchecked((int)0x8004D02A);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_PULL_COMM_FAILURE = unchecked((int)0x8004D02B);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_LU_TX_DISABLED = unchecked((int)0x8004D02C);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_CLERKNOTFOUND = unchecked((int)0x8004D080);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_CLERKEXISTS = unchecked((int)0x8004D081);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_RECOVERYINPROGRESS = unchecked((int)0x8004D082);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_TRANSACTIONCLOSED = unchecked((int)0x8004D083);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_INVALIDLSN = unchecked((int)0x8004D084);

        [NativeTypeName("HRESULT")]
        public const int XACT_E_REPLAYREQUEST = unchecked((int)0x8004D085);

        [NativeTypeName("HRESULT")]
        public const int XACT_S_ASYNC = 0x0004D000;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_DEFECT = 0x0004D001;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_READONLY = 0x0004D002;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_SOMENORETAIN = 0x0004D003;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_OKINFORM = 0x0004D004;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_MADECHANGESCONTENT = 0x0004D005;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_MADECHANGESINFORM = 0x0004D006;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_ALLNORETAIN = 0x0004D007;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_ABORTING = 0x0004D008;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_SINGLEPHASE = 0x0004D009;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_LOCALLY_OK = 0x0004D00A;

        [NativeTypeName("HRESULT")]
        public const int XACT_S_LASTRESOURCEMANAGER = 0x0004D010;

        public const int CONTEXT_E_FIRST = unchecked((int)0x8004E000);

        public const int CONTEXT_E_LAST = unchecked((int)0x8004E02F);

        public const int CONTEXT_S_FIRST = 0x0004E000;

        public const int CONTEXT_S_LAST = 0x0004E02F;

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_ABORTED = unchecked((int)0x8004E002);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_ABORTING = unchecked((int)0x8004E003);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_NOCONTEXT = unchecked((int)0x8004E004);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_WOULD_DEADLOCK = unchecked((int)0x8004E005);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_SYNCH_TIMEOUT = unchecked((int)0x8004E006);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_OLDREF = unchecked((int)0x8004E007);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_ROLENOTFOUND = unchecked((int)0x8004E00C);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_TMNOTAVAILABLE = unchecked((int)0x8004E00F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACTIVATIONFAILED = unchecked((int)0x8004E021);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACTIVATIONFAILED_EVENTLOGGED = unchecked((int)0x8004E022);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACTIVATIONFAILED_CATALOGERROR = unchecked((int)0x8004E023);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACTIVATIONFAILED_TIMEOUT = unchecked((int)0x8004E024);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INITIALIZATIONFAILED = unchecked((int)0x8004E025);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_NOJIT = unchecked((int)0x8004E026);

        [NativeTypeName("HRESULT")]
        public const int CONTEXT_E_NOTRANSACTION = unchecked((int)0x8004E027);

        [NativeTypeName("HRESULT")]
        public const int CO_E_THREADINGMODEL_CHANGED = unchecked((int)0x8004E028);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOIISINTRINSICS = unchecked((int)0x8004E029);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOCOOKIES = unchecked((int)0x8004E02A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_DBERROR = unchecked((int)0x8004E02B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOTPOOLED = unchecked((int)0x8004E02C);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOTCONSTRUCTED = unchecked((int)0x8004E02D);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOSYNCHRONIZATION = unchecked((int)0x8004E02E);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ISOLEVELMISMATCH = unchecked((int)0x8004E02F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED = unchecked((int)0x8004E030);

        [NativeTypeName("HRESULT")]
        public const int CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED = unchecked((int)0x8004E031);

        [NativeTypeName("HRESULT")]
        public const int OLE_S_USEREG = 0x00040000;

        [NativeTypeName("HRESULT")]
        public const int OLE_S_STATIC = 0x00040001;

        [NativeTypeName("HRESULT")]
        public const int OLE_S_MAC_CLIPFORMAT = 0x00040002;

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_S_DROP = 0x00040100;

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_S_CANCEL = 0x00040101;

        [NativeTypeName("HRESULT")]
        public const int DRAGDROP_S_USEDEFAULTCURSORS = 0x00040102;

        [NativeTypeName("HRESULT")]
        public const int DATA_S_SAMEFORMATETC = 0x00040130;

        [NativeTypeName("HRESULT")]
        public const int VIEW_S_ALREADY_FROZEN = 0x00040140;

        [NativeTypeName("HRESULT")]
        public const int CACHE_S_FORMATETC_NOTSUPPORTED = 0x00040170;

        [NativeTypeName("HRESULT")]
        public const int CACHE_S_SAMECACHE = 0x00040171;

        [NativeTypeName("HRESULT")]
        public const int CACHE_S_SOMECACHES_NOTUPDATED = 0x00040172;

        [NativeTypeName("HRESULT")]
        public const int OLEOBJ_S_INVALIDVERB = 0x00040180;

        [NativeTypeName("HRESULT")]
        public const int OLEOBJ_S_CANNOT_DOVERB_NOW = 0x00040181;

        [NativeTypeName("HRESULT")]
        public const int OLEOBJ_S_INVALIDHWND = 0x00040182;

        [NativeTypeName("HRESULT")]
        public const int INPLACE_S_TRUNCATED = 0x000401A0;

        [NativeTypeName("HRESULT")]
        public const int CONVERT10_S_NO_PRESENTATION = 0x000401C0;

        [NativeTypeName("HRESULT")]
        public const int MK_S_REDUCED_TO_SELF = 0x000401E2;

        [NativeTypeName("HRESULT")]
        public const int MK_S_ME = 0x000401E4;

        [NativeTypeName("HRESULT")]
        public const int MK_S_HIM = 0x000401E5;

        [NativeTypeName("HRESULT")]
        public const int MK_S_US = 0x000401E6;

        [NativeTypeName("HRESULT")]
        public const int MK_S_MONIKERALREADYREGISTERED = 0x000401E7;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_READY = 0x00041300;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_RUNNING = 0x00041301;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_DISABLED = 0x00041302;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_HAS_NOT_RUN = 0x00041303;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_NO_MORE_RUNS = 0x00041304;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_NOT_SCHEDULED = 0x00041305;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_TERMINATED = 0x00041306;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_NO_VALID_TRIGGERS = 0x00041307;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_EVENT_TRIGGER = 0x00041308;

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TRIGGER_NOT_FOUND = unchecked((int)0x80041309);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_NOT_READY = unchecked((int)0x8004130A);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_NOT_RUNNING = unchecked((int)0x8004130B);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_SERVICE_NOT_INSTALLED = unchecked((int)0x8004130C);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_CANNOT_OPEN_TASK = unchecked((int)0x8004130D);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_INVALID_TASK = unchecked((int)0x8004130E);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_ACCOUNT_INFORMATION_NOT_SET = unchecked((int)0x8004130F);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_ACCOUNT_NAME_NOT_FOUND = unchecked((int)0x80041310);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_ACCOUNT_DBASE_CORRUPT = unchecked((int)0x80041311);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_NO_SECURITY_SERVICES = unchecked((int)0x80041312);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_UNKNOWN_OBJECT_VERSION = unchecked((int)0x80041313);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_UNSUPPORTED_ACCOUNT_OPTION = unchecked((int)0x80041314);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_SERVICE_NOT_RUNNING = unchecked((int)0x80041315);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_UNEXPECTEDNODE = unchecked((int)0x80041316);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_NAMESPACE = unchecked((int)0x80041317);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_INVALIDVALUE = unchecked((int)0x80041318);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_MISSINGNODE = unchecked((int)0x80041319);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_MALFORMEDXML = unchecked((int)0x8004131A);

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_SOME_TRIGGERS_FAILED = 0x0004131B;

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_BATCH_LOGON_PROBLEM = 0x0004131C;

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TOO_MANY_NODES = unchecked((int)0x8004131D);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_PAST_END_BOUNDARY = unchecked((int)0x8004131E);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_ALREADY_RUNNING = unchecked((int)0x8004131F);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_USER_NOT_LOGGED_ON = unchecked((int)0x80041320);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_INVALID_TASK_HASH = unchecked((int)0x80041321);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_SERVICE_NOT_AVAILABLE = unchecked((int)0x80041322);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_SERVICE_TOO_BUSY = unchecked((int)0x80041323);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_ATTEMPTED = unchecked((int)0x80041324);

        [NativeTypeName("HRESULT")]
        public const int SCHED_S_TASK_QUEUED = 0x00041325;

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_DISABLED = unchecked((int)0x80041326);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_NOT_V1_COMPAT = unchecked((int)0x80041327);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_START_ON_DEMAND = unchecked((int)0x80041328);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_TASK_NOT_UBPM_COMPAT = unchecked((int)0x80041329);

        [NativeTypeName("HRESULT")]
        public const int SCHED_E_DEPRECATED_FEATURE_USED = unchecked((int)0x80041330);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CLASS_CREATE_FAILED = unchecked((int)0x80080001);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SCM_ERROR = unchecked((int)0x80080002);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SCM_RPC_FAILURE = unchecked((int)0x80080003);

        [NativeTypeName("HRESULT")]
        public const int CO_E_BAD_PATH = unchecked((int)0x80080004);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_EXEC_FAILURE = unchecked((int)0x80080005);

        [NativeTypeName("HRESULT")]
        public const int CO_E_OBJSRV_RPC_FAILURE = unchecked((int)0x80080006);

        [NativeTypeName("HRESULT")]
        public const int MK_E_NO_NORMALIZED = unchecked((int)0x80080007);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SERVER_STOPPING = unchecked((int)0x80080008);

        [NativeTypeName("HRESULT")]
        public const int MEM_E_INVALID_ROOT = unchecked((int)0x80080009);

        [NativeTypeName("HRESULT")]
        public const int MEM_E_INVALID_LINK = unchecked((int)0x80080010);

        [NativeTypeName("HRESULT")]
        public const int MEM_E_INVALID_SIZE = unchecked((int)0x80080011);

        [NativeTypeName("HRESULT")]
        public const int CO_S_NOTALLINTERFACES = 0x00080012;

        [NativeTypeName("HRESULT")]
        public const int CO_S_MACHINENAMENOTFOUND = 0x00080013;

        [NativeTypeName("HRESULT")]
        public const int CO_E_MISSING_DISPLAYNAME = unchecked((int)0x80080015);

        [NativeTypeName("HRESULT")]
        public const int CO_E_RUNAS_VALUE_MUST_BE_AAA = unchecked((int)0x80080016);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ELEVATION_DISABLED = unchecked((int)0x80080017);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_PACKAGING_INTERNAL = unchecked((int)0x80080200);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INTERLEAVING_NOT_ALLOWED = unchecked((int)0x80080201);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_RELATIONSHIPS_NOT_ALLOWED = unchecked((int)0x80080202);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_MISSING_REQUIRED_FILE = unchecked((int)0x80080203);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_MANIFEST = unchecked((int)0x80080204);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_BLOCKMAP = unchecked((int)0x80080205);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_CORRUPT_CONTENT = unchecked((int)0x80080206);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_BLOCK_HASH_INVALID = unchecked((int)0x80080207);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_REQUESTED_RANGE_TOO_LARGE = unchecked((int)0x80080208);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_SIP_CLIENT_DATA = unchecked((int)0x80080209);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_KEY_INFO = unchecked((int)0x8008020A);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_CONTENTGROUPMAP = unchecked((int)0x8008020B);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_APPINSTALLER = unchecked((int)0x8008020C);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_DELTA_BASELINE_VERSION_MISMATCH = unchecked((int)0x8008020D);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_DELTA_PACKAGE_MISSING_FILE = unchecked((int)0x8008020E);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_DELTA_PACKAGE = unchecked((int)0x8008020F);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_DELTA_APPENDED_PACKAGE_NOT_ALLOWED = unchecked((int)0x80080210);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_PACKAGING_LAYOUT = unchecked((int)0x80080211);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_PACKAGESIGNCONFIG = unchecked((int)0x80080212);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_RESOURCESPRI_NOT_ALLOWED = unchecked((int)0x80080213);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_FILE_COMPRESSION_MISMATCH = unchecked((int)0x80080214);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_PAYLOAD_PACKAGE_EXTENSION = unchecked((int)0x80080215);

        [NativeTypeName("HRESULT")]
        public const int APPX_E_INVALID_ENCRYPTION_EXCLUSION_FILE_LIST = unchecked((int)0x80080216);

        [NativeTypeName("HRESULT")]
        public const int BT_E_SPURIOUS_ACTIVATION = unchecked((int)0x80080300);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_UNKNOWNINTERFACE = unchecked((int)0x80020001);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_MEMBERNOTFOUND = unchecked((int)0x80020003);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_PARAMNOTFOUND = unchecked((int)0x80020004);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_TYPEMISMATCH = unchecked((int)0x80020005);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_UNKNOWNNAME = unchecked((int)0x80020006);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_NONAMEDARGS = unchecked((int)0x80020007);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_BADVARTYPE = unchecked((int)0x80020008);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_EXCEPTION = unchecked((int)0x80020009);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_OVERFLOW = unchecked((int)0x8002000A);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_BADINDEX = unchecked((int)0x8002000B);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_UNKNOWNLCID = unchecked((int)0x8002000C);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_ARRAYISLOCKED = unchecked((int)0x8002000D);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_BADPARAMCOUNT = unchecked((int)0x8002000E);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_PARAMNOTOPTIONAL = unchecked((int)0x8002000F);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_BADCALLEE = unchecked((int)0x80020010);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_NOTACOLLECTION = unchecked((int)0x80020011);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_DIVBYZERO = unchecked((int)0x80020012);

        [NativeTypeName("HRESULT")]
        public const int DISP_E_BUFFERTOOSMALL = unchecked((int)0x80020013);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_BUFFERTOOSMALL = unchecked((int)0x80028016);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_FIELDNOTFOUND = unchecked((int)0x80028017);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_INVDATAREAD = unchecked((int)0x80028018);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_UNSUPFORMAT = unchecked((int)0x80028019);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_REGISTRYACCESS = unchecked((int)0x8002801C);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_LIBNOTREGISTERED = unchecked((int)0x8002801D);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_UNDEFINEDTYPE = unchecked((int)0x80028027);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_QUALIFIEDNAMEDISALLOWED = unchecked((int)0x80028028);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_INVALIDSTATE = unchecked((int)0x80028029);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_WRONGTYPEKIND = unchecked((int)0x8002802A);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_ELEMENTNOTFOUND = unchecked((int)0x8002802B);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_AMBIGUOUSNAME = unchecked((int)0x8002802C);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_NAMECONFLICT = unchecked((int)0x8002802D);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_UNKNOWNLCID = unchecked((int)0x8002802E);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_DLLFUNCTIONNOTFOUND = unchecked((int)0x8002802F);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_BADMODULEKIND = unchecked((int)0x800288BD);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_SIZETOOBIG = unchecked((int)0x800288C5);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_DUPLICATEID = unchecked((int)0x800288C6);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_INVALIDID = unchecked((int)0x800288CF);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_TYPEMISMATCH = unchecked((int)0x80028CA0);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_OUTOFBOUNDS = unchecked((int)0x80028CA1);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_IOERROR = unchecked((int)0x80028CA2);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_CANTCREATETMPFILE = unchecked((int)0x80028CA3);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_CANTLOADLIBRARY = unchecked((int)0x80029C4A);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_INCONSISTENTPROPFUNCS = unchecked((int)0x80029C83);

        [NativeTypeName("HRESULT")]
        public const int TYPE_E_CIRCULARTYPE = unchecked((int)0x80029C84);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDFUNCTION = unchecked((int)0x80030001);

        [NativeTypeName("HRESULT")]
        public const int STG_E_FILENOTFOUND = unchecked((int)0x80030002);

        [NativeTypeName("HRESULT")]
        public const int STG_E_PATHNOTFOUND = unchecked((int)0x80030003);

        [NativeTypeName("HRESULT")]
        public const int STG_E_TOOMANYOPENFILES = unchecked((int)0x80030004);

        [NativeTypeName("HRESULT")]
        public const int STG_E_ACCESSDENIED = unchecked((int)0x80030005);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDHANDLE = unchecked((int)0x80030006);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INSUFFICIENTMEMORY = unchecked((int)0x80030008);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDPOINTER = unchecked((int)0x80030009);

        [NativeTypeName("HRESULT")]
        public const int STG_E_NOMOREFILES = unchecked((int)0x80030012);

        [NativeTypeName("HRESULT")]
        public const int STG_E_DISKISWRITEPROTECTED = unchecked((int)0x80030013);

        [NativeTypeName("HRESULT")]
        public const int STG_E_SEEKERROR = unchecked((int)0x80030019);

        [NativeTypeName("HRESULT")]
        public const int STG_E_WRITEFAULT = unchecked((int)0x8003001D);

        [NativeTypeName("HRESULT")]
        public const int STG_E_READFAULT = unchecked((int)0x8003001E);

        [NativeTypeName("HRESULT")]
        public const int STG_E_SHAREVIOLATION = unchecked((int)0x80030020);

        [NativeTypeName("HRESULT")]
        public const int STG_E_LOCKVIOLATION = unchecked((int)0x80030021);

        [NativeTypeName("HRESULT")]
        public const int STG_E_FILEALREADYEXISTS = unchecked((int)0x80030050);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDPARAMETER = unchecked((int)0x80030057);

        [NativeTypeName("HRESULT")]
        public const int STG_E_MEDIUMFULL = unchecked((int)0x80030070);

        [NativeTypeName("HRESULT")]
        public const int STG_E_PROPSETMISMATCHED = unchecked((int)0x800300F0);

        [NativeTypeName("HRESULT")]
        public const int STG_E_ABNORMALAPIEXIT = unchecked((int)0x800300FA);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDHEADER = unchecked((int)0x800300FB);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDNAME = unchecked((int)0x800300FC);

        [NativeTypeName("HRESULT")]
        public const int STG_E_UNKNOWN = unchecked((int)0x800300FD);

        [NativeTypeName("HRESULT")]
        public const int STG_E_UNIMPLEMENTEDFUNCTION = unchecked((int)0x800300FE);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INVALIDFLAG = unchecked((int)0x800300FF);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INUSE = unchecked((int)0x80030100);

        [NativeTypeName("HRESULT")]
        public const int STG_E_NOTCURRENT = unchecked((int)0x80030101);

        [NativeTypeName("HRESULT")]
        public const int STG_E_REVERTED = unchecked((int)0x80030102);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CANTSAVE = unchecked((int)0x80030103);

        [NativeTypeName("HRESULT")]
        public const int STG_E_OLDFORMAT = unchecked((int)0x80030104);

        [NativeTypeName("HRESULT")]
        public const int STG_E_OLDDLL = unchecked((int)0x80030105);

        [NativeTypeName("HRESULT")]
        public const int STG_E_SHAREREQUIRED = unchecked((int)0x80030106);

        [NativeTypeName("HRESULT")]
        public const int STG_E_NOTFILEBASEDSTORAGE = unchecked((int)0x80030107);

        [NativeTypeName("HRESULT")]
        public const int STG_E_EXTANTMARSHALLINGS = unchecked((int)0x80030108);

        [NativeTypeName("HRESULT")]
        public const int STG_E_DOCFILECORRUPT = unchecked((int)0x80030109);

        [NativeTypeName("HRESULT")]
        public const int STG_E_BADBASEADDRESS = unchecked((int)0x80030110);

        [NativeTypeName("HRESULT")]
        public const int STG_E_DOCFILETOOLARGE = unchecked((int)0x80030111);

        [NativeTypeName("HRESULT")]
        public const int STG_E_NOTSIMPLEFORMAT = unchecked((int)0x80030112);

        [NativeTypeName("HRESULT")]
        public const int STG_E_INCOMPLETE = unchecked((int)0x80030201);

        [NativeTypeName("HRESULT")]
        public const int STG_E_TERMINATED = unchecked((int)0x80030202);

        [NativeTypeName("HRESULT")]
        public const int STG_S_CONVERTED = 0x00030200;

        [NativeTypeName("HRESULT")]
        public const int STG_S_BLOCK = 0x00030201;

        [NativeTypeName("HRESULT")]
        public const int STG_S_RETRYNOW = 0x00030202;

        [NativeTypeName("HRESULT")]
        public const int STG_S_MONITORING = 0x00030203;

        [NativeTypeName("HRESULT")]
        public const int STG_S_MULTIPLEOPENS = 0x00030204;

        [NativeTypeName("HRESULT")]
        public const int STG_S_CONSOLIDATIONFAILED = 0x00030205;

        [NativeTypeName("HRESULT")]
        public const int STG_S_CANNOTCONSOLIDATE = 0x00030206;

        [NativeTypeName("HRESULT")]
        public const int STG_S_POWER_CYCLE_REQUIRED = 0x00030207;

        [NativeTypeName("HRESULT")]
        public const int STG_E_FIRMWARE_SLOT_INVALID = unchecked((int)0x80030208);

        [NativeTypeName("HRESULT")]
        public const int STG_E_FIRMWARE_IMAGE_INVALID = unchecked((int)0x80030209);

        [NativeTypeName("HRESULT")]
        public const int STG_E_DEVICE_UNRESPONSIVE = unchecked((int)0x8003020A);

        [NativeTypeName("HRESULT")]
        public const int STG_E_STATUS_COPY_PROTECTION_FAILURE = unchecked((int)0x80030305);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CSS_AUTHENTICATION_FAILURE = unchecked((int)0x80030306);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CSS_KEY_NOT_PRESENT = unchecked((int)0x80030307);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CSS_KEY_NOT_ESTABLISHED = unchecked((int)0x80030308);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CSS_SCRAMBLED_SECTOR = unchecked((int)0x80030309);

        [NativeTypeName("HRESULT")]
        public const int STG_E_CSS_REGION_MISMATCH = unchecked((int)0x8003030A);

        [NativeTypeName("HRESULT")]
        public const int STG_E_RESETS_EXHAUSTED = unchecked((int)0x8003030B);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CALL_REJECTED = unchecked((int)0x80010001);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CALL_CANCELED = unchecked((int)0x80010002);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTPOST_INSENDCALL = unchecked((int)0x80010003);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTCALLOUT_INASYNCCALL = unchecked((int)0x80010004);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTCALLOUT_INEXTERNALCALL = unchecked((int)0x80010005);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CONNECTION_TERMINATED = unchecked((int)0x80010006);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVER_DIED = unchecked((int)0x80010007);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CLIENT_DIED = unchecked((int)0x80010008);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_DATAPACKET = unchecked((int)0x80010009);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTTRANSMIT_CALL = unchecked((int)0x8001000A);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CLIENT_CANTMARSHAL_DATA = unchecked((int)0x8001000B);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CLIENT_CANTUNMARSHAL_DATA = unchecked((int)0x8001000C);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVER_CANTMARSHAL_DATA = unchecked((int)0x8001000D);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVER_CANTUNMARSHAL_DATA = unchecked((int)0x8001000E);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_DATA = unchecked((int)0x8001000F);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_PARAMETER = unchecked((int)0x80010010);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTCALLOUT_AGAIN = unchecked((int)0x80010011);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVER_DIED_DNE = unchecked((int)0x80010012);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SYS_CALL_FAILED = unchecked((int)0x80010100);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_OUT_OF_RESOURCES = unchecked((int)0x80010101);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_ATTEMPTED_MULTITHREAD = unchecked((int)0x80010102);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_NOT_REGISTERED = unchecked((int)0x80010103);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_FAULT = unchecked((int)0x80010104);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVERFAULT = unchecked((int)0x80010105);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CHANGED_MODE = unchecked((int)0x80010106);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALIDMETHOD = unchecked((int)0x80010107);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_DISCONNECTED = unchecked((int)0x80010108);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_RETRY = unchecked((int)0x80010109);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVERCALL_RETRYLATER = unchecked((int)0x8001010A);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_SERVERCALL_REJECTED = unchecked((int)0x8001010B);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_CALLDATA = unchecked((int)0x8001010C);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CANTCALLOUT_ININPUTSYNCCALL = unchecked((int)0x8001010D);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_WRONG_THREAD = unchecked((int)0x8001010E);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_THREAD_NOT_INIT = unchecked((int)0x8001010F);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_VERSION_MISMATCH = unchecked((int)0x80010110);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_HEADER = unchecked((int)0x80010111);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_EXTENSION = unchecked((int)0x80010112);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_IPID = unchecked((int)0x80010113);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_OBJECT = unchecked((int)0x80010114);

        [NativeTypeName("HRESULT")]
        public const int RPC_S_CALLPENDING = unchecked((int)0x80010115);

        [NativeTypeName("HRESULT")]
        public const int RPC_S_WAITONTIMER = unchecked((int)0x80010116);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_CALL_COMPLETE = unchecked((int)0x80010117);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_UNSECURE_CALL = unchecked((int)0x80010118);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_TOO_LATE = unchecked((int)0x80010119);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_NO_GOOD_SECURITY_PACKAGES = unchecked((int)0x8001011A);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_ACCESS_DENIED = unchecked((int)0x8001011B);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_REMOTE_DISABLED = unchecked((int)0x8001011C);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_OBJREF = unchecked((int)0x8001011D);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_NO_CONTEXT = unchecked((int)0x8001011E);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_TIMEOUT = unchecked((int)0x8001011F);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_NO_SYNC = unchecked((int)0x80010120);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_FULLSIC_REQUIRED = unchecked((int)0x80010121);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_INVALID_STD_NAME = unchecked((int)0x80010122);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOIMPERSONATE = unchecked((int)0x80010123);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOGETSECCTX = unchecked((int)0x80010124);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOOPENTHREADTOKEN = unchecked((int)0x80010125);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOGETTOKENINFO = unchecked((int)0x80010126);

        [NativeTypeName("HRESULT")]
        public const int CO_E_TRUSTEEDOESNTMATCHCLIENT = unchecked((int)0x80010127);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOQUERYCLIENTBLANKET = unchecked((int)0x80010128);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOSETDACL = unchecked((int)0x80010129);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACCESSCHECKFAILED = unchecked((int)0x8001012A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NETACCESSAPIFAILED = unchecked((int)0x8001012B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_WRONGTRUSTEENAMESYNTAX = unchecked((int)0x8001012C);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INVALIDSID = unchecked((int)0x8001012D);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CONVERSIONFAILED = unchecked((int)0x8001012E);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOMATCHINGSIDFOUND = unchecked((int)0x8001012F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_LOOKUPACCSIDFAILED = unchecked((int)0x80010130);

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOMATCHINGNAMEFOUND = unchecked((int)0x80010131);

        [NativeTypeName("HRESULT")]
        public const int CO_E_LOOKUPACCNAMEFAILED = unchecked((int)0x80010132);

        [NativeTypeName("HRESULT")]
        public const int CO_E_SETSERLHNDLFAILED = unchecked((int)0x80010133);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOGETWINDIR = unchecked((int)0x80010134);

        [NativeTypeName("HRESULT")]
        public const int CO_E_PATHTOOLONG = unchecked((int)0x80010135);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOGENUUID = unchecked((int)0x80010136);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOCREATEFILE = unchecked((int)0x80010137);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOCLOSEHANDLE = unchecked((int)0x80010138);

        [NativeTypeName("HRESULT")]
        public const int CO_E_EXCEEDSYSACLLIMIT = unchecked((int)0x80010139);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACESINWRONGORDER = unchecked((int)0x8001013A);

        [NativeTypeName("HRESULT")]
        public const int CO_E_INCOMPATIBLESTREAMVERSION = unchecked((int)0x8001013B);

        [NativeTypeName("HRESULT")]
        public const int CO_E_FAILEDTOOPENPROCESSTOKEN = unchecked((int)0x8001013C);

        [NativeTypeName("HRESULT")]
        public const int CO_E_DECODEFAILED = unchecked((int)0x8001013D);

        [NativeTypeName("HRESULT")]
        public const int CO_E_ACNOTINITIALIZED = unchecked((int)0x8001013F);

        [NativeTypeName("HRESULT")]
        public const int CO_E_CANCEL_DISABLED = unchecked((int)0x80010140);

        [NativeTypeName("HRESULT")]
        public const int RPC_E_UNEXPECTED = unchecked((int)0x8001FFFF);

        [NativeTypeName("HRESULT")]
        public const int ERROR_AUDITING_DISABLED = unchecked((int)0xC0090001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_ALL_SIDS_FILTERED = unchecked((int)0xC0090002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_BIZRULES_NOT_ENABLED = unchecked((int)0xC0090003);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_UID = unchecked((int)0x80090001);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_HASH = unchecked((int)0x80090002);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_KEY = unchecked((int)0x80090003);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_LEN = unchecked((int)0x80090004);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_DATA = unchecked((int)0x80090005);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_SIGNATURE = unchecked((int)0x80090006);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_VER = unchecked((int)0x80090007);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_ALGID = unchecked((int)0x80090008);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_FLAGS = unchecked((int)0x80090009);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_TYPE = unchecked((int)0x8009000A);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_KEY_STATE = unchecked((int)0x8009000B);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_HASH_STATE = unchecked((int)0x8009000C);

        [NativeTypeName("HRESULT")]
        public const int NTE_NO_KEY = unchecked((int)0x8009000D);

        [NativeTypeName("HRESULT")]
        public const int NTE_NO_MEMORY = unchecked((int)0x8009000E);

        [NativeTypeName("HRESULT")]
        public const int NTE_EXISTS = unchecked((int)0x8009000F);

        [NativeTypeName("HRESULT")]
        public const int NTE_PERM = unchecked((int)0x80090010);

        [NativeTypeName("HRESULT")]
        public const int NTE_NOT_FOUND = unchecked((int)0x80090011);

        [NativeTypeName("HRESULT")]
        public const int NTE_DOUBLE_ENCRYPT = unchecked((int)0x80090012);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_PROVIDER = unchecked((int)0x80090013);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_PROV_TYPE = unchecked((int)0x80090014);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_PUBLIC_KEY = unchecked((int)0x80090015);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_KEYSET = unchecked((int)0x80090016);

        [NativeTypeName("HRESULT")]
        public const int NTE_PROV_TYPE_NOT_DEF = unchecked((int)0x80090017);

        [NativeTypeName("HRESULT")]
        public const int NTE_PROV_TYPE_ENTRY_BAD = unchecked((int)0x80090018);

        [NativeTypeName("HRESULT")]
        public const int NTE_KEYSET_NOT_DEF = unchecked((int)0x80090019);

        [NativeTypeName("HRESULT")]
        public const int NTE_KEYSET_ENTRY_BAD = unchecked((int)0x8009001A);

        [NativeTypeName("HRESULT")]
        public const int NTE_PROV_TYPE_NO_MATCH = unchecked((int)0x8009001B);

        [NativeTypeName("HRESULT")]
        public const int NTE_SIGNATURE_FILE_BAD = unchecked((int)0x8009001C);

        [NativeTypeName("HRESULT")]
        public const int NTE_PROVIDER_DLL_FAIL = unchecked((int)0x8009001D);

        [NativeTypeName("HRESULT")]
        public const int NTE_PROV_DLL_NOT_FOUND = unchecked((int)0x8009001E);

        [NativeTypeName("HRESULT")]
        public const int NTE_BAD_KEYSET_PARAM = unchecked((int)0x8009001F);

        [NativeTypeName("HRESULT")]
        public const int NTE_FAIL = unchecked((int)0x80090020);

        [NativeTypeName("HRESULT")]
        public const int NTE_SYS_ERR = unchecked((int)0x80090021);

        [NativeTypeName("HRESULT")]
        public const int NTE_SILENT_CONTEXT = unchecked((int)0x80090022);

        [NativeTypeName("HRESULT")]
        public const int NTE_TOKEN_KEYSET_STORAGE_FULL = unchecked((int)0x80090023);

        [NativeTypeName("HRESULT")]
        public const int NTE_TEMPORARY_PROFILE = unchecked((int)0x80090024);

        [NativeTypeName("HRESULT")]
        public const int NTE_FIXEDPARAMETER = unchecked((int)0x80090025);

        [NativeTypeName("HRESULT")]
        public const int NTE_INVALID_HANDLE = unchecked((int)0x80090026);

        [NativeTypeName("HRESULT")]
        public const int NTE_INVALID_PARAMETER = unchecked((int)0x80090027);

        [NativeTypeName("HRESULT")]
        public const int NTE_BUFFER_TOO_SMALL = unchecked((int)0x80090028);

        [NativeTypeName("HRESULT")]
        public const int NTE_NOT_SUPPORTED = unchecked((int)0x80090029);

        [NativeTypeName("HRESULT")]
        public const int NTE_NO_MORE_ITEMS = unchecked((int)0x8009002A);

        [NativeTypeName("HRESULT")]
        public const int NTE_BUFFERS_OVERLAP = unchecked((int)0x8009002B);

        [NativeTypeName("HRESULT")]
        public const int NTE_DECRYPTION_FAILURE = unchecked((int)0x8009002C);

        [NativeTypeName("HRESULT")]
        public const int NTE_INTERNAL_ERROR = unchecked((int)0x8009002D);

        [NativeTypeName("HRESULT")]
        public const int NTE_UI_REQUIRED = unchecked((int)0x8009002E);

        [NativeTypeName("HRESULT")]
        public const int NTE_HMAC_NOT_SUPPORTED = unchecked((int)0x8009002F);

        [NativeTypeName("HRESULT")]
        public const int NTE_DEVICE_NOT_READY = unchecked((int)0x80090030);

        [NativeTypeName("HRESULT")]
        public const int NTE_AUTHENTICATION_IGNORED = unchecked((int)0x80090031);

        [NativeTypeName("HRESULT")]
        public const int NTE_VALIDATION_FAILED = unchecked((int)0x80090032);

        [NativeTypeName("HRESULT")]
        public const int NTE_INCORRECT_PASSWORD = unchecked((int)0x80090033);

        [NativeTypeName("HRESULT")]
        public const int NTE_ENCRYPTION_FAILURE = unchecked((int)0x80090034);

        [NativeTypeName("HRESULT")]
        public const int NTE_DEVICE_NOT_FOUND = unchecked((int)0x80090035);

        [NativeTypeName("HRESULT")]
        public const int NTE_USER_CANCELLED = unchecked((int)0x80090036);

        [NativeTypeName("HRESULT")]
        public const int NTE_PASSWORD_CHANGE_REQUIRED = unchecked((int)0x80090037);

        [NativeTypeName("HRESULT")]
        public const int NTE_NOT_ACTIVE_CONSOLE = unchecked((int)0x80090038);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INSUFFICIENT_MEMORY = unchecked((int)0x80090300);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INVALID_HANDLE = unchecked((int)0x80090301);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_UNSUPPORTED_FUNCTION = unchecked((int)0x80090302);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_TARGET_UNKNOWN = unchecked((int)0x80090303);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INTERNAL_ERROR = unchecked((int)0x80090304);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SECPKG_NOT_FOUND = unchecked((int)0x80090305);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NOT_OWNER = unchecked((int)0x80090306);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CANNOT_INSTALL = unchecked((int)0x80090307);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INVALID_TOKEN = unchecked((int)0x80090308);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CANNOT_PACK = unchecked((int)0x80090309);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_QOP_NOT_SUPPORTED = unchecked((int)0x8009030A);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_IMPERSONATION = unchecked((int)0x8009030B);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_LOGON_DENIED = unchecked((int)0x8009030C);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_UNKNOWN_CREDENTIALS = unchecked((int)0x8009030D);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_CREDENTIALS = unchecked((int)0x8009030E);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_MESSAGE_ALTERED = unchecked((int)0x8009030F);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_OUT_OF_SEQUENCE = unchecked((int)0x80090310);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_AUTHENTICATING_AUTHORITY = unchecked((int)0x80090311);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_CONTINUE_NEEDED = 0x00090312;

        [NativeTypeName("HRESULT")]
        public const int SEC_I_COMPLETE_NEEDED = 0x00090313;

        [NativeTypeName("HRESULT")]
        public const int SEC_I_COMPLETE_AND_CONTINUE = 0x00090314;

        [NativeTypeName("HRESULT")]
        public const int SEC_I_LOCAL_LOGON = 0x00090315;

        [NativeTypeName("HRESULT")]
        public const int SEC_I_GENERIC_EXTENSION_RECEIVED = 0x00090316;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_BAD_PKGID = unchecked((int)0x80090316);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CONTEXT_EXPIRED = unchecked((int)0x80090317);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_CONTEXT_EXPIRED = 0x00090317;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INCOMPLETE_MESSAGE = unchecked((int)0x80090318);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INCOMPLETE_CREDENTIALS = unchecked((int)0x80090320);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_BUFFER_TOO_SMALL = unchecked((int)0x80090321);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_INCOMPLETE_CREDENTIALS = 0x00090320;

        [NativeTypeName("HRESULT")]
        public const int SEC_I_RENEGOTIATE = 0x00090321;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_WRONG_PRINCIPAL = unchecked((int)0x80090322);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_NO_LSA_CONTEXT = 0x00090323;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_TIME_SKEW = unchecked((int)0x80090324);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_UNTRUSTED_ROOT = unchecked((int)0x80090325);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ILLEGAL_MESSAGE = unchecked((int)0x80090326);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CERT_UNKNOWN = unchecked((int)0x80090327);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CERT_EXPIRED = unchecked((int)0x80090328);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ENCRYPT_FAILURE = unchecked((int)0x80090329);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_DECRYPT_FAILURE = unchecked((int)0x80090330);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ALGORITHM_MISMATCH = unchecked((int)0x80090331);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SECURITY_QOS_FAILED = unchecked((int)0x80090332);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_UNFINISHED_CONTEXT_DELETED = unchecked((int)0x80090333);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_TGT_REPLY = unchecked((int)0x80090334);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_IP_ADDRESSES = unchecked((int)0x80090335);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_WRONG_CREDENTIAL_HANDLE = unchecked((int)0x80090336);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CRYPTO_SYSTEM_INVALID = unchecked((int)0x80090337);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_MAX_REFERRALS_EXCEEDED = unchecked((int)0x80090338);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_MUST_BE_KDC = unchecked((int)0x80090339);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_STRONG_CRYPTO_NOT_SUPPORTED = unchecked((int)0x8009033A);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_TOO_MANY_PRINCIPALS = unchecked((int)0x8009033B);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_PA_DATA = unchecked((int)0x8009033C);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_PKINIT_NAME_MISMATCH = unchecked((int)0x8009033D);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SMARTCARD_LOGON_REQUIRED = unchecked((int)0x8009033E);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SHUTDOWN_IN_PROGRESS = unchecked((int)0x8009033F);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_KDC_INVALID_REQUEST = unchecked((int)0x80090340);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_KDC_UNABLE_TO_REFER = unchecked((int)0x80090341);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_KDC_UNKNOWN_ETYPE = unchecked((int)0x80090342);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_UNSUPPORTED_PREAUTH = unchecked((int)0x80090343);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_DELEGATION_REQUIRED = unchecked((int)0x80090345);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_BAD_BINDINGS = unchecked((int)0x80090346);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_MULTIPLE_ACCOUNTS = unchecked((int)0x80090347);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_KERB_KEY = unchecked((int)0x80090348);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CERT_WRONG_USAGE = unchecked((int)0x80090349);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_DOWNGRADE_DETECTED = unchecked((int)0x80090350);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SMARTCARD_CERT_REVOKED = unchecked((int)0x80090351);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ISSUING_CA_UNTRUSTED = unchecked((int)0x80090352);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_REVOCATION_OFFLINE_C = unchecked((int)0x80090353);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_PKINIT_CLIENT_FAILURE = unchecked((int)0x80090354);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_SMARTCARD_CERT_EXPIRED = unchecked((int)0x80090355);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_S4U_PROT_SUPPORT = unchecked((int)0x80090356);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_CROSSREALM_DELEGATION_FAILURE = unchecked((int)0x80090357);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_REVOCATION_OFFLINE_KDC = unchecked((int)0x80090358);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ISSUING_CA_UNTRUSTED_KDC = unchecked((int)0x80090359);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_KDC_CERT_EXPIRED = unchecked((int)0x8009035A);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_KDC_CERT_REVOKED = unchecked((int)0x8009035B);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_SIGNATURE_NEEDED = 0x0009035C;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INVALID_PARAMETER = unchecked((int)0x8009035D);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_DELEGATION_POLICY = unchecked((int)0x8009035E);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_POLICY_NLTM_ONLY = unchecked((int)0x8009035F);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_NO_RENEGOTIATION = 0x00090360;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_NO_CONTEXT = unchecked((int)0x80090361);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_PKU2U_CERT_FAILURE = unchecked((int)0x80090362);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_MUTUAL_AUTH_FAILED = unchecked((int)0x80090363);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_MESSAGE_FRAGMENT = 0x00090364;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_ONLY_HTTPS_ALLOWED = unchecked((int)0x80090365);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_CONTINUE_NEEDED_MESSAGE_OK = 0x00090366;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_APPLICATION_PROTOCOL_MISMATCH = unchecked((int)0x80090367);

        [NativeTypeName("HRESULT")]
        public const int SEC_I_ASYNC_CALL_PENDING = 0x00090368;

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INVALID_UPN_NAME = unchecked((int)0x80090369);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_EXT_BUFFER_TOO_SMALL = unchecked((int)0x8009036A);

        [NativeTypeName("HRESULT")]
        public const int SEC_E_INSUFFICIENT_BUFFERS = unchecked((int)0x8009036B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_MSG_ERROR = unchecked((int)0x80091001);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_UNKNOWN_ALGO = unchecked((int)0x80091002);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_OID_FORMAT = unchecked((int)0x80091003);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_MSG_TYPE = unchecked((int)0x80091004);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_UNEXPECTED_ENCODING = unchecked((int)0x80091005);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_AUTH_ATTR_MISSING = unchecked((int)0x80091006);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_HASH_VALUE = unchecked((int)0x80091007);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_INDEX = unchecked((int)0x80091008);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ALREADY_DECRYPTED = unchecked((int)0x80091009);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NOT_DECRYPTED = unchecked((int)0x8009100A);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_RECIPIENT_NOT_FOUND = unchecked((int)0x8009100B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_CONTROL_TYPE = unchecked((int)0x8009100C);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ISSUER_SERIALNUMBER = unchecked((int)0x8009100D);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_SIGNER_NOT_FOUND = unchecked((int)0x8009100E);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ATTRIBUTES_MISSING = unchecked((int)0x8009100F);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_STREAM_MSG_NOT_READY = unchecked((int)0x80091010);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_STREAM_INSUFFICIENT_DATA = unchecked((int)0x80091011);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_I_NEW_PROTECTION_REQUIRED = 0x00091012;

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_BAD_LEN = unchecked((int)0x80092001);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_BAD_ENCODE = unchecked((int)0x80092002);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_FILE_ERROR = unchecked((int)0x80092003);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NOT_FOUND = unchecked((int)0x80092004);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_EXISTS = unchecked((int)0x80092005);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_PROVIDER = unchecked((int)0x80092006);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_SELF_SIGNED = unchecked((int)0x80092007);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_DELETED_PREV = unchecked((int)0x80092008);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_MATCH = unchecked((int)0x80092009);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_UNEXPECTED_MSG_TYPE = unchecked((int)0x8009200A);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_KEY_PROPERTY = unchecked((int)0x8009200B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_DECRYPT_CERT = unchecked((int)0x8009200C);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_BAD_MSG = unchecked((int)0x8009200D);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_SIGNER = unchecked((int)0x8009200E);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_PENDING_CLOSE = unchecked((int)0x8009200F);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_REVOKED = unchecked((int)0x80092010);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_REVOCATION_DLL = unchecked((int)0x80092011);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_REVOCATION_CHECK = unchecked((int)0x80092012);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_REVOCATION_OFFLINE = unchecked((int)0x80092013);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NOT_IN_REVOCATION_DATABASE = unchecked((int)0x80092014);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_NUMERIC_STRING = unchecked((int)0x80092020);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_PRINTABLE_STRING = unchecked((int)0x80092021);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_IA5_STRING = unchecked((int)0x80092022);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_INVALID_X500_STRING = unchecked((int)0x80092023);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NOT_CHAR_STRING = unchecked((int)0x80092024);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_FILERESIZED = unchecked((int)0x80092025);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_SECURITY_SETTINGS = unchecked((int)0x80092026);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_VERIFY_USAGE_DLL = unchecked((int)0x80092027);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_VERIFY_USAGE_CHECK = unchecked((int)0x80092028);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_VERIFY_USAGE_OFFLINE = unchecked((int)0x80092029);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NOT_IN_CTL = unchecked((int)0x8009202A);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_NO_TRUSTED_SIGNER = unchecked((int)0x8009202B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_MISSING_PUBKEY_PARA = unchecked((int)0x8009202C);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_OBJECT_LOCATOR_OBJECT_NOT_FOUND = unchecked((int)0x8009202D);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_OSS_ERROR = unchecked((int)0x80093000);

        [NativeTypeName("HRESULT")]
        public const int OSS_MORE_BUF = unchecked((int)0x80093001);

        [NativeTypeName("HRESULT")]
        public const int OSS_NEGATIVE_UINTEGER = unchecked((int)0x80093002);

        [NativeTypeName("HRESULT")]
        public const int OSS_PDU_RANGE = unchecked((int)0x80093003);

        [NativeTypeName("HRESULT")]
        public const int OSS_MORE_INPUT = unchecked((int)0x80093004);

        [NativeTypeName("HRESULT")]
        public const int OSS_DATA_ERROR = unchecked((int)0x80093005);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_ARG = unchecked((int)0x80093006);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_VERSION = unchecked((int)0x80093007);

        [NativeTypeName("HRESULT")]
        public const int OSS_OUT_MEMORY = unchecked((int)0x80093008);

        [NativeTypeName("HRESULT")]
        public const int OSS_PDU_MISMATCH = unchecked((int)0x80093009);

        [NativeTypeName("HRESULT")]
        public const int OSS_LIMITED = unchecked((int)0x8009300A);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_PTR = unchecked((int)0x8009300B);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_TIME = unchecked((int)0x8009300C);

        [NativeTypeName("HRESULT")]
        public const int OSS_INDEFINITE_NOT_SUPPORTED = unchecked((int)0x8009300D);

        [NativeTypeName("HRESULT")]
        public const int OSS_MEM_ERROR = unchecked((int)0x8009300E);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_TABLE = unchecked((int)0x8009300F);

        [NativeTypeName("HRESULT")]
        public const int OSS_TOO_LONG = unchecked((int)0x80093010);

        [NativeTypeName("HRESULT")]
        public const int OSS_CONSTRAINT_VIOLATED = unchecked((int)0x80093011);

        [NativeTypeName("HRESULT")]
        public const int OSS_FATAL_ERROR = unchecked((int)0x80093012);

        [NativeTypeName("HRESULT")]
        public const int OSS_ACCESS_SERIALIZATION_ERROR = unchecked((int)0x80093013);

        [NativeTypeName("HRESULT")]
        public const int OSS_NULL_TBL = unchecked((int)0x80093014);

        [NativeTypeName("HRESULT")]
        public const int OSS_NULL_FCN = unchecked((int)0x80093015);

        [NativeTypeName("HRESULT")]
        public const int OSS_BAD_ENCRULES = unchecked((int)0x80093016);

        [NativeTypeName("HRESULT")]
        public const int OSS_UNAVAIL_ENCRULES = unchecked((int)0x80093017);

        [NativeTypeName("HRESULT")]
        public const int OSS_CANT_OPEN_TRACE_WINDOW = unchecked((int)0x80093018);

        [NativeTypeName("HRESULT")]
        public const int OSS_UNIMPLEMENTED = unchecked((int)0x80093019);

        [NativeTypeName("HRESULT")]
        public const int OSS_OID_DLL_NOT_LINKED = unchecked((int)0x8009301A);

        [NativeTypeName("HRESULT")]
        public const int OSS_CANT_OPEN_TRACE_FILE = unchecked((int)0x8009301B);

        [NativeTypeName("HRESULT")]
        public const int OSS_TRACE_FILE_ALREADY_OPEN = unchecked((int)0x8009301C);

        [NativeTypeName("HRESULT")]
        public const int OSS_TABLE_MISMATCH = unchecked((int)0x8009301D);

        [NativeTypeName("HRESULT")]
        public const int OSS_TYPE_NOT_SUPPORTED = unchecked((int)0x8009301E);

        [NativeTypeName("HRESULT")]
        public const int OSS_REAL_DLL_NOT_LINKED = unchecked((int)0x8009301F);

        [NativeTypeName("HRESULT")]
        public const int OSS_REAL_CODE_NOT_LINKED = unchecked((int)0x80093020);

        [NativeTypeName("HRESULT")]
        public const int OSS_OUT_OF_RANGE = unchecked((int)0x80093021);

        [NativeTypeName("HRESULT")]
        public const int OSS_COPIER_DLL_NOT_LINKED = unchecked((int)0x80093022);

        [NativeTypeName("HRESULT")]
        public const int OSS_CONSTRAINT_DLL_NOT_LINKED = unchecked((int)0x80093023);

        [NativeTypeName("HRESULT")]
        public const int OSS_COMPARATOR_DLL_NOT_LINKED = unchecked((int)0x80093024);

        [NativeTypeName("HRESULT")]
        public const int OSS_COMPARATOR_CODE_NOT_LINKED = unchecked((int)0x80093025);

        [NativeTypeName("HRESULT")]
        public const int OSS_MEM_MGR_DLL_NOT_LINKED = unchecked((int)0x80093026);

        [NativeTypeName("HRESULT")]
        public const int OSS_PDV_DLL_NOT_LINKED = unchecked((int)0x80093027);

        [NativeTypeName("HRESULT")]
        public const int OSS_PDV_CODE_NOT_LINKED = unchecked((int)0x80093028);

        [NativeTypeName("HRESULT")]
        public const int OSS_API_DLL_NOT_LINKED = unchecked((int)0x80093029);

        [NativeTypeName("HRESULT")]
        public const int OSS_BERDER_DLL_NOT_LINKED = unchecked((int)0x8009302A);

        [NativeTypeName("HRESULT")]
        public const int OSS_PER_DLL_NOT_LINKED = unchecked((int)0x8009302B);

        [NativeTypeName("HRESULT")]
        public const int OSS_OPEN_TYPE_ERROR = unchecked((int)0x8009302C);

        [NativeTypeName("HRESULT")]
        public const int OSS_MUTEX_NOT_CREATED = unchecked((int)0x8009302D);

        [NativeTypeName("HRESULT")]
        public const int OSS_CANT_CLOSE_TRACE_FILE = unchecked((int)0x8009302E);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_ERROR = unchecked((int)0x80093100);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_INTERNAL = unchecked((int)0x80093101);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_EOD = unchecked((int)0x80093102);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_CORRUPT = unchecked((int)0x80093103);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_LARGE = unchecked((int)0x80093104);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_CONSTRAINT = unchecked((int)0x80093105);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_MEMORY = unchecked((int)0x80093106);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_OVERFLOW = unchecked((int)0x80093107);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_BADPDU = unchecked((int)0x80093108);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_BADARGS = unchecked((int)0x80093109);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_BADREAL = unchecked((int)0x8009310A);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_BADTAG = unchecked((int)0x8009310B);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_CHOICE = unchecked((int)0x8009310C);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_RULE = unchecked((int)0x8009310D);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_UTF8 = unchecked((int)0x8009310E);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_PDU_TYPE = unchecked((int)0x80093133);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_NYI = unchecked((int)0x80093134);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_EXTENDED = unchecked((int)0x80093201);

        [NativeTypeName("HRESULT")]
        public const int CRYPT_E_ASN1_NOEOD = unchecked((int)0x80093202);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_REQUESTSUBJECT = unchecked((int)0x80094001);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_REQUEST = unchecked((int)0x80094002);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_REQUESTSTATUS = unchecked((int)0x80094003);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_PROPERTY_EMPTY = unchecked((int)0x80094004);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_CA_CERTIFICATE = unchecked((int)0x80094005);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SERVER_SUSPENDED = unchecked((int)0x80094006);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ENCODING_LENGTH = unchecked((int)0x80094007);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ROLECONFLICT = unchecked((int)0x80094008);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_RESTRICTEDOFFICER = unchecked((int)0x80094009);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED = unchecked((int)0x8009400A);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_VALID_KRA = unchecked((int)0x8009400B);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL = unchecked((int)0x8009400C);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_CAADMIN_DEFINED = unchecked((int)0x8009400D);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE = unchecked((int)0x8009400E);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_DB_SESSIONS = unchecked((int)0x8009400F);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ALIGNMENT_FAULT = unchecked((int)0x80094010);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ENROLL_DENIED = unchecked((int)0x80094011);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_TEMPLATE_DENIED = unchecked((int)0x80094012);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE = unchecked((int)0x80094013);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ADMIN_DENIED_REQUEST = unchecked((int)0x80094014);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_POLICY_SERVER = unchecked((int)0x80094015);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_WEAK_SIGNATURE_OR_KEY = unchecked((int)0x80094016);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_KEY_ATTESTATION_NOT_SUPPORTED = unchecked((int)0x80094017);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ENCRYPTION_CERT_REQUIRED = unchecked((int)0x80094018);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_UNSUPPORTED_CERT_TYPE = unchecked((int)0x80094800);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_NO_CERT_TYPE = unchecked((int)0x80094801);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_TEMPLATE_CONFLICT = unchecked((int)0x80094802);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED = unchecked((int)0x80094803);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ARCHIVED_KEY_REQUIRED = unchecked((int)0x80094804);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SMIME_REQUIRED = unchecked((int)0x80094805);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_RENEWAL_SUBJECT = unchecked((int)0x80094806);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_BAD_TEMPLATE_VERSION = unchecked((int)0x80094807);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_TEMPLATE_POLICY_REQUIRED = unchecked((int)0x80094808);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SIGNATURE_POLICY_REQUIRED = unchecked((int)0x80094809);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SIGNATURE_COUNT = unchecked((int)0x8009480A);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SIGNATURE_REJECTED = unchecked((int)0x8009480B);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ISSUANCE_POLICY_REQUIRED = unchecked((int)0x8009480C);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SUBJECT_UPN_REQUIRED = unchecked((int)0x8009480D);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED = unchecked((int)0x8009480E);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SUBJECT_DNS_REQUIRED = unchecked((int)0x8009480F);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_ARCHIVED_KEY_UNEXPECTED = unchecked((int)0x80094810);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_KEY_LENGTH = unchecked((int)0x80094811);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_SUBJECT_EMAIL_REQUIRED = unchecked((int)0x80094812);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_UNKNOWN_CERT_TYPE = unchecked((int)0x80094813);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_CERT_TYPE_OVERLAP = unchecked((int)0x80094814);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_TOO_MANY_SIGNATURES = unchecked((int)0x80094815);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_RENEWAL_BAD_PUBLIC_KEY = unchecked((int)0x80094816);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_EK = unchecked((int)0x80094817);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_IDBINDING = unchecked((int)0x80094818);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_ATTESTATION = unchecked((int)0x80094819);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_KEY_ATTESTATION = unchecked((int)0x8009481A);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_CORRUPT_KEY_ATTESTATION = unchecked((int)0x8009481B);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_EXPIRED_CHALLENGE = unchecked((int)0x8009481C);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_RESPONSE = unchecked((int)0x8009481D);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_INVALID_REQUESTID = unchecked((int)0x8009481E);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_REQUEST_PRECERTIFICATE_MISMATCH = unchecked((int)0x8009481F);

        [NativeTypeName("HRESULT")]
        public const int CERTSRV_E_PENDING_CLIENT_RESPONSE = unchecked((int)0x80094820);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_KEY_NOT_EXPORTABLE = unchecked((int)0x80095000);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_CANNOT_ADD_ROOT_CERT = unchecked((int)0x80095001);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND = unchecked((int)0x80095002);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH = unchecked((int)0x80095003);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_RESPONSE_KA_HASH_MISMATCH = unchecked((int)0x80095004);

        [NativeTypeName("HRESULT")]
        public const int XENROLL_E_KEYSPEC_SMIME_MISMATCH = unchecked((int)0x80095005);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_SYSTEM_ERROR = unchecked((int)0x80096001);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_NO_SIGNER_CERT = unchecked((int)0x80096002);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_COUNTER_SIGNER = unchecked((int)0x80096003);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_CERT_SIGNATURE = unchecked((int)0x80096004);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_TIME_STAMP = unchecked((int)0x80096005);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_BAD_DIGEST = unchecked((int)0x80096010);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_MALFORMED_SIGNATURE = unchecked((int)0x80096011);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_BASIC_CONSTRAINTS = unchecked((int)0x80096019);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_FINANCIAL_CRITERIA = unchecked((int)0x8009601E);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_OUTOFMEMRANGE = unchecked((int)0x80097001);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_CANTGETOBJECT = unchecked((int)0x80097002);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_NOHEADTABLE = unchecked((int)0x80097003);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_BAD_MAGICNUMBER = unchecked((int)0x80097004);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_BAD_OFFSET_TABLE = unchecked((int)0x80097005);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_TABLE_TAGORDER = unchecked((int)0x80097006);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_TABLE_LONGWORD = unchecked((int)0x80097007);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT = unchecked((int)0x80097008);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_TABLES_OVERLAP = unchecked((int)0x80097009);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_TABLE_PADBYTES = unchecked((int)0x8009700A);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_FILETOOSMALL = unchecked((int)0x8009700B);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_TABLE_CHECKSUM = unchecked((int)0x8009700C);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_FILE_CHECKSUM = unchecked((int)0x8009700D);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_FAILED_POLICY = unchecked((int)0x80097010);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_FAILED_HINTS_CHECK = unchecked((int)0x80097011);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_NOT_OPENTYPE = unchecked((int)0x80097012);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_FILE = unchecked((int)0x80097013);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_CRYPT = unchecked((int)0x80097014);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_BADVERSION = unchecked((int)0x80097015);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_DSIG_STRUCTURE = unchecked((int)0x80097016);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_PCONST_CHECK = unchecked((int)0x80097017);

        [NativeTypeName("HRESULT")]
        public const int MSSIPOTF_E_STRUCTURE = unchecked((int)0x80097018);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CRED_REQUIRES_CONFIRMATION = unchecked((int)0x80097019);

        public const uint NTE_OP_OK = 0;

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_PROVIDER_UNKNOWN = unchecked((int)0x800B0001);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_ACTION_UNKNOWN = unchecked((int)0x800B0002);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_SUBJECT_FORM_UNKNOWN = unchecked((int)0x800B0003);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_SUBJECT_NOT_TRUSTED = unchecked((int)0x800B0004);

        [NativeTypeName("HRESULT")]
        public const int DIGSIG_E_ENCODE = unchecked((int)0x800B0005);

        [NativeTypeName("HRESULT")]
        public const int DIGSIG_E_DECODE = unchecked((int)0x800B0006);

        [NativeTypeName("HRESULT")]
        public const int DIGSIG_E_EXTENSIBILITY = unchecked((int)0x800B0007);

        [NativeTypeName("HRESULT")]
        public const int DIGSIG_E_CRYPTO = unchecked((int)0x800B0008);

        [NativeTypeName("HRESULT")]
        public const int PERSIST_E_SIZEDEFINITE = unchecked((int)0x800B0009);

        [NativeTypeName("HRESULT")]
        public const int PERSIST_E_SIZEINDEFINITE = unchecked((int)0x800B000A);

        [NativeTypeName("HRESULT")]
        public const int PERSIST_E_NOTSELFSIZING = unchecked((int)0x800B000B);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_NOSIGNATURE = unchecked((int)0x800B0100);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_EXPIRED = unchecked((int)0x800B0101);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_VALIDITYPERIODNESTING = unchecked((int)0x800B0102);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_ROLE = unchecked((int)0x800B0103);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_PATHLENCONST = unchecked((int)0x800B0104);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_CRITICAL = unchecked((int)0x800B0105);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_PURPOSE = unchecked((int)0x800B0106);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_ISSUERCHAINING = unchecked((int)0x800B0107);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_MALFORMED = unchecked((int)0x800B0108);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_UNTRUSTEDROOT = unchecked((int)0x800B0109);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_CHAINING = unchecked((int)0x800B010A);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_FAIL = unchecked((int)0x800B010B);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_REVOKED = unchecked((int)0x800B010C);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_UNTRUSTEDTESTROOT = unchecked((int)0x800B010D);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_REVOCATION_FAILURE = unchecked((int)0x800B010E);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_CN_NO_MATCH = unchecked((int)0x800B010F);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_WRONG_USAGE = unchecked((int)0x800B0110);

        [NativeTypeName("HRESULT")]
        public const int TRUST_E_EXPLICIT_DISTRUST = unchecked((int)0x800B0111);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_UNTRUSTEDCA = unchecked((int)0x800B0112);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_INVALID_POLICY = unchecked((int)0x800B0113);

        [NativeTypeName("HRESULT")]
        public const int CERT_E_INVALID_NAME = unchecked((int)0x800B0114);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_EXPECTED_SECTION_NAME = unchecked((int)0x800F0000);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_BAD_SECTION_NAME_LINE = unchecked((int)0x800F0001);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_SECTION_NAME_TOO_LONG = unchecked((int)0x800F0002);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_GENERAL_SYNTAX = unchecked((int)0x800F0003);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_WRONG_INF_STYLE = unchecked((int)0x800F0100);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_SECTION_NOT_FOUND = unchecked((int)0x800F0101);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_LINE_NOT_FOUND = unchecked((int)0x800F0102);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_BACKUP = unchecked((int)0x800F0103);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_ASSOCIATED_CLASS = unchecked((int)0x800F0200);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_CLASS_MISMATCH = unchecked((int)0x800F0201);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DUPLICATE_FOUND = unchecked((int)0x800F0202);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_DRIVER_SELECTED = unchecked((int)0x800F0203);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_KEY_DOES_NOT_EXIST = unchecked((int)0x800F0204);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_DEVINST_NAME = unchecked((int)0x800F0205);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_CLASS = unchecked((int)0x800F0206);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVINST_ALREADY_EXISTS = unchecked((int)0x800F0207);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVINFO_NOT_REGISTERED = unchecked((int)0x800F0208);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_REG_PROPERTY = unchecked((int)0x800F0209);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_INF = unchecked((int)0x800F020A);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_SUCH_DEVINST = unchecked((int)0x800F020B);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_CANT_LOAD_CLASS_ICON = unchecked((int)0x800F020C);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_CLASS_INSTALLER = unchecked((int)0x800F020D);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_DO_DEFAULT = unchecked((int)0x800F020E);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_NOFILECOPY = unchecked((int)0x800F020F);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_HWPROFILE = unchecked((int)0x800F0210);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_DEVICE_SELECTED = unchecked((int)0x800F0211);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVINFO_LIST_LOCKED = unchecked((int)0x800F0212);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVINFO_DATA_LOCKED = unchecked((int)0x800F0213);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_BAD_PATH = unchecked((int)0x800F0214);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_CLASSINSTALL_PARAMS = unchecked((int)0x800F0215);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_FILEQUEUE_LOCKED = unchecked((int)0x800F0216);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_BAD_SERVICE_INSTALLSECT = unchecked((int)0x800F0217);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_CLASS_DRIVER_LIST = unchecked((int)0x800F0218);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_ASSOCIATED_SERVICE = unchecked((int)0x800F0219);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE = unchecked((int)0x800F021A);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVICE_INTERFACE_ACTIVE = unchecked((int)0x800F021B);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVICE_INTERFACE_REMOVED = unchecked((int)0x800F021C);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_BAD_INTERFACE_INSTALLSECT = unchecked((int)0x800F021D);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_SUCH_INTERFACE_CLASS = unchecked((int)0x800F021E);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_REFERENCE_STRING = unchecked((int)0x800F021F);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_MACHINENAME = unchecked((int)0x800F0220);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_REMOTE_COMM_FAILURE = unchecked((int)0x800F0221);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_MACHINE_UNAVAILABLE = unchecked((int)0x800F0222);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_CONFIGMGR_SERVICES = unchecked((int)0x800F0223);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_PROPPAGE_PROVIDER = unchecked((int)0x800F0224);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_SUCH_DEVICE_INTERFACE = unchecked((int)0x800F0225);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_POSTPROCESSING_REQUIRED = unchecked((int)0x800F0226);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_COINSTALLER = unchecked((int)0x800F0227);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_COMPAT_DRIVERS = unchecked((int)0x800F0228);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_DEVICE_ICON = unchecked((int)0x800F0229);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_INF_LOGCONFIG = unchecked((int)0x800F022A);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_DONT_INSTALL = unchecked((int)0x800F022B);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_FILTER_DRIVER = unchecked((int)0x800F022C);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NON_WINDOWS_NT_DRIVER = unchecked((int)0x800F022D);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NON_WINDOWS_DRIVER = unchecked((int)0x800F022E);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_CATALOG_FOR_OEM_INF = unchecked((int)0x800F022F);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE = unchecked((int)0x800F0230);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NOT_DISABLEABLE = unchecked((int)0x800F0231);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_CANT_REMOVE_DEVINST = unchecked((int)0x800F0232);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INVALID_TARGET = unchecked((int)0x800F0233);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DRIVER_NONNATIVE = unchecked((int)0x800F0234);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_IN_WOW64 = unchecked((int)0x800F0235);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_SET_SYSTEM_RESTORE_POINT = unchecked((int)0x800F0236);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INCORRECTLY_COPIED_INF = unchecked((int)0x800F0237);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_SCE_DISABLED = unchecked((int)0x800F0238);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_UNKNOWN_EXCEPTION = unchecked((int)0x800F0239);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_PNP_REGISTRY_ERROR = unchecked((int)0x800F023A);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_REMOTE_REQUEST_UNSUPPORTED = unchecked((int)0x800F023B);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NOT_AN_INSTALLED_OEM_INF = unchecked((int)0x800F023C);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_INF_IN_USE_BY_DEVICES = unchecked((int)0x800F023D);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DI_FUNCTION_OBSOLETE = unchecked((int)0x800F023E);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_NO_AUTHENTICODE_CATALOG = unchecked((int)0x800F023F);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_AUTHENTICODE_DISALLOWED = unchecked((int)0x800F0240);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER = unchecked((int)0x800F0241);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED = unchecked((int)0x800F0242);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED = unchecked((int)0x800F0243);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH = unchecked((int)0x800F0244);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE = unchecked((int)0x800F0245);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVICE_INSTALLER_NOT_READY = unchecked((int)0x800F0246);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DRIVER_STORE_ADD_FAILED = unchecked((int)0x800F0247);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DEVICE_INSTALL_BLOCKED = unchecked((int)0x800F0248);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DRIVER_INSTALL_BLOCKED = unchecked((int)0x800F0249);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_WRONG_INF_TYPE = unchecked((int)0x800F024A);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_FILE_HASH_NOT_IN_CATALOG = unchecked((int)0x800F024B);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_DRIVER_STORE_DELETE_FAILED = unchecked((int)0x800F024C);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW = unchecked((int)0x800F0300);

        [NativeTypeName("HRESULT")]
        public const int SPAPI_E_ERROR_NOT_INSTALLED = unchecked((int)0x800F1000);

        [NativeTypeName("HRESULT")]
        public const int SCARD_F_INTERNAL_ERROR = unchecked((int)0x80100001);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_CANCELLED = unchecked((int)0x80100002);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_HANDLE = unchecked((int)0x80100003);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_PARAMETER = unchecked((int)0x80100004);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_TARGET = unchecked((int)0x80100005);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_MEMORY = unchecked((int)0x80100006);

        [NativeTypeName("HRESULT")]
        public const int SCARD_F_WAITED_TOO_LONG = unchecked((int)0x80100007);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INSUFFICIENT_BUFFER = unchecked((int)0x80100008);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_UNKNOWN_READER = unchecked((int)0x80100009);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_TIMEOUT = unchecked((int)0x8010000A);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_SHARING_VIOLATION = unchecked((int)0x8010000B);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_SMARTCARD = unchecked((int)0x8010000C);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_UNKNOWN_CARD = unchecked((int)0x8010000D);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_CANT_DISPOSE = unchecked((int)0x8010000E);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_PROTO_MISMATCH = unchecked((int)0x8010000F);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NOT_READY = unchecked((int)0x80100010);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_VALUE = unchecked((int)0x80100011);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_SYSTEM_CANCELLED = unchecked((int)0x80100012);

        [NativeTypeName("HRESULT")]
        public const int SCARD_F_COMM_ERROR = unchecked((int)0x80100013);

        [NativeTypeName("HRESULT")]
        public const int SCARD_F_UNKNOWN_ERROR = unchecked((int)0x80100014);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_ATR = unchecked((int)0x80100015);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NOT_TRANSACTED = unchecked((int)0x80100016);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_READER_UNAVAILABLE = unchecked((int)0x80100017);

        [NativeTypeName("HRESULT")]
        public const int SCARD_P_SHUTDOWN = unchecked((int)0x80100018);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_PCI_TOO_SMALL = unchecked((int)0x80100019);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_READER_UNSUPPORTED = unchecked((int)0x8010001A);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_DUPLICATE_READER = unchecked((int)0x8010001B);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_CARD_UNSUPPORTED = unchecked((int)0x8010001C);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_SERVICE = unchecked((int)0x8010001D);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_SERVICE_STOPPED = unchecked((int)0x8010001E);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_UNEXPECTED = unchecked((int)0x8010001F);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_ICC_INSTALLATION = unchecked((int)0x80100020);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_ICC_CREATEORDER = unchecked((int)0x80100021);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_UNSUPPORTED_FEATURE = unchecked((int)0x80100022);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_DIR_NOT_FOUND = unchecked((int)0x80100023);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_FILE_NOT_FOUND = unchecked((int)0x80100024);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_DIR = unchecked((int)0x80100025);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_FILE = unchecked((int)0x80100026);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_ACCESS = unchecked((int)0x80100027);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_WRITE_TOO_MANY = unchecked((int)0x80100028);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_BAD_SEEK = unchecked((int)0x80100029);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_INVALID_CHV = unchecked((int)0x8010002A);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_UNKNOWN_RES_MNG = unchecked((int)0x8010002B);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_SUCH_CERTIFICATE = unchecked((int)0x8010002C);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_CERTIFICATE_UNAVAILABLE = unchecked((int)0x8010002D);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_READERS_AVAILABLE = unchecked((int)0x8010002E);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_COMM_DATA_LOST = unchecked((int)0x8010002F);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_KEY_CONTAINER = unchecked((int)0x80100030);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_SERVER_TOO_BUSY = unchecked((int)0x80100031);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_PIN_CACHE_EXPIRED = unchecked((int)0x80100032);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_NO_PIN_CACHE = unchecked((int)0x80100033);

        [NativeTypeName("HRESULT")]
        public const int SCARD_E_READ_ONLY_CARD = unchecked((int)0x80100034);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_UNSUPPORTED_CARD = unchecked((int)0x80100065);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_UNRESPONSIVE_CARD = unchecked((int)0x80100066);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_UNPOWERED_CARD = unchecked((int)0x80100067);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_RESET_CARD = unchecked((int)0x80100068);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_REMOVED_CARD = unchecked((int)0x80100069);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_SECURITY_VIOLATION = unchecked((int)0x8010006A);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_WRONG_CHV = unchecked((int)0x8010006B);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CHV_BLOCKED = unchecked((int)0x8010006C);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_EOF = unchecked((int)0x8010006D);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CANCELLED_BY_USER = unchecked((int)0x8010006E);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CARD_NOT_AUTHENTICATED = unchecked((int)0x8010006F);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CACHE_ITEM_NOT_FOUND = unchecked((int)0x80100070);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CACHE_ITEM_STALE = unchecked((int)0x80100071);

        [NativeTypeName("HRESULT")]
        public const int SCARD_W_CACHE_ITEM_TOO_BIG = unchecked((int)0x80100072);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECTERRORS = unchecked((int)0x80110401);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECTINVALID = unchecked((int)0x80110402);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_KEYMISSING = unchecked((int)0x80110403);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_ALREADYINSTALLED = unchecked((int)0x80110404);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APP_FILE_WRITEFAIL = unchecked((int)0x80110407);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APP_FILE_READFAIL = unchecked((int)0x80110408);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APP_FILE_VERSION = unchecked((int)0x80110409);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_BADPATH = unchecked((int)0x8011040A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APPLICATIONEXISTS = unchecked((int)0x8011040B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_ROLEEXISTS = unchecked((int)0x8011040C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANTCOPYFILE = unchecked((int)0x8011040D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOUSER = unchecked((int)0x8011040F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_INVALIDUSERIDS = unchecked((int)0x80110410);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOREGISTRYCLSID = unchecked((int)0x80110411);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_BADREGISTRYPROGID = unchecked((int)0x80110412);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_AUTHENTICATIONLEVEL = unchecked((int)0x80110413);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_USERPASSWDNOTVALID = unchecked((int)0x80110414);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CLSIDORIIDMISMATCH = unchecked((int)0x80110418);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REMOTEINTERFACE = unchecked((int)0x80110419);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_DLLREGISTERSERVER = unchecked((int)0x8011041A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOSERVERSHARE = unchecked((int)0x8011041B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_DLLLOADFAILED = unchecked((int)0x8011041D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_BADREGISTRYLIBID = unchecked((int)0x8011041E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APPDIRNOTFOUND = unchecked((int)0x8011041F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGISTRARFAILED = unchecked((int)0x80110423);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_DOESNOTEXIST = unchecked((int)0x80110424);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_LOADDLLFAIL = unchecked((int)0x80110425);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_GETCLASSOBJ = unchecked((int)0x80110426);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_CLASSNOTAVAIL = unchecked((int)0x80110427);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_BADTLB = unchecked((int)0x80110428);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_NOTINSTALLABLE = unchecked((int)0x80110429);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOTCHANGEABLE = unchecked((int)0x8011042A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOTDELETEABLE = unchecked((int)0x8011042B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_SESSION = unchecked((int)0x8011042C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMP_MOVE_LOCKED = unchecked((int)0x8011042D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMP_MOVE_BAD_DEST = unchecked((int)0x8011042E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGISTERTLB = unchecked((int)0x80110430);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_SYSTEMAPP = unchecked((int)0x80110433);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPFILE_NOREGISTRAR = unchecked((int)0x80110434);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COREQCOMPINSTALLED = unchecked((int)0x80110435);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_SERVICENOTINSTALLED = unchecked((int)0x80110436);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PROPERTYSAVEFAILED = unchecked((int)0x80110437);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECTEXISTS = unchecked((int)0x80110438);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMPONENTEXISTS = unchecked((int)0x80110439);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGFILE_CORRUPT = unchecked((int)0x8011043B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PROPERTY_OVERFLOW = unchecked((int)0x8011043C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_NOTINREGISTRY = unchecked((int)0x8011043E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECTNOTPOOLABLE = unchecked((int)0x8011043F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APPLID_MATCHES_CLSID = unchecked((int)0x80110446);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_ROLE_DOES_NOT_EXIST = unchecked((int)0x80110447);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_START_APP_NEEDS_COMPONENTS = unchecked((int)0x80110448);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM = unchecked((int)0x80110449);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY = unchecked((int)0x8011044A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAN_NOT_START_APP = unchecked((int)0x8011044B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAN_NOT_EXPORT_SYS_APP = unchecked((int)0x8011044C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT = unchecked((int)0x8011044D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER = unchecked((int)0x8011044E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE = unchecked((int)0x8011044F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_BASE_PARTITION_ONLY = unchecked((int)0x80110450);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_START_APP_DISABLED = unchecked((int)0x80110451);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME = unchecked((int)0x80110457);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_INVALID_PARTITION_NAME = unchecked((int)0x80110458);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_PARTITION_IN_USE = unchecked((int)0x80110459);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES = unchecked((int)0x8011045A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED = unchecked((int)0x8011045B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_AMBIGUOUS_APPLICATION_NAME = unchecked((int)0x8011045C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_AMBIGUOUS_PARTITION_NAME = unchecked((int)0x8011045D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGDB_NOTINITIALIZED = unchecked((int)0x80110472);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGDB_NOTOPEN = unchecked((int)0x80110473);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGDB_SYSTEMERR = unchecked((int)0x80110474);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGDB_ALREADYRUNNING = unchecked((int)0x80110475);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_MIG_VERSIONNOTSUPPORTED = unchecked((int)0x80110480);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_MIG_SCHEMANOTFOUND = unchecked((int)0x80110481);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_BITNESSMISMATCH = unchecked((int)0x80110482);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_UNACCEPTABLEBITNESS = unchecked((int)0x80110483);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_WRONGAPPBITNESS = unchecked((int)0x80110484);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED = unchecked((int)0x80110485);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CAT_SERVERFAULT = unchecked((int)0x80110486);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_APPLICATION_NOT_QUEUED = unchecked((int)0x80110600);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_NO_QUEUEABLE_INTERFACES = unchecked((int)0x80110601);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE = unchecked((int)0x80110602);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_NO_IPERSISTSTREAM = unchecked((int)0x80110603);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_BAD_MESSAGE = unchecked((int)0x80110604);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_UNAUTHENTICATED = unchecked((int)0x80110605);

        [NativeTypeName("HRESULT")]
        public const int COMQC_E_UNTRUSTED_ENQUEUER = unchecked((int)0x80110606);

        [NativeTypeName("HRESULT")]
        public const int MSDTC_E_DUPLICATE_RESOURCE = unchecked((int)0x80110701);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECT_PARENT_MISSING = unchecked((int)0x80110808);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_OBJECT_DOES_NOT_EXIST = unchecked((int)0x80110809);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_APP_NOT_RUNNING = unchecked((int)0x8011080A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_INVALID_PARTITION = unchecked((int)0x8011080B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE = unchecked((int)0x8011080D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_USER_IN_SET = unchecked((int)0x8011080E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANTRECYCLELIBRARYAPPS = unchecked((int)0x8011080F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANTRECYCLESERVICEAPPS = unchecked((int)0x80110811);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PROCESSALREADYRECYCLED = unchecked((int)0x80110812);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED = unchecked((int)0x80110813);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANTMAKEINPROCSERVICE = unchecked((int)0x80110814);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PROGIDINUSEBYCLSID = unchecked((int)0x80110815);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET = unchecked((int)0x80110816);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED = unchecked((int)0x80110817);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PARTITION_ACCESSDENIED = unchecked((int)0x80110818);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PARTITION_MSI_ONLY = unchecked((int)0x80110819);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT = unchecked((int)0x8011081A);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS = unchecked((int)0x8011081B);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMP_MOVE_SOURCE = unchecked((int)0x8011081C);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMP_MOVE_DEST = unchecked((int)0x8011081D);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_COMP_MOVE_PRIVATE = unchecked((int)0x8011081E);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET = unchecked((int)0x8011081F);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_CANNOT_ALIAS_EVENTCLASS = unchecked((int)0x80110820);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PRIVATE_ACCESSDENIED = unchecked((int)0x80110821);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_SAFERINVALID = unchecked((int)0x80110822);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_REGISTRY_ACCESSDENIED = unchecked((int)0x80110823);

        [NativeTypeName("HRESULT")]
        public const int COMADMIN_E_PARTITIONS_DISABLED = unchecked((int)0x80110824);

        [NativeTypeName("HRESULT")]
        public const int WER_S_REPORT_DEBUG = 0x001B0000;

        [NativeTypeName("HRESULT")]
        public const int WER_S_REPORT_UPLOADED = 0x001B0001;

        [NativeTypeName("HRESULT")]
        public const int WER_S_REPORT_QUEUED = 0x001B0002;

        [NativeTypeName("HRESULT")]
        public const int WER_S_DISABLED = 0x001B0003;

        [NativeTypeName("HRESULT")]
        public const int WER_S_SUSPENDED_UPLOAD = 0x001B0004;

        [NativeTypeName("HRESULT")]
        public const int WER_S_DISABLED_QUEUE = 0x001B0005;

        [NativeTypeName("HRESULT")]
        public const int WER_S_DISABLED_ARCHIVE = 0x001B0006;

        [NativeTypeName("HRESULT")]
        public const int WER_S_REPORT_ASYNC = 0x001B0007;

        [NativeTypeName("HRESULT")]
        public const int WER_S_IGNORE_ASSERT_INSTANCE = 0x001B0008;

        [NativeTypeName("HRESULT")]
        public const int WER_S_IGNORE_ALL_ASSERTS = 0x001B0009;

        [NativeTypeName("HRESULT")]
        public const int WER_S_ASSERT_CONTINUE = 0x001B000A;

        [NativeTypeName("HRESULT")]
        public const int WER_S_THROTTLED = 0x001B000B;

        [NativeTypeName("HRESULT")]
        public const int WER_S_REPORT_UPLOADED_CAB = 0x001B000C;

        [NativeTypeName("HRESULT")]
        public const int WER_E_CRASH_FAILURE = unchecked((int)0x801B8000);

        [NativeTypeName("HRESULT")]
        public const int WER_E_CANCELED = unchecked((int)0x801B8001);

        [NativeTypeName("HRESULT")]
        public const int WER_E_NETWORK_FAILURE = unchecked((int)0x801B8002);

        [NativeTypeName("HRESULT")]
        public const int WER_E_NOT_INITIALIZED = unchecked((int)0x801B8003);

        [NativeTypeName("HRESULT")]
        public const int WER_E_ALREADY_REPORTING = unchecked((int)0x801B8004);

        [NativeTypeName("HRESULT")]
        public const int WER_E_DUMP_THROTTLED = unchecked((int)0x801B8005);

        [NativeTypeName("HRESULT")]
        public const int WER_E_INSUFFICIENT_CONSENT = unchecked((int)0x801B8006);

        [NativeTypeName("HRESULT")]
        public const int WER_E_TOO_HEAVY = unchecked((int)0x801B8007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_IO_COMPLETE = 0x001F0001;

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NO_HANDLER_DEFINED = unchecked((int)0x801F0001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_CONTEXT_ALREADY_DEFINED = unchecked((int)0x801F0002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST = unchecked((int)0x801F0003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_DISALLOW_FAST_IO = unchecked((int)0x801F0004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INVALID_NAME_REQUEST = unchecked((int)0x801F0005);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NOT_SAFE_TO_POST_OPERATION = unchecked((int)0x801F0006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NOT_INITIALIZED = unchecked((int)0x801F0007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_FILTER_NOT_READY = unchecked((int)0x801F0008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_POST_OPERATION_CLEANUP = unchecked((int)0x801F0009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INTERNAL_ERROR = unchecked((int)0x801F000A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_DELETING_OBJECT = unchecked((int)0x801F000B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_MUST_BE_NONPAGED_POOL = unchecked((int)0x801F000C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_DUPLICATE_ENTRY = unchecked((int)0x801F000D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_CBDQ_DISABLED = unchecked((int)0x801F000E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_DO_NOT_ATTACH = unchecked((int)0x801F000F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_DO_NOT_DETACH = unchecked((int)0x801F0010);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INSTANCE_ALTITUDE_COLLISION = unchecked((int)0x801F0011);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INSTANCE_NAME_COLLISION = unchecked((int)0x801F0012);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_FILTER_NOT_FOUND = unchecked((int)0x801F0013);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_VOLUME_NOT_FOUND = unchecked((int)0x801F0014);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INSTANCE_NOT_FOUND = unchecked((int)0x801F0015);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND = unchecked((int)0x801F0016);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_INVALID_CONTEXT_REGISTRATION = unchecked((int)0x801F0017);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NAME_CACHE_MISS = unchecked((int)0x801F0018);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NO_DEVICE_OBJECT = unchecked((int)0x801F0019);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_VOLUME_ALREADY_MOUNTED = unchecked((int)0x801F001A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_ALREADY_ENLISTED = unchecked((int)0x801F001B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_CONTEXT_ALREADY_LINKED = unchecked((int)0x801F001C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_NO_WAITER_FOR_REPLY = unchecked((int)0x801F0020);

        [NativeTypeName("HRESULT")]
        public const int ERROR_FLT_REGISTRATION_BUSY = unchecked((int)0x801F0023);

        [NativeTypeName("HRESULT")]
        public const int ERROR_HUNG_DISPLAY_DRIVER_THREAD = unchecked((int)0x80260001);

        [NativeTypeName("HRESULT")]
        public const int DWM_E_COMPOSITIONDISABLED = unchecked((int)0x80263001);

        [NativeTypeName("HRESULT")]
        public const int DWM_E_REMOTING_NOT_SUPPORTED = unchecked((int)0x80263002);

        [NativeTypeName("HRESULT")]
        public const int DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE = unchecked((int)0x80263003);

        [NativeTypeName("HRESULT")]
        public const int DWM_E_NOT_QUEUING_PRESENTS = unchecked((int)0x80263004);

        [NativeTypeName("HRESULT")]
        public const int DWM_E_ADAPTER_NOT_FOUND = unchecked((int)0x80263005);

        [NativeTypeName("HRESULT")]
        public const int DWM_S_GDI_REDIRECTION_SURFACE = 0x00263005;

        [NativeTypeName("HRESULT")]
        public const int DWM_E_TEXTURE_TOO_LARGE = unchecked((int)0x80263007);

        [NativeTypeName("HRESULT")]
        public const int DWM_S_GDI_REDIRECTION_SURFACE_BLT_VIA_GDI = 0x00263008;

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_NO_DESCRIPTOR = 0x00261001;

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT = 0x00261002;

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM = unchecked((int)0xC0261003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK = unchecked((int)0xC0261004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED = unchecked((int)0xC0261005);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK = unchecked((int)0xC0261006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK = unchecked((int)0xC0261007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA = unchecked((int)0xC0261008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK = unchecked((int)0xC0261009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_MONITOR_INVALID_MANUFACTURE_DATE = unchecked((int)0xC026100A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER = unchecked((int)0xC0262000);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER = unchecked((int)0xC0262001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER = unchecked((int)0xC0262002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ADAPTER_WAS_RESET = unchecked((int)0xC0262003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_DRIVER_MODEL = unchecked((int)0xC0262004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_MODE_CHANGED = unchecked((int)0xC0262005);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_OCCLUDED = unchecked((int)0xC0262006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_DENIED = unchecked((int)0xC0262007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANNOTCOLORCONVERT = unchecked((int)0xC0262008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DRIVER_MISMATCH = unchecked((int)0xC0262009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PARTIAL_DATA_POPULATED = 0x4026200A;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED = unchecked((int)0xC026200B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_UNOCCLUDED = unchecked((int)0xC026200C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_WINDOWDC_NOT_AVAILABLE = unchecked((int)0xC026200D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_WINDOWLESS_PRESENT_DISABLED = unchecked((int)0xC026200E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_INVALID_WINDOW = unchecked((int)0xC026200F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PRESENT_BUFFER_NOT_BOUND = unchecked((int)0xC0262010);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VAIL_STATE_CHANGED = unchecked((int)0xC0262011);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INDIRECT_DISPLAY_ABANDON_SWAPCHAIN = unchecked((int)0xC0262012);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INDIRECT_DISPLAY_DEVICE_STOPPED = unchecked((int)0xC0262013);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VAIL_FAILED_TO_SEND_CREATE_SUPERWETINK_MESSAGE = unchecked((int)0xC0262014);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VAIL_FAILED_TO_SEND_DESTROY_SUPERWETINK_MESSAGE = unchecked((int)0xC0262015);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_VIDEO_MEMORY = unchecked((int)0xC0262100);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANT_LOCK_MEMORY = unchecked((int)0xC0262101);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ALLOCATION_BUSY = unchecked((int)0xC0262102);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TOO_MANY_REFERENCES = unchecked((int)0xC0262103);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TRY_AGAIN_LATER = unchecked((int)0xC0262104);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TRY_AGAIN_NOW = unchecked((int)0xC0262105);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ALLOCATION_INVALID = unchecked((int)0xC0262106);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE = unchecked((int)0xC0262107);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED = unchecked((int)0xC0262108);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION = unchecked((int)0xC0262109);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE = unchecked((int)0xC0262110);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION = unchecked((int)0xC0262111);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ALLOCATION_CLOSED = unchecked((int)0xC0262112);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE = unchecked((int)0xC0262113);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE = unchecked((int)0xC0262114);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE = unchecked((int)0xC0262115);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST = unchecked((int)0xC0262116);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE = unchecked((int)0xC0262200);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SKIP_ALLOCATION_PREPARATION = 0x40262201;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY = unchecked((int)0xC0262300);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED = unchecked((int)0xC0262301);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED = unchecked((int)0xC0262302);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN = unchecked((int)0xC0262303);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE = unchecked((int)0xC0262304);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET = unchecked((int)0xC0262305);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED = unchecked((int)0xC0262306);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MODE_NOT_PINNED = 0x00262307;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET = unchecked((int)0xC0262308);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET = unchecked((int)0xC0262309);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_FREQUENCY = unchecked((int)0xC026230A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_ACTIVE_REGION = unchecked((int)0xC026230B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_TOTAL_REGION = unchecked((int)0xC026230C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE = unchecked((int)0xC0262310);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE = unchecked((int)0xC0262311);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET = unchecked((int)0xC0262312);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY = unchecked((int)0xC0262313);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET = unchecked((int)0xC0262314);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET = unchecked((int)0xC0262315);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET = unchecked((int)0xC0262316);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET = unchecked((int)0xC0262317);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TARGET_ALREADY_IN_SET = unchecked((int)0xC0262318);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH = unchecked((int)0xC0262319);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY = unchecked((int)0xC026231A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET = unchecked((int)0xC026231B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE = unchecked((int)0xC026231C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET = unchecked((int)0xC026231D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_PREFERRED_MODE = 0x0026231E;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET = unchecked((int)0xC026231F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_STALE_MODESET = unchecked((int)0xC0262320);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET = unchecked((int)0xC0262321);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE = unchecked((int)0xC0262322);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN = unchecked((int)0xC0262323);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE = unchecked((int)0xC0262324);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION = unchecked((int)0xC0262325);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES = unchecked((int)0xC0262326);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY = unchecked((int)0xC0262327);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE = unchecked((int)0xC0262328);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET = unchecked((int)0xC0262329);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET = unchecked((int)0xC026232A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR = unchecked((int)0xC026232B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET = unchecked((int)0xC026232C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET = unchecked((int)0xC026232D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE = unchecked((int)0xC026232E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE = unchecked((int)0xC026232F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_RESOURCES_NOT_RELATED = unchecked((int)0xC0262330);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE = unchecked((int)0xC0262331);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE = unchecked((int)0xC0262332);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET = unchecked((int)0xC0262333);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER = unchecked((int)0xC0262334);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_VIDPNMGR = unchecked((int)0xC0262335);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_ACTIVE_VIDPN = unchecked((int)0xC0262336);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY = unchecked((int)0xC0262337);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITOR_NOT_CONNECTED = unchecked((int)0xC0262338);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY = unchecked((int)0xC0262339);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE = unchecked((int)0xC026233A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE = unchecked((int)0xC026233B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_STRIDE = unchecked((int)0xC026233C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PIXELFORMAT = unchecked((int)0xC026233D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_COLORBASIS = unchecked((int)0xC026233E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE = unchecked((int)0xC026233F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY = unchecked((int)0xC0262340);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT = unchecked((int)0xC0262341);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE = unchecked((int)0xC0262342);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN = unchecked((int)0xC0262343);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL = unchecked((int)0xC0262344);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION = unchecked((int)0xC0262345);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED = unchecked((int)0xC0262346);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_GAMMA_RAMP = unchecked((int)0xC0262347);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED = unchecked((int)0xC0262348);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED = unchecked((int)0xC0262349);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MODE_NOT_IN_MODESET = unchecked((int)0xC026234A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DATASET_IS_EMPTY = 0x0026234B;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET = 0x0026234C;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON = unchecked((int)0xC026234D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE = unchecked((int)0xC026234E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE = unchecked((int)0xC026234F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS = unchecked((int)0xC0262350);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED = 0x00262351;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING = unchecked((int)0xC0262352);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED = unchecked((int)0xC0262353);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS = unchecked((int)0xC0262354);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT = unchecked((int)0xC0262355);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM = unchecked((int)0xC0262356);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN = unchecked((int)0xC0262357);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT = unchecked((int)0xC0262358);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED = unchecked((int)0xC0262359);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION = unchecked((int)0xC026235A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_CLIENT_TYPE = unchecked((int)0xC026235B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET = unchecked((int)0xC026235C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED = unchecked((int)0xC0262400);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED = unchecked((int)0xC0262401);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS = 0x4026242F;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER = unchecked((int)0xC0262430);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED = unchecked((int)0xC0262431);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED = unchecked((int)0xC0262432);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY = unchecked((int)0xC0262433);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED = unchecked((int)0xC0262434);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON = unchecked((int)0xC0262435);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE = unchecked((int)0xC0262436);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_LEADLINK_START_DEFERRED = 0x40262437;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER = unchecked((int)0xC0262438);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY = 0x40262439;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_START_DEFERRED = 0x4026243A;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED = unchecked((int)0xC026243B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DEPENDABLE_CHILD_STATUS = 0x4026243C;

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_NOT_SUPPORTED = unchecked((int)0xC0262500);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_COPP_NOT_SUPPORTED = unchecked((int)0xC0262501);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_UAB_NOT_SUPPORTED = unchecked((int)0xC0262502);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS = unchecked((int)0xC0262503);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST = unchecked((int)0xC0262505);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INTERNAL_ERROR = unchecked((int)0xC026250B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INVALID_HANDLE = unchecked((int)0xC026250C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH = unchecked((int)0xC026250E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED = unchecked((int)0xC026250F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED = unchecked((int)0xC0262510);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PVP_HFS_FAILED = unchecked((int)0xC0262511);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INVALID_SRM = unchecked((int)0xC0262512);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP = unchecked((int)0xC0262513);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP = unchecked((int)0xC0262514);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA = unchecked((int)0xC0262515);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET = unchecked((int)0xC0262516);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH = unchecked((int)0xC0262517);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE = unchecked((int)0xC0262518);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS = unchecked((int)0xC026251A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS = unchecked((int)0xC026251B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS = unchecked((int)0xC026251C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST = unchecked((int)0xC026251D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR = unchecked((int)0xC026251E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS = unchecked((int)0xC026251F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED = unchecked((int)0xC0262520);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST = unchecked((int)0xC0262521);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_I2C_NOT_SUPPORTED = unchecked((int)0xC0262580);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST = unchecked((int)0xC0262581);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA = unchecked((int)0xC0262582);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA = unchecked((int)0xC0262583);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED = unchecked((int)0xC0262584);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_INVALID_DATA = unchecked((int)0xC0262585);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE = unchecked((int)0xC0262586);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING = unchecked((int)0xC0262587);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_INTERNAL_ERROR = unchecked((int)0xC0262588);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND = unchecked((int)0xC0262589);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH = unchecked((int)0xC026258A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM = unchecked((int)0xC026258B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE = unchecked((int)0xC026258C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS = unchecked((int)0xC026258D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE = unchecked((int)0xC02625D8);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION = unchecked((int)0xC02625D9);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION = unchecked((int)0xC02625DA);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH = unchecked((int)0xC02625DB);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION = unchecked((int)0xC02625DC);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED = unchecked((int)0xC02625DE);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE = unchecked((int)0xC02625DF);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED = unchecked((int)0xC02625E0);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME = unchecked((int)0xC02625E1);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP = unchecked((int)0xC02625E2);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED = unchecked((int)0xC02625E3);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INVALID_POINTER = unchecked((int)0xC02625E4);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE = unchecked((int)0xC02625E5);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL = unchecked((int)0xC02625E6);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_INTERNAL_ERROR = unchecked((int)0xC02625E7);

        [NativeTypeName("HRESULT")]
        public const int ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS = unchecked((int)0xC02605E8);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_INVALID_PACKET = unchecked((int)0x80270001);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_MISSING_SOH = unchecked((int)0x80270002);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_CONFLICTING_ID = unchecked((int)0x80270003);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_NO_CACHED_SOH = unchecked((int)0x80270004);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_STILL_BOUND = unchecked((int)0x80270005);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_NOT_REGISTERED = unchecked((int)0x80270006);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_NOT_INITIALIZED = unchecked((int)0x80270007);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_MISMATCHED_ID = unchecked((int)0x80270008);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_NOT_PENDING = unchecked((int)0x80270009);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_ID_NOT_FOUND = unchecked((int)0x8027000A);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_MAXSIZE_TOO_SMALL = unchecked((int)0x8027000B);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_SERVICE_NOT_RUNNING = unchecked((int)0x8027000C);

        [NativeTypeName("HRESULT")]
        public const int NAP_S_CERT_ALREADY_PRESENT = 0x0027000D;

        [NativeTypeName("HRESULT")]
        public const int NAP_E_ENTITY_DISABLED = unchecked((int)0x8027000E);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_NETSH_GROUPPOLICY_ERROR = unchecked((int)0x8027000F);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_TOO_MANY_CALLS = unchecked((int)0x80270010);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_SHV_CONFIG_EXISTED = unchecked((int)0x80270011);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_SHV_CONFIG_NOT_FOUND = unchecked((int)0x80270012);

        [NativeTypeName("HRESULT")]
        public const int NAP_E_SHV_TIMEOUT = unchecked((int)0x80270013);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_ERROR_MASK = unchecked((int)0x80280000);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUTHFAIL = unchecked((int)0x80280001);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BADINDEX = unchecked((int)0x80280002);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_PARAMETER = unchecked((int)0x80280003);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUDITFAILURE = unchecked((int)0x80280004);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_CLEAR_DISABLED = unchecked((int)0x80280005);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DEACTIVATED = unchecked((int)0x80280006);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DISABLED = unchecked((int)0x80280007);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DISABLED_CMD = unchecked((int)0x80280008);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_FAIL = unchecked((int)0x80280009);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_ORDINAL = unchecked((int)0x8028000A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INSTALL_DISABLED = unchecked((int)0x8028000B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_KEYHANDLE = unchecked((int)0x8028000C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEYNOTFOUND = unchecked((int)0x8028000D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INAPPROPRIATE_ENC = unchecked((int)0x8028000E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MIGRATEFAIL = unchecked((int)0x8028000F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_PCR_INFO = unchecked((int)0x80280010);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOSPACE = unchecked((int)0x80280011);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOSRK = unchecked((int)0x80280012);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOTSEALED_BLOB = unchecked((int)0x80280013);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_OWNER_SET = unchecked((int)0x80280014);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_RESOURCES = unchecked((int)0x80280015);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_SHORTRANDOM = unchecked((int)0x80280016);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_SIZE = unchecked((int)0x80280017);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_WRONGPCRVAL = unchecked((int)0x80280018);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_PARAM_SIZE = unchecked((int)0x80280019);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_SHA_THREAD = unchecked((int)0x8028001A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_SHA_ERROR = unchecked((int)0x8028001B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_FAILEDSELFTEST = unchecked((int)0x8028001C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUTH2FAIL = unchecked((int)0x8028001D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BADTAG = unchecked((int)0x8028001E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_IOERROR = unchecked((int)0x8028001F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_ENCRYPT_ERROR = unchecked((int)0x80280020);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DECRYPT_ERROR = unchecked((int)0x80280021);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_AUTHHANDLE = unchecked((int)0x80280022);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NO_ENDORSEMENT = unchecked((int)0x80280023);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_KEYUSAGE = unchecked((int)0x80280024);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_WRONG_ENTITYTYPE = unchecked((int)0x80280025);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_POSTINIT = unchecked((int)0x80280026);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INAPPROPRIATE_SIG = unchecked((int)0x80280027);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_KEY_PROPERTY = unchecked((int)0x80280028);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_MIGRATION = unchecked((int)0x80280029);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_SCHEME = unchecked((int)0x8028002A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_DATASIZE = unchecked((int)0x8028002B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_MODE = unchecked((int)0x8028002C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_PRESENCE = unchecked((int)0x8028002D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_VERSION = unchecked((int)0x8028002E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NO_WRAP_TRANSPORT = unchecked((int)0x8028002F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUDITFAIL_UNSUCCESSFUL = unchecked((int)0x80280030);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUDITFAIL_SUCCESSFUL = unchecked((int)0x80280031);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOTRESETABLE = unchecked((int)0x80280032);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOTLOCAL = unchecked((int)0x80280033);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_TYPE = unchecked((int)0x80280034);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_RESOURCE = unchecked((int)0x80280035);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOTFIPS = unchecked((int)0x80280036);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_FAMILY = unchecked((int)0x80280037);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NO_NV_PERMISSION = unchecked((int)0x80280038);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_REQUIRES_SIGN = unchecked((int)0x80280039);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_NOTSUPPORTED = unchecked((int)0x8028003A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AUTH_CONFLICT = unchecked((int)0x8028003B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_AREA_LOCKED = unchecked((int)0x8028003C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_LOCALITY = unchecked((int)0x8028003D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_READ_ONLY = unchecked((int)0x8028003E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PER_NOWRITE = unchecked((int)0x8028003F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_FAMILYCOUNT = unchecked((int)0x80280040);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_WRITE_LOCKED = unchecked((int)0x80280041);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_ATTRIBUTES = unchecked((int)0x80280042);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_STRUCTURE = unchecked((int)0x80280043);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_OWNER_CONTROL = unchecked((int)0x80280044);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_COUNTER = unchecked((int)0x80280045);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOT_FULLWRITE = unchecked((int)0x80280046);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_CONTEXT_GAP = unchecked((int)0x80280047);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MAXNVWRITES = unchecked((int)0x80280048);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOOPERATOR = unchecked((int)0x80280049);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_RESOURCEMISSING = unchecked((int)0x8028004A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DELEGATE_LOCK = unchecked((int)0x8028004B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DELEGATE_FAMILY = unchecked((int)0x8028004C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DELEGATE_ADMIN = unchecked((int)0x8028004D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_TRANSPORT_NOTEXCLUSIVE = unchecked((int)0x8028004E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_OWNER_CONTROL = unchecked((int)0x8028004F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_RESOURCES = unchecked((int)0x80280050);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_INPUT_DATA0 = unchecked((int)0x80280051);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_INPUT_DATA1 = unchecked((int)0x80280052);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_ISSUER_SETTINGS = unchecked((int)0x80280053);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_TPM_SETTINGS = unchecked((int)0x80280054);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_STAGE = unchecked((int)0x80280055);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_ISSUER_VALIDITY = unchecked((int)0x80280056);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DAA_WRONG_W = unchecked((int)0x80280057);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_HANDLE = unchecked((int)0x80280058);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_DELEGATE = unchecked((int)0x80280059);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BADCONTEXT = unchecked((int)0x8028005A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_TOOMANYCONTEXTS = unchecked((int)0x8028005B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MA_TICKET_SIGNATURE = unchecked((int)0x8028005C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MA_DESTINATION = unchecked((int)0x8028005D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MA_SOURCE = unchecked((int)0x8028005E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_MA_AUTHORITY = unchecked((int)0x8028005F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PERMANENTEK = unchecked((int)0x80280061);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BAD_SIGNATURE = unchecked((int)0x80280062);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOCONTEXTSPACE = unchecked((int)0x80280063);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_ASYMMETRIC = unchecked((int)0x80280081);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_ATTRIBUTES = unchecked((int)0x80280082);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_HASH = unchecked((int)0x80280083);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_VALUE = unchecked((int)0x80280084);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_HIERARCHY = unchecked((int)0x80280085);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_KEY_SIZE = unchecked((int)0x80280087);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_MGF = unchecked((int)0x80280088);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_MODE = unchecked((int)0x80280089);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_TYPE = unchecked((int)0x8028008A);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_HANDLE = unchecked((int)0x8028008B);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_KDF = unchecked((int)0x8028008C);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_RANGE = unchecked((int)0x8028008D);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTH_FAIL = unchecked((int)0x8028008E);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NONCE = unchecked((int)0x8028008F);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_PP = unchecked((int)0x80280090);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SCHEME = unchecked((int)0x80280092);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SIZE = unchecked((int)0x80280095);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SYMMETRIC = unchecked((int)0x80280096);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_TAG = unchecked((int)0x80280097);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SELECTOR = unchecked((int)0x80280098);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_INSUFFICIENT = unchecked((int)0x8028009A);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SIGNATURE = unchecked((int)0x8028009B);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_KEY = unchecked((int)0x8028009C);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_POLICY_FAIL = unchecked((int)0x8028009D);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_INTEGRITY = unchecked((int)0x8028009F);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_TICKET = unchecked((int)0x802800A0);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_RESERVED_BITS = unchecked((int)0x802800A1);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_BAD_AUTH = unchecked((int)0x802800A2);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_EXPIRED = unchecked((int)0x802800A3);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_POLICY_CC = unchecked((int)0x802800A4);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_BINDING = unchecked((int)0x802800A5);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_CURVE = unchecked((int)0x802800A6);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_ECC_POINT = unchecked((int)0x802800A7);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_INITIALIZE = unchecked((int)0x80280100);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_FAILURE = unchecked((int)0x80280101);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SEQUENCE = unchecked((int)0x80280103);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_PRIVATE = unchecked((int)0x8028010B);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_HMAC = unchecked((int)0x80280119);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_DISABLED = unchecked((int)0x80280120);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_EXCLUSIVE = unchecked((int)0x80280121);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_ECC_CURVE = unchecked((int)0x80280123);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTH_TYPE = unchecked((int)0x80280124);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTH_MISSING = unchecked((int)0x80280125);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_POLICY = unchecked((int)0x80280126);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_PCR = unchecked((int)0x80280127);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_PCR_CHANGED = unchecked((int)0x80280128);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_UPGRADE = unchecked((int)0x8028012D);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_TOO_MANY_CONTEXTS = unchecked((int)0x8028012E);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTH_UNAVAILABLE = unchecked((int)0x8028012F);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_REBOOT = unchecked((int)0x80280130);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_UNBALANCED = unchecked((int)0x80280131);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_COMMAND_SIZE = unchecked((int)0x80280142);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_COMMAND_CODE = unchecked((int)0x80280143);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTHSIZE = unchecked((int)0x80280144);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_AUTH_CONTEXT = unchecked((int)0x80280145);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_RANGE = unchecked((int)0x80280146);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_SIZE = unchecked((int)0x80280147);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_LOCKED = unchecked((int)0x80280148);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_AUTHORIZATION = unchecked((int)0x80280149);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_UNINITIALIZED = unchecked((int)0x8028014A);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_SPACE = unchecked((int)0x8028014B);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_DEFINED = unchecked((int)0x8028014C);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_BAD_CONTEXT = unchecked((int)0x80280150);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_CPHASH = unchecked((int)0x80280151);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_PARENT = unchecked((int)0x80280152);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NEEDS_TEST = unchecked((int)0x80280153);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NO_RESULT = unchecked((int)0x80280154);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SENSITIVE = unchecked((int)0x80280155);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_COMMAND_BLOCKED = unchecked((int)0x80280400);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_HANDLE = unchecked((int)0x80280401);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DUPLICATE_VHANDLE = unchecked((int)0x80280402);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_EMBEDDED_COMMAND_BLOCKED = unchecked((int)0x80280403);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_EMBEDDED_COMMAND_UNSUPPORTED = unchecked((int)0x80280404);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_RETRY = unchecked((int)0x80280800);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NEEDS_SELFTEST = unchecked((int)0x80280801);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DOING_SELFTEST = unchecked((int)0x80280802);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_DEFEND_LOCK_RUNNING = unchecked((int)0x80280803);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_CONTEXT_GAP = unchecked((int)0x80280901);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_OBJECT_MEMORY = unchecked((int)0x80280902);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SESSION_MEMORY = unchecked((int)0x80280903);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_MEMORY = unchecked((int)0x80280904);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_SESSION_HANDLES = unchecked((int)0x80280905);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_OBJECT_HANDLES = unchecked((int)0x80280906);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_LOCALITY = unchecked((int)0x80280907);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_YIELDED = unchecked((int)0x80280908);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_CANCELED = unchecked((int)0x80280909);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_TESTING = unchecked((int)0x8028090A);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_RATE = unchecked((int)0x80280920);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_LOCKOUT = unchecked((int)0x80280921);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_RETRY = unchecked((int)0x80280922);

        [NativeTypeName("HRESULT")]
        public const int TPM_20_E_NV_UNAVAILABLE = unchecked((int)0x80280923);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_INTERNAL_ERROR = unchecked((int)0x80284001);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_BAD_PARAMETER = unchecked((int)0x80284002);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_INVALID_OUTPUT_POINTER = unchecked((int)0x80284003);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_INVALID_CONTEXT = unchecked((int)0x80284004);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_INSUFFICIENT_BUFFER = unchecked((int)0x80284005);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_IOERROR = unchecked((int)0x80284006);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_INVALID_CONTEXT_PARAM = unchecked((int)0x80284007);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_SERVICE_NOT_RUNNING = unchecked((int)0x80284008);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_TOO_MANY_TBS_CONTEXTS = unchecked((int)0x80284009);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_TOO_MANY_RESOURCES = unchecked((int)0x8028400A);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_SERVICE_START_PENDING = unchecked((int)0x8028400B);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_PPI_NOT_SUPPORTED = unchecked((int)0x8028400C);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_COMMAND_CANCELED = unchecked((int)0x8028400D);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_BUFFER_TOO_LARGE = unchecked((int)0x8028400E);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_TPM_NOT_FOUND = unchecked((int)0x8028400F);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_SERVICE_DISABLED = unchecked((int)0x80284010);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_NO_EVENT_LOG = unchecked((int)0x80284011);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_ACCESS_DENIED = unchecked((int)0x80284012);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_PROVISIONING_NOT_ALLOWED = unchecked((int)0x80284013);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_PPI_FUNCTION_UNSUPPORTED = unchecked((int)0x80284014);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_OWNERAUTH_NOT_FOUND = unchecked((int)0x80284015);

        [NativeTypeName("HRESULT")]
        public const int TBS_E_PROVISIONING_INCOMPLETE = unchecked((int)0x80284016);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_STATE = unchecked((int)0x80290100);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_NOT_ENOUGH_DATA = unchecked((int)0x80290101);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_TOO_MUCH_DATA = unchecked((int)0x80290102);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_OUTPUT_POINTER = unchecked((int)0x80290103);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_PARAMETER = unchecked((int)0x80290104);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_OUT_OF_MEMORY = unchecked((int)0x80290105);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_BUFFER_TOO_SMALL = unchecked((int)0x80290106);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INTERNAL_ERROR = unchecked((int)0x80290107);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_ACCESS_DENIED = unchecked((int)0x80290108);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_AUTHORIZATION_FAILED = unchecked((int)0x80290109);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_CONTEXT_HANDLE = unchecked((int)0x8029010A);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_TBS_COMMUNICATION_ERROR = unchecked((int)0x8029010B);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_TPM_COMMAND_ERROR = unchecked((int)0x8029010C);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_MESSAGE_TOO_LARGE = unchecked((int)0x8029010D);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_ENCODING = unchecked((int)0x8029010E);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_KEY_SIZE = unchecked((int)0x8029010F);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_ENCRYPTION_FAILED = unchecked((int)0x80290110);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_KEY_PARAMS = unchecked((int)0x80290111);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB = unchecked((int)0x80290112);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_PCR_INDEX = unchecked((int)0x80290113);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_DELEGATE_BLOB = unchecked((int)0x80290114);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_CONTEXT_PARAMS = unchecked((int)0x80290115);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_KEY_BLOB = unchecked((int)0x80290116);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_PCR_DATA = unchecked((int)0x80290117);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_OWNER_AUTH = unchecked((int)0x80290118);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_FIPS_RNG_CHECK_FAILED = unchecked((int)0x80290119);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_EMPTY_TCG_LOG = unchecked((int)0x8029011A);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_TCG_LOG_ENTRY = unchecked((int)0x8029011B);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_TCG_SEPARATOR_ABSENT = unchecked((int)0x8029011C);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_TCG_INVALID_DIGEST_ENTRY = unchecked((int)0x8029011D);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_POLICY_DENIES_OPERATION = unchecked((int)0x8029011E);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_NV_BITS_NOT_DEFINED = unchecked((int)0x8029011F);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_NV_BITS_NOT_READY = unchecked((int)0x80290120);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_SEALING_KEY_NOT_AVAILABLE = unchecked((int)0x80290121);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_NO_AUTHORIZATION_CHAIN_FOUND = unchecked((int)0x80290122);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_SVN_COUNTER_NOT_AVAILABLE = unchecked((int)0x80290123);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_OWNER_AUTH_NOT_NULL = unchecked((int)0x80290124);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_ENDORSEMENT_AUTH_NOT_NULL = unchecked((int)0x80290125);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_AUTHORIZATION_REVOKED = unchecked((int)0x80290126);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_MALFORMED_AUTHORIZATION_KEY = unchecked((int)0x80290127);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_AUTHORIZING_KEY_NOT_SUPPORTED = unchecked((int)0x80290128);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_AUTHORIZATION_SIGNATURE = unchecked((int)0x80290129);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_MALFORMED_AUTHORIZATION_POLICY = unchecked((int)0x8029012A);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_MALFORMED_AUTHORIZATION_OTHER = unchecked((int)0x8029012B);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_SEALING_KEY_CHANGED = unchecked((int)0x8029012C);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_TPM_VERSION = unchecked((int)0x8029012D);

        [NativeTypeName("HRESULT")]
        public const int TPMAPI_E_INVALID_POLICYAUTH_BLOB_TYPE = unchecked((int)0x8029012E);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_BUFFER_TOO_SMALL = unchecked((int)0x80290200);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_CLEANUP_FAILED = unchecked((int)0x80290201);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_INVALID_CONTEXT_HANDLE = unchecked((int)0x80290202);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_INVALID_CONTEXT_PARAM = unchecked((int)0x80290203);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_TPM_ERROR = unchecked((int)0x80290204);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_HASH_BAD_KEY = unchecked((int)0x80290205);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_DUPLICATE_VHANDLE = unchecked((int)0x80290206);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_INVALID_OUTPUT_POINTER = unchecked((int)0x80290207);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_INVALID_PARAMETER = unchecked((int)0x80290208);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_RPC_INIT_FAILED = unchecked((int)0x80290209);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_SCHEDULER_NOT_RUNNING = unchecked((int)0x8029020A);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_COMMAND_CANCELED = unchecked((int)0x8029020B);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_OUT_OF_MEMORY = unchecked((int)0x8029020C);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_LIST_NO_MORE_ITEMS = unchecked((int)0x8029020D);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_LIST_NOT_FOUND = unchecked((int)0x8029020E);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_NOT_ENOUGH_SPACE = unchecked((int)0x8029020F);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS = unchecked((int)0x80290210);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_COMMAND_FAILED = unchecked((int)0x80290211);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_UNKNOWN_ORDINAL = unchecked((int)0x80290212);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_RESOURCE_EXPIRED = unchecked((int)0x80290213);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_INVALID_RESOURCE = unchecked((int)0x80290214);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_NOTHING_TO_UNLOAD = unchecked((int)0x80290215);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_HASH_TABLE_FULL = unchecked((int)0x80290216);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_TOO_MANY_TBS_CONTEXTS = unchecked((int)0x80290217);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_TOO_MANY_RESOURCES = unchecked((int)0x80290218);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_PPI_NOT_SUPPORTED = unchecked((int)0x80290219);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_TPM_INCOMPATIBLE = unchecked((int)0x8029021A);

        [NativeTypeName("HRESULT")]
        public const int TBSIMP_E_NO_EVENT_LOG = unchecked((int)0x8029021B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PPI_ACPI_FAILURE = unchecked((int)0x80290300);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PPI_USER_ABORT = unchecked((int)0x80290301);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PPI_BIOS_FAILURE = unchecked((int)0x80290302);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PPI_NOT_SUPPORTED = unchecked((int)0x80290303);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PPI_BLOCKED_IN_BIOS = unchecked((int)0x80290304);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_ERROR_MASK = unchecked((int)0x80290400);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_DEVICE_NOT_READY = unchecked((int)0x80290401);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_INVALID_HANDLE = unchecked((int)0x80290402);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_INVALID_PARAMETER = unchecked((int)0x80290403);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_FLAG_NOT_SUPPORTED = unchecked((int)0x80290404);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_NOT_SUPPORTED = unchecked((int)0x80290405);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_BUFFER_TOO_SMALL = unchecked((int)0x80290406);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_INTERNAL_ERROR = unchecked((int)0x80290407);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_AUTHENTICATION_FAILED = unchecked((int)0x80290408);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_AUTHENTICATION_IGNORED = unchecked((int)0x80290409);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_POLICY_NOT_FOUND = unchecked((int)0x8029040A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_PROFILE_NOT_FOUND = unchecked((int)0x8029040B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_VALIDATION_FAILED = unchecked((int)0x8029040C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_WRONG_PARENT = unchecked((int)0x8029040E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_NOT_LOADED = unchecked((int)0x8029040F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NO_KEY_CERTIFICATION = unchecked((int)0x80290410);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_NOT_FINALIZED = unchecked((int)0x80290411);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_ATTESTATION_CHALLENGE_NOT_SET = unchecked((int)0x80290412);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_NOT_PCR_BOUND = unchecked((int)0x80290413);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_ALREADY_FINALIZED = unchecked((int)0x80290414);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_USAGE_POLICY_NOT_SUPPORTED = unchecked((int)0x80290415);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_USAGE_POLICY_INVALID = unchecked((int)0x80290416);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_SOFT_KEY_ERROR = unchecked((int)0x80290417);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_NOT_AUTHENTICATED = unchecked((int)0x80290418);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_KEY_NOT_AIK = unchecked((int)0x80290419);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_KEY_NOT_SIGNING_KEY = unchecked((int)0x8029041A);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_LOCKED_OUT = unchecked((int)0x8029041B);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_CLAIM_TYPE_NOT_SUPPORTED = unchecked((int)0x8029041C);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_VERSION_NOT_SUPPORTED = unchecked((int)0x8029041D);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_BUFFER_LENGTH_MISMATCH = unchecked((int)0x8029041E);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_IFX_RSA_KEY_CREATION_BLOCKED = unchecked((int)0x8029041F);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_TICKET_MISSING = unchecked((int)0x80290420);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_RAW_POLICY_NOT_SUPPORTED = unchecked((int)0x80290421);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_KEY_HANDLE_INVALIDATED = unchecked((int)0x80290422);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_UNSUPPORTED_PSS_SALT = 0x40290423;

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_PLATFORM_CLAIM_MAY_BE_OUTDATED = 0x40290424;

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_PLATFORM_CLAIM_OUTDATED = 0x40290425;

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PCP_PLATFORM_CLAIM_REBOOT = 0x40290426;

        [NativeTypeName("HRESULT")]
        public const int TPM_E_ZERO_EXHAUST_ENABLED = unchecked((int)0x80290500);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_PROVISIONING_INCOMPLETE = unchecked((int)0x80290600);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_INVALID_OWNER_AUTH = unchecked((int)0x80290601);

        [NativeTypeName("HRESULT")]
        public const int TPM_E_TOO_MUCH_DATA = unchecked((int)0x80290602);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_NOT_FOUND = unchecked((int)0x80300002);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_IN_USE = unchecked((int)0x803000AA);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_TOO_MANY_FOLDERS = unchecked((int)0x80300045);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_NO_MIN_DISK = unchecked((int)0x80300070);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_ALREADY_EXISTS = unchecked((int)0x803000B7);

        [NativeTypeName("HRESULT")]
        public const int PLA_S_PROPERTY_IGNORED = 0x00300100;

        [NativeTypeName("HRESULT")]
        public const int PLA_E_PROPERTY_CONFLICT = unchecked((int)0x80300101);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_SINGLETON_REQUIRED = unchecked((int)0x80300102);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_CREDENTIALS_REQUIRED = unchecked((int)0x80300103);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_NOT_RUNNING = unchecked((int)0x80300104);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_CONFLICT_INCL_EXCL_API = unchecked((int)0x80300105);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_NETWORK_EXE_NOT_VALID = unchecked((int)0x80300106);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_EXE_ALREADY_CONFIGURED = unchecked((int)0x80300107);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_EXE_PATH_NOT_VALID = unchecked((int)0x80300108);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DC_ALREADY_EXISTS = unchecked((int)0x80300109);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DCS_START_WAIT_TIMEOUT = unchecked((int)0x8030010A);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_DC_START_WAIT_TIMEOUT = unchecked((int)0x8030010B);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_REPORT_WAIT_TIMEOUT = unchecked((int)0x8030010C);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_NO_DUPLICATES = unchecked((int)0x8030010D);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_EXE_FULL_PATH_REQUIRED = unchecked((int)0x8030010E);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_INVALID_SESSION_NAME = unchecked((int)0x8030010F);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_PLA_CHANNEL_NOT_ENABLED = unchecked((int)0x80300110);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED = unchecked((int)0x80300111);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_RULES_MANAGER_FAILED = unchecked((int)0x80300112);

        [NativeTypeName("HRESULT")]
        public const int PLA_E_CABAPI_FAILURE = unchecked((int)0x80300113);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_LOCKED_VOLUME = unchecked((int)0x80310000);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ENCRYPTED = unchecked((int)0x80310001);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_TPM_BIOS = unchecked((int)0x80310002);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_MBR_METRIC = unchecked((int)0x80310003);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_BOOTSECTOR_METRIC = unchecked((int)0x80310004);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_BOOTMGR_METRIC = unchecked((int)0x80310005);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_WRONG_BOOTMGR = unchecked((int)0x80310006);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_SECURE_KEY_REQUIRED = unchecked((int)0x80310007);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ACTIVATED = unchecked((int)0x80310008);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_ACTION_NOT_ALLOWED = unchecked((int)0x80310009);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_SCHEMA_NOT_INSTALLED = unchecked((int)0x8031000A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_INVALID_DATATYPE = unchecked((int)0x8031000B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_INVALID_DATASIZE = unchecked((int)0x8031000C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_NO_VALUES = unchecked((int)0x8031000D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_ATTR_NOT_SET = unchecked((int)0x8031000E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_GUID_NOT_FOUND = unchecked((int)0x8031000F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BAD_INFORMATION = unchecked((int)0x80310010);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TOO_SMALL = unchecked((int)0x80310011);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_SYSTEM_VOLUME = unchecked((int)0x80310012);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FAILED_WRONG_FS = unchecked((int)0x80310013);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BAD_PARTITION_SIZE = unchecked((int)0x80310014);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_SUPPORTED = unchecked((int)0x80310015);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BAD_DATA = unchecked((int)0x80310016);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VOLUME_NOT_BOUND = unchecked((int)0x80310017);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TPM_NOT_OWNED = unchecked((int)0x80310018);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_DATA_VOLUME = unchecked((int)0x80310019);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_INSUFFICIENT_BUFFER = unchecked((int)0x8031001A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CONV_READ = unchecked((int)0x8031001B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CONV_WRITE = unchecked((int)0x8031001C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEY_REQUIRED = unchecked((int)0x8031001D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CLUSTERING_NOT_SUPPORTED = unchecked((int)0x8031001E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VOLUME_BOUND_ALREADY = unchecked((int)0x8031001F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_OS_NOT_PROTECTED = unchecked((int)0x80310020);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTION_DISABLED = unchecked((int)0x80310021);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_RECOVERY_KEY_REQUIRED = unchecked((int)0x80310022);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FOREIGN_VOLUME = unchecked((int)0x80310023);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_OVERLAPPED_UPDATE = unchecked((int)0x80310024);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TPM_SRK_AUTH_NOT_ZERO = unchecked((int)0x80310025);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FAILED_SECTOR_SIZE = unchecked((int)0x80310026);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FAILED_AUTHENTICATION = unchecked((int)0x80310027);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_OS_VOLUME = unchecked((int)0x80310028);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AUTOUNLOCK_ENABLED = unchecked((int)0x80310029);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_WRONG_BOOTSECTOR = unchecked((int)0x8031002A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_WRONG_SYSTEM_FS = unchecked((int)0x8031002B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PASSWORD_REQUIRED = unchecked((int)0x8031002C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CANNOT_SET_FVEK_ENCRYPTED = unchecked((int)0x8031002D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CANNOT_ENCRYPT_NO_KEY = unchecked((int)0x8031002E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BOOTABLE_CDDVD = unchecked((int)0x80310030);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_EXISTS = unchecked((int)0x80310031);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_RELATIVE_PATH = unchecked((int)0x80310032);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_NOT_FOUND = unchecked((int)0x80310033);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_KEY_FORMAT = unchecked((int)0x80310034);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_PASSWORD_FORMAT = unchecked((int)0x80310035);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_RNG_CHECK_FAILED = unchecked((int)0x80310036);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD = unchecked((int)0x80310037);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT = unchecked((int)0x80310038);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_DECRYPTED = unchecked((int)0x80310039);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_PROTECTOR_TYPE = unchecked((int)0x8031003A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_PROTECTORS_TO_TEST = unchecked((int)0x8031003B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEYFILE_NOT_FOUND = unchecked((int)0x8031003C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEYFILE_INVALID = unchecked((int)0x8031003D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEYFILE_NO_VMK = unchecked((int)0x8031003E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TPM_DISABLED = unchecked((int)0x8031003F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ALLOWED_IN_SAFE_MODE = unchecked((int)0x80310040);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TPM_INVALID_PCR = unchecked((int)0x80310041);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TPM_NO_VMK = unchecked((int)0x80310042);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PIN_INVALID = unchecked((int)0x80310043);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AUTH_INVALID_APPLICATION = unchecked((int)0x80310044);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AUTH_INVALID_CONFIG = unchecked((int)0x80310045);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED = unchecked((int)0x80310046);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FS_NOT_EXTENDED = unchecked((int)0x80310047);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED = unchecked((int)0x80310048);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_LICENSE = unchecked((int)0x80310049);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ON_STACK = unchecked((int)0x8031004A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FS_MOUNTED = unchecked((int)0x8031004B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TOKEN_NOT_IMPERSONATED = unchecked((int)0x8031004C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DRY_RUN_FAILED = unchecked((int)0x8031004D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_REBOOT_REQUIRED = unchecked((int)0x8031004E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DEBUGGER_ENABLED = unchecked((int)0x8031004F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_RAW_ACCESS = unchecked((int)0x80310050);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_RAW_BLOCKED = unchecked((int)0x80310051);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BCD_APPLICATIONS_PATH_INCORRECT = unchecked((int)0x80310052);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ALLOWED_IN_VERSION = unchecked((int)0x80310053);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_AUTOUNLOCK_MASTER_KEY = unchecked((int)0x80310054);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_MOR_FAILED = unchecked((int)0x80310055);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_HIDDEN_VOLUME = unchecked((int)0x80310056);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_TRANSIENT_STATE = unchecked((int)0x80310057);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PUBKEY_NOT_ALLOWED = unchecked((int)0x80310058);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VOLUME_HANDLE_OPEN = unchecked((int)0x80310059);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_FEATURE_LICENSE = unchecked((int)0x8031005A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_STARTUP_OPTIONS = unchecked((int)0x8031005B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED = unchecked((int)0x8031005C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED = unchecked((int)0x8031005D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED = unchecked((int)0x8031005E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_RECOVERY_KEY_REQUIRED = unchecked((int)0x8031005F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED = unchecked((int)0x80310060);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_PIN_REQUIRED = unchecked((int)0x80310061);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED = unchecked((int)0x80310062);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_KEY_REQUIRED = unchecked((int)0x80310063);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED = unchecked((int)0x80310064);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED = unchecked((int)0x80310065);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED = unchecked((int)0x80310066);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_STARTUP_TPM_REQUIRED = unchecked((int)0x80310067);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_INVALID_PIN_LENGTH = unchecked((int)0x80310068);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEY_PROTECTOR_NOT_SUPPORTED = unchecked((int)0x80310069);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED = unchecked((int)0x8031006A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PASSPHRASE_REQUIRED = unchecked((int)0x8031006B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_PREVENTS_PASSPHRASE = unchecked((int)0x8031006C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED = unchecked((int)0x8031006D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_BITLOCKER_OID = unchecked((int)0x8031006E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VOLUME_TOO_SMALL = unchecked((int)0x8031006F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DV_NOT_SUPPORTED_ON_FS = unchecked((int)0x80310070);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DV_NOT_ALLOWED_BY_GP = unchecked((int)0x80310071);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED = unchecked((int)0x80310072);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CERTIFICATE_REQUIRED = unchecked((int)0x80310073);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CERT_MUST_BE_HW = unchecked((int)0x80310074);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED = unchecked((int)0x80310075);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED = unchecked((int)0x80310076);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED = unchecked((int)0x80310077);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED = unchecked((int)0x80310078);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED = unchecked((int)0x80310079);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH = unchecked((int)0x80310080);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE = unchecked((int)0x80310081);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_RECOVERY_PARTITION = unchecked((int)0x80310082);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON = unchecked((int)0x80310083);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON = unchecked((int)0x80310084);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NON_BITLOCKER_OID = unchecked((int)0x80310085);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PROHIBITS_SELFSIGNED = unchecked((int)0x80310086);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED = unchecked((int)0x80310087);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CONV_RECOVERY_FAILED = unchecked((int)0x80310088);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VIRTUALIZED_SPACE_TOO_BIG = unchecked((int)0x80310089);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON = unchecked((int)0x80310090);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON = unchecked((int)0x80310091);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON = unchecked((int)0x80310092);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NON_BITLOCKER_KU = unchecked((int)0x80310093);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PRIVATEKEY_AUTH_FAILED = unchecked((int)0x80310094);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_REMOVAL_OF_DRA_FAILED = unchecked((int)0x80310095);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME = unchecked((int)0x80310096);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME = unchecked((int)0x80310097);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FIPS_HASH_KDF_NOT_ALLOWED = unchecked((int)0x80310098);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_ENH_PIN_INVALID = unchecked((int)0x80310099);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_PIN_CHARS = unchecked((int)0x8031009A);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_DATUM_TYPE = unchecked((int)0x8031009B);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EFI_ONLY = unchecked((int)0x8031009C);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_MULTIPLE_NKP_CERTS = unchecked((int)0x8031009D);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_REMOVAL_OF_NKP_FAILED = unchecked((int)0x8031009E);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_NKP_CERT = unchecked((int)0x8031009F);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_EXISTING_PIN = unchecked((int)0x803100A0);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_CHANGE_PIN_MISMATCH = unchecked((int)0x803100A1);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PIN_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED = unchecked((int)0x803100A2);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_CHANGE_MAX_PIN_CHANGE_ATTEMPTS_REACHED = unchecked((int)0x803100A3);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_PASSPHRASE_REQUIRES_ASCII = unchecked((int)0x803100A4);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_FULL_ENCRYPTION_NOT_ALLOWED_ON_TP_STORAGE = unchecked((int)0x803100A5);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_WIPE_NOT_ALLOWED_ON_TP_STORAGE = unchecked((int)0x803100A6);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEY_LENGTH_NOT_SUPPORTED_BY_EDRIVE = unchecked((int)0x803100A7);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_EXISTING_PASSPHRASE = unchecked((int)0x803100A8);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_CHANGE_PASSPHRASE_MISMATCH = unchecked((int)0x803100A9);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PASSPHRASE_TOO_LONG = unchecked((int)0x803100AA);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_PASSPHRASE_WITH_TPM = unchecked((int)0x803100AB);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_TPM_WITH_PASSPHRASE = unchecked((int)0x803100AC);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ALLOWED_ON_CSV_STACK = unchecked((int)0x803100AD);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ALLOWED_ON_CLUSTER = unchecked((int)0x803100AE);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_NO_FAILOVER_TO_SW = unchecked((int)0x803100AF);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_BAND_IN_USE = unchecked((int)0x803100B0);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_DISALLOWED_BY_GP = unchecked((int)0x803100B1);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_INCOMPATIBLE_VOLUME = unchecked((int)0x803100B2);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_ALLOWED_TO_UPGRADE_WHILE_CONVERTING = unchecked((int)0x803100B3);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_DV_NOT_SUPPORTED = unchecked((int)0x803100B4);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_PREBOOT_KEYBOARD_DETECTED = unchecked((int)0x803100B5);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_PREBOOT_KEYBOARD_OR_WINRE_DETECTED = unchecked((int)0x803100B6);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_REQUIRES_STARTUP_PIN_ON_TOUCH_DEVICE = unchecked((int)0x803100B7);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_REQUIRES_RECOVERY_PASSWORD_ON_TOUCH_DEVICE = unchecked((int)0x803100B8);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_WIPE_CANCEL_NOT_APPLICABLE = unchecked((int)0x803100B9);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_SECUREBOOT_DISABLED = unchecked((int)0x803100BA);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_SECUREBOOT_CONFIGURATION_INVALID = unchecked((int)0x803100BB);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_DRY_RUN_FAILED = unchecked((int)0x803100BC);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_SHADOW_COPY_PRESENT = unchecked((int)0x803100BD);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_POLICY_INVALID_ENHANCED_BCD_SETTINGS = unchecked((int)0x803100BE);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EDRIVE_INCOMPATIBLE_FIRMWARE = unchecked((int)0x803100BF);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTOR_CHANGE_MAX_PASSPHRASE_CHANGE_ATTEMPTS_REACHED = unchecked((int)0x803100C0);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PASSPHRASE_PROTECTOR_CHANGE_BY_STD_USER_DISALLOWED = unchecked((int)0x803100C1);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_LIVEID_ACCOUNT_SUSPENDED = unchecked((int)0x803100C2);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_LIVEID_ACCOUNT_BLOCKED = unchecked((int)0x803100C3);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_PROVISIONED_ON_ALL_VOLUMES = unchecked((int)0x803100C4);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_FIXED_DATA_NOT_SUPPORTED = unchecked((int)0x803100C5);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_HARDWARE_NOT_COMPLIANT = unchecked((int)0x803100C6);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_WINRE_NOT_CONFIGURED = unchecked((int)0x803100C7);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_PROTECTION_SUSPENDED = unchecked((int)0x803100C8);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_OS_VOLUME_NOT_PROTECTED = unchecked((int)0x803100C9);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_DEVICE_LOCKEDOUT = unchecked((int)0x803100CA);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_PROTECTION_NOT_YET_ENABLED = unchecked((int)0x803100CB);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_INVALID_PIN_CHARS_DETAILED = unchecked((int)0x803100CC);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DEVICE_LOCKOUT_COUNTER_UNAVAILABLE = unchecked((int)0x803100CD);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DEVICELOCKOUT_COUNTER_MISMATCH = unchecked((int)0x803100CE);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_BUFFER_TOO_LARGE = unchecked((int)0x803100CF);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NO_SUCH_CAPABILITY_ON_TARGET = unchecked((int)0x803100D0);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_PREVENTED_FOR_OS = unchecked((int)0x803100D1);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_VOLUME_OPTED_OUT = unchecked((int)0x803100D2);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DE_VOLUME_NOT_SUPPORTED = unchecked((int)0x803100D3);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EOW_NOT_SUPPORTED_IN_VERSION = unchecked((int)0x803100D4);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_ADBACKUP_NOT_ENABLED = unchecked((int)0x803100D5);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_VOLUME_EXTEND_PREVENTS_EOW_DECRYPT = unchecked((int)0x803100D6);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_NOT_DE_VOLUME = unchecked((int)0x803100D7);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_PROTECTION_CANNOT_BE_DISABLED = unchecked((int)0x803100D8);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_OSV_KSR_NOT_ALLOWED = unchecked((int)0x803100D9);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_OS_DRIVE = unchecked((int)0x803100DA);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_FIXED_DRIVE = unchecked((int)0x803100DB);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AD_BACKUP_REQUIRED_POLICY_NOT_SET_REMOVABLE_DRIVE = unchecked((int)0x803100DC);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEY_ROTATION_NOT_SUPPORTED = unchecked((int)0x803100DD);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_EXECUTE_REQUEST_SENT_TOO_SOON = unchecked((int)0x803100DE);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_KEY_ROTATION_NOT_ENABLED = unchecked((int)0x803100DF);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_DEVICE_NOT_JOINED = unchecked((int)0x803100E0);

        [NativeTypeName("HRESULT")]
        public const int FVE_E_AAD_ENDPOINT_BUSY = unchecked((int)0x803100E1);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CALLOUT_NOT_FOUND = unchecked((int)0x80320001);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CONDITION_NOT_FOUND = unchecked((int)0x80320002);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_FILTER_NOT_FOUND = unchecked((int)0x80320003);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_LAYER_NOT_FOUND = unchecked((int)0x80320004);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_PROVIDER_NOT_FOUND = unchecked((int)0x80320005);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_PROVIDER_CONTEXT_NOT_FOUND = unchecked((int)0x80320006);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_SUBLAYER_NOT_FOUND = unchecked((int)0x80320007);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NOT_FOUND = unchecked((int)0x80320008);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_ALREADY_EXISTS = unchecked((int)0x80320009);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_IN_USE = unchecked((int)0x8032000A);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_DYNAMIC_SESSION_IN_PROGRESS = unchecked((int)0x8032000B);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_WRONG_SESSION = unchecked((int)0x8032000C);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NO_TXN_IN_PROGRESS = unchecked((int)0x8032000D);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TXN_IN_PROGRESS = unchecked((int)0x8032000E);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TXN_ABORTED = unchecked((int)0x8032000F);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_SESSION_ABORTED = unchecked((int)0x80320010);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_TXN = unchecked((int)0x80320011);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TIMEOUT = unchecked((int)0x80320012);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NET_EVENTS_DISABLED = unchecked((int)0x80320013);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_LAYER = unchecked((int)0x80320014);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_KM_CLIENTS_ONLY = unchecked((int)0x80320015);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_LIFETIME_MISMATCH = unchecked((int)0x80320016);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_BUILTIN_OBJECT = unchecked((int)0x80320017);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TOO_MANY_CALLOUTS = unchecked((int)0x80320018);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NOTIFICATION_DROPPED = unchecked((int)0x80320019);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TRAFFIC_MISMATCH = unchecked((int)0x8032001A);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_SA_STATE = unchecked((int)0x8032001B);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NULL_POINTER = unchecked((int)0x8032001C);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_ENUMERATOR = unchecked((int)0x8032001D);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_FLAGS = unchecked((int)0x8032001E);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_NET_MASK = unchecked((int)0x8032001F);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_RANGE = unchecked((int)0x80320020);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_INTERVAL = unchecked((int)0x80320021);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_ZERO_LENGTH_ARRAY = unchecked((int)0x80320022);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NULL_DISPLAY_NAME = unchecked((int)0x80320023);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_ACTION_TYPE = unchecked((int)0x80320024);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_WEIGHT = unchecked((int)0x80320025);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_MATCH_TYPE_MISMATCH = unchecked((int)0x80320026);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TYPE_MISMATCH = unchecked((int)0x80320027);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_OUT_OF_BOUNDS = unchecked((int)0x80320028);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_RESERVED = unchecked((int)0x80320029);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_DUPLICATE_CONDITION = unchecked((int)0x8032002A);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_DUPLICATE_KEYMOD = unchecked((int)0x8032002B);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER = unchecked((int)0x8032002C);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER = unchecked((int)0x8032002D);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER = unchecked((int)0x8032002E);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT = unchecked((int)0x8032002F);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_AUTH_METHOD = unchecked((int)0x80320030);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_DH_GROUP = unchecked((int)0x80320031);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_EM_NOT_SUPPORTED = unchecked((int)0x80320032);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_NEVER_MATCH = unchecked((int)0x80320033);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_PROVIDER_CONTEXT_MISMATCH = unchecked((int)0x80320034);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_PARAMETER = unchecked((int)0x80320035);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_TOO_MANY_SUBLAYERS = unchecked((int)0x80320036);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CALLOUT_NOTIFICATION_FAILED = unchecked((int)0x80320037);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_AUTH_TRANSFORM = unchecked((int)0x80320038);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_CIPHER_TRANSFORM = unchecked((int)0x80320039);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM = unchecked((int)0x8032003A);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_TRANSFORM_COMBINATION = unchecked((int)0x8032003B);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_DUPLICATE_AUTH_METHOD = unchecked((int)0x8032003C);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_TUNNEL_ENDPOINT = unchecked((int)0x8032003D);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_L2_DRIVER_NOT_READY = unchecked((int)0x8032003E);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_KEY_DICTATOR_ALREADY_REGISTERED = unchecked((int)0x8032003F);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_KEY_DICTATION_INVALID_KEYING_MATERIAL = unchecked((int)0x80320040);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_CONNECTIONS_DISABLED = unchecked((int)0x80320041);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_INVALID_DNS_NAME = unchecked((int)0x80320042);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_STILL_ON = unchecked((int)0x80320043);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_IKEEXT_NOT_RUNNING = unchecked((int)0x80320044);

        [NativeTypeName("HRESULT")]
        public const int FWP_E_DROP_NOICMP = unchecked((int)0x80320104);

        [NativeTypeName("HRESULT")]
        public const int WS_S_ASYNC = 0x003D0000;

        [NativeTypeName("HRESULT")]
        public const int WS_S_END = 0x003D0001;

        [NativeTypeName("HRESULT")]
        public const int WS_E_INVALID_FORMAT = unchecked((int)0x803D0000);

        [NativeTypeName("HRESULT")]
        public const int WS_E_OBJECT_FAULTED = unchecked((int)0x803D0001);

        [NativeTypeName("HRESULT")]
        public const int WS_E_NUMERIC_OVERFLOW = unchecked((int)0x803D0002);

        [NativeTypeName("HRESULT")]
        public const int WS_E_INVALID_OPERATION = unchecked((int)0x803D0003);

        [NativeTypeName("HRESULT")]
        public const int WS_E_OPERATION_ABORTED = unchecked((int)0x803D0004);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_ACCESS_DENIED = unchecked((int)0x803D0005);

        [NativeTypeName("HRESULT")]
        public const int WS_E_OPERATION_TIMED_OUT = unchecked((int)0x803D0006);

        [NativeTypeName("HRESULT")]
        public const int WS_E_OPERATION_ABANDONED = unchecked((int)0x803D0007);

        [NativeTypeName("HRESULT")]
        public const int WS_E_QUOTA_EXCEEDED = unchecked((int)0x803D0008);

        [NativeTypeName("HRESULT")]
        public const int WS_E_NO_TRANSLATION_AVAILABLE = unchecked((int)0x803D0009);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SECURITY_VERIFICATION_FAILURE = unchecked((int)0x803D000A);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ADDRESS_IN_USE = unchecked((int)0x803D000B);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ADDRESS_NOT_AVAILABLE = unchecked((int)0x803D000C);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_NOT_FOUND = unchecked((int)0x803D000D);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_NOT_AVAILABLE = unchecked((int)0x803D000E);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_FAILURE = unchecked((int)0x803D000F);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_UNREACHABLE = unchecked((int)0x803D0010);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_ACTION_NOT_SUPPORTED = unchecked((int)0x803D0011);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_TOO_BUSY = unchecked((int)0x803D0012);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_FAULT_RECEIVED = unchecked((int)0x803D0013);

        [NativeTypeName("HRESULT")]
        public const int WS_E_ENDPOINT_DISCONNECTED = unchecked((int)0x803D0014);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_FAILURE = unchecked((int)0x803D0015);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_ACCESS_DENIED = unchecked((int)0x803D0016);

        [NativeTypeName("HRESULT")]
        public const int WS_E_NOT_SUPPORTED = unchecked((int)0x803D0017);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_REQUIRES_BASIC_AUTH = unchecked((int)0x803D0018);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_REQUIRES_DIGEST_AUTH = unchecked((int)0x803D0019);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_REQUIRES_NTLM_AUTH = unchecked((int)0x803D001A);

        [NativeTypeName("HRESULT")]
        public const int WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH = unchecked((int)0x803D001B);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SERVER_REQUIRES_BASIC_AUTH = unchecked((int)0x803D001C);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SERVER_REQUIRES_DIGEST_AUTH = unchecked((int)0x803D001D);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SERVER_REQUIRES_NTLM_AUTH = unchecked((int)0x803D001E);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH = unchecked((int)0x803D001F);

        [NativeTypeName("HRESULT")]
        public const int WS_E_INVALID_ENDPOINT_URL = unchecked((int)0x803D0020);

        [NativeTypeName("HRESULT")]
        public const int WS_E_OTHER = unchecked((int)0x803D0021);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SECURITY_TOKEN_EXPIRED = unchecked((int)0x803D0022);

        [NativeTypeName("HRESULT")]
        public const int WS_E_SECURITY_SYSTEM_FAILURE = unchecked((int)0x803D0023);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_TERMINATED_DURING_START = unchecked((int)0x80370100);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_IMAGE_MISMATCH = unchecked((int)0x80370101);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_HYPERV_NOT_INSTALLED = unchecked((int)0x80370102);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_INVALID_STATE = unchecked((int)0x80370105);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_UNEXPECTED_EXIT = unchecked((int)0x80370106);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_TERMINATED = unchecked((int)0x80370107);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_CONNECT_FAILED = unchecked((int)0x80370108);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_CONNECTION_TIMEOUT = unchecked((int)0x80370109);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_CONNECTION_CLOSED = unchecked((int)0x8037010A);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_UNKNOWN_MESSAGE = unchecked((int)0x8037010B);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_UNSUPPORTED_PROTOCOL_VERSION = unchecked((int)0x8037010C);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_INVALID_JSON = unchecked((int)0x8037010D);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_SYSTEM_NOT_FOUND = unchecked((int)0x8037010E);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_SYSTEM_ALREADY_EXISTS = unchecked((int)0x8037010F);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_SYSTEM_ALREADY_STOPPED = unchecked((int)0x80370110);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_PROTOCOL_ERROR = unchecked((int)0x80370111);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_INVALID_LAYER = unchecked((int)0x80370112);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_WINDOWS_INSIDER_REQUIRED = unchecked((int)0x80370113);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_SERVICE_NOT_AVAILABLE = unchecked((int)0x80370114);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_NOT_STARTED = unchecked((int)0x80370115);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_ALREADY_STARTED = unchecked((int)0x80370116);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_PENDING = unchecked((int)0x80370117);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_TIMEOUT = unchecked((int)0x80370118);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_SYSTEM_CALLBACK_ALREADY_SET = unchecked((int)0x80370119);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_OPERATION_RESULT_ALLOCATION_FAILED = unchecked((int)0x8037011A);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_ACCESS_DENIED = unchecked((int)0x8037011B);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_GUEST_CRITICAL_ERROR = unchecked((int)0x8037011C);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_PROCESS_INFO_NOT_AVAILABLE = unchecked((int)0x8037011D);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_SERVICE_DISCONNECT = unchecked((int)0x8037011E);

        [NativeTypeName("HRESULT")]
        public const int HCS_E_PROCESS_ALREADY_STOPPED = unchecked((int)0x8037011F);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_UNKNOWN_CAPABILITY = unchecked((int)0x80370300);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_INSUFFICIENT_BUFFER = unchecked((int)0x80370301);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_UNKNOWN_PROPERTY = unchecked((int)0x80370302);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_UNSUPPORTED_HYPERVISOR_CONFIG = unchecked((int)0x80370303);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_INVALID_PARTITION_CONFIG = unchecked((int)0x80370304);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_GPA_RANGE_NOT_FOUND = unchecked((int)0x80370305);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_VP_ALREADY_EXISTS = unchecked((int)0x80370306);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_VP_DOES_NOT_EXIST = unchecked((int)0x80370307);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_INVALID_VP_STATE = unchecked((int)0x80370308);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_INVALID_VP_REGISTER_NAME = unchecked((int)0x80370309);

        [NativeTypeName("HRESULT")]
        public const int WHV_E_UNSUPPORTED_PROCESSOR_CONFIG = unchecked((int)0x80370310);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_PARTITION_STATE_NOT_FOUND = unchecked((int)0xC0370500);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_GUEST_MEMORY_NOT_FOUND = unchecked((int)0xC0370501);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_NO_VP_FOUND_IN_PARTITION_STATE = unchecked((int)0xC0370502);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_NESTED_VIRTUALIZATION_NOT_SUPPORTED = unchecked((int)0xC0370503);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_WINDOWS_KERNEL_IMAGE_NOT_FOUND = unchecked((int)0xC0370504);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_PXE_NOT_PRESENT = unchecked((int)0xC0370505);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_PDPTE_NOT_PRESENT = unchecked((int)0xC0370506);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_PDE_NOT_PRESENT = unchecked((int)0xC0370507);

        [NativeTypeName("HRESULT")]
        public const int VM_SAVED_STATE_DUMP_E_PTE_NOT_PRESENT = unchecked((int)0xC0370508);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_NETWORK_NOT_FOUND = unchecked((int)0x803B0001);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_NOT_FOUND = unchecked((int)0x803B0002);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_LAYER_NOT_FOUND = unchecked((int)0x803B0003);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_SWITCH_NOT_FOUND = unchecked((int)0x803B0004);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_SUBNET_NOT_FOUND = unchecked((int)0x803B0005);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ADAPTER_NOT_FOUND = unchecked((int)0x803B0006);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_PORT_NOT_FOUND = unchecked((int)0x803B0007);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_POLICY_NOT_FOUND = unchecked((int)0x803B0008);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_VFP_PORTSETTING_NOT_FOUND = unchecked((int)0x803B0009);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_NETWORK = unchecked((int)0x803B000A);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_NETWORK_TYPE = unchecked((int)0x803B000B);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_ENDPOINT = unchecked((int)0x803B000C);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_POLICY = unchecked((int)0x803B000D);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_POLICY_TYPE = unchecked((int)0x803B000E);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_REMOTE_ENDPOINT_OPERATION = unchecked((int)0x803B000F);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_NETWORK_ALREADY_EXISTS = unchecked((int)0x803B0010);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_LAYER_ALREADY_EXISTS = unchecked((int)0x803B0011);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_POLICY_ALREADY_EXISTS = unchecked((int)0x803B0012);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_PORT_ALREADY_EXISTS = unchecked((int)0x803B0013);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_ALREADY_ATTACHED = unchecked((int)0x803B0014);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_REQUEST_UNSUPPORTED = unchecked((int)0x803B0015);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_MAPPING_NOT_SUPPORTED = unchecked((int)0x803B0016);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_DEGRADED_OPERATION = unchecked((int)0x803B0017);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_SHARED_SWITCH_MODIFICATION = unchecked((int)0x803B0018);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_GUID_CONVERSION_FAILURE = unchecked((int)0x803B0019);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_REGKEY_FAILURE = unchecked((int)0x803B001A);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_JSON = unchecked((int)0x803B001B);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_JSON_REFERENCE = unchecked((int)0x803B001C);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_SHARING_DISABLED = unchecked((int)0x803B001D);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_IP = unchecked((int)0x803B001E);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_SWITCH_EXTENSION_NOT_FOUND = unchecked((int)0x803B001F);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_MANAGER_STOPPED = unchecked((int)0x803B0020);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_MODULE_NOT_FOUND = unchecked((int)0x803B0021);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_NO_REQUEST_HANDLERS = unchecked((int)0x803B0022);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_REQUEST_UNSUPPORTED = unchecked((int)0x803B0023);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_RUNTIMEKEYS_FAILED = unchecked((int)0x803B0024);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_NETADAPTER_TIMEOUT = unchecked((int)0x803B0025);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_NETADAPTER_NOT_FOUND = unchecked((int)0x803B0026);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_NETCOMPARTMENT_NOT_FOUND = unchecked((int)0x803B0027);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_NETINTERFACE_NOT_FOUND = unchecked((int)0x803B0028);

        [NativeTypeName("HRESULT")]
        public const int GCN_E_DEFAULTNAMESPACE_EXISTS = unchecked((int)0x803B0029);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ICS_DISABLED = unchecked((int)0x803B002A);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_NAMESPACE_ALREADY_EXISTS = unchecked((int)0x803B002B);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENTITY_HAS_REFERENCES = unchecked((int)0x803B002C);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_INTERNAL_PORT = unchecked((int)0x803B002D);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_NAMESPACE_ATTACH_FAILED = unchecked((int)0x803B002E);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ADDR_INVALID_OR_RESERVED = unchecked((int)0x803B002F);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_PREFIX = unchecked((int)0x803B0030);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_OBJECT_USED_AFTER_UNLOAD = unchecked((int)0x803B0031);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_SUBNET = unchecked((int)0x803B0032);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_INVALID_IP_SUBNET = unchecked((int)0x803B0033);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_NOT_ATTACHED = unchecked((int)0x803B0034);

        [NativeTypeName("HRESULT")]
        public const int HCN_E_ENDPOINT_NOT_LOCAL = unchecked((int)0x803B0035);

        [NativeTypeName("HRESULT")]
        public const int HCN_INTERFACEPARAMETERS_ALREADY_APPLIED = unchecked((int)0x803B0036);

        public const int SDIAG_E_CANCELLED = unchecked((int)0x803C0100);

        public const int SDIAG_E_SCRIPT = unchecked((int)0x803C0101);

        public const int SDIAG_E_POWERSHELL = unchecked((int)0x803C0102);

        public const int SDIAG_E_MANAGEDHOST = unchecked((int)0x803C0103);

        public const int SDIAG_E_NOVERIFIER = unchecked((int)0x803C0104);

        public const int SDIAG_S_CANNOTRUN = 0x003C0105;

        public const int SDIAG_E_DISABLED = unchecked((int)0x803C0106);

        public const int SDIAG_E_TRUST = unchecked((int)0x803C0107);

        public const int SDIAG_E_CANNOTRUN = unchecked((int)0x803C0108);

        public const int SDIAG_E_VERSION = unchecked((int)0x803C0109);

        public const int SDIAG_E_RESOURCE = unchecked((int)0x803C010A);

        public const int SDIAG_E_ROOTCAUSE = unchecked((int)0x803C010B);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CHANNEL_CLOSED = unchecked((int)0x803E0100);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CHANNEL_REQUEST_NOT_COMPLETE = unchecked((int)0x803E0101);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_INVALID_APP = unchecked((int)0x803E0102);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_OUTSTANDING_CHANNEL_REQUEST = unchecked((int)0x803E0103);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_DUPLICATE_CHANNEL = unchecked((int)0x803E0104);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_PLATFORM_UNAVAILABLE = unchecked((int)0x803E0105);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_POSTED = unchecked((int)0x803E0106);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_HIDDEN = unchecked((int)0x803E0107);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_NOT_POSTED = unchecked((int)0x803E0108);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CLOUD_DISABLED = unchecked((int)0x803E0109);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CLOUD_INCAPABLE = unchecked((int)0x803E0110);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CLOUD_AUTH_UNAVAILABLE = unchecked((int)0x803E011A);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CLOUD_SERVICE_UNAVAILABLE = unchecked((int)0x803E011B);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_FAILED_LOCK_SCREEN_UPDATE_INTIALIZATION = unchecked((int)0x803E011C);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_DISABLED = unchecked((int)0x803E0111);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_INCAPABLE = unchecked((int)0x803E0112);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_INTERNET_INCAPABLE = unchecked((int)0x803E0113);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_TYPE_DISABLED = unchecked((int)0x803E0114);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_SIZE = unchecked((int)0x803E0115);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_TAG_SIZE = unchecked((int)0x803E0116);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_ACCESS_DENIED = unchecked((int)0x803E0117);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_DUPLICATE_REGISTRATION = unchecked((int)0x803E0118);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_PUSH_NOTIFICATION_INCAPABLE = unchecked((int)0x803E0119);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_DEV_ID_SIZE = unchecked((int)0x803E0120);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_TAG_ALPHANUMERIC = unchecked((int)0x803E012A);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_INVALID_HTTP_STATUS_CODE = unchecked((int)0x803E012B);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_OUT_OF_SESSION = unchecked((int)0x803E0200);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_POWER_SAVE = unchecked((int)0x803E0201);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_IMAGE_NOT_FOUND_IN_CACHE = unchecked((int)0x803E0202);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_ALL_URL_NOT_COMPLETED = unchecked((int)0x803E0203);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_INVALID_CLOUD_IMAGE = unchecked((int)0x803E0204);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_NOTIFICATION_ID_MATCHED = unchecked((int)0x803E0205);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CALLBACK_ALREADY_REGISTERED = unchecked((int)0x803E0206);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_TOAST_NOTIFICATION_DROPPED = unchecked((int)0x803E0207);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_STORAGE_LOCKED = unchecked((int)0x803E0208);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_GROUP_SIZE = unchecked((int)0x803E0209);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_GROUP_ALPHANUMERIC = unchecked((int)0x803E020A);

        [NativeTypeName("HRESULT")]
        public const int WPN_E_CLOUD_DISABLED_FOR_APP = unchecked((int)0x803E020B);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_CONTEXT_NOT_ACTIVATED = unchecked((int)0x80548201);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_BAD_SIM = unchecked((int)0x80548202);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_DATA_CLASS_NOT_AVAILABLE = unchecked((int)0x80548203);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_INVALID_ACCESS_STRING = unchecked((int)0x80548204);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_MAX_ACTIVATED_CONTEXTS = unchecked((int)0x80548205);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PACKET_SVC_DETACHED = unchecked((int)0x80548206);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PROVIDER_NOT_VISIBLE = unchecked((int)0x80548207);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_RADIO_POWER_OFF = unchecked((int)0x80548208);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SERVICE_NOT_ACTIVATED = unchecked((int)0x80548209);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SIM_NOT_INSERTED = unchecked((int)0x8054820A);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_VOICE_CALL_IN_PROGRESS = unchecked((int)0x8054820B);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_INVALID_CACHE = unchecked((int)0x8054820C);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_NOT_REGISTERED = unchecked((int)0x8054820D);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PROVIDERS_NOT_FOUND = unchecked((int)0x8054820E);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PIN_NOT_SUPPORTED = unchecked((int)0x8054820F);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PIN_REQUIRED = unchecked((int)0x80548210);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_PIN_DISABLED = unchecked((int)0x80548211);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_FAILURE = unchecked((int)0x80548212);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_INVALID_PROFILE = unchecked((int)0x80548218);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_DEFAULT_PROFILE_EXIST = unchecked((int)0x80548219);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_ENCODING_NOT_SUPPORTED = unchecked((int)0x80548220);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_FILTER_NOT_SUPPORTED = unchecked((int)0x80548221);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_INVALID_MEMORY_INDEX = unchecked((int)0x80548222);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_LANG_NOT_SUPPORTED = unchecked((int)0x80548223);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_MEMORY_FAILURE = unchecked((int)0x80548224);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_NETWORK_TIMEOUT = unchecked((int)0x80548225);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_UNKNOWN_SMSC_ADDRESS = unchecked((int)0x80548226);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_FORMAT_NOT_SUPPORTED = unchecked((int)0x80548227);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_OPERATION_NOT_ALLOWED = unchecked((int)0x80548228);

        [NativeTypeName("HRESULT")]
        public const int E_MBN_SMS_MEMORY_FULL = unchecked((int)0x80548229);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_IPV6_NOT_INSTALLED = unchecked((int)0x80630001);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NOT_INITIALIZED = unchecked((int)0x80630002);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CANNOT_START_SERVICE = unchecked((int)0x80630003);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NOT_LICENSED = unchecked((int)0x80630004);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_GRAPH = unchecked((int)0x80630010);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DBNAME_CHANGED = unchecked((int)0x80630011);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DUPLICATE_GRAPH = unchecked((int)0x80630012);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GRAPH_NOT_READY = unchecked((int)0x80630013);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GRAPH_SHUTTING_DOWN = unchecked((int)0x80630014);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GRAPH_IN_USE = unchecked((int)0x80630015);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_DATABASE = unchecked((int)0x80630016);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_TOO_MANY_ATTRIBUTES = unchecked((int)0x80630017);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONNECTION_NOT_FOUND = unchecked((int)0x80630103);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONNECT_SELF = unchecked((int)0x80630106);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_ALREADY_LISTENING = unchecked((int)0x80630107);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NODE_NOT_FOUND = unchecked((int)0x80630108);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONNECTION_FAILED = unchecked((int)0x80630109);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONNECTION_NOT_AUTHENTICATED = unchecked((int)0x8063010A);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONNECTION_REFUSED = unchecked((int)0x8063010B);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLASSIFIER_TOO_LONG = unchecked((int)0x80630201);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_TOO_MANY_IDENTITIES = unchecked((int)0x80630202);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NO_KEY_ACCESS = unchecked((int)0x80630203);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GROUPS_EXIST = unchecked((int)0x80630204);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_RECORD_NOT_FOUND = unchecked((int)0x80630301);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DATABASE_ACCESSDENIED = unchecked((int)0x80630302);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DBINITIALIZATION_FAILED = unchecked((int)0x80630303);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_MAX_RECORD_SIZE_EXCEEDED = unchecked((int)0x80630304);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DATABASE_ALREADY_PRESENT = unchecked((int)0x80630305);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DATABASE_NOT_PRESENT = unchecked((int)0x80630306);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_IDENTITY_NOT_FOUND = unchecked((int)0x80630401);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_EVENT_HANDLE_NOT_FOUND = unchecked((int)0x80630501);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_SEARCH = unchecked((int)0x80630601);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_ATTRIBUTES = unchecked((int)0x80630602);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVITATION_NOT_TRUSTED = unchecked((int)0x80630701);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CHAIN_TOO_LONG = unchecked((int)0x80630703);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_TIME_PERIOD = unchecked((int)0x80630705);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CIRCULAR_CHAIN_DETECTED = unchecked((int)0x80630706);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CERT_STORE_CORRUPTED = unchecked((int)0x80630801);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NO_CLOUD = unchecked((int)0x80631001);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CLOUD_NAME_AMBIGUOUS = unchecked((int)0x80631005);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_RECORD = unchecked((int)0x80632010);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NOT_AUTHORIZED = unchecked((int)0x80632020);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_PASSWORD_DOES_NOT_MEET_POLICY = unchecked((int)0x80632021);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_DEFERRED_VALIDATION = unchecked((int)0x80632030);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_GROUP_PROPERTIES = unchecked((int)0x80632040);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_PEER_NAME = unchecked((int)0x80632050);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_CLASSIFIER = unchecked((int)0x80632060);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_FRIENDLY_NAME = unchecked((int)0x80632070);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_ROLE_PROPERTY = unchecked((int)0x80632071);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_CLASSIFIER_PROPERTY = unchecked((int)0x80632072);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_RECORD_EXPIRATION = unchecked((int)0x80632080);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_CREDENTIAL_INFO = unchecked((int)0x80632081);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_CREDENTIAL = unchecked((int)0x80632082);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_RECORD_SIZE = unchecked((int)0x80632083);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_UNSUPPORTED_VERSION = unchecked((int)0x80632090);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GROUP_NOT_READY = unchecked((int)0x80632091);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_GROUP_IN_USE = unchecked((int)0x80632092);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_GROUP = unchecked((int)0x80632093);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NO_MEMBERS_FOUND = unchecked((int)0x80632094);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NO_MEMBER_CONNECTIONS = unchecked((int)0x80632095);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_UNABLE_TO_LISTEN = unchecked((int)0x80632096);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_IDENTITY_DELETED = unchecked((int)0x806320A0);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_SERVICE_NOT_AVAILABLE = unchecked((int)0x806320A1);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CONTACT_NOT_FOUND = unchecked((int)0x80636001);

        [NativeTypeName("HRESULT")]
        public const int PEER_S_GRAPH_DATA_CREATED = 0x00630001;

        [NativeTypeName("HRESULT")]
        public const int PEER_S_NO_EVENT_DATA = 0x00630002;

        [NativeTypeName("HRESULT")]
        public const int PEER_S_ALREADY_CONNECTED = 0x00632000;

        [NativeTypeName("HRESULT")]
        public const int PEER_S_SUBSCRIPTION_EXISTS = 0x00636000;

        [NativeTypeName("HRESULT")]
        public const int PEER_S_NO_CONNECTIVITY = 0x00630005;

        [NativeTypeName("HRESULT")]
        public const int PEER_S_ALREADY_A_MEMBER = 0x00630006;

        [NativeTypeName("HRESULT")]
        public const int PEER_E_CANNOT_CONVERT_PEER_NAME = unchecked((int)0x80634001);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_PEER_HOST_NAME = unchecked((int)0x80634002);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NO_MORE = unchecked((int)0x80634003);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_PNRP_DUPLICATE_PEER_NAME = unchecked((int)0x80634005);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVITE_CANCELLED = unchecked((int)0x80637000);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVITE_RESPONSE_NOT_AVAILABLE = unchecked((int)0x80637001);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_NOT_SIGNED_IN = unchecked((int)0x80637003);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_PRIVACY_DECLINED = unchecked((int)0x80637004);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_TIMEOUT = unchecked((int)0x80637005);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_INVALID_ADDRESS = unchecked((int)0x80637007);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_FW_EXCEPTION_DISABLED = unchecked((int)0x80637008);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_FW_BLOCKED_BY_POLICY = unchecked((int)0x80637009);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_FW_BLOCKED_BY_SHIELDS_UP = unchecked((int)0x8063700A);

        [NativeTypeName("HRESULT")]
        public const int PEER_E_FW_DECLINED = unchecked((int)0x8063700B);

        [NativeTypeName("HRESULT")]
        public const int UI_E_CREATE_FAILED = unchecked((int)0x802A0001);

        [NativeTypeName("HRESULT")]
        public const int UI_E_SHUTDOWN_CALLED = unchecked((int)0x802A0002);

        [NativeTypeName("HRESULT")]
        public const int UI_E_ILLEGAL_REENTRANCY = unchecked((int)0x802A0003);

        [NativeTypeName("HRESULT")]
        public const int UI_E_OBJECT_SEALED = unchecked((int)0x802A0004);

        [NativeTypeName("HRESULT")]
        public const int UI_E_VALUE_NOT_SET = unchecked((int)0x802A0005);

        [NativeTypeName("HRESULT")]
        public const int UI_E_VALUE_NOT_DETERMINED = unchecked((int)0x802A0006);

        [NativeTypeName("HRESULT")]
        public const int UI_E_INVALID_OUTPUT = unchecked((int)0x802A0007);

        [NativeTypeName("HRESULT")]
        public const int UI_E_BOOLEAN_EXPECTED = unchecked((int)0x802A0008);

        [NativeTypeName("HRESULT")]
        public const int UI_E_DIFFERENT_OWNER = unchecked((int)0x802A0009);

        [NativeTypeName("HRESULT")]
        public const int UI_E_AMBIGUOUS_MATCH = unchecked((int)0x802A000A);

        [NativeTypeName("HRESULT")]
        public const int UI_E_FP_OVERFLOW = unchecked((int)0x802A000B);

        [NativeTypeName("HRESULT")]
        public const int UI_E_WRONG_THREAD = unchecked((int)0x802A000C);

        [NativeTypeName("HRESULT")]
        public const int UI_E_STORYBOARD_ACTIVE = unchecked((int)0x802A0101);

        [NativeTypeName("HRESULT")]
        public const int UI_E_STORYBOARD_NOT_PLAYING = unchecked((int)0x802A0102);

        [NativeTypeName("HRESULT")]
        public const int UI_E_START_KEYFRAME_AFTER_END = unchecked((int)0x802A0103);

        [NativeTypeName("HRESULT")]
        public const int UI_E_END_KEYFRAME_NOT_DETERMINED = unchecked((int)0x802A0104);

        [NativeTypeName("HRESULT")]
        public const int UI_E_LOOPS_OVERLAP = unchecked((int)0x802A0105);

        [NativeTypeName("HRESULT")]
        public const int UI_E_TRANSITION_ALREADY_USED = unchecked((int)0x802A0106);

        [NativeTypeName("HRESULT")]
        public const int UI_E_TRANSITION_NOT_IN_STORYBOARD = unchecked((int)0x802A0107);

        [NativeTypeName("HRESULT")]
        public const int UI_E_TRANSITION_ECLIPSED = unchecked((int)0x802A0108);

        [NativeTypeName("HRESULT")]
        public const int UI_E_TIME_BEFORE_LAST_UPDATE = unchecked((int)0x802A0109);

        [NativeTypeName("HRESULT")]
        public const int UI_E_TIMER_CLIENT_ALREADY_CONNECTED = unchecked((int)0x802A010A);

        [NativeTypeName("HRESULT")]
        public const int UI_E_INVALID_DIMENSION = unchecked((int)0x802A010B);

        [NativeTypeName("HRESULT")]
        public const int UI_E_PRIMITIVE_OUT_OF_BOUNDS = unchecked((int)0x802A010C);

        [NativeTypeName("HRESULT")]
        public const int UI_E_WINDOW_CLOSED = unchecked((int)0x802A0201);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INVALID_HANDLE = unchecked((int)0x80650001);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_READ_NOT_PERMITTED = unchecked((int)0x80650002);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_WRITE_NOT_PERMITTED = unchecked((int)0x80650003);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INVALID_PDU = unchecked((int)0x80650004);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INSUFFICIENT_AUTHENTICATION = unchecked((int)0x80650005);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_REQUEST_NOT_SUPPORTED = unchecked((int)0x80650006);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INVALID_OFFSET = unchecked((int)0x80650007);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INSUFFICIENT_AUTHORIZATION = unchecked((int)0x80650008);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_PREPARE_QUEUE_FULL = unchecked((int)0x80650009);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_ATTRIBUTE_NOT_FOUND = unchecked((int)0x8065000A);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_ATTRIBUTE_NOT_LONG = unchecked((int)0x8065000B);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION_KEY_SIZE = unchecked((int)0x8065000C);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INVALID_ATTRIBUTE_VALUE_LENGTH = unchecked((int)0x8065000D);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_UNLIKELY = unchecked((int)0x8065000E);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INSUFFICIENT_ENCRYPTION = unchecked((int)0x8065000F);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_UNSUPPORTED_GROUP_TYPE = unchecked((int)0x80650010);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_INSUFFICIENT_RESOURCES = unchecked((int)0x80650011);

        [NativeTypeName("HRESULT")]
        public const int E_BLUETOOTH_ATT_UNKNOWN_ERROR = unchecked((int)0x80651000);

        [NativeTypeName("HRESULT")]
        public const int E_AUDIO_ENGINE_NODE_NOT_FOUND = unchecked((int)0x80660001);

        [NativeTypeName("HRESULT")]
        public const int E_HDAUDIO_EMPTY_CONNECTION_LIST = unchecked((int)0x80660002);

        [NativeTypeName("HRESULT")]
        public const int E_HDAUDIO_CONNECTION_LIST_NOT_SUPPORTED = unchecked((int)0x80660003);

        [NativeTypeName("HRESULT")]
        public const int E_HDAUDIO_NO_LOGICAL_DEVICES_CREATED = unchecked((int)0x80660004);

        [NativeTypeName("HRESULT")]
        public const int E_HDAUDIO_NULL_LINKED_LIST_ENTRY = unchecked((int)0x80660005);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_CONCURRENCY_LOCKING_FAILURE = unchecked((int)0x80670001);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_STATEMENT_INPROGRESS = unchecked((int)0x80670002);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_CONFIGURATION_INVALID = unchecked((int)0x80670003);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_UNKNOWN_SCHEMA_VERSION = unchecked((int)0x80670004);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_ERROR_DICTIONARY_CORRUPTED = unchecked((int)0x80670005);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_BLOCKED = unchecked((int)0x80670006);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_BUSY_RETRY = unchecked((int)0x80670007);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_BUSY_RECOVERY_RETRY = unchecked((int)0x80670008);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_LOCKED_RETRY = unchecked((int)0x80670009);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_LOCKED_SHAREDCACHE_RETRY = unchecked((int)0x8067000A);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_TRANSACTION_REQUIRED = unchecked((int)0x8067000B);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_BUSY_TIMEOUT_EXCEEDED = unchecked((int)0x8067000C);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_BUSY_RECOVERY_TIMEOUT_EXCEEDED = unchecked((int)0x8067000D);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_LOCKED_TIMEOUT_EXCEEDED = unchecked((int)0x8067000E);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_LOCKED_SHAREDCACHE_TIMEOUT_EXCEEDED = unchecked((int)0x8067000F);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_E_SERVICE_STOP_IN_PROGRESS = unchecked((int)0x80670010);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSTORY_E_NESTED_TRANSACTION_NOT_SUPPORTED = unchecked((int)0x80670011);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_ERROR_CACHE_CORRUPTED = unchecked((int)0x80670012);

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_TRANSACTION_CALLER_ID_CHANGED = 0x00670013;

        [NativeTypeName("HRESULT")]
        public const int STATEREPOSITORY_TRANSACTION_IN_PROGRESS = 0x00670014;

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_POOL_WAS_DELETED = 0x00E70001;

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_FAULT_DOMAIN_TYPE_INVALID = unchecked((int)0x80E70001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_INTERNAL_ERROR = unchecked((int)0x80E70002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_RESILIENCY_TYPE_INVALID = unchecked((int)0x80E70003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_DRIVE_SECTOR_SIZE_INVALID = unchecked((int)0x80E70004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_DRIVE_REDUNDANCY_INVALID = unchecked((int)0x80E70006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_NUMBER_OF_DATA_COPIES_INVALID = unchecked((int)0x80E70007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_PARITY_LAYOUT_INVALID = unchecked((int)0x80E70008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_INTERLEAVE_LENGTH_INVALID = unchecked((int)0x80E70009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_NUMBER_OF_COLUMNS_INVALID = unchecked((int)0x80E7000A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_NOT_ENOUGH_DRIVES = unchecked((int)0x80E7000B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_EXTENDED_ERROR = unchecked((int)0x80E7000C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_PROVISIONING_TYPE_INVALID = unchecked((int)0x80E7000D);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_ALLOCATION_SIZE_INVALID = unchecked((int)0x80E7000E);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_ENCLOSURE_AWARE_INVALID = unchecked((int)0x80E7000F);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_WRITE_CACHE_SIZE_INVALID = unchecked((int)0x80E70010);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_NUMBER_OF_GROUPS_INVALID = unchecked((int)0x80E70011);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_DRIVE_OPERATIONAL_STATE_INVALID = unchecked((int)0x80E70012);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_ENTRY_INCOMPLETE = unchecked((int)0x80E70013);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SPACES_ENTRY_INVALID = unchecked((int)0x80E70014);

        [NativeTypeName("HRESULT")]
        public const int ERROR_VOLSNAP_BOOTFILE_NOT_VALID = unchecked((int)0x80820001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_VOLSNAP_ACTIVATION_TIMEOUT = unchecked((int)0x80820002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_NOT_SUPPORTED_ON_VOLUME = unchecked((int)0x80830001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_VOLUME_DISMOUNT_IN_PROGRESS = unchecked((int)0x80830002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_STORAGE_TIER_NOT_FOUND = unchecked((int)0x80830003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_INVALID_FILE_ID = unchecked((int)0x80830004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_WRONG_CLUSTER_NODE = unchecked((int)0x80830005);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_ALREADY_PROCESSING = unchecked((int)0x80830006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_CANNOT_PIN_OBJECT = unchecked((int)0x80830007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_TIERING_FILE_IS_NOT_PINNED = unchecked((int)0x80830008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_NOT_A_TIERED_VOLUME = unchecked((int)0x80830009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_ATTRIBUTE_NOT_PRESENT = unchecked((int)0x8083000A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SECCORE_INVALID_COMMAND = unchecked((int)0xC0E80000);

        [NativeTypeName("HRESULT")]
        public const int ERROR_NO_APPLICABLE_APP_LICENSES_FOUND = unchecked((int)0xC0EA0001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_NOT_FOUND = unchecked((int)0xC0EA0002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_DEVICE_LICENSE_MISSING = unchecked((int)0xC0EA0003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_INVALID_SIGNATURE = unchecked((int)0xC0EA0004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_KEYHOLDER_LICENSE_MISSING_OR_INVALID = unchecked((int)0xC0EA0005);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_EXPIRED = unchecked((int)0xC0EA0006);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_SIGNED_BY_UNKNOWN_SOURCE = unchecked((int)0xC0EA0007);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_NOT_SIGNED = unchecked((int)0xC0EA0008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_HARDWARE_ID_OUT_OF_TOLERANCE = unchecked((int)0xC0EA0009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_CLIP_LICENSE_DEVICE_ID_MISMATCH = unchecked((int)0xC0EA000A);

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_OCCLUDED = 0x087A0001;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_CLIPPED = 0x087A0002;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_NO_REDIRECTION = 0x087A0004;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_NO_DESKTOP_ACCESS = 0x087A0005;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_GRAPHICS_VIDPN_SOURCE_IN_USE = 0x087A0006;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_MODE_CHANGED = 0x087A0007;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_MODE_CHANGE_IN_PROGRESS = 0x087A0008;

        [NativeTypeName("HRESULT")]
        public const int DXCORE_ERROR_EVENT_NOT_UNREGISTERED = unchecked((int)0x88800001);

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_UNOCCLUDED = 0x087A0009;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_DDA_WAS_STILL_DRAWING = 0x087A000A;

        [NativeTypeName("HRESULT")]
        public const int DXGI_STATUS_PRESENT_REQUIRED = 0x087A002F;

        [NativeTypeName("HRESULT")]
        public const int DXGI_DDI_ERR_WASSTILLDRAWING = unchecked((int)0x887B0001);

        [NativeTypeName("HRESULT")]
        public const int DXGI_DDI_ERR_UNSUPPORTED = unchecked((int)0x887B0002);

        [NativeTypeName("HRESULT")]
        public const int DXGI_DDI_ERR_NONEXCLUSIVE = unchecked((int)0x887B0003);

        [NativeTypeName("HRESULT")]
        public const int D3D10_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS = unchecked((int)0x88790001);

        [NativeTypeName("HRESULT")]
        public const int D3D10_ERROR_FILE_NOT_FOUND = unchecked((int)0x88790002);

        [NativeTypeName("HRESULT")]
        public const int D3D11_ERROR_TOO_MANY_UNIQUE_STATE_OBJECTS = unchecked((int)0x887C0001);

        [NativeTypeName("HRESULT")]
        public const int D3D11_ERROR_FILE_NOT_FOUND = unchecked((int)0x887C0002);

        [NativeTypeName("HRESULT")]
        public const int D3D11_ERROR_TOO_MANY_UNIQUE_VIEW_OBJECTS = unchecked((int)0x887C0003);

        [NativeTypeName("HRESULT")]
        public const int D3D11_ERROR_DEFERRED_CONTEXT_MAP_WITHOUT_INITIAL_DISCARD = unchecked((int)0x887C0004);

        [NativeTypeName("HRESULT")]
        public const int D3D12_ERROR_ADAPTER_NOT_FOUND = unchecked((int)0x887E0001);

        [NativeTypeName("HRESULT")]
        public const int D3D12_ERROR_DRIVER_VERSION_MISMATCH = unchecked((int)0x887E0002);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_WRONG_STATE = unchecked((int)0x88990001);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_NOT_INITIALIZED = unchecked((int)0x88990002);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_UNSUPPORTED_OPERATION = unchecked((int)0x88990003);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_SCANNER_FAILED = unchecked((int)0x88990004);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_SCREEN_ACCESS_DENIED = unchecked((int)0x88990005);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_DISPLAY_STATE_INVALID = unchecked((int)0x88990006);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_ZERO_VECTOR = unchecked((int)0x88990007);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INTERNAL_ERROR = unchecked((int)0x88990008);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED = unchecked((int)0x88990009);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_CALL = unchecked((int)0x8899000A);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_NO_HARDWARE_DEVICE = unchecked((int)0x8899000B);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_RECREATE_TARGET = unchecked((int)0x8899000C);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_TOO_MANY_SHADER_ELEMENTS = unchecked((int)0x8899000D);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_SHADER_COMPILE_FAILED = unchecked((int)0x8899000E);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_MAX_TEXTURE_SIZE_EXCEEDED = unchecked((int)0x8899000F);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_UNSUPPORTED_VERSION = unchecked((int)0x88990010);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_BAD_NUMBER = unchecked((int)0x88990011);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_WRONG_FACTORY = unchecked((int)0x88990012);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_LAYER_ALREADY_IN_USE = unchecked((int)0x88990013);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_POP_CALL_DID_NOT_MATCH_PUSH = unchecked((int)0x88990014);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_WRONG_RESOURCE_DOMAIN = unchecked((int)0x88990015);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_PUSH_POP_UNBALANCED = unchecked((int)0x88990016);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT = unchecked((int)0x88990017);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INCOMPATIBLE_BRUSH_TYPES = unchecked((int)0x88990018);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_WIN32_ERROR = unchecked((int)0x88990019);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_TARGET_NOT_GDI_COMPATIBLE = unchecked((int)0x8899001A);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_TEXT_EFFECT_IS_WRONG_TYPE = unchecked((int)0x8899001B);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_TEXT_RENDERER_NOT_RELEASED = unchecked((int)0x8899001C);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_EXCEEDS_MAX_BITMAP_SIZE = unchecked((int)0x8899001D);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_GRAPH_CONFIGURATION = unchecked((int)0x8899001E);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION = unchecked((int)0x8899001F);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_CYCLIC_GRAPH = unchecked((int)0x88990020);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_BITMAP_CANNOT_DRAW = unchecked((int)0x88990021);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_OUTSTANDING_BITMAP_REFERENCES = unchecked((int)0x88990022);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_ORIGINAL_TARGET_NOT_BOUND = unchecked((int)0x88990023);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_TARGET = unchecked((int)0x88990024);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_BITMAP_BOUND_AS_TARGET = unchecked((int)0x88990025);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES = unchecked((int)0x88990026);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INTERMEDIATE_TOO_LARGE = unchecked((int)0x88990027);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_EFFECT_IS_NOT_REGISTERED = unchecked((int)0x88990028);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_PROPERTY = unchecked((int)0x88990029);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_NO_SUBPROPERTIES = unchecked((int)0x8899002A);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_PRINT_JOB_CLOSED = unchecked((int)0x8899002B);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_PRINT_FORMAT_NOT_SUPPORTED = unchecked((int)0x8899002C);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_TOO_MANY_TRANSFORM_INPUTS = unchecked((int)0x8899002D);

        [NativeTypeName("HRESULT")]
        public const int D2DERR_INVALID_GLYPH_IMAGE = unchecked((int)0x8899002E);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_FILEFORMAT = unchecked((int)0x88985000);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_UNEXPECTED = unchecked((int)0x88985001);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_NOFONT = unchecked((int)0x88985002);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_FILENOTFOUND = unchecked((int)0x88985003);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_FILEACCESS = unchecked((int)0x88985004);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_FONTCOLLECTIONOBSOLETE = unchecked((int)0x88985005);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_ALREADYREGISTERED = unchecked((int)0x88985006);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_CACHEFORMAT = unchecked((int)0x88985007);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_CACHEVERSION = unchecked((int)0x88985008);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_UNSUPPORTEDOPERATION = unchecked((int)0x88985009);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_TEXTRENDERERINCOMPATIBLE = unchecked((int)0x8898500A);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_FLOWDIRECTIONCONFLICTS = unchecked((int)0x8898500B);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_NOCOLOR = unchecked((int)0x8898500C);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_WRONGSTATE = unchecked((int)0x88982F04);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_VALUEOUTOFRANGE = unchecked((int)0x88982F05);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNKNOWNIMAGEFORMAT = unchecked((int)0x88982F07);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNSUPPORTEDVERSION = unchecked((int)0x88982F0B);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_NOTINITIALIZED = unchecked((int)0x88982F0C);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_ALREADYLOCKED = unchecked((int)0x88982F0D);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_PROPERTYNOTFOUND = unchecked((int)0x88982F40);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_PROPERTYNOTSUPPORTED = unchecked((int)0x88982F41);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_PROPERTYSIZE = unchecked((int)0x88982F42);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_CODECPRESENT = unchecked((int)0x88982F43);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_CODECNOTHUMBNAIL = unchecked((int)0x88982F44);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_PALETTEUNAVAILABLE = unchecked((int)0x88982F45);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_CODECTOOMANYSCANLINES = unchecked((int)0x88982F46);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INTERNALERROR = unchecked((int)0x88982F48);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_SOURCERECTDOESNOTMATCHDIMENSIONS = unchecked((int)0x88982F49);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_COMPONENTNOTFOUND = unchecked((int)0x88982F50);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_IMAGESIZEOUTOFRANGE = unchecked((int)0x88982F51);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_TOOMUCHMETADATA = unchecked((int)0x88982F52);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_BADIMAGE = unchecked((int)0x88982F60);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_BADHEADER = unchecked((int)0x88982F61);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_FRAMEMISSING = unchecked((int)0x88982F62);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_BADMETADATAHEADER = unchecked((int)0x88982F63);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_BADSTREAMDATA = unchecked((int)0x88982F70);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_STREAMWRITE = unchecked((int)0x88982F71);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_STREAMREAD = unchecked((int)0x88982F72);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_STREAMNOTAVAILABLE = unchecked((int)0x88982F73);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT = unchecked((int)0x88982F80);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNSUPPORTEDOPERATION = unchecked((int)0x88982F81);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INVALIDREGISTRATION = unchecked((int)0x88982F8A);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_COMPONENTINITIALIZEFAILURE = unchecked((int)0x88982F8B);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INSUFFICIENTBUFFER = unchecked((int)0x88982F8C);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_DUPLICATEMETADATAPRESENT = unchecked((int)0x88982F8D);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_PROPERTYUNEXPECTEDTYPE = unchecked((int)0x88982F8E);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNEXPECTEDSIZE = unchecked((int)0x88982F8F);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INVALIDQUERYREQUEST = unchecked((int)0x88982F90);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_UNEXPECTEDMETADATATYPE = unchecked((int)0x88982F91);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_REQUESTONLYVALIDATMETADATAROOT = unchecked((int)0x88982F92);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INVALIDQUERYCHARACTER = unchecked((int)0x88982F93);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_WIN32ERROR = unchecked((int)0x88982F94);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INVALIDPROGRESSIVELEVEL = unchecked((int)0x88982F95);

        [NativeTypeName("HRESULT")]
        public const int WINCODEC_ERR_INVALIDJPEGSCANINDEX = unchecked((int)0x88982F96);

        [NativeTypeName("HRESULT")]
        public const int MILERR_OBJECTBUSY = unchecked((int)0x88980001);

        [NativeTypeName("HRESULT")]
        public const int MILERR_INSUFFICIENTBUFFER = unchecked((int)0x88980002);

        [NativeTypeName("HRESULT")]
        public const int MILERR_WIN32ERROR = unchecked((int)0x88980003);

        [NativeTypeName("HRESULT")]
        public const int MILERR_SCANNER_FAILED = unchecked((int)0x88980004);

        [NativeTypeName("HRESULT")]
        public const int MILERR_SCREENACCESSDENIED = unchecked((int)0x88980005);

        [NativeTypeName("HRESULT")]
        public const int MILERR_DISPLAYSTATEINVALID = unchecked((int)0x88980006);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NONINVERTIBLEMATRIX = unchecked((int)0x88980007);

        [NativeTypeName("HRESULT")]
        public const int MILERR_ZEROVECTOR = unchecked((int)0x88980008);

        [NativeTypeName("HRESULT")]
        public const int MILERR_TERMINATED = unchecked((int)0x88980009);

        [NativeTypeName("HRESULT")]
        public const int MILERR_BADNUMBER = unchecked((int)0x8898000A);

        [NativeTypeName("HRESULT")]
        public const int MILERR_INTERNALERROR = unchecked((int)0x88980080);

        [NativeTypeName("HRESULT")]
        public const int MILERR_DISPLAYFORMATNOTSUPPORTED = unchecked((int)0x88980084);

        [NativeTypeName("HRESULT")]
        public const int MILERR_INVALIDCALL = unchecked((int)0x88980085);

        [NativeTypeName("HRESULT")]
        public const int MILERR_ALREADYLOCKED = unchecked((int)0x88980086);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NOTLOCKED = unchecked((int)0x88980087);

        [NativeTypeName("HRESULT")]
        public const int MILERR_DEVICECANNOTRENDERTEXT = unchecked((int)0x88980088);

        [NativeTypeName("HRESULT")]
        public const int MILERR_GLYPHBITMAPMISSED = unchecked((int)0x88980089);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MALFORMEDGLYPHCACHE = unchecked((int)0x8898008A);

        [NativeTypeName("HRESULT")]
        public const int MILERR_GENERIC_IGNORE = unchecked((int)0x8898008B);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MALFORMED_GUIDELINE_DATA = unchecked((int)0x8898008C);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NO_HARDWARE_DEVICE = unchecked((int)0x8898008D);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NEED_RECREATE_AND_PRESENT = unchecked((int)0x8898008E);

        [NativeTypeName("HRESULT")]
        public const int MILERR_ALREADY_INITIALIZED = unchecked((int)0x8898008F);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MISMATCHED_SIZE = unchecked((int)0x88980090);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NO_REDIRECTION_SURFACE_AVAILABLE = unchecked((int)0x88980091);

        [NativeTypeName("HRESULT")]
        public const int MILERR_REMOTING_NOT_SUPPORTED = unchecked((int)0x88980092);

        [NativeTypeName("HRESULT")]
        public const int MILERR_QUEUED_PRESENT_NOT_SUPPORTED = unchecked((int)0x88980093);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NOT_QUEUING_PRESENTS = unchecked((int)0x88980094);

        [NativeTypeName("HRESULT")]
        public const int MILERR_NO_REDIRECTION_SURFACE_RETRY_LATER = unchecked((int)0x88980095);

        [NativeTypeName("HRESULT")]
        public const int MILERR_TOOMANYSHADERELEMNTS = unchecked((int)0x88980096);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MROW_READLOCK_FAILED = unchecked((int)0x88980097);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MROW_UPDATE_FAILED = unchecked((int)0x88980098);

        [NativeTypeName("HRESULT")]
        public const int MILERR_SHADER_COMPILE_FAILED = unchecked((int)0x88980099);

        [NativeTypeName("HRESULT")]
        public const int MILERR_MAX_TEXTURE_SIZE_EXCEEDED = unchecked((int)0x8898009A);

        [NativeTypeName("HRESULT")]
        public const int MILERR_QPC_TIME_WENT_BACKWARD = unchecked((int)0x8898009B);

        [NativeTypeName("HRESULT")]
        public const int MILERR_DXGI_ENUMERATION_OUT_OF_SYNC = unchecked((int)0x8898009D);

        [NativeTypeName("HRESULT")]
        public const int MILERR_ADAPTER_NOT_FOUND = unchecked((int)0x8898009E);

        [NativeTypeName("HRESULT")]
        public const int MILERR_COLORSPACE_NOT_SUPPORTED = unchecked((int)0x8898009F);

        [NativeTypeName("HRESULT")]
        public const int MILERR_PREFILTER_NOT_SUPPORTED = unchecked((int)0x889800A0);

        [NativeTypeName("HRESULT")]
        public const int MILERR_DISPLAYID_ACCESS_DENIED = unchecked((int)0x889800A1);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_INVALIDPACKETHEADER = unchecked((int)0x88980400);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_UNKNOWNPACKET = unchecked((int)0x88980401);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_ILLEGALPACKET = unchecked((int)0x88980402);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_MALFORMEDPACKET = unchecked((int)0x88980403);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_ILLEGALHANDLE = unchecked((int)0x88980404);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_HANDLELOOKUPFAILED = unchecked((int)0x88980405);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_RENDERTHREADFAILURE = unchecked((int)0x88980406);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_CTXSTACKFRSTTARGETNULL = unchecked((int)0x88980407);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_CONNECTIONIDLOOKUPFAILED = unchecked((int)0x88980408);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_BLOCKSFULL = unchecked((int)0x88980409);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_MEMORYFAILURE = unchecked((int)0x8898040A);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_PACKETRECORDOUTOFRANGE = unchecked((int)0x8898040B);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_ILLEGALRECORDTYPE = unchecked((int)0x8898040C);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_OUTOFHANDLES = unchecked((int)0x8898040D);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_UNCHANGABLE_UPDATE_ATTEMPTED = unchecked((int)0x8898040E);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_NO_MULTIPLE_WORKER_THREADS = unchecked((int)0x8898040F);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_REMOTINGNOTSUPPORTED = unchecked((int)0x88980410);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_MISSINGENDCOMMAND = unchecked((int)0x88980411);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_MISSINGBEGINCOMMAND = unchecked((int)0x88980412);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_CHANNELSYNCTIMEDOUT = unchecked((int)0x88980413);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_CHANNELSYNCABANDONED = unchecked((int)0x88980414);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_UNSUPPORTEDTRANSPORTVERSION = unchecked((int)0x88980415);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_TRANSPORTUNAVAILABLE = unchecked((int)0x88980416);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_FEEDBACK_UNSUPPORTED = unchecked((int)0x88980417);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_COMMANDTRANSPORTDENIED = unchecked((int)0x88980418);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_GRAPHICSSTREAMUNAVAILABLE = unchecked((int)0x88980419);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_GRAPHICSSTREAMALREADYOPEN = unchecked((int)0x88980420);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_TRANSPORTDISCONNECTED = unchecked((int)0x88980421);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_TRANSPORTOVERLOADED = unchecked((int)0x88980422);

        [NativeTypeName("HRESULT")]
        public const int UCEERR_PARTITION_ZOMBIED = unchecked((int)0x88980423);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_NOCLOCK = unchecked((int)0x88980500);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_NOMEDIATYPE = unchecked((int)0x88980501);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_NOVIDEOMIXER = unchecked((int)0x88980502);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_NOVIDEOPRESENTER = unchecked((int)0x88980503);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_NOREADYFRAMES = unchecked((int)0x88980504);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_MODULENOTLOADED = unchecked((int)0x88980505);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_WMPFACTORYNOTREGISTERED = unchecked((int)0x88980506);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_INVALIDWMPVERSION = unchecked((int)0x88980507);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_INSUFFICIENTVIDEORESOURCES = unchecked((int)0x88980508);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_VIDEOACCELERATIONNOTAVAILABLE = unchecked((int)0x88980509);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_REQUESTEDTEXTURETOOBIG = unchecked((int)0x8898050A);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_SEEKFAILED = unchecked((int)0x8898050B);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_UNEXPECTEDWMPFAILURE = unchecked((int)0x8898050C);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_MEDIAPLAYERCLOSED = unchecked((int)0x8898050D);

        [NativeTypeName("HRESULT")]
        public const int MILAVERR_UNKNOWNHARDWAREERROR = unchecked((int)0x8898050E);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_UNKNOWNPROPERTY = unchecked((int)0x8898060E);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_EFFECTNOTPARTOFGROUP = unchecked((int)0x8898060F);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_NOINPUTSOURCEATTACHED = unchecked((int)0x88980610);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_CONNECTORNOTCONNECTED = unchecked((int)0x88980611);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_CONNECTORNOTASSOCIATEDWITHEFFECT = unchecked((int)0x88980612);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_RESERVED = unchecked((int)0x88980613);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_CYCLEDETECTED = unchecked((int)0x88980614);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_EFFECTINMORETHANONEGRAPH = unchecked((int)0x88980615);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_EFFECTALREADYINAGRAPH = unchecked((int)0x88980616);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_EFFECTHASNOCHILDREN = unchecked((int)0x88980617);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_ALREADYATTACHEDTOLISTENER = unchecked((int)0x88980618);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_NOTAFFINETRANSFORM = unchecked((int)0x88980619);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_EMPTYBOUNDS = unchecked((int)0x8898061A);

        [NativeTypeName("HRESULT")]
        public const int MILEFFECTSERR_OUTPUTSIZETOOLARGE = unchecked((int)0x8898061B);

        [NativeTypeName("HRESULT")]
        public const int DWMERR_STATE_TRANSITION_FAILED = unchecked((int)0x88980700);

        [NativeTypeName("HRESULT")]
        public const int DWMERR_THEME_FAILED = unchecked((int)0x88980701);

        [NativeTypeName("HRESULT")]
        public const int DWMERR_CATASTROPHIC_FAILURE = unchecked((int)0x88980702);

        [NativeTypeName("HRESULT")]
        public const int DCOMPOSITION_ERROR_WINDOW_ALREADY_COMPOSED = unchecked((int)0x88980800);

        [NativeTypeName("HRESULT")]
        public const int DCOMPOSITION_ERROR_SURFACE_BEING_RENDERED = unchecked((int)0x88980801);

        [NativeTypeName("HRESULT")]
        public const int DCOMPOSITION_ERROR_SURFACE_NOT_BEING_RENDERED = unchecked((int)0x88980802);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_INVALID_AUTHENTICATION_TARGET = unchecked((int)0x80860001);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACCESS_DENIED_BY_TOU = unchecked((int)0x80860002);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_INVALID_APPLICATION = unchecked((int)0x80860003);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_PASSWORD_UPDATE_REQUIRED = unchecked((int)0x80860004);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACCOUNT_UPDATE_REQUIRED = unchecked((int)0x80860005);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_FORCESIGNIN = unchecked((int)0x80860006);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACCOUNT_LOCKED = unchecked((int)0x80860007);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_PARENTAL_CONSENT_REQUIRED = unchecked((int)0x80860008);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_EMAIL_VERIFICATION_REQUIRED = unchecked((int)0x80860009);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACCOUNT_SUSPENDED_COMPROIMISE = unchecked((int)0x8086000A);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACCOUNT_SUSPENDED_ABUSE = unchecked((int)0x8086000B);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_ACTION_REQUIRED = unchecked((int)0x8086000C);

        [NativeTypeName("HRESULT")]
        public const int ONL_CONNECTION_COUNT_LIMIT = unchecked((int)0x8086000D);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_CONNECTED_ACCOUNT_CAN_NOT_SIGNOUT = unchecked((int)0x8086000E);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_USER_AUTHENTICATION_REQUIRED = unchecked((int)0x8086000F);

        [NativeTypeName("HRESULT")]
        public const int ONL_E_REQUEST_THROTTLED = unchecked((int)0x80860010);

        [NativeTypeName("HRESULT")]
        public const int FA_E_MAX_PERSISTED_ITEMS_REACHED = unchecked((int)0x80270220);

        [NativeTypeName("HRESULT")]
        public const int FA_E_HOMEGROUP_NOT_AVAILABLE = unchecked((int)0x80270222);

        [NativeTypeName("HRESULT")]
        public const int E_MONITOR_RESOLUTION_TOO_LOW = unchecked((int)0x80270250);

        [NativeTypeName("HRESULT")]
        public const int E_ELEVATED_ACTIVATION_NOT_SUPPORTED = unchecked((int)0x80270251);

        [NativeTypeName("HRESULT")]
        public const int E_UAC_DISABLED = unchecked((int)0x80270252);

        [NativeTypeName("HRESULT")]
        public const int E_FULL_ADMIN_NOT_SUPPORTED = unchecked((int)0x80270253);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_NOT_REGISTERED = unchecked((int)0x80270254);

        [NativeTypeName("HRESULT")]
        public const int E_MULTIPLE_EXTENSIONS_FOR_APPLICATION = unchecked((int)0x80270255);

        [NativeTypeName("HRESULT")]
        public const int E_MULTIPLE_PACKAGES_FOR_FAMILY = unchecked((int)0x80270256);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_MANAGER_NOT_RUNNING = unchecked((int)0x80270257);

        [NativeTypeName("HRESULT")]
        public const int S_STORE_LAUNCHED_FOR_REMEDIATION = 0x00270258;

        [NativeTypeName("HRESULT")]
        public const int S_APPLICATION_ACTIVATION_ERROR_HANDLED_BY_DIALOG = 0x00270259;

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_ACTIVATION_TIMED_OUT = unchecked((int)0x8027025A);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_ACTIVATION_EXEC_FAILURE = unchecked((int)0x8027025B);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_TEMPORARY_LICENSE_ERROR = unchecked((int)0x8027025C);

        [NativeTypeName("HRESULT")]
        public const int E_APPLICATION_TRIAL_LICENSE_EXPIRED = unchecked((int)0x8027025D);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_ROOT_TARGET_FILE_SYSTEM_NOT_SUPPORTED = unchecked((int)0x80270260);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_ROOT_TARGET_OVERLAP = unchecked((int)0x80270261);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_ROOT_TARGET_CANNOT_INDEX = unchecked((int)0x80270262);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_FILE_NOT_UPLOADED = unchecked((int)0x80270263);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_UPDATE_AVAILABILITY_FAIL = unchecked((int)0x80270264);

        [NativeTypeName("HRESULT")]
        public const int E_SKYDRIVE_ROOT_TARGET_VOLUME_ROOT_NOT_SUPPORTED = unchecked((int)0x80270265);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FILE_SIZE_OVER_LIMIT = unchecked((int)0x8802B001);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FILE_SIZE_EXCEEDS_REMAINING_QUOTA = unchecked((int)0x8802B002);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_UNSUPPORTED_FILE_NAME = unchecked((int)0x8802B003);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FOLDER_ITEM_COUNT_LIMIT_EXCEEDED = unchecked((int)0x8802B004);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FILE_SYNC_PARTNER_ERROR = unchecked((int)0x8802B005);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_SYNC_PAUSED_BY_SERVICE = unchecked((int)0x8802B006);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FILE_IDENTIFIER_UNKNOWN = unchecked((int)0x8802C002);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_SERVICE_AUTHENTICATION_FAILED = unchecked((int)0x8802C003);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_UNKNOWN_SERVICE_ERROR = unchecked((int)0x8802C004);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_SERVICE_RETURNED_UNEXPECTED_SIZE = unchecked((int)0x8802C005);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_REQUEST_BLOCKED_BY_SERVICE = unchecked((int)0x8802C006);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_REQUEST_BLOCKED_DUE_TO_CLIENT_ERROR = unchecked((int)0x8802C007);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FOLDER_INACCESSIBLE = unchecked((int)0x8802D001);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_UNSUPPORTED_FOLDER_NAME = unchecked((int)0x8802D002);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_UNSUPPORTED_MARKET = unchecked((int)0x8802D003);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_PATH_LENGTH_LIMIT_EXCEEDED = unchecked((int)0x8802D004);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_REMOTE_PATH_LENGTH_LIMIT_EXCEEDED = unchecked((int)0x8802D005);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_CLIENT_UPDATE_NEEDED = unchecked((int)0x8802D006);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_PROXY_AUTHENTICATION_REQUIRED = unchecked((int)0x8802D007);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_STORAGE_SERVICE_PROVISIONING_FAILED = unchecked((int)0x8802D008);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_UNSUPPORTED_REPARSE_POINT = unchecked((int)0x8802D009);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_STORAGE_SERVICE_BLOCKED = unchecked((int)0x8802D00A);

        [NativeTypeName("HRESULT")]
        public const int E_SYNCENGINE_FOLDER_IN_REDIRECTION = unchecked((int)0x8802D00B);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_POLICY_NOT_MANAGED_BY_OS = unchecked((int)0x80550001);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_POLICY_COMPLIANT_WITH_ACTIONS = unchecked((int)0x80550002);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_REQUESTED_POLICY_NOT_ENFORCEABLE = unchecked((int)0x80550003);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_CURRENT_USER_HAS_BLANK_PASSWORD = unchecked((int)0x80550004);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_REQUESTED_POLICY_PASSWORD_EXPIRATION_INCOMPATIBLE = unchecked((int)0x80550005);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_USER_CANNOT_CHANGE_PASSWORD = unchecked((int)0x80550006);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_ADMINS_HAVE_BLANK_PASSWORD = unchecked((int)0x80550007);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_ADMINS_CANNOT_CHANGE_PASSWORD = unchecked((int)0x80550008);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_LOCAL_CONTROLLED_USERS_CANNOT_CHANGE_PASSWORD = unchecked((int)0x80550009);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CONNECTED_ADMINS = unchecked((int)0x8055000A);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_CONNECTED_ADMINS_NEED_TO_CHANGE_PASSWORD = unchecked((int)0x8055000B);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_PASSWORD_POLICY_NOT_ENFORCEABLE_FOR_CURRENT_CONNECTED_USER = unchecked((int)0x8055000C);

        [NativeTypeName("HRESULT")]
        public const int EAS_E_CURRENT_CONNECTED_USER_NEED_TO_CHANGE_PASSWORD = unchecked((int)0x8055000D);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_UNSUPPORTED_FORMAT = unchecked((int)0x83750001);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_INVALID_XML = unchecked((int)0x83750002);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_MISSING_REQUIRED_ELEMENT = unchecked((int)0x83750003);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_MISSING_REQUIRED_ATTRIBUTE = unchecked((int)0x83750004);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_UNEXPECTED_CONTENT = unchecked((int)0x83750005);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_RESOURCE_TOO_LARGE = unchecked((int)0x83750006);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_INVALID_JSON_STRING = unchecked((int)0x83750007);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_INVALID_JSON_NUMBER = unchecked((int)0x83750008);

        [NativeTypeName("HRESULT")]
        public const int WEB_E_JSON_VALUE_NOT_FOUND = unchecked((int)0x83750009);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_UNEXPECTED = unchecked((int)0x80190001);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_UNEXPECTED_REDIRECTION = unchecked((int)0x80190003);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_UNEXPECTED_CLIENT_ERROR = unchecked((int)0x80190004);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_UNEXPECTED_SERVER_ERROR = unchecked((int)0x80190005);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_AMBIGUOUS = unchecked((int)0x8019012C);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_MOVED = unchecked((int)0x8019012D);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_REDIRECT = unchecked((int)0x8019012E);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_REDIRECT_METHOD = unchecked((int)0x8019012F);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_NOT_MODIFIED = unchecked((int)0x80190130);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_USE_PROXY = unchecked((int)0x80190131);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_REDIRECT_KEEP_VERB = unchecked((int)0x80190133);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_BAD_REQUEST = unchecked((int)0x80190190);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_DENIED = unchecked((int)0x80190191);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_PAYMENT_REQ = unchecked((int)0x80190192);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_FORBIDDEN = unchecked((int)0x80190193);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_NOT_FOUND = unchecked((int)0x80190194);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_BAD_METHOD = unchecked((int)0x80190195);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_NONE_ACCEPTABLE = unchecked((int)0x80190196);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_PROXY_AUTH_REQ = unchecked((int)0x80190197);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_REQUEST_TIMEOUT = unchecked((int)0x80190198);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_CONFLICT = unchecked((int)0x80190199);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_GONE = unchecked((int)0x8019019A);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_LENGTH_REQUIRED = unchecked((int)0x8019019B);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_PRECOND_FAILED = unchecked((int)0x8019019C);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_REQUEST_TOO_LARGE = unchecked((int)0x8019019D);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_URI_TOO_LONG = unchecked((int)0x8019019E);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_UNSUPPORTED_MEDIA = unchecked((int)0x8019019F);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_RANGE_NOT_SATISFIABLE = unchecked((int)0x801901A0);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_EXPECTATION_FAILED = unchecked((int)0x801901A1);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_SERVER_ERROR = unchecked((int)0x801901F4);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_NOT_SUPPORTED = unchecked((int)0x801901F5);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_BAD_GATEWAY = unchecked((int)0x801901F6);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_SERVICE_UNAVAIL = unchecked((int)0x801901F7);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_GATEWAY_TIMEOUT = unchecked((int)0x801901F8);

        [NativeTypeName("HRESULT")]
        public const int HTTP_E_STATUS_VERSION_NOT_SUP = unchecked((int)0x801901F9);

        [NativeTypeName("HRESULT")]
        public const int E_INVALID_PROTOCOL_OPERATION = unchecked((int)0x83760001);

        [NativeTypeName("HRESULT")]
        public const int E_INVALID_PROTOCOL_FORMAT = unchecked((int)0x83760002);

        [NativeTypeName("HRESULT")]
        public const int E_PROTOCOL_EXTENSIONS_NOT_SUPPORTED = unchecked((int)0x83760003);

        [NativeTypeName("HRESULT")]
        public const int E_SUBPROTOCOL_NOT_SUPPORTED = unchecked((int)0x83760004);

        [NativeTypeName("HRESULT")]
        public const int E_PROTOCOL_VERSION_NOT_SUPPORTED = unchecked((int)0x83760005);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_OUT_OF_ORDER = unchecked((int)0x80400000);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_REENTRANCY = unchecked((int)0x80400001);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_MULTIMODAL = unchecked((int)0x80400002);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_PACKET = unchecked((int)0x80400003);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_FRAME = unchecked((int)0x80400004);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_HISTORY = unchecked((int)0x80400005);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_DEVICE_INFO = unchecked((int)0x80400006);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_TRANSFORM = unchecked((int)0x80400007);

        [NativeTypeName("HRESULT")]
        public const int INPUT_E_DEVICE_PROPERTY = unchecked((int)0x80400008);

        [NativeTypeName("HRESULT")]
        public const int ERROR_DBG_CREATE_PROCESS_FAILURE_LOCKDOWN = unchecked((int)0x80B00001);

        [NativeTypeName("HRESULT")]
        public const int ERROR_DBG_ATTACH_PROCESS_FAILURE_LOCKDOWN = unchecked((int)0x80B00002);

        [NativeTypeName("HRESULT")]
        public const int ERROR_DBG_CONNECT_SERVER_FAILURE_LOCKDOWN = unchecked((int)0x80B00003);

        [NativeTypeName("HRESULT")]
        public const int ERROR_DBG_START_SERVER_FAILURE_LOCKDOWN = unchecked((int)0x80B00004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_IO_PREEMPTED = unchecked((int)0x89010001);

        [NativeTypeName("HRESULT")]
        public const int JSCRIPT_E_CANTEXECUTE = unchecked((int)0x89020001);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_NOT_PROVISIONED_ON_ALL_VOLUMES = unchecked((int)0x88010001);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_FIXED_DATA_NOT_SUPPORTED = unchecked((int)0x88010002);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_HARDWARE_NOT_COMPLIANT = unchecked((int)0x88010003);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_LOCK_NOT_CONFIGURED = unchecked((int)0x88010004);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_PROTECTION_SUSPENDED = unchecked((int)0x88010005);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_NO_LICENSE = unchecked((int)0x88010006);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_OS_NOT_PROTECTED = unchecked((int)0x88010007);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_UNEXPECTED_FAIL = unchecked((int)0x88010008);

        [NativeTypeName("HRESULT")]
        public const int WEP_E_BUFFER_TOO_LARGE = unchecked((int)0x88010009);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_ERROR_STORED = unchecked((int)0xC05C0000);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_ERROR_NOT_AVAILABLE = unchecked((int)0xC05CFF00);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_AVAILABLE = unchecked((int)0xC05CFF01);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_CAPACITY_DATA_CHANGED = unchecked((int)0xC05CFF02);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_PREEMPTED = unchecked((int)0xC05CFF03);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_RESERVATIONS_RELEASED = unchecked((int)0xC05CFF04);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_REGISTRATIONS_PREEMPTED = unchecked((int)0xC05CFF05);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_UNIT_ATTENTION_OPERATING_DEFINITION_CHANGED = unchecked((int)0xC05CFF06);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_RESERVATION_CONFLICT = unchecked((int)0xC05CFF07);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_WRONG_FILE_TYPE = unchecked((int)0xC05CFF08);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_VERSION_MISMATCH = unchecked((int)0xC05CFF09);

        [NativeTypeName("HRESULT")]
        public const int ERROR_VHD_SHARED = unchecked((int)0xC05CFF0A);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SVHDX_NO_INITIATOR = unchecked((int)0xC05CFF0B);

        [NativeTypeName("HRESULT")]
        public const int ERROR_VHDSET_BACKING_STORAGE_NOT_FOUND = unchecked((int)0xC05CFF0C);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SMB_NO_PREAUTH_INTEGRITY_HASH_OVERLAP = unchecked((int)0xC05D0000);

        [NativeTypeName("HRESULT")]
        public const int ERROR_SMB_BAD_CLUSTER_DIALECT = unchecked((int)0xC05D0001);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_OUT_OF_HANDLES = unchecked((int)0x80072EE1);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_TIMEOUT = unchecked((int)0x80072EE2);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_EXTENDED_ERROR = unchecked((int)0x80072EE3);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INTERNAL_ERROR = unchecked((int)0x80072EE4);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_URL = unchecked((int)0x80072EE5);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_UNRECOGNIZED_SCHEME = unchecked((int)0x80072EE6);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NAME_NOT_RESOLVED = unchecked((int)0x80072EE7);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_PROTOCOL_NOT_FOUND = unchecked((int)0x80072EE8);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_OPTION = unchecked((int)0x80072EE9);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_BAD_OPTION_LENGTH = unchecked((int)0x80072EEA);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_OPTION_NOT_SETTABLE = unchecked((int)0x80072EEB);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SHUTDOWN = unchecked((int)0x80072EEC);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INCORRECT_USER_NAME = unchecked((int)0x80072EED);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INCORRECT_PASSWORD = unchecked((int)0x80072EEE);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_LOGIN_FAILURE = unchecked((int)0x80072EEF);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_OPERATION = unchecked((int)0x80072EF0);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_OPERATION_CANCELLED = unchecked((int)0x80072EF1);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INCORRECT_HANDLE_TYPE = unchecked((int)0x80072EF2);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INCORRECT_HANDLE_STATE = unchecked((int)0x80072EF3);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NOT_PROXY_REQUEST = unchecked((int)0x80072EF4);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_REGISTRY_VALUE_NOT_FOUND = unchecked((int)0x80072EF5);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_BAD_REGISTRY_PARAMETER = unchecked((int)0x80072EF6);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NO_DIRECT_ACCESS = unchecked((int)0x80072EF7);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NO_CONTEXT = unchecked((int)0x80072EF8);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NO_CALLBACK = unchecked((int)0x80072EF9);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_REQUEST_PENDING = unchecked((int)0x80072EFA);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INCORRECT_FORMAT = unchecked((int)0x80072EFB);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_ITEM_NOT_FOUND = unchecked((int)0x80072EFC);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CANNOT_CONNECT = unchecked((int)0x80072EFD);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CONNECTION_ABORTED = unchecked((int)0x80072EFE);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CONNECTION_RESET = unchecked((int)0x80072EFF);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_FORCE_RETRY = unchecked((int)0x80072F00);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_PROXY_REQUEST = unchecked((int)0x80072F01);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NEED_UI = unchecked((int)0x80072F02);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HANDLE_EXISTS = unchecked((int)0x80072F04);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_CERT_DATE_INVALID = unchecked((int)0x80072F05);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_CERT_CN_INVALID = unchecked((int)0x80072F06);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HTTP_TO_HTTPS_ON_REDIR = unchecked((int)0x80072F07);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HTTPS_TO_HTTP_ON_REDIR = unchecked((int)0x80072F08);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_MIXED_SECURITY = unchecked((int)0x80072F09);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CHG_POST_IS_NON_SECURE = unchecked((int)0x80072F0A);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_POST_IS_NON_SECURE = unchecked((int)0x80072F0B);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CLIENT_AUTH_CERT_NEEDED = unchecked((int)0x80072F0C);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_CA = unchecked((int)0x80072F0D);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_CLIENT_AUTH_NOT_SETUP = unchecked((int)0x80072F0E);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_ASYNC_THREAD_FAILED = unchecked((int)0x80072F0F);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_REDIRECT_SCHEME_CHANGE = unchecked((int)0x80072F10);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_DIALOG_PENDING = unchecked((int)0x80072F11);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_RETRY_DIALOG = unchecked((int)0x80072F12);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NO_NEW_CONTAINERS = unchecked((int)0x80072F13);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HTTPS_HTTP_SUBMIT_REDIR = unchecked((int)0x80072F14);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_CERT_ERRORS = unchecked((int)0x80072F17);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_CERT_REV_FAILED = unchecked((int)0x80072F19);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HEADER_NOT_FOUND = unchecked((int)0x80072F76);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_DOWNLEVEL_SERVER = unchecked((int)0x80072F77);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_SERVER_RESPONSE = unchecked((int)0x80072F78);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_HEADER = unchecked((int)0x80072F79);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_INVALID_QUERY_REQUEST = unchecked((int)0x80072F7A);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_HEADER_ALREADY_EXISTS = unchecked((int)0x80072F7B);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_REDIRECT_FAILED = unchecked((int)0x80072F7C);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SECURITY_CHANNEL_ERROR = unchecked((int)0x80072F7D);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_UNABLE_TO_CACHE_FILE = unchecked((int)0x80072F7E);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_TCPIP_NOT_INSTALLED = unchecked((int)0x80072F7F);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_DISCONNECTED = unchecked((int)0x80072F83);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SERVER_UNREACHABLE = unchecked((int)0x80072F84);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_PROXY_SERVER_UNREACHABLE = unchecked((int)0x80072F85);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_BAD_AUTO_PROXY_SCRIPT = unchecked((int)0x80072F86);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_UNABLE_TO_DOWNLOAD_SCRIPT = unchecked((int)0x80072F87);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_INVALID_CERT = unchecked((int)0x80072F89);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_SEC_CERT_REVOKED = unchecked((int)0x80072F8A);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_FAILED_DUETOSECURITYCHECK = unchecked((int)0x80072F8B);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NOT_INITIALIZED = unchecked((int)0x80072F8C);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = unchecked((int)0x80072F8E);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_DECODING_FAILED = unchecked((int)0x80072F8F);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_NOT_REDIRECTED = unchecked((int)0x80072F80);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_COOKIE_NEEDS_CONFIRMATION = unchecked((int)0x80072F81);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_COOKIE_DECLINED = unchecked((int)0x80072F82);

        [NativeTypeName("HRESULT")]
        public const int WININET_E_REDIRECT_NEEDS_CONFIRMATION = unchecked((int)0x80072F88);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_ERROR = unchecked((int)0x87AF0001);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_INTERNAL = unchecked((int)0x87AF0002);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_PERM = unchecked((int)0x87AF0003);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_ABORT = unchecked((int)0x87AF0004);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_BUSY = unchecked((int)0x87AF0005);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_LOCKED = unchecked((int)0x87AF0006);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOMEM = unchecked((int)0x87AF0007);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_READONLY = unchecked((int)0x87AF0008);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_INTERRUPT = unchecked((int)0x87AF0009);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR = unchecked((int)0x87AF000A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CORRUPT = unchecked((int)0x87AF000B);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOTFOUND = unchecked((int)0x87AF000C);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_FULL = unchecked((int)0x87AF000D);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CANTOPEN = unchecked((int)0x87AF000E);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_PROTOCOL = unchecked((int)0x87AF000F);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_EMPTY = unchecked((int)0x87AF0010);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_SCHEMA = unchecked((int)0x87AF0011);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_TOOBIG = unchecked((int)0x87AF0012);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT = unchecked((int)0x87AF0013);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_MISMATCH = unchecked((int)0x87AF0014);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_MISUSE = unchecked((int)0x87AF0015);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOLFS = unchecked((int)0x87AF0016);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_AUTH = unchecked((int)0x87AF0017);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_FORMAT = unchecked((int)0x87AF0018);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_RANGE = unchecked((int)0x87AF0019);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOTADB = unchecked((int)0x87AF001A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOTICE = unchecked((int)0x87AF001B);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_WARNING = unchecked((int)0x87AF001C);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_ROW = unchecked((int)0x87AF0064);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_DONE = unchecked((int)0x87AF0065);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_READ = unchecked((int)0x87AF010A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SHORT_READ = unchecked((int)0x87AF020A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_WRITE = unchecked((int)0x87AF030A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_FSYNC = unchecked((int)0x87AF040A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_DIR_FSYNC = unchecked((int)0x87AF050A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_TRUNCATE = unchecked((int)0x87AF060A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_FSTAT = unchecked((int)0x87AF070A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_UNLOCK = unchecked((int)0x87AF080A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_RDLOCK = unchecked((int)0x87AF090A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_DELETE = unchecked((int)0x87AF0A0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_BLOCKED = unchecked((int)0x87AF0B0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_NOMEM = unchecked((int)0x87AF0C0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_ACCESS = unchecked((int)0x87AF0D0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_CHECKRESERVEDLOCK = unchecked((int)0x87AF0E0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_LOCK = unchecked((int)0x87AF0F0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_CLOSE = unchecked((int)0x87AF100A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_DIR_CLOSE = unchecked((int)0x87AF110A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SHMOPEN = unchecked((int)0x87AF120A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SHMSIZE = unchecked((int)0x87AF130A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SHMLOCK = unchecked((int)0x87AF140A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SHMMAP = unchecked((int)0x87AF150A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_SEEK = unchecked((int)0x87AF160A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_DELETE_NOENT = unchecked((int)0x87AF170A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_MMAP = unchecked((int)0x87AF180A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_GETTEMPPATH = unchecked((int)0x87AF190A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_CONVPATH = unchecked((int)0x87AF1A0A);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_VNODE = unchecked((int)0x87AF1A02);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_IOERR_AUTH = unchecked((int)0x87AF1A03);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_LOCKED_SHAREDCACHE = unchecked((int)0x87AF0106);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_BUSY_RECOVERY = unchecked((int)0x87AF0105);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_BUSY_SNAPSHOT = unchecked((int)0x87AF0205);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CANTOPEN_NOTEMPDIR = unchecked((int)0x87AF010E);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CANTOPEN_ISDIR = unchecked((int)0x87AF020E);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CANTOPEN_FULLPATH = unchecked((int)0x87AF030E);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CANTOPEN_CONVPATH = unchecked((int)0x87AF040E);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CORRUPT_VTAB = unchecked((int)0x87AF010B);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_READONLY_RECOVERY = unchecked((int)0x87AF0108);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_READONLY_CANTLOCK = unchecked((int)0x87AF0208);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_READONLY_ROLLBACK = unchecked((int)0x87AF0308);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_READONLY_DBMOVED = unchecked((int)0x87AF0408);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_ABORT_ROLLBACK = unchecked((int)0x87AF0204);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_CHECK = unchecked((int)0x87AF0113);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_COMMITHOOK = unchecked((int)0x87AF0213);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_FOREIGNKEY = unchecked((int)0x87AF0313);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_FUNCTION = unchecked((int)0x87AF0413);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_NOTNULL = unchecked((int)0x87AF0513);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_PRIMARYKEY = unchecked((int)0x87AF0613);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_TRIGGER = unchecked((int)0x87AF0713);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_UNIQUE = unchecked((int)0x87AF0813);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_VTAB = unchecked((int)0x87AF0913);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_CONSTRAINT_ROWID = unchecked((int)0x87AF0A13);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOTICE_RECOVER_WAL = unchecked((int)0x87AF011B);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_NOTICE_RECOVER_ROLLBACK = unchecked((int)0x87AF021B);

        [NativeTypeName("HRESULT")]
        public const int SQLITE_E_WARNING_AUTOINDEX = unchecked((int)0x87AF011C);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TOGGLE_TRACE_STARTED = unchecked((int)0x87C51001);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ALTERNATIVE_TRACE_CANNOT_PREEMPT = unchecked((int)0x87C51002);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_AOT_NOT_RUNNING = unchecked((int)0x87C51003);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCRIPT_TYPE_INVALID = unchecked((int)0x87C51004);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCENARIODEF_NOT_FOUND = unchecked((int)0x87C51005);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRACEPROFILE_NOT_FOUND = unchecked((int)0x87C51006);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FORWARDER_ALREADY_ENABLED = unchecked((int)0x87C51007);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FORWARDER_ALREADY_DISABLED = unchecked((int)0x87C51008);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_EVENTLOG_ENTRY_MALFORMED = unchecked((int)0x87C51009);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_DIAGRULES_SCHEMAVERSION_MISMATCH = unchecked((int)0x87C5100A);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCRIPT_TERMINATED = unchecked((int)0x87C5100B);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_INVALID_CUSTOM_FILTER = unchecked((int)0x87C5100C);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRACE_NOT_RUNNING = unchecked((int)0x87C5100D);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_REESCALATED_TOO_QUICKLY = unchecked((int)0x87C5100E);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ESCALATION_ALREADY_RUNNING = unchecked((int)0x87C5100F);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_PERFTRACK_ALREADY_TRACING = unchecked((int)0x87C51010);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_REACHED_MAX_ESCALATIONS = unchecked((int)0x87C51011);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FORWARDER_PRODUCER_MISMATCH = unchecked((int)0x87C51012);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_INTENTIONAL_SCRIPT_FAILURE = unchecked((int)0x87C51013);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SQM_INIT_FAILED = unchecked((int)0x87C51014);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_NO_WER_LOGGER_SUPPORTED = unchecked((int)0x87C51015);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRACERS_DONT_EXIST = unchecked((int)0x87C51016);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_WINRT_INIT_FAILED = unchecked((int)0x87C51017);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCENARIODEF_SCHEMAVERSION_MISMATCH = unchecked((int)0x87C51018);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_INVALID_FILTER = unchecked((int)0x87C51019);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_EXE_TERMINATED = unchecked((int)0x87C5101A);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ESCALATION_NOT_AUTHORIZED = unchecked((int)0x87C5101B);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SETUP_NOT_AUTHORIZED = unchecked((int)0x87C5101C);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_CHILD_PROCESS_FAILED = unchecked((int)0x87C5101D);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_COMMAND_LINE_NOT_AUTHORIZED = unchecked((int)0x87C5101E);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_CANNOT_LOAD_SCENARIO_EDITOR_XML = unchecked((int)0x87C5101F);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ESCALATION_TIMED_OUT = unchecked((int)0x87C51020);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SETUP_TIMED_OUT = unchecked((int)0x87C51021);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRIGGER_MISMATCH = unchecked((int)0x87C51022);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRIGGER_NOT_FOUND = unchecked((int)0x87C51023);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SIF_NOT_SUPPORTED = unchecked((int)0x87C51024);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_DELAY_TERMINATED = unchecked((int)0x87C51025);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_DEVICE_TICKET_ERROR = unchecked((int)0x87C51026);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRACE_BUFFER_LIMIT_EXCEEDED = unchecked((int)0x87C51027);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_API_RESULT_UNAVAILABLE = unchecked((int)0x87C51028);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_RPC_TIMEOUT = unchecked((int)0x87C51029);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_RPC_WAIT_FAILED = unchecked((int)0x87C5102A);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_API_BUSY = unchecked((int)0x87C5102B);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRACE_MIN_DURATION_REQUIREMENT_NOT_MET = unchecked((int)0x87C5102C);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_EXCLUSIVITY_NOT_AVAILABLE = unchecked((int)0x87C5102D);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_GETFILE_FILE_PATH_NOT_APPROVED = unchecked((int)0x87C5102E);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ESCALATION_DIRECTORY_ALREADY_EXISTS = unchecked((int)0x87C5102F);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TIME_TRIGGER_ON_START_INVALID = unchecked((int)0x87C51030);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TIME_TRIGGER_ONLY_VALID_ON_SINGLE_TRANSITION = unchecked((int)0x87C51031);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TIME_TRIGGER_INVALID_TIME_RANGE = unchecked((int)0x87C51032);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_MULTIPLE_TIME_TRIGGER_ON_SINGLE_STATE = unchecked((int)0x87C51033);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_BINARY_MISSING = unchecked((int)0x87C51034);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FAILED_TO_RESOLVE_CONTAINER_ID = unchecked((int)0x87C51036);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_UNABLE_TO_RESOLVE_SESSION = unchecked((int)0x87C51037);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_THROTTLED = unchecked((int)0x87C51038);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_UNAPPROVED_SCRIPT = unchecked((int)0x87C51039);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCRIPT_MISSING = unchecked((int)0x87C5103A);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCENARIO_THROTTLED = unchecked((int)0x87C5103B);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_API_NOT_SUPPORTED = unchecked((int)0x87C5103C);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_GETFILE_EXTERNAL_PATH_NOT_APPROVED = unchecked((int)0x87C5103D);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TRY_GET_SCENARIO_TIMEOUT_EXCEEDED = unchecked((int)0x87C5103E);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_CERT_REV_FAILED = unchecked((int)0x87C5103F);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FAILED_TO_START_NDISCAP = unchecked((int)0x87C51040);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_KERNELDUMP_LIMIT_REACHED = unchecked((int)0x87C51041);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_MISSING_AGGREGATE_EVENT_TAG = unchecked((int)0x87C51042);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_INVALID_AGGREGATION_STRUCT = unchecked((int)0x87C51043);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ACTION_NOT_SUPPORTED_IN_DESTINATION = unchecked((int)0x87C51044);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_MISSING_ATTRIBUTE = unchecked((int)0x87C51045);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_INVALID_TYPE = unchecked((int)0x87C51046);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_VARIABLE_NOT_FOUND = unchecked((int)0x87C51047);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_FUNCTION_RESTRICTED = unchecked((int)0x87C51048);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_VERSION_MISMATCH = unchecked((int)0x87C51049);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_INVALID_FUNCTION = unchecked((int)0x87C51050);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_INVALID_FUNCTION_PARAMS = unchecked((int)0x87C51051);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_INVALID_COMMAND = unchecked((int)0x87C51052);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FILTER_ILLEGAL_EVAL = unchecked((int)0x87C51053);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TTTRACER_RETURNED_ERROR = unchecked((int)0x87C51054);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_AGENT_DIAGNOSTICS_TOO_LARGE = unchecked((int)0x87C51055);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_FAILED_TO_RECEIVE_AGENT_DIAGNOSTICS = unchecked((int)0x87C51056);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SCENARIO_HAS_NO_ACTIONS = unchecked((int)0x87C51057);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_TTTRACER_STORAGE_FULL = unchecked((int)0x87C51058);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_INSUFFICIENT_SPACE_TO_START_TRACE = unchecked((int)0x87C51059);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_ESCALATION_CANCELLED_AT_SHUTDOWN = unchecked((int)0x87C5105A);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_GETFILEINFOACTION_FILE_NOT_APPROVED = unchecked((int)0x87C5105B);

        [NativeTypeName("HRESULT")]
        public const int UTC_E_SETREGKEYACTION_TYPE_NOT_APPROVED = unchecked((int)0x87C5105C);

        [NativeTypeName("HRESULT")]
        public const int WINML_ERR_INVALID_DEVICE = unchecked((int)0x88900001);

        [NativeTypeName("HRESULT")]
        public const int WINML_ERR_INVALID_BINDING = unchecked((int)0x88900002);

        [NativeTypeName("HRESULT")]
        public const int WINML_ERR_VALUE_NOTFOUND = unchecked((int)0x88900003);

        [NativeTypeName("HRESULT")]
        public const int WINML_ERR_SIZE_MISMATCH = unchecked((int)0x88900004);

        [NativeTypeName("HRESULT")]
        public const int ERROR_QUIC_HANDSHAKE_FAILURE = unchecked((int)0x80410000);

        [NativeTypeName("HRESULT")]
        public const int ERROR_QUIC_VER_NEG_FAILURE = unchecked((int)0x80410001);

    }
}
