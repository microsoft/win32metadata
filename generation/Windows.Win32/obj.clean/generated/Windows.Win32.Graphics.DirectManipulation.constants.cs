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


namespace Windows.Win32.Graphics.DirectManipulation
{
    public static partial class Apis
    {
        public const uint DIRECTMANIPULATION_KEYBOARDFOCUS = 0xfffffffe;

        public const uint DIRECTMANIPULATION_MOUSEFOCUS = 0xfffffffd;

        public static readonly Guid CLSID_VerticalIndicatorContent__scanned__ = new Guid(0xa10b5f17, 0xafe0, 0x4aa2, 0x91, 0xe9, 0x3e, 0x70, 0x1, 0xd2, 0xe6, 0xb4);

        public static readonly Guid CLSID_HorizontalIndicatorContent__scanned__ = new Guid(0xe7d18cf5, 0x3ec7, 0x44d5, 0xa7, 0x6b, 0x37, 0x70, 0xf3, 0xcf, 0x90, 0x3d);

        public static readonly Guid CLSID_VirtualViewportContent__scanned__ = new Guid(0x3206a19a, 0x86f0, 0x4cb4, 0xa7, 0xf3, 0x16, 0xe3, 0xb7, 0xe2, 0xd8, 0x52);

        public static readonly Guid CLSID_DragDropConfigurationBehavior__scanned__ = new Guid(0x09b01b3e, 0xba6c, 0x454d, 0x82, 0xe8, 0x95, 0xe3, 0x52, 0x32, 0x9f, 0x23);

        public static readonly Guid CLSID_AutoScrollBehavior__scanned__ = new Guid(0x26126a51, 0x3c70, 0x4c9a, 0xae, 0xc2, 0x94, 0x88, 0x49, 0xee, 0xb0, 0x93);

        public static readonly Guid CLSID_DeferContactService__scanned__ = new Guid(0xd7b67cf4, 0x84bb, 0x434e, 0x86, 0xae, 0x65, 0x92, 0xbb, 0xc9, 0xab, 0xd9);

    }
}
