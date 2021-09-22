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


namespace Windows.Win32.NetworkManagement.Dhcp
{
    public static partial class Apis
    {
        public const uint OPTION_PAD = 0;

        public const uint OPTION_SUBNET_MASK = 1;

        public const uint OPTION_TIME_OFFSET = 2;

        public const uint OPTION_ROUTER_ADDRESS = 3;

        public const uint OPTION_TIME_SERVERS = 4;

        public const uint OPTION_IEN116_NAME_SERVERS = 5;

        public const uint OPTION_DOMAIN_NAME_SERVERS = 6;

        public const uint OPTION_LOG_SERVERS = 7;

        public const uint OPTION_COOKIE_SERVERS = 8;

        public const uint OPTION_LPR_SERVERS = 9;

        public const uint OPTION_IMPRESS_SERVERS = 10;

        public const uint OPTION_RLP_SERVERS = 11;

        public const uint OPTION_HOST_NAME = 12;

        public const uint OPTION_BOOT_FILE_SIZE = 13;

        public const uint OPTION_MERIT_DUMP_FILE = 14;

        public const uint OPTION_DOMAIN_NAME = 15;

        public const uint OPTION_SWAP_SERVER = 16;

        public const uint OPTION_ROOT_DISK = 17;

        public const uint OPTION_EXTENSIONS_PATH = 18;

        public const uint OPTION_BE_A_ROUTER = 19;

        public const uint OPTION_NON_LOCAL_SOURCE_ROUTING = 20;

        public const uint OPTION_POLICY_FILTER_FOR_NLSR = 21;

        public const uint OPTION_MAX_REASSEMBLY_SIZE = 22;

        public const uint OPTION_DEFAULT_TTL = 23;

        public const uint OPTION_PMTU_AGING_TIMEOUT = 24;

        public const uint OPTION_PMTU_PLATEAU_TABLE = 25;

        public const uint OPTION_MTU = 26;

        public const uint OPTION_ALL_SUBNETS_MTU = 27;

        public const uint OPTION_BROADCAST_ADDRESS = 28;

        public const uint OPTION_PERFORM_MASK_DISCOVERY = 29;

        public const uint OPTION_BE_A_MASK_SUPPLIER = 30;

        public const uint OPTION_PERFORM_ROUTER_DISCOVERY = 31;

        public const uint OPTION_ROUTER_SOLICITATION_ADDR = 32;

        public const uint OPTION_STATIC_ROUTES = 33;

        public const uint OPTION_TRAILERS = 34;

        public const uint OPTION_ARP_CACHE_TIMEOUT = 35;

        public const uint OPTION_ETHERNET_ENCAPSULATION = 36;

        public const uint OPTION_TTL = 37;

        public const uint OPTION_KEEP_ALIVE_INTERVAL = 38;

        public const uint OPTION_KEEP_ALIVE_DATA_SIZE = 39;

        public const uint OPTION_NETWORK_INFO_SERVICE_DOM = 40;

        public const uint OPTION_NETWORK_INFO_SERVERS = 41;

        public const uint OPTION_NETWORK_TIME_SERVERS = 42;

        public const uint OPTION_VENDOR_SPEC_INFO = 43;

        public const uint OPTION_NETBIOS_NAME_SERVER = 44;

        public const uint OPTION_NETBIOS_DATAGRAM_SERVER = 45;

        public const uint OPTION_NETBIOS_NODE_TYPE = 46;

        public const uint OPTION_NETBIOS_SCOPE_OPTION = 47;

        public const uint OPTION_XWINDOW_FONT_SERVER = 48;

        public const uint OPTION_XWINDOW_DISPLAY_MANAGER = 49;

        public const uint OPTION_REQUESTED_ADDRESS = 50;

        public const uint OPTION_LEASE_TIME = 51;

        public const uint OPTION_OK_TO_OVERLAY = 52;

        public const uint OPTION_MESSAGE_TYPE = 53;

