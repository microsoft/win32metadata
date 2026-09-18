#include <windows.h>
#include <wmcontainer.h>

#ifdef CINTERFACE
using SplitterGetNextSample = HRESULT (STDMETHODCALLTYPE *)(IMFASFSplitter*, DWORD*, WORD*, IMFSample**);
static_assert(__is_same(decltype(IMFASFSplitterVtbl::GetNextSample), SplitterGetNextSample));
#else
using SplitterGetNextSample = HRESULT (STDMETHODCALLTYPE IMFASFSplitter::*)(DWORD*, WORD*, IMFSample**);
static_assert(__is_same(decltype(&IMFASFSplitter::GetNextSample), SplitterGetNextSample));
#endif

static_assert(sizeof(ASF_STATUSFLAGS) == sizeof(DWORD));
static_assert(ASF_STATUSFLAGS_INCOMPLETE == 1);
static_assert(ASF_STATUSFLAGS_NONFATAL_ERROR == 2);
