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


using static Windows.Win32.UI.ColorSystem.Apis;

namespace Windows.Win32.UI.ColorSystem
{
    public enum ICM_COMMAND : uint
    {
        ICM_ADDPROFILE = 1,
        ICM_DELETEPROFILE = 2,
        ICM_QUERYPROFILE = 3,
        ICM_SETDEFAULTPROFILE = 4,
        ICM_REGISTERICMATCHER = 5,
        ICM_UNREGISTERICMATCHER = 6,
        ICM_QUERYMATCH = 7,
    }

    public enum COLOR_MATCH_TO_TARGET_ACTION
    {
        CS_ENABLE = 0x00000001,
        CS_DISABLE = 0x00000002,
        CS_DELETE_TRANSFORM = 0x00000003,
    }

}
