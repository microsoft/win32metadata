using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.SystemInformation
{
    public static unsafe partial class Apis
    {
        // Duplicated in msi.h. Prefer the values and namespace of sdkddkver.h.
        public const uint NTDDI_WIN2K = 0x05000000;
        public const uint NTDDI_WINXP = 0x05010000;
        public const uint NTDDI_WINXPSP2 = 0x05010200;
        public const uint NTDDI_WS03SP1 = 0x05020100;
        public const uint NTDDI_VISTA = 0x06000000;
        public const uint NTDDI_VISTASP1 = 0x06000100;
        public const uint NTDDI_WIN7 = 0x06010000;
        public const uint NTDDI_WIN8 = 0x06020000;
        public const uint NTDDI_WINBLUE = 0x06030000;
        public const uint NTDDI_WINTHRESHOLD = 0x0A000000;
    }
}
