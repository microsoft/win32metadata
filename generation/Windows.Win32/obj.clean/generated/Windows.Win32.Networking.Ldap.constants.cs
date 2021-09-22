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


namespace Windows.Win32.Networking.Ldap
{
    public static partial class Apis
    {
        public const int LBER_ERROR = unchecked((int)0xffffffff);

        public const int LBER_DEFAULT = unchecked((int)0xffffffff);

        public const uint LDAP_UNICODE = 1;

        public const uint LDAP_PORT = 389;

        public const uint LDAP_SSL_PORT = 636;

        public const uint LDAP_GC_PORT = 3268;

        public const uint LDAP_SSL_GC_PORT = 3269;

        public const uint LDAP_VERSION1 = 1;

        public const uint LDAP_VERSION2 = 2;

        public const uint LDAP_VERSION3 = 3;

        public const int LDAP_BIND_CMD = 0x60;

        public const int LDAP_UNBIND_CMD = 0x42;

        public const int LDAP_SEARCH_CMD = 0x63;

        public const int LDAP_MODIFY_CMD = 0x66;

        public const int LDAP_ADD_CMD = 0x68;

        public const int LDAP_DELETE_CMD = 0x4a;

        public const int LDAP_MODRDN_CMD = 0x6c;

        public const int LDAP_COMPARE_CMD = 0x6e;

        public const int LDAP_ABANDON_CMD = 0x50;

        public const int LDAP_SESSION_CMD = 0x71;

        public const int LDAP_EXTENDED_CMD = 0x77;

        public const int LDAP_RES_BIND = 0x61;

        public const int LDAP_RES_SEARCH_ENTRY = 0x64;

        public const int LDAP_RES_SEARCH_RESULT = 0x65;

        public const int LDAP_RES_MODIFY = 0x67;

        public const int LDAP_RES_ADD = 0x69;

        public const int LDAP_RES_DELETE = 0x6b;

        public const int LDAP_RES_MODRDN = 0x6d;

        public const int LDAP_RES_COMPARE = 0x6f;

        public const int LDAP_RES_SESSION = 0x72;

        public const int LDAP_RES_REFERRAL = 0x73;

        public const int LDAP_RES_EXTENDED = 0x78;

        public const int LDAP_RES_ANY = -1;

        public const uint LDAP_INVALID_CMD = 0xff;

        public const uint LDAP_INVALID_RES = 0xff;

        public const int LDAP_AUTH_SIMPLE = 0x80;

        public const int LDAP_AUTH_SASL = 0x83;

        public const int LDAP_AUTH_OTHERKIND = 0x86;

        public const uint LDAP_FILTER_AND = 0xa0;

        public const uint LDAP_FILTER_OR = 0xa1;

        public const uint LDAP_FILTER_NOT = 0xa2;

        public const uint LDAP_FILTER_EQUALITY = 0xa3;

        public const uint LDAP_FILTER_SUBSTRINGS = 0xa4;

        public const uint LDAP_FILTER_GE = 0xa5;

        public const uint LDAP_FILTER_LE = 0xa6;

        public const uint LDAP_FILTER_PRESENT = 0x87;

        public const uint LDAP_FILTER_APPROX = 0xa8;

        public const uint LDAP_FILTER_EXTENSIBLE = 0xa9;

        public const int LDAP_SUBSTRING_INITIAL = 0x80;

        public const int LDAP_SUBSTRING_ANY = 0x81;

        public const int LDAP_SUBSTRING_FINAL = 0x82;

        public const uint LDAP_DEREF_NEVER = 0;

        public const uint LDAP_DEREF_SEARCHING = 1;

        public const uint LDAP_DEREF_FINDING = 2;

        public const uint LDAP_DEREF_ALWAYS = 3;

        public const uint LDAP_NO_LIMIT = 0;

        public const uint LDAP_OPT_DNS = 0x00000001;

        public const uint LDAP_OPT_CHASE_REFERRALS = 0x00000002;

        public const uint LDAP_OPT_RETURN_REFS = 0x00000004;

        public const uint LDAP_MOD_ADD = 0x00;

        public const uint LDAP_MOD_DELETE = 0x01;

        public const uint LDAP_MOD_REPLACE = 0x02;

        public const uint LDAP_MOD_BVALUES = 0x80;

        public const uint LDAP_OPT_API_INFO = 0x00;

        public const uint LDAP_OPT_DESC = 0x01;

        public const uint LDAP_OPT_DEREF = 0x02;

        public const uint LDAP_OPT_SIZELIMIT = 0x03;

        public const uint LDAP_OPT_TIMELIMIT = 0x04;

        public const uint LDAP_OPT_THREAD_FN_PTRS = 0x05;

        public const uint LDAP_OPT_REBIND_FN = 0x06;

