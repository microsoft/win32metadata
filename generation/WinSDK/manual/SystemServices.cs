using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.SystemServices
{
    // Have to manually define this because of the way it's brought it using two typedefs
    [UnmanagedFunctionPointer]
    public unsafe delegate void PUMS_SCHEDULER_ENTRY_POINT([CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] RTL_UMS_SCHEDULER_REASON Reason, [NativeTypeName("ULONG_PTR")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] UIntPtr ActivationPayload, [NativeTypeName("PVOID")][CppAttributeList("Name=SAL_name; p1=\"_In_\"; p2=\"\"; p3=\"2\"^Name=SAL_begin^Name=SAL_pre^Name=SAL_notref^Name=SAL_null; p1=__no^Name=SAL_valid^Name=SAL_deref^Name=SAL_access; p1=0x1^Name=SAL_end")] void* SchedulerParam);

    public static unsafe partial class Apis
    {
        public const uint _MM_HINT_T0  = 1;
        public const uint _MM_HINT_T1  = 2;
        public const uint _MM_HINT_T2  = 3;
        public const uint _MM_HINT_NTA = 0;
    }
}
