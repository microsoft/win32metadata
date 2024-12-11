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
        [Fact]
        public void AllRaiiTypesHaveInvalidHandleValueAttribute()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            var excludedTypes = new HashSet<string>
            {
                "Windows.Win32.Foundation.BSTR", // Not a handle type
                "Windows.Win32.System.WinRT.HSTRING", // Has no invalid handle value
                "Windows.Win32.System.Threading.LPPROC_THREAD_ATTRIBUTE_LIST", // Not a handle type
            };

            var structsMissingMetadata = typeSystem.MainModule.TypeDefinitions
                .Where(type => type.Kind == TypeKind.Struct)
                .Where(type => type.GetAttributes().Any(attr => attr.AttributeType.Name == "RAIIFreeAttribute"))
                .Where(type => !type.GetAttributes().Any(attr => attr.AttributeType.Name == "InvalidHandleValueAttribute"))
                .Where(type => !excludedTypes.Contains(type.FullName))
                .Select(type => type.FullName);

            Assert.True(!structsMissingMetadata.Any(),
                $"RAII structs missing InvalidHandleValue attribute:{Environment.NewLine}" +
                string.Join(Environment.NewLine, structsMissingMetadata.Select(structName => $"- {structName}")));
        }
    }
}
