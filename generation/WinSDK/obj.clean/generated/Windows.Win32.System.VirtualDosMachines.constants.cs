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


namespace Windows.Win32.System.VirtualDosMachines
{
    public static partial class Apis
    {
        public const uint VDMCONTEXT_i386 = 0x00010000;

        public const uint VDMCONTEXT_i486 = 0x00010000;

        public const uint VDM_KGDT_R3_CODE = 24;

        public const uint VDM_MAXIMUM_SUPPORTED_EXTENSION = 512;

        public const uint V86FLAGS_CARRY = 0x00001;

        public const uint V86FLAGS_PARITY = 0x00004;

        public const uint V86FLAGS_AUXCARRY = 0x00010;

        public const uint V86FLAGS_ZERO = 0x00040;

        public const uint V86FLAGS_SIGN = 0x00080;

        public const uint V86FLAGS_TRACE = 0x00100;

        public const uint V86FLAGS_INTERRUPT = 0x00200;

        public const uint V86FLAGS_DIRECTION = 0x00400;

        public const uint V86FLAGS_OVERFLOW = 0x00800;

        public const uint V86FLAGS_IOPL = 0x03000;

        public const uint V86FLAGS_IOPL_BITS = 0x12;

        public const uint V86FLAGS_RESUME = 0x10000;

        public const uint V86FLAGS_V86 = 0x20000;

        public const uint V86FLAGS_ALIGNMENT = 0x40000;

        public const uint DBG_SEGLOAD = 0;

        public const uint DBG_SEGMOVE = 1;

        public const uint DBG_SEGFREE = 2;

        public const uint DBG_MODLOAD = 3;

        public const uint DBG_MODFREE = 4;

        public const uint DBG_SINGLESTEP = 5;

        public const uint DBG_BREAK = 6;

        public const uint DBG_GPFAULT = 7;

        public const uint DBG_DIVOVERFLOW = 8;

        public const uint DBG_INSTRFAULT = 9;

        public const uint DBG_TASKSTART = 10;

        public const uint DBG_TASKSTOP = 11;

        public const uint DBG_DLLSTART = 12;

        public const uint DBG_DLLSTOP = 13;

        public const uint DBG_ATTACH = 14;

        public const uint DBG_TOOLHELP = 15;

        public const uint DBG_STACKFAULT = 16;

        public const uint DBG_WOWINIT = 17;

        public const uint DBG_TEMPBP = 18;

        public const uint DBG_MODMOVE = 19;

        public const uint DBG_INIT = 20;

        public const uint DBG_GPFAULT2 = 21;

        public const uint VDMEVENT_NEEDS_INTERACTIVE = 0x8000;

        public const uint VDMEVENT_VERBOSE = 0x4000;

        public const uint VDMEVENT_PE = 0x2000;

        public const uint VDMEVENT_ALLFLAGS = 0xe000;

        public const uint VDMEVENT_V86 = 0x0001;

        public const uint VDMEVENT_PM16 = 0x0002;

        public const uint MAX_MODULE_NAME = 8 + 1;

        public const uint MAX_PATH16 = 255;

        public const uint SN_CODE = 0;

        public const uint SN_DATA = 1;

        public const uint SN_V86 = 2;

        public const uint GLOBAL_ALL = 0;

        public const uint GLOBAL_LRU = 1;

        public const uint GLOBAL_FREE = 2;

        public const uint GT_UNKNOWN = 0;

        public const uint GT_DGROUP = 1;

        public const uint GT_DATA = 2;

        public const uint GT_CODE = 3;

        public const uint GT_TASK = 4;

        public const uint GT_RESOURCE = 5;

        public const uint GT_MODULE = 6;

        public const uint GT_FREE = 7;

        public const uint GT_INTERNAL = 8;

        public const uint GT_SENTINEL = 9;

        public const uint GT_BURGERMASTER = 10;

        public const uint GD_USERDEFINED = 0;

        public const uint GD_CURSORCOMPONENT = 1;

        public const uint GD_BITMAP = 2;

        public const uint GD_ICONCOMPONENT = 3;

        public const uint GD_MENU = 4;

        public const uint GD_DIALOG = 5;

        public const uint GD_STRING = 6;

        public const uint GD_FONTDIR = 7;

        public const uint GD_FONT = 8;

        public const uint GD_ACCELERATORS = 9;

        public const uint GD_RCDATA = 10;

        public const uint GD_ERRTABLE = 11;

        public const uint GD_CURSOR = 12;

        public const uint GD_ICON = 14;

        public const uint GD_NAMETABLE = 15;

        public const uint GD_MAX_RESOURCE = 15;

        public const uint VDMDBG_BREAK_DOSTASK = 0x00000001;

        public const uint VDMDBG_BREAK_WOWTASK = 0x00000002;

        public const uint VDMDBG_BREAK_LOADDLL = 0x00000004;

        public const uint VDMDBG_BREAK_EXCEPTIONS = 0x00000008;

        public const uint VDMDBG_BREAK_DEBUGGER = 0x00000010;

        public const uint VDMDBG_TRACE_HISTORY = 0x00000080;

        public const uint VDMDBG_BREAK_DIVIDEBYZERO = 0x00000100;

        public const uint VDMDBG_MAX_SYMBOL_BUFFER = 256;

        public const uint VDMADDR_V86 = 2;

        public const uint VDMADDR_PM16 = 4;

        public const uint VDMADDR_PM32 = 16;

    }
}
