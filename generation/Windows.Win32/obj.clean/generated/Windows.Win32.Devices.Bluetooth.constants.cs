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


namespace Windows.Win32.Devices.Bluetooth
{
    public static partial class Apis
    {
        public const uint BT_PORT_MIN = 0x1;

        public const uint BT_PORT_MAX = 0xffff;

        public const uint BT_PORT_DYN_FIRST = 0x1001;

        public const ushort AF_BTH = 32;

        public const uint NS_BTH = 16;

        public static readonly Guid SVCID_BTH_PROVIDER__scanned__ = new Guid(0x6aa63e0, 0x7d60, 0x41ff, 0xaf, 0xb2, 0x3e, 0xe6, 0xd2, 0xd9, 0x39, 0x2d);

        public const uint BTH_ADDR_STRING_SIZE = 12;

        public const uint BTHPROTO_RFCOMM = 0x0003;

        public const uint BTHPROTO_L2CAP = 0x0100;

        public const uint SOL_SDP = 0x0101;

        public const uint SO_BTH_AUTHENTICATE = 0x80000001;

        public const uint SO_BTH_ENCRYPT = 0x00000002;

        public const uint SO_BTH_MTU = 0x80000007;

        public const uint SO_BTH_MTU_MAX = 0x80000008;

        public const uint SO_BTH_MTU_MIN = 0x8000000a;

        public const uint RFCOMM_MAX_MTU = 0x000003F3;

        public const uint RFCOMM_MIN_MTU = 0x00000017;

        public const uint BTH_SDP_VERSION = 1;

        public const uint SDP_DEFAULT_INQUIRY_SECONDS = 6;

        public const uint SDP_MAX_INQUIRY_SECONDS = 60;

        public const uint SDP_DEFAULT_INQUIRY_MAX_RESPONSES = 255;

        public const uint SDP_SERVICE_SEARCH_REQUEST = 1;

        public const uint SDP_SERVICE_ATTRIBUTE_REQUEST = 2;

        public const uint SDP_SERVICE_SEARCH_ATTRIBUTE_REQUEST = 3;

        public const uint BTHNS_RESULT_DEVICE_CONNECTED = 0x00010000;

        public const uint BTHNS_RESULT_DEVICE_REMEMBERED = 0x00020000;

        public const uint BTHNS_RESULT_DEVICE_AUTHENTICATED = 0x00040000;

        public const uint RFCOMM_CMD_NONE = 0;

        public const uint RFCOMM_CMD_MSC = 1;

        public const uint RFCOMM_CMD_RLS = 2;

        public const uint RFCOMM_CMD_RPN = 3;

        public const uint RFCOMM_CMD_RPN_REQUEST = 4;

        public const uint RFCOMM_CMD_RPN_RESPONSE = 5;

        public const uint BLUETOOTH_MAX_NAME_SIZE = 248;

        public const uint BLUETOOTH_MAX_PASSKEY_SIZE = 16;

        public const uint BLUETOOTH_MAX_PASSKEY_BUFFER_SIZE = BLUETOOTH_MAX_PASSKEY_SIZE + 1;

        public const uint BLUETOOTH_MAX_SERVICE_NAME_SIZE = 256;

        public const uint BLUETOOTH_DEVICE_NAME_SIZE = 256;

        public const uint BLUETOOTH_SERVICE_DISABLE = 0x00;

        public const uint BLUETOOTH_SERVICE_ENABLE = 0x01;

        public static readonly Guid GUID_BLUETOOTHLE_DEVICE_INTERFACE__scanned__ = new Guid(0x781aee18, 0x7733, 0x4ce4, 0xad, 0xd0, 0x91, 0xf4, 0x1c, 0x67, 0xb5, 0x92);

        public static readonly Guid GUID_BLUETOOTH_GATT_SERVICE_DEVICE_INTERFACE__scanned__ = new Guid(0x6e3bb679, 0x4372, 0x40c8, 0x9e, 0xaa, 0x45, 0x09, 0xdf, 0x26, 0x0c, 0xd8);

        public static readonly Guid BTH_LE_ATT_BLUETOOTH_BASE_GUID__scanned__ = new Guid(0x00000000, 0x0000, 0x1000, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB);

        public const uint BTH_LE_SERVICE_GAP = 0x1800;

        public const uint BTH_LE_SERVICE_GATT = 0x1801;

        public const uint BTH_LE_GATT_ATTRIBUTE_TYPE_PRIMARY_SERVICE = 0x2800;

        public const uint BTH_LE_GATT_ATTRIBUTE_TYPE_SECONDARY_SERVICE = 0x2801;

        public const uint BTH_LE_GATT_ATTRIBUTE_TYPE_INCLUDE = 0x2802;

        public const uint BTH_LE_GATT_ATTRIBUTE_TYPE_CHARACTERISTIC = 0x2803;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_EXTENDED_PROPERTIES = 0x2900;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_USER_DESCRIPTION = 0x2901;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_CLIENT_CONFIGURATION = 0x2902;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_SERVER_CONFIGURATION = 0x2903;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_FORMAT = 0x2904;

        public const uint BTH_LE_GATT_CHARACTERISTIC_DESCRIPTOR_AGGREGATE_FORMAT = 0x2905;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_DEVICE_NAME = 0x2A00;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_APPEARANCE = 0x2A01;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_PERIPHERAL_PRIVACY_FLAG = 0x2A02;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_RECONNECTION_ADDRESS = 0x2A03;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_PERIPHERAL_PREFERED_CONNECTION_PARAMETER = 0x2A04;

        public const uint BTH_LE_GATT_CHARACTERISTIC_TYPE_SERVICE_CHANGED = 0x2A05;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_OFFSET = 0x6;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_MASK = 0x3ff;

        public const uint BTH_LE_GAP_APPEARANCE_SUB_CATEGORY_MASK = 0x3f;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_UNCATEGORIZED = 0x0000;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_PHONE = 0x0001;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_COMPUTER = 0x0002;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_WATCH = 0x0003;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_CLOCK = 0x0004;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_DISPLAY = 0x0005;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_REMOTE_CONTROL = 0x0006;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_EYE_GLASSES = 0x0007;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_TAG = 0x0008;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_KEYRING = 0x0009;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_MEDIA_PLAYER = 0x000a;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_BARCODE_SCANNER = 0x000b;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_THERMOMETER = 0x000c;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_HEART_RATE = 0x000d;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_BLOOD_PRESSURE = 0x000e;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_HID = 0x000f;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_GLUCOSE_METER = 0x0010;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_RUNNING_WALKING_SENSOR = 0x0011;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_CYCLING = 0x0012;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_PLUSE_OXIMETER = 0x0031;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_WEIGHT_SCALE = 0x0032;

        public const uint BTH_LE_GAP_APPEARANCE_CATEGORY_OUTDOOR_SPORTS_ACTIVITY = 0x0051;

        public const uint BTH_LE_GAP_APPEARANCE_SUBCATEGORY_GENERIC = 0x00;

        public const uint BTH_LE_GAP_APPEARANCE_WATCH_SUBCATEGORY_SPORTS_WATCH = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_THERMOMETER_SUBCATEGORY_EAR = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_HEART_RATE_SUBCATEGORY_HEART_RATE_BELT = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_BLOOD_PRESSURE_SUBCATEGORY_ARM = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_BLOOD_PRESSURE_SUBCATEGORY_WRIST = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_KEYBOARD = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_MOUSE = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_JOYSTICK = 0x03;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_GAMEPAD = 0x04;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_DIGITIZER_TABLET = 0x05;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_CARD_READER = 0x06;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_DIGITAL_PEN = 0x07;

