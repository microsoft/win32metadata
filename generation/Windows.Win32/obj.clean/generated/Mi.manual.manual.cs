using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.Wmi 
{
    public static unsafe partial class Apis 
    {
        public const uint MI_FLAG_ANY = (1|2|4|8|16|32|64);
        public const uint MI_FLAG_VERSION = (1<<26|1<<27|1<<28);
        public const uint MI_FLAG_ADOPT = unchecked((uint)(1 << 31));
    }
}