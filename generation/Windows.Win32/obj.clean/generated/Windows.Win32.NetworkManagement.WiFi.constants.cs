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


namespace Windows.Win32.NetworkManagement.WiFi
{
    public static partial class Apis
    {
        public const uint L2_PROFILE_MAX_NAME_LENGTH = 256;

        public const uint L2_NOTIFICATION_SOURCE_NONE = 0;

        public const uint L2_NOTIFICATION_SOURCE_DOT3_AUTO_CONFIG = 0X00000001;

        public const uint L2_NOTIFICATION_SOURCE_SECURITY = 0X00000002;

        public const uint L2_NOTIFICATION_SOURCE_ONEX = 0X00000004;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_ACM = 0X00000008;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_MSM = 0X00000010;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_SECURITY = 0X00000020;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_IHV = 0X00000040;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_HNWK = 0X00000080;

        public const uint L2_NOTIFICATION_SOURCE_WCM = 0X00000100;

        public const uint L2_NOTIFICATION_SOURCE_WCM_CSP = 0X00000200;

        public const uint L2_NOTIFICATION_SOURCE_WFD = 0X00000400;

        public const uint L2_NOTIFICATION_SOURCE_WLAN_DEVICE_SERVICE = 0X00000800;

        public const uint L2_NOTIFICATION_SOURCE_ALL = 0X0000FFFF;

        public const uint L2_NOTIFICATION_CODE_PUBLIC_BEGIN = 0X00000000;

        public const uint L2_NOTIFICATION_CODE_GROUP_SIZE = 0x00001000;

        public const uint L2_REASON_CODE_GROUP_SIZE = 0x10000;

        public const uint L2_REASON_CODE_GEN_BASE = 0x10000;

        public const uint L2_REASON_CODE_SUCCESS = 0;

        public const uint L2_REASON_CODE_UNKNOWN = L2_REASON_CODE_GEN_BASE+1;

        public const uint L2_REASON_CODE_PROFILE_MISSING = 0x00000001;

        public const uint DOT11_HESSID_LENGTH = 6;

        public const uint DOT11_RATE_SET_MAX_LENGTH = 126;

        public const uint DOT11_WFD_SERVICE_NAME_MAX_LENGTH = 255;

        public const uint DOT11_WFD_APS2_SERVICE_TYPE_MAX_LENGTH = 21;

        public const uint DOT11_WFD_ASP2_INSTANCE_NAME_MAX_LENGTH = 63;

        public const uint DOT11_WFD_SERVICE_INFORMATION_MAX_LENGTH = 65535;

        public const uint DOT11_MAX_REQUESTED_SERVICE_INFORMATION_LENGTH = 255;

        public const uint DOT11_WFD_SESSION_INFO_MAX_LENGTH = 144;

        public const uint DOT11_MAX_PDU_SIZE = 2346;

        public const uint DOT11_MIN_PDU_SIZE = 256;

        public const uint DOT11_MAX_NUM_DEFAULT_KEY = 4;

        public const uint DOT11_MAX_NUM_DEFAULT_KEY_MFP = DOT11_MAX_NUM_DEFAULT_KEY + 2;

        public const uint OID_DOT11_NDIS_START = 0x0D010300;

        public const uint OID_DOT11_OFFLOAD_CAPABILITY = OID_DOT11_NDIS_START + 0;

        public const uint OID_DOT11_CURRENT_OFFLOAD_CAPABILITY = OID_DOT11_NDIS_START + 1;

        public const uint OID_DOT11_WEP_OFFLOAD = OID_DOT11_NDIS_START + 2;

        public const uint OID_DOT11_WEP_UPLOAD = OID_DOT11_NDIS_START + 3;

        public const uint OID_DOT11_DEFAULT_WEP_OFFLOAD = OID_DOT11_NDIS_START + 4;

        public const uint OID_DOT11_DEFAULT_WEP_UPLOAD = OID_DOT11_NDIS_START + 5;

        public const uint OID_DOT11_MPDU_MAX_LENGTH = OID_DOT11_NDIS_START + 6;

        public const uint OID_DOT11_OPERATION_MODE_CAPABILITY = OID_DOT11_NDIS_START + 7;

        public const uint OID_DOT11_CURRENT_OPERATION_MODE = OID_DOT11_NDIS_START + 8;

        public const uint OID_DOT11_CURRENT_PACKET_FILTER = OID_DOT11_NDIS_START + 9;

        public const uint OID_DOT11_ATIM_WINDOW = OID_DOT11_NDIS_START + 10;

        public const uint OID_DOT11_SCAN_REQUEST = OID_DOT11_NDIS_START + 11;

        public const uint OID_DOT11_CURRENT_PHY_TYPE = OID_DOT11_NDIS_START + 12;

        public const uint OID_DOT11_JOIN_REQUEST = OID_DOT11_NDIS_START + 13;

        public const uint OID_DOT11_START_REQUEST = OID_DOT11_NDIS_START + 14;

        public const uint OID_DOT11_UPDATE_IE = OID_DOT11_NDIS_START + 15;

        public const uint OID_DOT11_RESET_REQUEST = OID_DOT11_NDIS_START + 16;

        public const uint OID_DOT11_NIC_POWER_STATE = OID_DOT11_NDIS_START + 17;

        public const uint OID_DOT11_OPTIONAL_CAPABILITY = OID_DOT11_NDIS_START + 18;

        public const uint OID_DOT11_CURRENT_OPTIONAL_CAPABILITY = OID_DOT11_NDIS_START + 19;

        public const uint OID_DOT11_STATION_ID = OID_DOT11_NDIS_START + 20;

        public const uint OID_DOT11_MEDIUM_OCCUPANCY_LIMIT = OID_DOT11_NDIS_START + 21;

        public const uint OID_DOT11_CF_POLLABLE = OID_DOT11_NDIS_START + 22;

        public const uint OID_DOT11_CFP_PERIOD = OID_DOT11_NDIS_START + 23;

        public const uint OID_DOT11_CFP_MAX_DURATION = OID_DOT11_NDIS_START + 24;

        public const uint OID_DOT11_POWER_MGMT_MODE = OID_DOT11_NDIS_START + 25;

        public const uint OID_DOT11_OPERATIONAL_RATE_SET = OID_DOT11_NDIS_START + 26;

        public const uint OID_DOT11_BEACON_PERIOD = OID_DOT11_NDIS_START + 27;

        public const uint OID_DOT11_DTIM_PERIOD = OID_DOT11_NDIS_START + 28;

        public const uint OID_DOT11_WEP_ICV_ERROR_COUNT = OID_DOT11_NDIS_START + 29;

        public const uint OID_DOT11_MAC_ADDRESS = OID_DOT11_NDIS_START + 30;

        public const uint OID_DOT11_RTS_THRESHOLD = OID_DOT11_NDIS_START + 31;

        public const uint OID_DOT11_SHORT_RETRY_LIMIT = OID_DOT11_NDIS_START + 32;

        public const uint OID_DOT11_LONG_RETRY_LIMIT = OID_DOT11_NDIS_START + 33;

        public const uint OID_DOT11_FRAGMENTATION_THRESHOLD = OID_DOT11_NDIS_START + 34;

        public const uint OID_DOT11_MAX_TRANSMIT_MSDU_LIFETIME = OID_DOT11_NDIS_START + 35;

        public const uint OID_DOT11_MAX_RECEIVE_LIFETIME = OID_DOT11_NDIS_START + 36;