        public const uint BTH_LE_GAP_APPEARANCE_HID_SUBCATEGORY_BARCODE_SCANNER = 0x08;

        public const uint BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_IN_SHOE = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_ON_SHOE = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_RUNNING_WALKING_SENSOR_SUBCATEGORY_ON_HIP = 0x03;

        public const uint BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_CYCLING_COMPUTER = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_SPEED_SENSOR = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_CADENCE_SENSOR = 0x03;

        public const uint BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_POWER_SENSOR = 0x04;

        public const uint BTH_LE_GAP_APPEARANCE_CYCLING_SUBCATEGORY_SPEED_AND_CADENCE_SENSOR = 0x05;

        public const uint BTH_LE_GAP_APPEARANCE_PULSE_OXIMETER_SUBCATEGORY_FINGERTIP = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_PULSE_OXIMETER_SUBCATEGORY_WRIST_WORN = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_DISPLAY_DEVICE = 0x01;

        public const uint BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_NAVIGATION_DISPLAY_DEVICE = 0x02;

        public const uint BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_POD = 0x03;

        public const uint BTH_LE_GAP_APPEARANCE_OUTDOOR_SPORTS_ACTIVITY_SUBCATEGORY_LOCATION_NAVIGATION_POD = 0x04;

        public const uint BTH_LE_GATT_DEFAULT_MAX_INCLUDED_SERVICES_DEPTH = 3;

        public const uint BTH_LE_ATT_TRANSACTION_TIMEOUT = 30;

        public const uint BTH_LE_ATT_MAX_VALUE_SIZE = 512;

        public const uint BTH_LE_ATT_CID = 0x0004;

        public const uint BTHLEENUM_ATT_MTU_MIN = 23;

        public const uint BTHLEENUM_ATT_MTU_MAX = 0xFFFF;

        public const uint BTHLEENUM_ATT_MTU_INITIAL_NEGOTIATION = 525;

        public const uint BTH_LE_ERROR_INVALID_HANDLE = 0x01;

        public const uint BTH_LE_ERROR_READ_NOT_PERMITTED = 0x02;

        public const uint BTH_LE_ERROR_WRITE_NOT_PERMITTED = 0x03;

        public const uint BTH_LE_ERROR_INVALID_PDU = 0x04;

        public const uint BTH_LE_ERROR_INSUFFICIENT_AUTHENTICATION = 0x05;

        public const uint BTH_LE_ERROR_REQUEST_NOT_SUPPORTED = 0x06;

        public const uint BTH_LE_ERROR_INVALID_OFFSET = 0x07;

        public const uint BTH_LE_ERROR_INSUFFICIENT_AUTHORIZATION = 0x08;

        public const uint BTH_LE_ERROR_PREPARE_QUEUE_FULL = 0x09;

        public const uint BTH_LE_ERROR_ATTRIBUTE_NOT_FOUND = 0x0A;

        public const uint BTH_LE_ERROR_ATTRIBUTE_NOT_LONG = 0x0B;

        public const uint BTH_LE_ERROR_INSUFFICIENT_ENCRYPTION_KEY_SIZE = 0x0C;

        public const uint BTH_LE_ERROR_INVALID_ATTRIBUTE_VALUE_LENGTH = 0x0D;

        public const uint BTH_LE_ERROR_UNLIKELY = 0x0E;

        public const uint BTH_LE_ERROR_INSUFFICIENT_ENCRYPTION = 0x0F;

        public const uint BTH_LE_ERROR_UNSUPPORTED_GROUP_TYPE = 0x10;

        public const uint BTH_LE_ERROR_INSUFFICIENT_RESOURCES = 0x11;

        public const uint BTH_LE_ERROR_UNKNOWN = 0x1000;

        public const uint BLUETOOTH_GATT_FLAG_NONE = 0x00000000;

        public const uint BLUETOOTH_GATT_FLAG_CONNECTION_ENCRYPTED = 0x00000001;

        public const uint BLUETOOTH_GATT_FLAG_CONNECTION_AUTHENTICATED = 0x00000002;

        public const uint BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_DEVICE = 0x00000004;

        public const uint BLUETOOTH_GATT_FLAG_FORCE_READ_FROM_CACHE = 0x00000008;

        public const uint BLUETOOTH_GATT_FLAG_SIGNED_WRITE = 0x00000010;

        public const uint BLUETOOTH_GATT_FLAG_WRITE_WITHOUT_RESPONSE = 0x00000020;

        public const uint BLUETOOTH_GATT_FLAG_RETURN_ALL = 0x00000040;

        public static readonly Guid GUID_BTHPORT_DEVICE_INTERFACE__scanned__ = new Guid(0x850302a, 0xb344, 0x4fda, 0x9b, 0xe9, 0x90, 0x57, 0x6b, 0x8d, 0x46, 0xf0);

        public static readonly Guid GUID_BTH_RFCOMM_SERVICE_DEVICE_INTERFACE__scanned__ = new Guid(0xb142fc3e, 0xfa4e, 0x460b, 0x8a, 0xbc, 0x07, 0x2b, 0x62, 0x8b, 0x3c, 0x70);

        public static readonly Guid GUID_BLUETOOTH_RADIO_IN_RANGE__scanned__ = new Guid(0xea3b5b82, 0x26ee, 0x450e, 0xb0, 0xd8, 0xd2, 0x6f, 0xe3, 0x0a, 0x38, 0x69);

        public static readonly Guid GUID_BLUETOOTH_RADIO_OUT_OF_RANGE__scanned__ = new Guid(0xe28867c9, 0xc2aa, 0x4ced, 0xb9, 0x69, 0x45, 0x70, 0x86, 0x60, 0x37, 0xc4);

        public static readonly Guid GUID_BLUETOOTH_L2CAP_EVENT__scanned__ = new Guid(0x7eae4030, 0xb709, 0x4aa8, 0xac, 0x55, 0xe9, 0x53, 0x82, 0x9c, 0x9d, 0xaa);

        public static readonly Guid GUID_BLUETOOTH_HCI_EVENT__scanned__ = new Guid(0xfc240062, 0x1541, 0x49be, 0xb4, 0x63, 0x84, 0xc4, 0xdc, 0xd7, 0xbf, 0x7f);

        public static readonly Guid GUID_BLUETOOTH_AUTHENTICATION_REQUEST__scanned__ = new Guid(0x5DC9136D, 0x996C, 0x46DB, 0x84, 0xF5, 0x32, 0xC0, 0xA3, 0xF4, 0x73, 0x52);

        public static readonly Guid GUID_BLUETOOTH_KEYPRESS_EVENT__scanned__ = new Guid(0xD668DFCD, 0x0F4E, 0x4EFC, 0xBF, 0xE0, 0x39, 0x2E, 0xEE, 0xC5, 0x10, 0x9C);

        public static readonly Guid GUID_BLUETOOTH_HCI_VENDOR_EVENT__scanned__ = new Guid(0x547247e6, 0x45bb, 0x4c33, 0xaf, 0x8c, 0xc0, 0x0e, 0xfe, 0x15, 0xa7, 0x1d);

