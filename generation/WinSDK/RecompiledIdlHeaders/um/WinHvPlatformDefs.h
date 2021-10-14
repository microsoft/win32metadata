/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    WinHvPlatformDefs.h

Abstract:

    This module contains the constant, type and structure definitions for
    the Windows Hypervisor User-Mode APIs.

--*/

#ifndef _WINHVAPIDEFS_H_
#define _WINHVAPIDEFS_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#pragma warning(push)
#pragma warning(disable:4201) /* nonstandard extension used: nameless struct/union */
#pragma warning(disable:4214) /* nonstandard extension used: bit field types other than int */
#endif

//
// Platform capabilities
//
typedef enum WHV_CAPABILITY_CODE
{
    // Capabilities of the API implementation
    WHvCapabilityCodeHypervisorPresent                = 0x00000000,
    WHvCapabilityCodeFeatures                         = 0x00000001,
    WHvCapabilityCodeExtendedVmExits                  = 0x00000002,
    WHvCapabilityCodeExceptionExitBitmap              = 0x00000003,
    WHvCapabilityCodeX64MsrExitBitmap                 = 0x00000004,
    WHvCapabilityCodeGpaRangePopulateFlags            = 0x00000005,
    WHvCapabilityCodeSchedulerFeatures                = 0x00000006,

    // Capabilities of the system's processor
    WHvCapabilityCodeProcessorVendor                 = 0x00001000,
    WHvCapabilityCodeProcessorFeatures               = 0x00001001,
    WHvCapabilityCodeProcessorClFlushSize            = 0x00001002,
    WHvCapabilityCodeProcessorXsaveFeatures          = 0x00001003,
    WHvCapabilityCodeProcessorClockFrequency         = 0x00001004,
    WHvCapabilityCodeInterruptClockFrequency         = 0x00001005,
    WHvCapabilityCodeProcessorFeaturesBanks          = 0x00001006,
    WHvCapabilityCodeProcessorFrequencyCap           = 0x00001007,
    WHvCapabilityCodeSyntheticProcessorFeaturesBanks = 0x00001008,
    WHvCapabilityCodeProcessorPerfmonFeatures        = 0x00001009,
} WHV_CAPABILITY_CODE;

//
// Return values for WhvCapabilityCodeFeatures
//
typedef union WHV_CAPABILITY_FEATURES
{
    struct
    {
        UINT64 PartialUnmap : 1;
        UINT64 LocalApicEmulation : 1;
        UINT64 Xsave : 1;
        UINT64 DirtyPageTracking : 1;
        UINT64 SpeculationControl : 1;
        UINT64 ApicRemoteRead : 1;
        UINT64 IdleSuspend : 1;
        UINT64 VirtualPciDeviceSupport : 1;
        UINT64 IommuSupport : 1;
        UINT64 VpHotAddRemove : 1;
        UINT64 Reserved : 54;
    };

    UINT64 AsUINT64;
} WHV_CAPABILITY_FEATURES;

C_ASSERT(sizeof(WHV_CAPABILITY_FEATURES) == 8);

//
// Return values for WhvCapabilityCodeExtendedVmExits and input buffer for
// WHvPartitionPropertyCodeExtendedVmExits
//
typedef union WHV_EXTENDED_VM_EXITS
{
    struct
    {
        UINT64 X64CpuidExit               : 1; // WHvRunVpExitReasonX64CPUID supported
        UINT64 X64MsrExit                 : 1; // WHvRunVpExitX64ReasonMSRAccess supported
        UINT64 ExceptionExit              : 1; // WHvRunVpExitReasonException supported
        UINT64 X64RdtscExit               : 1; // WHvRunVpExitReasonX64Rdtsc supported
        UINT64 X64ApicSmiExitTrap         : 1; // WHvRunVpExitReasonX64ApicSmiTrap supported
        UINT64 HypercallExit              : 1; // WHvRunVpExitReasonHypercall supported
        UINT64 X64ApicInitSipiExitTrap    : 1; // WHvRunVpExitReasonX64ApicInitSipiTrap supported
        UINT64 X64ApicWriteLint0ExitTrap  : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteLint1ExitTrap  : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteSvrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 UnknownSynicConnection     : 1; // WHvRunVpExitReasonHypercall supported for unknown synic connection to HvSignalEvent
        UINT64 RetargetUnknownVpciDevice  : 1; // WHvRunVpExitReasonHypercall supported for unknown device to HvRetargetDeviceInterrupt
        UINT64 X64ApicWriteLdrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 X64ApicWriteDfrExitTrap    : 1; // WHvRunVpExitReasonX64ApicWriteTrap supported
        UINT64 GpaAccessFaultExit         : 1; // WHvRunVpExitReasonMemoryAccess supported for second-level page faults
        UINT64 Reserved                   : 49;
    };

    UINT64 AsUINT64;
} WHV_EXTENDED_VM_EXITS;

C_ASSERT(sizeof(WHV_EXTENDED_VM_EXITS) == 8);

//
// Return values for WhvCapabilityCodeProcessorVendor
//
typedef enum WHV_PROCESSOR_VENDOR
{
    WHvProcessorVendorAmd   = 0x0000,
    WHvProcessorVendorIntel = 0x0001,
    WHvProcessorVendorHygon = 0x0002

} WHV_PROCESSOR_VENDOR;

