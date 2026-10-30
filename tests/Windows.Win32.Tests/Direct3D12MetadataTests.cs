using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using TestCommon;
using Xunit;

namespace Windows.Win32.Tests
{
    public class Direct3D12MetadataTests
    {
        [Fact]
        public void SdkAndWindowsMetadataHaveUniqueTypeOwnership()
        {
            using var windowsStream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var windowsPe = new PEReader(windowsStream);
            using var sdkStream = File.OpenRead(TestUtils.Direct3D12WinmdPath);
            using var sdkPe = new PEReader(sdkStream);
            MetadataReader windows = windowsPe.GetMetadataReader(MetadataReaderOptions.None);
            MetadataReader sdk = sdkPe.GetMetadataReader(MetadataReaderOptions.None);
            var windowsTypes = GetTypeNames(windows);
            var sdkTypes = GetTypeNames(sdk);

            Assert.Empty(windowsTypes.Intersect(sdkTypes).Where(name => name != "<Module>"));
            Assert.DoesNotContain(windowsTypes, name => name.StartsWith("Windows.Win32.Graphics.Direct3D12.", StringComparison.Ordinal));
            Assert.Contains("Windows.Win32.Graphics.Direct3D12.ID3D12Device", sdkTypes);
            Assert.Contains("Windows.Win32.Media.MediaFoundation.ID3D12VideoDecoder", windowsTypes);
            Assert.Contains("Windows.Win32.Graphics.Direct3D11on12.ID3D11On12Device", windowsTypes);
        }

        [Theory]
        [InlineData("DML_BINDING_TABLE_DESC", "CPUDescriptorHandle", "D3D12_CPU_DESCRIPTOR_HANDLE", 0x11)]
        [InlineData("DML_BINDING_TABLE_DESC", "GPUDescriptorHandle", "D3D12_GPU_DESCRIPTOR_HANDLE", 0x11)]
        [InlineData("DML_BUFFER_BINDING", "Buffer", "ID3D12Resource", 0x12)]
        public void WindowsInteropFieldsReferenceSdkWithCorrectTypeKind(string owner, string fieldName, string typeName, int signatureKind)
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Name) == owner);
            FieldDefinition field = type.GetFields().Select(reader.GetFieldDefinition)
                .Single(definition => reader.GetString(definition.Name) == fieldName);
            BlobReader signature = reader.GetBlobReader(field.Signature);
            Assert.Equal(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.Equal(signatureKind, signature.ReadByte());
            TypeReference reference = reader.GetTypeReference((TypeReferenceHandle)signature.ReadTypeHandle());
            Assert.Equal(typeName, reader.GetString(reference.Name));
            AssertSdkScope(reader, reference);
        }

        [Fact]
        public void WindowsVideoInterfaceKeepsOnlyItsOwnVtableSlots()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            TypeDefinition decoder = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "ID3D12VideoDecoder");
            Assert.Equal(new[] { "GetDesc" }, decoder.GetMethods().Select(reader.GetMethodDefinition)
                .Select(method => reader.GetString(method.Name)).ToArray());
            TypeReference inherited = reader.GetTypeReference((TypeReferenceHandle)reader.GetInterfaceImplementation(
                decoder.GetInterfaceImplementations().Single()).Interface);
            Assert.Equal("ID3D12Pageable", reader.GetString(inherited.Name));
            AssertSdkScope(reader, inherited);
        }

        private static string[] GetTypeNames(MetadataReader reader)
        {
            return reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => !type.IsNested)
                .Select(type => string.IsNullOrEmpty(reader.GetString(type.Namespace))
                    ? reader.GetString(type.Name)
                    : reader.GetString(type.Namespace) + "." + reader.GetString(type.Name)).ToArray();
        }

        private static void AssertSdkScope(MetadataReader reader, TypeReference reference)
        {
            Assert.Equal(HandleKind.AssemblyReference, reference.ResolutionScope.Kind);
            Assert.Equal("Microsoft.Direct3D.D3D12.winmd",
                reader.GetString(reader.GetAssemblyReference((AssemblyReferenceHandle)reference.ResolutionScope).Name));
        }
    }
}
