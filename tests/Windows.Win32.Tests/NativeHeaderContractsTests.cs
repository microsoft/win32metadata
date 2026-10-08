using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using MetadataUtils;
using TestCommon;
using Xunit;

namespace Windows.Win32.Tests
{
    public class NativeHeaderContractsTests : IDisposable
    {
        private const string FileSystemNamespace = "Windows.Win32.Storage.FileSystem";
        private const string MediaFoundationNamespace = "Windows.Win32.Media.MediaFoundation";
        private readonly PEReader image;
        private readonly MetadataReader reader;
        private readonly GenericSignatureTypeProvider signatureProvider = new GenericSignatureTypeProvider();

        public NativeHeaderContractsTests()
        {
            this.image = new PEReader(File.OpenRead(TestUtils.Win32WinmdPath));
            this.reader = this.image.GetMetadataReader(MetadataReaderOptions.None);
        }

        [Fact]
        public void FileDeviceTypeHasExactlyTheNativeUnsignedValues()
        {
            var type = this.GetTypeDefinition(FileSystemNamespace, "FILE_DEVICE_TYPE");
            Assert.Equal(HandleKind.TypeReference, type.BaseType.Kind);
            var baseType = this.reader.GetTypeReference((TypeReferenceHandle)type.BaseType);
            Assert.Equal("System", this.reader.GetString(baseType.Namespace));
            Assert.Equal("Enum", this.reader.GetString(baseType.Name));
            var fields = type.GetFields().Select(this.reader.GetFieldDefinition).ToArray();
            var underlying = Assert.Single(fields.Where(field => this.reader.GetString(field.Name) == "value__"));
            Assert.Equal("uint", underlying.DecodeSignature(this.signatureProvider, null));

            var expected = new Dictionary<string, uint>
            {
                { "FILE_DEVICE_CD_ROM", 2 },
                { "FILE_DEVICE_DISK", 7 },
                { "FILE_DEVICE_TAPE", 31 },
                { "FILE_DEVICE_DVD", 51 },
            };
            var literals = fields.Where(field => (field.Attributes & FieldAttributes.Literal) != 0).ToArray();
            Assert.Equal(expected.Count, literals.Length);
            Assert.Equal(expected.Keys.OrderBy(name => name), literals.Select(field => this.reader.GetString(field.Name)).OrderBy(name => name));
            foreach (var field in literals)
            {
                var constant = this.reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.UInt32, constant.TypeCode);
                var value = this.reader.GetBlobReader(constant.Value);
                Assert.Equal(expected[this.reader.GetString(field.Name)], value.ReadUInt32());
                Assert.Equal(0, value.RemainingBytes);
            }
        }

        [Theory]
        [InlineData("NTMS_MEDIATYPEINFORMATION")]
        [InlineData("NTMS_DRIVETYPEINFORMATIONA")]
        [InlineData("NTMS_DRIVETYPEINFORMATIONW")]
        public void NtmsDeviceTypeKeepsDwordAndResolvesItsPhysicalEnum(string name)
        {
            var type = this.GetTypeDefinition(FileSystemNamespace, name);
            var field = Assert.Single(type.GetFields().Select(this.reader.GetFieldDefinition)
                .Where(item => this.reader.GetString(item.Name) == "DeviceType"));
            Assert.Equal("uint", field.DecodeSignature(this.signatureProvider, null));

            var attribute = Assert.Single(field.GetCustomAttributes().Select(this.reader.GetCustomAttribute)
                .Where(item => this.GetAttributeTypeName(item) == "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute"));
            var value = this.reader.GetBlobReader(attribute.Value);
            Assert.Equal(1, value.ReadUInt16());
            Assert.Equal("FILE_DEVICE_TYPE", value.ReadSerializedString());
            Assert.Equal(0, value.ReadUInt16());
            Assert.Equal(0, value.RemainingBytes);

            this.GetTypeDefinition(FileSystemNamespace, "FILE_DEVICE_TYPE");
        }

