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


namespace Windows.Win32.Networking.WinInet
{
    public static partial class Apis
    {
        public const uint DIALENG_OperationComplete = 0x10000;

        public const uint DIALENG_RedialAttempt = 0x10001;

        public const uint DIALENG_RedialWait = 0x10002;

        public const uint INTERNET_INVALID_PORT_NUMBER = 0;

        public const uint INTERNET_DEFAULT_FTP_PORT = 21;

        public const uint INTERNET_DEFAULT_GOPHER_PORT = 70;

        public const uint INTERNET_DEFAULT_SOCKS_PORT = 1080;

        public const uint INTERNET_MAX_HOST_NAME_LENGTH = 256;

        public const uint INTERNET_MAX_USER_NAME_LENGTH = 128;

        public const uint INTERNET_MAX_PASSWORD_LENGTH = 128;

        public const uint INTERNET_MAX_PORT_NUMBER_LENGTH = 5;

        public const uint INTERNET_MAX_PORT_NUMBER_VALUE = 65535;

        public const uint INTERNET_KEEP_ALIVE_UNKNOWN = 0xFFFFFFFF;

        public const uint INTERNET_KEEP_ALIVE_ENABLED = 1;

        public const uint INTERNET_KEEP_ALIVE_DISABLED = 0;

        public const uint INTERNET_REQFLAG_FROM_CACHE = 0x00000001;

        public const uint INTERNET_REQFLAG_ASYNC = 0x00000002;

        public const uint INTERNET_REQFLAG_VIA_PROXY = 0x00000004;

        public const uint INTERNET_REQFLAG_NO_HEADERS = 0x00000008;

        public const uint INTERNET_REQFLAG_PASSIVE = 0x00000010;

        public const uint INTERNET_REQFLAG_CACHE_WRITE_DISABLED = 0x00000040;

        public const uint INTERNET_REQFLAG_NET_TIMEOUT = 0x00000080;

        public const uint INTERNET_FLAG_IDN_DIRECT = 0x00000001;

        public const uint INTERNET_FLAG_IDN_PROXY = 0x00000002;

        public const uint INTERNET_FLAG_RELOAD = 0x80000000;

        public const uint INTERNET_FLAG_RAW_DATA = 0x40000000;

        public const uint INTERNET_FLAG_EXISTING_CONNECT = 0x20000000;

        public const uint INTERNET_FLAG_ASYNC = 0x10000000;

        public const uint INTERNET_FLAG_PASSIVE = 0x08000000;

        public const uint INTERNET_FLAG_NO_CACHE_WRITE = 0x04000000;

        public const uint INTERNET_FLAG_MAKE_PERSISTENT = 0x02000000;

        public const uint INTERNET_FLAG_FROM_CACHE = 0x01000000;

        public const uint INTERNET_FLAG_SECURE = 0x00800000;

        public const uint INTERNET_FLAG_KEEP_CONNECTION = 0x00400000;

        public const uint INTERNET_FLAG_NO_AUTO_REDIRECT = 0x00200000;

        public const uint INTERNET_FLAG_READ_PREFETCH = 0x00100000;

        public const uint INTERNET_FLAG_NO_COOKIES = 0x00080000;

        public const uint INTERNET_FLAG_NO_AUTH = 0x00040000;

        public const uint INTERNET_FLAG_CACHE_IF_NET_FAIL = 0x00010000;

        public const uint INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTP = 0x00008000;

        public const uint INTERNET_FLAG_IGNORE_REDIRECT_TO_HTTPS = 0x00004000;

        public const uint INTERNET_FLAG_IGNORE_CERT_DATE_INVALID = 0x00002000;

        public const uint INTERNET_FLAG_IGNORE_CERT_CN_INVALID = 0x00001000;

        public const uint INTERNET_FLAG_RESYNCHRONIZE = 0x00000800;

        public const uint INTERNET_FLAG_HYPERLINK = 0x00000400;

        public const uint INTERNET_FLAG_NO_UI = 0x00000200;

        public const uint INTERNET_FLAG_PRAGMA_NOCACHE = 0x00000100;

        public const uint INTERNET_FLAG_CACHE_ASYNC = 0x00000080;

        public const uint INTERNET_FLAG_FORMS_SUBMIT = 0x00000040;

        public const uint INTERNET_FLAG_FWD_BACK = 0x00000020;

        public const uint INTERNET_FLAG_NEED_FILE = 0x00000010;

        public const uint INTERNET_ERROR_MASK_INSERT_CDROM = 0x1;

        public const uint INTERNET_ERROR_MASK_COMBINED_SEC_CERT = 0x2;

        public const uint INTERNET_ERROR_MASK_NEED_MSN_SSPI_PKG = 0X4;

        public const uint INTERNET_ERROR_MASK_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = 0x8;

        public const uint WININET_API_FLAG_ASYNC = 0x00000001;

        public const uint WININET_API_FLAG_SYNC = 0x00000004;

        public const uint WININET_API_FLAG_USE_CONTEXT = 0x00000008;

        public const uint INTERNET_NO_CALLBACK = 0;

        public const uint IDSI_FLAG_KEEP_ALIVE = 0x00000001;

        public const uint IDSI_FLAG_SECURE = 0x00000002;

        public const uint IDSI_FLAG_PROXY = 0x00000004;

        public const uint IDSI_FLAG_TUNNEL = 0x00000008;

        public const uint INTERNET_PER_CONN_FLAGS_UI = 10;

        public const uint PROXY_TYPE_DIRECT = 0x00000001;

        public const uint PROXY_TYPE_PROXY = 0x00000002;

        public const uint PROXY_TYPE_AUTO_PROXY_URL = 0x00000004;

        public const uint PROXY_TYPE_AUTO_DETECT = 0x00000008;

        public const uint AUTO_PROXY_FLAG_USER_SET = 0x00000001;

        public const uint AUTO_PROXY_FLAG_ALWAYS_DETECT = 0x00000002;

        public const uint AUTO_PROXY_FLAG_DETECTION_RUN = 0x00000004;

        public const uint AUTO_PROXY_FLAG_MIGRATED = 0x00000008;

        public const uint AUTO_PROXY_FLAG_DONT_CACHE_PROXY_RESULT = 0x00000010;

        public const uint AUTO_PROXY_FLAG_CACHE_INIT_RUN = 0x00000020;

        public const uint AUTO_PROXY_FLAG_DETECTION_SUSPECT = 0x00000040;

        public const uint ISO_FORCE_DISCONNECTED = 0x00000001;

        public const uint INTERNET_RFC1123_FORMAT = 0;

        public const uint INTERNET_RFC1123_BUFSIZE = 30;

        public const uint ICU_USERNAME = 0x40000000;

        public const uint INTERNET_OPEN_TYPE_PRECONFIG_WITH_NO_AUTOPROXY = 4;

        public const uint INTERNET_SERVICE_FTP = 1;

        public const uint INTERNET_SERVICE_GOPHER = 2;

        public const uint INTERNET_SERVICE_HTTP = 3;

        public const uint IRF_NO_WAIT = 0x00000008;

        public const uint ISO_GLOBAL = 0x00000001;

        public const uint ISO_REGISTRY = 0x00000002;

        public const uint INTERNET_OPTION_CALLBACK = 1;

        public const uint INTERNET_OPTION_CONNECT_TIMEOUT = 2;

        public const uint INTERNET_OPTION_CONNECT_RETRIES = 3;

        public const uint INTERNET_OPTION_CONNECT_BACKOFF = 4;

        public const uint INTERNET_OPTION_SEND_TIMEOUT = 5;

        public const uint INTERNET_OPTION_RECEIVE_TIMEOUT = 6;

        public const uint INTERNET_OPTION_DATA_SEND_TIMEOUT = 7;

        public const uint INTERNET_OPTION_DATA_RECEIVE_TIMEOUT = 8;

        public const uint INTERNET_OPTION_HANDLE_TYPE = 9;

        public const uint INTERNET_OPTION_LISTEN_TIMEOUT = 11;

        public const uint INTERNET_OPTION_READ_BUFFER_SIZE = 12;

        public const uint INTERNET_OPTION_WRITE_BUFFER_SIZE = 13;

        public const uint INTERNET_OPTION_ASYNC_ID = 15;

        public const uint INTERNET_OPTION_ASYNC_PRIORITY = 16;

        public const uint INTERNET_OPTION_PARENT_HANDLE = 21;

        public const uint INTERNET_OPTION_KEEP_CONNECTION = 22;

        public const uint INTERNET_OPTION_REQUEST_FLAGS = 23;

        public const uint INTERNET_OPTION_EXTENDED_ERROR = 24;

        public const uint INTERNET_OPTION_OFFLINE_MODE = 26;

        public const uint INTERNET_OPTION_CACHE_STREAM_HANDLE = 27;

        public const uint INTERNET_OPTION_USERNAME = 28;

        public const uint INTERNET_OPTION_PASSWORD = 29;

        public const uint INTERNET_OPTION_ASYNC = 30;

        public const uint INTERNET_OPTION_SECURITY_FLAGS = 31;

        public const uint INTERNET_OPTION_SECURITY_CERTIFICATE_STRUCT = 32;

        public const uint INTERNET_OPTION_DATAFILE_NAME = 33;

        public const uint INTERNET_OPTION_URL = 34;

        public const uint INTERNET_OPTION_SECURITY_CERTIFICATE = 35;

        public const uint INTERNET_OPTION_SECURITY_KEY_BITNESS = 36;

