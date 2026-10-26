using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {

        internal static CompilationUnitSyntax[] ReadOpaqueRecordSources(HeaderAnnotationTests.NativeFixture fixture)
            => Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories)
                .Select(path => SyntaxFactory.ParseCompilationUnit(File.ReadAllText(path))).ToArray();

        internal static void AssertOpaqueRecordProvider(MetadataReader reader, string name)
        {
            var type = FindType(reader, name);
            Assert.Empty(type.GetFields());
            Assert.True(type.GetLayout().IsDefault);
            AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "GuidAttribute");
        }

        internal static void SaveOpaqueRecordArtifacts(HeaderAnnotationTests.NativeFixture fixture, string name)
        {
            string artifacts = Environment.GetEnvironmentVariable("WIN32_OPAQUE_PROVIDER_ARTIFACTS");
            if (string.IsNullOrEmpty(artifacts))
                return;
            string destination = Path.Combine(artifacts, name + "-" + Path.GetFileName(fixture.DirectoryPath));
            foreach (string path in Directory.GetFiles(fixture.DirectoryPath, "*", SearchOption.AllDirectories))
            {
                string copy = Path.Combine(destination, Path.GetRelativePath(fixture.DirectoryPath, path));
                Directory.CreateDirectory(Path.GetDirectoryName(copy));
                File.Copy(path, copy);
            }
            File.WriteAllText(Path.Combine(destination, "scraper-diagnostics.txt"), fixture.Diagnostics ?? string.Empty);
        }
    }
    public class HeaderOpaqueRecordTests : HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void ReferencedIncompleteRecordPointeesReachPhysicalWinmd(string architecture, string target, string language)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
struct _OPAQUE;
typedef struct _OPAQUE OPAQUE;
typedef OPAQUE* POPAQUE;
struct _UNUSED;
typedef struct _UNUSED UNUSED;
typedef OPAQUE* (__stdcall* OPAQUE_CALLBACK)(OPAQUE** value);
struct HOLDER { OPAQUE* value; };
OPAQUE* OpenOpaque(void);
void UseOpaque(POPAQUE value);
void WriteOpaque(OPAQUE** value);
void UseCallback(OPAQUE_CALLBACK callback);
", extraSettings: "--config\nexclude-empty-records\n--language\n" + language +
                "\n--std\n" + (language == "c" ? "c11" : "c++17") + "\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var declarations = ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
                Assert.Empty(Assert.Single(declarations.Where(type => type.Identifier.ValueText == "OPAQUE")).Members);
                Assert.DoesNotContain(declarations, type => type.Identifier.ValueText is "UNUSED" or "_UNUSED");
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                AssertOpaqueRecordProvider(reader, "OPAQUE");
                Assert.Equal("OPAQUE*", FindMethod(reader, "Apis", "OpenOpaque").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "OPAQUE*" }, FindMethod(reader, "Apis", "UseOpaque").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "OPAQUE**" }, FindMethod(reader, "Apis", "WriteOpaque").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                var callback = FindMethod(reader, "OPAQUE_CALLBACK", "Invoke").DecodeSignature(new SignatureNames(), null);
                Assert.Equal("OPAQUE*", callback.ReturnType);
                Assert.Equal(new[] { "OPAQUE**" }, callback.ParameterTypes);
                Assert.Equal("OPAQUE*", reader.GetFieldDefinition(Assert.Single(FindType(reader, "HOLDER").GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "pointers-" + architecture + "-" + language);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        public void ReferencedEmptyNativeDefinitionsReachPhysicalWinmd(string architecture, string target, bool multipleFiles)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
namespace Native
{
    struct EmptyStruct {};
    class EmptyClass {};
    class EmptyBase {};
    class EmptyDerived : public EmptyBase {};
    class Unused {};
}
Native::EmptyStruct* OpenStruct(void);
void UseClass(Native::EmptyClass* value);
void WriteDerived(Native::EmptyDerived** value);
", multipleFiles: multipleFiles, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                foreach (string name in new[] { "EmptyStruct", "EmptyClass", "EmptyDerived" })
                    AssertOpaqueRecordProvider(reader, name);
                Assert.DoesNotContain(reader.TypeDefinitions.Select(reader.GetTypeDefinition),
                    type => reader.GetString(type.Name) is "EmptyBase" or "Unused");
                Assert.Equal("EmptyStruct*", FindMethod(reader, "Apis", "OpenStruct").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "EmptyClass*" }, FindMethod(reader, "Apis", "UseClass").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal(new[] { "EmptyDerived**" }, FindMethod(reader, "Apis", "WriteDerived").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, $"empty-definitions-{architecture}-{multipleFiles}");
            }
        }

        [Theory]
        [InlineData("Empty")]
        [InlineData("OpenEmpty")]
        public void EmptyDefinitionRetentionRespectsExplicitExclusions(string excluded)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
