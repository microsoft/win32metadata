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


namespace Windows.Win32.UI.Wpf
{
    public static partial class Apis
    {
        public const uint MILBITMAPEFFECT_SDK_VERSION = 0x01000000;

        public static readonly Guid CLSID_MILBitmapEffectGroup__scanned__ = new Guid(0xac9c1a9a, 0x7e18, 0x4f64, 0xac, 0x7e, 0x47, 0xcf, 0x7f, 0x05, 0x1e, 0x95);

        public static readonly Guid CLSID_MILBitmapEffectBlur__scanned__ = new Guid(0xa924df87, 0x225d, 0x4373, 0x8f, 0x5b, 0xb9, 0xe, 0xc8, 0x5a, 0xe3, 0xde);

        public static readonly Guid CLSID_MILBitmapEffectDropShadow__scanned__ = new Guid(0x459a3fbe, 0xd8ac, 0x4692, 0x87, 0x4b, 0x7a, 0x26, 0x57, 0x15, 0xaa, 0x16);

        public static readonly Guid CLSID_MILBitmapEffectOuterGlow__scanned__ = new Guid(0xe2161bdd, 0x7eb6, 0x4725, 0x9c, 0x0b, 0x8a, 0x2a, 0x1b, 0x4f, 0x06, 0x67);

        public static readonly Guid CLSID_MILBitmapEffectBevel__scanned__ = new Guid(0xfd361dbe, 0x6c9b, 0x4de0, 0x82, 0x90, 0xf6, 0x40, 0xc, 0x27, 0x37, 0xed);

        public static readonly Guid CLSID_MILBitmapEffectEmboss__scanned__ = new Guid(0xcd299846, 0x824f, 0x47ec, 0xa0, 0x07, 0x12, 0xaa, 0x76, 0x7f, 0x28, 0x16);

    }
}
