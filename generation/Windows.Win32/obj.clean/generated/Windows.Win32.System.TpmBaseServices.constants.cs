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


namespace Windows.Win32.System.TpmBaseServices
{
    public static partial class Apis
    {
        public const uint TBS_CONTEXT_VERSION_ONE = 1;

        public const uint TBS_SUCCESS = 0;

        public const uint TBS_OWNERAUTH_TYPE_FULL = 1;

        public const uint TBS_OWNERAUTH_TYPE_ADMIN = 2;

        public const uint TBS_OWNERAUTH_TYPE_USER = 3;

        public const uint TBS_OWNERAUTH_TYPE_ENDORSEMENT = 4;

        public const uint TBS_OWNERAUTH_TYPE_ENDORSEMENT_20 = 12;

        public const uint TBS_OWNERAUTH_TYPE_STORAGE_20 = 13;

        public const uint TBS_CONTEXT_VERSION_TWO = 2;

        public const uint TPM_WNF_INFO_CLEAR_SUCCESSFUL = 0x00000001;

        public const uint TPM_WNF_INFO_OWNERSHIP_SUCCESSFUL = 0x00000002;

        public const uint TPM_WNF_INFO_NO_REBOOT_REQUIRED = 1;

        public const uint TPM_VERSION_UNKNOWN = 0;

        public const uint TPM_VERSION_12 = 1;

        public const uint TPM_VERSION_20 = 2;

        public const uint TPM_IFTYPE_UNKNOWN = 0;

        public const uint TPM_IFTYPE_1 = 1;

        public const uint TPM_IFTYPE_TRUSTZONE = 2;

        public const uint TPM_IFTYPE_HW = 3;

        public const uint TPM_IFTYPE_EMULATOR = 4;

        public const uint TPM_IFTYPE_SPB = 5;

        public const uint TBS_TCGLOG_SRTM_CURRENT = 0;

        public const uint TBS_TCGLOG_DRTM_CURRENT = 1;

        public const uint TBS_TCGLOG_SRTM_BOOT = 2;

        public const uint TBS_TCGLOG_SRTM_RESUME = 3;

        public const uint TBS_TCGLOG_DRTM_BOOT = 4;

        public const uint TBS_TCGLOG_DRTM_RESUME = 5;

    }
}
