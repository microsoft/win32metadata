using System;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypeProviderPreservesTraversedCompleteStorage(string architecture, string target)
        {
            const string declarations = @"
enum Status { Ready, Failed };
#include ""provider.h""
Native::Transform* OpenTransform(void);
Native::Transform EchoTransform(Native::Transform value);
";
            const string provider = @"
namespace Native
{
    class Transform
    {
    public:
        Transform() : native(nullptr), status(Ready) {}
        void Reset() { status = Ready; }
    private:
        Transform(const Transform&);
        Transform& operator=(const Transform&);
        Transform* native;
        Status status;
    };
    class Unused {};
    static_assert(sizeof(Transform) == (sizeof(void*) == 8 ? 16 : 8), ""Native storage"");
}
";
            using var control = TypeProviderFixture(architecture, target, declarations, "--traverse\nprovider.h\n",
                excludeEmptyRecords: false);
            using var fixture = TypeProviderFixture(architecture, target, declarations, "--traverse\nprovider.h\n");
            File.WriteAllText(Path.Combine(control.DirectoryPath, "provider.h"), provider);
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "provider.h"), provider);
            WriteDiscoveredCopyMemberExcludes(control, target);
            WriteDiscoveredCopyMemberExcludes(fixture, target);
            try
            {
                Assert.True(control.Run() == 0, control.Diagnostics);
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var ordinary = Assert.Single(ReadOpaqueRecordSources(control).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "Transform"));
                var recovered = Assert.Single(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(type => type.Identifier.ValueText == "Transform"));
                Assert.Equal(ordinary.Members.Select(member => member.ToString()), recovered.Members.Select(member => member.ToString()));
                Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<StructDeclarationSyntax>()), type => type.Identifier.ValueText == "Unused");

                using var ordinaryImage = Emit(control, architecture);
                using var image = Emit(fixture, architecture);
                var record = FindType(image.Reader, "Transform");
                var original = FindType(ordinaryImage.Reader, "Transform");
                Assert.Equal(new[] { "Transform*", "Status" }, record.GetFields().Select(handle =>
                    image.Reader.GetFieldDefinition(handle).DecodeSignature(new SignatureNames(), null)));
                Assert.Equal(original.GetLayout().IsDefault, record.GetLayout().IsDefault);
                Assert.Equal(original.GetLayout().Size, record.GetLayout().Size);
                Assert.Equal(original.GetLayout().PackingSize, record.GetLayout().PackingSize);
                Assert.Equal("Transform*", FindMethod(image.Reader, "Apis", "OpenTransform")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                Assert.Equal("Transform", FindMethod(image.Reader, "Apis", "EchoTransform")
                    .DecodeSignature(new SignatureNames(), null).ReturnType);
                AssertMetadataClosure(image.Reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(control, "native-type-provider-storage-control-" + architecture);
                SaveOpaqueRecordArtifacts(fixture, "native-type-provider-storage-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypeProviderResolvesADeclaredDependencyTraversal(string architecture, string target)
        {
            using var fixture = TypeProviderFixture(architecture, target, @"
#include ""dependency\provider.h""
DISPOSITION Dispatch(DISPOSITION value);
", "--traverse\nprovider.h\n");
            string provider = Path.Combine(fixture.DirectoryPath, "dependency", "provider.h");
            Directory.CreateDirectory(Path.GetDirectoryName(provider));
            File.WriteAllText(provider, @"
typedef enum _DISPOSITION
{
    ContinueExecution,
    ContinueSearch,
    NestedException,
    CollidedUnwind
} DISPOSITION;
");
            using (var index = CXIndex.Create(false, false))
            using (var native = ParseTypeProviderFixture(index, fixture, target))
            {
                string resolved = Assert.Single(RemapDiscovery.ResolveTraversalFiles(native.TranslationUnitDecl, new[] { "provider.h" }));
                Assert.Equal(provider, resolved, ignoreCase: true);
                File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--traverse\n" + resolved + "\n");
            }
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                var declarations = ReadOpaqueRecordSources(fixture).SelectMany(root =>
                    root.DescendantNodes().OfType<EnumDeclarationSyntax>()).ToArray();
                Assert.Equal("DISPOSITION", Assert.Single(declarations).Identifier.ValueText);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var fields = FindType(reader, "DISPOSITION").GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.Equal("Int32", fields[0].DecodeSignature(new SignatureNames(), null));
                Assert.Equal(new[] { "ContinueExecution", "ContinueSearch", "NestedException", "CollidedUnwind" },
                    fields.Skip(1).Select(field => reader.GetString(field.Name)));
                Assert.Equal(new[] { 0, 1, 2, 3 }, fields.Skip(1).Select(field =>
                    reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value).ReadInt32()));
                var signature = FindMethod(reader, "Apis", "Dispatch").DecodeSignature(new SignatureNames(), null);
                Assert.Equal("DISPOSITION", signature.ReturnType);
                Assert.Equal(new[] { "DISPOSITION" }, signature.ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "native-type-provider-enum-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeTypeProviderPreservesAnArchitectureDependentRecordAlias(string architecture, string target)
        {
            using var fixture = TypeProviderFixture(architecture, target, @"
typedef struct _NODE { struct _NODE* Next; } NODE;
#ifdef _WIN64
typedef struct __declspec(align(16)) _ALIGNED_NODE { struct _ALIGNED_NODE* Next; } ALIGNED_NODE, *PALIGNED_NODE;
#else
typedef struct _NODE ALIGNED_NODE, *PALIGNED_NODE;
#endif
PALIGNED_NODE PopNode(PALIGNED_NODE value);
", "--remap\n_NODE=NODE\nPALIGNED_NODE=ALIGNED_NODE*\n");
            try
            {
                int exitCode = fixture.Run();
                Assert.True(exitCode == (architecture == "x86" ? 0 : 1), fixture.Diagnostics);
                if (architecture != "x86")
                    Assert.Contains("requests 16 byte alignment which .NET cannot honor", fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                Assert.Equal("NODE*", reader.GetFieldDefinition(Assert.Single(FindType(reader, "NODE").GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                Assert.Equal("ALIGNED_NODE*", reader.GetFieldDefinition(Assert.Single(FindType(reader, "ALIGNED_NODE").GetFields()))
                    .DecodeSignature(new SignatureNames(), null));
                var signature = FindMethod(reader, "Apis", "PopNode").DecodeSignature(new SignatureNames(), null);
                Assert.Equal("ALIGNED_NODE*", signature.ReturnType);
                Assert.Equal(new[] { "ALIGNED_NODE*" }, signature.ParameterTypes);
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "native-type-provider-alias-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "incomplete")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "incomplete")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "incomplete")]
        [InlineData("x86", "i686-pc-windows-msvc", "empty")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "empty")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "empty")]
        [InlineData("x86", "i686-pc-windows-msvc", "nominal")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "nominal")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "nominal")]
        public void NativeTypeProviderPreservesAnnotatedPointerStorage(string architecture, string target, string storage)
        {
            string declaration = storage switch
            {
                "nominal" => "struct NativeHandle__ { int unused; };\n",
                "empty" => "struct NativeHandle__ {};\n",
                _ => "struct NativeHandle__;\n",
            };
            using var fixture = TypeProviderFixture(architecture, target,
                declaration + @"
_Win32_NativeTypedef_ typedef struct NativeHandle__* NATIVE_HANDLE;
_Win32_NativeTypedef_ typedef NATIVE_HANDLE NATIVE_ALIAS;
NATIVE_HANDLE OpenNative(void);
void UseNative(NATIVE_ALIAS value);
", storage == "empty" ? "--remap\nNATIVE_HANDLE=IntPtr\n" : "");
            try
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                using var image = Emit(fixture, architecture);
                var reader = image.Reader;
                var pointee = FindType(reader, "NativeHandle__");
                Assert.Equal(storage == "nominal" ? 1 : 0, pointee.GetFields().Count);
                if (storage == "nominal")
                    Assert.Equal("Int32", reader.GetFieldDefinition(Assert.Single(pointee.GetFields()))
                        .DecodeSignature(new SignatureNames(), null));
                foreach (string name in new[] { "NATIVE_HANDLE", "NATIVE_ALIAS" })
                {
                    var wrapper = FindType(reader, name);
                    AssertHasAttribute(reader, wrapper.GetCustomAttributes(), "NativeTypedefAttribute");
                    Assert.Equal("NativeHandle__*", reader.GetFieldDefinition(Assert.Single(wrapper.GetFields()))
                        .DecodeSignature(new SignatureNames(), null));
                }
                AssertMetadataClosure(reader);
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, $"native-type-provider-pointer-{architecture}-{storage}");
            }
        }

        [Fact]
        public void NativeTypeProviderRecoveryStillHonorsExplicitExclusions()
        {
            using var fixture = TypeProviderFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""provider.h""
ExcludedRecord* OpenRecord(void);
ExcludedEnum ReadEnum(void);
", "--traverse\nprovider.h\n--exclude\nExcludedRecord\nExcludedEnum\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "provider.h"), @"
struct ExcludedRecord { int value; };
enum ExcludedEnum { First };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.DoesNotContain(ReadOpaqueRecordSources(fixture).SelectMany(root =>
                root.DescendantNodes().OfType<BaseTypeDeclarationSyntax>()),
                type => type.Identifier.ValueText is "ExcludedRecord" or "ExcludedEnum");
        }

        [Fact]
        public void NativeTypeProviderRecoveryDoesNotInventFieldlessByValueStorage()
        {
            using var fixture = TypeProviderFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""provider.h""
ALIAS ReadValue(void);
", "--remap\n_STORAGE=PRIMARY\nALIAS=ALIAS\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "provider.h"),
                "typedef struct _STORAGE {} PRIMARY;\ntypedef struct _STORAGE ALIAS;");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("no ordinary generated instance fields", fixture.Diagnostics);
            Assert.Empty(Directory.GetFiles(fixture.DirectoryPath, "*.cs", SearchOption.AllDirectories));
        }

        [HeaderMigrationDataTheory]
        [InlineData("Partitions\\Gdiplus\\settings.rsp", "PathData")]
        [InlineData("Partitions\\CmpApi\\settings.rsp", "COMPRESSOR_HANDLE__")]
        [InlineData("Partitions\\DirectWrite\\settings.rsp", "DWRITE_FONT_AXIS_TAG")]
        [InlineData("Partitions\\Js\\settings.rsp", "JsRuntimeVersion")]
        [InlineData("Partitions\\WinRT\\settings.rsp", "RO_REGISTRATION_COOKIE")]
        [InlineData("scraper.settings.rsp", "_PSP")]
        public void NativeTypeProviderSdkProfilesDoNotExcludeTheirNativeDefinition(string relativePath, string name)
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", relativePath);
            Assert.DoesNotContain(File.ReadAllLines(path), line => line.Trim() == name);
        }

        [HeaderMigrationDataFact]
        public void NativeTypeProviderImportsTheExistingHostComputeNamespace()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "scraper.header.txt");
            Assert.Contains("using Windows.Win32.System.HostComputeSystem;", File.ReadAllLines(path));
        }

        [HeaderMigrationDataFact]
        public void NativeTypeProviderProfilesTraverseTheirActualDeclarationOwners()
        {
            string root = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "Partitions");
            Assert.Contains("<IncludeRoot>/um/gdiplusmatrix.h", File.ReadAllLines(Path.Combine(root, "Gdiplus", "settings.rsp")));
            Assert.Contains("excpt.h", File.ReadAllLines(Path.Combine(root, "Kernel", "settings.rsp")));
        }

        [Fact]
        public void NativeTypeProviderTraversalResolutionRejectsAmbiguousNativeFiles()
        {
            using var fixture = TypeProviderFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""first\provider.h""
#include ""second\provider.h""
");
            string first = Path.Combine(fixture.DirectoryPath, "first", "provider.h");
            string second = Path.Combine(fixture.DirectoryPath, "second", "provider.h");
            Directory.CreateDirectory(Path.GetDirectoryName(first));
            Directory.CreateDirectory(Path.GetDirectoryName(second));
            File.WriteAllText(first, "enum First { FirstValue };");
            File.WriteAllText(second, "enum Second { SecondValue };");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, "x86_64-pc-windows-msvc");
            var error = Assert.Throws<InvalidOperationException>(() =>
                RemapDiscovery.ResolveTraversalFiles(native.TranslationUnitDecl, new[] { "provider.h" }));
            Assert.Contains("distinct native source files", error.Message);
            Assert.Contains(first, error.Message);
            Assert.Contains(second, error.Message);
            Assert.Equal(new[] { first, "inactive.h", "relative\\inactive.h" },
                RemapDiscovery.ResolveTraversalFiles(native.TranslationUnitDecl, new[] { first, "inactive.h", "relative\\inactive.h" }));
        }

        [Fact]
        public void NativeTypeProviderCopyMemberDiscoveryPreservesCallableOverloadsAndVirtualSlots()
        {
            using var fixture = TypeProviderFixture("x64", "x86_64-pc-windows-msvc", @"
class Inaccessible
{
public:
    Inaccessible() {}
private:
    Inaccessible(const Inaccessible&);
    Inaccessible& operator=(const Inaccessible&);
};
class PublicOverload
{
public:
    PublicOverload();
private:
    PublicOverload(const PublicOverload&);
};
class VirtualSlot
{
private:
    virtual VirtualSlot& operator=(const VirtualSlot&);
};
class TemplateOverload
{
public:
    template<typename T> TemplateOverload(T value);
private:
    TemplateOverload(const TemplateOverload&);
};
");
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, "x86_64-pc-windows-msvc");
            var ordinary = RemapDiscovery.FindInaccessibleCopyMembers(native.TranslationUnitDecl, false);
            Assert.Equal(new[] { "Inaccessible::operator=" }, ordinary.OrderBy(name => name));
            var filtered = RemapDiscovery.FindInaccessibleCopyMembers(native.TranslationUnitDecl, true);
            Assert.Equal(new[] { "Inaccessible::Inaccessible", "Inaccessible::operator=" }, filtered.OrderBy(name => name));
        }

        private static void WriteDiscoveredCopyMemberExcludes(HeaderAnnotationTests.NativeFixture fixture, string target)
        {
            using var index = CXIndex.Create(false, false);
            using var native = ParseTypeProviderFixture(index, fixture, target);
            var excludes = RemapDiscovery.FindInaccessibleCopyMembers(native.TranslationUnitDecl, true);
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"),
                "--exclude\n" + string.Join("\n", excludes) + "\n");
        }

        private static TranslationUnit ParseTypeProviderFixture(CXIndex index, HeaderAnnotationTests.NativeFixture fixture, string target)
            => ParseTypeProviderFixture(index, fixture, target, Array.Empty<string>());

        private static TranslationUnit ParseTypeProviderFixture(CXIndex index, HeaderAnnotationTests.NativeFixture fixture, string target,
            string[] additionalArguments)
        {
            string[] arguments =
            {
                "--language=c++", "--std=c++17", "--target=" + target,
                "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"),
            };
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index,
                Path.Combine(fixture.DirectoryPath, "test.cpp"), arguments.Concat(additionalArguments).ToArray(),
                ReadOnlySpan<CXUnsavedFile>.Empty, CXTranslationUnit_Flags.CXTranslationUnit_None, out var handle));
            for (uint diagnostic = 0; diagnostic < handle.NumDiagnostics; diagnostic++)
            {
                using var message = handle.GetDiagnostic(diagnostic);
                Assert.True(message.Severity < CXDiagnosticSeverity.CXDiagnostic_Error,
                    message.Format(CXDiagnostic.DefaultDisplayOptions).ToString());
            }
            return TranslationUnit.GetOrCreate(handle);
        }

        private static HeaderAnnotationTests.NativeFixture TypeProviderFixture(string architecture, string target,
            string declarations, string extraSettings = "", bool excludeEmptyRecords = true)
            => new(architecture, target, declarations,
                extraSettings: "--config\n" + (excludeEmptyRecords ? "exclude-empty-records\n" : "") +
                    "exclude-funcs-with-body\n" + extraSettings,
                directoryRoot: Path.Combine(Directory.GetCurrentDirectory(), "artifacts", "native-type-provider-tests"));
    }
}
