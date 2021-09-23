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


namespace Windows.Win32.Storage.FileSystem
{
    public static partial class Apis
    {
        public const uint CLFS_FLAG_REENTRANT_FILE_SYSTEM = 0x00000008;

        public const uint CLFS_FLAG_NON_REENTRANT_FILTER = 0x00000010;

        public const uint CLFS_FLAG_REENTRANT_FILTER = 0x00000020;

        public const uint CLFS_FLAG_IGNORE_SHARE_ACCESS = 0x00000040;

        public const uint CLFS_FLAG_READ_IN_PROGRESS = 0x00000080;

        public const uint CLFS_FLAG_MINIFILTER_LEVEL = 0x00000100;

        public const uint CLFS_FLAG_HIDDEN_SYSTEM_LOG = 0x00000200;

        public const uint CLFS_MARSHALLING_FLAG_NONE = 0x00000000;

        public const uint CLFS_MARSHALLING_FLAG_DISABLE_BUFF_INIT = 0x00000001;

        public const uint TRANSACTION_MANAGER_VOLATILE = 0x00000001;

        public const uint TRANSACTION_MANAGER_COMMIT_DEFAULT = 0x00000000;

        public const uint TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME = 0x00000002;

        public const uint TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES = 0x00000004;

        public const uint TRANSACTION_MANAGER_COMMIT_LOWEST = 0x00000008;

        public const uint TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY = 0x00000010;

        public const uint TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS = 0x00000020;

        public const uint TRANSACTION_MANAGER_MAXIMUM_OPTION = 0x0000003F;

        public const uint TRANSACTION_DO_NOT_PROMOTE = 0x00000001;

        public const uint TRANSACTION_MAXIMUM_OPTION = 0x00000001;

        public const uint RESOURCE_MANAGER_VOLATILE = 0x00000001;

        public const uint RESOURCE_MANAGER_COMMUNICATION = 0x00000002;

        public const uint RESOURCE_MANAGER_MAXIMUM_OPTION = 0x00000003;

        public const uint CRM_PROTOCOL_EXPLICIT_MARSHAL_ONLY = 0x00000001;

        public const uint CRM_PROTOCOL_DYNAMIC_MARSHAL_INFO = 0x00000002;

        public const uint CRM_PROTOCOL_MAXIMUM_OPTION = 0x00000003;

        public const uint ENLISTMENT_SUPERIOR = 0x00000001;

        public const uint ENLISTMENT_MAXIMUM_OPTION = 0x00000001;

        public const uint TRANSACTION_NOTIFY_MASK = 0x3FFFFFFF;

        public const uint TRANSACTION_NOTIFY_PREPREPARE = 0x00000001;

        public const uint TRANSACTION_NOTIFY_PREPARE = 0x00000002;

        public const uint TRANSACTION_NOTIFY_COMMIT = 0x00000004;

        public const uint TRANSACTION_NOTIFY_ROLLBACK = 0x00000008;

        public const uint TRANSACTION_NOTIFY_PREPREPARE_COMPLETE = 0x00000010;

        public const uint TRANSACTION_NOTIFY_PREPARE_COMPLETE = 0x00000020;

        public const uint TRANSACTION_NOTIFY_COMMIT_COMPLETE = 0x00000040;

        public const uint TRANSACTION_NOTIFY_ROLLBACK_COMPLETE = 0x00000080;

        public const uint TRANSACTION_NOTIFY_RECOVER = 0x00000100;

        public const uint TRANSACTION_NOTIFY_SINGLE_PHASE_COMMIT = 0x00000200;

        public const uint TRANSACTION_NOTIFY_DELEGATE_COMMIT = 0x00000400;

        public const uint TRANSACTION_NOTIFY_RECOVER_QUERY = 0x00000800;

        public const uint TRANSACTION_NOTIFY_ENLIST_PREPREPARE = 0x00001000;

        public const uint TRANSACTION_NOTIFY_LAST_RECOVER = 0x00002000;

        public const uint TRANSACTION_NOTIFY_INDOUBT = 0x00004000;

        public const uint TRANSACTION_NOTIFY_PROPAGATE_PULL = 0x00008000;

        public const uint TRANSACTION_NOTIFY_PROPAGATE_PUSH = 0x00010000;

