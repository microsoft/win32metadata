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


namespace Windows.Win32.UI.LegacyWindowsEnvironmentFeatures
{
    public static partial class Apis
    {
        public const uint EVCF_HASSETTINGS = 0x0001;

        public const uint EVCF_ENABLEBYDEFAULT = 0x0002;

        public const uint EVCF_REMOVEFROMLIST = 0x0004;

        public const uint EVCF_ENABLEBYDEFAULT_AUTO = 0x0008;

        public const uint EVCF_DONTSHOWIFZERO = 0x0010;

        public const uint EVCF_SETTINGSMODE = 0x0020;

        public const uint EVCF_OUTOFDISKSPACE = 0x0040;

        public const uint EVCF_USERCONSENTOBTAINED = 0x0080;

        public const uint EVCF_SYSTEMAUTORUN = 0x0100;

        public const uint EVCCBF_LASTNOTIFICATION = 0x0001;

        public const uint STATEBITS_FLAT = 0x0001;

        [NativeTypeName("HRESULT")]
        public const int REC_S_IDIDTHEUPDATES = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1000));

        [NativeTypeName("HRESULT")]
        public const int REC_S_NOTCOMPLETE = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1001));

        [NativeTypeName("HRESULT")]
        public const int REC_S_NOTCOMPLETEBUTPROPAGATE = unchecked((int)((SEVERITY_SUCCESS) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1002));

        [NativeTypeName("HRESULT")]
        public const int REC_E_ABORTED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1000));

        [NativeTypeName("HRESULT")]
        public const int REC_E_NOCALLBACK = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1001));

        [NativeTypeName("HRESULT")]
        public const int REC_E_NORESIDUES = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1002));

        [NativeTypeName("HRESULT")]
        public const int REC_E_TOODIFFERENT = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1003));

        [NativeTypeName("HRESULT")]
        public const int REC_E_INEEDTODOTHEUPDATES = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_ITF)) << 16) | (int)(0x1004));

    }
}
