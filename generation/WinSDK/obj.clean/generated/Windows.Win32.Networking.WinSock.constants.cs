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


namespace Windows.Win32.Networking.WinSock
{
    public static partial class Apis
    {
        public static readonly Guid SOCKET_DEFAULT2_QM_POLICY__scanned__ = new Guid(0xaec2ef9c,   0x3a4d,   0x4d3e,   0x88, 0x42, 0x23, 0x99, 0x42, 0xe3, 0x9a, 0x47);

        public static readonly Guid REAL_TIME_NOTIFICATION_CAPABILITY__scanned__ = new Guid(0x6b59819a,   0x5cae,   0x492d,   0xa9, 0x01, 0x2a, 0x3c, 0x2c, 0x50, 0x16, 0x4f);

        public static readonly Guid REAL_TIME_NOTIFICATION_CAPABILITY_EX__scanned__ = new Guid(0x6843da03,   0x154a,   0x4616,   0xa5, 0x08, 0x44, 0x37, 0x12, 0x95, 0xf9, 0x6b);

        public static readonly Guid ASSOCIATE_NAMERES_CONTEXT__scanned__ = new Guid(0x59a38b67,   0xd4fe,   0x46e1,   0xba, 0x3c, 0x87, 0xea, 0x74, 0xca, 0x30, 0x49);

        public const uint TCP_INITIAL_RTO_DEFAULT_RTT = 0;

        public const uint TCP_INITIAL_RTO_DEFAULT_MAX_SYN_RETRANSMISSIONS = 0;

        public const uint SOCKET_SETTINGS_GUARANTEE_ENCRYPTION = 0x1;

        public const uint SOCKET_SETTINGS_ALLOW_INSECURE = 0x2;

        public const uint SOCKET_SETTINGS_IPSEC_SKIP_FILTER_INSTANTIATION = 0x1;

        public const uint SOCKET_SETTINGS_IPSEC_OPTIONAL_PEER_NAME_VERIFICATION = 0x2;

        public const uint SOCKET_SETTINGS_IPSEC_ALLOW_FIRST_INBOUND_PKT_UNENCRYPTED = 0x4;

        public const uint SOCKET_SETTINGS_IPSEC_PEER_NAME_IS_RAW_FORMAT = 0x8;

        public const uint SOCKET_QUERY_IPSEC2_ABORT_CONNECTION_ON_FIELD_CHANGE = 0x1;

        public const uint SOCKET_QUERY_IPSEC2_FIELD_MASK_MM_SA_ID = 0x1;

        public const uint SOCKET_QUERY_IPSEC2_FIELD_MASK_QM_SA_ID = 0x2;

        public const uint SOCKET_INFO_CONNECTION_SECURED = 0x1;

        public const uint SOCKET_INFO_CONNECTION_ENCRYPTED = 0x2;

        public const uint SOCKET_INFO_CONNECTION_IMPERSONATED = 0x4;

        public const uint IN4ADDR_LOOPBACK = 0x0100007f;

        public const uint IN4ADDR_LOOPBACKPREFIX_LENGTH = 8;

        public const uint IN4ADDR_LINKLOCALPREFIX_LENGTH = 16;

        public const uint IN4ADDR_MULTICASTPREFIX_LENGTH = 4;

        public const uint RIO_MSG_DONT_NOTIFY = 0x00000001;

        public const uint RIO_MSG_DEFER = 0x00000002;

        public const uint RIO_MSG_WAITALL = 0x00000004;

        public const uint RIO_MSG_COMMIT_ONLY = 0x00000008;

        public const uint RIO_MAX_CQ_SIZE = 0x8000000;

        public const uint RIO_CORRUPT_CQ = 0xFFFFFFFF;

        public const ushort AF_UNIX = 1;

        public const ushort AF_IMPLINK = 3;

        public const ushort AF_PUP = 4;

        public const ushort AF_CHAOS = 5;

        public const ushort AF_NS = 6;

        public const ushort AF_ISO = 7;

        public const ushort AF_ECMA = 8;

        public const ushort AF_DATAKIT = 9;

        public const ushort AF_CCITT = 10;

        public const ushort AF_SNA = 11;

        public const ushort AF_DECnet = 12;

        public const ushort AF_DLI = 13;

        public const ushort AF_LAT = 14;

        public const ushort AF_HYLINK = 15;

        public const ushort AF_APPLETALK = 16;

        public const ushort AF_NETBIOS = 17;

        public const ushort AF_VOICEVIEW = 18;

        public const ushort AF_FIREFOX = 19;

        public const ushort AF_UNKNOWN1 = 20;

        public const ushort AF_BAN = 21;

        public const ushort AF_ATM = 22;

        public const ushort AF_CLUSTER = 24;

        public const ushort AF_12844 = 25;

        public const ushort AF_IRDA = 26;

        public const ushort AF_NETDES = 28;

        public const ushort AF_MAX = 29;

        public const ushort AF_TCNPROCESS = 29;

        public const ushort AF_TCNMESSAGE = 30;

        public const ushort AF_ICLFXBM = 31;

        public const ushort AF_LINK = 33;

        public const ushort AF_HYPERV = 34;

        public const ushort SOCK_STREAM = 1;

        public const ushort SOCK_DGRAM = 2;

        public const ushort SOCK_RAW = 3;

        public const ushort SOCK_RDM = 4;

        public const ushort SOCK_SEQPACKET = 5;

        public const uint SOL_SOCKET = 0xffff;

        public const uint SO_DEBUG = 0x0001;

        public const uint SO_ACCEPTCONN = 0x0002;

        public const uint SO_REUSEADDR = 0x0004;

        public const uint SO_KEEPALIVE = 0x0008;

        public const uint SO_DONTROUTE = 0x0010;

        public const uint SO_BROADCAST = 0x0020;

        public const uint SO_USELOOPBACK = 0x0040;

        public const uint SO_LINGER = 0x0080;

        public const uint SO_OOBINLINE = 0x0100;

        public const uint SO_SNDBUF = 0x1001;

        public const uint SO_RCVBUF = 0x1002;

        public const uint SO_SNDLOWAT = 0x1003;

        public const uint SO_RCVLOWAT = 0x1004;

        public const uint SO_SNDTIMEO = 0x1005;

        public const uint SO_RCVTIMEO = 0x1006;

        public const uint SO_ERROR = 0x1007;

        public const uint SO_TYPE = 0x1008;

        public const uint SO_BSP_STATE = 0x1009;

        public const uint SO_GROUP_ID = 0x2001;

        public const uint SO_GROUP_PRIORITY = 0x2002;

        public const uint SO_MAX_MSG_SIZE = 0x2003;

        public const uint SO_CONDITIONAL_ACCEPT = 0x3002;

