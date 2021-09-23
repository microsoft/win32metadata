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


namespace Windows.Win32.NetworkManagement.IpHelper
{
    public static partial class Apis
    {
        public const uint NET_IF_OPER_STATUS_DOWN_NOT_AUTHENTICATED = 0x00000001;

        public const uint NET_IF_OPER_STATUS_DOWN_NOT_MEDIA_CONNECTED = 0x00000002;

        public const uint NET_IF_OPER_STATUS_DORMANT_PAUSED = 0x00000004;

        public const uint NET_IF_OPER_STATUS_DORMANT_LOW_POWER = 0x00000008;

        public const uint NET_IF_OID_IF_ALIAS = 0x00000001;

        public const uint NET_IF_OID_COMPARTMENT_ID = 0x00000002;

        public const uint NET_IF_OID_NETWORK_GUID = 0x00000003;

        public const uint NET_IF_OID_IF_ENTRY = 0x00000004;

        public const uint NET_SITEID_UNSPECIFIED = 0;

        public const uint NET_SITEID_MAXUSER = 0x07ffffff;

        public const uint NET_SITEID_MAXSYSTEM = 0x0fffffff;

        public const uint NET_IFLUID_UNSPECIFIED = 0;

        public const uint NIIF_HARDWARE_INTERFACE = 0x00000001;

        public const uint NIIF_FILTER_INTERFACE = 0x00000002;

        public const uint NIIF_NDIS_RESERVED1 = 0x00000004;

        public const uint NIIF_NDIS_RESERVED2 = 0x00000008;

        public const uint NIIF_NDIS_RESERVED3 = 0x00000010;

        public const uint NIIF_NDIS_WDM_INTERFACE = 0x00000020;

        public const uint NIIF_NDIS_ENDPOINT_INTERFACE = 0x00000040;

        public const uint NIIF_NDIS_ISCSI_INTERFACE = 0x00000080;

        public const uint NIIF_NDIS_RESERVED4 = 0x00000100;

        public const uint IF_MAX_STRING_SIZE = 256;

        public const uint IF_MAX_PHYS_ADDRESS_LENGTH = 32;

        public const uint ANY_SIZE = 1;

        public const uint MAXLEN_PHYSADDR = 8;

        public const uint MAXLEN_IFDESCR = 256;

        public const uint MAX_INTERFACE_NAME_LEN = 256;

        public const uint MIN_IF_TYPE = 1;

        public const uint IF_TYPE_OTHER = 1;

        public const uint IF_TYPE_REGULAR_1822 = 2;

        public const uint IF_TYPE_HDH_1822 = 3;

        public const uint IF_TYPE_DDN_X25 = 4;

        public const uint IF_TYPE_RFC877_X25 = 5;

        public const uint IF_TYPE_ETHERNET_CSMACD = 6;

        public const uint IF_TYPE_IS088023_CSMACD = 7;

        public const uint IF_TYPE_ISO88024_TOKENBUS = 8;

        public const uint IF_TYPE_ISO88025_TOKENRING = 9;

        public const uint IF_TYPE_ISO88026_MAN = 10;

        public const uint IF_TYPE_STARLAN = 11;

        public const uint IF_TYPE_PROTEON_10MBIT = 12;

        public const uint IF_TYPE_PROTEON_80MBIT = 13;

        public const uint IF_TYPE_HYPERCHANNEL = 14;

        public const uint IF_TYPE_FDDI = 15;

        public const uint IF_TYPE_LAP_B = 16;

        public const uint IF_TYPE_SDLC = 17;

        public const uint IF_TYPE_DS1 = 18;

        public const uint IF_TYPE_E1 = 19;

        public const uint IF_TYPE_BASIC_ISDN = 20;

        public const uint IF_TYPE_PRIMARY_ISDN = 21;

        public const uint IF_TYPE_PROP_POINT2POINT_SERIAL = 22;

        public const uint IF_TYPE_PPP = 23;

        public const uint IF_TYPE_SOFTWARE_LOOPBACK = 24;

        public const uint IF_TYPE_EON = 25;

        public const uint IF_TYPE_ETHERNET_3MBIT = 26;

