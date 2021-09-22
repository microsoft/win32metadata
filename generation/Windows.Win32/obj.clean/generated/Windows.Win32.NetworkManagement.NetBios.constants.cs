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


namespace Windows.Win32.NetworkManagement.NetBios
{
    public static partial class Apis
    {
        public const uint NCBNAMSZ = 16;

        public const uint MAX_LANA = 254;

        public const uint NAME_FLAGS_MASK = 0x87;

        public const uint GROUP_NAME = 0x80;

        public const uint UNIQUE_NAME = 0x00;

        public const uint REGISTERING = 0x00;

        public const uint REGISTERED = 0x04;

        public const uint DEREGISTERED = 0x05;

        public const uint DUPLICATE = 0x06;

        public const uint DUPLICATE_DEREG = 0x07;

        public const uint LISTEN_OUTSTANDING = 0x01;

        public const uint CALL_PENDING = 0x02;

        public const uint SESSION_ESTABLISHED = 0x03;

        public const uint HANGUP_PENDING = 0x04;

        public const uint HANGUP_COMPLETE = 0x05;

        public const uint SESSION_ABORTED = 0x06;

        public const uint NCBCALL = 0x10;

        public const uint NCBLISTEN = 0x11;

        public const uint NCBHANGUP = 0x12;

        public const uint NCBSEND = 0x14;

        public const uint NCBRECV = 0x15;

        public const uint NCBRECVANY = 0x16;

        public const uint NCBCHAINSEND = 0x17;

        public const uint NCBDGSEND = 0x20;

        public const uint NCBDGRECV = 0x21;

        public const uint NCBDGSENDBC = 0x22;

        public const uint NCBDGRECVBC = 0x23;

        public const uint NCBADDNAME = 0x30;

        public const uint NCBDELNAME = 0x31;

        public const uint NCBRESET = 0x32;

        public const uint NCBASTAT = 0x33;

        public const uint NCBSSTAT = 0x34;

        public const uint NCBCANCEL = 0x35;

        public const uint NCBADDGRNAME = 0x36;

        public const uint NCBENUM = 0x37;

        public const uint NCBUNLINK = 0x70;

        public const uint NCBSENDNA = 0x71;

        public const uint NCBCHAINSENDNA = 0x72;

        public const uint NCBLANSTALERT = 0x73;

        public const uint NCBACTION = 0x77;

        public const uint NCBFINDNAME = 0x78;

        public const uint NCBTRACE = 0x79;

        public const uint ASYNCH = 0x80;

        public const uint NRC_GOODRET = 0x00;

        public const uint NRC_BUFLEN = 0x01;

        public const uint NRC_ILLCMD = 0x03;

        public const uint NRC_CMDTMO = 0x05;

        public const uint NRC_INCOMP = 0x06;

        public const uint NRC_BADDR = 0x07;

        public const uint NRC_SNUMOUT = 0x08;

        public const uint NRC_NORES = 0x09;

        public const uint NRC_SCLOSED = 0x0a;

        public const uint NRC_CMDCAN = 0x0b;

        public const uint NRC_DUPNAME = 0x0d;

        public const uint NRC_NAMTFUL = 0x0e;

        public const uint NRC_ACTSES = 0x0f;

        public const uint NRC_LOCTFUL = 0x11;

        public const uint NRC_REMTFUL = 0x12;

        public const uint NRC_ILLNN = 0x13;

        public const uint NRC_NOCALL = 0x14;

        public const uint NRC_NOWILD = 0x15;

        public const uint NRC_INUSE = 0x16;

        public const uint NRC_NAMERR = 0x17;

        public const uint NRC_SABORT = 0x18;

        public const uint NRC_NAMCONF = 0x19;

        public const uint NRC_IFBUSY = 0x21;

        public const uint NRC_TOOMANY = 0x22;

        public const uint NRC_BRIDGE = 0x23;

        public const uint NRC_CANOCCR = 0x24;

        public const uint NRC_CANCEL = 0x26;

        public const uint NRC_DUPENV = 0x30;

        public const uint NRC_ENVNOTDEF = 0x34;

        public const uint NRC_OSRESNOTAV = 0x35;

        public const uint NRC_MAXAPPS = 0x36;

        public const uint NRC_NOSAPS = 0x37;

        public const uint NRC_NORESOURCES = 0x38;

        public const uint NRC_INVADDRESS = 0x39;

        public const uint NRC_INVDDID = 0x3B;

        public const uint NRC_LOCKFAIL = 0x3C;

        public const uint NRC_OPENERR = 0x3f;

        public const uint NRC_SYSTEM = 0x40;

        public const uint NRC_PENDING = 0xff;

    }
}