        public const uint OPTION_SERVER_IDENTIFIER = 54;

        public const uint OPTION_PARAMETER_REQUEST_LIST = 55;

        public const uint OPTION_MESSAGE = 56;

        public const uint OPTION_MESSAGE_LENGTH = 57;

        public const uint OPTION_RENEWAL_TIME = 58;

        public const uint OPTION_REBIND_TIME = 59;

        public const uint OPTION_CLIENT_CLASS_INFO = 60;

        public const uint OPTION_CLIENT_ID = 61;

        public const uint OPTION_TFTP_SERVER_NAME = 66;

        public const uint OPTION_BOOTFILE_NAME = 67;

        public const uint OPTION_MSFT_IE_PROXY = 252;

        public const uint OPTION_END = 255;

        public const uint DHCPCAPI_REQUEST_PERSISTENT = 0x01;

        public const uint DHCPCAPI_REQUEST_SYNCHRONOUS = 0x02;

        public const uint DHCPCAPI_REQUEST_ASYNCHRONOUS = 0x04;

        public const uint DHCPCAPI_REQUEST_CANCEL = 0x08;

        public const uint DHCPCAPI_REQUEST_MASK = 0x0F;

        public const uint DHCPCAPI_REGISTER_HANDLE_EVENT = 0x01;

        public const uint DHCPCAPI_DEREGISTER_HANDLE_EVENT = 0x01;

        public const uint ERROR_DHCP_REGISTRY_INIT_FAILED = 0x00004E20;

        public const uint ERROR_DHCP_DATABASE_INIT_FAILED = 0x00004E21;

        public const uint ERROR_DHCP_RPC_INIT_FAILED = 0x00004E22;

        public const uint ERROR_DHCP_NETWORK_INIT_FAILED = 0x00004E23;

        public const uint ERROR_DHCP_SUBNET_EXITS = 0x00004E24;

        public const uint ERROR_DHCP_SUBNET_NOT_PRESENT = 0x00004E25;

        public const uint ERROR_DHCP_PRIMARY_NOT_FOUND = 0x00004E26;

        public const uint ERROR_DHCP_ELEMENT_CANT_REMOVE = 0x00004E27;

        public const uint ERROR_DHCP_OPTION_EXITS = 0x00004E29;

        public const uint ERROR_DHCP_OPTION_NOT_PRESENT = 0x00004E2A;

        public const uint ERROR_DHCP_ADDRESS_NOT_AVAILABLE = 0x00004E2B;

        public const uint ERROR_DHCP_RANGE_FULL = 0x00004E2C;

        public const uint ERROR_DHCP_JET_ERROR = 0x00004E2D;

        public const uint ERROR_DHCP_CLIENT_EXISTS = 0x00004E2E;

        public const uint ERROR_DHCP_INVALID_DHCP_MESSAGE = 0x00004E2F;

        public const uint ERROR_DHCP_INVALID_DHCP_CLIENT = 0x00004E30;

        public const uint ERROR_DHCP_SERVICE_PAUSED = 0x00004E31;

        public const uint ERROR_DHCP_NOT_RESERVED_CLIENT = 0x00004E32;

        public const uint ERROR_DHCP_RESERVED_CLIENT = 0x00004E33;

        public const uint ERROR_DHCP_RANGE_TOO_SMALL = 0x00004E34;

        public const uint ERROR_DHCP_IPRANGE_EXITS = 0x00004E35;

        public const uint ERROR_DHCP_RESERVEDIP_EXITS = 0x00004E36;

        public const uint ERROR_DHCP_INVALID_RANGE = 0x00004E37;

        public const uint ERROR_DHCP_RANGE_EXTENDED = 0x00004E38;

        public const uint ERROR_EXTEND_TOO_SMALL = 0x00004E39;

        public const int WARNING_EXTENDED_LESS = 0x00004E3A;

        public const uint ERROR_DHCP_JET_CONV_REQUIRED = 0x00004E3B;

