using System;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using Xunit;

namespace MetadataUtils.Tests
{
    public class MetadataSerializationValidatorTests
    {
        [Fact]
        public void ExplicitInstanceFieldsRequirePhysicalRowsIncludingOffsetZero()
        {
            using var image = Image(metadata =>
            {
                AddType(metadata, "Test", "Union", TypeAttributes.ExplicitLayout);
                AddField(metadata, "Missing");
                var zero = AddField(metadata, "Zero");
                var nonzero = AddField(metadata, "Nonzero");
                AddField(metadata, "Static", FieldAttributes.Public | FieldAttributes.Static);
                metadata.AddFieldLayout(zero, 0);
                metadata.AddFieldLayout(nonzero, 8);
            });
            var diagnostic = Assert.Single(MetadataSerializationValidator.FindMissingFieldLayouts(Reader(image)));
            Assert.Equal("Test.Union.Missing", diagnostic.Owner);
            Assert.Equal(0x04000001, diagnostic.Token);
        }

        [Theory]
        [InlineData(TypeAttributes.SequentialLayout)]
        [InlineData(TypeAttributes.AutoLayout)]
        public void ImplicitLayoutDoesNotRequireFieldRows(TypeAttributes layout)
        {
            using var image = Image(metadata =>
            {
                AddType(metadata, "Test", "Record", layout);
                AddField(metadata, "Value");
            });
            Assert.Empty(MetadataSerializationValidator.FindMissingFieldLayouts(Reader(image)));
        }

        [Fact]
        public void NestedPhysicalArchitectureVariantsAreCheckedIndividually()
        {
            using var image = Image(metadata =>
            {
                var first = AddType(metadata, "Test", "Outer", TypeAttributes.SequentialLayout);
                var firstUnion = AddType(metadata, "", "Union", TypeAttributes.ExplicitLayout | TypeAttributes.NestedPublic);
                metadata.AddNestedType(firstUnion, first);
                AddArchitecture(metadata, first, 1);
                metadata.AddFieldLayout(AddField(metadata, "Value"), 0);
                var second = AddType(metadata, "Test", "Outer", TypeAttributes.SequentialLayout);
                var secondUnion = AddType(metadata, "", "Union", TypeAttributes.ExplicitLayout | TypeAttributes.NestedPublic);
                metadata.AddNestedType(secondUnion, second);
                AddArchitecture(metadata, second, 6);
                AddField(metadata, "Value");
            });
            var diagnostic = Assert.Single(MetadataSerializationValidator.FindMissingFieldLayouts(Reader(image)));
            Assert.Equal("Test.Outer+Union.Value", diagnostic.Owner);
            Assert.Equal(0x04000002, diagnostic.Token);
        }

