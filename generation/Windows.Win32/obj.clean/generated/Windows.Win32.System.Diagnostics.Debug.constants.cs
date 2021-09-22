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


namespace Windows.Win32.System.Diagnostics.Debug
{
    public static partial class Apis
    {
        public const uint WOW64_CONTEXT_i386 = 0x00010000;

        public const uint WOW64_CONTEXT_i486 = 0x00010000;

        public const uint WOW64_CONTEXT_EXCEPTION_ACTIVE = 0x08000000;

        public const uint WOW64_CONTEXT_SERVICE_ACTIVE = 0x10000000;

        public const uint WOW64_CONTEXT_EXCEPTION_REQUEST = 0x40000000;

        public const uint WOW64_CONTEXT_EXCEPTION_REPORTING = 0x80000000;

        public const uint WOW64_SIZE_OF_80387_REGISTERS = 80;

        public const uint WOW64_MAXIMUM_SUPPORTED_EXTENSION = 512;

        public const uint ERROR_DBG_CANCELLED = 0xC00004C7;

        public const uint ERROR_DBG_TIMEOUT = 0xC00005B4;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_NO_DOT_COMMANDS = 0x00000001;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_NO_EXTENSION_COMMANDS = 0x00000002;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_NO_SYMBOLS = 0x00000004;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_IS_DOT_COMMAND = 0x00000001;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_IS_EXTENSION_COMMAND = 0x00000002;

        public const uint DEBUG_GET_TEXT_COMPLETIONS_IS_SYMBOL = 0x00000004;

        public const uint DEBUG_REQUEST_SOURCE_PATH_HAS_SOURCE_SERVER = 0;

        public const uint DEBUG_REQUEST_TARGET_EXCEPTION_CONTEXT = 1;

        public const uint DEBUG_REQUEST_TARGET_EXCEPTION_THREAD = 2;

        public const uint DEBUG_REQUEST_TARGET_EXCEPTION_RECORD = 3;

        public const uint DEBUG_REQUEST_GET_ADDITIONAL_CREATE_OPTIONS = 4;

        public const uint DEBUG_REQUEST_SET_ADDITIONAL_CREATE_OPTIONS = 5;

        public const uint DEBUG_REQUEST_GET_WIN32_MAJOR_MINOR_VERSIONS = 6;

        public const uint DEBUG_REQUEST_READ_USER_MINIDUMP_STREAM = 7;

        public const uint DEBUG_REQUEST_TARGET_CAN_DETACH = 8;

        public const uint DEBUG_REQUEST_SET_LOCAL_IMPLICIT_COMMAND_LINE = 9;

        public const uint DEBUG_REQUEST_GET_CAPTURED_EVENT_CODE_OFFSET = 10;

        public const uint DEBUG_REQUEST_READ_CAPTURED_EVENT_CODE_STREAM = 11;

        public const uint DEBUG_REQUEST_EXT_TYPED_DATA_ANSI = 12;

        public const uint DEBUG_REQUEST_GET_EXTENSION_SEARCH_PATH_WIDE = 13;

        public const uint DEBUG_REQUEST_GET_TEXT_COMPLETIONS_WIDE = 14;

        public const uint DEBUG_REQUEST_GET_CACHED_SYMBOL_INFO = 15;

        public const uint DEBUG_REQUEST_ADD_CACHED_SYMBOL_INFO = 16;

        public const uint DEBUG_REQUEST_REMOVE_CACHED_SYMBOL_INFO = 17;

        public const uint DEBUG_REQUEST_GET_TEXT_COMPLETIONS_ANSI = 18;

        public const uint DEBUG_REQUEST_CURRENT_OUTPUT_CALLBACKS_ARE_DML_AWARE = 19;

        public const uint DEBUG_REQUEST_GET_OFFSET_UNWIND_INFORMATION = 20;

        public const uint DEBUG_REQUEST_GET_DUMP_HEADER = 21;

        public const uint DEBUG_REQUEST_SET_DUMP_HEADER = 22;

        public const uint DEBUG_REQUEST_MIDORI = 23;

        public const uint DEBUG_REQUEST_PROCESS_DESCRIPTORS = 24;

        public const uint DEBUG_REQUEST_MISC_INFORMATION = 25;

        public const uint DEBUG_REQUEST_OPEN_PROCESS_TOKEN = 26;

        public const uint DEBUG_REQUEST_OPEN_THREAD_TOKEN = 27;

        public const uint DEBUG_REQUEST_DUPLICATE_TOKEN = 28;

        public const uint DEBUG_REQUEST_QUERY_INFO_TOKEN = 29;

        public const uint DEBUG_REQUEST_CLOSE_TOKEN = 30;

        public const uint DEBUG_REQUEST_WOW_PROCESS = 31;

        public const uint DEBUG_REQUEST_WOW_MODULE = 32;

        public const uint DEBUG_LIVE_USER_NON_INVASIVE = 33;

        public const uint DEBUG_REQUEST_RESUME_THREAD = 34;

        public const uint DEBUG_REQUEST_INLINE_QUERY = 35;

        public const uint DEBUG_REQUEST_TL_INSTRUMENTATION_AWARE = 36;

        public const uint DEBUG_REQUEST_GET_INSTRUMENTATION_VERSION = 37;

        public const uint DEBUG_REQUEST_GET_MODULE_ARCHITECTURE = 38;

        public const uint DEBUG_SRCFILE_SYMBOL_TOKEN = 0;

        public const uint DEBUG_SRCFILE_SYMBOL_TOKEN_SOURCE_COMMAND_WIDE = 1;

        public const uint DEBUG_SRCFILE_SYMBOL_CHECKSUMINFO = 2;

        public const uint DEBUG_SYMINFO_BREAKPOINT_SOURCE_LINE = 0;

        public const uint DEBUG_SYMINFO_IMAGEHLP_MODULEW64 = 1;

        public const uint DEBUG_SYMINFO_GET_SYMBOL_NAME_BY_OFFSET_AND_TAG_WIDE = 2;

        public const uint DEBUG_SYMINFO_GET_MODULE_SYMBOL_NAMES_AND_OFFSETS = 3;

        public const uint DEBUG_SYSOBJINFO_THREAD_BASIC_INFORMATION = 0;

        public const uint DEBUG_SYSOBJINFO_THREAD_NAME_WIDE = 1;

        public const uint DEBUG_SYSOBJINFO_CURRENT_PROCESS_COOKIE = 2;

        public const uint DEBUG_TBINFO_EXIT_STATUS = 0x00000001;

        public const uint DEBUG_TBINFO_PRIORITY_CLASS = 0x00000002;

        public const uint DEBUG_TBINFO_PRIORITY = 0x00000004;

        public const uint DEBUG_TBINFO_TIMES = 0x00000008;

        public const uint DEBUG_TBINFO_START_OFFSET = 0x00000010;

        public const uint DEBUG_TBINFO_AFFINITY = 0x00000020;

        public const uint DEBUG_TBINFO_ALL = 0x0000003f;

        public const uint DEBUG_BREAKPOINT_CODE = 0;

        public const uint DEBUG_BREAKPOINT_DATA = 1;

        public const uint DEBUG_BREAKPOINT_TIME = 2;

        public const uint DEBUG_BREAKPOINT_INLINE = 3;

        public const uint DEBUG_BREAKPOINT_GO_ONLY = 0x00000001;

        public const uint DEBUG_BREAKPOINT_DEFERRED = 0x00000002;

        public const uint DEBUG_BREAKPOINT_ENABLED = 0x00000004;

        public const uint DEBUG_BREAKPOINT_ADDER_ONLY = 0x00000008;

        public const uint DEBUG_BREAKPOINT_ONE_SHOT = 0x00000010;

        public const uint DEBUG_BREAK_READ = 0x00000001;

        public const uint DEBUG_BREAK_WRITE = 0x00000002;

        public const uint DEBUG_BREAK_EXECUTE = 0x00000004;

        public const uint DEBUG_BREAK_IO = 0x00000008;

        public const uint DEBUG_ATTACH_KERNEL_CONNECTION = 0x00000000;

        public const uint DEBUG_ATTACH_LOCAL_KERNEL = 0x00000001;

        public const uint DEBUG_ATTACH_EXDI_DRIVER = 0x00000002;

        public const uint DEBUG_ATTACH_INSTALL_DRIVER = 0x00000004;

        public const uint DEBUG_GET_PROC_DEFAULT = 0x00000000;

        public const uint DEBUG_GET_PROC_FULL_MATCH = 0x00000001;

        public const uint DEBUG_GET_PROC_ONLY_MATCH = 0x00000002;

        public const uint DEBUG_GET_PROC_SERVICE_NAME = 0x00000004;

        public const uint DEBUG_PROC_DESC_DEFAULT = 0x00000000;

        public const uint DEBUG_PROC_DESC_NO_PATHS = 0x00000001;

        public const uint DEBUG_PROC_DESC_NO_SERVICES = 0x00000002;

        public const uint DEBUG_PROC_DESC_NO_MTS_PACKAGES = 0x00000004;

        public const uint DEBUG_PROC_DESC_NO_COMMAND_LINE = 0x00000008;

        public const uint DEBUG_PROC_DESC_NO_SESSION_ID = 0x00000010;

        public const uint DEBUG_PROC_DESC_NO_USER_NAME = 0x00000020;

        public const uint DEBUG_ATTACH_DEFAULT = 0x00000000;

        public const uint DEBUG_ATTACH_NONINVASIVE = 0x00000001;

        public const uint DEBUG_ATTACH_EXISTING = 0x00000002;

        public const uint DEBUG_ATTACH_NONINVASIVE_NO_SUSPEND = 0x00000004;

        public const uint DEBUG_ATTACH_INVASIVE_NO_INITIAL_BREAK = 0x00000008;

        public const uint DEBUG_ATTACH_INVASIVE_RESUME_PROCESS = 0x00000010;

        public const uint DEBUG_ATTACH_NONINVASIVE_ALLOW_PARTIAL = 0x00000020;

        public const uint DEBUG_ECREATE_PROCESS_DEFAULT = 0x00000000;

        public const uint DEBUG_ECREATE_PROCESS_INHERIT_HANDLES = 0x00000001;

        public const uint DEBUG_ECREATE_PROCESS_USE_VERIFIER_FLAGS = 0x00000002;

        public const uint DEBUG_ECREATE_PROCESS_USE_IMPLICIT_COMMAND_LINE = 0x00000004;

        public const uint DEBUG_PROCESS_DETACH_ON_EXIT = 0x00000001;

        public const uint DEBUG_PROCESS_ONLY_THIS_PROCESS = 0x00000002;

        public const uint DEBUG_CONNECT_SESSION_DEFAULT = 0x00000000;

        public const uint DEBUG_CONNECT_SESSION_NO_VERSION = 0x00000001;

        public const uint DEBUG_CONNECT_SESSION_NO_ANNOUNCE = 0x00000002;

        public const uint DEBUG_SERVERS_DEBUGGER = 0x00000001;

        public const uint DEBUG_SERVERS_PROCESS = 0x00000002;

        public const uint DEBUG_SERVERS_ALL = 0x00000003;

        public const uint DEBUG_END_PASSIVE = 0x00000000;

        public const uint DEBUG_END_ACTIVE_TERMINATE = 0x00000001;

        public const uint DEBUG_END_ACTIVE_DETACH = 0x00000002;

        public const uint DEBUG_END_REENTRANT = 0x00000003;

        public const uint DEBUG_END_DISCONNECT = 0x00000004;

        public const uint DEBUG_OUTPUT_NORMAL = 0x00000001;

