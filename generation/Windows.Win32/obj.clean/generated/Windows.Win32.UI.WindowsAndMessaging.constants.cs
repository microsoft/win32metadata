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


namespace Windows.Win32.UI.WindowsAndMessaging
{
    public static partial class Apis
    {
        public const uint WM_DEVICECHANGE = 0x0219;

        public const uint BSM_VXDS = 0x00000001;

        public const uint BSM_NETDRIVER = 0x00000002;

        public const uint BSM_INSTALLABLEDRIVERS = 0x00000004;

        public const uint OFN_SHAREFALLTHROUGH = 2;

        public const uint OFN_SHARENOWARN = 1;

        public const uint OFN_SHAREWARN = 0;

        public const uint CDM_FIRST = WM_USER + 100;

        public const uint CDM_LAST = WM_USER + 200;

        public const uint CDM_GETSPEC = CDM_FIRST + 0x0000;

        public const uint CDM_GETFILEPATH = CDM_FIRST + 0x0001;

        public const uint CDM_GETFOLDERPATH = CDM_FIRST + 0x0002;

        public const uint CDM_GETFOLDERIDLIST = CDM_FIRST + 0x0003;

        public const uint CDM_SETCONTROLTEXT = CDM_FIRST + 0x0004;

        public const uint CDM_HIDECONTROL = CDM_FIRST + 0x0005;

        public const uint CDM_SETDEFEXT = CDM_FIRST + 0x0006;

        public const uint FR_RAW = 0x00020000;

        public const uint FR_SHOWWRAPAROUND = 0x00040000;

        public const uint FR_NOWRAPAROUND = 0x00080000;

        public const uint FR_WRAPAROUND = 0x00100000;

        public const uint FRM_FIRST = WM_USER + 100;

        public const uint FRM_LAST = WM_USER + 200;

        public const uint FRM_SETOPERATIONRESULT = FRM_FIRST + 0x0000;

        public const uint FRM_SETOPERATIONRESULTTEXT = FRM_FIRST + 0x0001;

        public const uint PS_OPENTYPE_FONTTYPE = 0x10000;

        public const uint TT_OPENTYPE_FONTTYPE = 0x20000;

        public const uint TYPE1_FONTTYPE = 0x40000;

        public const uint SYMBOL_FONTTYPE = 0x80000;

        public const uint WM_CHOOSEFONT_GETLOGFONT = WM_USER + 1;

        public const uint WM_CHOOSEFONT_SETLOGFONT = WM_USER + 101;

        public const uint WM_CHOOSEFONT_SETFLAGS = WM_USER + 102;

        public const int CD_LBSELNOITEMS = -1;

        public const uint CD_LBSELCHANGE = 0;

        public const uint CD_LBSELSUB = 1;

        public const uint CD_LBSELADD = 2;

        public const uint START_PAGE_GENERAL = 0xffffffff;

        public const uint PD_RESULT_CANCEL = 0;

        public const uint PD_RESULT_PRINT = 1;

        public const uint PD_RESULT_APPLY = 2;

        public const uint DN_DEFAULTPRN = 0x0001;

        public const uint WM_PSD_FULLPAGERECT = WM_USER+1;

        public const uint WM_PSD_MINMARGINRECT = WM_USER+2;

        public const uint WM_PSD_MARGINRECT = WM_USER+3;

        public const uint WM_PSD_GREEKTEXTRECT = WM_USER+4;

        public const uint WM_PSD_ENVSTAMPRECT = WM_USER+5;

        public const uint WM_PSD_YAFULLPAGERECT = WM_USER+6;

        [NativeTypeName("LPCWSTR")]
        public const int RT_CURSOR = 1;

        [NativeTypeName("LPCWSTR")]
        public const int RT_BITMAP = 2;

        [NativeTypeName("LPCWSTR")]
        public const int RT_ICON = 3;

        [NativeTypeName("LPCWSTR")]
        public const int RT_MENU = 4;

        [NativeTypeName("LPCWSTR")]
        public const int RT_DIALOG = 5;

        [NativeTypeName("LPCWSTR")]
        public const int RT_FONTDIR = 7;

        [NativeTypeName("LPCWSTR")]
        public const int RT_FONT = 8;

        [NativeTypeName("LPCWSTR")]
        public const int RT_ACCELERATOR = 9;

        [NativeTypeName("LPCWSTR")]
        public const int RT_MESSAGETABLE = 11;

        public const uint DIFFERENCE = 11;

        [NativeTypeName("LPCWSTR")]
        public const int RT_VERSION = 16;

        [NativeTypeName("LPCWSTR")]
        public const int RT_DLGINCLUDE = 17;

        [NativeTypeName("LPCWSTR")]
        public const int RT_PLUGPLAY = 19;

        [NativeTypeName("LPCWSTR")]
        public const int RT_VXD = 20;

        [NativeTypeName("LPCWSTR")]
        public const int RT_ANICURSOR = 21;

        [NativeTypeName("LPCWSTR")]
        public const int RT_ANIICON = 22;

        [NativeTypeName("LPCWSTR")]
        public const int RT_HTML = 23;

        public const uint RT_MANIFEST = 24;

        public const uint CREATEPROCESS_MANIFEST_RESOURCE_ID = 1;

        public const uint ISOLATIONAWARE_MANIFEST_RESOURCE_ID = 2;

        public const uint ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID = 3;

        public const uint ISOLATIONPOLICY_MANIFEST_RESOURCE_ID = 4;

        public const uint ISOLATIONPOLICY_BROWSER_MANIFEST_RESOURCE_ID = 5;

        public const uint MINIMUM_RESERVED_MANIFEST_RESOURCE_ID = 1;

        public const uint MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID = 16;

        public const uint SB_LINEUP = 0;

        public const uint SB_LINELEFT = 0;

        public const uint SB_LINEDOWN = 1;

        public const uint SB_LINERIGHT = 1;

        public const uint SB_PAGEUP = 2;

        public const uint SB_PAGELEFT = 2;

        public const uint SB_PAGEDOWN = 3;

        public const uint SB_PAGERIGHT = 3;

        public const uint SB_THUMBPOSITION = 4;

        public const uint SB_THUMBTRACK = 5;

        public const uint SB_TOP = 6;

        public const uint SB_LEFT = 6;

        public const uint SB_BOTTOM = 7;

        public const uint SB_RIGHT = 7;

        public const uint SB_ENDSCROLL = 8;

        public const uint HIDE_WINDOW = 0;

        public const uint SHOW_OPENWINDOW = 1;

        public const uint SHOW_ICONWINDOW = 2;

        public const uint SHOW_FULLSCREEN = 3;

        public const uint SHOW_OPENNOACTIVATE = 4;

        public const uint KF_EXTENDED = 0x0100;

        public const uint KF_DLGMODE = 0x0800;

        public const uint KF_MENUMODE = 0x1000;

        public const uint KF_ALTDOWN = 0x2000;

        public const uint KF_REPEAT = 0x4000;

        public const uint KF_UP = 0x8000;

        public const int WH_MIN = -1;

        public const uint WH_HARDWARE = 8;

        public const uint WH_MAX = 14;

        public const uint HC_ACTION = 0;

        public const uint HC_GETNEXT = 1;

        public const uint HC_SKIP = 2;

        public const uint HC_NOREMOVE = 3;

        public const uint HC_SYSMODALON = 4;

        public const uint HC_SYSMODALOFF = 5;

        public const uint HCBT_MOVESIZE = 0;

        public const uint HCBT_MINMAX = 1;

        public const uint HCBT_QS = 2;

        public const uint HCBT_CREATEWND = 3;

        public const uint HCBT_DESTROYWND = 4;

        public const uint HCBT_ACTIVATE = 5;

        public const uint HCBT_CLICKSKIPPED = 6;

        public const uint HCBT_KEYSKIPPED = 7;

        public const uint HCBT_SYSCOMMAND = 8;

        public const uint HCBT_SETFOCUS = 9;

        public const uint WTS_CONSOLE_CONNECT = 0x1;

        public const uint WTS_CONSOLE_DISCONNECT = 0x2;

        public const uint WTS_REMOTE_CONNECT = 0x3;

        public const uint WTS_REMOTE_DISCONNECT = 0x4;

        public const uint WTS_SESSION_LOGON = 0x5;

        public const uint WTS_SESSION_LOGOFF = 0x6;

        public const uint WTS_SESSION_LOCK = 0x7;

        public const uint WTS_SESSION_UNLOCK = 0x8;

        public const uint WTS_SESSION_REMOTE_CONTROL = 0x9;

        public const uint WTS_SESSION_CREATE = 0xa;

        public const uint WTS_SESSION_TERMINATE = 0xb;

        public const uint MSGF_DIALOGBOX = 0;

        public const uint MSGF_MESSAGEBOX = 1;

        public const uint MSGF_MENU = 2;

        public const uint MSGF_SCROLLBAR = 5;

        public const uint MSGF_NEXTWINDOW = 6;

        public const uint MSGF_MAX = 8;

        public const uint MSGF_USER = 4096;

        public const uint HSHELL_WINDOWCREATED = 1;

        public const uint HSHELL_WINDOWDESTROYED = 2;

        public const uint HSHELL_ACTIVATESHELLWINDOW = 3;

        public const uint HSHELL_WINDOWACTIVATED = 4;

        public const uint HSHELL_GETMINRECT = 5;

        public const uint HSHELL_REDRAW = 6;

        public const uint HSHELL_TASKMAN = 7;

        public const uint HSHELL_LANGUAGE = 8;

        public const uint HSHELL_SYSMENU = 9;

        public const uint HSHELL_ENDTASK = 10;

        public const uint HSHELL_ACCESSIBILITYSTATE = 11;

        public const uint HSHELL_APPCOMMAND = 12;

        public const uint HSHELL_WINDOWREPLACED = 13;

        public const uint HSHELL_WINDOWREPLACING = 14;

        public const uint HSHELL_MONITORCHANGED = 16;

        public const uint HSHELL_HIGHBIT = 0x8000;

        public const uint FAPPCOMMAND_MOUSE = 0x8000;

        public const uint FAPPCOMMAND_KEY = 0;

        public const uint FAPPCOMMAND_OEM = 0x1000;

        public const uint FAPPCOMMAND_MASK = 0xF000;

        public const uint LLMHF_INJECTED = 0x00000001;

        public const uint LLMHF_LOWER_IL_INJECTED = 0x00000002;

        public const uint HKL_PREV = 0;

        public const uint HKL_NEXT = 1;

        public const uint INPUTLANGCHANGE_SYSCHARSET = 0x0001;

        public const uint INPUTLANGCHANGE_FORWARD = 0x0002;

        public const uint INPUTLANGCHANGE_BACKWARD = 0x0004;

        public const uint KL_NAMELENGTH = 9;

        public const int DESKTOP_READOBJECTS = 0x0001;

        public const int DESKTOP_CREATEWINDOW = 0x0002;

        public const int DESKTOP_CREATEMENU = 0x0004;

        public const int DESKTOP_HOOKCONTROL = 0x0008;

