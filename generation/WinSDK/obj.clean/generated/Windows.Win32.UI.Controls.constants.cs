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


namespace Windows.Win32.UI.Controls
{
    public static partial class Apis
    {
        public const uint FILEOPENORD = 1536;

        public const uint MULTIFILEOPENORD = 1537;

        public const uint PRINTDLGORD = 1538;

        public const uint PRNSETUPDLGORD = 1539;

        public const uint FINDDLGORD = 1540;

        public const uint REPLACEDLGORD = 1541;

        public const uint FONTDLGORD = 1542;

        public const uint FORMATDLGORD31 = 1543;

        public const uint FORMATDLGORD30 = 1544;

        public const uint RUNDLGORD = 1545;

        public const uint PAGESETUPDLGORD = 1546;

        public const uint NEWFILEOPENORD = 1547;

        public const uint PRINTDLGEXORD = 1549;

        public const uint PAGESETUPDLGORDMOTIF = 1550;

        public const uint COLORMGMTDLGORD = 1551;

        public const uint NEWFILEOPENV2ORD = 1552;

        public const uint NEWFILEOPENV3ORD = 1553;

        public const uint NEWFORMATDLGWITHLINK = 1591;

        public const uint IDC_MANAGE_LINK = 1592;

        public const uint WM_CTLCOLOR = 0x0019;

        public const uint ILDRF_IMAGELOWQUALITY = 0x00000001;

        public const uint ILDRF_OVERLAYLOWQUALITY = 0x00000010;

        public const uint ILR_DEFAULT = 0x0000;

        public const uint ILR_HORIZONTAL_LEFT = 0x0000;

        public const uint ILR_HORIZONTAL_CENTER = 0x0001;

        public const uint ILR_HORIZONTAL_RIGHT = 0x0002;

        public const uint ILR_VERTICAL_TOP = 0x0000;

        public const uint ILR_VERTICAL_CENTER = 0x0010;

        public const uint ILR_VERTICAL_BOTTOM = 0x0020;

        public const uint ILR_SCALE_CLIP = 0x0000;

        public const uint ILR_SCALE_ASPECTRATIO = 0x0100;

        public const uint ILGOS_ALWAYS = 0x00000000;

        public const uint ILGOS_FROMSTANDBY = 0x00000001;

        public const uint ILFIP_ALWAYS = 0x00000000;

        public const uint ILFIP_FROMSTANDBY = 0x00000001;

        public const uint ILDI_PURGE = 0x00000001;

        public const uint ILDI_STANDBY = 0x00000002;

        public const uint ILDI_RESETACCESS = 0x00000004;

        public const uint ILDI_QUERYACCESS = 0x00000008;

        public const uint MAXPROPPAGES = 100;

        public const uint PSP_DEFAULT = 0x00000000;

        public const uint PSP_DLGINDIRECT = 0x00000001;

        public const uint PSP_USEHICON = 0x00000002;

        public const uint PSP_USEICONID = 0x00000004;

        public const uint PSP_USETITLE = 0x00000008;

        public const uint PSP_RTLREADING = 0x00000010;

        public const uint PSP_HASHELP = 0x00000020;

        public const uint PSP_USEREFPARENT = 0x00000040;

        public const uint PSP_USECALLBACK = 0x00000080;

        public const uint PSP_PREMATURE = 0x00000400;

        public const uint PSP_HIDEHEADER = 0x00000800;

        public const uint PSP_USEHEADERTITLE = 0x00001000;

        public const uint PSP_USEHEADERSUBTITLE = 0x00002000;

        public const uint PSP_USEFUSIONCONTEXT = 0x00004000;

        public const uint PSH_DEFAULT = 0x00000000;

        public const uint PSH_PROPTITLE = 0x00000001;

        public const uint PSH_USEHICON = 0x00000002;

        public const uint PSH_USEICONID = 0x00000004;

        public const uint PSH_PROPSHEETPAGE = 0x00000008;

        public const uint PSH_WIZARDHASFINISH = 0x00000010;

        public const uint PSH_WIZARD = 0x00000020;

        public const uint PSH_USEPSTARTPAGE = 0x00000040;

        public const uint PSH_NOAPPLYNOW = 0x00000080;

        public const uint PSH_USECALLBACK = 0x00000100;

        public const uint PSH_HASHELP = 0x00000200;

        public const uint PSH_MODELESS = 0x00000400;

        public const uint PSH_RTLREADING = 0x00000800;

        public const uint PSH_WIZARDCONTEXTHELP = 0x00001000;

        public const uint PSH_WIZARD97 = 0x00002000;

        public const uint PSH_WATERMARK = 0x00008000;

        public const uint PSH_USEHBMWATERMARK = 0x00010000;

        public const uint PSH_USEHPLWATERMARK = 0x00020000;

        public const uint PSH_STRETCHWATERMARK = 0x00040000;

        public const uint PSH_HEADER = 0x00080000;

        public const uint PSH_USEHBMHEADER = 0x00100000;

        public const uint PSH_USEPAGELANG = 0x00200000;

        public const uint PSH_WIZARD_LITE = 0x00400000;

        public const uint PSH_NOCONTEXTHELP = 0x02000000;

        public const uint PSH_AEROWIZARD = 0x00004000;

        public const uint PSH_RESIZABLE = 0x04000000;

        public const uint PSH_HEADERBITMAP = 0x08000000;

        public const uint PSH_NOMARGIN = 0x10000000;

        public const uint PSCB_INITIALIZED = 1;

        public const uint PSCB_PRECREATE = 2;

        public const uint PSCB_BUTTONPRESSED = 3;

        public const uint PSNRET_NOERROR = 0;

        public const uint PSNRET_INVALID = 1;

        public const uint PSNRET_INVALID_NOCHANGEPAGE = 2;

        public const uint PSNRET_MESSAGEHANDLED = 3;

        public const uint PSM_SETCURSEL = WM_USER + 101;

        public const uint PSM_REMOVEPAGE = WM_USER + 102;

        public const uint PSM_ADDPAGE = WM_USER + 103;

        public const uint PSM_CHANGED = WM_USER + 104;

        public const uint PSM_RESTARTWINDOWS = WM_USER + 105;

        public const uint PSM_REBOOTSYSTEM = WM_USER + 106;

        public const uint PSM_CANCELTOCLOSE = WM_USER + 107;

        public const uint PSM_QUERYSIBLINGS = WM_USER + 108;

        public const uint PSM_UNCHANGED = WM_USER + 109;

        public const uint PSM_APPLY = WM_USER + 110;

        public const uint PSM_SETTITLEA = WM_USER + 111;

        public const uint PSM_SETTITLEW = WM_USER + 120;

        public const uint PSM_SETWIZBUTTONS = WM_USER + 112;

        public const uint PSWIZB_BACK = 0x00000001;

        public const uint PSWIZB_NEXT = 0x00000002;

        public const uint PSWIZB_FINISH = 0x00000004;

        public const uint PSWIZB_DISABLEDFINISH = 0x00000008;

        public const uint PSWIZBF_ELEVATIONREQUIRED = 0x00000001;

        public const uint PSWIZB_CANCEL = 0x00000010;

        public const uint PSM_PRESSBUTTON = WM_USER + 113;

        public const uint PSBTN_BACK = 0;

        public const uint PSBTN_NEXT = 1;

        public const uint PSBTN_FINISH = 2;

        public const uint PSBTN_OK = 3;

        public const uint PSBTN_APPLYNOW = 4;

        public const uint PSBTN_CANCEL = 5;

        public const uint PSBTN_HELP = 6;

        public const uint PSBTN_MAX = 6;

        public const uint PSM_SETCURSELID = WM_USER + 114;

        public const uint PSM_SETFINISHTEXTA = WM_USER + 115;

        public const uint PSM_SETFINISHTEXTW = WM_USER + 121;

        public const uint PSM_GETTABCONTROL = WM_USER + 116;

        public const uint PSM_ISDIALOGMESSAGE = WM_USER + 117;

        public const uint PSM_GETCURRENTPAGEHWND = WM_USER + 118;

        public const uint PSM_INSERTPAGE = WM_USER + 119;

        public const uint PSM_SETHEADERTITLEA = WM_USER + 125;

        public const uint PSM_SETHEADERTITLEW = WM_USER + 126;

        public const uint PSM_SETHEADERSUBTITLEA = WM_USER + 127;

        public const uint PSM_SETHEADERSUBTITLEW = WM_USER + 128;

        public const uint PSM_HWNDTOINDEX = WM_USER + 129;

        public const uint PSM_INDEXTOHWND = WM_USER + 130;

        public const uint PSM_PAGETOINDEX = WM_USER + 131;

        public const uint PSM_INDEXTOPAGE = WM_USER + 132;

        public const uint PSM_IDTOINDEX = WM_USER + 133;

        public const uint PSM_INDEXTOID = WM_USER + 134;

        public const uint PSM_GETRESULT = WM_USER + 135;

        public const uint PSM_RECALCPAGESIZES = WM_USER + 136;

        public const uint PSM_SETNEXTTEXTW = WM_USER + 137;

        public const uint PSWIZB_SHOW = 0;

        public const uint PSWIZB_RESTORE = 1;

        public const uint PSM_SHOWWIZBUTTONS = WM_USER + 138;

        public const uint PSM_ENABLEWIZBUTTONS = WM_USER + 139;

        public const uint PSM_SETBUTTONTEXTW = WM_USER + 140;

        public const uint ID_PSRESTARTWINDOWS = 0x2;

        public const uint WIZ_CXDLG = 276;

        public const uint WIZ_CYDLG = 140;

        public const uint WIZ_CXBMP = 80;

        public const uint WIZ_BODYX = 92;

        public const uint WIZ_BODYCX = 184;

        public const uint PROP_SM_CXDLG = 212;

        public const uint PROP_SM_CYDLG = 188;

        public const uint PROP_MED_CXDLG = 227;

        public const uint PROP_MED_CYDLG = 215;

        public const uint PROP_LG_CXDLG = 252;

        public const uint PROP_LG_CYDLG = 218;

        public const uint WM_CONTEXTMENU = 0x007B;

        public const uint WM_UNICHAR = 0x0109;

        public const uint WM_PRINTCLIENT = 0x0318;

        public const uint EM_CANPASTE = WM_USER + 50;

        public const uint EM_DISPLAYBAND = WM_USER + 51;

        public const uint EM_EXGETSEL = WM_USER + 52;

        public const uint EM_EXLIMITTEXT = WM_USER + 53;

        public const uint EM_EXLINEFROMCHAR = WM_USER + 54;

        public const uint EM_EXSETSEL = WM_USER + 55;

        public const uint EM_FINDTEXT = WM_USER + 56;

        public const uint EM_FORMATRANGE = WM_USER + 57;

        public const uint EM_GETCHARFORMAT = WM_USER + 58;

        public const uint EM_GETEVENTMASK = WM_USER + 59;

        public const uint EM_GETOLEINTERFACE = WM_USER + 60;

        public const uint EM_GETPARAFORMAT = WM_USER + 61;

        public const uint EM_GETSELTEXT = WM_USER + 62;

        public const uint EM_HIDESELECTION = WM_USER + 63;

        public const uint EM_PASTESPECIAL = WM_USER + 64;

        public const uint EM_REQUESTRESIZE = WM_USER + 65;

        public const uint EM_SELECTIONTYPE = WM_USER + 66;

        public const uint EM_SETBKGNDCOLOR = WM_USER + 67;

        public const uint EM_SETCHARFORMAT = WM_USER + 68;

        public const uint EM_SETEVENTMASK = WM_USER + 69;

        public const uint EM_SETOLECALLBACK = WM_USER + 70;

        public const uint EM_SETPARAFORMAT = WM_USER + 71;

        public const uint EM_SETTARGETDEVICE = WM_USER + 72;

        public const uint EM_STREAMIN = WM_USER + 73;

        public const uint EM_STREAMOUT = WM_USER + 74;

        public const uint EM_GETTEXTRANGE = WM_USER + 75;

        public const uint EM_FINDWORDBREAK = WM_USER + 76;

        public const uint EM_SETOPTIONS = WM_USER + 77;

        public const uint EM_GETOPTIONS = WM_USER + 78;

        public const uint EM_FINDTEXTEX = WM_USER + 79;

        public const uint EM_GETWORDBREAKPROCEX = WM_USER + 80;

        public const uint EM_SETWORDBREAKPROCEX = WM_USER + 81;

        public const uint EM_SETUNDOLIMIT = WM_USER + 82;

        public const uint EM_REDO = WM_USER + 84;

        public const uint EM_CANREDO = WM_USER + 85;

        public const uint EM_GETUNDONAME = WM_USER + 86;

        public const uint EM_GETREDONAME = WM_USER + 87;

        public const uint EM_STOPGROUPTYPING = WM_USER + 88;

        public const uint EM_SETTEXTMODE = WM_USER + 89;

        public const uint EM_GETTEXTMODE = WM_USER + 90;

        public const uint EM_AUTOURLDETECT = WM_USER + 91;

        public const uint AURL_ENABLEURL = 1;

        public const uint AURL_ENABLEEMAILADDR = 2;

        public const uint AURL_ENABLETELNO = 4;

        public const uint AURL_ENABLEEAURLS = 8;

        public const uint AURL_ENABLEDRIVELETTERS = 16;

        public const uint AURL_DISABLEMIXEDLGC = 32;

        public const uint EM_GETAUTOURLDETECT = WM_USER + 92;

        public const uint EM_SETPALETTE = WM_USER + 93;

        public const uint EM_GETTEXTEX = WM_USER + 94;

        public const uint EM_GETTEXTLENGTHEX = WM_USER + 95;

        public const uint EM_SHOWSCROLLBAR = WM_USER + 96;

        public const uint EM_SETTEXTEX = WM_USER + 97;

        public const uint EM_SETPUNCTUATION = WM_USER + 100;

        public const uint EM_GETPUNCTUATION = WM_USER + 101;

        public const uint EM_SETWORDWRAPMODE = WM_USER + 102;

        public const uint EM_GETWORDWRAPMODE = WM_USER + 103;

        public const uint EM_SETIMECOLOR = WM_USER + 104;

        public const uint EM_GETIMECOLOR = WM_USER + 105;

        public const uint EM_SETIMEOPTIONS = WM_USER + 106;

        public const uint EM_GETIMEOPTIONS = WM_USER + 107;

        public const uint EM_CONVPOSITION = WM_USER + 108;

        public const uint EM_SETLANGOPTIONS = WM_USER + 120;

        public const uint EM_GETLANGOPTIONS = WM_USER + 121;

        public const uint EM_GETIMECOMPMODE = WM_USER + 122;

        public const uint EM_FINDTEXTW = WM_USER + 123;

        public const uint EM_FINDTEXTEXW = WM_USER + 124;

        public const uint EM_RECONVERSION = WM_USER + 125;

        public const uint EM_SETIMEMODEBIAS = WM_USER + 126;

        public const uint EM_GETIMEMODEBIAS = WM_USER + 127;

        public const uint EM_SETBIDIOPTIONS = WM_USER + 200;

        public const uint EM_GETBIDIOPTIONS = WM_USER + 201;

        public const uint EM_SETTYPOGRAPHYOPTIONS = WM_USER + 202;

        public const uint EM_GETTYPOGRAPHYOPTIONS = WM_USER + 203;

        public const uint EM_SETEDITSTYLE = WM_USER + 204;

        public const uint EM_GETEDITSTYLE = WM_USER + 205;

        public const uint SES_EMULATESYSEDIT = 1;

        public const uint SES_BEEPONMAXTEXT = 2;

        public const uint SES_EXTENDBACKCOLOR = 4;

        public const uint SES_MAPCPS = 8;

        public const uint SES_HYPERLINKTOOLTIPS = 8;

        public const uint SES_EMULATE10 = 16;

        public const uint SES_DEFAULTLATINLIGA = 16;

        public const uint SES_USECRLF = 32;

        public const uint SES_NOFOCUSLINKNOTIFY = 32;

        public const uint SES_USEAIMM = 64;

        public const uint SES_NOIME = 128;

        public const uint SES_ALLOWBEEPS = 256;

        public const uint SES_UPPERCASE = 512;

        public const uint SES_LOWERCASE = 1024;

        public const uint SES_NOINPUTSEQUENCECHK = 2048;

        public const uint SES_BIDI = 4096;

        public const uint SES_SCROLLONKILLFOCUS = 8192;

        public const uint SES_XLTCRCRLFTOCR = 16384;

        public const uint SES_DRAFTMODE = 32768;

        public const uint SES_USECTF = 0x00010000;

        public const uint SES_HIDEGRIDLINES = 0x00020000;

        public const uint SES_USEATFONT = 0x00040000;

        public const uint SES_CUSTOMLOOK = 0x00080000;

        public const uint SES_LBSCROLLNOTIFY = 0x00100000;

        public const uint SES_CTFALLOWEMBED = 0x00200000;

        public const uint SES_CTFALLOWSMARTTAG = 0x00400000;

        public const uint SES_CTFALLOWPROOFING = 0x00800000;

        public const uint SES_LOGICALCARET = 0x01000000;

