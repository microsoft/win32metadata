using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Kernel
{
    public enum EXCEPTION_DISPOSITION
    {
        ExceptionContinueExecution,
        ExceptionContinueSearch,
        ExceptionNestedException,
        ExceptionCollidedUnwind
    }
}
