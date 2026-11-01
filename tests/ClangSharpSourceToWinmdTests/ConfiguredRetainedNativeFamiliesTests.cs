using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    public partial class HeaderTypedefCompositionTests
    {
        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void ConfiguredNativeFamiliesShareOnlyTheRetainedPublicProjection(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", @"using System;
using Windows.Win32.Foundation.Metadata;
namespace Canonical { [NativeTypedef] public partial struct HGROUP { public IntPtr Value; } }");
            foreach (string target in architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { architecture })
            {
                string first = ConfiguredRetainedProvider(fixture, target, "Canonical", "clusapi.h", "HGROUP",
                    "void*", "struct _HGROUP *", configured: true);
                string second = ConfiguredRetainedProvider(fixture, target, "Peer", "p2p.h", "HGROUP",
                    "PVOID", "PVOID", configured: true);
                string pointer = ConfiguredRetainedProvider(fixture, target, "Peer", "ntdef.h", "PVOID",
                    "void*", "void *", configured: false, inferred: true);
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target, "First.header-types.cs"), first);
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target, "Second.header-types.cs"), second);
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target, "Pointer.header-types.cs"), pointer);
                var firstSource = NativeTypedefSourceProvenance.Read(
                    CSharpSyntaxTree.ParseText(first).GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single())!;
                var secondSource = NativeTypedefSourceProvenance.Read(
                    CSharpSyntaxTree.ParseText(second).GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single())!;
                Assert.AreNotEqual(NativeRecordSourceProvenance.GetIdentityKey(firstSource),
                    NativeRecordSourceProvenance.GetIdentityKey(secondSource));
                Assert.IsFalse(NativeRecordSourceProvenance.SameDeclaration(firstSource, secondSource));
            }
            fixture.Write("Use.cs", @"namespace Canonical { public struct FIRST_USER { public HGROUP Value; } }
namespace Peer { public unsafe struct SECOND_USER { public HGROUP Value; public HGROUP* Pointer; } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var canonical = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.HGROUP")!;
            Assert.AreEqual(1, canonical.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_IntPtr,
                canonical.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
            Assert.IsNull(NativeTypedefSourceProvenance.Read(
                (StructDeclarationSyntax)canonical.DeclaringSyntaxReferences.Single().GetSyntax()));
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Peer.HGROUP"));
            var firstUser = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.FIRST_USER")!;
            var secondUser = compilation.CSharpCompilation.GetTypeByMetadataName("Peer.SECOND_USER")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(canonical,
                firstUser.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(canonical,
                secondUser.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(canonical,
                ((IPointerTypeSymbol)secondUser.GetMembers("Pointer").OfType<IFieldSymbol>().Single().Type).PointedAtType));
            string output = Path.Combine(fixture.DirectoryPath, "ConfiguredNativeFamilies.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "HGROUP");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x18 },
                reader.GetBlobBytes(reader.GetFieldDefinition(physical.GetFields().Single()).Signature));
            Assert.IsFalse(reader.TypeReferences.Select(reader.GetTypeReference).Any(type =>
                reader.GetString(type.Name) == "HGROUP" && reader.GetString(type.Namespace) == "Peer"));
        }

        [DataTestMethod]
        [DataRow("header-hash")]
        [DataRow("coordinates")]
        [DataRow("unconfigured-family")]
        [DataRow("missing-source")]
        [DataRow("binding-drift")]
        [DataRow("ambiguous-retained")]
        public void ConfiguredRetainedProjectionDoesNotBypassNativeFamilyValidation(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", @"using System;
using Windows.Win32.Foundation.Metadata;
namespace Canonical { [NativeTypedef] public partial struct HGROUP { public IntPtr Value; } }" +
                (scenario == "ambiguous-retained" ? @"
namespace Other { [NativeTypedef] public partial struct HGROUP { public IntPtr Value; } }" : ""));
            string first = ConfiguredRetainedProvider(fixture, "x64", "Canonical", "first.h", "HGROUP",
                "void*", "void *", configured: true);
            string second = ConfiguredRetainedProvider(fixture, "x64", "Canonical",
                scenario is "header-hash" or "coordinates" ? "first.h" : "second.h", "HGROUP",
                "void*", "void *", configured: scenario != "unconfigured-family",
                hash: scenario == "header-hash" ? 'B' : 'A', line: scenario == "coordinates" ? 2u : 1u);
            if (scenario is "missing-source" or "binding-drift")
            {
                var root = CSharpSyntaxTree.ParseText(second).GetRoot();
                var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var changed = scenario == "missing-source"
                    ? original.WithTrailingTrivia(default(SyntaxTriviaList))
                    : original.WithLeadingTrivia(original.GetLeadingTrivia().Select(trivia =>
                        trivia.ToString().StartsWith("/* Win32Metadata.NativeTypedefBinding.", StringComparison.Ordinal)
                            ? SyntaxFactory.Comment(trivia.ToString().Replace(new string('A', 64), new string('B', 64)))
                            : trivia));
                second = root.ReplaceNode(original, changed).ToFullString();
            }
            fixture.Write("First.header-types.cs", first);
            fixture.Write("Second.header-types.cs", second);
            var validation = new GenerationValidation();
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(validation: validation));
            StringAssert.Contains(error.Message, "CSSW005");
            Assert.IsTrue(validation.HasBlockingErrors);
        }

        private static string ConfiguredRetainedProvider(Fixture fixture, string target, string ns, string header,
            string name, string storage, string nativeType, bool configured, bool inferred = false,
            char hash = 'A', uint line = 1)
        {
            var root = CSharpSyntaxTree.ParseText($@"namespace {ns} {{
    [global::Windows.Win32.Foundation.Metadata.NativeTypedef]
    public unsafe partial struct {name} {{
        [global::Windows.Win32.Foundation.Metadata.NativeTypeName(""{nativeType}"")]
        public {storage} Value;
    }}
}}").GetCompilationUnitRoot();
            var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            long width = target == "x86" ? 4 : 8;
            var source = new NativeRecordSource("c:" + header + "@T@" + name, name,
                Path.Combine(fixture.DirectoryPath, header), new string(hash, 64), line, 1,
                name, ns, true, width, width)
            {
                SourceArchitecture = target switch
                {
                    "x86" => Architecture.X86,
                    "x64" => Architecture.X64,
                    "arm64" => Architecture.Arm64,
                    _ => throw new ArgumentException("Expected a direct native target.", nameof(target)),
                },
            };
            var declaration = NativeTypedefProjectionProvenance.WithPolicy(
                NativeTypedefSourceProvenance.Attach(original, source), inferred);
            if (configured)
                declaration = NativeTypedefProjectionProvenance.WithConfiguredNominalBinding(declaration);
            return root.ReplaceNode(original, declaration).ToFullString();
        }
    }
}