        public const int DESKTOP_JOURNALRECORD = 0x0010;

        public const int DESKTOP_JOURNALPLAYBACK = 0x0020;

        public const int DESKTOP_ENUMERATE = 0x0040;

        public const int DESKTOP_WRITEOBJECTS = 0x0080;

        public const int DESKTOP_SWITCHDESKTOP = 0x0100;

        public const int DF_ALLOWOTHERACCOUNTHOOK = 0x0001;

        public const int WINSTA_ENUMDESKTOPS = 0x0001;

        public const int WINSTA_READATTRIBUTES = 0x0002;

        public const int WINSTA_ACCESSCLIPBOARD = 0x0004;

        public const int WINSTA_CREATEDESKTOP = 0x0008;

        public const int WINSTA_WRITEATTRIBUTES = 0x0010;

        public const int WINSTA_ACCESSGLOBALATOMS = 0x0020;

        public const int WINSTA_EXITWINDOWS = 0x0040;

        public const int WINSTA_ENUMERATE = 0x0100;

        public const int WINSTA_READSCREEN = 0x0200;

        public const uint CWF_CREATE_ONLY = 0x00000001;

        public const int WSF_VISIBLE = 0x0001;

        public const uint UOI_TIMERPROC_EXCEPTION_SUPPRESSION = 7;

        public const uint WM_NULL = 0x0000;

        public const uint WM_CREATE = 0x0001;

        public const uint WM_DESTROY = 0x0002;

        public const uint WM_MOVE = 0x0003;

        public const uint WM_SIZE = 0x0005;

        public const uint WM_ACTIVATE = 0x0006;

        public const uint WA_INACTIVE = 0;

        public const uint WA_ACTIVE = 1;

        public const uint WA_CLICKACTIVE = 2;

        public const uint WM_SETFOCUS = 0x0007;

        public const uint WM_KILLFOCUS = 0x0008;

        public const uint WM_ENABLE = 0x000A;

        public const uint WM_SETREDRAW = 0x000B;

        public const uint WM_SETTEXT = 0x000C;

        public const uint WM_GETTEXT = 0x000D;

        public const uint WM_GETTEXTLENGTH = 0x000E;

        public const uint WM_PAINT = 0x000F;

        public const uint WM_CLOSE = 0x0010;

        public const uint WM_QUERYENDSESSION = 0x0011;

        public const uint WM_QUERYOPEN = 0x0013;

        public const uint WM_ENDSESSION = 0x0016;

        public const uint WM_QUIT = 0x0012;

        public const uint WM_ERASEBKGND = 0x0014;

        public const uint WM_SYSCOLORCHANGE = 0x0015;

        public const uint WM_SHOWWINDOW = 0x0018;

        public const uint WM_WININICHANGE = 0x001A;

        public const uint WM_DEVMODECHANGE = 0x001B;

        public const uint WM_ACTIVATEAPP = 0x001C;

        public const uint WM_FONTCHANGE = 0x001D;

        public const uint WM_TIMECHANGE = 0x001E;

        public const uint WM_CANCELMODE = 0x001F;

        public const uint WM_SETCURSOR = 0x0020;

        public const uint WM_MOUSEACTIVATE = 0x0021;

        public const uint WM_CHILDACTIVATE = 0x0022;

        public const uint WM_QUEUESYNC = 0x0023;

        public const uint WM_GETMINMAXINFO = 0x0024;

        public const uint WM_PAINTICON = 0x0026;

        public const uint WM_ICONERASEBKGND = 0x0027;

        public const uint WM_NEXTDLGCTL = 0x0028;

        public const uint WM_SPOOLERSTATUS = 0x002A;

        public const uint WM_DRAWITEM = 0x002B;

        public const uint WM_MEASUREITEM = 0x002C;

        public const uint WM_DELETEITEM = 0x002D;

        public const uint WM_VKEYTOITEM = 0x002E;

        public const uint WM_CHARTOITEM = 0x002F;

        public const uint WM_SETFONT = 0x0030;

        public const uint WM_GETFONT = 0x0031;

        public const uint WM_SETHOTKEY = 0x0032;

        public const uint WM_GETHOTKEY = 0x0033;

        public const uint WM_QUERYDRAGICON = 0x0037;

        public const uint WM_COMPAREITEM = 0x0039;

        public const uint WM_GETOBJECT = 0x003D;

        public const uint WM_COMPACTING = 0x0041;

        public const uint WM_COMMNOTIFY = 0x0044;

        public const uint WM_WINDOWPOSCHANGING = 0x0046;

        public const uint WM_WINDOWPOSCHANGED = 0x0047;

        public const uint WM_POWER = 0x0048;

        public const uint PWR_OK = 1;

        public const int PWR_FAIL = -1;

        public const uint PWR_SUSPENDREQUEST = 1;

        public const uint PWR_SUSPENDRESUME = 2;

        public const uint PWR_CRITICALRESUME = 3;

        public const uint WM_COPYDATA = 0x004A;

        public const uint WM_CANCELJOURNAL = 0x004B;

        public const uint WM_INPUTLANGCHANGEREQUEST = 0x0050;

        public const uint WM_INPUTLANGCHANGE = 0x0051;

        public const uint WM_TCARD = 0x0052;

        public const uint WM_HELP = 0x0053;

        public const uint WM_USERCHANGED = 0x0054;

        public const uint WM_NOTIFYFORMAT = 0x0055;

        public const uint NFR_ANSI = 1;

        public const uint NFR_UNICODE = 2;

        public const uint NF_QUERY = 3;

        public const uint NF_REQUERY = 4;

        public const uint WM_STYLECHANGING = 0x007C;

        public const uint WM_STYLECHANGED = 0x007D;

        public const uint WM_DISPLAYCHANGE = 0x007E;

        public const uint WM_GETICON = 0x007F;

        public const uint WM_SETICON = 0x0080;

        public const uint WM_NCCREATE = 0x0081;

        public const uint WM_NCDESTROY = 0x0082;

        public const uint WM_NCCALCSIZE = 0x0083;

        public const uint WM_NCHITTEST = 0x0084;

        public const uint WM_NCPAINT = 0x0085;

        public const uint WM_NCACTIVATE = 0x0086;

        public const uint WM_GETDLGCODE = 0x0087;

        public const uint WM_SYNCPAINT = 0x0088;

        public const uint WM_NCMOUSEMOVE = 0x00A0;

        public const uint WM_NCLBUTTONDOWN = 0x00A1;

        public const uint WM_NCLBUTTONUP = 0x00A2;

        public const uint WM_NCLBUTTONDBLCLK = 0x00A3;

        public const uint WM_NCRBUTTONDOWN = 0x00A4;

        public const uint WM_NCRBUTTONUP = 0x00A5;

        public const uint WM_NCRBUTTONDBLCLK = 0x00A6;

        public const uint WM_NCMBUTTONDOWN = 0x00A7;

        public const uint WM_NCMBUTTONUP = 0x00A8;

        public const uint WM_NCMBUTTONDBLCLK = 0x00A9;

        public const uint WM_NCXBUTTONDOWN = 0x00AB;

        public const uint WM_NCXBUTTONUP = 0x00AC;

        public const uint WM_NCXBUTTONDBLCLK = 0x00AD;

        public const uint WM_INPUT_DEVICE_CHANGE = 0x00FE;

        public const uint WM_INPUT = 0x00FF;

        public const uint WM_KEYFIRST = 0x0100;

        public const uint WM_KEYDOWN = 0x0100;

        public const uint WM_KEYUP = 0x0101;

        public const uint WM_CHAR = 0x0102;

        public const uint WM_DEADCHAR = 0x0103;

        public const uint WM_SYSKEYDOWN = 0x0104;

        public const uint WM_SYSKEYUP = 0x0105;

        public const uint WM_SYSCHAR = 0x0106;

        public const uint WM_SYSDEADCHAR = 0x0107;

        public const uint WM_KEYLAST = 0x0109;

        public const uint UNICODE_NOCHAR = 0xFFFF;

        public const uint WM_IME_STARTCOMPOSITION = 0x010D;

        public const uint WM_IME_ENDCOMPOSITION = 0x010E;

        public const uint WM_IME_COMPOSITION = 0x010F;

        public const uint WM_IME_KEYLAST = 0x010F;

        public const uint WM_INITDIALOG = 0x0110;

        public const uint WM_COMMAND = 0x0111;

        public const uint WM_SYSCOMMAND = 0x0112;

        public const uint WM_TIMER = 0x0113;

        public const uint WM_HSCROLL = 0x0114;

        public const uint WM_VSCROLL = 0x0115;

        public const uint WM_INITMENU = 0x0116;

        public const uint WM_INITMENUPOPUP = 0x0117;

        public const uint WM_GESTURE = 0x0119;

        public const uint WM_GESTURENOTIFY = 0x011A;

        public const uint WM_MENUSELECT = 0x011F;

        public const uint WM_MENUCHAR = 0x0120;

        public const uint WM_ENTERIDLE = 0x0121;

        public const uint WM_MENURBUTTONUP = 0x0122;

        public const uint WM_MENUDRAG = 0x0123;

        public const uint WM_MENUGETOBJECT = 0x0124;

        public const uint WM_UNINITMENUPOPUP = 0x0125;

        public const uint WM_MENUCOMMAND = 0x0126;

        public const uint WM_CHANGEUISTATE = 0x0127;

        public const uint WM_UPDATEUISTATE = 0x0128;

        public const uint WM_QUERYUISTATE = 0x0129;

        public const uint UIS_SET = 1;

        public const uint UIS_CLEAR = 2;

        public const uint UIS_INITIALIZE = 3;

        public const uint UISF_HIDEFOCUS = 0x1;

        public const uint UISF_HIDEACCEL = 0x2;

        public const uint UISF_ACTIVE = 0x4;

        public const uint WM_CTLCOLORMSGBOX = 0x0132;

        public const uint WM_CTLCOLOREDIT = 0x0133;

        public const uint WM_CTLCOLORLISTBOX = 0x0134;

        public const uint WM_CTLCOLORBTN = 0x0135;

        public const uint WM_CTLCOLORDLG = 0x0136;

        public const uint WM_CTLCOLORSCROLLBAR = 0x0137;

        public const uint WM_CTLCOLORSTATIC = 0x0138;

        public const uint MN_GETHMENU = 0x01E1;

        public const uint WM_MOUSEFIRST = 0x0200;

        public const uint WM_MOUSEMOVE = 0x0200;

        public const uint WM_LBUTTONDOWN = 0x0201;

        public const uint WM_LBUTTONUP = 0x0202;

        public const uint WM_LBUTTONDBLCLK = 0x0203;

        public const uint WM_RBUTTONDOWN = 0x0204;

        public const uint WM_RBUTTONUP = 0x0205;

        public const uint WM_RBUTTONDBLCLK = 0x0206;

        public const uint WM_MBUTTONDOWN = 0x0207;

        public const uint WM_MBUTTONUP = 0x0208;

        public const uint WM_MBUTTONDBLCLK = 0x0209;

        public const uint WM_MOUSEWHEEL = 0x020A;

