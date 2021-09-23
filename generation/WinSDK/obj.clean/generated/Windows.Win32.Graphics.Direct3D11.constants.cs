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


namespace Windows.Win32.Graphics.Direct3D11
{
    public static partial class Apis
    {
        public const uint D3D11_16BIT_INDEX_STRIP_CUT_VALUE = 0xffff;

        public const uint D3D11_32BIT_INDEX_STRIP_CUT_VALUE = 0xffffffff;

        public const uint D3D11_8BIT_INDEX_STRIP_CUT_VALUE = 0xff;

        public const uint D3D11_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT = 9;

        public const uint D3D11_CLIP_OR_CULL_DISTANCE_COUNT = 8;

        public const uint D3D11_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT = 2;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT = 14;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS = 4;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT = 15;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_PARTIAL_UPDATE_EXTENTS_BYTE_ALIGNMENT = 16;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT = 15;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D11_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT = 64;

        public const uint D3D11_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D11_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT = 1;

        public const uint D3D11_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D11_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS = 1;

        public const uint D3D11_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT = 128;

        public const uint D3D11_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS = 1;

        public const uint D3D11_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT = 128;

        public const uint D3D11_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS = 1;

        public const uint D3D11_COMMONSHADER_SAMPLER_REGISTER_COUNT = 16;

        public const uint D3D11_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS = 1;

        public const uint D3D11_COMMONSHADER_SAMPLER_SLOT_COUNT = 16;

        public const uint D3D11_COMMONSHADER_SUBROUTINE_NESTING_LIMIT = 32;

        public const uint D3D11_COMMONSHADER_TEMP_REGISTER_COMPONENTS = 4;

        public const uint D3D11_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_COMMONSHADER_TEMP_REGISTER_COUNT = 4096;

        public const uint D3D11_COMMONSHADER_TEMP_REGISTER_READS_PER_INST = 3;

        public const uint D3D11_COMMONSHADER_TEMP_REGISTER_READ_PORTS = 3;

        public const uint D3D11_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX = 10;

        public const int D3D11_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN = -10;

        public const int D3D11_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE = -8;

        public const uint D3D11_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE = 7;

        public const uint D3D11_CS_4_X_BUCKET00_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 256;

        public const uint D3D11_CS_4_X_BUCKET00_MAX_NUM_THREADS_PER_GROUP = 64;

        public const uint D3D11_CS_4_X_BUCKET01_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 240;

        public const uint D3D11_CS_4_X_BUCKET01_MAX_NUM_THREADS_PER_GROUP = 68;

        public const uint D3D11_CS_4_X_BUCKET02_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 224;

        public const uint D3D11_CS_4_X_BUCKET02_MAX_NUM_THREADS_PER_GROUP = 72;

        public const uint D3D11_CS_4_X_BUCKET03_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 208;

        public const uint D3D11_CS_4_X_BUCKET03_MAX_NUM_THREADS_PER_GROUP = 76;

        public const uint D3D11_CS_4_X_BUCKET04_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 192;

        public const uint D3D11_CS_4_X_BUCKET04_MAX_NUM_THREADS_PER_GROUP = 84;

        public const uint D3D11_CS_4_X_BUCKET05_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 176;

        public const uint D3D11_CS_4_X_BUCKET05_MAX_NUM_THREADS_PER_GROUP = 92;

        public const uint D3D11_CS_4_X_BUCKET06_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 160;

        public const uint D3D11_CS_4_X_BUCKET06_MAX_NUM_THREADS_PER_GROUP = 100;

        public const uint D3D11_CS_4_X_BUCKET07_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 144;

        public const uint D3D11_CS_4_X_BUCKET07_MAX_NUM_THREADS_PER_GROUP = 112;

        public const uint D3D11_CS_4_X_BUCKET08_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 128;

        public const uint D3D11_CS_4_X_BUCKET08_MAX_NUM_THREADS_PER_GROUP = 128;

        public const uint D3D11_CS_4_X_BUCKET09_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 112;

        public const uint D3D11_CS_4_X_BUCKET09_MAX_NUM_THREADS_PER_GROUP = 144;

        public const uint D3D11_CS_4_X_BUCKET10_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 96;

        public const uint D3D11_CS_4_X_BUCKET10_MAX_NUM_THREADS_PER_GROUP = 168;

        public const uint D3D11_CS_4_X_BUCKET11_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 80;

        public const uint D3D11_CS_4_X_BUCKET11_MAX_NUM_THREADS_PER_GROUP = 204;

        public const uint D3D11_CS_4_X_BUCKET12_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 64;

        public const uint D3D11_CS_4_X_BUCKET12_MAX_NUM_THREADS_PER_GROUP = 256;

        public const uint D3D11_CS_4_X_BUCKET13_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 48;

        public const uint D3D11_CS_4_X_BUCKET13_MAX_NUM_THREADS_PER_GROUP = 340;

        public const uint D3D11_CS_4_X_BUCKET14_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 32;

        public const uint D3D11_CS_4_X_BUCKET14_MAX_NUM_THREADS_PER_GROUP = 512;

        public const uint D3D11_CS_4_X_BUCKET15_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 16;

        public const uint D3D11_CS_4_X_BUCKET15_MAX_NUM_THREADS_PER_GROUP = 768;

        public const uint D3D11_CS_4_X_DISPATCH_MAX_THREAD_GROUPS_IN_Z_DIMENSION = 1;

        public const uint D3D11_CS_4_X_RAW_UAV_BYTE_ALIGNMENT = 256;

        public const uint D3D11_CS_4_X_THREAD_GROUP_MAX_THREADS_PER_GROUP = 768;

        public const uint D3D11_CS_4_X_THREAD_GROUP_MAX_X = 768;

        public const uint D3D11_CS_4_X_THREAD_GROUP_MAX_Y = 768;

