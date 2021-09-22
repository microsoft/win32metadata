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


namespace Windows.Win32.System.Diagnostics.Etw
{
    public static partial class Apis
    {
        public const uint WNODE_FLAG_ALL_DATA = 0x00000001;

        public const uint WNODE_FLAG_SINGLE_INSTANCE = 0x00000002;

        public const uint WNODE_FLAG_SINGLE_ITEM = 0x00000004;

        public const uint WNODE_FLAG_EVENT_ITEM = 0x00000008;

        public const uint WNODE_FLAG_FIXED_INSTANCE_SIZE = 0x00000010;

        public const uint WNODE_FLAG_TOO_SMALL = 0x00000020;

        public const uint WNODE_FLAG_INSTANCES_SAME = 0x00000040;

        public const uint WNODE_FLAG_STATIC_INSTANCE_NAMES = 0x00000080;

        public const uint WNODE_FLAG_INTERNAL = 0x00000100;

        public const uint WNODE_FLAG_USE_TIMESTAMP = 0x00000200;

        public const uint WNODE_FLAG_PERSIST_EVENT = 0x00000400;

        public const uint WNODE_FLAG_EVENT_REFERENCE = 0x00002000;

        public const uint WNODE_FLAG_ANSI_INSTANCENAMES = 0x00004000;

        public const uint WNODE_FLAG_METHOD_ITEM = 0x00008000;

        public const uint WNODE_FLAG_PDO_INSTANCE_NAMES = 0x00010000;

        public const uint WNODE_FLAG_TRACED_GUID = 0x00020000;

        public const uint WNODE_FLAG_LOG_WNODE = 0x00040000;

        public const uint WNODE_FLAG_USE_GUID_PTR = 0x00080000;

        public const uint WNODE_FLAG_USE_MOF_PTR = 0x00100000;

        public const uint WNODE_FLAG_NO_HEADER = 0x00200000;

        public const uint WNODE_FLAG_SEND_DATA_BLOCK = 0x00400000;

        public const uint WNODE_FLAG_VERSIONED_PROPERTIES = 0x00800000;

        public const uint WNODE_FLAG_SEVERITY_MASK = 0xff000000;

        public const uint WMIREG_FLAG_EXPENSIVE = 0x00000001;

        public const uint WMIREG_FLAG_INSTANCE_LIST = 0x00000004;

        public const uint WMIREG_FLAG_INSTANCE_BASENAME = 0x00000008;

        public const uint WMIREG_FLAG_INSTANCE_PDO = 0x00000020;

        public const uint WMIREG_FLAG_REMOVE_GUID = 0x00010000;

        public const uint WMIREG_FLAG_RESERVED1 = 0x00020000;

        public const uint WMIREG_FLAG_RESERVED2 = 0x00040000;

        public const uint WMIREG_FLAG_TRACED_GUID = 0x00080000;

        public const uint WMIREG_FLAG_TRACE_CONTROL_GUID = 0x00001000;

        public const uint WMIREG_FLAG_EVENT_ONLY_GUID = 0x00000040;

        public const uint WMI_GUIDTYPE_TRACECONTROL = 0;

        public const uint WMI_GUIDTYPE_TRACE = 1;

        public const uint WMI_GUIDTYPE_DATA = 2;

        public const uint WMI_GUIDTYPE_EVENT = 3;

        public const uint WMIGUID_QUERY = 0x0001;

        public const uint WMIGUID_SET = 0x0002;

        public const uint WMIGUID_NOTIFICATION = 0x0004;

        public const uint WMIGUID_READ_DESCRIPTION = 0x0008;

        public const uint WMIGUID_EXECUTE = 0x0010;

        public const uint TRACELOG_CREATE_REALTIME = 0x0020;

        public const uint TRACELOG_CREATE_ONDISK = 0x0040;

        public const uint TRACELOG_GUID_ENABLE = 0x0080;

