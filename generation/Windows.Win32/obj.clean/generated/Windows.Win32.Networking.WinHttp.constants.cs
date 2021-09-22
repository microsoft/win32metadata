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


namespace Windows.Win32.Networking.WinHttp
{
    public static partial class Apis
    {
        public const uint WINHTTP_FLAG_ASYNC = 0x10000000;

        public const uint WINHTTP_FLAG_SECURE_DEFAULTS = 0x30000000;

        public const uint SECURITY_FLAG_IGNORE_UNKNOWN_CA = 0x00000100;

        public const uint SECURITY_FLAG_IGNORE_CERT_DATE_INVALID = 0x00002000;

        public const uint SECURITY_FLAG_IGNORE_CERT_CN_INVALID = 0x00001000;

        public const uint SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE = 0x00000200;

        public const uint WINHTTP_AUTOPROXY_AUTO_DETECT = 0x00000001;

        public const uint WINHTTP_AUTOPROXY_CONFIG_URL = 0x00000002;

        public const uint WINHTTP_AUTOPROXY_HOST_KEEPCASE = 0x00000004;

        public const uint WINHTTP_AUTOPROXY_HOST_LOWERCASE = 0x00000008;

        public const uint WINHTTP_AUTOPROXY_ALLOW_AUTOCONFIG = 0x00000100;

        public const uint WINHTTP_AUTOPROXY_ALLOW_STATIC = 0x00000200;

        public const uint WINHTTP_AUTOPROXY_ALLOW_CM = 0x00000400;

        public const uint WINHTTP_AUTOPROXY_RUN_INPROCESS = 0x00010000;

        public const uint WINHTTP_AUTOPROXY_RUN_OUTPROCESS_ONLY = 0x00020000;

        public const uint WINHTTP_AUTOPROXY_NO_DIRECTACCESS = 0x00040000;

        public const uint WINHTTP_AUTOPROXY_NO_CACHE_CLIENT = 0x00080000;

        public const uint WINHTTP_AUTOPROXY_NO_CACHE_SVC = 0x00100000;

        public const uint WINHTTP_AUTOPROXY_SORT_RESULTS = 0x00400000;

        public const uint WINHTTP_AUTO_DETECT_TYPE_DHCP = 0x00000001;

        public const uint WINHTTP_AUTO_DETECT_TYPE_DNS_A = 0x00000002;

        public const uint NETWORKING_KEY_BUFSIZE = 128;

        public const uint WINHTTP_PROXY_TYPE_DIRECT = 0x00000001;

        public const uint WINHTTP_PROXY_TYPE_PROXY = 0x00000002;

        public const uint WINHTTP_PROXY_TYPE_AUTO_PROXY_URL = 0x00000004;

        public const uint WINHTTP_PROXY_TYPE_AUTO_DETECT = 0x00000008;

        public const uint WINHTTP_REQUEST_STAT_FLAG_TCP_FAST_OPEN = 0x00000001;

        public const uint WINHTTP_REQUEST_STAT_FLAG_TLS_SESSION_RESUMPTION = 0x00000002;

        public const uint WINHTTP_REQUEST_STAT_FLAG_TLS_FALSE_START = 0x00000004;

        public const uint WINHTTP_REQUEST_STAT_FLAG_PROXY_TLS_SESSION_RESUMPTION = 0x00000008;

        public const uint WINHTTP_REQUEST_STAT_FLAG_PROXY_TLS_FALSE_START = 0x00000010;

        public const uint WINHTTP_REQUEST_STAT_FLAG_FIRST_REQUEST = 0x00000020;

        public const uint WINHTTP_TIME_FORMAT_BUFSIZE = 62;

        public const uint WINHTTP_OPTION_CALLBACK = 1;

        public const uint WINHTTP_OPTION_RESOLVE_TIMEOUT = 2;

        public const uint WINHTTP_OPTION_CONNECT_TIMEOUT = 3;

        public const uint WINHTTP_OPTION_CONNECT_RETRIES = 4;

        public const uint WINHTTP_OPTION_SEND_TIMEOUT = 5;

        public const uint WINHTTP_OPTION_RECEIVE_TIMEOUT = 6;

        public const uint WINHTTP_OPTION_RECEIVE_RESPONSE_TIMEOUT = 7;

        public const uint WINHTTP_OPTION_HANDLE_TYPE = 9;

        public const uint WINHTTP_OPTION_READ_BUFFER_SIZE = 12;

        public const uint WINHTTP_OPTION_WRITE_BUFFER_SIZE = 13;

        public const uint WINHTTP_OPTION_PARENT_HANDLE = 21;

        public const uint WINHTTP_OPTION_EXTENDED_ERROR = 24;

        public const uint WINHTTP_OPTION_SECURITY_FLAGS = 31;

