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


namespace Windows.Win32.System.Performance
{
    public static partial class Apis
    {
        public const uint MAX_COUNTER_PATH = 256;

        public const uint PDH_MAX_COUNTER_NAME = 1024;

        public const uint PDH_MAX_INSTANCE_NAME = 1024;

        public const uint PDH_MAX_COUNTER_PATH = 2048;

        public const uint PDH_MAX_DATASOURCE_PATH = 1024;

        public const int PDH_MAX_SCALE = 7;

        public const int PDH_MIN_SCALE = -7;

        public const uint PDH_NOEXPANDCOUNTERS = 1;

        public const uint PDH_NOEXPANDINSTANCES = 2;

        public const uint PDH_REFRESHCOUNTERS = 4;

        public const uint PDH_LOG_TYPE_RETIRED_BIN = 3;

        public const uint PDH_LOG_TYPE_TRACE_KERNEL = 4;

        public const uint PDH_LOG_TYPE_TRACE_GENERIC = 5;

        public const uint PERF_PROVIDER_USER_MODE = 0;

        public const uint PERF_PROVIDER_KERNEL_MODE = 1;

        public const uint PERF_PROVIDER_DRIVER = 2;

        public const uint PERF_COUNTERSET_FLAG_MULTIPLE = 2;

        public const uint PERF_COUNTERSET_FLAG_AGGREGATE = 4;

        public const uint PERF_COUNTERSET_FLAG_HISTORY = 8;

        public const uint PERF_COUNTERSET_FLAG_INSTANCE = 16;

        public const uint PERF_COUNTERSET_SINGLE_INSTANCE = 0;

        public const uint PERF_AGGREGATE_MAX = 4;

        public const ulong PERF_ATTRIB_BY_REFERENCE = 0x0000000000000001;

        public const ulong PERF_ATTRIB_NO_DISPLAYABLE = 0x0000000000000002;

        public const ulong PERF_ATTRIB_NO_GROUP_SEPARATOR = 0x0000000000000004;

        public const ulong PERF_ATTRIB_DISPLAY_AS_REAL = 0x0000000000000008;

        public const ulong PERF_ATTRIB_DISPLAY_AS_HEX = 0x0000000000000010;

        public const uint PERF_WILDCARD_COUNTER = 0xFFFFFFFF;

        public const uint PERF_MAX_INSTANCE_NAME = 1024;

        public const uint PERF_ADD_COUNTER = 1;

        public const uint PERF_REMOVE_COUNTER = 2;

        public const uint PERF_ENUM_INSTANCES = 3;

        public const uint PERF_COLLECT_START = 5;

        public const uint PERF_COLLECT_END = 6;

        public const uint PERF_FILTER = 9;

        public const uint PERF_DATA_VERSION = 1;

        public const uint PERF_DATA_REVISION = 1;

        public const int PERF_NO_INSTANCES = -1;

        public const uint PERF_SIZE_DWORD = 0x00000000;

        public const uint PERF_SIZE_LARGE = 0x00000100;

        public const uint PERF_SIZE_ZERO = 0x00000200;

        public const uint PERF_SIZE_VARIABLE_LEN = 0x00000300;

        public const uint PERF_TYPE_NUMBER = 0x00000000;

        public const uint PERF_TYPE_COUNTER = 0x00000400;

        public const uint PERF_TYPE_TEXT = 0x00000800;

        public const uint PERF_TYPE_ZERO = 0x00000C00;

        public const uint PERF_NUMBER_HEX = 0x00000000;

        public const uint PERF_NUMBER_DECIMAL = 0x00010000;

        public const uint PERF_NUMBER_DEC_1000 = 0x00020000;

        public const uint PERF_COUNTER_VALUE = 0x00000000;

        public const uint PERF_COUNTER_RATE = 0x00010000;

        public const uint PERF_COUNTER_FRACTION = 0x00020000;

        public const uint PERF_COUNTER_BASE = 0x00030000;

        public const uint PERF_COUNTER_ELAPSED = 0x00040000;

        public const uint PERF_COUNTER_QUEUELEN = 0x00050000;

        public const uint PERF_COUNTER_HISTOGRAM = 0x00060000;

        public const uint PERF_COUNTER_PRECISION = 0x00070000;

        public const uint PERF_TEXT_UNICODE = 0x00000000;

        public const uint PERF_TEXT_ASCII = 0x00010000;

        public const uint PERF_TIMER_TICK = 0x00000000;

        public const uint PERF_TIMER_100NS = 0x00100000;

        public const uint PERF_OBJECT_TIMER = 0x00200000;

        public const uint PERF_DELTA_COUNTER = 0x00400000;

        public const uint PERF_DELTA_BASE = 0x00800000;

        public const uint PERF_INVERSE_COUNTER = 0x01000000;

        public const uint PERF_MULTI_COUNTER = 0x02000000;

        public const uint PERF_DISPLAY_NO_SUFFIX = 0x00000000;

        public const uint PERF_DISPLAY_PER_SEC = 0x10000000;

        public const uint PERF_DISPLAY_PERCENT = 0x20000000;

        public const uint PERF_DISPLAY_SECONDS = 0x30000000;

        public const uint PERF_DISPLAY_NOSHOW = 0x40000000;

        public const uint PERF_COUNTER_HISTOGRAM_TYPE = 0x80000000;

        public const int PERF_NO_UNIQUE_ID = -1;

        public const int MAX_PERF_OBJECTS_IN_QUERY_FUNCTION = 64;

        public const uint WINPERF_LOG_NONE = 0;

        public const uint WINPERF_LOG_USER = 1;

        public const uint WINPERF_LOG_DEBUG = 2;

        public const uint WINPERF_LOG_VERBOSE = 3;

        public const uint PLA_CAPABILITY_LOCAL = 0x10000000;

        public const uint PLA_CAPABILITY_V1_SVC = 0x00000001;

        public const uint PLA_CAPABILITY_V1_SESSION = 0x00000002;

        public const uint PLA_CAPABILITY_V1_SYSTEM = 0x00000004;

        public const uint PLA_CAPABILITY_LEGACY_SESSION = 0x00000008;

        public const uint PLA_CAPABILITY_LEGACY_SVC = 0x00000010;

        public const uint PLA_CAPABILITY_AUTOLOGGER = 0x00000020;

    }
}
