// Copyright © Microsoft
using System;
using System.Runtime.InteropServices;

using Windows.Win32.Foundation;
using Windows.Win32.System.Memory;

using Windows.Win32.Interop;

namespace Windows.Win32.Test
{
    public enum MyEnum
    {
        A,
        B,
        C
    }

    public struct MyStruct
    {
        public uint X;
    }

    public static unsafe partial class Apis
    {
		public const string NormalConst = "my const value";
        //public static readonly Guid CLSID_Guid1 = new Guid(0x2CD90691, 0x12E2, 0x11DC, 0x9F, 0xED, 0x00, 0x11, 0x43, 0xA0, 0x55, 0xF9);
        //public static readonly Guid CLSID_Guid2 = new Guid("00000000-0000-0000-C000-000000000046");

        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("SIZE_T")]
        public static extern UIntPtr VirtualQueryEx([NativeTypeName("HANDLE")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] IntPtr hProcess, [NativeTypeName("LPCVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_opt_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__maybe^Name=SAL_valid^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void* lpAddress, [NativeTypeName("PMEMORY_BASIC_INFORMATION")][CppAttributeList("Name=SAL_name; p1=\"_Out_writes_bytes_to_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=byteCount(dwLength)^Name=SAL_end^Name=SAL_post^Name=SAL_valid^Name=SAL_name; p1=\"_Post_bytecount_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_readableTo; p1=byteCount(return)")] MEMORY_BASIC_INFORMATION* lpBuffer, [NativeTypeName("SIZE_T")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] UIntPtr dwLength);

        [DllImport("OLEAUT32", ExactSpelling = true)]
        [return: NativeTypeName("BSTR")]
        public static extern ushort* SysAllocString([NativeTypeName("const OLECHAR *")][CppAttributeList("Name=SAL_name; p1=\"_In_opt_z_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_In_opt_\"; p2=\"\"; p3=\"2\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__maybe^Name=SAL_valid^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end^Name=SAL_nullTerminated; p1=__yes")] ushort* psz);

        [DllImport("OLEAUT32", ExactSpelling = true)]
        public static extern void SysFreeString([NativeTypeName("BSTR")] [CppAttributeList("Name=SAL_name; p1=\"_In_opt_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__maybe^Name=SAL_valid^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] ushort* bstrString);

        [DllImport("MyDll", ExactSpelling = true, SetLastError = true)]
        public static extern int StringFunc([NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] ushort* szName, [NativeTypeName("LPWSTR")] sbyte* szFillMe, [NativeTypeName("DWORD")] uint dwLen);

        [DllImport("USER32", ExactSpelling = true, SetLastError = true)]
        public static extern int GetWindowTextA([NativeTypeName("HWND")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] IntPtr hWnd, [NativeTypeName("LPSTR")][CppAttributeList("Name=SAL_name; p1=\"_Out_writes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_cap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(nMaxCount)^Name=SAL_end^Name=SAL_post^Name=SAL_valid")] sbyte* lpString, [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] int nMaxCount);

        [DllImport("MyDll", ExactSpelling = true, SetLastError = true)]
        public static extern int MyFunc(uint x);
    }
}
