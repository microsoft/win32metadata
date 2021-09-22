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


namespace Windows.Win32.System.WindowsSync
{
    public static partial class Apis
    {
        public const uint SYNC_VERSION_FLAG_FROM_FEED = 0x00000001;

        public const uint SYNC_VERSION_FLAG_HAS_BY = 0x00000002;

        public const uint SYNC_SERIALIZE_REPLICA_KEY_MAP = 0x00000001;

        public const uint SYNC_FILTER_INFO_FLAG_ITEM_LIST = 0x00000001;

        public const uint SYNC_FILTER_INFO_FLAG_CHANGE_UNIT_LIST = 0x00000002;

        public const uint SYNC_FILTER_INFO_FLAG_CUSTOM = 0x00000004;

        public const uint SYNC_FILTER_INFO_COMBINED = 0x00000008;

        public const uint SYNC_CHANGE_FLAG_DELETED = 0x00000001;

        public const uint SYNC_CHANGE_FLAG_DOES_NOT_EXIST = 0x00000002;

        public const uint SYNC_CHANGE_FLAG_GHOST = 0x00000004;

    }
}
