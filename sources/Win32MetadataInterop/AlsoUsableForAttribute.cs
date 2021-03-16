using System;
using System.Collections.Generic;
using System.Text;

namespace Windows.Win32.Interop
{
    public class AlsoUsableForAttribute : Attribute
    {
        public AlsoUsableForAttribute(string otherType)
        {

        }
    }
}
