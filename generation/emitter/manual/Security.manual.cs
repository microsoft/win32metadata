using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Security
{
    // We need to define this manually because of how it's defined with duplicate typedefs
    [UnmanagedFunctionPointer]
    [return: NativeTypeName("NTSTATUS")]
    public unsafe delegate int PLSA_AP_CALL_PACKAGE_UNTRUSTED([NativeTypeName("PLSA_CLIENT_REQUEST")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void** ClientRequest, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_reads_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecount_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_readableTo; p1=byteCount(SubmitBufferLength)^Name=SAL_valid^Name=SAL_end^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1")] void* ProtocolSubmitBuffer, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void* ClientBufferBase, [NativeTypeName("ULONG")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint SubmitBufferLength, [NativeTypeName("PVOID *")][CppAttributeList("Name=SAL_name; p1=\"_Outptr_result_bytebuffer_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_deref^Name=SAL_writableTo; p1=byteCount(*ReturnBufferLength)^Name=SAL_end")] void** ProtocolReturnBuffer, [NativeTypeName("PULONG")][CppAttributeList("Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] uint* ReturnBufferLength, [NativeTypeName("PNTSTATUS")][CppAttributeList("Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] int* ProtocolStatus);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint SEC_THREAD_START([NativeTypeName("LPVOID")] void* lpThreadParameter);

    public static unsafe partial class Apis
    {
        // Has to be int so it can be used in a shift
        public const int CERT_COMPARE_SHIFT = 16;
    }
}
