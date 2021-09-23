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


using static Windows.Win32.Storage.FileSystem.Apis;

namespace Windows.Win32.Storage.FileSystem
{
    [Flags]
    public enum GPT_ATTRIBUTES : ulong
    {
        GPT_ATTRIBUTE_PLATFORM_REQUIRED = 1,
        GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER = 9223372036854775808,
        GPT_BASIC_DATA_ATTRIBUTE_HIDDEN = 4611686018427387904,
        GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY = 2305843009213693952,
        GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY = 1152921504606846976,
    }

    [Flags]
    public enum GET_FILE_VERSION_INFO_FLAGS : uint
    {
        FILE_VER_GET_LOCALISED = 0x01,
        FILE_VER_GET_NEUTRAL = 0x02,
        FILE_VER_GET_PREFETCHED = 0x04,
    }

    public enum VER_FIND_FILE_FLAGS : uint
    {
        VFFF_ISSHAREDFILE = 0x0001,
    }

    [Flags]
    public enum VER_FIND_FILE_STATUS : uint
    {
        VFF_CURNEDEST = 0x0001,
        VFF_FILEINUSE = 0x0002,
        VFF_BUFFTOOSMALL = 0x0004,
    }

    public enum VER_INSTALL_FILE_FLAGS : uint
    {
        VIFF_FORCEINSTALL = 0x0001,
        VIFF_DONTDELETEOLD = 0x0002,
    }

    [Flags]
    public enum VER_INSTALL_FILE_STATUS : uint
    {
        VIF_TEMPFILE = 0x00000001,
        VIF_MISMATCH = 0x00000002,
        VIF_SRCOLD = 0x00000004,
        VIF_DIFFLANG = 0x00000008,
        VIF_DIFFCODEPG = 0x00000010,
        VIF_DIFFTYPE = 0x00000020,
        VIF_WRITEPROT = 0x00000040,
        VIF_FILEINUSE = 0x00000080,
        VIF_OUTOFSPACE = 0x00000100,
        VIF_ACCESSVIOLATION = 0x00000200,
        VIF_SHARINGVIOLATION = 0x00000400,
        VIF_CANNOTCREATE = 0x00000800,
        VIF_CANNOTDELETE = 0x00001000,
        VIF_CANNOTRENAME = 0x00002000,
        VIF_CANNOTDELETECUR = 0x00004000,
        VIF_OUTOFMEMORY = 0x00008000,
        VIF_CANNOTREADSRC = 0x00010000,
        VIF_CANNOTREADDST = 0x00020000,
        VIF_BUFFTOOSMALL = 0x00040000,
        VIF_CANNOTLOADLZ32 = 0x00080000,
        VIF_CANNOTLOADCABINET = 0x00100000,
    }

    [Flags]
    public enum VS_FIXEDFILEINFO_FILE_FLAGS : uint
    {
        VS_FF_DEBUG = 0x00000001,
        VS_FF_PRERELEASE = 0x00000002,
        VS_FF_PATCHED = 0x00000004,
        VS_FF_PRIVATEBUILD = 0x00000008,
        VS_FF_INFOINFERRED = 0x00000010,
        VS_FF_SPECIALBUILD = 0x00000020,
    }

    public enum VS_FIXEDFILEINFO_FILE_OS
    {
        VOS_UNKNOWN = 0x00000000,
        VOS_DOS = 0x00010000,
        VOS_OS216 = 0x00020000,
        VOS_OS232 = 0x00030000,
        VOS_NT = 0x00040000,
        VOS_WINCE = 0x00050000,
        VOS__BASE = 0x00000000,
        VOS__WINDOWS16 = 0x00000001,
        VOS__PM16 = 0x00000002,
        VOS__PM32 = 0x00000003,
        VOS__WINDOWS32 = 0x00000004,
        VOS_DOS_WINDOWS16 = 0x00010001,
        VOS_DOS_WINDOWS32 = 0x00010004,
        VOS_OS216_PM16 = 0x00020002,
        VOS_OS232_PM32 = 0x00030003,
        VOS_NT_WINDOWS32 = 0x00040004,
    }

    public enum VS_FIXEDFILEINFO_FILE_TYPE
    {
        VFT_UNKNOWN = 0x00000000,
        VFT_APP = 0x00000001,
        VFT_DLL = 0x00000002,
        VFT_DRV = 0x00000003,
        VFT_FONT = 0x00000004,
        VFT_VXD = 0x00000005,
        VFT_STATIC_LIB = 0x00000007,
    }

