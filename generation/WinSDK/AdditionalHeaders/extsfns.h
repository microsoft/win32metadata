/*++

Copyright (c) Microsoft Corporation

Module Name:

    extsfns.h

Abstract:

    This header file must be included after "windows.h", "dbgeng.h", and
    "wdbgexts.h".

    This file contains headers for various known extension functions defined
    in different extension dlls. To use these functions, the appropriate
    extension dll must be loaded in the debugger. IDebugSymbols->GetExtension
    (declared in dbgeng.h) method could be used to retrieve these functions.

    Please see the Debugger documentation for specific information about how
    to write your own debugger extension DLL.

Environment:

    Win32 only.

Revision History:

--*/

#pragma once

#ifndef _EXTFNS_H
#define _EXTFNS_H

#define _EXTSAPI_VER_ 10

#ifndef _KDEXTSFN_H
#define _KDEXTSFN_H

/*
 *  Extension functions defined in kdexts.dll
 */

//
// device.c
//
typedef struct _DEBUG_DEVICE_OBJECT_INFO {
    ULONG      SizeOfStruct; // must be == sizeof(DEBUG_DEVICE_OBJECT_INFO)
    ULONG64    DevObjAddress;
    ULONG      ReferenceCount;
    BOOL       QBusy;
    ULONG64    DriverObject;
    ULONG64    CurrentIrp;
    ULONG64    DevExtension;
    ULONG64    DevObjExtension;
} DEBUG_DEVICE_OBJECT_INFO, *PDEBUG_DEVICE_OBJECT_INFO;


// GetDevObjInfo
typedef HRESULT
(WINAPI *PGET_DEVICE_OBJECT_INFO)(
    IN PDEBUG_CLIENT Client,
    IN ULONG64 DeviceObject,
    OUT PDEBUG_DEVICE_OBJECT_INFO pDevObjInfo);


//
// driver.c
//
typedef struct _DEBUG_DRIVER_OBJECT_INFO {
    ULONG     SizeOfStruct; // must be == sizeof(DEBUG_DRIVER_OBJECT_INFO)
    ULONG     DriverSize;
    ULONG64   DriverObjAddress;
    ULONG64   DriverStart;
    ULONG64   DriverExtension;
    ULONG64   DeviceObject;
    struct {
        USHORT Length;
        USHORT MaximumLength;
        ULONG64 Buffer;
    } DriverName;
} DEBUG_DRIVER_OBJECT_INFO, *PDEBUG_DRIVER_OBJECT_INFO;

// GetDrvObjInfo
typedef HRESULT
(WINAPI *PGET_DRIVER_OBJECT_INFO)(
    IN PDEBUG_CLIENT Client,
    IN ULONG64 DriverObject,
    OUT PDEBUG_DRIVER_OBJECT_INFO pDrvObjInfo);


// GetProcessCommit

typedef struct _PROCESS_COMMIT_USAGE {
    UCHAR ImageFileName[16];
    ULONG64 ClientId;
    ULONG64 ProcessAddress;
    ULONG64 CommitCharge;
    ULONG64 SharedCommitCharge;
    ULONG64 ReleasedCommitDebt;
    ULONG64 Reserved;
} PROCESS_COMMIT_USAGE, *PPROCESS_COMMIT_USAGE;

typedef HRESULT
(WINAPI *PGET_PROCESS_COMMIT)(
    PDEBUG_CLIENT Client,
    PULONG64 TotalCommitCharge,
    PULONG   NumberOfProcesses,
    PPROCESS_COMMIT_USAGE *CommitData
    );

typedef HRESULT
(WINAPI *PGET_FULL_IMAGE_NAME)(
    PDEBUG_CLIENT Client,
    ULONG64 Process,
    LPSTR *FullImageName
    );

//
// dump.cpp
//
typedef struct _DEBUG_CPU_SPEED_INFO {
    ULONG SizeOfStruct; // must be == sizeof(DEBUG_CPU_SPEED_INFO)
    ULONG CurrentSpeed;
    ULONG RatedSpeed;
    WCHAR NameString[256];
} DEBUG_CPU_SPEED_INFO, *PDEBUG_CPU_SPEED_INFO;

typedef HRESULT
(WINAPI *PGET_CPU_PSPEED_INFO)(
    IN  PDEBUG_CLIENT         Client,
    OUT PDEBUG_CPU_SPEED_INFO pCpuSpeedInfo);

typedef struct _DEBUG_CPU_MICROCODE_VERSION {
    ULONG         SizeOfStruct; // must be == sizeof(DEBUG_CPU_MICROCODE_VERSION)
    LARGE_INTEGER CachedSignature;
    LARGE_INTEGER InitialSignature;
    ULONG         ProcessorModel;
    ULONG         ProcessorFamily;
    ULONG         ProcessorStepping;    // ProcessorRevision on IA64
    ULONG         ProcessorArchRev;     // IA64?
} DEBUG_CPU_MICROCODE_VERSION, *PDEBUG_CPU_MICROCODE_VERSION;

typedef HRESULT
(WINAPI *PGET_CPU_MICROCODE_VERSION)(
    IN  PDEBUG_CLIENT                Client,
    OUT PDEBUG_CPU_MICROCODE_VERSION pCpuMicrocodeVersion);

typedef struct _DEBUG_SMBIOS_INFO {
    ULONG SizeOfStruct;
    UCHAR SmbiosMajorVersion;
    UCHAR SmbiosMinorVersion;
    UCHAR DMIVersion;
    ULONG TableSize;
    UCHAR BiosMajorRelease;
    UCHAR BiosMinorRelease;
    UCHAR FirmwareMajorRelease;
    UCHAR FirmwareMinorRelease;
    CHAR  BaseBoardManufacturer[64];
    CHAR  BaseBoardProduct[64];
    CHAR  BaseBoardVersion[64];
    CHAR  BiosReleaseDate[64];
    CHAR  BiosVendor[64];
    CHAR  BiosVersion[64];
    CHAR  SystemFamily[64];
    CHAR  SystemManufacturer[64];
    CHAR  SystemProductName[64];
    CHAR  SystemSKU[64];
    CHAR  SystemVersion[64];
} DEBUG_SMBIOS_INFO, *PDEBUG_SMBIOS_INFO;

//
// GetSmbiosInfo extension function from kdexts
//
typedef HRESULT
(WINAPI *PGET_SMBIOS_INFO)(
    IN  PDEBUG_CLIENT       Client,
    OUT PDEBUG_SMBIOS_INFO  pSmbiosInfo
    );

//
// irp.c
//
typedef struct _DEBUG_IRP_STACK_INFO {
    UCHAR     Major;
    UCHAR     Minor;
    ULONG64   DeviceObject;
    ULONG64   FileObject;
    ULONG64   CompletionRoutine;
    ULONG64   StackAddress;
} DEBUG_IRP_STACK_INFO, *PDEBUG_IRP_STACK_INFO;

typedef struct _DEBUG_IRP_INFO {
    ULONG     SizeOfStruct;  // Must be == sizeof(DEBUG_IRP_INFO)
    ULONG64   IrpAddress;
    ULONG     IoStatus;
    ULONG     StackCount;
    ULONG     CurrentLocation;
    ULONG64   MdlAddress;
    ULONG64   Thread;
    ULONG64   CancelRoutine;
    DEBUG_IRP_STACK_INFO CurrentStack;
    DEBUG_IRP_STACK_INFO Stack[10]; // Top 10 frames of irp stack
} DEBUG_IRP_INFO, *PDEBUG_IRP_INFO;

// GetIrpInfo
typedef HRESULT
(WINAPI * PGET_IRP_INFO)(
    IN PDEBUG_CLIENT Client,
    IN ULONG64 Irp,
    OUT PDEBUG_IRP_INFO IrpInfo
    );

//
// pnpexts.cpp
//
typedef struct _DDEBUG_PNP_TRIAGE_INFO {
    ULONG   SizeOfStruct; // must be == sizeof(DEBUG_PNP_TRIAGE_INFO)
    ULONG64 Lock_Address;
    LONG    Lock_ActiveCount;
    ULONG   Lock_ContentionCount;
    ULONG   Lock_NumberOfExclusiveWaiters;
    ULONG   Lock_NumberOfSharedWaiters;
    USHORT  Lock_Flag;
    ULONG64 TriagedThread;
    LONG    ThreadCount;
    ULONG64 TriagedThread_WaitTime;
    //ULONG64 PpDeviceActionThread;
    //ULONG64 PpDeviceEventThread;
} DEBUG_PNP_TRIAGE_INFO, *PDEBUG_PNP_TRIAGE_INFO;

//
// pnpexts.cpp (GetPNPTriageInfo)
//
typedef HRESULT
(WINAPI *PGET_PNP_TRIAGE_INFO)(
    IN PDEBUG_CLIENT Client,
    OUT PDEBUG_PNP_TRIAGE_INFO pPNPTriageInfo);


//
// pool.c
//
#if defined(_MSC_VER)
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning(disable:4201) /* nonstandard extension used : nameless struct/union */
#endif // defined(_MSC_VER)

typedef struct _DEBUG_POOL_DATA {
    ULONG   SizeofStruct;
    ULONG64 PoolBlock;
    ULONG64 Pool;
    ULONG   PreviousSize;
    ULONG   Size;
    ULONG   PoolTag;
    ULONG64 ProcessBilled;
    union {
        struct {
            ULONG   Free:1;
            ULONG   LargePool:1;
            ULONG   SpecialPool:1;
            ULONG   Pageable:1;
            ULONG   Protected:1;
            ULONG   Allocated:1;
            ULONG   Session:1;
            ULONG   Reserved:25;
        };
        ULONG AsUlong;
    };
    ULONG64 Reserved2[4];
    CHAR    PoolTagDescription[64];
} DEBUG_POOL_DATA, *PDEBUG_POOL_DATA;

#if defined(_MSC_VER)
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif
#endif // defined(_MSC_VER)

// GetPoolData
typedef HRESULT
(WINAPI *PGET_POOL_DATA)(
    PDEBUG_CLIENT Client,
    ULONG64 Pool,
    PDEBUG_POOL_DATA PoolData
    );

typedef enum _DEBUG_POOL_REGION {
    DbgPoolRegionUnknown,
    DbgPoolRegionSpecial,
    DbgPoolRegionPaged,
    DbgPoolRegionNonPaged,
    DbgPoolRegionNonPagedExpansion,
    DbgPoolRegionSessionPaged,
    DbgPoolRegionMax,
} DEBUG_POOL_REGION;

// GetPoolRegion
typedef HRESULT
(WINAPI  *PGET_POOL_REGION)(
     PDEBUG_CLIENT Client,
     ULONG64 Pool,
     DEBUG_POOL_REGION *PoolRegion
     );

//
// Proces.c: FindMatchingThread
//
typedef struct _KDEXT_THREAD_FIND_PARAMS {
    ULONG    SizeofStruct;
    ULONG64  StackPointer;
    ULONG    Cid;
    ULONG64  Thread;
} KDEXT_THREAD_FIND_PARAMS, *PKDEXT_THREAD_FIND_PARAMS;

typedef HRESULT
(WINAPI *PFIND_MATCHING_THREAD)(
    PDEBUG_CLIENT Client,
    PKDEXT_THREAD_FIND_PARAMS ThreadInfo
    );

//
// Proces.c: FindMatchingProcess
//
typedef struct _KDEXT_PROCESS_FIND_PARAMS {
    ULONG    SizeofStruct;
    ULONG    Pid;
    ULONG    Session;
    PCHAR    ImageName;
} KDEXT_PROCESS_FIND_PARAMS, *PKDEXT_PROCESS_FIND_PARAMS;

typedef HRESULT
(WINAPI *PFIND_MATCHING_PROCESS)(
    _In_ PDEBUG_CLIENT Client,
    _In_ PKDEXT_PROCESS_FIND_PARAMS ProcessInfo,
    _Out_ PULONG64 Process
    );

//
// EnumerateJobProcesses
//     Enumerate Processes within a job tree.
//

typedef BOOLEAN
(WINAPI *EXTS_JOB_PROCESS_CALLBACK)(
    _In_ ULONG64 Job,
    _In_ ULONG64 Process,
    _Inout_opt_ PVOID Context
    );

typedef HRESULT
(WINAPI *PENUMERATE_JOB_PROCESSES)(
    _In_ PDEBUG_CLIENT Client,
    _In_ ULONG64 Job,
    _In_ EXTS_JOB_PROCESS_CALLBACK Callback,
    _In_opt_ PVOID Context
    );

//
// EnumerateHashTable
//     Enumerate _RTL_DYNAMIC_HASH_TABLE entries.
//

typedef BOOLEAN
(WINAPI *EXTS_TABLE_ENTRY_CALLBACK)(
    _In_ ULONG64 Entry,
    _Inout_opt_ PVOID Context
    );

typedef HRESULT
(WINAPI *PENUMERATE_HASH_TABLE)(
    _In_ PDEBUG_CLIENT Client,
    _In_ ULONG64 HashTable,
    _In_ EXTS_TABLE_ENTRY_CALLBACK Callback,
    _Inout_opt_ PVOID Context
    );

//
// EnumerateHandles
//     Enumerte Ob handle table entries.
//

typedef struct _KDEXT_HANDLE_INFORMATION {
    ULONG64 HandleTableEntry;
    ULONG64 Handle;
    ULONG64 Object;
    ULONG64 ObjectBody;
    ULONG64 GrantedAccess;
    ULONG   HandleAttributes;
    BOOLEAN PagedOut;
} KDEXT_HANDLE_INFORMATION, *PKDEXT_HANDLE_INFORMATION;

typedef
BOOLEAN
(*KDEXT_DUMP_HANDLE_CALLBACK)(
    _In_ PKDEXT_HANDLE_INFORMATION HandleInfo,
    _In_ ULONG Flags,
    _Inout_opt_ PVOID Context
    );

#define DUMP_HANDLE_FLAG_PRINT_OBJECT 0x2
#define DUMP_HANDLE_FLAG_PRINT_FREE_ENTRY 0x4
#define DUMP_HANDLE_FLAG_KERNEL_TABLE 0x10
#define DUMP_HANDLE_FLAG_CID_TABLE 0x20

typedef HRESULT
(WINAPI *PENUMERATE_HANDLES)(
    _In_ PDEBUG_CLIENT Client,
    _In_ ULONG64 Process,
    _In_ ULONG64 HandleToDump,
    _In_ ULONG Flags,
    _In_ KDEXT_DUMP_HANDLE_CALLBACK Callback,
    _In_opt_ PVOID Context
    );

//
// FindFileLockOwnerInfo
//
typedef struct _KDEXT_FILELOCK_OWNER {
    ULONG Sizeofstruct;
    ULONG64 FileObject;            // IN  File object whose owner is to be searched
    ULONG64 OwnerThread;           // OUT Thread owning file object
    ULONG64 WaitIrp;               // OUT Irp associated with file object in hte thread
    ULONG64 DeviceObject;          // OUT Device object on which IRP is blocked
    CHAR    BlockingDirver[32];    // OUT Driver for the device object
} KDEXT_FILELOCK_OWNER, *PKDEXT_FILELOCK_OWNER;

typedef HRESULT
(WINAPI *PFIND_FILELOCK_OWNERINFO)(
    PDEBUG_CLIENT Client,
    PKDEXT_FILELOCK_OWNER pFileLockOwner
    );

//
// locks
//
typedef struct _KDEXTS_LOCK_INFO {
    ULONG SizeOfStruct;
    ULONG64 Address;
    ULONG64 OwningThread;
    BOOL  ExclusiveOwned;
    ULONG NumOwners;
    ULONG ContentionCount;
    ULONG NumExclusiveWaiters;     // threads waiting on exclusive access
    ULONG NumSharedWaiters;        // threads waiting on shared access
    PULONG64 pOwnerThreads;        // Array of thread addresses [NumOwners] owning lock
                                   // Set by Lock enumerator, caller needs to preserve value before return
    PULONG64 pWaiterThreads;       // Array of thread addresses [NumExclusiveWaiters]
                                   // Set by Lock enumerator, caller needs to preserve value before return
} KDEXTS_LOCK_INFO,*PKDEXTS_LOCK_INFO;

typedef HRESULT
(WINAPI *KDEXTS_LOCK_CALLBACKROUTINE)(PKDEXTS_LOCK_INFO pLock,
                                      PVOID Context);

#define KDEXTS_LOCK_CALLBACKROUTINE_DEFINED 2

//
// EnumerateSystemLocks
//     Enumerates owned locks and calls CallbackRoutine on all owned/active locks.
//
typedef HRESULT
(WINAPI *PENUMERATE_SYSTEM_LOCKS)(
    PDEBUG_CLIENT Client,
    ULONG Flags,
    KDEXTS_LOCK_CALLBACKROUTINE Callback,
    PVOID Context
    );

