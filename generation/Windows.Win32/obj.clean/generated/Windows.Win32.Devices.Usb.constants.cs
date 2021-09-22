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


namespace Windows.Win32.Devices.Usb
{
    public static partial class Apis
    {
        public const uint SHORT_PACKET_TERMINATE = 0x01;

        public const uint AUTO_CLEAR_STALL = 0x02;

        public const uint PIPE_TRANSFER_TIMEOUT = 0x03;

        public const uint IGNORE_SHORT_PACKETS = 0x04;

        public const uint ALLOW_PARTIAL_READS = 0x05;

        public const uint AUTO_FLUSH = 0x06;

        public const uint RAW_IO = 0x07;

        public const uint MAXIMUM_TRANSFER_SIZE = 0x08;

        public const uint RESET_PIPE_ON_RESUME = 0x09;

        public const uint AUTO_SUSPEND = 0x81;

        public const uint SUSPEND_DELAY = 0x83;

        public const uint DEVICE_SPEED = 0x01;

        public const uint LowSpeed = 0x01;

        public const uint FullSpeed = 0x02;

        public const uint HighSpeed = 0x03;

        public const uint USBUSER_VERSION = 0x00000004;

        public const uint USBUSER_GET_CONTROLLER_INFO_0 = 0x00000001;

        public const uint USBUSER_GET_CONTROLLER_DRIVER_KEY = 0x00000002;

        public const uint USBUSER_PASS_THRU = 0x00000003;

        public const uint USBUSER_GET_POWER_STATE_MAP = 0x00000004;

        public const uint USBUSER_GET_BANDWIDTH_INFORMATION = 0x00000005;

        public const uint USBUSER_GET_BUS_STATISTICS_0 = 0x00000006;

        public const uint USBUSER_GET_ROOTHUB_SYMBOLIC_NAME = 0x00000007;

        public const uint USBUSER_GET_USB_DRIVER_VERSION = 0x00000008;

        public const uint USBUSER_GET_USB2_HW_VERSION = 0x00000009;

        public const uint USBUSER_USB_REFRESH_HCT_REG = 0x0000000a;

        public const uint USBUSER_OP_SEND_ONE_PACKET = 0x10000001;

        public const uint USBUSER_OP_RAW_RESET_PORT = 0x20000001;

        public const uint USBUSER_OP_OPEN_RAW_DEVICE = 0x20000002;

        public const uint USBUSER_OP_CLOSE_RAW_DEVICE = 0x20000003;

        public const uint USBUSER_OP_SEND_RAW_COMMAND = 0x20000004;

        public const uint USBUSER_SET_ROOTPORT_FEATURE = 0x20000005;

        public const uint USBUSER_CLEAR_ROOTPORT_FEATURE = 0x20000006;

        public const uint USBUSER_GET_ROOTPORT_STATUS = 0x20000007;

        public const uint USBUSER_INVALID_REQUEST = 0xFFFFFFF0;

        public const uint USBUSER_OP_MASK_DEVONLY_API = 0x10000000;

        public const uint USBUSER_OP_MASK_HCTEST_API = 0x20000000;

        public const uint USB_PACKETFLAG_LOW_SPEED = 0x00000001;

        public const uint USB_PACKETFLAG_FULL_SPEED = 0x00000002;

        public const uint USB_PACKETFLAG_HIGH_SPEED = 0x00000004;

        public const uint USB_PACKETFLAG_ASYNC_IN = 0x00000008;

        public const uint USB_PACKETFLAG_ASYNC_OUT = 0x00000010;

        public const uint USB_PACKETFLAG_ISO_IN = 0x00000020;

        public const uint USB_PACKETFLAG_ISO_OUT = 0x00000040;

        public const uint USB_PACKETFLAG_SETUP = 0x00000080;

        public const uint USB_PACKETFLAG_TOGGLE0 = 0x00000100;

        public const uint USB_PACKETFLAG_TOGGLE1 = 0x00000200;

        public const uint USB_HC_FEATURE_FLAG_PORT_POWER_SWITCHING = 0x00000001;

        public const uint USB_HC_FEATURE_FLAG_SEL_SUSPEND = 0x00000002;

        public const uint USB_HC_FEATURE_LEGACY_BIOS = 0x00000004;

        public const uint USB_HC_FEATURE_TIME_SYNC_API = 0x00000008;

        public const uint USB_SUBMIT_URB = 0;

        public const uint USB_RESET_PORT = 1;

        public const uint USB_GET_ROOTHUB_PDO = 3;

        public const uint USB_GET_PORT_STATUS = 4;

        public const uint USB_ENABLE_PORT = 5;

        public const uint USB_GET_HUB_COUNT = 6;