        public const uint SES_WORDDRAGDROP = 0x02000000;

        public const uint SES_SMARTDRAGDROP = 0x04000000;

        public const uint SES_MULTISELECT = 0x08000000;

        public const uint SES_CTFNOLOCK = 0x10000000;

        public const uint SES_NOEALINEHEIGHTADJUST = 0x20000000;

        public const uint SES_MAX = 0x20000000;

        public const uint IMF_AUTOKEYBOARD = 0x0001;

        public const uint IMF_AUTOFONT = 0x0002;

        public const uint IMF_IMECANCELCOMPLETE = 0x0004;

        public const uint IMF_IMEALWAYSSENDNOTIFY = 0x0008;

        public const uint IMF_AUTOFONTSIZEADJUST = 0x0010;

        public const uint IMF_UIFONTS = 0x0020;

        public const uint IMF_NOIMPLICITLANG = 0x0040;

        public const uint IMF_DUALFONT = 0x0080;

        public const uint IMF_NOKBDLIDFIXUP = 0x0200;

        public const uint IMF_NORTFFONTSUBSTITUTE = 0x0400;

        public const uint IMF_SPELLCHECKING = 0x0800;

        public const uint IMF_TKBPREDICTION = 0x1000;

        public const uint IMF_IMEUIINTEGRATION = 0x2000;

        public const uint ICM_NOTOPEN = 0x0000;

        public const uint ICM_LEVEL3 = 0x0001;

        public const uint ICM_LEVEL2 = 0x0002;

        public const uint ICM_LEVEL2_5 = 0x0003;

        public const uint ICM_LEVEL2_SUI = 0x0004;

        public const uint ICM_CTF = 0x0005;

        public const uint TO_ADVANCEDTYPOGRAPHY = 0x0001;

        public const uint TO_SIMPLELINEBREAK = 0x0002;

        public const uint TO_DISABLECUSTOMTEXTOUT = 0x0004;

        public const uint TO_ADVANCEDLAYOUT = 0x0008;

        public const uint EM_OUTLINE = WM_USER + 220;

        public const uint EM_GETSCROLLPOS = WM_USER + 221;

        public const uint EM_SETSCROLLPOS = WM_USER + 222;

        public const uint EM_SETFONTSIZE = WM_USER + 223;

        public const uint EM_GETZOOM = WM_USER + 224;

        public const uint EM_SETZOOM = WM_USER + 225;

        public const uint EM_GETVIEWKIND = WM_USER + 226;

        public const uint EM_SETVIEWKIND = WM_USER + 227;

        public const uint EM_GETPAGE = WM_USER + 228;

        public const uint EM_SETPAGE = WM_USER + 229;

        public const uint EM_GETHYPHENATEINFO = WM_USER + 230;

        public const uint EM_SETHYPHENATEINFO = WM_USER + 231;

        public const uint EM_GETPAGEROTATE = WM_USER + 235;

        public const uint EM_SETPAGEROTATE = WM_USER + 236;

        public const uint EM_GETCTFMODEBIAS = WM_USER + 237;

        public const uint EM_SETCTFMODEBIAS = WM_USER + 238;

        public const uint EM_GETCTFOPENSTATUS = WM_USER + 240;

        public const uint EM_SETCTFOPENSTATUS = WM_USER + 241;

        public const uint EM_GETIMECOMPTEXT = WM_USER + 242;

        public const uint EM_ISIME = WM_USER + 243;

        public const uint EM_GETIMEPROPERTY = WM_USER + 244;

        public const uint EM_GETQUERYRTFOBJ = WM_USER + 269;

        public const uint EM_SETQUERYRTFOBJ = WM_USER + 270;

        public const uint EPR_0 = 0;

        public const uint EPR_270 = 1;

        public const uint EPR_180 = 2;

        public const uint EPR_90 = 3;

        public const uint EPR_SE = 5;

        public const uint CTFMODEBIAS_DEFAULT = 0x0000;

        public const uint CTFMODEBIAS_FILENAME = 0x0001;

        public const uint CTFMODEBIAS_NAME = 0x0002;

        public const uint CTFMODEBIAS_READING = 0x0003;

        public const uint CTFMODEBIAS_DATETIME = 0x0004;

        public const uint CTFMODEBIAS_CONVERSATION = 0x0005;

        public const uint CTFMODEBIAS_NUMERIC = 0x0006;

        public const uint CTFMODEBIAS_HIRAGANA = 0x0007;

        public const uint CTFMODEBIAS_KATAKANA = 0x0008;

        public const uint CTFMODEBIAS_HANGUL = 0x0009;

        public const uint CTFMODEBIAS_HALFWIDTHKATAKANA = 0x000A;

        public const uint CTFMODEBIAS_FULLWIDTHALPHANUMERIC = 0x000B;

        public const uint CTFMODEBIAS_HALFWIDTHALPHANUMERIC = 0x000C;

        public const uint IMF_SMODE_PLAURALCLAUSE = 0x0001;

        public const uint IMF_SMODE_NONE = 0x0002;

        public const uint EMO_EXIT = 0;

        public const uint EMO_ENTER = 1;

        public const uint EMO_PROMOTE = 2;

        public const uint EMO_EXPAND = 3;

        public const uint EMO_MOVESELECTION = 4;

        public const uint EMO_GETVIEWMODE = 5;

        public const uint EMO_EXPANDSELECTION = 0;

        public const uint EMO_EXPANDDOCUMENT = 1;

        public const uint VM_NORMAL = 4;

        public const uint VM_OUTLINE = 2;

        public const uint VM_PAGE = 9;

        public const uint EM_INSERTTABLE = WM_USER + 232;

        public const uint EM_GETAUTOCORRECTPROC = WM_USER + 233;

        public const uint EM_SETAUTOCORRECTPROC = WM_USER + 234;

        public const uint EM_CALLAUTOCORRECTPROC = WM_USER + 255;

        public const uint ATP_NOCHANGE = 0;

        public const uint ATP_CHANGE = 1;

        public const uint ATP_NODELIMITER = 2;

        public const uint ATP_REPLACEALLTEXT = 4;

        public const uint EM_GETTABLEPARMS = WM_USER + 265;

        public const uint EM_SETEDITSTYLEEX = WM_USER + 275;

        public const uint EM_GETEDITSTYLEEX = WM_USER + 276;

        public const uint SES_EX_NOTABLE = 0x00000004;

        public const uint SES_EX_NOMATH = 0x00000040;

        public const uint SES_EX_HANDLEFRIENDLYURL = 0x00000100;

        public const uint SES_EX_NOTHEMING = 0x00080000;

        public const uint SES_EX_NOACETATESELECTION = 0x00100000;

        public const uint SES_EX_USESINGLELINE = 0x00200000;

        public const uint SES_EX_MULTITOUCH = 0x08000000;

        public const uint SES_EX_HIDETEMPFORMAT = 0x10000000;

        public const uint SES_EX_USEMOUSEWPARAM = 0x20000000;

        public const uint EM_GETSTORYTYPE = WM_USER + 290;

        public const uint EM_SETSTORYTYPE = WM_USER + 291;

        public const uint EM_GETELLIPSISMODE = WM_USER + 305;

        public const uint EM_SETELLIPSISMODE = WM_USER + 306;

        public const uint ELLIPSIS_MASK = 0x00000003;

        public const uint ELLIPSIS_NONE = 0x00000000;

        public const uint ELLIPSIS_END = 0x00000001;

        public const uint ELLIPSIS_WORD = 0x00000003;

        public const uint EM_SETTABLEPARMS = WM_USER + 307;

        public const uint EM_GETTOUCHOPTIONS = WM_USER + 310;

        public const uint EM_SETTOUCHOPTIONS = WM_USER + 311;

        public const uint EM_INSERTIMAGE = WM_USER + 314;

        public const uint EM_SETUIANAME = WM_USER + 320;

        public const uint EM_GETELLIPSISSTATE = WM_USER + 322;

        public const uint RTO_SHOWHANDLES = 1;

        public const uint RTO_DISABLEHANDLES = 2;

        public const uint RTO_READINGMODE = 3;

        public const uint EN_MSGFILTER = 0x0700;

        public const uint EN_REQUESTRESIZE = 0x0701;

        public const uint EN_SELCHANGE = 0x0702;

        public const uint EN_DROPFILES = 0x0703;

        public const uint EN_PROTECTED = 0x0704;

        public const uint EN_CORRECTTEXT = 0x0705;

        public const uint EN_STOPNOUNDO = 0x0706;

        public const uint EN_IMECHANGE = 0x0707;

        public const uint EN_SAVECLIPBOARD = 0x0708;

        public const uint EN_OLEOPFAILED = 0x0709;

        public const uint EN_OBJECTPOSITIONS = 0x070a;

        public const uint EN_LINK = 0x070b;

        public const uint EN_DRAGDROPDONE = 0x070c;

        public const uint EN_PARAGRAPHEXPANDED = 0x070d;

        public const uint EN_PAGECHANGE = 0x070e;

        public const uint EN_LOWFIRTF = 0x070f;

        public const uint EN_ALIGNLTR = 0x0710;

        public const uint EN_ALIGNRTL = 0x0711;

        public const uint EN_CLIPFORMAT = 0x0712;

        public const uint EN_STARTCOMPOSITION = 0x0713;

        public const uint EN_ENDCOMPOSITION = 0x0714;

        public const uint ENM_NONE = 0x00000000;

        public const uint ENM_CHANGE = 0x00000001;

        public const uint ENM_UPDATE = 0x00000002;

        public const uint ENM_SCROLL = 0x00000004;

        public const uint ENM_SCROLLEVENTS = 0x00000008;

        public const uint ENM_DRAGDROPDONE = 0x00000010;

        public const uint ENM_PARAGRAPHEXPANDED = 0x00000020;

        public const uint ENM_PAGECHANGE = 0x00000040;

        public const uint ENM_CLIPFORMAT = 0x00000080;

        public const uint ENM_KEYEVENTS = 0x00010000;

        public const uint ENM_MOUSEEVENTS = 0x00020000;

        public const uint ENM_REQUESTRESIZE = 0x00040000;

        public const uint ENM_SELCHANGE = 0x00080000;

        public const uint ENM_DROPFILES = 0x00100000;

        public const uint ENM_PROTECTED = 0x00200000;

        public const uint ENM_CORRECTTEXT = 0x00400000;

        public const uint ENM_IMECHANGE = 0x00800000;

        public const uint ENM_LANGCHANGE = 0x01000000;

        public const uint ENM_OBJECTPOSITIONS = 0x02000000;

        public const uint ENM_LINK = 0x04000000;

        public const uint ENM_LOWFIRTF = 0x08000000;

        public const uint ENM_STARTCOMPOSITION = 0x10000000;

        public const uint ENM_ENDCOMPOSITION = 0x20000000;

        public const uint ENM_GROUPTYPINGCHANGE = 0x40000000;

        public const uint ENM_HIDELINKTOOLTIP = 0x80000000;

        public const uint ES_SAVESEL = 0x00008000;

        public const uint ES_SUNKEN = 0x00004000;

        public const uint ES_DISABLENOSCROLL = 0x00002000;

        public const uint ES_SELECTIONBAR = 0x01000000;

        public const uint ES_NOOLEDRAGDROP = 0x00000008;

        public const uint ES_EX_NOCALLOLEINIT = 0x00000000;

        public const uint ES_VERTICAL = 0x00400000;

        public const uint ES_NOIME = 0x00080000;

        public const uint ES_SELFIME = 0x00040000;

        public const uint ECO_AUTOWORDSELECTION = 0x00000001;

        public const uint ECO_AUTOVSCROLL = 0x00000040;

        public const uint ECO_AUTOHSCROLL = 0x00000080;

        public const uint ECO_NOHIDESEL = 0x00000100;

        public const uint ECO_READONLY = 0x00000800;

        public const uint ECO_WANTRETURN = 0x00001000;

        public const uint ECO_SAVESEL = 0x00008000;

        public const uint ECO_SELECTIONBAR = 0x01000000;

        public const uint ECO_VERTICAL = 0x00400000;

        public const uint ECOOP_SET = 0x0001;

        public const uint ECOOP_OR = 0x0002;

        public const uint ECOOP_AND = 0x0003;

        public const uint ECOOP_XOR = 0x0004;

        public const uint WB_MOVEWORDPREV = 4;

        public const uint WB_MOVEWORDNEXT = 5;

        public const uint WB_PREVBREAK = 6;

        public const uint WB_NEXTBREAK = 7;

        public const uint PC_FOLLOWING = 1;

        public const uint PC_LEADING = 2;

        public const uint PC_OVERFLOW = 3;

        public const uint PC_DELIMITER = 4;

        public const uint WBF_WORDWRAP = 0x010;

        public const uint WBF_WORDBREAK = 0x020;

        public const uint WBF_OVERFLOW = 0x040;

        public const uint WBF_LEVEL1 = 0x080;

        public const uint WBF_LEVEL2 = 0x100;

        public const uint WBF_CUSTOM = 0x200;

        public const uint IMF_FORCENONE = 0x0001;

        public const uint IMF_FORCEENABLE = 0x0002;

        public const uint IMF_FORCEDISABLE = 0x0004;

        public const uint IMF_CLOSESTATUSWINDOW = 0x0008;

        public const uint IMF_VERTICAL = 0x0020;

        public const uint IMF_FORCEACTIVE = 0x0040;

        public const uint IMF_FORCEINACTIVE = 0x0080;

        public const uint IMF_FORCEREMEMBER = 0x0100;

        public const uint IMF_MULTIPLEEDIT = 0x0400;

        public const uint SCF_SELECTION = 0x0001;

        public const uint SCF_WORD = 0x0002;

        public const uint SCF_DEFAULT = 0x0000;

        public const uint SCF_ALL = 0x0004;

        public const uint SCF_USEUIRULES = 0x0008;

        public const uint SCF_ASSOCIATEFONT = 0x0010;

        public const uint SCF_NOKBUPDATE = 0x0020;

        public const uint SCF_ASSOCIATEFONT2 = 0x0040;

        public const uint SCF_SMARTFONT = 0x0080;

        public const uint SCF_CHARREPFROMLCID = 0x0100;

        public const uint SPF_DONTSETDEFAULT = 0x0002;

        public const uint SPF_SETDEFAULT = 0x0004;

        public const uint SF_TEXT = 0x0001;

        public const uint SF_RTF = 0x0002;

        public const uint SF_RTFNOOBJS = 0x0003;

        public const uint SF_TEXTIZED = 0x0004;

        public const uint SF_UNICODE = 0x0010;

        public const uint SF_USECODEPAGE = 0x0020;

        public const uint SF_NCRFORNONASCII = 0x40;

        public const uint SFF_WRITEXTRAPAR = 0x80;

        public const uint SFF_SELECTION = 0x8000;

        public const uint SFF_PLAINRTF = 0x4000;

        public const uint SFF_PERSISTVIEWSCALE = 0x2000;

        public const uint SFF_KEEPDOCINFO = 0x1000;

        public const uint SFF_PWD = 0x0800;

        public const uint SF_RTFVAL = 0x0700;

        public const uint MAX_TAB_STOPS = 32;

        public const uint MAX_TABLE_CELLS = 63;

        public const uint PFM_SPACEBEFORE = 0x00000040;

        public const uint PFM_SPACEAFTER = 0x00000080;

        public const uint PFM_LINESPACING = 0x00000100;

        public const uint PFM_STYLE = 0x00000400;

        public const uint PFM_BORDER = 0x00000800;

        public const uint PFM_SHADING = 0x00001000;

        public const uint PFM_NUMBERINGSTYLE = 0x00002000;

        public const uint PFM_NUMBERINGTAB = 0x00004000;

        public const uint PFM_NUMBERINGSTART = 0x00008000;

        public const uint PFM_KEEP = 0x00020000;

        public const uint PFM_KEEPNEXT = 0x00040000;

        public const uint PFM_PAGEBREAKBEFORE = 0x00080000;

        public const uint PFM_NOLINENUMBER = 0x00100000;

        public const uint PFM_NOWIDOWCONTROL = 0x00200000;

        public const uint PFM_DONOTHYPHEN = 0x00400000;

        public const uint PFM_SIDEBYSIDE = 0x00800000;

        public const uint PFM_COLLAPSED = 0x01000000;

        public const uint PFM_OUTLINELEVEL = 0x02000000;

        public const uint PFM_BOX = 0x04000000;

        public const uint PFM_RESERVED2 = 0x08000000;

        public const uint PFM_TABLEROWDELIMITER = 0x10000000;

        public const uint PFM_TEXTWRAPPINGBREAK = 0x20000000;

        public const uint PFM_TABLE = 0x40000000;

        public const uint PFN_BULLET = 1;

        public const uint PFN_ARABIC = 2;

        public const uint PFN_LCLETTER = 3;

        public const uint PFN_UCLETTER = 4;

        public const uint PFN_LCROMAN = 5;

        public const uint PFN_UCROMAN = 6;

        public const uint PFA_JUSTIFY = 4;

        public const uint PFA_FULL_INTERWORD = 4;

        public const uint WM_NOTIFY = 0x004E;