        public const uint ERROR_SERVER_INVALID_BOOT_FILE_TABLE = 0x00004E3C;

        public const uint ERROR_SERVER_UNKNOWN_BOOT_FILE_NAME = 0x00004E3D;

        public const uint ERROR_DHCP_SUPER_SCOPE_NAME_TOO_LONG = 0x00004E3E;

        public const uint ERROR_DHCP_IP_ADDRESS_IN_USE = 0x00004E40;

        public const uint ERROR_DHCP_LOG_FILE_PATH_TOO_LONG = 0x00004E41;

        public const uint ERROR_DHCP_UNSUPPORTED_CLIENT = 0x00004E42;

        public const uint ERROR_DHCP_JET97_CONV_REQUIRED = 0x00004E44;

        public const uint ERROR_DHCP_ROGUE_INIT_FAILED = 0x00004E45;

        public const uint ERROR_DHCP_ROGUE_SAMSHUTDOWN = 0x00004E46;

        public const uint ERROR_DHCP_ROGUE_NOT_AUTHORIZED = 0x00004E47;

        public const uint ERROR_DHCP_ROGUE_DS_UNREACHABLE = 0x00004E48;

        public const uint ERROR_DHCP_ROGUE_DS_CONFLICT = 0x00004E49;

        public const uint ERROR_DHCP_ROGUE_NOT_OUR_ENTERPRISE = 0x00004E4A;

        public const uint ERROR_DHCP_ROGUE_STANDALONE_IN_DS = 0x00004E4B;

        public const uint ERROR_DHCP_CLASS_NOT_FOUND = 0x00004E4C;

        public const uint ERROR_DHCP_CLASS_ALREADY_EXISTS = 0x00004E4D;

        public const uint ERROR_DHCP_SCOPE_NAME_TOO_LONG = 0x00004E4E;

        public const uint ERROR_DHCP_DEFAULT_SCOPE_EXITS = 0x00004E4F;

        public const uint ERROR_DHCP_CANT_CHANGE_ATTRIBUTE = 0x00004E50;

        public const uint ERROR_DHCP_IPRANGE_CONV_ILLEGAL = 0x00004E51;

        public const uint ERROR_DHCP_NETWORK_CHANGED = 0x00004E52;

        public const uint ERROR_DHCP_CANNOT_MODIFY_BINDINGS = 0x00004E53;

        public const uint ERROR_DHCP_SUBNET_EXISTS = 0x00004E54;

        public const uint ERROR_DHCP_MSCOPE_EXISTS = 0x00004E55;

        public const uint ERROR_MSCOPE_RANGE_TOO_SMALL = 0x00004E56;

        public const uint ERROR_DHCP_EXEMPTION_EXISTS = 0x00004E57;

        public const uint ERROR_DHCP_EXEMPTION_NOT_PRESENT = 0x00004E58;

        public const uint ERROR_DHCP_INVALID_PARAMETER_OPTION32 = 0x00004E59;

        public const uint ERROR_DDS_NO_DS_AVAILABLE = 0x00004E66;

        public const uint ERROR_DDS_NO_DHCP_ROOT = 0x00004E67;

        public const uint ERROR_DDS_UNEXPECTED_ERROR = 0x00004E68;

        public const uint ERROR_DDS_TOO_MANY_ERRORS = 0x00004E69;

        public const uint ERROR_DDS_DHCP_SERVER_NOT_FOUND = 0x00004E6A;

        public const uint ERROR_DDS_OPTION_ALREADY_EXISTS = 0x00004E6B;

        public const uint ERROR_DDS_OPTION_DOES_NOT_EXIST = 0x00004E6C;

        public const uint ERROR_DDS_CLASS_EXISTS = 0x00004E6D;

        public const uint ERROR_DDS_CLASS_DOES_NOT_EXIST = 0x00004E6E;

        public const uint ERROR_DDS_SERVER_ALREADY_EXISTS = 0x00004E6F;