        public const uint SO_PAUSE_ACCEPT = 0x3003;

        public const uint SO_COMPARTMENT_ID = 0x3004;

        public const uint SO_RANDOMIZE_PORT = 0x3005;

        public const uint SO_PORT_SCALABILITY = 0x3006;

        public const uint SO_REUSE_UNICASTPORT = 0x3007;

        public const uint SO_REUSE_MULTICASTPORT = 0x3008;

        public const uint SO_ORIGINAL_DST = 0x300F;

        public const uint WSK_SO_BASE = 0x4000;

        public const uint TCP_NODELAY = 0x0001;

        public const uint _SS_MAXSIZE = 128;

        public const uint IOC_UNIX = 0x00000000;

        public const uint IOC_WS2 = 0x08000000;

        public const uint IOC_PROTOCOL = 0x10000000;

        public const uint IOC_VENDOR = 0x18000000;

        public const uint IPPROTO_IP = 0;

        public const uint IPPORT_TCPMUX = 1;

        public const uint IPPORT_ECHO = 7;

        public const uint IPPORT_DISCARD = 9;

        public const uint IPPORT_SYSTAT = 11;

        public const uint IPPORT_DAYTIME = 13;

        public const uint IPPORT_NETSTAT = 15;

        public const uint IPPORT_QOTD = 17;

        public const uint IPPORT_MSP = 18;

        public const uint IPPORT_CHARGEN = 19;

        public const uint IPPORT_FTP_DATA = 20;

        public const uint IPPORT_FTP = 21;

        public const uint IPPORT_TELNET = 23;

        public const uint IPPORT_SMTP = 25;

        public const uint IPPORT_TIMESERVER = 37;

        public const uint IPPORT_NAMESERVER = 42;

        public const uint IPPORT_WHOIS = 43;

        public const uint IPPORT_MTP = 57;

        public const uint IPPORT_TFTP = 69;

        public const uint IPPORT_RJE = 77;

        public const uint IPPORT_FINGER = 79;

        public const uint IPPORT_TTYLINK = 87;

        public const uint IPPORT_SUPDUP = 95;

        public const uint IPPORT_POP3 = 110;

        public const uint IPPORT_NTP = 123;

        public const uint IPPORT_EPMAP = 135;

        public const uint IPPORT_NETBIOS_NS = 137;

        public const uint IPPORT_NETBIOS_DGM = 138;

        public const uint IPPORT_NETBIOS_SSN = 139;

        public const uint IPPORT_IMAP = 143;

        public const uint IPPORT_SNMP = 161;

        public const uint IPPORT_SNMP_TRAP = 162;

        public const uint IPPORT_IMAP3 = 220;

        public const uint IPPORT_LDAP = 389;

        public const uint IPPORT_HTTPS = 443;

        public const uint IPPORT_MICROSOFT_DS = 445;

        public const uint IPPORT_EXECSERVER = 512;

        public const uint IPPORT_LOGINSERVER = 513;

        public const uint IPPORT_CMDSERVER = 514;

        public const uint IPPORT_EFSSERVER = 520;

        public const uint IPPORT_BIFFUDP = 512;

        public const uint IPPORT_WHOSERVER = 513;

        public const uint IPPORT_ROUTESERVER = 520;

        public const uint IPPORT_RESERVED = 1024;

        public const uint IPPORT_REGISTERED_MAX = 0xbfff;

        public const uint IPPORT_DYNAMIC_MIN = 0xc000;

        public const uint IPPORT_DYNAMIC_MAX = 0xffff;

        public const uint IN_CLASSA_NET = 0xff000000;

        public const uint IN_CLASSA_NSHIFT = 24;

        public const uint IN_CLASSA_HOST = 0x00ffffff;

        public const uint IN_CLASSA_MAX = 128;

        public const uint IN_CLASSB_NET = 0xffff0000;

        public const uint IN_CLASSB_NSHIFT = 16;

        public const uint IN_CLASSB_HOST = 0x0000ffff;

        public const uint IN_CLASSB_MAX = 65536;

        public const uint IN_CLASSC_NET = 0xffffff00;

        public const uint IN_CLASSC_NSHIFT = 8;

        public const uint IN_CLASSC_HOST = 0x000000ff;

        public const uint IN_CLASSD_NET = 0xf0000000;

        public const uint IN_CLASSD_NSHIFT = 28;

        public const uint IN_CLASSD_HOST = 0x0fffffff;

        public const uint INADDR_LOOPBACK = 0x7f000001;

        public const uint INADDR_NONE = 0xffffffff;

        public const uint IOCPARM_MASK = 0x7f;

        public const uint IOC_VOID = 0x20000000;

        public const uint IOC_OUT = 0x40000000;

        public const uint IOC_IN = 0x80000000;

        public const uint MSG_TRUNC = 0x0100;

        public const uint MSG_CTRUNC = 0x0200;

        public const uint MSG_BCAST = 0x0400;

        public const uint MSG_MCAST = 0x0800;

        public const uint MSG_ERRQUEUE = 0x1000;

        public const uint AI_PASSIVE = 0x00000001;

        public const uint AI_CANONNAME = 0x00000002;

        public const uint AI_NUMERICHOST = 0x00000004;

        public const uint AI_NUMERICSERV = 0x00000008;

        public const uint AI_DNS_ONLY = 0x00000010;

        public const uint AI_ALL = 0x00000100;

        public const uint AI_ADDRCONFIG = 0x00000400;

        public const uint AI_V4MAPPED = 0x00000800;

        public const uint AI_NON_AUTHORITATIVE = 0x00004000;

        public const uint AI_SECURE = 0x00008000;

        public const uint AI_RETURN_PREFERRED_NAMES = 0x00010000;

        public const uint AI_FQDN = 0x00020000;

        public const uint AI_FILESERVER = 0x00040000;

        public const uint AI_DISABLE_IDN_ENCODING = 0x00080000;

        public const uint AI_EXTENDED = 0x80000000;

        public const uint AI_RESOLUTION_HANDLE = 0x40000000;

        public const uint ADDRINFOEX_VERSION_2 = 2;

        public const uint ADDRINFOEX_VERSION_3 = 3;

        public const uint ADDRINFOEX_VERSION_4 = 4;

        public const uint NS_ALL = 0;

        public const uint NS_SAP = 1;

        public const uint NS_NDS = 2;

        public const uint NS_PEER_BROWSE = 3;

        public const uint NS_SLP = 5;

        public const uint NS_DHCP = 6;

        public const uint NS_TCPIP_LOCAL = 10;

        public const uint NS_TCPIP_HOSTS = 11;

        public const uint NS_DNS = 12;

        public const uint NS_NETBT = 13;

