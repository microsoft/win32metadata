using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Devices.Properties
{
    public static unsafe partial class Apis
    {

        [NativeTypeName("DEVPROP_BOOLEAN")]
        public const char DEVPROP_TRUE  = unchecked((char)-1);

        [NativeTypeName("DEVPROP_BOOLEAN")]
        public const char DEVPROP_FALSE = (char)0;
    }
}