        public const uint ERROR_DDS_SERVER_DOES_NOT_EXIST = 0x00004E70;

        public const uint ERROR_DDS_SERVER_ADDRESS_MISMATCH = 0x00004E71;

        public const uint ERROR_DDS_SUBNET_EXISTS = 0x00004E72;

        public const uint ERROR_DDS_SUBNET_HAS_DIFF_SSCOPE = 0x00004E73;

        public const uint ERROR_DDS_SUBNET_NOT_PRESENT = 0x00004E74;

        public const uint ERROR_DDS_RESERVATION_NOT_PRESENT = 0x00004E75;

        public const uint ERROR_DDS_RESERVATION_CONFLICT = 0x00004E76;

        public const uint ERROR_DDS_POSSIBLE_RANGE_CONFLICT = 0x00004E77;

        public const uint ERROR_DDS_RANGE_DOES_NOT_EXIST = 0x00004E78;

        public const uint ERROR_DHCP_DELETE_BUILTIN_CLASS = 0x00004E79;

        public const uint ERROR_DHCP_INVALID_SUBNET_PREFIX = 0x00004E7B;

        public const uint ERROR_DHCP_INVALID_DELAY = 0x00004E7C;

        public const uint ERROR_DHCP_LINKLAYER_ADDRESS_EXISTS = 0x00004E7D;

        public const uint ERROR_DHCP_LINKLAYER_ADDRESS_RESERVATION_EXISTS = 0x00004E7E;

        public const uint ERROR_DHCP_LINKLAYER_ADDRESS_DOES_NOT_EXIST = 0x00004E7F;

        public const uint ERROR_DHCP_HARDWARE_ADDRESS_TYPE_ALREADY_EXEMPT = 0x00004E85;

        public const uint ERROR_DHCP_UNDEFINED_HARDWARE_ADDRESS_TYPE = 0x00004E86;

        public const uint ERROR_DHCP_OPTION_TYPE_MISMATCH = 0x00004E87;

        public const uint ERROR_DHCP_POLICY_BAD_PARENT_EXPR = 0x00004E88;

        public const uint ERROR_DHCP_POLICY_EXISTS = 0x00004E89;

        public const uint ERROR_DHCP_POLICY_RANGE_EXISTS = 0x00004E8A;

        public const uint ERROR_DHCP_POLICY_RANGE_BAD = 0x00004E8B;

        public const uint ERROR_DHCP_RANGE_INVALID_IN_SERVER_POLICY = 0x00004E8C;

        public const uint ERROR_DHCP_INVALID_POLICY_EXPRESSION = 0x00004E8D;

        public const uint ERROR_DHCP_INVALID_PROCESSING_ORDER = 0x00004E8E;

        public const uint ERROR_DHCP_POLICY_NOT_FOUND = 0x00004E8F;

        public const uint ERROR_SCOPE_RANGE_POLICY_RANGE_CONFLICT = 0x00004E90;

        public const uint ERROR_DHCP_FO_SCOPE_ALREADY_IN_RELATIONSHIP = 0x00004E91;

        public const uint ERROR_DHCP_FO_RELATIONSHIP_EXISTS = 0x00004E92;

        public const uint ERROR_DHCP_FO_RELATIONSHIP_DOES_NOT_EXIST = 0x00004E93;

        public const uint ERROR_DHCP_FO_SCOPE_NOT_IN_RELATIONSHIP = 0x00004E94;

        public const uint ERROR_DHCP_FO_RELATION_IS_SECONDARY = 0x00004E95;

        public const uint ERROR_DHCP_FO_NOT_SUPPORTED = 0x00004E96;

        public const uint ERROR_DHCP_FO_TIME_OUT_OF_SYNC = 0x00004E97;

        public const uint ERROR_DHCP_FO_STATE_NOT_NORMAL = 0x00004E98;

        public const uint ERROR_DHCP_NO_ADMIN_PERMISSION = 0x00004E99;

        public const uint ERROR_DHCP_SERVER_NOT_REACHABLE = 0x00004E9A;

