using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;
using static Windows.Win32.UI.WindowsAndMessaging.Apis;

namespace Windows.Win32.Security.Cryptography.Certificates
{
    public static partial class Apis
    {
        public const string wszREGKEYNOSYSTEMCERTSVCPATH = "CurrentControlSet\\Services\\" + wszSERVICE_NAME;

        public const string wszREGKEYCERTSVCPATH = "SYSTEM\\" + wszREGKEYNOSYSTEMCERTSVCPATH;
    }
}
