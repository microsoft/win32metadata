using System;
using System.Collections.Generic;
using System.Text;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
    public sealed class ComOutPtrAttribute : Attribute
    {
    }
}