        public const uint USB_CYCLE_PORT = 7;

        public const uint USB_GET_HUB_NAME = 8;

        public const uint USB_IDLE_NOTIFICATION = 9;

        public const uint USB_RECORD_FAILURE = 10;

        public const uint USB_GET_BUS_INFO = 264;

        public const uint USB_GET_CONTROLLER_NAME = 265;

        public const uint USB_GET_BUSGUID_INFO = 266;

        public const uint USB_GET_PARENT_HUB_INFO = 267;

        public const uint USB_GET_DEVICE_HANDLE = 268;

        public const uint USB_GET_DEVICE_HANDLE_EX = 269;

        public const uint USB_GET_TT_DEVICE_HANDLE = 270;

        public const uint USB_GET_TOPOLOGY_ADDRESS = 271;

        public const uint USB_IDLE_NOTIFICATION_EX = 272;

        public const uint USB_REQ_GLOBAL_SUSPEND = 273;

        public const uint USB_REQ_GLOBAL_RESUME = 274;

        public const uint USB_GET_HUB_CONFIG_INFO = 275;

        public const uint USB_FAIL_GET_STATUS = 280;

        public const uint USB_REGISTER_COMPOSITE_DEVICE = 0;

        public const uint USB_UNREGISTER_COMPOSITE_DEVICE = 1;

        public const uint USB_REQUEST_REMOTE_WAKE_NOTIFICATION = 2;

        public const uint HCD_GET_STATS_1 = 255;

        public const uint HCD_DIAGNOSTIC_MODE_ON = 256;

        public const uint HCD_DIAGNOSTIC_MODE_OFF = 257;

        public const uint HCD_GET_ROOT_HUB_NAME = 258;

        public const uint HCD_GET_DRIVERKEY_NAME = 265;

        public const uint HCD_GET_STATS_2 = 266;

        public const uint HCD_DISABLE_PORT = 268;

        public const uint HCD_ENABLE_PORT = 269;

        public const uint HCD_USER_REQUEST = 270;

        public const uint HCD_TRACE_READ_REQUEST = 275;

        public const uint USB_GET_NODE_INFORMATION = 258;

        public const uint USB_GET_NODE_CONNECTION_INFORMATION = 259;

        public const uint USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION = 260;

        public const uint USB_GET_NODE_CONNECTION_NAME = 261;

        public const uint USB_DIAG_IGNORE_HUBS_ON = 262;

        public const uint USB_DIAG_IGNORE_HUBS_OFF = 263;

        public const uint USB_GET_NODE_CONNECTION_DRIVERKEY_NAME = 264;

        public const uint USB_GET_HUB_CAPABILITIES = 271;

        public const uint USB_GET_NODE_CONNECTION_ATTRIBUTES = 272;

        public const uint USB_HUB_CYCLE_PORT = 273;

        public const uint USB_GET_NODE_CONNECTION_INFORMATION_EX = 274;

        public const uint USB_RESET_HUB = 275;

        public const uint USB_GET_HUB_CAPABILITIES_EX = 276;

        public const uint USB_GET_HUB_INFORMATION_EX = 277;

        public const uint USB_GET_PORT_CONNECTOR_PROPERTIES = 278;

        public const uint USB_GET_NODE_CONNECTION_INFORMATION_EX_V2 = 279;

        public const uint USB_GET_TRANSPORT_CHARACTERISTICS = 281;

        public const uint USB_REGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE = 282;

        public const uint USB_NOTIFY_ON_TRANSPORT_CHARACTERISTICS_CHANGE = 283;

        public const uint USB_UNREGISTER_FOR_TRANSPORT_CHARACTERISTICS_CHANGE = 284;

        public const uint USB_START_TRACKING_FOR_TIME_SYNC = 285;

        public const uint USB_GET_FRAME_NUMBER_AND_QPC_FOR_TIME_SYNC = 286;

        public const uint USB_STOP_TRACKING_FOR_TIME_SYNC = 287;

        public const uint USB_GET_DEVICE_CHARACTERISTICS = 288;

        public static readonly Guid GUID_DEVINTERFACE_USB_HUB__scanned__ = new Guid(0xf18a0e88, 0xc30c, 0x11d0, 0x88, 0x15, 0x00,              0xa0, 0xc9, 0x06, 0xbe, 0xd8);

        public static readonly Guid GUID_DEVINTERFACE_USB_BILLBOARD__scanned__ = new Guid(0x5e9adaef, 0xf879, 0x473f, 0xb8, 0x07, 0x4e,             0x5e, 0xa7, 0x7d, 0x1b, 0x1c);

