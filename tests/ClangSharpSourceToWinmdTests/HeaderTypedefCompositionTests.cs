using System;
using System.Collections.Generic;
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
    [TestClass]
    public partial class HeaderTypedefCompositionTests
    {
        [TestMethod]
        public void CrossArchPartialNativeAliasProvidersComposeBeforeDependentBinding()
        {
            using var fixture = new Fixture("crossarch");
            AddPartialNativeAliasProviders(fixture, "byte");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            foreach (var pair in new[] { (Alias: "NATIVE_FLAG", Storage: "BYTE_BASE"), (Alias: "NATIVE_STATUS", Storage: "INT_BASE") })
            {
                var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test." + pair.Alias)!;
                Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
                var field = alias.GetMembers("Value").OfType<IFieldSymbol>().Single();
                Assert.AreEqual("Test." + pair.Storage, field.Type.ToDisplayString());
            }
            var method = compilation.CSharpCompilation.GetTypeByMetadataName("Test.Apis")!.GetMembers("Read").OfType<IMethodSymbol>().Single();
            Assert.AreEqual("Test.NATIVE_STATUS", method.ReturnType.ToDisplayString());
            Assert.AreEqual("Test.NATIVE_FLAG", method.Parameters.Single().Type.ToDisplayString());
            string output = Path.Combine(fixture.DirectoryPath, "PartialProviders.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            RetainPartialProviderImage(output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (var pair in new[] { (Alias: "NATIVE_FLAG", Storage: "BYTE_BASE"), (Alias: "NATIVE_STATUS", Storage: "INT_BASE") })
            {
                var definition = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == pair.Alias);
                var field = reader.GetFieldDefinition(definition.GetFields().Single());
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var storage = signature.ReadTypeHandle();
                Assert.AreEqual(HandleKind.TypeDefinition, storage.Kind);
                Assert.AreEqual(pair.Storage, reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)storage).Name));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow("sbyte")]
        [DataRow("short")]
        [DataRow("float")]
        public void CrossArchPartialNativeAliasProvidersKeepStrictStorageValidation(string storage)
        {
            using var fixture = new Fixture("crossarch");
            AddPartialNativeAliasProviders(fixture, storage);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types.");
        }

        [DataTestMethod]
        [DataRow("byte", false, false)]
        [DataRow("sbyte", false, false)]
        [DataRow("short", false, false)]
        [DataRow("float", false, false)]
        [DataRow("byte", true, false)]
        [DataRow("sbyte", true, false)]
        [DataRow("short", true, false)]
        [DataRow("float", true, false)]
        [DataRow("byte", true, true)]
        [DataRow("sbyte", true, true)]
        [DataRow("short", true, true)]
        [DataRow("float", true, true)]
        public void CrossArchPartialNativeAliasProvidersRetainAllArchitectureVariantFragments(string storage, bool sameSignature, bool sameFile)
        {
            using var fixture = new Fixture("crossarch");
            AddPartialNativeAliasProviders(fixture, storage);
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
            {
                string header = Path.Combine(fixture.DirectoryPath, architecture, "Bindings.header-types.cs");
                string path = Path.Combine(fixture.DirectoryPath, architecture, "Other.header-types.cs");
                string first = File.ReadAllText(header);
                string second = File.ReadAllText(path);
                string incoming = storage;
                if (architecture != "x86")
                {
                    first = first.Replace("public byte Value;", "public ushort Value;");
                    incoming = storage == "byte" ? "ushort" : storage;
                    second = second.Replace("unsigned char", "unsigned short")
                        .Replace("public " + storage + " Value;", "public " + incoming + " Value;");
                }
                if (sameSignature)
                {
                    string clrStorage = incoming switch
                    {
                        "byte" => "System.Byte",
                        "ushort" => "System.UInt16",
                        "sbyte" => "System.SByte",
                        "short" => "System.Int16",
                        "float" => "System.Single",
                        _ => throw new ArgumentOutOfRangeException(nameof(storage)),
                    };
                    first = first.Replace("namespace Test {", "namespace Test { using STORAGE = Test.BYTE_BASE;")
                        .Replace("public BYTE_BASE Value;", "public STORAGE Value;");
                    second = second.Replace("namespace Test {", "namespace Test { using STORAGE = " + clrStorage + ";")
                        .Replace("public " + incoming + " Value;", "public STORAGE Value;");
                    if (sameFile)
                    {
                        var root = CSharpSyntaxTree.ParseText(first).GetCompilationUnitRoot();
                        var other = CSharpSyntaxTree.ParseText(second).GetCompilationUnitRoot();
                        first = root.WithMembers(root.Members.AddRange(other.Members)).ToFullString();
                        File.Delete(path);
                    }
                }
                if (!sameFile)
                    File.WriteAllText(path, second);
                File.WriteAllText(header, first);
            }
            if (sameFile)
            {
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message, "Header native typedef 'Test.NATIVE_FLAG");
                StringAssert.Contains(error.Message, "Multiple native aliases in one input project to the same type.");
                return;
            }
            if (storage != "byte")
            {
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types.");
                return;
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var aliases = new[] { "", "____1" }.Select(suffix =>
                compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_FLAG" + suffix)!).ToArray();
            var consumers = new[] { "", "____1" }.Select(suffix =>
                compilation.CSharpCompilation.GetTypeByMetadataName("Test.CONSUMER" + suffix)!).ToArray();
            foreach (int mask in new[] { 1, 6 })
            {
                var alias = aliases.Single(type => ArchitectureMask(type) == mask);
                Assert.IsNotNull(alias);
                Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
                var backing = (INamedTypeSymbol)alias.GetMembers("Value").OfType<IFieldSymbol>().Single().Type;
                CollectionAssert.Contains(new[] { "BYTE_BASE", "BYTE_BASE____1" }, backing.Name);
                Assert.AreEqual("Test", backing.ContainingNamespace.ToDisplayString());
                Assert.AreEqual(mask, backing.GetAttributes().Single(attribute =>
                    attribute.AttributeClass!.Name == "SupportedArchitectureAttribute").ConstructorArguments.Single().Value,
                    alias.ToDisplayString() + " -> " + backing.ToDisplayString() + Environment.NewLine +
                    string.Join(Environment.NewLine, compilation.CSharpCompilation.SyntaxTrees.SelectMany(tree =>
                        tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                        .Where(declaration => declaration.Identifier.ValueText.StartsWith("NATIVE_FLAG", StringComparison.Ordinal) ||
                            declaration.Identifier.ValueText.StartsWith("BYTE_BASE", StringComparison.Ordinal))
                        .Select(declaration => declaration.ToFullString())));
                Assert.AreEqual(mask == 1 ? SpecialType.System_Byte : SpecialType.System_UInt16,
                    backing.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
                Assert.AreEqual(mask, alias.GetAttributes().Single(attribute =>
                    attribute.AttributeClass!.Name == "SupportedArchitectureAttribute").ConstructorArguments.Single().Value);
                var consumer = consumers.Single(type => ArchitectureMask(type) == mask);
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(alias,
                    consumer.GetMembers("Flag").OfType<IFieldSymbol>().Single().Type));
                var method = compilation.CSharpCompilation.GetTypeByMetadataName("Test.Apis")!
                    .GetMembers().OfType<IMethodSymbol>()
                    .Single(method => (method.Name is "Read" or "Read____1") && ArchitectureMask(method) == mask);
                Assert.AreEqual("Test.NATIVE_STATUS", method.ReturnType.ToDisplayString());
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(alias, method.Parameters.Single().Type));
                Assert.AreEqual(mask, method.GetAttributes().Single(attribute =>
                    attribute.AttributeClass!.Name == "SupportedArchitectureAttribute").ConstructorArguments.Single().Value);
            }
            static int ArchitectureMask(ISymbol symbol) => (int)symbol.GetAttributes().Single(attribute =>
                attribute.AttributeClass!.Name == "SupportedArchitectureAttribute").ConstructorArguments.Single().Value!;
            string output = Path.Combine(fixture.DirectoryPath, sameSignature ? "PartialAliasedProviders.winmd" : "PartialVariantProviders.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            RetainPartialProviderImage(output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var definitions = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "NATIVE_FLAG").ToArray();
            Assert.AreEqual(2, definitions.Length);
            CollectionAssert.AreEquivalent(new[] { 1, 6 }, definitions.Select(type => ReadArchitecture(reader, type)).ToArray());
            foreach (var definition in definitions)
            {
                var field = reader.GetFieldDefinition(definition.GetFields().Single());
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var backing = signature.ReadTypeHandle();
                Assert.AreEqual(HandleKind.TypeDefinition, backing.Kind);
                var backingDefinition = reader.GetTypeDefinition((TypeDefinitionHandle)backing);
                Assert.AreEqual("BYTE_BASE", reader.GetString(backingDefinition.Name));
                int mask = ReadArchitecture(reader, definition);
                Assert.AreEqual(mask, ReadArchitecture(reader, backingDefinition));
                Assert.AreEqual(0, signature.RemainingBytes);
                var storageSignature = reader.GetBlobReader(reader.GetFieldDefinition(backingDefinition.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, storageSignature.ReadSignatureHeader().Kind);
                Assert.AreEqual(mask == 1 ? SignatureTypeCode.Byte : SignatureTypeCode.UInt16, storageSignature.ReadSignatureTypeCode());
                Assert.AreEqual(0, storageSignature.RemainingBytes);
            }
        }

        private static int ReadArchitecture(MetadataReader reader, TypeDefinition definition)
        {
            var handle = definition.GetCustomAttributes().Single(attribute =>
                AttributeName(reader, attribute) == "SupportedArchitectureAttribute");
            var value = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
            Assert.AreEqual((ushort)1, value.ReadUInt16());
            int architecture = value.ReadInt32();
            Assert.AreEqual((ushort)0, value.ReadUInt16());
            Assert.AreEqual(0, value.RemainingBytes);
            return architecture;
        }

        private static void RetainPartialProviderImage(string output)
        {
            string? evidence = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            if (evidence == null)
                return;
            Directory.CreateDirectory(evidence);
            File.Copy(output, Path.Combine(evidence, Path.GetFileName(output)));
        }

        private static void AddPartialNativeAliasProviders(Fixture fixture, string storage)
        {
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"using Windows.Win32.Foundation.Metadata;
namespace Test {
    [NativeTypedef] public partial struct BYTE_BASE { public byte Value; }
    [NativeTypedef] public partial struct INT_BASE { public int Value; }
    [NativeTypedef] public partial struct NATIVE_FLAG { [NativeTypeName(""BYTE_BASE"")] public BYTE_BASE Value; }
    [NativeTypedef] public partial struct NATIVE_STATUS { [NativeTypeName(""INT_BASE"")] public INT_BASE Value; }
}");
            fixture.Write("Other.header-types.cs", @"using Windows.Win32.Foundation.Metadata;
namespace Test {
    [NativeTypedef] public partial struct NATIVE_FLAG { [NativeTypeName(""unsigned char"")] public " + storage + @" Value; }
    [NativeTypedef] public partial struct NATIVE_STATUS { [NativeTypeName(""long"")] public int Value; }
}");
            fixture.Write("Bindings.cs", @"using System.Runtime.InteropServices;
namespace Test {
    public struct CONSUMER { public NATIVE_FLAG Flag; public NATIVE_STATUS Status; }
    public static class Apis { [DllImport(""test"")] public static extern NATIVE_STATUS Read(NATIVE_FLAG value); }
}");
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("crossarch", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        [DataRow("crossarch", true)]
        public void RetainedManualProvidersOwnLegacyRevertedRecordAliases(string architecture, bool headerInputs)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            if (!headerInputs)
                foreach (string target in architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { architecture })
                    File.Delete(Path.Combine(fixture.DirectoryPath, target, "Bindings.header-types.cs"));
            const string body = "{ public float r; public float g; public float b; public float a; }";
            fixture.Write("Legacy.manual.cs", "using Windows.Win32.Foundation.Metadata; namespace Original { " +
                "[Documentation(\"retained type documentation\")] public partial struct COLOR " +
                body.Replace("public float r;", "[Documentation(\"retained field documentation\")] public float r;") + " }");
            const string source = "using Canonical; namespace First { public partial struct COLOR___ " + body +
                " public struct Consumer { public COLOR___ Value; } }";
            fixture.Write("Bindings.cs", source);
            fixture.Write("Other.cs", source.Replace("namespace First", "namespace Second"));
            var compilation = fixture.Compile(new() { ["COLOR"] = "Canonical" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var color = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.COLOR")!;
            Assert.AreEqual(1, color.DeclaringSyntaxReferences.Length);
            Assert.AreEqual("retained type documentation", color.GetAttributes().Single().ConstructorArguments.Single().Value);
            Assert.AreEqual("retained field documentation",
                color.GetMembers("r").Single().GetAttributes().Single().ConstructorArguments.Single().Value);
            Assert.IsTrue(color.DeclaringSyntaxReferences.Single().SyntaxTree.FilePath
                .EndsWith("Legacy.manual.modified.cs", StringComparison.OrdinalIgnoreCase));
            foreach (string ns in new[] { "First", "Second" })
            {
                Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".COLOR___"));
                var consumer = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".Consumer")!;
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(color,
                    consumer.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            }
            string output = Path.Combine(fixture.DirectoryPath, "LegacyColors.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var colors = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Name).StartsWith("COLOR", StringComparison.Ordinal)).ToArray();
            Assert.AreEqual(1, colors.Length);
            Assert.AreEqual("Canonical", reader.GetString(colors[0].Namespace));
            var fields = colors[0].GetFields().Select(reader.GetFieldDefinition).ToArray();
            CollectionAssert.AreEqual(new[] { "r", "g", "b", "a" },
                fields.Select(field => reader.GetString(field.Name)).ToArray());
            foreach (var field in fields)
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x0c }, reader.GetBlobBytes(field.Signature));
        }

        [TestMethod]
        public void CompleteEmptyNativeRecordsDoNotBecomeLegacyManualProviders()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", "namespace Test { public partial struct EMPTY { } public partial struct EMPTY___ { } }");
            var compilation = fixture.Compile();
            foreach (string name in new[] { "Test.EMPTY", "Test.EMPTY___" })
            {
                var record = compilation.CSharpCompilation.GetTypeByMetadataName(name);
                Assert.IsNotNull(record);
                Assert.AreEqual(1, record!.DeclaringSyntaxReferences.Length);
            }
            string output = Path.Combine(fixture.DirectoryPath, "CompleteEmpty.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Test").ToArray();
            CollectionAssert.AreEquivalent(new[] { "EMPTY", "EMPTY___" },
                records.Select(definition => reader.GetString(definition.Name)).ToArray());
            Assert.IsTrue(records.All(definition => definition.GetFields().Count == 0));
        }

        [DataTestMethod]
        [DataRow("storage")]
        [DataRow("binding")]
        [DataRow("layout")]
        [DataRow("documentation-shadow")]
        public void ConflictingLegacyRecordStorageBindingsOrAttributesCannotReplaceManualProviders(string conflict)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Legacy.manual.cs", "using STORAGE = System.Int32; namespace Test { " +
                "public partial struct COLOR { public STORAGE Value; } }");
            fixture.Write("Bindings.cs", conflict switch
            {
                "binding" => "using STORAGE = System.UInt32; namespace Test { public partial struct COLOR___ { public STORAGE Value; } }",
                "layout" => "using STORAGE = System.Int32; using System.Runtime.InteropServices; namespace Test { " +
                    "[StructLayout(LayoutKind.Sequential, Pack=1)] public partial struct COLOR___ { public STORAGE Value; } }",
                "documentation-shadow" => "using STORAGE = System.Int32; using Other; " +
                    "namespace Other { public class DocumentationAttribute : System.Attribute { } } " +
                    "namespace Test { [Documentation] public partial struct COLOR___ { public STORAGE Value; } }",
                _ => "namespace Test { public partial struct COLOR___ { } }",
            });
            var error = Assert.ThrowsException<InvalidOperationException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "established manual provider 'Test.COLOR'");
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void InferredAliasesDoNotAssumeLayoutOfRetainedNominalStorage(bool explicitLayout)
        {
            using var fixture = new Fixture("x86");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", @"
using System.Runtime.InteropServices;
namespace Canonical {
[global::Windows.Win32.Foundation.Metadata.NativeTypedef]
[StructLayout(LayoutKind." + (explicitLayout ? "Explicit" : "Sequential, Pack = 1") + @")]
public struct RETAINED { " + (explicitLayout ? "[FieldOffset(0)] " : "") + @"public byte Value; }
}");
            var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, "Test", "native-alias", true,
                "global::Canonical.RETAINED", 1, 1)).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            fixture.Write("Test.header-types.cs", root.ReplaceNode(declaration,
                NativeTypedefProjectionProvenance.WithPolicy(declaration, inferred: true)).ToFullString());
            fixture.Write("Test.cs", "namespace Test { public struct Carrier { public SCALAR Value; } }");
            var compilation = fixture.Compile();
            string output = Path.Combine(fixture.DirectoryPath, "UnprovenNominalLayout.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition).ToArray();
            Assert.AreEqual(1, types.Count(type => reader.GetString(type.Name) == "SCALAR"));
            var carrier = types.Single(type => reader.GetString(type.Name) == "Carrier");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var alias = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Test", reader.GetString(alias.Namespace));
            Assert.AreEqual("SCALAR", reader.GetString(alias.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void ManualForwardsComposeWithoutDiscardingCompleteEmptyRecords(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Legacy.manual.cs", "namespace Test { public struct OPAQUE; }");
            fixture.Write("Bindings.cs", "namespace Test { public partial struct OPAQUE { } " +
                "public partial struct COMPLETE_EMPTY { } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var native = compilation.CSharpCompilation.GetTypeByMetadataName("Test.OPAQUE")!;
            Assert.AreEqual(2, native.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(native.DeclaringSyntaxReferences.Any(reference =>
                reference.SyntaxTree.FilePath.EndsWith("Bindings.modified.cs", StringComparison.OrdinalIgnoreCase)));
            string output = Path.Combine(fixture.DirectoryPath, "EmptyRecords.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Test").ToArray();
            CollectionAssert.AreEquivalent(new[] { "OPAQUE", "COMPLETE_EMPTY" },
                records.Select(definition => reader.GetString(definition.Name)).ToArray());
            Assert.IsTrue(records.All(definition => definition.GetFields().Count == 0));
        }

        [TestMethod]
        public void BraceBodiedManualEmptyRecordsAreNotTreatedAsForwardDeclarations()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Legacy.manual.cs", "namespace Test { public struct COMPLETE_EMPTY { } }");
            fixture.Write("Bindings.cs", "namespace Test { public partial struct COMPLETE_EMPTY { } }");
            var compilation = fixture.Compile();
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0260"));
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void RepeatedNativeRecordsComposeAfterSharedNamespaceAssignment(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            const string record = @"using System.Runtime.InteropServices;
namespace First {
    [StructLayout(LayoutKind.Sequential, Pack = 1)]
    public partial struct NATIVE_RECORD { public int Value; public short Other; }
}";
            fixture.Write("Bindings.cs", record);
            fixture.Write("Other.cs", record.Replace("namespace First", "namespace Second"));
            var compilation = fixture.Compile(new() { ["NATIVE_RECORD"] = "Canonical" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var type = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD");
            Assert.IsNotNull(type);
            Assert.AreEqual(1, type!.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(2, type.GetMembers().OfType<IFieldSymbol>().Count(field => !field.IsImplicitlyDeclared));
            string output = Path.Combine(fixture.DirectoryPath, "Records.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Name) == "NATIVE_RECORD");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            Assert.AreEqual(1, (int)physical.GetLayout().PackingSize);
            var fields = physical.GetFields().Select(reader.GetFieldDefinition).ToArray();
            Assert.AreEqual(2, fields.Length);
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 }, reader.GetBlobBytes(fields[0].Signature));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x06 }, reader.GetBlobBytes(fields[1].Signature));
        }

        [TestMethod]
        public void IdenticalRecordTextWithDifferentTypeBindingsRemainsACompilerError()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            const string source = @"using STORAGE = System.Int32;
namespace Test { public partial struct NATIVE_RECORD { public STORAGE Value; } }";
            fixture.Write("Bindings.cs", source);
            fixture.Write("Other.cs", source.Replace("System.Int32", "System.UInt32"));
            var compilation = fixture.Compile();
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_RECORD")!.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(false, true)]
        [DataRow(true, false)]
        [DataRow(true, true)]
        public void NativeRecordProvidersPreferDirectHeaderOwnershipAndExplicitRoutes(bool sameInput, bool explicitRoute)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            string observer = RecordProvider(fixture, "Dependency", "native-record", traversed: false);
            string owner = RecordProvider(fixture, "Canonical", "native-record", traversed: true);
            fixture.Write("Bindings.cs", sameInput ? observer + owner : observer);
            if (!sameInput)
                fixture.Write("Other.cs", owner);
            fixture.Write("Use.cs", @"using System.Runtime.InteropServices;
namespace Dependency { public static partial class Apis {
[DllImport(""record.dll"")] public static extern void UseNative(NATIVE_RECORD value); } }");
            var routes = new Dictionary<string, string> { ["UseNative"] = "Api" };
            if (explicitRoute)
                routes.Add("NATIVE_RECORD", "Explicit");
            var compilation = fixture.Compile(routes);
            var errors = compilation.CSharpCompilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string ns = explicitRoute ? "Explicit" : "Canonical";
            var record = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".NATIVE_RECORD")!;
            Assert.IsNotNull(record);
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(1, record.GetMembers().OfType<IFieldSymbol>().Count(field => !field.IsImplicitlyDeclared));
            var method = compilation.CSharpCompilation.GetTypeByMetadataName("Api.Apis")!.GetMembers("UseNative").OfType<IMethodSymbol>().Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(record, method.Parameters.Single().Type));
        }

        [TestMethod]
        public void DistinctNativeRecordsSharingAShortNameRetainTheirSourceNamespaces()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", RecordProvider(fixture, "First", "first-record", traversed: true));
            fixture.Write("Other.cs", RecordProvider(fixture, "Second", "second-record", traversed: true, storage: "uint"));
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.CSharpCompilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            foreach (var pair in new[] { (Namespace: "First", Storage: SpecialType.System_Int32), (Namespace: "Second", Storage: SpecialType.System_UInt32) })
            {
                var record = compilation.CSharpCompilation.GetTypeByMetadataName(pair.Namespace + ".NATIVE_RECORD")!;
                Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
                Assert.AreEqual(pair.Storage, record.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
            }
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void InferredNativeOwnerDoesNotRelocateAnUntrackedShortNameCollision(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", "using System.Runtime.InteropServices;\n" +
                RecordProvider(fixture, "Canonical", "native-record", traversed: true)
                    .Replace("public partial struct", "[global::Windows.Win32.Foundation.Metadata.Documentation(\"native\")] public partial struct") +
                @"namespace Canonical { public static partial class Apis {
[DllImport(""native.dll"")] public static extern NATIVE_RECORD NativeUse(); } }");
            fixture.Write("Other.cs", @"using System.Runtime.InteropServices;
namespace Other {
[global::Windows.Win32.Foundation.Metadata.Documentation(""ordinary"")]
public partial struct NATIVE_RECORD { public uint Value; }
public static partial class Apis {
[DllImport(""ordinary.dll"")] public static extern NATIVE_RECORD OrdinaryUse(); } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            foreach (var expected in new[]
            {
                (Namespace: "Canonical", Method: "NativeUse", Storage: SpecialType.System_Int32),
                (Namespace: "Other", Method: "OrdinaryUse", Storage: SpecialType.System_UInt32),
            })
            {
                var record = compilation.CSharpCompilation.GetTypeByMetadataName(expected.Namespace + ".NATIVE_RECORD")!;
                Assert.IsNotNull(record);
                Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
                Assert.AreEqual(expected.Storage, record.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
                var method = compilation.CSharpCompilation.GetTypeByMetadataName(expected.Namespace + ".Apis")!
                    .GetMembers(expected.Method).OfType<IMethodSymbol>().Single();
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(record, method.ReturnType));
            }
            string output = Path.Combine(fixture.DirectoryPath, "DistinctOwners.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "NATIVE_RECORD").ToArray();
            Assert.AreEqual(2, records.Length);
            foreach (var expected in new[] { (Namespace: "Canonical", Code: (byte)0x08), (Namespace: "Other", Code: (byte)0x09) })
            {
                var record = records.Single(type => reader.GetString(type.Namespace) == expected.Namespace);
                CollectionAssert.AreEqual(new byte[] { 0x06, expected.Code },
                    reader.GetBlobBytes(reader.GetFieldDefinition(record.GetFields().Single()).Signature));
                var api = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Name) == "Apis" && reader.GetString(type.Namespace) == expected.Namespace);
                var signature = reader.GetBlobReader(reader.GetMethodDefinition(api.GetMethods().Single()).Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(0, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                Assert.AreEqual(expected.Namespace, reader.GetString(ResolveLocalType(reader, signature.ReadTypeHandle()).Namespace));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow("x86", "")]
        [DataRow("x64", "")]
        [DataRow("arm64", "")]
        [DataRow("crossarch", "")]
        [DataRow("x64", "storage")]
        [DataRow("x64", "attribute")]
        [DataRow("x64", "proof")]
        [DataRow("x64", "abi")]
        public void ConditionalAnonymousUnionProvidersKeepCanonicalTraversedBody(string architecture, string conflict)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Owner.cs", Provider("ZCanonical", true));
            fixture.Write("Observer.cs", Provider("AObserver", false));
            fixture.Write("Use.cs", "using System.Runtime.InteropServices; namespace AObserver {" +
                "public static partial class Apis { [DllImport(\"native.dll\")] " +
                "public static extern NATIVE_RECORD Echo(NATIVE_RECORD value); }}");
            if (conflict is "proof" or "abi")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            if (conflict.Length != 0)
            {
                Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("ZCanonical.NATIVE_RECORD")!
                    .DeclaringSyntaxReferences.Length);
                Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
                return;
            }
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalAnonymousUnion.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var record = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            Assert.AreEqual("ZCanonical", reader.GetString(record.Namespace));
            CollectionAssert.AreEqual(new[] { "tag", "u", "trailer" },
                record.GetFields().Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)).ToArray());
            var union = reader.GetTypeDefinition(record.GetNestedTypes().Single());
            Assert.AreEqual("_u_e__Union", reader.GetString(union.Name));
            Assert.AreEqual(System.Reflection.TypeAttributes.ExplicitLayout, union.Attributes & System.Reflection.TypeAttributes.LayoutMask);
            CollectionAssert.AreEqual(new[] { "First", "Second" },
                union.GetFields().Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)).ToArray());
            foreach (var handle in union.GetFields())
            {
                var field = reader.GetFieldDefinition(handle);
                Assert.AreEqual(0, field.GetOffset());
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(reader.GetString(field.Name) == "First" ? SignatureTypeCode.Int32 : SignatureTypeCode.UInt32,
                    signature.ReadSignatureTypeCode());
                Assert.AreEqual(0, signature.RemainingBytes);
            }
            var echo = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "Echo");
            var methodSignature = reader.GetBlobReader(echo.Signature);
            Assert.AreEqual(SignatureKind.Method, methodSignature.ReadSignatureHeader().Kind);
            Assert.AreEqual(1, methodSignature.ReadCompressedInteger());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, methodSignature.ReadSignatureTypeCode());
            var returnType = methodSignature.ReadTypeHandle();
            Assert.AreEqual(SignatureTypeCode.TypeHandle, methodSignature.ReadSignatureTypeCode());
            Assert.AreEqual(returnType, methodSignature.ReadTypeHandle());
            Assert.AreEqual("ZCanonical", reader.GetString(ResolveLocalType(reader, returnType).Namespace));
            Assert.AreEqual(0, methodSignature.RemainingBytes);

            string Provider(string ns, bool direct)
            {
                string nestedName = direct ? "_u_e__Union" : "_Anonymous_e__Union";
                uint line = direct ? 10U : 20U;
                string storage = !direct && conflict == "storage" ? "uint" : "int";
                int offset = !direct && conflict == "attribute" ? 4 : 0;
                string header = Path.Combine(fixture.DirectoryPath, "native.h");
                var root = CSharpSyntaxTree.ParseText("using System.Runtime.InteropServices;" +
                    "using Windows.Win32.Foundation.Metadata; namespace " + ns + " {" +
                    "public partial struct NATIVE_RECORD { public int tag;" +
                    "[NativeTypeName(\"__AnonymousRecord_native_L" + (line + 1) + "_C1\")] public " +
                    nestedName + " " + (direct ? "u" : "Anonymous") + "; public int trailer;" +
                    "[StructLayout(LayoutKind.Explicit)] public partial struct " + nestedName + " {" +
                    "[FieldOffset(" + offset + ")] public " + storage + " First; [FieldOffset(0)] public uint Second; }}}").GetRoot();
                if (direct || conflict != "proof")
                {
                    var nested = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                        .Single(declaration => declaration.Identifier.ValueText == nestedName);
                    root = root.ReplaceNode(nested, NativeRecordSourceProvenance.Attach(nested,
                        new NativeRecordSource("c:@S@RECORD" + (direct ? "@U@native.h@32" : "@Ua"),
                            "native::NATIVE_RECORD::(" + (direct ? "unnamed" : "anonymous") + " union at " +
                            header + ":" + (line + 1) + ":1)", header, new string('A', 64), line + 1, 1,
                            nestedName, ns, direct, 4, 4)));
                }
                var record = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Single(declaration => declaration.Identifier.ValueText == "NATIVE_RECORD");
                return root.ReplaceNode(record, NativeRecordSourceProvenance.Attach(record,
                    new NativeRecordSource("c:@S@RECORD", "native::NATIVE_RECORD", header, new string('A', 64),
                        line, 1, "NATIVE_RECORD", ns, direct, !direct && conflict == "abi" ? 16 : 12, 4))).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow(false, false, false)]
        [DataRow(true, false, false)]
        [DataRow(false, true, false)]
        [DataRow(true, true, false)]
        [DataRow(false, false, true)]
        [DataRow(false, true, true)]
        public void ConditionalNativeProviderLocationsRespectArchitectureApplicability(bool alias, bool commonConflict,
            bool conditionalRecordIdentity)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            string name = alias ? "SCALAR" : "NATIVE_RECORD";
            foreach (var target in new[]
            {
                (Architecture: "x86", Storage: "int", Line: 10U, Size: 4L),
                (Architecture: "x64", Storage: "long", Line: 20U, Size: 8L),
                (Architecture: "arm64", Storage: "uint", Line: 30U, Size: 4L),
            })
            {
                string directory = Path.Combine(fixture.DirectoryPath, target.Architecture);
                foreach (var provider in new[] { (File: "Bindings", Namespace: "Observed", Direct: false),
                    (File: "Owner", Namespace: "Canonical", Direct: true) })
                {
                    string source = alias
                        ? TypedefProvider(fixture, provider.Namespace, "conditional-native", provider.Direct,
                            target.Storage, target.Size, target.Size, target.Line)
                        : RecordProvider(fixture, provider.Namespace,
                            conditionalRecordIdentity && target.Architecture == "arm64" ? "conditional-native-arm64" : "conditional-native",
                            provider.Direct, target.Storage, target.Size, target.Line,
                            conditionalRecordIdentity && target.Architecture == "arm64" ? "native::NATIVE_RECORD_ARM64" : null);
                    File.WriteAllText(Path.Combine(directory, provider.File + (alias ? ".header-types.cs" : ".cs")), source);
                }
                File.WriteAllText(Path.Combine(directory, "Use.cs"), @"using System.Runtime.InteropServices;
namespace Observed { public static partial class Apis {
[DllImport(""conditional.dll"")] public static extern " + name + " Echo(" + name + " value); } }");
            }
            if (commonConflict)
            {
                string directory = Path.Combine(fixture.DirectoryPath, "common");
                Directory.CreateDirectory(directory);
                File.WriteAllText(Path.Combine(directory, alias ? "Common.header-types.cs" : "Common.cs"),
                    alias ? TypedefProvider(fixture, "Observed", "conditional-native", false, line: 99)
                        : RecordProvider(fixture, "Observed", "conditional-native", false, line: 99));
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message,
                    "Conflicting native record identities");
                return;
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "ConditionalProviders.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var definitions = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == name).ToArray();
            Assert.AreEqual(3, definitions.Length);
            CollectionAssert.AreEquivalent(new[] { 1, 2, 4 }, definitions.Select(type => ReadArchitecture(reader, type)).ToArray());
            foreach (var definition in definitions)
            {
                Assert.AreEqual("Canonical", reader.GetString(definition.Namespace));
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(definition.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(ReadArchitecture(reader, definition) switch
                {
                    1 => SignatureTypeCode.Int32,
                    2 => SignatureTypeCode.Int64,
                    4 => SignatureTypeCode.UInt32,
                    _ => throw new InvalidOperationException("Unexpected architecture."),
                }, signature.ReadSignatureTypeCode());
                Assert.AreEqual(0, signature.RemainingBytes);
            }
            var methods = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Where(method => reader.GetString(method.Name) == "Echo").ToArray();
            Assert.AreEqual(3, methods.Length);
            foreach (var method in methods)
            {
                var signature = reader.GetBlobReader(method.Signature);
                Assert.IsFalse(signature.ReadSignatureHeader().IsInstance);
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var result = signature.ReadTypeHandle();
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                Assert.AreEqual(result, signature.ReadTypeHandle());
                Assert.AreEqual(0, signature.RemainingBytes);
                var definition = ResolveLocalType(reader, result);
                Assert.AreEqual("Canonical", reader.GetString(definition.Namespace));
                Assert.AreEqual(name, reader.GetString(definition.Name));
                var attribute = reader.GetCustomAttribute(method.GetCustomAttributes().Single(handle =>
                    AttributeName(reader, handle) == "SupportedArchitectureAttribute"));
                var value = reader.GetBlobReader(attribute.Value);
                Assert.AreEqual((ushort)1, value.ReadUInt16());
                Assert.AreEqual(ReadArchitecture(reader, definition), value.ReadInt32());
            }
        }

        [DataTestMethod]
        [DataRow("identity")]
        [DataRow("abi")]
        public void NativeRecordProvidersRejectConflictingIdentityAndAbi(string conflict)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", RecordProvider(fixture, "Test", "native-record", traversed: true));
            fixture.Write("Other.cs", RecordProvider(fixture, "Test",
                conflict == "identity" ? "another-record" : "native-record", traversed: false,
                size: conflict == "abi" ? 8 : 4));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CSSW005");
            StringAssert.Contains(error.Message, conflict == "identity" ? "Distinct native records" : "Conflicting native record providers");
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeRecordProvidersDoNotDiscardDifferentStorageBindings(bool alias)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", (alias ? "using STORAGE = System.Int32;\n" : "") +
                RecordProvider(fixture, "Test", "native-record", traversed: true, storage: alias ? "STORAGE" : "int"));
            fixture.Write("Other.cs", (alias ? "using STORAGE = System.UInt32;\n" : "") +
                RecordProvider(fixture, "Test", "native-record", traversed: false, storage: alias ? "STORAGE" : "uint"));
            var compilation = fixture.Compile();
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_RECORD")!.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void MovedNativeFieldRemapsRetainNativeSpellingAndSelectedEnum(bool explicitNativeName)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs",
                TypedefProvider(fixture, "Dependency", "native-scalar", traversed: false, storage: "uint"));
            fixture.Write("Other.header-types.cs",
                TypedefProvider(fixture, "Canonical", "native-scalar", traversed: true, storage: "uint"));
            fixture.Write("Flags.manual.cs", "namespace Public { public enum FLAGS : uint { First = 1 } }");
            string record = RecordProvider(fixture, "Dependency", "native-record", traversed: true, storage: "SCALAR");
            if (explicitNativeName)
                record = record.Replace("public SCALAR Value;", "[NativeTypeName(\"unsigned int\")] public SCALAR Value;");
            fixture.Write("Bindings.cs", "using Windows.Win32.Foundation.Metadata;\n" + record);
            var compilation = fixture.Compile(new() { ["NATIVE_RECORD"] = "Selected", ["FLAGS"] = "Public" },
                new() { ["NATIVE_RECORD::Value"] = "FLAGS" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var field = compilation.CSharpCompilation.GetTypeByMetadataName("Selected.NATIVE_RECORD")!
                .GetMembers("Value").OfType<IFieldSymbol>().Single();
            Assert.AreEqual("Public.FLAGS", field.Type.ToDisplayString());
            string nativeName = explicitNativeName ? "unsigned int" : "SCALAR";
            Assert.AreEqual(nativeName, field.GetAttributes().Single(attribute =>
                attribute.AttributeClass!.Name == "NativeTypeNameAttribute").ConstructorArguments.Single().Value);
            string output = Path.Combine(fixture.DirectoryPath, "NativeFieldRemap.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            var physicalField = reader.GetFieldDefinition(physical.GetFields().Single());
            var signature = reader.GetBlobReader(physicalField.Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var flags = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Public", reader.GetString(flags.Namespace));
            Assert.AreEqual("FLAGS", reader.GetString(flags.Name));
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void RepeatedNativeBitfieldHelpersDoNotPreventDeclarationComposition(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs",
                TypedefProvider(fixture, "Canonical", "native-scalar", traversed: true, storage: "uint"));
            const string members = @"[Windows.Win32.Foundation.Metadata.NativeBitfield(""Bits"", offset: 0, length: 1)]
public SCALAR Value;
public SCALAR Bits {
get { return Value & 1u; }
set { Value = (Value & ~1u) | (value & 1u); }
}";
            fixture.Write("Bindings.cs", "using Canonical;\n" +
                RecordProvider(fixture, "Dependency", "native-record", traversed: false)
                    .Replace("public int Value;", members));
            fixture.Write("Other.cs",
                RecordProvider(fixture, "Canonical", "native-record", traversed: true)
                    .Replace("public int Value;", members));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(1, record.GetMembers().OfType<IFieldSymbol>().Count(field => !field.IsImplicitlyDeclared));
            Assert.IsTrue(compilation.CSharpCompilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0019"));
            string output = Path.Combine(fixture.DirectoryPath, "Bitfields.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            Assert.AreEqual(0, physical.GetProperties().Count);
            Assert.AreEqual(0, physical.GetMethods().Count);
            var field = reader.GetFieldDefinition(physical.GetFields().Single());
            Assert.AreEqual("Value", reader.GetString(field.Name));
            var signature = reader.GetBlobReader(field.Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var scalar = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Canonical", reader.GetString(scalar.Namespace));
            Assert.AreEqual("SCALAR", reader.GetString(scalar.Name));
            var storage = reader.GetFieldDefinition(scalar.GetFields().Single());
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x09 }, reader.GetBlobBytes(storage.Signature));
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void RepeatedNativeRecordsKeepUnresolvedNonEmittedHelperLocals(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            const string members = @"public int Value;
public int Helper { get { UNRESOLVED local = default; return Value; } }";
            fixture.Write("Bindings.cs",
                RecordProvider(fixture, "Dependency", "native-record", traversed: false)
                    .Replace("public int Value;", members));
            fixture.Write("Other.cs",
                RecordProvider(fixture, "Canonical", "native-record", traversed: true)
                    .Replace("public int Value;", members));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.IsTrue(compilation.CSharpCompilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0246"));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            string output = Path.Combine(fixture.DirectoryPath, "UnresolvedHelper.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            Assert.AreEqual(0, physical.GetMethods().Count);
            var field = reader.GetFieldDefinition(physical.GetFields().Single());
            Assert.AreEqual("Value", reader.GetString(field.Name));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 }, reader.GetBlobBytes(field.Signature));
        }

        [DataTestMethod]
        [DataRow("field")]
        [DataRow("attribute")]
        [DataRow("property")]
        public void RepeatedNativeRecordsDoNotDiscardUnresolvedDeclarationBindings(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            string members = scenario switch
            {
                "field" => "public UNRESOLVED Value;",
                "attribute" => "[UNRESOLVED] public int Value;",
                "property" => "public int Value; public UNRESOLVED Helper { get { return default; } }",
                _ => throw new InvalidOperationException(scenario),
            };
            foreach (string file in new[] { "Bindings.cs", "Other.cs" })
                fixture.Write(file, RecordProvider(fixture, "Canonical", "native-record", file == "Bindings.cs")
                    .Replace("public int Value;", members));
            var compilation = fixture.Compile();
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic =>
                diagnostic.Severity == DiagnosticSeverity.Error && diagnostic.Id == "CS0246"));
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!
                .DeclaringSyntaxReferences.Length);
        }

        [DataTestMethod]
        [DataRow(1)]
        [DataRow(2)]
        [DataRow(4)]
        [DataRow(6)]
        [DataRow(7)]
        public void GeneratedLegacyAliasesRetainTheirSourceTargetsThroughPhysicalComposition(int mask)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + Environment.NewLine);
            foreach (var target in new[] { (Name: "x86", Mask: 1), (Name: "x64", Mask: 2), (Name: "arm64", Mask: 4) })
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Name, "Bindings.cs"),
                    (mask & target.Mask) == 0 ? "" :
                    "namespace Canonical { public enum ORIGINAL_KIND : int { ORIGINAL_VALUE = 5 } }");
            string header = Path.Combine(fixture.DirectoryPath, "aliases.h");
            File.WriteAllText(header, "#define FORWARDED_TWICE FORWARDED\n#define FORWARDED ORIGINAL_VALUE\n#define COMMON_VALUE 7\n");
            for (int pass = 0; pass < 2; pass++)
            {
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Alias", fixture.DirectoryPath, "",
                    new(), new() { [header] = "Alias" }, new(), new(), new(), new());
                foreach (var target in new[] { (Name: "x86", Mask: 1), (Name: "x64", Mask: 2), (Name: "arm64", Mask: 4) })
                {
                    var sources = Directory.GetFiles(fixture.DirectoryPath, "*.cs")
                        .Concat(Directory.GetFiles(Path.Combine(fixture.DirectoryPath, target.Name), "*.cs"))
                        .Select(file => CSharpSyntaxTree.ParseText(File.ReadAllText(file), path: file));
                    var control = CSharpCompilation.Create("LegacyAliasControl", sources,
                        new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                        new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                    var errors = control.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                    Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
                    var apis = control.GetTypeByMetadataName("Alias.Apis")!;
                    foreach (string name in new[] { "FORWARDED", "FORWARDED_TWICE" })
                    {
                        var fields = apis.GetMembers(name).OfType<IFieldSymbol>().ToArray();
                        Assert.AreEqual((mask & target.Mask) == 0 ? 0 : 1, fields.Length);
                        if (fields.Length != 0)
                        {
                            Assert.AreEqual(SpecialType.System_Int32, fields[0].Type.SpecialType);
                            Assert.AreEqual(5, fields[0].ConstantValue);
                        }
                    }
                    Assert.AreEqual(7u, apis.GetMembers("COMMON_VALUE").OfType<IFieldSymbol>().Single().ConstantValue);
                }
            }
            var compilation = fixture.Compile();
            var diagnostics = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, diagnostics.Length, string.Join(Environment.NewLine, diagnostics.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "TargetedAliases.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Namespace) == "Alias" && reader.GetString(type.Name) == "Apis");
            foreach (string name in new[] { "FORWARDED", "FORWARDED_TWICE", "COMMON_VALUE" })
            {
                var field = physical.GetFields().Select(reader.GetFieldDefinition)
                    .Single(candidate => reader.GetString(candidate.Name) == name);
                CollectionAssert.AreEqual(new byte[] { 0x06, name == "COMMON_VALUE" ? (byte)0x09 : (byte)0x08 },
                    reader.GetBlobBytes(field.Signature));
                var value = reader.GetConstant(field.GetDefaultValue());
                Assert.AreEqual(name == "COMMON_VALUE" ? 7 : 5, reader.GetBlobReader(value.Value).ReadInt32());
                var attributes = field.GetCustomAttributes().Where(attribute =>
                    AttributeName(reader, attribute) == "SupportedArchitectureAttribute").ToArray();
                Assert.AreEqual(name == "COMMON_VALUE" || mask == 7 ? 0 : 1, attributes.Length);
                if (attributes.Length != 0)
                {
                    var attribute = reader.GetBlobReader(reader.GetCustomAttribute(attributes.Single()).Value);
                    Assert.AreEqual((ushort)1, attribute.ReadUInt16());
                    Assert.AreEqual(mask, attribute.ReadInt32());
                }
            }
        }

        [DataTestMethod]
        [DataRow(1, "matching")]
        [DataRow(2, "matching")]
        [DataRow(4, "matching")]
        [DataRow(6, "matching")]
        [DataRow(7, "matching")]
        [DataRow(2, "identity")]
        [DataRow(2, "storage")]
        [DataRow(2, "attribute")]
        public void CommonCanonicalPointerAliasRetainsCoverageWithMatchingSparseObservations(int mask, string scenario)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Additional.header-types.cs", "");
            fixture.Write("Bindings.cs", @"using System.Runtime.InteropServices;
namespace Consumer { public static partial class Apis {
    [DllImport(""test"")] public static extern global::Canonical.POINTER Echo(global::Canonical.POINTER value);
} }");
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Word.header-types.cs"),
                TypedefProvider(fixture, "Canonical", "native-word", true, "ushort", 2, 2).Replace("SCALAR", "WORD"));
            File.WriteAllText(Path.Combine(common, "OtherWord.header-types.cs"),
                TypedefProvider(fixture, "Canonical", "native-other-word", true, "ushort", 2, 2, line: 3)
                    .Replace("SCALAR", "OTHERWORD"));
            string canonical = Pointer("Canonical", true, 4, "native-pointer", "global::Canonical.WORD*");
            var root = CSharpSyntaxTree.ParseText(canonical).GetCompilationUnitRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var proof = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = Architecture.X86 };
            canonical = root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList)), proof)).ToFullString();
            File.WriteAllText(Path.Combine(common, "Owner.header-types.cs"), canonical);
            File.WriteAllText(Path.Combine(common, "Legacy.header-types.cs"), @"using Windows.Win32.Foundation.Metadata;
namespace Canonical { [NativeTypedef] public unsafe partial struct POINTER {
    [NativeTypeName(""WORD *"")] public global::Canonical.WORD* Value;
} }");
            foreach (var target in new[] { (Name: "x86", Mask: 1), (Name: "x64", Mask: 2), (Name: "arm64", Mask: 4) })
                if ((mask & target.Mask) != 0)
                {
                    string incoming = Pointer(scenario == "identity" ? "Canonical" : "Dependency", false, target.Mask == 1 ? 4 : 8,
                        scenario == "identity" ? "another-native-pointer" : "native-pointer",
                        scenario == "storage" ? "global::Canonical.OTHERWORD*" : "global::Canonical.WORD*");
                    if (scenario == "attribute")
                        incoming = incoming.Replace("[NativeTypedef]", "[global::System.Obsolete(\"extra\")] [NativeTypedef]")
                            .Replace("[global::Windows.Win32.Foundation.Metadata.NativeTypedef]",
                                "[global::System.Obsolete(\"extra\")] [global::Windows.Win32.Foundation.Metadata.NativeTypedef]");
                    File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Name, "Additional.header-types.cs"), incoming);
                }
            if (scenario != "matching")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var pointer = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.POINTER")!;
            Assert.AreEqual(1, pointer.DeclaringSyntaxReferences.Length);
            var selected = (StructDeclarationSyntax)pointer.DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.IsTrue(NativeTypedefSourceProvenance.Read(selected)!.TraversedHeader);
            string output = Path.Combine(fixture.DirectoryPath, "CommonPointer.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "POINTER");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            Assert.IsFalse(physical.GetCustomAttributes().Any(attribute =>
                AttributeName(reader, attribute) == "SupportedArchitectureAttribute"));
            var field = reader.GetFieldDefinition(physical.GetFields().Single());
            var signature = reader.GetBlobReader(field.Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var word = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Canonical", reader.GetString(word.Namespace));
            Assert.AreEqual("WORD", reader.GetString(word.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x07 },
                reader.GetBlobBytes(reader.GetFieldDefinition(word.GetFields().Single()).Signature));

            string Pointer(string ns, bool direct, int size, string identity, string storage) =>
                TypedefProvider(fixture, ns, identity, direct, storage, size, size, line: 2)
                    .Replace("SCALAR", "POINTER").Replace("public partial struct", "public unsafe partial struct")
                    .Replace("public " + storage + " Value;", "[NativeTypeName(\"WORD *\")] public " + storage + " Value;");
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(false, true)]
        [DataRow(true, false)]
        [DataRow(true, true)]
        public void RepeatedNativeFixedBuffersKeepOneDirectOwnerAndMemberSet(bool inferredStorage, bool inlineArray)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", inferredStorage ?
                TypedefProvider(fixture, "Dependency", "native-scalar", traversed: false) : "");
            fixture.Write("Other.header-types.cs", inferredStorage ?
                TypedefProvider(fixture, "Canonical", "native-scalar", traversed: true) : "");
            string storage = inferredStorage ? "SCALAR" : "int";
            string members = @"public Buffer Values;
