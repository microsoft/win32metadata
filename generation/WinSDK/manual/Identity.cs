using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Security.Authentication.Identity
{
    public static unsafe partial class Apis
    {
        [DllImport("ADVAPI32.dll", EntryPoint = "SystemFunction036", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [return: NativeTypeName("BOOLEAN")]
        public static extern byte RtlGenRandom([NativeTypeName("PVOID")] [CppAttributeList("Name=SAL_name; p1=\"_Out_writes_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_writableTo; p1=byteCount(RandomBufferLength)^Name=SAL_end^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] void* RandomBuffer, [NativeTypeName("ULONG")] [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_valid^Name=SAL_pre^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint RandomBufferLength);

        [DllImport("ADVAPI32.dll", EntryPoint = "SystemFunction040", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [return: NativeTypeName("NTSTATUS")]
        public static extern int RtlEncryptMemory([NativeTypeName("PVOID")] [CppAttributeList("Name=SAL_name; p1=\"_Inout_updates_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_writableTo; p1=byteCount(MemorySize)^Name=SAL_end^Name=SAL_pre^Name=SAL_valid^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] void* Memory, [NativeTypeName("ULONG")] [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_valid^Name=SAL_pre^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint MemorySize, [NativeTypeName("ULONG")] [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_valid^Name=SAL_pre^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint OptionFlags);

        [DllImport("ADVAPI32.dll", EntryPoint = "SystemFunction041", CallingConvention = CallingConvention.StdCall, ExactSpelling = true)]
        [return: NativeTypeName("NTSTATUS")]
        public static extern int RtlDecryptMemory([NativeTypeName("PVOID")] [CppAttributeList("Name=SAL_name; p1=\"_Inout_updates_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecap_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_writableTo; p1=byteCount(MemorySize)^Name=SAL_end^Name=SAL_pre^Name=SAL_valid^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] void* Memory, [NativeTypeName("ULONG")] [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_valid^Name=SAL_pre^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint MemorySize, [NativeTypeName("ULONG")] [CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_pre^Name=SAL_valid^Name=SAL_pre^Name=SAL_notref^Name=SAL_deref^Name=SAL_notref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint OptionFlags);
    }
}
