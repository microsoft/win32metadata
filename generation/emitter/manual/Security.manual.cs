using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Security
{
    public static unsafe partial class Apis
    {
        // Has to be int so it can be used in a shift
        public const int CERT_COMPARE_SHIFT = 16;
    }
}
