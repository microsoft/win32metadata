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


namespace Windows.Win32.Storage.Packaging.Appx
{
    public static partial class Apis
    {
        public const uint PACKAGE_PROPERTY_FRAMEWORK = 0x00000001;

        public const uint PACKAGE_PROPERTY_RESOURCE = 0x00000002;

        public const uint PACKAGE_PROPERTY_BUNDLE = 0x00000004;

        public const uint PACKAGE_PROPERTY_OPTIONAL = 0x00000008;

        public const uint PACKAGE_FILTER_HEAD = 0x00000010;

        public const uint PACKAGE_FILTER_DIRECT = 0x00000020;

        public const uint PACKAGE_FILTER_RESOURCE = 0x00000040;

        public const uint PACKAGE_FILTER_BUNDLE = 0x00000080;

        public const uint PACKAGE_INFORMATION_BASIC = 0x00000000;

        public const uint PACKAGE_INFORMATION_FULL = 0x00000100;

        public const uint PACKAGE_PROPERTY_DEVELOPMENT_MODE = 0x00010000;

        public const uint PACKAGE_FILTER_OPTIONAL = 0x00020000;

        public const uint PACKAGE_PROPERTY_IS_IN_RELATED_SET = 0x00040000;

        public const uint PACKAGE_PROPERTY_STATIC = 0x00080000;

        public const uint PACKAGE_PROPERTY_DYNAMIC = 0x00100000;

        public const uint PACKAGE_FILTER_ALL_LOADED = 0;

    }
}