        public const uint INTERNET_OPTION_REFRESH = 37;

        public const uint INTERNET_OPTION_PROXY = 38;

        public const uint INTERNET_OPTION_SETTINGS_CHANGED = 39;

        public const uint INTERNET_OPTION_VERSION = 40;

        public const uint INTERNET_OPTION_USER_AGENT = 41;

        public const uint INTERNET_OPTION_END_BROWSER_SESSION = 42;

        public const uint INTERNET_OPTION_PROXY_USERNAME = 43;

        public const uint INTERNET_OPTION_PROXY_PASSWORD = 44;

        public const uint INTERNET_OPTION_CONTEXT_VALUE = 45;

        public const uint INTERNET_OPTION_CONNECT_LIMIT = 46;

        public const uint INTERNET_OPTION_SECURITY_SELECT_CLIENT_CERT = 47;

        public const uint INTERNET_OPTION_POLICY = 48;

        public const uint INTERNET_OPTION_DISCONNECTED_TIMEOUT = 49;

        public const uint INTERNET_OPTION_CONNECTED_STATE = 50;

        public const uint INTERNET_OPTION_IDLE_STATE = 51;

        public const uint INTERNET_OPTION_OFFLINE_SEMANTICS = 52;

        public const uint INTERNET_OPTION_SECONDARY_CACHE_KEY = 53;

        public const uint INTERNET_OPTION_CALLBACK_FILTER = 54;

        public const uint INTERNET_OPTION_CONNECT_TIME = 55;

        public const uint INTERNET_OPTION_SEND_THROUGHPUT = 56;

        public const uint INTERNET_OPTION_RECEIVE_THROUGHPUT = 57;

        public const uint INTERNET_OPTION_REQUEST_PRIORITY = 58;

        public const uint INTERNET_OPTION_HTTP_VERSION = 59;

        public const uint INTERNET_OPTION_RESET_URLCACHE_SESSION = 60;

        public const uint INTERNET_OPTION_ERROR_MASK = 62;

        public const uint INTERNET_OPTION_FROM_CACHE_TIMEOUT = 63;

        public const uint INTERNET_OPTION_BYPASS_EDITED_ENTRY = 64;

        public const uint INTERNET_OPTION_HTTP_DECODING = 65;

        public const uint INTERNET_OPTION_DIAGNOSTIC_SOCKET_INFO = 67;

        public const uint INTERNET_OPTION_CODEPAGE = 68;

        public const uint INTERNET_OPTION_CACHE_TIMESTAMPS = 69;

        public const uint INTERNET_OPTION_DISABLE_AUTODIAL = 70;

        public const uint INTERNET_OPTION_MAX_CONNS_PER_SERVER = 73;

        public const uint INTERNET_OPTION_MAX_CONNS_PER_1_0_SERVER = 74;

        public const uint INTERNET_OPTION_PER_CONNECTION_OPTION = 75;

        public const uint INTERNET_OPTION_DIGEST_AUTH_UNLOAD = 76;

        public const uint INTERNET_OPTION_IGNORE_OFFLINE = 77;

        public const uint INTERNET_OPTION_IDENTITY = 78;

        public const uint INTERNET_OPTION_REMOVE_IDENTITY = 79;

        public const uint INTERNET_OPTION_ALTER_IDENTITY = 80;

        public const uint INTERNET_OPTION_SUPPRESS_BEHAVIOR = 81;

        public const uint INTERNET_OPTION_AUTODIAL_MODE = 82;

        public const uint INTERNET_OPTION_AUTODIAL_CONNECTION = 83;

        public const uint INTERNET_OPTION_CLIENT_CERT_CONTEXT = 84;

        public const uint INTERNET_OPTION_AUTH_FLAGS = 85;

        public const uint INTERNET_OPTION_COOKIES_3RD_PARTY = 86;

        public const uint INTERNET_OPTION_DISABLE_PASSPORT_AUTH = 87;

        public const uint INTERNET_OPTION_SEND_UTF8_SERVERNAME_TO_PROXY = 88;

        public const uint INTERNET_OPTION_EXEMPT_CONNECTION_LIMIT = 89;

        public const uint INTERNET_OPTION_ENABLE_PASSPORT_AUTH = 90;

        public const uint INTERNET_OPTION_HIBERNATE_INACTIVE_WORKER_THREADS = 91;

        public const uint INTERNET_OPTION_ACTIVATE_WORKER_THREADS = 92;

        public const uint INTERNET_OPTION_RESTORE_WORKER_THREAD_DEFAULTS = 93;

        public const uint INTERNET_OPTION_SOCKET_SEND_BUFFER_LENGTH = 94;

        public const uint INTERNET_OPTION_PROXY_SETTINGS_CHANGED = 95;

        public const uint INTERNET_OPTION_DATAFILE_EXT = 96;

        public const uint INTERNET_OPTION_CODEPAGE_PATH = 100;

        public const uint INTERNET_OPTION_CODEPAGE_EXTRA = 101;

        public const uint INTERNET_OPTION_IDN = 102;

        public const uint INTERNET_OPTION_MAX_CONNS_PER_PROXY = 103;

        public const uint INTERNET_OPTION_SUPPRESS_SERVER_AUTH = 104;

        public const uint INTERNET_OPTION_SERVER_CERT_CHAIN_CONTEXT = 105;

        public const uint INTERNET_OPTION_ENABLE_REDIRECT_CACHE_READ = 122;

        public const uint INTERNET_OPTION_COMPRESSED_CONTENT_LENGTH = 147;

        public const uint INTERNET_OPTION_ENABLE_HTTP_PROTOCOL = 148;

        public const uint INTERNET_OPTION_HTTP_PROTOCOL_USED = 149;

        public const uint INTERNET_OPTION_ENCODE_EXTRA = 155;

        public const uint INTERNET_OPTION_HSTS = 157;

        public const uint INTERNET_OPTION_ENTERPRISE_CONTEXT = 159;

        public const uint INTERNET_OPTION_CONNECTION_FILTER = 162;

        public const uint INTERNET_OPTION_REFERER_TOKEN_BINDING_HOSTNAME = 163;

        public const uint INTERNET_OPTION_TOKEN_BINDING_PUBLIC_KEY = 181;

        public const uint INTERNET_OPTION_COOKIES_SAME_SITE_LEVEL = 187;

        public const uint INTERNET_PRIORITY_FOREGROUND = 1000;

        public const uint HTTP_COOKIES_SAME_SITE_LEVEL_UNKNOWN = 0x0;

        public const uint HTTP_COOKIES_SAME_SITE_LEVEL_SAME_SITE = 0x1;

        public const uint HTTP_COOKIES_SAME_SITE_LEVEL_CROSS_SITE_LAX = 0x2;

        public const uint HTTP_COOKIES_SAME_SITE_LEVEL_CROSS_SITE = 0x3;

        public const uint HTTP_PROTOCOL_FLAG_HTTP2 = 0x2;

        public const uint INTERNET_HANDLE_TYPE_INTERNET = 1;

        public const uint INTERNET_HANDLE_TYPE_CONNECT_FTP = 2;

        public const uint INTERNET_HANDLE_TYPE_CONNECT_GOPHER = 3;

        public const uint INTERNET_HANDLE_TYPE_CONNECT_HTTP = 4;

        public const uint INTERNET_HANDLE_TYPE_FTP_FIND = 5;

        public const uint INTERNET_HANDLE_TYPE_FTP_FIND_HTML = 6;

        public const uint INTERNET_HANDLE_TYPE_FTP_FILE = 7;

        public const uint INTERNET_HANDLE_TYPE_FTP_FILE_HTML = 8;

        public const uint INTERNET_HANDLE_TYPE_GOPHER_FIND = 9;

        public const uint INTERNET_HANDLE_TYPE_GOPHER_FIND_HTML = 10;

        public const uint INTERNET_HANDLE_TYPE_GOPHER_FILE = 11;

        public const uint INTERNET_HANDLE_TYPE_GOPHER_FILE_HTML = 12;

        public const uint INTERNET_HANDLE_TYPE_HTTP_REQUEST = 13;

        public const uint INTERNET_HANDLE_TYPE_FILE_REQUEST = 14;

        public const uint AUTH_FLAG_DISABLE_NEGOTIATE = 0x00000001;

        public const uint AUTH_FLAG_ENABLE_NEGOTIATE = 0x00000002;

        public const uint AUTH_FLAG_DISABLE_BASIC_CLEARCHANNEL = 0x00000004;

        public const uint AUTH_FLAG_DISABLE_SERVER_AUTH = 0x00000008;

        public const uint SECURITY_FLAG_UNKNOWNBIT = 0x80000000;

        public const uint SECURITY_FLAG_FORTEZZA = 0x08000000;

        public const uint SECURITY_FLAG_SSL = 0x00000002;

        public const uint SECURITY_FLAG_SSL3 = 0x00000004;

        public const uint SECURITY_FLAG_PCT = 0x00000008;

        public const uint SECURITY_FLAG_PCT4 = 0x00000010;

        public const uint SECURITY_FLAG_IETFSSL4 = 0x00000020;

        public const uint SECURITY_FLAG_IGNORE_REVOCATION = 0x00000080;

        public const uint SECURITY_FLAG_IGNORE_WRONG_USAGE = 0x00000200;

        public const uint SECURITY_FLAG_IGNORE_WEAK_SIGNATURE = 0x00010000;

