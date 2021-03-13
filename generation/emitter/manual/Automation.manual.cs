using System;
using System.Runtime.InteropServices;

using Windows.Win32.Com;

namespace Windows.Win32.Automation
{
    // For EXCEPINFO::pfnDeferredFillIn which defines the callback inline with the struct.
    // ClangSharp emits function pointers as IntPtr so we need to write our own signature
    // for the metadata
    [UnmanagedFunctionPointer]
    public unsafe delegate HRESULT LPEXCEPFINO_DEFERRED_FILLIN(EXCEPINFO *pExcepInfo);
}
