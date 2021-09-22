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


namespace Windows.Win32.Devices.HumanInterfaceDevice
{
    public static partial class Apis
    {
        public const uint DIRECTINPUT_VERSION = 0x0800;

        public static readonly Guid IID_IDirectInputEffectDriver__scanned__ = new Guid(0x02538130,0x898F,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid IID_IDirectInputJoyConfig__scanned__ = new Guid(0x1DE12AB1,0xC9F5,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputPIDDriver__scanned__ = new Guid(0xEEC6993A,0xB3FD,0x11D2,0xA9,0x16,0x00,0xC0,0x4F,0xB9,0x86,0x38);

        public static readonly Guid IID_IDirectInputJoyConfig8__scanned__ = new Guid(0xeb0d7dfa,0x1990,0x4f27,0xb4,0xd6,0xed,0xf2,0xee,0xc4,0xa4,0x4c);

        public const uint JOY_HW_NONE = 0;

        public const uint JOY_HW_CUSTOM = 1;

        public const uint JOY_HW_2A_2B_GENERIC = 2;

        public const uint JOY_HW_2A_4B_GENERIC = 3;

        public const uint JOY_HW_2B_GAMEPAD = 4;

        public const uint JOY_HW_2B_FLIGHTYOKE = 5;

        public const uint JOY_HW_2B_FLIGHTYOKETHROTTLE = 6;

        public const uint JOY_HW_3A_2B_GENERIC = 7;

        public const uint JOY_HW_3A_4B_GENERIC = 8;

        public const uint JOY_HW_4B_GAMEPAD = 9;

        public const uint JOY_HW_4B_FLIGHTYOKE = 10;

        public const uint JOY_HW_4B_FLIGHTYOKETHROTTLE = 11;

        public const uint JOY_HW_TWO_2A_2B_WITH_Y = 12;

        public const uint JOY_HW_LASTENTRY = 13;

        public const int JOY_ISCAL_XY = 0x00000001;

        public const int JOY_ISCAL_Z = 0x00000002;

        public const int JOY_ISCAL_R = 0x00000004;

        public const int JOY_ISCAL_U = 0x00000008;

        public const int JOY_ISCAL_V = 0x00000010;

        public const int JOY_ISCAL_POV = 0x00000020;

        public const uint JOY_POV_NUMDIRS = 4;

        public const uint JOY_POVVAL_FORWARD = 0;

        public const uint JOY_POVVAL_BACKWARD = 1;

        public const uint JOY_POVVAL_LEFT = 2;

        public const uint JOY_POVVAL_RIGHT = 3;

        public const int JOY_HWS_HASZ = 0x00000001;

        public const int JOY_HWS_HASPOV = 0x00000002;

        public const int JOY_HWS_POVISBUTTONCOMBOS = 0x00000004;

        public const int JOY_HWS_POVISPOLL = 0x00000008;

        public const int JOY_HWS_ISYOKE = 0x00000010;

        public const int JOY_HWS_ISGAMEPAD = 0x00000020;

        public const int JOY_HWS_ISCARCTRL = 0x00000040;

        public const int JOY_HWS_XISJ1Y = 0x00000080;

        public const int JOY_HWS_XISJ2X = 0x00000100;

        public const int JOY_HWS_XISJ2Y = 0x00000200;

        public const int JOY_HWS_YISJ1X = 0x00000400;

        public const int JOY_HWS_YISJ2X = 0x00000800;

        public const int JOY_HWS_YISJ2Y = 0x00001000;

        public const int JOY_HWS_ZISJ1X = 0x00002000;

        public const int JOY_HWS_ZISJ1Y = 0x00004000;

        public const int JOY_HWS_ZISJ2X = 0x00008000;

        public const int JOY_HWS_POVISJ1X = 0x00010000;

        public const int JOY_HWS_POVISJ1Y = 0x00020000;

        public const int JOY_HWS_POVISJ2X = 0x00040000;

        public const int JOY_HWS_HASR = 0x00080000;

        public const int JOY_HWS_RISJ1X = 0x00100000;

        public const int JOY_HWS_RISJ1Y = 0x00200000;

        public const int JOY_HWS_RISJ2Y = 0x00400000;

        public const int JOY_HWS_HASU = 0x00800000;

        public const int JOY_HWS_HASV = 0x01000000;

        public const int JOY_US_HASRUDDER = 0x00000001;

        public const int JOY_US_PRESENT = 0x00000002;

        public const int JOY_US_ISOEM = 0x00000004;

        public const int JOY_US_RESERVED = unchecked((int)0x80000000);

        public const int JOYTYPE_ZEROGAMEENUMOEMDATA = 0x00000001;

        public const int JOYTYPE_NOAUTODETECTGAMEPORT = 0x00000002;

        public const int JOYTYPE_NOHIDDIRECT = 0x00000004;

        public const int JOYTYPE_ANALOGCOMPAT = 0x00000008;

        public const int JOYTYPE_DEFAULTPROPSHEET = unchecked((int)0x80000000);

        public const int JOYTYPE_DEVICEHIDE = 0x00010000;

        public const int JOYTYPE_MOUSEHIDE = 0x00020000;

        public const int JOYTYPE_KEYBHIDE = 0x00040000;

        public const int JOYTYPE_GAMEHIDE = 0x00080000;

        public const int JOYTYPE_HIDEACTIVE = 0x00100000;

        public const int JOYTYPE_INFOMASK = 0x00E00000;

        public const int JOYTYPE_INFODEFAULT = 0x00000000;

        public const int JOYTYPE_INFOYYPEDALS = 0x00200000;

        public const int JOYTYPE_INFOZYPEDALS = 0x00400000;

        public const int JOYTYPE_INFOYRPEDALS = 0x00600000;

        public const int JOYTYPE_INFOZRPEDALS = 0x00800000;

        public const int JOYTYPE_INFOZISSLIDER = 0x00200000;

        public const int JOYTYPE_INFOZISZ = 0x00400000;

        public const int JOYTYPE_ENABLEINPUTREPORT = 0x01000000;

        public const uint MAX_JOYSTRING = 256;

        public const uint MAX_JOYSTICKOEMVXDNAME = 260;

        public const uint DITC_REGHWSETTINGS = 0x00000001;

        public const uint DITC_CLSIDCONFIG = 0x00000002;

        public const uint DITC_DISPLAYNAME = 0x00000004;

        public const uint DITC_CALLOUT = 0x00000008;

        public const uint DITC_HARDWAREID = 0x00000010;

        public const uint DITC_FLAGS1 = 0x00000020;

        public const uint DITC_FLAGS2 = 0x00000040;

        public const uint DITC_MAPFILE = 0x00000080;

        public const uint DIJC_GUIDINSTANCE = 0x00000001;

        public const uint DIJC_REGHWCONFIGTYPE = 0x00000002;

        public const uint DIJC_GAIN = 0x00000004;

        public const uint DIJC_CALLOUT = 0x00000008;

        public const uint DIJC_WDMGAMEPORT = 0x00000010;

        public const uint DIJU_USERVALUES = 0x00000001;

        public const uint DIJU_GLOBALDRIVER = 0x00000002;

        public const uint DIJU_GAMEPORTEMULATOR = 0x00000004;

        public static readonly Guid GUID_KeyboardClass__scanned__ = new Guid(0x4D36E96B,0xE325,0x11CE,0xBF,0xC1,0x08,0x00,0x2B,0xE1,0x03,0x18);

        public static readonly Guid GUID_MediaClass__scanned__ = new Guid(0x4D36E96C,0xE325,0x11CE,0xBF,0xC1,0x08,0x00,0x2B,0xE1,0x03,0x18);

        public static readonly Guid GUID_MouseClass__scanned__ = new Guid(0x4D36E96F,0xE325,0x11CE,0xBF,0xC1,0x08,0x00,0x2B,0xE1,0x03,0x18);

        public static readonly Guid GUID_HIDClass__scanned__ = new Guid(0x745A17A0,0x74D3,0x11D0,0xB6,0xFE,0x00,0xA0,0xC9,0x0F,0x57,0xDA);

        public const uint DIMSGWP_NEWAPPSTART = 0x00000001;

        public const uint DIMSGWP_DX8APPSTART = 0x00000002;

        public const uint DIMSGWP_DX8MAPPERAPPSTART = 0x00000003;

        public const uint DIAPPIDFLAG_NOTIME = 0x00000001;

        public const uint DIAPPIDFLAG_NOSIZE = 0x00000002;

        [NativeTypeName("HRESULT")]
        public const int DIERR_NOMOREITEMS = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_NO_MORE_ITEMS));

        public const int DIERR_DRIVERFIRST = unchecked((int)0x80040300);

        public const int DIERR_DRIVERLAST = unchecked((int)0x800403FF);

        public const int DIERR_INVALIDCLASSINSTALLER = unchecked((int)0x80040400);

        public const int DIERR_CANCELLED = unchecked((int)0x80040401);

        public const int DIERR_BADINF = unchecked((int)0x80040402);

        public const uint DIDIFT_DELETE = 0x01000000;

        public static readonly Guid GUID_DEVINTERFACE_HID__scanned__ = new Guid(0x4D1E55B2L, 0xF16F, 0x11CF, 0x88, 0xCB, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30);

        public static readonly Guid GUID_HID_INTERFACE_NOTIFY__scanned__ = new Guid(0x2c4e2e88L, 0x25e6, 0x4c33, 0x88, 0x2f, 0x3d, 0x82, 0xe6, 0x07, 0x36, 0x81 );