public partial struct Buffer {
public STORAGE e0;
public STORAGE e1;
public unsafe ref STORAGE this[int index] {
get { fixed (STORAGE* values = &e0) { return ref values[index]; } }
}}".Replace("STORAGE", storage);
            if (inlineArray)
                members = members.Replace("Buffer", "Buffer_e__FixedBuffer");
            fixture.Write("Bindings.cs", RecordProvider(fixture, "Dependency", "native-record", traversed: false, size: 8)
                .Replace("public int Value;", members));
            fixture.Write("Other.cs", RecordProvider(fixture, "Canonical", "native-record", traversed: true, size: 8)
                .Replace("public int Value;", members));
            var compilation = fixture.Compile();
            var errors = compilation.CSharpCompilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())) +
                Environment.NewLine + string.Join(Environment.NewLine, compilation.CSharpCompilation.SyntaxTrees
                    .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(node => node.Identifier.ValueText == "NATIVE_RECORD").Select(node => node.ToFullString())));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            var buffer = record.GetTypeMembers(inlineArray ? "Buffer_e__FixedBuffer" : "Buffer").Single();
            Assert.AreEqual(1, buffer.DeclaringSyntaxReferences.Length);
            CollectionAssert.AreEqual(new[] { "e0", "e1" }, buffer.GetMembers().OfType<IFieldSymbol>()
                .Where(field => !field.IsImplicitlyDeclared).Select(field => field.Name).ToArray());
            Assert.AreEqual(1, buffer.GetMembers().OfType<IPropertySymbol>().Count(property => property.IsIndexer));
            Assert.IsTrue(NativeRecordSourceProvenance.Read((StructDeclarationSyntax)
                record.DeclaringSyntaxReferences.Single().GetSyntax())!.TraversedHeader);
            if (inferredStorage)
            {
                var scalar = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.SCALAR")!;
                Assert.AreEqual(1, scalar.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(NativeTypedefSourceProvenance.Read((StructDeclarationSyntax)
                    scalar.DeclaringSyntaxReferences.Single().GetSyntax())!.TraversedHeader);
            }
            string output = Path.Combine(fixture.DirectoryPath, "FixedBuffers.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            Assert.AreEqual(1, physical.GetFields().Count);
            if (inlineArray)
            {
                Assert.AreEqual(0, physical.GetNestedTypes().Count());
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(physical.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.Array, signature.ReadSignatureTypeCode());
                if (inferredStorage)
                {
                    Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                    var element = ResolveLocalType(reader, signature.ReadTypeHandle());
                    Assert.AreEqual("Canonical", reader.GetString(element.Namespace));
                    Assert.AreEqual("SCALAR", reader.GetString(element.Name));
                }
                else
                    Assert.AreEqual(SignatureTypeCode.Int32, signature.ReadSignatureTypeCode());
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(2, signature.ReadCompressedInteger());
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(0, signature.ReadCompressedSignedInteger());
                Assert.AreEqual(0, signature.RemainingBytes);
            }
            else
            {
                var nested = reader.GetTypeDefinition(physical.GetNestedTypes().Single());
                CollectionAssert.AreEqual(new[] { "e0", "e1" }, nested.GetFields()
                    .Select(handle => reader.GetString(reader.GetFieldDefinition(handle).Name)).ToArray());
            }
        }

        [DataTestMethod]
        [DataRow("identity")]
        [DataRow("source")]
        [DataRow("storage")]
        public void NativeTypedefProvidersRejectConflictingDeclarationsAndStorage(string conflict)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "First", "native-scalar", traversed: true));
            string other = TypedefProvider(fixture, "Second", conflict == "identity" ? "another-native-scalar" : "native-scalar",
                traversed: false, storage: conflict == "storage" ? "uint" : "int");
            if (conflict == "source")
                other = other.Replace(new string('A', 64), new string('B', 64));
            fixture.Write("Other.header-types.cs", other);
            var error = Assert.ThrowsException<InvalidDataException>(() =>
                fixture.Compile(new() { ["SCALAR"] = "Canonical" }));
            StringAssert.Contains(error.Message, "CSSW005");
        }

        [DataTestMethod]
        [DataRow("declaration")]
        [DataRow("mapped")]
        [DataRow("storage")]
        [DataRow("source")]
        [DataRow("unrouted-overlap")]
        [DataRow("same-family-inferred-owner")]
        public void ExplicitRetainedOwnersValidateNativeRedeclarationsAndMappedAliases(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", @"using Windows.Win32.Foundation.Metadata;
namespace Canonical { [NativeTypedef] public partial struct SCALAR { public int Value; } }");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture,
                scenario is "unrouted-overlap" or "same-family-inferred-owner" ? "Canonical" : "First",
                "first-scalar", traversed: true));
            string other = TypedefProvider(fixture, scenario == "unrouted-overlap" ? "Canonical" : "Second",
                scenario is "source" or "same-family-inferred-owner" ? "first-scalar" : "second-scalar",
                traversed: true, storage: scenario == "storage" ? "uint" : "int");
            if (scenario == "source")
                other = other.Replace(new string('A', 64), new string('B', 64));
            if (scenario == "mapped")
                other = other.Replace("\"NativeName\":\"native::SCALAR\"", "\"NativeName\":\"native::MAPPED\"");
            fixture.Write("Other.header-types.cs", other);
            var routes = new Dictionary<string, string>();
            if (scenario is not "unrouted-overlap" and not "same-family-inferred-owner")
                routes.Add("SCALAR", "Canonical");
            if (scenario is "storage" or "source" or "unrouted-overlap")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(routes)).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile(routes);
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var type = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.SCALAR")!;
            Assert.AreEqual(1, type.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_Int32, type.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
            string output = Path.Combine(fixture.DirectoryPath, "RetainedProjection.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Name) == "SCALAR");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                reader.GetBlobBytes(reader.GetFieldDefinition(physical.GetFields().Single()).Signature));
        }

        [DataTestMethod]
        [DataRow("output-only")]
        [DataRow("explicit-route")]
        [DataRow("close-api")]
        public void AutoTypeOutputPlacementDoesNotEstablishUnrelatedNativeOwnership(string scenario)
        {
            using var fixture = new Fixture("x64");
            bool closeApi = scenario == "close-api";
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "Native", "native-scalar", true,
                closeApi ? "global::System.IntPtr" : "byte", closeApi ? 8 : 1, closeApi ? 8 : 1));
            fixture.Write("Bindings.cs", @"using System.Runtime.InteropServices;
namespace Native { public struct CARRIER { public SCALAR Value; } }
namespace Retained { public static class Apis { [DllImport(""test"")] public static extern void Release(); } }");
            string autoTypes = Path.Combine(fixture.DirectoryPath, "autoTypes.json");
            File.WriteAllText(autoTypes, closeApi
                ? @"[{ ""Name"": ""SCALAR"", ""ValueType"": ""IntPtr"", ""NativeTypedef"": true, ""CloseApi"": ""Release"" }]"
                : @"[{ ""Namespace"": ""Retained"", ""Name"": ""SCALAR"", ""ValueType"": ""IntPtr"", ""NativeTypedef"": true }]");
            string output = Path.Combine(fixture.DirectoryPath, "AutoTypeOwnership.winmd");
            var arguments = new List<string>
            {
                "--sourceDir", fixture.DirectoryPath, "--arch", "x64", "--outputFileName", output,
                "--autoTypes", autoTypes,
            };
            if (scenario == "explicit-route")
                arguments.AddRange(new[] { "--requiredNamespaceForName", "SCALAR=Retained" });
            int exit = ClangSharpSourceToWinmd.Program.Main(arguments.ToArray());
            if (scenario == "explicit-route")
            {
                Assert.AreNotEqual(0, exit);
                Assert.IsFalse(File.Exists(output));
                StringAssert.Contains(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "generation-diagnostics.json")),
                    "Conflicting native typedef Value storage types");
                return;
            }
            Assert.AreEqual(0, exit);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var scalars = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type =>
                reader.GetString(type.Name) == "SCALAR").ToArray();
            Assert.AreEqual(closeApi ? 1 : 2, scalars.Length);
            var retained = scalars.Single(type => reader.GetString(type.Namespace) == "Retained");
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x18 },
                reader.GetBlobBytes(reader.GetFieldDefinition(retained.GetFields().Single()).Signature));
            if (!closeApi)
            {
                var native = scalars.Single(type => reader.GetString(type.Namespace) == "Native");
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x05 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(native.GetFields().Single()).Signature));
            }
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Native" && reader.GetString(type.Name) == "CARRIER");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature);
            Assert.AreEqual((byte)0x06, signature.ReadByte());
            Assert.AreEqual((byte)0x11, signature.ReadByte());
            var binding = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual(closeApi ? "Retained" : "Native", reader.GetString(binding.Namespace));
            Assert.AreEqual("SCALAR", reader.GetString(binding.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("complete")]
        [DataRow("nested-buffer")]
        [DataRow("retained-enum")]
        [DataRow("retained-enum-native-integer")]
        [DataRow("missing-target")]
        [DataRow("different-binding")]
        [DataRow("unknown-observation")]
        public void CommonNativeDependenciesUseCompleteCanonicalArchitectureProviders(string scenario)
        {
            using var fixture = new Fixture("crossarch");
            bool retainedEnum = scenario is "retained-enum" or "retained-enum-native-integer";
            bool nativeInteger = scenario == "retained-enum-native-integer";
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", "");
            if (retainedEnum)
            {
                fixture.Write("Bindings.header-types.cs",
                    TypedefProvider(fixture, "Retained", "scalar", true, "uint"));
                fixture.Write("Values.enums.cs",
                    "namespace Retained { public enum SCALAR : uint { First = 1 } }");
            }
            if (nativeInteger)
                fixture.Write("autotypes.cs", @"using System; using Windows.Win32.Foundation.Metadata;
namespace Retained { [NativeTypedef] public struct NATIVE_SIZE { public UIntPtr Value; } }");
            foreach (var target in new[] { ("x86", Architecture.X86, 1), ("x64", Architecture.X64, 2),
                ("arm64", Architecture.Arm64, 3) })
            {
                if (scenario == "missing-target" && target.Item2 == Architecture.Arm64)
                    continue;
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Item1, "Bindings.cs"),
                    Provider("Owner", true, target.Item2, target.Item3));
                if (nativeInteger)
                    File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Item1, "Size.header-types.cs"),
                        TypedefProvider(fixture, "Retained", "native-size", true,
                            target.Item2 == Architecture.X86 ? "uint" : "ulong",
                            target.Item2 == Architecture.X86 ? 4 : 8, target.Item2 == Architecture.X86 ? 4 : 8)
                            .Replace("SCALAR", "NATIVE_SIZE", StringComparison.Ordinal));
            }
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Dependency.cs"),
                Provider("Observer", false, scenario == "unknown-observation" ? null : Architecture.X86, 1,
                    scenario == "different-binding" ? "uint" : "int") + @"
