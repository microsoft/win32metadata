using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.WindowsProgramming
{
    [Flags]
    public enum PROCESS_CREATION_FLAGS : uint
    {
        DEBUG_PROCESS = 0x00000001,
        DEBUG_ONLY_THIS_PROCESS = 0x00000002,
        CREATE_SUSPENDED = 0x00000004,
        DETACHED_PROCESS = 0x00000008,
        CREATE_NEW_CONSOLE = 0x00000010,
        NORMAL_PRIORITY_CLASS = 0x00000020,
        IDLE_PRIORITY_CLASS = 0x00000040,
        HIGH_PRIORITY_CLASS = 0x00000080,
        REALTIME_PRIORITY_CLASS = 0x00000100,
        CREATE_NEW_PROCESS_GROUP = 0x00000200,
        CREATE_UNICODE_ENVIRONMENT = 0x00000400,
        CREATE_SEPARATE_WOW_VDM = 0x00000800,
        CREATE_SHARED_WOW_VDM = 0x00001000,
        CREATE_FORCEDOS = 0x00002000,
        BELOW_NORMAL_PRIORITY_CLASS = 0x00004000,
        ABOVE_NORMAL_PRIORITY_CLASS = 0x00008000,
        INHERIT_PARENT_AFFINITY = 0x00010000,
        INHERIT_CALLER_PRIORITY = 0x00020000,
        CREATE_PROTECTED_PROCESS = 0x00040000,
        EXTENDED_STARTUPINFO_PRESENT = 0x00080000,
        PROCESS_MODE_BACKGROUND_BEGIN = 0x00100000,
        PROCESS_MODE_BACKGROUND_END = 0x00200000,
        CREATE_SECURE_PROCESS = 0x00400000,
        CREATE_BREAKAWAY_FROM_JOB = 0x01000000,
        CREATE_PRESERVE_CODE_AUTHZ_LEVEL = 0x02000000,
        CREATE_DEFAULT_ERROR_MODE = 0x04000000,
        CREATE_NO_WINDOW = 0x08000000,
        PROFILE_USER = 0x10000000,
        PROFILE_KERNEL = 0x20000000,
        PROFILE_SERVER = 0x40000000,
        CREATE_IGNORE_SYSTEM_DEFAULT = 0x80000000
    }

    public enum HANDLE_FLAG_OPTIONS
    {
        HANDLE_FLAG_INHERIT = 0x00000001,
        HANDLE_FLAG_PROTECT_FROM_CLOSE = 0x00000002
    }

    public enum DUPLICATE_HANDLE_OPTIONS
    {
        DUPLICATE_CLOSE_SOURCE = 0x00000001,
        DUPLICATE_SAME_ACCESS = 0x00000002
    }

    public enum STD_HANDLE_TYPE : uint
    {
        STD_INPUT_HANDLE = unchecked((uint)-10),
        STD_OUTPUT_HANDLE = unchecked((uint)-11),
        STD_ERROR_HANDLE = unchecked((uint)-12),
    }

    [Flags]
    public enum VER_FLAGS : uint
    {
        VER_MINORVERSION = 0x0000001,
        VER_MAJORVERSION = 0x0000002,
        VER_BUILDNUMBER = 0x0000004,
        VER_PLATFORMID = 0x0000008,
        VER_SERVICEPACKMINOR = 0x0000010,
        VER_SERVICEPACKMAJOR = 0x0000020,
        VER_SUITENAME = 0x0000040,
        VER_PRODUCT_TYPE = 0x0000080
    }

    [Flags]
    public enum ProcessAccessRights : uint
    {
        Terminate = (0x0001),
        CreateThread = (0x0002),
        SetSessionid = (0x0004),
        VmOperation = (0x0008),
        VmRead = (0x0010),
        VmWrite = (0x0020),
        DupHandle = (0x0040),
        CreateProcess = (0x0080),
        SetQuota = (0x0100),
        SetInformation = (0x0200),
        QueryInformation = (0x0400),
        SuspendResume = (0x0800),
        QueryLimitedInformation = (0x1000),
        SetLimitedInformation = (0x2000),
        AllAccess = (StandardRightsRequired | Synchronize | 0xFFFF),
        Delete = (0x00010000),
        ReadControl = (0x00020000),
        WriteDac = (0x00040000),
        WriteOwner = (0x00080000),
        Synchronize = (0x00100000),
        StandardRightsRequired = (0x000F0000)
    }
}