        [Fact]
        public void ExternalHResultCannotBeRewrittenAsAnUnresolvedLocalType()
        {
            using var image = Image(metadata =>
            {
                var windows = AddAssemblyReference(metadata, "Windows");
                metadata.AddTypeReference(windows, metadata.GetOrAddString("Windows.Foundation"), metadata.GetOrAddString("HResult"));
                metadata.AddTypeReference(MetadataTokens.EntityHandle(0x00000001), metadata.GetOrAddString("Windows.Foundation"), metadata.GetOrAddString("HResult"));
            });
            var diagnostic = Assert.Single(MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image)));
            Assert.Equal("Windows.Foundation.HResult", diagnostic.Owner);
            Assert.Equal(0x01000002, diagnostic.Token);
        }

        [Fact]
        public void LocalDefinitionsResolveByExactNamespaceAndCase()
        {
            using var image = Image(metadata =>
            {
                AddType(metadata, "Test", "Value", TypeAttributes.SequentialLayout);
                AddReference(metadata, "Test", "Value");
                AddReference(metadata, "Other", "Value");
                AddReference(metadata, "Test", "value");
            });
            Assert.Equal(
                new[] { "Other.Value", "Test.value" },
                MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image)).Select(d => d.Owner));
        }

        [Fact]
        public void LocalNestedReferencesRequireTheExactDeclaringChain()
        {
            using var image = Image(metadata =>
            {
                var parent = AddType(metadata, "Test", "Outer", TypeAttributes.SequentialLayout);
                var nested = AddType(metadata, "", "Inner", TypeAttributes.SequentialLayout | TypeAttributes.NestedPublic);
                metadata.AddNestedType(nested, parent);
                AddType(metadata, "Test", "Other", TypeAttributes.SequentialLayout);
                var outer = AddReference(metadata, "Test", "Outer");
                metadata.AddTypeReference(outer, default, metadata.GetOrAddString("Inner"));
                var other = AddReference(metadata, "Test", "Other");
                metadata.AddTypeReference(other, default, metadata.GetOrAddString("Inner"));
                AddReference(metadata, "Test", "Inner");
            });
            Assert.Equal(
                new[] { "Test.Other+Inner", "Test.Inner" },
                MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image)).Select(d => d.Owner));
        }

        [Fact]
        public void ExternalAndNestedExternalReferencesNeedNoLocalDefinition()
        {
            using var image = Image(metadata =>
            {
                var assembly = AddAssemblyReference(metadata, "External");
                var external = metadata.AddTypeReference(assembly, metadata.GetOrAddString("External"), metadata.GetOrAddString("Outer"));
                metadata.AddTypeReference(external, default, metadata.GetOrAddString("Inner"));
                var module = metadata.AddModuleReference(metadata.GetOrAddString("external.netmodule"));
                metadata.AddTypeReference(module, metadata.GetOrAddString("External"), metadata.GetOrAddString("ModuleType"));
            });
            Assert.Empty(MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image)));
        }

        [Fact]
        public void SameNameArchitectureVariantsAreNotAmbiguousLocalReferences()
        {
            using var image = Image(metadata =>
            {
                foreach (int mask in new[] { 1, 6 })
                {
                    var parent = AddType(metadata, "Test", "Outer", TypeAttributes.SequentialLayout);
                    AddArchitecture(metadata, parent, mask);
                    var nested = AddType(metadata, "", "Inner", TypeAttributes.SequentialLayout | TypeAttributes.NestedPublic);
                    metadata.AddNestedType(nested, parent);
                }

                var outer = AddReference(metadata, "Test", "Outer");
                metadata.AddTypeReference(outer, default, metadata.GetOrAddString("Inner"));
            });
            Assert.Empty(MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image)));
        }

        [Fact]
        public void CyclicTypeReferenceScopesFailWithoutRecursing()
        {
            using var image = Image(metadata =>
            {
                metadata.AddTypeReference(MetadataTokens.TypeReferenceHandle(2), default, metadata.GetOrAddString("First"));
                metadata.AddTypeReference(MetadataTokens.TypeReferenceHandle(1), default, metadata.GetOrAddString("Second"));
            });
            var diagnostics = MetadataSerializationValidator.FindUnresolvedLocalTypeReferences(Reader(image));
            Assert.Equal(2, diagnostics.Count);
            Assert.All(diagnostics, diagnostic => Assert.Contains("cycle", diagnostic.Message));
        }

        private static MetadataReader Reader(PEReader image) => image.GetMetadataReader(MetadataReaderOptions.None);

        private static PEReader Image(Action<MetadataBuilder> configure)
        {
            var metadata = new MetadataBuilder();
            metadata.AddModule(0, metadata.GetOrAddString("Fixture"), metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
            metadata.AddAssembly(metadata.GetOrAddString("Fixture"), new Version(1, 0), default, default, 0, AssemblyHashAlgorithm.None);
            AddType(metadata, "", "<Module>", TypeAttributes.NotPublic);
            configure(metadata);
            var image = new BlobBuilder();
            new ManagedPEBuilder(
                new PEHeaderBuilder(imageCharacteristics: Characteristics.ExecutableImage | Characteristics.Dll),
                new MetadataRootBuilder(metadata),
                new BlobBuilder(),
                flags: CorFlags.ILOnly).Serialize(image);
            return new PEReader(image.ToImmutableArray());
        }

        private static TypeDefinitionHandle AddType(MetadataBuilder metadata, string ns, string name, TypeAttributes attributes)
            => metadata.AddTypeDefinition(
                attributes, metadata.GetOrAddString(ns), metadata.GetOrAddString(name), default,
                MetadataTokens.FieldDefinitionHandle(metadata.GetRowCount(TableIndex.Field) + 1),
                MetadataTokens.MethodDefinitionHandle(1));

        private static FieldDefinitionHandle AddField(MetadataBuilder metadata, string name, FieldAttributes attributes = FieldAttributes.Public)
            => metadata.AddFieldDefinition(attributes, metadata.GetOrAddString(name), metadata.GetOrAddBlob(new byte[] { 0x06, 0x08 }));

        private static TypeReferenceHandle AddReference(MetadataBuilder metadata, string ns, string name)
            => metadata.AddTypeReference(MetadataTokens.EntityHandle(0x00000001), metadata.GetOrAddString(ns), metadata.GetOrAddString(name));

        private static AssemblyReferenceHandle AddAssemblyReference(MetadataBuilder metadata, string name)
            => metadata.AddAssemblyReference(metadata.GetOrAddString(name), new Version(1, 0), default, default, 0, default);

        private static void AddArchitecture(MetadataBuilder metadata, TypeDefinitionHandle type, int mask)
        {
            var assembly = AddAssemblyReference(metadata, "Attribute.Contracts");
            var attribute = metadata.AddTypeReference(
                assembly, metadata.GetOrAddString("Windows.Win32.Foundation.Metadata"), metadata.GetOrAddString("SupportedArchitectureAttribute"));
            var constructor = metadata.AddMemberReference(
                attribute, metadata.GetOrAddString(".ctor"), metadata.GetOrAddBlob(new byte[] { 0x20, 1, 1, 8 }));
            var value = new BlobBuilder();
            value.WriteUInt16(1);
            value.WriteInt32(mask);
            value.WriteUInt16(0);
            metadata.AddCustomAttribute(type, constructor, metadata.GetOrAddBlob(value));
        }
    }
}
