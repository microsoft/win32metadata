using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
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

        public const uint NM_FIRST = 0;
        public const uint NM_OUTOFMEMORY = unchecked((uint)NM_FIRST-1);
        public const uint NM_CLICK = unchecked((uint)NM_FIRST-2);
        public const uint NM_DBLCLK = unchecked((uint)NM_FIRST-3);
        public const uint NM_RETURN = unchecked((uint)NM_FIRST-4);
        public const uint NM_RCLICK = unchecked((uint)NM_FIRST-5);
        public const uint NM_RDBLCLK = unchecked((uint)NM_FIRST-6);
        public const uint NM_SETFOCUS = unchecked((uint)NM_FIRST-7);
        public const uint NM_KILLFOCUS = unchecked((uint)NM_FIRST-8);
        public const uint NM_CUSTOMDRAW = unchecked((uint)NM_FIRST-12);
        public const uint NM_HOVER = unchecked((uint)NM_FIRST-13);
        public const uint NM_NCHITTEST = unchecked((uint)NM_FIRST-14);
        public const uint NM_KEYDOWN = unchecked((uint)NM_FIRST-15);
        public const uint NM_RELEASEDCAPTURE = unchecked((uint)NM_FIRST-16);
        public const uint NM_SETCURSOR = unchecked((uint)NM_FIRST-17);
        public const uint NM_CHAR = unchecked((uint)NM_FIRST-18);
        public const uint NM_TOOLTIPSCREATED = unchecked((uint)NM_FIRST-19);
        public const uint NM_LDOWN = unchecked((uint)NM_FIRST-20);
        public const uint NM_RDOWN = unchecked((uint)NM_FIRST-21);
        public const uint NM_THEMECHANGED = unchecked((uint)NM_FIRST-22);
        public const uint NM_FONTCHANGED = unchecked((uint)NM_FIRST-23);
        public const uint NM_CUSTOMTEXT = unchecked((uint)NM_FIRST-24);
        public const uint NM_TVSTATEIMAGECHANGING = unchecked((uint)NM_FIRST-24);

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

    public enum POPUPSUBMENUHCHOTSTATES
    {
        MSMHC_HOT = 1,
    }
}