        public const uint GCMF_GRIPPER = 0x00000001;

        public const uint GCMF_SPELLING = 0x00000002;

        public const uint GCMF_TOUCHMENU = 0x00004000;

        public const uint GCMF_MOUSEMENU = 0x00002000;

        public const uint OLEOP_DOVERB = 1;

        public const uint ST_DEFAULT = 0;

        public const uint ST_KEEPUNDO = 1;

        public const uint ST_SELECTION = 2;

        public const uint ST_NEWCHARS = 4;

        public const uint ST_UNICODE = 8;

        public const uint BOM_DEFPARADIR = 0x0001;

        public const uint BOM_PLAINTEXT = 0x0002;

        public const uint BOM_NEUTRALOVERRIDE = 0x0004;

        public const uint BOM_CONTEXTREADING = 0x0008;

        public const uint BOM_CONTEXTALIGNMENT = 0x0010;

        public const uint BOM_LEGACYBIDICLASS = 0x0040;

        public const uint BOM_UNICODEBIDI = 0x0080;

        public const uint BOE_RTLDIR = 0x0001;

        public const uint BOE_PLAINTEXT = 0x0002;

        public const uint BOE_NEUTRALOVERRIDE = 0x0004;

        public const uint BOE_CONTEXTREADING = 0x0008;

        public const uint BOE_CONTEXTALIGNMENT = 0x0010;

        public const uint BOE_FORCERECALC = 0x0020;

        public const uint BOE_LEGACYBIDICLASS = 0x0040;

        public const uint BOE_UNICODEBIDI = 0x0080;

        public const uint FR_MATCHDIAC = 0x20000000;

        public const uint FR_MATCHKASHIDA = 0x40000000;

        public const uint FR_MATCHALEFHAMZA = 0x80000000;

        public const uint PFA_FULL_NEWSPAPER = 5;

        public const uint PFA_FULL_INTERLETTER = 6;

        public const uint PFA_FULL_SCALED = 7;

        public const uint PFA_FULL_GLYPHS = 8;

        public const uint AURL_ENABLEEA = 1;

        public const uint GCM_TOUCHMENU = 0x4000;

        public const uint GCM_MOUSEMENU = 0x2000;

        public const int REO_NULL = 0x00000000;

        public const int REO_READWRITEMASK = 0x000007FF;

        public const int RECO_PASTE = 0x00000000;

        public const int RECO_DROP = 0x00000001;

        public const int RECO_COPY = 0x00000002;

        public const int RECO_CUT = 0x00000003;

        public const int RECO_DRAG = 0x00000004;

        public static readonly Guid IID_IRichEditOle__scanned__ = new Guid(0x00020D00, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        public static readonly Guid IID_IRichEditOleCallback__scanned__ = new Guid(0x00020D03, 0, 0, 0xC0,0,0,0,0,0,0,0x46);

        [NativeTypeName("HRESULT")]
        public const int S_MSG_KEY_IGNORED = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x201));

        public const uint TXTBIT_RICHTEXT = 1;

        public const uint TXTBIT_MULTILINE = 2;

        public const uint TXTBIT_READONLY = 4;

        public const uint TXTBIT_SHOWACCELERATOR = 8;

        public const uint TXTBIT_USEPASSWORD = 0x10;

        public const uint TXTBIT_HIDESELECTION = 0x20;

        public const uint TXTBIT_SAVESELECTION = 0x40;

        public const uint TXTBIT_AUTOWORDSEL = 0x80;

        public const uint TXTBIT_VERTICAL = 0x100;

        public const uint TXTBIT_SELBARCHANGE = 0x200;

        public const uint TXTBIT_WORDWRAP = 0x400;

        public const uint TXTBIT_ALLOWBEEP = 0x800;

        public const uint TXTBIT_DISABLEDRAG = 0x1000;

        public const uint TXTBIT_VIEWINSETCHANGE = 0x2000;

        public const uint TXTBIT_BACKSTYLECHANGE = 0x4000;

        public const uint TXTBIT_MAXLENGTHCHANGE = 0x8000;

        public const uint TXTBIT_SCROLLBARCHANGE = 0x10000;

        public const uint TXTBIT_CHARFORMATCHANGE = 0x20000;

        public const uint TXTBIT_PARAFORMATCHANGE = 0x40000;

        public const uint TXTBIT_EXTENTCHANGE = 0x80000;

        public const uint TXTBIT_CLIENTRECTCHANGE = 0x100000;

        public const uint TXTBIT_USECURRENTBKG = 0x200000;

        public const uint TXTBIT_NOTHREADREFCOUNT = 0x400000;

        public const uint TXTBIT_SHOWPASSWORD = 0x800000;

        public const uint TXTBIT_D2DDWRITE = 0x1000000;

        public const uint TXTBIT_D2DSIMPLETYPOGRAPHY = 0x2000000;

        public const uint TXTBIT_D2DPIXELSNAPPED = 0x4000000;

        public const uint TXTBIT_D2DSUBPIXELLINES = 0x8000000;

        public const uint TXTBIT_FLASHLASTPASSWORDCHAR = 0x10000000;

        public const uint TXTBIT_ADVANCEDINPUT = 0x20000000;

        public const uint TXES_ISDIALOG = 1;

        public const uint DA_LAST = 0x7FFFFFFF;

        public const int DA_ERR = -1;

        public const uint DPAM_SORTED = 0x00000001;

        public const uint DPAM_NORMAL = 0x00000002;

        public const uint DPAM_UNION = 0x00000004;

        public const uint DPAM_INTERSECT = 0x00000008;

        public const uint DPAS_SORTED = 0x0001;

        public const uint DPAS_INSERTBEFORE = 0x0002;

        public const uint DPAS_INSERTAFTER = 0x0004;

        public const uint MAX_THEMECOLOR = 64;

        public const uint MAX_THEMESIZE = 64;

        public const uint DTBG_CLIPRECT = 0x00000001;

        public const uint DTBG_DRAWSOLID = 0x00000002;

        public const uint DTBG_OMITBORDER = 0x00000004;

        public const uint DTBG_OMITCONTENT = 0x00000008;

        public const uint DTBG_COMPUTINGREGION = 0x00000010;

        public const uint DTBG_MIRRORDC = 0x00000020;

        public const uint DTBG_NOMIRROR = 0x00000040;

        public const uint DTT_GRAYED = 0x00000001;

        public const uint HTTB_BACKGROUNDSEG = 0x00000000;

        public const uint HTTB_FIXEDBORDER = 0x00000002;

        public const uint HTTB_CAPTION = 0x00000004;

        public const uint HTTB_RESIZINGBORDER_LEFT = 0x00000010;

        public const uint HTTB_RESIZINGBORDER_TOP = 0x00000020;

        public const uint HTTB_RESIZINGBORDER_RIGHT = 0x00000040;

        public const uint HTTB_RESIZINGBORDER_BOTTOM = 0x00000080;

        public const uint HTTB_SIZINGTEMPLATE = 0x00000100;

        public const uint HTTB_SYSTEMSIZINGMARGINS = 0x00000200;

        public const uint MAX_INTLIST_COUNT = 402;

        public const uint ETDT_DISABLE = 0x00000001;

        public const uint ETDT_ENABLE = 0x00000002;

        public const uint ETDT_USETABTEXTURE = 0x00000004;

        public const uint ETDT_USEAEROWIZARDTABTEXTURE = 0x00000008;

        public const uint WTNCA_NODRAWCAPTION = 0x00000001;

        public const uint WTNCA_NODRAWICON = 0x00000002;

        public const uint WTNCA_NOSYSMENU = 0x00000004;

        public const uint WTNCA_NOMIRRORHELP = 0x00000008;

        public const uint ODT_HEADER = 100;

        public const uint LVM_FIRST = 0x1000;

        public const uint TV_FIRST = 0x1100;

        public const uint HDM_FIRST = 0x1200;

        public const uint TCM_FIRST = 0x1300;

        public const uint PGM_FIRST = 0x1400;

        public const uint ECM_FIRST = 0x1500;

        public const uint BCM_FIRST = 0x1600;

        public const uint CBM_FIRST = 0x1700;

        public const uint CCM_FIRST = 0x2000;

        public const uint CCM_LAST = CCM_FIRST + 0x200;

        public const uint CCM_SETBKCOLOR = CCM_FIRST + 1;

        public const uint CCM_SETCOLORSCHEME = CCM_FIRST + 2;

        public const uint CCM_GETCOLORSCHEME = CCM_FIRST + 3;

        public const uint CCM_GETDROPTARGET = CCM_FIRST + 4;

        public const uint CCM_SETUNICODEFORMAT = CCM_FIRST + 5;

        public const uint CCM_GETUNICODEFORMAT = CCM_FIRST + 6;

        public const uint COMCTL32_VERSION = 6;

        public const uint CCM_SETVERSION = CCM_FIRST + 0x7;

        public const uint CCM_GETVERSION = CCM_FIRST + 0x8;

        public const uint CCM_SETNOTIFYWINDOW = CCM_FIRST + 0x9;

        public const uint CCM_SETWINDOWTHEME = CCM_FIRST + 0xb;

        public const uint CCM_DPISCALE = CCM_FIRST + 0xc;

        public const uint INFOTIPSIZE = 1024;

        public const uint MSGF_COMMCTRL_BEGINDRAG = 0x4200;

        public const uint MSGF_COMMCTRL_SIZEHEADER = 0x4201;

        public const uint MSGF_COMMCTRL_DRAGSELECT = 0x4202;

        public const uint MSGF_COMMCTRL_TOOLBARCUST = 0x4203;

        public const uint CDRF_DODEFAULT = 0x00000000;

        public const uint CDRF_NEWFONT = 0x00000002;

        public const uint CDRF_SKIPDEFAULT = 0x00000004;

        public const uint CDRF_DOERASE = 0x00000008;

        public const uint CDRF_SKIPPOSTPAINT = 0x00000100;

        public const uint CDRF_NOTIFYPOSTPAINT = 0x00000010;

        public const uint CDRF_NOTIFYITEMDRAW = 0x00000020;

        public const uint CDRF_NOTIFYSUBITEMDRAW = 0x00000020;

        public const uint CDRF_NOTIFYPOSTERASE = 0x00000040;

        public const uint CDDS_POSTERASE = 0x00000004;

        public const uint CDDS_ITEM = 0x00010000;

        public const uint CDIS_SELECTED = 0x0001;

        public const uint CDIS_GRAYED = 0x0002;

        public const uint CDIS_DISABLED = 0x0004;

        public const uint CDIS_CHECKED = 0x0008;

        public const uint CDIS_FOCUS = 0x0010;

        public const uint CDIS_DEFAULT = 0x0020;

        public const uint CDIS_HOT = 0x0040;

        public const uint CDIS_MARKED = 0x0080;

        public const uint CDIS_INDETERMINATE = 0x0100;

        public const uint CDIS_SHOWKEYBOARDCUES = 0x0200;

        public const uint CDIS_NEARHOT = 0x0400;

        public const uint CDIS_OTHERSIDEHOT = 0x0800;

        public const uint CDIS_DROPHILITED = 0x1000;

        public const uint NM_GETCUSTOMSPLITRECT = BCN_FIRST + 0x0003;

        public const int CLR_NONE = unchecked((int)0xFFFFFFFF);

        public const int CLR_DEFAULT = unchecked((int)0xFF000000);

        public const uint ILD_TRANSPARENT = 0x00000001;

        public const uint ILD_IMAGE = 0x00000020;

        public const uint ILD_ROP = 0x00000040;

        public const uint ILD_BLEND25 = 0x00000002;

        public const uint ILD_OVERLAYMASK = 0x00000F00;

        public const uint ILD_PRESERVEALPHA = 0x00001000;

        public const uint ILD_SCALE = 0x00002000;

        public const uint ILD_DPISCALE = 0x00004000;

        public const uint ILD_ASYNC = 0x00008000;

        public const uint ILS_NORMAL = 0x00000000;

        public const uint ILS_GLOW = 0x00000001;

        public const uint ILS_SHADOW = 0x00000002;

        public const uint ILS_SATURATE = 0x00000004;

        public const uint ILS_ALPHA = 0x00000008;

        public const uint ILGT_NORMAL = 0x00000000;

        public const uint ILGT_ASYNC = 0x00000001;

        public const uint ILP_NORMAL = 0;

        public const uint ILP_DOWNLEVEL = 1;

        public const uint HDS_HORZ = 0x0000;

        public const uint HDS_BUTTONS = 0x0002;

        public const uint HDS_HOTTRACK = 0x0004;

        public const uint HDS_HIDDEN = 0x0008;

        public const uint HDS_DRAGDROP = 0x0040;

        public const uint HDS_FULLDRAG = 0x0080;

        public const uint HDS_FILTERBAR = 0x0100;

        public const uint HDS_FLAT = 0x0200;

        public const uint HDS_CHECKBOXES = 0x0400;

        public const uint HDS_NOSIZING = 0x0800;

        public const uint HDS_OVERFLOW = 0x1000;

        public const uint HDFT_ISSTRING = 0x0000;

        public const uint HDFT_ISNUMBER = 0x0001;

        public const uint HDFT_ISDATE = 0x0002;

        public const uint HDFT_HASNOVALUE = 0x8000;

        public const uint HDF_LEFT = 0x0000;

        public const uint HDF_RIGHT = 0x0001;

        public const uint HDF_CENTER = 0x0002;

        public const uint HDF_JUSTIFYMASK = 0x0003;

        public const uint HDF_RTLREADING = 0x0004;

        public const uint HDF_BITMAP = 0x2000;

        public const uint HDF_STRING = 0x4000;

        public const uint HDF_OWNERDRAW = 0x8000;

        public const uint HDF_IMAGE = 0x0800;

        public const uint HDF_BITMAP_ON_RIGHT = 0x1000;

        public const uint HDF_SORTUP = 0x0400;

        public const uint HDF_SORTDOWN = 0x0200;

        public const uint HDF_CHECKBOX = 0x0040;

        public const uint HDF_CHECKED = 0x0080;

        public const uint HDF_FIXEDWIDTH = 0x0100;

        public const uint HDF_SPLITBUTTON = 0x1000000;

        public const uint HDIS_FOCUSED = 0x00000001;

        public const uint HDM_GETITEMCOUNT = HDM_FIRST + 0;

        public const uint HDM_INSERTITEMA = HDM_FIRST + 1;

        public const uint HDM_INSERTITEMW = HDM_FIRST + 10;

        public const uint HDM_DELETEITEM = HDM_FIRST + 2;

        public const uint HDM_GETITEMA = HDM_FIRST + 3;

        public const uint HDM_GETITEMW = HDM_FIRST + 11;

        public const uint HDM_SETITEMA = HDM_FIRST + 4;

        public const uint HDM_SETITEMW = HDM_FIRST + 12;

        public const uint HDM_LAYOUT = HDM_FIRST + 5;

        public const uint HHT_NOWHERE = 0x0001;

        public const uint HHT_ONHEADER = 0x0002;

        public const uint HHT_ONDIVIDER = 0x0004;

        public const uint HHT_ONDIVOPEN = 0x0008;

        public const uint HHT_ONFILTER = 0x0010;

        public const uint HHT_ONFILTERBUTTON = 0x0020;

        public const uint HHT_ABOVE = 0x0100;

        public const uint HHT_BELOW = 0x0200;

        public const uint HHT_TORIGHT = 0x0400;

        public const uint HHT_TOLEFT = 0x0800;

        public const uint HHT_ONITEMSTATEICON = 0x1000;

        public const uint HHT_ONDROPDOWN = 0x2000;

        public const uint HHT_ONOVERFLOW = 0x4000;

        public const uint HDSIL_NORMAL = 0;

        public const uint HDSIL_STATE = 1;

        public const uint HDM_HITTEST = HDM_FIRST + 6;

        public const uint HDM_GETITEMRECT = HDM_FIRST + 7;

        public const uint HDM_SETIMAGELIST = HDM_FIRST + 8;

        public const uint HDM_GETIMAGELIST = HDM_FIRST + 9;

        public const uint HDM_ORDERTOINDEX = HDM_FIRST + 15;

        public const uint HDM_CREATEDRAGIMAGE = HDM_FIRST + 16;

        public const uint HDM_GETORDERARRAY = HDM_FIRST + 17;

        public const uint HDM_SETORDERARRAY = HDM_FIRST + 18;

        public const uint HDM_SETHOTDIVIDER = HDM_FIRST + 19;

        public const uint HDM_SETBITMAPMARGIN = HDM_FIRST + 20;

        public const uint HDM_GETBITMAPMARGIN = HDM_FIRST + 21;

        public const uint HDM_SETFILTERCHANGETIMEOUT = HDM_FIRST+22;

        public const uint HDM_EDITFILTER = HDM_FIRST+23;

        public const uint HDM_CLEARFILTER = HDM_FIRST+24;

        public const uint HDM_GETITEMDROPDOWNRECT = HDM_FIRST+25;

        public const uint HDM_GETOVERFLOWRECT = HDM_FIRST+26;

        public const uint HDM_GETFOCUSEDITEM = HDM_FIRST+27;