        public static readonly Guid GUID_DEVINTERFACE_USB_DEVICE__scanned__ = new Guid(0xA5DCBF10L, 0x6530, 0x11D2, 0x90, 0x1F, 0x00,              0xC0, 0x4F, 0xB9, 0x51, 0xED);

        public static readonly Guid GUID_DEVINTERFACE_USB_HOST_CONTROLLER__scanned__ = new Guid(0x3abf6f2d, 0x71c4, 0x462a, 0x8a, 0x92, 0x1e,              0x68, 0x61, 0xe6, 0xaf, 0x27);

        public static readonly Guid GUID_USB_WMI_STD_DATA__scanned__ = new Guid(0x4E623B20L, 0xCB14, 0x11D1, 0xB3, 0x31, 0x00,             0xA0, 0xC9, 0x59, 0xBB, 0xD2);

        public static readonly Guid GUID_USB_WMI_STD_NOTIFICATION__scanned__ = new Guid(0x4E623B20L, 0xCB14, 0x11D1, 0xB3, 0x31, 0x00,             0xA0, 0xC9, 0x59, 0xBB, 0xD2);

        public static readonly Guid GUID_USB_WMI_DEVICE_PERF_INFO__scanned__ = new Guid(0x66c1aa3c, 0x499f, 0x49a0, 0xa9, 0xa5, 0x61, 0xe2,             0x35, 0x9f, 0x64, 0x7);

        public static readonly Guid GUID_USB_WMI_NODE_INFO__scanned__ = new Guid(0x9c179357, 0xdc7a, 0x4f41, 0xb6, 0x6b, 0x32, 0x3b, 0x9d, 0xdc, 0xb5, 0xb1);

        public static readonly Guid GUID_USB_WMI_TRACING__scanned__ = new Guid(0x3a61881b, 0xb4e6, 0x4bf9, 0xae, 0xf, 0x3c, 0xd8, 0xf3, 0x94, 0xe5, 0x2f);

        public static readonly Guid GUID_USB_TRANSFER_TRACING__scanned__ = new Guid(0x681eb8aa, 0x403d, 0x452c, 0x9f, 0x8a, 0xf0, 0x61, 0x6f, 0xac, 0x95, 0x40);

        public static readonly Guid GUID_USB_PERFORMANCE_TRACING__scanned__ = new Guid(0xd5de77a6, 0x6ae9, 0x425c, 0xb1, 0xe2, 0xf5, 0x61, 0x5f, 0xd3, 0x48, 0xa9);

        public static readonly Guid GUID_USB_WMI_SURPRISE_REMOVAL_NOTIFICATION__scanned__ = new Guid(0x9bbbf831, 0xa2f2, 0x43b4, 0x96, 0xd1, 0x86, 0x94, 0x4b, 0x59, 0x14, 0xb3);

        public const uint BMREQUEST_HOST_TO_DEVICE = 0;

        public const uint BMREQUEST_DEVICE_TO_HOST = 1;

        public const uint BMREQUEST_STANDARD = 0;

        public const uint BMREQUEST_CLASS = 1;

        public const uint BMREQUEST_VENDOR = 2;

        public const uint BMREQUEST_TO_DEVICE = 0;

        public const uint BMREQUEST_TO_INTERFACE = 1;

        public const uint BMREQUEST_TO_ENDPOINT = 2;

        public const uint BMREQUEST_TO_OTHER = 3;

        public const uint USB_REQUEST_GET_STATUS = 0x00;

        public const uint USB_REQUEST_CLEAR_FEATURE = 0x01;

        public const uint USB_REQUEST_SET_FEATURE = 0x03;

        public const uint USB_REQUEST_SET_ADDRESS = 0x05;

        public const uint USB_REQUEST_GET_DESCRIPTOR = 0x06;

        public const uint USB_REQUEST_SET_DESCRIPTOR = 0x07;

        public const uint USB_REQUEST_GET_CONFIGURATION = 0x08;

        public const uint USB_REQUEST_SET_CONFIGURATION = 0x09;

        public const uint USB_REQUEST_GET_INTERFACE = 0x0A;

        public const uint USB_REQUEST_SET_INTERFACE = 0x0B;

        public const uint USB_REQUEST_SYNC_FRAME = 0x0C;

        public const uint USB_REQUEST_GET_FIRMWARE_STATUS = 0x1A;

        public const uint USB_REQUEST_SET_FIRMWARE_STATUS = 0x1B;

        public const uint USB_GET_FIRMWARE_ALLOWED_OR_DISALLOWED_STATE = 0x00;

        public const uint USB_GET_FIRMWARE_HASH = 0x01;

        public const uint USB_DEVICE_FIRMWARE_HASH_LENGTH = 32;

