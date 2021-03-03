// Copyright © Tanner Gooding and Contributors. Licensed under the MIT License (MIT). See License.md in the repository root for more information.

// Ported from um/d3d12.h in the Windows SDK for Windows 10.0.19041.0
// Original source is Copyright © Microsoft. All rights reserved.

using System;
using static Windows.Win32.Direct3D12.D3D12_FILTER_REDUCTION_TYPE;
using static Windows.Win32.Direct3D12.D3D12_FILTER_TYPE;

namespace Windows.Win32.Direct3D12
{
    public static unsafe partial class Apis
    {
        public const uint D3D12_16BIT_INDEX_STRIP_CUT_VALUE = 0xFFFF;

        public const uint D3D12_32BIT_INDEX_STRIP_CUT_VALUE = 0xFFFFFFFF;

        public const uint D3D12_8BIT_INDEX_STRIP_CUT_VALUE = 0xFF;

        public const uint D3D12_APPEND_ALIGNED_ELEMENT = 0xFFFFFFFF;

        public const uint D3D12_ARRAY_AXIS_ADDRESS_RANGE_BIT_COUNT = 9;

        public const uint D3D12_CLIP_OR_CULL_DISTANCE_COUNT = 8;

        public const uint D3D12_CLIP_OR_CULL_DISTANCE_ELEMENT_COUNT = 2;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_API_SLOT_COUNT = 14;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_COMPONENTS = 4;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_HW_SLOT_COUNT = 15;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_PARTIAL_UPDATE_EXTENTS_BYTE_ALIGNMENT = 16;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_COUNT = 15;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_COMMONSHADER_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D12_COMMONSHADER_FLOWCONTROL_NESTING_LIMIT = 64;

        public const uint D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COMPONENTS = 4;

        public const uint D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_COUNT = 1;

        public const uint D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_COMMONSHADER_IMMEDIATE_CONSTANT_BUFFER_REGISTER_READ_PORTS = 1;

        public const uint D3D12_COMMONSHADER_IMMEDIATE_VALUE_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_COMPONENTS = 1;

        public const uint D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_COUNT = 128;

        public const uint D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_COMMONSHADER_INPUT_RESOURCE_REGISTER_READ_PORTS = 1;

        public const uint D3D12_COMMONSHADER_INPUT_RESOURCE_SLOT_COUNT = 128;

        public const uint D3D12_COMMONSHADER_SAMPLER_REGISTER_COMPONENTS = 1;

        public const uint D3D12_COMMONSHADER_SAMPLER_REGISTER_COUNT = 16;

        public const uint D3D12_COMMONSHADER_SAMPLER_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_COMMONSHADER_SAMPLER_REGISTER_READ_PORTS = 1;

        public const uint D3D12_COMMONSHADER_SAMPLER_SLOT_COUNT = 16;

        public const uint D3D12_COMMONSHADER_SUBROUTINE_NESTING_LIMIT = 32;

        public const uint D3D12_COMMONSHADER_TEMP_REGISTER_COMPONENTS = 4;

        public const uint D3D12_COMMONSHADER_TEMP_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_COMMONSHADER_TEMP_REGISTER_COUNT = 4096;

        public const uint D3D12_COMMONSHADER_TEMP_REGISTER_READS_PER_INST = 3;

        public const uint D3D12_COMMONSHADER_TEMP_REGISTER_READ_PORTS = 3;

        public const uint D3D12_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MAX = 10;

        public const int D3D12_COMMONSHADER_TEXCOORD_RANGE_REDUCTION_MIN = -10;

        public const int D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_NEGATIVE = -8;

        public const uint D3D12_COMMONSHADER_TEXEL_OFFSET_MAX_POSITIVE = 7;

        public const uint D3D12_CONSTANT_BUFFER_DATA_PLACEMENT_ALIGNMENT = 256;

        public const uint D3D12_CS_4_X_BUCKET00_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 256;

        public const uint D3D12_CS_4_X_BUCKET00_MAX_NUM_THREADS_PER_GROUP = 64;

        public const uint D3D12_CS_4_X_BUCKET01_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 240;

        public const uint D3D12_CS_4_X_BUCKET01_MAX_NUM_THREADS_PER_GROUP = 68;

        public const uint D3D12_CS_4_X_BUCKET02_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 224;

        public const uint D3D12_CS_4_X_BUCKET02_MAX_NUM_THREADS_PER_GROUP = 72;

        public const uint D3D12_CS_4_X_BUCKET03_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 208;

        public const uint D3D12_CS_4_X_BUCKET03_MAX_NUM_THREADS_PER_GROUP = 76;

        public const uint D3D12_CS_4_X_BUCKET04_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 192;

        public const uint D3D12_CS_4_X_BUCKET04_MAX_NUM_THREADS_PER_GROUP = 84;

        public const uint D3D12_CS_4_X_BUCKET05_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 176;

        public const uint D3D12_CS_4_X_BUCKET05_MAX_NUM_THREADS_PER_GROUP = 92;

        public const uint D3D12_CS_4_X_BUCKET06_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 160;

        public const uint D3D12_CS_4_X_BUCKET06_MAX_NUM_THREADS_PER_GROUP = 100;

        public const uint D3D12_CS_4_X_BUCKET07_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 144;

        public const uint D3D12_CS_4_X_BUCKET07_MAX_NUM_THREADS_PER_GROUP = 112;

        public const uint D3D12_CS_4_X_BUCKET08_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 128;

        public const uint D3D12_CS_4_X_BUCKET08_MAX_NUM_THREADS_PER_GROUP = 128;

