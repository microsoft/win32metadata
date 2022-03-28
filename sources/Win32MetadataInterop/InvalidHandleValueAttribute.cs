using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true, Inherited = true)]
    public class InvalidHandleValueAttribute : Attribute
    {
        public InvalidHandleValueAttribute(long value) => this.Value = value;
        public long Value { get; }
    }
}
