using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Networking.WinSock
{
    public static unsafe partial class Apis
    {
        // (SOCKET)(~0) which equals uint.MaxValue
        public const uint INVALID_SOCKET = uint.MaxValue;
    }
}