        public static readonly Guid Bluetooth_Base_UUID__scanned__ = new Guid(0x00000000, 0x0000, 0x1000, 0x80, 0x00, 0x00, 0x80, 0x5F, 0x9B, 0x34, 0xFB);

        public const uint SDP_PROTOCOL_UUID16 = 0x0001;

        public const uint UDP_PROTOCOL_UUID16 = 0x0002;

        public const uint RFCOMM_PROTOCOL_UUID16 = 0x0003;

        public const uint TCP_PROTOCOL_UUID16 = 0x0004;

        public const uint TCSBIN_PROTOCOL_UUID16 = 0x0005;

        public const uint TCSAT_PROTOCOL_UUID16 = 0x0006;

        public const uint ATT_PROTOCOL_UUID16 = 0x0007;

        public const uint OBEX_PROTOCOL_UUID16 = 0x0008;

        public const uint IP_PROTOCOL_UUID16 = 0x0009;

        public const uint FTP_PROTOCOL_UUID16 = 0x000A;

        public const uint HTTP_PROTOCOL_UUID16 = 0x000C;

        public const uint WSP_PROTOCOL_UUID16 = 0x000E;

        public const uint BNEP_PROTOCOL_UUID16 = 0x000F;

        public const uint UPNP_PROTOCOL_UUID16 = 0x0010;

        public const uint HID_PROTOCOL_UUID16 = 0x0011;

        public const uint HCCC_PROTOCOL_UUID16 = 0x0012;

        public const uint HCDC_PROTOCOL_UUID16 = 0x0014;

        public const uint HCN_PROTOCOL_UUID16 = 0x0016;

        public const uint AVCTP_PROTOCOL_UUID16 = 0x0017;

        public const uint AVDTP_PROTOCOL_UUID16 = 0x0019;

        public const uint CMPT_PROTOCOL_UUID16 = 0x001B;

        public const uint UDI_C_PLANE_PROTOCOL_UUID16 = 0x001D;

        public const uint L2CAP_PROTOCOL_UUID16 = 0x0100;

        public const uint ServiceDiscoveryServerServiceClassID_UUID16 = 0x1000;

        public const uint BrowseGroupDescriptorServiceClassID_UUID16 = 0x1001;

        public const uint PublicBrowseGroupServiceClassID_UUID16 = 0x1002;

        public const uint SerialPortServiceClassID_UUID16 = 0x1101;

        public const uint LANAccessUsingPPPServiceClassID_UUID16 = 0x1102;

        public const uint DialupNetworkingServiceClassID_UUID16 = 0x1103;

        public const uint IrMCSyncServiceClassID_UUID16 = 0x1104;

        public const uint OBEXObjectPushServiceClassID_UUID16 = 0x1105;

        public const uint OBEXFileTransferServiceClassID_UUID16 = 0x1106;

        public const uint IrMcSyncCommandServiceClassID_UUID16 = 0x1107;

        public const uint HeadsetServiceClassID_UUID16 = 0x1108;

        public const uint CordlessTelephonyServiceClassID_UUID16 = 0x1109;

        public const uint AudioSourceServiceClassID_UUID16 = 0x110A;

        public const uint AudioSinkServiceClassID_UUID16 = 0x110B;

        public const uint AVRemoteControlTargetServiceClassID_UUID16 = 0x110C;

        public const uint AVRemoteControlServiceClassID_UUID16 = 0x110E;

        public const uint AVRemoteControlControllerServiceClass_UUID16 = 0x110F;

        public const uint IntercomServiceClassID_UUID16 = 0x1110;

        public const uint FaxServiceClassID_UUID16 = 0x1111;

        public const uint HeadsetAudioGatewayServiceClassID_UUID16 = 0x1112;

        public const uint WAPServiceClassID_UUID16 = 0x1113;

        public const uint WAPClientServiceClassID_UUID16 = 0x1114;

        public const uint PANUServiceClassID_UUID16 = 0x1115;

        public const uint NAPServiceClassID_UUID16 = 0x1116;

        public const uint GNServiceClassID_UUID16 = 0x1117;

        public const uint DirectPrintingServiceClassID_UUID16 = 0x1118;

        public const uint ReferencePrintingServiceClassID_UUID16 = 0x1119;

        public const uint ImagingResponderServiceClassID_UUID16 = 0x111B;

        public const uint ImagingAutomaticArchiveServiceClassID_UUID16 = 0x111C;

        public const uint ImagingReferenceObjectsServiceClassID_UUID16 = 0x111D;

        public const uint HandsfreeServiceClassID_UUID16 = 0x111E;

        public const uint HandsfreeAudioGatewayServiceClassID_UUID16 = 0x111F;

        public const uint DirectPrintingReferenceObjectsServiceClassID_UUID16 = 0x1120;

        public const uint ReflectsUIServiceClassID_UUID16 = 0x1121;

        public const uint PrintingStatusServiceClassID_UUID16 = 0x1123;

        public const uint HumanInterfaceDeviceServiceClassID_UUID16 = 0x1124;

        public const uint HCRPrintServiceClassID_UUID16 = 0x1126;

        public const uint HCRScanServiceClassID_UUID16 = 0x1127;

        public const uint CommonISDNAccessServiceClassID_UUID16 = 0x1128;

        public const uint VideoConferencingGWServiceClassID_UUID16 = 0x1129;

        public const uint UDIMTServiceClassID_UUID16 = 0x112A;

        public const uint UDITAServiceClassID_UUID16 = 0x112B;

        public const uint AudioVideoServiceClassID_UUID16 = 0x112C;

        public const uint SimAccessServiceClassID_UUID16 = 0x112D;

        public const uint PhonebookAccessPceServiceClassID_UUID16 = 0x112E;

        public const uint PhonebookAccessPseServiceClassID_UUID16 = 0x112F;

        public const uint HeadsetHSServiceClassID_UUID16 = 0x1131;

        public const uint MessageAccessServerServiceClassID_UUID16 = 0x1132;

        public const uint MessageNotificationServerServiceClassID_UUID16 = 0x1133;

        public const uint GNSSServerServiceClassID_UUID16 = 0x1136;

        public const uint ThreeDimensionalDisplayServiceClassID_UUID16 = 0x1137;

        public const uint ThreeDimensionalGlassesServiceClassID_UUID16 = 0x1138;

        public const uint MPSServiceClassID_UUID16 = 0x113B;

        public const uint CTNAccessServiceClassID_UUID16 = 0x113C;

        public const uint CTNNotificationServiceClassID_UUID16 = 0x113D;

        public const uint PnPInformationServiceClassID_UUID16 = 0x1200;

        public const uint GenericNetworkingServiceClassID_UUID16 = 0x1201;

        public const uint GenericFileTransferServiceClassID_UUID16 = 0x1202;

        public const uint GenericAudioServiceClassID_UUID16 = 0x1203;

        public const uint GenericTelephonyServiceClassID_UUID16 = 0x1204;

        public const uint UPnpServiceClassID_UUID16 = 0x1205;

        public const uint UPnpIpServiceClassID_UUID16 = 0x1206;

        public const uint ESdpUpnpIpPanServiceClassID_UUID16 = 0x1300;

        public const uint ESdpUpnpIpLapServiceClassID_UUID16 = 0x1301;

        public const uint ESdpUpnpL2capServiceClassID_UUID16 = 0x1302;

        public const uint VideoSourceServiceClassID_UUID16 = 0x1303;

        public const uint VideoSinkServiceClassID_UUID16 = 0x1304;