class Empty {};
Empty* OpenEmpty(void);
", extraSettings: "--config\nexclude-empty-records\n--exclude\n" + excluded + "\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                    type => type.Identifier.ValueText == "Empty");
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "empty-definition-exclude-" + excluded);
            }
        }

        [Theory]
        [InlineData("Empty Create(void);")]
        [InlineData("Empty* Open(void); void UseValue(Empty value);")]
        public void EmptyDefinitionRecoveryDoesNotInventAByValueContract(string use)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "struct Empty {};\n" + use, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.NotEqual(0, fixture.Run());
                Assert.Contains("empty native record", fixture.Diagnostics, StringComparison.OrdinalIgnoreCase);
                Assert.Contains("by value", fixture.Diagnostics, StringComparison.OrdinalIgnoreCase);
                Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
                Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "remaps.txt")));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "empty-definition-by-value-" + use.Split('(')[0].Replace('*', '_').Replace(' ', '_'));
            }
        }

        [Theory]
        [InlineData(false, false, false)]
        [InlineData(false, true, false)]
        [InlineData(true, true, false)]
        [InlineData(true, false, true)]
        public void OpaqueRecordRetentionSupportsOrdinaryAndAnnotatedOutputModes(bool annotations, bool multipleFiles, bool fileScoped)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Opaque;
Opaque* OpenOpaque(void);
void UseOpaque(Opaque* value);
struct Unused;
", annotationsEnabled: annotations, multipleFiles: multipleFiles,
                extraSettings: "--config\nexclude-empty-records\n" + (fileScoped ? "generate-file-scoped-namespaces\n" : ""));
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var declarations = ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
                Assert.Empty(Assert.Single(declarations.Where(type => type.Identifier.ValueText == "Opaque")).Members);
                Assert.DoesNotContain(declarations, type => type.Identifier.ValueText == "Unused");
                using var image = Emit(fixture, "x64");
                AssertOpaqueRecordProvider(image.Reader, "Opaque");
                Assert.Equal("Opaque*", FindMethod(image.Reader, "Apis", "OpenOpaque").DecodeSignature(new SignatureNames(), null).ReturnType);
                AssertMetadataClosure(image.Reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, $"modes-{annotations}-{multipleFiles}-{fileScoped}");
            }
        }

        [Fact]
        public void NativePointerTypedefStorageDoesNotCreateAnOpaqueBackingRecord()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Opaque;