        public const uint HDM_SETFOCUSEDITEM = HDM_FIRST+28;

        public const uint CMB_MASKED = 0x02;

        public const uint TBSTATE_CHECKED = 0x01;

        public const uint TBSTATE_PRESSED = 0x02;

        public const uint TBSTATE_ENABLED = 0x04;

        public const uint TBSTATE_HIDDEN = 0x08;

        public const uint TBSTATE_INDETERMINATE = 0x10;

        public const uint TBSTATE_WRAP = 0x20;

        public const uint TBSTATE_ELLIPSES = 0x40;

        public const uint TBSTATE_MARKED = 0x80;

        public const uint TBSTYLE_BUTTON = 0x0000;

        public const uint TBSTYLE_SEP = 0x0001;

        public const uint TBSTYLE_CHECK = 0x0002;

        public const uint TBSTYLE_GROUP = 0x0004;

        public const uint TBSTYLE_DROPDOWN = 0x0008;

        public const uint TBSTYLE_AUTOSIZE = 0x0010;

        public const uint TBSTYLE_NOPREFIX = 0x0020;

        public const uint TBSTYLE_TOOLTIPS = 0x0100;

        public const uint TBSTYLE_WRAPABLE = 0x0200;

        public const uint TBSTYLE_ALTDRAG = 0x0400;

        public const uint TBSTYLE_FLAT = 0x0800;

        public const uint TBSTYLE_LIST = 0x1000;

        public const uint TBSTYLE_CUSTOMERASE = 0x2000;

        public const uint TBSTYLE_REGISTERDROP = 0x4000;

        public const uint TBSTYLE_TRANSPARENT = 0x8000;

        public const uint TBSTYLE_EX_DRAWDDARROWS = 0x00000001;

        public const uint BTNS_SHOWTEXT = 0x0040;

        public const uint BTNS_WHOLEDROPDOWN = 0x0080;

        public const uint TBSTYLE_EX_MIXEDBUTTONS = 0x00000008;

        public const uint TBSTYLE_EX_HIDECLIPPEDBUTTONS = 0x00000010;

        public const uint TBSTYLE_EX_MULTICOLUMN = 0x00000002;

        public const uint TBSTYLE_EX_VERTICAL = 0x00000004;

        public const uint TBSTYLE_EX_DOUBLEBUFFER = 0x00000080;

        public const uint TBCDRF_NOEDGES = 0x00010000;

        public const uint TBCDRF_HILITEHOTTRACK = 0x00020000;

        public const uint TBCDRF_NOOFFSET = 0x00040000;

        public const uint TBCDRF_NOMARK = 0x00080000;

        public const uint TBCDRF_NOETCHEDEFFECT = 0x00100000;

        public const uint TBCDRF_BLENDICON = 0x00200000;

        public const uint TBCDRF_NOBACKGROUND = 0x00400000;

        public const uint TBCDRF_USECDCOLORS = 0x00800000;

        public const uint TB_ENABLEBUTTON = WM_USER + 1;

        public const uint TB_CHECKBUTTON = WM_USER + 2;

        public const uint TB_PRESSBUTTON = WM_USER + 3;

        public const uint TB_HIDEBUTTON = WM_USER + 4;

        public const uint TB_INDETERMINATE = WM_USER + 5;

        public const uint TB_MARKBUTTON = WM_USER + 6;

        public const uint TB_ISBUTTONENABLED = WM_USER + 9;

        public const uint TB_ISBUTTONCHECKED = WM_USER + 10;

        public const uint TB_ISBUTTONPRESSED = WM_USER + 11;

        public const uint TB_ISBUTTONHIDDEN = WM_USER + 12;

        public const uint TB_ISBUTTONINDETERMINATE = WM_USER + 13;

        public const uint TB_ISBUTTONHIGHLIGHTED = WM_USER + 14;

        public const uint TB_SETSTATE = WM_USER + 17;

        public const uint TB_GETSTATE = WM_USER + 18;

        public const uint TB_ADDBITMAP = WM_USER + 19;

        public const uint IDB_STD_SMALL_COLOR = 0;

        public const uint IDB_STD_LARGE_COLOR = 1;

        public const uint IDB_VIEW_SMALL_COLOR = 4;

        public const uint IDB_VIEW_LARGE_COLOR = 5;

        public const uint IDB_HIST_SMALL_COLOR = 8;

        public const uint IDB_HIST_LARGE_COLOR = 9;

        public const uint IDB_HIST_NORMAL = 12;

        public const uint IDB_HIST_HOT = 13;

        public const uint IDB_HIST_DISABLED = 14;

        public const uint IDB_HIST_PRESSED = 15;

        public const uint STD_CUT = 0;

        public const uint STD_COPY = 1;

        public const uint STD_PASTE = 2;

        public const uint STD_UNDO = 3;

        public const uint STD_REDOW = 4;

        public const uint STD_DELETE = 5;

        public const uint STD_FILENEW = 6;

        public const uint STD_FILEOPEN = 7;

        public const uint STD_FILESAVE = 8;

        public const uint STD_PRINTPRE = 9;

        public const uint STD_PROPERTIES = 10;

        public const uint STD_HELP = 11;

        public const uint STD_FIND = 12;

        public const uint STD_REPLACE = 13;

        public const uint STD_PRINT = 14;

        public const uint VIEW_LARGEICONS = 0;

        public const uint VIEW_SMALLICONS = 1;

        public const uint VIEW_LIST = 2;

        public const uint VIEW_DETAILS = 3;

        public const uint VIEW_SORTNAME = 4;

        public const uint VIEW_SORTSIZE = 5;

        public const uint VIEW_SORTDATE = 6;

        public const uint VIEW_SORTTYPE = 7;

        public const uint VIEW_PARENTFOLDER = 8;

        public const uint VIEW_NETCONNECT = 9;

        public const uint VIEW_NETDISCONNECT = 10;

        public const uint VIEW_NEWFOLDER = 11;

        public const uint VIEW_VIEWMENU = 12;

        public const uint HIST_BACK = 0;

        public const uint HIST_FORWARD = 1;

        public const uint HIST_FAVORITES = 2;

        public const uint HIST_ADDTOFAVORITES = 3;

        public const uint HIST_VIEWTREE = 4;

        public const uint TB_ADDBUTTONSA = WM_USER + 20;

        public const uint TB_INSERTBUTTONA = WM_USER + 21;

        public const uint TB_DELETEBUTTON = WM_USER + 22;

        public const uint TB_GETBUTTON = WM_USER + 23;

        public const uint TB_BUTTONCOUNT = WM_USER + 24;

        public const uint TB_COMMANDTOINDEX = WM_USER + 25;

        public const uint TB_SAVERESTOREA = WM_USER + 26;

        public const uint TB_SAVERESTOREW = WM_USER + 76;

        public const uint TB_CUSTOMIZE = WM_USER + 27;

        public const uint TB_ADDSTRINGA = WM_USER + 28;

        public const uint TB_ADDSTRINGW = WM_USER + 77;

        public const uint TB_GETITEMRECT = WM_USER + 29;

        public const uint TB_BUTTONSTRUCTSIZE = WM_USER + 30;

        public const uint TB_SETBUTTONSIZE = WM_USER + 31;

        public const uint TB_SETBITMAPSIZE = WM_USER + 32;

        public const uint TB_AUTOSIZE = WM_USER + 33;

        public const uint TB_GETTOOLTIPS = WM_USER + 35;

        public const uint TB_SETTOOLTIPS = WM_USER + 36;

        public const uint TB_SETPARENT = WM_USER + 37;

        public const uint TB_SETROWS = WM_USER + 39;

        public const uint TB_GETROWS = WM_USER + 40;

        public const uint TB_SETCMDID = WM_USER + 42;

        public const uint TB_CHANGEBITMAP = WM_USER + 43;

        public const uint TB_GETBITMAP = WM_USER + 44;

        public const uint TB_GETBUTTONTEXTA = WM_USER + 45;

        public const uint TB_GETBUTTONTEXTW = WM_USER + 75;

        public const uint TB_REPLACEBITMAP = WM_USER + 46;

        public const uint TB_SETINDENT = WM_USER + 47;

        public const uint TB_SETIMAGELIST = WM_USER + 48;

        public const uint TB_GETIMAGELIST = WM_USER + 49;

        public const uint TB_LOADIMAGES = WM_USER + 50;

        public const uint TB_GETRECT = WM_USER + 51;

        public const uint TB_SETHOTIMAGELIST = WM_USER + 52;

        public const uint TB_GETHOTIMAGELIST = WM_USER + 53;

        public const uint TB_SETDISABLEDIMAGELIST = WM_USER + 54;

        public const uint TB_GETDISABLEDIMAGELIST = WM_USER + 55;

        public const uint TB_SETSTYLE = WM_USER + 56;

        public const uint TB_GETSTYLE = WM_USER + 57;

        public const uint TB_GETBUTTONSIZE = WM_USER + 58;

        public const uint TB_SETBUTTONWIDTH = WM_USER + 59;

        public const uint TB_SETMAXTEXTROWS = WM_USER + 60;

        public const uint TB_GETTEXTROWS = WM_USER + 61;

        public const uint TB_GETOBJECT = WM_USER + 62;

        public const uint TB_GETHOTITEM = WM_USER + 71;

        public const uint TB_SETHOTITEM = WM_USER + 72;

        public const uint TB_SETANCHORHIGHLIGHT = WM_USER + 73;

        public const uint TB_GETANCHORHIGHLIGHT = WM_USER + 74;

        public const uint TB_MAPACCELERATORA = WM_USER + 78;

        public const uint TB_GETINSERTMARK = WM_USER + 79;

        public const uint TB_SETINSERTMARK = WM_USER + 80;

        public const uint TB_INSERTMARKHITTEST = WM_USER + 81;

        public const uint TB_MOVEBUTTON = WM_USER + 82;

        public const uint TB_GETMAXSIZE = WM_USER + 83;

        public const uint TB_SETEXTENDEDSTYLE = WM_USER + 84;

        public const uint TB_GETEXTENDEDSTYLE = WM_USER + 85;

        public const uint TB_GETPADDING = WM_USER + 86;

        public const uint TB_SETPADDING = WM_USER + 87;

        public const uint TB_SETINSERTMARKCOLOR = WM_USER + 88;

        public const uint TB_GETINSERTMARKCOLOR = WM_USER + 89;

        public const uint TB_MAPACCELERATORW = WM_USER + 90;

        public const uint TBBF_LARGE = 0x0001;

        public const uint TB_GETBITMAPFLAGS = WM_USER + 41;

        public const uint TB_GETBUTTONINFOW = WM_USER + 63;

        public const uint TB_SETBUTTONINFOW = WM_USER + 64;

        public const uint TB_GETBUTTONINFOA = WM_USER + 65;

        public const uint TB_SETBUTTONINFOA = WM_USER + 66;

        public const uint TB_INSERTBUTTONW = WM_USER + 67;

        public const uint TB_ADDBUTTONSW = WM_USER + 68;

        public const uint TB_HITTEST = WM_USER + 69;

        public const uint TB_SETDRAWTEXTFLAGS = WM_USER + 70;

        public const uint TB_GETSTRINGW = WM_USER + 91;

        public const uint TB_GETSTRINGA = WM_USER + 92;

        public const uint TB_SETBOUNDINGSIZE = WM_USER + 93;

        public const uint TB_SETHOTITEM2 = WM_USER + 94;

        public const uint TB_HASACCELERATOR = WM_USER + 95;

        public const uint TB_SETLISTGAP = WM_USER + 96;

        public const uint TB_GETIMAGELISTCOUNT = WM_USER + 98;

        public const uint TB_GETIDEALSIZE = WM_USER + 99;

        public const uint TBMF_PAD = 0x00000001;

        public const uint TBMF_BARPAD = 0x00000002;

        public const uint TBMF_BUTTONSPACING = 0x00000004;

        public const uint TB_GETMETRICS = WM_USER + 101;

        public const uint TB_SETMETRICS = WM_USER + 102;

        public const uint TB_GETITEMDROPDOWNRECT = WM_USER + 103;

        public const uint TB_SETPRESSEDIMAGELIST = WM_USER + 104;

        public const uint TB_GETPRESSEDIMAGELIST = WM_USER + 105;

        public const uint TBNRF_HIDEHELP = 0x00000001;

        public const uint TBNRF_ENDCUSTOMIZE = 0x00000002;

        public const uint TBDDRET_DEFAULT = 0;

        public const uint TBDDRET_NODEFAULT = 1;

        public const uint TBDDRET_TREATPRESSED = 2;

        public const uint RBIM_IMAGELIST = 0x00000001;

        public const uint RBS_TOOLTIPS = 0x00000100;

        public const uint RBS_VARHEIGHT = 0x00000200;

        public const uint RBS_BANDBORDERS = 0x00000400;

        public const uint RBS_FIXEDORDER = 0x00000800;

        public const uint RBS_REGISTERDROP = 0x00001000;

        public const uint RBS_AUTOSIZE = 0x00002000;

        public const uint RBS_VERTICALGRIPPER = 0x00004000;

        public const uint RBS_DBLCLKTOGGLE = 0x00008000;

        public const uint RBBS_BREAK = 0x00000001;

        public const uint RBBS_FIXEDSIZE = 0x00000002;

        public const uint RBBS_CHILDEDGE = 0x00000004;

        public const uint RBBS_HIDDEN = 0x00000008;

        public const uint RBBS_NOVERT = 0x00000010;

        public const uint RBBS_FIXEDBMP = 0x00000020;

        public const uint RBBS_VARIABLEHEIGHT = 0x00000040;

        public const uint RBBS_GRIPPERALWAYS = 0x00000080;

        public const uint RBBS_NOGRIPPER = 0x00000100;

        public const uint RBBS_USECHEVRON = 0x00000200;

        public const uint RBBS_HIDETITLE = 0x00000400;

        public const uint RBBS_TOPALIGN = 0x00000800;

        public const uint RBBIM_STYLE = 0x00000001;

        public const uint RBBIM_COLORS = 0x00000002;

        public const uint RBBIM_TEXT = 0x00000004;

        public const uint RBBIM_IMAGE = 0x00000008;

        public const uint RBBIM_CHILD = 0x00000010;

        public const uint RBBIM_CHILDSIZE = 0x00000020;

        public const uint RBBIM_SIZE = 0x00000040;

        public const uint RBBIM_BACKGROUND = 0x00000080;

        public const uint RBBIM_ID = 0x00000100;

        public const uint RBBIM_IDEALSIZE = 0x00000200;

        public const uint RBBIM_LPARAM = 0x00000400;

        public const uint RBBIM_HEADERSIZE = 0x00000800;

        public const uint RBBIM_CHEVRONLOCATION = 0x00001000;

        public const uint RBBIM_CHEVRONSTATE = 0x00002000;

        public const uint RB_INSERTBANDA = WM_USER +  1;

        public const uint RB_DELETEBAND = WM_USER +  2;

        public const uint RB_GETBARINFO = WM_USER +  3;

        public const uint RB_SETBARINFO = WM_USER +  4;

        public const uint RB_SETBANDINFOA = WM_USER +  6;

        public const uint RB_SETPARENT = WM_USER +  7;

        public const uint RB_HITTEST = WM_USER +  8;

        public const uint RB_GETRECT = WM_USER +  9;

        public const uint RB_INSERTBANDW = WM_USER +  10;

        public const uint RB_SETBANDINFOW = WM_USER +  11;

        public const uint RB_GETBANDCOUNT = WM_USER +  12;

        public const uint RB_GETROWCOUNT = WM_USER +  13;

        public const uint RB_GETROWHEIGHT = WM_USER +  14;

        public const uint RB_IDTOINDEX = WM_USER +  16;

        public const uint RB_GETTOOLTIPS = WM_USER +  17;

        public const uint RB_SETTOOLTIPS = WM_USER +  18;

        public const uint RB_SETBKCOLOR = WM_USER +  19;

        public const uint RB_GETBKCOLOR = WM_USER +  20;

        public const uint RB_SETTEXTCOLOR = WM_USER +  21;

        public const uint RB_GETTEXTCOLOR = WM_USER +  22;

        public const uint RBSTR_CHANGERECT = 0x0001;

        public const uint RB_SIZETORECT = WM_USER +  23;

        public const uint RB_BEGINDRAG = WM_USER + 24;

        public const uint RB_ENDDRAG = WM_USER + 25;

        public const uint RB_DRAGMOVE = WM_USER + 26;

        public const uint RB_GETBARHEIGHT = WM_USER + 27;

        public const uint RB_GETBANDINFOW = WM_USER + 28;

        public const uint RB_GETBANDINFOA = WM_USER + 29;

        public const uint RB_MINIMIZEBAND = WM_USER + 30;

        public const uint RB_MAXIMIZEBAND = WM_USER + 31;

        public const uint RB_GETBANDBORDERS = WM_USER + 34;

        public const uint RB_SHOWBAND = WM_USER + 35;

        public const uint RB_SETPALETTE = WM_USER + 37;

        public const uint RB_GETPALETTE = WM_USER + 38;

        public const uint RB_MOVEBAND = WM_USER + 39;

        public const uint RB_GETBANDMARGINS = WM_USER + 40;

