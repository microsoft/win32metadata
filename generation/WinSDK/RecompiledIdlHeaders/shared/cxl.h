/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    cxl.h

Abstract:

    CXL MMIO register definitions

Revision:

    Oct. 2024 - Align to CXL spec version 3.1.

--*/

#ifndef CXL_INCLUDED
#define CXL_INCLUDED

#include <winapifamily.h>

#pragma region Desktop Family or OneCore Package
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)


//
// Interface GUIDs
//
// need these GUIDs outside conditional includes so that user can
//   #include <cxl.h> in precompiled header
//   #include <initguid.h> in a single source file
//   #include <cxl.h> in that source file a second time to instantiate the GUIDs
//
// Note: GUIDs utilize little endian for the first 3 arguments 
// so the values need to be swapped from the big endian UUID definition
//

#ifdef DEFINE_GUID

//
// CXL Type 3 Log UUIDs and resulting GUIDs
//
DEFINE_GUID( /* 0da9c0b5-bf41-4b78-8f79-96b1623b3f17 */
    CxlType3CommandEffectsLog,
    0xb5c0a90d,
    0x41bf,
    0x784b,
    0x8f, 0x79, 0x96, 0xb1, 0x62, 0x3b, 0x3f, 0x17);

DEFINE_GUID( /* 5e1819d9-11a9-400c-811f-d60719403d86 */
    CxlType3VendorDebugLog,
    0xd919185e,
    0xa911,
    0x0c40,
    0x81, 0x1f, 0xd6, 0x07, 0x19, 0x40, 0x3d, 0x86);

DEFINE_GUID( /* b3fab4cf-01b6-4332-943e-5e9962f23567 */
    CxlType3ComponentStateDumpLog,
    0xcfb4fab3,
    0xb601,
    0x3243,
    0x94, 0x3e, 0x5e, 0x99, 0x62, 0xf2, 0x35, 0x67);

DEFINE_GUID( /* f1720d60-a7a9-4306-a003-11948f9e077c */
    CxlType3DDR5ErrorCheckScrubLog,
    0x600d72f1,
    0xa9a7,
    0x0643,
    0xa0, 0x03, 0x11, 0x94, 0x8f, 0x9e, 0x07, 0x7c);

DEFINE_GUID( /* e6dfa32c-d13e-4a5c-8ca8-99bebbf731a4 */
    CxlType3MediaTestCapabilityLog,
    0x2ca3dfe6,
    0x3ed1,
    0x5c4a,
    0x8c, 0xa8, 0x99, 0xbe, 0xbb, 0xf7, 0x31, 0xa4);

DEFINE_GUID( /* 2c255522-8ce4-11ec-b909-0242ac120002 */
    CxlType3MediaTestResultsShortLog,
    0x2255252c,
    0xe48c,
    0xec11,
    0xb9, 0x09, 0x02, 0x42, 0xac, 0x12, 0x00, 0x02);

DEFINE_GUID( /* c1fe0b3e-7a00-448e-a24e-a6aabbfe587a */
    CxlType3MediaTestResultsLongLog,
    0x3e0bfec1,
    0x007a,
    0x8e44,
    0xa2, 0x4e, 0xa6, 0xaa, 0xbb, 0xfe, 0x58, 0x7a);

//
// CXL Type 3 Event Record UUIDs and resulting GUIDs
//
DEFINE_GUID( /* fbcd0a77-c260-417f-85a9-088b1621eba6 */
    CxlType3EventRecord_GeneralMedia,
    0x770acdfb,
    0x60c2,
    0x7f41,
    0x85, 0xa9, 0x08, 0x8b, 0x16, 0x21, 0xeb, 0xa6);

DEFINE_GUID( /* 601dcbb3-9c06-4eab-b8af-4e9bfb5c9624 */
    CxlType3EventRecord_DRAM,
    0xb3cb1d60,
    0x069c,
    0xab4e,
    0xb8, 0xaf, 0x4e, 0x9b, 0xfb, 0x5c, 0x96, 0x24);

DEFINE_GUID( /* fe927475-dd59-4339-a586-79bab113b774 */
    CxlType3EventRecord_MemoryModule,
    0x757492fe,
    0x59dd,
    0x3943,
    0xa5, 0x86, 0x79, 0xba, 0xb1, 0x13, 0xb7, 0x74);

DEFINE_GUID( /* e71f3a40-2d29-4092-8a39-4d1c966c7c65 */
    CxlType3EventRecord_MemorySparing,
    0x403a1fe7,
    0x292d,
    0x9240,
    0x8a, 0x39, 0x4d, 0x1c, 0x96, 0x6c, 0x7c, 0x65);

DEFINE_GUID( /* ca95afa7-f183-4018-8c2f-95268e101a2a */
    CxlType3EventRecord_DynamicCapacity,
    0xa7af95ca,
    0x83f1,
    0x1840,
    0x8c, 0x2f, 0x95, 0x26, 0x8e, 0x10, 0x1a, 0x2a);

#endif // DEFINE_GUID


#if _MSC_VER >= 1200
#pragma once
#pragma warning(push)
#endif

#pragma warning(disable:4214)   // bit field types other than int
#pragma warning(disable:4201)   // nameless struct/union
#pragma warning(disable:4200)   // zero-sized array in struct/union



//
// CXL Registers definitions (CXL Spec V3.1)
//

#define CXL_COMPONENT_REGISTER_BLOCK_ID   1
#define CXL_DEVICE_REGISTER_BLOCK_ID      3
#define CXL_MEMORY_LOW_PART_MASK          0xF0000000


//
// CXL Component Registers V3.1
//

#define CXL_COMPONENT_REGISTER_SIZE         0x10000
#define CXL_CACHEMEM_PRIMARY_RANGE_OFFSET   0x1000

typedef enum _CXL_CACHEMEM_CAPABILITY_ID {
    CxlCacheMemCapabilityID_NullCapability = 0,
    CxlCacheMemCapabilityID_Capability = 1,
    CxlCacheMemCapabilityID_RASCapability,
    CxlCacheMemCapabilityID_SecurityCapability,
    CxlCacheMemCapabilityID_LinkCapability,
    CxlCacheMemCapabilityID_HDMDecoderCapability,
    CxlCacheMemCapabilityID_ExtendedSecurityCapability,
    CxlCacheMemCapabilityID_IDECapability,
    CxlCacheMemCapabilityID_SnoopFilterCapability,
    CxlCacheMemCapabilityID_TimeoutAndIsolationCapability,
    CxlCacheMemCapabilityID_ExtendedRegisterCapability,
    CxlCacheMemCapabilityID_BIRouteTableCapability,
    CxlCacheMemCapabilityID_BIDecoderCapability,
    CxlCacheMemCapabilityID_CacheIDRouteTableCapability,
    CxlCacheMemCapabilityID_CacheIDDecoderCapability,
    CxlCacheMemCapabilityID_ExtendedHDMDecoderCapability,
    CxlCacheMemCapabilityID_ExtendedMetadataCapability
} CXL_CACHEMEM_CAPABILITY_ID, *PCXL_CACHEMEM_CAPABILITY_ID;

