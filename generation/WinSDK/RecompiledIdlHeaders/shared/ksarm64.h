

//
// Pointer size in bytes
//

#define SizeofPointer 0x8

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
#define AsProcess 0x20
#define AsKernelApcPending 0x29
#define AsUserApcPendingAll 0x2a
#define KAPC_STATE_ANY_USER_APC_PENDING_MASK 0x3


//
// Apc Record Structure Offset Definitions
//

#define ArNormalRoutine 0x0
#define ArNormalContext 0x8
#define ArSystemArgument1 0x10
#define ArSystemArgument2 0x18
#define ArFlags 0x20
#define KAPC_RECORD_LENGTH 0x30
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
#define CidUniqueThread 0x8

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
#define ErExceptionAddress 0x10
#define ErNumberParameters 0x18
#define ErExceptionInformation 0x20
#define ExceptionRecordLength 0xa0

//
// Fast Mutex Structure Offset Definitions
//

#define FmCount 0x0
#define FmOwner 0x8
#define FmContention 0x10
#define FmOldIrql 0x30

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
#define LsBlink 0x8

//
// String Structure Offset Definitions
//

#define StrLength 0x0
#define StrMaximumLength 0x2
#define StrBuffer 0x8

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
#define PsneKiUserCallbackDispatcher 0x30

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
#define ApApcListEntry 0x10
#define ApKernelRoutine 0x20
#define ApRundownRoutine 0x28
#define ApNormalRoutine 0x30
#define ApNormalContext 0x38
#define ApSystemArgument1 0x40
#define ApSystemArgument2 0x48
#define ApApcStateIndex 0x50
#define ApApcMode 0x51
#define ApInserted 0x52
#define ApcObjectLength 0x58

//
// DPC object Structure Offset Definitions
//

#define DpType 0x0
#define DpNumber 0x2
#define DpImportance 0x1
#define DpDpcListEntry 0x8
#define DpDeferredRoutine 0x18
#define DpDeferredContext 0x20
#define DpSystemArgument1 0x28
#define DpSystemArgument2 0x30
#define DpDpcData 0x38
#define DpcObjectLength 0x40

#define KI_DPC_ALL_FLAGS 0xbf
#define KI_DPC_ANY_DPC_ACTIVE 0x10001

//
// Device Queue Object Structure Offset Definitions
//

#define DvType 0x0
#define DvSize 0x2
#define DvDeviceListHead 0x8
#define DvSpinLock 0x18
#define DvBusy 0x20
#define DeviceQueueObjectLength 0x28

//
// Device Queue Entry Structure Offset Definitions
//

#define DeDeviceListEntry 0x0
#define DeSortKey 0x10
#define DeInserted 0x14
#define DeviceQueueEntryLength 0x18

//
// Event Object Structure Offset Definitions
//

#define EvType 0x0
#define EvSize 0x2
#define EvSignalState 0x4
#define EvWaitListHead 0x8
#define EventObjectLength 0x18

//
// Interrupt Object Structure Offset Definitions
//

#define KINTERRUPT_STATE_DISABLED_BIT 0x0
#define KINTERRUPT_STATE_DISABLED 0x1
#define InLevelSensitive 0x0
#define InLatched 0x1

#define InType 0x0
#define InSize 0x2
#define InInterruptListEntry 0x8
#define InServiceRoutine 0x18
#define InServiceContext 0x30
#define InSpinLock 0x38
#define InTickCount 0x40
#define InActualLock 0x48
#define InDispatchAddress 0x50
#define InVector 0x58
#define InIrql 0x5c
#define InSynchronizeIrql 0x5d
#define InFloatingSave 0x5e
#define InConnected 0x5f
#define InNumber 0x60
#define InShareVector 0x64
#define InInternalState 0x68
#define InMode 0x6c
#define InServiceCount 0x74
#define InDispatchCount 0x78
#define InTrapFrame 0x88
#define InterruptObjectLength 0x120

//
// Process Object Structure Offset Definitions
//

#define PrType 0x0
#define PrSize 0x2
#define PrSignalState 0x4
#define PrProfileListHead 0x18
#define PrDirectoryTableBase 0x28
#define PrThreadListHead 0x38
#define PrAffinity 0x58
#define PrReadyListHead 0x160
#define PrSwapListEntry 0x170
#define PrActiveProcessors 0x178
#define PrProcessFlags 0x280
#define PrBasePriority 0x288
#define PrQuantumReset 0x289
#define PrCycleTime 0x368
#define PrKernelTime 0x384
#define PrUserTime 0x388
#define PrInstrumentationCallback 0x390
#define PrMitigationFlags2 0xa94
#define KernelProcessObjectLength 0x3f0
#define ExecutiveProcessObjectLength 0xc80
#define Win32BatchFlushCallout 0x7

//
// Profile Object Structure Offset Definitions
//

#define PfType 0x0
#define PfSize 0x2
#define PfProfileListEntry 0x8
#define PfProcess 0x18
#define PfRangeBase 0x20
#define PfRangeLimit 0x28
#define PfBucketShift 0x30
#define PfBuffer 0x38
#define PfSegment 0x40
#define PfAffinity 0x48
#define PfSource 0x158
#define PfStarted 0x15a
#define ProfileObjectLength 0x160

//
// Queue Object Structure Offset Definitions
//

#define QuSignalState 0x4
#define QuEntryListHead 0x18
#define QuCurrentCount 0x28
#define QuMaximumCount 0x2c
#define QuThreadListHead 0x30
#define QueueObjectLength 0x40

//
// Thread Object Structure Offset Definitions
//

#define EtCid 0x4e8
#define EtPicoContext 0x650

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
#define ThCycleTime 0x48
#define ThCurrentRunTime 0x50
#define ThVfpState 0x230
#define ThInitialStack 0x28
#define ThStackLimit 0x30
#define ThKernelStack 0x58
#define ThThreadLock 0x40
#define ThApcState 0x90
#define ThProcess 0x240
#define ThNextProcessor 0x238
#define ThAdjustReason 0x256
#define ThAdjustIncrement 0x257
#define ThWaitReason 0x2a3
#define ThRunning 0x69
#define ThAlerted 0x6a
#define ThWaitTime 0x1ac
#define ThCombinedApcDisable 0x1dc
#define ThKernelApcDisable 0x1dc
#define ThSpecialApcDisable 0x1de
#define ThTeb 0xe8
#define ThTimer 0xf8
#define thProcess 0x240

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