        public const uint HealthDeviceProfileSourceServiceClassID_UUID16 = 0x1401;

        public const uint HealthDeviceProfileSinkServiceClassID_UUID16 = 0x1402;

        public const uint AdvancedAudioDistributionProfileID_UUID16 = 0x110D;

        public const uint ImagingServiceProfileID_UUID16 = 0x111A;

        public const uint BasicPrintingProfileID_UUID16 = 0x1122;

        public const uint HardcopyCableReplacementProfileID_UUID16 = 0x1125;

        public const uint PhonebookAccessProfileID_UUID16 = 0x1130;

        public const uint MessageAccessProfileID_UUID16 = 0x1134;

        public const uint GNSSProfileID_UUID16 = 0x1135;

        public const uint ThreeDimensionalSynchronizationProfileID_UUID16 = 0x1139;

        public const uint MPSProfileID_UUID16 = 0x113A;

        public const uint CTNProfileID_UUID16 = 0x113E;

        public const uint VideoDistributionProfileID_UUID16 = 0x1305;

        public const uint HealthDeviceProfileID_UUID16 = 0x1400;

        public const uint BTH_MAX_NAME_SIZE = 248;

        public const uint BTH_MAX_PIN_SIZE = 16;

        public const uint BTH_LINK_KEY_LENGTH = 16;

        public const uint BTH_MFG_ERICSSON = 0;

        public const uint BTH_MFG_NOKIA = 1;

        public const uint BTH_MFG_INTEL = 2;

        public const uint BTH_MFG_IBM = 3;

        public const uint BTH_MFG_TOSHIBA = 4;

        public const uint BTH_MFG_3COM = 5;

        public const uint BTH_MFG_MICROSOFT = 6;

        public const uint BTH_MFG_LUCENT = 7;

        public const uint BTH_MFG_MOTOROLA = 8;

        public const uint BTH_MFG_INFINEON = 9;

        public const uint BTH_MFG_CSR = 10;

        public const uint BTH_MFG_SILICONWAVE = 11;

        public const uint BTH_MFG_DIGIANSWER = 12;

        public const uint BTH_MFG_TI = 13;

        public const uint BTH_MFG_PARTHUS = 14;

        public const uint BTH_MFG_BROADCOM = 15;

        public const uint BTH_MFG_MITEL = 16;

        public const uint BTH_MFG_WIDCOMM = 17;

        public const uint BTH_MFG_ZEEVO = 18;

        public const uint BTH_MFG_ATMEL = 19;

        public const uint BTH_MFG_MITSIBUSHI = 20;

        public const uint BTH_MFG_RTX_TELECOM = 21;

        public const uint BTH_MFG_KC_TECHNOLOGY = 22;

        public const uint BTH_MFG_NEWLOGIC = 23;

        public const uint BTH_MFG_TRANSILICA = 24;

        public const uint BTH_MFG_ROHDE_SCHWARZ = 25;

        public const uint BTH_MFG_TTPCOM = 26;

        public const uint BTH_MFG_SIGNIA = 27;

        public const uint BTH_MFG_CONEXANT = 28;

        public const uint BTH_MFG_QUALCOMM = 29;

        public const uint BTH_MFG_INVENTEL = 30;

        public const uint BTH_MFG_AVM_BERLIN = 31;

        public const uint BTH_MFG_BANDSPEED = 32;

        public const uint BTH_MFG_MANSELLA = 33;

        public const uint BTH_MFG_NEC = 34;

        public const uint BTH_MFG_WAVEPLUS_TECHNOLOGY_CO = 35;

        public const uint BTH_MFG_ALCATEL = 36;

        public const uint BTH_MFG_PHILIPS_SEMICONDUCTOR = 37;

        public const uint BTH_MFG_C_TECHNOLOGIES = 38;

        public const uint BTH_MFG_OPEN_INTERFACE = 39;

        public const uint BTH_MFG_RF_MICRO_DEVICES = 40;

        public const uint BTH_MFG_HITACHI = 41;

        public const uint BTH_MFG_SYMBOL_TECHNOLOGIES = 42;

        public const uint BTH_MFG_TENOVIS = 43;

        public const uint BTH_MFG_MACRONIX_INTERNATIONAL = 44;

        public const uint BTH_MFG_MARVELL = 72;

        public const uint BTH_MFG_APPLE = 76;

        public const uint BTH_MFG_NORDIC_SEMICONDUCTORS_ASA = 89;

        public const uint BTH_MFG_ARUBA_NETWORKS = 283;

        public const uint BTH_MFG_INTERNAL_USE = 65535;

        public const uint SAP_BIT_OFFSET = 0;

        public const uint COD_FORMAT_BIT_OFFSET = 0;

        public const uint COD_MINOR_BIT_OFFSET = 2;

        public const uint COD_FORMAT_MASK = 0x000003;

        public const uint COD_MINOR_MASK = 0x0000FC;

        public const uint COD_MAJOR_MASK = 0x001F00;

        public const uint COD_SERVICE_MASK = 0xFFE000;

        public const uint COD_VERSION = 0x0;

        public const uint COD_SERVICE_LIMITED = 0x0001;

        public const uint COD_SERVICE_POSITIONING = 0x0008;

        public const uint COD_SERVICE_NETWORKING = 0x0010;

        public const uint COD_SERVICE_RENDERING = 0x0020;

        public const uint COD_SERVICE_CAPTURING = 0x0040;

        public const uint COD_SERVICE_OBJECT_XFER = 0x0080;

        public const uint COD_SERVICE_AUDIO = 0x0100;

        public const uint COD_SERVICE_TELEPHONY = 0x0200;

        public const uint COD_SERVICE_INFORMATION = 0x0400;

        public const uint COD_SERVICE_MAX_COUNT = 9;

        public const uint COD_MAJOR_MISCELLANEOUS = 0x00;

        public const uint COD_MAJOR_COMPUTER = 0x01;

        public const uint COD_MAJOR_PHONE = 0x02;

        public const uint COD_MAJOR_LAN_ACCESS = 0x03;

        public const uint COD_MAJOR_AUDIO = 0x04;

        public const uint COD_MAJOR_PERIPHERAL = 0x05;

        public const uint COD_MAJOR_IMAGING = 0x06;

        public const uint COD_MAJOR_WEARABLE = 0x07;

        public const uint COD_MAJOR_TOY = 0x08;

        public const uint COD_MAJOR_HEALTH = 0x09;

        public const uint COD_MAJOR_UNCLASSIFIED = 0x1F;

        public const uint COD_COMPUTER_MINOR_UNCLASSIFIED = 0x00;

        public const uint COD_COMPUTER_MINOR_DESKTOP = 0x01;

        public const uint COD_COMPUTER_MINOR_SERVER = 0x02;

        public const uint COD_COMPUTER_MINOR_LAPTOP = 0x03;

        public const uint COD_COMPUTER_MINOR_HANDHELD = 0x04;

        public const uint COD_COMPUTER_MINOR_PALM = 0x05;

        public const uint COD_COMPUTER_MINOR_WEARABLE = 0x06;

        public const uint COD_PHONE_MINOR_UNCLASSIFIED = 0x00;

        public const uint COD_PHONE_MINOR_CELLULAR = 0x01;

        public const uint COD_PHONE_MINOR_CORDLESS = 0x02;

        public const uint COD_PHONE_MINOR_SMART = 0x03;

