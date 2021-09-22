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


namespace Windows.Win32.System.Contacts
{
    public static partial class Apis
    {
        public const uint CGD_DEFAULT = 0x00000000;

        public const uint CGD_UNKNOWN_PROPERTY = 0x00000000;

        public const uint CGD_STRING_PROPERTY = 0x00000001;

        public const uint CGD_DATE_PROPERTY = 0x00000002;

        public const uint CGD_BINARY_PROPERTY = 0x00000004;

        public const uint CGD_ARRAY_NODE = 0x00000008;

    }
}
