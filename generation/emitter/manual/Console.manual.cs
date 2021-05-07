using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Console
{
    [Flags]
    public enum CONSOLE_MODE : uint
    {
        ENABLE_ECHO_INPUT = 0x0004,
        ENABLE_INSERT_MODE = 0x0020,
        ENABLE_LINE_INPUT = 0x0002,
        ENABLE_MOUSE_INPUT = 0x0010,
        ENABLE_PROCESSED_INPUT = 0x0001,
        ENABLE_QUICK_EDIT_MODE = 0x0040,
        ENABLE_WINDOW_INPUT = 0x0008,
        ENABLE_VIRTUAL_TERMINAL_INPUT = 0x0200,
        ENABLE_PROCESSED_OUTPUT = 0x0001,
        ENABLE_WRAP_AT_EOL_OUTPUT = 0x0002,
        ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004,
        DISABLE_NEWLINE_AUTO_RETURN = 0x0008,
        ENABLE_LVB_GRID_WORLDWIDE = 0x0010
    }
}