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


namespace Windows.Win32.Data.HtmlHelp
{
    public static partial class Apis
    {
        public const uint HH_DISPLAY_TOPIC = 0x0000;

        public const uint HH_HELP_FINDER = 0x0000;

        public const uint HH_DISPLAY_TOC = 0x0001;

        public const uint HH_DISPLAY_INDEX = 0x0002;

        public const uint HH_DISPLAY_SEARCH = 0x0003;

        public const uint HH_SET_WIN_TYPE = 0x0004;

        public const uint HH_GET_WIN_TYPE = 0x0005;

        public const uint HH_GET_WIN_HANDLE = 0x0006;

        public const uint HH_ENUM_INFO_TYPE = 0x0007;

        public const uint HH_SET_INFO_TYPE = 0x0008;

        public const uint HH_SYNC = 0x0009;

        public const uint HH_RESERVED1 = 0x000A;

        public const uint HH_RESERVED2 = 0x000B;

        public const uint HH_RESERVED3 = 0x000C;

        public const uint HH_KEYWORD_LOOKUP = 0x000D;

        public const uint HH_DISPLAY_TEXT_POPUP = 0x000E;

        public const uint HH_HELP_CONTEXT = 0x000F;

        public const uint HH_TP_HELP_CONTEXTMENU = 0x0010;

        public const uint HH_TP_HELP_WM_HELP = 0x0011;

        public const uint HH_CLOSE_ALL = 0x0012;

        public const uint HH_ALINK_LOOKUP = 0x0013;

        public const uint HH_GET_LAST_ERROR = 0x0014;

        public const uint HH_ENUM_CATEGORY = 0x0015;

        public const uint HH_ENUM_CATEGORY_IT = 0x0016;

        public const uint HH_RESET_IT_FILTER = 0x0017;

        public const uint HH_SET_INCLUSIVE_FILTER = 0x0018;

        public const uint HH_SET_EXCLUSIVE_FILTER = 0x0019;

        public const uint HH_INITIALIZE = 0x001C;

        public const uint HH_UNINITIALIZE = 0x001D;

        public const uint HH_SET_QUERYSERVICE = 0x001E;

        public const uint HH_PRETRANSLATEMESSAGE = 0x00fd;

        public const uint HH_SET_GLOBAL_PROPERTY = 0x00fc;

        public const uint HH_SAFE_DISPLAY_TOPIC = 0x0020;

        public const uint HHWIN_PROP_TAB_AUTOHIDESHOW = 1u<< 0;

        public const uint HHWIN_PROP_ONTOP = 1u<< 1;

        public const uint HHWIN_PROP_NOTITLEBAR = 1u<< 2;

        public const uint HHWIN_PROP_NODEF_STYLES = 1u<< 3;

        public const uint HHWIN_PROP_NODEF_EXSTYLES = 1u<< 4;

        public const uint HHWIN_PROP_TRI_PANE = 1u<< 5;

        public const uint HHWIN_PROP_NOTB_TEXT = 1u<< 6;

        public const uint HHWIN_PROP_POST_QUIT = 1u<< 7;

        public const uint HHWIN_PROP_AUTO_SYNC = 1u<< 8;

        public const uint HHWIN_PROP_TRACKING = 1u<< 9;

        public const uint HHWIN_PROP_TAB_SEARCH = 1u<< 10;

        public const uint HHWIN_PROP_TAB_HISTORY = 1u<< 11;

        public const uint HHWIN_PROP_TAB_FAVORITES = 1u<< 12;

        public const uint HHWIN_PROP_CHANGE_TITLE = 1u<< 13;

        public const uint HHWIN_PROP_NAV_ONLY_WIN = 1u<< 14;

        public const uint HHWIN_PROP_NO_TOOLBAR = 1u<< 15;

        public const uint HHWIN_PROP_MENU = 1u<< 16;

        public const uint HHWIN_PROP_TAB_ADVSEARCH = 1u<< 17;

        public const uint HHWIN_PROP_USER_POS = 1u<< 18;

        public const uint HHWIN_PROP_TAB_CUSTOM1 = 1u<< 19;

        public const uint HHWIN_PROP_TAB_CUSTOM2 = 1u<< 20;

        public const uint HHWIN_PROP_TAB_CUSTOM3 = 1u<< 21;

        public const uint HHWIN_PROP_TAB_CUSTOM4 = 1u<< 22;

