using System;
using System.Collections.Generic;
using System.Linq;
using ICSharpCode.Decompiler.TypeSystem;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{

    public class RaiiFreeAttributeTests
    {
        private static readonly HashSet<string> ExcludedTypes = new HashSet<string>(StringComparer.Ordinal)
        {
            "Windows.Win32.Foundation.BSTR", // Not a handle type
            "Windows.Win32.System.SystemServices.BSTR", // Native-header owner of the same non-handle type
            "Windows.Win32.System.WinRT.HSTRING", // Has no invalid handle value
            "Windows.Win32.System.Threading.LPPROC_THREAD_ATTRIBUTE_LIST", // Not a handle type
            "Windows.Win32.System.Threading.PPROC_THREAD_ATTRIBUTE_LIST", // Sibling alias in the same native typedef
        };

        [Fact]
        public void AllRaiiTypesHaveInvalidHandleValueAttribute()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            var structsMissingMetadata = FindRaiiTypesMissingInvalidHandleValue(typeSystem.MainModule.TypeDefinitions);

            Assert.True(!structsMissingMetadata.Any(),
                $"RAII structs missing InvalidHandleValue attribute:{Environment.NewLine}" +
                string.Join(Environment.NewLine, structsMissingMetadata.Select(structName => $"- {structName}")));
        }

        public static IEnumerable<string> FindRaiiTypesMissingInvalidHandleValue(IEnumerable<ITypeDefinition> types)
        {
            return types
                .Where(type => type.Kind == TypeKind.Struct)
                .Where(type => type.GetAttributes().Any(attr => attr.AttributeType.Name == "RAIIFreeAttribute"))
                .Where(type => !type.GetAttributes().Any(attr => attr.AttributeType.Name == "InvalidHandleValueAttribute"))
                .Where(type => !ExcludedTypes.Contains(type.FullName))
                .Select(type => type.FullName);
        }

        [Theory]
        [InlineData("Windows.Win32.Foundation.BSTR", true)]
        [InlineData("Windows.Win32.System.SystemServices.BSTR", true)]
        [InlineData("Windows.Win32.System.WinRT.HSTRING", true)]
        [InlineData("Windows.Win32.System.Threading.LPPROC_THREAD_ATTRIBUTE_LIST", true)]
        [InlineData("Windows.Win32.System.Threading.PPROC_THREAD_ATTRIBUTE_LIST", true)]
        [InlineData("Other.BSTR", false)]
        [InlineData("Other.PPROC_THREAD_ATTRIBUTE_LIST", false)]
        [InlineData("Windows.Win32.System.SystemServices.bstr", false)]
        [InlineData("Windows.Win32.System.Threading.PROC_THREAD_ATTRIBUTE_LIST", false)]
        [InlineData("Windows.Win32.Foundation.HANDLE", false)]
        public void NonHandleExemptionsUseExactQualifiedIdentities(string name, bool excluded)
        {
            Assert.Equal(excluded, ExcludedTypes.Contains(name));
        }

        [Fact]
        public void UnknownRaiiValuesAndHandlesStillRequireInvalidValues()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(typeof(RaiiFreeAttributeTests).Assembly.Location);
            var controls = typeSystem.MainModule.TypeDefinitions
                .Where(type => type.Name == nameof(UnknownRaiiValue) ||
                    type.Name == nameof(HandleWithoutInvalidValue) ||
                    type.Name == nameof(HandleWithInvalidValue))
                .ToArray();
            Assert.Equal(3, controls.Length);
            Assert.Equal(
                controls.Where(type => type.Name != nameof(HandleWithInvalidValue)).Select(type => type.FullName).OrderBy(name => name),
                FindRaiiTypesMissingInvalidHandleValue(controls).OrderBy(name => name));
        }

        private sealed class RAIIFreeAttribute : Attribute
        {
        }

        private sealed class InvalidHandleValueAttribute : Attribute
        {
        }

        [RAIIFree]
        private struct UnknownRaiiValue
        {
            public IntPtr Value { get; set; }
        }

        [RAIIFree]
        private struct HandleWithoutInvalidValue
        {
            public IntPtr Value { get; set; }
        }

        [RAIIFree, InvalidHandleValue]
        private struct HandleWithInvalidValue
        {
            public IntPtr Value { get; set; }
        }
    }
}