        public const uint SECURITY_FLAG_OPT_IN_WEAK_SIGNATURE = 0x00020000;

        public const uint AUTODIAL_MODE_NEVER = 1;

        public const uint AUTODIAL_MODE_ALWAYS = 2;

        public const uint AUTODIAL_MODE_NO_NETWORK_PRESENT = 4;

        public const uint INTERNET_STATUS_RESOLVING_NAME = 10;

        public const uint INTERNET_STATUS_NAME_RESOLVED = 11;

        public const uint INTERNET_STATUS_CONNECTING_TO_SERVER = 20;

        public const uint INTERNET_STATUS_CONNECTED_TO_SERVER = 21;

        public const uint INTERNET_STATUS_SENDING_REQUEST = 30;

        public const uint INTERNET_STATUS_REQUEST_SENT = 31;

        public const uint INTERNET_STATUS_RECEIVING_RESPONSE = 40;

        public const uint INTERNET_STATUS_RESPONSE_RECEIVED = 41;

        public const uint INTERNET_STATUS_CTL_RESPONSE_RECEIVED = 42;

        public const uint INTERNET_STATUS_PREFETCH = 43;

        public const uint INTERNET_STATUS_CLOSING_CONNECTION = 50;

        public const uint INTERNET_STATUS_CONNECTION_CLOSED = 51;

        public const uint INTERNET_STATUS_HANDLE_CREATED = 60;

        public const uint INTERNET_STATUS_HANDLE_CLOSING = 70;

        public const uint INTERNET_STATUS_DETECTING_PROXY = 80;

        public const uint INTERNET_STATUS_REQUEST_COMPLETE = 100;

        public const uint INTERNET_STATUS_REDIRECT = 110;

        public const uint INTERNET_STATUS_INTERMEDIATE_RESPONSE = 120;

        public const uint INTERNET_STATUS_USER_INPUT_REQUIRED = 140;

        public const uint INTERNET_STATUS_STATE_CHANGE = 200;

        public const uint INTERNET_STATUS_COOKIE_SENT = 320;

        public const uint INTERNET_STATUS_COOKIE_RECEIVED = 321;

        public const uint INTERNET_STATUS_PRIVACY_IMPACTED = 324;

        public const uint INTERNET_STATUS_P3P_HEADER = 325;

        public const uint INTERNET_STATUS_P3P_POLICYREF = 326;

        public const uint INTERNET_STATUS_COOKIE_HISTORY = 327;

        public const uint MAX_GOPHER_DISPLAY_TEXT = 128;

        public const uint MAX_GOPHER_SELECTOR_TEXT = 256;

        public const uint MAX_GOPHER_CATEGORY_NAME = 128;

        public const uint MAX_GOPHER_ATTRIBUTE_NAME = 128;

        public const uint MIN_GOPHER_ATTRIBUTE_LENGTH = 256;

        public const uint GOPHER_ATTRIBUTE_ID_BASE = 0xabcccc00;

        public const uint GOPHER_CATEGORY_ID_ALL = GOPHER_ATTRIBUTE_ID_BASE + 1;

        public const uint GOPHER_CATEGORY_ID_INFO = GOPHER_ATTRIBUTE_ID_BASE + 2;

        public const uint GOPHER_CATEGORY_ID_ADMIN = GOPHER_ATTRIBUTE_ID_BASE + 3;

        public const uint GOPHER_CATEGORY_ID_VIEWS = GOPHER_ATTRIBUTE_ID_BASE + 4;

        public const uint GOPHER_CATEGORY_ID_ABSTRACT = GOPHER_ATTRIBUTE_ID_BASE + 5;

        public const uint GOPHER_CATEGORY_ID_VERONICA = GOPHER_ATTRIBUTE_ID_BASE + 6;

        public const uint GOPHER_CATEGORY_ID_ASK = GOPHER_ATTRIBUTE_ID_BASE + 7;

        public const uint GOPHER_CATEGORY_ID_UNKNOWN = GOPHER_ATTRIBUTE_ID_BASE + 8;

        public const uint GOPHER_ATTRIBUTE_ID_ALL = GOPHER_ATTRIBUTE_ID_BASE + 9;

        public const uint GOPHER_ATTRIBUTE_ID_ADMIN = GOPHER_ATTRIBUTE_ID_BASE + 10;

        public const uint GOPHER_ATTRIBUTE_ID_MOD_DATE = GOPHER_ATTRIBUTE_ID_BASE + 11;

        public const uint GOPHER_ATTRIBUTE_ID_TTL = GOPHER_ATTRIBUTE_ID_BASE + 12;

        public const uint GOPHER_ATTRIBUTE_ID_SCORE = GOPHER_ATTRIBUTE_ID_BASE + 13;

        public const uint GOPHER_ATTRIBUTE_ID_RANGE = GOPHER_ATTRIBUTE_ID_BASE + 14;

        public const uint GOPHER_ATTRIBUTE_ID_SITE = GOPHER_ATTRIBUTE_ID_BASE + 15;

        public const uint GOPHER_ATTRIBUTE_ID_ORG = GOPHER_ATTRIBUTE_ID_BASE + 16;

        public const uint GOPHER_ATTRIBUTE_ID_LOCATION = GOPHER_ATTRIBUTE_ID_BASE + 17;

        public const uint GOPHER_ATTRIBUTE_ID_GEOG = GOPHER_ATTRIBUTE_ID_BASE + 18;

        public const uint GOPHER_ATTRIBUTE_ID_TIMEZONE = GOPHER_ATTRIBUTE_ID_BASE + 19;

        public const uint GOPHER_ATTRIBUTE_ID_PROVIDER = GOPHER_ATTRIBUTE_ID_BASE + 20;

        public const uint GOPHER_ATTRIBUTE_ID_VERSION = GOPHER_ATTRIBUTE_ID_BASE + 21;

        public const uint GOPHER_ATTRIBUTE_ID_ABSTRACT = GOPHER_ATTRIBUTE_ID_BASE + 22;

        public const uint GOPHER_ATTRIBUTE_ID_VIEW = GOPHER_ATTRIBUTE_ID_BASE + 23;

        public const uint GOPHER_ATTRIBUTE_ID_TREEWALK = GOPHER_ATTRIBUTE_ID_BASE + 24;

        public const uint GOPHER_ATTRIBUTE_ID_UNKNOWN = GOPHER_ATTRIBUTE_ID_BASE + 25;

        public const uint HTTP_MAJOR_VERSION = 1;

        public const uint HTTP_MINOR_VERSION = 0;

        public const uint HTTP_QUERY_MIME_VERSION = 0;

        public const uint HTTP_QUERY_CONTENT_TYPE = 1;

        public const uint HTTP_QUERY_CONTENT_TRANSFER_ENCODING = 2;

        public const uint HTTP_QUERY_CONTENT_ID = 3;

        public const uint HTTP_QUERY_CONTENT_DESCRIPTION = 4;

        public const uint HTTP_QUERY_CONTENT_LENGTH = 5;

        public const uint HTTP_QUERY_CONTENT_LANGUAGE = 6;

        public const uint HTTP_QUERY_ALLOW = 7;

        public const uint HTTP_QUERY_PUBLIC = 8;

        public const uint HTTP_QUERY_DATE = 9;

        public const uint HTTP_QUERY_EXPIRES = 10;

        public const uint HTTP_QUERY_LAST_MODIFIED = 11;

        public const uint HTTP_QUERY_MESSAGE_ID = 12;

        public const uint HTTP_QUERY_URI = 13;

        public const uint HTTP_QUERY_DERIVED_FROM = 14;

        public const uint HTTP_QUERY_COST = 15;

        public const uint HTTP_QUERY_LINK = 16;

        public const uint HTTP_QUERY_PRAGMA = 17;

        public const uint HTTP_QUERY_VERSION = 18;

        public const uint HTTP_QUERY_STATUS_CODE = 19;

        public const uint HTTP_QUERY_STATUS_TEXT = 20;

        public const uint HTTP_QUERY_RAW_HEADERS = 21;

        public const uint HTTP_QUERY_RAW_HEADERS_CRLF = 22;

        public const uint HTTP_QUERY_CONNECTION = 23;

        public const uint HTTP_QUERY_ACCEPT = 24;

        public const uint HTTP_QUERY_ACCEPT_CHARSET = 25;

        public const uint HTTP_QUERY_ACCEPT_ENCODING = 26;

        public const uint HTTP_QUERY_ACCEPT_LANGUAGE = 27;

        public const uint HTTP_QUERY_AUTHORIZATION = 28;

        public const uint HTTP_QUERY_CONTENT_ENCODING = 29;

        public const uint HTTP_QUERY_FORWARDED = 30;

        public const uint HTTP_QUERY_FROM = 31;

        public const uint HTTP_QUERY_IF_MODIFIED_SINCE = 32;

        public const uint HTTP_QUERY_LOCATION = 33;

        public const uint HTTP_QUERY_ORIG_URI = 34;

        public const uint HTTP_QUERY_REFERER = 35;

        public const uint HTTP_QUERY_RETRY_AFTER = 36;

        public const uint HTTP_QUERY_SERVER = 37;

        public const uint HTTP_QUERY_TITLE = 38;

        public const uint HTTP_QUERY_USER_AGENT = 39;

        public const uint HTTP_QUERY_WWW_AUTHENTICATE = 40;

        public const uint HTTP_QUERY_PROXY_AUTHENTICATE = 41;

        public const uint HTTP_QUERY_ACCEPT_RANGES = 42;

