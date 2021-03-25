using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Controls
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("HTREEITEM")]
        public const int TVI_ROOT = -0x10000;

        [NativeTypeName("HTREEITEM")]
        public const int TVI_FIRST = -0x0FFFF;

        [NativeTypeName("HTREEITEM")]
        public const int TVI_LAST = -0x0FFFE;

        [NativeTypeName("HTREEITEM")]
        public const int TVI_SORT = -0x0FFFD;

        public const uint BCN_FIRST = unchecked((uint)-1250);
    }
}