        public const uint TRACELOG_ACCESS_KERNEL_LOGGER = 0x0100;

        public const uint TRACELOG_LOG_EVENT = 0x0200;

        public const uint TRACELOG_CREATE_INPROC = 0x0200;

        public const uint TRACELOG_ACCESS_REALTIME = 0x0400;

        public const uint TRACELOG_REGISTER_GUIDS = 0x0800;

        public const uint TRACELOG_JOIN_GROUP = 0x1000;

        public const uint WMI_GLOBAL_LOGGER_ID = 0x0001;

        public const uint MAX_PAYLOAD_PREDICATES = 8;

        public static readonly Guid EventTraceGuid__scanned__ = new Guid(0x68fdd900,    0x4a3e,    0x11d1,    0x84, 0xf4, 0x00, 0x00, 0xf8, 0x04, 0x64, 0xe3  );

        public static readonly Guid SystemTraceControlGuid__scanned__ = new Guid(0x9e814aad,    0x3204,    0x11d2,    0x9a, 0x82, 0x00, 0x60, 0x08, 0xa8, 0x69, 0x39  );

        public static readonly Guid EventTraceConfigGuid__scanned__ = new Guid(0x01853a65,    0x418f,    0x4f36,    0xae, 0xfc, 0xdc, 0x0f, 0x1d, 0x2f, 0xd2, 0x35  );

        public static readonly Guid DefaultTraceSecurityGuid__scanned__ = new Guid(0x0811c1af,    0x7a07,    0x4a06,    0x82, 0xed, 0x86, 0x94, 0x55, 0xcd, 0xf7, 0x13  );

        public static readonly Guid PrivateLoggerNotificationGuid__scanned__ = new Guid(0x3595ab5c,    0x042a,    0x4c8e,    0xb9, 0x42, 0x2d, 0x05, 0x9b, 0xfe, 0xb1, 0xb1  );

        public const uint MAX_MOF_FIELDS = 16;

        public const uint SYSTEM_EVENT_TYPE = 1;

        public const uint EVENT_TRACE_TYPE_INFO = 0x00;

        public const uint EVENT_TRACE_TYPE_START = 0x01;

        public const uint EVENT_TRACE_TYPE_END = 0x02;

        public const uint EVENT_TRACE_TYPE_STOP = 0x02;

        public const uint EVENT_TRACE_TYPE_DC_START = 0x03;

        public const uint EVENT_TRACE_TYPE_DC_END = 0x04;

        public const uint EVENT_TRACE_TYPE_EXTENSION = 0x05;

        public const uint EVENT_TRACE_TYPE_REPLY = 0x06;

        public const uint EVENT_TRACE_TYPE_DEQUEUE = 0x07;

        public const uint EVENT_TRACE_TYPE_RESUME = 0x07;

        public const uint EVENT_TRACE_TYPE_CHECKPOINT = 0x08;

        public const uint EVENT_TRACE_TYPE_SUSPEND = 0x08;

        public const uint EVENT_TRACE_TYPE_WINEVT_SEND = 0x09;

        public const uint EVENT_TRACE_TYPE_WINEVT_RECEIVE = 0XF0;

        public const uint TRACE_LEVEL_NONE = 0;

        public const uint TRACE_LEVEL_CRITICAL = 1;

        public const uint TRACE_LEVEL_FATAL = 1;

        public const uint TRACE_LEVEL_ERROR = 2;

        public const uint TRACE_LEVEL_WARNING = 3;

        public const uint TRACE_LEVEL_INFORMATION = 4;

        public const uint TRACE_LEVEL_VERBOSE = 5;

        public const uint TRACE_LEVEL_RESERVED6 = 6;

        public const uint TRACE_LEVEL_RESERVED7 = 7;

        public const uint TRACE_LEVEL_RESERVED8 = 8;

        public const uint TRACE_LEVEL_RESERVED9 = 9;

        public const uint EVENT_TRACE_TYPE_LOAD = 0x0A;