        public const uint NS_WINS = 14;

        public const uint NS_NLA = 15;

        public const uint NS_NBP = 20;

        public const uint NS_MS = 30;

        public const uint NS_STDA = 31;

        public const uint NS_NTDS = 32;

        public const uint NS_EMAIL = 37;

        public const uint NS_X500 = 40;

        public const uint NS_NIS = 41;

        public const uint NS_NISPLUS = 42;

        public const uint NS_WRQ = 50;

        public const uint NS_NETDES = 60;

        public const uint NI_NOFQDN = 0x01;

        public const uint NI_NUMERICHOST = 0x02;

        public const uint NI_NAMEREQD = 0x04;

        public const uint NI_NUMERICSERV = 0x08;

        public const uint NI_DGRAM = 0x10;

        public const uint NI_MAXHOST = 1025;

        public const uint NI_MAXSERV = 32;

        public const uint IFF_UP = 0x00000001;

        public const uint IFF_BROADCAST = 0x00000002;

        public const uint IFF_LOOPBACK = 0x00000004;

        public const uint IFF_POINTTOPOINT = 0x00000008;

        public const uint IFF_MULTICAST = 0x00000010;

        public const uint IP_OPTIONS = 1;

        public const uint IP_HDRINCL = 2;

        public const uint IP_TOS = 3;

        public const uint IP_TTL = 4;

        public const uint IP_MULTICAST_IF = 9;

        public const uint IP_MULTICAST_TTL = 10;

        public const uint IP_MULTICAST_LOOP = 11;

        public const uint IP_ADD_MEMBERSHIP = 12;

        public const uint IP_DROP_MEMBERSHIP = 13;

        public const uint IP_DONTFRAGMENT = 14;

        public const uint IP_ADD_SOURCE_MEMBERSHIP = 15;

        public const uint IP_DROP_SOURCE_MEMBERSHIP = 16;

        public const uint IP_BLOCK_SOURCE = 17;

        public const uint IP_UNBLOCK_SOURCE = 18;

        public const uint IP_PKTINFO = 19;

        public const uint IP_HOPLIMIT = 21;

        public const uint IP_RECVTTL = 21;

        public const uint IP_RECEIVE_BROADCAST = 22;

        public const uint IP_RECVIF = 24;

        public const uint IP_RECVDSTADDR = 25;

        public const uint IP_IFLIST = 28;

        public const uint IP_ADD_IFLIST = 29;

        public const uint IP_DEL_IFLIST = 30;

        public const uint IP_UNICAST_IF = 31;

        public const uint IP_RTHDR = 32;

        public const uint IP_GET_IFLIST = 33;

        public const uint IP_RECVRTHDR = 38;

        public const uint IP_TCLASS = 39;

        public const uint IP_RECVTCLASS = 40;

        public const uint IP_RECVTOS = 40;

        public const uint IP_ORIGINAL_ARRIVAL_IF = 47;

        public const uint IP_ECN = 50;

        public const uint IP_PKTINFO_EX = 51;

        public const uint IP_WFP_REDIRECT_RECORDS = 60;

        public const uint IP_WFP_REDIRECT_CONTEXT = 70;

        public const uint IP_MTU_DISCOVER = 71;

        public const uint IP_MTU = 73;

        public const uint IP_NRT_INTERFACE = 74;

        public const uint IP_RECVERR = 75;

        public const uint IP_USER_MTU = 76;

        public const int IP_UNSPECIFIED_TYPE_OF_SERVICE = -1;

        public const uint IN6ADDR_LINKLOCALPREFIX_LENGTH = 64;

        public const uint IN6ADDR_MULTICASTPREFIX_LENGTH = 8;

        public const uint IN6ADDR_SOLICITEDNODEMULTICASTPREFIX_LENGTH = 104;

        public const uint IN6ADDR_V4MAPPEDPREFIX_LENGTH = 96;

        public const uint IN6ADDR_6TO4PREFIX_LENGTH = 16;

        public const uint IN6ADDR_TEREDOPREFIX_LENGTH = 32;

        public const uint MCAST_JOIN_GROUP = 41;

        public const uint MCAST_LEAVE_GROUP = 42;

        public const uint MCAST_BLOCK_SOURCE = 43;

        public const uint MCAST_UNBLOCK_SOURCE = 44;

        public const uint MCAST_JOIN_SOURCE_GROUP = 45;

        public const uint MCAST_LEAVE_SOURCE_GROUP = 46;

        public const uint IPV6_HOPOPTS = 1;

        public const uint IPV6_HDRINCL = 2;

        public const uint IPV6_UNICAST_HOPS = 4;

        public const uint IPV6_MULTICAST_IF = 9;

        public const uint IPV6_MULTICAST_HOPS = 10;

        public const uint IPV6_MULTICAST_LOOP = 11;

        public const uint IPV6_ADD_MEMBERSHIP = 12;

        public const uint IPV6_DROP_MEMBERSHIP = 13;

        public const uint IPV6_DONTFRAG = 14;

        public const uint IPV6_PKTINFO = 19;

        public const uint IPV6_HOPLIMIT = 21;

        public const uint IPV6_PROTECTION_LEVEL = 23;

        public const uint IPV6_RECVIF = 24;

        public const uint IPV6_RECVDSTADDR = 25;

        public const uint IPV6_CHECKSUM = 26;

        public const uint IPV6_V6ONLY = 27;

        public const uint IPV6_IFLIST = 28;

        public const uint IPV6_ADD_IFLIST = 29;

        public const uint IPV6_DEL_IFLIST = 30;

        public const uint IPV6_UNICAST_IF = 31;

        public const uint IPV6_RTHDR = 32;

        public const uint IPV6_GET_IFLIST = 33;

        public const uint IPV6_RECVRTHDR = 38;

        public const uint IPV6_TCLASS = 39;

        public const uint IPV6_RECVTCLASS = 40;

        public const uint IPV6_ECN = 50;

        public const uint IPV6_PKTINFO_EX = 51;

        public const uint IPV6_WFP_REDIRECT_RECORDS = 60;

        public const uint IPV6_WFP_REDIRECT_CONTEXT = 70;

        public const uint IPV6_MTU_DISCOVER = 71;

        public const uint IPV6_MTU = 72;

        public const uint IPV6_NRT_INTERFACE = 74;

        public const uint IPV6_RECVERR = 75;

        public const uint IPV6_USER_MTU = 76;

        public const int IP_UNSPECIFIED_HOP_LIMIT = -1;

        public const uint PROTECTION_LEVEL_UNRESTRICTED = 10;

        public const uint PROTECTION_LEVEL_EDGERESTRICTED = 20;

        public const uint PROTECTION_LEVEL_RESTRICTED = 30;

