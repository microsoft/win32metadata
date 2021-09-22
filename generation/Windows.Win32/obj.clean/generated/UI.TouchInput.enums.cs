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


using static Windows.Win32.UI.TouchInput.Apis;

namespace Windows.Win32.UI.TouchInput
{
    [Flags]
    public enum GESTURECONFIG_ID : uint
    {
        GID_BEGIN = 1,
        GID_END = 2,
        GID_ZOOM = 3,
        GID_PAN = 4,
        GID_ROTATE = 5,
        GID_TWOFINGERTAP = 6,
        GID_PRESSANDTAP = 7,
        GID_ROLLOVER = GID_PRESSANDTAP,
    }

    [Flags]
    public enum TOUCHEVENTF_FLAGS : uint
    {
        TOUCHEVENTF_MOVE = 0x0001,
        TOUCHEVENTF_DOWN = 0x0002,
        TOUCHEVENTF_UP = 0x0004,
        TOUCHEVENTF_INRANGE = 0x0008,
        TOUCHEVENTF_PRIMARY = 0x0010,
        TOUCHEVENTF_NOCOALESCE = 0x0020,
        TOUCHEVENTF_PEN = 0x0040,
        TOUCHEVENTF_PALM = 0x0080,
    }

    [Flags]
    public enum TOUCHINPUTMASKF_MASK : uint
    {
        TOUCHINPUTMASKF_TIMEFROMSYSTEM = 0x0001,
        TOUCHINPUTMASKF_EXTRAINFO = 0x0002,
        TOUCHINPUTMASKF_CONTACTAREA = 0x0004,
    }

    public enum REGISTER_TOUCH_WINDOW_FLAGS : uint
    {
        TWF_FINETOUCH = 0x00000001,
        TWF_WANTPALM = 0x00000002,
    }

}