        public const uint WINHTTP_OPTION_SECURITY_CERTIFICATE_STRUCT = 32;

        public const uint WINHTTP_OPTION_URL = 34;

        public const uint WINHTTP_OPTION_SECURITY_KEY_BITNESS = 36;

        public const uint WINHTTP_OPTION_PROXY = 38;

        public const uint WINHTTP_OPTION_PROXY_RESULT_ENTRY = 39;

        public const uint WINHTTP_OPTION_USER_AGENT = 41;

        public const uint WINHTTP_OPTION_CONTEXT_VALUE = 45;

        public const uint WINHTTP_OPTION_CLIENT_CERT_CONTEXT = 47;

        public const uint WINHTTP_OPTION_REQUEST_PRIORITY = 58;

        public const uint WINHTTP_OPTION_HTTP_VERSION = 59;

        public const uint WINHTTP_OPTION_DISABLE_FEATURE = 63;

        public const uint WINHTTP_OPTION_CODEPAGE = 68;

        public const uint WINHTTP_OPTION_MAX_CONNS_PER_SERVER = 73;

        public const uint WINHTTP_OPTION_MAX_CONNS_PER_1_0_SERVER = 74;

        public const uint WINHTTP_OPTION_AUTOLOGON_POLICY = 77;

        public const uint WINHTTP_OPTION_SERVER_CERT_CONTEXT = 78;

        public const uint WINHTTP_OPTION_ENABLE_FEATURE = 79;

        public const uint WINHTTP_OPTION_WORKER_THREAD_COUNT = 80;

        public const uint WINHTTP_OPTION_PASSPORT_COBRANDING_TEXT = 81;

        public const uint WINHTTP_OPTION_PASSPORT_COBRANDING_URL = 82;

        public const uint WINHTTP_OPTION_CONFIGURE_PASSPORT_AUTH = 83;

        public const uint WINHTTP_OPTION_SECURE_PROTOCOLS = 84;

        public const uint WINHTTP_OPTION_ENABLETRACING = 85;

        public const uint WINHTTP_OPTION_PASSPORT_SIGN_OUT = 86;

        public const uint WINHTTP_OPTION_PASSPORT_RETURN_URL = 87;

        public const uint WINHTTP_OPTION_REDIRECT_POLICY = 88;

        public const uint WINHTTP_OPTION_MAX_HTTP_AUTOMATIC_REDIRECTS = 89;

        public const uint WINHTTP_OPTION_MAX_HTTP_STATUS_CONTINUE = 90;

        public const uint WINHTTP_OPTION_MAX_RESPONSE_HEADER_SIZE = 91;

        public const uint WINHTTP_OPTION_MAX_RESPONSE_DRAIN_SIZE = 92;

        public const uint WINHTTP_OPTION_CONNECTION_INFO = 93;

        public const uint WINHTTP_OPTION_CLIENT_CERT_ISSUER_LIST = 94;

        public const uint WINHTTP_OPTION_SPN = 96;

        public const uint WINHTTP_OPTION_GLOBAL_PROXY_CREDS = 97;

        public const uint WINHTTP_OPTION_GLOBAL_SERVER_CREDS = 98;

        public const uint WINHTTP_OPTION_UNLOAD_NOTIFY_EVENT = 99;

        public const uint WINHTTP_OPTION_REJECT_USERPWD_IN_URL = 100;

        public const uint WINHTTP_OPTION_USE_GLOBAL_SERVER_CREDENTIALS = 101;

        public const uint WINHTTP_OPTION_RECEIVE_PROXY_CONNECT_RESPONSE = 103;

        public const uint WINHTTP_OPTION_IS_PROXY_CONNECT_RESPONSE = 104;

        public const uint WINHTTP_OPTION_SERVER_SPN_USED = 106;

        public const uint WINHTTP_OPTION_PROXY_SPN_USED = 107;

        public const uint WINHTTP_OPTION_SERVER_CBT = 108;

        public const uint WINHTTP_OPTION_UNSAFE_HEADER_PARSING = 110;

        public const uint WINHTTP_OPTION_ASSURED_NON_BLOCKING_CALLBACKS = 111;

        public const uint WINHTTP_OPTION_UPGRADE_TO_WEB_SOCKET = 114;

        public const uint WINHTTP_OPTION_WEB_SOCKET_CLOSE_TIMEOUT = 115;

        public const uint WINHTTP_OPTION_WEB_SOCKET_KEEPALIVE_INTERVAL = 116;

        public const uint WINHTTP_OPTION_DECOMPRESSION = 118;

        public const uint WINHTTP_OPTION_WEB_SOCKET_RECEIVE_BUFFER_SIZE = 122;

        public const uint WINHTTP_OPTION_WEB_SOCKET_SEND_BUFFER_SIZE = 123;

