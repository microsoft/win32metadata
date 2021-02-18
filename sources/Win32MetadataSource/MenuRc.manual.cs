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

    [Flags]
    public enum DI_FLAGS : uint
    {
        DI_MASK = 0x0001,
        DI_IMAGE = 0x0002,
        DI_NORMAL = 0x0003,
        DI_COMPAT = 0x0004,
        DI_DEFAULTSIZE = 0x0008,
        DI_NOMIRROR = 0x0010,
    }
}
