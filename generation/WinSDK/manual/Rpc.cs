using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Rpc
{
    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    public unsafe delegate void* PFN_RPC_ALLOCATE([NativeTypeName("size_t")] UIntPtr param0);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    public unsafe delegate void PFN_RPC_FREE(void* param0);
}