        public const uint WM_XBUTTONDOWN = 0x020B;

        public const uint WM_XBUTTONUP = 0x020C;

        public const uint WM_XBUTTONDBLCLK = 0x020D;

        public const uint WM_MOUSEHWHEEL = 0x020E;

        public const uint WM_MOUSELAST = 0x020E;

        public const uint WHEEL_DELTA = 120;

        public const uint WM_PARENTNOTIFY = 0x0210;

        public const uint WM_ENTERMENULOOP = 0x0211;

        public const uint WM_EXITMENULOOP = 0x0212;

        public const uint WM_NEXTMENU = 0x0213;

        public const uint WM_SIZING = 0x0214;

        public const uint WM_CAPTURECHANGED = 0x0215;

        public const uint WM_MOVING = 0x0216;

        public const uint WM_POWERBROADCAST = 0x0218;

        public const uint PBT_APMQUERYSUSPEND = 0x0000;

        public const uint PBT_APMQUERYSTANDBY = 0x0001;

        public const uint PBT_APMQUERYSUSPENDFAILED = 0x0002;

        public const uint PBT_APMQUERYSTANDBYFAILED = 0x0003;

        public const uint PBT_APMSUSPEND = 0x0004;

        public const uint PBT_APMSTANDBY = 0x0005;

        public const uint PBT_APMRESUMECRITICAL = 0x0006;

        public const uint PBT_APMRESUMESUSPEND = 0x0007;

        public const uint PBT_APMRESUMESTANDBY = 0x0008;

        public const uint PBTF_APMRESUMEFROMFAILURE = 0x00000001;

        public const uint PBT_APMBATTERYLOW = 0x0009;

        public const uint PBT_APMPOWERSTATUSCHANGE = 0x000A;

        public const uint PBT_APMOEMEVENT = 0x000B;

        public const uint PBT_APMRESUMEAUTOMATIC = 0x0012;

        public const uint PBT_POWERSETTINGCHANGE = 0x8013;

        public const uint WM_MDICREATE = 0x0220;

        public const uint WM_MDIDESTROY = 0x0221;

        public const uint WM_MDIACTIVATE = 0x0222;

        public const uint WM_MDIRESTORE = 0x0223;

        public const uint WM_MDINEXT = 0x0224;

        public const uint WM_MDIMAXIMIZE = 0x0225;

        public const uint WM_MDITILE = 0x0226;

        public const uint WM_MDICASCADE = 0x0227;

        public const uint WM_MDIICONARRANGE = 0x0228;

        public const uint WM_MDIGETACTIVE = 0x0229;

        public const uint WM_MDISETMENU = 0x0230;

        public const uint WM_ENTERSIZEMOVE = 0x0231;

        public const uint WM_EXITSIZEMOVE = 0x0232;

        public const uint WM_DROPFILES = 0x0233;

        public const uint WM_MDIREFRESHMENU = 0x0234;

        public const uint WM_POINTERDEVICECHANGE = 0x238;

        public const uint WM_POINTERDEVICEINRANGE = 0x239;

        public const uint WM_POINTERDEVICEOUTOFRANGE = 0x23A;

        public const uint WM_TOUCH = 0x0240;

        public const uint WM_NCPOINTERUPDATE = 0x0241;

        public const uint WM_NCPOINTERDOWN = 0x0242;

        public const uint WM_NCPOINTERUP = 0x0243;

        public const uint WM_POINTERUPDATE = 0x0245;

        public const uint WM_POINTERDOWN = 0x0246;

        public const uint WM_POINTERUP = 0x0247;

        public const uint WM_POINTERENTER = 0x0249;

        public const uint WM_POINTERLEAVE = 0x024A;

        public const uint WM_POINTERACTIVATE = 0x024B;

        public const uint WM_POINTERCAPTURECHANGED = 0x024C;

        public const uint WM_TOUCHHITTESTING = 0x024D;

        public const uint WM_POINTERWHEEL = 0x024E;

        public const uint WM_POINTERHWHEEL = 0x024F;

        public const uint DM_POINTERHITTEST = 0x0250;

        public const uint WM_POINTERROUTEDTO = 0x0251;

        public const uint WM_POINTERROUTEDAWAY = 0x0252;

        public const uint WM_POINTERROUTEDRELEASED = 0x0253;

        public const uint WM_IME_SETCONTEXT = 0x0281;

        public const uint WM_IME_NOTIFY = 0x0282;

        public const uint WM_IME_CONTROL = 0x0283;

        public const uint WM_IME_COMPOSITIONFULL = 0x0284;

        public const uint WM_IME_SELECT = 0x0285;

        public const uint WM_IME_CHAR = 0x0286;

        public const uint WM_IME_REQUEST = 0x0288;

        public const uint WM_IME_KEYDOWN = 0x0290;

        public const uint WM_IME_KEYUP = 0x0291;

        public const uint WM_NCMOUSEHOVER = 0x02A0;

        public const uint WM_NCMOUSELEAVE = 0x02A2;

        public const uint WM_WTSSESSION_CHANGE = 0x02B1;

        public const uint WM_TABLET_FIRST = 0x02c0;

        public const uint WM_TABLET_LAST = 0x02df;

        public const uint WM_DPICHANGED = 0x02E0;

        public const uint WM_DPICHANGED_BEFOREPARENT = 0x02E2;

        public const uint WM_DPICHANGED_AFTERPARENT = 0x02E3;

        public const uint WM_GETDPISCALEDSIZE = 0x02E4;

        public const uint WM_CUT = 0x0300;

        public const uint WM_COPY = 0x0301;

        public const uint WM_PASTE = 0x0302;

        public const uint WM_CLEAR = 0x0303;

        public const uint WM_UNDO = 0x0304;

        public const uint WM_RENDERFORMAT = 0x0305;

        public const uint WM_RENDERALLFORMATS = 0x0306;

        public const uint WM_DESTROYCLIPBOARD = 0x0307;

        public const uint WM_DRAWCLIPBOARD = 0x0308;

        public const uint WM_PAINTCLIPBOARD = 0x0309;

        public const uint WM_VSCROLLCLIPBOARD = 0x030A;

        public const uint WM_SIZECLIPBOARD = 0x030B;

        public const uint WM_ASKCBFORMATNAME = 0x030C;

        public const uint WM_CHANGECBCHAIN = 0x030D;

        public const uint WM_HSCROLLCLIPBOARD = 0x030E;

        public const uint WM_QUERYNEWPALETTE = 0x030F;

        public const uint WM_PALETTEISCHANGING = 0x0310;

        public const uint WM_PALETTECHANGED = 0x0311;

        public const uint WM_HOTKEY = 0x0312;

        public const uint WM_PRINT = 0x0317;

        public const uint WM_APPCOMMAND = 0x0319;

        public const uint WM_THEMECHANGED = 0x031A;

        public const uint WM_CLIPBOARDUPDATE = 0x031D;

        public const uint WM_DWMCOMPOSITIONCHANGED = 0x031E;

        public const uint WM_DWMNCRENDERINGCHANGED = 0x031F;

        public const uint WM_DWMCOLORIZATIONCOLORCHANGED = 0x0320;

        public const uint WM_DWMWINDOWMAXIMIZEDCHANGE = 0x0321;

        public const uint WM_DWMSENDICONICTHUMBNAIL = 0x0323;

        public const uint WM_DWMSENDICONICLIVEPREVIEWBITMAP = 0x0326;

        public const uint WM_GETTITLEBARINFOEX = 0x033F;

        public const uint WM_HANDHELDFIRST = 0x0358;

        public const uint WM_HANDHELDLAST = 0x035F;

        public const uint WM_AFXFIRST = 0x0360;

        public const uint WM_AFXLAST = 0x037F;

        public const uint WM_PENWINFIRST = 0x0380;

        public const uint WM_PENWINLAST = 0x038F;

        public const uint WM_APP = 0x8000;

        public const uint WM_USER = 0x0400;

        public const uint WMSZ_LEFT = 1;

        public const uint WMSZ_RIGHT = 2;

        public const uint WMSZ_TOP = 3;

        public const uint WMSZ_TOPLEFT = 4;

        public const uint WMSZ_TOPRIGHT = 5;

        public const uint WMSZ_BOTTOM = 6;

        public const uint WMSZ_BOTTOMLEFT = 7;

        public const uint WMSZ_BOTTOMRIGHT = 8;

        public const int HTERROR = -2;

        public const int HTTRANSPARENT = -1;

        public const uint HTNOWHERE = 0;

        public const uint HTCLIENT = 1;

        public const uint HTCAPTION = 2;

        public const uint HTSYSMENU = 3;

        public const uint HTGROWBOX = 4;

        public const uint HTMENU = 5;

        public const uint HTHSCROLL = 6;

        public const uint HTVSCROLL = 7;

        public const uint HTMINBUTTON = 8;

        public const uint HTMAXBUTTON = 9;

        public const uint HTLEFT = 10;

        public const uint HTRIGHT = 11;

        public const uint HTTOP = 12;

        public const uint HTTOPLEFT = 13;

        public const uint HTTOPRIGHT = 14;

        public const uint HTBOTTOM = 15;

        public const uint HTBOTTOMLEFT = 16;

        public const uint HTBOTTOMRIGHT = 17;

        public const uint HTBORDER = 18;

        public const uint HTOBJECT = 19;

        public const uint HTCLOSE = 20;

        public const uint HTHELP = 21;

        public const uint MA_ACTIVATE = 1;

        public const uint MA_ACTIVATEANDEAT = 2;

        public const uint MA_NOACTIVATE = 3;

        public const uint MA_NOACTIVATEANDEAT = 4;

        public const uint ICON_SMALL = 0;

        public const uint ICON_BIG = 1;

        public const uint ICON_SMALL2 = 2;

        public const uint SIZE_RESTORED = 0;

        public const uint SIZE_MINIMIZED = 1;

        public const uint SIZE_MAXIMIZED = 2;

        public const uint SIZE_MAXSHOW = 3;

        public const uint SIZE_MAXHIDE = 4;

        public const uint WVR_ALIGNTOP = 0x0010;

        public const uint WVR_ALIGNLEFT = 0x0020;

        public const uint WVR_ALIGNBOTTOM = 0x0040;

        public const uint WVR_ALIGNRIGHT = 0x0080;

        public const uint WVR_HREDRAW = 0x0100;

        public const uint WVR_VREDRAW = 0x0200;

        public const uint WVR_VALIDRECTS = 0x0400;

        public const uint MK_LBUTTON = 0x0001;

        public const uint MK_RBUTTON = 0x0002;

        public const uint MK_SHIFT = 0x0004;

        public const uint MK_CONTROL = 0x0008;

        public const uint MK_MBUTTON = 0x0010;

        public const uint MK_XBUTTON1 = 0x0020;

        public const uint MK_XBUTTON2 = 0x0040;

        public const int PRF_CHECKVISIBLE = 0x00000001;

        public const int PRF_NONCLIENT = 0x00000002;

        public const int PRF_CLIENT = 0x00000004;

        public const int PRF_ERASEBKGND = 0x00000008;

