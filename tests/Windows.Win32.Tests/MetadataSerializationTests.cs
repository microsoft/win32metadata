using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using MetadataUtils;
using TestCommon;
using Xunit;

namespace Windows.Win32.Tests
{
    public class MetadataSerializationTests
    {
        [Fact]
        public void ExplicitLayoutInstanceFieldsHavePhysicalOffsets()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var image = new PEReader(stream);
            AssertNoDiagnostics(MetadataSerializationValidator.FindMissingFieldLayouts(
                image.GetMetadataReader(MetadataReaderOptions.None)));
        }

        [Fact]
        public void ModuleScopedTypeReferencesResolveToLocalDefinitions()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var image = new PEReader(stream);
            AssertNoDiagnostics(MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(
                image.GetMetadataReader(MetadataReaderOptions.None)));
        }

        private static void AssertNoDiagnostics(IReadOnlyList<MetadataSerializationDiagnostic> diagnostics)
        {
            Assert.True(
                diagnostics.Count == 0,
                string.Join(Environment.NewLine, diagnostics.Select(diagnostic =>
                    $"0x{diagnostic.Token:X8} {diagnostic.Owner}: {diagnostic.Message}")));
        }
    }
}