        public const uint D3D11_CS_4_X_UAV_REGISTER_COUNT = 1;

        public const uint D3D11_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION = 65535;

        public const uint D3D11_CS_TGSM_REGISTER_COUNT = 8192;

        public const uint D3D11_CS_TGSM_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_CS_TGSM_RESOURCE_REGISTER_COMPONENTS = 1;

        public const uint D3D11_CS_TGSM_RESOURCE_REGISTER_READ_PORTS = 1;

        public const uint D3D11_CS_THREADGROUPID_REGISTER_COMPONENTS = 3;

        public const uint D3D11_CS_THREADGROUPID_REGISTER_COUNT = 1;

        public const uint D3D11_CS_THREADIDINGROUPFLATTENED_REGISTER_COMPONENTS = 1;

        public const uint D3D11_CS_THREADIDINGROUPFLATTENED_REGISTER_COUNT = 1;

        public const uint D3D11_CS_THREADIDINGROUP_REGISTER_COMPONENTS = 3;

        public const uint D3D11_CS_THREADIDINGROUP_REGISTER_COUNT = 1;

        public const uint D3D11_CS_THREADID_REGISTER_COMPONENTS = 3;

        public const uint D3D11_CS_THREADID_REGISTER_COUNT = 1;

        public const uint D3D11_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP = 1024;

        public const uint D3D11_CS_THREAD_GROUP_MAX_X = 1024;

        public const uint D3D11_CS_THREAD_GROUP_MAX_Y = 1024;

        public const uint D3D11_CS_THREAD_GROUP_MAX_Z = 64;

        public const uint D3D11_CS_THREAD_GROUP_MIN_X = 1;

        public const uint D3D11_CS_THREAD_GROUP_MIN_Y = 1;

        public const uint D3D11_CS_THREAD_GROUP_MIN_Z = 1;

        public const uint D3D11_CS_THREAD_LOCAL_TEMP_REGISTER_POOL = 16384;

        public const float D3D11_DEFAULT_BLEND_FACTOR_ALPHA = 1.0f;

        public const float D3D11_DEFAULT_BLEND_FACTOR_BLUE = 1.0f;

        public const float D3D11_DEFAULT_BLEND_FACTOR_GREEN = 1.0f;

        public const float D3D11_DEFAULT_BLEND_FACTOR_RED = 1.0f;

        public const float D3D11_DEFAULT_BORDER_COLOR_COMPONENT = 0.0f;

        public const uint D3D11_DEFAULT_DEPTH_BIAS = 0;

        public const float D3D11_DEFAULT_DEPTH_BIAS_CLAMP = 0.0f;

        public const uint D3D11_DEFAULT_MAX_ANISOTROPY = 16;

        public const float D3D11_DEFAULT_MIP_LOD_BIAS = 0.0f;

        public const uint D3D11_DEFAULT_RENDER_TARGET_ARRAY_INDEX = 0;

        public const uint D3D11_DEFAULT_SAMPLE_MASK = 0xffffffff;

        public const uint D3D11_DEFAULT_SCISSOR_ENDX = 0;

        public const uint D3D11_DEFAULT_SCISSOR_ENDY = 0;

        public const uint D3D11_DEFAULT_SCISSOR_STARTX = 0;

        public const uint D3D11_DEFAULT_SCISSOR_STARTY = 0;

        public const float D3D11_DEFAULT_SLOPE_SCALED_DEPTH_BIAS = 0.0f;

        public const uint D3D11_DEFAULT_STENCIL_READ_MASK = 0xff;

        public const uint D3D11_DEFAULT_STENCIL_REFERENCE = 0;

        public const uint D3D11_DEFAULT_STENCIL_WRITE_MASK = 0xff;

        public const uint D3D11_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX = 0;

        public const uint D3D11_DEFAULT_VIEWPORT_HEIGHT = 0;

        public const float D3D11_DEFAULT_VIEWPORT_MAX_DEPTH = 0.0f;

        public const float D3D11_DEFAULT_VIEWPORT_MIN_DEPTH = 0.0f;

        public const uint D3D11_DEFAULT_VIEWPORT_TOPLEFTX = 0;

        public const uint D3D11_DEFAULT_VIEWPORT_TOPLEFTY = 0;

        public const uint D3D11_DEFAULT_VIEWPORT_WIDTH = 0;

        public const uint D3D11_DS_INPUT_CONTROL_POINTS_MAX_TOTAL_SCALARS = 3968;

        public const uint D3D11_DS_INPUT_CONTROL_POINT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_DS_INPUT_CONTROL_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_DS_INPUT_CONTROL_POINT_REGISTER_COUNT = 32;

        public const uint D3D11_DS_INPUT_CONTROL_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_DS_INPUT_CONTROL_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_DS_INPUT_DOMAIN_POINT_REGISTER_COMPONENTS = 3;

        public const uint D3D11_DS_INPUT_DOMAIN_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_DS_INPUT_DOMAIN_POINT_REGISTER_COUNT = 1;

        public const uint D3D11_DS_INPUT_DOMAIN_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_DS_INPUT_DOMAIN_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_DS_INPUT_PATCH_CONSTANT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_DS_INPUT_PATCH_CONSTANT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_DS_INPUT_PATCH_CONSTANT_REGISTER_COUNT = 32;

        public const uint D3D11_DS_INPUT_PATCH_CONSTANT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_DS_INPUT_PATCH_CONSTANT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_DS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_DS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_DS_INPUT_PRIMITIVE_ID_REGISTER_COUNT = 1;

        public const uint D3D11_DS_INPUT_PRIMITIVE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_DS_INPUT_PRIMITIVE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D11_DS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_DS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_DS_OUTPUT_REGISTER_COUNT = 32;

