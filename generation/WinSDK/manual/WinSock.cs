using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Networking.WinSock
{
    public static unsafe partial class Apis
    {
        // (SOCKET)(~0) which equals -1 or uint.MaxValue or UIntPtr.MaxValue.
        // https://github.com/microsoft/win32metadata/issues/848 - we decided projections
        // could cast the conversion from -1 to uint/UIntPtr depending on the build
        [NativeTypeName("SOCKET")]
        public const int INVALID_SOCKET = -1;

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

        public const ushort POLLIN = POLLRDNORM | POLLRDBAND;
    }
}
