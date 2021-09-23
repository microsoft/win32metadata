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


using static Windows.Win32.System.ErrorReporting.Apis;

namespace Windows.Win32.System.ErrorReporting
{
    [Flags]
    public enum WER_FILE : uint
    {
        WER_FILE_ANONYMOUS_DATA = 2,
        WER_FILE_DELETE_WHEN_DONE = 1,
    }

    [Flags]
    public enum WER_SUBMIT_FLAGS : uint
    {
        WER_SUBMIT_ADD_REGISTERED_DATA = 16,
        WER_SUBMIT_HONOR_RECOVERY = 1,
        WER_SUBMIT_HONOR_RESTART = 2,
        WER_SUBMIT_NO_ARCHIVE = 256,
        WER_SUBMIT_NO_CLOSE_UI = 64,
        WER_SUBMIT_NO_QUEUE = 128,
        WER_SUBMIT_OUTOFPROCESS = 32,
        WER_SUBMIT_OUTOFPROCESS_ASYNC = 1024,
        WER_SUBMIT_QUEUE = 4,
        WER_SUBMIT_SHOW_DEBUG = 8,
        WER_SUBMIT_START_MINIMIZED = 512,
        WER_SUBMIT_BYPASS_DATA_THROTTLING = 2048,
        WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY = 4096,
        WER_SUBMIT_REPORT_MACHINE_ID = 8192,
    }

    [Flags]
    public enum WER_FAULT_REPORTING : uint
    {
        WER_FAULT_REPORTING_FLAG_DISABLE_THREAD_SUSPENSION = 4,
        WER_FAULT_REPORTING_FLAG_NOHEAP = 1,
        WER_FAULT_REPORTING_FLAG_QUEUE = 2,
        WER_FAULT_REPORTING_FLAG_QUEUE_UPLOAD = 8,
        WER_FAULT_REPORTING_ALWAYS_SHOW_UI = 16,
    }

}