#define ThMiscFlags 0x6c
#define ThThreadFlags 0x70
#define ThPreviousMode 0x252
#define ThContextSwitches 0x14c
#define ThState 0x17c
#define ThWaitIrql 0x17e
#define ThTrapFrame 0x88
#define ThFirstArgument 0x80
#define ThApcStateIndex 0x26a
#define ThSystemCallNumber 0x78
#define ThWin32Thread 0x1c0
#define ThStackBase 0x38
#define ThLegoData 0x2f0
#define KernelThreadObjectLength 0x4a0
#define ExecutiveThreadObjectLength 0x910


//
// Timer object Structure Offset Definitions
//

#define TiType 0x0
#define TiSize 0x2
#define TiSignalState 0x4
#define TiDueTime 0x18
#define TiTimerListEntry 0x20
#define TiDpc 0x30
#define TiPeriod 0x3c
#define TimerObjectLength 0x40


//
// Wait Block Structure Offset Definitions
//

#define WbWaitListEntry 0x0
#define WbThread 0x18
#define WbObject 0x20
#define WbWaitKey 0x12
#define WbWaitType 0x10

//
// Fiber Structure Offset Definitions
//

#define FbFiberData 0x0
#define FbExceptionList 0x8
#define FbStackBase 0x10
#define FbStackLimit 0x18
#define FbDeallocationStack 0x20
#define FbFiberContext 0x30
#define FbWx86Tib 0x3c0
#define FbActivationContextStackPointer 0x3c8
#define FbFlsData 0x3d0
#define FbGuaranteedStackBytes 0x3d8
#define FbTebFlags 0x3dc

//
// ARM64EC Fiber Structure Offset Definitions
//

#define EcFbFiberData 0x0
#define EcFbExceptionList 0x8
#define EcFbStackBase 0x10
#define EcFbStackLimit 0x18
#define EcFbDeallocationStack 0x20
#define EcFbFiberContext 0x30
#define EcFbWx86Tib 0x500
#define EcFbActivationContextStackPointer 0x508
#define EcFbFlsData 0x510
#define EcFbGuaranteedStackBytes 0x518
#define EcFbTebFlags 0x51c

//
// Process Environment Block Structure Offset Definitions
//

#define PeBeingDebugged 0x2
#define PeProcessParameters 0x20
#define PeKernelCallbackTable 0x58
#define ProcessEnvironmentBlockLength 0x7d0

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
#define SERVICE_TABLE_SHIFT 0x7
#define SERVICE_TABLE_MASK 0x20
#define SERVICE_TABLE_TEST 0x20

#define SdBase 0x0
#define SdLimit 0x10
#define SdNumber 0x18
#define SdLength 0x20

//
// CHPEV2 EC Code Range Bitmap
//

#define PeEcCodeBitMap 0x368

//
// CHPEV2 Per-Thread Emulation Structure Definitions
//

#define Cv2ciInSimulation 0x0
#define Cv2ciInSyscallCallback 0x1
#define Cv2ciEmulatorData 0x28
#define Cv2ciEmulatorData2 0x30
#define Cv2ciEmulatorData3 0x38
#define Cv2ciEmulatorData4 0x40
#define Cv2ciEmulatorDataInline 0x50
#define Cv2ciEmulatorStackBase 0x8
#define Cv2ciEmulatorStackLimit 0x10
#define Cv2ciContextAmd64 0x18
#define Cv2ciSuspendDoorbell 0x20

//
// Thread Environment Block Structure Offset Definitions
//

#define TeCmTeb 0x0
#define TeStackBase 0x8
#define TeStackLimit 0x10
#define TeFiberData 0x20
#define TeSelf 0x30
#define TeEnvironmentPointer 0x38
#define TeClientId 0x40
#define TeActiveRpcHandle 0x50
#define TeThreadLocalStoragePointer 0x58
#define TeCountOfOwnedCriticalSections 0x6c
#define TePeb 0x60
#define TeCsrClientThread 0x70
#define TeWOW32Reserved 0x100
#define TeSoftFpcr 0x10c
#define TeExceptionCode 0x2c0
#define TeActivationContextStackPointer 0x2c8
#define TeInstrumentationCallbackSp 0x2d0
#define TeInstrumentationCallbackPreviousPc 0x2d8
#define TeInstrumentationCallbackPreviousSp 0x2e0
#define TeUnalignedLoadStoreExceptions 0x2ed
#define TeGdiClientPID 0x7f0
#define TeGdiClientTID 0x7f4
#define TeGdiThreadLocalInfo 0x7f8
#define TeglDispatchTable 0x9f0
#define TeglReserved1 0x1138
#define TeglReserved2 0x1220
#define TeglSectionInfo 0x1228
#define TeglSection 0x1230
#define TeglTable 0x1238
#define TeglCurrentRC 0x1240
#define TeglContext 0x1248
#define TeDeallocationStack 0x1478
#define TeTlsSlots 0x1480
#define TeTlsExpansionSlots 0x1780
#define TeLastErrorValue 0x68
#define TeVdm 0x1690
#define TeInstrumentation 0x16b8
#define TeGdiBatchCount 0x1740
#define TeGuaranteedStackBytes 0x1748
#define TeChpeV2CpuAreaInfo 0x1788
#define TeFlsData 0x17c8
#define ThreadEnvironmentBlockLength 0x1850
#define CmThreadEnvironmentBlockOffset 0x2000
#define TLS_MINIMUM_AVAILABLE 0x40
#define TLS_EXPANSION_SLOTS 0x400

//
// Lock Queue Structure Offset Definitions
//

#define LOCK_QUEUE_WAIT 0x1
#define LOCK_QUEUE_OWNER 0x2
#define LOCK_QUEUE_HEADER_SIZE 0x10


#define LqNext 0x0
#define LqLock 0x8

#define LqhLockQueue 0x0
#define LqhOldIrql 0x10
#define LqhNext 0x0
#define LqhLock 0x8

//
// Kernel Stack Control Structure Offset (relative to initial stack pointer) Definitions
//

#define KSTACK_CONTROL_LENGTH 0x40
#define KcPreviousBase 0x20
#define KcPreviousLimit 0x28
#define KcPreviousKernel 0x30
#define KcPreviousInitial 0x38
#define KcCurrentBase 0x0
#define KcActualLimit 0x8
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
#define PbEntropyCount 0xf78
#define PbEntropyBuffer 0xf7c
#define KENTROPY_TIMING_INTERRUPTS_PER_BUFFER 0x400
#define KENTROPY_TIMING_BUFFER_MASK 0x7ff
#define KENTROPY_TIMING_ANALYSIS 0x0

