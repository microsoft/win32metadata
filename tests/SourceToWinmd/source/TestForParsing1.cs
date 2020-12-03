using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32.Interop;

namespace Test
{
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int MYCALLBACK();

    public unsafe partial struct MyCallbackStruct
    {
        [NativeTypeName("MYCALLBACK")]
        public IntPtr MyCallback;
    }

    public static unsafe partial class Apis
    {
        [DllImport("SHLWAPI", ExactSpelling = true)]
        [return: NativeTypeName("LPCWSTR")]
        public static extern ushort* PathFindSuffixArrayW([NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] ushort* pszPath, [NativeTypeName("const LPCWSTR *")][CppAttributeList("Name=SAL_name; p1=\"_In_reads_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_count_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_readableTo; p1=elementCount(iArraySize)^Name=SAL_valid^Name=SAL_end^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1")] ushort** apszSuffix, [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] int iArraySize);

        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("BOOL")]
        public static extern int FuncUsingCallback([NativeTypeName("MYCALLBACK")] IntPtr myCallBack);
    }

    public struct NestedTest
    {
        public enum NestedEnum
        {
            X,
            Y,
            Z
        }

        NestedEnum n1;
    }

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int MYCALLBACK();

    public unsafe partial struct MyCallbackStruct
    {
        [NativeTypeName("MYCALLBACK")]
        public IntPtr MyCallback;
    }

    public enum Enum1
    {
        A,
        B,
        C
    }

    public struct S2
    {
        int x;
        Sub sub;

        [NativeTypeName("LPCWSTR")]
        public ushort* lpSource;

        public struct Sub
        {
            int z;
        }
    }

    public struct S1
    {
        S2 s2;
        IntPtr addRIAAToMe;
        int changeToEnum;
    }
}

