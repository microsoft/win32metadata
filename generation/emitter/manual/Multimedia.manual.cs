using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Multimedia
{
    // We need to define this manually because of how it's defined with duplicate typedefs
    [UnmanagedFunctionPointer]
    public delegate void LPWAVECALLBACK([NativeTypeName("HDRVR")] IntPtr hdrvr, [NativeTypeName("UINT")] uint uMsg, [NativeTypeName("DWORD_PTR")] UIntPtr dwUser, [NativeTypeName("DWORD_PTR")] UIntPtr dw1, [NativeTypeName("DWORD_PTR")] UIntPtr dw2);

    // We need to define this manually because of how it's defined with duplicate typedefs
    [UnmanagedFunctionPointer]
    public delegate void LPMIDICALLBACK([NativeTypeName("HDRVR")] IntPtr hdrvr, [NativeTypeName("UINT")] uint uMsg, [NativeTypeName("DWORD_PTR")] UIntPtr dwUser, [NativeTypeName("DWORD_PTR")] UIntPtr dw1, [NativeTypeName("DWORD_PTR")] UIntPtr dw2);
}
