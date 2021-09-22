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


namespace Windows.Win32.Graphics.Direct3D10
{
    public static partial class Apis
    {
        public const uint D3D10_16BIT_INDEX_STRIP_CUT_VALUE = 0xffff;

        public const uint D3D10_32BIT_INDEX_STRIP_CUT_VALUE = 0xffffffff;

        public const uint D3D10_8BIT_INDEX_STRIP_CUT_VALUE = 0xff;

        public const uint D3D10_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT = 9;

        public const uint D3D10_CLIP_OR_CULL_DISTANCE_COUNT = 8;

        public const uint D3D10_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT = 2;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT = 14;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS = 4;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT = 15;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT = 15;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D10_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D10_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT = 64;

        public const uint D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT = 1;

        public const uint D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D10_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D10_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS = 1;

        public const uint D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT = 128;

        public const uint D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST = 1;

        public const uint D3D10_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS = 1;

        public const uint D3D10_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT = 128;

        public const uint D3D10_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS = 1;

        public const uint D3D10_COMMONSHADER_SAMPLER_REGISTER_COUNT = 16;

        public const uint D3D10_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST = 1;

        public const uint D3D10_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS = 1;

        public const uint D3D10_COMMONSHADER_SAMPLER_SLOT_COUNT = 16;

        public const uint D3D10_COMMONSHADER_SUBROUTINE_NESTING_LIMIT = 32;

        public const uint D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENTS = 4;

        public const uint D3D10_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_COMMONSHADER_TEMP_REGISTER_COUNT = 4096;

        public const uint D3D10_COMMONSHADER_TEMP_REGISTER_READS_PER_INST = 3;

        public const uint D3D10_COMMONSHADER_TEMP_REGISTER_READ_PORTS = 3;

        public const uint D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX = 10;

        public const int D3D10_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN = -10;

        public const int D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE = -8;

        public const uint D3D10_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE = 7;

        public const float D3D10_DEFAULT_BLEND_FACTOR_ALPHA = 1.0f;

        public const float D3D10_DEFAULT_BLEND_FACTOR_BLUE = 1.0f;

        public const float D3D10_DEFAULT_BLEND_FACTOR_GREEN = 1.0f;

        public const float D3D10_DEFAULT_BLEND_FACTOR_RED = 1.0f;

        public const float D3D10_DEFAULT_BORDER_COLOR_COMPONENT = 0.0f;

        public const uint D3D10_DEFAULT_DEPTH_BIAS = 0;

        public const float D3D10_DEFAULT_DEPTH_BIAS_CLAMP = 0.0f;

        public const float D3D10_DEFAULT_MAX_ANISOTROPY = 16.0f;

        public const float D3D10_DEFAULT_MIP_LOD_BIAS = 0.0f;

        public const uint D3D10_DEFAULT_RENDER_TARGET_ARRAY_INDEX = 0;

        public const uint D3D10_DEFAULT_SAMPLE_MASK = 0xffffffff;

        public const uint D3D10_DEFAULT_SCISSOR_ENDX = 0;

        public const uint D3D10_DEFAULT_SCISSOR_ENDY = 0;

        public const uint D3D10_DEFAULT_SCISSOR_STARTX = 0;

        public const uint D3D10_DEFAULT_SCISSOR_STARTY = 0;

        public const float D3D10_DEFAULT_SLOPE_SCALED_DEPTH_BIAS = 0.0f;

        public const uint D3D10_DEFAULT_STENCIL_READ_MASK = 0xff;

        public const uint D3D10_DEFAULT_STENCIL_REFERENCE = 0;

        public const uint D3D10_DEFAULT_STENCIL_WRITE_MASK = 0xff;

        public const uint D3D10_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX = 0;

        public const uint D3D10_DEFAULT_VIEWPORT_HEIGHT = 0;

        public const float D3D10_DEFAULT_VIEWPORT_MAX_DEPTH = 0.0f;

        public const float D3D10_DEFAULT_VIEWPORT_MIN_DEPTH = 0.0f;

        public const uint D3D10_DEFAULT_VIEWPORT_TOPLEFTX = 0;

        public const uint D3D10_DEFAULT_VIEWPORT_TOPLEFTY = 0;

        public const uint D3D10_DEFAULT_VIEWPORT_WIDTH = 0;

        public const double D3D10_FLOAT16_FUSED_TOLERANCE_IN_ULP = 0.6;