        public const uint OID_DOT11_COUNTERS_ENTRY = OID_DOT11_NDIS_START + 37;

        public const uint OID_DOT11_SUPPORTED_PHY_TYPES = OID_DOT11_NDIS_START + 38;

        public const uint OID_DOT11_CURRENT_REG_DOMAIN = OID_DOT11_NDIS_START + 39;

        public const uint OID_DOT11_TEMP_TYPE = OID_DOT11_NDIS_START + 40;

        public const uint OID_DOT11_CURRENT_TX_ANTENNA = OID_DOT11_NDIS_START + 41;

        public const uint OID_DOT11_DIVERSITY_SUPPORT = OID_DOT11_NDIS_START + 42;

        public const uint OID_DOT11_CURRENT_RX_ANTENNA = OID_DOT11_NDIS_START + 43;

        public const uint OID_DOT11_SUPPORTED_POWER_LEVELS = OID_DOT11_NDIS_START + 44;

        public const uint OID_DOT11_CURRENT_TX_POWER_LEVEL = OID_DOT11_NDIS_START + 45;

        public const uint OID_DOT11_HOP_TIME = OID_DOT11_NDIS_START + 46;

        public const uint OID_DOT11_CURRENT_CHANNEL_NUMBER = OID_DOT11_NDIS_START + 47;

        public const uint OID_DOT11_MAX_DWELL_TIME = OID_DOT11_NDIS_START + 48;

        public const uint OID_DOT11_CURRENT_DWELL_TIME = OID_DOT11_NDIS_START + 49;

        public const uint OID_DOT11_CURRENT_SET = OID_DOT11_NDIS_START + 50;

        public const uint OID_DOT11_CURRENT_PATTERN = OID_DOT11_NDIS_START + 51;

        public const uint OID_DOT11_CURRENT_INDEX = OID_DOT11_NDIS_START + 52;

        public const uint OID_DOT11_CURRENT_CHANNEL = OID_DOT11_NDIS_START + 53;

        public const uint OID_DOT11_CCA_MODE_SUPPORTED = OID_DOT11_NDIS_START + 54;

        public const uint OID_DOT11_CURRENT_CCA_MODE = OID_DOT11_NDIS_START + 55;

        public const uint OID_DOT11_ED_THRESHOLD = OID_DOT11_NDIS_START + 56;

        public const uint OID_DOT11_CCA_WATCHDOG_TIMER_MAX = OID_DOT11_NDIS_START + 57;

        public const uint OID_DOT11_CCA_WATCHDOG_COUNT_MAX = OID_DOT11_NDIS_START + 58;

        public const uint OID_DOT11_CCA_WATCHDOG_TIMER_MIN = OID_DOT11_NDIS_START + 59;

        public const uint OID_DOT11_CCA_WATCHDOG_COUNT_MIN = OID_DOT11_NDIS_START + 60;

        public const uint OID_DOT11_REG_DOMAINS_SUPPORT_VALUE = OID_DOT11_NDIS_START + 61;

        public const uint OID_DOT11_SUPPORTED_TX_ANTENNA = OID_DOT11_NDIS_START + 62;

        public const uint OID_DOT11_SUPPORTED_RX_ANTENNA = OID_DOT11_NDIS_START + 63;

        public const uint OID_DOT11_DIVERSITY_SELECTION_RX = OID_DOT11_NDIS_START + 64;

        public const uint OID_DOT11_SUPPORTED_DATA_RATES_VALUE = OID_DOT11_NDIS_START + 65;

        public const uint OID_DOT11_CURRENT_FREQUENCY = OID_DOT11_NDIS_START + 66;

        public const uint OID_DOT11_TI_THRESHOLD = OID_DOT11_NDIS_START + 67;

        public const uint OID_DOT11_FREQUENCY_BANDS_SUPPORTED = OID_DOT11_NDIS_START + 68;

        public const uint OID_DOT11_SHORT_PREAMBLE_OPTION_IMPLEMENTED = OID_DOT11_NDIS_START + 69;

        public const uint OID_DOT11_PBCC_OPTION_IMPLEMENTED = OID_DOT11_NDIS_START + 70;

        public const uint OID_DOT11_CHANNEL_AGILITY_PRESENT = OID_DOT11_NDIS_START + 71;

        public const uint OID_DOT11_CHANNEL_AGILITY_ENABLED = OID_DOT11_NDIS_START + 72;

        public const uint OID_DOT11_HR_CCA_MODE_SUPPORTED = OID_DOT11_NDIS_START + 73;

        public const uint OID_DOT11_MULTI_DOMAIN_CAPABILITY_IMPLEMENTED = OID_DOT11_NDIS_START + 74;

        public const uint OID_DOT11_MULTI_DOMAIN_CAPABILITY_ENABLED = OID_DOT11_NDIS_START + 75;

        public const uint OID_DOT11_COUNTRY_STRING = OID_DOT11_NDIS_START + 76;

        public const uint OID_DOT11_MULTI_DOMAIN_CAPABILITY = OID_DOT11_NDIS_START + 77;

        public const uint OID_DOT11_EHCC_PRIME_RADIX = OID_DOT11_NDIS_START + 78;

        public const uint OID_DOT11_EHCC_NUMBER_OF_CHANNELS_FAMILY_INDEX = OID_DOT11_NDIS_START + 79;

        public const uint OID_DOT11_EHCC_CAPABILITY_IMPLEMENTED = OID_DOT11_NDIS_START + 80;

        public const uint OID_DOT11_EHCC_CAPABILITY_ENABLED = OID_DOT11_NDIS_START + 81;

        public const uint OID_DOT11_HOP_ALGORITHM_ADOPTED = OID_DOT11_NDIS_START + 82;

        public const uint OID_DOT11_RANDOM_TABLE_FLAG = OID_DOT11_NDIS_START + 83;

        public const uint OID_DOT11_NUMBER_OF_HOPPING_SETS = OID_DOT11_NDIS_START + 84;

        public const uint OID_DOT11_HOP_MODULUS = OID_DOT11_NDIS_START + 85;

        public const uint OID_DOT11_HOP_OFFSET = OID_DOT11_NDIS_START + 86;

        public const uint OID_DOT11_HOPPING_PATTERN = OID_DOT11_NDIS_START + 87;

        public const uint OID_DOT11_RANDOM_TABLE_FIELD_NUMBER = OID_DOT11_NDIS_START + 88;

        public const uint OID_DOT11_WPA_TSC = OID_DOT11_NDIS_START + 89;

        public const uint OID_DOT11_RSSI_RANGE = OID_DOT11_NDIS_START + 90;

        public const uint OID_DOT11_RF_USAGE = OID_DOT11_NDIS_START + 91;

        public const uint OID_DOT11_NIC_SPECIFIC_EXTENSION = OID_DOT11_NDIS_START + 92;

        public const uint OID_DOT11_AP_JOIN_REQUEST = OID_DOT11_NDIS_START + 93;

        public const uint OID_DOT11_ERP_PBCC_OPTION_IMPLEMENTED = OID_DOT11_NDIS_START + 94;

        public const uint OID_DOT11_ERP_PBCC_OPTION_ENABLED = OID_DOT11_NDIS_START + 95;

        public const uint OID_DOT11_DSSS_OFDM_OPTION_IMPLEMENTED = OID_DOT11_NDIS_START + 96;

        public const uint OID_DOT11_DSSS_OFDM_OPTION_ENABLED = OID_DOT11_NDIS_START + 97;

        public const uint OID_DOT11_SHORT_SLOT_TIME_OPTION_IMPLEMENTED = OID_DOT11_NDIS_START + 98;

