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


using static Windows.Win32.System.Diagnostics.Etw.Apis;

namespace Windows.Win32.System.Diagnostics.Etw
{
    [Flags]
    public enum TRACE_MESSAGE_FLAGS : uint
    {
        TRACE_MESSAGE_COMPONENTID = 4,
        TRACE_MESSAGE_GUID = 2,
        TRACE_MESSAGE_SEQUENCE = 1,
        TRACE_MESSAGE_SYSTEMINFO = 32,
        TRACE_MESSAGE_TIMESTAMP = 8,
    }

    public enum ENABLECALLBACK_ENABLED_STATE : uint
    {
        EVENT_CONTROL_CODE_DISABLE_PROVIDER = 0,
        EVENT_CONTROL_CODE_ENABLE_PROVIDER = 1,
        EVENT_CONTROL_CODE_CAPTURE_STATE = 2,
    }

    public enum EVENT_TRACE_CONTROL : uint
    {
        EVENT_TRACE_CONTROL_FLUSH = 3,
        EVENT_TRACE_CONTROL_QUERY = 0,
        EVENT_TRACE_CONTROL_STOP = 1,
        EVENT_TRACE_CONTROL_UPDATE = 2,
    }

    [Flags]
    public enum EVENT_TRACE_FLAG : uint
    {
        EVENT_TRACE_FLAG_ALPC = 1048576,
        EVENT_TRACE_FLAG_CSWITCH = 16,
        EVENT_TRACE_FLAG_DBGPRINT = 262144,
        EVENT_TRACE_FLAG_DISK_FILE_IO = 512,
        EVENT_TRACE_FLAG_DISK_IO = 256,
        EVENT_TRACE_FLAG_DISK_IO_INIT = 1024,
        EVENT_TRACE_FLAG_DISPATCHER = 2048,
        EVENT_TRACE_FLAG_DPC = 32,
        EVENT_TRACE_FLAG_DRIVER = 8388608,
        EVENT_TRACE_FLAG_FILE_IO = 33554432,
        EVENT_TRACE_FLAG_FILE_IO_INIT = 67108864,
        EVENT_TRACE_FLAG_IMAGE_LOAD = 4,
        EVENT_TRACE_FLAG_INTERRUPT = 64,
        EVENT_TRACE_FLAG_JOB = 524288,
        EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS = 8192,
        EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS = 4096,
        EVENT_TRACE_FLAG_NETWORK_TCPIP = 65536,
        EVENT_TRACE_FLAG_NO_SYSCONFIG = 268435456,
        EVENT_TRACE_FLAG_PROCESS = 1,
        EVENT_TRACE_FLAG_PROCESS_COUNTERS = 8,
        EVENT_TRACE_FLAG_PROFILE = 16777216,
        EVENT_TRACE_FLAG_REGISTRY = 131072,
        EVENT_TRACE_FLAG_SPLIT_IO = 2097152,
        EVENT_TRACE_FLAG_SYSTEMCALL = 128,
        EVENT_TRACE_FLAG_THREAD = 2,
        EVENT_TRACE_FLAG_VAMAP = 32768,
        EVENT_TRACE_FLAG_VIRTUAL_ALLOC = 16384,
    }

}
