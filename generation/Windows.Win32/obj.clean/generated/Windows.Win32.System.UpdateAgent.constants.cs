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


namespace Windows.Win32.System.UpdateAgent
{
    public static partial class Apis
    {
        public static readonly Guid LIBID_WUApiLib__scanned__ = new Guid(0xB596CC9F,0x56E5,0x419E,0xA6,0x22,0xE0,0x1B,0xB4,0x57,0x43,0x1E);

        public static readonly Guid CLSID_StringCollection__scanned__ = new Guid(0x72C97D74,0x7C3B,0x40AE,0xB7,0x7D,0xAB,0xDB,0x22,0xEB,0xA6,0xFB);

        public static readonly Guid CLSID_UpdateSearcher__scanned__ = new Guid(0xB699E5E8,0x67FF,0x4177,0x88,0xB0,0x36,0x84,0xA3,0x38,0x8B,0xFB);

        public static readonly Guid CLSID_WebProxy__scanned__ = new Guid(0x650503cf,0x9108,0x4ddc,0xa2,0xce,0x6c,0x23,0x41,0xe1,0xc5,0x82);

        public static readonly Guid CLSID_SystemInformation__scanned__ = new Guid(0xC01B9BA0,0xBEA7,0x41BA,0xB6,0x04,0xD0,0xA3,0x6F,0x46,0x91,0x33);

        public static readonly Guid CLSID_WindowsUpdateAgentInfo__scanned__ = new Guid(0xC2E88C2F,0x6F5B,0x4AAA,0x89,0x4B,0x55,0xC8,0x47,0xAD,0x3A,0x2D);

        public static readonly Guid CLSID_AutomaticUpdates__scanned__ = new Guid(0xBFE18E9C,0x6D87,0x4450,0xB3,0x7C,0xE0,0x2F,0x0B,0x37,0x38,0x03);

        public static readonly Guid CLSID_UpdateCollection__scanned__ = new Guid(0x13639463,0x00DB,0x4646,0x80,0x3D,0x52,0x80,0x26,0x14,0x0D,0x88);

        public static readonly Guid CLSID_UpdateDownloader__scanned__ = new Guid(0x5BAF654A,0x5A07,0x4264,0xA2,0x55,0x9F,0xF5,0x4C,0x71,0x51,0xE7);

        public static readonly Guid CLSID_UpdateInstaller__scanned__ = new Guid(0xD2E0FE7F,0xD23E,0x48E1,0x93,0xC0,0x6F,0xA8,0xCC,0x34,0x64,0x74);

        public static readonly Guid CLSID_UpdateSession__scanned__ = new Guid(0x4CB43D7F,0x7EEE,0x4906,0x86,0x98,0x60,0xDA,0x1C,0x38,0xF2,0xFE);

        public static readonly Guid CLSID_UpdateServiceManager__scanned__ = new Guid(0xF8D253D9,0x89A4,0x4DAA,0x87,0xB6,0x11,0x68,0x36,0x9F,0x0B,0x21);

        public static readonly Guid CLSID_InstallationAgent__scanned__ = new Guid(0x317E92FC,0x1679,0x46FD,0xA0,0xB5,0xF0,0x89,0x14,0xDD,0x86,0x23);

        public const uint UPDATE_LOCKDOWN_WEBSITE_ACCESS = 0x1;

    }
}
