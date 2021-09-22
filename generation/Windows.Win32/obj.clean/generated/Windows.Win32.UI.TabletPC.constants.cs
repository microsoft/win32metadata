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


namespace Windows.Win32.UI.TabletPC
{
    public static partial class Apis
    {
        public const uint SAFE_PARTIAL = 1;

        public const uint BEST_COMPLETE = 2;

        public const uint MAX_VENDORNAME = 32;

        public const uint MAX_FRIENDLYNAME = 64;

        public const uint MAX_LANGUAGES = 64;

        public const uint CAC_FULL = 0;

        public const uint CAC_PREFIX = 1;

        public const uint CAC_RANDOM = 2;

        public const uint ASYNC_RECO_INTERRUPTED = 0x1;

        public const uint ASYNC_RECO_PROCESS_FAILED = 0x2;

        public const uint ASYNC_RECO_ADDSTROKE_FAILED = 0x4;

        public const uint ASYNC_RECO_SETCACMODE_FAILED = 0x8;

        public const uint ASYNC_RECO_RESETCONTEXT_FAILED = 0x10;

        public const uint ASYNC_RECO_SETGUIDE_FAILED = 0x20;

        public const uint ASYNC_RECO_SETFLAGS_FAILED = 0x40;

        public const uint ASYNC_RECO_SETFACTOID_FAILED = 0x80;

        public const uint ASYNC_RECO_SETTEXTCONTEXT_FAILED = 0x100;

        public const uint ASYNC_RECO_SETWORDLIST_FAILED = 0x200;

        public const int RF_DONTCARE = 1;

        public const int RF_OBJECT = 2;

        public const int RF_FREE_INPUT = 4;

        public const int RF_LINED_INPUT = 8;

        public const int RF_BOXED_INPUT = 16;

        public const int RF_CAC_INPUT = 32;

        public const int RF_RIGHT_AND_DOWN = 64;

        public const int RF_LEFT_AND_DOWN = 128;

        public const int RF_DOWN_AND_LEFT = 256;

        public const int RF_DOWN_AND_RIGHT = 512;

        public const int RF_ARBITRARY_ANGLE = 1024;

        public const int RF_LATTICE = 2048;

        public const int RF_ADVISEINKCHANGE = 4096;

        public const int RF_STROKEREORDER = 8192;

        public const int RF_PERSONALIZABLE = 16384;

        public const int RF_PERFORMSLINEBREAKING = 65536;

        public const int RF_REQUIRESSEGMENTATIONBREAKING = 131072;

        public const uint FLICK_WM_HANDLED_MASK = 0x1;

        public const uint NUM_FLICK_DIRECTIONS = 8;

        public const uint WM_TABLET_DEFBASE = 0x02C0;

        public const uint WM_TABLET_MAXOFFSET = 0x20;

        public const uint WM_TABLET_ADDED = WM_TABLET_DEFBASE + 8;

        public const uint WM_TABLET_DELETED = WM_TABLET_DEFBASE + 9;

        public const uint WM_TABLET_FLICK = WM_TABLET_DEFBASE + 11;

        public const uint WM_TABLET_QUERYSYSTEMGESTURESTATUS = WM_TABLET_DEFBASE + 12;

        public const uint TABLET_DISABLE_PRESSANDHOLD = 0x00000001;

        public const uint TABLET_DISABLE_PENTAPFEEDBACK = 0x00000008;

        public const uint TABLET_DISABLE_PENBARRELFEEDBACK = 0x00000010;

        public const uint TABLET_DISABLE_TOUCHUIFORCEON = 0x00000100;

        public const uint TABLET_DISABLE_TOUCHUIFORCEOFF = 0x00000200;

        public const uint TABLET_DISABLE_TOUCHSWITCH = 0x00008000;

        public const uint TABLET_DISABLE_FLICKS = 0x00010000;

        public const uint TABLET_ENABLE_FLICKSONCONTEXT = 0x00020000;

        public const uint TABLET_ENABLE_FLICKLEARNINGMODE = 0x00040000;

        public const uint TABLET_DISABLE_SMOOTHSCROLLING = 0x00080000;

        public const uint TABLET_DISABLE_FLICKFALLBACKKEYS = 0x00100000;

        public const uint TABLET_ENABLE_MULTITOUCHDATA = 0x01000000;

        public const uint MAX_PACKET_PROPERTY_COUNT = 32;

        public const uint MAX_PACKET_BUTTON_COUNT = 32;

        public const uint IP_CURSOR_DOWN = 0x00000001;

        public const uint IP_INVERTED = 0x00000002;

        public const uint IP_MARGIN = 0x00000004;

        public const uint IEC__BASE = WM_USER + 0x0200;

        public const uint EM_GETINKMODE = IEC__BASE + 1;

        public const uint EM_SETINKMODE = IEC__BASE + 2;

        public const uint EM_GETINKINSERTMODE = IEC__BASE + 3;

        public const uint EM_SETINKINSERTMODE = IEC__BASE + 4;

        public const uint EM_GETDRAWATTR = IEC__BASE + 5;

        public const uint EM_SETDRAWATTR = IEC__BASE + 6;

        public const uint EM_GETRECOTIMEOUT = IEC__BASE + 7;

        public const uint EM_SETRECOTIMEOUT = IEC__BASE + 8;

        public const uint EM_GETGESTURESTATUS = IEC__BASE + 9;

        public const uint EM_SETGESTURESTATUS = IEC__BASE + 10;

        public const uint EM_GETRECOGNIZER = IEC__BASE + 11;

        public const uint EM_SETRECOGNIZER = IEC__BASE + 12;

        public const uint EM_GETFACTOID = IEC__BASE + 13;

        public const uint EM_SETFACTOID = IEC__BASE + 14;

        public const uint EM_GETSELINK = IEC__BASE + 15;

        public const uint EM_SETSELINK = IEC__BASE + 16;

        public const uint EM_GETMOUSEICON = IEC__BASE + 17;

        public const uint EM_SETMOUSEICON = IEC__BASE + 18;

        public const uint EM_GETMOUSEPOINTER = IEC__BASE + 19;

        public const uint EM_SETMOUSEPOINTER = IEC__BASE + 20;

        public const uint EM_GETSTATUS = IEC__BASE + 21;

        public const uint EM_RECOGNIZE = IEC__BASE + 22;

        public const uint EM_GETUSEMOUSEFORINPUT = IEC__BASE + 23;

        public const uint EM_SETUSEMOUSEFORINPUT = IEC__BASE + 24;

        public const uint EM_SETSELINKDISPLAYMODE = IEC__BASE + 25;

        public const uint EM_GETSELINKDISPLAYMODE = IEC__BASE + 26;

        public const uint IECN__BASE = 0x0800;

        public const uint IECN_STROKE = IECN__BASE + 1;

        public const uint IECN_GESTURE = IECN__BASE + 2;

        public const uint IECN_RECOGNITIONRESULT = IECN__BASE + 3;

    }
}
