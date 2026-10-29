////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// DXDumpFileFormat
//
// Format of the DirectX Dump (.dxdmp) File
//
// Copyright (C) Microsoft Corporation
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// FILE LAYOUT
// ===========
//
// A .dxdmp file has the following binary layout:
//
//   [DX_DUMP_FILE_HEADER]                      -- Fixed-size 256-byte header (DX_DUMP_FILE_HEADER_MAX_SIZE)
//   [DX_DUMP_FILE_SECTION_HEADER][Payload]     -- Section 1
//   [DX_DUMP_FILE_SECTION_HEADER][Payload]     -- Section 2
//   ...
//   [DX_DUMP_FILE_SECTION_HEADER][Payload]     -- Section N
//
// Each section is identified by a FourCC code in DX_DUMP_FILE_SECTION_HEADER.SectionType.
// DX_DUMP_FILE_SECTION_HEADER.SectionSizeBytes gives the total byte length of the payload
// (not including the section header itself). Sub-blocks within a section payload are aligned
// to 8 bytes.
//
// TYPED SECTIONS vs MEMORY BUFFER SECTIONS
// =========================================
//
// Most sections contain a single typed struct as their payload (e.g., DX_DUMP_FILE_SECTION_APP_DESC
// contains a DX_DUMP_FILE_APPLICATION_DESC). These are called "typed sections."
//
// Sections with SectionType = DX_DUMP_FILE_SECTION_MEMORY_BUFFER are generic containers.
// Their payload starts with a DX_DUMP_FILE_MEM_HEADER, which identifies the content type
// via its MemType FourCC. The actual data follows the MEM_HEADER.
//
// STRING INTERNING
// ================
//
// String fields in structs (e.g., NameId, ExeFilenameId) are stored as UINT64 string IDs,
// NOT as inline text. To resolve a string ID:
//
//   1. Scan all MEMORY_BUFFER sections with MemType = DX_DUMP_FILE_MEM_TYPE_W_STR.
//   2. For each such section, DX_DUMP_FILE_MEM_HEADER.Key holds the string ID.
//   3. The payload (after the MEM_HEADER) is the null-terminated UTF-16 string content.
//   4. Build a map: string_id -> wchar_t* content.
//
// A string field set to INVALID_STRING_ID (UINT64_MAX) means "no string" / not set.
// DRED strings use DX_DUMP_FILE_MEM_TYPE_DRED_W_STR (Unicode) and DX_DUMP_FILE_MEM_TYPE_DRED_A_STR
// (ASCII) with the original runtime pointer as the Key field.
//
// ARRAY MEMORY SECTIONS (Object Snapshots)
// =========================================
//
// For object arrays (resources, fences, heaps, command queues, etc.):
//   - MemType identifies the object type (e.g., DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_RESOURCES).
//   - Key holds the **element count** (number of structs in the array).
//   - The payload is a flat array of the corresponding struct type.
//
// INDEX-TABLE + BLOB PATTERN (Root Signatures, State Objects)
// ===========================================================
//
// For variable-length data (serialized root signature blobs, pipeline state subobjects):
//   - Key holds the number of index entries.
//   - Payload = [index table entries...][variable-length blob data].
//   - Each index entry contains Offset and Size fields that reference byte positions
//     within the blob portion (which starts immediately after the last index entry,
//     accounting for 8-byte alignment).
//
// PARSING PSEUDOCODE
// ==================
//
//   1. Read 256 bytes as DX_DUMP_FILE_HEADER. Verify Signature == DX_DUMP_FILE_SIGNATURE.
//   2. Loop until EOF:
//      a. Read 16 bytes as DX_DUMP_FILE_SECTION_HEADER.
//      b. Read SectionSizeBytes of payload.
//      c. Dispatch on SectionType:
//         - If MEMORY_BUFFER: parse DX_DUMP_FILE_MEM_HEADER from payload start, then dispatch on MemType.
//         - Otherwise: interpret payload directly as the struct matching the FourCC.
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "d3d12.h"

namespace GpuDebug
{

// Indicates whether live debugging (e.g., via a GPU debugger attached to the process)
// completed before the dump was written.
enum LIVE_DEBUGGING_END_STATUS : UINT32
{
    LIVE_DEBUGGING_NOT_DONE = 0, // Live debugging was not performed or did not finish
    LIVE_DEBUGGING_DONE     = 1, // Live debugging completed before dump creation
};

// Describes the application that produced this dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_APP_DESC section.
struct DX_DUMP_FILE_APPLICATION_DESC
{
    UINT64 ExeFilenameId;              // String ID: executable filename (e.g., "MyGame.exe")
    UINT64 NameId;                     // String ID: application name set via ID3D12Device::SetName or equivalent
    D3D12_VERSION_NUMBER Version;      // Application version reported by the app
    UINT64 EngineNameId;               // String ID: engine name (e.g., "Unreal Engine")
    D3D12_VERSION_NUMBER EngineVersion;// Engine version reported by the app
    GUID AppId;                        // Application GUID for telemetry correlation
};
static_assert(sizeof(DX_DUMP_FILE_APPLICATION_DESC) == 56, "Size of DX_DUMP_FILE_APPLICATION_DESC must be 56 bytes.");

// Dump file capability and configuration snapshot.
// Found as the payload of a DX_DUMP_FILE_SECTION_DUMP_CAPS_AND_CONFIG section.
struct DX_DUMP_FILE_CAPS_AND_CONFIG
{
    D3D12_FEATURE_DATA_DUMP_FILE FeatureData;      // Feature support data queried from the driver
    D3D12_DUMP_FILE_DRIVER_OPTIONS DriverOptions;  // Options set by the app via ConfigureDumpFile or defaults from the runtime
    union
    {
        struct
        {
            UINT32 SupportedByKMD : 1;             // 1 if the kernel-mode driver supports GPU dump collection
            UINT32 Unused         : 31;
        } Flags;
        UINT32 FlagBits;
    };
};
static_assert(sizeof(DX_DUMP_FILE_CAPS_AND_CONFIG) == 20, "Size of DX_DUMP_FILE_CAPS_AND_CONFIG must be 20 bytes.");

// GPU adapter information and memory budget at the time of the dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_ADAPTER_INFO section.
struct DX_DUMP_FILE_ADAPTER_INFO
{
    DXGI_ADAPTER_DESC3 AdapterDesc;    // Full DXGI adapter description (name, vendor ID, device ID, etc.)
    UINT64 DriverVersion;              // Driver version as a packed UINT64 (use HIWORD/LOWORD to extract parts)

