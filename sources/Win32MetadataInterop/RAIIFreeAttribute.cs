using System;

namespace Windows.Win32.Interop
{
    public class RAIIFreeAttribute : Attribute
    {
        public RAIIFreeAttribute(string name)
        {
            this.Name = name;
        }

        /// <summary>Gets the name of the type that was used in the native signature.</summary>
        public string Name { get; }
    }
}