        public const double D3D11_FLOAT16_FUSED_TOLERANCE_IN_ULP = 0.6;

        public const float D3D11_FLOAT32_MAX = 3.402823466e+38f;

        public const float D3D11_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6f;

        public const float D3D11_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR = 2.4f;

        public const float D3D11_FLOAT_TO_SRGB_EXPONENT_NUMERATOR = 1.0f;

        public const float D3D11_FLOAT_TO_SRGB_OFFSET = 0.055f;

        public const float D3D11_FLOAT_TO_SRGB_SCALE_1 = 12.92f;

        public const float D3D11_FLOAT_TO_SRGB_SCALE_2 = 1.055f;

        public const float D3D11_FLOAT_TO_SRGB_THRESHOLD = 0.0031308f;

        public const float D3D11_FTOI_INSTRUCTION_MAX_INPUT = 2147483647.999f;

        public const float D3D11_FTOI_INSTRUCTION_MIN_INPUT = -2147483648.999f;

        public const float D3D11_FTOU_INSTRUCTION_MAX_INPUT = 4294967295.999f;

        public const float D3D11_FTOU_INSTRUCTION_MIN_INPUT = 0.0f;

        public const uint D3D11_GS_INPUT_INSTANCE_ID_READS_PER_INST = 2;

        public const uint D3D11_GS_INPUT_INSTANCE_ID_READ_PORTS = 1;

        public const uint D3D11_GS_INPUT_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_GS_INPUT_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_GS_INPUT_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D11_GS_INPUT_PRIM_CONST_REGISTER_COMPONENTS = 1;

        public const uint D3D11_GS_INPUT_PRIM_CONST_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_GS_INPUT_PRIM_CONST_REGISTER_COUNT = 1;

        public const uint D3D11_GS_INPUT_PRIM_CONST_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_GS_INPUT_PRIM_CONST_REGISTER_READ_PORTS = 1;

        public const uint D3D11_GS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_GS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_GS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D11_GS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_GS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_GS_INPUT_REGISTER_VERTICES = 32;

        public const uint D3D11_GS_MAX_INSTANCE_COUNT = 32;

        public const uint D3D11_GS_MAX_OUTPUT_VERTEX_COUNT_ACROSS_INSTANCES = 1024;

        public const uint D3D11_GS_OUTPUT_ELEMENTS = 32;

        public const uint D3D11_GS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_GS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_GS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D11_HS_CONTROL_POINT_PHASE_INPUT_REGISTER_COUNT = 32;

        public const uint D3D11_HS_CONTROL_POINT_PHASE_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D11_HS_CONTROL_POINT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_HS_CONTROL_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_CONTROL_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_CONTROL_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_FORK_PHASE_INSTANCE_COUNT_UPPER_BOUND = 0xffffffff;

        public const uint D3D11_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D11_HS_INPUT_FORK_INSTANCE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_INPUT_FORK_INSTANCE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D11_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_HS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_INPUT_PRIMITIVE_ID_REGISTER_COUNT = 1;

        public const uint D3D11_HS_INPUT_PRIMITIVE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_INPUT_PRIMITIVE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_JOIN_PHASE_INSTANCE_COUNT_UPPER_BOUND = 0xffffffff;

        public const float D3D11_HS_MAXTESSFACTOR_LOWER_BOUND = 1.0f;

        public const float D3D11_HS_MAXTESSFACTOR_UPPER_BOUND = 64.0f;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINTS_MAX_TOTAL_SCALARS = 3968;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COUNT = 1;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COUNT = 32;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_HS_OUTPUT_PATCH_CONSTANT_REGISTER_SCALAR_COMPONENTS = 128;

        public const uint D3D11_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D11_IA_DEFAULT_PRIMITIVE_TOPOLOGY = 0;

        public const uint D3D11_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D11_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT = 1;

        public const uint D3D11_IA_INSTANCE_ID_BIT_COUNT = 32;

        public const uint D3D11_IA_INTEGER_ARITHMETIC_BIT_COUNT = 32;

        public const uint D3D11_IA_PATCH_MAX_CONTROL_POINT_COUNT = 32;

        public const uint D3D11_IA_PRIMITIVE_ID_BIT_COUNT = 32;

        public const uint D3D11_IA_VERTEX_ID_BIT_COUNT = 32;

        public const uint D3D11_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = 32;

        public const uint D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 128;

        public const uint D3D11_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = 32;

        public const uint D3D11_INTEGER_DIVIDE_BY_ZERO_QUOTIENT = 0xffffffff;

        public const uint D3D11_INTEGER_DIVIDE_BY_ZERO_REMAINDER = 0xffffffff;

        public const uint D3D11_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL = 0xffffffff;

        public const uint D3D11_KEEP_UNORDERED_ACCESS_VIEWS = 0xffffffff;

        public const float D3D11_LINEAR_GAMMA = 1.0f;

        public const uint D3D11_MAJOR_VERSION = 11;

        public const float D3D11_MAX_BORDER_COLOR_COMPONENT = 1.0f;

        public const float D3D11_MAX_DEPTH = 1.0f;

        public const uint D3D11_MAX_MAXANISOTROPY = 16;

        public const uint D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT = 32;

        public const float D3D11_MAX_POSITION_VALUE = 3.402823466e+34f;

        public const uint D3D11_MAX_TEXTURE_DIMENSION_2_TO_EXP = 17;

        public const uint D3D11_MINOR_VERSION = 0;

        public const float D3D11_MIN_BORDER_COLOR_COMPONENT = 0.0f;

        public const float D3D11_MIN_DEPTH = 0.0f;

        public const uint D3D11_MIN_MAXANISOTROPY = 0;

        public const float D3D11_MIP_LOD_BIAS_MAX = 15.99f;

        public const float D3D11_MIP_LOD_BIAS_MIN = -16.0f;