//
// Priority state definitions
//

#define KPRIORITY_STATE_PRIORITY_BITMASK 0x7f
#define PERF_SYSCALL_FLAG_BIT 0x6

//
// Special Register Structure Offset Definition
//

#define KsElr_El1 0x0
#define KsSpsr_El1 0x8
#define KsTpidr_El0 0x10
#define KsTpidrro_El0 0x18
#define KsTpidr_El1 0x20
#define KsKernelBcr 0x68
#define KsKernelBvr 0x28
#define KsKernelWcr 0x98
#define KsKernelBvr 0x28

//
// ARM Architectural State Structure Offset Definitions
//

#define AaMidr_El1 0x0
#define AaSctlr_El1 0x8
#define AaActlr_El1 0x10
#define AaCpacr_El1 0x18
#define AaTcr_El1 0x20
#define AaTtbr0_El1 0x28
#define AaTtbr1_El1 0x30
#define AaEsr_El1 0x38
#define AaFar_El1 0x40
#define AaPmcr_El0 0x48
#define AaPmcntenset_El0 0x50
#define AaPmccntr_El0 0x58
#define AaPmxevcntr_El0 0x60
#define AaPmxevtyper_El0 0x158
#define AaPmovsclr_El0 0x250
#define AaPmselr_El0 0x258
#define AaPmuserenr_El0 0x260
#define AaMair_El1 0x268
#define AaVbar_El1 0x270

//
// Processor Control Region Structure Offset Definitions
//

#define PCR_BTI_MITIGATION_NONE 0x0
#define PCR_BTI_MITIGATION_TRAP_HVC 0x1
#define PCR_BTI_MITIGATION_TRAP_SMC 0x2
#define PCR_BTI_MITIGATION_CSWAP_HVC 0x4
#define PCR_BTI_MITIGATION_CSWAP_SMC 0x8
#define PCR_BTI_MITIGATION_TRAP_HVC_BIT 0x0
#define PCR_BTI_MITIGATION_TRAP_SMC_BIT 0x1
#define PCR_BTI_MITIGATION_CSWAP_HVC_BIT 0x2
#define PCR_BTI_MITIGATION_CSWAP_SMC_BIT 0x3
#define ARM64_ASID_KVA_SHADOW 0x8000
#define PSCI_FUNCTION_CODE_SMCCC_ARCH_WORKAROUND_1 0x80008000
#define PcSelf 0x18
#define PcLockArray 0x28
#define PcCurrentIrql 0x38
#define PcTeb 0x30
#define PcStallScaleFactor 0x40
#define PcBtiMitigation 0x4c
#define PcSsbMitigationFlags 0x4d
#define PcPanicStorage 0x50
#define PcHalReserved 0x88
#define PcPrcb 0x980
#define PcKvaUserModeTtbr1 0xf8
#define PcIdleHalt 0x982
#define PcCurrentThread 0x988
#define PcNextThread 0x990
#define PcIdleThread 0x998
#define PcNestingLevel 0x9a0
#define PcNumber 0x9a4
#define PcGroup 0x10e8
#define PcPrcbLock 0x9a8
#define PcGroupSetMember 0x10e0
#define PcFeatureBits 0x1214
#define PcVirtualApicAssist 0x2128
#define PcTrappedSecurityDomain 0x1578
#define PcEmulatedFaultSyndrome 0x1230
#define PcEmulatedAccess 0x122c
#define TlThread 0x0
#define TlCpuNumber 0x8
#define TlTrapType 0x9
#define TlPadding 0xa
#define TlCpsr 0xc
#define TlX0 0x10
#define TlX1 0x18
#define TlX2 0x20
#define TlX3 0x28
#define TlX4 0x30
#define TlX5 0x38
#define TlX6 0x40
#define TlX7 0x48
#define TlFp 0x50
#define TlLr 0x58
#define TlSp 0x60
#define TlPc 0x68
#define TRAP_TYPE_INTERRUPT 0x1
#define TRAP_TYPE_SYSCALL 0x2
#define TRAP_TYPE_UNDEFINED 0x3
#define TRAP_TYPE_DATA_ABORT 0x4
#define TRAP_TYPE_PREFETCH_ABORT 0x5
#define TRAP_TYPE_RESET 0x6
#define TRAP_TYPE_FIQ 0x7
#define PcInterruptCount 0x1880
#define PcDebuggerSavedIRQL 0x1899
#define PcDeferredReadyListHead 0x1388
#define PcInterruptCount 0x1880
#define PcSystemCalls 0x13b8
#define PcDpcRoutineActive 0x149a
#define PcDeferredReadyListHead 0x1388
#define PcSkipTick 0x1898
#define PcStartCycles 0x18c8
#define PcSpBase 0x1480
#define ProcessorControlRegisterLength 0x29fc0

//
// Defines for user shared data
//

#define USER_SHARED_DATA 0xfffff78000000000
#define MM_SHARED_USER_DATA_VA 0x000000007ffe0000
#define UsTickCountMultiplier 0x4
#define UsTickCount 0x320
#define UsInterruptTime 0x8
#define UsSystemTime 0x14
#define UsProcessorFeatures 0x274

//
// Defines for user address space.
//

#define MM_LOWEST_USER_ADDRESS 0x0000000000010000

#define ARM64_CPACR_VFP_MASK 0x300000
#define ARM64_CPACR_VFP_MASK_BIT 0x14

//
// Processor Block Structure Offset Definitions
//