    UINT64 DedicatedUsed;
    UINT64 DedicatedBudget;
    UINT64 SystemUsed;
    UINT64 SystemBudget;

    // If this is a compute-only device, this will be D3D_FEATURE_LEVEL_1_0_CORE.
    // If the device is capable of graphics, this will be D3D_FEATURE_LEVEL_11_0.
    // (It is assumed that less-than-d3d12-capable graphics adapters are never considered.)
    D3D_FEATURE_LEVEL MinimumFeatureLevelForMostCapableAttribute;
};
#if defined(_WIN32) && defined(_WIN64)
    static_assert(sizeof(DX_DUMP_FILE_ADAPTER_INFO) == 368, "Size of DX_DUMP_FILE_ADAPTER_INFO must be 368 bytes.");
#endif

// Device Removed Extended Data (DRED) summary at the time of the dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_DRED_INFO section.
struct DX_DUMP_FILE_DRED_INFO
{
    D3D12_DRED_VERSION Version;             // DRED version used to collect data (currently 1.3)
    D3D12_DRED_DEVICE_STATE DeviceState;    // Device state (e.g., fault, hung, pagefault)
    HRESULT DeviceRemovedReason;            // The HRESULT returned by GetDeviceRemovedReason()
};
static_assert(sizeof(DX_DUMP_FILE_DRED_INFO) == 12, "Size of DX_DUMP_FILE_DRED_INFO must be 12 bytes.");

// Per-command-list auto-breadcrumb node capturing GPU progress at the time of device removal.
// Found as the payload of a DX_DUMP_FILE_SECTION_DRED_BREADCRUMB_NODE section (one section per node).
// Address fields reference DRED memory sections (DRED_A_STR, DRED_W_STR, DRED_CMD_HSTR, DRED_BRDC_CTX)
// that can be resolved by matching DX_DUMP_FILE_MEM_HEADER.Key to the address value.
struct DX_DUMP_FILE_DRED_AUTO_BREADCRUMB_NODE1
{
    UINT64 CommandListDebugNameAAddress;  // Key into DRED_A_STR sections: ASCII debug name of the command list
    UINT64 CommandListDebugNameWAddress;  // Key into DRED_W_STR sections: Unicode debug name of the command list
    UINT64 CommandQueueDebugNameAAddress; // Key into DRED_A_STR sections: ASCII debug name of the command queue
    UINT64 CommandQueueDebugNameWAddress; // Key into DRED_W_STR sections: Unicode debug name of the command queue

    UINT64 GraphicsCommandListAddress;   // Runtime address of the ID3D12GraphicsCommandList (for correlation)
    UINT64 CommandQueueAddress;          // Runtime address of the ID3D12CommandQueue (for correlation)

