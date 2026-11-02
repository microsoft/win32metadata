using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.Metadata.Ecma335;
using System.Reflection.PortableExecutable;
using TestCommon;
using Win32MetadataTestCases;
using Xunit;
using Xunit.Abstractions;

namespace Windows.Win32.Tests
{
    public class IntegrityTests
    {
        private ITestOutputHelper outputHelper;

        public IntegrityTests(ITestOutputHelper outputHelper)
        {
            this.outputHelper = outputHelper;
        }

        [Fact]
        public void NoDuplicateImports()
        {
            string allowedDuplicateImportsFileName = TestUtils.GetAssetFile("duplicateImportsAllowList.rsp");
            string args = $"showDuplicateImports --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedDuplicateImportsFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoDuplicateTypes()
        {
            string args = $"showDuplicateTypes --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoDuplicateConstants()
        {
            string allowedDuplicateConstantsFileName = TestUtils.GetAssetFile("duplicateConstantsAllowList.rsp");
            string args = $"showDuplicateConstants --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedDuplicateConstantsFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoInvalidEmptyDelegates()
        {
            string allowedEmptyDelegatesFileName = TestUtils.GetAssetFile("emptyDelegatesAllowList.rsp");
            string args = $"showEmptyDelegates --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedEmptyDelegatesFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoInvalidPointersToDelegates()
        {
            string pointersToDelegatesFileName = TestUtils.GetAssetFile("pointersToDelegatesAllowList.rsp");
            string args = $"showPointersToDelegates --winmd \"{TestUtils.Win32WinmdPath}\" \"@{pointersToDelegatesFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoSuggestedRemappings()
        {
            string suggestedRemappingsFileName = TestUtils.GetAssetFile("suggestedRemappingsAllowList.rsp");
            string projectRoot = Environment.GetEnvironmentVariable("WIN32_METADATA_TEST_PROJECT");
            if (string.IsNullOrEmpty(projectRoot))
                projectRoot = Path.GetFullPath(Path.Combine(TestUtils.Win32WinmdPath, "../../generation/WinSDK"));
            if (!Directory.Exists(projectRoot))
                throw new DirectoryNotFoundException("The explicitly selected integrity-test SDK project does not exist: " + projectRoot);
            string args = $"showSuggestedRemappings --winmd \"{TestUtils.Win32WinmdPath}\" \"@{suggestedRemappingsFileName}\" --projectRoot \"{projectRoot}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoBrokenArchTypes()
        {
            string args = $"showBrokenArchTypes --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoCyclicalNamespaces()
        {
            string args = $"showNamespaceCycles --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void ConstructorsHaveInstanceSignatures()
        {
            using var image = new PEReader(File.OpenRead(TestUtils.Win32WinmdPath));
            var reader = image.GetMetadataReader(MetadataReaderOptions.None);
            int constructorCount = 0;
            foreach (var handle in reader.MethodDefinitions)
            {
                var method = reader.GetMethodDefinition(handle);
                if (reader.GetString(method.Name) != ".ctor")
                    continue;
                constructorCount++;
                var signature = reader.GetBlobReader(method.Signature);
                string typeName = reader.GetString(reader.GetTypeDefinition(method.GetDeclaringType()).Name);
                Assert.True(signature.ReadSignatureHeader().IsInstance, $"Constructor of '{typeName}' lacks HASTHIS.");
                Assert.False(method.Attributes.HasFlag(MethodAttributes.Static));
            }
            Assert.True(constructorCount > 0);
        }

        [Theory]
        [InlineData(1, 4)]
        [InlineData(2, 16)]
        [InlineData(4, 16)]
        public void SListEntriesPreserveNativeRecordLayout(int architecture, int size)
        {
            using var image = new PEReader(File.OpenRead(TestUtils.Win32WinmdPath));
            var reader = image.GetMetadataReader(MetadataReaderOptions.None);
            var record = Assert.Single(reader.TypeDefinitions
                .Select(handle => reader.GetTypeDefinition(handle))
                .Where(type => reader.GetString(type.Namespace) == "Windows.Win32.System.Kernel" &&
                    reader.GetString(type.Name) == "SLIST_ENTRY" &&
                    (ReadSupportedArchitectures(reader, type.GetCustomAttributes()) & architecture) != 0));

            if (architecture == 1)
            {
                Assert.Equal(size, NativeContractPhysicalAssertions.X86SinglePointerRecordSize(reader, record));
                return;
            }

            Assert.Equal(size, record.GetLayout().Size);
            var attributeHandle = Assert.Single(record.GetCustomAttributes()
                .Where(handle => AttributeTypeName(reader, handle) ==
                    "Windows.Win32.Foundation.Metadata.AlignmentAttribute"));
            var value = reader.GetBlobReader(reader.GetCustomAttribute(attributeHandle).Value);
            Assert.Equal(1, value.ReadUInt16());
            Assert.Equal(size, value.ReadInt32());
            Assert.Equal(0, value.ReadUInt16());
            Assert.Equal(0, value.RemainingBytes);
        }

        [Fact]
        public void X86PointerRecordSizeRejectsBrokenPhysicalStorage()
        {
            foreach (var (fieldCount, wideField, offset, attributes, classSize, valid) in new[]
            {
                (1, false, -1, FieldAttributes.Public, 0, true),
                (1, false, -1, FieldAttributes.Public, 4, true),
                (0, false, -1, FieldAttributes.Public, 0, false),
                (2, false, -1, FieldAttributes.Public, 0, false),
                (1, true, -1, FieldAttributes.Public, 0, false),
                (1, false, 4, FieldAttributes.Public, 0, false),
                (1, false, -1, FieldAttributes.Public | FieldAttributes.Static, 0, false),
                (1, false, -1, FieldAttributes.Public, 8, false),
            })
            {
                using var image = PointerRecordMetadata(fieldCount, wideField, offset, attributes, classSize);
                var reader = image.GetMetadataReader(MetadataReaderOptions.None);
                var record = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == "SLIST_ENTRY"));
                if (valid)
                    Assert.Equal(4, NativeContractPhysicalAssertions.X86SinglePointerRecordSize(reader, record));
                else
                    Assert.ThrowsAny<Xunit.Sdk.XunitException>(() =>
                        Assert.Equal(4, NativeContractPhysicalAssertions.X86SinglePointerRecordSize(reader, record)));
            }
        }

        private static MetadataReaderProvider PointerRecordMetadata(
            int fieldCount, bool wideField, int offset, FieldAttributes attributes, int classSize)
        {
            var metadata = new MetadataBuilder();
            metadata.AddModule(0, metadata.GetOrAddString("pointer-record.dll"),
                metadata.GetOrAddGuid(Guid.NewGuid()), default, default);
            var assembly = metadata.AddAssemblyReference(metadata.GetOrAddString("mscorlib"),
                new Version(4, 0, 0, 0), default, default, default, default);
            var baseType = metadata.AddTypeReference(assembly,
                metadata.GetOrAddString("System"), metadata.GetOrAddString("ValueType"));
            var fields = MetadataTokens.FieldDefinitionHandle(1);
            var methods = MetadataTokens.MethodDefinitionHandle(1);
            metadata.AddTypeDefinition(TypeAttributes.NotPublic, default,
                metadata.GetOrAddString("<Module>"), default, fields, methods);
            var record = metadata.AddTypeDefinition(TypeAttributes.Public |
                (offset < 0 ? TypeAttributes.SequentialLayout : TypeAttributes.ExplicitLayout),
                metadata.GetOrAddString("Windows.Win32.System.Kernel"),
                metadata.GetOrAddString("SLIST_ENTRY"), baseType, fields, methods);
            if (classSize != 0)
                metadata.AddTypeLayout(record, 0, (uint)classSize);
            for (int index = 0; index < fieldCount; index++)
            {
                var signature = new BlobBuilder();
                var encoder = new BlobEncoder(signature).FieldSignature();
                if (wideField)
                    encoder.UInt64();
                else
                    encoder.Pointer().Type(record, isValueType: true);
                var field = metadata.AddFieldDefinition(attributes,
                    metadata.GetOrAddString(index == 0 ? "Next" : "Extra"), metadata.GetOrAddBlob(signature));
                if (offset >= 0)
                    metadata.AddFieldLayout(field, offset);
            }
            var bytes = new BlobBuilder();
            new MetadataRootBuilder(metadata).Serialize(bytes, methodBodyStreamRva: 0, mappedFieldDataStreamRva: 0);
            return MetadataReaderProvider.FromMetadataImage(bytes.ToImmutableArray());
        }

        private static int ReadSupportedArchitectures(MetadataReader reader, CustomAttributeHandleCollection attributes)
        {
            var matches = attributes.Where(handle => AttributeTypeName(reader, handle) ==
                "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute").ToArray();
            if (matches.Length == 0)
                return 7;

            var value = reader.GetBlobReader(reader.GetCustomAttribute(Assert.Single(matches)).Value);
            Assert.Equal(1, value.ReadUInt16());
            int architectures = value.ReadInt32();
            Assert.InRange(architectures, 1, 7);
            Assert.Equal(0, value.ReadUInt16());
            Assert.Equal(0, value.RemainingBytes);
            return architectures;
        }

        private static string AttributeTypeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            EntityHandle type = constructor.Kind switch
            {
                HandleKind.MemberReference => reader.GetMemberReference((MemberReferenceHandle)constructor).Parent,
                HandleKind.MethodDefinition => reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType(),
                _ => throw new BadImageFormatException($"Invalid attribute constructor kind: {constructor.Kind}.")
            };
            var names = type.Kind switch
            {
                HandleKind.TypeReference => (Namespace: reader.GetTypeReference((TypeReferenceHandle)type).Namespace,
                    Name: reader.GetTypeReference((TypeReferenceHandle)type).Name),
                HandleKind.TypeDefinition => (Namespace: reader.GetTypeDefinition((TypeDefinitionHandle)type).Namespace,
                    Name: reader.GetTypeDefinition((TypeDefinitionHandle)type).Name),
                _ => throw new BadImageFormatException($"Invalid attribute type kind: {type.Kind}.")
            };
            return reader.GetString(names.Namespace) + "." + reader.GetString(names.Name);
        }

        private void ExecWinmdUtils(string args)
        {
            string winmdUtilsDll = Path.Combine(TestUtils.BinPath, "winmdutils.dll");
            string fullArgs = $"\"{winmdUtilsDll}\" {args}";
            int ret = TestUtils.ExecuteCmd("dotnet", fullArgs, out var outputText, this.outputHelper);
            this.outputHelper.WriteLine(outputText);
            Assert.Equal(0, ret);
        }
    }
}