        public const uint LDAP_OPT_REBIND_ARG = 0x07;

        public const uint LDAP_OPT_REFERRALS = 0x08;

        public const uint LDAP_OPT_RESTART = 0x09;

        public const uint LDAP_OPT_SSL = 0x0a;

        public const uint LDAP_OPT_IO_FN_PTRS = 0x0b;

        public const uint LDAP_OPT_CACHE_FN_PTRS = 0x0d;

        public const uint LDAP_OPT_CACHE_STRATEGY = 0x0e;

        public const uint LDAP_OPT_CACHE_ENABLE = 0x0f;

        public const uint LDAP_OPT_REFERRAL_HOP_LIMIT = 0x10;

        public const uint LDAP_OPT_PROTOCOL_VERSION = 0x11;

        public const uint LDAP_OPT_VERSION = 0x11;

        public const uint LDAP_OPT_API_FEATURE_INFO = 0x15;

        public const uint LDAP_OPT_HOST_NAME = 0x30;

        public const uint LDAP_OPT_ERROR_NUMBER = 0x31;

        public const uint LDAP_OPT_ERROR_STRING = 0x32;

        public const uint LDAP_OPT_SERVER_ERROR = 0x33;

        public const uint LDAP_OPT_SERVER_EXT_ERROR = 0x34;

        public const uint LDAP_OPT_HOST_REACHABLE = 0x3E;

        public const uint LDAP_OPT_PING_KEEP_ALIVE = 0x36;

        public const uint LDAP_OPT_PING_WAIT_TIME = 0x37;

        public const uint LDAP_OPT_PING_LIMIT = 0x38;

        public const uint LDAP_OPT_DNSDOMAIN_NAME = 0x3B;

        public const uint LDAP_OPT_GETDSNAME_FLAGS = 0x3D;

        public const uint LDAP_OPT_PROMPT_CREDENTIALS = 0x3F;

        public const uint LDAP_OPT_AUTO_RECONNECT = 0x91;

        public const uint LDAP_OPT_SSPI_FLAGS = 0x92;

        public const uint LDAP_OPT_SSL_INFO = 0x93;

        public const uint LDAP_OPT_SIGN = 0x95;

        public const uint LDAP_OPT_ENCRYPT = 0x96;

        public const uint LDAP_OPT_SASL_METHOD = 0x97;

        public const uint LDAP_OPT_AREC_EXCLUSIVE = 0x98;

        public const uint LDAP_OPT_SECURITY_CONTEXT = 0x99;

        public const uint LDAP_OPT_ROOTDSE_CACHE = 0x9a;

        public const uint LDAP_OPT_TCP_KEEPALIVE = 0x40;

        public const uint LDAP_OPT_FAST_CONCURRENT_BIND = 0x41;

        public const uint LDAP_OPT_SEND_TIMEOUT = 0x42;

        public const uint LDAP_OPT_SCH_FLAGS = 0x43;

        public const uint LDAP_OPT_SOCKET_BIND_ADDRESSES = 0x44;

        public const uint LDAP_CHASE_SUBORDINATE_REFERRALS = 0x00000020;

        public const uint LDAP_CHASE_EXTERNAL_REFERRALS = 0x00000040;

        public const uint LDAP_SCOPE_BASE = 0x00;

        public const uint LDAP_SCOPE_ONELEVEL = 0x01;

        public const uint LDAP_SCOPE_SUBTREE = 0x02;

        public const uint LDAP_MSG_ONE = 0;

        public const uint LDAP_MSG_ALL = 1;

        public const uint LDAP_MSG_RECEIVED = 2;

        public const uint LBER_USE_DER = 0x01;

        public const uint LBER_USE_INDEFINITE_LEN = 0x02;

        public const uint LBER_TRANSLATE_STRINGS = 0x04;

        public const uint LAPI_MAJOR_VER1 = 1;

        public const uint LAPI_MINOR_VER1 = 1;

        public const uint LDAP_API_INFO_VERSION = 1;

        public const uint LDAP_API_VERSION = 2004;

        public const uint LDAP_VERSION_MIN = 2;

        public const uint LDAP_VERSION_MAX = 3;

        public const uint LDAP_VENDOR_VERSION = 510;

        public const uint LDAP_FEATURE_INFO_VERSION = 1;

        public const uint LDAP_API_FEATURE_VIRTUAL_LIST_VIEW = 1001;

        public const uint LDAP_VLVINFO_VERSION = 1;

        public const uint LDAP_OPT_REFERRAL_CALLBACK = 0x70;

        public const uint LDAP_OPT_CLIENT_CERTIFICATE = 0x80;

        public const uint LDAP_OPT_SERVER_CERTIFICATE = 0x81;

        public const uint LDAP_OPT_REF_DEREF_CONN_PER_MSG = 0x94;

    }
}
