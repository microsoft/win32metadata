using System;

namespace Microsoft.Windows.Sdk.Win32Metadata.Interop
{
    public class RIAAFreeAttribute : Attribute
    {
        public RIAAFreeAttribute(string name)
        {
            this.Name = name;
        }

        /// <summary>Gets the name of the type that was used in the native signature.</summary>
        public string Name { get; }
    }
}