    UINT32 BreadcrumbCount;              // Number of D3D12_AUTO_BREADCRUMB_OP values in the command history
    UINT64 CommandHistoryAddress;        // Key into DRED_CMD_HSTR sections: array of D3D12_AUTO_BREADCRUMB_OP
    UINT LastBreadcrumbValue;            // Index of the last breadcrumb confirmed complete by the GPU
    UINT BreadcrumbContextsCount;        // Number of DX_DUMP_FILE_DRED_BREADCRUMB_CONTEXT entries
    UINT64 BreadcrumbContextAddress;     // Key into DRED_BRDC_CTX sections: array of breadcrumb contexts
};
static_assert(sizeof(DX_DUMP_FILE_DRED_AUTO_BREADCRUMB_NODE1) == 80, "Size of DX_DUMP_FILE_DRED_AUTO_BREADCRUMB_NODE1 must be 80 bytes.");

// A breadcrumb context entry associating a breadcrumb index with a user-provided context string.
// Found in DX_DUMP_FILE_MEM_TYPE_DRED_BRDC_CTX memory sections as an array.
struct DX_DUMP_FILE_DRED_BREADCRUMB_CONTEXT
{
    UINT BreadcrumbIndex;              // Index into the breadcrumb op array this context applies to
    UINT64 ContextStringAddress;       // Key into DRED_W_STR sections: the context string content
};
static_assert(sizeof(DX_DUMP_FILE_DRED_BREADCRUMB_CONTEXT) == 16, "Size of DX_DUMP_FILE_DRED_BREADCRUMB_CONTEXT must be 16 bytes.");

// GPU virtual address page fault information from DRED.
// Found as the payload of a DX_DUMP_FILE_SECTION_DRED_PAGE_FAULT_INFO section.
struct DX_DUMP_FILE_DRED_PAGE_FAULT_INFO
{
    D3D12_GPU_VIRTUAL_ADDRESS PageFaultVA;      // The GPU virtual address that caused the page fault
    D3D12_DRED_PAGE_FAULT_FLAGS PageFaultFlags; // Flags indicating the nature of the fault
};
static_assert(sizeof(DX_DUMP_FILE_DRED_PAGE_FAULT_INFO) == 16, "Size of DX_DUMP_FILE_DRED_PAGE_FAULT_INFO must be 16 bytes.");

// A DRED allocation node representing a tracked allocation (existing or recently freed).
// Found as the payload of DX_DUMP_FILE_SECTION_DRED_EXIST_ALLOC_NODE (still-live allocations)
// or DX_DUMP_FILE_SECTION_DRED_FREED_ALLOC_NODE (recently freed allocations).
struct DX_DUMP_FILE_DRED_ALLOCATION_NODE1
{
    UINT64 AsciiObjectNameAddress;              // Key into DRED_A_STR sections: ASCII name of the allocation
    UINT64 UnicodeObjectNameAddress;            // Key into DRED_W_STR sections: Unicode name of the allocation
    D3D12_DRED_ALLOCATION_TYPE AllocationType;  // The type of D3D12 allocation (resource, heap, etc.)
    UINT64 ObjectAddress;                       // Runtime address of the D3D object for correlation
};
static_assert(sizeof(DX_DUMP_FILE_DRED_ALLOCATION_NODE1) == 32, "Size of DX_DUMP_FILE_DRED_ALLOCATION_NODE1 must be 32 bytes.");

// A D3D runtime journal entry capturing significant events (API calls, warnings, errors).
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_JOURNAL memory sections as an array.
// Key of the MEM_HEADER holds the element count.
struct DX_DUMP_FILE_D3D_JOURNAL_ENTRY
{
    UINT32 Code;                       // Event code identifying the journal entry type
    DWORD ThreadID;                    // Thread that logged this entry
    DWORD TickCount;                   // GetTickCount() value at the time of the entry
    UINT64 StackCaptureAddress[3];     // Up to 3 return addresses from the call stack
    UINT64 EntryPointAddress;          // Address of the D3D API entry point invoked
    UINT64 CallerAddress;              // Caller address (return address of the API call)
    UINT64 MessageStringId;            // String ID (W_STR) for an associated message, or INVALID_STRING_ID
};
static_assert(sizeof(DX_DUMP_FILE_D3D_JOURNAL_ENTRY) == 64, "Size of DX_DUMP_FILE_D3D_JOURNAL_ENTRY must be 64 bytes.");

// Enumerates all D3D12 object types that can be captured in a dump file.
// Used by DX_DUMP_FILE_D3D_OBJECT_GENERIC.Type to identify objects without a dedicated struct.
enum DX_DUMP_FILE_D3D_OBJECT_TYPE : UINT32
{
    DX_DUMP_FILE_D3D_OBJECT_TYPE_GRAPHICS_COMMAND_QUEUE     = 0,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_COMMAND_ALLOCATOR          = 1,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_PIPELINE_STATE             = 2,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_GRAPHICS_COMMAND_LIST      = 3,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_DECODE_COMMAND_LIST  = 4,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_RESOURCE                   = 5,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_DESCRIPTOR_HEAP            = 6,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_ROOT_SIGNATURE             = 7,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_HEAP                       = 8,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_FENCE                      = 9,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_QUERY_HEAP                 = 10,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_COMMAND_SIGNATURE          = 11,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_PIPELINE_LIBRARY           = 12,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_DECODER              = 13,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_DECODE_COMMAND_QUEUE = 14,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_PROCESSOR            = 15,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_PROCESS_COMMAND_LIST = 16,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_PROCESS_COMMAND_QUEUE = 17,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_CRYPTO_SESSION             = 18,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_CRYPTO_SESSION_POLICY      = 19,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_PROTECTED_RESOURCE_SESSION = 20,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_DECODER_HEAP         = 21,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_STATE_OBJECT               = 22,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_META_COMMAND               = 23,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_LIFETIME_TRACKER           = 24,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_TRACKED_WORKLOAD           = 25,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_ENCODE_COMMAND_LIST  = 26,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_ENCODE_COMMAND_QUEUE = 27,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_MOTION_ESTIMATOR     = 28,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_MOTION_VECTOR_HEAP   = 29,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_EXTENSION_COMMAND    = 30,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_SHADER_CACHE_SESSION       = 31,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_ENCODER              = 32,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_VIDEO_ENCODER_HEAP         = 33,
    DX_DUMP_FILE_D3D_OBJECT_TYPE_SOFTWARE_COMMAND_QUEUE     = 34,




    // Must be last external object representation:
    DX_DUMP_FILE_D3D_OBJECT_TYPE_COUNT,
};

// Snapshot of a D3D12 device object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DEVICE memory sections.
// Superseded by DX_DUMP_FILE_D3D_OBJECT_DEVICE1; retained for reading older dumps.
struct DX_DUMP_FILE_D3D_OBJECT_DEVICE
{
    D3D_FEATURE_LEVEL MinimumFeatureLevel; // The minimum feature level used to create the device
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_DEVICE) == 4, "Size of DX_DUMP_FILE_D3D_OBJECT_DEVICE must be 4 bytes.");

// Snapshot of a D3D12 device object, including its name.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DEVICE1 memory sections.
struct DX_DUMP_FILE_D3D_OBJECT_DEVICE1
{
    D3D_FEATURE_LEVEL MinimumFeatureLevel; // The minimum feature level used to create the device
    UINT32 Reserved;                       // Padding for alignment
    UINT64 NameId;                         // String ID for the name
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_DEVICE1) == 16, "Size of DX_DUMP_FILE_D3D_OBJECT_DEVICE1 must be 16 bytes.");

// Describes how a resource relates to its backing memory heap.
enum DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE : UINT32
{
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE_PLACED          = 0, // Placed resource on an immutable heap
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE_COMMITTED       = 1, // Committed resource with an implicit heap
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE_API_HEAP        = 2, // Implicit resource (e.g. swap chain back buffer)
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE_RESERVED        = 3, // Reserved/tiled resource
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE_PLACED_TEXTURE  = 4, // Placed texture on an immutable buffer: app cannot set it, it is internal to D3D
};

