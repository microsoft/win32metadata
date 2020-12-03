using System;
using System.Diagnostics;

namespace Windows.Win32.Interop
{
    /// <summary>Defines the type of a member as it was used in the native signature.</summary>
    //[Conditional("DEBUG")]
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [System.Runtime.InteropServices.ComVisible(true)]
    public sealed class NativeTypeNameAttribute : Attribute
    {
        /// <summary>Initializes a new instance of the <see cref="NativeTypeNameAttribute" /> class.</summary>
        /// <param name="name">The name of the type that was used in the native signature.</param>
        public NativeTypeNameAttribute(String name)
        {
            this.Name = name;
        }

        /// <summary>Gets the name of the type that was used in the native signature.</summary>
        public string Name { get; }
    }
}
