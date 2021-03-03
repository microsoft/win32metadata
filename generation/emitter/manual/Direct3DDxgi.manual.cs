using System;

namespace Windows.Win32.Dxgi
{
    public static unsafe partial class Apis
    {
        public const uint DXGI_USAGE_SHADER_INPUT = 0x00000010;

        public const uint DXGI_USAGE_RENDER_TARGET_OUTPUT = 0x00000020;

        public const uint DXGI_USAGE_BACK_BUFFER = 0x00000040;

        public const uint DXGI_USAGE_SHARED = 0x00000080;

        public const uint DXGI_USAGE_READ_ONLY = 0x00000100;

        public const uint DXGI_USAGE_DISCARD_ON_PRESENT = 0x00000200;

        public const uint DXGI_USAGE_UNORDERED_ACCESS = 0x00000400;

        public const uint DXGI_RESOURCE_PRIORITY_MINIMUM = 0x28000000;

        public const uint DXGI_RESOURCE_PRIORITY_LOW = 0x50000000;

        public const uint DXGI_RESOURCE_PRIORITY_NORMAL = 0x78000000;

        public const uint DXGI_RESOURCE_PRIORITY_HIGH = 0xA0000000;

        public const uint DXGI_RESOURCE_PRIORITY_MAXIMUM = 0xC8000000;

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

        public const uint DXGI_MWA_NO_WINDOW_CHANGES = 1 << 0;

        public const uint DXGI_MWA_NO_ALT_ENTER = 1 << 1;

        public const uint DXGI_MWA_NO_PRINT_SCREEN = 1 << 2;

        public const uint DXGI_MWA_VALID = 0x7;
    }
}