        public const uint WINHTTP_OPTION_TCP_PRIORITY_HINT = 128;

        public const uint WINHTTP_OPTION_CONNECTION_FILTER = 131;

        public const uint WINHTTP_OPTION_ENABLE_HTTP_PROTOCOL = 133;

        public const uint WINHTTP_OPTION_HTTP_PROTOCOL_USED = 134;

        public const uint WINHTTP_OPTION_KDC_PROXY_SETTINGS = 136;

        public const uint WINHTTP_OPTION_ENCODE_EXTRA = 138;

        public const uint WINHTTP_OPTION_DISABLE_STREAM_QUEUE = 139;

        public const uint WINHTTP_OPTION_IPV6_FAST_FALLBACK = 140;

        public const uint WINHTTP_OPTION_CONNECTION_STATS_V0 = 141;

        public const uint WINHTTP_OPTION_REQUEST_TIMES = 142;

        public const uint WINHTTP_OPTION_EXPIRE_CONNECTION = 143;

        public const uint WINHTTP_OPTION_DISABLE_SECURE_PROTOCOL_FALLBACK = 144;

        public const uint WINHTTP_OPTION_HTTP_PROTOCOL_REQUIRED = 145;

        public const uint WINHTTP_OPTION_REQUEST_STATS = 146;

        public const uint WINHTTP_OPTION_SERVER_CERT_CHAIN_CONTEXT = 147;

        public const uint WINHTTP_OPTION_CONNECTION_STATS_V1 = 150;

        public const uint WINHTTP_OPTION_SECURITY_INFO = 151;

        public const uint WINHTTP_OPTION_TCP_KEEPALIVE = 152;

        public const uint WINHTTP_OPTION_TCP_FAST_OPEN = 153;

        public const uint WINHTTP_OPTION_TLS_FALSE_START = 154;

        public const uint WINHTTP_OPTION_IGNORE_CERT_REVOCATION_OFFLINE = 155;

        public const uint WINHTTP_OPTION_SOURCE_ADDRESS = 156;

        public const uint WINHTTP_OPTION_USERNAME = 0x1000;

        public const uint WINHTTP_OPTION_PASSWORD = 0x1001;

        public const uint WINHTTP_OPTION_PROXY_USERNAME = 0x1002;

        public const uint WINHTTP_OPTION_PROXY_PASSWORD = 0x1003;

        public const uint WINHTTP_CONNS_PER_SERVER_UNLIMITED = 0xFFFFFFFF;

        public const uint WINHTTP_DECOMPRESSION_FLAG_GZIP = 0x00000001;

        public const uint WINHTTP_DECOMPRESSION_FLAG_DEFLATE = 0x00000002;

        public const uint WINHTTP_PROTOCOL_FLAG_HTTP2 = 0x1;

        public const uint WINHTTP_AUTOLOGON_SECURITY_LEVEL_MEDIUM = 0;

        public const uint WINHTTP_AUTOLOGON_SECURITY_LEVEL_LOW = 1;

        public const uint WINHTTP_AUTOLOGON_SECURITY_LEVEL_HIGH = 2;

        public const uint WINHTTP_OPTION_REDIRECT_POLICY_NEVER = 0;

        public const uint WINHTTP_OPTION_REDIRECT_POLICY_DISALLOW_HTTPS_TO_HTTP = 1;

        public const uint WINHTTP_OPTION_REDIRECT_POLICY_ALWAYS = 2;

        public const uint WINHTTP_DISABLE_PASSPORT_AUTH = 0x00000000;

        public const uint WINHTTP_ENABLE_PASSPORT_AUTH = 0x10000000;

        public const uint WINHTTP_DISABLE_PASSPORT_KEYRING = 0x20000000;

        public const uint WINHTTP_ENABLE_PASSPORT_KEYRING = 0x40000000;

        public const uint WINHTTP_DISABLE_COOKIES = 0x00000001;

        public const uint WINHTTP_DISABLE_REDIRECTS = 0x00000002;

        public const uint WINHTTP_DISABLE_AUTHENTICATION = 0x00000004;

        public const uint WINHTTP_DISABLE_KEEP_ALIVE = 0x00000008;

        public const uint WINHTTP_ENABLE_SSL_REVOCATION = 0x00000001;

        public const uint WINHTTP_ENABLE_SSL_REVERT_IMPERSONATION = 0x00000002;

        public const uint WINHTTP_DISABLE_SPN_SERVER_PORT = 0x00000000;

        public const uint WINHTTP_ENABLE_SPN_SERVER_PORT = 0x00000001;

        public const uint WINHTTP_HANDLE_TYPE_SESSION = 1;

        public const uint WINHTTP_HANDLE_TYPE_CONNECT = 2;

        public const uint WINHTTP_HANDLE_TYPE_REQUEST = 3;