//
// Return values for WhvCapabilityCodeProcessorFeatures and input buffer for
// WHvPartitionPropertyCodeProcessorFeatures. Additionally the value is embeded
// in WHV_PROCESSOR_FEATURES_BANKS.
//
typedef union WHV_PROCESSOR_FEATURES
{
    struct
    {
        UINT64 Sse3Support : 1;
        UINT64 LahfSahfSupport : 1;
        UINT64 Ssse3Support : 1;
        UINT64 Sse4_1Support : 1;
        UINT64 Sse4_2Support : 1;
        UINT64 Sse4aSupport : 1;
        UINT64 XopSupport : 1;
        UINT64 PopCntSupport : 1;
        UINT64 Cmpxchg16bSupport : 1;
        UINT64 Altmovcr8Support : 1;
        UINT64 LzcntSupport : 1;
        UINT64 MisAlignSseSupport : 1;
        UINT64 MmxExtSupport : 1;
        UINT64 Amd3DNowSupport : 1;
        UINT64 ExtendedAmd3DNowSupport : 1;
        UINT64 Page1GbSupport : 1;
        UINT64 AesSupport : 1;
        UINT64 PclmulqdqSupport : 1;
        UINT64 PcidSupport : 1;
        UINT64 Fma4Support : 1;
        UINT64 F16CSupport : 1;
        UINT64 RdRandSupport : 1;
        UINT64 RdWrFsGsSupport : 1;
        UINT64 SmepSupport : 1;
        UINT64 EnhancedFastStringSupport : 1;
        UINT64 Bmi1Support : 1;
        UINT64 Bmi2Support : 1;
        UINT64 Reserved1 : 2;
        UINT64 MovbeSupport : 1;
        UINT64 Npiep1Support : 1;
        UINT64 DepX87FPUSaveSupport : 1;
        UINT64 RdSeedSupport : 1;
        UINT64 AdxSupport : 1;
        UINT64 IntelPrefetchSupport : 1;
        UINT64 SmapSupport : 1;
        UINT64 HleSupport : 1;
        UINT64 RtmSupport : 1;
        UINT64 RdtscpSupport : 1;
        UINT64 ClflushoptSupport : 1;
        UINT64 ClwbSupport : 1;
        UINT64 ShaSupport : 1;
        UINT64 X87PointersSavedSupport : 1;
        UINT64 InvpcidSupport : 1;
        UINT64 IbrsSupport : 1;
        UINT64 StibpSupport : 1;
        UINT64 IbpbSupport : 1;
        UINT64 Reserved2 : 1;
        UINT64 SsbdSupport : 1;
        UINT64 FastShortRepMovSupport : 1;
        UINT64 Reserved3 : 1;
        UINT64 RdclNo : 1;
        UINT64 IbrsAllSupport : 1;
        UINT64 Reserved4 : 1;
        UINT64 SsbNo : 1;
        UINT64 RsbANo : 1;
        UINT64 Reserved5 : 1;
        UINT64 RdPidSupport : 1;
        UINT64 UmipSupport : 1;
        UINT64 MdsNoSupport : 1;
        UINT64 MdClearSupport : 1;
        UINT64 TaaNoSupport : 1;
        UINT64 TsxCtrlSupport : 1;
        UINT64 Reserved6 : 1;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_FEATURES;

C_ASSERT(sizeof(WHV_PROCESSOR_FEATURES) == 8);

//
// Return values for WhvCapabilityCodeProcessorFeaturesBanks and input buffer
// for WHvPartitionPropertyCodeProcessorFeaturesBanks. BanksCount must be populated
// before calling WHP APIs.
//
typedef union WHV_PROCESSOR_FEATURES1
{
    struct
    {
        UINT64 ACountMCountSupport : 1;
        UINT64 TscInvariantSupport : 1;
        UINT64 ClZeroSupport : 1;
        UINT64 RdpruSupport : 1;
        UINT64 Reserved2 : 2;
        UINT64 NestedVirtSupport : 1;
        UINT64 PsfdSupport: 1;
        UINT64 CetSsSupport : 1;
        UINT64 CetIbtSupport : 1;
        UINT64 VmxExceptionInjectSupport : 1;
        UINT64 Reserved4 : 1;
        UINT64 UmwaitTpauseSupport : 1;
        UINT64 MovdiriSupport : 1;
        UINT64 Movdir64bSupport : 1;
        UINT64 CldemoteSupport : 1;
        UINT64 SerializeSupport : 1;
        UINT64 TscDeadlineTmrSupport : 1;
        UINT64 TscAdjustSupport : 1;
        UINT64 FZLRepMovsb : 1;
        UINT64 FSRepStosb : 1;
        UINT64 FSRepCmpsb : 1;
        UINT64 Reserved5 : 42;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_FEATURES1;

C_ASSERT(sizeof(WHV_PROCESSOR_FEATURES1) == 8);

#define WHV_PROCESSOR_FEATURES_BANKS_COUNT 2

typedef struct WHV_PROCESSOR_FEATURES_BANKS
{
    UINT32 BanksCount;
    UINT32 Reserved0;
    union
    {
        struct
        {
            WHV_PROCESSOR_FEATURES Bank0;
            WHV_PROCESSOR_FEATURES1 Bank1;
        };

        UINT64 AsUINT64[WHV_PROCESSOR_FEATURES_BANKS_COUNT];
    };
} WHV_PROCESSOR_FEATURES_BANKS;

C_ASSERT(sizeof(WHV_PROCESSOR_FEATURES_BANKS) == 8 * (WHV_PROCESSOR_FEATURES_BANKS_COUNT + 1));

//
// Synthetic processor features for exo partitions.
//

typedef union WHV_SYNTHETIC_PROCESSOR_FEATURES
{
    struct
    {
        // Report a hypervisor is present. CPUID leaves
        // 0x40000000 and 0x40000001 are supported.
        UINT64 HypervisorPresent:1;

        //
        // Features associated with HV#1:
        //

        // Report support for Hv1 (CPUID leaves 0x40000000 - 0x40000006).
        UINT64 Hv1:1;

        // Access to HV_X64_MSR_VP_RUNTIME.
        // Corresponds to AccessVpRunTimeReg privilege.
        UINT64 AccessVpRunTimeReg:1;

        // Access to HV_X64_MSR_TIME_REF_COUNT.
        // Corresponds to AccessPartitionReferenceCounter privilege.
        UINT64 AccessPartitionReferenceCounter:1;

        // Access to SINT-related registers (HV_X64_MSR_SCONTROL through
        // HV_X64_MSR_EOM and HV_X64_MSR_SINT0 through HV_X64_MSR_SINT15).
        // Corresponds to AccessSynicRegs privilege.
        UINT64 AccessSynicRegs:1;

        // Access to synthetic timers and associated MSRs
        // (HV_X64_MSR_STIMER0_CONFIG through HV_X64_MSR_STIMER3_COUNT).
        // Corresponds to AccessSyntheticTimerRegs privilege.
        UINT64 AccessSyntheticTimerRegs:1;

#if defined(_AMD64_)
        // Access to APIC MSRs (HV_X64_MSR_EOI, HV_X64_MSR_ICR and HV_X64_MSR_TPR)
        // as well as the VP assist page.
        // Corresponds to AccessIntrCtrlRegs privilege.
        UINT64 AccessIntrCtrlRegs:1;
#else
        UINT64 ReservedZ6:1;
#endif

        // Access to registers associated with hypercalls (HV_X64_MSR_GUEST_OS_ID
        // and HV_X64_MSR_HYPERCALL).
        // Corresponds to AccessHypercallMsrs privilege.
        UINT64 AccessHypercallRegs:1;

        // VP index can be queried. Corresponds to AccessVpIndex privilege.
        UINT64 AccessVpIndex:1;

        // Access to the reference TSC. Corresponds to AccessPartitionReferenceTsc
        // privilege.
        UINT64 AccessPartitionReferenceTsc:1;

#if defined(_AMD64_)
        // Partition has access to the guest idle reg. Corresponds to
        // AccessGuestIdleReg privilege.
        //
        UINT64 AccessGuestIdleReg:1;

        // Partition has access to frequency regs. Corresponds to AccessFrequencyRegs
        // privilege.
        UINT64 AccessFrequencyRegs:1;
#else
        UINT64 ReservedZ10:1;
        UINT64 ReservedZ11:1;
#endif

        UINT64 ReservedZ12:1;
        UINT64 ReservedZ13:1;
        UINT64 ReservedZ14:1;

#if defined(_AMD64_)
        // Extended GVA ranges for HvCallFlushVirtualAddressList hypercall.
        // Corresponds to privilege.
        UINT64 EnableExtendedGvaRangesForFlushVirtualAddressList:1;
#else
        UINT64 ReservedZ15:1;
#endif

        UINT64 ReservedZ16:1;
        UINT64 ReservedZ17:1;

        // Use fast hypercall output. Corresponds to privilege.
        UINT64 FastHypercallOutput:1;

        UINT64 ReservedZ19:1;

        UINT64 ReservedZ20:1;

        UINT64 ReservedZ21:1;

        // Synthetic timers in direct mode.
        UINT64 DirectSyntheticTimers:1;

        UINT64 ReservedZ23:1;

        // Use extended processor masks.
        UINT64 ExtendedProcessorMasks:1;

#if defined(_AMD64_)
        // HvCallFlushVirtualAddressSpace / HvCallFlushVirtualAddressList are supported.
        UINT64 TbFlushHypercalls:1;
#else
        UINT64 ReservedZ25:1;
#endif

        // HvCallSendSyntheticClusterIpi is supported.
        UINT64 SyntheticClusterIpi:1;

        // HvCallNotifyLongSpinWait is supported.
        UINT64 NotifyLongSpinWait:1;

        // HvCallQueryNumaDistance is supported.
        UINT64 QueryNumaDistance:1;

        // HvCallSignalEvent is supported. Corresponds to privilege.
        UINT64 SignalEvents:1;

        // HvCallRetargetDeviceInterrupt is supported.
        UINT64 RetargetDeviceInterrupt:1;

        UINT64 Reserved:33;
    };

    UINT64 AsUINT64;
} WHV_SYNTHETIC_PROCESSOR_FEATURES;

C_ASSERT(sizeof(WHV_SYNTHETIC_PROCESSOR_FEATURES) == 8);

#define WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS_COUNT 1

typedef struct WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS
{
    UINT32 BanksCount;
    UINT32 Reserved0;
    union
    {
        struct
        {
            WHV_SYNTHETIC_PROCESSOR_FEATURES Bank0;
        };

        UINT64 AsUINT64[WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS_COUNT];
    };
} WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS;

C_ASSERT(sizeof(WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS) == 16);

//
// Partitions
//

typedef VOID* WHV_PARTITION_HANDLE;

typedef enum WHV_PARTITION_PROPERTY_CODE
{
    WHvPartitionPropertyCodeExtendedVmExits         = 0x00000001,
    WHvPartitionPropertyCodeExceptionExitBitmap     = 0x00000002,
    WHvPartitionPropertyCodeSeparateSecurityDomain  = 0x00000003,
    // Nested virtualization support is experimental and not supported.
    WHvPartitionPropertyCodeNestedVirtualization    = 0x00000004,
    WHvPartitionPropertyCodeX64MsrExitBitmap        = 0x00000005,
    WHvPartitionPropertyCodePrimaryNumaNode         = 0x00000006,
    WHvPartitionPropertyCodeCpuReserve              = 0x00000007,
    WHvPartitionPropertyCodeCpuCap                  = 0x00000008,
    WHvPartitionPropertyCodeCpuWeight               = 0x00000009,
    WHvPartitionPropertyCodeCpuGroupId              = 0x0000000a,
    WHvPartitionPropertyCodeProcessorFrequencyCap   = 0x0000000b,
    WHvPartitionPropertyCodeAllowDeviceAssignment   = 0x0000000c,
    WHvPartitionPropertyCodeDisableSmt              = 0x0000000d,

    WHvPartitionPropertyCodeProcessorFeatures               = 0x00001001,
    WHvPartitionPropertyCodeProcessorClFlushSize            = 0x00001002,
    WHvPartitionPropertyCodeCpuidExitList                   = 0x00001003,
    WHvPartitionPropertyCodeCpuidResultList                 = 0x00001004,
    WHvPartitionPropertyCodeLocalApicEmulationMode          = 0x00001005,
    WHvPartitionPropertyCodeProcessorXsaveFeatures          = 0x00001006,
    WHvPartitionPropertyCodeProcessorClockFrequency         = 0x00001007,
    WHvPartitionPropertyCodeInterruptClockFrequency         = 0x00001008,
    WHvPartitionPropertyCodeApicRemoteReadSupport           = 0x00001009,
    WHvPartitionPropertyCodeProcessorFeaturesBanks          = 0x0000100A,
    WHvPartitionPropertyCodeReferenceTime                   = 0x0000100B,
    WHvPartitionPropertyCodeSyntheticProcessorFeaturesBanks = 0x0000100C,
    WHvPartitionPropertyCodeCpuidResultList2                = 0x0000100D,
    WHvPartitionPropertyCodeProcessorPerfmonFeatures        = 0x0000100E,
    WHvPartitionPropertyCodeMsrActionList                   = 0x0000100F,
    WHvPartitionPropertyCodeUnimplementedMsrAction          = 0x00001010,

    WHvPartitionPropertyCodeProcessorCount          = 0x00001fff
} WHV_PARTITION_PROPERTY_CODE;

//
// Return values for WHvCapabilityCodeProcessorXsaveFeatures and input buffer
// for WHvPartitionPropertyCodeProcessorXsaveFeatures
//
typedef union WHV_PROCESSOR_XSAVE_FEATURES
{
    struct
    {
        UINT64 XsaveSupport : 1;
        UINT64 XsaveoptSupport : 1;
        UINT64 AvxSupport : 1;
        UINT64 Avx2Support : 1;
        UINT64 FmaSupport : 1;
        UINT64 MpxSupport : 1;
        UINT64 Avx512Support : 1;
        UINT64 Avx512DQSupport : 1;
        UINT64 Avx512CDSupport : 1;
        UINT64 Avx512BWSupport : 1;
        UINT64 Avx512VLSupport : 1;
        UINT64 XsaveCompSupport : 1;
        UINT64 XsaveSupervisorSupport : 1;
        UINT64 Xcr1Support : 1;
        UINT64 Avx512BitalgSupport : 1;
        UINT64 Avx512IfmaSupport : 1;
        UINT64 Avx512VBmiSupport : 1;
        UINT64 Avx512VBmi2Support : 1;
        UINT64 Avx512VnniSupport : 1;
        UINT64 GfniSupport : 1;
        UINT64 VaesSupport : 1;
        UINT64 Avx512VPopcntdqSupport : 1;
        UINT64 VpclmulqdqSupport : 1;
        UINT64 Avx512Bf16Support : 1;
        UINT64 Avx512Vp2IntersectSupport : 1;
        UINT64 Avx512Fp16Support : 1;
        UINT64 XfdSupport : 1;
        UINT64 AmxTileSupport : 1;
        UINT64 AmxBf16Support : 1;
        UINT64 AmxInt8Support : 1;
        UINT64 AvxVnniSupport : 1;
        UINT64 Reserved : 33;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_XSAVE_FEATURES, *PWHV_PROCESSOR_XSAVE_FEATURES;

C_ASSERT(sizeof(WHV_PROCESSOR_XSAVE_FEATURES) == 8);

//
// Return values for WHvCapabilityCodeProcessorPerfmonFeatures and input buffer
// for WHvPartitionPropertyCodeProcessorPerfmonFeatures
//
typedef union WHV_PROCESSOR_PERFMON_FEATURES
{
    struct
    {
        UINT64 PmuSupport : 1;
        UINT64 LbrSupport : 1;
        UINT64 Reserved : 62;
    };

    UINT64 AsUINT64;
} WHV_PROCESSOR_PERFMON_FEATURES, *PWHV_PROCESSOR_PERFMON_FEATURES;

C_ASSERT(sizeof(WHV_PROCESSOR_PERFMON_FEATURES) == 8);

//
// Return value for WHvCapabilityCodeX64MsrExits and input buffer for
// WHvPartitionPropertyCodeX64MsrcExits
//
typedef union WHV_X64_MSR_EXIT_BITMAP
{
    UINT64 AsUINT64;
    struct
    {
        UINT64 UnhandledMsrs:1;
        UINT64 TscMsrWrite:1;
        UINT64 TscMsrRead:1;
        UINT64 ApicBaseMsrWrite:1;
        UINT64 MiscEnableMsrRead:1;
        UINT64 McUpdatePatchLevelMsrRead:1;
        UINT64 Reserved:58;
    };

} WHV_X64_MSR_EXIT_BITMAP;

C_ASSERT(sizeof(WHV_X64_MSR_EXIT_BITMAP) == 8);

//
// Structure describing a memory range entry
//
typedef struct WHV_MEMORY_RANGE_ENTRY {
    UINT64 GuestAddress;
    UINT64 SizeInBytes;
} WHV_MEMORY_RANGE_ENTRY;

C_ASSERT(sizeof(WHV_MEMORY_RANGE_ENTRY) == 16);

typedef union WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS
{
    UINT32 AsUINT32;
    struct
    {
        UINT32 Prefetch:1;
        UINT32 AvoidHardFaults:1;
        UINT32 Reserved:30;
    };
} WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS) == 4);

typedef enum WHV_MEMORY_ACCESS_TYPE
{
    WHvMemoryAccessRead    = 0,
    WHvMemoryAccessWrite   = 1,
    WHvMemoryAccessExecute = 2
} WHV_MEMORY_ACCESS_TYPE;

//
// Parameters used by WHvAdviseGpaRangeCodePopulate
//
typedef struct WHV_ADVISE_GPA_RANGE_POPULATE
{
    WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS Flags;
    WHV_MEMORY_ACCESS_TYPE AccessType;
} WHV_ADVISE_GPA_RANGE_POPULATE;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE_POPULATE) == 8);

typedef struct WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP
{
    UINT32 IsSupported:1;
    UINT32 Reserved:31;
    UINT32 HighestFrequencyMhz;
    UINT32 NominalFrequencyMhz;
    UINT32 LowestFrequencyMhz;
    UINT32 FrequencyStepMhz;
} WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP;

C_ASSERT(sizeof(WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP) == 20);

typedef union WHV_SCHEDULER_FEATURES
{
    struct
    {
        UINT64 CpuReserve: 1;
        UINT64 CpuCap: 1;
        UINT64 CpuWeight: 1;
        UINT64 CpuGroupId: 1;
        UINT64 DisableSmt: 1;
        UINT64 Reserved: 59;
    };

    UINT64 AsUINT64;
} WHV_SCHEDULER_FEATURES;

C_ASSERT(sizeof(WHV_SCHEDULER_FEATURES) == 8);

//
// WHvGetCapability output buffer
//
typedef union WHV_CAPABILITY
{
    BOOL HypervisorPresent;
    WHV_CAPABILITY_FEATURES Features;
    WHV_EXTENDED_VM_EXITS ExtendedVmExits;
    WHV_PROCESSOR_VENDOR ProcessorVendor;
    WHV_PROCESSOR_FEATURES ProcessorFeatures;
    WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS SyntheticProcessorFeaturesBanks;
    WHV_PROCESSOR_XSAVE_FEATURES ProcessorXsaveFeatures;
    UINT8 ProcessorClFlushSize;
    UINT64 ExceptionExitBitmap;
    WHV_X64_MSR_EXIT_BITMAP X64MsrExitBitmap;
    UINT64 ProcessorClockFrequency;
    UINT64 InterruptClockFrequency;
    WHV_PROCESSOR_FEATURES_BANKS ProcessorFeaturesBanks;
    WHV_ADVISE_GPA_RANGE_POPULATE_FLAGS GpaRangePopulateFlags;
    WHV_CAPABILITY_PROCESSOR_FREQUENCY_CAP ProcessorFrequencyCap;
    WHV_PROCESSOR_PERFMON_FEATURES ProcessorPerfmonFeatures;
    WHV_SCHEDULER_FEATURES SchedulerFeatures;
} WHV_CAPABILITY;

//
// WHvPartitionPropertyCodeCpuidResultList input buffer list element.
//
typedef struct WHV_X64_CPUID_RESULT
{
    UINT32 Function;
    UINT32 Reserved[3];
    UINT32 Eax;
    UINT32 Ebx;
    UINT32 Ecx;
    UINT32 Edx;
} WHV_X64_CPUID_RESULT;

C_ASSERT(sizeof(WHV_X64_CPUID_RESULT) == 32);

typedef enum WHV_X64_CPUID_RESULT2_FLAGS
{
    WHvX64CpuidResult2FlagSubleafSpecific   = 0x00000001,
    WHvX64CpuidResult2FlagVpSpecific        = 0x00000002,
} WHV_X64_CPUID_RESULT2_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_X64_CPUID_RESULT2_FLAGS);

typedef struct WHV_CPUID_OUTPUT
{
    UINT32 Eax;
    UINT32 Ebx;
    UINT32 Ecx;
    UINT32 Edx;
} WHV_CPUID_OUTPUT;

C_ASSERT(sizeof(WHV_CPUID_OUTPUT) == 16);

//
// WHvPartitionPropertyCodeCpuidResultList2 input buffer list element.
//
typedef struct WHV_X64_CPUID_RESULT2
{
    UINT32 Function;
    UINT32 Index;
    UINT32 VpIndex;
    WHV_X64_CPUID_RESULT2_FLAGS Flags;
    WHV_CPUID_OUTPUT Output;
    WHV_CPUID_OUTPUT Mask;
} WHV_X64_CPUID_RESULT2;

C_ASSERT(sizeof(WHV_X64_CPUID_RESULT2) == 48);

//
// WHvPartitionPropertyCodeMsrActionList input buffer list element.
//
typedef struct WHV_MSR_ACTION_ENTRY
{
    UINT32 Index;
    UINT8 ReadAction; // WHV_MSR_ACTION
    UINT8 WriteAction; // WHV_MSR_ACTION
    UINT16 Reserved;
} WHV_MSR_ACTION_ENTRY;

C_ASSERT(sizeof(WHV_MSR_ACTION_ENTRY) == 8);

//
// WHvPartitionPropertyCodeUnimplementedMsrAction input.
//
typedef enum WHV_MSR_ACTION
{
    WHvMsrActionArchitectureDefault = 0,
    WHvMsrActionIgnoreWriteReadZero = 1,
    WHvMsrActionExit = 2,
} WHV_MSR_ACTION;

//
// WHvPartitionPropertyCodeExceptionBitmap enumeration values.
//
typedef enum WHV_EXCEPTION_TYPE
{
    WHvX64ExceptionTypeDivideErrorFault = 0x0,
    WHvX64ExceptionTypeDebugTrapOrFault = 0x1,
    WHvX64ExceptionTypeBreakpointTrap = 0x3,
    WHvX64ExceptionTypeOverflowTrap = 0x4,
    WHvX64ExceptionTypeBoundRangeFault = 0x5,
    WHvX64ExceptionTypeInvalidOpcodeFault = 0x6,
    WHvX64ExceptionTypeDeviceNotAvailableFault = 0x7,
    WHvX64ExceptionTypeDoubleFaultAbort = 0x8,
    WHvX64ExceptionTypeInvalidTaskStateSegmentFault = 0x0A,
    WHvX64ExceptionTypeSegmentNotPresentFault = 0x0B,
    WHvX64ExceptionTypeStackFault = 0x0C,
    WHvX64ExceptionTypeGeneralProtectionFault = 0x0D,
    WHvX64ExceptionTypePageFault = 0x0E,
    WHvX64ExceptionTypeFloatingPointErrorFault = 0x10,
    WHvX64ExceptionTypeAlignmentCheckFault = 0x11,
    WHvX64ExceptionTypeMachineCheckAbort = 0x12,
    WHvX64ExceptionTypeSimdFloatingPointFault = 0x13,
} WHV_EXCEPTION_TYPE;

typedef enum WHV_X64_LOCAL_APIC_EMULATION_MODE
{
    WHvX64LocalApicEmulationModeNone,
    WHvX64LocalApicEmulationModeXApic,
    WHvX64LocalApicEmulationModeX2Apic
} WHV_X64_LOCAL_APIC_EMULATION_MODE;

//
// WHvGetPartitionProperty output buffer / WHvSetPartitionProperty input buffer
//
typedef union WHV_PARTITION_PROPERTY
{
    WHV_EXTENDED_VM_EXITS ExtendedVmExits;
    WHV_PROCESSOR_FEATURES ProcessorFeatures;
    WHV_SYNTHETIC_PROCESSOR_FEATURES_BANKS SyntheticProcessorFeaturesBanks;
    WHV_PROCESSOR_XSAVE_FEATURES ProcessorXsaveFeatures;
    UINT8 ProcessorClFlushSize;
    UINT32 ProcessorCount;
    UINT32 CpuidExitList[1];
    WHV_X64_CPUID_RESULT CpuidResultList[1];
    WHV_X64_CPUID_RESULT2 CpuidResultList2[1];
    WHV_MSR_ACTION_ENTRY MsrActionList[1];
    WHV_MSR_ACTION UnimplementedMsrAction;
    UINT64 ExceptionExitBitmap;
    WHV_X64_LOCAL_APIC_EMULATION_MODE LocalApicEmulationMode;
    BOOL SeparateSecurityDomain;
    // Nested virtualization support is experimental and not supported.
    BOOL NestedVirtualization;
    WHV_X64_MSR_EXIT_BITMAP X64MsrExitBitmap;
    UINT64 ProcessorClockFrequency;
    UINT64 InterruptClockFrequency;
    BOOL ApicRemoteRead;
    WHV_PROCESSOR_FEATURES_BANKS ProcessorFeaturesBanks;
    UINT64 ReferenceTime;
    USHORT PrimaryNumaNode;
    UINT32 CpuReserve;
    UINT32 CpuCap;
    UINT32 CpuWeight;
    UINT64 CpuGroupId;
    UINT32 ProcessorFrequencyCap;
    BOOL AllowDeviceAssignment;
    WHV_PROCESSOR_PERFMON_FEATURES ProcessorPerfmonFeatures;
    BOOL DisableSmt;
} WHV_PARTITION_PROPERTY;

//
// Memory Management
//

//
// Guest physical or virtual address
//
typedef UINT64 WHV_GUEST_PHYSICAL_ADDRESS;
typedef UINT64 WHV_GUEST_VIRTUAL_ADDRESS;

//
// Flags used by WHvMapGpaRange/WHvMapGpaRange2
//
typedef enum WHV_MAP_GPA_RANGE_FLAGS
{
    WHvMapGpaRangeFlagNone             = 0x00000000,
    WHvMapGpaRangeFlagRead             = 0x00000001,
    WHvMapGpaRangeFlagWrite            = 0x00000002,
    WHvMapGpaRangeFlagExecute          = 0x00000004,
    WHvMapGpaRangeFlagTrackDirtyPages  = 0x00000008,

} WHV_MAP_GPA_RANGE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_MAP_GPA_RANGE_FLAGS);

