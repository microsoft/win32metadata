

//
// Pointer size in bytes
//

#define SizeofPointer 0x4

//
// Process State Enumerated Type Values
//

#define ProcessInMemory 0x0
#define ProcessOutOfMemory 0x1
#define ProcessInTransition 0x2

//
// Thread State Enumerated Type Values
//

#define Initialized 0x0
#define Ready 0x1
#define Running 0x2
#define Standby 0x3
#define Terminated 0x4
#define Waiting 0x5

//
// Processor Mode Definitions
//

#define KernelMode 0x0
#define UserMode 0x1

//
// Wait Reason and Wait Type Enumerated Type Values
//

#define WrExecutive 0x0
#define WrDispatchInt 0x1f
#define WaitAny 0x1
#define WaitAll 0x0

//
// Apc State Structure Offset Definitions
//

#define AsApcListHead 0x0
#define AsProcess 0x10
#define AsKernelApcPending 0x15
#define AsUserApcPendingAll 0x16
#define KAPC_STATE_ANY_USER_APC_PENDING_MASK 0x3


//
// Apc Record Structure Offset Definitions
//

#define ArNormalRoutine 0x0
#define ArNormalContext 0x4
#define ArSystemArgument1 0x8
#define ArSystemArgument2 0xc
#define ArFlags 0x10
#define KAPC_RECORD_LENGTH 0x18
#define KAPC_RECORD_FLAGS_CHECK_ALERT 0x1


//
// Bug Check Code Definitions
//

#define APC_INDEX_MISMATCH 0x1
#define KERNEL_APC_PENDING_DURING_EXIT 0x20
#define ATTEMPTED_SWITCH_FROM_DPC 0xb8
#define DATA_BUS_ERROR 0x2e
#define DATA_COHERENCY_EXCEPTION 0x55
#define HAL1_INITIALIZATION_FAILED 0x61
#define INSTRUCTION_BUS_ERROR 0x2f
#define INSTRUCTION_COHERENCY_EXCEPTION 0x56
#define INTERRUPT_EXCEPTION_NOT_HANDLED 0x3d
#define INTERRUPT_UNWIND_ATTEMPTED 0x3c
#define INVALID_AFFINITY_SET 0x3
#define INVALID_DATA_ACCESS_TRAP 0x4
#define IRQL_GT_ZERO_AT_SYSTEM_SERVICE 0x4a
#define IRQL_NOT_LESS_OR_EQUAL 0xa
#define KMODE_EXCEPTION_NOT_HANDLED 0x1e
#define NMI_HARDWARE_FAILURE 0x80
#define NO_USER_MODE_CONTEXT 0xe
#define PAGE_FAULT_WITH_INTERRUPTS_OFF 0x49
#define PANIC_STACK_SWITCH 0x2b
#define SPIN_LOCK_INIT_FAILURE 0x81
#define SYSTEM_EXIT_OWNED_MUTEX 0x39
#define SYSTEM_SERVICE_EXCEPTION 0x3b
#define SYSTEM_UNWIND_PREVIOUS_USER 0x3a
#define TRAP_CAUSE_UNKNOWN 0x12
#define UNEXPECTED_KERNEL_MODE_TRAP 0x7f
#define HARDWARE_INTERRUPT_STORM 0xf2
#define RECURSIVE_MACHINE_CHECK 0xfb
#define RECURSIVE_NMI 0x111
#define KERNEL_SECURITY_CHECK_FAILURE 0x139
#define UNSUPPORTED_INSTRUCTION_MODE 0x151
#define BUGCHECK_CONTEXT_MODIFIER 0x80000000
#define INVALID_CALLBACK_STACK_ADDRESS 0x1cd
#define INVALID_KERNEL_STACK_ADDRESS 0x1ce

//
// Breakpoint type definitions
//

#define DBG_STATUS_CONTROL_C 0x1
#define STATUS_ASSERTION_FAILURE 0xc0000420

//
// Client Id Structure Offset Definitions
//

#define CidUniqueProcess 0x0
#define CidUniqueThread 0x4

//
// Exception Record Offset, Flag, and Enumerated Type Definitions
//

#define EXCEPTION_NONCONTINUABLE 0x1
#define EXCEPTION_UNWINDING 0x2
#define EXCEPTION_EXIT_UNWIND 0x4
#define EXCEPTION_STACK_INVALID 0x8
#define EXCEPTION_NESTED_CALL 0x10
#define EXCEPTION_TARGET_UNWIND 0x20
#define EXCEPTION_COLLIDED_UNWIND 0x40
#define EXCEPTION_UNWIND 0x66
#define EXCEPTION_EXECUTE_HANDLER 0x1
#define EXCEPTION_CONTINUE_SEARCH 0x0
#define EXCEPTION_CONTINUE_EXECUTION 0xffffffff

#define ExceptionContinueExecution 0x0
#define ExceptionContinueSearch 0x1
#define ExceptionNestedException 0x2
#define ExceptionCollidedUnwind 0x3

#define ErExceptionCode 0x0
#define ErExceptionFlags 0x4
#define ErExceptionRecord 0x8
#define ErExceptionAddress 0xc
#define ErNumberParameters 0x10
#define ErExceptionInformation 0x14
#define ExceptionRecordLength 0x50

//
// Fast Mutex Structure Offset Definitions
//

#define FmCount 0x0
#define FmOwner 0x4
#define FmContention 0x8
#define FmOldIrql 0x1c

//
// Interrupt Priority Request Level Definitions
//

#define PASSIVE_LEVEL 0x0
#define APC_LEVEL 0x1
#define DISPATCH_LEVEL 0x2
#define IPI_LEVEL 0xe
#define POWER_LEVEL 0xe
#define PROFILE_LEVEL 0xf
#define HIGH_LEVEL 0xf
#ifdef NT_UP
#define SYNCH_LEVEL 0x2
#else
#define SYNCH_LEVEL 0xc
#endif

//
// Large Integer Structure Offset Definitions
//

#define LiLowPart 0x0
#define LiHighPart 0x4

//
// List Entry Structure Offset Definitions
//

#define LsFlink 0x0
#define LsBlink 0x4

//
// String Structure Offset Definitions
//

#define StrLength 0x0
#define StrMaximumLength 0x2
#define StrBuffer 0x4

//
// System DLL Init Block Structure Offset Definitions
//

#define IbCfgBitMap 0xb8
#define IbWow64CfgBitMap 0xc8
#define IbMitigationOptionsMap 0xa0
#define PS_MITIGATION_OPTION_BITS_PER_OPTION 0x4
#define PS_MITIGATION_OPTION_ALWAYS_ON 0x1
#define PS_MITIGATION_OPTION_ALWAYS_OFF 0x2
#define PS_MITIGATION_OPTION_MASK 0x3
#define PS_MITIGATION_OPTION_RETURN_FLOW_GUARD 0x10
#define PS_MITIGATION_OPTION_RESTRICT_SET_THREAD_CONTEXT 0x13
#define PS_MITIGATION_OPTION_CET_USER_SHADOW_STACKS 0x1f
#define PsneKiUserCallbackDispatcher 0x18

//
// User Shared Data Structure Offset Definitions
//