        [Fact]
        public void WtsCurrentUserAccessIncludesEveryNativeFlag()
        {
            var type = this.GetTypeDefinition("Windows.Win32.System.RemoteDesktop", "Apis");
            var field = Assert.Single(type.GetFields().Select(this.reader.GetFieldDefinition)
                .Where(item => this.reader.GetString(item.Name) == "WTS_SECURITY_CURRENT_USER_ACCESS"));
            var constant = this.reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.Int32, constant.TypeCode);
            var value = this.reader.GetBlobReader(constant.Value);
            Assert.Equal(590, value.ReadInt32());
            Assert.Equal(0, value.RemainingBytes);
        }

        [Theory]
        [InlineData("OPMXboxEnableHDCP", new[] { MediaFoundationNamespace + ".OPM_HDCP_TYPE" }, new[] { "HDCPType" })]
        [InlineData("OPMXboxGetHDCPStatus", new[] { MediaFoundationNamespace + ".OPM_HDCP_STATUS*" }, new[] { "pHDCPStatus" })]
        [InlineData("OPMXboxGetHDCPStatusAndType", new[] { MediaFoundationNamespace + ".OPM_HDCP_STATUS*", MediaFoundationNamespace + ".OPM_HDCP_TYPE*" }, new[] { "pHDCPStatus", "pHDCPType" })]
        public void OpmXboxImportsKeepTheNativeCSignature(string name, string[] parameterTypes, string[] parameterNames)
        {
            var type = this.GetTypeDefinition(MediaFoundationNamespace, "Apis");
            var methods = type.GetMethods().Select(this.reader.GetMethodDefinition)
                .Where(method => this.reader.GetString(method.Name) == name).ToArray();
            Assert.NotEmpty(methods);
            foreach (var method in methods)
            {
                Assert.True((method.Attributes & MethodAttributes.PinvokeImpl) != 0);
                var import = method.GetImport();
                Assert.Equal("opmxbox.dll", this.reader.GetString(this.reader.GetModuleReference(import.Module).Name), ignoreCase: true);
                Assert.Equal(name, this.reader.GetString(import.Name));
                Assert.Equal(MethodImportAttributes.CallingConventionCDecl, import.Attributes & MethodImportAttributes.CallingConventionMask);

                var signature = method.DecodeSignature(this.signatureProvider, null);
                Assert.Equal("Windows.Win32.Foundation.HRESULT", signature.ReturnType);
                Assert.Equal(parameterTypes, signature.ParameterTypes.ToArray());
                var parameters = method.GetParameters().Select(this.reader.GetParameter)
                    .Where(parameter => parameter.SequenceNumber != 0).OrderBy(parameter => parameter.SequenceNumber).ToArray();
                Assert.Equal(parameterNames, parameters.Select(parameter => this.reader.GetString(parameter.Name)).ToArray());
                for (var i = 0; i < parameters.Length; i++)
                {
                    var direction = parameters[i].Attributes & (ParameterAttributes.In | ParameterAttributes.Out);
                    if (parameterTypes[i].EndsWith("*", StringComparison.Ordinal))
                    {
                        Assert.Equal(ParameterAttributes.In | ParameterAttributes.Out, direction);
                    }
                    else
                    {
                        Assert.Equal((ParameterAttributes)0, direction & ParameterAttributes.Out);
                    }
                }
            }
        }

        public void Dispose()
        {
            this.image.Dispose();
        }

        private TypeDefinition GetTypeDefinition(string typeNamespace, string name)
        {
            return Assert.Single(this.reader.TypeDefinitions.Select(this.reader.GetTypeDefinition)
                .Where(type => this.reader.GetString(type.Namespace) == typeNamespace && this.reader.GetString(type.Name) == name));
        }

        private string GetAttributeTypeName(CustomAttribute attribute)
        {
            var parent = attribute.Constructor.Kind switch
            {
                HandleKind.MemberReference => this.reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor).Parent,
                HandleKind.MethodDefinition => this.reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).GetDeclaringType(),
                _ => throw new InvalidOperationException($"Unexpected attribute constructor: {attribute.Constructor.Kind}"),
            };
            if (parent.Kind == HandleKind.TypeDefinition)
            {
                var type = this.reader.GetTypeDefinition((TypeDefinitionHandle)parent);
                return this.reader.GetString(type.Namespace) + "." + this.reader.GetString(type.Name);
            }

            Assert.Equal(HandleKind.TypeReference, parent.Kind);
            var reference = this.reader.GetTypeReference((TypeReferenceHandle)parent);
            return this.reader.GetString(reference.Namespace) + "." + this.reader.GetString(reference.Name);
        }
    }
}