        public const uint D3D12_CS_4_X_BUCKET09_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 112;

        public const uint D3D12_CS_4_X_BUCKET09_MAX_NUM_THREADS_PER_GROUP = 144;

        public const uint D3D12_CS_4_X_BUCKET10_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 96;

        public const uint D3D12_CS_4_X_BUCKET10_MAX_NUM_THREADS_PER_GROUP = 168;

        public const uint D3D12_CS_4_X_BUCKET11_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 80;

        public const uint D3D12_CS_4_X_BUCKET11_MAX_NUM_THREADS_PER_GROUP = 204;

        public const uint D3D12_CS_4_X_BUCKET12_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 64;

        public const uint D3D12_CS_4_X_BUCKET12_MAX_NUM_THREADS_PER_GROUP = 256;

        public const uint D3D12_CS_4_X_BUCKET13_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 48;

        public const uint D3D12_CS_4_X_BUCKET13_MAX_NUM_THREADS_PER_GROUP = 340;

        public const uint D3D12_CS_4_X_BUCKET14_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 32;

        public const uint D3D12_CS_4_X_BUCKET14_MAX_NUM_THREADS_PER_GROUP = 512;

        public const uint D3D12_CS_4_X_BUCKET15_MAX_BYTES_TGSM_WRITABLE_PER_THREAD = 16;

        public const uint D3D12_CS_4_X_BUCKET15_MAX_NUM_THREADS_PER_GROUP = 768;

        public const uint D3D12_CS_4_X_DISPATCH_MAX_THREAD_GROUPS_IN_Z_DIMENSION = 1;

        public const uint D3D12_CS_4_X_RAW_UAV_BYTE_ALIGNMENT = 256;

        public const uint D3D12_CS_4_X_THREAD_GROUP_MAX_THREADS_PER_GROUP = 768;

        public const uint D3D12_CS_4_X_THREAD_GROUP_MAX_X = 768;

        public const uint D3D12_CS_4_X_THREAD_GROUP_MAX_Y = 768;

        public const uint D3D12_CS_4_X_UAV_REGISTER_COUNT = 1;

        public const uint D3D12_CS_DISPATCH_MAX_THREAD_GROUPS_PER_DIMENSION = 65535;

        public const uint D3D12_CS_TGSM_REGISTER_COUNT = 8192;

        public const uint D3D12_CS_TGSM_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_CS_TGSM_RESOURCE_REGISTER_COMPONENTS = 1;

        public const uint D3D12_CS_TGSM_RESOURCE_REGISTER_READ_PORTS = 1;

        public const uint D3D12_CS_THREADGROUPID_REGISTER_COMPONENTS = 3;

        public const uint D3D12_CS_THREADGROUPID_REGISTER_COUNT = 1;

        public const uint D3D12_CS_THREADIDINGROUPFLATTENED_REGISTER_COMPONENTS = 1;

        public const uint D3D12_CS_THREADIDINGROUPFLATTENED_REGISTER_COUNT = 1;

        public const uint D3D12_CS_THREADIDINGROUP_REGISTER_COMPONENTS = 3;

        public const uint D3D12_CS_THREADIDINGROUP_REGISTER_COUNT = 1;

        public const uint D3D12_CS_THREADID_REGISTER_COMPONENTS = 3;

        public const uint D3D12_CS_THREADID_REGISTER_COUNT = 1;

        public const uint D3D12_CS_THREAD_GROUP_MAX_THREADS_PER_GROUP = 1024;

        public const uint D3D12_CS_THREAD_GROUP_MAX_X = 1024;

        public const uint D3D12_CS_THREAD_GROUP_MAX_Y = 1024;

        public const uint D3D12_CS_THREAD_GROUP_MAX_Z = 64;

        public const uint D3D12_CS_THREAD_GROUP_MIN_X = 1;

        public const uint D3D12_CS_THREAD_GROUP_MIN_Y = 1;

        public const uint D3D12_CS_THREAD_GROUP_MIN_Z = 1;

        public const uint D3D12_CS_THREAD_LOCAL_TEMP_REGISTER_POOL = 16384;

        public const float D3D12_DEFAULT_BLEND_FACTOR_ALPHA = 1.0f;

        public const float D3D12_DEFAULT_BLEND_FACTOR_BLUE = 1.0f;

        public const float D3D12_DEFAULT_BLEND_FACTOR_GREEN = 1.0f;

        public const float D3D12_DEFAULT_BLEND_FACTOR_RED = 1.0f;

        public const float D3D12_DEFAULT_BORDER_COLOR_COMPONENT = 0.0f;

        public const int D3D12_DEFAULT_DEPTH_BIAS = 0;

        public const float D3D12_DEFAULT_DEPTH_BIAS_CLAMP = 0.0f;

        public const uint D3D12_DEFAULT_MAX_ANISOTROPY = 16;

        public const float D3D12_DEFAULT_MIP_LOD_BIAS = 0.0f;

        public const uint D3D12_DEFAULT_MSAA_RESOURCE_PLACEMENT_ALIGNMENT = 4194304;

        public const uint D3D12_DEFAULT_RENDER_TARGET_ARRAY_INDEX = 0;

        public const uint D3D12_DEFAULT_RESOURCE_PLACEMENT_ALIGNMENT = 65536;

        public const uint D3D12_DEFAULT_SAMPLE_MASK = 0xFFFFFFFF;

        public const uint D3D12_DEFAULT_SCISSOR_ENDX = 0;