        public const uint RB_SETEXTENDEDSTYLE = WM_USER + 41;

        public const uint RB_GETEXTENDEDSTYLE = WM_USER + 42;

        public const uint RB_PUSHCHEVRON = WM_USER + 43;

        public const uint RB_SETBANDWIDTH = WM_USER + 44;

        public const uint RBAB_AUTOSIZE = 0x0001;

        public const uint RBAB_ADDBAND = 0x0002;

        public const uint RBHT_NOWHERE = 0x0001;

        public const uint RBHT_CAPTION = 0x0002;

        public const uint RBHT_CLIENT = 0x0003;

        public const uint RBHT_GRABBER = 0x0004;

        public const uint RBHT_CHEVRON = 0x0008;

        public const uint RBHT_SPLITTER = 0x0010;

        public const uint TTS_ALWAYSTIP = 0x01;

        public const uint TTS_NOPREFIX = 0x02;

        public const uint TTS_NOANIMATE = 0x10;

        public const uint TTS_NOFADE = 0x20;

        public const uint TTS_BALLOON = 0x40;

        public const uint TTS_CLOSE = 0x80;

        public const uint TTS_USEVISUALSTYLE = 0x100;

        public const uint TTF_DI_SETITEM = 0x8000;

        public const uint TTDT_AUTOMATIC = 0;

        public const uint TTDT_RESHOW = 1;

        public const uint TTDT_AUTOPOP = 2;

        public const uint TTDT_INITIAL = 3;

        public const uint TTM_ACTIVATE = WM_USER + 1;

        public const uint TTM_SETDELAYTIME = WM_USER + 3;

        public const uint TTM_ADDTOOLA = WM_USER + 4;

        public const uint TTM_ADDTOOLW = WM_USER + 50;

        public const uint TTM_DELTOOLA = WM_USER + 5;

        public const uint TTM_DELTOOLW = WM_USER + 51;

        public const uint TTM_NEWTOOLRECTA = WM_USER + 6;

        public const uint TTM_NEWTOOLRECTW = WM_USER + 52;

        public const uint TTM_RELAYEVENT = WM_USER + 7;

        public const uint TTM_GETTOOLINFOA = WM_USER + 8;

        public const uint TTM_GETTOOLINFOW = WM_USER + 53;

        public const uint TTM_SETTOOLINFOA = WM_USER + 9;

        public const uint TTM_SETTOOLINFOW = WM_USER + 54;

        public const uint TTM_HITTESTA = WM_USER +10;

        public const uint TTM_HITTESTW = WM_USER +55;

        public const uint TTM_GETTEXTA = WM_USER +11;

        public const uint TTM_GETTEXTW = WM_USER +56;

        public const uint TTM_UPDATETIPTEXTA = WM_USER +12;

        public const uint TTM_UPDATETIPTEXTW = WM_USER +57;

        public const uint TTM_GETTOOLCOUNT = WM_USER +13;

        public const uint TTM_ENUMTOOLSA = WM_USER +14;

        public const uint TTM_ENUMTOOLSW = WM_USER +58;

        public const uint TTM_GETCURRENTTOOLA = WM_USER + 15;

        public const uint TTM_GETCURRENTTOOLW = WM_USER + 59;

        public const uint TTM_WINDOWFROMPOINT = WM_USER + 16;

        public const uint TTM_TRACKACTIVATE = WM_USER + 17;

        public const uint TTM_TRACKPOSITION = WM_USER + 18;

        public const uint TTM_SETTIPBKCOLOR = WM_USER + 19;

        public const uint TTM_SETTIPTEXTCOLOR = WM_USER + 20;

        public const uint TTM_GETDELAYTIME = WM_USER + 21;

        public const uint TTM_GETTIPBKCOLOR = WM_USER + 22;

        public const uint TTM_GETTIPTEXTCOLOR = WM_USER + 23;

        public const uint TTM_SETMAXTIPWIDTH = WM_USER + 24;

        public const uint TTM_GETMAXTIPWIDTH = WM_USER + 25;

        public const uint TTM_SETMARGIN = WM_USER + 26;

        public const uint TTM_GETMARGIN = WM_USER + 27;

        public const uint TTM_POP = WM_USER + 28;

        public const uint TTM_UPDATE = WM_USER + 29;

        public const uint TTM_GETBUBBLESIZE = WM_USER + 30;

        public const uint TTM_ADJUSTRECT = WM_USER + 31;

        public const uint TTM_SETTITLEA = WM_USER + 32;

        public const uint TTM_SETTITLEW = WM_USER + 33;

        public const uint TTM_POPUP = WM_USER + 34;

        public const uint TTM_GETTITLE = WM_USER + 35;

        public const uint SBARS_SIZEGRIP = 0x0100;

        public const uint SBARS_TOOLTIPS = 0x0800;

        public const uint SBT_TOOLTIPS = 0x0800;

        public const uint SB_SETTEXTA = WM_USER+1;

        public const uint SB_SETTEXTW = WM_USER+11;

        public const uint SB_GETTEXTA = WM_USER+2;

        public const uint SB_GETTEXTW = WM_USER+13;

        public const uint SB_GETTEXTLENGTHA = WM_USER+3;

        public const uint SB_GETTEXTLENGTHW = WM_USER+12;

        public const uint SB_SETPARTS = WM_USER+4;

        public const uint SB_GETPARTS = WM_USER+6;

        public const uint SB_GETBORDERS = WM_USER+7;

        public const uint SB_SETMINHEIGHT = WM_USER+8;

        public const uint SB_SIMPLE = WM_USER+9;

        public const uint SB_GETRECT = WM_USER+10;

        public const uint SB_ISSIMPLE = WM_USER+14;

        public const uint SB_SETICON = WM_USER+15;

        public const uint SB_SETTIPTEXTA = WM_USER+16;

        public const uint SB_SETTIPTEXTW = WM_USER+17;

        public const uint SB_GETTIPTEXTA = WM_USER+18;

        public const uint SB_GETTIPTEXTW = WM_USER+19;

        public const uint SB_GETICON = WM_USER+20;

        public const uint SBT_OWNERDRAW = 0x1000;

        public const uint SBT_NOBORDERS = 0x0100;

        public const uint SBT_POPOUT = 0x0200;

        public const uint SBT_RTLREADING = 0x0400;

        public const uint SBT_NOTABPARSING = 0x0800;

        public const uint SB_SIMPLEID = 0x00ff;

        public const uint TBS_AUTOTICKS = 0x0001;

        public const uint TBS_VERT = 0x0002;

        public const uint TBS_HORZ = 0x0000;

        public const uint TBS_TOP = 0x0004;

        public const uint TBS_BOTTOM = 0x0000;

        public const uint TBS_LEFT = 0x0004;

        public const uint TBS_RIGHT = 0x0000;

        public const uint TBS_BOTH = 0x0008;

        public const uint TBS_NOTICKS = 0x0010;

        public const uint TBS_ENABLESELRANGE = 0x0020;

        public const uint TBS_FIXEDLENGTH = 0x0040;

        public const uint TBS_NOTHUMB = 0x0080;

        public const uint TBS_TOOLTIPS = 0x0100;

        public const uint TBS_REVERSED = 0x0200;

        public const uint TBS_DOWNISLEFT = 0x0400;

        public const uint TBS_NOTIFYBEFOREMOVE = 0x0800;

        public const uint TBS_TRANSPARENTBKGND = 0x1000;

        public const uint TBM_GETRANGEMIN = WM_USER+1;

        public const uint TBM_GETRANGEMAX = WM_USER+2;

        public const uint TBM_GETTIC = WM_USER+3;

        public const uint TBM_SETTIC = WM_USER+4;

        public const uint TBM_SETPOS = WM_USER+5;

        public const uint TBM_SETRANGE = WM_USER+6;

        public const uint TBM_SETRANGEMIN = WM_USER+7;

        public const uint TBM_SETRANGEMAX = WM_USER+8;

        public const uint TBM_CLEARTICS = WM_USER+9;

        public const uint TBM_SETSEL = WM_USER+10;

        public const uint TBM_SETSELSTART = WM_USER+11;

        public const uint TBM_SETSELEND = WM_USER+12;

        public const uint TBM_GETPTICS = WM_USER+14;

        public const uint TBM_GETTICPOS = WM_USER+15;

        public const uint TBM_GETNUMTICS = WM_USER+16;

        public const uint TBM_GETSELSTART = WM_USER+17;

        public const uint TBM_GETSELEND = WM_USER+18;

        public const uint TBM_CLEARSEL = WM_USER+19;

        public const uint TBM_SETTICFREQ = WM_USER+20;

        public const uint TBM_SETPAGESIZE = WM_USER+21;

        public const uint TBM_GETPAGESIZE = WM_USER+22;

        public const uint TBM_SETLINESIZE = WM_USER+23;

        public const uint TBM_GETLINESIZE = WM_USER+24;

        public const uint TBM_GETTHUMBRECT = WM_USER+25;

        public const uint TBM_GETCHANNELRECT = WM_USER+26;

        public const uint TBM_SETTHUMBLENGTH = WM_USER+27;

        public const uint TBM_GETTHUMBLENGTH = WM_USER+28;

        public const uint TBM_SETTOOLTIPS = WM_USER+29;

        public const uint TBM_GETTOOLTIPS = WM_USER+30;

        public const uint TBM_SETTIPSIDE = WM_USER+31;

        public const uint TBTS_TOP = 0;

        public const uint TBTS_LEFT = 1;

        public const uint TBTS_BOTTOM = 2;

        public const uint TBTS_RIGHT = 3;

        public const uint TBM_SETBUDDY = WM_USER+32;

        public const uint TBM_GETBUDDY = WM_USER+33;

        public const uint TBM_SETPOSNOTIFY = WM_USER+34;

        public const uint TB_LINEUP = 0;

        public const uint TB_LINEDOWN = 1;

        public const uint TB_PAGEUP = 2;

        public const uint TB_PAGEDOWN = 3;

        public const uint TB_THUMBPOSITION = 4;

        public const uint TB_THUMBTRACK = 5;

        public const uint TB_TOP = 6;

        public const uint TB_BOTTOM = 7;

        public const uint TB_ENDTRACK = 8;

        public const uint TBCD_TICS = 0x0001;

        public const uint TBCD_THUMB = 0x0002;

        public const uint TBCD_CHANNEL = 0x0003;

        public const uint DL_CURSORSET = 0;

        public const uint DL_STOPCURSOR = 1;

        public const uint DL_COPYCURSOR = 2;

        public const uint DL_MOVECURSOR = 3;

        public const uint UD_MAXVAL = 0x7fff;

        public const uint UDS_WRAP = 0x0001;

        public const uint UDS_SETBUDDYINT = 0x0002;

        public const uint UDS_ALIGNRIGHT = 0x0004;

        public const uint UDS_ALIGNLEFT = 0x0008;

        public const uint UDS_AUTOBUDDY = 0x0010;

        public const uint UDS_ARROWKEYS = 0x0020;

        public const uint UDS_HORZ = 0x0040;

        public const uint UDS_NOTHOUSANDS = 0x0080;

        public const uint UDS_HOTTRACK = 0x0100;

        public const uint UDM_SETRANGE = WM_USER+101;

        public const uint UDM_GETRANGE = WM_USER+102;

        public const uint UDM_SETPOS = WM_USER+103;

        public const uint UDM_GETPOS = WM_USER+104;

        public const uint UDM_SETBUDDY = WM_USER+105;

        public const uint UDM_GETBUDDY = WM_USER+106;

        public const uint UDM_SETACCEL = WM_USER+107;

        public const uint UDM_GETACCEL = WM_USER+108;

        public const uint UDM_SETBASE = WM_USER+109;

        public const uint UDM_GETBASE = WM_USER+110;

        public const uint UDM_SETRANGE32 = WM_USER+111;

        public const uint UDM_GETRANGE32 = WM_USER+112;

        public const uint UDM_SETPOS32 = WM_USER+113;

        public const uint UDM_GETPOS32 = WM_USER+114;

        public const uint PBS_SMOOTH = 0x01;

        public const uint PBS_VERTICAL = 0x04;

        public const uint PBM_SETRANGE = WM_USER+1;

        public const uint PBM_SETPOS = WM_USER+2;

        public const uint PBM_DELTAPOS = WM_USER+3;

        public const uint PBM_SETSTEP = WM_USER+4;

        public const uint PBM_STEPIT = WM_USER+5;

        public const uint PBM_SETRANGE32 = WM_USER+6;

        public const uint PBM_GETRANGE = WM_USER+7;

        public const uint PBM_GETPOS = WM_USER+8;

        public const uint PBM_SETBARCOLOR = WM_USER+9;

        public const uint PBS_MARQUEE = 0x08;

        public const uint PBM_SETMARQUEE = WM_USER+10;

        public const uint PBS_SMOOTHREVERSE = 0x10;

        public const uint PBM_GETSTEP = WM_USER+13;

        public const uint PBM_GETBKCOLOR = WM_USER+14;

        public const uint PBM_GETBARCOLOR = WM_USER+15;

        public const uint PBM_SETSTATE = WM_USER+16;

        public const uint PBM_GETSTATE = WM_USER+17;

        public const uint PBST_NORMAL = 0x0001;

        public const uint PBST_ERROR = 0x0002;

        public const uint PBST_PAUSED = 0x0003;

        public const uint HOTKEYF_SHIFT = 0x01;

        public const uint HOTKEYF_CONTROL = 0x02;

        public const uint HOTKEYF_ALT = 0x04;

        public const uint HOTKEYF_EXT = 0x80;

        public const uint HKCOMB_NONE = 0x0001;

        public const uint HKCOMB_S = 0x0002;

        public const uint HKCOMB_C = 0x0004;

        public const uint HKCOMB_A = 0x0008;

        public const uint HKCOMB_SC = 0x0010;

        public const uint HKCOMB_SA = 0x0020;

        public const uint HKCOMB_CA = 0x0040;

        public const uint HKCOMB_SCA = 0x0080;

        public const uint HKM_SETHOTKEY = WM_USER+1;

        public const uint HKM_GETHOTKEY = WM_USER+2;

        public const uint HKM_SETRULES = WM_USER+3;

        public const int CCS_TOP = 0x00000001;

        public const int CCS_NOMOVEY = 0x00000002;

        public const int CCS_BOTTOM = 0x00000003;

        public const int CCS_NORESIZE = 0x00000004;

        public const int CCS_NOPARENTALIGN = 0x00000008;

        public const int CCS_ADJUSTABLE = 0x00000020;

        public const int CCS_NODIVIDER = 0x00000040;

        public const int CCS_VERT = 0x00000080;

        public const int INVALID_LINK_INDEX = -1;

        public const uint MAX_LINKID_TEXT = 48;

        public const uint LWS_TRANSPARENT = 0x0001;

        public const uint LWS_IGNORERETURN = 0x0002;

        public const uint LWS_NOPREFIX = 0x0004;

        public const uint LWS_USEVISUALSTYLE = 0x0008;

        public const uint LWS_USECUSTOMTEXT = 0x0010;

        public const uint LWS_RIGHT = 0x0020;

        public const uint LIF_ITEMINDEX = 0x00000001;

        public const uint LIF_STATE = 0x00000002;

        public const uint LIF_ITEMID = 0x00000004;

        public const uint LIF_URL = 0x00000008;

        public const uint LIS_FOCUSED = 0x00000001;

        public const uint LIS_ENABLED = 0x00000002;

        public const uint LIS_VISITED = 0x00000004;

        public const uint LIS_HOTTRACK = 0x00000008;

        public const uint LIS_DEFAULTCOLORS = 0x00000010;

        public const uint LM_HITTEST = WM_USER+0x300;

        public const uint LM_GETIDEALHEIGHT = WM_USER+0x301;

        public const uint LM_SETITEM = WM_USER+0x302;

        public const uint LM_GETITEM = WM_USER+0x303;

        public const uint LVS_ICON = 0x0000;

        public const uint LVS_REPORT = 0x0001;

        public const uint LVS_SMALLICON = 0x0002;

        public const uint LVS_LIST = 0x0003;

        public const uint LVS_TYPEMASK = 0x0003;

        public const uint LVS_SINGLESEL = 0x0004;

        public const uint LVS_SHOWSELALWAYS = 0x0008;

        public const uint LVS_SORTASCENDING = 0x0010;

        public const uint LVS_SORTDESCENDING = 0x0020;

        public const uint LVS_SHAREIMAGELISTS = 0x0040;

        public const uint LVS_NOLABELWRAP = 0x0080;

        public const uint LVS_AUTOARRANGE = 0x0100;

        public const uint LVS_EDITLABELS = 0x0200;

        public const uint LVS_OWNERDATA = 0x1000;

        public const uint LVS_NOSCROLL = 0x2000;

        public const uint LVS_TYPESTYLEMASK = 0xfc00;

        public const uint LVS_ALIGNTOP = 0x0000;

        public const uint LVS_ALIGNLEFT = 0x0800;

        public const uint LVS_ALIGNMASK = 0x0c00;

        public const uint LVS_OWNERDRAWFIXED = 0x0400;