        public const uint HTTP_QUERY_SET_COOKIE = 43;

        public const uint HTTP_QUERY_COOKIE = 44;

        public const uint HTTP_QUERY_REQUEST_METHOD = 45;

        public const uint HTTP_QUERY_REFRESH = 46;

        public const uint HTTP_QUERY_CONTENT_DISPOSITION = 47;

        public const uint HTTP_QUERY_AGE = 48;

        public const uint HTTP_QUERY_CACHE_CONTROL = 49;

        public const uint HTTP_QUERY_CONTENT_BASE = 50;

        public const uint HTTP_QUERY_CONTENT_LOCATION = 51;

        public const uint HTTP_QUERY_CONTENT_MD5 = 52;

        public const uint HTTP_QUERY_CONTENT_RANGE = 53;

        public const uint HTTP_QUERY_ETAG = 54;

        public const uint HTTP_QUERY_HOST = 55;

        public const uint HTTP_QUERY_IF_MATCH = 56;

        public const uint HTTP_QUERY_IF_NONE_MATCH = 57;

        public const uint HTTP_QUERY_IF_RANGE = 58;

        public const uint HTTP_QUERY_IF_UNMODIFIED_SINCE = 59;

        public const uint HTTP_QUERY_MAX_FORWARDS = 60;

        public const uint HTTP_QUERY_PROXY_AUTHORIZATION = 61;

        public const uint HTTP_QUERY_RANGE = 62;

        public const uint HTTP_QUERY_TRANSFER_ENCODING = 63;

        public const uint HTTP_QUERY_UPGRADE = 64;

        public const uint HTTP_QUERY_VARY = 65;

        public const uint HTTP_QUERY_VIA = 66;

        public const uint HTTP_QUERY_WARNING = 67;

        public const uint HTTP_QUERY_EXPECT = 68;

        public const uint HTTP_QUERY_PROXY_CONNECTION = 69;

        public const uint HTTP_QUERY_UNLESS_MODIFIED_SINCE = 70;

        public const uint HTTP_QUERY_ECHO_REQUEST = 71;

        public const uint HTTP_QUERY_ECHO_REPLY = 72;

        public const uint HTTP_QUERY_ECHO_HEADERS = 73;

        public const uint HTTP_QUERY_ECHO_HEADERS_CRLF = 74;

        public const uint HTTP_QUERY_PROXY_SUPPORT = 75;

        public const uint HTTP_QUERY_AUTHENTICATION_INFO = 76;

        public const uint HTTP_QUERY_PASSPORT_URLS = 77;

        public const uint HTTP_QUERY_PASSPORT_CONFIG = 78;

        public const uint HTTP_QUERY_X_CONTENT_TYPE_OPTIONS = 79;

        public const uint HTTP_QUERY_P3P = 80;

        public const uint HTTP_QUERY_X_P2P_PEERDIST = 81;

        public const uint HTTP_QUERY_TRANSLATE = 82;

        public const uint HTTP_QUERY_X_UA_COMPATIBLE = 83;

        public const uint HTTP_QUERY_DEFAULT_STYLE = 84;

        public const uint HTTP_QUERY_X_FRAME_OPTIONS = 85;

        public const uint HTTP_QUERY_X_XSS_PROTECTION = 86;

        public const uint HTTP_QUERY_SET_COOKIE2 = 87;

        public const uint HTTP_QUERY_DO_NOT_TRACK = 88;

        public const uint HTTP_QUERY_KEEP_ALIVE = 89;

        public const uint HTTP_QUERY_HTTP2_SETTINGS = 90;

        public const uint HTTP_QUERY_STRICT_TRANSPORT_SECURITY = 91;

        public const uint HTTP_QUERY_TOKEN_BINDING = 92;

        public const uint HTTP_QUERY_INCLUDE_REFERRED_TOKEN_BINDING_ID = 93;

        public const uint HTTP_QUERY_PUBLIC_KEY_PINS = 94;

        public const uint HTTP_QUERY_PUBLIC_KEY_PINS_REPORT_ONLY = 95;

        public const uint HTTP_QUERY_MAX = 95;

        public const uint HTTP_QUERY_CUSTOM = 65535;

        public const uint HTTP_QUERY_FLAG_REQUEST_HEADERS = 0x80000000;

        public const uint HTTP_QUERY_FLAG_SYSTEMTIME = 0x40000000;

        public const uint HTTP_QUERY_FLAG_NUMBER = 0x20000000;

        public const uint HTTP_QUERY_FLAG_COALESCE = 0x10000000;

        public const uint HTTP_QUERY_FLAG_NUMBER64 = 0x08000000;

        public const uint HTTP_QUERY_FLAG_COALESCE_WITH_COMMA = 0x04000000;

        public const uint HTTP_STATUS_MISDIRECTED_REQUEST = 421;

        public const uint HTTP_ADDREQ_INDEX_MASK = 0x0000FFFF;

        public const uint HTTP_ADDREQ_FLAGS_MASK = 0xFFFF0000;

        public const uint HSR_INITIATE = 0x00000008;

        public const uint HSR_DOWNLOAD = 0x00000010;

        public const uint HSR_CHUNKED = 0x00000020;

        public const uint INTERNET_COOKIE_IS_SECURE = 0x00000001;

        public const uint INTERNET_COOKIE_IS_SESSION = 0x00000002;

        public const uint INTERNET_COOKIE_PROMPT_REQUIRED = 0x00000020;

        public const uint INTERNET_COOKIE_EVALUATE_P3P = 0x00000040;

        public const uint INTERNET_COOKIE_APPLY_P3P = 0x00000080;

        public const uint INTERNET_COOKIE_P3P_ENABLED = 0x00000100;

        public const uint INTERNET_COOKIE_IS_RESTRICTED = 0x00000200;

        public const uint INTERNET_COOKIE_IE6 = 0x00000400;

        public const uint INTERNET_COOKIE_IS_LEGACY = 0x00000800;

        public const uint INTERNET_COOKIE_NON_SCRIPT = 0x00001000;

        public const uint INTERNET_COOKIE_HOST_ONLY = 0x00004000;

        public const uint INTERNET_COOKIE_APPLY_HOST_ONLY = 0x00008000;

        public const uint INTERNET_COOKIE_HOST_ONLY_APPLIED = 0x00080000;

        public const uint INTERNET_COOKIE_SAME_SITE_STRICT = 0x00100000;

        public const uint INTERNET_COOKIE_SAME_SITE_LAX = 0x00200000;

        public const uint INTERNET_COOKIE_SAME_SITE_LEVEL_CROSS_SITE = 0x00400000;

        public const uint FLAG_ICC_FORCE_CONNECTION = 0x00000001;

        public const uint FLAGS_ERROR_UI_FILTER_FOR_ERRORS = 0x01;

        public const uint FLAGS_ERROR_UI_FLAGS_CHANGE_OPTIONS = 0x02;

        public const uint FLAGS_ERROR_UI_FLAGS_GENERATE_DATA = 0x04;

        public const uint FLAGS_ERROR_UI_FLAGS_NO_UI = 0x08;

        public const uint FLAGS_ERROR_UI_SERIALIZE_DIALOGS = 0x10;

        public const uint INTERNET_ERROR_BASE = 12000;

        public const uint ERROR_INTERNET_OUT_OF_HANDLES = INTERNET_ERROR_BASE + 1;

        public const uint ERROR_INTERNET_TIMEOUT = INTERNET_ERROR_BASE + 2;

        public const uint ERROR_INTERNET_EXTENDED_ERROR = INTERNET_ERROR_BASE + 3;

        public const uint ERROR_INTERNET_INTERNAL_ERROR = INTERNET_ERROR_BASE + 4;

        public const uint ERROR_INTERNET_INVALID_URL = INTERNET_ERROR_BASE + 5;

        public const uint ERROR_INTERNET_UNRECOGNIZED_SCHEME = INTERNET_ERROR_BASE + 6;

        public const uint ERROR_INTERNET_NAME_NOT_RESOLVED = INTERNET_ERROR_BASE + 7;

        public const uint ERROR_INTERNET_PROTOCOL_NOT_FOUND = INTERNET_ERROR_BASE + 8;

        public const uint ERROR_INTERNET_INVALID_OPTION = INTERNET_ERROR_BASE + 9;

        public const uint ERROR_INTERNET_BAD_OPTION_LENGTH = INTERNET_ERROR_BASE + 10;

        public const uint ERROR_INTERNET_OPTION_NOT_SETTABLE = INTERNET_ERROR_BASE + 11;

        public const uint ERROR_INTERNET_SHUTDOWN = INTERNET_ERROR_BASE + 12;

        public const uint ERROR_INTERNET_INCORRECT_USER_NAME = INTERNET_ERROR_BASE + 13;

        public const uint ERROR_INTERNET_INCORRECT_PASSWORD = INTERNET_ERROR_BASE + 14;

        public const uint ERROR_INTERNET_LOGIN_FAILURE = INTERNET_ERROR_BASE + 15;

        public const uint ERROR_INTERNET_INVALID_OPERATION = INTERNET_ERROR_BASE + 16;

        public const uint ERROR_INTERNET_OPERATION_CANCELLED = INTERNET_ERROR_BASE + 17;

        public const uint ERROR_INTERNET_INCORRECT_HANDLE_TYPE = INTERNET_ERROR_BASE + 18;

        public const uint ERROR_INTERNET_INCORRECT_HANDLE_STATE = INTERNET_ERROR_BASE + 19;