        public const uint USB_DISALLOW_FIRMWARE_UPDATE = 0x00;

        public const uint USB_ALLOW_FIRMWARE_UPDATE = 0x01;

        public const uint USB_REQUEST_SET_SEL = 0x30;

        public const uint USB_REQUEST_ISOCH_DELAY = 0x31;

        public const uint USB_DEVICE_DESCRIPTOR_TYPE = 0x01;

        public const uint USB_CONFIGURATION_DESCRIPTOR_TYPE = 0x02;

        public const uint USB_STRING_DESCRIPTOR_TYPE = 0x03;

        public const uint USB_INTERFACE_DESCRIPTOR_TYPE = 0x04;

        public const uint USB_ENDPOINT_DESCRIPTOR_TYPE = 0x05;

        public const uint USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE = 0x06;

        public const uint USB_OTHER_SPEED_CONFIGURATION_DESCRIPTOR_TYPE = 0x07;

        public const uint USB_INTERFACE_POWER_DESCRIPTOR_TYPE = 0x08;

        public const uint USB_OTG_DESCRIPTOR_TYPE = 0x09;

        public const uint USB_DEBUG_DESCRIPTOR_TYPE = 0x0A;

        public const uint USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE = 0x0B;

        public const uint USB_BOS_DESCRIPTOR_TYPE = 0x0F;

        public const uint USB_DEVICE_CAPABILITY_DESCRIPTOR_TYPE = 0x10;

        public const uint USB_SUPERSPEED_ENDPOINT_COMPANION_DESCRIPTOR_TYPE = 0x30;

        public const uint USB_SUPERSPEEDPLUS_ISOCH_ENDPOINT_COMPANION_DESCRIPTOR_TYPE = 0x31;

        public const uint USB_RESERVED_DESCRIPTOR_TYPE = 0x06;

        public const uint USB_CONFIG_POWER_DESCRIPTOR_TYPE = 0x07;

        public const uint USB_FEATURE_ENDPOINT_STALL = 0x00;

        public const uint USB_FEATURE_REMOTE_WAKEUP = 0x01;

        public const uint USB_FEATURE_TEST_MODE = 0x02;

        public const uint USB_FEATURE_FUNCTION_SUSPEND = 0x00;

        public const uint USB_FEATURE_U1_ENABLE = 0x30;

        public const uint USB_FEATURE_U2_ENABLE = 0x31;

        public const uint USB_FEATURE_LTM_ENABLE = 0x32;

        public const uint USB_FEATURE_LDM_ENABLE = 0x35;

        public const uint USB_FEATURE_BATTERY_WAKE_MASK = 0x28;

        public const uint USB_FEATURE_OS_IS_PD_AWARE = 0x29;

        public const uint USB_FEATURE_POLICY_MODE = 0x2A;

        public const uint USB_FEATURE_CHARGING_POLICY = 0x36;

        public const uint USB_CHARGING_POLICY_DEFAULT = 0x00;

        public const uint USB_CHARGING_POLICY_ICCHPF = 0x01;

        public const uint USB_CHARGING_POLICY_ICCLPF = 0x02;

        public const uint USB_CHARGING_POLICY_NO_POWER = 0x03;

        public const uint USB_STATUS_PORT_STATUS = 0x00;

        public const uint USB_STATUS_PD_STATUS = 0x01;

        public const uint USB_STATUS_EXT_PORT_STATUS = 0x02;

        public const uint USB_GETSTATUS_SELF_POWERED = 0x01;

        public const uint USB_GETSTATUS_REMOTE_WAKEUP_ENABLED = 0x02;

        public const uint USB_GETSTATUS_U1_ENABLE = 0x04;

        public const uint USB_GETSTATUS_U2_ENABLE = 0x08;

        public const uint USB_GETSTATUS_LTM_ENABLE = 0x10;

        public const uint USB_DEVICE_CLASS_RESERVED = 0x00;

        public const uint USB_DEVICE_CLASS_AUDIO = 0x01;

        public const uint USB_DEVICE_CLASS_COMMUNICATIONS = 0x02;

        public const uint USB_DEVICE_CLASS_HUMAN_INTERFACE = 0x03;

        public const uint USB_DEVICE_CLASS_MONITOR = 0x04;

        public const uint USB_DEVICE_CLASS_PHYSICAL_INTERFACE = 0x05;

        public const uint USB_DEVICE_CLASS_POWER = 0x06;

        public const uint USB_DEVICE_CLASS_IMAGE = 0x06;

        public const uint USB_DEVICE_CLASS_PRINTER = 0x07;

        public const uint USB_DEVICE_CLASS_STORAGE = 0x08;

        public const uint USB_DEVICE_CLASS_HUB = 0x09;