        public const uint ERROR_DHCP_SERVER_NOT_RUNNING = 0x00004E9B;

        public const uint ERROR_DHCP_SERVER_NAME_NOT_RESOLVED = 0x00004E9C;

        public const uint ERROR_DHCP_FO_RELATIONSHIP_NAME_TOO_LONG = 0x00004E9D;

        public const uint ERROR_DHCP_REACHED_END_OF_SELECTION = 0x00004E9E;

        public const uint ERROR_DHCP_FO_ADDSCOPE_LEASES_NOT_SYNCED = 0x00004E9F;

        public const uint ERROR_DHCP_FO_MAX_RELATIONSHIPS = 0x00004EA0;

        public const uint ERROR_DHCP_FO_IPRANGE_TYPE_CONV_ILLEGAL = 0x00004EA1;

        public const uint ERROR_DHCP_FO_MAX_ADD_SCOPES = 0x00004EA2;

        public const uint ERROR_DHCP_FO_BOOT_NOT_SUPPORTED = 0x00004EA3;

        public const uint ERROR_DHCP_FO_RANGE_PART_OF_REL = 0x00004EA4;

        public const uint ERROR_DHCP_FO_SCOPE_SYNC_IN_PROGRESS = 0x00004EA5;

        public const uint ERROR_DHCP_FO_FEATURE_NOT_SUPPORTED = 0x00004EA6;

        public const uint ERROR_DHCP_POLICY_FQDN_RANGE_UNSUPPORTED = 0x00004EA7;

        public const uint ERROR_DHCP_POLICY_FQDN_OPTION_UNSUPPORTED = 0x00004EA8;

        public const uint ERROR_DHCP_POLICY_EDIT_FQDN_UNSUPPORTED = 0x00004EA9;

        public const uint ERROR_DHCP_NAP_NOT_SUPPORTED = 0x00004EAA;

        public const uint ERROR_LAST_DHCP_SERVER_ERROR = 0x00004EAB;

        public const uint DHCP_SUBNET_INFO_VQ_FLAG_QUARANTINE = 1u<< 0;

        public const uint MAX_PATTERN_LENGTH = 255;

        public const uint MAC_ADDRESS_LENGTH = 6;

        public const uint HWTYPE_ETHERNET_10MB = 1;

        public const uint FILTER_STATUS_NONE = 0x00000001;

        public const uint FILTER_STATUS_FULL_MATCH_IN_ALLOW_LIST = 0x00000002;

        public const uint FILTER_STATUS_FULL_MATCH_IN_DENY_LIST = 0x00000004;

        public const uint FILTER_STATUS_WILDCARD_MATCH_IN_ALLOW_LIST = 0x00000008;

        public const uint FILTER_STATUS_WILDCARD_MATCH_IN_DENY_LIST = 0x00000010;

        public const uint Set_APIProtocolSupport = 0x00000001;

        public const uint Set_DatabaseName = 0x00000002;

        public const uint Set_DatabasePath = 0x00000004;

        public const uint Set_BackupPath = 0x00000008;

        public const uint Set_BackupInterval = 0x00000010;

        public const uint Set_DatabaseLoggingFlag = 0x00000020;

        public const uint Set_RestoreFlag = 0x00000040;

        public const uint Set_DatabaseCleanupInterval = 0x00000080;

        public const uint Set_DebugFlag = 0x00000100;

        public const uint Set_PingRetries = 0x00000200;

        public const uint Set_BootFileTable = 0x00000400;

        public const uint Set_AuditLogState = 0x00000800;

        public const uint Set_QuarantineON = 0x00001000;

        public const uint Set_QuarantineDefFail = 0x00002000;

        public const uint CLIENT_TYPE_UNSPECIFIED = 0x0;

        public const uint CLIENT_TYPE_DHCP = 0x1;

        public const uint CLIENT_TYPE_BOOTP = 0x2;

