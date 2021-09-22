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


namespace Windows.Win32.NetworkManagement.Dns
{
    public static partial class Apis
    {
        public const uint SIZEOF_IP4_ADDRESS = 4;

        public const uint IP4_ADDRESS_STRING_LENGTH = 16;

        public const uint IP4_ADDRESS_STRING_BUFFER_LENGTH = 16;

        public const uint DNS_ADDR_MAX_SOCKADDR_LENGTH = 32;

        public const uint IP6_ADDRESS_STRING_LENGTH = 65;

        public const uint IP6_ADDRESS_STRING_BUFFER_LENGTH = 65;

        public const uint DNS_PORT_HOST_ORDER = 0x0035;

        public const uint DNS_PORT_NET_ORDER = 0x3500;

        public const uint DNS_RFC_MAX_UDP_PACKET_LENGTH = 512;

        public const uint DNS_MAX_NAME_LENGTH = 255;

        public const uint DNS_MAX_LABEL_LENGTH = 63;

        public const uint DNS_MAX_NAME_BUFFER_LENGTH = 256;

        public const uint DNS_MAX_LABEL_BUFFER_LENGTH = 64;

        public const uint DNS_MAX_IP4_REVERSE_NAME_LENGTH = IP4_ADDRESS_STRING_LENGTH+15;

        public const uint DNS_MAX_IP6_REVERSE_NAME_LENGTH = 75;

        public const uint DNS_MAX_TEXT_STRING_LENGTH = 255;

        public const uint DNS_COMPRESSED_QUESTION_NAME = 0xC00C;

        public const uint DNS_OPCODE_QUERY = 0;

        public const uint DNS_OPCODE_IQUERY = 1;

        public const uint DNS_OPCODE_SERVER_STATUS = 2;

        public const uint DNS_OPCODE_UNKNOWN = 3;

        public const uint DNS_OPCODE_NOTIFY = 4;

        public const uint DNS_OPCODE_UPDATE = 5;

        public const uint DNS_RCODE_NOERROR = 0;

        public const uint DNS_RCODE_FORMERR = 1;

        public const uint DNS_RCODE_SERVFAIL = 2;

        public const uint DNS_RCODE_NXDOMAIN = 3;

        public const uint DNS_RCODE_NOTIMPL = 4;

        public const uint DNS_RCODE_REFUSED = 5;

        public const uint DNS_RCODE_YXDOMAIN = 6;

        public const uint DNS_RCODE_YXRRSET = 7;

        public const uint DNS_RCODE_NXRRSET = 8;

        public const uint DNS_RCODE_NOTAUTH = 9;

        public const uint DNS_RCODE_NOTZONE = 10;

        public const uint DNS_RCODE_MAX = 15;

        public const uint DNS_RCODE_BADVERS = 16;

        public const uint DNS_RCODE_BADSIG = 16;

        public const uint DNS_RCODE_BADKEY = 17;

        public const uint DNS_RCODE_BADTIME = 18;

        public const uint DNS_CLASS_INTERNET = 0x0001;

        public const uint DNS_CLASS_CSNET = 0x0002;

        public const uint DNS_CLASS_CHAOS = 0x0003;

        public const uint DNS_CLASS_HESIOD = 0x0004;

        public const uint DNS_CLASS_NONE = 0x00fe;

        public const uint DNS_CLASS_ALL = 0x00ff;

        public const uint DNS_CLASS_ANY = 0x00ff;

        public const uint DNS_CLASS_UNICAST_RESPONSE = 0x8000;

        public const uint DNS_RCLASS_INTERNET = 0x0100;

        public const uint DNS_RCLASS_CSNET = 0x0200;

        public const uint DNS_RCLASS_CHAOS = 0x0300;

        public const uint DNS_RCLASS_HESIOD = 0x0400;

        public const uint DNS_RCLASS_NONE = 0xfe00;