#define UsTickCountMultiplier 0x4
#define UsInterruptTime 0x8
#define UsSystemTime 0x14
#define UsTimeZoneBias 0x20
#define UsImageNumberLow 0x2c
#define UsImageNumberHigh 0x2e
#define UsNtSystemRoot 0x30
#define UsMaxStackTraceDepth 0x238
#define UsCryptoExponent 0x23c
#define UsTimeZoneId 0x240
#define UsLargePageMinimum 0x244
#define UsNtBuildNumber 0x260
#define UsNtProductType 0x264
#define UsProductTypeIsValid 0x268
#define UsNtMajorVersion 0x26c
#define UsNtMinorVersion 0x270
#define UsProcessorFeatures 0x274
#define UsReserved1 0x2b4
#define UsReserved3 0x2b8
#define UsTimeSlip 0x2bc
#define UsAlternativeArchitecture 0x2c0
#define UsSystemExpirationDate 0x2c8
#define UsSuiteMask 0x2d0
#define UsKdDebuggerEnabled 0x2d4
#define UsActiveConsoleId 0x2d8
#define UsDismountCount 0x2dc
#define UsComPlusPackage 0x2e0
#define UsLastSystemRITEventTickCount 0x2e4
#define UsNumberOfPhysicalPages 0x2e8
#define UsSafeBootMode 0x2ec
#define UsTestRetInstruction 0x2f8
#define UsSystemCallPad 0x310
#define UsTickCount 0x320
#define UsTickCountQuad 0x320
#define UsXState 0x3d8

//
// Time Structure Offset Definitions
//

#define TmLowTime 0x0
#define TmHighTime 0x4

//
// Thread Switch Counter Offset Definitions
//

#define TwFindAny 0x0
#define TwFindIdeal 0x4
#define TwFindLast 0x8
#define TwIdleAny 0xc
#define TwIdleCurrent 0x10
#define TwIdleIdeal 0x14
#define TwIdleLast 0x18
#define TwPreemptAny 0x1c
#define TwPreemptCurrent 0x20
#define TwPreemptLast 0x24
#define TwSwitchToIdle 0x28

//
// Status Code Definitions
//

#define STATUS_ACCESS_VIOLATION 0xc0000005
#define STATUS_ARRAY_BOUNDS_EXCEEDED 0xc000008c
#define STATUS_BAD_COMPRESSION_BUFFER 0xc0000242
#define STATUS_BREAKPOINT 0x80000003
#define STATUS_CALLBACK_POP_STACK 0xc0000423
#define STATUS_DATATYPE_MISALIGNMENT 0x80000002
#define STATUS_FLOAT_DENORMAL_OPERAND 0xc000008d
#define STATUS_FLOAT_DIVIDE_BY_ZERO 0xc000008e
#define STATUS_FLOAT_INEXACT_RESULT 0xc000008f
#define STATUS_FLOAT_INVALID_OPERATION 0xc0000090
#define STATUS_FLOAT_OVERFLOW 0xc0000091
#define STATUS_FLOAT_STACK_CHECK 0xc0000092
#define STATUS_FLOAT_UNDERFLOW 0xc0000093
#define STATUS_FLOAT_MULTIPLE_FAULTS 0xc00002b4
#define STATUS_FLOAT_MULTIPLE_TRAPS 0xc00002b5
#define STATUS_GUARD_PAGE_VIOLATION 0x80000001
#define STATUS_ILLEGAL_FLOAT_CONTEXT 0xc000014a
#define STATUS_ILLEGAL_INSTRUCTION 0xc000001d
#define STATUS_INSTRUCTION_MISALIGNMENT 0xc00000aa
#define STATUS_INVALID_HANDLE 0xc0000008
#define STATUS_INVALID_LOCK_SEQUENCE 0xc000001e
#define STATUS_INVALID_OWNER 0xc000005a
#define STATUS_INVALID_PARAMETER 0xc000000d
#define STATUS_INVALID_PARAMETER_1 0xc00000ef
#define STATUS_INVALID_SYSTEM_SERVICE 0xc000001c
#define STATUS_INVALID_THREAD 0xc000071c
#define STATUS_INTEGER_DIVIDE_BY_ZERO 0xc0000094
#define STATUS_INTEGER_OVERFLOW 0xc0000095
#define STATUS_IN_PAGE_ERROR 0xc0000006
#define STATUS_KERNEL_APC 0x100
#define STATUS_LONGJUMP 0x80000026
#define STATUS_NO_CALLBACK_ACTIVE 0xc0000258
#define STATUS_PRIVILEGED_INSTRUCTION 0xc0000096
#define STATUS_SINGLE_STEP 0x80000004
#define STATUS_STACK_BUFFER_OVERRUN 0xc0000409
#define STATUS_STACK_OVERFLOW 0xc00000fd
#define STATUS_SUCCESS 0x0
#define STATUS_THREAD_IS_TERMINATING 0xc000004b
#define STATUS_TIMEOUT 0x102
#define STATUS_UNWIND 0xc0000027
#define STATUS_UNWIND_CONSOLIDATE 0x80000029
#define STATUS_USER_APC 0xc0
#define STATUS_WAKE_SYSTEM 0x40000294
#define STATUS_WAKE_SYSTEM_DEBUGGER 0x80000007
#define STATUS_SET_CONTEXT_DENIED 0xc000060a
#define STATUS_RETURN_ADDRESS_HIJACK_ATTEMPT 0x80000033

//
// Fast Fail Code Definitions
//

#define FAST_FAIL_INVALID_BUFFER_ACCESS 0x1c
#define FAST_FAIL_INVALID_NEXT_THREAD 0x1e
#define FAST_FAIL_INVALID_CONTROL_STACK 0x2f
#define FAST_FAIL_SET_CONTEXT_DENIED 0x30
#define FAST_FAIL_ENCLAVE_CALL_FAILURE 0x35
#define FAST_FAIL_FLAGS_CORRUPTION 0x3b

//
// APC Object Structure Offset Definitions
//

#define ApType 0x0
#define ApSize 0x2
#define ApThread 0x8
#define ApApcListEntry 0xc
#define ApKernelRoutine 0x14
#define ApRundownRoutine 0x18
#define ApNormalRoutine 0x1c
#define ApNormalContext 0x20
#define ApSystemArgument1 0x24
#define ApSystemArgument2 0x28
#define ApApcStateIndex 0x2c
#define ApApcMode 0x2d
#define ApInserted 0x2e
#define ApcObjectLength 0x30

//
// DPC object Structure Offset Definitions
//

#define DpType 0x0
#define DpNumber 0x2
#define DpImportance 0x1
#define DpDpcListEntry 0x4
#define DpDeferredRoutine 0xc
#define DpDeferredContext 0x10
#define DpSystemArgument1 0x14
#define DpSystemArgument2 0x18
#define DpDpcData 0x1c
#define DpcObjectLength 0x20

#define KI_DPC_ALL_FLAGS 0xbf
#define KI_DPC_ANY_DPC_ACTIVE 0x10001

//
// Device Queue Object Structure Offset Definitions
//

#define DvType 0x0
#define DvSize 0x2
#define DvDeviceListHead 0x4
#define DvSpinLock 0xc
#define DvBusy 0x10
#define DeviceQueueObjectLength 0x14

//
// Device Queue Entry Structure Offset Definitions
//

#define DeDeviceListEntry 0x0
#define DeSortKey 0x8
#define DeInserted 0xc
#define DeviceQueueEntryLength 0x10

//
// Event Object Structure Offset Definitions
//

#define EvType 0x0
#define EvSize 0x2
#define EvSignalState 0x4
#define EvWaitListHead 0x8
#define EventObjectLength 0x10

//
// Interrupt Object Structure Offset Definitions
//

#define KINTERRUPT_STATE_DISABLED_BIT 0x0
#define KINTERRUPT_STATE_DISABLED 0x1
#define InLevelSensitive 0x0
#define InLatched 0x1

#define InType 0x0
#define InSize 0x2
#define InInterruptListEntry 0x4
#define InServiceRoutine 0xc
#define InServiceContext 0x18
#define InSpinLock 0x1c
#define InTickCount 0x20
#define InActualLock 0x24
#define InDispatchAddress 0x28
#define InVector 0x2c
#define InIrql 0x30
#define InSynchronizeIrql 0x31
#define InFloatingSave 0x32
#define InConnected 0x33
#define InNumber 0x34
#define InShareVector 0x38
#define InInternalState 0x3c
#define InMode 0x40
#define InServiceCount 0x48
#define InDispatchCount 0x4c
#define InTrapFrame 0x54
#define InterruptObjectLength 0xd0

