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


namespace Windows.Win32.Networking.HttpServer
{
    public static partial class Apis
    {
        public const uint HTTP_DEMAND_CBT = 0x00000004;

        public const uint HTTP_MAX_SERVER_QUEUE_LENGTH = 0x7FFFFFFF;

        public const uint HTTP_MIN_SERVER_QUEUE_LENGTH = 1;

        public const uint HTTP_AUTH_ENABLE_BASIC = 0x00000001;

        public const uint HTTP_AUTH_ENABLE_DIGEST = 0x00000002;

        public const uint HTTP_AUTH_ENABLE_NTLM = 0x00000004;

        public const uint HTTP_AUTH_ENABLE_NEGOTIATE = 0x00000008;

        public const uint HTTP_AUTH_ENABLE_KERBEROS = 0x00000010;

        public const uint HTTP_AUTH_EX_FLAG_ENABLE_KERBEROS_CREDENTIAL_CACHING = 0x01;

        public const uint HTTP_AUTH_EX_FLAG_CAPTURE_CREDENTIAL = 0x02;

        public const uint HTTP_CHANNEL_BIND_PROXY = 0x1;

        public const uint HTTP_CHANNEL_BIND_PROXY_COHOSTING = 0x20;

        public const uint HTTP_CHANNEL_BIND_NO_SERVICE_NAME_CHECK = 0x2;

        public const uint HTTP_CHANNEL_BIND_DOTLESS_SERVICE = 0x4;

        public const uint HTTP_CHANNEL_BIND_SECURE_CHANNEL_TOKEN = 0x8;

        public const uint HTTP_CHANNEL_BIND_CLIENT_SERVICE = 0x10;

        public const uint HTTP_LOG_FIELD_DATE = 0x00000001;

        public const uint HTTP_LOG_FIELD_TIME = 0x00000002;

        public const uint HTTP_LOG_FIELD_CLIENT_IP = 0x00000004;

        public const uint HTTP_LOG_FIELD_USER_NAME = 0x00000008;

        public const uint HTTP_LOG_FIELD_SITE_NAME = 0x00000010;

        public const uint HTTP_LOG_FIELD_COMPUTER_NAME = 0x00000020;

        public const uint HTTP_LOG_FIELD_SERVER_IP = 0x00000040;

        public const uint HTTP_LOG_FIELD_METHOD = 0x00000080;

        public const uint HTTP_LOG_FIELD_URI_STEM = 0x00000100;

        public const uint HTTP_LOG_FIELD_URI_QUERY = 0x00000200;

        public const uint HTTP_LOG_FIELD_STATUS = 0x00000400;

        public const uint HTTP_LOG_FIELD_WIN32_STATUS = 0x00000800;

        public const uint HTTP_LOG_FIELD_BYTES_SENT = 0x00001000;

        public const uint HTTP_LOG_FIELD_BYTES_RECV = 0x00002000;

        public const uint HTTP_LOG_FIELD_TIME_TAKEN = 0x00004000;

        public const uint HTTP_LOG_FIELD_SERVER_PORT = 0x00008000;

        public const uint HTTP_LOG_FIELD_USER_AGENT = 0x00010000;

        public const uint HTTP_LOG_FIELD_COOKIE = 0x00020000;

        public const uint HTTP_LOG_FIELD_REFERER = 0x00040000;

        public const uint HTTP_LOG_FIELD_VERSION = 0x00080000;

        public const uint HTTP_LOG_FIELD_HOST = 0x00100000;

        public const uint HTTP_LOG_FIELD_SUB_STATUS = 0x00200000;

        public const uint HTTP_LOG_FIELD_STREAM_ID = 0x08000000;

        public const uint HTTP_LOG_FIELD_STREAM_ID_EX = 0x10000000;

        public const uint HTTP_LOG_FIELD_TRANSPORT_TYPE = 0x20000000;

        public const uint HTTP_LOG_FIELD_CLIENT_PORT = 0x00400000;

        public const uint HTTP_LOG_FIELD_URI = 0x00800000;

        public const uint HTTP_LOG_FIELD_SITE_ID = 0x01000000;

        public const uint HTTP_LOG_FIELD_REASON = 0x02000000;

        public const uint HTTP_LOG_FIELD_QUEUE_NAME = 0x04000000;

