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


using static Windows.Win32.System.Performance.Apis;

namespace Windows.Win32.System.Performance
{
    public enum PERF_DETAIL : uint
    {
        PERF_DETAIL_NOVICE = 100,
        PERF_DETAIL_ADVANCED = 200,
        PERF_DETAIL_EXPERT = 300,
        PERF_DETAIL_WIZARD = 400,
    }

    public enum REAL_TIME_DATA_SOURCE_ID_FLAGS : uint
    {
        DATA_SOURCE_REGISTRY = ((uint) 0x00000001),
        DATA_SOURCE_WBEM = ((uint) 0x00000004),
    }

    public enum PDH_PATH_FLAGS : uint
    {
        PDH_PATH_WBEM_RESULT = ((uint) 0x00000001),
        PDH_PATH_WBEM_INPUT = ((uint) 0x00000002),
        PDH_PATH_WBEM_NONE = 0,
    }

    public enum PDH_FMT : uint
    {
        PDH_FMT_DOUBLE = ((uint) 0x00000200),
        PDH_FMT_LARGE = ((uint) 0x00000400),
        PDH_FMT_LONG = ((uint) 0x00000100),
    }

    public enum PDH_LOG_TYPE : uint
    {
        PDH_LOG_TYPE_UNDEFINED = 0,
        PDH_LOG_TYPE_CSV = 1,
        PDH_LOG_TYPE_SQL = 7,
        PDH_LOG_TYPE_TSV = 2,
        PDH_LOG_TYPE_BINARY = 8,
        PDH_LOG_TYPE_PERFMON = 6,
    }

    public enum PDH_LOG : uint
    {
        PDH_LOG_READ_ACCESS = ((uint) 0x00010000),
        PDH_LOG_WRITE_ACCESS = ((uint) 0x00020000),
        PDH_LOG_UPDATE_ACCESS = ((uint) 0x00040000),
    }

    public enum PDH_SELECT_DATA_SOURCE_FLAGS : uint
    {
        PDH_FLAGS_FILE_BROWSER_ONLY = ((uint) 0x00000001),
        PDH_FLAGS_NONE = 0,
    }

    public enum PDH_DLL_VERSION : uint
    {
        PDH_CVERSION_WIN50 = ((uint)(0x0500)),
        PDH_VERSION = ((uint)((PDH_CVERSION_WIN50) + 0x0003)),
    }

    public enum PERF_COUNTER_AGGREGATE_FUNC : uint
    {
        PERF_AGGREGATE_UNDEFINED = 0,
        PERF_AGGREGATE_TOTAL = 1,
        PERF_AGGREGATE_AVG = 2,
        PERF_AGGREGATE_MIN = 3,
    }

}