//
// Process Object Structure Offset Definitions
//

#define PrType 0x0
#define PrSize 0x2
#define PrSignalState 0x4
#define PrProfileListHead 0x10
#define PrDirectoryTableBase 0x18
#define PrPageDirectory 0x1c
#define PrThreadListHead 0x28
#define PrAffinity 0x40
#define PrReadyListHead 0x4c
#define PrSwapListEntry 0x54
#define PrActiveProcessors 0x58
#define PrProcessFlags 0x64
#define PrBasePriority 0x68
#define PrQuantumReset 0x69
#define PrCycleTime 0x80
#define PrKernelTime 0x98
#define PrUserTime 0x9c
#define PrInstrumentationCallback 0xa4
#define PrMitigationFlags2 0x55c
#define KernelProcessObjectLength 0xe0
#define ExecutiveProcessObjectLength 0x600
#define Win32BatchFlushCallout 0x7

//
// Profile Object Structure Offset Definitions
//

#define PfType 0x0
#define PfSize 0x2
#define PfProfileListEntry 0x4
#define PfProcess 0xc
#define PfRangeBase 0x10
#define PfRangeLimit 0x14
#define PfBucketShift 0x18
#define PfBuffer 0x1c
#define PfSegment 0x20
#define PfAffinity 0x24
#define PfSource 0x34
#define PfStarted 0x36
#define ProfileObjectLength 0x38

//
// Queue Object Structure Offset Definitions
//

#define QuSignalState 0x4
#define QuEntryListHead 0x10
#define QuCurrentCount 0x18
#define QuMaximumCount 0x1c
#define QuThreadListHead 0x20
#define QueueObjectLength 0x28

//
// Thread Object Structure Offset Definitions
//

#define EtCid 0x2cc
#define EtPicoContext 0x39c

#define ThType 0x0
#define ThSize 0x2
#define ThLock 0x0
#define THREAD_FLAGS_CYCLE_PROFILING 0x1
#define THREAD_FLAGS_CYCLE_PROFILING_LOCK_BIT 0x10
#define THREAD_FLAGS_CYCLE_PROFILING_LOCK 0x10000
#define THREAD_FLAGS_COUNTER_PROFILING 0x2
#define THREAD_FLAGS_COUNTER_PROFILING_LOCK_BIT 0x11
#define THREAD_FLAGS_COUNTER_PROFILING_LOCK 0x20000
#define THREAD_FLAGS_GROUP_SCHEDULING 0x4
#define THREAD_FLAGS_AFFINITY_SET 0x8
#define THREAD_FLAGS_ACCOUNTING_CSWITCH 0xb6
#define THREAD_FLAGS_ACCOUNTING_INTERRUPT 0x72
#define THREAD_FLAGS_ACCOUNTING_ANY 0xbe
#define ThDebugActive 0x3
#define ThThreadControlFlags 0x2
#define ThSignalState 0x4
#define ThCycleTime 0x30
#define ThCurrentRunTime 0x38
#define ThVfpState 0x140
#define ThInitialStack 0x20
#define ThStackLimit 0x24
#define ThKernelStack 0x40
#define ThThreadLock 0x2c
#define ThApcState 0x64
#define ThProcess 0x150
#define ThNextProcessor 0x148
#define ThAdjustReason 0x15e
#define ThAdjustIncrement 0x15f
#define ThWaitReason 0x18b
#define ThRunning 0x49
#define ThAlerted 0x4a
#define ThWaitTime 0x130
#define ThCombinedApcDisable 0x134
#define ThKernelApcDisable 0x134
#define ThSpecialApcDisable 0x136
#define ThTeb 0x9c
#define ThTimer 0xa8
#define thProcess 0x150

#define KTHREAD_AUTO_ALIGNMENT_BIT 0x2
#define KTHREAD_GUI_THREAD_MASK 0x80
#define KTHREAD_RESTRICTED_GUI_THREAD_MASK 0x200000
#define KTHREAD_SYSTEM_THREAD_BIT 0xa
#define KTHREAD_QUEUE_DEFER_PREEMPTION_BIT 0xb
#define KTHREAD_BAM_QOS_LEVEL_MASK 0xff
#define KTHREAD_CET_USER_SHADOW_STACK_BIT 0x14
#define KTHREAD_CET_KERNEL_SHADOW_STACK_BIT 0x16

#define DEBUG_ACTIVE_ALT_SYSCALL_HANDLER 0x24
#define PsSystemCallMapToSystem 0x1

#define ThMiscFlags 0x4c
#define ThThreadFlags 0x50
#define ThPreviousMode 0x15a
#define ThContextSwitches 0x80
#define ThState 0x84
#define ThWaitIrql 0x86
#define ThTrapFrame 0x60
#define ThFirstArgument 0x5c
#define ThApcStateIndex 0x16a
#define ThSystemCallNumber 0x58
#define ThWin32Thread 0x11c
#define ThStackBase 0x28
#define ThLegoData 0x1b8
#define KernelThreadObjectLength 0x2a0
#define ExecutiveThreadObjectLength 0x530

#define KF_VFP_32REG 0x10

//
// Timer object Structure Offset Definitions
//

#define TiType 0x0
#define TiSize 0x2
#define TiSignalState 0x4
#define TiDueTime 0x10
#define TiTimerListEntry 0x18
#define TiDpc 0x20
#define TiPeriod 0x28
#define TimerObjectLength 0x30


//
// Wait Block Structure Offset Definitions
//

#define WbWaitListEntry 0x0
#define WbThread 0xc
#define WbObject 0x10
#define WbWaitKey 0xa
#define WbWaitType 0x8

//
// Fiber Structure Offset Definitions
//

#define FbFiberData 0x0
#define FbExceptionList 0x4
#define FbStackBase 0x8
#define FbStackLimit 0xc
#define FbDeallocationStack 0x10
#define FbFiberContext 0x18
#define FbWx86Tib 0x1b8
#define FbActivationContextStackPointer 0x1bc
#define FbFlsData 0x1c0
#define FbGuaranteedStackBytes 0x1c4
#define FbTebFlags 0x1c8

//
// Process Environment Block Structure Offset Definitions
//

#define PeBeingDebugged 0x2
#define PeProcessParameters 0x10
#define PeKernelCallbackTable 0x2c
#define ProcessEnvironmentBlockLength 0x488

//
// Process Parameters Block Structure Offset Definitions
//

#define PpFlags 0x8
#define USER_CALLBACK_FILTER 0x80000

//
// System Service Descriptor Table Structure Definitions
//

#define NUMBER_SERVICE_TABLES 0x2
#define SERVICE_NUMBER_MASK 0xfff
#define SERVICE_TABLE_SHIFT 0x8
#define SERVICE_TABLE_MASK 0x10
#define SERVICE_TABLE_TEST 0x10

#define SdBase 0x0
#define SdLimit 0x8
#define SdNumber 0xc
#define SdLength 0x10

//
// Thread Environment Block Structure Offset Definitions
//