        public const uint IF_TYPE_NSIP = 27;

        public const uint IF_TYPE_SLIP = 28;

        public const uint IF_TYPE_ULTRA = 29;

        public const uint IF_TYPE_DS3 = 30;

        public const uint IF_TYPE_SIP = 31;

        public const uint IF_TYPE_FRAMERELAY = 32;

        public const uint IF_TYPE_RS232 = 33;

        public const uint IF_TYPE_PARA = 34;

        public const uint IF_TYPE_ARCNET = 35;

        public const uint IF_TYPE_ARCNET_PLUS = 36;

        public const uint IF_TYPE_ATM = 37;

        public const uint IF_TYPE_MIO_X25 = 38;

        public const uint IF_TYPE_SONET = 39;

        public const uint IF_TYPE_X25_PLE = 40;

        public const uint IF_TYPE_ISO88022_LLC = 41;

        public const uint IF_TYPE_LOCALTALK = 42;

        public const uint IF_TYPE_SMDS_DXI = 43;

        public const uint IF_TYPE_FRAMERELAY_SERVICE = 44;

        public const uint IF_TYPE_V35 = 45;

        public const uint IF_TYPE_HSSI = 46;

        public const uint IF_TYPE_HIPPI = 47;

        public const uint IF_TYPE_MODEM = 48;

        public const uint IF_TYPE_AAL5 = 49;

        public const uint IF_TYPE_SONET_PATH = 50;

        public const uint IF_TYPE_SONET_VT = 51;

        public const uint IF_TYPE_SMDS_ICIP = 52;

        public const uint IF_TYPE_PROP_VIRTUAL = 53;

        public const uint IF_TYPE_PROP_MULTIPLEXOR = 54;

        public const uint IF_TYPE_IEEE80212 = 55;

        public const uint IF_TYPE_FIBRECHANNEL = 56;

        public const uint IF_TYPE_HIPPIINTERFACE = 57;

        public const uint IF_TYPE_FRAMERELAY_INTERCONNECT = 58;

        public const uint IF_TYPE_AFLANE_8023 = 59;

        public const uint IF_TYPE_AFLANE_8025 = 60;

        public const uint IF_TYPE_CCTEMUL = 61;

        public const uint IF_TYPE_FASTETHER = 62;

        public const uint IF_TYPE_ISDN = 63;

        public const uint IF_TYPE_V11 = 64;

        public const uint IF_TYPE_V36 = 65;

        public const uint IF_TYPE_G703_64K = 66;

        public const uint IF_TYPE_G703_2MB = 67;

        public const uint IF_TYPE_QLLC = 68;

        public const uint IF_TYPE_FASTETHER_FX = 69;

        public const uint IF_TYPE_CHANNEL = 70;

        public const uint IF_TYPE_IEEE80211 = 71;

        public const uint IF_TYPE_IBM370PARCHAN = 72;

        public const uint IF_TYPE_ESCON = 73;

        public const uint IF_TYPE_DLSW = 74;

        public const uint IF_TYPE_ISDN_S = 75;

        public const uint IF_TYPE_ISDN_U = 76;

        public const uint IF_TYPE_LAP_D = 77;

        public const uint IF_TYPE_IPSWITCH = 78;

        public const uint IF_TYPE_RSRB = 79;

        public const uint IF_TYPE_ATM_LOGICAL = 80;

        public const uint IF_TYPE_DS0 = 81;

        public const uint IF_TYPE_DS0_BUNDLE = 82;

        public const uint IF_TYPE_BSC = 83;

        public const uint IF_TYPE_ASYNC = 84;

        public const uint IF_TYPE_CNR = 85;

        public const uint IF_TYPE_ISO88025R_DTR = 86;

        public const uint IF_TYPE_EPLRS = 87;

        public const uint IF_TYPE_ARAP = 88;

        public const uint IF_TYPE_PROP_CNLS = 89;

        public const uint IF_TYPE_HOSTPAD = 90;

        public const uint IF_TYPE_TERMPAD = 91;

        public const uint IF_TYPE_FRAMERELAY_MPI = 92;

        public const uint IF_TYPE_X213 = 93;