        public const uint INET_ADDRSTRLEN = 22;

        public const uint INET6_ADDRSTRLEN = 65;

        public const uint TCP_OFFLOAD_NO_PREFERENCE = 0;

        public const uint TCP_OFFLOAD_NOT_PREFERRED = 1;

        public const uint TCP_OFFLOAD_PREFERRED = 2;

        public const uint TCP_EXPEDITED_1122 = 0x0002;

        public const uint TCP_KEEPALIVE = 3;

        public const uint TCP_MAXSEG = 4;

        public const uint TCP_MAXRT = 5;

        public const uint TCP_STDURG = 6;

        public const uint TCP_NOURG = 7;

        public const uint TCP_ATMARK = 8;

        public const uint TCP_NOSYNRETRIES = 9;

        public const uint TCP_TIMESTAMPS = 10;

        public const uint TCP_OFFLOAD_PREFERENCE = 11;

        public const uint TCP_CONGESTION_ALGORITHM = 12;

        public const uint TCP_DELAY_FIN_ACK = 13;

        public const uint TCP_MAXRTMS = 14;

        public const uint TCP_FASTOPEN = 15;

        public const uint TCP_KEEPCNT = 16;

        public const uint TCP_KEEPINTVL = 17;

        public const uint TCP_FAIL_CONNECT_ON_ICMP_ERROR = 18;

        public const uint TCP_ICMP_ERROR_INFO = 19;

        public const uint UDP_SEND_MSG_SIZE = 2;

        public const uint UDP_RECV_MAX_COALESCED_SIZE = 3;

        public const uint UDP_COALESCED_INFO = 3;

        public const uint WINDOWS_AF_IRDA = 26;

        public const uint WCE_AF_IRDA = 22;

        public const uint IRDA_PROTO_SOCK_STREAM = 1;

        public const uint SOL_IRLMP = 0x00FF;

        public const uint IRLMP_ENUMDEVICES = 0x00000010;

        public const uint IRLMP_IAS_SET = 0x00000011;

        public const uint IRLMP_IAS_QUERY = 0x00000012;

        public const uint IRLMP_SEND_PDU_LEN = 0x00000013;

        public const uint IRLMP_EXCLUSIVE_MODE = 0x00000014;

        public const uint IRLMP_IRLPT_MODE = 0x00000015;

        public const uint IRLMP_9WIRE_MODE = 0x00000016;

        public const uint IRLMP_TINYTP_MODE = 0x00000017;

        public const uint IRLMP_PARAMETERS = 0x00000018;

        public const uint IRLMP_DISCOVERY_MODE = 0x00000019;

        public const uint IRLMP_SHARP_MODE = 0x00000020;

        public const uint IAS_ATTRIB_NO_CLASS = 0x00000010;

        public const uint IAS_ATTRIB_NO_ATTRIB = 0x00000000;

        public const uint IAS_ATTRIB_INT = 0x00000001;

        public const uint IAS_ATTRIB_OCTETSEQ = 0x00000002;

        public const uint IAS_ATTRIB_STR = 0x00000003;

        public const uint IAS_MAX_USER_STRING = 256;

        public const uint IAS_MAX_OCTET_STRING = 1024;

        public const uint IAS_MAX_CLASSNAME = 64;

        public const uint IAS_MAX_ATTRIBNAME = 256;

        public const uint LmCharSetASCII = 0;

        public const uint LmCharSetISO_8859_1 = 1;

        public const uint LmCharSetISO_8859_2 = 2;

        public const uint LmCharSetISO_8859_3 = 3;

        public const uint LmCharSetISO_8859_4 = 4;

        public const uint LmCharSetISO_8859_5 = 5;

        public const uint LmCharSetISO_8859_6 = 6;

        public const uint LmCharSetISO_8859_7 = 7;

        public const uint LmCharSetISO_8859_8 = 8;

        public const uint LmCharSetISO_8859_9 = 9;

        public const uint LmCharSetUNICODE = 0xff;

        public const uint LM_BAUD_1200 = 1200;

        public const uint LM_BAUD_2400 = 2400;

        public const uint LM_BAUD_9600 = 9600;

        public const uint LM_BAUD_19200 = 19200;

        public const uint LM_BAUD_38400 = 38400;

        public const uint LM_BAUD_57600 = 57600;

        public const uint LM_BAUD_115200 = 115200;

        public const uint LM_BAUD_576K = 576000;

        public const uint LM_BAUD_1152K = 1152000;

        public const uint LM_BAUD_4M = 4000000;

        public const uint LM_BAUD_16M = 16000000;

        public const uint SO_CONNDATA = 0x7000;

        public const uint SO_CONNOPT = 0x7001;

        public const uint SO_DISCDATA = 0x7002;

        public const uint SO_DISCOPT = 0x7003;

        public const uint SO_CONNDATALEN = 0x7004;

        public const uint SO_CONNOPTLEN = 0x7005;

        public const uint SO_DISCDATALEN = 0x7006;

        public const uint SO_DISCOPTLEN = 0x7007;

        public const uint SO_OPENTYPE = 0x7008;

        public const uint SO_SYNCHRONOUS_ALERT = 0x10;

        public const uint SO_SYNCHRONOUS_NONALERT = 0x20;

        public const uint SO_MAXDG = 0x7009;

        public const uint SO_MAXPATHDG = 0x700A;

        public const uint SO_UPDATE_ACCEPT_CONTEXT = 0x700B;

        public const uint SO_CONNECT_TIME = 0x700C;

        public const uint SO_UPDATE_CONNECT_CONTEXT = 0x7010;

        public const uint TCP_BSDURGENT = 0x7000;

        public const uint TF_DISCONNECT = 0x01;

        public const uint TF_REUSE_SOCKET = 0x02;

        public const uint TF_WRITE_BEHIND = 0x04;

        public const uint TF_USE_DEFAULT_WORKER = 0x00;

        public const uint TF_USE_SYSTEM_THREAD = 0x10;

        public const uint TF_USE_KERNEL_APC = 0x20;

        public const uint TP_ELEMENT_MEMORY = 1;

        public const uint TP_ELEMENT_FILE = 2;

        public const uint TP_ELEMENT_EOP = 4;

        public const uint NLA_ALLUSERS_NETWORK = 0x00000001;

        public const uint NLA_FRIENDLY_NAME = 0x00000002;

        public const uint SERVICE_RESOURCE = 0x00000001;

        public const uint SERVICE_SERVICE = 0x00000002;

        public const uint SERVICE_LOCAL = 0x00000004;

        public const uint SERVICE_FLAG_DEFER = 0x00000001;

        public const uint SERVICE_FLAG_HARD = 0x00000002;