        public const uint DNS_RCLASS_ALL = 0xff00;

        public const uint DNS_RCLASS_ANY = 0xff00;

        public const uint DNS_RCLASS_UNICAST_RESPONSE = 0x0080;

        public const uint DNS_TYPE_ZERO = 0x0000;

        public const uint DNS_TYPE_A = 0x0001;

        public const uint DNS_TYPE_NS = 0x0002;

        public const uint DNS_TYPE_MD = 0x0003;

        public const uint DNS_TYPE_MF = 0x0004;

        public const uint DNS_TYPE_CNAME = 0x0005;

        public const uint DNS_TYPE_SOA = 0x0006;

        public const uint DNS_TYPE_MB = 0x0007;

        public const uint DNS_TYPE_MG = 0x0008;

        public const uint DNS_TYPE_MR = 0x0009;

        public const uint DNS_TYPE_NULL = 0x000a;

        public const uint DNS_TYPE_WKS = 0x000b;

        public const uint DNS_TYPE_PTR = 0x000c;

        public const uint DNS_TYPE_HINFO = 0x000d;

        public const uint DNS_TYPE_MINFO = 0x000e;

        public const uint DNS_TYPE_MX = 0x000f;

        public const uint DNS_TYPE_TEXT = 0x0010;

        public const uint DNS_TYPE_RP = 0x0011;

        public const uint DNS_TYPE_AFSDB = 0x0012;

        public const uint DNS_TYPE_X25 = 0x0013;

        public const uint DNS_TYPE_ISDN = 0x0014;

        public const uint DNS_TYPE_RT = 0x0015;

        public const uint DNS_TYPE_NSAP = 0x0016;

        public const uint DNS_TYPE_NSAPPTR = 0x0017;

        public const uint DNS_TYPE_SIG = 0x0018;

        public const uint DNS_TYPE_KEY = 0x0019;

        public const uint DNS_TYPE_PX = 0x001a;

        public const uint DNS_TYPE_GPOS = 0x001b;

        public const uint DNS_TYPE_AAAA = 0x001c;

        public const uint DNS_TYPE_LOC = 0x001d;

        public const uint DNS_TYPE_NXT = 0x001e;

        public const uint DNS_TYPE_EID = 0x001f;

        public const uint DNS_TYPE_NIMLOC = 0x0020;

        public const uint DNS_TYPE_SRV = 0x0021;

        public const uint DNS_TYPE_ATMA = 0x0022;

        public const uint DNS_TYPE_NAPTR = 0x0023;

        public const uint DNS_TYPE_KX = 0x0024;

        public const uint DNS_TYPE_CERT = 0x0025;

        public const uint DNS_TYPE_A6 = 0x0026;

        public const uint DNS_TYPE_DNAME = 0x0027;

        public const uint DNS_TYPE_SINK = 0x0028;

        public const uint DNS_TYPE_OPT = 0x0029;

        public const uint DNS_TYPE_DS = 0x002b;

        public const uint DNS_TYPE_RRSIG = 0x002e;

        public const uint DNS_TYPE_NSEC = 0x002f;

        public const uint DNS_TYPE_DNSKEY = 0x0030;

        public const uint DNS_TYPE_DHCID = 0x0031;

        public const uint DNS_TYPE_NSEC3 = 0x0032;

        public const uint DNS_TYPE_NSEC3PARAM = 0x0033;

        public const uint DNS_TYPE_TLSA = 0x0034;

        public const uint DNS_TYPE_UINFO = 0x0064;

        public const uint DNS_TYPE_UID = 0x0065;

        public const uint DNS_TYPE_GID = 0x0066;

        public const uint DNS_TYPE_UNSPEC = 0x0067;

        public const uint DNS_TYPE_ADDRS = 0x00f8;

        public const uint DNS_TYPE_TKEY = 0x00f9;

        public const uint DNS_TYPE_TSIG = 0x00fa;