        public const uint DEBUG_OUTPUT_ERROR = 0x00000002;

        public const uint DEBUG_OUTPUT_WARNING = 0x00000004;

        public const uint DEBUG_OUTPUT_VERBOSE = 0x00000008;

        public const uint DEBUG_OUTPUT_PROMPT = 0x00000010;

        public const uint DEBUG_OUTPUT_PROMPT_REGISTERS = 0x00000020;

        public const uint DEBUG_OUTPUT_EXTENSION_WARNING = 0x00000040;

        public const uint DEBUG_OUTPUT_DEBUGGEE = 0x00000080;

        public const uint DEBUG_OUTPUT_DEBUGGEE_PROMPT = 0x00000100;

        public const uint DEBUG_OUTPUT_SYMBOLS = 0x00000200;

        public const uint DEBUG_OUTPUT_STATUS = 0x00000400;

        public const uint DEBUG_OUTPUT_XML = 0x00000800;

        public const uint DEBUG_IOUTPUT_KD_PROTOCOL = 0x80000000;

        public const uint DEBUG_IOUTPUT_REMOTING = 0x40000000;

        public const uint DEBUG_IOUTPUT_BREAKPOINT = 0x20000000;

        public const uint DEBUG_IOUTPUT_EVENT = 0x10000000;

        public const uint DEBUG_IOUTPUT_ADDR_TRANSLATE = 0x08000000;

        public const uint DEBUG_OUTPUT_IDENTITY_DEFAULT = 0x00000000;

        public const uint DEBUG_CLIENT_UNKNOWN = 0x0;

        public const uint DEBUG_CLIENT_VSINT = 0x1;

        public const uint DEBUG_CLIENT_NTSD = 0x2;

        public const uint DEBUG_CLIENT_NTKD = 0x3;

        public const uint DEBUG_CLIENT_CDB = 0x4;

        public const uint DEBUG_CLIENT_KD = 0x5;

        public const uint DEBUG_CLIENT_WINDBG = 0x6;

        public const uint DEBUG_CLIENT_WINIDE = 0x7;

        public const uint DEBUG_FORMAT_DEFAULT = 0x00000000;

        public const uint DEBUG_FORMAT_CAB_SECONDARY_ALL_IMAGES = 0x10000000;

        public const uint DEBUG_FORMAT_WRITE_CAB = 0x20000000;

        public const uint DEBUG_FORMAT_CAB_SECONDARY_FILES = 0x40000000;

        public const uint DEBUG_FORMAT_NO_OVERWRITE = 0x80000000;

        public const uint DEBUG_FORMAT_USER_SMALL_FULL_MEMORY = 0x00000001;

        public const uint DEBUG_FORMAT_USER_SMALL_HANDLE_DATA = 0x00000002;

        public const uint DEBUG_FORMAT_USER_SMALL_UNLOADED_MODULES = 0x00000004;

        public const uint DEBUG_FORMAT_USER_SMALL_INDIRECT_MEMORY = 0x00000008;

        public const uint DEBUG_FORMAT_USER_SMALL_DATA_SEGMENTS = 0x00000010;

        public const uint DEBUG_FORMAT_USER_SMALL_FILTER_MEMORY = 0x00000020;

        public const uint DEBUG_FORMAT_USER_SMALL_FILTER_PATHS = 0x00000040;

        public const uint DEBUG_FORMAT_USER_SMALL_PROCESS_THREAD_DATA = 0x00000080;

        public const uint DEBUG_FORMAT_USER_SMALL_PRIVATE_READ_WRITE_MEMORY = 0x00000100;

        public const uint DEBUG_FORMAT_USER_SMALL_NO_OPTIONAL_DATA = 0x00000200;

        public const uint DEBUG_FORMAT_USER_SMALL_FULL_MEMORY_INFO = 0x00000400;

        public const uint DEBUG_FORMAT_USER_SMALL_THREAD_INFO = 0x00000800;

        public const uint DEBUG_FORMAT_USER_SMALL_CODE_SEGMENTS = 0x00001000;

        public const uint DEBUG_FORMAT_USER_SMALL_NO_AUXILIARY_STATE = 0x00002000;

        public const uint DEBUG_FORMAT_USER_SMALL_FULL_AUXILIARY_STATE = 0x00004000;

        public const uint DEBUG_FORMAT_USER_SMALL_MODULE_HEADERS = 0x00008000;

        public const uint DEBUG_FORMAT_USER_SMALL_FILTER_TRIAGE = 0x00010000;

        public const uint DEBUG_FORMAT_USER_SMALL_ADD_AVX_XSTATE_CONTEXT = 0x00020000;

        public const uint DEBUG_FORMAT_USER_SMALL_IPT_TRACE = 0x00040000;

        public const uint DEBUG_FORMAT_USER_SMALL_IGNORE_INACCESSIBLE_MEM = 0x08000000;

        public const uint DEBUG_FORMAT_USER_SMALL_SCAN_PARTIAL_PAGES = 0x10000000;

        public const uint DEBUG_DUMP_FILE_BASE = 0xffffffff;

        public const uint DEBUG_DUMP_FILE_PAGE_FILE_DUMP = 0x00000000;

        public const uint DEBUG_DUMP_FILE_LOAD_FAILED_INDEX = 0xffffffff;

        public const uint DEBUG_DUMP_FILE_ORIGINAL_CAB_INDEX = 0xfffffffe;

        public const uint DEBUG_STATUS_NO_CHANGE = 0;

        public const uint DEBUG_STATUS_GO = 1;

        public const uint DEBUG_STATUS_GO_HANDLED = 2;

        public const uint DEBUG_STATUS_GO_NOT_HANDLED = 3;

        public const uint DEBUG_STATUS_STEP_OVER = 4;

        public const uint DEBUG_STATUS_STEP_INTO = 5;

        public const uint DEBUG_STATUS_BREAK = 6;

        public const uint DEBUG_STATUS_NO_DEBUGGEE = 7;

        public const uint DEBUG_STATUS_STEP_BRANCH = 8;

        public const uint DEBUG_STATUS_IGNORE_EVENT = 9;

        public const uint DEBUG_STATUS_RESTART_REQUESTED = 10;

        public const uint DEBUG_STATUS_REVERSE_GO = 11;

        public const uint DEBUG_STATUS_REVERSE_STEP_BRANCH = 12;

        public const uint DEBUG_STATUS_REVERSE_STEP_OVER = 13;

        public const uint DEBUG_STATUS_REVERSE_STEP_INTO = 14;

        public const uint DEBUG_STATUS_OUT_OF_SYNC = 15;

        public const uint DEBUG_STATUS_WAIT_INPUT = 16;

        public const uint DEBUG_STATUS_TIMEOUT = 17;

        public const uint DEBUG_STATUS_MASK = 0x1f;

        public const ulong DEBUG_STATUS_INSIDE_WAIT = 0x100000000;

        public const ulong DEBUG_STATUS_WAIT_TIMEOUT = 0x200000000;

        public const uint DEBUG_OUTCTL_THIS_CLIENT = 0x00000000;

        public const uint DEBUG_OUTCTL_ALL_CLIENTS = 0x00000001;

        public const uint DEBUG_OUTCTL_ALL_OTHER_CLIENTS = 0x00000002;

        public const uint DEBUG_OUTCTL_IGNORE = 0x00000003;

        public const uint DEBUG_OUTCTL_LOG_ONLY = 0x00000004;

        public const uint DEBUG_OUTCTL_SEND_MASK = 0x00000007;

        public const uint DEBUG_OUTCTL_NOT_LOGGED = 0x00000008;

        public const uint DEBUG_OUTCTL_OVERRIDE_MASK = 0x00000010;

        public const uint DEBUG_OUTCTL_DML = 0x00000020;

        public const uint DEBUG_OUTCTL_AMBIENT_DML = 0xfffffffe;

        public const uint DEBUG_OUTCTL_AMBIENT_TEXT = 0xffffffff;

        public const uint DEBUG_INTERRUPT_ACTIVE = 0;

        public const uint DEBUG_INTERRUPT_PASSIVE = 1;

        public const uint DEBUG_INTERRUPT_EXIT = 2;

        public const uint DEBUG_CURRENT_DEFAULT = 0x0000000f;

        public const uint DEBUG_CURRENT_SYMBOL = 0x00000001;

        public const uint DEBUG_CURRENT_DISASM = 0x00000002;

        public const uint DEBUG_CURRENT_REGISTERS = 0x00000004;

        public const uint DEBUG_CURRENT_SOURCE_LINE = 0x00000008;

        public const uint DEBUG_DISASM_EFFECTIVE_ADDRESS = 0x00000001;

        public const uint DEBUG_DISASM_MATCHING_SYMBOLS = 0x00000002;

        public const uint DEBUG_DISASM_SOURCE_LINE_NUMBER = 0x00000004;

        public const uint DEBUG_DISASM_SOURCE_FILE_NAME = 0x00000008;

        public const uint DEBUG_LEVEL_SOURCE = 0;

        public const uint DEBUG_LEVEL_ASSEMBLY = 1;

        public const uint DEBUG_ENGOPT_IGNORE_DBGHELP_VERSION = 0x00000001;

        public const uint DEBUG_ENGOPT_IGNORE_EXTENSION_VERSIONS = 0x00000002;

        public const uint DEBUG_ENGOPT_ALLOW_NETWORK_PATHS = 0x00000004;

        public const uint DEBUG_ENGOPT_DISALLOW_NETWORK_PATHS = 0x00000008;

        public const uint DEBUG_ENGOPT_IGNORE_LOADER_EXCEPTIONS = 0x00000010;

        public const uint DEBUG_ENGOPT_INITIAL_BREAK = 0x00000020;

        public const uint DEBUG_ENGOPT_INITIAL_MODULE_BREAK = 0x00000040;

        public const uint DEBUG_ENGOPT_FINAL_BREAK = 0x00000080;

        public const uint DEBUG_ENGOPT_NO_EXECUTE_REPEAT = 0x00000100;

        public const uint DEBUG_ENGOPT_FAIL_INCOMPLETE_INFORMATION = 0x00000200;

        public const uint DEBUG_ENGOPT_ALLOW_READ_ONLY_BREAKPOINTS = 0x00000400;

        public const uint DEBUG_ENGOPT_SYNCHRONIZE_BREAKPOINTS = 0x00000800;

        public const uint DEBUG_ENGOPT_DISALLOW_SHELL_COMMANDS = 0x00001000;

        public const uint DEBUG_ENGOPT_KD_QUIET_MODE = 0x00002000;

        public const uint DEBUG_ENGOPT_DISABLE_MANAGED_SUPPORT = 0x00004000;

        public const uint DEBUG_ENGOPT_DISABLE_MODULE_SYMBOL_LOAD = 0x00008000;

        public const uint DEBUG_ENGOPT_DISABLE_EXECUTION_COMMANDS = 0x00010000;

        public const uint DEBUG_ENGOPT_DISALLOW_IMAGE_FILE_MAPPING = 0x00020000;

        public const uint DEBUG_ENGOPT_PREFER_DML = 0x00040000;

        public const uint DEBUG_ENGOPT_DISABLESQM = 0x00080000;

        public const uint DEBUG_ENGOPT_DISABLE_STEPLINES_OPTIONS = 0x00200000;

        public const uint DEBUG_ENGOPT_DEBUGGING_SENSITIVE_DATA = 0x00400000;

        public const uint DEBUG_ENGOPT_PREFER_TRACE_FILES = 0x00800000;

        public const uint DEBUG_ENGOPT_ALL = 0x00EFFFFF;

        public const uint DEBUG_ANY_ID = 0xffffffff;