        public const uint ERROR_INTERNET_NOT_PROXY_REQUEST = INTERNET_ERROR_BASE + 20;

        public const uint ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND = INTERNET_ERROR_BASE + 21;

        public const uint ERROR_INTERNET_BAD_REGISTRY_PARAMETER = INTERNET_ERROR_BASE + 22;

        public const uint ERROR_INTERNET_NO_DIRECT_ACCESS = INTERNET_ERROR_BASE + 23;

        public const uint ERROR_INTERNET_NO_CONTEXT = INTERNET_ERROR_BASE + 24;

        public const uint ERROR_INTERNET_NO_CALLBACK = INTERNET_ERROR_BASE + 25;

        public const uint ERROR_INTERNET_REQUEST_PENDING = INTERNET_ERROR_BASE + 26;

        public const uint ERROR_INTERNET_INCORRECT_FORMAT = INTERNET_ERROR_BASE + 27;

        public const uint ERROR_INTERNET_ITEM_NOT_FOUND = INTERNET_ERROR_BASE + 28;

        public const uint ERROR_INTERNET_CANNOT_CONNECT = INTERNET_ERROR_BASE + 29;

        public const uint ERROR_INTERNET_CONNECTION_ABORTED = INTERNET_ERROR_BASE + 30;

        public const uint ERROR_INTERNET_CONNECTION_RESET = INTERNET_ERROR_BASE + 31;

        public const uint ERROR_INTERNET_FORCE_RETRY = INTERNET_ERROR_BASE + 32;

        public const uint ERROR_INTERNET_INVALID_PROXY_REQUEST = INTERNET_ERROR_BASE + 33;

        public const uint ERROR_INTERNET_NEED_UI = INTERNET_ERROR_BASE + 34;

        public const uint ERROR_INTERNET_HANDLE_EXISTS = INTERNET_ERROR_BASE + 36;

        public const uint ERROR_INTERNET_SEC_CERT_DATE_INVALID = INTERNET_ERROR_BASE + 37;

        public const uint ERROR_INTERNET_SEC_CERT_CN_INVALID = INTERNET_ERROR_BASE + 38;

        public const uint ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR = INTERNET_ERROR_BASE + 39;

        public const uint ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR = INTERNET_ERROR_BASE + 40;

        public const uint ERROR_INTERNET_MIXED_SECURITY = INTERNET_ERROR_BASE + 41;

        public const uint ERROR_INTERNET_CHG_POST_IS_NON_SECURE = INTERNET_ERROR_BASE + 42;

        public const uint ERROR_INTERNET_POST_IS_NON_SECURE = INTERNET_ERROR_BASE + 43;

        public const uint ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED = INTERNET_ERROR_BASE + 44;

        public const uint ERROR_INTERNET_INVALID_CA = INTERNET_ERROR_BASE + 45;

        public const uint ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP = INTERNET_ERROR_BASE + 46;

        public const uint ERROR_INTERNET_ASYNC_THREAD_FAILED = INTERNET_ERROR_BASE + 47;

        public const uint ERROR_INTERNET_REDIRECT_SCHEME_CHANGE = INTERNET_ERROR_BASE + 48;

        public const uint ERROR_INTERNET_DIALOG_PENDING = INTERNET_ERROR_BASE + 49;

        public const uint ERROR_INTERNET_RETRY_DIALOG = INTERNET_ERROR_BASE + 50;

        public const uint ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR = INTERNET_ERROR_BASE + 52;

        public const uint ERROR_INTERNET_INSERT_CDROM = INTERNET_ERROR_BASE + 53;

        public const uint ERROR_INTERNET_FORTEZZA_LOGIN_NEEDED = INTERNET_ERROR_BASE + 54;

        public const uint ERROR_INTERNET_SEC_CERT_ERRORS = INTERNET_ERROR_BASE + 55;

        public const uint ERROR_INTERNET_SEC_CERT_NO_REV = INTERNET_ERROR_BASE + 56;

        public const uint ERROR_INTERNET_SEC_CERT_REV_FAILED = INTERNET_ERROR_BASE + 57;

        public const uint ERROR_HTTP_HSTS_REDIRECT_REQUIRED = INTERNET_ERROR_BASE + 60;

        public const uint ERROR_INTERNET_SEC_CERT_WEAK_SIGNATURE = INTERNET_ERROR_BASE + 62;

        public const uint ERROR_FTP_TRANSFER_IN_PROGRESS = INTERNET_ERROR_BASE + 110;

        public const uint ERROR_FTP_DROPPED = INTERNET_ERROR_BASE + 111;

        public const uint ERROR_FTP_NO_PASSIVE_MODE = INTERNET_ERROR_BASE + 112;

        public const uint ERROR_GOPHER_PROTOCOL_ERROR = INTERNET_ERROR_BASE + 130;

        public const uint ERROR_GOPHER_NOT_FILE = INTERNET_ERROR_BASE + 131;

        public const uint ERROR_GOPHER_DATA_ERROR = INTERNET_ERROR_BASE + 132;

        public const uint ERROR_GOPHER_END_OF_DATA = INTERNET_ERROR_BASE + 133;

        public const uint ERROR_GOPHER_INVALID_LOCATOR = INTERNET_ERROR_BASE + 134;

        public const uint ERROR_GOPHER_INCORRECT_LOCATOR_TYPE = INTERNET_ERROR_BASE + 135;

        public const uint ERROR_GOPHER_NOT_GOPHER_PLUS = INTERNET_ERROR_BASE + 136;

        public const uint ERROR_GOPHER_ATTRIBUTE_NOT_FOUND = INTERNET_ERROR_BASE + 137;

        public const uint ERROR_GOPHER_UNKNOWN_LOCATOR = INTERNET_ERROR_BASE + 138;

        public const uint ERROR_HTTP_HEADER_NOT_FOUND = INTERNET_ERROR_BASE + 150;

        public const uint ERROR_HTTP_DOWNLEVEL_SERVER = INTERNET_ERROR_BASE + 151;

        public const uint ERROR_HTTP_INVALID_SERVER_RESPONSE = INTERNET_ERROR_BASE + 152;

        public const uint ERROR_HTTP_INVALID_HEADER = INTERNET_ERROR_BASE + 153;

        public const uint ERROR_HTTP_INVALID_QUERY_REQUEST = INTERNET_ERROR_BASE + 154;

        public const uint ERROR_HTTP_HEADER_ALREADY_EXISTS = INTERNET_ERROR_BASE + 155;

        public const uint ERROR_HTTP_REDIRECT_FAILED = INTERNET_ERROR_BASE + 156;

        public const uint ERROR_HTTP_NOT_REDIRECTED = INTERNET_ERROR_BASE + 160;

        public const uint ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION = INTERNET_ERROR_BASE + 161;

        public const uint ERROR_HTTP_COOKIE_DECLINED = INTERNET_ERROR_BASE + 162;

        public const uint ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION = INTERNET_ERROR_BASE + 168;

        public const uint ERROR_INTERNET_SECURITY_CHANNEL_ERROR = INTERNET_ERROR_BASE + 157;

        public const uint ERROR_INTERNET_UNABLE_TO_CACHE_FILE = INTERNET_ERROR_BASE + 158;

        public const uint ERROR_INTERNET_TCPIP_NOT_INSTALLED = INTERNET_ERROR_BASE + 159;

        public const uint ERROR_INTERNET_DISCONNECTED = INTERNET_ERROR_BASE + 163;

        public const uint ERROR_INTERNET_SERVER_UNREACHABLE = INTERNET_ERROR_BASE + 164;

        public const uint ERROR_INTERNET_PROXY_SERVER_UNREACHABLE = INTERNET_ERROR_BASE + 165;

        public const uint ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT = INTERNET_ERROR_BASE + 166;

        public const uint ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT = INTERNET_ERROR_BASE + 167;

        public const uint ERROR_INTERNET_SEC_INVALID_CERT = INTERNET_ERROR_BASE + 169;

        public const uint ERROR_INTERNET_SEC_CERT_REVOKED = INTERNET_ERROR_BASE + 170;

        public const uint ERROR_INTERNET_FAILED_DUETOSECURITYCHECK = INTERNET_ERROR_BASE + 171;

        public const uint ERROR_INTERNET_NOT_INITIALIZED = INTERNET_ERROR_BASE + 172;

        public const uint ERROR_INTERNET_NEED_MSN_SSPI_PKG = INTERNET_ERROR_BASE + 173;

        public const uint ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY = INTERNET_ERROR_BASE + 174;

        public const uint ERROR_INTERNET_DECODING_FAILED = INTERNET_ERROR_BASE + 175;

        public const uint ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED_PROXY = INTERNET_ERROR_BASE + 187;

        public const uint ERROR_INTERNET_SECURE_FAILURE_PROXY = INTERNET_ERROR_BASE + 188;

        public const uint ERROR_INTERNET_HTTP_PROTOCOL_MISMATCH = INTERNET_ERROR_BASE + 190;

        public const uint INTERNET_ERROR_LAST = INTERNET_ERROR_BASE + 190;

        public const uint NORMAL_CACHE_ENTRY = 0x00000001;

        public const uint STICKY_CACHE_ENTRY = 0x00000004;

        public const uint EDITED_CACHE_ENTRY = 0x00000008;

        public const uint TRACK_OFFLINE_CACHE_ENTRY = 0x00000010;