//
// Flags used by WHvTranslateGva
//
typedef enum WHV_TRANSLATE_GVA_FLAGS
{
    WHvTranslateGvaFlagNone             = 0x00000000,
    WHvTranslateGvaFlagValidateRead     = 0x00000001,
    WHvTranslateGvaFlagValidateWrite    = 0x00000002,
    WHvTranslateGvaFlagValidateExecute  = 0x00000004,
    WHvTranslateGvaFlagPrivilegeExempt  = 0x00000008,
    WHvTranslateGvaFlagSetPageTableBits = 0x00000010,
    WHvTranslateGvaFlagEnforceSmap      = 0x00000100,
    WHvTranslateGvaFlagOverrideSmap     = 0x00000200
} WHV_TRANSLATE_GVA_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_TRANSLATE_GVA_FLAGS);

//
// Result of an attempt to translate a guest virtual address
//
typedef enum WHV_TRANSLATE_GVA_RESULT_CODE
{
    WHvTranslateGvaResultSuccess                 = 0,

    // Translation failures
    WHvTranslateGvaResultPageNotPresent          = 1,
    WHvTranslateGvaResultPrivilegeViolation      = 2,
    WHvTranslateGvaResultInvalidPageTableFlags   = 3,

    // GPA access failures
    WHvTranslateGvaResultGpaUnmapped             = 4,
    WHvTranslateGvaResultGpaNoReadAccess         = 5,
    WHvTranslateGvaResultGpaNoWriteAccess        = 6,
    WHvTranslateGvaResultGpaIllegalOverlayAccess = 7,
    WHvTranslateGvaResultIntercept               = 8
} WHV_TRANSLATE_GVA_RESULT_CODE;

//
// Output buffer of WHvTranslateGva
//
typedef struct WHV_TRANSLATE_GVA_RESULT
{
    WHV_TRANSLATE_GVA_RESULT_CODE ResultCode;
    UINT32 Reserved;
} WHV_TRANSLATE_GVA_RESULT;