        public const uint IF_TYPE_ADSL = 94;

        public const uint IF_TYPE_RADSL = 95;

        public const uint IF_TYPE_SDSL = 96;

        public const uint IF_TYPE_VDSL = 97;

        public const uint IF_TYPE_ISO88025_CRFPRINT = 98;

        public const uint IF_TYPE_MYRINET = 99;

        public const uint IF_TYPE_VOICE_EM = 100;

        public const uint IF_TYPE_VOICE_FXO = 101;

        public const uint IF_TYPE_VOICE_FXS = 102;

        public const uint IF_TYPE_VOICE_ENCAP = 103;

        public const uint IF_TYPE_VOICE_OVERIP = 104;

        public const uint IF_TYPE_ATM_DXI = 105;

        public const uint IF_TYPE_ATM_FUNI = 106;

        public const uint IF_TYPE_ATM_IMA = 107;

        public const uint IF_TYPE_PPPMULTILINKBUNDLE = 108;

        public const uint IF_TYPE_IPOVER_CDLC = 109;

        public const uint IF_TYPE_IPOVER_CLAW = 110;

        public const uint IF_TYPE_STACKTOSTACK = 111;

        public const uint IF_TYPE_VIRTUALIPADDRESS = 112;

        public const uint IF_TYPE_MPC = 113;

        public const uint IF_TYPE_IPOVER_ATM = 114;

        public const uint IF_TYPE_ISO88025_FIBER = 115;

        public const uint IF_TYPE_TDLC = 116;

        public const uint IF_TYPE_GIGABITETHERNET = 117;

        public const uint IF_TYPE_HDLC = 118;

        public const uint IF_TYPE_LAP_F = 119;

        public const uint IF_TYPE_V37 = 120;

        public const uint IF_TYPE_X25_MLP = 121;

        public const uint IF_TYPE_X25_HUNTGROUP = 122;

        public const uint IF_TYPE_TRANSPHDLC = 123;

        public const uint IF_TYPE_INTERLEAVE = 124;

        public const uint IF_TYPE_FAST = 125;

        public const uint IF_TYPE_IP = 126;

        public const uint IF_TYPE_DOCSCABLE_MACLAYER = 127;

        public const uint IF_TYPE_DOCSCABLE_DOWNSTREAM = 128;

        public const uint IF_TYPE_DOCSCABLE_UPSTREAM = 129;

        public const uint IF_TYPE_A12MPPSWITCH = 130;

        public const uint IF_TYPE_TUNNEL = 131;

        public const uint IF_TYPE_COFFEE = 132;

        public const uint IF_TYPE_CES = 133;

        public const uint IF_TYPE_ATM_SUBINTERFACE = 134;

        public const uint IF_TYPE_L2_VLAN = 135;

        public const uint IF_TYPE_L3_IPVLAN = 136;

        public const uint IF_TYPE_L3_IPXVLAN = 137;

        public const uint IF_TYPE_DIGITALPOWERLINE = 138;

        public const uint IF_TYPE_MEDIAMAILOVERIP = 139;

        public const uint IF_TYPE_DTM = 140;

        public const uint IF_TYPE_DCN = 141;

        public const uint IF_TYPE_IPFORWARD = 142;

        public const uint IF_TYPE_MSDSL = 143;

        public const uint IF_TYPE_IEEE1394 = 144;

        public const uint IF_TYPE_IF_GSN = 145;

        public const uint IF_TYPE_DVBRCC_MACLAYER = 146;

        public const uint IF_TYPE_DVBRCC_DOWNSTREAM = 147;

        public const uint IF_TYPE_DVBRCC_UPSTREAM = 148;

        public const uint IF_TYPE_ATM_VIRTUAL = 149;

        public const uint IF_TYPE_MPLS_TUNNEL = 150;

        public const uint IF_TYPE_SRP = 151;

        public const uint IF_TYPE_VOICEOVERATM = 152;

        public const uint IF_TYPE_VOICEOVERFRAMERELAY = 153;

        public const uint IF_TYPE_IDSL = 154;

        public const uint IF_TYPE_COMPOSITELINK = 155;

