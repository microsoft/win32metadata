using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
    public sealed class AgileAttribute : Attribute
    {
    }
}