        public const int PRF_CHILDREN = 0x00000010;

        public const int PRF_OWNED = 0x00000020;

        public const uint IDANI_OPEN = 1;

        public const uint IDANI_CAPTION = 3;

        public const uint FVIRTKEY = 1;

        public const uint FNOINVERT = 0x02;

        public const uint FSHIFT = 0x04;

        public const uint FCONTROL = 0x08;

        public const uint FALT = 0x10;

        public const uint ODA_DRAWENTIRE = 0x0001;

        public const uint ODA_SELECT = 0x0002;

        public const uint ODA_FOCUS = 0x0004;

        public const uint ODS_SELECTED = 0x0001;

        public const uint ODS_GRAYED = 0x0002;

        public const uint ODS_DISABLED = 0x0004;

        public const uint ODS_CHECKED = 0x0008;

        public const uint ODS_FOCUS = 0x0010;

        public const uint ODS_DEFAULT = 0x0020;

        public const uint ODS_COMBOBOXEDIT = 0x1000;

        public const uint ODS_HOTLIGHT = 0x0040;

        public const uint ODS_INACTIVE = 0x0080;

        public const uint ODS_NOACCEL = 0x0100;

        public const uint ODS_NOFOCUSRECT = 0x0200;

        public const int IDHOT_SNAPWINDOW = -1;

        public const int IDHOT_SNAPDESKTOP = -2;

        public const uint ENDSESSION_CLOSEAPP = 0x00000001;

        public const uint ENDSESSION_CRITICAL = 0x40000000;

        public const uint ENDSESSION_LOGOFF = 0x80000000;

        public const uint EWX_FORCE = 0x00000004;

        public const uint EWX_FORCEIFHUNG = 0x00000010;

        public const uint EWX_QUICKRESOLVE = 0x00000020;

        public const uint EWX_BOOTOPTIONS = 0x01000000;

        public const uint EWX_ARSO = 0x04000000;

        public const uint BROADCAST_QUERY_DENY = 0x424D5144;

        public const uint DEVICE_NOTIFY_ALL_INTERFACE_CLASSES = 0x00000004;

        [NativeTypeName("HWND")]
        public const int HWND_MESSAGE = -3;

        public const uint ISMEX_NOSEND = 0x00000000;

        public const uint ISMEX_SEND = 0x00000001;

        public const uint ISMEX_NOTIFY = 0x00000002;

        public const uint ISMEX_CALLBACK = 0x00000004;

        public const uint ISMEX_REPLIED = 0x00000008;

        [NativeTypeName("HWND")]
        public const int HWND_DESKTOP = 0;

        public const uint PW_RENDERFULLCONTENT = 0x00000002;

        [NativeTypeName("HWND")]
        public const int HWND_TOP = 0;

        [NativeTypeName("HWND")]
        public const int HWND_BOTTOM = 1;

        [NativeTypeName("HWND")]
        public const int HWND_TOPMOST = -1;

        [NativeTypeName("HWND")]
        public const int HWND_NOTOPMOST = -2;

        public const uint DLGWINDOWEXTRA = 30;

        public const uint POINTER_MOD_SHIFT = 0x0004;

        public const uint POINTER_MOD_CTRL = 0x0008;

        public const uint TOUCH_FLAG_NONE = 0x00000000;

        public const uint TOUCH_MASK_NONE = 0x00000000;

        public const uint TOUCH_MASK_CONTACTAREA = 0x00000001;

        public const uint TOUCH_MASK_ORIENTATION = 0x00000002;

        public const uint TOUCH_MASK_PRESSURE = 0x00000004;

        public const uint PEN_FLAG_NONE = 0x00000000;

        public const uint PEN_FLAG_BARREL = 0x00000001;

        public const uint PEN_FLAG_INVERTED = 0x00000002;

        public const uint PEN_FLAG_ERASER = 0x00000004;

        public const uint PEN_MASK_NONE = 0x00000000;

        public const uint PEN_MASK_PRESSURE = 0x00000001;

        public const uint PEN_MASK_ROTATION = 0x00000002;

        public const uint PEN_MASK_TILT_X = 0x00000004;

        public const uint PEN_MASK_TILT_Y = 0x00000008;

        public const uint POINTER_MESSAGE_FLAG_NEW = 0x00000001;

        public const uint POINTER_MESSAGE_FLAG_INRANGE = 0x00000002;

        public const uint POINTER_MESSAGE_FLAG_INCONTACT = 0x00000004;

        public const uint POINTER_MESSAGE_FLAG_FIRSTBUTTON = 0x00000010;

        public const uint POINTER_MESSAGE_FLAG_SECONDBUTTON = 0x00000020;

        public const uint POINTER_MESSAGE_FLAG_THIRDBUTTON = 0x00000040;

        public const uint POINTER_MESSAGE_FLAG_FOURTHBUTTON = 0x00000080;

        public const uint POINTER_MESSAGE_FLAG_FIFTHBUTTON = 0x00000100;

        public const uint POINTER_MESSAGE_FLAG_PRIMARY = 0x00002000;

        public const uint POINTER_MESSAGE_FLAG_CONFIDENCE = 0x00004000;

        public const uint POINTER_MESSAGE_FLAG_CANCELED = 0x00008000;

        public const uint MAX_TOUCH_COUNT = 256;

        public const uint TOUCH_HIT_TESTING_DEFAULT = 0x0;

        public const uint TOUCH_HIT_TESTING_CLIENT = 0x1;

        public const uint TOUCH_HIT_TESTING_NONE = 0x2;

        public const uint TOUCH_HIT_TESTING_PROXIMITY_CLOSEST = 0x0;

        public const uint TOUCH_HIT_TESTING_PROXIMITY_FARTHEST = 0xFFF;

        public const uint GWFS_INCLUDE_ANCESTORS = 0x00000001;

        public const uint MAPVK_VK_TO_VSC = 0;

        public const uint MAPVK_VSC_TO_VK = 1;

        public const uint MAPVK_VK_TO_CHAR = 2;

        public const uint MAPVK_VSC_TO_VK_EX = 3;

        public const uint MAPVK_VK_TO_VSC_EX = 4;

        public const uint QS_TOUCH = 0x0800;

        public const uint QS_POINTER = 0x1000;

        public const uint USER_TIMER_MAXIMUM = 0x7FFFFFFF;

        public const uint USER_TIMER_MINIMUM = 0x0000000A;

        public const uint TIMERV_DEFAULT_COALESCING = 0;

        public const uint TIMERV_NO_COALESCING = 0xFFFFFFFF;

        public const uint TIMERV_COALESCING_MIN = 1;

        public const uint TIMERV_COALESCING_MAX = 0x7FFFFFF5;

        public const uint SM_RESERVED1 = 24;

        public const uint SM_RESERVED2 = 25;

        public const uint SM_RESERVED3 = 26;

        public const uint SM_RESERVED4 = 27;

        public const uint SM_CMETRICS = 76;

        public const uint SM_CARETBLINKINGENABLED = 0x2002;

        public const uint SM_SYSTEMDOCKED = 0x2004;

        public const uint PMB_ACTIVE = 0x00000001;

        public const uint MNC_IGNORE = 0;

        public const uint MNC_CLOSE = 1;

        public const uint MNC_EXECUTE = 2;

        public const uint MNC_SELECT = 3;

        public const uint MND_CONTINUE = 0;

        public const uint MND_ENDMENU = 1;

        public const uint MNGO_NOINTERFACE = 0x00000000;

        public const uint MNGO_NOERROR = 0x00000001;

        public const uint DOF_EXECUTABLE = 0x8001;

        public const uint DOF_DOCUMENT = 0x8002;

        public const uint DOF_DIRECTORY = 0x8003;

        public const uint DOF_MULTIPLE = 0x8004;

        public const uint DOF_PROGMAN = 0x0001;

        public const uint DOF_SHELLDATA = 0x0002;

        public const int DO_DROPFILE = 0x454C4946;

        public const int DO_PRINTFILE = 0x544E5250;

        public const uint ASFW_ANY = 0xFFFFFFFF;

        public const int DCX_EXCLUDEUPDATE = 0x00000100;

        public const uint HELPINFO_WINDOW = 0x0001;

        public const uint HELPINFO_MENUITEM = 0x0002;

        public const uint CTLCOLOR_MSGBOX = 0;

        public const uint CTLCOLOR_EDIT = 1;

        public const uint CTLCOLOR_LISTBOX = 2;

        public const uint CTLCOLOR_BTN = 3;

        public const uint CTLCOLOR_DLG = 4;

        public const uint CTLCOLOR_SCROLLBAR = 5;

        public const uint CTLCOLOR_STATIC = 6;

        public const uint CTLCOLOR_MAX = 7;

        public const uint COLOR_BTNHIGHLIGHT = 20;

        public const uint GW_MAX = 5;

        public const uint SC_SIZE = 0xF000;

        public const uint SC_MOVE = 0xF010;

        public const uint SC_MINIMIZE = 0xF020;

        public const uint SC_MAXIMIZE = 0xF030;

        public const uint SC_NEXTWINDOW = 0xF040;

        public const uint SC_PREVWINDOW = 0xF050;

        public const uint SC_CLOSE = 0xF060;

        public const uint SC_VSCROLL = 0xF070;

        public const uint SC_HSCROLL = 0xF080;

        public const uint SC_MOUSEMENU = 0xF090;

        public const uint SC_KEYMENU = 0xF100;

        public const uint SC_ARRANGE = 0xF110;

        public const uint SC_RESTORE = 0xF120;

        public const uint SC_TASKLIST = 0xF130;

        public const uint SC_SCREENSAVE = 0xF140;

        public const uint SC_HOTKEY = 0xF150;

        public const uint SC_DEFAULT = 0xF160;

        public const uint SC_MONITORPOWER = 0xF170;

        public const uint SC_CONTEXTHELP = 0xF180;

        public const uint SC_SEPARATOR = 0xF00F;

        public const uint SCF_ISSECURE = 0x00000001;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_ARROW = 32512;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_IBEAM = 32513;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_WAIT = 32514;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_CROSS = 32515;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_UPARROW = 32516;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZE = 32640;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_ICON = 32641;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZENWSE = 32642;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZENESW = 32643;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZEWE = 32644;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZENS = 32645;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_SIZEALL = 32646;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_NO = 32648;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_HAND = 32649;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_APPSTARTING = 32650;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_HELP = 32651;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_PIN = 32671;

        [NativeTypeName("LPCWSTR")]
        public const int IDC_PERSON = 32672;

        public const uint IMAGE_ENHMETAFILE = 3;

        public const uint LR_COLOR = 0x00000002;

        public const uint RES_ICON = 1;

        public const uint RES_CURSOR = 2;

        public const uint OBM_CLOSE = 32754;

        public const uint OBM_UPARROW = 32753;

        public const uint OBM_DNARROW = 32752;

        public const uint OBM_RGARROW = 32751;

        public const uint OBM_LFARROW = 32750;

        public const uint OBM_REDUCE = 32749;

        public const uint OBM_ZOOM = 32748;

