using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32.Interop;

namespace Test
{
    public static unsafe partial class Apis
    {
        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("BOOL")]
        public static extern int AnotherFunc();

        [DllImport("KERNEL32", ExactSpelling = true, SetLastError = true)]
        [return: NativeTypeName("HANDLE")]
        public static extern IntPtr CreateFileW([NativeTypeName("LPCWSTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] ushort* lpFileName, [NativeTypeName("DWORD")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] uint dwDesiredAccess, [NativeTypeName("DWORD")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] uint dwShareMode, [NativeTypeName("Enum1 *")][CppAttributeList("Name=SAL_name; p1=\"_In_opt_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__maybe|Name=SAL_valid|Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] Enum1* lpSecurityAttributes, [NativeTypeName("DWORD")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] uint dwCreationDisposition, [NativeTypeName("DWORD")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] uint dwFlagsAndAttributes, [NativeTypeName("HANDLE")][CppAttributeList("Name=SAL_name; p1=\"_In_opt_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__maybe|Name=SAL_valid|Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] IntPtr hTemplateFile);
    }

    public enum Enum2
    {
        X,
        Y,
        Z = Y + 7
    }

    [UnmanagedFunctionPointer(CallingConvention.Winapi)]
    public unsafe delegate int MyCallback([NativeTypeName("S2 *")][CppAttributeList("Name=SAL_name; p1=\"_Inout_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_name; p1=\"_Prepost_valid_\"; p2=\"\"; p3=\"1.1\"|Name=SAL_name; p1=\"_Pre_valid_\"; p2=\"\"; p3=\"2\"|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_end|Name=SAL_name; p1=\"_Post_valid_\"; p2=\"\"; p3=\"2\"|Name=SAL_post")] S2* ExceptionRecord, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] void* EstablisherFrame, [NativeTypeName("struct _CONTEXT *")][CppAttributeList("Name=SAL_name; p1=\"_Inout_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_name; p1=\"_Prepost_valid_\"; p2=\"\"; p3=\"1.1\"|Name=SAL_name; p1=\"_Pre_valid_\"; p2=\"\"; p3=\"2\"|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_end|Name=SAL_name; p1=\"_Post_valid_\"; p2=\"\"; p3=\"2\"|Name=SAL_post")] S1* ContextRecord, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"|Name=SAL_begin|Name=SAL_pre|Name=SAL_notref|Name=SAL_null; p1=__no|Name=SAL_valid|Name=SAL_deref|Name=SAL_access; p1=0x1|Name=SAL_end")] void* DispatcherContext);
}