        public const uint IF_TYPE_SS7_SIGLINK = 156;

        public const uint IF_TYPE_PROP_WIRELESS_P2P = 157;

        public const uint IF_TYPE_FR_FORWARD = 158;

        public const uint IF_TYPE_RFC1483 = 159;

        public const uint IF_TYPE_USB = 160;

        public const uint IF_TYPE_IEEE8023AD_LAG = 161;

        public const uint IF_TYPE_BGP_POLICY_ACCOUNTING = 162;

        public const uint IF_TYPE_FRF16_MFR_BUNDLE = 163;

        public const uint IF_TYPE_H323_GATEKEEPER = 164;

        public const uint IF_TYPE_H323_PROXY = 165;

        public const uint IF_TYPE_MPLS = 166;

        public const uint IF_TYPE_MF_SIGLINK = 167;

        public const uint IF_TYPE_HDSL2 = 168;

        public const uint IF_TYPE_SHDSL = 169;

        public const uint IF_TYPE_DS1_FDL = 170;

        public const uint IF_TYPE_POS = 171;

        public const uint IF_TYPE_DVB_ASI_IN = 172;

        public const uint IF_TYPE_DVB_ASI_OUT = 173;

        public const uint IF_TYPE_PLC = 174;

        public const uint IF_TYPE_NFAS = 175;

        public const uint IF_TYPE_TR008 = 176;

        public const uint IF_TYPE_GR303_RDT = 177;

        public const uint IF_TYPE_GR303_IDT = 178;

        public const uint IF_TYPE_ISUP = 179;

        public const uint IF_TYPE_PROP_DOCS_WIRELESS_MACLAYER = 180;

        public const uint IF_TYPE_PROP_DOCS_WIRELESS_DOWNSTREAM = 181;

        public const uint IF_TYPE_PROP_DOCS_WIRELESS_UPSTREAM = 182;

        public const uint IF_TYPE_HIPERLAN2 = 183;

        public const uint IF_TYPE_PROP_BWA_P2MP = 184;

        public const uint IF_TYPE_SONET_OVERHEAD_CHANNEL = 185;

        public const uint IF_TYPE_DIGITAL_WRAPPER_OVERHEAD_CHANNEL = 186;

        public const uint IF_TYPE_AAL2 = 187;

        public const uint IF_TYPE_RADIO_MAC = 188;

        public const uint IF_TYPE_ATM_RADIO = 189;

        public const uint IF_TYPE_IMT = 190;

        public const uint IF_TYPE_MVL = 191;

        public const uint IF_TYPE_REACH_DSL = 192;

        public const uint IF_TYPE_FR_DLCI_ENDPT = 193;

        public const uint IF_TYPE_ATM_VCI_ENDPT = 194;

        public const uint IF_TYPE_OPTICAL_CHANNEL = 195;

        public const uint IF_TYPE_OPTICAL_TRANSPORT = 196;

        public const uint IF_TYPE_IEEE80216_WMAN = 237;

        public const uint IF_TYPE_WWANPP = 243;

        public const uint IF_TYPE_WWANPP2 = 244;

        public const uint IF_TYPE_IEEE802154 = 259;

        public const uint IF_TYPE_XBOX_WIRELESS = 281;

        public const uint MAX_IF_TYPE = 281;

        public const uint IF_CHECK_NONE = 0x00;

        public const uint IF_CHECK_MCAST = 0x01;

        public const uint IF_CHECK_SEND = 0x02;

        public const uint IF_CONNECTION_DEDICATED = 1;

        public const uint IF_CONNECTION_PASSIVE = 2;

        public const uint IF_CONNECTION_DEMAND = 3;

        public const uint IF_ADMIN_STATUS_UP = 1;

        public const uint IF_ADMIN_STATUS_DOWN = 2;

        public const uint IF_ADMIN_STATUS_TESTING = 3;

        public const uint MIB_IF_TYPE_OTHER = 1;

        public const uint MIB_IF_TYPE_ETHERNET = 6;

        public const uint MIB_IF_TYPE_TOKENRING = 9;

        public const uint MIB_IF_TYPE_FDDI = 15;

