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


using static Windows.Win32.Networking.WinInet.Apis;

namespace Windows.Win32.Networking.WinInet
{
    public enum CACHE_CONFIG : uint
    {
        CACHE_CONFIG_FORCE_CLEANUP_FC = 32,
        CACHE_CONFIG_DISK_CACHE_PATHS_FC = 64,
        CACHE_CONFIG_SYNC_MODE_FC = 128,
        CACHE_CONFIG_CONTENT_PATHS_FC = 256,
        CACHE_CONFIG_HISTORY_PATHS_FC = 1024,
        CACHE_CONFIG_COOKIES_PATHS_FC = 512,
        CACHE_CONFIG_QUOTA_FC = 2048,
        CACHE_CONFIG_USER_MODE_FC = 4096,
        CACHE_CONFIG_CONTENT_USAGE_FC = 8192,
        CACHE_CONFIG_STICKY_CONTENT_USAGE_FC = 16384,
    }

    public enum FTP_FLAGS : uint
    {
        FTP_TRANSFER_TYPE_ASCII = 0x00000001,
        FTP_TRANSFER_TYPE_BINARY = 0x00000002,
        FTP_TRANSFER_TYPE_UNKNOWN = 0x00000000,
        INTERNET_FLAG_TRANSFER_ASCII = FTP_TRANSFER_TYPE_ASCII,
        INTERNET_FLAG_TRANSFER_BINARY = FTP_TRANSFER_TYPE_BINARY,
    }

    [Flags]
    public enum INTERNET_CONNECTION : uint
    {
        INTERNET_CONNECTION_CONFIGURED = 64,
        INTERNET_CONNECTION_LAN_ = 2,
        INTERNET_CONNECTION_MODEM = 0x01,
        INTERNET_CONNECTION_MODEM_BUSY = 0x08,
        INTERNET_CONNECTION_OFFLINE_ = 32,
        INTERNET_CONNECTION_PROXY = 0x04,
        INTERNET_RAS_INSTALLED = 0x10,
    }

    [Flags]
    public enum HTTP_ADDREQ_FLAG : uint
    {
        HTTP_ADDREQ_FLAG_ADD = 0x20000000,
        HTTP_ADDREQ_FLAG_ADD_IF_NEW = 0x10000000,
        HTTP_ADDREQ_FLAG_COALESCE = HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA,
        HTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA = 0x40000000,
        HTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON = 0x01000000,
        HTTP_ADDREQ_FLAG_REPLACE = 0x80000000,
    }

    public enum INTERNET_COOKIE_FLAGS : uint
    {
        INTERNET_COOKIE_HTTPONLY = 0x00002000,
        INTERNET_COOKIE_THIRD_PARTY = 0x00000010,
        INTERNET_FLAG_RESTRICTED_ZONE = 0x00020000,
    }

    [Flags]
    public enum PROXY_AUTO_DETECT_TYPE : uint
    {
        PROXY_AUTO_DETECT_TYPE_DHCP = 1,
        PROXY_AUTO_DETECT_TYPE_DNS_A = 2,
    }

    public enum INTERNET_AUTODIAL : uint
    {
        INTERNET_AUTODIAL_FAILIFSECURITYCHECK = 4,
        INTERNET_AUTODIAL_FORCE_ONLINE = 1,
        INTERNET_AUTODIAL_FORCE_UNATTENDED = 2,
        INTERNET_AUTODIAL_OVERRIDE_NET_PRESENT = 8,
    }

    public enum GOPHER_TYPE : uint
    {
        GOPHER_TYPE_ASK = 0x40000000,
        GOPHER_TYPE_BINARY = 0x00000200,
        GOPHER_TYPE_BITMAP = 0x00004000,
        GOPHER_TYPE_CALENDAR = 0x00080000,
        GOPHER_TYPE_CSO = 0x00000004,
        GOPHER_TYPE_DIRECTORY = 0x00000002,
        GOPHER_TYPE_DOS_ARCHIVE = 0x00000020,
        GOPHER_TYPE_ERROR = 0x00000008,
        GOPHER_TYPE_GIF = 0x00001000,
        GOPHER_TYPE_GOPHER_PLUS = 0x80000000,
        GOPHER_TYPE_HTML = 0x00020000,
        GOPHER_TYPE_IMAGE = 0x00002000,
        GOPHER_TYPE_INDEX_SERVER = 0x00000080,
        GOPHER_TYPE_INLINE = 0x00100000,
        GOPHER_TYPE_MAC_BINHEX = 0x00000010,
        GOPHER_TYPE_MOVIE = 0x00008000,
        GOPHER_TYPE_PDF = 0x00040000,
        GOPHER_TYPE_REDUNDANT = 0x00000400,
        GOPHER_TYPE_SOUND = 0x00010000,
        GOPHER_TYPE_TELNET = 0x00000100,
        GOPHER_TYPE_TEXT_FILE = 0x00000001,
        GOPHER_TYPE_TN3270 = 0x00000800,
        GOPHER_TYPE_UNIX_UUENCODED = 0x00000040,
        GOPHER_TYPE_UNKNOWN = 0x20000000,
    }

    public enum INTERNET_PER_CONN : uint
    {
        INTERNET_PER_CONN_AUTOCONFIG_URL = 4,
        INTERNET_PER_CONN_AUTODISCOVERY_FLAGS = 5,
        INTERNET_PER_CONN_FLAGS = 1,
        INTERNET_PER_CONN_PROXY_BYPASS = 3,
        INTERNET_PER_CONN_PROXY_SERVER = 2,
        INTERNET_PER_CONN_AUTOCONFIG_SECONDARY_URL = 6,
        INTERNET_PER_CONN_AUTOCONFIG_RELOAD_DELAY_MINS = 7,
        INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_TIME = 8,
        INTERNET_PER_CONN_AUTOCONFIG_LAST_DETECT_URL = 9,
    }

    public enum INTERNET_ACCESS_TYPE : uint
    {
        INTERNET_OPEN_TYPE_DIRECT = 1,
        INTERNET_OPEN_TYPE_PRECONFIG = 0,
        INTERNET_OPEN_TYPE_PROXY = 3,
    }

    public enum INTERNET_STATE : uint
    {
        INTERNET_STATE_CONNECTED = 0x00000001,
        INTERNET_STATE_DISCONNECTED = 0x00000002,
        INTERNET_STATE_DISCONNECTED_BY_USER = 0x00000010,
        INTERNET_STATE_IDLE = 0x00000100,
        INTERNET_STATE_BUSY = 0x00000200,
    }

}