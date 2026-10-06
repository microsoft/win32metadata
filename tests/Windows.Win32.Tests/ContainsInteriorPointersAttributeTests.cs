using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using TestCommon;
using Xunit;

namespace Windows.Win32.Tests
{
    public class ContainsInteriorPointersAttributeTests
    {
        private const string AttributeName = "Windows.Win32.Foundation.Metadata.ContainsInteriorPointersAttribute";

        private static readonly string[] AnnotatedBuffers =
        {
            "AddJobA::pData", "AddJobW::pData",
            "CryptDecodeObject::pvStructInfo",
            "EnumDependentServicesA::lpServices", "EnumDependentServicesW::lpServices",
            "EnumFormsA::pForm", "EnumFormsW::pForm",
            "EnumJobsA::pJob", "EnumJobsW::pJob",
            "EnumMonitorsA::pMonitor", "EnumMonitorsW::pMonitor",
            "EnumPortsA::pPort", "EnumPortsW::pPort",
            "EnumPrinterDataExA::pEnumValues", "EnumPrinterDataExW::pEnumValues",
            "EnumPrinterDriversA::pDriverInfo", "EnumPrinterDriversW::pDriverInfo",
            "EnumPrintersA::pPrinterEnum", "EnumPrintersW::pPrinterEnum",
            "EnumPrintProcessorDatatypesA::pDatatypes", "EnumPrintProcessorDatatypesW::pDatatypes",
            "EnumPrintProcessorsA::pPrintProcessorInfo", "EnumPrintProcessorsW::pPrintProcessorInfo",
            "EnumServicesStatusA::lpServices", "EnumServicesStatusW::lpServices",
            "EnumServicesStatusExA::lpServices", "EnumServicesStatusExW::lpServices",
            "EvtGetChannelConfigProperty::PropertyValueBuffer",
            "EvtGetEventInfo::PropertyValueBuffer",
            "EvtGetEventMetadataProperty::EventMetadataPropertyBuffer",
            "EvtGetObjectArrayProperty::PropertyValueBuffer",
            "EvtGetPublisherMetadataProperty::PublisherMetadataPropertyBuffer",
            "EvtGetQueryInfo::PropertyValueBuffer",
            "EvtRender::Buffer",
            "GdipGetImageDecoders::decoders", "GdipGetImageEncoders::encoders",
            "GetAdaptersAddresses::AdapterAddresses", "GetAdaptersInfo::AdapterInfo",
            "GetFormA::pForm", "GetFormW::pForm",
            "GetJobA::pJob", "GetJobW::pJob",
            "GetOwnerModuleFromTcpEntry::pBuffer",
            "GetPerAdapterInfo::pPerAdapterInfo",
            "GetPrinterA::pPrinter", "GetPrinterW::pPrinter",
            "GetPrinterDriverA::pDriverInfo", "GetPrinterDriverW::pDriverInfo",
            "GetPrinterDriver2W::pDriverInfo",
            "GetTokenInformation::TokenInformation",
            "GetCurrentPackageId::buffer",
            "GetCurrentPackageInfo::buffer", "GetCurrentPackageInfo2::buffer",
            "GetPackageApplicationIds::buffer",
            "GetPackageId::buffer",
            "GetPackageInfo::buffer", "GetPackageInfo2::buffer",
            "PackageIdFromFullName::buffer",
            "HttpReceiveHttpRequest::RequestBuffer",
            "QueryServiceConfigA::lpServiceConfig", "QueryServiceConfigW::lpServiceConfig",
            "QueryServiceConfig2A::lpBuffer", "QueryServiceConfig2W::lpBuffer",
            "QueryServiceLockStatusA::lpLockStatus", "QueryServiceLockStatusW::lpLockStatus",
            "WNetEnumResourceW::lpBuffer",
            "WNetGetResourceInformationW::lpBuffer",
            "WNetGetUniversalNameW::lpBuffer",
            "WSAEnumNameSpaceProvidersA::lpnspBuffer", "WSAEnumNameSpaceProvidersW::lpnspBuffer",
            "WSAEnumNameSpaceProvidersExA::lpnspBuffer", "WSAEnumNameSpaceProvidersExW::lpnspBuffer",
        };

        [Fact]
        public void AttributeIsParameterOnlyAndValueless()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            MetadataReader reader = peReader.GetMetadataReader();
            TypeDefinition type = reader.TypeDefinitions
                .Select(reader.GetTypeDefinition)
                .Single(t => reader.GetString(t.Namespace) + "." + reader.GetString(t.Name) == AttributeName);

