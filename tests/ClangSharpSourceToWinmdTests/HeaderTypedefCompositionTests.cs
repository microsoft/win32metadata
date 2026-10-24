using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class HeaderTypedefCompositionTests
    {
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

            internal ClangSharpSourceCompilation Compile(Dictionary<string, string>? requiredNamespaces = null) => ClangSharpSourceCompilation.Create(
                DirectoryPath, Architecture, new(), new(), Array.Empty<string>(), new(), requiredNamespaces ?? new(), new(),
                Array.Empty<string>(), new(), new());

            public void Dispose() => Directory.Delete(DirectoryPath, recursive: true);
        }

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
    [Flags] public enum Architecture { None = 0, X86 = 1, X64 = 2, Arm64 = 4, All = 7 }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class SupportedArchitectureAttribute : Attribute { public SupportedArchitectureAttribute(Architecture architecture) { } }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class NativeTypedefAttribute : Attribute { }
    [AttributeUsage(AttributeTargets.Struct)]
    public sealed class RAIIFreeAttribute : Attribute { public RAIIFreeAttribute(string method) { } }
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true)]
    public sealed class InvalidHandleValueAttribute : Attribute { public InvalidHandleValueAttribute(long value) { } }
    [AttributeUsage(AttributeTargets.Struct, AllowMultiple = true)]
    public sealed class AlsoUsableForAttribute : Attribute { public AlsoUsableForAttribute(string name) { } }
}";
    }
}