C_ASSERT(sizeof(WHV_TRANSLATE_GVA_RESULT) == 8);

//
// WHvAdviseGpaRange buffer
//
typedef union WHV_ADVISE_GPA_RANGE
{
    WHV_ADVISE_GPA_RANGE_POPULATE Populate;
} WHV_ADVISE_GPA_RANGE;

C_ASSERT(sizeof(WHV_ADVISE_GPA_RANGE) == 8);

typedef enum WHV_CACHE_TYPE {
    WHvCacheTypeUncached         = 0,
    WHvCacheTypeWriteCombining   = 1,
    WHvCacheTypeWriteThrough     = 4,

#if defined(_AMD64_)
    WHvCacheTypeWriteProtected   = 5,
#endif

    WHvCacheTypeWriteBack        = 6
} WHV_CACHE_TYPE;

//
// Control flags used by WHvReadGpaRange and WHvWriteGpaRange
//
typedef union WHV_ACCESS_GPA_CONTROLS
{
    UINT64 AsUINT64;
    struct
    {
        //
        // Cache type for access
        //
        WHV_CACHE_TYPE CacheType;
        UINT32 Reserved;
    };
} WHV_ACCESS_GPA_CONTROLS;

C_ASSERT(sizeof(WHV_ACCESS_GPA_CONTROLS) == 8);

//
// Maxmium data size used by WHvReadGpaRange and WHvWriteGpaRange
//
#define WHV_READ_WRITE_GPA_RANGE_MAX_SIZE 16

//
// Virtual Processor Register Definitions
//
typedef enum WHV_REGISTER_NAME
{
    // X64 General purpose registers
    WHvX64RegisterRax              = 0x00000000,
    WHvX64RegisterRcx              = 0x00000001,
    WHvX64RegisterRdx              = 0x00000002,
    WHvX64RegisterRbx              = 0x00000003,
    WHvX64RegisterRsp              = 0x00000004,
    WHvX64RegisterRbp              = 0x00000005,
    WHvX64RegisterRsi              = 0x00000006,
    WHvX64RegisterRdi              = 0x00000007,
    WHvX64RegisterR8               = 0x00000008,
    WHvX64RegisterR9               = 0x00000009,
    WHvX64RegisterR10              = 0x0000000A,
    WHvX64RegisterR11              = 0x0000000B,
    WHvX64RegisterR12              = 0x0000000C,
    WHvX64RegisterR13              = 0x0000000D,
    WHvX64RegisterR14              = 0x0000000E,
    WHvX64RegisterR15              = 0x0000000F,
    WHvX64RegisterRip              = 0x00000010,
    WHvX64RegisterRflags           = 0x00000011,

    // X64 Segment registers
    WHvX64RegisterEs               = 0x00000012,
    WHvX64RegisterCs               = 0x00000013,
    WHvX64RegisterSs               = 0x00000014,
    WHvX64RegisterDs               = 0x00000015,
    WHvX64RegisterFs               = 0x00000016,
    WHvX64RegisterGs               = 0x00000017,
    WHvX64RegisterLdtr             = 0x00000018,
    WHvX64RegisterTr               = 0x00000019,

    // X64 Table registers
    WHvX64RegisterIdtr             = 0x0000001A,
    WHvX64RegisterGdtr             = 0x0000001B,

    // X64 Control Registers
    WHvX64RegisterCr0              = 0x0000001C,
    WHvX64RegisterCr2              = 0x0000001D,
    WHvX64RegisterCr3              = 0x0000001E,
    WHvX64RegisterCr4              = 0x0000001F,
    WHvX64RegisterCr8              = 0x00000020,

    // X64 Debug Registers
    WHvX64RegisterDr0              = 0x00000021,
    WHvX64RegisterDr1              = 0x00000022,
    WHvX64RegisterDr2              = 0x00000023,
    WHvX64RegisterDr3              = 0x00000024,
    WHvX64RegisterDr6              = 0x00000025,
    WHvX64RegisterDr7              = 0x00000026,

    // X64 Extended Control Registers
    WHvX64RegisterXCr0             = 0x00000027,

    // X64 Virtual Control Registers
    WHvX64RegisterVirtualCr0       = 0x00000028,
    WHvX64RegisterVirtualCr3       = 0x00000029,
    WHvX64RegisterVirtualCr4       = 0x0000002A,
    WHvX64RegisterVirtualCr8       = 0x0000002B,

    // X64 Floating Point and Vector Registers
    WHvX64RegisterXmm0             = 0x00001000,
    WHvX64RegisterXmm1             = 0x00001001,
    WHvX64RegisterXmm2             = 0x00001002,
    WHvX64RegisterXmm3             = 0x00001003,
    WHvX64RegisterXmm4             = 0x00001004,
    WHvX64RegisterXmm5             = 0x00001005,
    WHvX64RegisterXmm6             = 0x00001006,
    WHvX64RegisterXmm7             = 0x00001007,
    WHvX64RegisterXmm8             = 0x00001008,
    WHvX64RegisterXmm9             = 0x00001009,
    WHvX64RegisterXmm10            = 0x0000100A,
    WHvX64RegisterXmm11            = 0x0000100B,
    WHvX64RegisterXmm12            = 0x0000100C,
    WHvX64RegisterXmm13            = 0x0000100D,
    WHvX64RegisterXmm14            = 0x0000100E,
    WHvX64RegisterXmm15            = 0x0000100F,
    WHvX64RegisterFpMmx0           = 0x00001010,
    WHvX64RegisterFpMmx1           = 0x00001011,
    WHvX64RegisterFpMmx2           = 0x00001012,
    WHvX64RegisterFpMmx3           = 0x00001013,
    WHvX64RegisterFpMmx4           = 0x00001014,
    WHvX64RegisterFpMmx5           = 0x00001015,
    WHvX64RegisterFpMmx6           = 0x00001016,
    WHvX64RegisterFpMmx7           = 0x00001017,
    WHvX64RegisterFpControlStatus  = 0x00001018,
    WHvX64RegisterXmmControlStatus = 0x00001019,

    // X64 MSRs
    WHvX64RegisterTsc              = 0x00002000,
    WHvX64RegisterEfer             = 0x00002001,
    WHvX64RegisterKernelGsBase     = 0x00002002,
    WHvX64RegisterApicBase         = 0x00002003,
    WHvX64RegisterPat              = 0x00002004,
    WHvX64RegisterSysenterCs       = 0x00002005,
    WHvX64RegisterSysenterEip      = 0x00002006,
    WHvX64RegisterSysenterEsp      = 0x00002007,
    WHvX64RegisterStar             = 0x00002008,
    WHvX64RegisterLstar            = 0x00002009,
    WHvX64RegisterCstar            = 0x0000200A,
    WHvX64RegisterSfmask           = 0x0000200B,
    WHvX64RegisterInitialApicId    = 0x0000200C,

    WHvX64RegisterMsrMtrrCap         = 0x0000200D,
    WHvX64RegisterMsrMtrrDefType     = 0x0000200E,

    WHvX64RegisterMsrMtrrPhysBase0   = 0x00002010,
    WHvX64RegisterMsrMtrrPhysBase1   = 0x00002011,
    WHvX64RegisterMsrMtrrPhysBase2   = 0x00002012,
    WHvX64RegisterMsrMtrrPhysBase3   = 0x00002013,
    WHvX64RegisterMsrMtrrPhysBase4   = 0x00002014,
    WHvX64RegisterMsrMtrrPhysBase5   = 0x00002015,
    WHvX64RegisterMsrMtrrPhysBase6   = 0x00002016,
    WHvX64RegisterMsrMtrrPhysBase7   = 0x00002017,
    WHvX64RegisterMsrMtrrPhysBase8   = 0x00002018,
    WHvX64RegisterMsrMtrrPhysBase9   = 0x00002019,
    WHvX64RegisterMsrMtrrPhysBaseA   = 0x0000201A,
    WHvX64RegisterMsrMtrrPhysBaseB   = 0x0000201B,
    WHvX64RegisterMsrMtrrPhysBaseC   = 0x0000201C,
    WHvX64RegisterMsrMtrrPhysBaseD   = 0x0000201D,
    WHvX64RegisterMsrMtrrPhysBaseE   = 0x0000201E,
    WHvX64RegisterMsrMtrrPhysBaseF   = 0x0000201F,

    WHvX64RegisterMsrMtrrPhysMask0   = 0x00002040,
    WHvX64RegisterMsrMtrrPhysMask1   = 0x00002041,
    WHvX64RegisterMsrMtrrPhysMask2   = 0x00002042,
    WHvX64RegisterMsrMtrrPhysMask3   = 0x00002043,
    WHvX64RegisterMsrMtrrPhysMask4   = 0x00002044,
    WHvX64RegisterMsrMtrrPhysMask5   = 0x00002045,
    WHvX64RegisterMsrMtrrPhysMask6   = 0x00002046,
    WHvX64RegisterMsrMtrrPhysMask7   = 0x00002047,
    WHvX64RegisterMsrMtrrPhysMask8   = 0x00002048,
    WHvX64RegisterMsrMtrrPhysMask9   = 0x00002049,
    WHvX64RegisterMsrMtrrPhysMaskA   = 0x0000204A,
    WHvX64RegisterMsrMtrrPhysMaskB   = 0x0000204B,
    WHvX64RegisterMsrMtrrPhysMaskC   = 0x0000204C,
    WHvX64RegisterMsrMtrrPhysMaskD   = 0x0000204D,
    WHvX64RegisterMsrMtrrPhysMaskE   = 0x0000204E,
    WHvX64RegisterMsrMtrrPhysMaskF   = 0x0000204F,

    WHvX64RegisterMsrMtrrFix64k00000 = 0x00002070,
    WHvX64RegisterMsrMtrrFix16k80000 = 0x00002071,
    WHvX64RegisterMsrMtrrFix16kA0000 = 0x00002072,
    WHvX64RegisterMsrMtrrFix4kC0000  = 0x00002073,
    WHvX64RegisterMsrMtrrFix4kC8000  = 0x00002074,
    WHvX64RegisterMsrMtrrFix4kD0000  = 0x00002075,
    WHvX64RegisterMsrMtrrFix4kD8000  = 0x00002076,
    WHvX64RegisterMsrMtrrFix4kE0000  = 0x00002077,
    WHvX64RegisterMsrMtrrFix4kE8000  = 0x00002078,
    WHvX64RegisterMsrMtrrFix4kF0000  = 0x00002079,
    WHvX64RegisterMsrMtrrFix4kF8000  = 0x0000207A,

    WHvX64RegisterTscAux           = 0x0000207B,
    WHvX64RegisterBndcfgs          = 0x0000207C,
    WHvX64RegisterMCount           = 0x0000207E,
    WHvX64RegisterACount           = 0x0000207F,
    WHvX64RegisterSpecCtrl         = 0x00002084,
    WHvX64RegisterPredCmd          = 0x00002085,
    WHvX64RegisterTscVirtualOffset = 0x00002087,
    WHvX64RegisterTsxCtrl          = 0x00002088,
    WHvX64RegisterXss              = 0x0000208B,
    WHvX64RegisterUCet             = 0x0000208C,
    WHvX64RegisterSCet             = 0x0000208D,
    WHvX64RegisterSsp              = 0x0000208E,
    WHvX64RegisterPl0Ssp           = 0x0000208F,
    WHvX64RegisterPl1Ssp           = 0x00002090,
    WHvX64RegisterPl2Ssp           = 0x00002091,
    WHvX64RegisterPl3Ssp           = 0x00002092,
    WHvX64RegisterInterruptSspTableAddr = 0x00002093,
    WHvX64RegisterTscDeadline      = 0x00002095,
    WHvX64RegisterTscAdjust        = 0x00002096,
    WHvX64RegisterUmwaitControl    = 0x00002098,
    WHvX64RegisterXfd              = 0x00002099,
    WHvX64RegisterXfdErr           = 0x0000209A,

    // APIC state (also accessible via WHv(Get/Set)VirtualProcessorInterruptControllerState)
    WHvX64RegisterApicId           = 0x00003002,
    WHvX64RegisterApicVersion      = 0x00003003,
    // X2APIC state (also accessible via WHv(Get/Set)VirtualProcessorInterruptControllerState)
    WHvX64RegisterApicTpr          = 0x00003008,
    WHvX64RegisterApicPpr          = 0x0000300A,
    WHvX64RegisterApicEoi          = 0x0000300B,
    WHvX64RegisterApicLdr          = 0x0000300D,
    WHvX64RegisterApicSpurious     = 0x0000300F,
    WHvX64RegisterApicIsr0         = 0x00003010,
    WHvX64RegisterApicIsr1         = 0x00003011,
    WHvX64RegisterApicIsr2         = 0x00003012,
    WHvX64RegisterApicIsr3         = 0x00003013,
    WHvX64RegisterApicIsr4         = 0x00003014,
    WHvX64RegisterApicIsr5         = 0x00003015,
    WHvX64RegisterApicIsr6         = 0x00003016,
    WHvX64RegisterApicIsr7         = 0x00003017,
    WHvX64RegisterApicTmr0         = 0x00003018,
    WHvX64RegisterApicTmr1         = 0x00003019,
    WHvX64RegisterApicTmr2         = 0x0000301A,
    WHvX64RegisterApicTmr3         = 0x0000301B,
    WHvX64RegisterApicTmr4         = 0x0000301C,
    WHvX64RegisterApicTmr5         = 0x0000301D,
    WHvX64RegisterApicTmr6         = 0x0000301E,
    WHvX64RegisterApicTmr7         = 0x0000301F,
    WHvX64RegisterApicIrr0         = 0x00003020,
    WHvX64RegisterApicIrr1         = 0x00003021,
    WHvX64RegisterApicIrr2         = 0x00003022,
    WHvX64RegisterApicIrr3         = 0x00003023,
    WHvX64RegisterApicIrr4         = 0x00003024,
    WHvX64RegisterApicIrr5         = 0x00003025,
    WHvX64RegisterApicIrr6         = 0x00003026,
    WHvX64RegisterApicIrr7         = 0x00003027,
    WHvX64RegisterApicEse          = 0x00003028,
    WHvX64RegisterApicIcr          = 0x00003030,
    WHvX64RegisterApicLvtTimer     = 0x00003032,
    WHvX64RegisterApicLvtThermal   = 0x00003033,
    WHvX64RegisterApicLvtPerfmon   = 0x00003034,
    WHvX64RegisterApicLvtLint0     = 0x00003035,
    WHvX64RegisterApicLvtLint1     = 0x00003036,
    WHvX64RegisterApicLvtError     = 0x00003037,
    WHvX64RegisterApicInitCount    = 0x00003038,
    WHvX64RegisterApicCurrentCount = 0x00003039,
    WHvX64RegisterApicDivide       = 0x0000303E,
    WHvX64RegisterApicSelfIpi      = 0x0000303F,

    // Synic registers
    WHvRegisterSint0               = 0x00004000,
    WHvRegisterSint1               = 0x00004001,
    WHvRegisterSint2               = 0x00004002,
    WHvRegisterSint3               = 0x00004003,
    WHvRegisterSint4               = 0x00004004,
    WHvRegisterSint5               = 0x00004005,
    WHvRegisterSint6               = 0x00004006,
    WHvRegisterSint7               = 0x00004007,
    WHvRegisterSint8               = 0x00004008,
    WHvRegisterSint9               = 0x00004009,
    WHvRegisterSint10              = 0x0000400A,
    WHvRegisterSint11              = 0x0000400B,
    WHvRegisterSint12              = 0x0000400C,
    WHvRegisterSint13              = 0x0000400D,
    WHvRegisterSint14              = 0x0000400E,
    WHvRegisterSint15              = 0x0000400F,
    WHvRegisterScontrol            = 0x00004010,
    WHvRegisterSversion            = 0x00004011,
    WHvRegisterSiefp               = 0x00004012,
    WHvRegisterSimp                = 0x00004013,
    WHvRegisterEom                 = 0x00004014,

    // Synthetic processor feature registers
    WHvRegisterVpRuntime           = 0x00005000,
    WHvX64RegisterHypercall        = 0x00005001,
    WHvRegisterGuestOsId           = 0x00005002,
    WHvRegisterVpAssistPage        = 0x00005013,
    WHvRegisterReferenceTsc        = 0x00005017,
    WHvRegisterReferenceTscSequence = 0x0000501A,

    // Interrupt / Event Registers
    WHvRegisterPendingInterruption = 0x80000000,
    WHvRegisterInterruptState      = 0x80000001,
    WHvRegisterPendingEvent        = 0x80000002,
    WHvX64RegisterDeliverabilityNotifications = 0x80000004,
    WHvRegisterInternalActivityState = 0x80000005,
    WHvX64RegisterPendingDebugException = 0x80000006,

} WHV_REGISTER_NAME;