#define PbNestingLevel 0x20
#define PbIdleHalt 0x2
#define PbCurrentThread 0x8
#define PbNextThread 0x10
#define PbIdleThread 0x18
#define PbNumber 0x24
#define PbPrcbLock 0x28
#define PbKeSpinLockOrdering 0xbf4
#define KI_SPINLOCK_ORDER_PRCB_LOCK 0x80
#define PbProcessorState 0x40
#define PbHalReserved 0x700
#define PbMinorVersion 0x750
#define PbMajorVersion 0x752
#define PbBuildType 0x754
#define PbCoresPerPhysicalProcessor 0x756
#define PbLogicalProcessorsPerCore 0x757
#define PbPriorityState 0x30
#define PbLockQueue 0x780
#define PbPPLookasideList 0x900
#define PbPPNPagedLookasideList 0x6780
#define PbPPPagedLookasideList 0x7380
#define PbPacketBarrier 0xa00
#define PbDeferredReadyListHead 0xa08
#define PbLookasideIrpFloat 0xa58
#define PbRequestMailbox 0x9600
#define PbMailbox 0xa80
#define PbDpcGate 0xb80
#define PbWaitListHead 0xc00
#define PbCcFastMdlReadNoWait 0x1180
#define PbPowerState 0x1200
#define PbSpinLockAcquireCount 0x1800
#define PbSystemCalls 0xa38
#define PbReadOperationCount 0xa5c
#define PbWriteOperationCount 0xa60
#define PbOtherOperationCount 0xa64
#define PbReadTransferCount 0xa68
#define PbWriteTransferCount 0xa70
#define PbOtherTransferCount 0xa78
#define PbContextSwitches 0xa3c
#define PbIpiFrozen 0xa8c
#define PbDpcList 0xa98
#define PbDpcLock 0xaa8
#define PbDpcCount 0xab4
#define PbDpcStack 0xaf8
#define PbSpBase 0xb00
#define PbMaximumDpcQueueDepth 0xb08
#define PbDpcRequestRate 0xb0c
#define PbMinimumDpcRate 0xb10
#define PbDpcRoutineActive 0xb1a
#define PbDpcRequestSummary 0xb1c
#define PbNormalDpcState 0xb1c
#define PbDpcLastCount 0xb14
#define PbQuantumEnd 0xb19
#define PbIdleSchedule 0xb1b
#define PbDispatcherReadyListHead 0xd00
#define PbInterruptCount 0xf00
#define PbKernelTime 0xf04
#define PbUserTime 0xf08
#define PbDpcTime 0xf0c
#define PbInterruptTime 0xf10
#define PbAdjustDpcThreshold 0xf14
#define PbStartCycles 0xf48
#define PbPageColor 0x10e0
#define PbNodeColor 0x10e4
#define PbNodeShiftedColor 0x10e8
#define PbSecondaryColorMask 0x10ec
#define PbCycleTime 0x10f0
#define PbFastReadNoWait 0xa40
#define PbFastReadWait 0xa44
#define PbFastReadNotPossible 0xa48
#define PbCopyReadNoWait 0xa4c
#define PbCopyReadWait 0xa50
#define PbCopyReadNoWaitMiss 0xa54
#define PbAlignmentFixupCount 0x1470
#define PbExceptionDispatchCount 0xf34
#define PbProcessorVendorString 0x890
#define PbFeatureBits 0x894
#define PbPanicStackBase 0x18d8

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
#define THREAD_FLAGS_CYCLE_PROFILING_BIT 0x0
#define DEBUG_ACTIVE_EMULATION_THREAD_BIT 0x6

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
#define KI_USER_PER_PROCESS_IP_AUTH_ENABLED_BIT 0x0
#define KI_USER_GLOBAL_IP_AUTH_ENABLED_BIT 0x1
#define KI_KERNEL_IP_AUTH_ENABLED_BIT 0x2

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

#define CPSRM_EL3h 0xd
#define CPSRM_EL3t 0xc
#define CPSRM_EL2h 0x9
#define CPSRM_EL2t 0x8
#define CPSRM_EL1h 0x5
#define CPSRM_EL1t 0x4
#define CPSRM_EL0t 0x0
#define CPSRM_MASK 0xf
#define SYSCALL_PSR 0x0
#define CPSREL_3 0xc
#define CPSREL_2 0x8
#define CPSREL_1 0x4
#define CPSREL_0 0x0
#define CPSREL_MASK 0xc
#define CPSREL_1_BIT 0x2

//
// DAIF enable/disables
//

#define DAIF_DEBUG 0x200
#define DAIF_ABORT 0x100
#define DAIF_INT 0x80
#define DAIF_FIQ 0x40
#define DAIF_DEBUG_BIT 0x9
#define DAIF_ABORT_BIT 0x8
#define DAIF_INT_BIT 0x7
#define DAIF_FIQ_BIT 0x6

//
// NZCV flags
//

#define NZCV_N 0x80000000
#define NZCV_Z 0x40000000
#define NZCV_C 0x20000000
#define NZCV_V 0x10000000
#define NZCV_N_BIT 0x1f
#define NZCV_Z_BIT 0x1e
#define NZCV_C_BIT 0x1d
#define NZCV_V_BIT 0x1c

//
// New ARM64 CSPR flags
//

#define CPSRM_T 0x20
#define CPSRM_AA32 0x10
#define CPSR_IL 0x100000
#define CPSR_SS 0x200000
#define CPSR_SSBS32 0x800000
#define CPSR_SSBS64 0x1000
#define CPSR_IL_BIT 0x14
#define CPSR_SS_BIT 0x15
#define CPSR_SSBS32_BIT 0x17
#define CPSR_SSBS64_BIT 0xc

//
// FPCR modes
//

#define FPCRM_AHP 0x4000000
#define FPCRM_DN 0x2000000
#define FPCRM_FZ 0x1000000
#define FPCRM_AHP_BIT 0x1a
#define FPCRM_DN_BIT 0x19
#define FPCRM_FZ_BIT 0x18
#define FPCRM_RMODE_MASK 0xc00000
#define FPCRM_RMODE_RN 0x0
#define FPCRM_RMODE_RP 0x400000
#define FPCRM_RMODE_RM 0x800000
#define FPCRM_RMODE_RZ 0xc00000

//
// FPCR exception controls
//

#define FPCR_IDE 0x8000
#define FPCR_IXE 0x1000
#define FPCR_UFE 0x800
#define FPCR_OFE 0x400
#define FPCR_DZE 0x200
#define FPCR_IOE 0x100

//
// FPSR exception states
//

#define FPSR_IDC 0x80
#define FPSR_IXC 0x10
#define FPSR_UFC 0x8
#define FPSR_OFC 0x4
#define FPSR_DZC 0x2
#define FPSR_IOC 0x1

//
// ARMv8 Status Registers
//

#define ARM64_SPSR_EL1 0x4200
#define ARM64_SPSR_EL2 0x6200
#define ARM64_ELR_EL1 0x4201
#define ARM64_ELR_EL2 0x6201
#define ARM64_SP_EL0 0x4208
#define ARM64_SP_EL1 0x6208
#define ARM64_SP_EL2 0x7208
#define ARM64_SPSel 0x4210
#define ARM64_DAIF 0x5a11
#define ARM64_CurrentEL 0x4212
#define ARM64_NZCV 0x5a10
#define ARM64_FPCR 0x5a20
#define ARM64_FPSR 0x5a21
#define ARM64_DSPSR 0x5a28
#define ARM64_DLR 0x5a29