_Win32_NativeTypedef_ typedef struct Opaque* HOPAQUE;
HOPAQUE OpenOpaque(void);
void UseOpaque(HOPAQUE value);
", extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, "x64");
                Assert.DoesNotContain(image.Reader.TypeDefinitions.Select(image.Reader.GetTypeDefinition),
                    type => image.Reader.GetString(type.Name) == "Opaque");
                var wrapper = FindType(image.Reader, "HOPAQUE");
                AssertHasAttribute(image.Reader, wrapper.GetCustomAttributes(), "NativeTypedefAttribute");
                Assert.Equal("Void*", image.Reader.GetFieldDefinition(Assert.Single(wrapper.GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                Assert.Equal("HOPAQUE", FindMethod(image.Reader, "Apis", "OpenOpaque").DecodeSignature(new SignatureNames(), null).ReturnType);
                AssertMetadataClosure(image.Reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "native-pointer-typedef");
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeHandlePointeesMatchOrdinaryRecordEmission(string architecture, string target, bool multipleFiles)
        {
            const string declarations = @"
struct NativeHandle__ { int unused; };
struct UnusedHandle__ { int unused; };
_Win32_NativeTypedef_ typedef struct NativeHandle__* HNATIVE;
HNATIVE OpenNative(void);
void UseNative(HNATIVE value);
NativeHandle__* OpenRawNative(void);
";
            using var ordinary = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations, multipleFiles: multipleFiles);
            using var filtered = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                multipleFiles: multipleFiles, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.True(ordinary.Run() == 0, ordinary.Diagnostics);
                var ordinaryProvider = Assert.Single(ReadOpaqueRecordSources(ordinary).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "NativeHandle__"));
                using var ordinaryImage = Emit(ordinary, architecture);
                AssertMetadataClosure(ordinaryImage.Reader);

                Assert.True(filtered.Run() == 0, filtered.Diagnostics);
                var filteredDeclarations = ReadOpaqueRecordSources(filtered).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
                var filteredProvider = Assert.Single(filteredDeclarations
                    .Where(type => type.Identifier.ValueText == "NativeHandle__"));
                Assert.Equal(ordinaryProvider.Members.Select(member => member.NormalizeWhitespace().ToFullString()),
                    filteredProvider.Members.Select(member => member.NormalizeWhitespace().ToFullString()));
                Assert.DoesNotContain(filteredDeclarations, type => type.Identifier.ValueText == "UnusedHandle__");
                using var image = Emit(filtered, architecture);
                var reader = image.Reader;
                var layout = FindType(reader, "NativeHandle__").GetLayout();
                var ordinaryLayout = FindType(ordinaryImage.Reader, "NativeHandle__").GetLayout();
                Assert.Equal(ordinaryLayout.IsDefault, layout.IsDefault);
                Assert.Equal(ordinaryLayout.Size, layout.Size);
                Assert.Equal(ordinaryLayout.PackingSize, layout.PackingSize);
                var wrapper = FindType(reader, "HNATIVE");
                AssertHasAttribute(reader, wrapper.GetCustomAttributes(), "NativeTypedefAttribute");
                Assert.Equal("NativeHandle__*", reader.GetFieldDefinition(Assert.Single(wrapper.GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                Assert.Equal("HNATIVE", FindMethod(reader, "Apis", "OpenNative").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "HNATIVE" }, FindMethod(reader, "Apis", "UseNative").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal("NativeHandle__*", FindMethod(reader, "Apis", "OpenRawNative").DecodeSignature(new SignatureNames(), null).ReturnType);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(ordinary, $"nominal-handle-ordinary-{architecture}-{multipleFiles}");
                SaveOpaqueRecordArtifacts(filtered, $"nominal-handle-filtered-{architecture}-{multipleFiles}");
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, true)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true)]
        public void NativeRecordAliasesRetainTheirOrdinaryStorage(string architecture, string target, bool excludeEmptyRecords, bool multipleFiles)
        {
            const string declarations = @"
typedef struct _RECORD { struct _RECORD* Next; unsigned short Flags; } PRIMARY;
typedef struct _RECORD SECONDARY, *PSECONDARY;
typedef struct _RECORD UNUSED_ALIAS;
PSECONDARY OpenAlias(void);
void UseAlias(PSECONDARY value);
SECONDARY EchoAlias(SECONDARY value);
static_assert(sizeof(SECONDARY) == (sizeof(void*) == 8 ? 16 : 8), ""Native record alias layout"");
";
            string filter = excludeEmptyRecords ? "--config\nexclude-empty-records\n" : string.Empty;
            using var control = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                multipleFiles: multipleFiles,
                extraSettings: filter + "--remap\n_RECORD=SECONDARY\nSECONDARY=SECONDARY\nPSECONDARY=SECONDARY*\n");
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                multipleFiles: multipleFiles,
                extraSettings: filter + "--remap\n_RECORD=PRIMARY\nSECONDARY=SECONDARY\nPSECONDARY=SECONDARY*\n");
            try
            {
                Assert.True(control.Run() == 0, control.Diagnostics);
                var controlProvider = Assert.Single(ReadOpaqueRecordSources(control).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "SECONDARY"));
                using var controlImage = Emit(control, architecture);
                AssertMetadataClosure(controlImage.Reader);

                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var declarationsFromSource = ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
                Assert.Single(declarationsFromSource.Where(type => type.Identifier.ValueText == "PRIMARY"));
                var alias = Assert.Single(declarationsFromSource.Where(type => type.Identifier.ValueText == "SECONDARY"));
                Assert.DoesNotContain(declarationsFromSource, type => type.Identifier.ValueText == "UNUSED_ALIAS");
                Assert.Equal(controlProvider.Members.Select(member => member.NormalizeWhitespace().ToFullString()),
                    alias.Members.Select(member => member.NormalizeWhitespace().ToFullString()));
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var definition = FindType(reader, "SECONDARY");
                var expectedDefinition = FindType(controlImage.Reader, "SECONDARY");
                Assert.Equal(new[] { "Next", "Flags" }, definition.GetFields()
                    .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)));
                Assert.Equal(expectedDefinition.GetFields().Select(handle =>
                    controlImage.Reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)),
                    definition.GetFields().Select(handle =>
                        reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
                Assert.Equal(expectedDefinition.GetLayout().IsDefault, definition.GetLayout().IsDefault);
                Assert.Equal(expectedDefinition.GetLayout().Size, definition.GetLayout().Size);
                Assert.Equal(expectedDefinition.GetLayout().PackingSize, definition.GetLayout().PackingSize);
                Assert.Equal("SECONDARY*", FindMethod(reader, "Apis", "OpenAlias").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "SECONDARY*" }, FindMethod(reader, "Apis", "UseAlias").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                Assert.Equal("SECONDARY", FindMethod(reader, "Apis", "EchoAlias").DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal(new[] { "SECONDARY" }, FindMethod(reader, "Apis", "EchoAlias").DecodeSignature(new SignatureNames(), null).ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(control, $"native-alias-control-{architecture}-{excludeEmptyRecords}-{multipleFiles}");
                SaveOpaqueRecordArtifacts(fixture, $"native-alias-provider-{architecture}-{excludeEmptyRecords}-{multipleFiles}");
            }
        }

        [Theory]
        [InlineData("SECONDARY")]
        [InlineData("_RECORD")]
        public void NativeRecordAliasRetentionHonorsExplicitExclusions(string excluded)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct _RECORD { int value; } PRIMARY;
typedef struct _RECORD SECONDARY, *PSECONDARY;
PSECONDARY OpenAlias(void);
", extraSettings: "--config\nexclude-empty-records\n--remap\n_RECORD=PRIMARY\nPSECONDARY=SECONDARY*\n--exclude\n" + excluded + "\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                type => type.Identifier.ValueText == "SECONDARY");
            SaveOpaqueRecordArtifacts(fixture, "native-alias-exclusion-" + excluded);
        }

        [Fact]
        public void NativeRecordAliasesCannotInventFieldlessByValueStorage()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct _RECORD {} PRIMARY;