        public const uint COD_PHONE_MINOR_WIRED_MODEM = 0x04;

        public const uint COD_AUDIO_MINOR_UNCLASSIFIED = 0x00;

        public const uint COD_AUDIO_MINOR_HEADSET = 0x01;

        public const uint COD_AUDIO_MINOR_HANDS_FREE = 0x02;

        public const uint COD_AUDIO_MINOR_HEADSET_HANDS_FREE = 0x03;

        public const uint COD_AUDIO_MINOR_MICROPHONE = 0x04;

        public const uint COD_AUDIO_MINOR_LOUDSPEAKER = 0x05;

        public const uint COD_AUDIO_MINOR_HEADPHONES = 0x06;

        public const uint COD_AUDIO_MINOR_PORTABLE_AUDIO = 0x07;

        public const uint COD_AUDIO_MINOR_CAR_AUDIO = 0x08;

        public const uint COD_AUDIO_MINOR_SET_TOP_BOX = 0x09;

        public const uint COD_AUDIO_MINOR_HIFI_AUDIO = 0x0A;

        public const uint COD_AUDIO_MINOR_VCR = 0x0B;

        public const uint COD_AUDIO_MINOR_VIDEO_CAMERA = 0x0C;

        public const uint COD_AUDIO_MINOR_CAMCORDER = 0x0D;

        public const uint COD_AUDIO_MINOR_VIDEO_MONITOR = 0x0E;

        public const uint COD_AUDIO_MINOR_VIDEO_DISPLAY_LOUDSPEAKER = 0x0F;

        public const uint COD_AUDIO_MINOR_VIDEO_DISPLAY_CONFERENCING = 0x10;

        public const uint COD_AUDIO_MINOR_GAMING_TOY = 0x12;

        public const uint COD_PERIPHERAL_MINOR_KEYBOARD_MASK = 0x10;

        public const uint COD_PERIPHERAL_MINOR_POINTER_MASK = 0x20;

        public const uint COD_PERIPHERAL_MINOR_NO_CATEGORY = 0x00;

        public const uint COD_PERIPHERAL_MINOR_JOYSTICK = 0x01;

        public const uint COD_PERIPHERAL_MINOR_GAMEPAD = 0x02;

        public const uint COD_PERIPHERAL_MINOR_REMOTE_CONTROL = 0x03;

        public const uint COD_PERIPHERAL_MINOR_SENSING = 0x04;

        public const uint COD_IMAGING_MINOR_DISPLAY_MASK = 0x04;

        public const uint COD_IMAGING_MINOR_CAMERA_MASK = 0x08;

        public const uint COD_IMAGING_MINOR_SCANNER_MASK = 0x10;

        public const uint COD_IMAGING_MINOR_PRINTER_MASK = 0x20;

        public const uint COD_WEARABLE_MINOR_WRIST_WATCH = 0x01;

        public const uint COD_WEARABLE_MINOR_PAGER = 0x02;

        public const uint COD_WEARABLE_MINOR_JACKET = 0x03;

        public const uint COD_WEARABLE_MINOR_HELMET = 0x04;

        public const uint COD_WEARABLE_MINOR_GLASSES = 0x05;

        public const uint COD_TOY_MINOR_ROBOT = 0x01;

        public const uint COD_TOY_MINOR_VEHICLE = 0x02;

        public const uint COD_TOY_MINOR_DOLL_ACTION_FIGURE = 0x03;

        public const uint COD_TOY_MINOR_CONTROLLER = 0x04;

        public const uint COD_TOY_MINOR_GAME = 0x05;

        public const uint COD_HEALTH_MINOR_BLOOD_PRESSURE_MONITOR = 0x01;

        public const uint COD_HEALTH_MINOR_THERMOMETER = 0x02;

        public const uint COD_HEALTH_MINOR_WEIGHING_SCALE = 0x03;

        public const uint COD_HEALTH_MINOR_GLUCOSE_METER = 0x04;

        public const uint COD_HEALTH_MINOR_PULSE_OXIMETER = 0x05;

        public const uint COD_HEALTH_MINOR_HEART_PULSE_MONITOR = 0x06;

        public const uint COD_HEALTH_MINOR_HEALTH_DATA_DISPLAY = 0x07;

        public const uint COD_HEALTH_MINOR_STEP_COUNTER = 0x08;

        public const uint COD_LAN_ACCESS_BIT_OFFSET = 5;

        public const uint COD_LAN_MINOR_MASK = 0x00001C;

        public const uint COD_LAN_ACCESS_MASK = 0x0000E0;

        public const uint COD_LAN_MINOR_UNCLASSIFIED = 0x00;

        public const uint COD_LAN_ACCESS_0_USED = 0x00;

        public const uint COD_LAN_ACCESS_17_USED = 0x01;

        public const uint COD_LAN_ACCESS_33_USED = 0x02;

        public const uint COD_LAN_ACCESS_50_USED = 0x03;

        public const uint COD_LAN_ACCESS_67_USED = 0x04;

        public const uint COD_LAN_ACCESS_83_USED = 0x05;

        public const uint COD_LAN_ACCESS_99_USED = 0x06;

        public const uint COD_LAN_ACCESS_FULL = 0x07;

        public const uint BTH_EIR_FLAGS_ID = 0x01;

        public const uint BTH_EIR_16_UUIDS_PARTIAL_ID = 0x02;

        public const uint BTH_EIR_16_UUIDS_COMPLETE_ID = 0x03;

        public const uint BTH_EIR_32_UUIDS_PARTIAL_ID = 0x04;

        public const uint BTH_EIR_32_UUIDS_COMPLETE_ID = 0x05;

        public const uint BTH_EIR_128_UUIDS_PARTIAL_ID = 0x06;

        public const uint BTH_EIR_128_UUIDS_COMPLETE_ID = 0x07;

        public const uint BTH_EIR_LOCAL_NAME_PARTIAL_ID = 0x08;

        public const uint BTH_EIR_LOCAL_NAME_COMPLETE_ID = 0x09;

        public const uint BTH_EIR_TX_POWER_LEVEL_ID = 0x0A;

        public const uint BTH_EIR_OOB_OPT_DATA_LEN_ID = 0x0B;

        public const uint BTH_EIR_OOB_BD_ADDR_ID = 0x0C;

        public const uint BTH_EIR_OOB_COD_ID = 0x0D;

        public const uint BTH_EIR_OOB_SP_HASH_ID = 0x0E;

        public const uint BTH_EIR_OOB_SP_RANDOMIZER_ID = 0x0F;

        public const uint BTH_EIR_MANUFACTURER_ID = 0xFF;

        public const uint BTH_EIR_SIZE = 240;

        public const uint LAP_GIAC_VALUE = 0x009E8B33;

        public const uint LAP_LIAC_VALUE = 0x009E8B00;

        public const uint BTH_ADDR_IAC_FIRST = 0x9E8B00;

        public const uint BTH_ADDR_IAC_LAST = 0x9E8B3f;

        public const uint BTH_ADDR_LIAC = 0x9E8B00;

        public const uint BTH_ADDR_GIAC = 0x9E8B33;

        public const uint BTH_ERROR_SUCCESS = 0x00;

        public const uint BTH_ERROR_UNKNOWN_HCI_COMMAND = 0x01;

        public const uint BTH_ERROR_NO_CONNECTION = 0x02;

        public const uint BTH_ERROR_HARDWARE_FAILURE = 0x03;

