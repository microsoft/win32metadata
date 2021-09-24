using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.UI.Controls.Apis;

namespace Windows.Win32.UI.Controls
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

        // These are defined in winuser.h and richedit.h with
        // different values. Exclude them from the ConstantsScraper
        // and manually define them here with the values from winuser.h.
        // Also define EM_SETLIMITTEXT as an alias for EM_LIMITTEXT.
        // https://github.com/microsoft/win32metadata/issues/527
        public const uint EM_SCROLLCARET = 0x00B7;
        public const uint EM_SETLIMITTEXT = EM_LIMITTEXT;
        public const uint EM_GETLIMITTEXT = 0x00D5;
        public const uint EM_POSFROMCHAR = 0x00D6;
        public const uint EM_CHARFROMPOS = 0x00D7;
    }
}
