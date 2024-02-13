using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
using static Windows.Win32.UI.WindowsAndMessaging.Apis;

namespace Windows.Win32.Security.Cryptography
{
    public static partial class Apis
    {
        public const uint CERT_SYSTEM_STORE_CURRENT_USER = CERT_SYSTEM_STORE_CURRENT_USER_ID << 16;

        public const uint CERT_SYSTEM_STORE_LOCAL_MACHINE = CERT_SYSTEM_STORE_LOCAL_MACHINE_ID << 16;
    }
}
