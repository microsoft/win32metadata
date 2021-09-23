/*++

Copyright (c) Microsoft Corporation. All rights reserved.

Module Name:

    VmSavedStateDump.h

Abstract:

    This module contains the interface definition for the VmSavedState Dump Provider APIs.

--*/

#ifndef _VMSAVEDSTATEDUMP_H_
#define _VMSAVEDSTATEDUMP_H_

#include "VmSavedStateDumpDefs.h"

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif

#pragma region Desktop Family or OneCore Family
#if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)

#ifdef __cplusplus
extern "C" {
#endif


/// Locates the saved state file(s) for a given VM and/or snapshot. This function uses WMI and the V1 or V2
/// virtualization namespace. So this is expected to fail if ran on a machine without Hyper-V installed.
///  - If the given VM has a VMRS file, parameters BinPath and VsvPath will be a single null terminator character.
///  - If the given VM has BIN and VSV files, parameter VmrsPath will be a single null terminator character.
///  - If no saved state files are found, all three returned string parameters will be single null terminator characters.
///
/// \param  VmName        Supplies the VM name for which the saved state file will be located.
/// \param  SnapshotName  Supplies an optional snapshot name to locate its saved state file
///                       on relation to the given VM name.
/// \retval BinPath       Returns a pointer to a NULL-terminated string containing the full path
///                       name to the BIN file. The caller must call LocalFree on the returned
///                       pointer in order to release the memory occupied by the string.
/// \retval VsvPath       Returns a pointer to a NULL-terminated string containing the full path
///                       name to the VSV file. The caller must call LocalFree on the returned
///                       pointer in order to release the memory occupied by the string.
/// \retval VmrsPath      Returns a pointer to a NULL-terminated string containing the full path
///                       name to the VMRS file. The caller must call LocalFree on the returned
///                       pointer in order to release the memory occupied by the string.
///
/// \return S_OK           The full path(s) to the saved state file were returned successfully.
///         E_OUTOFMEMORY  There was insufficient memory to return the full path(s).
///         HRESULT        Other HRESULT failure codes might be returned.
///
HRESULT
WINAPI
LocateSavedStateFiles(
    _In_        LPCWSTR                     VmName,
    _In_opt_    LPCWSTR                     SnapshotName,
    _Out_       LPWSTR*                     BinPath,
    _Out_       LPWSTR*                     VsvPath,
    _Out_       LPWSTR*                     VmrsPath
    );


/// Loads the given saved state file and creates an instance of VmSavedStateDump.
/// This instance can be referenced on the other methods with the returned UINT64 Id.
///
/// \param  VmrsFile                Supplies the path to the VMRS file to load.
/// \retval VmSavedStateDumpHandle  Returns a Handle to the dump provider instance created.
///
/// \return HRESULT.
///
HRESULT
WINAPI
LoadSavedStateFile(
    _In_    LPCWSTR                         VmrsFile,
    _Out_   VM_SAVED_STATE_DUMP_HANDLE*     VmSavedStateDumpHandle
    );


/// Opens the given saved state file in read-write exclusive mode so that it applies any pending
/// replay logs to the contents. This method doesn't loads the saved state file into the library
/// and can't be used to get content data; function LoadSavedStateFile must be used instead.
///
/// \param VmrsFile  Supplies the path to the VMRS file whose any pending replay log will be applied.
///
/// \return HRESULT.
///
HRESULT
WINAPI
ApplyPendingSavedStateFileReplayLog(
    _In_    LPCWSTR                         VmrsFile
    );


/// Loads the given saved state files and creates an instance of VmSavedStateDump.
/// This instance can be referenced on the other methods with the returned UINT64 Id.
///
/// \param  BinFile                 Supplies the path to the BIN file to load.
/// \param  VsvFile                 Supplies the path to the VSV file to load.
/// \retval VmSavedStateDumpHandle  Returns the ID for the dump provider instance created.
///
/// \return HRESULT.
///
HRESULT
WINAPI
LoadSavedStateFiles(
    _In_    LPCWSTR                         BinFile,
    _In_    LPCWSTR                         VsvFile,
    _Out_   VM_SAVED_STATE_DUMP_HANDLE*     VmSavedStateDumpHandle
    );


/// Releases the given VmSavedStateDump provider that matches the supplied ID.
/// Releasing the provider releases the locks to the saved state files.
/// This means that it won't be available for use on other methods.
///
/// \param VmSavedStateDumpHandle  Supplies the ID of the dump provider instance to release.
///
/// \return HRESULT.
///
HRESULT
WINAPI
ReleaseSavedStateFiles(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle
    );


//-----------------------------------------------------------------------------------------//
//------ The following methods provide mechanisms to query processor related content ------//
//------       and getting memory from already loaded saved state file(s).           ------//
//-----------------------------------------------------------------------------------------//

/// Queries for the Virtual Processor count for a given VmSavedStateDump.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \retval VpCount                 Returns the Virtual Processor count.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetVpCount(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _Out_   UINT32*                         VpCount
    );