        public const uint D3D12_DEFAULT_SCISSOR_ENDY = 0;

        public const uint D3D12_DEFAULT_SCISSOR_STARTX = 0;

        public const uint D3D12_DEFAULT_SCISSOR_STARTY = 0;

        public const float D3D12_DEFAULT_SLOPE_SCALED_DEPTH_BIAS = 0.0f;

        public const uint D3D12_DEFAULT_STENCIL_READ_MASK = 0xFF;

        public const uint D3D12_DEFAULT_STENCIL_REFERENCE = 0;

        public const uint D3D12_DEFAULT_STENCIL_WRITE_MASK = 0xFF;

        public const uint D3D12_DEFAULT_VIEWPORT_AND_SCISSORRECT_INDEX = 0;

        public const uint D3D12_DEFAULT_VIEWPORT_HEIGHT = 0;

        public const float D3D12_DEFAULT_VIEWPORT_MAX_DEPTH = 0.0f;

        public const float D3D12_DEFAULT_VIEWPORT_MIN_DEPTH = 0.0f;

        public const uint D3D12_DEFAULT_VIEWPORT_TOPLEFTX = 0;

        public const uint D3D12_DEFAULT_VIEWPORT_TOPLEFTY = 0;

        public const uint D3D12_DEFAULT_VIEWPORT_WIDTH = 0;

        public const uint D3D12_DESCRIPTOR_RANGE_OFFSET_APPEND = 0xFFFFFFFF;

        public const uint D3D12_DRIVER_RESERVED_REGISTER_SPACE_VALUES_END = 0xFFFFFFF7;

        public const uint D3D12_DRIVER_RESERVED_REGISTER_SPACE_VALUES_START = 0xFFFFFFF0;

        public const uint D3D12_DS_INPUT_CONTROL_POINTS_MAX_TOTAL_SCALARS = 3968;

        public const uint D3D12_DS_INPUT_CONTROL_POINT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_DS_INPUT_CONTROL_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_DS_INPUT_CONTROL_POINT_REGISTER_COUNT = 32;

        public const uint D3D12_DS_INPUT_CONTROL_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_DS_INPUT_CONTROL_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_DS_INPUT_DOMAIN_POINT_REGISTER_COMPONENTS = 3;

        public const uint D3D12_DS_INPUT_DOMAIN_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_DS_INPUT_DOMAIN_POINT_REGISTER_COUNT = 1;

        public const uint D3D12_DS_INPUT_DOMAIN_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_DS_INPUT_DOMAIN_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_DS_INPUT_PATCH_CONSTANT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_DS_INPUT_PATCH_CONSTANT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_DS_INPUT_PATCH_CONSTANT_REGISTER_COUNT = 32;

        public const uint D3D12_DS_INPUT_PATCH_CONSTANT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_DS_INPUT_PATCH_CONSTANT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_DS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_DS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_DS_INPUT_PRIMITIVE_ID_REGISTER_COUNT = 1;

        public const uint D3D12_DS_INPUT_PRIMITIVE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_DS_INPUT_PRIMITIVE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D12_DS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_DS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_DS_OUTPUT_REGISTER_COUNT = 32;

        public const float D3D12_FLOAT16_FUSED_TOLERANCE_IN_ULP = 0.6f;

        public const float D3D12_FLOAT32_MAX = 3.402823466e+38f;

        public const float D3D12_FLOAT32_TO_INTEGER_TOLERANCE_IN_ULP = 0.6f;

        public const float D3D12_FLOAT_TO_SRGB_EXPONENT_DENOMINATOR = 2.4f;

        public const float D3D12_FLOAT_TO_SRGB_EXPONENT_NUMERATOR = 1.0f;

        public const float D3D12_FLOAT_TO_SRGB_OFFSET = 0.055f;

        public const float D3D12_FLOAT_TO_SRGB_SCALE_1 = 12.92f;

        public const float D3D12_FLOAT_TO_SRGB_SCALE_2 = 1.055f;

        public const float D3D12_FLOAT_TO_SRGB_THRESHOLD = 0.0031308f;

        public const float D3D12_FTOI_INSTRUCTION_MAX_INPUT = 2147483647.999f;

        public const float D3D12_FTOI_INSTRUCTION_MIN_INPUT = -2147483648.999f;

        public const float D3D12_FTOU_INSTRUCTION_MAX_INPUT = 4294967295.999f;

        public const float D3D12_FTOU_INSTRUCTION_MIN_INPUT = 0.0f;

        public const uint D3D12_GS_INPUT_INSTANCE_ID_READS_PER_INST = 2;

        public const uint D3D12_GS_INPUT_INSTANCE_ID_READ_PORTS = 1;

        public const uint D3D12_GS_INPUT_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_GS_INPUT_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_GS_INPUT_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D12_GS_INPUT_PRIM_CONST_REGISTER_COMPONENTS = 1;

        public const uint D3D12_GS_INPUT_PRIM_CONST_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_GS_INPUT_PRIM_CONST_REGISTER_COUNT = 1;

        public const uint D3D12_GS_INPUT_PRIM_CONST_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_GS_INPUT_PRIM_CONST_REGISTER_READ_PORTS = 1;

        public const uint D3D12_GS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_GS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_GS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D12_GS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_GS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_GS_INPUT_REGISTER_VERTICES = 32;

        public const uint D3D12_GS_MAX_INSTANCE_COUNT = 32;

        public const uint D3D12_GS_MAX_OUTPUT_VERTEX_COUNT_ACROSS_INSTANCES = 1024;