        public const float D3D10_FLOAT32_MAX = 3.402823466e+38f;

        public const float D3D10_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6f;

        public const float D3D10_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR = 2.4f;

        public const float D3D10_FLOAT_TO_SRGB_EXPONENT_NUMERATOR = 1.0f;

        public const float D3D10_FLOAT_TO_SRGB_OFFSET = 0.055f;

        public const float D3D10_FLOAT_TO_SRGB_SCALE_1 = 12.92f;

        public const float D3D10_FLOAT_TO_SRGB_SCALE_2 = 1.055f;

        public const float D3D10_FLOAT_TO_SRGB_THRESHOLD = 0.0031308f;

        public const float D3D10_FTOI_INSTRUCTION_MAX_INPUT = 2147483647.999f;

        public const float D3D10_FTOI_INSTRUCTION_MIN_INPUT = -2147483648.999f;

        public const float D3D10_FTOU_INSTRUCTION_MAX_INPUT = 4294967295.999f;

        public const float D3D10_FTOU_INSTRUCTION_MIN_INPUT = 0.0f;

        public const uint D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENTS = 1;

        public const uint D3D10_GS_INPUT_PRIM_CONST_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_GS_INPUT_PRIM_CONST_REGISTER_COUNT = 1;

        public const uint D3D10_GS_INPUT_PRIM_CONST_REGISTER_READS_PER_INST = 2;

        public const uint D3D10_GS_INPUT_PRIM_CONST_REGISTER_READ_PORTS = 1;

        public const uint D3D10_GS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_GS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_GS_INPUT_REGISTER_COUNT = 16;

        public const uint D3D10_GS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D10_GS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D10_GS_INPUT_REGISTER_VERTICES = 6;

        public const uint D3D10_GS_OUTPUT_ELEMENTS = 32;

        public const uint D3D10_GS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_GS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_GS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D10_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D10_IA_DEFAULT_PRIMITIVE_TOPOLOGY = 0;

        public const uint D3D10_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D10_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT = 1;

        public const uint D3D10_IA_INSTANCE_ID_BIT_COUNT = 32;

        public const uint D3D10_IA_INTEGER_ARITHMETIC_BIT_COUNT = 32;

        public const uint D3D10_IA_PRIMITIVE_ID_BIT_COUNT = 32;

        public const uint D3D10_IA_VERTEX_ID_BIT_COUNT = 32;

        public const uint D3D10_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = 16;

        public const uint D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 64;

        public const uint D3D10_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = 16;

        public const uint D3D10_INTEGER_DIVIDE_BY_ZERO_QUOTIENT = 0xffffffff;

        public const uint D3D10_INTEGER_DIVIDE_BY_ZERO_REMAINDER = 0xffffffff;

        public const float D3D10_LINEAR_GAMMA = 1.0f;

        public const float D3D10_MAX_BORDER_COLOR_COMPONENT = 1.0f;

        public const float D3D10_MAX_DEPTH = 1.0f;

        public const uint D3D10_MAX_MAXANISOTROPY = 16;

        public const uint D3D10_MAX_MULTISAMPLE_SAMPLE_COUNT = 32;

        public const float D3D10_MAX_POSITION_VALUE = 3.402823466e+34f;

        public const uint D3D10_MAX_TEXTURE_DIMENSION_2_TO_EXP = 17;

        public const float D3D10_MIN_BORDER_COLOR_COMPONENT = 0.0f;

        public const float D3D10_MIN_DEPTH = 0.0f;

        public const uint D3D10_MIN_MAXANISOTROPY = 0;

        public const float D3D10_MIP_LOD_BIAS_MAX = 15.99f;

        public const float D3D10_MIP_LOD_BIAS_MIN = -16.0f;

        public const uint D3D10_MIP_LOD_FRACTIONAL_BIT_COUNT = 6;

        public const uint D3D10_MIP_LOD_RANGE_BIT_COUNT = 8;

        public const float D3D10_MULTISAMPLE_ANTIALIAS_LINE_WIDTH = 1.4f;

        public const uint D3D10_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT = 0;

        public const uint D3D10_PIXEL_ADDRESS_RANGE_BIT_COUNT = 13;

        public const uint D3D10_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT = 15;

        public const uint D3D10_PS_FRONTFACING_DEFAULT_VALUE = 0xffffffff;

        public const uint D3D10_PS_FRONTFACING_FALSE_VALUE = 0;

