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


namespace Windows.Win32.System.ComponentServices
{
    public static partial class Apis
    {
        public static readonly Guid IID_IXAResourceManager__scanned__ = new Guid(0x4131E751, 0x1AEA, 0x11d0, 0x94, 0x4B, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x6E);

        public static readonly Guid IID_IXAResourceManagerFactory__scanned__ = new Guid(0x4131E750, 0x1AEA, 0x11d0, 0x94, 0x4B, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x6E);

        public static readonly Guid IID_IXATransaction__scanned__ = new Guid(0x4131E752, 0x1AEA, 0x11d0, 0x94, 0x4B, 0x00, 0xA0, 0xC9, 0x05, 0x41, 0x6E);

        public const uint GUID_STRING_SIZE = 40;

        public const uint DATA_NOT_AVAILABLE = 0xffffffff;

        public const uint MTXDM_E_ENLISTRESOURCEFAILED = 0x8004E100;

        public const uint CRR_NO_REASON_SUPPLIED = 0x00000000;

        public const uint CRR_LIFETIME_LIMIT = 0xFFFFFFFF;

        public const uint CRR_ACTIVATION_LIMIT = 0xFFFFFFFE;

        public const uint CRR_CALL_LIMIT = 0xFFFFFFFD;

        public const uint CRR_MEMORY_LIMIT = 0xFFFFFFFC;

        public const uint CRR_RECYCLED_FROM_UI = 0xFFFFFFFB;

    }
}
