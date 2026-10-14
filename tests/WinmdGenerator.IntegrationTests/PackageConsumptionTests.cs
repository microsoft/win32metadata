using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using Xunit;

namespace WinmdGenerator.IntegrationTests
{
    public class PackageConsumptionTests : IClassFixture<PackageFixture>
    {
        private readonly PackageFixture package;

        public PackageConsumptionTests(PackageFixture package)
        {
            this.package = package;
        }

        [Theory]
        [InlineData("Basic", "x64")]
        [InlineData("Basic", "x86")]
        [InlineData("Basic", "arm64")]
        [InlineData("Basic", "crossarch")]
        [InlineData("ResponseFiles", "x64")]
        public void SdkBuild_EmitsExpectedMetadata(string scenario, string arch)
        {
            string winmd = package.Build(scenario, arch);
            using var stream = File.OpenRead(winmd);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            Assert.True(pe.HasMetadata);
            Assert.Equal("PackageIntegration.winmd", reader.GetString(reader.GetAssemblyDefinition().Name));
            Assert.Equal(new Version(1, 2, 3, 4), reader.GetAssemblyDefinition().Version);

            bool remapped = scenario == "ResponseFiles";
            string recordName = remapped ? "REMAPPED_RECORD" : "ORIGINAL_RECORD";
            var record = FindType(reader, "PackageIntegration", recordName);
            Assert.Equal(TypeAttributes.SequentialLayout, record.Attributes & TypeAttributes.LayoutMask);
            var value = reader.GetFieldDefinition(Assert.Single(record.GetFields()));
            Assert.Equal("value", reader.GetString(value.Name));
            Assert.Equal(new byte[] { 0x06, 0x08 }, reader.GetBlobBytes(value.Signature));
            Assert.DoesNotContain(reader.TypeDefinitions, handle =>
                reader.GetString(reader.GetTypeDefinition(handle).Name) == (remapped ? "ORIGINAL_RECORD" : "REMAPPED_RECORD"));

            string apiNamespace = remapped ? "PackageIntegration.Remapped" : "PackageIntegration";
            var apis = FindType(reader, apiNamespace, "Apis");
            var method = reader.GetMethodDefinition(Assert.Single(apis.GetMethods()));
            Assert.Equal("PackageFunction", reader.GetString(method.Name));
            Assert.True((method.Attributes & MethodAttributes.PinvokeImpl) != 0);
            Assert.Equal(new byte[] { 0x00, 0x01, 0x08, 0x08 }, reader.GetBlobBytes(method.Signature));
            var import = method.GetImport();
            Assert.Equal("PackageFunction", reader.GetString(import.Name));
            Assert.Equal("packageintegration.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));

            var constant = reader.GetFieldDefinition(Assert.Single(apis.GetFields()));
            Assert.Equal("SAMPLE_VALUE", reader.GetString(constant.Name));
            Assert.True((constant.Attributes & FieldAttributes.Literal) != 0);
            var constantValue = reader.GetConstant(constant.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt32, constantValue.TypeCode);
            Assert.Equal(42u, reader.GetBlobReader(constantValue.Value).ReadUInt32());

            string nativeDirectory = Path.Combine(package.PackageDirectory, "tools", "net10.0", "win-x64");
            foreach (string name in new[] { "libclang.dll", "libClangSharp.dll", "MSVCP140.dll", "VCRUNTIME140.dll", "VCRUNTIME140_1.dll" })
            {
                using var nativeStream = File.OpenRead(Path.Combine(nativeDirectory, name));
                using var nativePe = new PEReader(nativeStream);
                Assert.Equal(Machine.Amd64, nativePe.PEHeaders.CoffHeader.Machine);
            }

            Assert.True(File.Exists(Path.Combine(package.PackageDirectory, "ThirdPartyNotices.txt")));
            Assert.Empty(Directory.GetFiles(nativeDirectory, "ucrtbase.dll"));
            Assert.Empty(Directory.GetFiles(nativeDirectory, "api-ms-win-crt-*.dll"));
        }

        private static TypeDefinition FindType(MetadataReader reader, string ns, string name)
        {
            var handle = Assert.Single(reader.TypeDefinitions.Where(handle =>
            {
                var type = reader.GetTypeDefinition(handle);
                return reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == name;
            }));
            return reader.GetTypeDefinition(handle);
        }
    }
}
