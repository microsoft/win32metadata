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


namespace Windows.Win32.System.Registry
{
    public static partial class Apis
    {
        public const uint RRF_SUBKEY_WOW6464KEY = 0x00010000;

        public const uint RRF_SUBKEY_WOW6432KEY = 0x00020000;

        public const uint RRF_WOW64_MASK = 0x00030000;

        public const uint RRF_NOEXPAND = 0x10000000;

        public const uint RRF_ZEROONFAILURE = 0x20000000;

        public const uint REG_PROCESS_APPKEY = 0x00000001;

        public const uint PROVIDER_KEEPS_VALUE_LENGTH = 0x1;

        public const uint REG_MUI_STRING_TRUNCATE = 0x00000001;

        public const uint REG_SECURE_CONNECTION = 1;

    }
}
