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


namespace Windows.Win32.System.Console
{
    public static partial class Apis
    {
        public const uint ATTACH_PARENT_PROCESS = 0xFFFFFFFF;

        public const uint CTRL_C_EVENT = 0;

        public const uint CTRL_BREAK_EVENT = 1;

        public const uint CTRL_CLOSE_EVENT = 2;

        public const uint CTRL_LOGOFF_EVENT = 5;

        public const uint CTRL_SHUTDOWN_EVENT = 6;

        public const uint PSEUDOCONSOLE_INHERIT_CURSOR = 0x1;

        public const uint FOREGROUND_BLUE = 0x0001;

        public const uint FOREGROUND_GREEN = 0x0002;

        public const uint FOREGROUND_RED = 0x0004;

        public const uint FOREGROUND_INTENSITY = 0x0008;

        public const uint BACKGROUND_BLUE = 0x0010;

        public const uint BACKGROUND_GREEN = 0x0020;

        public const uint BACKGROUND_RED = 0x0040;

        public const uint BACKGROUND_INTENSITY = 0x0080;

        public const uint COMMON_LVB_LEADING_BYTE = 0x0100;

        public const uint COMMON_LVB_TRAILING_BYTE = 0x0200;

        public const uint COMMON_LVB_GRID_HORIZONTAL = 0x0400;

        public const uint COMMON_LVB_GRID_LVERTICAL = 0x0800;

        public const uint COMMON_LVB_GRID_RVERTICAL = 0x1000;

        public const uint COMMON_LVB_REVERSE_VIDEO = 0x4000;

        public const uint COMMON_LVB_UNDERSCORE = 0x8000;

        public const uint COMMON_LVB_SBCSDBCS = 0x0300;

        public const uint CONSOLE_NO_SELECTION = 0x0000;

        public const uint CONSOLE_SELECTION_IN_PROGRESS = 0x0001;

        public const uint CONSOLE_SELECTION_NOT_EMPTY = 0x0002;

        public const uint CONSOLE_MOUSE_SELECTION = 0x0004;

        public const uint CONSOLE_MOUSE_DOWN = 0x0008;

        public const uint HISTORY_NO_DUP_FLAG = 0x1;

        public const uint CONSOLE_FULLSCREEN = 1;

        public const uint CONSOLE_FULLSCREEN_HARDWARE = 2;

        public const uint CONSOLE_FULLSCREEN_MODE = 1;

        public const uint CONSOLE_WINDOWED_MODE = 2;

        public const uint RIGHT_ALT_PRESSED = 0x0001;

        public const uint LEFT_ALT_PRESSED = 0x0002;

        public const uint RIGHT_CTRL_PRESSED = 0x0004;

        public const uint LEFT_CTRL_PRESSED = 0x0008;

        public const uint SHIFT_PRESSED = 0x0010;

        public const uint NUMLOCK_ON = 0x0020;

        public const uint SCROLLLOCK_ON = 0x0040;

        public const uint CAPSLOCK_ON = 0x0080;

        public const uint ENHANCED_KEY = 0x0100;

        public const uint NLS_DBCSCHAR = 0x00010000;

        public const uint NLS_ALPHANUMERIC = 0x00000000;

        public const uint NLS_KATAKANA = 0x00020000;

        public const uint NLS_HIRAGANA = 0x00040000;

        public const uint NLS_ROMAN = 0x00400000;

        public const uint NLS_IME_CONVERSION = 0x00800000;

        public const uint ALTNUMPAD_BIT = 0x04000000;

        public const uint NLS_IME_DISABLE = 0x20000000;

        public const uint FROM_LEFT_1ST_BUTTON_PRESSED = 0x0001;

        public const uint RIGHTMOST_BUTTON_PRESSED = 0x0002;

        public const uint FROM_LEFT_2ND_BUTTON_PRESSED = 0x0004;

        public const uint FROM_LEFT_3RD_BUTTON_PRESSED = 0x0008;

        public const uint FROM_LEFT_4TH_BUTTON_PRESSED = 0x0010;

        public const uint MOUSE_MOVED = 0x0001;

        public const uint DOUBLE_CLICK = 0x0002;

        public const uint MOUSE_WHEELED = 0x0004;

        public const uint MOUSE_HWHEELED = 0x0008;

        public const uint KEY_EVENT = 0x0001;

        public const uint MOUSE_EVENT = 0x0002;

        public const uint WINDOW_BUFFER_SIZE_EVENT = 0x0004;

        public const uint MENU_EVENT = 0x0008;

        public const uint FOCUS_EVENT = 0x0010;

    }
}