// Snapshot of a D3D12 resource object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_RESOURCES memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_RESOURCE
{
    UINT64 Address;                                         // Runtime address of the D3D object
    UINT64 NameId;                                          // String ID for the name
    UINT64 DdiHandle;                                       // Driver handle
    UINT64 GpuVirtualAddress;                               // D3D12_GPU_VIRTUAL_ADDRESS
    UINT64 HeapAddress;                                     // Runtime address of the associated heap (0 if none)
    DX_DUMP_FILE_D3D_RESOURCE_HEAP_TYPE ResourceHeapType;   // How the resource relates to its backing heap
    D3D12_RESOURCE_DESC2 Desc;                              // Resource description
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_RESOURCE) == 128, "Size of DX_DUMP_FILE_D3D_OBJECT_RESOURCE must be 128 bytes.");

// Snapshot of a D3D12 root signature object (index entry for serialized blob).
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_ROOT_SIGNATURE_BLOBS memory sections.
// Layout: [array of this struct (index table)][concatenated blob data].
// Offset and Size reference positions within the blob portion (after the index table).
struct DX_DUMP_FILE_D3D_OBJECT_ROOT_SIGNATURE
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    UINT64 Offset;                      // Byte offset into the blob data that follows the index table
    UINT64 Size;                        // Size in bytes of the serialized root signature blob
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_ROOT_SIGNATURE) == 40, "Size of DX_DUMP_FILE_D3D_OBJECT_ROOT_SIGNATURE must be 40 bytes.");

// A single vertex input element definition within a pipeline state's input layout.
// Part of the variable-length blob data referenced by DX_DUMP_FILE_D3D_OBJECT_INPUT_LAYOUT.
struct DX_DUMP_FILE_D3D_OBJECT_INPUT_ELEMENT
{
    UINT32 InputSlot;
    UINT32 AlignedByteOffset;
    DXGI_FORMAT Format;
    D3D12_INPUT_CLASSIFICATION InputSlotClass;
    UINT32 InstanceDataStepRate;
    UINT32 InputRegister;
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_INPUT_ELEMENT) == 24, "Size of DX_DUMP_FILE_D3D_OBJECT_INPUT_ELEMENT must be 24 bytes.");

// Input layout description referencing input elements stored in the pipeline state blob.
struct DX_DUMP_FILE_D3D_OBJECT_INPUT_LAYOUT
{
    UINT32 NumElements;                 // Number of input elements
    UINT32 ElementsOffset;              // Byte offset into the blob where DX_DUMP_FILE_D3D_OBJECT_INPUT_ELEMENT array starts
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_INPUT_LAYOUT) == 8, "Size of DX_DUMP_FILE_D3D_OBJECT_INPUT_LAYOUT must be 8 bytes.");

// A single stream output declaration entry within a pipeline state.
// Part of the variable-length blob data referenced by DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT.
struct DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT_DECL_ENTRY
{
    UINT32 Stream;
    UINT32 OutputSlot;
    UINT32 RegisterIndex;
    UINT32 RegisterMask;                // 4 LSBs are xyzw respectively
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT_DECL_ENTRY) == 16, "Size of DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT_DECL_ENTRY must be 16 bytes.");

// Stream output configuration referencing strides and entries in the pipeline state blob.
struct DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT
{
    UINT32 NumStrides;                  // Number of buffer strides
    UINT32 NumEntries;                  // Number of declaration entries
    UINT32 RasterizedStream;            // Rasterized stream index
    UINT32 StridesOffset;               // Byte offset into blob for UINT32[] buffer strides array
    UINT32 EntriesOffset;               // Byte offset into blob for DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT_DECL_ENTRY array
    UINT32 Reserved;                    // Padding for alignment
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT) == 24, "Size of DX_DUMP_FILE_D3D_OBJECT_STREAM_OUTPUT must be 24 bytes.");

// Snapshot of a D3D12 pipeline state object or state object with variable-length subobject data.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_LEGACY_PIPELINE_STATES or DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_STATE_OBJECTS.
// Layout: [array of this struct (index table)][concatenated subobject blob data].
struct DX_DUMP_FILE_D3D_OBJECT_WITH_SUBOBJECTS
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    UINT32 Type;                        // D3D12_STATE_OBJECT_TYPE for SOs, 0 for legacy PSOs which are stored as a different memory type.
                                        // INVALID_VALUE means the state object was being created or modified on another thread while the
                                        // dump was captured, so its type is unknown and its subobjects are absent. Test for INVALID_VALUE
                                        // explicitly rather than treating 0 as unset: 0 is a valid D3D12_STATE_OBJECT_TYPE_COLLECTION.
    UINT32 SubobjectsCount;             // Number of subobject entries in the blob
    UINT64 SubobjectsOffset;            // Byte offset into the blob data that follows the object array
    UINT64 SubobjectsSize;              // Size in bytes of the variable-length subobject data
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_WITH_SUBOBJECTS) == 48, "Size of DX_DUMP_FILE_D3D_OBJECT_WITH_SUBOBJECTS must be 48 bytes.");

// Snapshot of a D3D12 descriptor heap object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DESCRIPTOR_HEAPS memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_DESCRIPTOR_HEAP
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_DESCRIPTOR_HEAP_DESC Desc;
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_DESCRIPTOR_HEAP) == 40, "Size of DX_DUMP_FILE_D3D_OBJECT_DESCRIPTOR_HEAP must be 40 bytes.");