        public const uint DBG_FRAME_DEFAULT = 0;

        public const uint DBG_FRAME_IGNORE_INLINE = 0xFFFFFFFF;

        public const uint STACK_FRAME_TYPE_INIT = 0x00;

        public const uint STACK_FRAME_TYPE_STACK = 0x01;

        public const uint STACK_FRAME_TYPE_INLINE = 0x02;

        public const uint STACK_FRAME_TYPE_RA = 0x80;

        public const uint STACK_FRAME_TYPE_IGNORE = 0xFF;

        public const uint DEBUG_STACK_ARGUMENTS = 0x00000001;

        public const uint DEBUG_STACK_FUNCTION_INFO = 0x00000002;

        public const uint DEBUG_STACK_SOURCE_LINE = 0x00000004;

        public const uint DEBUG_STACK_FRAME_ADDRESSES = 0x00000008;

        public const uint DEBUG_STACK_COLUMN_NAMES = 0x00000010;

        public const uint DEBUG_STACK_NONVOLATILE_REGISTERS = 0x00000020;

        public const uint DEBUG_STACK_FRAME_NUMBERS = 0x00000040;

        public const uint DEBUG_STACK_PARAMETERS = 0x00000080;

        public const uint DEBUG_STACK_FRAME_ADDRESSES_RA_ONLY = 0x00000100;

        public const uint DEBUG_STACK_FRAME_MEMORY_USAGE = 0x00000200;

        public const uint DEBUG_STACK_PARAMETERS_NEWLINE = 0x00000400;

        public const uint DEBUG_STACK_DML = 0x00000800;

        public const uint DEBUG_STACK_FRAME_OFFSETS = 0x00001000;

        public const uint DEBUG_STACK_PROVIDER = 0x00002000;

        public const uint DEBUG_STACK_FRAME_ARCH = 0x00004000;

        public const uint DEBUG_CLASS_UNINITIALIZED = 0;

        public const uint DEBUG_CLASS_KERNEL = 1;

        public const uint DEBUG_CLASS_USER_WINDOWS = 2;

        public const uint DEBUG_CLASS_IMAGE_FILE = 3;

        public const uint DEBUG_DUMP_SMALL = 1024;

        public const uint DEBUG_DUMP_DEFAULT = 1025;

        public const uint DEBUG_DUMP_FULL = 1026;

        public const uint DEBUG_DUMP_IMAGE_FILE = 1027;

        public const uint DEBUG_DUMP_TRACE_LOG = 1028;

        public const uint DEBUG_DUMP_WINDOWS_CE = 1029;

        public const uint DEBUG_DUMP_ACTIVE = 1030;

        public const uint DEBUG_KERNEL_CONNECTION = 0;

        public const uint DEBUG_KERNEL_LOCAL = 1;

        public const uint DEBUG_KERNEL_EXDI_DRIVER = 2;

        public const uint DEBUG_KERNEL_IDNA = 3;

        public const uint DEBUG_KERNEL_INSTALL_DRIVER = 4;

        public const uint DEBUG_KERNEL_REPT = 5;

        public const uint DEBUG_USER_WINDOWS_PROCESS = 0;

        public const uint DEBUG_USER_WINDOWS_PROCESS_SERVER = 1;

        public const uint DEBUG_USER_WINDOWS_IDNA = 2;

        public const uint DEBUG_USER_WINDOWS_REPT = 3;

        public const uint DEBUG_EXTENSION_AT_ENGINE = 0x00000000;

        public const uint DEBUG_EXECUTE_DEFAULT = 0x00000000;

        public const uint DEBUG_EXECUTE_ECHO = 0x00000001;

        public const uint DEBUG_EXECUTE_NOT_LOGGED = 0x00000002;

        public const uint DEBUG_EXECUTE_NO_REPEAT = 0x00000004;

        public const uint DEBUG_EXECUTE_USER_TYPED = 0x00000008;

        public const uint DEBUG_EXECUTE_USER_CLICKED = 0x00000010;

        public const uint DEBUG_EXECUTE_EXTENSION = 0x00000020;

        public const uint DEBUG_EXECUTE_INTERNAL = 0x00000040;

        public const uint DEBUG_EXECUTE_SCRIPT = 0x00000080;

        public const uint DEBUG_EXECUTE_TOOLBAR = 0x00000100;

        public const uint DEBUG_EXECUTE_MENU = 0x00000200;

        public const uint DEBUG_EXECUTE_HOTKEY = 0x00000400;

        public const uint DEBUG_EXECUTE_EVENT = 0x00000800;

        public const uint DEBUG_FILTER_CREATE_THREAD = 0x00000000;

        public const uint DEBUG_FILTER_EXIT_THREAD = 0x00000001;

        public const uint DEBUG_FILTER_CREATE_PROCESS = 0x00000002;

        public const uint DEBUG_FILTER_EXIT_PROCESS = 0x00000003;

        public const uint DEBUG_FILTER_LOAD_MODULE = 0x00000004;

        public const uint DEBUG_FILTER_UNLOAD_MODULE = 0x00000005;

        public const uint DEBUG_FILTER_SYSTEM_ERROR = 0x00000006;

        public const uint DEBUG_FILTER_INITIAL_BREAKPOINT = 0x00000007;

        public const uint DEBUG_FILTER_INITIAL_MODULE_LOAD = 0x00000008;

        public const uint DEBUG_FILTER_DEBUGGEE_OUTPUT = 0x00000009;

        public const uint DEBUG_FILTER_BREAK = 0x00000000;

        public const uint DEBUG_FILTER_SECOND_CHANCE_BREAK = 0x00000001;

        public const uint DEBUG_FILTER_OUTPUT = 0x00000002;

        public const uint DEBUG_FILTER_IGNORE = 0x00000003;

        public const uint DEBUG_FILTER_REMOVE = 0x00000004;

        public const uint DEBUG_FILTER_GO_HANDLED = 0x00000000;

        public const uint DEBUG_FILTER_GO_NOT_HANDLED = 0x00000001;

        public const uint DEBUG_WAIT_DEFAULT = 0x00000000;

        public const uint DEBUG_VALUE_INVALID = 0;

        public const uint DEBUG_VALUE_INT8 = 1;

        public const uint DEBUG_VALUE_INT16 = 2;

        public const uint DEBUG_VALUE_INT32 = 3;

        public const uint DEBUG_VALUE_INT64 = 4;

        public const uint DEBUG_VALUE_FLOAT32 = 5;

        public const uint DEBUG_VALUE_FLOAT64 = 6;

        public const uint DEBUG_VALUE_FLOAT80 = 7;

        public const uint DEBUG_VALUE_FLOAT82 = 8;

        public const uint DEBUG_VALUE_FLOAT128 = 9;

        public const uint DEBUG_VALUE_VECTOR64 = 10;

        public const uint DEBUG_VALUE_VECTOR128 = 11;

        public const uint DEBUG_VALUE_TYPES = 12;

        public const uint DEBUG_OUT_TEXT_REPL_DEFAULT = 0x00000000;

        public const uint DEBUG_ASMOPT_DEFAULT = 0x00000000;

        public const uint DEBUG_ASMOPT_VERBOSE = 0x00000001;

        public const uint DEBUG_ASMOPT_NO_CODE_BYTES = 0x00000002;

        public const uint DEBUG_ASMOPT_IGNORE_OUTPUT_WIDTH = 0x00000004;

        public const uint DEBUG_ASMOPT_SOURCE_LINE_NUMBER = 0x00000008;

        public const uint DEBUG_EXPR_MASM = 0x00000000;

        public const uint DEBUG_EXPR_CPLUSPLUS = 0x00000001;

        public const uint DEBUG_EINDEX_NAME = 0x00000000;

        public const uint DEBUG_EINDEX_FROM_START = 0x00000000;

        public const uint DEBUG_EINDEX_FROM_END = 0x00000001;

        public const uint DEBUG_EINDEX_FROM_CURRENT = 0x00000002;

        public const uint DEBUG_LOG_DEFAULT = 0x00000000;

        public const uint DEBUG_LOG_APPEND = 0x00000001;

        public const uint DEBUG_LOG_UNICODE = 0x00000002;

        public const uint DEBUG_LOG_DML = 0x00000004;

        public const uint DEBUG_SYSVERSTR_SERVICE_PACK = 0x00000000;

        public const uint DEBUG_SYSVERSTR_BUILD = 0x00000001;

        public const uint DEBUG_MANAGED_DISABLED = 0x00000000;

        public const uint DEBUG_MANAGED_ALLOWED = 0x00000001;

        public const uint DEBUG_MANAGED_DLL_LOADED = 0x00000002;

        public const uint DEBUG_MANSTR_NONE = 0x00000000;

        public const uint DEBUG_MANSTR_LOADED_SUPPORT_DLL = 0x00000001;

        public const uint DEBUG_MANSTR_LOAD_STATUS = 0x00000002;

        public const uint DEBUG_MANRESET_DEFAULT = 0x00000000;

        public const uint DEBUG_MANRESET_LOAD_DLL = 0x00000001;

        public const uint DEBUG_EXEC_FLAGS_NONBLOCK = 0x00000001;

        public const uint DEBUG_DATA_SPACE_VIRTUAL = 0;

        public const uint DEBUG_DATA_SPACE_PHYSICAL = 1;

        public const uint DEBUG_DATA_SPACE_CONTROL = 2;

        public const uint DEBUG_DATA_SPACE_IO = 3;

        public const uint DEBUG_DATA_SPACE_MSR = 4;

        public const uint DEBUG_DATA_SPACE_BUS_DATA = 5;

        public const uint DEBUG_DATA_SPACE_DEBUGGER_DATA = 6;

        public const uint DEBUG_DATA_SPACE_COUNT = 7;

        public const uint DEBUG_DATA_KernBase = 24;

        public const uint DEBUG_DATA_BreakpointWithStatusAddr = 32;

        public const uint DEBUG_DATA_SavedContextAddr = 40;

        public const uint DEBUG_DATA_KiCallUserModeAddr = 56;

        public const uint DEBUG_DATA_KeUserCallbackDispatcherAddr = 64;

        public const uint DEBUG_DATA_PsLoadedModuleListAddr = 72;

        public const uint DEBUG_DATA_PsActiveProcessHeadAddr = 80;

        public const uint DEBUG_DATA_PspCidTableAddr = 88;

        public const uint DEBUG_DATA_ExpSystemResourcesListAddr = 96;

        public const uint DEBUG_DATA_ExpPagedPoolDescriptorAddr = 104;

        public const uint DEBUG_DATA_ExpNumberOfPagedPoolsAddr = 112;

        public const uint DEBUG_DATA_KeTimeIncrementAddr = 120;

        public const uint DEBUG_DATA_KeBugCheckCallbackListHeadAddr = 128;

        public const uint DEBUG_DATA_KiBugcheckDataAddr = 136;

        public const uint DEBUG_DATA_IopErrorLogListHeadAddr = 144;

        public const uint DEBUG_DATA_ObpRootDirectoryObjectAddr = 152;

        public const uint DEBUG_DATA_ObpTypeObjectTypeAddr = 160;

        public const uint DEBUG_DATA_MmSystemCacheStartAddr = 168;

        public const uint DEBUG_DATA_MmSystemCacheEndAddr = 176;

        public const uint DEBUG_DATA_MmSystemCacheWsAddr = 184;

        public const uint DEBUG_DATA_MmPfnDatabaseAddr = 192;

        public const uint DEBUG_DATA_MmSystemPtesStartAddr = 200;

        public const uint DEBUG_DATA_MmSystemPtesEndAddr = 208;