        public const uint MIB_IF_TYPE_PPP = 23;

        public const uint MIB_IF_TYPE_LOOPBACK = 24;

        public const uint MIB_IF_TYPE_SLIP = 28;

        public const uint MIB_IF_ADMIN_STATUS_UP = 1;

        public const uint MIB_IF_ADMIN_STATUS_DOWN = 2;

        public const uint MIB_IF_ADMIN_STATUS_TESTING = 3;

        public const uint MIB_IPADDR_PRIMARY = 0x0001;

        public const uint MIB_IPADDR_DYNAMIC = 0x0004;

        public const uint MIB_IPADDR_DISCONNECTED = 0x0008;

        public const uint MIB_IPADDR_DELETED = 0x0040;

        public const uint MIB_IPADDR_TRANSIENT = 0x0080;

        public const uint MIB_IPADDR_DNS_ELIGIBLE = 0X0100;

        public const uint MIB_IPROUTE_TYPE_OTHER = 1;

        public const uint MIB_IPROUTE_TYPE_INVALID = 2;

        public const uint MIB_IPROUTE_TYPE_DIRECT = 3;

        public const uint MIB_IPROUTE_TYPE_INDIRECT = 4;

        public const uint MIB_IPROUTE_METRIC_UNUSED = 0xFFFFFFFF;

        public const uint MIB_USE_CURRENT_TTL = 0xFFFFFFFF;

        public const uint MIB_USE_CURRENT_FORWARDING = 0xFFFFFFFF;

        public const uint ICMP6_INFOMSG_MASK = 0x80;

        public const uint IPRTRMGR_PID = 10000;

        public const uint IF_NUMBER = 0;

        public const uint IF_TABLE = IF_NUMBER          + 1;

        public const uint IF_ROW = IF_TABLE           + 1;

        public const uint IP_STATS = IF_ROW             + 1;

        public const uint IP_ADDRTABLE = IP_STATS           + 1;

        public const uint IP_ADDRROW = IP_ADDRTABLE       + 1;

        public const uint IP_FORWARDNUMBER = IP_ADDRROW         + 1;

        public const uint IP_FORWARDTABLE = IP_FORWARDNUMBER   + 1;

        public const uint IP_FORWARDROW = IP_FORWARDTABLE    + 1;

        public const uint IP_NETTABLE = IP_FORWARDROW      + 1;

        public const uint IP_NETROW = IP_NETTABLE        + 1;

        public const uint ICMP_STATS = IP_NETROW          + 1;

        public const uint TCP_STATS = ICMP_STATS         + 1;

        public const uint TCP_TABLE = TCP_STATS          + 1;

        public const uint TCP_ROW = TCP_TABLE          + 1;

        public const uint UDP_STATS = TCP_ROW            + 1;

        public const uint UDP_TABLE = UDP_STATS          + 1;

        public const uint UDP_ROW = UDP_TABLE          + 1;

        public const uint MCAST_MFE = UDP_ROW            + 1;

        public const uint MCAST_MFE_STATS = MCAST_MFE          + 1;

        public const uint BEST_IF = MCAST_MFE_STATS    + 1;

        public const uint BEST_ROUTE = BEST_IF            + 1;

        public const uint PROXY_ARP = BEST_ROUTE         + 1;

        public const uint MCAST_IF_ENTRY = PROXY_ARP          + 1;

        public const uint MCAST_GLOBAL = MCAST_IF_ENTRY     + 1;

        public const uint IF_STATUS = MCAST_GLOBAL       + 1;

        public const uint MCAST_BOUNDARY = IF_STATUS          + 1;

        public const uint MCAST_SCOPE = MCAST_BOUNDARY     + 1;

        public const uint DEST_MATCHING = MCAST_SCOPE        + 1;

        public const uint DEST_LONGER = DEST_MATCHING      + 1;

        public const uint DEST_SHORTER = DEST_LONGER        + 1;

        public const uint ROUTE_MATCHING = DEST_SHORTER       + 1;

        public const uint ROUTE_LONGER = ROUTE_MATCHING     + 1;

        public const uint ROUTE_SHORTER = ROUTE_LONGER       + 1;

