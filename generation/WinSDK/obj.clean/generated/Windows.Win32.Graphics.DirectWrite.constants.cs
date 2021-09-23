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


namespace Windows.Win32.Graphics.DirectWrite
{
    public static partial class Apis
    {
        public const uint DWRITE_ALPHA_MAX = 255;

        public const uint FACILITY_DWRITE = 0x898;

        public const uint DWRITE_ERR_BASE = 0x5000;

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_REMOTEFONT = unchecked((int)0x8898500D);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_DOWNLOADCANCELLED = unchecked((int)0x8898500E);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_DOWNLOADFAILED = unchecked((int)0x8898500F);

        [NativeTypeName("HRESULT")]
        public const int DWRITE_E_TOOMANYDOWNLOADS = unchecked((int)0x88985010);

    }
}