typedef struct _RECORD SECONDARY;
SECONDARY ReadAlias(void);
", extraSettings: "--remap\n_RECORD=PRIMARY\nSECONDARY=SECONDARY\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("no ordinary generated instance fields", fixture.Diagnostics);
            Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
            SaveOpaqueRecordArtifacts(fixture, "native-alias-fieldless-by-value");
        }

        [Fact]
        public void NativeRecordAliasesUseTheirQualifiedNativeDefinition()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
namespace Native { struct Record { int value; }; }
typedef Native::Record ALIAS, *PALIAS;
PALIAS OpenAlias(void);
", extraSettings: "--config\nexclude-empty-records\n--remap\nNative::Record=PRIMARY\nPALIAS=ALIAS*\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var alias = FindType(reader, "ALIAS");
            Assert.Equal("value", reader.GetString(reader.GetFieldDefinition(Assert.Single(alias.GetFields())).Name));
            Assert.Equal("ALIAS*", FindMethod(reader, "Apis", "OpenAlias").DecodeSignature(new SignatureNames(), null).ReturnType);
            AssertMetadataClosure(reader);
            SaveOpaqueRecordArtifacts(fixture, "native-alias-qualified-definition");
        }

        [Fact]
        public void NativeRecordAliasRetentionPreservesItsExistingEnclosingRecord()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Parent
{
    struct Record { int value; };
    Record* field;
    typedef Record Alias;
};
Parent::Alias* OpenAlias(void);
", extraSettings: "--config\nexclude-empty-records\n--remap\nParent::Record=PRIMARY\nParent::Alias=Parent.Alias\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            var parent = FindType(reader, "Parent");
            Assert.Single(parent.GetFields());
            Assert.Equal(new[] { "Alias", "PRIMARY" }, parent.GetNestedTypes()
                .Select(handle => reader.GetString(reader.GetTypeDefinition(handle).Name)).OrderBy(name => name));
            Assert.Single(FindType(reader, "Alias").GetFields());
            AssertMetadataClosure(reader);
            SaveOpaqueRecordArtifacts(fixture, "native-alias-nested-record");
        }

        [Fact]
        public void NominalHandleRetentionDoesNotRecoverByValueUses()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct ValueHandle__ { int unused; };
