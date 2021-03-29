using System;
using System.Runtime.InteropServices;

namespace Windows.Win32.Interop
{
    public class NativeArrayInfoAttribute : Attribute
    {
        //
        // Summary:
        //     Indicates the number of elements in the fixed-length array or the number of characters
        //     (not bytes) in a string to import.
        public int CountConst;
        //
        // Summary:
        //     Indicates the zero-based parameter that contains the count of array elements,
        //     similar to size_is in COM.
        public short CountParamIndex;

        public NativeArrayInfoAttribute()
        {
        }
    }
}
