using System;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;

namespace Windows.Win32.Devices.Properties
{
    public static unsafe partial class Apis
    {

        [NativeTypeName("DEVPROP_BOOLEAN")]
        public const byte DEVPROP_TRUE  = unchecked((byte)-1);

        [NativeTypeName("DEVPROP_BOOLEAN")]
        public const byte DEVPROP_FALSE = (byte)0;
    }
}