        public const uint HHWIN_PROP_TAB_CUSTOM5 = 1u<< 23;

        public const uint HHWIN_PROP_TAB_CUSTOM6 = 1u<< 24;

        public const uint HHWIN_PROP_TAB_CUSTOM7 = 1u<< 25;

        public const uint HHWIN_PROP_TAB_CUSTOM8 = 1u<< 26;

        public const uint HHWIN_PROP_TAB_CUSTOM9 = 1u<< 27;

        public const uint HHWIN_TB_MARGIN = 1u<< 28;

        public const uint HHWIN_PARAM_PROPERTIES = 1u<< 1;

        public const uint HHWIN_PARAM_STYLES = 1u<< 2;

        public const uint HHWIN_PARAM_EXSTYLES = 1u<< 3;

        public const uint HHWIN_PARAM_RECT = 1u<< 4;

        public const uint HHWIN_PARAM_NAV_WIDTH = 1u<< 5;

        public const uint HHWIN_PARAM_SHOWSTATE = 1u<< 6;

        public const uint HHWIN_PARAM_INFOTYPES = 1u<< 7;

        public const uint HHWIN_PARAM_TB_FLAGS = 1u<< 8;

        public const uint HHWIN_PARAM_EXPANSION = 1u<< 9;

        public const uint HHWIN_PARAM_TABPOS = 1u<< 10;

        public const uint HHWIN_PARAM_TABORDER = 1u<< 11;

        public const uint HHWIN_PARAM_HISTORY_COUNT = 1u<< 12;

        public const uint HHWIN_PARAM_CUR_TAB = 1u<< 13;

        public const uint HHWIN_BUTTON_EXPAND = 1u<< 1;

        public const uint HHWIN_BUTTON_BACK = 1u<< 2;

        public const uint HHWIN_BUTTON_FORWARD = 1u<< 3;

        public const uint HHWIN_BUTTON_STOP = 1u<< 4;

        public const uint HHWIN_BUTTON_REFRESH = 1u<< 5;

        public const uint HHWIN_BUTTON_HOME = 1u<< 6;

        public const uint HHWIN_BUTTON_BROWSE_FWD = 1u<< 7;

        public const uint HHWIN_BUTTON_BROWSE_BCK = 1u<< 8;

        public const uint HHWIN_BUTTON_NOTES = 1u<< 9;

        public const uint HHWIN_BUTTON_CONTENTS = 1u<< 10;

        public const uint HHWIN_BUTTON_SYNC = 1u<< 11;

        public const uint HHWIN_BUTTON_OPTIONS = 1u<< 12;

        public const uint HHWIN_BUTTON_PRINT = 1u<< 13;

        public const uint HHWIN_BUTTON_INDEX = 1u<< 14;

        public const uint HHWIN_BUTTON_SEARCH = 1u<< 15;

        public const uint HHWIN_BUTTON_HISTORY = 1u<< 16;

        public const uint HHWIN_BUTTON_FAVORITES = 1u<< 17;

        public const uint HHWIN_BUTTON_JUMP1 = 1u<< 18;

        public const uint HHWIN_BUTTON_JUMP2 = 1u<< 19;

        public const uint HHWIN_BUTTON_ZOOM = 1u<< 20;

        public const uint HHWIN_BUTTON_TOC_NEXT = 1u<< 21;

        public const uint HHWIN_BUTTON_TOC_PREV = 1u<< 22;

        public const uint IDTB_EXPAND = 200;

        public const uint IDTB_CONTRACT = 201;

        public const uint IDTB_STOP = 202;

        public const uint IDTB_REFRESH = 203;

        public const uint IDTB_BACK = 204;

        public const uint IDTB_HOME = 205;

        public const uint IDTB_SYNC = 206;

        public const uint IDTB_PRINT = 207;

        public const uint IDTB_OPTIONS = 208;

        public const uint IDTB_FORWARD = 209;

        public const uint IDTB_NOTES = 210;

        public const uint IDTB_BROWSE_FWD = 211;

        public const uint IDTB_BROWSE_BACK = 212;

        public const uint IDTB_CONTENTS = 213;

        public const uint IDTB_INDEX = 214;

        public const uint IDTB_SEARCH = 215;

        public const uint IDTB_HISTORY = 216;

        public const uint IDTB_FAVORITES = 217;

