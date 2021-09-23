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


namespace Windows.Win32.System.LibraryLoader
{
    public static partial class Apis
    {
        public const uint FIND_RESOURCE_DIRECTORY_TYPES = 0x0100;

        public const uint FIND_RESOURCE_DIRECTORY_NAMES = 0x0200;

        public const uint FIND_RESOURCE_DIRECTORY_LANGUAGES = 0x0400;

        public const uint RESOURCE_ENUM_LN = 0x0001;

        public const uint RESOURCE_ENUM_MUI = 0x0002;

        public const uint RESOURCE_ENUM_MUI_SYSTEM = 0x0004;

        public const uint RESOURCE_ENUM_VALIDATE = 0x0008;

        public const uint RESOURCE_ENUM_MODULE_EXACT = 0x0010;

        public const uint SUPPORT_LANG_NUMBER = 32;

        public const uint GET_MODULE_HANDLE_EX_FLAG_PIN = 0x00000001;

        public const uint GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT = 0x00000002;

        public const uint GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS = 0x00000004;

        public const uint CURRENT_IMPORT_REDIRECTION_VERSION = 1;

        public const uint LOAD_LIBRARY_OS_INTEGRITY_CONTINUITY = 0x00008000;

    }
}
