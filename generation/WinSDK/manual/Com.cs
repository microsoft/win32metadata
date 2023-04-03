using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.UI.Controls.Apis;

namespace Windows.Win32.System.Com
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("PWSTR")]
        public const int COLE_DEFAULT_PRINCIPAL = -1;
        [NativeTypeName("void*")]
        public const int COLE_DEFAULT_AUTHINFO = -1;
    }
}
