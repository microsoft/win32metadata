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


using static Windows.Win32.System.TpmBaseServices.Apis;

namespace Windows.Win32.System.TpmBaseServices
{
    public enum TBS_COMMAND_PRIORITY : uint
    {
        TBS_COMMAND_PRIORITY_LOW = 100,
        TBS_COMMAND_PRIORITY_NORMAL = 200,
        TBS_COMMAND_PRIORITY_SYSTEM = 400,
        TBS_COMMAND_PRIORITY_HIGH = 300,
        TBS_COMMAND_PRIORITY_MAX = 0x80000000,
    }

    public enum TBS_COMMAND_LOCALITY : uint
    {
        TBS_COMMAND_LOCALITY_ZERO = 0,
        TBS_COMMAND_LOCALITY_ONE = 1,
        TBS_COMMAND_LOCALITY_TWO = 2,
        TBS_COMMAND_LOCALITY_THREE = 3,
        TBS_COMMAND_LOCALITY_FOUR = 4,
    }

}
