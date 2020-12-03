using System;
using System.Diagnostics;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
    public sealed class NativeInheritanceAttribute : Attribute
    {
        public NativeInheritanceAttribute(string baseName)
        {
            this.BaseName = BaseName;
        }

        public string BaseName { get; }
    }
}