        public const uint OID_DOT11_SHORT_SLOT_TIME_OPTION_ENABLED = OID_DOT11_NDIS_START + 99;

        public const uint OID_DOT11_MAX_MAC_ADDRESS_STATES = OID_DOT11_NDIS_START + 100;

        public const uint OID_DOT11_RECV_SENSITIVITY_LIST = OID_DOT11_NDIS_START + 101;

        public const uint OID_DOT11_WME_IMPLEMENTED = OID_DOT11_NDIS_START + 102;

        public const uint OID_DOT11_WME_ENABLED = OID_DOT11_NDIS_START + 103;

        public const uint OID_DOT11_WME_AC_PARAMETERS = OID_DOT11_NDIS_START + 104;

        public const uint OID_DOT11_WME_UPDATE_IE = OID_DOT11_NDIS_START + 105;

        public const uint OID_DOT11_QOS_TX_QUEUES_SUPPORTED = OID_DOT11_NDIS_START + 106;

        public const uint OID_DOT11_QOS_TX_DURATION = OID_DOT11_NDIS_START + 107;

        public const uint OID_DOT11_QOS_TX_MEDIUM_TIME = OID_DOT11_NDIS_START + 108;

        public const uint OID_DOT11_SUPPORTED_OFDM_FREQUENCY_LIST = OID_DOT11_NDIS_START + 109;

        public const uint OID_DOT11_SUPPORTED_DSSS_CHANNEL_LIST = OID_DOT11_NDIS_START + 110;

        public const uint DOT11_MAX_NUM_OF_FRAGMENTS = 16;

        public const uint DOT11_PRIORITY_CONTENTION = 0;

        public const uint DOT11_PRIORITY_CONTENTION_FREE = 1;

        public const uint DOT11_SERVICE_CLASS_REORDERABLE_MULTICAST = 0;

        public const uint DOT11_SERVICE_CLASS_STRICTLY_ORDERED = 1;

        public const uint DOT11_FLAGS_80211B_SHORT_PREAMBLE = 0x00000001;

        public const uint DOT11_FLAGS_80211B_PBCC = 0x00000002;

        public const uint DOT11_FLAGS_80211B_CHANNEL_AGILITY = 0x00000004;

        public const uint DOT11_FLAGS_PS_ON = 0x00000008;

        public const uint DOT11_FLAGS_80211G_DSSS_OFDM = 0x00000010;

        public const uint DOT11_FLAGS_80211G_USE_PROTECTION = 0x00000020;

        public const uint DOT11_FLAGS_80211G_NON_ERP_PRESENT = 0x00000040;

        public const uint DOT11_FLAGS_80211G_BARKER_PREAMBLE_MODE = 0x00000080;

        public const uint DOT11_WME_PACKET = 0x00000100;

        public const uint DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_OID_SUPPORTED = 0x1;

        public const uint DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_CERTIFIED = 0x2;

        public const uint DOT11_EXTSTA_ATTRIBUTES_SAFEMODE_RESERVED = 0xC;

        public const uint DOT11_STATUS_SUCCESS = 0x00000001;

        public const uint DOT11_STATUS_RETRY_LIMIT_EXCEEDED = 0x00000002;

        public const uint DOT11_STATUS_UNSUPPORTED_PRIORITY = 0x00000004;

        public const uint DOT11_STATUS_UNSUPPORTED_SERVICE_CLASS = 0x00000008;

        public const uint DOT11_STATUS_UNAVAILABLE_PRIORITY = 0x00000010;

        public const uint DOT11_STATUS_UNAVAILABLE_SERVICE_CLASS = 0x00000020;

        public const uint DOT11_STATUS_XMIT_MSDU_TIMER_EXPIRED = 0x00000040;

        public const uint DOT11_STATUS_UNAVAILABLE_BSS = 0x00000080;

        public const uint DOT11_STATUS_EXCESSIVE_DATA_LENGTH = 0x00000100;

        public const uint DOT11_STATUS_ENCRYPTION_FAILED = 0x00000200;

        public const uint DOT11_STATUS_WEP_KEY_UNAVAILABLE = 0x00000400;

        public const uint DOT11_STATUS_ICV_VERIFIED = 0x00000800;

        public const uint DOT11_STATUS_PACKET_REASSEMBLED = 0x00001000;

        public const uint DOT11_STATUS_PACKET_NOT_REASSEMBLED = 0x00002000;

        public const uint DOT11_STATUS_GENERATE_AUTH_FAILED = 0x00004000;

        public const uint DOT11_STATUS_AUTH_NOT_VERIFIED = 0x00008000;

        public const uint DOT11_STATUS_AUTH_VERIFIED = 0x00010000;

        public const uint DOT11_STATUS_AUTH_FAILED = 0x00020000;

        public const uint DOT11_STATUS_PS_LIFETIME_EXPIRED = 0x00040000;

        public const uint DOT11_STATUS_RESET_CONFIRM = 4;

        public const uint DOT11_STATUS_SCAN_CONFIRM = 1;

        public const uint DOT11_STATUS_JOIN_CONFIRM = 2;

        public const uint DOT11_STATUS_START_CONFIRM = 3;

        public const uint DOT11_STATUS_AP_JOIN_CONFIRM = 5;

        public const uint DOT11_STATUS_MPDU_MAX_LENGTH_CHANGED = 6;

        public const uint DOT11_ENCAP_RFC_1042 = 1;

        public const uint DOT11_ENCAP_802_1H = 2;

        public const uint DOT11_ASSOC_STATUS_SUCCESS = 0;

        public const uint OID_DOT11_PRIVATE_OIDS_START = OID_DOT11_NDIS_START + 1024;

        public const uint OID_DOT11_CURRENT_ADDRESS = OID_DOT11_PRIVATE_OIDS_START + 2;

        public const uint OID_DOT11_PERMANENT_ADDRESS = OID_DOT11_PRIVATE_OIDS_START + 3;

        public const uint OID_DOT11_MULTICAST_LIST = OID_DOT11_PRIVATE_OIDS_START + 4;

        public const uint OID_DOT11_MAXIMUM_LIST_SIZE = OID_DOT11_PRIVATE_OIDS_START + 5;

        public const uint DOT11_EXTAP_ATTRIBUTES_REVISION_1 = 1;

        public const uint DOT11_INCOMING_ASSOC_STARTED_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_INCOMING_ASSOC_REQUEST_RECEIVED_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_ASSOC_ERROR_SOURCE_OS = 0x0;

        public const uint DOT11_ASSOC_ERROR_SOURCE_REMOTE = 0x01;

        public const uint DOT11_ASSOC_ERROR_SOURCE_OTHER = 0xFF;

        public const uint DOT11_INCOMING_ASSOC_COMPLETION_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_STOP_AP_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_STOP_AP_REASON_FREQUENCY_NOT_AVAILABLE = 0x1;

        public const uint DOT11_STOP_AP_REASON_CHANNEL_NOT_AVAILABLE = 0x2;

        public const uint DOT11_STOP_AP_REASON_AP_ACTIVE = 0x3;

        public const uint DOT11_STOP_AP_REASON_IHV_START = 0xFF000000;

        public const uint DOT11_STOP_AP_REASON_IHV_END = 0xFFFFFFFF;

        public const uint DOT11_PHY_FREQUENCY_ADOPTED_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_CAN_SUSTAIN_AP_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_CAN_SUSTAIN_AP_REASON_IHV_START = 0xFF000000;

