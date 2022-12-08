using System;
using System.Runtime.InteropServices;

namespace Windows.Win32.Interop
{
    public class ConstantAttribute : Attribute
    {
        public ConstantAttribute(String value)
        {
            this.Value = value;
        }

        public string Value { get; }
    }
}