        public const uint DNS_TYPE_IXFR = 0x00fb;

        public const uint DNS_TYPE_AXFR = 0x00fc;

        public const uint DNS_TYPE_MAILB = 0x00fd;

        public const uint DNS_TYPE_MAILA = 0x00fe;

        public const uint DNS_TYPE_ALL = 0x00ff;

        public const uint DNS_TYPE_ANY = 0x00ff;

        public const uint DNS_TYPE_WINS = 0xff01;

        public const uint DNS_TYPE_WINSR = 0xff02;

        public const uint DNS_RTYPE_A = 0x0100;

        public const uint DNS_RTYPE_NS = 0x0200;

        public const uint DNS_RTYPE_MD = 0x0300;

        public const uint DNS_RTYPE_MF = 0x0400;

        public const uint DNS_RTYPE_CNAME = 0x0500;

        public const uint DNS_RTYPE_SOA = 0x0600;

        public const uint DNS_RTYPE_MB = 0x0700;

        public const uint DNS_RTYPE_MG = 0x0800;

        public const uint DNS_RTYPE_MR = 0x0900;

        public const uint DNS_RTYPE_NULL = 0x0a00;

        public const uint DNS_RTYPE_WKS = 0x0b00;

        public const uint DNS_RTYPE_PTR = 0x0c00;

        public const uint DNS_RTYPE_HINFO = 0x0d00;

        public const uint DNS_RTYPE_MINFO = 0x0e00;

        public const uint DNS_RTYPE_MX = 0x0f00;

        public const uint DNS_RTYPE_TEXT = 0x1000;

        public const uint DNS_RTYPE_RP = 0x1100;

        public const uint DNS_RTYPE_AFSDB = 0x1200;

        public const uint DNS_RTYPE_X25 = 0x1300;

        public const uint DNS_RTYPE_ISDN = 0x1400;

        public const uint DNS_RTYPE_RT = 0x1500;

        public const uint DNS_RTYPE_NSAP = 0x1600;

        public const uint DNS_RTYPE_NSAPPTR = 0x1700;

        public const uint DNS_RTYPE_SIG = 0x1800;

        public const uint DNS_RTYPE_KEY = 0x1900;

        public const uint DNS_RTYPE_PX = 0x1a00;

        public const uint DNS_RTYPE_GPOS = 0x1b00;

        public const uint DNS_RTYPE_AAAA = 0x1c00;

        public const uint DNS_RTYPE_LOC = 0x1d00;

        public const uint DNS_RTYPE_NXT = 0x1e00;

        public const uint DNS_RTYPE_EID = 0x1f00;

        public const uint DNS_RTYPE_NIMLOC = 0x2000;

        public const uint DNS_RTYPE_SRV = 0x2100;

        public const uint DNS_RTYPE_ATMA = 0x2200;

        public const uint DNS_RTYPE_NAPTR = 0x2300;

        public const uint DNS_RTYPE_KX = 0x2400;

        public const uint DNS_RTYPE_CERT = 0x2500;

        public const uint DNS_RTYPE_A6 = 0x2600;

        public const uint DNS_RTYPE_DNAME = 0x2700;

        public const uint DNS_RTYPE_SINK = 0x2800;

        public const uint DNS_RTYPE_OPT = 0x2900;

        public const uint DNS_RTYPE_DS = 0x2b00;

        public const uint DNS_RTYPE_RRSIG = 0x2e00;

        public const uint DNS_RTYPE_NSEC = 0x2f00;

        public const uint DNS_RTYPE_DNSKEY = 0x3000;

        public const uint DNS_RTYPE_DHCID = 0x3100;

        public const uint DNS_RTYPE_NSEC3 = 0x3200;

        public const uint DNS_RTYPE_NSEC3PARAM = 0x3300;

        public const uint DNS_RTYPE_TLSA = 0x3400;