        public const uint DOT11_CAN_SUSTAIN_AP_REASON_IHV_END = 0xFFFFFFFF;

        public const uint DOT11_AVAILABLE_CHANNEL_LIST_REVISION_1 = 1;

        public const uint DOT11_AVAILABLE_FREQUENCY_LIST_REVISION_1 = 1;

        public const uint DOT11_DISASSOCIATE_PEER_REQUEST_REVISION_1 = 1;

        public const uint DOT11_INCOMING_ASSOC_DECISION_REVISION_1 = 1;

        public const uint DOT11_INCOMING_ASSOC_DECISION_REVISION_2 = 2;

        public const uint DOT11_ADDITIONAL_IE_REVISION_1 = 1;

        public const uint DOT11_EXTAP_SEND_CONTEXT_REVISION_1 = 1;

        public const uint DOT11_EXTAP_RECV_CONTEXT_REVISION_1 = 1;

        public const uint DOT11_PEER_INFO_LIST_REVISION_1 = 1;

        public const uint DOT11_VWIFI_COMBINATION_REVISION_1 = 1;

        public const uint DOT11_VWIFI_COMBINATION_REVISION_2 = 2;

        public const uint DOT11_VWIFI_COMBINATION_REVISION_3 = 3;

        public const uint DOT11_VWIFI_ATTRIBUTES_REVISION_1 = 1;

        public const uint DOT11_MAC_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_WFD_ATTRIBUTES_REVISION_1 = 1;

        public const uint DOT11_WFD_STATUS_SUCCESS = 0;

        public const uint DOT11_WFD_STATUS_FAILED_INFORMATION_IS_UNAVAILABLE = 1;

        public const uint DOT11_WFD_STATUS_FAILED_INCOMPATIBLE_PARAMETERS = 2;

        public const uint DOT11_WFD_STATUS_FAILED_LIMIT_REACHED = 3;

        public const uint DOT11_WFD_STATUS_FAILED_INVALID_PARAMETERS = 4;

        public const uint DOT11_WFD_STATUS_FAILED_UNABLE_TO_ACCOMODATE_REQUEST = 5;

        public const uint DOT11_WFD_STATUS_FAILED_PREVIOUS_PROTOCOL_ERROR = 6;

        public const uint DOT11_WFD_STATUS_FAILED_NO_COMMON_CHANNELS = 7;

        public const uint DOT11_WFD_STATUS_FAILED_UNKNOWN_WFD_GROUP = 8;

        public const uint DOT11_WFD_STATUS_FAILED_MATCHING_MAX_INTENT = 9;

        public const uint DOT11_WFD_STATUS_FAILED_INCOMPATIBLE_PROVISIONING_METHOD = 10;

        public const uint DOT11_WFD_STATUS_FAILED_REJECTED_BY_USER = 11;

        public const uint DOT11_WFD_STATUS_SUCCESS_ACCEPTED_BY_USER = 12;

        public const uint DOT11_WFD_MINOR_REASON_SUCCESS = 0;

        public const uint DOT11_WFD_MINOR_REASON_DISASSOCIATED_FROM_WLAN_CROSS_CONNECTION_POLICY = 1;

        public const uint DOT11_WFD_MINOR_REASON_DISASSOCIATED_NOT_MANAGED_INFRASTRUCTURE_CAPABLE = 2;

        public const uint DOT11_WFD_MINOR_REASON_DISASSOCIATED_WFD_COEXISTENCE_POLICY = 3;

        public const uint DOT11_WFD_MINOR_REASON_DISASSOCIATED_INFRASTRUCTURE_MANAGED_POLICY = 4;

        public const uint DOT11_WPS_VERSION_1_0 = 0x01;

        public const uint DOT11_WPS_VERSION_2_0 = 0x02;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_SERVICE_DISCOVERY = 0x01;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_P2P_CLIENT_DISCOVERABILITY = 0x02;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_CONCURRENT_OPERATION = 0x04;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_P2P_INFRASTRUCTURE_MANAGED = 0x08;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_P2P_DEVICE_LIMIT = 0x10;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_P2P_INVITATION_PROCEDURE = 0x20;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_RESERVED_6 = 0x40;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_RESERVED_7 = 0x80;

        public const uint DOT11_WFD_GROUP_CAPABILITY_NONE = 0x00;

        public const uint DOT11_WFD_GROUP_CAPABILITY_GROUP_OWNER = 0x01;

        public const uint DOT11_WFD_GROUP_CAPABILITY_PERSISTENT_GROUP = 0x02;

        public const uint DOT11_WFD_GROUP_CAPABILITY_GROUP_LIMIT_REACHED = 0x04;

        public const uint DOT11_WFD_GROUP_CAPABILITY_INTRABSS_DISTRIBUTION_SUPPORTED = 0x08;

        public const uint DOT11_WFD_GROUP_CAPABILITY_CROSS_CONNECTION_SUPPORTED = 0x10;

        public const uint DOT11_WFD_GROUP_CAPABILITY_PERSISTENT_RECONNECT_SUPPORTED = 0x20;

        public const uint DOT11_WFD_GROUP_CAPABILITY_IN_GROUP_FORMATION = 0x40;

        public const uint DOT11_WFD_GROUP_CAPABILITY_RESERVED_7 = 0x80;

        public const uint DOT11_WFD_GROUP_CAPABILITY_EAPOL_KEY_IP_ADDRESS_ALLOCATION_SUPPORTED = 0x80;

        public const uint DOT11_WPS_DEVICE_NAME_MAX_LENGTH = 32;

        public const uint DOT11_WPS_MAX_PASSKEY_LENGTH = 8;

        public const uint DOT11_WPS_MAX_MODEL_NAME_LENGTH = 32;

        public const uint DOT11_WPS_MAX_MODEL_NUMBER_LENGTH = 32;

        public const uint WFDSVC_CONNECTION_CAPABILITY_NEW = 0x01;

        public const uint WFDSVC_CONNECTION_CAPABILITY_CLIENT = 0x02;

        public const uint WFDSVC_CONNECTION_CAPABILITY_GO = 0x04;

        public const uint DOT11_WFD_DISCOVER_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_WFD_DISCOVER_COMPLETE_MAX_LIST_SIZE = 128;

        public const uint DOT11_GO_NEGOTIATION_REQUEST_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_GO_NEGOTIATION_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_GO_NEGOTIATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_GO_NEGOTIATION_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_GO_NEGOTIATION_CONFIRMATION_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_GO_NEGOTIATION_CONFIRMATION_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_INVITATION_REQUEST_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_INVITATION_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_INVITATION_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_INVITATION_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_PROVISION_DISCOVERY_REQUEST_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_PROVISION_DISCOVERY_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_PROVISION_DISCOVERY_RESPONSE_SEND_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_RECEIVED_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_ANQP_QUERY_COMPLETE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_WFD_DEVICE_CAPABILITY_CONFIG_REVISION_1 = 1;

        public const uint DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG_REVISION_1 = 1;

        public const uint DOT11_WFD_GROUP_OWNER_CAPABILITY_CONFIG_REVISION_2 = 2;

        public const uint DOT11_WFD_DEVICE_INFO_REVISION_1 = 1;

        public const uint DOT11_WFD_SECONDARY_DEVICE_TYPE_LIST_REVISION_1 = 1;

        public const uint DISCOVERY_FILTER_BITMASK_DEVICE = 0x1;

        public const uint DISCOVERY_FILTER_BITMASK_GO = 0x2;