#define TeStackBase 0x4
#define TeStackLimit 0x8
#define TeFiberData 0x10
#define TeSelf 0x18
#define TeEnvironmentPointer 0x1c
#define TeClientId 0x20
#define TeActiveRpcHandle 0x28
#define TeThreadLocalStoragePointer 0x2c
#define TeCountOfOwnedCriticalSections 0x38
#define TePeb 0x30
#define TeCsrClientThread 0x3c
#define TeWOW32Reserved 0xc0
#define TeSoftFpcr 0xc8
#define TeExceptionCode 0x1a4
#define TeActivationContextStackPointer 0x1a8
#define TeInstrumentationCallbackSp 0x1ac
#define TeInstrumentationCallbackPreviousPc 0x1b0
#define TeInstrumentationCallbackPreviousSp 0x1b4
#define TeGdiClientPID 0x6c0
#define TeGdiClientTID 0x6c4
#define TeGdiThreadLocalInfo 0x6c8
#define TeglDispatchTable 0x7c4
#define TeglReserved1 0xb68
#define TeglReserved2 0xbdc
#define TeglSectionInfo 0xbe0
#define TeglSection 0xbe4
#define TeglTable 0xbe8
#define TeglCurrentRC 0xbec
#define TeglContext 0xbf0
#define TeDeallocationStack 0xe0c
#define TeTlsSlots 0xe10
#define TeTlsExpansionSlots 0xf94
#define TeLastErrorValue 0x34
#define TeVdm 0xf18
#define TeInstrumentation 0xf2c
#define TeGdiBatchCount 0xf70
#define TeGuaranteedStackBytes 0xf78
#define TeFlsData 0xfb4
#define ThreadEnvironmentBlockLength 0x1018
#define CmThreadEnvironmentBlockOffset 0x2000
#define TLS_MINIMUM_AVAILABLE 0x40
#define TLS_EXPANSION_SLOTS 0x400

//
// Lock Queue Structure Offset Definitions
//

#define LOCK_QUEUE_WAIT 0x1
#define LOCK_QUEUE_OWNER 0x2
#define LOCK_QUEUE_HEADER_SIZE 0x8


#define LqNext 0x0
#define LqLock 0x4

#define LqhLockQueue 0x0
#define LqhOldIrql 0x8
#define LqhNext 0x0
#define LqhLock 0x4

//
// Kernel Stack Control Structure Offset (relative to initial stack pointer) Definitions
//

#define KSTACK_CONTROL_LENGTH 0x18
#define KcPreviousBase 0x8
#define KcPreviousLimit 0xc
#define KcPreviousKernel 0x10
#define KcPreviousInitial 0x14
#define KcCurrentBase 0x0
#define KcActualLimit 0x4
#define KSTACK_ACTUAL_LIMIT_EXPANDED 0x1


//
// ETW Definitions
//

#define PERF_CONTEXTSWAP_OFFSET 0x4
#define PERF_CONTEXTSWAP_FLAG 0x4
#define PERF_INTERRUPT 0x20004000
#define PERF_INTERRUPT_OFFSET 0x4
#define PERF_INTERRUPT_FLAG 0x4000
#define PERF_SYSCALL_OFFSET 0x8
#define PERF_SYSCALL_FLAG 0x40
#define PERF_SPEC_CONTROL_OFFSET 0x14
#define PERF_SPEC_CONTROL_FLAG 0x2
#define NTOS_YIELD_MACRO 0x1
#define EtwTSLength 0x20

//
// Extended context structure offset definitions
//

#define CxxAllOffset 0x0
#define CxxAllLength 0x4
#define CxxLegacyOffset 0x8
#define CxxLegacyLength 0xc
#define CxxXStateOffset 0x10
#define CxxXStateLength 0x14
#define CxxKernelCetOffset 0x18
#define CxxKernelCetLength 0x1c

//
// KAFFINITY_EX offsets
//

#define AfCount 0x0
#define AfBitmap 0x8
#define PbEntropyCount 0x980
#define PbEntropyBuffer 0x984
#define KENTROPY_TIMING_INTERRUPTS_PER_BUFFER 0x400
#define KENTROPY_TIMING_BUFFER_MASK 0x7ff
#define KENTROPY_TIMING_ANALYSIS 0x0

//
// Priority state definitions
//

#define KPRIORITY_STATE_PRIORITY_BITMASK 0x7f

//
// Special Register Structure Offset Definition
//

#define KsCp15_Cr13_SvcRW 0x24
#define KsCp15_Cr13_UsrRO 0x20
#define KsCp15_Cr13_UsrRW 0x1c
#define KsKernelBcr 0x48
#define KsKernelBvr 0x28
#define KsKernelWcr 0x6c
#define KsKernelBvr 0x28
#define KsFpexc 0x70
#define KsFpinst 0x74
#define KsFpinst2 0x78
#define KsUserSp 0x7c
#define KsUserLr 0x80
#define KsAbortSp 0x84
#define KsAbortLr 0x88
#define KsAbortSpsr 0x8c
#define KsUdfSp 0x90
#define KsUdfLr 0x94
#define KsUdfSpsr 0x98
#define KsIrqSp 0x9c
#define KsIrqLr 0xa0
#define KsIrqSpsr 0xa4

//
// ARM Architectural State Structure Offset Definitions
//

#define AaCp15_Cr0_CpuId 0x0
#define AaCp15_Cr1_Control 0x4
#define AaCp15_Cr1_AuxControl 0x8
#define AaCp15_Cr1_Cpacr 0xc
#define AaCp15_Cr2_TtbControl 0x10
#define AaCp15_Cr2_Ttb0 0x14
#define AaCp15_Cr2_Ttb1 0x18
#define AaCp15_Cr3_Dacr 0x1c
#define AaCp15_Cr5_Dfsr 0x20
#define AaCp15_Cr5_Ifsr 0x24
#define AaCp15_Cr6_Dfar 0x28
#define AaCp15_Cr6_Ifar 0x2c
#define AaCp15_Cr9_PmControl 0x30
#define AaCp15_Cr9_PmCountEnableSet 0x34
#define AaCp15_Cr9_PmCycleCounter 0x38
#define AaCp15_Cr9_PmEventCounter 0x3c
#define AaCp15_Cr9_PmEventType 0xb8
#define AaCp15_Cr9_PmInterruptSelect 0x134
#define AaCp15_Cr9_PmOverflowStatus 0x138
#define AaCp15_Cr9_PmSelect 0x13c
#define AaCp15_Cr9_PmUserEnable 0x140
#define AaCp15_Cr10_PrimaryMemoryRemap 0x144
#define AaCp15_Cr10_NormalMemoryRemap 0x148
#define AaCp15_Cr12_VBARns 0x14c
#define AaCp15_Cr13_ContextId 0x150

//
// Processor Control Region Structure Offset Definitions
//

#define PcSelf 0xc
#define PcCurrentPrcb 0x10
#define PcLockArray 0x14
#define PcTeb 0x18
#define PcStallScaleFactor 0x30
#define PcHalReserved 0x84
#define PcPrcb 0x580
#define PcIdleHalt 0x582
#define PcCurrentThread 0x584
#define PcNextThread 0x588
#define PcIdleThread 0x58c
#define PcNestingLevel 0x590
#define PcNumber 0x594
#define PcPrcbLock 0x598
#define PcGroupSetMember 0x998
#define PcFeatureBits 0xa8c
#define TlThread 0x0
#define TlCpuNumber 0x4
#define TlTrapType 0x5
#define TlPadding 0x6
#define TlR0 0x8
#define TlR1 0xc
#define TlR2 0x10
#define TlR3 0x14
#define TlR12 0x18
#define TlSp 0x1c
#define TlLr 0x20
#define TlR11 0x24
#define TlPc 0x28
#define TlCpsr 0x2c
#define TRAP_TYPE_INTERRUPT 0x1
#define TRAP_TYPE_SYSCALL 0x2
#define TRAP_TYPE_UNDEFINED 0x3
#define TRAP_TYPE_DATA_ABORT 0x4
#define TRAP_TYPE_PREFETCH_ABORT 0x5
#define TRAP_TYPE_RESET 0x6
#define TRAP_TYPE_FIQ 0x7
#define PcInterruptCount 0xe80
#define PcDebuggerSavedIRQL 0xe99
#define PcDeferredReadyListHead 0xb84
#define PcInterruptCount 0xe80
#define PcSystemCalls 0xbb0
#define PcDpcRoutineActive 0xc62
#define PcDeferredReadyListHead 0xb84
#define PcSkipTick 0xe98
#define PcStartCycles 0xec8
#define PcSpBase 0xc4c
#define PcCycleCounterHigh 0xef0
#define ProcessorControlRegisterLength 0x70e0

