#if CAPTURE_INCLUDE_ORDER == 0
#include <sal.h>
#include <specstrings.h>
#include <specstrings_strict.h>
#elif CAPTURE_INCLUDE_ORDER == 1
#include <specstrings_strict.h>
#include <sal.h>
#include <specstrings.h>
#else
#include <windows.h>
#include <specstrings.h>
#include <sal.h>
#endif

#if __SPECSTRINGS_STRICT_LEVEL != 1
#error This regression must not disable the SDK strict annotation layer.
#endif

typedef void* CAPTURE_HANDLE;
typedef CAPTURE_HANDLE CAPTURE_LOCAL;
typedef CAPTURE_HANDLE* CAPTURE_HANDLE_PTR;
#if CAPTURE_INCLUDE_ORDER != 2
typedef const wchar_t* PCWSTR;
typedef void* LPVOID;
typedef void* PVOID;
#endif

extern "C" {
void CaptureOutptrAlias(_Outptr_ CAPTURE_HANDLE_PTR value);
void CaptureOutAlias(_Out_ CAPTURE_HANDLE_PTR value);
void CaptureOutptrDirect(_Outptr_ CAPTURE_HANDLE* value);
void CaptureOutDirect(_Out_ CAPTURE_HANDLE* value);
void CaptureFreesOptional(_Frees_ptr_opt_ CAPTURE_LOCAL value);
void CaptureFreesRequired(_Frees_ptr_ CAPTURE_LOCAL value);
void CaptureInOptional(_In_opt_ CAPTURE_LOCAL value);
void CaptureUnannotated(CAPTURE_LOCAL value);
void CaptureDoubleNull(
    _Out_writes_to_opt_(capacity, *length) _Post_ _NullNull_terminated_ wchar_t* value,
    unsigned int capacity,
    _Out_ unsigned int* length);
void CaptureDoubleNullOnly(_NullNull_terminated_ wchar_t* value);
void CapturePostOnly(_Post_ wchar_t* value);
void CaptureSingleNull(_In_z_ const wchar_t* value);
void CaptureCounted(_In_reads_(count) const int* value, unsigned int count);
void CaptureBinary(_Out_writes_bytes_(count) void* value, unsigned int count);
LPVOID CaptureRetainLpvoid(LPVOID const* value);
PVOID CaptureRetainPvoid(PVOID const* value);
void CaptureNamedLpvoidInput(_In_ LPVOID value);
void CaptureNamedPvoidInput(_In_ PVOID value);
void CaptureNamedLpvoidOutput(
    _Out_writes_bytes_to_(count, *written) LPVOID value,
    unsigned int count,
    _Out_opt_ unsigned int* written);
void CaptureNamedPvoidOutput(
    _Out_writes_bytes_to_(count, *written) PVOID value,
    unsigned int count,
    _Out_opt_ unsigned int* written);
}
