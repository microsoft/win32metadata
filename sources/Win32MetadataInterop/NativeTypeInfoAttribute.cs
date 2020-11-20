using System;
using System.Runtime.InteropServices;

namespace Microsoft.Windows.Sdk.Win32Metadata.Interop
{
    public class NativeTypeInfoAttribute : Attribute
    {
        public UnmanagedType ArraySubType;
        //
        // Summary:
        //     Indicates the number of elements in the fixed-length array or the number of characters
        //     (not bytes) in a string to import.
        public int SizeConst;
        //
        // Summary:
        //     Indicates the zero-based parameter that contains the count of array elements,
        //     similar to size_is in COM.
        public short SizeParamIndex;
        //
        // Summary:
        //     Indicates whether the value is const
        public bool IsConst;
        //
        // Summary:
        //     Indicates whether the array is null terminated
        public bool IsNullTerminated;
        //
        // Summary:
        //     Indicates whether the array is terminated by double nulls
        public bool IsNullNullTerminated;
        //
        // Summary:
        //     Initializes a new instance of the System.Runtime.InteropServices.MarshalAsAttribute
        //     class with the specified System.Runtime.InteropServices.UnmanagedType value.
        //
        // Parameters:
        //   unmanagedType:
        //     The value the data is to be marshaled as.
        public NativeTypeInfoAttribute(short unmanagedType)
        {
            Value = (UnmanagedType)unmanagedType;
        }

        //
        // Summary:
        //     Initializes a new instance of the System.Runtime.InteropServices.MarshalAsAttribute
        //     class with the specified System.Runtime.InteropServices.UnmanagedType enumeration
        //     member.
        //
        // Parameters:
        //   unmanagedType:
        //     The value the data is to be marshaled as.
        public NativeTypeInfoAttribute(UnmanagedType unmanagedType)
        {
            Value = (UnmanagedType) unmanagedType;
        }

        //
        // Summary:
        //     Gets the System.Runtime.InteropServices.UnmanagedType value the data is to be
        //     marshaled as.
        //
        // Returns:
        //     The System.Runtime.InteropServices.UnmanagedType value the data is to be marshaled
        //     as.
        public UnmanagedType Value { get; }
    }
}
