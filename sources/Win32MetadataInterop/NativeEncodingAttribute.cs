using System;
using System.Diagnostics;

namespace Windows.Win32.Interop
{
    /// <summary>Defines the encoding of a string as it was defined in the native signature.</summary>
    //[Conditional("DEBUG")]
    [AttributeUsage(AttributeTargets.Property, AllowMultiple = false, Inherited = false)]
    [System.Runtime.InteropServices.ComVisible(true)]
    public sealed class NativeEncodingAttribute : Attribute
    {
        /// <summary>Initializes a new instance of the <see cref="NativeEncodingAttribute" /> class.</summary>
        /// <param name="name">The encoding of a string as it was defined in the native signature.</param>
        public NativeEncodingAttribute(String name)
        {
            this.Name = name;
        }

        /// <summary>Gets the encoding of a string as it was defined in the native signature.</summary>
        public string Name { get; }
    }
}
