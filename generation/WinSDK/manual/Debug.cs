using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.System.Diagnostics.Debug
{
    public static unsafe partial class Apis
    {
        public const int EXCEPTION_EXECUTE_HANDLER = 1;
        public const int EXCEPTION_CONTINUE_SEARCH = 0;
        public const int EXCEPTION_CONTINUE_EXECUTION = -1;
    }
}