        public const uint DNS_RTYPE_UINFO = 0x6400;

        public const uint DNS_RTYPE_UID = 0x6500;

        public const uint DNS_RTYPE_GID = 0x6600;

        public const uint DNS_RTYPE_UNSPEC = 0x6700;

        public const uint DNS_RTYPE_TKEY = 0xf900;

        public const uint DNS_RTYPE_TSIG = 0xfa00;

        public const uint DNS_RTYPE_IXFR = 0xfb00;

        public const uint DNS_RTYPE_AXFR = 0xfc00;

        public const uint DNS_RTYPE_MAILB = 0xfd00;

        public const uint DNS_RTYPE_MAILA = 0xfe00;

        public const uint DNS_RTYPE_ALL = 0xff00;

        public const uint DNS_RTYPE_ANY = 0xff00;

        public const uint DNS_RTYPE_WINS = 0x01ff;

        public const uint DNS_RTYPE_WINSR = 0x02ff;

        public const uint DNS_ATMA_FORMAT_E164 = 1;

        public const uint DNS_ATMA_FORMAT_AESA = 2;

        public const uint DNS_ATMA_MAX_ADDR_LENGTH = 20;

        public const uint DNS_ATMA_AESA_ADDR_LENGTH = 20;

        public const uint DNS_ATMA_MAX_RECORD_LENGTH = DNS_ATMA_MAX_ADDR_LENGTH+1;

        public const uint DNSSEC_ALGORITHM_RSAMD5 = 1;

        public const uint DNSSEC_ALGORITHM_RSASHA1 = 5;

        public const uint DNSSEC_ALGORITHM_RSASHA1_NSEC3 = 7;

        public const uint DNSSEC_ALGORITHM_RSASHA256 = 8;

        public const uint DNSSEC_ALGORITHM_RSASHA512 = 10;

        public const uint DNSSEC_ALGORITHM_ECDSAP256_SHA256 = 13;

        public const uint DNSSEC_ALGORITHM_ECDSAP384_SHA384 = 14;

        public const uint DNSSEC_ALGORITHM_NULL = 253;

        public const uint DNSSEC_ALGORITHM_PRIVATE = 254;

        public const uint DNSSEC_DIGEST_ALGORITHM_SHA1 = 1;

        public const uint DNSSEC_DIGEST_ALGORITHM_SHA256 = 2;

        public const uint DNSSEC_DIGEST_ALGORITHM_SHA384 = 4;

        public const uint DNSSEC_PROTOCOL_NONE = 0;

        public const uint DNSSEC_PROTOCOL_TLS = 1;

        public const uint DNSSEC_PROTOCOL_EMAIL = 2;

        public const uint DNSSEC_PROTOCOL_DNSSEC = 3;

        public const uint DNSSEC_PROTOCOL_IPSEC = 4;

        public const uint DNSSEC_KEY_FLAG_NOAUTH = 0x0001;

        public const uint DNSSEC_KEY_FLAG_NOCONF = 0x0002;

        public const uint DNSSEC_KEY_FLAG_FLAG2 = 0x0004;

        public const uint DNSSEC_KEY_FLAG_EXTEND = 0x0008;

        public const uint DNSSEC_KEY_FLAG_FLAG4 = 0x0010;

        public const uint DNSSEC_KEY_FLAG_FLAG5 = 0x0020;

        public const uint DNSSEC_KEY_FLAG_USER = 0x0000;

        public const uint DNSSEC_KEY_FLAG_ZONE = 0x0040;

        public const uint DNSSEC_KEY_FLAG_HOST = 0x0080;

        public const uint DNSSEC_KEY_FLAG_NTPE3 = 0x00c0;

        public const uint DNSSEC_KEY_FLAG_FLAG8 = 0x0100;

        public const uint DNSSEC_KEY_FLAG_FLAG9 = 0x0200;

        public const uint DNSSEC_KEY_FLAG_FLAG10 = 0x0400;