typedef union _CXL_CAPABILITY_HEADER_REGISTER {
    struct {
        ULONG CxlCapabilityID : 16;
        ULONG CxlCapabilityVersion : 4;
        ULONG CxlCacheMemVersion : 4;
        ULONG ArraySize : 8;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_CAPABILITY_HEADER_REGISTER, *PCXL_CAPABILITY_HEADER_REGISTER;

typedef union _CXL_CACHEMEM_CAPABILITY_HEADER_REGISTER {
    struct {
        ULONG CxlCapabilityID : 16;
        ULONG CxlCapabilityVersion : 4;
        ULONG CapabilityOffset : 12;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_CACHEMEM_CAPABILITY_HEADER_REGISTER, *PCXL_CACHEMEM_CAPABILITY_HEADER_REGISTER;

typedef struct _CXL_CACHEMEM_REGISTERS {
    CXL_CAPABILITY_HEADER_REGISTER CapabilityHeaderRegister;
    CXL_CACHEMEM_CAPABILITY_HEADER_REGISTER CacheMemCapabilityHeaderRegister[ANYSIZE_ARRAY];
} CXL_CACHEMEM_REGISTERS, *PCXL_CACHEMEM_REGISTERS;

typedef enum _CXL_HDM_DECODER_COUNT {
    CxlHdmDecoderCount_1 = 0,
    CxlHdmDecoderCount_2,
    CxlHdmDecoderCount_4,
    CxlHdmDecoderCount_6,
    CxlHdmDecoderCount_8,
    CxlHdmDecoderCount_10,
    CxlHdmDecoderCount_12,
    CxlHdmDecoderCount_14,
    CxlHdmDecoderCount_16,
    CxlHdmDecoderCount_20,
    CxlHdmDecoderCount_24,
    CxlHdmDecoderCount_28,
    CxlHdmDecoderCount_32,

    CxlHdmDecoderCount_Max
} CXL_HDM_DECODER_COUNT, *PCXL_HDM_DECODER_COUNT;

typedef union _CXL_HDM_DECODER_CAPABILITY_REGISTER {
    struct {
        ULONG DecoderCount : 4;
        ULONG TargetCount : 4;
        ULONG A11to8InterleaveCapable : 1;
        ULONG A14to12InterleaveCapable: 1;
        ULONG PoisonOnDecodeErrorCapability : 1;
        ULONG InterleaveCapable_3_6_12Way : 1;
        ULONG InterleaveCapable_16Way : 1;
        ULONG UIOCapable : 1;

        ULONG Reserved : 2;

        ULONG UIOCapableDecoderCount : 4;
        ULONG MemDataNXMCapable : 1;
        ULONG SupportedCoherencyModels : 2;

        ULONG Reserved2 : 9;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_CAPABILITY_REGISTER, *PCXL_HDM_DECODER_CAPABILITY_REGISTER;

typedef union _CXL_HDM_DECODER_GLOBAL_CONTROL_REGISTER {
    struct {
        ULONG PoisonOnDecoderErrorEnable : 1;
        ULONG HDMDecoderEnable : 1;

        ULONG Reserved : 30;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_GLOBAL_CONTROL_REGISTER, *PCXL_HDM_DECODER_GLOBAL_CONTROL_REGISTER;

typedef union _CXL_HDM_MEMORY_BASE_LOW {
    struct {
        ULONG Reserved : 28;

        ULONG MemoryBaseLow : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_MEMORY_BASE_LOW, *PCXL_HDM_MEMORY_BASE_LOW;

typedef union _CXL_HDM_MEMORY_SIZE_LOW {
    struct {
        ULONG Reserved : 28;

        ULONG MemorySizeLow : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_MEMORY_SIZE_LOW, *PCXL_HDM_MEMORY_SIZE_LOW;

typedef enum _CXL_INTERLEAVE_WAYS {
    CxlInterleaveWays_1Way,
    CxlInterleaveWays_2Way,
    CxlInterleaveWays_4Way,
    CxlInterleaveWays_8Way,
    CxlInterleaveWays_16Way,
    CxlInterleaveWays_3Way = 0x8,
    CxlInterleaveWays_6Way = 0x9,
    CxlInterleaveWays_12Way = 0xA,

    CxlInterleaveWays_Max
} CXL_INTERLEAVE_WAYS, *PCXL_INTERLEAVE_WAYS;

typedef enum _CXL_INTERLEAVE_GRANULARITY {
    CxlInterleaveGranularity_256,
    CxlInterleaveGranularity_512,
    CxlInterleaveGranularity_1024,
    CxlInterleaveGranularity_2048,
    CxlInterleaveGranularity_4096,
    CxlInterleaveGranularity_8192,
    CxlInterleaveGranularity_16384,

    CxlInterleaveGranularity_Max
} CXL_INTERLEAVE_GRANULARITY, *PCXL_INTERLEAVE_GRANULARITY;

typedef union _CXL_HDM_DECODER_CONTROL_REGISTER {
    struct {
        ULONG InterleaveGranularity : 4;
        ULONG InterleaveWays : 4;
        ULONG LockOnCommit : 1;
        ULONG Commit : 1;
        ULONG Committed : 1;
        ULONG ErrorNotCommitted : 1;
        ULONG TargetRangeType : 1;
        ULONG BI : 1;
        ULONG UIO : 1;

        ULONG Reserved : 1;

        ULONG UpstreamInterleaveGranularity : 4;
        ULONG UpstreamInterleaveWays : 4;
        ULONG InterleaveSetPosition : 4;

        ULONG Reserved2 : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_CONTROL_REGISTER, *PCXL_HDM_DECODER_CONTROL_REGISTER;

typedef union _CXL_HDM_DECODER_DPA_SKIP_LOW_REGISTER {
    struct {
        ULONG Reserved : 28;

        ULONG DPASkipLow : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_DPA_SKIP_LOW_REGISTER, *PCXL_HDM_DECODER_DPA_SKIP_LOW_REGISTER;

typedef union _CXL_HDM_DECODER_TARGET_LIST_LOW_REGISTER {
    struct {
        ULONG TargetPortIdentifierForInterleaveWayIs0 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs1 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs2 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs3 : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_TARGET_LIST_LOW_REGISTER, *PCXL_HDM_DECODER_TARGET_LIST_LOW_REGISTER;

typedef union _CXL_HDM_DECODER_TARGET_LIST_HIGH_REGISTER {
    struct {
        ULONG TargetPortIdentifierForInterleaveWayIs4 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs5 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs6 : 4;
        ULONG TargetPortIdentifierForInterleaveWayIs7 : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_HDM_DECODER_TARGET_LIST_HIGH_REGISTER, *PCXL_HDM_DECODER_TARGET_LIST_HIGH_REGISTER;

typedef struct _CXL_HDM_DECODER_REGISTERS {
    CXL_HDM_MEMORY_BASE_LOW MemoryBaseLow;
    ULONG MemoryBaseHigh;
    CXL_HDM_MEMORY_SIZE_LOW MemorySizeLow;
    ULONG MemorySizeHigh;
    CXL_HDM_DECODER_CONTROL_REGISTER Control;

    union {
        CXL_HDM_DECODER_TARGET_LIST_LOW_REGISTER TargetListLow; // Not applicable to devices.
        CXL_HDM_DECODER_DPA_SKIP_LOW_REGISTER DpaSkipLow;       // Devices only.
    } u1;

    union {
        CXL_HDM_DECODER_TARGET_LIST_HIGH_REGISTER TargetListHigh;   // Not applicable to devices.
        ULONG DpaSkipHigh;                                          // Devices only.
    } u2;

    ULONG Reserved;
} CXL_HDM_DECODER_REGISTERS, *PCXL_HDM_DECODER_REGISTERS;

C_ASSERT(sizeof(CXL_HDM_DECODER_REGISTERS) == 0x20);

typedef struct _CXL_HDM_DECODER_CAPABILITY_STRUCTURE {
    CXL_HDM_DECODER_CAPABILITY_REGISTER CapabilityRegister;
    CXL_HDM_DECODER_GLOBAL_CONTROL_REGISTER GlobalControlRegister;

    ULONG Reserved[2];

    CXL_HDM_DECODER_REGISTERS Decoders[ANYSIZE_ARRAY];
} CXL_HDM_DECODER_CAPABILITY_STRUCTURE, *PCXL_HDM_DECODER_CAPABILITY_STRUCTURE;

typedef union _CXL_RAS_UNCORRECTABLE_ERROR_STATUS_REGISTER {
    struct {
        ULONG CacheDataParity : 1;
        ULONG CacheAddressParity : 1;
        ULONG CacheBeParity : 1;
        ULONG CacheDataEcc : 1;
        ULONG MemDataParity: 1;
        ULONG MemAddressParity : 1;
        ULONG MemBeParity : 1;
        ULONG MemDataEcc : 1;
        ULONG ReinitThreshold : 1;
        ULONG RsvdEncodingViolation : 1;
        ULONG PoisonReceived : 1;
        ULONG ReceiverOverflow : 1;
        ULONG Reserved : 2;
        ULONG InternalError : 1;
        ULONG CxlIdeTxError : 1;
        ULONG CxlIdeRxError : 1;
        ULONG ExtendedMetadataError : 1;
        ULONG Reserved2 : 14;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_UNCORRECTABLE_ERROR_STATUS_REGISTER, *PCXL_RAS_UNCORRECTABLE_ERROR_STATUS_REGISTER;

typedef union _CXL_RAS_UNCORRECTABLE_ERROR_MASK_REGISTER {
    struct {
        ULONG CacheDataParityMask : 1;
        ULONG CacheAddressParityMask : 1;
        ULONG CacheBeParityMask : 1;
        ULONG CacheDataEccMask : 1;
        ULONG MemDataParityMask: 1;
        ULONG MemAddressParityMask : 1;
        ULONG MemBeParityMask : 1;
        ULONG MemDataEccMask : 1;
        ULONG ReinitThresholdMask : 1;
        ULONG RsvdEncodingViolationMask : 1;
        ULONG PoisonReceivedMask : 1;
        ULONG ReceiverOverflowMask : 1;
        ULONG Reserved : 2;
        ULONG InternalErrorMask : 1;
        ULONG CxlIdeTxErrorMask : 1;
        ULONG CxlIdeRxErrorMask : 1;
        ULONG ExtendedMetadataErrorMask : 1;
        ULONG Reserved2 : 14;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_UNCORRECTABLE_ERROR_MASK_REGISTER, *PCXL_RAS_UNCORRECTABLE_ERROR_MASK_REGISTER;

typedef union _CXL_RAS_UNCORRECTABLE_ERROR_SEVERITY_REGISTER {
    struct {
        ULONG CacheDataParitySeverity : 1;
        ULONG CacheAddressParitySeverity : 1;
        ULONG CacheBeParitySeverity : 1;
        ULONG CacheDataEccSeverity : 1;
        ULONG MemDataParitySeverity: 1;
        ULONG MemAddressParitySeverity : 1;
        ULONG MemBeParitySeverity : 1;
        ULONG MemDataEccSeverity : 1;
        ULONG ReinitThresholdSeverity : 1;
        ULONG RsvdEncodingViolationSeverity : 1;
        ULONG PoisonReceivedSeverity : 1;
        ULONG ReceiverOverflowSeverity : 1;
        ULONG Reserved : 2;
        ULONG InternalErrorSeverity : 1;
        ULONG CxlIdeTxErrorSeverity : 1;
        ULONG CxlIdeRxErrorSeverity : 1;
        ULONG ExtendedMetadataErrorSeverity : 1;
        ULONG Reserved2 : 14;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_UNCORRECTABLE_ERROR_SEVERITY_REGISTER, *PCXL_RAS_UNCORRECTABLE_ERROR_SEVERITY_REGISTER;

typedef union _CXL_RAS_CORRECTABLE_ERROR_STATUS_REGISTER {
    struct {
        ULONG CacheDataEcc : 1;
        ULONG MemDataEcc : 1;
        ULONG CrcThreshold : 1;
        ULONG RetryThreshold : 1;
        ULONG CachePoisonReceived: 1;
        ULONG MemPoisonReceived : 1;
        ULONG PhysicalLayerError : 1;
        ULONG Reserved : 25;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_CORRECTABLE_ERROR_STATUS_REGISTER, *PCXL_RAS_CORRECTABLE_ERROR_STATUS_REGISTER;

typedef union _CXL_RAS_CORRECTABLE_ERROR_MASK_REGISTER {
    struct {
        ULONG CacheDataEccMask : 1;
        ULONG MemDataEccMask : 1;
        ULONG CrcThresholdMask : 1;
        ULONG RetryThresholdMask : 1;
        ULONG CachePoisonReceivedMask: 1;
        ULONG MemPoisonReceivedMask : 1;
        ULONG PhysicalLayerErrorMask : 1;
        ULONG Reserved : 25;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_CORRECTABLE_ERROR_MASK_REGISTER, *PCXL_RAS_CORRECTABLE_ERROR_MASK_REGISTER;

typedef union _CXL_RAS_ERROR_CAPABILITY_AND_CONTROL_REGISTER {
    struct {
        ULONG FirstErrorPointer : 6;
        ULONG Reserved : 3;
        ULONG MultipleHeaderRecordingCapability : 1;
        ULONG Reserved2 : 3;
        ULONG PoisonEnabled: 1;
        ULONG Reserved3 : 18;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_RAS_ERROR_CAPABILITY_AND_CONTROL_REGISTER, *PCXL_RAS_ERROR_CAPABILITY_AND_CONTROL_REGISTER;

typedef struct _CXL_RAS_HEADER_LOG_REGISTERS {
    ULONG HeaderLogArray[16];
} CXL_RAS_HEADER_LOG_REGISTERS, *PCXL_RAS_HEADER_LOG_REGISTERS;

typedef struct _CXL_RAS_CAPABILITY_STRUCTURE {
    CXL_RAS_UNCORRECTABLE_ERROR_STATUS_REGISTER UncorrectableErrorStatusRegister;
    CXL_RAS_UNCORRECTABLE_ERROR_MASK_REGISTER UncorrectableErrorMaskRegister;
    CXL_RAS_UNCORRECTABLE_ERROR_SEVERITY_REGISTER UncorrectableErrorSeverityRegister;
    CXL_RAS_CORRECTABLE_ERROR_STATUS_REGISTER CorrectableErrorStatusRegister;
    CXL_RAS_CORRECTABLE_ERROR_MASK_REGISTER CorrectableErrorMaskRegister;
    CXL_RAS_ERROR_CAPABILITY_AND_CONTROL_REGISTER ErrorCapabilityAndControlRegister;
    CXL_RAS_HEADER_LOG_REGISTERS HeaderLogRegisters;
} CXL_RAS_CAPABILITY_STRUCTURE, *PCXL_RAS_CAPABILITY_STRUCTURE;

//
// CXL Device Registers V3.1
//

typedef enum _CXL_DEVICE_CAPABILITY_ARRAY_TYPE {
    CxlDeviceCapabilityArrayType_InferredFromPciClassCode,
    CxlDeviceCapabilityArrayType_MemoryDeviceCapabilities,
    CxlDeviceCapabilityArrayType_SwitchMailboxCCICapabilities,

    CxlDeviceCapabilityArrayType_Max
} CXL_DEVICE_CAPABILITY_ARRAY_TYPE, *PCXL_DEVICE_CAPABILITY_ARRAY_TYPE;

typedef enum _CXL_DEVICE_CAPABILITY_ID {
    CxlDeviceCapabilityID_CapabilityArray = 0,
    CxlDeviceCapabilityID_DeviceStatusRegisters = 1,
    CxlDeviceCapabilityID_PrimaryMailboxRegisters,
    CxlDeviceCapabilityID_SecondaryMailboxRegisters,

    CxlDeviceCapabilityID_MemoryDeviceStatusRegisters = 0x4000
} CXL_DEVICE_CAPABILITY_ID, *PCXL_DEVICE_CAPABILITY_ID;

//
// Device Capabilities Array Register
// Offset Device Registers Offset + 00h
//
typedef union _CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER_HEADER {
    struct {
        ULONG CapabilityID : 16;
        ULONG Version : 8;
        ULONG Type : 4;
        ULONG Reserved : 4;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER_HEADER, *PCXL_DEVICE_CAPABILITIES_ARRAY_REGISTER_HEADER;

typedef struct _CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER {
    CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER_HEADER Header;
    USHORT CapabilitiesCount;

    USHORT Reserved;
    ULONG Reserved1[2];
} CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER, *PCXL_DEVICE_CAPABILITIES_ARRAY_REGISTER;

C_ASSERT(sizeof(CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER) == 16);

typedef union _CXL_DEVICE_CAPABILITY_HEADER_REGISTER_HEADER {
    struct {
        ULONG CapabilityID : 16;
        ULONG Version : 8;
        ULONG Reserved : 8;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_DEVICE_CAPABILITY_HEADER_REGISTER_HEADER, *PCXL_DEVICE_CAPABILITY_HEADER_REGISTER_HEADER;

//
// Device Capability Header Register
//
typedef struct _CXL_DEVICE_CAPABILITY_HEADER_REGISTER {
    CXL_DEVICE_CAPABILITY_HEADER_REGISTER_HEADER Header;
    ULONG Offset;
    ULONG Length;
    ULONG Reserved;
} CXL_DEVICE_CAPABILITY_HEADER_REGISTER, *PCXL_DEVICE_CAPABILITY_HEADER_REGISTER;

C_ASSERT(sizeof(CXL_DEVICE_CAPABILITY_HEADER_REGISTER) == 16);

typedef struct _CXL_DEVICE_REGISTERS {
    CXL_DEVICE_CAPABILITIES_ARRAY_REGISTER CapabilityArrayRegister;
    CXL_DEVICE_CAPABILITY_HEADER_REGISTER CapabilityHeaderRegister[ANYSIZE_ARRAY];
} CXL_DEVICE_REGISTERS, *PCXL_DEVICE_REGISTERS;

//
// CXL Device Status Registers
//

//
// Event Status Register
// Offset Device Status Register Capability Offset + 00h
//
typedef union _CXL_EVENT_STATUS_REGISTER {
    struct {
        ULONGLONG InformationalEventLog : 1;
        ULONGLONG WarningEventLog : 1;
        ULONGLONG FailureEventLog : 1;
        ULONGLONG FatalEventLog : 1;
        ULONGLONG DynamicCapacityEventLog : 1;

        ULONGLONG Reserved : 59;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_EVENT_STATUS_REGISTER, *PCXL_EVENT_STATUS_REGISTER;

typedef struct _CXL_DEVICE_STATUS_REGISTERS {

    CXL_EVENT_STATUS_REGISTER EventStatusRegister;

} CXL_DEVICE_STATUS_REGISTERS, *PCXL_DEVICE_STATUS_REGISTERS;

//
// Mailbox Registers
//

//
// CXL mailbox command timeout is 2 seconds.
// Commands that require a longer execution time shall be completed asynchronously in the background.
//
#define CXL_MAILBOX_COMMAND_TIMEOUT_IN_SEC  2

typedef enum _CXL_MAILBOX_CAPABILITY_TYPE {
    CxlMailboxCapabilityType_InferredFromPciClassCode,
    CxlMailboxCapabilityType_MemoryDeviceCommands,
    CxlMailboxCapabilityType_FMApiCommands,

    CxlMailboxCapabilityType_Max
} CXL_MAILBOX_CAPABILITY_TYPE, *PCXL_MAILBOX_CAPABILITY_TYPE;

//
// Mailbox Capabilities Register
// Offset Mailbox Registers Capability Offset + 00h
//
typedef union _CXL_MAILBOX_CAPABILITY_REGISTER {
    struct {
        ULONG PayloadSize : 5;              // 2 ^ N
        ULONG MBDoorbellInterruptCapable : 1;
        ULONG BackgroundCommandCompleteInterruptCapable : 1;
        ULONG InterruptMessageNumber : 4;
        ULONG MailboxReadyTime : 8;         // In seconds.
        ULONG Type : 4;

        ULONG Reserved : 9;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_MAILBOX_CAPABILITY_REGISTER, *PCXL_MAILBOX_CAPABILITY_REGISTER;

//
// Mailbox Control Register
// Offset Mailbox Registers Capability Offset + 04h
//
typedef union _CXL_MAILBOX_CONTROL_REGISTER {
    struct {
        ULONG Doorbell : 1;
        ULONG MBDoorbellInterrupt : 1;
        ULONG BackgroundCommandCompleteInterrupt : 1;

        ULONG Reserved : 29;
    } DUMMYSTRUCTNAME;

    ULONG AsUlong;
} CXL_MAILBOX_CONTROL_REGISTER, *PCXL_MAILBOX_CONTROL_REGISTER;

//
// Command Register
// Offset Mailbox Registers Capability Offset + 08h
//
typedef union _CXL_COMMAND_REGISTER {
    struct {
        ULONGLONG CommandOpcode : 16;
        ULONGLONG PayloadLength : 21;

        ULONGLONG Reserved : 27;
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;
} CXL_COMMAND_REGISTER, *PCXL_COMMAND_REGISTER;

typedef enum _CXL_COMMAND_RETURN_CODE {
    CxlCommandReturnCode_Success = 0x0000,
    CxlCommandReturnCode_BackgroundCommandStarted,
    CxlCommandReturnCode_InvalidInput,
    CxlCommandReturnCode_Unsupported,
    CxlCommandReturnCode_InternalError,
    CxlCommandReturnCode_RetryRequired,
    CxlCommandReturnCode_Busy,
    CxlCommandReturnCode_MediaDisabled,
    CxlCommandReturnCode_FWTransferInProgress,
    CxlCommandReturnCode_FWTransferOutOfOrder,
    CxlCommandReturnCode_FWVerificationFailed,
    CxlCommandReturnCode_InvalidSlot,
    CxlCommandReturnCode_ActivationFailed_FWRolledBack,
    CxlCommandReturnCode_ActivationFailed_ColdResetRequired,
    CxlCommandReturnCode_InvalidHandle,
    CxlCommandReturnCode_InvalidPhysicalAddress,
    CxlCommandReturnCode_InjectPoisonLimitReached,
    CxlCommandReturnCode_PermanentMediaFailure,
    CxlCommandReturnCode_Aborted,
    CxlCommandReturnCode_InvalidSecurityState,
    CxlCommandReturnCode_IncorrectPassphrase,
    CxlCommandReturnCode_UnsupportedMailboxOrCCI,
    CxlCommandReturnCode_InvalidPayloadLength,
    CxlCommandReturnCode_InvalidLog,
    CxlCommandReturnCode_Interrupted,
    CxlCommandReturnCode_UnsupportedFeatureVersion,
    CxlCommandReturnCode_UnsupportedFeatureSelectionValue,
    CxlCommandReturnCode_FeatureTransferInProgress,
    CxlCommandReturnCode_FeatureTransferOutOfOrder,
    CxlCommandReturnCode_ResourcesExhausted,
    CxlCommandReturnCode_InvalidExtentList,
    CxlCommandReturnCode_TransferOutOfOrder,
    CxlCommandReturnCode_RequestAbortNotSupportedByBackgroundOperation,

    CxlCommandReturnCode_Max
} CXL_COMMAND_RETURN_CODE, *PCXL_COMMAND_RETURN_CODE;

C_ASSERT(CxlCommandReturnCode_Max == 0x0021);

//
// Mailbox Status Register
// Offset Mailbox Registers Capability Offset + 10h
//
typedef union _CXL_MAILBOX_STATUS_REGISTER {
    struct {
        ULONGLONG BackgroundOperation : 1;

        ULONGLONG Reserved : 31;

        ULONGLONG ReturnCode : 16;
        ULONGLONG VendorSpecificExtendedStatus : 16;
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;
} CXL_MAILBOX_STATUS_REGISTER, *PCXL_MAILBOX_STATUS_REGISTER;

//
// Background Command Status Register
// Offset Mailbox Registers Capability Offset + 18h
//
typedef union _CXL_BACKGROUND_COMMAND_STATUS_REGISTER {
    struct {
        ULONGLONG CommandOpcode : 16;
        ULONGLONG PercentageComplete : 7;

        ULONGLONG Reserved : 9;

        ULONGLONG ReturnCode : 16;
        ULONGLONG VendorSpecificExtendedStatus : 16;
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;
} CXL_BACKGROUND_COMMAND_STATUS_REGISTER, *PCXL_BACKGROUND_COMMAND_STATUS_REGISTER;

//
// Command Payload Registers
// Offset Mailbox Registers Capability Offset + 20h
//
typedef struct _CXL_COMMAND_PAYLOAD_REGISTERS {
    ULONG Payload[ANYSIZE_ARRAY];
} CXL_COMMAND_PAYLOAD_REGISTERS, *PCXL_COMMAND_PAYLOAD_REGISTERS;

typedef struct _CXL_MAILBOX_REGISTERS {
    CXL_MAILBOX_CAPABILITY_REGISTER CapabilityRegister;
    CXL_MAILBOX_CONTROL_REGISTER ControlRegister;
    CXL_COMMAND_REGISTER CommandRegister;
    CXL_MAILBOX_STATUS_REGISTER StatusRegister;
    CXL_BACKGROUND_COMMAND_STATUS_REGISTER BackgroundCommandStatusRegister;
    CXL_COMMAND_PAYLOAD_REGISTERS PayloadRegisters;
} CXL_MAILBOX_REGISTERS, *PCXL_MAILBOX_REGISTERS;

//
// Memory Device Status Registers
//

typedef enum _CXL_MEMORY_DEVICE_MEDIA_STATUS {
    CxlMemoryDeviceMediaStatus_NotReady,
    CxlMemoryDeviceMediaStatus_Ready,
    CxlMemoryDeviceMediaStatus_Error,
    CxlMemoryDeviceMediaStatus_Disabled,

    CxlMemoryDeviceMediaStatus_Max
} CXL_MEMORY_DEVICE_MEDIA_STATUS, *PCXL_MEMORY_DEVICE_MEDIA_STATUS;

//
// Memory Device Status Register
// Offset Memory Device Status Registers Capability Offset + 00h
//
typedef union _CXL_MEMORY_DEVICE_STATUS_REGISTER {
    struct {
        ULONGLONG DeviceFatal : 1;
        ULONGLONG FwHalt : 1;
        ULONGLONG MediaStatus : 2;
        ULONGLONG MailboxInterfacesReady : 1;
        ULONGLONG ResetNeeded : 3;

        ULONGLONG Reserved : 56;
    } DUMMYSTRUCTNAME;

    ULONGLONG AsUlonglong;
} CXL_MEMORY_DEVICE_STATUS_REGISTER, *PCXL_MEMORY_DEVICE_STATUS_REGISTER;

typedef struct _CXL_MEMORY_DEVICE_STATUS_REGISTERS {
    CXL_MEMORY_DEVICE_STATUS_REGISTER MemoryDeviceStatusRegister;
} CXL_MEMORY_DEVICE_STATUS_REGISTERS, *PCXL_MEMORY_DEVICE_STATUS_REGISTERS;

//
// CXL Mailbox Commands
//

typedef enum _CXL_MAILBOX_COMMAND {

    //
    // Generic CXL Component commands (0000h - 3FFFh)
    //

    //
    // Information and Status
    //
    CxlMailboxCommand_Identify                          = 0x0001,
    CxlMailboxCommand_BackgroundOperationStatus         = 0x0002,
    CxlMailboxCommand_GetResponseMessageLimit           = 0x0003,
    CxlMailboxCommand_SetResponseMessageLimit           = 0x0004,
    CxlMailboxCommand_RequestAbortBackgroundOperation   = 0x0005,

    //
    // Events
    //
    CxlMailboxCommand_GetEventRecords                   = 0x0100,
    CxlMailboxCommand_ClearEventRecords                 = 0x0101,
    CxlMailboxCommand_GetEventInterruptPolicy           = 0x0102,
    CxlMailboxCommand_SetEventInterruptPolicy           = 0x0103,
    CxlMailboxCommand_GetMCTPEventInterruptPolicy       = 0x0104,
    CxlMailboxCommand_SetMCTPEventInterruptPolicy       = 0x0105,
    CxlMailboxCommand_EventNotification                 = 0x0106,
    CxlMailboxCommand_GFDEnhancedEventNotification      = 0x0107,
    CxlMailboxCommand_GFDtoGAEEnhancedEventNotification = 0x0108,
    CxlMailboxCommand_GetGAMBuffer                      = 0x0109,
    CxlMailboxCommand_SetGAMBuffer                      = 0x010A,

    //
    // Firmware Update
    //
    CxlMailboxCommand_GetFWInfo     = 0x0200,
    CxlMailboxCommand_TransferFW    = 0x0201,
    CxlMailboxCommand_ActivateFW    = 0x0202,

    //
    // Timestamp
    //
    CxlMailboxCommand_GetTimestamp  = 0x0300,
    CxlMailboxCommand_SetTimestamp  = 0x0301,

    //
    // Logs
    //
    CxlMailboxCommand_GetSupportedLogs          = 0x0400,
    CxlMailboxCommand_GetLog                    = 0x0401,
    CxlMailboxCommand_GetLogCapabilities        = 0x0402,
    CxlMailboxCommand_ClearLog                  = 0x0403,
    CxlMailboxCommand_PopulateLog               = 0x0404,
    CxlMailboxCommand_GetSupportedLogSubList    = 0x0405,

    //
    // Features
    //
    CxlMailboxCommand_GetSupportedFeatures  = 0x0500,
    CxlMailboxCommand_GetFeature            = 0x0501,
    CxlMailboxCommand_SetFeature            = 0x0502,

    //
    // Maintenance
    //
    CxlMailboxCommand_PerformMaintenance    = 0x0600,

    //
    // PBR Components
    //
    CxlMailboxCommand_IdentifyPBRComponent  = 0x0700,
    CxlMailboxCommand_ClaimOwnership        = 0x0701,
    CxlMailboxCommand_ReadCDAT              = 0x0702,

    //
    // CXL Type specific commands (4000h - BFFFh)
    //

    //
    // CXL Memory Device commands
    //

    //
    // Identify Memory Device
    //
    CxlMailboxCommand_IdentifyMemoryDevice  = 0x4000,

    //
    // Capacity Config and Label Storage
    //
    CxlMailboxCommand_GetPartitionInfo  = 0x4100,
    CxlMailboxCommand_SetPartitionInfo  = 0x4101,
    CxlMailboxCommand_GetLSA            = 0x4102,
    CxlMailboxCommand_SetLSA            = 0x4103,

    //
    // Health Info and Alerts
    //
    CxlMailboxCommand_GetHealthInfo             = 0x4200,
    CxlMailboxCommand_GetAlertConfiguration     = 0x4201,
    CxlMailboxCommand_SetAlertConfiguration     = 0x4202,
    CxlMailboxCommand_GetShutdownState          = 0x4203,
    CxlMailboxCommand_SetShutdownState          = 0x4204,

    //
    // Media and Poison Management
    //
    CxlMailboxCommand_GetPoisonList             = 0x4300,
    CxlMailboxCommand_InjectPoison              = 0x4301,
    CxlMailboxCommand_ClearPoison               = 0x4302,
    CxlMailboxCommand_GetScanMediaCapabilities  = 0x4303,
    CxlMailboxCommand_ScanMedia                 = 0x4304,
    CxlMailboxCommand_GetScanMediaResults       = 0x4305,

    //
    // Sanitize and Media Operations
    //
    CxlMailboxCommand_Sanitize          = 0x4400,
    CxlMailboxCommand_SecureErase       = 0x4401,
    CxlMailboxCommand_MediaOperations   = 0x4402,

    //
    // Persistent Memory Data-at-rest Security
    //
    CxlMailboxCommand_GetSecurityState          = 0x4500,
    CxlMailboxCommand_SetPassphrase             = 0x4501,
    CxlMailboxCommand_DisablePassphrase         = 0x4502,
    CxlMailboxCommand_Unlock                    = 0x4503,
    CxlMailboxCommand_FreezeSecurityState       = 0x4504,
    CxlMailboxCommand_passphraseSecureErase     = 0x4505,

    //
    // Security Passthrough
    //
    CxlMailboxCommand_SecuritySend      = 0x4600,
    CxlMailboxCommand_SecurityReceive   = 0x4601,

    //
    // SLD QoS Telemetry
    //
    CxlMailboxCommand_GetSLDQoSControl  = 0x4700,
    CxlMailboxCommand_SetSLDQoSControl  = 0x4701,
    CxlMailboxCommand_GetSLDQoSStatus   = 0x4702,

    //
    // Dynamic Capacity
    //
    CxlMailboxCommand_GetDynamicCapacityConfiguration   = 0x4800,
    CxlMailboxCommand_GetDynamicCapacityExtentList      = 0x4801,
    CxlMailboxCommand_AddDynamicCapacityResponse        = 0x4802,
    CxlMailboxCommand_ReleaseDynamicCapacity            = 0x4803,

    //
    // GFD Component Management
    //
    CxlMailboxCommand_IdentifyGFD                           = 0x4900,
    CxlMailboxCommand_GetGFDStatus                          = 0x4901,
    CxlMailboxCommand_GetGFDDcRegionConfiguration           = 0x4902,
    CxlMailboxCommand_SetGFDDcRegionConfiguration           = 0x4903,
    CxlMailboxCommand_GetGFDDcRegionExtentLists             = 0x4904,
    CxlMailboxCommand_GetGFDDmpConfiguration                = 0x4905,
    CxlMailboxCommand_SetGFDDmpConfiguration                = 0x4906,
    CxlMailboxCommand_GFDDynamicCapacityAdd                 = 0x4907,
    CxlMailboxCommand_GFDDynamicCapacityRelease             = 0x4908,
    CxlMailboxCommand_GFDDynamicCapacityAddReference        = 0x4909,
    CxlMailboxCommand_GFDDynamicCapacityRemoveReference     = 0x490A,
    CxlMailboxCommand_GFDDynamicCapacityListTags            = 0x490B,
    CxlMailboxCommand_GetGFDSatEntry                        = 0x490C,
    CxlMailboxCommand_SetGFDSatEntry                        = 0x490D,
    CxlMailboxCommand_GetGFDQoSControl                      = 0x490E,
    CxlMailboxCommand_SetGFDQoSControl                      = 0x490F,
    CxlMailboxCommand_GetGFDQoSStatus                       = 0x4910,
    CxlMailboxCommand_GetGFDQoSBWLimit                      = 0x4911,
    CxlMailboxCommand_SetGFDQoSBWLimit                      = 0x4912,
    CxlMailboxCommand_GetGDTConfiguration                   = 0x4913,
    CxlMailboxCommand_SetGDTConfiguration                   = 0x4914,

    //
    // CXL Vendor specific commands (C000h - FFFFh)
    //

} CXL_MAILBOX_COMMAND, *PCXL_MAILBOX_COMMAND;

//
// Mailbox Command Payloads
//

#define CXL_FIRMWARE_REVISION_LENGTH    16

//
// Output buffer for command IdentifyMemoryDevice.
//
typedef struct _CXL_MAILBOX_MEMORY_DEVICE_IDENTIFY_INFO {
    CHAR FWRevision[CXL_FIRMWARE_REVISION_LENGTH];
    UCHAR TotalCapacity[8];
    UCHAR VolatileOnlyCapacity[8];
    UCHAR PersistentOnlyCapacity[8];
    UCHAR PartitionAlignment[8];
    UCHAR InformationEventLogSize[2];
    UCHAR WarningEventLogSize[2];
    UCHAR FailureEventLogSize[2];
    UCHAR FatalEventLogSize[2];
    UCHAR LSASize[4];
    UCHAR PoisonListMaximumMediaErrorRecords[3];
    UCHAR InjectPoisonLimit[2];

    struct {
        UCHAR InjectsPersistentPoison : 1;
        UCHAR ScansForPoison : 1;

        UCHAR Reserved : 6;
    } PoisonHandlingCapabilities;

    struct {
        UCHAR EgressPortCongestionSupported : 1;
        UCHAR TemporaryThroughputReductionSupported : 1;

        UCHAR Reserved : 6;
    } QoSTelemetryCapabilities;

    UCHAR DynamicCapacityEventLogSize[2];

    UCHAR Reserved[3];  // Padding (not in spec)
} CXL_MAILBOX_MEMORY_DEVICE_IDENTIFY_INFO, *PCXL_MAILBOX_MEMORY_DEVICE_IDENTIFY_INFO;

C_ASSERT(sizeof(CXL_MAILBOX_MEMORY_DEVICE_IDENTIFY_INFO) == 72);

#define CXL_MAXIMUM_FIRMWARE_SLOTS  4

//
// Output buffer for command GetFWInfo
//
typedef struct _CXL_MAILBOX_FIRMWARE_INFO {
    UCHAR FWSlotsSupported;
    struct {
        UCHAR ActiveFWSlotNumber : 3;
        UCHAR StagedFWSlotNumber : 3;

        UCHAR Reserved : 2;
    } FWSlotInfo;
    struct {
        UCHAR OnlineFWActivation : 1;

        UCHAR Reserved2 : 7;
    } FWActivationCapabilities;

    UCHAR Reserved3[13];

    CHAR SlotFWRevisions[CXL_MAXIMUM_FIRMWARE_SLOTS][CXL_FIRMWARE_REVISION_LENGTH];
} CXL_MAILBOX_FIRMWARE_INFO, *PCXL_MAILBOX_FIRMWARE_INFO;

C_ASSERT(sizeof(CXL_MAILBOX_FIRMWARE_INFO) == 80);

//
// Input buffer for command TransferFW
//

typedef enum _CXL_MAILBOX_TRANSFER_FIRMWARE_ACTION {
    CxlMailboxTransferFWAction_FullFWTransfer = 0,
    CxlMailboxTransferFWAction_InitiateFWTransfer,
    CxlMailboxTransferFWAction_ContinueFWTransfer,
    CxlMailboxTransferFWAction_EndTransfer,
    CxlMailboxTransferFWAction_AbortTransfer,

    CxlMailboxTransferFWAction_Max
} CXL_MAILBOX_TRANSFER_FIRMWARE_ACTION, *PCXL_MAILBOX_TRANSFER_FIRMWARE_ACTION;

typedef struct _CXL_MAILBOX_TRANSFER_FIRMWARE {
    UCHAR Action;
    UCHAR Slot;

    USHORT Reserved;

    //
    // Expressed in multiples of 128 bytes.
    //
    ULONG Offset;

    UCHAR Reserved2[120];

    UCHAR Data[ANYSIZE_ARRAY];  // The FW package data.
} CXL_MAILBOX_TRANSFER_FIRMWARE, *PCXL_MAILBOX_TRANSFER_FIRMWARE;

typedef enum _CXL_MAILBOX_ACTIVATE_FIRMWARE_ACTION {
    CxlMailboxActivateFWAction_Online = 0,
    CxlMailboxActivateFWAction_OnNextReset,

    CxlMailboxActivateFWAction_Max
} CXL_MAILBOX_ACTIVATE_FIRMWARE_ACTION, *PCXL_MAILBOX_ACTIVATE_FIRMWARE_ACTION;

//
// Input buffer for command ActivateFW
//

typedef struct _CXL_MAILBOX_ACTIVATE_FIRMWARE {
    UCHAR Action;
    UCHAR Slot;
} CXL_MAILBOX_ACTIVATE_FIRMWARE, *PCXL_MAILBOX_ACTIVATE_FIRMWARE;


typedef struct _CXL_MAILBOX_SUPPORTED_LOG_ENTRY {
    GUID LogIdentifier;
    ULONG LogSize;      // Maximum number of bytes of log data available to retrieve.
} CXL_MAILBOX_SUPPORTED_LOG_ENTRY, *PCXL_MAILBOX_SUPPORTED_LOG_ENTRY;

//
// Output buffer for command GetSupportedLogs
//
typedef struct _CXL_MAILBOX_GET_SUPPORTED_LOGS {
    USHORT NumberOfSupportedLogsEntries;

    UCHAR Reserved[6];

    _Field_size_(NumberOfSupportedLogsEntries) CXL_MAILBOX_SUPPORTED_LOG_ENTRY SupportedLogEntries[ANYSIZE_ARRAY];
} CXL_MAILBOX_GET_SUPPORTED_LOGS, *PCXL_MAILBOX_GET_SUPPORTED_LOGS;

//
// Input Buffer for command GetLogCapabilities
//
typedef struct _CXL_MAILBOX_GET_LOG_CAPABILITIES_INPUT {
    GUID LogIdentifier;
} CXL_MAILBOX_GET_LOG_CAPABILITIES_INPUT, *PCXL_MAILBOX_GET_LOG_CAPABILITIES_INPUT;

//
// Output Buffer for command GetLogCapabilities
//
typedef struct _CXL_MAILBOX_GET_LOG_CAPABILITIES_OUTPUT {
    ULONG ClearLogSupported : 1;
    ULONG PopulateLogSupported : 1;
    ULONG AutoPopulateSupported : 1;
    ULONG PersistentAcrossColdReset : 1;

    ULONG Reserved : 28;
} CXL_MAILBOX_GET_LOG_CAPABILITIES_OUTPUT, *PCXL_MAILBOX_GET_LOG_CAPABILITIES_OUTPUT;

//
// Input buffer for command GetLog
//
typedef struct _CXL_MAILBOX_GET_LOG_INPUT {
    GUID LogIdentifier;
    ULONG Offset;
    ULONG Length;
} CXL_MAILBOX_GET_LOG_INPUT, *PCXL_MAILBOX_GET_LOG_INPUT;

//
// Output buffers for command GetLog
//

//
// Command Effects Log (CEL)
//

typedef struct _CXL_MAILBOX_CEL_ENTRY {
    USHORT Opcode;
    struct {
        USHORT ConfigurationChangeAfterColdReset : 1;
        USHORT ImmediateConfigurationChange : 1;
        USHORT ImmediateDataChange : 1;
        USHORT ImmediatePolicyChange : 1;
        USHORT SecurityStateChange : 1;
        USHORT BackgroundOperation : 1;
        USHORT SecondaryMailboxSupported : 1;
        USHORT RequestAbortBackgroundOperationSupported : 1;
        USHORT CEL1110Valid : 1;
        USHORT ConfigurationChangeAfterConventionalReset : 1;
        USHORT ConfigurationChangeAfterCXLReset : 1;

        USHORT Reserved : 4;
    } CommandEffect;
} CXL_MAILBOX_CEL_ENTRY, *PCXL_MAILBOX_CEL_ENTRY;

typedef struct _CXL_MAILBOX_CEL_LOG {
    CXL_MAILBOX_CEL_ENTRY LogEntry[ANYSIZE_ARRAY];
} CXL_MAILBOX_CEL_LOG, *PCXL_MAILBOX_CEL_LOG;

typedef enum _CXL_EVENT_RECORD_SEVERITY {
    CxlEventRecordSeverity_Informational,
    CxlEventRecordSeverity_Warning,
    CxlEventRecordSeverity_Failure,
    CxlEventRecordSeverity_Fatal,

    CxlEventRecordSeverity_Max
} CXL_EVENT_RECORD_SEVERITY, *PCXL_EVENT_RECORD_SEVERITY;

//
// Output buffer for command GetEventInterruptPolicy
// Input buffer for SetEventInterruptPolicy
//
typedef enum _CXL_MAILBOX_INTERRUPT_POLICY_MODE {
    CxlMailboxInterruptPolicyMode_NoInterrupts = 0,
    CxlMailboxInterruptPolicyMode_MsiMsiX,
    CxlMailboxInterruptPolicyMode_FwInterrupt,
    CxlMailboxInterruptPolicyMode_Reserved
} CXL_MAILBOX_INTERRUPT_POLICY_MODE, *PCXL_MAILBOX_INTERRUPT_POLICY_MODE;

typedef struct _CXL_INTERRUPT_POLICY {
    UCHAR InterruptMode : 2; // CXL_MAILBOX_INTERRUPT_POLICY_MODE
    UCHAR Reserved : 2;
    UCHAR InterruptMessageNumber : 4;
} CXL_INTERRUPT_POLICY, *PCXL_INTERRUPT_POLICY;

//
// CXL 3.0 version
//
typedef struct _CXL_MAILBOX_INTERRUPT_POLICY {
    CXL_INTERRUPT_POLICY InformationalEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY WarningEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY FailureEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY FatalEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY DynamicCapacityEventLogInterruptSettings;
} CXL_MAILBOX_INTERRUPT_POLICY, *PCXL_MAILBOX_INTERRUPT_POLICY;
C_ASSERT(sizeof(CXL_MAILBOX_INTERRUPT_POLICY) == 0x05);

//
// CXL 2.0 version
//
typedef struct _CXL_MAILBOX_INTERRUPT_POLICY_2_0 {
    CXL_INTERRUPT_POLICY InformationalEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY WarningEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY FailureEventLogInterruptSettings;
    CXL_INTERRUPT_POLICY FatalEventLogInterruptSettings;
} CXL_MAILBOX_INTERRUPT_POLICY_2_0, *PCXL_MAILBOX_INTERRUPT_POLICY_2_0;
C_ASSERT(sizeof(CXL_MAILBOX_INTERRUPT_POLICY_2_0) == 0x04);

//
// Device DPA is always 64B aligned so lower 6 bits are always 0.
//
#define CXL_DPA_ADDRESS_MASK 0xFFFFFFFFFFFFFFC0

//
// Input buffer for InjectPoison and ClearPoison
//
typedef struct _CXL_MAILBOX_INJECT_POISON_INPUT {
    ULONGLONG InjectPoisonPhysicalAddress;
} CXL_MAILBOX_INJECT_POISON_INPUT, *PCXL_MAILBOX_INJECT_POISON_INPUT;
C_ASSERT(sizeof(CXL_MAILBOX_INJECT_POISON_INPUT) == 0x08);

#define CXL_CLEAR_POISON_WRITE_DATA_SIZE 64

typedef struct _CXL_MAILBOX_CLEAR_POISON_INPUT {
    ULONGLONG ClearPoisonPhysicalAddress;
    UCHAR ClearPoisonWriteData[CXL_CLEAR_POISON_WRITE_DATA_SIZE];
} CXL_MAILBOX_CLEAR_POISON_INPUT, *PCXL_MAILBOX_CLEAR_POISON_INPUT;
C_ASSERT(sizeof(CXL_MAILBOX_CLEAR_POISON_INPUT) == 0x48);

#pragma pack(push, 1)

//
// Input buffer for GetPoisonList
// 
typedef struct _CXL_MAILBOX_GET_POISON_LIST_INPUT {
    ULONGLONG RestartRequest : 1;
    ULONGLONG Reserved : 5;
    ULONGLONG PhysicalAddress : 58;

    ULONGLONG PhysicalAddressLength;
} CXL_MAILBOX_GET_POISON_LIST_INPUT, *PCXL_MAILBOX_GET_POISON_LIST_INPUT;
C_ASSERT(sizeof(CXL_MAILBOX_GET_POISON_LIST_INPUT) == 0x10);

//
// Output buffer for GetPoisonList
// 
typedef enum _CXL_MAILBOX_MEDIA_ERROR_RECORD_SOURCE {
    CxlMailboxErrorRecordSource_Unknown = 0,
    CxlMailboxErrorRecordSource_External,
    CxlMailboxErrorRecordSource_Internal,
    CxlMailboxErrorRecordSource_Injected,
    CxlMailboxErrorRecordSource_VendorSpecific,

    CxlMailboxErrorRecordSource_Max
} CXL_MAILBOX_MEDIA_ERROR_RECORD_SOURCE, *PCXL_MAILBOX_MEDIA_ERROR_RECORD_SOURCE;

typedef struct _CXL_MAILBOX_MEDIA_ERROR_RECORD {
    ULONGLONG ErrorSource : 3; // CXL_MAILBOX_MEDIA_ERROR_RECORD_SOURCE
    ULONGLONG Reserved : 3;
    ULONGLONG MediaErrorAddress : 58;

    ULONG MediaErrorLength;

    UCHAR Reserved1[4];
} CXL_MAILBOX_MEDIA_ERROR_RECORD, *PCXL_MAILBOX_MEDIA_ERROR_RECORD;
C_ASSERT(sizeof(CXL_MAILBOX_MEDIA_ERROR_RECORD) == 0x10);

typedef struct _CXL_MAILBOX_GET_POISON_LIST_OUTPUT {
    struct {
        UCHAR MoreMediaErrorRecords : 1;
        UCHAR PoisonListOverflow : 1;
        UCHAR ScanMediaInProgress : 1;
        UCHAR RestartAck : 1;

        UCHAR Reserved : 4;
    } PoisonListFlags;

    UCHAR Reserved;

    ULONGLONG OverflowTimestamp;
    USHORT MediaErrorRecordCount;

    UCHAR Reserved1[0x14];

    _Field_size_(MediaErrorRecordCount) CXL_MAILBOX_MEDIA_ERROR_RECORD MediaErrorRecords[ANYSIZE_ARRAY];
} CXL_MAILBOX_GET_POISON_LIST_OUTPUT, *PCXL_MAILBOX_GET_POISON_LIST_OUTPUT;

//
// CXL Common Event Record
//
typedef struct _CXL_COMMON_EVENT_RECORD_HEADER {
    GUID EventRecordIdentifier;
    UCHAR EventRecordLength;

    union {
        struct {
            USHORT EventRecordSeverity : 2;
            USHORT PermanentCondition : 1;
            USHORT MaintenanceNeeded : 1;
            USHORT PerformanceDegraded : 1;
            USHORT HardwareReplacementNeeded : 1;
            USHORT MaintenanceOperationSubclassValid : 1;
            USHORT LdIdValid : 1;
            USHORT HeadIdValid : 1;

            USHORT Reserved : 7;
        } bits;
        USHORT AsUshort;
    } EventRecordFlags;

    UCHAR Reserved;
    USHORT EventRecordHandle;
    USHORT RelatedEventRecordHandle;
    ULONGLONG EventRecordTimestamp;
    UCHAR MaintenanceOperationClass;
    UCHAR MaintenanceOperationSubclass;
    USHORT LdId;  // CXL 3.2
    UCHAR HeadId; // CXL 3.2
    UCHAR Reserved1[0xB];
} CXL_COMMON_EVENT_RECORD_HEADER, *PCXL_COMMON_EVENT_RECORD_HEADER;
C_ASSERT(sizeof(CXL_COMMON_EVENT_RECORD_HEADER) == 0x30);

typedef struct _CXL_COMMON_EVENT_RECORD {
    CXL_COMMON_EVENT_RECORD_HEADER Header;
    UCHAR EventRecordData[0x50];
} CXL_COMMON_EVENT_RECORD, *PCXL_COMMON_EVENT_RECORD;
C_ASSERT(sizeof(CXL_COMMON_EVENT_RECORD) == 0x80);

//
// General Media Event Record
//
typedef enum _CXL_TRANSACTION_TYPE {
    CxlTransactionType_Unknown = 0,
    CxlTransactionType_HostRead,
    CxlTransactionType_HostWrite,
    CxlTransactionType_HostScanMedia,
    CxlTransactionType_HostInjectPoison,
    CxlTransactionType_MediaPatrolScrub,
    CxlTransactionType_MediaManagement,
    CxlTransactionType_InternalMediaCheckScrub,
    CxlTransactionType_MediaInitialization
} CXL_TRANSACTION_TYPE, *PCXL_TRANSACTION_TYPE;

typedef enum _CXL_MEMORY_EVENT_SUBTYPE {
    CxlMemoryEventSubtype_NotReported = 0,
    CxlMemoryEventSubtype_InternalDatapathError,
    CxlMemoryEventSubtype_MediaLinkCommandTrainingError,
    CxlMemoryEventSubtype_MediaLinkDataTrainingError,
    CxlMemoryEventSubtype_MediaLinkCrcError
} CXL_MEMORY_EVENT_SUBTYPE, *PCXL_MEMORY_EVENT_SUBTYPE;

typedef enum _CXL_GENERAL_MEDIA_EVENT_TYPE {
    CxlGeneralMediaEventType_MediaEccError = 0,
    CxlGeneralMediaEventType_InvAddress,
    CxlGeneralMediaEventType_DataPathError,
    CxlGeneralMediaEventType_TeStateViolation,
    CxlGeneralMediaEventType_ScrubMediaEccError,
    CxlGeneralMediaEventType_AdvProgCorrMemErrCounterExp,
    CxlGeneralMediaEventType_CkidViolation
} CXL_GENERAL_MEDIA_EVENT_TYPE, *PCXL_GENERAL_MEDIA_EVENT_TYPE;

typedef struct _CXL_GENERAL_MEDIA_EVENT_RECORD {
    CXL_COMMON_EVENT_RECORD_HEADER Header;

    struct {
        ULONGLONG Volatile : 1;
        ULONGLONG DpaNotRepairable : 1;
        ULONGLONG Reserved : 4;
        ULONGLONG Dpa : 58;
    } PhysicalAddress;

    struct {
        UCHAR UncorrectableEvent : 1;
        UCHAR ThresholdEvent : 1;
        UCHAR PoisonListOverflow : 1;

        UCHAR Reserved : 5;
    } MemoryEventDescriptor;

    UCHAR MemoryEventType; // CXL_GENERAL_MEDIA_EVENT_TYPE
    UCHAR TransactionType; // CXL_TRANSACTION_TYPE

    struct {
        USHORT Channel : 1;
        USHORT Rank : 1;
        USHORT Device : 1;
        USHORT ComponentIdentifier : 1;
        USHORT ComponentIdentifierFormat : 1;

        USHORT Reserved : 11;
    } ValidityFlags;

    UCHAR Channel;
    UCHAR Rank;
    UCHAR Device[3];
    UCHAR ComponentIdentifier[0x10];

    struct {
        UCHAR MoreThanOneComponent : 1;
        UCHAR ProgrammableThresholdExceeded : 1;

        UCHAR Reserved : 6;
    } AdvProgCorrMemErrThresholdEventFlags;

    UCHAR CorrectedMemoryCountAtEvent[3];
    UCHAR MemoryEventSubType; // CXL_MEMORY_EVENT_SUBTYPE

    UCHAR Reserved[0x29];
} CXL_GENERAL_MEDIA_EVENT_RECORD, *PCXL_GENERAL_MEDIA_EVENT_RECORD;
C_ASSERT(sizeof(CXL_GENERAL_MEDIA_EVENT_RECORD) == 0x80);

//
// DRAM Event Record
//
typedef enum _CXL_DRAM_EVENT_TYPE {
    CxlDRAMEventType_MediaEccError = 0,
    CxlDRAMEventType_ScrubMediaEccError,
    CxlDRAMEventType_InvAddress,
    CxlDRAMEventType_DataPathError,
    CxlDRAMEventType_TeStateViolation,
    CxlDRAMEventType_AdvProgCorrMemErrCounterExp,
    CxlDRAMEventType_CkidViolation
} CXL_DRAM_EVENT_TYPE, *PCXL_DRAM_EVENT_TYPE;

typedef struct _CXL_DRAM_EVENT_RECORD {
    CXL_COMMON_EVENT_RECORD_HEADER Header;

    struct {
        ULONGLONG Volatile : 1;
        ULONGLONG DpaNotRepairable : 1;
        ULONGLONG Reserved : 4;
        ULONGLONG Dpa : 58;
    } PhysicalAddress;

    struct {
        UCHAR UncorrectableEvent : 1;
        UCHAR ThresholdEvent : 1;
        UCHAR PoisonListOverflow : 1;

        UCHAR Reserved : 5;
    } MemoryEventDescriptor;

    UCHAR MemoryEventType; // CXL_DRAM_EVENT_TYPE
    UCHAR TransactionType; // CXL_TRANSACTION_TYPE

    struct {
        USHORT Channel : 1;
        USHORT Rank : 1;
        USHORT NibbleMask : 1;
        USHORT BankGroup : 1;
        USHORT Bank : 1;
        USHORT Row : 1;
        USHORT Column : 1;
        USHORT CorrectionMask : 1;
        USHORT ComponentIdentifier : 1;
        USHORT ComponentIdentifierFormat : 1;
        USHORT Subchannel : 1;

        USHORT Reserved : 5;
    } ValidityFlags;

    UCHAR Channel;
    UCHAR Rank;
    UCHAR NibbleMask[3];
    UCHAR BankGroup;
    UCHAR Bank;
    UCHAR Row[3];
    UCHAR Column[2];
    UCHAR CorrectionMask[0x20];
    UCHAR ComponentIdentifier[0x10];
    UCHAR SubChannel;

    struct {
        UCHAR MoreThanOneComponent : 1;
        UCHAR ProgrammableThresholdExceeded : 1;

        UCHAR Reserved : 6;
    } AdvProgCorrMemErrThresholdEventFlags;

    UCHAR CVMECountAtEvent[3];
    UCHAR MemoryEventSubType; // CXL_MEMORY_EVENT_SUBTYPE
    UCHAR Reserved;
} CXL_DRAM_EVENT_RECORD, *PCXL_DRAM_EVENT_RECORD;
C_ASSERT(sizeof(CXL_DRAM_EVENT_RECORD) == 0x80);

//
// Device Health Information
//
typedef enum _CXL_MEDIA_STATUS {
    CxlMediaStatus_Normal = 0,
    CxlMediaStatus_NotReady,
    CxlMediaStatus_WritePersistencyLost,
    CxlMediaStatus_AllDataLost,
    CxlMediaStatus_WritePersistencyLossPowerLoss,
    CxlMediaStatus_WritePersistencyLossShutdown,
    CxlMediaStatus_WritePersistencyLossImminent,
    CxlMediaStatus_AllDataLossPowerLoss,
    CxlMediaStatus_AllDataLossShutdown,
    CxlMediaStatus_AllDataLossImminent
} CXL_MEDIA_STATUS, *PCXL_MEDIA_STATUS;

typedef enum _CXL_ADDITIONAL_HEALTH_STATUS {
    CxlAdditionalHealthStatus_Normal = 0,
    CxlAdditionalHealthStatus_Warning,
    CxlAdditionalHealthStatus_Critical
} CXL_ADDITIONAL_HEALTH_STATUS, *PCXL_ADDITIONAL_HEALTH_STATUS;

typedef struct _CXL_DEVICE_HEALTH_INFO {

    union {
        struct {
            UCHAR MaintenanceNeeded : 1;
            UCHAR PerformanceDegraded : 1;
            UCHAR HardwareReplacementNeeded : 1;
            UCHAR MemoryCapacityDegraded : 1;

            UCHAR Reserved : 4;
        } bits;
        UCHAR AsUchar;
    } HealthStatus; 

    UCHAR MediaStatus; // CXL_MEDIA_STATUS

    union {
        struct {
            UCHAR LifeUsed : 2; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR DeviceTemperature : 2; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR CorrectedVolatileErrorCount : 1; // CXL_ADDITIONAL_HEALTH_STATUS
            UCHAR CorrectedPersistentErrorCount : 1; // CXL_ADDITIONAL_HEALTH_STATUS

            UCHAR Reserved : 2;
        } bits;
        UCHAR AsUchar;   
    } AdditionalStatus; 

    UCHAR LifeUsed;
    USHORT DeviceTemperature;
    ULONG DirtyShutdownCount;
    ULONG CorrectedVolatileErrorCount;
    ULONG CorrectedPersistentErrorCount;
} CXL_DEVICE_HEALTH_INFO, *PCXL_DEVICE_HEALTH_INFO;
C_ASSERT(sizeof(CXL_DEVICE_HEALTH_INFO) == 0x12);

//
// Memory module event record
//
typedef enum _CXL_DEVICE_EVENT_TYPE {
    CxlDeviceEventType_HealthStatusChange = 0,
    CxlDeviceEventType_MediaStatusChange,
    CxlDeviceEventType_LifeUsedChange,
    CxlDeviceEventType_TemperatureChange,
    CxlDeviceEventType_DataPathError,
    CxlDeviceEventType_LsaError,
    CxlDeviceEventType_UnrecorverableInternalSideBandBusError,
    CxlDeviceEventType_MemoryMediaFruError,
    CxlDeviceEventType_PowerManagementFault
} CXL_DEVICE_EVENT_TYPE, *PCXL_DEVICE_EVENT_TYPE;

typedef enum _CXL_DEVICE_EVENT_SUBTYPE {
    CxlDeviceEventSubtype_NotReported = 0,
    CxlDeviceEventSubtype_InvalidConfigurationData,
    CxlDeviceEventSubtype_UnsupportedConfigurationData,
    CxlDeviceEventSubtype_UnsuportedMemoryMediaFru
} CXL_DEVICE_EVENT_SUBTYPE, *PCXL_DEVICE_EVENT_SUBTYPE;

typedef struct _CXL_MEMORY_MODULE_EVENT_RECORD {
    CXL_COMMON_EVENT_RECORD_HEADER Header;
    UCHAR DeviceEventType; // CXL_DEVICE_EVENT_TYPE
    CXL_DEVICE_HEALTH_INFO DeviceHealthInfo;

    struct {
        USHORT ComponentIdentifier : 1;
        USHORT ComponentIdentifierFormat : 1;

        USHORT Reserved : 14;
    } ValidityFlags;

    UCHAR ComponentIdentifier[0x10];
    UCHAR DeviceEventSubtype; // CXL_DEVICE_EVENT_SUBTYPE
    UCHAR Reserved[0x2A];
} CXL_MEMORY_MODULE_EVENT_RECORD, *PCXL_MEMORY_MODULE_EVENT_RECORD;
C_ASSERT(sizeof(CXL_MEMORY_MODULE_EVENT_RECORD) == 0x80);

//
// Memory Sparing Event Record
//
typedef enum _CXL_SPARING_RESULT {
    CxlSparingResult_Success = 0,
    CxlSparingResult_ResourcesExhausted,
    CxlSparingResult_GeneralFailure = 0xFF
} CXL_SPARING_RESULT, *PCXL_SPARING_RESULT;

typedef enum _CXL_SPARE_RESOURCES {
    CxlSpareResources_NoneAvailable = 0,
    CxlSpareResources_OneAvailable,
    CxlSpareResources_TwoAvailable,
    CxlSpareResources_ThreeOrMoreAvailable
} CXL_SPARE_RESOURCES, *PCXL_SPARE_RESOURCES;

typedef struct _CXL_MEMORY_SPARING_EVENT_RECORD {
    CXL_COMMON_EVENT_RECORD_HEADER Header;
    UCHAR MaintenanceOperationClass;
    UCHAR MaintenanceOperationSubclass;

    struct {
        UCHAR QueryResourcesFlag : 1;
        UCHAR HardSparingFlag : 1;
        UCHAR DeviceInitiated : 1;

        UCHAR Reserved : 5;
    } Flags;

    UCHAR Result; // CXL_SPARING_RESULT

    struct {
        USHORT Channel : 1;
        USHORT Rank : 1;
        USHORT NibbleMask : 1;
        USHORT BankGroup : 1;
        USHORT Bank : 1;
        USHORT Row : 1;
        USHORT Column : 1;
        USHORT ComponentIdentifier : 1;
        USHORT ComponentIdentifierFormat : 1;
        USHORT Subchannel : 1;

        USHORT Reserved : 6;
    } ValidityFlags;

    UCHAR Reserved[6];
    USHORT SpareResourceAvailable; // CXL_SPARE_RESOURCES
    UCHAR Channel;
    UCHAR Rank;
    UCHAR NibbleMask[3];
    UCHAR BankGroup;
    UCHAR Bank;
    UCHAR Row[3];
    UCHAR Column[2];
    UCHAR ComponentIdentifier[0x10];
    UCHAR SubChannel;
    UCHAR Reserved3[0x25];
} CXL_MEMORY_SPARING_EVENT_RECORD, *PCXL_MEMORY_SPARING_EVENT_RECORD;
C_ASSERT(sizeof(CXL_MEMORY_SPARING_EVENT_RECORD) == 0x80);

//
// Event log for GetEventRecords and ClearEventRecords
//
typedef enum _CXL_MAILBOX_EVENT_LOG {
    CxlMailboxEventRecords_InformationalEventLog = 0,
    CxlMailboxEventRecords_WarningEventLog,
    CxlMailboxEventRecords_FailureEventLog,
    CxlMailboxEventRecords_FatalEventLog,
    CxlMailboxEventRecords_DynamicCapacityEventLog
} CXL_MAILBOX_EVENT_LOG, *PCXL_MAILBOX_EVENT_LOG;

//
// Input buffer for command GetEventRecords
//
typedef struct _CXL_MAILBOX_GET_EVENT_RECORDS_INPUT {
    UCHAR EventLog; // CXL_MAILBOX_EVENT_LOG
} CXL_MAILBOX_GET_EVENT_RECORDS_INPUT, *PCXL_MAILBOX_GET_EVENT_RECORDS_INPUT;

//
// Output buffer for command GetEventRecords
//
typedef struct _CXL_MAILBOX_GET_EVENT_RECORDS_OUTPUT {

    struct {
        UCHAR Overflow : 1;
        UCHAR MoreEventRecords : 1;

        UCHAR Reserved : 6;
    } Flags;

    UCHAR Reserved;
    USHORT OverflowErrorCount;
    ULONGLONG FirstOverflowEventTimestamp;
    ULONGLONG LastOverflowEventTimestamp;
    USHORT EventRecordCount;
    UCHAR Reserved1[0xA];
    _Field_size_(EventRecordCount) CXL_COMMON_EVENT_RECORD EventRecords[ANYSIZE_ARRAY];
} CXL_MAILBOX_GET_EVENT_RECORDS_OUTPUT, *PCXL_MAILBOX_GET_EVENT_RECORDS_OUTPUT;

//
// Input buffer for command ClearEventRecords
//
typedef struct _CXL_MAILBOX_CLEAR_EVENT_RECORDS_INPUT {
    UCHAR EventLog; // CXL_MAILBOX_EVENT_LOG

    struct {
        UCHAR ClearAllEvents : 1;

        UCHAR Reserved : 7;
    } ClearEventFlags;

    UCHAR NumberOfEventRecordHandles;
    UCHAR Reserved[3];
    _Field_size_(NumberOfEventRecordHandles) USHORT EventRecordHandles[ANYSIZE_ARRAY];
} CXL_MAILBOX_CLEAR_EVENT_RECORDS_INPUT, *PCXL_MAILBOX_CLEAR_EVENT_RECORDS_INPUT;

//
// Output buffer for GetAlertConfiguration
//
typedef struct _CXL_MAILBOX_GET_ALERT_CONFIG_OUTPUT {

    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ValidAlerts;

    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ProgrammableAlerts;

    UCHAR LifeUsedCriticalThreshold;
    UCHAR LifeUsedProgrammableWarningThreshold;
    USHORT DeviceOverTemperatureCriticalThreshold;
    USHORT DeviceUnderTemperatureCriticalThreshold;
    USHORT DeviceOverTemperatureProgrammableWarningThreshold;
    USHORT DeviceUnderTemperatureProgrammableWarningThreshold;
    USHORT CorrectedVolatileMemoryProgrammableWarningThreshold;
    USHORT CorrectedPersistentMemoryProgrammableWarningThreshold;
} CXL_MAILBOX_GET_ALERT_CONFIG_OUTPUT, *PCXL_MAILBOX_GET_ALERT_CONFIG_OUTPUT;
C_ASSERT(sizeof(CXL_MAILBOX_GET_ALERT_CONFIG_OUTPUT) == 0x10);

//
// Input buffer for SetAlertConfiguration
//
typedef struct _CXL_MAILBOX_SET_ALERT_CONFIG_INPUT {

    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } ValidAlertActions;

    union {
        struct {
            UCHAR LifeUsed: 1;
            UCHAR DeviceOverTemp : 1;
            UCHAR DeviceUnderTemp : 1;
            UCHAR CorrectedVolatileMemory : 1;
            UCHAR CorrectedPersistentMemory : 1;
            UCHAR Reserved : 3;
        } bits;
        UCHAR AsUchar;
    } EnableAlertActions;
    
    UCHAR LifeUsedProgrammableWarningThreshold;
    UCHAR Reserved;
    USHORT DeviceOverTemperatureProgrammableWarningThreshold;
    USHORT DeviceUnderTemperatureProgrammableWarningThreshold;
    USHORT CorrectedVolatileMemoryProgrammableWarningThreshold;
    USHORT CorrectedPersistentMemoryProgrammableWarningThreshold;
} CXL_MAILBOX_SET_ALERT_CONFIG_INPUT, *PCXL_MAILBOX_SET_ALERT_CONFIG_INPUT;
C_ASSERT(sizeof(CXL_MAILBOX_SET_ALERT_CONFIG_INPUT) == 0x0C);

#pragma pack(pop)

#if _MSC_VER >= 1200
#pragma warning(pop)
#else
#pragma warning(default:4214)
#pragma warning(default:4201)
#pragma warning(default:4200)
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#endif //CXL_INCLUDED