// Snapshot of a D3D12 heap object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_HEAPS memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_HEAP
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_HEAP_DESC Desc;               // Heap description
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_HEAP) == 72, "Size of DX_DUMP_FILE_D3D_OBJECT_HEAP must be 72 bytes.");

// Snapshot of a D3D12 fence object with its last completed value.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_FENCES memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_FENCE
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_FENCE_FLAGS Flags;
    UINT32 Reserved;                    // Padding for alignment
    UINT64 CompletedValue;
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_FENCE) == 40, "Size of DX_DUMP_FILE_D3D_OBJECT_FENCE must be 40 bytes.");

// Snapshot of a D3D12 command queue object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_QUEUES memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_COMMAND_QUEUE
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_COMMAND_QUEUE_DESC Desc;      // Command queue description
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_COMMAND_QUEUE) == 40, "Size of DX_DUMP_FILE_D3D_OBJECT_COMMAND_QUEUE must be 40 bytes.");

// Snapshot of a D3D12 command list object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_LISTS memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_COMMAND_LIST
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_COMMAND_LIST_TYPE Type;
    UINT32 NodeMask;                    // API node mask
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_COMMAND_LIST) == 32, "Size of DX_DUMP_FILE_D3D_OBJECT_COMMAND_LIST must be 32 bytes.");

// Snapshot of a D3D12 command allocator object.
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_ALLOCATORS memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_COMMAND_ALLOCATOR
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    UINT64 DdiHandle;                   // Driver handle
    D3D12_COMMAND_LIST_TYPE Type;
    UINT32 Reserved;                    // Padding for alignment
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_COMMAND_ALLOCATOR) == 32, "Size of DX_DUMP_FILE_D3D_OBJECT_COMMAND_ALLOCATOR must be 32 bytes.");

// Snapshot of a D3D12 generic object (catch-all for types without a dedicated struct).
// Found in DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_GENERICS memory sections as an array.
struct DX_DUMP_FILE_D3D_OBJECT_GENERIC
{
    UINT64 Address;                     // Runtime address of the D3D object
    UINT64 NameId;                      // String ID for the name
    DX_DUMP_FILE_D3D_OBJECT_TYPE Type;  // Type of the D3D object
    UINT32 Reserved;                    // Padding for alignment
};
static_assert(sizeof(DX_DUMP_FILE_D3D_OBJECT_GENERIC) == 24, "Size of DX_DUMP_FILE_D3D_OBJECT_GENERIC must be 24 bytes.");

// An application-defined annotation (user marker/event) captured in the dump.
// Found in DX_DUMP_FILE_MEM_TYPE_APP_ANNOTATIONS memory sections as an array.
// Associated data blobs are stored in DX_DUMP_FILE_MEM_TYPE_APP_ANNOTATION_DATA sections
// keyed by the annotation ID in Key.
struct DX_DUMP_FILE_APP_ANNOTATION
{
    UINT64 ID;                         // Unique annotation ID; used as key for annotation data lookups
    UINT Metadata;                     // Application-defined metadata value
    UINT8 Type;                        // Application-defined annotation type
};
static_assert(sizeof(DX_DUMP_FILE_APP_ANNOTATION) == 16, "Size of DX_DUMP_FILE_APP_ANNOTATION must be 16 bytes.");

// Maps a D3D object (by DDI handle) to its array of annotation IDs.
// Found in DX_DUMP_FILE_MEM_TYPE_APP_COMMAND_QUEUE_ANNOTATION_ID_MAP or
// DX_DUMP_FILE_MEM_TYPE_APP_COMMAND_ALLOCATOR_ANNOTATION_ID_MAP memory sections.
// Immediately following this struct in the blob is an array of UINT64 annotation IDs.
struct DX_DUMP_FILE_APP_ANNOTATION_ID_MAP
{
    UINT64 DdiHandle;                   // Driver handle to identify the D3D object
    UINT64 AnnotationIdCount;           // Number of UINT64 annotation IDs in the array that follows this struct
};
static_assert(sizeof(DX_DUMP_FILE_APP_ANNOTATION_ID_MAP) == 16, "Size of DX_DUMP_FILE_APP_ANNOTATION_ID_MAP must be 16 bytes.");

// Operating system information at the time of the dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_OS_INFO section.
struct DX_DUMP_FILE_OS_INFO
{
    UINT32 MajorVersion;        // OS major version (e.g. 10)
    UINT32 MinorVersion;        // OS minor version (e.g. 0)
    UINT32 BuildNumber;         // OS build number (e.g. 22621; >=22000 indicates Windows 11)
    UINT32 PlatformId;          // VER_PLATFORM_WIN32_NT
    UINT16 ServicePackMajor;    // Major version of the latest installed service pack (0 if none)
    UINT16 ServicePackMinor;    // Minor version of the latest installed service pack (0 if none)
    UINT16 SuiteMask;           // Bitmask of installed product suites (VER_SUITE_* flags)
    UINT8  ProductType;         // VER_NT_WORKSTATION, VER_NT_DOMAIN_CONTROLLER, VER_NT_SERVER
    UINT8  Reserved;
    UINT32 ProductEdition;      // PRODUCT_* from GetProductInfo() (e.g. PRODUCT_PROFESSIONAL, PRODUCT_ENTERPRISE)
    union
    {
        struct
        {
            UINT32 DeveloperModeEnabled : 1;
            UINT32 Unused               : 31;
        } Flags;
        UINT32 FlagBits;
    };
    UINT64 OSDescriptionId;     // Interned string: full build string (e.g. from BuildLabEx registry value)
};
static_assert(sizeof(DX_DUMP_FILE_OS_INFO) == 40, "Size of DX_DUMP_FILE_OS_INFO must be 40 bytes.");