        public const uint EVENT_TRACE_TYPE_TERMINATE = 0x0B;

        public const uint EVENT_TRACE_TYPE_IO_READ = 0x0A;

        public const uint EVENT_TRACE_TYPE_IO_WRITE = 0x0B;

        public const uint EVENT_TRACE_TYPE_IO_READ_INIT = 0x0C;

        public const uint EVENT_TRACE_TYPE_IO_WRITE_INIT = 0x0D;

        public const uint EVENT_TRACE_TYPE_IO_FLUSH = 0x0E;

        public const uint EVENT_TRACE_TYPE_IO_FLUSH_INIT = 0x0F;

        public const uint EVENT_TRACE_TYPE_IO_REDIRECTED_INIT = 0x10;

        public const uint EVENT_TRACE_TYPE_MM_TF = 0x0A;

        public const uint EVENT_TRACE_TYPE_MM_DZF = 0x0B;

        public const uint EVENT_TRACE_TYPE_MM_COW = 0x0C;

        public const uint EVENT_TRACE_TYPE_MM_GPF = 0x0D;

        public const uint EVENT_TRACE_TYPE_MM_HPF = 0x0E;

        public const uint EVENT_TRACE_TYPE_MM_AV = 0x0F;

        public const uint EVENT_TRACE_TYPE_SEND = 0x0A;

        public const uint EVENT_TRACE_TYPE_RECEIVE = 0x0B;

        public const uint EVENT_TRACE_TYPE_CONNECT = 0x0C;

        public const uint EVENT_TRACE_TYPE_DISCONNECT = 0x0D;

        public const uint EVENT_TRACE_TYPE_RETRANSMIT = 0x0E;

        public const uint EVENT_TRACE_TYPE_ACCEPT = 0x0F;

        public const uint EVENT_TRACE_TYPE_RECONNECT = 0x10;

        public const uint EVENT_TRACE_TYPE_CONNFAIL = 0x11;

        public const uint EVENT_TRACE_TYPE_COPY_TCP = 0x12;

        public const uint EVENT_TRACE_TYPE_COPY_ARP = 0x13;

        public const uint EVENT_TRACE_TYPE_ACKFULL = 0x14;

        public const uint EVENT_TRACE_TYPE_ACKPART = 0x15;

        public const uint EVENT_TRACE_TYPE_ACKDUP = 0x16;

        public const uint EVENT_TRACE_TYPE_GUIDMAP = 0x0A;

        public const uint EVENT_TRACE_TYPE_CONFIG = 0x0B;

        public const uint EVENT_TRACE_TYPE_SIDINFO = 0x0C;

        public const uint EVENT_TRACE_TYPE_SECURITY = 0x0D;

        public const uint EVENT_TRACE_TYPE_DBGID_RSDS = 0x40;

        public const uint EVENT_TRACE_TYPE_REGCREATE = 0x0A;

        public const uint EVENT_TRACE_TYPE_REGOPEN = 0x0B;

        public const uint EVENT_TRACE_TYPE_REGDELETE = 0x0C;

        public const uint EVENT_TRACE_TYPE_REGQUERY = 0x0D;

        public const uint EVENT_TRACE_TYPE_REGSETVALUE = 0x0E;

        public const uint EVENT_TRACE_TYPE_REGDELETEVALUE = 0x0F;

        public const uint EVENT_TRACE_TYPE_REGQUERYVALUE = 0x10;

        public const uint EVENT_TRACE_TYPE_REGENUMERATEKEY = 0x11;

        public const uint EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY = 0x12;

        public const uint EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE = 0x13;

        public const uint EVENT_TRACE_TYPE_REGSETINFORMATION = 0x14;

        public const uint EVENT_TRACE_TYPE_REGFLUSH = 0x15;

        public const uint EVENT_TRACE_TYPE_REGKCBCREATE = 0x16;