        public const uint HTTP_LOGGING_FLAG_LOCAL_TIME_ROLLOVER = 0x00000001;

        public const uint HTTP_LOGGING_FLAG_USE_UTF8_CONVERSION = 0x00000002;

        public const uint HTTP_LOGGING_FLAG_LOG_ERRORS_ONLY = 0x00000004;

        public const uint HTTP_LOGGING_FLAG_LOG_SUCCESS_ONLY = 0x00000008;

        public const uint HTTP_CREATE_REQUEST_QUEUE_FLAG_OPEN_EXISTING = 0x00000001;

        public const uint HTTP_CREATE_REQUEST_QUEUE_FLAG_CONTROLLER = 0x00000002;

        public const uint HTTP_RECEIVE_REQUEST_ENTITY_BODY_FLAG_FILL_BUFFER = 0x00000001;

        public const uint HTTP_SEND_RESPONSE_FLAG_DISCONNECT = 0x00000001;

        public const uint HTTP_SEND_RESPONSE_FLAG_MORE_DATA = 0x00000002;

        public const uint HTTP_SEND_RESPONSE_FLAG_BUFFER_DATA = 0x00000004;

        public const uint HTTP_SEND_RESPONSE_FLAG_ENABLE_NAGLING = 0x00000008;

        public const uint HTTP_SEND_RESPONSE_FLAG_PROCESS_RANGES = 0x00000020;

        public const uint HTTP_SEND_RESPONSE_FLAG_OPAQUE = 0x00000040;

        public const uint HTTP_SEND_RESPONSE_FLAG_GOAWAY = 0x00000100;

        public const uint HTTP_FLUSH_RESPONSE_FLAG_RECURSIVE = 0x00000001;

        public const uint HTTP_URL_FLAG_REMOVE_ALL = 0x00000001;

        public const uint HTTP_RECEIVE_SECURE_CHANNEL_TOKEN = 0x1;

        public const uint HTTP_REQUEST_SIZING_INFO_FLAG_TCP_FAST_OPEN = 0x00000001;

        public const uint HTTP_REQUEST_SIZING_INFO_FLAG_TLS_SESSION_RESUMPTION = 0x00000002;

        public const uint HTTP_REQUEST_SIZING_INFO_FLAG_TLS_FALSE_START = 0x00000004;

        public const uint HTTP_REQUEST_SIZING_INFO_FLAG_FIRST_REQUEST = 0x00000008;

        public const uint HTTP_REQUEST_AUTH_FLAG_TOKEN_FOR_CACHED_CRED = 0x00000001;

        public const uint HTTP_REQUEST_FLAG_MORE_ENTITY_BODY_EXISTS = 0x00000001;

        public const uint HTTP_REQUEST_FLAG_IP_ROUTED = 0x00000002;

        public const uint HTTP_REQUEST_FLAG_HTTP2 = 0x00000004;

        public const uint HTTP_RESPONSE_FLAG_MULTIPLE_ENCODINGS_AVAILABLE = 0x00000001;

        public const uint HTTP_RESPONSE_FLAG_MORE_ENTITY_BODY_EXISTS = 0x00000002;

        public const uint HTTP_RESPONSE_INFO_FLAGS_PRESERVE_ORDER = 0x00000001;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_USE_DS_MAPPER = 0x00000001;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_NEGOTIATE_CLIENT_CERT = 0x00000002;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_NO_RAW_FILTER = 0x00000004;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_REJECT = 0x00000008;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_HTTP2 = 0x00000010;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_QUIC = 0x00000020;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_TLS13 = 0x00000040;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_OCSP_STAPLING = 0x00000080;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_ENABLE_TOKEN_BINDING = 0x00000100;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_LOG_EXTENDED_EVENTS = 0x00000200;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_LEGACY_TLS = 0x00000400;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_ENABLE_SESSION_TICKET = 0x00000800;

        public const uint HTTP_SERVICE_CONFIG_SSL_FLAG_DISABLE_TLS12 = 0x00001000;

        public const uint HTTP_REQUEST_PROPERTY_SNI_HOST_MAX_LENGTH = 255;

        public const uint HTTP_REQUEST_PROPERTY_SNI_FLAG_SNI_USED = 0x00000001;

        public const uint HTTP_REQUEST_PROPERTY_SNI_FLAG_NO_SNI = 0x00000002;

    }
}