ValueHandle__ ReadValue(void);
", extraSettings: "--config\nexclude-empty-records\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("nominal handle native record 'ValueHandle__' is used by value", fixture.Diagnostics);
            Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
            SaveOpaqueRecordArtifacts(fixture, "nominal-handle-by-value");
        }

        [Fact]
        public void NominalHandleRetentionDoesNotOverrideExplicitExclusions()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct ExcludedHandle__ { int unused; };
ExcludedHandle__* OpenExcluded(void);
", extraSettings: "--config\nexclude-empty-records\n--exclude\nExcludedHandle__\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                type => type.Identifier.ValueText == "ExcludedHandle__");
            SaveOpaqueRecordArtifacts(fixture, "nominal-handle-explicit-exclusion");
        }

        [Theory]
        [InlineData("Opaque")]
        [InlineData("OpenOpaque")]
        public void OpaqueRecordRetentionRespectsExplicitExclusions(string excluded)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Opaque;
Opaque* OpenOpaque(void);
", extraSettings: "--config\nexclude-empty-records\n--exclude\n" + excluded + "\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>()),
                    type => type.Identifier.ValueText == "Opaque");
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "exclude-" + excluded);
            }
        }

        [Fact]
        public void CompleteNativeDefinitionTakesPrecedenceOverOpaqueForwardDeclaration()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Record;
Record* OpenRecord(void);
struct Record { int value; };
", extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                Assert.Single(ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "Record"));
                using var image = Emit(fixture, "x64");
                var field = image.Reader.GetFieldDefinition(Assert.Single(FindType(image.Reader, "Record").GetFields()));
                Assert.Equal("value", image.Reader.GetString(field.Name));
                Assert.Equal("Int32", field.DecodeSignature(new SignatureNames(), null));
                AssertMetadataClosure(image.Reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "complete-definition");
            }
        }

        [Theory]
        [InlineData("Opaque RoundTrip(Opaque value);")]
        [InlineData("Opaque* OpenOpaque(void); void UseValue(Opaque value);")]
        [InlineData("typedef void (__stdcall* CALLBACK)(Opaque value); void SetCallback(CALLBACK callback);")]
        public void IncompleteRecordsCannotAcquireAFabricatedByValueLayout(string use)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "struct Opaque;\n" + use, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.NotEqual(0, fixture.Run());
                Assert.Contains("incomplete", fixture.Diagnostics, StringComparison.OrdinalIgnoreCase);
                Assert.Contains("by value", fixture.Diagnostics, StringComparison.OrdinalIgnoreCase);
                Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
                Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "remaps.txt")));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "by-value-" + use.Split('(')[0].Replace('*', '_').Replace(' ', '_'));
            }
        }

        [Fact]
        public void OpaqueRecordRetentionPreservesRecordAnnotations()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct _Win32_SupportedOS_WindowsVista_ Opaque;
