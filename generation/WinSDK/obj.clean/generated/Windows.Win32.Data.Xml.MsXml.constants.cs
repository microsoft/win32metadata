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


namespace Windows.Win32.Data.Xml.MsXml
{
    public static partial class Apis
    {
        public const int E_XML_NOTWF = unchecked((int)0xC00CE223);

        public const int E_XML_NODTD = unchecked((int)0xC00CE224);

        public const int E_XML_INVALID = unchecked((int)0xC00CE225);

        public const int E_XML_BUFFERTOOSMALL = unchecked((int)0xC00CE226);

        public const uint XHR_PROP_ONDATA_ALWAYS = 0x0;

        public const ulong XHR_PROP_ONDATA_NEVER = 0xFFFFFFFFFFFFFFFF;

    }
}
