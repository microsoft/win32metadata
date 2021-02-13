using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.MenusAndResources
{
    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int WINSTAENUMPROCA([NativeTypeName("LPSTR")] sbyte* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int WINSTAENUMPROCW([NativeTypeName("LPWSTR")] ushort* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int DESKTOPENUMPROCA([NativeTypeName("LPSTR")] sbyte* param0, [NativeTypeName("LPARAM")] IntPtr param1);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int DESKTOPENUMPROCW([NativeTypeName("LPWSTR")] ushort* param0, [NativeTypeName("LPARAM")] IntPtr param1);
}