        public const uint D3D10_PS_FRONTFACING_TRUE_VALUE = 0xffffffff;

        public const uint D3D10_PS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_PS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D10_PS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D10_PS_INPUT_REGISTER_READ_PORTS = 1;

        public const float D3D10_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.0f;

        public const uint D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS = 1;

        public const uint D3D10_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_PS_OUTPUT_DEPTH_REGISTER_COUNT = 1;

        public const uint D3D10_PS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_PS_OUTPUT_REGISTER_COUNT = 8;

        public const float D3D10_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.5f;

        public const uint D3D10_REQ_BLEND_OBJECT_COUNT_PER_CONTEXT = 4096;

        public const uint D3D10_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP = 27;

        public const uint D3D10_REQ_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D10_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_CONTEXT = 4096;

        public const uint D3D10_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 32;

        public const uint D3D10_REQ_DRAW_VERTEX_COUNT_2_TO_EXP = 32;

        public const uint D3D10_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION = 8192;

        public const uint D3D10_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT = 1024;

        public const uint D3D10_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D10_REQ_MAXANISOTROPY = 16;

        public const uint D3D10_REQ_MIP_LEVELS = 14;

        public const uint D3D10_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES = 2048;

        public const uint D3D10_REQ_RASTERIZER_OBJECT_COUNT_PER_CONTEXT = 4096;

        public const uint D3D10_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH = 8192;

        public const uint D3D10_REQ_RESOURCE_SIZE_IN_MEGABYTES = 128;

        public const uint D3D10_REQ_RESOURCE_VIEW_COUNT_PER_CONTEXT_2_TO_EXP = 20;

        public const uint D3D10_REQ_SAMPLER_OBJECT_COUNT_PER_CONTEXT = 4096;

        public const uint D3D10_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION = 512;

        public const uint D3D10_REQ_TEXTURE1D_U_DIMENSION = 8192;

        public const uint D3D10_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION = 512;

        public const uint D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION = 8192;

        public const uint D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION = 2048;

        public const uint D3D10_REQ_TEXTURECUBE_DIMENSION = 8192;

        public const uint D3D10_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL = 0;

        public const uint D3D10_SHADER_MAJOR_VERSION = 4;

        public const uint D3D10_SHADER_MINOR_VERSION = 0;

        public const uint D3D10_SHIFT_INSTRUCTION_PAD_VALUE = 0;

        public const uint D3D10_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT = 5;

        public const uint D3D10_SIMULTANEOUS_RENDER_TARGET_COUNT = 8;

        public const uint D3D10_SO_BUFFER_MAX_STRIDE_IN_BYTES = 2048;

        public const uint D3D10_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES = 256;

        public const uint D3D10_SO_BUFFER_SLOT_COUNT = 4;

        public const uint D3D10_SO_DDI_REGISTER_INDEX_DENOTING_GAP = 0xffffffff;

        public const uint D3D10_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER = 1;

        public const uint D3D10_SO_SINGLE_BUFFER_COMPONENT_LIMIT = 64;

        public const float D3D10_SRGB_GAMMA = 2.2f;

        public const float D3D10_SRGB_TO_FLOAT_DENOMINATOR_1 = 12.92f;

        public const float D3D10_SRGB_TO_FLOAT_DENOMINATOR_2 = 1.055f;

        public const float D3D10_SRGB_TO_FLOAT_EXPONENT = 2.4f;

        public const float D3D10_SRGB_TO_FLOAT_OFFSET = 0.055f;

        public const float D3D10_SRGB_TO_FLOAT_THRESHOLD = 0.04045f;

        public const float D3D10_SRGB_TO_FLOAT_TOLERANCE_IN_ULP = 0.5f;

        public const uint D3D10_STANDARD_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_STANDARD_COMPONENT_BIT_COUNT_DOUBLED = 64;

        public const uint D3D10_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE = 4;

        public const uint D3D10_STANDARD_PIXEL_COMPONENT_COUNT = 128;

        public const uint D3D10_STANDARD_PIXEL_ELEMENT_COUNT = 32;

        public const uint D3D10_STANDARD_VECTOR_SIZE = 4;

        public const uint D3D10_STANDARD_VERTEX_ELEMENT_COUNT = 16;

        public const uint D3D10_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT = 64;

        public const uint D3D10_SUBPIXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D10_SUBTEXEL_FRACTIONAL_BIT_COUNT = 6;