    public enum VS_FIXEDFILEINFO_FILE_SUBTYPE
    {
        VFT2_UNKNOWN = 0x00000000,
        VFT2_DRV_PRINTER = 0x00000001,
        VFT2_DRV_KEYBOARD = 0x00000002,
        VFT2_DRV_LANGUAGE = 0x00000003,
        VFT2_DRV_DISPLAY = 0x00000004,
        VFT2_DRV_MOUSE = 0x00000005,
        VFT2_DRV_NETWORK = 0x00000006,
        VFT2_DRV_SYSTEM = 0x00000007,
        VFT2_DRV_INSTALLABLE = 0x00000008,
        VFT2_DRV_SOUND = 0x00000009,
        VFT2_DRV_COMM = 0x0000000A,
        VFT2_DRV_INPUTMETHOD = 0x0000000B,
        VFT2_DRV_VERSIONED_PRINTER = 0x0000000C,
        VFT2_FONT_RASTER = 0x00000001,
        VFT2_FONT_VECTOR = 0x00000002,
        VFT2_FONT_TRUETYPE = 0x00000003,
    }

    public enum FILE_CREATION_DISPOSITION : uint
    {
        CREATE_NEW = 1,
        CREATE_ALWAYS = 2,
        OPEN_EXISTING = 3,
        OPEN_ALWAYS = 4,
        TRUNCATE_EXISTING = 5,
    }

    [Flags]
    public enum FILE_SHARE_MODE : uint
    {
        FILE_SHARE_NONE = 0,
        FILE_SHARE_DELETE = 4,
        FILE_SHARE_READ = 1,
        FILE_SHARE_WRITE = 2,
    }

    [Flags]
    public enum SHARE_TYPE : uint
    {
        STYPE_DISKTREE = 0,
        STYPE_PRINTQ = 1,
        STYPE_DEVICE = 2,
        STYPE_IPC = 3,
        STYPE_SPECIAL = 0x80000000,
        STYPE_TEMPORARY = 0x40000000,
        STYPE_MASK = 0x000000FF,
    }

    [Flags]
    public enum CLFS_FLAG : uint
    {
        CLFS_FLAG_FORCE_APPEND = 0x00000001,
        CLFS_FLAG_FORCE_FLUSH = 0x00000002,
        CLFS_FLAG_NO_FLAGS = 0x00000000,
        CLFS_FLAG_USE_RESERVATION = 0x00000004,
    }

    public enum SET_FILE_POINTER_MOVE_METHOD : uint
    {
        FILE_BEGIN = 0,
        FILE_CURRENT = 1,
        FILE_END = 2,
    }

    [Flags]
    public enum MOVE_FILE_FLAGS : uint
    {
        MOVEFILE_COPY_ALLOWED = 0x00000002,
        MOVEFILE_CREATE_HARDLINK = 0x00000010,
        MOVEFILE_DELAY_UNTIL_REBOOT = 0x00000004,
        MOVEFILE_REPLACE_EXISTING = 0x00000001,
        MOVEFILE_WRITE_THROUGH = 0x00000008,
        MOVEFILE_FAIL_IF_NOT_TRACKABLE = 0x00000020,
    }

    public enum FILE_NAME : uint
    {
        FILE_NAME_NORMALIZED = 0,
        FILE_NAME_OPENED = 8,
    }

    [Flags]
    public enum LZOPENFILE_STYLE : uint
    {
        OF_CANCEL = 2048,
        OF_CREATE = 4096,
        OF_DELETE = 512,
        OF_EXIST = 16384,
        OF_PARSE = 256,
        OF_PROMPT = 8192,
        OF_READ = 0,
        OF_READWRITE = 2,
        OF_REOPEN = 32768,
        OF_SHARE_DENY_NONE = 64,
        OF_SHARE_DENY_READ = 48,
        OF_SHARE_DENY_WRITE = 32,
        OF_SHARE_EXCLUSIVE = 16,
        OF_WRITE = 1,
        OF_SHARE_COMPAT = 0,
        OF_VERIFY = 0x00000400,
    }