//
// ID and feature registers
//

#define ARM64_MIDR_EL1 0x4000
#define ARM64_VPIDR_EL2 0x6000
#define ARM64_CTR_EL0 0x5801
#define ARM64_MPIDR_EL1 0x4005
#define ARM64_VMPIDR_EL2 0x6005
#define ARM64_ID_AA64PFR0_EL1 0x4020
#define ARM64_ID_AA64PFR1_EL1 0x4021
#define ARM64_ID_AA64DFR0_EL1 0x4028
#define ARM64_ID_AA64DFR1_EL1 0x4029
#define ARM64_ID_AA64AFR0_EL1 0x402c
#define ARM64_ID_AA64AFR1_EL1 0x402d
#define ARM64_ID_AA64ISAR0_EL1 0x4030
#define ARM64_ID_AA64ISAR1_EL1 0x4031
#define ARM64_ID_AA64MMFR0_EL1 0x4038
#define ARM64_ID_AA64MMFR1_EL1 0x4039
#define ARM64_ID_AA64MMFR2_EL1 0x403a

//
// System control registers
//

#define ARM64_SCTLR_EL1 0x4080
#define ARM64_SCTLR_EL2 0x6080
#define ARM64_HCR_EL2 0x6088
#define ARM64_HCR_EL2_VM 0x0000000000000001
#define ARM64_HCR_EL2_FMO 0x0000000000000008
#define ARM64_HCR_EL2_IMO 0x0000000000000010
#define ARM64_HCR_EL2_AMO 0x0000000000000020
#define ARM64_HCR_EL2_TID3 0x0000000000040000
#define ARM64_HCR_EL2_TSC 0x0000000000080000
#define ARM64_HCR_EL2_TGE 0x0000000008000000
#define ARM64_HCR_EL2_RW 0x0000000080000000
#define ARM64_ACTLR_EL1 0x4081
#define ARM64_ACTLR_EL2 0x6081
#define ARM64_CPACR_EL1 0x4082
#define ARM64_SCR_EL3 0x7088
#define ARM64_CPTR_EL3 0x708a

//
// Memory protection and control registers
//

#define ARM64_TTBR0_EL1 0x4100
#define ARM64_TTBR0_EL2 0x6100
#define ARM64_TTBR1_EL1 0x4101
#define ARM64_TCR_EL1 0x4102
#define ARM64_TCR_EL2 0x6102
#define ARM64_TCR_EL2_TBI 0x100000
#define ARM64_TCR_EL2_PASize_SHIFT 0x10
#define ARM64_TCR_IPASize_SHIFT 0x20
#define ARM64_TCR_IPASize_MASK 0x0000000700000000
#define ARM64_TCR_PASize_MASK 0x0000000000070000
#define ARM64_TCR_TBI0 0x0000002000000000
#define ARM64_ESR_EL1 0x4290
#define ARM64_ESR_EL2 0x6290
#define ARM64_FAR_EL1 0x4300
#define ARM64_FAR_EL2 0x6300
#define ARM64_HPFAR_EL2 0x6304
#define ARM64_AFSR0_EL2 0x6288
#define ARM64_AFSR1_EL2 0x6289
#define ARM64_TCR_T0SZ_MASK 0x3f
#define ARM64_TCR_IRGN0_MASK 0x300
#define ARM64_TCR_ORGN0_MASK 0xc00
#define ARM64_TCR_SH0_MASK 0x3000
#define ARM64_TCR_TG0_MASK 0xc000

//
// ARM Cache Operations
//

#define ARM64_DCZID_EL0 0x5807
#define ARM64_IC_IALLUIS 0x388
#define ARM64_IC_IALLU 0x3a8
#define ARM64_IC_IVAU 0x1ba9
#define ARM64_DC_ZVA 0x1ba1
#define ARM64_DC_IVAC 0x3b1
#define ARM64_DC_ISW 0x3b2
#define ARM64_DC_CVAC 0x1bd1
#define ARM64_DC_CSW 0x3d2
#define ARM64_DC_CVAU 0x1bd9
#define ARM64_DC_CIVAC 0x1bf1
#define ARM64_DC_CISW 0x3f2

//
// ARM Translation Operations
//

#define ARM64_PAR_EL1 0x43a0
#define ARM64_AT_S1E1R 0x3c0
#define ARM64_AT_S1E1W 0x3c1
#define ARM64_AT_S1E0R 0x3c2
#define ARM64_AT_S1E0W 0x3c3
#define ARM64_AT_S1E2R 0x23c0

//
// TLB maintenance operations
//

#define ARM64_TLBI_VMALLE1 0x438
#define ARM64_TLBI_ALLE1 0x243c
#define ARM64_TLBI_ALLE2 0x2438
#define ARM64_TLBI_VAE1 0x439
#define ARM64_TLBI_ASIDE1 0x43a
#define ARM64_TLBI_VAAE1 0x43b
#define ARM64_TLBI_VALE1 0x43d
#define ARM64_TLBI_VAALE1 0x43f
#define ARM64_TLBI_VMALLE1IS 0x418
#define ARM64_TLBI_VAE1IS 0x419
#define ARM64_TLBI_ASIDE1IS 0x41a
#define ARM64_TLBI_VAAE1IS 0x41b
#define ARM64_TLBI_VALE1IS 0x41d
#define ARM64_TLBI_VAALE1IS 0x41f

//
// Performance counter registers
//

#define ARM64_PMCCFILTR_EL0 0x5f7f
#define ARM64_PMCCFILTR_NSH 0x8000000
#define ARM64_MDCR_EL2 0x6089
#define ARM64_MDCR_HPME 0x80
#define ARM64_PMCR_EL0 0x5ce0
#define ARM64_PMCNTENSET_EL0 0x5ce1
#define ARM64_PMCNTENCLR_EL0 0x5ce2
#define ARM64_PMCNTEN_PMCCNT 0x80000000
#define ARM64_PMOVSSET_EL0 0x5cf3
#define ARM64_PMOVSCLR_EL0 0x5ce3
#define ARM64_PMSWINC_EL0 0x5ce4
#define ARM64_PMSELR_EL0 0x5ce5
#define ARM64_PMCCNTR_EL0 0x5ce8
#define ARM64_PMXEVTYPER_EL0 0x5ce9
#define ARM64_PMXEVCNTR_EL0 0x5cea
#define ARM64_PMUSERENR_EL0 0x5cf0
#define ARM64_PMINTENSET_EL1 0x44f1
#define ARM64_PMINTENCLR_EL1 0x44f2

