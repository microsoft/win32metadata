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


using static Windows.Win32.UI.PointerInput.Apis;

namespace Windows.Win32.UI.PointerInput
{
    [Flags]
    public enum POINTER_FLAGS : uint
    {
        POINTER_FLAG_NONE = 0x00000000,
        POINTER_FLAG_NEW = 0x00000001,
        POINTER_FLAG_INRANGE = 0x00000002,
        POINTER_FLAG_INCONTACT = 0x00000004,
        POINTER_FLAG_FIRSTBUTTON = 0x00000010,
        POINTER_FLAG_SECONDBUTTON = 0x00000020,
        POINTER_FLAG_THIRDBUTTON = 0x00000040,
        POINTER_FLAG_FOURTHBUTTON = 0x00000080,
        POINTER_FLAG_FIFTHBUTTON = 0x00000100,
        POINTER_FLAG_PRIMARY = 0x00002000,
        POINTER_FLAG_CONFIDENCE = 0x00004000,
        POINTER_FLAG_CANCELED = 0x00008000,
        POINTER_FLAG_DOWN = 0x00010000,
        POINTER_FLAG_UPDATE = 0x00020000,
        POINTER_FLAG_UP = 0x00040000,
        POINTER_FLAG_WHEEL = 0x00080000,
        POINTER_FLAG_HWHEEL = 0x00100000,
        POINTER_FLAG_CAPTURECHANGED = 0x00200000,
        POINTER_FLAG_HASTRANSFORM = 0x00400000,
    }

}
