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


namespace Windows.Win32.Storage.OfflineFiles
{
    public static partial class Apis
    {
        public const uint OFFLINEFILES_SYNC_STATE_LOCAL_KNOWN = 0x1;

        public const uint OFFLINEFILES_SYNC_STATE_REMOTE_KNOWN = 0x2;

        public const uint OFFLINEFILES_CHANGES_NONE = 0;

        public const uint OFFLINEFILES_CHANGES_LOCAL_SIZE = 0x1;

        public const uint OFFLINEFILES_CHANGES_LOCAL_ATTRIBUTES = 0x2;

        public const uint OFFLINEFILES_CHANGES_LOCAL_TIME = 0x4;

        public const uint OFFLINEFILES_CHANGES_REMOTE_SIZE = 0x8;

        public const uint OFFLINEFILES_CHANGES_REMOTE_ATTRIBUTES = 0x10;

        public const uint OFFLINEFILES_CHANGES_REMOTE_TIME = 0x20;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_DATA = 0x1;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED_ATTRIBUTES = 0x2;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_MODIFIED = 0x4;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_CREATED = 0x8;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_DELETED = 0x10;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_DIRTY = 0x20;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_SPARSE = 0x40;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_FILE = 0x80;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_DIRECTORY = 0x100;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_USER = 0x200;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_OTHERS = 0x400;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_PINNED_COMPUTER = 0x800;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_PINNED = 0x1000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_GHOST = 0x2000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_SUSPENDED = 0x4000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_OFFLINE = 0x8000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_ONLINE = 0x10000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_USER_WRITE = 0x20000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_USER_READ = 0x40000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_USER_ANYACCESS = 0x80000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_WRITE = 0x100000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_READ = 0x200000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_OTHER_ANYACCESS = 0x400000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_WRITE = 0x800000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_READ = 0x1000000;

        public const uint OFFLINEFILES_ITEM_FILTER_FLAG_GUEST_ANYACCESS = 0x2000000;

        public const uint OFFLINEFILES_ITEM_QUERY_REMOTEINFO = 0x1;

        public const uint OFFLINEFILES_ITEM_QUERY_CONNECTIONSTATE = 0x2;

        public const uint OFFLINEFILES_ITEM_QUERY_LOCALDIRTYBYTECOUNT = 0x4;

        public const uint OFFLINEFILES_ITEM_QUERY_REMOTEDIRTYBYTECOUNT = 0x8;

        public const uint OFFLINEFILES_ITEM_QUERY_INCLUDETRANSPARENTCACHE = 0x10;

        public const uint OFFLINEFILES_ITEM_QUERY_ATTEMPT_TRANSITIONONLINE = 0x20;

        public const uint OFFLINEFILES_ITEM_QUERY_ADMIN = 0x80000000;

        public const uint OFFLINEFILES_ENUM_FLAT = 0x1;

        public const uint OFFLINEFILES_ENUM_FLAT_FILESONLY = 0x2;

        public const uint OFFLINEFILES_SETTING_SCOPE_USER = 0x1;

        public const uint OFFLINEFILES_SETTING_SCOPE_COMPUTER = 0x2;

        public const uint OFFLINEFILES_PINLINKTARGETS_NEVER = 0;

        public const uint OFFLINEFILES_PINLINKTARGETS_EXPLICIT = 1;

        public const uint OFFLINEFILES_PINLINKTARGETS_ALWAYS = 2;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_FILLSPARSE = 0x1;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCIN = 0x2;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_SYNCOUT = 0x4;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINNEWFILES = 0x8;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINLINKTARGETS = 0x10;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER = 0x20;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORUSER_POLICY = 0x40;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORALL = 0x80;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_PINFORREDIR = 0x100;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_LOWPRIORITY = 0x200;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_ASYNCPROGRESS = 0x400;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_INTERACTIVE = 0x800;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_CONSOLE = 0x1000;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_SKIPSUSPENDEDDIRS = 0x2000;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_BACKGROUND = 0x10000;

        public const uint OFFLINEFILES_SYNC_CONTROL_FLAG_NONEWFILESOUT = 0x20000;

        public const uint OFFLINEFILES_SYNC_CONTROL_CR_MASK = 0xf0000000;

        public const uint OFFLINEFILES_SYNC_CONTROL_CR_DEFAULT = 0;

        public const uint OFFLINEFILES_SYNC_CONTROL_CR_KEEPLOCAL = 0x10000000;

        public const uint OFFLINEFILES_SYNC_CONTROL_CR_KEEPREMOTE = 0x20000000;

        public const uint OFFLINEFILES_SYNC_CONTROL_CR_KEEPLATEST = 0x30000000;

        public const uint OFFLINEFILES_DELETE_FLAG_NOAUTOCACHED = 0x1;

        public const uint OFFLINEFILES_DELETE_FLAG_NOPINNED = 0x2;

        public const uint OFFLINEFILES_DELETE_FLAG_DELMODIFIED = 0x4;

        public const uint OFFLINEFILES_DELETE_FLAG_ADMIN = 0x80000000;

        public const uint OFFLINEFILES_TRANSITION_FLAG_INTERACTIVE = 0x1;

        public const uint OFFLINEFILES_TRANSITION_FLAG_CONSOLE = 0x2;

        public const uint OFFLINEFILES_SYNC_ITEM_CHANGE_NONE = 0;

        public const uint OFFLINEFILES_SYNC_ITEM_CHANGE_CHANGETIME = 0x1;

        public const uint OFFLINEFILES_SYNC_ITEM_CHANGE_WRITETIME = 0x2;

        public const uint OFFLINEFILES_SYNC_ITEM_CHANGE_FILESIZE = 0x4;

        public const uint OFFLINEFILES_SYNC_ITEM_CHANGE_ATTRIBUTES = 0x8;

    }
}
