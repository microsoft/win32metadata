using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Iis
{
    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_IIS_GETSERVERVARIABLE([NativeTypeName("HCONN")] void* param0, [NativeTypeName("LPSTR")] sbyte* param1, void* param2, uint* param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_IIS_WRITECLIENT([NativeTypeName("HCONN")] void* param0, void* param1, uint* param2, uint param3);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_IIS_READCLIENT([NativeTypeName("HCONN")] void* param0, void* param1, uint* param2);

    [UnmanagedFunctionPointer(CallingConvention.Winapi))]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int PFN_IIS_SERVERSUPPORTFUNCTION([NativeTypeName("HCONN")] void* param0, uint param1, void* param2, uint* param3, uint* param4);
}
