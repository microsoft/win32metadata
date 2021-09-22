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


namespace Windows.Win32.Devices.Display
{
    public static partial class Apis
    {
        public static readonly Guid GUID_DEVINTERFACE_DISPLAY_ADAPTER__scanned__ = new Guid(0x5b45201d, 0xf2f2, 0x4f3b, 0x85, 0xbb, 0x30, 0xff, 0x1f, 0x95, 0x35, 0x99);

        public static readonly Guid GUID_DEVINTERFACE_MONITOR__scanned__ = new Guid(0xe6f07b5f, 0xee97, 0x4a90, 0xb0, 0x76, 0x33, 0xf5, 0x7b, 0xf4, 0xea, 0xa7);

        public static readonly Guid GUID_DISPLAY_DEVICE_ARRIVAL__scanned__ = new Guid(0x1CA05180, 0xA699, 0x450A, 0x9A, 0x0C, 0xDE, 0x4F, 0xBE, 0x3D, 0xDD, 0x89);

        public static readonly Guid GUID_DEVINTERFACE_VIDEO_OUTPUT_ARRIVAL__scanned__ = new Guid(0x1AD9E4F0, 0xF88D, 0x4360, 0xBA, 0xB9, 0x4C, 0x2D, 0x55, 0xE5, 0x64, 0xCD);

        [PropertyKey(0xc50a3f10, 0xaa5c, 0x4247, 0xb8, 0x30, 0xd6, 0xa6, 0xf8, 0xea, 0xa3, 0x10, 0x01)]
        public static readonly PROPERTYKEY DEVPKEY_IndirectDisplay;

        [PropertyKey(0xc50a3f10, 0xaa5c, 0x4247, 0xb8, 0x30, 0xd6, 0xa6, 0xf8, 0xea, 0xa3, 0x10, 0x02)]
        public static readonly PROPERTYKEY DEVPKEY_Device_TerminalLuid;

        [PropertyKey(0xc50a3f10, 0xaa5c, 0x4247, 0xb8, 0x30, 0xd6, 0xa6, 0xf8, 0xea, 0xa3, 0x10, 0x03)]
        public static readonly PROPERTYKEY DEVPKEY_Device_AdapterLuid;

        [PropertyKey(0xc50a3f10, 0xaa5c, 0x4247, 0xb8, 0x30, 0xd6, 0xa6, 0xf8, 0xea, 0xa3, 0x10, 0x04)]
        public static readonly PROPERTYKEY DEVPKEY_Device_ActivityId;

        public const uint INDIRECT_DISPLAY_INFO_FLAGS_CREATED_IDDCX_ADAPTER = 0x1;