//
// Memory remap registers
//

#define ARM64_MAIR_EL1 0x4510
#define ARM64_MAIR_EL2 0x6510
#define ARM64_AMAIR_EL2 0x6518

//
// Security extensions registers
//

#define ARM64_VBAR_EL1 0x4600
#define ARM64_VBAR_EL2 0x6600
#define ARM64_ISR_EL1 0x4608

//
// Process, context and thread ID registers
//

#define ARM64_TPIDR_EL0 0x5e82
#define ARM64_TPIDRRO_EL0 0x5e83
#define ARM64_TPIDR_EL1 0x4684
#define ARM64_TPIDR_EL2 0x6682

//
// Cache information registers
//

#define ARM64_CCSIDR_EL1 0x4800
#define ARM64_CLIDR_EL1 0x4801
#define ARM64_AIDR_EL1 0x4807
#define ARM64_CSSELR_EL1 0x5000

//
// CP14 debugging registers
//

#define ARM64_MDCCSR_EL0 0x1808
#define ARM64_DBGDTRRX_EL0 0x1828
#define ARM64_DBGDTRTX_EL0 0x1828
#define ARM64_OSDTRRX_EL1 0x2
#define ARM64_MDSCR_EL1 0x12
#define ARM64_OSDTRTX_EL1 0x1a
#define ARM64_DBGBVR0_EL1 0x4
#define ARM64_DBGBVR1_EL1 0xc
#define ARM64_DBGBVR2_EL1 0x14
#define ARM64_DBGBVR3_EL1 0x1c
#define ARM64_DBGBVR4_EL1 0x24
#define ARM64_DBGBVR5_EL1 0x2c
#define ARM64_DBGBVR6_EL1 0x34
#define ARM64_DBGBVR7_EL1 0x3c
#define ARM64_DBGBVR8_EL1 0x44
#define ARM64_DBGBVR9_EL1 0x4c
#define ARM64_DBGBVR10_EL1 0x54
#define ARM64_DBGBVR11_EL1 0x5c
#define ARM64_DBGBVR12_EL1 0x64
#define ARM64_DBGBVR13_EL1 0x6c
#define ARM64_DBGBVR14_EL1 0x74
#define ARM64_DBGBVR15_EL1 0x7c
#define ARM64_DBGBCR0_EL1 0x5
#define ARM64_DBGBCR1_EL1 0xd
#define ARM64_DBGBCR2_EL1 0x15
#define ARM64_DBGBCR3_EL1 0x1d
#define ARM64_DBGBCR4_EL1 0x25
#define ARM64_DBGBCR5_EL1 0x2d
#define ARM64_DBGBCR6_EL1 0x35
#define ARM64_DBGBCR7_EL1 0x3d
#define ARM64_DBGBCR8_EL1 0x45
#define ARM64_DBGBCR9_EL1 0x4d
#define ARM64_DBGBCR10_EL1 0x55
#define ARM64_DBGBCR11_EL1 0x5d
#define ARM64_DBGBCR12_EL1 0x65
#define ARM64_DBGBCR13_EL1 0x6d
#define ARM64_DBGBCR14_EL1 0x75
#define ARM64_DBGBCR15_EL1 0x7d
#define ARM64_DBGWVR0_EL1 0x6
#define ARM64_DBGWVR1_EL1 0xe
#define ARM64_DBGWVR2_EL1 0x16
#define ARM64_DBGWVR3_EL1 0x1e
#define ARM64_DBGWVR4_EL1 0x26
#define ARM64_DBGWVR5_EL1 0x2e
#define ARM64_DBGWVR6_EL1 0x36
#define ARM64_DBGWVR7_EL1 0x3e
#define ARM64_DBGWVR8_EL1 0x46
#define ARM64_DBGWVR9_EL1 0x4e
#define ARM64_DBGWVR10_EL1 0x56
#define ARM64_DBGWVR11_EL1 0x5e
#define ARM64_DBGWVR12_EL1 0x66
#define ARM64_DBGWVR13_EL1 0x6e
#define ARM64_DBGWVR14_EL1 0x76
#define ARM64_DBGWVR15_EL1 0x7e
#define ARM64_DBGWCR0_EL1 0x7
#define ARM64_DBGWCR1_EL1 0xf
#define ARM64_DBGWCR2_EL1 0x17
#define ARM64_DBGWCR3_EL1 0x1f
#define ARM64_DBGWCR4_EL1 0x27
#define ARM64_DBGWCR5_EL1 0x2f
#define ARM64_DBGWCR6_EL1 0x37
#define ARM64_DBGWCR7_EL1 0x3f
#define ARM64_DBGWCR8_EL1 0x47
#define ARM64_DBGWCR9_EL1 0x4f
#define ARM64_DBGWCR10_EL1 0x57
#define ARM64_DBGWCR11_EL1 0x5f
#define ARM64_DBGWCR12_EL1 0x67
#define ARM64_DBGWCR13_EL1 0x6f
#define ARM64_DBGWCR14_EL1 0x77
#define ARM64_DBGWCR15_EL1 0x7f
#define ARM64_OSLAR_EL1 0x84
#define ARM64_OSLSR_EL1 0x8c
#define ARM64_OSDLR_EL1 0x9c
#define ARM64_DBGPRCR_EL1 0xa4

//
// Counter-Timer Control Registers
//

#define ARM64_CNT_HCTL_EL2 0x6708
#define ARM64_CNT_HCTL_EL1PCTEN 0x0000000000000001
#define ARM64_CNT_HCTL_EL1PCEN 0x0000000000000002
#define ARM64_CNTV_OFF_EL2 0x6703

//
// Interrupt Controller Registers
//

#define ARM64_ICC_SRE_EL2 0x664d

//
// Pointer Authentication Key Registers
//

#define ARM64_APIBKeyHi_EL1 0x410b
#define ARM64_APIBKeyLo_EL1 0x410a

//
// SCTLR bits
//