        public const uint ROUTE_STATE = ROUTE_SHORTER      + 1;

        public const uint MCAST_MFE_STATS_EX = ROUTE_STATE        + 1;

        public const uint IP6_STATS = MCAST_MFE_STATS_EX + 1;

        public const uint UDP6_STATS = IP6_STATS          + 1;

        public const uint TCP6_STATS = UDP6_STATS         + 1;

        public const uint NUMBER_OF_EXPORTED_VARIABLES = TCP6_STATS + 1;

        public const uint MAX_SCOPE_NAME_LEN = 255;

        public const uint MAX_MIB_OFFSET = 8;

        public const uint MIB_INVALID_TEREDO_PORT_NUMBER = 0;

        public const uint DNS_SETTINGS_VERSION1 = 0x0001;

        public const uint DNS_INTERFACE_SETTINGS_VERSION1 = 0x0001;

        public const uint DNS_INTERFACE_SETTINGS_VERSION2 = 0x0002;

        public const uint DNS_SETTING_IPV6 = 0x0001;

        public const uint DNS_SETTING_NAMESERVER = 0x0002;

        public const uint DNS_SETTING_SEARCHLIST = 0x0004;

        public const uint DNS_SETTING_REGISTRATION_ENABLED = 0x0008;

        public const uint DNS_SETTING_REGISTER_ADAPTER_NAME = 0x0010;

        public const uint DNS_SETTING_DOMAIN = 0x0020;

        public const uint DNS_SETTING_HOSTNAME = 0x0040;

        public const uint DNS_SETTINGS_ENABLE_LLMNR = 0x0080;

        public const uint DNS_SETTINGS_QUERY_ADAPTER_NAME = 0x0100;

        public const uint DNS_SETTING_PROFILE_NAMESERVER = 0x0200;

        public const uint DNS_SETTING_DISABLE_UNCONSTRAINED_QUERIES = 0x0400;

        public const uint DNS_SETTING_SUPPLEMENTAL_SEARCH_LIST = 0x0800;

        public const uint TCPIP_OWNING_MODULE_SIZE = 16;

        public const uint FD_FLAGS_NOSYN = 0x1;

        public const uint LB_SRC_ADDR_USE_SRCADDR_FLAG = 0x00000001;

        public const uint LB_SRC_ADDR_USE_DSTADDR_FLAG = 0x00000002;

        public const uint LB_DST_ADDR_USE_SRCADDR_FLAG = 0x00000004;

        public const uint LB_DST_ADDR_USE_DSTADDR_FLAG = 0x00000008;

        public const uint LB_SRC_MASK_LATE_FLAG = 0x00000010;

        public const uint LB_DST_MASK_LATE_FLAG = 0x00000020;

        public const uint ERROR_BASE = 23000;

        public const uint PFERROR_NO_PF_INTERFACE = ERROR_BASE + 0;

        public const uint PFERROR_NO_FILTERS_GIVEN = ERROR_BASE + 1;

        public const uint PFERROR_BUFFER_TOO_SMALL = ERROR_BASE + 2;

        public const uint ERROR_IPV6_NOT_IMPLEMENTED = ERROR_BASE + 3;

        public const uint IP_EXPORT_INCLUDED = 1;

        public const uint MAX_ADAPTER_NAME = 128;

        public const uint IP_STATUS_BASE = 11000;

        public const uint IP_SUCCESS = 0;

        public const uint IP_BUF_TOO_SMALL = IP_STATUS_BASE + 1;

        public const uint IP_DEST_NET_UNREACHABLE = IP_STATUS_BASE + 2;

        public const uint IP_DEST_HOST_UNREACHABLE = IP_STATUS_BASE + 3;

        public const uint IP_DEST_PROT_UNREACHABLE = IP_STATUS_BASE + 4;

        public const uint IP_DEST_PORT_UNREACHABLE = IP_STATUS_BASE + 5;

        public const uint IP_NO_RESOURCES = IP_STATUS_BASE + 6;

        public const uint IP_BAD_OPTION = IP_STATUS_BASE + 7;

        public const uint IP_HW_ERROR = IP_STATUS_BASE + 8;