        public const uint D3D11_MIP_LOD_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D11_MIP_LOD_RANGE_BIT_COUNT = 8;

        public const float D3D11_MULTISAMPLE_ANTIALIAS_LINE_WIDTH = 1.4f;

        public const uint D3D11_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT = 0;

        public const uint D3D11_PIXEL_ADDRESS_RANGE_BIT_COUNT = 15;

        public const uint D3D11_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT = 16;

        public const uint D3D11_PS_CS_UAV_REGISTER_COMPONENTS = 1;

        public const uint D3D11_PS_CS_UAV_REGISTER_COUNT = 8;

        public const uint D3D11_PS_CS_UAV_REGISTER_READS_PER_INST = 1;

        public const uint D3D11_PS_CS_UAV_REGISTER_READ_PORTS = 1;

        public const uint D3D11_PS_FRONTFACING_DEFAULT_VALUE = 0xffffffff;

        public const uint D3D11_PS_FRONTFACING_FALSE_VALUE = 0;

        public const uint D3D11_PS_FRONTFACING_TRUE_VALUE = 0xffffffff;

        public const uint D3D11_PS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_PS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D11_PS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_PS_INPUT_REGISTER_READ_PORTS = 1;

        public const float D3D11_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.0f;

        public const uint D3D11_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS = 1;

        public const uint D3D11_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_PS_OUTPUT_DEPTH_REGISTER_COUNT = 1;

        public const uint D3D11_PS_OUTPUT_MASK_REGISTER_COMPONENTS = 1;

        public const uint D3D11_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_PS_OUTPUT_MASK_REGISTER_COUNT = 1;

        public const uint D3D11_PS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_PS_OUTPUT_REGISTER_COUNT = 8;

        public const float D3D11_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.5f;

        public const uint D3D11_RAW_UAV_SRV_BYTE_ALIGNMENT = 16;

        public const uint D3D11_REQ_BLEND_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D11_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP = 27;

        public const uint D3D11_REQ_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D11_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D11_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 32;

        public const uint D3D11_REQ_DRAW_VERTEX_COUNT_2_TO_EXP = 32;

        public const uint D3D11_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION = 16384;

        public const uint D3D11_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT = 1024;

        public const uint D3D11_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D11_REQ_MAXANISOTROPY = 16;

        public const uint D3D11_REQ_MIP_LEVELS = 15;

        public const uint D3D11_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES = 2048;

        public const uint D3D11_REQ_RASTERIZER_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D11_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH = 16384;

        public const uint D3D11_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_A_TERM = 128;

        public const float D3D11_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_B_TERM = 0.25f;

        public const uint D3D11_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_C_TERM = 2048;

        public const uint D3D11_REQ_RESOURCE_VIEW_COUNT_PER_DEVICE_2_TO_EXP = 20;

        public const uint D3D11_REQ_SAMPLER_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D11_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION = 2048;

        public const uint D3D11_REQ_TEXTURE1D_U_DIMENSION = 16384;

        public const uint D3D11_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION = 2048;

        public const uint D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION = 16384;

        public const uint D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION = 2048;

        public const uint D3D11_REQ_TEXTURECUBE_DIMENSION = 16384;

        public const uint D3D11_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL = 0;

        public const uint D3D11_SHADER_MAJOR_VERSION = 5;

        public const uint D3D11_SHADER_MAX_INSTANCES = 65535;

        public const uint D3D11_SHADER_MAX_INTERFACES = 253;

        public const uint D3D11_SHADER_MAX_INTERFACE_CALL_SITES = 4096;

        public const uint D3D11_SHADER_MAX_TYPES = 65535;

        public const uint D3D11_SHADER_MINOR_VERSION = 0;

        public const uint D3D11_SHIFT_INSTRUCTION_PAD_VALUE = 0;

        public const uint D3D11_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT = 5;

        public const uint D3D11_SIMULTANEOUS_RENDER_TARGET_COUNT = 8;

        public const uint D3D11_SO_BUFFER_MAX_STRIDE_IN_BYTES = 2048;

        public const uint D3D11_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES = 512;

        public const uint D3D11_SO_BUFFER_SLOT_COUNT = 4;

        public const uint D3D11_SO_DDI_REGISTER_INDEX_DENOTING_GAP = 0xffffffff;

        public const uint D3D11_SO_NO_RASTERIZED_STREAM = 0xffffffff;

        public const uint D3D11_SO_OUTPUT_COMPONENT_COUNT = 128;

        public const uint D3D11_SO_STREAM_COUNT = 4;

        public const uint D3D11_SPEC_DATE_DAY = 16;

        public const uint D3D11_SPEC_DATE_MONTH = 05;

        public const uint D3D11_SPEC_DATE_YEAR = 2011;

        public const double D3D11_SPEC_VERSION = 1.07;

        public const float D3D11_SRGB_GAMMA = 2.2f;

        public const float D3D11_SRGB_TO_FLOAT_DENOMINATOR_1 = 12.92f;

        public const float D3D11_SRGB_TO_FLOAT_DENOMINATOR_2 = 1.055f;

        public const float D3D11_SRGB_TO_FLOAT_EXPONENT = 2.4f;

        public const float D3D11_SRGB_TO_FLOAT_OFFSET = 0.055f;

        public const float D3D11_SRGB_TO_FLOAT_THRESHOLD = 0.04045f;

        public const float D3D11_SRGB_TO_FLOAT_TOLERANCE_IN_ULP = 0.5f;

        public const uint D3D11_STANDARD_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_STANDARD_COMPONENT_BIT_COUNT_DOUBLED = 64;

        public const uint D3D11_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE = 4;

        public const uint D3D11_STANDARD_PIXEL_COMPONENT_COUNT = 128;

        public const uint D3D11_STANDARD_PIXEL_ELEMENT_COUNT = 32;

