#include <winapifamily.h>

/*++

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    EvnTrace.h

Abstract:

    Public headers for event tracing control applications,
    consumers and providers

--*/

#ifndef _EVNTRACE_
#define _EVNTRACE_

#pragma once

#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4820) /* padding added */
#endif

#if defined(_WINNT_) || defined(WINNT)

#if !defined(NO_ETW_APP_DEPRECATION_WARNINGS)

#if (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) || WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_GAMES)) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_SYSTEM)
#define ETW_APP_DECLSPEC_DEPRECATED __declspec(deprecated("This API is not recommended for general usage in Windows Store Apps or Games and may not be supported in future versions of Windows"))
#else
#define ETW_APP_DECLSPEC_DEPRECATED
#endif // (WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP) || WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_GAMES)) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) && !WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_SYSTEM)

#else

#define ETW_APP_DECLSPEC_DEPRECATED
#endif // NO_ETW_APP_DEPRECATION_WARNINGS

#pragma region Application Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#ifndef WMIAPI
#ifndef MIDL_PASS
#ifdef _WMI_SOURCE_
#define WMIAPI __stdcall
#else
#define WMIAPI DECLSPEC_IMPORT __stdcall
#endif // _WMI_SOURCE
#endif // MIDL_PASS

#endif // WMIAPI

#include <guiddef.h>

#if defined(_NTDDK_) || defined(_NTIFS_) || defined(_WMIKM_)

#define _EVNTRACE_KERNEL_MODE

#endif

#if !defined(_EVNTRACE_KERNEL_MODE)

#include <wmistr.h>

#endif

//
// EventTraceGuid is used to identify a event tracing session
//
DEFINE_GUID ( /* 68fdd900-4a3e-11d1-84f4-0000f80464e3 */
    EventTraceGuid,
    0x68fdd900,
    0x4a3e,
    0x11d1,
    0x84, 0xf4, 0x00, 0x00, 0xf8, 0x04, 0x64, 0xe3
  );

//
// SystemTraceControlGuid. Used to specify event tracing for kernel
//
DEFINE_GUID ( /* 9e814aad-3204-11d2-9a82-006008a86939 */
    SystemTraceControlGuid,
    0x9e814aad,
    0x3204,
    0x11d2,
    0x9a, 0x82, 0x00, 0x60, 0x08, 0xa8, 0x69, 0x39
  );

//
// EventTraceConfigGuid. Used to report system configuration records
//
DEFINE_GUID ( /* 01853a65-418f-4f36-aefc-dc0f1d2fd235 */
    EventTraceConfigGuid,
    0x01853a65,
    0x418f,
    0x4f36,
    0xae, 0xfc, 0xdc, 0x0f, 0x1d, 0x2f, 0xd2, 0x35
  );

//
// DefaultTraceSecurityGuid. Specifies the default event tracing security
//
DEFINE_GUID ( /* 0811c1af-7a07-4a06-82ed-869455cdf713 */
    DefaultTraceSecurityGuid,
    0x0811c1af,
    0x7a07,
    0x4a06,
    0x82, 0xed, 0x86, 0x94, 0x55, 0xcd, 0xf7, 0x13
  );


//
// PrivateLoggerNotificationGuid
// Used for private cross-process logger notifications.
//

DEFINE_GUID ( /* 3595ab5c-042a-4c8e-b942-2d059bfeb1b1 */
    PrivateLoggerNotificationGuid,
    0x3595ab5c,
    0x042a,
    0x4c8e,
    0xb9, 0x42, 0x2d, 0x05, 0x9b, 0xfe, 0xb1, 0xb1
  );


#define KERNEL_LOGGER_NAMEW         L"NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEW         L"GlobalLogger"
#define EVENT_LOGGER_NAMEW          L"EventLog"
#define DIAG_LOGGER_NAMEW           L"DiagLog"

#define KERNEL_LOGGER_NAMEA         "NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEA         "GlobalLogger"
#define EVENT_LOGGER_NAMEA          "EventLog"
#define DIAG_LOGGER_NAMEA           "DiagLog"

#define MAX_MOF_FIELDS                      16  // Limit of USE_MOF_PTR fields

#ifndef _TRACEHANDLE_DEFINED
#define _TRACEHANDLE_DEFINED
typedef ULONG64 TRACEHANDLE, *PTRACEHANDLE;
#endif

 //types for event data going to System Event Logger
#define SYSTEM_EVENT_TYPE                        1

//
// predefined generic event types (0x00 to 0x09 reserved).
//

#define EVENT_TRACE_TYPE_INFO               0x00  // Info or point event
#define EVENT_TRACE_TYPE_START              0x01  // Start event
#define EVENT_TRACE_TYPE_END                0x02  // End event
#define EVENT_TRACE_TYPE_STOP               0x02  // Stop event (WinEvent compatible)
#define EVENT_TRACE_TYPE_DC_START           0x03  // Collection start marker
#define EVENT_TRACE_TYPE_DC_END             0x04  // Collection end marker
#define EVENT_TRACE_TYPE_EXTENSION          0x05  // Extension/continuation
#define EVENT_TRACE_TYPE_REPLY              0x06  // Reply event
#define EVENT_TRACE_TYPE_DEQUEUE            0x07  // De-queue event
#define EVENT_TRACE_TYPE_RESUME             0x07  // Resume event (WinEvent compatible)
#define EVENT_TRACE_TYPE_CHECKPOINT         0x08  // Generic checkpoint event
#define EVENT_TRACE_TYPE_SUSPEND            0x08  // Suspend event (WinEvent compatible)
#define EVENT_TRACE_TYPE_WINEVT_SEND        0x09  // Send Event (WinEvent compatible)
#define EVENT_TRACE_TYPE_WINEVT_RECEIVE     0XF0  // Receive Event (WinEvent compatible)

//
// Predefined Event Tracing Levels for Software/Debug Tracing
//
//
// Trace Level is UCHAR and passed in through the EnableLevel parameter
// in EnableTrace API. It is retrieved by the provider using the
// GetTraceEnableLevel macro.It should be interpreted as an integer value
// to mean everything at or below that level will be traced.
//
// Here are the possible Levels.
//

#define TRACE_LEVEL_NONE        0   // Tracing is not on
#define TRACE_LEVEL_CRITICAL    1   // Abnormal exit or termination
#define TRACE_LEVEL_FATAL       1   // Deprecated name for Abnormal exit or termination
#define TRACE_LEVEL_ERROR       2   // Severe errors that need logging
#define TRACE_LEVEL_WARNING     3   // Warnings such as allocation failure
#define TRACE_LEVEL_INFORMATION 4   // Includes non-error cases(e.g.,Entry-Exit)
#define TRACE_LEVEL_VERBOSE     5   // Detailed traces from intermediate steps
#define TRACE_LEVEL_RESERVED6   6
#define TRACE_LEVEL_RESERVED7   7
#define TRACE_LEVEL_RESERVED8   8
#define TRACE_LEVEL_RESERVED9   9


//
// Event types for Process & Threads
//

#define EVENT_TRACE_TYPE_LOAD                  0x0A      // Load image
#define EVENT_TRACE_TYPE_TERMINATE             0x0B      // Terminate Process

//
// Event types for IO subsystem
//

#define EVENT_TRACE_TYPE_IO_READ               0x0A
#define EVENT_TRACE_TYPE_IO_WRITE              0x0B
#define EVENT_TRACE_TYPE_IO_READ_INIT          0x0C
#define EVENT_TRACE_TYPE_IO_WRITE_INIT         0x0D
#define EVENT_TRACE_TYPE_IO_FLUSH              0x0E
#define EVENT_TRACE_TYPE_IO_FLUSH_INIT         0x0F
#define EVENT_TRACE_TYPE_IO_REDIRECTED_INIT    0x10

//
// Event types for Memory subsystem
//

#define EVENT_TRACE_TYPE_MM_TF                 0x0A      // Transition fault
#define EVENT_TRACE_TYPE_MM_DZF                0x0B      // Demand Zero fault
#define EVENT_TRACE_TYPE_MM_COW                0x0C      // Copy on Write
#define EVENT_TRACE_TYPE_MM_GPF                0x0D      // Guard Page fault
#define EVENT_TRACE_TYPE_MM_HPF                0x0E      // Hard page fault
#define EVENT_TRACE_TYPE_MM_AV                 0x0F      // Access violation

//
// Event types for Network subsystem, all protocols
//

#define EVENT_TRACE_TYPE_SEND                  0x0A     // Send
#define EVENT_TRACE_TYPE_RECEIVE               0x0B     // Receive
#define EVENT_TRACE_TYPE_CONNECT               0x0C     // Connect
#define EVENT_TRACE_TYPE_DISCONNECT            0x0D     // Disconnect
#define EVENT_TRACE_TYPE_RETRANSMIT            0x0E     // ReTransmit
#define EVENT_TRACE_TYPE_ACCEPT                0x0F     // Accept
#define EVENT_TRACE_TYPE_RECONNECT             0x10     // ReConnect
#define EVENT_TRACE_TYPE_CONNFAIL              0x11     // Fail
#define EVENT_TRACE_TYPE_COPY_TCP              0x12     // Copy in PendData
#define EVENT_TRACE_TYPE_COPY_ARP              0x13     // NDIS_STATUS_RESOURCES Copy
#define EVENT_TRACE_TYPE_ACKFULL               0x14     // A full data ACK
#define EVENT_TRACE_TYPE_ACKPART               0x15     // A Partial data ACK
#define EVENT_TRACE_TYPE_ACKDUP                0x16     // A Duplicate data ACK


//
// Event Types for the Header (to handle internal event headers)
//

#define EVENT_TRACE_TYPE_GUIDMAP                0x0A
#define EVENT_TRACE_TYPE_CONFIG                 0x0B
#define EVENT_TRACE_TYPE_SIDINFO                0x0C
#define EVENT_TRACE_TYPE_SECURITY               0x0D
#define EVENT_TRACE_TYPE_DBGID_RSDS             0x40

//
// Event Types for Registry subsystem
//