        public const uint TRANSACTION_NOTIFY_MARSHAL = 0x00020000;

        public const uint TRANSACTION_NOTIFY_ENLIST_MASK = 0x00040000;

        public const uint TRANSACTION_NOTIFY_RM_DISCONNECTED = 0x01000000;

        public const uint TRANSACTION_NOTIFY_TM_ONLINE = 0x02000000;

        public const uint TRANSACTION_NOTIFY_COMMIT_REQUEST = 0x04000000;

        public const uint TRANSACTION_NOTIFY_PROMOTE = 0x08000000;

        public const uint TRANSACTION_NOTIFY_PROMOTE_NEW = 0x10000000;

        public const uint TRANSACTION_NOTIFY_REQUEST_OUTCOME = 0x20000000;

        public const uint TRANSACTION_NOTIFY_COMMIT_FINALIZE = 0x40000000;

        public const uint TRANSACTION_NOTIFICATION_TM_ONLINE_FLAG_IS_CLUSTERED = 0x1;

        public const uint KTM_MARSHAL_BLOB_VERSION_MAJOR = 1;

        public const uint KTM_MARSHAL_BLOB_VERSION_MINOR = 1;

        public const uint MAX_TRANSACTION_DESCRIPTION_LENGTH = 64;

        public const uint MAX_RESOURCEMANAGER_DESCRIPTION_LENGTH = 64;

