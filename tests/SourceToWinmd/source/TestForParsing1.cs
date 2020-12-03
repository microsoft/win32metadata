using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32.Interop;

namespace Test
{
    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("HANDLE")]
    public unsafe delegate IntPtr MyOtherCallback([NativeTypeName("DWORD")] uint dwRetypeMeToo);

    public static unsafe partial class Apis
    {
        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("HANDLE")]
        public static extern IntPtr TestFunc([NativeTypeName("DWORD")] uint dwRetypeMe, [NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] ushort* lpFileName);

        [DllImport("SHLWAPI", ExactSpelling = true)]
        [return: NativeTypeName("LPCWSTR")]
        public static extern ushort* PathFindSuffixArrayW([NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] ushort* pszPath, [NativeTypeName("const LPCWSTR *")][CppAttributeList("Name=SAL_name; p1=\"_In_reads_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_count_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_readableTo; p1=elementCount(iArraySize)^Name=SAL_valid^Name=SAL_end^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1")] ushort** apszSuffix, [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] int iArraySize);

        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("BOOL")]
        public static extern int FuncUsingCallback([NativeTypeName("MYCALLBACK")] IntPtr myCallBack);
    }

    [Guid("51973C51-CB0C-11D0-B5C9-00A0244A0E7A")]
    [NativeTypeName("struct IEnumTest")]
    public unsafe partial struct IEnumTest
    {
        public void** lpVtbl;

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Next(IEnumTest* pThis, [NativeTypeName("ULONG")] uint celt, [NativeTypeName("S2 *")] S2* pi, [NativeTypeName("ULONG *")] uint* pcEltsfetched);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Skip(IEnumTest* pThis, [NativeTypeName("ULONG")] uint celt);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Reset(IEnumTest* pThis);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _Clone(IEnumTest* pThis, [NativeTypeName("IEnumTest **")][CppAttributeList("Name=SAL_name; p1=\"__RPC__deref_out_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__deref_out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end")] IEnumTest** ppepi);

        [UnmanagedFunctionPointer(CallingConvention.Winapi)]
        [return: NativeTypeName("HRESULT")]
        public delegate int _GetCount(IEnumTest* pThis, [NativeTypeName("ULONG *")][CppAttributeList("Name=SAL_name; p1=\"__RPC__out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] uint* pcelt);

        [return: NativeTypeName("HRESULT")]
        public int Next([NativeTypeName("ULONG")] uint celt, [NativeTypeName("S2 *")] S2* pi, [NativeTypeName("ULONG *")] uint* pcEltsfetched)
        {
            fixed (IEnumTest* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Next>((IntPtr)(lpVtbl[3]))(pThis, celt, pi, pcEltsfetched);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Skip([NativeTypeName("ULONG")] uint celt)
        {
            fixed (IEnumTest* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Skip>((IntPtr)(lpVtbl[4]))(pThis, celt);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Reset()
        {
            fixed (IEnumTest* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Reset>((IntPtr)(lpVtbl[5]))(pThis);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int Clone([NativeTypeName("IEnumTest **")][CppAttributeList("Name=SAL_name; p1=\"__RPC__deref_out_opt\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"__RPC__deref_out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_name; p1=\"_Outptr_\"; p2=\"\"; p3=\"2\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_deref^Name=SAL_readableTo; p1=elementCount(1)^Name=SAL_end")] IEnumTest** ppepi)
        {
            fixed (IEnumTest* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_Clone>((IntPtr)(lpVtbl[6]))(pThis, ppepi);
            }
        }

        [return: NativeTypeName("HRESULT")]
        public int GetCount([NativeTypeName("ULONG *")][CppAttributeList("Name=SAL_name; p1=\"__RPC__out\"; p2=\"\"; p3=\"1.2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] uint* pcelt)
        {
            fixed (IEnumTest* pThis = &this)
            {
                return Marshal.GetDelegateForFunctionPointer<_GetCount>((IntPtr)(lpVtbl[7]))(pThis, pcelt);
            }
        }
    }

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    [return: NativeTypeName("BOOL")]
    public unsafe delegate int MYCALLBACK([NativeTypeName("DWORD")] uint dwRetypeMeToo);

    public unsafe partial struct MyCallbackStruct
    {
        [NativeTypeName("MYCALLBACK")]
        public IntPtr MyCallback;
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
        [NativeTypeName("DWORD")]
        uint addRIAAToMeMakeMeIntPtrAndChangeMyName;
        [NativeTypeName("DWORD")]
        uint changeToEnum;
    }
}