        public const uint IP_PACKET_TOO_BIG = IP_STATUS_BASE + 9;

        public const uint IP_REQ_TIMED_OUT = IP_STATUS_BASE + 10;

        public const uint IP_BAD_REQ = IP_STATUS_BASE + 11;

        public const uint IP_BAD_ROUTE = IP_STATUS_BASE + 12;

        public const uint IP_TTL_EXPIRED_TRANSIT = IP_STATUS_BASE + 13;

        public const uint IP_TTL_EXPIRED_REASSEM = IP_STATUS_BASE + 14;

        public const uint IP_PARAM_PROBLEM = IP_STATUS_BASE + 15;

        public const uint IP_SOURCE_QUENCH = IP_STATUS_BASE + 16;

        public const uint IP_OPTION_TOO_BIG = IP_STATUS_BASE + 17;

        public const uint IP_BAD_DESTINATION = IP_STATUS_BASE + 18;

        public const uint IP_DEST_NO_ROUTE = IP_STATUS_BASE + 2;

        public const uint IP_DEST_ADDR_UNREACHABLE = IP_STATUS_BASE + 3;

        public const uint IP_DEST_PROHIBITED = IP_STATUS_BASE + 4;

        public const uint IP_HOP_LIMIT_EXCEEDED = IP_STATUS_BASE + 13;

        public const uint IP_REASSEMBLY_TIME_EXCEEDED = IP_STATUS_BASE + 14;

        public const uint IP_PARAMETER_PROBLEM = IP_STATUS_BASE + 15;

        public const uint IP_DEST_UNREACHABLE = IP_STATUS_BASE + 40;

        public const uint IP_TIME_EXCEEDED = IP_STATUS_BASE + 41;

        public const uint IP_BAD_HEADER = IP_STATUS_BASE + 42;

        public const uint IP_UNRECOGNIZED_NEXT_HEADER = IP_STATUS_BASE + 43;

        public const uint IP_ICMP_ERROR = IP_STATUS_BASE + 44;

        public const uint IP_DEST_SCOPE_MISMATCH = IP_STATUS_BASE + 45;

        public const uint IP_ADDR_DELETED = IP_STATUS_BASE + 19;

        public const uint IP_SPEC_MTU_CHANGE = IP_STATUS_BASE + 20;

        public const uint IP_MTU_CHANGE = IP_STATUS_BASE + 21;

        public const uint IP_UNLOAD = IP_STATUS_BASE + 22;

        public const uint IP_ADDR_ADDED = IP_STATUS_BASE + 23;

        public const uint IP_MEDIA_CONNECT = IP_STATUS_BASE + 24;

        public const uint IP_MEDIA_DISCONNECT = IP_STATUS_BASE + 25;

        public const uint IP_BIND_ADAPTER = IP_STATUS_BASE + 26;

        public const uint IP_UNBIND_ADAPTER = IP_STATUS_BASE + 27;

        public const uint IP_DEVICE_DOES_NOT_EXIST = IP_STATUS_BASE + 28;

        public const uint IP_DUPLICATE_ADDRESS = IP_STATUS_BASE + 29;

        public const uint IP_INTERFACE_METRIC_CHANGE = IP_STATUS_BASE + 30;

        public const uint IP_RECONFIG_SECFLTR = IP_STATUS_BASE + 31;

        public const uint IP_NEGOTIATING_IPSEC = IP_STATUS_BASE + 32;

        public const uint IP_INTERFACE_WOL_CAPABILITY_CHANGE = IP_STATUS_BASE + 33;

        public const uint IP_DUPLICATE_IPADD = IP_STATUS_BASE + 34;

        public const uint IP_GENERAL_FAILURE = IP_STATUS_BASE + 50;

        public const uint IP_PENDING = IP_STATUS_BASE + 255;

        public const uint IP_FLAG_REVERSE = 0x1;

        public const uint IP_FLAG_DF = 0x2;

        public const uint IP_OPT_EOL = 0;

        public const uint IP_OPT_NOP = 1;

        public const uint IP_OPT_SECURITY = 0x82;

        public const uint IP_OPT_LSRR = 0x83;

