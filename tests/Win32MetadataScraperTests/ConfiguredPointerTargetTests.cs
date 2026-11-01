using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using static Win32MetadataScraperTests.HeaderAnnotationWinmdTests;

namespace Win32MetadataScraperTests
{
    public class ConfiguredPointerTargetTests
    {
        [Fact]
        public void NativeBoolRetainsItsDeclaredTypeThroughTheOriginalPointerSettings()
        {
            foreach (var (architecture, target) in Architectures)
            {
                using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int BOOL;
typedef BOOL* PBOOL;
typedef BOOL* LPBOOL;
struct FLAG_FIELD { BOOL value; };
extern ""C"" BOOL ReadBool(BOOL value, PBOOL values, LPBOOL otherValues, PBOOL* table);
", annotationsEnabled: false, namespaceName: "Windows.Win32.Foundation",
                    extraSettings: "--remap\nPBOOL=BOOL*\nLPBOOL=BOOL*\n");
                fixture.AssertSuccess();
                var declarations = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                    .DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
                var declaration = declarations.Single(type => type.Identifier.ValueText == "BOOL");
                AssertNominal(declaration, fixture, "BOOL");
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var decoder = new SignatureNames(qualifiedNames: true);
                var storage = reader.GetFieldDefinition(FindType(reader, "BOOL").GetFields().Single());
                Assert.Equal("Int32", storage.DecodeSignature(decoder, null));
                var field = reader.GetFieldDefinition(FindType(reader, "FLAG_FIELD").GetFields().Single());
                Assert.Equal("Windows.Win32.Foundation.BOOL", field.DecodeSignature(decoder, null));
                var method = FindMethod(reader, "Apis", "ReadBool").DecodeSignature(decoder, null);
                Assert.Equal("Windows.Win32.Foundation.BOOL", method.ReturnType);
                Assert.Equal(new[]
                {
                    "Windows.Win32.Foundation.BOOL",
                    "Windows.Win32.Foundation.BOOL*",
                    "Windows.Win32.Foundation.BOOL*",
                    "Windows.Win32.Foundation.BOOL**",
                }, method.ParameterTypes);
                AssertMetadataClosure(reader);
            }
        }

        [Fact]
        public void PointerTargetsPreserveNominalNamesWithoutOverridingExplicitStorage()
        {
            foreach (var (architecture, target) in Architectures)
            {
                using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef int NOMINAL_FLAG;
typedef NOMINAL_FLAG* PNOMINAL_FLAG;
typedef NOMINAL_FLAG** PPNOMINAL_FLAG;
typedef int STORAGE_FLAG;
typedef STORAGE_FLAG* PSTORAGE_FLAG;
typedef int ORDINARY_FLAG;
typedef ORDINARY_FLAG* PORDINARY_FLAG;
extern ""C"" {
NOMINAL_FLAG ReadNominal(NOMINAL_FLAG value, PNOMINAL_FLAG values, PPNOMINAL_FLAG table);
STORAGE_FLAG ReadStorage(STORAGE_FLAG value, PSTORAGE_FLAG values);
ORDINARY_FLAG ReadOrdinary(ORDINARY_FLAG value, PORDINARY_FLAG values);
}
", annotationsEnabled: false, extraSettings: "--remap\nPNOMINAL_FLAG=NOMINAL_FLAG*\n" +
                    "PPNOMINAL_FLAG=NOMINAL_FLAG**\nSTORAGE_FLAG=int\nPSTORAGE_FLAG=STORAGE_FLAG*\n");
                fixture.AssertSuccess();
                var declarations = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                    .DescendantNodes().OfType<StructDeclarationSyntax>().ToArray();
                AssertNominal(declarations.Single(type => type.Identifier.ValueText == "NOMINAL_FLAG"),
                    fixture, "NOMINAL_FLAG");
                foreach (string name in new[] { "STORAGE_FLAG", "ORDINARY_FLAG" })
                {
                    var declaration = declarations.Single(type => type.Identifier.ValueText == name);
                    Assert.True(NativeTypedefProjectionProvenance.IsInferred(declaration));
                    Assert.False(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));
                }
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var decoder = new SignatureNames(qualifiedNames: true);
                var method = FindMethod(reader, "Apis", "ReadNominal").DecodeSignature(decoder, null);
                Assert.Equal("Test.NOMINAL_FLAG", method.ReturnType);
                Assert.Equal(new[] { "Test.NOMINAL_FLAG", "Test.NOMINAL_FLAG*", "Test.NOMINAL_FLAG**" },
                    method.ParameterTypes);
                foreach (string name in new[] { "ReadStorage", "ReadOrdinary" })
                {
                    method = FindMethod(reader, "Apis", name).DecodeSignature(decoder, null);
                    Assert.Equal("Int32", method.ReturnType);
                    Assert.Equal(new[] { "Int32", "Int32*" }, method.ParameterTypes);
                }
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition), type =>
                    reader.GetString(type.Name) is "STORAGE_FLAG" or "ORDINARY_FLAG");
                AssertMetadataClosure(reader);
            }
        }

        private static void AssertNominal(StructDeclarationSyntax declaration,
            HeaderAnnotationTests.NativeFixture fixture, string name)
        {
            var source = NativeTypedefSourceProvenance.Read(declaration);
            Assert.NotNull(source);
            Assert.Equal(name, source.NativeName);
            Assert.Equal(fixture.Header, source.Header);
            Assert.Equal(Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(fixture.Header))), source.HeaderHash);
            Assert.Equal(4L, source.Size);
            Assert.Equal(4L, source.Alignment);
            Assert.False(NativeTypedefProjectionProvenance.IsInferred(declaration));
            Assert.True(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));
        }

        private static readonly (string Architecture, string Target)[] Architectures =
        {
            ("x86", "i686-pc-windows-msvc"),
            ("x64", "x86_64-pc-windows-msvc"),
            ("arm64", "aarch64-pc-windows-msvc"),
        };
    }
}
