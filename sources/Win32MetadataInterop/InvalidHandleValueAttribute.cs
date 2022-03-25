using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
    public class InvalidHandleValueAttribute : Attribute
    {
        public InvalidHandleValueAttribute(ulong value) => this.Value = value;
        public ulong Value { get; }
    }
}