//
// Defines for user shared data
//

#define USER_SHARED_DATA 0xffff9000
#define MM_SHARED_USER_DATA_VA 0x7ffe0000
#define UsTickCountMultiplier 0x4
#define UsTickCount 0x320
#define UsInterruptTime 0x8
#define UsSystemTime 0x14
#define UsProcessorFeatures 0x274

#define CP15_CPACR_D32DIS 0x80000000
#define CP15_CPACR_ASEDIS 0x40000000
#define CP15_CPACR_VFP_MASK 0xf00000
#define CPVFP_FPEXC_EX 0x80000000
#define CPVFP_FPEXC_EN 0x40000000
#define CPVFP_FPEXC_DEX 0x20000000
#define CPVFP_FPEXC_FP2V 0x10000000

//
// Processor Block Structure Offset Definitions
//

#define PbNestingLevel 0x10
#define PbIdleHalt 0x2
#define PbCurrentThread 0x4
#define PbNextThread 0x8
#define PbIdleThread 0xc
#define PbNumber 0x14
#define PbPrcbLock 0x18
#define PbKeSpinLockOrdering 0x748
#define KI_SPINLOCK_ORDER_PRCB_LOCK 0x80
#define PbGroup 0x41c
#define PbGroupIndex 0x41d
#define PbProcessorState 0x20
#define PbHalReserved 0x3d0
#define PbMinorVersion 0x40c
#define PbMajorVersion 0x40e
#define PbBuildType 0x410
#define PbCoresPerPhysicalProcessor 0x412
#define PbLogicalProcessorsPerCore 0x413
#define PbPriorityState 0x1c
#define PbLockQueue 0x480
#define PbPPLookasideList 0x580
#define PbPPNPagedLookasideList 0x4b00
#define PbPPPagedLookasideList 0x5400
#define PbPacketBarrier 0x600
#define PbDeferredReadyListHead 0x604
#define PbLookasideIrpFloat 0x650
#define PbRequestMailbox 0x6700
#define PbMailbox 0x680
#define PbDpcGate 0x700
#define PbWaitListHead 0x780
#define PbCcFastMdlReadNoWait 0xb00
#define PbPowerState 0xb80
#define PbSpinLockAcquireCount 0xe80
#define PbSystemCalls 0x630
#define PbReadOperationCount 0x654
#define PbWriteOperationCount 0x658
#define PbOtherOperationCount 0x65c
#define PbReadTransferCount 0x660
#define PbWriteTransferCount 0x668
#define PbOtherTransferCount 0x670
#define PbContextSwitches 0x634
#define PbIpiFrozen 0x688
#define PbDpcList 0x690
#define PbDpcLock 0x698
#define PbDpcCount 0x6a0
#define PbDpcStack 0x6c8
#define PbSpBase 0x6cc
#define PbMaximumDpcQueueDepth 0x6d0
#define PbDpcRequestRate 0x6d4
#define PbMinimumDpcRate 0x6d8
#define PbDpcRoutineActive 0x6e2
#define PbDpcRequestSummary 0x6e4
#define PbNormalDpcState 0x6e4
#define PbDpcLastCount 0x6dc
#define PbQuantumEnd 0x6e1
#define PbIdleSchedule 0x6e3
#define PbDispatcherReadyListHead 0x800
#define PbInterruptCount 0x900
#define PbKernelTime 0x904
#define PbUserTime 0x908
#define PbDpcTime 0x90c
#define PbInterruptTime 0x910
#define PbAdjustDpcThreshold 0x914
#define PbStartCycles 0x948
#define PbPageColor 0xabc
#define PbNodeColor 0xac0
#define PbNodeShiftedColor 0xac4
#define PbSecondaryColorMask 0xac8
#define PbCycleTime 0xad0
#define PbFastReadNoWait 0x638
#define PbFastReadWait 0x63c
#define PbFastReadNotPossible 0x640
#define PbCopyReadNoWait 0x644
#define PbCopyReadWait 0x648
#define PbCopyReadNoWaitMiss 0x64c
#define PbAlignmentFixupCount 0xd08
#define PbExceptionDispatchCount 0x934
#define PbProcessorVendorString 0x508
#define PbFeatureBits 0x50c
#define PbPanicStackBase 0xff0
#define PbFiqMiniStack 0xf50
#define PbIrqMiniStack 0xf70
#define PbUdfMiniStack 0xf90
#define PbAbtMiniStack 0xfb0
#define PbPanicMiniStack 0xfd0
#define PbCycleCounterHigh 0x970
#define ThNpxState 0x85
#define ThUserRoBase 0x3a0
#define ThUserRwBase 0x3a4

//
// KTHREAD state
//

#define Initialized 0x0
#define Ready 0x1
#define Running 0x2
#define Standby 0x3
#define Terminated 0x4
#define Waiting 0x5
#define Transition 0x6
#define DeferredReady 0x7
#define GateWaitObsolete 0x8

//
// Immediate Interprocessor Command Definitions
//

#define IPI_APC 0x1
#define IPI_DPC 0x2
#define IPI_FREEZE 0x4
#define IPI_PACKET_READY 0x5

//
// Processor Idle Times Offset Definitions
//

#define PiStartTime 0x0
#define PiEndTime 0x8

//
// Immediate Interprocessor Command Definitions
//

#define IPI_PACKET_READY 0x5

//
// Time Fields (TIME_FIELDS) Structure Offset Definitions
//

#define TfSecond 0xa
#define TfMinute 0x8
#define TfHour 0x6
#define TfWeekday 0xe
#define TfDay 0x4
#define TfMonth 0x2
#define TfYear 0x0
#define TfMilliseconds 0xc


//
// CPSR mode constants
//

#define CPSRM_USER 0x10
#define CPSRM_FIQ 0x11
#define CPSRM_INT 0x12
#define CPSRM_SVC 0x13
#define CPSRM_ABT 0x17
#define CPSRM_UDF 0x1b
#define CPSRM_SYS 0x1f
#define CPSRM_MASK 0x1f
#define SYSCALL_PSR 0x30

//
// CPSR flag constants
//

#define CPSRF_N 0x80000000
#define CPSRF_Z 0x40000000
#define CPSRF_C 0x20000000
#define CPSRF_V 0x10000000
#define CPSRF_Q 0x8000000
#define CPSR_IT_MASK 0x600fc00

//
// FPSCR flags
//

#define FPSCRF_N 0x80000000
#define FPSCRF_Z 0x40000000
#define FPSCRF_C 0x20000000
#define FPSCRF_V 0x10000000
#define FPSCRF_QC 0x8000000

//
// FPSCR modes
//

#define FPSCRM_AHP 0x4000000
#define FPSCRM_DN 0x2000000
#define FPSCRM_FZ 0x1000000
#define FPSCRM_RMODE_MASK 0xc00000
#define FPSCRM_RMODE_RN 0x0
#define FPSCRM_RMODE_RP 0x400000
#define FPSCRM_RMODE_RM 0x800000
#define FPSCRM_RMODE_RZ 0xc00000
#define FPSCRM_DEPRECATED 0x370000

//
// FPSCR exceptions
//

