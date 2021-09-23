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


namespace Windows.Win32.NetworkManagement.Ndis
{
    public static partial class Apis
    {
        public const uint IOCTL_NDIS_RESERVED5 = ((FILE_DEVICE_PHYSICAL_NETCARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0xD) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_NDIS_RESERVED6 = ((FILE_DEVICE_PHYSICAL_NETCARD) << 16) | (uint)(((int)(FILE_WRITE_ACCESS)) << 14) | ((0xE) << 2) | (METHOD_BUFFERED);

        public const uint NDIS_OBJECT_TYPE_DEFAULT = 0x80;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_INIT_PARAMETERS = 0x81;

        public const uint NDIS_OBJECT_TYPE_SG_DMA_DESCRIPTION = 0x83;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_INTERRUPT = 0x84;

        public const uint NDIS_OBJECT_TYPE_DEVICE_OBJECT_ATTRIBUTES = 0x85;

        public const uint NDIS_OBJECT_TYPE_BIND_PARAMETERS = 0x86;

        public const uint NDIS_OBJECT_TYPE_OPEN_PARAMETERS = 0x87;

        public const uint NDIS_OBJECT_TYPE_RSS_CAPABILITIES = 0x88;

        public const uint NDIS_OBJECT_TYPE_RSS_PARAMETERS = 0x89;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_DRIVER_CHARACTERISTICS = 0x8A;

        public const uint NDIS_OBJECT_TYPE_FILTER_DRIVER_CHARACTERISTICS = 0x8B;

        public const uint NDIS_OBJECT_TYPE_FILTER_PARTIAL_CHARACTERISTICS = 0x8C;

        public const uint NDIS_OBJECT_TYPE_FILTER_ATTRIBUTES = 0x8D;

        public const uint NDIS_OBJECT_TYPE_CLIENT_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS = 0x8E;

        public const uint NDIS_OBJECT_TYPE_PROVIDER_CHIMNEY_OFFLOAD_GENERIC_CHARACTERISTICS = 0x8F;

        public const uint NDIS_OBJECT_TYPE_CO_PROTOCOL_CHARACTERISTICS = 0x90;

        public const uint NDIS_OBJECT_TYPE_CO_MINIPORT_CHARACTERISTICS = 0x91;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_PNP_CHARACTERISTICS = 0x92;

        public const uint NDIS_OBJECT_TYPE_CLIENT_CHIMNEY_OFFLOAD_CHARACTERISTICS = 0x93;

        public const uint NDIS_OBJECT_TYPE_PROVIDER_CHIMNEY_OFFLOAD_CHARACTERISTICS = 0x94;

        public const uint NDIS_OBJECT_TYPE_PROTOCOL_DRIVER_CHARACTERISTICS = 0x95;

        public const uint NDIS_OBJECT_TYPE_REQUEST_EX = 0x96;

        public const uint NDIS_OBJECT_TYPE_OID_REQUEST = 0x96;

        public const uint NDIS_OBJECT_TYPE_TIMER_CHARACTERISTICS = 0x97;

        public const uint NDIS_OBJECT_TYPE_STATUS_INDICATION = 0x98;

        public const uint NDIS_OBJECT_TYPE_FILTER_ATTACH_PARAMETERS = 0x99;

        public const uint NDIS_OBJECT_TYPE_FILTER_PAUSE_PARAMETERS = 0x9A;

        public const uint NDIS_OBJECT_TYPE_FILTER_RESTART_PARAMETERS = 0x9B;

        public const uint NDIS_OBJECT_TYPE_PORT_CHARACTERISTICS = 0x9C;

        public const uint NDIS_OBJECT_TYPE_PORT_STATE = 0x9D;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_REGISTRATION_ATTRIBUTES = 0x9E;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_GENERAL_ATTRIBUTES = 0x9F;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_OFFLOAD_ATTRIBUTES = 0xA0;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NATIVE_802_11_ATTRIBUTES = 0xA1;

        public const uint NDIS_OBJECT_TYPE_RESTART_GENERAL_ATTRIBUTES = 0xA2;

        public const uint NDIS_OBJECT_TYPE_PROTOCOL_RESTART_PARAMETERS = 0xA3;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADD_DEVICE_REGISTRATION_ATTRIBUTES = 0xA4;

        public const uint NDIS_OBJECT_TYPE_CO_CALL_MANAGER_OPTIONAL_HANDLERS = 0xA5;

        public const uint NDIS_OBJECT_TYPE_CO_CLIENT_OPTIONAL_HANDLERS = 0xA6;

        public const uint NDIS_OBJECT_TYPE_OFFLOAD = 0xA7;

        public const uint NDIS_OBJECT_TYPE_OFFLOAD_ENCAPSULATION = 0xA8;

        public const uint NDIS_OBJECT_TYPE_CONFIGURATION_OBJECT = 0xA9;

        public const uint NDIS_OBJECT_TYPE_DRIVER_WRAPPER_OBJECT = 0xAA;

        public const uint NDIS_OBJECT_TYPE_HD_SPLIT_ATTRIBUTES = 0xAB;

        public const uint NDIS_OBJECT_TYPE_NSI_NETWORK_RW_STRUCT = 0xAC;

        public const uint NDIS_OBJECT_TYPE_NSI_COMPARTMENT_RW_STRUCT = 0xAD;

        public const uint NDIS_OBJECT_TYPE_NSI_INTERFACE_PERSIST_RW_STRUCT = 0xAE;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_HARDWARE_ASSIST_ATTRIBUTES = 0xAF;

        public const uint NDIS_OBJECT_TYPE_SHARED_MEMORY_PROVIDER_CHARACTERISTICS = 0xB0;

        public const uint NDIS_OBJECT_TYPE_RSS_PROCESSOR_INFO = 0xB1;

        public const uint NDIS_OBJECT_TYPE_NDK_PROVIDER_CHARACTERISTICS = 0xB2;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_NDK_ATTRIBUTES = 0xB3;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_SS_CHARACTERISTICS = 0xB4;

        public const uint NDIS_OBJECT_TYPE_QOS_CAPABILITIES = 0xB5;

        public const uint NDIS_OBJECT_TYPE_QOS_PARAMETERS = 0xB6;

        public const uint NDIS_OBJECT_TYPE_QOS_CLASSIFICATION_ELEMENT = 0xB7;

        public const uint NDIS_OBJECT_TYPE_SWITCH_OPTIONAL_HANDLERS = 0xB8;

        public const uint NDIS_OBJECT_TYPE_PD_TRANSMIT_QUEUE = 0xBE;

        public const uint NDIS_OBJECT_TYPE_PD_RECEIVE_QUEUE = 0xBF;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_ADAPTER_PACKET_DIRECT_ATTRIBUTES = 0xC5;

        public const uint NDIS_OBJECT_TYPE_MINIPORT_DEVICE_POWER_NOTIFICATION = 0xC6;

        public const uint NDIS_OBJECT_TYPE_RSS_PARAMETERS_V2 = 0xC8;

        public const uint NDIS_OBJECT_TYPE_RSS_SET_INDIRECTION_ENTRIES = 0xC9;

        public const uint NDIS_OBJECT_REVISION_1 = 1;

        public const uint NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_RCV = 0x00000001;

        public const uint NDIS_STATISTICS_FLAGS_VALID_MULTICAST_FRAMES_RCV = 0x00000002;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BROADCAST_FRAMES_RCV = 0x00000004;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BYTES_RCV = 0x00000008;

        public const uint NDIS_STATISTICS_FLAGS_VALID_RCV_DISCARDS = 0x00000010;

        public const uint NDIS_STATISTICS_FLAGS_VALID_RCV_ERROR = 0x00000020;

        public const uint NDIS_STATISTICS_FLAGS_VALID_DIRECTED_FRAMES_XMIT = 0x00000040;

        public const uint NDIS_STATISTICS_FLAGS_VALID_MULTICAST_FRAMES_XMIT = 0x00000080;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BROADCAST_FRAMES_XMIT = 0x00000100;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BYTES_XMIT = 0x00000200;

        public const uint NDIS_STATISTICS_FLAGS_VALID_XMIT_ERROR = 0x00000400;

        public const uint NDIS_STATISTICS_FLAGS_VALID_XMIT_DISCARDS = 0x00008000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_DIRECTED_BYTES_RCV = 0x00010000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_MULTICAST_BYTES_RCV = 0x00020000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BROADCAST_BYTES_RCV = 0x00040000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_DIRECTED_BYTES_XMIT = 0x00080000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_MULTICAST_BYTES_XMIT = 0x00100000;

        public const uint NDIS_STATISTICS_FLAGS_VALID_BROADCAST_BYTES_XMIT = 0x00200000;

        public const uint NDIS_STATISTICS_INFO_REVISION_1 = 1;

        public const uint NDIS_RSC_STATISTICS_REVISION_1 = 1;

        public const uint NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_RESET = 0x00000001;

        public const uint NDIS_INTERRUPT_MODERATION_CHANGE_NEEDS_REINITIALIZE = 0x00000002;

        public const uint NDIS_INTERRUPT_MODERATION_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_TIMEOUT_DPC_REQUEST_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_OBJECT_TYPE_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_1 = 1;

        public const uint NDIS_OBJECT_TYPE_PCI_DEVICE_CUSTOM_PROPERTIES_REVISION_2 = 2;

        public const uint OID_GEN_SUPPORTED_LIST = 0x00010101;

        public const uint OID_GEN_HARDWARE_STATUS = 0x00010102;

        public const uint OID_GEN_MEDIA_SUPPORTED = 0x00010103;

        public const uint OID_GEN_MEDIA_IN_USE = 0x00010104;

        public const uint OID_GEN_MAXIMUM_LOOKAHEAD = 0x00010105;

        public const uint OID_GEN_MAXIMUM_FRAME_SIZE = 0x00010106;

        public const uint OID_GEN_LINK_SPEED = 0x00010107;

        public const uint OID_GEN_TRANSMIT_BUFFER_SPACE = 0x00010108;

        public const uint OID_GEN_RECEIVE_BUFFER_SPACE = 0x00010109;

        public const uint OID_GEN_TRANSMIT_BLOCK_SIZE = 0x0001010A;

        public const uint OID_GEN_RECEIVE_BLOCK_SIZE = 0x0001010B;

        public const uint OID_GEN_VENDOR_ID = 0x0001010C;

        public const uint OID_GEN_VENDOR_DESCRIPTION = 0x0001010D;

        public const uint OID_GEN_CURRENT_PACKET_FILTER = 0x0001010E;

        public const uint OID_GEN_CURRENT_LOOKAHEAD = 0x0001010F;

        public const uint OID_GEN_DRIVER_VERSION = 0x00010110;

        public const uint OID_GEN_MAXIMUM_TOTAL_SIZE = 0x00010111;

        public const uint OID_GEN_PROTOCOL_OPTIONS = 0x00010112;

        public const uint OID_GEN_MAC_OPTIONS = 0x00010113;

        public const uint OID_GEN_MEDIA_CONNECT_STATUS = 0x00010114;

        public const uint OID_GEN_MAXIMUM_SEND_PACKETS = 0x00010115;

        public const uint OID_GEN_VENDOR_DRIVER_VERSION = 0x00010116;

        public const uint OID_GEN_SUPPORTED_GUIDS = 0x00010117;

        public const uint OID_GEN_NETWORK_LAYER_ADDRESSES = 0x00010118;

        public const uint OID_GEN_TRANSPORT_HEADER_OFFSET = 0x00010119;

        public const uint OID_GEN_MEDIA_CAPABILITIES = 0x00010201;

        public const uint OID_GEN_PHYSICAL_MEDIUM = 0x00010202;

        public const uint OID_GEN_RECEIVE_SCALE_CAPABILITIES = 0x00010203;

        public const uint OID_GEN_RECEIVE_SCALE_PARAMETERS = 0x00010204;

        public const uint OID_GEN_MAC_ADDRESS = 0x00010205;

        public const uint OID_GEN_MAX_LINK_SPEED = 0x00010206;

        public const uint OID_GEN_LINK_STATE = 0x00010207;

        public const uint OID_GEN_LINK_PARAMETERS = 0x00010208;

        public const uint OID_GEN_INTERRUPT_MODERATION = 0x00010209;

        public const uint OID_GEN_NDIS_RESERVED_3 = 0x0001020A;

        public const uint OID_GEN_NDIS_RESERVED_4 = 0x0001020B;

        public const uint OID_GEN_NDIS_RESERVED_5 = 0x0001020C;

        public const uint OID_GEN_ENUMERATE_PORTS = 0x0001020D;

        public const uint OID_GEN_PORT_STATE = 0x0001020E;

        public const uint OID_GEN_PORT_AUTHENTICATION_PARAMETERS = 0x0001020F;

        public const uint OID_GEN_TIMEOUT_DPC_REQUEST_CAPABILITIES = 0x00010210;

        public const uint OID_GEN_PCI_DEVICE_CUSTOM_PROPERTIES = 0x00010211;

        public const uint OID_GEN_NDIS_RESERVED_6 = 0x00010212;

        public const uint OID_GEN_PHYSICAL_MEDIUM_EX = 0x00010213;

        public const uint OID_GEN_RECEIVE_SCALE_PARAMETERS_V2 = 0x00010214;

        public const uint OID_GEN_MACHINE_NAME = 0x0001021A;

        public const uint OID_GEN_RNDIS_CONFIG_PARAMETER = 0x0001021B;

        public const uint OID_GEN_VLAN_ID = 0x0001021C;

        public const uint OID_GEN_RECEIVE_HASH = 0x0001021F;

        public const uint OID_GEN_MINIPORT_RESTART_ATTRIBUTES = 0x0001021D;

        public const uint OID_GEN_HD_SPLIT_PARAMETERS = 0x0001021E;

        public const uint OID_GEN_HD_SPLIT_CURRENT_CONFIG = 0x00010220;

        public const uint OID_GEN_PROMISCUOUS_MODE = 0x00010280;

        public const uint OID_GEN_LAST_CHANGE = 0x00010281;

        public const uint OID_GEN_DISCONTINUITY_TIME = 0x00010282;

        public const uint OID_GEN_OPERATIONAL_STATUS = 0x00010283;

        public const uint OID_GEN_XMIT_LINK_SPEED = 0x00010284;

        public const uint OID_GEN_RCV_LINK_SPEED = 0x00010285;

        public const uint OID_GEN_UNKNOWN_PROTOS = 0x00010286;

        public const uint OID_GEN_INTERFACE_INFO = 0x00010287;

        public const uint OID_GEN_ADMIN_STATUS = 0x00010288;

        public const uint OID_GEN_ALIAS = 0x00010289;

        public const uint OID_GEN_MEDIA_CONNECT_STATUS_EX = 0x0001028A;

        public const uint OID_GEN_LINK_SPEED_EX = 0x0001028B;

        public const uint OID_GEN_MEDIA_DUPLEX_STATE = 0x0001028C;

        public const uint OID_GEN_IP_OPER_STATUS = 0x0001028D;

        public const uint OID_WWAN_DRIVER_CAPS = 0x0e010100;

        public const uint OID_WWAN_DEVICE_CAPS = 0x0e010101;

        public const uint OID_WWAN_READY_INFO = 0x0e010102;

        public const uint OID_WWAN_RADIO_STATE = 0x0e010103;

        public const uint OID_WWAN_PIN = 0x0e010104;

        public const uint OID_WWAN_PIN_LIST = 0x0e010105;

        public const uint OID_WWAN_HOME_PROVIDER = 0x0e010106;

        public const uint OID_WWAN_PREFERRED_PROVIDERS = 0x0e010107;

        public const uint OID_WWAN_VISIBLE_PROVIDERS = 0x0e010108;

        public const uint OID_WWAN_REGISTER_STATE = 0x0e010109;

        public const uint OID_WWAN_PACKET_SERVICE = 0x0e01010a;

        public const uint OID_WWAN_SIGNAL_STATE = 0x0e01010b;

        public const uint OID_WWAN_CONNECT = 0x0e01010c;

        public const uint OID_WWAN_PROVISIONED_CONTEXTS = 0x0e01010d;

        public const uint OID_WWAN_SERVICE_ACTIVATION = 0x0e01010e;

        public const uint OID_WWAN_SMS_CONFIGURATION = 0x0e01010f;

        public const uint OID_WWAN_SMS_READ = 0x0e010110;

        public const uint OID_WWAN_SMS_SEND = 0x0e010111;

        public const uint OID_WWAN_SMS_DELETE = 0x0e010112;

        public const uint OID_WWAN_SMS_STATUS = 0x0e010113;

        public const uint OID_WWAN_VENDOR_SPECIFIC = 0x0e010114;

        public const uint OID_WWAN_AUTH_CHALLENGE = 0x0e010115;

        public const uint OID_WWAN_ENUMERATE_DEVICE_SERVICES = 0x0e010116;

        public const uint OID_WWAN_SUBSCRIBE_DEVICE_SERVICE_EVENTS = 0x0e010117;

        public const uint OID_WWAN_DEVICE_SERVICE_COMMAND = 0x0e010118;

        public const uint OID_WWAN_USSD = 0x0e010119;

        public const uint OID_WWAN_PIN_EX = 0x0e010121;

        public const uint OID_WWAN_ENUMERATE_DEVICE_SERVICE_COMMANDS = 0x0e010122;

        public const uint OID_WWAN_DEVICE_SERVICE_SESSION = 0x0e010123;

        public const uint OID_WWAN_DEVICE_SERVICE_SESSION_WRITE = 0x0e010124;

        public const uint OID_WWAN_PREFERRED_MULTICARRIER_PROVIDERS = 0x0e010125;

        public const uint OID_WWAN_CREATE_MAC = 0x0e010126;

        public const uint OID_WWAN_DELETE_MAC = 0x0e010127;

        public const uint OID_WWAN_UICC_FILE_STATUS = 0x0e010128;

        public const uint OID_WWAN_UICC_ACCESS_BINARY = 0x0e010129;

        public const uint OID_WWAN_UICC_ACCESS_RECORD = 0x0e01012a;

        public const uint OID_WWAN_PIN_EX2 = 0x0e01012b;

        public const uint OID_WWAN_MBIM_VERSION = 0x0e01012c;

        public const uint OID_WWAN_SYS_CAPS = 0x0e01012d;

        public const uint OID_WWAN_DEVICE_CAPS_EX = 0x0e01012e;

        public const uint OID_WWAN_SYS_SLOTMAPPINGS = 0x0e01012f;

        public const uint OID_WWAN_SLOT_INFO_STATUS = 0x0e010130;

        public const uint OID_WWAN_DEVICE_BINDINGS = 0x0e010131;

        public const uint OID_WWAN_REGISTER_STATE_EX = 0x0e010132;

        public const uint OID_WWAN_IMS_VOICE_STATE = 0x0e010133;

        public const uint OID_WWAN_SIGNAL_STATE_EX = 0x0e010134;

        public const uint OID_WWAN_LOCATION_STATE = 0x0e010135;

        public const uint OID_WWAN_NITZ = 0x0e010136;

        public const uint OID_WWAN_NETWORK_IDLE_HINT = 0x0e010137;

        public const uint OID_WWAN_PRESHUTDOWN = 0x0e010138;

        public const uint OID_WWAN_UICC_ATR = 0x0e010139;

        public const uint OID_WWAN_UICC_OPEN_CHANNEL = 0x0e01013a;

        public const uint OID_WWAN_UICC_CLOSE_CHANNEL = 0x0e01013b;

        public const uint OID_WWAN_UICC_APDU = 0x0e01013c;

        public const uint OID_WWAN_UICC_TERMINAL_CAPABILITY = 0x0e01013d;

        public const uint OID_WWAN_PS_MEDIA_CONFIG = 0x0e01013e;

        public const uint OID_WWAN_SAR_CONFIG = 0x0e01013f;

        public const uint OID_WWAN_SAR_TRANSMISSION_STATUS = 0x0e010140;

        public const uint OID_WWAN_NETWORK_BLACKLIST = 0x0e010141;

        public const uint OID_WWAN_LTE_ATTACH_CONFIG = 0x0e010142;

        public const uint OID_WWAN_LTE_ATTACH_STATUS = 0x0e010143;

        public const uint OID_WWAN_MODEM_CONFIG_INFO = 0x0e010144;

        public const uint OID_WWAN_PCO = 0x0e010145;

        public const uint OID_WWAN_UICC_RESET = 0x0e010146;

        public const uint OID_WWAN_DEVICE_RESET = 0x0e010147;

        public const uint OID_WWAN_BASE_STATIONS_INFO = 0x0e010148;

        public const uint OID_WWAN_MPDP = 0x0e010149;

        public const uint OID_WWAN_UICC_APP_LIST = 0x0e01014a;

        public const uint OID_WWAN_MODEM_LOGGING_CONFIG = 0x0e01014b;

        public const uint OID_WWAN_REGISTER_PARAMS = 0x0e01014c;

        public const uint OID_WWAN_NETWORK_PARAMS = 0x0e01014d;

        public const uint OID_GEN_XMIT_OK = 0x00020101;

        public const uint OID_GEN_RCV_OK = 0x00020102;

        public const uint OID_GEN_XMIT_ERROR = 0x00020103;

        public const uint OID_GEN_RCV_ERROR = 0x00020104;

        public const uint OID_GEN_RCV_NO_BUFFER = 0x00020105;

        public const uint OID_GEN_STATISTICS = 0x00020106;

        public const uint OID_GEN_DIRECTED_BYTES_XMIT = 0x00020201;

        public const uint OID_GEN_DIRECTED_FRAMES_XMIT = 0x00020202;

        public const uint OID_GEN_MULTICAST_BYTES_XMIT = 0x00020203;

        public const uint OID_GEN_MULTICAST_FRAMES_XMIT = 0x00020204;

        public const uint OID_GEN_BROADCAST_BYTES_XMIT = 0x00020205;

        public const uint OID_GEN_BROADCAST_FRAMES_XMIT = 0x00020206;

        public const uint OID_GEN_DIRECTED_BYTES_RCV = 0x00020207;

        public const uint OID_GEN_DIRECTED_FRAMES_RCV = 0x00020208;

        public const uint OID_GEN_MULTICAST_BYTES_RCV = 0x00020209;

        public const uint OID_GEN_MULTICAST_FRAMES_RCV = 0x0002020A;

        public const uint OID_GEN_BROADCAST_BYTES_RCV = 0x0002020B;

        public const uint OID_GEN_BROADCAST_FRAMES_RCV = 0x0002020C;

        public const uint OID_GEN_RCV_CRC_ERROR = 0x0002020D;

        public const uint OID_GEN_TRANSMIT_QUEUE_LENGTH = 0x0002020E;

        public const uint OID_GEN_GET_TIME_CAPS = 0x0002020F;

        public const uint OID_GEN_GET_NETCARD_TIME = 0x00020210;

        public const uint OID_GEN_NETCARD_LOAD = 0x00020211;

        public const uint OID_GEN_DEVICE_PROFILE = 0x00020212;

        public const uint OID_GEN_INIT_TIME_MS = 0x00020213;

        public const uint OID_GEN_RESET_COUNTS = 0x00020214;

        public const uint OID_GEN_MEDIA_SENSE_COUNTS = 0x00020215;

        public const uint OID_GEN_FRIENDLY_NAME = 0x00020216;

        public const uint OID_GEN_NDIS_RESERVED_1 = 0x00020217;

        public const uint OID_GEN_NDIS_RESERVED_2 = 0x00020218;

        public const uint OID_GEN_BYTES_RCV = 0x00020219;

        public const uint OID_GEN_BYTES_XMIT = 0x0002021A;

        public const uint OID_GEN_RCV_DISCARDS = 0x0002021B;

        public const uint OID_GEN_XMIT_DISCARDS = 0x0002021C;

        public const uint OID_TCP_RSC_STATISTICS = 0x0002021D;

        public const uint OID_GEN_NDIS_RESERVED_7 = 0x0002021E;

        public const uint OID_GEN_CO_MINIMUM_LINK_SPEED = 0x00020120;

        public const uint OID_GEN_CO_BYTES_XMIT_OUTSTANDING = 0x00020221;

        public const uint OID_802_3_PERMANENT_ADDRESS = 0x01010101;

        public const uint OID_802_3_CURRENT_ADDRESS = 0x01010102;

        public const uint OID_802_3_MULTICAST_LIST = 0x01010103;

        public const uint OID_802_3_MAXIMUM_LIST_SIZE = 0x01010104;

        public const uint OID_802_3_MAC_OPTIONS = 0x01010105;

        public const uint NDIS_802_3_MAC_OPTION_PRIORITY = 0x00000001;

        public const uint OID_802_3_RCV_ERROR_ALIGNMENT = 0x01020101;

        public const uint OID_802_3_XMIT_ONE_COLLISION = 0x01020102;

        public const uint OID_802_3_XMIT_MORE_COLLISIONS = 0x01020103;

        public const uint OID_802_3_XMIT_DEFERRED = 0x01020201;

        public const uint OID_802_3_XMIT_MAX_COLLISIONS = 0x01020202;

        public const uint OID_802_3_RCV_OVERRUN = 0x01020203;

        public const uint OID_802_3_XMIT_UNDERRUN = 0x01020204;

        public const uint OID_802_3_XMIT_HEARTBEAT_FAILURE = 0x01020205;

        public const uint OID_802_3_XMIT_TIMES_CRS_LOST = 0x01020206;

        public const uint OID_802_3_XMIT_LATE_COLLISIONS = 0x01020207;

        public const uint OID_802_3_ADD_MULTICAST_ADDRESS = 0x01010208;

        public const uint OID_802_3_DELETE_MULTICAST_ADDRESS = 0x01010209;

        public const uint OID_802_5_PERMANENT_ADDRESS = 0x02010101;

        public const uint OID_802_5_CURRENT_ADDRESS = 0x02010102;

        public const uint OID_802_5_CURRENT_FUNCTIONAL = 0x02010103;

        public const uint OID_802_5_CURRENT_GROUP = 0x02010104;

        public const uint OID_802_5_LAST_OPEN_STATUS = 0x02010105;

        public const uint OID_802_5_CURRENT_RING_STATUS = 0x02010106;

        public const uint OID_802_5_CURRENT_RING_STATE = 0x02010107;

        public const uint OID_802_5_LINE_ERRORS = 0x02020101;

        public const uint OID_802_5_LOST_FRAMES = 0x02020102;

        public const uint OID_802_5_BURST_ERRORS = 0x02020201;

        public const uint OID_802_5_AC_ERRORS = 0x02020202;

        public const uint OID_802_5_ABORT_DELIMETERS = 0x02020203;

        public const uint OID_802_5_FRAME_COPIED_ERRORS = 0x02020204;

        public const uint OID_802_5_FREQUENCY_ERRORS = 0x02020205;

        public const uint OID_802_5_TOKEN_ERRORS = 0x02020206;

        public const uint OID_802_5_INTERNAL_ERRORS = 0x02020207;

        public const uint OID_FDDI_LONG_PERMANENT_ADDR = 0x03010101;

        public const uint OID_FDDI_LONG_CURRENT_ADDR = 0x03010102;

        public const uint OID_FDDI_LONG_MULTICAST_LIST = 0x03010103;

        public const uint OID_FDDI_LONG_MAX_LIST_SIZE = 0x03010104;

        public const uint OID_FDDI_SHORT_PERMANENT_ADDR = 0x03010105;

        public const uint OID_FDDI_SHORT_CURRENT_ADDR = 0x03010106;

        public const uint OID_FDDI_SHORT_MULTICAST_LIST = 0x03010107;

        public const uint OID_FDDI_SHORT_MAX_LIST_SIZE = 0x03010108;

        public const uint OID_FDDI_ATTACHMENT_TYPE = 0x03020101;

        public const uint OID_FDDI_UPSTREAM_NODE_LONG = 0x03020102;

        public const uint OID_FDDI_DOWNSTREAM_NODE_LONG = 0x03020103;

        public const uint OID_FDDI_FRAME_ERRORS = 0x03020104;

        public const uint OID_FDDI_FRAMES_LOST = 0x03020105;

        public const uint OID_FDDI_RING_MGT_STATE = 0x03020106;

        public const uint OID_FDDI_LCT_FAILURES = 0x03020107;

        public const uint OID_FDDI_LEM_REJECTS = 0x03020108;

        public const uint OID_FDDI_LCONNECTION_STATE = 0x03020109;

        public const uint OID_FDDI_SMT_STATION_ID = 0x03030201;

        public const uint OID_FDDI_SMT_OP_VERSION_ID = 0x03030202;

        public const uint OID_FDDI_SMT_HI_VERSION_ID = 0x03030203;

        public const uint OID_FDDI_SMT_LO_VERSION_ID = 0x03030204;

        public const uint OID_FDDI_SMT_MANUFACTURER_DATA = 0x03030205;

        public const uint OID_FDDI_SMT_USER_DATA = 0x03030206;

        public const uint OID_FDDI_SMT_MIB_VERSION_ID = 0x03030207;

        public const uint OID_FDDI_SMT_MAC_CT = 0x03030208;

        public const uint OID_FDDI_SMT_NON_MASTER_CT = 0x03030209;

        public const uint OID_FDDI_SMT_MASTER_CT = 0x0303020A;

        public const uint OID_FDDI_SMT_AVAILABLE_PATHS = 0x0303020B;

        public const uint OID_FDDI_SMT_CONFIG_CAPABILITIES = 0x0303020C;

        public const uint OID_FDDI_SMT_CONFIG_POLICY = 0x0303020D;

        public const uint OID_FDDI_SMT_CONNECTION_POLICY = 0x0303020E;

        public const uint OID_FDDI_SMT_T_NOTIFY = 0x0303020F;

        public const uint OID_FDDI_SMT_STAT_RPT_POLICY = 0x03030210;

        public const uint OID_FDDI_SMT_TRACE_MAX_EXPIRATION = 0x03030211;

        public const uint OID_FDDI_SMT_PORT_INDEXES = 0x03030212;

        public const uint OID_FDDI_SMT_MAC_INDEXES = 0x03030213;

        public const uint OID_FDDI_SMT_BYPASS_PRESENT = 0x03030214;

        public const uint OID_FDDI_SMT_ECM_STATE = 0x03030215;

        public const uint OID_FDDI_SMT_CF_STATE = 0x03030216;

        public const uint OID_FDDI_SMT_HOLD_STATE = 0x03030217;

        public const uint OID_FDDI_SMT_REMOTE_DISCONNECT_FLAG = 0x03030218;

        public const uint OID_FDDI_SMT_STATION_STATUS = 0x03030219;

        public const uint OID_FDDI_SMT_PEER_WRAP_FLAG = 0x0303021A;

        public const uint OID_FDDI_SMT_MSG_TIME_STAMP = 0x0303021B;

        public const uint OID_FDDI_SMT_TRANSITION_TIME_STAMP = 0x0303021C;

        public const uint OID_FDDI_SMT_SET_COUNT = 0x0303021D;

        public const uint OID_FDDI_SMT_LAST_SET_STATION_ID = 0x0303021E;

        public const uint OID_FDDI_MAC_FRAME_STATUS_FUNCTIONS = 0x0303021F;

        public const uint OID_FDDI_MAC_BRIDGE_FUNCTIONS = 0x03030220;

        public const uint OID_FDDI_MAC_T_MAX_CAPABILITY = 0x03030221;

        public const uint OID_FDDI_MAC_TVX_CAPABILITY = 0x03030222;

        public const uint OID_FDDI_MAC_AVAILABLE_PATHS = 0x03030223;

        public const uint OID_FDDI_MAC_CURRENT_PATH = 0x03030224;

        public const uint OID_FDDI_MAC_UPSTREAM_NBR = 0x03030225;

        public const uint OID_FDDI_MAC_DOWNSTREAM_NBR = 0x03030226;

        public const uint OID_FDDI_MAC_OLD_UPSTREAM_NBR = 0x03030227;

        public const uint OID_FDDI_MAC_OLD_DOWNSTREAM_NBR = 0x03030228;

        public const uint OID_FDDI_MAC_DUP_ADDRESS_TEST = 0x03030229;

        public const uint OID_FDDI_MAC_REQUESTED_PATHS = 0x0303022A;

        public const uint OID_FDDI_MAC_DOWNSTREAM_PORT_TYPE = 0x0303022B;

        public const uint OID_FDDI_MAC_INDEX = 0x0303022C;

        public const uint OID_FDDI_MAC_SMT_ADDRESS = 0x0303022D;

        public const uint OID_FDDI_MAC_LONG_GRP_ADDRESS = 0x0303022E;

        public const uint OID_FDDI_MAC_SHORT_GRP_ADDRESS = 0x0303022F;

        public const uint OID_FDDI_MAC_T_REQ = 0x03030230;

        public const uint OID_FDDI_MAC_T_NEG = 0x03030231;

        public const uint OID_FDDI_MAC_T_MAX = 0x03030232;

        public const uint OID_FDDI_MAC_TVX_VALUE = 0x03030233;

        public const uint OID_FDDI_MAC_T_PRI0 = 0x03030234;

        public const uint OID_FDDI_MAC_T_PRI1 = 0x03030235;

        public const uint OID_FDDI_MAC_T_PRI2 = 0x03030236;

        public const uint OID_FDDI_MAC_T_PRI3 = 0x03030237;

        public const uint OID_FDDI_MAC_T_PRI4 = 0x03030238;

        public const uint OID_FDDI_MAC_T_PRI5 = 0x03030239;

        public const uint OID_FDDI_MAC_T_PRI6 = 0x0303023A;

        public const uint OID_FDDI_MAC_FRAME_CT = 0x0303023B;

        public const uint OID_FDDI_MAC_COPIED_CT = 0x0303023C;

        public const uint OID_FDDI_MAC_TRANSMIT_CT = 0x0303023D;

        public const uint OID_FDDI_MAC_TOKEN_CT = 0x0303023E;

        public const uint OID_FDDI_MAC_ERROR_CT = 0x0303023F;

        public const uint OID_FDDI_MAC_LOST_CT = 0x03030240;

        public const uint OID_FDDI_MAC_TVX_EXPIRED_CT = 0x03030241;

        public const uint OID_FDDI_MAC_NOT_COPIED_CT = 0x03030242;

        public const uint OID_FDDI_MAC_LATE_CT = 0x03030243;

        public const uint OID_FDDI_MAC_RING_OP_CT = 0x03030244;

        public const uint OID_FDDI_MAC_FRAME_ERROR_THRESHOLD = 0x03030245;

        public const uint OID_FDDI_MAC_FRAME_ERROR_RATIO = 0x03030246;

        public const uint OID_FDDI_MAC_NOT_COPIED_THRESHOLD = 0x03030247;

        public const uint OID_FDDI_MAC_NOT_COPIED_RATIO = 0x03030248;

        public const uint OID_FDDI_MAC_RMT_STATE = 0x03030249;

        public const uint OID_FDDI_MAC_DA_FLAG = 0x0303024A;

        public const uint OID_FDDI_MAC_UNDA_FLAG = 0x0303024B;

        public const uint OID_FDDI_MAC_FRAME_ERROR_FLAG = 0x0303024C;

        public const uint OID_FDDI_MAC_NOT_COPIED_FLAG = 0x0303024D;

        public const uint OID_FDDI_MAC_MA_UNITDATA_AVAILABLE = 0x0303024E;

        public const uint OID_FDDI_MAC_HARDWARE_PRESENT = 0x0303024F;

        public const uint OID_FDDI_MAC_MA_UNITDATA_ENABLE = 0x03030250;

        public const uint OID_FDDI_PATH_INDEX = 0x03030251;

        public const uint OID_FDDI_PATH_RING_LATENCY = 0x03030252;

        public const uint OID_FDDI_PATH_TRACE_STATUS = 0x03030253;

        public const uint OID_FDDI_PATH_SBA_PAYLOAD = 0x03030254;

        public const uint OID_FDDI_PATH_SBA_OVERHEAD = 0x03030255;

        public const uint OID_FDDI_PATH_CONFIGURATION = 0x03030256;

        public const uint OID_FDDI_PATH_T_R_MODE = 0x03030257;

        public const uint OID_FDDI_PATH_SBA_AVAILABLE = 0x03030258;

        public const uint OID_FDDI_PATH_TVX_LOWER_BOUND = 0x03030259;

        public const uint OID_FDDI_PATH_T_MAX_LOWER_BOUND = 0x0303025A;

        public const uint OID_FDDI_PATH_MAX_T_REQ = 0x0303025B;

        public const uint OID_FDDI_PORT_MY_TYPE = 0x0303025C;

        public const uint OID_FDDI_PORT_NEIGHBOR_TYPE = 0x0303025D;

        public const uint OID_FDDI_PORT_CONNECTION_POLICIES = 0x0303025E;

        public const uint OID_FDDI_PORT_MAC_INDICATED = 0x0303025F;

        public const uint OID_FDDI_PORT_CURRENT_PATH = 0x03030260;

        public const uint OID_FDDI_PORT_REQUESTED_PATHS = 0x03030261;

        public const uint OID_FDDI_PORT_MAC_PLACEMENT = 0x03030262;

        public const uint OID_FDDI_PORT_AVAILABLE_PATHS = 0x03030263;

        public const uint OID_FDDI_PORT_MAC_LOOP_TIME = 0x03030264;

        public const uint OID_FDDI_PORT_PMD_CLASS = 0x03030265;

        public const uint OID_FDDI_PORT_CONNECTION_CAPABILITIES = 0x03030266;

        public const uint OID_FDDI_PORT_INDEX = 0x03030267;

        public const uint OID_FDDI_PORT_MAINT_LS = 0x03030268;

        public const uint OID_FDDI_PORT_BS_FLAG = 0x03030269;

        public const uint OID_FDDI_PORT_PC_LS = 0x0303026A;

        public const uint OID_FDDI_PORT_EB_ERROR_CT = 0x0303026B;

        public const uint OID_FDDI_PORT_LCT_FAIL_CT = 0x0303026C;

        public const uint OID_FDDI_PORT_LER_ESTIMATE = 0x0303026D;

        public const uint OID_FDDI_PORT_LEM_REJECT_CT = 0x0303026E;

        public const uint OID_FDDI_PORT_LEM_CT = 0x0303026F;

        public const uint OID_FDDI_PORT_LER_CUTOFF = 0x03030270;

        public const uint OID_FDDI_PORT_LER_ALARM = 0x03030271;

        public const uint OID_FDDI_PORT_CONNNECT_STATE = 0x03030272;

        public const uint OID_FDDI_PORT_PCM_STATE = 0x03030273;

        public const uint OID_FDDI_PORT_PC_WITHHOLD = 0x03030274;

        public const uint OID_FDDI_PORT_LER_FLAG = 0x03030275;

        public const uint OID_FDDI_PORT_HARDWARE_PRESENT = 0x03030276;

        public const uint OID_FDDI_SMT_STATION_ACTION = 0x03030277;

        public const uint OID_FDDI_PORT_ACTION = 0x03030278;

        public const uint OID_FDDI_IF_DESCR = 0x03030279;

        public const uint OID_FDDI_IF_TYPE = 0x0303027A;

        public const uint OID_FDDI_IF_MTU = 0x0303027B;

        public const uint OID_FDDI_IF_SPEED = 0x0303027C;

        public const uint OID_FDDI_IF_PHYS_ADDRESS = 0x0303027D;

        public const uint OID_FDDI_IF_ADMIN_STATUS = 0x0303027E;

        public const uint OID_FDDI_IF_OPER_STATUS = 0x0303027F;

        public const uint OID_FDDI_IF_LAST_CHANGE = 0x03030280;

        public const uint OID_FDDI_IF_IN_OCTETS = 0x03030281;

        public const uint OID_FDDI_IF_IN_UCAST_PKTS = 0x03030282;

        public const uint OID_FDDI_IF_IN_NUCAST_PKTS = 0x03030283;

        public const uint OID_FDDI_IF_IN_DISCARDS = 0x03030284;

        public const uint OID_FDDI_IF_IN_ERRORS = 0x03030285;

        public const uint OID_FDDI_IF_IN_UNKNOWN_PROTOS = 0x03030286;

        public const uint OID_FDDI_IF_OUT_OCTETS = 0x03030287;

        public const uint OID_FDDI_IF_OUT_UCAST_PKTS = 0x03030288;

        public const uint OID_FDDI_IF_OUT_NUCAST_PKTS = 0x03030289;

        public const uint OID_FDDI_IF_OUT_DISCARDS = 0x0303028A;

        public const uint OID_FDDI_IF_OUT_ERRORS = 0x0303028B;

        public const uint OID_FDDI_IF_OUT_QLEN = 0x0303028C;

        public const uint OID_FDDI_IF_SPECIFIC = 0x0303028D;

        public const uint OID_WAN_PERMANENT_ADDRESS = 0x04010101;

        public const uint OID_WAN_CURRENT_ADDRESS = 0x04010102;

        public const uint OID_WAN_QUALITY_OF_SERVICE = 0x04010103;

        public const uint OID_WAN_PROTOCOL_TYPE = 0x04010104;

        public const uint OID_WAN_MEDIUM_SUBTYPE = 0x04010105;

        public const uint OID_WAN_HEADER_FORMAT = 0x04010106;

        public const uint OID_WAN_GET_INFO = 0x04010107;

        public const uint OID_WAN_SET_LINK_INFO = 0x04010108;

        public const uint OID_WAN_GET_LINK_INFO = 0x04010109;

        public const uint OID_WAN_LINE_COUNT = 0x0401010A;

        public const uint OID_WAN_PROTOCOL_CAPS = 0x0401010B;

        public const uint OID_WAN_GET_BRIDGE_INFO = 0x0401020A;

        public const uint OID_WAN_SET_BRIDGE_INFO = 0x0401020B;

        public const uint OID_WAN_GET_COMP_INFO = 0x0401020C;

        public const uint OID_WAN_SET_COMP_INFO = 0x0401020D;

        public const uint OID_WAN_GET_STATS_INFO = 0x0401020E;

        public const uint OID_WAN_CO_GET_INFO = 0x04010180;

        public const uint OID_WAN_CO_SET_LINK_INFO = 0x04010181;

        public const uint OID_WAN_CO_GET_LINK_INFO = 0x04010182;

        public const uint OID_WAN_CO_GET_COMP_INFO = 0x04010280;

        public const uint OID_WAN_CO_SET_COMP_INFO = 0x04010281;

        public const uint OID_WAN_CO_GET_STATS_INFO = 0x04010282;

        public const uint OID_LTALK_CURRENT_NODE_ID = 0x05010102;

        public const uint OID_LTALK_IN_BROADCASTS = 0x05020101;

        public const uint OID_LTALK_IN_LENGTH_ERRORS = 0x05020102;

        public const uint OID_LTALK_OUT_NO_HANDLERS = 0x05020201;

        public const uint OID_LTALK_COLLISIONS = 0x05020202;

        public const uint OID_LTALK_DEFERS = 0x05020203;

        public const uint OID_LTALK_NO_DATA_ERRORS = 0x05020204;

        public const uint OID_LTALK_RANDOM_CTS_ERRORS = 0x05020205;

        public const uint OID_LTALK_FCS_ERRORS = 0x05020206;

        public const uint OID_ARCNET_PERMANENT_ADDRESS = 0x06010101;

        public const uint OID_ARCNET_CURRENT_ADDRESS = 0x06010102;

        public const uint OID_ARCNET_RECONFIGURATIONS = 0x06020201;

        public const uint OID_TAPI_ACCEPT = 0x07030101;

        public const uint OID_TAPI_ANSWER = 0x07030102;

        public const uint OID_TAPI_CLOSE = 0x07030103;

        public const uint OID_TAPI_CLOSE_CALL = 0x07030104;

        public const uint OID_TAPI_CONDITIONAL_MEDIA_DETECTION = 0x07030105;

        public const uint OID_TAPI_CONFIG_DIALOG = 0x07030106;

        public const uint OID_TAPI_DEV_SPECIFIC = 0x07030107;

        public const uint OID_TAPI_DIAL = 0x07030108;

        public const uint OID_TAPI_DROP = 0x07030109;

        public const uint OID_TAPI_GET_ADDRESS_CAPS = 0x0703010A;

        public const uint OID_TAPI_GET_ADDRESS_ID = 0x0703010B;

        public const uint OID_TAPI_GET_ADDRESS_STATUS = 0x0703010C;

        public const uint OID_TAPI_GET_CALL_ADDRESS_ID = 0x0703010D;

        public const uint OID_TAPI_GET_CALL_INFO = 0x0703010E;

        public const uint OID_TAPI_GET_CALL_STATUS = 0x0703010F;

        public const uint OID_TAPI_GET_DEV_CAPS = 0x07030110;

        public const uint OID_TAPI_GET_DEV_CONFIG = 0x07030111;

        public const uint OID_TAPI_GET_EXTENSION_ID = 0x07030112;

        public const uint OID_TAPI_GET_ID = 0x07030113;

        public const uint OID_TAPI_GET_LINE_DEV_STATUS = 0x07030114;

        public const uint OID_TAPI_MAKE_CALL = 0x07030115;

        public const uint OID_TAPI_NEGOTIATE_EXT_VERSION = 0x07030116;

        public const uint OID_TAPI_OPEN = 0x07030117;

        public const uint OID_TAPI_PROVIDER_INITIALIZE = 0x07030118;

        public const uint OID_TAPI_PROVIDER_SHUTDOWN = 0x07030119;

        public const uint OID_TAPI_SECURE_CALL = 0x0703011A;

        public const uint OID_TAPI_SELECT_EXT_VERSION = 0x0703011B;

        public const uint OID_TAPI_SEND_USER_USER_INFO = 0x0703011C;

        public const uint OID_TAPI_SET_APP_SPECIFIC = 0x0703011D;

        public const uint OID_TAPI_SET_CALL_PARAMS = 0x0703011E;

        public const uint OID_TAPI_SET_DEFAULT_MEDIA_DETECTION = 0x0703011F;

        public const uint OID_TAPI_SET_DEV_CONFIG = 0x07030120;

        public const uint OID_TAPI_SET_MEDIA_MODE = 0x07030121;

        public const uint OID_TAPI_SET_STATUS_MESSAGES = 0x07030122;

        public const uint OID_TAPI_GATHER_DIGITS = 0x07030123;

        public const uint OID_TAPI_MONITOR_DIGITS = 0x07030124;

        public const uint OID_ATM_SUPPORTED_VC_RATES = 0x08010101;

        public const uint OID_ATM_SUPPORTED_SERVICE_CATEGORY = 0x08010102;

        public const uint OID_ATM_SUPPORTED_AAL_TYPES = 0x08010103;

        public const uint OID_ATM_HW_CURRENT_ADDRESS = 0x08010104;

        public const uint OID_ATM_MAX_ACTIVE_VCS = 0x08010105;

        public const uint OID_ATM_MAX_ACTIVE_VCI_BITS = 0x08010106;

        public const uint OID_ATM_MAX_ACTIVE_VPI_BITS = 0x08010107;

        public const uint OID_ATM_MAX_AAL0_PACKET_SIZE = 0x08010108;

        public const uint OID_ATM_MAX_AAL1_PACKET_SIZE = 0x08010109;

        public const uint OID_ATM_MAX_AAL34_PACKET_SIZE = 0x0801010A;

        public const uint OID_ATM_MAX_AAL5_PACKET_SIZE = 0x0801010B;

        public const uint OID_ATM_SIGNALING_VPIVCI = 0x08010201;

        public const uint OID_ATM_ASSIGNED_VPI = 0x08010202;

        public const uint OID_ATM_ACQUIRE_ACCESS_NET_RESOURCES = 0x08010203;

        public const uint OID_ATM_RELEASE_ACCESS_NET_RESOURCES = 0x08010204;

        public const uint OID_ATM_ILMI_VPIVCI = 0x08010205;

        public const uint OID_ATM_DIGITAL_BROADCAST_VPIVCI = 0x08010206;

        public const uint OID_ATM_GET_NEAREST_FLOW = 0x08010207;

        public const uint OID_ATM_ALIGNMENT_REQUIRED = 0x08010208;

        public const uint OID_ATM_LECS_ADDRESS = 0x08010209;

        public const uint OID_ATM_SERVICE_ADDRESS = 0x0801020A;

        public const uint OID_ATM_CALL_PROCEEDING = 0x0801020B;

        public const uint OID_ATM_CALL_ALERTING = 0x0801020C;

        public const uint OID_ATM_PARTY_ALERTING = 0x0801020D;

        public const uint OID_ATM_CALL_NOTIFY = 0x0801020E;

        public const uint OID_ATM_MY_IP_NM_ADDRESS = 0x0801020F;

        public const uint OID_ATM_RCV_CELLS_OK = 0x08020101;

        public const uint OID_ATM_XMIT_CELLS_OK = 0x08020102;

        public const uint OID_ATM_RCV_CELLS_DROPPED = 0x08020103;

        public const uint OID_ATM_RCV_INVALID_VPI_VCI = 0x08020201;

        public const uint OID_ATM_CELLS_HEC_ERROR = 0x08020202;

        public const uint OID_ATM_RCV_REASSEMBLY_ERROR = 0x08020203;

        public const uint OID_802_11_BSSID = 0x0D010101;

        public const uint OID_802_11_SSID = 0x0D010102;

        public const uint OID_802_11_NETWORK_TYPES_SUPPORTED = 0x0D010203;

        public const uint OID_802_11_NETWORK_TYPE_IN_USE = 0x0D010204;

        public const uint OID_802_11_TX_POWER_LEVEL = 0x0D010205;

        public const uint OID_802_11_RSSI = 0x0D010206;

        public const uint OID_802_11_RSSI_TRIGGER = 0x0D010207;

        public const uint OID_802_11_INFRASTRUCTURE_MODE = 0x0D010108;

        public const uint OID_802_11_FRAGMENTATION_THRESHOLD = 0x0D010209;

        public const uint OID_802_11_RTS_THRESHOLD = 0x0D01020A;

        public const uint OID_802_11_NUMBER_OF_ANTENNAS = 0x0D01020B;

        public const uint OID_802_11_RX_ANTENNA_SELECTED = 0x0D01020C;

        public const uint OID_802_11_TX_ANTENNA_SELECTED = 0x0D01020D;

        public const uint OID_802_11_SUPPORTED_RATES = 0x0D01020E;

        public const uint OID_802_11_DESIRED_RATES = 0x0D010210;

        public const uint OID_802_11_CONFIGURATION = 0x0D010211;

        public const uint OID_802_11_STATISTICS = 0x0D020212;

        public const uint OID_802_11_ADD_WEP = 0x0D010113;

        public const uint OID_802_11_REMOVE_WEP = 0x0D010114;

        public const uint OID_802_11_DISASSOCIATE = 0x0D010115;

        public const uint OID_802_11_POWER_MODE = 0x0D010216;

        public const uint OID_802_11_BSSID_LIST = 0x0D010217;

        public const uint OID_802_11_AUTHENTICATION_MODE = 0x0D010118;

        public const uint OID_802_11_PRIVACY_FILTER = 0x0D010119;

        public const uint OID_802_11_BSSID_LIST_SCAN = 0x0D01011A;

        public const uint OID_802_11_WEP_STATUS = 0x0D01011B;

        public const uint OID_802_11_RELOAD_DEFAULTS = 0x0D01011C;

        public const uint OID_802_11_ADD_KEY = 0x0D01011D;

        public const uint OID_802_11_REMOVE_KEY = 0x0D01011E;

        public const uint OID_802_11_ASSOCIATION_INFORMATION = 0x0D01011F;

        public const uint OID_802_11_TEST = 0x0D010120;

        public const uint OID_802_11_MEDIA_STREAM_MODE = 0x0D010121;

        public const uint OID_802_11_CAPABILITY = 0x0D010122;

        public const uint OID_802_11_PMKID = 0x0D010123;

        public const uint OID_802_11_NON_BCAST_SSID_LIST = 0x0D010124;

        public const uint OID_802_11_RADIO_STATUS = 0x0D010125;

        public const uint NDIS_ETH_TYPE_IPV4 = 0x0800;

        public const uint NDIS_ETH_TYPE_ARP = 0x0806;

        public const uint NDIS_ETH_TYPE_IPV6 = 0x86dd;

        public const uint NDIS_ETH_TYPE_802_1X = 0x888e;

        public const uint NDIS_ETH_TYPE_802_1Q = 0x8100;

        public const uint NDIS_ETH_TYPE_SLOW_PROTOCOL = 0x8809;

        public const uint NDIS_802_11_LENGTH_SSID = 32;

        public const uint NDIS_802_11_LENGTH_RATES = 8;

        public const uint NDIS_802_11_LENGTH_RATES_EX = 16;

        public const uint NDIS_802_11_AUTH_REQUEST_AUTH_FIELDS = 0x0f;

        public const uint NDIS_802_11_AUTH_REQUEST_REAUTH = 0x01;

        public const uint NDIS_802_11_AUTH_REQUEST_KEYUPDATE = 0x02;

        public const uint NDIS_802_11_AUTH_REQUEST_PAIRWISE_ERROR = 0x06;

        public const uint NDIS_802_11_AUTH_REQUEST_GROUP_ERROR = 0x0E;

        public const uint NDIS_802_11_PMKID_CANDIDATE_PREAUTH_ENABLED = 0x01;

        public const uint NDIS_802_11_AI_REQFI_CAPABILITIES = 1;

        public const uint NDIS_802_11_AI_REQFI_LISTENINTERVAL = 2;

        public const uint NDIS_802_11_AI_REQFI_CURRENTAPADDRESS = 4;

        public const uint NDIS_802_11_AI_RESFI_CAPABILITIES = 1;

        public const uint NDIS_802_11_AI_RESFI_STATUSCODE = 2;

        public const uint NDIS_802_11_AI_RESFI_ASSOCIATIONID = 4;

        public const uint OID_IRDA_RECEIVING = 0x0A010100;

        public const uint OID_IRDA_TURNAROUND_TIME = 0x0A010101;

        public const uint OID_IRDA_SUPPORTED_SPEEDS = 0x0A010102;

        public const uint OID_IRDA_LINK_SPEED = 0x0A010103;

        public const uint OID_IRDA_MEDIA_BUSY = 0x0A010104;

        public const uint OID_IRDA_EXTRA_RCV_BOFS = 0x0A010200;

        public const uint OID_IRDA_RATE_SNIFF = 0x0A010201;

        public const uint OID_IRDA_UNICAST_LIST = 0x0A010202;

        public const uint OID_IRDA_MAX_UNICAST_LIST_SIZE = 0x0A010203;

        public const uint OID_IRDA_MAX_RECEIVE_WINDOW_SIZE = 0x0A010204;

        public const uint OID_IRDA_MAX_SEND_WINDOW_SIZE = 0x0A010205;

        public const uint OID_IRDA_RESERVED1 = 0x0A01020A;

        public const uint OID_IRDA_RESERVED2 = 0x0A01020F;

        public const uint OID_1394_LOCAL_NODE_INFO = 0x0C010101;

        public const uint OID_1394_VC_INFO = 0x0C010102;

        public const uint OID_CO_ADD_PVC = 0xFE000001;

        public const uint OID_CO_DELETE_PVC = 0xFE000002;

        public const uint OID_CO_GET_CALL_INFORMATION = 0xFE000003;

        public const uint OID_CO_ADD_ADDRESS = 0xFE000004;

        public const uint OID_CO_DELETE_ADDRESS = 0xFE000005;

        public const uint OID_CO_GET_ADDRESSES = 0xFE000006;

        public const uint OID_CO_ADDRESS_CHANGE = 0xFE000007;

        public const uint OID_CO_SIGNALING_ENABLED = 0xFE000008;

        public const uint OID_CO_SIGNALING_DISABLED = 0xFE000009;

        public const uint OID_CO_AF_CLOSE = 0xFE00000A;

        public const uint OID_CO_TAPI_CM_CAPS = 0xFE001001;

        public const uint OID_CO_TAPI_LINE_CAPS = 0xFE001002;

        public const uint OID_CO_TAPI_ADDRESS_CAPS = 0xFE001003;

        public const uint OID_CO_TAPI_TRANSLATE_TAPI_CALLPARAMS = 0xFE001004;

        public const uint OID_CO_TAPI_TRANSLATE_NDIS_CALLPARAMS = 0xFE001005;

        public const uint OID_CO_TAPI_TRANSLATE_TAPI_SAP = 0xFE001006;

        public const uint OID_CO_TAPI_GET_CALL_DIAGNOSTICS = 0xFE001007;

        public const uint OID_CO_TAPI_REPORT_DIGITS = 0xFE001008;

        public const uint OID_CO_TAPI_DONT_REPORT_DIGITS = 0xFE001009;

        public const uint OID_PNP_CAPABILITIES = 0xFD010100;

        public const uint OID_PNP_SET_POWER = 0xFD010101;

        public const uint OID_PNP_QUERY_POWER = 0xFD010102;

        public const uint OID_PNP_ADD_WAKE_UP_PATTERN = 0xFD010103;

        public const uint OID_PNP_REMOVE_WAKE_UP_PATTERN = 0xFD010104;

        public const uint OID_PNP_WAKE_UP_PATTERN_LIST = 0xFD010105;

        public const uint OID_PNP_ENABLE_WAKE_UP = 0xFD010106;

        public const uint OID_PNP_WAKE_UP_OK = 0xFD020200;

        public const uint OID_PNP_WAKE_UP_ERROR = 0xFD020201;

        public const uint OID_PM_CURRENT_CAPABILITIES = 0xFD010107;

        public const uint OID_PM_HARDWARE_CAPABILITIES = 0xFD010108;

        public const uint OID_PM_PARAMETERS = 0xFD010109;

        public const uint OID_PM_ADD_WOL_PATTERN = 0xFD01010A;

        public const uint OID_PM_REMOVE_WOL_PATTERN = 0xFD01010B;

        public const uint OID_PM_WOL_PATTERN_LIST = 0xFD01010C;

        public const uint OID_PM_ADD_PROTOCOL_OFFLOAD = 0xFD01010D;

        public const uint OID_PM_GET_PROTOCOL_OFFLOAD = 0xFD01010E;

        public const uint OID_PM_REMOVE_PROTOCOL_OFFLOAD = 0xFD01010F;

        public const uint OID_PM_PROTOCOL_OFFLOAD_LIST = 0xFD010110;

        public const uint OID_PM_RESERVED_1 = 0xFD010111;

        public const uint OID_RECEIVE_FILTER_HARDWARE_CAPABILITIES = 0x00010221;

        public const uint OID_RECEIVE_FILTER_GLOBAL_PARAMETERS = 0x00010222;

        public const uint OID_RECEIVE_FILTER_ALLOCATE_QUEUE = 0x00010223;

        public const uint OID_RECEIVE_FILTER_FREE_QUEUE = 0x00010224;

        public const uint OID_RECEIVE_FILTER_ENUM_QUEUES = 0x00010225;

        public const uint OID_RECEIVE_FILTER_QUEUE_PARAMETERS = 0x00010226;

        public const uint OID_RECEIVE_FILTER_SET_FILTER = 0x00010227;

        public const uint OID_RECEIVE_FILTER_CLEAR_FILTER = 0x00010228;

        public const uint OID_RECEIVE_FILTER_ENUM_FILTERS = 0x00010229;

        public const uint OID_RECEIVE_FILTER_PARAMETERS = 0x0001022A;

        public const uint OID_RECEIVE_FILTER_QUEUE_ALLOCATION_COMPLETE = 0x0001022B;

        public const uint OID_RECEIVE_FILTER_CURRENT_CAPABILITIES = 0x0001022D;

        public const uint OID_NIC_SWITCH_HARDWARE_CAPABILITIES = 0x0001022E;

        public const uint OID_NIC_SWITCH_CURRENT_CAPABILITIES = 0x0001022F;

        public const uint OID_RECEIVE_FILTER_MOVE_FILTER = 0x00010230;

        public const uint OID_VLAN_RESERVED1 = 0x00010231;

        public const uint OID_VLAN_RESERVED2 = 0x00010232;

        public const uint OID_VLAN_RESERVED3 = 0x00010233;

        public const uint OID_VLAN_RESERVED4 = 0x00010234;

        public const uint OID_PACKET_COALESCING_FILTER_MATCH_COUNT = 0x00010235;

        public const uint OID_NIC_SWITCH_CREATE_SWITCH = 0x00010237;

        public const uint OID_NIC_SWITCH_PARAMETERS = 0x00010238;

        public const uint OID_NIC_SWITCH_DELETE_SWITCH = 0x00010239;

        public const uint OID_NIC_SWITCH_ENUM_SWITCHES = 0x00010240;

        public const uint OID_NIC_SWITCH_CREATE_VPORT = 0x00010241;

        public const uint OID_NIC_SWITCH_VPORT_PARAMETERS = 0x00010242;

        public const uint OID_NIC_SWITCH_ENUM_VPORTS = 0x00010243;

        public const uint OID_NIC_SWITCH_DELETE_VPORT = 0x00010244;

        public const uint OID_NIC_SWITCH_ALLOCATE_VF = 0x00010245;

        public const uint OID_NIC_SWITCH_FREE_VF = 0x00010246;

        public const uint OID_NIC_SWITCH_VF_PARAMETERS = 0x00010247;

        public const uint OID_NIC_SWITCH_ENUM_VFS = 0x00010248;

        public const uint OID_SRIOV_HARDWARE_CAPABILITIES = 0x00010249;

        public const uint OID_SRIOV_CURRENT_CAPABILITIES = 0x00010250;

        public const uint OID_SRIOV_READ_VF_CONFIG_SPACE = 0x00010251;

        public const uint OID_SRIOV_WRITE_VF_CONFIG_SPACE = 0x00010252;

        public const uint OID_SRIOV_READ_VF_CONFIG_BLOCK = 0x00010253;

        public const uint OID_SRIOV_WRITE_VF_CONFIG_BLOCK = 0x00010254;

        public const uint OID_SRIOV_RESET_VF = 0x00010255;

        public const uint OID_SRIOV_SET_VF_POWER_STATE = 0x00010256;

        public const uint OID_SRIOV_VF_VENDOR_DEVICE_ID = 0x00010257;

        public const uint OID_SRIOV_PROBED_BARS = 0x00010258;

        public const uint OID_SRIOV_BAR_RESOURCES = 0x00010259;

        public const uint OID_SRIOV_PF_LUID = 0x00010260;

        public const uint OID_SRIOV_CONFIG_STATE = 0x00010261;

        public const uint OID_SRIOV_VF_SERIAL_NUMBER = 0x00010262;

        public const uint OID_SRIOV_OVERLYING_ADAPTER_INFO = 0x00010268;

        public const uint OID_SRIOV_VF_INVALIDATE_CONFIG_BLOCK = 0x00010269;

        public const uint OID_SWITCH_PROPERTY_ADD = 0x00010263;

        public const uint OID_SWITCH_PROPERTY_UPDATE = 0x00010264;

        public const uint OID_SWITCH_PROPERTY_DELETE = 0x00010265;

        public const uint OID_SWITCH_PROPERTY_ENUM = 0x00010266;

        public const uint OID_SWITCH_FEATURE_STATUS_QUERY = 0x00010267;

        public const uint OID_SWITCH_NIC_REQUEST = 0x00010270;

        public const uint OID_SWITCH_PORT_PROPERTY_ADD = 0x00010271;

        public const uint OID_SWITCH_PORT_PROPERTY_UPDATE = 0x00010272;

        public const uint OID_SWITCH_PORT_PROPERTY_DELETE = 0x00010273;

        public const uint OID_SWITCH_PORT_PROPERTY_ENUM = 0x00010274;

        public const uint OID_SWITCH_PARAMETERS = 0x00010275;

        public const uint OID_SWITCH_PORT_ARRAY = 0x00010276;

        public const uint OID_SWITCH_NIC_ARRAY = 0x00010277;

        public const uint OID_SWITCH_PORT_CREATE = 0x00010278;

        public const uint OID_SWITCH_PORT_DELETE = 0x00010279;

        public const uint OID_SWITCH_NIC_CREATE = 0x0001027A;

        public const uint OID_SWITCH_NIC_CONNECT = 0x0001027B;

        public const uint OID_SWITCH_NIC_DISCONNECT = 0x0001027C;

        public const uint OID_SWITCH_NIC_DELETE = 0x0001027D;

        public const uint OID_SWITCH_PORT_FEATURE_STATUS_QUERY = 0x0001027E;

        public const uint OID_SWITCH_PORT_TEARDOWN = 0x0001027F;

        public const uint OID_SWITCH_NIC_SAVE = 0x00010290;

        public const uint OID_SWITCH_NIC_SAVE_COMPLETE = 0x00010291;

        public const uint OID_SWITCH_NIC_RESTORE = 0x00010292;

        public const uint OID_SWITCH_NIC_RESTORE_COMPLETE = 0x00010293;

        public const uint OID_SWITCH_NIC_UPDATED = 0x00010294;

        public const uint OID_SWITCH_PORT_UPDATED = 0x00010295;

        public const uint OID_SWITCH_NIC_DIRECT_REQUEST = 0x00010296;

        public const uint OID_SWITCH_NIC_SUSPEND = 0x00010297;

        public const uint OID_SWITCH_NIC_RESUME = 0x00010298;

        public const uint OID_SWITCH_NIC_SUSPENDED_LM_SOURCE_STARTED = 0x00010299;

        public const uint OID_SWITCH_NIC_SUSPENDED_LM_SOURCE_FINISHED = 0x0001029A;

        public const uint OID_GEN_RSS_SET_INDIRECTION_TABLE_ENTRIES = 0x000102C0;

        public const uint OID_GEN_ISOLATION_PARAMETERS = 0x00010300;

        public const uint OID_GFT_HARDWARE_CAPABILITIES = 0x00010401;

        public const uint OID_GFT_CURRENT_CAPABILITIES = 0x00010402;

        public const uint OID_GFT_GLOBAL_PARAMETERS = 0x00010403;

        public const uint OID_GFT_CREATE_TABLE = 0x00010404;

        public const uint OID_GFT_DELETE_TABLE = 0x00010405;

        public const uint OID_GFT_ENUM_TABLES = 0x00010406;

        public const uint OID_GFT_ALLOCATE_COUNTERS = 0x00010407;

        public const uint OID_GFT_FREE_COUNTERS = 0x00010408;

        public const uint OID_GFT_ENUM_COUNTERS = 0x00010409;

        public const uint OID_GFT_COUNTER_VALUES = 0x0001040A;

        public const uint OID_GFT_STATISTICS = 0x0001040B;

        public const uint OID_GFT_ADD_FLOW_ENTRIES = 0x0001040C;

        public const uint OID_GFT_DELETE_FLOW_ENTRIES = 0x0001040D;

        public const uint OID_GFT_ENUM_FLOW_ENTRIES = 0x0001040E;

        public const uint OID_GFT_ACTIVATE_FLOW_ENTRIES = 0x0001040F;

        public const uint OID_GFT_DEACTIVATE_FLOW_ENTRIES = 0x00010410;

        public const uint OID_GFT_FLOW_ENTRY_PARAMETERS = 0x00010411;

        public const uint OID_GFT_EXACT_MATCH_PROFILE = 0x00010412;

        public const uint OID_GFT_HEADER_TRANSPOSITION_PROFILE = 0x00010413;

        public const uint OID_GFT_WILDCARD_MATCH_PROFILE = 0x00010414;

        public const uint OID_GFT_ENUM_PROFILES = 0x00010415;

        public const uint OID_GFT_DELETE_PROFILE = 0x00010416;

        public const uint OID_GFT_VPORT_PARAMETERS = 0x00010417;

        public const uint OID_GFT_CREATE_LOGICAL_VPORT = 0x00010418;

        public const uint OID_GFT_DELETE_LOGICAL_VPORT = 0x00010419;

        public const uint OID_GFT_ENUM_LOGICAL_VPORTS = 0x0001041A;

        public const uint OID_QOS_OFFLOAD_HARDWARE_CAPABILITIES = 0x00010601;

        public const uint OID_QOS_OFFLOAD_CURRENT_CAPABILITIES = 0x00010602;

        public const uint OID_QOS_OFFLOAD_CREATE_SQ = 0x00010603;

        public const uint OID_QOS_OFFLOAD_DELETE_SQ = 0x00010604;

        public const uint OID_QOS_OFFLOAD_UPDATE_SQ = 0x00010605;

        public const uint OID_QOS_OFFLOAD_ENUM_SQS = 0x00010606;

        public const uint OID_QOS_OFFLOAD_SQ_STATS = 0x00010607;

        public const uint OID_PD_OPEN_PROVIDER = 0x00010501;

        public const uint OID_PD_CLOSE_PROVIDER = 0x00010502;

        public const uint OID_PD_QUERY_CURRENT_CONFIG = 0x00010503;

        public const uint NDIS_PNP_WAKE_UP_MAGIC_PACKET = 0x00000001;

        public const uint NDIS_PNP_WAKE_UP_PATTERN_MATCH = 0x00000002;

        public const uint NDIS_PNP_WAKE_UP_LINK_CHANGE = 0x00000004;

        public const uint OID_TCP_TASK_OFFLOAD = 0xFC010201;

        public const uint OID_TCP_TASK_IPSEC_ADD_SA = 0xFC010202;

        public const uint OID_TCP_TASK_IPSEC_DELETE_SA = 0xFC010203;

        public const uint OID_TCP_SAN_SUPPORT = 0xFC010204;

        public const uint OID_TCP_TASK_IPSEC_ADD_UDPESP_SA = 0xFC010205;

        public const uint OID_TCP_TASK_IPSEC_DELETE_UDPESP_SA = 0xFC010206;

        public const uint OID_TCP4_OFFLOAD_STATS = 0xFC010207;

        public const uint OID_TCP6_OFFLOAD_STATS = 0xFC010208;

        public const uint OID_IP4_OFFLOAD_STATS = 0xFC010209;

        public const uint OID_IP6_OFFLOAD_STATS = 0xFC01020A;

        public const uint OID_TCP_OFFLOAD_CURRENT_CONFIG = 0xFC01020B;

        public const uint OID_TCP_OFFLOAD_PARAMETERS = 0xFC01020C;

        public const uint OID_TCP_OFFLOAD_HARDWARE_CAPABILITIES = 0xFC01020D;

        public const uint OID_TCP_CONNECTION_OFFLOAD_CURRENT_CONFIG = 0xFC01020E;

        public const uint OID_TCP_CONNECTION_OFFLOAD_HARDWARE_CAPABILITIES = 0xFC01020F;

        public const uint OID_OFFLOAD_ENCAPSULATION = 0x0101010A;

        public const uint OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA = 0xFC030202;

        public const uint OID_TCP_TASK_IPSEC_OFFLOAD_V2_DELETE_SA = 0xFC030203;

        public const uint OID_TCP_TASK_IPSEC_OFFLOAD_V2_UPDATE_SA = 0xFC030204;

        public const uint OID_TCP_TASK_IPSEC_OFFLOAD_V2_ADD_SA_EX = 0xFC030205;

        public const uint OID_FFP_SUPPORT = 0xFC010210;

        public const uint OID_FFP_FLUSH = 0xFC010211;

        public const uint OID_FFP_CONTROL = 0xFC010212;

        public const uint OID_FFP_PARAMS = 0xFC010213;

        public const uint OID_FFP_DATA = 0xFC010214;

        public const uint OID_FFP_DRIVER_STATS = 0xFC020210;

        public const uint OID_FFP_ADAPTER_STATS = 0xFC020211;

        public const uint OID_TCP_CONNECTION_OFFLOAD_PARAMETERS = 0xFC030201;

        public const uint OID_TUNNEL_INTERFACE_SET_OID = 0x0f010106;

        public const uint OID_TUNNEL_INTERFACE_RELEASE_OID = 0x0f010107;

        public const uint OID_QOS_RESERVED1 = 0xFB010100;

        public const uint OID_QOS_RESERVED2 = 0xFB010101;

        public const uint OID_QOS_RESERVED3 = 0xFB010102;

        public const uint OID_QOS_RESERVED4 = 0xFB010103;

        public const uint OID_QOS_RESERVED5 = 0xFB010104;

        public const uint OID_QOS_RESERVED6 = 0xFB010105;

        public const uint OID_QOS_RESERVED7 = 0xFB010106;

        public const uint OID_QOS_RESERVED8 = 0xFB010107;

        public const uint OID_QOS_RESERVED9 = 0xFB010108;

        public const uint OID_QOS_RESERVED10 = 0xFB010109;

        public const uint OID_QOS_RESERVED11 = 0xFB01010A;

        public const uint OID_QOS_RESERVED12 = 0xFB01010B;

        public const uint OID_QOS_RESERVED13 = 0xFB01010C;

        public const uint OID_QOS_RESERVED14 = 0xFB01010D;

        public const uint OID_QOS_RESERVED15 = 0xFB01010E;

        public const uint OID_QOS_RESERVED16 = 0xFB01010F;

        public const uint OID_QOS_RESERVED17 = 0xFB010110;

        public const uint OID_QOS_RESERVED18 = 0xFB010111;

        public const uint OID_QOS_RESERVED19 = 0xFB010112;

        public const uint OID_QOS_RESERVED20 = 0xFB010113;

        public const uint OID_XBOX_ACC_RESERVED0 = 0xFA000000;

        public const uint OFFLOAD_MAX_SAS = 3;

        public const uint OFFLOAD_INBOUND_SA = 0x0001;

        public const uint OFFLOAD_OUTBOUND_SA = 0x0002;

        public const uint NDIS_PROTOCOL_ID_DEFAULT = 0x00;

        public const uint NDIS_PROTOCOL_ID_TCP_IP = 0x02;

        public const uint NDIS_PROTOCOL_ID_IP6 = 0x03;

        public const uint NDIS_PROTOCOL_ID_IPX = 0x06;

        public const uint NDIS_PROTOCOL_ID_NBF = 0x07;

        public const uint NDIS_PROTOCOL_ID_MAX = 0x0F;

        public const uint NDIS_PROTOCOL_ID_MASK = 0x0F;

        public const uint READABLE_LOCAL_CLOCK = 0x00000001;

        public const uint CLOCK_NETWORK_DERIVED = 0x00000002;

        public const uint CLOCK_PRECISION = 0x00000004;

        public const uint RECEIVE_TIME_INDICATION_CAPABLE = 0x00000008;

        public const uint TIMED_SEND_CAPABLE = 0x00000010;

        public const uint TIME_STAMP_CAPABLE = 0x00000020;

        public const uint NDIS_DEVICE_WAKE_UP_ENABLE = 0x00000001;

        public const uint NDIS_DEVICE_WAKE_ON_PATTERN_MATCH_ENABLE = 0x00000002;

        public const uint NDIS_DEVICE_WAKE_ON_MAGIC_PACKET_ENABLE = 0x00000004;

        public const uint WAN_PROTOCOL_KEEPS_STATS = 0x00000001;

        public const uint NDIS_PACKET_TYPE_DIRECTED = 0x00000001;

        public const uint NDIS_PACKET_TYPE_MULTICAST = 0x00000002;

        public const uint NDIS_PACKET_TYPE_ALL_MULTICAST = 0x00000004;

        public const uint NDIS_PACKET_TYPE_BROADCAST = 0x00000008;

        public const uint NDIS_PACKET_TYPE_SOURCE_ROUTING = 0x00000010;

        public const uint NDIS_PACKET_TYPE_PROMISCUOUS = 0x00000020;

        public const uint NDIS_PACKET_TYPE_SMT = 0x00000040;

        public const uint NDIS_PACKET_TYPE_ALL_LOCAL = 0x00000080;

        public const uint NDIS_PACKET_TYPE_GROUP = 0x00001000;

        public const uint NDIS_PACKET_TYPE_ALL_FUNCTIONAL = 0x00002000;

        public const uint NDIS_PACKET_TYPE_FUNCTIONAL = 0x00004000;

        public const uint NDIS_PACKET_TYPE_MAC_FRAME = 0x00008000;

        public const uint NDIS_PACKET_TYPE_NO_LOCAL = 0x00010000;

        public const uint NDIS_RING_SIGNAL_LOSS = 0x00008000;

        public const uint NDIS_RING_HARD_ERROR = 0x00004000;

        public const uint NDIS_RING_SOFT_ERROR = 0x00002000;

        public const uint NDIS_RING_TRANSMIT_BEACON = 0x00001000;

        public const uint NDIS_RING_LOBE_WIRE_FAULT = 0x00000800;

        public const uint NDIS_RING_AUTO_REMOVAL_ERROR = 0x00000400;

        public const uint NDIS_RING_REMOVE_RECEIVED = 0x00000200;

        public const uint NDIS_RING_COUNTER_OVERFLOW = 0x00000100;

        public const uint NDIS_RING_SINGLE_STATION = 0x00000080;

        public const uint NDIS_RING_RING_RECOVERY = 0x00000040;

        public const uint NDIS_PROT_OPTION_ESTIMATED_LENGTH = 0x00000001;

        public const uint NDIS_PROT_OPTION_NO_LOOPBACK = 0x00000002;

        public const uint NDIS_PROT_OPTION_NO_RSVD_ON_RCVPKT = 0x00000004;

        public const uint NDIS_PROT_OPTION_SEND_RESTRICTED = 0x00000008;

        public const uint NDIS_MAC_OPTION_COPY_LOOKAHEAD_DATA = 0x00000001;

        public const uint NDIS_MAC_OPTION_RECEIVE_SERIALIZED = 0x00000002;

        public const uint NDIS_MAC_OPTION_TRANSFERS_NOT_PEND = 0x00000004;

        public const uint NDIS_MAC_OPTION_NO_LOOPBACK = 0x00000008;

        public const uint NDIS_MAC_OPTION_FULL_DUPLEX = 0x00000010;

        public const uint NDIS_MAC_OPTION_EOTX_INDICATION = 0x00000020;

        public const uint NDIS_MAC_OPTION_8021P_PRIORITY = 0x00000040;

        public const uint NDIS_MAC_OPTION_SUPPORTS_MAC_ADDRESS_OVERWRITE = 0x00000080;

        public const uint NDIS_MAC_OPTION_RECEIVE_AT_DPC = 0x00000100;

        public const uint NDIS_MAC_OPTION_8021Q_VLAN = 0x00000200;

        public const uint NDIS_MAC_OPTION_RESERVED = 0x80000000;

        public const uint NDIS_MEDIA_CAP_TRANSMIT = 0x00000001;

        public const uint NDIS_MEDIA_CAP_RECEIVE = 0x00000002;

        public const uint NDIS_CO_MAC_OPTION_DYNAMIC_LINK_SPEED = 0x00000001;

        public const uint NDIS_LINK_STATE_XMIT_LINK_SPEED_AUTO_NEGOTIATED = 0x00000001;

        public const uint NDIS_LINK_STATE_RCV_LINK_SPEED_AUTO_NEGOTIATED = 0x00000002;

        public const uint NDIS_LINK_STATE_DUPLEX_AUTO_NEGOTIATED = 0x00000004;

        public const uint NDIS_LINK_STATE_PAUSE_FUNCTIONS_AUTO_NEGOTIATED = 0x00000008;

        public const uint NDIS_LINK_STATE_REVISION_1 = 1;

        public const uint NDIS_LINK_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_OPER_STATE_REVISION_1 = 1;

        public const uint MAXIMUM_IP_OPER_STATUS_ADDRESS_FAMILIES_SUPPORTED = 32;

        public const uint NDIS_IP_OPER_STATUS_INFO_REVISION_1 = 1;

        public const uint NDIS_IP_OPER_STATE_REVISION_1 = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_NO_CHANGE = 0;

        public const uint NDIS_OFFLOAD_PARAMETERS_TX_RX_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_TX_ENABLED_RX_DISABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_RX_ENABLED_TX_DISABLED = 3;

        public const uint NDIS_OFFLOAD_PARAMETERS_TX_RX_ENABLED = 4;

        public const uint NDIS_OFFLOAD_PARAMETERS_LSOV1_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_LSOV1_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV1_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV1_AH_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV1_ESP_ENABLED = 3;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV1_AH_AND_ESP_ENABLED = 4;

        public const uint NDIS_OFFLOAD_PARAMETERS_LSOV2_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_LSOV2_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV2_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV2_AH_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV2_ESP_ENABLED = 3;

        public const uint NDIS_OFFLOAD_PARAMETERS_IPSECV2_AH_AND_ESP_ENABLED = 4;

        public const uint NDIS_OFFLOAD_PARAMETERS_RSC_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_RSC_ENABLED = 2;

        public const uint NDIS_ENCAPSULATION_TYPE_GRE_MAC = 0x00000001;

        public const uint NDIS_ENCAPSULATION_TYPE_VXLAN = 0x00000002;

        public const uint NDIS_OFFLOAD_PARAMETERS_CONNECTION_OFFLOAD_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_CONNECTION_OFFLOAD_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_USO_DISABLED = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_USO_ENABLED = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_OFFLOAD_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_OFFLOAD_PARAMETERS_REVISION_3 = 3;

        public const uint NDIS_OFFLOAD_PARAMETERS_REVISION_4 = 4;

        public const uint NDIS_OFFLOAD_PARAMETERS_REVISION_5 = 5;

        public const uint NDIS_OFFLOAD_PARAMETERS_SKIP_REGISTRY_UPDATE = 0x00000001;

        public const uint NDIS_OFFLOAD_NOT_SUPPORTED = 0;

        public const uint NDIS_OFFLOAD_SUPPORTED = 1;

        public const uint NDIS_OFFLOAD_SET_NO_CHANGE = 0;

        public const uint NDIS_OFFLOAD_SET_ON = 1;

        public const uint NDIS_OFFLOAD_SET_OFF = 2;

        public const uint NDIS_ENCAPSULATION_NOT_SUPPORTED = 0x00000000;

        public const uint NDIS_ENCAPSULATION_NULL = 0x00000001;

        public const uint NDIS_ENCAPSULATION_IEEE_802_3 = 0x00000002;

        public const uint NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q = 0x00000004;

        public const uint NDIS_ENCAPSULATION_IEEE_802_3_P_AND_Q_IN_OOB = 0x00000008;

        public const uint NDIS_ENCAPSULATION_IEEE_LLC_SNAP_ROUTED = 0x00000010;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_MD5 = 0x00000001;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_1 = 0x00000002;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_SHA_256 = 0x00000004;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_128 = 0x00000008;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_192 = 0x00000010;

        public const uint IPSEC_OFFLOAD_V2_AUTHENTICATION_AES_GCM_256 = 0x00000020;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_NONE = 0x00000001;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_DES_CBC = 0x00000002;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_3_DES_CBC = 0x00000004;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_128 = 0x00000008;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_192 = 0x00000010;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_GCM_256 = 0x00000020;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_128 = 0x00000040;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_192 = 0x00000080;

        public const uint IPSEC_OFFLOAD_V2_ENCRYPTION_AES_CBC_256 = 0x00000100;

        public const uint NDIS_TCP_RECV_SEG_COALESC_OFFLOAD_REVISION_1 = 1;

        public const uint NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_NOT_SUPPORTED = 0x00000000;

        public const uint NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_INNER_IPV4 = 0x00000001;

        public const uint NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV4 = 0x00000002;

        public const uint NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_INNER_IPV6 = 0x00000004;

        public const uint NDIS_ENCAPSULATED_PACKET_TASK_OFFLOAD_OUTER_IPV6 = 0x00000008;

        public const uint NDIS_OFFLOAD_FLAGS_GROUP_CHECKSUM_CAPABILITIES = 0x00000001;

        public const uint IPSEC_OFFLOAD_V2_AND_TCP_CHECKSUM_COEXISTENCE = 0x00000002;

        public const uint IPSEC_OFFLOAD_V2_AND_UDP_CHECKSUM_COEXISTENCE = 0x00000004;

        public const uint NDIS_OFFLOAD_REVISION_1 = 1;

        public const uint NDIS_OFFLOAD_REVISION_2 = 2;

        public const uint NDIS_OFFLOAD_REVISION_3 = 3;

        public const uint NDIS_OFFLOAD_REVISION_4 = 4;

        public const uint NDIS_OFFLOAD_REVISION_5 = 5;

        public const uint NDIS_OFFLOAD_REVISION_6 = 6;

        public const uint NDIS_TCP_CONNECTION_OFFLOAD_REVISION_1 = 1;

        public const uint NDIS_TCP_CONNECTION_OFFLOAD_REVISION_2 = 2;

        public const uint NDIS_MAXIMUM_PORTS = 0x1000000;

        public const uint NDIS_PORT_AUTHENTICATION_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_WMI_DEFAULT_METHOD_ID = 1;

        public const uint NDIS_WMI_OBJECT_TYPE_SET = 0x01;

        public const uint NDIS_WMI_OBJECT_TYPE_METHOD = 0x02;

        public const uint NDIS_WMI_OBJECT_TYPE_EVENT = 0x03;

        public const uint NDIS_WMI_OBJECT_TYPE_ENUM_ADAPTER = 0x04;

        public const uint NDIS_WMI_OBJECT_TYPE_OUTPUT_INFO = 0x05;

        public const uint NDIS_WMI_METHOD_HEADER_REVISION_1 = 1;

        public const uint NDIS_WMI_SET_HEADER_REVISION_1 = 1;

        public const uint NDIS_WMI_EVENT_HEADER_REVISION_1 = 1;

        public const uint NDIS_WMI_ENUM_ADAPTER_REVISION_1 = 1;

        public const uint NDIS_DEVICE_TYPE_ENDPOINT = 0x00000001;

        public const uint NDIS_HD_SPLIT_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_HD_SPLIT_COMBINE_ALL_HEADERS = 0x00000001;

        public const uint NDIS_HD_SPLIT_CURRENT_CONFIG_REVISION_1 = 1;

        public const uint NDIS_HD_SPLIT_CAPS_SUPPORTS_HEADER_DATA_SPLIT = 0x00000001;

        public const uint NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV4_OPTIONS = 0x00000002;

        public const uint NDIS_HD_SPLIT_CAPS_SUPPORTS_IPV6_EXTENSION_HEADERS = 0x00000004;

        public const uint NDIS_HD_SPLIT_CAPS_SUPPORTS_TCP_OPTIONS = 0x00000008;

        public const uint NDIS_HD_SPLIT_ENABLE_HEADER_DATA_SPLIT = 0x00000001;

        public const uint NDIS_PM_WOL_BITMAP_PATTERN_SUPPORTED = 0x00000001;

        public const uint NDIS_PM_WOL_MAGIC_PACKET_SUPPORTED = 0x00000002;

        public const uint NDIS_PM_WOL_IPV4_TCP_SYN_SUPPORTED = 0x00000004;

        public const uint NDIS_PM_WOL_IPV6_TCP_SYN_SUPPORTED = 0x00000008;

        public const uint NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_SUPPORTED = 0x00000200;

        public const uint NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_SUPPORTED = 0x00000800;

        public const uint NDIS_PM_WOL_EAPOL_REQUEST_ID_MESSAGE_SUPPORTED = 0x00010000;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_ARP_SUPPORTED = 0x00000001;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_NS_SUPPORTED = 0x00000002;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_80211_RSN_REKEY_SUPPORTED = 0x00000080;

        public const uint NDIS_PM_WAKE_ON_MEDIA_CONNECT_SUPPORTED = 0x00000001;

        public const uint NDIS_PM_WAKE_ON_MEDIA_DISCONNECT_SUPPORTED = 0x00000002;

        public const uint NDIS_WLAN_WAKE_ON_NLO_DISCOVERY_SUPPORTED = 0x00000001;

        public const uint NDIS_WLAN_WAKE_ON_AP_ASSOCIATION_LOST_SUPPORTED = 0x00000002;

        public const uint NDIS_WLAN_WAKE_ON_GTK_HANDSHAKE_ERROR_SUPPORTED = 0x00000004;

        public const uint NDIS_WLAN_WAKE_ON_4WAY_HANDSHAKE_REQUEST_SUPPORTED = 0x00000008;

        public const uint NDIS_WWAN_WAKE_ON_REGISTER_STATE_SUPPORTED = 0x00000001;

        public const uint NDIS_WWAN_WAKE_ON_SMS_RECEIVE_SUPPORTED = 0x00000002;

        public const uint NDIS_WWAN_WAKE_ON_USSD_RECEIVE_SUPPORTED = 0x00000004;

        public const uint NDIS_WWAN_WAKE_ON_PACKET_STATE_SUPPORTED = 0x00000008;

        public const uint NDIS_WWAN_WAKE_ON_UICC_CHANGE_SUPPORTED = 0x00000010;

        public const uint NDIS_PM_WAKE_PACKET_INDICATION_SUPPORTED = 0x00000001;

        public const uint NDIS_PM_SELECTIVE_SUSPEND_SUPPORTED = 0x00000002;

        public const uint NDIS_PM_WOL_BITMAP_PATTERN_ENABLED = 0x00000001;

        public const uint NDIS_PM_WOL_MAGIC_PACKET_ENABLED = 0x00000002;

        public const uint NDIS_PM_WOL_IPV4_TCP_SYN_ENABLED = 0x00000004;

        public const uint NDIS_PM_WOL_IPV6_TCP_SYN_ENABLED = 0x00000008;

        public const uint NDIS_PM_WOL_IPV4_DEST_ADDR_WILDCARD_ENABLED = 0x00000200;

        public const uint NDIS_PM_WOL_IPV6_DEST_ADDR_WILDCARD_ENABLED = 0x00000800;

        public const uint NDIS_PM_WOL_EAPOL_REQUEST_ID_MESSAGE_ENABLED = 0x00010000;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_ARP_ENABLED = 0x00000001;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_NS_ENABLED = 0x00000002;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_80211_RSN_REKEY_ENABLED = 0x00000080;

        public const uint NDIS_PM_WAKE_ON_LINK_CHANGE_ENABLED = 0x00000001;

        public const uint NDIS_PM_WAKE_ON_MEDIA_DISCONNECT_ENABLED = 0x00000002;

        public const uint NDIS_PM_SELECTIVE_SUSPEND_ENABLED = 0x00000010;

        public const uint NDIS_WLAN_WAKE_ON_NLO_DISCOVERY_ENABLED = 0x00000001;

        public const uint NDIS_WLAN_WAKE_ON_AP_ASSOCIATION_LOST_ENABLED = 0x00000002;

        public const uint NDIS_WLAN_WAKE_ON_GTK_HANDSHAKE_ERROR_ENABLED = 0x00000004;

        public const uint NDIS_WLAN_WAKE_ON_4WAY_HANDSHAKE_REQUEST_ENABLED = 0x00000008;

        public const uint NDIS_WWAN_WAKE_ON_REGISTER_STATE_ENABLED = 0x00000001;

        public const uint NDIS_WWAN_WAKE_ON_SMS_RECEIVE_ENABLED = 0x00000002;

        public const uint NDIS_WWAN_WAKE_ON_USSD_RECEIVE_ENABLED = 0x00000004;

        public const uint NDIS_WWAN_WAKE_ON_PACKET_STATE_ENABLED = 0x00000008;

        public const uint NDIS_WWAN_WAKE_ON_UICC_CHANGE_ENABLED = 0x00000010;

        public const uint NDIS_PM_WOL_PRIORITY_LOWEST = 0xFFFFFFFF;

        public const uint NDIS_PM_WOL_PRIORITY_NORMAL = 0x10000000;

        public const uint NDIS_PM_WOL_PRIORITY_HIGHEST = 0x00000001;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_LOWEST = 0xFFFFFFFF;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_NORMAL = 0x10000000;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_PRIORITY_HIGHEST = 0x00000001;

        public const uint NDIS_PM_MAX_STRING_SIZE = 64;

        public const uint NDIS_PM_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_PM_CAPABILITIES_REVISION_2 = 2;

        public const uint NDIS_PM_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_PM_PARAMETERS_REVISION_2 = 2;

        public const uint EAPOL_REQUEST_ID_WOL_FLAG_MUST_ENCRYPT = 0x00000001;

        public const uint NDIS_PM_MAX_PATTERN_ID = 0x0000FFFF;

        public const uint NDIS_PM_PRIVATE_PATTERN_ID = 0x00000001;

        public const uint NDIS_PM_WOL_PATTERN_REVISION_1 = 1;

        public const uint NDIS_PM_WOL_PATTERN_REVISION_2 = 2;

        public const uint DOT11_RSN_KCK_LENGTH = 16;

        public const uint DOT11_RSN_KEK_LENGTH = 16;

        public const uint DOT11_RSN_MAX_CIPHER_KEY_LENGTH = 32;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1 = 1;

        public const uint NDIS_PM_PROTOCOL_OFFLOAD_REVISION_2 = 2;

        public const uint NDIS_SIZEOF_NDIS_PM_PROTOCOL_OFFLOAD_REVISION_1 = 0xF0;

        public const uint NDIS_PM_WAKE_REASON_REVISION_1 = 1;

        public const uint NDIS_PM_WAKE_PACKET_REVISION_1 = 1;

        public const uint NDIS_WMI_PM_ADMIN_CONFIG_REVISION_1 = 1;

        public const uint NDIS_WMI_PM_ACTIVE_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_IPV4_HEADER_SUPPORTED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_IPV6_HEADER_SUPPORTED = 0x00000004;

        public const uint NDIS_RECEIVE_FILTER_ARP_HEADER_SUPPORTED = 0x00000008;

        public const uint NDIS_RECEIVE_FILTER_UDP_HEADER_SUPPORTED = 0x00000010;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_DEST_ADDR_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_SOURCE_ADDR_SUPPORTED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_PROTOCOL_SUPPORTED = 0x00000004;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_VLAN_ID_SUPPORTED = 0x00000008;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_PRIORITY_SUPPORTED = 0x00000010;

        public const uint NDIS_RECEIVE_FILTER_MAC_HEADER_PACKET_TYPE_SUPPORTED = 0x00000020;

        public const uint NDIS_RECEIVE_FILTER_ARP_HEADER_OPERATION_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_ARP_HEADER_SPA_SUPPORTED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_ARP_HEADER_TPA_SUPPORTED = 0x00000004;

        public const uint NDIS_RECEIVE_FILTER_IPV4_HEADER_PROTOCOL_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_IPV6_HEADER_PROTOCOL_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_UDP_HEADER_DEST_PORT_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_EQUAL_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_MASK_EQUAL_SUPPORTED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_TEST_HEADER_FIELD_NOT_EQUAL_SUPPORTED = 0x00000004;

        public const uint NDIS_RECEIVE_FILTER_MSI_X_SUPPORTED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_VM_QUEUE_SUPPORTED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_LOOKAHEAD_SPLIT_SUPPORTED = 0x00000004;

        public const uint NDIS_RECEIVE_FILTER_DYNAMIC_PROCESSOR_AFFINITY_CHANGE_SUPPORTED = 0x00000008;

        public const uint NDIS_RECEIVE_FILTER_INTERRUPT_VECTOR_COALESCING_SUPPORTED = 0x00000010;

        public const uint NDIS_RECEIVE_FILTER_IMPLAT_MIN_OF_QUEUES_MODE = 0x00000040;

        public const uint NDIS_RECEIVE_FILTER_IMPLAT_SUM_OF_QUEUES_MODE = 0x00000080;

        public const uint NDIS_RECEIVE_FILTER_PACKET_COALESCING_SUPPORTED_ON_DEFAULT_QUEUE = 0x00000100;

        public const uint NDIS_RECEIVE_FILTER_ANY_VLAN_SUPPORTED = 0x00000020;

        public const uint NDIS_RECEIVE_FILTER_DYNAMIC_PROCESSOR_AFFINITY_CHANGE_FOR_DEFAULT_QUEUE_SUPPORTED = 0x00000040;

        public const uint NDIS_RECEIVE_FILTER_VMQ_FILTERS_ENABLED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_PACKET_COALESCING_FILTERS_ENABLED = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_VM_QUEUES_ENABLED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_CAPABILITIES_REVISION_2 = 2;

        public const uint NDIS_NIC_SWITCH_CAPS_VLAN_SUPPORTED = 0x00000001;

        public const uint NDIS_NIC_SWITCH_CAPS_PER_VPORT_INTERRUPT_MODERATION_SUPPORTED = 0x00000002;

        public const uint NDIS_NIC_SWITCH_CAPS_ASYMMETRIC_QUEUE_PAIRS_FOR_NONDEFAULT_VPORT_SUPPORTED = 0x00000004;

        public const uint NDIS_NIC_SWITCH_CAPS_VF_RSS_SUPPORTED = 0x00000008;

        public const uint NDIS_NIC_SWITCH_CAPS_SINGLE_VPORT_POOL = 0x00000010;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PARAMETERS_PER_PF_VPORT_SUPPORTED = 0x00000020;

        public const uint NDIS_NIC_SWITCH_CAPS_NIC_SWITCH_WITHOUT_IOV_SUPPORTED = 0x00000040;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_ON_PF_VPORTS_SUPPORTED = 0x00000080;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_INDIRECTION_TABLE_SUPPORTED = 0x00000100;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_FUNCTION_SUPPORTED = 0x00000200;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_TYPE_SUPPORTED = 0x00000400;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_HASH_KEY_SUPPORTED = 0x00000800;

        public const uint NDIS_NIC_SWITCH_CAPS_RSS_PER_PF_VPORT_INDIRECTION_TABLE_SIZE_RESTRICTED = 0x00001000;

        public const uint NDIS_NIC_SWITCH_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_CAPABILITIES_REVISION_2 = 2;

        public const uint NDIS_NIC_SWITCH_CAPABILITIES_REVISION_3 = 3;

        public const uint NDIS_RECEIVE_FILTER_GLOBAL_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_DEFAULT_RECEIVE_QUEUE_ID = 0;

        public const uint NDIS_DEFAULT_RECEIVE_QUEUE_GROUP_ID = 0;

        public const uint NDIS_DEFAULT_RECEIVE_FILTER_ID = 0;

        public const uint NDIS_RECEIVE_FILTER_FIELD_MAC_HEADER_VLAN_UNTAGGED_OR_ZERO = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_FIELD_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_FILTER_FLAGS_RESERVED = 0x00000001;

        public const uint NDIS_RECEIVE_FILTER_PACKET_ENCAPSULATION_GRE = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_PACKET_ENCAPSULATION = 0x00000002;

        public const uint NDIS_RECEIVE_FILTER_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_FILTER_CLEAR_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_PER_QUEUE_RECEIVE_INDICATION = 0x00000001;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_LOOKAHEAD_SPLIT_REQUIRED = 0x00000002;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_FLAGS_CHANGED = 0x00010000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_PROCESSOR_AFFINITY_CHANGED = 0x00020000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_SUGGESTED_RECV_BUFFER_NUMBERS_CHANGED = 0x00040000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_NAME_CHANGED = 0x00080000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_INTERRUPT_COALESCING_DOMAIN_ID_CHANGED = 0x00100000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_QOS_SQ_ID_CHANGED = 0x00200000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_CHANGE_MASK = 0xFFFF0000;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_QUEUE_PARAMETERS_REVISION_3 = 3;

        public const uint NDIS_RECEIVE_QUEUE_FREE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_QUEUE_INFO_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_QUEUE_INFO_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_QUEUE_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_INFO_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_INFO_ARRAY_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_FILTER_INFO_ARRAY_VPORT_ID_SPECIFIED = 0x00000001;

        public const uint NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_QUEUE_ALLOCATION_COMPLETE_ARRAY_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_SCALE_CAPABILITIES_REVISION_3 = 3;

        public const uint NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV4 = 0x00000100;

        public const uint NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6 = 0x00000200;

        public const uint NDIS_RSS_CAPS_HASH_TYPE_TCP_IPV6_EX = 0x00000400;

        public const uint NDIS_RSS_CAPS_MESSAGE_SIGNALED_INTERRUPTS = 0x01000000;

        public const uint NDIS_RSS_CAPS_CLASSIFICATION_AT_ISR = 0x02000000;

        public const uint NDIS_RSS_CAPS_CLASSIFICATION_AT_DPC = 0x04000000;

        public const uint NdisHashFunctionToeplitz = 0x00000001;

        public const uint NdisHashFunctionReserved1 = 0x00000002;

        public const uint NdisHashFunctionReserved2 = 0x00000004;

        public const uint NdisHashFunctionReserved3 = 0x00000008;

        public const uint NDIS_HASH_FUNCTION_MASK = 0x000000FF;

        public const uint NDIS_HASH_TYPE_MASK = 0x00FFFF00;

        public const uint NDIS_HASH_IPV4 = 0x00000100;

        public const uint NDIS_HASH_TCP_IPV4 = 0x00000200;

        public const uint NDIS_HASH_IPV6 = 0x00000400;

        public const uint NDIS_HASH_IPV6_EX = 0x00000800;

        public const uint NDIS_HASH_TCP_IPV6 = 0x00001000;

        public const uint NDIS_HASH_TCP_IPV6_EX = 0x00002000;

        public const uint NDIS_RSS_PARAM_FLAG_BASE_CPU_UNCHANGED = 0x0001;

        public const uint NDIS_RSS_PARAM_FLAG_HASH_INFO_UNCHANGED = 0x0002;

        public const uint NDIS_RSS_PARAM_FLAG_ITABLE_UNCHANGED = 0x0004;

        public const uint NDIS_RSS_PARAM_FLAG_HASH_KEY_UNCHANGED = 0x0008;

        public const uint NDIS_RSS_PARAM_FLAG_DISABLE_RSS = 0x0010;

        public const uint NDIS_RSS_PARAM_FLAG_DEFAULT_PROCESSOR_UNCHANGED = 0x0020;

        public const uint NDIS_RSS_INDIRECTION_TABLE_SIZE_REVISION_1 = 128;

        public const uint NDIS_RSS_HASH_SECRET_KEY_SIZE_REVISION_1 = 40;

        public const uint NDIS_RECEIVE_SCALE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_SCALE_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_RECEIVE_SCALE_PARAMETERS_REVISION_3 = 3;

        public const uint NDIS_RSS_INDIRECTION_TABLE_MAX_SIZE_REVISION_1 = 128;

        public const uint NDIS_RSS_HASH_SECRET_KEY_MAX_SIZE_REVISION_1 = 40;

        public const uint NDIS_RSS_HASH_SECRET_KEY_MAX_SIZE_REVISION_2 = 40;

        public const uint NDIS_RSS_HASH_SECRET_KEY_MAX_SIZE_REVISION_3 = 40;

        public const uint NDIS_RECEIVE_SCALE_PARAMETERS_V2_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_SCALE_PARAM_ENABLE_RSS = 0x00000001;

        public const uint NDIS_RECEIVE_SCALE_PARAM_HASH_INFO_CHANGED = 0x00000002;

        public const uint NDIS_RECEIVE_SCALE_PARAM_HASH_KEY_CHANGED = 0x00000004;

        public const uint NDIS_RECEIVE_SCALE_PARAM_NUMBER_OF_QUEUES_CHANGED = 0x00000008;

        public const uint NDIS_RECEIVE_SCALE_PARAM_NUMBER_OF_ENTRIES_CHANGED = 0x00000010;

        public const uint NDIS_RSS_SET_INDIRECTION_ENTRY_FLAG_PRIMARY_PROCESSOR = 0x00000001;

        public const uint NDIS_RSS_SET_INDIRECTION_ENTRY_FLAG_DEFAULT_PROCESSOR = 0x00000002;

        public const uint NDIS_RSS_SET_INDIRECTION_ENTRIES_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_HASH_FLAG_ENABLE_HASH = 0x00000001;

        public const uint NDIS_RECEIVE_HASH_FLAG_HASH_INFO_UNCHANGED = 0x00000002;

        public const uint NDIS_RECEIVE_HASH_FLAG_HASH_KEY_UNCHANGED = 0x00000004;

        public const uint NDIS_RECEIVE_HASH_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_RSS_PROCESSOR_INFO_REVISION_1 = 1;

        public const uint NDIS_RSS_PROCESSOR_INFO_REVISION_2 = 2;

        public const uint NDIS_SYSTEM_PROCESSOR_INFO_EX_REVISION_1 = 1;

        public const uint NDIS_HYPERVISOR_INFO_FLAG_HYPERVISOR_PRESENT = 0x00000001;

        public const uint NDIS_HYPERVISOR_INFO_REVISION_1 = 1;

        public const uint NDIS_WMI_RECEIVE_QUEUE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_WMI_RECEIVE_QUEUE_INFO_REVISION_1 = 1;

        public const uint NDIS_NDK_CAPABILITIES_REVISION_1 = 1;

        public const uint OID_NDK_SET_STATE = 0xFC040201;

        public const uint OID_NDK_STATISTICS = 0xFC040202;

        public const uint OID_NDK_CONNECTIONS = 0xFC040203;

        public const uint OID_NDK_LOCAL_ENDPOINTS = 0xFC040204;

        public static readonly Guid GUID_NDIS_NDK_CAPABILITIES__scanned__ = new Guid(0x7969ba4d, 0xdd80, 0x4bc7, 0xb3, 0xe6, 0x68, 0x04, 0x39, 0x97, 0xe5, 0x19);

        public static readonly Guid GUID_NDIS_NDK_STATE__scanned__ = new Guid(0x530c69c9, 0x2f51, 0x49de, 0xa1, 0xaf, 0x08, 0x8d, 0x54, 0xff, 0xa4, 0x74);

        public const uint NDIS_NDK_STATISTICS_INFO_REVISION_1 = 1;

        public const uint NDIS_NDK_CONNECTIONS_REVISION_1 = 1;

        public const uint NDIS_NDK_LOCAL_ENDPOINTS_REVISION_1 = 1;

        public const uint OID_QOS_HARDWARE_CAPABILITIES = 0xFC050001;

        public const uint OID_QOS_CURRENT_CAPABILITIES = 0xFC050002;

        public const uint OID_QOS_PARAMETERS = 0xFC050003;

        public const uint OID_QOS_OPERATIONAL_PARAMETERS = 0xFC050004;

        public const uint OID_QOS_REMOTE_PARAMETERS = 0xFC050005;

        public const uint NDIS_QOS_MAXIMUM_PRIORITIES = 8;

        public const uint NDIS_QOS_MAXIMUM_TRAFFIC_CLASSES = 8;

        public const uint NDIS_QOS_CAPABILITIES_STRICT_TSA_SUPPORTED = 0x00000001;

        public const uint NDIS_QOS_CAPABILITIES_MACSEC_BYPASS_SUPPORTED = 0x00000002;

        public const uint NDIS_QOS_CAPABILITIES_CEE_DCBX_SUPPORTED = 0x00000004;

        public const uint NDIS_QOS_CAPABILITIES_IEEE_DCBX_SUPPORTED = 0x00000008;

        public const uint NDIS_QOS_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_QOS_CLASSIFICATION_SET_BY_MINIPORT_MASK = 0xFF000000;

        public const uint NDIS_QOS_CLASSIFICATION_ENFORCED_BY_MINIPORT = 0x01000000;

        public const uint NDIS_QOS_CONDITION_RESERVED = 0x0;

        public const uint NDIS_QOS_CONDITION_DEFAULT = 0x1;

        public const uint NDIS_QOS_CONDITION_TCP_PORT = 0x2;

        public const uint NDIS_QOS_CONDITION_UDP_PORT = 0x3;

        public const uint NDIS_QOS_CONDITION_TCP_OR_UDP_PORT = 0x4;

        public const uint NDIS_QOS_CONDITION_ETHERTYPE = 0x5;

        public const uint NDIS_QOS_CONDITION_NETDIRECT_PORT = 0x6;

        public const uint NDIS_QOS_CONDITION_MAXIMUM = 0x7;

        public const uint NDIS_QOS_ACTION_PRIORITY = 0x0;

        public const uint NDIS_QOS_ACTION_MAXIMUM = 0x1;

        public const uint NDIS_QOS_CLASSIFICATION_ELEMENT_REVISION_1 = 1;

        public const uint NDIS_QOS_PARAMETERS_ETS_CHANGED = 0x00000001;

        public const uint NDIS_QOS_PARAMETERS_ETS_CONFIGURED = 0x00000002;

        public const uint NDIS_QOS_PARAMETERS_PFC_CHANGED = 0x00000100;

        public const uint NDIS_QOS_PARAMETERS_PFC_CONFIGURED = 0x00000200;

        public const uint NDIS_QOS_PARAMETERS_CLASSIFICATION_CHANGED = 0x00010000;

        public const uint NDIS_QOS_PARAMETERS_CLASSIFICATION_CONFIGURED = 0x00020000;

        public const uint NDIS_QOS_PARAMETERS_WILLING = 0x80000000;

        public const uint NDIS_QOS_TSA_STRICT = 0x0;

        public const uint NDIS_QOS_TSA_CBS = 0x1;

        public const uint NDIS_QOS_TSA_ETS = 0x2;

        public const uint NDIS_QOS_TSA_MAXIMUM = 0x3;

        public const uint NDIS_QOS_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_DEFAULT_VPORT_ID = 0;

        public const uint NDIS_DEFAULT_SWITCH_ID = 0;

        public const uint NDIS_NIC_SWITCH_PARAMETERS_CHANGE_MASK = 0xFFFF0000;

        public const uint NDIS_NIC_SWITCH_PARAMETERS_SWITCH_NAME_CHANGED = 0x00010000;

        public const uint NDIS_NIC_SWITCH_PARAMETERS_DEFAULT_NUMBER_OF_QUEUE_PAIRS_FOR_DEFAULT_VPORT = 1;

        public const uint NDIS_NIC_SWITCH_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_NIC_SWITCH_DELETE_SWITCH_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_INFO_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_LOOKAHEAD_SPLIT_ENABLED = 0x00000001;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_PACKET_DIRECT_RX_ONLY = 0x00000002;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_ENFORCE_MAX_SG_LIST = 0x00008000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_CHANGE_MASK = 0xFFFF0000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_FLAGS_CHANGED = 0x00010000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_NAME_CHANGED = 0x00020000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_INT_MOD_CHANGED = 0x00040000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_STATE_CHANGED = 0x00080000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_PROCESSOR_AFFINITY_CHANGED = 0x00100000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_NDK_PARAMS_CHANGED = 0x00200000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_QOS_SQ_ID_CHANGED = 0x00400000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMS_NUM_QUEUE_PAIRS_CHANGED = 0x00800000;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VPORT_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_NIC_SWITCH_DELETE_VPORT_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_LOOKAHEAD_SPLIT_ENABLED = 0x00000001;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_PACKET_DIRECT_RX_ONLY = 0x00000002;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_GFT_ENABLED = 0x00000004;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_FUNCTION = 0x00000001;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_ENUM_ON_SPECIFIC_SWITCH = 0x00000002;

        public const uint NDIS_NIC_SWITCH_VPORT_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VF_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_FREE_VF_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VF_INFO_REVISION_1 = 1;

        public const uint NDIS_NIC_SWITCH_VF_INFO_ARRAY_ENUM_ON_SPECIFIC_SWITCH = 0x00000001;

        public const uint NDIS_NIC_SWITCH_VF_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_SRIOV_CAPS_SRIOV_SUPPORTED = 0x00000001;

        public const uint NDIS_SRIOV_CAPS_PF_MINIPORT = 0x00000002;

        public const uint NDIS_SRIOV_CAPS_VF_MINIPORT = 0x00000004;

        public const uint NDIS_SRIOV_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_SRIOV_READ_VF_CONFIG_SPACE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_WRITE_VF_CONFIG_SPACE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_READ_VF_CONFIG_BLOCK_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_WRITE_VF_CONFIG_BLOCK_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_RESET_VF_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_SET_VF_POWER_STATE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_CONFIG_STATE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_VF_VENDOR_DEVICE_ID_INFO_REVISION_1 = 1;

        public const uint NDIS_SRIOV_PROBED_BARS_INFO_REVISION_1 = 1;

        public const uint NDIS_RECEIVE_FILTER_MOVE_FILTER_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SRIOV_BAR_RESOURCES_INFO_REVISION_1 = 1;

        public const uint NDIS_SRIOV_PF_LUID_INFO_REVISION_1 = 1;

        public const uint NDIS_SRIOV_VF_SERIAL_NUMBER_INFO_REVISION_1 = 1;

        public const uint NDIS_SRIOV_VF_INVALIDATE_CONFIG_BLOCK_INFO_REVISION_1 = 1;

        public const uint NDIS_SRIOV_OVERLYING_ADAPTER_INFO_VERSION_1 = 1;

        public const uint NDIS_ISOLATION_NAME_MAX_STRING_SIZE = 127;

        public const uint NDIS_ROUTING_DOMAIN_ISOLATION_ENTRY_REVISION_1 = 1;

        public const uint NDIS_ROUTING_DOMAIN_ENTRY_REVISION_1 = 1;

        public const uint NDIS_ISOLATION_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_OBJECT_SERIALIZATION_VERSION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_SECURITY_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_SECURITY_REVISION_2 = 2;

        public const uint NDIS_SWITCH_PORT_PROPERTY_VLAN_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_PROFILE_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_ISOLATION_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_ROUTING_DOMAIN_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_CUSTOM_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_DELETE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_ENUM_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PROPERTY_ENUM_INFO_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_FEATURE_STATUS_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_FEATURE_STATUS_CUSTOM_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PROPERTY_CUSTOM_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PROPERTY_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PROPERTY_DELETE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PROPERTY_ENUM_INFO_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PROPERTY_ENUM_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_FEATURE_STATUS_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_FEATURE_STATUS_CUSTOM_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_PARAMETERS_FLAG_UNTRUSTED_INTERNAL_PORT = 0x1;

        public const uint NDIS_SWITCH_PORT_PARAMETERS_FLAG_RESTORING_PORT = 0x2;

        public const uint NDIS_SWITCH_PORT_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_PORT_ARRAY_REVISION_1 = 1;

        public const uint NDIS_SWITCH_NIC_FLAGS_NIC_INITIALIZING = 0x00000001;

        public const uint NDIS_SWITCH_NIC_FLAGS_NIC_SUSPENDED = 0x00000002;

        public const uint NDIS_SWITCH_NIC_FLAGS_MAPPED_NIC_UPDATED = 0x00000004;

        public const uint NDIS_SWITCH_NIC_FLAGS_NIC_SUSPENDED_LM = 0x00000010;

        public const uint NDIS_SWITCH_NIC_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_SWITCH_NIC_ARRAY_REVISION_1 = 1;

        public const uint NDIS_SWITCH_NIC_OID_REQUEST_REVISION_1 = 1;

        public const uint NDIS_SWITCH_NIC_SAVE_STATE_REVISION_1 = 1;

        public const uint NDIS_SWITCH_NIC_SAVE_STATE_REVISION_2 = 2;

        public const uint NDIS_PORT_STATE_REVISION_1 = 1;

        public const uint NDIS_PORT_CHAR_USE_DEFAULT_AUTH_SETTINGS = 0x00000001;

        public const uint NDIS_PORT_CHARACTERISTICS_REVISION_1 = 1;

        public const uint NDIS_PORT_ARRAY_REVISION_1 = 1;

        public const uint ETHERNET_LENGTH_OF_ADDRESS = 6;

        public const uint NDIS_GFP_HEADER_PRESENT_ETHERNET = 0x00000001;

        public const uint NDIS_GFP_HEADER_PRESENT_IPV4 = 0x00000002;

        public const uint NDIS_GFP_HEADER_PRESENT_IPV6 = 0x00000004;

        public const uint NDIS_GFP_HEADER_PRESENT_TCP = 0x00000008;

        public const uint NDIS_GFP_HEADER_PRESENT_UDP = 0x00000010;

        public const uint NDIS_GFP_HEADER_PRESENT_ICMP = 0x00000020;

        public const uint NDIS_GFP_HEADER_PRESENT_NO_ENCAP = 0x00000040;

        public const uint NDIS_GFP_HEADER_PRESENT_IP_IN_IP_ENCAP = 0x00000080;

        public const uint NDIS_GFP_HEADER_PRESENT_IP_IN_GRE_ENCAP = 0x00000100;

        public const uint NDIS_GFP_HEADER_PRESENT_NVGRE_ENCAP = 0x00000200;

        public const uint NDIS_GFP_HEADER_PRESENT_VXLAN_ENCAP = 0x00000400;

        public const uint NDIS_GFP_HEADER_PRESENT_ESP = 0x00000800;

        public const uint NDIS_GFP_ENCAPSULATION_TYPE_NOT_ENCAPSULATED = 0x00000001;

        public const uint NDIS_GFP_ENCAPSULATION_TYPE_IP_IN_IP = 0x00000002;

        public const uint NDIS_GFP_ENCAPSULATION_TYPE_IP_IN_GRE = 0x00000004;

        public const uint NDIS_GFP_ENCAPSULATION_TYPE_NVGRE = 0x00000008;

        public const uint NDIS_GFP_ENCAPSULATION_TYPE_VXLAN = 0x00000010;

        public const uint NDIS_GFP_UNDEFINED_PROFILE_ID = 0;

        public const uint NDIS_GFP_HEADER_GROUP_EXACT_MATCH_PROFILE_IS_TTL_ONE = 0x00000001;

        public const uint NDIS_GFP_HEADER_GROUP_EXACT_MATCH_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFP_EXACT_MATCH_PROFILE_RDMA_FLOW = 0x00000001;

        public const uint NDIS_GFP_EXACT_MATCH_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFP_HEADER_GROUP_EXACT_MATCH_IS_TTL_ONE = 0x00000001;

        public const uint NDIS_GFP_HEADER_GROUP_EXACT_MATCH_REVISION_1 = 1;

        public const uint NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH_PROFILE_IS_TTL_ONE = 0x00000001;

        public const uint NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFP_WILDCARD_MATCH_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH_IS_TTL_ONE = 0x00000001;

        public const uint NDIS_GFP_HEADER_GROUP_WILDCARD_MATCH_REVISION_1 = 1;

        public const uint NDIS_PD_CAPS_RECEIVE_FILTER_COUNTERS_SUPPORTED = 0x00000001;

        public const uint NDIS_PD_CAPS_DRAIN_NOTIFICATIONS_SUPPORTED = 0x00000002;

        public const uint NDIS_PD_CAPS_NOTIFICATION_MODERATION_INTERVAL_SUPPORTED = 0x00000004;

        public const uint NDIS_PD_CAPS_NOTIFICATION_MODERATION_COUNT_SUPPORTED = 0x00000008;

        public const uint NDIS_PD_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_PD_CONFIG_REVISION_1 = 1;

        public const uint NDIS_GFT_UNDEFINED_FLOW_ENTRY_ID = 0;

        public const uint NDIS_GFT_UNDEFINED_TABLE_ID = 0;

        public const uint NDIS_GFT_TABLE_INCLUDE_EXTERNAL_VPPORT = 0x00000001;

        public const uint NDIS_GFT_TABLE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_TABLE_INFO_REVISION_1 = 1;

        public const uint NDIS_GFT_TABLE_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_DELETE_TABLE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_UNDEFINED_COUNTER_ID = 0;

        public const uint NDIS_GFT_MAX_COUNTER_OBJECTS_PER_FLOW_ENTRY = 8;

        public const uint NDIS_GFT_COUNTER_PARAMETERS_CLIENT_SPECIFIED_ADDRESS = 0x00000001;

        public const uint NDIS_GFT_COUNTER_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_FREE_COUNTER_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_COUNTER_INFO_REVISION_1 = 1;

        public const uint NDIS_GFT_COUNTER_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_COUNTER_VALUE_ARRAY_UPDATE_MEMORY_MAPPED_COUNTERS = 0x00000001;

        public const uint NDIS_GFT_COUNTER_VALUE_ARRAY_GET_VALUES = 0x00000002;

        public const uint NDIS_GFT_COUNTER_VALUE_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_STATISTICS_REVISION_1 = 1;

        public const uint NDIS_GFT_HEADER_GROUP_TRANSPOSITION_PROFILE_DECREMENT_TTL_IF_NOT_ONE = 0x00000001;

        public const uint NDIS_GFT_HEADER_GROUP_TRANSPOSITION_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFT_UNDEFINED_CUSTOM_ACTION = 0;

        public const uint NDIS_GFT_RESERVED_CUSTOM_ACTIONS = 256;

        public const uint NDIS_GFT_CUSTOM_ACTION_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFT_HTP_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT = 0x00000001;

        public const uint NDIS_GFT_HTP_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT = 0x00000002;

        public const uint NDIS_GFT_HTP_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000004;

        public const uint NDIS_GFT_HTP_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000008;

        public const uint NDIS_GFT_HTP_COPY_ALL_PACKETS = 0x00000010;

        public const uint NDIS_GFT_HTP_COPY_FIRST_PACKET = 0x00000020;

        public const uint NDIS_GFT_HTP_COPY_WHEN_TCP_FLAG_SET = 0x00000040;

        public const uint NDIS_GFT_HTP_CUSTOM_ACTION_PRESENT = 0x00000080;

        public const uint NDIS_GFT_HTP_META_ACTION_BEFORE_HEADER_TRANSPOSITION = 0x00000100;

        public const uint NDIS_GFT_HEADER_TRANSPOSITION_PROFILE_REVISION_1 = 1;

        public const uint NDIS_GFT_HEADER_GROUP_TRANSPOSITION_DECREMENT_TTL_IF_NOT_ONE = 0x00000001;

        public const uint NDIS_GFT_HEADER_GROUP_TRANSPOSITION_REVISION_1 = 1;

        public const uint NDIS_GFT_CUSTOM_ACTION_LAST_ACTION = 0x00000001;

        public const uint NDIS_GFT_CUSTOM_ACTION_REVISION_1 = 1;

        public const uint NDIS_GFT_EMFE_ADD_IN_ACTIVATED_STATE = 0x00000001;

        public const uint NDIS_GFT_EMFE_MATCH_AND_ACTION_MUST_BE_SUPPORTED = 0x00000002;

        public const uint NDIS_GFT_EMFE_RDMA_FLOW = 0x00000004;

        public const uint NDIS_GFT_EMFE_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT = 0x00001000;

        public const uint NDIS_GFT_EMFE_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT = 0x00002000;

        public const uint NDIS_GFT_EMFE_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00004000;

        public const uint NDIS_GFT_EMFE_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00008000;

        public const uint NDIS_GFT_EMFE_COPY_ALL_PACKETS = 0x00010000;

        public const uint NDIS_GFT_EMFE_COPY_FIRST_PACKET = 0x00020000;

        public const uint NDIS_GFT_EMFE_COPY_WHEN_TCP_FLAG_SET = 0x00040000;

        public const uint NDIS_GFT_EMFE_CUSTOM_ACTION_PRESENT = 0x00080000;

        public const uint NDIS_GFT_EMFE_META_ACTION_BEFORE_HEADER_TRANSPOSITION = 0x00100000;

        public const uint NDIS_GFT_EMFE_COPY_AFTER_TCP_FIN_FLAG_SET = 0x00200000;

        public const uint NDIS_GFT_EMFE_COPY_AFTER_TCP_RST_FLAG_SET = 0x00400000;

        public const uint NDIS_GFT_EMFE_COPY_CONDITION_CHANGED = 0x01000000;

        public const uint NDIS_GFT_EMFE_ALL_VPORT_FLOW_ENTRIES = 0x02000000;

        public const uint NDIS_GFT_EMFE_COUNTER_ALLOCATE = 0x00000001;

        public const uint NDIS_GFT_EMFE_COUNTER_MEMORY_MAPPED = 0x00000002;

        public const uint NDIS_GFT_EMFE_COUNTER_CLIENT_SPECIFIED_ADDRESS = 0x00000004;

        public const uint NDIS_GFT_EMFE_COUNTER_TRACK_TCP_FLOW = 0x00000008;

        public const uint NDIS_GFT_EXACT_MATCH_FLOW_ENTRY_REVISION_1 = 1;

        public const uint NDIS_GFT_WCFE_ADD_IN_ACTIVATED_STATE = 0x00000001;

        public const uint NDIS_GFT_WCFE_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT = 0x00000002;

        public const uint NDIS_GFT_WCFE_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT = 0x00000004;

        public const uint NDIS_GFT_WCFE_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000008;

        public const uint NDIS_GFT_WCFE_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000010;

        public const uint NDIS_GFT_WCFE_COPY_ALL_PACKETS = 0x00000020;

        public const uint NDIS_GFT_WCFE_CUSTOM_ACTION_PRESENT = 0x00000040;

        public const uint NDIS_GFT_WCFE_COUNTER_ALLOCATE = 0x00000001;

        public const uint NDIS_GFT_WCFE_COUNTER_MEMORY_MAPPED = 0x00000002;

        public const uint NDIS_GFT_WCFE_COUNTER_CLIENT_SPECIFIED_ADDRESS = 0x00000004;

        public const uint NDIS_GFT_WILDCARD_MATCH_FLOW_ENTRY_REVISION_1 = 1;

        public const uint NDIS_GFT_PROFILE_INFO_REVISION_1 = 1;

        public const uint NDIS_GFT_PROFILE_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_DELETE_PROFILE_ALL_PROFILES = 0x00000001;

        public const uint NDIS_GFT_DELETE_PROFILE_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_FLOW_ENTRY_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_FLOW_ENTRY_INFO_ALL_FLOW_ENTRIES = 0x00000001;

        public const uint NDIS_GFT_FLOW_ENTRY_INFO_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ALL_NIC_SWITCH_FLOW_ENTRIES = 0x00000001;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ALL_TABLE_FLOW_ENTRIES = 0x00000002;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ALL_VPORT_FLOW_ENTRIES = 0x00000004;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_RANGE_DEFINED = 0x00000008;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ARRAY_DEFINED = 0x00000010;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ARRAY_COUNTER_VALUES = 0x00010000;

        public const uint NDIS_GFT_FLOW_ENTRY_ID_ARRAY_REVISION_1 = 1;

        public const uint NDIS_GFT_OFFLOAD_PARAMETERS_ENABLE_OFFLOAD = 0x00000001;

        public const uint NDIS_GFT_OFFLOAD_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_GFT_OFFLOAD_CAPS_ADD_FLOW_ENTRY_DEACTIVATED_PREFERRED = 0x00000001;

        public const uint NDIS_GFT_OFFLOAD_CAPS_RATE_LIMITING_QUEUE_SUPPORTED = 0x00000002;

        public const uint NDIS_GFT_OFFLOAD_CAPS_MEMORY_MAPPED_COUNTERS = 0x00000001;

        public const uint NDIS_GFT_OFFLOAD_CAPS_MEMORY_MAPPED_PAKCET_AND_BYTE_COUNTERS = 0x00000002;

        public const uint NDIS_GFT_OFFLOAD_CAPS_PER_FLOW_ENTRY_COUNTERS = 0x00000004;

        public const uint NDIS_GFT_OFFLOAD_CAPS_PER_PACKET_COUNTER_UPDATE = 0x00000008;

        public const uint NDIS_GFT_OFFLOAD_CAPS_CLIENT_SPECIFIED_MEMORY_MAPPED_COUNTERS = 0x00000010;

        public const uint NDIS_GFT_OFFLOAD_CAPS_INGRESS_AGGREGATE_COUNTERS = 0x00000020;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EGRESS_AGGREGATE_COUNTERS = 0x00000040;

        public const uint NDIS_GFT_OFFLOAD_CAPS_TRACK_TCP_FLOW_STATE = 0x00000080;

        public const uint NDIS_GFT_OFFLOAD_CAPS_COMBINED_COUNTER_AND_STATE = 0x00000100;

        public const uint NDIS_GFT_OFFLOAD_CAPS_INGRESS_WILDCARD_MATCH = 0x00000001;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EGRESS_WILDCARD_MATCH = 0x00000002;

        public const uint NDIS_GFT_OFFLOAD_CAPS_INGRESS_EXACT_MATCH = 0x00000004;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EGRESS_EXACT_MATCH = 0x00000008;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EXT_VPORT_INGRESS_WILDCARD_MATCH = 0x00000010;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EXT_VPORT_EGRESS_WILDCARD_MATCH = 0x00000020;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EXT_VPORT_INGRESS_EXACT_MATCH = 0x00000040;

        public const uint NDIS_GFT_OFFLOAD_CAPS_EXT_VPORT_EGRESS_EXACT_MATCH = 0x00000080;

        public const uint NDIS_GFT_OFFLOAD_CAPS_POP = 0x00000001;

        public const uint NDIS_GFT_OFFLOAD_CAPS_PUSH = 0x00000002;

        public const uint NDIS_GFT_OFFLOAD_CAPS_MODIFY = 0x00000004;

        public const uint NDIS_GFT_OFFLOAD_CAPS_IGNORE_ACTION_SUPPORTED = 0x00000008;

        public const uint NDIS_GFT_OFFLOAD_CAPS_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT = 0x00000010;

        public const uint NDIS_GFT_OFFLOAD_CAPS_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT = 0x00000020;

        public const uint NDIS_GFT_OFFLOAD_CAPS_REDIRECT_TO_INGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000040;

        public const uint NDIS_GFT_OFFLOAD_CAPS_REDIRECT_TO_EGRESS_QUEUE_OF_VPORT_IF_TTL_IS_ONE = 0x00000080;

        public const uint NDIS_GFT_OFFLOAD_CAPS_COPY_ALL = 0x00000100;

        public const uint NDIS_GFT_OFFLOAD_CAPS_COPY_FIRST = 0x00000200;

        public const uint NDIS_GFT_OFFLOAD_CAPS_COPY_WHEN_TCP_FLAG_SET = 0x00000400;

        public const uint NDIS_GFT_OFFLOAD_CAPS_SAMPLE = 0x00000800;

        public const uint NDIS_GFT_OFFLOAD_CAPS_META_ACTION_BEFORE_HEADER_TRANSPOSITION = 0x00001000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_META_ACTION_AFTER_HEADER_TRANSPOSITION = 0x00002000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_PER_VPORT_EXCEPTION_VPORT = 0x00004000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_DESIGNATED_EXCEPTION_VPORT = 0x00008000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_DSCP_MASK = 0x00010000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_8021P_PRIORITY_MASK = 0x00020000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_ALLOW = 0x00040000;

        public const uint NDIS_GFT_OFFLOAD_CAPS_DROP = 0x00080000;

        public const uint NDIS_GFT_OFFLOAD_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_GFT_VPORT_ENABLE = 0x00000001;

        public const uint NDIS_GFT_VPORT_PARSE_VXLAN = 0x00000002;

        public const uint NDIS_GFT_VPORT_PARSE_VXLAN_NOT_IN_SRC_PORT_RANGE = 0x00000004;

        public const uint NDIS_GFT_VPORT_ENABLE_STATE_CHANGED = 0x00100000;

        public const uint NDIS_GFT_VPORT_EXCEPTION_VPORT_CHANGED = 0x00200000;

        public const uint NDIS_GFT_VPORT_SAMPLING_RATE_CHANGED = 0x00400000;

        public const uint NDIS_GFT_VPORT_DSCP_MASK_CHANGED = 0x00800000;

        public const uint NDIS_GFT_VPORT_PRIORITY_MASK_CHANGED = 0x01000000;

        public const uint NDIS_GFT_VPORT_VXLAN_SETTINGS_CHANGED = 0x02000000;

        public const uint NDIS_GFT_VPORT_DSCP_FLAGS_CHANGED = 0x04000000;

        public const uint NDIS_GFT_VPORT_PARAMS_CHANGE_MASK = 0xFFF00000;

        public const uint NDIS_GFT_VPORT_MAX_DSCP_MASK_COUNTER_OBJECTS = 64;

        public const uint NDIS_GFT_VPORT_MAX_PRIORITY_MASK_COUNTER_OBJECTS = 8;

        public const uint NDIS_GFT_VPORT_DSCP_GUARD_ENABLE_RX = 0x00000001;

        public const uint NDIS_GFT_VPORT_DSCP_GUARD_ENABLE_TX = 0x00000002;

        public const uint NDIS_GFT_VPORT_DSCP_MASK_ENABLE_RX = 0x00000004;

        public const uint NDIS_GFT_VPORT_DSCP_MASK_ENABLE_TX = 0x00000008;

        public const uint NDIS_GFT_VPORT_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_QOS_DEFAULT_SQ_ID = 0;

        public const uint NDIS_QOS_SQ_PARAMETERS_REVISION_1 = 1;

        public const uint NDIS_QOS_SQ_PARAMETERS_REVISION_2 = 2;

        public const uint NDIS_QOS_SQ_TRANSMIT_CAP_ENABLED = 0x00000001;

        public const uint NDIS_QOS_SQ_TRANSMIT_RESERVATION_ENABLED = 0x00000002;

        public const uint NDIS_QOS_SQ_RECEIVE_CAP_ENABLED = 0x00000004;

        public const uint NDIS_QOS_SQ_PARAMETERS_ARRAY_REVISION_1 = 1;

        public const uint NDIS_QOS_SQ_ARRAY_REVISION_1 = 1;

        public const uint NDIS_QOS_OFFLOAD_CAPABILITIES_REVISION_1 = 1;

        public const uint NDIS_QOS_OFFLOAD_CAPABILITIES_REVISION_2 = 2;

        public const uint NDIS_QOS_OFFLOAD_CAPS_STANDARD_SQ = 0x00000001;

        public const uint NDIS_QOS_OFFLOAD_CAPS_GFT_SQ = 0x00000002;

        public const uint NDIS_QOS_SQ_STATS_REVISION_1 = 1;

        public const uint NDIS_TIMESTAMP_CAPABILITIES_REVISION_1 = 1;

        public const uint OID_TIMESTAMP_CAPABILITY = 0x00A00001;

        public const uint OID_TIMESTAMP_CURRENT_CONFIG = 0x00A00002;

        public const uint NDIS_HARDWARE_CROSSTIMESTAMP_REVISION_1 = 1;

        public const uint OID_TIMESTAMP_GET_CROSSTIMESTAMP = 0x00A00003;

    }
}
