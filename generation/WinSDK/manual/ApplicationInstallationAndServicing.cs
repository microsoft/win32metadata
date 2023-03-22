using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.System.ApplicationInstallationAndServicing
{
    public static unsafe partial class Apis 
    {
        [NativeTypeName("PWSTR")][Const]
        public const int MSIDBOPEN_READONLY = 0;
        [NativeTypeName("PWSTR")][Const]
        public const int MSIDBOPEN_TRANSACT = 1;
        [NativeTypeName("PWSTR")][Const]
        public const int MSIDBOPEN_DIRECT = 2;
        [NativeTypeName("PWSTR")][Const]
        public const int MSIDBOPEN_CREATE = 3;
        [NativeTypeName("PWSTR")][Const]
        public const int MSIDBOPEN_CREATEDIRECT = 4;

        public const int MSIDBOPEN_PATCHFILE = 16;
    }
}