        public const uint DISCOVERY_FILTER_BITMASK_ANY = 0xF;

        public const uint DOT11_WFD_DISCOVER_REQUEST_REVISION_1 = 1;

        public const uint DOT11_DEVICE_ENTRY_BYTE_ARRAY_REVISION_1 = 1;

        public const uint DOT11_WFD_ADDITIONAL_IE_REVISION_1 = 1;

        public const uint DOT11_SEND_GO_NEGOTIATION_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_GO_NEGOTIATION_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_GO_NEGOTIATION_CONFIRMATION_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_INVITATION_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_INVITATION_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_PROVISION_DISCOVERY_REQUEST_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_SEND_PROVISION_DISCOVERY_RESPONSE_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_WFD_DEVICE_LISTEN_CHANNEL_REVISION_1 = 1;

        public const uint DOT11_WFD_GROUP_START_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_WFD_GROUP_JOIN_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_POWER_MGMT_AUTO_MODE_ENABLED_REVISION_1 = 1;

        public const uint DOT11_POWER_MGMT_MODE_STATUS_INFO_REVISION_1 = 1;

        public const uint DOT11_NLO_FLAG_STOP_NLO_INDICATION = 0x00000001;

        public const uint DOT11_NLO_FLAG_SCAN_ON_AOAC_PLATFORM = 0x00000002;

        public const uint DOT11_NLO_FLAG_SCAN_AT_SYSTEM_RESUME = 0x00000004;

        public const uint DOT11_OFFLOAD_NETWORK_LIST_REVISION_1 = 1;

        public const uint DOT11_OFFLOAD_NETWORK_STATUS_PARAMETERS_REVISION_1 = 1;

        public const uint DOT11_MANUFACTURING_TEST_REVISION_1 = 1;

        public const uint DOT11_SSID_MAX_LENGTH = 32;

        public const uint DOT11_OI_MAX_LENGTH = 5;

        public const uint DOT11_OI_MIN_LENGTH = 3;

        public const uint DevProp_PciRootBus_SecondaryInterface_PciConventional = 0;

        public const uint DevProp_PciRootBus_SecondaryInterface_PciXMode1 = 1;

        public const uint DevProp_PciRootBus_SecondaryInterface_PciXMode2 = 2;

        public const uint DevProp_PciRootBus_SecondaryInterface_PciExpress = 3;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_33Mhz = 0;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_66Mhz = 1;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_66Mhz = 2;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_100Mhz = 3;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_133Mhz = 4;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_66Mhz = 5;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_100Mhz = 6;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_133Mhz = 7;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_66Mhz = 8;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_100Mhz = 9;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_133Mhz = 10;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_66Mhz = 11;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_100Mhz = 12;

        public const uint DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_133Mhz = 13;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_33Mhz = 1;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_66Mhz = 2;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_66Mhz = 4;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_133Mhz = 8;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_266Mhz = 16;

        public const uint DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_533Mhz = 32;

        public const uint DevProp_PciRootBus_BusWidth_32Bits = 0;

        public const uint DevProp_PciRootBus_BusWidth_64Bits = 1;

        public const uint DevProp_PciDevice_DeviceType_PciConventional = 0;

        public const uint DevProp_PciDevice_DeviceType_PciX = 1;

        public const uint DevProp_PciDevice_DeviceType_PciExpressEndpoint = 2;

        public const uint DevProp_PciDevice_DeviceType_PciExpressLegacyEndpoint = 3;

        public const uint DevProp_PciDevice_DeviceType_PciExpressRootComplexIntegratedEndpoint = 4;

        public const uint DevProp_PciDevice_DeviceType_PciExpressTreatedAsPci = 5;

        public const uint DevProp_PciDevice_BridgeType_PciConventional = 6;

        public const uint DevProp_PciDevice_BridgeType_PciX = 7;

        public const uint DevProp_PciDevice_BridgeType_PciExpressRootPort = 8;

        public const uint DevProp_PciDevice_BridgeType_PciExpressUpstreamSwitchPort = 9;

        public const uint DevProp_PciDevice_BridgeType_PciExpressDownstreamSwitchPort = 10;

        public const uint DevProp_PciDevice_BridgeType_PciExpressToPciXBridge = 11;

        public const uint DevProp_PciDevice_BridgeType_PciXToExpressBridge = 12;

        public const uint DevProp_PciDevice_BridgeType_PciExpressTreatedAsPci = 13;

        public const uint DevProp_PciDevice_BridgeType_PciExpressEventCollector = 14;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_33MHz = 0;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_66MHz = 1;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode_Conventional_Pci = 0x0;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_66Mhz = 0x1;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_100Mhz = 0x2;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_133MHZ = 0x3;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_66Mhz = 0x5;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_100Mhz = 0x6;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_133Mhz = 0x7;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_66MHz = 0x9;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_100MHz = 0xA;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_133MHz = 0xB;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_66MHz = 0xD;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_100MHz = 0xE;

        public const uint DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_133MHz = 0xF;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_128Bytes = 0;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_256Bytes = 1;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_512Bytes = 2;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_1024Bytes = 3;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_2048Bytes = 4;

        public const uint DevProp_PciExpressDevice_PayloadOrRequestSize_4096Bytes = 5;

        public const uint DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps = 1;

        public const uint DevProp_PciExpressDevice_LinkSpeed_Five_Gbps = 2;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_1 = 1;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_2 = 2;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_4 = 4;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_8 = 8;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_12 = 12;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_16 = 16;

        public const uint DevProp_PciExpressDevice_LinkWidth_By_32 = 32;

        public const uint DevProp_PciExpressDevice_Spec_Version_10 = 1;

        public const uint DevProp_PciExpressDevice_Spec_Version_11 = 2;

        public const uint DevProp_PciDevice_InterruptType_LineBased = 1;

        public const uint DevProp_PciDevice_InterruptType_Msi = 2;

        public const uint DevProp_PciDevice_InterruptType_MsiX = 4;

        public const uint DevProp_PciDevice_SriovSupport_Ok = 0x0;

        public const uint DevProp_PciDevice_SriovSupport_MissingAcs = 0x1;

        public const uint DevProp_PciDevice_SriovSupport_MissingPfDriver = 0x2;

        public const uint DevProp_PciDevice_SriovSupport_NoBusResource = 0x3;

        public const uint DevProp_PciDevice_SriovSupport_DidntGetVfBarSpace = 0x4;

        public const uint DevProp_PciDevice_AcsSupport_Present = 0x0;

        public const uint DevProp_PciDevice_AcsSupport_NotNeeded = 0x1;

        public const uint DevProp_PciDevice_AcsSupport_Missing = 0x2;

        public const uint DevProp_PciDevice_AcsCompatibleUpHierarchy_NotSupported = 0x0;

        public const uint DevProp_PciDevice_AcsCompatibleUpHierarchy_SingleFunctionSupported = 0x1;

        public const uint DevProp_PciDevice_AcsCompatibleUpHierarchy_NoP2PSupported = 0x2;

        public const uint DevProp_PciDevice_AcsCompatibleUpHierarchy_Supported = 0x3;

        public const uint WLAN_API_VERSION_1_0 = 0x00000001;

        public const uint WLAN_API_VERSION_2_0 = 0x00000002;

        public const uint WLAN_PROFILE_GROUP_POLICY = 0x00000001;

        public const uint WLAN_PROFILE_USER = 0x00000002;

        public const uint WLAN_PROFILE_GET_PLAINTEXT_KEY = 0x00000004;

