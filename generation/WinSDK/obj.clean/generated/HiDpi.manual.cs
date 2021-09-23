using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.UI.HiDpi
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("DPI_AWARENESS_CONTEXT")]
        public const int DPI_AWARENESS_CONTEXT_UNAWARE = -1;

        [NativeTypeName("DPI_AWARENESS_CONTEXT")]
        public const int DPI_AWARENESS_CONTEXT_SYSTEM_AWARE = -2;

        [NativeTypeName("DPI_AWARENESS_CONTEXT")]
        public const int DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE = -3;

        [NativeTypeName("DPI_AWARENESS_CONTEXT")]
        public const int DPI_AWARENESS_CONTEXT_PER_MONITOR_AWARE_V2 = -4;

        [NativeTypeName("DPI_AWARENESS_CONTEXT")]
        public const int DPI_AWARENESS_CONTEXT_UNAWARE_GDISCALED = -5;
    }
}
