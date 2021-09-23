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


namespace Windows.Win32.NetworkManagement.NetworkDiagnosticsFramework
{
    public static partial class Apis
    {
        public const uint NDF_ERROR_START = 0xF900;

        [NativeTypeName("HRESULT")]
        public const int NDF_E_LENGTH_EXCEEDED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_NOHELPERCLASS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 1));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_CANCELLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 2));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_DISABLED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 4));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_BAD_PARAM = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 5));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_VALIDATION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 6));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_UNKNOWN = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 7));

        [NativeTypeName("HRESULT")]
        public const int NDF_E_PROBLEM_PRESENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WINDOWS)) << 16) | (int)(NDF_ERROR_START + 8));

        public const uint RF_WORKAROUND = 0x20000000;

        public const uint RF_USER_ACTION = 0x10000000;

        public const uint RF_USER_CONFIRMATION = 0x8000000;

        public const uint RF_INFORMATION_ONLY = 0x2000000;

        public const uint RF_UI_ONLY = 0x1000000;

        public const uint RF_SHOW_EVENTS = 0x800000;

        public const uint RF_VALIDATE_HELPTOPIC = 0x400000;

        public const uint RF_REPRO = 0x200000;

        public const uint RF_CONTACT_ADMIN = 0x20000;

        public const uint RF_RESERVED = 0x40000000;

        public const uint RF_RESERVED_CA = 0x80000000;

        public const uint RF_RESERVED_LNI = 0x10000;

        public const uint RCF_ISLEAF = 0x1;

        public const uint RCF_ISCONFIRMED = 0x2;

        public const uint RCF_ISTHIRDPARTY = 0x4;

        public const uint DF_IMPERSONATION = 0x80000000;

        public const uint DF_TRACELESS = 0x40000000;

        public const uint NDF_INBOUND_FLAG_EDGETRAVERSAL = 0x00001;

        public const uint NDF_INBOUND_FLAG_HEALTHCHECK = 0x00002;

        public const uint NDF_ADD_CAPTURE_TRACE = 0x0001;

        public const uint NDF_APPLY_INCLUSION_LIST_FILTER = 0x0002;

    }
}
