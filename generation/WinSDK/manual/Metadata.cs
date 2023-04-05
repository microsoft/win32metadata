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
        public ConstantAttribute(String Value)
        {
        }
    }

    public class ConstAttribute : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
    public sealed class CppAttributeList : Attribute
    {
        public CppAttributeList(String AttributeList)
        {
        }
    }
    
    public class DoNotReleaseAttribute : Attribute
    {
    }
    
    [AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
    public sealed class FreeWithAttribute : Attribute
    {
        public FreeWithAttribute(String Name)
        {
        }
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
        public InvalidHandleValueAttribute(long Value)
        {

        }
    }
    
    public class MemorySizeAttribute : Attribute
    {
        private short _bytesParamIndex;

        public MemorySizeAttribute()
        {
        }

        public short BytesParamIndex;
        public short get_BytesParamIndex() => return _bytesParamIndex;
        public void set_BytesParamIndex(short value) => _bytesParamIndex = value;
    }
    
    public class NativeArrayInfoAttribute : Attribute
    {
        private int _countConst;
        private short _countParamIndex;
        private string _countFieldName;

        //
        // Summary:
        //     Indicates the number of elements in the fixed-length array or the number of characters
        //     (not bytes) in a string to import.
        public int CountConst;
        public int get_CountConst() => return _countConst;
        public void set_CountConst(int value) => _countConst = value;

        //
        // Summary:
        //     Indicates the zero-based parameter that contains the count of array elements,
        //     similar to size_is in COM.
        public short CountParamIndex;
        public short get_CountParamIndex() => return _countParamIndex;
        public void set_CountParamIndex(short value) => _countParamIndex = value;
        //
        // Summary:
        //     Indicates the struct field name that contains the count of array elements.
        public string CountFieldName;
        public string get_CountFieldName() => return _countFieldName;
        public void set_CountFieldName(string value) => _countFieldName = value;
    }

    /// <summary>Defines the encoding of a string as it was defined in the native signature.</summary>
    //[Conditional("DEBUG")]
    [AttributeUsage(AttributeTargets.Property, AllowMultiple = false, Inherited = false)]
    [ComVisible(true)]
    public sealed class NativeEncodingAttribute : Attribute
    {
        /// <summary>Initializes a new instance of the <see cref="NativeEncodingAttribute" /> class.</summary>
        /// <param name="name">The encoding of a string as it was defined in the native signature.</param>
        public NativeEncodingAttribute(String Name)
        {
        }
    }
    
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
    public sealed class NativeInheritanceAttribute : Attribute
    {
        public NativeInheritanceAttribute(string BaseName)
        {
        }
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
        public NativeTypeNameAttribute(String Name)
        {
        }
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
        public RAIIFreeAttribute(string Name)
        {
        }
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
        public StaticLibraryAttribute(string LibName)
        {
        }
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