        public const uint CLIENT_TYPE_RESERVATION_FLAG = 0x4;

        public const uint CLIENT_TYPE_NONE = 0x64;

        public const uint Set_UnicastFlag = 0x00000001;

        public const uint Set_RapidCommitFlag = 0x00000002;

        public const uint Set_PreferredLifetime = 0x00000004;

        public const uint Set_ValidLifetime = 0x00000008;

        public const uint Set_T1 = 0x00000010;

        public const uint Set_T2 = 0x00000020;

        public const uint Set_PreferredLifetimeIATA = 0x00000040;

        public const uint Set_ValidLifetimeIATA = 0x00000080;

        public const uint V5_ADDRESS_STATE_OFFERED = 0x0;

        public const uint V5_ADDRESS_STATE_ACTIVE = 0x1;

        public const uint V5_ADDRESS_STATE_DECLINED = 0x2;

        public const uint V5_ADDRESS_STATE_DOOM = 0x3;

        public const uint V5_ADDRESS_BIT_DELETED = 0x80;

        public const uint V5_ADDRESS_BIT_UNREGISTERED = 0x40;

        public const uint V5_ADDRESS_BIT_BOTH_REC = 0x20;

        public const uint V5_ADDRESS_EX_BIT_DISABLE_PTR_RR = 0x01;

        public const uint DNS_FLAG_ENABLED = 0x01;

        public const uint DNS_FLAG_UPDATE_DOWNLEVEL = 0x02;

        public const uint DNS_FLAG_CLEANUP_EXPIRED = 0x04;

        public const uint DNS_FLAG_UPDATE_BOTH_ALWAYS = 0x10;

        public const uint DNS_FLAG_UPDATE_DHCID = 0x20;

        public const uint DNS_FLAG_DISABLE_PTR_UPDATE = 0x40;

        public const uint DNS_FLAG_HAS_DNS_SUFFIX = 0x80;

        public const uint DHCP_OPT_ENUM_IGNORE_VENDOR = 0x01;

        public const uint DHCP_OPT_ENUM_USE_CLASSNAME = 0x02;

        public const uint DHCP_FLAGS_DONT_ACCESS_DS = 0x01;

        public const uint DHCP_FLAGS_DONT_DO_RPC = 0x02;

        public const uint DHCP_FLAGS_OPTION_IS_VENDOR = 0x03;

        public const uint DHCP_ATTRIB_BOOL_IS_ROGUE = 0x01;

        public const uint DHCP_ATTRIB_BOOL_IS_DYNBOOTP = 0x02;

        public const uint DHCP_ATTRIB_BOOL_IS_PART_OF_DSDC = 0x03;

        public const uint DHCP_ATTRIB_BOOL_IS_BINDING_AWARE = 0x04;

        public const uint DHCP_ATTRIB_BOOL_IS_ADMIN = 0x05;

        public const uint DHCP_ATTRIB_ULONG_RESTORE_STATUS = 0x06;

        public const uint DHCP_ATTRIB_TYPE_BOOL = 0x01;

        public const uint DHCP_ATTRIB_TYPE_ULONG = 0x02;

        public const uint DHCP_ENDPOINT_FLAG_CANT_MODIFY = 0x01;

        public const uint QUARANTIN_OPTION_BASE = 43220;

        public const uint QUARANTINE_SCOPE_QUARPROFILE_OPTION = QUARANTIN_OPTION_BASE + 1;

        public const uint QUARANTINE_CONFIG_OPTION = QUARANTIN_OPTION_BASE + 2;

        public const uint ADDRESS_TYPE_IANA = 0;

        public const uint ADDRESS_TYPE_IATA = 1;

        public const uint DHCP_MIN_DELAY = 0;

        public const uint DHCP_MAX_DELAY = 1000;

        public const uint DHCP_FAILOVER_DELETE_SCOPES = 0x00000001;

        public const uint DHCP_FAILOVER_MAX_NUM_ADD_SCOPES = 400;