namespace Observer { public static unsafe partial class Apis {
    [DllImport(""test"")] public static extern NATIVE_RECORD* UseNativeRecord(NATIVE_RECORD* value);
} }");
            if (scenario is not ("complete" or "nested-buffer" or "retained-enum" or "retained-enum-native-integer"))
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile(retainedEnum
                ? new() { ["SCALAR"] = "Retained", ["NATIVE_SIZE"] = "Retained" } : null);
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.IsFalse(compilation.CSharpCompilation.SyntaxTrees.Where(tree =>
                    Path.GetFileName(tree.FilePath) == "Dependency.modified.cs")
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Any(record => record.Identifier.ValueText == "NATIVE_RECORD"));
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalArchitectureRecords.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type =>
                reader.GetString(type.Name) == "NATIVE_RECORD").ToArray();
            Assert.AreEqual(3, records.Length);
            int coverage = 0;
            foreach (var record in records)
            {
                Assert.AreEqual("Owner", reader.GetString(record.Namespace));
                var attribute = record.GetCustomAttributes().Single(handle =>
                    AttributeName(reader, handle) == "SupportedArchitectureAttribute");
                var blob = reader.GetBlobReader(reader.GetCustomAttribute(attribute).Value);
                Assert.AreEqual((ushort)1, blob.ReadUInt16());
                int mask = blob.ReadInt32();
                Assert.AreEqual(0, coverage & mask);
                coverage |= mask;
                Assert.AreEqual(mask == 1 ? 1 : mask == 2 ? 2 : 3, record.GetFields().Count);
                foreach (var field in record.GetFields())
                {
                    var definition = reader.GetFieldDefinition(field);
                    var bytes = reader.GetBlobBytes(definition.Signature);
                    if (retainedEnum ||
                        scenario == "nested-buffer" && reader.GetString(definition.Name) == "Value")
                        CollectionAssert.AreEqual(new byte[] { 0x06, 0x11 }, bytes.Take(2).ToArray());
                    else
                        CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 }, bytes);
                }
            }
            Assert.AreEqual(7, coverage);
            if (nativeInteger)
            {
                int integerCoverage = 0;
                foreach (var nativeSize in reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type =>
                    reader.GetString(type.Namespace) == "Retained" && reader.GetString(type.Name) == "NATIVE_SIZE"))
                {
                    int mask = 7;
                    foreach (var attribute in nativeSize.GetCustomAttributes().Where(handle =>
                        AttributeName(reader, handle) == "SupportedArchitectureAttribute"))
                    {
                        var blob = reader.GetBlobReader(reader.GetCustomAttribute(attribute).Value);
                        Assert.AreEqual((ushort)1, blob.ReadUInt16());
                        mask = blob.ReadInt32();
                    }
                    Assert.AreEqual(0, integerCoverage & mask);
                    integerCoverage |= mask;
                    CollectionAssert.AreEqual(new byte[] { 0x06, 0x19 },
                        reader.GetBlobBytes(reader.GetFieldDefinition(nativeSize.GetFields().Single()).Signature));
                }
                Assert.AreEqual(7, integerCoverage);
            }
            var apis = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Observer" && reader.GetString(type.Name) == "Apis");
            var method = apis.GetMethods().Select(reader.GetMethodDefinition).Single(method =>
                reader.GetString(method.Name) == "UseNativeRecord");
            var signature = reader.GetBlobReader(method.Signature);
            Assert.AreEqual((byte)0, signature.ReadByte());
            Assert.AreEqual(1, signature.ReadCompressedInteger());
            for (int i = 0; i < 2; i++)
            {
                Assert.AreEqual((byte)0x0f, signature.ReadByte());
                Assert.AreEqual((byte)0x11, signature.ReadByte());
                var handle = signature.ReadTypeHandle();
                if (handle.Kind == HandleKind.TypeDefinition)
                {
                    var definition = reader.GetTypeDefinition((TypeDefinitionHandle)handle);
                    Assert.AreEqual("Owner", reader.GetString(definition.Namespace));
                    Assert.AreEqual("NATIVE_RECORD", reader.GetString(definition.Name));
                }
                else
                {
                    Assert.AreEqual(HandleKind.TypeReference, handle.Kind);
                    var reference = reader.GetTypeReference((TypeReferenceHandle)handle);
                    Assert.AreEqual(HandleKind.ModuleDefinition, reference.ResolutionScope.Kind);
                    Assert.AreEqual("Owner", reader.GetString(reference.Namespace));
                    Assert.AreEqual("NATIVE_RECORD", reader.GetString(reference.Name));
                }
            }
            Assert.AreEqual(0, signature.RemainingBytes);

            string Provider(string ns, bool direct, Architecture? observed, int fields, string storage = "int")
            {
                if (retainedEnum)
                    storage = "global::Retained.SCALAR";
                string text = "using System.Runtime.InteropServices;\n" +
                    RecordProvider(fixture, ns, "conditional-native-record", direct, storage, fields * 4,
                        line: (uint)fields);
                for (int i = 1; i < fields; i++)
                    text = text.Replace("public " + storage + " Value;", "public " + storage +
                        " Extra" + i + "; public " + storage + " Value;");
                if (scenario == "nested-buffer")
                    text = text.Replace("public int Value;", @"public STORAGE Value;
    public partial struct STORAGE {
        public int e0;
        public unsafe ref int this[int index] { get {
            fixed (int* pThis = &e0) { return ref pThis[index]; }
        } }
    }");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var record = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Single(record => record.Identifier.ValueText == "NATIVE_RECORD");
                var proof = NativeRecordSourceProvenance.Read(record)! with { SourceArchitecture = observed };
                return root.ReplaceNode(record, NativeRecordSourceProvenance.Attach(
                    record.WithTrailingTrivia(default(SyntaxTriviaList)), proof)).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow("complete")]
        [DataRow("projected-sibling")]
        [DataRow("missing-target")]
        [DataRow("different-binding")]
        [DataRow("unknown-observation")]
        [DataRow("different-field-attribute")]
        [DataRow("different-abi")]
        [DataRow("different-identity")]
        public void CommonNativeTypedefDependenciesUseTheirObservedCanonicalTarget(string scenario)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            if (scenario == "projected-sibling")
            {
                fixture.Write("Values.enums.cs", "namespace Retained { public enum PROJECTED : uint { First = 1 } }");
                fixture.Write("Use.cs", "namespace Retained { public struct USER { public PROJECTED Value; } }");
            }
            foreach (var target in new[] { ("x86", Architecture.X86), ("x64", Architecture.X64),
                ("arm64", Architecture.Arm64) })
            {
                if (scenario == "missing-target" && target.Item2 == Architecture.Arm64)
                    continue;
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Item1, "Owner.header-types.cs"),
                    Provider("Owner", true, target.Item2, target.Item2 == Architecture.X86 ? "ulong" : "void*"));
            }
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Dependency.header-types.cs"),
                Provider("Observer", false, scenario == "unknown-observation" ? null : Architecture.X86,
                    scenario == "different-binding" ? "long" : "ulong"));
            File.WriteAllText(Path.Combine(common, "Dependency.cs"), @"
using System.Runtime.InteropServices;
namespace Observer { public static partial class Apis {
    [DllImport(""test"")] public static extern SCALAR UseNativeAlias(SCALAR value);
} }");
            bool unrelated = scenario == "different-identity";
            if (scenario is not ("complete" or "projected-sibling") && !unrelated)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(unrelated, compilation.CSharpCompilation.SyntaxTrees.Where(tree =>
                    Path.GetFileName(tree.FilePath) == "Dependency.header-types.modified.cs")
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Any(declaration => declaration.Identifier.ValueText == "SCALAR"));
            string output = Path.Combine(fixture.DirectoryPath, "ObservedNativeAlias.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            int coverage = 0;
            var allAliases = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "SCALAR").ToArray();
            Assert.AreEqual(unrelated ? 3 : 2, allAliases.Length);
            if (unrelated)
            {
                var observer = allAliases.Single(type => reader.GetString(type.Namespace) == "Observer");
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x0b },
                    reader.GetBlobBytes(reader.GetFieldDefinition(observer.GetFields().Single()).Signature));
            }
            var aliases = allAliases.Where(type => reader.GetString(type.Namespace) == "Owner").ToArray();
            Assert.AreEqual(2, aliases.Length);
            foreach (var alias in aliases)
            {
                Assert.AreEqual("Owner", reader.GetString(alias.Namespace));
                var attribute = alias.GetCustomAttributes().Single(handle =>
                    AttributeName(reader, handle) == "SupportedArchitectureAttribute");
                var blob = reader.GetBlobReader(reader.GetCustomAttribute(attribute).Value);
                Assert.AreEqual((ushort)1, blob.ReadUInt16());
                int mask = blob.ReadInt32();
                Assert.AreEqual(0, coverage & mask);
                coverage |= mask;
                CollectionAssert.AreEqual(mask == 1 ? new byte[] { 0x06, 0x0b } : new byte[] { 0x06, 0x0f, 0x01 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(alias.GetFields().Single()).Signature));
            }
            Assert.AreEqual(7, coverage);
            foreach (var reference in reader.TypeReferences.Select(reader.GetTypeReference).Where(reference =>
                reader.GetString(reference.Name) == "SCALAR"))
            {
                Assert.AreEqual(HandleKind.ModuleDefinition, reference.ResolutionScope.Kind);
                Assert.AreEqual(unrelated ? "Observer" : "Owner", reader.GetString(reference.Namespace));
            }

            string Provider(string ns, bool direct, Architecture? observed, string storage)
            {
                string text = TypedefProvider(fixture, ns,
                    !direct && scenario == "different-identity" ? "other-native-alias" : "fixed-pointer-alias",
                    direct, storage, !direct && scenario == "different-abi" ? 4 : 8, 8)
                    .Replace("public partial struct", "public unsafe partial struct")
                    .Replace("public " + storage + " Value;", "[NativeTypeName(\"void * __ptr64\")] public " + storage + " Value;");
                if (!direct && scenario == "different-field-attribute")
                    text = text.Replace("[NativeTypeName(", "[Const] [NativeTypeName(");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var proof = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = observed };
                text = root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), proof)).ToFullString();
                return direct && scenario == "projected-sibling"
                    ? text + TypedefProvider(fixture, "Retained", "projected-enum", true, "uint")
                        .Replace("SCALAR", "PROJECTED", StringComparison.Ordinal)
                        .Replace("using Windows.Win32.Foundation.Metadata;", "", StringComparison.Ordinal)
                    : text;
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void CommonNativeAliasConstraintsRemainForFullFamilyComposition(bool alternateNativeSpelling)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            foreach (var target in new[] { ("x86", Architecture.X86), ("x64", Architecture.X64),
                ("arm64", Architecture.Arm64) })
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Item1, "Owner.header-types.cs"),
                    TypedefProvider(fixture, "Owner", "native-base", true, "uint")
                        .Replace("SCALAR", "BASE", StringComparison.Ordinal) +
                    Provider("Owner", true, target.Item2, "global::Owner.BASE", "BASE")
                        .Replace("using Windows.Win32.Foundation.Metadata;", "", StringComparison.Ordinal));
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Dependency.header-types.cs"),
                Provider("Observer", false, Architecture.X86, "uint", alternateNativeSpelling ? "unsigned int" : "BASE"));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "FullFamilyNativeAlias.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var alias = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Owner" && reader.GetString(type.Name) == "SCALAR");
            var blob = reader.GetBlobReader(reader.GetFieldDefinition(alias.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, blob.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, blob.ReadSignatureTypeCode());
            var storage = ResolveLocalType(reader, blob.ReadTypeHandle());
            Assert.AreEqual("BASE", reader.GetString(storage.Name));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x09 },
                reader.GetBlobBytes(reader.GetFieldDefinition(storage.GetFields().Single()).Signature));

            string Provider(string ns, bool direct, Architecture observed, string storage, string nativeSpelling)
            {
                string text = TypedefProvider(fixture, ns, "native-alias", direct, storage)
                    .Replace("public " + storage + " Value;", "[NativeTypeName(\"" + nativeSpelling +
                        "\")] public " + storage + " Value;");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var proof = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = observed };
                return root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), proof)).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(true, false)]
        [DataRow(true, true)]
        public void NativeObservationArchitectureIsSeparateFromCommonSourceApplicability(bool observedTarget,
            bool sameTarget)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            string directory = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(directory);
            File.WriteAllText(Path.Combine(directory, "Common.header-types.cs"),
                Provider(10, observedTarget ? Architecture.X86 : null));
            foreach (var target in new[] { ("x86", Architecture.X86, 10U),
                ("x64", Architecture.X64, 20U), ("arm64", Architecture.Arm64, 30U) })
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target.Item1, "Bindings.header-types.cs"),
                    Provider(target.Item3, sameTarget ? Architecture.X86 : target.Item2));
            if (!observedTarget || sameTarget)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message,
                    "Conflicting native record identities");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var scalar = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.SCALAR")!;
            Assert.AreEqual(1, scalar.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_IntPtr, scalar.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);

            string Provider(uint line, Architecture? architecture)
            {
                string text = TypedefProvider(fixture, "Canonical", "native-scalar", traversed: true,
                    storage: "global::System.IntPtr",
                    size: architecture is Architecture.X64 or Architecture.Arm64 ? 8 : 4,
                    alignment: architecture is Architecture.X64 or Architecture.Arm64 ? 8 : 4, line: line);
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var proof = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = architecture };
                var stamped = NativeTypedefSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), proof);
                Assert.AreEqual(architecture, NativeTypedefSourceProvenance.Read(stamped)!.SourceArchitecture);
                return root.ReplaceNode(declaration, stamped).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow(0)]
        [DataRow(7)]
        [DataRow(8)]
        public void NativeSourceProofRejectsInvalidObservedArchitecture(int mask)
        {
            using var fixture = new Fixture("x64");
            string text = TypedefProvider(fixture, "First", "native-scalar", traversed: true);
            var declaration = CSharpSyntaxTree.ParseText(text).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Single();
            var source = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = (Architecture)mask };
            Assert.ThrowsException<InvalidDataException>(() => NativeTypedefSourceProvenance.Attach(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source));
        }

        [DataTestMethod]
        [DataRow("version")]
        [DataRow("duplicate")]
        [DataRow("name")]
        [DataRow("namespace")]
        [DataRow("mixed")]
        public void NativeTypedefProvidersRejectMalformedOrConflictingSourceProof(string invalid)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            string source = TypedefProvider(fixture, "First", "native-scalar", traversed: true);
            if (invalid == "mixed")
            {
                var root = CSharpSyntaxTree.ParseText(source).GetCompilationUnitRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var stamped = NativeRecordSourceProvenance.Attach(declaration,
                    NativeTypedefSourceProvenance.Read(declaration)!);
                source = root.ReplaceNode(declaration, stamped.WithTrailingTrivia(stamped.GetTrailingTrivia()
                    .Where(trivia => trivia.IsKind(SyntaxKind.MultiLineCommentTrivia)))).ToFullString();
            }
            else if (invalid == "duplicate")
            {
                int start = source.IndexOf("/* Win32Metadata.NativeTypedefSource.", StringComparison.Ordinal);
                int end = source.IndexOf(" */", start, StringComparison.Ordinal) + 3;
                string proof = source.Substring(start, end - start);
                source = source.Replace(proof, proof + proof);
            }
            else
                source = invalid switch
                {
                    "version" => source.Replace("NativeTypedefSource.v1 ", "NativeTypedefSource.v2 "),
                    "name" => source.Replace("\"Name\":\"SCALAR\"", "\"Name\":\"OTHER\""),
                    "namespace" => source.Replace("\"Namespace\":\"First\"", "\"Namespace\":\"Other\""),
                    _ => throw new InvalidOperationException(invalid),
                };
            fixture.Write("Bindings.header-types.cs", source);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CSSW005");
        }

        [TestMethod]
        public void NativeRecordProvidersDoNotDiscardDistinctNominalTypedefBindings()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "First", "first-scalar", traversed: true));
            fixture.Write("Other.header-types.cs", TypedefProvider(fixture, "Second", "second-scalar", traversed: true));
            fixture.Write("Bindings.cs", RecordProvider(fixture, "First", "native-record", traversed: false, storage: "SCALAR"));
            fixture.Write("Other.cs", RecordProvider(fixture, "Second", "native-record", traversed: true, storage: "SCALAR"));
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Second.NATIVE_RECORD")!;
            Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("First.SCALAR"));
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Second.SCALAR"));
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
        }

        [TestMethod]
        public void UnmovedConsumersKeepRelocatedNativeAliasBindingsAndNestedTypePrecedence()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "Original", "native-scalar", traversed: false));
            fixture.Write("Owner.header-types.cs", TypedefProvider(fixture, "Canonical", "native-scalar", traversed: true));
            fixture.Write("Foreign.header-types.cs", TypedefProvider(fixture, "Foreign", "foreign-scalar", traversed: true,
                storage: "uint"));
            fixture.Write("Bindings.cs", @"
using Canonical;
using Foreign;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace Original {
public static partial class Apis {
[NativeTypeName(""SCALAR"")] public const SCALAR Value = (SCALAR)5;
[DllImport(""native.dll"")] public static extern SCALAR Echo(SCALAR value);
}
public partial struct Holder { public SCALAR Value; }
public partial struct Nested {
public partial struct SCALAR { public short Value; }
public SCALAR Value;
}
}");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var owner = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.SCALAR")!;
            var apis = compilation.CSharpCompilation.GetTypeByMetadataName("Original.Apis")!;
            var method = apis.GetMembers("Echo").OfType<IMethodSymbol>().Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(owner, method.ReturnType));
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(owner, method.Parameters.Single().Type));
            var holder = compilation.CSharpCompilation.GetTypeByMetadataName("Original.Holder")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(owner, holder.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            Assert.AreEqual(5, apis.GetMembers("Value").OfType<IFieldSymbol>().Single().ConstantValue);
            var nested = compilation.CSharpCompilation.GetTypeByMetadataName("Original.Nested")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(nested.GetTypeMembers("SCALAR").Single(),
                nested.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            string output = Path.Combine(fixture.DirectoryPath, "UnmovedConsumers.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Name) == "Holder");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(physical.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var scalar = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Canonical", reader.GetString(scalar.Namespace));
            Assert.AreEqual("SCALAR", reader.GetString(scalar.Name));
        }

        [TestMethod]
        public void ConstantQualificationReportsCompilerErrorsOnTheDeclaredType()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "First", "first-scalar", traversed: true));
            fixture.Write("Other.header-types.cs", TypedefProvider(fixture, "Second", "second-scalar", traversed: true));
            fixture.Write("Bindings.cs", @"using First; using Second;
using Windows.Win32.Foundation.Metadata;
namespace Consumer { public static partial class Apis {
[NativeTypeName(""SCALAR"")] public const SCALAR Value = 5;
} }");
            var error = Assert.ThrowsException<InvalidOperationException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CS0104");
            StringAssert.Contains(error.Message, "emitter.constant-binding");
            StringAssert.Contains(error.Message, "architecture: X86");
            Assert.IsFalse(File.Exists(Path.Combine(fixture.DirectoryPath, "Windows.Win32.winmd")));
        }

        [DataTestMethod]
        [DataRow(true, false, false)]
        [DataRow(false, false, false)]
        [DataRow(true, true, false)]
        [DataRow(true, false, true)]
        public void AlternateNativeDefinitionsKeepCanonicalDeclaredFieldTypes(bool alternateHeaders, bool signedStorage,
            bool commonOwner)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "ZCanonical", "canonical-word",
                traversed: true, storage: "uint").Replace("SCALAR", "CANON_WORD")
                .Replace("public uint Value;", "[NativeTypeName(\"unsigned int\")] public uint Value;"));
            fixture.Write("Other.header-types.cs", TypedefProvider(fixture, "AObserver", "observed-word",
                traversed: true, storage: signedStorage ? "int" : "uint").Replace("SCALAR", "OBS_WORD")
                .Replace("public uint Value;", "[NativeTypeName(\"unsigned int\")] public uint Value;"));
            string canonical = Provider("ZCanonical", true, "CANON_WORD");
            fixture.Write("Bindings.cs", commonOwner ? "" : canonical);
            fixture.Write("Other.cs", commonOwner ? "" : Provider("AObserver", false, "OBS_WORD"));
            if (commonOwner)
            {
                string common = Path.Combine(fixture.DirectoryPath, "common");
                Directory.CreateDirectory(common);
                File.WriteAllText(Path.Combine(common, "Canonical.cs"), canonical);
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "arm64", "Other.cs"),
                    Provider("AObserver", false, "OBS_WORD"));
            }
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("ZCanonical.NATIVE_RECORD")!;
            if (!alternateHeaders || signedStorage)
            {
                Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
                return;
            }
            var diagnostics = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, diagnostics.Length, string.Join(Environment.NewLine, diagnostics.Select(diagnostic => diagnostic.ToString())));
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual("ZCanonical.CANON_WORD", record.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.ToDisplayString());
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("AObserver.OBS_WORD"));
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalFieldTypes.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Name) == "NATIVE_RECORD");
            Assert.AreEqual("ZCanonical", reader.GetString(physical.Namespace));
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(physical.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var declared = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("ZCanonical", reader.GetString(declared.Namespace));
            Assert.AreEqual("CANON_WORD", reader.GetString(declared.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
            Assert.AreEqual(1, reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Count(definition => reader.GetString(definition.Name) == "OBS_WORD"));

            string Provider(string ns, bool direct, string storage)
            {
                string text = RecordProvider(fixture, ns, "same-native-record", direct, storage);
                if (!alternateHeaders || direct)
                    return text;
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeRecordSourceProvenance.Read(declaration)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath, "alternate.h"),
                    HeaderHash = new string('B', 64),
                };
                return root.ReplaceNode(declaration, NativeRecordSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source)).ToFullString();
            }
        }

        [TestMethod]
        public void NativeRecordProvidersBindQualifiedAndImportedDependencyTypes()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Dependencies.cs", "namespace Support { public struct CLOCK { public int Ticks; } }");
            fixture.Write("Bindings.cs", RecordProvider(fixture, "Dependency", "native-record",
                traversed: false, storage: "global::Support.CLOCK"));
            fixture.Write("Other.cs", "using Support;\n" + RecordProvider(fixture, "Canonical", "native-record",
                traversed: true, storage: "CLOCK"));
            var compilation = fixture.Compile();
            var errors = compilation.CSharpCompilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual("Support.CLOCK", record.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.ToDisplayString());
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void RepeatedNativeFixedBufferHelpersBindQualifiedLocalTypes(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Dependencies.cs", "namespace Support { public struct CLOCK { public int Ticks; } }");
            string Members(string type) => "public Buffer Value; public partial struct Buffer {" +
                "public " + type + " e0; public unsafe ref " + type + " this[int index] {" +
                "get { fixed (" + type + "* p = &e0) { return ref p[index]; } } }}";
            fixture.Write("Bindings.cs", "using Support;\n" + RecordProvider(fixture, "Dependency", "native-record",
                traversed: false).Replace("public int Value;", Members("CLOCK")));
            fixture.Write("Other.cs", RecordProvider(fixture, "Canonical", "native-record", traversed: true)
                .Replace("public int Value;", Members("global::Support.CLOCK")));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual("Support.CLOCK", record.GetTypeMembers("Buffer").Single()
                .GetMembers("e0").OfType<IFieldSymbol>().Single().Type.ToDisplayString());
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalLocalBuffer.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Canonical" && reader.GetString(type.Name) == "NATIVE_RECORD");
            var buffer = reader.GetTypeDefinition(physical.GetNestedTypes().Single());
            Assert.AreEqual(1, physical.GetFields().Count);
            Assert.AreEqual(1, buffer.GetFields().Count);
            Assert.AreEqual(0, buffer.GetMethods().Count);
        }

        [DataTestMethod]
        [DataRow("CHAR", "sbyte", "char", 1, SignatureTypeCode.SByte, SignatureTypeCode.TypeHandle)]
        [DataRow("WCHAR", "ushort", "wchar_t", 2, SignatureTypeCode.UInt16, SignatureTypeCode.Char)]
        public void NativeTypedefValueStorageDoesNotReapplyPublicCharacterProjection(string name, string storage,
            string nativeType, int size, SignatureTypeCode storageCode, SignatureTypeCode publicCode)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            string field = "public " + storage + " Value;";
            string nativeField = "[NativeTypeName(\"" + nativeType + "\")] " + field;
            string source = TypedefProvider(fixture, "Canonical", "native-character", traversed: true,
                storage: storage, size: size, alignment: size).Replace("SCALAR", name);
            StringAssert.Contains(source, field);
            fixture.Write("Bindings.header-types.cs", source.Replace(field, nativeField));
            fixture.Write("Bindings.cs", "using Windows.Win32.Foundation.Metadata; namespace Canonical {" +
                "public partial struct Holder { " + nativeField + " }" +
                "[NativeTypedef] public partial struct LEGACY { " + nativeField + " }}");
            var compilation = fixture.Compile();
            var errors = compilation.CSharpCompilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "CharacterStorage.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (string typeName in new[] { name, "Holder", "LEGACY" })
            {
                var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Name) == typeName);
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(type.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                var expected = typeName == name ? storageCode : publicCode;
                Assert.AreEqual(expected, signature.ReadSignatureTypeCode(), typeName);
                if (expected == SignatureTypeCode.TypeHandle)
                {
                    var target = ResolveLocalType(reader, signature.ReadTypeHandle());
                    Assert.AreEqual("Canonical", reader.GetString(target.Namespace));
                    Assert.AreEqual(name, reader.GetString(target.Name));
                }
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        private static TypeDefinition ResolveLocalType(MetadataReader reader, EntityHandle handle)
        {
            if (handle.Kind == HandleKind.TypeDefinition)
                return reader.GetTypeDefinition((TypeDefinitionHandle)handle);
            Assert.AreEqual(HandleKind.TypeReference, handle.Kind);
            var reference = reader.GetTypeReference((TypeReferenceHandle)handle);
            Assert.AreEqual(HandleKind.ModuleDefinition, reference.ResolutionScope.Kind);
            return reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == reader.GetString(reference.Namespace) &&
                reader.GetString(type.Name) == reader.GetString(reference.Name));
        }

        [DataTestMethod]
        [DataRow("configured")]
        [DataRow("unmarked")]
        [DataRow("inferred")]
        [DataRow("conflicting-storage")]
        [DataRow("conflicting-source")]
        [DataRow("binding-source-drift")]
        [DataRow("ambiguous-target")]
        [DataRow("distinct-family")]
        public void ConfiguredNativeNominalTargetsRequireSourceBoundIntentAndCompatibleStorage(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", @"using Windows.Win32.Foundation.Metadata;
namespace Retained { [NativeTypedef] public partial struct SCALAR { public int Value; } }" +
                (scenario == "ambiguous-target" ? @"
namespace OtherRetained { [NativeTypedef] public partial struct SCALAR { public int Value; } }" : ""));
            fixture.Write("Bindings.header-types.cs", Provider("Native", "native-scalar",
                scenario == "conflicting-storage" ? "uint" : "int", scenario is not "unmarked" and not "inferred"));
            fixture.Write("Bindings.cs", @"namespace Native { public struct CARRIER { public SCALAR Value; } }");
            if (scenario == "conflicting-source")
                fixture.Write("Other.header-types.cs", Provider("OtherNative", "native-scalar", "int", true)
                    .Replace(new string('A', 64), new string('B', 64)));
            if (scenario == "distinct-family")
            {
                fixture.Write("Other.header-types.cs", Provider("OtherNative", "other-scalar", "int", false));
                fixture.Write("Other.cs", @"namespace OtherNative { public struct OTHER_CARRIER { public SCALAR Value; } }");
            }
            if (scenario is "conflicting-storage" or "conflicting-source" or "binding-source-drift" or "ambiguous-target")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "ConfiguredNominal.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var scalars = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "SCALAR").ToArray();
            Assert.AreEqual(scenario is "unmarked" or "distinct-family" ? 2 : 1, scalars.Length);
            foreach (var type in scalars)
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(type.GetFields().Single()).Signature));
            AssertCarrier("Native", "CARRIER", scenario == "unmarked" ? "Native" : "Retained",
                intrinsic: scenario == "inferred");
            if (scenario == "distinct-family")
                AssertCarrier("OtherNative", "OTHER_CARRIER", "OtherNative", intrinsic: false);

            string Provider(string ns, string identity, string storage, bool configured)
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, ns, identity, true, storage)).GetCompilationUnitRoot();
                var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var declaration = NativeTypedefProjectionProvenance.WithPolicy(original, scenario == "inferred");
                if (configured)
                    declaration = NativeTypedefProjectionProvenance.WithConfiguredNominalBinding(declaration);
                if (scenario == "binding-source-drift")
                    declaration = declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Select(trivia =>
                        trivia.ToString().StartsWith("/* Win32Metadata.NativeTypedefBinding.", StringComparison.Ordinal)
                            ? SyntaxFactory.Comment(trivia.ToString().Replace(new string('A', 64), new string('B', 64)))
                            : trivia));
                return root.ReplaceNode(original, declaration).ToFullString();
            }

            void AssertCarrier(string ns, string name, string expectedOwner, bool intrinsic)
            {
                var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == name);
                var field = reader.GetFieldDefinition(carrier.GetFields().Single());
                if (intrinsic)
                {
                    CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 }, reader.GetBlobBytes(field.Signature));
                    return;
                }
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual((byte)0x06, signature.ReadByte());
                Assert.AreEqual((byte)0x11, signature.ReadByte());
                var binding = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual(expectedOwner, reader.GetString(binding.Namespace));
                Assert.AreEqual("SCALAR", reader.GetString(binding.Name));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        private static string TypedefProvider(Fixture fixture, string ns, string identity, bool traversed, string storage = "int",
            long size = 4, long alignment = 4, uint line = 1)
        {
            var root = CSharpSyntaxTree.ParseText("using Windows.Win32.Foundation.Metadata; namespace " + ns +
                " { [NativeTypedef] public partial struct SCALAR { public " + storage + " Value; } }").GetCompilationUnitRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var source = new NativeRecordSource(identity, "native::SCALAR", Path.Combine(fixture.DirectoryPath, "native.h"),
                new string('A', 64), line, 1, "SCALAR", ns, traversed, size, alignment);
            return root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(declaration, source)).ToFullString();
        }

        [TestMethod]
        public void NativeBindingCanonicalViewsStayWithinTheirFamilyAndCompilation()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            var compilation = fixture.Compile().CSharpCompilation;
            var copies = Enumerable.Range(0, 6).Select(index =>
            {
                string text = RecordProvider(fixture, "Test", "native-record", index == 0,
                    storage: index == 5 ? "short" : "int");
                string mask = index is 3 or 4 ? "X86" : "All";
                text = text.Replace("public partial struct", "[global::Windows.Win32.Foundation.Metadata.SupportedArchitecture(" +
                    "global::Windows.Win32.Foundation.Metadata.Architecture." + mask + ")] public partial struct");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                if (index == 4)
                {
                    var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                    var source = NativeRecordSourceProvenance.Read(declaration)! with
                    {
                        Header = Path.Combine(fixture.DirectoryPath, "alternate.h"),
                    };
                    root = root.ReplaceNode(declaration, NativeRecordSourceProvenance.Attach(
                        declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source));
                }
                return CSharpSyntaxTree.Create((CSharpSyntaxNode)root, path: Path.Combine(fixture.DirectoryPath, $"Provider{index}.cs"));
            }).Select(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>().Single()).ToArray();
            compilation = compilation.AddSyntaxTrees(copies.Select(declaration => declaration.SyntaxTree));
            const System.Reflection.BindingFlags flags = System.Reflection.BindingFlags.NonPublic | System.Reflection.BindingFlags.Static;
            var contextType = typeof(ClangSharpSourceCompilation).GetNestedType("NativeBindingComparison",
                System.Reflection.BindingFlags.NonPublic)!;
            var constructor = contextType.GetConstructor(new[] { typeof(CSharpCompilation), typeof(IReadOnlyList<StructDeclarationSyntax>) })!;
            var compare = typeof(ClangSharpSourceCompilation).GetMethod("NativeBindingsMatch", flags)!;
            object Context(CSharpCompilation source) => constructor.Invoke(new object[] { source, copies });
            System.Collections.IDictionary Views(object context) =>
                (System.Collections.IDictionary)contextType.GetProperty("CanonicalViews")!.GetValue(context)!;
            bool Match(object context, int first, int second) =>
                (bool)compare.Invoke(null, new object[] { context, copies[first], copies[second] })!;
            object Model(object context)
            {
                object view = Views(context).Values.Cast<object>().Single();
                return view.GetType().GetField("Item2")!.GetValue(view)!;
            }
            object context = Context(compilation);
            Assert.IsTrue(Match(context, 0, 1));
            object model = Model(context);
            Assert.IsTrue(Match(context, 0, 2));
            Assert.AreEqual(1, Views(context).Count);
            Assert.AreSame(model, Model(context));
            Assert.IsFalse(Match(context, 0, 3));
            Assert.AreEqual(1, Views(context).Count);
            Assert.IsTrue(Match(context, 0, 4));
            Assert.AreEqual(2, Views(context).Count);
            Assert.IsFalse(Match(context, 0, 5));
            Assert.AreEqual(2, Views(context).Count);
            Assert.IsTrue(Match(context, 1, 2));
            Assert.AreEqual(3, Views(context).Count);
            var metadataTree = compilation.SyntaxTrees.Single(tree => tree.GetRoot().DescendantNodes()
                .OfType<ClassDeclarationSyntax>().Any(type => type.Identifier.ValueText == "SupportedArchitectureAttribute"));
            var replacement = metadataTree.WithRootAndOptions(
                metadataTree.GetRoot().WithLeadingTrivia(SyntaxFactory.Comment("// replacement compilation")), metadataTree.Options);
            object replaced = Context(compilation.ReplaceSyntaxTree(metadataTree, replacement));
            Assert.AreEqual(0, Views(replaced).Count);
            Assert.IsTrue(Match(replaced, 0, 1));
            Assert.AreNotSame(model, Model(replaced));
        }

        [TestMethod]
        public void UnrelatedNativeRecordsWithTheSameGlobalUsrKeepTheirPhysicalHeaderOwners()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            foreach (var item in new[] { (Namespace: "First", Guid: "13741d21-87eb-11ce-8081-0080c758527e"),
                (Namespace: "Second", Guid: "56a868ac-0ad4-11ce-b03a-0020af0ba770") })
            {
                string text = RecordProvider(fixture, item.Namespace, "c:@S@NATIVE_RECORD", true)
                    .Replace("public partial struct", "[global::System.Runtime.InteropServices.Guid(\"" + item.Guid +
                        "\")] public partial struct");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeRecordSourceProvenance.Read(declaration)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath, item.Namespace + ".h"),
                    HeaderHash = new string(item.Namespace == "First" ? 'A' : 'B', 64),
                };
                fixture.Write(item.Namespace + ".cs", root.ReplaceNode(declaration, NativeRecordSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source)).ToFullString());
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            foreach (string ns in new[] { "First", "Second" })
                Assert.AreEqual(1, compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".NATIVE_RECORD")!
                    .DeclaringSyntaxReferences.Length);
            string output = Path.Combine(fixture.DirectoryPath, "DistinctNativeRecords.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            CollectionAssert.AreEquivalent(new[] { "First", "Second" }, reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "NATIVE_RECORD")
                .Select(type => reader.GetString(type.Namespace)).ToArray());
        }

        [DataTestMethod]
        [DataRow("compatible")]
        [DataRow("inferred")]
        [DataRow("unmarked")]
        [DataRow("storage")]
        [DataRow("binding-drift")]
        [DataRow("target-drift")]
        [DataRow("ambiguous-target")]
        [DataRow("foreign-family")]
        [DataRow("missing-target")]
        [DataRow("separate-target")]
        [DataRow("separate-unbound")]
        [DataRow("missing-route")]
        public void ConfiguredNativeViewsRequireAnActualBoundNativeTarget(string scenario)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            var providers = new List<string>();
            if (scenario != "missing-target")
                providers.Add(Provider("SCALAR", inferred: true, configured: false));
            providers.Add(Provider("RENAMED", inferred: scenario == "inferred", configured: scenario is not ("inferred" or "unmarked"),
                storage: scenario == "storage" ? "uint" : "int"));
            if (scenario is "target-drift" or "ambiguous-target")
                providers.Add(Provider("SCALAR", inferred: true, configured: false,
                    header: scenario == "ambiguous-target" ? "other-target" : null, hash: 'B'));
            if (scenario is "foreign-family" or "missing-target")
                providers.Add(Provider("UNRELATED", inferred: false, configured: false));
            fixture.Write("Bindings.header-types.cs", string.Join(Environment.NewLine, providers));
            if (scenario is "separate-target" or "separate-unbound" or "missing-route")
                fixture.Write("Other.header-types.cs", Provider("SCALAR", inferred: true, configured: false,
                    header: "other-target", ns: "Other") + (scenario == "separate-unbound" ? "" :
                    Provider("OTHER_RENAMED", inferred: false, configured: true, ns: "Other")));
            fixture.Write("Bindings.cs", @"
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace Native {
public struct CARRIER { public SCALAR Value; }
[return: NativeTypeName(""SCALAR"")] public delegate SCALAR CALLBACK();
public static partial class Apis {
[NativeTypeName(""SCALAR"")] public const SCALAR Value = (SCALAR)5;
[DllImport(""native.dll""), PreserveSig]
[return: NativeTypeName(""SCALAR"")] public static extern SCALAR Echo();
}
}");
            var owners = scenario == "missing-route" ? new Dictionary<string, string>() :
                new Dictionary<string, string> { ["SCALAR"] = "Canonical" };
            if (scenario is not ("compatible" or "inferred" or "separate-target"))
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(owners)).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile(owners);
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "NativeReceiver.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var scalars = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "SCALAR").ToArray();
            Assert.AreEqual(scenario == "inferred" ? 0 : 1, scalars.Length);
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "CARRIER");
            AssertSignature(reader.GetFieldDefinition(carrier.GetFields().Single()));
            var constant = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "Apis").SelectMany(type => type.GetFields())
                .Select(reader.GetFieldDefinition).Single(field => reader.GetString(field.Name) == "Value");
            AssertSignature(constant);
            var payload = reader.GetConstant(constant.GetDefaultValue());
            Assert.AreEqual(ConstantTypeCode.Int32, payload.TypeCode);
            Assert.AreEqual(5, reader.GetBlobReader(payload.Value).ReadInt32());
            foreach (var expected in new[] { (Type: "Apis", Method: "Echo"), (Type: "CALLBACK", Method: "Invoke") })
            {
                var method = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => reader.GetString(type.Name) == expected.Type).SelectMany(type => type.GetMethods())
                    .Select(reader.GetMethodDefinition).Single(method => reader.GetString(method.Name) == expected.Method);
                var signature = reader.GetBlobReader(method.Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(0, signature.ReadCompressedInteger());
                AssertValueSignature(signature);
                if (expected.Method == "Echo")
                    Assert.AreNotEqual(0, (int)(method.ImplAttributes & System.Reflection.MethodImplAttributes.PreserveSig));
            }
            if (scenario is "compatible" or "separate-target")
            {
                var canonical = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.SCALAR")!;
                var source = NativeTypedefSourceProvenance.Read((StructDeclarationSyntax)canonical.DeclaringSyntaxReferences.Single().GetSyntax())!;
                Assert.AreEqual("SCALAR", source.NativeName);
                Assert.AreEqual("Canonical", reader.GetString(scalars.Single().Namespace));
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(scalars.Single().GetFields().Single()).Signature));
            }

            void AssertSignature(FieldDefinition field)
            {
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual((byte)0x06, signature.ReadByte());
                AssertValueSignature(signature);
            }

            void AssertValueSignature(BlobReader signature)
            {
                if (scenario == "inferred")
                {
                    Assert.AreEqual((byte)0x08, signature.ReadByte());
                    Assert.AreEqual(0, signature.RemainingBytes);
                    return;
                }
                Assert.AreEqual((byte)0x11, signature.ReadByte());
                var target = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual("Canonical", reader.GetString(target.Namespace));
                Assert.AreEqual("SCALAR", reader.GetString(target.Name));
                Assert.AreEqual(0, signature.RemainingBytes);
            }

            string Provider(string nativeName, bool inferred, bool configured, string storage = "int",
                string? header = null, char hash = 'A', string ns = "Native")
            {
                string file = (header ?? nativeName) + ".h";
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, ns, "c:" + file + "@T@" + nativeName,
                    true, storage)).GetRoot();
                var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(original)! with
                {
                    NativeName = nativeName,
                    Header = Path.Combine(fixture.DirectoryPath, file),
                    HeaderHash = new string(hash, 64),
                };
                var declaration = NativeTypedefProjectionProvenance.WithPolicy(NativeTypedefSourceProvenance.Attach(
                    original.WithTrailingTrivia(default(SyntaxTriviaList)), source), inferred);
                if (configured)
                    declaration = NativeTypedefProjectionProvenance.WithConfiguredNominalBinding(declaration);
                if (scenario == "binding-drift" && configured)
                    declaration = declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Select(trivia =>
                        trivia.ToString().StartsWith("/* Win32Metadata.NativeTypedefBinding.", StringComparison.Ordinal)
                            ? SyntaxFactory.Comment(trivia.ToString().Replace(new string('A', 64), new string('B', 64)))
                            : trivia));
                return root.ReplaceNode(original, declaration).ToFullString()
                    .Replace("using Windows.Win32.Foundation.Metadata;", "", StringComparison.Ordinal)
                    .Replace("[NativeTypedef]", "[global::Windows.Win32.Foundation.Metadata.NativeTypedef]", StringComparison.Ordinal);
            }
        }

        [DataTestMethod]
        [DataRow("lifecycle")]
        [DataRow("output-only")]
        [DataRow("foreign-family")]
        [DataRow("storage")]
        [DataRow("ambiguous-cleanup")]
        [DataRow("compatible-type")]
        [DataRow("duplicate-cleanup")]
        public void NativeHandleOwnersRequireSourceBoundIntentAndAnUnambiguousCleanupNamespace(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", Provider("Observer", "observed", inferred: true,
                nativeName: scenario == "foreign-family" ? "UNRELATED" : "SCALAR",
                storage: scenario == "storage" ? "global::System.IntPtr" : "global::System.UIntPtr"));
            fixture.Write("Owner.header-types.cs", Provider("Canonical", "canonical", inferred: false,
                lifecycle: scenario != "output-only"));
            fixture.Write("Bindings.cs", @"
using System.Runtime.InteropServices;
namespace Observer { public struct CARRIER { public SCALAR Value; } }
namespace Canonical { public static class Apis {
[DllImport(""native.dll"")] public static extern void Release();
} }" + (scenario == "ambiguous-cleanup" ? @"
namespace Other { public static class Apis {
[DllImport(""other.dll"")] public static extern void Release();
} }" : ""));
            if (scenario is "storage" or "duplicate-cleanup")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "NativeHandleOwner.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var scalar = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "SCALAR");
            Assert.AreEqual("Canonical", reader.GetString(scalar.Namespace));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x19 },
                reader.GetBlobBytes(reader.GetFieldDefinition(scalar.GetFields().Single()).Signature));
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "CARRIER");
            var field = reader.GetFieldDefinition(carrier.GetFields().Single());
            if (scenario is not ("lifecycle" or "compatible-type"))
            {
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x19 }, reader.GetBlobBytes(field.Signature));
                return;
            }
            var signature = reader.GetBlobReader(field.Signature);
            Assert.AreEqual((byte)0x06, signature.ReadByte());
            Assert.AreEqual((byte)0x11, signature.ReadByte());
            Assert.AreEqual("Canonical", reader.GetString(ResolveLocalType(reader, signature.ReadTypeHandle()).Namespace));
            Assert.AreEqual(0, signature.RemainingBytes);

            string Provider(string ns, string header, bool inferred, string nativeName = "SCALAR",
                string storage = "global::System.UIntPtr", bool lifecycle = false)
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, ns, "c:" + header + ".h@T@" + nativeName,
                    true, storage, 8, 8)).GetRoot();
                var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(original)! with
                {
                    NativeName = nativeName,
                    Header = Path.Combine(fixture.DirectoryPath, header + ".h"),
                    SourceArchitecture = Architecture.X64,
                };
                var declaration = NativeTypedefProjectionProvenance.WithPolicy(NativeTypedefSourceProvenance.Attach(
                    original.WithTrailingTrivia(default(SyntaxTriviaList)), source), inferred);
                if (lifecycle)
                    declaration = declaration.AddAttributeLists(SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(
                        SyntaxFactory.Attribute(SyntaxFactory.ParseName(scenario == "compatible-type"
                            ? "global::Windows.Win32.Foundation.Metadata.AlsoUsableFor"
                            : "global::Windows.Win32.Foundation.Metadata.RAIIFree"),
                            SyntaxFactory.AttributeArgumentList(SyntaxFactory.SingletonSeparatedList(
                                SyntaxFactory.AttributeArgument(SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression,
                                    SyntaxFactory.Literal(scenario == "compatible-type" ? "SCALAR_BASE" : "Release")))))))));
                if (lifecycle && scenario == "duplicate-cleanup")
                    declaration = declaration.AddAttributeLists(declaration.AttributeLists.Last());
                return root.ReplaceNode(original, declaration).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow("compatible")]
        [DataRow("storage")]
        [DataRow("source")]
        [DataRow("layout")]
        [DataRow("nominal")]
        [DataRow("unmarked")]
        public void IndependentInferredAliasesRequireCompleteIntrinsicProjectionProof(string scenario)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", Provider("First", "int", inferred: true, first: true));
            fixture.Write("Other.header-types.cs", Provider(scenario == "source" ? "First" : "Second",
                scenario == "storage" ? "uint" : "int", inferred: scenario != "nominal", first: false));
            fixture.Write("Bindings.cs", "namespace Native { public struct CARRIER { public SCALAR Value; } }");
            var owners = new Dictionary<string, string> { ["SCALAR"] = "Canonical" };
            if (scenario != "compatible")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(owners)).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile(owners);
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "IntrinsicRedeclarations.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            Assert.AreEqual(0, reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Count(type => reader.GetString(type.Name) == "SCALAR"));
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "CARRIER");
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                reader.GetBlobBytes(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature));

            string Provider(string header, string storage, bool inferred, bool first)
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, "Native",
                    "c:native.h@T@SCALAR", true, storage)).GetRoot();
                var original = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(original)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath, header, "native.h"),
                    HeaderHash = new string(first ? 'A' : 'B', 64),
                    Alignment = scenario == "layout" && header == "Second" ? 8 : 4,
                };
                var declaration = NativeTypedefSourceProvenance.Attach(
                    original.WithTrailingTrivia(default(SyntaxTriviaList)), source);
                if (scenario != "unmarked" || header == "First")
                    declaration = NativeTypedefProjectionProvenance.WithPolicy(declaration, inferred);
                return root.ReplaceNode(original, declaration).ToFullString();
            }
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(true, false)]
        [DataRow(false, true)]
        [DataRow(true, true)]
        public void NativeFileLocalBasenamesRequireTheSamePhysicalDeclaration(bool conflictingSameHeader, bool inferred)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            foreach (string ns in new[] { "First", "Second" })
            {
                var root = CSharpSyntaxTree.ParseText(
                    TypedefProvider(fixture, ns, "c:main.cpp@T@SCALAR", true)).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(declaration)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath,
                        conflictingSameHeader ? "Shared" : ns, "main.cpp"),
                    HeaderHash = new string(ns == "First" ? 'A' : 'B', 64),
                };
                fixture.Write(ns + ".header-types.cs", root.ReplaceNode(declaration,
                    NativeTypedefProjectionProvenance.WithPolicy(NativeTypedefSourceProvenance.Attach(
                        declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source), inferred)).ToFullString());
                fixture.Write(ns + ".cs", "namespace " + ns + " { public struct CARRIER { public SCALAR Value; } }");
            }
            if (conflictingSameHeader)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "FileLocalOwners.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (string ns in new[] { "First", "Second" })
            {
                var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == "CARRIER");
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature);
                Assert.AreEqual((byte)0x06, signature.ReadByte());
                if (inferred)
                {
                    Assert.AreEqual((byte)0x08, signature.ReadByte());
                    Assert.IsFalse(reader.TypeDefinitions.Select(reader.GetTypeDefinition).Any(type =>
                        reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == "SCALAR"));
                }
                else
                {
                    var scalar = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                        reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == "SCALAR");
                    CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                        reader.GetBlobBytes(reader.GetFieldDefinition(scalar.GetFields().Single()).Signature));
                    Assert.AreEqual((byte)0x11, signature.ReadByte());
                    Assert.AreEqual(ns, reader.GetString(ResolveLocalType(reader, signature.ReadTypeHandle()).Namespace));
                }
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NativeFileLocalIdentityNormalizesOnlyThePhysicalHeaderCasing(bool differentNativeIdentifier)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs",
                TypedefProvider(fixture, "First", "c:native.h@T@SCALAR", true));
            string text = TypedefProvider(fixture, "Observer",
                differentNativeIdentifier ? "c:NATIVE.H@T@Scalar" : "c:NATIVE.H@T@SCALAR", false);
            var root = CSharpSyntaxTree.ParseText(text).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var source = NativeTypedefSourceProvenance.Read(declaration)! with
            {
                Header = Path.Combine(fixture.DirectoryPath, "NATIVE.H"),
                NativeName = differentNativeIdentifier ? "native::Scalar" : "native::SCALAR",
            };
            fixture.Write("Observer.header-types.cs", root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source)).ToFullString());
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(1, compilation.CSharpCompilation.GetTypeByMetadataName("First.SCALAR")!.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(differentNativeIdentifier,
                compilation.CSharpCompilation.GetTypeByMetadataName("Observer.SCALAR") != null);
            StringAssert.Contains(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "x64", "Observer.header-types.cs")),
                differentNativeIdentifier ? "c:NATIVE.H@T@Scalar" : "c:NATIVE.H@T@SCALAR");
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void LegacySuffixReferencesFollowTheConfiguredManualProviderNamespace(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Owner.manual.cs",
                "namespace Original { public partial struct NATIVE_RECORD { public int Value; } }");
            fixture.Write("Bindings.cs", RecordProvider(fixture, "Observer", "native-record", false)
                .Replace("NATIVE_RECORD", "NATIVE_RECORD___"));
            string text = RecordProvider(fixture, "Observer", "native-holder", true, "NATIVE_RECORD___");
            var root = CSharpSyntaxTree.ParseText(text).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var source = NativeRecordSourceProvenance.Read(declaration)! with { Name = "HOLDER", NativeName = "native::HOLDER" };
            declaration = NativeRecordSourceProvenance.Attach(
                declaration.WithIdentifier(SyntaxFactory.Identifier("HOLDER")).WithTrailingTrivia(default(SyntaxTriviaList)), source);
            fixture.Write("Holder.cs", root.ReplaceNode(root.DescendantNodes().OfType<StructDeclarationSyntax>().Single(), declaration)
                .ToFullString());
            var compilation = fixture.Compile(new() { ["NATIVE_RECORD"] = "Canonical" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "ManualSuffixOwner.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var holder = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Name) == "HOLDER");
            var blob = reader.GetBlobReader(reader.GetFieldDefinition(holder.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, blob.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, blob.ReadSignatureTypeCode());
            var value = ResolveLocalType(reader, blob.ReadTypeHandle());
            Assert.AreEqual("NATIVE_RECORD", reader.GetString(value.Name));
            Assert.AreEqual("Canonical", reader.GetString(value.Namespace));
        }

        [DataTestMethod]
        [DataRow("none")]
        [DataRow("native-name")]
        [DataRow("storage")]
        [DataRow("spelling")]
        [DataRow("attributes")]
        [DataRow("layout")]
        public void SameNativeRecordAliasBindingsRequireMatchingNativeFacts(string difference)
        {
            using var fixture = new Fixture("x86");
            fixture.Write("autotypes.cs", "");
            foreach (string ns in new[] { "Canonical", "Observer" })
            {
                string storage = ns == "Observer" && difference == "storage" ? "int" : "uint";
                string spelling = ns == "Observer" && difference == "spelling" ? "unsigned long" : "unsigned int";
                string text = TypedefProvider(fixture, ns, ns + "-alias", true, storage)
                    .Replace("public " + storage + " Value;", "[NativeTypeName(\"" + spelling + "\")] " +
                        (ns == "Observer" && difference == "attributes" ? "[NotNullTerminated] " : "") +
                        "public " + storage + " Value;");
                var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(declaration)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath, ns + ".h"),
                    NativeName = ns == "Observer" && difference == "native-name" ? "native::OTHER" : "native::SCALAR",
                    Size = ns == "Observer" && difference == "layout" ? 8 : 4,
                };
                fixture.Write(ns + ".header-types.cs", root.ReplaceNode(declaration, NativeTypedefSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source)).ToFullString());
                fixture.Write(ns + ".cs", RecordProvider(fixture, ns, "same-native-record", ns == "Canonical", ns + ".SCALAR"));
            }
            fixture.Write("Bindings.header-types.cs", "");
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            if (difference != "none")
            {
                Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(errors.Any(diagnostic => diagnostic.Id == "CS0102"));
                return;
            }
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            AssertCanonicalField(fixture, compilation, "Canonical", "SCALAR");
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Observer.SCALAR"));
        }

        [DataTestMethod]
        [DataRow(0, "none")]
        [DataRow(1, "none")]
        [DataRow(2, "none")]
        [DataRow(0, "native-name")]
        [DataRow(0, "missing-const")]
        [DataRow(1, "extra-const")]
        [DataRow(1, "pointer-depth")]
        [DataRow(0, "attribute-binding")]
        public void SameNativeRecordParametersPreserveProvenNominalPointerAliases(int depth, string difference)
        {
            using var fixture = new Fixture("x86");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "Canonical", "native-pointer",
                true, "void*").Replace("public partial struct", "public unsafe partial struct")
                .Replace("public void* Value;", "[NativeTypeName(\"const void *\"), Const] public void* Value;"));
            foreach (string ns in new[] { "Canonical", "Observer" })
            {
                bool canonical = ns == "Canonical";
                string type = canonical ? "global::Canonical.SCALAR" + new string('*', depth) :
                    "void" + new string('*', depth + (difference == "pointer-depth" ? 2 : 1));
                string native = (difference == "native-name" ? "native::OTHER" : "native::SCALAR") +
                    string.Concat(Enumerable.Repeat(" *", depth));
                bool isConst = depth == 0 && difference != "missing-const" || difference == "extra-const";
                string attributes = canonical ? "" : "[global::Windows.Win32.Foundation.Metadata.NativeTypeName(\"" +
                    native + "\")" + (isConst ? ", global::Windows.Win32.Foundation.Metadata.Const" : "") + "]" +
                    (difference == "attribute-binding" ? "[Missing]" : "");
                string parameter = attributes + " " + type + " data";
                string members = "public void** lpVtbl; " +
                    "[global::System.Runtime.InteropServices.UnmanagedFunctionPointer(" +
                    "global::System.Runtime.InteropServices.CallingConvention.StdCall)] public delegate void _Use(" +
                    "NATIVE_RECORD* self, " + parameter + "); public void Use(" + parameter + ") {" +
                    "fixed (NATIVE_RECORD* self = &this) { global::System.Runtime.InteropServices.Marshal." +
                    "GetDelegateForFunctionPointer<_Use>((IntPtr)(lpVtbl[0]))(self, data); }}";
                fixture.Write(ns + ".cs", "using System;\n" + RecordProvider(fixture, ns, "same-native-record", canonical, "void*")
                    .Replace("public partial struct", "public unsafe partial struct")
                    .Replace("public void* Value;", members));
            }
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            if (difference != "none")
            {
                Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(errors.Length != 0);
                return;
            }
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            var parameterType = record.GetTypeMembers("_Use").Single().DelegateInvokeMethod!.Parameters[1].Type;
            for (int i = 0; i < depth; i++)
                parameterType = ((IPointerTypeSymbol)parameterType).PointedAtType;
            Assert.AreEqual("Canonical.SCALAR", parameterType.ToDisplayString());
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalPointerParameters.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            var signature = reader.GetBlobReader(reader.GetMethodDefinition(physical.GetMethods()
                .Single(method => reader.GetString(reader.GetMethodDefinition(method).Name) == "Use")).Signature);
            signature.ReadSignatureHeader();
            Assert.AreEqual(1, signature.ReadCompressedInteger());
            Assert.AreEqual(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
            for (int i = 0; i < depth; i++)
                Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            Assert.AreEqual("SCALAR", reader.GetString(ResolveLocalType(reader, signature.ReadTypeHandle()).Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("none")]
        [DataRow("missing-spelling")]
        [DataRow("different-spelling")]
        [DataRow("pointer-depth")]
        [DataRow("target-proof")]
        [DataRow("attribute-binding")]
        public void SameNativeRecordPointerFieldsRequireTheirDeclaredRecordIdentity(string difference)
        {
            using var fixture = new Fixture("x86");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            string pointee = RecordProvider(fixture, "Canonical", "native-pointee", true, line: 2)
                .Replace("NATIVE_RECORD", "POINTEE");
            if (difference == "target-proof")
            {
                var root = CSharpSyntaxTree.ParseText(pointee).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                pointee = root.ReplaceNode(declaration, declaration.WithTrailingTrivia(default(SyntaxTriviaList))).ToFullString();
            }
            fixture.Write("Pointee.cs", pointee);
            foreach (string ns in new[] { "Canonical", "Observer" })
            {
                string storage = ns == "Canonical" ? "global::Canonical.POINTEE*" :
                    difference == "pointer-depth" ? "void**" : "void*";
                string attribute = ns == "Observer" && difference == "missing-spelling" ? "" :
                    "[global::Windows.Win32.Foundation.Metadata.NativeTypeName(\"struct native::" +
                    (ns == "Observer" && difference == "different-spelling" ? "OTHER" : "POINTEE") + " *\")]";
                if (ns == "Observer" && difference == "attribute-binding")
                    attribute += "[Missing]";
                fixture.Write(ns + ".cs", RecordProvider(fixture, ns, "same-native-record", ns == "Canonical", storage)
                    .Replace("public partial struct", "public unsafe partial struct")
                    .Replace("public " + storage + " Value;", attribute + " public " + storage + " Value;"));
            }
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            if (difference != "none")
            {
                Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(errors.Length != 0);
                return;
            }
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalRecordPointer.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(physical.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var target = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Canonical", reader.GetString(target.Namespace));
            Assert.AreEqual("POINTEE", reader.GetString(target.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("wchar_t", 1)]
        [DataRow("unsigned short", 1)]
        [DataRow("unsigned int", 1)]
        [DataRow("wchar_t", 2)]
        public void AlternateNativeRecordCharacterPointersUseExistingEncodingProof(string spelling, int retainedDepth)
        {
            using var fixture = new Fixture("x86");
            fixture.Write("autotypes.cs", "namespace Retained { [global::Windows.Win32.Foundation.Metadata.NativeTypedef] " +
                "public unsafe struct TEXT { public char" + new string('*', retainedDepth) + " Value; } }");
            string character = TypedefProvider(fixture, "Canonical", "native-character", true, "ushort", 2, 2)
                .Replace("SCALAR", "CHARACTER")
                .Replace("public ushort Value;", "[NativeTypeName(\"" + spelling + "\")] public ushort Value;");
            string pointer = TypedefProvider(fixture, "Canonical", "native-character-pointer", true,
                "global::Canonical.CHARACTER*").Replace("SCALAR", "TEXT")
                .Replace("public partial struct", "public unsafe partial struct")
                .Replace("public global::Canonical.CHARACTER* Value;", "[NativeTypeName(\"CHARACTER *\")] " +
                    "public global::Canonical.CHARACTER* Value;")
                .Replace("using Windows.Win32.Foundation.Metadata;", "");
            fixture.Write("Bindings.header-types.cs", character + pointer);
            fixture.Write("Bindings.cs", RecordProvider(fixture, "Canonical", "same-native-record", true, "Canonical.TEXT"));
            var root = CSharpSyntaxTree.ParseText(RecordProvider(fixture, "Observer", "same-native-record", false, "Retained.TEXT")).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var source = NativeRecordSourceProvenance.Read(declaration)! with { Header = Path.Combine(fixture.DirectoryPath, "alternate.h") };
            fixture.Write("Other.cs", root.ReplaceNode(declaration, NativeRecordSourceProvenance.Attach(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source)).ToFullString());
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.NATIVE_RECORD")!;
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            if (spelling == "unsigned int" || retainedDepth != 1)
            {
                Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
                Assert.IsTrue(errors.Any(diagnostic => diagnostic.Id == "CS0102"));
                return;
            }
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            AssertCanonicalField(fixture, compilation, "Canonical", "TEXT");
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Retained.TEXT"));
        }

        private static void AssertCanonicalField(Fixture fixture, ClangSharpSourceCompilation compilation, string ns, string name)
        {
            string output = Path.Combine(fixture.DirectoryPath, "CanonicalNativeBinding.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var record = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "NATIVE_RECORD");
            Assert.AreEqual(ns, reader.GetString(record.Namespace));
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(record.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var alias = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual(ns, reader.GetString(alias.Namespace));
            Assert.AreEqual(name, reader.GetString(alias.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        private static string RecordProvider(Fixture fixture, string ns, string identity, bool traversed, string storage = "int",
            long size = 4, uint line = 1, string? nativeName = null)
        {
            var root = CSharpSyntaxTree.ParseText("namespace " + ns + " { public partial struct NATIVE_RECORD { public " + storage + " Value; } }")
                .GetCompilationUnitRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var proof = new NativeRecordSource(identity, nativeName ?? "native::NATIVE_RECORD", Path.Combine(fixture.DirectoryPath, "native.h"),
                new string('A', 64), line, 1, "NATIVE_RECORD", ns, traversed, size, 4);
            return root.ReplaceNode(declaration, NativeRecordSourceProvenance.Attach(declaration, proof)).ToFullString() + "\n";
        }

        [TestMethod]
        public void IdenticalRecordTextWithDifferentAttributeArgumentsRemainsACompilerError()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Packing.manual.cs", @"namespace First { public static class Packing { public const int Value = 1; } }
namespace Second { public static class Packing { public const int Value = 2; } }");
            const string source = @"using System.Runtime.InteropServices; using PACKING = First.Packing;
namespace Test { [StructLayout(LayoutKind.Sequential, Pack = PACKING.Value)]
public partial struct NATIVE_RECORD { public int Value; } }";
            fixture.Write("Bindings.cs", source);
            fixture.Write("Other.cs", source.Replace("PACKING = First.Packing", "PACKING = Second.Packing"));
            var compilation = fixture.Compile();
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_RECORD")!.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
        }

        [TestMethod]
        public void DistinctPartialRecordMembersArePreserved()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Bindings.cs", "namespace Test { public partial struct NATIVE_RECORD { public int First; } }");
            fixture.Write("Other.cs", "namespace Test { public partial struct NATIVE_RECORD { public short Second; } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var type = compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_RECORD")!;
            Assert.AreEqual(2, type.DeclaringSyntaxReferences.Length);
            Assert.IsNotNull(type.GetMembers("First").SingleOrDefault());
            Assert.IsNotNull(type.GetMembers("Second").SingleOrDefault());
        }

        [TestMethod]
        public void DuplicateRecordDefinitionsInOneInputRemainACompilerError()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            const string record = "namespace Test { public partial struct NATIVE_RECORD { public int Value; } }";
            fixture.Write("Bindings.cs", record + record);
            var compilation = fixture.Compile();
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE_RECORD")!.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0102"));
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void HeaderOnlyAliasesComposeAfterSharedNamespaceAssignment(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("namespace Test", "namespace First"));
            fixture.Write("Other.header-types.cs", HeaderAlias.Replace("namespace Test", "namespace Second"));
            fixture.Write("Bindings.cs", @"using First; using Second; using Canonical;
namespace Consumers { public unsafe struct Holder { public HANDLE Value; } }");
            var compilation = fixture.Compile(new() { ["HANDLE"] = "Canonical" });
            var errors = compilation.CSharpCompilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.HANDLE");
            Assert.IsNotNull(alias);
            Assert.AreEqual(1, alias!.DeclaringSyntaxReferences.Length);
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("First.HANDLE"));
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Second.HANDLE"));
            string output = Path.Combine(fixture.DirectoryPath, "Shared.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "HANDLE");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            var field = reader.GetFieldDefinition(physical.GetFields().Single());
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x0f, 0x01 }, reader.GetBlobBytes(field.Signature));
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void HeaderAliasComposesWithRetainedCleanupAndInvalidValues(string architecture)
        {
            using var fixture = new Fixture(architecture);
            var compilation = fixture.Compile();
            var diagnostics = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, diagnostics.Length, string.Join(Environment.NewLine, diagnostics.Select(diagnostic => diagnostic.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE");
            Assert.IsNotNull(alias);
            Assert.AreEqual(1, alias!.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(1, alias.GetMembers("Value").Length);
            CollectionAssert.AreEquivalent(
                new[] { "RAIIFreeAttribute", "InvalidHandleValueAttribute", "NativeTypedefAttribute", "AlsoUsableForAttribute" },
                alias.GetAttributes().Select(attribute => attribute.AttributeClass!.Name).ToArray());
            Assert.AreEqual("Close", alias.GetAttributes().Single(attribute => attribute.AttributeClass!.Name == "RAIIFreeAttribute")
                .ConstructorArguments[0].Value);
            Assert.AreEqual(0L, alias.GetAttributes().Single(attribute => attribute.AttributeClass!.Name == "InvalidHandleValueAttribute")
                .ConstructorArguments[0].Value);
            Assert.AreEqual("OTHER_HANDLE", alias.GetAttributes().Single(attribute => attribute.AttributeClass!.Name == "AlsoUsableForAttribute")
                .ConstructorArguments[0].Value);

            string output = Path.Combine(fixture.DirectoryPath, "Test.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(File.Exists(output));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE");
            var field = type.GetFields().Select(reader.GetFieldDefinition).Single();
            Assert.AreEqual("Value", reader.GetString(field.Name));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x0f, 0x01 }, reader.GetBlobBytes(field.Signature));
            Assert.AreEqual(4, type.GetCustomAttributes().Count);
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void CompleteRetainedInvalidSetsReachTheSamePhysicalWrapper(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", RetainedAlias.Replace("[InvalidHandleValue(0)]",
                "[InvalidHandleValue(-1)][InvalidHandleValue(0)]", StringComparison.Ordinal));
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            CollectionAssert.AreEqual(new[] { -1L, 0L }, alias.GetAttributes()
                .Where(attribute => attribute.AttributeClass!.Name == "InvalidHandleValueAttribute")
                .Select(attribute => (long)attribute.ConstructorArguments[0].Value!).OrderBy(value => value).ToArray());
            Assert.AreEqual(1, alias.GetAttributes().Count(attribute => attribute.AttributeClass!.Name == "AlsoUsableForAttribute"));
            Assert.AreEqual(1, alias.GetAttributes().Count(attribute => attribute.AttributeClass!.Name == "RAIIFreeAttribute"));
            string output = Path.Combine(fixture.DirectoryPath, "Complete.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE");
            var values = type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "InvalidHandleValueAttribute")
                .Select(handle =>
                {
                    var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
                    Assert.AreEqual((ushort)1, blob.ReadUInt16());
                    long value = blob.ReadInt64();
                    Assert.AreEqual((ushort)0, blob.ReadUInt16());
                    Assert.AreEqual(0, blob.RemainingBytes);
                    return value;
                }).OrderBy(value => value).ToArray();
            CollectionAssert.AreEqual(new[] { -1L, 0L }, values);
            Assert.AreEqual(1, type.GetFields().Count);
            Assert.AreEqual(5, type.GetCustomAttributes().Count);
        }

        [DataTestMethod]
        [DataRow("uint", "", "", "Value storage")]
        [DataRow("long", "", "", "Value storage")]
        [DataRow("int*", "", "", "Value storage")]
        [DataRow("global::System.UIntPtr", "", "", "Value storage")]
        [DataRow("void*", "[RAIIFree(\"DifferentClose\")]", "", "RAIIFreeAttribute")]
        [DataRow("void*", "[InvalidHandleValue(-1)]", "", "InvalidHandleValueAttribute")]
        [DataRow("void*", "", "[AlsoUsableFor(\"DifferentHandle\")]", "AlsoUsableForAttribute")]
        public void ConflictingAliasStorageOrAnnotationsFailClosed(string storage, string headerAttribute, string retainedAttribute, string diagnostic)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", "using Windows.Win32.Foundation.Metadata;" +
                HeaderAlias.Replace("public void* Value", $"public {storage} Value").Replace("public unsafe", headerAttribute + "public unsafe"));
            fixture.Write("autotypes.cs", RetainedAlias.Replace("[NativeTypedef]", retainedAttribute + "[NativeTypedef]"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, diagnostic);
            StringAssert.Contains(error.Message, "Test.HANDLE");
        }

        [DataTestMethod]
        [DataRow("RECORD*", "namespace Test { public struct RECORD { public int unused; } }")]
        [DataRow("HANDLE__*", "namespace Test { public struct HANDLE__ { public int unused; } }")]
        [DataRow("HANDLE__*", "namespace Test { public struct HANDLE__ { public int Value; } }")]
        [DataRow("HANDLE__*", "namespace Test { public struct HANDLE__ { } }")]
        [DataRow("OTHER_HANDLE__*", "namespace Test { public struct OTHER_HANDLE__ { public int unused; } }")]
        [DataRow("global::Other.HANDLE__*", "namespace Other { public struct HANDLE__ { public int unused; } }")]
        [DataRow("HANDLE__**", "namespace Test { public struct HANDLE__ { public int unused; } }")]
        [DataRow("MISSING_NATIVE_TAG*", "")]
        public void RetainedInvalidValuesAndHandleShapedRecordsDoNotProveNativeHandleStorage(string storage, string record)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("[RAIIFree(\"Close\")]", "", StringComparison.Ordinal));
            fixture.Write("Bindings.header-types.cs", HeaderAlias
                .Replace("[global::Windows.Win32.Foundation.Metadata.AlsoUsableFor(\"OTHER_HANDLE\")]", "", StringComparison.Ordinal)
                .Replace("public void* Value", $"public {storage} Value", StringComparison.Ordinal));
            fixture.Write("Bindings.cs", record);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
            StringAssert.Contains(error.Message, "Test.HANDLE");
        }

        [DataTestMethod]
        [DataRow("void*", "global::System.IntPtr*")]
        [DataRow("global::System.IntPtr", "global::System.IntPtr*")]
        [DataRow("void*", "void**")]
        [DataRow("global::System.IntPtr", "void**")]
        public void RetainedNativeStorageDoesNotAuthorizeAdditionalPointerLevels(string retainedStorage, string headerStorage)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("public void* Value", $"public {retainedStorage} Value"));
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value", $"public {headerStorage} Value"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("void*")]
        [DataRow("global::System.IntPtr")]
        public void MultipleRetainedProvidersDoNotAuthorizeNativeHandlePointerStorage(string otherStorage)
        {
            using var fixture = new Fixture("x64");
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "autotypes.cs"),
                RetainedAlias.Replace("public void* Value", $"public {otherStorage} Value"));
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value", "public HANDLE__* Value"));
            fixture.Write("Bindings.cs", "namespace Test { public struct HANDLE__ { public int unused; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("crossarch", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        [DataRow("crossarch", true)]
        public void MatchingDeclareHandleProofsPreserveLegacyStorageAndNativeRecords(string architecture, bool completeEmptyRecord)
        {
            using var fixture = new Fixture(architecture);
            long[] invalidValues = completeEmptyRecord ? new long[] { -1, 0 } : new long[] { 0 };
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource(sourceNamespace: "Retained", invalidValues: invalidValues));
            string header = HeaderWithDeclareHandleProof(NativeHandleHeader.Replace("namespace Test", "namespace Native"));
            fixture.Write("Bindings.header-types.cs", header);
            fixture.Write("Other.header-types.cs", header);
            fixture.Write("Bindings.cs", "namespace Native { public partial struct HANDLE__ { " +
                (completeEmptyRecord ? "" : "public int unused;") + " } }");
            var compilation = fixture.Compile(new() { ["HANDLE"] = "Canonical", ["HANDLE__"] = "Canonical" });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.HANDLE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(((IFieldSymbol)alias.GetMembers("Value").Single()).Type is IPointerTypeSymbol pointer &&
                pointer.PointedAtType.SpecialType == SpecialType.System_Void);
            CollectionAssert.AreEquivalent(invalidValues, alias.GetAttributes()
                .Where(attribute => attribute.AttributeClass!.Name == "InvalidHandleValueAttribute")
                .Select(attribute => (long)attribute.ConstructorArguments.Single().Value!).ToArray());
            Assert.AreEqual(invalidValues.Length + 1, alias.GetAttributes().Length);
            var native = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.HANDLE__")!;
            Assert.AreEqual(1, native.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(completeEmptyRecord ? 0 : 1,
                native.GetMembers().OfType<IFieldSymbol>().Count(field => !field.IsImplicitlyDeclared));
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(
                (StructDeclarationSyntax)alias.DeclaringSyntaxReferences.Single().GetSyntax(), out _));

            string output = Path.Combine(fixture.DirectoryPath, "ProvenHandles.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Canonical").ToArray();
            CollectionAssert.AreEquivalent(new[] { "HANDLE", "HANDLE__" },
                types.Select(definition => reader.GetString(definition.Name)).ToArray());
            var physical = types.Single(definition => reader.GetString(definition.Name) == "HANDLE");
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x0f, 0x01 },
                reader.GetBlobBytes(reader.GetFieldDefinition(physical.GetFields().Single()).Signature));
            CollectionAssert.AreEqual(invalidValues, ReadInvalidValues(reader, physical));
            Assert.AreEqual(invalidValues.Length + 1, physical.GetCustomAttributes().Count);
            Assert.AreEqual(completeEmptyRecord ? 0 : 1,
                types.Single(definition => reader.GetString(definition.Name) == "HANDLE__").GetFields().Count);
        }

        [DataTestMethod]
        [DataRow("missing-retained")]
        [DataRow("missing-header")]
        [DataRow("other-handle")]
        [DataRow("wrong-generated-alias")]
        [DataRow("stale-header-storage")]
        [DataRow("stale-retained-storage")]
        [DataRow("wrong-kind")]
        [DataRow("wrong-provider")]
        [DataRow("duplicate-proof")]
        [DataRow("missing-invalid-values")]
        [DataRow("additional-pointer")]
        [DataRow("system-pointer")]
        [DataRow("aliased-storage")]
        [DataRow("native-typedef-pointee")]
        [DataRow("ambiguous-pointee")]
        [DataRow("ambiguous-pointee-resolution")]
        public void UnmatchedIncompleteOrAmbiguousDeclareHandleProofsFailClosed(string conflict)
        {
            using var fixture = new Fixture("x64");
            string retained = RetainedDeclareHandleSource();
            string header = HeaderWithDeclareHandleProof();
            string records = "namespace Test { public partial struct HANDLE__ { public int unused; } " +
                "public struct OTHER_HANDLE__ { public int unused; } }";
            switch (conflict)
            {
                case "missing-retained":
                    retained = WithoutHandleSourceProof(retained);
                    break;
                case "missing-header":
                    header = WithoutHandleSourceProof(header);
                    break;
                case "other-handle":
                    header = HeaderWithDeclareHandleProof(NativeHandleHeader.Replace("HANDLE__*", "OTHER_HANDLE__*"),
                        "OTHER_HANDLE", "OTHER_HANDLE__*");
                    break;
                case "wrong-generated-alias":
                    header = header.Replace("\"generatedAlias\":\"HANDLE\"", "\"generatedAlias\":\"OTHER_HANDLE\"");
                    break;
                case "stale-header-storage":
                    header = header.Replace("public HANDLE__* Value", "public OTHER_HANDLE__* Value");
                    break;
                case "stale-retained-storage":
                    retained = retained.Replace("public void* Value", "public IntPtr Value");
                    break;
                case "wrong-kind":
                    header = header.Replace("\"kind\":\"DECLARE_HANDLE\"", "\"kind\":\"OTHER_KIND\"");
                    break;
                case "wrong-provider":
                    header = header.Replace("\"provider\":\"header\"", "\"provider\":\"retained\"");
                    break;
                case "duplicate-proof":
                    var root = CSharpSyntaxTree.ParseText(header).GetRoot();
                    var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                    header = root.ReplaceNode(declaration, declaration.WithLeadingTrivia(
                        declaration.GetLeadingTrivia().AddRange(declaration.GetLeadingTrivia()))).ToFullString();
                    break;
                case "missing-invalid-values":
                    retained = RetainedDeclareHandleSource(invalidValues: Array.Empty<long>());
                    break;
                case "additional-pointer":
                    header = header.Replace("HANDLE__*", "HANDLE__**");
                    break;
                case "system-pointer":
                    header = HeaderWithDeclareHandleProof(NativeHandleHeader.Replace("HANDLE__*", "global::System.IntPtr*"),
                        storage: "global::System.IntPtr*");
                    break;
                case "aliased-storage":
                    header = HeaderWithDeclareHandleProof("using STORAGE = Test.OTHER_HANDLE__;\n" +
                        NativeHandleHeader.Replace("HANDLE__*", "STORAGE*"), storage: "STORAGE*");
                    break;
                case "native-typedef-pointee":
                    records = "namespace Test { [global::Windows.Win32.Foundation.Metadata.NativeTypedef] " +
                        "public partial struct HANDLE__ { public int Value; } }";
                    break;
                case "ambiguous-pointee":
                    records = "namespace Test { public partial struct HANDLE__ { public int First; } " +
                        "public partial struct HANDLE__ { public int Second; } }";
                    break;
                case "ambiguous-pointee-resolution":
                    records = "namespace First { public struct HANDLE__ { public int unused; } } " +
                        "namespace Second { public struct HANDLE__ { public int unused; } }";
                    header = HeaderWithDeclareHandleProof("using First; using Second;\n" + NativeHandleHeader);
                    break;
            }
            fixture.Write("autotypes.cs", retained);
            fixture.Write("Bindings.header-types.cs", header);
            fixture.Write("Bindings.cs", records);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void MatchingHandleProofsDoNotRequireIntentionallyExcludedNativeTagDefinitions(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof());
            fixture.Write("Other.header-types.cs", HeaderWithDeclareHandleProof());
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE__"));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(((IFieldSymbol)alias.GetMembers("Value").Single()).Type is IPointerTypeSymbol pointer &&
                pointer.PointedAtType.SpecialType == SpecialType.System_Void);
            Assert.AreEqual(0L, alias.GetAttributes()
                .Single(attribute => attribute.AttributeClass!.Name == "InvalidHandleValueAttribute").ConstructorArguments.Single().Value);
        }

        [TestMethod]
        public void DifferentUnresolvedPointerStoragesCannotShareOneRetainedHandleProof()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof());
            fixture.Write("Other.header-types.cs", HeaderWithDeclareHandleProof(
                NativeHandleHeader.Replace("HANDLE__*", "OTHER_NATIVE_STORAGE*"), storage: "OTHER_NATIVE_STORAGE*"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("REMAPPED_NATIVE_TAG*")]
        [DataRow("global::Test.REMAPPED_NATIVE_TAG*")]
        public void ProvenGeneratedStorageDoesNotDependOnNativeTagNamingConventions(string storage)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof(
                NativeHandleHeader.Replace("HANDLE__*", storage), storage: storage));
            fixture.Write("Bindings.cs", "namespace Test { public partial struct REMAPPED_NATIVE_TAG { public int unused; } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.IsTrue(((IFieldSymbol)alias.GetMembers("Value").Single()).Type is IPointerTypeSymbol pointer &&
                pointer.PointedAtType.SpecialType == SpecialType.System_Void);
        }

        [TestMethod]
        public void ConflictingProvenNativePointerBindingsAreNotCollapsed()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof());
            fixture.Write("Other.header-types.cs", HeaderWithDeclareHandleProof(
                NativeHandleHeader.Replace("HANDLE__*", "OTHER_NATIVE_STORAGE*"), storage: "OTHER_NATIVE_STORAGE*"));
            fixture.Write("Bindings.cs", "namespace Test { public partial struct HANDLE__ { public int unused; } " +
                "public partial struct OTHER_NATIVE_STORAGE { public int unused; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [TestMethod]
        public void MatchingHandleProofsDoNotOverrideConflictingInvalidValueMetadata()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof(NativeHandleHeader.Replace("public unsafe",
                "[global::Windows.Win32.Foundation.Metadata.InvalidHandleValue(-1)] public unsafe")));
            fixture.Write("Bindings.cs", "namespace Test { public partial struct HANDLE__ { public int unused; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting 'global::Windows.Win32.Foundation.Metadata.InvalidHandleValueAttribute' annotations");
        }

        [TestMethod]
        public void MatchingProofsCannotChooseBetweenMultipleRetainedProviders()
        {
            using var fixture = new Fixture("x64");
            string retained = RetainedDeclareHandleSource();
            fixture.Write("autotypes.cs", retained);
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "autotypes.cs"), retained);
            fixture.Write("Bindings.header-types.cs", HeaderWithDeclareHandleProof());
            fixture.Write("Bindings.cs", "namespace Test { public partial struct HANDLE__ { public int unused; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("missing")]
        [DataRow("other-alias")]
        [DataRow("wrong-kind")]
        public void CrossArchCoalescingCannotDiscardAProfileWithoutMatchingHandleProof(string conflict)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            string header = HeaderWithDeclareHandleProof();
            fixture.Write("Bindings.header-types.cs", header);
            fixture.Write("Bindings.cs", "namespace Test { public partial struct HANDLE__ { public int unused; } }");
            string unproven = conflict switch
            {
                "missing" => WithoutHandleSourceProof(header),
                "other-alias" => header.Replace("\"nativeAlias\":\"::HANDLE\"", "\"nativeAlias\":\"::OTHER_HANDLE\""),
                _ => header.Replace("\"kind\":\"DECLARE_HANDLE\"", "\"kind\":\"OTHER_KIND\""),
            };
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "x64", "Bindings.header-types.cs"), unproven);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [TestMethod]
        public void ProvenCrossArchHandleVariantsRetainLegacyStorageAndInvalidValues()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedDeclareHandleSource());
            fixture.Write("Bindings.cs", "namespace Test { public partial struct HANDLE__ { public int unused; } }");
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
            {
                string header = NativeHandleHeader.Replace("public unsafe",
                    $"[global::Windows.Win32.Foundation.Metadata.AlsoUsableFor(\"{architecture}\")] public unsafe");
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, architecture, "Bindings.header-types.cs"),
                    HeaderWithDeclareHandleProof(header));
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "ProvenVariants.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var aliases = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE").ToArray();
            Assert.AreEqual(3, aliases.Length);
            foreach (var alias in aliases)
            {
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x0f, 0x01 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(alias.GetFields().Single()).Signature));
                CollectionAssert.AreEqual(new long[] { 0 }, ReadInvalidValues(reader, alias));
                Assert.AreEqual(4, alias.GetCustomAttributes().Count);
            }
        }

        [DataTestMethod]
        [DataRow("void*", "global::System.IntPtr")]
        [DataRow("global::System.IntPtr", "void*")]
        public void RetainedNativePointerStorageIsPreserved(string retainedStorage, string headerStorage)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("public void* Value", $"public {retainedStorage} Value"));
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value", $"public {headerStorage} Value"));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(4, alias.GetAttributes().Length);
            string output = Path.Combine(fixture.DirectoryPath, "Pointer.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE");
            var field = reader.GetFieldDefinition(type.GetFields().Single());
            CollectionAssert.AreEqual(retainedStorage == "void*" ? new byte[] { 0x06, 0x0f, 0x01 } : new byte[] { 0x06, 0x18 },
                reader.GetBlobBytes(field.Signature));
        }

        [TestMethod]
        public void HeaderOnlyPointerStorageDisagreementsFailClosed()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Other.header-types.cs", HeaderAlias.Replace("public void* Value", "public global::System.IntPtr Value"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
        }

        [DataTestMethod]
        [DataRow("public int Extra;")]
        [DataRow("[global::System.Runtime.InteropServices.DllImport(\"test\")] public static extern void Method();")]
        public void NonWrapperMembersAreNotDiscarded(string member)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value;", "public void* Value; " + member));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "one public instance Value field");
        }

        [TestMethod]
        public void OrdinaryDeclarationsAreNotMergedIntoGeneratedAliases()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.cs", RetainedAlias);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "outside generated");
        }

        [TestMethod]
        public void DuplicateAliasesWithinOneTranslationUnitFailClosed()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", HeaderAlias + HeaderAlias);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Multiple native aliases in one input");
        }

        [TestMethod]
        public void RepeatedHeaderFragmentsAndIdenticalLegacyAnnotationsComposeOnce()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Other.header-types.cs", HeaderAlias);
            fixture.Write("autotypes.cs", RetainedAlias.Replace("[NativeTypedef]",
                "[global::Windows.Win32.Foundation.Metadata.AlsoUsableForAttribute(\"OTHER_HANDLE\")][NativeTypedef]"));
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(1, alias.GetMembers("Value").Length);
            Assert.AreEqual(4, alias.GetAttributes().Length);
        }

        [TestMethod]
        public void AForeignShortNameDoesNotAffectComposition()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.cs", "namespace Other { public struct HANDLE { public uint Value; } }");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(SpecialType.System_UInt32,
                ((IFieldSymbol)compilation.CSharpCompilation.GetTypeByMetadataName("Other.HANDLE")!.GetMembers("Value").Single()).Type.SpecialType);
            Assert.AreEqual(1, compilation.CSharpCompilation.GetTypeByMetadataName("Other.HANDLE")!.DeclaringSyntaxReferences.Length);
        }

        [TestMethod]
        public void RetainedAliasWithoutHeaderMetadataIsUnchanged()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", "");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(3, compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!.GetAttributes().Length);
        }

        [TestMethod]
        public void HeaderAliasWithoutRetainedAutoTypesIsUnchanged()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(2, compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!.GetAttributes().Length);
        }

        [DataTestMethod]
        [DataRow(true)]
        [DataRow(false)]
        public void CrossArchAnnotationDifferencesDoNotLoseRetainedFacts(bool retainAutoTypes)
        {
            using var fixture = new Fixture("crossarch");
            if (!retainAutoTypes)
                fixture.Write("autotypes.cs", "");
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
            {
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, architecture, "Bindings.header-types.cs"),
                    HeaderAlias.Replace("OTHER_HANDLE", architecture));
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, architecture, "Bindings.cs"), @"
using System.Runtime.InteropServices;
namespace Test { public static class Apis {
    [DllImport(""test"")] public static extern HANDLE Use(HANDLE value);
}}");
            }
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(diagnostic => diagnostic.ToString())));
            var aliases = compilation.CSharpCompilation.GlobalNamespace.GetNamespaceMembers().Single(ns => ns.Name == "Test").GetTypeMembers();
            foreach (var alias in aliases.Where(alias => alias.TypeKind == TypeKind.Struct))
            {
                var attributes = alias.GetAttributes().Select(attribute => attribute.AttributeClass!.Name).ToArray();
                if (retainAutoTypes)
                {
                    CollectionAssert.Contains(attributes, "RAIIFreeAttribute", alias.ToDisplayString());
                    CollectionAssert.Contains(attributes, "InvalidHandleValueAttribute", alias.ToDisplayString());
                }
                CollectionAssert.Contains(attributes, "AlsoUsableForAttribute", alias.ToDisplayString());
            }
            string output = Path.Combine(fixture.DirectoryPath, "Test.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(File.Exists(output));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE").ToArray();
            Assert.AreEqual(3, physical.Length);
            foreach (var alias in physical)
            {
                Assert.AreEqual(1, alias.GetFields().Count);
                Assert.AreEqual(retainAutoTypes ? 5 : 3, alias.GetCustomAttributes().Count);
            }
        }

        [TestMethod]
        public void PartialHeaderArchitectureCoverageCannotEraseCommonAutoTypes()
        {
            using var fixture = new Fixture("crossarch");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "arm64", "Bindings.header-types.cs"), "");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "complete x86/x64/arm64 coverage");
        }

        [TestMethod]
        public void NativePointerStorageIsRetainedAcrossHeaderArchitectureVariants()
        {
            using var fixture = new Fixture("crossarch");
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, architecture, "Bindings.header-types.cs"),
                    HeaderAlias.Replace("public void* Value", "public global::System.IntPtr Value")
                        .Replace("OTHER_HANDLE", architecture));
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string output = Path.Combine(fixture.DirectoryPath, "Variants.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var aliases = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(definition => reader.GetString(definition.Namespace) == "Test" && reader.GetString(definition.Name) == "HANDLE").ToArray();
            Assert.AreEqual(3, aliases.Length);
            foreach (var alias in aliases)
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x0f, 0x01 },
                    reader.GetBlobBytes(reader.GetFieldDefinition(alias.GetFields().Single()).Signature));
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(true, false)]
        [DataRow(false, true)]
        [DataRow(true, true)]
        public void RoutedHeaderAliasesKeepTheirOriginalDependencyBinding(bool qualified, bool moveDependency)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Original {
    [NativeTypedef] public partial struct BASE { [NativeTypeName(""unsigned char"")] public byte Value; }
    [NativeTypedef] public partial struct ALIAS { [NativeTypeName(""BASE"")] public " +
                (qualified ? "global::Original.BASE" : "BASE") + @" Value; }
}");
            fixture.Write("Bindings.cs", "namespace Other { public struct " +
                (moveDependency ? "UNRELATED" : "BASE") + " { public uint Value; } }");
            var owners = new Dictionary<string, string> { ["ALIAS"] = "Canonical", ["UNRELATED"] = "Other" };
            if (moveDependency)
                owners["BASE"] = "CanonicalBase";
            var compilation = fixture.Compile(owners);
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.ALIAS")!;
            Assert.AreEqual((moveDependency ? "CanonicalBase" : "Original") + ".BASE",
                ((IFieldSymbol)alias.GetMembers("Value").Single()).Type.ToDisplayString());
        }

        [DataTestMethod]
        [DataRow("Const", "ConstAttribute")]
        [DataRow("Documentation(\"same\")", "DocumentationAttribute")]
        [DataRow("NotNullTerminated", "NotNullTerminatedAttribute")]
        [DataRow("NullNullTerminated", "NullNullTerminatedAttribute")]
        [DataRow("NotNullTerminated,NullNullTerminated", "NullNullTerminatedAttribute")]
        public void ComposedAliasesPreserveSupportedValueFieldMetadata(string attribute, string name)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value",
                $"[NativeTypeName(\"const void *\"), {attribute}] public void* Value"));
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var field = (IFieldSymbol)compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!.GetMembers("Value").Single();
            Assert.AreEqual(1, field.GetAttributes().Count(value => value.AttributeClass!.Name == name));
            string output = Path.Combine(fixture.DirectoryPath, "FieldMetadata.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "HANDLE");
            var attributes = reader.GetFieldDefinition(type.GetFields().Single()).GetCustomAttributes()
                .Select(handle => AttributeName(reader, handle)).ToArray();
            Assert.AreEqual(1, attributes.Count(value => value == name));
            if (attribute.Contains("NotNullTerminated,NullNullTerminated", StringComparison.Ordinal))
                Assert.AreEqual(1, attributes.Count(value => value == "NotNullTerminatedAttribute"));
        }

        [DataTestMethod]
        [DataRow("AlsoUsableFor(\"Other\")", "", "Value fields only support")]
        [DataRow("NativeTypeName(\"void *\"), NativeTypeName(\"void *\")", "", "Value fields only support")]
        [DataRow("NotNullTerminated, NotNullTerminated", "", "Value fields only support")]
        [DataRow("Documentation(\"header\")", "Documentation(\"retained\")", "Conflicting Value-field")]
        public void UnsupportedOrConflictingValueFieldMetadataStillRejects(string header, string retained, string diagnostic)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value", $"[{header}] public void* Value"));
            if (retained.Length != 0)
                fixture.Write("autotypes.cs", RetainedAlias.Replace("public void* Value", $"[{retained}] public void* Value"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, diagnostic);
        }

        [DataTestMethod]
        [DataRow("UIntPtr", "uint", "ulong", false, true)]
        [DataRow("IntPtr", "int", "long", false, true)]
        [DataRow("UIntPtr", "int", "ulong", false, false)]
        [DataRow("UIntPtr", "ulong", "ulong", false, false)]
        [DataRow("UIntPtr", "uint", "long", false, false)]
        [DataRow("UIntPtr", "uint", "ulong", true, false)]
        public void NativeIntegerEncodingRequiresMatchingSignedStorageOnEveryArchitecture(
            string retained, string x86, string wide, bool omitArm64, bool compatible)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("void*", "global::System." + retained));
            foreach (string arch in new[] { "x86", "x64", "arm64" })
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, arch, "Bindings.header-types.cs"),
                    omitArm64 && arch == "arm64" ? "" : HeaderAlias.Replace("void*", arch == "x86" ? x86 : wide));
            if (!compatible)
            {
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message, omitArm64 ? "complete x86/x64/arm64 coverage" : "Value storage");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var aliases = compilation.CSharpCompilation.GlobalNamespace.GetNamespaceMembers().Single(ns => ns.Name == "Test")
                .GetTypeMembers().Where(type => type.Name.StartsWith("HANDLE", StringComparison.Ordinal)).ToArray();
            Assert.AreEqual(2, aliases.Length);
            foreach (var alias in aliases)
                Assert.AreEqual("System." + retained, ((IFieldSymbol)alias.GetMembers("Value").Single()).Type.ToDisplayString());
        }

        [DataTestMethod]
        [DataRow("byte", "sbyte", "char", true)]
        [DataRow("byte", "sbyte", "signed char", false)]
        [DataRow("byte*", "sbyte*", "char *", true)]
        [DataRow("byte*", "sbyte*", "signed char *", false)]
        [DataRow("char*", "ushort*", "unsigned short *", true)]
        [DataRow("char*", "short*", "short *", false)]
        [DataRow("char", "uint", "unsigned int", false)]
        [DataRow("byte", "short", "char", false)]
        [DataRow("char**", "ushort*", "unsigned short *", false)]
        public void RetainedCharacterEncodingsRequireTheirNativeCharacterContract(
            string retained, string incoming, string native, bool compatible)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("void*", retained)
                .Replace("[RAIIFree(\"Close\")]", "").Replace("[InvalidHandleValue(0)]", ""));
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value",
                $"[NativeTypeName(\"{native}\")] public {incoming} Value"));
            if (!compatible)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "Value storage");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(retained, ((IFieldSymbol)alias.GetMembers("Value").Single()).Type.ToDisplayString());
            string output = Path.Combine(fixture.DirectoryPath, "Character.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "HANDLE");
            CollectionAssert.AreEqual(retained switch
            {
                "byte" => new byte[] { 0x06, 0x05 },
                "byte*" => new byte[] { 0x06, 0x0f, 0x05 },
                "char*" => new byte[] { 0x06, 0x0f, 0x03 },
                _ => throw new InvalidOperationException("Unexpected retained character encoding."),
            }, reader.GetBlobBytes(reader.GetFieldDefinition(physical.GetFields().Single()).Signature));
        }

        [DataTestMethod]
        [DataRow("struct _RECORD *", false, false, true)]
        [DataRow("struct _RECORD *", true, false, false)]
        [DataRow("struct _RECORD *", false, true, false)]
        [DataRow("RECORD *", false, false, true)]
        [DataRow("const RECORD *", false, false, true)]
        [DataRow("OTHER *", false, false, false)]
        [DataRow("RECORD *", true, false, false)]
        [DataRow("RECORD *", false, true, false)]
        public void HeaderRecordPointerViewsRequireOneSourceBoundPointee(
            string nativeType, bool differentNativeTag, bool conflictingManagedOwner, bool compatible)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""" + nativeType + @""")] public void* Value;
}}");
            fixture.Write("Other.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""" + (differentNativeTag ? nativeType.Replace("RECORD", "OTHER") : nativeType) +
    @""")] public global::Test.RECORD* Value;
}}");
            fixture.Write("Bindings.cs", "namespace Test { public struct RECORD { public int value; } } " +
                "namespace Other { public struct RECORD { public int value; } }");
            if (conflictingManagedOwner)
                fixture.Write("Conflict.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""" + nativeType + @""")] public global::Other.RECORD* Value;
}}");
            if (!compatible)
            {
                Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual("Test.RECORD*", ((IFieldSymbol)compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!
                .GetMembers("Value").Single()).Type.ToDisplayString());
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void DistinctNativePointerAliasesKeepTheirDeclaringOwnersAndSignatureBindings(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            int size = architecture == "x86" ? 4 : 8;
            string Provider(string ns, string identity, string storage) => TypedefProvider(fixture, ns, identity, traversed: true,
                storage: storage, size: size, alignment: size)
                .Replace("public partial struct", "public unsafe partial struct")
                .Replace("public " + storage + " Value",
                    "[NativeTypeName(\"RECORD_ALIAS *\")] public " + storage + " Value");
            fixture.Write("Bindings.header-types.cs", Provider("First", "first-native-pointer", "void*"));
            fixture.Write("Other.header-types.cs", Provider("Second", "second-native-pointer", "global::Second.RECORD*"));
            fixture.Write("Bindings.cs", @"
using System.Runtime.InteropServices;
namespace First { public static partial class Apis {
    [DllImport(""test"")] public static extern void UseFirst(SCALAR value);
} }
namespace Second {
    public struct RECORD { public int value; }
    public static partial class Apis {
        [DllImport(""test"")] public static extern void UseSecond(SCALAR value);
    }
}");
            var compilation = fixture.Compile(apiNamesToNamespaces: new() { ["SCALAR"] = "First" });
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            foreach (string ns in new[] { "First", "Second" })
            {
                var alias = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".SCALAR")!;
                Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
                var method = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".Apis")!
                    .GetMembers("Use" + ns).OfType<IMethodSymbol>().Single();
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(alias, method.Parameters.Single().Type));
            }
            string output = Path.Combine(fixture.DirectoryPath, "DistinctPointeeAliases.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "SCALAR").ToArray();
            Assert.AreEqual(2, physical.Length);
            foreach (string ns in new[] { "First", "Second" })
            {
                var alias = physical.Single(type => reader.GetString(type.Namespace) == ns);
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(alias.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
                if (ns == "First")
                    Assert.AreEqual(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
                else
                {
                    Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                    var pointee = ResolveLocalType(reader, signature.ReadTypeHandle());
                    Assert.AreEqual("Second", reader.GetString(pointee.Namespace));
                    Assert.AreEqual("RECORD", reader.GetString(pointee.Name));
                }
                Assert.AreEqual(0, signature.RemainingBytes);
                var method = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == "Use" + ns);
                signature = reader.GetBlobReader(method.Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var parameter = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual(ns, reader.GetString(parameter.Namespace));
                Assert.AreEqual("SCALAR", reader.GetString(parameter.Name));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void IntrinsicGuidPointerViewsRequireTheRuntimeGuidIdentity(bool unrelatedGuid)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            const string alias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""GUID *"")] public void* Value;
}}";
            fixture.Write("Bindings.header-types.cs", alias);
            fixture.Write("Other.header-types.cs", alias.Replace("void*",
                unrelatedGuid ? "global::Other.Guid*" : "global::System.Guid*"));
            fixture.Write("Other.cs", "namespace Other { public struct Guid { public long A, B; } }");
            if (unrelatedGuid)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "Value storage");
                return;
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "IntrinsicGuid.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                reader.GetString(type.Namespace) == "Test" && reader.GetString(type.Name) == "HANDLE");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(type.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.Pointer, signature.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var target = signature.ReadTypeHandle();
            Assert.AreEqual(HandleKind.TypeReference, target.Kind);
            var reference = reader.GetTypeReference((TypeReferenceHandle)target);
            Assert.AreEqual("System", reader.GetString(reference.Namespace));
            Assert.AreEqual("Guid", reader.GetString(reference.Name));
            Assert.AreEqual(HandleKind.AssemblyReference, reference.ResolutionScope.Kind);
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow(true, "int", true)]
        [DataRow(false, "int", false)]
        [DataRow(true, "uint", false)]
        public void SameInputAliasesNeedAnExplicitCompatibleRetainedOwner(bool route, string storage, bool compatible)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("void*", "int")
                .Replace("[RAIIFree(\"Close\")]", "").Replace("[InvalidHandleValue(0)]", ""));
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
    [NativeTypedef] public partial struct HANDLE { [NativeTypeName(""long"")] public int Value; }
    [NativeTypedef] public partial struct HANDLE { [NativeTypeName(""LONG"")] public " + storage + @" Value; }
}");
            Dictionary<string, string> owners = route ? new() { ["HANDLE"] = "Test" } : new();
            if (!compatible)
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(owners)).Message,
                    route ? "Value storage" : "Multiple native aliases");
                return;
            }
            var compilation = fixture.Compile(owners);
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(1, compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!.DeclaringSyntaxReferences.Length);
        }

        [TestMethod]
        public void NativeAliasDoesNotReplaceAnExplicitMetadataTypedefContract()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("[NativeTypedef]", "[MetadataTypedef]"));
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(1, alias.GetAttributes().Count(attribute => attribute.AttributeClass!.Name == "MetadataTypedefAttribute"));
            Assert.AreEqual(0, alias.GetAttributes().Count(attribute => attribute.AttributeClass!.Name == "NativeTypedefAttribute"));
        }

        [TestMethod]
        public void PartialHeaderObservationsCannotNarrowAnUnchangedRetainedContract()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("void*", "global::System.IntPtr"));
            fixture.Write("Bindings.header-types.cs",
                HeaderAlias.Replace("[global::Windows.Win32.Foundation.Metadata.AlsoUsableFor(\"OTHER_HANDLE\")]", ""));
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "x86", "Bindings.header-types.cs"), "");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var alias = compilation.CSharpCompilation.GetTypeByMetadataName("Test.HANDLE")!;
            Assert.AreEqual(1, alias.DeclaringSyntaxReferences.Length);
            Assert.AreEqual("System.IntPtr", ((IFieldSymbol)alias.GetMembers("Value").Single()).Type.ToDisplayString());
            Assert.IsFalse(alias.GetAttributes().Any(attribute => attribute.AttributeClass!.Name == "SupportedArchitectureAttribute"));
        }

        [TestMethod]
        public void MalformedPartialAliasCoverageRetainsTypedCompositionDiagnostics()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", RetainedAlias.Replace("void*", "global::System.IntPtr"));
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("public void* Value;",
                "public void* Value; public int Extra;")
                .Replace("[global::Windows.Win32.Foundation.Metadata.AlsoUsableFor(\"OTHER_HANDLE\")]", ""));
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "x86", "Bindings.header-types.cs"), "");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CSSW005");
            StringAssert.Contains(error.Message, "one public instance Value field");
        }

        [DataTestMethod]
        [DataRow(false, false)]
        [DataRow(true, false)]
        [DataRow(false, true)]
        [DataRow(true, true)]
        public void CommonPointerAliasConstraintsComposeWithCompleteRecordArchitectureVariants(bool notYetUnmanaged,
            bool repeatedRecords)
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            const string alias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""RECORD *"")] public global::Test.RECORD* Value;
}}";
            fixture.Write("Bindings.header-types.cs", alias);
            const string outerAlias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct OUTER {
    [NativeTypeName(""HANDLE"")] public global::Test.HANDLE Value;
}}";
            fixture.Write("Outer.header-types.cs", outerAlias);
            foreach (string arch in new[] { "x86", "x64", "arm64" })
            {
                string field = notYetUnmanaged && arch == "x86" ?
                    "[global::System.Runtime.InteropServices.MarshalAs(global::System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 4)] public byte[] value;" :
                    "public " + (arch == "x86" ? "int" : arch == "x64" ? "long" : "short") + " value;";
                string record = "namespace Test { public partial struct RECORD { " + field + " } }";
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, arch, "Bindings.cs"), record);
                if (repeatedRecords)
                    File.WriteAllText(Path.Combine(fixture.DirectoryPath, arch, "Duplicate.cs"), record);
            }
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Extra.header-types.cs"), alias);
            File.WriteAllText(Path.Combine(common, "OuterConstraint.header-types.cs"), outerAlias);
            var compilation = fixture.Compile(new() { ["RECORD"] = "Canonical" });
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var aliases = compilation.CSharpCompilation.GlobalNamespace.GetNamespaceMembers().Single(ns => ns.Name == "Test")
                .GetTypeMembers().Where(type => type.Name.StartsWith("HANDLE", StringComparison.Ordinal)).ToArray();
            Assert.AreEqual(3, aliases.Length);
            foreach (var type in aliases)
            {
                Assert.AreEqual(1, type.DeclaringSyntaxReferences.Length);
                var pointer = (IPointerTypeSymbol)((IFieldSymbol)type.GetMembers("Value").Single()).Type;
                Assert.AreEqual("Canonical", pointer.PointedAtType.ContainingNamespace.ToDisplayString());
            }
            var outers = compilation.CSharpCompilation.GlobalNamespace.GetNamespaceMembers().Single(ns => ns.Name == "Test")
                .GetTypeMembers().Where(type => type.Name.StartsWith("OUTER", StringComparison.Ordinal)).ToArray();
            Assert.AreEqual(3, outers.Length);
            foreach (var outer in outers)
            {
                var inner = (INamedTypeSymbol)((IFieldSymbol)outer.GetMembers("Value").Single()).Type;
                Assert.IsTrue(inner.Name.StartsWith("HANDLE", StringComparison.Ordinal));
                var outerMask = outer.GetAttributes().Single(attribute => attribute.AttributeClass!.Name == "SupportedArchitectureAttribute")
                    .ConstructorArguments.Single().Value;
                var innerMask = inner.GetAttributes().Single(attribute => attribute.AttributeClass!.Name == "SupportedArchitectureAttribute")
                    .ConstructorArguments.Single().Value;
                Assert.AreEqual(outerMask, innerMask);
            }
        }

        [TestMethod]
        public void AuthoredSuffixesCannotProveARecordArchitectureFamily()
        {
            using var fixture = new Fixture("crossarch");
            fixture.Write("autotypes.cs", "");
            const string alias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe partial struct HANDLE {
    [NativeTypeName(""RECORD *"")] public global::Test.RECORD____1* Value;
}}";
            foreach (string arch in new[] { "x86", "x64", "arm64" })
            {
                string record = arch == "x86" ? "RECORD____1" : "RECORD____2";
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, arch, "Bindings.header-types.cs"),
                    alias.Replace("RECORD____1", record));
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, arch, "Bindings.cs"),
                    "namespace Test { public partial struct " + record + " { public int value; } }");
            }
            string common = Path.Combine(fixture.DirectoryPath, "common");
            Directory.CreateDirectory(common);
            File.WriteAllText(Path.Combine(common, "Extra.header-types.cs"), alias);
            StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() => fixture.Compile()).Message, "Value storage");
        }

        [DataTestMethod]
        [DataRow("x64", "Test.Devices.1234", false)]
        [DataRow("crossarch", "Test.Devices .5678", false)]
        [DataRow("x64", "Test.Devices.1234", true)]
        [DataRow("crossarch", "Test.Devices .5678", true)]
        public void NumericNamespacePartitionsKeepTheirEstablishedEffectiveOwner(string architecture, string configuredNamespace,
            bool sourceProven)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("namespace Test", "namespace " + configuredNamespace) +
                (sourceProven ? TypedefProvider(fixture, "Test.Devices", "numeric-native", traversed: true)
                    .Replace("using Windows.Win32.Foundation.Metadata;", "")
                    .Replace("Test.Devices", configuredNamespace) : ""));
            fixture.Write("Bindings.cs", "namespace " + configuredNamespace +
                " { public struct RECORD { public int value; } public static partial class Apis { public const int NUMBER = 7; } }");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Test.Devices.RECORD"));
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Test.Devices.HANDLE"));
            Assert.IsNotNull(compilation.CSharpCompilation.GetTypeByMetadataName("Test.Devices.Apis"));
            foreach (var tree in compilation.CSharpCompilation.SyntaxTrees)
                Assert.AreEqual(0, tree.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "NumericNamespace.winmd");
            ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var names = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Test.Devices")
                .Select(type => reader.GetString(type.Name)).ToArray();
            CollectionAssert.IsSubsetOf(new[] { "RECORD", "HANDLE", "Apis" }, names);
            if (sourceProven)
                Assert.AreEqual(1, names.Count(name => name == "SCALAR"));
        }

        [DataTestMethod]
        [DataRow("x86", true, false, false)]
        [DataRow("x64", true, false, false)]
        [DataRow("arm64", true, false, false)]
        [DataRow("crossarch", true, false, false)]
        [DataRow("x64", false, false, false)]
        [DataRow("x64", true, true, false)]
        [DataRow("x86", true, false, true)]
        [DataRow("x64", true, false, true)]
        [DataRow("arm64", true, false, true)]
        [DataRow("crossarch", true, false, true)]
        public void RetainedTypedefOwnerKeepsDistinctSameBasenameNativeDeclarations(string architecture, bool retained,
            bool conflictingStorage, bool closeApiOwner)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            if (retained && !closeApiOwner)
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "autotypes.cs"),
                    "using Windows.Win32.Foundation.Metadata; namespace Canonical {" +
                    "[NativeTypedef] public struct SCALAR { public int Value; }}");
            foreach (var provider in new[] { (File: "Bindings", Namespace: "First", Header: "one", Line: 10U),
                (File: "Other", Namespace: "Second", Header: "two", Line: 20U) })
            {
                string source = TypedefProvider(fixture, provider.Namespace, "c:main.cpp@T@SCALAR", traversed: true,
                    storage: conflictingStorage && provider.File == "Other" ? "uint" : "int", line: provider.Line);
                var root = CSharpSyntaxTree.ParseText(source).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var proof = NativeTypedefSourceProvenance.Read(declaration)! with
                {
                    Header = Path.Combine(fixture.DirectoryPath, provider.Header, "main.cpp"),
                };
                fixture.Write(provider.File + ".header-types.cs", root.ReplaceNode(declaration,
                    NativeTypedefSourceProvenance.Attach(declaration.WithTrailingTrivia(default(SyntaxTriviaList)), proof)).ToFullString());
            }
            if (!retained || conflictingStorage)
            {
                var error = Assert.ThrowsException<InvalidDataException>(() =>
                    fixture.Compile(retained ? new() { ["SCALAR"] = "Canonical" } : new()));
                StringAssert.Contains(error.Message, conflictingStorage ? "Value storage" : "Conflicting native record identities");
                return;
            }
            string output = Path.Combine(fixture.DirectoryPath, "RetainedNativeOwner.winmd");
            if (closeApiOwner)
            {
                fixture.Write("Close.cs", "using System.Runtime.InteropServices; namespace Canonical {" +
                    "public static partial class Apis { [DllImport(\"native.dll\")] public static extern int Close(SCALAR value); }}");
                string autoTypes = Path.Combine(fixture.DirectoryPath, "autotypes.json");
                File.WriteAllText(autoTypes, "[{\"Name\":\"SCALAR\",\"ValueType\":\"int\",\"CloseApi\":\"Close\"," +
                    "\"InvalidHandleValues\":[0],\"NativeTypedef\":true}]");
                Assert.AreEqual(0, Program.Main(new[] { "--sourceDir", fixture.DirectoryPath, "--arch", architecture,
                    "--outputFileName", output, "--autoTypes", autoTypes }));
            }
            else
            {
                var compilation = fixture.Compile(new() { ["SCALAR"] = "Canonical" });
                var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
                Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
                var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                    compilation, new(), new(), new(), new Version(1, 0), output);
                Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            }
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var scalar = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "SCALAR");
            Assert.AreEqual("Canonical", reader.GetString(scalar.Namespace));
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(scalar.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.Int32, signature.ReadSignatureTypeCode());
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("Test.Devices.1234.Other", "public int value;")]
        [DataRow("Test.Devices.1234", "public int value public int other;")]
        public void NamespaceCompatibilityDoesNotHideMalformedSource(string configuredNamespace, string field)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", HeaderAlias.Replace("namespace Test", "namespace " + configuredNamespace));
            fixture.Write("Bindings.cs", "namespace " + configuredNamespace + " { public struct RECORD { " + field + " } }");
            var error = Assert.ThrowsException<InvalidOperationException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "emitter.source-syntax-preflight");
        }

        [DataTestMethod]
        [DataRow("x64")]
        [DataRow("crossarch")]
        public void MovedDeclarationsKeepTheirOriginalNativeAliasBindings(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public struct NATIVE { public uint Value; } }
namespace Foreign { [NativeTypedef] public struct NATIVE { public byte Value; } }");
            fixture.Write("NativeEnums.cs", @"
namespace Test { public enum INPUT_KIND { Primary = 1 } }
namespace Foreign { public enum INPUT_KIND { Other = 2 } }");
            fixture.Write("Bindings.cs", @"
using Foreign;
using System.Runtime.InteropServices;
namespace Test {
    public struct RECORD { public NATIVE Value; public INPUT_KIND Kind; }
    public delegate NATIVE CALLBACK(NATIVE value);
    public static partial class Apis { [DllImport(""test"")] public static extern NATIVE Read(NATIVE value); }
}");
            var compilation = fixture.Compile(new()
            {
                ["RECORD"] = "Canonical", ["CALLBACK"] = "Canonical", ["Read"] = "Canonical",
            });
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var native = compilation.CSharpCompilation.GetTypeByMetadataName("Test.NATIVE")!;
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.RECORD")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(native, record.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            var enumeration = compilation.CSharpCompilation.GetTypeByMetadataName("Test.INPUT_KIND")!;
            var foreignEnumeration = compilation.CSharpCompilation.GetTypeByMetadataName("Foreign.INPUT_KIND")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(enumeration,
                record.GetMembers("Kind").OfType<IFieldSymbol>().Single().Type));
            Assert.IsFalse(SymbolEqualityComparer.Default.Equals(enumeration, foreignEnumeration));
            foreach (var method in new[]
            {
                compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.CALLBACK")!.DelegateInvokeMethod!,
                compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.Apis")!.GetMembers("Read").OfType<IMethodSymbol>().Single(),
            })
            {
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(native, method.ReturnType));
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(native, method.Parameters.Single().Type));
            }
        }

        [TestMethod]
        public void HeaderAliasesUseActualDependencyNamespacesAndFrameworkImports()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
    [NativeTypedef] public unsafe struct POINTER { [NativeTypeName(""RECORD *"")] public RECORD* Value; }
    [NativeTypedef] public struct IDENTIFIER { public Guid Value; }
}");
            fixture.Write("Bindings.cs", "namespace Dependency { public struct RECORD { public int value; } }");
            var compilation = fixture.Compile(apiNamesToNamespaces: new() { ["RECORD"] = "Dependency" });
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Dependency.RECORD")!;
            var pointer = (IPointerTypeSymbol)compilation.CSharpCompilation.GetTypeByMetadataName("Test.POINTER")!
                .GetMembers("Value").OfType<IFieldSymbol>().Single().Type;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(record, pointer.PointedAtType));
            Assert.AreEqual("System.Guid", compilation.CSharpCompilation.GetTypeByMetadataName("Test.IDENTIFIER")!
                .GetMembers("Value").OfType<IFieldSymbol>().Single().Type.ToDisplayString());
        }

        [TestMethod]
        public void RetainedComposedNativeAliasesStillLowerConstantCastsAndEnumBacking()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public struct STATUS { public int Value; } }");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
    [NativeTypedef] public struct STATUS { [NativeTypeName(""int"")] public int Value; }
    [NativeTypedef] public struct STORAGE { public uint Value; }
}");
            fixture.Write("Bindings.cs", @"
namespace Test {
    public enum ERRORS : int { Failure = unchecked((int)((STATUS)0x80000000u)) }
    public enum VALUES : STORAGE { First = 1 }
}");
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.AreEqual(int.MinValue, compilation.CSharpCompilation.GetTypeByMetadataName("Test.ERRORS")!
                .GetMembers("Failure").OfType<IFieldSymbol>().Single().ConstantValue);
            Assert.AreEqual(SpecialType.System_UInt32,
                compilation.CSharpCompilation.GetTypeByMetadataName("Test.VALUES")!.EnumUnderlyingType!.SpecialType);
            Assert.AreEqual(TypeKind.Struct, compilation.CSharpCompilation.GetTypeByMetadataName("Test.STATUS")!.TypeKind);
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void QualifiedFrameworkDelegateReturnRemapsDoNotRequireSystemImports(string architecture)
        {
            using var fixture = new Fixture(architecture);
            const string attribute = "[global::System.Runtime.InteropServices.UnmanagedFunctionPointer(" +
                "global::System.Runtime.InteropServices.CallingConvention.Winapi)]";
            string[] names = { "FARPROC", "NEARPROC", "PROC" };
            fixture.Write("Bindings.cs", "using Windows.Win32.Foundation.Metadata; namespace Test { " + string.Join(" ", names.Select(name =>
                attribute + " public delegate int " + name + "();")) + " }");
            var compilation = fixture.Compile(remaps: names.ToDictionary(name => name + "::return",
                _ => "global::System.IntPtr", StringComparer.Ordinal));
            var errors = compilation.CSharpCompilation.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            foreach (string name in names)
                Assert.AreEqual(SpecialType.System_IntPtr,
                    compilation.CSharpCompilation.GetTypeByMetadataName("Test." + name)!.DelegateInvokeMethod!.ReturnType.SpecialType);
            string output = Path.Combine(fixture.DirectoryPath, "ProcedureReturns.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (string name in names)
            {
                var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Name) == name);
                var invoke = physical.GetMethods().Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == "Invoke");
                var signature = reader.GetBlobReader(invoke.Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(0, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.IntPtr, signature.ReadSignatureTypeCode());
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow("x86", false, false)]
        [DataRow("x64", false, false)]
        [DataRow("arm64", false, false)]
        [DataRow("crossarch", false, false)]
        [DataRow("crossarch", true, false)]
        [DataRow("x86", false, true)]
        [DataRow("x64", false, true)]
        [DataRow("arm64", false, true)]
        [DataRow("crossarch", false, true)]
        [DataRow("crossarch", true, true)]
        public void ExplicitMemberTypeRemapsSurviveCompetingNativeAliases(string architecture, bool regex, bool rename)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            string[] targets = architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { architecture };
            const string ns = "Windows.Win32.Foundation";
            const string nativeOwner = "Windows.Win32.System.ApplicationInstallationAndServicing";
            string[] names = { "FARPROC", "NEARPROC", "PROC" };
            foreach (string target in targets)
            {
                string providers = TypedefProvider(fixture, nativeOwner, "native-int", true).Replace("SCALAR", "INT") +
                    TypedefProvider(fixture, nativeOwner, "native-int-ptr", true, "global::System.IntPtr",
                        target == "x86" ? 4 : 8, target == "x86" ? 4 : 8, line: 2).Replace("SCALAR", "INT_PTR")
                        .Replace("using Windows.Win32.Foundation.Metadata;", "");
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target, "Bindings.header-types.cs"), providers);
                string returnType = target == "x86" ? "int" : "IntPtr";
                string returnAttribute = target == "x86" ? "" : "[return: NativeTypeName(\"INT_PTR\")]";
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, target, "Bindings.cs"),
                    "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata; namespace " + ns + " { " +
                    string.Join(" ", names.Select(name => "[UnmanagedFunctionPointer(CallingConvention.StdCall)] " +
                        returnAttribute + " public delegate " + returnType + " " + name + "();")) + @"
[return: NativeTypeName(""INT"")] public delegate int UNMAPPED();
public partial struct CARRIER {
    [NativeTypeName(""INT"")] public int Value;
    [NativeTypeName(""INT"")] public int UnmappedValue;
}
public static partial class Apis {
    [DllImport(""test"")] [return: NativeTypeName(""INT"")]
    public static extern int Retyped([NativeTypeName(""INT"")] int value);
    [DllImport(""test"")] public static extern void KeepNative([NativeTypeName(""INT"")] int value);
} }");
            }
            var remaps = names.ToDictionary(name => name + "::return", _ => "global::System.IntPtr", StringComparer.Ordinal);
            if (regex)
            {
                remaps.Clear();
                remaps["^(FARPROC|NEARPROC|PROC)::return$"] = "global::System.IntPtr";
            }
            remaps[regex ? "^CARRIER::Value$" : "CARRIER::Value"] =
                "global::System.IntPtr" + (rename ? " Selected" : "");
            remaps["Retyped::return"] = "global::System.IntPtr";
            remaps[regex ? "^Retyped::value$" : "Retyped::value"] =
                "global::System.IntPtr" + (rename ? " renamed" : "");
            remaps[regex ? "^CARRIER::UnmappedValue$" : "CARRIER::UnmappedValue"] = "[Const]";
            remaps[regex ? "^KeepNative::value$" : "KeepNative::value"] = "[In]";
            var compilation = fixture.Compile(remaps: remaps);
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            string fieldName = rename ? "Selected" : "Value";
            string parameterName = rename ? "renamed" : "value";
            var boundCarrier = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".CARRIER")!;
            var boundField = boundCarrier.GetMembers(fieldName).OfType<IFieldSymbol>().Single();
            var boundMethod = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".Apis")!
                .GetMembers("Retyped").OfType<IMethodSymbol>().Single();
            Assert.AreEqual(SpecialType.System_IntPtr, boundField.Type.SpecialType);
            Assert.AreEqual(SpecialType.System_IntPtr, boundMethod.Parameters.Single().Type.SpecialType);
            Assert.AreEqual(parameterName, boundMethod.Parameters.Single().Name);
            foreach (string name in names)
            {
                var procedure = compilation.CSharpCompilation.GetTypeByMetadataName(ns + "." + name)!;
                Assert.AreEqual(SpecialType.System_IntPtr,
                    procedure.DelegateInvokeMethod!.ReturnType.SpecialType);
                var native = procedure.DelegateInvokeMethod.GetReturnTypeAttributes()
                    .Single(attribute => attribute.AttributeClass!.Name == "NativeTypeNameAttribute");
                Assert.AreEqual(architecture == "x64" || architecture == "arm64" ? "INT_PTR" : "INT",
                    native.ConstructorArguments[0].Value);
                Assert.AreEqual((int)System.Runtime.InteropServices.CallingConvention.Winapi, procedure.GetAttributes().Single(attribute =>
                    attribute.AttributeClass!.Name == "UnmanagedFunctionPointerAttribute").ConstructorArguments[0].Value);
            }
            string output = Path.Combine(fixture.DirectoryPath, "ExplicitNativeRemaps.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (string name in names)
            {
                var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == name);
                Assert.AreEqual(7, physical.GetCustomAttributes().Any(attribute =>
                    AttributeName(reader, attribute) == "SupportedArchitectureAttribute") ? ReadArchitecture(reader, physical) : 7);
                var invoke = physical.GetMethods().Select(reader.GetMethodDefinition)
                    .Single(method => reader.GetString(method.Name) == "Invoke");
                CollectionAssert.AreEqual(new byte[] { 0x20, 0x00, 0x18 }, reader.GetBlobBytes(invoke.Signature));
            }
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == "CARRIER");
            var selectedField = carrier.GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == fieldName);
            var retyped = reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "Retyped");
            Assert.AreEqual("0618|00011818", Convert.ToHexString(reader.GetBlobBytes(selectedField.Signature)) + "|" +
                Convert.ToHexString(reader.GetBlobBytes(retyped.Signature)));
            Assert.AreEqual(parameterName, retyped.GetParameters().Select(reader.GetParameter)
                .Where(parameter => parameter.SequenceNumber != 0).Select(parameter => reader.GetString(parameter.Name)).Single());
            var untouchedField = carrier.GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "UnmappedValue");
            var untouchedSignature = reader.GetBlobReader(untouchedField.Signature);
            Assert.AreEqual(SignatureKind.Field, untouchedSignature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, untouchedSignature.ReadSignatureTypeCode());
            Assert.AreEqual(nativeOwner + ".INT", PhysicalName(untouchedSignature.ReadTypeHandle()));
            Assert.AreEqual(0, untouchedSignature.RemainingBytes);
            var keepNative = reader.GetBlobReader(reader.MethodDefinitions.Select(reader.GetMethodDefinition)
                .Single(method => reader.GetString(method.Name) == "KeepNative").Signature);
            keepNative.ReadSignatureHeader();
            Assert.AreEqual(1, keepNative.ReadCompressedInteger());
            Assert.AreEqual(SignatureTypeCode.Void, keepNative.ReadSignatureTypeCode());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, keepNative.ReadSignatureTypeCode());
            Assert.AreEqual(nativeOwner + ".INT", PhysicalName(keepNative.ReadTypeHandle()));
            Assert.AreEqual(0, keepNative.RemainingBytes);
            var unmapped = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Namespace) == ns && reader.GetString(type.Name) == "UNMAPPED");
            var unmappedInvoke = reader.GetBlobReader(reader.GetMethodDefinition(unmapped.GetMethods()
                .Single(method => reader.GetString(reader.GetMethodDefinition(method).Name) == "Invoke")).Signature);
            unmappedInvoke.ReadSignatureHeader();
            Assert.AreEqual(0, unmappedInvoke.ReadCompressedInteger());
            Assert.AreEqual(SignatureTypeCode.TypeHandle, unmappedInvoke.ReadSignatureTypeCode());
            var nativeInt = ResolveLocalType(reader, unmappedInvoke.ReadTypeHandle());
            Assert.AreEqual(nativeOwner, reader.GetString(nativeInt.Namespace));
            Assert.AreEqual("INT", reader.GetString(nativeInt.Name));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x08 },
                reader.GetBlobBytes(reader.GetFieldDefinition(nativeInt.GetFields().Single()).Signature));

            string PhysicalName(EntityHandle handle)
            {
                var type = ResolveLocalType(reader, handle);
                return reader.GetString(type.Namespace) + "." + reader.GetString(type.Name);
            }
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void DelegateTypeRemapsAddUnsafeOnlyWhenRequired(bool returnsPointer)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.cs", "using Windows.Win32.Foundation.Metadata; namespace Test { public delegate int CALLBACK(int value); public delegate int PLAIN(int value); }");
            var compilation = fixture.Compile(remaps: new()
            {
                [returnsPointer ? "CALLBACK::return" : "CALLBACK::value"] = "byte*",
            });
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var callback = compilation.CSharpCompilation.GetTypeByMetadataName("Test.CALLBACK")!;
            var declaration = (DelegateDeclarationSyntax)callback.DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.IsTrue(declaration.Modifiers.Any(SyntaxKind.UnsafeKeyword));
            Assert.AreEqual(TypeKind.Pointer, (returnsPointer ? callback.DelegateInvokeMethod!.ReturnType :
                callback.DelegateInvokeMethod!.Parameters.Single().Type).TypeKind);
            var plain = (DelegateDeclarationSyntax)compilation.CSharpCompilation.GetTypeByMetadataName("Test.PLAIN")!
                .DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.IsFalse(plain.Modifiers.Any(SyntaxKind.UnsafeKeyword));
        }

        [DataTestMethod]
        [DataRow("uint", false, false)]
        [DataRow("int", true, false)]
        [DataRow("uint", false, true)]
        public void BoundLegacyEnumProjectionRetainsItsMetadataOwner(string nativeStorage, bool explicitProjection, bool manual)
        {
            using var fixture = new Fixture("crossarch");
            AddLegacyEnumProjection(fixture, nativeStorage, explicitProjection, manual);
            var compilation = fixture.Compile(new() { ["FLAGS"] = "Canonical" },
                explicitProjection ? new() { ["Project::value"] = "FLAGS" } : null);
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var owner = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.FLAGS")!;
            Assert.AreEqual(TypeKind.Enum, owner.TypeKind);
            Assert.AreEqual(SpecialType.System_UInt32, owner.EnumUnderlyingType!.SpecialType);
            Assert.AreEqual(1, owner.DeclaringSyntaxReferences.Length);
            var method = compilation.CSharpCompilation.GetTypeByMetadataName("Test.Apis")!
                .GetMembers("Project").OfType<IMethodSymbol>().Single();
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(owner, method.Parameters.Single().Type));
            string output = Path.Combine(fixture.DirectoryPath, "LegacyProjection.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var definition = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Namespace) == "Canonical" && reader.GetString(type.Name) == "FLAGS");
            var storage = reader.GetFieldDefinition(definition.GetFields().Single(field =>
                reader.GetString(reader.GetFieldDefinition(field).Name) == "value__"));
            var signature = reader.GetBlobReader(storage.Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.UInt32, signature.ReadSignatureTypeCode());
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        public void InferredNativeOwnerDoesNotOverrideABoundLegacyEnumProjection(string architecture, bool sameDeclaration)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", TypedefProvider(fixture, "Other", "other-flags",
                traversed: true, storage: sameDeclaration ? "uint" : "int").Replace("SCALAR", "FLAGS") +
                (sameDeclaration ? "" : @"
namespace Canonical {
[global::Windows.Win32.Foundation.Metadata.NativeTypedef]
public struct FLAGS { public uint Value; } }"));
            if (sameDeclaration)
                fixture.Write("Canonical.header-types.cs", TypedefProvider(fixture, "Canonical", "other-flags",
                    traversed: false, storage: "uint").Replace("SCALAR", "FLAGS"));
            fixture.Write("Bindings.enums.cs", "namespace Canonical { public enum FLAGS : uint { First = 1 } }");
            fixture.Write("Bindings.cs", @"using System.Runtime.InteropServices;
namespace Canonical { public static partial class Apis {
[DllImport(""legacy.dll"")] public static extern void Project(FLAGS value); } }
namespace Other { public static partial class Apis {
[DllImport(""other.dll"")] public static extern void KeepNative(FLAGS value); } }");
            var compilation = fixture.Compile();
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
            var enumeration = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.FLAGS");
            var native = compilation.CSharpCompilation.GetTypeByMetadataName("Other.FLAGS");
            Assert.IsNotNull(enumeration);
            Assert.AreEqual(TypeKind.Enum, enumeration.TypeKind);
            Assert.AreEqual(SpecialType.System_UInt32, enumeration.EnumUnderlyingType!.SpecialType);
            if (sameDeclaration)
                Assert.IsNull(native);
            else
            {
                Assert.AreEqual(TypeKind.Struct, native!.TypeKind);
                Assert.AreEqual(SpecialType.System_Int32, native.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);
            }
            foreach (var expected in new[] { (Namespace: "Canonical", Method: "Project", Type: enumeration),
                (Namespace: "Other", Method: "KeepNative", Type: sameDeclaration ? enumeration : native) })
            {
                var method = compilation.CSharpCompilation.GetTypeByMetadataName(expected.Namespace + ".Apis")!
                    .GetMembers(expected.Method).OfType<IMethodSymbol>().Single();
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(expected.Type, method.Parameters.Single().Type));
            }
            string output = Path.Combine(fixture.DirectoryPath, "DistinctEnumOwner.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == "FLAGS").ToArray();
            Assert.AreEqual(sameDeclaration ? 1 : 2, types.Length);
            var expectedTypes = new[] { (Namespace: "Canonical", Field: "value__", Code: (byte)0x09),
                (Namespace: "Other", Field: "Value", Code: (byte)0x08) };
            foreach (var expected in expectedTypes.Take(sameDeclaration ? 1 : 2))
            {
                var type = types.Single(type => reader.GetString(type.Namespace) == expected.Namespace);
                var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                Assert.AreEqual(expected.Namespace == "Canonical" ? 2 : 1, fields.Length);
                var field = fields.Single(field => reader.GetString(field.Name) == expected.Field);
                Assert.AreEqual(expected.Field, reader.GetString(field.Name));
                CollectionAssert.AreEqual(new byte[] { 0x06, expected.Code }, reader.GetBlobBytes(field.Signature));
            }
            foreach (var expected in new[] { (Namespace: "Canonical", Method: "Project"),
                (Namespace: "Other", Method: "KeepNative") })
            {
                var apis = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == expected.Namespace && reader.GetString(type.Name) == "Apis");
                var method = apis.GetMethods().Select(reader.GetMethodDefinition).Single(definition =>
                    reader.GetString(definition.Name) == expected.Method);
                var signature = reader.GetBlobReader(method.Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                Assert.AreEqual(SignatureTypeCode.Void, signature.ReadSignatureTypeCode());
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var binding = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual("FLAGS", reader.GetString(binding.Name));
                Assert.AreEqual(sameDeclaration ? "Canonical" : expected.Namespace, reader.GetString(binding.Namespace));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [TestMethod]
        public void InferredNativeOwnerRejectsAmbiguousObservedLegacyEnumOwners()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            foreach (string ns in new[] { "Native", "First", "Second" })
                fixture.Write(ns + ".header-types.cs", TypedefProvider(fixture, ns, "shared-flags",
                    traversed: ns == "Native", storage: "uint").Replace("SCALAR", "FLAGS"));
            foreach (string ns in new[] { "First", "Second" })
                fixture.Write(ns + ".enums.cs", "namespace " + ns + " { public enum FLAGS : uint { First = 1 } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CSSW005");
            StringAssert.Contains(error.Message, "multiple observed retained metadata owners");
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void NativeTypeNamesKeepTheirContextBoundIndependentAliasProviders(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            foreach (var provider in new[] { (Namespace: "First", Storage: "int"), (Namespace: "Second", Storage: "uint") })
            {
                fixture.Write(provider.Namespace + ".header-types.cs", TypedefProvider(fixture, provider.Namespace,
                    provider.Namespace + "-integer", traversed: true, storage: provider.Storage).Replace("SCALAR", "INT"));
                fixture.Write(provider.Namespace + ".cs", @"
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace " + provider.Namespace + @" {
public struct CARRIER { [NativeTypeName(""INT"")] public " + provider.Storage + @" Value; }
public static class Apis {
[DllImport(""native.dll"")] [return: NativeTypeName(""INT"")]
public static extern " + provider.Storage + @" Use([NativeTypeName(""INT"")] " + provider.Storage + @" value);
} }");
            }
            var compilation = fixture.Compile();
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            string output = Path.Combine(fixture.DirectoryPath, "ContextBoundNativeAliases.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            foreach (string ns in new[] { "First", "Second" })
            {
                var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type =>
                    reader.GetString(type.Namespace) == ns).ToArray();
                var carrier = types.Single(type => reader.GetString(type.Name) == "CARRIER");
                var field = reader.GetFieldDefinition(carrier.GetFields().Single());
                var signature = reader.GetBlobReader(field.Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                AssertAlias(ref signature, ns);
                Assert.AreEqual(0, signature.RemainingBytes);
                var apis = types.Single(type => reader.GetString(type.Name) == "Apis");
                var method = apis.GetMethods().Select(reader.GetMethodDefinition).Single(definition =>
                    reader.GetString(definition.Name) == "Use");
                signature = reader.GetBlobReader(method.Signature);
                Assert.AreEqual(SignatureKind.Method, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(1, signature.ReadCompressedInteger());
                AssertAlias(ref signature, ns);
                AssertAlias(ref signature, ns);
                Assert.AreEqual(0, signature.RemainingBytes);
            }

            void AssertAlias(ref BlobReader signature, string ns)
            {
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var binding = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual("INT", reader.GetString(binding.Name));
                Assert.AreEqual(ns, reader.GetString(binding.Namespace));
            }
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        public void InferredNativeIdentitiesPreserveIntrinsicUseSitesAndNominalStorage(string architecture, bool retainedEvidence)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            foreach (var provider in new[] { (Namespace: "First", Storage: "int", Code: (byte)0x08),
                (Namespace: "Second", Storage: "uint", Code: (byte)0x09) })
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, provider.Namespace,
                    provider.Namespace + "-native", true, provider.Storage)
                    .Replace("native::SCALAR", "SCALAR").Replace("SCALAR", "INT")).GetRoot();
                if (!retainedEvidence)
                {
                    var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                    root = root.ReplaceNode(declaration,
                        NativeTypedefProjectionProvenance.WithPolicy(declaration, inferred: true));
                }
                fixture.Write(provider.Namespace + ".header-types.cs", root.ToFullString());
                if (retainedEvidence)
                    fixture.Write(provider.Namespace + ".native-declarations.json",
                        "{\"schemaVersion\":1,\"primaryFlags\":\"12288\",\"projectionCompleted\":true}");
                fixture.Write(provider.Namespace + ".cs", @"
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace " + provider.Namespace + @" {
public struct CARRIER { [NativeTypeName(""INT"")] public INT Value; }
public static class Apis {
[DllImport(""native.dll"")] [return: NativeTypeName(""INT"")]
public static extern INT Use([NativeTypeName(""INT"")] INT value);
} }");
            }
            var nominal = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, "First",
                "nominal-native", true, "INT").Replace("SCALAR", "NOMINAL")).GetRoot();
            var nominalDeclaration = nominal.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            nominal = nominal.ReplaceNode(nominalDeclaration,
                NativeTypedefProjectionProvenance.WithPolicy(nominalDeclaration, inferred: false));
            fixture.Write("Nominal.header-types.cs", nominal.ToFullString());
            var compilation = fixture.Compile();
            foreach (string ns in new[] { "First", "Second" })
            {
                var alias = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".INT")!;
                Assert.AreEqual(ns + "-native",
                    NativeTypedefSourceProvenance.Read((StructDeclarationSyntax)alias.DeclaringSyntaxReferences.Single().GetSyntax()).Identity);
                var carrier = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".CARRIER")!;
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(alias,
                    carrier.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            }
            string output = Path.Combine(fixture.DirectoryPath, "IntrinsicUseSites.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition).ToArray();
            foreach (var expected in new[] { (Namespace: "First", Code: (byte)0x08),
                (Namespace: "Second", Code: (byte)0x09) })
            {
                var carrier = types.Single(type => reader.GetString(type.Namespace) == expected.Namespace &&
                    reader.GetString(type.Name) == "CARRIER");
                CollectionAssert.AreEqual(new byte[] { 0x06, expected.Code },
                    reader.GetBlobBytes(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature));
                var apis = types.Single(type => reader.GetString(type.Namespace) == expected.Namespace &&
                    reader.GetString(type.Name) == "Apis");
                CollectionAssert.AreEqual(new byte[] { 0x00, 0x01, expected.Code, expected.Code },
                    reader.GetBlobBytes(reader.GetMethodDefinition(apis.GetMethods().Single()).Signature));
            }
            Assert.AreEqual(1, types.Count(type => reader.GetString(type.Name) == "INT"));
            var retained = types.Single(type => reader.GetString(type.Name) == "INT");
            Assert.AreEqual("First", reader.GetString(retained.Namespace));
            var nativeStorage = types.Single(type => reader.GetString(type.Name) == "NOMINAL");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(nativeStorage.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            Assert.AreEqual("First", reader.GetString(ResolveLocalType(reader, signature.ReadTypeHandle()).Namespace));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        public void InferredAliasesPreserveTheirRetainedNominalUseTarget(string architecture, bool pointerSized)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", @"
namespace Canonical {
[global::Windows.Win32.Foundation.Metadata.NativeTypedef]
public struct RETAINED { public " + (pointerSized ? "System.IntPtr" : "byte") + @" Value; }
}");
            var target = architecture switch
            {
                "x86" => MetadataUtils.Architecture.X86,
                "x64" => MetadataUtils.Architecture.X64,
                _ => MetadataUtils.Architecture.Arm64,
            };
            int width = pointerSized ? target == MetadataUtils.Architecture.X86 ? 4 : 8 : 1;
            foreach (string ns in new[] { "First", "Second" })
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, ns, ns + "-native", true,
                    "global::Canonical.RETAINED", width, width)).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                var source = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = target };
                var provider = NativeTypedefSourceProvenance.Attach(
                    declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source);
                fixture.Write(ns + ".header-types.cs", root.ReplaceNode(declaration,
                    NativeTypedefProjectionProvenance.WithPolicy(provider, inferred: true)).ToFullString());
                fixture.Write(ns + ".cs", "namespace " + ns +
                    " { public struct " + ns + "Carrier { public SCALAR Value; } }");
            }
            var compilation = fixture.Compile();
            foreach (string ns in new[] { "First", "Second" })
            {
                var provider = compilation.CSharpCompilation.GetTypeByMetadataName(ns + ".SCALAR")!;
                Assert.AreEqual(ns + "-native", NativeTypedefSourceProvenance.Read(
                    (StructDeclarationSyntax)provider.DeclaringSyntaxReferences.Single().GetSyntax()).Identity);
                Assert.AreEqual("Canonical.RETAINED",
                    provider.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.ToDisplayString());
            }
            string output = Path.Combine(fixture.DirectoryPath, "RetainedAliasTargets.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition).ToArray();
            Assert.AreEqual(0, types.Count(type => reader.GetString(type.Name) == "SCALAR"));
            Assert.AreEqual(1, types.Count(type => reader.GetString(type.Name) == "RETAINED"));
            foreach (string ns in new[] { "First", "Second" })
            {
                var carrier = types.Single(type => reader.GetString(type.Name) == ns + "Carrier");
                var signature = reader.GetBlobReader(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
                var retained = ResolveLocalType(reader, signature.ReadTypeHandle());
                Assert.AreEqual("Canonical", reader.GetString(retained.Namespace));
                Assert.AreEqual("RETAINED", reader.GetString(retained.Name));
                Assert.AreEqual(0, signature.RemainingBytes);
            }
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        public void InferredPointerFixedBuffersPreserveElementPointerDepth(string architecture)
        {
            using var fixture = new Fixture(architecture);
            fixture.Write("autotypes.cs", "");
            var target = architecture switch
            {
                "x86" => MetadataUtils.Architecture.X86,
                "x64" => MetadataUtils.Architecture.X64,
                _ => MetadataUtils.Architecture.Arm64,
            };
            int width = target == MetadataUtils.Architecture.X86 ? 4 : 8;
            var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, "Test", "native-pointer",
                true, "void*", width, width).Replace("SCALAR", "PVOID")
                .Replace("public partial struct", "public unsafe partial struct")).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            var source = NativeTypedefSourceProvenance.Read(declaration)! with { SourceArchitecture = target };
            var provider = NativeTypedefSourceProvenance.Attach(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList)), source);
            fixture.Write("Bindings.header-types.cs", root.ReplaceNode(declaration,
                NativeTypedefProjectionProvenance.WithPolicy(provider, inferred: true)).ToFullString());
            fixture.Write("Buffers.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
public unsafe partial struct POINTER_BUFFERS {
    [NativeTypeName(""PVOID[1]"")]
    public _Single_e__FixedBuffer Single;
    [NativeTypeName(""PVOID[8]"")]
    public _Reserved_e__FixedBuffer Reserved;
    [NativeTypeName(""PVOID *[2]"")]
    public _Indirect_e__FixedBuffer Indirect;
    [NativeTypeName(""int *[2]"")]
    public _Direct_e__FixedBuffer Direct;
    public partial struct _Single_e__FixedBuffer { public PVOID e0; }
    public partial struct _Reserved_e__FixedBuffer {
        public PVOID e0;
        public PVOID e1;
        public PVOID e2;
        public PVOID e3;
        public PVOID e4;
        public PVOID e5;
        public PVOID e6;
        public PVOID e7;
    }
    public unsafe partial struct _Indirect_e__FixedBuffer { public PVOID* e0; public PVOID* e1; }
    public unsafe partial struct _Direct_e__FixedBuffer { public int* e0; public int* e1; }
}
}");
            var compilation = fixture.Compile();
            string output = Path.Combine(fixture.DirectoryPath, "PointerBuffers.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "POINTER_BUFFERS");
            var fields = carrier.GetFields().Select(reader.GetFieldDefinition)
                .ToDictionary(field => reader.GetString(field.Name));
            foreach (var expected in new[]
            {
                (Name: "Single", Element: new byte[] { 0x0F, 0x01 }, Count: (byte)1),
                (Name: "Reserved", Element: new byte[] { 0x0F, 0x01 }, Count: (byte)8),
                (Name: "Indirect", Element: new byte[] { 0x0F, 0x0F, 0x01 }, Count: (byte)2),
                (Name: "Direct", Element: new byte[] { 0x0F, 0x08 }, Count: (byte)2),
            })
                CollectionAssert.AreEqual(new byte[] { 0x06, 0x14 }.Concat(expected.Element)
                    .Concat(new byte[] { 0x01, 0x01, expected.Count, 0x01, 0x00 }).ToArray(),
                    reader.GetBlobBytes(fields[expected.Name].Signature), expected.Name);
        }

        [TestMethod]
        public void EmissionDiagnosticsPreserveTheFailingFieldAndOriginalStack()
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("Unsupported.cs", "namespace Test { public struct Unsupported { public decimal Value; } }");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                fixture.Compile(), new(), new(), new(), new Version(1, 0),
                Path.Combine(fixture.DirectoryPath, "Unsupported.winmd"));
            Assert.IsFalse(generator.WroteWinmd);
            string error = string.Join(Environment.NewLine, generator.GetDiagnostics());
            StringAssert.Contains(error, "Failed to encode field Unsupported.Value");
            StringAssert.Contains(error, "System.NotImplementedException");
            StringAssert.Contains(error, "EncodeSpecialType");
            StringAssert.Contains(error, "EncodeFieldSignature");
        }

        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void NominalNativeProjectionIntentSurvivesObservedProviderSelection(bool retainedProvider)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", retainedProvider
                ? "namespace Canonical { [global::Windows.Win32.Foundation.Metadata.NativeTypedef] public struct SCALAR { public int Value; } }" : "");
            foreach (var observation in new[] { (Namespace: "Canonical", Inferred: true, Direct: true),
                (Namespace: "Observed", Inferred: retainedProvider, Direct: false) })
            {
                var root = CSharpSyntaxTree.ParseText(TypedefProvider(fixture, observation.Namespace,
                    "same-native-scalar", observation.Direct)).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                fixture.Write(observation.Namespace + ".header-types.cs",
                    root.ReplaceNode(declaration, NativeTypedefProjectionProvenance.WithPolicy(
                        declaration, observation.Inferred)).ToFullString());
            }
            fixture.Write("Use.cs", @"
namespace Canonical { public struct CARRIER { public SCALAR Value; } }");
            var compilation = fixture.Compile();
            string output = Path.Combine(fixture.DirectoryPath, "NominalIntent.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var carrier = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "CARRIER");
            var signature = reader.GetBlobReader(reader.GetFieldDefinition(carrier.GetFields().Single()).Signature);
            Assert.AreEqual(SignatureKind.Field, signature.ReadSignatureHeader().Kind);
            Assert.AreEqual(SignatureTypeCode.TypeHandle, signature.ReadSignatureTypeCode());
            var binding = ResolveLocalType(reader, signature.ReadTypeHandle());
            Assert.AreEqual("Canonical", reader.GetString(binding.Namespace));
            Assert.AreEqual("SCALAR", reader.GetString(binding.Name));
            Assert.AreEqual(0, signature.RemainingBytes);
        }

        [DataTestMethod]
        [DataRow("unknown-policy")]
        [DataRow("duplicate-policy")]
        [DataRow("failed-native-projection")]
        [DataRow("missing-source")]
        public void NativeProjectionPolicyRequiresUnambiguousSuccessfulSourceEvidence(string scenario)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("Bindings.header-types.cs", "");
            fixture.Write("autotypes.cs", "");
            string provider = scenario == "missing-source"
                ? "namespace Test { public struct SCALAR { public int Value; } }"
                : TypedefProvider(fixture, "Test", "native-scalar", true).Replace("native::SCALAR", "SCALAR");
            string marker = "/* Win32Metadata.NativeTypedefProjection.v1 Inferred */";
            string policy = scenario switch
            {
                "unknown-policy" => marker.Replace("Inferred", "Unknown"),
                "duplicate-policy" => marker + marker,
                "missing-source" => marker,
                _ => "",
            };
            if (policy.Length != 0)
            {
                var root = CSharpSyntaxTree.ParseText(provider).GetRoot();
                var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                provider = root.ReplaceNode(declaration, declaration.WithLeadingTrivia(
                    SyntaxFactory.ParseLeadingTrivia(Environment.NewLine + policy + Environment.NewLine)
                        .AddRange(declaration.GetLeadingTrivia()))).ToFullString();
            }
            if (scenario == "failed-native-projection")
                fixture.Write("Policy.native-declarations.json",
                    "{\"schemaVersion\":1,\"primaryFlags\":\"12288\",\"projectionCompleted\":false}");
            fixture.Write("Policy.header-types.cs", provider);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "CSSW005");
            StringAssert.Contains(error.Message, "emitter.native-typedef-policy");
        }

        [DataTestMethod]
        [DataRow("independent-declarations")]
        [DataRow("conflicting-source")]
        [DataRow("conflicting-storage")]
        public void SelectedLegacyEnumValidatesEachNativeDeclarationFamily(string scenario)
        {
            using var fixture = new Fixture("x64");
            AddLegacyEnumProjection(fixture, "uint", false, false);
            string Provider(string ns, string identity, string storage) => TypedefProvider(fixture, ns, identity, traversed: true,
                storage: storage).Replace("SCALAR", "FLAGS");
            fixture.Write("Bindings.header-types.cs", Provider("Test", "first-flags", "uint"));
            string other = Provider("Other", scenario == "conflicting-source" ? "first-flags" : "second-flags",
                scenario == "conflicting-storage" ? "int" : "uint");
            if (scenario == "conflicting-source")
                other = other.Replace(new string('A', 64), new string('B', 64));
            fixture.Write("Other.header-types.cs", other);
            if (scenario != "independent-declarations")
            {
                StringAssert.Contains(Assert.ThrowsException<InvalidDataException>(() =>
                    fixture.Compile(new() { ["FLAGS"] = "Canonical" })).Message, "CSSW005");
                return;
            }
            var compilation = fixture.Compile(new() { ["FLAGS"] = "Canonical" });
            Assert.AreEqual(0, compilation.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var owner = compilation.CSharpCompilation.GetTypeByMetadataName("Canonical.FLAGS")!;
            Assert.AreEqual(TypeKind.Enum, owner.TypeKind);
            Assert.AreEqual(1, owner.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_UInt32, owner.EnumUnderlyingType!.SpecialType);
            string output = Path.Combine(fixture.DirectoryPath, "NativeFamiliesEnum.winmd");
            var generated = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0), output);
            Assert.IsTrue(generated.WroteWinmd, string.Join(Environment.NewLine, generated.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Single(type => reader.GetString(type.Name) == "FLAGS");
            Assert.AreEqual("Canonical", reader.GetString(physical.Namespace));
            var backing = reader.GetFieldDefinition(physical.GetFields().Single(field =>
                reader.GetString(reader.GetFieldDefinition(field).Name) == "value__"));
            CollectionAssert.AreEqual(new byte[] { 0x06, 0x09 }, reader.GetBlobBytes(backing.Signature));
        }

        [DataTestMethod]
        [DataRow("int", false)]
        [DataRow("ulong", true)]
        [DataRow("void*", true)]
        public void LegacyEnumProjectionDoesNotInferSignednessOrChangeNativeAbi(string storage, bool explicitProjection)
        {
            using var fixture = new Fixture("x64");
            AddLegacyEnumProjection(fixture, storage, explicitProjection, false);
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(
                new() { ["FLAGS"] = "Canonical" }, explicitProjection ? new() { ["Project::value"] = "FLAGS" } : null));
            StringAssert.Contains(error.Message, "legacy enum requires exact native integer storage");
        }

        [TestMethod]
        public void ExplicitEnumProjectionKeepsNativeProviderAndAttributeConflictsRejected()
        {
            using var fixture = new Fixture("x64");
            AddLegacyEnumProjection(fixture, "int", true, false);
            fixture.Write("Other.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public struct FLAGS { public uint Value; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(
                new() { ["FLAGS"] = "Canonical" }, new() { ["Project::value"] = "FLAGS" }));
            StringAssert.Contains(error.Message, "Conflicting native typedef Value storage types");
            fixture.Write("Other.header-types.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public struct FLAGS { [Const] public int Value; } }");
            error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(
                new() { ["FLAGS"] = "Canonical" }, new() { ["Project::value"] = "FLAGS" }));
            StringAssert.Contains(error.Message, "cannot discard native typedef annotations");
        }

        [TestMethod]
        public void LegacyEnumProjectionDoesNotPermitIncompatiblePrimitiveParameterRemaps()
        {
            using var fixture = new Fixture("x64");
            AddLegacyEnumProjection(fixture, "int", true, false);
            fixture.Write("Bindings.cs", @"
using Canonical;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace Test { public static partial class Apis { [DllImport(""test"")] public static extern void Project(int value); } }");
            var compilation = fixture.Compile(new() { ["FLAGS"] = "Canonical" }, new() { ["Project::value"] = "FLAGS" });
            string output = Path.Combine(fixture.DirectoryPath, "IncompatiblePrimitiveProjection.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsFalse(generator.WroteWinmd);
            StringAssert.Contains(string.Join(Environment.NewLine, generator.GetDiagnostics()), "same size and sign");
        }

        [DataTestMethod]
        [DataRow("Owner.cs", true)]
        [DataRow("Bindings.enums.cs", false)]
        public void EnumNameAndStorageCoincidenceDoNotEstablishProjectionOwnership(string source, bool hasUse)
        {
            using var fixture = new Fixture("x64");
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public struct FLAGS { public uint Value; } }");
            fixture.Write(source, "namespace Test { public enum FLAGS : uint { First = 1 } }");
            fixture.Write("Bindings.cs", hasUse ? @"
using System.Runtime.InteropServices;
namespace Test { public static partial class Apis { [DllImport(""test"")] public static extern void Project(FLAGS value); } }" : "");
            var compilation = fixture.Compile();
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0101"));
        }

        private static void AddLegacyEnumProjection(Fixture fixture, string storage, bool explicitProjection, bool manual)
        {
            fixture.Write("autotypes.cs", "");
            fixture.Write("Bindings.header-types.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Test { [NativeTypedef] public unsafe struct FLAGS { public " + storage + @" Value; } }");
            fixture.Write(manual ? "Bindings.manual.cs" : "Bindings.enums.cs",
                "namespace Canonical { public enum FLAGS : uint { First = 1 } }");
            fixture.Write("Bindings.cs", @"
using Canonical;
using System.Runtime.InteropServices;
using Windows.Win32.Foundation.Metadata;
namespace Test { public static unsafe partial class Apis { [DllImport(""test"")] public static extern void Project(" +
                "FLAGS value); } }");
        }

        private static string RetainedDeclareHandleSource(string sourceNamespace = "Test", long[]? invalidValues = null)
        {
            using var stream = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "HANDLE",
                    Namespace = sourceNamespace,
                    ValueType = "DECLARE_HANDLE",
                    InvalidHandleValues = invalidValues ?? new long[] { 0 },
                },
            }, stream);
            return Encoding.UTF8.GetString(stream.ToArray());
        }

        private static string HeaderWithDeclareHandleProof(string source = NativeHandleHeader,
            string nativeAlias = "HANDLE", string storage = "HANDLE__*")
        {
            var root = CSharpSyntaxTree.ParseText(source).GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            return root.ReplaceNode(declaration,
                NativeHandleSourceProvenance.AttachHeaderDeclareHandle(declaration, nativeAlias, storage))
                .NormalizeWhitespace().ToFullString() + Environment.NewLine;
        }

        private static string WithoutHandleSourceProof(string source)
        {
            var root = CSharpSyntaxTree.ParseText(source).GetRoot();
            return root.ReplaceNodes(root.DescendantNodes().OfType<StructDeclarationSyntax>(),
                (_, rewritten) => NativeHandleSourceProvenance.Remove(rewritten)).ToFullString();
        }

        private static long[] ReadInvalidValues(MetadataReader reader, TypeDefinition type) =>
            type.GetCustomAttributes().Where(handle => AttributeName(reader, handle) == "InvalidHandleValueAttribute")
                .Select(handle =>
                {
                    var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
                    Assert.AreEqual((ushort)1, blob.ReadUInt16());
                    long value = blob.ReadInt64();
                    Assert.AreEqual((ushort)0, blob.ReadUInt16());
                    Assert.AreEqual(0, blob.RemainingBytes);
                    return value;
                }).OrderBy(value => value).ToArray();

        private static string AttributeName(MetadataReader reader, CustomAttributeHandle handle)
        {
            var constructor = reader.GetCustomAttribute(handle).Constructor;
            var owner = constructor.Kind == HandleKind.MethodDefinition
                ? reader.GetMethodDefinition((MethodDefinitionHandle)constructor).GetDeclaringType()
                : reader.GetMemberReference((MemberReferenceHandle)constructor).Parent;
            return owner.Kind == HandleKind.TypeDefinition
                ? reader.GetString(reader.GetTypeDefinition((TypeDefinitionHandle)owner).Name)
                : reader.GetString(reader.GetTypeReference((TypeReferenceHandle)owner).Name);
        }

        private sealed class Fixture : IDisposable
        {
            internal Fixture(string architecture)
            {
                Architecture = architecture;
                DirectoryPath = Path.Combine(Path.GetTempPath(), "header-typedef-composition-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(DirectoryPath);
                File.WriteAllText(Path.Combine(DirectoryPath, "Metadata.manual.cs"), Metadata);
                foreach (string target in architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { architecture })
                {
                    string directory = Path.Combine(DirectoryPath, target);
                    Directory.CreateDirectory(directory);
                    File.WriteAllText(Path.Combine(directory, "Bindings.header-types.cs"), HeaderAlias);
                    File.WriteAllText(Path.Combine(directory, "autotypes.cs"), RetainedAlias);
                }
            }

            internal string DirectoryPath { get; }
            internal string Architecture { get; }

            internal void Write(string name, string source)
            {
                foreach (string target in Architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { Architecture })
                    File.WriteAllText(Path.Combine(DirectoryPath, target, name), source);
            }

            internal ClangSharpSourceCompilation Compile(Dictionary<string, string>? requiredNamespaces = null,
                Dictionary<string, string>? remaps = null,
                Dictionary<string, string>? apiNamesToNamespaces = null) => ClangSharpSourceCompilation.Create(
                DirectoryPath, Architecture, remaps ?? new(), new(), Array.Empty<string>(), new(), requiredNamespaces ?? new(), new(),
                Array.Empty<string>(), new(), apiNamesToNamespaces ?? new());

            public void Dispose() => Directory.Delete(DirectoryPath, recursive: true);
        }

        private const string NativeHandleHeader = @"
namespace Test {
    [global::Windows.Win32.Foundation.Metadata.NativeTypedef]
    public unsafe partial struct HANDLE { public HANDLE__* Value; }
}";

        private const string HeaderAlias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
    [global::Windows.Win32.Foundation.Metadata.NativeTypedef]
    [global::Windows.Win32.Foundation.Metadata.AlsoUsableFor(""OTHER_HANDLE"")]
    public unsafe partial struct HANDLE { public void* Value; }
}";

        private const string RetainedAlias = @"
using Windows.Win32.Foundation.Metadata;
namespace Test {
    [RAIIFree(""Close"")]
    [InvalidHandleValue(0)]
    [NativeTypedef]
    public unsafe struct HANDLE { public void* Value; }
}";

        private const string Metadata = @"
using System;
namespace Windows.Win32.Foundation.Metadata {
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Field)]
    public sealed class DocumentationAttribute : Attribute { public DocumentationAttribute(string url) { } }
    [Flags] public enum Architecture { None = 0, X86 = 1, X64 = 2, Arm64 = 4, All = 7 }
    [AttributeUsage(AttributeTargets.Struct | AttributeTargets.Enum | AttributeTargets.Field | AttributeTargets.Method)]
    public sealed class SupportedArchitectureAttribute : Attribute { public SupportedArchitectureAttribute(Architecture architecture) { } }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class NativeTypedefAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class MetadataTypedefAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Field | AttributeTargets.Parameter | AttributeTargets.ReturnValue)]
    public sealed class NativeTypeNameAttribute : Attribute { public NativeTypeNameAttribute(string value) { } }
    [AttributeUsage(AttributeTargets.Field)]
    public sealed class NativeBitfieldAttribute : Attribute { public NativeBitfieldAttribute(string name, int offset, int length) { } }
    [AttributeUsage(AttributeTargets.Field | AttributeTargets.Parameter)]
    public sealed class ConstAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Field)]
    public sealed class NotNullTerminatedAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Field)]
    public sealed class NullNullTerminatedAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class RAIIFreeAttribute : Attribute { public RAIIFreeAttribute(string method) { } }
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true)]
    public sealed class InvalidHandleValueAttribute : Attribute { public InvalidHandleValueAttribute(long value) { } }
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true)]
    public sealed class AlsoUsableForAttribute : Attribute { public AlsoUsableForAttribute(string name) { } }
}";
    }
}
