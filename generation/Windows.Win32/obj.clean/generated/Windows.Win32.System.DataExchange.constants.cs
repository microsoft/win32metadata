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


namespace Windows.Win32.System.DataExchange
{
    public static partial class Apis
    {
        public const uint WM_DDE_FIRST = 0x03E0;

        public const uint WM_DDE_TERMINATE = WM_DDE_FIRST+1;

        public const uint WM_DDE_ADVISE = WM_DDE_FIRST+2;

        public const uint WM_DDE_UNADVISE = WM_DDE_FIRST+3;

        public const uint WM_DDE_ACK = WM_DDE_FIRST+4;

        public const uint WM_DDE_DATA = WM_DDE_FIRST+5;

        public const uint WM_DDE_REQUEST = WM_DDE_FIRST+6;

        public const uint WM_DDE_POKE = WM_DDE_FIRST+7;

        public const uint WM_DDE_EXECUTE = WM_DDE_FIRST+8;

        public const uint WM_DDE_LAST = WM_DDE_FIRST+8;

        public const uint CADV_LATEACK = 0xFFFF;

        public const uint DDE_FACK = 0x8000;

        public const uint DDE_FBUSY = 0x4000;

        public const uint DDE_FDEFERUPD = 0x4000;

        public const uint DDE_FACKREQ = 0x8000;

        public const uint DDE_FRELEASE = 0x2000;

        public const uint DDE_FREQUESTED = 0x1000;

        public const uint DDE_FAPPSTATUS = 0x00ff;

        public const uint DDE_FNOTPROCESSED = 0x0000;

        public const uint MSGF_DDEMGR = 0x8001;

        public const int CP_WINANSI = 1004;

        public const int CP_WINUNICODE = 1200;

        public const uint XTYPF_NOBLOCK = 0x0002;

        public const uint XTYPF_NODATA = 0x0004;

        public const uint XTYPF_ACKREQ = 0x0008;

        public const uint XCLASS_MASK = 0xFC00;

        public const uint XCLASS_BOOL = 0x1000;

        public const uint XCLASS_DATA = 0x2000;

        public const uint XCLASS_FLAGS = 0x4000;

        public const uint XCLASS_NOTIFICATION = 0x8000;

        public const uint XTYP_MASK = 0x00F0;

        public const uint XTYP_SHIFT = 4;

        public const uint TIMEOUT_ASYNC = 0xFFFFFFFF;

        public const uint QID_SYNC = 0xFFFFFFFF;

        public const int APPCMD_MASK = 0x00000FF0;

        public const int APPCLASS_MASK = 0x0000000F;

        public const uint HDATA_APPOWNED = 0x0001;

        public const uint DMLERR_NO_ERROR = 0;

        public const uint DMLERR_FIRST = 0x4000;

        public const uint DMLERR_ADVACKTIMEOUT = 0x4000;

        public const uint DMLERR_BUSY = 0x4001;

        public const uint DMLERR_DATAACKTIMEOUT = 0x4002;

        public const uint DMLERR_DLL_NOT_INITIALIZED = 0x4003;

        public const uint DMLERR_DLL_USAGE = 0x4004;

        public const uint DMLERR_EXECACKTIMEOUT = 0x4005;

        public const uint DMLERR_INVALIDPARAMETER = 0x4006;

        public const uint DMLERR_LOW_MEMORY = 0x4007;

        public const uint DMLERR_MEMORY_ERROR = 0x4008;

        public const uint DMLERR_NOTPROCESSED = 0x4009;

        public const uint DMLERR_NO_CONV_ESTABLISHED = 0x400a;

        public const uint DMLERR_POKEACKTIMEOUT = 0x400b;

        public const uint DMLERR_POSTMSG_FAILED = 0x400c;

        public const uint DMLERR_REENTRANCY = 0x400d;

        public const uint DMLERR_SERVER_DIED = 0x400e;

        public const uint DMLERR_SYS_ERROR = 0x400f;

        public const uint DMLERR_UNADVACKTIMEOUT = 0x4010;

        public const uint DMLERR_UNFOUND_QUEUE_ID = 0x4011;

        public const uint DMLERR_LAST = 0x4011;

        public const uint MH_CREATE = 1;

        public const uint MH_KEEP = 2;

        public const uint MH_DELETE = 3;

        public const uint MH_CLEANUP = 4;

        public const uint MAX_MONITORS = 4;

        public const uint MF_MASK = 0xFF000000;

    }
}