        public const uint OBM_RESTORE = 32747;

        public const uint OBM_REDUCED = 32746;

        public const uint OBM_ZOOMD = 32745;

        public const uint OBM_RESTORED = 32744;

        public const uint OBM_UPARROWD = 32743;

        public const uint OBM_DNARROWD = 32742;

        public const uint OBM_RGARROWD = 32741;

        public const uint OBM_LFARROWD = 32740;

        public const uint OBM_MNARROW = 32739;

        public const uint OBM_COMBO = 32738;

        public const uint OBM_UPARROWI = 32737;

        public const uint OBM_DNARROWI = 32736;

        public const uint OBM_RGARROWI = 32735;

        public const uint OBM_LFARROWI = 32734;

        public const uint OBM_OLD_CLOSE = 32767;

        public const uint OBM_SIZE = 32766;

        public const uint OBM_OLD_UPARROW = 32765;

        public const uint OBM_OLD_DNARROW = 32764;

        public const uint OBM_OLD_RGARROW = 32763;

        public const uint OBM_OLD_LFARROW = 32762;

        public const uint OBM_BTSIZE = 32761;

        public const uint OBM_CHECK = 32760;

        public const uint OBM_CHECKBOXES = 32759;

        public const uint OBM_BTNCORNERS = 32758;

        public const uint OBM_OLD_REDUCE = 32757;

        public const uint OBM_OLD_ZOOM = 32756;

        public const uint OBM_OLD_RESTORE = 32755;

        public const uint OCR_SIZE = 32640;

        public const uint OCR_ICON = 32641;

        public const uint OCR_ICOCUR = 32647;

        public const uint OIC_SAMPLE = 32512;

        public const uint OIC_HAND = 32513;

        public const uint OIC_QUES = 32514;

        public const uint OIC_BANG = 32515;

        public const uint OIC_NOTE = 32516;

        public const uint OIC_WINLOGO = 32517;

        public const uint OIC_SHIELD = 32518;

        public const uint ORD_LANGDRIVER = 1;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_APPLICATION = 32512;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_HAND = 32513;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_QUESTION = 32514;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_EXCLAMATION = 32515;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_ASTERISK = 32516;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_WINLOGO = 32517;

        [NativeTypeName("LPCWSTR")]
        public const uint IDI_SHIELD = 32518;

        public const int ES_LEFT = 0x0000;

        public const int ES_CENTER = 0x0001;

        public const int ES_RIGHT = 0x0002;

        public const int ES_MULTILINE = 0x0004;

        public const int ES_UPPERCASE = 0x0008;

        public const int ES_LOWERCASE = 0x0010;

        public const int ES_PASSWORD = 0x0020;

        public const int ES_AUTOVSCROLL = 0x0040;

        public const int ES_AUTOHSCROLL = 0x0080;

        public const int ES_NOHIDESEL = 0x0100;

        public const int ES_OEMCONVERT = 0x0400;

        public const int ES_READONLY = 0x0800;

        public const int ES_WANTRETURN = 0x1000;

        public const int ES_NUMBER = 0x2000;

        public const uint EN_SETFOCUS = 0x0100;

        public const uint EN_KILLFOCUS = 0x0200;

        public const uint EN_CHANGE = 0x0300;

        public const uint EN_UPDATE = 0x0400;

        public const uint EN_ERRSPACE = 0x0500;

        public const uint EN_MAXTEXT = 0x0501;

        public const uint EN_HSCROLL = 0x0601;

        public const uint EN_VSCROLL = 0x0602;

        public const uint EN_ALIGN_LTR_EC = 0x0700;

        public const uint EN_ALIGN_RTL_EC = 0x0701;

        public const uint EN_BEFORE_PASTE = 0x0800;

        public const uint EN_AFTER_PASTE = 0x0801;

        public const uint EC_LEFTMARGIN = 0x0001;

        public const uint EC_RIGHTMARGIN = 0x0002;

        public const uint EC_USEFONTINFO = 0xffff;

        public const uint EMSIS_COMPOSITIONSTRING = 0x0001;

        public const uint EIMES_GETCOMPSTRATONCE = 0x0001;

        public const uint EIMES_CANCELCOMPSTRINFOCUS = 0x0002;

        public const uint EIMES_COMPLETECOMPSTRKILLFOCUS = 0x0004;

        public const int BS_PUSHBUTTON = 0x00000000;

        public const int BS_DEFPUSHBUTTON = 0x00000001;

        public const int BS_CHECKBOX = 0x00000002;

        public const int BS_AUTOCHECKBOX = 0x00000003;

        public const int BS_RADIOBUTTON = 0x00000004;

        public const int BS_3STATE = 0x00000005;

        public const int BS_AUTO3STATE = 0x00000006;

        public const int BS_GROUPBOX = 0x00000007;

        public const int BS_USERBUTTON = 0x00000008;

        public const int BS_AUTORADIOBUTTON = 0x00000009;

        public const int BS_PUSHBOX = 0x0000000A;

        public const int BS_OWNERDRAW = 0x0000000B;

        public const int BS_TYPEMASK = 0x0000000F;

        public const int BS_LEFTTEXT = 0x00000020;

        public const int BS_TEXT = 0x00000000;

        public const int BS_ICON = 0x00000040;

        public const int BS_BITMAP = 0x00000080;

        public const int BS_LEFT = 0x00000100;

        public const int BS_RIGHT = 0x00000200;

        public const int BS_CENTER = 0x00000300;

        public const int BS_TOP = 0x00000400;

        public const int BS_BOTTOM = 0x00000800;

        public const int BS_VCENTER = 0x00000C00;

        public const int BS_PUSHLIKE = 0x00001000;

        public const int BS_MULTILINE = 0x00002000;

        public const int BS_NOTIFY = 0x00004000;

        public const int BS_FLAT = 0x00008000;

        public const uint BN_CLICKED = 0;

        public const uint BN_PAINT = 1;

        public const uint BN_HILITE = 2;

        public const uint BN_UNHILITE = 3;

        public const uint BN_DISABLE = 4;

        public const uint BN_DOUBLECLICKED = 5;

        public const uint BN_SETFOCUS = 6;

        public const uint BN_KILLFOCUS = 7;

        public const uint BM_GETCHECK = 0x00F0;

        public const uint BM_SETCHECK = 0x00F1;

        public const uint BM_GETSTATE = 0x00F2;

        public const uint BM_SETSTATE = 0x00F3;

        public const uint BM_SETSTYLE = 0x00F4;

        public const uint BM_CLICK = 0x00F5;

        public const uint BM_GETIMAGE = 0x00F6;

        public const uint BM_SETIMAGE = 0x00F7;

        public const uint BM_SETDONTCLICK = 0x00F8;

        public const uint BST_PUSHED = 0x0004;

        public const uint BST_FOCUS = 0x0008;

        public const int SS_LEFT = 0x00000000;

        public const int SS_CENTER = 0x00000001;

        public const int SS_RIGHT = 0x00000002;

        public const int SS_ICON = 0x00000003;

        public const int SS_BLACKRECT = 0x00000004;

        public const int SS_GRAYRECT = 0x00000005;

        public const int SS_WHITERECT = 0x00000006;

        public const int SS_BLACKFRAME = 0x00000007;

        public const int SS_GRAYFRAME = 0x00000008;

        public const int SS_WHITEFRAME = 0x00000009;

        public const int SS_USERITEM = 0x0000000A;

        public const int SS_SIMPLE = 0x0000000B;

        public const int SS_LEFTNOWORDWRAP = 0x0000000C;

        public const int SS_OWNERDRAW = 0x0000000D;

        public const int SS_BITMAP = 0x0000000E;

        public const int SS_ENHMETAFILE = 0x0000000F;

        public const int SS_ETCHEDHORZ = 0x00000010;

        public const int SS_ETCHEDVERT = 0x00000011;

        public const int SS_ETCHEDFRAME = 0x00000012;

        public const int SS_TYPEMASK = 0x0000001F;

        public const int SS_REALSIZECONTROL = 0x00000040;

        public const int SS_NOPREFIX = 0x00000080;

        public const int SS_NOTIFY = 0x00000100;

        public const int SS_CENTERIMAGE = 0x00000200;

        public const int SS_RIGHTJUST = 0x00000400;

        public const int SS_REALSIZEIMAGE = 0x00000800;

        public const int SS_SUNKEN = 0x00001000;

        public const int SS_EDITCONTROL = 0x00002000;

        public const int SS_ENDELLIPSIS = 0x00004000;

        public const int SS_PATHELLIPSIS = 0x00008000;

        public const int SS_WORDELLIPSIS = 0x0000C000;

        public const int SS_ELLIPSISMASK = 0x0000C000;

        public const uint STM_SETICON = 0x0170;

        public const uint STM_GETICON = 0x0171;

        public const uint STM_SETIMAGE = 0x0172;

        public const uint STM_GETIMAGE = 0x0173;

        public const uint STN_CLICKED = 0;

        public const uint STN_DBLCLK = 1;

        public const uint STN_ENABLE = 2;

        public const uint STN_DISABLE = 3;

        public const uint STM_MSGMAX = 0x0174;

        public const uint DWL_MSGRESULT = 0;

        public const uint DWL_DLGPROC = 4;

        public const uint DWL_USER = 8;

        public const uint DWLP_MSGRESULT = 0;

        public const int DS_ABSALIGN = 0x01;

        public const int DS_SYSMODAL = 0x02;

        public const int DS_LOCALEDIT = 0x20;

        public const int DS_SETFONT = 0x40;

        public const int DS_MODALFRAME = 0x80;

        public const int DS_NOIDLEMSG = 0x100;

        public const int DS_SETFOREGROUND = 0x200;

        public const int DS_3DLOOK = 0x0004;

        public const int DS_FIXEDSYS = 0x0008;

        public const int DS_NOFAILCREATE = 0x0010;

        public const int DS_CONTROL = 0x0400;

        public const int DS_CENTER = 0x0800;

        public const int DS_CENTERMOUSE = 0x1000;

        public const int DS_CONTEXTHELP = 0x2000;

        public const int DS_USEPIXELS = 0x8000;

        public const uint DM_GETDEFID = WM_USER+0;

        public const uint DM_SETDEFID = WM_USER+1;

        public const uint DM_REPOSITION = WM_USER+2;

        public const uint DC_HASDEFID = 0x534B;

        public const uint DLGC_WANTARROWS = 0x0001;

        public const uint DLGC_WANTTAB = 0x0002;

        public const uint DLGC_WANTALLKEYS = 0x0004;

        public const uint DLGC_WANTMESSAGE = 0x0004;

        public const uint DLGC_HASSETSEL = 0x0008;

        public const uint DLGC_DEFPUSHBUTTON = 0x0010;

        public const uint DLGC_UNDEFPUSHBUTTON = 0x0020;

        public const uint DLGC_RADIOBUTTON = 0x0040;

        public const uint DLGC_WANTCHARS = 0x0080;

        public const uint DLGC_STATIC = 0x0100;

        public const uint DLGC_BUTTON = 0x2000;

        public const int LB_CTLCODE = 0;