    [Flags]
    public enum FILE_NOTIFY_CHANGE : uint
    {
        FILE_NOTIFY_CHANGE_FILE_NAME = 1,
        FILE_NOTIFY_CHANGE_DIR_NAME = 2,
        FILE_NOTIFY_CHANGE_ATTRIBUTES = 4,
        FILE_NOTIFY_CHANGE_SIZE = 8,
        FILE_NOTIFY_CHANGE_LAST_WRITE = 16,
        FILE_NOTIFY_CHANGE_LAST_ACCESS = 32,
        FILE_NOTIFY_CHANGE_CREATION = 64,
        FILE_NOTIFY_CHANGE_SECURITY = 256,
    }

    public enum TXFS_MINIVERSION : uint
    {
        TXFS_MINIVERSION_COMMITTED_VIEW = 0,
        TXFS_MINIVERSION_DIRTY_VIEW = 65535,
        TXFS_MINIVERSION_DEFAULT_VIEW = 65534,
    }

    public enum TAPE_POSITION_TYPE
    {
        TAPE_ABSOLUTE_POSITION = 0,
        TAPE_LOGICAL_POSITION = 1,
    }

    public enum CREATE_TAPE_PARTITION_METHOD
    {
        TAPE_FIXED_PARTITIONS = 0,
        TAPE_INITIATOR_PARTITIONS = 2,
        TAPE_SELECT_PARTITIONS = 1,
    }

    [Flags]
    public enum REPLACE_FILE_FLAGS : uint
    {
        REPLACEFILE_WRITE_THROUGH = 1,
        REPLACEFILE_IGNORE_MERGE_ERRORS = 2,
        REPLACEFILE_IGNORE_ACL_ERRORS = 4,
    }

    public enum TAPEMARK_TYPE
    {
        TAPE_FILEMARKS = 1,
        TAPE_LONG_FILEMARKS = 3,
        TAPE_SETMARKS = 0,
        TAPE_SHORT_FILEMARKS = 2,
    }

    public enum DISKQUOTA_USERNAME_RESOLVE : uint
    {
        DISKQUOTA_USERNAME_RESOLVE_ASYNC = 2,
        DISKQUOTA_USERNAME_RESOLVE_NONE = 0,
        DISKQUOTA_USERNAME_RESOLVE_SYNC = 1,
    }

    public enum TAPE_POSITION_METHOD
    {
        TAPE_ABSOLUTE_BLOCK = 1,
        TAPE_LOGICAL_BLOCK = 2,
        TAPE_REWIND = 0,
        TAPE_SPACE_END_OF_DATA = 4,
        TAPE_SPACE_FILEMARKS = 6,
        TAPE_SPACE_RELATIVE_BLOCKS = 5,
        TAPE_SPACE_SEQUENTIAL_FMKS = 7,
        TAPE_SPACE_SEQUENTIAL_SMKS = 9,
        TAPE_SPACE_SETMARKS = 8,
    }

    public enum TAPE_INFORMATION_TYPE : uint
    {
        SET_TAPE_DRIVE_INFORMATION = 1,
        SET_TAPE_MEDIA_INFORMATION = 0,
    }

    public enum NTMS_OMID_TYPE : uint
    {
        NTMS_OMID_TYPE_FILESYSTEM_INFO = 0x02,
        NTMS_OMID_TYPE_RAW_LABEL = 0x01,
    }

    [Flags]
    public enum LOCK_FILE_FLAGS : uint
    {
        LOCKFILE_EXCLUSIVE_LOCK = 2,
        LOCKFILE_FAIL_IMMEDIATELY = 1,
    }

    public enum LPPROGRESS_ROUTINE_CALLBACK_REASON : uint
    {
        CALLBACK_CHUNK_FINISHED = 0,
        CALLBACK_STREAM_SWITCH = 1,
    }

    public enum PREPARE_TAPE_OPERATION
    {
        TAPE_FORMAT = 5,
        TAPE_LOAD = 0,
        TAPE_LOCK = 3,
        TAPE_TENSION = 2,
        TAPE_UNLOAD = 1,
        TAPE_UNLOCK = 4,
    }

    public enum GET_TAPE_DRIVE_PARAMETERS_OPERATION : uint
    {
        GET_TAPE_DRIVE_INFORMATION = 1,
        GET_TAPE_MEDIA_INFORMATION = 0,
    }

    public enum ERASE_TAPE_TYPE
    {
        TAPE_ERASE_LONG = 1,
        TAPE_ERASE_SHORT = 0,
    }

