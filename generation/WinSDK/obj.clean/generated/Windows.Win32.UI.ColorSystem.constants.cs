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


namespace Windows.Win32.UI.ColorSystem
{
    public static partial class Apis
    {
        public static readonly Guid CATID_WcsPlugin__scanned__ = new Guid(0xa0b402e0, 0x8240, 0x405f, 0x8a, 0x16, 0x8a, 0x5b, 0x4d, 0xf2, 0xf0, 0xdd);

        public const uint MAX_COLOR_CHANNELS = 8;

        public const uint INTENT_PERCEPTUAL = 0;

        public const uint INTENT_RELATIVE_COLORIMETRIC = 1;

        public const uint INTENT_SATURATION = 2;

        public const uint INTENT_ABSOLUTE_COLORIMETRIC = 3;

        public const uint FLAG_EMBEDDEDPROFILE = 0x00000001;

        public const uint FLAG_DEPENDENTONDATA = 0x00000002;

        public const uint FLAG_ENABLE_CHROMATIC_ADAPTATION = 0x02000000;

        public const uint ATTRIB_TRANSPARENCY = 0x00000001;

        public const uint ATTRIB_MATTE = 0x00000002;

        public const uint PROFILE_FILENAME = 1;

        public const uint PROFILE_MEMBUFFER = 2;

        public const uint PROFILE_READ = 1;

        public const uint PROFILE_READWRITE = 2;

        public const uint INDEX_DONT_CARE = 0;

        public const uint ENUM_TYPE_VERSION = 0x0300;

        public const uint ET_DEVICENAME = 0x00000001;

        public const uint ET_MEDIATYPE = 0x00000002;

        public const uint ET_DITHERMODE = 0x00000004;

        public const uint ET_RESOLUTION = 0x00000008;

        public const uint ET_CMMTYPE = 0x00000010;

        public const uint ET_CLASS = 0x00000020;

        public const uint ET_DATACOLORSPACE = 0x00000040;

        public const uint ET_CONNECTIONSPACE = 0x00000080;

        public const uint ET_SIGNATURE = 0x00000100;

        public const uint ET_PLATFORM = 0x00000200;

        public const uint ET_PROFILEFLAGS = 0x00000400;

        public const uint ET_MANUFACTURER = 0x00000800;

        public const uint ET_MODEL = 0x00001000;

        public const uint ET_ATTRIBUTES = 0x00002000;

        public const uint ET_RENDERINGINTENT = 0x00004000;

        public const uint ET_CREATOR = 0x00008000;

        public const uint ET_DEVICECLASS = 0x00010000;

        public const uint ET_STANDARDDISPLAYCOLOR = 0x00020000;

        public const uint ET_EXTENDEDDISPLAYCOLOR = 0x00040000;

        public const uint PROOF_MODE = 0x00000001;

        public const uint NORMAL_MODE = 0x00000002;

        public const uint BEST_MODE = 0x00000003;

        public const uint ENABLE_GAMUT_CHECKING = 0x00010000;

        public const uint USE_RELATIVE_COLORIMETRIC = 0x00020000;

        public const uint FAST_TRANSLATE = 0x00040000;

        public const uint PRESERVEBLACK = 0x00100000;

        public const uint WCS_ALWAYS = 0x00200000;

        public const uint SEQUENTIAL_TRANSFORM = 0x80800000;

        public const uint RESERVED = 0x80000000;

        public const uint CSA_A = 1;

        public const uint CSA_ABC = 2;

        public const uint CSA_DEF = 3;

        public const uint CSA_DEFG = 4;

        public const uint CSA_GRAY = 5;

        public const uint CSA_RGB = 6;

        public const uint CSA_CMYK = 7;

        public const uint CSA_Lab = 8;

        public const uint CMM_WIN_VERSION = 0;

        public const uint CMM_IDENT = 1;

        public const uint CMM_DRIVER_VERSION = 2;

        public const uint CMM_DLL_VERSION = 3;

        public const uint CMM_VERSION = 4;

        public const uint CMM_DESCRIPTION = 5;

        public const uint CMM_LOGOICON = 6;

        public const uint CMS_FORWARD = 0;

        public const uint CMS_BACKWARD = 1;

        public const uint COLOR_MATCH_VERSION = 0x0200;

        public const uint CMS_DISABLEICM = 1;

        public const uint CMS_ENABLEPROOFING = 2;

        public const uint CMS_SETRENDERINTENT = 4;

        public const uint CMS_SETPROOFINTENT = 8;

        public const uint CMS_SETMONITORPROFILE = 0x10;

        public const uint CMS_SETPRINTERPROFILE = 0x20;

        public const uint CMS_SETTARGETPROFILE = 0x40;

        public const uint CMS_USEHOOK = 0x80;

        public const uint CMS_USEAPPLYCALLBACK = 0x100;

        public const uint CMS_USEDESCRIPTION = 0x200;

        public const uint CMS_DISABLEINTENT = 0x400;

        public const uint CMS_DISABLERENDERINTENT = 0x800;

        public const int CMS_MONITOROVERFLOW = unchecked((int)0x80000000);

        public const int CMS_PRINTEROVERFLOW = 0x40000000;

        public const int CMS_TARGETOVERFLOW = 0x20000000;

        public const int DONT_USE_EMBEDDED_WCS_PROFILES = 0x00000001;

        public const int WCS_DEFAULT = 0x00000000;

        public const int WCS_ICCONLY = 0x00010000;

        public const uint COLORADAPTER_PROFILE_NAME_MAX_LENGTH = 80;

    }
}