        public const uint WINHTTP_AUTH_SCHEME_PASSPORT = 0x00000004;

        public const uint WINHTTP_AUTH_SCHEME_DIGEST = 0x00000008;

        public const uint WINHTTP_AUTH_TARGET_SERVER = 0x00000000;

        public const uint WINHTTP_AUTH_TARGET_PROXY = 0x00000001;

        public const uint SECURITY_FLAG_SECURE = 0x00000001;

        public const uint SECURITY_FLAG_STRENGTH_WEAK = 0x10000000;

        public const uint SECURITY_FLAG_STRENGTH_MEDIUM = 0x40000000;

        public const uint SECURITY_FLAG_STRENGTH_STRONG = 0x20000000;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_CERT_REV_FAILED = 0x00000001;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CERT = 0x00000002;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_CERT_REVOKED = 0x00000004;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_INVALID_CA = 0x00000008;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_CERT_CN_INVALID = 0x00000010;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_CERT_DATE_INVALID = 0x00000020;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_CERT_WRONG_USAGE = 0x00000040;

        public const uint WINHTTP_CALLBACK_STATUS_FLAG_SECURITY_CHANNEL_ERROR = 0x80000000;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_SSL2 = 0x00000008;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_SSL3 = 0x00000020;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_TLS1 = 0x00000080;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_1 = 0x00000200;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_2 = 0x00000800;

        public const uint WINHTTP_FLAG_SECURE_PROTOCOL_TLS1_3 = 0x00002000;

        public const uint WINHTTP_CALLBACK_STATUS_RESOLVING_NAME = 0x00000001;

        public const uint WINHTTP_CALLBACK_STATUS_NAME_RESOLVED = 0x00000002;

        public const uint WINHTTP_CALLBACK_STATUS_CONNECTING_TO_SERVER = 0x00000004;

        public const uint WINHTTP_CALLBACK_STATUS_CONNECTED_TO_SERVER = 0x00000008;

        public const uint WINHTTP_CALLBACK_STATUS_SENDING_REQUEST = 0x00000010;

        public const uint WINHTTP_CALLBACK_STATUS_REQUEST_SENT = 0x00000020;

        public const uint WINHTTP_CALLBACK_STATUS_RECEIVING_RESPONSE = 0x00000040;

        public const uint WINHTTP_CALLBACK_STATUS_RESPONSE_RECEIVED = 0x00000080;

        public const uint WINHTTP_CALLBACK_STATUS_CLOSING_CONNECTION = 0x00000100;

        public const uint WINHTTP_CALLBACK_STATUS_CONNECTION_CLOSED = 0x00000200;

        public const uint WINHTTP_CALLBACK_STATUS_HANDLE_CREATED = 0x00000400;

        public const uint WINHTTP_CALLBACK_STATUS_HANDLE_CLOSING = 0x00000800;

        public const uint WINHTTP_CALLBACK_STATUS_DETECTING_PROXY = 0x00001000;

        public const uint WINHTTP_CALLBACK_STATUS_REDIRECT = 0x00004000;

        public const uint WINHTTP_CALLBACK_STATUS_INTERMEDIATE_RESPONSE = 0x00008000;

        public const uint WINHTTP_CALLBACK_STATUS_SECURE_FAILURE = 0x00010000;

        public const uint WINHTTP_CALLBACK_STATUS_HEADERS_AVAILABLE = 0x00020000;

        public const uint WINHTTP_CALLBACK_STATUS_DATA_AVAILABLE = 0x00040000;

        public const uint WINHTTP_CALLBACK_STATUS_READ_COMPLETE = 0x00080000;

        public const uint WINHTTP_CALLBACK_STATUS_WRITE_COMPLETE = 0x00100000;

        public const uint WINHTTP_CALLBACK_STATUS_REQUEST_ERROR = 0x00200000;

        public const uint WINHTTP_CALLBACK_STATUS_SENDREQUEST_COMPLETE = 0x00400000;

        public const uint WINHTTP_CALLBACK_STATUS_GETPROXYFORURL_COMPLETE = 0x01000000;

        public const uint WINHTTP_CALLBACK_STATUS_CLOSE_COMPLETE = 0x02000000;

        public const uint WINHTTP_CALLBACK_STATUS_SHUTDOWN_COMPLETE = 0x04000000;

        public const uint WINHTTP_CALLBACK_STATUS_SETTINGS_WRITE_COMPLETE = 0x10000000;

        public const uint WINHTTP_CALLBACK_STATUS_SETTINGS_READ_COMPLETE = 0x20000000;

        public const uint API_RECEIVE_RESPONSE = 1;

        public const uint API_QUERY_DATA_AVAILABLE = 2;

        public const uint API_READ_DATA = 3;