        public const uint DEBUG_DATA_MmSubsectionBaseAddr = 216;

        public const uint DEBUG_DATA_MmNumberOfPagingFilesAddr = 224;

        public const uint DEBUG_DATA_MmLowestPhysicalPageAddr = 232;

        public const uint DEBUG_DATA_MmHighestPhysicalPageAddr = 240;

        public const uint DEBUG_DATA_MmNumberOfPhysicalPagesAddr = 248;

        public const uint DEBUG_DATA_MmMaximumNonPagedPoolInBytesAddr = 256;

        public const uint DEBUG_DATA_MmNonPagedSystemStartAddr = 264;

        public const uint DEBUG_DATA_MmNonPagedPoolStartAddr = 272;

        public const uint DEBUG_DATA_MmNonPagedPoolEndAddr = 280;

        public const uint DEBUG_DATA_MmPagedPoolStartAddr = 288;

        public const uint DEBUG_DATA_MmPagedPoolEndAddr = 296;

        public const uint DEBUG_DATA_MmPagedPoolInformationAddr = 304;

        public const uint DEBUG_DATA_MmPageSize = 312;

        public const uint DEBUG_DATA_MmSizeOfPagedPoolInBytesAddr = 320;

        public const uint DEBUG_DATA_MmTotalCommitLimitAddr = 328;

        public const uint DEBUG_DATA_MmTotalCommittedPagesAddr = 336;

        public const uint DEBUG_DATA_MmSharedCommitAddr = 344;

        public const uint DEBUG_DATA_MmDriverCommitAddr = 352;

        public const uint DEBUG_DATA_MmProcessCommitAddr = 360;

        public const uint DEBUG_DATA_MmPagedPoolCommitAddr = 368;

        public const uint DEBUG_DATA_MmExtendedCommitAddr = 376;

        public const uint DEBUG_DATA_MmZeroedPageListHeadAddr = 384;

        public const uint DEBUG_DATA_MmFreePageListHeadAddr = 392;

        public const uint DEBUG_DATA_MmStandbyPageListHeadAddr = 400;

        public const uint DEBUG_DATA_MmModifiedPageListHeadAddr = 408;

        public const uint DEBUG_DATA_MmModifiedNoWritePageListHeadAddr = 416;

        public const uint DEBUG_DATA_MmAvailablePagesAddr = 424;

        public const uint DEBUG_DATA_MmResidentAvailablePagesAddr = 432;

        public const uint DEBUG_DATA_PoolTrackTableAddr = 440;

        public const uint DEBUG_DATA_NonPagedPoolDescriptorAddr = 448;

        public const uint DEBUG_DATA_MmHighestUserAddressAddr = 456;

        public const uint DEBUG_DATA_MmSystemRangeStartAddr = 464;

        public const uint DEBUG_DATA_MmUserProbeAddressAddr = 472;

        public const uint DEBUG_DATA_KdPrintCircularBufferAddr = 480;

        public const uint DEBUG_DATA_KdPrintCircularBufferEndAddr = 488;

        public const uint DEBUG_DATA_KdPrintWritePointerAddr = 496;

        public const uint DEBUG_DATA_KdPrintRolloverCountAddr = 504;

        public const uint DEBUG_DATA_MmLoadedUserImageListAddr = 512;

        public const uint DEBUG_DATA_NtBuildLabAddr = 520;

        public const uint DEBUG_DATA_KiNormalSystemCall = 528;

        public const uint DEBUG_DATA_KiProcessorBlockAddr = 536;

        public const uint DEBUG_DATA_MmUnloadedDriversAddr = 544;

        public const uint DEBUG_DATA_MmLastUnloadedDriverAddr = 552;

        public const uint DEBUG_DATA_MmTriageActionTakenAddr = 560;

        public const uint DEBUG_DATA_MmSpecialPoolTagAddr = 568;

        public const uint DEBUG_DATA_KernelVerifierAddr = 576;

        public const uint DEBUG_DATA_MmVerifierDataAddr = 584;

        public const uint DEBUG_DATA_MmAllocatedNonPagedPoolAddr = 592;

        public const uint DEBUG_DATA_MmPeakCommitmentAddr = 600;

        public const uint DEBUG_DATA_MmTotalCommitLimitMaximumAddr = 608;

        public const uint DEBUG_DATA_CmNtCSDVersionAddr = 616;

        public const uint DEBUG_DATA_MmPhysicalMemoryBlockAddr = 624;

        public const uint DEBUG_DATA_MmSessionBase = 632;

        public const uint DEBUG_DATA_MmSessionSize = 640;

        public const uint DEBUG_DATA_MmSystemParentTablePage = 648;

        public const uint DEBUG_DATA_MmVirtualTranslationBase = 656;

        public const uint DEBUG_DATA_OffsetKThreadNextProcessor = 664;

        public const uint DEBUG_DATA_OffsetKThreadTeb = 666;

        public const uint DEBUG_DATA_OffsetKThreadKernelStack = 668;

        public const uint DEBUG_DATA_OffsetKThreadInitialStack = 670;

        public const uint DEBUG_DATA_OffsetKThreadApcProcess = 672;

        public const uint DEBUG_DATA_OffsetKThreadState = 674;

        public const uint DEBUG_DATA_OffsetKThreadBStore = 676;

        public const uint DEBUG_DATA_OffsetKThreadBStoreLimit = 678;

        public const uint DEBUG_DATA_SizeEProcess = 680;

        public const uint DEBUG_DATA_OffsetEprocessPeb = 682;

        public const uint DEBUG_DATA_OffsetEprocessParentCID = 684;

        public const uint DEBUG_DATA_OffsetEprocessDirectoryTableBase = 686;

        public const uint DEBUG_DATA_SizePrcb = 688;

        public const uint DEBUG_DATA_OffsetPrcbDpcRoutine = 690;

        public const uint DEBUG_DATA_OffsetPrcbCurrentThread = 692;

        public const uint DEBUG_DATA_OffsetPrcbMhz = 694;

        public const uint DEBUG_DATA_OffsetPrcbCpuType = 696;

        public const uint DEBUG_DATA_OffsetPrcbVendorString = 698;

        public const uint DEBUG_DATA_OffsetPrcbProcessorState = 700;

        public const uint DEBUG_DATA_OffsetPrcbNumber = 702;

        public const uint DEBUG_DATA_SizeEThread = 704;

        public const uint DEBUG_DATA_KdPrintCircularBufferPtrAddr = 712;

        public const uint DEBUG_DATA_KdPrintBufferSizeAddr = 720;

        public const uint DEBUG_DATA_MmBadPagesDetected = 800;

        public const uint DEBUG_DATA_EtwpDebuggerData = 816;

        public const uint DEBUG_DATA_PteBase = 864;

        public const uint DEBUG_DATA_PaeEnabled = 100000;

        public const uint DEBUG_DATA_SharedUserData = 100008;

        public const uint DEBUG_DATA_ProductType = 100016;

        public const uint DEBUG_DATA_SuiteMask = 100024;

        public const uint DEBUG_DATA_DumpWriterStatus = 100032;

        public const uint DEBUG_DATA_DumpFormatVersion = 100040;

        public const uint DEBUG_DATA_DumpWriterVersion = 100048;

        public const uint DEBUG_DATA_DumpPowerState = 100056;

        public const uint DEBUG_DATA_DumpMmStorage = 100064;

        public const uint DEBUG_DATA_DumpAttributes = 100072;

        public const uint DEBUG_DATA_KPCR_OFFSET = 0;

        public const uint DEBUG_DATA_KPRCB_OFFSET = 1;

        public const uint DEBUG_DATA_KTHREAD_OFFSET = 2;

        public const uint DEBUG_DATA_BASE_TRANSLATION_VIRTUAL_OFFSET = 3;

        public const uint DEBUG_DATA_PROCESSOR_IDENTIFICATION = 4;

        public const uint DEBUG_DATA_PROCESSOR_SPEED = 5;

        public const uint DEBUG_HANDLE_DATA_TYPE_BASIC = 0;

        public const uint DEBUG_HANDLE_DATA_TYPE_TYPE_NAME = 1;

        public const uint DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME = 2;

        public const uint DEBUG_HANDLE_DATA_TYPE_HANDLE_COUNT = 3;

        public const uint DEBUG_HANDLE_DATA_TYPE_TYPE_NAME_WIDE = 4;

        public const uint DEBUG_HANDLE_DATA_TYPE_OBJECT_NAME_WIDE = 5;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_THREAD_1 = 6;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_1 = 7;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_MUTANT_2 = 8;

        public const uint DEBUG_HANDLE_DATA_TYPE_PER_HANDLE_OPERATIONS = 9;

        public const uint DEBUG_HANDLE_DATA_TYPE_ALL_HANDLE_OPERATIONS = 10;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_1 = 11;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_PROCESS_2 = 12;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_EVENT_1 = 13;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_SECTION_1 = 14;

        public const uint DEBUG_HANDLE_DATA_TYPE_MINI_SEMAPHORE_1 = 15;

        public const uint DEBUG_OFFSINFO_VIRTUAL_SOURCE = 0x00000001;

        public const uint DEBUG_VSOURCE_INVALID = 0x00000000;

        public const uint DEBUG_VSOURCE_DEBUGGEE = 0x00000001;

        public const uint DEBUG_VSOURCE_MAPPED_IMAGE = 0x00000002;

        public const uint DEBUG_VSOURCE_DUMP_WITHOUT_MEMINFO = 0x00000003;

        public const uint DEBUG_VSEARCH_DEFAULT = 0x00000000;

        public const uint DEBUG_VSEARCH_WRITABLE_ONLY = 0x00000001;

        public const uint DEBUG_PHYSICAL_DEFAULT = 0x00000000;

        public const uint DEBUG_PHYSICAL_CACHED = 0x00000001;

        public const uint DEBUG_PHYSICAL_UNCACHED = 0x00000002;

        public const uint DEBUG_PHYSICAL_WRITE_COMBINED = 0x00000003;

        public const uint DEBUG_EVENT_BREAKPOINT = 0x00000001;

        public const uint DEBUG_EVENT_EXCEPTION = 0x00000002;

        public const uint DEBUG_EVENT_CREATE_THREAD = 0x00000004;

        public const uint DEBUG_EVENT_EXIT_THREAD = 0x00000008;

        public const uint DEBUG_EVENT_CREATE_PROCESS = 0x00000010;

        public const uint DEBUG_EVENT_EXIT_PROCESS = 0x00000020;

        public const uint DEBUG_EVENT_LOAD_MODULE = 0x00000040;

        public const uint DEBUG_EVENT_UNLOAD_MODULE = 0x00000080;

        public const uint DEBUG_EVENT_SYSTEM_ERROR = 0x00000100;

        public const uint DEBUG_EVENT_SESSION_STATUS = 0x00000200;

        public const uint DEBUG_EVENT_CHANGE_DEBUGGEE_STATE = 0x00000400;

        public const uint DEBUG_EVENT_CHANGE_ENGINE_STATE = 0x00000800;

        public const uint DEBUG_EVENT_CHANGE_SYMBOL_STATE = 0x00001000;

        public const uint DEBUG_EVENT_SERVICE_EXCEPTION = 0x00002000;

        public const uint DEBUG_SESSION_ACTIVE = 0x00000000;

        public const uint DEBUG_SESSION_END_SESSION_ACTIVE_TERMINATE = 0x00000001;

        public const uint DEBUG_SESSION_END_SESSION_ACTIVE_DETACH = 0x00000002;

        public const uint DEBUG_SESSION_END_SESSION_PASSIVE = 0x00000003;

