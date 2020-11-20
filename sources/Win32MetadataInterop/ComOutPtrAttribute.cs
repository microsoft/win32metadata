using System;
using System.Collections.Generic;
using System.Text;

namespace Microsoft.Windows.Sdk.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
    public sealed class ComOutPtrAttribute : Attribute
    {
    }
}