        public const uint D3D12_GS_OUTPUT_ELEMENTS = 32;

        public const uint D3D12_GS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_GS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_GS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D12_HS_CONTROL_POINT_PHASE_INPUT_REGISTER_COUNT = 32;

        public const uint D3D12_HS_CONTROL_POINT_PHASE_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D12_HS_CONTROL_POINT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_HS_CONTROL_POINT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_CONTROL_POINT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_CONTROL_POINT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_FORK_PHASE_INSTANCE_COUNT_UPPER_BOUND = 0xFFFFFFFF;

        public const uint D3D12_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_INPUT_FORK_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D12_HS_INPUT_FORK_INSTANCE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_INPUT_FORK_INSTANCE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_COUNT = 1;

        public const uint D3D12_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_INPUT_JOIN_INSTANCE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_HS_INPUT_PRIMITIVE_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_INPUT_PRIMITIVE_ID_REGISTER_COUNT = 1;

        public const uint D3D12_HS_INPUT_PRIMITIVE_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_INPUT_PRIMITIVE_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_JOIN_PHASE_INSTANCE_COUNT_UPPER_BOUND = 0xFFFFFFFF;

        public const float D3D12_HS_MAXTESSFACTOR_LOWER_BOUND = 1.0f;

        public const float D3D12_HS_MAXTESSFACTOR_UPPER_BOUND = 64.0f;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINTS_MAX_TOTAL_SCALARS = 3968;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COMPONENTS = 1;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_COUNT = 1;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_OUTPUT_CONTROL_POINT_ID_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_COUNT = 32;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_HS_OUTPUT_PATCH_CONSTANT_REGISTER_SCALAR_COMPONENTS = 128;

        public const uint D3D12_IA_DEFAULT_INDEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D12_IA_DEFAULT_PRIMITIVE_TOPOLOGY = 0;

        public const uint D3D12_IA_DEFAULT_VERTEX_BUFFER_OFFSET_IN_BYTES = 0;

        public const uint D3D12_IA_INDEX_INPUT_RESOURCE_SLOT_COUNT = 1;

        public const uint D3D12_IA_INSTANCE_ID_BIT_COUNT = 32;

        public const uint D3D12_IA_INTEGER_ARITHMETIC_BIT_COUNT = 32;

        public const uint D3D12_IA_PATCH_MAX_CONTROL_POINT_COUNT = 32;

        public const uint D3D12_IA_PRIMITIVE_ID_BIT_COUNT = 32;

        public const uint D3D12_IA_VERTEX_ID_BIT_COUNT = 32;

        public const uint D3D12_IA_VERTEX_INPUT_RESOURCE_SLOT_COUNT = 32;

        public const uint D3D12_IA_VERTEX_INPUT_STRUCTURE_ELEMENTS_COMPONENTS = 128;

        public const uint D3D12_IA_VERTEX_INPUT_STRUCTURE_ELEMENT_COUNT = 32;

        public const uint D3D12_INTEGER_DIVIDE_BY_ZERO_QUOTIENT = 0xFFFFFFFF;

        public const uint D3D12_INTEGER_DIVIDE_BY_ZERO_REMAINDER = 0xFFFFFFFF;

        public const uint D3D12_KEEP_RENDER_TARGETS_AND_DEPTH_STENCIL = 0xFFFFFFFF;

        public const uint D3D12_KEEP_UNORDERED_ACCESS_VIEWS = 0xFFFFFFFF;

        public const float D3D12_LINEAR_GAMMA = 1.0f;

        public const uint D3D12_MAJOR_VERSION = 12;

        public const float D3D12_MAX_BORDER_COLOR_COMPONENT = 1.0f;

        public const float D3D12_MAX_DEPTH = 1.0f;

        public const uint D3D12_MAX_LIVE_STATIC_SAMPLERS = 2032;

        public const uint D3D12_MAX_MAXANISOTROPY = 16;

        public const uint D3D12_MAX_MULTISAMPLE_SAMPLE_COUNT = 32;

        public const float D3D12_MAX_POSITION_VALUE = 3.402823466e+34f;

        public const uint D3D12_MAX_ROOT_COST = 64;

        public const uint D3D12_MAX_SHADER_VISIBLE_DESCRIPTOR_HEAP_SIZE_TIER_1 = 1000000;

        public const uint D3D12_MAX_SHADER_VISIBLE_DESCRIPTOR_HEAP_SIZE_TIER_2 = 1000000;

        public const uint D3D12_MAX_SHADER_VISIBLE_SAMPLER_HEAP_SIZE = 2048;

        public const uint D3D12_MAX_TEXTURE_DIMENSION_2_TO_EXP = 17;

        public const uint D3D12_MAX_VIEW_INSTANCE_COUNT = 4;

        public const uint D3D12_MINOR_VERSION = 0;

        public const float D3D12_MIN_BORDER_COLOR_COMPONENT = 0.0f;

        public const float D3D12_MIN_DEPTH = 0.0f;

        public const uint D3D12_MIN_MAXANISOTROPY = 0;

        public const float D3D12_MIP_LOD_BIAS_MAX = 15.99f;

        public const float D3D12_MIP_LOD_BIAS_MIN = -16.0f;

        public const uint D3D12_MIP_LOD_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D12_MIP_LOD_RANGE_BIT_COUNT = 8;

        public const float D3D12_MULTISAMPLE_ANTIALIAS_LINE_WIDTH = 1.4f;

        public const uint D3D12_NONSAMPLE_FETCH_OUT_OF_RANGE_ACCESS_RESULT = 0;

