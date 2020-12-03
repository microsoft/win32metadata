using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [System.Runtime.InteropServices.ComVisible(true)]
    public sealed class CppAttributeList : Attribute
    {
        public CppAttributeList(String attributeList)
        {
            this.AttributeList = attributeList;
        }

        public string AttributeList { get; }
    }
}
