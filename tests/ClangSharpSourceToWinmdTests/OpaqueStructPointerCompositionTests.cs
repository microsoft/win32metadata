using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text;
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
        public void OpaqueStructPointerProofsPreserveFactoryIntPtrAndInvalidMetadata(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", RetainedOpaqueStructSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithOpaqueStructProof());
            fixture.Write("Bindings.cs", "namespace Test { public partial struct OPAQUE_TAG { } }");
            var compilation = fixture.Compile(new() { ["COOKIE"] = "Canonical" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.COOKIE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_IntPtr, ((IFieldSymbol)alias.GetMembers("Value").Single()).Type.SpecialType);
            Assert.AreEqual("", NativeHandleSourceProvenance.GetSignature(
                (StructDeclarationSyntax)alias.DeclaringSyntaxReferences.Single().GetSyntax()));
            var native = compilation.CSharpCompilation.GetTypeByMetadataName("Test.OPAQUE_TAG")!;
            Assert.AreEqual(1, native.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(0, native.GetMembers().OfType<IFieldSymbol>().Count());
            string output = Path.Combine(fixture.DirectoryPath, "OpaqueCookie.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var image = new PEReader(stream);
            var reader = image.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "COOKIE");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x18 },
                reader.GetBlobBytes(reader.GetFieldDefinition(physical.GetFields().Single()).Signature));
            CollectionAssert.AreEqual(new long[] { -1, 0 }, ReadInvalidValues(reader, physical));
            CollectionAssert.AreEquivalent(new[] { "NativeTypedefAttribute", "InvalidHandleValueAttribute", "InvalidHandleValueAttribute" },
                physical.GetCustomAttributes().Select(handle => AttributeName(reader, handle)).ToArray());
        }

        [DataTestMethod]
        [DataRow("OPAQUE_TAG*", false)]
        [DataRow("RENAMED_TAG*", false)]
        [DataRow("global::Test.RENAMED_TAG*", false)]
        [DataRow("OPAQUE_TAG*", true)]
        public void OpaqueStructPointerProofUsesExactRecordedStorageNotTagSpellingOrLayout(string storage, bool excludedTag)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedOpaqueStructSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithOpaqueStructProof(storage: storage));
            fixture.Write("Other.header-types.cs", HeaderWithOpaqueStructProof(storage: storage));
            fixture.Write("Bindings.cs", excludedTag ? "" :
                "namespace Test { public partial struct OPAQUE_TAG { public long Value; } " +
                "public partial struct RENAMED_TAG { public int Value; } }");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(SpecialType.System_IntPtr, ((IFieldSymbol)compilation.CSharpCompilation
                .GetTypeByMetadataName("Test.COOKIE")!.GetMembers("Value").Single()).Type.SpecialType);
            Assert.AreEqual(excludedTag ? 0 : 1, compilation.CSharpCompilation.GetTypeByMetadataName("Test.OPAQUE_TAG")?
                .DeclaringSyntaxReferences.Length ?? 0);
        }

        [DataTestMethod]
        [DataRow("missing-native-proof")]
        [DataRow("missing-retained-proof")]
        [DataRow("missing-retained-intent")]
        [DataRow("ordinary-complete-empty-provider")]
        [DataRow("other-alias")]
        [DataRow("other-alias-namespace")]
        [DataRow("other-tag")]
        [DataRow("other-tag-namespace")]
        [DataRow("other-provider")]
        [DataRow("other-generated-alias")]
        [DataRow("other-source-kind")]
        [DataRow("declare-handle-retained")]
        [DataRow("stale-storage")]
        [DataRow("additional-pointer")]
        [DataRow("pointer-to-intptr")]
        [DataRow("missing-native-intent")]
        [DataRow("missing-invalid-value")]
        [DataRow("named-handle-pointee")]
        [DataRow("ambiguous-pointee")]
        [DataRow("ambiguous-pointee-resolution")]
        [DataRow("generic-pointee")]
        [DataRow("nested-pointee")]
        [DataRow("aliased-pointee")]
        public void OpaqueStructPointerCompositionReportsIncompleteOrConflictingProof(string conflict)
        {
            using var fixture = new Fixture("x64");
            string retained = RetainedOpaqueStructSource();
            string header = HeaderWithOpaqueStructProof();
            string records = "namespace Test { public partial struct OPAQUE_TAG { } }";
            switch (conflict)
            {
                case "missing-native-proof":
                    header = WithoutHandleSourceProof(header);
                    break;
                case "missing-retained-proof":
                    retained = WithoutHandleSourceProof(retained);
                    break;
                case "missing-retained-intent":
                    retained = RetainedOpaqueStructSource(explicitWrapperIntent: false);
                    break;
                case "ordinary-complete-empty-provider":
                    retained = RetainedOpaqueStructSource(valueType: "IntPtr");
                    break;
                case "other-alias":
                    header = HeaderWithOpaqueStructProof(nativeAlias: "OTHER_COOKIE");
                    break;
                case "other-alias-namespace":
                    header = HeaderWithOpaqueStructProof(nativeAlias: "Other::COOKIE");
                    break;
                case "other-tag":
                    header = HeaderWithOpaqueStructProof(nativeTag: "OTHER_TAG");
                    break;
                case "other-tag-namespace":
                    retained = RetainedOpaqueStructSource(valueType: "typedef struct First::OPAQUE_TAG");
                    header = HeaderWithOpaqueStructProof(nativeTag: "Second::OPAQUE_TAG");
                    break;
                case "other-provider":
                    header = header.Replace("\"provider\":\"header\"", "\"provider\":\"retained\"", StringComparison.Ordinal);
                    break;
                case "other-generated-alias":
                    header = header.Replace("\"generatedAlias\":\"COOKIE\"", "\"generatedAlias\":\"OTHER_COOKIE\"", StringComparison.Ordinal);
                    break;
                case "other-source-kind":
                    header = HeaderWithDeclareHandleProof(source: OpaqueHeaderSource(), nativeAlias: "COOKIE", storage: "OPAQUE_TAG*");
                    break;
                case "declare-handle-retained":
                    retained = RetainedDeclareHandleSource().Replace("HANDLE", "COOKIE", StringComparison.Ordinal);
                    break;
                case "stale-storage":
                    header = header.Replace("\"storage\":\"OPAQUE_TAG*\"", "\"storage\":\"OTHER_TAG*\"", StringComparison.Ordinal);
                    break;
                case "additional-pointer":
                    header = header.Replace("OPAQUE_TAG*", "OPAQUE_TAG**", StringComparison.Ordinal);
                    break;
                case "pointer-to-intptr":
                    header = HeaderWithOpaqueStructProof(storage: "global::System.IntPtr*");
                    break;
                case "missing-native-intent":
                    header = header.Replace("\"wrapperIntent\":true", "\"wrapperIntent\":false", StringComparison.Ordinal);
                    break;
                case "missing-invalid-value":
                    retained = RetainedOpaqueStructSource(invalidValues: Array.Empty<long>());
                    break;
                case "named-handle-pointee":
                    records = "namespace Test { [global::Windows.Win32.Foundation.Metadata.NativeTypedef] " +
                        "public struct OPAQUE_TAG { public global::System.IntPtr Value; } }";
                    break;
                case "ambiguous-pointee":
                    records = "namespace Test { public partial struct OPAQUE_TAG { public int First; } " +
                        "public partial struct OPAQUE_TAG { public int Second; } }";
                    break;
                case "ambiguous-pointee-resolution":
                    records = "namespace First { public struct OPAQUE_TAG { } } " +
                        "namespace Second { public struct OPAQUE_TAG { } }";
                    header = "using First; using Second;\n" + header;
                    break;
                case "generic-pointee":
                    records = "namespace Test { public struct GENERIC_TAG<T> { public T Value; } }";
                    header = HeaderWithOpaqueStructProof(storage: "GENERIC_TAG<int>*");
                    break;
                case "nested-pointee":
                    records = "namespace Test { public struct OUTER { public struct NESTED_TAG { } } }";
                    header = HeaderWithOpaqueStructProof(storage: "OUTER.NESTED_TAG*");
                    break;
                case "aliased-pointee":
                    records = "namespace Other { public struct NATIVE_RECORD { public int Value; } }";
                    header = "using OPAQUE_TAG = Other.NATIVE_RECORD;\n" + header;
                    break;
            }
            fixture.Write("autotypes.cs", retained);
            fixture.Write("Bindings.header-types.cs", header);
            fixture.Write("Bindings.cs", records);
            var error = AssertRecoveredConflict(fixture, () => fixture.Compile(),
                emissionFailure: conflict == "generic-pointee" ? "GENERIC_TAG" : null);
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [TestMethod]
        public void OpaqueStructPointerProvidersKeepCanonicalStorageAndReportUnprovedMappings()
        {
            using var fixture = new Fixture("x64");
            string retained = RetainedOpaqueStructSource();
            fixture.Write("autotypes.cs", retained);
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "autotypes.cs"), retained);
            fixture.Write("Bindings.header-types.cs", HeaderWithOpaqueStructProof());
            fixture.Write("Bindings.cs", "namespace Test { public partial struct OPAQUE_TAG { } }");
            var error = AssertRecoveredConflict(fixture, () => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [TestMethod]
        public void OpaqueStructPointerProofCannotOverrideInvalidValueAnnotations()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedOpaqueStructSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithOpaqueStructProof(
                source: OpaqueHeaderSource().Replace("public unsafe",
                    "[global::Windows.Win32.Foundation.Metadata.InvalidHandleValue(5)] public unsafe", StringComparison.Ordinal)));
            fixture.Write("Bindings.cs", "namespace Test { public partial struct OPAQUE_TAG { } }");
            var error = AssertRecoveredConflict(fixture, () => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting 'global::Windows.Win32.Foundation.Metadata.InvalidHandleValueAttribute' annotations");
        }

        [DataTestMethod]
        [DataRow("missing")]
        [DataRow("tag-namespace")]
        [DataRow("pointer-depth")]
        public void OpaqueStructPointerCrossArchCoalescingCannotDiscardConflictingProof(string conflict)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedOpaqueStructSource());
            string header = HeaderWithOpaqueStructProof();
            fixture.Write("Bindings.header-types.cs", header);
            fixture.Write("Bindings.cs", "namespace Test { public partial struct OPAQUE_TAG { } }");
            string conflicting = conflict switch
            {
                "missing" => WithoutHandleSourceProof(header),
                "tag-namespace" => HeaderWithOpaqueStructProof(nativeTag: "Other::OPAQUE_TAG"),
                _ => header.Replace("\"pointerDepth\":1", "\"pointerDepth\":2", StringComparison.Ordinal),
            };
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "x64", "Bindings.header-types.cs"), conflicting);
            var error = AssertRecoveredConflict(fixture, () => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void OpaqueStructPointerProofCannotRebindASecondHeaderProvider(bool excludedTags)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedOpaqueStructSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithOpaqueStructProof());
            fixture.Write("Other.header-types.cs", HeaderWithOpaqueStructProof(storage: "OTHER_TAG*"));
            fixture.Write("Bindings.cs", excludedTags ? "" :
                "namespace Test { public partial struct OPAQUE_TAG { } public partial struct OTHER_TAG { } }");
            var error = AssertRecoveredConflict(fixture, () => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        private static string RetainedOpaqueStructSource(string valueType = "typedef struct OPAQUE_TAG",
            bool explicitWrapperIntent = true, long[]? invalidValues = null)
        {
            using var output = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "COOKIE", Namespace = "Test", ValueType = valueType, NativeTypedef = explicitWrapperIntent,
                    InvalidHandleValues = invalidValues ?? new long[] { -1, 0 },
                },
            }, output);
            return Encoding.UTF8.GetString(output.ToArray());
        }

        private static string HeaderWithOpaqueStructProof(string nativeAlias = "COOKIE", string nativeTag = "OPAQUE_TAG",
            string storage = "OPAQUE_TAG*", string? source = null)
        {
            var root = CSharpSyntaxTree.ParseText(source ?? OpaqueHeaderSource(storage)).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            return root.ReplaceNode(declaration, NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                declaration, nativeAlias, nativeTag, storage, explicitWrapperIntent: true))
                .NormalizeWhitespace().ToFullString() + Environment.NewLine;
        }

        private static string OpaqueHeaderSource(string storage = "OPAQUE_TAG*") =>
            "namespace Test { [global::Windows.Win32.Foundation.Metadata.NativeTypedef] " +
            $"public unsafe partial struct COOKIE {{ public {storage} Value; }} }}";
    }
}
