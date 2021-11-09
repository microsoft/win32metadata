using System;
using System.Runtime.InteropServices;
using Windows.Win32.Interop;

namespace Windows.Win32.Foundation
{
    public static unsafe partial class Apis
    {
        [NativeTypeName("HANDLE")]
        public const int INVALID_HANDLE_VALUE = -1;

        [NativeTypeName("HRESULT")]
        public const int CO_E_NOTINITIALIZED = unchecked((int)0x800401F0);
    }
}
