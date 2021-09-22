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


namespace Windows.Win32.Storage.DistributedFileSystem
{
    public static partial class Apis
    {
        public const uint DFS_VOLUME_STATES = 0xF;

        public const uint DFS_VOLUME_STATE_OK = 1;

        public const uint DFS_VOLUME_STATE_INCONSISTENT = 2;

        public const uint DFS_VOLUME_STATE_OFFLINE = 3;

        public const uint DFS_VOLUME_STATE_ONLINE = 4;

        public const uint DFS_VOLUME_STATE_RESYNCHRONIZE = 0x10;

        public const uint DFS_VOLUME_STATE_STANDBY = 0x20;

        public const uint DFS_VOLUME_STATE_FORCE_SYNC = 0x40;

        public const uint DFS_VOLUME_FLAVORS = 0x0300;

        public const uint DFS_VOLUME_FLAVOR_UNUSED1 = 0x0000;

        public const uint DFS_VOLUME_FLAVOR_STANDALONE = 0x0100;

        public const uint DFS_VOLUME_FLAVOR_AD_BLOB = 0x0200;

        public const uint DFS_STORAGE_FLAVOR_UNUSED2 = 0x0300;

        public const uint DFS_STORAGE_STATES = 0xF;

        public const uint DFS_STORAGE_STATE_OFFLINE = 1;

        public const uint DFS_STORAGE_STATE_ONLINE = 2;

        public const uint DFS_STORAGE_STATE_ACTIVE = 4;

        public const uint DFS_PROPERTY_FLAG_INSITE_REFERRALS = 0x00000001;

        public const uint DFS_PROPERTY_FLAG_ROOT_SCALABILITY = 0x00000002;

        public const uint DFS_PROPERTY_FLAG_SITE_COSTING = 0x00000004;

        public const uint DFS_PROPERTY_FLAG_TARGET_FAILBACK = 0x00000008;

        public const uint DFS_PROPERTY_FLAG_CLUSTER_ENABLED = 0x00000010;

        public const uint DFS_PROPERTY_FLAG_ABDE = 0x00000020;

        public const uint DFS_ADD_VOLUME = 1;

        public const uint DFS_RESTORE_VOLUME = 2;

        public const uint NET_DFS_SETDC_FLAGS = 0x00000000;

        public const uint NET_DFS_SETDC_TIMEOUT = 0x00000001;

        public const uint NET_DFS_SETDC_INITPKT = 0x00000002;

        public const uint DFS_SITE_PRIMARY = 0x1;

        public const uint DFS_MOVE_FLAG_REPLACE_IF_EXISTS = 0x00000001;

        public const uint DFS_FORCE_REMOVE = 0x80000000;

        public const uint FSCTL_DFS_GET_PKT_ENTRY_STATE = ((FSCTL_DFS_BASE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((2031) << 2) | (METHOD_BUFFERED);

    }
}