    public enum FILE_ACTION : uint
    {
        FILE_ACTION_ADDED = 1,
        FILE_ACTION_REMOVED = 2,
        FILE_ACTION_MODIFIED = 3,
        FILE_ACTION_RENAMED_OLD_NAME = 4,
        FILE_ACTION_RENAMED_NEW_NAME = 5,
    }

    [Flags]
    public enum USN_DELETE_FLAGS : uint
    {
        USN_DELETE_FLAG_DELETE = 1,
        USN_DELETE_FLAG_NOTIFY = 2,
    }

    public enum SHARE_INFO_PERMISSIONS : uint
    {
        ACCESS_READ = 1,
        ACCESS_WRITE = 2,
        ACCESS_CREATE = 4,
        ACCESS_EXEC = 8,
        ACCESS_DELETE = 16,
        ACCESS_ATRIB = 32,
        ACCESS_PERM = 64,
        ACCESS_ALL = 32768,
    }

    public enum FILE_DEVICE_TYPE : uint
    {
        FILE_DEVICE_CD_ROM = 0x00000002,
        FILE_DEVICE_DISK = 0x00000007,
        FILE_DEVICE_TAPE = 0x0000001f,
        FILE_DEVICE_DVD = 0x00000033,
    }

    [Flags]
    public enum TXFS_RMF_LAGS : uint
    {
        TXFS_RM_FLAG_LOGGING_MODE = 1,
        TXFS_RM_FLAG_RENAME_RM = 2,
        TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX = 4,
        TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN = 8,
        TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS = 16,
        TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT = 32,
        TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE = 64,
        TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX = 128,
        TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN = 256,
        TXFS_RM_FLAG_GROW_LOG = 1024,
        TXFS_RM_FLAG_SHRINK_LOG = 2048,
        TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE = 4096,
        TXFS_RM_FLAG_PRESERVE_CHANGES = 8192,
        TXFS_RM_FLAG_RESET_RM_AT_NEXT_START = 16384,
        TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START = 32768,
        TXFS_RM_FLAG_PREFER_CONSISTENCY = 65536,
        TXFS_RM_FLAG_PREFER_AVAILABILITY = 131072,
    }

    public enum FILESYSTEM_STATISTICS_TYPE : ushort
    {
        FILESYSTEM_STATISTICS_TYPE_EXFAT = 3,
        FILESYSTEM_STATISTICS_TYPE_FAT = 2,
        FILESYSTEM_STATISTICS_TYPE_NTFS = 1,
    }

    public enum USN_SOURCE_INFO_ID : uint
    {
        USN_SOURCE_AUXILIARY_DATA = 2,
        USN_SOURCE_DATA_MANAGEMENT = 1,
        USN_SOURCE_REPLICATION_MANAGEMENT = 4,
        USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT = 8,
    }

    [Flags]
    public enum FILE_STORAGE_TIER_FLAGS : uint
    {
        FILE_STORAGE_TIER_FLAG_NO_SEEK_PENALTY = 131072,
    }

    public enum SESSION_INFO_USER_FLAGS : uint
    {
        SESS_GUEST = 0x00000001,
        SESS_NOENCRYPTION = 0x00000002,
    }

    public enum WIN_STREAM_ID : uint
    {
        BACKUP_ALTERNATE_DATA = 4,
        BACKUP_DATA = 1,
        BACKUP_EA_DATA = 2,
        BACKUP_LINK = 5,
        BACKUP_OBJECT_ID = 7,
        BACKUP_PROPERTY_DATA = 6,
        BACKUP_REPARSE_DATA = 8,
        BACKUP_SECURITY_DATA = 3,
        BACKUP_SPARSE_BLOCK = 9,
        BACKUP_TXFS_DATA = 10,
    }

    public enum TXF_LOG_RECORD_TYPE : ushort
    {
        TXF_LOG_RECORD_TYPE_AFFECTED_FILE = 4,
        TXF_LOG_RECORD_TYPE_TRUNCATE = 2,
        TXF_LOG_RECORD_TYPE_WRITE = 1,
    }

    [Flags]
    public enum FILE_INFO_FLAGS_PERMISSIONS : uint
    {
        PERM_FILE_READ = 0x1,
        PERM_FILE_WRITE = 0x2,
        PERM_FILE_CREATE = 0x4,
    }

    [Flags]
    public enum SYMBOLIC_LINK_FLAGS : uint
    {
        SYMBOLIC_LINK_FLAG_DIRECTORY = 0x1,
        SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE = 0x2,
    }

}