        public const uint API_WRITE_DATA = 4;

        public const uint API_SEND_REQUEST = 5;

        public const uint API_GET_PROXY_FOR_URL = 6;

        public const uint WINHTTP_CALLBACK_FLAG_ALL_NOTIFICATIONS = 0xffffffff;

        public const uint WINHTTP_QUERY_MIME_VERSION = 0;

        public const uint WINHTTP_QUERY_CONTENT_TYPE = 1;

        public const uint WINHTTP_QUERY_CONTENT_TRANSFER_ENCODING = 2;

        public const uint WINHTTP_QUERY_CONTENT_ID = 3;

        public const uint WINHTTP_QUERY_CONTENT_DESCRIPTION = 4;

        public const uint WINHTTP_QUERY_CONTENT_LENGTH = 5;

        public const uint WINHTTP_QUERY_CONTENT_LANGUAGE = 6;

        public const uint WINHTTP_QUERY_ALLOW = 7;

        public const uint WINHTTP_QUERY_PUBLIC = 8;

        public const uint WINHTTP_QUERY_DATE = 9;

        public const uint WINHTTP_QUERY_EXPIRES = 10;

        public const uint WINHTTP_QUERY_LAST_MODIFIED = 11;

        public const uint WINHTTP_QUERY_MESSAGE_ID = 12;

        public const uint WINHTTP_QUERY_URI = 13;

        public const uint WINHTTP_QUERY_DERIVED_FROM = 14;

        public const uint WINHTTP_QUERY_COST = 15;

        public const uint WINHTTP_QUERY_LINK = 16;

        public const uint WINHTTP_QUERY_PRAGMA = 17;

        public const uint WINHTTP_QUERY_VERSION = 18;

        public const uint WINHTTP_QUERY_STATUS_CODE = 19;

        public const uint WINHTTP_QUERY_STATUS_TEXT = 20;

        public const uint WINHTTP_QUERY_RAW_HEADERS = 21;

        public const uint WINHTTP_QUERY_RAW_HEADERS_CRLF = 22;

        public const uint WINHTTP_QUERY_CONNECTION = 23;

        public const uint WINHTTP_QUERY_ACCEPT = 24;

        public const uint WINHTTP_QUERY_ACCEPT_CHARSET = 25;

        public const uint WINHTTP_QUERY_ACCEPT_ENCODING = 26;

        public const uint WINHTTP_QUERY_ACCEPT_LANGUAGE = 27;

        public const uint WINHTTP_QUERY_AUTHORIZATION = 28;

        public const uint WINHTTP_QUERY_CONTENT_ENCODING = 29;

        public const uint WINHTTP_QUERY_FORWARDED = 30;

        public const uint WINHTTP_QUERY_FROM = 31;

        public const uint WINHTTP_QUERY_IF_MODIFIED_SINCE = 32;

        public const uint WINHTTP_QUERY_LOCATION = 33;

        public const uint WINHTTP_QUERY_ORIG_URI = 34;

        public const uint WINHTTP_QUERY_REFERER = 35;

        public const uint WINHTTP_QUERY_RETRY_AFTER = 36;

        public const uint WINHTTP_QUERY_SERVER = 37;

        public const uint WINHTTP_QUERY_TITLE = 38;

        public const uint WINHTTP_QUERY_USER_AGENT = 39;

        public const uint WINHTTP_QUERY_WWW_AUTHENTICATE = 40;

        public const uint WINHTTP_QUERY_PROXY_AUTHENTICATE = 41;

        public const uint WINHTTP_QUERY_ACCEPT_RANGES = 42;

        public const uint WINHTTP_QUERY_SET_COOKIE = 43;

        public const uint WINHTTP_QUERY_COOKIE = 44;

        public const uint WINHTTP_QUERY_REQUEST_METHOD = 45;

        public const uint WINHTTP_QUERY_REFRESH = 46;

        public const uint WINHTTP_QUERY_CONTENT_DISPOSITION = 47;

        public const uint WINHTTP_QUERY_AGE = 48;

        public const uint WINHTTP_QUERY_CACHE_CONTROL = 49;

        public const uint WINHTTP_QUERY_CONTENT_BASE = 50;

        public const uint WINHTTP_QUERY_CONTENT_LOCATION = 51;

        public const uint WINHTTP_QUERY_CONTENT_MD5 = 52;

        public const uint WINHTTP_QUERY_CONTENT_RANGE = 53;

        public const uint WINHTTP_QUERY_ETAG = 54;

        public const uint WINHTTP_QUERY_HOST = 55;

        public const uint WINHTTP_QUERY_IF_MATCH = 56;

        public const uint WINHTTP_QUERY_IF_NONE_MATCH = 57;

        public const uint WINHTTP_QUERY_IF_RANGE = 58;