        public const uint PROP_COMMENT = 0x00000001;

        public const uint PROP_LOCALE = 0x00000002;

        public const uint PROP_DISPLAY_HINT = 0x00000004;

        public const uint PROP_VERSION = 0x00000008;

        public const uint PROP_START_TIME = 0x00000010;

        public const uint PROP_MACHINE = 0x00000020;

        public const uint PROP_ADDRESSES = 0x00000100;

        public const uint PROP_SD = 0x00000200;

        public const uint PROP_ALL = 0x80000000;

        public const uint SERVICE_ADDRESS_FLAG_RPC_CN = 0x00000001;

        public const uint SERVICE_ADDRESS_FLAG_RPC_DG = 0x00000002;

        public const uint SERVICE_ADDRESS_FLAG_RPC_NB = 0x00000004;

        public const uint NS_DEFAULT = 0;

        public const uint NS_VNS = 50;

        public const uint NSTYPE_HIERARCHICAL = 0x00000001;

        public const uint NSTYPE_DYNAMIC = 0x00000002;

        public const uint NSTYPE_ENUMERABLE = 0x00000004;

        public const uint NSTYPE_WORKGROUP = 0x00000008;

        public const uint XP_CONNECTIONLESS = 0x00000001;

        public const uint XP_GUARANTEED_DELIVERY = 0x00000002;

        public const uint XP_GUARANTEED_ORDER = 0x00000004;

        public const uint XP_MESSAGE_ORIENTED = 0x00000008;

        public const uint XP_PSEUDO_STREAM = 0x00000010;

        public const uint XP_GRACEFUL_CLOSE = 0x00000020;

        public const uint XP_EXPEDITED_DATA = 0x00000040;

        public const uint XP_CONNECT_DATA = 0x00000080;

        public const uint XP_DISCONNECT_DATA = 0x00000100;

        public const uint XP_SUPPORTS_BROADCAST = 0x00000200;

        public const uint XP_SUPPORTS_MULTICAST = 0x00000400;

        public const uint XP_BANDWIDTH_ALLOCATION = 0x00000800;

        public const uint XP_FRAGMENTATION = 0x00001000;

        public const uint XP_ENCRYPTS = 0x00002000;

        public const uint RES_SOFT_SEARCH = 0x00000001;

        public const uint RES_FIND_MULTIPLE = 0x00000002;

        public const uint RES_SERVICE = 0x00000004;

        public const uint SET_SERVICE_PARTIAL_SUCCESS = 0x00000001;

        public const uint FD_SETSIZE = 64;

        public const uint IPPROTO_ICMP = 1;

        public const uint IPPROTO_IGMP = 2;

        public const uint IPPROTO_GGP = 3;

        public const uint IPPROTO_TCP = 6;

        public const uint IPPROTO_PUP = 12;

        public const uint IPPROTO_UDP = 17;

        public const uint IPPROTO_IDP = 22;

        public const uint IPPROTO_ND = 77;

        public const uint IPPROTO_RAW = 255;

        public const uint IPPROTO_MAX = 256;

        public const uint IMPLINK_IP = 155;

        public const uint IMPLINK_LOWEXPER = 156;

        public const uint IMPLINK_HIGHEXPER = 158;

        public const uint WSADESCRIPTION_LEN = 256;

        public const uint WSASYS_STATUS_LEN = 128;

        public const uint IP_DEFAULT_MULTICAST_TTL = 1;

        public const uint IP_DEFAULT_MULTICAST_LOOP = 1;

        public const uint IP_MAX_MEMBERSHIPS = 20;

        public const int SOCKET_ERROR = -1;

        public const ushort AF_IPX = 6;

        public const uint SOMAXCONN = 5;

        public const uint MSG_PEEK = 0x2;

        public const uint MSG_MAXIOVLEN = 16;

        public const uint MSG_PARTIAL = 0x8000;

        public const uint MAXGETHOSTSTRUCT = 1024;

        public const uint FD_READ = 0x01;

        public const uint FD_WRITE = 0x02;

        public const uint FD_OOB = 0x04;

        public const uint FD_ACCEPT = 0x08;

        public const uint FD_CONNECT = 0x10;

        public const uint FD_CLOSE = 0x20;

        public const uint INCL_WINSOCK_API_PROTOTYPES = 1;

        public const uint INCL_WINSOCK_API_TYPEDEFS = 0;

        public const int FROM_PROTOCOL_INFO = -1;

        public const uint SO_PROTOCOL_INFOA = 0x2004;

        public const uint SO_PROTOCOL_INFOW = 0x2005;

        public const uint PVD_CONFIG = 0x3001;

        public const uint MSG_WAITALL = 0x8;

        public const uint MSG_PUSH_IMMEDIATE = 0x20;

        public const uint MSG_INTERRUPT = 0x10;

        public const uint FD_READ_BIT = 0;

        public const uint FD_WRITE_BIT = 1;

        public const uint FD_OOB_BIT = 2;

        public const uint FD_ACCEPT_BIT = 3;

        public const uint FD_CONNECT_BIT = 4;

        public const uint FD_CLOSE_BIT = 5;

        public const uint FD_QOS_BIT = 6;

        public const uint FD_GROUP_QOS_BIT = 7;

        public const uint FD_ROUTING_INTERFACE_CHANGE_BIT = 8;

        public const uint FD_ADDRESS_LIST_CHANGE_BIT = 9;

        public const uint FD_MAX_EVENTS = 10;

        public const uint WSA_WAIT_FAILED = 0xFFFFFFFF;

        public const uint WSA_INFINITE = 0xFFFFFFFF;

        public const uint CF_ACCEPT = 0x0000;

        public const uint CF_REJECT = 0x0001;

        public const uint CF_DEFER = 0x0002;

        public const uint SD_RECEIVE = 0x00;

        public const uint SD_SEND = 0x01;

        public const uint SD_BOTH = 0x02;

        public const uint SG_UNCONSTRAINED_GROUP = 0x01;

        public const uint SG_CONSTRAINED_GROUP = 0x02;

        public const uint MAX_PROTOCOL_CHAIN = 7;

        public const uint BASE_PROTOCOL = 1;

        public const uint LAYERED_PROTOCOL = 0;

        public const uint WSAPROTOCOL_LEN = 255;

        public const uint PFL_MULTIPLE_PROTO_ENTRIES = 0x00000001;

        public const uint PFL_RECOMMENDED_PROTO_ENTRY = 0x00000002;

        public const uint PFL_HIDDEN = 0x00000004;

        public const uint PFL_MATCHES_PROTOCOL_ZERO = 0x00000008;

        public const uint PFL_NETWORKDIRECT_PROVIDER = 0x00000010;

        public const uint XP1_CONNECTIONLESS = 0x00000001;

