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


using static Windows.Win32.UI.XInput.Apis;

namespace Windows.Win32.UI.XInput
{
    public enum XINPUT_VIRTUAL_KEY : ushort
    {
        VK_PAD_A = 0x5800,
        VK_PAD_B = 0x5801,
        VK_PAD_X = 0x5802,
        VK_PAD_Y = 0x5803,
        VK_PAD_RSHOULDER = 0x5804,
        VK_PAD_LSHOULDER = 0x5805,
        VK_PAD_LTRIGGER = 0x5806,
        VK_PAD_RTRIGGER = 0x5807,
        VK_PAD_DPAD_UP = 0x5810,
        VK_PAD_DPAD_DOWN = 0x5811,
        VK_PAD_DPAD_LEFT = 0x5812,
        VK_PAD_DPAD_RIGHT = 0x5813,
        VK_PAD_START = 0x5814,
        VK_PAD_BACK = 0x5815,
        VK_PAD_LTHUMB_PRESS = 0x5816,
        VK_PAD_RTHUMB_PRESS = 0x5817,
        VK_PAD_LTHUMB_UP = 0x5820,
        VK_PAD_LTHUMB_DOWN = 0x5821,
        VK_PAD_LTHUMB_RIGHT = 0x5822,
        VK_PAD_LTHUMB_LEFT = 0x5823,
        VK_PAD_LTHUMB_UPLEFT = 0x5824,
        VK_PAD_LTHUMB_UPRIGHT = 0x5825,
        VK_PAD_LTHUMB_DOWNRIGHT = 0x5826,
        VK_PAD_LTHUMB_DOWNLEFT = 0x5827,
        VK_PAD_RTHUMB_UP = 0x5830,
        VK_PAD_RTHUMB_DOWN = 0x5831,
        VK_PAD_RTHUMB_RIGHT = 0x5832,
        VK_PAD_RTHUMB_LEFT = 0x5833,
        VK_PAD_RTHUMB_UPLEFT = 0x5834,
        VK_PAD_RTHUMB_UPRIGHT = 0x5835,
        VK_PAD_RTHUMB_DOWNRIGHT = 0x5836,
        VK_PAD_RTHUMB_DOWNLEFT = 0x5837,
    }

}
