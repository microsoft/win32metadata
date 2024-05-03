﻿using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.System.Threading
{
    public static unsafe partial class Apis
    {
        public const uint WAIT_OBJECT_0 = 0x00000000;
        public const uint WAIT_ABANDONED = 0x00000080;
        public const uint WAIT_ABANDONED_0 = 0x00000080;
        public const uint WAIT_IO_COMPLETION = 0x000000C0;

        public const uint CONDITION_VARIABLE_LOCKMODE_SHARED = 0x1;
        public const uint INIT_ONCE_CHECK_ONLY = 0x00000001;
        public const uint INIT_ONCE_ASYNC = 0x00000002;
        public const uint INIT_ONCE_INIT_FAILED = 0x00000004;
        public const uint INIT_ONCE_CTX_RESERVED_BITS = 2;

        [Constant("0")]
        public static CONDITION_VARIABLE CONDITION_VARIABLE_INIT;

        [Constant("0")]
        public static SRWLOCK SRWLOCK_INIT;

        [Constant("0")]
        public static INIT_ONCE INIT_ONCE_STATIC_INIT;

        [DllImport("FORCEINLINE")]
        [Constant("-4")]
        [return: DoNotRelease]
        public static extern HANDLE GetCurrentProcessToken();

        [DllImport("FORCEINLINE")]
        [Constant("-5")]
        [return: DoNotRelease]
        public static extern HANDLE GetCurrentThreadToken();

        [DllImport("FORCEINLINE")]
        [Constant("-6")]
        [return: DoNotRelease]
        public static extern HANDLE GetCurrentThreadEffectiveToken();
    }

    public unsafe partial struct PROCESS_BASIC_INFORMATION
    {
        public NTSTATUS ExitStatus;

        public unsafe PEB* PebBaseAddress;

        public UIntPtr AffinityMask;

        public int BasePriority;

        public UIntPtr UniqueProcessId;

        public UIntPtr InheritedFromUniqueProcessId;
    }
    
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

    [Flags]
    public enum PROCESS_ACCESS_RIGHTS : uint
    {
        PROCESS_TERMINATE = (0x0001),
        PROCESS_CREATE_THREAD = (0x0002),
        PROCESS_SET_SESSIONID = (0x0004),
        PROCESS_VM_OPERATION = (0x0008),
        PROCESS_VM_READ = (0x0010),
        PROCESS_VM_WRITE = (0x0020),
        PROCESS_DUP_HANDLE = (0x0040),
        PROCESS_CREATE_PROCESS = (0x0080),
        PROCESS_SET_QUOTA = (0x0100),
        PROCESS_SET_INFORMATION = (0x0200),
        PROCESS_QUERY_INFORMATION = (0x0400),
        PROCESS_SUSPEND_RESUME = (0x0800),
        PROCESS_QUERY_LIMITED_INFORMATION = (0x1000),
        PROCESS_SET_LIMITED_INFORMATION = (0x2000),
        PROCESS_ALL_ACCESS = (PROCESS_STANDARD_RIGHTS_REQUIRED | PROCESS_SYNCHRONIZE | 0xFFFF),
        PROCESS_DELETE = (0x00010000),
        PROCESS_READ_CONTROL = (0x00020000),
        PROCESS_WRITE_DAC = (0x00040000),
        PROCESS_WRITE_OWNER = (0x00080000),
        PROCESS_SYNCHRONIZE = (0x00100000),
        PROCESS_STANDARD_RIGHTS_REQUIRED = (0x000F0000)
    }
}