        public const uint DHCP_FAILOVER_MAX_NUM_REL = 31;

        public const uint MCLT = 0x00000001;

        public const uint SAFEPERIOD = 0x00000002;

        public const uint CHANGESTATE = 0x00000004;

        public const uint PERCENTAGE = 0x00000008;

        public const uint MODE = 0x00000010;

        public const uint PREVSTATE = 0x00000020;

        public const uint SHAREDSECRET = 0x00000040;

        public const uint DHCP_CONTROL_START = 0x00000001;

        public const uint DHCP_CONTROL_STOP = 0x00000002;

        public const uint DHCP_CONTROL_PAUSE = 0x00000003;

        public const uint DHCP_CONTROL_CONTINUE = 0x00000004;

        public const uint DHCP_DROP_DUPLICATE = 0x00000001;

        public const uint DHCP_DROP_NOMEM = 0x00000002;

        public const uint DHCP_DROP_INTERNAL_ERROR = 0x00000003;

        public const uint DHCP_DROP_TIMEOUT = 0x00000004;

        public const uint DHCP_DROP_UNAUTH = 0x00000005;

        public const uint DHCP_DROP_PAUSED = 0x00000006;

        public const uint DHCP_DROP_NO_SUBNETS = 0x00000007;

        public const uint DHCP_DROP_INVALID = 0x00000008;

        public const uint DHCP_DROP_WRONG_SERVER = 0x00000009;

        public const uint DHCP_DROP_NOADDRESS = 0x0000000A;

        public const uint DHCP_DROP_PROCESSED = 0x0000000B;

        public const uint DHCP_DROP_GEN_FAILURE = 0x00000100;

        public const uint DHCP_SEND_PACKET = 0x10000000;

        public const uint DHCP_PROB_CONFLICT = 0x20000001;

        public const uint DHCP_PROB_DECLINE = 0x20000002;

        public const uint DHCP_PROB_RELEASE = 0x20000003;

        public const uint DHCP_PROB_NACKED = 0x20000004;

        public const uint DHCP_GIVE_ADDRESS_NEW = 0x30000001;

        public const uint DHCP_GIVE_ADDRESS_OLD = 0x30000002;

        public const uint DHCP_CLIENT_BOOTP = 0x30000003;

        public const uint DHCP_CLIENT_DHCP = 0x30000004;

        public const uint DHCPV6_OPTION_CLIENTID = 1;

        public const uint DHCPV6_OPTION_SERVERID = 2;

        public const uint DHCPV6_OPTION_IA_NA = 3;

        public const uint DHCPV6_OPTION_IA_TA = 4;

        public const uint DHCPV6_OPTION_ORO = 6;

        public const uint DHCPV6_OPTION_PREFERENCE = 7;

        public const uint DHCPV6_OPTION_UNICAST = 12;

        public const uint DHCPV6_OPTION_RAPID_COMMIT = 14;

        public const uint DHCPV6_OPTION_USER_CLASS = 15;

        public const uint DHCPV6_OPTION_VENDOR_CLASS = 16;

        public const uint DHCPV6_OPTION_VENDOR_OPTS = 17;

        public const uint DHCPV6_OPTION_RECONF_MSG = 19;

        public const uint DHCPV6_OPTION_SIP_SERVERS_NAMES = 21;

        public const uint DHCPV6_OPTION_SIP_SERVERS_ADDRS = 22;

        public const uint DHCPV6_OPTION_DNS_SERVERS = 23;

        public const uint DHCPV6_OPTION_DOMAIN_LIST = 24;

        public const uint DHCPV6_OPTION_IA_PD = 25;

        public const uint DHCPV6_OPTION_NIS_SERVERS = 27;

        public const uint DHCPV6_OPTION_NISP_SERVERS = 28;

        public const uint DHCPV6_OPTION_NIS_DOMAIN_NAME = 29;

        public const uint DHCPV6_OPTION_NISP_DOMAIN_NAME = 30;

    }
}
