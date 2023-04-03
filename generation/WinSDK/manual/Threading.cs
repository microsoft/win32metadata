using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Threading
{
    public static unsafe partial class Apis
    {
        public const uint WAIT_OBJECT_0 = 0x00000000;
        public const uint WAIT_ABANDONED = 0x00000080;
        public const uint WAIT_ABANDONED_0 = 0x00000080;
        public const uint WAIT_IO_COMPLETION = 0x000000C0;

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

    // Define this manually to consolidate SDK and WDK duplicate definitions
    public enum PROCESSINFOCLASS : int
    {
        ProcessBasicInformation                      = 0,
        ProcessQuotaLimits                           = 1,
        ProcessIoCounters                            = 2,
        ProcessVmCounters                            = 3,
        ProcessTimes                                 = 4,
        ProcessBasePriority                          = 5,
        ProcessRaisePriority                         = 6,
        ProcessDebugPort                             = 7,
        ProcessExceptionPort                         = 8,
        ProcessAccessToken                           = 9,
        ProcessLdtInformation                        = 10,
        ProcessLdtSize                               = 11,
        ProcessDefaultHardErrorMode                  = 12,
        ProcessIoPortHandlers                        = 13,   // Note: this is kernel mode only
        ProcessPooledUsageAndLimits                  = 14,
        ProcessWorkingSetWatch                       = 15,
        ProcessUserModeIOPL                          = 16,
        ProcessEnableAlignmentFaultFixup             = 17,
        ProcessPriorityClass                         = 18,
        ProcessWx86Information                       = 19,
        ProcessHandleCount                           = 20,
        ProcessAffinityMask                          = 21,
        ProcessPriorityBoost                         = 22,
        ProcessDeviceMap                             = 23,
        ProcessSessionInformation                    = 24,
        ProcessForegroundInformation                 = 25,
        ProcessWow64Information                      = 26,
        ProcessImageFileName                         = 27,
        ProcessLUIDDeviceMapsEnabled                 = 28,
        ProcessBreakOnTermination                    = 29,
        ProcessDebugObjectHandle                     = 30,
        ProcessDebugFlags                            = 31,
        ProcessHandleTracing                         = 32,
        ProcessIoPriority                            = 33,
        ProcessExecuteFlags                          = 34,
        ProcessTlsInformation                        = 35,
        ProcessCookie                                = 36,
        ProcessImageInformation                      = 37,
        ProcessCycleTime                             = 38,
        ProcessPagePriority                          = 39,
        ProcessInstrumentationCallback               = 40,
        ProcessThreadStackAllocation                 = 41,
        ProcessWorkingSetWatchEx                     = 42,
        ProcessImageFileNameWin32                    = 43,
        ProcessImageFileMapping                      = 44,
        ProcessAffinityUpdateMode                    = 45,
        ProcessMemoryAllocationMode                  = 46,
        ProcessGroupInformation                      = 47,
        ProcessTokenVirtualizationEnabled            = 48,
        ProcessOwnerInformation                      = 49,
        ProcessWindowInformation                     = 50,
        ProcessHandleInformation                     = 51,
        ProcessMitigationPolicy                      = 52,
        ProcessDynamicFunctionTableInformation       = 53,
        ProcessHandleCheckingMode                    = 54,
        ProcessKeepAliveCount                        = 55,
        ProcessRevokeFileHandles                     = 56,
        ProcessWorkingSetControl                     = 57,
        ProcessHandleTable                           = 58,
        ProcessCheckStackExtentsMode                 = 59,
        ProcessCommandLineInformation                = 60,
        ProcessProtectionInformation                 = 61,
        ProcessMemoryExhaustion                      = 62,
        ProcessFaultInformation                      = 63,
        ProcessTelemetryIdInformation                = 64,
        ProcessCommitReleaseInformation              = 65,
        ProcessReserved1Information                  = 66,
        ProcessReserved2Information                  = 67,
        ProcessSubsystemProcess                      = 68,
        ProcessInPrivate                             = 70,
        ProcessRaiseUMExceptionOnInvalidHandleClose  = 71,
        ProcessSubsystemInformation                  = 75,
        ProcessWin32kSyscallFilterInformation        = 79,
        ProcessEnergyTrackingState                   = 82,
        MaxProcessInfoClass                             // MaxProcessInfoClass should always be the last enum
    }

    // Define this manually to consolidate SDK and WDK duplicate definitions
    public enum THREADINFOCLASS : int
    {
        ThreadBasicInformation          = 0,
        ThreadTimes                     = 1,
        ThreadPriority                  = 2,
        ThreadBasePriority              = 3,
        ThreadAffinityMask              = 4,
        ThreadImpersonationToken        = 5,
        ThreadDescriptorTableEntry      = 6,
        ThreadEnableAlignmentFaultFixup = 7,
        ThreadEventPair_Reusable        = 8,
        ThreadQuerySetWin32StartAddress = 9,
        ThreadZeroTlsCell               = 10,
        ThreadPerformanceCount          = 11,
        ThreadAmILastThread             = 12,
        ThreadIdealProcessor            = 13,
        ThreadPriorityBoost             = 14,
        ThreadSetTlsArrayAddress        = 15,   // Obsolete
        ThreadIsIoPending               = 16,
        ThreadHideFromDebugger          = 17,
        ThreadBreakOnTermination        = 18,
        ThreadSwitchLegacyState         = 19,
        ThreadIsTerminated              = 20,
        ThreadLastSystemCall            = 21,
        ThreadIoPriority                = 22,
        ThreadCycleTime                 = 23,
        ThreadPagePriority              = 24,
        ThreadActualBasePriority        = 25,
        ThreadTebInformation            = 26,
        ThreadCSwitchMon                = 27,   // Obsolete
        ThreadCSwitchPmu                = 28,
        ThreadWow64Context              = 29,
        ThreadGroupInformation          = 30,
        ThreadUmsInformation            = 31,   // Obsolete
        ThreadCounterProfiling          = 32,
        ThreadIdealProcessorEx          = 33,
        ThreadCpuAccountingInformation  = 34,
        ThreadSuspendCount              = 35,
        ThreadActualGroupAffinity       = 41,
        ThreadDynamicCodePolicyInfo     = 42,
        ThreadSubsystemInformation      = 45,
        MaxThreadInfoClass              = 53,
    }
}
