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


namespace Windows.Win32.Media.MediaPlayer
{
    public static partial class Apis
    {
        public static readonly Guid CLSID_XFeedsManager__scanned__ = new Guid(0xfe6b11c3, 0xc72e, 0x4061, 0x86, 0xc6, 0x9d, 0x16, 0x31, 0x21, 0xf2, 0x29);

        public const uint WMPGC_FLAGS_ALLOW_PREROLL = 0x00000001;

        public const uint WMPGC_FLAGS_SUPPRESS_DIALOGS = 0x00000002;

        public const uint WMPGC_FLAGS_IGNORE_AV_SYNC = 0x00000004;

        public const uint WMPGC_FLAGS_DISABLE_PLUGINS = 0x00000008;

        public const uint WMPGC_FLAGS_USE_CUSTOM_GRAPH = 0x00000010;

        public const uint WMPUE_EC_USER = EC_USER + 0x100;

        public const uint WMP_MDRT_FLAGS_UNREPORTED_DELETED_ITEMS = 0x00000001;

        public const uint WMP_MDRT_FLAGS_UNREPORTED_ADDED_ITEMS = 0x00000002;

        public const uint IOCTL_WMP_METADATA_ROUND_TRIP = 0x31504d57;

        public const uint IOCTL_WMP_DEVICE_CAN_SYNC = 0x32504d57;

        public const uint EFFECT_CANGOFULLSCREEN = 0x1;

        public const uint EFFECT_HASPROPERTYPAGE = 0x2;

        public const uint EFFECT_VARIABLEFREQSTEP = 0x4;

        public const uint EFFECT_WINDOWEDONLY = 0x8;

        public const uint EFFECT2_FULLSCREENEXCLUSIVE = 0x10;

        public const uint SA_BUFFER_SIZE = 1024;

        public const uint PLUGIN_TYPE_BACKGROUND = 0x1;

        public const uint PLUGIN_TYPE_SEPARATEWINDOW = 0x2;

        public const uint PLUGIN_TYPE_DISPLAYAREA = 0x3;

        public const uint PLUGIN_TYPE_SETTINGSAREA = 0x4;

        public const uint PLUGIN_TYPE_METADATAAREA = 0x5;

        public const uint PLUGIN_FLAGS_HASPROPERTYPAGE = 0x80000000;

        public const uint PLUGIN_FLAGS_INSTALLAUTORUN = 0x40000000;

        public const uint PLUGIN_FLAGS_LAUNCHPROPERTYPAGE = 0x20000000;

        public const uint PLUGIN_FLAGS_ACCEPTSMEDIA = 0x10000000;

        public const uint PLUGIN_FLAGS_ACCEPTSPLAYLISTS = 0x8000000;

        public const uint PLUGIN_FLAGS_HASPRESETS = 0x4000000;

        public const uint PLUGIN_FLAGS_HIDDEN = 0x2000000;

        public const uint SUBSCRIPTION_CAP_DEVICEAVAILABLE = 0x00000010;

        public const uint SUBSCRIPTION_CAP_BACKGROUNDPROCESSING = 0x00000008;

        public const uint SUBSCRIPTION_CAP_IS_CONTENTPARTNER = 0x00000040;

        public const uint SUBSCRIPTION_CAP_ALTLOGIN = 0x00000080;

        public const uint SUBSCRIPTION_CAP_ALLOWPLAY = 0x00000001;

        public const uint SUBSCRIPTION_CAP_ALLOWCDBURN = 0x00000002;

        public const uint SUBSCRIPTION_CAP_ALLOWPDATRANSFER = 0x00000004;

        public const uint SUBSCRIPTION_CAP_PREPAREFORSYNC = 0x00000020;

        public const uint SUBSCRIPTION_V1_CAPS = 0x0000000F;

        public const uint SUBSCRIPTION_CAP_UILESSMODE_ALLOWPLAY = 0x00000100;

    }
}