        public const uint TRACK_ONLINE_CACHE_ENTRY = 0x00000020;

        public const uint SPARSE_CACHE_ENTRY = 0x00010000;

        public const uint COOKIE_CACHE_ENTRY = 0x00100000;

        public const uint URLHISTORY_CACHE_ENTRY = 0x00200000;

        public const uint CACHEGROUP_ATTRIBUTE_GET_ALL = 0xffffffff;

        public const uint CACHEGROUP_ATTRIBUTE_BASIC = 0x00000001;

        public const uint CACHEGROUP_ATTRIBUTE_FLAG = 0x00000002;

        public const uint CACHEGROUP_ATTRIBUTE_TYPE = 0x00000004;

        public const uint CACHEGROUP_ATTRIBUTE_QUOTA = 0x00000008;

        public const uint CACHEGROUP_ATTRIBUTE_GROUPNAME = 0x00000010;

        public const uint CACHEGROUP_ATTRIBUTE_STORAGE = 0x00000020;

        public const uint CACHEGROUP_FLAG_NONPURGEABLE = 0x00000001;

        public const uint CACHEGROUP_FLAG_GIDONLY = 0x00000004;

        public const uint CACHEGROUP_FLAG_FLUSHURL_ONDELETE = 0x00000002;

        public const uint CACHEGROUP_SEARCH_ALL = 0x00000000;

        public const uint CACHEGROUP_SEARCH_BYURL = 0x00000001;

        public const uint CACHEGROUP_TYPE_INVALID = 0x00000001;

        public const uint GROUPNAME_MAX_LENGTH = 120;

        public const uint GROUP_OWNER_STORAGE_SIZE = 4;

        public const uint CACHE_ENTRY_ATTRIBUTE_FC = 0x00000004;

        public const uint CACHE_ENTRY_HITRATE_FC = 0x00000010;

        public const uint CACHE_ENTRY_MODTIME_FC = 0x00000040;

        public const uint CACHE_ENTRY_EXPTIME_FC = 0x00000080;

        public const uint CACHE_ENTRY_ACCTIME_FC = 0x00000100;

        public const uint CACHE_ENTRY_SYNCTIME_FC = 0x00000200;

        public const uint CACHE_ENTRY_HEADERINFO_FC = 0x00000400;

        public const uint CACHE_ENTRY_EXEMPT_DELTA_FC = 0x00000800;

        public const uint INTERNET_CACHE_GROUP_ADD = 0;

        public const uint INTERNET_CACHE_GROUP_REMOVE = 1;

        public const uint INTERNET_DIAL_FORCE_PROMPT = 0x2000;

        public const uint INTERNET_DIAL_SHOW_OFFLINE = 0x4000;

        public const uint INTERNET_DIAL_UNATTENDED = 0x8000;

        public const uint INTERENT_GOONLINE_REFRESH = 0x00000001;

        public const uint INTERENT_GOONLINE_NOPROMPT = 0x00000002;

        public const uint INTERENT_GOONLINE_MASK = 0x00000003;

        public const uint INTERNET_CONNECTION_LAN = 0x02;

        public const uint INTERNET_CONNECTION_OFFLINE = 0x20;

        public const uint INTERNET_CUSTOMDIAL_CONNECT = 0;

        public const uint INTERNET_CUSTOMDIAL_UNATTENDED = 1;

        public const uint INTERNET_CUSTOMDIAL_DISCONNECT = 2;

        public const uint INTERNET_CUSTOMDIAL_SHOWOFFLINE = 4;

        public const uint INTERNET_CUSTOMDIAL_SAFE_FOR_UNATTENDED = 1;

        public const uint INTERNET_CUSTOMDIAL_WILL_SUPPLY_STATE = 2;

        public const uint INTERNET_CUSTOMDIAL_CAN_HANGUP = 4;

        public const uint INTERNET_DIALSTATE_DISCONNECTED = 1;

        public const uint INTERNET_IDENTITY_FLAG_PRIVATE_CACHE = 0x01;

        public const uint INTERNET_IDENTITY_FLAG_SHARED_CACHE = 0x02;

        public const uint INTERNET_IDENTITY_FLAG_CLEAR_DATA = 0x04;

        public const uint INTERNET_IDENTITY_FLAG_CLEAR_COOKIES = 0x08;

        public const uint INTERNET_IDENTITY_FLAG_CLEAR_HISTORY = 0x10;

        public const uint INTERNET_IDENTITY_FLAG_CLEAR_CONTENT = 0x20;

        public const uint INTERNET_SUPPRESS_RESET_ALL = 0x00;

        public const uint INTERNET_SUPPRESS_COOKIE_POLICY = 0x01;

        public const uint INTERNET_SUPPRESS_COOKIE_POLICY_RESET = 0x02;

        public const uint PRIVACY_TEMPLATE_NO_COOKIES = 0;

        public const uint PRIVACY_TEMPLATE_HIGH = 1;

        public const uint PRIVACY_TEMPLATE_MEDIUM_HIGH = 2;

        public const uint PRIVACY_TEMPLATE_MEDIUM = 3;

        public const uint PRIVACY_TEMPLATE_MEDIUM_LOW = 4;

        public const uint PRIVACY_TEMPLATE_LOW = 5;

        public const uint PRIVACY_TEMPLATE_CUSTOM = 100;

        public const uint PRIVACY_TEMPLATE_ADVANCED = 101;

        public const uint PRIVACY_TYPE_FIRST_PARTY = 0;

        public const uint PRIVACY_TYPE_THIRD_PARTY = 1;

        public const uint MAX_CACHE_ENTRY_INFO_SIZE = 4096;

        public const uint INTERNET_REQFLAG_FROM_APP_CACHE = 0x00000100;

        public const uint INTERNET_FLAG_BGUPDATE = 0x00000008;

        public const uint INTERNET_FLAG_FTP_FOLDER_VIEW = 0x00000004;

        public const uint INTERNET_PREFETCH_PROGRESS = 0;

        public const uint INTERNET_PREFETCH_COMPLETE = 1;

        public const uint INTERNET_PREFETCH_ABORTED = 2;

        public const uint DLG_FLAGS_INVALID_CA = 0x01000000;

        public const uint DLG_FLAGS_SEC_CERT_CN_INVALID = 0x02000000;

        public const uint DLG_FLAGS_SEC_CERT_DATE_INVALID = 0x04000000;

        public const uint DLG_FLAGS_WEAK_SIGNATURE = 0x00200000;

        public const uint DLG_FLAGS_INSECURE_FALLBACK = 0x00400000;

        public const uint DLG_FLAGS_SEC_CERT_REV_FAILED = 0x00800000;

        public const uint INTERNET_SERVICE_URL = 0;

        public const uint INTERNET_OPTION_CONTEXT_VALUE_OLD = 10;

        public const uint INTERNET_OPTION_NET_SPEED = 61;

        public const uint INTERNET_OPTION_SECURITY_CONNECTION_INFO = 66;

        public const uint INTERNET_OPTION_DETECT_POST_SEND = 71;

        public const uint INTERNET_OPTION_DISABLE_NTLM_PREAUTH = 72;

        public const uint INTERNET_OPTION_ORIGINAL_CONNECT_FLAGS = 97;

        public const uint INTERNET_OPTION_CERT_ERROR_FLAGS = 98;

        public const uint INTERNET_OPTION_IGNORE_CERT_ERROR_FLAGS = 99;

        public const uint INTERNET_OPTION_SESSION_START_TIME = 106;

        public const uint INTERNET_OPTION_PROXY_CREDENTIALS = 107;

        public const uint INTERNET_OPTION_EXTENDED_CALLBACKS = 108;

        public const uint INTERNET_OPTION_PROXY_FROM_REQUEST = 109;

        public const uint INTERNET_OPTION_ALLOW_FAILED_CONNECT_CONTENT = 110;

        public const uint INTERNET_OPTION_CACHE_PARTITION = 111;

        public const uint INTERNET_OPTION_AUTODIAL_HWND = 112;

        public const uint INTERNET_OPTION_SERVER_CREDENTIALS = 113;

        public const uint INTERNET_OPTION_WPAD_SLEEP = 114;

        public const uint INTERNET_OPTION_FAIL_ON_CACHE_WRITE_ERROR = 115;

        public const uint INTERNET_OPTION_DOWNLOAD_MODE = 116;

        public const uint INTERNET_OPTION_RESPONSE_RESUMABLE = 117;

        public const uint INTERNET_OPTION_CM_HANDLE_COPY_REF = 118;

        public const uint INTERNET_OPTION_CONNECTION_INFO = 120;

        public const uint INTERNET_OPTION_BACKGROUND_CONNECTIONS = 121;

        public const uint INTERNET_OPTION_DO_NOT_TRACK = 123;

        public const uint INTERNET_OPTION_USE_MODIFIED_HEADER_FILTER = 124;

        public const uint INTERNET_OPTION_WWA_MODE = 125;

        public const uint INTERNET_OPTION_UPGRADE_TO_WEB_SOCKET = 126;

        public const uint INTERNET_OPTION_WEB_SOCKET_KEEPALIVE_INTERVAL = 127;

        public const uint INTERNET_OPTION_UNLOAD_NOTIFY_EVENT = 128;

        public const uint INTERNET_OPTION_SOCKET_NODELAY = 129;

        public const uint INTERNET_OPTION_APP_CACHE = 130;

        public const uint INTERNET_OPTION_DEPENDENCY_HANDLE = 131;

