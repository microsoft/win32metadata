using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
    public sealed class RetValAttribute : Attribute
    {
    }
}