        public const uint D3D10_TEXEL_ADDRESS_RANGE_BIT_COUNT = 18;

        public const uint D3D10_UNBOUND_MEMORY_ACCESS_RESULT = 0;

        public const uint D3D10_VIEWPORT_AND_SCISSORRECT_MAX_INDEX = 15;

        public const uint D3D10_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE = 16;

        public const uint D3D10_VIEWPORT_BOUNDS_MAX = 16383;

        public const int D3D10_VIEWPORT_BOUNDS_MIN = -16384;

        public const uint D3D10_VS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_VS_INPUT_REGISTER_COUNT = 16;

        public const uint D3D10_VS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D10_VS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D10_VS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D10_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_VS_OUTPUT_REGISTER_COUNT = 16;

        public const uint D3D10_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT = 10;

        public const uint D3D10_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 25;

        public const uint D3D10_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP = 25;

        public const uint D3D_MAJOR_VERSION = 10;

        public const uint D3D_MINOR_VERSION = 0;

        public const uint D3D_SPEC_DATE_DAY = 8;

        public const uint D3D_SPEC_DATE_MONTH = 8;

        public const uint D3D_SPEC_DATE_YEAR = 2006;

        public const double D3D_SPEC_VERSION = 1.050005;

        public const uint _FACD3D10 = 0x879;

        public const uint D3D10_APPEND_ALIGNED_ELEMENT = 0xffffffff;

        public const uint D3D10_FILTER_TYPE_MASK = 0x3;

        public const uint D3D10_MIN_FILTER_SHIFT = 4;

        public const uint D3D10_MAG_FILTER_SHIFT = 2;

        public const uint D3D10_MIP_FILTER_SHIFT = 0;

        public const uint D3D10_COMPARISON_FILTERING_BIT = 0x80;

        public const uint D3D10_ANISOTROPIC_FILTERING_BIT = 0x40;

        public const uint D3D10_TEXT_1BIT_BIT = 0x80000000;

        public const uint D3D10_SDK_VERSION = 29;

        public const uint D3D10_1_DEFAULT_SAMPLE_MASK = 0xffffffff;

        public const double D3D10_1_FLOAT16_FUSED_TOLERANCE_IN_ULP = 0.6;

        public const float D3D10_1_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6f;

        public const uint D3D10_1_GS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D10_1_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = 32;

        public const uint D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 128;

        public const uint D3D10_1_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = 32;

        public const uint D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENTS = 1;

        public const uint D3D10_1_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D10_1_PS_OUTPUT_MASK_REGISTER_COUNT = 1;

        public const uint D3D10_1_SHADER_MAJOR_VERSION = 4;

        public const uint D3D10_1_SHADER_MINOR_VERSION = 1;

        public const uint D3D10_1_SO_BUFFER_MAX_STRIDE_IN_BYTES = 2048;

        public const uint D3D10_1_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES = 256;

        public const uint D3D10_1_SO_BUFFER_SLOT_COUNT = 4;

        public const uint D3D10_1_SO_MULTIPLE_BUFFER_ELEMENTS_PER_BUFFER = 1;

        public const uint D3D10_1_SO_SINGLE_BUFFER_COMPONENT_LIMIT = 64;

        public const uint D3D10_1_STANDARD_VERTEX_ELEMENT_COUNT = 32;

        public const uint D3D10_1_SUBPIXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D10_1_VS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D10_1_VS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D10_SDK_LAYERS_VERSION = 11;

        public const uint D3D10_DEBUG_FEATURE_FLUSH_PER_RENDER_OP = 0x1;

        public const uint D3D10_DEBUG_FEATURE_FINISH_PER_RENDER_OP = 0x2;

        public const uint D3D10_DEBUG_FEATURE_PRESENT_PER_RENDER_OP = 0x4;

        public static readonly Guid DXGI_DEBUG_D3D10__scanned__ = new Guid(0x243b4c52, 0x3606, 0x4d3a, 0x99, 0xd7, 0xa7, 0xe7, 0xb3, 0x3e, 0xd7, 0x6);

        public const uint D3D10_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT = 1024;

        public const uint D3D10_SHADER_DEBUG = 1u<< 0;

        public const uint D3D10_SHADER_SKIP_VALIDATION = 1u<< 1;

        public const uint D3D10_SHADER_SKIP_OPTIMIZATION = 1u<< 2;

        public const uint D3D10_SHADER_PACK_MATRIX_ROW_MAJOR = 1u<< 3;