#define EVENT_TRACE_TYPE_REGCREATE                  0x0A     // NtCreateKey
#define EVENT_TRACE_TYPE_REGOPEN                    0x0B     // NtOpenKey
#define EVENT_TRACE_TYPE_REGDELETE                  0x0C     // NtDeleteKey
#define EVENT_TRACE_TYPE_REGQUERY                   0x0D     // NtQueryKey
#define EVENT_TRACE_TYPE_REGSETVALUE                0x0E     // NtSetValueKey
#define EVENT_TRACE_TYPE_REGDELETEVALUE             0x0F     // NtDeleteValueKey
#define EVENT_TRACE_TYPE_REGQUERYVALUE              0x10     // NtQueryValueKey
#define EVENT_TRACE_TYPE_REGENUMERATEKEY            0x11     // NtEnumerateKey
#define EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY       0x12     // NtEnumerateValueKey
#define EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE      0x13     // NtQueryMultipleValueKey
#define EVENT_TRACE_TYPE_REGSETINFORMATION          0x14     // NtSetInformationKey
#define EVENT_TRACE_TYPE_REGFLUSH                   0x15     // NtFlushKey
#define EVENT_TRACE_TYPE_REGKCBCREATE               0x16     // KcbCreate
#define EVENT_TRACE_TYPE_REGKCBDELETE               0x17     // KcbDelete
#define EVENT_TRACE_TYPE_REGKCBRUNDOWNBEGIN         0x18     // KcbRundownBegin
#define EVENT_TRACE_TYPE_REGKCBRUNDOWNEND           0x19     // KcbRundownEnd
#define EVENT_TRACE_TYPE_REGVIRTUALIZE              0x1A     // VirtualizeKey
#define EVENT_TRACE_TYPE_REGCLOSE                   0x1B     // NtClose (KeyObject)
#define EVENT_TRACE_TYPE_REGSETSECURITY             0x1C     // SetSecurityDescriptor (KeyObject)
#define EVENT_TRACE_TYPE_REGQUERYSECURITY           0x1D     // QuerySecurityDescriptor (KeyObject)
#define EVENT_TRACE_TYPE_REGCOMMIT                  0x1E     // CmKtmNotification (TRANSACTION_NOTIFY_COMMIT)
#define EVENT_TRACE_TYPE_REGPREPARE                 0x1F     // CmKtmNotification (TRANSACTION_NOTIFY_PREPARE)
#define EVENT_TRACE_TYPE_REGROLLBACK                0x20     // CmKtmNotification (TRANSACTION_NOTIFY_ROLLBACK)
#define EVENT_TRACE_TYPE_REGMOUNTHIVE               0x21     // NtLoadKey variations + system hives

//
// Event types for system configuration records
//
#define EVENT_TRACE_TYPE_CONFIG_CPU             0x0A     // CPU Configuration
#define EVENT_TRACE_TYPE_CONFIG_PHYSICALDISK    0x0B     // Physical Disk Configuration
#define EVENT_TRACE_TYPE_CONFIG_LOGICALDISK     0x0C     // Logical Disk Configuration
#define EVENT_TRACE_TYPE_CONFIG_NIC             0x0D     // NIC Configuration
#define EVENT_TRACE_TYPE_CONFIG_VIDEO           0x0E     // Video Adapter Configuration
#define EVENT_TRACE_TYPE_CONFIG_SERVICES        0x0F     // Active Services
#define EVENT_TRACE_TYPE_CONFIG_POWER           0x10     // ACPI Configuration
#define EVENT_TRACE_TYPE_CONFIG_NETINFO         0x11     // Networking Configuration
#define EVENT_TRACE_TYPE_CONFIG_OPTICALMEDIA    0x12     // Optical Media Configuration

#define EVENT_TRACE_TYPE_CONFIG_IRQ             0x15     // IRQ assigned to devices
#define EVENT_TRACE_TYPE_CONFIG_PNP             0x16     // PnP device info
#define EVENT_TRACE_TYPE_CONFIG_IDECHANNEL      0x17     // Primary/Secondary IDE channel Configuration
#define EVENT_TRACE_TYPE_CONFIG_NUMANODE        0x18     // Numa configuration
#define EVENT_TRACE_TYPE_CONFIG_PLATFORM        0x19     // Platform Configuration
#define EVENT_TRACE_TYPE_CONFIG_PROCESSORGROUP  0x1A     // Processor Group Configuration
#define EVENT_TRACE_TYPE_CONFIG_PROCESSORNUMBER 0x1B     // ProcessorIndex -> ProcNumber mapping
#define EVENT_TRACE_TYPE_CONFIG_DPI             0x1C     // Display DPI Configuration
#define EVENT_TRACE_TYPE_CONFIG_CI_INFO         0x1D     // Display System Code Integrity Information
#define EVENT_TRACE_TYPE_CONFIG_MACHINEID       0x1E     // SQM Machine Id
#define EVENT_TRACE_TYPE_CONFIG_DEFRAG          0x1F     // Logical Disk Defragmenter Information
#define EVENT_TRACE_TYPE_CONFIG_MOBILEPLATFORM  0x20     // Mobile Platform Configuration
#define EVENT_TRACE_TYPE_CONFIG_DEVICEFAMILY    0x21     // Device Family Information
#define EVENT_TRACE_TYPE_CONFIG_FLIGHTID        0x22     // Flights on the machine
#define EVENT_TRACE_TYPE_CONFIG_PROCESSOR       0x23     // CentralProcessor records
#define EVENT_TRACE_TYPE_CONFIG_VIRTUALIZATION  0x24     // virtualization config info
#define EVENT_TRACE_TYPE_CONFIG_BOOT            0x25     // boot config info

//
// Event types for Optical IO subsystem
//

#define EVENT_TRACE_TYPE_OPTICAL_IO_READ        0x37
#define EVENT_TRACE_TYPE_OPTICAL_IO_WRITE       0x38
#define EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH       0x39
#define EVENT_TRACE_TYPE_OPTICAL_IO_READ_INIT   0x3a
#define EVENT_TRACE_TYPE_OPTICAL_IO_WRITE_INIT  0x3b
#define EVENT_TRACE_TYPE_OPTICAL_IO_FLUSH_INIT  0x3c

//
// Event types for Filter Manager
//

#define EVENT_TRACE_TYPE_FLT_PREOP_INIT         0x60   // Minifilter preop initiation
#define EVENT_TRACE_TYPE_FLT_POSTOP_INIT        0x61   // Minifilter postop initiation
#define EVENT_TRACE_TYPE_FLT_PREOP_COMPLETION   0x62   // Minifilter preop completion
#define EVENT_TRACE_TYPE_FLT_POSTOP_COMPLETION  0x63   // Minifilter postop completion
#define EVENT_TRACE_TYPE_FLT_PREOP_FAILURE      0x64   // Minifilter failed preop
#define EVENT_TRACE_TYPE_FLT_POSTOP_FAILURE     0x65   // Minifilter failed postop

//
// Enable flags for Kernel Events
//
#define EVENT_TRACE_FLAG_PROCESS            0x00000001  // process start & end
#define EVENT_TRACE_FLAG_THREAD             0x00000002  // thread start & end
#define EVENT_TRACE_FLAG_IMAGE_LOAD         0x00000004  // image load

#define EVENT_TRACE_FLAG_DISK_IO            0x00000100  // physical disk IO
#define EVENT_TRACE_FLAG_DISK_FILE_IO       0x00000200  // requires disk IO

#define EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS 0x00001000  // all page faults
#define EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS 0x00002000  // hard faults only

#define EVENT_TRACE_FLAG_NETWORK_TCPIP      0x00010000  // tcpip send & receive

#define EVENT_TRACE_FLAG_REGISTRY           0x00020000  // registry calls
#define EVENT_TRACE_FLAG_DBGPRINT           0x00040000  // DbgPrint(ex) Calls

//
// Enable flags for Kernel Events on Vista and above
//
#define EVENT_TRACE_FLAG_PROCESS_COUNTERS   0x00000008  // process perf counters
#define EVENT_TRACE_FLAG_CSWITCH            0x00000010  // context switches
#define EVENT_TRACE_FLAG_DPC                0x00000020  // deferred procedure calls
#define EVENT_TRACE_FLAG_INTERRUPT          0x00000040  // interrupts
#define EVENT_TRACE_FLAG_SYSTEMCALL         0x00000080  // system calls

#define EVENT_TRACE_FLAG_DISK_IO_INIT       0x00000400  // physical disk IO initiation
#define EVENT_TRACE_FLAG_ALPC               0x00100000  // ALPC traces
#define EVENT_TRACE_FLAG_SPLIT_IO           0x00200000  // split io traces (VolumeManager)

#define EVENT_TRACE_FLAG_DRIVER             0x00800000  // driver delays
#define EVENT_TRACE_FLAG_PROFILE            0x01000000  // sample based profiling
#define EVENT_TRACE_FLAG_FILE_IO            0x02000000  // file IO
#define EVENT_TRACE_FLAG_FILE_IO_INIT       0x04000000  // file IO initiation

//
// Enable flags for Kernel Events on Win7 and above
//
#define EVENT_TRACE_FLAG_DISPATCHER         0x00000800  // scheduler (ReadyThread)
#define EVENT_TRACE_FLAG_VIRTUAL_ALLOC      0x00004000  // VM operations

//
// Enable flags for Kernel Events on Win8 and above
//
#define EVENT_TRACE_FLAG_VAMAP              0x00008000  // map/unmap (excluding images)
#define EVENT_TRACE_FLAG_NO_SYSCONFIG       0x10000000  // Do not do sys config rundown

//
// Enable flags for Kernel Events on Threshold and above
//
#define EVENT_TRACE_FLAG_JOB                0x00080000  // job start & end
#define EVENT_TRACE_FLAG_DEBUG_EVENTS       0x00400000  // debugger events (break/continue/...)

//
// Pre-defined Enable flags for everybody else
//
#define EVENT_TRACE_FLAG_EXTENSION          0x80000000  // Indicates more flags
#define EVENT_TRACE_FLAG_FORWARD_WMI        0x40000000  // Can forward to WMI
#define EVENT_TRACE_FLAG_ENABLE_RESERVE     0x20000000  // Reserved