        public const uint IOCTL_VIDEO_DISABLE_VDM = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x01) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_REGISTER_VDM = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x02) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_OUTPUT_DEVICE_POWER_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x03) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_GET_OUTPUT_DEVICE_POWER_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x04) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_MONITOR_DEVICE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x05) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_ENUM_MONITOR_PDO = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x06) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_INIT_WIN32K_CALLBACKS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x07) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_IS_VGA_DEVICE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x09) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_USE_DEVICE_IN_SESSION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0a) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_PREPARE_FOR_EARECOVERY = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x0b) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_ENABLE_VDM = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x00) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SAVE_HARDWARE_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x80) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_RESTORE_HARDWARE_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x81) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_HANDLE_VIDEOPARAMETERS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x08) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_AVAIL_MODES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x100) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_NUM_AVAIL_MODES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x101) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_CURRENT_MODE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x102) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_CURRENT_MODE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x103) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_RESET_DEVICE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x104) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_LOAD_AND_SET_FONT = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x105) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_PALETTE_REGISTERS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x106) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_COLOR_REGISTERS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x107) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_ENABLE_CURSOR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x108) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_DISABLE_CURSOR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x109) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_CURSOR_ATTR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10a) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_CURSOR_ATTR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10b) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_CURSOR_POSITION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10c) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_CURSOR_POSITION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10d) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_ENABLE_POINTER = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10e) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_DISABLE_POINTER = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x10f) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_POINTER_ATTR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x110) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_POINTER_ATTR = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x111) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_POINTER_POSITION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x112) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_POINTER_POSITION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x113) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_POINTER_CAPABILITIES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x114) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_GET_BANK_SELECT_CODE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x115) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_MAP_VIDEO_MEMORY = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x116) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_UNMAP_VIDEO_MEMORY = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x117) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_PUBLIC_ACCESS_RANGES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x118) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_FREE_PUBLIC_ACCESS_RANGES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x119) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_COLOR_CAPABILITIES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11a) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_POWER_MANAGEMENT = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11b) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_GET_POWER_MANAGEMENT = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11c) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SHARE_VIDEO_MEMORY = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11d) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_UNSHARE_VIDEO_MEMORY = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11e) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_COLOR_LUT_DATA = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x11f) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_GET_CHILD_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x120) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_VALIDATE_CHILD_STATE_CONFIGURATION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x121) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_CHILD_STATE_CONFIGURATION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x122) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SWITCH_DUALVIEW = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x123) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_BANK_POSITION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x124) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_SUPPORTED_BRIGHTNESS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x125) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_QUERY_DISPLAY_BRIGHTNESS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x126) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_VIDEO_SET_DISPLAY_BRIGHTNESS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x127) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_COPY_FRAME_BUFFER = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x200) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_WRITE_TO_FRAME_BUFFER = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x201) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_REVERSE_MOUSE_POINTER = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x202) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_SET_CURRENT_MODE = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x203) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_SET_SCREEN_INFORMATION = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x204) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_FSVIDEO_SET_CURSOR_POSITION = ((FILE_DEVICE_FULLSCREEN_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x205) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_QUERY_BRIGHTNESS_CAPS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x300) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_QUERY_BRIGHTNESS_RANGES = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x301) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_GET_BRIGHTNESS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x302) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_SET_BRIGHTNESS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x303) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_SET_BRIGHTNESS_STATE = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x304) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_SET_BACKLIGHT_OPTIMIZATION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x305) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_PANEL_GET_BACKLIGHT_REDUCTION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x306) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_COLORSPACE_TRANSFORM_QUERY_TARGET_CAPS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x400) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_COLORSPACE_TRANSFORM_SET = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x401) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_SET_ACTIVE_COLOR_PROFILE_NAME = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x402) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MIPI_DSI_QUERY_CAPS = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x500) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MIPI_DSI_TRANSMISSION = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x501) << 2) | (METHOD_BUFFERED);

        public const uint IOCTL_MIPI_DSI_RESET = ((FILE_DEVICE_VIDEO) << 16) | (uint)(((int)(FILE_ANY_ACCESS)) << 14) | ((0x502) << 2) | (METHOD_BUFFERED);

        public const uint DXGK_WIN32K_PARAM_FLAG_UPDATEREGISTRY = 1;

        public const uint DXGK_WIN32K_PARAM_FLAG_MODESWITCH = 2;

        public const uint DXGK_WIN32K_PARAM_FLAG_DISABLEVIEW = 4;

        public const uint VIDEO_DUALVIEW_REMOVABLE = 0x00000001;

        public const uint VIDEO_DUALVIEW_PRIMARY = 0x80000000;

        public const uint VIDEO_DUALVIEW_SECONDARY = 0x40000000;

        public const uint VIDEO_DUALVIEW_WDDM_VGA = 0x20000000;

        public const uint VIDEO_STATE_NON_STANDARD_VGA = 0x00000001;

        public const uint VIDEO_STATE_UNEMULATED_VGA_STATE = 0x00000002;

        public const uint VIDEO_STATE_PACKED_CHAIN4_MODE = 0x00000004;

        public const uint VIDEO_MODE_NO_ZERO_MEMORY = 0x80000000;

        public const uint VIDEO_MODE_MAP_MEM_LINEAR = 0x40000000;

        public const uint VIDEO_MODE_COLOR = 0x0001;

        public const uint VIDEO_MODE_GRAPHICS = 0x0002;

        public const uint VIDEO_MODE_PALETTE_DRIVEN = 0x0004;

        public const uint VIDEO_MODE_MANAGED_PALETTE = 0x0008;

        public const uint VIDEO_MODE_INTERLACED = 0x0010;

        public const uint VIDEO_MODE_NO_OFF_SCREEN = 0x0020;

        public const uint VIDEO_MODE_NO_64_BIT_ACCESS = 0x0040;

        public const uint VIDEO_MODE_BANKED = 0x0080;

        public const uint VIDEO_MODE_LINEAR = 0x0100;

        public const uint VIDEO_MODE_ASYNC_POINTER = 0x01;

        public const uint VIDEO_MODE_MONO_POINTER = 0x02;

        public const uint VIDEO_MODE_COLOR_POINTER = 0x04;

        public const uint VIDEO_MODE_ANIMATE_START = 0x08;

        public const uint VIDEO_MODE_ANIMATE_UPDATE = 0x10;

        public const uint PLANAR_HC = 0x00000001;

        public const uint VIDEO_DEVICE_COLOR = 0x1;

        public const uint VIDEO_OPTIONAL_GAMMET_TABLE = 0x2;

        public const uint VIDEO_COLOR_LUT_DATA_FORMAT_RGB256WORDS = 0x00000001;

        public const uint VIDEO_COLOR_LUT_DATA_FORMAT_PRIVATEFORMAT = 0x80000000;

        public const uint DISPLAYPOLICY_AC = 0x00000001;

        public const uint DISPLAYPOLICY_DC = 0x00000002;

        public const uint CHAR_TYPE_SBCS = 0;

        public const uint CHAR_TYPE_LEADING = 2;

        public const uint CHAR_TYPE_TRAILING = 3;

        public const uint BITMAP_BITS_BYTE_ALIGN = 8;

        public const uint BITMAP_BITS_WORD_ALIGN = 16;

        public const uint BITMAP_ARRAY_BYTE = 3;

        public const uint BITMAP_PLANES = 1;

        public const uint BITMAP_BITS_PIXEL = 1;

        public const uint VIDEO_REASON_NONE = 0;

        public const uint VIDEO_REASON_POLICY1 = 1;

        public const uint VIDEO_REASON_POLICY2 = 2;

        public const uint VIDEO_REASON_POLICY3 = 3;

        public const uint VIDEO_REASON_POLICY4 = 4;

        public const uint VIDEO_REASON_LOCK = 5;

        public const uint VIDEO_REASON_FAILED_ROTATION = 5;

        public const uint VIDEO_REASON_ALLOCATION = 6;

        public const uint VIDEO_REASON_SCRATCH = 8;

        public const uint VIDEO_REASON_CONFIGURATION = 9;

        public const uint BRIGHTNESS_MAX_LEVEL_COUNT = 103;

        public const uint BRIGHTNESS_MAX_NIT_RANGE_COUNT = 16;

        public const uint DSI_PACKET_EMBEDDED_PAYLOAD_SIZE = 8;

        public const uint MAX_PACKET_COUNT = 0x80;

        public const uint DSI_INVALID_PACKET_INDEX = 0xFF;

        public const uint DSI_SOT_ERROR = 0x0001;

        public const uint DSI_SOT_SYNC_ERROR = 0x0002;

        public const uint DSI_EOT_SYNC_ERROR = 0x0004;

        public const uint DSI_ESCAPE_MODE_ENTRY_COMMAND_ERROR = 0x0008;

        public const uint DSI_LOW_POWER_TRANSMIT_SYNC_ERROR = 0x0010;

        public const uint DSI_PERIPHERAL_TIMEOUT_ERROR = 0x0020;

        public const uint DSI_FALSE_CONTROL_ERROR = 0x0040;

        public const uint DSI_CONTENTION_DETECTED = 0x0080;

        public const uint DSI_CHECKSUM_ERROR_CORRECTED = 0x0100;

        public const uint DSI_CHECKSUM_ERROR_NOT_CORRECTED = 0x0200;

        public const uint DSI_LONG_PACKET_PAYLOAD_CHECKSUM_ERROR = 0x0400;

        public const uint DSI_DSI_DATA_TYPE_NOT_RECOGNIZED = 0x0800;

        public const uint DSI_DSI_VC_ID_INVALID = 0x1000;

        public const uint DSI_INVALID_TRANSMISSION_LENGTH = 0x2000;

        public const uint DSI_DSI_PROTOCOL_VIOLATION = 0x8000;

        public const uint HOST_DSI_DEVICE_NOT_READY = 0x0001;

        public const uint HOST_DSI_INTERFACE_RESET = 0x0002;

        public const uint HOST_DSI_DEVICE_RESET = 0x0004;

        public const uint HOST_DSI_TRANSMISSION_CANCELLED = 0x0010;

        public const uint HOST_DSI_TRANSMISSION_DROPPED = 0x0020;

        public const uint HOST_DSI_TRANSMISSION_TIMEOUT = 0x0040;

        public const uint HOST_DSI_INVALID_TRANSMISSION = 0x0100;

        public const uint HOST_DSI_OS_REJECTED_PACKET = 0x0200;

        public const uint HOST_DSI_DRIVER_REJECTED_PACKET = 0x0400;

        public const uint HOST_DSI_BAD_TRANSMISSION_MODE = 0x1000;

        public static readonly Guid GUID_MONITOR_OVERRIDE_PSEUDO_SPECIALIZED__scanned__ = new Guid(0xf196c02f, 0xf86f, 0x4f9a, 0xaa, 0x15, 0xe9, 0xce, 0xbd, 0xfe, 0x3b, 0x96);

        public const int SURFACEALIGN_DISCARDABLE = 0x00000001;

        public const int VMEMHEAP_LINEAR = 0x00000001;

        public const int VMEMHEAP_RECTANGULAR = 0x00000002;

        public const int VMEMHEAP_ALIGNMENT = 0x00000004;

        public const uint MC_CAPS_NONE = 0x00000000;

        public const uint MC_CAPS_MONITOR_TECHNOLOGY_TYPE = 0x00000001;

        public const uint MC_CAPS_BRIGHTNESS = 0x00000002;

        public const uint MC_CAPS_CONTRAST = 0x00000004;

        public const uint MC_CAPS_COLOR_TEMPERATURE = 0x00000008;

        public const uint MC_CAPS_RED_GREEN_BLUE_GAIN = 0x00000010;

        public const uint MC_CAPS_RED_GREEN_BLUE_DRIVE = 0x00000020;

        public const uint MC_CAPS_DEGAUSS = 0x00000040;

        public const uint MC_CAPS_DISPLAY_AREA_POSITION = 0x00000080;

        public const uint MC_CAPS_DISPLAY_AREA_SIZE = 0x00000100;

        public const uint MC_CAPS_RESTORE_FACTORY_DEFAULTS = 0x00000400;

        public const uint MC_CAPS_RESTORE_FACTORY_COLOR_DEFAULTS = 0x00000800;

        public const uint MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS = 0x00001000;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_NONE = 0x00000000;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_4000K = 0x00000001;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_5000K = 0x00000002;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_6500K = 0x00000004;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_7500K = 0x00000008;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_8200K = 0x00000010;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_9300K = 0x00000020;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_10000K = 0x00000040;

        public const uint MC_SUPPORTED_COLOR_TEMPERATURE_11500K = 0x00000080;

        public const uint PHYSICAL_MONITOR_DESCRIPTION_SIZE = 128;

    }
}
