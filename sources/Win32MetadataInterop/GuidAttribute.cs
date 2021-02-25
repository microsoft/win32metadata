using System;
using System.Collections.Generic;
using System.Text;

namespace Windows.Win32.Interop
{
    public class GuidAttribute : Attribute
    {
        public GuidAttribute(uint a, ushort b, ushort c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k)
        {
        }
    }
}