//
// pte information
//
typedef struct _KDEXTS_PTE_INFO {
    ULONG   SizeOfStruct;       // Must be sizeof(_KDEXTS_PTE_INFO)
    ULONG64 VirtualAddress;     // Virtual address to lookup PTE
    ULONG64 PpeAddress;
    ULONG64 PdeAddress;
    ULONG64 PteAddress;
    ULONG64 Pfn;
    ULONG64 Levels;
    ULONG   PteValid:1;
    ULONG   PteTransition:1;
    ULONG   Prototype:1;
    ULONG   Protection:1;
    ULONG   Reserved:28;

    // Pte Pfn info
    ULONG   ReadInProgress:1;
    ULONG   WriteInProgress:1;
    ULONG   Modified:1;
} KDEXTS_PTE_INFO, *PKDEXTS_PTE_INFO;

//
// GetPteInfo
//
typedef HRESULT
(WINAPI *PKDEXTS_GET_PTE_INFO)(
    _In_ PDEBUG_CLIENT Client,
    _In_ ULONG64 Virtual,
    _Out_ PKDEXTS_PTE_INFO PteInfo
    );

#endif // _KDEXTSFN_H


#ifndef _KEXTFN_H
#define _KEXTFN_H

/*
 *  Extension functions defined in kext.dll
 */

/*****************************************************************************
        PoolTag definitions
 *****************************************************************************/

typedef struct _DEBUG_POOLTAG_DESCRIPTION {
    ULONG  SizeOfStruct; // must be == sizeof(DEBUG_POOLTAG_DESCRIPTION)
    ULONG  PoolTag;
    CHAR   Description[MAX_PATH];
    CHAR   Binary[32];
    CHAR   Owner[32];
} DEBUG_POOLTAG_DESCRIPTION, *PDEBUG_POOLTAG_DESCRIPTION;

// GetPoolTagDescription
typedef HRESULT
(WINAPI *PGET_POOL_TAG_DESCRIPTION)(
    ULONG PoolTag,
    PDEBUG_POOLTAG_DESCRIPTION pDescription
    );

#endif // _KEXTFN_H

#ifndef _EXTAPIS_H
#define _EXTAPIS_H

/*
 *  Extension functions defined in ext.dll
 */

/*****************************************************************************
        Failure analysis definitions
 *****************************************************************************/
#ifndef AUTOBUG_PROCESSING_SUPPORT
#define AUTOBUG_PROCESSING_SUPPORT
#endif

typedef enum _DEBUG_FAILURE_TYPE {
    DEBUG_FLR_UNKNOWN,
    DEBUG_FLR_KERNEL,
    DEBUG_FLR_USER
} DEBUG_FAILURE_TYPE;