        public const uint USB_DEVICE_CLASS_CDC_DATA = 0x0A;

        public const uint USB_DEVICE_CLASS_SMART_CARD = 0x0B;

        public const uint USB_DEVICE_CLASS_CONTENT_SECURITY = 0x0D;

        public const uint USB_DEVICE_CLASS_VIDEO = 0x0E;

        public const uint USB_DEVICE_CLASS_PERSONAL_HEALTHCARE = 0x0F;

        public const uint USB_DEVICE_CLASS_AUDIO_VIDEO = 0x10;

        public const uint USB_DEVICE_CLASS_BILLBOARD = 0x11;

        public const uint USB_DEVICE_CLASS_DIAGNOSTIC_DEVICE = 0xDC;

        public const uint USB_DEVICE_CLASS_WIRELESS_CONTROLLER = 0xE0;

        public const uint USB_DEVICE_CLASS_MISCELLANEOUS = 0xEF;

        public const uint USB_DEVICE_CLASS_APPLICATION_SPECIFIC = 0xFE;

        public const uint USB_DEVICE_CLASS_VENDOR_SPECIFIC = 0xFF;

        public const uint USB_DEVICE_CAPABILITY_WIRELESS_USB = 0x01;

        public const uint USB_DEVICE_CAPABILITY_USB20_EXTENSION = 0x02;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_USB = 0x03;

        public const uint USB_DEVICE_CAPABILITY_CONTAINER_ID = 0x04;

        public const uint USB_DEVICE_CAPABILITY_PLATFORM = 0x05;

        public const uint USB_DEVICE_CAPABILITY_POWER_DELIVERY = 0x06;

        public const uint USB_DEVICE_CAPABILITY_BATTERY_INFO = 0x07;

        public const uint USB_DEVICE_CAPABILITY_PD_CONSUMER_PORT = 0x08;

        public const uint USB_DEVICE_CAPABILITY_PD_PROVIDER_PORT = 0x09;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_USB = 0x0A;

        public const uint USB_DEVICE_CAPABILITY_PRECISION_TIME_MEASUREMENT = 0x0B;

        public const uint USB_DEVICE_CAPABILITY_BILLBOARD = 0x0D;

        public const uint USB_DEVICE_CAPABILITY_FIRMWARE_STATUS = 0x11;

        public const uint USB_DEVICE_CAPABILITY_USB20_EXTENSION_BMATTRIBUTES_RESERVED_MASK = 0xFFFF00E1;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_BMATTRIBUTES_RESERVED_MASK = 0xFD;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_BMATTRIBUTES_LTM_CAPABLE = 0x02;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_SPEEDS_SUPPORTED_RESERVED_MASK = 0xFFF0;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_SPEEDS_SUPPORTED_LOW = 0x0001;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_SPEEDS_SUPPORTED_FULL = 0x0002;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_SPEEDS_SUPPORTED_HIGH = 0x0004;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_SPEEDS_SUPPORTED_SUPER = 0x0008;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_U1_DEVICE_EXIT_MAX_VALUE = 0x0A;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEED_U2_DEVICE_EXIT_MAX_VALUE = 0x07FF;

        public const uint USB_DEVICE_CAPABILITY_MAX_U1_LATENCY = 0x0A;

        public const uint USB_DEVICE_CAPABILITY_MAX_U2_LATENCY = 0x07FF;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_LSE_BPS = 0;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_LSE_KBPS = 1;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_LSE_MBPS = 2;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_LSE_GBPS = 3;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_MODE_SYMMETRIC = 0;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_MODE_ASYMMETRIC = 1;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_DIR_RX = 0;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_DIR_TX = 1;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_PROTOCOL_SS = 0;

        public const uint USB_DEVICE_CAPABILITY_SUPERSPEEDPLUS_SPEED_PROTOCOL_SSP = 1;

        public static readonly Guid GUID_USB_MSOS20_PLATFORM_CAPABILITY_ID__scanned__ = new Guid(0xD8DD60DF, 0x4589, 0x4CC7, 0x9C, 0xD2, 0x65, 0x9D, 0x9E, 0x64, 0x8A, 0x9F);

        public const uint USB_CONFIG_POWERED_MASK = 0xC0;

        public const uint USB_CONFIG_BUS_POWERED = 0x80;

        public const uint USB_CONFIG_SELF_POWERED = 0x40;

        public const uint USB_CONFIG_REMOTE_WAKEUP = 0x20;

        public const uint USB_CONFIG_RESERVED = 0x1F;

        public const uint USB_ENDPOINT_DIRECTION_MASK = 0x80;

        public const uint USB_ENDPOINT_ADDRESS_MASK = 0x0F;