Opaque* OpenOpaque(void);
", extraSettings: "--config\nexclude-empty-records\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            AssertOpaqueRecordProvider(image.Reader, "Opaque");
            AssertStringAttribute(image.Reader, FindType(image.Reader, "Opaque").GetCustomAttributes(),
                "SupportedOSPlatformAttribute", "windows6.0.6000");
            SaveOpaqueRecordArtifacts(fixture, "annotated-record");
        }

        [Fact]
        public void OpaqueRecordRetentionCanReachATransitivelyIncludedDeclaration()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""opaque.h""
Opaque* OpenOpaque(void);
", extraSettings: "--config\nexclude-empty-records\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "opaque.h"), "struct Opaque;\nstruct Unused;\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            AssertOpaqueRecordProvider(image.Reader, "Opaque");
            Assert.DoesNotContain(image.Reader.TypeDefinitions.Select(image.Reader.GetTypeDefinition),
                type => image.Reader.GetString(type.Name) == "Unused");
            AssertMetadataClosure(image.Reader);
            SaveOpaqueRecordArtifacts(fixture, "transitive-record");
        }

        [Fact]
        public void OpaqueRecordRetentionUsesQualifiedNativeNamesAndConfiguredRemappings()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
namespace First { struct Opaque; }
namespace Second { struct Opaque; }
First::Opaque* OpenFirst(void);
Second::Opaque* OpenSecond(void);
", extraSettings: "--config\nexclude-empty-records\n--remap\nFirst::Opaque=FirstOpaque\nSecond::Opaque=SecondOpaque\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "x64");
            AssertOpaqueRecordProvider(image.Reader, "FirstOpaque");
            AssertOpaqueRecordProvider(image.Reader, "SecondOpaque");
            Assert.Equal("FirstOpaque*", FindMethod(image.Reader, "Apis", "OpenFirst").DecodeSignature(new SignatureNames(), null).ReturnType);
            Assert.Equal("SecondOpaque*", FindMethod(image.Reader, "Apis", "OpenSecond").DecodeSignature(new SignatureNames(), null).ReturnType);
            AssertMetadataClosure(image.Reader);
            SaveOpaqueRecordArtifacts(fixture, "qualified-native-names");
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void OpaqueRecordRetentionPreservesAnExistingNestedRecordScope(bool multipleFiles)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Parent { struct Opaque; Opaque* value; };
Parent::Opaque* OpenOpaque(void);
", multipleFiles: multipleFiles, extraSettings: "--config\nexclude-empty-records\n");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, "x64");
                AssertOpaqueRecordProvider(image.Reader, "Opaque");
                var parent = FindType(image.Reader, "Parent");
                Assert.Single(parent.GetFields());
                Assert.Equal(parent.GetNestedTypes().Single(), image.Reader.TypeDefinitions.Single(handle =>
                    image.Reader.GetString(image.Reader.GetTypeDefinition(handle).Name) == "Opaque"));
                Assert.Equal("Opaque*", FindMethod(image.Reader, "Apis", "OpenOpaque").DecodeSignature(new SignatureNames(), null).ReturnType);
                AssertMetadataClosure(image.Reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "nested-record-" + multipleFiles);
            }
        }

        [Fact]
        public void OpaqueRecordRetentionDoesNotFabricateAnExcludedEnclosingRecord()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Parent { struct Opaque; };
Parent::Opaque* OpenOpaque(void);
", extraSettings: "--config\nexclude-empty-records\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("enclosing type", fixture.Diagnostics);
            Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
            SaveOpaqueRecordArtifacts(fixture, "excluded-enclosing-record");
        }

        [Fact]
        public void OpaqueRecordRetentionDoesNotDisableTheOtherEmptyRecordExclusions()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct Opaque;
struct Empty {};
struct Handle__ { int unused; };
Opaque* OpenOpaque(void);
", extraSettings: "--config\nexclude-empty-records\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var declarations = ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
            Assert.Empty(Assert.Single(declarations.Where(type => type.Identifier.ValueText == "Opaque")).Members);
            Assert.DoesNotContain(declarations, type => type.Identifier.ValueText is "Empty" or "Handle__");
        }
    }
}