        public const uint LB_OKAY = 0;

        public const int LB_ERR = -1;

        public const int LB_ERRSPACE = -2;

        public const int LBN_ERRSPACE = -2;

        public const uint LBN_SELCHANGE = 1;

        public const uint LBN_DBLCLK = 2;

        public const uint LBN_SELCANCEL = 3;

        public const uint LBN_SETFOCUS = 4;

        public const uint LBN_KILLFOCUS = 5;

        public const uint LB_ADDSTRING = 0x0180;

        public const uint LB_INSERTSTRING = 0x0181;

        public const uint LB_DELETESTRING = 0x0182;

        public const uint LB_SELITEMRANGEEX = 0x0183;

        public const uint LB_RESETCONTENT = 0x0184;

        public const uint LB_SETSEL = 0x0185;

        public const uint LB_SETCURSEL = 0x0186;

        public const uint LB_GETSEL = 0x0187;

        public const uint LB_GETCURSEL = 0x0188;

        public const uint LB_GETTEXT = 0x0189;

        public const uint LB_GETTEXTLEN = 0x018A;

        public const uint LB_GETCOUNT = 0x018B;

        public const uint LB_SELECTSTRING = 0x018C;

        public const uint LB_DIR = 0x018D;

        public const uint LB_GETTOPINDEX = 0x018E;

        public const uint LB_FINDSTRING = 0x018F;

        public const uint LB_GETSELCOUNT = 0x0190;

        public const uint LB_GETSELITEMS = 0x0191;

        public const uint LB_SETTABSTOPS = 0x0192;

        public const uint LB_GETHORIZONTALEXTENT = 0x0193;

        public const uint LB_SETHORIZONTALEXTENT = 0x0194;

        public const uint LB_SETCOLUMNWIDTH = 0x0195;

        public const uint LB_ADDFILE = 0x0196;

        public const uint LB_SETTOPINDEX = 0x0197;

        public const uint LB_GETITEMRECT = 0x0198;

        public const uint LB_GETITEMDATA = 0x0199;

        public const uint LB_SETITEMDATA = 0x019A;

        public const uint LB_SELITEMRANGE = 0x019B;

        public const uint LB_SETANCHORINDEX = 0x019C;

        public const uint LB_GETANCHORINDEX = 0x019D;

        public const uint LB_SETCARETINDEX = 0x019E;

        public const uint LB_GETCARETINDEX = 0x019F;

        public const uint LB_SETITEMHEIGHT = 0x01A0;

        public const uint LB_GETITEMHEIGHT = 0x01A1;

        public const uint LB_FINDSTRINGEXACT = 0x01A2;

        public const uint LB_SETLOCALE = 0x01A5;

        public const uint LB_GETLOCALE = 0x01A6;

        public const uint LB_SETCOUNT = 0x01A7;

        public const uint LB_INITSTORAGE = 0x01A8;

        public const uint LB_ITEMFROMPOINT = 0x01A9;

        public const uint LB_MULTIPLEADDSTRING = 0x01B1;

        public const uint LB_GETLISTBOXINFO = 0x01B2;

        public const uint LB_MSGMAX = 0x01B3;

        public const int LBS_NOTIFY = 0x0001;

        public const int LBS_SORT = 0x0002;

        public const int LBS_NOREDRAW = 0x0004;

        public const int LBS_MULTIPLESEL = 0x0008;

        public const int LBS_OWNERDRAWFIXED = 0x0010;

        public const int LBS_OWNERDRAWVARIABLE = 0x0020;

        public const int LBS_HASSTRINGS = 0x0040;

        public const int LBS_USETABSTOPS = 0x0080;

        public const int LBS_NOINTEGRALHEIGHT = 0x0100;

        public const int LBS_MULTICOLUMN = 0x0200;

        public const int LBS_WANTKEYBOARDINPUT = 0x0400;

        public const int LBS_EXTENDEDSEL = 0x0800;

        public const int LBS_DISABLENOSCROLL = 0x1000;

        public const int LBS_NODATA = 0x2000;

        public const int LBS_NOSEL = 0x4000;

        public const int LBS_COMBOBOX = 0x8000;

        public const uint CB_OKAY = 0;

        public const int CB_ERR = -1;

        public const int CB_ERRSPACE = -2;

        public const int CBN_ERRSPACE = -1;

        public const uint CBN_SELCHANGE = 1;

        public const uint CBN_DBLCLK = 2;

        public const uint CBN_SETFOCUS = 3;

        public const uint CBN_KILLFOCUS = 4;

        public const uint CBN_EDITCHANGE = 5;

        public const uint CBN_EDITUPDATE = 6;

        public const uint CBN_DROPDOWN = 7;

        public const uint CBN_CLOSEUP = 8;

        public const uint CBN_SELENDOK = 9;

        public const uint CBN_SELENDCANCEL = 10;

        public const int CBS_SIMPLE = 0x0001;

        public const int CBS_DROPDOWN = 0x0002;

        public const int CBS_DROPDOWNLIST = 0x0003;

        public const int CBS_OWNERDRAWFIXED = 0x0010;

        public const int CBS_OWNERDRAWVARIABLE = 0x0020;

        public const int CBS_AUTOHSCROLL = 0x0040;

        public const int CBS_OEMCONVERT = 0x0080;

        public const int CBS_SORT = 0x0100;

        public const int CBS_HASSTRINGS = 0x0200;

        public const int CBS_NOINTEGRALHEIGHT = 0x0400;

        public const int CBS_DISABLENOSCROLL = 0x0800;

        public const int CBS_UPPERCASE = 0x2000;

        public const int CBS_LOWERCASE = 0x4000;

        public const uint CB_GETEDITSEL = 0x0140;

        public const uint CB_LIMITTEXT = 0x0141;

        public const uint CB_SETEDITSEL = 0x0142;

        public const uint CB_ADDSTRING = 0x0143;

        public const uint CB_DELETESTRING = 0x0144;

        public const uint CB_DIR = 0x0145;

        public const uint CB_GETCOUNT = 0x0146;

        public const uint CB_GETCURSEL = 0x0147;

        public const uint CB_GETLBTEXT = 0x0148;

        public const uint CB_GETLBTEXTLEN = 0x0149;

        public const uint CB_INSERTSTRING = 0x014A;

        public const uint CB_RESETCONTENT = 0x014B;

        public const uint CB_FINDSTRING = 0x014C;

        public const uint CB_SELECTSTRING = 0x014D;

        public const uint CB_SETCURSEL = 0x014E;

        public const uint CB_SHOWDROPDOWN = 0x014F;

        public const uint CB_GETITEMDATA = 0x0150;

        public const uint CB_SETITEMDATA = 0x0151;

        public const uint CB_GETDROPPEDCONTROLRECT = 0x0152;

        public const uint CB_SETITEMHEIGHT = 0x0153;

        public const uint CB_GETITEMHEIGHT = 0x0154;

        public const uint CB_SETEXTENDEDUI = 0x0155;

        public const uint CB_GETEXTENDEDUI = 0x0156;

        public const uint CB_GETDROPPEDSTATE = 0x0157;

        public const uint CB_FINDSTRINGEXACT = 0x0158;

        public const uint CB_SETLOCALE = 0x0159;

        public const uint CB_GETLOCALE = 0x015A;

        public const uint CB_GETTOPINDEX = 0x015b;

        public const uint CB_SETTOPINDEX = 0x015c;

        public const uint CB_GETHORIZONTALEXTENT = 0x015d;

        public const uint CB_SETHORIZONTALEXTENT = 0x015e;

        public const uint CB_GETDROPPEDWIDTH = 0x015f;

        public const uint CB_SETDROPPEDWIDTH = 0x0160;

        public const uint CB_INITSTORAGE = 0x0161;

        public const uint CB_MULTIPLEADDSTRING = 0x0163;

        public const uint CB_GETCOMBOBOXINFO = 0x0164;

        public const uint CB_MSGMAX = 0x0165;

        public const int SBS_HORZ = 0x0000;

        public const int SBS_VERT = 0x0001;

        public const int SBS_TOPALIGN = 0x0002;

        public const int SBS_LEFTALIGN = 0x0002;

        public const int SBS_BOTTOMALIGN = 0x0004;

        public const int SBS_RIGHTALIGN = 0x0004;

        public const int SBS_SIZEBOXTOPLEFTALIGN = 0x0002;

        public const int SBS_SIZEBOXBOTTOMRIGHTALIGN = 0x0004;

        public const int SBS_SIZEBOX = 0x0008;

        public const int SBS_SIZEGRIP = 0x0010;

        public const uint SBM_SETPOS = 0x00E0;

        public const uint SBM_GETPOS = 0x00E1;

        public const uint SBM_SETRANGE = 0x00E2;

        public const uint SBM_SETRANGEREDRAW = 0x00E6;

        public const uint SBM_GETRANGE = 0x00E3;

        public const uint SBM_ENABLE_ARROWS = 0x00E4;

        public const uint SBM_SETSCROLLINFO = 0x00E9;

        public const uint SBM_GETSCROLLINFO = 0x00EA;

        public const uint SBM_GETSCROLLBARINFO = 0x00EB;

        public const uint MDIS_ALLCHILDSTYLES = 0x0001;

        public const int HELP_CONTEXT = 0x0001;

        public const int HELP_QUIT = 0x0002;

        public const int HELP_INDEX = 0x0003;

        public const int HELP_CONTENTS = 0x0003;

        public const int HELP_HELPONHELP = 0x0004;

        public const int HELP_SETINDEX = 0x0005;

        public const int HELP_SETCONTENTS = 0x0005;

        public const int HELP_CONTEXTPOPUP = 0x0008;

        public const int HELP_FORCEFILE = 0x0009;

        public const int HELP_KEY = 0x0101;

        public const int HELP_COMMAND = 0x0102;

        public const int HELP_PARTIALKEY = 0x0105;

        public const int HELP_MULTIKEY = 0x0201;

        public const int HELP_SETWINPOS = 0x0203;

        public const uint HELP_CONTEXTMENU = 0x000a;

        public const uint HELP_FINDER = 0x000b;

        public const uint HELP_WM_HELP = 0x000c;

        public const uint HELP_SETPOPUP_POS = 0x000d;

        public const uint HELP_TCARD = 0x8000;

        public const uint HELP_TCARD_DATA = 0x0010;

        public const uint HELP_TCARD_OTHER_CALLER = 0x0011;

        public const uint IDH_NO_HELP = 28440;

        public const uint IDH_MISSING_CONTEXT = 28441;

        public const uint IDH_GENERIC_HELP_BUTTON = 28442;

        public const uint IDH_OK = 28443;

        public const uint IDH_CANCEL = 28444;

        public const uint IDH_HELP = 28445;

        public const uint MAX_TOUCH_PREDICTION_FILTER_TAPS = 3;

        public const uint TOUCHPREDICTIONPARAMETERS_DEFAULT_LATENCY = 8;

        public const uint TOUCHPREDICTIONPARAMETERS_DEFAULT_SAMPLETIME = 8;

