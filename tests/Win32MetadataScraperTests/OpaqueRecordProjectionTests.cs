using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis.CSharp;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class OpaqueRecordProjectionTests
    {
        [Theory]
        [InlineData("using Reference = global::Test.Opaque; namespace Test { public static unsafe class Apis { public static extern Reference* Read(); } }")]
        [InlineData("namespace Test { public unsafe struct Apis { public delegate* unmanaged<Opaque*, Opaque*> Callback; } }")]
        [InlineData("namespace Test { public static unsafe class Apis { public static Opaque* Read() => null; public static void Use() { var value = Read(); } } }")]
        public void CandidateDiscoveryPreservesAliasesFunctionPointersAndInferredTypes(string source)
        {
            using var native = new NativeRecords("namespace Test { struct Opaque; }\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { GeneratedSource.FromText(source) },
                new Dictionary<string, string>());
            Assert.Equal(new[] { "Test::Opaque" }, projection.IncludedNames);
        }

        [Fact]
        public void ResolvedAliasReferencesDoNotSelectUnneededNativeProviders()
        {
            using var native = new NativeRecords("namespace Test { struct Opaque; }\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
using Reference = global::Test.Opaque;
namespace Test
{
    public struct Opaque { public int Value; }
    public static unsafe class Apis { public static extern Reference* Read(); }
}" }, new Dictionary<string, string>());
            Assert.Empty(projection.IncludedNames);
            Assert.Empty(projection.RecordAliases);
        }

        [Fact]
        public void CandidateMentionsInAnotherSourcesAliasStillRequireBinding()
        {
            using var native = new NativeRecords("namespace Test { struct Opaque; }\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[]
            {
                "global using Reference = global::Test.Opaque;",
                "namespace Test { public static unsafe class Apis { public static extern Reference* Read(); } }",
            }, new Dictionary<string, string>());
            Assert.Equal(new[] { "Test::Opaque" }, projection.IncludedNames);
        }

        [Theory]
        [InlineData("namespace Test { public static unsafe class Apis { public static extern O\\u0070aque* Read(); } }")]
        [InlineData("namespace Test { public static unsafe class Apis { public static extern @Opaque* Read(); } }")]
        public void CandidateNamesUseIdentifierValuesRatherThanSourceSpellings(string source)
        {
            using var native = new NativeRecords("namespace Test { struct Opaque; }\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { source },
                new Dictionary<string, string>());
            Assert.Equal(new[] { "Test::Opaque" }, projection.IncludedNames);
        }

        [Fact]
        public void CandidateDiscoveryUsesTheManagedRemapName()
        {
            using var native = new NativeRecords("struct NativeTag;\n");
            var projection = new OpaqueRecordProjection(native.Unit,
                new[] { "public static unsafe class Apis { public static extern PublicName* Read(); }" },
                new Dictionary<string, string> { ["NativeTag"] = "PublicName" });
            Assert.Equal(new[] { "NativeTag" }, projection.IncludedNames);
        }

        [Fact]
        public void UnusedNativeCandidatesDoNotInventAProviderForCommentsOrStrings()
        {
            using var native = new NativeRecords("struct Opaque;\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[]
            {
                "// Opaque\npublic static class Apis { public const string Name = \"Opaque\"; public static int Read() => 1; }",
            }, new Dictionary<string, string>());
            Assert.Empty(projection.IncludedNames);
            Assert.Empty(projection.RecordAliases);
        }

        [Fact]
        public void ResolvedNamesDoNotTriggerUnneededNativeAliasAmbiguityErrors()
        {
            using var native = new NativeRecords(@"
namespace First { struct Record { int value; }; typedef Record Alias; }
namespace Second { struct Record { short value; }; typedef Record Alias; }
");
            var projection = new OpaqueRecordProjection(native.Unit, new[]
            {
                "public struct Alias { public int Value; } public static unsafe class Apis { public static extern Alias* Read(); }",
            }, new Dictionary<string, string>());
            Assert.Empty(projection.IncludedNames);
            Assert.Empty(projection.RecordAliases);
        }

        [Fact]
        public void DiscoveryRequiresAnUnresolvedReferenceAndNoCompleteStorageDefinition()
        {
            using var native = new NativeRecords(@"
struct Opaque;
struct Unused;
struct Complete;
struct Complete { int value; };
struct Empty {};
");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
namespace Test
{
    public static unsafe class Apis
    {
        public static extern Opaque* Open();
        public static extern Complete* OpenComplete();
        public static extern Empty* OpenEmpty();
    }
}" }, new Dictionary<string, string>());
            Assert.Equal(new[] { "Empty", "Opaque" }, projection.IncludedNames.OrderBy(name => name));
        }

        [Fact]
        public void CompleteEmptyDefinitionsExcludeStorageMethodsAndVirtualBases()
        {
            using var native = new NativeRecords(@"
class Empty {};
class Derived : public Empty {};
class Storage { int value; };
class StorageBase : public Storage {};
class VirtualBase : virtual public Empty {};
class VirtualMethod { virtual void Call(); };
class Method { void Call(); };
class StaticMember { static int value; };
struct ForwardEmpty;
struct ForwardEmpty {};
");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
public static unsafe class Apis
{
    public static extern Empty* OpenEmpty();
    public static extern Derived* OpenDerived();
    public static extern Storage* OpenStorage();
    public static extern StorageBase* OpenStorageBase();
    public static extern VirtualBase* OpenVirtualBase();
    public static extern VirtualMethod* OpenVirtualMethod();
    public static extern Method* OpenMethod();
    public static extern StaticMember* OpenStaticMember();
    public static extern ForwardEmpty* OpenForwardEmpty();
}" }, new Dictionary<string, string>());
            Assert.Equal(new[] { "Derived", "Empty", "ForwardEmpty" }, projection.IncludedNames.OrderBy(name => name));
        }

        [Fact]
        public void NominalHandleCandidatesRequireTheNativeSingleIntUnusedShape()
        {
            using var native = new NativeRecords(@"
struct Handle__ { int unused; };
struct NoSuffix { int unused; };
struct DifferentField__ { int value; };
struct ShortField__ { short unused; };
struct ArrayField__ { int unused[1]; };
struct BitField__ { int unused : 1; };
struct ExtraField__ { int unused; int value; };
struct Method__ { int unused; void Call(); };
struct Derived__ : Handle__ { int unused; };
union Union__ { int unused; };
");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
public static unsafe class Apis
{
    public static extern Handle__* OpenHandle();
    public static extern NoSuffix* OpenNoSuffix();
    public static extern DifferentField__* OpenDifferentField();
    public static extern ShortField__* OpenShortField();
    public static extern ArrayField__* OpenArrayField();
    public static extern BitField__* OpenBitField();
    public static extern ExtraField__* OpenExtraField();
    public static extern Method__* OpenMethod();
    public static extern Derived__* OpenDerived();
    public static extern Union__* OpenUnion();
}" }, new Dictionary<string, string>());
            Assert.Equal(new[] { "Handle__" }, projection.IncludedNames);
        }

        [Fact]
        public void NativeRecordAliasDiscoveryRequiresAnUnresolvedCompleteNativeAlias()
        {
            using var native = new NativeRecords(@"
struct Record { int value; };
typedef Record Primary;
typedef Record Secondary;
typedef Record Unused;
struct Forward;
typedef Forward IncompleteAlias;
");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
public struct Primary { public int value; }
public static unsafe class Apis
{
    public static extern Secondary* Open();
    public static extern IncompleteAlias* OpenIncomplete();
}" }, new Dictionary<string, string> { ["Record"] = "Primary" });
            var alias = Assert.Single(projection.RecordAliases);
            Assert.Equal("Secondary", alias.Name);
            Assert.Equal("Record", alias.RecordName);
            Assert.True(alias.Declaration.IsCompleteDefinition);
        }

        [Fact]
        public void NativeRecordAliasesCannotMergeDifferentNativeDefinitions()
        {
            using var native = new NativeRecords(@"
namespace First { struct Record { int value; }; typedef Record Alias; }
namespace Second { struct Record { short value; }; typedef Record Alias; }
");
            var error = Assert.Throws<InvalidOperationException>(() => new OpaqueRecordProjection(native.Unit,
                new[] { "public static unsafe class Apis { public static extern Alias* Open(); }" },
                new Dictionary<string, string>()));
            Assert.Contains("Distinct native record aliases", error.Message);
        }

        [Fact]
        public void NativeRecordAliasDiscoveryDeduplicatesTheSameNativeDefinition()
        {
            using var native = new NativeRecords(@"
struct Record { int value; };
typedef Record First;
typedef Record Second;
");
            var projection = new OpaqueRecordProjection(native.Unit,
                new[] { "public static unsafe class Apis { public static extern Alias* Open(); }" },
                new Dictionary<string, string> { ["Record"] = "Primary", ["First"] = "Alias", ["Second"] = "Alias" });
            Assert.Single(projection.RecordAliases);
        }

        [Fact]
        public void NativeRecordAliasProvidersCannotShadowAnAlreadyResolvedType()
        {
            using var native = new NativeRecords("struct Record { int value; };\ntypedef Record IntPtr;\n");
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
using System;
namespace Test
{
    public static unsafe class Apis
    {
        public static extern IntPtr Existing();
        public static extern global::Test.IntPtr* Missing();
    }
}" }, new Dictionary<string, string> { ["Record"] = "Primary" });
            var alias = Assert.Single(projection.RecordAliases);
            alias.Declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
            string source = "namespace Test { [SourceLocation(" + SyntaxFactory.Literal(file.ToString()).ToFullString() +
                $", {line}, {column})] public partial struct IntPtr {{ public int value; }} }}";
            var error = Assert.Throws<InvalidOperationException>(() => projection.ForAlias(alias).SelectRequiredBindings(
                new Dictionary<string, string> { ["IntPtr.cs"] = source }));
            Assert.Contains("already resolved", error.Message);
        }

        [Fact]
        public void SelectionUsesGeneratedSourceCoordinatesAndRetainedPointerReferences()
        {
            using var native = new NativeRecords("struct Opaque;\nstruct Unused;\n");
            var opaque = native.Unit.TranslationUnitDecl.CursorChildren.OfType<RecordDecl>().First(record => record.Name == "Opaque");
            opaque.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
namespace Test
{
    public static unsafe class Apis { public static extern Opaque* Open(); }
}" }, new Dictionary<string, string>());
            string source = "namespace Test { [SourceLocation(" + SyntaxFactory.Literal(file.ToString()).ToFullString() +
                $", {line}, {column})] public partial struct Opaque {{ }} }}";
            var result = projection.SelectRequiredBindings(new Dictionary<string, string> { ["Opaque.cs"] = source });
            Assert.Contains("struct Opaque", Assert.Single(result).Value);
        }

        [Fact]
        public void ASecondGeneratorCanRecoverAReferencedRecordFromTheSameTranslationUnit()
        {
            using var native = new NativeRecords("struct Opaque;\nOpaque* OpenOpaque(void);\n");
            var options = PInvokeGeneratorConfigurationOptions.GenerateCompatibleCode |
                PInvokeGeneratorConfigurationOptions.GenerateCppAttributes;
            var primary = Generate(options | PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords, Array.Empty<string>());
            var projection = new OpaqueRecordProjection(native.Unit, primary.Values, new Dictionary<string, string>());
            Assert.Equal(new[] { "Opaque" }, projection.IncludedNames);
            var supplemental = Generate(options | PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute, projection.IncludedNames);
            var selected = projection.SelectRequiredBindings(supplemental);
            Assert.True(selected.Count == 1, "The selective pass failed to provide the record. Supplemental output:" +
                Environment.NewLine + string.Join(Environment.NewLine, supplemental.Values));

            Dictionary<string, string> Generate(PInvokeGeneratorConfigurationOptions flags, IReadOnlyCollection<string> names)
            {
                var streams = new Dictionary<string, MemoryStream>();
                var config = new PInvokeGeneratorConfiguration("c++", "c++17", "Test",
                    Path.ChangeExtension(native.SourcePath, ".cs"), Path.Combine(AppContext.BaseDirectory, "assets", "scraper.header.txt"),
                    PInvokeGeneratorOutputMode.CSharp, flags)
                {
                    IncludedNames = names,
                    TraversalNames = new[] { native.SourcePath },
                    DefaultClass = "Apis",
                    LibraryPath = "scan.dll",
                };
                using var generator = new PInvokeGenerator(config, path =>
                {
                    var stream = new MemoryStream();
                    streams[path] = stream;
                    return stream;
                });
                generator.GenerateBindings(native.Unit, native.SourcePath,
                    new[] { "--language=c++", "--std=c++17", "--target=x86_64-pc-windows-msvc" },
                    CXTranslationUnit_Flags.CXTranslationUnit_None);
                Assert.DoesNotContain(generator.Diagnostics, diagnostic => diagnostic.Level == DiagnosticLevel.Error);
                generator.Close();
                return streams.ToDictionary(pair => pair.Key, pair => Encoding.UTF8.GetString(pair.Value.ToArray()));
            }
        }

        [Fact]
        public void RetainedProvidersCannotShadowAnAlreadyResolvedType()
        {
            using var native = new NativeRecords("struct IntPtr;\n");
            var record = native.Unit.TranslationUnitDecl.CursorChildren.OfType<RecordDecl>().Single();
            record.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
            var projection = new OpaqueRecordProjection(native.Unit, new[] { @"
using System;
namespace Test
{
    public static unsafe class Apis
    {
        public static extern IntPtr* Existing();
        public static extern global::Test.IntPtr* Missing();
    }
}" }, new Dictionary<string, string>());
            string source = "namespace Test { [SourceLocation(" + SyntaxFactory.Literal(file.ToString()).ToFullString() +
                $", {line}, {column})] public partial struct IntPtr {{ }} }}";
            var error = Assert.Throws<InvalidOperationException>(() => projection.SelectRequiredBindings(
                new Dictionary<string, string> { ["IntPtr.cs"] = source }));
            Assert.Contains("already resolved", error.Message);
        }

        internal sealed class NativeRecords : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "win32-opaque-discovery-" + Guid.NewGuid().ToString("N"));
            private readonly CXIndex index;

            internal NativeRecords(string source)
            {
                Directory.CreateDirectory(directory);
                string path = Path.Combine(directory, "native.cpp");
                File.WriteAllText(path, source);
                index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
                Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, path,
                    new[] { "--language=c++", "--std=c++17", "--target=x86_64-pc-windows-msvc" },
                    ReadOnlySpan<CXUnsavedFile>.Empty, CXTranslationUnit_Flags.CXTranslationUnit_None, out var handle));
                Unit = TranslationUnit.GetOrCreate(handle);
            }

            internal TranslationUnit Unit { get; }
            internal string SourcePath => Path.Combine(directory, "native.cpp");

            public void Dispose()
            {
                Unit.Dispose();
                index.Dispose();
                Directory.Delete(directory, recursive: true);
            }
        }
    }
}
