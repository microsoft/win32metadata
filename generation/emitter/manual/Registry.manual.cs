using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Registry
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("HKEY")]
        public const int HKEY_CLASSES_ROOT = unchecked((int)0x80000000);

        [NativeTypeName("HKEY")]
        public const int HKEY_CURRENT_USER = unchecked((int)0x80000001);

        [NativeTypeName("HKEY")]
        public const int HKEY_LOCAL_MACHINE = unchecked((int)0x80000002);

        [NativeTypeName("HKEY")]
        public const int HKEY_USERS = unchecked((int)0x80000003);

        [NativeTypeName("HKEY")]
        public const int HKEY_PERFORMANCE_DATA = unchecked((int)0x80000004);

        [NativeTypeName("HKEY")]
        public const int HKEY_PERFORMANCE_TEXT = unchecked((int)0x80000050);

        [NativeTypeName("HKEY")]
        public const int HKEY_PERFORMANCE_NLSTEXT = unchecked((int)0x80000060);

        [NativeTypeName("HKEY")]
        public const int HKEY_CURRENT_CONFIG = unchecked((int)0x80000005);

        [NativeTypeName("HKEY")]
        public const int HKEY_DYN_DATA = unchecked((int)0x80000006);

        [NativeTypeName("HKEY")]
        public const int HKEY_CURRENT_USER_LOCAL_SETTINGS = unchecked((int)0x80000007);
    }

    public enum REG_VALUE_TYPE : uint
    {
        REG_NONE = 0,
        REG_SZ = 1,
        REG_EXPAND_SZ = 2,
        REG_BINARY = 3,
        REG_DWORD = 4,
        REG_DWORD_LITTLE_ENDIAN = 4,
        REG_DWORD_BIG_ENDIAN = 5,
        REG_LINK = 6,
        REG_MULTI_SZ = 7,
        REG_RESOURCE_LIST = 8,
        REG_FULL_RESOURCE_DESCRIPTOR =  9,
        REG_RESOURCE_REQUIREMENTS_LIST = 10,
        REG_QWORD = 11,
        REG_QWORD_LITTLE_ENDIAN = 11
    }

    [Flags]
    public enum REG_SAM_FLAGS : uint
    {
        KEY_QUERY_VALUE = 0x0001,
        KEY_SET_VALUE = 0x0002,
        KEY_CREATE_SUB_KEY = 0x0004,
        KEY_ENUMERATE_SUB_KEYS = 0x0008,
        KEY_NOTIFY = 0x0010,
        KEY_CREATE_LINK = 0x0020,
        KEY_WOW64_32KEY = 0x0200,
        KEY_WOW64_64KEY = 0x0100,
        KEY_WOW64_RES = 0x0300,

        KEY_READ = 0x20019,
        KEY_WRITE = 0x20006,
        KEY_EXECUTE = 0x20019,
        KEY_ALL_ACCESS = 0xF003F
    }

    [Flags]
    public enum REG_OPEN_CREATE_OPTIONS : uint
    {
        REG_OPTION_RESERVED = 0x00000000,
        REG_OPTION_NON_VOLATILE = 0x00000000,
        REG_OPTION_VOLATILE  = 0x00000001,
        REG_OPTION_CREATE_LINK = 0x00000002,
        REG_OPTION_BACKUP_RESTORE = 0x00000004,
        REG_OPTION_OPEN_LINK = 0x00000008,
        REG_OPTION_DONT_VIRTUALIZE = 0x00000010
    }

    public enum REG_CREATE_KEY_DISPOSITION : uint
    {
        REG_CREATED_NEW_KEY = 0x00000001,
        REG_OPENED_EXISTING_KEY = 0x00000002
    }
}