        public const uint USB_ENDPOINT_TYPE_MASK = 0x03;

        public const uint USB_ENDPOINT_TYPE_CONTROL = 0x00;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS = 0x01;

        public const uint USB_ENDPOINT_TYPE_BULK = 0x02;

        public const uint USB_ENDPOINT_TYPE_INTERRUPT = 0x03;

        public const uint USB_ENDPOINT_TYPE_BULK_RESERVED_MASK = 0xFC;

        public const uint USB_ENDPOINT_TYPE_CONTROL_RESERVED_MASK = 0xFC;

        public const uint USB_20_ENDPOINT_TYPE_INTERRUPT_RESERVED_MASK = 0xFC;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_RESERVED_MASK = 0xCC;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_RESERVED_MASK = 0xC0;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_USAGE_MASK = 0x30;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_USAGE_PERIODIC = 0x00;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_USAGE_NOTIFICATION = 0x10;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_USAGE_RESERVED10 = 0x20;

        public const uint USB_30_ENDPOINT_TYPE_INTERRUPT_USAGE_RESERVED11 = 0x30;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_SYNCHRONIZATION_MASK = 0x0C;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_SYNCHRONIZATION_NO_SYNCHRONIZATION = 0x00;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_SYNCHRONIZATION_ASYNCHRONOUS = 0x04;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_SYNCHRONIZATION_ADAPTIVE = 0x08;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_SYNCHRONIZATION_SYNCHRONOUS = 0x0C;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_USAGE_MASK = 0x30;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_USAGE_DATA_ENDOINT = 0x00;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_USAGE_FEEDBACK_ENDPOINT = 0x10;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_USAGE_IMPLICIT_FEEDBACK_DATA_ENDPOINT = 0x20;

        public const uint USB_ENDPOINT_TYPE_ISOCHRONOUS_USAGE_RESERVED = 0x30;

        public const uint USB_ENDPOINT_SUPERSPEED_BULK_MAX_PACKET_SIZE = 1024;

        public const uint USB_ENDPOINT_SUPERSPEED_CONTROL_MAX_PACKET_SIZE = 512;

        public const uint USB_ENDPOINT_SUPERSPEED_ISO_MAX_PACKET_SIZE = 1024;

        public const uint USB_ENDPOINT_SUPERSPEED_INTERRUPT_MAX_PACKET_SIZE = 1024;

        public const uint MAXIMUM_USB_STRING_LENGTH = 255;

        public const uint USB_SUPERSPEED_ISOCHRONOUS_MAX_MULTIPLIER = 2;

        public const uint USB_SUPERSPEEDPLUS_ISOCHRONOUS_MIN_BYTESPERINTERVAL = 0xC001;

        public const uint USB_SUPERSPEEDPLUS_ISOCHRONOUS_MAX_BYTESPERINTERVAL = 0xFFFFFF;

        public const uint USB_20_HUB_DESCRIPTOR_TYPE = 0x29;

        public const uint USB_30_HUB_DESCRIPTOR_TYPE = 0x2A;

        public const uint USB_REQUEST_GET_STATE = 0x02;

        public const uint USB_REQUEST_CLEAR_TT_BUFFER = 0x08;

        public const uint USB_REQUEST_RESET_TT = 0x09;

        public const uint USB_REQUEST_GET_TT_STATE = 0x0A;

        public const uint USB_REQUEST_STOP_TT = 0x0B;

        public const uint USB_REQUEST_SET_HUB_DEPTH = 0x0C;

        public const uint USB_REQUEST_GET_PORT_ERR_COUNT = 0x0D;

        public const uint USB_PORT_STATUS_CONNECT = 0x0001;

        public const uint USB_PORT_STATUS_ENABLE = 0x0002;

        public const uint USB_PORT_STATUS_SUSPEND = 0x0004;

        public const uint USB_PORT_STATUS_OVER_CURRENT = 0x0008;

        public const uint USB_PORT_STATUS_RESET = 0x0010;

        public const uint USB_PORT_STATUS_POWER = 0x0100;

        public const uint USB_PORT_STATUS_LOW_SPEED = 0x0200;

        public const uint USB_PORT_STATUS_HIGH_SPEED = 0x0400;

        public const uint PORT_LINK_STATE_U0 = 0;

        public const uint PORT_LINK_STATE_U1 = 1;

        public const uint PORT_LINK_STATE_U2 = 2;

        public const uint PORT_LINK_STATE_U3 = 3;

        public const uint PORT_LINK_STATE_DISABLED = 4;

        public const uint PORT_LINK_STATE_RX_DETECT = 5;

        public const uint PORT_LINK_STATE_INACTIVE = 6;