/*
    Each analysis entry can have associated data with it.  The
    analyzer knows how to handle each of these entries.
    For example it could do a !driver on a DEBUG_FLR_DRIVER_OBJECT
    or it could do a .cxr and k on a DEBUG_FLR_CONTEXT.
*/
typedef enum _DEBUG_FLR_PARAM_TYPE {
    DEBUG_FLR_INVALID = 0,
    DEBUG_FLR_RESERVED,
    DEBUG_FLR_DRIVER_OBJECT,
    DEBUG_FLR_DEVICE_OBJECT,
    DEBUG_FLR_INVALID_PFN,
    DEBUG_FLR_WORKER_ROUTINE,
    DEBUG_FLR_WORK_ITEM,
    DEBUG_FLR_INVALID_DPC_FOUND,
    DEBUG_FLR_PROCESS_OBJECT,
    // Address for which an instruction could not be executed,
    // such as invalid instructions or attempts to execute
    // non-instruction memory.
    DEBUG_FLR_FAILED_INSTRUCTION_ADDRESS,
    DEBUG_FLR_LAST_CONTROL_TRANSFER,
    DEBUG_FLR_ACPI_EXTENSION,
    DEBUG_FLR_ACPI_RESCONFLICT,
    DEBUG_FLR_ACPI_OBJECT,
    DEBUG_FLR_READ_ADDRESS,
    DEBUG_FLR_WRITE_ADDRESS,
    DEBUG_FLR_CRITICAL_SECTION,
    DEBUG_FLR_BAD_HANDLE,
    DEBUG_FLR_INVALID_HEAP_ADDRESS,
    DEBUG_FLR_CHKIMG_EXTENSION,
    DEBUG_FLR_USBPORT_OCADATA,
    DEBUG_FLR_WORK_QUEUE_ITEM,
    DEBUG_FLR_ERESOURCE_ADDRESS,  // ERESOURCE, use !locks to display this
    DEBUG_FLR_PNP_TRIAGE_DATA_DEPRECATED,
    DEBUG_FLR_HANDLE_VALUE,
    DEBUG_FLR_WHEA_ERROR_RECORD, // WHEA_ERROR_RECORD for bugcheck 0x124
    DEBUG_FLR_VERIFIER_FOUND_DEADLOCK, // Possible deadlock found, run !deadlock
    DEBUG_FLR_PG_MISMATCH,  // Patchguard nt!KiMismatchSummary
    DEBUG_FLR_DEVICE_NODE,
    DEBUG_FLR_POWERREQUEST_ADDRESS,
    DEBUG_FLR_EXECUTE_ADDRESS,

    DEBUG_FLR_IRP_ADDRESS = 0x100,
    DEBUG_FLR_IRP_MAJOR_FN,
    DEBUG_FLR_IRP_MINOR_FN,
    DEBUG_FLR_IRP_CANCEL_ROUTINE,
    DEBUG_FLR_IOSB_ADDRESS,
    DEBUG_FLR_INVALID_USEREVENT,
    DEBUG_FLR_VIDEO_TDR_CONTEXT,
    DEBUG_FLR_VERIFIER_DRIVER_ENTRY,
    DEBUG_FLR_PNP_IRP_ADDRESS_DEPRECATED,


    // Previous mode 0 == KernelMode , 1 == UserMode
    DEBUG_FLR_PREVIOUS_MODE,

    // Irql
    DEBUG_FLR_CURRENT_IRQL = 0x200,
    DEBUG_FLR_PREVIOUS_IRQL,
    DEBUG_FLR_REQUESTED_IRQL,

    // Exceptions
    DEBUG_FLR_ASSERT_DATA = 0x300,
    DEBUG_FLR_ASSERT_FILE,
    DEBUG_FLR_EXCEPTION_PARAMETER1,
    DEBUG_FLR_EXCEPTION_PARAMETER2,
    DEBUG_FLR_EXCEPTION_PARAMETER3,
    DEBUG_FLR_EXCEPTION_PARAMETER4,
    DEBUG_FLR_EXCEPTION_RECORD,
    DEBUG_FLR_IO_ERROR_CODE,
    DEBUG_FLR_EXCEPTION_STR,
    DEBUG_FLR_EXCEPTION_DOESNOT_MATCH_CODE, // address causing read/write av was'nt referred in code
    DEBUG_FLR_ASSERT_INSTRUCTION,

    // Pool
    DEBUG_FLR_POOL_ADDRESS = 0x400,
    DEBUG_FLR_SPECIAL_POOL_CORRUPTION_TYPE,
    DEBUG_FLR_CORRUPTING_POOL_ADDRESS,
    DEBUG_FLR_CORRUPTING_POOL_TAG,
    DEBUG_FLR_FREED_POOL_TAG,
    DEBUG_FLR_LEAKED_SESSION_POOL_TAG,
    DEBUG_FLR_INSTR_SESSION_POOL_TAG,
    DEBUG_FLR_CLIENT_DRIVER,

    // Filesystem
    DEBUG_FLR_FILE_ID = 0x500,
    DEBUG_FLR_FILE_LINE,

    // bugcheck data
    DEBUG_FLR_BUGCHECK_STR = 0x600,
    DEBUG_FLR_BUGCHECK_SPECIFIER,
    DEBUG_FLR_BUGCHECK_DESC,

    // Managed Code
    DEBUG_FLR_MANAGED_CODE = 0x700,
    DEBUG_FLR_MANAGED_OBJECT,               // Deprecated
    DEBUG_FLR_MANAGED_EXCEPTION_OBJECT,     // Deprecated
    DEBUG_FLR_MANAGED_EXCEPTION_MESSAGE_deprecated,   // Placeholder, DEBUG_FLR_MANAGED_EXCEPTION_MESSAGE moved
    DEBUG_FLR_MANAGED_STACK_STRING,         // Deprecated
    DEBUG_FLR_MANAGED_BITNESS_MISMATCH,
    DEBUG_FLR_MANAGED_OBJECT_NAME,          // Deprecated
    DEBUG_FLR_MANAGED_EXCEPTION_CONTEXT_MESSAGE, // Deprecated
    DEBUG_FLR_MANAGED_STACK_COMMAND,        // Deprecated
    DEBUG_FLR_MANAGED_KERNEL_DEBUGGER,
    DEBUG_FLR_MANAGED_HRESULT_STRING,       // Deprecated
    DEBUG_FLR_MANAGED_ENGINE_MODULE,
    DEBUG_FLR_MANAGED_ANALYSIS_PROVIDER,

    // Managed Exception
    DEBUG_FLR_MANAGED_EXCEPTION_ADDRESS = 0x800,
    DEBUG_FLR_MANAGED_EXCEPTION_HRESULT,
    DEBUG_FLR_MANAGED_EXCEPTION_TYPE,
    DEBUG_FLR_MANAGED_EXCEPTION_MESSAGE,
    DEBUG_FLR_MANAGED_EXCEPTION_CALLSTACK,
    DEBUG_FLR_MANAGED_EXCEPTION_INNER_ADDRESS = 0x810,
    DEBUG_FLR_MANAGED_EXCEPTION_INNER_HRESULT,
    DEBUG_FLR_MANAGED_EXCEPTION_INNER_TYPE,
    DEBUG_FLR_MANAGED_EXCEPTION_INNER_MESSAGE,
    DEBUG_FLR_MANAGED_EXCEPTION_INNER_CALLSTACK,
    DEBUG_FLR_MANAGED_EXCEPTION_NESTED_ADDRESS = 0x820,
    DEBUG_FLR_MANAGED_EXCEPTION_NESTED_HRESULT,
    DEBUG_FLR_MANAGED_EXCEPTION_NESTED_TYPE,
    DEBUG_FLR_MANAGED_EXCEPTION_NESTED_MESSAGE,
    DEBUG_FLR_MANAGED_EXCEPTION_NESTED_CALLSTACK,
    DEBUG_FLR_MANAGED_EXCEPTION_CMD = 0x8F0,

    // Managed Thread
    DEBUG_FLR_MANAGED_THREAD_ID = 0x900,
    DEBUG_FLR_MANAGED_THREAD_CMD_CALLSTACK = 0x9F0,
    DEBUG_FLR_MANAGED_THREAD_CMD_STACKOBJECTS,

    // Constant values / exception code / bugcheck subtypes etc
    DEBUG_FLR_DRIVER_VERIFIER_IO_VIOLATION_TYPE = 0x1000,
    DEBUG_FLR_EXCEPTION_CODE,
    DEBUG_FLR_EXCEPTION_CODE_STR,
    DEBUG_FLR_IOCONTROL_CODE,
    DEBUG_FLR_MM_INTERNAL_CODE,
    DEBUG_FLR_DRVPOWERSTATE_SUBCODE,
    DEBUG_FLR_STATUS_CODE,
    DEBUG_FLR_SYMBOL_STACK_INDEX,
    DEBUG_FLR_SYMBOL_ON_RAW_STACK,
    DEBUG_FLR_SECURITY_COOKIES,
    DEBUG_FLR_THREADPOOL_WAITER,
    DEBUG_FLR_TARGET_MODE,  // Value is DEBUG_FAILURE_TYPE
    DEBUG_FLR_BUGCHECK_CODE,
    DEBUG_FLR_BADPAGES_DETECTED,
    DEBUG_FLR_DPC_TIMEOUT_TYPE,
    DEBUG_FLR_DPC_RUNTIME,
    DEBUG_FLR_DPC_TIMELIMIT,
    DEBUG_FLR_DUMP_FILE_ATTRIBUTES,
    DEBUG_FLR_PAGE_HASH_ERRORS,
    DEBUG_FLR_BUGCHECK_P1,
    DEBUG_FLR_BUGCHECK_P2,
    DEBUG_FLR_BUGCHECK_P3,
    DEBUG_FLR_BUGCHECK_P4,
    DEBUG_FLR_CRITICAL_PROCESS, // Value is the name of the critical process.


    // Clustering (RHS)
    DEBUG_FLR_RESOURCE_CALL_TYPE = 0x1100,
    DEBUG_FLR_RESOURCE_CALL_TYPE_STR,

    // Notification IDs, values under it doesn't have significance
    DEBUG_FLR_CORRUPT_MODULE_LIST = 0x2000,
    DEBUG_FLR_BAD_STACK,
    DEBUG_FLR_ZEROED_STACK,
    DEBUG_FLR_WRONG_SYMBOLS,
    DEBUG_FLR_FOLLOWUP_DRIVER_ONLY,   //bugcheckEA indicates a general driver failure
    DEBUG_FLR_UNUSED001,             //bucket include timestamp, so each drive is tracked
    DEBUG_FLR_CPU_OVERCLOCKED,
    DEBUG_FLR_POSSIBLE_INVALID_CONTROL_TRANSFER,
    DEBUG_FLR_POISONED_TB,
    DEBUG_FLR_UNKNOWN_MODULE,
    DEBUG_FLR_ANALYZABLE_POOL_CORRUPTION,
    DEBUG_FLR_SINGLE_BIT_ERROR,
    DEBUG_FLR_TWO_BIT_ERROR,
    DEBUG_FLR_INVALID_KERNEL_CONTEXT,
    DEBUG_FLR_DISK_HARDWARE_ERROR,
    DEBUG_FLR_SHOW_ERRORLOG,
    DEBUG_FLR_MANUAL_BREAKIN,
    DEBUG_FLR_HANG,
    DEBUG_FLR_BAD_MEMORY_REFERENCE,
    DEBUG_FLR_BAD_OBJECT_REFERENCE,
    DEBUG_FLR_APPKILL,
    DEBUG_FLR_SINGLE_BIT_PFN_PAGE_ERROR,
    DEBUG_FLR_HARDWARE_ERROR,
    DEBUG_FLR_NO_IMAGE_IN_BUCKET,        // do not add image name in bucket
    DEBUG_FLR_NO_BUGCHECK_IN_BUCKET,     // do not add bugcheck string in bucket
    DEBUG_FLR_SKIP_STACK_ANALYSIS,       // do not look at stack
    DEBUG_FLR_INVALID_OPCODE,            // Bad op code instruction
    DEBUG_FLR_ADD_PROCESS_IN_BUCKET,
    DEBUG_FLR_RAISED_IRQL_USER_FAULT,
    DEBUG_FLR_USE_DEFAULT_CONTEXT,
    DEBUG_FLR_BOOST_FOLLOWUP_TO_SPECIFIC,
    DEBUG_FLR_SWITCH_PROCESS_CONTEXT,    // Set process context when getting tread stack
    DEBUG_FLR_VERIFIER_STOP,
    DEBUG_FLR_USERBREAK_PEB_PAGEDOUT,
    DEBUG_FLR_MOD_SPECIFIC_DATA_ONLY,
    DEBUG_FLR_OVERLAPPED_MODULE,         // Module with overlapping address space
    DEBUG_FLR_CPU_MICROCODE_ZERO_INTEL,
    DEBUG_FLR_INTEL_CPU_BIOS_UPGRADE_NEEDED,
    DEBUG_FLR_OVERLAPPED_UNLOADED_MODULE,
    DEBUG_FLR_INVALID_USER_CONTEXT,
    DEBUG_FLR_MILCORE_BREAK,
    DEBUG_FLR_NO_IMAGE_TIMESTAMP_IN_BUCKET, // do not add _DATE_#### to bucket (aplicable for
                                            // buckets containing just the image name)
    DEBUG_FLR_KERNEL_VERIFIER_ENABLED,      // Set for kernel targets which have verifier enabled
    DEBUG_FLR_SKIP_CORRUPT_MODULE_DETECTION, // do not look at module list for known corrupt modules
    DEBUG_FLR_GSFAILURE_FALSE_POSITIVE,
    DEBUG_FLR_IGNORE_LARGE_MODULE_CORRUPTION,
    DEBUG_FLR_IGNORE_BUCKET_ID_OFFSET,  // set to prevent the function offset from being set in the bucket ID
    DEBUG_FLR_NO_ARCH_IN_BUCKET,        // do not add the architecture name to the bucket
    DEBUG_FLR_IGNORE_MODULE_HARDWARE_ID, // do not set Hardware ID info from sysdata.xml. (used if the hardware ID was already set)
    DEBUG_FLR_ARM_WRITE_AV_CAVEAT,       // Add note that ARM may incorrectly label read AV as write AV in some cases.
    DEBUG_FLR_ON_DPC_STACK,           // Note if the stack pointer is currently on a DPC stack.
    DEBUG_FLR_LIVE_KERNEL_DUMP,       // This is a live kernel dump, not a bugcheck.
    DEBUG_FLR_COVERAGE_BUILD,         // This is an instrumented coverage build
    DEBUG_FLR_POSSIBLE_STACK_OVERFLOW, // An exception is possibly caused by stack overflow.
    DEBUG_FLR_WRONG_SYMBOLS_TIMESTAMP,  // Timestamp of Missing/Wrong Symbol
    DEBUG_FLR_WRONG_SYMBOLS_SIZE,       // Size of Missing/Wrong Symbol
    DEBUG_FLR_MISSING_IMPORTANT_SYMBOL, // Important module doesn't have private symbols
    DEBUG_FLR_MISSING_CLR_SYMBOL,       // CLR doesn't have private symbols

    DEBUG_FLR_TARGET_TIME,                     // Target event (crash) time in ISO 8601 format
    DEBUG_FLR_LOW_SYSTEM_COMMIT,
    DEBUG_FLR_LEGACY_PAGE_TABLE_ACCESS,     // AMD64 Kernel mode accessing legacy page table

    DEBUG_FLR_HIGH_PROCESS_COMMIT,
    DEBUG_FLR_HIGH_SERVICE_COMMIT,
    DEBUG_FLR_HIGH_NONPAGED_POOL_USAGE,
    DEBUG_FLR_HIGH_PAGED_POOL_USAGE,
    DEBUG_FLR_HIGH_SHARED_COMMIT_USAGE,
    DEBUG_FLR_APPS_NOT_TERMINATED,

    // Known analyzed failure cause or problem that bucketing could be
    // applied against.
    DEBUG_FLR_POOL_CORRUPTOR = 0x3000,
    DEBUG_FLR_MEMORY_CORRUPTOR,
    DEBUG_FLR_UNALIGNED_STACK_POINTER,
    DEBUG_FLR_OS_VERSION_deprecated,    // See DEBUG_FLR_OS_VERSION elsewhere
    DEBUG_FLR_BUGCHECKING_DRIVER,
    DEBUG_FLR_SOLUTION_ID,
    DEBUG_FLR_DEFAULT_SOLUTION_ID,
    DEBUG_FLR_SOLUTION_TYPE,
    DEBUG_FLR_RECURRING_STACK,
    DEBUG_FLR_FAULTING_INSTR_CODE,
    DEBUG_FLR_SYSTEM_LOCALE_deprecated,
    DEBUG_FLR_CUSTOMER_CRASH_COUNT,
    DEBUG_FLR_TRAP_FRAME_RECURSION,
    DEBUG_FLR_STACK_OVERFLOW,
    DEBUG_FLR_STACK_POINTER_ERROR,
    DEBUG_FLR_STACK_POINTER_ONEBIT_ERROR,
    DEBUG_FLR_STACK_POINTER_MISALIGNED,
    DEBUG_FLR_INSTR_POINTER_MISALIGNED,
    DEBUG_FLR_INSTR_POINTER_CLIFAULT,
    DEBUG_FLR_REGISTRYTXT_STRESS_ID,
    DEBUG_FLR_CORRUPT_SERVICE_TABLE,
    DEBUG_FLR_LOP_STACKHASH,
    DEBUG_FLR_GSFAILURE_FUNCTION,
    DEBUG_FLR_GSFAILURE_MODULE_COOKIE,
    DEBUG_FLR_GSFAILURE_FRAME_COOKIE,
    DEBUG_FLR_GSFAILURE_FRAME_COOKIE_COMPLEMENT,
    DEBUG_FLR_GSFAILURE_CORRUPTED_COOKIE,
    DEBUG_FLR_GSFAILURE_CORRUPTED_EBP,
    DEBUG_FLR_GSFAILURE_OVERRUN_LOCAL,
    DEBUG_FLR_GSFAILURE_OVERRUN_LOCAL_NAME,
    DEBUG_FLR_GSFAILURE_CORRUPTED_EBPESP,
    DEBUG_FLR_GSFAILURE_POSITIVELY_CORRUPTED_EBPESP,
    DEBUG_FLR_GSFAILURE_MEMORY_READ_ERROR,
    DEBUG_FLR_GSFAILURE_PROBABLY_NOT_USING_GS,
    DEBUG_FLR_GSFAILURE_POSITIVE_BUFFER_OVERFLOW,
    DEBUG_FLR_GSFAILURE_ANALYSIS_TEXT,
    DEBUG_FLR_GSFAILURE_OFF_BY_ONE_OVERRUN,
    DEBUG_FLR_GSFAILURE_RA_SMASHED,
    DEBUG_FLR_GSFAILURE_NOT_UP2DATE,
    DEBUG_FLR_GSFAILURE_UP2DATE_UNKNOWN,
    DEBUG_FLR_TRIAGER_OS_BUILD_NAME,  // OS Build Name via Triager: OSBuildName!<OS Build> - e.g. OSBuildName!7601 --> Win7SP1
    DEBUG_FLR_CPU_MICROCODE_VERSION,
    DEBUG_FLR_CPU_COUNT,
    DEBUG_FLR_CPU_SPEED,
    DEBUG_FLR_CPU_VENDOR,
    DEBUG_FLR_CPU_FAMILY,
    DEBUG_FLR_CPU_MODEL,
    DEBUG_FLR_CPU_STEPPING,
    DEBUG_FLR_INSTR_POINTER_ON_STACK,
    DEBUG_FLR_INSTR_POINTER_ON_HEAP,
    DEBUG_FLR_EVENT_CODE_DATA_MISMATCH,
    DEBUG_FLR_PROCESSOR_INFO,              // Data is DEBUG_ANALYSIS_PROCESSOR_INFO
    DEBUG_FLR_INSTR_POINTER_IN_UNLOADED_MODULE,
    DEBUG_FLR_MEMDIAG_LASTRUN_STATUS,
    DEBUG_FLR_MEMDIAG_LASTRUN_TIME,
    DEBUG_FLR_INSTR_POINTER_IN_FREE_BLOCK,
    DEBUG_FLR_INSTR_POINTER_IN_RESERVED_BLOCK,
    DEBUG_FLR_INSTR_POINTER_IN_VM_MAPPED_MODULE,
    DEBUG_FLR_INSTR_POINTER_IN_MODULE_NOT_IN_LIST,
    DEBUG_FLR_INSTR_POINTER_NOT_IN_STREAM,
    DEBUG_FLR_MEMORY_CORRUPTION_SIGNATURE, // Memory corruption address, size and pattern (bit, byte, word, stride or large)
    DEBUG_FLR_BUILDNAME_IN_BUCKET,
    DEBUG_FLR_CANCELLATION_NOT_SUPPORTED,
    DEBUG_FLR_DETOURED_IMAGE, // At least one of images on target is detoured
    DEBUG_FLR_EXCEPTION_CONTEXT_RECURSION,
    DEBUG_FLR_DISKIO_READ_FAILURE,
    DEBUG_FLR_DISKIO_WRITE_FAILURE,
    // this belongs with the GS related tags above, but here so that we dont disturb the order
    DEBUG_FLR_GSFAILURE_MISSING_ESTABLISHER_FRAME,
    DEBUG_FLR_GSFAILURE_COOKIES_MATCH_EXH,
    DEBUG_FLR_GSFAILURE_MANAGED,
    DEBUG_FLR_MANAGED_FRAME_CHAIN_CORRUPTION,  // not really a GS Failure, but reported and analyzed detected in the same way
    DEBUG_FLR_GSFAILURE_MANAGED_THREADID,
    DEBUG_FLR_GSFAILURE_MANAGED_FRAMEID,
    DEBUG_FLR_STACKUSAGE_IMAGE,   // The address of the image which used the most stack
    DEBUG_FLR_STACKUSAGE_IMAGE_SIZE, // The size of stack used by blamed image
    DEBUG_FLR_STACKUSAGE_FUNCTION, // The address of a function which used the most stack
    DEBUG_FLR_STACKUSAGE_FUNCTION_SIZE,  // The size of stack used by blamed function.
    DEBUG_FLR_STACKUSAGE_RECURSION_COUNT,  // The number of times the blamed function appeared in the stack due to recursion


    // Xbox specific string values
    DEBUG_FLR_XBOX_SYSTEM_UPTIME,
    DEBUG_FLR_XBOX_SYSTEM_CRASHTIME,
    DEBUG_FLR_XBOX_LIVE_ENVIRONMENT,

    // These should be in the analyzed failure cause, but here to not disturb order
    DEBUG_FLR_LARGE_TICK_INCREMENT,            // Value is the number of ticks incremented by KeUpdateRunTime
    DEBUG_FLR_INSTR_POINTER_IN_PAGED_CODE,     // Code is marked pagable, but attempted to execute at IRQL >= DPC_LEVEL
    DEBUG_FLR_SERVICETABLE_MODIFIED,           // Kernel service table modification/hooking has been detected
    DEBUG_FLR_ALUREON,                         // KDCOM is incorrect size, suspect Alureon

    // Internal data, retated to the OCA database
    DEBUG_FLR_INTERNAL_RAID_BUG = 0x4000,
    DEBUG_FLR_INTERNAL_BUCKET_URL,
    DEBUG_FLR_INTERNAL_SOLUTION_TEXT,
    DEBUG_FLR_INTERNAL_BUCKET_HITCOUNT,
    DEBUG_FLR_INTERNAL_RAID_BUG_DATABASE_STRING,
    DEBUG_FLR_INTERNAL_BUCKET_CONTINUABLE,
    DEBUG_FLR_INTERNAL_BUCKET_STATUS_TEXT,

    // Data corelating a user target to watson DB
    DEBUG_FLR_WATSON_MODULE = 0x4100,
    DEBUG_FLR_WATSON_MODULE_VERSION,
    DEBUG_FLR_WATSON_MODULE_OFFSET,
    DEBUG_FLR_WATSON_PROCESS_VERSION,
    DEBUG_FLR_WATSON_IBUCKET,
    DEBUG_FLR_WATSON_MODULE_TIMESTAMP,
    DEBUG_FLR_WATSON_PROCESS_TIMESTAMP,
    DEBUG_FLR_WATSON_GENERIC_EVENT_NAME,        /* or Generic EventType or EventTypeName */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_00,      /* for Generic Event P0 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_01,      /* for Generic Event P1 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_02,      /* for Generic Event P2 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_03,      /* for Generic Event P3 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_04,      /* for Generic Event P4 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_05,      /* for Generic Event P5 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_06,      /* for Generic Event P6 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_07,      /* for Generic Event P7 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_08,      /* for Generic Event P8 */
    DEBUG_FLR_WATSON_GENERIC_BUCKETING_09,      /* for Generic Event P9 */

    // Data extracted from cabbed files with dump
    DEBUG_FLR_SYSXML_LOCALEID = 0x4200,
    DEBUG_FLR_SYSXML_CHECKSUM,
    DEBUG_FLR_WQL_EVENT_COUNT,
    DEBUG_FLR_WQL_EVENTLOG_INFO,

    // System information such as bios data, manufactures (from !sysinfo)
    DEBUG_FLR_SYSINFO_SYSTEM_MANUFACTURER = 0x4300,
    DEBUG_FLR_SYSINFO_SYSTEM_PRODUCT,
    DEBUG_FLR_SYSINFO_SYSTEM_SKU,
    DEBUG_FLR_SYSINFO_SYSTEM_VERSION,
    DEBUG_FLR_SYSINFO_BASEBOARD_MANUFACTURER,
    DEBUG_FLR_SYSINFO_BASEBOARD_PRODUCT,
    DEBUG_FLR_SYSINFO_BASEBOARD_VERSION,
    DEBUG_FLR_SYSINFO_BIOS_VENDOR,
    DEBUG_FLR_SYSINFO_BIOS_VERSION,
    DEBUG_FLR_SYSINFO_BIOS_DATE,
    DEBUG_FLR_VIRTUAL_MACHINE,

    // Service Control Manager
    DEBUG_FLR_SERVICE = 0x5000,
    DEBUG_FLR_SERVICE_NAME,             // HKLM\SYSTEM\CurrentControlSet\Services\<Name>
    DEBUG_FLR_SERVICE_GROUP,            // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\Group
    DEBUG_FLR_SERVICE_DISPLAYNAME,      // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\DisplayName
    DEBUG_FLR_SERVICE_DESCRIPTION,      // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\Description
    DEBUG_FLR_SERVICE_DEPENDONSERVICE,  // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\DependOnService
    DEBUG_FLR_SERVICE_DEPENDONGROUP,    // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\DependOnGroup

    DEBUG_FLR_SVCHOST = 0x5100,
    DEBUG_FLR_SVCHOST_GROUP,            // ImagePath: "%SystemRoot%\System32\svchost.exe -k LocalService" --> "LocalService"
    DEBUG_FLR_SVCHOST_IMAGEPATH,        // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\ImagePath
    DEBUG_FLR_SVCHOST_SERVICEDLL,       // HKLM\SYSTEM\CurrentControlSet\Services\<Name>\Parameters\ServiceDll

    DEBUG_FLR_SCM = 0x5200,
    DEBUG_FLR_SCM_BLACKBOX = 0x52F0,
    DEBUG_FLR_SCM_BLACKBOX_ENTRY,
    DEBUG_FLR_SCM_BLACKBOX_ENTRY_CONTROLCODE,
    DEBUG_FLR_SCM_BLACKBOX_ENTRY_STARTTIME,
    DEBUG_FLR_SCM_BLACKBOX_ENTRY_SERVICENAME,

    // ACPI
    DEBUG_FLR_ACPI = 0x6000,
    DEBUG_FLR_ACPI_BLACKBOX = 0x6100,
    DEBUG_FLR_PO_BLACKBOX ,
    // bootstat.dat
    DEBUG_FLR_BOOTSTAT = 0x7000,
    DEBUG_FLR_BOOTSTAT_BLACKBOX = 0x7100,

    // Storage Device
    DEBUG_FLR_STORAGE = 0x7400,
    DEBUG_FLR_STORAGE_ORGID,
    DEBUG_FLR_STORAGE_MODEL,
    DEBUG_FLR_STORAGE_MFGID,
    DEBUG_FLR_STORAGE_ISSUEDESCSTRING,
    DEBUG_FLR_STORAGE_PUBLIC_TOTSIZE,
    DEBUG_FLR_STORAGE_PUBLIC_OFFSET,
    DEBUG_FLR_STORAGE_PUBLIC_DATASIZE,
    DEBUG_FLR_STORAGE_PRIVATE_TOTSIZE,
    DEBUG_FLR_STORAGE_PRIVATE_OFFSET,
    DEBUG_FLR_STORAGE_PRIVATE_DATASIZE,
    DEBUG_FLR_STORAGE_TOTALSIZE,
    DEBUG_FLR_STORAGE_REASON,
    DEBUG_FLR_STORAGE_BLACKBOX = 0x74F0,

    // Filesystems
    DEBUG_FLR_FILESYSTEMS_NTFS = 0x7600,
    DEBUG_FLR_FILESYSTEMS_NTFS_BLACKBOX = 0x76F0,
    DEBUG_FLR_FILESYSTEMS_REFS = 0x7800,
    DEBUG_FLR_FILESYSTEMS_REFS_BLACKBOX = 0x78F0,

    // Plug'n'Play (PnP)
    DEBUG_FLR_PNP = 0x8000,
    DEBUG_FLR_PNP_TRIAGE_DATA,          // DEBUG_PNP_TRIAGE_INFO struct
    DEBUG_FLR_PNP_IRP_ADDRESS,
    DEBUG_FLR_PNP_BLACKBOX = 0x8100,

    // Strings.
    DEBUG_FLR_BUCKET_ID = 0x10000,
    DEBUG_FLR_IMAGE_NAME,
    DEBUG_FLR_SYMBOL_NAME,
    DEBUG_FLR_FOLLOWUP_NAME,
    DEBUG_FLR_STACK_COMMAND,
    DEBUG_FLR_STACK_TEXT,
    DEBUG_FLR_MODULE_NAME,         // Kernel Blamed module/driver name
    DEBUG_FLR_FIXED_IN_OSVERSION,
    DEBUG_FLR_DEFAULT_BUCKET_ID,
    DEBUG_FLR_MODULE_BUCKET_ID,         // Part of Bucket id specific to the culprit module
    DEBUG_FLR_ADDITIONAL_DEBUGTEXT,
    DEBUG_FLR_PROCESS_NAME,
    DEBUG_FLR_USER_NAME,
    DEBUG_FLR_MARKER_FILE,       // Marker file name from sysdata.xml in cabs
    DEBUG_FLR_INTERNAL_RESPONSE, // Response text for bucket
    DEBUG_FLR_CONTEXT_RESTORE_COMMAND, // command to restore original context as before analysis
    DEBUG_FLR_DRIVER_HARDWAREID,    // hardware id of faulting driver from sysdata.xml
    DEBUG_FLR_DRIVER_HARDWARE_VENDOR_ID,
    DEBUG_FLR_DRIVER_HARDWARE_DEVICE_ID,
    DEBUG_FLR_DRIVER_HARDWARE_SUBSYS_ID,
    DEBUG_FLR_DRIVER_HARDWARE_REV_ID,
    DEBUG_FLR_DRIVER_HARDWARE_ID_BUS_TYPE,
    DEBUG_FLR_MARKER_MODULE_FILE, // Secondary marker file name from the module list
    DEBUG_FLR_BUGCHECKING_DRIVER_IDTAG,  // Tag set during processing to identify bugchecking driver frm triage.ini
    DEBUG_FLR_MARKER_BUCKET,      // bucket id derived from machine marker
    DEBUG_FLR_FAILURE_BUCKET_ID,
    DEBUG_FLR_DRIVER_XML_DESCRIPTION,
    DEBUG_FLR_DRIVER_XML_PRODUCTNAME,
    DEBUG_FLR_DRIVER_XML_MANUFACTURER,
    DEBUG_FLR_DRIVER_XML_VERSION,
    DEBUG_FLR_BUILD_VERSION_STRING,         // N.N.N.N (<branch>.YYMMDD-HHNN)
    DEBUG_FLR_BUILD_OS_FULL_VERSION_STRING, // Asimov-compatible version string
    DEBUG_FLR_ORIGINAL_CAB_NAME,
    DEBUG_FLR_FAULTING_SOURCE_CODE,
    DEBUG_FLR_FAULTING_SERVICE_NAME,
    DEBUG_FLR_FILE_IN_CAB, // name of file (other than dump itself) found in cab
    DEBUG_FLR_UNRESPONSIVE_UI_SYMBOL_NAME,
    DEBUG_FLR_UNRESPONSIVE_UI_FOLLOWUP_NAME,
    DEBUG_FLR_UNRESPONSIVE_UI_STACK,
    DEBUG_FLR_PROCESS_PRODUCTNAME,         // Product name string from process image version info
    DEBUG_FLR_MODULE_PRODUCTNAME,          // Product name string from module image version info
    DEBUG_FLR_COLLECT_DATA_FOR_BUCKET,              // DataWanted sproc params
    DEBUG_FLR_COMPUTER_NAME,
    DEBUG_FLR_IMAGE_CLASS,
    DEBUG_FLR_SYMBOL_ROUTINE_NAME,
    DEBUG_FLR_HARDWARE_BUCKET_TAG,
    DEBUG_FLR_KERNEL_LOG_PROCESS_NAME,
    DEBUG_FLR_KERNEL_LOG_STATUS,
    DEBUG_FLR_REGISTRYTXT_SOURCE,
    DEBUG_FLR_FAULTING_SOURCE_LINE,
    DEBUG_FLR_FAULTING_SOURCE_FILE,             // This TAG is a duplicate of the tag above.  The former is left due to an external (Autobug) dependency
    DEBUG_FLR_FAULTING_SOURCE_LINE_NUMBER,  // This isnt a string, but it is coorelated with the tag above, so keep them together

    DEBUG_FLR_SKIP_MODULE_SPECIFIC_BUCKET_INFO, // Do not add the module name to the bucket string.
    DEBUG_FLR_BUCKET_ID_FUNC_OFFSET, // when pruning the offset from the bucket ID, it is saved in this string instead
    DEBUG_FLR_XHCI_FIRMWARE_VERSION,
    DEBUG_FLR_FAILURE_ANALYSIS_SOURCE,  // Kernel/User/TruScan/Radar/Xbox/Phone etc..
    DEBUG_FLR_FAILURE_ID_HASH,          // MD5 Hash of DEBUG_FLR_FAILURE_ID_HASH_STRING
    DEBUG_FLR_FAILURE_ID_HASH_STRING,   // LowerCase(DEBUG_FLR_FAILURE_ANALYSIS_SOURCE+FAILURE_BUCKET_ID)
    DEBUG_FLR_FAILURE_ID_REPORT_LINK,   // Failure ID Report URL - OCA.INI:debugger-params!failurereporturl+FAILURE_ID_HASH
    DEBUG_FLR_HOLDINFO,                // Live Debug hold info metadata
    DEBUG_FLR_HOLDINFO_ACTIVE_HOLD_COUNT,
    DEBUG_FLR_HOLDINFO_TENET_SOCRE,
    DEBUG_FLR_HOLDINFO_HISTORIC_HOLD_COUNT,
    DEBUG_FLR_HOLDINFO_ALWAYS_IGNORE,
    DEBUG_FLR_HOLDINFO_ALWAYS_HOLD,
    DEBUG_FLR_HOLDINFO_MAX_HOLD_LIMIT,
    DEBUG_FLR_HOLDINFO_MANUAL_HOLD,
    DEBUG_FLR_HOLDINFO_NOTIFICATION_ALIASES,
    DEBUG_FLR_HOLDINFO_LAST_SEEN_HOLD_DATE,
    DEBUG_FLR_HOLDINFO_RECOMMEND_HOLD, // Indicates if a live debug should be held or released

    // FailureBucketID, the individual building blocks
    DEBUG_FLR_FAILURE_PROBLEM_CLASS,
    DEBUG_FLR_FAILURE_EXCEPTION_CODE,
    DEBUG_FLR_FAILURE_IMAGE_NAME,
    DEBUG_FLR_FAILURE_FUNCTION_NAME,
    DEBUG_FLR_FAILURE_SYMBOL_NAME,

    // RETracer support
    DEBUG_FLR_FOLLOWUP_BEFORE_RETRACER,

    // Messages for the human debugger
    DEBUG_FLR_END_MESSAGE,
    DEBUG_FLR_FEATURE_PATH,

    // User mode watson crumbs in kernel mode dumps
    DEBUG_FLR_USER_MODE_BUCKET,
    DEBUG_FLR_USER_MODE_BUCKET_INDEX,
    DEBUG_FLR_USER_MODE_BUCKET_EVENTTYPE,
    DEBUG_FLR_USER_MODE_BUCKET_REPORTGUID,
    DEBUG_FLR_USER_MODE_BUCKET_REPORTCREATIONTIME,
    DEBUG_FLR_USER_MODE_BUCKET_P0,
    DEBUG_FLR_USER_MODE_BUCKET_P1,
    DEBUG_FLR_USER_MODE_BUCKET_P2,
    DEBUG_FLR_USER_MODE_BUCKET_P3,
    DEBUG_FLR_USER_MODE_BUCKET_P4,
    DEBUG_FLR_USER_MODE_BUCKET_P5,
    DEBUG_FLR_USER_MODE_BUCKET_P6,
    DEBUG_FLR_USER_MODE_BUCKET_P7,
    DEBUG_FLR_USER_MODE_BUCKET_STRING,
    DEBUG_FLR_CRITICAL_PROCESS_REPORTGUID,

    DEBUG_FLR_FAILURE_MODULE_NAME,
    DEBUG_FLR_PLATFORM_BUCKET_STRING, // Holds the platform string to optionally add to the Bucket Id.

    // Human readable vendor/subvendor/device names for given venid/devid codes
    DEBUG_FLR_DRIVER_HARDWARE_VENDOR_NAME,
    DEBUG_FLR_DRIVER_HARDWARE_SUBVENDOR_NAME,
    DEBUG_FLR_DRIVER_HARDWARE_DEVICE_NAME,

    // Source Server information
    DEBUG_FLR_FAULTING_SOURCE_COMMIT_ID,
    DEBUG_FLR_FAULTING_SOURCE_CONTROL_TYPE,
    DEBUG_FLR_FAULTING_SOURCE_PROJECT,
    DEBUG_FLR_FAULTING_SOURCE_REPO_ID,
    DEBUG_FLR_FAULTING_SOURCE_REPO_URL,
    DEBUG_FLR_FAULTING_SOURCE_SRV_COMMAND,

    // User-mode specific stuff
    DEBUG_FLR_USERMODE_DATA = 0x100000,
    DEBUG_FLR_THREAD_ATTRIBUTES, // Thread attributes
    DEBUG_FLR_PROBLEM_CLASSES,
    DEBUG_FLR_PRIMARY_PROBLEM_CLASS,
    DEBUG_FLR_PRIMARY_PROBLEM_CLASS_DATA,
    DEBUG_FLR_UNRESPONSIVE_UI_PROBLEM_CLASS,
    DEBUG_FLR_UNRESPONSIVE_UI_PROBLEM_CLASS_DATA,
    DEBUG_FLR_DERIVED_WAIT_CHAIN,
    DEBUG_FLR_HANG_DATA_NEEDED,
    DEBUG_FLR_PROBLEM_CODE_PATH_HASH,
    DEBUG_FLR_SUSPECT_CODE_PATH_HASH,
    DEBUG_FLR_LOADERLOCK_IN_WAIT_CHAIN,
    DEBUG_FLR_XPROC_HANG,
    DEBUG_FLR_DEADLOCK_INPROC,
    DEBUG_FLR_DEADLOCK_XPROC,
    DEBUG_FLR_WCT_XML_AVAILABLE,
    DEBUG_FLR_XPROC_DUMP_AVAILABLE,
    DEBUG_FLR_DESKTOP_HEAP_MISSING,
    DEBUG_FLR_HANG_REPORT_THREAD_IS_IDLE,
    DEBUG_FLR_FAULT_THREAD_SHA1_HASH_MF,    // these fault thread hash variations are used in kernel mode too
    DEBUG_FLR_FAULT_THREAD_SHA1_HASH_MFO,
    DEBUG_FLR_FAULT_THREAD_SHA1_HASH_M,
    DEBUG_FLR_WAIT_CHAIN_COMMAND,
    DEBUG_FLR_NTGLOBALFLAG,
    DEBUG_FLR_APPVERIFERFLAGS,
    DEBUG_FLR_MODLIST_SHA1_HASH,
    DEBUG_FLR_DUMP_TYPE,
    DEBUG_FLR_XCS_PATH,
    DEBUG_FLR_LOADERLOCK_OWNER_API,
    DEBUG_FLR_LOADERLOCK_BLOCKED_API,
    DEBUG_FLR_MODLIST_TSCHKSUM_SHA1_HASH,     // hash of module list (with checksum, timestamp & size)
    DEBUG_FLR_MODLIST_UNLOADED_SHA1_HASH,     // hash of unloaded module list
    DEBUG_FLR_MACHINE_INFO_SHA1_HASH,         // hash of unloaded module list
    DEBUG_FLR_URLS_DISCOVERED,
    DEBUG_FLR_URLS,
    DEBUG_FLR_URL_ENTRY,
    DEBUG_FLR_WATSON_IBUCKET_S1_RESP,
    DEBUG_FLR_WATSON_IBUCKETTABLE_S1_RESP,
    DEBUG_FLR_SEARCH_HANG,
    DEBUG_FLR_WER_DATA_COLLECTION_INFO,
    DEBUG_FLR_WER_MACHINE_ID,
    DEBUG_FLR_ULS_SCRIPT_EXCEPTION,
    DEBUG_FLR_LCIE_ISO_AVAILABLE,
    DEBUG_FLR_SHOW_LCIE_ISO_DATA,
    DEBUG_FLR_URL_LCIE_ENTRY,
    DEBUG_FLR_URL_URLMON_ENTRY,
    DEBUG_FLR_URL_XMLHTTPREQ_SYNC_ENTRY,
    DEBUG_FLR_FAULTING_LOCAL_VARIABLE_NAME,
    DEBUG_FLR_MODULE_LIST,
    DEBUG_FLR_DUMP_FLAGS,
    DEBUG_FLR_APPLICATION_VERIFIER_LOADED,
    DEBUG_FLR_DUMP_CLASS,
    DEBUG_FLR_DUMP_QUALIFIER,
    DEBUG_FLR_KM_MODULE_LIST,

    // Scale Analysis (OS Version, Blame information)
    DEBUG_FLR_EXCEPTION_CODE_STR_deprecated = 0x101000, // String representation of the exception code (ie. c0000005)
                                                        // Defined elsewhere as DEBUG_FLR_EXCEPTION_CODE_STR
    DEBUG_FLR_BUCKET_ID_PREFIX_STR,  // This is the prefix part of BUCKET_ID. Everything before the start of the module name
    DEBUG_FLR_BUCKET_ID_MODULE_STR,  // This is module, without the offset or _ni postfix
    DEBUG_FLR_BUCKET_ID_MODVER_STR,  // This is version of the aforementioned module, 0.0.0.0 if none.
    DEBUG_FLR_BUCKET_ID_FUNCTION_STR,// This is same as Sym from Watson. If missing 'unknown'.
    DEBUG_FLR_BUCKET_ID_OFFSET,      // The offset portion SYMBOL_NAME
    DEBUG_FLR_OS_BUILD,              // OS Build Version number (n.n.N.n) in decimal
    DEBUG_FLR_OS_SERVICEPACK,        // OS Service Pack number (0, 1, 2, etc,)
    DEBUG_FLR_OS_BRANCH,             // OS Branch - from the Build Lab string (e.g. rs5_release, rs_foo_bar_dev)
    DEBUG_FLR_OS_BUILD_TIMESTAMP_LAB,// OS Build Timestamp - Build Lab string format - YYMMDD-HHNN
    DEBUG_FLR_OS_VERSION,            // OS Build Version number (N.N.N.N) in decimal
    DEBUG_FLR_BUCKET_ID_TIMEDATESTAMP,
    DEBUG_FLR_BUCKET_ID_CHECKSUM,
    DEBUG_FLR_OS_FLAVOR,
    DEBUG_FLR_BUCKET_ID_FLAVOR_STR,   // Is the failing module chk or fre
    DEBUG_FLR_OS_SKU,
    DEBUG_FLR_OS_PRODUCT_TYPE,
    DEBUG_FLR_OS_SUITE_MASK,
    DEBUG_FLR_USER_LCID,              // User's Language Number (1033)
    DEBUG_FLR_OS_REVISION,            // OS Build Version Revision number (n.n.n.N) in decimal
    DEBUG_FLR_OS_NAME,                // OS Name
    DEBUG_FLR_OS_NAME_EDITION,        // Complete OS Name along with edition
    DEBUG_FLR_OS_PLATFORM_ARCH,       // OS Architecture - x86 / x64 / ia64
    DEBUG_FLR_OS_SERVICEPACK_deprecated,
    DEBUG_FLR_OS_LOCALE,              // OS Locale/Language Code Identifier String (en-US/zh-TW)
    DEBUG_FLR_OS_BUILD_TIMESTAMP_ISO, // OS Build Timestamp - ISO format - YYYY-MM-DDTHH:NN
    DEBUG_FLR_USER_LCID_STR,          // User's Language String (en-us)
    DEBUG_FLR_ANALYSIS_SESSION_TIME,  // time stamp when analysis is running
    DEBUG_FLR_ANALYSIS_SESSION_HOST,  // machine on which analysis is running
    DEBUG_FLR_ANALYSIS_SESSION_ELAPSED_TIME, // processing time for analysis set in milliseconds
    DEBUG_FLR_ANALYSIS_VERSION,       // !analyze version
    DEBUG_FLR_BUCKET_ID_IMAGE_STR,    // This is image, with the .dll/exe/tmp, etc. extension
    DEBUG_FLR_BUCKET_ID_PRIVATE,
    DEBUG_FLR_ANALYSIS_REPROCESS,     // Reprocessing is advised due to transitory issues
    DEBUG_FLR_OS_MAJOR,               // OS Build Version Major number (N.n.n.n) in decimal
    DEBUG_FLR_OS_MINOR,               // OS Build Version Minor number (n.N.n.n) in decimal
    DEBUG_FLR_OS_BUILD_STRING,        // OS Build String - the entire string including version, timestamp and branch (multiple formats)
    DEBUG_FLR_OS_LOCALE_LCID,         // OS Language Code Identifier (0x409/0n1033)
    DEBUG_FLR_OS_PLATFORM_ID,         // OS Platform ID - VER_PLATFORM_WIN32_WINDOWS(1)/VER_PLATFORM_WIN32_NT(2)/VER_PLATFORM_UNIX(10)/VER_PLATFORM_MACOSX(11)
    DEBUG_FLR_OS_BUILD_LAYERS_XML,    // OneCore Layering XML

    DEBUG_FLR_OSBUILD_deprecated = 0x101100, // Use DEBUG_FLR_OS_BUILD
    DEBUG_FLR_BUILDOSVER_STR_deprecated,     // Use DEBUG_FLR_OS_VERSION

    // Debug Analysis
    DEBUG_FLR_DEBUG_ANALYSIS = 0x111000,

    // Key/Value
    DEBUG_FLR_KEYVALUE_ANALYSIS = 0x112000,
    DEBUG_FLR_KEY_VALUES_STRING = 0x112100,
    DEBUG_FLR_KEY_VALUES_VARIANT = 0x112200,

    // Timeline
    DEBUG_FLR_TIMELINE_ANALYSIS = 0x113000,
    DEBUG_FLR_TIMELINE_TIMES,

    // Stream Analysis
    DEBUG_FLR_STREAM_ANALYSIS = 0x114000,

    // Memory Analysis
    DEBUG_FLR_MEMORY_ANALYSIS = 0x115000,

    // Stack Hash Analysis
    DEBUG_FLR_STACKHASH_ANALYSIS = 0x116000,

    // Processes Analysis
    DEBUG_FLR_PROCESSES_ANALYSIS = 0x117000,

    // Services Analysis
    DEBUG_FLR_SERVICE_ANALYSIS = 0x118000,

    // Addional XML
    DEBUG_FLR_ADDITIONAL_XML = 0x119000,

    // Analysis structured data
    DEBUG_FLR_STACK = 0x200000,
    DEBUG_FLR_FOLLOWUP_CONTEXT,
    DEBUG_FLR_XML_MODULE_LIST,
    DEBUG_FLR_STACK_FRAME,
    DEBUG_FLR_STACK_FRAME_NUMBER,
    DEBUG_FLR_STACK_FRAME_INSTRUCTION,
    DEBUG_FLR_STACK_FRAME_SYMBOL,
    DEBUG_FLR_STACK_FRAME_SYMBOL_OFFSET,
    DEBUG_FLR_STACK_FRAME_MODULE,
    DEBUG_FLR_STACK_FRAME_IMAGE,
    DEBUG_FLR_STACK_FRAME_FUNCTION,
    DEBUG_FLR_STACK_FRAME_FLAGS,
    DEBUG_FLR_CONTEXT_COMMAND,
    DEBUG_FLR_CONTEXT_FLAGS,
    DEBUG_FLR_CONTEXT_ORDER,
    DEBUG_FLR_CONTEXT_SYSTEM,
    DEBUG_FLR_CONTEXT_ID,
    DEBUG_FLR_XML_MODULE_INFO,
    DEBUG_FLR_XML_MODULE_INFO_INDEX,
    DEBUG_FLR_XML_MODULE_INFO_NAME,
    DEBUG_FLR_XML_MODULE_INFO_IMAGE_NAME,
    DEBUG_FLR_XML_MODULE_INFO_IMAGE_PATH,
    DEBUG_FLR_XML_MODULE_INFO_CHECKSUM,
    DEBUG_FLR_XML_MODULE_INFO_TIMESTAMP,
    DEBUG_FLR_XML_MODULE_INFO_UNLOADED,
    DEBUG_FLR_XML_MODULE_INFO_ON_STACK,
    DEBUG_FLR_XML_MODULE_INFO_FIXED_FILE_VER,
    DEBUG_FLR_XML_MODULE_INFO_FIXED_PROD_VER,
    DEBUG_FLR_XML_MODULE_INFO_STRING_FILE_VER,
    DEBUG_FLR_XML_MODULE_INFO_STRING_PROD_VER,
    DEBUG_FLR_XML_MODULE_INFO_COMPANY_NAME,
    DEBUG_FLR_XML_MODULE_INFO_FILE_DESCRIPTION,
    DEBUG_FLR_XML_MODULE_INFO_INTERNAL_NAME,
    DEBUG_FLR_XML_MODULE_INFO_ORIG_FILE_NAME,
    DEBUG_FLR_XML_MODULE_INFO_BASE,
    DEBUG_FLR_XML_MODULE_INFO_SIZE,
    DEBUG_FLR_XML_MODULE_INFO_PRODUCT_NAME,
    DEBUG_FLR_PROCESS_INFO,
    DEBUG_FLR_EXCEPTION_MODULE_INFO,
    DEBUG_FLR_CONTEXT_FOLLOWUP_INDEX,
    DEBUG_FLR_XML_GLOBALATTRIBUTE_LIST,
    DEBUG_FLR_XML_ATTRIBUTE_LIST,
    DEBUG_FLR_XML_ATTRIBUTE,
    DEBUG_FLR_XML_ATTRIBUTE_NAME,
    DEBUG_FLR_XML_ATTRIBUTE_VALUE,
    DEBUG_FLR_XML_ATTRIBUTE_D1VALUE,
    DEBUG_FLR_XML_ATTRIBUTE_D2VALUE,
    DEBUG_FLR_XML_ATTRIBUTE_DOVALUE,
    DEBUG_FLR_XML_ATTRIBUTE_VALUE_TYPE,
    DEBUG_FLR_XML_ATTRIBUTE_FRAME_NUMBER,
    DEBUG_FLR_XML_ATTRIBUTE_THREAD_INDEX,
    DEBUG_FLR_XML_PROBLEMCLASS_LIST,
    DEBUG_FLR_XML_PROBLEMCLASS,
    DEBUG_FLR_XML_PROBLEMCLASS_NAME,
    DEBUG_FLR_XML_PROBLEMCLASS_VALUE,
    DEBUG_FLR_XML_PROBLEMCLASS_VALUE_TYPE,
    DEBUG_FLR_XML_PROBLEMCLASS_FRAME_NUMBER,
    DEBUG_FLR_XML_PROBLEMCLASS_THREAD_INDEX,
    DEBUG_FLR_XML_STACK_FRAME_TRIAGE_STATUS,
    DEBUG_FLR_CONTEXT_METADATA,
    DEBUG_FLR_STACK_FRAMES,
    DEBUG_FLR_XML_ENCODED_OFFSETS,
    DEBUG_FLR_FA_PERF_DATA,
    DEBUG_FLR_FA_PERF_ITEM,
    DEBUG_FLR_FA_PERF_ITEM_NAME,
    DEBUG_FLR_FA_PERF_ITERATIONS,
    DEBUG_FLR_FA_PERF_ELAPSED_MS,
    DEBUG_FLR_STACK_SHA1_HASH_MF,
    DEBUG_FLR_STACK_SHA1_HASH_MFO,
    DEBUG_FLR_STACK_SHA1_HASH_M,
    DEBUG_FLR_XML_MODULE_INFO_SYMBOL_TYPE, // loaded symbol type
    DEBUG_FLR_XML_MODULE_INFO_FILE_FLAGS, // whether debug or release build
    DEBUG_FLR_STACK_FRAME_MODULE_BASE,
    DEBUG_FLR_STACK_FRAME_SRC,
    DEBUG_FLR_XML_SYSTEMINFO,
    DEBUG_FLR_XML_SYSTEMINFO_SYSTEMMANUFACTURER,
    DEBUG_FLR_XML_SYSTEMINFO_SYSTEMMODEL,
    DEBUG_FLR_XML_SYSTEMINFO_SYSTEMMARKER,
    DEBUG_FLR_FA_ADHOC_ANALYSIS_ITEMS,
    DEBUG_FLR_XML_APPLICATION_NAME,
    DEBUG_FLR_XML_PACKAGE_MONIKER,
    DEBUG_FLR_XML_PACKAGE_RELATIVE_APPLICATION_ID,
    DEBUG_FLR_XML_MODERN_ASYNC_REQUEST_OUTSTANDING,
    DEBUG_FLR_XML_EVENTTYPE,
    DEBUG_FLR_XML_PACKAGE_NAME,
    DEBUG_FLR_XML_PACKAGE_VERSION,

    DEBUG_FLR_FAILURE_LIST,
    DEBUG_FLR_FAILURE_DISPLAY_NAME,
    DEBUG_FLR_FRAME_SOURCE_FILE_NAME,
    DEBUG_FLR_FRAME_SOURCE_FILE_PATH,
    DEBUG_FLR_FRAME_SOURCE_LINE_NUMBER,

    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_IMAGE_STATUS,  // Deprecated
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_IMAGE_ERROR,
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_IMAGE_DETAIL,
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_IMAGE_SEC,

    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_PDB_STATUS,    // Deprecated
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_PDB_ERROR,
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_PDB_DETAIL,
    DEBUG_FLR_XML_MODULE_INFO_SYMSRV_PDB_SEC,

    DEBUG_FLR_XML_MODULE_INFO_DRIVER_GROUP,

    // cabbed text data / structured data
    DEBUG_FLR_REGISTRY_DATA = 0x300000,
    DEBUG_FLR_WMI_QUERY_DATA = 0x301000,
    DEBUG_FLR_USER_GLOBAL_ATTRIBUTES = 0x302000,
    DEBUG_FLR_USER_THREAD_ATTRIBUTES = 0x303000,
    DEBUG_FLR_USER_PROBLEM_CLASSES = 0x304000,

    // Compressed store specific information
    DEBUG_FLR_SM_COMPRESSION_FORMAT = 0x50000000,
    DEBUG_FLR_SM_SOURCE_PFN1,
    DEBUG_FLR_SM_SOURCE_PFN2,
    DEBUG_FLR_SM_SOURCE_OFFSET,
    DEBUG_FLR_SM_SOURCE_SIZE,
    DEBUG_FLR_SM_TARGET_PFN,
    DEBUG_FLR_SM_BUFFER_HASH,
    DEBUG_FLR_SM_ONEBIT_SOLUTION_COUNT,

    // Windows Store specific information
    DEBUG_FLR_STORE_PRODUCT_ID = 0x60000000,
    DEBUG_FLR_STORE_PRODUCT_DISPLAY_NAME,
    DEBUG_FLR_STORE_PRODUCT_DESCRIPTION,
    DEBUG_FLR_STORE_PRODUCT_EXTENDED_NAME,
    DEBUG_FLR_STORE_PUBLISHER_ID,
    DEBUG_FLR_STORE_PUBLISHER_NAME,
    DEBUG_FLR_STORE_PUBLISHER_CERTIFICATE_NAME,
    DEBUG_FLR_STORE_DEVELOPER_NAME,
    DEBUG_FLR_STORE_PACKAGE_FAMILY_NAME,
    DEBUG_FLR_STORE_PACKAGE_IDENTITY_NAME,
    DEBUG_FLR_STORE_PRIMARY_PARENT_PRODUCT_ID,
    DEBUG_FLR_STORE_LEGACY_PARENT_PRODUCT_ID,
    DEBUG_FLR_STORE_LEGACY_WINDOWS_STORE_PRODUCT_ID,
    DEBUG_FLR_STORE_LEGACY_WINDOWS_PHONE_PRODUCT_ID,
    DEBUG_FLR_STORE_LEGACY_XBOX_ONE_PRODUCT_ID,
    DEBUG_FLR_STORE_LEGACY_XBOX_360_PRODUCT_ID,
    DEBUG_FLR_STORE_XBOX_TITLE_ID,
    DEBUG_FLR_STORE_PREFERRED_SKU_ID,
    DEBUG_FLR_STORE_IS_MICROSOFT_PRODUCT,
    DEBUG_FLR_STORE_URL_APP,
    DEBUG_FLR_STORE_URL_APPHEALTH,

    // Windows Phone specific information
    DEBUG_FLR_PHONE_VERSIONMAJOR=0x70000000,
    DEBUG_FLR_PHONE_VERSIONMINOR,
    DEBUG_FLR_PHONE_BUILDNUMBER,
    DEBUG_FLR_PHONE_BUILDTIMESTAMP,
    DEBUG_FLR_PHONE_BUILDBRANCH,
    DEBUG_FLR_PHONE_BUILDER,
    DEBUG_FLR_PHONE_LCID,
    DEBUG_FLR_PHONE_QFE,
    DEBUG_FLR_PHONE_OPERATOR,
    DEBUG_FLR_PHONE_MCCMNC,
    DEBUG_FLR_PHONE_FIRMWAREREVISION,
    DEBUG_FLR_PHONE_RAM,
    DEBUG_FLR_PHONE_ROMVERSION,
    DEBUG_FLR_PHONE_SOCVERSION,
    DEBUG_FLR_PHONE_HARDWAREREVISION,
    DEBUG_FLR_PHONE_RADIOHARDWAREREVISION,
    DEBUG_FLR_PHONE_RADIOSOFTWAREREVISION,
    DEBUG_FLR_PHONE_BOOTLOADERVERSION,
    DEBUG_FLR_PHONE_REPORTGUID,
    DEBUG_FLR_PHONE_SOURCE,
    DEBUG_FLR_PHONE_SOURCEEXTERNAL,
    DEBUG_FLR_PHONE_USERALIAS,
    DEBUG_FLR_PHONE_REPORTTIMESTAMP,
    DEBUG_FLR_PHONE_APPID,
    DEBUG_FLR_PHONE_SKUID,
    DEBUG_FLR_PHONE_APPVERSION,
    DEBUG_FLR_PHONE_UIF_COMMENT,
    DEBUG_FLR_PHONE_UIF_APPNAME,
    DEBUG_FLR_PHONE_UIF_APPID,
    DEBUG_FLR_PHONE_UIF_CATEGORY,
    DEBUG_FLR_PHONE_UIF_ORIGIN,

    DEBUG_FLR_SIMULTANEOUS_TELSVC_INSTANCES,
    DEBUG_FLR_SIMULTANEOUS_TELWP_INSTANCES,
    DEBUG_FLR_MINUTES_SINCE_LAST_EVENT,
    DEBUG_FLR_MINUTES_SINCE_LAST_EVENT_OF_THIS_TYPE,

    DEBUG_FLR_REPORT_INFO_GUID,
    DEBUG_FLR_REPORT_INFO_SOURCE,
    DEBUG_FLR_REPORT_INFO_CREATION_TIME,

    // Culprit module
    DEBUG_FLR_FAULTING_IP = 0x80000000,     // Instruction where failure occurred
    DEBUG_FLR_FAULTING_MODULE,
    DEBUG_FLR_IMAGE_TIMESTAMP,
    DEBUG_FLR_FOLLOWUP_IP,
    DEBUG_FLR_FRAME_ONE_INVALID,
    DEBUG_FLR_SYMBOL_FROM_RAW_STACK_ADDRESS,
    DEBUG_FLR_IMAGE_VERSION,
    DEBUG_FLR_FOLLOWUP_BUCKET_ID,

    // custom analysis plugin tags
    DEBUG_FLR_CUSTOM_ANALYSIS_TAG_MIN = 0xA0000000,
    DEBUG_FLR_CUSTOM_ANALYSIS_TAG_MAX = 0xB0000000,

    // To get faulting stack
    DEBUG_FLR_FAULTING_THREAD = 0xc0000000,
    DEBUG_FLR_CONTEXT,
    DEBUG_FLR_TRAP_FRAME,
    DEBUG_FLR_TSS,
    DEBUG_FLR_BLOCKING_THREAD, // Thread which is blocking others to execute by holding locks/critsec
    DEBUG_FLR_UNRESPONSIVE_UI_THREAD,
    DEBUG_FLR_BLOCKED_THREAD0, // Threads blocked / waiting for some event / crit section
    DEBUG_FLR_BLOCKED_THREAD1,
    DEBUG_FLR_BLOCKED_THREAD2,
    DEBUG_FLR_BLOCKING_PROCESSID, // process id of processes which is blocking execution
    DEBUG_FLR_PROCESSOR_ID,  // CPU where the fault is
    DEBUG_FLR_XDV_VIOLATED_CONDITION,
    DEBUG_FLR_XDV_STATE_VARIABLE,
    DEBUG_FLR_XDV_HELP_LINK,
    DEBUG_FLR_XDV_RULE_INFO,
    DEBUG_FLR_DPC_STACK_BASE,

    DEBUG_FLR_TESTRESULTSERVER = 0xF0000000,
    DEBUG_FLR_TESTRESULTGUID,

    DEBUG_FLR_CUSTOMREPORTTAG,

    DEBUG_FLR_DISKSEC_ORGID_DEPRECATED,
    DEBUG_FLR_DISKSEC_MODEL_DEPRECATED,
    DEBUG_FLR_DISKSEC_MFGID_DEPRECATED,
    DEBUG_FLR_DISKSEC_ISSUEDESCSTRING_DEPRECATED,
    DEBUG_FLR_DISKSEC_PUBLIC_TOTSIZE_DEPRECATED,
    DEBUG_FLR_DISKSEC_PUBLIC_OFFSET_DEPRECATED,
    DEBUG_FLR_DISKSEC_PUBLIC_DATASIZE_DEPRECATED,
    DEBUG_FLR_DISKSEC_PRIVATE_TOTSIZE_DEPRECATED,
    DEBUG_FLR_DISKSEC_PRIVATE_OFFSET_DEPRECATED,
    DEBUG_FLR_DISKSEC_PRIVATE_DATASIZE_DEPRECATED,
    DEBUG_FLR_DISKSEC_TOTALSIZE_DEPRECATED,
    DEBUG_FLR_DISKSEC_REASON_DEPRECATED,

    DEBUG_FLR_WERCOLLECTION_PROCESSTERMINATED,
    DEBUG_FLR_WERCOLLECTION_PROCESSHEAPDUMP_REQUEST_FAILURE,
    DEBUG_FLR_WERCOLLECTION_MINIDUMP_WRITE_FAILURE,
    DEBUG_FLR_WERCOLLECTION_DEFAULTCOLLECTION_FAILURE,

    DEBUG_FLR_PROCESS_BAM_CURRENT_THROTTLED,
    DEBUG_FLR_PROCESS_BAM_PREVIOUS_THROTTLED,

    DEBUG_FLR_DUMPSTREAM_COMMENTA,
    DEBUG_FLR_DUMPSTREAM_COMMENTW,

    DEBUG_FLR_CHPE_PROCESS,
    DEBUG_FLR_WINLOGON_BLACKBOX,

    DEBUG_FLR_CUSTOM_COMMAND,
    DEBUG_FLR_CUSTOM_COMMAND_OUTPUT,

    DEBUG_FLR_MASK_ALL = 0xFFFFFFFF

} DEBUG_FLR_PARAM_TYPE;