        public const uint INTERNET_OPTION_USE_FIRST_AVAILABLE_CONNECTION = 132;

        public const uint INTERNET_OPTION_TIMED_CONNECTION_LIMIT_BYPASS = 133;

        public const uint INTERNET_OPTION_WEB_SOCKET_CLOSE_TIMEOUT = 134;

        public const uint INTERNET_OPTION_FLUSH_STATE = 135;

        public const uint INTERNET_OPTION_DISALLOW_PREMATURE_EOF = 137;

        public const uint INTERNET_OPTION_SOCKET_NOTIFICATION_IOCTL = 138;

        public const uint INTERNET_OPTION_CACHE_ENTRY_EXTRA_DATA = 139;

        public const uint INTERNET_OPTION_MAX_QUERY_BUFFER_SIZE = 140;

        public const uint INTERNET_OPTION_FALSE_START = 141;

        public const uint INTERNET_OPTION_USER_PASS_SERVER_ONLY = 142;

        public const uint INTERNET_OPTION_SERVER_AUTH_SCHEME = 143;

        public const uint INTERNET_OPTION_PROXY_AUTH_SCHEME = 144;

        public const uint INTERNET_OPTION_TUNNEL_ONLY = 145;

        public const uint INTERNET_OPTION_SOURCE_PORT = 146;

        public const uint INTERNET_OPTION_CHUNK_ENCODE_REQUEST = 150;

        public const uint INTERNET_OPTION_SECURE_FAILURE = 151;

        public const uint INTERNET_OPTION_NOTIFY_SENDING_COOKIE = 152;

        public const uint INTERNET_OPTION_CLIENT_CERT_ISSUER_LIST = 153;

        public const uint INTERNET_OPTION_RESET = 154;

        public const uint INTERNET_OPTION_SERVER_ADDRESS_INFO = 156;

        public const uint INTERNET_OPTION_ENABLE_WBOEXT = 158;

        public const uint INTERNET_OPTION_DISABLE_INSECURE_FALLBACK = 160;

        public const uint INTERNET_OPTION_ALLOW_INSECURE_FALLBACK = 161;

        public const uint INTERNET_OPTION_SET_IN_PRIVATE = 164;

        public const uint INTERNET_OPTION_DOWNLOAD_MODE_HANDLE = 165;

        public const uint INTERNET_OPTION_EDGE_COOKIES = 166;

        public const uint INTERNET_OPTION_NO_HTTP_SERVER_AUTH = 167;

        public const uint INTERNET_OPTION_ENABLE_HEADER_CALLBACKS = 168;

        public const uint INTERNET_OPTION_PRESERVE_REQUEST_SERVER_CREDENTIALS_ON_REDIRECT = 169;

        public const uint INTERNET_OPTION_PRESERVE_REFERER_ON_HTTPS_TO_HTTP_REDIRECT = 170;

        public const uint INTERNET_OPTION_TCP_FAST_OPEN = 171;

        public const uint INTERNET_OPTION_SYNC_MODE_AUTOMATIC_SESSION_DISABLED = 172;

        public const uint INTERNET_OPTION_ENABLE_ZLIB_DEFLATE = 173;

        public const uint INTERNET_OPTION_ENCODE_FALLBACK_FOR_REDIRECT_URI = 174;

        public const uint INTERNET_OPTION_EDGE_COOKIES_TEMP = 175;

        public const uint INTERNET_OPTION_OPT_IN_WEAK_SIGNATURE = 176;

        public const uint INTERNET_OPTION_PARSE_LINE_FOLDING = 177;

        public const uint INTERNET_OPTION_FORCE_DECODE = 178;

        public const uint INTERNET_OPTION_COOKIES_APPLY_HOST_ONLY = 179;

        public const uint INTERNET_OPTION_EDGE_MODE = 180;

        public const uint INTERNET_OPTION_CANCEL_CACHE_WRITE = 182;

        public const uint INTERNET_OPTION_AUTH_SCHEME_SELECTED = 183;

        public const uint INTERNET_OPTION_NOCACHE_WRITE_IN_PRIVATE = 184;

        public const uint INTERNET_OPTION_ACTIVITY_ID = 185;

        public const uint INTERNET_OPTION_REQUEST_TIMES = 186;

        public const uint DUO_PROTOCOL_FLAG_SPDY3 = 0x1;

        public const uint AUTH_FLAG_RESET = 0x00000000;

        public const uint INTERNET_AUTH_SCHEME_BASIC = 0;

        public const uint INTERNET_AUTH_SCHEME_DIGEST = 1;

        public const uint INTERNET_AUTH_SCHEME_NTLM = 2;

        public const uint INTERNET_AUTH_SCHEME_KERBEROS = 3;

        public const uint INTERNET_AUTH_SCHEME_NEGOTIATE = 4;

        public const uint INTERNET_AUTH_SCHEME_PASSPORT = 5;

        public const uint INTERNET_AUTH_SCHEME_UNKNOWN = 6;

        public const uint INTERNET_STATUS_SENDING_COOKIE = 328;

        public const uint INTERNET_STATUS_REQUEST_HEADERS_SET = 329;

        public const uint INTERNET_STATUS_RESPONSE_HEADERS_SET = 330;

        public const uint INTERNET_STATUS_PROXY_CREDENTIALS = 400;

        public const uint INTERNET_STATUS_SERVER_CREDENTIALS = 401;

        public const uint INTERNET_STATUS_SERVER_CONNECTION_STATE = 410;

        public const uint INTERNET_STATUS_END_BROWSER_SESSION = 420;

        public const uint INTERNET_STATUS_COOKIE = 430;

        public const uint COOKIE_STATE_LB = 0;

        public const uint COOKIE_STATE_UB = 5;

        public const uint MaxPrivacySettings = 0x4000;

        public const uint INTERNET_STATUS_FILTER_RESOLVING = 0x00000001;

        public const uint INTERNET_STATUS_FILTER_RESOLVED = 0x00000002;

        public const uint INTERNET_STATUS_FILTER_CONNECTING = 0x00000004;

        public const uint INTERNET_STATUS_FILTER_CONNECTED = 0x00000008;

        public const uint INTERNET_STATUS_FILTER_SENDING = 0x00000010;

        public const uint INTERNET_STATUS_FILTER_SENT = 0x00000020;

        public const uint INTERNET_STATUS_FILTER_RECEIVING = 0x00000040;

        public const uint INTERNET_STATUS_FILTER_RECEIVED = 0x00000080;

        public const uint INTERNET_STATUS_FILTER_CLOSING = 0x00000100;

        public const uint INTERNET_STATUS_FILTER_CLOSED = 0x00000200;

        public const uint INTERNET_STATUS_FILTER_HANDLE_CREATED = 0x00000400;

        public const uint INTERNET_STATUS_FILTER_HANDLE_CLOSING = 0x00000800;

        public const uint INTERNET_STATUS_FILTER_PREFETCH = 0x00001000;

        public const uint INTERNET_STATUS_FILTER_REDIRECT = 0x00002000;

        public const uint INTERNET_STATUS_FILTER_STATE_CHANGE = 0x00004000;

        public const uint HTTP_ADDREQ_FLAG_RESPONSE_HEADERS = 0x02000000;

        public const uint HTTP_ADDREQ_FLAG_ALLOW_EMPTY_VALUES = 0x04000000;

        public const uint COOKIE_DONT_ALLOW = 1;

        public const uint COOKIE_ALLOW = 2;

        public const uint COOKIE_ALLOW_ALL = 4;

        public const uint COOKIE_DONT_ALLOW_ALL = 8;

        public const uint COOKIE_OP_SET = 0x01;

        public const uint COOKIE_OP_MODIFY = 0x02;

        public const uint COOKIE_OP_GET = 0x04;

        public const uint COOKIE_OP_SESSION = 0x08;

        public const uint COOKIE_OP_PERSISTENT = 0x10;

        public const uint COOKIE_OP_3RD_PARTY = 0x20;

        public const uint INTERNET_COOKIE_PERSISTENT_HOST_ONLY = 0x00010000;

        public const uint INTERNET_COOKIE_RESTRICTED_ZONE = 0x00020000;

        public const uint INTERNET_COOKIE_EDGE_COOKIES = 0x00040000;

        public const uint INTERNET_COOKIE_ALL_COOKIES = 0x20000000;

        public const uint INTERNET_COOKIE_NO_CALLBACK = 0x40000000;

        public const uint INTERNET_COOKIE_ECTX_3RDPARTY = 0x80000000;

        public const uint FLAGS_ERROR_UI_SHOW_IDN_HOSTNAME = 0x20;

        public const uint ERROR_INTERNET_NO_NEW_CONTAINERS = INTERNET_ERROR_BASE + 51;

        public const uint ERROR_INTERNET_SOURCE_PORT_IN_USE = INTERNET_ERROR_BASE + 58;

        public const uint ERROR_INTERNET_INSECURE_FALLBACK_REQUIRED = INTERNET_ERROR_BASE + 59;

        public const uint ERROR_INTERNET_PROXY_ALERT = INTERNET_ERROR_BASE + 61;

        public const uint ERROR_INTERNET_NO_CM_CONNECTION = INTERNET_ERROR_BASE + 80;

        public const uint ERROR_HTTP_PUSH_STATUS_CODE_NOT_SUPPORTED = INTERNET_ERROR_BASE + 147;

        public const uint ERROR_HTTP_PUSH_RETRY_NOT_SUPPORTED = INTERNET_ERROR_BASE + 148;

