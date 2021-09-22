using System;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;
using Windows.Win32.System.PropertiesSystem; // For PROPERTYKEY
using Windows.Win32.System.SystemServices;
using static Windows.Win32.Foundation.Apis; // Various constants
using static Windows.Win32.System.Diagnostics.Debug.WIN32_ERROR;
using static Windows.Win32.System.SystemServices.Apis; // Various constants
using static Windows.Win32.Media.Multimedia.Apis; // Various constants
using static Windows.Win32.Media.Audio.CoreAudio.Apis; // Various constants
using static Windows.Win32.Graphics.DirectShow.Apis; // Various constants
using static Windows.Win32.UI.WindowsAndMessaging.Apis; // For WM_USER
using static Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS; // For FILE_* constants
using static Windows.Win32.System.Diagnostics.Debug.FACILITY_CODE; // For MAKE_HRESULT constants


using static Windows.Win32.System.Memory.Apis;

namespace Windows.Win32.System.Memory
{
    [Flags]
    public enum FILE_MAP : uint
    {
        FILE_MAP_WRITE = SECTION_FLAGS.SECTION_MAP_WRITE,
        FILE_MAP_READ = SECTION_FLAGS.SECTION_MAP_READ,
        FILE_MAP_ALL_ACCESS = SECTION_FLAGS.SECTION_ALL_ACCESS,
        FILE_MAP_EXECUTE = SECTION_FLAGS.SECTION_MAP_EXECUTE_EXPLICIT,
        FILE_MAP_COPY = 0x00000001,
        FILE_MAP_RESERVE = 0x80000000,
        FILE_MAP_TARGETS_INVALID = 0x40000000,
        FILE_MAP_LARGE_PAGES = 0x20000000,
    }

    [Flags]
    public enum HEAP_FLAGS : uint
    {
        HEAP_NONE = 0x00000000,
        HEAP_NO_SERIALIZE = 0x00000001,
        HEAP_GROWABLE = 0x00000002,
        HEAP_GENERATE_EXCEPTIONS = 0x00000004,
        HEAP_ZERO_MEMORY = 0x00000008,
        HEAP_REALLOC_IN_PLACE_ONLY = 0x00000010,
        HEAP_TAIL_CHECKING_ENABLED = 0x00000020,
        HEAP_FREE_CHECKING_ENABLED = 0x00000040,
        HEAP_DISABLE_COALESCE_ON_FREE = 0x00000080,
        HEAP_CREATE_ALIGN_16 = 0x00010000,
        HEAP_CREATE_ENABLE_TRACING = 0x00020000,
        HEAP_CREATE_ENABLE_EXECUTE = 0x00040000,
        HEAP_MAXIMUM_TAG = 0x0FFF,
        HEAP_PSEUDO_TAG_FLAG = 0x8000,
        HEAP_TAG_SHIFT = 18,
        HEAP_CREATE_SEGMENT_HEAP = 0x00000100,
        HEAP_CREATE_HARDENED = 0x00000200,
    }

    [Flags]
    public enum PAGE_PROTECTION_FLAGS : uint
    {
        PAGE_NOACCESS = 0x01,
        PAGE_READONLY = 0x02,
        PAGE_READWRITE = 0x04,
        PAGE_WRITECOPY = 0x08,
        PAGE_EXECUTE = 0x10,
        PAGE_EXECUTE_READ = 0x20,
        PAGE_EXECUTE_READWRITE = 0x40,
        PAGE_EXECUTE_WRITECOPY = 0x80,
        PAGE_GUARD = 0x100,
        PAGE_NOCACHE = 0x200,
        PAGE_WRITECOMBINE = 0x400,
        PAGE_GRAPHICS_NOACCESS = 0x0800,
        PAGE_GRAPHICS_READONLY = 0x1000,
        PAGE_GRAPHICS_READWRITE = 0x2000,
        PAGE_GRAPHICS_EXECUTE = 0x4000,
        PAGE_GRAPHICS_EXECUTE_READ = 0x8000,
        PAGE_GRAPHICS_EXECUTE_READWRITE = 0x10000,
        PAGE_GRAPHICS_COHERENT = 0x20000,
        PAGE_GRAPHICS_NOCACHE = 0x40000,
        PAGE_ENCLAVE_THREAD_CONTROL = 0x80000000,
        PAGE_REVERT_TO_FILE_MAP = 0x80000000,
        PAGE_TARGETS_NO_UPDATE = 0x40000000,
        PAGE_TARGETS_INVALID = 0x40000000,
        PAGE_ENCLAVE_UNVALIDATED = 0x20000000,
        PAGE_ENCLAVE_MASK = 0x10000000,
        PAGE_ENCLAVE_DECOMMIT = (PAGE_ENCLAVE_MASK | 0),
        PAGE_ENCLAVE_SS_FIRST = (PAGE_ENCLAVE_MASK | 1),
        PAGE_ENCLAVE_SS_REST = (PAGE_ENCLAVE_MASK | 2),
        SEC_PARTITION_OWNER_HANDLE = 0x00040000,
        SEC_64K_PAGES = 0x00080000,
        SEC_FILE = 0x00800000,
        SEC_IMAGE = 0x01000000,
        SEC_PROTECTED_IMAGE = 0x02000000,
        SEC_RESERVE = 0x04000000,
        SEC_COMMIT = 0x08000000,
        SEC_NOCACHE = 0x10000000,
        SEC_WRITECOMBINE = 0x40000000,
        SEC_LARGE_PAGES = 0x80000000,
        SEC_IMAGE_NO_EXECUTE = (SEC_IMAGE | SEC_NOCACHE),
    }

    public enum UNMAP_VIEW_OF_FILE_FLAGS : uint
    {
        MEM_UNMAP_NONE = 0,
        MEM_UNMAP_WITH_TRANSIENT_BOOST = 1,
        MEM_PRESERVE_PLACEHOLDER = 2,
    }

    public enum VIRTUAL_FREE_TYPE : uint
    {
        MEM_DECOMMIT = 16384,
        MEM_RELEASE = 32768,
    }

    [Flags]
    public enum VIRTUAL_ALLOCATION_TYPE : uint
    {
        MEM_COMMIT = 4096,
        MEM_RESERVE = 8192,
        MEM_RESET = 524288,
        MEM_RESET_UNDO = 16777216,
        MEM_REPLACE_PLACEHOLDER = 16384,
        MEM_LARGE_PAGES = 536870912,
        MEM_RESERVE_PLACEHOLDER = 262144,
        MEM_FREE = 65536,
    }

    [Flags]
    public enum LOCAL_ALLOC_FLAGS : uint
    {
        LHND = 66,
        LMEM_FIXED = 0,
        LMEM_MOVEABLE = 2,
        LMEM_ZEROINIT = 64,
        LPTR = 64,
        NONZEROLHND = (LMEM_MOVEABLE),
        NONZEROLPTR = (LMEM_FIXED),
    }

    [Flags]
    public enum GLOBAL_ALLOC_FLAGS : uint
    {
        GHND = 66,
        GMEM_FIXED = 0,
        GMEM_MOVEABLE = 2,
        GMEM_ZEROINIT = 64,
        GPTR = 64,
    }

    [Flags]
    public enum PAGE_TYPE : uint
    {
        MEM_PRIVATE = 0x00020000,
        MEM_MAPPED = 0x00040000,
        MEM_IMAGE = 0x01000000,
    }

}
