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


namespace Windows.Win32.Devices.Enumeration.Pnp
{
    public static partial class Apis
    {
        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ROOT_ELEMENT_EXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0200));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_ELEMENT_EXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0201));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_SERVICE_ELEMENT_EXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0202));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_SERVICE_NODE_INCOMPLETE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0203));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_NODE_INCOMPLETE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0204));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ICON_ELEMENT_EXPECTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0205));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ICON_NODE_INCOMPLETE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0206));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_ACTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0207));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_ARGUMENTS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0208));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_OUT_OF_SYNC = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0209));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ACTION_REQUEST_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0210));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_TRANSPORT_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0211));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_VARIABLE_VALUE_UNKNOWN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0212));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_VARIABLE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0213));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0214));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_PROTOCOL_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0215));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ERROR_PROCESSING_RESPONSE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0216));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_TIMEOUT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0217));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_DOCUMENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0500));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_EVENT_SUBSCRIPTION_FAILED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0501));

        public const uint FAULT_INVALID_ACTION = 401;

        public const uint FAULT_INVALID_ARG = 402;

        public const uint FAULT_INVALID_SEQUENCE_NUMBER = 403;

        public const uint FAULT_INVALID_VARIABLE = 404;

        public const uint FAULT_DEVICE_INTERNAL_ERROR = 501;

        public const uint FAULT_ACTION_SPECIFIC_BASE = 600;

        public const uint FAULT_ACTION_SPECIFIC_MAX = 899;

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_ACTION_SPECIFIC_BASE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x0300));

        public const uint UPNP_ADDRESSFAMILY_IPv4 = 0x1;

        public const uint UPNP_ADDRESSFAMILY_IPv6 = 0x2;

        public const uint UPNP_ADDRESSFAMILY_BOTH = 0x3;

        public const uint UPNP_SERVICE_DELAY_SCPD_AND_SUBSCRIPTION = 0x1;

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_REQUIRED_ELEMENT_ERROR = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA020));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DUPLICATE_NOT_ALLOWED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA021));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DUPLICATE_SERVICE_ID = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA022));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_DESCRIPTION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA023));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_SERVICE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA024));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_ICON = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA025));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_XML = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA026));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_INVALID_ROOT_NAMESPACE = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA027));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_SUFFIX_TOO_LONG = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA028));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_URLBASE_PRESENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA029));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_VALUE_TOO_LONG = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA030));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_RUNNING = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA031));

        [NativeTypeName("HRESULT")]
        public const int UPNP_E_DEVICE_NOTREGISTERED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0xA032));

    }
}
