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


namespace Windows.Win32.Storage.IscsiDisc
{
    public static partial class Apis
    {
        public static readonly Guid ScsiRawInterfaceGuid__scanned__ = new Guid(0x53f56309L, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public static readonly Guid WmiScsiAddressGuid__scanned__ = new Guid(0x53f5630fL, 0xb6bf, 0x11d0, 0x94, 0xf2, 0x00, 0xa0, 0xc9, 0x1e, 0xfb, 0x8b);

        public const uint FILE_DEVICE_SCSI = 0x0000001b;

        public const uint IOCTL_SCSI_PASS_THROUGH = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0401) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_MINIPORT = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0402) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_GET_INQUIRY_DATA = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0403) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_GET_CAPABILITIES = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0404) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_PASS_THROUGH_DIRECT = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0405) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_GET_ADDRESS = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0406) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_RESCAN_BUS = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0407) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_GET_DUMP_POINTERS = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0408) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_FREE_DUMP_POINTERS = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0409) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_IDE_PASS_THROUGH = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040a) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_ATA_PASS_THROUGH = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040b) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_ATA_PASS_THROUGH_DIRECT = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040c) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_ATA_MINIPORT = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040d) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MINIPORT_PROCESS_SERVICE_IRP = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040e) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MPIO_PASS_THROUGH_PATH = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x040f) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0410) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_PASS_THROUGH_EX = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0411) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SCSI_PASS_THROUGH_DIRECT_EX = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0412) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MPIO_PASS_THROUGH_PATH_EX = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0413) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT_EX = ((IOCTL_SCSI_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((0x0414) << 2) | (METHOD_BUFFERED);

        public const uint ATA_FLAGS_DRDY_REQUIRED = 1u<< 0;

        public const uint ATA_FLAGS_DATA_IN = 1u<< 1;

        public const uint ATA_FLAGS_DATA_OUT = 1u<< 2;

        public const uint ATA_FLAGS_48BIT_COMMAND = 1u<< 3;

        public const uint ATA_FLAGS_USE_DMA = 1u<< 4;

        public const uint ATA_FLAGS_NO_MULTIPLE = 1u<< 5;

        public const uint NRB_FUNCTION_NVCACHE_INFO = 0xEC;

        public const uint NRB_FUNCTION_SPINDLE_STATUS = 0xE5;

        public const uint NRB_FUNCTION_NVCACHE_POWER_MODE_SET = 0x00;

        public const uint NRB_FUNCTION_NVCACHE_POWER_MODE_RETURN = 0x01;

        public const uint NRB_FUNCTION_FLUSH_NVCACHE = 0x14;

        public const uint NRB_FUNCTION_QUERY_PINNED_SET = 0x12;

        public const uint NRB_FUNCTION_QUERY_CACHE_MISS = 0x13;

        public const uint NRB_FUNCTION_ADD_LBAS_PINNED_SET = 0x10;

        public const uint NRB_FUNCTION_REMOVE_LBAS_PINNED_SET = 0x11;

        public const uint NRB_FUNCTION_QUERY_ASCENDER_STATUS = 0xD0;

        public const uint NRB_FUNCTION_QUERY_HYBRID_DISK_STATUS = 0xD1;

        public const uint NRB_FUNCTION_PASS_HINT_PAYLOAD = 0xE0;

        public const uint NRB_FUNCTION_NVSEPARATED_INFO = 0xc0;

        public const uint NRB_FUNCTION_NVSEPARATED_FLUSH = 0xc1;

        public const uint NRB_FUNCTION_NVSEPARATED_WB_DISABLE = 0xc2;

        public const uint NRB_FUNCTION_NVSEPARATED_WB_REVERT_DEFAULT = 0xc3;

        public const uint NRB_SUCCESS = 0;

        public const uint NRB_ILLEGAL_REQUEST = 1;

        public const uint NRB_INVALID_PARAMETER = 2;

        public const uint NRB_INPUT_DATA_OVERRUN = 3;

        public const uint NRB_INPUT_DATA_UNDERRUN = 4;

        public const uint NRB_OUTPUT_DATA_OVERRUN = 5;

        public const uint NRB_OUTPUT_DATA_UNDERRUN = 6;

        public const uint NV_SEP_CACHE_PARAMETER_VERSION_1 = 1;

        public const uint STORAGE_DIAGNOSTIC_STATUS_SUCCESS = 0;

        public const uint STORAGE_DIAGNOSTIC_STATUS_BUFFER_TOO_SMALL = 0x1;

        public const uint STORAGE_DIAGNOSTIC_STATUS_UNSUPPORTED_VERSION = 0x2;

        public const uint STORAGE_DIAGNOSTIC_STATUS_INVALID_PARAMETER = 0x3;

        public const uint STORAGE_DIAGNOSTIC_STATUS_INVALID_SIGNATURE = 0x4;

        public const uint STORAGE_DIAGNOSTIC_STATUS_INVALID_TARGET_TYPE = 0x5;

        public const uint STORAGE_DIAGNOSTIC_STATUS_MORE_DATA = 0x6;

        public const uint MINIPORT_DSM_NOTIFICATION_VERSION_1 = 1;

        public const uint MINIPORT_DSM_PROFILE_UNKNOWN = 0;

        public const uint MINIPORT_DSM_PROFILE_PAGE_FILE = 1;

        public const uint MINIPORT_DSM_PROFILE_HIBERNATION_FILE = 2;

        public const uint MINIPORT_DSM_PROFILE_CRASHDUMP_FILE = 3;

        public const uint MINIPORT_DSM_NOTIFY_FLAG_BEGIN = 0x00000001;

        public const uint MINIPORT_DSM_NOTIFY_FLAG_END = 0x00000002;

        public const uint HYBRID_FUNCTION_GET_INFO = 0x01;

        public const uint HYBRID_FUNCTION_DISABLE_CACHING_MEDIUM = 0x10;

        public const uint HYBRID_FUNCTION_ENABLE_CACHING_MEDIUM = 0x11;

        public const uint HYBRID_FUNCTION_SET_DIRTY_THRESHOLD = 0x12;

        public const uint HYBRID_FUNCTION_DEMOTE_BY_SIZE = 0x13;

        public const uint HYBRID_STATUS_SUCCESS = 0x0;

        public const uint HYBRID_STATUS_ILLEGAL_REQUEST = 0x1;

        public const uint HYBRID_STATUS_INVALID_PARAMETER = 0x2;

        public const uint HYBRID_STATUS_OUTPUT_BUFFER_TOO_SMALL = 0x3;

        public const uint HYBRID_STATUS_ENABLE_REFCOUNT_HOLD = 0x10;

        public const uint HYBRID_REQUEST_BLOCK_STRUCTURE_VERSION = 0x1;

        public const uint HYBRID_REQUEST_INFO_STRUCTURE_VERSION = 0x1;

        public const uint FIRMWARE_FUNCTION_GET_INFO = 0x01;

        public const uint FIRMWARE_FUNCTION_DOWNLOAD = 0x02;

        public const uint FIRMWARE_FUNCTION_ACTIVATE = 0x03;

        public const uint FIRMWARE_STATUS_SUCCESS = 0x0;

        public const uint FIRMWARE_STATUS_ERROR = 0x1;

        public const uint FIRMWARE_STATUS_ILLEGAL_REQUEST = 0x2;

        public const uint FIRMWARE_STATUS_INVALID_PARAMETER = 0x3;

        public const uint FIRMWARE_STATUS_INPUT_BUFFER_TOO_BIG = 0x4;

        public const uint FIRMWARE_STATUS_OUTPUT_BUFFER_TOO_SMALL = 0x5;

        public const uint FIRMWARE_STATUS_INVALID_SLOT = 0x6;

        public const uint FIRMWARE_STATUS_INVALID_IMAGE = 0x7;

        public const uint FIRMWARE_STATUS_CONTROLLER_ERROR = 0x10;

        public const uint FIRMWARE_STATUS_POWER_CYCLE_REQUIRED = 0x20;

        public const uint FIRMWARE_STATUS_DEVICE_ERROR = 0x40;

        public const uint FIRMWARE_STATUS_INTERFACE_CRC_ERROR = 0x80;

        public const uint FIRMWARE_STATUS_UNCORRECTABLE_DATA_ERROR = 0x81;

        public const uint FIRMWARE_STATUS_MEDIA_CHANGE = 0x82;

        public const uint FIRMWARE_STATUS_ID_NOT_FOUND = 0x83;

        public const uint FIRMWARE_STATUS_MEDIA_CHANGE_REQUEST = 0x84;

        public const uint FIRMWARE_STATUS_COMMAND_ABORT = 0x85;

        public const uint FIRMWARE_STATUS_END_OF_MEDIA = 0x86;

        public const uint FIRMWARE_STATUS_ILLEGAL_LENGTH = 0x87;

        public const uint FIRMWARE_REQUEST_BLOCK_STRUCTURE_VERSION = 0x1;

        public const uint FIRMWARE_REQUEST_FLAG_CONTROLLER = 0x00000001;

        public const uint FIRMWARE_REQUEST_FLAG_LAST_SEGMENT = 0x00000002;

        public const uint FIRMWARE_REQUEST_FLAG_FIRST_SEGMENT = 0x00000004;

        public const uint FIRMWARE_REQUEST_FLAG_SWITCH_TO_EXISTING_FIRMWARE = 0x80000000;

        public const uint STORAGE_FIRMWARE_INFO_STRUCTURE_VERSION = 0x1;

        public const uint STORAGE_FIRMWARE_INFO_STRUCTURE_VERSION_V2 = 0x2;

        public const uint STORAGE_FIRMWARE_INFO_INVALID_SLOT = 0xFF;

        public const uint STORAGE_FIRMWARE_SLOT_INFO_V2_REVISION_LENGTH = 16;

        public const uint STORAGE_FIRMWARE_DOWNLOAD_STRUCTURE_VERSION = 0x1;

        public const uint STORAGE_FIRMWARE_DOWNLOAD_STRUCTURE_VERSION_V2 = 0x2;

        public const uint STORAGE_FIRMWARE_ACTIVATE_STRUCTURE_VERSION = 0x1;

        public const uint DUMP_POINTERS_VERSION_1 = 1;

        public const uint DUMP_POINTERS_VERSION_2 = 2;

        public const uint DUMP_POINTERS_VERSION_3 = 3;

        public const uint DUMP_POINTERS_VERSION_4 = 4;

        public const uint DUMP_DRIVER_NAME_LENGTH = 15;

        public const uint DUMP_EX_FLAG_SUPPORT_64BITMEMORY = 0x00000001;

        public const uint DUMP_EX_FLAG_SUPPORT_DD_TELEMETRY = 0x00000002;

        public const uint DUMP_EX_FLAG_RESUME_SUPPORT = 0x00000004;

        public const uint DUMP_EX_FLAG_DRIVER_FULL_PATH_SUPPORT = 0x00000008;

        public const uint SCSI_IOCTL_DATA_OUT = 0;

        public const uint SCSI_IOCTL_DATA_IN = 1;

        public const uint SCSI_IOCTL_DATA_UNSPECIFIED = 2;

        public const uint SCSI_IOCTL_DATA_BIDIRECTIONAL = 3;

        public const uint MPIO_IOCTL_FLAG_USE_PATHID = 1;

        public const uint MPIO_IOCTL_FLAG_USE_SCSIADDRESS = 2;

        public const uint MPIO_IOCTL_FLAG_INVOLVE_DSM = 4;

        public const uint MAX_ISCSI_HBANAME_LEN = 256;

        public const uint MAX_ISCSI_NAME_LEN = 223;

        public const uint MAX_ISCSI_ALIAS_LEN = 255;

        public const uint MAX_ISCSI_PORTAL_NAME_LEN = 256;

        public const uint MAX_ISCSI_PORTAL_ALIAS_LEN = 256;

        public const uint MAX_ISCSI_TEXT_ADDRESS_LEN = 256;

        public const uint MAX_ISCSI_DISCOVERY_DOMAIN_LEN = 256;

        public const uint MAX_RADIUS_ADDRESS_LEN = 41;

        public const uint ISCSI_SECURITY_FLAG_TUNNEL_MODE_PREFERRED = 0x00000040;

        public const uint ISCSI_SECURITY_FLAG_TRANSPORT_MODE_PREFERRED = 0x00000020;

        public const uint ISCSI_SECURITY_FLAG_PFS_ENABLED = 0x00000010;

        public const uint ISCSI_SECURITY_FLAG_AGGRESSIVE_MODE_ENABLED = 0x00000008;

        public const uint ISCSI_SECURITY_FLAG_MAIN_MODE_ENABLED = 0x00000004;

        public const uint ISCSI_SECURITY_FLAG_IKE_IPSEC_ENABLED = 0x00000002;

        public const uint ISCSI_SECURITY_FLAG_VALID = 0x00000001;

        public const uint ISCSI_LOGIN_FLAG_REQUIRE_IPSEC = 0x00000001;

        public const uint ISCSI_LOGIN_FLAG_MULTIPATH_ENABLED = 0x00000002;

        public const uint ISCSI_LOGIN_FLAG_RESERVED1 = 0x00000004;

        public const uint ISCSI_LOGIN_FLAG_ALLOW_PORTAL_HOPPING = 0x00000008;

        public const uint ISCSI_LOGIN_FLAG_USE_RADIUS_RESPONSE = 0x00000010;

        public const uint ISCSI_LOGIN_FLAG_USE_RADIUS_VERIFICATION = 0x00000020;

        public const uint ISCSI_LOGIN_OPTIONS_HEADER_DIGEST = 0x00000001;

        public const uint ISCSI_LOGIN_OPTIONS_DATA_DIGEST = 0x00000002;

        public const uint ISCSI_LOGIN_OPTIONS_MAXIMUM_CONNECTIONS = 0x00000004;

        public const uint ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_WAIT = 0x00000008;

        public const uint ISCSI_LOGIN_OPTIONS_DEFAULT_TIME_2_RETAIN = 0x00000010;

        public const uint ISCSI_LOGIN_OPTIONS_USERNAME = 0x00000020;

        public const uint ISCSI_LOGIN_OPTIONS_PASSWORD = 0x00000040;

        public const uint ISCSI_LOGIN_OPTIONS_AUTH_TYPE = 0x00000080;

        public const uint ISCSI_LOGIN_OPTIONS_VERSION = 0;

        public const uint ISCSI_TARGET_FLAG_HIDE_STATIC_TARGET = 0x00000002;

        public const uint ISCSI_TARGET_FLAG_MERGE_TARGET_INFORMATION = 0x00000004;

        public const uint ID_IPV4_ADDR = 1;

        public const uint ID_FQDN = 2;

        public const uint ID_USER_FQDN = 3;

        public const uint ID_IPV6_ADDR = 5;

    }
}
