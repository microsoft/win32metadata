/********************************************************************************
*                                                                               *
* rtlsupportapi.h -- ApiSet Contract for api-ms-win-core-rtlsupport-l1          *
*                                                                               *
* Copyright (c) Microsoft Corporation. All rights reserved.                     *
*                                                                               *
********************************************************************************/

#ifdef _MSC_VER
#pragma once
#endif // _MSC_VER

#ifndef _APISETRTLSUPPORT_
#define _APISETRTLSUPPORT_

// begin_winnt begin_wdm
#include <apiset.h>
// end_winnt end_wdm

#include <apisetcconv.h>


#include <winapifamily.h>

#if _MSC_VER >= 1200
#pragma warning(push)
#pragma warning(disable:4668) // #if not_defined treated as #if 0
#endif

#ifdef __cplusplus
extern "C" {
#endif

// begin_winnt

//
// prototypes
//

// begin_ntifs

#pragma region Application or OneCore or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (NTDDI_VERSION > NTDDI_WINXP)

NTSYSAPI
_Success_(return != 0)
USHORT
NTAPI
RtlCaptureStackBackTrace(
    _In_ ULONG FramesToSkip,
    _In_ ULONG FramesToCapture,
    _Out_writes_to_(FramesToCapture,return) PVOID* BackTrace,
    _Out_opt_ PULONG BackTraceHash
    );


#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

#if (NTDDI_VERSION > NTDDI_WIN2K)

NTSYSAPI
VOID
NTAPI
RtlCaptureContext(
    _Out_ PCONTEXT ContextRecord
    );


#endif

#if (NTDDI_VERSION >= NTDDI_WIN10_VB)

#if defined(_AMD64_)

NTSYSAPI
VOID
NTAPI
RtlCaptureContext2(
    _Inout_ PCONTEXT ContextRecord
    );


#endif

#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

// end_ntifs

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
VOID
NTAPI
RtlUnwind(
    _In_opt_ PVOID TargetFrame,
    _In_opt_ PVOID TargetIp,
    _In_opt_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PVOID ReturnValue
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#if defined(_AMD64_)

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

NTSYSAPI
BOOLEAN
__cdecl
RtlAddFunctionTable(
    _In_reads_(EntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG64 BaseAddress
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlDeleteFunctionTable(
    _In_ PRUNTIME_FUNCTION FunctionTable
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlInstallFunctionTableCallback(
    _In_ ULONG64 TableIdentifier,
    _In_ ULONG64 BaseAddress,
    _In_ ULONG Length,
    _In_ PGET_RUNTIME_FUNCTION_CALLBACK Callback,
    _In_opt_ PVOID Context,
    _In_opt_ PCWSTR OutOfProcessCallbackDll
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#if (NTDDI_VERSION >= NTDDI_WIN8)

NTSYSAPI
NTSTATUS
NTAPI
RtlAddGrowableFunctionTable(
    _Out_ PVOID* DynamicTable,
    _In_reads_(MaximumEntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG MaximumEntryCount,
    _In_ ULONG_PTR RangeBase,
    _In_ ULONG_PTR RangeEnd
    );


NTSYSAPI
VOID
NTAPI
RtlGrowFunctionTable(
    _Inout_ PVOID DynamicTable,
    _In_ ULONG NewEntryCount
    );


NTSYSAPI
VOID
NTAPI
RtlDeleteGrowableFunctionTable(
    _In_ PVOID DynamicTable
    );


#endif // (NTDDI_VERSION >= NTDDI_WIN8)

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
PRUNTIME_FUNCTION
NTAPI
RtlLookupFunctionEntry(
    _In_ ULONG64 ControlPc,
    _Out_ PULONG64 ImageBase,
    _Inout_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


NTSYSAPI
VOID
__cdecl
RtlRestoreContext(
    _In_ PCONTEXT ContextRecord,
    _In_opt_ struct _EXCEPTION_RECORD* ExceptionRecord
    );


NTSYSAPI
VOID
NTAPI
RtlUnwindEx(
    _In_opt_ PVOID TargetFrame,
    _In_opt_ PVOID TargetIp,
    _In_opt_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PVOID ReturnValue,
    _In_ PCONTEXT ContextRecord,
    _In_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


NTSYSAPI
PEXCEPTION_ROUTINE
NTAPI
RtlVirtualUnwind(
    _In_ ULONG HandlerType,
    _In_ ULONG64 ImageBase,
    _In_ ULONG64 ControlPc,
    _In_ PRUNTIME_FUNCTION FunctionEntry,
    _Inout_ PCONTEXT ContextRecord,
    _Out_ PVOID* HandlerData,
    _Out_ PULONG64 EstablisherFrame,
    _Inout_opt_ PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _AMD64_

// end_winnt

// begin_winnt

#if defined(_ARM_)

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

NTSYSAPI
BOOLEAN
__cdecl
RtlAddFunctionTable(
    _In_reads_(EntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG BaseAddress
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlDeleteFunctionTable(
    _In_ PRUNTIME_FUNCTION FunctionTable
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlInstallFunctionTableCallback(
    _In_ ULONG TableIdentifier,
    _In_ ULONG BaseAddress,
    _In_ ULONG Length,
    _In_ PGET_RUNTIME_FUNCTION_CALLBACK Callback,
    _In_opt_ PVOID Context,
    _In_opt_ PCWSTR OutOfProcessCallbackDll
    );


#if (NTDDI_VERSION >= NTDDI_WIN8)

NTSYSAPI
NTSTATUS
NTAPI
RtlAddGrowableFunctionTable(
    _Out_ PVOID* DynamicTable,
    _In_reads_(MaximumEntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG MaximumEntryCount,
    _In_ ULONG_PTR RangeBase,
    _In_ ULONG_PTR RangeEnd
    );


NTSYSAPI
VOID
NTAPI
RtlGrowFunctionTable(
    _Inout_ PVOID DynamicTable,
    _In_ ULONG NewEntryCount
    );


NTSYSAPI
VOID
NTAPI
RtlDeleteGrowableFunctionTable(
    _In_ PVOID DynamicTable
    );


#endif // (NTDDI_VERSION >= NTDDI_WIN8)

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
PRUNTIME_FUNCTION
NTAPI
RtlLookupFunctionEntry(
    _In_ ULONG_PTR ControlPc,
    _Out_ PULONG ImageBase,
    _Inout_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
VOID
__cdecl
RtlRestoreContext(
    _In_ PCONTEXT ContextRecord,
    _In_opt_ struct _EXCEPTION_RECORD* ExceptionRecord
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
VOID
NTAPI
RtlUnwindEx(
    _In_opt_ PVOID TargetFrame,
    _In_opt_ PVOID TargetIp,
    _In_opt_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PVOID ReturnValue,
    _In_ PCONTEXT ContextRecord,
    _In_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


NTSYSAPI
PEXCEPTION_ROUTINE
NTAPI
RtlVirtualUnwind(
    _In_ ULONG HandlerType,
    _In_ ULONG ImageBase,
    _In_ ULONG ControlPc,
    _In_ PRUNTIME_FUNCTION FunctionEntry,
    _Inout_ PCONTEXT ContextRecord,
    _Out_ PVOID* HandlerData,
    _Out_ PULONG EstablisherFrame,
    _Inout_opt_ PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _ARM_

// end_winnt

// begin_winnt

#if defined(_ARM64_)

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

NTSYSAPI
BOOLEAN
__cdecl
RtlAddFunctionTable(
    _In_reads_(EntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG_PTR BaseAddress
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlDeleteFunctionTable(
    _In_ PRUNTIME_FUNCTION FunctionTable
    );


NTSYSAPI
BOOLEAN
__cdecl
RtlInstallFunctionTableCallback(
    _In_ ULONG_PTR TableIdentifier,
    _In_ ULONG_PTR BaseAddress,
    _In_ ULONG Length,
    _In_ PGET_RUNTIME_FUNCTION_CALLBACK Callback,
    _In_opt_ PVOID Context,
    _In_opt_ PCWSTR OutOfProcessCallbackDll
    );


#if (NTDDI_VERSION >= NTDDI_WIN8)

NTSYSAPI
NTSTATUS
NTAPI
RtlAddGrowableFunctionTable(
    _Out_ PVOID* DynamicTable,
    _In_reads_(MaximumEntryCount) PRUNTIME_FUNCTION FunctionTable,
    _In_ ULONG EntryCount,
    _In_ ULONG MaximumEntryCount,
    _In_ ULONG_PTR RangeBase,
    _In_ ULONG_PTR RangeEnd
    );


NTSYSAPI
VOID
NTAPI
RtlGrowFunctionTable(
    _Inout_ PVOID DynamicTable,
    _In_ ULONG NewEntryCount
    );


NTSYSAPI
VOID
NTAPI
RtlDeleteGrowableFunctionTable(
    _In_ PVOID DynamicTable
    );


#endif // (NTDDI_VERSION >= NTDDI_WIN8)

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
PRUNTIME_FUNCTION
NTAPI
RtlLookupFunctionEntry(
    _In_ ULONG_PTR ControlPc,
    _Out_ PULONG_PTR ImageBase,
    _Inout_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
VOID
__cdecl
RtlRestoreContext(
    _In_ PCONTEXT ContextRecord,
    _In_opt_ struct _EXCEPTION_RECORD* ExceptionRecord
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
VOID
NTAPI
RtlUnwindEx(
    _In_opt_ PVOID TargetFrame,
    _In_opt_ PVOID TargetIp,
    _In_opt_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PVOID ReturnValue,
    _In_ PCONTEXT ContextRecord,
    _In_opt_ PUNWIND_HISTORY_TABLE HistoryTable
    );


NTSYSAPI
PEXCEPTION_ROUTINE
NTAPI
RtlVirtualUnwind(
    _In_ ULONG HandlerType,
    _In_ ULONG_PTR ImageBase,
    _In_ ULONG_PTR ControlPc,
    _In_ PRUNTIME_FUNCTION FunctionEntry,
    _Inout_ PCONTEXT ContextRecord,
    _Out_ PVOID* HandlerData,
    _Out_ PULONG_PTR EstablisherFrame,
    _Inout_opt_ PKNONVOLATILE_CONTEXT_POINTERS ContextPointers
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#endif // _ARM64_

#if defined(_CHPE_X86_ARM64_)

#pragma region Application or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

NTSYSAPI
VOID
NTAPI
RtlUnwindEx(
    _In_opt_ PVOID TargetFrame,
    _In_opt_ PVOID TargetIp,
    _In_opt_ PEXCEPTION_RECORD ExceptionRecord,
    _In_ PVOID ReturnValue,
    _In_ PCONTEXT ContextRecord,
    _In_opt_ PVOID HistoryTable
    );


NTSYSAPI
PIMAGE_ARM64_RUNTIME_FUNCTION_ENTRY
NTAPI
RtlLookupFunctionEntryCHPE(
    _In_ ULONG_PTR ControlPc,
    _Out_ PULONG_PTR ImageBase,
    _Inout_opt_ PVOID HistoryTable
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

#endif // _X86_

#pragma region Desktop Family or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
__analysis_noreturn
VOID
NTAPI
RtlRaiseException(
    _In_ PEXCEPTION_RECORD ExceptionRecord
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

#pragma region Application or OneCore Family or Games Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES)

NTSYSAPI
PVOID
NTAPI
RtlPcToFileHeader(
    _In_ PVOID PcValue,
    _Out_ PVOID* BaseOfImage
    );


#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM | WINAPI_PARTITION_GAMES) */
#pragma endregion

// end_winnt

// begin_winnt begin_ntndis begin_wdm

#pragma region Application Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM)

#if (NTDDI_VERSION >= NTDDI_WIN2K)

_Check_return_
NTSYSAPI
SIZE_T
NTAPI
RtlCompareMemory(
    _In_ const VOID* Source1,
    _In_ const VOID* Source2,
    _In_ SIZE_T Length
    );


#endif

#endif /* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP | WINAPI_PARTITION_SYSTEM) */
#pragma endregion

// end_ntndis end_winnt end_wdm


#ifdef __cplusplus
}
#endif

#if _MSC_VER >= 1200
#pragma warning(pop)
#endif

#endif // _APISETRTLSUPPORT_