// Extended operating system information.
// Found as the payload of a DX_DUMP_FILE_SECTION_OS_INFO1 section.
struct DX_DUMP_FILE_OS_INFO1
{
    UINT32 MajorVersion;        // OS major version (e.g. 10)
    UINT32 MinorVersion;        // OS minor version (e.g. 0)
    UINT32 BuildNumber;         // OS build number (e.g. 22621; >=22000 indicates Windows 11)
    UINT32 PlatformId;          // VER_PLATFORM_WIN32_NT
    UINT16 ServicePackMajor;    // Major version of the latest installed service pack (0 if none)
    UINT16 ServicePackMinor;    // Minor version of the latest installed service pack (0 if none)
    UINT16 SuiteMask;           // Bitmask of installed product suites (VER_SUITE_* flags)
    UINT8  ProductType;         // VER_NT_WORKSTATION, VER_NT_DOMAIN_CONTROLLER, VER_NT_SERVER
    UINT8  Reserved;
    UINT32 ProductEdition;      // PRODUCT_* from GetProductInfo() (e.g. PRODUCT_PROFESSIONAL, PRODUCT_ENTERPRISE)
    union
    {
        struct
        {
            UINT32 DeveloperModeEnabled : 1;
            UINT32 Unused               : 31;
        } Flags;
        UINT32 FlagBits;
    };
    UINT64 OSDescriptionId;     // Interned string: full build string (e.g. from BuildLabEx registry value)
    UINT32 UpdateBuildRevision; // Windows update build revision (UBR), e.g. 9711 in 26200.9711
    UINT32 Reserved2;
};
static_assert(sizeof(DX_DUMP_FILE_OS_INFO1) == 48, "Size of DX_DUMP_FILE_OS_INFO1 must be 48 bytes.");

// System memory (RAM) information at the time of the dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_SYSTEM_MEMORY_INFO section.
struct DX_DUMP_FILE_SYSTEM_MEMORY_INFO
{
    UINT64 TotalPhysicalMemory;     // Total physical RAM in bytes
    UINT64 AvailablePhysicalMemory; // Available physical RAM in bytes
    UINT64 TotalPageFile;           // Total page file (swap) size in bytes
    UINT64 AvailablePageFile;       // Available page file in bytes
    UINT64 TotalVirtualMemory;      // Total virtual address space in bytes
    UINT64 AvailableVirtualMemory;  // Available virtual address space in bytes
    UINT32 MemoryLoad;              // Approximate percentage of physical memory in use (0-100)
    UINT16 MemoryType;              // SMBIOS Memory Type (e.g. 26=DDR4, 34=DDR5, 24=DDR3)
    UINT16 MemorySpeedMTs;          // Memory speed in MT/s (megatransfers per second) from SMBIOS
};
static_assert(sizeof(DX_DUMP_FILE_SYSTEM_MEMORY_INFO) == 56, "Size of DX_DUMP_FILE_SYSTEM_MEMORY_INFO must be 56 bytes.");

// CPU information at the time of the dump.
// Found as the payload of a DX_DUMP_FILE_SECTION_CPU_INFO section.
// Immediately followed by ProcessorPackageCount instances of DX_DUMP_FILE_CPU_PACKAGE_INFO.
struct DX_DUMP_FILE_CPU_INFO
{
    UINT32 ProcessorPackageCount;    // Number of physical CPU packages (sockets); also the array length of entries that follow
    UINT32 ProcessorArchitecture;    // PROCESSOR_ARCHITECTURE_AMD64, PROCESSOR_ARCHITECTURE_ARM64, etc.
    UINT32 TotalLogicalProcessors;   // Total logical processors across all packages
    UINT32 PageSize;                 // System page size in bytes
    UINT8  VirtualizationEnabled;    // 1 if virtualization is enabled in the firmware and made available by the OS, 0 otherwise
    UINT8  Reserved[3];
    UINT32 Reserved2;
    UINT64 TimestampClockFrequencyHz; // High-resolution performance counter frequency (from QueryPerformanceFrequency)
};
static_assert(sizeof(DX_DUMP_FILE_CPU_INFO) == 32, "Size of DX_DUMP_FILE_CPU_INFO must be 32 bytes.");

// Per-CPU-package (socket) details. An array of these follows DX_DUMP_FILE_CPU_INFO in the same section.
struct DX_DUMP_FILE_CPU_PACKAGE_INFO
{
    UINT32 ProcessorIndex;      // Package index (0, 1, ...)
    UINT32 PhysicalCoreCount;   // Physical cores in this package
    UINT32 LogicalCoreCount;    // Logical cores (hardware threads) in this package
    UINT32 MaxClockMHz;         // Maximum clock speed in MHz
    UINT64 ProcessorNameId;     // Interned string: processor name
    UINT64 VendorStringId;      // Interned string: vendor identifier
    UINT64 DeviceStringId;      // Interned string: device identifier from registry
};
static_assert(sizeof(DX_DUMP_FILE_CPU_PACKAGE_INFO) == 40, "Size of DX_DUMP_FILE_CPU_PACKAGE_INFO must be 40 bytes.");

// Maximum size of the file header in bytes. The header is always this size (padded with zeros).
#define DX_DUMP_FILE_HEADER_MAX_SIZE 256

// Current value of DX_DUMP_FILE_HEADER.Fields.Version. Increment on breaking format changes.
static constexpr UINT32 DX_DUMP_FILE_VERSION = 1;

