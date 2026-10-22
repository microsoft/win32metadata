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
    public partial class HeaderAnnotationWinmdTests
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
        public void NativePointerTypedefStorageRetainsItsOpaquePointee()
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
                AssertOpaqueRecordProvider(image.Reader, "Opaque");
                var wrapper = FindType(image.Reader, "HOPAQUE");
                AssertHasAttribute(image.Reader, wrapper.GetCustomAttributes(), "NativeTypedefAttribute");
                Assert.Equal("Opaque*", image.Reader.GetFieldDefinition(Assert.Single(wrapper.GetFields()))
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
Handle__* OpenHandle(void);
", extraSettings: "--config\nexclude-empty-records\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var declarations = ReadOpaqueRecordSources(fixture).SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>()).ToArray();
            Assert.Empty(Assert.Single(declarations.Where(type => type.Identifier.ValueText == "Opaque")).Members);
            Assert.DoesNotContain(declarations, type => type.Identifier.ValueText is "Empty" or "Handle__");
        }

        private static CompilationUnitSyntax[] ReadOpaqueRecordSources(HeaderAnnotationTests.NativeFixture fixture)
            => Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories)
                .Select(path => SyntaxFactory.ParseCompilationUnit(File.ReadAllText(path))).ToArray();

        private static void AssertOpaqueRecordProvider(MetadataReader reader, string name)
        {
            var type = FindType(reader, name);
            Assert.Empty(type.GetFields());
            Assert.True(type.GetLayout().IsDefault);
            AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "NativeTypedefAttribute");
            AssertDoesNotHaveAttribute(reader, type.GetCustomAttributes(), "GuidAttribute");
        }

        private static void SaveOpaqueRecordArtifacts(HeaderAnnotationTests.NativeFixture fixture, string name)
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
}
