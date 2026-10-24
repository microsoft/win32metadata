using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        private const string OpaqueCookieStorageRemaps = "--remap\nSOURCE_COOKIE=IntPtr\nCOOKIE_TAG=IntPtr\n--exclude\nCOOKIE_TAG\n";

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", 0)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 0)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", 0)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 1)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 2)]
        public void OpaqueStructPointerProofPreservesRetainedIntPtrAndNativeAliasIndirection(
            string architecture, string target, int recordRemap)
        {
            string recordMapping = recordRemap switch
            {
                1 => "RENAMED_COOKIE_TAG",
                2 => "SOURCE_COOKIE",
                _ => "IntPtr",
            };
            string settings = $"--remap\nSOURCE_COOKIE=IntPtr\nCOOKIE_TAG={recordMapping}\n--exclude\nCOOKIE_TAG\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef struct COOKIE_TAG {} *SOURCE_COOKIE;
typedef SOURCE_COOKIE _Win32_NativeTypedef_ SOURCE_COOKIE;
SOURCE_COOKIE OpenCookie(void);
void UseCookie(SOURCE_COOKIE value, SOURCE_COOKIE* output, SOURCE_COOKIE** indirect);
", extraSettings: settings);
            fixture.AssertSuccess();
            var wrapper = ReadOpaqueCookieWrapper(fixture);
            string expectedStorage = recordRemap == 1 ? "RENAMED_COOKIE_TAG*" : "COOKIE_TAG*";
            Assert.Equal(expectedStorage, Assert.Single(wrapper.Members.OfType<FieldDeclarationSyntax>()).Declaration.Type.ToString());
            Assert.True(NativeHandleSourceProvenance.TryRead(wrapper, out var headerProof));
            Assert.Equal(NativeHandleSourceProvider.Header, headerProof.Provider);
            Assert.Equal(NativeHandleSourceProvenance.OpaqueStructPointerKind, headerProof.Kind);
            Assert.Equal("::SOURCE_COOKIE", headerProof.NativeAlias);
            Assert.Equal("::COOKIE_TAG", headerProof.NativeTag);
            Assert.Equal(expectedStorage, headerProof.StorageType);
            Assert.True(headerProof.WrapperIntent);
            Assert.Equal(1, headerProof.PointerDepth);
            WriteRetainedOpaqueCookie(fixture);
            var retained = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "autotypes.cs")))
                .GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.True(NativeHandleSourceProvenance.TryRead(retained, out var retainedProof));
            Assert.Equal(NativeHandleSourceProvider.Retained, retainedProof.Provider);
            Assert.Equal(headerProof.NativeAlias, retainedProof.NativeAlias);
            Assert.Equal(headerProof.NativeTag, retainedProof.NativeTag);
            Assert.Equal(headerProof.Kind, retainedProof.Kind);
            Assert.Equal("IntPtr", retainedProof.StorageType);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var type = FindType(reader, "SOURCE_COOKIE");
            var value = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(value.Name));
            Assert.Equal(new byte[] { 0x06, 0x18 }, reader.GetBlobBytes(value.Signature));
            Assert.Equal(new long[] { 0 }, ReadInvalidValues(reader, type.GetCustomAttributes()));
            AssertHasAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            Assert.Equal(2, type.GetCustomAttributes().Count);
            Assert.Equal("SOURCE_COOKIE", FindMethod(reader, "Apis", "OpenCookie")
                .DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "SOURCE_COOKIE", "SOURCE_COOKIE*", "SOURCE_COOKIE**" },
                FindMethod(reader, "Apis", "UseCookie").DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("typedef const COOKIE_TAG* SOURCE_COOKIE;")]
        [InlineData("typedef volatile COOKIE_TAG* SOURCE_COOKIE;")]
        [InlineData("typedef COOKIE_TAG* const SOURCE_COOKIE;")]
        [InlineData("typedef COOKIE_TAG* volatile SOURCE_COOKIE;")]
        [InlineData("typedef COOKIE_TAG* __restrict SOURCE_COOKIE;")]
        [InlineData("typedef const COOKIE_TAG QUALIFIED_TAG; typedef QUALIFIED_TAG* SOURCE_COOKIE;")]
        [InlineData("typedef COOKIE_TAG** SOURCE_COOKIE;")]
        public void OpaqueStructPointerNativeProofRejectsQualifiersAndAdditionalIndirection(string declaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "struct COOKIE_TAG {};\n" + declaration +
                "\ntypedef SOURCE_COOKIE _Win32_NativeTypedef_ SOURCE_COOKIE;\n",
                extraSettings: OpaqueCookieStorageRemaps);
            fixture.AssertSuccess();
            Assert.False(NativeHandleSourceProvenance.TryRead(ReadOpaqueCookieWrapper(fixture), out _));
            WriteRetainedOpaqueCookie(fixture);
            var error = Assert.Throws<InvalidDataException>(() => Emit(fixture, "x64"));
            Assert.Contains("Conflicting native typedef Value storage types", error.Message);
        }

        [Theory]
        [InlineData("union COOKIE_TAG { int value; }; typedef COOKIE_TAG* SOURCE_COOKIE;")]
        [InlineData("class COOKIE_TAG {}; typedef COOKIE_TAG* SOURCE_COOKIE;")]
        [InlineData("enum COOKIE_TAG : int { VALUE = 0 }; typedef COOKIE_TAG* SOURCE_COOKIE;")]
        public void OpaqueStructPointerNativeProofRejectsOtherNativeSourceKinds(string declaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declaration + "\ntypedef SOURCE_COOKIE _Win32_NativeTypedef_ SOURCE_COOKIE;\n",
                extraSettings: OpaqueCookieStorageRemaps);
            fixture.AssertSuccess();
            Assert.False(NativeHandleSourceProvenance.TryRead(ReadOpaqueCookieWrapper(fixture), out _));
            WriteRetainedOpaqueCookie(fixture);
            var error = Assert.Throws<InvalidDataException>(() => Emit(fixture, "x64"));
            Assert.Contains("Conflicting native typedef Value storage types", error.Message);
        }

        [Fact]
        public void OpaqueStructPointerNativeProofRequiresExplicitNativeWrapperIntent()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct COOKIE_TAG {};
