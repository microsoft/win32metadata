using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32.Interop;

namespace Foobar
{
    //[Guid("00000000-0000-0000-C000-000000000046")]
    //public unsafe partial struct UsesEnum1
    //{
    //    public Enum1 MyVar;
    //}

    public static unsafe partial class Apis
    {
        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("HANDLE")]
        [return: RIAAFree("CloseHandle")]
        public static extern IntPtr Foobar([NativeTypeName("LPCWSTR")][Const][NativeTypeInfo(UnmanagedType.LPWStr, IsNullTerminated = true)][In] ushort* lpFileName);
    }
}

