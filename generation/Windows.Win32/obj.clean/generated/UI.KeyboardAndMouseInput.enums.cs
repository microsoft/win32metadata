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


using static Windows.Win32.UI.KeyboardAndMouseInput.Apis;

namespace Windows.Win32.UI.KeyboardAndMouseInput
{
    public enum RAW_INPUT_DATA_COMMAND_FLAGS : uint
    {
        RID_HEADER = 268435461,
        RID_INPUT = 268435459,
    }

    [Flags]
    public enum HOT_KEY_MODIFIERS : uint
    {
        MOD_ALT = 1,
        MOD_CONTROL = 2,
        MOD_NOREPEAT = 16384,
        MOD_SHIFT = 4,
        MOD_WIN = 8,
    }

    public enum RAW_INPUT_DEVICE_INFO_COMMAND : uint
    {
        RIDI_PREPARSEDDATA = 536870917,
        RIDI_DEVICENAME = 536870919,
        RIDI_DEVICEINFO = 536870923,
    }

    public enum ACTIVATE_KEYBOARD_LAYOUT_FLAGS : uint
    {
        KLF_REORDER = 8,
        KLF_RESET = 1073741824,
        KLF_SETFORPROCESS = 256,
        KLF_SHIFTLOCK = 65536,
        KLF_ACTIVATE = 1,
        KLF_NOTELLSHELL = 128,
        KLF_REPLACELANG = 16,
        KLF_SUBSTITUTE_OK = 2,
    }

    public enum GET_MOUSE_MOVE_POINTS_EX_RESOLUTION : uint
    {
        GMMP_USE_DISPLAY_POINTS = 1,
        GMMP_USE_HIGH_RESOLUTION_POINTS = 2,
    }

    [Flags]
    public enum KEYBD_EVENT_FLAGS : uint
    {
        KEYEVENTF_EXTENDEDKEY = 1,
        KEYEVENTF_KEYUP = 2,
        KEYEVENTF_SCANCODE = 8,
        KEYEVENTF_UNICODE = 4,
    }

    public enum MOUSE_EVENT_FLAGS : uint
    {
        MOUSEEVENTF_ABSOLUTE = 32768,
        MOUSEEVENTF_LEFTDOWN = 2,
        MOUSEEVENTF_LEFTUP = 4,
        MOUSEEVENTF_MIDDLEDOWN = 32,
        MOUSEEVENTF_MIDDLEUP = 64,
        MOUSEEVENTF_MOVE = 1,
        MOUSEEVENTF_RIGHTDOWN = 8,
        MOUSEEVENTF_RIGHTUP = 16,
        MOUSEEVENTF_WHEEL = 2048,
        MOUSEEVENTF_XDOWN = 128,
        MOUSEEVENTF_XUP = 256,
        MOUSEEVENTF_HWHEEL = 4096,
        MOUSEEVENTF_MOVE_NOCOALESCE = 8192,
        MOUSEEVENTF_VIRTUALDESK = 16384,
    }

    public enum RID_DEVICE_INFO_TYPE : uint
    {
        RIM_TYPEMOUSE = 0,
        RIM_TYPEKEYBOARD = 1,
        RIM_TYPEHID = 2,
    }

    public enum RAWINPUTDEVICE_FLAGS : uint
    {
        RIDEV_REMOVE = 1,
        RIDEV_EXCLUDE = 16,
        RIDEV_PAGEONLY = 32,
        RIDEV_NOLEGACY = 48,
        RIDEV_INPUTSINK = 256,
        RIDEV_CAPTUREMOUSE = 512,
        RIDEV_NOHOTKEYS = 512,
        RIDEV_APPKEYS = 1024,
        RIDEV_EXINPUTSINK = 4096,
        RIDEV_DEVNOTIFY = 8192,
    }

    public enum INPUT_TYPE : uint
    {
        INPUT_MOUSE = 0,
        INPUT_KEYBOARD = 1,
        INPUT_HARDWARE = 2,
    }

    [Flags]
    public enum TRACKMOUSEEVENT_FLAGS : uint
    {
        TME_CANCEL = 2147483648,
        TME_HOVER = 1,
        TME_LEAVE = 2,
        TME_NONCLIENT = 16,
        TME_QUERY = 1073741824,
    }