        public const uint D3D12_OS_RESERVED_REGISTER_SPACE_VALUES_END = 0xFFFFFFFF;

        public const uint D3D12_OS_RESERVED_REGISTER_SPACE_VALUES_START = 0xFFFFFFF8;

        public const uint D3D12_PACKED_TILE = 0xFFFFFFFF;

        public const uint D3D12_PIXEL_ADDRESS_RANGE_BIT_COUNT = 15;

        public const uint D3D12_PRE_SCISSOR_PIXEL_ADDRESS_RANGE_BIT_COUNT = 16;

        public const uint D3D12_PS_CS_UAV_REGISTER_COMPONENTS = 1;

        public const uint D3D12_PS_CS_UAV_REGISTER_COUNT = 8;

        public const uint D3D12_PS_CS_UAV_REGISTER_READS_PER_INST = 1;

        public const uint D3D12_PS_CS_UAV_REGISTER_READ_PORTS = 1;

        public const uint D3D12_PS_FRONTFACING_DEFAULT_VALUE = 0xFFFFFFFF;

        public const uint D3D12_PS_FRONTFACING_FALSE_VALUE = 0x00000000;

        public const uint D3D12_PS_FRONTFACING_TRUE_VALUE = 0xFFFFFFFF;

        public const uint D3D12_PS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_PS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_PS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D12_PS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_PS_INPUT_REGISTER_READ_PORTS = 1;

        public const float D3D12_PS_LEGACY_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.0f;

        public const uint D3D12_PS_OUTPUT_DEPTH_REGISTER_COMPONENTS = 1;

        public const uint D3D12_PS_OUTPUT_DEPTH_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_PS_OUTPUT_DEPTH_REGISTER_COUNT = 1;

        public const uint D3D12_PS_OUTPUT_MASK_REGISTER_COMPONENTS = 1;

        public const uint D3D12_PS_OUTPUT_MASK_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_PS_OUTPUT_MASK_REGISTER_COUNT = 1;

        public const uint D3D12_PS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_PS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_PS_OUTPUT_REGISTER_COUNT = 8;

        public const float D3D12_PS_PIXEL_CENTER_FRACTIONAL_COMPONENT = 0.5f;

        public const uint D3D12_RAW_UAV_SRV_BYTE_ALIGNMENT = 16;

        public const uint D3D12_RAYTRACING_AABB_BYTE_ALIGNMENT = 8;

        public const uint D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BYTE_ALIGNMENT = 256;

        public const uint D3D12_RAYTRACING_INSTANCE_DESCS_BYTE_ALIGNMENT = 16;

        public const uint D3D12_RAYTRACING_MAX_ATTRIBUTE_SIZE_IN_BYTES = 32;

        public const uint D3D12_RAYTRACING_MAX_DECLARABLE_TRACE_RECURSION_DEPTH = 31;

        public const uint D3D12_RAYTRACING_MAX_GEOMETRIES_PER_BOTTOM_LEVEL_ACCELERATION_STRUCTURE = 16777216;

        public const uint D3D12_RAYTRACING_MAX_INSTANCES_PER_TOP_LEVEL_ACCELERATION_STRUCTURE = 16777216;

        public const uint D3D12_RAYTRACING_MAX_PRIMITIVES_PER_BOTTOM_LEVEL_ACCELERATION_STRUCTURE = 536870912;

        public const uint D3D12_RAYTRACING_MAX_RAY_GENERATION_SHADER_THREADS = 1073741824;

        public const uint D3D12_RAYTRACING_MAX_SHADER_RECORD_STRIDE = 4096;

        public const uint D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT = 32;

        public const uint D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT = 64;

        public const uint D3D12_RAYTRACING_TRANSFORM3X4_BYTE_ALIGNMENT = 16;

        public const uint D3D12_REQ_BLEND_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D12_REQ_BUFFER_RESOURCE_TEXEL_COUNT_2_TO_EXP = 27;

        public const uint D3D12_REQ_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D12_REQ_DEPTH_STENCIL_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D12_REQ_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 32;

        public const uint D3D12_REQ_DRAW_VERTEX_COUNT_2_TO_EXP = 32;

        public const uint D3D12_REQ_FILTERING_HW_ADDRESSABLE_RESOURCE_DIMENSION = 16384;

        public const uint D3D12_REQ_GS_INVOCATION_32BIT_OUTPUT_COMPONENT_LIMIT = 1024;

        public const uint D3D12_REQ_IMMEDIATE_CONSTANT_BUFFER_ELEMENT_COUNT = 4096;

        public const uint D3D12_REQ_MAXANISOTROPY = 16;

        public const uint D3D12_REQ_MIP_LEVELS = 15;

        public const uint D3D12_REQ_MULTI_ELEMENT_STRUCTURE_SIZE_IN_BYTES = 2048;

        public const uint D3D12_REQ_RASTERIZER_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D12_REQ_RENDER_TO_BUFFER_WINDOW_WIDTH = 16384;

        public const uint D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_A_TERM = 128;

        public const float D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_B_TERM = 0.25f;

        public const uint D3D12_REQ_RESOURCE_SIZE_IN_MEGABYTES_EXPRESSION_C_TERM = 2048;

        public const uint D3D12_REQ_RESOURCE_VIEW_COUNT_PER_DEVICE_2_TO_EXP = 20;

        public const uint D3D12_REQ_SAMPLER_OBJECT_COUNT_PER_DEVICE = 4096;

        public const uint D3D12_REQ_SUBRESOURCES = 30720;

        public const uint D3D12_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION = 2048;

