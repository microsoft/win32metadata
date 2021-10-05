#include "pch.h"
#include "SampleHeader.h"

DLL_DECLSPEC BOOL WINAPI SampleFunction1(
    _In_ SAMPLE_HANDLE, /* handle1 */
    _Inout_ PSAMPLE_HANDLE, /* pHandle2 */
    DWORD /*dwOptions */)
{
    return TRUE;
}

DLL_DECLSPEC SAMPLE_HANDLE WINAPI SampleFunction2(
    _In_ OTHER_SAMPLE_HANDLE /*handle1*/,
    _Inout_ PSAMPLE_HANDLE /*pHandle2*/,
    _In_ RENAME_ME* /*pRename1*/,
    _Inout_ PRENAME_ME /*pRename2*/)
{
    return nullptr;
}

DLL_DECLSPEC void WINAPI CloseSampleHandle(
    _In_ SAMPLE_HANDLE /*handle*/)
{

}

DLL_DECLSPEC void WINAPI SampleCallMe1(
    _In_ LPSAMPLECALLBACK /*callback*/)
{
}

DLL_DECLSPEC void WINAPI SampleCallMe2(
    _In_ LPALREADYPTR_SAMPLECALLBACK /*callback*/)
{
}
