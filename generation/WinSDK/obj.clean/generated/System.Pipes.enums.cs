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


using static Windows.Win32.System.Pipes.Apis;

namespace Windows.Win32.System.Pipes
{
    [Flags]
    public enum NAMED_PIPE_MODE : uint
    {
        PIPE_WAIT = 0,
        PIPE_NOWAIT = 1,
        PIPE_READMODE_BYTE = 0,
        PIPE_READMODE_MESSAGE = 2,
    }

    public enum WAIT_NAMED_PIPE_TIME_OUT_FLAGS : uint
    {
        NMPWAIT_USE_DEFAULT_WAIT = 0,
        NMPWAIT_WAIT_FOREVER = 4294967295,
    }

    [Flags]
    public enum NAMED_PIPE_INFO_FLAGS : uint
    {
        PIPE_CLIENT_END = 0,
        PIPE_SERVER_END = 1,
        PIPE_TYPE_BYTE = 0,
        PIPE_TYPE_MESSAGE = 4,
    }

}