        public const uint D3D11_STANDARD_VECTOR_SIZE = 4;

        public const uint D3D11_STANDARD_VERTEX_ELEMENT_COUNT = 32;

        public const uint D3D11_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT = 64;

        public const uint D3D11_SUBPIXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D11_SUBTEXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D11_TESSELLATOR_MAX_EVEN_TESSELLATION_FACTOR = 64;

        public const uint D3D11_TESSELLATOR_MAX_ISOLINE_DENSITY_TESSELLATION_FACTOR = 64;

        public const uint D3D11_TESSELLATOR_MAX_ODD_TESSELLATION_FACTOR = 63;

        public const uint D3D11_TESSELLATOR_MAX_TESSELLATION_FACTOR = 64;

        public const uint D3D11_TESSELLATOR_MIN_EVEN_TESSELLATION_FACTOR = 2;

        public const uint D3D11_TESSELLATOR_MIN_ISOLINE_DENSITY_TESSELLATION_FACTOR = 1;

        public const uint D3D11_TESSELLATOR_MIN_ODD_TESSELLATION_FACTOR = 1;

        public const uint D3D11_TEXEL_ADDRESS_RANGE_BIT_COUNT = 16;

        public const uint D3D11_UNBOUND_MEMORY_ACCESS_RESULT = 0;

        public const uint D3D11_VIEWPORT_AND_SCISSORRECT_MAX_INDEX = 15;

        public const uint D3D11_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE = 16;

        public const uint D3D11_VIEWPORT_BOUNDS_MAX = 32767;

        public const int D3D11_VIEWPORT_BOUNDS_MIN = -32768;

        public const uint D3D11_VS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_VS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D11_VS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D11_VS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D11_VS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D11_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D11_VS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D11_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT = 10;

        public const uint D3D11_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 25;

        public const uint D3D11_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP = 25;

        public const uint D3D11_1_UAV_SLOT_COUNT = 64;

        public const uint D3D11_2_TILED_RESOURCE_TILE_SIZE_IN_BYTES = 65536;

        public const uint D3D11_4_VIDEO_DECODER_MAX_HISTOGRAM_COMPONENTS = 4;

        public const uint D3D11_4_VIDEO_DECODER_HISTOGRAM_OFFSET_ALIGNMENT = 256;

        public const uint _FACD3D11 = 0x87c;

        public const uint D3D11_APPEND_ALIGNED_ELEMENT = 0xffffffff;

        public const uint D3D11_FILTER_REDUCTION_TYPE_MASK = 0x3;

        public const uint D3D11_FILTER_REDUCTION_TYPE_SHIFT = 7;

        public const uint D3D11_FILTER_TYPE_MASK = 0x3;

        public const uint D3D11_MIN_FILTER_SHIFT = 4;

        public const uint D3D11_MAG_FILTER_SHIFT = 2;

        public const uint D3D11_MIP_FILTER_SHIFT = 0;

        public const uint D3D11_COMPARISON_FILTERING_BIT = 0x80;