// The fixed-size file header that starts every .dxdmp file.
// Always exactly DX_DUMP_FILE_HEADER_MAX_SIZE (256) bytes; unused bytes are zeroed.
// Parsers should verify Fields.Signature == DX_DUMP_FILE_SIGNATURE before proceeding.
struct DX_DUMP_FILE_HEADER
{
    union
    {
        struct
        {
            UINT32 Signature;                                   // Must be DX_DUMP_FILE_SIGNATURE. Identifies a valid .dxdmp file.
            UINT32 Version;                                     // Header format version (DX_DUMP_FILE_VERSION). Increment on breaking changes.
            GUID Guid;                                          // Unique dump identifier; correlates with TDR/Watson reports.
            D3D12_DEVICE_ERROR_CODE DeviceErrorCode;            // The device error code that triggered the dump.
            FILETIME CreationTime;                              // UTC timestamp when the dump was created.
            BOOL UploadedToWatson;                              // TRUE if this dump was uploaded to Watson telemetry.
            LIVE_DEBUGGING_END_STATUS LiveDebuggingEndStatus;   // Whether live debugging finished before dump write.
        } Fields;
        BYTE AllBytes[DX_DUMP_FILE_HEADER_MAX_SIZE]; // Provides the fixed 256-byte footprint.
    };
};
static_assert(sizeof(DX_DUMP_FILE_HEADER) == DX_DUMP_FILE_HEADER_MAX_SIZE, "GPU Dump header size exceeds max size.");

// Section header that precedes every section's payload in the file.
// Read 16 bytes, then read SectionSizeBytes of payload data.
struct DX_DUMP_FILE_SECTION_HEADER
{
    UINT32 SectionType;                // FourCC identifying the section (one of DX_DUMP_FILE_SECTION_* constants)
    UINT64 SectionSizeBytes;           // Total byte length of the section payload (excludes this header)
};
static_assert(sizeof(DX_DUMP_FILE_SECTION_HEADER) == 16, "Size of DX_DUMP_FILE_SECTION_HEADER must be 16 bytes.");

// Sub-header for MEMORY_BUFFER sections. Appears at the start of the section payload
// when SectionType == DX_DUMP_FILE_SECTION_MEMORY_BUFFER.
// The typed payload data immediately follows this header.
struct DX_DUMP_FILE_MEM_HEADER
{
    UINT32 MemType;                    // FourCC identifying the memory content type (one of DX_DUMP_FILE_MEM_TYPE_* constants)
    UINT64 SizeBytes;                  // Byte length of the data following this header
    UINT64 Key;                        // Context-dependent key: string ID for strings, element count for arrays,
                                       // or original runtime pointer for DRED strings (used for cross-reference)
};
static_assert(sizeof(DX_DUMP_FILE_MEM_HEADER) == 24, "Size of DX_DUMP_FILE_MEM_HEADER must be 24 bytes.");

// Sentinel values
static constexpr UINT INVALID_VALUE = UINT32_MAX;       // Generic invalid/unset marker for UINT32 fields
static constexpr UINT64 INVALID_STRING_ID = UINT64_MAX; // Indicates "no string" for UINT64 string ID fields

template <int a, int b, int c, int d>
struct FourCC
{
    static constexpr unsigned int value = (((((d << 8) | c) << 8) | b) << 8) | a;
};

// File signature and section type FourCC constants.
// These identify the kind of data in each section. Match against DX_DUMP_FILE_SECTION_HEADER.SectionType.
static constexpr UINT32 DX_DUMP_FILE_SIGNATURE                          = FourCC<'m', 'D', 'p', 'G'>::value;
static constexpr UINT32 DX_DUMP_FILE_SECTION_APP_DESC                   = FourCC<'A', 'p', 'D', 's'>::value;  // Payload: DX_DUMP_FILE_APPLICATION_DESC
static constexpr UINT32 DX_DUMP_FILE_SECTION_DEVICE_CONFIGURATION_DESC  = FourCC<'D', 'v', 'C', 'f'>::value;  // Payload: D3D12_DEVICE_CONFIGURATION_DESC
static constexpr UINT32 DX_DUMP_FILE_SECTION_DUMP_CAPS_AND_CONFIG       = FourCC<'D', 'C', 'A', 'C'>::value;  // Payload: DX_DUMP_FILE_CAPS_AND_CONFIG
static constexpr UINT32 DX_DUMP_FILE_SECTION_ADAPTER_INFO               = FourCC<'A', 'd', 'I', 'n'>::value;  // Payload: DX_DUMP_FILE_ADAPTER_INFO
static constexpr UINT32 DX_DUMP_FILE_SECTION_OS_INFO                    = FourCC<'O', 'S', 'I', '0'>::value;  // Payload: DX_DUMP_FILE_OS_INFO
static constexpr UINT32 DX_DUMP_FILE_SECTION_OS_INFO1                   = FourCC<'O', 'S', 'I', '1'>::value;  // Payload: DX_DUMP_FILE_OS_INFO1
static constexpr UINT32 DX_DUMP_FILE_SECTION_SYSTEM_MEMORY_INFO         = FourCC<'S', 'M', 'I', '0'>::value;  // Payload: DX_DUMP_FILE_SYSTEM_MEMORY_INFO
static constexpr UINT32 DX_DUMP_FILE_SECTION_CPU_INFO                   = FourCC<'C', 'P', 'I', '0'>::value;  // Payload: DX_DUMP_FILE_CPU_INFO + DX_DUMP_FILE_CPU_PACKAGE_INFO[]
static constexpr UINT32 DX_DUMP_FILE_SECTION_MEMORY_BUFFER              = FourCC<'M', 'e', 'm', 'r'>::value;  // Payload: DX_DUMP_FILE_MEM_HEADER + typed data (see MEM_TYPE constants below)
static constexpr UINT32 DX_DUMP_FILE_SECTION_DRED_INFO                  = FourCC<'D', 'R', 'I', 'N'>::value;  // Payload: DX_DUMP_FILE_DRED_INFO
static constexpr UINT32 DX_DUMP_FILE_SECTION_DRED_BREADCRUMB_NODE       = FourCC<'D', 'R', 'B', 'N'>::value;  // Payload: DX_DUMP_FILE_DRED_AUTO_BREADCRUMB_NODE1 (one per section)
static constexpr UINT32 DX_DUMP_FILE_SECTION_DRED_PAGE_FAULT_INFO       = FourCC<'D', 'R', 'P', 'F'>::value;  // Payload: DX_DUMP_FILE_DRED_PAGE_FAULT_INFO
static constexpr UINT32 DX_DUMP_FILE_SECTION_DRED_EXIST_ALLOC_NODE      = FourCC<'D', 'E', 'A', 'N'>::value;  // Payload: DX_DUMP_FILE_DRED_ALLOCATION_NODE1 (existing allocations)
static constexpr UINT32 DX_DUMP_FILE_SECTION_DRED_FREED_ALLOC_NODE      = FourCC<'D', 'F', 'A', 'N'>::value;  // Payload: DX_DUMP_FILE_DRED_ALLOCATION_NODE1 (freed allocations)

