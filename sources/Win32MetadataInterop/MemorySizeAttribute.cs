using System;
using System.Runtime.InteropServices;

namespace Windows.Win32.Interop
{
    public class MemorySizeAttribute : Attribute
    {
        public short BytesParamIndex; 
        public MemorySizeAttribute()
        {
        }
    }
}
