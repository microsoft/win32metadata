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


using static Windows.Win32.Globalization.Apis;

namespace Windows.Win32.Globalization
{
    [Flags]
    public enum FOLD_STRING_MAP_FLAGS : uint
    {
        MAP_COMPOSITE = 0x00000040,
        MAP_EXPAND_LIGATURES = 0x00002000,
        MAP_FOLDCZONE = 0x00000010,
        MAP_FOLDDIGITS = 0x00000080,
        MAP_PRECOMPOSED = 0x00000020,
    }

    public enum SET_COMPOSITION_STRING_TYPE : uint
    {
        SCS_SETSTR = (GCS_COMPREADSTR|GCS_COMPSTR),
        SCS_CHANGEATTR = (GCS_COMPREADATTR|GCS_COMPATTR),
        SCS_CHANGECLAUSE = (GCS_COMPREADCLAUSE|GCS_COMPCLAUSE),
        SCS_SETRECONVERTSTRING = 0x00010000,
        SCS_QUERYRECONVERTSTRING = 0x00020000,
    }

    public enum GET_GUIDE_LINE_TYPE : uint
    {
        GGL_LEVEL = 0x00000001,
        GGL_INDEX = 0x00000002,
        GGL_STRING = 0x00000003,
        GGL_PRIVATE = 0x00000004,
    }

    public enum ENUM_DATE_FORMATS_FLAGS : uint
    {
        DATE_SHORTDATE = 0x00000001,
        DATE_LONGDATE = 0x00000002,
        DATE_YEARMONTH = 0x00000008,
        DATE_MONTHDAY = 0x00000080,
        DATE_AUTOLAYOUT = 0x00000040,
        DATE_LTRREADING = 0x00000010,
        DATE_RTLREADING = 0x00000020,
        DATE_USE_ALT_CALENDAR = 0x00000004,
    }

    public enum NOTIFY_IME_INDEX : uint
    {
        CPS_CANCEL = 0x0004,
        CPS_COMPLETE = 0x0001,
        CPS_CONVERT = 0x0002,
        CPS_REVERT = 0x0003,
    }

    public enum TRANSLATE_CHARSET_INFO_FLAGS : uint
    {
        TCI_SRCCHARSET = 1,
        TCI_SRCCODEPAGE = 2,
        TCI_SRCFONTSIG = 3,
        TCI_SRCLOCALE = 0x1000,
    }

    [Flags]
    public enum TIME_FORMAT_FLAGS : uint
    {
        TIME_NOMINUTESORSECONDS = 0x00000001,
        TIME_NOSECONDS = 0x00000002,
        TIME_NOTIMEMARKER = 0x00000004,
        TIME_FORCE24HOURFORMAT = 0x00000008,
    }

    public enum NOTIFY_IME_ACTION : uint
    {
        NI_CHANGECANDIDATELIST = 0x0013,
        NI_CLOSECANDIDATE = 0x0011,
        NI_COMPOSITIONSTR = 0x0015,
        NI_IMEMENUSELECTED = 0x0018,
        NI_OPENCANDIDATE = 0x0010,
        NI_SELECTCANDIDATESTR = 0x0012,
        NI_SETCANDIDATE_PAGESIZE = 0x0017,
        NI_SETCANDIDATE_PAGESTART = 0x0016,
    }

    public enum GET_CONVERSION_LIST_FLAG : uint
    {
        GCL_CONVERSION = 0x0001,
        GCL_REVERSECONVERSION = 0x0002,
        GCL_REVERSE_LENGTH = 0x0003,
    }

    public enum ENUM_SYSTEM_LANGUAGE_GROUPS_FLAGS : uint
    {
        LGRPID_INSTALLED = 0x00000001,
        LGRPID_SUPPORTED = 0x00000002,
    }

    [Flags]
    public enum MULTI_BYTE_TO_WIDE_CHAR_FLAGS : uint
    {
        MB_COMPOSITE = 0x00000002,
        MB_ERR_INVALID_CHARS = 0x00000008,
        MB_PRECOMPOSED = 0x00000001,
        MB_USEGLYPHCHARS = 0x00000004,
    }

