using System;
using System.Runtime.InteropServices;

namespace Windows.Win32.Foundation.Metadata;

[AttributeUsage(AttributeTargets.Interface, AllowMultiple = false, Inherited = true)]
public class AgileAttribute : Attribute
{
    public AgileAttribute()
    {
    }
}

public class AlsoUsableForAttribute : Attribute
{
    public AlsoUsableForAttribute(string otherType)
    {
    }
}

public class AnsiAttribute : Attribute
{
    public AnsiAttribute()
    {
    }
}

public class AssociatedEnumAttribute : Attribute
{
    public AssociatedEnumAttribute(string Name)
    {
    }
}

public class CanReturnErrorsAsSuccessAttribute : Attribute
{
    public CanReturnErrorsAsSuccessAttribute()
    {
    }
}

public class CanReturnMultipleSuccessValuesAttribute : Attribute
{
    public CanReturnMultipleSuccessValuesAttribute()
    {
    }
}

[AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
public class ComOutPtrAttribute : Attribute
{
    public ComOutPtrAttribute()
    {
    }
}

public class ConstantAttribute : Attribute
{
    public ConstantAttribute(String Value)
    {
    }
}

public class ConstAttribute : Attribute
{
    public ConstAttribute()
    {
    }
}

[AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
[ComVisible(true)]
public class CppAttributeList : Attribute
{
    public CppAttributeList(String AttributeList)
    {
    }
}

public class DoNotReleaseAttribute : Attribute
{
    public DoNotReleaseAttribute()
    {
    }
}

[AttributeUsage(AttributeTargets.Field, AllowMultiple = false, Inherited = false)]
public class FlexibleArrayAttribute : Attribute
{
    public FlexibleArrayAttribute()
    {
    }
}

[AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
[ComVisible(true)]
public class FreeWithAttribute : Attribute
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

[AttributeUsage(AttributeTargets.Parameter, AllowMultiple = true)]
public class IgnoreIfReturnAttribute : Attribute
{
    public IgnoreIfReturnAttribute(String Value)
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
    public short BytesParamIndex;

    public MemorySizeAttribute()
    {
    }
}

[AttributeUsage(AttributeTargets.Struct, AllowMultiple = false)]
public class MetadataTypedefAttribute : Attribute
{
    public MetadataTypedefAttribute()
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
public class NativeEncodingAttribute : Attribute
{
    /// <summary>Initializes a new instance of the <see cref="NativeEncodingAttribute" /> class.</summary>
    /// <param name="name">The encoding of a string as it was defined in the native signature.</param>
    public NativeEncodingAttribute(String Name)
    {
    }
}

[AttributeUsage(AttributeTargets.Struct, AllowMultiple = false, Inherited = true)]
public class NativeInheritanceAttribute : Attribute
{
    public NativeInheritanceAttribute(string BaseName)
    {
    }
}

[AttributeUsage(AttributeTargets.Struct, AllowMultiple = false)]
public class NativeTypedefAttribute : Attribute
{
    public NativeTypedefAttribute()
    {
    }
}

/// <summary>Defines the type of a member as it was used in the native signature.</summary>
//[Conditional("DEBUG")]
[AttributeUsage(AttributeTargets.Enum | AttributeTargets.Property | AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
[ComVisible(true)]
public class NativeTypeNameAttribute : Attribute
{
    /// <summary>Initializes a new instance of the <see cref="NativeTypeNameAttribute" /> class.</summary>
    /// <param name="name">The name of the type that was used in the native signature.</param>
    public NativeTypeNameAttribute(String Name)
    {
    }
}

public class NotNullTerminatedAttribute : Attribute
{
    public NotNullTerminatedAttribute()
    {
    }
}

public class NullNullTerminatedAttribute : Attribute
{
    public NullNullTerminatedAttribute()
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
    public ReservedAttribute()
    {
    }
}

public class ReturnsUnownedHandle : Attribute
{
    public ReturnsUnownedHandle()
    {
    }
}

[AttributeUsage(AttributeTargets.Parameter, AllowMultiple = false, Inherited = true)]
public class RetValAttribute : Attribute
{
    public RetValAttribute()
    {
    }
}

public class ScopedEnumAttribute : Attribute
{
    public ScopedEnumAttribute()
    {
    }
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

public class UnicodeAttribute : Attribute
{
    public UnicodeAttribute()
    {
    }
}