        public const uint WINHTTP_QUERY_IF_UNMODIFIED_SINCE = 59;

        public const uint WINHTTP_QUERY_MAX_FORWARDS = 60;

        public const uint WINHTTP_QUERY_PROXY_AUTHORIZATION = 61;

        public const uint WINHTTP_QUERY_RANGE = 62;

        public const uint WINHTTP_QUERY_TRANSFER_ENCODING = 63;

        public const uint WINHTTP_QUERY_UPGRADE = 64;

        public const uint WINHTTP_QUERY_VARY = 65;

        public const uint WINHTTP_QUERY_VIA = 66;

        public const uint WINHTTP_QUERY_WARNING = 67;

        public const uint WINHTTP_QUERY_EXPECT = 68;

        public const uint WINHTTP_QUERY_PROXY_CONNECTION = 69;

        public const uint WINHTTP_QUERY_UNLESS_MODIFIED_SINCE = 70;

        public const uint WINHTTP_QUERY_PROXY_SUPPORT = 75;

        public const uint WINHTTP_QUERY_AUTHENTICATION_INFO = 76;

        public const uint WINHTTP_QUERY_PASSPORT_URLS = 77;

        public const uint WINHTTP_QUERY_PASSPORT_CONFIG = 78;

        public const uint WINHTTP_QUERY_MAX = 78;

        public const uint WINHTTP_QUERY_CUSTOM = 65535;

        public const uint WINHTTP_QUERY_FLAG_REQUEST_HEADERS = 0x80000000;

        public const uint WINHTTP_QUERY_FLAG_SYSTEMTIME = 0x40000000;

        public const uint WINHTTP_QUERY_FLAG_NUMBER = 0x20000000;

        public const uint WINHTTP_QUERY_FLAG_NUMBER64 = 0x08000000;

        public const uint HTTP_STATUS_CONTINUE = 100;

        public const uint HTTP_STATUS_SWITCH_PROTOCOLS = 101;

        public const uint HTTP_STATUS_OK = 200;

        public const uint HTTP_STATUS_CREATED = 201;

        public const uint HTTP_STATUS_ACCEPTED = 202;

        public const uint HTTP_STATUS_PARTIAL = 203;

        public const uint HTTP_STATUS_NO_CONTENT = 204;

        public const uint HTTP_STATUS_RESET_CONTENT = 205;

        public const uint HTTP_STATUS_PARTIAL_CONTENT = 206;

        public const uint HTTP_STATUS_WEBDAV_MULTI_STATUS = 207;

        public const uint HTTP_STATUS_AMBIGUOUS = 300;

        public const uint HTTP_STATUS_MOVED = 301;

        public const uint HTTP_STATUS_REDIRECT = 302;

        public const uint HTTP_STATUS_REDIRECT_METHOD = 303;

        public const uint HTTP_STATUS_NOT_MODIFIED = 304;

        public const uint HTTP_STATUS_USE_PROXY = 305;

        public const uint HTTP_STATUS_REDIRECT_KEEP_VERB = 307;

        public const uint HTTP_STATUS_PERMANENT_REDIRECT = 308;

        public const uint HTTP_STATUS_BAD_REQUEST = 400;

        public const uint HTTP_STATUS_DENIED = 401;

        public const uint HTTP_STATUS_PAYMENT_REQ = 402;

        public const uint HTTP_STATUS_FORBIDDEN = 403;

        public const uint HTTP_STATUS_NOT_FOUND = 404;

        public const uint HTTP_STATUS_BAD_METHOD = 405;

        public const uint HTTP_STATUS_NONE_ACCEPTABLE = 406;

        public const uint HTTP_STATUS_PROXY_AUTH_REQ = 407;

        public const uint HTTP_STATUS_REQUEST_TIMEOUT = 408;

        public const uint HTTP_STATUS_CONFLICT = 409;

        public const uint HTTP_STATUS_GONE = 410;

        public const uint HTTP_STATUS_LENGTH_REQUIRED = 411;

        public const uint HTTP_STATUS_PRECOND_FAILED = 412;

        public const uint HTTP_STATUS_REQUEST_TOO_LARGE = 413;

        public const uint HTTP_STATUS_URI_TOO_LONG = 414;

        public const uint HTTP_STATUS_UNSUPPORTED_MEDIA = 415;

        public const uint HTTP_STATUS_RETRY_WITH = 449;

        public const uint HTTP_STATUS_SERVER_ERROR = 500;

        public const uint HTTP_STATUS_NOT_SUPPORTED = 501;

        public const uint HTTP_STATUS_BAD_GATEWAY = 502;

        public const uint HTTP_STATUS_SERVICE_UNAVAIL = 503;

        public const uint HTTP_STATUS_GATEWAY_TIMEOUT = 504;