        public const uint DEBUG_SESSION_END = 0x00000004;

        public const uint DEBUG_SESSION_REBOOT = 0x00000005;

        public const uint DEBUG_SESSION_HIBERNATE = 0x00000006;

        public const uint DEBUG_SESSION_FAILURE = 0x00000007;

        public const uint DEBUG_CDS_ALL = 0xffffffff;

        public const uint DEBUG_CDS_REGISTERS = 0x00000001;

        public const uint DEBUG_CDS_DATA = 0x00000002;

        public const uint DEBUG_CDS_REFRESH = 0x00000004;

        public const uint DEBUG_CDS_REFRESH_EVALUATE = 1;

        public const uint DEBUG_CDS_REFRESH_EXECUTE = 2;

        public const uint DEBUG_CDS_REFRESH_EXECUTECOMMANDFILE = 3;

        public const uint DEBUG_CDS_REFRESH_ADDBREAKPOINT = 4;

        public const uint DEBUG_CDS_REFRESH_REMOVEBREAKPOINT = 5;

        public const uint DEBUG_CDS_REFRESH_WRITEVIRTUAL = 6;

        public const uint DEBUG_CDS_REFRESH_WRITEVIRTUALUNCACHED = 7;

        public const uint DEBUG_CDS_REFRESH_WRITEPHYSICAL = 8;

        public const uint DEBUG_CDS_REFRESH_WRITEPHYSICAL2 = 9;

        public const uint DEBUG_CDS_REFRESH_SETVALUE = 10;

        public const uint DEBUG_CDS_REFRESH_SETVALUE2 = 11;

        public const uint DEBUG_CDS_REFRESH_SETSCOPE = 12;

        public const uint DEBUG_CDS_REFRESH_SETSCOPEFRAMEBYINDEX = 13;

        public const uint DEBUG_CDS_REFRESH_SETSCOPEFROMJITDEBUGINFO = 14;

        public const uint DEBUG_CDS_REFRESH_SETSCOPEFROMSTOREDEVENT = 15;

        public const uint DEBUG_CDS_REFRESH_INLINESTEP = 16;

        public const uint DEBUG_CDS_REFRESH_INLINESTEP_PSEUDO = 17;

        public const uint DEBUG_CES_ALL = 0xffffffff;

        public const uint DEBUG_CES_CURRENT_THREAD = 0x00000001;

        public const uint DEBUG_CES_EFFECTIVE_PROCESSOR = 0x00000002;

        public const uint DEBUG_CES_BREAKPOINTS = 0x00000004;

        public const uint DEBUG_CES_CODE_LEVEL = 0x00000008;

        public const uint DEBUG_CES_EXECUTION_STATUS = 0x00000010;

        public const uint DEBUG_CES_ENGINE_OPTIONS = 0x00000020;

        public const uint DEBUG_CES_LOG_FILE = 0x00000040;

        public const uint DEBUG_CES_RADIX = 0x00000080;

        public const uint DEBUG_CES_EVENT_FILTERS = 0x00000100;

        public const uint DEBUG_CES_PROCESS_OPTIONS = 0x00000200;

        public const uint DEBUG_CES_EXTENSIONS = 0x00000400;

        public const uint DEBUG_CES_SYSTEMS = 0x00000800;

        public const uint DEBUG_CES_ASSEMBLY_OPTIONS = 0x00001000;

        public const uint DEBUG_CES_EXPRESSION_SYNTAX = 0x00002000;

        public const uint DEBUG_CES_TEXT_REPLACEMENTS = 0x00004000;

        public const uint DEBUG_CSS_ALL = 0xffffffff;

        public const uint DEBUG_CSS_LOADS = 0x00000001;

        public const uint DEBUG_CSS_UNLOADS = 0x00000002;

        public const uint DEBUG_CSS_SCOPE = 0x00000004;

        public const uint DEBUG_CSS_PATHS = 0x00000008;

        public const uint DEBUG_CSS_SYMBOL_OPTIONS = 0x00000010;

        public const uint DEBUG_CSS_TYPE_OPTIONS = 0x00000020;

        public const uint DEBUG_CSS_COLLAPSE_CHILDREN = 0x00000040;

        public const uint DEBUG_OUTCBI_EXPLICIT_FLUSH = 0x00000001;

        public const uint DEBUG_OUTCBI_TEXT = 0x00000002;

        public const uint DEBUG_OUTCBI_DML = 0x00000004;

        public const uint DEBUG_OUTCBI_ANY_FORMAT = 0x00000006;

        public const uint DEBUG_OUTCB_TEXT = 0;

        public const uint DEBUG_OUTCB_DML = 1;

        public const uint DEBUG_OUTCB_EXPLICIT_FLUSH = 2;

        public const uint DEBUG_OUTCBF_COMBINED_EXPLICIT_FLUSH = 0x00000001;

        public const uint DEBUG_OUTCBF_DML_HAS_TAGS = 0x00000002;

        public const uint DEBUG_OUTCBF_DML_HAS_SPECIAL_CHARACTERS = 0x00000004;

        public const uint DEBUG_REGISTERS_DEFAULT = 0x00000000;

        public const uint DEBUG_REGISTERS_INT32 = 0x00000001;

        public const uint DEBUG_REGISTERS_INT64 = 0x00000002;

        public const uint DEBUG_REGISTERS_FLOAT = 0x00000004;

        public const uint DEBUG_REGISTERS_ALL = 0x00000007;

        public const uint DEBUG_REGISTER_SUB_REGISTER = 0x00000001;

        public const uint DEBUG_REGSRC_DEBUGGEE = 0x00000000;

        public const uint DEBUG_REGSRC_EXPLICIT = 0x00000001;

        public const uint DEBUG_REGSRC_FRAME = 0x00000002;

        public const uint DEBUG_OUTPUT_SYMBOLS_DEFAULT = 0x00000000;

        public const uint DEBUG_OUTPUT_SYMBOLS_NO_NAMES = 0x00000001;

        public const uint DEBUG_OUTPUT_SYMBOLS_NO_OFFSETS = 0x00000002;

        public const uint DEBUG_OUTPUT_SYMBOLS_NO_VALUES = 0x00000004;

        public const uint DEBUG_OUTPUT_SYMBOLS_NO_TYPES = 0x00000010;

        public const uint DEBUG_SYMBOL_EXPANSION_LEVEL_MASK = 0x0000000f;

        public const uint DEBUG_SYMBOL_EXPANDED = 0x00000010;

        public const uint DEBUG_SYMBOL_READ_ONLY = 0x00000020;

        public const uint DEBUG_SYMBOL_IS_ARRAY = 0x00000040;

        public const uint DEBUG_SYMBOL_IS_FLOAT = 0x00000080;

        public const uint DEBUG_SYMBOL_IS_ARGUMENT = 0x00000100;

        public const uint DEBUG_SYMBOL_IS_LOCAL = 0x00000200;

        public const uint DEBUG_SYMENT_IS_CODE = 0x00000001;

        public const uint DEBUG_SYMENT_IS_DATA = 0x00000002;

        public const uint DEBUG_SYMENT_IS_PARAMETER = 0x00000004;

        public const uint DEBUG_SYMENT_IS_LOCAL = 0x00000008;

        public const uint DEBUG_SYMENT_IS_MANAGED = 0x00000010;

        public const uint DEBUG_SYMENT_IS_SYNTHETIC = 0x00000020;

        public const uint DEBUG_MODULE_LOADED = 0x00000000;

        public const uint DEBUG_MODULE_UNLOADED = 0x00000001;

        public const uint DEBUG_MODULE_USER_MODE = 0x00000002;

        public const uint DEBUG_MODULE_EXE_MODULE = 0x00000004;

        public const uint DEBUG_MODULE_EXPLICIT = 0x00000008;

        public const uint DEBUG_MODULE_SECONDARY = 0x00000010;

        public const uint DEBUG_MODULE_SYNTHETIC = 0x00000020;

        public const uint DEBUG_MODULE_SYM_BAD_CHECKSUM = 0x00010000;

        public const uint DEBUG_SYMTYPE_NONE = 0;

        public const uint DEBUG_SYMTYPE_COFF = 1;

        public const uint DEBUG_SYMTYPE_CODEVIEW = 2;

        public const uint DEBUG_SYMTYPE_PDB = 3;

        public const uint DEBUG_SYMTYPE_EXPORT = 4;

        public const uint DEBUG_SYMTYPE_DEFERRED = 5;

        public const uint DEBUG_SYMTYPE_SYM = 6;

        public const uint DEBUG_SYMTYPE_DIA = 7;

        public const uint DEBUG_SCOPE_GROUP_ARGUMENTS = 0x00000001;

        public const uint DEBUG_SCOPE_GROUP_LOCALS = 0x00000002;

        public const uint DEBUG_SCOPE_GROUP_ALL = 0x00000003;

        public const uint DEBUG_SCOPE_GROUP_BY_DATAMODEL = 0x00000004;

        public const uint DEBUG_OUTTYPE_DEFAULT = 0x00000000;

        public const uint DEBUG_OUTTYPE_NO_INDENT = 0x00000001;

        public const uint DEBUG_OUTTYPE_NO_OFFSET = 0x00000002;

        public const uint DEBUG_OUTTYPE_VERBOSE = 0x00000004;

        public const uint DEBUG_OUTTYPE_COMPACT_OUTPUT = 0x00000008;

        public const uint DEBUG_OUTTYPE_ADDRESS_OF_FIELD = 0x00010000;

        public const uint DEBUG_OUTTYPE_ADDRESS_AT_END = 0x00020000;

        public const uint DEBUG_OUTTYPE_BLOCK_RECURSE = 0x00200000;

        public const uint DEBUG_FIND_SOURCE_DEFAULT = 0x00000000;

        public const uint DEBUG_FIND_SOURCE_FULL_PATH = 0x00000001;

        public const uint DEBUG_FIND_SOURCE_BEST_MATCH = 0x00000002;

        public const uint DEBUG_FIND_SOURCE_NO_SRCSRV = 0x00000004;

        public const uint DEBUG_FIND_SOURCE_TOKEN_LOOKUP = 0x00000008;

        public const uint DEBUG_FIND_SOURCE_WITH_CHECKSUM = 0x00000010;

        public const uint MODULE_ORDERS_MASK = 0xF0000000;

        public const uint MODULE_ORDERS_LOADTIME = 0x10000000;

        public const uint MODULE_ORDERS_MODULENAME = 0x20000000;

        public const uint DEBUG_MODNAME_IMAGE = 0x00000000;

        public const uint DEBUG_MODNAME_MODULE = 0x00000001;

        public const uint DEBUG_MODNAME_LOADED_IMAGE = 0x00000002;

        public const uint DEBUG_MODNAME_SYMBOL_FILE = 0x00000003;

        public const uint DEBUG_MODNAME_MAPPED_IMAGE = 0x00000004;

        public const uint DEBUG_TYPEOPTS_UNICODE_DISPLAY = 0x00000001;

        public const uint DEBUG_TYPEOPTS_LONGSTATUS_DISPLAY = 0x00000002;

        public const uint DEBUG_TYPEOPTS_FORCERADIX_OUTPUT = 0x00000004;

        public const uint DEBUG_TYPEOPTS_MATCH_MAXSIZE = 0x00000008;

        public const uint DEBUG_GETMOD_DEFAULT = 0x00000000;

        public const uint DEBUG_GETMOD_NO_LOADED_MODULES = 0x00000001;

        public const uint DEBUG_GETMOD_NO_UNLOADED_MODULES = 0x00000002;

        public const uint DEBUG_ADDSYNTHMOD_DEFAULT = 0x00000000;