        public const uint WLAN_PROFILE_CONNECTION_MODE_SET_BY_CLIENT = 0x00010000;

        public const uint WLAN_PROFILE_CONNECTION_MODE_AUTO = 0x00020000;

        public const uint DOT11_PSD_IE_MAX_DATA_SIZE = 240;

        public const uint DOT11_PSD_IE_MAX_ENTRY_NUMBER = 5;

        public const uint WLAN_REASON_CODE_NETWORK_NOT_COMPATIBLE = WLAN_REASON_CODE_AC_BASE +1;

        public const uint WLAN_REASON_CODE_PROFILE_NOT_COMPATIBLE = WLAN_REASON_CODE_AC_BASE +2;

        public const uint WLAN_REASON_CODE_NO_AUTO_CONNECTION = WLAN_REASON_CODE_AC_CONNECT_BASE +1;

        public const uint WLAN_REASON_CODE_NOT_VISIBLE = WLAN_REASON_CODE_AC_CONNECT_BASE +2;

        public const uint WLAN_REASON_CODE_GP_DENIED = WLAN_REASON_CODE_AC_CONNECT_BASE +3;

        public const uint WLAN_REASON_CODE_USER_DENIED = WLAN_REASON_CODE_AC_CONNECT_BASE +4;

        public const uint WLAN_REASON_CODE_BSS_TYPE_NOT_ALLOWED = WLAN_REASON_CODE_AC_CONNECT_BASE +5;

        public const uint WLAN_REASON_CODE_IN_FAILED_LIST = WLAN_REASON_CODE_AC_CONNECT_BASE +6;

        public const uint WLAN_REASON_CODE_IN_BLOCKED_LIST = WLAN_REASON_CODE_AC_CONNECT_BASE +7;

        public const uint WLAN_REASON_CODE_SSID_LIST_TOO_LONG = WLAN_REASON_CODE_AC_CONNECT_BASE +8;

        public const uint WLAN_REASON_CODE_CONNECT_CALL_FAIL = WLAN_REASON_CODE_AC_CONNECT_BASE +9;

        public const uint WLAN_REASON_CODE_SCAN_CALL_FAIL = WLAN_REASON_CODE_AC_CONNECT_BASE +10;

        public const uint WLAN_REASON_CODE_NETWORK_NOT_AVAILABLE = WLAN_REASON_CODE_AC_CONNECT_BASE +11;

        public const uint WLAN_REASON_CODE_PROFILE_CHANGED_OR_DELETED = WLAN_REASON_CODE_AC_CONNECT_BASE +12;

        public const uint WLAN_REASON_CODE_KEY_MISMATCH = WLAN_REASON_CODE_AC_CONNECT_BASE + 13;

        public const uint WLAN_REASON_CODE_USER_NOT_RESPOND = WLAN_REASON_CODE_AC_CONNECT_BASE + 14;

        public const uint WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED_FOR_CLIENT = WLAN_REASON_CODE_AC_CONNECT_BASE + 15;

        public const uint WLAN_REASON_CODE_AP_PROFILE_NOT_ALLOWED = WLAN_REASON_CODE_AC_CONNECT_BASE + 16;

        public const uint WLAN_REASON_CODE_HOTSPOT2_PROFILE_DENIED = WLAN_REASON_CODE_AC_CONNECT_BASE + 17;

        public const uint WLAN_REASON_CODE_INVALID_PROFILE_SCHEMA = WLAN_REASON_CODE_PROFILE_BASE +1;

        public const uint WLAN_REASON_CODE_PROFILE_MISSING = WLAN_REASON_CODE_PROFILE_BASE +2;

        public const uint WLAN_REASON_CODE_INVALID_PROFILE_NAME = WLAN_REASON_CODE_PROFILE_BASE +3;

        public const uint WLAN_REASON_CODE_INVALID_PROFILE_TYPE = WLAN_REASON_CODE_PROFILE_BASE +4;

        public const uint WLAN_REASON_CODE_INVALID_PHY_TYPE = WLAN_REASON_CODE_PROFILE_BASE +5;

        public const uint WLAN_REASON_CODE_MSM_SECURITY_MISSING = WLAN_REASON_CODE_PROFILE_BASE +6;

        public const uint WLAN_REASON_CODE_IHV_SECURITY_NOT_SUPPORTED = WLAN_REASON_CODE_PROFILE_BASE +7;

        public const uint WLAN_REASON_CODE_IHV_OUI_MISMATCH = WLAN_REASON_CODE_PROFILE_BASE +8;

        public const uint WLAN_REASON_CODE_IHV_OUI_MISSING = WLAN_REASON_CODE_PROFILE_BASE +9;

        public const uint WLAN_REASON_CODE_IHV_SETTINGS_MISSING = WLAN_REASON_CODE_PROFILE_BASE +10;

        public const uint WLAN_REASON_CODE_CONFLICT_SECURITY = WLAN_REASON_CODE_PROFILE_BASE +11;

        public const uint WLAN_REASON_CODE_SECURITY_MISSING = WLAN_REASON_CODE_PROFILE_BASE +12;

        public const uint WLAN_REASON_CODE_INVALID_BSS_TYPE = WLAN_REASON_CODE_PROFILE_BASE +13;

        public const uint WLAN_REASON_CODE_INVALID_ADHOC_CONNECTION_MODE = WLAN_REASON_CODE_PROFILE_BASE +14;

        public const uint WLAN_REASON_CODE_NON_BROADCAST_SET_FOR_ADHOC = WLAN_REASON_CODE_PROFILE_BASE +15;

        public const uint WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_ADHOC = WLAN_REASON_CODE_PROFILE_BASE +16;

        public const uint WLAN_REASON_CODE_AUTO_SWITCH_SET_FOR_MANUAL_CONNECTION = WLAN_REASON_CODE_PROFILE_BASE +17;

        public const uint WLAN_REASON_CODE_IHV_SECURITY_ONEX_MISSING = WLAN_REASON_CODE_PROFILE_BASE +18;

        public const uint WLAN_REASON_CODE_PROFILE_SSID_INVALID = WLAN_REASON_CODE_PROFILE_BASE +19;

        public const uint WLAN_REASON_CODE_TOO_MANY_SSID = WLAN_REASON_CODE_PROFILE_BASE +20;

        public const uint WLAN_REASON_CODE_IHV_CONNECTIVITY_NOT_SUPPORTED = WLAN_REASON_CODE_PROFILE_BASE +21;

        public const uint WLAN_REASON_CODE_BAD_MAX_NUMBER_OF_CLIENTS_FOR_AP = WLAN_REASON_CODE_PROFILE_BASE +22;

        public const uint WLAN_REASON_CODE_INVALID_CHANNEL = WLAN_REASON_CODE_PROFILE_BASE +23;

        public const uint WLAN_REASON_CODE_OPERATION_MODE_NOT_SUPPORTED = WLAN_REASON_CODE_PROFILE_BASE +24;

        public const uint WLAN_REASON_CODE_AUTO_AP_PROFILE_NOT_ALLOWED = WLAN_REASON_CODE_PROFILE_BASE +25;

        public const uint WLAN_REASON_CODE_AUTO_CONNECTION_NOT_ALLOWED = WLAN_REASON_CODE_PROFILE_BASE +26;

        public const uint WLAN_REASON_CODE_HOTSPOT2_PROFILE_NOT_ALLOWED = WLAN_REASON_CODE_PROFILE_BASE +27;

        public const uint WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET_BY_OS = WLAN_REASON_CODE_MSM_BASE +1;