typedef union DECLSPEC_ALIGN(16) WHV_UINT128
{
    struct
    {
        UINT64  Low64;
        UINT64  High64;
    };

    UINT32  Dword[4];
} WHV_UINT128;

C_ASSERT(sizeof(WHV_UINT128) == 16);

typedef union WHV_X64_FP_REGISTER
{
    struct
    {
        UINT64 Mantissa;
        UINT64 BiasedExponent:15;
        UINT64 Sign:1;
        UINT64 Reserved:48;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_FP_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_REGISTER) == 16);

typedef union WHV_X64_FP_CONTROL_STATUS_REGISTER
{
    struct
    {
        UINT16 FpControl;
        UINT16 FpStatus;
        UINT8  FpTag;
        UINT8  Reserved;
        UINT16 LastFpOp;
        union
        {
            // Long Mode
            UINT64 LastFpRip;

            // 32 Bit Mode
            struct
            {
                UINT32 LastFpEip;
                UINT16 LastFpCs;
                UINT16 Reserved2;
            };
        };
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_FP_CONTROL_STATUS_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_CONTROL_STATUS_REGISTER) == 16);

typedef union WHV_X64_XMM_CONTROL_STATUS_REGISTER
{
    struct
    {
        union
        {
            // Long Mode
            UINT64 LastFpRdp;

            // 32 Bit Mode
            struct
            {
                UINT32 LastFpDp;
                UINT16 LastFpDs;
                UINT16 Reserved;
            };
        };
        UINT32 XmmStatusControl;
        UINT32 XmmStatusControlMask;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_XMM_CONTROL_STATUS_REGISTER;

C_ASSERT(sizeof(WHV_X64_FP_CONTROL_STATUS_REGISTER) == 16);

typedef struct WHV_X64_SEGMENT_REGISTER
{
    UINT64 Base;
    UINT32 Limit;
    UINT16 Selector;

    union
    {
        struct
        {
            UINT16 SegmentType:4;
            UINT16 NonSystemSegment:1;
            UINT16 DescriptorPrivilegeLevel:2;
            UINT16 Present:1;
            UINT16 Reserved:4;
            UINT16 Available:1;
            UINT16 Long:1;
            UINT16 Default:1;
            UINT16 Granularity:1;
        };

        UINT16 Attributes;
    };
} WHV_X64_SEGMENT_REGISTER;

C_ASSERT(sizeof(WHV_X64_SEGMENT_REGISTER) == 16);

typedef struct WHV_X64_TABLE_REGISTER
{
    UINT16     Pad[3];
    UINT16     Limit;
    UINT64     Base;
} WHV_X64_TABLE_REGISTER;

C_ASSERT(sizeof(WHV_X64_TABLE_REGISTER) == 16);

typedef union WHV_X64_INTERRUPT_STATE_REGISTER
{
    struct
    {
        UINT64 InterruptShadow:1;
        UINT64 NmiMasked:1;
        UINT64 Reserved:62;
    };

    UINT64 AsUINT64;
} WHV_X64_INTERRUPT_STATE_REGISTER;

C_ASSERT(sizeof(WHV_X64_INTERRUPT_STATE_REGISTER) == 8);

typedef union WHV_X64_PENDING_INTERRUPTION_REGISTER
{
    struct
    {
        UINT32 InterruptionPending:1;
        UINT32 InterruptionType:3;  // WHV_X64_PENDING_INTERRUPTION_TYPE
        UINT32 DeliverErrorCode:1;
        UINT32 InstructionLength:4;
        UINT32 NestedEvent:1;
        UINT32 Reserved:6;
        UINT32 InterruptionVector:16;
        UINT32 ErrorCode;
    };

    UINT64 AsUINT64;
} WHV_X64_PENDING_INTERRUPTION_REGISTER;

C_ASSERT(sizeof(WHV_X64_PENDING_INTERRUPTION_REGISTER) == 8);

typedef union WHV_X64_DELIVERABILITY_NOTIFICATIONS_REGISTER
{
    struct
    {
        UINT64 NmiNotification:1;
        UINT64 InterruptNotification:1;
        UINT64 InterruptPriority:4;
        UINT64 Reserved:42;
        UINT64 Sint:16;
    };

    UINT64 AsUINT64;
} WHV_X64_DELIVERABILITY_NOTIFICATIONS_REGISTER;

C_ASSERT(sizeof(WHV_X64_DELIVERABILITY_NOTIFICATIONS_REGISTER) == 8);

typedef enum WHV_X64_PENDING_EVENT_TYPE
{
    WHvX64PendingEventException = 0,
    WHvX64PendingEventExtInt    = 5,
} WHV_X64_PENDING_EVENT_TYPE;

typedef union WHV_X64_PENDING_EXCEPTION_EVENT
{
    struct
    {
        UINT32 EventPending         : 1;
        UINT32 EventType            : 3; // Must be WHvX64PendingEventException
        UINT32 Reserved0            : 4;

        UINT32 DeliverErrorCode     : 1;
        UINT32 Reserved1            : 7;
        UINT32 Vector               : 16;
        UINT32 ErrorCode;
        UINT64 ExceptionParameter;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_EXCEPTION_EVENT;

C_ASSERT(sizeof(WHV_X64_PENDING_EXCEPTION_EVENT) == 16);

typedef union WHV_X64_PENDING_EXT_INT_EVENT
{
    struct
    {
        UINT64 EventPending     : 1;
        UINT64 EventType        : 3; // Must be WHvX64PendingEventExtInt
        UINT64 Reserved0        : 4;
        UINT64 Vector           : 8;
        UINT64 Reserved1        : 48;

        UINT64 Reserved2;
    };

    WHV_UINT128 AsUINT128;
} WHV_X64_PENDING_EXT_INT_EVENT;

C_ASSERT(sizeof(WHV_X64_PENDING_EXT_INT_EVENT) == 16);

typedef union WHV_INTERNAL_ACTIVITY_REGISTER
{
    struct
    {
        UINT64 StartupSuspend : 1;
        UINT64 HaltSuspend : 1;
        UINT64 IdleSuspend : 1;
        UINT64 Reserved:61;
    };

    UINT64 AsUINT64;
} WHV_INTERNAL_ACTIVITY_REGISTER;

C_ASSERT(sizeof(WHV_INTERNAL_ACTIVITY_REGISTER) == 8);

typedef union WHV_X64_PENDING_DEBUG_EXCEPTION
{
    UINT64 AsUINT64;

    struct
    {
        UINT64 Breakpoint0 : 1;
        UINT64 Breakpoint1 : 1;
        UINT64 Breakpoint2 : 1;
        UINT64 Breakpoint3 : 1;
        UINT64 SingleStep : 1;
        UINT64 Reserved0 : 59;
    };

} WHV_X64_PENDING_DEBUG_EXCEPTION;

C_ASSERT(sizeof(WHV_X64_PENDING_DEBUG_EXCEPTION) == 8);

typedef struct WHV_SYNIC_SINT_DELIVERABLE_CONTEXT
{
    UINT16 DeliverableSints;
    UINT16 Reserved1;
    UINT32 Reserved2;
} WHV_SYNIC_SINT_DELIVERABLE_CONTEXT;

C_ASSERT(sizeof(WHV_SYNIC_SINT_DELIVERABLE_CONTEXT) == 8);

//
// Register values
//
typedef union WHV_REGISTER_VALUE
{
    WHV_UINT128 Reg128;
    UINT64 Reg64;
    UINT32 Reg32;
    UINT16 Reg16;
    UINT8 Reg8;
    WHV_X64_FP_REGISTER Fp;
    WHV_X64_FP_CONTROL_STATUS_REGISTER FpControlStatus;
    WHV_X64_XMM_CONTROL_STATUS_REGISTER XmmControlStatus;
    WHV_X64_SEGMENT_REGISTER Segment;
    WHV_X64_TABLE_REGISTER Table;
    WHV_X64_INTERRUPT_STATE_REGISTER InterruptState;
    WHV_X64_PENDING_INTERRUPTION_REGISTER PendingInterruption;
    WHV_X64_DELIVERABILITY_NOTIFICATIONS_REGISTER DeliverabilityNotifications;
    WHV_X64_PENDING_EXCEPTION_EVENT ExceptionEvent;
    WHV_X64_PENDING_EXT_INT_EVENT ExtIntEvent;
    WHV_INTERNAL_ACTIVITY_REGISTER InternalActivity;
    WHV_X64_PENDING_DEBUG_EXCEPTION PendingDebugException;
} WHV_REGISTER_VALUE;

C_ASSERT(sizeof(WHV_REGISTER_VALUE) == 16);

//
// Virtual Processor Execution
//

//
// Reason for a VM exit
//
typedef enum WHV_RUN_VP_EXIT_REASON
{
    WHvRunVpExitReasonNone                   = 0x00000000,

    // Standard exits caused by operations of the virtual processor
    WHvRunVpExitReasonMemoryAccess           = 0x00000001,
    WHvRunVpExitReasonX64IoPortAccess        = 0x00000002,
    WHvRunVpExitReasonUnrecoverableException = 0x00000004,
    WHvRunVpExitReasonInvalidVpRegisterValue = 0x00000005,
    WHvRunVpExitReasonUnsupportedFeature     = 0x00000006,
    WHvRunVpExitReasonX64InterruptWindow     = 0x00000007,
    WHvRunVpExitReasonX64Halt                = 0x00000008,
    WHvRunVpExitReasonX64ApicEoi             = 0x00000009,
    WHvRunVpExitReasonSynicSintDeliverable   = 0x0000000A,

    // Additional exits that can be configured through partition properties
    WHvRunVpExitReasonX64MsrAccess           = 0x00001000,
    WHvRunVpExitReasonX64Cpuid               = 0x00001001,
    WHvRunVpExitReasonException              = 0x00001002,
    WHvRunVpExitReasonX64Rdtsc               = 0x00001003,
    WHvRunVpExitReasonX64ApicSmiTrap         = 0x00001004,
    WHvRunVpExitReasonHypercall              = 0x00001005,
    WHvRunVpExitReasonX64ApicInitSipiTrap    = 0x00001006,
    WHvRunVpExitReasonX64ApicWriteTrap       = 0x00001007,

    // Exits caused by the host
    WHvRunVpExitReasonCanceled               = 0x00002001,
} WHV_RUN_VP_EXIT_REASON;

//
// Execution state of the virtual processor
//
typedef union WHV_X64_VP_EXECUTION_STATE
{
    struct
    {
        UINT16 Cpl : 2;
        UINT16 Cr0Pe : 1;
        UINT16 Cr0Am : 1;
        UINT16 EferLma : 1;
        UINT16 DebugActive : 1;
        UINT16 InterruptionPending : 1;
        UINT16 Reserved0 : 5;
        UINT16 InterruptShadow : 1;
        UINT16 Reserved1 : 3;
    };

    UINT16 AsUINT16;
} WHV_X64_VP_EXECUTION_STATE;

C_ASSERT(sizeof(WHV_X64_VP_EXECUTION_STATE) == 2);

//
// Execution context of a virtual processor at the time of an exit
//
typedef struct WHV_VP_EXIT_CONTEXT
{
    WHV_X64_VP_EXECUTION_STATE ExecutionState;
    UINT8 InstructionLength : 4;
    UINT8 Cr8 : 4;
    UINT8 Reserved;
    UINT32 Reserved2;
    WHV_X64_SEGMENT_REGISTER Cs;
    UINT64 Rip;
    UINT64 Rflags;
} WHV_VP_EXIT_CONTEXT;

C_ASSERT(sizeof(WHV_VP_EXIT_CONTEXT) == 40);

//
// Context data for a VM exit caused by a memory access (WHvRunVpExitReasonMemoryAccess)
//

typedef union WHV_MEMORY_ACCESS_INFO
{
    struct {
        UINT32 AccessType  : 2;  // WHV_MEMORY_ACCESS_TYPE
        UINT32 GpaUnmapped : 1;
        UINT32 GvaValid    : 1;
        UINT32 Reserved    : 28;
    };

    UINT32 AsUINT32;
} WHV_MEMORY_ACCESS_INFO;

C_ASSERT(sizeof(WHV_MEMORY_ACCESS_INFO) == 4);

typedef struct WHV_MEMORY_ACCESS_CONTEXT
{
    // Context of the virtual processor
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // Memory access info
    WHV_MEMORY_ACCESS_INFO AccessInfo;
    WHV_GUEST_PHYSICAL_ADDRESS Gpa;
    WHV_GUEST_VIRTUAL_ADDRESS Gva;
} WHV_MEMORY_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_MEMORY_ACCESS_CONTEXT) == 40);

//
// Context data for an exit caused by an I/O port access (WHvRunVpExitReasonX64IOPortAccess)
//
typedef union WHV_X64_IO_PORT_ACCESS_INFO
{
    struct
    {
        UINT32 IsWrite : 1;
        UINT32 AccessSize: 3;
        UINT32 StringOp : 1;
        UINT32 RepPrefix : 1;
        UINT32 Reserved : 26;
    };

    UINT32 AsUINT32;
} WHV_X64_IO_PORT_ACCESS_INFO;

C_ASSERT(sizeof(WHV_X64_IO_PORT_ACCESS_INFO) == 4);

typedef struct WHV_X64_IO_PORT_ACCESS_CONTEXT
{
    // Context of the virtual processor
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // I/O port access info
    WHV_X64_IO_PORT_ACCESS_INFO AccessInfo;
    UINT16 PortNumber;
    UINT16 Reserved2[3];
    UINT64 Rax;
    UINT64 Rcx;
    UINT64 Rsi;
    UINT64 Rdi;
    WHV_X64_SEGMENT_REGISTER Ds;
    WHV_X64_SEGMENT_REGISTER Es;
} WHV_X64_IO_PORT_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_IO_PORT_ACCESS_CONTEXT) == 96);

