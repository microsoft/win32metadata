using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {
        internal const string DeclareHandleDefinition =
            "#define DECLARE_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__ *name\n";
    }
    public class NativeHandleProvenanceWinmdTests : HeaderAnnotationWinmdTests
    {

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CompilerProvenHandlePreservesRetainedPublicStorageAndInvalidValue(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, DeclareHandleDefinition + @"
DECLARE_HANDLE(SOURCE_HANDLE);
typedef SOURCE_HANDLE _Win32_NativeTypedef_ SOURCE_HANDLE;
SOURCE_HANDLE OpenHandle(void);
void CloseHandle(SOURCE_HANDLE value);
");
            fixture.AssertSuccess();
            var wrapper = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single(type => type.Identifier.ValueText == "SOURCE_HANDLE");
            Assert.True(NativeHandleSourceProvenance.TryRead(wrapper, out var proof));
            Assert.Equal(NativeHandleSourceProvider.Header, proof.Provider);
            Assert.Equal("::SOURCE_HANDLE", proof.NativeAlias);
            Assert.Equal("SOURCE_HANDLE__*", proof.StorageType);
            using (var output = File.Create(Path.Combine(fixture.DirectoryPath, "autotypes.cs")))
                NativeTypedefStructsCreator.WriteToStream(new(), new[]
                {
                    new AutoType
                    {
                        Name = "SOURCE_HANDLE", Namespace = "Test", ValueType = "DECLARE_HANDLE",
                        InvalidHandleValues = new long[] { 0 },
                    },
                }, output);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var type = FindType(reader, "SOURCE_HANDLE");
            var field = reader.GetFieldDefinition(Assert.Single(type.GetFields()));
            Assert.Equal("Value", reader.GetString(field.Name));
            Assert.Equal(new byte[] { 0x06, 0x0f, 0x01 }, reader.GetBlobBytes(field.Signature));
            Assert.Equal(new long[] { 0 }, ReadInvalidValues(reader, type.GetCustomAttributes()));
            AssertHasAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            Assert.Equal("SOURCE_HANDLE", FindMethod(reader, "Apis", "OpenHandle")
                .DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal(new[] { "SOURCE_HANDLE" }, FindMethod(reader, "Apis", "CloseHandle")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("struct SOURCE_HANDLE__ { int unused; }; typedef SOURCE_HANDLE__* SOURCE_HANDLE;")]
        [InlineData("struct SOURCE_HANDLE__ {}; typedef SOURCE_HANDLE__* SOURCE_HANDLE;")]
        [InlineData("#define OTHER_HANDLE(name) struct name##__ { int unused; }; typedef struct name##__* name\nOTHER_HANDLE(SOURCE_HANDLE);")]
        [InlineData("#define DECLARE_HANDLE(name) struct name##__ { unsigned flags; }; typedef struct name##__* name\nDECLARE_HANDLE(SOURCE_HANDLE);")]
        [InlineData(DeclareHandleDefinition + "#define FACTORY(name) DECLARE_HANDLE(name)\nFACTORY(SOURCE_HANDLE);")]
        [InlineData(DeclareHandleDefinition + "DECLARE_HANDLE(OTHER_HANDLE); typedef OTHER_HANDLE SOURCE_HANDLE;")]
        [InlineData(DeclareHandleDefinition + "DECLARE_HANDLE(OTHER_HANDLE); typedef OTHER_HANDLE* SOURCE_HANDLE;")]
        public void NativeHandleProvenanceRequiresTheExactOriginalMacroAndAlias(string declarations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                declarations + "\ntypedef SOURCE_HANDLE _Win32_NativeTypedef_ SOURCE_HANDLE;\n");
            fixture.AssertSuccess();
            var wrapper = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single(type => type.Identifier.ValueText == "SOURCE_HANDLE");
            Assert.False(NativeHandleSourceProvenance.TryRead(wrapper, out _));
        }
    }
}