        public const uint ERROR_HTTP_PUSH_ENABLE_FAILED = INTERNET_ERROR_BASE + 149;

        public const uint ERROR_INTERNET_DISALLOW_INPRIVATE = INTERNET_ERROR_BASE + 189;

        public const uint INTERNET_INTERNAL_ERROR_BASE = INTERNET_ERROR_BASE + 900;

        public const uint ERROR_INTERNET_INTERNAL_SOCKET_ERROR = INTERNET_INTERNAL_ERROR_BASE + 1;

        public const uint ERROR_INTERNET_CONNECTION_AVAILABLE = INTERNET_INTERNAL_ERROR_BASE + 2;

        public const uint ERROR_INTERNET_NO_KNOWN_SERVERS = INTERNET_INTERNAL_ERROR_BASE + 3;

        public const uint ERROR_INTERNET_PING_FAILED = INTERNET_INTERNAL_ERROR_BASE + 4;

        public const uint ERROR_INTERNET_NO_PING_SUPPORT = INTERNET_INTERNAL_ERROR_BASE + 5;

        public const uint ERROR_INTERNET_CACHE_SUCCESS = INTERNET_INTERNAL_ERROR_BASE + 6;

        public const uint ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION_EX = INTERNET_INTERNAL_ERROR_BASE + 7;

        public const uint HTTP_1_1_CACHE_ENTRY = 0x00000040;

        public const uint STATIC_CACHE_ENTRY = 0x00000080;

        public const uint MUST_REVALIDATE_CACHE_ENTRY = 0x00000100;

        public const uint SHORTPATH_CACHE_ENTRY = 0x00000200;

        public const uint DOWNLOAD_CACHE_ENTRY = 0x00000400;

        public const uint REDIRECT_CACHE_ENTRY = 0x00000800;

        public const uint COOKIE_ACCEPTED_CACHE_ENTRY = 0x00001000;

        public const uint COOKIE_LEASHED_CACHE_ENTRY = 0x00002000;

        public const uint COOKIE_DOWNGRADED_CACHE_ENTRY = 0x00004000;

        public const uint COOKIE_REJECTED_CACHE_ENTRY = 0x00008000;

        public const uint PRIVACY_MODE_CACHE_ENTRY = 0x00020000;

        public const uint XDR_CACHE_ENTRY = 0x00040000;

        public const uint IMMUTABLE_CACHE_ENTRY = 0x00080000;

        public const uint PENDING_DELETE_CACHE_ENTRY = 0x00400000;

        public const uint OTHER_USER_CACHE_ENTRY = 0x00800000;

        public const uint PRIVACY_IMPACTED_CACHE_ENTRY = 0x02000000;

        public const uint POST_RESPONSE_CACHE_ENTRY = 0x04000000;

        public const uint INSTALLED_CACHE_ENTRY = 0x10000000;

        public const uint POST_CHECK_CACHE_ENTRY = 0x20000000;

        public const uint IDENTITY_CACHE_ENTRY = 0x80000000;

        public const uint ANY_CACHE_ENTRY = 0xFFFFFFFF;

        public const uint CACHEGROUP_FLAG_VALID = 0x00000007;

        public const ulong CACHEGROUP_ID_BUILTIN_STICKY = 0x1000000000000007;

        public const uint INTERNET_CACHE_FLAG_ALLOW_COLLISIONS = 0x00000100;

        public const uint INTERNET_CACHE_FLAG_INSTALLED_ENTRY = 0x00000200;

        public const uint INTERNET_CACHE_FLAG_ENTRY_OR_MAPPING = 0x00000400;

        public const uint INTERNET_CACHE_FLAG_ADD_FILENAME_ONLY = 0x00000800;

        public const uint INTERNET_CACHE_FLAG_GET_STRUCT_ONLY = 0x00001000;

        public const uint CACHE_ENTRY_TYPE_FC = 0x00001000;

        public const uint CACHE_ENTRY_MODIFY_DATA_FC = 0x80000000;

        public const uint INTERNET_CACHE_CONTAINER_NOSUBDIRS = 0x1;

        public const uint INTERNET_CACHE_CONTAINER_AUTODELETE = 0x2;

        public const uint INTERNET_CACHE_CONTAINER_RESERVED1 = 0x4;

        public const uint INTERNET_CACHE_CONTAINER_NODESKTOPINIT = 0x8;

        public const uint INTERNET_CACHE_CONTAINER_MAP_ENABLED = 0x10;

        public const uint INTERNET_CACHE_CONTAINER_BLOOM_FILTER = 0x20;

        public const uint INTERNET_CACHE_CONTAINER_SHARE_READ = 0x100;

        public const uint INTERNET_CACHE_CONTAINER_SHARE_READ_WRITE = 0x300;

        public const uint CACHE_FIND_CONTAINER_RETURN_NOCHANGE = 0x1;

        public const uint CACHE_HEADER_DATA_CURRENT_SETTINGS_VERSION = 0;

        public const uint CACHE_HEADER_DATA_CONLIST_CHANGE_COUNT = 1;

        public const uint CACHE_HEADER_DATA_COOKIE_CHANGE_COUNT = 2;

        public const uint CACHE_HEADER_DATA_NOTIFICATION_HWND = 3;

        public const uint CACHE_HEADER_DATA_NOTIFICATION_MESG = 4;

        public const uint CACHE_HEADER_DATA_ROOTGROUP_OFFSET = 5;

        public const uint CACHE_HEADER_DATA_GID_LOW = 6;

        public const uint CACHE_HEADER_DATA_GID_HIGH = 7;

        public const uint CACHE_HEADER_DATA_LAST_SCAVENGE_TIMESTAMP = 8;

        public const uint CACHE_HEADER_DATA_CACHE_READ_COUNT_SINCE_LAST_SCAVENGE = 9;

        public const uint CACHE_HEADER_DATA_CACHE_WRITE_COUNT_SINCE_LAST_SCAVENGE = 10;

        public const uint CACHE_HEADER_DATA_HSTS_CHANGE_COUNT = 11;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_12 = 12;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_13 = 13;

        public const uint CACHE_HEADER_DATA_SSL_STATE_COUNT = 14;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_15 = 15;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_16 = 16;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_17 = 17;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_18 = 18;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_19 = 19;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_20 = 20;

        public const uint CACHE_HEADER_DATA_NOTIFICATION_FILTER = 21;

        public const uint CACHE_HEADER_DATA_ROOT_LEAK_OFFSET = 22;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_23 = 23;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_24 = 24;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_25 = 25;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_26 = 26;

        public const uint CACHE_HEADER_DATA_ROOT_GROUPLIST_OFFSET = 27;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_28 = 28;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_29 = 29;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_30 = 30;

        public const uint CACHE_HEADER_DATA_CACHE_RESERVED_31 = 31;

        public const uint CACHE_HEADER_DATA_LAST = 31;

        public const uint CACHE_NOTIFY_ADD_URL = 0x00000001;

        public const uint CACHE_NOTIFY_DELETE_URL = 0x00000002;

        public const uint CACHE_NOTIFY_UPDATE_URL = 0x00000004;

        public const uint CACHE_NOTIFY_DELETE_ALL = 0x00000008;

        public const uint CACHE_NOTIFY_URL_SET_STICKY = 0x00000010;

        public const uint CACHE_NOTIFY_URL_UNSET_STICKY = 0x00000020;

        public const uint CACHE_NOTIFY_SET_ONLINE = 0x00000100;

        public const uint CACHE_NOTIFY_SET_OFFLINE = 0x00000200;

        public const uint CACHE_NOTIFY_FILTER_CHANGED = 0x10000000;

        public const uint APP_CACHE_LOOKUP_NO_MASTER_ONLY = 0x1;

        public const uint APP_CACHE_ENTRY_TYPE_MASTER = 0x01;

        public const uint APP_CACHE_ENTRY_TYPE_EXPLICIT = 0x02;

        public const uint APP_CACHE_ENTRY_TYPE_FALLBACK = 0x04;

        public const uint APP_CACHE_ENTRY_TYPE_FOREIGN = 0x08;

        public const uint APP_CACHE_ENTRY_TYPE_MANIFEST = 0x10;

        public const uint CACHE_CONFIG_CONTENT_QUOTA_FC = 0x00008000;

        public const uint CACHE_CONFIG_TOTAL_CONTENT_QUOTA_FC = 0x00010000;

        public const uint CACHE_CONFIG_APPCONTAINER_CONTENT_QUOTA_FC = 0x00020000;

        public const uint CACHE_CONFIG_APPCONTAINER_TOTAL_CONTENT_QUOTA_FC = 0x00040000;

        public const uint INTERNET_AUTOPROXY_INIT_DEFAULT = 0x1;

        public const uint INTERNET_AUTOPROXY_INIT_DOWNLOADSYNC = 0x2;

        public const uint INTERNET_AUTOPROXY_INIT_QUERYSTATE = 0x4;

        public const uint INTERNET_AUTOPROXY_INIT_ONLYQUERY = 0x8;

        public const uint INTERNET_SUPPRESS_COOKIE_PERSIST = 0x03;

        public const uint INTERNET_SUPPRESS_COOKIE_PERSIST_RESET = 0x04;

        public const uint HTTP_WEB_SOCKET_MAX_CLOSE_REASON_LENGTH = 123;

        public const uint HTTP_WEB_SOCKET_MIN_KEEPALIVE_VALUE = 10000;

    }
}