//
// Context data for an exit caused by an MSR access (WHvRunVpExitReasonX64MSRAccess)
//
typedef union WHV_X64_MSR_ACCESS_INFO
{
    struct
    {
        UINT32 IsWrite : 1;
        UINT32 Reserved : 31;
    };

    UINT32 AsUINT32;
} WHV_X64_MSR_ACCESS_INFO;

C_ASSERT(sizeof(WHV_X64_MSR_ACCESS_INFO) == 4);

typedef struct WHV_X64_MSR_ACCESS_CONTEXT
{
    // MSR access info
    WHV_X64_MSR_ACCESS_INFO AccessInfo;
    UINT32 MsrNumber;
    UINT64 Rax;
    UINT64 Rdx;
} WHV_X64_MSR_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_MSR_ACCESS_CONTEXT) == 24);

//
// Context data for an exit caused by a CPUID call (WHvRunVpExitReasonX64CPUID)
//
typedef struct WHV_X64_CPUID_ACCESS_CONTEXT
{
    // CPUID access info
    UINT64 Rax;
    UINT64 Rcx;
    UINT64 Rdx;
    UINT64 Rbx;
    UINT64 DefaultResultRax;
    UINT64 DefaultResultRcx;
    UINT64 DefaultResultRdx;
    UINT64 DefaultResultRbx;
} WHV_X64_CPUID_ACCESS_CONTEXT;

C_ASSERT(sizeof(WHV_X64_CPUID_ACCESS_CONTEXT) == 64);

//
// Context data for an exit caused by an exception generated by the virtual processor
// (WHvRunVpExitReasonException)
//
typedef union WHV_VP_EXCEPTION_INFO
{
    struct
    {
        UINT32 ErrorCodeValid : 1;
        UINT32 SoftwareException : 1;
        UINT32 Reserved : 30;
    };

    UINT32 AsUINT32;
} WHV_VP_EXCEPTION_INFO;

C_ASSERT(sizeof(WHV_VP_EXCEPTION_INFO) == 4);

typedef struct WHV_VP_EXCEPTION_CONTEXT
{
    UINT8 InstructionByteCount;
    UINT8 Reserved[3];
    UINT8 InstructionBytes[16];

    // Exception info
    WHV_VP_EXCEPTION_INFO ExceptionInfo;
    UINT8 ExceptionType; // WHV_EXCEPTION_TYPE
    UINT8 Reserved2[3];
    UINT32 ErrorCode;
    UINT64 ExceptionParameter;
} WHV_VP_EXCEPTION_CONTEXT;

C_ASSERT(sizeof(WHV_VP_EXCEPTION_CONTEXT) == 40);

//
// Context data for an exit caused by the use of an unsupported processor feature
// (WHvRunVpExitReasonUnsupportedFeature)
//
typedef enum WHV_X64_UNSUPPORTED_FEATURE_CODE
{
    WHvUnsupportedFeatureIntercept     = 1,
    WHvUnsupportedFeatureTaskSwitchTss = 2
} WHV_X64_UNSUPPORTED_FEATURE_CODE;

typedef struct WHV_X64_UNSUPPORTED_FEATURE_CONTEXT
{
    WHV_X64_UNSUPPORTED_FEATURE_CODE FeatureCode;
    UINT32 Reserved;
    UINT64 FeatureParameter;
} WHV_X64_UNSUPPORTED_FEATURE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_UNSUPPORTED_FEATURE_CONTEXT) == 16);

//
// Context data for an exit caused by a cancellation from the host (WHvRunVpExitReasonCanceled)
//
typedef enum WHV_RUN_VP_CANCEL_REASON
{
    WHvRunVpCancelReasonUser = 0 // Execution canceled by WHvCancelRunVirtualProcessor
} WHV_RUN_VP_CANCEL_REASON;