// Bucketing - Scale Analysis
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_CHECKSUM        DEBUG_FLR_BUCKET_ID_CHECKSUM
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_FLAVOR_STR      DEBUG_FLR_BUCKET_ID_FLAVOR_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_FUNCTION_STR    DEBUG_FLR_BUCKET_ID_FUNCTION_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_IMAGE_STR       DEBUG_FLR_BUCKET_ID_IMAGE_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_MODULE_STR      DEBUG_FLR_BUCKET_ID_MODULE_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_MODVER_STR      DEBUG_FLR_BUCKET_ID_MODVER_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_OFFSET          DEBUG_FLR_BUCKET_ID_OFFSET
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_PREFIX_STR      DEBUG_FLR_BUCKET_ID_PREFIX_STR
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_PRIVATE         DEBUG_FLR_BUCKET_ID_PRIVATE
#define DEBUG_FLR_AUTOBUG_BUCKET_ID_TIMEDATESTAMP   DEBUG_FLR_BUCKET_ID_TIMEDATESTAMP

// Deprecated - Use the Replacement Name
#define DEBUG_FLR_OSBUILD                           DEBUG_FLR_OS_BUILD
#define DEBUG_FLR_OS_PLATFORM_TYPE                  DEBUG_FLR_OS_PLATFORM_ARCH
#define DEBUG_FLR_OSSERVICEPACK                     DEBUG_FLR_OS_SERVICEPACK
#define DEBUG_FLR_OSSERVICEPACK_NUMBER              DEBUG_FLR_OS_SERVICEPACK_deprecated
#define DEBUG_FLR_BUILD_FLAVOR_STR                  DEBUG_FLR_OS_FLAVOR
#define DEBUG_FLR_BUILDLAB_STR                      DEBUG_FLR_OS_BRANCH
#define DEBUG_FLR_BUILDDATESTAMP_STR                DEBUG_FLR_OS_BUILD_TIMESTAMP_LAB
#define DEBUG_FLR_BUILDDATESTAMP                    DEBUG_FLR_OS_BUILD_TIMESTAMP_ISO
#define DEBUG_FLR_PRODUCT_TYPE                      DEBUG_FLR_OS_PRODUCT_TYPE
#define DEBUG_FLR_SUITE_MASK                        DEBUG_FLR_OS_SUITE_MASK