        public const uint BTH_ERROR_PAGE_TIMEOUT = 0x04;

        public const uint BTH_ERROR_AUTHENTICATION_FAILURE = 0x05;

        public const uint BTH_ERROR_KEY_MISSING = 0x06;

        public const uint BTH_ERROR_MEMORY_FULL = 0x07;

        public const uint BTH_ERROR_CONNECTION_TIMEOUT = 0x08;

        public const uint BTH_ERROR_MAX_NUMBER_OF_CONNECTIONS = 0x09;

        public const uint BTH_ERROR_MAX_NUMBER_OF_SCO_CONNECTIONS = 0x0a;

        public const uint BTH_ERROR_ACL_CONNECTION_ALREADY_EXISTS = 0x0b;

        public const uint BTH_ERROR_COMMAND_DISALLOWED = 0x0c;

        public const uint BTH_ERROR_HOST_REJECTED_LIMITED_RESOURCES = 0x0d;

        public const uint BTH_ERROR_HOST_REJECTED_SECURITY_REASONS = 0x0e;

        public const uint BTH_ERROR_HOST_REJECTED_PERSONAL_DEVICE = 0x0f;

        public const uint BTH_ERROR_HOST_TIMEOUT = 0x10;

        public const uint BTH_ERROR_UNSUPPORTED_FEATURE_OR_PARAMETER = 0x11;

        public const uint BTH_ERROR_INVALID_HCI_PARAMETER = 0x12;

        public const uint BTH_ERROR_REMOTE_USER_ENDED_CONNECTION = 0x13;

        public const uint BTH_ERROR_REMOTE_LOW_RESOURCES = 0x14;

        public const uint BTH_ERROR_REMOTE_POWERING_OFF = 0x15;

        public const uint BTH_ERROR_LOCAL_HOST_TERMINATED_CONNECTION = 0x16;

        public const uint BTH_ERROR_REPEATED_ATTEMPTS = 0x17;

        public const uint BTH_ERROR_PAIRING_NOT_ALLOWED = 0x18;

        public const uint BTH_ERROR_UKNOWN_LMP_PDU = 0x19;

        public const uint BTH_ERROR_UNSUPPORTED_REMOTE_FEATURE = 0x1a;

        public const uint BTH_ERROR_SCO_OFFSET_REJECTED = 0x1b;

        public const uint BTH_ERROR_SCO_INTERVAL_REJECTED = 0x1c;

        public const uint BTH_ERROR_SCO_AIRMODE_REJECTED = 0x1d;

        public const uint BTH_ERROR_INVALID_LMP_PARAMETERS = 0x1e;

        public const uint BTH_ERROR_UNSPECIFIED_ERROR = 0x1f;

        public const uint BTH_ERROR_UNSUPPORTED_LMP_PARM_VALUE = 0x20;

        public const uint BTH_ERROR_ROLE_CHANGE_NOT_ALLOWED = 0x21;

        public const uint BTH_ERROR_LMP_RESPONSE_TIMEOUT = 0x22;

        public const uint BTH_ERROR_LMP_TRANSACTION_COLLISION = 0x23;

        public const uint BTH_ERROR_LMP_PDU_NOT_ALLOWED = 0x24;

        public const uint BTH_ERROR_ENCRYPTION_MODE_NOT_ACCEPTABLE = 0x25;

        public const uint BTH_ERROR_UNIT_KEY_NOT_USED = 0x26;

        public const uint BTH_ERROR_QOS_IS_NOT_SUPPORTED = 0x27;

        public const uint BTH_ERROR_INSTANT_PASSED = 0x28;

        public const uint BTH_ERROR_PAIRING_WITH_UNIT_KEY_NOT_SUPPORTED = 0x29;

        public const uint BTH_ERROR_DIFFERENT_TRANSACTION_COLLISION = 0x2a;

        public const uint BTH_ERROR_QOS_UNACCEPTABLE_PARAMETER = 0x2c;

        public const uint BTH_ERROR_QOS_REJECTED = 0x2d;

        public const uint BTH_ERROR_CHANNEL_CLASSIFICATION_NOT_SUPPORTED = 0x2e;

        public const uint BTH_ERROR_INSUFFICIENT_SECURITY = 0x2f;

        public const uint BTH_ERROR_PARAMETER_OUT_OF_MANDATORY_RANGE = 0x30;

        public const uint BTH_ERROR_ROLE_SWITCH_PENDING = 0x32;

        public const uint BTH_ERROR_RESERVED_SLOT_VIOLATION = 0x34;

        public const uint BTH_ERROR_ROLE_SWITCH_FAILED = 0x35;

        public const uint BTH_ERROR_EXTENDED_INQUIRY_RESPONSE_TOO_LARGE = 0x36;

        public const uint BTH_ERROR_SECURE_SIMPLE_PAIRING_NOT_SUPPORTED_BY_HOST = 0x37;

        public const uint BTH_ERROR_HOST_BUSY_PAIRING = 0x38;

        public const uint BTH_ERROR_CONNECTION_REJECTED_DUE_TO_NO_SUITABLE_CHANNEL_FOUND = 0x39;

        public const uint BTH_ERROR_CONTROLLER_BUSY = 0x3a;

        public const uint BTH_ERROR_UNACCEPTABLE_CONNECTION_INTERVAL = 0x3b;

        public const uint BTH_ERROR_DIRECTED_ADVERTISING_TIMEOUT = 0x3c;

        public const uint BTH_ERROR_CONNECTION_TERMINATED_DUE_TO_MIC_FAILURE = 0x3d;

        public const uint BTH_ERROR_CONNECTION_FAILED_TO_BE_ESTABLISHED = 0x3e;

        public const uint BTH_ERROR_MAC_CONNECTION_FAILED = 0x3f;

        public const uint BTH_ERROR_COARSE_CLOCK_ADJUSTMENT_REJECTED = 0x40;

        public const uint BTH_ERROR_TYPE_0_SUBMAP_NOT_DEFINED = 0x41;

        public const uint BTH_ERROR_UNKNOWN_ADVERTISING_IDENTIFIER = 0x42;

        public const uint BTH_ERROR_LIMIT_REACHED = 0x43;

        public const uint BTH_ERROR_OPERATION_CANCELLED_BY_HOST = 0X44;

        public const uint BTH_ERROR_PACKET_TOO_LONG = 0x45;

        public const uint BTH_ERROR_UNSPECIFIED = 0xFF;

        public const uint L2CAP_MIN_MTU = 48;

        public const uint L2CAP_MAX_MTU = 0xFFFF;

        public const uint L2CAP_DEFAULT_MTU = 672;

        public const uint MAX_L2CAP_PING_DATA_LENGTH = 44;

        public const uint MAX_L2CAP_INFO_DATA_LENGTH = 44;

        public const uint BDIF_ADDRESS = 0x00000001;

        public const uint BDIF_COD = 0x00000002;

        public const uint BDIF_NAME = 0x00000004;

        public const uint BDIF_PAIRED = 0x00000008;

        public const uint BDIF_PERSONAL = 0x00000010;

        public const uint BDIF_CONNECTED = 0x00000020;

        public const uint BDIF_SHORT_NAME = 0x00000040;

        public const uint BDIF_VISIBLE = 0x00000080;

        public const uint BDIF_SSP_SUPPORTED = 0x00000100;

        public const uint BDIF_SSP_PAIRED = 0x00000200;