#define FPSCR_IDE 0x8000
#define FPSCR_IXE 0x1000
#define FPSCR_UFE 0x800
#define FPSCR_OFE 0x400
#define FPSCR_DZE 0x200
#define FPSCR_IOE 0x100
#define FPSCR_IDC 0x80
#define FPSCR_IXC 0x10
#define FPSCR_UFC 0x8
#define FPSCR_OFC 0x4
#define FPSCR_DZC 0x2
#define FPSCR_IOC 0x1

//
// CPSR control constants
//

#define CPSRC_INT 0x80
#define CPSRC_ABORT 0x100
#define CPSRC_THUMB 0x20

//
// Sofware fault status constants
//

#define SWFS_PAGE_FAULT 0x10
#define SWFS_ALIGN_FAULT 0x20
#define SWFS_HWERR_FAULT 0x40
#define SWFS_DEBUG_FAULT 0x80
#define SWFS_EXECUTE 0x8
#define SWFS_WRITE 0x1

//
// ARM DBGDSCR MOE bits
//

#define CP14_DBGDSCR_MOE_MASK 0x3c
#define CP14_DBGDSCR_MOE_SHIFT 0x2
#define CP14_DBGDSCR_MOE_HALT 0x0
#define CP14_DBGDSCR_MOE_BP 0x1
#define CP14_DBGDSCR_MOE_WPASYNC 0x2
#define CP14_DBGDSCR_MOE_BKPT 0x3
#define CP14_DBGDSCR_MOE_EXTERNAL 0x4
#define CP14_DBGDSCR_MOE_VECTOR 0x5
#define CP14_DBGDSCR_MOE_WPSYNC 0xa

//
// PMCR bits
//

#define CP15_PMCR_DP 0x20
#define CP15_PMCR_X 0x10
#define CP15_PMCR_CLKCNT_DIV 0x8
#define CP15_PMCR_CLKCNT_RST 0x4
#define CP15_PMCR_CNT_RST 0x2
#define CP15_PMCR_ENABLE 0x1

//
// Special opcodes
//

#define THUMB_BREAKPOINT 0xdefe
#define THUMB_DEBUG_SERVICE 0xdefd
#define THUMB_ASSERT 0xdefc
#define THUMB_FASTFAIL 0xdefb
#define THUMB_READ_CYCLES 0xdefa
#define THUMB_DIVIDE_BY_0 0xdef9

//
// CP14 masks and constants
//

#define DBGDSCR_MON_EN_BIT 0x8000
#define CP14_DBGBCR_MISMATCH_BIT 0x400000
#define CP14_DBGBCR_ENABLE_BIT 0x1

//
// CP15 masks and constants
//

#define CP15_CR0_HARVARD_CACHE 0x1000000
#define CP15_xFSR_FS_HIGH 0x400
#define CP15_xFSR_FS_LOW 0xf
#define CP15_DFSR_WnR 0x800
#define CP15_SCTLR_I 0x1000
#define CP15_SCTLR_C 0x4
#define CP15_SCTLR_M 0x1
#define CP15_SCTLR_Z 0x800
#define CP15_THREAD_RESERVED_MASK 0x3f

#define CP15_MIDR              15, 0,  0,  0, 0

#define CP15_CTR               15, 0,  0,  0, 1

#define CP15_TCMTR             15, 0,  0,  0, 2

#define CP15_TLBTR             15, 0,  0,  0, 3

#define CP15_MPIDR             15, 0,  0,  0, 5

#define CP15_PFR0              15, 0,  0,  1, 0

#define CP15_PFR1              15, 0,  0,  1, 1

#define CP15_DFR0              15, 0,  0,  1, 2

#define CP15_AFR0              15, 0,  0,  1, 3

#define CP15_MMFR0             15, 0,  0,  1, 4

#define CP15_MMFR1             15, 0,  0,  1, 5

#define CP15_MMFR2             15, 0,  0,  1, 6

#define CP15_MMFR3             15, 0,  0,  1, 7

#define CP15_ISAR0             15, 0,  0,  2, 0

#define CP15_ISAR1             15, 0,  0,  2, 1

#define CP15_ISAR2             15, 0,  0,  2, 2

#define CP15_ISAR3             15, 0,  0,  2, 3

#define CP15_ISAR4             15, 0,  0,  2, 4

#define CP15_ISAR5             15, 0,  0,  2, 5

#define CP15_ISAR6             15, 0,  0,  2, 6

#define CP15_ISAR7             15, 0,  0,  2, 7

#define CP15_SCTLR             15, 0,  1,  0, 0

#define CP15_ACTLR             15, 0,  1,  0, 1

#define CP15_CPACR             15, 0,  1,  0, 2

#define CP15_SCR               15, 0,  1,  1, 0

#define CP15_SDER              15, 0,  1,  1, 1

#define CP15_NSACR             15, 0,  1,  1, 2

#define CP15_TTBR0             15, 0,  2,  0, 0

#define CP15_TTBR1             15, 0,  2,  0, 1

#define CP15_TTBCR             15, 0,  2,  0, 2

#define CP15_DACR              15, 0,  3,  0, 0

#define CP15_DFSR              15, 0,  5,  0, 0

#define CP15_IFSR              15, 0,  5,  0, 1

#define CP15_DFAR              15, 0,  6,  0, 0

#define CP15_IFAR              15, 0,  6,  0, 2

#define CP15_ICIALLUIS         15, 0,  7,  1, 0

#define CP15_BPIALLIS          15, 0,  7,  1, 6

#define CP15_ICIALLU           15, 0,  7,  5, 0

#define CP15_ICIMVAU           15, 0,  7,  5, 1

#define CP15_BPIALL            15, 0,  7,  5, 6

#define CP15_BPIMVA            15, 0,  7,  5, 7

#define CP15_DCIMVAC           15, 0,  7,  6, 1

#define CP15_DCISW             15, 0,  7,  6, 2

#define CP15_DCCMVAC           15, 0,  7, 10, 1

#define CP15_DCCSW             15, 0,  7, 10, 2

#define CP15_DCCMVAU           15, 0,  7, 11, 1

#define CP15_DCCIMVAC          15, 0,  7, 14, 1

#define CP15_DCCISW            15, 0,  7, 14, 2

#define CP15_PAR               15, 0,  7,  4, 0

#define CP15_ATS1CPR           15, 0,  7,  8, 0

#define CP15_ATS1CPW           15, 0,  7,  8, 1

#define CP15_ATS1CUR           15, 0,  7,  8, 2

#define CP15_ATS1CUW           15, 0,  7,  8, 3

#define CP15_ISB               15, 0,  7,  5, 4

#define CP15_DSB               15, 0,  7, 10, 4

#define CP15_DMB               15, 0,  7, 10, 5

#define CP15_TLBIALLIS         15, 0,  8,  3, 0

#define CP15_TLBIMVAIS         15, 0,  8,  3, 1

#define CP15_TLBIASIDIS        15, 0,  8,  3, 2

#define CP15_TLBIMVAAIS        15, 0,  8,  3, 3

#define CP15_ITLBIALL          15, 0,  8,  5, 0

#define CP15_ITLBIMVA          15, 0,  8,  5, 1

#define CP15_ITLBIASID         15, 0,  8,  5, 2

#define CP15_DTLBIALL          15, 0,  8,  6, 0

#define CP15_DTLBIMVA          15, 0,  8,  6, 1

#define CP15_DTLBIASID         15, 0,  8,  6, 2

#define CP15_TLBIALL           15, 0,  8,  7, 0

#define CP15_TLBIMVA           15, 0,  8,  7, 1

#define CP15_TLBIASID          15, 0,  8,  7, 2

#define CP15_TLBIMVAA          15, 0,  8,  7, 3

#define CP15_PMCR              15, 0,  9, 12, 0