        public const uint PORT_LINK_STATE_POLLING = 7;

        public const uint PORT_LINK_STATE_RECOVERY = 8;

        public const uint PORT_LINK_STATE_HOT_RESET = 9;

        public const uint PORT_LINK_STATE_COMPLIANCE_MODE = 10;

        public const uint PORT_LINK_STATE_LOOPBACK = 11;

        public const uint PORT_LINK_STATE_TEST_MODE = 11;

        public const uint USB_FEATURE_INTERFACE_POWER_D0 = 0x0002;

        public const uint USB_FEATURE_INTERFACE_POWER_D1 = 0x0003;

        public const uint USB_FEATURE_INTERFACE_POWER_D2 = 0x0004;

        public const uint USB_FEATURE_INTERFACE_POWER_D3 = 0x0005;

        public const uint USB_SUPPORT_D0_COMMAND = 0x01;

        public const uint USB_SUPPORT_D1_COMMAND = 0x02;

        public const uint USB_SUPPORT_D2_COMMAND = 0x04;

        public const uint USB_SUPPORT_D3_COMMAND = 0x08;

        public const uint USB_SUPPORT_D1_WAKEUP = 0x10;

        public const uint USB_SUPPORT_D2_WAKEUP = 0x20;

        public const uint USBDI_VERSION = 0x00000600;

        public const uint USB_PORTATTR_NO_CONNECTOR = 0x00000001;

        public const uint USB_PORTATTR_SHARED_USB2 = 0x00000002;

        public const uint USB_PORTATTR_MINI_CONNECTOR = 0x00000004;

        public const uint USB_PORTATTR_OEM_CONNECTOR = 0x00000008;

        public const uint USB_PORTATTR_OWNED_BY_CC = 0x01000000;

        public const uint USB_PORTATTR_NO_OVERCURRENT_UI = 0x02000000;

        public const uint USB_DEFAULT_DEVICE_ADDRESS = 0;

        public const uint USB_DEFAULT_ENDPOINT_ADDRESS = 0;

        public const uint USB_DEFAULT_MAX_PACKET = 64;

        public const uint URB_FUNCTION_SELECT_CONFIGURATION = 0x0000;

        public const uint URB_FUNCTION_SELECT_INTERFACE = 0x0001;

        public const uint URB_FUNCTION_ABORT_PIPE = 0x0002;

        public const uint URB_FUNCTION_TAKE_FRAME_LENGTH_CONTROL = 0x0003;

        public const uint URB_FUNCTION_RELEASE_FRAME_LENGTH_CONTROL = 0x0004;

        public const uint URB_FUNCTION_GET_FRAME_LENGTH = 0x0005;

        public const uint URB_FUNCTION_SET_FRAME_LENGTH = 0x0006;

        public const uint URB_FUNCTION_GET_CURRENT_FRAME_NUMBER = 0x0007;

        public const uint URB_FUNCTION_CONTROL_TRANSFER = 0x0008;

        public const uint URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER = 0x0009;

        public const uint URB_FUNCTION_ISOCH_TRANSFER = 0x000A;

        public const uint URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE = 0x000B;

        public const uint URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE = 0x000C;

        public const uint URB_FUNCTION_SET_FEATURE_TO_DEVICE = 0x000D;

        public const uint URB_FUNCTION_SET_FEATURE_TO_INTERFACE = 0x000E;

        public const uint URB_FUNCTION_SET_FEATURE_TO_ENDPOINT = 0x000F;

        public const uint URB_FUNCTION_CLEAR_FEATURE_TO_DEVICE = 0x0010;

        public const uint URB_FUNCTION_CLEAR_FEATURE_TO_INTERFACE = 0x0011;

        public const uint URB_FUNCTION_CLEAR_FEATURE_TO_ENDPOINT = 0x0012;

        public const uint URB_FUNCTION_GET_STATUS_FROM_DEVICE = 0x0013;

        public const uint URB_FUNCTION_GET_STATUS_FROM_INTERFACE = 0x0014;

        public const uint URB_FUNCTION_GET_STATUS_FROM_ENDPOINT = 0x0015;

        public const uint URB_FUNCTION_RESERVED_0X0016 = 0x0016;

        public const uint URB_FUNCTION_VENDOR_DEVICE = 0x0017;

        public const uint URB_FUNCTION_VENDOR_INTERFACE = 0x0018;

        public const uint URB_FUNCTION_VENDOR_ENDPOINT = 0x0019;

        public const uint URB_FUNCTION_CLASS_DEVICE = 0x001A;

        public const uint URB_FUNCTION_CLASS_INTERFACE = 0x001B;

        public const uint URB_FUNCTION_CLASS_ENDPOINT = 0x001C;