        public const uint IDTB_JUMP1 = 218;

        public const uint IDTB_JUMP2 = 219;

        public const uint IDTB_CUSTOMIZE = 221;

        public const uint IDTB_ZOOM = 222;

        public const uint IDTB_TOC_NEXT = 223;

        public const uint IDTB_TOC_PREV = 224;

        public const uint HH_MAX_TABS = 19;

        public const int HH_FTS_DEFAULT_PROXIMITY = -1;

        public static readonly Guid IID_IITPropList__scanned__ = new Guid(0x1f403bb1, 0x9997, 0x11d0, 0xa8, 0x50, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1);

        public static readonly Guid CLSID_IITPropList__scanned__ = new Guid(0x4662daae, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public const uint PROP_ADD = 0x00000000;

        public const uint PROP_DELETE = 0x00000001;

        public const uint PROP_UPDATE = 0x00000002;

        public const uint TYPE_VALUE = 0x00000000;

        public const uint TYPE_POINTER = 0x00000001;

        public const uint TYPE_STRING = 0x00000002;

        public static readonly Guid IID_IITDatabase__scanned__ = new Guid(0x8fa0d5a2, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITDatabase__scanned__ = new Guid(0x66673452, 0x8c23, 0x11d0, 0xa8, 0x4e, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1);

        public static readonly Guid CLSID_IITDatabaseLocal__scanned__ = new Guid(0x4662daa9, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public const uint STDPROP_UID = 1;

        public const uint STDPROP_TITLE = 2;

        public const uint STDPROP_USERDATA = 3;

        public const uint STDPROP_KEY = 4;

        public const uint STDPROP_SORTKEY = 100;

        public const uint STDPROP_DISPLAYKEY = 101;

        public const uint STDPROP_SORTORDINAL = 102;

        public const uint STDPROP_INDEX_TEXT = 200;

        public const uint STDPROP_INDEX_VFLD = 201;

        public const uint STDPROP_INDEX_DTYPE = 202;

        public const uint STDPROP_INDEX_LENGTH = 203;

        public const uint STDPROP_INDEX_BREAK = 204;

        public const uint STDPROP_INDEX_TERM = 210;

        public const uint STDPROP_INDEX_TERM_RAW_LENGTH = 211;

        public const uint STDPROP_USERPROP_BASE = 0x00010000;

        public const uint STDPROP_USERPROP_MAX = 0x7FFFFFFF;

        public static readonly Guid CLSID_IITCmdInt__scanned__ = new Guid(0x4662daa2, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITSvMgr__scanned__ = new Guid(0x4662daa3, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid IID_IITCmdInt__scanned__ = new Guid(0x4cf34c30, 0x9bf9, 0x11d0, 0x87, 0x64, 0x0, 0xa0, 0xc9, 0x13, 0xf7, 0x64);

        public static readonly Guid IID_IITSvMgr__scanned__ = new Guid(0x4e7da031, 0x9c11, 0x11d0, 0x87, 0x64, 0x0, 0xa0, 0xc9, 0x13, 0xf7, 0x64);

        public static readonly Guid CLSID_IITWordWheelUpdate__scanned__ = new Guid(0x4662daa5, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid IID_IITBuildCollect__scanned__ = new Guid(0x8fa0d5a5, 0xdedf, 0x11d0, 0x9a, 0x61, 0x0, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITGroupUpdate__scanned__ = new Guid(0x4662daa4, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITIndexBuild__scanned__ = new Guid(0x8fa0d5aa, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITWWFilterBuild__scanned__ = new Guid(0x8fa0d5ab, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid IID_IITWordWheel__scanned__ = new Guid(0x8fa0d5a4, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_IITWordWheel__scanned__ = new Guid(0xd73725c2, 0x8c12, 0x11d0, 0xa8, 0x4e, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1);

        public static readonly Guid CLSID_IITWordWheelLocal__scanned__ = new Guid(0x4662daa8, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public const uint ITWW_OPEN_NOCONNECT = 0x00000001;

        public const uint ITWW_CBKEY_MAX = 1024;

        public const uint IITWBC_BREAK_ACCEPT_WILDCARDS = 0x00000001;

        public const uint IITWBC_BREAK_AND_STEM = 0x00000002;

        [NativeTypeName("HRESULT")]
        public const int E_NOTEXIST = unchecked((int)0x80001000);

        [NativeTypeName("HRESULT")]
        public const int E_DUPLICATE = unchecked((int)0x80001001);

        [NativeTypeName("HRESULT")]
        public const int E_BADVERSION = unchecked((int)0x80001002);

        [NativeTypeName("HRESULT")]
        public const int E_BADFILE = unchecked((int)0x80001003);

        [NativeTypeName("HRESULT")]
        public const int E_BADFORMAT = unchecked((int)0x80001004);

        [NativeTypeName("HRESULT")]
        public const int E_NOPERMISSION = unchecked((int)0x80001005);

        [NativeTypeName("HRESULT")]
        public const int E_ASSERT = unchecked((int)0x80001006);

        [NativeTypeName("HRESULT")]
        public const int E_INTERRUPT = unchecked((int)0x80001007);

        [NativeTypeName("HRESULT")]
        public const int E_NOTSUPPORTED = unchecked((int)0x80001008);

        [NativeTypeName("HRESULT")]
        public const int E_OUTOFRANGE = unchecked((int)0x80001009);

        [NativeTypeName("HRESULT")]
        public const int E_GROUPIDTOOBIG = unchecked((int)0x8000100A);

        [NativeTypeName("HRESULT")]
        public const int E_TOOMANYTITLES = unchecked((int)0x8000100B);

        [NativeTypeName("HRESULT")]
        public const int E_NOMERGEDDATA = unchecked((int)0x8000100C);

        [NativeTypeName("HRESULT")]
        public const int E_NOTFOUND = unchecked((int)0x8000100D);

        [NativeTypeName("HRESULT")]
        public const int E_CANTFINDDLL = unchecked((int)0x8000100E);

        [NativeTypeName("HRESULT")]
        public const int E_NOHANDLE = unchecked((int)0x8000100F);

        [NativeTypeName("HRESULT")]
        public const int E_GETLASTERROR = unchecked((int)0x80001010);

        [NativeTypeName("HRESULT")]
        public const int E_BADPARAM = unchecked((int)0x80001011);

        [NativeTypeName("HRESULT")]
        public const int E_INVALIDSTATE = unchecked((int)0x80001012);

        [NativeTypeName("HRESULT")]
        public const int E_NOTOPEN = unchecked((int)0x80001013);

        [NativeTypeName("HRESULT")]
        public const int E_ALREADYOPEN = unchecked((int)0x80001013);

        [NativeTypeName("HRESULT")]
        public const int E_UNKNOWN_TRANSPORT = unchecked((int)0x80001016);

        [NativeTypeName("HRESULT")]
        public const int E_UNSUPPORTED_TRANSPORT = unchecked((int)0x80001017);

        [NativeTypeName("HRESULT")]
        public const int E_BADFILTERSIZE = unchecked((int)0x80001018);

        [NativeTypeName("HRESULT")]
        public const int E_TOOMANYOBJECTS = unchecked((int)0x80001019);

        [NativeTypeName("HRESULT")]
        public const int E_NAMETOOLONG = unchecked((int)0x80001020);

        [NativeTypeName("HRESULT")]
        public const int E_FILECREATE = unchecked((int)0x80001030);

        [NativeTypeName("HRESULT")]
        public const int E_FILECLOSE = unchecked((int)0x80001031);

        [NativeTypeName("HRESULT")]
        public const int E_FILEREAD = unchecked((int)0x80001032);

        [NativeTypeName("HRESULT")]
        public const int E_FILESEEK = unchecked((int)0x80001033);

        [NativeTypeName("HRESULT")]
        public const int E_FILEWRITE = unchecked((int)0x80001034);

        [NativeTypeName("HRESULT")]
        public const int E_FILEDELETE = unchecked((int)0x80001035);

        [NativeTypeName("HRESULT")]
        public const int E_FILEINVALID = unchecked((int)0x80001036);

        [NativeTypeName("HRESULT")]
        public const int E_FILENOTFOUND = unchecked((int)0x80001037);

        [NativeTypeName("HRESULT")]
        public const int E_DISKFULL = unchecked((int)0x80001038);

        [NativeTypeName("HRESULT")]
        public const int E_TOOMANYTOPICS = unchecked((int)0x80001050);

        [NativeTypeName("HRESULT")]
        public const int E_TOOMANYDUPS = unchecked((int)0x80001051);

        [NativeTypeName("HRESULT")]
        public const int E_TREETOOBIG = unchecked((int)0x80001052);

        [NativeTypeName("HRESULT")]
        public const int E_BADBREAKER = unchecked((int)0x80001053);

        [NativeTypeName("HRESULT")]
        public const int E_BADVALUE = unchecked((int)0x80001054);

        [NativeTypeName("HRESULT")]
        public const int E_ALL_WILD = unchecked((int)0x80001055);

        [NativeTypeName("HRESULT")]
        public const int E_TOODEEP = unchecked((int)0x80001056);

        [NativeTypeName("HRESULT")]
        public const int E_EXPECTEDTERM = unchecked((int)0x80001057);

        [NativeTypeName("HRESULT")]
        public const int E_MISSLPAREN = unchecked((int)0x80001058);

        [NativeTypeName("HRESULT")]
        public const int E_MISSRPAREN = unchecked((int)0x80001059);

        [NativeTypeName("HRESULT")]
        public const int E_MISSQUOTE = unchecked((int)0x8000105A);

        [NativeTypeName("HRESULT")]
        public const int E_NULLQUERY = unchecked((int)0x8000105B);

        [NativeTypeName("HRESULT")]
        public const int E_STOPWORD = unchecked((int)0x8000105C);

        [NativeTypeName("HRESULT")]
        public const int E_BADRANGEOP = unchecked((int)0x8000105D);

        [NativeTypeName("HRESULT")]
        public const int E_UNMATCHEDTYPE = unchecked((int)0x8000105E);

        [NativeTypeName("HRESULT")]
        public const int E_WORDTOOLONG = unchecked((int)0x8000105F);

        [NativeTypeName("HRESULT")]
        public const int E_BADINDEXFLAGS = unchecked((int)0x80001060);

        [NativeTypeName("HRESULT")]
        public const int E_WILD_IN_DTYPE = unchecked((int)0x80001061);

        [NativeTypeName("HRESULT")]
        public const int E_NOSTEMMER = unchecked((int)0x80001062);

        [NativeTypeName("HRESULT")]
        public const int E_MISSINGPROP = unchecked((int)0x80001080);

        [NativeTypeName("HRESULT")]
        public const int E_PROPLISTNOTEMPTY = unchecked((int)0x80001081);

        [NativeTypeName("HRESULT")]
        public const int E_PROPLISTEMPTY = unchecked((int)0x80001082);

        [NativeTypeName("HRESULT")]
        public const int E_ALREADYINIT = unchecked((int)0x80001083);

        [NativeTypeName("HRESULT")]
        public const int E_NOTINIT = unchecked((int)0x80001084);

        [NativeTypeName("HRESULT")]
        public const int E_RESULTSETEMPTY = unchecked((int)0x80001085);

        [NativeTypeName("HRESULT")]
        public const int E_TOOMANYCOLUMNS = unchecked((int)0x80001086);

        [NativeTypeName("HRESULT")]
        public const int E_NOKEYPROP = unchecked((int)0x80001087);

        public static readonly Guid IID_IITResultSet__scanned__ = new Guid(0x3bb91d41, 0x998b, 0x11d0, 0xa8, 0x50, 0x0, 0xaa, 0x0, 0x6c, 0x7d, 0x1);

        public static readonly Guid CLSID_IITResultSet__scanned__ = new Guid(0x4662daa7, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public const uint MAX_COLUMNS = 256;

        public static readonly Guid IID_IWordBreakerConfig__scanned__ = new Guid(0x8fa0d5a6, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_ITStdBreaker__scanned__ = new Guid(0x4662daaf, 0xd393, 0x11d0, 0x9a, 0x56, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid IID_IITStopWordList__scanned__ = new Guid(0x8fa0d5ad, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid IID_IStemSink__scanned__ = new Guid(0xfe77c330, 0x7f42, 0x11ce, 0xbe, 0x57, 0x00, 0xaa, 0x00, 0x51, 0xfe, 0x20);

        public static readonly Guid IID_IStemmerConfig__scanned__ = new Guid(0x8fa0d5a7, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

        public static readonly Guid CLSID_ITEngStemmer__scanned__ = new Guid(0x8fa0d5a8, 0xdedf, 0x11d0, 0x9a, 0x61, 0x00, 0xc0, 0x4f, 0xb6, 0x8b, 0xf7);

    }
}