        public const uint EVENT_TRACE_TYPE_REGKCBDELETE = 0x17;

        public const uint EVENT_TRACE_TYPE_REGKCBRUNDOWNBEGIN = 0x18;

        public const uint EVENT_TRACE_TYPE_REGKCBRUNDOWNEND = 0x19;

        public const uint EVENT_TRACE_TYPE_REGVIRTUALIZE = 0x1A;

        public const uint EVENT_TRACE_TYPE_REGCLOSE = 0x1B;

        public const uint EVENT_TRACE_TYPE_REGSETSECURITY = 0x1C;

        public const uint EVENT_TRACE_TYPE_REGQUERYSECURITY = 0x1D;

        public const uint EVENT_TRACE_TYPE_REGCOMMIT = 0x1E;

        public const uint EVENT_TRACE_TYPE_REGPREPARE = 0x1F;

        public const uint EVENT_TRACE_TYPE_REGROLLBACK = 0x20;

        public const uint EVENT_TRACE_TYPE_REGMOUNTHIVE = 0x21;

        public const uint EVENT_TRACE_TYPE_CONFIG_CPU = 0x0A;

        public const uint EVENT_TRACE_TYPE_CONFIG_PHYSICALDISK = 0x0B;

        public const uint EVENT_TRACE_TYPE_CONFIG_LOGICALDISK = 0x0C;

        public const uint EVENT_TRACE_TYPE_CONFIG_NIC = 0x0D;

        public const uint EVENT_TRACE_TYPE_CONFIG_VIDEO = 0x0E;

        public const uint EVENT_TRACE_TYPE_CONFIG_SERVICES = 0x0F;

        public const uint EVENT_TRACE_TYPE_CONFIG_POWER = 0x10;

        public const uint EVENT_TRACE_TYPE_CONFIG_NETINFO = 0x11;

        public const uint EVENT_TRACE_TYPE_CONFIG_OPTICALMEDIA = 0x12;

        public const uint EVENT_TRACE_TYPE_CONFIG_IRQ = 0x15;

        public const uint EVENT_TRACE_TYPE_CONFIG_PNP = 0x16;

        public const uint EVENT_TRACE_TYPE_CONFIG_IDECHANNEL = 0x17;

        public const uint EVENT_TRACE_TYPE_CONFIG_NUMANODE = 0x18;

        public const uint EVENT_TRACE_TYPE_CONFIG_PLATFORM = 0x19;

        public const uint EVENT_TRACE_TYPE_CONFIG_PROCESSORGROUP = 0x1A;

        public const uint EVENT_TRACE_TYPE_CONFIG_PROCESSORNUMBER = 0x1B;

        public const uint EVENT_TRACE_TYPE_CONFIG_DPI = 0x1C;

        public const uint EVENT_TRACE_TYPE_CONFIG_CI_INFO = 0x1D;

        public const uint EVENT_TRACE_TYPE_CONFIG_MACHINEID = 0x1E;

        public const uint EVENT_TRACE_TYPE_CONFIG_DEFRAG = 0x1F;

        public const uint EVENT_TRACE_TYPE_CONFIG_MOBILEPLATFORM = 0x20;

        public const uint EVENT_TRACE_TYPE_CONFIG_DEVICEFAMILY = 0x21;

        public const uint EVENT_TRACE_TYPE_CONFIG_FLIGHTID = 0x22;

        public const uint EVENT_TRACE_TYPE_CONFIG_PROCESSOR = 0x23;

        public const uint EVENT_TRACE_TYPE_CONFIG_VIRTUALIZATION = 0x24;

        public const uint EVENT_TRACE_TYPE_CONFIG_BOOT = 0x25;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_READ = 0x37;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_WRITE = 0x38;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH = 0x39;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_READ_INIT = 0x3a;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_WRITE_INIT = 0x3b;

        public const uint EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH_INIT = 0x3c;

        public const uint EVENT_TRACE_TYPE_FLT_PREOP_INIT = 0x60;

