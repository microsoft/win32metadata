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


namespace Windows.Win32.Storage.Cabinets
{
    public static partial class Apis
    {
        public const uint INCLUDED_FCI = 1;

        public const uint _A_NAME_IS_UTF = 0x80;

        public const uint _A_EXEC = 0x40;

        public const uint INCLUDED_TYPES_FCI_FDI = 1;

        public const int CB_MAX_DISK = 0x7fffffff;

        public const uint CB_MAX_FILENAME = 256;

        public const uint CB_MAX_CABINET_NAME = 256;

        public const uint CB_MAX_CAB_PATH = 256;

        public const uint CB_MAX_DISK_NAME = 256;

        public const uint INCLUDED_FDI = 1;

    }
}