        public const uint LVS_NOCOLUMNHEADER = 0x4000;

        public const uint LVS_NOSORTHEADER = 0x8000;

        public const uint LVM_GETBKCOLOR = LVM_FIRST + 0;

        public const uint LVM_SETBKCOLOR = LVM_FIRST + 1;

        public const uint LVM_GETIMAGELIST = LVM_FIRST + 2;

        public const uint LVSIL_NORMAL = 0;

        public const uint LVSIL_SMALL = 1;

        public const uint LVSIL_STATE = 2;

        public const uint LVSIL_GROUPHEADER = 3;

        public const uint LVM_SETIMAGELIST = LVM_FIRST + 3;

        public const uint LVM_GETITEMCOUNT = LVM_FIRST + 4;

        public const uint LVIF_TEXT = 0x00000001;

        public const uint LVIF_IMAGE = 0x00000002;

        public const uint LVIF_PARAM = 0x00000004;

        public const uint LVIF_STATE = 0x00000008;

        public const uint LVIF_INDENT = 0x00000010;

        public const uint LVIF_NORECOMPUTE = 0x00000800;

        public const uint LVIF_GROUPID = 0x00000100;

        public const uint LVIF_COLUMNS = 0x00000200;

        public const uint LVIF_COLFMT = 0x00010000;

        public const uint LVIS_FOCUSED = 0x0001;

        public const uint LVIS_SELECTED = 0x0002;

        public const uint LVIS_CUT = 0x0004;

        public const uint LVIS_DROPHILITED = 0x0008;

        public const uint LVIS_GLOW = 0x0010;

        public const uint LVIS_ACTIVATING = 0x0020;

        public const uint LVIS_OVERLAYMASK = 0x0F00;

        public const uint LVIS_STATEIMAGEMASK = 0xF000;

        public const int I_INDENTCALLBACK = -1;

        public const int I_IMAGECALLBACK = -1;

        public const int I_IMAGENONE = -2;

        public const uint LVM_GETITEMA = LVM_FIRST + 5;

        public const uint LVM_GETITEMW = LVM_FIRST + 75;

        public const uint LVM_SETITEMA = LVM_FIRST + 6;

        public const uint LVM_SETITEMW = LVM_FIRST + 76;

        public const uint LVM_INSERTITEMA = LVM_FIRST + 7;

        public const uint LVM_INSERTITEMW = LVM_FIRST + 77;

        public const uint LVM_DELETEITEM = LVM_FIRST + 8;

        public const uint LVM_DELETEALLITEMS = LVM_FIRST + 9;

        public const uint LVM_GETCALLBACKMASK = LVM_FIRST + 10;

        public const uint LVM_SETCALLBACKMASK = LVM_FIRST + 11;

        public const uint LVNI_ALL = 0x0000;

        public const uint LVNI_FOCUSED = 0x0001;

        public const uint LVNI_SELECTED = 0x0002;

        public const uint LVNI_CUT = 0x0004;

        public const uint LVNI_DROPHILITED = 0x0008;

        public const uint LVNI_VISIBLEORDER = 0x0010;

        public const uint LVNI_PREVIOUS = 0x0020;

        public const uint LVNI_VISIBLEONLY = 0x0040;

        public const uint LVNI_SAMEGROUPONLY = 0x0080;

        public const uint LVNI_ABOVE = 0x0100;

        public const uint LVNI_BELOW = 0x0200;

        public const uint LVNI_TOLEFT = 0x0400;

        public const uint LVNI_TORIGHT = 0x0800;

        public const uint LVM_GETNEXTITEM = LVM_FIRST + 12;

        public const uint LVM_FINDITEMA = LVM_FIRST + 13;

        public const uint LVM_FINDITEMW = LVM_FIRST + 83;

        public const uint LVIR_BOUNDS = 0;

        public const uint LVIR_ICON = 1;

        public const uint LVIR_LABEL = 2;

        public const uint LVIR_SELECTBOUNDS = 3;

        public const uint LVM_GETITEMRECT = LVM_FIRST + 14;

        public const uint LVM_SETITEMPOSITION = LVM_FIRST + 15;

        public const uint LVM_GETITEMPOSITION = LVM_FIRST + 16;

        public const uint LVM_GETSTRINGWIDTHA = LVM_FIRST + 17;

        public const uint LVM_GETSTRINGWIDTHW = LVM_FIRST + 87;

        public const uint LVM_HITTEST = LVM_FIRST + 18;

        public const uint LVM_ENSUREVISIBLE = LVM_FIRST + 19;

        public const uint LVM_SCROLL = LVM_FIRST + 20;

        public const uint LVM_REDRAWITEMS = LVM_FIRST + 21;

        public const uint LVA_DEFAULT = 0x0000;

        public const uint LVA_ALIGNLEFT = 0x0001;

        public const uint LVA_ALIGNTOP = 0x0002;

        public const uint LVA_SNAPTOGRID = 0x0005;

        public const uint LVM_ARRANGE = LVM_FIRST + 22;

        public const uint LVM_EDITLABELA = LVM_FIRST + 23;

        public const uint LVM_EDITLABELW = LVM_FIRST + 118;

        public const uint LVM_GETEDITCONTROL = LVM_FIRST + 24;

        public const uint LVCFMT_LINE_BREAK = 0x100000;

        public const uint LVCFMT_FILL = 0x200000;

        public const uint LVCFMT_WRAP = 0x400000;

        public const uint LVCFMT_NO_TITLE = 0x800000;

        public const uint LVM_GETCOLUMNA = LVM_FIRST + 25;

        public const uint LVM_GETCOLUMNW = LVM_FIRST + 95;

        public const uint LVM_SETCOLUMNA = LVM_FIRST + 26;

        public const uint LVM_SETCOLUMNW = LVM_FIRST + 96;

        public const uint LVM_INSERTCOLUMNA = LVM_FIRST + 27;

        public const uint LVM_INSERTCOLUMNW = LVM_FIRST + 97;

        public const uint LVM_DELETECOLUMN = LVM_FIRST + 28;

        public const uint LVM_GETCOLUMNWIDTH = LVM_FIRST + 29;

        public const int LVSCW_AUTOSIZE = -1;

        public const int LVSCW_AUTOSIZE_USEHEADER = -2;

        public const uint LVM_SETCOLUMNWIDTH = LVM_FIRST + 30;

        public const uint LVM_GETHEADER = LVM_FIRST + 31;

        public const uint LVM_CREATEDRAGIMAGE = LVM_FIRST + 33;

        public const uint LVM_GETVIEWRECT = LVM_FIRST + 34;

        public const uint LVM_GETTEXTCOLOR = LVM_FIRST + 35;

        public const uint LVM_SETTEXTCOLOR = LVM_FIRST + 36;

        public const uint LVM_GETTEXTBKCOLOR = LVM_FIRST + 37;

        public const uint LVM_SETTEXTBKCOLOR = LVM_FIRST + 38;

        public const uint LVM_GETTOPINDEX = LVM_FIRST + 39;

        public const uint LVM_GETCOUNTPERPAGE = LVM_FIRST + 40;

        public const uint LVM_GETORIGIN = LVM_FIRST + 41;

        public const uint LVM_UPDATE = LVM_FIRST + 42;

        public const uint LVM_SETITEMSTATE = LVM_FIRST + 43;

        public const uint LVM_GETITEMSTATE = LVM_FIRST + 44;

        public const uint LVM_GETITEMTEXTA = LVM_FIRST + 45;

        public const uint LVM_GETITEMTEXTW = LVM_FIRST + 115;

        public const uint LVM_SETITEMTEXTA = LVM_FIRST + 46;

        public const uint LVM_SETITEMTEXTW = LVM_FIRST + 116;

        public const uint LVSICF_NOINVALIDATEALL = 0x00000001;

        public const uint LVSICF_NOSCROLL = 0x00000002;

        public const uint LVM_SETITEMCOUNT = LVM_FIRST + 47;

        public const uint LVM_SORTITEMS = LVM_FIRST + 48;

        public const uint LVM_SETITEMPOSITION32 = LVM_FIRST + 49;

        public const uint LVM_GETSELECTEDCOUNT = LVM_FIRST + 50;

        public const uint LVM_GETITEMSPACING = LVM_FIRST + 51;

        public const uint LVM_GETISEARCHSTRINGA = LVM_FIRST + 52;

        public const uint LVM_GETISEARCHSTRINGW = LVM_FIRST + 117;

        public const uint LVM_SETICONSPACING = LVM_FIRST + 53;

        public const uint LVM_SETEXTENDEDLISTVIEWSTYLE = LVM_FIRST + 54;

        public const uint LVM_GETEXTENDEDLISTVIEWSTYLE = LVM_FIRST + 55;

        public const uint LVS_EX_GRIDLINES = 0x00000001;

        public const uint LVS_EX_SUBITEMIMAGES = 0x00000002;

        public const uint LVS_EX_CHECKBOXES = 0x00000004;

        public const uint LVS_EX_TRACKSELECT = 0x00000008;

        public const uint LVS_EX_HEADERDRAGDROP = 0x00000010;

        public const uint LVS_EX_FULLROWSELECT = 0x00000020;

        public const uint LVS_EX_ONECLICKACTIVATE = 0x00000040;

        public const uint LVS_EX_TWOCLICKACTIVATE = 0x00000080;

        public const uint LVS_EX_FLATSB = 0x00000100;

        public const uint LVS_EX_REGIONAL = 0x00000200;

        public const uint LVS_EX_INFOTIP = 0x00000400;

        public const uint LVS_EX_UNDERLINEHOT = 0x00000800;

        public const uint LVS_EX_UNDERLINECOLD = 0x00001000;

        public const uint LVS_EX_MULTIWORKAREAS = 0x00002000;

        public const uint LVS_EX_LABELTIP = 0x00004000;

        public const uint LVS_EX_BORDERSELECT = 0x00008000;

        public const uint LVS_EX_DOUBLEBUFFER = 0x00010000;

        public const uint LVS_EX_HIDELABELS = 0x00020000;

        public const uint LVS_EX_SINGLEROW = 0x00040000;

        public const uint LVS_EX_SNAPTOGRID = 0x00080000;

        public const uint LVS_EX_SIMPLESELECT = 0x00100000;

        public const uint LVS_EX_JUSTIFYCOLUMNS = 0x00200000;

        public const uint LVS_EX_TRANSPARENTBKGND = 0x00400000;

        public const uint LVS_EX_TRANSPARENTSHADOWTEXT = 0x00800000;

        public const uint LVS_EX_AUTOAUTOARRANGE = 0x01000000;

        public const uint LVS_EX_HEADERINALLVIEWS = 0x02000000;

        public const uint LVS_EX_AUTOCHECKSELECT = 0x08000000;

        public const uint LVS_EX_AUTOSIZECOLUMNS = 0x10000000;

        public const uint LVS_EX_COLUMNSNAPPOINTS = 0x40000000;

        public const uint LVS_EX_COLUMNOVERFLOW = 0x80000000;

        public const uint LVM_GETSUBITEMRECT = LVM_FIRST + 56;

        public const uint LVM_SUBITEMHITTEST = LVM_FIRST + 57;

        public const uint LVM_SETCOLUMNORDERARRAY = LVM_FIRST + 58;

        public const uint LVM_GETCOLUMNORDERARRAY = LVM_FIRST + 59;

        public const uint LVM_SETHOTITEM = LVM_FIRST + 60;

        public const uint LVM_GETHOTITEM = LVM_FIRST + 61;

        public const uint LVM_SETHOTCURSOR = LVM_FIRST + 62;

        public const uint LVM_GETHOTCURSOR = LVM_FIRST + 63;

        public const uint LVM_APPROXIMATEVIEWRECT = LVM_FIRST + 64;

        public const uint LV_MAX_WORKAREAS = 16;

        public const uint LVM_SETWORKAREAS = LVM_FIRST + 65;

        public const uint LVM_GETWORKAREAS = LVM_FIRST + 70;

        public const uint LVM_GETNUMBEROFWORKAREAS = LVM_FIRST + 73;

        public const uint LVM_GETSELECTIONMARK = LVM_FIRST + 66;

        public const uint LVM_SETSELECTIONMARK = LVM_FIRST + 67;

        public const uint LVM_SETHOVERTIME = LVM_FIRST + 71;

        public const uint LVM_GETHOVERTIME = LVM_FIRST + 72;

        public const uint LVM_SETTOOLTIPS = LVM_FIRST + 74;

        public const uint LVM_GETTOOLTIPS = LVM_FIRST + 78;

        public const uint LVM_SORTITEMSEX = LVM_FIRST + 81;

        public const uint LVBKIF_SOURCE_NONE = 0x00000000;

        public const uint LVBKIF_SOURCE_HBITMAP = 0x00000001;

        public const uint LVBKIF_SOURCE_URL = 0x00000002;

        public const uint LVBKIF_SOURCE_MASK = 0x00000003;

        public const uint LVBKIF_STYLE_NORMAL = 0x00000000;

        public const uint LVBKIF_STYLE_TILE = 0x00000010;

        public const uint LVBKIF_STYLE_MASK = 0x00000010;

        public const uint LVBKIF_FLAG_TILEOFFSET = 0x00000100;

        public const uint LVBKIF_TYPE_WATERMARK = 0x10000000;

        public const uint LVBKIF_FLAG_ALPHABLEND = 0x20000000;

        public const uint LVM_SETBKIMAGEA = LVM_FIRST + 68;

        public const uint LVM_SETBKIMAGEW = LVM_FIRST + 138;

        public const uint LVM_GETBKIMAGEA = LVM_FIRST + 69;

        public const uint LVM_GETBKIMAGEW = LVM_FIRST + 139;

        public const uint LVM_SETSELECTEDCOLUMN = LVM_FIRST + 140;

        public const uint LV_VIEW_ICON = 0x0000;

        public const uint LV_VIEW_DETAILS = 0x0001;

        public const uint LV_VIEW_SMALLICON = 0x0002;

        public const uint LV_VIEW_LIST = 0x0003;

        public const uint LV_VIEW_TILE = 0x0004;

        public const uint LV_VIEW_MAX = 0x0004;

        public const uint LVM_SETVIEW = LVM_FIRST + 142;

        public const uint LVM_GETVIEW = LVM_FIRST + 143;

        public const uint LVGF_ALIGN = 0x00000008;

        public const uint LVGF_GROUPID = 0x00000010;

        public const uint LVGF_SUBTITLE = 0x00000100;

        public const uint LVGF_TASK = 0x00000200;

        public const uint LVGF_DESCRIPTIONTOP = 0x00000400;

        public const uint LVGF_DESCRIPTIONBOTTOM = 0x00000800;

        public const uint LVGF_TITLEIMAGE = 0x00001000;

        public const uint LVGF_EXTENDEDIMAGE = 0x00002000;

        public const uint LVGF_ITEMS = 0x00004000;

        public const uint LVGF_SUBSET = 0x00008000;

        public const uint LVGF_SUBSETITEMS = 0x00010000;

        public const uint LVGS_NORMAL = 0x00000000;

        public const uint LVGS_COLLAPSED = 0x00000001;

        public const uint LVGS_HIDDEN = 0x00000002;

        public const uint LVGS_NOHEADER = 0x00000004;

        public const uint LVGS_COLLAPSIBLE = 0x00000008;

        public const uint LVGS_FOCUSED = 0x00000010;

        public const uint LVGS_SELECTED = 0x00000020;

        public const uint LVGS_SUBSETED = 0x00000040;

        public const uint LVGS_SUBSETLINKFOCUSED = 0x00000080;

        public const uint LVGA_FOOTER_LEFT = 0x00000008;

        public const uint LVGA_FOOTER_CENTER = 0x00000010;

        public const uint LVGA_FOOTER_RIGHT = 0x00000020;

        public const uint LVM_INSERTGROUP = LVM_FIRST + 145;

        public const uint LVM_SETGROUPINFO = LVM_FIRST + 147;

        public const uint LVM_GETGROUPINFO = LVM_FIRST + 149;

        public const uint LVM_REMOVEGROUP = LVM_FIRST + 150;

        public const uint LVM_MOVEGROUP = LVM_FIRST + 151;

        public const uint LVM_GETGROUPCOUNT = LVM_FIRST + 152;

        public const uint LVM_GETGROUPINFOBYINDEX = LVM_FIRST + 153;

        public const uint LVM_MOVEITEMTOGROUP = LVM_FIRST + 154;

        public const uint LVGGR_GROUP = 0;

        public const uint LVGGR_HEADER = 1;

        public const uint LVGGR_LABEL = 2;

        public const uint LVGGR_SUBSETLINK = 3;

        public const uint LVM_GETGROUPRECT = LVM_FIRST + 98;

        public const uint LVGMF_NONE = 0x00000000;

        public const uint LVGMF_BORDERSIZE = 0x00000001;

        public const uint LVGMF_BORDERCOLOR = 0x00000002;

        public const uint LVGMF_TEXTCOLOR = 0x00000004;

        public const uint LVM_SETGROUPMETRICS = LVM_FIRST + 155;

        public const uint LVM_GETGROUPMETRICS = LVM_FIRST + 156;