//
// Alias for non-standard capitalization found in earlier versions of the header
//
#define WhvRunVpCancelReasonUser WHvRunVpCancelReasonUser

typedef struct WHV_RUN_VP_CANCELED_CONTEXT
{
    WHV_RUN_VP_CANCEL_REASON CancelReason;
} WHV_RUN_VP_CANCELED_CONTEXT;

C_ASSERT(sizeof(WHV_RUN_VP_CANCELED_CONTEXT) == 4);

//
// Context data for an exit caused by an interrupt delivery window cancellation from the host
// (WHvRunVpExitReasonX64InterruptWindow)
//
typedef enum WHV_X64_PENDING_INTERRUPTION_TYPE
{
    WHvX64PendingInterrupt           = 0,
    WHvX64PendingNmi                 = 2,
    WHvX64PendingException           = 3
} WHV_X64_PENDING_INTERRUPTION_TYPE, *PWHV_X64_PENDING_INTERRUPTION_TYPE;

typedef struct WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT
{
    WHV_X64_PENDING_INTERRUPTION_TYPE DeliverableType;
} WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT, *PWHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT) == 4);

//
// Context data for an exit caused by an APIC EOI of a level-triggered
// interrupt (WHvRunVpExitReasonX64ApicEoi)
//
typedef struct WHV_X64_APIC_EOI_CONTEXT
{
    UINT32 InterruptVector;
} WHV_X64_APIC_EOI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_EOI_CONTEXT) == 4);

//
// Context data for an exit caused by a rdtsc(p) instruction (WHvRunVpExitReasonX64Rdtsc)
//
typedef union WHV_X64_RDTSC_INFO
{
    struct
    {
        UINT64 IsRdtscp:1;
        UINT64 Reserved:63;
    };

    UINT64 AsUINT64;
} WHV_X64_RDTSC_INFO;

C_ASSERT(sizeof(WHV_X64_RDTSC_INFO) == 8);

typedef struct WHV_X64_RDTSC_CONTEXT
{
    UINT64 TscAux;
    UINT64 VirtualOffset;
    UINT64 Tsc;
    UINT64 ReferenceTime;
    WHV_X64_RDTSC_INFO RdtscInfo;
} WHV_X64_RDTSC_CONTEXT;

C_ASSERT(sizeof(WHV_X64_RDTSC_CONTEXT) == 40);

//
// Context data for an exit caused by an APIC SMI (WHvRunVpExitReasonX64ApicSmiTrap)
//
typedef struct WHV_X64_APIC_SMI_CONTEXT
{
    UINT64 ApicIcr;
} WHV_X64_APIC_SMI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_SMI_CONTEXT) == 8);

//
// Context data for an exit caused by a hypercall (WHvRunVpExitReasonHypercall)
//

#define WHV_HYPERCALL_CONTEXT_MAX_XMM_REGISTERS 6

typedef struct WHV_HYPERCALL_CONTEXT
{
    UINT64 Rax;
    UINT64 Rbx;
    UINT64 Rcx;
    UINT64 Rdx;
    UINT64 R8;
    UINT64 Rsi;
    UINT64 Rdi;
    UINT64 Reserved0;
    WHV_UINT128 XmmRegisters[WHV_HYPERCALL_CONTEXT_MAX_XMM_REGISTERS];
    UINT64 Reserved1[2];
} WHV_HYPERCALL_CONTEXT, *PWHV_HYPERCALL_CONTEXT;

C_ASSERT(sizeof(WHV_HYPERCALL_CONTEXT) == 176);

//
// Context data for an exit caused by an APIC INIT SIPI (WHvRunVpExitReasonX64ApicInitSipiTrap)
//
typedef struct WHV_X64_APIC_INIT_SIPI_CONTEXT
{
    UINT64 ApicIcr;
} WHV_X64_APIC_INIT_SIPI_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_INIT_SIPI_CONTEXT) == 8);

//
// Types of APIC write exits (WHvRunVpExitReasonX64ApicWriteTrap)
//
typedef enum WHV_X64_APIC_WRITE_TYPE
{
    WHvX64ApicWriteTypeLdr   = 0xD0,
    WHvX64ApicWriteTypeDfr   = 0xE0,
    WHvX64ApicWriteTypeSvr   = 0xF0,
    WHvX64ApicWriteTypeLint0 = 0x350,
    WHvX64ApicWriteTypeLint1 = 0x360
} WHV_X64_APIC_WRITE_TYPE;

//
// Context data for an exit caused by an APIC write (WHvRunVpExitReasonX64ApicWriteTrap)
//
typedef struct WHV_X64_APIC_WRITE_CONTEXT
{
    WHV_X64_APIC_WRITE_TYPE Type;
    UINT32 Reserved;
    UINT64 WriteValue;
} WHV_X64_APIC_WRITE_CONTEXT;

C_ASSERT(sizeof(WHV_X64_APIC_WRITE_CONTEXT) == 16);

// WHvRunVirtualProcessor output buffer
typedef struct WHV_RUN_VP_EXIT_CONTEXT
{
    WHV_RUN_VP_EXIT_REASON ExitReason;
    UINT32 Reserved;
    WHV_VP_EXIT_CONTEXT VpContext;

    union
    {
        WHV_MEMORY_ACCESS_CONTEXT MemoryAccess;
        WHV_X64_IO_PORT_ACCESS_CONTEXT IoPortAccess;
        WHV_X64_MSR_ACCESS_CONTEXT MsrAccess;
        WHV_X64_CPUID_ACCESS_CONTEXT CpuidAccess;
        WHV_VP_EXCEPTION_CONTEXT VpException;
        WHV_X64_INTERRUPTION_DELIVERABLE_CONTEXT InterruptWindow;
        WHV_X64_UNSUPPORTED_FEATURE_CONTEXT UnsupportedFeature;
        WHV_RUN_VP_CANCELED_CONTEXT CancelReason;
        WHV_X64_APIC_EOI_CONTEXT ApicEoi;
        WHV_X64_RDTSC_CONTEXT ReadTsc;
        WHV_X64_APIC_SMI_CONTEXT ApicSmi;
        WHV_HYPERCALL_CONTEXT Hypercall;
        WHV_X64_APIC_INIT_SIPI_CONTEXT ApicInitSipi;
        WHV_X64_APIC_WRITE_CONTEXT ApicWrite;
        WHV_SYNIC_SINT_DELIVERABLE_CONTEXT SynicSintDeliverable;
    };
} WHV_RUN_VP_EXIT_CONTEXT;

C_ASSERT(sizeof(WHV_RUN_VP_EXIT_CONTEXT) == 224);

typedef enum WHV_INTERRUPT_TYPE
{
    WHvX64InterruptTypeFixed            = 0,
    WHvX64InterruptTypeLowestPriority   = 1,
    WHvX64InterruptTypeNmi              = 4,
    WHvX64InterruptTypeInit             = 5,
    WHvX64InterruptTypeSipi             = 6,
    WHvX64InterruptTypeLocalInt1        = 9,
} WHV_INTERRUPT_TYPE;

typedef enum WHV_INTERRUPT_DESTINATION_MODE
{
    WHvX64InterruptDestinationModePhysical,
    WHvX64InterruptDestinationModeLogical,
} WHV_INTERRUPT_DESTINATION_MODE;

typedef enum WHV_INTERRUPT_TRIGGER_MODE
{
    WHvX64InterruptTriggerModeEdge,
    WHvX64InterruptTriggerModeLevel,
} WHV_INTERRUPT_TRIGGER_MODE;

typedef struct WHV_INTERRUPT_CONTROL
{
    UINT64 Type : 8;             // WHV_INTERRUPT_TYPE
    UINT64 DestinationMode : 4;  // WHV_INTERRUPT_DESTINATION_MODE
    UINT64 TriggerMode : 4;      // WHV_INTERRUPT_TRIGGER_MODE
    UINT64 Reserved : 48;
    UINT32 Destination;
    UINT32 Vector;
} WHV_INTERRUPT_CONTROL;

C_ASSERT(sizeof(WHV_INTERRUPT_CONTROL) == 16);

typedef struct WHV_DOORBELL_MATCH_DATA
{
    WHV_GUEST_PHYSICAL_ADDRESS GuestAddress;
    UINT64 Value;
    UINT32 Length;
    UINT32 MatchOnValue:1;
    UINT32 MatchOnLength:1;
    UINT32 Reserved:30;
} WHV_DOORBELL_MATCH_DATA;

C_ASSERT(sizeof(WHV_DOORBELL_MATCH_DATA) == 24);

// WHvGetPartitionCounters types
typedef enum WHV_PARTITION_COUNTER_SET
{
    WHvPartitionCounterSetMemory,
} WHV_PARTITION_COUNTER_SET;

typedef struct WHV_PARTITION_MEMORY_COUNTERS
{
    UINT64 Mapped4KPageCount;
    UINT64 Mapped2MPageCount;
    UINT64 Mapped1GPageCount;
} WHV_PARTITION_MEMORY_COUNTERS;

C_ASSERT(sizeof(WHV_PARTITION_MEMORY_COUNTERS) == 24);

// WHvGetVirtualProcessorCounters types
typedef enum WHV_PROCESSOR_COUNTER_SET
{
    WHvProcessorCounterSetRuntime,
    WHvProcessorCounterSetIntercepts,
    WHvProcessorCounterSetEvents,
    WHvProcessorCounterSetApic,
    WHvProcessorCounterSetSyntheticFeatures,
} WHV_PROCESSOR_COUNTER_SET;

typedef struct WHV_PROCESSOR_RUNTIME_COUNTERS
{
    UINT64 TotalRuntime100ns;
    UINT64 HypervisorRuntime100ns;
} WHV_PROCESSOR_RUNTIME_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_RUNTIME_COUNTERS) == 16);

typedef struct WHV_PROCESSOR_INTERCEPT_COUNTER
{
    UINT64 Count;
    UINT64 Time100ns;
} WHV_PROCESSOR_INTERCEPT_COUNTER;

C_ASSERT(sizeof(WHV_PROCESSOR_INTERCEPT_COUNTER) == 16);

typedef struct WHV_PROCESSOR_INTERCEPT_COUNTERS
{
    WHV_PROCESSOR_INTERCEPT_COUNTER PageInvalidations;
    WHV_PROCESSOR_INTERCEPT_COUNTER ControlRegisterAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER IoInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER HaltInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER CpuidInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER MsrAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER OtherIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER PendingInterrupts;
    WHV_PROCESSOR_INTERCEPT_COUNTER EmulatedInstructions;
    WHV_PROCESSOR_INTERCEPT_COUNTER DebugRegisterAccesses;
    WHV_PROCESSOR_INTERCEPT_COUNTER PageFaultIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER NestedPageFaultIntercepts;
    WHV_PROCESSOR_INTERCEPT_COUNTER Hypercalls;
    WHV_PROCESSOR_INTERCEPT_COUNTER RdpmcInstructions;
} WHV_PROCESSOR_ACTIVITY_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_ACTIVITY_COUNTERS) == 224);

typedef struct WHV_PROCESSOR_EVENT_COUNTERS
{
    UINT64 PageFaultCount;
    UINT64 ExceptionCount;
    UINT64 InterruptCount;
} WHV_PROCESSOR_GUEST_EVENT_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_GUEST_EVENT_COUNTERS) == 24);