        public const uint TOUCHPREDICTIONPARAMETERS_DEFAULT_USE_HW_TIMESTAMP = 1;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_DELTA = 0.001f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MIN = 0.9f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_MAX = 0.999f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_LAMBDA_LEARNING_RATE = 0.001f;

        public const float TOUCHPREDICTIONPARAMETERS_DEFAULT_RLS_EXPO_SMOOTH_ALPHA = 0.99f;

        public const uint MAX_LOGICALDPIOVERRIDE = 2;

        public const int MIN_LOGICALDPIOVERRIDE = -2;

        public const uint FE_FONTSMOOTHINGSTANDARD = 0x0001;

        public const uint FE_FONTSMOOTHINGCLEARTYPE = 0x0002;

        public const uint FE_FONTSMOOTHINGORIENTATIONBGR = 0x0000;

        public const uint FE_FONTSMOOTHINGORIENTATIONRGB = 0x0001;

        public const uint CONTACTVISUALIZATION_OFF = 0x0000;

        public const uint CONTACTVISUALIZATION_ON = 0x0001;

        public const uint CONTACTVISUALIZATION_PRESENTATIONMODE = 0x0002;

        public const uint GESTUREVISUALIZATION_OFF = 0x0000;

        public const uint GESTUREVISUALIZATION_ON = 0x001F;

        public const uint GESTUREVISUALIZATION_TAP = 0x0001;

        public const uint GESTUREVISUALIZATION_DOUBLETAP = 0x0002;

        public const uint GESTUREVISUALIZATION_PRESSANDTAP = 0x0004;

        public const uint GESTUREVISUALIZATION_PRESSANDHOLD = 0x0008;

        public const uint GESTUREVISUALIZATION_RIGHTTAP = 0x0010;

        public const uint MOUSEWHEEL_ROUTING_FOCUS = 0;

        public const uint MOUSEWHEEL_ROUTING_HYBRID = 1;

        public const uint MOUSEWHEEL_ROUTING_MOUSE_POS = 2;

        public const uint PENVISUALIZATION_ON = 0x0023;

        public const uint PENVISUALIZATION_OFF = 0x0000;

        public const uint PENVISUALIZATION_TAP = 0x0001;

        public const uint PENVISUALIZATION_DOUBLETAP = 0x0002;

        public const uint PENVISUALIZATION_CURSOR = 0x0020;

        public const uint PENARBITRATIONTYPE_NONE = 0x0000;

        public const uint PENARBITRATIONTYPE_WIN8 = 0x0001;

        public const uint PENARBITRATIONTYPE_FIS = 0x0002;

        public const uint PENARBITRATIONTYPE_SPT = 0x0003;

        public const uint PENARBITRATIONTYPE_MAX = 0x0004;

        public const int METRICS_USEDEFAULT = -1;

        public const int ARW_STARTMASK = 0x0003;

        public const int ARW_STARTRIGHT = 0x0001;

        public const int ARW_STARTTOP = 0x0002;

        public const int ARW_LEFT = 0x0000;

        public const int ARW_RIGHT = 0x0000;

        public const int ARW_UP = 0x0004;

        public const int ARW_DOWN = 0x0004;

        public const int ARW_HIDE = 0x0008;

        public const uint HCF_LOGONDESKTOP = 0x00000100;

        public const uint HCF_DEFAULTDESKTOP = 0x00000200;

        public const uint EDS_RAWMODE = 0x00000002;

        public const uint EDS_ROTATEDMODE = 0x00000004;

        public const uint EDD_GET_DEVICE_INTERFACE_NAME = 0x00000001;

        public const uint FKF_FILTERKEYSON = 0x00000001;

        public const uint FKF_AVAILABLE = 0x00000002;

        public const uint FKF_HOTKEYACTIVE = 0x00000004;

        public const uint FKF_CONFIRMHOTKEY = 0x00000008;

        public const uint FKF_HOTKEYSOUND = 0x00000010;

        public const uint FKF_INDICATOR = 0x00000020;

        public const uint FKF_CLICKON = 0x00000040;

        public const uint MKF_MOUSEKEYSON = 0x00000001;

        public const uint MKF_AVAILABLE = 0x00000002;

        public const uint MKF_HOTKEYACTIVE = 0x00000004;

        public const uint MKF_CONFIRMHOTKEY = 0x00000008;

        public const uint MKF_HOTKEYSOUND = 0x00000010;

        public const uint MKF_INDICATOR = 0x00000020;

        public const uint MKF_MODIFIERS = 0x00000040;

        public const uint MKF_REPLACENUMBERS = 0x00000080;

        public const uint MKF_LEFTBUTTONSEL = 0x10000000;

        public const uint MKF_RIGHTBUTTONSEL = 0x20000000;

        public const uint MKF_LEFTBUTTONDOWN = 0x01000000;

        public const uint MKF_RIGHTBUTTONDOWN = 0x02000000;

        public const uint MKF_MOUSEMODE = 0x80000000;

        public const uint TKF_TOGGLEKEYSON = 0x00000001;

        public const uint TKF_AVAILABLE = 0x00000002;

        public const uint TKF_HOTKEYACTIVE = 0x00000004;

        public const uint TKF_CONFIRMHOTKEY = 0x00000008;

        public const uint TKF_HOTKEYSOUND = 0x00000010;

        public const uint TKF_INDICATOR = 0x00000020;

        public const uint MONITORINFOF_PRIMARY = 0x00000001;

        public const uint WINEVENT_OUTOFCONTEXT = 0x0000;

        public const uint WINEVENT_SKIPOWNTHREAD = 0x0001;

        public const uint WINEVENT_SKIPOWNPROCESS = 0x0002;

        public const uint WINEVENT_INCONTEXT = 0x0004;

        public const uint CHILDID_SELF = 0;

        public const uint INDEXID_OBJECT = 0;

        public const uint INDEXID_CONTAINER = 0;

        public const uint EVENT_MIN = 0x00000001;

        public const uint EVENT_MAX = 0x7FFFFFFF;

        public const uint EVENT_SYSTEM_SOUND = 0x0001;

        public const uint EVENT_SYSTEM_ALERT = 0x0002;

        public const uint EVENT_SYSTEM_FOREGROUND = 0x0003;

        public const uint EVENT_SYSTEM_MENUSTART = 0x0004;

        public const uint EVENT_SYSTEM_MENUEND = 0x0005;

        public const uint EVENT_SYSTEM_MENUPOPUPSTART = 0x0006;

        public const uint EVENT_SYSTEM_MENUPOPUPEND = 0x0007;

        public const uint EVENT_SYSTEM_CAPTURESTART = 0x0008;

        public const uint EVENT_SYSTEM_CAPTUREEND = 0x0009;

        public const uint EVENT_SYSTEM_MOVESIZESTART = 0x000A;

        public const uint EVENT_SYSTEM_MOVESIZEEND = 0x000B;

        public const uint EVENT_SYSTEM_CONTEXTHELPSTART = 0x000C;

        public const uint EVENT_SYSTEM_CONTEXTHELPEND = 0x000D;

        public const uint EVENT_SYSTEM_DRAGDROPSTART = 0x000E;

        public const uint EVENT_SYSTEM_DRAGDROPEND = 0x000F;

        public const uint EVENT_SYSTEM_DIALOGSTART = 0x0010;

        public const uint EVENT_SYSTEM_DIALOGEND = 0x0011;

        public const uint EVENT_SYSTEM_SCROLLINGSTART = 0x0012;

        public const uint EVENT_SYSTEM_SCROLLINGEND = 0x0013;

        public const uint EVENT_SYSTEM_SWITCHSTART = 0x0014;

        public const uint EVENT_SYSTEM_SWITCHEND = 0x0015;

        public const uint EVENT_SYSTEM_MINIMIZESTART = 0x0016;

        public const uint EVENT_SYSTEM_MINIMIZEEND = 0x0017;

        public const uint EVENT_SYSTEM_DESKTOPSWITCH = 0x0020;

        public const uint EVENT_SYSTEM_SWITCHER_APPGRABBED = 0x0024;

        public const uint EVENT_SYSTEM_SWITCHER_APPOVERTARGET = 0x0025;

        public const uint EVENT_SYSTEM_SWITCHER_APPDROPPED = 0x0026;

        public const uint EVENT_SYSTEM_SWITCHER_CANCELLED = 0x0027;

        public const uint EVENT_SYSTEM_IME_KEY_NOTIFICATION = 0x0029;

        public const uint EVENT_SYSTEM_END = 0x00FF;

        public const uint EVENT_OEM_DEFINED_START = 0x0101;

        public const uint EVENT_OEM_DEFINED_END = 0x01FF;

        public const uint EVENT_UIA_EVENTID_START = 0x4E00;

        public const uint EVENT_UIA_EVENTID_END = 0x4EFF;

        public const uint EVENT_UIA_PROPID_START = 0x7500;

        public const uint EVENT_UIA_PROPID_END = 0x75FF;

        public const uint EVENT_CONSOLE_CARET = 0x4001;

        public const uint EVENT_CONSOLE_UPDATE_REGION = 0x4002;

        public const uint EVENT_CONSOLE_UPDATE_SIMPLE = 0x4003;

        public const uint EVENT_CONSOLE_UPDATE_SCROLL = 0x4004;

        public const uint EVENT_CONSOLE_LAYOUT = 0x4005;

        public const uint EVENT_CONSOLE_START_APPLICATION = 0x4006;

        public const uint EVENT_CONSOLE_END_APPLICATION = 0x4007;

        public const uint CONSOLE_APPLICATION_16BIT = 0x0000;

        public const uint CONSOLE_CARET_SELECTION = 0x0001;

        public const uint CONSOLE_CARET_VISIBLE = 0x0002;

        public const uint EVENT_CONSOLE_END = 0x40FF;

        public const uint EVENT_OBJECT_CREATE = 0x8000;

        public const uint EVENT_OBJECT_DESTROY = 0x8001;

        public const uint EVENT_OBJECT_SHOW = 0x8002;

        public const uint EVENT_OBJECT_HIDE = 0x8003;

        public const uint EVENT_OBJECT_REORDER = 0x8004;

        public const uint EVENT_OBJECT_FOCUS = 0x8005;

        public const uint EVENT_OBJECT_SELECTION = 0x8006;

        public const uint EVENT_OBJECT_SELECTIONADD = 0x8007;

        public const uint EVENT_OBJECT_SELECTIONREMOVE = 0x8008;

        public const uint EVENT_OBJECT_SELECTIONWITHIN = 0x8009;

        public const uint EVENT_OBJECT_STATECHANGE = 0x800A;

        public const uint EVENT_OBJECT_LOCATIONCHANGE = 0x800B;

        public const uint EVENT_OBJECT_NAMECHANGE = 0x800C;

        public const uint EVENT_OBJECT_DESCRIPTIONCHANGE = 0x800D;

        public const uint EVENT_OBJECT_VALUECHANGE = 0x800E;

        public const uint EVENT_OBJECT_PARENTCHANGE = 0x800F;

        public const uint EVENT_OBJECT_HELPCHANGE = 0x8010;