            MethodDefinition constructor = type.GetMethods()
                .Select(reader.GetMethodDefinition)
                .Single(m => reader.GetString(m.Name) == ".ctor");
            BlobReader signature = reader.GetBlobReader(constructor.Signature);
            SignatureHeader header = signature.ReadSignatureHeader();
            Assert.Equal(SignatureKind.Method, header.Kind);
            Assert.False(header.IsGeneric);
            Assert.Equal(0, signature.ReadCompressedInteger());
            Assert.Equal(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
            Assert.Equal(0, signature.RemainingBytes);
            Assert.Empty(type.GetFields());

            CustomAttribute usage = type.GetCustomAttributes()
                .Select(reader.GetCustomAttribute)
                .Single(a => GetAttributeTypeName(reader, a) == "System.AttributeUsageAttribute");
            BlobReader blob = reader.GetBlobReader(usage.Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal((int)AttributeTargets.Parameter, blob.ReadInt32());
            Assert.Equal(2, blob.ReadUInt16());
            var namedArguments = new Dictionary<string, bool>();
            for (int i = 0; i < 2; i++)
            {
                byte argumentKind = blob.ReadByte();
                Assert.True(argumentKind == 0x53 || argumentKind == 0x54);
                Assert.Equal((byte)SignatureTypeCode.Boolean, blob.ReadByte());
                namedArguments.Add(blob.ReadSerializedString(), blob.ReadBoolean());
            }

            Assert.False(namedArguments["AllowMultiple"]);
            Assert.False(namedArguments["Inherited"]);
            Assert.Equal(0, blob.RemainingBytes);
        }

        [Fact]
        public void VerifiedBuffersHaveExactlyOneValuelessAnnotation()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            MetadataReader reader = peReader.GetMetadataReader();
            var actual = new HashSet<string>();

            foreach (MethodDefinitionHandle methodHandle in reader.MethodDefinitions)
            {
                MethodDefinition method = reader.GetMethodDefinition(methodHandle);
                foreach (ParameterHandle parameterHandle in method.GetParameters())
                {
                    Parameter parameter = reader.GetParameter(parameterHandle);
                    CustomAttribute[] attributes = parameter.GetCustomAttributes()
                        .Select(reader.GetCustomAttribute)
                        .Where(a => GetAttributeTypeName(reader, a) == AttributeName)
                        .ToArray();
                    if (attributes.Length == 0)
                    {
                        continue;
                    }

                    Assert.Single(attributes);
                    Assert.True(parameter.SequenceNumber > 0, "Return values must not be annotated.");
                    Assert.Equal(new byte[] { 0x01, 0x00, 0x00, 0x00 }, reader.GetBlobBytes(attributes[0].Value));
                    actual.Add(reader.GetString(method.Name) + "::" + reader.GetString(parameter.Name));
                }
            }

            Assert.True(
                actual.SetEquals(AnnotatedBuffers),
                "Missing: " + string.Join(", ", AnnotatedBuffers.Except(actual)) +
                "; unexpected: " + string.Join(", ", actual.Except(AnnotatedBuffers)));
            foreach (CustomAttributeHandle handle in reader.CustomAttributes)
            {
                CustomAttribute attribute = reader.GetCustomAttribute(handle);
                if (GetAttributeTypeName(reader, attribute) == AttributeName)
                {
                    Assert.Equal(HandleKind.Parameter, attribute.Parent.Kind);
                }
            }
        }

        [Theory]
        [InlineData("GetPackagesByPackageFamily")]
        [InlineData("FindPackagesByPackageFamily")]
        [InlineData("GetCurrentPackageInfo3")]
        [InlineData("GetPrinterDriver2A")]
        [InlineData("GetCurrentPackageFullName")]
        [InlineData("PackageFullNameFromId")]
        [InlineData("EnumPrinterKeyA")]
        [InlineData("EnumPrinterKeyW")]
        [InlineData("CryptDecodeObjectEx")]
        [InlineData("EvtGetLogInfo")]
        [InlineData("GetNetworkParams")]
        [InlineData("GetOutlineTextMetricsA")]
        [InlineData("GetOutlineTextMetricsW")]
        [InlineData("NetShareEnum")]
        public void DifferentStorageContractsAreNotAnnotated(string methodName)
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var peReader = new PEReader(stream);
            MetadataReader reader = peReader.GetMetadataReader();
            MethodDefinition[] methods = reader.MethodDefinitions
                .Select(reader.GetMethodDefinition)
                .Where(m => reader.GetString(m.Name) == methodName)
                .ToArray();
            Assert.NotEmpty(methods);
            foreach (MethodDefinition method in methods)
            {
                foreach (ParameterHandle parameterHandle in method.GetParameters())
                {
                    Assert.DoesNotContain(
                        reader.GetParameter(parameterHandle).GetCustomAttributes().Select(reader.GetCustomAttribute),
                        a => GetAttributeTypeName(reader, a) == AttributeName);
                }
            }
        }

        private static string GetAttributeTypeName(MetadataReader reader, CustomAttribute attribute)
        {
            if (attribute.Constructor.Kind == HandleKind.MethodDefinition)
            {
                TypeDefinition type = reader.GetTypeDefinition(
                    reader.GetMethodDefinition((MethodDefinitionHandle)attribute.Constructor).GetDeclaringType());
                return reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
            }

            EntityHandle parent = reader.GetMemberReference((MemberReferenceHandle)attribute.Constructor).Parent;
            if (parent.Kind == HandleKind.TypeDefinition)
            {
                TypeDefinition type = reader.GetTypeDefinition((TypeDefinitionHandle)parent);
                return reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
            }

            TypeReference reference = reader.GetTypeReference((TypeReferenceHandle)parent);
            return reader.GetString(reference.Namespace) + "." + reader.GetString(reference.Name);
        }
    }
}
