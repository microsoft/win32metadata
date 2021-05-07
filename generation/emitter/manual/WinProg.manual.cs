using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.WindowsProgramming
{
    public enum HANDLE_FLAG_OPTIONS
    {
        HANDLE_FLAG_INHERIT = 0x00000001,
        HANDLE_FLAG_PROTECT_FROM_CLOSE = 0x00000002
    }

    public enum DUPLICATE_HANDLE_OPTIONS
    {
        DUPLICATE_CLOSE_SOURCE = 0x00000001,
        DUPLICATE_SAME_ACCESS = 0x00000002
    }

    public enum STD_HANDLE_TYPE : uint
    {
        STD_INPUT_HANDLE = unchecked((uint)-10),
        STD_OUTPUT_HANDLE = unchecked((uint)-11),
        STD_ERROR_HANDLE = unchecked((uint)-12),
    }

    [Flags]
    public enum VER_FLAGS : uint
    {
        VER_MINORVERSION = 0x0000001,
        VER_MAJORVERSION = 0x0000002,
        VER_BUILDNUMBER = 0x0000004,
        VER_PLATFORMID = 0x0000008,
        VER_SERVICEPACKMINOR = 0x0000010,
        VER_SERVICEPACKMAJOR = 0x0000020,
        VER_SUITENAME = 0x0000040,
        VER_PRODUCT_TYPE = 0x0000080
    }
}
