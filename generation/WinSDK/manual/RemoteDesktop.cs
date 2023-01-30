using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.RemoteDesktop
{
    public static partial class Apis
    {
        [NativeTypeName("HANDLE")]
        public const int WTS_CURRENT_SERVER = 0;

        [NativeTypeName("HANDLE")]
        public const int WTS_CURRENT_SERVER_HANDLE = 0;

        public const string WTS_CURRENT_SERVER_NAME = "";
    }
}