        public const uint D3D12_REQ_TEXTURE1D_U_DIMENSION = 16384;

        public const uint D3D12_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION = 2048;

        public const uint D3D12_REQ_TEXTURE2D_U_OR_V_DIMENSION = 16384;

        public const uint D3D12_REQ_TEXTURE3D_U_V_OR_W_DIMENSION = 2048;

        public const uint D3D12_REQ_TEXTURECUBE_DIMENSION = 16384;

        public const uint D3D12_RESINFO_INSTRUCTION_MISSING_COMPONENT_RETVAL = 0;

        public const uint D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES = 0xFFFFFFFF;

        public const uint D3D12_RS_SET_SHADING_RATE_COMBINER_COUNT = 2;

        public const uint D3D12_SHADER_IDENTIFIER_SIZE_IN_BYTES = 32;

        public const uint D3D12_SHADER_MAJOR_VERSION = 5;

        public const uint D3D12_SHADER_MAX_INSTANCES = 65535;

        public const uint D3D12_SHADER_MAX_INTERFACES = 253;

        public const uint D3D12_SHADER_MAX_INTERFACE_CALL_SITES = 4096;

        public const uint D3D12_SHADER_MAX_TYPES = 65535;

        public const uint D3D12_SHADER_MINOR_VERSION = 1;

        public const uint D3D12_SHIFT_INSTRUCTION_PAD_VALUE = 0;

        public const uint D3D12_SHIFT_INSTRUCTION_SHIFT_VALUE_BIT_COUNT = 5;

        public const uint D3D12_SIMULTANEOUS_RENDER_TARGET_COUNT = 8;

        public const uint D3D12_SMALL_MSAA_RESOURCE_PLACEMENT_ALIGNMENT = 65536;

        public const uint D3D12_SMALL_RESOURCE_PLACEMENT_ALIGNMENT = 4096;

        public const uint D3D12_SO_BUFFER_MAX_STRIDE_IN_BYTES = 2048;

        public const uint D3D12_SO_BUFFER_MAX_WRITE_WINDOW_IN_BYTES = 512;

        public const uint D3D12_SO_BUFFER_SLOT_COUNT = 4;

        public const uint D3D12_SO_DDI_REGISTER_INDEX_DENOTING_GAP = 0xFFFFFFFF;

        public const uint D3D12_SO_NO_RASTERIZED_STREAM = 0xFFFFFFFF;

        public const uint D3D12_SO_OUTPUT_COMPONENT_COUNT = 128;

        public const uint D3D12_SO_STREAM_COUNT = 4;

        public const uint D3D12_SPEC_DATE_DAY = 14;

        public const uint D3D12_SPEC_DATE_MONTH = 11;

        public const uint D3D12_SPEC_DATE_YEAR = 2014;

        public const float D3D12_SPEC_VERSION = 1.16f;

        public const float D3D12_SRGB_GAMMA = 2.2f;

        public const float D3D12_SRGB_TO_FLOAT_DENOMINATOR_1 = 12.92f;

        public const float D3D12_SRGB_TO_FLOAT_DENOMINATOR_2 = 1.055f;

        public const float D3D12_SRGB_TO_FLOAT_EXPONENT = 2.4f;

        public const float D3D12_SRGB_TO_FLOAT_OFFSET = 0.055f;

        public const float D3D12_SRGB_TO_FLOAT_THRESHOLD = 0.04045f;

        public const float D3D12_SRGB_TO_FLOAT_TOLERANCE_IN_ULP = 0.5f;

        public const uint D3D12_STANDARD_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_STANDARD_COMPONENT_BIT_COUNT_DOUBLED = 64;

        public const uint D3D12_STANDARD_MAXIMUM_ELEMENT_ALIGNMENT_BYTE_MULTIPLE = 4;

        public const uint D3D12_STANDARD_PIXEL_COMPONENT_COUNT = 128;

        public const uint D3D12_STANDARD_PIXEL_ELEMENT_COUNT = 32;

        public const uint D3D12_STANDARD_VECTOR_SIZE = 4;

        public const uint D3D12_STANDARD_VERTEX_ELEMENT_COUNT = 32;

        public const uint D3D12_STANDARD_VERTEX_TOTAL_COMPONENT_COUNT = 64;

        public const uint D3D12_SUBPIXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D12_SUBTEXEL_FRACTIONAL_BIT_COUNT = 8;

        public const uint D3D12_SYSTEM_RESERVED_REGISTER_SPACE_VALUES_END = 0xFFFFFFFF;

        public const uint D3D12_SYSTEM_RESERVED_REGISTER_SPACE_VALUES_START = 0xFFFFFFF0;

        public const uint D3D12_TESSELLATOR_MAX_EVEN_TESSELLATION_FACTOR = 64;

        public const uint D3D12_TESSELLATOR_MAX_ISOLINE_DENSITY_TESSELLATION_FACTOR = 64;

        public const uint D3D12_TESSELLATOR_MAX_ODD_TESSELLATION_FACTOR = 63;

        public const uint D3D12_TESSELLATOR_MAX_TESSELLATION_FACTOR = 64;

        public const uint D3D12_TESSELLATOR_MIN_EVEN_TESSELLATION_FACTOR = 2;

        public const uint D3D12_TESSELLATOR_MIN_ISOLINE_DENSITY_TESSELLATION_FACTOR = 1;

        public const uint D3D12_TESSELLATOR_MIN_ODD_TESSELLATION_FACTOR = 1;

        public const uint D3D12_TEXEL_ADDRESS_RANGE_BIT_COUNT = 16;