        public const uint BDIF_SSP_MITM_PROTECTED = 0x00000400;

        public const uint BDIF_RSSI = 0x00001000;

        public const uint BDIF_EIR = 0x00002000;

        public const uint BDIF_BR = 0x00004000;

        public const uint BDIF_LE = 0x00008000;

        public const uint BDIF_LE_PAIRED = 0x00010000;

        public const uint BDIF_LE_PERSONAL = 0x00020000;

        public const uint BDIF_LE_MITM_PROTECTED = 0x00040000;

        public const uint BDIF_LE_PRIVACY_ENABLED = 0x00080000;

        public const uint BDIF_LE_RANDOM_ADDRESS_TYPE = 0x00100000;

        public const uint BDIF_LE_DISCOVERABLE = 0x00200000;

        public const uint BDIF_LE_NAME = 0x00400000;

        public const uint BDIF_LE_VISIBLE = 0x00800000;

        public const uint BDIF_LE_CONNECTED = 0x01000000;

        public const uint BDIF_LE_CONNECTABLE = 0x02000000;

        public const uint BDIF_CONNECTION_INBOUND = 0x04000000;

        public const uint BDIF_BR_SECURE_CONNECTION_PAIRED = 0x08000000;

        public const uint BDIF_LE_SECURE_CONNECTION_PAIRED = 0x10000000;

        public const uint BDIF_DEBUGKEY = 0x20000000;

        public const uint BDIF_LE_DEBUGKEY = 0x40000000;

        public const uint BDIF_TX_POWER = 0x80000000;

        public const uint HCI_CONNECTION_TYPE_ACL = 1;

        public const uint HCI_CONNECTION_TYPE_SCO = 2;

        public const uint HCI_CONNECTION_TYPE_LE = 3;

        public const uint BTH_MAX_SERVICE_NAME_SIZE = 256;

        public const uint MAX_UUIDS_IN_QUERY = 12;

        public const uint BTH_VID_DEFAULT_VALUE = 0xFFFF;

        public const uint SDP_ERROR_INVALID_SDP_VERSION = 0x0001;

        public const uint SDP_ERROR_INVALID_RECORD_HANDLE = 0x0002;

        public const uint SDP_ERROR_INVALID_REQUEST_SYNTAX = 0x0003;

        public const uint SDP_ERROR_INVALID_PDU_SIZE = 0x0004;

        public const uint SDP_ERROR_INVALID_CONTINUATION_STATE = 0x0005;

        public const uint SDP_ERROR_INSUFFICIENT_RESOURCES = 0x0006;

        public const uint SDP_ATTRIB_RECORD_HANDLE = 0x0000;

        public const uint SDP_ATTRIB_CLASS_ID_LIST = 0x0001;

        public const uint SDP_ATTRIB_RECORD_STATE = 0x0002;

        public const uint SDP_ATTRIB_SERVICE_ID = 0x0003;

        public const uint SDP_ATTRIB_PROTOCOL_DESCRIPTOR_LIST = 0x0004;

        public const uint SDP_ATTRIB_BROWSE_GROUP_LIST = 0x0005;

        public const uint SDP_ATTRIB_LANG_BASE_ATTRIB_ID_LIST = 0x0006;

        public const uint SDP_ATTRIB_INFO_TIME_TO_LIVE = 0x0007;

        public const uint SDP_ATTRIB_AVAILABILITY = 0x0008;

        public const uint SDP_ATTRIB_PROFILE_DESCRIPTOR_LIST = 0x0009;

        public const uint SDP_ATTRIB_DOCUMENTATION_URL = 0x000A;

        public const uint SDP_ATTRIB_CLIENT_EXECUTABLE_URL = 0x000B;

        public const uint SDP_ATTRIB_ICON_URL = 0x000C;

        public const uint SDP_ATTRIB_ADDITIONAL_PROTOCOL_DESCRIPTOR_LIST = 0x000D;

        public const uint SDP_ATTRIB_PROFILE_SPECIFIC = 0x0200;

        public const uint LANG_BASE_LANGUAGE_INDEX = 0x0000;

        public const uint LANG_BASE_ENCODING_INDEX = 0x0001;

        public const uint LANG_BASE_OFFSET_INDEX = 0x0002;

        public const uint LANG_DEFAULT_ID = 0x0100;

        public const uint LANGUAGE_EN_US = 0x656E;

        public const uint ENCODING_UTF_8 = 0x006A;

        public const uint STRING_NAME_OFFSET = 0x0000;

        public const uint STRING_DESCRIPTION_OFFSET = 0x0001;

        public const uint STRING_PROVIDER_NAME_OFFSET = 0x0002;

        public const uint SDP_ATTRIB_SDP_VERSION_NUMBER_LIST = 0x0200;

        public const uint SDP_ATTRIB_SDP_DATABASE_STATE = 0x0201;

        public const uint SDP_ATTRIB_BROWSE_GROUP_ID = 0x0200;

        public const uint SDP_ATTRIB_CORDLESS_EXTERNAL_NETWORK = 0x0301;

        public const uint SDP_ATTRIB_FAX_CLASS_1_SUPPORT = 0x0302;

        public const uint SDP_ATTRIB_FAX_CLASS_2_0_SUPPORT = 0x0303;

        public const uint SDP_ATTRIB_FAX_CLASS_2_SUPPORT = 0x0304;

        public const uint SDP_ATTRIB_FAX_AUDIO_FEEDBACK_SUPPORT = 0x0305;

        public const uint SDP_ATTRIB_HEADSET_REMOTE_AUDIO_VOLUME_CONTROL = 0x0302;

        public const uint SDP_ATTRIB_LAN_LPSUBNET = 0x0200;

        public const uint SDP_ATTRIB_OBJECT_PUSH_SUPPORTED_FORMATS_LIST = 0x0303;

        public const uint SDP_ATTRIB_SYNCH_SUPPORTED_DATA_STORES_LIST = 0x0301;

        public const uint SDP_ATTRIB_SERVICE_VERSION = 0x0300;

        public const uint SDP_ATTRIB_PAN_NETWORK_ADDRESS = 0x0306;

        public const uint SDP_ATTRIB_PAN_WAP_GATEWAY = 0x0307;

        public const uint SDP_ATTRIB_PAN_HOME_PAGE_URL = 0x0308;

        public const uint SDP_ATTRIB_PAN_WAP_STACK_TYPE = 0x0309;

        public const uint SDP_ATTRIB_PAN_SECURITY_DESCRIPTION = 0x030A;

        public const uint SDP_ATTRIB_PAN_NET_ACCESS_TYPE = 0x030B;

        public const uint SDP_ATTRIB_PAN_MAX_NET_ACCESS_RATE = 0x030C;

        public const uint SDP_ATTRIB_IMAGING_SUPPORTED_CAPABILITIES = 0x0310;

        public const uint SDP_ATTRIB_IMAGING_SUPPORTED_FEATURES = 0x0311;

        public const uint SDP_ATTRIB_IMAGING_SUPPORTED_FUNCTIONS = 0x0312;

        public const uint SDP_ATTRIB_IMAGING_TOTAL_DATA_CAPACITY = 0x0313;

        public const uint SDP_ATTRIB_DI_SPECIFICATION_ID = 0x0200;

        public const uint SDP_ATTRIB_DI_VENDOR_ID = 0x0201;

        public const uint SDP_ATTRIB_DI_PRODUCT_ID = 0x0202;

