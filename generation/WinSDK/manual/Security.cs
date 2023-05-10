using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Security
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("BOOLEAN")]
        public const byte SECURITY_DYNAMIC_TRACKING = 1;
        
        [NativeTypeName("BOOLEAN")]
        public const byte SECURITY_STATIC_TRACKING = 0;

        [Constant("{0, 0, 0, 0, 0, 0}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_NULL_SID_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 1}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_WORLD_SID_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 2}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_LOCAL_SID_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 3}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_CREATOR_SID_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 4}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_NON_UNIQUE_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 5}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_NT_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 9}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_RESOURCE_MANAGER_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 15}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_APP_PACKAGE_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 16}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_MANDATORY_LABEL_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 17}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_SCOPED_POLICY_ID_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 18}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_AUTHENTICATION_AUTHORITY;
        [Constant("{0, 0, 0, 0, 0, 19}")]
        public static readonly SID_IDENTIFIER_AUTHORITY SECURITY_PROCESS_TRUST_AUTHORITY;
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
        TOKEN_READ = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_RIGHTS.STANDARD_RIGHTS_READ | TOKEN_QUERY),
        TOKEN_WRITE = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_RIGHTS.STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT),
        TOKEN_EXECUTE = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_RIGHTS.STANDARD_RIGHTS_EXECUTE),
        TOKEN_TRUST_CONSTRAINT_MASK = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_RIGHTS.STANDARD_RIGHTS_READ | TOKEN_QUERY | TOKEN_QUERY_SOURCE),
        TOKEN_ACCESS_PSEUDO_HANDLE_WIN8 = (TOKEN_QUERY | TOKEN_QUERY_SOURCE),
        TOKEN_ACCESS_PSEUDO_HANDLE = TOKEN_ACCESS_PSEUDO_HANDLE_WIN8,
        TOKEN_ALL_ACCESS = (Windows.Win32.Storage.FileSystem.FILE_ACCESS_RIGHTS.STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS |TOKEN_ADJUST_DEFAULT | TOKEN_ADJUST_SESSIONID)
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