        public const uint D3D10_SHADER_PACK_MATRIX_COLUMN_MAJOR = 1u<< 4;

        public const uint D3D10_SHADER_PARTIAL_PRECISION = 1u<< 5;

        public const uint D3D10_SHADER_FORCE_VS_SOFTWARE_NO_OPT = 1u<< 6;

        public const uint D3D10_SHADER_FORCE_PS_SOFTWARE_NO_OPT = 1u<< 7;

        public const uint D3D10_SHADER_NO_PRESHADER = 1u<< 8;

        public const uint D3D10_SHADER_AVOID_FLOW_CONTROL = 1u<< 9;

        public const uint D3D10_SHADER_PREFER_FLOW_CONTROL = 1u<< 10;

        public const uint D3D10_SHADER_ENABLE_STRICTNESS = 1u<< 11;

        public const uint D3D10_SHADER_ENABLE_BACKWARDS_COMPATIBILITY = 1u<< 12;

        public const uint D3D10_SHADER_IEEE_STRICTNESS = 1u<< 13;

        public const uint D3D10_SHADER_WARNINGS_ARE_ERRORS = 1u<< 18;

        public const uint D3D10_SHADER_RESOURCES_MAY_ALIAS = 1u<< 19;

        public const uint D3D10_ENABLE_UNBOUNDED_DESCRIPTOR_TABLES = 1u<< 20;

        public const uint D3D10_ALL_RESOURCES_BOUND = 1u<< 21;

        public const uint D3D10_SHADER_DEBUG_NAME_FOR_SOURCE = 1u<< 22;

        public const uint D3D10_SHADER_DEBUG_NAME_FOR_BINARY = 1u<< 23;

        public const uint D3D10_SHADER_OPTIMIZATION_LEVEL0 = 1u<< 14;

        public const uint D3D10_SHADER_OPTIMIZATION_LEVEL1 = 0;

        public const uint D3D10_SHADER_OPTIMIZATION_LEVEL3 = 1u<< 15;

        public const uint D3D10_SHADER_FLAGS2_FORCE_ROOT_SIGNATURE_LATEST = 0;

        public const uint D3D10_SHADER_FLAGS2_FORCE_ROOT_SIGNATURE_1_0 = 1u<< 4;

        public const uint D3D10_SHADER_FLAGS2_FORCE_ROOT_SIGNATURE_1_1 = 1u<< 5;

        public static readonly Guid IID_ID3D10StateBlock__scanned__ = new Guid(0x803425a, 0x57f5, 0x4dd6, 0x94, 0x65, 0xa8, 0x75, 0x70, 0x83, 0x4a, 0x8);

        public const uint D3D10_EFFECT_COMPILE_CHILD_EFFECT = 1u<< 0;

        public const uint D3D10_EFFECT_COMPILE_ALLOW_SLOW_OPS = 1u<< 1;

        public const uint D3D10_EFFECT_SINGLE_THREADED = 1u<< 3;

        public const uint D3D10_EFFECT_VARIABLE_POOLED = 1u<< 0;

        public const uint D3D10_EFFECT_VARIABLE_ANNOTATION = 1u<< 1;

        public const uint D3D10_EFFECT_VARIABLE_EXPLICIT_BIND_POINT = 1u<< 2;

        public static readonly Guid IID_ID3D10EffectType__scanned__ = new Guid(0x4e9e1ddc, 0xcd9d, 0x4772, 0xa8, 0x37, 0x0, 0x18, 0xb, 0x9b, 0x88, 0xfd);

        public static readonly Guid IID_ID3D10EffectVariable__scanned__ = new Guid(0xae897105, 0xe6, 0x45bf, 0xbb, 0x8e, 0x28, 0x1d, 0xd6, 0xdb, 0x8e, 0x1b);

        public static readonly Guid IID_ID3D10EffectScalarVariable__scanned__ = new Guid(0xe48f7b, 0xd2c8, 0x49e8, 0xa8, 0x6c, 0x2, 0x2d, 0xee, 0x53, 0x43, 0x1f);

        public static readonly Guid IID_ID3D10EffectVectorVariable__scanned__ = new Guid(0x62b98c44, 0x1f82, 0x4c67, 0xbc, 0xd0, 0x72, 0xcf, 0x8f, 0x21, 0x7e, 0x81);