_Win32_AlsoUsableFor_(OTHER_COOKIE) typedef COOKIE_TAG* SOURCE_COOKIE;
", extraSettings: OpaqueCookieStorageRemaps);
            fixture.AssertSuccess();
            var wrapper = ReadOpaqueCookieWrapper(fixture);
            Assert.Contains(wrapper.AttributeLists.SelectMany(list => list.Attributes),
                attribute => attribute.Name.ToString().EndsWith("NativeTypedef"));
            Assert.False(NativeHandleSourceProvenance.TryRead(wrapper, out _));
            WriteRetainedOpaqueCookie(fixture);
            var error = Assert.Throws<InvalidDataException>(() => Emit(fixture, "x64"));
            Assert.Contains("Conflicting native typedef Value storage types", error.Message);
        }

        [Theory]
        [InlineData("IntPtr", true)]
        [InlineData("typedef struct COOKIE_TAG", false)]
        [InlineData("typedef struct OTHER_TAG", true)]
        [InlineData("typedef struct Other::COOKIE_TAG", true)]
        public void OpaqueStructPointerCompleteEmptyRecordRequiresMatchingRetainedFactoryProof(
            string retainedFactory, bool explicitWrapperIntent)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct COOKIE_TAG {} *SOURCE_COOKIE;
typedef SOURCE_COOKIE _Win32_NativeTypedef_ SOURCE_COOKIE;
", extraSettings: OpaqueCookieStorageRemaps);
            fixture.AssertSuccess();
            Assert.True(NativeHandleSourceProvenance.TryRead(ReadOpaqueCookieWrapper(fixture), out var headerProof));
            Assert.Equal(NativeHandleSourceProvenance.OpaqueStructPointerKind, headerProof.Kind);
            WriteRetainedOpaqueCookie(fixture, retainedFactory, explicitWrapperIntent);
            var error = Assert.Throws<InvalidDataException>(() => Emit(fixture, "x64"));
            Assert.Contains("Conflicting native typedef Value storage types", error.Message);
        }

        [Fact]
        public void OpaqueStructPointerNativeProofRecordsTheCompilerQualifiedTag()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
namespace Native { struct COOKIE_TAG {}; }
typedef Native::COOKIE_TAG* SOURCE_COOKIE;
typedef SOURCE_COOKIE _Win32_NativeTypedef_ SOURCE_COOKIE;
", extraSettings: "--remap\nSOURCE_COOKIE=IntPtr\n");
            fixture.AssertSuccess();
            Assert.True(NativeHandleSourceProvenance.TryRead(ReadOpaqueCookieWrapper(fixture), out var proof));
            Assert.Equal("::Native::COOKIE_TAG", proof.NativeTag);
            Assert.Equal("::SOURCE_COOKIE", proof.NativeAlias);
            WriteRetainedOpaqueCookie(fixture, "typedef struct Other::COOKIE_TAG");
            var error = Assert.Throws<InvalidDataException>(() => Emit(fixture, "x64"));
            Assert.Contains("Conflicting native typedef Value storage types", error.Message);
        }

        private static StructDeclarationSyntax ReadOpaqueCookieWrapper(HeaderAnnotationTests.NativeFixture fixture) =>
            CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single(type => type.Identifier.ValueText == "SOURCE_COOKIE");

        private static void WriteRetainedOpaqueCookie(HeaderAnnotationTests.NativeFixture fixture,
            string valueType = "typedef struct COOKIE_TAG", bool explicitWrapperIntent = true)
        {
            using var output = File.Create(Path.Combine(fixture.DirectoryPath, "autotypes.cs"));
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "SOURCE_COOKIE", Namespace = "Test", ValueType = valueType,
                    NativeTypedef = explicitWrapperIntent, InvalidHandleValues = new long[] { 0 },
                },
            }, output);
        }
    }
}
