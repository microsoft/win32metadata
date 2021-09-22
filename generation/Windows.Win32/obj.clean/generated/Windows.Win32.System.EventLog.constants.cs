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


namespace Windows.Win32.System.EventLog
{
    public static partial class Apis
    {
        public const uint EVT_VARIANT_TYPE_MASK = 0x7f;

        public const uint EVT_VARIANT_TYPE_ARRAY = 128;

        public const uint EVT_READ_ACCESS = 0x1;

        public const uint EVT_WRITE_ACCESS = 0x2;

        public const uint EVT_CLEAR_ACCESS = 0x4;

        public const uint EVT_ALL_ACCESS = 0x7;

    }
}