        public const uint XP1_GUARANTEED_DELIVERY = 0x00000002;

        public const uint XP1_GUARANTEED_ORDER = 0x00000004;

        public const uint XP1_MESSAGE_ORIENTED = 0x00000008;

        public const uint XP1_PSEUDO_STREAM = 0x00000010;

        public const uint XP1_GRACEFUL_CLOSE = 0x00000020;

        public const uint XP1_EXPEDITED_DATA = 0x00000040;

        public const uint XP1_CONNECT_DATA = 0x00000080;

        public const uint XP1_DISCONNECT_DATA = 0x00000100;

        public const uint XP1_SUPPORT_BROADCAST = 0x00000200;

        public const uint XP1_SUPPORT_MULTIPOINT = 0x00000400;

        public const uint XP1_MULTIPOINT_CONTROL_PLANE = 0x00000800;

        public const uint XP1_MULTIPOINT_DATA_PLANE = 0x00001000;

        public const uint XP1_QOS_SUPPORTED = 0x00002000;

        public const uint XP1_INTERRUPT = 0x00004000;

        public const uint XP1_UNI_SEND = 0x00008000;

        public const uint XP1_UNI_RECV = 0x00010000;

        public const uint XP1_IFS_HANDLES = 0x00020000;

        public const uint XP1_PARTIAL_MESSAGE = 0x00040000;

        public const uint XP1_SAN_SUPPORT_SDP = 0x00080000;

        public const uint BIGENDIAN = 0x0000;

        public const uint LITTLEENDIAN = 0x0001;

        public const uint SECURITY_PROTOCOL_NONE = 0x0000;

        public const uint JL_SENDER_ONLY = 0x01;

        public const uint JL_RECEIVER_ONLY = 0x02;

        public const uint JL_BOTH = 0x04;

        public const uint WSA_FLAG_OVERLAPPED = 0x01;

        public const uint WSA_FLAG_MULTIPOINT_C_ROOT = 0x02;

        public const uint WSA_FLAG_MULTIPOINT_C_LEAF = 0x04;

        public const uint WSA_FLAG_MULTIPOINT_D_ROOT = 0x08;

        public const uint WSA_FLAG_MULTIPOINT_D_LEAF = 0x10;

        public const uint WSA_FLAG_ACCESS_SYSTEM_SECURITY = 0x40;

        public const uint WSA_FLAG_NO_HANDLE_INHERIT = 0x80;

        public const uint WSA_FLAG_REGISTERED_IO = 0x100;

        public const uint TH_NETDEV = 0x00000001;

        public const uint TH_TAPI = 0x00000002;

        public const uint SERVICE_MULTIPLE = 0x00000001;

        public const uint NS_LOCALNAME = 19;

        public const uint RES_UNUSED_1 = 0x00000001;

        public const uint RES_FLUSH_CACHE = 0x00000002;

        public const uint LUP_DEEP = 0x0001;

        public const uint LUP_CONTAINERS = 0x0002;

        public const uint LUP_NOCONTAINERS = 0x0004;

        public const uint LUP_NEAREST = 0x0008;

        public const uint LUP_RETURN_NAME = 0x0010;

        public const uint LUP_RETURN_TYPE = 0x0020;

        public const uint LUP_RETURN_VERSION = 0x0040;

        public const uint LUP_RETURN_COMMENT = 0x0080;

        public const uint LUP_RETURN_ADDR = 0x0100;

        public const uint LUP_RETURN_BLOB = 0x0200;

        public const uint LUP_RETURN_ALIASES = 0x0400;

        public const uint LUP_RETURN_QUERY_STRING = 0x0800;

        public const uint LUP_RETURN_ALL = 0x0FF0;

        public const uint LUP_RES_SERVICE = 0x8000;

        public const uint LUP_FLUSHCACHE = 0x1000;

        public const uint LUP_FLUSHPREVIOUS = 0x2000;

        public const uint LUP_NON_AUTHORITATIVE = 0x4000;

        public const uint LUP_SECURE = 0x8000;

        public const uint LUP_RETURN_PREFERRED_NAMES = 0x10000;

        public const uint LUP_DNS_ONLY = 0x20000;

        public const uint LUP_ADDRCONFIG = 0x00100000;

        public const uint LUP_DUAL_ADDR = 0x00200000;

        public const uint LUP_FILESERVER = 0x00400000;

        public const uint LUP_DISABLE_IDN_ENCODING = 0x00800000;

        public const uint LUP_API_ANSI = 0x01000000;

        public const uint LUP_RESOLUTION_HANDLE = 0x80000000;

        public const uint RESULT_IS_ALIAS = 0x0001;

        public const uint RESULT_IS_ADDED = 0x0010;

        public const uint RESULT_IS_CHANGED = 0x0020;

        public const uint RESULT_IS_DELETED = 0x0040;

        public const uint POLLRDNORM = 0x0100;

        public const uint POLLRDBAND = 0x0200;

        public const uint POLLPRI = 0x0400;

        public const uint POLLWRNORM = 0x0010;

        public const uint POLLWRBAND = 0x0020;

        public const uint POLLERR = 0x0001;

        public const uint POLLHUP = 0x0002;

        public const uint POLLNVAL = 0x0004;

        public const uint ATMPROTO_AALUSER = 0x00;

        public const uint ATMPROTO_AAL1 = 0x01;

        public const uint ATMPROTO_AAL2 = 0x02;

        public const uint ATMPROTO_AAL34 = 0x03;

        public const uint ATMPROTO_AAL5 = 0x05;

        public const uint SAP_FIELD_ABSENT = 0xFFFFFFFE;

        public const uint SAP_FIELD_ANY = 0xFFFFFFFF;

        public const uint SAP_FIELD_ANY_AESA_SEL = 0xFFFFFFFA;

        public const uint SAP_FIELD_ANY_AESA_REST = 0xFFFFFFFB;

        public const uint ATM_E164 = 0x01;

        public const uint ATM_NSAP = 0x02;

        public const uint ATM_AESA = 0x02;

        public const uint ATM_ADDR_SIZE = 20;

        public const uint BLLI_L2_ISO_1745 = 0x01;

        public const uint BLLI_L2_Q921 = 0x02;

        public const uint BLLI_L2_X25L = 0x06;

        public const uint BLLI_L2_X25M = 0x07;

        public const uint BLLI_L2_ELAPB = 0x08;

        public const uint BLLI_L2_HDLC_ARM = 0x09;

        public const uint BLLI_L2_HDLC_NRM = 0x0A;

        public const uint BLLI_L2_HDLC_ABM = 0x0B;

        public const uint BLLI_L2_LLC = 0x0C;

        public const uint BLLI_L2_X75 = 0x0D;

