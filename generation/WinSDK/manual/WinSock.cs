using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Networking.WinSock
{
    public static unsafe partial class Apis
    {
        // (SOCKET)(~0) which equals uint.MaxValue
        [NativeTypeName("SOCKET")]
        public const uint INVALID_SOCKET = uint.MaxValue;

        public const uint WSA_INFINITE = 0xFFFFFFFF;

        public const uint IOC_INOUT = 0x80000000 | 0x40000000;
        
        public const int FIONREAD = 1074030207;
        public const int FIONBIO = -2147195266;
        public const int FIOASYNC = -2147195267;
        public const int SIOCSHIWAT = -2147192064;
        public const int SIOCGHIWAT = 1074033409;
        public const int SIOCSLOWAT = -2147192062;
        public const int SIOCGLOWAT = 1074033411;
        public const int SIOCATMARK = 1074033415;
    }
}