typedef struct WHV_PROCESSOR_APIC_COUNTERS
{
    UINT64 MmioAccessCount;
    UINT64 EoiAccessCount;
    UINT64 TprAccessCount;
    UINT64 SentIpiCount;
    UINT64 SelfIpiCount;
} WHV_PROCESSOR_APIC_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_APIC_COUNTERS) == 40);

typedef struct WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS
{
    UINT64 SyntheticInterruptsCount;
    UINT64 LongSpinWaitHypercallsCount;
    UINT64 OtherHypercallsCount;
    UINT64 SyntheticInterruptHypercallsCount;
    UINT64 VirtualInterruptHypercallsCount;
    UINT64 VirtualMmuHypercallsCount;
} WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS;

C_ASSERT(sizeof(WHV_PROCESSOR_SYNTHETIC_FEATURES_COUNTERS) == 48);

// WHvAdviseGpaRange types
typedef enum WHV_ADVISE_GPA_RANGE_CODE
{
    WHvAdviseGpaRangeCodePopulate         = 0x00000000,
    WHvAdviseGpaRangeCodePin              = 0x00000001,
    WHvAdviseGpaRangeCodeUnpin            = 0x00000002,
} WHV_ADVISE_GPA_RANGE_CODE;

// WHvGetVirtualProcessorState and WHvSetVirtualProcessorState types.
typedef enum WHV_VIRTUAL_PROCESSOR_STATE_TYPE
{
    WHvVirtualProcessorStateTypeSynicMessagePage          = 0x00000000,
    WHvVirtualProcessorStateTypeSynicEventFlagPage        = 0x00000001,
    WHvVirtualProcessorStateTypeSynicTimerState           = 0x00000002,

    WHvVirtualProcessorStateTypeInterruptControllerState2 = 0x00001000,
    WHvVirtualProcessorStateTypeXsaveState                = 0x00001001,
} WHV_VIRTUAL_PROCESSOR_STATE_TYPE;

//
// Synic definitions
//

typedef struct WHV_SYNIC_EVENT_PARAMETERS
{
    UINT32 VpIndex;
    UINT8 TargetSint;
    UINT8 Reserved;
    UINT16 FlagNumber;
} WHV_SYNIC_EVENT_PARAMETERS;

C_ASSERT(sizeof(WHV_SYNIC_EVENT_PARAMETERS) == 8);

//
// Virtual PCI type definitions.
//

typedef enum WHV_ALLOCATE_VPCI_RESOURCE_FLAGS
{
    WHvAllocateVpciResourceFlagNone = 0x00000000,
    WHvAllocateVpciResourceFlagAllowDirectP2P = 0x00000001

} WHV_ALLOCATE_VPCI_RESOURCE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_ALLOCATE_VPCI_RESOURCE_FLAGS);

#define WHV_MAX_DEVICE_ID_SIZE_IN_CHARS 200 // PnP manager limit

typedef struct WHV_SRIOV_RESOURCE_DESCRIPTOR
{
    WCHAR PnpInstanceId[WHV_MAX_DEVICE_ID_SIZE_IN_CHARS];
    LUID VirtualFunctionId;
    UINT16 VirtualFunctionIndex;
    UINT16 Reserved;

} WHV_SRIOV_RESOURCE_DESCRIPTOR;

C_ASSERT(sizeof(WHV_SRIOV_RESOURCE_DESCRIPTOR) == 412);

typedef enum WHV_VPCI_DEVICE_NOTIFICATION_TYPE
{
    WHvVpciDeviceNotificationUndefined = 0,
    WHvVpciDeviceNotificationMmioRemapping = 1,
    WHvVpciDeviceNotificationSurpriseRemoval = 2

} WHV_VPCI_DEVICE_NOTIFICATION_TYPE;

typedef struct WHV_VPCI_DEVICE_NOTIFICATION
{
    WHV_VPCI_DEVICE_NOTIFICATION_TYPE NotificationType;
    UINT32 Reserved1;
    union
    {
        UINT64 Reserved2;
    };

} WHV_VPCI_DEVICE_NOTIFICATION;

C_ASSERT(sizeof(WHV_VPCI_DEVICE_NOTIFICATION) == 16);

typedef enum WHV_CREATE_VPCI_DEVICE_FLAGS
{
    WHvCreateVpciDeviceFlagNone = 0x00000000,
    WHvCreateVpciDeviceFlagPhysicallyBacked = 0x00000001,
    WHvCreateVpciDeviceFlagUseLogicalInterrupts = 0x00000002

} WHV_CREATE_VPCI_DEVICE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_CREATE_VPCI_DEVICE_FLAGS);

typedef enum WHV_VPCI_DEVICE_PROPERTY_CODE
{
    WHvVpciDevicePropertyCodeUndefined   = 0,
    WHvVpciDevicePropertyCodeHardwareIDs = 1,
    WHvVpciDevicePropertyCodeProbedBARs  = 2

} WHV_VPCI_DEVICE_PROPERTY_CODE;

typedef struct WHV_VPCI_HARDWARE_IDS
{
    UINT16 VendorID;
    UINT16 DeviceID;
    UINT8 RevisionID;
    UINT8 ProgIf;
    UINT8 SubClass;
    UINT8 BaseClass;
    UINT16 SubVendorID;
    UINT16 SubSystemID;

} WHV_VPCI_HARDWARE_IDS;

C_ASSERT(sizeof(WHV_VPCI_HARDWARE_IDS) == 12);

#define WHV_VPCI_TYPE0_BAR_COUNT 6

typedef struct WHV_VPCI_PROBED_BARS
{
    UINT32 Value[WHV_VPCI_TYPE0_BAR_COUNT];

} WHV_VPCI_PROBED_BARS;

C_ASSERT(sizeof(WHV_VPCI_PROBED_BARS) == 24);

typedef enum WHV_VPCI_MMIO_RANGE_FLAGS
{
    WHvVpciMmioRangeFlagReadAccess = 0x00000001,
    WHvVpciMmioRangeFlagWriteAccess = 0x00000002

} WHV_VPCI_MMIO_RANGE_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_VPCI_MMIO_RANGE_FLAGS);

typedef enum WHV_VPCI_DEVICE_REGISTER_SPACE
{
    WHvVpciConfigSpace = -1,
    WHvVpciBar0 = 0,
    WHvVpciBar1 = 1,
    WHvVpciBar2 = 2,
    WHvVpciBar3 = 3,
    WHvVpciBar4 = 4,
    WHvVpciBar5 = 5

} WHV_VPCI_DEVICE_REGISTER_SPACE;

typedef struct WHV_VPCI_MMIO_MAPPING
{
    WHV_VPCI_DEVICE_REGISTER_SPACE Location;
    WHV_VPCI_MMIO_RANGE_FLAGS Flags;
    UINT64 SizeInBytes;
    UINT64 OffsetInBytes;
    PVOID VirtualAddress;

} WHV_VPCI_MMIO_MAPPING;

C_ASSERT(sizeof(WHV_VPCI_MMIO_MAPPING) == 32);

typedef struct WHV_VPCI_DEVICE_REGISTER
{
    WHV_VPCI_DEVICE_REGISTER_SPACE Location;
    UINT32 SizeInBytes;
    UINT64 OffsetInBytes;

} WHV_VPCI_DEVICE_REGISTER;

C_ASSERT(sizeof(WHV_VPCI_DEVICE_REGISTER) == 16);

typedef enum WHV_VPCI_INTERRUPT_TARGET_FLAGS
{
    WHvVpciInterruptTargetFlagNone      = 0x00000000,
    WHvVpciInterruptTargetFlagMulticast = 0x00000001,

} WHV_VPCI_INTERRUPT_TARGET_FLAGS;

DEFINE_ENUM_FLAG_OPERATORS(WHV_VPCI_INTERRUPT_TARGET_FLAGS);

typedef struct WHV_VPCI_INTERRUPT_TARGET
{
    UINT32 Vector;
    WHV_VPCI_INTERRUPT_TARGET_FLAGS Flags;
    UINT32 ProcessorCount;
    UINT32 Processors[ANYSIZE_ARRAY];

} WHV_VPCI_INTERRUPT_TARGET;

C_ASSERT(sizeof(WHV_VPCI_INTERRUPT_TARGET) == 16);

//
// Triggers
//

typedef enum WHV_TRIGGER_TYPE
{
    WHvTriggerTypeInterrupt = 0,
    WHvTriggerTypeSynicEvent = 1,
    WHvTriggerTypeDeviceInterrupt = 2,
} WHV_TRIGGER_TYPE;

typedef struct WHV_TRIGGER_PARAMETERS
{
    WHV_TRIGGER_TYPE TriggerType;
    UINT32 Reserved;
    union
    {
        WHV_INTERRUPT_CONTROL Interrupt;
        WHV_SYNIC_EVENT_PARAMETERS SynicEvent;
        struct
        {
            UINT64 LogicalDeviceId;
            UINT64 MsiAddress;
            UINT32 MsiData;
            UINT32 Reserved;
        } DeviceInterrupt;
    };
} WHV_TRIGGER_PARAMETERS;

C_ASSERT(sizeof(WHV_TRIGGER_PARAMETERS) == 32);

typedef PVOID WHV_TRIGGER_HANDLE;

typedef enum WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE
{
    WHvVirtualProcessorPropertyCodeNumaNode = 0x00000000,
} WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE;

typedef struct WHV_VIRTUAL_PROCESSOR_PROPERTY
{
    WHV_VIRTUAL_PROCESSOR_PROPERTY_CODE PropertyCode;
    UINT32 Reserved;
    union
    {
        USHORT NumaNode;
        UINT64 Padding;
    };
} WHV_VIRTUAL_PROCESSOR_PROPERTY;

C_ASSERT(sizeof(WHV_VIRTUAL_PROCESSOR_PROPERTY) == 16);

//
// Notification ports
//

typedef enum WHV_NOTIFICATION_PORT_TYPE
{
    WHvNotificationPortTypeEvent = 2,
    WHvNotificationPortTypeDoorbell = 4,
} WHV_NOTIFICATION_PORT_TYPE;

typedef struct WHV_NOTIFICATION_PORT_PARAMETERS
{
    WHV_NOTIFICATION_PORT_TYPE NotificationPortType;
    UINT32 Reserved;
    union
    {
        WHV_DOORBELL_MATCH_DATA Doorbell;
        struct
        {
            UINT32 ConnectionId;
        } Event;
    };

} WHV_NOTIFICATION_PORT_PARAMETERS;

C_ASSERT(sizeof(WHV_NOTIFICATION_PORT_PARAMETERS) == 32);

typedef enum WHV_NOTIFICATION_PORT_PROPERTY_CODE
{
    WHvNotificationPortPropertyPreferredTargetVp = 1,
    WHvNotificationPortPropertyPreferredTargetDuration = 5,
} WHV_NOTIFICATION_PORT_PROPERTY_CODE;

typedef UINT64 WHV_NOTIFICATION_PORT_PROPERTY;

//
// The preferred target VP defaults to any VP.
//

#define WHV_ANY_VP (0xFFFFFFFF)

//
// Define the maximum possible value for the preferred target duration.
//

#define WHV_NOTIFICATION_PORT_PREFERRED_DURATION_MAX (0xFFFFFFFFFFFFFFFFUI64)

typedef PVOID WHV_NOTIFICATION_PORT_HANDLE;

//
// Post message
//

#define WHV_SYNIC_MESSAGE_SIZE  256

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma warning(pop)
#endif

#endif // _WINHVAPIDEFS_H_