        public const uint IP_OPT_SSRR = 0x89;

        public const uint IP_OPT_RR = 0x7;

        public const uint IP_OPT_TS = 0x44;

        public const uint IP_OPT_SID = 0x88;

        public const uint IP_OPT_ROUTER_ALERT = 0x94;

        public const uint MAX_OPT_SIZE = 40;

        public const uint IOCTL_IP_RTCHANGE_NOTIFY_REQUEST = 101;

        public const uint IOCTL_IP_ADDCHANGE_NOTIFY_REQUEST = 102;

        public const uint IOCTL_ARP_SEND_REQUEST = 103;

        public const uint IOCTL_IP_INTERFACE_INFO = 104;

        public const uint IOCTL_IP_GET_BEST_INTERFACE = 105;

        public const uint IOCTL_IP_UNIDIRECTIONAL_ADAPTER_ADDRESS = 106;

        public const uint INTERFACE_TIMESTAMP_CAPABILITIES_VERSION_1 = 0x01;

        public const uint INTERFACE_HARDWARE_CROSSTIMESTAMP_VERSION_1 = 0x01;

        public const uint NET_STRING_IPV4_ADDRESS = 0x00000001;

        public const uint NET_STRING_IPV4_SERVICE = 0x00000002;

        public const uint NET_STRING_IPV4_NETWORK = 0x00000004;

        public const uint NET_STRING_IPV6_ADDRESS = 0x00000008;

        public const uint NET_STRING_IPV6_ADDRESS_NO_SCOPE = 0x00000010;

        public const uint NET_STRING_IPV6_SERVICE = 0x00000020;

        public const uint NET_STRING_IPV6_SERVICE_NO_SCOPE = 0x00000040;

        public const uint NET_STRING_IPV6_NETWORK = 0x00000080;

        public const uint NET_STRING_NAMED_ADDRESS = 0x00000100;

        public const uint NET_STRING_NAMED_SERVICE = 0x00000200;

        public const uint MAX_ADAPTER_DESCRIPTION_LENGTH = 128;

        public const uint MAX_ADAPTER_NAME_LENGTH = 256;

        public const uint MAX_ADAPTER_ADDRESS_LENGTH = 8;

        public const uint DEFAULT_MINIMUM_ENTITIES = 32;

        public const uint MAX_HOSTNAME_LEN = 128;

        public const uint MAX_DOMAIN_NAME_LEN = 128;

        public const uint MAX_SCOPE_ID_LEN = 256;

        public const uint MAX_DHCPV6_DUID_LENGTH = 130;

        public const uint MAX_DNS_SUFFIX_STRING_LENGTH = 256;

        public const uint BROADCAST_NODETYPE = 1;

        public const uint PEER_TO_PEER_NODETYPE = 2;

        public const uint MIXED_NODETYPE = 4;

        public const uint HYBRID_NODETYPE = 8;

        public const uint IP_ADAPTER_ADDRESS_DNS_ELIGIBLE = 0x01;

        public const uint IP_ADAPTER_ADDRESS_TRANSIENT = 0x02;

        public const uint IP_ADAPTER_DDNS_ENABLED = 0x00000001;

        public const uint IP_ADAPTER_REGISTER_ADAPTER_SUFFIX = 0x00000002;

        public const uint IP_ADAPTER_DHCP_ENABLED = 0x00000004;

        public const uint IP_ADAPTER_RECEIVE_ONLY = 0x00000008;

        public const uint IP_ADAPTER_NO_MULTICAST = 0x00000010;

        public const uint IP_ADAPTER_IPV6_OTHER_STATEFUL_CONFIG = 0x00000020;

        public const uint IP_ADAPTER_NETBIOS_OVER_TCPIP_ENABLED = 0x00000040;

        public const uint IP_ADAPTER_IPV4_ENABLED = 0x00000080;

        public const uint IP_ADAPTER_IPV6_ENABLED = 0x00000100;

        public const uint IP_ADAPTER_IPV6_MANAGE_ADDRESS_CONFIG = 0x00000200;

        public const uint GAA_FLAG_SKIP_DNS_INFO = 0x0800;

    }
}