/// Queries for the current Architecture/ISA the virtual processor was running at the time the
/// saved state file was generated.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the VP to query.
/// \retval Architecture            Returns the architecture of the supplied vp.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetArchitecture(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _Out_   VIRTUAL_PROCESSOR_ARCH*         Architecture
    );


/// Forces the current Architecture/ISA of a given virtual processor.
/// This is useful to force architecture specific virtual to physical address translation techniques.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the VP to force the architecure on.
/// \retval Architecture            Supplies the architecture to force on the vp.
///
/// \return HRESULT.
///
HRESULT
WINAPI
ForceArchitecture(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _In_    VIRTUAL_PROCESSOR_ARCH          Architecture
    );


/// Queries if a given VP is in kernel space.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the VP to query.
/// \retval InKernelSpace           Returns if the VP is in kernel space.
///
/// \return HRESULT.
///
HRESULT
WINAPI
InKernelSpace(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _Out_   BOOL*                           InKernelSpace
    );


/// Queries for a specific register value for a given VP in a VmSavedStateDump.
/// Callers must specify architecture and register ID in parameter Register, and this function
/// returns the register value through it.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the Virtual Processor Id.
/// \retval Register                Supplies the register architecture and ID, and returns the value.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetRegisterValue(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _Inout_ VIRTUAL_PROCESSOR_REGISTER*     Register
    );


/// Queries for the current Paging Mode in use by the virtual processor at the time the
/// saved state file was generated.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the Virtual Processor Id.
/// \retval PagingMode              Returns the paging mode.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetPagingMode(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _Out_   PAGING_MODE*                    PagingMode
    );


/// Forces the Paging Mode for a given virtual processor.
/// This is useful to force paging mode specific virtual to physical address translation techniques.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the Virtual Processor Id.
/// \retval PagingMode              Supplies the paging mode to force on the virtual processor.
///
/// \returns HRESULT.
///
HRESULT
WINAPI
ForcePagingMode(
    _In_    VM_SAVED_STATE_DUMP_HANDLE  VmSavedStateDumpHandle,
    _In_    UINT32                      VpId,
    _In_    PAGING_MODE                 PagingMode
    );


/// Reads from the saved state file the given guest physical address range and then
/// it is written into the supplied buffer.
/// If BytesRead returns something lower than BufferSize, then the end of memory has been reached.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  PhysicalAddress         Supplies the physical address to read.
/// \retval Buffer                  Returns the read memory range on the given address.
/// \param  BufferSize              Supplies the requested byte count to read.
/// \retval BytesRead               Optionally returns the bytes actually read.
///
/// \return HRESULT.
///
HRESULT
WINAPI
ReadGuestPhysicalAddress(
    _In_        VM_SAVED_STATE_DUMP_HANDLE  VmSavedStateDumpHandle,
    _In_        GUEST_PHYSICAL_ADDRESS      PhysicalAddress,
    _Out_writes_bytes_(BufferSize) LPVOID   Buffer,
    _In_        UINT32                      BufferSize,
    _Out_opt_   UINT32*                     BytesRead
    );


/// Translates a virtual address to a pysical address using information found in the
/// guest's memory and processor's state.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  VpId                    Supplies the VP from where the virtual address is read.
/// \param  VirtualAddress          Supplies the virtual address to translate.
/// \retval PhysicalAddress         Returns the physical address assigned to the supplied virtual address.
///
/// \return HRESULT on any error.
///         VM_SAVED_STATE_DUMP_E_PXE_NOT_PRESENT - Failed to read Page Map Level 4 entry (pxe) for a virtual address.
///         VM_SAVED_STATE_DUMP_E_PDPTE_NOT_PRESENT - Failed to read Page Directory Page Table entry (pdpte) for a virtual address.
///         VM_SAVED_STATE_DUMP_E_PDE_NOT_PRESENT - Failed to read Page Directory entry (pde) for a virtual address.
///         VM_SAVED_STATE_DUMP_E_PTE_NOT_PRESENT - Failed to read Page Table entry (pte) for a virtual address.
///
HRESULT
WINAPI
GuestVirtualAddressToPhysicalAddress(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT32                          VpId,
    _In_    const GUEST_VIRTUAL_ADDRESS     VirtualAddress,
    _Out_   GUEST_PHYSICAL_ADDRESS*         PhysicalAddress
    );