    [Flags]
    public enum COMPARE_STRING_FLAGS : uint
    {
        LINGUISTIC_IGNORECASE = 0x00000010,
        LINGUISTIC_IGNOREDIACRITIC = 0x00000020,
        NORM_IGNORECASE = 0x00000001,
        NORM_IGNOREKANATYPE = 0x00010000,
        NORM_IGNORENONSPACE = 0x00000002,
        NORM_IGNORESYMBOLS = 0x00000004,
        NORM_IGNOREWIDTH = 0x00020000,
        NORM_LINGUISTIC_CASING = 0x08000000,
        SORT_DIGITSASNUMBERS = 0x00000008,
        SORT_STRINGSORT = 0x00001000,
    }

    public enum IS_VALID_LOCALE_FLAGS : uint
    {
        LCID_INSTALLED = 0x00000001,
        LCID_SUPPORTED = 0x00000002,
    }

    public enum ENUM_SYSTEM_CODE_PAGES_FLAGS : uint
    {
        CP_INSTALLED = 0x00000001,
        CP_SUPPORTED = 0x00000002,
    }

    public enum IME_PAD_REQUEST_FLAGS : uint
    {
        IMEPADREQ_INSERTSTRING = IMEPADREQ_FIRST + 1,
        IMEPADREQ_SENDCONTROL = IMEPADREQ_FIRST + 4,
        IMEPADREQ_SETAPPLETSIZE = IMEPADREQ_FIRST + 8,
        IMEPADREQ_GETCOMPOSITIONSTRING = IMEPADREQ_FIRST + 6,
        IMEPADREQ_GETCOMPOSITIONSTRINGINFO = IMEPADREQ_FIRST + 12,
        IMEPADREQ_DELETESTRING = IMEPADREQ_FIRST + 16,
        IMEPADREQ_CHANGESTRING = IMEPADREQ_FIRST + 17,
        IMEPADREQ_GETAPPLHWND = IMEPADREQ_FIRST + 20,
        IMEPADREQ_FORCEIMEPADWINDOWSHOW = IMEPADREQ_FIRST + 21,
        IMEPADREQ_POSTMODALNOTIFY = IMEPADREQ_FIRST + 22,
        IMEPADREQ_GETDEFAULTUILANGID = IMEPADREQ_FIRST + 23,
        IMEPADREQ_GETAPPLETUISTYLE = IMEPADREQ_FIRST + 25,
        IMEPADREQ_SETAPPLETUISTYLE = IMEPADREQ_FIRST + 26,
        IMEPADREQ_ISAPPLETACTIVE = IMEPADREQ_FIRST + 27,
        IMEPADREQ_ISIMEPADWINDOWVISIBLE = IMEPADREQ_FIRST + 28,
        IMEPADREQ_SETAPPLETMINMAXSIZE = IMEPADREQ_FIRST + 29,
        IMEPADREQ_GETCONVERSIONSTATUS = IMEPADREQ_FIRST + 30,
        IMEPADREQ_GETVERSION = IMEPADREQ_FIRST + 31,
        IMEPADREQ_GETCURRENTIMEINFO = IMEPADREQ_FIRST + 32,
    }

    public enum SCRIPT_IS_COMPLEX_FLAGS : uint
    {
        SIC_ASCIIDIGIT = 2,
        SIC_COMPLEX = 1,
        SIC_NEUTRAL = 4,
    }

    [Flags]
    public enum IS_TEXT_UNICODE_RESULT : uint
    {
        IS_TEXT_UNICODE_ASCII16 = 0x0001,
        IS_TEXT_UNICODE_REVERSE_ASCII16 = 0x0010,
        IS_TEXT_UNICODE_STATISTICS = 0x0002,
        IS_TEXT_UNICODE_REVERSE_STATISTICS = 0x0020,
        IS_TEXT_UNICODE_CONTROLS = 0x0004,
        IS_TEXT_UNICODE_REVERSE_CONTROLS = 0x0040,
        IS_TEXT_UNICODE_SIGNATURE = 0x0008,
        IS_TEXT_UNICODE_REVERSE_SIGNATURE = 0x0080,
        IS_TEXT_UNICODE_ILLEGAL_CHARS = 0x0100,
        IS_TEXT_UNICODE_ODD_LENGTH = 0x0200,
        IS_TEXT_UNICODE_NULL_BYTES = 0x1000,
        IS_TEXT_UNICODE_UNICODE_MASK = 0x000F,
        IS_TEXT_UNICODE_REVERSE_MASK = 0x00F0,
        IS_TEXT_UNICODE_NOT_UNICODE_MASK = 0x0F00,
        IS_TEXT_UNICODE_NOT_ASCII_MASK = 0xF000,
    }

}