        public static readonly Guid GUID_HID_INTERFACE_HIDPARSE__scanned__ = new Guid(0xf5c315a5, 0x69ac, 0x4bc2, 0x92, 0x79, 0xd0, 0xb6, 0x45, 0x76, 0xf4, 0x4b );

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 2)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_UsagePage;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 3)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_UsageId;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 4)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_IsReadOnly;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 5)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_VendorId;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 6)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_ProductId;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 7)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_VersionNumber;

        [PropertyKey(0xcbf38310, 0x4a17, 0x4310, 0xa1, 0xeb, 0x24, 0x7f, 0xb, 0x67, 0x59, 0x3b, 8)]
        public static readonly PROPERTYKEY DEVPKEY_DeviceInterface_HID_BackgroundAccess;

        public const uint HID_REVISION = 0x00000001;

        public const ushort HID_USAGE_PAGE_UNDEFINED = 0x00;

        public const ushort HID_USAGE_PAGE_GENERIC = 0x01;

        public const ushort HID_USAGE_PAGE_SIMULATION = 0x02;

        public const ushort HID_USAGE_PAGE_VR = 0x03;

        public const ushort HID_USAGE_PAGE_SPORT = 0x04;

        public const ushort HID_USAGE_PAGE_GAME = 0x05;

        public const ushort HID_USAGE_PAGE_GENERIC_DEVICE = 0x06;

        public const ushort HID_USAGE_PAGE_KEYBOARD = 0x07;

        public const ushort HID_USAGE_PAGE_LED = 0x08;

        public const ushort HID_USAGE_PAGE_BUTTON = 0x09;

        public const ushort HID_USAGE_PAGE_ORDINAL = 0x0A;

        public const ushort HID_USAGE_PAGE_TELEPHONY = 0x0B;

        public const ushort HID_USAGE_PAGE_CONSUMER = 0x0C;

        public const ushort HID_USAGE_PAGE_DIGITIZER = 0x0D;

        public const ushort HID_USAGE_PAGE_HAPTICS = 0x0E;

        public const ushort HID_USAGE_PAGE_PID = 0x0F;

        public const ushort HID_USAGE_PAGE_UNICODE = 0x10;

        public const ushort HID_USAGE_PAGE_ALPHANUMERIC = 0x14;

        public const ushort HID_USAGE_PAGE_SENSOR = 0x20;

        public const ushort HID_USAGE_PAGE_LIGHTING_ILLUMINATION = 0x59;

        public const ushort HID_USAGE_PAGE_BARCODE_SCANNER = 0x8C;

        public const ushort HID_USAGE_PAGE_WEIGHING_DEVICE = 0x8D;

        public const ushort HID_USAGE_PAGE_MAGNETIC_STRIPE_READER = 0x8E;

        public const ushort HID_USAGE_PAGE_CAMERA_CONTROL = 0x90;

        public const ushort HID_USAGE_PAGE_ARCADE = 0x91;

        public const ushort HID_USAGE_PAGE_MICROSOFT_BLUETOOTH_HANDSFREE = 0xFFF3;

        public const ushort HID_USAGE_PAGE_VENDOR_DEFINED_BEGIN = 0xFF00;

        public const ushort HID_USAGE_PAGE_VENDOR_DEFINED_END = 0xFFFF;

        public const ushort HID_USAGE_GENERIC_POINTER = 0x01;

        public const ushort HID_USAGE_GENERIC_MOUSE = 0x02;

        public const ushort HID_USAGE_GENERIC_JOYSTICK = 0x04;

        public const ushort HID_USAGE_GENERIC_GAMEPAD = 0x05;

        public const ushort HID_USAGE_GENERIC_KEYBOARD = 0x06;

        public const ushort HID_USAGE_GENERIC_KEYPAD = 0x07;

        public const ushort HID_USAGE_GENERIC_MULTI_AXIS_CONTROLLER = 0x08;

        public const ushort HID_USAGE_GENERIC_TABLET_PC_SYSTEM_CTL = 0x09;

        public const ushort HID_USAGE_GENERIC_PORTABLE_DEVICE_CONTROL = 0x0D;

        public const ushort HID_USAGE_GENERIC_INTERACTIVE_CONTROL = 0x0E;

        public const ushort HID_USAGE_GENERIC_COUNTED_BUFFER = 0x3A;

        public const ushort HID_USAGE_GENERIC_SYSTEM_CTL = 0x80;

        public const ushort HID_USAGE_GENERIC_X = 0x30;

        public const ushort HID_USAGE_GENERIC_Y = 0x31;

        public const ushort HID_USAGE_GENERIC_Z = 0x32;

        public const ushort HID_USAGE_GENERIC_RX = 0x33;

        public const ushort HID_USAGE_GENERIC_RY = 0x34;

        public const ushort HID_USAGE_GENERIC_RZ = 0x35;

        public const ushort HID_USAGE_GENERIC_SLIDER = 0x36;

        public const ushort HID_USAGE_GENERIC_DIAL = 0x37;

        public const ushort HID_USAGE_GENERIC_WHEEL = 0x38;

        public const ushort HID_USAGE_GENERIC_HATSWITCH = 0x39;

        public const ushort HID_USAGE_GENERIC_BYTE_COUNT = 0x3B;

        public const ushort HID_USAGE_GENERIC_MOTION_WAKEUP = 0x3C;

        public const ushort HID_USAGE_GENERIC_START = 0x3D;

        public const ushort HID_USAGE_GENERIC_SELECT = 0x3E;

        public const ushort HID_USAGE_GENERIC_VX = 0x40;

        public const ushort HID_USAGE_GENERIC_VY = 0x41;

        public const ushort HID_USAGE_GENERIC_VZ = 0x42;

        public const ushort HID_USAGE_GENERIC_VBRX = 0x43;

        public const ushort HID_USAGE_GENERIC_VBRY = 0x44;

        public const ushort HID_USAGE_GENERIC_VBRZ = 0x45;

        public const ushort HID_USAGE_GENERIC_VNO = 0x46;

        public const ushort HID_USAGE_GENERIC_FEATURE_NOTIFICATION = 0x47;

        public const ushort HID_USAGE_GENERIC_RESOLUTION_MULTIPLIER = 0x48;

        public const ushort HID_USAGE_GENERIC_SYSCTL_POWER = 0x81;

        public const ushort HID_USAGE_GENERIC_SYSCTL_SLEEP = 0x82;

        public const ushort HID_USAGE_GENERIC_SYSCTL_WAKE = 0x83;

        public const ushort HID_USAGE_GENERIC_SYSCTL_CONTEXT_MENU = 0x84;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MAIN_MENU = 0x85;

        public const ushort HID_USAGE_GENERIC_SYSCTL_APP_MENU = 0x86;

        public const ushort HID_USAGE_GENERIC_SYSCTL_HELP_MENU = 0x87;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_EXIT = 0x88;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_SELECT = 0x89;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_RIGHT = 0x8A;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_LEFT = 0x8B;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_UP = 0x8C;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MENU_DOWN = 0x8D;

        public const ushort HID_USAGE_GENERIC_SYSCTL_COLD_RESTART = 0x8E;

        public const ushort HID_USAGE_GENERIC_SYSCTL_WARM_RESTART = 0x8F;

        public const ushort HID_USAGE_GENERIC_DPAD_UP = 0x90;

        public const ushort HID_USAGE_GENERIC_DPAD_DOWN = 0x91;

        public const ushort HID_USAGE_GENERIC_DPAD_RIGHT = 0x92;

        public const ushort HID_USAGE_GENERIC_DPAD_LEFT = 0x93;

        public const ushort HID_USAGE_GENERIC_SYSCTL_FN = 0x97;

        public const ushort HID_USAGE_GENERIC_SYSCTL_FN_LOCK = 0x98;

        public const ushort HID_USAGE_GENERIC_SYSCTL_FN_LOCK_INDICATOR = 0x99;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISMISS_NOTIFICATION = 0x9A;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DOCK = 0xA0;

        public const ushort HID_USAGE_GENERIC_SYSCTL_UNDOCK = 0xA1;

        public const ushort HID_USAGE_GENERIC_SYSCTL_SETUP = 0xA2;

        public const ushort HID_USAGE_GENERIC_SYSCTL_SYS_BREAK = 0xA3;

        public const ushort HID_USAGE_GENERIC_SYSCTL_SYS_DBG_BREAK = 0xA4;

        public const ushort HID_USAGE_GENERIC_SYSCTL_APP_BREAK = 0xA5;

        public const ushort HID_USAGE_GENERIC_SYSCTL_APP_DBG_BREAK = 0xA6;

        public const ushort HID_USAGE_GENERIC_SYSCTL_MUTE = 0xA7;

        public const ushort HID_USAGE_GENERIC_SYSCTL_HIBERNATE = 0xA8;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_INVERT = 0xB0;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_INTERNAL = 0xB1;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_EXTERNAL = 0xB2;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_BOTH = 0xB3;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_DUAL = 0xB4;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_TOGGLE = 0xB5;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_SWAP = 0xB6;

        public const ushort HID_USAGE_GENERIC_SYSCTL_DISP_AUTOSCALE = 0xB7;

        public const ushort HID_USAGE_GENERIC_SYSTEM_DISPLAY_ROTATION_LOCK_BUTTON = 0xC9;

        public const ushort HID_USAGE_GENERIC_SYSTEM_DISPLAY_ROTATION_LOCK_SLIDER_SWITCH = 0xCA;

        public const ushort HID_USAGE_GENERIC_CONTROL_ENABLE = 0xCB;

        public const ushort HID_USAGE_SIMULATION_FLIGHT_SIMULATION_DEVICE = 0x01;

        public const ushort HID_USAGE_SIMULATION_AUTOMOBILE_SIMULATION_DEVICE = 0x02;

        public const ushort HID_USAGE_SIMULATION_TANK_SIMULATION_DEVICE = 0x03;

        public const ushort HID_USAGE_SIMULATION_SPACESHIP_SIMULATION_DEVICE = 0x04;

        public const ushort HID_USAGE_SIMULATION_SUBMARINE_SIMULATION_DEVICE = 0x05;

        public const ushort HID_USAGE_SIMULATION_SAILING_SIMULATION_DEVICE = 0x06;

        public const ushort HID_USAGE_SIMULATION_MOTORCYCLE_SIMULATION_DEVICE = 0x07;

        public const ushort HID_USAGE_SIMULATION_SPORTS_SIMULATION_DEVICE = 0x08;

        public const ushort HID_USAGE_SIMULATION_AIRPLANE_SIMULATION_DEVICE = 0x09;

        public const ushort HID_USAGE_SIMULATION_HELICOPTER_SIMULATION_DEVICE = 0x0A;

        public const ushort HID_USAGE_SIMULATION_MAGIC_CARPET_SIMULATION_DEVICE = 0x0B;

        public const ushort HID_USAGE_SIMULATION_BICYCLE_SIMULATION_DEVICE = 0x0C;

        public const ushort HID_USAGE_SIMULATION_FLIGHT_CONTROL_STICK = 0x20;

        public const ushort HID_USAGE_SIMULATION_FLIGHT_STICK = 0x21;

        public const ushort HID_USAGE_SIMULATION_CYCLIC_CONTROL = 0x22;

        public const ushort HID_USAGE_SIMULATION_CYCLIC_TRIM = 0x23;

        public const ushort HID_USAGE_SIMULATION_FLIGHT_YOKE = 0x24;

        public const ushort HID_USAGE_SIMULATION_TRACK_CONTROL = 0x25;

        public const ushort HID_USAGE_SIMULATION_AILERON = 0xB0;

        public const ushort HID_USAGE_SIMULATION_AILERON_TRIM = 0xB1;

        public const ushort HID_USAGE_SIMULATION_ANTI_TORQUE_CONTROL = 0xB2;

        public const ushort HID_USAGE_SIMULATION_AUTOPIOLOT_ENABLE = 0xB3;

        public const ushort HID_USAGE_SIMULATION_CHAFF_RELEASE = 0xB4;

        public const ushort HID_USAGE_SIMULATION_COLLECTIVE_CONTROL = 0xB5;

        public const ushort HID_USAGE_SIMULATION_DIVE_BRAKE = 0xB6;

        public const ushort HID_USAGE_SIMULATION_ELECTRONIC_COUNTERMEASURES = 0xB7;

        public const ushort HID_USAGE_SIMULATION_ELEVATOR = 0xB8;

        public const ushort HID_USAGE_SIMULATION_ELEVATOR_TRIM = 0xB9;

        public const ushort HID_USAGE_SIMULATION_RUDDER = 0xBA;

        public const ushort HID_USAGE_SIMULATION_THROTTLE = 0xBB;

        public const ushort HID_USAGE_SIMULATION_FLIGHT_COMMUNICATIONS = 0xBC;

        public const ushort HID_USAGE_SIMULATION_FLARE_RELEASE = 0xBD;

        public const ushort HID_USAGE_SIMULATION_LANDING_GEAR = 0xBE;

        public const ushort HID_USAGE_SIMULATION_TOE_BRAKE = 0xBF;

        public const ushort HID_USAGE_SIMULATION_TRIGGER = 0xC0;

        public const ushort HID_USAGE_SIMULATION_WEAPONS_ARM = 0xC1;

        public const ushort HID_USAGE_SIMULATION_WEAPONS_SELECT = 0xC2;

        public const ushort HID_USAGE_SIMULATION_WING_FLAPS = 0xC3;

        public const ushort HID_USAGE_SIMULATION_ACCELLERATOR = 0xC4;

        public const ushort HID_USAGE_SIMULATION_BRAKE = 0xC5;

        public const ushort HID_USAGE_SIMULATION_CLUTCH = 0xC6;

        public const ushort HID_USAGE_SIMULATION_SHIFTER = 0xC7;

        public const ushort HID_USAGE_SIMULATION_STEERING = 0xC8;

        public const ushort HID_USAGE_SIMULATION_TURRET_DIRECTION = 0xC9;

        public const ushort HID_USAGE_SIMULATION_BARREL_ELEVATION = 0xCA;

        public const ushort HID_USAGE_SIMULATION_DIVE_PLANE = 0xCB;

        public const ushort HID_USAGE_SIMULATION_BALLAST = 0xCC;

        public const ushort HID_USAGE_SIMULATION_BICYCLE_CRANK = 0xCD;

        public const ushort HID_USAGE_SIMULATION_HANDLE_BARS = 0xCE;

        public const ushort HID_USAGE_SIMULATION_FRONT_BRAKE = 0xCF;

        public const ushort HID_USAGE_SIMULATION_REAR_BRAKE = 0xD0;

        public const ushort HID_USAGE_VR_BELT = 0x01;

        public const ushort HID_USAGE_VR_BODY_SUIT = 0x02;

        public const ushort HID_USAGE_VR_FLEXOR = 0x03;

        public const ushort HID_USAGE_VR_GLOVE = 0x04;

        public const ushort HID_USAGE_VR_HEAD_TRACKER = 0x05;

        public const ushort HID_USAGE_VR_HEAD_MOUNTED_DISPLAY = 0x06;

        public const ushort HID_USAGE_VR_HAND_TRACKER = 0x07;

        public const ushort HID_USAGE_VR_OCULOMETER = 0x08;

        public const ushort HID_USAGE_VR_VEST = 0x09;

        public const ushort HID_USAGE_VR_ANIMATRONIC_DEVICE = 0x0A;

        public const ushort HID_USAGE_VR_STEREO_ENABLE = 0x20;

        public const ushort HID_USAGE_VR_DISPLAY_ENABLE = 0x21;

        public const ushort HID_USAGE_SPORT_BASEBALL_BAT = 0x01;

        public const ushort HID_USAGE_SPORT_GOLF_CLUB = 0x02;

        public const ushort HID_USAGE_SPORT_ROWING_MACHINE = 0x03;

        public const ushort HID_USAGE_SPORT_TREADMILL = 0x04;

        public const ushort HID_USAGE_SPORT_STICK_TYPE = 0x38;

        public const ushort HID_USAGE_SPORT_OAR = 0x30;

        public const ushort HID_USAGE_SPORT_SLOPE = 0x31;

        public const ushort HID_USAGE_SPORT_RATE = 0x32;

        public const ushort HID_USAGE_SPORT_STICK_SPEED = 0x33;

        public const ushort HID_USAGE_SPORT_STICK_FACE_ANGLE = 0x34;

        public const ushort HID_USAGE_SPORT_HEEL_TOE = 0x35;

        public const ushort HID_USAGE_SPORT_FOLLOW_THROUGH = 0x36;

        public const ushort HID_USAGE_SPORT_TEMPO = 0x37;

        public const ushort HID_USAGE_SPORT_HEIGHT = 0x39;

        public const ushort HID_USAGE_SPORT_PUTTER = 0x50;

        public const ushort HID_USAGE_SPORT_1_IRON = 0x51;

        public const ushort HID_USAGE_SPORT_2_IRON = 0x52;

        public const ushort HID_USAGE_SPORT_3_IRON = 0x53;

        public const ushort HID_USAGE_SPORT_4_IRON = 0x54;

        public const ushort HID_USAGE_SPORT_5_IRON = 0x55;

        public const ushort HID_USAGE_SPORT_6_IRON = 0x56;

        public const ushort HID_USAGE_SPORT_7_IRON = 0x57;

        public const ushort HID_USAGE_SPORT_8_IRON = 0x58;

        public const ushort HID_USAGE_SPORT_9_IRON = 0x59;

        public const ushort HID_USAGE_SPORT_10_IRON = 0x5A;

        public const ushort HID_USAGE_SPORT_11_IRON = 0x5B;

        public const ushort HID_USAGE_SPORT_SAND_WEDGE = 0x5C;

        public const ushort HID_USAGE_SPORT_LOFT_WEDGE = 0x5D;

        public const ushort HID_USAGE_SPORT_POWER_WEDGE = 0x5E;

        public const ushort HID_USAGE_SPORT_1_WOOD = 0x5F;

        public const ushort HID_USAGE_SPORT_3_WOOD = 0x60;

        public const ushort HID_USAGE_SPORT_5_WOOD = 0x61;

        public const ushort HID_USAGE_SPORT_7_WOOD = 0x62;

        public const ushort HID_USAGE_SPORT_9_WOOD = 0x63;

        public const ushort HID_USAGE_GAME_3D_GAME_CONTROLLER = 0x01;

        public const ushort HID_USAGE_GAME_PINBALL_DEVICE = 0x02;

        public const ushort HID_USAGE_GAME_GUN_DEVICE = 0x03;

        public const ushort HID_USAGE_GAME_POINT_OF_VIEW = 0x20;

        public const ushort HID_USAGE_GAME_GUN_SELECTOR = 0x32;

        public const ushort HID_USAGE_GAME_GAMEPAD_FIRE_JUMP = 0x37;

        public const ushort HID_USAGE_GAME_GAMEPAD_TRIGGER = 0x39;

        public const ushort HID_USAGE_GAME_TURN_RIGHT_LEFT = 0x21;

        public const ushort HID_USAGE_GAME_PITCH_FORWARD_BACK = 0x22;

        public const ushort HID_USAGE_GAME_ROLL_RIGHT_LEFT = 0x23;

        public const ushort HID_USAGE_GAME_MOVE_RIGHT_LEFT = 0x24;

        public const ushort HID_USAGE_GAME_MOVE_FORWARD_BACK = 0x25;

        public const ushort HID_USAGE_GAME_MOVE_UP_DOWN = 0x26;

        public const ushort HID_USAGE_GAME_LEAN_RIGHT_LEFT = 0x27;

        public const ushort HID_USAGE_GAME_LEAN_FORWARD_BACK = 0x28;

        public const ushort HID_USAGE_GAME_POV_HEIGHT = 0x29;

        public const ushort HID_USAGE_GAME_FLIPPER = 0x2A;

        public const ushort HID_USAGE_GAME_SECONDARY_FLIPPER = 0x2B;

        public const ushort HID_USAGE_GAME_BUMP = 0x2C;

        public const ushort HID_USAGE_GAME_NEW_GAME = 0x2D;

        public const ushort HID_USAGE_GAME_SHOOT_BALL = 0x2E;

        public const ushort HID_USAGE_GAME_PLAYER = 0x2F;

        public const ushort HID_USAGE_GAME_GUN_BOLT = 0x30;

        public const ushort HID_USAGE_GAME_GUN_CLIP = 0x31;

        public const ushort HID_USAGE_GAME_GUN_SINGLE_SHOT = 0x33;

        public const ushort HID_USAGE_GAME_GUN_BURST = 0x34;

        public const ushort HID_USAGE_GAME_GUN_AUTOMATIC = 0x35;

        public const ushort HID_USAGE_GAME_GUN_SAFETY = 0x36;

        public const ushort HID_USAGE_GENERIC_DEVICE_BATTERY_STRENGTH = 0x20;

        public const ushort HID_USAGE_GENERIC_DEVICE_WIRELESS_CHANNEL = 0x21;

        public const ushort HID_USAGE_GENERIC_DEVICE_WIRELESS_ID = 0x22;

        public const ushort HID_USAGE_GENERIC_DEVICE_DISCOVER_WIRELESS_CONTROL = 0x23;

        public const ushort HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CHAR_ENTERED = 0x24;

        public const ushort HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CHAR_ERASED = 0x25;

        public const ushort HID_USAGE_GENERIC_DEVICE_SECURITY_CODE_CLEARED = 0x26;

        public const ushort HID_USAGE_KEYBOARD_NOEVENT = 0x00;

        public const ushort HID_USAGE_KEYBOARD_ROLLOVER = 0x01;

        public const ushort HID_USAGE_KEYBOARD_POSTFAIL = 0x02;

        public const ushort HID_USAGE_KEYBOARD_UNDEFINED = 0x03;

        public const ushort HID_USAGE_KEYBOARD_aA = 0x04;

        public const ushort HID_USAGE_KEYBOARD_zZ = 0x1D;

        public const ushort HID_USAGE_KEYBOARD_ONE = 0x1E;

        public const ushort HID_USAGE_KEYBOARD_ZERO = 0x27;

        public const ushort HID_USAGE_KEYBOARD_LCTRL = 0xE0;

        public const ushort HID_USAGE_KEYBOARD_LSHFT = 0xE1;

        public const ushort HID_USAGE_KEYBOARD_LALT = 0xE2;

        public const ushort HID_USAGE_KEYBOARD_LGUI = 0xE3;

        public const ushort HID_USAGE_KEYBOARD_RCTRL = 0xE4;

        public const ushort HID_USAGE_KEYBOARD_RSHFT = 0xE5;

        public const ushort HID_USAGE_KEYBOARD_RALT = 0xE6;

        public const ushort HID_USAGE_KEYBOARD_RGUI = 0xE7;

        public const ushort HID_USAGE_KEYBOARD_SCROLL_LOCK = 0x47;

        public const ushort HID_USAGE_KEYBOARD_NUM_LOCK = 0x53;

        public const ushort HID_USAGE_KEYBOARD_CAPS_LOCK = 0x39;

        public const ushort HID_USAGE_KEYBOARD_F1 = 0x3A;

        public const ushort HID_USAGE_KEYBOARD_F2 = 0x3B;

        public const ushort HID_USAGE_KEYBOARD_F3 = 0x3C;

        public const ushort HID_USAGE_KEYBOARD_F4 = 0x3D;

        public const ushort HID_USAGE_KEYBOARD_F5 = 0x3E;

        public const ushort HID_USAGE_KEYBOARD_F6 = 0x3F;

        public const ushort HID_USAGE_KEYBOARD_F7 = 0x40;

        public const ushort HID_USAGE_KEYBOARD_F8 = 0x41;

        public const ushort HID_USAGE_KEYBOARD_F9 = 0x42;

        public const ushort HID_USAGE_KEYBOARD_F10 = 0x43;

        public const ushort HID_USAGE_KEYBOARD_F11 = 0x44;

        public const ushort HID_USAGE_KEYBOARD_F12 = 0x45;

        public const ushort HID_USAGE_KEYBOARD_F13 = 0x68;

        public const ushort HID_USAGE_KEYBOARD_F14 = 0x69;

        public const ushort HID_USAGE_KEYBOARD_F15 = 0x6A;

        public const ushort HID_USAGE_KEYBOARD_F16 = 0x6B;

        public const ushort HID_USAGE_KEYBOARD_F17 = 0x6C;

        public const ushort HID_USAGE_KEYBOARD_F18 = 0x6D;

        public const ushort HID_USAGE_KEYBOARD_F19 = 0x6E;

        public const ushort HID_USAGE_KEYBOARD_F20 = 0x6F;

        public const ushort HID_USAGE_KEYBOARD_F21 = 0x70;

        public const ushort HID_USAGE_KEYBOARD_F22 = 0x71;

        public const ushort HID_USAGE_KEYBOARD_F23 = 0x72;

        public const ushort HID_USAGE_KEYBOARD_F24 = 0x73;

        public const ushort HID_USAGE_KEYBOARD_RETURN = 0x28;

        public const ushort HID_USAGE_KEYBOARD_ESCAPE = 0x29;

        public const ushort HID_USAGE_KEYBOARD_DELETE = 0x2A;

        public const ushort HID_USAGE_KEYBOARD_PRINT_SCREEN = 0x46;

        public const ushort HID_USAGE_KEYBOARD_DELETE_FORWARD = 0x4C;

        public const ushort HID_USAGE_LED_NUM_LOCK = 0x01;

        public const ushort HID_USAGE_LED_CAPS_LOCK = 0x02;

        public const ushort HID_USAGE_LED_SCROLL_LOCK = 0x03;

        public const ushort HID_USAGE_LED_COMPOSE = 0x04;

        public const ushort HID_USAGE_LED_KANA = 0x05;

        public const ushort HID_USAGE_LED_POWER = 0x06;

        public const ushort HID_USAGE_LED_SHIFT = 0x07;

        public const ushort HID_USAGE_LED_DO_NOT_DISTURB = 0x08;

        public const ushort HID_USAGE_LED_MUTE = 0x09;

        public const ushort HID_USAGE_LED_TONE_ENABLE = 0x0A;

        public const ushort HID_USAGE_LED_HIGH_CUT_FILTER = 0x0B;

        public const ushort HID_USAGE_LED_LOW_CUT_FILTER = 0x0C;

        public const ushort HID_USAGE_LED_EQUALIZER_ENABLE = 0x0D;

        public const ushort HID_USAGE_LED_SOUND_FIELD_ON = 0x0E;

        public const ushort HID_USAGE_LED_SURROUND_FIELD_ON = 0x0F;

        public const ushort HID_USAGE_LED_REPEAT = 0x10;

        public const ushort HID_USAGE_LED_STEREO = 0x11;

        public const ushort HID_USAGE_LED_SAMPLING_RATE_DETECT = 0x12;

        public const ushort HID_USAGE_LED_SPINNING = 0x13;

        public const ushort HID_USAGE_LED_CAV = 0x14;

        public const ushort HID_USAGE_LED_CLV = 0x15;

        public const ushort HID_USAGE_LED_RECORDING_FORMAT_DET = 0x16;

        public const ushort HID_USAGE_LED_OFF_HOOK = 0x17;

        public const ushort HID_USAGE_LED_RING = 0x18;

        public const ushort HID_USAGE_LED_MESSAGE_WAITING = 0x19;

        public const ushort HID_USAGE_LED_DATA_MODE = 0x1A;

        public const ushort HID_USAGE_LED_BATTERY_OPERATION = 0x1B;

        public const ushort HID_USAGE_LED_BATTERY_OK = 0x1C;

        public const ushort HID_USAGE_LED_BATTERY_LOW = 0x1D;

        public const ushort HID_USAGE_LED_SPEAKER = 0x1E;

        public const ushort HID_USAGE_LED_HEAD_SET = 0x1F;

        public const ushort HID_USAGE_LED_HOLD = 0x20;

        public const ushort HID_USAGE_LED_MICROPHONE = 0x21;

        public const ushort HID_USAGE_LED_COVERAGE = 0x22;

        public const ushort HID_USAGE_LED_NIGHT_MODE = 0x23;

        public const ushort HID_USAGE_LED_SEND_CALLS = 0x24;

        public const ushort HID_USAGE_LED_CALL_PICKUP = 0x25;

        public const ushort HID_USAGE_LED_CONFERENCE = 0x26;

        public const ushort HID_USAGE_LED_STAND_BY = 0x27;

        public const ushort HID_USAGE_LED_CAMERA_ON = 0x28;

        public const ushort HID_USAGE_LED_CAMERA_OFF = 0x29;

        public const ushort HID_USAGE_LED_ON_LINE = 0x2A;

        public const ushort HID_USAGE_LED_OFF_LINE = 0x2B;

        public const ushort HID_USAGE_LED_BUSY = 0x2C;

        public const ushort HID_USAGE_LED_READY = 0x2D;

        public const ushort HID_USAGE_LED_PAPER_OUT = 0x2E;

        public const ushort HID_USAGE_LED_PAPER_JAM = 0x2F;

        public const ushort HID_USAGE_LED_REMOTE = 0x30;

        public const ushort HID_USAGE_LED_FORWARD = 0x31;

        public const ushort HID_USAGE_LED_REVERSE = 0x32;

        public const ushort HID_USAGE_LED_STOP = 0x33;

        public const ushort HID_USAGE_LED_REWIND = 0x34;

        public const ushort HID_USAGE_LED_FAST_FORWARD = 0x35;

        public const ushort HID_USAGE_LED_PLAY = 0x36;

        public const ushort HID_USAGE_LED_PAUSE = 0x37;

        public const ushort HID_USAGE_LED_RECORD = 0x38;

        public const ushort HID_USAGE_LED_ERROR = 0x39;

        public const ushort HID_USAGE_LED_SELECTED_INDICATOR = 0x3A;

        public const ushort HID_USAGE_LED_IN_USE_INDICATOR = 0x3B;

        public const ushort HID_USAGE_LED_MULTI_MODE_INDICATOR = 0x3C;

        public const ushort HID_USAGE_LED_INDICATOR_ON = 0x3D;

        public const ushort HID_USAGE_LED_INDICATOR_FLASH = 0x3E;

        public const ushort HID_USAGE_LED_INDICATOR_SLOW_BLINK = 0x3F;

        public const ushort HID_USAGE_LED_INDICATOR_FAST_BLINK = 0x40;

        public const ushort HID_USAGE_LED_INDICATOR_OFF = 0x41;

        public const ushort HID_USAGE_LED_FLASH_ON_TIME = 0x42;

        public const ushort HID_USAGE_LED_SLOW_BLINK_ON_TIME = 0x43;

        public const ushort HID_USAGE_LED_SLOW_BLINK_OFF_TIME = 0x44;

        public const ushort HID_USAGE_LED_FAST_BLINK_ON_TIME = 0x45;

        public const ushort HID_USAGE_LED_FAST_BLINK_OFF_TIME = 0x46;

        public const ushort HID_USAGE_LED_INDICATOR_COLOR = 0x47;

        public const ushort HID_USAGE_LED_RED = 0x48;

        public const ushort HID_USAGE_LED_GREEN = 0x49;

        public const ushort HID_USAGE_LED_AMBER = 0x4A;

        public const ushort HID_USAGE_LED_GENERIC_INDICATOR = 0x4B;

        public const ushort HID_USAGE_LED_SYSTEM_SUSPEND = 0x4C;

        public const ushort HID_USAGE_LED_EXTERNAL_POWER = 0x4D;

        public const ushort HID_USAGE_TELEPHONY_PHONE = 0x01;

        public const ushort HID_USAGE_TELEPHONY_ANSWERING_MACHINE = 0x02;

        public const ushort HID_USAGE_TELEPHONY_MESSAGE_CONTROLS = 0x03;

        public const ushort HID_USAGE_TELEPHONY_HANDSET = 0x04;

        public const ushort HID_USAGE_TELEPHONY_HEADSET = 0x05;

        public const ushort HID_USAGE_TELEPHONY_KEYPAD = 0x06;

        public const ushort HID_USAGE_TELEPHONY_PROGRAMMABLE_BUTTON = 0x07;

        public const ushort HID_USAGE_TELEPHONY_REDIAL = 0x24;

        public const ushort HID_USAGE_TELEPHONY_TRANSFER = 0x25;

        public const ushort HID_USAGE_TELEPHONY_DROP = 0x26;

        public const ushort HID_USAGE_TELEPHONY_LINE = 0x2A;

        public const ushort HID_USAGE_TELEPHONY_RING_ENABLE = 0x2D;

        public const ushort HID_USAGE_TELEPHONY_SEND = 0x31;

        public const ushort HID_USAGE_TELEPHONY_KEYPAD_0 = 0xB0;

        public const ushort HID_USAGE_TELEPHONY_KEYPAD_D = 0xBF;

        public const ushort HID_USAGE_TELEPHONY_HOST_AVAILABLE = 0xF1;

        public const ushort HID_USAGE_CONSUMERCTRL = 0x01;

        public const ushort HID_USAGE_CONSUMER_CHANNEL_INCREMENT = 0x9C;

        public const ushort HID_USAGE_CONSUMER_CHANNEL_DECREMENT = 0x9D;

        public const ushort HID_USAGE_CONSUMER_PLAY = 0xB0;

        public const ushort HID_USAGE_CONSUMER_PAUSE = 0xB1;

        public const ushort HID_USAGE_CONSUMER_RECORD = 0xB2;

        public const ushort HID_USAGE_CONSUMER_FAST_FORWARD = 0xB3;

        public const ushort HID_USAGE_CONSUMER_REWIND = 0xB4;

        public const ushort HID_USAGE_CONSUMER_SCAN_NEXT_TRACK = 0xB5;

        public const ushort HID_USAGE_CONSUMER_SCAN_PREV_TRACK = 0xB6;

        public const ushort HID_USAGE_CONSUMER_STOP = 0xB7;

        public const ushort HID_USAGE_CONSUMER_PLAY_PAUSE = 0xCD;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_OPEN_GAMEBAR = 0xD0;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_RECORD = 0xD1;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_RECORD_CLIP = 0xD2;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_SCREENSHOT = 0xD3;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_INDICATOR = 0xD4;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_MICROPHONE = 0xD5;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_CAMERA = 0xD6;

        public const ushort HID_USAGE_CONSUMER_GAMEDVR_TOGGLE_BROADCAST = 0xD7;

        public const ushort HID_USAGE_CONSUMER_VOLUME = 0xE0;

        public const ushort HID_USAGE_CONSUMER_BALANCE = 0xE1;

        public const ushort HID_USAGE_CONSUMER_MUTE = 0xE2;

        public const ushort HID_USAGE_CONSUMER_BASS = 0xE3;

        public const ushort HID_USAGE_CONSUMER_TREBLE = 0xE4;

        public const ushort HID_USAGE_CONSUMER_BASS_BOOST = 0xE5;

        public const ushort HID_USAGE_CONSUMER_SURROUND_MODE = 0xE6;

        public const ushort HID_USAGE_CONSUMER_LOUDNESS = 0xE7;

        public const ushort HID_USAGE_CONSUMER_MPX = 0xE8;

        public const ushort HID_USAGE_CONSUMER_VOLUME_INCREMENT = 0xE9;

        public const ushort HID_USAGE_CONSUMER_VOLUME_DECREMENT = 0xEA;

        public const ushort HID_USAGE_CONSUMER_BASS_INCREMENT = 0x152;

        public const ushort HID_USAGE_CONSUMER_BASS_DECREMENT = 0x153;

        public const ushort HID_USAGE_CONSUMER_TREBLE_INCREMENT = 0x154;

        public const ushort HID_USAGE_CONSUMER_TREBLE_DECREMENT = 0x155;

        public const ushort HID_USAGE_CONSUMER_AL_CONFIGURATION = 0x183;

        public const ushort HID_USAGE_CONSUMER_AL_EMAIL = 0x18A;

        public const ushort HID_USAGE_CONSUMER_AL_CALCULATOR = 0x192;

        public const ushort HID_USAGE_CONSUMER_AL_BROWSER = 0x194;

        public const ushort HID_USAGE_CONSUMER_AL_SEARCH = 0x1C6;

        public const ushort HID_USAGE_CONSUMER_AC_SEARCH = 0x221;

        public const ushort HID_USAGE_CONSUMER_AC_GOTO = 0x222;

        public const ushort HID_USAGE_CONSUMER_AC_HOME = 0x223;

        public const ushort HID_USAGE_CONSUMER_AC_BACK = 0x224;

        public const ushort HID_USAGE_CONSUMER_AC_FORWARD = 0x225;

        public const ushort HID_USAGE_CONSUMER_AC_STOP = 0x226;

        public const ushort HID_USAGE_CONSUMER_AC_REFRESH = 0x227;

        public const ushort HID_USAGE_CONSUMER_AC_PREVIOUS = 0x228;

        public const ushort HID_USAGE_CONSUMER_AC_NEXT = 0x229;

        public const ushort HID_USAGE_CONSUMER_AC_BOOKMARKS = 0x22A;

        public const ushort HID_USAGE_CONSUMER_AC_PAN = 0x238;

        public const ushort HID_USAGE_CONSUMER_EXTENDED_KEYBOARD_ATTRIBUTES_COLLECTION = 0x2C0;

        public const ushort HID_USAGE_CONSUMER_KEYBOARD_FORM_FACTOR = 0x2C1;

        public const ushort HID_USAGE_CONSUMER_KEYBOARD_KEY_TYPE = 0x2C2;

        public const ushort HID_USAGE_CONSUMER_KEYBOARD_PHYSICAL_LAYOUT = 0x2C3;

        public const ushort HID_USAGE_CONSUMER_VENDOR_SPECIFIC_KEYBOARD_PHYSICAL_LAYOUT = 0x2C4;

        public const ushort HID_USAGE_CONSUMER_KEYBOARD_IETF_LANGUAGE_TAG_INDEX = 0x2C5;

        public const ushort HID_USAGE_CONSUMER_IMPLEMENTED_KEYBOARD_INPUT_ASSIST_CONTROLS = 0x2C6;

        public const ushort HID_USAGE_DIGITIZER_DIGITIZER = 0x01;

        public const ushort HID_USAGE_DIGITIZER_PEN = 0x02;

        public const ushort HID_USAGE_DIGITIZER_LIGHT_PEN = 0x03;

        public const ushort HID_USAGE_DIGITIZER_TOUCH_SCREEN = 0x04;

        public const ushort HID_USAGE_DIGITIZER_TOUCH_PAD = 0x05;

        public const ushort HID_USAGE_DIGITIZER_WHITE_BOARD = 0x06;

        public const ushort HID_USAGE_DIGITIZER_COORD_MEASURING = 0x07;

        public const ushort HID_USAGE_DIGITIZER_3D_DIGITIZER = 0x08;

        public const ushort HID_USAGE_DIGITIZER_STEREO_PLOTTER = 0x09;

        public const ushort HID_USAGE_DIGITIZER_ARTICULATED_ARM = 0x0A;

        public const ushort HID_USAGE_DIGITIZER_ARMATURE = 0x0B;

        public const ushort HID_USAGE_DIGITIZER_MULTI_POINT = 0x0C;

        public const ushort HID_USAGE_DIGITIZER_FREE_SPACE_WAND = 0x0D;

        public const ushort HID_USAGE_DIGITIZER_STYLUS = 0x20;

        public const ushort HID_USAGE_DIGITIZER_PUCK = 0x21;

        public const ushort HID_USAGE_DIGITIZER_FINGER = 0x22;

        public const ushort HID_USAGE_DIGITIZER_TABLET_FUNC_KEYS = 0x39;

        public const ushort HID_USAGE_DIGITIZER_PROG_CHANGE_KEYS = 0x3A;

        public const ushort HID_USAGE_DIGITIZER_TIP_PRESSURE = 0x30;

        public const ushort HID_USAGE_DIGITIZER_BARREL_PRESSURE = 0x31;

        public const ushort HID_USAGE_DIGITIZER_IN_RANGE = 0x32;

        public const ushort HID_USAGE_DIGITIZER_TOUCH = 0x33;

        public const ushort HID_USAGE_DIGITIZER_UNTOUCH = 0x34;

        public const ushort HID_USAGE_DIGITIZER_TAP = 0x35;

        public const ushort HID_USAGE_DIGITIZER_QUALITY = 0x36;

        public const ushort HID_USAGE_DIGITIZER_DATA_VALID = 0x37;

        public const ushort HID_USAGE_DIGITIZER_TRANSDUCER_INDEX = 0x38;

        public const ushort HID_USAGE_DIGITIZER_BATTERY_STRENGTH = 0x3B;

        public const ushort HID_USAGE_DIGITIZER_INVERT = 0x3C;

        public const ushort HID_USAGE_DIGITIZER_X_TILT = 0x3D;

        public const ushort HID_USAGE_DIGITIZER_Y_TILT = 0x3E;

        public const ushort HID_USAGE_DIGITIZER_AZIMUTH = 0x3F;

        public const ushort HID_USAGE_DIGITIZER_ALTITUDE = 0x40;

        public const ushort HID_USAGE_DIGITIZER_TWIST = 0x41;

        public const ushort HID_USAGE_DIGITIZER_TIP_SWITCH = 0x42;

        public const ushort HID_USAGE_DIGITIZER_SECONDARY_TIP_SWITCH = 0x43;

        public const ushort HID_USAGE_DIGITIZER_BARREL_SWITCH = 0x44;

        public const ushort HID_USAGE_DIGITIZER_ERASER = 0x45;

        public const ushort HID_USAGE_DIGITIZER_TABLET_PICK = 0x46;

        public const ushort HID_USAGE_DIGITIZER_TRANSDUCER_SERIAL = 0x5B;

        public const ushort HID_USAGE_DIGITIZER_TRANSDUCER_VENDOR = 0x92;

        public const ushort HID_USAGE_DIGITIZER_TRANSDUCER_CONNECTED = 0xA2;

        public const ushort HID_USAGE_HAPTICS_SIMPLE_CONTROLLER = 0x01;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_LIST = 0x10;

        public const ushort HID_USAGE_HAPTICS_DURATION_LIST = 0x11;

        public const ushort HID_USAGE_HAPTICS_AUTO_TRIGGER = 0x20;

        public const ushort HID_USAGE_HAPTICS_MANUAL_TRIGGER = 0x21;

        public const ushort HID_USAGE_HAPTICS_AUTO_ASSOCIATED_CONTROL = 0x22;

        public const ushort HID_USAGE_HAPTICS_INTENSITY = 0x23;

        public const ushort HID_USAGE_HAPTICS_REPEAT_COUNT = 0x24;

        public const ushort HID_USAGE_HAPTICS_RETRIGGER_PERIOD = 0x25;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_VENDOR_PAGE = 0x26;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_VENDOR_ID = 0x27;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_CUTOFF_TIME = 0x28;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_BEGIN = 0x1000;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_STOP = 0x1001;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_NULL = 0x1002;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_CLICK = 0x1003;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_BUZZ = 0x1004;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_RUMBLE = 0x1005;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_PRESS = 0x1006;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_RELEASE = 0x1007;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_END = 0x1FFF;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_VENDOR_BEGIN = 0x2000;

        public const ushort HID_USAGE_HAPTICS_WAVEFORM_VENDOR_END = 0x2FFF;

        public const ushort HID_USAGE_ALPHANUMERIC_ALPHANUMERIC_DISPLAY = 0x01;

        public const ushort HID_USAGE_ALPHANUMERIC_BITMAPPED_DISPLAY = 0x02;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_ATTRIBUTES_REPORT = 0x20;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_CONTROL_REPORT = 0x24;

        public const ushort HID_USAGE_ALPHANUMERIC_CHARACTER_REPORT = 0x2B;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_STATUS = 0x2D;

        public const ushort HID_USAGE_ALPHANUMERIC_CURSOR_POSITION_REPORT = 0x32;

        public const ushort HID_USAGE_ALPHANUMERIC_FONT_REPORT = 0x3B;

        public const ushort HID_USAGE_ALPHANUMERIC_FONT_DATA = 0x3C;

        public const ushort HID_USAGE_ALPHANUMERIC_CHARACTER_ATTRIBUTE = 0x48;

        public const ushort HID_USAGE_ALPHANUMERIC_PALETTE_REPORT = 0x85;

        public const ushort HID_USAGE_ALPHANUMERIC_PALETTE_DATA = 0x88;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_REPORT = 0x8A;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_DATA = 0x8F;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON = 0x90;

        public const ushort HID_USAGE_ALPHANUMERIC_ASCII_CHARACTER_SET = 0x21;

        public const ushort HID_USAGE_ALPHANUMERIC_DATA_READ_BACK = 0x22;

        public const ushort HID_USAGE_ALPHANUMERIC_FONT_READ_BACK = 0x23;

        public const ushort HID_USAGE_ALPHANUMERIC_CLEAR_DISPLAY = 0x25;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_ENABLE = 0x26;

        public const ushort HID_USAGE_ALPHANUMERIC_SCREEN_SAVER_DELAY = 0x27;

        public const ushort HID_USAGE_ALPHANUMERIC_SCREEN_SAVER_ENABLE = 0x28;

        public const ushort HID_USAGE_ALPHANUMERIC_VERTICAL_SCROLL = 0x29;

        public const ushort HID_USAGE_ALPHANUMERIC_HORIZONTAL_SCROLL = 0x2A;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_DATA = 0x2C;

        public const ushort HID_USAGE_ALPHANUMERIC_STATUS_NOT_READY = 0x2E;

        public const ushort HID_USAGE_ALPHANUMERIC_STATUS_READY = 0x2F;

        public const ushort HID_USAGE_ALPHANUMERIC_ERR_NOT_A_LOADABLE_CHARACTER = 0x30;

        public const ushort HID_USAGE_ALPHANUMERIC_ERR_FONT_DATA_CANNOT_BE_READ = 0x31;

        public const ushort HID_USAGE_ALPHANUMERIC_ROW = 0x33;

        public const ushort HID_USAGE_ALPHANUMERIC_COLUMN = 0x34;

        public const ushort HID_USAGE_ALPHANUMERIC_ROWS = 0x35;

        public const ushort HID_USAGE_ALPHANUMERIC_COLUMNS = 0x36;

        public const ushort HID_USAGE_ALPHANUMERIC_CURSOR_PIXEL_POSITIONING = 0x37;

        public const ushort HID_USAGE_ALPHANUMERIC_CURSOR_MODE = 0x38;

        public const ushort HID_USAGE_ALPHANUMERIC_CURSOR_ENABLE = 0x39;

        public const ushort HID_USAGE_ALPHANUMERIC_CURSOR_BLINK = 0x3A;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_WIDTH = 0x3D;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_HEIGHT = 0x3E;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_SPACING_HORIZONTAL = 0x3F;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_SPACING_VERTICAL = 0x40;

        public const ushort HID_USAGE_ALPHANUMERIC_UNICODE_CHAR_SET = 0x41;

        public const ushort HID_USAGE_ALPHANUMERIC_FONT_7_SEGMENT = 0x42;

        public const ushort HID_USAGE_ALPHANUMERIC_7_SEGMENT_DIRECT_MAP = 0x43;

        public const ushort HID_USAGE_ALPHANUMERIC_FONT_14_SEGMENT = 0x44;

        public const ushort HID_USAGE_ALPHANUMERIC_14_SEGMENT_DIRECT_MAP = 0x45;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_BRIGHTNESS = 0x46;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_CONTRAST = 0x47;

        public const ushort HID_USAGE_ALPHANUMERIC_ATTRIBUTE_READBACK = 0x49;

        public const ushort HID_USAGE_ALPHANUMERIC_ATTRIBUTE_DATA = 0x4A;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_ATTR_ENHANCE = 0x4B;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_ATTR_UNDERLINE = 0x4C;

        public const ushort HID_USAGE_ALPHANUMERIC_CHAR_ATTR_BLINK = 0x4D;

        public const ushort HID_USAGE_ALPHANUMERIC_BITMAP_SIZE_X = 0x80;

        public const ushort HID_USAGE_ALPHANUMERIC_BITMAP_SIZE_Y = 0x81;

        public const ushort HID_USAGE_ALPHANUMERIC_BIT_DEPTH_FORMAT = 0x83;

        public const ushort HID_USAGE_ALPHANUMERIC_DISPLAY_ORIENTATION = 0x84;

        public const ushort HID_USAGE_ALPHANUMERIC_PALETTE_DATA_SIZE = 0x86;

        public const ushort HID_USAGE_ALPHANUMERIC_PALETTE_DATA_OFFSET = 0x87;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_X1 = 0x8B;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_Y1 = 0x8C;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_X2 = 0x8D;

        public const ushort HID_USAGE_ALPHANUMERIC_BLIT_RECTANGLE_Y2 = 0x8E;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_ID = 0x91;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_SIDE = 0x92;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_OFFSET1 = 0x93;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_OFFSET2 = 0x94;

        public const ushort HID_USAGE_ALPHANUMERIC_SOFT_BUTTON_REPORT = 0x95;

        public const ushort HID_USAGE_LAMPARRAY = 0x01;

        public const ushort HID_USAGE_LAMPARRAY_ATTRBIUTES_REPORT = 0x02;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_COUNT = 0x03;

        public const ushort HID_USAGE_LAMPARRAY_BOUNDING_BOX_WIDTH_IN_MICROMETERS = 0x04;

        public const ushort HID_USAGE_LAMPARRAY_BOUNDING_BOX_HEIGHT_IN_MICROMETERS = 0x05;

        public const ushort HID_USAGE_LAMPARRAY_BOUNDING_BOX_DEPTH_IN_MICROMETERS = 0x06;

        public const ushort HID_USAGE_LAMPARRAY_KIND = 0x07;

        public const ushort HID_USAGE_LAMPARRAY_MIN_UPDATE_INTERVAL_IN_MICROSECONDS = 0x08;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_ATTRIBUTES_REQUEST_REPORT = 0x20;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_ID = 0x21;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_ATTRIBUTES_RESPONSE_REPORT = 0x22;

        public const ushort HID_USAGE_LAMPARRAY_POSITION_X_IN_MICROMETERS = 0x23;

        public const ushort HID_USAGE_LAMPARRAY_POSITION_Y_IN_MICROMETERS = 0x24;

        public const ushort HID_USAGE_LAMPARRAY_POSITION_Z_IN_MICROMETERS = 0x25;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_PURPOSES = 0x26;

        public const ushort HID_USAGE_LAMPARRAY_UPDATE_LATENCY_IN_MICROSECONDS = 0x27;

        public const ushort HID_USAGE_LAMPARRAY_RED_LEVEL_COUNT = 0x28;

        public const ushort HID_USAGE_LAMPARRAY_GREEN_LEVEL_COUNT = 0x29;

        public const ushort HID_USAGE_LAMPARRAY_BLUE_LEVEL_COUNT = 0x2A;

        public const ushort HID_USAGE_LAMPARRAY_INTENSITY_LEVEL_COUNT = 0x2B;

        public const ushort HID_USAGE_LAMPARRAY_IS_PROGRAMMABLE = 0x2C;

        public const ushort HID_USAGE_LAMPARRAY_INPUT_BINDING = 0x2D;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_MULTI_UPDATE_REPORT = 0x50;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_RED_UPDATE_CHANNEL = 0x51;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_GREEN_UPDATE_CHANNEL = 0x52;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_BLUE_UPDATE_CHANNEL = 0x53;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_INTENSITY_UPDATE_CHANNEL = 0x54;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_UPDATE_FLAGS = 0x55;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_RANGE_UPDATE_REPORT = 0x60;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_ID_START = 0x61;

        public const ushort HID_USAGE_LAMPARRAY_LAMP_ID_END = 0x62;

        public const ushort HID_USAGE_LAMPARRAY_CONTROL_REPORT = 0x70;

        public const ushort HID_USAGE_LAMPARRAY_AUTONOMOUS_MODE = 0x71;

        public const ushort HID_USAGE_CAMERA_AUTO_FOCUS = 0x20;

        public const ushort HID_USAGE_CAMERA_SHUTTER = 0x21;

        public const ushort HID_USAGE_MS_BTH_HF_DIALNUMBER = 0x21;

        public const ushort HID_USAGE_MS_BTH_HF_DIALMEMORY = 0x22;

        public const uint IOCTL_KEYBOARD_QUERY_ATTRIBUTES = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0000) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_SET_TYPEMATIC = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0001) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_SET_INDICATORS = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0002) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_QUERY_TYPEMATIC = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0008) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_QUERY_INDICATORS = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0010) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0020) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_INSERT_DATA = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0040) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_QUERY_EXTENDED_ATTRIBUTES = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0080) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_QUERY_IME_STATUS = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0400) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_KEYBOARD_SET_IME_STATUS = ((FILE_DEVICE_KEYBOARD) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0401) << 2) | (METHOD_BUFFERED);

        public static readonly Guid GUID_DEVINTERFACE_KEYBOARD__scanned__ = new Guid(0x884b96c3, 0x56ef, 0x11d1,              0xbc, 0x8c, 0x00, 0xa0, 0xc9, 0x14, 0x05, 0xdd);

        public const uint KEYBOARD_OVERRUN_MAKE_CODE = 0xFF;

        public const uint KEY_MAKE = 0;

        public const uint KEY_BREAK = 1;

        public const uint KEY_E0 = 2;

        public const uint KEY_E1 = 4;

        public const uint KEY_TERMSRV_SET_LED = 8;

        public const uint KEY_TERMSRV_SHADOW = 0x10;

        public const uint KEY_TERMSRV_VKPACKET = 0x20;

        public const uint KEY_RIM_VKEY = 0x40;

        public const uint KEY_FROM_KEYBOARD_OVERRIDER = 0x80;

        public const uint KEY_UNICODE_SEQUENCE_ITEM = 0x100;

        public const uint KEY_UNICODE_SEQUENCE_END = 0x200;

        public const uint KEYBOARD_EXTENDED_ATTRIBUTES_STRUCT_VERSION_1 = 1;

        public const uint KEYBOARD_LED_INJECTED = 0x8000;

        public const uint KEYBOARD_SHADOW = 0x4000;

        public const uint KEYBOARD_KANA_LOCK_ON = 8;

        public const uint KEYBOARD_CAPS_LOCK_ON = 4;

        public const uint KEYBOARD_NUM_LOCK_ON = 2;

        public const uint KEYBOARD_SCROLL_LOCK_ON = 1;

        public const uint KEYBOARD_ERROR_VALUE_BASE = 10000;

        public const uint IOCTL_MOUSE_QUERY_ATTRIBUTES = ((FILE_DEVICE_MOUSE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MOUSE_INSERT_DATA = ((FILE_DEVICE_MOUSE) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((1) << 2) | (METHOD_BUFFERED);

        public static readonly Guid GUID_DEVINTERFACE_MOUSE__scanned__ = new Guid(0x378de44c, 0x56ef, 0x11d1,             0xbc, 0x8c, 0x00, 0xa0, 0xc9, 0x14, 0x05, 0xdd );

        public const uint MOUSE_LEFT_BUTTON_DOWN = 0x0001;

        public const uint MOUSE_LEFT_BUTTON_UP = 0x0002;

        public const uint MOUSE_RIGHT_BUTTON_DOWN = 0x0004;

        public const uint MOUSE_RIGHT_BUTTON_UP = 0x0008;

        public const uint MOUSE_MIDDLE_BUTTON_DOWN = 0x0010;

        public const uint MOUSE_MIDDLE_BUTTON_UP = 0x0020;

        public const uint MOUSE_BUTTON_4_DOWN = 0x0040;

        public const uint MOUSE_BUTTON_4_UP = 0x0080;

        public const uint MOUSE_BUTTON_5_DOWN = 0x0100;

        public const uint MOUSE_BUTTON_5_UP = 0x0200;

        public const uint MOUSE_WHEEL = 0x0400;

        public const uint MOUSE_HWHEEL = 0x0800;

        public const uint MOUSE_MOVE_RELATIVE = 0;

        public const uint MOUSE_MOVE_ABSOLUTE = 1;

        public const uint MOUSE_VIRTUAL_DESKTOP = 0x02;

        public const uint MOUSE_ATTRIBUTES_CHANGED = 0x04;

        public const uint MOUSE_MOVE_NOCOALESCE = 0x08;

        public const uint MOUSE_TERMSRV_SRC_SHADOW = 0x100;

        public const uint MOUSE_INPORT_HARDWARE = 0x0001;

        public const uint MOUSE_I8042_HARDWARE = 0x0002;

        public const uint MOUSE_SERIAL_HARDWARE = 0x0004;

        public const uint BALLPOINT_I8042_HARDWARE = 0x0008;

        public const uint BALLPOINT_SERIAL_HARDWARE = 0x0010;

        public const uint WHEELMOUSE_I8042_HARDWARE = 0x0020;

        public const uint WHEELMOUSE_SERIAL_HARDWARE = 0x0040;

        public const uint MOUSE_HID_HARDWARE = 0x0080;

        public const uint WHEELMOUSE_HID_HARDWARE = 0x0100;

        public const uint HORIZONTAL_WHEEL_PRESENT = 0x8000;

        public const uint MOUSE_ERROR_VALUE_BASE = 20000;

        public const uint DIRECTINPUT_HEADER_VERSION = 0x0800;

        public static readonly Guid CLSID_DirectInput__scanned__ = new Guid(0x25E609E0,0xB259,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid CLSID_DirectInputDevice__scanned__ = new Guid(0x25E609E1,0xB259,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid CLSID_DirectInput8__scanned__ = new Guid(0x25E609E4,0xB259,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid CLSID_DirectInputDevice8__scanned__ = new Guid(0x25E609E5,0xB259,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputA__scanned__ = new Guid(0x89521360,0xAA8A,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputW__scanned__ = new Guid(0x89521361,0xAA8A,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInput2A__scanned__ = new Guid(0x5944E662,0xAA8A,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInput2W__scanned__ = new Guid(0x5944E663,0xAA8A,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInput7A__scanned__ = new Guid(0x9A4CB684,0x236D,0x11D3,0x8E,0x9D,0x00,0xC0,0x4F,0x68,0x44,0xAE);

        public static readonly Guid IID_IDirectInput7W__scanned__ = new Guid(0x9A4CB685,0x236D,0x11D3,0x8E,0x9D,0x00,0xC0,0x4F,0x68,0x44,0xAE);

        public static readonly Guid IID_IDirectInput8A__scanned__ = new Guid(0xBF798030,0x483A,0x4DA2,0xAA,0x99,0x5D,0x64,0xED,0x36,0x97,0x00);

        public static readonly Guid IID_IDirectInput8W__scanned__ = new Guid(0xBF798031,0x483A,0x4DA2,0xAA,0x99,0x5D,0x64,0xED,0x36,0x97,0x00);

        public static readonly Guid IID_IDirectInputDeviceA__scanned__ = new Guid(0x5944E680,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputDeviceW__scanned__ = new Guid(0x5944E681,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputDevice2A__scanned__ = new Guid(0x5944E682,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputDevice2W__scanned__ = new Guid(0x5944E683,0xC92E,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid IID_IDirectInputDevice7A__scanned__ = new Guid(0x57D7C6BC,0x2356,0x11D3,0x8E,0x9D,0x00,0xC0,0x4F,0x68,0x44,0xAE);

        public static readonly Guid IID_IDirectInputDevice7W__scanned__ = new Guid(0x57D7C6BD,0x2356,0x11D3,0x8E,0x9D,0x00,0xC0,0x4F,0x68,0x44,0xAE);

        public static readonly Guid IID_IDirectInputDevice8A__scanned__ = new Guid(0x54D41080,0xDC15,0x4833,0xA4,0x1B,0x74,0x8F,0x73,0xA3,0x81,0x79);

        public static readonly Guid IID_IDirectInputDevice8W__scanned__ = new Guid(0x54D41081,0xDC15,0x4833,0xA4,0x1B,0x74,0x8F,0x73,0xA3,0x81,0x79);

        public static readonly Guid IID_IDirectInputEffect__scanned__ = new Guid(0xE7E1F7C0,0x88D2,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_XAxis__scanned__ = new Guid(0xA36D02E0,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_YAxis__scanned__ = new Guid(0xA36D02E1,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_ZAxis__scanned__ = new Guid(0xA36D02E2,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_RxAxis__scanned__ = new Guid(0xA36D02F4,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_RyAxis__scanned__ = new Guid(0xA36D02F5,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_RzAxis__scanned__ = new Guid(0xA36D02E3,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_Slider__scanned__ = new Guid(0xA36D02E4,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_Button__scanned__ = new Guid(0xA36D02F0,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_Key__scanned__ = new Guid(0x55728220,0xD33C,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_POV__scanned__ = new Guid(0xA36D02F2,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_Unknown__scanned__ = new Guid(0xA36D02F3,0xC9F3,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysMouse__scanned__ = new Guid(0x6F1D2B60,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysKeyboard__scanned__ = new Guid(0x6F1D2B61,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_Joystick__scanned__ = new Guid(0x6F1D2B70,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysMouseEm__scanned__ = new Guid(0x6F1D2B80,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysMouseEm2__scanned__ = new Guid(0x6F1D2B81,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysKeyboardEm__scanned__ = new Guid(0x6F1D2B82,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_SysKeyboardEm2__scanned__ = new Guid(0x6F1D2B83,0xD5A0,0x11CF,0xBF,0xC7,0x44,0x45,0x53,0x54,0x00,0x00);

        public static readonly Guid GUID_ConstantForce__scanned__ = new Guid(0x13541C20,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_RampForce__scanned__ = new Guid(0x13541C21,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Square__scanned__ = new Guid(0x13541C22,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Sine__scanned__ = new Guid(0x13541C23,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Triangle__scanned__ = new Guid(0x13541C24,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_SawtoothUp__scanned__ = new Guid(0x13541C25,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_SawtoothDown__scanned__ = new Guid(0x13541C26,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Spring__scanned__ = new Guid(0x13541C27,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Damper__scanned__ = new Guid(0x13541C28,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Inertia__scanned__ = new Guid(0x13541C29,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_Friction__scanned__ = new Guid(0x13541C2A,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public static readonly Guid GUID_CustomForce__scanned__ = new Guid(0x13541C2B,0x8E33,0x11D0,0x9A,0xD0,0x00,0xA0,0xC9,0xA0,0x6E,0x35);

        public const uint DIEFT_ALL = 0x00000000;

        public const uint DIEFT_CONSTANTFORCE = 0x00000001;

        public const uint DIEFT_RAMPFORCE = 0x00000002;

        public const uint DIEFT_PERIODIC = 0x00000003;

        public const uint DIEFT_CONDITION = 0x00000004;

        public const uint DIEFT_CUSTOMFORCE = 0x00000005;

        public const uint DIEFT_HARDWARE = 0x000000FF;

        public const uint DIEFT_FFATTACK = 0x00000200;

        public const uint DIEFT_FFFADE = 0x00000400;

        public const uint DIEFT_SATURATION = 0x00000800;

        public const uint DIEFT_POSNEGCOEFFICIENTS = 0x00001000;

        public const uint DIEFT_POSNEGSATURATION = 0x00002000;

        public const uint DIEFT_DEADBAND = 0x00004000;

        public const uint DIEFT_STARTDELAY = 0x00008000;

        public const uint DI_DEGREES = 100;

        public const uint DI_FFNOMINALMAX = 10000;

        public const uint DI_SECONDS = 1000000;

        public const uint DIEFF_OBJECTIDS = 0x00000001;

        public const uint DIEFF_OBJECTOFFSETS = 0x00000002;

        public const uint DIEFF_CARTESIAN = 0x00000010;

        public const uint DIEFF_POLAR = 0x00000020;

        public const uint DIEFF_SPHERICAL = 0x00000040;

        public const uint DIEP_DURATION = 0x00000001;

        public const uint DIEP_SAMPLEPERIOD = 0x00000002;

        public const uint DIEP_GAIN = 0x00000004;

        public const uint DIEP_TRIGGERBUTTON = 0x00000008;

        public const uint DIEP_TRIGGERREPEATINTERVAL = 0x00000010;

        public const uint DIEP_AXES = 0x00000020;

        public const uint DIEP_DIRECTION = 0x00000040;

        public const uint DIEP_ENVELOPE = 0x00000080;

        public const uint DIEP_TYPESPECIFICPARAMS = 0x00000100;

        public const uint DIEP_STARTDELAY = 0x00000200;

        public const uint DIEP_ALLPARAMS_DX5 = 0x000001FF;

        public const uint DIEP_ALLPARAMS = 0x000003FF;

        public const uint DIEP_START = 0x20000000;

        public const uint DIEP_NORESTART = 0x40000000;

        public const uint DIEP_NODOWNLOAD = 0x80000000;

        public const uint DIEB_NOTRIGGER = 0xFFFFFFFF;

        public const uint DIES_SOLO = 0x00000001;

        public const uint DIES_NODOWNLOAD = 0x80000000;

        public const uint DIEGES_PLAYING = 0x00000001;

        public const uint DIEGES_EMULATED = 0x00000002;

        public const uint DIDEVTYPE_DEVICE = 1;

        public const uint DIDEVTYPE_MOUSE = 2;

        public const uint DIDEVTYPE_KEYBOARD = 3;

        public const uint DIDEVTYPE_JOYSTICK = 4;

        public const uint DI8DEVCLASS_ALL = 0;

        public const uint DI8DEVCLASS_DEVICE = 1;

        public const uint DI8DEVCLASS_POINTER = 2;

        public const uint DI8DEVCLASS_KEYBOARD = 3;

        public const uint DI8DEVCLASS_GAMECTRL = 4;

        public const uint DI8DEVTYPE_DEVICE = 0x11;

        public const uint DI8DEVTYPE_MOUSE = 0x12;

        public const uint DI8DEVTYPE_KEYBOARD = 0x13;

        public const uint DI8DEVTYPE_JOYSTICK = 0x14;

        public const uint DI8DEVTYPE_GAMEPAD = 0x15;

        public const uint DI8DEVTYPE_DRIVING = 0x16;

        public const uint DI8DEVTYPE_FLIGHT = 0x17;

        public const uint DI8DEVTYPE_1STPERSON = 0x18;

        public const uint DI8DEVTYPE_DEVICECTRL = 0x19;

        public const uint DI8DEVTYPE_SCREENPOINTER = 0x1A;

        public const uint DI8DEVTYPE_REMOTE = 0x1B;

        public const uint DI8DEVTYPE_SUPPLEMENTAL = 0x1C;

        public const uint DIDEVTYPE_HID = 0x00010000;

        public const uint DIDEVTYPEMOUSE_UNKNOWN = 1;

        public const uint DIDEVTYPEMOUSE_TRADITIONAL = 2;

        public const uint DIDEVTYPEMOUSE_FINGERSTICK = 3;

        public const uint DIDEVTYPEMOUSE_TOUCHPAD = 4;

        public const uint DIDEVTYPEMOUSE_TRACKBALL = 5;

        public const uint DIDEVTYPEKEYBOARD_UNKNOWN = 0;

        public const uint DIDEVTYPEKEYBOARD_PCXT = 1;

        public const uint DIDEVTYPEKEYBOARD_OLIVETTI = 2;

        public const uint DIDEVTYPEKEYBOARD_PCAT = 3;

        public const uint DIDEVTYPEKEYBOARD_PCENH = 4;

        public const uint DIDEVTYPEKEYBOARD_NOKIA1050 = 5;

        public const uint DIDEVTYPEKEYBOARD_NOKIA9140 = 6;

        public const uint DIDEVTYPEKEYBOARD_NEC98 = 7;

        public const uint DIDEVTYPEKEYBOARD_NEC98LAPTOP = 8;

        public const uint DIDEVTYPEKEYBOARD_NEC98106 = 9;

        public const uint DIDEVTYPEKEYBOARD_JAPAN106 = 10;

        public const uint DIDEVTYPEKEYBOARD_JAPANAX = 11;

        public const uint DIDEVTYPEKEYBOARD_J3100 = 12;

        public const uint DIDEVTYPEJOYSTICK_UNKNOWN = 1;

        public const uint DIDEVTYPEJOYSTICK_TRADITIONAL = 2;

        public const uint DIDEVTYPEJOYSTICK_FLIGHTSTICK = 3;

        public const uint DIDEVTYPEJOYSTICK_GAMEPAD = 4;

        public const uint DIDEVTYPEJOYSTICK_RUDDER = 5;

        public const uint DIDEVTYPEJOYSTICK_WHEEL = 6;

        public const uint DIDEVTYPEJOYSTICK_HEADTRACKER = 7;

        public const uint DI8DEVTYPEMOUSE_UNKNOWN = 1;

        public const uint DI8DEVTYPEMOUSE_TRADITIONAL = 2;

        public const uint DI8DEVTYPEMOUSE_FINGERSTICK = 3;

        public const uint DI8DEVTYPEMOUSE_TOUCHPAD = 4;

        public const uint DI8DEVTYPEMOUSE_TRACKBALL = 5;

        public const uint DI8DEVTYPEMOUSE_ABSOLUTE = 6;

        public const uint DI8DEVTYPEKEYBOARD_UNKNOWN = 0;

        public const uint DI8DEVTYPEKEYBOARD_PCXT = 1;

        public const uint DI8DEVTYPEKEYBOARD_OLIVETTI = 2;

        public const uint DI8DEVTYPEKEYBOARD_PCAT = 3;

        public const uint DI8DEVTYPEKEYBOARD_PCENH = 4;

        public const uint DI8DEVTYPEKEYBOARD_NOKIA1050 = 5;

        public const uint DI8DEVTYPEKEYBOARD_NOKIA9140 = 6;

        public const uint DI8DEVTYPEKEYBOARD_NEC98 = 7;

        public const uint DI8DEVTYPEKEYBOARD_NEC98LAPTOP = 8;

        public const uint DI8DEVTYPEKEYBOARD_NEC98106 = 9;

        public const uint DI8DEVTYPEKEYBOARD_JAPAN106 = 10;

        public const uint DI8DEVTYPEKEYBOARD_JAPANAX = 11;

        public const uint DI8DEVTYPEKEYBOARD_J3100 = 12;

        public const uint DI8DEVTYPE_LIMITEDGAMESUBTYPE = 1;

        public const uint DI8DEVTYPEJOYSTICK_STANDARD = 2;

        public const uint DI8DEVTYPEGAMEPAD_STANDARD = 2;

        public const uint DI8DEVTYPEGAMEPAD_TILT = 3;

        public const uint DI8DEVTYPEDRIVING_COMBINEDPEDALS = 2;

        public const uint DI8DEVTYPEDRIVING_DUALPEDALS = 3;

        public const uint DI8DEVTYPEDRIVING_THREEPEDALS = 4;

        public const uint DI8DEVTYPEDRIVING_HANDHELD = 5;

        public const uint DI8DEVTYPEFLIGHT_STICK = 2;

        public const uint DI8DEVTYPEFLIGHT_YOKE = 3;

        public const uint DI8DEVTYPEFLIGHT_RC = 4;

        public const uint DI8DEVTYPE1STPERSON_UNKNOWN = 2;

        public const uint DI8DEVTYPE1STPERSON_SIXDOF = 3;

        public const uint DI8DEVTYPE1STPERSON_SHOOTER = 4;

        public const uint DI8DEVTYPESCREENPTR_UNKNOWN = 2;

        public const uint DI8DEVTYPESCREENPTR_LIGHTGUN = 3;

        public const uint DI8DEVTYPESCREENPTR_LIGHTPEN = 4;

        public const uint DI8DEVTYPESCREENPTR_TOUCH = 5;

        public const uint DI8DEVTYPEREMOTE_UNKNOWN = 2;

        public const uint DI8DEVTYPEDEVICECTRL_UNKNOWN = 2;

        public const uint DI8DEVTYPEDEVICECTRL_COMMSSELECTION = 3;

        public const uint DI8DEVTYPEDEVICECTRL_COMMSSELECTION_HARDWIRED = 4;

        public const uint DI8DEVTYPESUPPLEMENTAL_UNKNOWN = 2;

        public const uint DI8DEVTYPESUPPLEMENTAL_2NDHANDCONTROLLER = 3;

        public const uint DI8DEVTYPESUPPLEMENTAL_HEADTRACKER = 4;

        public const uint DI8DEVTYPESUPPLEMENTAL_HANDTRACKER = 5;

        public const uint DI8DEVTYPESUPPLEMENTAL_SHIFTSTICKGATE = 6;

        public const uint DI8DEVTYPESUPPLEMENTAL_SHIFTER = 7;

        public const uint DI8DEVTYPESUPPLEMENTAL_THROTTLE = 8;

        public const uint DI8DEVTYPESUPPLEMENTAL_SPLITTHROTTLE = 9;

        public const uint DI8DEVTYPESUPPLEMENTAL_COMBINEDPEDALS = 10;

        public const uint DI8DEVTYPESUPPLEMENTAL_DUALPEDALS = 11;

        public const uint DI8DEVTYPESUPPLEMENTAL_THREEPEDALS = 12;

        public const uint DI8DEVTYPESUPPLEMENTAL_RUDDERPEDALS = 13;

        public const uint DIDC_ATTACHED = 0x00000001;

        public const uint DIDC_POLLEDDEVICE = 0x00000002;

        public const uint DIDC_EMULATED = 0x00000004;

        public const uint DIDC_POLLEDDATAFORMAT = 0x00000008;

        public const uint DIDC_FORCEFEEDBACK = 0x00000100;

        public const uint DIDC_FFATTACK = 0x00000200;

        public const uint DIDC_FFFADE = 0x00000400;

        public const uint DIDC_SATURATION = 0x00000800;

        public const uint DIDC_POSNEGCOEFFICIENTS = 0x00001000;

        public const uint DIDC_POSNEGSATURATION = 0x00002000;

        public const uint DIDC_DEADBAND = 0x00004000;

        public const uint DIDC_STARTDELAY = 0x00008000;

        public const uint DIDC_ALIAS = 0x00010000;

        public const uint DIDC_PHANTOM = 0x00020000;

        public const uint DIDC_HIDDEN = 0x00040000;

        public const uint DIDFT_ALL = 0x00000000;

        public const uint DIDFT_RELAXIS = 0x00000001;

        public const uint DIDFT_ABSAXIS = 0x00000002;

        public const uint DIDFT_AXIS = 0x00000003;

        public const uint DIDFT_PSHBUTTON = 0x00000004;

        public const uint DIDFT_TGLBUTTON = 0x00000008;

        public const uint DIDFT_BUTTON = 0x0000000C;

        public const uint DIDFT_POV = 0x00000010;

        public const uint DIDFT_COLLECTION = 0x00000040;

        public const uint DIDFT_NODATA = 0x00000080;

        public const uint DIDFT_ANYINSTANCE = 0x00FFFF00;

        public const uint DIDFT_FFACTUATOR = 0x01000000;

        public const uint DIDFT_FFEFFECTTRIGGER = 0x02000000;

        public const uint DIDFT_OUTPUT = 0x10000000;

        public const uint DIDFT_VENDORDEFINED = 0x04000000;

        public const uint DIDFT_ALIAS = 0x08000000;

        public const uint DIDFT_NOCOLLECTION = 0x00FFFF00;

        public const uint DIDF_ABSAXIS = 0x00000001;

        public const uint DIDF_RELAXIS = 0x00000002;

        public const uint DIA_FORCEFEEDBACK = 0x00000001;

        public const uint DIA_APPMAPPED = 0x00000002;

        public const uint DIA_APPNOMAP = 0x00000004;

        public const uint DIA_NORANGE = 0x00000008;

        public const uint DIA_APPFIXED = 0x00000010;

        public const uint DIAH_UNMAPPED = 0x00000000;

        public const uint DIAH_USERCONFIG = 0x00000001;

        public const uint DIAH_APPREQUESTED = 0x00000002;

        public const uint DIAH_HWAPP = 0x00000004;

        public const uint DIAH_HWDEFAULT = 0x00000008;

        public const uint DIAH_DEFAULT = 0x00000020;

        public const uint DIAH_ERROR = 0x80000000;

        public const uint DIAFTS_NEWDEVICELOW = 0xFFFFFFFF;

        public const uint DIAFTS_NEWDEVICEHIGH = 0xFFFFFFFF;

        public const uint DIAFTS_UNUSEDDEVICELOW = 0x00000000;

        public const uint DIAFTS_UNUSEDDEVICEHIGH = 0x00000000;

        public const uint DIDBAM_DEFAULT = 0x00000000;

        public const uint DIDBAM_PRESERVE = 0x00000001;

        public const uint DIDBAM_INITIALIZE = 0x00000002;

        public const uint DIDBAM_HWDEFAULTS = 0x00000004;

        public const uint DIDSAM_DEFAULT = 0x00000000;

        public const uint DIDSAM_NOUSER = 0x00000001;

        public const uint DIDSAM_FORCESAVE = 0x00000002;

        public const uint DICD_DEFAULT = 0x00000000;

        public const uint DICD_EDIT = 0x00000001;

        public const uint DIDIFT_CONFIGURATION = 0x00000001;

        public const uint DIDIFT_OVERLAY = 0x00000002;

        public const uint DIDAL_CENTERED = 0x00000000;

        public const uint DIDAL_LEFTALIGNED = 0x00000001;

        public const uint DIDAL_RIGHTALIGNED = 0x00000002;

        public const uint DIDAL_MIDDLE = 0x00000000;

        public const uint DIDAL_TOPALIGNED = 0x00000004;

        public const uint DIDAL_BOTTOMALIGNED = 0x00000008;

        public const uint DIDOI_FFACTUATOR = 0x00000001;

        public const uint DIDOI_FFEFFECTTRIGGER = 0x00000002;

        public const uint DIDOI_POLLED = 0x00008000;

        public const uint DIDOI_ASPECTPOSITION = 0x00000100;

        public const uint DIDOI_ASPECTVELOCITY = 0x00000200;

        public const uint DIDOI_ASPECTACCEL = 0x00000300;

        public const uint DIDOI_ASPECTFORCE = 0x00000400;

        public const uint DIDOI_ASPECTMASK = 0x00000F00;

        public const uint DIDOI_GUIDISUSAGE = 0x00010000;

        public const uint DIPH_DEVICE = 0;

        public const uint DIPH_BYOFFSET = 1;

        public const uint DIPH_BYID = 2;

        public const uint DIPH_BYUSAGE = 3;

        public const uint MAXCPOINTSNUM = 8;

        public const uint DIPROPAXISMODE_ABS = 0;

        public const uint DIPROPAXISMODE_REL = 1;

        public const uint DIPROPAUTOCENTER_OFF = 0;

        public const uint DIPROPAUTOCENTER_ON = 1;

        public const uint DIPROPCALIBRATIONMODE_COOKED = 0;

        public const uint DIPROPCALIBRATIONMODE_RAW = 1;

        public const uint DIGDD_PEEK = 0x00000001;

        public const uint DISCL_EXCLUSIVE = 0x00000001;

        public const uint DISCL_NONEXCLUSIVE = 0x00000002;

        public const uint DISCL_FOREGROUND = 0x00000004;

        public const uint DISCL_BACKGROUND = 0x00000008;

        public const uint DISCL_NOWINKEY = 0x00000010;

        public const uint DISFFC_RESET = 0x00000001;

        public const uint DISFFC_STOPALL = 0x00000002;

        public const uint DISFFC_PAUSE = 0x00000004;

        public const uint DISFFC_CONTINUE = 0x00000008;

        public const uint DISFFC_SETACTUATORSON = 0x00000010;

        public const uint DISFFC_SETACTUATORSOFF = 0x00000020;

        public const uint DIGFFS_EMPTY = 0x00000001;

        public const uint DIGFFS_STOPPED = 0x00000002;

        public const uint DIGFFS_PAUSED = 0x00000004;

        public const uint DIGFFS_ACTUATORSON = 0x00000010;

        public const uint DIGFFS_ACTUATORSOFF = 0x00000020;

        public const uint DIGFFS_POWERON = 0x00000040;

        public const uint DIGFFS_POWEROFF = 0x00000080;

        public const uint DIGFFS_SAFETYSWITCHON = 0x00000100;

        public const uint DIGFFS_SAFETYSWITCHOFF = 0x00000200;

        public const uint DIGFFS_USERFFSWITCHON = 0x00000400;

        public const uint DIGFFS_USERFFSWITCHOFF = 0x00000800;

        public const uint DIGFFS_DEVICELOST = 0x80000000;

        public const uint DISDD_CONTINUE = 0x00000001;

        public const uint DIFEF_DEFAULT = 0x00000000;

        public const uint DIFEF_INCLUDENONSTANDARD = 0x00000001;

        public const uint DIFEF_MODIFYIFNEEDED = 0x00000010;

        public const uint DIK_ESCAPE = 0x01;

        public const uint DIK_1 = 0x02;

        public const uint DIK_2 = 0x03;

        public const uint DIK_3 = 0x04;

        public const uint DIK_4 = 0x05;

        public const uint DIK_5 = 0x06;

        public const uint DIK_6 = 0x07;

        public const uint DIK_7 = 0x08;

        public const uint DIK_8 = 0x09;

        public const uint DIK_9 = 0x0A;

        public const uint DIK_0 = 0x0B;

        public const uint DIK_MINUS = 0x0C;

        public const uint DIK_EQUALS = 0x0D;

        public const uint DIK_BACK = 0x0E;

        public const uint DIK_TAB = 0x0F;

        public const uint DIK_Q = 0x10;

        public const uint DIK_W = 0x11;

        public const uint DIK_E = 0x12;

        public const uint DIK_R = 0x13;

        public const uint DIK_T = 0x14;

        public const uint DIK_Y = 0x15;

        public const uint DIK_U = 0x16;

        public const uint DIK_I = 0x17;

        public const uint DIK_O = 0x18;

        public const uint DIK_P = 0x19;

        public const uint DIK_LBRACKET = 0x1A;

        public const uint DIK_RBRACKET = 0x1B;

        public const uint DIK_RETURN = 0x1C;

        public const uint DIK_LCONTROL = 0x1D;

        public const uint DIK_A = 0x1E;

        public const uint DIK_S = 0x1F;

        public const uint DIK_D = 0x20;

        public const uint DIK_F = 0x21;

        public const uint DIK_G = 0x22;

        public const uint DIK_H = 0x23;

        public const uint DIK_J = 0x24;

        public const uint DIK_K = 0x25;

        public const uint DIK_L = 0x26;

        public const uint DIK_SEMICOLON = 0x27;

        public const uint DIK_APOSTROPHE = 0x28;

        public const uint DIK_GRAVE = 0x29;

        public const uint DIK_LSHIFT = 0x2A;

        public const uint DIK_BACKSLASH = 0x2B;

        public const uint DIK_Z = 0x2C;

        public const uint DIK_X = 0x2D;

        public const uint DIK_C = 0x2E;

        public const uint DIK_V = 0x2F;

        public const uint DIK_B = 0x30;

        public const uint DIK_N = 0x31;

        public const uint DIK_M = 0x32;

        public const uint DIK_COMMA = 0x33;

        public const uint DIK_PERIOD = 0x34;

        public const uint DIK_SLASH = 0x35;

        public const uint DIK_RSHIFT = 0x36;

        public const uint DIK_MULTIPLY = 0x37;

        public const uint DIK_LMENU = 0x38;

        public const uint DIK_SPACE = 0x39;

        public const uint DIK_CAPITAL = 0x3A;

        public const uint DIK_F1 = 0x3B;

        public const uint DIK_F2 = 0x3C;

        public const uint DIK_F3 = 0x3D;

        public const uint DIK_F4 = 0x3E;

        public const uint DIK_F5 = 0x3F;

        public const uint DIK_F6 = 0x40;

        public const uint DIK_F7 = 0x41;

        public const uint DIK_F8 = 0x42;

        public const uint DIK_F9 = 0x43;

        public const uint DIK_F10 = 0x44;

        public const uint DIK_NUMLOCK = 0x45;

        public const uint DIK_SCROLL = 0x46;

        public const uint DIK_NUMPAD7 = 0x47;

        public const uint DIK_NUMPAD8 = 0x48;

        public const uint DIK_NUMPAD9 = 0x49;

        public const uint DIK_SUBTRACT = 0x4A;

        public const uint DIK_NUMPAD4 = 0x4B;

        public const uint DIK_NUMPAD5 = 0x4C;

        public const uint DIK_NUMPAD6 = 0x4D;

        public const uint DIK_ADD = 0x4E;

        public const uint DIK_NUMPAD1 = 0x4F;

        public const uint DIK_NUMPAD2 = 0x50;

        public const uint DIK_NUMPAD3 = 0x51;

        public const uint DIK_NUMPAD0 = 0x52;

        public const uint DIK_DECIMAL = 0x53;

        public const uint DIK_OEM_102 = 0x56;

        public const uint DIK_F11 = 0x57;

        public const uint DIK_F12 = 0x58;

        public const uint DIK_F13 = 0x64;

        public const uint DIK_F14 = 0x65;

        public const uint DIK_F15 = 0x66;

        public const uint DIK_KANA = 0x70;

        public const uint DIK_ABNT_C1 = 0x73;

        public const uint DIK_CONVERT = 0x79;

        public const uint DIK_NOCONVERT = 0x7B;

        public const uint DIK_YEN = 0x7D;

        public const uint DIK_ABNT_C2 = 0x7E;

        public const uint DIK_NUMPADEQUALS = 0x8D;

        public const uint DIK_PREVTRACK = 0x90;

        public const uint DIK_AT = 0x91;

        public const uint DIK_COLON = 0x92;

        public const uint DIK_UNDERLINE = 0x93;

        public const uint DIK_KANJI = 0x94;

        public const uint DIK_STOP = 0x95;

        public const uint DIK_AX = 0x96;

        public const uint DIK_UNLABELED = 0x97;

        public const uint DIK_NEXTTRACK = 0x99;

        public const uint DIK_NUMPADENTER = 0x9C;

        public const uint DIK_RCONTROL = 0x9D;

        public const uint DIK_MUTE = 0xA0;

        public const uint DIK_CALCULATOR = 0xA1;

        public const uint DIK_PLAYPAUSE = 0xA2;

        public const uint DIK_MEDIASTOP = 0xA4;

        public const uint DIK_VOLUMEDOWN = 0xAE;

        public const uint DIK_VOLUMEUP = 0xB0;

        public const uint DIK_WEBHOME = 0xB2;

        public const uint DIK_NUMPADCOMMA = 0xB3;

        public const uint DIK_DIVIDE = 0xB5;

        public const uint DIK_SYSRQ = 0xB7;

        public const uint DIK_RMENU = 0xB8;

        public const uint DIK_PAUSE = 0xC5;

        public const uint DIK_HOME = 0xC7;

        public const uint DIK_UP = 0xC8;

        public const uint DIK_PRIOR = 0xC9;

        public const uint DIK_LEFT = 0xCB;

        public const uint DIK_RIGHT = 0xCD;

        public const uint DIK_END = 0xCF;

        public const uint DIK_DOWN = 0xD0;

        public const uint DIK_NEXT = 0xD1;

        public const uint DIK_INSERT = 0xD2;

        public const uint DIK_DELETE = 0xD3;

        public const uint DIK_LWIN = 0xDB;

        public const uint DIK_RWIN = 0xDC;

        public const uint DIK_APPS = 0xDD;

        public const uint DIK_POWER = 0xDE;

        public const uint DIK_SLEEP = 0xDF;

        public const uint DIK_WAKE = 0xE3;

        public const uint DIK_WEBSEARCH = 0xE5;

        public const uint DIK_WEBFAVORITES = 0xE6;

        public const uint DIK_WEBREFRESH = 0xE7;

        public const uint DIK_WEBSTOP = 0xE8;

        public const uint DIK_WEBFORWARD = 0xE9;

        public const uint DIK_WEBBACK = 0xEA;

        public const uint DIK_MYCOMPUTER = 0xEB;

        public const uint DIK_MAIL = 0xEC;

        public const uint DIK_MEDIASELECT = 0xED;

        public const uint DIENUM_STOP = 0;

        public const uint DIENUM_CONTINUE = 1;

        public const uint DIEDFL_ALLDEVICES = 0x00000000;

        public const uint DIEDFL_ATTACHEDONLY = 0x00000001;

        public const uint DIEDFL_FORCEFEEDBACK = 0x00000100;

        public const uint DIEDFL_INCLUDEALIASES = 0x00010000;

        public const uint DIEDFL_INCLUDEPHANTOMS = 0x00020000;

        public const uint DIEDFL_INCLUDEHIDDEN = 0x00040000;

        public const uint DIEDBS_MAPPEDPRI1 = 0x00000001;

        public const uint DIEDBS_MAPPEDPRI2 = 0x00000002;

        public const uint DIEDBS_RECENTDEVICE = 0x00000010;

        public const uint DIEDBS_NEWDEVICE = 0x00000020;

        public const uint DIEDBSFL_ATTACHEDONLY = 0x00000000;

        public const uint DIEDBSFL_THISUSER = 0x00000010;

        public const uint DIEDBSFL_AVAILABLEDEVICES = 0x00001000;

        public const uint DIEDBSFL_MULTIMICEKEYBOARDS = 0x00002000;

        public const uint DIEDBSFL_NONGAMINGDEVICES = 0x00004000;

        public const uint DIEDBSFL_VALID = 0x00007110;

        [NativeTypeName("HRESULT")]
        public const int DI_POLLEDDEVICE = 0x00000002;

        [NativeTypeName("HRESULT")]
        public const int DI_DOWNLOADSKIPPED = 0x00000003;

        [NativeTypeName("HRESULT")]
        public const int DI_EFFECTRESTARTED = 0x00000004;

        [NativeTypeName("HRESULT")]
        public const int DI_TRUNCATED = 0x00000008;

        [NativeTypeName("HRESULT")]
        public const int DI_SETTINGSNOTSAVED = 0x0000000B;

        [NativeTypeName("HRESULT")]
        public const int DI_TRUNCATEDANDRESTARTED = 0x0000000C;

        [NativeTypeName("HRESULT")]
        public const int DI_WRITEPROTECT = 0x00000013;

        [NativeTypeName("HRESULT")]
        public const int DIERR_OLDDIRECTINPUTVERSION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_OLD_WIN_VERSION));

        [NativeTypeName("HRESULT")]
        public const int DIERR_BETADIRECTINPUTVERSION = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_RMODE_APP));

        [NativeTypeName("HRESULT")]
        public const int DIERR_BADDRIVERVER = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_BAD_DRIVER_LEVEL));

        [NativeTypeName("HRESULT")]
        public const int DIERR_NOTFOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_FILE_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int DIERR_OBJECTNOTFOUND = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_FILE_NOT_FOUND));

        [NativeTypeName("HRESULT")]
        public const int DIERR_NOTINITIALIZED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_NOT_READY));

        [NativeTypeName("HRESULT")]
        public const int DIERR_ALREADYINITIALIZED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_ALREADY_INITIALIZED));

        [NativeTypeName("HRESULT")]
        public const int DIERR_INPUTLOST = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_READ_FAULT));

        [NativeTypeName("HRESULT")]
        public const int DIERR_ACQUIRED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_BUSY));

        [NativeTypeName("HRESULT")]
        public const int DIERR_NOTACQUIRED = unchecked((int)((SEVERITY_ERROR) << 31) | (((int)(FACILITY_WIN32)) << 16) | (int)(ERROR_INVALID_ACCESS));

        public const int DIERR_INSUFFICIENTPRIVS = unchecked((int)0x80040200);

        public const int DIERR_DEVICEFULL = unchecked((int)0x80040201);

        public const int DIERR_MOREDATA = unchecked((int)0x80040202);

        public const int DIERR_NOTDOWNLOADED = unchecked((int)0x80040203);

        public const int DIERR_HASEFFECTS = unchecked((int)0x80040204);

        public const int DIERR_NOTEXCLUSIVEACQUIRED = unchecked((int)0x80040205);

        public const int DIERR_INCOMPLETEEFFECT = unchecked((int)0x80040206);

        public const int DIERR_NOTBUFFERED = unchecked((int)0x80040207);

        public const int DIERR_EFFECTPLAYING = unchecked((int)0x80040208);

        public const int DIERR_UNPLUGGED = unchecked((int)0x80040209);

        public const int DIERR_REPORTFULL = unchecked((int)0x8004020A);

        public const int DIERR_MAPFILEFAIL = unchecked((int)0x8004020B);

        public const uint DIKEYBOARD_ESCAPE = 0x81000401;

        public const uint DIKEYBOARD_1 = 0x81000402;

        public const uint DIKEYBOARD_2 = 0x81000403;

        public const uint DIKEYBOARD_3 = 0x81000404;

        public const uint DIKEYBOARD_4 = 0x81000405;

        public const uint DIKEYBOARD_5 = 0x81000406;

        public const uint DIKEYBOARD_6 = 0x81000407;

        public const uint DIKEYBOARD_7 = 0x81000408;

        public const uint DIKEYBOARD_8 = 0x81000409;

        public const uint DIKEYBOARD_9 = 0x8100040A;

        public const uint DIKEYBOARD_0 = 0x8100040B;

        public const uint DIKEYBOARD_MINUS = 0x8100040C;

        public const uint DIKEYBOARD_EQUALS = 0x8100040D;

        public const uint DIKEYBOARD_BACK = 0x8100040E;

        public const uint DIKEYBOARD_TAB = 0x8100040F;

        public const uint DIKEYBOARD_Q = 0x81000410;

        public const uint DIKEYBOARD_W = 0x81000411;

        public const uint DIKEYBOARD_E = 0x81000412;

        public const uint DIKEYBOARD_R = 0x81000413;

        public const uint DIKEYBOARD_T = 0x81000414;

        public const uint DIKEYBOARD_Y = 0x81000415;

        public const uint DIKEYBOARD_U = 0x81000416;

        public const uint DIKEYBOARD_I = 0x81000417;

        public const uint DIKEYBOARD_O = 0x81000418;

        public const uint DIKEYBOARD_P = 0x81000419;

        public const uint DIKEYBOARD_LBRACKET = 0x8100041A;

        public const uint DIKEYBOARD_RBRACKET = 0x8100041B;

        public const uint DIKEYBOARD_RETURN = 0x8100041C;

        public const uint DIKEYBOARD_LCONTROL = 0x8100041D;

        public const uint DIKEYBOARD_A = 0x8100041E;

        public const uint DIKEYBOARD_S = 0x8100041F;

        public const uint DIKEYBOARD_D = 0x81000420;

        public const uint DIKEYBOARD_F = 0x81000421;

        public const uint DIKEYBOARD_G = 0x81000422;

        public const uint DIKEYBOARD_H = 0x81000423;

        public const uint DIKEYBOARD_J = 0x81000424;

        public const uint DIKEYBOARD_K = 0x81000425;

        public const uint DIKEYBOARD_L = 0x81000426;

        public const uint DIKEYBOARD_SEMICOLON = 0x81000427;

        public const uint DIKEYBOARD_APOSTROPHE = 0x81000428;

        public const uint DIKEYBOARD_GRAVE = 0x81000429;

        public const uint DIKEYBOARD_LSHIFT = 0x8100042A;

        public const uint DIKEYBOARD_BACKSLASH = 0x8100042B;

        public const uint DIKEYBOARD_Z = 0x8100042C;

        public const uint DIKEYBOARD_X = 0x8100042D;

        public const uint DIKEYBOARD_C = 0x8100042E;

        public const uint DIKEYBOARD_V = 0x8100042F;

        public const uint DIKEYBOARD_B = 0x81000430;

        public const uint DIKEYBOARD_N = 0x81000431;

        public const uint DIKEYBOARD_M = 0x81000432;

        public const uint DIKEYBOARD_COMMA = 0x81000433;

        public const uint DIKEYBOARD_PERIOD = 0x81000434;

        public const uint DIKEYBOARD_SLASH = 0x81000435;

        public const uint DIKEYBOARD_RSHIFT = 0x81000436;

        public const uint DIKEYBOARD_MULTIPLY = 0x81000437;

        public const uint DIKEYBOARD_LMENU = 0x81000438;

        public const uint DIKEYBOARD_SPACE = 0x81000439;

        public const uint DIKEYBOARD_CAPITAL = 0x8100043A;

        public const uint DIKEYBOARD_F1 = 0x8100043B;

        public const uint DIKEYBOARD_F2 = 0x8100043C;

        public const uint DIKEYBOARD_F3 = 0x8100043D;

        public const uint DIKEYBOARD_F4 = 0x8100043E;

        public const uint DIKEYBOARD_F5 = 0x8100043F;

        public const uint DIKEYBOARD_F6 = 0x81000440;

        public const uint DIKEYBOARD_F7 = 0x81000441;

        public const uint DIKEYBOARD_F8 = 0x81000442;

        public const uint DIKEYBOARD_F9 = 0x81000443;

        public const uint DIKEYBOARD_F10 = 0x81000444;

        public const uint DIKEYBOARD_NUMLOCK = 0x81000445;

        public const uint DIKEYBOARD_SCROLL = 0x81000446;

        public const uint DIKEYBOARD_NUMPAD7 = 0x81000447;

        public const uint DIKEYBOARD_NUMPAD8 = 0x81000448;

        public const uint DIKEYBOARD_NUMPAD9 = 0x81000449;

        public const uint DIKEYBOARD_SUBTRACT = 0x8100044A;

        public const uint DIKEYBOARD_NUMPAD4 = 0x8100044B;

        public const uint DIKEYBOARD_NUMPAD5 = 0x8100044C;

        public const uint DIKEYBOARD_NUMPAD6 = 0x8100044D;

        public const uint DIKEYBOARD_ADD = 0x8100044E;

        public const uint DIKEYBOARD_NUMPAD1 = 0x8100044F;

        public const uint DIKEYBOARD_NUMPAD2 = 0x81000450;

        public const uint DIKEYBOARD_NUMPAD3 = 0x81000451;

        public const uint DIKEYBOARD_NUMPAD0 = 0x81000452;

        public const uint DIKEYBOARD_DECIMAL = 0x81000453;

        public const uint DIKEYBOARD_OEM_102 = 0x81000456;

        public const uint DIKEYBOARD_F11 = 0x81000457;

        public const uint DIKEYBOARD_F12 = 0x81000458;

        public const uint DIKEYBOARD_F13 = 0x81000464;

        public const uint DIKEYBOARD_F14 = 0x81000465;

        public const uint DIKEYBOARD_F15 = 0x81000466;

        public const uint DIKEYBOARD_KANA = 0x81000470;

        public const uint DIKEYBOARD_ABNT_C1 = 0x81000473;

        public const uint DIKEYBOARD_CONVERT = 0x81000479;

        public const uint DIKEYBOARD_NOCONVERT = 0x8100047B;

        public const uint DIKEYBOARD_YEN = 0x8100047D;

        public const uint DIKEYBOARD_ABNT_C2 = 0x8100047E;

        public const uint DIKEYBOARD_NUMPADEQUALS = 0x8100048D;

        public const uint DIKEYBOARD_PREVTRACK = 0x81000490;

        public const uint DIKEYBOARD_AT = 0x81000491;

        public const uint DIKEYBOARD_COLON = 0x81000492;

        public const uint DIKEYBOARD_UNDERLINE = 0x81000493;

        public const uint DIKEYBOARD_KANJI = 0x81000494;

        public const uint DIKEYBOARD_STOP = 0x81000495;

        public const uint DIKEYBOARD_AX = 0x81000496;

        public const uint DIKEYBOARD_UNLABELED = 0x81000497;

        public const uint DIKEYBOARD_NEXTTRACK = 0x81000499;

        public const uint DIKEYBOARD_NUMPADENTER = 0x8100049C;

        public const uint DIKEYBOARD_RCONTROL = 0x8100049D;

        public const uint DIKEYBOARD_MUTE = 0x810004A0;

        public const uint DIKEYBOARD_CALCULATOR = 0x810004A1;

        public const uint DIKEYBOARD_PLAYPAUSE = 0x810004A2;

        public const uint DIKEYBOARD_MEDIASTOP = 0x810004A4;

        public const uint DIKEYBOARD_VOLUMEDOWN = 0x810004AE;

        public const uint DIKEYBOARD_VOLUMEUP = 0x810004B0;

        public const uint DIKEYBOARD_WEBHOME = 0x810004B2;

        public const uint DIKEYBOARD_NUMPADCOMMA = 0x810004B3;

        public const uint DIKEYBOARD_DIVIDE = 0x810004B5;

        public const uint DIKEYBOARD_SYSRQ = 0x810004B7;

        public const uint DIKEYBOARD_RMENU = 0x810004B8;

        public const uint DIKEYBOARD_PAUSE = 0x810004C5;

        public const uint DIKEYBOARD_HOME = 0x810004C7;

        public const uint DIKEYBOARD_UP = 0x810004C8;

        public const uint DIKEYBOARD_PRIOR = 0x810004C9;

        public const uint DIKEYBOARD_LEFT = 0x810004CB;

        public const uint DIKEYBOARD_RIGHT = 0x810004CD;

        public const uint DIKEYBOARD_END = 0x810004CF;

        public const uint DIKEYBOARD_DOWN = 0x810004D0;

        public const uint DIKEYBOARD_NEXT = 0x810004D1;

        public const uint DIKEYBOARD_INSERT = 0x810004D2;

        public const uint DIKEYBOARD_DELETE = 0x810004D3;

        public const uint DIKEYBOARD_LWIN = 0x810004DB;

        public const uint DIKEYBOARD_RWIN = 0x810004DC;

        public const uint DIKEYBOARD_APPS = 0x810004DD;

        public const uint DIKEYBOARD_POWER = 0x810004DE;

        public const uint DIKEYBOARD_SLEEP = 0x810004DF;

        public const uint DIKEYBOARD_WAKE = 0x810004E3;

        public const uint DIKEYBOARD_WEBSEARCH = 0x810004E5;

        public const uint DIKEYBOARD_WEBFAVORITES = 0x810004E6;

        public const uint DIKEYBOARD_WEBREFRESH = 0x810004E7;

        public const uint DIKEYBOARD_WEBSTOP = 0x810004E8;

        public const uint DIKEYBOARD_WEBFORWARD = 0x810004E9;

        public const uint DIKEYBOARD_WEBBACK = 0x810004EA;

        public const uint DIKEYBOARD_MYCOMPUTER = 0x810004EB;

        public const uint DIKEYBOARD_MAIL = 0x810004EC;

        public const uint DIKEYBOARD_MEDIASELECT = 0x810004ED;

        public const uint DIVOICE_CHANNEL1 = 0x83000401;

        public const uint DIVOICE_CHANNEL2 = 0x83000402;

        public const uint DIVOICE_CHANNEL3 = 0x83000403;

        public const uint DIVOICE_CHANNEL4 = 0x83000404;

        public const uint DIVOICE_CHANNEL5 = 0x83000405;

        public const uint DIVOICE_CHANNEL6 = 0x83000406;

        public const uint DIVOICE_CHANNEL7 = 0x83000407;

        public const uint DIVOICE_CHANNEL8 = 0x83000408;

        public const uint DIVOICE_TEAM = 0x83000409;

        public const uint DIVOICE_ALL = 0x8300040A;

        public const uint DIVOICE_RECORDMUTE = 0x8300040B;

        public const uint DIVOICE_PLAYBACKMUTE = 0x8300040C;

        public const uint DIVOICE_TRANSMIT = 0x8300040D;

        public const uint DIVOICE_VOICECOMMAND = 0x83000410;

        public const uint DIVIRTUAL_DRIVING_RACE = 0x01000000;

        public const uint DIAXIS_DRIVINGR_STEER = 0x01008A01;

        public const uint DIAXIS_DRIVINGR_ACCELERATE = 0x01039202;

        public const uint DIAXIS_DRIVINGR_BRAKE = 0x01041203;

        public const uint DIBUTTON_DRIVINGR_SHIFTUP = 0x01000C01;

        public const uint DIBUTTON_DRIVINGR_SHIFTDOWN = 0x01000C02;

        public const uint DIBUTTON_DRIVINGR_VIEW = 0x01001C03;

        public const uint DIBUTTON_DRIVINGR_MENU = 0x010004FD;

        public const uint DIAXIS_DRIVINGR_ACCEL_AND_BRAKE = 0x01014A04;

        public const uint DIHATSWITCH_DRIVINGR_GLANCE = 0x01004601;

        public const uint DIBUTTON_DRIVINGR_BRAKE = 0x01004C04;

        public const uint DIBUTTON_DRIVINGR_DASHBOARD = 0x01004405;

        public const uint DIBUTTON_DRIVINGR_AIDS = 0x01004406;

        public const uint DIBUTTON_DRIVINGR_MAP = 0x01004407;

        public const uint DIBUTTON_DRIVINGR_BOOST = 0x01004408;

        public const uint DIBUTTON_DRIVINGR_PIT = 0x01004409;

        public const uint DIBUTTON_DRIVINGR_ACCELERATE_LINK = 0x0103D4E0;

        public const uint DIBUTTON_DRIVINGR_STEER_LEFT_LINK = 0x0100CCE4;

        public const uint DIBUTTON_DRIVINGR_STEER_RIGHT_LINK = 0x0100CCEC;

        public const uint DIBUTTON_DRIVINGR_GLANCE_LEFT_LINK = 0x0107C4E4;

        public const uint DIBUTTON_DRIVINGR_GLANCE_RIGHT_LINK = 0x0107C4EC;

        public const uint DIBUTTON_DRIVINGR_DEVICE = 0x010044FE;

        public const uint DIBUTTON_DRIVINGR_PAUSE = 0x010044FC;

        public const uint DIVIRTUAL_DRIVING_COMBAT = 0x02000000;

        public const uint DIAXIS_DRIVINGC_STEER = 0x02008A01;

        public const uint DIAXIS_DRIVINGC_ACCELERATE = 0x02039202;

        public const uint DIAXIS_DRIVINGC_BRAKE = 0x02041203;

        public const uint DIBUTTON_DRIVINGC_FIRE = 0x02000C01;

        public const uint DIBUTTON_DRIVINGC_WEAPONS = 0x02000C02;

        public const uint DIBUTTON_DRIVINGC_TARGET = 0x02000C03;

        public const uint DIBUTTON_DRIVINGC_MENU = 0x020004FD;

        public const uint DIAXIS_DRIVINGC_ACCEL_AND_BRAKE = 0x02014A04;

        public const uint DIHATSWITCH_DRIVINGC_GLANCE = 0x02004601;

        public const uint DIBUTTON_DRIVINGC_SHIFTUP = 0x02004C04;

        public const uint DIBUTTON_DRIVINGC_SHIFTDOWN = 0x02004C05;

        public const uint DIBUTTON_DRIVINGC_DASHBOARD = 0x02004406;

        public const uint DIBUTTON_DRIVINGC_AIDS = 0x02004407;

        public const uint DIBUTTON_DRIVINGC_BRAKE = 0x02004C08;

        public const uint DIBUTTON_DRIVINGC_FIRESECONDARY = 0x02004C09;

        public const uint DIBUTTON_DRIVINGC_ACCELERATE_LINK = 0x0203D4E0;

        public const uint DIBUTTON_DRIVINGC_STEER_LEFT_LINK = 0x0200CCE4;

        public const uint DIBUTTON_DRIVINGC_STEER_RIGHT_LINK = 0x0200CCEC;

        public const uint DIBUTTON_DRIVINGC_GLANCE_LEFT_LINK = 0x0207C4E4;

        public const uint DIBUTTON_DRIVINGC_GLANCE_RIGHT_LINK = 0x0207C4EC;

        public const uint DIBUTTON_DRIVINGC_DEVICE = 0x020044FE;

        public const uint DIBUTTON_DRIVINGC_PAUSE = 0x020044FC;

        public const uint DIVIRTUAL_DRIVING_TANK = 0x03000000;

        public const uint DIAXIS_DRIVINGT_STEER = 0x03008A01;

        public const uint DIAXIS_DRIVINGT_BARREL = 0x03010202;

        public const uint DIAXIS_DRIVINGT_ACCELERATE = 0x03039203;

        public const uint DIAXIS_DRIVINGT_ROTATE = 0x03020204;

        public const uint DIBUTTON_DRIVINGT_FIRE = 0x03000C01;

        public const uint DIBUTTON_DRIVINGT_WEAPONS = 0x03000C02;

        public const uint DIBUTTON_DRIVINGT_TARGET = 0x03000C03;

        public const uint DIBUTTON_DRIVINGT_MENU = 0x030004FD;

        public const uint DIHATSWITCH_DRIVINGT_GLANCE = 0x03004601;

        public const uint DIAXIS_DRIVINGT_BRAKE = 0x03045205;

        public const uint DIAXIS_DRIVINGT_ACCEL_AND_BRAKE = 0x03014A06;

        public const uint DIBUTTON_DRIVINGT_VIEW = 0x03005C04;

        public const uint DIBUTTON_DRIVINGT_DASHBOARD = 0x03005C05;

        public const uint DIBUTTON_DRIVINGT_BRAKE = 0x03004C06;

        public const uint DIBUTTON_DRIVINGT_FIRESECONDARY = 0x03004C07;

        public const uint DIBUTTON_DRIVINGT_ACCELERATE_LINK = 0x0303D4E0;

        public const uint DIBUTTON_DRIVINGT_STEER_LEFT_LINK = 0x0300CCE4;

        public const uint DIBUTTON_DRIVINGT_STEER_RIGHT_LINK = 0x0300CCEC;

        public const uint DIBUTTON_DRIVINGT_BARREL_UP_LINK = 0x030144E0;

        public const uint DIBUTTON_DRIVINGT_BARREL_DOWN_LINK = 0x030144E8;

        public const uint DIBUTTON_DRIVINGT_ROTATE_LEFT_LINK = 0x030244E4;

        public const uint DIBUTTON_DRIVINGT_ROTATE_RIGHT_LINK = 0x030244EC;

        public const uint DIBUTTON_DRIVINGT_GLANCE_LEFT_LINK = 0x0307C4E4;

        public const uint DIBUTTON_DRIVINGT_GLANCE_RIGHT_LINK = 0x0307C4EC;

        public const uint DIBUTTON_DRIVINGT_DEVICE = 0x030044FE;

        public const uint DIBUTTON_DRIVINGT_PAUSE = 0x030044FC;

        public const uint DIVIRTUAL_FLYING_CIVILIAN = 0x04000000;

        public const uint DIAXIS_FLYINGC_BANK = 0x04008A01;

        public const uint DIAXIS_FLYINGC_PITCH = 0x04010A02;

        public const uint DIAXIS_FLYINGC_THROTTLE = 0x04039203;

        public const uint DIBUTTON_FLYINGC_VIEW = 0x04002401;

        public const uint DIBUTTON_FLYINGC_DISPLAY = 0x04002402;

        public const uint DIBUTTON_FLYINGC_GEAR = 0x04002C03;

        public const uint DIBUTTON_FLYINGC_MENU = 0x040004FD;

        public const uint DIHATSWITCH_FLYINGC_GLANCE = 0x04004601;

        public const uint DIAXIS_FLYINGC_BRAKE = 0x04046A04;

        public const uint DIAXIS_FLYINGC_RUDDER = 0x04025205;

        public const uint DIAXIS_FLYINGC_FLAPS = 0x04055A06;

        public const uint DIBUTTON_FLYINGC_FLAPSUP = 0x04006404;

        public const uint DIBUTTON_FLYINGC_FLAPSDOWN = 0x04006405;

        public const uint DIBUTTON_FLYINGC_BRAKE_LINK = 0x04046CE0;

        public const uint DIBUTTON_FLYINGC_FASTER_LINK = 0x0403D4E0;

        public const uint DIBUTTON_FLYINGC_SLOWER_LINK = 0x0403D4E8;

        public const uint DIBUTTON_FLYINGC_GLANCE_LEFT_LINK = 0x0407C4E4;

        public const uint DIBUTTON_FLYINGC_GLANCE_RIGHT_LINK = 0x0407C4EC;

        public const uint DIBUTTON_FLYINGC_GLANCE_UP_LINK = 0x0407C4E0;

        public const uint DIBUTTON_FLYINGC_GLANCE_DOWN_LINK = 0x0407C4E8;

        public const uint DIBUTTON_FLYINGC_DEVICE = 0x040044FE;

        public const uint DIBUTTON_FLYINGC_PAUSE = 0x040044FC;

        public const uint DIVIRTUAL_FLYING_MILITARY = 0x05000000;

        public const uint DIAXIS_FLYINGM_BANK = 0x05008A01;

        public const uint DIAXIS_FLYINGM_PITCH = 0x05010A02;

        public const uint DIAXIS_FLYINGM_THROTTLE = 0x05039203;

        public const uint DIBUTTON_FLYINGM_FIRE = 0x05000C01;

        public const uint DIBUTTON_FLYINGM_WEAPONS = 0x05000C02;

        public const uint DIBUTTON_FLYINGM_TARGET = 0x05000C03;

        public const uint DIBUTTON_FLYINGM_MENU = 0x050004FD;

        public const uint DIHATSWITCH_FLYINGM_GLANCE = 0x05004601;

        public const uint DIBUTTON_FLYINGM_COUNTER = 0x05005C04;

        public const uint DIAXIS_FLYINGM_RUDDER = 0x05024A04;

        public const uint DIAXIS_FLYINGM_BRAKE = 0x05046205;

        public const uint DIBUTTON_FLYINGM_VIEW = 0x05006405;

        public const uint DIBUTTON_FLYINGM_DISPLAY = 0x05006406;

        public const uint DIAXIS_FLYINGM_FLAPS = 0x05055206;

        public const uint DIBUTTON_FLYINGM_FLAPSUP = 0x05005407;

        public const uint DIBUTTON_FLYINGM_FLAPSDOWN = 0x05005408;

        public const uint DIBUTTON_FLYINGM_FIRESECONDARY = 0x05004C09;

        public const uint DIBUTTON_FLYINGM_GEAR = 0x0500640A;

        public const uint DIBUTTON_FLYINGM_BRAKE_LINK = 0x050464E0;

        public const uint DIBUTTON_FLYINGM_FASTER_LINK = 0x0503D4E0;

        public const uint DIBUTTON_FLYINGM_SLOWER_LINK = 0x0503D4E8;

        public const uint DIBUTTON_FLYINGM_GLANCE_LEFT_LINK = 0x0507C4E4;

        public const uint DIBUTTON_FLYINGM_GLANCE_RIGHT_LINK = 0x0507C4EC;

        public const uint DIBUTTON_FLYINGM_GLANCE_UP_LINK = 0x0507C4E0;

        public const uint DIBUTTON_FLYINGM_GLANCE_DOWN_LINK = 0x0507C4E8;

        public const uint DIBUTTON_FLYINGM_DEVICE = 0x050044FE;

        public const uint DIBUTTON_FLYINGM_PAUSE = 0x050044FC;

        public const uint DIVIRTUAL_FLYING_HELICOPTER = 0x06000000;

        public const uint DIAXIS_FLYINGH_BANK = 0x06008A01;

        public const uint DIAXIS_FLYINGH_PITCH = 0x06010A02;

        public const uint DIAXIS_FLYINGH_COLLECTIVE = 0x06018A03;

        public const uint DIBUTTON_FLYINGH_FIRE = 0x06001401;

        public const uint DIBUTTON_FLYINGH_WEAPONS = 0x06001402;

        public const uint DIBUTTON_FLYINGH_TARGET = 0x06001403;

        public const uint DIBUTTON_FLYINGH_MENU = 0x060004FD;

        public const uint DIHATSWITCH_FLYINGH_GLANCE = 0x06004601;

        public const uint DIAXIS_FLYINGH_TORQUE = 0x06025A04;

        public const uint DIAXIS_FLYINGH_THROTTLE = 0x0603DA05;

        public const uint DIBUTTON_FLYINGH_COUNTER = 0x06005404;

        public const uint DIBUTTON_FLYINGH_VIEW = 0x06006405;

        public const uint DIBUTTON_FLYINGH_GEAR = 0x06006406;

        public const uint DIBUTTON_FLYINGH_FIRESECONDARY = 0x06004C07;

        public const uint DIBUTTON_FLYINGH_FASTER_LINK = 0x0603DCE0;

        public const uint DIBUTTON_FLYINGH_SLOWER_LINK = 0x0603DCE8;

        public const uint DIBUTTON_FLYINGH_GLANCE_LEFT_LINK = 0x0607C4E4;

        public const uint DIBUTTON_FLYINGH_GLANCE_RIGHT_LINK = 0x0607C4EC;

        public const uint DIBUTTON_FLYINGH_GLANCE_UP_LINK = 0x0607C4E0;

        public const uint DIBUTTON_FLYINGH_GLANCE_DOWN_LINK = 0x0607C4E8;

        public const uint DIBUTTON_FLYINGH_DEVICE = 0x060044FE;

        public const uint DIBUTTON_FLYINGH_PAUSE = 0x060044FC;

        public const uint DIVIRTUAL_SPACESIM = 0x07000000;

        public const uint DIAXIS_SPACESIM_LATERAL = 0x07008201;

        public const uint DIAXIS_SPACESIM_MOVE = 0x07010202;

        public const uint DIAXIS_SPACESIM_THROTTLE = 0x07038203;

        public const uint DIBUTTON_SPACESIM_FIRE = 0x07000401;

        public const uint DIBUTTON_SPACESIM_WEAPONS = 0x07000402;

        public const uint DIBUTTON_SPACESIM_TARGET = 0x07000403;

        public const uint DIBUTTON_SPACESIM_MENU = 0x070004FD;

        public const uint DIHATSWITCH_SPACESIM_GLANCE = 0x07004601;

        public const uint DIAXIS_SPACESIM_CLIMB = 0x0701C204;

        public const uint DIAXIS_SPACESIM_ROTATE = 0x07024205;

        public const uint DIBUTTON_SPACESIM_VIEW = 0x07004404;

        public const uint DIBUTTON_SPACESIM_DISPLAY = 0x07004405;

        public const uint DIBUTTON_SPACESIM_RAISE = 0x07004406;

        public const uint DIBUTTON_SPACESIM_LOWER = 0x07004407;

        public const uint DIBUTTON_SPACESIM_GEAR = 0x07004408;

        public const uint DIBUTTON_SPACESIM_FIRESECONDARY = 0x07004409;

        public const uint DIBUTTON_SPACESIM_LEFT_LINK = 0x0700C4E4;

        public const uint DIBUTTON_SPACESIM_RIGHT_LINK = 0x0700C4EC;

        public const uint DIBUTTON_SPACESIM_FORWARD_LINK = 0x070144E0;

        public const uint DIBUTTON_SPACESIM_BACKWARD_LINK = 0x070144E8;

        public const uint DIBUTTON_SPACESIM_FASTER_LINK = 0x0703C4E0;

        public const uint DIBUTTON_SPACESIM_SLOWER_LINK = 0x0703C4E8;

        public const uint DIBUTTON_SPACESIM_TURN_LEFT_LINK = 0x070244E4;

        public const uint DIBUTTON_SPACESIM_TURN_RIGHT_LINK = 0x070244EC;

        public const uint DIBUTTON_SPACESIM_GLANCE_LEFT_LINK = 0x0707C4E4;

        public const uint DIBUTTON_SPACESIM_GLANCE_RIGHT_LINK = 0x0707C4EC;

        public const uint DIBUTTON_SPACESIM_GLANCE_UP_LINK = 0x0707C4E0;

        public const uint DIBUTTON_SPACESIM_GLANCE_DOWN_LINK = 0x0707C4E8;

        public const uint DIBUTTON_SPACESIM_DEVICE = 0x070044FE;

        public const uint DIBUTTON_SPACESIM_PAUSE = 0x070044FC;

        public const uint DIVIRTUAL_FIGHTING_HAND2HAND = 0x08000000;

        public const uint DIAXIS_FIGHTINGH_LATERAL = 0x08008201;

        public const uint DIAXIS_FIGHTINGH_MOVE = 0x08010202;

        public const uint DIBUTTON_FIGHTINGH_PUNCH = 0x08000401;

        public const uint DIBUTTON_FIGHTINGH_KICK = 0x08000402;

        public const uint DIBUTTON_FIGHTINGH_BLOCK = 0x08000403;

        public const uint DIBUTTON_FIGHTINGH_CROUCH = 0x08000404;

        public const uint DIBUTTON_FIGHTINGH_JUMP = 0x08000405;

        public const uint DIBUTTON_FIGHTINGH_SPECIAL1 = 0x08000406;

        public const uint DIBUTTON_FIGHTINGH_SPECIAL2 = 0x08000407;

        public const uint DIBUTTON_FIGHTINGH_MENU = 0x080004FD;

        public const uint DIBUTTON_FIGHTINGH_SELECT = 0x08004408;

        public const uint DIHATSWITCH_FIGHTINGH_SLIDE = 0x08004601;

        public const uint DIBUTTON_FIGHTINGH_DISPLAY = 0x08004409;

        public const uint DIAXIS_FIGHTINGH_ROTATE = 0x08024203;

        public const uint DIBUTTON_FIGHTINGH_DODGE = 0x0800440A;

        public const uint DIBUTTON_FIGHTINGH_LEFT_LINK = 0x0800C4E4;

        public const uint DIBUTTON_FIGHTINGH_RIGHT_LINK = 0x0800C4EC;

        public const uint DIBUTTON_FIGHTINGH_FORWARD_LINK = 0x080144E0;

        public const uint DIBUTTON_FIGHTINGH_BACKWARD_LINK = 0x080144E8;

        public const uint DIBUTTON_FIGHTINGH_DEVICE = 0x080044FE;

        public const uint DIBUTTON_FIGHTINGH_PAUSE = 0x080044FC;

        public const uint DIVIRTUAL_FIGHTING_FPS = 0x09000000;

        public const uint DIAXIS_FPS_ROTATE = 0x09008201;

        public const uint DIAXIS_FPS_MOVE = 0x09010202;

        public const uint DIBUTTON_FPS_FIRE = 0x09000401;

        public const uint DIBUTTON_FPS_WEAPONS = 0x09000402;

        public const uint DIBUTTON_FPS_APPLY = 0x09000403;

        public const uint DIBUTTON_FPS_SELECT = 0x09000404;

        public const uint DIBUTTON_FPS_CROUCH = 0x09000405;

        public const uint DIBUTTON_FPS_JUMP = 0x09000406;

        public const uint DIAXIS_FPS_LOOKUPDOWN = 0x09018203;

        public const uint DIBUTTON_FPS_STRAFE = 0x09000407;

        public const uint DIBUTTON_FPS_MENU = 0x090004FD;

        public const uint DIHATSWITCH_FPS_GLANCE = 0x09004601;

        public const uint DIBUTTON_FPS_DISPLAY = 0x09004408;

        public const uint DIAXIS_FPS_SIDESTEP = 0x09024204;

        public const uint DIBUTTON_FPS_DODGE = 0x09004409;

        public const uint DIBUTTON_FPS_GLANCEL = 0x0900440A;

        public const uint DIBUTTON_FPS_GLANCER = 0x0900440B;

        public const uint DIBUTTON_FPS_FIRESECONDARY = 0x0900440C;

        public const uint DIBUTTON_FPS_ROTATE_LEFT_LINK = 0x0900C4E4;

        public const uint DIBUTTON_FPS_ROTATE_RIGHT_LINK = 0x0900C4EC;

        public const uint DIBUTTON_FPS_FORWARD_LINK = 0x090144E0;

        public const uint DIBUTTON_FPS_BACKWARD_LINK = 0x090144E8;

        public const uint DIBUTTON_FPS_GLANCE_UP_LINK = 0x0901C4E0;

        public const uint DIBUTTON_FPS_GLANCE_DOWN_LINK = 0x0901C4E8;

        public const uint DIBUTTON_FPS_STEP_LEFT_LINK = 0x090244E4;

        public const uint DIBUTTON_FPS_STEP_RIGHT_LINK = 0x090244EC;

        public const uint DIBUTTON_FPS_DEVICE = 0x090044FE;

        public const uint DIBUTTON_FPS_PAUSE = 0x090044FC;

        public const uint DIVIRTUAL_FIGHTING_THIRDPERSON = 0x0A000000;

        public const uint DIAXIS_TPS_TURN = 0x0A020201;

        public const uint DIAXIS_TPS_MOVE = 0x0A010202;

        public const uint DIBUTTON_TPS_RUN = 0x0A000401;

        public const uint DIBUTTON_TPS_ACTION = 0x0A000402;

        public const uint DIBUTTON_TPS_SELECT = 0x0A000403;

        public const uint DIBUTTON_TPS_USE = 0x0A000404;

        public const uint DIBUTTON_TPS_JUMP = 0x0A000405;

        public const uint DIBUTTON_TPS_MENU = 0x0A0004FD;

        public const uint DIHATSWITCH_TPS_GLANCE = 0x0A004601;

        public const uint DIBUTTON_TPS_VIEW = 0x0A004406;

        public const uint DIBUTTON_TPS_STEPLEFT = 0x0A004407;

        public const uint DIBUTTON_TPS_STEPRIGHT = 0x0A004408;

        public const uint DIAXIS_TPS_STEP = 0x0A00C203;

        public const uint DIBUTTON_TPS_DODGE = 0x0A004409;

        public const uint DIBUTTON_TPS_INVENTORY = 0x0A00440A;

        public const uint DIBUTTON_TPS_TURN_LEFT_LINK = 0x0A0244E4;

        public const uint DIBUTTON_TPS_TURN_RIGHT_LINK = 0x0A0244EC;

        public const uint DIBUTTON_TPS_FORWARD_LINK = 0x0A0144E0;

        public const uint DIBUTTON_TPS_BACKWARD_LINK = 0x0A0144E8;

        public const uint DIBUTTON_TPS_GLANCE_UP_LINK = 0x0A07C4E0;

        public const uint DIBUTTON_TPS_GLANCE_DOWN_LINK = 0x0A07C4E8;

        public const uint DIBUTTON_TPS_GLANCE_LEFT_LINK = 0x0A07C4E4;

        public const uint DIBUTTON_TPS_GLANCE_RIGHT_LINK = 0x0A07C4EC;

        public const uint DIBUTTON_TPS_DEVICE = 0x0A0044FE;

        public const uint DIBUTTON_TPS_PAUSE = 0x0A0044FC;

        public const uint DIVIRTUAL_STRATEGY_ROLEPLAYING = 0x0B000000;

        public const uint DIAXIS_STRATEGYR_LATERAL = 0x0B008201;

        public const uint DIAXIS_STRATEGYR_MOVE = 0x0B010202;

        public const uint DIBUTTON_STRATEGYR_GET = 0x0B000401;

        public const uint DIBUTTON_STRATEGYR_APPLY = 0x0B000402;

        public const uint DIBUTTON_STRATEGYR_SELECT = 0x0B000403;

        public const uint DIBUTTON_STRATEGYR_ATTACK = 0x0B000404;

        public const uint DIBUTTON_STRATEGYR_CAST = 0x0B000405;

        public const uint DIBUTTON_STRATEGYR_CROUCH = 0x0B000406;

        public const uint DIBUTTON_STRATEGYR_JUMP = 0x0B000407;

        public const uint DIBUTTON_STRATEGYR_MENU = 0x0B0004FD;

        public const uint DIHATSWITCH_STRATEGYR_GLANCE = 0x0B004601;

        public const uint DIBUTTON_STRATEGYR_MAP = 0x0B004408;

        public const uint DIBUTTON_STRATEGYR_DISPLAY = 0x0B004409;

        public const uint DIAXIS_STRATEGYR_ROTATE = 0x0B024203;

        public const uint DIBUTTON_STRATEGYR_LEFT_LINK = 0x0B00C4E4;

        public const uint DIBUTTON_STRATEGYR_RIGHT_LINK = 0x0B00C4EC;

        public const uint DIBUTTON_STRATEGYR_FORWARD_LINK = 0x0B0144E0;

        public const uint DIBUTTON_STRATEGYR_BACK_LINK = 0x0B0144E8;

        public const uint DIBUTTON_STRATEGYR_ROTATE_LEFT_LINK = 0x0B0244E4;

        public const uint DIBUTTON_STRATEGYR_ROTATE_RIGHT_LINK = 0x0B0244EC;

        public const uint DIBUTTON_STRATEGYR_DEVICE = 0x0B0044FE;

        public const uint DIBUTTON_STRATEGYR_PAUSE = 0x0B0044FC;

        public const uint DIVIRTUAL_STRATEGY_TURN = 0x0C000000;

        public const uint DIAXIS_STRATEGYT_LATERAL = 0x0C008201;

        public const uint DIAXIS_STRATEGYT_MOVE = 0x0C010202;

        public const uint DIBUTTON_STRATEGYT_SELECT = 0x0C000401;

        public const uint DIBUTTON_STRATEGYT_INSTRUCT = 0x0C000402;

        public const uint DIBUTTON_STRATEGYT_APPLY = 0x0C000403;

        public const uint DIBUTTON_STRATEGYT_TEAM = 0x0C000404;

        public const uint DIBUTTON_STRATEGYT_TURN = 0x0C000405;

        public const uint DIBUTTON_STRATEGYT_MENU = 0x0C0004FD;

        public const uint DIBUTTON_STRATEGYT_ZOOM = 0x0C004406;

        public const uint DIBUTTON_STRATEGYT_MAP = 0x0C004407;

        public const uint DIBUTTON_STRATEGYT_DISPLAY = 0x0C004408;

        public const uint DIBUTTON_STRATEGYT_LEFT_LINK = 0x0C00C4E4;

        public const uint DIBUTTON_STRATEGYT_RIGHT_LINK = 0x0C00C4EC;

        public const uint DIBUTTON_STRATEGYT_FORWARD_LINK = 0x0C0144E0;

        public const uint DIBUTTON_STRATEGYT_BACK_LINK = 0x0C0144E8;

        public const uint DIBUTTON_STRATEGYT_DEVICE = 0x0C0044FE;

        public const uint DIBUTTON_STRATEGYT_PAUSE = 0x0C0044FC;

        public const uint DIVIRTUAL_SPORTS_HUNTING = 0x0D000000;

        public const uint DIAXIS_HUNTING_LATERAL = 0x0D008201;

        public const uint DIAXIS_HUNTING_MOVE = 0x0D010202;

        public const uint DIBUTTON_HUNTING_FIRE = 0x0D000401;

        public const uint DIBUTTON_HUNTING_AIM = 0x0D000402;

        public const uint DIBUTTON_HUNTING_WEAPON = 0x0D000403;

        public const uint DIBUTTON_HUNTING_BINOCULAR = 0x0D000404;

        public const uint DIBUTTON_HUNTING_CALL = 0x0D000405;

        public const uint DIBUTTON_HUNTING_MAP = 0x0D000406;

        public const uint DIBUTTON_HUNTING_SPECIAL = 0x0D000407;

        public const uint DIBUTTON_HUNTING_MENU = 0x0D0004FD;

        public const uint DIHATSWITCH_HUNTING_GLANCE = 0x0D004601;

        public const uint DIBUTTON_HUNTING_DISPLAY = 0x0D004408;

        public const uint DIAXIS_HUNTING_ROTATE = 0x0D024203;

        public const uint DIBUTTON_HUNTING_CROUCH = 0x0D004409;

        public const uint DIBUTTON_HUNTING_JUMP = 0x0D00440A;

        public const uint DIBUTTON_HUNTING_FIRESECONDARY = 0x0D00440B;

        public const uint DIBUTTON_HUNTING_LEFT_LINK = 0x0D00C4E4;

        public const uint DIBUTTON_HUNTING_RIGHT_LINK = 0x0D00C4EC;

        public const uint DIBUTTON_HUNTING_FORWARD_LINK = 0x0D0144E0;

        public const uint DIBUTTON_HUNTING_BACK_LINK = 0x0D0144E8;

        public const uint DIBUTTON_HUNTING_ROTATE_LEFT_LINK = 0x0D0244E4;

        public const uint DIBUTTON_HUNTING_ROTATE_RIGHT_LINK = 0x0D0244EC;

        public const uint DIBUTTON_HUNTING_DEVICE = 0x0D0044FE;

        public const uint DIBUTTON_HUNTING_PAUSE = 0x0D0044FC;

        public const uint DIVIRTUAL_SPORTS_FISHING = 0x0E000000;

        public const uint DIAXIS_FISHING_LATERAL = 0x0E008201;

        public const uint DIAXIS_FISHING_MOVE = 0x0E010202;

        public const uint DIBUTTON_FISHING_CAST = 0x0E000401;

        public const uint DIBUTTON_FISHING_TYPE = 0x0E000402;

        public const uint DIBUTTON_FISHING_BINOCULAR = 0x0E000403;

        public const uint DIBUTTON_FISHING_BAIT = 0x0E000404;

        public const uint DIBUTTON_FISHING_MAP = 0x0E000405;

        public const uint DIBUTTON_FISHING_MENU = 0x0E0004FD;

        public const uint DIHATSWITCH_FISHING_GLANCE = 0x0E004601;

        public const uint DIBUTTON_FISHING_DISPLAY = 0x0E004406;

        public const uint DIAXIS_FISHING_ROTATE = 0x0E024203;

        public const uint DIBUTTON_FISHING_CROUCH = 0x0E004407;

        public const uint DIBUTTON_FISHING_JUMP = 0x0E004408;

        public const uint DIBUTTON_FISHING_LEFT_LINK = 0x0E00C4E4;

        public const uint DIBUTTON_FISHING_RIGHT_LINK = 0x0E00C4EC;

        public const uint DIBUTTON_FISHING_FORWARD_LINK = 0x0E0144E0;

        public const uint DIBUTTON_FISHING_BACK_LINK = 0x0E0144E8;

        public const uint DIBUTTON_FISHING_ROTATE_LEFT_LINK = 0x0E0244E4;

        public const uint DIBUTTON_FISHING_ROTATE_RIGHT_LINK = 0x0E0244EC;

        public const uint DIBUTTON_FISHING_DEVICE = 0x0E0044FE;

        public const uint DIBUTTON_FISHING_PAUSE = 0x0E0044FC;

        public const uint DIVIRTUAL_SPORTS_BASEBALL_BAT = 0x0F000000;

        public const uint DIAXIS_BASEBALLB_LATERAL = 0x0F008201;

        public const uint DIAXIS_BASEBALLB_MOVE = 0x0F010202;

        public const uint DIBUTTON_BASEBALLB_SELECT = 0x0F000401;

        public const uint DIBUTTON_BASEBALLB_NORMAL = 0x0F000402;

        public const uint DIBUTTON_BASEBALLB_POWER = 0x0F000403;

        public const uint DIBUTTON_BASEBALLB_BUNT = 0x0F000404;

        public const uint DIBUTTON_BASEBALLB_STEAL = 0x0F000405;

        public const uint DIBUTTON_BASEBALLB_BURST = 0x0F000406;

        public const uint DIBUTTON_BASEBALLB_SLIDE = 0x0F000407;

        public const uint DIBUTTON_BASEBALLB_CONTACT = 0x0F000408;

        public const uint DIBUTTON_BASEBALLB_MENU = 0x0F0004FD;

        public const uint DIBUTTON_BASEBALLB_NOSTEAL = 0x0F004409;

        public const uint DIBUTTON_BASEBALLB_BOX = 0x0F00440A;

        public const uint DIBUTTON_BASEBALLB_LEFT_LINK = 0x0F00C4E4;

        public const uint DIBUTTON_BASEBALLB_RIGHT_LINK = 0x0F00C4EC;

        public const uint DIBUTTON_BASEBALLB_FORWARD_LINK = 0x0F0144E0;

        public const uint DIBUTTON_BASEBALLB_BACK_LINK = 0x0F0144E8;

        public const uint DIBUTTON_BASEBALLB_DEVICE = 0x0F0044FE;

        public const uint DIBUTTON_BASEBALLB_PAUSE = 0x0F0044FC;

        public const uint DIVIRTUAL_SPORTS_BASEBALL_PITCH = 0x10000000;

        public const uint DIAXIS_BASEBALLP_LATERAL = 0x10008201;

        public const uint DIAXIS_BASEBALLP_MOVE = 0x10010202;

        public const uint DIBUTTON_BASEBALLP_SELECT = 0x10000401;

        public const uint DIBUTTON_BASEBALLP_PITCH = 0x10000402;

        public const uint DIBUTTON_BASEBALLP_BASE = 0x10000403;

        public const uint DIBUTTON_BASEBALLP_THROW = 0x10000404;

        public const uint DIBUTTON_BASEBALLP_FAKE = 0x10000405;

        public const uint DIBUTTON_BASEBALLP_MENU = 0x100004FD;

        public const uint DIBUTTON_BASEBALLP_WALK = 0x10004406;

        public const uint DIBUTTON_BASEBALLP_LOOK = 0x10004407;

        public const uint DIBUTTON_BASEBALLP_LEFT_LINK = 0x1000C4E4;

        public const uint DIBUTTON_BASEBALLP_RIGHT_LINK = 0x1000C4EC;

        public const uint DIBUTTON_BASEBALLP_FORWARD_LINK = 0x100144E0;

        public const uint DIBUTTON_BASEBALLP_BACK_LINK = 0x100144E8;

        public const uint DIBUTTON_BASEBALLP_DEVICE = 0x100044FE;

        public const uint DIBUTTON_BASEBALLP_PAUSE = 0x100044FC;

        public const uint DIVIRTUAL_SPORTS_BASEBALL_FIELD = 0x11000000;

        public const uint DIAXIS_BASEBALLF_LATERAL = 0x11008201;

        public const uint DIAXIS_BASEBALLF_MOVE = 0x11010202;

        public const uint DIBUTTON_BASEBALLF_NEAREST = 0x11000401;

        public const uint DIBUTTON_BASEBALLF_THROW1 = 0x11000402;

        public const uint DIBUTTON_BASEBALLF_THROW2 = 0x11000403;

        public const uint DIBUTTON_BASEBALLF_BURST = 0x11000404;

        public const uint DIBUTTON_BASEBALLF_JUMP = 0x11000405;

        public const uint DIBUTTON_BASEBALLF_DIVE = 0x11000406;

        public const uint DIBUTTON_BASEBALLF_MENU = 0x110004FD;

        public const uint DIBUTTON_BASEBALLF_SHIFTIN = 0x11004407;

        public const uint DIBUTTON_BASEBALLF_SHIFTOUT = 0x11004408;

        public const uint DIBUTTON_BASEBALLF_AIM_LEFT_LINK = 0x1100C4E4;

        public const uint DIBUTTON_BASEBALLF_AIM_RIGHT_LINK = 0x1100C4EC;

        public const uint DIBUTTON_BASEBALLF_FORWARD_LINK = 0x110144E0;

        public const uint DIBUTTON_BASEBALLF_BACK_LINK = 0x110144E8;

        public const uint DIBUTTON_BASEBALLF_DEVICE = 0x110044FE;

        public const uint DIBUTTON_BASEBALLF_PAUSE = 0x110044FC;

        public const uint DIVIRTUAL_SPORTS_BASKETBALL_OFFENSE = 0x12000000;

        public const uint DIAXIS_BBALLO_LATERAL = 0x12008201;

        public const uint DIAXIS_BBALLO_MOVE = 0x12010202;

        public const uint DIBUTTON_BBALLO_SHOOT = 0x12000401;

        public const uint DIBUTTON_BBALLO_DUNK = 0x12000402;

        public const uint DIBUTTON_BBALLO_PASS = 0x12000403;

        public const uint DIBUTTON_BBALLO_FAKE = 0x12000404;

        public const uint DIBUTTON_BBALLO_SPECIAL = 0x12000405;

        public const uint DIBUTTON_BBALLO_PLAYER = 0x12000406;

        public const uint DIBUTTON_BBALLO_BURST = 0x12000407;

        public const uint DIBUTTON_BBALLO_CALL = 0x12000408;

        public const uint DIBUTTON_BBALLO_MENU = 0x120004FD;

        public const uint DIHATSWITCH_BBALLO_GLANCE = 0x12004601;

        public const uint DIBUTTON_BBALLO_SCREEN = 0x12004409;

        public const uint DIBUTTON_BBALLO_PLAY = 0x1200440A;

        public const uint DIBUTTON_BBALLO_JAB = 0x1200440B;

        public const uint DIBUTTON_BBALLO_POST = 0x1200440C;

        public const uint DIBUTTON_BBALLO_TIMEOUT = 0x1200440D;

        public const uint DIBUTTON_BBALLO_SUBSTITUTE = 0x1200440E;

        public const uint DIBUTTON_BBALLO_LEFT_LINK = 0x1200C4E4;

        public const uint DIBUTTON_BBALLO_RIGHT_LINK = 0x1200C4EC;

        public const uint DIBUTTON_BBALLO_FORWARD_LINK = 0x120144E0;

        public const uint DIBUTTON_BBALLO_BACK_LINK = 0x120144E8;

        public const uint DIBUTTON_BBALLO_DEVICE = 0x120044FE;

        public const uint DIBUTTON_BBALLO_PAUSE = 0x120044FC;

        public const uint DIVIRTUAL_SPORTS_BASKETBALL_DEFENSE = 0x13000000;

        public const uint DIAXIS_BBALLD_LATERAL = 0x13008201;

        public const uint DIAXIS_BBALLD_MOVE = 0x13010202;

        public const uint DIBUTTON_BBALLD_JUMP = 0x13000401;

        public const uint DIBUTTON_BBALLD_STEAL = 0x13000402;

        public const uint DIBUTTON_BBALLD_FAKE = 0x13000403;

        public const uint DIBUTTON_BBALLD_SPECIAL = 0x13000404;

        public const uint DIBUTTON_BBALLD_PLAYER = 0x13000405;

        public const uint DIBUTTON_BBALLD_BURST = 0x13000406;

        public const uint DIBUTTON_BBALLD_PLAY = 0x13000407;

        public const uint DIBUTTON_BBALLD_MENU = 0x130004FD;

        public const uint DIHATSWITCH_BBALLD_GLANCE = 0x13004601;

        public const uint DIBUTTON_BBALLD_TIMEOUT = 0x13004408;

        public const uint DIBUTTON_BBALLD_SUBSTITUTE = 0x13004409;

        public const uint DIBUTTON_BBALLD_LEFT_LINK = 0x1300C4E4;

        public const uint DIBUTTON_BBALLD_RIGHT_LINK = 0x1300C4EC;

        public const uint DIBUTTON_BBALLD_FORWARD_LINK = 0x130144E0;

        public const uint DIBUTTON_BBALLD_BACK_LINK = 0x130144E8;

        public const uint DIBUTTON_BBALLD_DEVICE = 0x130044FE;

        public const uint DIBUTTON_BBALLD_PAUSE = 0x130044FC;

        public const uint DIVIRTUAL_SPORTS_FOOTBALL_FIELD = 0x14000000;

        public const uint DIBUTTON_FOOTBALLP_PLAY = 0x14000401;

        public const uint DIBUTTON_FOOTBALLP_SELECT = 0x14000402;

        public const uint DIBUTTON_FOOTBALLP_HELP = 0x14000403;

        public const uint DIBUTTON_FOOTBALLP_MENU = 0x140004FD;

        public const uint DIBUTTON_FOOTBALLP_DEVICE = 0x140044FE;

        public const uint DIBUTTON_FOOTBALLP_PAUSE = 0x140044FC;

        public const uint DIVIRTUAL_SPORTS_FOOTBALL_QBCK = 0x15000000;

        public const uint DIAXIS_FOOTBALLQ_LATERAL = 0x15008201;

        public const uint DIAXIS_FOOTBALLQ_MOVE = 0x15010202;

        public const uint DIBUTTON_FOOTBALLQ_SELECT = 0x15000401;

        public const uint DIBUTTON_FOOTBALLQ_SNAP = 0x15000402;

        public const uint DIBUTTON_FOOTBALLQ_JUMP = 0x15000403;

        public const uint DIBUTTON_FOOTBALLQ_SLIDE = 0x15000404;

        public const uint DIBUTTON_FOOTBALLQ_PASS = 0x15000405;

        public const uint DIBUTTON_FOOTBALLQ_FAKE = 0x15000406;

        public const uint DIBUTTON_FOOTBALLQ_MENU = 0x150004FD;

        public const uint DIBUTTON_FOOTBALLQ_FAKESNAP = 0x15004407;

        public const uint DIBUTTON_FOOTBALLQ_MOTION = 0x15004408;

        public const uint DIBUTTON_FOOTBALLQ_AUDIBLE = 0x15004409;

        public const uint DIBUTTON_FOOTBALLQ_LEFT_LINK = 0x1500C4E4;

        public const uint DIBUTTON_FOOTBALLQ_RIGHT_LINK = 0x1500C4EC;

        public const uint DIBUTTON_FOOTBALLQ_FORWARD_LINK = 0x150144E0;

        public const uint DIBUTTON_FOOTBALLQ_BACK_LINK = 0x150144E8;

        public const uint DIBUTTON_FOOTBALLQ_DEVICE = 0x150044FE;

        public const uint DIBUTTON_FOOTBALLQ_PAUSE = 0x150044FC;

        public const uint DIVIRTUAL_SPORTS_FOOTBALL_OFFENSE = 0x16000000;

        public const uint DIAXIS_FOOTBALLO_LATERAL = 0x16008201;

        public const uint DIAXIS_FOOTBALLO_MOVE = 0x16010202;

        public const uint DIBUTTON_FOOTBALLO_JUMP = 0x16000401;

        public const uint DIBUTTON_FOOTBALLO_LEFTARM = 0x16000402;

        public const uint DIBUTTON_FOOTBALLO_RIGHTARM = 0x16000403;

        public const uint DIBUTTON_FOOTBALLO_THROW = 0x16000404;

        public const uint DIBUTTON_FOOTBALLO_SPIN = 0x16000405;

        public const uint DIBUTTON_FOOTBALLO_MENU = 0x160004FD;

        public const uint DIBUTTON_FOOTBALLO_JUKE = 0x16004406;

        public const uint DIBUTTON_FOOTBALLO_SHOULDER = 0x16004407;

        public const uint DIBUTTON_FOOTBALLO_TURBO = 0x16004408;

        public const uint DIBUTTON_FOOTBALLO_DIVE = 0x16004409;

        public const uint DIBUTTON_FOOTBALLO_ZOOM = 0x1600440A;

        public const uint DIBUTTON_FOOTBALLO_SUBSTITUTE = 0x1600440B;

        public const uint DIBUTTON_FOOTBALLO_LEFT_LINK = 0x1600C4E4;

        public const uint DIBUTTON_FOOTBALLO_RIGHT_LINK = 0x1600C4EC;

        public const uint DIBUTTON_FOOTBALLO_FORWARD_LINK = 0x160144E0;

        public const uint DIBUTTON_FOOTBALLO_BACK_LINK = 0x160144E8;

        public const uint DIBUTTON_FOOTBALLO_DEVICE = 0x160044FE;

        public const uint DIBUTTON_FOOTBALLO_PAUSE = 0x160044FC;

        public const uint DIVIRTUAL_SPORTS_FOOTBALL_DEFENSE = 0x17000000;

        public const uint DIAXIS_FOOTBALLD_LATERAL = 0x17008201;

        public const uint DIAXIS_FOOTBALLD_MOVE = 0x17010202;

        public const uint DIBUTTON_FOOTBALLD_PLAY = 0x17000401;

        public const uint DIBUTTON_FOOTBALLD_SELECT = 0x17000402;

        public const uint DIBUTTON_FOOTBALLD_JUMP = 0x17000403;

        public const uint DIBUTTON_FOOTBALLD_TACKLE = 0x17000404;

        public const uint DIBUTTON_FOOTBALLD_FAKE = 0x17000405;

        public const uint DIBUTTON_FOOTBALLD_SUPERTACKLE = 0x17000406;

        public const uint DIBUTTON_FOOTBALLD_MENU = 0x170004FD;

        public const uint DIBUTTON_FOOTBALLD_SPIN = 0x17004407;

        public const uint DIBUTTON_FOOTBALLD_SWIM = 0x17004408;

        public const uint DIBUTTON_FOOTBALLD_BULLRUSH = 0x17004409;

        public const uint DIBUTTON_FOOTBALLD_RIP = 0x1700440A;

        public const uint DIBUTTON_FOOTBALLD_AUDIBLE = 0x1700440B;

        public const uint DIBUTTON_FOOTBALLD_ZOOM = 0x1700440C;

        public const uint DIBUTTON_FOOTBALLD_SUBSTITUTE = 0x1700440D;

        public const uint DIBUTTON_FOOTBALLD_LEFT_LINK = 0x1700C4E4;

        public const uint DIBUTTON_FOOTBALLD_RIGHT_LINK = 0x1700C4EC;

        public const uint DIBUTTON_FOOTBALLD_FORWARD_LINK = 0x170144E0;

        public const uint DIBUTTON_FOOTBALLD_BACK_LINK = 0x170144E8;

        public const uint DIBUTTON_FOOTBALLD_DEVICE = 0x170044FE;

        public const uint DIBUTTON_FOOTBALLD_PAUSE = 0x170044FC;

        public const uint DIVIRTUAL_SPORTS_GOLF = 0x18000000;

        public const uint DIAXIS_GOLF_LATERAL = 0x18008201;

        public const uint DIAXIS_GOLF_MOVE = 0x18010202;

        public const uint DIBUTTON_GOLF_SWING = 0x18000401;

        public const uint DIBUTTON_GOLF_SELECT = 0x18000402;

        public const uint DIBUTTON_GOLF_UP = 0x18000403;

        public const uint DIBUTTON_GOLF_DOWN = 0x18000404;

        public const uint DIBUTTON_GOLF_TERRAIN = 0x18000405;

        public const uint DIBUTTON_GOLF_FLYBY = 0x18000406;

        public const uint DIBUTTON_GOLF_MENU = 0x180004FD;

        public const uint DIHATSWITCH_GOLF_SCROLL = 0x18004601;

        public const uint DIBUTTON_GOLF_ZOOM = 0x18004407;

        public const uint DIBUTTON_GOLF_TIMEOUT = 0x18004408;

        public const uint DIBUTTON_GOLF_SUBSTITUTE = 0x18004409;

        public const uint DIBUTTON_GOLF_LEFT_LINK = 0x1800C4E4;

        public const uint DIBUTTON_GOLF_RIGHT_LINK = 0x1800C4EC;

        public const uint DIBUTTON_GOLF_FORWARD_LINK = 0x180144E0;

        public const uint DIBUTTON_GOLF_BACK_LINK = 0x180144E8;

        public const uint DIBUTTON_GOLF_DEVICE = 0x180044FE;

        public const uint DIBUTTON_GOLF_PAUSE = 0x180044FC;

        public const uint DIVIRTUAL_SPORTS_HOCKEY_OFFENSE = 0x19000000;

        public const uint DIAXIS_HOCKEYO_LATERAL = 0x19008201;

        public const uint DIAXIS_HOCKEYO_MOVE = 0x19010202;

        public const uint DIBUTTON_HOCKEYO_SHOOT = 0x19000401;

        public const uint DIBUTTON_HOCKEYO_PASS = 0x19000402;

        public const uint DIBUTTON_HOCKEYO_BURST = 0x19000403;

        public const uint DIBUTTON_HOCKEYO_SPECIAL = 0x19000404;

        public const uint DIBUTTON_HOCKEYO_FAKE = 0x19000405;

        public const uint DIBUTTON_HOCKEYO_MENU = 0x190004FD;

        public const uint DIHATSWITCH_HOCKEYO_SCROLL = 0x19004601;

        public const uint DIBUTTON_HOCKEYO_ZOOM = 0x19004406;

        public const uint DIBUTTON_HOCKEYO_STRATEGY = 0x19004407;

        public const uint DIBUTTON_HOCKEYO_TIMEOUT = 0x19004408;

        public const uint DIBUTTON_HOCKEYO_SUBSTITUTE = 0x19004409;

        public const uint DIBUTTON_HOCKEYO_LEFT_LINK = 0x1900C4E4;

        public const uint DIBUTTON_HOCKEYO_RIGHT_LINK = 0x1900C4EC;

        public const uint DIBUTTON_HOCKEYO_FORWARD_LINK = 0x190144E0;

        public const uint DIBUTTON_HOCKEYO_BACK_LINK = 0x190144E8;

        public const uint DIBUTTON_HOCKEYO_DEVICE = 0x190044FE;

        public const uint DIBUTTON_HOCKEYO_PAUSE = 0x190044FC;

        public const uint DIVIRTUAL_SPORTS_HOCKEY_DEFENSE = 0x1A000000;

        public const uint DIAXIS_HOCKEYD_LATERAL = 0x1A008201;

        public const uint DIAXIS_HOCKEYD_MOVE = 0x1A010202;

        public const uint DIBUTTON_HOCKEYD_PLAYER = 0x1A000401;

        public const uint DIBUTTON_HOCKEYD_STEAL = 0x1A000402;

        public const uint DIBUTTON_HOCKEYD_BURST = 0x1A000403;

        public const uint DIBUTTON_HOCKEYD_BLOCK = 0x1A000404;

        public const uint DIBUTTON_HOCKEYD_FAKE = 0x1A000405;

        public const uint DIBUTTON_HOCKEYD_MENU = 0x1A0004FD;

        public const uint DIHATSWITCH_HOCKEYD_SCROLL = 0x1A004601;

        public const uint DIBUTTON_HOCKEYD_ZOOM = 0x1A004406;

        public const uint DIBUTTON_HOCKEYD_STRATEGY = 0x1A004407;

        public const uint DIBUTTON_HOCKEYD_TIMEOUT = 0x1A004408;

        public const uint DIBUTTON_HOCKEYD_SUBSTITUTE = 0x1A004409;

        public const uint DIBUTTON_HOCKEYD_LEFT_LINK = 0x1A00C4E4;

        public const uint DIBUTTON_HOCKEYD_RIGHT_LINK = 0x1A00C4EC;

        public const uint DIBUTTON_HOCKEYD_FORWARD_LINK = 0x1A0144E0;

        public const uint DIBUTTON_HOCKEYD_BACK_LINK = 0x1A0144E8;

        public const uint DIBUTTON_HOCKEYD_DEVICE = 0x1A0044FE;

        public const uint DIBUTTON_HOCKEYD_PAUSE = 0x1A0044FC;

        public const uint DIVIRTUAL_SPORTS_HOCKEY_GOALIE = 0x1B000000;

        public const uint DIAXIS_HOCKEYG_LATERAL = 0x1B008201;

        public const uint DIAXIS_HOCKEYG_MOVE = 0x1B010202;

        public const uint DIBUTTON_HOCKEYG_PASS = 0x1B000401;

        public const uint DIBUTTON_HOCKEYG_POKE = 0x1B000402;

        public const uint DIBUTTON_HOCKEYG_STEAL = 0x1B000403;

        public const uint DIBUTTON_HOCKEYG_BLOCK = 0x1B000404;

        public const uint DIBUTTON_HOCKEYG_MENU = 0x1B0004FD;

        public const uint DIHATSWITCH_HOCKEYG_SCROLL = 0x1B004601;

        public const uint DIBUTTON_HOCKEYG_ZOOM = 0x1B004405;

        public const uint DIBUTTON_HOCKEYG_STRATEGY = 0x1B004406;

        public const uint DIBUTTON_HOCKEYG_TIMEOUT = 0x1B004407;

        public const uint DIBUTTON_HOCKEYG_SUBSTITUTE = 0x1B004408;

        public const uint DIBUTTON_HOCKEYG_LEFT_LINK = 0x1B00C4E4;

        public const uint DIBUTTON_HOCKEYG_RIGHT_LINK = 0x1B00C4EC;

        public const uint DIBUTTON_HOCKEYG_FORWARD_LINK = 0x1B0144E0;

        public const uint DIBUTTON_HOCKEYG_BACK_LINK = 0x1B0144E8;

        public const uint DIBUTTON_HOCKEYG_DEVICE = 0x1B0044FE;

        public const uint DIBUTTON_HOCKEYG_PAUSE = 0x1B0044FC;

        public const uint DIVIRTUAL_SPORTS_BIKING_MOUNTAIN = 0x1C000000;

        public const uint DIAXIS_BIKINGM_TURN = 0x1C008201;

        public const uint DIAXIS_BIKINGM_PEDAL = 0x1C010202;

        public const uint DIBUTTON_BIKINGM_JUMP = 0x1C000401;

        public const uint DIBUTTON_BIKINGM_CAMERA = 0x1C000402;

        public const uint DIBUTTON_BIKINGM_SPECIAL1 = 0x1C000403;

        public const uint DIBUTTON_BIKINGM_SELECT = 0x1C000404;

        public const uint DIBUTTON_BIKINGM_SPECIAL2 = 0x1C000405;

        public const uint DIBUTTON_BIKINGM_MENU = 0x1C0004FD;

        public const uint DIHATSWITCH_BIKINGM_SCROLL = 0x1C004601;

        public const uint DIBUTTON_BIKINGM_ZOOM = 0x1C004406;

        public const uint DIAXIS_BIKINGM_BRAKE = 0x1C044203;

        public const uint DIBUTTON_BIKINGM_LEFT_LINK = 0x1C00C4E4;

        public const uint DIBUTTON_BIKINGM_RIGHT_LINK = 0x1C00C4EC;

        public const uint DIBUTTON_BIKINGM_FASTER_LINK = 0x1C0144E0;

        public const uint DIBUTTON_BIKINGM_SLOWER_LINK = 0x1C0144E8;

        public const uint DIBUTTON_BIKINGM_BRAKE_BUTTON_LINK = 0x1C0444E8;

        public const uint DIBUTTON_BIKINGM_DEVICE = 0x1C0044FE;

        public const uint DIBUTTON_BIKINGM_PAUSE = 0x1C0044FC;

        public const uint DIVIRTUAL_SPORTS_SKIING = 0x1D000000;

        public const uint DIAXIS_SKIING_TURN = 0x1D008201;

        public const uint DIAXIS_SKIING_SPEED = 0x1D010202;

        public const uint DIBUTTON_SKIING_JUMP = 0x1D000401;

        public const uint DIBUTTON_SKIING_CROUCH = 0x1D000402;

        public const uint DIBUTTON_SKIING_CAMERA = 0x1D000403;

        public const uint DIBUTTON_SKIING_SPECIAL1 = 0x1D000404;

        public const uint DIBUTTON_SKIING_SELECT = 0x1D000405;

        public const uint DIBUTTON_SKIING_SPECIAL2 = 0x1D000406;

        public const uint DIBUTTON_SKIING_MENU = 0x1D0004FD;

        public const uint DIHATSWITCH_SKIING_GLANCE = 0x1D004601;

        public const uint DIBUTTON_SKIING_ZOOM = 0x1D004407;

        public const uint DIBUTTON_SKIING_LEFT_LINK = 0x1D00C4E4;

        public const uint DIBUTTON_SKIING_RIGHT_LINK = 0x1D00C4EC;

        public const uint DIBUTTON_SKIING_FASTER_LINK = 0x1D0144E0;

        public const uint DIBUTTON_SKIING_SLOWER_LINK = 0x1D0144E8;

        public const uint DIBUTTON_SKIING_DEVICE = 0x1D0044FE;

        public const uint DIBUTTON_SKIING_PAUSE = 0x1D0044FC;

        public const uint DIVIRTUAL_SPORTS_SOCCER_OFFENSE = 0x1E000000;

        public const uint DIAXIS_SOCCERO_LATERAL = 0x1E008201;

        public const uint DIAXIS_SOCCERO_MOVE = 0x1E010202;

        public const uint DIAXIS_SOCCERO_BEND = 0x1E018203;

        public const uint DIBUTTON_SOCCERO_SHOOT = 0x1E000401;

        public const uint DIBUTTON_SOCCERO_PASS = 0x1E000402;

        public const uint DIBUTTON_SOCCERO_FAKE = 0x1E000403;

        public const uint DIBUTTON_SOCCERO_PLAYER = 0x1E000404;

        public const uint DIBUTTON_SOCCERO_SPECIAL1 = 0x1E000405;

        public const uint DIBUTTON_SOCCERO_SELECT = 0x1E000406;

        public const uint DIBUTTON_SOCCERO_MENU = 0x1E0004FD;

        public const uint DIHATSWITCH_SOCCERO_GLANCE = 0x1E004601;

        public const uint DIBUTTON_SOCCERO_SUBSTITUTE = 0x1E004407;

        public const uint DIBUTTON_SOCCERO_SHOOTLOW = 0x1E004408;

        public const uint DIBUTTON_SOCCERO_SHOOTHIGH = 0x1E004409;

        public const uint DIBUTTON_SOCCERO_PASSTHRU = 0x1E00440A;

        public const uint DIBUTTON_SOCCERO_SPRINT = 0x1E00440B;

        public const uint DIBUTTON_SOCCERO_CONTROL = 0x1E00440C;

        public const uint DIBUTTON_SOCCERO_HEAD = 0x1E00440D;

        public const uint DIBUTTON_SOCCERO_LEFT_LINK = 0x1E00C4E4;

        public const uint DIBUTTON_SOCCERO_RIGHT_LINK = 0x1E00C4EC;

        public const uint DIBUTTON_SOCCERO_FORWARD_LINK = 0x1E0144E0;

        public const uint DIBUTTON_SOCCERO_BACK_LINK = 0x1E0144E8;

        public const uint DIBUTTON_SOCCERO_DEVICE = 0x1E0044FE;

        public const uint DIBUTTON_SOCCERO_PAUSE = 0x1E0044FC;

        public const uint DIVIRTUAL_SPORTS_SOCCER_DEFENSE = 0x1F000000;

        public const uint DIAXIS_SOCCERD_LATERAL = 0x1F008201;

        public const uint DIAXIS_SOCCERD_MOVE = 0x1F010202;

        public const uint DIBUTTON_SOCCERD_BLOCK = 0x1F000401;

        public const uint DIBUTTON_SOCCERD_STEAL = 0x1F000402;

        public const uint DIBUTTON_SOCCERD_FAKE = 0x1F000403;

        public const uint DIBUTTON_SOCCERD_PLAYER = 0x1F000404;

        public const uint DIBUTTON_SOCCERD_SPECIAL = 0x1F000405;

        public const uint DIBUTTON_SOCCERD_SELECT = 0x1F000406;

        public const uint DIBUTTON_SOCCERD_SLIDE = 0x1F000407;

        public const uint DIBUTTON_SOCCERD_MENU = 0x1F0004FD;

        public const uint DIHATSWITCH_SOCCERD_GLANCE = 0x1F004601;

        public const uint DIBUTTON_SOCCERD_FOUL = 0x1F004408;

        public const uint DIBUTTON_SOCCERD_HEAD = 0x1F004409;

        public const uint DIBUTTON_SOCCERD_CLEAR = 0x1F00440A;

        public const uint DIBUTTON_SOCCERD_GOALIECHARGE = 0x1F00440B;

        public const uint DIBUTTON_SOCCERD_SUBSTITUTE = 0x1F00440C;

        public const uint DIBUTTON_SOCCERD_LEFT_LINK = 0x1F00C4E4;

        public const uint DIBUTTON_SOCCERD_RIGHT_LINK = 0x1F00C4EC;

        public const uint DIBUTTON_SOCCERD_FORWARD_LINK = 0x1F0144E0;

        public const uint DIBUTTON_SOCCERD_BACK_LINK = 0x1F0144E8;

        public const uint DIBUTTON_SOCCERD_DEVICE = 0x1F0044FE;

        public const uint DIBUTTON_SOCCERD_PAUSE = 0x1F0044FC;

        public const uint DIVIRTUAL_SPORTS_RACQUET = 0x20000000;

        public const uint DIAXIS_RACQUET_LATERAL = 0x20008201;

        public const uint DIAXIS_RACQUET_MOVE = 0x20010202;

        public const uint DIBUTTON_RACQUET_SWING = 0x20000401;

        public const uint DIBUTTON_RACQUET_BACKSWING = 0x20000402;

        public const uint DIBUTTON_RACQUET_SMASH = 0x20000403;

        public const uint DIBUTTON_RACQUET_SPECIAL = 0x20000404;

        public const uint DIBUTTON_RACQUET_SELECT = 0x20000405;

        public const uint DIBUTTON_RACQUET_MENU = 0x200004FD;

        public const uint DIHATSWITCH_RACQUET_GLANCE = 0x20004601;

        public const uint DIBUTTON_RACQUET_TIMEOUT = 0x20004406;

        public const uint DIBUTTON_RACQUET_SUBSTITUTE = 0x20004407;

        public const uint DIBUTTON_RACQUET_LEFT_LINK = 0x2000C4E4;

        public const uint DIBUTTON_RACQUET_RIGHT_LINK = 0x2000C4EC;

        public const uint DIBUTTON_RACQUET_FORWARD_LINK = 0x200144E0;

        public const uint DIBUTTON_RACQUET_BACK_LINK = 0x200144E8;

        public const uint DIBUTTON_RACQUET_DEVICE = 0x200044FE;

        public const uint DIBUTTON_RACQUET_PAUSE = 0x200044FC;

        public const uint DIVIRTUAL_ARCADE_SIDE2SIDE = 0x21000000;

        public const uint DIAXIS_ARCADES_LATERAL = 0x21008201;

        public const uint DIAXIS_ARCADES_MOVE = 0x21010202;

        public const uint DIBUTTON_ARCADES_THROW = 0x21000401;

        public const uint DIBUTTON_ARCADES_CARRY = 0x21000402;

        public const uint DIBUTTON_ARCADES_ATTACK = 0x21000403;

        public const uint DIBUTTON_ARCADES_SPECIAL = 0x21000404;

        public const uint DIBUTTON_ARCADES_SELECT = 0x21000405;

        public const uint DIBUTTON_ARCADES_MENU = 0x210004FD;

        public const uint DIHATSWITCH_ARCADES_VIEW = 0x21004601;

        public const uint DIBUTTON_ARCADES_LEFT_LINK = 0x2100C4E4;

        public const uint DIBUTTON_ARCADES_RIGHT_LINK = 0x2100C4EC;

        public const uint DIBUTTON_ARCADES_FORWARD_LINK = 0x210144E0;

        public const uint DIBUTTON_ARCADES_BACK_LINK = 0x210144E8;

        public const uint DIBUTTON_ARCADES_VIEW_UP_LINK = 0x2107C4E0;

        public const uint DIBUTTON_ARCADES_VIEW_DOWN_LINK = 0x2107C4E8;

        public const uint DIBUTTON_ARCADES_VIEW_LEFT_LINK = 0x2107C4E4;

        public const uint DIBUTTON_ARCADES_VIEW_RIGHT_LINK = 0x2107C4EC;

        public const uint DIBUTTON_ARCADES_DEVICE = 0x210044FE;

        public const uint DIBUTTON_ARCADES_PAUSE = 0x210044FC;

        public const uint DIVIRTUAL_ARCADE_PLATFORM = 0x22000000;

        public const uint DIAXIS_ARCADEP_LATERAL = 0x22008201;

        public const uint DIAXIS_ARCADEP_MOVE = 0x22010202;

        public const uint DIBUTTON_ARCADEP_JUMP = 0x22000401;

        public const uint DIBUTTON_ARCADEP_FIRE = 0x22000402;

        public const uint DIBUTTON_ARCADEP_CROUCH = 0x22000403;

        public const uint DIBUTTON_ARCADEP_SPECIAL = 0x22000404;

        public const uint DIBUTTON_ARCADEP_SELECT = 0x22000405;

        public const uint DIBUTTON_ARCADEP_MENU = 0x220004FD;

        public const uint DIHATSWITCH_ARCADEP_VIEW = 0x22004601;

        public const uint DIBUTTON_ARCADEP_FIRESECONDARY = 0x22004406;

        public const uint DIBUTTON_ARCADEP_LEFT_LINK = 0x2200C4E4;

        public const uint DIBUTTON_ARCADEP_RIGHT_LINK = 0x2200C4EC;

        public const uint DIBUTTON_ARCADEP_FORWARD_LINK = 0x220144E0;

        public const uint DIBUTTON_ARCADEP_BACK_LINK = 0x220144E8;

        public const uint DIBUTTON_ARCADEP_VIEW_UP_LINK = 0x2207C4E0;

        public const uint DIBUTTON_ARCADEP_VIEW_DOWN_LINK = 0x2207C4E8;

        public const uint DIBUTTON_ARCADEP_VIEW_LEFT_LINK = 0x2207C4E4;

        public const uint DIBUTTON_ARCADEP_VIEW_RIGHT_LINK = 0x2207C4EC;

        public const uint DIBUTTON_ARCADEP_DEVICE = 0x220044FE;

        public const uint DIBUTTON_ARCADEP_PAUSE = 0x220044FC;

        public const uint DIVIRTUAL_CAD_2DCONTROL = 0x23000000;

        public const uint DIAXIS_2DCONTROL_LATERAL = 0x23008201;

        public const uint DIAXIS_2DCONTROL_MOVE = 0x23010202;

        public const uint DIAXIS_2DCONTROL_INOUT = 0x23018203;

        public const uint DIBUTTON_2DCONTROL_SELECT = 0x23000401;

        public const uint DIBUTTON_2DCONTROL_SPECIAL1 = 0x23000402;

        public const uint DIBUTTON_2DCONTROL_SPECIAL = 0x23000403;

        public const uint DIBUTTON_2DCONTROL_SPECIAL2 = 0x23000404;

        public const uint DIBUTTON_2DCONTROL_MENU = 0x230004FD;

        public const uint DIHATSWITCH_2DCONTROL_HATSWITCH = 0x23004601;

        public const uint DIAXIS_2DCONTROL_ROTATEZ = 0x23024204;

        public const uint DIBUTTON_2DCONTROL_DISPLAY = 0x23004405;

        public const uint DIBUTTON_2DCONTROL_DEVICE = 0x230044FE;

        public const uint DIBUTTON_2DCONTROL_PAUSE = 0x230044FC;

        public const uint DIVIRTUAL_CAD_3DCONTROL = 0x24000000;

        public const uint DIAXIS_3DCONTROL_LATERAL = 0x24008201;

        public const uint DIAXIS_3DCONTROL_MOVE = 0x24010202;

        public const uint DIAXIS_3DCONTROL_INOUT = 0x24018203;

        public const uint DIBUTTON_3DCONTROL_SELECT = 0x24000401;

        public const uint DIBUTTON_3DCONTROL_SPECIAL1 = 0x24000402;

        public const uint DIBUTTON_3DCONTROL_SPECIAL = 0x24000403;

        public const uint DIBUTTON_3DCONTROL_SPECIAL2 = 0x24000404;

        public const uint DIBUTTON_3DCONTROL_MENU = 0x240004FD;

        public const uint DIHATSWITCH_3DCONTROL_HATSWITCH = 0x24004601;

        public const uint DIAXIS_3DCONTROL_ROTATEX = 0x24034204;

        public const uint DIAXIS_3DCONTROL_ROTATEY = 0x2402C205;

        public const uint DIAXIS_3DCONTROL_ROTATEZ = 0x24024206;

        public const uint DIBUTTON_3DCONTROL_DISPLAY = 0x24004405;

        public const uint DIBUTTON_3DCONTROL_DEVICE = 0x240044FE;

        public const uint DIBUTTON_3DCONTROL_PAUSE = 0x240044FC;

        public const uint DIVIRTUAL_CAD_FLYBY = 0x25000000;

        public const uint DIAXIS_CADF_LATERAL = 0x25008201;

        public const uint DIAXIS_CADF_MOVE = 0x25010202;

        public const uint DIAXIS_CADF_INOUT = 0x25018203;

        public const uint DIBUTTON_CADF_SELECT = 0x25000401;

        public const uint DIBUTTON_CADF_SPECIAL1 = 0x25000402;

        public const uint DIBUTTON_CADF_SPECIAL = 0x25000403;

        public const uint DIBUTTON_CADF_SPECIAL2 = 0x25000404;

        public const uint DIBUTTON_CADF_MENU = 0x250004FD;

        public const uint DIHATSWITCH_CADF_HATSWITCH = 0x25004601;

        public const uint DIAXIS_CADF_ROTATEX = 0x25034204;

        public const uint DIAXIS_CADF_ROTATEY = 0x2502C205;

        public const uint DIAXIS_CADF_ROTATEZ = 0x25024206;

        public const uint DIBUTTON_CADF_DISPLAY = 0x25004405;

        public const uint DIBUTTON_CADF_DEVICE = 0x250044FE;

        public const uint DIBUTTON_CADF_PAUSE = 0x250044FC;

        public const uint DIVIRTUAL_CAD_MODEL = 0x26000000;

        public const uint DIAXIS_CADM_LATERAL = 0x26008201;

        public const uint DIAXIS_CADM_MOVE = 0x26010202;

        public const uint DIAXIS_CADM_INOUT = 0x26018203;

        public const uint DIBUTTON_CADM_SELECT = 0x26000401;

        public const uint DIBUTTON_CADM_SPECIAL1 = 0x26000402;

        public const uint DIBUTTON_CADM_SPECIAL = 0x26000403;

        public const uint DIBUTTON_CADM_SPECIAL2 = 0x26000404;

        public const uint DIBUTTON_CADM_MENU = 0x260004FD;

        public const uint DIHATSWITCH_CADM_HATSWITCH = 0x26004601;

        public const uint DIAXIS_CADM_ROTATEX = 0x26034204;

        public const uint DIAXIS_CADM_ROTATEY = 0x2602C205;

        public const uint DIAXIS_CADM_ROTATEZ = 0x26024206;

        public const uint DIBUTTON_CADM_DISPLAY = 0x26004405;

        public const uint DIBUTTON_CADM_DEVICE = 0x260044FE;

        public const uint DIBUTTON_CADM_PAUSE = 0x260044FC;

        public const uint DIVIRTUAL_REMOTE_CONTROL = 0x27000000;

        public const uint DIAXIS_REMOTE_SLIDER = 0x27050201;

        public const uint DIBUTTON_REMOTE_MUTE = 0x27000401;

        public const uint DIBUTTON_REMOTE_SELECT = 0x27000402;

        public const uint DIBUTTON_REMOTE_PLAY = 0x27002403;

        public const uint DIBUTTON_REMOTE_CUE = 0x27002404;

        public const uint DIBUTTON_REMOTE_REVIEW = 0x27002405;

        public const uint DIBUTTON_REMOTE_CHANGE = 0x27002406;

        public const uint DIBUTTON_REMOTE_RECORD = 0x27002407;

        public const uint DIBUTTON_REMOTE_MENU = 0x270004FD;

        public const uint DIAXIS_REMOTE_SLIDER2 = 0x27054202;

        public const uint DIBUTTON_REMOTE_TV = 0x27005C08;

        public const uint DIBUTTON_REMOTE_CABLE = 0x27005C09;

        public const uint DIBUTTON_REMOTE_CD = 0x27005C0A;

        public const uint DIBUTTON_REMOTE_VCR = 0x27005C0B;

        public const uint DIBUTTON_REMOTE_TUNER = 0x27005C0C;

        public const uint DIBUTTON_REMOTE_DVD = 0x27005C0D;

        public const uint DIBUTTON_REMOTE_ADJUST = 0x27005C0E;

        public const uint DIBUTTON_REMOTE_DIGIT0 = 0x2700540F;

        public const uint DIBUTTON_REMOTE_DIGIT1 = 0x27005410;

        public const uint DIBUTTON_REMOTE_DIGIT2 = 0x27005411;

        public const uint DIBUTTON_REMOTE_DIGIT3 = 0x27005412;

        public const uint DIBUTTON_REMOTE_DIGIT4 = 0x27005413;

        public const uint DIBUTTON_REMOTE_DIGIT5 = 0x27005414;

        public const uint DIBUTTON_REMOTE_DIGIT6 = 0x27005415;

        public const uint DIBUTTON_REMOTE_DIGIT7 = 0x27005416;

        public const uint DIBUTTON_REMOTE_DIGIT8 = 0x27005417;

        public const uint DIBUTTON_REMOTE_DIGIT9 = 0x27005418;

        public const uint DIBUTTON_REMOTE_DEVICE = 0x270044FE;

        public const uint DIBUTTON_REMOTE_PAUSE = 0x270044FC;

        public const uint DIVIRTUAL_BROWSER_CONTROL = 0x28000000;

        public const uint DIAXIS_BROWSER_LATERAL = 0x28008201;

        public const uint DIAXIS_BROWSER_MOVE = 0x28010202;

        public const uint DIBUTTON_BROWSER_SELECT = 0x28000401;

        public const uint DIAXIS_BROWSER_VIEW = 0x28018203;

        public const uint DIBUTTON_BROWSER_REFRESH = 0x28000402;

        public const uint DIBUTTON_BROWSER_MENU = 0x280004FD;

        public const uint DIBUTTON_BROWSER_SEARCH = 0x28004403;

        public const uint DIBUTTON_BROWSER_STOP = 0x28004404;

        public const uint DIBUTTON_BROWSER_HOME = 0x28004405;

        public const uint DIBUTTON_BROWSER_FAVORITES = 0x28004406;

        public const uint DIBUTTON_BROWSER_NEXT = 0x28004407;

        public const uint DIBUTTON_BROWSER_PREVIOUS = 0x28004408;

        public const uint DIBUTTON_BROWSER_HISTORY = 0x28004409;

        public const uint DIBUTTON_BROWSER_PRINT = 0x2800440A;

        public const uint DIBUTTON_BROWSER_DEVICE = 0x280044FE;

        public const uint DIBUTTON_BROWSER_PAUSE = 0x280044FC;

        public const uint DIVIRTUAL_DRIVING_MECHA = 0x29000000;

        public const uint DIAXIS_MECHA_STEER = 0x29008201;

        public const uint DIAXIS_MECHA_TORSO = 0x29010202;

        public const uint DIAXIS_MECHA_ROTATE = 0x29020203;

        public const uint DIAXIS_MECHA_THROTTLE = 0x29038204;

        public const uint DIBUTTON_MECHA_FIRE = 0x29000401;

        public const uint DIBUTTON_MECHA_WEAPONS = 0x29000402;

        public const uint DIBUTTON_MECHA_TARGET = 0x29000403;

        public const uint DIBUTTON_MECHA_REVERSE = 0x29000404;

        public const uint DIBUTTON_MECHA_ZOOM = 0x29000405;

        public const uint DIBUTTON_MECHA_JUMP = 0x29000406;

        public const uint DIBUTTON_MECHA_MENU = 0x290004FD;

        public const uint DIBUTTON_MECHA_CENTER = 0x29004407;

        public const uint DIHATSWITCH_MECHA_GLANCE = 0x29004601;

        public const uint DIBUTTON_MECHA_VIEW = 0x29004408;

        public const uint DIBUTTON_MECHA_FIRESECONDARY = 0x29004409;

        public const uint DIBUTTON_MECHA_LEFT_LINK = 0x2900C4E4;

        public const uint DIBUTTON_MECHA_RIGHT_LINK = 0x2900C4EC;

        public const uint DIBUTTON_MECHA_FORWARD_LINK = 0x290144E0;

        public const uint DIBUTTON_MECHA_BACK_LINK = 0x290144E8;

        public const uint DIBUTTON_MECHA_ROTATE_LEFT_LINK = 0x290244E4;

        public const uint DIBUTTON_MECHA_ROTATE_RIGHT_LINK = 0x290244EC;

        public const uint DIBUTTON_MECHA_FASTER_LINK = 0x2903C4E0;

        public const uint DIBUTTON_MECHA_SLOWER_LINK = 0x2903C4E8;

        public const uint DIBUTTON_MECHA_DEVICE = 0x290044FE;

        public const uint DIBUTTON_MECHA_PAUSE = 0x290044FC;

        public const uint DIAXIS_ANY_X_1 = 0xFF00C201;

        public const uint DIAXIS_ANY_X_2 = 0xFF00C202;

        public const uint DIAXIS_ANY_Y_1 = 0xFF014201;

        public const uint DIAXIS_ANY_Y_2 = 0xFF014202;

        public const uint DIAXIS_ANY_Z_1 = 0xFF01C201;

        public const uint DIAXIS_ANY_Z_2 = 0xFF01C202;

        public const uint DIAXIS_ANY_R_1 = 0xFF024201;

        public const uint DIAXIS_ANY_R_2 = 0xFF024202;

        public const uint DIAXIS_ANY_U_1 = 0xFF02C201;

        public const uint DIAXIS_ANY_U_2 = 0xFF02C202;

        public const uint DIAXIS_ANY_V_1 = 0xFF034201;

        public const uint DIAXIS_ANY_V_2 = 0xFF034202;

        public const uint DIAXIS_ANY_A_1 = 0xFF03C201;

        public const uint DIAXIS_ANY_A_2 = 0xFF03C202;

        public const uint DIAXIS_ANY_B_1 = 0xFF044201;

        public const uint DIAXIS_ANY_B_2 = 0xFF044202;

        public const uint DIAXIS_ANY_C_1 = 0xFF04C201;

        public const uint DIAXIS_ANY_C_2 = 0xFF04C202;

        public const uint DIAXIS_ANY_S_1 = 0xFF054201;

        public const uint DIAXIS_ANY_S_2 = 0xFF054202;

        public const uint DIAXIS_ANY_1 = 0xFF004201;

        public const uint DIAXIS_ANY_2 = 0xFF004202;

        public const uint DIAXIS_ANY_3 = 0xFF004203;

        public const uint DIAXIS_ANY_4 = 0xFF004204;

        public const uint DIPOV_ANY_1 = 0xFF004601;

        public const uint DIPOV_ANY_2 = 0xFF004602;

        public const uint DIPOV_ANY_3 = 0xFF004603;

        public const uint DIPOV_ANY_4 = 0xFF004604;

        public const int JOY_PASSDRIVERDATA = 0x10000000;

        public const int JOY_HWS_ISHEADTRACKER = 0x02000000;

        public const int JOY_HWS_ISGAMEPORTDRIVER = 0x04000000;

        public const int JOY_HWS_ISANALOGPORTDRIVER = 0x08000000;

        public const int JOY_HWS_AUTOLOAD = 0x10000000;

        public const int JOY_HWS_NODEVNODE = 0x20000000;

        public const int JOY_HWS_ISGAMEPORTBUS = unchecked((int)0x80000000);

        public const int JOY_HWS_GAMEPORTBUSBUSY = 0x00000001;

        public const int JOY_US_VOLATILE = 0x00000008;

        public const uint JOY_OEMPOLL_PASSDRIVERDATA = 7;

    }
}
