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


namespace Windows.Win32.Storage.CloudFilters
{
    public static partial class Apis
    {
        public const uint CF_REQUEST_KEY_DEFAULT = 0;

        public const uint CF_PLACEHOLDER_MAX_FILE_IDENTITY_LENGTH = 4096;

        public const uint CF_MAX_PRIORITY_HINT = 15;

        public const uint CF_MAX_PROVIDER_NAME_LENGTH = 255;

        public const uint CF_MAX_PROVIDER_VERSION_LENGTH = 255;

    }
}
