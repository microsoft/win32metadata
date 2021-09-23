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


namespace Windows.Win32.Storage.Vhd
{
    public static partial class Apis
    {
        public static readonly Guid VIRTUAL_STORAGE_TYPE_VENDOR_UNKNOWN__scanned__ = new Guid(0x00000000, 0x0000, 0x0000, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00);

        public static readonly Guid VIRTUAL_STORAGE_TYPE_VENDOR_MICROSOFT__scanned__ = new Guid(0xec984aec, 0xa0f9, 0x47e9, 0x90, 0x1f, 0x71, 0x41, 0x5a, 0x66, 0x34, 0x5b);

        public const uint VIRTUAL_STORAGE_TYPE_DEVICE_UNKNOWN = 0;

        public const uint VIRTUAL_STORAGE_TYPE_DEVICE_ISO = 1;

        public const uint VIRTUAL_STORAGE_TYPE_DEVICE_VHD = 2;

        public const uint VIRTUAL_STORAGE_TYPE_DEVICE_VHDX = 3;

        public const uint VIRTUAL_STORAGE_TYPE_DEVICE_VHDSET = 4;

        public const uint OPEN_VIRTUAL_DISK_RW_DEPTH_DEFAULT = 1;

        public const uint CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_BLOCK_SIZE = 0;

        public const uint CREATE_VIRTUAL_DISK_PARAMETERS_DEFAULT_SECTOR_SIZE = 0;

        public const uint VIRTUAL_DISK_MAXIMUM_CHANGE_TRACKING_ID_LENGTH = 256;

        public const uint MERGE_VIRTUAL_DISK_DEFAULT_MERGE_DEPTH = 1;

    }
}
