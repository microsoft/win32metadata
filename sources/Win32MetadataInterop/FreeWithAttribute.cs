using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [System.Runtime.InteropServices.ComVisible(true)]
    public sealed class FreeWithAttribute : Attribute
    {
        public FreeWithAttribute(String name)
        {
            this.Name = name;
        }

        public string Name { get; }
    }
}