    public enum VIRTUAL_KEY : ushort
    {
        VK_0 = 0x30,
        VK_1 = 0x31,
        VK_2 = 0x32,
        VK_3 = 0x33,
        VK_4 = 0x34,
        VK_5 = 0x35,
        VK_6 = 0x36,
        VK_7 = 0x37,
        VK_8 = 0x38,
        VK_9 = 0x39,
        VK_A = 0x41,
        VK_B = 0x42,
        VK_C = 0x43,
        VK_D = 0x44,
        VK_E = 0x45,
        VK_F = 0x46,
        VK_G = 0x47,
        VK_H = 0x48,
        VK_I = 0x49,
        VK_J = 0x4A,
        VK_K = 0x4B,
        VK_L = 0x4C,
        VK_M = 0x4D,
        VK_N = 0x4E,
        VK_O = 0x4F,
        VK_P = 0x50,
        VK_Q = 0x51,
        VK_R = 0x52,
        VK_S = 0x53,
        VK_T = 0x54,
        VK_U = 0x55,
        VK_V = 0x56,
        VK_W = 0x57,
        VK_X = 0x58,
        VK_Y = 0x59,
        VK_Z = 0x5A,
        VK_LBUTTON = 0x01,
        VK_RBUTTON = 0x02,
        VK_CANCEL = 0x03,
        VK_MBUTTON = 0x04,
        VK_XBUTTON1 = 0x05,
        VK_XBUTTON2 = 0x06,
        VK_BACK = 0x08,
        VK_TAB = 0x09,
        VK_CLEAR = 0x0C,
        VK_RETURN = 0x0D,
        VK_SHIFT = 0x10,
        VK_CONTROL = 0x11,
        VK_MENU = 0x12,
        VK_PAUSE = 0x13,
        VK_CAPITAL = 0x14,
        VK_KANA = 0x15,
        VK_HANGEUL = 0x15,
        VK_HANGUL = 0x15,
        VK_JUNJA = 0x17,
        VK_FINAL = 0x18,
        VK_HANJA = 0x19,
        VK_KANJI = 0x19,
        VK_ESCAPE = 0x1B,
        VK_CONVERT = 0x1C,
        VK_NONCONVERT = 0x1D,
        VK_ACCEPT = 0x1E,
        VK_MODECHANGE = 0x1F,
        VK_SPACE = 0x20,
        VK_PRIOR = 0x21,
        VK_NEXT = 0x22,
        VK_END = 0x23,
        VK_HOME = 0x24,
        VK_LEFT = 0x25,
        VK_UP = 0x26,
        VK_RIGHT = 0x27,
        VK_DOWN = 0x28,
        VK_SELECT = 0x29,
        VK_PRINT = 0x2A,
        VK_EXECUTE = 0x2B,
        VK_SNAPSHOT = 0x2C,
        VK_INSERT = 0x2D,
        VK_DELETE = 0x2E,
        VK_HELP = 0x2F,
        VK_LWIN = 0x5B,
        VK_RWIN = 0x5C,
        VK_APPS = 0x5D,
        VK_SLEEP = 0x5F,
        VK_NUMPAD0 = 0x60,
        VK_NUMPAD1 = 0x61,
        VK_NUMPAD2 = 0x62,
        VK_NUMPAD3 = 0x63,
        VK_NUMPAD4 = 0x64,
        VK_NUMPAD5 = 0x65,
        VK_NUMPAD6 = 0x66,
        VK_NUMPAD7 = 0x67,
        VK_NUMPAD8 = 0x68,
        VK_NUMPAD9 = 0x69,
        VK_MULTIPLY = 0x6A,
        VK_ADD = 0x6B,
        VK_SEPARATOR = 0x6C,
        VK_SUBTRACT = 0x6D,
        VK_DECIMAL = 0x6E,
        VK_DIVIDE = 0x6F,
        VK_F1 = 0x70,
        VK_F2 = 0x71,
        VK_F3 = 0x72,
        VK_F4 = 0x73,
        VK_F5 = 0x74,
        VK_F6 = 0x75,
        VK_F7 = 0x76,
        VK_F8 = 0x77,
        VK_F9 = 0x78,
        VK_F10 = 0x79,
        VK_F11 = 0x7A,
        VK_F12 = 0x7B,
        VK_F13 = 0x7C,
        VK_F14 = 0x7D,
        VK_F15 = 0x7E,
        VK_F16 = 0x7F,
        VK_F17 = 0x80,
        VK_F18 = 0x81,
        VK_F19 = 0x82,
        VK_F20 = 0x83,
        VK_F21 = 0x84,
        VK_F22 = 0x85,
        VK_F23 = 0x86,
        VK_F24 = 0x87,
        VK_NAVIGATION_VIEW = 0x88,
        VK_NAVIGATION_MENU = 0x89,
        VK_NAVIGATION_UP = 0x8A,
        VK_NAVIGATION_DOWN = 0x8B,
        VK_NAVIGATION_LEFT = 0x8C,
        VK_NAVIGATION_RIGHT = 0x8D,
        VK_NAVIGATION_ACCEPT = 0x8E,
        VK_NAVIGATION_CANCEL = 0x8F,
        VK_NUMLOCK = 0x90,
        VK_SCROLL = 0x91,
        VK_OEM_NEC_EQUAL = 0x92,
        VK_OEM_FJ_JISHO = 0x92,
        VK_OEM_FJ_MASSHOU = 0x93,
        VK_OEM_FJ_TOUROKU = 0x94,
        VK_OEM_FJ_LOYA = 0x95,
        VK_OEM_FJ_ROYA = 0x96,
        VK_LSHIFT = 0xA0,
        VK_RSHIFT = 0xA1,
        VK_LCONTROL = 0xA2,
        VK_RCONTROL = 0xA3,
        VK_LMENU = 0xA4,
        VK_RMENU = 0xA5,
        VK_BROWSER_BACK = 0xA6,
        VK_BROWSER_FORWARD = 0xA7,
        VK_BROWSER_REFRESH = 0xA8,
        VK_BROWSER_STOP = 0xA9,
        VK_BROWSER_SEARCH = 0xAA,
        VK_BROWSER_FAVORITES = 0xAB,
        VK_BROWSER_HOME = 0xAC,
        VK_VOLUME_MUTE = 0xAD,
        VK_VOLUME_DOWN = 0xAE,
        VK_VOLUME_UP = 0xAF,
        VK_MEDIA_NEXT_TRACK = 0xB0,
        VK_MEDIA_PREV_TRACK = 0xB1,
        VK_MEDIA_STOP = 0xB2,
        VK_MEDIA_PLAY_PAUSE = 0xB3,
        VK_LAUNCH_MAIL = 0xB4,
        VK_LAUNCH_MEDIA_SELECT = 0xB5,
        VK_LAUNCH_APP1 = 0xB6,
        VK_LAUNCH_APP2 = 0xB7,
        VK_OEM_1 = 0xBA,
        VK_OEM_PLUS = 0xBB,
        VK_OEM_COMMA = 0xBC,
        VK_OEM_MINUS = 0xBD,
        VK_OEM_PERIOD = 0xBE,
        VK_OEM_2 = 0xBF,
        VK_OEM_3 = 0xC0,
        VK_GAMEPAD_A = 0xC3,
        VK_GAMEPAD_B = 0xC4,
        VK_GAMEPAD_X = 0xC5,
        VK_GAMEPAD_Y = 0xC6,
        VK_GAMEPAD_RIGHT_SHOULDER = 0xC7,
        VK_GAMEPAD_LEFT_SHOULDER = 0xC8,
        VK_GAMEPAD_LEFT_TRIGGER = 0xC9,
        VK_GAMEPAD_RIGHT_TRIGGER = 0xCA,
        VK_GAMEPAD_DPAD_UP = 0xCB,
        VK_GAMEPAD_DPAD_DOWN = 0xCC,
        VK_GAMEPAD_DPAD_LEFT = 0xCD,
        VK_GAMEPAD_DPAD_RIGHT = 0xCE,
        VK_GAMEPAD_MENU = 0xCF,
        VK_GAMEPAD_VIEW = 0xD0,
        VK_GAMEPAD_LEFT_THUMBSTICK_BUTTON = 0xD1,
        VK_GAMEPAD_RIGHT_THUMBSTICK_BUTTON = 0xD2,
        VK_GAMEPAD_LEFT_THUMBSTICK_UP = 0xD3,
        VK_GAMEPAD_LEFT_THUMBSTICK_DOWN = 0xD4,
        VK_GAMEPAD_LEFT_THUMBSTICK_RIGHT = 0xD5,
        VK_GAMEPAD_LEFT_THUMBSTICK_LEFT = 0xD6,
        VK_GAMEPAD_RIGHT_THUMBSTICK_UP = 0xD7,
        VK_GAMEPAD_RIGHT_THUMBSTICK_DOWN = 0xD8,
        VK_GAMEPAD_RIGHT_THUMBSTICK_RIGHT = 0xD9,
        VK_GAMEPAD_RIGHT_THUMBSTICK_LEFT = 0xDA,
        VK_OEM_4 = 0xDB,
        VK_OEM_5 = 0xDC,
        VK_OEM_6 = 0xDD,
        VK_OEM_7 = 0xDE,
        VK_OEM_8 = 0xDF,
        VK_OEM_AX = 0xE1,
        VK_OEM_102 = 0xE2,
        VK_ICO_HELP = 0xE3,
        VK_ICO_00 = 0xE4,
        VK_PROCESSKEY = 0xE5,
        VK_ICO_CLEAR = 0xE6,
        VK_PACKET = 0xE7,
        VK_OEM_RESET = 0xE9,
        VK_OEM_JUMP = 0xEA,
        VK_OEM_PA1 = 0xEB,
        VK_OEM_PA2 = 0xEC,
        VK_OEM_PA3 = 0xED,
        VK_OEM_WSCTRL = 0xEE,
        VK_OEM_CUSEL = 0xEF,
        VK_OEM_ATTN = 0xF0,
        VK_OEM_FINISH = 0xF1,
        VK_OEM_COPY = 0xF2,
        VK_OEM_AUTO = 0xF3,
        VK_OEM_ENLW = 0xF4,
        VK_OEM_BACKTAB = 0xF5,
        VK_ATTN = 0xF6,
        VK_CRSEL = 0xF7,
        VK_EXSEL = 0xF8,
        VK_EREOF = 0xF9,
        VK_PLAY = 0xFA,
        VK_ZOOM = 0xFB,
        VK_NONAME = 0xFC,
        VK_PA1 = 0xFD,
        VK_OEM_CLEAR = 0xFE,
    }

}