        public const uint URB_FUNCTION_RESERVE_0X001D = 0x001D;

        public const uint URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL = 0x001E;

        public const uint URB_FUNCTION_CLASS_OTHER = 0x001F;

        public const uint URB_FUNCTION_VENDOR_OTHER = 0x0020;

        public const uint URB_FUNCTION_GET_STATUS_FROM_OTHER = 0x0021;

        public const uint URB_FUNCTION_CLEAR_FEATURE_TO_OTHER = 0x0022;

        public const uint URB_FUNCTION_SET_FEATURE_TO_OTHER = 0x0023;

        public const uint URB_FUNCTION_GET_DESCRIPTOR_FROM_ENDPOINT = 0x0024;

        public const uint URB_FUNCTION_SET_DESCRIPTOR_TO_ENDPOINT = 0x0025;

        public const uint URB_FUNCTION_GET_CONFIGURATION = 0x0026;

        public const uint URB_FUNCTION_GET_INTERFACE = 0x0027;

        public const uint URB_FUNCTION_GET_DESCRIPTOR_FROM_INTERFACE = 0x0028;

        public const uint URB_FUNCTION_SET_DESCRIPTOR_TO_INTERFACE = 0x0029;

        public const uint URB_FUNCTION_RESERVE_0X002B = 0x002B;

        public const uint URB_FUNCTION_RESERVE_0X002C = 0x002C;

        public const uint URB_FUNCTION_RESERVE_0X002D = 0x002D;

        public const uint URB_FUNCTION_RESERVE_0X002E = 0x002E;

        public const uint URB_FUNCTION_RESERVE_0X002F = 0x002F;

        public const uint URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR = 0x002A;

        public const uint URB_FUNCTION_SYNC_RESET_PIPE = 0x0030;

        public const uint URB_FUNCTION_SYNC_CLEAR_STALL = 0x0031;

        public const uint URB_FUNCTION_CONTROL_TRANSFER_EX = 0x0032;

        public const uint URB_FUNCTION_RESERVE_0X0033 = 0x0033;

        public const uint URB_FUNCTION_RESERVE_0X0034 = 0x0034;

        public const uint URB_FUNCTION_OPEN_STATIC_STREAMS = 0x0035;

        public const uint URB_FUNCTION_CLOSE_STATIC_STREAMS = 0x0036;

        public const uint URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER_USING_CHAINED_MDL = 0x0037;

        public const uint URB_FUNCTION_ISOCH_TRANSFER_USING_CHAINED_MDL = 0x0038;

        public const uint URB_FUNCTION_GET_ISOCH_PIPE_TRANSFER_PATH_DELAYS = 0x003D;

        public const uint USBD_SHORT_TRANSFER_OK = 0x00000002;

        public const uint USBD_START_ISO_TRANSFER_ASAP = 0x00000004;

        public const uint USBD_DEFAULT_PIPE_TRANSFER = 0x00000008;

        public const uint USBD_TRANSFER_DIRECTION_OUT = 0;

        public const uint USBD_TRANSFER_DIRECTION_IN = 1;

        public const uint USBD_ISO_START_FRAME_RANGE = 1024;

        public const uint USBD_DEFAULT_MAXIMUM_TRANSFER_SIZE = 0xFFFFFFFF;

        public const uint USBD_PF_CHANGE_MAX_PACKET = 0x00000001;

        public const uint USBD_PF_SHORT_PACKET_OPT = 0x00000002;

        public const uint USBD_PF_ENABLE_RT_THREAD_ACCESS = 0x00000004;

        public const uint USBD_PF_MAP_ADD_TRANSFERS = 0x00000008;

        public const uint USBD_PF_VIDEO_PRIORITY = 0x00000010;

        public const uint USBD_PF_VOICE_PRIORITY = 0x00000020;

        public const uint USBD_PF_INTERACTIVE_PRIORITY = 0x00000030;

        public const uint USBD_PF_PRIORITY_MASK = 0x000000F0;

        public const uint USBD_PF_HANDLES_SSP_HIGH_BANDWIDTH_ISOCH = 0x00000100;

        public const uint USBD_PF_SSP_HIGH_BANDWIDTH_ISOCH = 0x00010000;

        public const uint OS_STRING_DESCRIPTOR_INDEX = 0xEE;

        public const uint MS_GENRE_DESCRIPTOR_INDEX = 0x0001;

        public const uint MS_POWER_DESCRIPTOR_INDEX = 0x0002;

        public const uint MS_OS_FLAGS_CONTAINERID = 0x02;

        public const uint URB_OPEN_STATIC_STREAMS_VERSION_100 = 0x100;

    }
}