        public const uint LVM_ENABLEGROUPVIEW = LVM_FIRST + 157;

        public const uint LVM_SORTGROUPS = LVM_FIRST + 158;

        public const uint LVM_INSERTGROUPSORTED = LVM_FIRST + 159;

        public const uint LVM_REMOVEALLGROUPS = LVM_FIRST + 160;

        public const uint LVM_HASGROUP = LVM_FIRST + 161;

        public const uint LVM_GETGROUPSTATE = LVM_FIRST + 92;

        public const uint LVM_GETFOCUSEDGROUP = LVM_FIRST + 93;

        public const uint LVTVIF_AUTOSIZE = 0x00000000;

        public const uint LVTVIF_FIXEDWIDTH = 0x00000001;

        public const uint LVTVIF_FIXEDHEIGHT = 0x00000002;

        public const uint LVTVIF_FIXEDSIZE = 0x00000003;

        public const uint LVTVIM_TILESIZE = 0x00000001;

        public const uint LVTVIM_COLUMNS = 0x00000002;

        public const uint LVTVIM_LABELMARGIN = 0x00000004;

        public const uint LVM_SETTILEVIEWINFO = LVM_FIRST + 162;

        public const uint LVM_GETTILEVIEWINFO = LVM_FIRST + 163;

        public const uint LVM_SETTILEINFO = LVM_FIRST + 164;

        public const uint LVM_GETTILEINFO = LVM_FIRST + 165;

        public const uint LVIM_AFTER = 0x00000001;

        public const uint LVM_SETINSERTMARK = LVM_FIRST + 166;

        public const uint LVM_GETINSERTMARK = LVM_FIRST + 167;

        public const uint LVM_INSERTMARKHITTEST = LVM_FIRST + 168;

        public const uint LVM_GETINSERTMARKRECT = LVM_FIRST + 169;

        public const uint LVM_SETINSERTMARKCOLOR = LVM_FIRST + 170;

        public const uint LVM_GETINSERTMARKCOLOR = LVM_FIRST + 171;

        public const uint LVM_SETINFOTIP = LVM_FIRST + 173;

        public const uint LVM_GETSELECTEDCOLUMN = LVM_FIRST + 174;

        public const uint LVM_ISGROUPVIEWENABLED = LVM_FIRST + 175;

        public const uint LVM_GETOUTLINECOLOR = LVM_FIRST + 176;

        public const uint LVM_SETOUTLINECOLOR = LVM_FIRST + 177;

        public const uint LVM_CANCELEDITLABEL = LVM_FIRST + 179;

        public const uint LVM_MAPINDEXTOID = LVM_FIRST + 180;

        public const uint LVM_MAPIDTOINDEX = LVM_FIRST + 181;

        public const uint LVM_ISITEMVISIBLE = LVM_FIRST + 182;

        public const uint LVM_GETEMPTYTEXT = LVM_FIRST + 204;

        public const uint LVM_GETFOOTERRECT = LVM_FIRST + 205;

        public const uint LVFF_ITEMCOUNT = 0x00000001;

        public const uint LVM_GETFOOTERINFO = LVM_FIRST + 206;

        public const uint LVM_GETFOOTERITEMRECT = LVM_FIRST + 207;

        public const uint LVFIS_FOCUSED = 0x0001;

        public const uint LVM_GETFOOTERITEM = LVM_FIRST + 208;

        public const uint LVM_GETITEMINDEXRECT = LVM_FIRST + 209;

        public const uint LVM_SETITEMINDEXSTATE = LVM_FIRST + 210;

        public const uint LVM_GETNEXTITEMINDEX = LVM_FIRST + 211;

        public const uint LVKF_ALT = 0x0001;

        public const uint LVKF_CONTROL = 0x0002;

        public const uint LVKF_SHIFT = 0x0004;

        public const uint LVCDRF_NOSELECT = 0x00010000;

        public const uint LVCDRF_NOGROUPFRAME = 0x00020000;

        public const uint LVIF_DI_SETITEM = 0x1000;

        public const uint LVGIT_UNFOLDED = 0x0001;

        public const int LVNSCH_DEFAULT = -1;

        public const int LVNSCH_ERROR = -2;

        public const int LVNSCH_IGNORE = -3;

        public const uint TVS_HASBUTTONS = 0x0001;

        public const uint TVS_HASLINES = 0x0002;

        public const uint TVS_LINESATROOT = 0x0004;

        public const uint TVS_EDITLABELS = 0x0008;

        public const uint TVS_DISABLEDRAGDROP = 0x0010;

        public const uint TVS_SHOWSELALWAYS = 0x0020;

        public const uint TVS_RTLREADING = 0x0040;

        public const uint TVS_NOTOOLTIPS = 0x0080;

        public const uint TVS_CHECKBOXES = 0x0100;

        public const uint TVS_TRACKSELECT = 0x0200;

        public const uint TVS_SINGLEEXPAND = 0x0400;

        public const uint TVS_INFOTIP = 0x0800;

        public const uint TVS_FULLROWSELECT = 0x1000;

        public const uint TVS_NOSCROLL = 0x2000;

        public const uint TVS_NONEVENHEIGHT = 0x4000;

        public const uint TVS_NOHSCROLL = 0x8000;

        public const uint TVS_EX_NOSINGLECOLLAPSE = 0x0001;

        public const uint TVS_EX_MULTISELECT = 0x0002;

        public const uint TVS_EX_DOUBLEBUFFER = 0x0004;

        public const uint TVS_EX_NOINDENTSTATE = 0x0008;

        public const uint TVS_EX_RICHTOOLTIP = 0x0010;

        public const uint TVS_EX_AUTOHSCROLL = 0x0020;

        public const uint TVS_EX_FADEINOUTEXPANDOS = 0x0040;

        public const uint TVS_EX_PARTIALCHECKBOXES = 0x0080;

        public const uint TVS_EX_EXCLUSIONCHECKBOXES = 0x0100;

        public const uint TVS_EX_DIMMEDCHECKBOXES = 0x0200;

        public const uint TVS_EX_DRAWIMAGEASYNC = 0x0400;

        public const uint TVIS_SELECTED = 0x0002;

        public const uint TVIS_CUT = 0x0004;

        public const uint TVIS_DROPHILITED = 0x0008;

        public const uint TVIS_BOLD = 0x0010;

        public const uint TVIS_EXPANDED = 0x0020;

        public const uint TVIS_EXPANDEDONCE = 0x0040;

        public const uint TVIS_EXPANDPARTIAL = 0x0080;

        public const uint TVIS_OVERLAYMASK = 0x0F00;

        public const uint TVIS_STATEIMAGEMASK = 0xF000;

        public const uint TVIS_USERMASK = 0xF000;

        public const uint TVIS_EX_FLAT = 0x0001;

        public const uint TVIS_EX_DISABLED = 0x0002;

        public const uint TVIS_EX_ALL = 0x0002;

        public const uint TVM_INSERTITEMA = TV_FIRST + 0;

        public const uint TVM_INSERTITEMW = TV_FIRST + 50;

        public const uint TVM_DELETEITEM = TV_FIRST + 1;

        public const uint TVM_EXPAND = TV_FIRST + 2;

        public const uint TVE_COLLAPSE = 0x0001;

        public const uint TVE_EXPAND = 0x0002;

        public const uint TVE_TOGGLE = 0x0003;

        public const uint TVE_EXPANDPARTIAL = 0x4000;

        public const uint TVE_COLLAPSERESET = 0x8000;

        public const uint TVM_GETITEMRECT = TV_FIRST + 4;

        public const uint TVM_GETCOUNT = TV_FIRST + 5;

        public const uint TVM_GETINDENT = TV_FIRST + 6;

        public const uint TVM_SETINDENT = TV_FIRST + 7;

        public const uint TVM_GETIMAGELIST = TV_FIRST + 8;

        public const uint TVSIL_NORMAL = 0;

        public const uint TVSIL_STATE = 2;

        public const uint TVM_SETIMAGELIST = TV_FIRST + 9;

        public const uint TVM_GETNEXTITEM = TV_FIRST + 10;

        public const uint TVGN_ROOT = 0x0000;

        public const uint TVGN_NEXT = 0x0001;

        public const uint TVGN_PREVIOUS = 0x0002;

        public const uint TVGN_PARENT = 0x0003;

        public const uint TVGN_CHILD = 0x0004;

        public const uint TVGN_FIRSTVISIBLE = 0x0005;

        public const uint TVGN_NEXTVISIBLE = 0x0006;

        public const uint TVGN_PREVIOUSVISIBLE = 0x0007;

        public const uint TVGN_DROPHILITE = 0x0008;

        public const uint TVGN_CARET = 0x0009;

        public const uint TVGN_LASTVISIBLE = 0x000A;

        public const uint TVGN_NEXTSELECTED = 0x000B;

        public const uint TVSI_NOSINGLEEXPAND = 0x8000;

        public const uint TVM_SELECTITEM = TV_FIRST + 11;

        public const uint TVM_GETITEMA = TV_FIRST + 12;

        public const uint TVM_GETITEMW = TV_FIRST + 62;

        public const uint TVM_SETITEMA = TV_FIRST + 13;

        public const uint TVM_SETITEMW = TV_FIRST + 63;

        public const uint TVM_EDITLABELA = TV_FIRST + 14;

        public const uint TVM_EDITLABELW = TV_FIRST + 65;

        public const uint TVM_GETEDITCONTROL = TV_FIRST + 15;

        public const uint TVM_GETVISIBLECOUNT = TV_FIRST + 16;

        public const uint TVM_HITTEST = TV_FIRST + 17;

        public const uint TVM_CREATEDRAGIMAGE = TV_FIRST + 18;

        public const uint TVM_SORTCHILDREN = TV_FIRST + 19;

        public const uint TVM_ENSUREVISIBLE = TV_FIRST + 20;

        public const uint TVM_SORTCHILDRENCB = TV_FIRST + 21;

        public const uint TVM_ENDEDITLABELNOW = TV_FIRST + 22;

        public const uint TVM_GETISEARCHSTRINGA = TV_FIRST + 23;

        public const uint TVM_GETISEARCHSTRINGW = TV_FIRST + 64;

        public const uint TVM_SETTOOLTIPS = TV_FIRST + 24;

        public const uint TVM_GETTOOLTIPS = TV_FIRST + 25;

        public const uint TVM_SETINSERTMARK = TV_FIRST + 26;

        public const uint TVM_SETITEMHEIGHT = TV_FIRST + 27;

        public const uint TVM_GETITEMHEIGHT = TV_FIRST + 28;

        public const uint TVM_SETBKCOLOR = TV_FIRST + 29;

        public const uint TVM_SETTEXTCOLOR = TV_FIRST + 30;

        public const uint TVM_GETBKCOLOR = TV_FIRST + 31;

        public const uint TVM_GETTEXTCOLOR = TV_FIRST + 32;

        public const uint TVM_SETSCROLLTIME = TV_FIRST + 33;

        public const uint TVM_GETSCROLLTIME = TV_FIRST + 34;

        public const uint TVM_SETINSERTMARKCOLOR = TV_FIRST + 37;

        public const uint TVM_GETINSERTMARKCOLOR = TV_FIRST + 38;

        public const uint TVM_SETBORDER = TV_FIRST + 35;

        public const uint TVSBF_XBORDER = 0x00000001;

        public const uint TVSBF_YBORDER = 0x00000002;

        public const uint TVM_GETITEMSTATE = TV_FIRST + 39;

        public const uint TVM_SETLINECOLOR = TV_FIRST + 40;

        public const uint TVM_GETLINECOLOR = TV_FIRST + 41;

        public const uint TVM_MAPACCIDTOHTREEITEM = TV_FIRST + 42;

        public const uint TVM_MAPHTREEITEMTOACCID = TV_FIRST + 43;

        public const uint TVM_SETEXTENDEDSTYLE = TV_FIRST + 44;

        public const uint TVM_GETEXTENDEDSTYLE = TV_FIRST + 45;

        public const uint TVM_SETAUTOSCROLLINFO = TV_FIRST + 59;

        public const uint TVM_SETHOT = TV_FIRST + 58;

        public const uint TVM_GETSELECTEDCOUNT = TV_FIRST + 70;

        public const uint TVM_SHOWINFOTIP = TV_FIRST + 71;

        public const uint TVM_GETITEMPARTRECT = TV_FIRST + 72;

        public const uint TVC_UNKNOWN = 0x0000;

        public const uint TVC_BYMOUSE = 0x0001;

        public const uint TVC_BYKEYBOARD = 0x0002;

        public const uint TVNRET_DEFAULT = 0;

        public const uint TVNRET_SKIPOLD = 1;

        public const uint TVNRET_SKIPNEW = 2;

        public const uint TVCDRF_NOIMAGES = 0x00010000;

        public const uint CBEM_INSERTITEMA = WM_USER + 1;

        public const uint CBEM_SETIMAGELIST = WM_USER + 2;

        public const uint CBEM_GETIMAGELIST = WM_USER + 3;

        public const uint CBEM_GETITEMA = WM_USER + 4;

        public const uint CBEM_SETITEMA = WM_USER + 5;

        public const uint CBEM_GETCOMBOCONTROL = WM_USER + 6;

        public const uint CBEM_GETEDITCONTROL = WM_USER + 7;

        public const uint CBEM_SETEXSTYLE = WM_USER + 8;

        public const uint CBEM_SETEXTENDEDSTYLE = WM_USER + 14;

        public const uint CBEM_GETEXSTYLE = WM_USER + 9;

        public const uint CBEM_GETEXTENDEDSTYLE = WM_USER + 9;

        public const uint CBEM_HASEDITCHANGED = WM_USER + 10;

        public const uint CBEM_INSERTITEMW = WM_USER + 11;

        public const uint CBEM_SETITEMW = WM_USER + 12;

        public const uint CBEM_GETITEMW = WM_USER + 13;

        public const uint CBES_EX_NOEDITIMAGE = 0x00000001;

        public const uint CBES_EX_NOEDITIMAGEINDENT = 0x00000002;

        public const uint CBES_EX_PATHWORDBREAKPROC = 0x00000004;

        public const uint CBES_EX_NOSIZELIMIT = 0x00000008;

        public const uint CBES_EX_CASESENSITIVE = 0x00000010;

        public const uint CBES_EX_TEXTENDELLIPSIS = 0x00000020;

        public const uint CBENF_KILLFOCUS = 1;

        public const uint CBENF_RETURN = 2;

        public const uint CBENF_ESCAPE = 3;

        public const uint CBENF_DROPDOWN = 4;

        public const uint CBEMAXSTRLEN = 260;

        public const uint TCS_SCROLLOPPOSITE = 0x0001;

        public const uint TCS_BOTTOM = 0x0002;

        public const uint TCS_RIGHT = 0x0002;

        public const uint TCS_MULTISELECT = 0x0004;

        public const uint TCS_FLATBUTTONS = 0x0008;

        public const uint TCS_FORCEICONLEFT = 0x0010;

        public const uint TCS_FORCELABELLEFT = 0x0020;

        public const uint TCS_HOTTRACK = 0x0040;

        public const uint TCS_VERTICAL = 0x0080;

        public const uint TCS_TABS = 0x0000;

        public const uint TCS_BUTTONS = 0x0100;

        public const uint TCS_SINGLELINE = 0x0000;

        public const uint TCS_MULTILINE = 0x0200;

        public const uint TCS_RIGHTJUSTIFY = 0x0000;

        public const uint TCS_FIXEDWIDTH = 0x0400;

        public const uint TCS_RAGGEDRIGHT = 0x0800;

        public const uint TCS_FOCUSONBUTTONDOWN = 0x1000;

        public const uint TCS_OWNERDRAWFIXED = 0x2000;

        public const uint TCS_TOOLTIPS = 0x4000;

        public const uint TCS_FOCUSNEVER = 0x8000;

        public const uint TCS_EX_FLATSEPARATORS = 0x00000001;

        public const uint TCS_EX_REGISTERDROP = 0x00000002;

        public const uint TCM_GETIMAGELIST = TCM_FIRST + 2;

        public const uint TCM_SETIMAGELIST = TCM_FIRST + 3;

        public const uint TCM_GETITEMCOUNT = TCM_FIRST + 4;

        public const uint TCIS_BUTTONPRESSED = 0x0001;

        public const uint TCIS_HIGHLIGHTED = 0x0002;

        public const uint TCM_GETITEMA = TCM_FIRST + 5;

        public const uint TCM_GETITEMW = TCM_FIRST + 60;

        public const uint TCM_SETITEMA = TCM_FIRST + 6;

        public const uint TCM_SETITEMW = TCM_FIRST + 61;

        public const uint TCM_INSERTITEMA = TCM_FIRST + 7;

        public const uint TCM_INSERTITEMW = TCM_FIRST + 62;

        public const uint TCM_DELETEITEM = TCM_FIRST + 8;

        public const uint TCM_DELETEALLITEMS = TCM_FIRST + 9;

        public const uint TCM_GETITEMRECT = TCM_FIRST + 10;

        public const uint TCM_GETCURSEL = TCM_FIRST + 11;

        public const uint TCM_SETCURSEL = TCM_FIRST + 12;