        public const uint DEBUG_ADDSYNTHMOD_ZEROBASE = 0x00000001;

        public const uint DEBUG_ADDSYNTHSYM_DEFAULT = 0x00000000;

        public const uint DEBUG_OUTSYM_DEFAULT = 0x00000000;

        public const uint DEBUG_OUTSYM_FORCE_OFFSET = 0x00000001;

        public const uint DEBUG_OUTSYM_SOURCE_LINE = 0x00000002;

        public const uint DEBUG_OUTSYM_ALLOW_DISPLACEMENT = 0x00000004;

        public const uint DEBUG_GETFNENT_DEFAULT = 0x00000000;

        public const uint DEBUG_GETFNENT_RAW_ENTRY_ONLY = 0x00000001;

        public const uint DEBUG_SOURCE_IS_STATEMENT = 0x00000001;

        public const uint DEBUG_GSEL_DEFAULT = 0x00000000;

        public const uint DEBUG_GSEL_NO_SYMBOL_LOADS = 0x00000001;

        public const uint DEBUG_GSEL_ALLOW_LOWER = 0x00000002;

        public const uint DEBUG_GSEL_ALLOW_HIGHER = 0x00000004;

        public const uint DEBUG_GSEL_NEAREST_ONLY = 0x00000008;

        public const uint DEBUG_GSEL_INLINE_CALLSITE = 0x00000010;

        public const uint DEBUG_FRAME_DEFAULT = 0;

        public const uint DEBUG_FRAME_IGNORE_INLINE = 0x00000001;

        public const uint DEBUG_COMMAND_EXCEPTION_ID = 0xdbe00dbe;

        public const uint DEBUG_CMDEX_INVALID = 0x00000000;

        public const uint DEBUG_CMDEX_ADD_EVENT_STRING = 0x00000001;

        public const uint DEBUG_CMDEX_RESET_EVENT_STRINGS = 0x00000002;

        public const uint DEBUG_EXTINIT_HAS_COMMAND_HELP = 0x00000001;

        public const uint DEBUG_NOTIFY_SESSION_ACTIVE = 0x00000000;

        public const uint DEBUG_NOTIFY_SESSION_INACTIVE = 0x00000001;

        public const uint DEBUG_NOTIFY_SESSION_ACCESSIBLE = 0x00000002;

        public const uint DEBUG_NOTIFY_SESSION_INACCESSIBLE = 0x00000003;

        public const uint DEBUG_KNOWN_STRUCT_GET_NAMES = 1;

        public const uint DEBUG_KNOWN_STRUCT_GET_SINGLE_LINE_OUTPUT = 2;

        public const uint DEBUG_KNOWN_STRUCT_SUPPRESS_TYPE_NAME = 3;

        public const uint DEBUG_EXT_QVALUE_DEFAULT = 0x00000000;

        public const uint DEBUG_EXT_PVALUE_DEFAULT = 0x00000000;

        public const uint DEBUG_EXT_PVTYPE_IS_VALUE = 0x00000000;

        public const uint DEBUG_EXT_PVTYPE_IS_POINTER = 0x00000001;

        public const uint CROSS_PLATFORM_MAXIMUM_PROCESSORS = 2048;

        public const uint EXT_API_VERSION_NUMBER = 5;

        public const uint EXT_API_VERSION_NUMBER32 = 5;

        public const uint EXT_API_VERSION_NUMBER64 = 6;

        public const uint IG_KD_CONTEXT = 1;

        public const uint IG_READ_CONTROL_SPACE = 2;

        public const uint IG_WRITE_CONTROL_SPACE = 3;

        public const uint IG_READ_IO_SPACE = 4;

        public const uint IG_WRITE_IO_SPACE = 5;

        public const uint IG_READ_PHYSICAL = 6;

        public const uint IG_WRITE_PHYSICAL = 7;

        public const uint IG_READ_IO_SPACE_EX = 8;

        public const uint IG_WRITE_IO_SPACE_EX = 9;

        public const uint IG_KSTACK_HELP = 10;

        public const uint IG_SET_THREAD = 11;

        public const uint IG_READ_MSR = 12;

        public const uint IG_WRITE_MSR = 13;

        public const uint IG_GET_DEBUGGER_DATA = 14;

        public const uint IG_GET_KERNEL_VERSION = 15;

        public const uint IG_RELOAD_SYMBOLS = 16;

        public const uint IG_GET_SET_SYMPATH = 17;

        public const uint IG_GET_EXCEPTION_RECORD = 18;

        public const uint IG_IS_PTR64 = 19;

        public const uint IG_GET_BUS_DATA = 20;

        public const uint IG_SET_BUS_DATA = 21;

        public const uint IG_DUMP_SYMBOL_INFO = 22;

        public const uint IG_LOWMEM_CHECK = 23;

        public const uint IG_SEARCH_MEMORY = 24;

        public const uint IG_GET_CURRENT_THREAD = 25;

        public const uint IG_GET_CURRENT_PROCESS = 26;

        public const uint IG_GET_TYPE_SIZE = 27;

        public const uint IG_GET_CURRENT_PROCESS_HANDLE = 28;

        public const uint IG_GET_INPUT_LINE = 29;

        public const uint IG_GET_EXPRESSION_EX = 30;

        public const uint IG_TRANSLATE_VIRTUAL_TO_PHYSICAL = 31;

        public const uint IG_GET_CACHE_SIZE = 32;

        public const uint IG_READ_PHYSICAL_WITH_FLAGS = 33;

        public const uint IG_WRITE_PHYSICAL_WITH_FLAGS = 34;

        public const uint IG_POINTER_SEARCH_PHYSICAL = 35;

        public const uint IG_OBSOLETE_PLACEHOLDER_36 = 36;

        public const uint IG_GET_THREAD_OS_INFO = 37;

        public const uint IG_GET_CLR_DATA_INTERFACE = 38;

        public const uint IG_MATCH_PATTERN_A = 39;

        public const uint IG_FIND_FILE = 40;

        public const uint IG_TYPED_DATA_OBSOLETE = 41;

        public const uint IG_QUERY_TARGET_INTERFACE = 42;

        public const uint IG_TYPED_DATA = 43;

        public const uint IG_DISASSEMBLE_BUFFER = 44;

        public const uint IG_GET_ANY_MODULE_IN_RANGE = 45;

        public const uint IG_VIRTUAL_TO_PHYSICAL = 46;

        public const uint IG_PHYSICAL_TO_VIRTUAL = 47;

        public const uint IG_GET_CONTEXT_EX = 48;

        public const uint IG_GET_TEB_ADDRESS = 128;

        public const uint IG_GET_PEB_ADDRESS = 129;

        public const uint PHYS_FLAG_DEFAULT = 0;

        public const uint PHYS_FLAG_CACHED = 1;

        public const uint PHYS_FLAG_UNCACHED = 2;

        public const uint PHYS_FLAG_WRITE_COMBINED = 3;

        public const uint PTR_SEARCH_PHYS_ALL_HITS = 0x00000001;

        public const uint PTR_SEARCH_PHYS_PTE = 0x00000002;

        public const uint PTR_SEARCH_PHYS_RANGE_CHECK_ONLY = 0x00000004;

        public const uint PTR_SEARCH_PHYS_SIZE_SHIFT = 3;

        public const uint PTR_SEARCH_NO_SYMBOL_CHECK = 0x80000000;

        public const uint EXT_FIND_FILE_ALLOW_GIVEN_PATH = 0x00000001;

        public const uint DEBUG_TYPED_DATA_IS_IN_MEMORY = 0x00000001;

        public const uint DEBUG_TYPED_DATA_PHYSICAL_DEFAULT = 0x00000002;

        public const uint DEBUG_TYPED_DATA_PHYSICAL_CACHED = 0x00000004;

        public const uint DEBUG_TYPED_DATA_PHYSICAL_UNCACHED = 0x00000006;

        public const uint DEBUG_TYPED_DATA_PHYSICAL_WRITE_COMBINED = 0x00000008;

        public const uint DEBUG_TYPED_DATA_PHYSICAL_MEMORY = 0x0000000e;

        public const uint EXT_TDF_PHYSICAL_DEFAULT = 0x00000002;

        public const uint EXT_TDF_PHYSICAL_CACHED = 0x00000004;

        public const uint EXT_TDF_PHYSICAL_UNCACHED = 0x00000006;

        public const uint EXT_TDF_PHYSICAL_WRITE_COMBINED = 0x00000008;

        public const uint EXT_TDF_PHYSICAL_MEMORY = 0x0000000e;

        public const uint WDBGEXTS_ADDRESS_DEFAULT = 0x00000000;

        public const uint WDBGEXTS_ADDRESS_SEG16 = 0x00000001;

        public const uint WDBGEXTS_ADDRESS_SEG32 = 0x00000002;

        public const uint WDBGEXTS_ADDRESS_RESERVED0 = 0x80000000;

        public const uint DBGKD_VERS_FLAG_MP = 0x0001;

        public const uint DBGKD_VERS_FLAG_DATA = 0x0002;

        public const uint DBGKD_VERS_FLAG_PTR64 = 0x0004;

        public const uint DBGKD_VERS_FLAG_NOMM = 0x0008;

        public const uint DBGKD_VERS_FLAG_HSS = 0x0010;

        public const uint DBGKD_VERS_FLAG_PARTITIONS = 0x0020;

        public const uint DBGKD_VERS_FLAG_HAL_IN_NTOS = 0x0040;

        public const uint KD_SECONDARY_VERSION_DEFAULT = 0;

        public const uint KD_SECONDARY_VERSION_AMD64_OBSOLETE_CONTEXT_1 = 0;

        public const uint KD_SECONDARY_VERSION_AMD64_OBSOLETE_CONTEXT_2 = 1;

        public const uint KD_SECONDARY_VERSION_AMD64_CONTEXT = 2;

        public const uint DBG_DUMP_NO_INDENT = 0x00000001;

        public const uint DBG_DUMP_NO_OFFSET = 0x00000002;

        public const uint DBG_DUMP_VERBOSE = 0x00000004;

        public const uint DBG_DUMP_CALL_FOR_EACH = 0x00000008;

        public const uint DBG_DUMP_LIST = 0x00000020;

        public const uint DBG_DUMP_NO_PRINT = 0x00000040;

        public const uint DBG_DUMP_GET_SIZE_ONLY = 0x00000080;

        public const uint DBG_DUMP_COMPACT_OUT = 0x00002000;

        public const uint DBG_DUMP_ARRAY = 0x00008000;

        public const uint DBG_DUMP_ADDRESS_OF_FIELD = 0x00010000;

        public const uint DBG_DUMP_ADDRESS_AT_END = 0x00020000;

        public const uint DBG_DUMP_COPY_TYPE_DATA = 0x00040000;

        public const uint DBG_DUMP_READ_PHYSICAL = 0x00080000;

        public const uint DBG_DUMP_FUNCTION_FORMAT = 0x00100000;

        public const uint DBG_DUMP_BLOCK_RECURSE = 0x00200000;

        public const uint DBG_DUMP_MATCH_SIZE = 0x00400000;

        public const uint DBG_RETURN_TYPE = 0;

        public const uint DBG_RETURN_SUBTYPES = 0;

        public const uint DBG_RETURN_TYPE_VALUES = 0;

        public const uint DBG_DUMP_FIELD_CALL_BEFORE_PRINT = 0x00000001;

        public const uint DBG_DUMP_FIELD_NO_CALLBACK_REQ = 0x00000002;

        public const uint DBG_DUMP_FIELD_RECUR_ON_THIS = 0x00000004;