        public const uint EVENT_TRACE_TYPE_FLT_POSTOP_INIT = 0x61;

        public const uint EVENT_TRACE_TYPE_FLT_PREOP_COMPLETION = 0x62;

        public const uint EVENT_TRACE_TYPE_FLT_POSTOP_COMPLETION = 0x63;

        public const uint EVENT_TRACE_TYPE_FLT_PREOP_FAILURE = 0x64;

        public const uint EVENT_TRACE_TYPE_FLT_POSTOP_FAILURE = 0x65;

        public const uint EVENT_TRACE_FLAG_DEBUG_EVENTS = 0x00400000;

        public const uint EVENT_TRACE_FLAG_EXTENSION = 0x80000000;

        public const uint EVENT_TRACE_FLAG_FORWARD_WMI = 0x40000000;

        public const uint EVENT_TRACE_FLAG_ENABLE_RESERVE = 0x20000000;

        public const uint EVENT_TRACE_FILE_MODE_NONE = 0x00000000;

        public const uint EVENT_TRACE_FILE_MODE_SEQUENTIAL = 0x00000001;

        public const uint EVENT_TRACE_FILE_MODE_CIRCULAR = 0x00000002;

        public const uint EVENT_TRACE_FILE_MODE_APPEND = 0x00000004;

        public const uint EVENT_TRACE_REAL_TIME_MODE = 0x00000100;

        public const uint EVENT_TRACE_DELAY_OPEN_FILE_MODE = 0x00000200;

        public const uint EVENT_TRACE_BUFFERING_MODE = 0x00000400;

        public const uint EVENT_TRACE_PRIVATE_LOGGER_MODE = 0x00000800;

        public const uint EVENT_TRACE_ADD_HEADER_MODE = 0x00001000;

        public const uint EVENT_TRACE_USE_GLOBAL_SEQUENCE = 0x00004000;

        public const uint EVENT_TRACE_USE_LOCAL_SEQUENCE = 0x00008000;

        public const uint EVENT_TRACE_RELOG_MODE = 0x00010000;

        public const uint EVENT_TRACE_USE_PAGED_MEMORY = 0x01000000;

        public const uint EVENT_TRACE_FILE_MODE_NEWFILE = 0x00000008;

        public const uint EVENT_TRACE_FILE_MODE_PREALLOCATE = 0x00000020;

        public const uint EVENT_TRACE_NONSTOPPABLE_MODE = 0x00000040;

        public const uint EVENT_TRACE_SECURE_MODE = 0x00000080;

        public const uint EVENT_TRACE_USE_KBYTES_FOR_SIZE = 0x00002000;

        public const uint EVENT_TRACE_PRIVATE_IN_PROC = 0x00020000;

        public const uint EVENT_TRACE_MODE_RESERVED = 0x00100000;

        public const uint EVENT_TRACE_NO_PER_PROCESSOR_BUFFERING = 0x10000000;

        public const uint EVENT_TRACE_SYSTEM_LOGGER_MODE = 0x02000000;

        public const uint EVENT_TRACE_ADDTO_TRIAGE_DUMP = 0x80000000;

        public const uint EVENT_TRACE_STOP_ON_HYBRID_SHUTDOWN = 0x00400000;

        public const uint EVENT_TRACE_PERSIST_ON_HYBRID_SHUTDOWN = 0x00800000;

        public const uint EVENT_TRACE_INDEPENDENT_SESSION_MODE = 0x08000000;

        public const uint EVENT_TRACE_COMPRESSED_MODE = 0x04000000;

        public const uint EVENT_TRACE_CONTROL_INCREMENT_FILE = 4;

        public const uint TRACE_MESSAGE_PERFORMANCE_TIMESTAMP = 16;

        public const uint TRACE_MESSAGE_POINTER32 = 0x0040;

        public const uint TRACE_MESSAGE_POINTER64 = 0x0080;