#define ARM64_SCTLR_M 0x1
#define ARM64_SCTLR_A 0x2
#define ARM64_SCTLR_C 0x4
#define ARM64_SCTLR_SA 0x8
#define ARM64_SCTLR_SA0 0x10
#define ARM64_SCTLR_CP15BEN 0x20
#define ARM64_SCTLR_NAA 0x40
#define ARM64_SCTLR_ITD 0x80
#define ARM64_SCTLR_SED 0x100
#define ARM64_SCTLR_UMA 0x200
#define ARM64_SCTLR_I 0x1000
#define ARM64_SCTLR_DZE 0x4000
#define ARM64_SCTLR_UCT 0x8000
#define ARM64_SCTLR_nTWI 0x10000
#define ARM64_SCTLR_nTWE 0x40000
#define ARM64_SCTLR_WXN 0x80000
#define ARM64_SCTLR_E0E 0x1000000
#define ARM64_SCTLR_EE 0x2000000
#define ARM64_SCTLR_UCI 0x4000000
#define ARM64_SCTLR_EnIB 0x40000000

//
// MDSCR bits
//

#define ARM64_MDSCR_SS 0x1
#define ARM64_MDSCR_MDE 0x8000
#define ARM64_MDSCR_KDE 0x2000
#define ARM64_MDSCR_SS_KDE_MDE 0xa001
#define ARM64_MDSCR_SS_BIT 0x0

//
// BRK opcodes
//

#define ARM64_BREAKPOINT 0xf000
#define ARM64_ASSERT 0xf001
#define ARM64_DEBUG_SERVICE 0xf002
#define ARM64_FASTFAIL 0xf003
#define ARM64_DIVIDE_BY_0 0xf004
#define ARM64_EMULATE_ATOMIC16 0xf801
#define ARM64_EMULATE_ATOMIC32 0xf802
#define ARM64_EMULATE_ATOMIC64 0xf803

//
// Miscellaneous Definitions
//

#define MAXIMUM_PROCESSORS 0x40
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
#define FAST_FAIL_CONTROL_INVALID_RETURN_ADDRESS 0x39
#define BASE_PRIORITY_THRESHOLD 0x8
#define LOW_REALTIME_PRIORITY 0x10
#define KERNEL_LARGE_STACK_COMMIT 0x8000
#define KERNEL_LARGE_STACK_SIZE 0x12000
#define DOUBLE_FAULT_STACK_SIZE 0x8000
#define BREAKPOINT_BREAK 0x0
#define BREAKPOINT_HW_BREAK 0x7
#define BREAKPOINT_HW_WATCH 0x6
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
#define STATUS_UNSUCCESSFUL 0xc0000001
#define SKCALL_MAXPARAMETERS 0xc

//
// Exception Frame Offset Definitions and Length
//

#define ExX19 0x0
#define ExX20 0x8
#define ExX21 0x10
#define ExX22 0x18
#define ExX23 0x20
#define ExX24 0x28
#define ExX25 0x30
#define ExX26 0x38
#define ExX27 0x40
#define ExX28 0x48
#define ExFp 0x50
#define ExReturn 0x58

#define KEXCEPTION_FRAME_LENGTH 0x60
#define EXCEPTION_RECORD_LENGTH 0xa0

#define Enable_Feature_DTrace 0x1

//
// Kernel Dynamic Tracing flags
//

#define KI_DYNAMIC_TRACE_SYSCALL_FLAG_BIT 0x0


//
// Jump Offset Definitions and Length
//

#define JbFrame 0x0
#define JbX19 0x10
#define JbX20 0x18
#define JbX21 0x20
#define JbX22 0x28
#define JbX23 0x30
#define JbX24 0x38
#define JbX25 0x40
#define JbX26 0x48
#define JbX27 0x50
#define JbX28 0x58
#define JbFp 0x60
#define JbLr 0x68
#define JbSp 0x70
#define JbFpcr 0x78
#define JbFpsr 0x7c
#define JbD 0x80

//
// Switch Frame Offset Definitions and Length
//

#define SwApcBypass 0x0
#define SwFp 0x10
#define SwReturn 0x18

#define KSWITCH_FRAME_LENGTH 0x20

//
// Start System Thread Frame Offset Definitions and Length
//

#define SfX0 0x0
#define SfX1 0x8
#define SfX2 0x10
#define SfReturn 0x18

#define KSTART_FRAME_LENGTH 0x20


//
// Trap Frame Definitions
//

#define KEXCEPTION_ACTIVE_INTERRUPT_FRAME 0x0
#define KEXCEPTION_ACTIVE_EXCEPTION_FRAME 0x1
#define KEXCEPTION_ACTIVE_SERVICE_FRAME 0x2
#define KTRAP_FRAME_SIGNATURE 0x7072544b

#define TrReserved 0x4
#define TrFaultAddress 0x8
#define TrTrapFrame 0x8
#define TrExceptionActive 0x0
#define TrContextFromKFramesUnwound 0x1
#define TrDebugRegistersValid 0x2
#define TrPreviousMode 0x3
#define TrPreviousIrql 0x3
#define TrVfpState 0x10
#define TrBvr 0x38
#define TrBcr 0x18
#define TrWvr 0x80
#define TrWcr 0x78
#define TrX 0xa0
#define TrFp 0x140
#define TrLr 0x138
#define TrSp 0x98
#define TrPc 0x148
#define TrSpsr 0x90
#define TrEsr 0x94

#define KTRAP_FRAME_LENGTH 0x150
#define KTRAP_FRAME_ARGUMENTS 0x50
#define ARM64_RED_ZONE_BYTES 0x10

//
// Usermode Callout User Frame Definitions
//

#define CkBuffer 0x0
#define CkLength 0x8
#define CkApiNumber 0xc
#define CkOriginalLr 0x18
#define CkPc 0x28
#define CkSp 0x20
#define CalloutFrameLength 0x30

//
// Machine Frame Offset Definitions
//

#define MfPc 0x8
#define MfSp 0x0
#define MachineFrameLength 0x10

//
// DPC Stack Frame Defintions
//

#define DpSp 0x0
#define DpPc 0x8

//
// Context Frame Offset and Flag Definitions
//

#define CONTEXT_FULL 0x400007
#define CONTEXT_CONTROL 0x400001
#define CONTEXT_INTEGER 0x400002
#define CONTEXT_FLOATING_POINT 0x400004
#define CONTEXT_DEBUG_REGISTERS 0x400008

