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


namespace Windows.Win32.Storage.FileServerResourceManager
{
    public static partial class Apis
    {
        public const uint FSRM_DISPID_FEATURE_MASK = 0xf000000;

        public const uint FSRM_DISPID_INTERFACE_A_MASK = 0xf00000;

        public const uint FSRM_DISPID_INTERFACE_B_MASK = 0xf0000;

        public const uint FSRM_DISPID_INTERFACE_C_MASK = 0xf000;

        public const uint FSRM_DISPID_INTERFACE_D_MASK = 0xf00;

        public const uint FSRM_DISPID_IS_PROPERTY = 0x80;

        public const uint FSRM_DISPID_METHOD_NUM_MASK = 0x7f;

        public const uint FSRM_DISPID_FEATURE_GENERAL = 0x1000000;

        public const uint FSRM_DISPID_FEATURE_QUOTA = 0x2000000;

        public const uint FSRM_DISPID_FEATURE_FILESCREEN = 0x3000000;

        public const uint FSRM_DISPID_FEATURE_REPORTS = 0x4000000;

        public const uint FSRM_DISPID_FEATURE_CLASSIFICATION = 0x5000000;

        public const uint FSRM_DISPID_FEATURE_PIPELINE = 0x6000000;

        public const uint FsrmMaxNumberThresholds = 16;

        public const uint FsrmMinThresholdValue = 1;

        public const uint FsrmMaxThresholdValue = 250;

        public const uint FsrmMinQuotaLimit = 1024;

        public const uint FsrmMaxExcludeFolders = 32;

        public const uint FsrmMaxNumberPropertyDefinitions = 100;

        public const uint MessageSizeLimit = 4096;

        public const int FsrmDaysNotSpecified = -1;

    }
}