//------------------------------------------------------------------------//
//------ Guest physical memory layout and raw saved memory methods. ------//
//------------------------------------------------------------------------//


/// Returns the layout of the physical memory of the guest. This information contains the chunks of memory
/// with consecutive pages and from where each one starts. If the supplied count is less than the amount
/// of chunks for this guest, then this function returns the expected chunk count.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \retval MemoryChunkPageSize     Returns the size of a page in the memory chunk layout.
/// \retval MemoryChunks            Supplies a buffer of memory chunk structures that are filled up with the
///                                 requested information if the buffer size is the same or bigger than the
///                                 memory chunks count for this guest.
/// \retval MemoryChunkCount        Supplies the size of the MemoryChunks buffer. If this count is lower than
///                                 what the guest really has, then it returns the expected count. If it was
///                                 higher than what the guest has, then it returns the exact count.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetGuestPhysicalMemoryChunks(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _Out_   UINT64*                         MemoryChunkPageSize,
    _Out_   GPA_MEMORY_CHUNK*               MemoryChunks,
    _Inout_ UINT64*                         MemoryChunkCount
    );


/// Translates the given guest physical address to a raw saved memory offset. This is specially useful
/// if callers need to read a memory range directly from all of the guest's saved memory starting
/// in the saved memory address equivalent to the supplied guest physical address.
/// Translation from raw saved memory offset to physical address is not supported.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  PhysicalAddress         Supplies the guest physical address to translate.
/// \retval RawSavedMemoryOffset    Returns the raw saved memory offset for a given physical address.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GuestPhysicalAddressToRawSavedMemoryOffset(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    GUEST_PHYSICAL_ADDRESS          PhysicalAddress,
    _Out_   UINT64*                         RawSavedMemoryOffset
    );


/// Reads raw memory from the saved state file. This function reads raw memory from the saved state file
/// as if it were a flat memory layout, regardless of the guest memory layout.
/// If BytesRead returns something lower than BufferSize, then the end of memory has been reached.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param  RawSavedMemoryOffset    Byte offset on the raw saved memory from where to start reading.
/// \retval Buffer                  Returns the raw memory read on the current raw memory offset.
/// \param  BufferSize              Supplies the requested byte count to read.
/// \retval BytesRead               Optionally returns the bytes actually read.
///
/// \return HRESULT.
///
HRESULT
WINAPI
ReadGuestRawSavedMemory(
    _In_        VM_SAVED_STATE_DUMP_HANDLE  VmSavedStateDumpHandle,
    _In_        UINT64                      RawSavedMemoryOffset,
    _Out_writes_bytes_(BufferSize) LPVOID   Buffer,
    _In_        UINT32                      BufferSize,
    _Out_opt_   UINT32*                     BytesRead
    );


/// Returns the size in bytes of the saved memory for a given VM saved state file.
///
/// \param  VmSavedStateDumpHandle   Supplies a handle to a dump provider instance.
/// \retval GuestRawSavedMemorySize  Returns the size of the saved memory of a given guest in bytes.
///
/// \return HRESULT.
///
HRESULT
WINAPI
GetGuestRawSavedMemorySize(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _Out_   UINT64*                         GuestRawSavedMemorySize
    );


/// Sets the memory block cache limit for a saved state file. By default this is 0.
/// A VmSavedStateDump provider instance reads from the saved state file in a memory block basis.
/// Setting a memory block cache limit will make the instance cache in-memory blocks read from the
/// file, which is useful for performance.
/// Setting the limit back to 0 discards all cached memory blocks.
///
///
/// \param VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \param MemoryBlockCacheLimit   Supplies the memory block cache limit to set.
///
/// \return HRESULT.
///
HRESULT
WINAPI
SetMemoryBlockCacheLimit(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _In_    UINT64                          MemoryBlockCacheLimit
    );


/// Returns the memory block cache limit for a saved state file.
///
/// \param  VmSavedStateDumpHandle  Supplies a handle to a dump provider instance.
/// \retval MemoryBlockCacheLimit   Returns the memory block cache limit.
///
/// \return HRESULT.
///
HRESULT
GetMemoryBlockCacheLimit(
    _In_    VM_SAVED_STATE_DUMP_HANDLE      VmSavedStateDumpHandle,
    _Out_   UINT64*                         MemoryBlockCacheLimit
    );

#ifdef __cplusplus
} // extern "C"
#endif

#endif // WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM)
#pragma endregion

#endif // _VMSAVEDSTATEDUMP_H_