#define CP15_PMCNTENSET        15, 0,  9, 12, 1

#define CP15_PMCNTENCLR        15, 0,  9, 12, 2

#define CP15_PMOVSR            15, 0,  9, 12, 3

#define CP15_PSWINC            15, 0,  9, 12, 4

#define CP15_PMSELR            15, 0,  9, 12, 5

#define CP15_PMCCNTR           15, 0,  9, 13, 0

#define CP15_PMXEVTYPER        15, 0,  9, 13, 1

#define CP15_PMXEVCNTR         15, 0,  9, 13, 2

#define CP15_PMUSERENR         15, 0,  9, 14, 0

#define CP15_PMINTENSET        15, 0,  9, 14, 1

#define CP15_PMINTENCLR        15, 0,  9, 14, 2

#define CP15_PRRR              15, 0, 10,  2, 0

#define CP15_NMRR              15, 0, 10,  2, 1

#define CP15_VBAR              15, 0, 12,  0, 0

#define CP15_MVBAR             15, 0, 12,  0, 1

#define CP15_ISR               15, 0, 12,  1, 0

#define CP15_CONTEXTIDR        15, 0, 13,  0, 1

#define CP15_TPIDRURW          15, 0, 13,  0, 2

#define CP15_TPIDRURO          15, 0, 13,  0, 3

#define CP15_TPIDRPRW          15, 0, 13,  0, 4

#define CP15_CCSIDR            15, 1,  0,  0, 0

#define CP15_CLIDR             15, 1,  0,  0, 1

#define CP15_AIDR              15, 1,  0,  0, 7

#define CP15_CSSELR            15, 2,  0,  0, 0

#define CP14_DBGDIDR           14, 0,  0,  0, 0

#define CP14_DBGWFAR           14, 0,  0,  6, 0

#define CP14_DBGVCR            14, 0,  0,  7, 0

#define CP14_DBGECR            14, 0,  0,  9, 0

#define CP14_DBGDSCCR          14, 0,  0, 10, 0

#define CP14_DBGDSMCR          14, 0,  0, 11, 0

#define CP14_DBGDTRRX          14, 0,  0,  0, 2

#define CP14_DBGPCSR           14, 0,  0,  1, 2

#define CP14_DBGITR            14, 0,  0,  1, 2

#define CP14_DBGDSCR           14, 0,  0,  2, 2

#define CP14_DBGDTRTX          14, 0,  0,  3, 2

#define CP14_DBGDRCR           14, 0,  0,  4, 2

#define CP14_DBGCIDSR          14, 0,  0,  9, 2

#define CP14_DBGBVR0           14, 0,  0,  0, 4

#define CP14_DBGBVR1           14, 0,  0,  1, 4

#define CP14_DBGBVR2           14, 0,  0,  2, 4

#define CP14_DBGBVR3           14, 0,  0,  3, 4

#define CP14_DBGBVR4           14, 0,  0,  4, 4

#define CP14_DBGBVR5           14, 0,  0,  5, 4

#define CP14_DBGBVR6           14, 0,  0,  6, 4

#define CP14_DBGBVR7           14, 0,  0,  7, 4

#define CP14_DBGBCR0           14, 0,  0,  0, 5

#define CP14_DBGBCR1           14, 0,  0,  1, 5

#define CP14_DBGBCR2           14, 0,  0,  2, 5

#define CP14_DBGBCR3           14, 0,  0,  3, 5

#define CP14_DBGBCR4           14, 0,  0,  4, 5

#define CP14_DBGBCR5           14, 0,  0,  5, 5

#define CP14_DBGBCR6           14, 0,  0,  6, 5

#define CP14_DBGBCR7           14, 0,  0,  7, 5

#define CP14_DBGWVR0           14, 0,  0,  0, 6

#define CP14_DBGWVR1           14, 0,  0,  1, 6

#define CP14_DBGWVR2           14, 0,  0,  2, 6

#define CP14_DBGWVR3           14, 0,  0,  3, 6

#define CP14_DBGWCR0           14, 0,  0,  0, 7

#define CP14_DBGWCR1           14, 0,  0,  1, 7

#define CP14_DBGWCR2           14, 0,  0,  2, 7

#define CP14_DBGWCR3           14, 0,  0,  3, 7

#define CPVFP_FPSID            10, 7,  0,  0, 0

#define CPVFP_FPSCR            10, 7,  1,  0, 0

#define CPVFP_MVFR1            10, 7,  6,  0, 0

#define CPVFP_MVFR0            10, 7,  7,  0, 0

#define CPVFP_FPEXC            10, 7,  8,  0, 0
#define CP15_TTBRx_PD_MASK 0xffffc000

//
// Miscellaneous Definitions
//

#define MAXIMUM_PROCESSORS 0x20
#define INITIAL_STALL_COUNT 0x64
#define IRQL_NOT_GREATER_OR_EQUAL 0x9
#define IRQL_NOT_LESS_OR_EQUAL 0xa
#define MUTEX_ALREADY_OWNED 0xbf
#define THREAD_NOT_MUTEX_OWNER 0x11
#define SPIN_LOCK_ALREADY_OWNED 0xf
#define SPIN_LOCK_NOT_OWNED 0x10
#define Executive 0x0
#define KernelMode 0x0
#define UserMode 0x1
#define FALSE 0x0
#define TRUE 0x1

//
// Fast Fail Definitions
//

#define FAST_FAIL_GUARD_ICALL_CHECK_FAILURE 0xa
#define FAST_FAIL_DEPRECATED_SERVICE_INVOKED 0x1b
#define BASE_PRIORITY_THRESHOLD 0x8
#define LOW_REALTIME_PRIORITY 0x10
#define KERNEL_LARGE_STACK_COMMIT 0x3000
#define KERNEL_LARGE_STACK_SIZE 0xf000
#define DOUBLE_FAULT_STACK_SIZE 0x3000
#define BREAKPOINT_BREAK 0x0
#define BREAKPOINT_HW_BREAK 0x8
#define BREAKPOINT_HW_SYNCH_WATCH 0x6
#define BREAKPOINT_HW_ASYNCH_WATCH 0x7
#define BREAKPOINT_COMMAND_STRING 0x5
#define BREAKPOINT_PRINT 0x1
#define BREAKPOINT_PROMPT 0x2
#define BREAKPOINT_LOAD_SYMBOLS 0x3
#define BREAKPOINT_UNLOAD_SYMBOLS 0x4
#define CLOCK_QUANTUM_DECREMENT 0x3
#define READY_SKIP_QUANTUM 0x2
#define THREAD_QUANTUM 0x6
#define WAIT_QUANTUM_DECREMENT 0x1
#define ROUND_TRIP_DECREMENT_COUNT 0x10
#define KI_EXCEPTION_INTERNAL 0x10000000
#define KI_EXCEPTION_GP_FAULT 0x10000001
#define KI_EXCEPTION_INVALID_OP 0x10000002
#define KI_EXCEPTION_ACCESS_VIOLATION 0x10000004
#define KI_EXCEPTION_HARDWARE_ERROR 0x10000005
#define KI_DPC_INTERRUPT_FLAGS 0xaf

//
// Exception Frame Offset Definitions and Length
//

#define ExR4 0x14
#define ExR5 0x18
#define ExR6 0x1c
#define ExR7 0x20
#define ExR8 0x24
#define ExR9 0x28
#define ExR10 0x2c
#define ExR11 0x30
#define ExTrapFrame 0x4
#define ExParam5 0x0
#define ExReturn 0x34

#define KEXCEPTION_FRAME_LENGTH 0x38
#define EXCEPTION_RECORD_LENGTH 0x50


//
// Jump Offset Definitions and Length
//