        public const uint DBG_DUMP_FIELD_FULL_NAME = 0x00000008;

        public const uint DBG_DUMP_FIELD_ARRAY = 0x00000010;

        public const uint DBG_DUMP_FIELD_COPY_FIELD_DATA = 0x00000020;

        public const uint DBG_DUMP_FIELD_RETURN_ADDRESS = 0x00001000;

        public const uint DBG_DUMP_FIELD_SIZE_IN_BITS = 0x00002000;

        public const uint DBG_DUMP_FIELD_NO_PRINT = 0x00004000;

        public const uint DBG_DUMP_FIELD_DEFAULT_STRING = 0x00010000;

        public const uint DBG_DUMP_FIELD_WCHAR_STRING = 0x00020000;

        public const uint DBG_DUMP_FIELD_MULTI_STRING = 0x00040000;

        public const uint DBG_DUMP_FIELD_GUID_STRING = 0x00080000;

        public const uint DBG_DUMP_FIELD_UTF32_STRING = 0x00100000;

        public const uint MEMORY_READ_ERROR = 0x01;

        public const uint SYMBOL_TYPE_INDEX_NOT_FOUND = 0x02;

        public const uint SYMBOL_TYPE_INFO_NOT_FOUND = 0x03;

        public const uint FIELDS_DID_NOT_MATCH = 0x04;

        public const uint NULL_SYM_DUMP_PARAM = 0x05;

        public const uint NULL_FIELD_NAME = 0x06;

        public const uint INCORRECT_VERSION_INFO = 0x07;

        public const uint EXIT_ON_CONTROLC = 0x08;

        public const uint CANNOT_ALLOCATE_MEMORY = 0x09;

        public const uint INSUFFICIENT_SPACE_TO_COPY = 0x0a;

        public const uint ADDRESS_TYPE_INDEX_NOT_FOUND = 0x0b;

        public const uint UNAVAILABLE_ERROR = 0x0c;