        public const uint EVENT_OBJECT_DEFACTIONCHANGE = 0x8011;

        public const uint EVENT_OBJECT_ACCELERATORCHANGE = 0x8012;

        public const uint EVENT_OBJECT_INVOKED = 0x8013;

        public const uint EVENT_OBJECT_TEXTSELECTIONCHANGED = 0x8014;

        public const uint EVENT_OBJECT_CONTENTSCROLLED = 0x8015;

        public const uint EVENT_SYSTEM_ARRANGMENTPREVIEW = 0x8016;

        public const uint EVENT_OBJECT_CLOAKED = 0x8017;

        public const uint EVENT_OBJECT_UNCLOAKED = 0x8018;

        public const uint EVENT_OBJECT_LIVEREGIONCHANGED = 0x8019;

        public const uint EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED = 0x8020;

        public const uint EVENT_OBJECT_DRAGSTART = 0x8021;

        public const uint EVENT_OBJECT_DRAGCANCEL = 0x8022;

        public const uint EVENT_OBJECT_DRAGCOMPLETE = 0x8023;

        public const uint EVENT_OBJECT_DRAGENTER = 0x8024;

        public const uint EVENT_OBJECT_DRAGLEAVE = 0x8025;

        public const uint EVENT_OBJECT_DRAGDROPPED = 0x8026;

        public const uint EVENT_OBJECT_IME_SHOW = 0x8027;

        public const uint EVENT_OBJECT_IME_HIDE = 0x8028;

        public const uint EVENT_OBJECT_IME_CHANGE = 0x8029;

        public const uint EVENT_OBJECT_TEXTEDIT_CONVERSIONTARGETCHANGED = 0x8030;

        public const uint EVENT_OBJECT_END = 0x80FF;

        public const uint EVENT_AIA_START = 0xA000;

        public const uint EVENT_AIA_END = 0xAFFF;

        public const uint SOUND_SYSTEM_STARTUP = 1;

        public const uint SOUND_SYSTEM_SHUTDOWN = 2;

        public const uint SOUND_SYSTEM_BEEP = 3;

        public const uint SOUND_SYSTEM_ERROR = 4;

        public const uint SOUND_SYSTEM_QUESTION = 5;

        public const uint SOUND_SYSTEM_WARNING = 6;

        public const uint SOUND_SYSTEM_INFORMATION = 7;

        public const uint SOUND_SYSTEM_MAXIMIZE = 8;

        public const uint SOUND_SYSTEM_MINIMIZE = 9;

        public const uint SOUND_SYSTEM_RESTOREUP = 10;

        public const uint SOUND_SYSTEM_RESTOREDOWN = 11;

        public const uint SOUND_SYSTEM_APPSTART = 12;

        public const uint SOUND_SYSTEM_FAULT = 13;

        public const uint SOUND_SYSTEM_APPEND = 14;

        public const uint SOUND_SYSTEM_MENUCOMMAND = 15;

        public const uint SOUND_SYSTEM_MENUPOPUP = 16;

        public const uint CSOUND_SYSTEM = 16;

        public const uint CALERT_SYSTEM = 6;

        public const uint GUI_16BITTASK = 0x00000000;

        public const uint USER_DEFAULT_SCREEN_DPI = 96;

        public const uint STATE_SYSTEM_SELECTED = 0x00000002;

        public const uint STATE_SYSTEM_FOCUSED = 0x00000004;

        public const uint STATE_SYSTEM_CHECKED = 0x00000010;

        public const uint STATE_SYSTEM_MIXED = 0x00000020;

        public const uint STATE_SYSTEM_READONLY = 0x00000040;

        public const uint STATE_SYSTEM_HOTTRACKED = 0x00000080;

        public const uint STATE_SYSTEM_DEFAULT = 0x00000100;

        public const uint STATE_SYSTEM_EXPANDED = 0x00000200;

        public const uint STATE_SYSTEM_COLLAPSED = 0x00000400;

        public const uint STATE_SYSTEM_BUSY = 0x00000800;

        public const uint STATE_SYSTEM_FLOATING = 0x00001000;

        public const uint STATE_SYSTEM_MARQUEED = 0x00002000;

        public const uint STATE_SYSTEM_ANIMATED = 0x00004000;

        public const uint STATE_SYSTEM_SIZEABLE = 0x00020000;

        public const uint STATE_SYSTEM_MOVEABLE = 0x00040000;

        public const uint STATE_SYSTEM_SELFVOICING = 0x00080000;

        public const uint STATE_SYSTEM_SELECTABLE = 0x00200000;

        public const uint STATE_SYSTEM_LINKED = 0x00400000;

        public const uint STATE_SYSTEM_TRAVERSED = 0x00800000;

        public const uint STATE_SYSTEM_MULTISELECTABLE = 0x01000000;

        public const uint STATE_SYSTEM_EXTSELECTABLE = 0x02000000;

        public const uint STATE_SYSTEM_ALERT_LOW = 0x04000000;

        public const uint STATE_SYSTEM_ALERT_MEDIUM = 0x08000000;

        public const uint STATE_SYSTEM_ALERT_HIGH = 0x10000000;

        public const uint STATE_SYSTEM_PROTECTED = 0x20000000;

        public const uint STATE_SYSTEM_VALID = 0x3FFFFFFF;

        public const uint CCHILDREN_TITLEBAR = 5;

        public const uint CCHILDREN_SCROLLBAR = 5;

        public const uint RIM_INPUT = 0;

        public const uint RIM_INPUTSINK = 1;

        public const uint RIM_TYPEMAX = 2;

        public const uint RI_MOUSE_LEFT_BUTTON_DOWN = 0x0001;

        public const uint RI_MOUSE_LEFT_BUTTON_UP = 0x0002;

        public const uint RI_MOUSE_RIGHT_BUTTON_DOWN = 0x0004;

        public const uint RI_MOUSE_RIGHT_BUTTON_UP = 0x0008;

        public const uint RI_MOUSE_MIDDLE_BUTTON_DOWN = 0x0010;

        public const uint RI_MOUSE_MIDDLE_BUTTON_UP = 0x0020;

        public const uint RI_MOUSE_BUTTON_4_DOWN = 0x0040;

        public const uint RI_MOUSE_BUTTON_4_UP = 0x0080;

        public const uint RI_MOUSE_BUTTON_5_DOWN = 0x0100;

        public const uint RI_MOUSE_BUTTON_5_UP = 0x0200;

        public const uint RI_MOUSE_WHEEL = 0x0400;

        public const uint RI_MOUSE_HWHEEL = 0x0800;

        public const uint RI_KEY_MAKE = 0;

        public const uint RI_KEY_BREAK = 1;

        public const uint RI_KEY_E0 = 2;

        public const uint RI_KEY_E1 = 4;

        public const uint RI_KEY_TERMSRV_SET_LED = 8;

        public const uint RI_KEY_TERMSRV_SHADOW = 0x10;

        public const uint RIDEV_EXMODEMASK = 0x000000F0;

        public const uint GIDC_ARRIVAL = 1;

        public const uint GIDC_REMOVAL = 2;

        public const uint POINTER_DEVICE_PRODUCT_STRING_MAX = 520;

        public const uint PDC_ARRIVAL = 0x001;

        public const uint PDC_REMOVAL = 0x002;

        public const uint PDC_ORIENTATION_0 = 0x004;

        public const uint PDC_ORIENTATION_90 = 0x008;

        public const uint PDC_ORIENTATION_180 = 0x010;

        public const uint PDC_ORIENTATION_270 = 0x020;

        public const uint PDC_MODE_DEFAULT = 0x040;

        public const uint PDC_MODE_CENTERED = 0x080;

        public const uint PDC_MAPPING_CHANGE = 0x100;

        public const uint PDC_RESOLUTION = 0x200;

        public const uint PDC_ORIGIN = 0x400;

        public const uint PDC_MODE_ASPECTRATIOPRESERVED = 0x800;

        public const uint GF_BEGIN = 0x00000001;

        public const uint GF_INERTIA = 0x00000002;

        public const uint GF_END = 0x00000004;

        public const uint GESTURECONFIGMAXCOUNT = 256;

        public const uint GCF_INCLUDE_ANCESTORS = 0x00000001;

        public const uint NID_INTEGRATED_TOUCH = 0x00000001;

        public const uint NID_EXTERNAL_TOUCH = 0x00000002;

        public const uint NID_INTEGRATED_PEN = 0x00000004;

        public const uint NID_EXTERNAL_PEN = 0x00000008;

        public const uint NID_MULTI_INPUT = 0x00000040;

        public const uint NID_READY = 0x00000080;

        public const uint MAX_STR_BLOCKREASON = 256;

        public const uint STRSAFE_USE_SECURE_CRT = 0;

        public const uint STRSAFE_MAX_CCH = 2147483647;

        public const uint STRSAFE_IGNORE_NULLS = 0x00000100;

        public const uint STRSAFE_FILL_BEHIND_NULL = 0x00000200;

        public const uint STRSAFE_FILL_ON_FAILURE = 0x00000400;

        public const uint STRSAFE_NULL_ON_FAILURE = 0x00000800;

        public const uint STRSAFE_NO_TRUNCATION = 0x00001000;

        [NativeTypeName("HRESULT")]
        public const int STRSAFE_E_INSUFFICIENT_BUFFER = unchecked((int)0x8007007A);

        [NativeTypeName("HRESULT")]
        public const int STRSAFE_E_INVALID_PARAMETER = unchecked((int)0x80070057);

        [NativeTypeName("HRESULT")]
        public const int STRSAFE_E_END_OF_FILE = unchecked((int)0x80070026);

        public const uint __WARNING_CYCLOMATIC_COMPLEXITY = 28734;

        public const uint __WARNING_USING_UNINIT_VAR = 6001;

        public const uint __WARNING_RETURN_UNINIT_VAR = 6101;

        public const uint __WARNING_DEREF_NULL_PTR = 6011;

        public const uint __WARNING_MISSING_ZERO_TERMINATION2 = 6054;

        public const uint __WARNING_INVALID_PARAM_VALUE_1 = 6387;

        public const uint __WARNING_INCORRECT_ANNOTATION = 26007;

        public const uint __WARNING_POTENTIAL_BUFFER_OVERFLOW_HIGH_PRIORITY = 26015;

        public const uint __WARNING_PRECONDITION_NULLTERMINATION_VIOLATION = 26035;

        public const uint __WARNING_POSTCONDITION_NULLTERMINATION_VIOLATION = 26036;

        public const uint __WARNING_HIGH_PRIORITY_OVERFLOW_POSTCONDITION = 26045;

        public const uint __WARNING_RANGE_POSTCONDITION_VIOLATION = 26061;

        public const uint __WARNING_POTENTIAL_RANGE_POSTCONDITION_VIOLATION = 26071;

        public const uint __WARNING_INVALID_PARAM_VALUE_3 = 28183;

        public const uint __WARNING_RETURNING_BAD_RESULT = 28196;

        public const uint __WARNING_BANNED_API_USAGE = 28719;

        public const uint __WARNING_POST_EXPECTED = 28210;

    }
}
