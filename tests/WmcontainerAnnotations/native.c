#include <windows.h>
#include <wmcontainer.h>

typedef HRESULT (STDMETHODCALLTYPE *SplitterGetNextSample)(IMFASFSplitter*, DWORD*, WORD*, IMFSample**);
_Static_assert(__builtin_types_compatible_p(__typeof__(((IMFASFSplitterVtbl*)0)->GetNextSample), SplitterGetNextSample), "GetNextSample must keep its native C vtable signature");
_Static_assert(sizeof(ASF_STATUSFLAGS) == sizeof(DWORD), "ASF_STATUSFLAGS storage changed");
_Static_assert(ASF_STATUSFLAGS_INCOMPLETE == 1, "ASF_STATUSFLAGS_INCOMPLETE changed");
_Static_assert(ASF_STATUSFLAGS_NONFATAL_ERROR == 2, "ASF_STATUSFLAGS_NONFATAL_ERROR changed");