        public static readonly Guid CATID_ActiveScript__scanned__ = new Guid(0xf0b7a1a1, 0x9847, 0x11cf, 0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

        public static readonly Guid CATID_ActiveScriptParse__scanned__ = new Guid(0xf0b7a1a2, 0x9847, 0x11cf, 0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

        public static readonly Guid CATID_ActiveScriptEncode__scanned__ = new Guid(0xf0b7a1a3, 0x9847, 0x11cf, 0x8f, 0x20, 0x00, 0x80, 0x5f, 0x2c, 0xd0, 0x64);

        public static readonly Guid OID_VBSSIP__scanned__ = new Guid(0x1629f04e, 0x2799, 0x4db5, 0x8f, 0xe5, 0xac, 0xe1, 0x0f, 0x17, 0xeb, 0xab);

        public static readonly Guid OID_JSSIP__scanned__ = new Guid(0x6c9e010, 0x38ce, 0x11d4, 0xa2, 0xa3, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90);

        public static readonly Guid OID_WSFSIP__scanned__ = new Guid(0x1a610570, 0x38ce, 0x11d4, 0xa2, 0xa3, 0x00, 0x10, 0x4b, 0xd3, 0x50, 0x90);

        public const uint SCRIPTITEM_ISVISIBLE = 0x00000002;

        public const uint SCRIPTITEM_ISSOURCE = 0x00000004;

        public const uint SCRIPTITEM_GLOBALMEMBERS = 0x00000008;

        public const uint SCRIPTITEM_ISPERSISTENT = 0x00000040;

        public const uint SCRIPTITEM_CODEONLY = 0x00000200;

        public const uint SCRIPTITEM_NOCODE = 0x00000400;

        public const uint SCRIPTTYPELIB_ISCONTROL = 0x00000010;

        public const uint SCRIPTTYPELIB_ISPERSISTENT = 0x00000040;

        public const uint SCRIPTTEXT_DELAYEXECUTION = 0x00000001;

        public const uint SCRIPTTEXT_ISVISIBLE = 0x00000002;

        public const uint SCRIPTTEXT_ISEXPRESSION = 0x00000020;

        public const uint SCRIPTTEXT_ISPERSISTENT = 0x00000040;

        public const uint SCRIPTTEXT_HOSTMANAGESSOURCE = 0x00000080;

        public const uint SCRIPTTEXT_ISXDOMAIN = 0x00000100;

        public const uint SCRIPTTEXT_ISNONUSERCODE = 0x00000200;

        public const uint SCRIPTPROC_ISEXPRESSION = 0x00000020;

        public const uint SCRIPTPROC_HOSTMANAGESSOURCE = 0x00000080;

        public const uint SCRIPTPROC_IMPLICIT_THIS = 0x00000100;

        public const uint SCRIPTPROC_IMPLICIT_PARENTS = 0x00000200;

        public const uint SCRIPTPROC_ISXDOMAIN = 0x00000400;

        public const uint SCRIPTINFO_IUNKNOWN = 0x00000001;

        public const uint SCRIPTINFO_ITYPEINFO = 0x00000002;

        public const uint SCRIPTINTERRUPT_DEBUG = 0x00000001;

        public const uint SCRIPTINTERRUPT_RAISEEXCEPTION = 0x00000002;

        public const uint SCRIPTSTAT_STATEMENT_COUNT = 1;

        public const uint SCRIPTSTAT_INSTRUCTION_COUNT = 2;

        public const uint SCRIPTSTAT_INTSTRUCTION_TIME = 3;

        public const uint SCRIPTSTAT_TOTAL_TIME = 4;

        public const uint SCRIPT_ENCODE_SECTION = 0x00000001;

        public const uint SCRIPT_ENCODE_DEFAULT_LANGUAGE = 0x00000001;

        public const uint SCRIPT_ENCODE_NO_ASP_LANGUAGE = 0x00000002;

        public const uint SCRIPTPROP_NAME = 0x00000000;

        public const uint SCRIPTPROP_MAJORVERSION = 0x00000001;

        public const uint SCRIPTPROP_MINORVERSION = 0x00000002;

        public const uint SCRIPTPROP_BUILDNUMBER = 0x00000003;

        public const uint SCRIPTPROP_DELAYEDEVENTSINKING = 0x00001000;

        public const uint SCRIPTPROP_CATCHEXCEPTION = 0x00001001;

        public const uint SCRIPTPROP_CONVERSIONLCID = 0x00001002;

        public const uint SCRIPTPROP_HOSTSTACKREQUIRED = 0x00001003;

        public const uint SCRIPTPROP_SCRIPTSAREFULLYTRUSTED = 0x00001004;

        public const uint SCRIPTPROP_DEBUGGER = 0x00001100;

        public const uint SCRIPTPROP_JITDEBUG = 0x00001101;

        public const uint SCRIPTPROP_GCCONTROLSOFTCLOSE = 0x00002000;

        public const uint SCRIPTPROP_INTEGERMODE = 0x00003000;

        public const uint SCRIPTPROP_STRINGCOMPAREINSTANCE = 0x00003001;

        public const uint SCRIPTPROP_INVOKEVERSIONING = 0x00004000;

        public const uint SCRIPTPROP_HACK_FIBERSUPPORT = 0x70000000;

        public const uint SCRIPTPROP_HACK_TRIDENTEVENTSINK = 0x70000001;

        public const uint SCRIPTPROP_ABBREVIATE_GLOBALNAME_RESOLUTION = 0x70000002;

        public const uint SCRIPTPROP_HOSTKEEPALIVE = 0x70000004;

        public const int SCRIPT_E_RECORDED = unchecked((int)0x86664004);

        public const int SCRIPT_E_REPORTED = unchecked((int)0x80020101);

        public const int SCRIPT_E_PROPAGATE = unchecked((int)0x80020102);

        public const uint MINIDUMP_VERSION = 42899;

        public const uint MINIDUMP_MISC1_PROCESSOR_POWER_INFO = 0x00000004;

        public const uint MINIDUMP_MISC3_PROCESS_INTEGRITY = 0x00000010;

        public const uint MINIDUMP_MISC3_PROCESS_EXECUTE_FLAGS = 0x00000020;

        public const uint MINIDUMP_MISC3_TIMEZONE = 0x00000040;

        public const uint MINIDUMP_MISC3_PROTECTED_PROCESS = 0x00000080;

        public const uint MINIDUMP_MISC4_BUILDSTRING = 0x00000100;

        public const uint MINIDUMP_MISC5_PROCESS_COOKIE = 0x00000200;

        public const uint MINIDUMP_SYSMEMINFO1_FILECACHE_TRANSITIONREPURPOSECOUNT_FLAGS = 0x0001;

        public const uint MINIDUMP_SYSMEMINFO1_BASICPERF = 0x0002;

        public const uint MINIDUMP_SYSMEMINFO1_PERF_CCTOTALDIRTYPAGES_CCDIRTYPAGETHRESHOLD = 0x0004;

        public const uint MINIDUMP_SYSMEMINFO1_PERF_RESIDENTAVAILABLEPAGES_SHAREDCOMMITPAGES = 0x0008;

        public const uint MINIDUMP_PROCESS_VM_COUNTERS = 0x0001;

        public const uint MINIDUMP_PROCESS_VM_COUNTERS_VIRTUALSIZE = 0x0002;

        public const uint MINIDUMP_PROCESS_VM_COUNTERS_EX = 0x0004;

        public const uint MINIDUMP_PROCESS_VM_COUNTERS_EX2 = 0x0008;

        public const uint MINIDUMP_PROCESS_VM_COUNTERS_JOB = 0x0010;

        public const uint MAX_SYM_NAME = 2000;

        public const uint ERROR_IMAGE_NOT_STRIPPED = 0x8800;

        public const uint ERROR_NO_DBG_POINTER = 0x8801;

        public const uint ERROR_NO_PDB_POINTER = 0x8802;

        public const uint UNDNAME_COMPLETE = 0x0000;

        public const uint UNDNAME_NO_LEADING_UNDERSCORES = 0x0001;

        public const uint UNDNAME_NO_MS_KEYWORDS = 0x0002;

        public const uint UNDNAME_NO_FUNCTION_RETURNS = 0x0004;

        public const uint UNDNAME_NO_ALLOCATION_MODEL = 0x0008;

        public const uint UNDNAME_NO_ALLOCATION_LANGUAGE = 0x0010;

        public const uint UNDNAME_NO_MS_THISTYPE = 0x0020;

        public const uint UNDNAME_NO_CV_THISTYPE = 0x0040;

        public const uint UNDNAME_NO_THISTYPE = 0x0060;

        public const uint UNDNAME_NO_ACCESS_SPECIFIERS = 0x0080;

        public const uint UNDNAME_NO_THROW_SIGNATURES = 0x0100;

        public const uint UNDNAME_NO_MEMBER_TYPE = 0x0200;

        public const uint UNDNAME_NO_RETURN_UDT_MODEL = 0x0400;

        public const uint UNDNAME_32_BIT_DECODE = 0x0800;

        public const uint UNDNAME_NAME_ONLY = 0x1000;

        public const uint UNDNAME_NO_ARGUMENTS = 0x2000;

        public const uint UNDNAME_NO_SPECIAL_SYMS = 0x4000;

        public const uint DBHHEADER_PDBGUID = 0x3;

        public const uint INLINE_FRAME_CONTEXT_INIT = 0;

        public const uint INLINE_FRAME_CONTEXT_IGNORE = 0xFFFFFFFF;

        public const uint SYM_STKWALK_DEFAULT = 0x00000000;

        public const uint SYM_STKWALK_FORCE_FRAMEPTR = 0x00000001;

        public const uint API_VERSION_NUMBER = 12;

        public const uint SYMFLAG_NULL = 0x00080000;

        public const uint SYMFLAG_FUNC_NO_RETURN = 0x00100000;

        public const uint SYMFLAG_SYNTHETIC_ZEROBASE = 0x00200000;

        public const uint SYMFLAG_PUBLIC_CODE = 0x00400000;

        public const uint SYMFLAG_REGREL_ALIASINDIR = 0x00800000;

        public const uint SYMFLAG_RESET = 0x80000000;

        public const uint CBA_DEFERRED_SYMBOL_LOAD_START = 0x00000001;

        public const uint CBA_DEFERRED_SYMBOL_LOAD_COMPLETE = 0x00000002;

        public const uint CBA_DEFERRED_SYMBOL_LOAD_FAILURE = 0x00000003;

        public const uint CBA_SYMBOLS_UNLOADED = 0x00000004;

        public const uint CBA_DUPLICATE_SYMBOL = 0x00000005;

        public const uint CBA_READ_MEMORY = 0x00000006;

        public const uint CBA_DEFERRED_SYMBOL_LOAD_CANCEL = 0x00000007;

        public const uint CBA_SET_OPTIONS = 0x00000008;

        public const uint CBA_EVENT = 0x00000010;

        public const uint CBA_DEFERRED_SYMBOL_LOAD_PARTIAL = 0x00000020;

        public const uint CBA_DEBUG_INFO = 0x10000000;

        public const uint CBA_SRCSRV_INFO = 0x20000000;

        public const uint CBA_SRCSRV_EVENT = 0x40000000;

        public const uint CBA_UPDATE_STATUS_BAR = 0x50000000;

        public const uint CBA_ENGINE_PRESENT = 0x60000000;

        public const uint CBA_CHECK_ENGOPT_DISALLOW_NETWORK_PATHS = 0x70000000;

        public const uint CBA_CHECK_ARM_MACHINE_THUMB_TYPE_OVERRIDE = 0x80000000;

        public const uint CBA_XML_LOG = 0x90000000;

        public const uint EVENT_SRCSPEW_START = 100;

        public const uint EVENT_SRCSPEW = 100;

        public const uint EVENT_SRCSPEW_END = 199;

        public const uint DSLFLAG_MISMATCHED_PDB = 0x1;

        public const uint DSLFLAG_MISMATCHED_DBG = 0x2;

        public const uint FLAG_ENGINE_PRESENT = 0x4;

        public const uint FLAG_ENGOPT_DISALLOW_NETWORK_PATHS = 0x8;

        public const uint FLAG_OVERRIDE_ARM_MACHINE_TYPE = 0x10;

        public const uint SYM_INLINE_COMP_ERROR = 0;

        public const uint SYM_INLINE_COMP_IDENTICAL = 1;

        public const uint SYM_INLINE_COMP_STEPIN = 2;

        public const uint SYM_INLINE_COMP_STEPOUT = 3;

        public const uint SYM_INLINE_COMP_STEPOVER = 4;

        public const uint SYM_INLINE_COMP_DIFFERENT = 5;

        public const uint ESLFLAG_FULLPATH = 0x00000001;

        public const uint ESLFLAG_NEAREST = 0x00000002;

        public const uint ESLFLAG_PREV = 0x00000004;

        public const uint ESLFLAG_NEXT = 0x00000008;

        public const uint ESLFLAG_INLINE_SITE = 0x00000010;

        public const uint SYMENUM_OPTIONS_DEFAULT = 0x00000001;

        public const uint SYMENUM_OPTIONS_INLINE = 0x00000002;

        public const uint SYMSEARCH_MASKOBJS = 0x01;

        public const uint SYMSEARCH_RECURSE = 0X02;

        public const uint SYMSEARCH_GLOBALSONLY = 0X04;

        public const uint SYMSEARCH_ALLITEMS = 0X08;

        public const uint EXT_OUTPUT_VER = 1;

        public const uint SYMSRV_VERSION = 2;

        public const uint SSRVOPT_CALLBACK = 0x00000001;

        public const uint SSRVOPT_OLDGUIDPTR = 0x00000010;

        public const uint SSRVOPT_UNATTENDED = 0x00000020;

        public const uint SSRVOPT_NOCOPY = 0x00000040;

        public const uint SSRVOPT_GETPATH = 0x00000040;

        public const uint SSRVOPT_PARENTWIN = 0x00000080;

        public const uint SSRVOPT_PARAMTYPE = 0x00000100;

        public const uint SSRVOPT_SECURE = 0x00000200;

        public const uint SSRVOPT_TRACE = 0x00000400;

        public const uint SSRVOPT_SETCONTEXT = 0x00000800;

        public const uint SSRVOPT_PROXY = 0x00001000;

        public const uint SSRVOPT_DOWNSTREAM_STORE = 0x00002000;

        public const uint SSRVOPT_OVERWRITE = 0x00004000;

        public const uint SSRVOPT_RESETTOU = 0x00008000;

        public const uint SSRVOPT_CALLBACKW = 0x00010000;

        public const uint SSRVOPT_FLAT_DEFAULT_STORE = 0x00020000;

        public const uint SSRVOPT_PROXYW = 0x00040000;

        public const uint SSRVOPT_MESSAGE = 0x00080000;

        public const uint SSRVOPT_SERVICE = 0x00100000;

        public const uint SSRVOPT_FAVOR_COMPRESSED = 0x00200000;

        public const uint SSRVOPT_STRING = 0x00400000;

        public const uint SSRVOPT_WINHTTP = 0x00800000;

        public const uint SSRVOPT_WININET = 0x01000000;

        public const uint SSRVOPT_DONT_UNCOMPRESS = 0x02000000;

        public const uint SSRVOPT_DISABLE_PING_HOST = 0x04000000;

        public const uint SSRVOPT_DISABLE_TIMEOUT = 0x08000000;

        public const uint SSRVOPT_ENABLE_COMM_MSG = 0x10000000;

        public const uint SSRVOPT_URI_FILTER = 0x20000000;

        public const uint SSRVOPT_URI_TIERS = 0x40000000;

        public const uint SSRVOPT_RETRY_APP_HANG = 0x80000000;

        public const uint SSRVOPT_MAX = 0x80000000;

        public const uint NUM_SSRVOPTS = 32;

        public const uint SSRVURI_HTTP_NORMAL = 0x01;

        public const uint SSRVURI_HTTP_COMPRESSED = 0x02;

        public const uint SSRVURI_HTTP_FILEPTR = 0x04;

        public const uint SSRVURI_UNC_NORMAL = 0x10;

        public const uint SSRVURI_UNC_COMPRESSED = 0x20;

        public const uint SSRVURI_UNC_FILEPTR = 0x40;

        public const uint SSRVURI_HTTP_MASK = 0x0F;

        public const uint SSRVURI_UNC_MASK = 0xF0;

        public const uint SSRVURI_ALL = 0xFF;

        public const uint SSRVACTION_TRACE = 1;

        public const uint SSRVACTION_QUERYCANCEL = 2;

        public const uint SSRVACTION_EVENT = 3;

        public const uint SSRVACTION_EVENTW = 4;

        public const uint SSRVACTION_SIZE = 5;

        public const uint SSRVACTION_HTTPSTATUS = 6;

        public const uint SSRVACTION_XMLOUTPUT = 7;

        public const uint SSRVACTION_CHECKSUMSTATUS = 8;

        public const uint SYMF_OMAP_GENERATED = 0x00000001;

        public const uint SYMF_OMAP_MODIFIED = 0x00000002;

        public const uint SYMF_REGISTER = 0x00000008;

        public const uint SYMF_REGREL = 0x00000010;

        public const uint SYMF_FRAMEREL = 0x00000020;

        public const uint SYMF_PARAMETER = 0x00000040;

        public const uint SYMF_LOCAL = 0x00000080;

        public const uint SYMF_CONSTANT = 0x00000100;

        public const uint SYMF_EXPORT = 0x00000200;

        public const uint SYMF_FORWARDER = 0x00000400;

        public const uint SYMF_FUNCTION = 0x00000800;

        public const uint SYMF_VIRTUAL = 0x00001000;

        public const uint SYMF_THUNK = 0x00002000;

        public const uint SYMF_TLSREL = 0x00004000;

        public const uint IMAGEHLP_SYMBOL_INFO_VALUEPRESENT = 1;

        public const uint IMAGEHLP_RMAP_MAPPED_FLAT = 0x00000001;

        public const uint IMAGEHLP_RMAP_BIG_ENDIAN = 0x00000002;

        public const uint IMAGEHLP_RMAP_IGNORE_MISCOMPARE = 0x00000004;

        public const uint IMAGEHLP_RMAP_LOAD_RW_DATA_SECTIONS = 0x20000000;

        public const uint IMAGEHLP_RMAP_OMIT_SHARED_RW_DATA_SECTIONS = 0x40000000;

        public const uint IMAGEHLP_RMAP_FIXUP_IMAGEBASE = 0x80000000;

        public const uint WCT_MAX_NODE_COUNT = 16;

        public const uint WCT_OBJNAME_LENGTH = 128;

        public const uint WCT_NETWORK_IO_FLAG = 0x8;

        public const uint APPBREAKFLAG_DEBUGGER_BLOCK = 0x1;

        public const uint APPBREAKFLAG_DEBUGGER_HALT = 0x2;

        public const uint APPBREAKFLAG_STEP = 0x10000;

        public const uint APPBREAKFLAG_NESTED = 0x20000;

        public const uint APPBREAKFLAG_STEPTYPE_SOURCE = 0;

        public const uint APPBREAKFLAG_STEPTYPE_BYTECODE = 0x100000;

        public const uint APPBREAKFLAG_STEPTYPE_MACHINE = 0x200000;

        public const uint APPBREAKFLAG_STEPTYPE_MASK = 0xf00000;

        public const uint APPBREAKFLAG_IN_BREAKPOINT = 0x80000000;

        public const uint SOURCETEXT_ATTR_KEYWORD = 0x1;

        public const uint SOURCETEXT_ATTR_COMMENT = 0x2;

        public const uint SOURCETEXT_ATTR_NONSOURCE = 0x4;

        public const uint SOURCETEXT_ATTR_OPERATOR = 0x8;

        public const uint SOURCETEXT_ATTR_NUMBER = 0x10;

        public const uint SOURCETEXT_ATTR_STRING = 0x20;

        public const uint SOURCETEXT_ATTR_FUNCTION_START = 0x40;

        public const uint TEXT_DOC_ATTR_READONLY = 0x1;

        public const uint TEXT_DOC_ATTR_TYPE_PRIMARY = 0x2;

        public const uint TEXT_DOC_ATTR_TYPE_WORKER = 0x4;

        public const uint TEXT_DOC_ATTR_TYPE_SCRIPT = 0x8;

        public const uint DEBUG_TEXT_ISEXPRESSION = 0x1;

        public const uint DEBUG_TEXT_RETURNVALUE = 0x2;

        public const uint DEBUG_TEXT_NOSIDEEFFECTS = 0x4;

        public const uint DEBUG_TEXT_ALLOWBREAKPOINTS = 0x8;

        public const uint DEBUG_TEXT_ALLOWERRORREPORT = 0x10;

        public const uint DEBUG_TEXT_EVALUATETOCODECONTEXT = 0x20;

        public const uint DEBUG_TEXT_ISNONUSERCODE = 0x40;

        public const uint THREAD_STATE_RUNNING = 0x1;

        public const uint THREAD_STATE_SUSPENDED = 0x2;

        public const uint THREAD_BLOCKED = 0x4;

        public const uint THREAD_OUT_OF_CONTEXT = 0x8;

    }
}
