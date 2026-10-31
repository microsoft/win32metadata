using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using static Win32MetadataScraperTests.HeaderAnnotationWinmdTests;

namespace Win32MetadataScraperTests
{
    public class NativeLoweringRegressionTests
    {
        [Fact]
        public void NativeLoweringBatchPreservesContractsAcrossArchitectures()
        {
            foreach (var (architecture, target) in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
            {
                Console.WriteLine($"Native lowering batch: architecture={architecture}; target={target}");
                NativeTypedefEnumExpressionsPreserveTheirDeclaredStorage(architecture, target);
                NominalRecordAndItsSameNameTypedefRecoverOneCompleteProvider(architecture, target, false);
                NominalRecordAndItsSameNameTypedefRecoverOneCompleteProvider(architecture, target, true);
                HeaderEnumOwnsCompatibleInferredScalarAliasesFromOtherHeaders(architecture, target);
                AlternateNativeRecordDefinitionsCompareEquivalentCharacterPointerStorage(architecture, target);
            }
        }

        private static void NativeTypedefEnumExpressionsPreserveTheirDeclaredStorage(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned long DWORD;
typedef unsigned char BYTE;
typedef unsigned int UINT32;
typedef unsigned char UINT8;
enum PixelFormat {
    PackedPixel = ((DWORD)((BYTE)('U')) | ((DWORD)((BYTE)('Y')) << 8) |
        ((DWORD)((BYTE)('V')) << 16) | ((DWORD)((BYTE)('Y')) << 24))
};
enum FeatureTag {
    PackedFeature = ((UINT32)(UINT8)('a')) | (((UINT32)(UINT8)('a')) << 8) |
        (((UINT32)(UINT8)('l')) << 16) | (((UINT32)(UINT8)('t')) << 24)
};
enum PropertyFormat { TextFormat = 3 };
enum PropertyType { NameType = 4 };
enum PropertySyntax {
    PackedProperty = ((DWORD)(((PropertyType)(NameType)) << 16 | (PropertyFormat)(TextFormat)))
};
enum AxisTag : UINT32 {
    PackedAxis = ((UINT32)(UINT8)('w')) | (((UINT32)(UINT8)('g')) << 8) |
        (((UINT32)(UINT8)('h')) << 16) | (((UINT32)(UINT8)('t')) << 24)
};
extern ""C"" {
PixelFormat ReadPixel(PixelFormat value);
FeatureTag ReadFeature(FeatureTag value);
PropertySyntax ReadProperty(PropertySyntax value);
AxisTag ReadAxis(AxisTag value);
}
");
            fixture.AssertSuccess();
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            AssertEnum(reader, "PixelFormat", "PackedPixel", SignatureTypeCode.Int32, 0x59565955);
            AssertEnum(reader, "FeatureTag", "PackedFeature", SignatureTypeCode.Int32, 0x746C6161);
            AssertEnum(reader, "PropertySyntax", "PackedProperty", SignatureTypeCode.Int32, 0x00040003);
            AssertEnum(reader, "AxisTag", "PackedAxis", SignatureTypeCode.UInt32, 0x74686777);
            AssertMetadataClosure(reader);
        }

        private static void NominalRecordAndItsSameNameTypedefRecoverOneCompleteProvider(
            string architecture, string target, bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef struct Token__ { int unused; } Token__;
typedef Token__* Token;
typedef Token__* OtherToken;
extern ""C"" Token ReadToken(Token value, OtherToken other);
", annotationsEnabled, extraSettings: "--config\nexclude-empty-records");
            fixture.AssertSuccess();
            var provider = SyntaxFactory.ParseCompilationUnit(fixture.ReadSource())
                .DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(declaration => declaration.Identifier.ValueText == "Token__");
            var field = Assert.Single(provider.Members.OfType<FieldDeclarationSyntax>());
            Assert.Equal("unused", Assert.Single(field.Declaration.Variables).Identifier.ValueText);
            using var image = Emit(fixture, architecture);
            var signature = image.Reader.GetBlobReader(FindMethod(image.Reader, "Apis", "ReadToken").Signature);
            signature.ReadSignatureHeader();
            Assert.Equal(2, signature.ReadCompressedInteger());
            Assert.Equal(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            var pointee = signature.ReadSignatureTypeCode();
            Assert.NotEqual(SignatureTypeCode.Pointer, pointee);
            var pointeeHandle = pointee == SignatureTypeCode.TypeHandle ? signature.ReadTypeHandle() : default;
            for (int index = 0; index < 2; index++)
            {
                Assert.Equal(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
                Assert.Equal(pointee, signature.ReadSignatureTypeCode());
                if (pointee == SignatureTypeCode.TypeHandle)
                    Assert.Equal(pointeeHandle, signature.ReadTypeHandle());
            }
            Assert.Equal(0, signature.RemainingBytes);
            AssertMetadataClosure(image.Reader);
        }

        private static void HeaderEnumOwnsCompatibleInferredScalarAliasesFromOtherHeaders(string architecture, string target)
        {
            using var owner = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef _WIN32META_ANNOTATION_(""Enum(FirstAlgorithm, SecondAlgorithm)"", 1, 2)
    unsigned int Algorithm;
extern ""C"" Algorithm ReadAlgorithm(Algorithm value);
");
            using var consumer = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned int Algorithm;
extern ""C"" Algorithm ConsumeAlgorithm(Algorithm value);
");
            owner.AssertSuccess();
            consumer.AssertSuccess();
            Assert.Contains("enum Algorithm", owner.ReadAdditionalTypes());
            Assert.Contains("struct Algorithm", consumer.ReadAdditionalTypes());
            RetainConsumer(owner, consumer, architecture);
            using var image = Emit(owner, architecture);
            var reader = image.Reader;
            AssertEnum(reader, "Algorithm", "FirstAlgorithm", SignatureTypeCode.UInt32, 1);
            AssertEnum(reader, "Algorithm", "SecondAlgorithm", SignatureTypeCode.UInt32, 2);
            Assert.Equal(2, FindType(reader, "Apis").GetMethods().Count());
            AssertMetadataClosure(reader);
        }

        private static void AlternateNativeRecordDefinitionsCompareEquivalentCharacterPointerStorage(string architecture, string target)
        {
            using var owner = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned short USHORT;
typedef wchar_t WCHAR;
typedef WCHAR* PWCH;
typedef struct _TEXT {
    USHORT Length;
    USHORT MaximumLength;
    _Field_size_bytes_(MaximumLength) PWCH Buffer;
} TEXT, *PTEXT;
extern ""C"" PTEXT ReadText(PTEXT value);
", namespaceName: "Owner");
            using var consumer = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned short USHORT;
typedef wchar_t WCHAR;
typedef WCHAR* PWSTR;
typedef struct _TEXT {
    USHORT Length;
    USHORT MaximumLength;
    _Null_terminated_ PWSTR Buffer;
} TEXT, *PTEXT;
extern ""C"" PTEXT ConsumeText(PTEXT value);
", namespaceName: "Consumer", extraSettings: "--remap\nPWSTR=PWSTR");
            owner.AssertSuccess();
            consumer.AssertSuccess();
            RetainConsumer(owner, consumer, architecture);
            var namespaces = new System.Collections.Generic.Dictionary<string, string>
            {
                ["TEXT"] = "Test",
                ["PWSTR"] = "Test",
            };
            using var image = Emit(owner.DirectoryPath, architecture, requiredNamespaces: namespaces);
            var reader = image.Reader;
            var fields = FindType(reader, "TEXT").GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.Equal(new[] { "Length", "MaximumLength", "Buffer" }, fields.Select(field => reader.GetString(field.Name)));
            Assert.Equal(2, reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "Apis").Sum(type => type.GetMethods().Count()));
            AssertMetadataClosure(reader);
        }

        private static void RetainConsumer(HeaderAnnotationTests.NativeFixture owner,
            HeaderAnnotationTests.NativeFixture consumer, string architecture)
        {
            string directory = Path.Combine(owner.DirectoryPath, architecture);
            File.Copy(consumer.Output, Path.Combine(directory, "Consumer.cs"));
            File.Copy(Path.ChangeExtension(consumer.Output, ".header-types.cs"), Path.Combine(directory, "Consumer.header-types.cs"));
        }

        private static void AssertEnum(MetadataReader reader, string name, string member,
            SignatureTypeCode storage, uint bits)
        {
            var fields = FindType(reader, name).GetFields().Select(reader.GetFieldDefinition).ToArray();
            var underlying = reader.GetBlobReader(fields.Single(field => reader.GetString(field.Name) == "value__").Signature);
            underlying.ReadSignatureHeader();
            Assert.Equal(storage, underlying.ReadSignatureTypeCode());
            Assert.Equal(0, underlying.RemainingBytes);
            var constant = reader.GetConstant(fields.Single(field => reader.GetString(field.Name) == member).GetDefaultValue());
            var blob = reader.GetBlobReader(constant.Value);
            Assert.Equal(bits, blob.ReadUInt32());
            Assert.Equal(0, blob.RemainingBytes);
        }
    }
}
