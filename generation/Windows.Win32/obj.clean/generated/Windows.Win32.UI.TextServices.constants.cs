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


namespace Windows.Win32.UI.TextServices
{
    public static partial class Apis
    {
        public static readonly Guid GUID_TS_SERVICE_DATAOBJECT__scanned__ = new Guid(0x6086fbb5, 0xe225, 0x46ce, 0xa7, 0x70, 0xc1, 0xbb, 0xd3, 0xe0, 0x5d, 0x7b);

        public static readonly Guid GUID_TS_SERVICE_ACCESSIBLE__scanned__ = new Guid(0xf9786200, 0xa5bf, 0x4a0f, 0x8c, 0x24, 0xfb, 0x16, 0xf5, 0xd1, 0xaa, 0xbb);

        public static readonly Guid GUID_TS_SERVICE_ACTIVEX__scanned__ = new Guid(0xea937a50, 0xc9a6, 0x4b7d, 0x89, 0x4a, 0x49, 0xd9, 0x9b, 0x78, 0x48, 0x34);

        [NativeTypeName("HRESULT")]
        public const int TS_E_INVALIDPOS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOLOCK = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0201));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOOBJECT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0202));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOSERVICE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0203));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOINTERFACE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0204));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOSELECTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0205));

        [NativeTypeName("HRESULT")]
        public const int TS_E_NOLAYOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0206));

        [NativeTypeName("HRESULT")]
        public const int TS_E_INVALIDPOINT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0207));

        [NativeTypeName("HRESULT")]
        public const int TS_E_SYNCHRONOUS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0208));

        [NativeTypeName("HRESULT")]
        public const int TS_E_READONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0209));

        [NativeTypeName("HRESULT")]
        public const int TS_E_FORMAT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020a));

        [NativeTypeName("HRESULT")]
        public const int TS_S_ASYNC = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0300));

        public const uint TS_AS_TEXT_CHANGE = 0x1;

        public const uint TS_AS_SEL_CHANGE = 0x2;

        public const uint TS_AS_LAYOUT_CHANGE = 0x4;

        public const uint TS_AS_ATTR_CHANGE = 0x8;

        public const uint TS_AS_STATUS_CHANGE = 0x10;

        public const uint TS_LF_SYNC = 0x1;

        public const uint TS_SD_READONLY = 0x1;

        public const uint TS_SD_LOADING = 0x2;

        public const uint TS_SD_RESERVED = 0x4;

        public const uint TS_SD_TKBAUTOCORRECTENABLE = 0x8;

        public const uint TS_SD_TKBPREDICTIONENABLE = 0x10;

        public const uint TS_SD_UIINTEGRATIONENABLE = 0x20;

        public const uint TS_SD_INPUTPANEMANUALDISPLAYENABLE = 0x40;

        public const uint TS_SD_EMBEDDEDHANDWRITINGVIEW_ENABLED = 0x80;

        public const uint TS_SD_EMBEDDEDHANDWRITINGVIEW_VISIBLE = 0x100;

        public const uint TS_SS_DISJOINTSEL = 0x1;

        public const uint TS_SS_REGIONS = 0x2;

        public const uint TS_SS_TRANSITORY = 0x4;

        public const uint TS_SS_NOHIDDENTEXT = 0x8;

        public const uint TS_SS_TKBAUTOCORRECTENABLE = 0x10;

        public const uint TS_SS_TKBPREDICTIONENABLE = 0x20;

        public const uint TS_SS_UWPCONTROL = 0x40;

        public const uint TS_IE_CORRECTION = 0x1;

        public const uint TS_IE_COMPOSITION = 0x2;

        public const uint TS_IAS_NOQUERY = 0x1;

        public const uint TS_IAS_QUERYONLY = 0x2;

        public const uint GXFPF_ROUND_NEAREST = 0x1;

        public const uint GXFPF_NEAREST = 0x2;

        public const uint TS_CHAR_EMBEDDED = 0xfffc;

        public const uint TS_CHAR_REGION = 0;

        public const uint TS_CHAR_REPLACEMENT = 0xfffd;

        public const uint TS_ATTR_FIND_BACKWARDS = 0x1;

        public const uint TS_ATTR_FIND_WANT_OFFSET = 0x2;

        public const uint TS_ATTR_FIND_UPDATESTART = 0x4;

        public const uint TS_ATTR_FIND_WANT_VALUE = 0x8;

        public const uint TS_ATTR_FIND_WANT_END = 0x10;

        public const uint TS_ATTR_FIND_HIDDEN = 0x20;

        public const uint TS_VCOOKIE_NUL = 0xffffffff;

        public const uint TS_SHIFT_COUNT_HIDDEN = 0x1;

        public const uint TS_SHIFT_HALT_HIDDEN = 0x2;

        public const uint TS_SHIFT_HALT_VISIBLE = 0x4;

        public const uint TS_SHIFT_COUNT_ONLY = 0x8;

        public const uint TS_GTA_HIDDEN = 0x1;

        public const uint TS_GEA_HIDDEN = 0x1;

        [NativeTypeName("HRESULT")]
        public const int TF_E_LOCKED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0500));

        [NativeTypeName("HRESULT")]
        public const int TF_E_STACKFULL = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0501));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOTOWNEDRANGE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0502));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOPROVIDER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0503));

        [NativeTypeName("HRESULT")]
        public const int TF_E_DISCONNECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0504));

        [NativeTypeName("HRESULT")]
        public const int TF_E_INVALIDVIEW = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0505));

        [NativeTypeName("HRESULT")]
        public const int TF_E_ALREADY_EXISTS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0506));

        [NativeTypeName("HRESULT")]
        public const int TF_E_RANGE_NOT_COVERED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0507));

        [NativeTypeName("HRESULT")]
        public const int TF_E_COMPOSITION_REJECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0508));

        [NativeTypeName("HRESULT")]
        public const int TF_E_EMPTYCONTEXT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0509));

        [NativeTypeName("HRESULT")]
        public const int TF_E_INVALIDPOS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOLOCK = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0201));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOOBJECT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0202));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOSERVICE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0203));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOINTERFACE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0204));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOSELECTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0205));

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOLAYOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0206));

        [NativeTypeName("HRESULT")]
        public const int TF_E_INVALIDPOINT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0207));

        [NativeTypeName("HRESULT")]
        public const int TF_E_SYNCHRONOUS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0208));

        [NativeTypeName("HRESULT")]
        public const int TF_E_READONLY = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0209));

        [NativeTypeName("HRESULT")]
        public const int TF_E_FORMAT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x020a));

        [NativeTypeName("HRESULT")]
        public const int TF_S_ASYNC = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0300));

        public const uint TF_RCM_COMLESS = 0x00000001;

        public const uint TF_RCM_VKEY = 0x00000002;

        public const uint TF_RCM_HINT_READING_LENGTH = 0x00000004;

        public const uint TF_RCM_HINT_COLLISION = 0x00000008;

        public const uint TKB_ALTERNATES_STANDARD = 0x00000001;

        public const uint TKB_ALTERNATES_FOR_AUTOCORRECTION = 0x00000002;

        public const uint TKB_ALTERNATES_FOR_PREDICTION = 0x00000003;

        public const uint TKB_ALTERNATES_AUTOCORRECTION_APPLIED = 0x00000004;

        public const uint TF_TMAE_NOACTIVATETIP = 0x00000001;

        public const uint TF_TMAE_SECUREMODE = 0x00000002;

        public const uint TF_TMAE_UIELEMENTENABLEDONLY = 0x00000004;

        public const uint TF_TMAE_COMLESS = 0x00000008;

        public const uint TF_TMAE_WOW16 = 0x00000010;

        public const uint TF_TMAE_NOACTIVATEKEYBOARDLAYOUT = 0x00000020;

        public const uint TF_TMAE_CONSOLE = 0x00000040;

        public const uint TF_TMF_IMMERSIVEMODE = 0x40000000;

        public const uint TF_TMF_ACTIVATED = 0x80000000;

        public const uint TF_MOD_ALT = 0x0001;

        public const uint TF_MOD_CONTROL = 0x0002;

        public const uint TF_MOD_SHIFT = 0x0004;

        public const uint TF_MOD_RALT = 0x0008;

        public const uint TF_MOD_RCONTROL = 0x0010;

        public const uint TF_MOD_RSHIFT = 0x0020;

        public const uint TF_MOD_LALT = 0x0040;

        public const uint TF_MOD_LCONTROL = 0x0080;

        public const uint TF_MOD_LSHIFT = 0x0100;

        public const uint TF_MOD_ON_KEYUP = 0x0200;

        public const uint TF_MOD_IGNORE_ALL_MODIFIER = 0x0400;

        public const uint TF_US_HIDETIPUI = 0x00000001;

        public const uint TF_DISABLE_SPEECH = 0x00000001;

        public const uint TF_DISABLE_DICTATION = 0x00000002;

        public const uint TF_DISABLE_COMMANDING = 0x00000004;

        public const uint TF_CLUIE_DOCUMENTMGR = 0x00000001;

        public const uint TF_CLUIE_COUNT = 0x00000002;

        public const uint TF_CLUIE_SELECTION = 0x00000004;

        public const uint TF_CLUIE_STRING = 0x00000008;

        public const uint TF_CLUIE_PAGEINDEX = 0x00000010;

        public const uint TF_CLUIE_CURRENTPAGE = 0x00000020;

        public const uint TF_RIUIE_CONTEXT = 0x00000001;

        public const uint TF_RIUIE_STRING = 0x00000002;

        public const uint TF_RIUIE_MAXREADINGSTRINGLENGTH = 0x00000004;

        public const uint TF_RIUIE_ERRORINDEX = 0x00000008;

        public const uint TF_RIUIE_VERTICALORDER = 0x00000010;

        public const uint TF_CONVERSIONMODE_ALPHANUMERIC = 0x0000;

        public const uint TF_CONVERSIONMODE_NATIVE = 0x0001;

        public const uint TF_CONVERSIONMODE_KATAKANA = 0x0002;

        public const uint TF_CONVERSIONMODE_FULLSHAPE = 0x0008;

        public const uint TF_CONVERSIONMODE_ROMAN = 0x0010;

        public const uint TF_CONVERSIONMODE_CHARCODE = 0x0020;

        public const uint TF_CONVERSIONMODE_SOFTKEYBOARD = 0x0080;

        public const uint TF_CONVERSIONMODE_NOCONVERSION = 0x0100;

        public const uint TF_CONVERSIONMODE_EUDC = 0x0200;

        public const uint TF_CONVERSIONMODE_SYMBOL = 0x0400;

        public const uint TF_CONVERSIONMODE_FIXED = 0x0800;

        public const uint TF_SENTENCEMODE_NONE = 0x0000;

        public const uint TF_SENTENCEMODE_PLAURALCLAUSE = 0x0001;

        public const uint TF_SENTENCEMODE_SINGLECONVERT = 0x0002;

        public const uint TF_SENTENCEMODE_AUTOMATIC = 0x0004;

        public const uint TF_SENTENCEMODE_PHRASEPREDICT = 0x0008;

        public const uint TF_SENTENCEMODE_CONVERSATION = 0x0010;

        public const uint TF_TRANSITORYEXTENSION_NONE = 0x0000;

        public const uint TF_TRANSITORYEXTENSION_FLOATING = 0x0001;

        public const uint TF_TRANSITORYEXTENSION_ATSELECTION = 0x0002;

        public const uint TF_PROFILETYPE_INPUTPROCESSOR = 0x0001;

        public const uint TF_PROFILETYPE_KEYBOARDLAYOUT = 0x0002;

        public const uint TF_RIP_FLAG_FREEUNUSEDLIBRARIES = 0x00000001;

        public const uint TF_IPP_FLAG_ACTIVE = 0x00000001;

        public const uint TF_IPP_FLAG_ENABLED = 0x00000002;

        public const uint TF_IPP_FLAG_SUBSTITUTEDBYINPUTPROCESSOR = 0x00000004;

        public const uint TF_IPP_CAPS_DISABLEONTRANSITORY = 0x00000001;

        public const uint TF_IPP_CAPS_SECUREMODESUPPORT = 0x00000002;

        public const uint TF_IPP_CAPS_UIELEMENTENABLED = 0x00000004;

        public const uint TF_IPP_CAPS_COMLESSSUPPORT = 0x00000008;

        public const uint TF_IPP_CAPS_WOW16SUPPORT = 0x00000010;

        public const uint TF_IPP_CAPS_IMMERSIVESUPPORT = 0x00010000;

        public const uint TF_IPP_CAPS_SYSTRAYSUPPORT = 0x00020000;

        public const uint TF_IPPMF_FORPROCESS = 0x10000000;

        public const uint TF_IPPMF_FORSESSION = 0x20000000;

        public const uint TF_IPPMF_FORSYSTEMALL = 0x40000000;

        public const uint TF_IPPMF_ENABLEPROFILE = 0x00000001;

        public const uint TF_IPPMF_DISABLEPROFILE = 0x00000002;

        public const uint TF_IPPMF_DONTCARECURRENTINPUTLANGUAGE = 0x00000004;

        public const uint TF_RP_HIDDENINSETTINGUI = 0x00000002;

        public const uint TF_RP_LOCALPROCESS = 0x00000004;

        public const uint TF_RP_LOCALTHREAD = 0x00000008;

        public const uint TF_RP_SUBITEMINSETTINGUI = 0x00000010;

        public const uint TF_URP_ALLPROFILES = 0x00000002;

        public const uint TF_URP_LOCALPROCESS = 0x00000004;

        public const uint TF_URP_LOCALTHREAD = 0x00000008;

        public const uint TF_IPSINK_FLAG_ACTIVE = 0x0001;

        public const uint TF_INVALID_EDIT_COOKIE = 0;

        public const uint TF_POPF_ALL = 0x1;

        public const uint TF_HF_OBJECT = 1;

        public const uint TF_TF_MOVESTART = 1;

        public const uint TF_TF_IGNOREEND = 2;

        public const uint TF_ST_CORRECTION = 1;

        public const uint TF_IE_CORRECTION = 1;

        public const uint TF_TU_CORRECTION = 0x1;

        public const uint TF_INVALID_COOKIE = 0xffffffff;

        public static readonly Guid TF_PROFILE_NEWPHONETIC__scanned__ = new Guid(0xB2F9C502, 0x1742, 0x11D4, 0x97, 0x90, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_PHONETIC__scanned__ = new Guid(0x761309DE, 0x317A, 0x11D4, 0x9B, 0x5D, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_NEWCHANGJIE__scanned__ = new Guid(0xF3BA907A, 0x6C7E, 0x11D4, 0x97, 0xFA, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_CHANGJIE__scanned__ = new Guid(0x4BDF9F03, 0xC7D3, 0x11D4, 0xB2, 0xAB, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_NEWQUICK__scanned__ = new Guid(0x0B883BA0, 0xC1C7, 0x11D4, 0x87, 0xF9, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_QUICK__scanned__ = new Guid(0x6024B45F, 0x5C54, 0x11D4, 0xB9, 0x21, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_CANTONESE__scanned__ = new Guid(0x0AEC109C, 0x7E96, 0x11D4, 0xB2, 0xEF, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_PINYIN__scanned__ = new Guid(0xF3BA9077, 0x6C7E, 0x11D4, 0x97, 0xFA, 0x00, 0x80, 0xC8, 0x82, 0x68, 0x7E);

        public static readonly Guid TF_PROFILE_SIMPLEFAST__scanned__ = new Guid(0xFA550B04, 0x5AD7, 0x411F, 0xA5, 0xAC, 0xCA, 0x03, 0x8E, 0xC5, 0x15, 0xD7);

        public static readonly Guid TF_PROFILE_WUBI__scanned__ = new Guid(0x82590C13, 0xF4DD, 0x44F4, 0xBA, 0x1D, 0x86, 0x67, 0x24, 0x6F, 0xDF, 0x8E);

        public static readonly Guid TF_PROFILE_DAYI__scanned__ = new Guid(0x037B2C25, 0x480C, 0x4D7F, 0xB0, 0x27, 0xD6, 0xCA, 0x6B, 0x69, 0x78, 0x8A);

        public static readonly Guid TF_PROFILE_ARRAY__scanned__ = new Guid(0xD38EFF65, 0xAA46, 0x4FD5, 0x91, 0xA7, 0x67, 0x84, 0x5F, 0xB0, 0x2F, 0x5B);

        public static readonly Guid TF_PROFILE_YI__scanned__ = new Guid(0x409C8376, 0x007B, 0x4357, 0xAE, 0x8E, 0x26, 0x31, 0x6E, 0xE3, 0xFB, 0x0D);

        public static readonly Guid TF_PROFILE_TIGRINYA__scanned__ = new Guid(0x3CAB88B7, 0xCC3E, 0x46A6, 0x97, 0x65, 0xB7, 0x72, 0xAD, 0x77, 0x61, 0xFF);

        [NativeTypeName("HRESULT")]
        public const int TF_E_NOCONVERSION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0600));

        public const uint TF_DICTATION_ON = 0x00000001;

        public const uint TF_DICTATION_ENABLED = 0x00000002;

        public const uint TF_COMMANDING_ENABLED = 0x00000004;

        public const uint TF_COMMANDING_ON = 0x00000008;

        public const uint TF_SPEECHUI_SHOWN = 0x00000010;

        public const uint TF_SHOW_BALLOON = 0x00000001;

        public const uint TF_DISABLE_BALLOON = 0x00000002;

        public const uint TF_MENUREADY = 0x00000001;

        public const uint TF_PROPUI_STATUS_SAVETOFILE = 0x00000001;

        public static readonly Guid GUID_INTEGRATIONSTYLE_SEARCHBOX__scanned__ = new Guid(0xe6d1bd11, 0x82f7, 0x4903, 0xae, 0x21, 0x1a, 0x63, 0x97, 0xcd, 0xe2, 0xeb);

        public const uint TKBL_UNDEFINED = 0;

        public const uint TKBL_CLASSIC_TRADITIONAL_CHINESE_PHONETIC = 0x0404;

        public const uint TKBL_CLASSIC_TRADITIONAL_CHINESE_CHANGJIE = 0xF042;

        public const uint TKBL_CLASSIC_TRADITIONAL_CHINESE_DAYI = 0xF043;

        public const uint TKBL_OPT_JAPANESE_ABC = 0x0411;

        public const uint TKBL_OPT_KOREAN_HANGUL_2_BULSIK = 0x0412;

        public const uint TKBL_OPT_SIMPLIFIED_CHINESE_PINYIN = 0x0804;

        public const uint TKBL_OPT_TRADITIONAL_CHINESE_PHONETIC = 0x0404;

        public const uint TF_LBI_ICON = 0x00000001;

        public const uint TF_LBI_TEXT = 0x00000002;

        public const uint TF_LBI_TOOLTIP = 0x00000004;

        public const uint TF_LBI_BITMAP = 0x00000008;

        public const uint TF_LBI_BALLOON = 0x00000010;

        public const uint TF_LBI_CUSTOMUI = 0x00000020;

        public const uint TF_LBI_STATUS = 0x00010000;

        public const uint TF_LBI_STYLE_HIDDENSTATUSCONTROL = 0x00000001;

        public const uint TF_LBI_STYLE_SHOWNINTRAY = 0x00000002;

        public const uint TF_LBI_STYLE_HIDEONNOOTHERITEMS = 0x00000004;

        public const uint TF_LBI_STYLE_SHOWNINTRAYONLY = 0x00000008;

        public const uint TF_LBI_STYLE_HIDDENBYDEFAULT = 0x00000010;

        public const uint TF_LBI_STYLE_TEXTCOLORICON = 0x00000020;

        public const uint TF_LBI_STYLE_BTN_BUTTON = 0x00010000;

        public const uint TF_LBI_STYLE_BTN_MENU = 0x00020000;

        public const uint TF_LBI_STYLE_BTN_TOGGLE = 0x00040000;

        public const uint TF_LBI_STATUS_HIDDEN = 0x00000001;

        public const uint TF_LBI_STATUS_DISABLED = 0x00000002;

        public const uint TF_LBI_STATUS_BTN_TOGGLED = 0x00010000;

        public const uint TF_LBI_BMPF_VERTICAL = 0x00000001;

        public const uint TF_SFT_SHOWNORMAL = 0x00000001;

        public const uint TF_SFT_DOCK = 0x00000002;

        public const uint TF_SFT_MINIMIZED = 0x00000004;

        public const uint TF_SFT_HIDDEN = 0x00000008;

        public const uint TF_SFT_NOTRANSPARENCY = 0x00000010;

        public const uint TF_SFT_LOWTRANSPARENCY = 0x00000020;

        public const uint TF_SFT_HIGHTRANSPARENCY = 0x00000040;

        public const uint TF_SFT_LABELS = 0x00000080;

        public const uint TF_SFT_NOLABELS = 0x00000100;

        public const uint TF_SFT_EXTRAICONSONMINIMIZED = 0x00000200;

        public const uint TF_SFT_NOEXTRAICONSONMINIMIZED = 0x00000400;

        public const uint TF_SFT_DESKBAND = 0x00000800;

        public const uint TF_LBI_DESC_MAXLEN = 32;

        public const uint TF_LBMENUF_CHECKED = 0x1;

        public const uint TF_LBMENUF_SUBMENU = 0x2;

        public const uint TF_LBMENUF_SEPARATOR = 0x4;

        public const uint TF_LBMENUF_RADIOCHECKED = 0x8;

        public const uint TF_LBMENUF_GRAYED = 0x10;

        public static readonly Guid GUID_PROP_INPUTSCOPE__scanned__ = new Guid(0x1713dd5a, 0x68e7, 0x4a5b, 0x9a, 0xf6, 0x59, 0x2a, 0x59, 0x5c, 0x77, 0x8d);

        public const uint DCM_FLAGS_TASKENG = 0x00000001;

        public const uint DCM_FLAGS_CTFMON = 0x00000002;

        public const uint DCM_FLAGS_LOCALTHREADTSF = 0x00000004;

        public const uint ILMCM_CHECKLAYOUTANDTIPENABLED = 0x00001;

        public const uint ILMCM_LANGUAGEBAROFF = 0x00002;

        public static readonly Guid LIBID_MSAATEXTLib__scanned__ = new Guid(0x150E2D7A,0xDAC1,0x4582,0x94,0x7D,0x2A,0x8F,0xD7,0x8B,0x82,0xCD);

        public static readonly Guid CLSID_MSAAControl__scanned__ = new Guid(0x08cd963f,0x7a3e,0x4f5c,0x9b,0xd8,0xd6,0x92,0xbb,0x04,0x3c,0x5b );

        public static readonly Guid CLSID_AccStore__scanned__ = new Guid(0x5440837F,0x4BFF,0x4AE5,0xA1,0xB1,0x77,0x22,0xEC,0xC6,0x33,0x2A );

        public static readonly Guid CLSID_AccDictionary__scanned__ = new Guid(0x6572EE16,0x5FE5,0x4331,0xBB,0x6D,0x76,0xA4,0x9C,0x56,0xE4,0x23 );

        public static readonly Guid CLSID_AccServerDocMgr__scanned__ = new Guid(0x6089A37E,0xEB8A,0x482D,0xBD,0x6F,0xF9,0xF4,0x69,0x04,0xD1,0x6D );

        public static readonly Guid CLSID_AccClientDocMgr__scanned__ = new Guid(0xFC48CC30,0x4F3E,0x4fa1,0x80,0x3B,0xAD,0x0E,0x19,0x6A,0x83,0xB1 );

        public static readonly Guid CLSID_DocWrap__scanned__ = new Guid(0xBF426F7E,0x7A5E,0x44D6,0x83,0x0C,0xA3,0x90,0xEA,0x94,0x62,0xA3 );

        public const uint TS_STRF_START = 0;

        public const uint TS_STRF_MID = 1;

        public const uint TS_STRF_END = 2;

    }
}
