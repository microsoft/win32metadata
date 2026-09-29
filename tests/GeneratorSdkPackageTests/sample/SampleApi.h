#pragma once

#include <sal.h>

#include "DependencyConstants.h"
#include "win32metadata_annotations.h"

typedef void* SAMPLE_HANDLE;
typedef const char* PCSTR;

#include "CleanupApi.h"
#include "Redeclarations.h"
#include "SupportedOsApi.h"

enum _Win32_AssociatedConstant_(SAMPLE_MODE_EXTERNAL) SAMPLE_MODE : unsigned long
{
    SAMPLE_MODE_NONE = 0,
    SAMPLE_MODE_FAST = 1,
};

#define SAMPLE_INVALID_HANDLE ((SAMPLE_HANDLE)(__int64)-1)

_Win32_RAIIFree_(SampleCloseHandle, SAMPLE_INVALID_HANDLE, 0)
typedef SAMPLE_HANDLE SAMPLE_RESOURCE_HANDLE;

_Win32_AlsoUsableFor_(SAMPLE_HANDLE)
typedef SAMPLE_RESOURCE_HANDLE SAMPLE_COMPAT_HANDLE;

typedef struct SAMPLE_POINT
{
    int x;
    int y;
} SAMPLE_POINT;

class SAMPLE_PROPERTY
{
public:
    unsigned long id;
    void* value;
};

typedef long HRESULT;

typedef int (__stdcall SAMPLE_CALLBACK)(int code);
typedef SAMPLE_CALLBACK* PSAMPLE_CALLBACK;

typedef struct SAMPLE_CALLBACKS
{
    PSAMPLE_CALLBACK chained;
    PSAMPLE_CALLBACK* pointer;
    int (__stdcall *anonymous)(int code);
} SAMPLE_CALLBACKS;

typedef struct SAMPLE_ARRAYS
{
    const unsigned char bytes[4];
    int values[3];
} SAMPLE_ARRAYS;

#pragma pack(push, 2)
typedef struct __declspec(align(8)) SAMPLE_PACKED
{
    char tag;
    int value;
} SAMPLE_PACKED;
#pragma pack(pop)

#if defined(_M_IX86)
typedef struct SAMPLE_ARCH_VALUE
{
    int value;
} SAMPLE_ARCH_VALUE;
#else
typedef struct SAMPLE_ARCH_VALUE
{
    __int64 value;
} SAMPLE_ARCH_VALUE;
#endif

struct __declspec(uuid("12345678-1234-1234-1234-123456789abc")) ISampleFactory
{
    virtual HRESULT __stdcall Create(_COM_Outptr_retval_ void** value) = 0;

    _Win32_PreserveResult_
    virtual HRESULT __stdcall TryCreate(_COM_Outptr_ void** value) = 0;
};

extern "C" _Win32_SetLastError_
    _Win32_ImportLibrary_("sampleapi.dll")
    _Windows_SupportedOS_19041_662_
    int SampleAdd(int left, int right);

extern "C" _Win32_PreserveResult_
    HRESULT SamplePreservedResult(void);

extern "C" _Win32_AssociatedEnum_(SAMPLE_MODE)
    unsigned long SampleGetMode(
        _Win32_AssociatedEnum_(SAMPLE_MODE) unsigned long fallback);

extern "C" _Win32_RAIIFree_(SampleCloseHandle, SAMPLE_INVALID_HANDLE, 0)
    SAMPLE_HANDLE SampleOpenHandle(void);

extern "C" int SampleCreateHandle(
    _Out_ _Win32_RAIIFree_(SampleCloseHandle, SAMPLE_INVALID_HANDLE, 0)
        SAMPLE_HANDLE* result);

extern "C" void SampleUseHandle(
    _In_ _Win32_Retained_ SAMPLE_HANDLE handle);

extern "C" _Win32_ImportLibrary_("samplemerged.dll")
    _Windows_SupportedOS_Windows7_
    int SampleMergedContract(void* buffer, unsigned long length);

extern "C" void SampleBuffers(
    _In_reads_(elementCount) const int* values,
    unsigned long elementCount,
    _In_reads_bytes_(byteCount) const void* bytes,
    unsigned long byteCount,
    _In_z_ const char* terminated,
    const char* raw
        _WIN32META_ANNOTATION_("win32metadata:not_null_terminated"),
    const char* multistring
        _WIN32META_ANNOTATION_("win32metadata:not_null_terminated")
        _WIN32META_ANNOTATION_("win32metadata:null_null_terminated"));

#if defined(_M_IX86)
extern "C" int SampleX86Only(void);
#else
extern "C" __int64 SampleWideOnly(void);
#endif