        public const uint DNSSEC_KEY_FLAG_FLAG11 = 0x0800;

        public const uint DNSSEC_KEY_FLAG_SIG0 = 0x0000;

        public const uint DNSSEC_KEY_FLAG_SIG1 = 0x1000;

        public const uint DNSSEC_KEY_FLAG_SIG2 = 0x2000;

        public const uint DNSSEC_KEY_FLAG_SIG3 = 0x3000;

        public const uint DNSSEC_KEY_FLAG_SIG4 = 0x4000;

        public const uint DNSSEC_KEY_FLAG_SIG5 = 0x5000;

        public const uint DNSSEC_KEY_FLAG_SIG6 = 0x6000;

        public const uint DNSSEC_KEY_FLAG_SIG7 = 0x7000;

        public const uint DNSSEC_KEY_FLAG_SIG8 = 0x8000;

        public const uint DNSSEC_KEY_FLAG_SIG9 = 0x9000;

        public const uint DNSSEC_KEY_FLAG_SIG10 = 0xa000;

        public const uint DNSSEC_KEY_FLAG_SIG11 = 0xb000;

        public const uint DNSSEC_KEY_FLAG_SIG12 = 0xc000;

        public const uint DNSSEC_KEY_FLAG_SIG13 = 0xd000;

        public const uint DNSSEC_KEY_FLAG_SIG14 = 0xe000;

        public const uint DNSSEC_KEY_FLAG_SIG15 = 0xf000;

        public const uint DNS_TKEY_MODE_SERVER_ASSIGN = 1;

        public const uint DNS_TKEY_MODE_DIFFIE_HELLMAN = 2;

        public const uint DNS_TKEY_MODE_GSS = 3;

        public const uint DNS_TKEY_MODE_RESOLVER_ASSIGN = 4;

        public const uint DNS_WINS_FLAG_SCOPE = 0x80000000;

        public const uint DNS_WINS_FLAG_LOCAL = 0x00010000;

        public const uint DNS_CONFIG_FLAG_ALLOC = 0x00000001;

        public const uint DNSREC_SECTION = 0x00000003;

        public const uint DNSREC_QUESTION = 0x00000000;

        public const uint DNSREC_ANSWER = 0x00000001;

        public const uint DNSREC_AUTHORITY = 0x00000002;

        public const uint DNSREC_ADDITIONAL = 0x00000003;

        public const uint DNSREC_ZONE = 0x00000000;

        public const uint DNSREC_PREREQ = 0x00000001;

        public const uint DNSREC_UPDATE = 0x00000002;

        public const uint DNSREC_DELETE = 0x00000004;

        public const uint DNSREC_NOEXIST = 0x00000004;

        public const uint DNS_QUERY_STANDARD = 0x00000000;

        public const uint DNS_QUERY_ACCEPT_TRUNCATED_RESPONSE = 0x00000001;

        public const uint DNS_QUERY_USE_TCP_ONLY = 0x00000002;

        public const uint DNS_QUERY_NO_RECURSION = 0x00000004;

        public const uint DNS_QUERY_BYPASS_CACHE = 0x00000008;

        public const uint DNS_QUERY_NO_WIRE_QUERY = 0x00000010;

        public const uint DNS_QUERY_NO_LOCAL_NAME = 0x00000020;

        public const uint DNS_QUERY_NO_HOSTS_FILE = 0x00000040;

        public const uint DNS_QUERY_NO_NETBT = 0x00000080;

        public const uint DNS_QUERY_WIRE_ONLY = 0x00000100;

        public const uint DNS_QUERY_RETURN_MESSAGE = 0x00000200;

        public const uint DNS_QUERY_MULTICAST_ONLY = 0x00000400;

        public const uint DNS_QUERY_NO_MULTICAST = 0x00000800;

        public const uint DNS_QUERY_TREAT_AS_FQDN = 0x00001000;

