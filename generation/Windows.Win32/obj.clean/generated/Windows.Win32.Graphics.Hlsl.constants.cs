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


namespace Windows.Win32.Graphics.Hlsl
{
    public static partial class Apis
    {
        public const uint D3D_COMPILER_VERSION = 47;

        public const uint D3DCOMPILE_DEBUG = 1u<< 0;

        public const uint D3DCOMPILE_SKIP_VALIDATION = 1u<< 1;

        public const uint D3DCOMPILE_SKIP_OPTIMIZATION = 1u<< 2;

        public const uint D3DCOMPILE_PACK_MATRIX_ROW_MAJOR = 1u<< 3;

        public const uint D3DCOMPILE_PACK_MATRIX_COLUMN_MAJOR = 1u<< 4;

        public const uint D3DCOMPILE_PARTIAL_PRECISION = 1u<< 5;

        public const uint D3DCOMPILE_FORCE_VS_SOFTWARE_NO_OPT = 1u<< 6;

        public const uint D3DCOMPILE_FORCE_PS_SOFTWARE_NO_OPT = 1u<< 7;

        public const uint D3DCOMPILE_NO_PRESHADER = 1u<< 8;

        public const uint D3DCOMPILE_AVOID_FLOW_CONTROL = 1u<< 9;

        public const uint D3DCOMPILE_PREFER_FLOW_CONTROL = 1u<< 10;

        public const uint D3DCOMPILE_ENABLE_STRICTNESS = 1u<< 11;

        public const uint D3DCOMPILE_ENABLE_BACKWARDS_COMPATIBILITY = 1u<< 12;

        public const uint D3DCOMPILE_IEEE_STRICTNESS = 1u<< 13;

        public const uint D3DCOMPILE_OPTIMIZATION_LEVEL0 = 1u<< 14;

        public const uint D3DCOMPILE_OPTIMIZATION_LEVEL1 = 0;

        public const uint D3DCOMPILE_OPTIMIZATION_LEVEL3 = 1u<< 15;

        public const uint D3DCOMPILE_RESERVED16 = 1u<< 16;

        public const uint D3DCOMPILE_RESERVED17 = 1u<< 17;

        public const uint D3DCOMPILE_WARNINGS_ARE_ERRORS = 1u<< 18;

        public const uint D3DCOMPILE_RESOURCES_MAY_ALIAS = 1u<< 19;

        public const uint D3DCOMPILE_ENABLE_UNBOUNDED_DESCRIPTOR_TABLES = 1u<< 20;

        public const uint D3DCOMPILE_ALL_RESOURCES_BOUND = 1u<< 21;

        public const uint D3DCOMPILE_DEBUG_NAME_FOR_SOURCE = 1u<< 22;

        public const uint D3DCOMPILE_DEBUG_NAME_FOR_BINARY = 1u<< 23;

        public const uint D3DCOMPILE_EFFECT_CHILD_EFFECT = 1u<< 0;

        public const uint D3DCOMPILE_EFFECT_ALLOW_SLOW_OPS = 1u<< 1;

        public const uint D3DCOMPILE_FLAGS2_FORCE_ROOT_SIGNATURE_LATEST = 0;

        public const uint D3DCOMPILE_FLAGS2_FORCE_ROOT_SIGNATURE_1_0 = 1u<< 4;

        public const uint D3DCOMPILE_FLAGS2_FORCE_ROOT_SIGNATURE_1_1 = 1u<< 5;

        public const uint D3DCOMPILE_SECDATA_MERGE_UAV_SLOTS = 0x00000001;

        public const uint D3DCOMPILE_SECDATA_PRESERVE_TEMPLATE_SLOTS = 0x00000002;

        public const uint D3DCOMPILE_SECDATA_REQUIRE_TEMPLATE_MATCH = 0x00000004;

        public const uint D3D_DISASM_ENABLE_COLOR_CODE = 0x00000001;

        public const uint D3D_DISASM_ENABLE_DEFAULT_VALUE_PRINTS = 0x00000002;

        public const uint D3D_DISASM_ENABLE_INSTRUCTION_NUMBERING = 0x00000004;

        public const uint D3D_DISASM_ENABLE_INSTRUCTION_CYCLE = 0x00000008;

        public const uint D3D_DISASM_DISABLE_DEBUG_INFO = 0x00000010;

        public const uint D3D_DISASM_ENABLE_INSTRUCTION_OFFSET = 0x00000020;

        public const uint D3D_DISASM_INSTRUCTION_ONLY = 0x00000040;

        public const uint D3D_DISASM_PRINT_HEX_LITERALS = 0x00000080;

        public const uint D3D_GET_INST_OFFSETS_INCLUDE_NON_EXECUTABLE = 0x00000001;

        public const uint D3D_COMPRESS_SHADER_KEEP_ALL_PARTS = 0x00000001;

    }
}