typedef struct _DBG_THREAD_ATTRIBUTES
{
    ULONG ThreadIndex;
    ULONG64 ProcessID;
    ULONG64 ThreadID;
    ULONG64 AttributeBits;

/*
        bHas_StringData         0x0001
        bBlockedOnPID           0x0002
        bBlockedOnTID           0x0004
        bHas_CritSecAddress     0x0008
        bHas_timeout            0x0010
        m_szSymName[0]          0x0020
*/
    ULONG BoolBits;
    ULONG64 BlockedOnPID;
    ULONG64 BlockedOnTID;
    ULONG64 CritSecAddress;
    ULONG Timeout_msec;
    char StringData[100];
    char SymName[100];
} DBG_THREAD_ATTRIBUTES, *PDBG_THREAD_ATTRIBUTES;

//----------------------------------------------------------------------------
//
// A failure analysis is a dynamic buffer of tagged blobs.  Values
// are accessed through the Get/Set methods.
//
// Entries are always fully aligned.
//
// Set methods throw E_OUTOFMEMORY exceptions when the data
// buffer cannot be extended.
//
//----------------------------------------------------------------------------

typedef DEBUG_FLR_PARAM_TYPE FA_TAG;

//
// This is set in IDebugFAEntryTags Tag Type to determine
// type of value contained in entry
//
typedef enum _FA_ENTRY_TYPE
{
    // Undefined entry, this may be used for
    // FA_TAGs whose values do not have any significance
    DEBUG_FA_ENTRY_NO_TYPE,
    // FA_ENTRY is of ULONG type
    DEBUG_FA_ENTRY_ULONG,
    // FA_ENTRY is of ULONG64 type
    DEBUG_FA_ENTRY_ULONG64,
    // FA_ENTRY is offset in instruction stream
    DEBUG_FA_ENTRY_INSTRUCTION_OFFSET,
    // FA_ENTRY is a (ULONG64 sign-extended) pointer value
    DEBUG_FA_ENTRY_POINTER,
    // FA_ENTRY is null terminated char array
    // DataSize is size of string including null terminator
    DEBUG_FA_ENTRY_ANSI_STRING,
    // FA_ENTRY is an array of strings, each of the string
    // is null terminated char array.
    // DataSize is sum size of all string including null terminator
    DEBUG_FA_ENTRY_ANSI_STRINGs,
    // FA_ENTRY is a link to an extension command. !analyze -v
    // would run the command when showing the entry value
    // The Entry contains extension command string.
    DEBUG_FA_ENTRY_EXTENSION_CMD,
    // FA_ENTRY is a link is structured analysis data
    // The Entry contains pointer to PDEBUG_FAILURE_ANALYSIS2 object.
    DEBUG_FA_ENTRY_STRUCTURED_DATA,
    // FA_ENTRY is null terminated unicode char array
    // DataSize is size of unicode string including null terminator
    DEBUG_FA_ENTRY_UNICODE_STRING,
    // Bit flag modifier for any of the basic type
    // (ULONG/POINTER/INSTRUCTION_OFFSET). FA_ENTRY is an
    // array of any basic type other than string. DataSize
    // member of the Entry can be used to determine array length.
    DEBUG_FA_ENTRY_ARRAY = 0x8000,
} FA_ENTRY_TYPE;