        public const uint DNS_QUERY_ADDRCONFIG = 0x00002000;

        public const uint DNS_QUERY_DUAL_ADDR = 0x00004000;

        public const uint DNS_QUERY_DONT_RESET_TTL_VALUES = 0x00100000;

        public const uint DNS_QUERY_DISABLE_IDN_ENCODING = 0x00200000;

        public const uint DNS_QUERY_APPEND_MULTILABEL = 0x00800000;

        public const uint DNS_QUERY_DNSSEC_OK = 0x01000000;

        public const uint DNS_QUERY_DNSSEC_CHECKING_DISABLED = 0x02000000;

        public const uint DNS_QUERY_RESERVED = 0xf0000000;

        public const uint DNS_QUERY_RESULTS_VERSION1 = 0x1;

        public const uint DNS_QUERY_REQUEST_VERSION1 = 0x1;

        public const uint DNS_UPDATE_SECURITY_USE_DEFAULT = 0x00000000;

        public const uint DNS_UPDATE_SECURITY_OFF = 0x00000010;

        public const uint DNS_UPDATE_SECURITY_ON = 0x00000020;

        public const uint DNS_UPDATE_SECURITY_ONLY = 0x00000100;

        public const uint DNS_UPDATE_CACHE_SECURITY_CONTEXT = 0x00000200;

        public const uint DNS_UPDATE_TEST_USE_LOCAL_SYS_ACCT = 0x00000400;

        public const uint DNS_UPDATE_FORCE_SECURITY_NEGO = 0x00000800;

        public const uint DNS_UPDATE_TRY_ALL_MASTER_SERVERS = 0x00001000;

        public const uint DNS_UPDATE_SKIP_NO_UPDATE_ADAPTERS = 0x00002000;

        public const uint DNS_UPDATE_REMOTE_SERVER = 0x00004000;

        public const uint DNS_UPDATE_RESERVED = 0xffff0000;

        public const uint DNS_VALSVR_ERROR_INVALID_ADDR = 0x01;

        public const uint DNS_VALSVR_ERROR_INVALID_NAME = 0x02;

        public const uint DNS_VALSVR_ERROR_UNREACHABLE = 0x03;

        public const uint DNS_VALSVR_ERROR_NO_RESPONSE = 0x04;

        public const uint DNS_VALSVR_ERROR_NO_AUTH = 0x05;

        public const uint DNS_VALSVR_ERROR_REFUSED = 0x06;

        public const uint DNS_VALSVR_ERROR_NO_TCP = 0x10;

        public const uint DNS_VALSVR_ERROR_UNKNOWN = 0xFF;

        public const uint DNS_CONNECTION_NAME_MAX_LENGTH = 64;

        public const uint DNS_CONNECTION_PROXY_INFO_CURRENT_VERSION = 1;

        public const uint DNS_CONNECTION_PROXY_INFO_SERVER_MAX_LENGTH = 256;

        public const uint DNS_CONNECTION_PROXY_INFO_FRIENDLY_NAME_MAX_LENGTH = 64;

        public const uint DNS_CONNECTION_PROXY_INFO_USERNAME_MAX_LENGTH = 128;

        public const uint DNS_CONNECTION_PROXY_INFO_PASSWORD_MAX_LENGTH = 128;

        public const uint DNS_CONNECTION_PROXY_INFO_EXCEPTION_MAX_LENGTH = 1024;

        public const uint DNS_CONNECTION_PROXY_INFO_EXTRA_INFO_MAX_LENGTH = 1024;

        public const uint DNS_CONNECTION_PROXY_INFO_FLAG_DISABLED = 0x1;

        public const uint DNS_CONNECTION_PROXY_INFO_FLAG_BYPASSLOCAL = 0x2;

        public const uint DNS_CONNECTION_POLICY_ENTRY_ONDEMAND = 0x00000001;

    }
}