        public static readonly Guid IID_ID3D10EffectMatrixVariable__scanned__ = new Guid(0x50666c24, 0xb82f, 0x4eed, 0xa1, 0x72, 0x5b, 0x6e, 0x7e, 0x85, 0x22, 0xe0);

        public static readonly Guid IID_ID3D10EffectStringVariable__scanned__ = new Guid(0x71417501, 0x8df9, 0x4e0a, 0xa7, 0x8a, 0x25, 0x5f, 0x97, 0x56, 0xba, 0xff);

        public static readonly Guid IID_ID3D10EffectShaderResourceVariable__scanned__ = new Guid(0xc0a7157b, 0xd872, 0x4b1d, 0x80, 0x73, 0xef, 0xc2, 0xac, 0xd4, 0xb1, 0xfc);

        public static readonly Guid IID_ID3D10EffectRenderTargetViewVariable__scanned__ = new Guid(0x28ca0cc3, 0xc2c9, 0x40bb, 0xb5, 0x7f, 0x67, 0xb7, 0x37, 0x12, 0x2b, 0x17);

        public static readonly Guid IID_ID3D10EffectDepthStencilViewVariable__scanned__ = new Guid(0x3e02c918, 0xcc79, 0x4985, 0xb6, 0x22, 0x2d, 0x92, 0xad, 0x70, 0x16, 0x23);

        public static readonly Guid IID_ID3D10EffectConstantBuffer__scanned__ = new Guid(0x56648f4d, 0xcc8b, 0x4444, 0xa5, 0xad, 0xb5, 0xa3, 0xd7, 0x6e, 0x91, 0xb3);

        public static readonly Guid IID_ID3D10EffectShaderVariable__scanned__ = new Guid(0x80849279, 0xc799, 0x4797, 0x8c, 0x33, 0x4, 0x7, 0xa0, 0x7d, 0x9e, 0x6);

        public static readonly Guid IID_ID3D10EffectBlendVariable__scanned__ = new Guid(0x1fcd2294, 0xdf6d, 0x4eae, 0x86, 0xb3, 0xe, 0x91, 0x60, 0xcf, 0xb0, 0x7b);

        public static readonly Guid IID_ID3D10EffectDepthStencilVariable__scanned__ = new Guid(0xaf482368, 0x330a, 0x46a5, 0x9a, 0x5c, 0x1, 0xc7, 0x1a, 0xf2, 0x4c, 0x8d);

        public static readonly Guid IID_ID3D10EffectRasterizerVariable__scanned__ = new Guid(0x21af9f0e, 0x4d94, 0x4ea9, 0x97, 0x85, 0x2c, 0xb7, 0x6b, 0x8c, 0xb, 0x34);

        public static readonly Guid IID_ID3D10EffectSamplerVariable__scanned__ = new Guid(0x6530d5c7, 0x7e9, 0x4271, 0xa4, 0x18, 0xe7, 0xce, 0x4b, 0xd1, 0xe4, 0x80);

        public static readonly Guid IID_ID3D10EffectPass__scanned__ = new Guid(0x5cfbeb89, 0x1a06, 0x46e0, 0xb2, 0x82, 0xe3, 0xf9, 0xbf, 0xa3, 0x6a, 0x54);

        public static readonly Guid IID_ID3D10EffectTechnique__scanned__ = new Guid(0xdb122ce8, 0xd1c9, 0x4292, 0xb2, 0x37, 0x24, 0xed, 0x3d, 0xe8, 0xb1, 0x75);

        public static readonly Guid IID_ID3D10Effect__scanned__ = new Guid(0x51b0ca8b, 0xec0b, 0x4519, 0x87, 0xd, 0x8e, 0xe1, 0xcb, 0x50, 0x17, 0xc7);

        public static readonly Guid IID_ID3D10EffectPool__scanned__ = new Guid(0x9537ab04, 0x3250, 0x412e, 0x82, 0x13, 0xfc, 0xd2, 0xf8, 0x67, 0x79, 0x33);

        public static readonly Guid GUID_DeviceType__scanned__ = new Guid(0xd722fb4d, 0x7a68, 0x437a, 0xb2, 0x0c, 0x58, 0x04, 0xee, 0x24, 0x94, 0xa6);

        public static readonly Guid IID_ID3D10ShaderReflection1__scanned__ = new Guid(0xc3457783, 0xa846, 0x47ce, 0x95, 0x20, 0xce, 0xa6, 0xf6, 0x6e, 0x74, 0x47);

    }
}