//
// Logger Mode flags
//
#define EVENT_TRACE_FILE_MODE_NONE          0x00000000  // Logfile is off
#define EVENT_TRACE_FILE_MODE_SEQUENTIAL    0x00000001  // Log sequentially
#define EVENT_TRACE_FILE_MODE_CIRCULAR      0x00000002  // Log in circular manner
#define EVENT_TRACE_FILE_MODE_APPEND        0x00000004  // Append sequential log

#define EVENT_TRACE_REAL_TIME_MODE          0x00000100  // Real time mode on
#define EVENT_TRACE_DELAY_OPEN_FILE_MODE    0x00000200  // Delay opening file
#define EVENT_TRACE_BUFFERING_MODE          0x00000400  // Buffering mode only
#define EVENT_TRACE_PRIVATE_LOGGER_MODE     0x00000800  // Process Private Logger
#define EVENT_TRACE_ADD_HEADER_MODE         0x00001000  // Add a logfile header

#define EVENT_TRACE_USE_GLOBAL_SEQUENCE     0x00004000  // Use global sequence no.
#define EVENT_TRACE_USE_LOCAL_SEQUENCE      0x00008000  // Use local sequence no.

#define EVENT_TRACE_RELOG_MODE              0x00010000  // Relogger

#define EVENT_TRACE_USE_PAGED_MEMORY        0x01000000  // Use pageable buffers

//
// Logger Mode flags on XP and above
//

#define EVENT_TRACE_FILE_MODE_NEWFILE       0x00000008  // Auto-switch log file
#define EVENT_TRACE_FILE_MODE_PREALLOCATE   0x00000020  // Pre-allocate mode

//
// Logger Mode flags on Vista and above
//

#define EVENT_TRACE_NONSTOPPABLE_MODE       0x00000040  // Session cannot be stopped (Autologger only)
#define EVENT_TRACE_SECURE_MODE             0x00000080  // Secure session
#define EVENT_TRACE_USE_KBYTES_FOR_SIZE     0x00002000  // Use KBytes as file size unit
#define EVENT_TRACE_PRIVATE_IN_PROC         0x00020000  // In process private logger

#define EVENT_TRACE_MODE_RESERVED           0x00100000  // Reserved bit, used to signal Heap/Critsec tracing

//
// Logger Mode flags on Win7 and above
//

#define EVENT_TRACE_NO_PER_PROCESSOR_BUFFERING 0x10000000  // Use this for low frequency sessions.

//
// Logger Mode flags on Win8 and above
//

#define EVENT_TRACE_SYSTEM_LOGGER_MODE      0x02000000  // Receive events from SystemTraceProvider
#define EVENT_TRACE_ADDTO_TRIAGE_DUMP       0x80000000  // Add ETW buffers to triage dumps
#define EVENT_TRACE_STOP_ON_HYBRID_SHUTDOWN 0x00400000  // Stop on hybrid shutdown
#define EVENT_TRACE_PERSIST_ON_HYBRID_SHUTDOWN 0x00800000 // Persist on hybrid shutdown

//
// Logger Mode flags on Blue and above
//

#define EVENT_TRACE_INDEPENDENT_SESSION_MODE  0x08000000  // Independent logger session

//
// Logger Mode flags on Redstone and above
//

#define EVENT_TRACE_COMPRESSED_MODE         0x04000000 // Compressed logger session.

//
// ControlTrace Codes
//

#define EVENT_TRACE_CONTROL_QUERY           0
#define EVENT_TRACE_CONTROL_STOP            1
#define EVENT_TRACE_CONTROL_UPDATE          2

//
// Flush ControlTrace Codes for XP and above
//

#define EVENT_TRACE_CONTROL_FLUSH           3       // Flushes all the buffers

#define EVENT_TRACE_CONTROL_INCREMENT_FILE  4       // Causes a session with EVENT_TRACE_FILE_MODE_NEWFILE
                                                    // to switch to the next file before the automatic 
                                                    // switching criteria is met

//
// Flags used by WMI Trace Message
// Note that the order or value of these flags should NOT be changed as they are processed
// in this order.
//

#define TRACE_MESSAGE_SEQUENCE              1  // Message should include a sequence number
#define TRACE_MESSAGE_GUID                  2  // Message includes a GUID
#define TRACE_MESSAGE_COMPONENTID           4  // Message has no GUID, Component ID instead
#define TRACE_MESSAGE_TIMESTAMP             8  // Message includes a timestamp
#define TRACE_MESSAGE_PERFORMANCE_TIMESTAMP 16 // *Obsolete* Clock type is controlled by the logger
#define TRACE_MESSAGE_SYSTEMINFO            32 // Message includes system information TID,PID

//
// Vista flags set by system to indicate provider pointer size.
//

#define TRACE_MESSAGE_POINTER32         0x0040   // Message logged by 32 bit provider
#define TRACE_MESSAGE_POINTER64         0x0080   // Message logged by 64 bit provider

#define TRACE_MESSAGE_FLAG_MASK         0xFFFF   // Only the lower 16 bits of flags are placed in the message
                                                 // those above 16 bits are reserved for local processing
//
// Maximum size allowed for a single TraceMessage message.
//
// N.B. This limit was increased from 8K to 64K in Win8.
//

#define TRACE_MESSAGE_MAXIMUM_SIZE   (64 * 1024)

//
// Flags to indicate to consumer which fields
// in the EVENT_TRACE_HEADER are valid
//

#define EVENT_TRACE_USE_PROCTIME          0x0001    // ProcessorTime field is valid
#define EVENT_TRACE_USE_NOCPUTIME         0x0002    // No Kernel/User/Processor Times

//
// TRACE_HEADER_FLAG values are used in the Flags field of EVENT_TRACE_HEADER
// structure while calling into TraceEvent API
//

#define TRACE_HEADER_FLAG_USE_TIMESTAMP     0x00000200
#define TRACE_HEADER_FLAG_TRACED_GUID       0x00020000 // denotes a trace
#define TRACE_HEADER_FLAG_LOG_WNODE         0x00040000 // request to log Wnode
#define TRACE_HEADER_FLAG_USE_GUID_PTR      0x00080000 // Guid is actually a pointer
#define TRACE_HEADER_FLAG_USE_MOF_PTR       0x00100000 // MOF data are dereferenced

typedef enum {
    EtwCompressionModeRestart = 0,
    EtwCompressionModeNoDisable = 1,
    EtwCompressionModeNoRestart = 2
} ETW_COMPRESSION_RESUMPTION_MODE;

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */

//
// Trace header for all legacy events.
//