        public const uint WLAN_REASON_CODE_UNSUPPORTED_SECURITY_SET = WLAN_REASON_CODE_MSM_BASE +2;

        public const uint WLAN_REASON_CODE_BSS_TYPE_UNMATCH = WLAN_REASON_CODE_MSM_BASE +3;

        public const uint WLAN_REASON_CODE_PHY_TYPE_UNMATCH = WLAN_REASON_CODE_MSM_BASE +4;

        public const uint WLAN_REASON_CODE_DATARATE_UNMATCH = WLAN_REASON_CODE_MSM_BASE +5;

        public const uint WLAN_REASON_CODE_USER_CANCELLED = WLAN_REASON_CODE_MSM_CONNECT_BASE+1;

        public const uint WLAN_REASON_CODE_ASSOCIATION_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+2;

        public const uint WLAN_REASON_CODE_ASSOCIATION_TIMEOUT = WLAN_REASON_CODE_MSM_CONNECT_BASE+3;

        public const uint WLAN_REASON_CODE_PRE_SECURITY_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+4;

        public const uint WLAN_REASON_CODE_START_SECURITY_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+5;

        public const uint WLAN_REASON_CODE_SECURITY_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+6;

        public const uint WLAN_REASON_CODE_SECURITY_TIMEOUT = WLAN_REASON_CODE_MSM_CONNECT_BASE+7;

        public const uint WLAN_REASON_CODE_ROAMING_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+8;

        public const uint WLAN_REASON_CODE_ROAMING_SECURITY_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+9;

        public const uint WLAN_REASON_CODE_ADHOC_SECURITY_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+10;

        public const uint WLAN_REASON_CODE_DRIVER_DISCONNECTED = WLAN_REASON_CODE_MSM_CONNECT_BASE+11;

        public const uint WLAN_REASON_CODE_DRIVER_OPERATION_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+12;

        public const uint WLAN_REASON_CODE_IHV_NOT_AVAILABLE = WLAN_REASON_CODE_MSM_CONNECT_BASE+13;

        public const uint WLAN_REASON_CODE_IHV_NOT_RESPONDING = WLAN_REASON_CODE_MSM_CONNECT_BASE+14;

        public const uint WLAN_REASON_CODE_DISCONNECT_TIMEOUT = WLAN_REASON_CODE_MSM_CONNECT_BASE+15;

        public const uint WLAN_REASON_CODE_INTERNAL_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+16;

        public const uint WLAN_REASON_CODE_UI_REQUEST_TIMEOUT = WLAN_REASON_CODE_MSM_CONNECT_BASE+17;

        public const uint WLAN_REASON_CODE_TOO_MANY_SECURITY_ATTEMPTS = WLAN_REASON_CODE_MSM_CONNECT_BASE+18;

        public const uint WLAN_REASON_CODE_AP_STARTING_FAILURE = WLAN_REASON_CODE_MSM_CONNECT_BASE+19;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_KEY_INDEX = WLAN_REASON_CODE_MSMSEC_BASE+1;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_PRESENT = WLAN_REASON_CODE_MSMSEC_BASE+2;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_LENGTH = WLAN_REASON_CODE_MSMSEC_BASE+3;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_PSK_LENGTH = WLAN_REASON_CODE_MSMSEC_BASE+4;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_NO_AUTH_CIPHER_SPECIFIED = WLAN_REASON_CODE_MSMSEC_BASE+5;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_TOO_MANY_AUTH_CIPHER_SPECIFIED = WLAN_REASON_CODE_MSMSEC_BASE+6;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_DUPLICATE_AUTH_CIPHER = WLAN_REASON_CODE_MSMSEC_BASE+7;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_RAWDATA_INVALID = WLAN_REASON_CODE_MSMSEC_BASE+8;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_AUTH_CIPHER = WLAN_REASON_CODE_MSMSEC_BASE+9;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_DISABLED = WLAN_REASON_CODE_MSMSEC_BASE+10;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_ONEX_ENABLED = WLAN_REASON_CODE_MSMSEC_BASE+11;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_MODE = WLAN_REASON_CODE_MSMSEC_BASE+12;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_SIZE = WLAN_REASON_CODE_MSMSEC_BASE+13;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PMKCACHE_TTL = WLAN_REASON_CODE_MSMSEC_BASE+14;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_MODE = WLAN_REASON_CODE_MSMSEC_BASE+15;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_PREAUTH_THROTTLE = WLAN_REASON_CODE_MSMSEC_BASE+16;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_PREAUTH_ONLY_ENABLED = WLAN_REASON_CODE_MSMSEC_BASE+17;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_NETWORK = WLAN_REASON_CODE_MSMSEC_BASE+18;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_NIC = WLAN_REASON_CODE_MSMSEC_BASE+19;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE = WLAN_REASON_CODE_MSMSEC_BASE+20;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_DISCOVERY = WLAN_REASON_CODE_MSMSEC_BASE+21;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_PASSPHRASE_CHAR = WLAN_REASON_CODE_MSMSEC_BASE+22;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_KEYMATERIAL_CHAR = WLAN_REASON_CODE_MSMSEC_BASE+23;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_WRONG_KEYTYPE = WLAN_REASON_CODE_MSMSEC_BASE+24;

        public const uint WLAN_REASON_CODE_MSMSEC_MIXED_CELL = WLAN_REASON_CODE_MSMSEC_BASE+25;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_AUTH_TIMERS_INVALID = WLAN_REASON_CODE_MSMSEC_BASE+26;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_INVALID_GKEY_INTV = WLAN_REASON_CODE_MSMSEC_BASE+27;

        public const uint WLAN_REASON_CODE_MSMSEC_TRANSITION_NETWORK = WLAN_REASON_CODE_MSMSEC_BASE+28;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_KEY_UNMAPPED_CHAR = WLAN_REASON_CODE_MSMSEC_BASE+29;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_AUTH = WLAN_REASON_CODE_MSMSEC_BASE+30;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_CIPHER = WLAN_REASON_CODE_MSMSEC_BASE+31;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_SAFE_MODE = WLAN_REASON_CODE_MSMSEC_BASE+32;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NIC = WLAN_REASON_CODE_MSMSEC_BASE+33;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_PROFILE_SAFE_MODE_NW = WLAN_REASON_CODE_MSMSEC_BASE+34;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_AUTH = WLAN_REASON_CODE_MSMSEC_BASE+35;

        public const uint WLAN_REASON_CODE_MSMSEC_PROFILE_UNSUPPORTED_CIPHER = WLAN_REASON_CODE_MSMSEC_BASE+36;

        public const uint WLAN_REASON_CODE_MSMSEC_CAPABILITY_MFP_NW_NIC = WLAN_REASON_CODE_MSMSEC_BASE+37;

        public const uint WLAN_REASON_CODE_MSMSEC_UI_REQUEST_FAILURE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+1;

        public const uint WLAN_REASON_CODE_MSMSEC_AUTH_START_TIMEOUT = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+2;

        public const uint WLAN_REASON_CODE_MSMSEC_AUTH_SUCCESS_TIMEOUT = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+3;

        public const uint WLAN_REASON_CODE_MSMSEC_KEY_START_TIMEOUT = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+4;

        public const uint WLAN_REASON_CODE_MSMSEC_KEY_SUCCESS_TIMEOUT = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+5;

        public const uint WLAN_REASON_CODE_MSMSEC_M3_MISSING_KEY_DATA = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+6;

        public const uint WLAN_REASON_CODE_MSMSEC_M3_MISSING_IE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+7;