        public const uint SDP_ATTRIB_DI_VERSION = 0x0203;

        public const uint SDP_ATTRIB_DI_PRIMARY_RECORD = 0x0204;

        public const uint SDP_ATTRIB_DI_VENDOR_ID_SOURCE = 0x0205;

        public const uint SDP_ATTRIB_HID_DEVICE_RELEASE_NUMBER = 0x0200;

        public const uint SDP_ATTRIB_HID_PARSER_VERSION = 0x0201;

        public const uint SDP_ATTRIB_HID_DEVICE_SUBCLASS = 0x0202;

        public const uint SDP_ATTRIB_HID_COUNTRY_CODE = 0x0203;

        public const uint SDP_ATTRIB_HID_VIRTUAL_CABLE = 0x0204;

        public const uint SDP_ATTRIB_HID_RECONNECT_INITIATE = 0x0205;

        public const uint SDP_ATTRIB_HID_DESCRIPTOR_LIST = 0x0206;

        public const uint SDP_ATTRIB_HID_LANG_ID_BASE_LIST = 0x0207;

        public const uint SDP_ATTRIB_HID_SDP_DISABLE = 0x0208;

        public const uint SDP_ATTRIB_HID_BATTERY_POWER = 0x0209;

        public const uint SDP_ATTRIB_HID_REMOTE_WAKE = 0x020A;

        public const uint SDP_ATTRIB_HID_PROFILE_VERSION = 0x020B;

        public const uint SDP_ATTRIB_HID_SUPERVISION_TIMEOUT = 0x020C;

        public const uint SDP_ATTRIB_HID_NORMALLY_CONNECTABLE = 0x020D;

        public const uint SDP_ATTRIB_HID_BOOT_DEVICE = 0x020E;

        public const uint SDP_ATTRIB_HID_SSR_HOST_MAX_LATENCY = 0x020F;

        public const uint SDP_ATTRIB_HID_SSR_HOST_MIN_TIMEOUT = 0x0210;

        public const uint SDP_ATTRIB_A2DP_SUPPORTED_FEATURES = 0x0311;

        public const uint SDP_ATTRIB_AVRCP_SUPPORTED_FEATURES = 0x0311;

        public const uint SDP_ATTRIB_HFP_SUPPORTED_FEATURES = 0x0311;

        public const uint AVRCP_SUPPORTED_FEATURES_CATEGORY_1 = 0x0001;

        public const uint AVRCP_SUPPORTED_FEATURES_CATEGORY_2 = 0x0002;

        public const uint AVRCP_SUPPORTED_FEATURES_CATEGORY_3 = 0x0004;

        public const uint AVRCP_SUPPORTED_FEATURES_CATEGORY_4 = 0x0008;

        public const uint AVRCP_SUPPORTED_FEATURES_CT_BROWSING = 0x0040;

        public const uint AVRCP_SUPPORTED_FEATURES_CT_COVER_ART_IMAGE_PROPERTIES = 0X0080;

        public const uint AVRCP_SUPPORTED_FEATURES_CT_COVER_ART_IMAGE = 0X0100;

        public const uint AVRCP_SUPPORTED_FEATURES_CT_COVER_ART_LINKED_THUMBNAIL = 0x0200;

        public const uint AVRCP_SUPPORTED_FEATURES_TG_PLAYER_APPLICATION_SETTINGS = 0x0010;

        public const uint AVRCP_SUPPORTED_FEATURES_TG_GROUP_NAVIGATION = 0x0020;

        public const uint AVRCP_SUPPORTED_FEATURES_TG_BROWSING = 0x0040;

        public const uint AVRCP_SUPPORTED_FEATURES_TG_MULTIPLE_PLAYER_APPLICATIONS = 0x0080;

        public const uint AVRCP_SUPPORTED_FEATURES_TG_COVER_ART = 0x0100;

        public const uint A2DP_SINK_SUPPORTED_FEATURES_HEADPHONE = 0x0001;

        public const uint A2DP_SINK_SUPPORTED_FEATURES_SPEAKER = 0x0002;

        public const uint A2DP_SINK_SUPPORTED_FEATURES_RECORDER = 0x0004;

        public const uint A2DP_SINK_SUPPORTED_FEATURES_AMPLIFIER = 0x0008;

        public const uint A2DP_SOURCE_SUPPORTED_FEATURES_PLAYER = 0x0001;

        public const uint A2DP_SOURCE_SUPPORTED_FEATURES_MICROPHONE = 0x0002;

        public const uint A2DP_SOURCE_SUPPORTED_FEATURES_TUNER = 0x0004;

        public const uint A2DP_SOURCE_SUPPORTED_FEATURES_MIXER = 0x0008;

        public const uint CORDLESS_EXTERNAL_NETWORK_PSTN = 0x01;

        public const uint CORDLESS_EXTERNAL_NETWORK_ISDN = 0x02;

        public const uint CORDLESS_EXTERNAL_NETWORK_GSM = 0x03;

        public const uint CORDLESS_EXTERNAL_NETWORK_CDMA = 0x04;

        public const uint CORDLESS_EXTERNAL_NETWORK_ANALOG_CELLULAR = 0x05;

        public const uint CORDLESS_EXTERNAL_NETWORK_PACKET_SWITCHED = 0x06;

        public const uint CORDLESS_EXTERNAL_NETWORK_OTHER = 0x07;

        public const uint OBJECT_PUSH_FORMAT_VCARD_2_1 = 0x01;

        public const uint OBJECT_PUSH_FORMAT_VCARD_3_0 = 0x02;

        public const uint OBJECT_PUSH_FORMAT_VCAL_1_0 = 0x03;

        public const uint OBJECT_PUSH_FORMAT_ICAL_2_0 = 0x04;

        public const uint OBJECT_PUSH_FORMAT_VNOTE = 0x05;

        public const uint OBJECT_PUSH_FORMAT_VMESSAGE = 0x06;

        public const uint OBJECT_PUSH_FORMAT_ANY = 0xFF;

        public const uint SYNCH_DATA_STORE_PHONEBOOK = 0x01;

        public const uint SYNCH_DATA_STORE_CALENDAR = 0x03;

        public const uint SYNCH_DATA_STORE_NOTES = 0x05;

        public const uint SYNCH_DATA_STORE_MESSAGES = 0x06;

        public const uint DI_VENDOR_ID_SOURCE_BLUETOOTH_SIG = 0x0001;

        public const uint DI_VENDOR_ID_SOURCE_USB_IF = 0x0002;

        public const uint PSM_SDP = 0x0001;

        public const uint PSM_RFCOMM = 0x0003;

        public const uint PSM_TCS_BIN = 0x0005;

        public const uint PSM_TCS_BIN_CORDLESS = 0x0007;

        public const uint PSM_BNEP = 0x000F;

        public const uint PSM_HID_CONTROL = 0x0011;

        public const uint PSM_HID_INTERRUPT = 0x0013;

        public const uint PSM_UPNP = 0x0015;

        public const uint PSM_AVCTP = 0x0017;

        public const uint PSM_AVDTP = 0x0019;

        public const uint PSM_AVCTP_BROWSE = 0x001B;

        public const uint PSM_UDI_C_PLANE = 0x001D;

        public const uint PSM_ATT = 0x001F;

        public const uint PSM_3DSP = 0x0021;

        public const uint PSM_LE_IPSP = 0x0023;

    }
}
