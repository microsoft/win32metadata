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
        [DataRow("uint", "", "", "Value storage")]
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

            internal ClangSharpSourceCompilation Compile() => ClangSharpSourceCompilation.Create(
                DirectoryPath, Architecture, new(), new(), Array.Empty<string>(), new(), new(), new(),
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
