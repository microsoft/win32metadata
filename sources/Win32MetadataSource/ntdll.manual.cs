using System;
using System.Runtime.InteropServices;
using Microsoft.Windows.Sdk.Win32.Interop;

namespace Microsoft.Windows.Sdk.Win32
{
    [Flags]
    public enum VER_FLAGS : uint
    {
        VER_MINORVERSION = 0x0000001,
        VER_MAJORVERSION = 0x0000002,
        VER_BUILDNUMBER = 0x0000004,
        VER_PLATFORMID = 0x0000008,
        VER_SERVICEPACKMINOR = 0x0000010,
        VER_SERVICEPACKMAJOR = 0x0000020,
        VER_SUITENAME = 0x0000040,
        VER_PRODUCT_TYPE = 0x0000080
    }
}