        public const uint BLLI_L2_Q922 = 0x0E;

        public const uint BLLI_L2_USER_SPECIFIED = 0x10;

        public const uint BLLI_L2_ISO_7776 = 0x11;

        public const uint BLLI_L3_X25 = 0x06;

        public const uint BLLI_L3_ISO_8208 = 0x07;

        public const uint BLLI_L3_X223 = 0x08;

        public const uint BLLI_L3_SIO_8473 = 0x09;

        public const uint BLLI_L3_T70 = 0x0A;

        public const uint BLLI_L3_ISO_TR9577 = 0x0B;

        public const uint BLLI_L3_USER_SPECIFIED = 0x10;

        public const uint BLLI_L3_IPI_SNAP = 0x80;

        public const uint BLLI_L3_IPI_IP = 0xCC;

        public const uint BHLI_ISO = 0x00;

        public const uint BHLI_UserSpecific = 0x01;

        public const uint BHLI_HighLayerProfile = 0x02;

        public const uint BHLI_VendorSpecificAppId = 0x03;

        public const uint AAL5_MODE_MESSAGE = 0x01;

        public const uint AAL5_MODE_STREAMING = 0x02;

        public const uint AAL5_SSCS_NULL = 0x00;

        public const uint AAL5_SSCS_SSCOP_ASSURED = 0x01;

        public const uint AAL5_SSCS_SSCOP_NON_ASSURED = 0x02;

        public const uint AAL5_SSCS_FRAME_RELAY = 0x04;

        public const uint BCOB_A = 0x01;

        public const uint BCOB_C = 0x03;

        public const uint BCOB_X = 0x10;

        public const uint TT_NOIND = 0x00;

        public const uint TT_CBR = 0x04;

        public const uint TT_VBR = 0x08;

        public const uint TR_NOIND = 0x00;

        public const uint TR_END_TO_END = 0x01;

        public const uint TR_NO_END_TO_END = 0x02;

        public const uint CLIP_NOT = 0x00;

        public const uint CLIP_SUS = 0x20;

        public const uint UP_P2P = 0x00;

        public const uint UP_P2MP = 0x01;

        public const uint BLLI_L2_MODE_NORMAL = 0x40;

        public const uint BLLI_L2_MODE_EXT = 0x80;

        public const uint BLLI_L3_MODE_NORMAL = 0x40;

        public const uint BLLI_L3_MODE_EXT = 0x80;

        public const uint BLLI_L3_PACKET_16 = 0x04;

        public const uint BLLI_L3_PACKET_32 = 0x05;

        public const uint BLLI_L3_PACKET_64 = 0x06;

        public const uint BLLI_L3_PACKET_128 = 0x07;

        public const uint BLLI_L3_PACKET_256 = 0x08;

        public const uint BLLI_L3_PACKET_512 = 0x09;

        public const uint BLLI_L3_PACKET_1024 = 0x0A;

        public const uint BLLI_L3_PACKET_2048 = 0x0B;

        public const uint BLLI_L3_PACKET_4096 = 0x0C;

        public const uint PI_ALLOWED = 0x00;

        public const uint PI_RESTRICTED = 0x40;

        public const uint PI_NUMBER_NOT_AVAILABLE = 0x80;

        public const uint SI_USER_NOT_SCREENED = 0x00;

        public const uint SI_USER_PASSED = 0x01;

        public const uint SI_USER_FAILED = 0x02;

        public const uint SI_NETWORK = 0x03;

        public const uint CAUSE_LOC_USER = 0x00;

        public const uint CAUSE_LOC_PRIVATE_LOCAL = 0x01;

        public const uint CAUSE_LOC_PUBLIC_LOCAL = 0x02;

        public const uint CAUSE_LOC_TRANSIT_NETWORK = 0x03;

        public const uint CAUSE_LOC_PUBLIC_REMOTE = 0x04;

        public const uint CAUSE_LOC_PRIVATE_REMOTE = 0x05;

        public const uint CAUSE_LOC_INTERNATIONAL_NETWORK = 0x07;

        public const uint CAUSE_LOC_BEYOND_INTERWORKING = 0x0A;

        public const uint CAUSE_UNALLOCATED_NUMBER = 0x01;

        public const uint CAUSE_NO_ROUTE_TO_TRANSIT_NETWORK = 0x02;

        public const uint CAUSE_NO_ROUTE_TO_DESTINATION = 0x03;

        public const uint CAUSE_VPI_VCI_UNACCEPTABLE = 0x0A;

        public const uint CAUSE_NORMAL_CALL_CLEARING = 0x10;

        public const uint CAUSE_USER_BUSY = 0x11;

        public const uint CAUSE_NO_USER_RESPONDING = 0x12;

        public const uint CAUSE_CALL_REJECTED = 0x15;

        public const uint CAUSE_NUMBER_CHANGED = 0x16;

        public const uint CAUSE_USER_REJECTS_CLIR = 0x17;

        public const uint CAUSE_DESTINATION_OUT_OF_ORDER = 0x1B;

        public const uint CAUSE_INVALID_NUMBER_FORMAT = 0x1C;

        public const uint CAUSE_STATUS_ENQUIRY_RESPONSE = 0x1E;

        public const uint CAUSE_NORMAL_UNSPECIFIED = 0x1F;

        public const uint CAUSE_VPI_VCI_UNAVAILABLE = 0x23;

        public const uint CAUSE_NETWORK_OUT_OF_ORDER = 0x26;

        public const uint CAUSE_TEMPORARY_FAILURE = 0x29;

        public const uint CAUSE_ACCESS_INFORMAION_DISCARDED = 0x2B;

        public const uint CAUSE_NO_VPI_VCI_AVAILABLE = 0x2D;

        public const uint CAUSE_RESOURCE_UNAVAILABLE = 0x2F;

        public const uint CAUSE_QOS_UNAVAILABLE = 0x31;

        public const uint CAUSE_USER_CELL_RATE_UNAVAILABLE = 0x33;

        public const uint CAUSE_BEARER_CAPABILITY_UNAUTHORIZED = 0x39;

        public const uint CAUSE_BEARER_CAPABILITY_UNAVAILABLE = 0x3A;

        public const uint CAUSE_OPTION_UNAVAILABLE = 0x3F;

        public const uint CAUSE_BEARER_CAPABILITY_UNIMPLEMENTED = 0x41;

        public const uint CAUSE_UNSUPPORTED_TRAFFIC_PARAMETERS = 0x49;

        public const uint CAUSE_INVALID_CALL_REFERENCE = 0x51;

        public const uint CAUSE_CHANNEL_NONEXISTENT = 0x52;

        public const uint CAUSE_INCOMPATIBLE_DESTINATION = 0x58;

