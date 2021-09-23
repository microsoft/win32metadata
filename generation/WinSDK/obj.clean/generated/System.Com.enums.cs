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


using static Windows.Win32.System.Com.Apis;

namespace Windows.Win32.System.Com
{
    [Flags]
    public enum UPDFCACHE_FLAGS : uint
    {
        UPDFCACHE_ALL = ~UPDFCACHE_ONLYIFBLANK,
        UPDFCACHE_ALLBUTNODATACACHE = UPDFCACHE_ALL & ~UPDFCACHE_NODATACACHE,
        UPDFCACHE_NORMALCACHE = 0x8,
        UPDFCACHE_IFBLANK = 0x10,
        UPDFCACHE_ONLYIFBLANK = 0x80000000,
        UPDFCACHE_NODATACACHE = 0x1,
        UPDFCACHE_ONSAVECACHE = 0x2,
        UPDFCACHE_ONSTOPCACHE = 0x4,
        UPDFCACHE_IFBLANKORONSAVECACHE = ( ( UPDFCACHE_IFBLANK | UPDFCACHE_ONSAVECACHE )  ),
    }

    [Flags]
    public enum URI_CREATE_FLAGS : uint
    {
        Uri_CREATE_ALLOW_RELATIVE = 0x00000001,
        Uri_CREATE_ALLOW_IMPLICIT_WILDCARD_SCHEME = 0x00000002,
        Uri_CREATE_ALLOW_IMPLICIT_FILE_SCHEME = 0x00000004,
        Uri_CREATE_NOFRAG = 0x00000008,
        Uri_CREATE_NO_CANONICALIZE = 0x00000010,
        Uri_CREATE_CANONICALIZE = 0x00000100,
        Uri_CREATE_FILE_USE_DOS_PATH = 0x00000020,
        Uri_CREATE_DECODE_EXTRA_INFO = 0x00000040,
        Uri_CREATE_NO_DECODE_EXTRA_INFO = 0x00000080,
        Uri_CREATE_CRACK_UNKNOWN_SCHEMES = 0x00000200,
        Uri_CREATE_NO_CRACK_UNKNOWN_SCHEMES = 0x00000400,
        Uri_CREATE_PRE_PROCESS_HTML_URI = 0x00000800,
        Uri_CREATE_NO_PRE_PROCESS_HTML_URI = 0x00001000,
        Uri_CREATE_IE_SETTINGS = 0x00002000,
        Uri_CREATE_NO_IE_SETTINGS = 0x00004000,
        Uri_CREATE_NO_ENCODE_FORBIDDEN_CHARACTERS = 0x00008000,
        Uri_CREATE_NORMALIZE_INTL_CHARACTERS = 0x00010000,
        Uri_CREATE_CANONICALIZE_ABSOLUTE = 0x00020000,
    }

    public enum RPC_C_AUTHN_LEVEL : uint
    {
        RPC_C_AUTHN_LEVEL_DEFAULT = 0,
        RPC_C_AUTHN_LEVEL_NONE = 1,
        RPC_C_AUTHN_LEVEL_CONNECT = 2,
        RPC_C_AUTHN_LEVEL_CALL = 3,
        RPC_C_AUTHN_LEVEL_PKT = 4,
        RPC_C_AUTHN_LEVEL_PKT_INTEGRITY = 5,
        RPC_C_AUTHN_LEVEL_PKT_PRIVACY = 6,
    }

    public enum RPC_C_IMP_LEVEL : uint
    {
        RPC_C_IMP_LEVEL_DEFAULT = 0,
        RPC_C_IMP_LEVEL_ANONYMOUS = 1,
        RPC_C_IMP_LEVEL_IDENTIFY = 2,
        RPC_C_IMP_LEVEL_IMPERSONATE = 3,
        RPC_C_IMP_LEVEL_DELEGATE = 4,
    }

    public enum ENUM_CONTROLS_WHICH_FLAGS : uint
    {
        GCW_WCH_SIBLING = 1,
        GC_WCH_CONTAINER = 2,
        GC_WCH_CONTAINED = 3,
        GC_WCH_ALL = 4,
        GC_WCH_FREVERSEDIR = 134217728,
        GC_WCH_FONLYAFTER = 268435456,
        GC_WCH_FONLYBEFORE = 536870912,
        GC_WCH_FSELECTED = 1073741824,
    }

    public enum MULTICLASSINFO_FLAGS : uint
    {
        MULTICLASSINFO_GETTYPEINFO = 1,
        MULTICLASSINFO_GETNUMRESERVEDDISPIDS = 2,
        MULTICLASSINFO_GETIIDPRIMARY = 4,
        MULTICLASSINFO_GETIIDSOURCE = 8,
    }

}