        public const uint TCM_HITTEST = TCM_FIRST + 13;

        public const uint TCM_SETITEMEXTRA = TCM_FIRST + 14;

        public const uint TCM_ADJUSTRECT = TCM_FIRST + 40;

        public const uint TCM_SETITEMSIZE = TCM_FIRST + 41;

        public const uint TCM_REMOVEIMAGE = TCM_FIRST + 42;

        public const uint TCM_SETPADDING = TCM_FIRST + 43;

        public const uint TCM_GETROWCOUNT = TCM_FIRST + 44;

        public const uint TCM_GETTOOLTIPS = TCM_FIRST + 45;

        public const uint TCM_SETTOOLTIPS = TCM_FIRST + 46;

        public const uint TCM_GETCURFOCUS = TCM_FIRST + 47;

        public const uint TCM_SETCURFOCUS = TCM_FIRST + 48;

        public const uint TCM_SETMINTABWIDTH = TCM_FIRST + 49;

        public const uint TCM_DESELECTALL = TCM_FIRST + 50;

        public const uint TCM_HIGHLIGHTITEM = TCM_FIRST + 51;

        public const uint TCM_SETEXTENDEDSTYLE = TCM_FIRST + 52;

        public const uint TCM_GETEXTENDEDSTYLE = TCM_FIRST + 53;

        public const uint ACS_CENTER = 0x0001;

        public const uint ACS_TRANSPARENT = 0x0002;

        public const uint ACS_AUTOPLAY = 0x0004;

        public const uint ACS_TIMER = 0x0008;

        public const uint ACM_OPENA = WM_USER+100;

        public const uint ACM_OPENW = WM_USER+103;

        public const uint ACM_PLAY = WM_USER+101;

        public const uint ACM_STOP = WM_USER+102;

        public const uint ACM_ISPLAYING = WM_USER+104;

        public const uint ACN_START = 1;

        public const uint ACN_STOP = 2;

        public const uint MCM_FIRST = 0x1000;

        public const uint MCM_GETCURSEL = MCM_FIRST + 1;

        public const uint MCM_SETCURSEL = MCM_FIRST + 2;

        public const uint MCM_GETMAXSELCOUNT = MCM_FIRST + 3;

        public const uint MCM_SETMAXSELCOUNT = MCM_FIRST + 4;

        public const uint MCM_GETSELRANGE = MCM_FIRST + 5;

        public const uint MCM_SETSELRANGE = MCM_FIRST + 6;

        public const uint MCM_GETMONTHRANGE = MCM_FIRST + 7;

        public const uint MCM_SETDAYSTATE = MCM_FIRST + 8;

        public const uint MCM_GETMINREQRECT = MCM_FIRST + 9;

        public const uint MCM_SETCOLOR = MCM_FIRST + 10;

        public const uint MCM_GETCOLOR = MCM_FIRST + 11;

        public const uint MCSC_BACKGROUND = 0;

        public const uint MCSC_TEXT = 1;

        public const uint MCSC_TITLEBK = 2;

        public const uint MCSC_TITLETEXT = 3;

        public const uint MCSC_MONTHBK = 4;

        public const uint MCSC_TRAILINGTEXT = 5;

        public const uint MCM_SETTODAY = MCM_FIRST + 12;

        public const uint MCM_GETTODAY = MCM_FIRST + 13;

        public const uint MCM_HITTEST = MCM_FIRST + 14;

        public const uint MCHT_TITLE = 0x00010000;

        public const uint MCHT_CALENDAR = 0x00020000;

        public const uint MCHT_TODAYLINK = 0x00030000;

        public const uint MCHT_CALENDARCONTROL = 0x00100000;

        public const uint MCHT_NEXT = 0x01000000;

        public const uint MCHT_PREV = 0x02000000;

        public const uint MCHT_NOWHERE = 0x00000000;

        public const uint MCM_SETFIRSTDAYOFWEEK = MCM_FIRST + 15;

        public const uint MCM_GETFIRSTDAYOFWEEK = MCM_FIRST + 16;

        public const uint MCM_GETRANGE = MCM_FIRST + 17;

        public const uint MCM_SETRANGE = MCM_FIRST + 18;

        public const uint MCM_GETMONTHDELTA = MCM_FIRST + 19;

        public const uint MCM_SETMONTHDELTA = MCM_FIRST + 20;

        public const uint MCM_GETMAXTODAYWIDTH = MCM_FIRST + 21;

        public const uint MCMV_MONTH = 0;

        public const uint MCMV_YEAR = 1;

        public const uint MCMV_DECADE = 2;

        public const uint MCMV_CENTURY = 3;

        public const uint MCM_GETCURRENTVIEW = MCM_FIRST + 22;

        public const uint MCM_GETCALENDARCOUNT = MCM_FIRST + 23;

        public const uint MCM_GETCALENDARGRIDINFO = MCM_FIRST + 24;

        public const uint MCM_GETCALID = MCM_FIRST + 27;

        public const uint MCM_SETCALID = MCM_FIRST + 28;

        public const uint MCM_SIZERECTTOMIN = MCM_FIRST + 29;

        public const uint MCM_SETCALENDARBORDER = MCM_FIRST + 30;

        public const uint MCM_GETCALENDARBORDER = MCM_FIRST + 31;

        public const uint MCM_SETCURRENTVIEW = MCM_FIRST + 32;

        public const uint MCS_DAYSTATE = 0x0001;

        public const uint MCS_MULTISELECT = 0x0002;

        public const uint MCS_WEEKNUMBERS = 0x0004;

        public const uint MCS_NOTODAYCIRCLE = 0x0008;

        public const uint MCS_NOTODAY = 0x0010;

        public const uint MCS_NOTRAILINGDATES = 0x0040;

        public const uint MCS_SHORTDAYSOFWEEK = 0x0080;

        public const uint MCS_NOSELCHANGEONNAV = 0x0100;

        public const uint GMR_VISIBLE = 0;

        public const uint GMR_DAYSTATE = 1;

        public const uint DTM_FIRST = 0x1000;

        public const uint DTM_GETSYSTEMTIME = DTM_FIRST + 1;

        public const uint DTM_SETSYSTEMTIME = DTM_FIRST + 2;

        public const uint DTM_GETRANGE = DTM_FIRST + 3;

        public const uint DTM_SETRANGE = DTM_FIRST + 4;

        public const uint DTM_SETFORMATA = DTM_FIRST + 5;

        public const uint DTM_SETFORMATW = DTM_FIRST + 50;

        public const uint DTM_SETMCCOLOR = DTM_FIRST + 6;

        public const uint DTM_GETMCCOLOR = DTM_FIRST + 7;

        public const uint DTM_GETMONTHCAL = DTM_FIRST + 8;

        public const uint DTM_SETMCFONT = DTM_FIRST + 9;

        public const uint DTM_GETMCFONT = DTM_FIRST + 10;

        public const uint DTM_SETMCSTYLE = DTM_FIRST + 11;

        public const uint DTM_GETMCSTYLE = DTM_FIRST + 12;

        public const uint DTM_CLOSEMONTHCAL = DTM_FIRST + 13;

        public const uint DTM_GETDATETIMEPICKERINFO = DTM_FIRST + 14;

        public const uint DTM_GETIDEALSIZE = DTM_FIRST + 15;

        public const uint DTS_UPDOWN = 0x0001;

        public const uint DTS_SHOWNONE = 0x0002;

        public const uint DTS_SHORTDATEFORMAT = 0x0000;

        public const uint DTS_LONGDATEFORMAT = 0x0004;

        public const uint DTS_SHORTDATECENTURYFORMAT = 0x000C;

        public const uint DTS_TIMEFORMAT = 0x0009;

        public const uint DTS_APPCANPARSE = 0x0010;

        public const uint DTS_RIGHTALIGN = 0x0020;

        public const uint GDTR_MIN = 0x0001;

        public const uint GDTR_MAX = 0x0002;

        public const int GDT_ERROR = -1;

        public const uint GDT_VALID = 0;

        public const uint GDT_NONE = 1;

        public const uint IPM_CLEARADDRESS = WM_USER+100;

        public const uint IPM_SETADDRESS = WM_USER+101;

        public const uint IPM_GETADDRESS = WM_USER+102;

        public const uint IPM_SETRANGE = WM_USER+103;

        public const uint IPM_SETFOCUS = WM_USER+104;

        public const uint IPM_ISBLANK = WM_USER+105;

        public const uint PGS_VERT = 0x00000000;

        public const uint PGS_HORZ = 0x00000001;

        public const uint PGS_AUTOSCROLL = 0x00000002;

        public const uint PGS_DRAGNDROP = 0x00000004;

        public const uint PGF_INVISIBLE = 0;

        public const uint PGF_NORMAL = 1;

        public const uint PGF_GRAYED = 2;

        public const uint PGF_DEPRESSED = 4;

        public const uint PGF_HOT = 8;

        public const uint PGB_TOPORLEFT = 0;

        public const uint PGB_BOTTOMORRIGHT = 1;

        public const uint PGM_SETCHILD = PGM_FIRST + 1;

        public const uint PGM_RECALCSIZE = PGM_FIRST + 2;

        public const uint PGM_FORWARDMOUSE = PGM_FIRST + 3;

        public const uint PGM_SETBKCOLOR = PGM_FIRST + 4;

        public const uint PGM_GETBKCOLOR = PGM_FIRST + 5;

        public const uint PGM_SETBORDER = PGM_FIRST + 6;

        public const uint PGM_GETBORDER = PGM_FIRST + 7;

        public const uint PGM_SETPOS = PGM_FIRST + 8;

        public const uint PGM_GETPOS = PGM_FIRST + 9;

        public const uint PGM_SETBUTTONSIZE = PGM_FIRST + 10;

        public const uint PGM_GETBUTTONSIZE = PGM_FIRST + 11;

        public const uint PGM_GETBUTTONSTATE = PGM_FIRST + 12;

        public const uint PGM_SETSCROLLINFO = PGM_FIRST + 13;

        public const uint NFS_EDIT = 0x0001;

        public const uint NFS_STATIC = 0x0002;

        public const uint NFS_LISTCOMBO = 0x0004;

        public const uint NFS_BUTTON = 0x0008;

        public const uint NFS_ALL = 0x0010;

        public const uint NFS_USEFONTASSOC = 0x0020;

        public const uint BCM_GETIDEALSIZE = BCM_FIRST + 0x0001;

        public const uint BCM_SETIMAGELIST = BCM_FIRST + 0x0002;

        public const uint BCM_GETIMAGELIST = BCM_FIRST + 0x0003;

        public const uint BCM_SETTEXTMARGIN = BCM_FIRST + 0x0004;

        public const uint BCM_GETTEXTMARGIN = BCM_FIRST + 0x0005;

        public const uint BCN_HOTITEMCHANGE = BCN_FIRST + 0x0001;

        public const uint BST_HOT = 0x0200;

        public const uint BST_DROPDOWNPUSHED = 0x0400;

        public const int BS_SPLITBUTTON = 0x0000000C;

        public const int BS_DEFSPLITBUTTON = 0x0000000D;

        public const int BS_COMMANDLINK = 0x0000000E;

        public const int BS_DEFCOMMANDLINK = 0x0000000F;

        public const uint BCSIF_GLYPH = 0x0001;

        public const uint BCSIF_IMAGE = 0x0002;

        public const uint BCSIF_STYLE = 0x0004;

        public const uint BCSIF_SIZE = 0x0008;

        public const uint BCSS_NOSPLIT = 0x0001;

        public const uint BCSS_STRETCH = 0x0002;

        public const uint BCSS_ALIGNLEFT = 0x0004;

        public const uint BCSS_IMAGE = 0x0008;

        public const uint BCM_SETDROPDOWNSTATE = BCM_FIRST + 0x0006;

        public const uint BCM_SETSPLITINFO = BCM_FIRST + 0x0007;

        public const uint BCM_GETSPLITINFO = BCM_FIRST + 0x0008;

        public const uint BCM_SETNOTE = BCM_FIRST + 0x0009;

        public const uint BCM_GETNOTE = BCM_FIRST + 0x000A;

        public const uint BCM_GETNOTELENGTH = BCM_FIRST + 0x000B;

        public const uint BCM_SETSHIELD = BCM_FIRST + 0x000C;

        public const uint BCN_DROPDOWN = BCN_FIRST + 0x0002;

        public const int ES_EX_ALLOWEOL_CR = 0x0001;

        public const int ES_EX_ALLOWEOL_LF = 0x0002;

        public const int ES_EX_CONVERT_EOL_ON_PASTE = 0x0004;

        public const int ES_EX_ZOOMABLE = 0x0010;

        public const uint EM_SETCUEBANNER = ECM_FIRST + 1;

        public const uint EM_GETCUEBANNER = ECM_FIRST + 2;

        public const uint EM_SHOWBALLOONTIP = ECM_FIRST + 3;

        public const uint EM_HIDEBALLOONTIP = ECM_FIRST + 4;

        public const uint EM_SETHILITE = ECM_FIRST + 5;

        public const uint EM_GETHILITE = ECM_FIRST + 6;

        public const uint EM_NOSETFOCUS = ECM_FIRST + 7;

        public const uint EM_TAKEFOCUS = ECM_FIRST + 8;

        public const uint EM_SETEXTENDEDSTYLE = ECM_FIRST + 10;

        public const uint EM_GETEXTENDEDSTYLE = ECM_FIRST + 11;

        public const uint EM_SETENDOFLINE = ECM_FIRST + 12;

        public const uint EM_GETENDOFLINE = ECM_FIRST + 13;

        public const uint EM_ENABLESEARCHWEB = ECM_FIRST + 14;

        public const uint EM_SEARCHWEB = ECM_FIRST + 15;

        public const uint EM_SETCARETINDEX = ECM_FIRST + 17;

        public const uint EM_GETCARETINDEX = ECM_FIRST + 18;

        public const uint EM_FILELINEFROMCHAR = ECM_FIRST + 19;

        public const uint EM_FILELINEINDEX = ECM_FIRST + 20;

        public const uint EM_FILELINELENGTH = ECM_FIRST + 21;

        public const uint EM_GETFILELINE = ECM_FIRST + 22;

        public const uint EM_GETFILELINECOUNT = ECM_FIRST + 23;

        public const uint CB_SETMINVISIBLE = CBM_FIRST + 1;

        public const uint CB_GETMINVISIBLE = CBM_FIRST + 2;

        public const uint CB_SETCUEBANNER = CBM_FIRST + 3;

        public const uint CB_GETCUEBANNER = CBM_FIRST + 4;

        public const uint WM_MOUSEHOVER = 0x02A1;

        public const uint WM_MOUSELEAVE = 0x02A3;

        public const uint HOVER_DEFAULT = 0xFFFFFFFF;

        public const int WSB_PROP_MASK = 0x00000FFF;

        public const uint FSB_FLAT_MODE = 2;

        public const uint FSB_ENCARTA_MODE = 1;

        public const uint FSB_REGULAR_MODE = 0;

        public const uint EM_GETSEL = 0x00B0;

        public const uint EM_SETSEL = 0x00B1;

        public const uint EM_GETRECT = 0x00B2;

        public const uint EM_SETRECT = 0x00B3;

        public const uint EM_SETRECTNP = 0x00B4;

        public const uint EM_SCROLL = 0x00B5;

        public const uint EM_LINESCROLL = 0x00B6;

        public const uint EM_GETMODIFY = 0x00B8;

        public const uint EM_SETMODIFY = 0x00B9;

        public const uint EM_GETLINECOUNT = 0x00BA;

        public const uint EM_LINEINDEX = 0x00BB;

        public const uint EM_SETHANDLE = 0x00BC;

        public const uint EM_GETHANDLE = 0x00BD;

        public const uint EM_GETTHUMB = 0x00BE;

        public const uint EM_LINELENGTH = 0x00C1;

        public const uint EM_REPLACESEL = 0x00C2;

        public const uint EM_GETLINE = 0x00C4;

        public const uint EM_LIMITTEXT = 0x00C5;

        public const uint EM_CANUNDO = 0x00C6;

        public const uint EM_UNDO = 0x00C7;

        public const uint EM_FMTLINES = 0x00C8;

        public const uint EM_LINEFROMCHAR = 0x00C9;

        public const uint EM_SETTABSTOPS = 0x00CB;

        public const uint EM_SETPASSWORDCHAR = 0x00CC;

        public const uint EM_EMPTYUNDOBUFFER = 0x00CD;

        public const uint EM_GETFIRSTVISIBLELINE = 0x00CE;

        public const uint EM_SETREADONLY = 0x00CF;

        public const uint EM_SETWORDBREAKPROC = 0x00D0;

        public const uint EM_GETWORDBREAKPROC = 0x00D1;

        public const uint EM_GETPASSWORDCHAR = 0x00D2;

        public const uint EM_SETMARGINS = 0x00D3;

        public const uint EM_GETMARGINS = 0x00D4;

        public const uint EM_SETIMESTATUS = 0x00D8;

        public const uint EM_GETIMESTATUS = 0x00D9;

        public const uint EM_ENABLEFEATURE = 0x00DA;

    }
}
