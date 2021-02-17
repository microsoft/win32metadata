// Copyright © Microsoft
using System;
using System.Runtime.InteropServices;

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

        [DllImport("HID", ExactSpelling = true)]
        [return: NativeTypeName("NTSTATUS")]
        public static extern int HidP_InitializeReportForID([CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] HIDP_REPORT_TYPE ReportType, [NativeTypeName("UCHAR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] byte ReportID, [NativeTypeName("PHIDP_PREPARSED_DATA")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] IntPtr PreparsedData, [NativeTypeName("PCHAR")][CppAttributeList("Name=SAL_name; p1=\"_Out_writes_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=byteCount(ReportLength)^Name=SAL_end^Name=SAL_post^Name=SAL_valid")] sbyte* Report, [NativeTypeName("ULONG")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint ReportLength);

        [DllImport("MyDll", ExactSpelling = true, SetLastError = true)]
        public static extern int StringFunc([NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] ushort* szName, [NativeTypeName("LPWSTR")] sbyte* szFillMe, [NativeTypeName("DWORD")] uint dwLen);

        [DllImport("USER32", ExactSpelling = true, SetLastError = true)]
        public static extern int GetWindowTextA([NativeTypeName("HWND")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] IntPtr hWnd, [NativeTypeName("LPSTR")][CppAttributeList("Name=SAL_name; p1=\"_Out_writes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_cap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(nMaxCount)^Name=SAL_end^Name=SAL_post^Name=SAL_valid")] sbyte* lpString, [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] int nMaxCount);

        [DllImport("MyDll", ExactSpelling = true, SetLastError = true)]
        public static extern int MyFunc(uint x);
    }
}