// Memory buffer type FourCC constants.
// These identify the typed content within MEMORY_BUFFER sections.
// Match against DX_DUMP_FILE_MEM_HEADER.MemType after reading a MEMORY_BUFFER section.
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_APP_BLOB                                  = FourCC<'A', 'p', 'B', 'l'>::value;    // Application blobs (opaque app-provided debug data)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_KMD_BLOB                                  = FourCC<'K', 'm', 'B', 'l'>::value;    // Kernel mode driver collected GPU debug blob (IHV-specific format)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_UMD_BLOB                                  = FourCC<'U', 'm', 'B', 'l'>::value;    // User mode driver collected GPU debug blob (IHV-specific format)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_DRED_A_STR                                = FourCC<'D', 'R', 'A', 'S'>::value;    // DRED ASCII string (Key = original runtime pointer)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_DRED_W_STR                                = FourCC<'D', 'R', 'W', 'S'>::value;    // DRED Unicode string (Key = original runtime pointer)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_DRED_CMD_HSTR                             = FourCC<'D', 'C', 'H', 'R'>::value;    // DRED command history: array of D3D12_AUTO_BREADCRUMB_OP (Key = original pointer)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_DRED_BRDC_CTX                             = FourCC<'D', 'B', 'C', 'C'>::value;    // DRED breadcrumb context: array of DX_DUMP_FILE_DRED_BREADCRUMB_CONTEXT (Key = original pointer)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_JOURNAL                               = FourCC<'D', '3', 'J', 'R'>::value;    // D3D journal: array of DX_DUMP_FILE_D3D_JOURNAL_ENTRY (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DEVICE                         = FourCC<'D', 'D', 'v', '0'>::value;    // DX_DUMP_FILE_D3D_OBJECT_DEVICE (single instance)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DEVICE1                        = FourCC<'D', 'D', 'v', '1'>::value;    // DX_DUMP_FILE_D3D_OBJECT_DEVICE1 (single instance)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_RESOURCES                      = FourCC<'D', 'R', 's', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_RESOURCE (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_ROOT_SIGNATURE_BLOBS           = FourCC<'D', 'R', 'S', '0'>::value;    // Index table + blob: DX_DUMP_FILE_D3D_OBJECT_ROOT_SIGNATURE[] + serialized blobs (Key = entry count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_DESCRIPTOR_HEAPS               = FourCC<'D', 'D', 'H', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_DESCRIPTOR_HEAP (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_HEAPS                          = FourCC<'D', 'H', 'p', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_HEAP (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_FENCES                         = FourCC<'D', 'F', 'n', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_FENCE (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_QUEUES                 = FourCC<'D', 'C', 'Q', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_COMMAND_QUEUE (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_LISTS                  = FourCC<'D', 'C', 'L', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_COMMAND_LIST (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_COMMAND_ALLOCATORS             = FourCC<'D', 'C', 'A', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_COMMAND_ALLOCATOR (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_GENERICS                       = FourCC<'D', 'G', 'O', '0'>::value;    // Array of DX_DUMP_FILE_D3D_OBJECT_GENERIC (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_LEGACY_PIPELINE_STATES         = FourCC<'D', 'P', 'S', '0'>::value;    // Index table + blob: DX_DUMP_FILE_D3D_OBJECT_WITH_SUBOBJECTS[] + subobject data (Key = entry count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_D3D_OBJECT_STATE_OBJECTS                  = FourCC<'D', 'S', 'O', '0'>::value;    // Index table + blob: DX_DUMP_FILE_D3D_OBJECT_WITH_SUBOBJECTS[] + subobject data (Key = entry count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_APP_ANNOTATIONS                           = FourCC<'A', 'p', 'A', 'n'>::value;    // Array of DX_DUMP_FILE_APP_ANNOTATION (Key = count)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_APP_ANNOTATION_DATA                       = FourCC<'A', 'A', 'D', 'T'>::value;    // Opaque annotation data blob (Key = annotation ID)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_APP_COMMAND_QUEUE_ANNOTATION_ID_MAP       = FourCC<'A', 'A', 'C', 'Q'>::value;    // DX_DUMP_FILE_APP_ANNOTATION_ID_MAP + UINT64[] annotation IDs (for command queues)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_APP_COMMAND_ALLOCATOR_ANNOTATION_ID_MAP   = FourCC<'A', 'A', 'C', 'A'>::value;    // DX_DUMP_FILE_APP_ANNOTATION_ID_MAP + UINT64[] annotation IDs (for command allocators)
static constexpr UINT32 DX_DUMP_FILE_MEM_TYPE_W_STR                                     = FourCC<'W', 'S', 'T', 'R'>::value;    // Interned Unicode string (Key = string ID)

}
