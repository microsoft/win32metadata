using System;

namespace MetadataUtils
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
}