typedef struct _EVENT_TRACE_HEADER {        // overlays WNODE_HEADER
    USHORT          Size;                   // Size of entire record
    union {
        USHORT      FieldTypeFlags;         // Indicates valid fields
        struct {
            UCHAR   HeaderType;             // Header type - internal use only
            UCHAR   MarkerFlags;            // Marker - internal use only
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    union {
        ULONG       Version;
        struct {
            UCHAR   Type;                   // event type
            UCHAR   Level;                  // trace instrumentation level
            USHORT  Version;                // version of trace record
        } Class;
    } DUMMYUNIONNAME2;
    ULONG           ThreadId;               // Thread Id
    ULONG           ProcessId;              // Process Id
    LARGE_INTEGER   TimeStamp;              // time when event happens
    union {
        GUID        Guid;                   // Guid that identifies event
        ULONGLONG   GuidPtr;                // use with WNODE_FLAG_USE_GUID_PTR
    } DUMMYUNIONNAME3;
    union {
        struct {
            ULONG   KernelTime;             // Kernel Mode CPU ticks
            ULONG   UserTime;               // User mode CPU ticks
        } DUMMYSTRUCTNAME;
        ULONG64     ProcessorTime;          // Processor Clock
        struct {
            ULONG   ClientContext;          // Reserved
            ULONG   Flags;                  // Event Flags
        } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME4;
} EVENT_TRACE_HEADER, *PEVENT_TRACE_HEADER;

//
// This header is used to trace and track transaction co-relations
//
typedef struct _EVENT_INSTANCE_HEADER {
    USHORT          Size;
    union {
        USHORT      FieldTypeFlags;     // Indicates valid fields
        struct {
            UCHAR   HeaderType;         // Header type - internal use only
            UCHAR   MarkerFlags;        // Marker - internal use only
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    union {
        ULONG       Version;
        struct {
            UCHAR   Type;
            UCHAR   Level;
            USHORT  Version;
        } Class;
    } DUMMYUNIONNAME2;
    ULONG           ThreadId;
    ULONG           ProcessId;
    LARGE_INTEGER   TimeStamp;
    ULONGLONG       RegHandle;
    ULONG           InstanceId;
    ULONG           ParentInstanceId;
    union {
        struct {
            ULONG   KernelTime;             // Kernel Mode CPU ticks
            ULONG   UserTime;               // User mode CPU ticks
        } DUMMYSTRUCTNAME;
        ULONG64     ProcessorTime;          // Processor Clock
        struct {
            ULONG   EventId;                // Event ID
            ULONG   Flags;                  // Trace header Flags
        } DUMMYSTRUCTNAME2;
    } DUMMYUNIONNAME3;
    ULONGLONG       ParentRegHandle;
} EVENT_INSTANCE_HEADER, *PEVENT_INSTANCE_HEADER;

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

//
// Following are structures and macros for use with USE_MOF_PTR
//

// Trace data types
#define ETW_NULL_TYPE_VALUE                 0
#define ETW_OBJECT_TYPE_VALUE               1
#define ETW_STRING_TYPE_VALUE               2
#define ETW_SBYTE_TYPE_VALUE                3
#define ETW_BYTE_TYPE_VALUE                 4
#define ETW_INT16_TYPE_VALUE                5
#define ETW_UINT16_TYPE_VALUE               6
#define ETW_INT32_TYPE_VALUE                7
#define ETW_UINT32_TYPE_VALUE               8
#define ETW_INT64_TYPE_VALUE                9
#define ETW_UINT64_TYPE_VALUE               10
#define ETW_CHAR_TYPE_VALUE                 11
#define ETW_SINGLE_TYPE_VALUE               12
#define ETW_DOUBLE_TYPE_VALUE               13
#define ETW_BOOLEAN_TYPE_VALUE              14
#define ETW_DECIMAL_TYPE_VALUE              15
// Extended types
#define ETW_GUID_TYPE_VALUE                 101
#define ETW_ASCIICHAR_TYPE_VALUE            102
#define ETW_ASCIISTRING_TYPE_VALUE          103
#define ETW_COUNTED_STRING_TYPE_VALUE       104
#define ETW_POINTER_TYPE_VALUE              105
#define ETW_SIZET_TYPE_VALUE                106
#define ETW_HIDDEN_TYPE_VALUE               107
#define ETW_BOOL_TYPE_VALUE                 108
#define ETW_COUNTED_ANSISTRING_TYPE_VALUE   109
#define ETW_REVERSED_COUNTED_STRING_TYPE_VALUE 110
#define ETW_REVERSED_COUNTED_ANSISTRING_TYPE_VALUE 111
#define ETW_NON_NULL_TERMINATED_STRING_TYPE_VALUE 112
#define ETW_REDUCED_ANSISTRING_TYPE_VALUE   113
#define ETW_REDUCED_STRING_TYPE_VALUE       114
#define ETW_SID_TYPE_VALUE                  115
#define ETW_VARIANT_TYPE_VALUE              116
#define ETW_PTVECTOR_TYPE_VALUE             117
#define ETW_WMITIME_TYPE_VALUE              118
#define ETW_DATETIME_TYPE_VALUE             119
#define ETW_REFRENCE_TYPE_VALUE             120


#define DEFINE_TRACE_MOF_FIELD(MOF, ptr, length, type) \
    (MOF)->DataPtr  = (ULONG64)(ULONG_PTR) ptr; \
    (MOF)->Length   = (ULONG) length; \
    (MOF)->DataType = (ULONG) type;

typedef struct _MOF_FIELD {
    ULONG64     DataPtr;    // Pointer to the field. Up to 64-bits only
    ULONG       Length;     // Length of the MOF field
    ULONG       DataType;   // Type of data
} MOF_FIELD, *PMOF_FIELD;

#if !defined(_EVNTRACE_KERNEL_MODE) || defined(_WMIKM_)

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */

//
// This is the header for every logfile. The memory for LoggerName
// and LogFileName must be contiguous adjacent to this structure
// Allows both user-mode and kernel-mode to understand the header.
//
// TRACE_LOGFILE_HEADER32 and TRACE_LOGFILE_HEADER64 structures
// are also provided to simplify cross platform decoding of the
// header event.
//

typedef struct _TRACE_LOGFILE_HEADER {
    ULONG           BufferSize;         // Logger buffer size in Kbytes
    union {
        ULONG       Version;            // Logger version
        struct {
            UCHAR   MajorVersion;
            UCHAR   MinorVersion;
            UCHAR   SubVersion;
            UCHAR   SubMinorVersion;
        } VersionDetail;
    } DUMMYUNIONNAME;
    ULONG           ProviderVersion;    // defaults to NT version
    ULONG           NumberOfProcessors; // Number of Processors
    LARGE_INTEGER   EndTime;            // Time when logger stops
    ULONG           TimerResolution;    // assumes timer is constant!!!
    ULONG           MaximumFileSize;    // Maximum in Mbytes
    ULONG           LogFileMode;        // specify logfile mode
    ULONG           BuffersWritten;     // used to file start of Circular File
    union {
        GUID LogInstanceGuid;           // For RealTime Buffer Delivery
        struct {
            ULONG   StartBuffers;       // Count of buffers written at start.
            ULONG   PointerSize;        // Size of pointer type in bits
            ULONG   EventsLost;         // Events lost during log session
            ULONG   CpuSpeedInMHz;      // Cpu Speed in MHz
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME2;
#if defined(_WMIKM_)
    PWCHAR          LoggerName;
    PWCHAR          LogFileName;
    RTL_TIME_ZONE_INFORMATION TimeZone;
#else
    LPWSTR          LoggerName;
    LPWSTR          LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
#endif
    LARGE_INTEGER   BootTime;
    LARGE_INTEGER   PerfFreq;           // Reserved
    LARGE_INTEGER   StartTime;          // Reserved
    ULONG           ReservedFlags;      // ClockType
    ULONG           BuffersLost;
} TRACE_LOGFILE_HEADER, *PTRACE_LOGFILE_HEADER;

typedef struct _TRACE_LOGFILE_HEADER32 {
    ULONG           BufferSize;         // Logger buffer size in Kbytes
    union {
        ULONG       Version;            // Logger version
        struct {
            UCHAR   MajorVersion;
            UCHAR   MinorVersion;
            UCHAR   SubVersion;
            UCHAR   SubMinorVersion;
        } VersionDetail;
    };
    ULONG           ProviderVersion;    // defaults to NT version
    ULONG           NumberOfProcessors; // Number of Processors
    LARGE_INTEGER   EndTime;            // Time when logger stops
    ULONG           TimerResolution;    // assumes timer is constant!!!
    ULONG           MaximumFileSize;    // Maximum in Mbytes
    ULONG           LogFileMode;        // specify logfile mode
    ULONG           BuffersWritten;     // used to file start of Circular File
    union {
        GUID LogInstanceGuid;           // For RealTime Buffer Delivery
        struct {
            ULONG   StartBuffers;       // Count of buffers written at start.
            ULONG   PointerSize;        // Size of pointer type in bits
            ULONG   EventsLost;         // Events lost during log session
            ULONG   CpuSpeedInMHz;      // Cpu Speed in MHz
        };
    };
#if defined(_WMIKM_)
    ULONG32         LoggerName;
    ULONG32         LogFileName;
    RTL_TIME_ZONE_INFORMATION TimeZone;
#else
    ULONG32         LoggerName;
    ULONG32         LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
#endif
    LARGE_INTEGER   BootTime;
    LARGE_INTEGER   PerfFreq;           // Reserved
    LARGE_INTEGER   StartTime;          // Reserved
    ULONG           ReservedFlags;      // ClockType
    ULONG           BuffersLost;
} TRACE_LOGFILE_HEADER32, *PTRACE_LOGFILE_HEADER32;

typedef struct _TRACE_LOGFILE_HEADER64 {
    ULONG           BufferSize;         // Logger buffer size in Kbytes
    union {
        ULONG       Version;            // Logger version
        struct {
            UCHAR   MajorVersion;
            UCHAR   MinorVersion;
            UCHAR   SubVersion;
            UCHAR   SubMinorVersion;
        } VersionDetail;
    };
    ULONG           ProviderVersion;    // defaults to NT version
    ULONG           NumberOfProcessors; // Number of Processors
    LARGE_INTEGER   EndTime;            // Time when logger stops
    ULONG           TimerResolution;    // assumes timer is constant!!!
    ULONG           MaximumFileSize;    // Maximum in Mbytes
    ULONG           LogFileMode;        // specify logfile mode
    ULONG           BuffersWritten;     // used to file start of Circular File
    union {
        GUID LogInstanceGuid;           // For RealTime Buffer Delivery
        struct {
            ULONG   StartBuffers;       // Count of buffers written at start.
            ULONG   PointerSize;        // Size of pointer type in bits
            ULONG   EventsLost;         // Events lost during log session
            ULONG   CpuSpeedInMHz;      // Cpu Speed in MHz
        };
    };
#if defined(_WMIKM_)
    ULONG64         LoggerName;
    ULONG64         LogFileName;
    RTL_TIME_ZONE_INFORMATION TimeZone;
#else
    ULONG64         LoggerName;
    ULONG64         LogFileName;
    TIME_ZONE_INFORMATION TimeZone;
#endif
    LARGE_INTEGER   BootTime;
    LARGE_INTEGER   PerfFreq;           // Reserved
    LARGE_INTEGER   StartTime;          // Reserved
    ULONG           ReservedFlags;      // ClockType
    ULONG           BuffersLost;
} TRACE_LOGFILE_HEADER64, *PTRACE_LOGFILE_HEADER64;

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#endif // !_EVNTRACE_KERNEL_MODE || _WMIKM_

//
// Instance Information to track parent child relationship of Instances.
//

typedef struct EVENT_INSTANCE_INFO {
    HANDLE      RegHandle;
    ULONG       InstanceId;
} EVENT_INSTANCE_INFO, *PEVENT_INSTANCE_INFO;

#if !defined(_EVNTRACE_KERNEL_MODE)

//
// Structures that have UNICODE and ANSI versions are defined here
//

//
// Logger configuration and running statistics. This structure is used
// by user-mode callers, such as PDH library
//

#if _MSC_VER >= 1200
#pragma warning(push)
#endif

typedef struct _EVENT_FILTER_DESCRIPTOR
               EVENT_FILTER_DESCRIPTOR, *PEVENT_FILTER_DESCRIPTOR;

#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */
#pragma warning (disable:4214) /* nonstandard extension used : bit field other than int */

typedef struct _EVENT_TRACE_PROPERTIES {
    WNODE_HEADER Wnode;
//
// data provided by caller
    ULONG BufferSize;                   // buffer size for logging (kbytes)
    ULONG MinimumBuffers;               // minimum to preallocate
    ULONG MaximumBuffers;               // maximum buffers allowed
    ULONG MaximumFileSize;              // maximum logfile size (in MBytes)
    ULONG LogFileMode;                  // sequential, circular
    ULONG FlushTimer;                   // buffer flush timer, in seconds
    ULONG EnableFlags;                  // trace enable flags
    union {
        LONG  AgeLimit;                 // unused
        LONG  FlushThreshold;           // Number of buffers to fill before flushing
    } DUMMYUNIONNAME;

// data returned to caller
    ULONG NumberOfBuffers;              // no of buffers in use
    ULONG FreeBuffers;                  // no of buffers free
    ULONG EventsLost;                   // event records lost
    ULONG BuffersWritten;               // no of buffers written to file
    ULONG LogBuffersLost;               // no of logfile write failures
    ULONG RealTimeBuffersLost;          // no of rt delivery failures
    HANDLE LoggerThreadId;              // thread id of Logger
    ULONG LogFileNameOffset;            // Offset to LogFileName
    ULONG LoggerNameOffset;             // Offset to LoggerName
} EVENT_TRACE_PROPERTIES, *PEVENT_TRACE_PROPERTIES;

typedef struct _EVENT_TRACE_PROPERTIES_V2 {
    WNODE_HEADER Wnode;                  // Always have WNODE_FLAG_VERSIONED_PROPERTIES.
    //
    // data provided by caller
    ULONG BufferSize;                    // buffer size for logging (kbytes)
    ULONG MinimumBuffers;                // minimum to preallocate
    ULONG MaximumBuffers;                // maximum buffers allowed
    ULONG MaximumFileSize;               // maximum logfile size (in MBytes)
    ULONG LogFileMode;                   // sequential, circular
    ULONG FlushTimer;                    // buffer flush timer, in seconds
    ULONG EnableFlags;                   // trace enable flags
    union {
        LONG  AgeLimit;                  // unused
        LONG  FlushThreshold;            // Number of buffers to fill before flushing
    } DUMMYUNIONNAME;

    // data returned to caller
    ULONG NumberOfBuffers;               // no of buffers in use
    ULONG FreeBuffers;                   // no of buffers free
    ULONG EventsLost;                    // event records lost
    ULONG BuffersWritten;                // no of buffers written to file
    ULONG LogBuffersLost;                // no of logfile write failures
    ULONG RealTimeBuffersLost;           // no of rt delivery failures
    HANDLE LoggerThreadId;               // thread id of Logger
    ULONG LogFileNameOffset;             // Offset to LogFileName
    ULONG LoggerNameOffset;              // Offset to LoggerName

    // V2 data
    union {
        struct {
            ULONG VersionNumber : 8;     // Should be set to 2 for this version.
        } DUMMYSTRUCTNAME;
        ULONG V2Control;
    } DUMMYUNIONNAME2;
    ULONG FilterDescCount;               // Number of filters
    PEVENT_FILTER_DESCRIPTOR FilterDesc; // Only applicable for Private Loggers
    union {
        struct {
            ULONG Wow : 1; // Logger was started by a WOW64 process (output only).
            ULONG QpcDeltaTracking : 1; // QPC delta tracking events are enabled.
            ULONG LargeMdlPages : 1; // Buffers allocated via large MDL pages.
            ULONG ExcludeKernelStack : 1; // Exclude kernel stack from stack walk.
        } DUMMYSTRUCTNAME;
        ULONG64 V2Options;
    } DUMMYUNIONNAME3;
} EVENT_TRACE_PROPERTIES_V2, *PEVENT_TRACE_PROPERTIES_V2;

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

//
// Data Provider structures
//
// Used by RegisterTraceGuids()
//
typedef struct  _TRACE_GUID_REGISTRATION {
    LPCGUID Guid;            // Guid of data block being registered or updated.
    HANDLE RegHandle;        // Guid Registration Handle is returned.
} TRACE_GUID_REGISTRATION, *PTRACE_GUID_REGISTRATION;

//
// Data consumer structures
//

#endif // !_EVNTRACE_KERNEL_MODE

typedef struct _TRACE_GUID_PROPERTIES {
    GUID    Guid;
    ULONG   GuidType;
    ULONG   LoggerId;
    ULONG   EnableLevel;
    ULONG   EnableFlags;
    BOOLEAN IsEnable;
} TRACE_GUID_PROPERTIES, *PTRACE_GUID_PROPERTIES;

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */
#ifndef ETW_BUFFER_CONTEXT_DEF
#define ETW_BUFFER_CONTEXT_DEF
typedef struct _ETW_BUFFER_CONTEXT {
    union {
        struct {
            UCHAR ProcessorNumber;
            UCHAR Alignment;
        } DUMMYSTRUCTNAME;
        USHORT ProcessorIndex;
    } DUMMYUNIONNAME;
    USHORT  LoggerId;
} ETW_BUFFER_CONTEXT, *PETW_BUFFER_CONTEXT;
#endif
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

//
// Provider Information Flags used on Vista and above.
//
#define TRACE_PROVIDER_FLAG_LEGACY     (0x00000001)
#define TRACE_PROVIDER_FLAG_PRE_ENABLE (0x00000002)

//
// Enable Information for Provider Instance
// Used on Vista and above
//
typedef struct _TRACE_ENABLE_INFO {

    ULONG       IsEnabled;
    UCHAR       Level;
    UCHAR       Reserved1;
    USHORT      LoggerId;
    ULONG       EnableProperty;
    ULONG       Reserved2;
    ULONGLONG   MatchAnyKeyword;
    ULONGLONG   MatchAllKeyword;

} TRACE_ENABLE_INFO, *PTRACE_ENABLE_INFO;

//
// Instance Information for Provider
// Used on Vista and above
//
typedef struct _TRACE_PROVIDER_INSTANCE_INFO {

    ULONG NextOffset;
    ULONG EnableCount;
    ULONG Pid;
    ULONG Flags;

} TRACE_PROVIDER_INSTANCE_INFO, *PTRACE_PROVIDER_INSTANCE_INFO;

//
// GUID Information Used on Vista and above
//
typedef struct _TRACE_GUID_INFO {
    ULONG InstanceCount;
    ULONG Reserved;
} TRACE_GUID_INFO, *PTRACE_GUID_INFO;

typedef struct _PROFILE_SOURCE_INFO {
    ULONG NextEntryOffset;
    ULONG Source;
    ULONG MinInterval;
    ULONG MaxInterval;
    ULONG64 Reserved;
    WCHAR Description[ANYSIZE_ARRAY];
} PROFILE_SOURCE_INFO, *PPROFILE_SOURCE_INFO;

//
// An EVENT_TRACE consists of a fixed header (EVENT_TRACE_HEADER) and
// optionally a variable portion pointed to by MofData. The datablock
// layout of the variable portion is unknown to the Logger and must
// be obtained from WBEM CIMOM database.
//

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */
typedef struct _EVENT_TRACE {
    EVENT_TRACE_HEADER      Header;             // Event trace header
    ULONG                   InstanceId;         // Instance Id of this event
    ULONG                   ParentInstanceId;   // Parent Instance Id.
    GUID                    ParentGuid;         // Parent Guid;
    PVOID                   MofData;            // Pointer to Variable Data
    ULONG                   MofLength;          // Variable Datablock Length
    union {
        ULONG               ClientContext;
        ETW_BUFFER_CONTEXT  BufferContext;
    } DUMMYUNIONNAME;
} EVENT_TRACE, *PEVENT_TRACE;
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#define EVENT_CONTROL_CODE_DISABLE_PROVIDER 0
#define EVENT_CONTROL_CODE_ENABLE_PROVIDER  1
#define EVENT_CONTROL_CODE_CAPTURE_STATE    2

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#if !defined(_EVNTRACE_KERNEL_MODE)

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

typedef struct _EVENT_RECORD
                EVENT_RECORD, *PEVENT_RECORD;

typedef struct _EVENT_TRACE_LOGFILEW
                EVENT_TRACE_LOGFILEW, *PEVENT_TRACE_LOGFILEW;

typedef struct _EVENT_TRACE_LOGFILEA
                EVENT_TRACE_LOGFILEA, *PEVENT_TRACE_LOGFILEA;

typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKW)
                (PEVENT_TRACE_LOGFILEW Logfile);

typedef ULONG (WINAPI * PEVENT_TRACE_BUFFER_CALLBACKA)
                (PEVENT_TRACE_LOGFILEA Logfile);

typedef VOID (WINAPI *PEVENT_CALLBACK)( PEVENT_TRACE pEvent );

typedef VOID (WINAPI *PEVENT_RECORD_CALLBACK) (PEVENT_RECORD EventRecord);

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Prototype for service request callback. Data providers register with WMI
// by passing a service request callback function that is called for all
// wmi requests.

typedef ULONG (
#ifndef MIDL_PASS
WINAPI
#endif
*WMIDPREQUEST)(
    _In_ WMIDPREQUESTCODE RequestCode,
    _In_ PVOID RequestContext,
    _Inout_ ULONG *BufferSize,
    _Inout_ PVOID Buffer
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning (disable:4201) /* nonstandard extension used : nameless struct/union */

struct _EVENT_TRACE_LOGFILEW {
    LPWSTR                  LogFileName;      // Logfile Name
    LPWSTR                  LoggerName;       // LoggerName
    LONGLONG                CurrentTime;      // timestamp of last event
    ULONG                   BuffersRead;      // buffers read to date
    union {
        // Mode of the logfile
        ULONG               LogFileMode;
        // Processing flags used on Vista and above
        ULONG               ProcessTraceMode;
    } DUMMYUNIONNAME;
    EVENT_TRACE             CurrentEvent;     // Current Event from this stream.
    TRACE_LOGFILE_HEADER    LogfileHeader;    // logfile header structure
    PEVENT_TRACE_BUFFER_CALLBACKW             // callback before each buffer
                            BufferCallback;   // is read
    //
    // following variables are filled for BufferCallback.
    //
    ULONG                   BufferSize;
    ULONG                   Filled;
    ULONG                   EventsLost;
    //
    // following needs to be propagated to each buffer
    //
    union {
        // Callback with EVENT_TRACE
        PEVENT_CALLBACK         EventCallback;
        // Callback with EVENT_RECORD on Vista and above
        PEVENT_RECORD_CALLBACK  EventRecordCallback;
    } DUMMYUNIONNAME2;

    ULONG                   IsKernelTrace;    // TRUE for kernel logfile

    PVOID                   Context;          // reserved for internal use
};

struct _EVENT_TRACE_LOGFILEA {
    LPSTR                   LogFileName;      // Logfile Name
    LPSTR                   LoggerName;       // LoggerName
    LONGLONG                CurrentTime;      // timestamp of last event
    ULONG                   BuffersRead;      // buffers read to date
    union {
        ULONG               LogFileMode;      // Mode of the logfile
        ULONG               ProcessTraceMode; // Processing flags
    } DUMMYUNIONNAME;
    EVENT_TRACE             CurrentEvent;     // Current Event from this stream
    TRACE_LOGFILE_HEADER    LogfileHeader;    // logfile header structure
    PEVENT_TRACE_BUFFER_CALLBACKA             // callback before each buffer
                            BufferCallback;   // is read

    //
    // following variables are filled for BufferCallback.
    //
    ULONG                   BufferSize;
    ULONG                   Filled;
    ULONG                   EventsLost;
    //
    // following needs to be propagated to each buffer
    //
    union {
        PEVENT_CALLBACK         EventCallback;  // callback for every event
        PEVENT_RECORD_CALLBACK  EventRecordCallback;
    } DUMMYUNIONNAME2;


    ULONG                   IsKernelTrace;  // TRUE for kernel logfile

    PVOID                   Context;        // reserved for internal use
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


//
// Define generic structures
//

#if defined(_UNICODE) || defined(UNICODE)

#define PEVENT_TRACE_BUFFER_CALLBACK    PEVENT_TRACE_BUFFER_CALLBACKW
#define EVENT_TRACE_LOGFILE             EVENT_TRACE_LOGFILEW
#define PEVENT_TRACE_LOGFILE            PEVENT_TRACE_LOGFILEW
#define KERNEL_LOGGER_NAME              KERNEL_LOGGER_NAMEW
#define GLOBAL_LOGGER_NAME              GLOBAL_LOGGER_NAMEW
#define EVENT_LOGGER_NAME               EVENT_LOGGER_NAMEW

#else

#define PEVENT_TRACE_BUFFER_CALLBACK    PEVENT_TRACE_BUFFER_CALLBACKA
#define EVENT_TRACE_LOGFILE             EVENT_TRACE_LOGFILEA
#define PEVENT_TRACE_LOGFILE            PEVENT_TRACE_LOGFILEA
#define KERNEL_LOGGER_NAME              KERNEL_LOGGER_NAMEA
#define GLOBAL_LOGGER_NAME              GLOBAL_LOGGER_NAMEA
#define EVENT_LOGGER_NAME               EVENT_LOGGER_NAMEA

#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _APISET_EVENTING

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Logger control APIs
//

//
// Use the routine below to start an event trace session
//

// ULONG
// StartTrace(
//      _Out_ PTRACEHANDLE TraceHandle,
//      _In_ LPTSTR InstanceName,
//      _Inout_ PEVENT_TRACE_PROPERTIES Properties
//      );


 EXTERN_C
ULONG
WMIAPI
StartTraceW (
    _Out_ PTRACEHANDLE TraceHandle,
    _In_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
StartTraceA (
    _Out_ PTRACEHANDLE TraceHandle,
    _In_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Use the routine below to stop an event trace session
//

//
// ULONG
// StopTrace(
//      _In_ TRACEHANDLE TraceHandle,
//      _In_opt_ LPTSTR InstanceName,
//      _Inout_ PEVENT_TRACE_PROPERTIES Properties
//      );

EXTERN_C
ULONG
WMIAPI
StopTraceW (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
StopTraceA (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Use the routine below to query the properties of an event trace session
//

// ULONG
// QueryTrace(
//      _In_ TRACEHANDLE TraceHandle,
//      _In_opt_ LPTSTR InstanceName,
//      _Inout_ PEVENT_TRACE_PROPERTIES Properties
//      );

EXTERN_C
ULONG
WMIAPI
QueryTraceW (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
QueryTraceA (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

//
// Use the routine below to update certain properties of an event trace session
//

// ULONG
// UpdateTrace(
//      _In_ PTRACEHANDLE TraceHandle,
//      _In_opt_ LPTSTR InstanceName,
//      _Inout_ PEVENT_TRACE_PROPERTIES Properties
//      );

EXTERN_C
ULONG
WMIAPI
UpdateTraceW (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

EXTERN_C
ULONG
WMIAPI
UpdateTraceA (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );

//
// Use the routine below to request that all active buffers an event trace
// session be "flushed", or written out.
//

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

// ULONG
// FlushTrace(
//      _In_ TRACEHANDLE TraceHandle,
//      _In_opt_ LPTSTR InstanceName,
//      _Inout_ PEVENT_TRACE_PROPERTIES Properties
//      );

#if (WINVER >= _WIN32_WINNT_WINXP)
EXTERN_C
ULONG
WMIAPI
FlushTraceW (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (WINVER >= _WIN32_WINNT_WINXP)
EXTERN_C
ULONG
WMIAPI
FlushTraceA (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Generic trace control routine
//
EXTERN_C
ULONG
WMIAPI
ControlTraceW (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCWSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties,
    _In_ ULONG ControlCode
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
ControlTraceA (
    _In_ TRACEHANDLE TraceHandle,
    _In_opt_ LPCSTR InstanceName,
    _Inout_ PEVENT_TRACE_PROPERTIES Properties,
    _In_ ULONG ControlCode
    );

//
// ULONG
// QueryAllTraces(
//  _Out_writes_(PropertyArrayCount) PEVENT_TRACE_PROPERTIES *PropertyArray,
//  _In_ ULONG PropertyArrayCount,
//  _Out_ PULONG LoggerCount
//  );
//
EXTERN_C
ULONG
WMIAPI
QueryAllTracesW (
    _Out_writes_(PropertyArrayCount) PEVENT_TRACE_PROPERTIES *PropertyArray,
    _In_  ULONG PropertyArrayCount,
    _Out_ PULONG LoggerCount
    );

EXTERN_C
ULONG
WMIAPI
QueryAllTracesA (
    _Out_writes_(PropertyArrayCount) PEVENT_TRACE_PROPERTIES *PropertyArray,
    _In_  ULONG PropertyArrayCount,
    _Out_ PULONG LoggerCount
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Data Provider Enable APIs
//

EXTERN_C
ULONG
WMIAPI
EnableTrace (
    _In_ ULONG Enable,
    _In_ ULONG EnableFlag,
    _In_ ULONG EnableLevel,
    _In_ LPCGUID ControlGuid,
    _In_ TRACEHANDLE TraceHandle
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _APISET_EVENTING

#ifndef _APISET_EVENTING

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (WINVER >= _WIN32_WINNT_VISTA)
EXTERN_C
ULONG
WMIAPI
EnableTraceEx (
    _In_ LPCGUID ProviderId,
    _In_opt_ LPCGUID SourceId,
    _In_ TRACEHANDLE TraceHandle,
    _In_ ULONG IsEnabled,
    _In_ UCHAR Level,
    _In_ ULONGLONG MatchAnyKeyword,
    _In_ ULONGLONG MatchAllKeyword,
    _In_ ULONG EnableProperty,
    _In_opt_ PEVENT_FILTER_DESCRIPTOR EnableFilterDesc
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _APISET_EVENTING

#define ENABLE_TRACE_PARAMETERS_VERSION      1
#define ENABLE_TRACE_PARAMETERS_VERSION_2    2

typedef struct _ENABLE_TRACE_PARAMETERS_V1 {
    ULONG                    Version;
    ULONG                    EnableProperty;
    ULONG                    ControlFlags;
    GUID                     SourceId;
    PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
} ENABLE_TRACE_PARAMETERS_V1, *PENABLE_TRACE_PARAMETERS_V1;

typedef struct _ENABLE_TRACE_PARAMETERS {
    ULONG                    Version;
    ULONG                    EnableProperty;
    ULONG                    ControlFlags;
    GUID                     SourceId;
    PEVENT_FILTER_DESCRIPTOR EnableFilterDesc;
    ULONG                    FilterDescCount;
} ENABLE_TRACE_PARAMETERS, *PENABLE_TRACE_PARAMETERS;

#ifndef _APISET_EVENTING

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (WINVER >= _WIN32_WINNT_WIN7)
EXTERN_C
ULONG
WMIAPI
EnableTraceEx2 (
    _In_ TRACEHANDLE TraceHandle,
    _In_ LPCGUID ProviderId,
    _In_ ULONG ControlCode,
    _In_ UCHAR Level,
    _In_ ULONGLONG MatchAnyKeyword,
    _In_ ULONGLONG MatchAllKeyword,
    _In_ ULONG Timeout,
    _In_opt_ PENABLE_TRACE_PARAMETERS EnableParameters
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _APISET_EVENTING

//
// TRACE_QUERY_INFO_CLASS/TRACE_INFO_CLASS
// This enumeration contains values that are passed to one or more of the
// ETW query/set APIs: EnumerateTraceGuidsEx, TraceSetInformation, TraceQueryInformation.
//

typedef enum _TRACE_QUERY_INFO_CLASS {
    //
    // TraceGuidQueryList:
    // - EnumerateTraceGuidsEx.
    //      Returns a list of provider GUIDs that are currently registered with the kernel.
    //      Note: This is not the same thing as having an installed manifest.
    //
    //      Input Format: None.
    //      Output Format: An array of GUIDs.
    //
    TraceGuidQueryList = 0,

    //
    // TraceGuidQueryList:
    // - EnumerateTraceGuidsEx.
    //      Returns the current registration and enablement information for the input GUID.
    //
    //      Input Format: GUID
    //      Output Format: TRACE_GUID_INFO followed by TRACE_GUID_INFO.InstanceCount
    //                     TRACE_PROVIDER_INSTANCE_INFO structs, each bundled with
    //                     TRACE_PROVIDER_INSTANCE_INFO.EnableCount TRACE_ENABLE_INFO.
    //                For example, a GUID with two provider registrations, the first enabled
    //                  by two loggers and the second by three loggers would look like:
    //                  {
    //                      TRACE_GUID_INFO;  // Where InstanceCount = 2
    //                      TRACE_PROVIDER_INSTANCE_INFO; // Where EnableCount = 2
    //                      TRACE_ENABLE_INFO;
    //                      TRACE_ENABLE_INFO;
    //                      TRACE_PROVIDER_INSTANCE_INFO; // Where EnableCount = 3
    //                      TRACE_ENABLE_INFO;
    //                      TRACE_ENABLE_INFO;
    //                      TRACE_ENABLE_INFO;
    //                  }
    //
    TraceGuidQueryInfo = 1,

    //
    // TraceGuidQueryProcess:
    // - EnumerateTraceGuidsEx.
    //      Returns a list of provider GUIDs that are registered in the current process.
    //      Note: This is not the same thing as having an installed manifest.
    //
    //      Input Format: None.
    //      Output Format: An array of GUIDs.
    //
    TraceGuidQueryProcess = 2,

    //
    // TraceStackTracingInfo:
    // - TraceSetInformation.
    //      Turns on stack trace collection for the specified kernel events for the specified logger.
    //      It also turns off stack tracing for all kernel events not on this list, regardless of prior status.
    //
    //      Input Format: An array of CLASSIC_EVENT_ID structs.
    //
    TraceStackTracingInfo = 3,

    //
    // TraceSystemTraceEnableFlagsInfo:
    // - TraceSetInformation
    //      Sets the Group Mask state for the specified logging session.
    //
    //      Input Format: PERFINFO_GROUPMASK
    //
    // - TraceQueryInformation
    //      Queries the current Group Mask state for the specified logging session.
    //
    //      Return Format: PERFINFO_GROUPMASK
    //
    TraceSystemTraceEnableFlagsInfo = 4,

    //
    // TraceSampledProfileIntervalInfo:
    // - TraceSetInformation
    //      Sets the Sample Profile interval for the system.
    //      Expects NULL SessionHandle parameter.
    //
    //      Input Format: TRACE_PROFILE_INTERVAL
    //
    // - TraceQueryInformation
    //      Queries the current Sample Profile Interval for the system.
    //      Expects NULL SessionHandle parameter.
    //
    //      Output Format: TRACE_PROFILE_INTERVAL
    //
    TraceSampledProfileIntervalInfo = 5,

    //
    // TraceProfileSourceConfigInfo:
    // - TraceSetInformation
    //      Sets a list of sources to be used for PMC Profiling system-wide.
    //      Expects NULL SessionHandle parameter.
    //
    //      Input Format: An array of ULONGs specifying the IDs of the sources.
    //
    TraceProfileSourceConfigInfo = 6,

    //
    // TraceProfileSourceListInfo:
    // - TraceQueryInformation
    //      Queries the list of PMC Profiling sources available on the system.
    //      Expects NULL SessionHandle parameter.
    //
    //      Output Format: An array of PROFILE_SOURCE_INFO structs.
    //
    TraceProfileSourceListInfo = 7,

    //
    // TracePmcEventListInfo:
    // - TraceSetInformation
    //      Updates the list of kernel events for which PMC counters will be collected
    //      for the specified logger.  This can only be set once per logger and cannot
    //      be updated.
    //      The counters collected are specified by
    //      TraceSetInformation(TracePmcCounterListInfo, ...) described below.
    //
    //      Input Format: An array of CLASSIC_EVENT_ID structs.
    //
    TracePmcEventListInfo = 8,

    //
    // TracePmcCounterListInfo:
    // - TraceSetInformation
    //      Sets the list of PMC counters to be collected on system events.
    //      This can only be set once per logger and cannot be updated.
    //      The specified counters will be collected on the events specified by
    //      TraceSetInformation(TracePmcEventListInfo, ...) described above.
    //
    //      Input Format: An array of ULONGs.
    //
    TracePmcCounterListInfo = 9,

    //
    // TraceSetDisallowList:
    // - TraceSetInformation
    //      Sets a list of provider GUIDs that should not be enabled via
    //      Provider Groups on the specified logging session.
    //
    //      Input Format: An array of GUIDs.
    //
    TraceSetDisallowList = 10,

    //
    // TraceVersionInfo:
    // - TraceQueryInformation
    //      Queries the version number of the trace processing code.
    //
    //      Output Format: TRACE_VERSION_INFO
    //
    TraceVersionInfo = 11,

    //
    // TraceGroupQueryList:
    // - EnumerateTraceGuidsEx.
    //      Returns a list of Group GUIDs that are currently known to the kernel.
    //
    //      Input Format: None.
    //      Output Format: An array of GUIDs.
    //
    TraceGroupQueryList = 12,

    //
    // TraceGroupQueryInfo:
    // - EnumerateTraceGuidsEx.
    //      Returns the current enablement information and list of member providers
    //      for the input Group GUID.
    //
    //      Input Format: GUID
    //      Output Format:  a) ULONG - Length of the following TRACE_ENABLE_INFO array.
    //                      b) Array of TRACE_ENABLE_INFO. Size of the array is inferred from (a)
    //                      c) ULONG - Count of the Number of Unique Providers that belong to this Group
    //                      d) Array of GUID - Size of the array is specified by (c)
    //
    //                  PseudoStructure -
    //                      struct TRACE_GROUP_INFO {
    //                          ULONG TraceEnableInfoSize;
    //                          TRACE_ENABLE_INFO TraceEnableInfos[TraceEnableInfoSize];
    //                          ULONG GuidArraySize;
    //                          GUID UniqueProviders[GuidArraySize];
    //                      }
    //
    TraceGroupQueryInfo = 13,

    //
    // TraceDisallowListQuery:
    // - TraceQueryInformation
    //      Queries the list of provider GUIDs that should not be enabled via
    //      Provider Groups on the specified logging session.
    //
    //      Output Format: An array of GUIDs.
    //
    TraceDisallowListQuery = 14,

    TraceInfoReserved15 = 15,

    //
    // TracePeriodicCaptureStateListInfo:
    // - TraceSetInformation
    //      Sets the list of providers for which capture stat should be collected
    //      at periodic time intervals for the specified logging session.
    //      If a NULL input buffer is specified, then the current periodic capture state
    //      settings are cleared.
    //
    //      Input Format: TRACE_PERIODIC_CAPTURE_STATE_INFO followed by an array of ProviderCount
    //                      Provider GUIDs. Or a NULL Buffer.
    //
    TracePeriodicCaptureStateListInfo = 16,

    //
    // TracePeriodicCaptureStatInfo:
    // - TraceQueryInformation
    //      Queries the limits of periodic capture settings on this system, including
    //      the minimum time frequency and the maximum number of providers that can be
    //      enabled for periodic capture state.
    //
    //      Output Format: TRACE_PERIODIC_CAPTURE_STATE_INFO
    //
    TracePeriodicCaptureStateInfo = 17,

    //
    // TraceProviderBinaryTracking:
    // - TraceSetInformation
    //      Instructs ETW to begin tracking binaries for all providers that are enabled
    //      to the session. The tracking applies retroactively for providers that were
    //      enabled to the session prior to the call, as well as for all future providers
    //      that are enabled to the session.
    //
    //      ETW fabricates tracking events for these tracked providers that contain a
    //      mapping between provider GUID(s). ETW also fabricates the file path that describes
    //      where the registered provider is located on disk. If the session is in realtime,
    //      the events are provided live in the realtime buffers. If the session is file-based
    //      (i.e. trace is saved to an .etl file), the events are aggregated and written to the
    //      file header; they will be among some of the first events the ETW runtime provides
    //      when the .etl file is played back.
    //
    //      The binary tracking events will come from the EventTraceGuid provider, with an opcode
    //      of WMI_LOG_TYPE_BINARY_PATH.
    //
    //      Input Format: BOOLEAN (The 1-byte type, rather than the 4-byte BOOL.)
    //                    True to turn tracking on. False to turn tracking off.
    //
    TraceProviderBinaryTracking = 18,

    //
    // TraceMaxLoggersQuery:
    // - TraceQueryInformation
    //      Queries the maximum number of system-wide loggers that can be running at a time
    //      on this system.
    //
    //      Output Format: ULONG
    //
    TraceMaxLoggersQuery = 19,

    //
    // TraceLbrConfigurationInfo:
    // - TraceSetInformation
    //      Sets a bitfield of configuration options for Last Branch Record tracing.
    //
    //      Input Format: ULONG
    //
    TraceLbrConfigurationInfo = 20,

    //
    // TraceLbrEventListInfo:
    // - TraceSetInformation
    //      Provides a list of kernel events to collect Last Branch Records on.
    //      The events are specified by their HookIds.
    //
    //      Input Format: An array of ULONGs
    //
    TraceLbrEventListInfo = 21,

    //
    // TraceMaxPmcCounterQuery:
    // - TraceQueryInformation
    //      Queries the maximum number of PMC counters supported on this platform
    //
    //      Output Format: ULONG
    //
    TraceMaxPmcCounterQuery = 22,
    MaxTraceSetInfoClass
} TRACE_QUERY_INFO_CLASS, TRACE_INFO_CLASS;

#ifndef _APISET_EVENTING

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (WINVER >= _WIN32_WINNT_VISTA)
EXTERN_C
ULONG
WMIAPI
EnumerateTraceGuidsEx (
    _In_ TRACE_QUERY_INFO_CLASS TraceQueryInfoClass,
    _In_reads_bytes_opt_(InBufferSize) PVOID InBuffer,
    _In_ ULONG InBufferSize,
    _Out_writes_bytes_opt_(OutBufferSize) PVOID OutBuffer,
    _In_ ULONG OutBufferSize,
    _Out_ PULONG ReturnLength
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _APISET_EVENTING

typedef struct _CLASSIC_EVENT_ID {
    GUID  EventGuid;
    UCHAR Type;
    UCHAR Reserved[7];
} CLASSIC_EVENT_ID, *PCLASSIC_EVENT_ID;

typedef struct _TRACE_PROFILE_INTERVAL {
    ULONG Source;
    ULONG Interval;
} TRACE_PROFILE_INTERVAL, *PTRACE_PROFILE_INTERVAL;

typedef struct _TRACE_VERSION_INFO {
    UINT EtwTraceProcessingVersion;
    UINT Reserved;
} TRACE_VERSION_INFO, *PTRACE_VERSION_INFO;

typedef struct _TRACE_PERIODIC_CAPTURE_STATE_INFO {
    ULONG CaptureStateFrequencyInSeconds;
    USHORT ProviderCount;
    USHORT Reserved;
} TRACE_PERIODIC_CAPTURE_STATE_INFO, *PTRACE_PERIODIC_CAPTURE_STATE_INFO;

#ifndef _APISET_EVENTING

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (WINVER >= _WIN32_WINNT_WIN7)
EXTERN_C
ULONG
WMIAPI
TraceSetInformation (
    _In_ TRACEHANDLE SessionHandle,
    _In_ TRACE_INFO_CLASS InformationClass,
    _In_reads_bytes_(InformationLength) PVOID TraceInformation,
    _In_ ULONG InformationLength
    );
#endif

#if (WINVER >= _WIN32_WINNT_WIN8)
EXTERN_C
ULONG
WMIAPI
TraceQueryInformation (
    _In_ TRACEHANDLE SessionHandle,
    _In_ TRACE_INFO_CLASS InformationClass,
    _Out_writes_bytes_(InformationLength) PVOID TraceInformation,
    _In_ ULONG InformationLength,
    _Out_opt_ PULONG ReturnLength
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

//
// Data Provider APIs
//

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

EXTERN_C
ULONG
WMIAPI
CreateTraceInstanceId (
    _In_ HANDLE RegHandle,
    _Inout_ PEVENT_INSTANCE_INFO InstInfo
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Use the routine below to generate and record an event trace
//

EXTERN_C
ULONG
WMIAPI
TraceEvent (
    _In_ TRACEHANDLE TraceHandle,
    _In_ PEVENT_TRACE_HEADER EventTrace
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

EXTERN_C
ULONG
WMIAPI
TraceEventInstance (
    _In_ TRACEHANDLE TraceHandle,
    _In_ PEVENT_INSTANCE_HEADER EventTrace,
    _In_ PEVENT_INSTANCE_INFO InstInfo,
    _In_opt_ PEVENT_INSTANCE_INFO ParentInstInfo
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

//
// Use the routine below to register a guid for tracing.
//

//
// ULONG
// RegisterTraceGuids(
//  _In_ WMIDPREQUEST RequestAddress,
//  _In_opt_ PVOID RequestContext,
//  _In_ LPCGUID ControlGuid,
//  _In_ ULONG GuidCount,
//  _In_reads_opt_(GuidCount) PTRACE_GUID_REGISTRATION TraceGuidReg,
//  _In_opt_ LPCTSTR MofImagePath,
//  _In_opt_ LPCTSTR MofResourceName,
//  _Out_ PTRACEHANDLE RegistrationHandle
//  );
//

EXTERN_C
ULONG
WMIAPI
RegisterTraceGuidsW (
    _In_ WMIDPREQUEST RequestAddress,
    _In_opt_ PVOID RequestContext,
    _In_ LPCGUID ControlGuid,
    _In_ ULONG GuidCount,
    _In_reads_opt_(GuidCount) PTRACE_GUID_REGISTRATION TraceGuidReg,
    _In_opt_ LPCWSTR MofImagePath,
    _In_opt_ LPCWSTR MofResourceName,
    _Out_ PTRACEHANDLE RegistrationHandle
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
RegisterTraceGuidsA (
    _In_ WMIDPREQUEST RequestAddress,
    _In_opt_ PVOID RequestContext,
    _In_ LPCGUID ControlGuid,
    _In_ ULONG GuidCount,
    _In_reads_opt_(GuidCount) PTRACE_GUID_REGISTRATION TraceGuidReg,
    _In_opt_ LPCSTR MofImagePath,
    _In_opt_ LPCSTR MofResourceName,
    _Out_ PTRACEHANDLE RegistrationHandle
    );

#if (WINVER >= _WIN32_WINNT_WINXP)
EXTERN_C
ULONG
WMIAPI
EnumerateTraceGuids (
    _Inout_updates_(PropertyArrayCount) PTRACE_GUID_PROPERTIES *GuidPropertiesArray,
    _In_ ULONG PropertyArrayCount,
    _Out_ PULONG GuidCount
    );
#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
WMIAPI
UnregisterTraceGuids (
    _In_ TRACEHANDLE RegistrationHandle
    );

EXTERN_C
TRACEHANDLE
WMIAPI
GetTraceLoggerHandle (
    _In_ PVOID Buffer
    );

EXTERN_C
UCHAR
WMIAPI
GetTraceEnableLevel (
    _In_ TRACEHANDLE TraceHandle
    );

EXTERN_C
ULONG
WMIAPI
GetTraceEnableFlags (
    _In_ TRACEHANDLE TraceHandle
    );

//
// Data Consumer APIs and structures start here
//

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

//
// TRACEHANDLE
// OpenTrace(
//  _Inout_ PEVENT_TRACE_LOGFILE Logfile
//  );
//

EXTERN_C
ETW_APP_DECLSPEC_DEPRECATED
TRACEHANDLE
WMIAPI
OpenTraceW (
    _Inout_ PEVENT_TRACE_LOGFILEW Logfile
    );

EXTERN_C
ETW_APP_DECLSPEC_DEPRECATED
ULONG
WMIAPI
ProcessTrace (
    _In_reads_(HandleCount) PTRACEHANDLE HandleArray,
    _In_ ULONG HandleCount,
    _In_opt_ LPFILETIME StartTime,
    _In_opt_ LPFILETIME EndTime
    );

EXTERN_C
ETW_APP_DECLSPEC_DEPRECATED
ULONG
WMIAPI
CloseTrace (
    _In_ TRACEHANDLE TraceHandle
    );

//
// Structures and enums for QueryTraceProcessingHandle
//

typedef enum _ETW_PROCESS_HANDLE_INFO_TYPE {
    EtwQueryPartitionInformation = 1,
    EtwQueryPartitionInformationV2 = 2,
    EtwQueryLastDroppedTimes = 3,
    EtwQueryProcessHandleInfoMax
} ETW_PROCESS_HANDLE_INFO_TYPE;

typedef struct _ETW_TRACE_PARTITION_INFORMATION {
    GUID PartitionId;
    GUID ParentId;
    LONG64 QpcOffsetFromRoot;
    ULONG PartitionType;
} ETW_TRACE_PARTITION_INFORMATION, *PETW_TRACE_PARTITION_INFORMATION;

typedef struct _ETW_TRACE_PARTITION_INFORMATION_V2 {
    LONG64 QpcOffsetFromRoot;
    ULONG PartitionType;
    PWSTR PartitionId;
    PWSTR ParentId;
} ETW_TRACE_PARTITION_INFORMATION_V2, *PETW_TRACE_PARTITION_INFORMATION_V2;


EXTERN_C
ETW_APP_DECLSPEC_DEPRECATED
ULONG
WMIAPI
QueryTraceProcessingHandle (
    _In_ TRACEHANDLE ProcessingHandle,
    _In_ ETW_PROCESS_HANDLE_INFO_TYPE InformationClass,
    _In_opt_ PVOID InBuffer,
    _In_ ULONG InBufferSize,
    _Out_opt_ PVOID OutBuffer,
    _In_ ULONG OutBufferSize,
    _Inout_ PULONG ReturnLength
    );

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

//
// Data Consumer APIs and structures start here
//

//
// TRACEHANDLE
// OpenTrace(
//  _Inout_ PEVENT_TRACE_LOGFILE Logfile
//  );
//

EXTERN_C
TRACEHANDLE
WMIAPI
OpenTraceA (
    _Inout_ PEVENT_TRACE_LOGFILEA Logfile
    );

EXTERN_C
ULONG
WMIAPI
SetTraceCallback (
    _In_ LPCGUID pGuid,
    _In_ PEVENT_CALLBACK EventCallback
    );

EXTERN_C
ULONG
WMIAPI
RemoveTraceCallback (
    _In_ LPCGUID pGuid
    );

//
// The routines for tracing Messages follow
//

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
__cdecl
TraceMessage (
    _In_ TRACEHANDLE LoggerHandle,
    _In_ ULONG MessageFlags,
    _In_ LPCGUID MessageGuid,
    _In_ USHORT MessageNumber,
    ...
);

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

EXTERN_C
ULONG
TraceMessageVa (
    _In_ TRACEHANDLE LoggerHandle,
    _In_ ULONG MessageFlags,
    _In_ LPCGUID MessageGuid,
    _In_ USHORT MessageNumber,
    _In_ va_list MessageArgList
);

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _APISET_EVENTING

#ifdef __cplusplus
}       // extern "C"
#endif

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define INVALID_PROCESSTRACE_HANDLE ((TRACEHANDLE)INVALID_HANDLE_VALUE)

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#ifndef _APISET_EVENTING

//
//
// Define the encoding independent routines
//

#if defined(UNICODE) || defined(_UNICODE)

#pragma region Application Family or OneCore Family or GameCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#define RegisterTraceGuids      RegisterTraceGuidsW
#define StartTrace              StartTraceW
#define ControlTrace            ControlTraceW
#if defined(__TRACE_W2K_COMPATIBLE)
#define StopTrace(a,b,c)        ControlTraceW((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a,b,c)       ControlTraceW((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c)      ControlTraceW((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace               StopTraceW
#define QueryTrace              QueryTraceW
#define UpdateTrace             UpdateTraceW
#endif
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define FlushTrace              FlushTraceW
#endif // NTDDI_VERSION >= NTDDI_WINXP
#define QueryAllTraces          QueryAllTracesW
#define OpenTrace               OpenTraceW

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP| WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#else

#pragma region Desktop Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)

#define RegisterTraceGuids      RegisterTraceGuidsA
#define StartTrace              StartTraceA
#define ControlTrace            ControlTraceA
#if defined(__TRACE_W2K_COMPATIBLE)
#define StopTrace(a,b,c)        ControlTraceA((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a,b,c)       ControlTraceA((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c)      ControlTraceA((a),(b),(c), \
                                        EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace               StopTraceA
#define QueryTrace              QueryTraceA
#define UpdateTrace             UpdateTraceA
#endif
#if (NTDDI_VERSION >= NTDDI_WINXP)
#define FlushTrace              FlushTraceA
#endif // NTDDI_VERSION >= NTDDI_WINXP
#define QueryAllTraces          QueryAllTracesA
#define OpenTrace               OpenTraceA

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) */
#pragma endregion

#endif  // UNICODE

#endif // _APISET_EVENTING

#endif // !_EVNTRACE_KERNEL_MODE

#endif // WINNT

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#endif /* _EVNTRACE_ */