        public const uint TRACE_MESSAGE_FLAG_MASK = 0xFFFF;

        public const uint EVENT_TRACE_USE_PROCTIME = 0x0001;

        public const uint EVENT_TRACE_USE_NOCPUTIME = 0x0002;

        public const uint TRACE_HEADER_FLAG_USE_TIMESTAMP = 0x00000200;

        public const uint TRACE_HEADER_FLAG_TRACED_GUID = 0x00020000;

        public const uint TRACE_HEADER_FLAG_LOG_WNODE = 0x00040000;

        public const uint TRACE_HEADER_FLAG_USE_GUID_PTR = 0x00080000;

        public const uint TRACE_HEADER_FLAG_USE_MOF_PTR = 0x00100000;

        public const uint ETW_NULL_TYPE_VALUE = 0;

        public const uint ETW_OBJECT_TYPE_VALUE = 1;

        public const uint ETW_STRING_TYPE_VALUE = 2;

        public const uint ETW_SBYTE_TYPE_VALUE = 3;

        public const uint ETW_BYTE_TYPE_VALUE = 4;

        public const uint ETW_INT16_TYPE_VALUE = 5;

        public const uint ETW_UINT16_TYPE_VALUE = 6;

        public const uint ETW_INT32_TYPE_VALUE = 7;

        public const uint ETW_UINT32_TYPE_VALUE = 8;

        public const uint ETW_INT64_TYPE_VALUE = 9;

        public const uint ETW_UINT64_TYPE_VALUE = 10;

        public const uint ETW_CHAR_TYPE_VALUE = 11;

        public const uint ETW_SINGLE_TYPE_VALUE = 12;

        public const uint ETW_DOUBLE_TYPE_VALUE = 13;

        public const uint ETW_BOOLEAN_TYPE_VALUE = 14;

        public const uint ETW_DECIMAL_TYPE_VALUE = 15;

        public const uint ETW_GUID_TYPE_VALUE = 101;

        public const uint ETW_ASCIICHAR_TYPE_VALUE = 102;

        public const uint ETW_ASCIISTRING_TYPE_VALUE = 103;

        public const uint ETW_COUNTED_STRING_TYPE_VALUE = 104;

        public const uint ETW_POINTER_TYPE_VALUE = 105;

        public const uint ETW_SIZET_TYPE_VALUE = 106;

        public const uint ETW_HIDDEN_TYPE_VALUE = 107;

        public const uint ETW_BOOL_TYPE_VALUE = 108;

        public const uint ETW_COUNTED_ANSISTRING_TYPE_VALUE = 109;

        public const uint ETW_REVERSED_COUNTED_STRING_TYPE_VALUE = 110;

        public const uint ETW_REVERSED_COUNTED_ANSISTRING_TYPE_VALUE = 111;

        public const uint ETW_NON_NULL_TERMINATED_STRING_TYPE_VALUE = 112;

        public const uint ETW_REDUCED_ANSISTRING_TYPE_VALUE = 113;

        public const uint ETW_REDUCED_STRING_TYPE_VALUE = 114;

        public const uint ETW_SID_TYPE_VALUE = 115;

        public const uint ETW_VARIANT_TYPE_VALUE = 116;

        public const uint ETW_PTVECTOR_TYPE_VALUE = 117;

        public const uint ETW_WMITIME_TYPE_VALUE = 118;

        public const uint ETW_DATETIME_TYPE_VALUE = 119;

        public const uint ETW_REFRENCE_TYPE_VALUE = 120;

        public const uint TRACE_PROVIDER_FLAG_LEGACY = 0x00000001;

        public const uint TRACE_PROVIDER_FLAG_PRE_ENABLE = 0x00000002;

        public const uint ENABLE_TRACE_PARAMETERS_VERSION = 1;

        public const uint ENABLE_TRACE_PARAMETERS_VERSION_2 = 2;

        public const uint EVENT_MIN_LEVEL = 0;