#undef INTERFACE
#define INTERFACE IDebugFAEntryTags
DECLARE_INTERFACE(IDebugFAEntryTags)
{
    // Looksup Type associated for the failure tag
    STDMETHOD_(FA_ENTRY_TYPE, GetType)(
        THIS_
        _In_ FA_TAG Tag
        ) PURE;

    // Sets Type associated for the failure tag
    STDMETHOD(SetType)(
        THIS_
        _In_ FA_TAG Tag,
        _In_ FA_ENTRY_TYPE EntryType
        ) PURE;

    // Looksup description and name for the failure tag
    STDMETHOD(GetProperties)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_writes_bytes_opt_(*NameSize) PSTR Name,
        _Inout_opt_ PULONG NameSize,
        _Out_writes_bytes_opt_(*DescSize) PSTR Description,
        _Inout_opt_ PULONG DescSize,
        _Out_opt_ PULONG Flags
        ) PURE;

    // Sets description and name for the failure tag
    // If the given tag already had these defined, this will overwrite
    // previous definition(s)
    STDMETHOD(SetProperties)(
        THIS_
        _In_ FA_TAG Tag,
        _In_opt_ PCSTR Name,
        _In_opt_ PCSTR Description,
        _In_opt_ ULONG Flags
        ) PURE;

    // This looks up default analysis tag or plugin's registered tag
    // by its name
    STDMETHOD(GetTagByName)(
        THIS_
        _In_opt_ PCSTR PluginId,
        _In_ PCSTR TagName,
        _Out_ FA_TAG* Tag
        ) PURE;

    // This allows extensions to check if a given failure
    // tag value can be set. This would return true for all
    // tags that were allocated via AllocateTagRange or
    // the predefined tag values in this header file
    STDMETHOD_(BOOL, IsValidTagToSet)(
        THIS_
        _In_ FA_TAG Tag
        ) PURE;
};

typedef struct _FA_ENTRY
{
    FA_TAG Tag;
    USHORT FullSize;
    USHORT DataSize;
} FA_ENTRY, *PFA_ENTRY;

#define FA_ENTRY_DATA(Type, Entry) ((Type)((Entry) + 1))


// IID_IDebugFailureAnalysis
// {ed0de363-451f-4943-820c-62dccdfa7e6d}
DEFINE_GUID(IID_IDebugFailureAnalysis, 0xed0de363, 0x451f, 0x4943, 0x82, 0x0c, 0x62, 0xdc, 0xcd, 0xfa, 0x7e, 0x6d);
typedef interface DECLSPEC_UUID("ed0de363-451f-4943-820c-62dccdfa7e6d") IDebugFailureAnalysis* PDEBUG_FAILURE_ANALYSIS;

#undef INTERFACE
#define INTERFACE IDebugFailureAnalysis
DECLARE_INTERFACE_(IDebugFailureAnalysis, IUnknown)
{
    // IUnknown

    STDMETHOD(QueryInterface)(
        THIS_
        IN REFIID InterfaceId,
        OUT PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    // IDebugFailureAnalysis

    STDMETHOD_(ULONG, GetFailureClass)(
        THIS
        ) PURE;
    STDMETHOD_(DEBUG_FAILURE_TYPE, GetFailureType)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, GetFailureCode)(
        THIS
        ) PURE;
    STDMETHOD_(PFA_ENTRY, Get)(
        THIS_
        FA_TAG Tag
        ) PURE;
    STDMETHOD_(PFA_ENTRY, GetNext)(
        THIS_
        PFA_ENTRY Entry,
        FA_TAG Tag,
        FA_TAG TagMask
        ) PURE;
    STDMETHOD_(PFA_ENTRY, GetString)(
        THIS_
        FA_TAG Tag,
        _Out_writes_bytes_(MaxSize) PSTR Str,
        ULONG MaxSize
        ) PURE;
    STDMETHOD_(PFA_ENTRY, GetBuffer)(
        THIS_
        FA_TAG Tag,
        _Out_writes_bytes_(Size) PVOID Buf,
        ULONG Size
        ) PURE;
    STDMETHOD_(PFA_ENTRY, GetUlong)(
        THIS_
        FA_TAG Tag,
        _Out_ PULONG Value
        ) PURE;
    STDMETHOD_(PFA_ENTRY, GetUlong64)(
        THIS_
        FA_TAG Tag,
        _Out_ PULONG64 Value
        ) PURE;
    STDMETHOD_(PFA_ENTRY, NextEntry)(
        THIS_
        _In_opt_ PFA_ENTRY Entry
        ) PURE;
};

// IID_IDebugFailureAnalysis2
// {ea15c288-8226-4b70-acf6-0be6b189e3ad}
DEFINE_GUID(IID_IDebugFailureAnalysis2, 0xea15c288, 0x8226, 0x4b70, 0xac, 0xf6, 0x0b, 0xe6, 0xb1, 0x89, 0xe3, 0xad);
typedef interface DECLSPEC_UUID("ea15c288-8226-4b70-acf6-0be6b189e3ad") IDebugFailureAnalysis2* PDEBUG_FAILURE_ANALYSIS2;

#undef INTERFACE
#define INTERFACE IDebugFailureAnalysis2
DECLARE_INTERFACE_(IDebugFailureAnalysis2, IUnknown)
{
    //
    // IUnknown
    //

    STDMETHOD(QueryInterface)(
        THIS_
        IN REFIID InterfaceId,
        OUT PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    //
    // IDebugFailureAnalysis
    //

    // Target class for the given failure
    STDMETHOD_(ULONG, GetFailureClass)(
        THIS
        ) PURE;
    // Type of failure being analyzed
    STDMETHOD_(DEBUG_FAILURE_TYPE, GetFailureType)(
        THIS
        ) PURE;
    // Failure code: Bugcheck code for kernel mode,
    // exception code for user mode
    STDMETHOD_(ULONG, GetFailureCode)(
        THIS
        ) PURE;
    // Lookup FA_ENTRY by tag
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, Get)(
        THIS_
        _In_ FA_TAG Tag
        ) PURE;
    // Looks up next FA_ENTRY after the given 'Entry' by
    // matching with Tag & and TagMask
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetNext)(
        THIS_
        _In_ PFA_ENTRY Entry,
        _In_ FA_TAG Tag,
        _In_ FA_TAG TagMask
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its string value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetString)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_writes_(MaxSize) PSTR Str,
        _In_ ULONG MaxSize
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its data value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetBuffer)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_writes_bytes_(Size) PVOID Buf,
        _In_ ULONG Size
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its ULONG value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetUlong)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_ PULONG Value
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its ULONG64 value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetUlong64)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_ PULONG64 Value
        ) PURE;
    // Looks up next FA_ENTRY after the given 'Entry'
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, NextEntry)(
        THIS_
        _In_opt_ PFA_ENTRY Entry
        ) PURE;

    //
    // IDebugFailureAnalysis2
    //

    // Sets the given String for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetString)(
        THIS_
        FA_TAG Tag,
        PCSTR Str
        ) PURE;
    // Sets the given extension command and its
    // argument for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetExtensionCommand)(
        THIS_
        FA_TAG Tag,
        PCSTR Extension
        ) PURE;
    // Sets the given ULONG value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetUlong)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG Value
        ) PURE;
    // Sets the given ULONG64 value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetUlong64)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG64 Value
        ) PURE;
    // Sets the given Buffer value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetBuffer)(
        THIS_
        FA_TAG Tag,
        _In_ FA_ENTRY_TYPE EntryType,
        _In_reads_bytes_(Size) PVOID Buf,
        _In_ ULONG Size
        ) PURE;
    // Sets the given String for corresponding tag
    // It adds a new entry the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, AddString)(
        THIS_
        FA_TAG Tag,
        _In_ PCSTR Str
        ) PURE;
    // Sets the given extension command and its
    // argument for corresponding tag in a new entry
    STDMETHOD_(PFA_ENTRY, AddExtensionCommand)(
        THIS_
        FA_TAG Tag,
        _In_ PCSTR Extension
        ) PURE;
    // Sets the given ULONG value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddUlong)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG Value
        ) PURE;
    // Sets the given ULONG64 value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddUlong64)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG64 Value
        ) PURE;
    // Sets the given Buffer value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddBuffer)(
        THIS_
        FA_TAG Tag,
        _In_ FA_ENTRY_TYPE EntryType,
        _In_reads_bytes_(Size) PVOID const Buf,
        _In_ ULONG Size
        ) PURE;
    // Get the interface to query and set meta-data about
    // failure analysis tags
    STDMETHOD(GetDebugFATagControl)(
        THIS_
        _Out_ IDebugFAEntryTags** FATagControl
        ) PURE;
    // Generates and returns XML fragment from analysis data
    STDMETHOD(GetAnalysisXml)(
        THIS_
        #ifdef __IXMLDOMElement_FWD_DEFINED__
        _Out_ IXMLDOMElement** ppXMLDOMElement
        #else
        _Out_ IUnknown** ppXMLDOMElement
        #endif
        ) PURE;
    // Adds another analysis object as structured data in a new entry
    STDMETHOD(AddStructuredAnalysisData)(
        THIS_
        FA_TAG Tag,
        _In_ IDebugFailureAnalysis2 *Analysis
        ) PURE;
};


// IID_IDebugFailureAnalysis3
// {3627DC67-FD45-42ff-9BA4-4A67EE64619F}
DEFINE_GUID(IID_IDebugFailureAnalysis3, 0x3627dc67, 0xfd45, 0x42ff, 0x9b, 0xa4, 0x4a, 0x67, 0xee, 0x64, 0x61, 0x9f);
typedef interface DECLSPEC_UUID("3627DC67-FD45-42ff-9BA4-4A67EE64619F") IDebugFailureAnalysis3* PDEBUG_FAILURE_ANALYSIS3;