        public const uint D3D11_ANISOTROPIC_FILTERING_BIT = 0x40;

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG2_MOCOMP__scanned__ = new Guid(0xe6a9f44b, 0x61b0, 0x4563,0x9e,0xa4,0x63,0xd2,0xa3,0xc6,0xfe,0x66);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG2_IDCT__scanned__ = new Guid(0xbf22ad00, 0x03ea, 0x4690,0x80,0x77,0x47,0x33,0x46,0x20,0x9b,0x7e);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG2_VLD__scanned__ = new Guid(0xee27417f, 0x5e28, 0x4e65,0xbe,0xea,0x1d,0x26,0xb5,0x08,0xad,0xc9);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG1_VLD__scanned__ = new Guid(0x6f3ec719, 0x3735, 0x42cc,0x80,0x63,0x65,0xcc,0x3c,0xb3,0x66,0x16);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG2and1_VLD__scanned__ = new Guid(0x86695f12, 0x340e, 0x4f04,0x9f,0xd3,0x92,0x53,0xdd,0x32,0x74,0x60);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_MOCOMP_NOFGT__scanned__ = new Guid(0x1b81be64, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_MOCOMP_FGT__scanned__ = new Guid(0x1b81be65, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_IDCT_NOFGT__scanned__ = new Guid(0x1b81be66, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_IDCT_FGT__scanned__ = new Guid(0x1b81be67, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_NOFGT__scanned__ = new Guid(0x1b81be68, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_FGT__scanned__ = new Guid(0x1b81be69, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_WITHFMOASO_NOFGT__scanned__ = new Guid(0xd5f04ff9, 0x3418,0x45d8,0x95,0x61,0x32,0xa7,0x6a,0xae,0x2d,0xdd);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_STEREO_PROGRESSIVE_NOFGT__scanned__ = new Guid(0xd79be8da, 0x0cf1,0x4c81,0xb8,0x2a,0x69,0xa4,0xe2,0x36,0xf4,0x3d);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_STEREO_NOFGT__scanned__ = new Guid(0xf9aaccbb, 0xc2b6,0x4cfc,0x87,0x79,0x57,0x07,0xb1,0x76,0x05,0x52);

        public static readonly Guid D3D11_DECODER_PROFILE_H264_VLD_MULTIVIEW_NOFGT__scanned__ = new Guid(0x705b9d82, 0x76cf,0x49d6,0xb7,0xe6,0xac,0x88,0x72,0xdb,0x01,0x3c);

        public static readonly Guid D3D11_DECODER_PROFILE_WMV8_POSTPROC__scanned__ = new Guid(0x1b81be80, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_WMV8_MOCOMP__scanned__ = new Guid(0x1b81be81, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_WMV9_POSTPROC__scanned__ = new Guid(0x1b81be90, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_WMV9_MOCOMP__scanned__ = new Guid(0x1b81be91, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_WMV9_IDCT__scanned__ = new Guid(0x1b81be94, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_VC1_POSTPROC__scanned__ = new Guid(0x1b81beA0, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_VC1_MOCOMP__scanned__ = new Guid(0x1b81beA1, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_VC1_IDCT__scanned__ = new Guid(0x1b81beA2, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_VC1_VLD__scanned__ = new Guid(0x1b81beA3, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_VC1_D2010__scanned__ = new Guid(0x1b81beA4, 0xa0c7,0x11d3,0xb9,0x84,0x00,0xc0,0x4f,0x2e,0x73,0xc5);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG4PT2_VLD_SIMPLE__scanned__ = new Guid(0xefd64d74, 0xc9e8,0x41d7,0xa5,0xe9,0xe9,0xb0,0xe3,0x9f,0xa3,0x19);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG4PT2_VLD_ADVSIMPLE_NOGMC__scanned__ = new Guid(0xed418a9f, 0x010d,0x4eda,0x9a,0xe3,0x9a,0x65,0x35,0x8d,0x8d,0x2e);

        public static readonly Guid D3D11_DECODER_PROFILE_MPEG4PT2_VLD_ADVSIMPLE_GMC__scanned__ = new Guid(0xab998b5b, 0x4258,0x44a9,0x9f,0xeb,0x94,0xe5,0x97,0xa6,0xba,0xae);

        public static readonly Guid D3D11_DECODER_PROFILE_HEVC_VLD_MAIN__scanned__ = new Guid(0x5b11d51b, 0x2f4c,0x4452,0xbc,0xc3,0x09,0xf2,0xa1,0x16,0x0c,0xc0);

        public static readonly Guid D3D11_DECODER_PROFILE_HEVC_VLD_MAIN10__scanned__ = new Guid(0x107af0e0, 0xef1a,0x4d19,0xab,0xa8,0x67,0xa1,0x63,0x07,0x3d,0x13);

        public static readonly Guid D3D11_DECODER_PROFILE_VP9_VLD_PROFILE0__scanned__ = new Guid(0x463707f8, 0xa1d0, 0x4585, 0x87, 0x6d, 0x83, 0xaa, 0x6d, 0x60, 0xb8, 0x9e);

        public static readonly Guid D3D11_DECODER_PROFILE_VP9_VLD_10BIT_PROFILE2__scanned__ = new Guid(0xa4c749ef, 0x6ecf, 0x48aa, 0x84, 0x48, 0x50, 0xa7, 0xa1, 0x16, 0x5f, 0xf7);

        public static readonly Guid D3D11_DECODER_PROFILE_VP8_VLD__scanned__ = new Guid(0x90b899ea, 0x3a62, 0x4705, 0x88, 0xb3, 0x8d, 0xf0, 0x4b, 0x27, 0x44, 0xe7);

        public static readonly Guid D3D11_CRYPTO_TYPE_AES128_CTR__scanned__ = new Guid(0x9b6bd711, 0x4f74, 0x41c9, 0x9e, 0x7b, 0xb, 0xe2, 0xd7, 0xd9, 0x3b, 0x4f );

        public static readonly Guid D3D11_DECODER_ENCRYPTION_HW_CENC__scanned__ = new Guid(0x89d6ac4f, 0x9f2, 0x4229, 0xb2, 0xcd, 0x37, 0x74, 0xa, 0x6d, 0xfd, 0x81);

        public static readonly Guid D3D11_DECODER_BITSTREAM_ENCRYPTION_TYPE_CENC__scanned__ = new Guid(0xb0405235, 0xc13d, 0x44f2, 0x9a, 0xe5, 0xdd, 0x48, 0xe0, 0x8e, 0x5b, 0x67);

        public static readonly Guid D3D11_DECODER_BITSTREAM_ENCRYPTION_TYPE_CBCS__scanned__ = new Guid(0x422d9319, 0x9d21, 0x4bb7, 0x93, 0x71, 0xfa, 0xf5, 0xa8, 0x2c, 0x3e, 0x04);

        public static readonly Guid D3D11_KEY_EXCHANGE_HW_PROTECTION__scanned__ = new Guid(0xb1170d8a, 0x628d, 0x4da3, 0xad, 0x3b, 0x82, 0xdd, 0xb0, 0x8b, 0x49, 0x70);

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_PROTECTION__scanned__ = new Guid(0xa84eb584, 0xc495, 0x48aa, 0xb9, 0x4d, 0x8b, 0xd2, 0xd6, 0xfb, 0xce, 0x5 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_CHANNEL_TYPE__scanned__ = new Guid(0xbc1b18a5, 0xb1fb, 0x42ab, 0xbd, 0x94, 0xb5, 0x82, 0x8b, 0x4b, 0xf7, 0xbe );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_DEVICE_HANDLE__scanned__ = new Guid(0xec1c539d, 0x8cff, 0x4e2a, 0xbc, 0xc4, 0xf5, 0x69, 0x2f, 0x99, 0xf4, 0x80 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_CRYPTO_SESSION__scanned__ = new Guid(0x2634499e, 0xd018, 0x4d74, 0xac, 0x17, 0x7f, 0x72, 0x40, 0x59, 0x52, 0x8d );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS_COUNT__scanned__ = new Guid(0xdb207b3, 0x9450, 0x46a6, 0x82, 0xde, 0x1b, 0x96, 0xd4, 0x4f, 0x9c, 0xf2 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_RESTRICTED_SHARED_RESOURCE_PROCESS__scanned__ = new Guid(0x649bbadb, 0xf0f4, 0x4639, 0xa1, 0x5b, 0x24, 0x39, 0x3f, 0xc3, 0xab, 0xac );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_UNRESTRICTED_PROTECTED_SHARED_RESOURCE_COUNT__scanned__ = new Guid(0x12f0bd6, 0xe662, 0x4474, 0xbe, 0xfd, 0xaa, 0x53, 0xe5, 0x14, 0x3c, 0x6d );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_OUTPUT_ID_COUNT__scanned__ = new Guid(0x2c042b5e, 0x8c07, 0x46d5, 0xaa, 0xbe, 0x8f, 0x75, 0xcb, 0xad, 0x4c, 0x31 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_OUTPUT_ID__scanned__ = new Guid(0x839ddca3, 0x9b4e, 0x41e4, 0xb0, 0x53, 0x89, 0x2b, 0xd2, 0xa1, 0x1e, 0xe7 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_ACCESSIBILITY_ATTRIBUTES__scanned__ = new Guid(0x6214d9d2, 0x432c, 0x4abb, 0x9f, 0xce, 0x21, 0x6e, 0xea, 0x26, 0x9e, 0x3b );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_ENCRYPTION_WHEN_ACCESSIBLE_GUID_COUNT__scanned__ = new Guid(0xb30f7066, 0x203c, 0x4b07, 0x93, 0xfc, 0xce, 0xaa, 0xfd, 0x61, 0x24, 0x1e );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_ENCRYPTION_WHEN_ACCESSIBLE_GUID__scanned__ = new Guid(0xf83a5958, 0xe986, 0x4bda, 0xbe, 0xb0, 0x41, 0x1f, 0x6a, 0x7a, 0x1, 0xb7 );

        public static readonly Guid D3D11_AUTHENTICATED_QUERY_CURRENT_ENCRYPTION_WHEN_ACCESSIBLE__scanned__ = new Guid(0xec1791c7, 0xdad3, 0x4f15, 0x9e, 0xc3, 0xfa, 0xa9, 0x3d, 0x60, 0xd4, 0xf0 );

        public static readonly Guid D3D11_AUTHENTICATED_CONFIGURE_INITIALIZE__scanned__ = new Guid(0x6114bdb, 0x3523, 0x470a, 0x8d, 0xca, 0xfb, 0xc2, 0x84, 0x51, 0x54, 0xf0 );

        public static readonly Guid D3D11_AUTHENTICATED_CONFIGURE_PROTECTION__scanned__ = new Guid(0x50455658, 0x3f47, 0x4362, 0xbf, 0x99, 0xbf, 0xdf, 0xcd, 0xe9, 0xed, 0x29 );

        public static readonly Guid D3D11_AUTHENTICATED_CONFIGURE_CRYPTO_SESSION__scanned__ = new Guid(0x6346cc54, 0x2cfc, 0x4ad4, 0x82, 0x24, 0xd1, 0x58, 0x37, 0xde, 0x77, 0x0 );

        public static readonly Guid D3D11_AUTHENTICATED_CONFIGURE_SHARED_RESOURCE__scanned__ = new Guid(0x772d047, 0x1b40, 0x48e8, 0x9c, 0xa6, 0xb5, 0xf5, 0x10, 0xde, 0x9f, 0x1 );

        public static readonly Guid D3D11_AUTHENTICATED_CONFIGURE_ENCRYPTION_WHEN_ACCESSIBLE__scanned__ = new Guid(0x41fff286, 0x6ae0, 0x4d43, 0x9d, 0x55, 0xa4, 0x6e, 0x9e, 0xfd, 0x15, 0x8a );

        public static readonly Guid D3D11_KEY_EXCHANGE_RSAES_OAEP__scanned__ = new Guid(0xc1949895, 0xd72a, 0x4a1d, 0x8e, 0x5d, 0xed, 0x85, 0x7d, 0x17, 0x15, 0x20);

        public const uint D3D11_SDK_VERSION = 7;

        public const uint D3D11_PACKED_TILE = 0xffffffff;

        public const uint D3D11_SDK_LAYERS_VERSION = 1;

        public const uint D3D11_DEBUG_FEATURE_FLUSH_PER_RENDER_OP = 0x1;

        public const uint D3D11_DEBUG_FEATURE_FINISH_PER_RENDER_OP = 0x2;

        public const uint D3D11_DEBUG_FEATURE_PRESENT_PER_RENDER_OP = 0x4;

        public const uint D3D11_DEBUG_FEATURE_ALWAYS_DISCARD_OFFERED_RESOURCE = 0x8;

        public const uint D3D11_DEBUG_FEATURE_NEVER_DISCARD_OFFERED_RESOURCE = 0x10;

        public const uint D3D11_DEBUG_FEATURE_AVOID_BEHAVIOR_CHANGING_DEBUG_AIDS = 0x40;

        public const uint D3D11_DEBUG_FEATURE_DISABLE_TILED_RESOURCE_MAPPING_TRACKING_AND_VALIDATION = 0x80;

        public static readonly Guid DXGI_DEBUG_D3D11__scanned__ = new Guid(0x4b99317b, 0xac39, 0x4aa6, 0xbb, 0xb, 0xba, 0xa0, 0x47, 0x84, 0x79, 0x8f);

        public const uint D3D11_INFO_QUEUE_DEFAULT_MESSAGE_COUNT_LIMIT = 1024;

        public const int D3D_RETURN_PARAMETER_INDEX = -1;

        public const uint D3D_SHADER_REQUIRES_DOUBLES = 0x00000001;

        public const uint D3D_SHADER_REQUIRES_EARLY_DEPTH_STENCIL = 0x00000002;

        public const uint D3D_SHADER_REQUIRES_UAVS_AT_EVERY_STAGE = 0x00000004;

        public const uint D3D_SHADER_REQUIRES_64_UAVS = 0x00000008;

        public const uint D3D_SHADER_REQUIRES_MINIMUM_PRECISION = 0x00000010;

        public const uint D3D_SHADER_REQUIRES_11_1_DOUBLE_EXTENSIONS = 0x00000020;

        public const uint D3D_SHADER_REQUIRES_11_1_SHADER_EXTENSIONS = 0x00000040;

        public const uint D3D_SHADER_REQUIRES_LEVEL_9_COMPARISON_FILTERING = 0x00000080;

        public const uint D3D_SHADER_REQUIRES_TILED_RESOURCES = 0x00000100;

        public const uint D3D11_TRACE_COMPONENT_X = 0x1;

        public const uint D3D11_TRACE_COMPONENT_Y = 0x2;

        public const uint D3D11_TRACE_COMPONENT_Z = 0x4;

        public const uint D3D11_TRACE_COMPONENT_W = 0x8;

        public const uint D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_WRITES = 0x1;

        public const uint D3D11_SHADER_TRACE_FLAG_RECORD_REGISTER_READS = 0x2;

        public const uint D3D11_TRACE_REGISTER_FLAGS_RELATIVE_INDEXING = 0x1;

        public const uint D3D11_TRACE_MISC_GS_EMIT = 0x1;

        public const uint D3D11_TRACE_MISC_GS_CUT = 0x2;

        public const uint D3D11_TRACE_MISC_PS_DISCARD = 0x4;

        public const uint D3D11_TRACE_MISC_GS_EMIT_STREAM = 0x8;

        public const uint D3D11_TRACE_MISC_GS_CUT_STREAM = 0x10;

        public const uint D3D11_TRACE_MISC_HALT = 0x20;

        public const uint D3D11_TRACE_MISC_MESSAGE = 0x40;

        public const uint D3D_FL9_1_REQ_TEXTURE1D_U_DIMENSION = 2048;

        public const uint D3D_FL9_3_REQ_TEXTURE1D_U_DIMENSION = 4096;

        public const uint D3D_FL9_1_REQ_TEXTURE2D_U_OR_V_DIMENSION = 2048;

        public const uint D3D_FL9_3_REQ_TEXTURE2D_U_OR_V_DIMENSION = 4096;

        public const uint D3D_FL9_1_REQ_TEXTURECUBE_DIMENSION = 512;

        public const uint D3D_FL9_3_REQ_TEXTURECUBE_DIMENSION = 4096;

        public const uint D3D_FL9_1_REQ_TEXTURE3D_U_V_OR_W_DIMENSION = 256;

        public const uint D3D_FL9_1_DEFAULT_MAX_ANISOTROPY = 2;

        public const uint D3D_FL9_1_IA_PRIMITIVE_MAX_COUNT = 65535;

        public const uint D3D_FL9_2_IA_PRIMITIVE_MAX_COUNT = 1048575;

        public const uint D3D_FL9_1_SIMULTANEOUS_RENDER_TARGET_COUNT = 1;

        public const uint D3D_FL9_3_SIMULTANEOUS_RENDER_TARGET_COUNT = 4;

        public const uint D3D_FL9_1_MAX_TEXTURE_REPEAT = 128;

        public const uint D3D_FL9_2_MAX_TEXTURE_REPEAT = 2048;

        public const uint D3D_FL9_3_MAX_TEXTURE_REPEAT = 8192;

        public static readonly Guid WKPDID_D3DDebugObjectName__scanned__ = new Guid(0x429b8c22,0x9188,0x4b0c,0x87,0x42,0xac,0xb0,0xbf,0x85,0xc2,0x00);

        public static readonly Guid WKPDID_D3DDebugObjectNameW__scanned__ = new Guid(0x4cca5fd8,0x921f,0x42c8,0x85,0x66,0x70,0xca,0xf2,0xa9,0xb7,0x41);

        public static readonly Guid WKPDID_CommentStringW__scanned__ = new Guid(0xd0149dc0,0x90e8,0x4ec8,0x81, 0x44, 0xe9, 0x00, 0xad, 0x26, 0x6b, 0xb2);

        public const uint D3D_COMPONENT_MASK_X = 1;

        public const uint D3D_COMPONENT_MASK_Y = 2;

        public const uint D3D_COMPONENT_MASK_Z = 4;

        public const uint D3D_COMPONENT_MASK_W = 8;

        public static readonly Guid D3D_TEXTURE_LAYOUT_ROW_MAJOR__scanned__ = new Guid(0xb5dc234f,0x72bb,0x4bec,0x97,0x05,0x8c,0xf2,0x58,0xdf,0x6b,0x6c);

        public static readonly Guid D3D_TEXTURE_LAYOUT_64KB_STANDARD_SWIZZLE__scanned__ = new Guid(0x4c0f29e3,0x3f5f,0x4d35,0x84,0xc9,0xbc,0x09,0x83,0xb6,0x2c,0x28);

        public static readonly Guid IID_ID3DX11Scan__scanned__ = new Guid(0x5089b68f, 0xe71d, 0x4d38, 0xbe, 0x8e, 0xf3, 0x63, 0xb9, 0x5a, 0x94, 0x05);

        public static readonly Guid IID_ID3DX11SegmentedScan__scanned__ = new Guid(0xa915128c, 0xd954, 0x4c79, 0xbf, 0xe1, 0x64, 0xdb, 0x92, 0x31, 0x94, 0xd6);

        public const uint D3DX11_FFT_MAX_PRECOMPUTE_BUFFERS = 4;

        public const uint D3DX11_FFT_MAX_TEMP_BUFFERS = 4;

        public const uint D3DX11_FFT_MAX_DIMENSIONS = 32;

        public static readonly Guid IID_ID3DX11FFT__scanned__ = new Guid(0xb3f7a938, 0x4c93, 0x4310, 0xa6, 0x75, 0xb3, 0x0d, 0x6d, 0xe5, 0x05, 0x53);

    }
}