        public const uint HTTP_STATUS_VERSION_NOT_SUP = 505;

        public const uint ICU_NO_ENCODE = 0x20000000;

        public const uint ICU_NO_META = 0x08000000;

        public const uint ICU_ENCODE_SPACES_ONLY = 0x04000000;

        public const uint ICU_BROWSER_MODE = 0x02000000;

        public const uint ICU_ENCODE_PERCENT = 0x00001000;

        public const uint ICU_ESCAPE_AUTHORITY = 0x00002000;

        public const uint WINHTTP_ADDREQ_INDEX_MASK = 0x0000FFFF;

        public const uint WINHTTP_ADDREQ_FLAGS_MASK = 0xFFFF0000;

        public const uint WINHTTP_ADDREQ_FLAG_ADD_IF_NEW = 0x10000000;

        public const uint WINHTTP_ADDREQ_FLAG_ADD = 0x20000000;

        public const uint WINHTTP_ADDREQ_FLAG_COALESCE_WITH_COMMA = 0x40000000;

        public const uint WINHTTP_ADDREQ_FLAG_COALESCE_WITH_SEMICOLON = 0x01000000;

        public const uint WINHTTP_ADDREQ_FLAG_REPLACE = 0x80000000;

        public const uint WINHTTP_EXTENDED_HEADER_FLAG_UNICODE = 0x00000001;

        public const uint WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH = 0;

        public const uint WINHTTP_ERROR_BASE = 12000;

        public const uint ERROR_WINHTTP_OUT_OF_HANDLES = WINHTTP_ERROR_BASE + 1;

        public const uint ERROR_WINHTTP_TIMEOUT = WINHTTP_ERROR_BASE + 2;

        public const uint ERROR_WINHTTP_INTERNAL_ERROR = WINHTTP_ERROR_BASE + 4;

        public const uint ERROR_WINHTTP_INVALID_URL = WINHTTP_ERROR_BASE + 5;

        public const uint ERROR_WINHTTP_UNRECOGNIZED_SCHEME = WINHTTP_ERROR_BASE + 6;

        public const uint ERROR_WINHTTP_NAME_NOT_RESOLVED = WINHTTP_ERROR_BASE + 7;

        public const uint ERROR_WINHTTP_INVALID_OPTION = WINHTTP_ERROR_BASE + 9;

        public const uint ERROR_WINHTTP_OPTION_NOT_SETTABLE = WINHTTP_ERROR_BASE + 11;

        public const uint ERROR_WINHTTP_SHUTDOWN = WINHTTP_ERROR_BASE + 12;

        public const uint ERROR_WINHTTP_LOGIN_FAILURE = WINHTTP_ERROR_BASE + 15;

        public const uint ERROR_WINHTTP_OPERATION_CANCELLED = WINHTTP_ERROR_BASE + 17;

        public const uint ERROR_WINHTTP_INCORRECT_HANDLE_TYPE = WINHTTP_ERROR_BASE + 18;

        public const uint ERROR_WINHTTP_INCORRECT_HANDLE_STATE = WINHTTP_ERROR_BASE + 19;

        public const uint ERROR_WINHTTP_CANNOT_CONNECT = WINHTTP_ERROR_BASE + 29;

        public const uint ERROR_WINHTTP_CONNECTION_ERROR = WINHTTP_ERROR_BASE + 30;

        public const uint ERROR_WINHTTP_RESEND_REQUEST = WINHTTP_ERROR_BASE + 32;

        public const uint ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED = WINHTTP_ERROR_BASE + 44;

        public const uint ERROR_WINHTTP_CANNOT_CALL_BEFORE_OPEN = WINHTTP_ERROR_BASE + 100;

        public const uint ERROR_WINHTTP_CANNOT_CALL_BEFORE_SEND = WINHTTP_ERROR_BASE + 101;

        public const uint ERROR_WINHTTP_CANNOT_CALL_AFTER_SEND = WINHTTP_ERROR_BASE + 102;

        public const uint ERROR_WINHTTP_CANNOT_CALL_AFTER_OPEN = WINHTTP_ERROR_BASE + 103;

        public const uint ERROR_WINHTTP_HEADER_NOT_FOUND = WINHTTP_ERROR_BASE + 150;

        public const uint ERROR_WINHTTP_INVALID_SERVER_RESPONSE = WINHTTP_ERROR_BASE + 152;

        public const uint ERROR_WINHTTP_INVALID_HEADER = WINHTTP_ERROR_BASE + 153;

        public const uint ERROR_WINHTTP_INVALID_QUERY_REQUEST = WINHTTP_ERROR_BASE + 154;

        public const uint ERROR_WINHTTP_HEADER_ALREADY_EXISTS = WINHTTP_ERROR_BASE + 155;