#undef INTERFACE
#define INTERFACE IDebugFailureAnalysis3
DECLARE_INTERFACE_(IDebugFailureAnalysis3, IUnknown)
{
    //
    // IUnknown
    //

    STDMETHOD(QueryInterface)(
        THIS_
        IN REFIID InterfaceId,
        OUT PVOID* Interface
        ) PURE;
    STDMETHOD_(ULONG, AddRef)(
        THIS
        ) PURE;
    STDMETHOD_(ULONG, Release)(
        THIS
        ) PURE;

    //
    // IDebugFailureAnalysis
    //

    // Target class for the given failure
    STDMETHOD_(ULONG, GetFailureClass)(
        THIS
        ) PURE;
    // Type of failure being analyzed
    STDMETHOD_(DEBUG_FAILURE_TYPE, GetFailureType)(
        THIS
        ) PURE;
    // Failure code: Bugcheck code for kernel mode,
    // exception code for user mode
    STDMETHOD_(ULONG, GetFailureCode)(
        THIS
        ) PURE;
    // Lookup FA_ENTRY by tag
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, Get)(
        THIS_
        _In_ FA_TAG Tag
        ) PURE;
    // Looks up next FA_ENTRY after the given 'Entry' by
    // matching with Tag & and TagMask
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetNext)(
        THIS_
        _In_ PFA_ENTRY Entry,
        _In_ FA_TAG Tag,
        _In_ FA_TAG TagMask
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its string value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetString)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_writes_(MaxSize) PSTR Str,
        _In_ ULONG MaxSize
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its data value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetBuffer)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_writes_bytes_(Size) PVOID Buf,
        _In_ ULONG Size
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its ULONG value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetUlong)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_ PULONG Value
        ) PURE;
    // Looksup FA_ENTRY by tag and copies its ULONG64 value
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, GetUlong64)(
        THIS_
        _In_ FA_TAG Tag,
        _Out_ PULONG64 Value
        ) PURE;
    // Looks up next FA_ENTRY after the given 'Entry'
    // Returns NULL if tag is not found
    STDMETHOD_(PFA_ENTRY, NextEntry)(
        THIS_
        _In_opt_ PFA_ENTRY Entry
        ) PURE;

    //
    // IDebugFailureAnalysis2
    //

    // Sets the given String for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetString)(
        THIS_
        FA_TAG Tag,
        PCSTR Str
        ) PURE;
    // Sets the given extension command and its
    // argument for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetExtensionCommand)(
        THIS_
        FA_TAG Tag,
        PCSTR Extension
        ) PURE;
    // Sets the given ULONG value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetUlong)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG Value
        ) PURE;
    // Sets the given ULONG64 value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetUlong64)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG64 Value
        ) PURE;
    // Sets the given Buffer value for corresponding tag
    // It overwrites the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, SetBuffer)(
        THIS_
        FA_TAG Tag,
        _In_ FA_ENTRY_TYPE EntryType,
        _In_reads_bytes_(Size) PVOID Buf,
        _In_ ULONG Size
        ) PURE;
    // Sets the given String for corresponding tag
    // It adds a new entry the value if tag is already
    // present.
    STDMETHOD_(PFA_ENTRY, AddString)(
        THIS_
        FA_TAG Tag,
        _In_ PCSTR Str
        ) PURE;
    // Sets the given extension command and its
    // argument for corresponding tag in a new entry
    STDMETHOD_(PFA_ENTRY, AddExtensionCommand)(
        THIS_
        FA_TAG Tag,
        _In_ PCSTR Extension
        ) PURE;
    // Sets the given ULONG value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddUlong)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG Value
        ) PURE;
    // Sets the given ULONG64 value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddUlong64)(
        THIS_
        FA_TAG Tag,
        _In_ ULONG64 Value
        ) PURE;
    // Sets the given Buffer value for corresponding tag
    // in a new entry
    STDMETHOD_(PFA_ENTRY, AddBuffer)(
        THIS_
        FA_TAG Tag,
        _In_ FA_ENTRY_TYPE EntryType,
        _In_reads_bytes_(Size) PVOID const Buf,
        _In_ ULONG Size
        ) PURE;
    // Get the interface to query and set meta-data about
    // failure analysis tags
    STDMETHOD(GetDebugFATagControl)(
        THIS_
        _Out_ IDebugFAEntryTags** FATagControl
        ) PURE;
    // Generates and returns XML fragment from analysis data
    STDMETHOD(GetAnalysisXml)(
        THIS_
        #ifdef __IXMLDOMElement_FWD_DEFINED__
        _Out_ IXMLDOMElement** ppXMLDOMElement
        #else
        _Out_ IUnknown** ppXMLDOMElement
        #endif
        ) PURE;
    // Adds another analysis object as structured data in a new entry
    STDMETHOD(AddStructuredAnalysisData)(
        THIS_
        FA_TAG Tag,
        _In_ IDebugFailureAnalysis2 *Analysis
        ) PURE;

    //
    // IDebugFailureAnalysis3
    //

    STDMETHOD(AddThreads)(
        THIS_
        _In_ IUnknown* pDebugFailureThreadEnum
        ) PURE;

    // Attributes

    STDMETHOD(AttributeGet)(
        THIS_
        _In_ ULONG nIndex,
        _Out_ VARIANT* pValue
        ) PURE;

    STDMETHOD(AttributeGetName)(
        THIS_
        _In_ ULONG nIndex,
        _Out_ BSTR* pName
        ) PURE;

    STDMETHOD(AttributeSet)(
        THIS_
        _In_ ULONG nIndex,
        _In_ VARIANT Value
        ) PURE;

    // Blames

    STDMETHOD(BlameApplication)(
        THIS_
        _In_ BSTR Postfix
        ) PURE;

    STDMETHOD(BlameProcess)(
        THIS_
        _In_ BSTR Postfix
        ) PURE;

    STDMETHOD(BlameThread)(
        THIS_
        _In_ IUnknown* pThread
        ) PURE;

    STDMETHOD(BlameStitch)(
        THIS_
        _In_ IUnknown* pThread,
        _In_ BSTR Stitch
        ) PURE;

    STDMETHOD(BlameTEB)(
        THIS_
        _In_ ULONG64 Address
        ) PURE;

    STDMETHOD(BlameETHREAD)(
        THIS_
        _In_ ULONG64 Address
        ) PURE;

    // Problem Classes

    STDMETHOD(ProblemClassIsSet)(
        THIS_
        _In_ ULONG nIndex,
        _Out_ VARIANT_BOOL* pSet
        ) PURE;

    STDMETHOD(ProblemClassDelete)(
        THIS_
        _In_ ULONG nIndex
        ) PURE;

    STDMETHOD(ProblemClassSet)(
        THIS_
        _In_ ULONG nIndex
        ) PURE;

    STDMETHOD(ProblemClassSetBSTR)(
        THIS_
        _In_ ULONG nIndex,
        _In_ BSTR Value
        ) PURE;

    // XMLs

    STDMETHOD(SetAdditionalXML)(
        THIS_
        _In_ BSTR Key,
        _In_ IUnknown* pXMLDOMElement
        ) PURE;

    STDMETHOD(GetAdditionalXML)(
        THIS_
        _In_ BSTR Key,
        _Out_ IUnknown** ppXMLDOMElement
        ) PURE;

    STDMETHOD(DeleteAdditionalXML)(
        THIS_
        _In_ BSTR Key
        ) PURE;
};

//
// Analysis control flags
//
// Analyzer doesn't lookup database for information about failure
#define FAILURE_ANALYSIS_NO_DB_LOOKUP           0x0001
// Produces verbose analysis output
#define FAILURE_ANALYSIS_VERBOSE                0x0002
// Assumes target is hung when doing analysis
#define FAILURE_ANALYSIS_ASSUME_HANG            0x0004
// Ignores manual breakin state and continues forward with analysis
#define FAILURE_ANALYSIS_IGNORE_BREAKIN         0x0008
// Sets the analysis failure context after finishing up analysis
#define FAILURE_ANALYSIS_SET_FAILURE_CONTEXT    0x0010
// Analyze the exception as if it were a hang
#define FAILURE_ANALYSIS_EXCEPTION_AS_HANG      0x0020
// Support Autobug processing
#define FAILURE_ANALYSIS_AUTOBUG_PROCESSING     0x0040
// Produces xml analysis output
#define FAILURE_ANALYSIS_XML_OUTPUT             0x0080
// produces XML representations of callstacks
#define FAILURE_ANALYSIS_CALLSTACK_XML          0x0100
// Adds cabbed registry data to analysis tags
#define FAILURE_ANALYSIS_REGISTRY_DATA          0x0200
// Adds cabbed WMI query data to analysis tags
#define FAILURE_ANALYSIS_WMI_QUERY_DATA         0x0400
// Adds user analysis attribute list as analysis data
#define FAILURE_ANALYSIS_USER_ATTRIBUTES        0x0800
// produces XML listing of loaded and unloaded modules
#define FAILURE_ANALYSIS_MODULE_INFO_XML        0x1000
// skip image corruption analysis
#define FAILURE_ANALYSIS_NO_IMAGE_CORRUPTION    0x2000
// Automatically sets symbol and image path if no symbols are currently available
#define FAILURE_ANALYSIS_AUTOSET_SYMPATH        0x4000
// All Attributes to XML
#define FAILURE_ANALYSIS_USER_ATTRIBUTES_ALL    0x8000
//interlace stack frames with attributes for xml
#define FAILURE_ANALYSIS_USER_ATTRIBUTES_FRAMES 0x10000
// analyze multiple targets if available
#define FAILURE_ANALYSIS_MULTI_TARGET           0x20000
// Show source line information in STACK_TEXT. Switching on this option has significant perf impact otherwise
#define FAILURE_ANALYSIS_SHOW_SOURCE            0x40000
// Print wait chain stacks
#define FAILURE_ANALYSIS_SHOW_WCT_STACKS        0x80000
// Create basic DebugFailureAnalysis instance
#define FAILURE_ANALYSIS_CREATE_INSTANCE        0x100000
// Evaluate failure for holding a live debug session
#define FAILURE_ANALYSIS_LIVE_DEBUG_HOLD_CHECK  0x200000
// produces XML file output
#define FAILURE_ANALYSIS_XML_FILE_OUTPUT        0x400000
// verify Analysis XML against XSD
#define FAILURE_ANALYSIS_XSD_VERIFY             0x800000
// Include full source info (source path and line number) in callstack XML
#define FAILURE_ANALYSIS_CALLSTACK_XML_FULL_SOURCE_INFO 0x1000000
// Blame function in heap_corruption bucket (the default behavior is to blame module)
#define FAILURE_ANALYSIS_HEAP_CORRUPTION_BLAME_FUNCTION 0x2000000
// Do not modify STATUS_ACCESS_VIOLATION in the heap manager (the default behavior is to translate to STATUS_HEAP_CORRUPTION)
#define FAILURE_ANALYSIS_PERMIT_HEAP_ACCESS_VIOLATIONS  0x4000000

// Apply specified XSLT to the Analysis XML
#define FAILURE_ANALYSIS_XSLT_FILE_INPUT        0x10000000
// Save XSLT Ouput to the specified File (default is to the screen)
#define FAILURE_ANALYSIS_XSLT_FILE_OUTPUT       0x20000000

//
// Class Factory for IDebugFailureAnalysis
// ## Deprecated ##
//
typedef HRESULT
(WINAPI* EXT_GET_FAILURE_ANALYSIS)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ ULONG Flags,
    _Out_ IDebugFailureAnalysis** ppAnalysis
    );

//
// Class Factory for IDebugFailureAnalysis2
// ## Deprecated ##
//
typedef HRESULT
(WINAPI* EXT_GET_DEBUG_FAILURE_ANALYSIS)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ ULONG Flags,
    _In_ CLSID ClassId,  // Not Used
    _Out_ IDebugFailureAnalysis2** ppAnalysis
    );

//
// CoCreateInstance style Class Factory for CLSID_DebugFailureAnalysis* based objects
//
// Classes implemented by ext.dll (!analyze)
// - All  classes require IDebugClient
// - Some classes require IDebugClient4 (or higher)
// - All  classes support IDebugFailureAnalysis
// - All  classes support IDebugFailureAnalysis2
// - Some classes support IDebugAnalysis
// - Some classes support ICLRManagedAnalysis
// - Some classes support IStreamAnalysis
// - Some classes support IKeyValues
// - Some classes support ITimelines
//
// Parameters:
// - Client : IDebugClient via dbgeng.h               (ext.dll - IDebugClient4 or higher is required)
// - Args   : Flags via Command Line        (optional)(ext.dll - !analyze Command Line)
// - Flags  : FAILURE_ANALYSIS_* mask       (optional)(ext.dll - FAILURE_ANALYSIS_CREATE_INSTANCE creates CLSID_DebugFailureAnalysisBase)
// - rclsid : CLSID_DebugFailureAnalysis*             (ext.dll - CLSID_NULL defaults to CLSID_DebugFailureAnalysisTarget)
// - riid   : IUnknown based interface                (ext.dll - IDebugFailureAnalysis or IDebugFailureAnalysis2)
// - ppv    : IUnknown based pointer
//
// Note: !analyze merges the Args/Flags/oca.ini (debugger-params!AnalysisFlags) bitmasks
//
// Return:
// - S_OK - Success
// - E_NOINTERFACE - No Interface
// - E_NOTIMPL - Not Implemented
// - E_OUTOFMEMORY - Out of Memory
// - E_* - : Other Failures
//

typedef HRESULT
(WINAPI* fnDebugFailureAnalysisCreateInstance)(
    _In_ IDebugClient* Client,
    _In_opt_ PCWSTR Args,
    _In_opt_ ULONG Flags,
    _In_opt_ REFCLSID rclsid,
    _In_ REFIID riid,
    _Out_ LPVOID *ppv
    );

// CLSID_DebugFailureAnalysisBasic
// {B74EED7F-1C7D-4c1b-959F-B96DD9175AA4}
DEFINE_GUID(CLSID_DebugFailureAnalysisBasic, 0xb74eed7f, 0x1c7d, 0x4c1b, 0x95, 0x9f, 0xb9, 0x6d, 0xd9, 0x17, 0x5a, 0xa4);

// CLSID_DebugFailureAnalysisTarget -- User/Kernel/WinCE/XBox360/etc. based on Target
// {BA9BFB05-EF75-4bbd-A745-A6B5529458B8}
DEFINE_GUID(CLSID_DebugFailureAnalysisTarget, 0xba9bfb05, 0xef75, 0x4bbd, 0xa7, 0x45, 0xa6, 0xb5, 0x52, 0x94, 0x58, 0xb8);

// CLSID_DebugFailureAnalysisUser
// {E60B0C93-CF49-4a32-8147-0362202DC56B}
DEFINE_GUID(CLSID_DebugFailureAnalysisUser, 0xe60b0c93, 0xcf49, 0x4a32, 0x81, 0x47, 0x3, 0x62, 0x20, 0x2d, 0xc5, 0x6b);

// CLSID_DebugFailureAnalysisKernel
// {EE433078-64AF-4c33-AB2F-ECAD7F2A002D}
DEFINE_GUID(CLSID_DebugFailureAnalysisKernel, 0xee433078, 0x64af, 0x4c33, 0xab, 0x2f, 0xec, 0xad, 0x7f, 0x2a, 0x0, 0x2d);

// CLSID_DebugFailureAnalysisWinCE
// {67D5E86F-F5E2-462a-9233-1BD616FCC7E8}
DEFINE_GUID(CLSID_DebugFailureAnalysisWinCE, 0x67d5e86f, 0xf5e2, 0x462a, 0x92, 0x33, 0x1b, 0xd6, 0x16, 0xfc, 0xc7, 0xe8);

// CLSID_DebugFailureAnalysisXBox360
// {901625BB-95F1-4318-AC80-9D733CEE8C8B}
DEFINE_GUID(CLSID_DebugFailureAnalysisXBox360, 0x901625bb, 0x95f1, 0x4318, 0xac, 0x80, 0x9d, 0x73, 0x3c, 0xee, 0x8c, 0x8b);


//
// This determines the analysis phase during which a registered
// analysis-plugin is invoked. The extensions can register their
// plugin along with one or more of these flags to control the
// time when the plugin gets called.
//
typedef enum _FA_EXTENSION_PLUGIN_PHASE
{
    // Extension plugin is invoked after the primary data such as
    // exception record (for user mode) / bugcheck code (for kernel
    // mode) is initialized
    FA_PLUGIN_INITIALIZATION   = 0x0001,
    // Extension plugin is invoked after the stack is analyzed and
    // the analysis has the information about faulting symbol and
    // module if it were available on stack
    FA_PLUGIN_STACK_ANALYSIS   = 0x0002,
    // Extension plugin is invoked just before generating bucket.
    FA_PLUGIN_PRE_BUCKETING    = 0x0004,
    // Extension plugin is invoked just after generating bucket.
    FA_PLUGIN_POST_BUCKETING   = 0x0008,
} FA_EXTENSION_PLUGIN_PHASE;

#define FA_PLUGIN_INITILIZATION FA_PLUGIN_INITIALIZATION     // fix typo

//
// Function signature for custom analyzer entry point in a
// registered analysis-plugin dll.
//
typedef HRESULT
(WINAPI* EXT_ANALYSIS_PLUGIN)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ FA_EXTENSION_PLUGIN_PHASE CallPhase,
    _In_ PDEBUG_FAILURE_ANALYSIS2 pAnalysis
    );

typedef HRESULT
(WINAPI* EXT_GET_FA_ENTRIES_DATA)(
    IN PDEBUG_CLIENT4 Client,
    IN PULONG Count,
    OUT PFA_ENTRY* Entries
    );


/*****************************************************************************
   Target Information
 *****************************************************************************/

