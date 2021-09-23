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


using static Windows.Win32.Networking.WinHttp.Apis;

namespace Windows.Win32.Networking.WinHttp
{
    public enum INTERNET_PORT : uint
    {
        INTERNET_DEFAULT_HTTP_PORT = 80,
        INTERNET_DEFAULT_HTTPS_PORT = 443,
        INTERNET_DEFAULT_PORT = 0,
    }

    [Flags]
    public enum WINHTTP_OPEN_REQUEST_FLAGS : uint
    {
        WINHTTP_FLAG_BYPASS_PROXY_CACHE = 0x00000100,
        WINHTTP_FLAG_ESCAPE_DISABLE = 0x00000040,
        WINHTTP_FLAG_ESCAPE_DISABLE_QUERY = 0x00000080,
        WINHTTP_FLAG_ESCAPE_PERCENT = 0x00000004,
        WINHTTP_FLAG_NULL_CODEPAGE = 0x00000008,
        WINHTTP_FLAG_REFRESH = WINHTTP_FLAG_BYPASS_PROXY_CACHE,
        WINHTTP_FLAG_SECURE = 0x00800000,
    }

    public enum WIN_HTTP_CREATE_URL_FLAGS : uint
    {
        ICU_ESCAPE = 0x80000000,
        ICU_REJECT_USERPWD = 0x00004000,
        ICU_DECODE = 0x10000000,
    }

    public enum WINHTTP_ACCESS_TYPE : uint
    {
        WINHTTP_ACCESS_TYPE_NO_PROXY = 1,
        WINHTTP_ACCESS_TYPE_DEFAULT_PROXY = 0,
        WINHTTP_ACCESS_TYPE_NAMED_PROXY = 3,
        WINHTTP_ACCESS_TYPE_AUTOMATIC_PROXY = 4,
    }

    public enum WINHTTP_CREDS_AUTHSCHEME : uint
    {
        WINHTTP_AUTH_SCHEME_BASIC = 0x00000001,
        WINHTTP_AUTH_SCHEME_NTLM = 0x00000002,
        WINHTTP_AUTH_SCHEME_NEGOTIATE = 0x00000010,
    }

    public enum WINHTTP_INTERNET_SCHEME : uint
    {
        WINHTTP_INTERNET_SCHEME_HTTP = (1),
        WINHTTP_INTERNET_SCHEME_HTTPS = (2),
        WINHTTP_INTERNET_SCHEME_FTP = (3),
        WINHTTP_INTERNET_SCHEME_SOCKS = (4),
    }

}