        public const uint IOCTL_VOLUME_SUPPORTS_ONLINE_OFFLINE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((1) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_IS_OFFLINE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((4) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_IS_IO_CAPABLE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((5) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_QUERY_FAILOVER_SET = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((6) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_QUERY_VOLUME_NUMBER = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((7) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_LOGICAL_TO_PHYSICAL = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((8) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_PHYSICAL_TO_LOGICAL = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((9) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_IS_PARTITION = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((10) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_READ_PLEX = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((11) << 2) | (METHOD_OUT_DIRECT);

        public const uint IOCTL_VOLUME_SET_GPT_ATTRIBUTES = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((13) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_GET_BC_PROPERTIES = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((15) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_ALLOCATE_BC_STREAM = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((16) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_FREE_BC_STREAM = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((17) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_BC_VERSION = 1;

        public const uint IOCTL_VOLUME_IS_DYNAMIC = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((18) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_PREPARE_FOR_CRITICAL_IO = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((19) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_QUERY_ALLOCATION_HINT = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((20) << 2) | (METHOD_OUT_DIRECT);

        public const uint IOCTL_VOLUME_UPDATE_PROPERTIES = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((21) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_QUERY_MINIMUM_SHRINK_SIZE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS)) << 14) | ((22) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_PREPARE_FOR_SHRINK = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((23) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_IS_CSV = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((24) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_POST_ONLINE = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((25) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VOLUME_GET_CSVBLOCKCACHE_CALLBACK = ((IOCTL_VOLUME_BASE) << 16) | (uint)(((int)(FILE_READ_ACCESS | FILE_WRITE_ACCESS)) << 14) | ((26) << 2) | (METHOD_BUFFERED);

        public const uint CSV_BLOCK_CACHE_CALLBACK_VERSION = 01;

        public const uint CSV_BLOCK_AND_FILE_CACHE_CALLBACK_VERSION = 02;

        public const uint CLFS_MGMT_POLICY_VERSION = 0x01;

        public const uint LOG_POLICY_OVERWRITE = 0x01;

        public const uint LOG_POLICY_PERSIST = 0x02;

        public const uint CLFS_MGMT_CLIENT_REGISTRATION_VERSION = 0x1;

        public static readonly Guid CLSID_DiskQuotaControl__scanned__ = new Guid(0x7988b571, 0xec89, 0x11cf, 0x9c, 0x0, 0x0, 0xaa, 0x0, 0xa1, 0x4f, 0x56);

        public const uint DISKQUOTA_STATE_DISABLED = 0x00000000;

        public const uint DISKQUOTA_STATE_TRACK = 0x00000001;

        public const uint DISKQUOTA_STATE_ENFORCE = 0x00000002;

        public const uint DISKQUOTA_STATE_MASK = 0x00000003;

        public const uint DISKQUOTA_FILESTATE_INCOMPLETE = 0x00000100;

        public const uint DISKQUOTA_FILESTATE_REBUILDING = 0x00000200;

        public const uint DISKQUOTA_FILESTATE_MASK = 0x00000300;

        public const uint DISKQUOTA_LOGFLAG_USER_THRESHOLD = 0x00000001;

        public const uint DISKQUOTA_LOGFLAG_USER_LIMIT = 0x00000002;

        public const uint DISKQUOTA_USER_ACCOUNT_RESOLVED = 0;

        public const uint DISKQUOTA_USER_ACCOUNT_UNAVAILABLE = 1;

        public const uint DISKQUOTA_USER_ACCOUNT_DELETED = 2;

        public const uint DISKQUOTA_USER_ACCOUNT_INVALID = 3;

        public const uint DISKQUOTA_USER_ACCOUNT_UNKNOWN = 4;

        public const uint DISKQUOTA_USER_ACCOUNT_UNRESOLVED = 5;

        public const uint INVALID_SET_FILE_POINTER = 0xFFFFFFFF;

        public const uint INVALID_FILE_ATTRIBUTES = 0xFFFFFFFF;

        public const uint SHARE_NETNAME_PARMNUM = 1;

        public const uint SHARE_TYPE_PARMNUM = 3;

        public const uint SHARE_REMARK_PARMNUM = 4;

        public const uint SHARE_PERMISSIONS_PARMNUM = 5;

        public const uint SHARE_MAX_USES_PARMNUM = 6;

        public const uint SHARE_CURRENT_USES_PARMNUM = 7;

        public const uint SHARE_PATH_PARMNUM = 8;

        public const uint SHARE_PASSWD_PARMNUM = 9;

        public const uint SHARE_FILE_SD_PARMNUM = 501;

        public const uint SHARE_SERVER_PARMNUM = 503;

        public const uint SHI1_NUM_ELEMENTS = 4;

        public const uint SHI2_NUM_ELEMENTS = 10;

        public const uint STYPE_RESERVED1 = 0x01000000;

        public const uint STYPE_RESERVED2 = 0x02000000;

        public const uint STYPE_RESERVED3 = 0x04000000;

        public const uint STYPE_RESERVED4 = 0x08000000;

        public const uint STYPE_RESERVED5 = 0x00100000;

        public const uint STYPE_RESERVED_ALL = 0x3FFFFF00;

        public const uint SHI_USES_UNLIMITED = 0xFFFFFFFF;

        public const uint SHI1005_FLAGS_DFS = 0x0001;

        public const uint SHI1005_FLAGS_DFS_ROOT = 0x0002;

        public const uint CSC_MASK_EXT = 0x2030;

        public const uint CSC_MASK = 0x0030;

        public const uint CSC_CACHE_MANUAL_REINT = 0x0000;

        public const uint CSC_CACHE_AUTO_REINT = 0x0010;

        public const uint CSC_CACHE_VDO = 0x0020;

        public const uint CSC_CACHE_NONE = 0x0030;

        public const uint SHI1005_FLAGS_RESTRICT_EXCLUSIVE_OPENS = 0x00100;

        public const uint SHI1005_FLAGS_FORCE_SHARED_DELETE = 0x00200;

        public const uint SHI1005_FLAGS_ALLOW_NAMESPACE_CACHING = 0x00400;

        public const uint SHI1005_FLAGS_ACCESS_BASED_DIRECTORY_ENUM = 0x00800;

        public const uint SHI1005_FLAGS_FORCE_LEVELII_OPLOCK = 0x01000;

        public const uint SHI1005_FLAGS_ENABLE_HASH = 0x02000;

        public const uint SHI1005_FLAGS_ENABLE_CA = 0x04000;

        public const uint SHI1005_FLAGS_ENCRYPT_DATA = 0x08000;

        public const uint SHI1005_FLAGS_RESERVED = 0x10000;

        public const uint SHI1005_FLAGS_DISABLE_CLIENT_BUFFERING = 0x20000;

        public const uint SHI1005_FLAGS_IDENTITY_REMOTING = 0x40000;

        public const uint SHI1005_FLAGS_CLUSTER_MANAGED = 0x80000;

        public const uint SESI1_NUM_ELEMENTS = 8;

        public const uint SESI2_NUM_ELEMENTS = 9;

        public const uint STATSOPT_CLR = 1;

        public const int LZERROR_BADINHANDLE = -1;

        public const int LZERROR_BADOUTHANDLE = -2;

        public const int LZERROR_READ = -3;

        public const int LZERROR_WRITE = -4;

        public const int LZERROR_GLOBALLOC = -5;

        public const int LZERROR_GLOBLOCK = -6;

        public const int LZERROR_BADVALUE = -7;

        public const int LZERROR_UNKNOWNALG = -8;

        public const uint NTMS_OBJECTNAME_LENGTH = 64;

        public const uint NTMS_DESCRIPTION_LENGTH = 127;

        public const uint NTMS_DEVICENAME_LENGTH = 64;

        public const uint NTMS_SERIALNUMBER_LENGTH = 32;

        public const uint NTMS_REVISION_LENGTH = 32;

        public const uint NTMS_BARCODE_LENGTH = 64;

        public const uint NTMS_SEQUENCE_LENGTH = 32;

        public const uint NTMS_VENDORNAME_LENGTH = 128;

        public const uint NTMS_PRODUCTNAME_LENGTH = 128;

        public const uint NTMS_USERNAME_LENGTH = 64;

        public const uint NTMS_APPLICATIONNAME_LENGTH = 64;

        public const uint NTMS_COMPUTERNAME_LENGTH = 64;

        public const uint NTMS_I1_MESSAGE_LENGTH = 127;

        public const uint NTMS_MESSAGE_LENGTH = 256;

        public const uint NTMS_POOLHIERARCHY_LENGTH = 512;

        public const uint NTMS_OMIDLABELID_LENGTH = 255;

        public const uint NTMS_OMIDLABELTYPE_LENGTH = 64;

        public const uint NTMS_OMIDLABELINFO_LENGTH = 256;

        public const uint NTMS_MAXATTR_LENGTH = 0x10000;

        public const uint NTMS_MAXATTR_NAMELEN = 32;

        public const uint NTMSMLI_MAXTYPE = 64;

        public const uint NTMSMLI_MAXIDSIZE = 256;

        public const uint NTMSMLI_MAXAPPDESCR = 256;

        public const uint TXF_LOG_RECORD_GENERIC_TYPE_COMMIT = 0x01;

        public const uint TXF_LOG_RECORD_GENERIC_TYPE_ABORT = 0x02;

        public const uint TXF_LOG_RECORD_GENERIC_TYPE_PREPARE = 0x04;

        public const uint TXF_LOG_RECORD_GENERIC_TYPE_DATA = 0x08;

        public const uint VS_VERSION_INFO = 1;

        public const uint VS_USER_DEFINED = 100;

        public const int VS_FFI_SIGNATURE = unchecked((int)0xFEEF04BD);

        public const int VS_FFI_STRUCVERSION = 0x00010000;

        public const int VS_FFI_FILEFLAGSMASK = 0x0000003F;

        public const uint WINEFS_SETUSERKEY_SET_CAPABILITIES = 0x00000001;

        public const uint EFS_COMPATIBILITY_VERSION_NCRYPT_PROTECTOR = 5;

        public const uint EFS_COMPATIBILITY_VERSION_PFILE_PROTECTOR = 6;

        public const uint EFS_SUBVER_UNKNOWN = 0;

        public const uint EFS_EFS_SUBVER_EFS_CERT = 1;

        public const uint EFS_PFILE_SUBVER_RMS = 2;

        public const uint EFS_PFILE_SUBVER_APPX = 3;

        public const uint MAX_SID_SIZE = 256;

        public const uint EFS_METADATA_ADD_USER = 0x00000001;

        public const uint EFS_METADATA_REMOVE_USER = 0x00000002;

        public const uint EFS_METADATA_REPLACE_USER = 0x00000004;

        public const uint EFS_METADATA_GENERAL_OP = 0x00000008;

        public const uint WIM_ENTRY_FLAG_NOT_ACTIVE = 0x00000001;

        public const uint WIM_ENTRY_FLAG_SUSPENDED = 0x00000002;

    }
}