#define CxContextFlags 0x0
#define CxCpsr 0x4
#define CxX 0x8
#define CxFp 0xf0
#define CxLr 0xf8
#define CxSp 0x100
#define CxPc 0x108
#define CxFpsr 0x314
#define CxFpcr 0x310
#define CxV 0x110
#define CxBvr 0x338
#define CxBcr 0x318
#define CxWvr 0x380
#define CxWcr 0x378
#define CONTEXT_FRAME_LENGTH 0x390
#define CONTEXT_ALIGN 0x10
#define DEBUG_ACTIVE_DBG 0x1
#define DEBUG_ACTIVE_DBG_BIT 0x0
#define DEBUG_ACTIVE_DBG_INSTRUMENTED 0x3
#define DEBUG_ACTIVE_INSTRUMENTED 0x2
#define DEBUG_ACTIVE_MINIMAL_THREAD 0x4
#define DEBUG_ACTIVE_MINIMAL_THREAD_BIT 0x2

//
// ARM64EC Context Frame Offsets
//

#define EcContextFlags 0x30
#define EcAMD64_MxCsr_copy 0x34
#define EcAMD64_SegCs 0x38
#define EcAMD64_SegDs 0x3a
#define EcAMD64_SegEs 0x3c
#define EcAMD64_SegFs 0x3e
#define EcAMD64_SegGs 0x40
#define EcAMD64_SegSs 0x42
#define EcAMD64_EFlags 0x44
#define EcAMD64_Dr0 0x48
#define EcAMD64_Dr1 0x50
#define EcAMD64_Dr2 0x58
#define EcAMD64_Dr3 0x60
#define EcAMD64_Dr6 0x68
#define EcAMD64_Dr7 0x70
#define EcX8 0x78
#define EcX0 0x80
#define EcX1 0x88
#define EcX27 0x90
#define EcSp 0x98
#define EcFp 0xa0
#define EcX25 0xa8
#define EcX26 0xb0
#define EcX2 0xb8
#define EcX3 0xc0
#define EcX4 0xc8
#define EcX5 0xd0
#define EcX19 0xd8
#define EcX20 0xe0
#define EcX21 0xe8
#define EcX22 0xf0
#define EcPc 0xf8
#define EcAMD64_ControlWord 0x100
#define EcAMD64_StatusWord 0x102
#define EcAMD64_TagWord 0x104
#define EcAMD64_ErrorOpcode 0x106
#define EcAMD64_ErrorOffset 0x108
#define EcAMD64_ErrorSelector 0x10c
#define EcAMD64_DataOffset 0x110
#define EcAMD64_DataSelector 0x114
#define EcAMD64_DataSelector 0x114
#define EcAMD64_MxCsr 0x118
#define EcAMD64_MxCsr_Mask 0x11c
#define EcLr 0x120
#define EcX16_0 0x128
#define EcX6 0x130
#define EcX16_1 0x138
#define EcX7 0x140
#define EcX16_2 0x148
#define EcX9 0x150
#define EcX16_3 0x158
#define EcX10 0x160
#define EcX17_0 0x168
#define EcX11 0x170
#define EcX17_1 0x178
#define EcX12 0x180
#define EcX17_2 0x188
#define EcX15 0x190
#define EcX17_3 0x198
#define EcV 0x1a0
#define EcAMD64_VectorRegister 0x300
#define EcAMD64_VectorControl 0x4a0
#define EcAMD64_DebugControl 0x4a8
#define EcAMD64_LastBranchToRip 0x4b0
#define EcAMD64_LastBranchFromRip 0x4b8
#define EcAMD64_LastExceptionToRip 0x4c0
#define EcAMD64_LastExceptionFromRip 0x4c8
#define ARM64EC_CONTEXT_LENGTH 0x4d0

//
// Dispatcher Context Structure Offset Definitions
//

#define DcControlPc 0x0
#define DcImageBase 0x8
#define DcFunctionEntry 0x10
#define DcEstablisherFrame 0x18
#define DcTargetPc 0x20
#define DcContextRecord 0x28
#define DcLanguageHandler 0x30
#define DcHandlerData 0x38
#define DcHistoryTable 0x40
#define DcScopeIndex 0x48
#define DcControlPcIsUnwound 0x4c
#define DcNonVolatileRegisters 0x50
#define VsLink 0x0
#define VsFpcr 0x8
#define VsFpsr 0xc
#define VsV 0x10
#define VFP_STATE_LENGTH 0x210


#define ARM64_ID_AA64MMFR0_EL1 0x4038
#define ARM64_ID_AA64PFR0_EL1 0x4020
#define PF_ARM_V81_ATOMIC_INSTRUCTIONS_AVAILABLE 0x22

//
// Processor State Frame Offset Definitions
//

#define PsCpuid 0xa0
#define PsControl 0xa8
#define PsAuxControl 0xb0
#define PsCpacr 0xb8
#define PsTtbControl 0xc0
#define PsTtbr0 0xc8
#define PsTtbr1 0xd0
#define PsVBARns 0x310
#define PsMemoryRemap 0x308
#define PsUsrRW 0x10
#define PsUsrRO 0x18
#define PsSvcRW 0x20
#define PsSpecialRegisters 0x0
#define PsArchState 0xa0
#define PsContextFrame 0x320
#define ProcessorStateLength 0x6b0

//
// Processor Parked Page Offset Definitions
//

#define PppArchitecturalStateVirtualAddress 0x10
#define PppArchitecturalState 0x20
#define ProcessorParkedPageLength 0x1000

//
// Processor Start Block Offset Definitions
//

#define PsbSelfMap 0x0
#define PsbTiledTtb0 0x8
#define ProcessorStartBlockLength 0x10

//
// EPROCESS
//

#define EpDebugPort 0x530
#define EpSecurityDomain 0xaa0
#define EpPointerAuthUserIpKey 0xbe8

//
// EPROCESS MitigationFlags2
//

#define PS_PROCESS_MITIGATION_FLAGS2_POINTER_AUTH_USER_IP_BIT 0x1b
#define PS_PROCESS_MITIGATION_FLAGS2_SPECULATIVE_STORE_BYPASS_DISABLE 0xd

//
// KeFeatureBits defines
//


//
// LoaderParameterBlock offsets relative to base
//

#define LpbKernelStack 0x80
#define LpbPrcb 0x88
#define LpbProcess 0x90
#define LpbThread 0x98
#define PAGE_SIZE 0x1000
#define PAGE_SHIFT 0xc
#define TRANSITION_ASID 0x0
#define ARM64_TTBRx_ASID_SHIFT 0x30

//
// KAFFINITY_EX size
//

#define AffinityExLength 0x108
#include "kxarm64.h"
;
