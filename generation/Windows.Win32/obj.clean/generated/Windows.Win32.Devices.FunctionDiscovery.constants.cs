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


namespace Windows.Win32.Devices.FunctionDiscovery
{
    public static partial class Apis
    {
        public const uint FD_EVENTID_PRIVATE = 100;

        public const uint FD_EVENTID = 1000;

        public const uint FD_EVENTID_ASYNCTHREADEXIT = FD_EVENTID + 1;

        public const uint FD_EVENTID_SEARCHSTART = FD_EVENTID + 2;

        public const uint FD_EVENTID_IPADDRESSCHANGE = FD_EVENTID + 3;

        public const uint FD_EVENTID_QUERYREFRESH = FD_EVENTID + 4;

        public static readonly Guid SID_PnpProvider__scanned__ = new Guid(0x8101368e, 0xcabb, 0x4426, 0xac, 0xff, 0x96, 0xc4, 0x10, 0x81, 0x20, 0x00);

        public static readonly Guid SID_UPnPActivator__scanned__ = new Guid(0x0D0D66EB, 0xCF74, 0x4164, 0xB5, 0x2F, 0x08, 0x34, 0x46, 0x72, 0xDD, 0x46);

        public static readonly Guid SID_EnumInterface__scanned__ = new Guid(0x40eab0b9, 0x4d7f, 0x4b53, 0xa3, 0x34, 0x15, 0x81, 0xdd, 0x90, 0x41, 0xf4);

        public static readonly Guid SID_PNPXPropertyStore__scanned__ = new Guid(0xa86530b1, 0x542f, 0x439f, 0xB7, 0x1c, 0xb0, 0x75, 0x6b, 0x13, 0x67, 0x7a);

        public static readonly Guid SID_PNPXAssociation__scanned__ = new Guid(0xcee8ccc9, 0x4f6b, 0x4469, 0xa2, 0x35, 0x5a, 0x22, 0x86, 0x9e, 0xef, 0x03);

        public static readonly Guid SID_PNPXServiceCollection__scanned__ = new Guid(0x439e80ee, 0xa217, 0x4712, 0x9f, 0xa6, 0xde, 0xab, 0xd9, 0xc2, 0xa7, 0x27);

        public static readonly Guid SID_FDPairingHandler__scanned__ = new Guid(0x383b69fa, 0x5486, 0x49da, 0x91, 0xf5, 0xd6, 0x3c, 0x24, 0xc8, 0xe9, 0xd0);

        public static readonly Guid SID_EnumDeviceFunction__scanned__ = new Guid(0x13e0e9e2, 0xc3fa, 0x4e3c, 0x90, 0x6e, 0x64, 0x50, 0x2f, 0xa4, 0xdc, 0x95);

        public static readonly Guid SID_UnpairProvider__scanned__ = new Guid(0x89A502FC,0x857B,0x4698,0xA0,0xB7,0x02,0x71,0x92,0x00,0x2F,0x9E);

        public static readonly Guid SID_DeviceDisplayStatusManager__scanned__ = new Guid(0xf59aa553, 0x8309, 0x46ca, 0x97, 0x36, 0x1a, 0xc3, 0xc6, 0x2d, 0x60, 0x31);

        public static readonly Guid SID_FunctionDiscoveryProviderRefresh__scanned__ = new Guid(0x2b4cbdc9, 0x31c4, 0x40d4, 0xa6, 0x2d, 0x77, 0x2a, 0xa1, 0x74, 0xed, 0x52);

        public static readonly Guid SID_UninstallDeviceFunction__scanned__ = new Guid(0xc920566e, 0x5671, 0x4496, 0x80, 0x25, 0xbf, 0x0b, 0x89, 0xbd, 0x44, 0xcd);

        public static readonly Guid FMTID_FD__scanned__ = new Guid(0x904b03a2, 0x471d, 0x423c, 0xa5, 0x84, 0xf3, 0x48, 0x32, 0x38, 0xa1, 0x46);

        public const uint FD_Visibility_Default = 0;

        public const uint FD_Visibility_Hidden = 1;

        public static readonly Guid FMTID_Device__scanned__ = new Guid(0x78c34fc8, 0x104a, 0x4aca, 0x9e, 0xa4, 0x52, 0x4d, 0x52, 0x99, 0x6e, 0x57);

        public static readonly Guid FMTID_DeviceInterface__scanned__ = new Guid(0x53808008, 0x07BB, 0x4661, 0xBC, 0x3C, 0xB5, 0x95, 0x3E, 0x70, 0x85, 0x60);

        public static readonly Guid FMTID_Pairing__scanned__ = new Guid(0x8807cae6, 0x7db6, 0x4f10, 0x8e, 0xe4, 0x43, 0x5e, 0xaa, 0x13, 0x92, 0xbc);

        public static readonly Guid FMTID_WSD__scanned__ = new Guid(0x92506491, 0xFF95, 0x4724, 0xA0, 0x5A, 0x5B, 0x81, 0x88, 0x5A, 0x7C, 0x92);

        public static readonly Guid FMTID_PNPX__scanned__ = new Guid(0x656A3BB3, 0xECC0, 0x43FD, 0x84, 0x77, 0x4A, 0xE0, 0x40, 0x4A, 0x96, 0xCD);

        public static readonly Guid FMTID_PNPXDynamicProperty__scanned__ = new Guid(0x4FC5077E, 0xB686, 0x44BE, 0x93, 0xE3, 0x86, 0xCA, 0xFE, 0x36, 0x8C, 0xCD);

        public const uint PNPX_INSTALLSTATE_NOTINSTALLED = 0;

        public const uint PNPX_INSTALLSTATE_INSTALLED = 1;

        public const uint PNPX_INSTALLSTATE_INSTALLING = 2;

        public const uint PNPX_INSTALLSTATE_FAILED = 3;

        public const uint FD_LONGHORN = 1;

    }
}
