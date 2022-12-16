using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Security
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("BOOLEAN")]
        public const byte SECURITY_DYNAMIC_TRACKING = 1;
        
        [NativeTypeName("BOOLEAN")]
        public const byte SECURITY_STATIC_TRACKING = 0;
    }

    // We need to define this manually because of how it's defined with duplicate typedefs
    [UnmanagedFunctionPointer]
    [return: NativeTypeName("NTSTATUS")]
    public unsafe delegate int PLSA_AP_CALL_PACKAGE_UNTRUSTED([NativeTypeName("PLSA_CLIENT_REQUEST")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void** ClientRequest, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_reads_bytes_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_name; p1=\"_Pre_bytecount_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_readableTo; p1=byteCount(SubmitBufferLength)^Name=SAL_valid^Name=SAL_end^Name=SAL_name; p1=\"_Deref_pre_readonly_\"; p2=\"\"; p3=\"1.1\"^Name=SAL_deref^Name=SAL_access; p1=0x1")] void* ProtocolSubmitBuffer, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void* ClientBufferBase, [NativeTypeName("ULONG")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] uint SubmitBufferLength, [NativeTypeName("PVOID *")][CppAttributeList("Name=SAL_name; p1=\"_Outptr_result_bytebuffer_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_deref^Name=SAL_writableTo; p1=byteCount(*ReturnBufferLength)^Name=SAL_end")] void** ProtocolReturnBuffer, [NativeTypeName("PULONG")][CppAttributeList("Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] uint* ReturnBufferLength, [NativeTypeName("PNTSTATUS")][CppAttributeList("Name=SAL_name; p1=\"_Out_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_writableTo; p1=elementCount(1)^Name=SAL_post^Name=SAL_valid^Name=SAL_end")] int* ProtocolStatus);

    [UnmanagedFunctionPointer]
    [return: NativeTypeName("DWORD")]
    public unsafe delegate uint SEC_THREAD_START([NativeTypeName("LPVOID")] void* lpThreadParameter);

    [Flags]
    public enum TOKEN_ACCESS_MASK : uint
    {
        TOKEN_DELETE = (0x00010000),
        TOKEN_READ_CONTROL = (0x00020000),
        TOKEN_WRITE_DAC = (0x00040000),
        TOKEN_WRITE_OWNER = (0x00080000),
        TOKEN_ACCESS_SYSTEM_SECURITY = (0x01000000),
        TOKEN_ASSIGN_PRIMARY = (0x0001),
        TOKEN_DUPLICATE = (0x0002),
        TOKEN_IMPERSONATE = (0x0004),
        TOKEN_QUERY = (0x0008),
        TOKEN_QUERY_SOURCE = (0x0010),
        TOKEN_ADJUST_PRIVILEGES = (0x0020),
        TOKEN_ADJUST_GROUPS = (0x0040),
        TOKEN_ADJUST_DEFAULT = (0x0080),
        TOKEN_ADJUST_SESSIONID = (0x0100),
        TOKEN_READ = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.STANDARD_RIGHTS_READ | TOKEN_QUERY),
        TOKEN_WRITE = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT),
        TOKEN_EXECUTE = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.STANDARD_RIGHTS_EXECUTE),
        TOKEN_TRUST_CONSTRAINT_MASK = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.STANDARD_RIGHTS_READ | TOKEN_QUERY | TOKEN_QUERY_SOURCE),
        TOKEN_ACCESS_PSEUDO_HANDLE_WIN8 = (TOKEN_QUERY | TOKEN_QUERY_SOURCE),
        TOKEN_ACCESS_PSEUDO_HANDLE = TOKEN_ACCESS_PSEUDO_HANDLE_WIN8,
        TOKEN_ALL_ACCESS = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_FLAGS.STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS |TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID)
    }
}

namespace Windows.Win32.Security.Credentials
{
    public static unsafe partial class Apis
    {
        public const uint CRED_MAX_CREDENTIAL_BLOB_SIZE = 5*512;
        public const uint CRED_MAX_USERNAME_LENGTH = 256+1+256;
        public const uint CRED_MAX_DOMAIN_TARGET_NAME_LENGTH = 256+1+80;
    }
}

namespace Windows.Win32.Security.Cryptography
{
    public static unsafe partial class Apis
    {
        // Has to be int so it can be used in a shift
        public const int CERT_COMPARE_SHIFT = 16;
    }
}
