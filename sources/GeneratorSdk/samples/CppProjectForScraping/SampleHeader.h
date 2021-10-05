#pragma once

#include "framework.h"

DECLARE_HANDLE(SAMPLE_HANDLE);
typedef SAMPLE_HANDLE* PSAMPLE_HANDLE;

typedef LPVOID OTHER_SAMPLE_HANDLE;
typedef OTHER_SAMPLE_HANDLE* POTHER_SAMPLE_HANDLE;

typedef struct tagRENAME_ME
{
    int x;
    int y;
#if defined(_X86_)
    int x86;
#endif
#if defined(_AMD64_)
    int x64;
#endif
#if defined(_ARM64_)
    int arm64;
#endif
} RENAME_ME, *PRENAME_ME;

struct IGNORE_ME
{
    int unused;
};

enum OTHER_OPTIONS
{
    OTHER_OPTIONS_1 = 1,
    OTHER_OPTIONS_2 = 2,
    OTHER_OPTIONS_4 = 4,
};

enum ScopeMe
{
    A,
    B,
    C
};

DEFINE_GUID(IID_IFoobar, 0xdeadbeef, 0x64d4, 0x426d, 0xae, 0x8d, 0xad, 0x1, 0x47, 0xf4, 0x27, 0x5c);

typedef void (CALLBACK SAMPLECALLBACK)();
typedef SAMPLECALLBACK FAR* LPSAMPLECALLBACK;

typedef void (CALLBACK *ALREADYPTR_SAMPLECALLBACK)();
typedef ALREADYPTR_SAMPLECALLBACK LPALREADYPTR_SAMPLECALLBACK;

#define SAMPLE_FUNC_OPTION_1 1
#define SAMPLE_FUNC_OPTION_2 2
#define SAMPLE_FUNC_OPTION_4 4

#define MY_SHORT_CONST 0xffff

DLL_DECLSPEC BOOL WINAPI SampleFunction1(_In_ SAMPLE_HANDLE handle1, _Inout_ PSAMPLE_HANDLE pHandle2, DWORD dwOptions);
DLL_DECLSPEC SAMPLE_HANDLE WINAPI SampleFunction2(_In_ OTHER_SAMPLE_HANDLE handle1, _Inout_ PSAMPLE_HANDLE pHandle2, _In_ RENAME_ME* pRename1, _Inout_ PRENAME_ME pRename2);
DLL_DECLSPEC void WINAPI CloseSampleHandle(_In_ SAMPLE_HANDLE handle);

DLL_DECLSPEC void WINAPI SampleCallMe1(_In_ LPSAMPLECALLBACK callback);
DLL_DECLSPEC void WINAPI SampleCallMe2(_In_ LPALREADYPTR_SAMPLECALLBACK callback);

interface IOverloads : public IUnknown
{
    virtual HRESULT A(int a);
    virtual HRESULT B(int b);
    virtual HRESULT C(int c);
    virtual HRESULT C(int a, int c);
    virtual HRESULT B(int a, int b);
    virtual HRESULT B(int a, int b, int c);
    virtual HRESULT A(int a, int b, int c);
};

// This should get skipped in favor of the manual one
#define MANUAL_CONST_1 101

#define OTHER_CONST 202

