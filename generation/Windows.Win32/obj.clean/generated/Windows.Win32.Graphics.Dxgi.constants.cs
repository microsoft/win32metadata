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


namespace Windows.Win32.Graphics.Dxgi
{
    public static partial class Apis
    {
        public const uint _FACDXGI = 0x87a;

        public const uint DXGI_CPU_ACCESS_NONE = 0;

        public const uint DXGI_CPU_ACCESS_DYNAMIC = 1;

        public const uint DXGI_CPU_ACCESS_READ_WRITE = 2;

        public const uint DXGI_CPU_ACCESS_SCRATCH = 3;

        public const uint DXGI_CPU_ACCESS_FIELD = 15;

        public const uint DXGI_FORMAT_DEFINED = 1;

        public const uint DXGI_STANDARD_MULTISAMPLE_QUALITY_PATTERN = 0xffffffff;

        public const uint DXGI_CENTER_MULTISAMPLE_QUALITY_PATTERN = 0xfffffffe;

        public const uint DXGI_USAGE_SHADER_INPUT = 0x00000010;

        public const uint DXGI_USAGE_RENDER_TARGET_OUTPUT = 0x00000020;

        public const uint DXGI_USAGE_BACK_BUFFER = 0x00000040;

        public const uint DXGI_USAGE_SHARED = 0x00000080;

        public const uint DXGI_USAGE_READ_ONLY = 0x00000100;

        public const uint DXGI_USAGE_DISCARD_ON_PRESENT = 0x00000200;

        public const uint DXGI_USAGE_UNORDERED_ACCESS = 0x00000400;

        public const uint DXGI_MAP_READ = 1;

        public const uint DXGI_MAP_WRITE = 2;

        public const uint DXGI_MAP_DISCARD = 4;

        public const uint DXGI_ENUM_MODES_INTERLACED = 1;

        public const uint DXGI_ENUM_MODES_SCALING = 2;

        public const uint DXGI_MAX_SWAP_CHAIN_BUFFERS = 16;

        public const uint DXGI_PRESENT_TEST = 0x00000001;

        public const uint DXGI_PRESENT_DO_NOT_SEQUENCE = 0x00000002;

        public const uint DXGI_PRESENT_RESTART = 0x00000004;

        public const uint DXGI_PRESENT_DO_NOT_WAIT = 0x00000008;

        public const uint DXGI_PRESENT_STEREO_PREFER_RIGHT = 0x00000010;

        public const uint DXGI_PRESENT_STEREO_TEMPORARY_MONO = 0x00000020;

        public const uint DXGI_PRESENT_RESTRICT_TO_OUTPUT = 0x00000040;

        public const uint DXGI_PRESENT_USE_DURATION = 0x00000100;

        public const uint DXGI_PRESENT_ALLOW_TEARING = 0x00000200;

        public const uint DXGI_MWA_NO_WINDOW_CHANGES = 1u<< 0;

        public const uint DXGI_MWA_NO_ALT_ENTER = 1u<< 1;

        public const uint DXGI_MWA_NO_PRINT_SCREEN = 1u<< 2;

        public const uint DXGI_MWA_VALID = 0x7;

        public const uint DXGI_ENUM_MODES_STEREO = 4;

        public const uint DXGI_ENUM_MODES_DISABLED_STEREO = 8;

        public const uint DXGI_SHARED_RESOURCE_READ = 0x80000000;

        public const uint DXGI_SHARED_RESOURCE_WRITE = 1;

        public const uint DXGI_DEBUG_BINARY_VERSION = 1;

        public static readonly Guid DXGI_DEBUG_ALL__scanned__ = new Guid(0xe48ae283, 0xda80, 0x490b, 0x87, 0xe6, 0x43, 0xe9, 0xa9, 0xcf, 0xda, 0x8);

        public static readonly Guid DXGI_DEBUG_DX__scanned__ = new Guid(0x35cdd7fc, 0x13b2, 0x421d, 0xa5, 0xd7, 0x7e, 0x44, 0x51, 0x28, 0x7d, 0x64);

        public static readonly Guid DXGI_DEBUG_DXGI__scanned__ = new Guid(0x25cddaa4, 0xb1c6, 0x47e1, 0xac, 0x3e, 0x98, 0x87, 0x5b, 0x5a, 0x2e, 0x2a);

        public static readonly Guid DXGI_DEBUG_APP__scanned__ = new Guid(0x6cd6e01, 0x4219, 0x4ebd, 0x87, 0x9, 0x27, 0xed, 0x23, 0x36, 0xc, 0x62);

        public const uint DXGI_INFO_QUEUE_MESSAGE_ID_STRING_FROM_APPLICATION = 0;

        public const uint DXGI_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT = 1024;

        public const uint DXGI_CREATE_FACTORY_DEBUG = 0x1;

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_INVALID_CALL = unchecked((int)0x887A0001);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NOT_FOUND = unchecked((int)0x887A0002);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_MORE_DATA = unchecked((int)0x887A0003);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_UNSUPPORTED = unchecked((int)0x887A0004);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_DEVICE_REMOVED = unchecked((int)0x887A0005);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_DEVICE_HUNG = unchecked((int)0x887A0006);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_DEVICE_RESET = unchecked((int)0x887A0007);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_WAS_STILL_DRAWING = unchecked((int)0x887A000A);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_FRAME_STATISTICS_DISJOINT = unchecked((int)0x887A000B);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE = unchecked((int)0x887A000C);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_DRIVER_INTERNAL_ERROR = unchecked((int)0x887A0020);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NONEXCLUSIVE = unchecked((int)0x887A0021);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NOT_CURRENTLY_AVAILABLE = unchecked((int)0x887A0022);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_REMOTE_CLIENT_DISCONNECTED = unchecked((int)0x887A0023);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_REMOTE_OUTOFMEMORY = unchecked((int)0x887A0024);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_ACCESS_LOST = unchecked((int)0x887A0026);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_WAIT_TIMEOUT = unchecked((int)0x887A0027);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_SESSION_DISCONNECTED = unchecked((int)0x887A0028);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_RESTRICT_TO_OUTPUT_STALE = unchecked((int)0x887A0029);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_CANNOT_PROTECT_CONTENT = unchecked((int)0x887A002A);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_ACCESS_DENIED = unchecked((int)0x887A002B);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NAME_ALREADY_EXISTS = unchecked((int)0x887A002C);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_SDK_COMPONENT_MISSING = unchecked((int)0x887A002D);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NOT_CURRENT = unchecked((int)0x887A002E);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_HW_PROTECTION_OUTOFMEMORY = unchecked((int)0x887A0030);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_DYNAMIC_CODE_POLICY_VIOLATION = unchecked((int)0x887A0031);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_NON_COMPOSITED_UI = unchecked((int)0x887A0032);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_MODE_CHANGE_IN_PROGRESS = unchecked((int)0x887A0025);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_CACHE_CORRUPT = unchecked((int)0x887A0033);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_CACHE_FULL = unchecked((int)0x887A0034);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_CACHE_HASH_COLLISION = unchecked((int)0x887A0035);

        [NativeTypeName("HRESULT")]
        public const int DXGI_ERROR_ALREADY_EXISTS = unchecked((int)0x887A0036);

    }
}
