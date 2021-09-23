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


using static Windows.Win32.System.EventLog.Apis;

namespace Windows.Win32.System.EventLog
{
    public enum REPORT_EVENT_TYPE : ushort
    {
        EVENTLOG_SUCCESS = 0,
        EVENTLOG_AUDIT_FAILURE = 16,
        EVENTLOG_AUDIT_SUCCESS = 8,
        EVENTLOG_ERROR_TYPE = 1,
        EVENTLOG_INFORMATION_TYPE = 4,
        EVENTLOG_WARNING_TYPE = 2,
    }

    public enum READ_EVENT_LOG_READ_FLAGS : uint
    {
        EVENTLOG_SEEK_READ = 2,
        EVENTLOG_SEQUENTIAL_READ = 1,
    }

}
