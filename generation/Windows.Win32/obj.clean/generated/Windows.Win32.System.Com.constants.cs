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


namespace Windows.Win32.System.Com
{
    public static partial class Apis
    {
        public static readonly Guid IID_IPropertyFrame__scanned__ = new Guid(0xB196B28A,0xBAB4,0x101A,0xB6,0x9C,0x00,0xAA,0x00,0x34,0x1D,0x07);

        public static readonly Guid CLSID_CFontPropPage__scanned__ = new Guid(0x0be35200,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

        public static readonly Guid CLSID_CColorPropPage__scanned__ = new Guid(0x0be35201,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

        public static readonly Guid CLSID_CPicturePropPage__scanned__ = new Guid(0x0be35202,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

        public static readonly Guid CLSID_PersistPropset__scanned__ = new Guid(0xfb8f0821,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);

        public static readonly Guid CLSID_ConvertVBX__scanned__ = new Guid(0xfb8f0822,0x0164,0x101b,0x84,0xed,0x08,0x00,0x2b,0x2e,0xc7,0x13);

        public static readonly Guid CLSID_StdFont__scanned__ = new Guid(0x0be35203,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

        public static readonly Guid CLSID_StdPicture__scanned__ = new Guid(0x0be35204,0x8f91,0x11ce,0x9d,0xe3,0x00,0xaa,0x00,0x4b,0xb8,0x51);

        public static readonly Guid GUID_HIMETRIC__scanned__ = new Guid(0x66504300,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_COLOR__scanned__ = new Guid(0x66504301,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_XPOSPIXEL__scanned__ = new Guid(0x66504302,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_YPOSPIXEL__scanned__ = new Guid(0x66504303,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_XSIZEPIXEL__scanned__ = new Guid(0x66504304,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_YSIZEPIXEL__scanned__ = new Guid(0x66504305,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_XPOS__scanned__ = new Guid(0x66504306,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_YPOS__scanned__ = new Guid(0x66504307,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_XSIZE__scanned__ = new Guid(0x66504308,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_YSIZE__scanned__ = new Guid(0x66504309,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_TRISTATE__scanned__ = new Guid(0x6650430A,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_OPTIONVALUEEXCLUSIVE__scanned__ = new Guid(0x6650430B,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_CHECKVALUEEXCLUSIVE__scanned__ = new Guid(0x6650430C,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTNAME__scanned__ = new Guid(0x6650430D,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTSIZE__scanned__ = new Guid(0x6650430E,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTBOLD__scanned__ = new Guid(0x6650430F,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTITALIC__scanned__ = new Guid(0x66504310,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTUNDERSCORE__scanned__ = new Guid(0x66504311,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_FONTSTRIKETHROUGH__scanned__ = new Guid(0x66504312,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public static readonly Guid GUID_HANDLE__scanned__ = new Guid(0x66504313,0xBE0F,0x101A,0x8B,0xBB,0x00,0xAA,0x00,0x30,0x0C,0xAB);

        public const int PICTYPE_UNINITIALIZED = -1;

        public const uint PICTYPE_NONE = 0;

        public const uint PICTYPE_BITMAP = 1;

        public const uint PICTYPE_METAFILE = 2;

        public const uint PICTYPE_ICON = 3;

        public const uint PICTYPE_ENHMETAFILE = 4;

        public const uint FACILITY_CONTROL = 0xa;

        [NativeTypeName("HRESULT")]
        public const int CONNECT_E_LAST = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        [NativeTypeName("HRESULT")]
        public const int CONNECT_S_FIRST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int CONNECT_S_LAST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        [NativeTypeName("HRESULT")]
        public const int SELFREG_E_LAST = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        [NativeTypeName("HRESULT")]
        public const int SELFREG_S_FIRST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int SELFREG_S_LAST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        [NativeTypeName("HRESULT")]
        public const int PERPROP_E_LAST = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        [NativeTypeName("HRESULT")]
        public const int PERPROP_S_FIRST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int PERPROP_S_LAST = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020F));

        public const int OLEMISC_INVISIBLEATRUNTIME = 0x00000400;

        public const int OLEMISC_ALWAYSRUN = 0x00000800;

        public const int OLEMISC_ACTSLIKEBUTTON = 0x00001000;

        public const int OLEMISC_ACTSLIKELABEL = 0x00002000;

        public const int OLEMISC_NOUIACTIVATE = 0x00004000;

        public const int OLEMISC_ALIGNABLE = 0x00008000;

        public const int OLEMISC_SIMPLEFRAME = 0x00010000;

        public const int OLEMISC_SETCLIENTSITEFIRST = 0x00020000;

        public const int OLEMISC_IMEMODE = 0x00040000;

        public const int OLEIVERB_PROPERTIES = -7;

        public const uint VT_STREAMED_PROPSET = 73;

        public const uint VT_STORED_PROPSET = 74;

        public const uint VT_BLOB_PROPSET = 75;

        public const uint VT_VERBOSE_ENUM = 76;

        public const uint OCM__BASE = WM_USER+0x1c00;

        public const uint LP_DEFAULT = 0x00;

        public const uint LP_MONOCHROME = 0x01;

        public const uint LP_VGACOLOR = 0x02;

        public const uint LP_COLOR = 0x04;

        public const int DISPID_AUTOSIZE = -500;

        public const int DISPID_BACKCOLOR = -501;

        public const int DISPID_BACKSTYLE = -502;

        public const int DISPID_BORDERCOLOR = -503;

        public const int DISPID_BORDERSTYLE = -504;

        public const int DISPID_BORDERWIDTH = -505;

        public const int DISPID_DRAWMODE = -507;

        public const int DISPID_DRAWSTYLE = -508;

        public const int DISPID_DRAWWIDTH = -509;

        public const int DISPID_FILLCOLOR = -510;

        public const int DISPID_FILLSTYLE = -511;

        public const int DISPID_FONT = -512;

        public const int DISPID_FORECOLOR = -513;

        public const int DISPID_ENABLED = -514;

        public const int DISPID_HWND = -515;

        public const int DISPID_TABSTOP = -516;

        public const int DISPID_TEXT = -517;

        public const int DISPID_CAPTION = -518;

        public const int DISPID_BORDERVISIBLE = -519;

        public const int DISPID_APPEARANCE = -520;

        public const int DISPID_MOUSEPOINTER = -521;

        public const int DISPID_MOUSEICON = -522;

        public const int DISPID_PICTURE = -523;

        public const int DISPID_VALID = -524;

        public const int DISPID_READYSTATE = -525;

        public const int DISPID_LISTINDEX = -526;

        public const int DISPID_SELECTED = -527;

        public const int DISPID_LIST = -528;

        public const int DISPID_COLUMN = -529;

        public const int DISPID_LISTCOUNT = -531;

        public const int DISPID_MULTISELECT = -532;

        public const int DISPID_MAXLENGTH = -533;

        public const int DISPID_PASSWORDCHAR = -534;

        public const int DISPID_SCROLLBARS = -535;

        public const int DISPID_WORDWRAP = -536;

        public const int DISPID_MULTILINE = -537;

        public const int DISPID_NUMBEROFROWS = -538;

        public const int DISPID_NUMBEROFCOLUMNS = -539;

        public const int DISPID_DISPLAYSTYLE = -540;

        public const int DISPID_GROUPNAME = -541;

        public const int DISPID_IMEMODE = -542;

        public const int DISPID_ACCELERATOR = -543;

        public const int DISPID_ENTERKEYBEHAVIOR = -544;

        public const int DISPID_TABKEYBEHAVIOR = -545;

        public const int DISPID_SELTEXT = -546;

        public const int DISPID_SELSTART = -547;

        public const int DISPID_SELLENGTH = -548;

        public const int DISPID_REFRESH = -550;

        public const int DISPID_DOCLICK = -551;

        public const int DISPID_ABOUTBOX = -552;

        public const int DISPID_ADDITEM = -553;

        public const int DISPID_CLEAR = -554;

        public const int DISPID_REMOVEITEM = -555;

        public const int DISPID_CLICK = -600;

        public const int DISPID_DBLCLICK = -601;

        public const int DISPID_KEYDOWN = -602;

        public const int DISPID_KEYPRESS = -603;

        public const int DISPID_KEYUP = -604;

        public const int DISPID_MOUSEDOWN = -605;

        public const int DISPID_MOUSEMOVE = -606;

        public const int DISPID_MOUSEUP = -607;

        public const int DISPID_ERROREVENT = -608;

        public const int DISPID_READYSTATECHANGE = -609;

        public const int DISPID_CLICK_VALUE = -610;

        public const int DISPID_RIGHTTOLEFT = -611;

        public const int DISPID_TOPTOBOTTOM = -612;

        public const int DISPID_AMBIENT_BACKCOLOR = -701;

        public const int DISPID_AMBIENT_DISPLAYNAME = -702;

        public const int DISPID_AMBIENT_FONT = -703;

        public const int DISPID_AMBIENT_FORECOLOR = -704;

        public const int DISPID_AMBIENT_LOCALEID = -705;

        public const int DISPID_AMBIENT_MESSAGEREFLECT = -706;

        public const int DISPID_AMBIENT_SCALEUNITS = -707;

        public const int DISPID_AMBIENT_TEXTALIGN = -708;

        public const int DISPID_AMBIENT_USERMODE = -709;

        public const int DISPID_AMBIENT_UIDEAD = -710;

        public const int DISPID_AMBIENT_SHOWGRABHANDLES = -711;

        public const int DISPID_AMBIENT_SHOWHATCHING = -712;

        public const int DISPID_AMBIENT_DISPLAYASDEFAULT = -713;

        public const int DISPID_AMBIENT_SUPPORTSMNEMONICS = -714;

        public const int DISPID_AMBIENT_AUTOCLIP = -715;

        public const int DISPID_AMBIENT_APPEARANCE = -716;

        public const int DISPID_AMBIENT_CODEPAGE = -725;

        public const int DISPID_AMBIENT_PALETTE = -726;

        public const int DISPID_AMBIENT_CHARSET = -727;

        public const int DISPID_AMBIENT_TRANSFERPRIORITY = -728;

        public const int DISPID_AMBIENT_RIGHTTOLEFT = -732;

        public const int DISPID_AMBIENT_TOPTOBOTTOM = -733;

        public const int DISPID_Name = -800;

        public const int DISPID_Delete = -801;

        public const int DISPID_Object = -802;

        public const int DISPID_Parent = -803;

        public const uint DISPID_FONT_NAME = 0;

        public const uint DISPID_FONT_SIZE = 2;

        public const uint DISPID_FONT_BOLD = 3;

        public const uint DISPID_FONT_ITALIC = 4;

        public const uint DISPID_FONT_UNDER = 5;

        public const uint DISPID_FONT_STRIKE = 6;

        public const uint DISPID_FONT_WEIGHT = 7;

        public const uint DISPID_FONT_CHARSET = 8;

        public const uint DISPID_FONT_CHANGED = 9;

        public const uint DISPID_PICT_HANDLE = 0;

        public const uint DISPID_PICT_HPAL = 2;

        public const uint DISPID_PICT_TYPE = 3;

        public const uint DISPID_PICT_WIDTH = 4;

        public const uint DISPID_PICT_HEIGHT = 5;

        public const uint DISPID_PICT_RENDER = 6;

        public const int GC_WCH_SIBLING = 0x00000001;

        public const uint TIFLAGS_EXTENDDISPATCHONLY = 0x00000001;

        public const uint OLECMD_TASKDLGID_ONBEFOREUNLOAD = 1;

        public const uint OLECMDARGINDEX_SHOWPAGEACTIONMENU_HWND = 0;

        public const uint OLECMDARGINDEX_SHOWPAGEACTIONMENU_X = 1;

        public const uint OLECMDARGINDEX_SHOWPAGEACTIONMENU_Y = 2;

        public const uint OLECMDARGINDEX_ACTIVEXINSTALL_PUBLISHER = 0;

        public const uint OLECMDARGINDEX_ACTIVEXINSTALL_DISPLAYNAME = 1;

        public const uint OLECMDARGINDEX_ACTIVEXINSTALL_CLSID = 2;

        public const uint OLECMDARGINDEX_ACTIVEXINSTALL_INSTALLSCOPE = 3;

        public const uint OLECMDARGINDEX_ACTIVEXINSTALL_SOURCEURL = 4;

        public const uint INSTALL_SCOPE_INVALID = 0;

        public const uint INSTALL_SCOPE_MACHINE = 1;

        public const uint INSTALL_SCOPE_USER = 2;

        public const uint MK_ALT = 0x20;

        public const uint DROPEFFECT_NONE = 0;

        public const uint DROPEFFECT_COPY = 1;

        public const uint DROPEFFECT_MOVE = 2;

        public const uint DROPEFFECT_LINK = 4;

        public const uint DROPEFFECT_SCROLL = 0x80000000;

        public const uint DD_DEFSCROLLINSET = 11;

        public const uint DD_DEFSCROLLDELAY = 50;

        public const uint DD_DEFSCROLLINTERVAL = 50;

        public const uint DD_DEFDRAGDELAY = 200;

        public const uint DD_DEFDRAGMINDIST = 2;

        public const int OT_LINK = 1;

        public const int OT_EMBEDDED = 2;

        public const int OT_STATIC = 3;

        public const uint OLEVERB_PRIMARY = 0;

        public const uint OF_SET = 0x0001;

        public const uint OF_GET = 0x0002;

        public const uint OF_HANDLER = 0x0004;

        public const uint WIN32 = 100;

        public const int OLEIVERB_PRIMARY = 0;

        public const int OLEIVERB_SHOW = -1;

        public const int OLEIVERB_OPEN = -2;

        public const int OLEIVERB_HIDE = -3;

        public const int OLEIVERB_UIACTIVATE = -4;

        public const int OLEIVERB_INPLACEACTIVATE = -5;

        public const int OLEIVERB_DISCARDUNDOSTATE = -6;

        public const int EMBDHLP_INPROC_HANDLER = 0x0000;

        public const int EMBDHLP_INPROC_SERVER = 0x0001;

        public const int EMBDHLP_CREATENOW = 0x00000000;

        public const int EMBDHLP_DELAYCREATE = 0x00010000;

        public const uint OLECREATE_LEAVERUNNING = 0x00000001;

        public const uint IDC_OLEUIHELP = 99;

        public const uint IDC_IO_CREATENEW = 2100;

        public const uint IDC_IO_CREATEFROMFILE = 2101;

        public const uint IDC_IO_LINKFILE = 2102;

        public const uint IDC_IO_OBJECTTYPELIST = 2103;

        public const uint IDC_IO_DISPLAYASICON = 2104;

        public const uint IDC_IO_CHANGEICON = 2105;

        public const uint IDC_IO_FILE = 2106;

        public const uint IDC_IO_FILEDISPLAY = 2107;

        public const uint IDC_IO_RESULTIMAGE = 2108;

        public const uint IDC_IO_RESULTTEXT = 2109;

        public const uint IDC_IO_ICONDISPLAY = 2110;

        public const uint IDC_IO_OBJECTTYPETEXT = 2111;

        public const uint IDC_IO_FILETEXT = 2112;

        public const uint IDC_IO_FILETYPE = 2113;

        public const uint IDC_IO_INSERTCONTROL = 2114;

        public const uint IDC_IO_ADDCONTROL = 2115;

        public const uint IDC_IO_CONTROLTYPELIST = 2116;

        public const uint IDC_PS_PASTE = 500;

        public const uint IDC_PS_PASTELINK = 501;

        public const uint IDC_PS_SOURCETEXT = 502;

        public const uint IDC_PS_PASTELIST = 503;

        public const uint IDC_PS_PASTELINKLIST = 504;

        public const uint IDC_PS_DISPLAYLIST = 505;

        public const uint IDC_PS_DISPLAYASICON = 506;

        public const uint IDC_PS_ICONDISPLAY = 507;

        public const uint IDC_PS_CHANGEICON = 508;

        public const uint IDC_PS_RESULTIMAGE = 509;

        public const uint IDC_PS_RESULTTEXT = 510;

        public const uint IDC_CI_GROUP = 120;

        public const uint IDC_CI_CURRENT = 121;

        public const uint IDC_CI_CURRENTICON = 122;

        public const uint IDC_CI_DEFAULT = 123;

        public const uint IDC_CI_DEFAULTICON = 124;

        public const uint IDC_CI_FROMFILE = 125;

        public const uint IDC_CI_FROMFILEEDIT = 126;

        public const uint IDC_CI_ICONLIST = 127;

        public const uint IDC_CI_LABEL = 128;

        public const uint IDC_CI_LABELEDIT = 129;

        public const uint IDC_CI_BROWSE = 130;

        public const uint IDC_CI_ICONDISPLAY = 131;

        public const uint IDC_CV_OBJECTTYPE = 150;

        public const uint IDC_CV_DISPLAYASICON = 152;

        public const uint IDC_CV_CHANGEICON = 153;

        public const uint IDC_CV_ACTIVATELIST = 154;

        public const uint IDC_CV_CONVERTTO = 155;

        public const uint IDC_CV_ACTIVATEAS = 156;

        public const uint IDC_CV_RESULTTEXT = 157;

        public const uint IDC_CV_CONVERTLIST = 158;

        public const uint IDC_CV_ICONDISPLAY = 165;

        public const uint IDC_EL_CHANGESOURCE = 201;

        public const uint IDC_EL_AUTOMATIC = 202;

        public const uint IDC_EL_CANCELLINK = 209;

        public const uint IDC_EL_UPDATENOW = 210;

        public const uint IDC_EL_OPENSOURCE = 211;

        public const uint IDC_EL_MANUAL = 212;

        public const uint IDC_EL_LINKSOURCE = 216;

        public const uint IDC_EL_LINKTYPE = 217;

        public const uint IDC_EL_LINKSLISTBOX = 206;

        public const uint IDC_EL_COL1 = 220;

        public const uint IDC_EL_COL2 = 221;

        public const uint IDC_EL_COL3 = 222;

        public const uint IDC_BZ_RETRY = 600;

        public const uint IDC_BZ_ICON = 601;

        public const uint IDC_BZ_MESSAGE1 = 602;

        public const uint IDC_BZ_SWITCHTO = 604;

        public const uint IDC_UL_METER = 1029;

        public const uint IDC_UL_STOP = 1030;

        public const uint IDC_UL_PERCENT = 1031;

        public const uint IDC_UL_PROGRESS = 1032;

        public const uint IDC_PU_LINKS = 900;

        public const uint IDC_PU_TEXT = 901;

        public const uint IDC_PU_CONVERT = 902;

        public const uint IDC_PU_ICON = 908;

        public const uint IDC_GP_OBJECTNAME = 1009;

        public const uint IDC_GP_OBJECTTYPE = 1010;

        public const uint IDC_GP_OBJECTSIZE = 1011;

        public const uint IDC_GP_CONVERT = 1013;

        public const uint IDC_GP_OBJECTICON = 1014;

        public const uint IDC_GP_OBJECTLOCATION = 1022;

        public const uint IDC_VP_PERCENT = 1000;

        public const uint IDC_VP_CHANGEICON = 1001;

        public const uint IDC_VP_EDITABLE = 1002;

        public const uint IDC_VP_ASICON = 1003;

        public const uint IDC_VP_RELATIVE = 1005;

        public const uint IDC_VP_SPIN = 1006;

        public const uint IDC_VP_SCALETXT = 1034;

        public const uint IDC_VP_ICONDISPLAY = 1021;

        public const uint IDC_VP_RESULTIMAGE = 1033;

        public const uint IDC_LP_OPENSOURCE = 1006;

        public const uint IDC_LP_UPDATENOW = 1007;

        public const uint IDC_LP_BREAKLINK = 1008;

        public const uint IDC_LP_LINKSOURCE = 1012;

        public const uint IDC_LP_CHANGESOURCE = 1015;

        public const uint IDC_LP_AUTOMATIC = 1016;

        public const uint IDC_LP_MANUAL = 1017;

        public const uint IDC_LP_DATE = 1018;

        public const uint IDC_LP_TIME = 1019;

        public const uint IDD_INSERTOBJECT = 1000;

        public const uint IDD_CHANGEICON = 1001;

        public const uint IDD_CONVERT = 1002;

        public const uint IDD_PASTESPECIAL = 1003;

        public const uint IDD_EDITLINKS = 1004;

        public const uint IDD_BUSY = 1006;

        public const uint IDD_UPDATELINKS = 1007;

        public const uint IDD_CHANGESOURCE = 1009;

        public const uint IDD_INSERTFILEBROWSE = 1010;

        public const uint IDD_CHANGEICONBROWSE = 1011;

        public const uint IDD_CONVERTONLY = 1012;

        public const uint IDD_CHANGESOURCE4 = 1013;

        public const uint IDD_GNRLPROPS = 1100;

        public const uint IDD_VIEWPROPS = 1101;

        public const uint IDD_LINKPROPS = 1102;

        public const uint IDD_CONVERT4 = 1103;

        public const uint IDD_CONVERTONLY4 = 1104;

        public const uint IDD_EDITLINKS4 = 1105;

        public const uint IDD_GNRLPROPS4 = 1106;

        public const uint IDD_LINKPROPS4 = 1107;

        public const uint IDD_PASTESPECIAL4 = 1108;

        public const uint IDD_CANNOTUPDATELINK = 1008;

        public const uint IDD_LINKSOURCEUNAVAILABLE = 1020;

        public const uint IDD_SERVERNOTFOUND = 1023;

        public const uint IDD_OUTOFMEMORY = 1024;

        public const uint IDD_SERVERNOTREGW = 1021;

        public const uint IDD_LINKTYPECHANGEDW = 1022;

        public const uint IDD_SERVERNOTREGA = 1025;

        public const uint IDD_LINKTYPECHANGEDA = 1026;

        public const uint ID_BROWSE_CHANGEICON = 1;

        public const uint ID_BROWSE_INSERTFILE = 2;

        public const uint ID_BROWSE_ADDCONTROL = 3;

        public const uint ID_BROWSE_CHANGESOURCE = 4;

        public const uint OLEUI_FALSE = 0;

        public const uint OLEUI_SUCCESS = 1;

        public const uint OLEUI_OK = 1;

        public const uint OLEUI_CANCEL = 2;

        public const uint OLEUI_ERR_STANDARDMIN = 100;

        public const uint OLEUI_ERR_OLEMEMALLOC = 100;

        public const uint OLEUI_ERR_STRUCTURENULL = 101;

        public const uint OLEUI_ERR_STRUCTUREINVALID = 102;

        public const uint OLEUI_ERR_CBSTRUCTINCORRECT = 103;

        public const uint OLEUI_ERR_HWNDOWNERINVALID = 104;

        public const uint OLEUI_ERR_LPSZCAPTIONINVALID = 105;

        public const uint OLEUI_ERR_LPFNHOOKINVALID = 106;

        public const uint OLEUI_ERR_HINSTANCEINVALID = 107;

        public const uint OLEUI_ERR_LPSZTEMPLATEINVALID = 108;

        public const uint OLEUI_ERR_HRESOURCEINVALID = 109;

        public const uint OLEUI_ERR_FINDTEMPLATEFAILURE = 110;

        public const uint OLEUI_ERR_LOADTEMPLATEFAILURE = 111;

        public const uint OLEUI_ERR_DIALOGFAILURE = 112;

        public const uint OLEUI_ERR_LOCALMEMALLOC = 113;

        public const uint OLEUI_ERR_GLOBALMEMALLOC = 114;

        public const uint OLEUI_ERR_LOADSTRING = 115;

        public const uint OLEUI_ERR_STANDARDMAX = 116;

        public const int IOF_SHOWHELP = 0x00000001;

        public const int IOF_SELECTCREATENEW = 0x00000002;

        public const int IOF_SELECTCREATEFROMFILE = 0x00000004;

        public const int IOF_CHECKLINK = 0x00000008;

        public const int IOF_CHECKDISPLAYASICON = 0x00000010;

        public const int IOF_CREATENEWOBJECT = 0x00000020;

        public const int IOF_CREATEFILEOBJECT = 0x00000040;

        public const int IOF_CREATELINKOBJECT = 0x00000080;

        public const int IOF_DISABLELINK = 0x00000100;

        public const int IOF_VERIFYSERVERSEXIST = 0x00000200;

        public const int IOF_DISABLEDISPLAYASICON = 0x00000400;

        public const int IOF_HIDECHANGEICON = 0x00000800;

        public const int IOF_SHOWINSERTCONTROL = 0x00001000;

        public const int IOF_SELECTCREATECONTROL = 0x00002000;

        public const uint OLEUI_IOERR_LPSZFILEINVALID = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_IOERR_LPSZLABELINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_IOERR_HICONINVALID = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_IOERR_LPFORMATETCINVALID = OLEUI_ERR_STANDARDMAX+3;

        public const uint OLEUI_IOERR_PPVOBJINVALID = OLEUI_ERR_STANDARDMAX+4;

        public const uint OLEUI_IOERR_LPIOLECLIENTSITEINVALID = OLEUI_ERR_STANDARDMAX+5;

        public const uint OLEUI_IOERR_LPISTORAGEINVALID = OLEUI_ERR_STANDARDMAX+6;

        public const uint OLEUI_IOERR_SCODEHASERROR = OLEUI_ERR_STANDARDMAX+7;

        public const uint OLEUI_IOERR_LPCLSIDEXCLUDEINVALID = OLEUI_ERR_STANDARDMAX+8;

        public const uint OLEUI_IOERR_CCHFILEINVALID = OLEUI_ERR_STANDARDMAX+9;

        public const uint PS_MAXLINKTYPES = 8;

        public const int PSF_SHOWHELP = 0x00000001;

        public const int PSF_SELECTPASTE = 0x00000002;

        public const int PSF_SELECTPASTELINK = 0x00000004;

        public const int PSF_CHECKDISPLAYASICON = 0x00000008;

        public const int PSF_DISABLEDISPLAYASICON = 0x00000010;

        public const int PSF_HIDECHANGEICON = 0x00000020;

        public const int PSF_STAYONCLIPBOARDCHANGE = 0x00000040;

        public const int PSF_NOREFRESHDATAOBJECT = 0x00000080;

        public const uint OLEUI_IOERR_SRCDATAOBJECTINVALID = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_IOERR_ARRPASTEENTRIESINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_IOERR_ARRLINKTYPESINVALID = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_PSERR_CLIPBOARDCHANGED = OLEUI_ERR_STANDARDMAX+3;

        public const uint OLEUI_PSERR_GETCLIPBOARDFAILED = OLEUI_ERR_STANDARDMAX+4;

        public const uint OLEUI_ELERR_LINKCNTRNULL = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_ELERR_LINKCNTRINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const int ELF_SHOWHELP = 0x00000001;

        public const int ELF_DISABLEUPDATENOW = 0x00000002;

        public const int ELF_DISABLEOPENSOURCE = 0x00000004;

        public const int ELF_DISABLECHANGESOURCE = 0x00000008;

        public const int ELF_DISABLECANCELLINK = 0x00000010;

        public const int CIF_SHOWHELP = 0x00000001;

        public const int CIF_SELECTCURRENT = 0x00000002;

        public const int CIF_SELECTDEFAULT = 0x00000004;

        public const int CIF_SELECTFROMFILE = 0x00000008;

        public const int CIF_USEICONEXE = 0x00000010;

        public const uint OLEUI_CIERR_MUSTHAVECLSID = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_CIERR_MUSTHAVECURRENTMETAFILE = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_CIERR_SZICONEXEINVALID = OLEUI_ERR_STANDARDMAX+2;

        public const int CF_SHOWHELPBUTTON = 0x00000001;

        public const int CF_SETCONVERTDEFAULT = 0x00000002;

        public const int CF_SETACTIVATEDEFAULT = 0x00000004;

        public const int CF_SELECTCONVERTTO = 0x00000008;

        public const int CF_SELECTACTIVATEAS = 0x00000010;

        public const int CF_DISABLEDISPLAYASICON = 0x00000020;

        public const int CF_DISABLEACTIVATEAS = 0x00000040;

        public const int CF_HIDECHANGEICON = 0x00000080;

        public const int CF_CONVERTONLY = 0x00000100;

        public const uint OLEUI_CTERR_CLASSIDINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_CTERR_DVASPECTINVALID = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_CTERR_CBFORMATINVALID = OLEUI_ERR_STANDARDMAX+3;

        public const uint OLEUI_CTERR_HMETAPICTINVALID = OLEUI_ERR_STANDARDMAX+4;

        public const uint OLEUI_CTERR_STRINGINVALID = OLEUI_ERR_STANDARDMAX+5;

        public const int BZ_DISABLECANCELBUTTON = 0x00000001;

        public const int BZ_DISABLESWITCHTOBUTTON = 0x00000002;

        public const int BZ_DISABLERETRYBUTTON = 0x00000004;

        public const int BZ_NOTRESPONDINGDIALOG = 0x00000008;

        public const uint OLEUI_BZERR_HTASKINVALID = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_BZ_SWITCHTOSELECTED = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_BZ_RETRYSELECTED = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_BZ_CALLUNBLOCKED = OLEUI_ERR_STANDARDMAX+3;

        public const int CSF_SHOWHELP = 0x00000001;

        public const int CSF_VALIDSOURCE = 0x00000002;

        public const int CSF_ONLYGETSOURCE = 0x00000004;

        public const int CSF_EXPLORER = 0x00000008;

        public const uint OLEUI_CSERR_LINKCNTRNULL = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_CSERR_LINKCNTRINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_CSERR_FROMNOTNULL = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_CSERR_TONOTNULL = OLEUI_ERR_STANDARDMAX+3;

        public const uint OLEUI_CSERR_SOURCENULL = OLEUI_ERR_STANDARDMAX+4;

        public const uint OLEUI_CSERR_SOURCEINVALID = OLEUI_ERR_STANDARDMAX+5;

        public const uint OLEUI_CSERR_SOURCEPARSERROR = OLEUI_ERR_STANDARDMAX+6;

        public const uint OLEUI_CSERR_SOURCEPARSEERROR = OLEUI_ERR_STANDARDMAX+6;

        public const int VPF_SELECTRELATIVE = 0x00000001;

        public const int VPF_DISABLERELATIVE = 0x00000002;

        public const int VPF_DISABLESCALE = 0x00000004;

        public const int OPF_OBJECTISLINK = 0x00000001;

        public const int OPF_NOFILLDEFAULT = 0x00000002;

        public const int OPF_SHOWHELP = 0x00000004;

        public const int OPF_DISABLECONVERT = 0x00000008;

        public const uint OLEUI_OPERR_SUBPROPNULL = OLEUI_ERR_STANDARDMAX+0;

        public const uint OLEUI_OPERR_SUBPROPINVALID = OLEUI_ERR_STANDARDMAX+1;

        public const uint OLEUI_OPERR_PROPSHEETNULL = OLEUI_ERR_STANDARDMAX+2;

        public const uint OLEUI_OPERR_PROPSHEETINVALID = OLEUI_ERR_STANDARDMAX+3;

        public const uint OLEUI_OPERR_SUPPROP = OLEUI_ERR_STANDARDMAX+4;

        public const uint OLEUI_OPERR_PROPSINVALID = OLEUI_ERR_STANDARDMAX+5;

        public const uint OLEUI_OPERR_PAGESINCORRECT = OLEUI_ERR_STANDARDMAX+6;

        public const uint OLEUI_OPERR_INVALIDPAGES = OLEUI_ERR_STANDARDMAX+7;

        public const uint OLEUI_OPERR_NOTSUPPORTED = OLEUI_ERR_STANDARDMAX+8;

        public const uint OLEUI_OPERR_DLGPROCNOTNULL = OLEUI_ERR_STANDARDMAX+9;

        public const uint OLEUI_OPERR_LPARAMNOTZERO = OLEUI_ERR_STANDARDMAX+10;

        public const uint OLEUI_GPERR_STRINGINVALID = OLEUI_ERR_STANDARDMAX+11;

        public const uint OLEUI_GPERR_CLASSIDINVALID = OLEUI_ERR_STANDARDMAX+12;

        public const uint OLEUI_GPERR_LPCLSIDEXCLUDEINVALID = OLEUI_ERR_STANDARDMAX+13;

        public const uint OLEUI_GPERR_CBFORMATINVALID = OLEUI_ERR_STANDARDMAX+14;

        public const uint OLEUI_VPERR_METAPICTINVALID = OLEUI_ERR_STANDARDMAX+15;

        public const uint OLEUI_VPERR_DVASPECTINVALID = OLEUI_ERR_STANDARDMAX+16;

        public const uint OLEUI_LPERR_LINKCNTRNULL = OLEUI_ERR_STANDARDMAX+17;

        public const uint OLEUI_LPERR_LINKCNTRINVALID = OLEUI_ERR_STANDARDMAX+18;

        public const uint OLEUI_OPERR_PROPERTYSHEET = OLEUI_ERR_STANDARDMAX+19;

        public const uint OLEUI_OPERR_OBJINFOINVALID = OLEUI_ERR_STANDARDMAX+20;

        public const uint OLEUI_OPERR_LINKINFOINVALID = OLEUI_ERR_STANDARDMAX+21;

        public const uint OLEUI_QUERY_GETCLASSID = 0xFF00;

        public const uint OLEUI_QUERY_LINKBROKEN = 0xFF01;

        public const uint MKSYS_URLMONIKER = 6;

        public const uint URL_MK_LEGACY = 0;

        public const uint URL_MK_UNIFORM = 1;

        public const uint URL_MK_NO_CANONICALIZE = 2;

        public const uint FIEF_FLAG_FORCE_JITUI = 0x1;

        public const uint FIEF_FLAG_PEEK = 0x2;

        public const uint FIEF_FLAG_SKIP_INSTALLED_VERSION_CHECK = 0x4;

        public const uint FIEF_FLAG_RESERVED_0 = 0x8;

        public const uint FMFD_DEFAULT = 0x00000000;

        public const uint FMFD_URLASFILENAME = 0x00000001;

        public const uint FMFD_ENABLEMIMESNIFFING = 0x00000002;

        public const uint FMFD_IGNOREMIMETEXTPLAIN = 0x00000004;

        public const uint FMFD_SERVERMIME = 0x00000008;

        public const uint FMFD_RESPECTTEXTPLAIN = 0x00000010;

        public const uint FMFD_RETURNUPDATEDIMGMIMES = 0x00000020;

        public const uint FMFD_RESERVED_1 = 0x00000040;

        public const uint UAS_EXACTLEGACY = 0x00001000;

        public const uint URLMON_OPTION_USERAGENT = 0x10000001;

        public const uint URLMON_OPTION_USERAGENT_REFRESH = 0x10000002;

        public const uint URLMON_OPTION_URL_ENCODING = 0x10000004;

        public const uint URLMON_OPTION_USE_BINDSTRINGCREDS = 0x10000008;

        public const uint URLMON_OPTION_USE_BROWSERAPPSDOCUMENTS = 0x10000010;

        public const uint CF_NULL = 0;

        [NativeTypeName("HRESULT")]
        public const int MK_S_ASYNCHRONOUS = 0x000401E8;

        [NativeTypeName("HRESULT")]
        public const int E_PENDING = unchecked((int)0x8000000A);

        [NativeTypeName("HRESULT")]
        public const int INET_E_INVALID_URL = unchecked((int)0x800C0002);

        [NativeTypeName("HRESULT")]
        public const int INET_E_NO_SESSION = unchecked((int)0x800C0003);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CANNOT_CONNECT = unchecked((int)0x800C0004);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESOURCE_NOT_FOUND = unchecked((int)0x800C0005);

        [NativeTypeName("HRESULT")]
        public const int INET_E_OBJECT_NOT_FOUND = unchecked((int)0x800C0006);

        [NativeTypeName("HRESULT")]
        public const int INET_E_DATA_NOT_AVAILABLE = unchecked((int)0x800C0007);

        [NativeTypeName("HRESULT")]
        public const int INET_E_DOWNLOAD_FAILURE = unchecked((int)0x800C0008);

        [NativeTypeName("HRESULT")]
        public const int INET_E_AUTHENTICATION_REQUIRED = unchecked((int)0x800C0009);

        [NativeTypeName("HRESULT")]
        public const int INET_E_NO_VALID_MEDIA = unchecked((int)0x800C000A);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CONNECTION_TIMEOUT = unchecked((int)0x800C000B);

        [NativeTypeName("HRESULT")]
        public const int INET_E_INVALID_REQUEST = unchecked((int)0x800C000C);

        [NativeTypeName("HRESULT")]
        public const int INET_E_UNKNOWN_PROTOCOL = unchecked((int)0x800C000D);

        [NativeTypeName("HRESULT")]
        public const int INET_E_SECURITY_PROBLEM = unchecked((int)0x800C000E);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CANNOT_LOAD_DATA = unchecked((int)0x800C000F);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CANNOT_INSTANTIATE_OBJECT = unchecked((int)0x800C0010);

        [NativeTypeName("HRESULT")]
        public const int INET_E_INVALID_CERTIFICATE = unchecked((int)0x800C0019);

        [NativeTypeName("HRESULT")]
        public const int INET_E_REDIRECT_FAILED = unchecked((int)0x800C0014);

        [NativeTypeName("HRESULT")]
        public const int INET_E_REDIRECT_TO_DIR = unchecked((int)0x800C0015);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CANNOT_LOCK_REQUEST = unchecked((int)0x800C0016);

        [NativeTypeName("HRESULT")]
        public const int INET_E_USE_EXTEND_BINDING = unchecked((int)0x800C0017);

        [NativeTypeName("HRESULT")]
        public const int INET_E_TERMINATED_BIND = unchecked((int)0x800C0018);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESERVED_1 = unchecked((int)0x800C001A);

        [NativeTypeName("HRESULT")]
        public const int INET_E_BLOCKED_REDIRECT_XSECURITYID = unchecked((int)0x800C001B);

        [NativeTypeName("HRESULT")]
        public const int INET_E_DOMINJECTIONVALIDATION = unchecked((int)0x800C001C);

        [NativeTypeName("HRESULT")]
        public const int INET_E_VTAB_SWITCH_FORCE_ENGINE = unchecked((int)0x800C001D);

        [NativeTypeName("HRESULT")]
        public const int INET_E_HSTS_CERTIFICATE_ERROR = unchecked((int)0x800C001E);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESERVED_2 = unchecked((int)0x800C001F);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESERVED_3 = unchecked((int)0x800C0020);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESERVED_4 = unchecked((int)0x800C0021);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESERVED_5 = unchecked((int)0x800C0022);

        [NativeTypeName("HRESULT")]
        public const int INET_E_ERROR_FIRST = unchecked((int)0x800C0002);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_DOWNLOAD_DECLINED = unchecked((int)0x800C0100);

        [NativeTypeName("HRESULT")]
        public const int INET_E_RESULT_DISPATCHED = unchecked((int)0x800C0200);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CANNOT_REPLACE_SFP_FILE = unchecked((int)0x800C0300);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_INSTALL_SUPPRESSED = unchecked((int)0x800C0400);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_INSTALL_BLOCKED_BY_HASH_POLICY = unchecked((int)0x800C0500);

        [NativeTypeName("HRESULT")]
        public const int INET_E_DOWNLOAD_BLOCKED_BY_INPRIVATE = unchecked((int)0x800C0501);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_INSTALL_BLOCKED_IMMERSIVE = unchecked((int)0x800C0502);

        [NativeTypeName("HRESULT")]
        public const int INET_E_FORBIDFRAMING = unchecked((int)0x800C0503);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_INSTALL_BLOCKED_ARM = unchecked((int)0x800C0504);

        [NativeTypeName("HRESULT")]
        public const int INET_E_BLOCKED_PLUGGABLE_PROTOCOL = unchecked((int)0x800C0505);

        [NativeTypeName("HRESULT")]
        public const int INET_E_BLOCKED_ENHANCEDPROTECTEDMODE = unchecked((int)0x800C0506);

        [NativeTypeName("HRESULT")]
        public const int INET_E_CODE_INSTALL_BLOCKED_BITNESS = unchecked((int)0x800C0507);

        [NativeTypeName("HRESULT")]
        public const int INET_E_DOWNLOAD_BLOCKED_BY_CSP = unchecked((int)0x800C0508);

        public const uint Uri_DISPLAY_NO_FRAGMENT = 0x00000001;

        public const uint Uri_PUNYCODE_IDN_HOST = 0x00000002;

        public const uint Uri_DISPLAY_IDN_HOST = 0x00000004;

        public const uint Uri_DISPLAY_NO_PUNYCODE = 0x00000008;

        public const uint Uri_ENCODING_USER_INFO_AND_PATH_IS_PERCENT_ENCODED_UTF8 = 0x00000001;

        public const uint Uri_ENCODING_USER_INFO_AND_PATH_IS_CP = 0x00000002;

        public const uint Uri_ENCODING_HOST_IS_IDN = 0x00000004;

        public const uint Uri_ENCODING_HOST_IS_PERCENT_ENCODED_UTF8 = 0x00000008;

        public const uint Uri_ENCODING_HOST_IS_PERCENT_ENCODED_CP = 0x00000010;

        public const uint Uri_ENCODING_QUERY_AND_FRAGMENT_IS_PERCENT_ENCODED_UTF8 = 0x00000020;

        public const uint Uri_ENCODING_QUERY_AND_FRAGMENT_IS_CP = 0x00000040;

        public const uint UriBuilder_USE_ORIGINAL_FLAGS = 0x00000001;

        public const uint WININETINFO_OPTION_LOCK_HANDLE = 65534;

        public const uint URLOSTRM_USECACHEDCOPY_ONLY = 0x1;

        public const uint URLOSTRM_USECACHEDCOPY = 0x2;

        public const uint URLOSTRM_GETNEWESTVERSION = 0x3;

        public const uint SET_FEATURE_ON_THREAD = 0x00000001;

        public const uint SET_FEATURE_ON_PROCESS = 0x00000002;

        public const uint SET_FEATURE_IN_REGISTRY = 0x00000004;

        public const uint SET_FEATURE_ON_THREAD_LOCALMACHINE = 0x00000008;

        public const uint SET_FEATURE_ON_THREAD_INTRANET = 0x00000010;

        public const uint SET_FEATURE_ON_THREAD_TRUSTED = 0x00000020;

        public const uint SET_FEATURE_ON_THREAD_INTERNET = 0x00000040;

        public const uint SET_FEATURE_ON_THREAD_RESTRICTED = 0x00000080;

        public const uint GET_FEATURE_FROM_THREAD = 0x00000001;

        public const uint GET_FEATURE_FROM_PROCESS = 0x00000002;

        public const uint GET_FEATURE_FROM_REGISTRY = 0x00000004;

        public const uint GET_FEATURE_FROM_THREAD_LOCALMACHINE = 0x00000008;

        public const uint GET_FEATURE_FROM_THREAD_INTRANET = 0x00000010;

        public const uint GET_FEATURE_FROM_THREAD_TRUSTED = 0x00000020;

        public const uint GET_FEATURE_FROM_THREAD_INTERNET = 0x00000040;

        public const uint GET_FEATURE_FROM_THREAD_RESTRICTED = 0x00000080;

        [NativeTypeName("HRESULT")]
        public const int INET_E_USE_DEFAULT_PROTOCOLHANDLER = unchecked((int)0x800C0011);

        [NativeTypeName("HRESULT")]
        public const int INET_E_USE_DEFAULT_SETTING = unchecked((int)0x800C0012);

        [NativeTypeName("HRESULT")]
        public const int INET_E_QUERYOPTION_UNKNOWN = unchecked((int)0x800C0013);

        [NativeTypeName("HRESULT")]
        public const int INET_E_REDIRECTING = unchecked((int)0x800C0014);

        public const uint PROTOCOLFLAG_NO_PICS_CHECK = 0x00000001;

        public const uint MUTZ_NOSAVEDFILECHECK = 0x00000001;

        public const uint MUTZ_ISFILE = 0x00000002;

        public const uint MUTZ_ACCEPT_WILDCARD_SCHEME = 0x00000080;

        public const uint MUTZ_ENFORCERESTRICTED = 0x00000100;

        public const uint MUTZ_RESERVED = 0x00000200;

        public const uint MUTZ_REQUIRESAVEDFILECHECK = 0x00000400;

        public const uint MUTZ_DONT_UNESCAPE = 0x00000800;

        public const uint MUTZ_DONT_USE_CACHE = 0x00001000;

        public const uint MUTZ_FORCE_INTRANET_FLAGS = 0x00002000;

        public const uint MUTZ_IGNORE_ZONE_MAPPINGS = 0x00004000;

        public const uint MAX_SIZE_SECURITY_ID = 512;

        public const uint URLACTION_MIN = 0x00001000;

        public const uint URLACTION_DOWNLOAD_MIN = 0x00001000;

        public const uint URLACTION_DOWNLOAD_SIGNED_ACTIVEX = 0x00001001;

        public const uint URLACTION_DOWNLOAD_UNSIGNED_ACTIVEX = 0x00001004;

        public const uint URLACTION_DOWNLOAD_CURR_MAX = 0x00001004;

        public const uint URLACTION_DOWNLOAD_MAX = 0x000011FF;

        public const uint URLACTION_ACTIVEX_MIN = 0x00001200;

        public const uint URLACTION_ACTIVEX_RUN = 0x00001200;

        public const uint URLPOLICY_ACTIVEX_CHECK_LIST = 0x00010000;

        public const uint URLACTION_ACTIVEX_OVERRIDE_OBJECT_SAFETY = 0x00001201;

        public const uint URLACTION_ACTIVEX_OVERRIDE_DATA_SAFETY = 0x00001202;

        public const uint URLACTION_ACTIVEX_OVERRIDE_SCRIPT_SAFETY = 0x00001203;

        public const uint URLACTION_SCRIPT_OVERRIDE_SAFETY = 0x00001401;

        public const uint URLACTION_ACTIVEX_CONFIRM_NOOBJECTSAFETY = 0x00001204;

        public const uint URLACTION_ACTIVEX_TREATASUNTRUSTED = 0x00001205;

        public const uint URLACTION_ACTIVEX_NO_WEBOC_SCRIPT = 0x00001206;

        public const uint URLACTION_ACTIVEX_OVERRIDE_REPURPOSEDETECTION = 0x00001207;

        public const uint URLACTION_ACTIVEX_OVERRIDE_OPTIN = 0x00001208;

        public const uint URLACTION_ACTIVEX_SCRIPTLET_RUN = 0x00001209;

        public const uint URLACTION_ACTIVEX_DYNSRC_VIDEO_AND_ANIMATION = 0x0000120A;

        public const uint URLACTION_ACTIVEX_OVERRIDE_DOMAINLIST = 0x0000120B;

        public const uint URLACTION_ACTIVEX_ALLOW_TDC = 0x0000120C;

        public const uint URLACTION_ACTIVEX_CURR_MAX = 0x0000120C;

        public const uint URLACTION_ACTIVEX_MAX = 0x000013ff;

        public const uint URLACTION_SCRIPT_MIN = 0x00001400;

        public const uint URLACTION_SCRIPT_RUN = 0x00001400;

        public const uint URLACTION_SCRIPT_JAVA_USE = 0x00001402;

        public const uint URLACTION_SCRIPT_SAFE_ACTIVEX = 0x00001405;

        public const uint URLACTION_CROSS_DOMAIN_DATA = 0x00001406;

        public const uint URLACTION_SCRIPT_PASTE = 0x00001407;

        public const uint URLACTION_ALLOW_XDOMAIN_SUBFRAME_RESIZE = 0x00001408;

        public const uint URLACTION_SCRIPT_XSSFILTER = 0x00001409;

        public const uint URLACTION_SCRIPT_NAVIGATE = 0x0000140A;

        public const uint URLACTION_PLUGGABLE_PROTOCOL_XHR = 0x0000140B;

        public const uint URLACTION_ALLOW_VBSCRIPT_IE = 0x0000140C;

        public const uint URLACTION_SCRIPT_CURR_MAX = 0x0000140C;

        public const uint URLACTION_SCRIPT_MAX = 0x000015ff;

        public const uint URLACTION_HTML_MIN = 0x00001600;

        public const uint URLACTION_HTML_SUBMIT_FORMS = 0x00001601;

        public const uint URLACTION_HTML_SUBMIT_FORMS_FROM = 0x00001602;

        public const uint URLACTION_HTML_SUBMIT_FORMS_TO = 0x00001603;

        public const uint URLACTION_HTML_FONT_DOWNLOAD = 0x00001604;

        public const uint URLACTION_HTML_JAVA_RUN = 0x00001605;

        public const uint URLACTION_HTML_USERDATA_SAVE = 0x00001606;

        public const uint URLACTION_HTML_SUBFRAME_NAVIGATE = 0x00001607;

        public const uint URLACTION_HTML_META_REFRESH = 0x00001608;

        public const uint URLACTION_HTML_MIXED_CONTENT = 0x00001609;

        public const uint URLACTION_HTML_INCLUDE_FILE_PATH = 0x0000160A;

        public const uint URLACTION_HTML_ALLOW_INJECTED_DYNAMIC_HTML = 0x0000160B;

        public const uint URLACTION_HTML_REQUIRE_UTF8_DOCUMENT_CODEPAGE = 0x0000160C;

        public const uint URLACTION_HTML_ALLOW_CROSS_DOMAIN_CANVAS = 0x0000160D;

        public const uint URLACTION_HTML_ALLOW_WINDOW_CLOSE = 0x0000160E;

        public const uint URLACTION_HTML_ALLOW_CROSS_DOMAIN_WEBWORKER = 0x0000160F;

        public const uint URLACTION_HTML_ALLOW_CROSS_DOMAIN_TEXTTRACK = 0x00001610;

        public const uint URLACTION_HTML_ALLOW_INDEXEDDB = 0x00001611;

        public const uint URLACTION_HTML_MAX = 0x000017ff;

        public const uint URLACTION_SHELL_MIN = 0x00001800;

        public const uint URLACTION_SHELL_INSTALL_DTITEMS = 0x00001800;

        public const uint URLACTION_SHELL_MOVE_OR_COPY = 0x00001802;

        public const uint URLACTION_SHELL_FILE_DOWNLOAD = 0x00001803;

        public const uint URLACTION_SHELL_VERB = 0x00001804;

        public const uint URLACTION_SHELL_WEBVIEW_VERB = 0x00001805;

        public const uint URLACTION_SHELL_SHELLEXECUTE = 0x00001806;

        public const uint URLACTION_SHELL_EXECUTE_HIGHRISK = 0x00001806;

        public const uint URLACTION_SHELL_EXECUTE_MODRISK = 0x00001807;

        public const uint URLACTION_SHELL_EXECUTE_LOWRISK = 0x00001808;

        public const uint URLACTION_SHELL_POPUPMGR = 0x00001809;

        public const uint URLACTION_SHELL_RTF_OBJECTS_LOAD = 0x0000180A;

        public const uint URLACTION_SHELL_ENHANCED_DRAGDROP_SECURITY = 0x0000180B;

        public const uint URLACTION_SHELL_EXTENSIONSECURITY = 0x0000180C;

        public const uint URLACTION_SHELL_SECURE_DRAGSOURCE = 0x0000180D;

        public const uint URLACTION_SHELL_REMOTEQUERY = 0x0000180E;

        public const uint URLACTION_SHELL_PREVIEW = 0x0000180F;

        public const uint URLACTION_SHELL_SHARE = 0x00001810;

        public const uint URLACTION_SHELL_ALLOW_CROSS_SITE_SHARE = 0x00001811;

        public const uint URLACTION_SHELL_TOCTOU_RISK = 0x00001812;

        public const uint URLACTION_SHELL_CURR_MAX = 0x00001812;

        public const uint URLACTION_SHELL_MAX = 0x000019ff;

        public const uint URLACTION_NETWORK_MIN = 0x00001A00;

        public const uint URLACTION_CREDENTIALS_USE = 0x00001A00;

        public const uint URLPOLICY_CREDENTIALS_SILENT_LOGON_OK = 0x00000000;

        public const uint URLPOLICY_CREDENTIALS_MUST_PROMPT_USER = 0x00010000;

        public const uint URLPOLICY_CREDENTIALS_CONDITIONAL_PROMPT = 0x00020000;

        public const uint URLPOLICY_CREDENTIALS_ANONYMOUS_ONLY = 0x00030000;

        public const uint URLACTION_AUTHENTICATE_CLIENT = 0x00001A01;

        public const uint URLPOLICY_AUTHENTICATE_CLEARTEXT_OK = 0x00000000;

        public const uint URLPOLICY_AUTHENTICATE_CHALLENGE_RESPONSE = 0x00010000;

        public const uint URLPOLICY_AUTHENTICATE_MUTUAL_ONLY = 0x00030000;

        public const uint URLACTION_COOKIES = 0x00001A02;

        public const uint URLACTION_COOKIES_SESSION = 0x00001A03;

        public const uint URLACTION_CLIENT_CERT_PROMPT = 0x00001A04;

        public const uint URLACTION_COOKIES_THIRD_PARTY = 0x00001A05;

        public const uint URLACTION_COOKIES_SESSION_THIRD_PARTY = 0x00001A06;

        public const uint URLACTION_COOKIES_ENABLED = 0x00001A10;

        public const uint URLACTION_NETWORK_CURR_MAX = 0x00001A10;

        public const uint URLACTION_NETWORK_MAX = 0x00001Bff;

        public const uint URLACTION_JAVA_MIN = 0x00001C00;

        public const uint URLACTION_JAVA_PERMISSIONS = 0x00001C00;

        public const uint URLPOLICY_JAVA_PROHIBIT = 0x00000000;

        public const uint URLPOLICY_JAVA_HIGH = 0x00010000;

        public const uint URLPOLICY_JAVA_MEDIUM = 0x00020000;

        public const uint URLPOLICY_JAVA_LOW = 0x00030000;

        public const uint URLPOLICY_JAVA_CUSTOM = 0x00800000;

        public const uint URLACTION_JAVA_CURR_MAX = 0x00001C00;

        public const uint URLACTION_JAVA_MAX = 0x00001Cff;

        public const uint URLACTION_INFODELIVERY_MIN = 0x00001D00;

        public const uint URLACTION_INFODELIVERY_NO_ADDING_CHANNELS = 0x00001D00;

        public const uint URLACTION_INFODELIVERY_NO_EDITING_CHANNELS = 0x00001D01;

        public const uint URLACTION_INFODELIVERY_NO_REMOVING_CHANNELS = 0x00001D02;

        public const uint URLACTION_INFODELIVERY_NO_ADDING_SUBSCRIPTIONS = 0x00001D03;

        public const uint URLACTION_INFODELIVERY_NO_EDITING_SUBSCRIPTIONS = 0x00001D04;

        public const uint URLACTION_INFODELIVERY_NO_REMOVING_SUBSCRIPTIONS = 0x00001D05;

        public const uint URLACTION_INFODELIVERY_NO_CHANNEL_LOGGING = 0x00001D06;

        public const uint URLACTION_INFODELIVERY_CURR_MAX = 0x00001D06;

        public const uint URLACTION_INFODELIVERY_MAX = 0x00001Dff;

        public const uint URLACTION_CHANNEL_SOFTDIST_MIN = 0x00001E00;

        public const uint URLACTION_CHANNEL_SOFTDIST_PERMISSIONS = 0x00001E05;

        public const uint URLPOLICY_CHANNEL_SOFTDIST_PROHIBIT = 0x00010000;

        public const uint URLPOLICY_CHANNEL_SOFTDIST_PRECACHE = 0x00020000;

        public const uint URLPOLICY_CHANNEL_SOFTDIST_AUTOINSTALL = 0x00030000;

        public const uint URLACTION_CHANNEL_SOFTDIST_MAX = 0x00001Eff;

        public const uint URLACTION_DOTNET_USERCONTROLS = 0x00002005;

        public const uint URLACTION_BEHAVIOR_MIN = 0x00002000;

        public const uint URLACTION_BEHAVIOR_RUN = 0x00002000;

        public const uint URLPOLICY_BEHAVIOR_CHECK_LIST = 0x00010000;

        public const uint URLACTION_FEATURE_MIN = 0x00002100;

        public const uint URLACTION_FEATURE_MIME_SNIFFING = 0x00002100;

        public const uint URLACTION_FEATURE_ZONE_ELEVATION = 0x00002101;

        public const uint URLACTION_FEATURE_WINDOW_RESTRICTIONS = 0x00002102;

        public const uint URLACTION_FEATURE_SCRIPT_STATUS_BAR = 0x00002103;

        public const uint URLACTION_FEATURE_FORCE_ADDR_AND_STATUS = 0x00002104;

        public const uint URLACTION_FEATURE_BLOCK_INPUT_PROMPTS = 0x00002105;

        public const uint URLACTION_FEATURE_DATA_BINDING = 0x00002106;

        public const uint URLACTION_FEATURE_CROSSDOMAIN_FOCUS_CHANGE = 0x00002107;

        public const uint URLACTION_AUTOMATIC_DOWNLOAD_UI_MIN = 0x00002200;

        public const uint URLACTION_AUTOMATIC_DOWNLOAD_UI = 0x00002200;

        public const uint URLACTION_AUTOMATIC_ACTIVEX_UI = 0x00002201;

        public const uint URLACTION_ALLOW_RESTRICTEDPROTOCOLS = 0x00002300;

        public const uint URLACTION_ALLOW_APEVALUATION = 0x00002301;

        public const uint URLACTION_ALLOW_XHR_EVALUATION = 0x00002302;

        public const uint URLACTION_WINDOWS_BROWSER_APPLICATIONS = 0x00002400;

        public const uint URLACTION_XPS_DOCUMENTS = 0x00002401;

        public const uint URLACTION_LOOSE_XAML = 0x00002402;

        public const uint URLACTION_LOWRIGHTS = 0x00002500;

        public const uint URLACTION_WINFX_SETUP = 0x00002600;

        public const uint URLACTION_INPRIVATE_BLOCKING = 0x00002700;

        public const uint URLACTION_ALLOW_AUDIO_VIDEO = 0x00002701;

        public const uint URLACTION_ALLOW_ACTIVEX_FILTERING = 0x00002702;

        public const uint URLACTION_ALLOW_STRUCTURED_STORAGE_SNIFFING = 0x00002703;

        public const uint URLACTION_ALLOW_AUDIO_VIDEO_PLUGINS = 0x00002704;

        public const uint URLACTION_ALLOW_ZONE_ELEVATION_VIA_OPT_OUT = 0x00002705;

        public const uint URLACTION_ALLOW_ZONE_ELEVATION_OPT_OUT_ADDITION = 0x00002706;

        public const uint URLACTION_ALLOW_CROSSDOMAIN_DROP_WITHIN_WINDOW = 0x00002708;

        public const uint URLACTION_ALLOW_CROSSDOMAIN_DROP_ACROSS_WINDOWS = 0x00002709;

        public const uint URLACTION_ALLOW_CROSSDOMAIN_APPCACHE_MANIFEST = 0x0000270A;

        public const uint URLACTION_ALLOW_RENDER_LEGACY_DXTFILTERS = 0x0000270B;

        public const uint URLACTION_ALLOW_ANTIMALWARE_SCANNING_OF_ACTIVEX = 0x0000270C;

        public const uint URLACTION_ALLOW_CSS_EXPRESSIONS = 0x0000270D;

        public const uint URLPOLICY_ALLOW = 0x00;

        public const uint URLPOLICY_QUERY = 0x01;

        public const uint URLPOLICY_DISALLOW = 0x03;

        public const uint URLPOLICY_NOTIFY_ON_ALLOW = 0x10;

        public const uint URLPOLICY_NOTIFY_ON_DISALLOW = 0x20;

        public const uint URLPOLICY_LOG_ON_ALLOW = 0x40;

        public const uint URLPOLICY_LOG_ON_DISALLOW = 0x80;

        public const uint URLPOLICY_MASK_PERMISSIONS = 0x0f;

        public const uint URLPOLICY_DONTCHECKDLGBOX = 0x100;

        public const uint URLZONE_ESC_FLAG = 0x100;

        public const uint SECURITY_IE_STATE_GREEN = 0x00000000;

        public const uint SECURITY_IE_STATE_RED = 0x00000001;

        public const uint SOFTDIST_FLAG_USAGE_EMAIL = 0x00000001;

        public const uint SOFTDIST_FLAG_USAGE_PRECACHE = 0x00000002;

        public const uint SOFTDIST_FLAG_USAGE_AUTOINSTALL = 0x00000004;

        public const uint SOFTDIST_FLAG_DELETE_SUBSCRIPTION = 0x00000008;

        public const uint SOFTDIST_ADSTATE_NONE = 0x00000000;

        public const uint SOFTDIST_ADSTATE_AVAILABLE = 0x00000001;

        public const uint SOFTDIST_ADSTATE_DOWNLOADED = 0x00000002;

        public const uint SOFTDIST_ADSTATE_INSTALLED = 0x00000003;

        public const uint CONFIRMSAFETYACTION_LOADOBJECT = 0x00000001;

        public const uint COM_RIGHTS_EXECUTE = 1;

        public const uint COM_RIGHTS_EXECUTE_LOCAL = 2;

        public const uint COM_RIGHTS_EXECUTE_REMOTE = 4;

        public const uint COM_RIGHTS_ACTIVATE_LOCAL = 8;

        public const uint COM_RIGHTS_ACTIVATE_REMOTE = 16;

        public const uint COM_RIGHTS_RESERVED1 = 32;

        public const uint COM_RIGHTS_RESERVED2 = 64;

        public const uint CWMO_MAX_HANDLES = 56;

        public const uint ROTREGFLAGS_ALLOWANYCLIENT = 0x1;

        public const uint APPIDREGFLAGS_ACTIVATE_IUSERVER_INDESKTOP = 0x1;

        public const uint APPIDREGFLAGS_SECURE_SERVER_PROCESS_SD_AND_BIND = 0x2;

        public const uint APPIDREGFLAGS_ISSUE_ACTIVATION_RPC_AT_IDENTIFY = 0x4;

        public const uint APPIDREGFLAGS_IUSERVER_UNMODIFIED_LOGON_TOKEN = 0x8;

        public const uint APPIDREGFLAGS_IUSERVER_SELF_SID_IN_LAUNCH_PERMISSION = 0x10;

        public const uint APPIDREGFLAGS_IUSERVER_ACTIVATE_IN_CLIENT_SESSION_ONLY = 0x20;

        public const uint APPIDREGFLAGS_RESERVED1 = 0x40;

        public const uint APPIDREGFLAGS_RESERVED2 = 0x80;

        public const uint APPIDREGFLAGS_RESERVED3 = 0x100;

        public const uint APPIDREGFLAGS_RESERVED4 = 0x200;

        public const uint APPIDREGFLAGS_RESERVED5 = 0x400;

        public const uint APPIDREGFLAGS_AAA_NO_IMPLICIT_ACTIVATE_AS_IU = 0x800;

        public const uint APPIDREGFLAGS_RESERVED7 = 0x1000;

        public const uint APPIDREGFLAGS_RESERVED8 = 0x2000;

        public const uint APPIDREGFLAGS_RESERVED9 = 0x4000;

        public const uint DCOMSCM_ACTIVATION_USE_ALL_AUTHNSERVICES = 0x1;

        public const uint DCOMSCM_ACTIVATION_DISALLOW_UNSECURE_CALL = 0x2;

        public const uint DCOMSCM_RESOLVE_USE_ALL_AUTHNSERVICES = 0x4;

        public const uint DCOMSCM_RESOLVE_DISALLOW_UNSECURE_CALL = 0x8;

        public const uint DCOMSCM_PING_USE_MID_AUTHNSERVICE = 0x10;

        public const uint DCOMSCM_PING_DISALLOW_UNSECURE_CALL = 0x20;

        public const ulong MAXLSN = 0x7FFFFFFFFFFFFFFF;

        public const uint DMUS_ERRBASE = 0x1000;

    }
}