        public const uint CAUSE_INVALID_ENDPOINT_REFERENCE = 0x59;

        public const uint CAUSE_INVALID_TRANSIT_NETWORK_SELECTION = 0x5B;

        public const uint CAUSE_TOO_MANY_PENDING_ADD_PARTY = 0x5C;

        public const uint CAUSE_AAL_PARAMETERS_UNSUPPORTED = 0x5D;

        public const uint CAUSE_MANDATORY_IE_MISSING = 0x60;

        public const uint CAUSE_UNIMPLEMENTED_MESSAGE_TYPE = 0x61;

        public const uint CAUSE_UNIMPLEMENTED_IE = 0x63;

        public const uint CAUSE_INVALID_IE_CONTENTS = 0x64;

        public const uint CAUSE_INVALID_STATE_FOR_MESSAGE = 0x65;

        public const uint CAUSE_RECOVERY_ON_TIMEOUT = 0x66;

        public const uint CAUSE_INCORRECT_MESSAGE_LENGTH = 0x68;

        public const uint CAUSE_PROTOCOL_ERROR = 0x6F;

        public const uint CAUSE_COND_UNKNOWN = 0x00;

        public const uint CAUSE_COND_PERMANENT = 0x01;

        public const uint CAUSE_COND_TRANSIENT = 0x02;

        public const uint CAUSE_REASON_USER = 0x00;

        public const uint CAUSE_REASON_IE_MISSING = 0x04;

        public const uint CAUSE_REASON_IE_INSUFFICIENT = 0x08;

        public const uint CAUSE_PU_PROVIDER = 0x00;

        public const uint CAUSE_PU_USER = 0x08;

        public const uint CAUSE_NA_NORMAL = 0x00;

        public const uint CAUSE_NA_ABNORMAL = 0x04;

        public const uint QOS_CLASS0 = 0x00;

        public const uint QOS_CLASS1 = 0x01;

        public const uint QOS_CLASS2 = 0x02;

        public const uint QOS_CLASS3 = 0x03;

        public const uint QOS_CLASS4 = 0x04;

        public const uint TNS_TYPE_NATIONAL = 0x40;

        public const uint TNS_PLAN_CARRIER_ID_CODE = 0x01;

        public const uint SIO_GET_NUMBER_OF_ATM_DEVICES = 0x50160001;

        public const uint SIO_GET_ATM_ADDRESS = 0xd0160002;

        public const uint SIO_ASSOCIATE_PVC = 0x90160003;

        public const uint SIO_GET_ATM_CONNECTION_ID = 0x50160004;

        public const uint WSPDESCRIPTION_LEN = 255;

        public const int WSS_OPERATION_IN_PROGRESS = 0x00000103;

        public const uint LSP_SYSTEM = 0x80000000;

        public const uint LSP_INSPECTOR = 0x00000001;

        public const uint LSP_REDIRECTOR = 0x00000002;

        public const uint LSP_PROXY = 0x00000004;

        public const uint LSP_FIREWALL = 0x00000008;

        public const uint LSP_INBOUND_MODIFY = 0x00000010;

        public const uint LSP_OUTBOUND_MODIFY = 0x00000020;

        public const uint LSP_CRYPTO_COMPRESS = 0x00000040;

        public const uint LSP_LOCAL_CACHE = 0x00000080;

        public const uint UDP_NOCHECKSUM = 1;

        public const uint UDP_CHECKSUM_COVERAGE = 20;

        public const uint GAI_STRERROR_BUFFER_SIZE = 1024;

        public const uint IPX_PTYPE = 0x4000;

        public const uint IPX_FILTERPTYPE = 0x4001;

        public const uint IPX_STOPFILTERPTYPE = 0x4003;

        public const uint IPX_DSTYPE = 0x4002;

        public const uint IPX_EXTENDED_ADDRESS = 0x4004;

        public const uint IPX_RECVHDR = 0x4005;

        public const uint IPX_MAXSIZE = 0x4006;

        public const uint IPX_ADDRESS = 0x4007;

        public const uint IPX_GETNETINFO = 0x4008;

        public const uint IPX_GETNETINFO_NORIP = 0x4009;

        public const uint IPX_SPXGETCONNECTIONSTATUS = 0x400B;

        public const uint IPX_ADDRESS_NOTIFY = 0x400C;

        public const uint IPX_MAX_ADAPTER_NUM = 0x400D;

        public const uint IPX_RERIPNETNUMBER = 0x400E;

        public const uint IPX_RECEIVE_BROADCAST = 0x400F;

        public const uint IPX_IMMEDIATESPXACK = 0x4010;

        public const uint IPPROTO_RM = 113;

        public const uint MAX_MCAST_TTL = 255;

        public const uint RM_OPTIONSBASE = 1000;

        public const uint RM_RATE_WINDOW_SIZE = RM_OPTIONSBASE + 1;

        public const uint RM_SET_MESSAGE_BOUNDARY = RM_OPTIONSBASE + 2;

        public const uint RM_FLUSHCACHE = RM_OPTIONSBASE + 3;

        public const uint RM_SENDER_WINDOW_ADVANCE_METHOD = RM_OPTIONSBASE + 4;

        public const uint RM_SENDER_STATISTICS = RM_OPTIONSBASE + 5;

        public const uint RM_LATEJOIN = RM_OPTIONSBASE + 6;

        public const uint RM_SET_SEND_IF = RM_OPTIONSBASE + 7;

        public const uint RM_ADD_RECEIVE_IF = RM_OPTIONSBASE + 8;

        public const uint RM_DEL_RECEIVE_IF = RM_OPTIONSBASE + 9;

        public const uint RM_SEND_WINDOW_ADV_RATE = RM_OPTIONSBASE + 10;

        public const uint RM_USE_FEC = RM_OPTIONSBASE + 11;

        public const uint RM_SET_MCAST_TTL = RM_OPTIONSBASE + 12;

        public const uint RM_RECEIVER_STATISTICS = RM_OPTIONSBASE + 13;

        public const uint RM_HIGH_SPEED_INTRANET_OPT = RM_OPTIONSBASE + 14;

        public const uint SENDER_DEFAULT_RATE_KBITS_PER_SEC = 56;

        public const uint SENDER_DEFAULT_WINDOW_ADV_PERCENTAGE = 15;

        public const uint MAX_WINDOW_INCREMENT_PERCENTAGE = 25;

        public const uint SENDER_DEFAULT_LATE_JOINER_PERCENTAGE = 0;

        public const uint SENDER_MAX_LATE_JOINER_PERCENTAGE = 75;

        public const uint BITS_PER_BYTE = 8;

        public const uint LOG2_BITS_PER_BYTE = 3;

    }
}
