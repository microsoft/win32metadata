using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Kernel
{
    public enum EXCEPTION_DISPOSITION
    {
        ExceptionContinueExecution,
        ExceptionContinueSearch,
        ExceptionNestedException,
        ExceptionCollidedUnwind
    }

    public unsafe partial struct SLIST_ENTRY
    {
        public unsafe SLIST_ENTRY* Next;
    }
}