        public const uint D3D12_TEXTURE_DATA_PITCH_ALIGNMENT = 256;

        public const uint D3D12_TEXTURE_DATA_PLACEMENT_ALIGNMENT = 512;

        public const uint D3D12_TILED_RESOURCE_TILE_SIZE_IN_BYTES = 65536;

        public const uint D3D12_TRACKED_WORKLOAD_MAX_INSTANCES = 32;

        public const uint D3D12_UAV_COUNTER_PLACEMENT_ALIGNMENT = 4096;

        public const uint D3D12_UAV_SLOT_COUNT = 64;

        public const uint D3D12_UNBOUND_MEMORY_ACCESS_RESULT = 0;

        public const uint D3D12_VIDEO_DECODE_MAX_ARGUMENTS = 10;

        public const uint D3D12_VIDEO_DECODE_MAX_HISTOGRAM_COMPONENTS = 4;

        public const uint D3D12_VIDEO_DECODE_MIN_BITSTREAM_OFFSET_ALIGNMENT = 256;

        public const uint D3D12_VIDEO_DECODE_MIN_HISTOGRAM_OFFSET_ALIGNMENT = 256;

        public const uint D3D12_VIDEO_DECODE_STATUS_MACROBLOCKS_AFFECTED_UNKNOWN = 0xFFFFFFFF;

        public const uint D3D12_VIDEO_PROCESS_MAX_FILTERS = 32;

        public const uint D3D12_VIDEO_PROCESS_STEREO_VIEWS = 2;

        public const uint D3D12_VIEWPORT_AND_SCISSORRECT_MAX_INDEX = 15;

        public const uint D3D12_VIEWPORT_AND_SCISSORRECT_OBJECT_COUNT_PER_PIPELINE = 16;

        public const uint D3D12_VIEWPORT_BOUNDS_MAX = 32767;

        public const int D3D12_VIEWPORT_BOUNDS_MIN = -32768;

        public const uint D3D12_VS_INPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_VS_INPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_VS_INPUT_REGISTER_COUNT = 32;

        public const uint D3D12_VS_INPUT_REGISTER_READS_PER_INST = 2;

        public const uint D3D12_VS_INPUT_REGISTER_READ_PORTS = 1;

        public const uint D3D12_VS_OUTPUT_REGISTER_COMPONENTS = 4;

        public const uint D3D12_VS_OUTPUT_REGISTER_COMPONENT_BIT_COUNT = 32;

        public const uint D3D12_VS_OUTPUT_REGISTER_COUNT = 32;

        public const uint D3D12_WHQL_CONTEXT_COUNT_FOR_RESOURCE_LIMIT = 10;

        public const uint D3D12_WHQL_DRAWINDEXED_INDEX_COUNT_2_TO_EXP = 25;

        public const uint D3D12_WHQL_DRAW_VERTEX_COUNT_2_TO_EXP = 25;

        public const uint D3D12_SHADER_COMPONENT_MAPPING_MASK = 0x7;

        public const uint D3D12_SHADER_COMPONENT_MAPPING_SHIFT = 3;

        public const uint D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES = 1 << (unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT) * 4);

        public const uint D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING = 0x1688;

        public const uint D3D12_FILTER_REDUCTION_TYPE_MASK = 0x00000003;

        public const uint D3D12_FILTER_REDUCTION_TYPE_SHIFT = 7;

        public const uint D3D12_FILTER_TYPE_MASK = 0x00000003;

        public const uint D3D12_MIN_FILTER_SHIFT = 4;

        public const uint D3D12_MAG_FILTER_SHIFT = 2;

        public const uint D3D12_MIP_FILTER_SHIFT = 0;

        public const uint D3D12_ANISOTROPIC_FILTERING_BIT = 0x00000040;

        public const uint D3D12_SHADING_RATE_X_AXIS_SHIFT = 2;

        public const uint D3D12_SHADING_RATE_VALID_MASK = 3;