        public const uint EVENT_MAX_LEVEL = 0xff;

        public const uint EVENT_ACTIVITY_CTRL_GET_ID = 1;

        public const uint EVENT_ACTIVITY_CTRL_SET_ID = 2;

        public const uint EVENT_ACTIVITY_CTRL_CREATE_ID = 3;

        public const uint EVENT_ACTIVITY_CTRL_GET_SET_ID = 4;

        public const uint EVENT_ACTIVITY_CTRL_CREATE_SET_ID = 5;

        public const uint MAX_EVENT_DATA_DESCRIPTORS = 128;

        public const uint MAX_EVENT_FILTER_DATA_SIZE = 1024;

        public const uint MAX_EVENT_FILTER_PAYLOAD_SIZE = 4096;

        public const uint MAX_EVENT_FILTER_EVENT_NAME_SIZE = 4096;

        public const uint MAX_EVENT_FILTERS_COUNT = 13;

        public const uint MAX_EVENT_FILTER_PID_COUNT = 8;

        public const uint MAX_EVENT_FILTER_EVENT_ID_COUNT = 64;

        public const uint EVENT_FILTER_TYPE_NONE = 0x00000000;

        public const uint EVENT_FILTER_TYPE_SCHEMATIZED = 0x80000000;

        public const uint EVENT_FILTER_TYPE_SYSTEM_FLAGS = 0x80000001;

        public const uint EVENT_FILTER_TYPE_TRACEHANDLE = 0x80000002;

        public const uint EVENT_FILTER_TYPE_PID = 0x80000004;

        public const uint EVENT_FILTER_TYPE_EXECUTABLE_NAME = 0x80000008;

        public const uint EVENT_FILTER_TYPE_PACKAGE_ID = 0x80000010;

        public const uint EVENT_FILTER_TYPE_PACKAGE_APP_ID = 0x80000020;

        public const uint EVENT_FILTER_TYPE_PAYLOAD = 0x80000100;

        public const uint EVENT_FILTER_TYPE_EVENT_ID = 0x80000200;

        public const uint EVENT_FILTER_TYPE_EVENT_NAME = 0x80000400;

        public const uint EVENT_FILTER_TYPE_STACKWALK = 0x80001000;

        public const uint EVENT_FILTER_TYPE_STACKWALK_NAME = 0x80002000;

        public const uint EVENT_FILTER_TYPE_STACKWALK_LEVEL_KW = 0x80004000;

        public const uint EVENT_FILTER_TYPE_CONTAINER = 0x80008000;

        public const uint EVENT_DATA_DESCRIPTOR_TYPE_NONE = 0;

        public const uint EVENT_DATA_DESCRIPTOR_TYPE_EVENT_METADATA = 1;

        public const uint EVENT_DATA_DESCRIPTOR_TYPE_PROVIDER_METADATA = 2;

        public const uint EVENT_DATA_DESCRIPTOR_TYPE_TIMESTAMP_OVERRIDE = 3;

        public const uint EVENT_WRITE_FLAG_NO_FAULTING = 0x00000001;

        public const uint EVENT_WRITE_FLAG_INPRIVATE = 0x00000002;

        public const uint EVENT_HEADER_EXT_TYPE_RELATED_ACTIVITYID = 0x0001;

        public const uint EVENT_HEADER_EXT_TYPE_SID = 0x0002;

        public const uint EVENT_HEADER_EXT_TYPE_TS_ID = 0x0003;

        public const uint EVENT_HEADER_EXT_TYPE_INSTANCE_INFO = 0x0004;

        public const uint EVENT_HEADER_EXT_TYPE_STACK_TRACE32 = 0x0005;

        public const uint EVENT_HEADER_EXT_TYPE_STACK_TRACE64 = 0x0006;

        public const uint EVENT_HEADER_EXT_TYPE_PEBS_INDEX = 0x0007;

