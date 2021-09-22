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


namespace Windows.Win32.Devices.WebServicesOnDevices
{
    public static partial class Apis
    {
        public const uint WSDAPI_OPTION_MAX_INBOUND_MESSAGE_SIZE = 0x0001;

        public const uint WSDAPI_OPTION_TRACE_XML_TO_DEBUGGER = 0x0002;

        public const uint WSDAPI_OPTION_TRACE_XML_TO_FILE = 0x0003;

        public const uint WSDAPI_SSL_CERT_APPLY_DEFAULT_CHECKS = 0x0;

        public const uint WSDAPI_SSL_CERT_IGNORE_REVOCATION = 0x1;

        public const uint WSDAPI_SSL_CERT_IGNORE_EXPIRY = 0x2;

        public const uint WSDAPI_SSL_CERT_IGNORE_WRONG_USAGE = 0x4;

        public const uint WSDAPI_SSL_CERT_IGNORE_UNKNOWN_CA = 0x8;

        public const uint WSDAPI_SSL_CERT_IGNORE_INVALID_CN = 0x10;

        public const uint WSDAPI_COMPACTSIG_ACCEPT_ALL_MESSAGES = 0x1;

        public const uint WSD_SECURITY_HTTP_AUTH_SCHEME_NEGOTIATE = 0x1;

        public const uint WSD_SECURITY_HTTP_AUTH_SCHEME_NTLM = 0x2;

        public const uint WSDAPI_ADDRESSFAMILY_IPV4 = 1;

        public const uint WSDAPI_ADDRESSFAMILY_IPV6 = 2;

    }
}