#define JbFrame 0x0
#define JbR4 0x4
#define JbR5 0x8
#define JbR6 0xc
#define JbR7 0x10
#define JbR8 0x14
#define JbR9 0x18
#define JbR10 0x1c
#define JbR11 0x20
#define JbSp 0x24
#define JbPc 0x28
#define JbFpscr 0x2c
#define JbD 0x30

//
// Switch Frame Offset Definitions and Length
//

#define SwApcBypass 0x0
#define SwR11 0x8
#define SwReturn 0xc

#define KSWITCH_FRAME_LENGTH 0x10

//
// Start System Thread Frame Offset Definitions and Length
//

#define SfR0 0x0
#define SfR1 0x4
#define SfR2 0x8
#define SfReturn 0xc

#define KSTART_FRAME_LENGTH 0x10


//
// Trap Frame Definitions
//

#define KEXCEPTION_ACTIVE_INTERRUPT_FRAME 0x0
#define KEXCEPTION_ACTIVE_EXCEPTION_FRAME 0x1
#define KEXCEPTION_ACTIVE_SERVICE_FRAME 0x2

#define TrArg3 0x0
#define TrFaultStatus 0x4
#define TrFaultAddress 0x8
#define TrTrapFrame 0x8
#define TrReserved 0xc
#define TrExceptionActive 0x10
#define TrPreviousMode 0x13
#define TrDebugRegistersValid 0x12
#define TrBvr 0x18
#define TrBcr 0x38
#define TrWvr 0x58
#define TrWcr 0x5c
#define TrVfpState 0x14
#define TrR0 0x60
#define TrR1 0x64
#define TrR2 0x68
#define TrR3 0x6c
#define TrR12 0x70
#define TrSp 0x74
#define TrLr 0x78
#define TrR11 0x7c
#define TrPc 0x80
#define TrCpsr 0x84

#define KTRAP_FRAME_LENGTH 0x88
#define KTRAP_FRAME_ARGUMENTS 0x38
#define ARM_RED_ZONE_BYTES 0x8

//
// Usermode Callout User Frame Definitions
//

#define CkBuffer 0x0
#define CkLength 0x4
#define CkApiNumber 0x8
#define CkPc 0x14
#define CkSp 0x10
#define CalloutFrameLength 0x18

//
// Machine Frame Offset Definitions
//

#define MfPc 0x4
#define MfSp 0x0
#define MachineFrameLength 0x8

//
// DPC Stack Frame Defintions
//

#define DpSp 0x8
#define DpPc 0xc

//
// ARM Mini-Stack Defintions
//

#define MsPc 0x0
#define MsCpsr 0x4
#define MsR4 0x8
#define MsR5 0xc
#define MsR6 0x10
#define MsR7 0x14
#define MsReserved 0x18
#define MiniStackLength 0x20

//
// Context Frame Offset and Flag Definitions
//

#define CONTEXT_FULL 0x200007
#define CONTEXT_CONTROL 0x200001
#define CONTEXT_INTEGER 0x200002
#define CONTEXT_FLOATING_POINT 0x200004
#define CONTEXT_DEBUG_REGISTERS 0x200008

#define CxContextFlags 0x0
#define CxR0 0x4
#define CxR1 0x8
#define CxR2 0xc
#define CxR3 0x10
#define CxR4 0x14
#define CxR5 0x18
#define CxR6 0x1c
#define CxR7 0x20
#define CxR8 0x24
#define CxR9 0x28
#define CxR10 0x2c
#define CxR11 0x30
#define CxR11 0x30
#define CxR12 0x34
#define CxSp 0x38
#define CxLr 0x3c
#define CxPc 0x40
#define CxCpsr 0x44
#define CxQ 0x50
#define CxD 0x50
#define CxD8 0x90
#define CxS 0x50
#define CxFpscr 0x48
#define CxBvr 0x150
#define CxBcr 0x170
#define CxWvr 0x190
#define CxWcr 0x194
#define CONTEXT_FRAME_LENGTH 0x1a0
#define CONTEXT_ALIGN 0x8
#define DEBUG_ACTIVE_DBG 0x1
#define DEBUG_ACTIVE_DBG_INSTRUMENTED 0x3
#define DEBUG_ACTIVE_MINIMAL_THREAD 0x4
#define DEBUG_ACTIVE_INSTRUMENTED 0x2

//
// Dispatcher Context Structure Offset Definitions
//

#define DcControlPc 0x0
#define DcImageBase 0x4
#define DcFunctionEntry 0x8
#define DcEstablisherFrame 0xc
#define DcTargetPc 0x10
#define DcContextRecord 0x14
#define DcLanguageHandler 0x18
#define DcHandlerData 0x1c
#define DcHistoryTable 0x20
#define DcScopeIndex 0x24
#define DcControlPcIsUnwound 0x28
#define DcNonVolatileRegisters 0x2c
#define DcReserved 0x30
#define ARM_VFP_MANAGEMENT 0x0
#define ARM_VFP_ENABLE_STATISTICS 0x0
#define ARM_VFP_ALWAYSON 0x0
#define ARM_VFP_LAZY_ONEWAY 0x1
#define ARM_VFP_LAZY_WITH_DEMOTION 0x2
#define VsLink 0x0
#define VsFpscr 0x4
#define VsVfpD 0x10
#define VsVfpD8 0x50
#define VFP_STATE_LENGTH 0x110

#define PF_ARM_EXTERNAL_CACHE_AVAILABLE 0x1a


//
// Processor State Frame Offset Definitions
//

#define PsCpuid 0xa8
#define PsControl 0xac
#define PsAuxControl 0xb0
#define PsAsid 0x1f8
#define PsCpacr 0xb4
#define PsTtbControl 0xb8
#define PsTtb0 0xbc
#define PsTtb1 0xc0
#define PsDacr 0xc4
#define PsVBARns 0x1f4
#define PsContextId 0x1f8
#define PsPrimaryMemoryRemap 0x1ec
#define PsNormalMemoryRemap 0x1f0
#define PsUsrRW 0x1c
#define PsUsrRO 0x20
#define PsSvcRW 0x24
#define PsSpecialRegisters 0x0
#define PsArchState 0xa8
#define PsContextFrame 0x200
#define ProcessorStateLength 0x3a0

//
// Processor Parked Page Offset Definitions
//

#define PppArchitecturalStateVirtualAddress 0x10
#define PppArchitecturalState 0x18
#define ProcessorParkedPageLength 0x1000

//
// Processor Start Block Offset Definitions
//

#define PsbSelfMap 0x0
#define PsbTiledTtb0 0x4
#define ProcessorStartBlockLength 0x8

//
// EPROCESS
//

#define EpDebugPort 0x18c

//
// Pico Process Provider Routines
//

#define PprDispatchSystemCall 0x4

//
// KeFeatureBits defines
//


//
// LoaderParameterBlock offsets relative to base
//

#define LpbKernelStack 0x48
#define LpbPrcb 0x4c
#define LpbProcess 0x50
#define LpbThread 0x54
#define PAGE_SIZE 0x1000
#define PAGE_SHIFT 0xc
#define PTE_TOP 0xc03fffff
#define TRANSITION_ASID 0xff

//
// Kernel Mode Callout Frame Definitions
//

#define CuTrapFrame 0x4
#define CuOutputBuffer 0x8
#define CuOutputLength 0xc

//
// Handle table entry definition
//

#define EXHANDLE_TABLE_ENTRY_LOCK 0x1
#define EXHANDLE_REFERENCE_SHIFT 0x1b
#define EXHANDLE_REF_ACQUIRE_LOCK 0xffffffff
#define EXHANDLE_REPLENISH_REFS 0x8
#define EXHANDLE_CACHED_REFS 0x1f

//
// KAFFINITY_EX size
//

#define AffinityExLength 0xc
#include "kxarm.h"
;
