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


namespace Windows.Win32.Storage.VirtualDiskService
{
    public static partial class Apis
    {
        public const uint VDS_NF_VOLUME_ARRIVE = 4;

        public const uint VDS_NF_VOLUME_DEPART = 5;

        public const uint VDS_NF_VOLUME_MODIFY = 6;

        public const uint VDS_NF_VOLUME_REBUILDING_PROGRESS = 7;

        public const uint VDS_NF_PARTITION_ARRIVE = 11;

        public const uint VDS_NF_PARTITION_DEPART = 12;

        public const uint VDS_NF_PARTITION_MODIFY = 13;

        public const uint VDS_NF_SUB_SYSTEM_ARRIVE = 101;

        public const uint VDS_NF_SUB_SYSTEM_DEPART = 102;

        public const uint VDS_NF_PORTAL_ARRIVE = 123;

        public const uint VDS_NF_PORTAL_DEPART = 124;

        public const uint VDS_NF_PORTAL_MODIFY = 125;

        public const uint VDS_NF_TARGET_ARRIVE = 126;

        public const uint VDS_NF_TARGET_DEPART = 127;

        public const uint VDS_NF_TARGET_MODIFY = 128;

        public const uint VDS_NF_PORTAL_GROUP_ARRIVE = 129;

        public const uint VDS_NF_PORTAL_GROUP_DEPART = 130;

        public const uint VDS_NF_PORTAL_GROUP_MODIFY = 131;

        public const uint VDS_NF_SUB_SYSTEM_MODIFY = 151;

        public const uint VDS_NF_DRIVE_LETTER_FREE = 201;

        public const uint VDS_NF_DRIVE_LETTER_ASSIGN = 202;

        public const uint VDS_NF_MOUNT_POINTS_CHANGE = 205;

        public const uint VDS_NF_FILE_SYSTEM_SHRINKING_PROGRESS = 206;

        public const uint VDS_NF_SERVICE_OUT_OF_SYNC = 301;

        public const uint GPT_PARTITION_NAME_LENGTH = 36;

        public const int VDS_HINT_FASTCRASHRECOVERYREQUIRED = 0x1;

        public const int VDS_HINT_MOSTLYREADS = 0x2;

        public const int VDS_HINT_OPTIMIZEFORSEQUENTIALREADS = 0x4;

        public const int VDS_HINT_OPTIMIZEFORSEQUENTIALWRITES = 0x8;

        public const int VDS_HINT_READBACKVERIFYENABLED = 0x10;

        public const int VDS_HINT_REMAPENABLED = 0x20;

        public const int VDS_HINT_WRITETHROUGHCACHINGENABLED = 0x40;

        public const int VDS_HINT_HARDWARECHECKSUMENABLED = 0x80;

        public const int VDS_HINT_ISYANKABLE = 0x100;

        public const int VDS_HINT_ALLOCATEHOTSPARE = 0x200;

        public const int VDS_HINT_BUSTYPE = 0x400;

        public const int VDS_HINT_USEMIRROREDCACHE = 0x800;

        public const int VDS_HINT_READCACHINGENABLED = 0x1000;

        public const int VDS_HINT_WRITECACHINGENABLED = 0x2000;

        public const int VDS_HINT_MEDIASCANENABLED = 0x4000;

        public const int VDS_HINT_CONSISTENCYCHECKENABLED = 0x8000;

        public const uint VDS_REBUILD_PRIORITY_MIN = 0;

        public const uint VDS_REBUILD_PRIORITY_MAX = 16;

        public const int VDS_POOL_ATTRIB_RAIDTYPE = 0x1;

        public const int VDS_POOL_ATTRIB_BUSTYPE = 0x2;

        public const int VDS_POOL_ATTRIB_ALLOW_SPINDOWN = 0x4;

        public const int VDS_POOL_ATTRIB_THIN_PROVISION = 0x8;

        public const int VDS_POOL_ATTRIB_NO_SINGLE_POF = 0x10;

        public const int VDS_POOL_ATTRIB_DATA_RDNCY_MAX = 0x20;

        public const int VDS_POOL_ATTRIB_DATA_RDNCY_MIN = 0x40;

        public const int VDS_POOL_ATTRIB_DATA_RDNCY_DEF = 0x80;

        public const int VDS_POOL_ATTRIB_PKG_RDNCY_MAX = 0x100;

        public const int VDS_POOL_ATTRIB_PKG_RDNCY_MIN = 0x200;

        public const int VDS_POOL_ATTRIB_PKG_RDNCY_DEF = 0x400;

        public const int VDS_POOL_ATTRIB_STRIPE_SIZE = 0x800;

        public const int VDS_POOL_ATTRIB_STRIPE_SIZE_MAX = 0x1000;

        public const int VDS_POOL_ATTRIB_STRIPE_SIZE_MIN = 0x2000;

        public const int VDS_POOL_ATTRIB_STRIPE_SIZE_DEF = 0x4000;

        public const int VDS_POOL_ATTRIB_NUM_CLMNS = 0x8000;

        public const int VDS_POOL_ATTRIB_NUM_CLMNS_MAX = 0x10000;

        public const int VDS_POOL_ATTRIB_NUM_CLMNS_MIN = 0x20000;

        public const int VDS_POOL_ATTRIB_NUM_CLMNS_DEF = 0x40000;

        public const int VDS_POOL_ATTRIB_DATA_AVL_HINT = 0x80000;

        public const int VDS_POOL_ATTRIB_ACCS_RNDM_HINT = 0x100000;

        public const int VDS_POOL_ATTRIB_ACCS_DIR_HINT = 0x200000;

        public const int VDS_POOL_ATTRIB_ACCS_SIZE_HINT = 0x400000;

        public const int VDS_POOL_ATTRIB_ACCS_LTNCY_HINT = 0x800000;

        public const int VDS_POOL_ATTRIB_ACCS_BDW_WT_HINT = 0x1000000;

        public const int VDS_POOL_ATTRIB_STOR_COST_HINT = 0x2000000;

        public const int VDS_POOL_ATTRIB_STOR_EFFCY_HINT = 0x4000000;

        public const int VDS_POOL_ATTRIB_CUSTOM_ATTRIB = 0x8000000;

        public const uint VDS_ATTACH_VIRTUAL_DISK_FLAG_USE_FILE_ACL = 0x1;

        public static readonly Guid CLSID_VdsLoader__scanned__ = new Guid(0X9C38ED61,0xD565,0x4728,0xAE,0xEE,0xC8,0x09,0x52,0xF0,0xEC,0xDE);

        public static readonly Guid CLSID_VdsService__scanned__ = new Guid(0x7D1933CB,0x86F6,0x4A98,0x86,0x28,0x01,0xBE,0x94,0xC9,0xA5,0x75);

        public const uint MAX_FS_NAME_SIZE = 8;

        public const uint MAX_FS_FORMAT_SUPPORT_NAME_SIZE = 32;

        public const uint MAX_FS_ALLOWED_CLUSTER_SIZES_SIZE = 32;

        public const uint VER_VDS_LUN_INFORMATION = 1;

    }
}
