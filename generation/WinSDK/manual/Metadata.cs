using System;
using System.Runtime.InteropServices;

namespace Windows.Win32.Foundation.Metadata
{
    [AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
    public sealed class AgileAttribute : Attribute
    {
    }

    public class AlsoUsableForAttribute : Attribute
    {
        public AlsoUsableForAttribute(string otherType)
        {

        }
    }

    public class CanReturnErrorsAsSuccessAttribute : Attribute
    {
    }
    
    public class CanReturnMultipleSuccessValuesAttribute : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
    public sealed class ComOutPtrAttribute : Attribute
    {
    }
    
    public class ConstantAttribute : Attribute
    {
        public ConstantAttribute(String value)
        {
            this.Value = value;
        }

        public string Value { get; }
    }

    public class ConstAttribute : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
    public sealed class CppAttributeList : Attribute
    {
        public CppAttributeList(String attributeList)
        {
            this.AttributeList = attributeList;
        }

        public string AttributeList { get; }
    }
    
    public class DoNotReleaseAttribute : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
    public sealed class FreeWithAttribute : Attribute
    {
        public FreeWithAttribute(String name)
        {
            this.Name = name;
        }

        public string Name { get; }
    }
    
    public class GuidAttribute : Attribute
    {
        public GuidAttribute(uint a, ushort b, ushort c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k)
        {
        }
    }
    
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true, Inherited = true)]
    public class InvalidHandleValueAttribute : Attribute
    {
        public InvalidHandleValueAttribute(long value) => this.Value = value;
        public long Value { get; }
    }
    
    public class MemorySizeAttribute : Attribute
    {
        public short BytesParamIndex; 
        public MemorySizeAttribute()
        {
        }
    }
    
    public class NativeArrayInfoAttribute : Attribute
    {
        //
        // Summary:
        //     Indicates the number of elements in the fixed-length array or the number of characters
        //     (not bytes) in a string to import.
        public int CountConst;
        //
        // Summary:
        //     Indicates the zero-based parameter that contains the count of array elements,
        //     similar to size_is in COM.
        public short CountParamIndex;
        //
        // Summary:
        //     Indicates the struct field name that contains the count of array elements.
        public string CountFieldName;

        public NativeArrayInfoAttribute()
        {
        }
    }

    /// <summary>Defines the encoding of a string as it was defined in the native signature.</summary>
    //[Conditional("DEBUG")]
    [AttributeUsage(AttributeTargets.Property, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
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
    
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
    public sealed class NativeInheritanceAttribute : Attribute
    {
        public NativeInheritanceAttribute(string baseName)
        {
            this.BaseName = BaseName;
        }

        public string BaseName { get; }
    }
    
    public class NativeTypedefAttribute : Attribute
    {
    }

    /// <summary>Defines the type of a member as it was used in the native signature.</summary>
    //[Conditional("DEBUG")]
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
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
    
    public class NotNullTerminatedAttribute : Attribute
    {
    }
    
    public class NullNullTerminatedAttribute : Attribute
    {
    }
    
    public class PropertyKeyAttribute : Attribute
    {
        public PropertyKeyAttribute(uint a, ushort b, ushort c, byte d, byte e, byte f, byte g, byte h, byte i, byte j, byte k, uint pid)
        {
        }
    }
    
    public class RAIIFreeAttribute : Attribute
    {
        public RAIIFreeAttribute(string name)
        {
            this.Name = name;
        }

        /// <summary>Gets the name of the type that was used in the native signature.</summary>
        public string Name { get; }
    }
    
    public class ReservedAttribute : Attribute
    {
    }

    public class ReturnsUnownedHandle : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
    public sealed class RetValAttribute : Attribute
    {
    }
    
    public class ScopedEnumAttribute : Attribute
    {
    }
    
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

    public class StructSizeFieldAttribute : Attribute
    {
        public StructSizeFieldAttribute(string field)
        {

        }
    }
    
    [Flags]
    public enum Architecture
    {
        None = 0,
        X86 = 1,
        X64 = 2,
        Arm64 = 4,
        All = Architecture.X64 | Architecture.X86 | Architecture.Arm64
    }

    public class SupportedArchitectureAttribute : Attribute
    {
        public SupportedArchitectureAttribute(Architecture arch)
        {
        }
    }
    
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Interface | AttributeTargets.Method, AllowMultiple = false)]
    public class SupportedOSPlatformAttribute : Attribute
    {
        public SupportedOSPlatformAttribute(string platform)
        {
        }
    }
}