        public const uint WLAN_REASON_CODE_MSMSEC_M3_MISSING_GRP_KEY = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+8;

        public const uint WLAN_REASON_CODE_MSMSEC_PR_IE_MATCHING = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+9;

        public const uint WLAN_REASON_CODE_MSMSEC_SEC_IE_MATCHING = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+10;

        public const uint WLAN_REASON_CODE_MSMSEC_NO_PAIRWISE_KEY = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+11;

        public const uint WLAN_REASON_CODE_MSMSEC_G1_MISSING_KEY_DATA = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+12;

        public const uint WLAN_REASON_CODE_MSMSEC_G1_MISSING_GRP_KEY = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+13;

        public const uint WLAN_REASON_CODE_MSMSEC_PEER_INDICATED_INSECURE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+14;

        public const uint WLAN_REASON_CODE_MSMSEC_NO_AUTHENTICATOR = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+15;

        public const uint WLAN_REASON_CODE_MSMSEC_NIC_FAILURE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+16;

        public const uint WLAN_REASON_CODE_MSMSEC_CANCELLED = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+17;

        public const uint WLAN_REASON_CODE_MSMSEC_KEY_FORMAT = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+18;

        public const uint WLAN_REASON_CODE_MSMSEC_DOWNGRADE_DETECTED = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+19;

        public const uint WLAN_REASON_CODE_MSMSEC_PSK_MISMATCH_SUSPECTED = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+20;

        public const uint WLAN_REASON_CODE_MSMSEC_FORCED_FAILURE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+21;

        public const uint WLAN_REASON_CODE_MSMSEC_M3_TOO_MANY_RSNIE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+22;

        public const uint WLAN_REASON_CODE_MSMSEC_M2_MISSING_KEY_DATA = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+23;

        public const uint WLAN_REASON_CODE_MSMSEC_M2_MISSING_IE = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+24;

        public const uint WLAN_REASON_CODE_MSMSEC_AUTH_WCN_COMPLETED = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+25;

        public const uint WLAN_REASON_CODE_MSMSEC_M3_MISSING_MGMT_GRP_KEY = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+26;

        public const uint WLAN_REASON_CODE_MSMSEC_G1_MISSING_MGMT_GRP_KEY = WLAN_REASON_CODE_MSMSEC_CONNECT_BASE+27;

        public const uint WLAN_AVAILABLE_NETWORK_CONNECTED = 0x00000001;

        public const uint WLAN_AVAILABLE_NETWORK_HAS_PROFILE = 0x00000002;

        public const uint WLAN_AVAILABLE_NETWORK_CONSOLE_USER_PROFILE = 0x00000004;

        public const uint WLAN_AVAILABLE_NETWORK_INTERWORKING_SUPPORTED = 0x00000008;

        public const uint WLAN_AVAILABLE_NETWORK_HOTSPOT2_ENABLED = 0x00000010;

        public const uint WLAN_AVAILABLE_NETWORK_ANQP_SUPPORTED = 0x00000020;

        public const uint WLAN_AVAILABLE_NETWORK_HOTSPOT2_DOMAIN = 0x00000040;

        public const uint WLAN_AVAILABLE_NETWORK_HOTSPOT2_ROAMING = 0x00000080;

        public const uint WLAN_AVAILABLE_NETWORK_AUTO_CONNECT_FAILED = 0x00000100;

        public const uint WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_ADHOC_PROFILES = 0x00000001;

        public const uint WLAN_AVAILABLE_NETWORK_INCLUDE_ALL_MANUAL_HIDDEN_PROFILES = 0x00000002;

        public const uint WLAN_MAX_PHY_TYPE_NUMBER = 8;

        public const uint WLAN_MAX_PHY_INDEX = 64;

        public const uint WLAN_CONNECTION_HIDDEN_NETWORK = 0x00000001;

        public const uint WLAN_CONNECTION_ADHOC_JOIN_ONLY = 0x00000002;

        public const uint WLAN_CONNECTION_IGNORE_PRIVACY_BIT = 0x00000004;

        public const uint WLAN_CONNECTION_EAPOL_PASSTHROUGH = 0x00000008;

        public const uint WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE = 0x00000010;

        public const uint WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE_CONNECTION_MODE_AUTO = 0x00000020;

        public const uint WLAN_CONNECTION_PERSIST_DISCOVERY_PROFILE_OVERWRITE_EXISTING = 0x00000040;

        public const uint WFD_API_VERSION_1_0 = 0x00000001;

        public const uint WLAN_UI_API_VERSION = 1;

        public const uint WLAN_UI_API_INITIAL_VERSION = 1;

        public static readonly Guid GUID_DEVINTERFACE_WIFIDIRECT_DEVICE__scanned__ = new Guid(0x439b20af, 0x8955, 0x405b, 0x99, 0xf0, 0xa6, 0x2a, 0xf0, 0xc6, 0x8d, 0x43    );

        public static readonly Guid GUID_AEPSERVICE_WIFIDIRECT_DEVICE__scanned__ = new Guid(0xcc29827c, 0x9caf, 0x4928, 0x99, 0xa9, 0x18, 0xf7, 0xc2, 0x38, 0x13, 0x89    );

        public static readonly Guid GUID_DEVINTERFACE_ASP_INFRA_DEVICE__scanned__ = new Guid(0xff823995, 0x7a72, 0x4c80, 0x87, 0x57, 0xc6, 0x7e, 0xe1, 0x3d, 0x1a, 0x49    );

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x01    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_DeviceAddress;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x02    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_InterfaceAddress;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x03    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_InterfaceGuid;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x04    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_GroupId;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x05    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsConnected;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x06    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsVisible;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x07    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsLegacyDevice;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x08    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_MiracastVersion;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x09    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsMiracastLCPSupported;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0A    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_Services;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0B    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_SupportedChannelList;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0C    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_InformationElements;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0D    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_DeviceAddressCopy;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0E    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsRecentlyAssociated;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x0F    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_Service_Aeps;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x10    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_NoMiracastAutoProject;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x11    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_Supported;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x12    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_StreamSecuritySupported;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x13    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_AccessPointBssid;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x14    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_SinkHostName;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x15    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_ChallengeAep;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x16    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_IsDMGCapable;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x17    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_DevnodeAep;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x18    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_FoundWsbService;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x19)]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_HostName_ResolutionMode;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x1A    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_SinkIpAddress;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x1B    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_TransientAssociation;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x1C    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirect_LinkQuality;

        [PropertyKey(0x1506935d, 0xe3e7, 0x450f, 0x86, 0x37, 0x82, 0x23, 0x3e, 0xbe, 0x5f, 0x6E,    0x1D    )]
        public static readonly PROPERTYKEY DEVPKEY_InfraCast_PinSupported;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x02    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_ServiceAddress;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x03    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_ServiceName;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x04    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_ServiceInformation;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x05    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_AdvertisementId;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x06    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_ServiceConfigMethods;

        [PropertyKey(0x31b37743, 0x7c5e, 0x4005, 0x93, 0xe6, 0xe9, 0x53, 0xf9, 0x2b, 0x82, 0xe9,    0x07    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFiDirectServices_RequestServiceInformation;

        [PropertyKey(0xef1167eb, 0xcbfc, 0x4341, 0xa5, 0x68, 0xa7, 0xc9, 0x1a, 0x68, 0x98, 0x2c,    0x02    )]
        public static readonly PROPERTYKEY DEVPKEY_WiFi_InterfaceGuid;

    }
}