        public const uint EVENT_HEADER_EXT_TYPE_PMC_COUNTERS = 0x0008;

        public const uint EVENT_HEADER_EXT_TYPE_PSM_KEY = 0x0009;

        public const uint EVENT_HEADER_EXT_TYPE_EVENT_KEY = 0x000A;

        public const uint EVENT_HEADER_EXT_TYPE_EVENT_SCHEMA_TL = 0x000B;

        public const uint EVENT_HEADER_EXT_TYPE_PROV_TRAITS = 0x000C;

        public const uint EVENT_HEADER_EXT_TYPE_PROCESS_START_KEY = 0x000D;

        public const uint EVENT_HEADER_EXT_TYPE_CONTROL_GUID = 0x000E;

        public const uint EVENT_HEADER_EXT_TYPE_QPC_DELTA = 0x000F;

        public const uint EVENT_HEADER_EXT_TYPE_CONTAINER_ID = 0x0010;

        public const uint EVENT_HEADER_EXT_TYPE_MAX = 0x0011;

        public const uint EVENT_HEADER_PROPERTY_XML = 0x0001;

        public const uint EVENT_HEADER_PROPERTY_FORWARDED_XML = 0x0002;

        public const uint EVENT_HEADER_PROPERTY_LEGACY_EVENTLOG = 0x0004;

        public const uint EVENT_HEADER_PROPERTY_RELOGGABLE = 0x0008;

        public const uint EVENT_HEADER_FLAG_EXTENDED_INFO = 0x0001;

        public const uint EVENT_HEADER_FLAG_PRIVATE_SESSION = 0x0002;

        public const uint EVENT_HEADER_FLAG_STRING_ONLY = 0x0004;

        public const uint EVENT_HEADER_FLAG_TRACE_MESSAGE = 0x0008;

        public const uint EVENT_HEADER_FLAG_NO_CPUTIME = 0x0010;

        public const uint EVENT_HEADER_FLAG_32_BIT_HEADER = 0x0020;

        public const uint EVENT_HEADER_FLAG_64_BIT_HEADER = 0x0040;

        public const uint EVENT_HEADER_FLAG_DECODE_GUID = 0x0080;

        public const uint EVENT_HEADER_FLAG_CLASSIC_HEADER = 0x0100;

        public const uint EVENT_HEADER_FLAG_PROCESSOR_INDEX = 0x0200;

        public const uint EVENT_ENABLE_PROPERTY_SID = 0x00000001;

        public const uint EVENT_ENABLE_PROPERTY_TS_ID = 0x00000002;

        public const uint EVENT_ENABLE_PROPERTY_STACK_TRACE = 0x00000004;

        public const uint EVENT_ENABLE_PROPERTY_PSM_KEY = 0x00000008;

        public const uint EVENT_ENABLE_PROPERTY_IGNORE_KEYWORD_0 = 0x00000010;

        public const uint EVENT_ENABLE_PROPERTY_PROVIDER_GROUP = 0x00000020;

        public const uint EVENT_ENABLE_PROPERTY_ENABLE_KEYWORD_0 = 0x00000040;

        public const uint EVENT_ENABLE_PROPERTY_PROCESS_START_KEY = 0x00000080;

        public const uint EVENT_ENABLE_PROPERTY_EVENT_KEY = 0x00000100;

        public const uint EVENT_ENABLE_PROPERTY_EXCLUDE_INPRIVATE = 0x00000200;

        public const uint EVENT_ENABLE_PROPERTY_ENABLE_SILOS = 0x00000400;

        public const uint EVENT_ENABLE_PROPERTY_SOURCE_CONTAINER_TRACKING = 0x00000800;

        public const uint PROCESS_TRACE_MODE_REAL_TIME = 0x00000100;

        public const uint PROCESS_TRACE_MODE_RAW_TIMESTAMP = 0x00001000;

        public const uint PROCESS_TRACE_MODE_EVENT_RECORD = 0x10000000;

    }
}
