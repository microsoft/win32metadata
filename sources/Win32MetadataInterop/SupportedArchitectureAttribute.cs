using System;
using System.Collections.Generic;
using System.Text;

namespace Windows.Win32.Interop
{
    [Flags]
    public enum Architecture
    {
        None = 0,
        X86 = 1,
        X64 = 2,
        Arm64 = 4,
        All = Architecture.X64 | Architecture.X86 | Architecture.Arm64
    }

    public class SupportedArchitectureAttribute : Attribute
    {
        public SupportedArchitectureAttribute(Architecture arch)
        {
        }
    }
}