        public static uint D3D12_ENCODE_SHADER_4_COMPONENT_MAPPING(D3D12_SHADER_COMPONENT_MAPPING Src0, D3D12_SHADER_COMPONENT_MAPPING Src1, D3D12_SHADER_COMPONENT_MAPPING Src2, D3D12_SHADER_COMPONENT_MAPPING Src3)
        {
            return ((uint)Src0 & D3D12_SHADER_COMPONENT_MAPPING_MASK)
                | (((uint)Src1 & D3D12_SHADER_COMPONENT_MAPPING_MASK) << unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT))
                | (((uint)Src2 & D3D12_SHADER_COMPONENT_MAPPING_MASK) << (unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT) * 2))
                | (((uint)Src3 & D3D12_SHADER_COMPONENT_MAPPING_MASK) << (unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT) * 3))
                | D3D12_SHADER_COMPONENT_MAPPING_ALWAYS_SET_BIT_AVOIDING_ZEROMEM_MISTAKES;
        }

        public static D3D12_SHADER_COMPONENT_MAPPING D3D12_DECODE_SHADER_4_COMPONENT_MAPPING(int ComponentToExtract, uint Mapping) => (D3D12_SHADER_COMPONENT_MAPPING)((Mapping >> (unchecked((int)D3D12_SHADER_COMPONENT_MAPPING_SHIFT) * ComponentToExtract)) & D3D12_SHADER_COMPONENT_MAPPING_MASK);

        public static D3D12_FILTER D3D12_ENCODE_BASIC_FILTER(D3D12_FILTER_TYPE min, D3D12_FILTER_TYPE mag, D3D12_FILTER_TYPE mip, D3D12_FILTER_REDUCTION_TYPE reduction)
        {
            return (D3D12_FILTER)((((uint)min & D3D12_FILTER_TYPE_MASK) << unchecked((int)D3D12_MIN_FILTER_SHIFT))
                                | (((uint)mag & D3D12_FILTER_TYPE_MASK) << unchecked((int)D3D12_MAG_FILTER_SHIFT))
                                | (((uint)mip & D3D12_FILTER_TYPE_MASK) << unchecked((int)D3D12_MIP_FILTER_SHIFT))
                                | (((uint)reduction & D3D12_FILTER_REDUCTION_TYPE_MASK) << unchecked((int)D3D12_FILTER_REDUCTION_TYPE_SHIFT)));
        }

        public static D3D12_FILTER D3D12_ENCODE_ANISOTROPIC_FILTER(D3D12_FILTER_REDUCTION_TYPE reduction) => (D3D12_FILTER)(D3D12_ANISOTROPIC_FILTERING_BIT | (uint)D3D12_ENCODE_BASIC_FILTER(D3D12_FILTER_TYPE_LINEAR, D3D12_FILTER_TYPE_LINEAR, D3D12_FILTER_TYPE_LINEAR, reduction));

        public static D3D12_FILTER_TYPE D3D12_DECODE_MIN_FILTER(D3D12_FILTER D3D12Filter) => (D3D12_FILTER_TYPE)(((uint)D3D12Filter >> unchecked((int)D3D12_MIN_FILTER_SHIFT)) & D3D12_FILTER_TYPE_MASK);

        public static D3D12_FILTER_TYPE D3D12_DECODE_MAG_FILTER(D3D12_FILTER D3D12Filter) => (D3D12_FILTER_TYPE)(((uint)D3D12Filter >> unchecked((int)D3D12_MAG_FILTER_SHIFT)) & D3D12_FILTER_TYPE_MASK);

        public static D3D12_FILTER_TYPE D3D12_DECODE_MIP_FILTER(D3D12_FILTER D3D12Filter) => (D3D12_FILTER_TYPE)(((uint)D3D12Filter >> unchecked((int)D3D12_MIP_FILTER_SHIFT)) & D3D12_FILTER_TYPE_MASK);

        public static D3D12_FILTER_REDUCTION_TYPE D3D12_DECODE_FILTER_REDUCTION(D3D12_FILTER D3D12Filter) => (D3D12_FILTER_REDUCTION_TYPE)(((uint)D3D12Filter >> unchecked((int)D3D12_FILTER_REDUCTION_TYPE_SHIFT)) & D3D12_FILTER_REDUCTION_TYPE_MASK);

        public static bool D3D12_DECODE_IS_COMPARISON_FILTER(D3D12_FILTER D3D12Filter) => D3D12_DECODE_FILTER_REDUCTION(D3D12Filter) == D3D12_FILTER_REDUCTION_TYPE_COMPARISON;

        public static bool D3D12_DECODE_IS_ANISOTROPIC_FILTER(D3D12_FILTER D3D12Filter)
        {
            return (((uint)D3D12Filter & D3D12_ANISOTROPIC_FILTERING_BIT) != 0)
                && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIN_FILTER(D3D12Filter))
                && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MAG_FILTER(D3D12Filter))
                && (D3D12_FILTER_TYPE_LINEAR == D3D12_DECODE_MIP_FILTER(D3D12Filter));
        }

        public static uint D3D12_MAKE_COARSE_SHADING_RATE(uint x, uint y) => (x << unchecked((int)D3D12_SHADING_RATE_X_AXIS_SHIFT)) | y;

        public static uint D3D12_GET_COARSE_SHADING_RATE_X_AXIS(uint x) => (x >> unchecked((int)D3D12_SHADING_RATE_X_AXIS_SHIFT)) & D3D12_SHADING_RATE_VALID_MASK;

        public static uint D3D12_GET_COARSE_SHADING_RATE_Y_AXIS(uint y) => y & D3D12_SHADING_RATE_VALID_MASK;

        //public static int D3D12ReflectLibrary(void* pSrcData, UIntPtr SrcDataSize, ID3D12LibraryReflection** ppReflector)
        //{
        //    var iid = IID_ID3D12LibraryReflection;
        //    return D3DReflectLibrary(pSrcData, SrcDataSize, &iid, (void**)ppReflector);
        //}

        //public static int D3D_SET_OBJECT_NAME_N_A(ID3D12Object* pObject, uint Chars, sbyte* pName)
        //{
        //    var guid = WKPDID_D3DDebugObjectName;
        //    return pObject->SetPrivateData(&guid, Chars, pName);
        //}

        //public static int D3D_SET_OBJECT_NAME_A(ID3D12Object* pObject, sbyte* pName)
        //{
        //    return D3D_SET_OBJECT_NAME_N_A(pObject, (uint)lstrlenA(pName), pName);
        //}

        //public static int D3D_SET_OBJECT_NAME_N_W(ID3D12Object* pObject, uint Chars, ushort* pName)
        //{
        //    var guid = WKPDID_D3DDebugObjectNameW;
        //    return pObject->SetPrivateData(&guid, Chars * 2, pName);
        //}

        //public static int D3D_SET_OBJECT_NAME_W(ID3D12Object* pObject, ushort* pName)
        //{
        //    return D3D_SET_OBJECT_NAME_N_W(pObject, (uint)lstrlenW(pName), pName);
        //}
    }
}
