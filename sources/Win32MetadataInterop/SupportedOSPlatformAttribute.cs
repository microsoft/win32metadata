using System;

namespace Windows.Win32.Interop
{
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Interface | AttributeTargets.Method, AllowMultiple = false)]
    public class SupportedOSPlatformAttribute : Attribute
    {
        public SupportedOSPlatformAttribute(string platform)
        {
        }
    }
}
