using System;

namespace Windows.Win32.Interop
{
    /// <summary>
    /// Indicates that the attributed method is defined in an unmanaged static library (LIB).
    /// </summary>
    [AttributeUsage(AttributeTargets.Method, Inherited = false)]
    public class StaticLibraryAttribute : Attribute
    {
        /// <summary>
        /// Initialize a new instance of <see cref="StaticLibraryAttribute"/> with the name of the LIB
        /// file that contains the definition of this method.
        /// </summary>
        /// <param name="libName">
        /// The name of the LIB file that contains the definition of this method.
        /// </param>
        public StaticLibraryAttribute(string libName)
        {
            this.Value = libName;
        }

        /// <summary>
        /// Gets the name of a static library which may be substituted for the
        /// <see cref="System.Runtime.InteropServices.DllImportAttribute"/> DLL.
        /// </summary>
        /// <value>
        /// The name of the LIB file that contains the definition of this entry point.
        /// </value>
        public string Value { get; }
    }
}