        public const uint ERROR_WINHTTP_REDIRECT_FAILED = WINHTTP_ERROR_BASE + 156;

        public const uint ERROR_WINHTTP_AUTO_PROXY_SERVICE_ERROR = WINHTTP_ERROR_BASE + 178;

        public const uint ERROR_WINHTTP_BAD_AUTO_PROXY_SCRIPT = WINHTTP_ERROR_BASE + 166;

        public const uint ERROR_WINHTTP_UNABLE_TO_DOWNLOAD_SCRIPT = WINHTTP_ERROR_BASE + 167;

        public const uint ERROR_WINHTTP_UNHANDLED_SCRIPT_TYPE = WINHTTP_ERROR_BASE + 176;

        public const uint ERROR_WINHTTP_SCRIPT_EXECUTION_ERROR = WINHTTP_ERROR_BASE + 177;

        public const uint ERROR_WINHTTP_NOT_INITIALIZED = WINHTTP_ERROR_BASE + 172;

        public const uint ERROR_WINHTTP_SECURE_FAILURE = WINHTTP_ERROR_BASE + 175;

        public const uint ERROR_WINHTTP_SECURE_CERT_DATE_INVALID = WINHTTP_ERROR_BASE + 37;

        public const uint ERROR_WINHTTP_SECURE_CERT_CN_INVALID = WINHTTP_ERROR_BASE + 38;

        public const uint ERROR_WINHTTP_SECURE_INVALID_CA = WINHTTP_ERROR_BASE + 45;

        public const uint ERROR_WINHTTP_SECURE_CERT_REV_FAILED = WINHTTP_ERROR_BASE + 57;

        public const uint ERROR_WINHTTP_SECURE_CHANNEL_ERROR = WINHTTP_ERROR_BASE + 157;

        public const uint ERROR_WINHTTP_SECURE_INVALID_CERT = WINHTTP_ERROR_BASE + 169;

        public const uint ERROR_WINHTTP_SECURE_CERT_REVOKED = WINHTTP_ERROR_BASE + 170;

        public const uint ERROR_WINHTTP_SECURE_CERT_WRONG_USAGE = WINHTTP_ERROR_BASE + 179;

        public const uint ERROR_WINHTTP_AUTODETECTION_FAILED = WINHTTP_ERROR_BASE + 180;

        public const uint ERROR_WINHTTP_HEADER_COUNT_EXCEEDED = WINHTTP_ERROR_BASE + 181;

        public const uint ERROR_WINHTTP_HEADER_SIZE_OVERFLOW = WINHTTP_ERROR_BASE + 182;

        public const uint ERROR_WINHTTP_CHUNKED_ENCODING_HEADER_SIZE_OVERFLOW = WINHTTP_ERROR_BASE + 183;

        public const uint ERROR_WINHTTP_RESPONSE_DRAIN_OVERFLOW = WINHTTP_ERROR_BASE + 184;

        public const uint ERROR_WINHTTP_CLIENT_CERT_NO_PRIVATE_KEY = WINHTTP_ERROR_BASE + 185;

        public const uint ERROR_WINHTTP_CLIENT_CERT_NO_ACCESS_PRIVATE_KEY = WINHTTP_ERROR_BASE + 186;

        public const uint ERROR_WINHTTP_CLIENT_AUTH_CERT_NEEDED_PROXY = WINHTTP_ERROR_BASE + 187;

        public const uint ERROR_WINHTTP_SECURE_FAILURE_PROXY = WINHTTP_ERROR_BASE + 188;

        public const uint ERROR_WINHTTP_RESERVED_189 = WINHTTP_ERROR_BASE + 189;

        public const uint ERROR_WINHTTP_HTTP_PROTOCOL_MISMATCH = WINHTTP_ERROR_BASE + 190;

        public const uint WINHTTP_ERROR_LAST = WINHTTP_ERROR_BASE + 188;

        public const uint WINHTTP_RESET_STATE = 0x00000001;

        public const uint WINHTTP_RESET_SWPAD_CURRENT_NETWORK = 0x00000002;

        public const uint WINHTTP_RESET_SWPAD_ALL = 0x00000004;

        public const uint WINHTTP_RESET_SCRIPT_CACHE = 0x00000008;

        public const uint WINHTTP_RESET_ALL = 0x0000FFFF;

        public const uint WINHTTP_RESET_NOTIFY_NETWORK_CHANGED = 0x00010000;

        public const uint WINHTTP_RESET_OUT_OF_PROC = 0x00020000;

        public const uint WINHTTP_RESET_DISCARD_RESOLVERS = 0x00040000;

        public const uint WINHTTP_WEB_SOCKET_MAX_CLOSE_REASON_LENGTH = 123;

        public const uint WINHTTP_WEB_SOCKET_MIN_KEEPALIVE_VALUE = 15000;

    }
}
