using System;
using System.Collections.Generic;
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
        public void LogicalGroupOwnershipMovesConsumersAndRemovesOnlyItsOriginalConstantCopies(string architecture)
        {
            using var fixture = DeclarationFixture(architecture);
            foreach (string target in DeclarationTargets(architecture))
            {
                WriteDeclaration(fixture, target, "Owner.header-types.cs",
                    LogicalProvider(fixture, target, "Owner", true));
                WriteDeclaration(fixture, target, "Observer.header-types.cs",
                    LogicalProvider(fixture, target, "Observer", false));
                WriteDeclaration(fixture, target, "Observer.cs", @"
using Windows.Win32.Foundation.Metadata;
namespace Observer {
    public partial struct Carrier {
        public GROUP Value;
        [AssociatedEnum(""Observer.GROUP"")] public uint Code;
        public uint Read() => (uint)GROUP.FIRST;
    }
    public static partial class Apis { public const uint Alias = (uint)GROUP.FIRST; }
}");
                WriteDeclaration(fixture, target, "Observer.constants.cs",
                    "namespace Observer { public static partial class Apis { public const uint FIRST = 1; } }");
                WriteDeclaration(fixture, target, "Foreign.constants.cs",
                    "namespace Foreign { public static partial class Apis { public const uint FIRST = 9; } }");
            }

            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var group = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.GROUP")!;
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Observer.GROUP"));
            Assert.AreEqual(SpecialType.System_UInt32, group.EnumUnderlyingType!.SpecialType);
            Assert.AreEqual(1U, group.GetMembers("FIRST").OfType<IFieldSymbol>().Single().ConstantValue);
            var carrier = compilation.CSharpCompilation.GetTypeByMetadataName("Observer.Carrier")!;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(group, carrier.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
            var code = carrier.GetMembers("Code").OfType<IFieldSymbol>().Single();
            Assert.AreEqual("Owner.GROUP", code.GetAttributes().Single(attribute =>
                attribute.AttributeClass?.ToDisplayString() == "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute")
                .ConstructorArguments.Single().Value);
            var originalConstants = compilation.CSharpCompilation.GetTypeByMetadataName("Observer.Apis")!;
            Assert.AreEqual(0, originalConstants.GetMembers("FIRST").Length);
            Assert.AreEqual(1U, originalConstants.GetMembers("Alias").OfType<IFieldSymbol>().Single().ConstantValue);
            Assert.AreEqual(9U, compilation.CSharpCompilation.GetTypeByMetadataName("Foreign.Apis")!
                .GetMembers("FIRST").OfType<IFieldSymbol>().Single().ConstantValue);
            AssertDeclarationImage(fixture, compilation, "GROUP", "Owner", "Observer");
        }

        [DataTestMethod]
        [DataRow(true, true)]
        [DataRow(false, false)]
        public void LogicalGroupOwnershipRejectsAmbiguousOrMissingTraversalOwners(bool firstOwner, bool secondOwner)
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "First.header-types.cs",
                LogicalProvider(fixture, "x86", "First", firstOwner));
            WriteDeclaration(fixture, "x86", "Second.header-types.cs",
                LogicalProvider(fixture, "x86", "Second", secondOwner));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Canonical ownership requires one source-bound traversed-header namespace.");
        }

        [TestMethod]
        public void IndependentLogicalContributionsKeepTheirMembersWithoutClaimingOneNativeDeclaration()
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "First.header-types.cs",
                LogicalProvider(fixture, "x86", "Owner", true));
            WriteDeclaration(fixture, "x86", "Second.header-types.cs",
                LogicalProvider(fixture, "x86", "Owner", true, "SECOND", 2, "second-native.h"));
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var group = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.GROUP")!;
            CollectionAssert.AreEquivalent(new[] { "FIRST", "SECOND" }, group.GetMembers().OfType<IFieldSymbol>()
                .Where(field => field.HasConstantValue).Select(field => field.Name).ToArray());
            var declaration = (EnumDeclarationSyntax)group.DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.IsNull(NativeDeclarationSourceProvenance.Read(declaration));
        }

        [TestMethod]
        public void SameManagedGroupNameDoesNotAuthorizeDifferentNativeNames()
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "First.header-types.cs",
                LogicalProvider(fixture, "x86", "Owner", true));
            WriteDeclaration(fixture, "x86", "Second.header-types.cs",
                LogicalProvider(fixture, "x86", "Owner", true, "SECOND", 2, "second-native.h", "OTHER"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Distinct native logical groups cannot share a projection solely by managed name.");
        }

        [DataTestMethod]
        [DataRow("x86")]
        [DataRow("x64")]
        [DataRow("arm64")]
        [DataRow("crossarch")]
        public void IncompleteDeclarationsUseNativeIdentityAndKeepPointerConsumers(string architecture)
        {
            using var fixture = DeclarationFixture(architecture);
            foreach (string target in DeclarationTargets(architecture))
            {
                WriteDeclaration(fixture, target, "Owner.cs", IncompleteProvider(fixture, target, "Owner", true));
                WriteDeclaration(fixture, target, "Observer.cs", IncompleteProvider(fixture, target, "Observer", false) + @"
namespace Observer { public unsafe partial struct Carrier { public VALUE* Value; } }");
            }
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.VALUE")!;
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Observer.VALUE"));
            var carrier = compilation.CSharpCompilation.GetTypeByMetadataName("Observer.Carrier")!;
            var pointer = (IPointerTypeSymbol)carrier.GetMembers("Value").OfType<IFieldSymbol>().Single().Type;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(record, pointer.PointedAtType));
            Assert.AreEqual(0, record.GetMembers().OfType<IFieldSymbol>().Count());
            var declaration = (StructDeclarationSyntax)record.DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.IsNotNull(NativeDeclarationSourceProvenance.Read(declaration));
            Assert.IsNull(NativeRecordSourceProvenance.Read(declaration));
            Assert.IsNull(NativeTypedefSourceProvenance.Read(declaration));
            AssertDeclarationImage(fixture, compilation, "VALUE", "Owner", "Observer");
        }

        [TestMethod]
        public void AnUnprovenEmptyRecordCannotComposeWithAProvenNativeDeclaration()
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "Owner.cs", IncompleteProvider(fixture, "x86", "Owner", true));
            WriteDeclaration(fixture, "x86", "Unknown.cs", "namespace Owner { public partial struct VALUE { } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting incomplete native declarations");
        }

        [TestMethod]
        public void UnprovenEmptyRecordsRemainUnresolvedInsteadOfBeingCollapsedBySpelling()
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "First.cs", "namespace Owner { public partial struct VALUE { } }");
            WriteDeclaration(fixture, "x86", "Second.cs", "namespace Owner { public partial struct VALUE { } }");
            var compilation = fixture.Compile();
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.VALUE")!;
            Assert.AreEqual(2, record.DeclaringSyntaxReferences.Length);
            Assert.IsTrue(record.DeclaringSyntaxReferences.All(reference =>
                NativeDeclarationSourceProvenance.Read((StructDeclarationSyntax)reference.GetSyntax()) == null));
        }

        [TestMethod]
        public void LegacyEmptyPlaceholdersRequireTheirOwnQualifiedDefinition()
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "Definitions.cs", @"
namespace Foreign { public struct VALUE { public int Field; } }
namespace Owner { public partial struct COMPLETE { public int Field; } }");
            WriteDeclaration(fixture, "x86", "Legacy.manual.cs", @"
namespace Owner {
    public partial struct VALUE { }
    public partial struct COMPLETE { }
}");
            WriteDeclaration(fixture, "x86", "Consumer.cs", @"
namespace Owner { public unsafe struct Carrier { public VALUE* Pointer; } }");
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var incomplete = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.VALUE")!;
            var foreign = compilation.CSharpCompilation.GetTypeByMetadataName("Foreign.VALUE")!;
            var complete = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.COMPLETE")!;
            Assert.IsNotNull(incomplete);
            Assert.IsNotNull(foreign);
            Assert.IsNotNull(complete);
            Assert.AreEqual(1, incomplete.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(0, incomplete.GetMembers().OfType<IFieldSymbol>().Count());
            Assert.AreEqual(1, complete.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_Int32,
                complete.GetMembers("Field").OfType<IFieldSymbol>().Single().Type.SpecialType);
            var carrier = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.Carrier")!;
            var pointer = (IPointerTypeSymbol)carrier.GetMembers("Pointer").OfType<IFieldSymbol>().Single().Type;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(incomplete, pointer.PointedAtType));
            Assert.IsFalse(SymbolEqualityComparer.Default.Equals(incomplete, foreign));
        }

        [DataTestMethod]
        [DataRow("second-native.h", "c:@S@VALUE")]
        [DataRow("native-shared.h", "c:@N@Other@S@VALUE")]
        public void SameSpelledIncompleteRecordsDoNotAcquireACommonOwner(string header, string identity)
        {
            using var fixture = DeclarationFixture("x86");
            WriteDeclaration(fixture, "x86", "First.cs", IncompleteProvider(fixture, "x86", "First", true));
            WriteDeclaration(fixture, "x86", "Second.cs", IncompleteProvider(fixture, "x86", "Second", true, header, identity));
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var first = compilation.CSharpCompilation.GetTypeByMetadataName("First.VALUE")!;
            var second = compilation.CSharpCompilation.GetTypeByMetadataName("Second.VALUE")!;
            Assert.IsFalse(SymbolEqualityComparer.Default.Equals(first, second));
        }

        [DataTestMethod]
        [DataRow(true)]
        [DataRow(false)]
        public void CommonNativeObservationRequiresAllDirectArchitectureProviders(bool fullCoverage)
        {
            using var fixture = DeclarationFixture("crossarch");
            foreach (string target in fullCoverage ? DeclarationTargets("crossarch") : new[] { "x86", "x64" })
                WriteDeclaration(fixture, target, "Owner.cs", IncompleteProvider(fixture, target, "Owner", true));
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Observation.cs"),
                IncompleteProvider(fixture, "x86", "Observer", false));
            if (!fullCoverage)
            {
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message, "direct providers for all three architectures");
                return;
            }
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.VALUE")!;
            Assert.AreEqual(1, record.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(0, record.GetAttributes().Count(attribute =>
                attribute.AttributeClass?.ToDisplayString() == "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute"));
        }

        private static Fixture DeclarationFixture(string architecture)
        {
            var fixture = new Fixture(architecture);
            fixture.Write("Bindings.header-types.cs", "namespace Test { }");
            fixture.Write("autotypes.cs", "namespace Test { }");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Associations.manual.cs"), @"
namespace Windows.Win32.Foundation.Metadata {
    [System.AttributeUsage(System.AttributeTargets.Field | System.AttributeTargets.Parameter | System.AttributeTargets.ReturnValue)]
    public sealed class AssociatedEnumAttribute : System.Attribute {
        public AssociatedEnumAttribute(string value) { }
    }
}");
            return fixture;
        }

        private static string[] DeclarationTargets(string architecture) =>
            architecture == "crossarch" ? new[] { "x86", "x64", "arm64" } : new[] { architecture };

        private static void WriteDeclaration(Fixture fixture, string architecture, string name, string text) =>
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, architecture, name), text);

        private static string DeclarationHeader(Fixture fixture, string name, string text)
        {
            string path = Path.Combine(fixture.DirectoryPath, name);
            if (!File.Exists(path))
                File.WriteAllText(path, text);
            return path;
        }

        private static string LogicalProvider(Fixture fixture, string architecture, string ns, bool owner,
            string member = "FIRST", uint value = 1, string headerName = "native-shared.h", string nativeName = "GROUP")
        {
            string header = DeclarationHeader(fixture, headerName, "typedef unsigned int GROUP;\n");
            string constants = DeclarationHeader(fixture, "constants.h", "#define FIRST 1\n#define SECOND 2\n");
            string main = DeclarationHeader(fixture, "main.cpp", "#include \"native-shared.h\"\n");
            string expression = $"unchecked((uint){value}UL)";
            var declaration = (EnumDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                $"public enum GROUP : uint {{ {member} = {expression} }}")!;
            var binding = new NativeConstantBinding("Macro", member, constants,
                member == "FIRST" ? 1U : 2U, 1, NativeConstantGroupProvenance.HashFile(constants),
                "int", "uint", value.ToString(System.Globalization.CultureInfo.InvariantCulture));
            var group = new NativeConstantGroup("::" + nativeName, "GROUP", ns, "uint", header, 1,
                new[] { new NativeConstantGroupMember(member, expression, new[] { binding }) });
            var constantSource = new NativeConstantGroupSource(main, NativeConstantGroupProvenance.HashFile(main),
                DeclarationArchitecture(architecture), group);
            declaration = NativeConstantGroupProvenance.Attach(declaration, constantSource);
            var source = new NativeDeclarationSource("c:" + headerName + "@T@" + nativeName, nativeName, header,
                NativeConstantGroupProvenance.HashFile(header), 1, 1, "GROUP", ns, owner, NativeDeclarationKind.LogicalEnum)
            { SourceArchitecture = DeclarationArchitecture(architecture) };
            declaration = NativeDeclarationSourceProvenance.Attach(declaration, source);
            string text = $"namespace {ns} {{\n{declaration.ToFullString()}\n}}";
            var reparsed = CSharpSyntaxTree.ParseText(text).GetRoot().DescendantNodes()
                .OfType<EnumDeclarationSyntax>().Single();
            Assert.AreEqual(source, NativeDeclarationSourceProvenance.Read(reparsed));
            var transportedConstants = NativeConstantGroupProvenance.Read(reparsed);
            Assert.IsNotNull(transportedConstants);
            Assert.AreEqual(constantSource.SourceFile, transportedConstants.SourceFile);
            Assert.AreEqual(constantSource.SourceHash, transportedConstants.SourceHash);
            Assert.AreEqual(constantSource.Architecture, transportedConstants.Architecture);
            Assert.AreEqual(constantSource.Group.NativeName, transportedConstants.Group.NativeName);
            Assert.AreEqual(constantSource.Group.Namespace, transportedConstants.Group.Namespace);
            return text;
        }

        private static string IncompleteProvider(Fixture fixture, string architecture, string ns, bool owner,
            string headerName = "native-shared.h", string identity = "c:@S@VALUE")
        {
            string header = DeclarationHeader(fixture, headerName, "struct VALUE;\n");
            var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                "public partial struct VALUE { }")!;
            declaration = NativeDeclarationSourceProvenance.Attach(declaration,
                new NativeDeclarationSource(identity, identity.Contains("@N@", StringComparison.Ordinal) ? "Other::VALUE" : "VALUE",
                    header, NativeConstantGroupProvenance.HashFile(header), 1, 1, "VALUE", ns, owner,
                    NativeDeclarationKind.IncompleteRecord) { SourceArchitecture = DeclarationArchitecture(architecture) });
            return $"namespace {ns} {{ {declaration.ToFullString()} }}";
        }

        private static Architecture DeclarationArchitecture(string architecture) => architecture switch
        {
            "x86" => Architecture.X86,
            "x64" => Architecture.X64,
            "arm64" => Architecture.Arm64,
            _ => throw new ArgumentOutOfRangeException(nameof(architecture)),
        };

        private static void AssertDeclarationCompilation(ClangSharpSourceCompilation compilation)
        {
            var errors = compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error).ToArray();
            Assert.AreEqual(0, errors.Length, string.Join(Environment.NewLine, errors.Select(error => error.ToString())));
        }

        private static void AssertDeclarationImage(Fixture fixture, ClangSharpSourceCompilation compilation,
            string name, string owner, string observer)
        {
            string output = Path.Combine(fixture.DirectoryPath, "NativeDeclaration.winmd");
            var generator = ClangSharpSourceWinmdGenerator.GenerateWindmdForCompilation(
                compilation, new(), new(), new(), new Version(1, 0, 0, 0), output);
            Assert.IsTrue(generator.WroteWinmd, string.Join(Environment.NewLine, generator.GetDiagnostics()));
            using var stream = File.OpenRead(output);
            using var pe = new PEReader(stream);
            var reader = pe.GetMetadataReader();
            var declarations = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Name) == name).ToArray();
            Assert.AreEqual(1, declarations.Length);
            Assert.AreEqual(owner, reader.GetString(declarations[0].Namespace));
            Assert.IsFalse(reader.TypeReferences.Select(reader.GetTypeReference).Any(type =>
                reader.GetString(type.Name) == name && reader.GetString(type.Namespace) == observer));
        }
    }
}