//
// CURRENT VERSION
//
// Changes of Note:
// - CROSS_PLATFORM_MAXIMUM_PROCESSORS = 2048
//

    #ifndef CROSS_PLATFORM_MAXIMUM_PROCESSORS
    // NB: Keep in sync with wdbgexts.w/h (the legacy debugger API header)
    #define CROSS_PLATFORM_MAXIMUM_PROCESSORS 2048
    #endif

    typedef enum _OS_TYPE {
        WIN_95,
        WIN_98,
        WIN_ME,
        WIN_NT4,
        WIN_NT5,
        WIN_NT5_1,
        WIN_NT5_2,
        WIN_NT6_0,
        WIN_NT6_1,
        WIN_UNDEFINED = 0xFF
    } OS_TYPE;

    typedef struct _OS_INFO {
        ULONG     MajorVer;      // Os major version
        ULONG     MinorVer;      // Os minor version
        ULONG     Build;         // Os build number
        ULONG     BuildQfe;      // Os build QFE number
        ULONG     ProductType; // NT, LanMan or Server
        ULONG     Suite;        // OS flavour - per, SmallBuisness etc.
        ULONG     Revision;
        struct {
            ULONG Checked:1;     // If its a checked build
            ULONG Pae:1;         // True for Pae systems
            ULONG MultiProc:1;   // True for multiproc enabled OS
            ULONG Reserved:29;
        } s;
        ULONG   SrvPackNumber;          // Service pack number of OS
        ULONG   ServicePackBuild;       // Service pack build
        ULONG   Architecture;           // Architecture name such as x86, ia64 or x64
        ULONG   Lcid;                   // Language id
        CHAR    Name[64];               // Short name of OS
        CHAR    FullName[256];          // Full name of OS includeing SP, Suite, product
        CHAR    Language[30];           // OS language
        CHAR    BuildVersion[64];       // Build version string
        CHAR    ServicePackString[64];  // Service pack string
    } OS_INFO, *POS_INFO;

    typedef struct _CPU_INFO {
        ULONG Type;              // Processor type as in IMAGE_FILE_MACHINE types
        ULONG NumCPUs;           // Actual number of Processors
        ULONG CurrentProc;       // Current processor
        DEBUG_PROCESSOR_IDENTIFICATION_ALL ProcInfo[CROSS_PLATFORM_MAXIMUM_PROCESSORS];
        ULONG Mhz;               // Processor speed (from currentproc.prcb)
    } CPU_INFO, *PCPU_INFO;

    typedef struct _TARGET_DEBUG_INFO {
        ULONG       SizeOfStruct;
        ULONG64     EntryDate;   // Date created
        ULONG       DebugeeClass;// Kernel / User mode
        ULONG64     SysUpTime;   // System Up time
        ULONG64     AppUpTime;   // Application up time
        ULONG64     CrashTime;   // Time system / app crashed
        OS_INFO     OsInfo;      // OS details
        CPU_INFO    Cpu;         // Processor details
        CHAR        DumpFile[MAX_PATH]; // Dump file name if its a dump
    } TARGET_DEBUG_INFO, *PTARGET_DEBUG_INFO;

//
// VERSION 2
//
// Changes of Note:
// - OS_INFO structure
// - CROSS_PLATFORM_MAXIMUM_PROCESSORS = 1280
//

    typedef struct _CPU_INFO_v2 {
        ULONG Type;              // Processor type as in IMAGE_FILE_MACHINE types
        ULONG NumCPUs;           // Actual number of Processors
        ULONG CurrentProc;       // Current processor
        DEBUG_PROCESSOR_IDENTIFICATION_ALL ProcInfo[1280];
        ULONG Mhz;               // Processor speed (from currentproc.prcb)
    } CPU_INFO_v2, *PCPU_INFO_v2;

    typedef struct _TARGET_DEBUG_INFO_v2 {
        ULONG       SizeOfStruct;
        ULONG64     EntryDate;   // Date created
        ULONG       DebugeeClass;// Kernel / User mode
        ULONG64     SysUpTime;   // System Up time
        ULONG64     AppUpTime;   // Application up time
        ULONG64     CrashTime;   // Time system / app crashed
        OS_INFO     OsInfo;      // OS details
        CPU_INFO_v2 Cpu;         // Processor details
        CHAR        DumpFile[MAX_PATH]; // Dump file name if its a dump
    } TARGET_DEBUG_INFO_v2, *PTARGET_DEBUG_INFO_v2;

//
// VERSION 1
//

    #define MAX_STACK_IN_BYTES 4096

    typedef struct _OS_INFO_v1 {
        OS_TYPE   Type;          // OS type such as NT4, NT5 etc.
        union {
            struct {
                ULONG Major;
                ULONG Minor;
            } Version;     // 64 bit OS version number
            ULONG64 Ver64;
        };
        ULONG ProductType; // NT, LanMan or Server
        ULONG Suite;        // OS flavour - per, SmallBuisness etc.
        struct {
            ULONG Checked:1;     // If its a checked build
            ULONG Pae:1;         // True for Pae systems
            ULONG MultiProc:1;   // True for multiproc enabled OS
            ULONG Reserved:29;
        } s;
        ULONG   SrvPackNumber;   // Service pack number of OS
        CHAR   Language[30];    // OS language
        CHAR   OsString[64];    // Build string
        CHAR   ServicePackString[64];
                                 // Service pack string
    } OS_INFO_v1, *POS_INFO_v1;

    typedef struct _CPU_INFO_v1 {
        ULONG Type;              // Processor type as in IMAGE_FILE_MACHINE types
        ULONG NumCPUs;           // Actual number of Processors
        ULONG CurrentProc;       // Current processor
        DEBUG_PROCESSOR_IDENTIFICATION_ALL ProcInfo[32];
        ULONG Mhz;               // Processor speed (from currentproc.prcb)
    } CPU_INFO_v1, *PCPU_INFO_v1;

    typedef struct _TARGET_DEBUG_INFO_v1 {
        ULONG       SizeOfStruct;
        ULONG64     Id;          // ID unique to this debug info
        ULONG64     Source;      // Source where this came from
        ULONG64     EntryDate;   // Date created
        ULONG64     SysUpTime;   // System Up time
        ULONG64     AppUpTime;   // Application up time
        ULONG64     CrashTime;   // Time system / app crashed
        ULONG64     Mode;        // Kernel / User mode
        OS_INFO_v1  OsInfo;      // OS details
        CPU_INFO_v1 Cpu;         // Processor details
        CHAR       DumpFile[MAX_PATH]; // Dump file name if its a dump
        PVOID       FailureData; // Failure data collected by debugger
        CHAR        StackTr[MAX_STACK_IN_BYTES];
                                     // Contains stacks, with frames separated by newline
    } TARGET_DEBUG_INFO_v1, *PTARGET_DEBUG_INFO_v1;

//
// GetTargetInfo EXPORT
//

    // GetTargetInfo
    // - !analyze supports all structure versions defined above
    // - If there is data trucation (e.g. more CPU are present on the system than the legacy structure supports), the first N are set and S_FALSE is returned

    typedef HRESULT
    (WINAPI* EXT_TARGET_INFO)(
        PDEBUG_CLIENT4  Client,
        PTARGET_DEBUG_INFO pTargetInfo
        );

/*****************************************************************************
   Decoding
 *****************************************************************************/

typedef struct _DEBUG_DECODE_ERROR {
    ULONG     SizeOfStruct;   // Must be == sizeof(DEBUG_DECODE_ERROR)
    ULONG     Code;           // Error code to be decoded
    BOOL      TreatAsStatus;  // True if code is to be treated as Status
    CHAR      Source[64];     // Source from where we got decoded message
    CHAR      Message[MAX_PATH]; // Message string for error code
} DEBUG_DECODE_ERROR, *PDEBUG_DECODE_ERROR;

/*
   Decodes and prints the given error code - DecodeError
*/
typedef VOID
(WINAPI *EXT_DECODE_ERROR)(
    PDEBUG_DECODE_ERROR pDecodeError
    );

//
// ext.dll: GetTriageFollowupFromSymbol
//
//       This returns owner info from a given symbol name
//
typedef struct _DEBUG_TRIAGE_FOLLOWUP_INFO {
    ULONG SizeOfStruct;      // Must be == sizeof (DEBUG_TRIAGE_FOLLOWUP_INFO)
    ULONG OwnerNameSize;     // Size of allocated buffer
    PCHAR OwnerName;         // Followup owner name returned in this
                             // Caller should initialize the name buffer
} DEBUG_TRIAGE_FOLLOWUP_INFO, *PDEBUG_TRIAGE_FOLLOWUP_INFO;

typedef struct _DEBUG_TRIAGE_FOLLOWUP_INFO_2 {
    ULONG SizeOfStruct;      // Must be == sizeof (DEBUG_TRIAGE_FOLLOWUP_INFO_2)
    ULONG OwnerNameSize;     // Size of allocated buffer
    PCHAR OwnerName;         // Followup owner name returned in this
                             // Caller should initialize the name buffer
    ULONG FeaturePathSize;   // Feature path size
    PCHAR FeaturePath;       // Feature path in the bug management tool (PS, VSO, etc.)
} DEBUG_TRIAGE_FOLLOWUP_INFO_2, *PDEBUG_TRIAGE_FOLLOWUP_INFO_2;

#define TRIAGE_FOLLOWUP_FAIL    0
#define TRIAGE_FOLLOWUP_IGNORE  1
#define TRIAGE_FOLLOWUP_DEFAULT 2
#define TRIAGE_FOLLOWUP_SUCCESS 3

typedef DWORD
(WINAPI *EXT_TRIAGE_FOLLOWUP)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ PCSTR SymbolName,
    OUT PDEBUG_TRIAGE_FOLLOWUP_INFO OwnerInfo
    );

typedef HRESULT
(WINAPI *EXT_RELOAD_TRIAGER)(
   _In_ PDEBUG_CLIENT4 Client
    );


//
// Struct to receive data from syzdata.XML file cabbed along with the dump
//
typedef struct _EXT_CAB_XML_DATA {
    ULONG SizeOfStruct;       // Must be == sizeof(_EXT_CAB_XML_DATA)
    PCWSTR XmlObjectTag;      // Look for text under this tag
    ULONG NumSubTags;         // Number of subtags
    struct _SUBTAGS {
        PCWSTR SubTag;        // Look for text under this sub-tag of XmlObjectTag
        PCWSTR MatchPattern;  // Match the text with MatchPattern according to MatchType
        PWSTR  ReturnText;    // Return the matched text in ReturnText, multiple
                              // matches are returned in multistring
        ULONG ReturnTextSize; // Size of ReturnText in bytes
        ULONG MatchType:3;    // 0: Prefix match, 2: In-text match  1: Suffix match
        ULONG Reserved:29;
        ULONG Reserved2;
    } SubTags[1];
} EXT_CAB_XML_DATA, *PEXT_CAB_XML_DATA;

typedef HRESULT
(WINAPI *EXT_XML_DATA)(
    PDEBUG_CLIENT4 Client,
    PEXT_CAB_XML_DATA pXmpData
    );

//
// Driver Info as read from sysdata.xml
//
typedef struct XML_DRIVER_NODE_INFO {
    CHAR    FileName[64]; //MAX_MODULE_STRLEN
    ULONG64 FileSize;
    ULONG64 CreationDate;
    CHAR Version[64]; //MAX_VERSION_STRLEN
    CHAR Manufacturer[MAX_PATH];
    CHAR ProductName[MAX_PATH];
    CHAR Group[MAX_PATH];
    CHAR Altitude[MAX_PATH];
} XML_DRIVER_NODE_INFO, *PXML_DRIVER_NODE_INFO;

//
// Extension function type definition for dlls which want to export analyzer
// function to be used by !analyze to gather component specific data
//

#define EXT_ANALYZER_FLAG_MOD  0x00000001
#define EXT_ANALYZER_FLAG_ID   0x00000002

typedef HRESULT
(WINAPI *EXT_ANALYZER)(
   _In_opt_ PDEBUG_CLIENT Client,
   _Out_writes_bytes_(cbBucketSuffix) PSTR BucketSuffix,     // The additional suffix analyzer wants to
                              // be added to !analyze BUGCKET_ID to better distinguish this bucket
   _In_ ULONG cbBucketSuffix,   // byte count of BucketSuffix buffer supplied
   _Out_writes_bytes_(cbDebugText) PSTR DebugText,        // The debugging text (optional) which !analyze
                              // should print out to help people debugging this failure
   _In_ ULONG cbDebugText,      // byte count of DebugText buffer supplied
   _In_ PULONG Flags,           // Flags that contorl the bucketing
   _In_ PDEBUG_FAILURE_ANALYSIS pAnalysis // Data for current analysis
   );

//
// Data queried about processor, returned as part of analysis tag DEBUG_FLR_PROCESSOR_INFO
//
typedef struct _DEBUG_ANALYSIS_PROCESSOR_INFO {
    ULONG         SizeOfStruct; // must be == sizeof(DEBUG_ANALYSIS_PROCESSOR_INFO)
    ULONG         Model;
    ULONG         Family;
    ULONG         Stepping;
    ULONG         Architecture;
    ULONG         Revision;
    ULONG         CurrentClockSpeed;
    ULONG         CurrentVoltage;
    ULONG         MaxClockSpeed;
    ULONG         ProcessorType;
    CHAR          DeviceID[32];
    CHAR          Manufacturer[64];
    CHAR          Name[64];
    CHAR          Version[64];
    CHAR          Description[64];
} DEBUG_ANALYSIS_PROCESSOR_INFO, *PDEBUG_ANALYSIS_PROCESSOR_INFO;


// Queried target build binary dir, the build dir string is returned in pData
// pQueryInfo must be null
#define EXTDLL_DATA_QUERY_BUILD_BINDIR 1
#define EXTDLL_DATA_QUERY_BUILD_SYMDIR 2
#define EXTDLL_DATA_QUERY_BUILD_WOW64SYMDIR 3
#define EXTDLL_DATA_QUERY_BUILD_WOW64BINDIR 4

#define EXTDLL_DATA_QUERY_BUILD_BINDIR_SYMSRV 11
#define EXTDLL_DATA_QUERY_BUILD_SYMDIR_SYMSRV 12
#define EXTDLL_DATA_QUERY_BUILD_WOW64SYMDIR_SYMSRV 13
#define EXTDLL_DATA_QUERY_BUILD_WOW64BINDIR_SYMSRV 14

//
// Extension function ExtDllQueryDataByTag exported by ext.dll to query
// various data values. The alowd tags values are defined above
//
typedef HRESULT
(WINAPI *EXTDLL_QUERYDATABYTAG)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ ULONG dwDataTag,
    _In_ PVOID pQueryInfo,
    _Out_writes_bytes_(cbData) PBYTE pData,
    _In_ ULONG cbData
    );

//
// This is an extension of the function ExtDllQueryDataByTagEx exported by ext.dll to query
// various data values. This function will return the Path-Non_existing buildName/UNC path value.
//
typedef HRESULT
(WINAPI *EXTDLL_QUERYDATABYTAGEX)(
    _In_ PDEBUG_CLIENT4 Client,
    _In_ ULONG dwDataTag,
    _In_ PVOID pQueryInfo,
    _Out_writes_bytes_(cbData) PBYTE pData,
    _In_ ULONG cbData,
    _Out_writes_bytes_(cbDataEx) PBYTE pDataEx,
    _In_ ULONG cbDataEx
    );

typedef
HRESULT
(*ENTRY_CALLBACK) (
    _In_ ULONG64 EntryAddress,
    _Inout_opt_ PVOID Context
    );;

typedef VOID
(WINAPI *EXTDLL_ITERATERTLBALANCEDNODES) (
    _In_ ULONG64 RootNode,
    _In_ ULONG EntryOffset,
    _In_ ENTRY_CALLBACK Callback,
    _Inout_opt_ PVOID CallbackContext
    );

#endif // _EXTAPIS_H


//
// Function exported from ntsdexts.dll
//
typedef HRESULT
(WINAPI *EXT_GET_HANDLE_TRACE)(
    PDEBUG_CLIENT Client,
    ULONG TraceType,
    ULONG StartIndex,
    PULONG64 HandleValue,
    PULONG64 StackFunctions,
    ULONG StackTraceSize
    );


//
// Functions exported from exts.dll
//

//
// GetEnvironmenttVariable - gets environment variable value from the target
//
typedef HRESULT
(WINAPI* EXT_GET_ENVIRONMENT_VARIABLE)(
    ULONG64 Peb,           // Peb address where variable resides, 0 for default
    PSTR Variable,         // Env Variable name
    PSTR Buffer,           // Buffer to receive the value in
    ULONG BufferSize       // size of buffer
    );




 /*++

    Structures defined that are used to pass data
    between ext.dll & wmiTrace.dll debug extensions

 --*/



typedef enum _TANALYZE_RETURN{
    NO_TYPE,
    PROCESS_END,
    EXIT_STATUS,
    DISK_READ_0_BYTES,
    DISK_WRITE,
    NT_STATUS_CODE,
}TANALYZE_RETURN;


typedef struct _CKCL_DATA{
    PVOID NextLogEvent;
    CHAR * TAnalyzeString;
    TANALYZE_RETURN TAnalyzeReturnType;
}CKCL_DATA, *PCKCL_DATA;


typedef struct _CKCL_LISTHEAD{
    PCKCL_DATA LogEventListHead;
    HANDLE  Heap;
}CKCL_LISTHEAD,*PCKCL_LISTHEAD;

#endif // _EXTFNS_H
