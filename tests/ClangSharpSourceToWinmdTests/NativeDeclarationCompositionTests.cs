using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
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
            var error = Assert.ThrowsException<InvalidOperationException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "error WMA003:");
            StringAssert.Contains(error.Message, "Distinct native logical groups cannot share a projection solely by managed name.");
            StringAssert.Contains(error.Message, "Blocked stage 'emitter.source-cleaning': requires valid logical enum composition.");
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
        [DataRow(true, false, false)]
        [DataRow(false, false, false)]
        [DataRow(true, true, true)]
        [DataRow(false, true, true)]
        [DataRow(true, true, false)]
        [DataRow(false, true, false)]
        public void CommonNativeObservationRequiresAllDirectArchitectureProviders(bool fullCoverage, bool commonDirectory, bool samePartition)
        {
            using var fixture = DeclarationFixture("crossarch");
            foreach (string target in fullCoverage ? DeclarationTargets("crossarch") : new[] { "x86", "x64" })
                WriteDeclaration(fixture, target, "Owner.cs", IncompleteProvider(fixture, target, "Owner", true));
            string observation = commonDirectory
                ? Path.Combine(Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName,
                    samePartition ? "Owner.cs" : "Observation.cs")
                : Path.Combine(fixture.DirectoryPath, "Observation.cs");
            File.WriteAllText(observation,
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

        [TestMethod]
        public void SingleCommonOriginalSdkDeclarationsPreserveNativeContracts()
        {
            var trees = OriginalCommonNativeInputs();
            var original = DeclarationRecords(trees).ToArray();
            var originalForwards = original.Where(record => NativeDeclarationSourceProvenance.Read(record) != null).ToArray();
            var originalProviders = original.Where(record => NativeRecordSourceProvenance.Read(record) != null).ToArray();
            var originalForwardMap = originalForwards.ToDictionary(record =>
                (record.SyntaxTree.FilePath, Source: NativeDeclarationSourceProvenance.Read(record)!));
            Assert.AreEqual(1435, originalForwards.Length);
            Assert.AreEqual(8, originalProviders.Length);
            var foreign = CSharpSyntaxTree.ParseText(
                "namespace Foreign { public struct CONTEXT { public int Value; } }",
                path: Path.Combine(Path.GetTempPath(), "common", "Foreign.cs"));
            var validation = new GenerationValidation();
            var composed = CoalesceNativeDeclarations(trees.Append(foreign).ToArray(), validation);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            Assert.IsTrue(composed.Contains(foreign));
            var declarations = DeclarationRecords(composed).ToArray();
            var forwards = declarations.Where(record => NativeDeclarationSourceProvenance.Read(record) != null).ToArray();
            var forwardKeys = forwards.Select(record =>
                (record.SyntaxTree.FilePath, Source: NativeDeclarationSourceProvenance.Read(record)!)).ToHashSet();
            Assert.AreEqual(1431, forwards.Length);
            foreach (var forward in forwards)
            {
                var source = NativeDeclarationSourceProvenance.Read(forward)!;
                var originalForward = originalForwardMap[(forward.SyntaxTree.FilePath, source)];
                Assert.AreEqual(Architecture.X86, source.SourceArchitecture);
                Assert.AreEqual(originalForward.ToFullString(), forward.ToFullString());
                Assert.IsNull(NativeRecordSourceProvenance.Read(forward));
                Assert.IsNull(NativeTypedefSourceProvenance.Read(forward));
            }
            foreach (var provider in originalProviders)
            {
                var source = NativeRecordSourceProvenance.Read(provider)!;
                var retained = declarations.Single(record => record.SyntaxTree.FilePath == provider.SyntaxTree.FilePath &&
                    NativeRecordSourceProvenance.Read(record) == source);
                Assert.AreEqual(provider.ToFullString(), retained.ToFullString());
                Assert.AreEqual(source, NativeRecordSourceProvenance.Read(retained));
            }
            var removed = originalForwards.Where(record =>
                !forwardKeys.Contains((record.SyntaxTree.FilePath, NativeDeclarationSourceProvenance.Read(record)!))).ToArray();
            Assert.AreEqual(4, removed.Length);
            Assert.AreEqual(2, removed.Count(record => !NativeDeclarationSourceProvenance.Read(record)!.TraversedHeader));
            foreach (var forward in removed)
            {
                var source = NativeDeclarationSourceProvenance.Read(forward)!;
                Assert.IsTrue(originalProviders.Any(record =>
                {
                    var definition = NativeRecordSourceProvenance.Read(record)!;
                    return NativeRecordSourceProvenance.GetIdentityKey(definition) ==
                        NativeDeclarationSourceProvenance.GetIdentityKey(source) &&
                        definition.Name == source.Name && definition.NativeName == source.NativeName;
                }));
            }
            AssertOriginalLegacyManualSourceRoles(forwards);
        }

        [TestMethod]
        public void OriginalSdkNativeProvidersAndReferencesShareTheirPublicOwnerAcrossPhaseHandoffs()
        {
            using var fixture = DeclarationFixture("crossarch");
            using var stream = File.OpenRead(Path.Combine(AppContext.BaseDirectory, "assets",
                "NativeProviderReferences.originalb466.json"));
            using var document = JsonDocument.Parse(stream);
            var root = document.RootElement;
            Assert.AreEqual(1, root.GetProperty("Version").GetInt32());
            Assert.AreEqual(8, root.GetProperty("Inputs").GetArrayLength());
            Assert.AreEqual(32, root.GetProperty("Consumers").GetArrayLength());
            var trees = root.GetProperty("Inputs").EnumerateArray().Select(input =>
            {
                string declaration = input.GetProperty("Declaration").GetString()!;
                Assert.AreEqual(input.GetProperty("Sha256").GetString(),
                    Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(declaration))));
                string ns = input.GetProperty("Namespace").GetString()!;
                return CSharpSyntaxTree.ParseText(
                    $"using System;\nusing System.Runtime.InteropServices;\nusing Windows.Win32.Foundation.Metadata;\n" +
                    $"namespace {ns} {{\n{declaration}\n}}",
                    path: Path.Combine(fixture.DirectoryPath, input.GetProperty("Path").GetString()!));
            }).Cast<SyntaxTree>().ToList();
            string manual = root.GetProperty("ManualSource").GetString()!;
            Assert.AreEqual(root.GetProperty("ManualSourceSha256").GetString(),
                Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(manual))));
            trees.Add(CSharpSyntaxTree.ParseText(manual,
                path: Path.Combine(fixture.DirectoryPath, "Direct2D.manual.cs")));
            var nominal = root.GetProperty("NominalProjection");
            using (var output = new MemoryStream())
            {
                NativeTypedefStructsCreator.WriteToStream(new(), new[] { new AutoType
                {
                    Namespace = nominal.GetProperty("Namespace").GetString(),
                    Name = nominal.GetProperty("Name").GetString()!,
                    ValueType = nominal.GetProperty("ValueType").GetString()!,
                    NativeTypedef = nominal.GetProperty("NativeTypedef").GetBoolean(),
                } }, output);
                trees.Add(CSharpSyntaxTree.ParseText(Encoding.UTF8.GetString(output.ToArray()),
                    path: Path.Combine(fixture.DirectoryPath, "common", "autotypes.cs")));
            }
            trees.Add(CSharpSyntaxTree.ParseText(Metadata,
                path: Path.Combine(fixture.DirectoryPath, "Metadata.manual.cs")));
            var owners = new Dictionary<string, string>
            {
                ["IDirectDrawSurface"] = "Windows.Win32.Graphics.DirectDraw",
                ["IPrintDocumentPackageTarget"] = "Windows.Win32.Storage.Xps.Printing",
                ["D2D_COLOR_F___"] = "Windows.Win32.Graphics.Direct2D",
                ["CGpEffect"] = "Windows.Win32.Graphics.GdiPlus",
            };
            int index = 0;
            foreach (var consumer in root.GetProperty("Consumers").EnumerateArray())
            {
                string signature = consumer.GetProperty("Signature").GetString()!;
                Assert.AreEqual(consumer.GetProperty("Sha256").GetString(),
                    Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(signature))));
                string usings = string.Join("\n", root.GetProperty("ImportsByOriginalEntry")
                    .GetProperty(consumer.GetProperty("OriginalEntry").GetString()!).EnumerateArray()
                    .Select(import => $"using {import.GetString()};"));
                string body = signature.EndsWith(';') ? "" : " => throw new System.NotImplementedException();";
                trees.Add(CSharpSyntaxTree.ParseText(
                    $"using System;\nusing Windows.Win32.Foundation.Metadata;\n{usings}\n" +
                    $"namespace {consumer.GetProperty("Namespace").GetString()} {{ " +
                    $"public unsafe partial struct Consumer{index} {{ {signature}{body} }} }}",
                    path: Path.Combine(fixture.DirectoryPath, "common", $"Consumer{index++}.cs")));
            }
            var validation = new GenerationValidation();
            var originalRecords = DeclarationRecords(trees).Select(record => NativeRecordSourceProvenance.Read(record))
                .Where(source => source != null).ToDictionary(source => source!.Name);
            var recordRoutes = NativeNamespaceRoutes(trees.ToArray(), validation);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            foreach (var declaration in DeclarationRecords(trees).Where(record =>
                NativeRecordSourceProvenance.Read(record) != null ||
                NativeDeclarationSourceProvenance.Read(record) != null))
            {
                string name = declaration.Identifier.ValueText;
                Assert.AreEqual(owners[name],
                    recordRoutes[(SyntaxUtils.GetEnclosingNamespace(declaration), name)]);
            }

            var references = new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) };
            var original = ManagedNativeReferenceCompilation(trees, references);
            var sourceTypes = DeclarationRecords(trees).Select(record =>
                (SyntaxUtils.GetEnclosingNamespace(record), record.Identifier.ValueText)).ToHashSet();
            var moved = trees.Select(tree =>
                NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, new(), sourceTypes, recordRoutes,
                    nativeReferenceModels: new[] { original.GetSemanticModel(tree) })).ToArray();
            var required = owners.ToDictionary(pair => pair.Key, pair => pair.Value);
            var cleaned = moved.Select(tree => MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, new(), new(), new(),
                required, new(), required, new(), new(), Path.Combine(Path.GetDirectoryName(tree.FilePath)!,
                    Path.GetFileNameWithoutExtension(tree.FilePath) + ".modified.cs"), validation: validation)).ToArray();
            Assert.IsTrue(cleaned.Any(tree => Path.GetFileName(tree.FilePath) == "autotypes.modified.cs"));
            Assert.IsTrue(cleaned.Any(tree => Path.GetFileName(tree.FilePath) == "Direct2D.manual.modified.cs"));
            var composed = CoalesceNativeDeclarations(cleaned, validation);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            Assert.AreEqual(0, DeclarationRecords(composed).Count(record =>
                NativeDeclarationSourceProvenance.Read(record) != null));
            foreach (var provider in DeclarationRecords(composed).Where(record =>
                NativeRecordSourceProvenance.Read(record) != null))
            {
                var source = NativeRecordSourceProvenance.Read(provider)!;
                Assert.AreEqual(Architecture.X86, source.SourceArchitecture);
                Assert.AreEqual(originalRecords[source.Name], source);
            }
            foreach (var tree in composed)
                Directory.CreateDirectory(Path.GetDirectoryName(tree.FilePath)!);
            var beforeLegacy = ManagedNativeReferenceCompilation(composed, references);
            var mergeLegacy = typeof(ClangSharpSourceCompilation).GetMethod("MergeLegacyTypedefProjections",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var final = (CSharpCompilation)mergeLegacy.Invoke(null, new object[] { beforeLegacy, required, validation })!;
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            Assert.IsNull(final.GetTypeByMetadataName("Windows.Win32.Graphics.Direct2D.D2D_COLOR_F___"));
            Assert.IsNull(final.GetTypeByMetadataName("Windows.Win32.System.WinRT.Pdf.D2D_COLOR_F"));
            var expectedOwners = owners.ToDictionary(pair => pair.Key, pair => pair.Value);
            expectedOwners.Remove("D2D_COLOR_F___");
            expectedOwners.Add("D2D_COLOR_F", "Windows.Win32.Graphics.Direct2D");
            int checkedReferences = 0;
            foreach (var tree in final.SyntaxTrees.Where(tree => Path.GetFileName(tree.FilePath).StartsWith("Consumer",
                StringComparison.Ordinal)))
            {
                var model = final.GetSemanticModel(tree);
                foreach (var name in tree.GetRoot().DescendantNodes().OfType<NameSyntax>().Where(name =>
                    name is QualifiedNameSyntax or AliasQualifiedNameSyntax &&
                    expectedOwners.ContainsKey(name.ToString().Split('.').Last())))
                {
                    string typeName = name.ToString().Split('.').Last();
                    var symbol = model.GetSymbolInfo(name).Symbol as INamedTypeSymbol;
                    Assert.IsNotNull(symbol, name.ToString());
                    Assert.AreEqual(expectedOwners[typeName], symbol!.ContainingNamespace.ToDisplayString());
                    checkedReferences++;
                }
            }
            Assert.AreEqual(33, checkedReferences);
            var nominalType = final.GetTypeByMetadataName("Windows.Win32.Graphics.GdiPlus.CGpEffect")!;
            Assert.AreEqual(1, nominalType.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_IntPtr, nominalType.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);

            AssertNativeReferenceIsolation(trees, references, recordRoutes);
            AssertRetainedOpaqueProjectionRequiresItsSourceRole(cleaned);
            var alteredManual = beforeLegacy.SyntaxTrees.Single(tree =>
                Path.GetFileName(tree.FilePath) == "Direct2D.manual.modified.cs");
            var mismatched = beforeLegacy.ReplaceSyntaxTree(alteredManual, CSharpSyntaxTree.ParseText(
                alteredManual.GetText().ToString().Replace("float a", "uint a", StringComparison.Ordinal),
                path: alteredManual.FilePath));
            var mismatchValidation = new GenerationValidation();
            mergeLegacy.Invoke(null, new object[] { mismatched, required, mismatchValidation });
            Assert.IsTrue(mismatchValidation.Errors.Any(error => error.Code == "CSSW005" &&
                error.Stage == "emitter.legacy-typedef-composition"));
        }

        private static CSharpCompilation ManagedNativeReferenceCompilation(IEnumerable<SyntaxTree> trees,
            IEnumerable<MetadataReference> references) => CSharpCompilation.Create("OriginalNativeReferenceHandoffs",
                trees, references, new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));

        private static Dictionary<(string Namespace, string Name), string> NativeNamespaceRoutes(
            SyntaxTree[] trees, GenerationValidation validation)
        {
            var records = typeof(ClangSharpSourceCompilation).GetMethod("ResolveNativeNamespaces",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var declarations = typeof(ClangSharpSourceCompilation).GetMethod("ResolveNativeDeclarationNamespaces",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var routes = (Dictionary<(string Namespace, string Name), string>)records.Invoke(null,
                new object[] { trees, new Dictionary<string, string>(), new Dictionary<string, string>(), validation })!;
            var forwards = (Dictionary<(string Namespace, string Name), string>)declarations.Invoke(null,
                new object[] { trees, new Dictionary<string, string>(), routes, validation })!;
            foreach (var pair in forwards)
            {
                if (routes.TryGetValue(pair.Key, out string? previous))
                    Assert.AreEqual(previous, pair.Value);
                routes[pair.Key] = pair.Value;
            }
            return routes;
        }

        private static void AssertNativeReferenceIsolation(IEnumerable<SyntaxTree> inputs,
            IEnumerable<MetadataReference> references, Dictionary<(string Namespace, string Name), string> routes)
        {
            var foreign = CSharpSyntaxTree.ParseText(@"
namespace Foreign { public struct IDirectDrawSurface { public int Different; } }
namespace ForeignConsumer { public struct Carrier { public global::Foreign.IDirectDrawSurface Value; } }",
                path: "Foreign.cs");
            var alias = CSharpSyntaxTree.ParseText(@"
using Surface = Foreign.IDirectDrawSurface;
namespace AliasConsumer { public struct Carrier { public Surface Value; } }", path: "Alias.cs");
            var ambiguous = CSharpSyntaxTree.ParseText(@"
using Foreign;
using Windows.Win32.Graphics.DirectDraw;
namespace AmbiguousConsumer { public struct Carrier { public IDirectDrawSurface Value; } }", path: "Ambiguous.cs");
            var compilation = ManagedNativeReferenceCompilation(inputs.Concat(new[] { foreign, alias, ambiguous }), references);
            foreach (var tree in new[] { foreign, alias, ambiguous })
            {
                var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, new(),
                    nativeRecordNamespaces: routes, nativeReferenceModels: new[] { compilation.GetSemanticModel(tree) });
                Assert.AreEqual(tree.GetText().ToString(), moved.GetText().ToString());
            }
            var original = DeclarationRecords(inputs).Single(record =>
                NativeDeclarationSourceProvenance.Read(record)?.Name == "IDirectDrawSurface" &&
                Path.GetFileName(Path.GetDirectoryName(record.SyntaxTree.FilePath)) == "x86");
            var source = NativeDeclarationSourceProvenance.Read(original)!;
            var other = NativeDeclarationSourceProvenance.Attach(
                (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration("public partial struct IDirectDrawSurface {}")!,
                new NativeDeclarationSource("c:@N@Unrelated@S@IDirectDrawSurface", "Unrelated::IDirectDrawSurface",
                    source.Header, source.HeaderHash, source.Line, source.Column, source.Name,
                    "NativeForeign", true, source.Kind) { SourceArchitecture = source.SourceArchitecture });
            var nativeForeign = CSharpSyntaxTree.ParseText($"namespace NativeForeign {{ {other.ToFullString()} }}",
                path: Path.Combine(Path.GetTempPath(), "x86", "NativeForeign.cs"));
            var nativeAmbiguous = CSharpSyntaxTree.ParseText(@"
using NativeForeign;
using Windows.Win32.Graphics.DirectDraw;
namespace NativeAmbiguousConsumer { public struct Carrier { public IDirectDrawSurface Value; } }",
                path: "NativeAmbiguous.cs");
            var originalInputs = inputs.Concat(new[] { nativeForeign, nativeAmbiguous }).ToArray();
            var validation = new GenerationValidation();
            var nativeRoutes = NativeNamespaceRoutes(originalInputs, validation);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            var nativeCompilation = ManagedNativeReferenceCompilation(originalInputs, references);
            var unchanged = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(nativeAmbiguous, new(),
                nativeRecordNamespaces: nativeRoutes,
                nativeReferenceModels: new[] { nativeCompilation.GetSemanticModel(nativeAmbiguous) });
            Assert.AreEqual(nativeAmbiguous.GetText().ToString(), unchanged.GetText().ToString());
        }

        private static void AssertRetainedOpaqueProjectionRequiresItsSourceRole(SyntaxTree[] trees)
        {
            var nominal = trees.Single(tree => Path.GetFileName(tree.FilePath) == "autotypes.modified.cs");
            var unproved = trees.Select(tree => tree == nominal ? tree.WithFilePath(
                Path.Combine(Path.GetDirectoryName(tree.FilePath)!, "Unproved.modified.cs")) : tree).ToArray();
            var validation = new GenerationValidation();
            var composed = CoalesceNativeDeclarations(unproved, validation);
            Assert.IsTrue(DeclarationRecords(composed).Any(record =>
                NativeDeclarationSourceProvenance.Read(record)?.Name == "CGpEffect"));
            var compilation = ManagedNativeReferenceCompilation(composed,
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) });
            Assert.IsTrue(compilation.GetDiagnostics().Any(diagnostic => diagnostic.Id == "CS0260" &&
                diagnostic.GetMessage().Contains("CGpEffect", StringComparison.Ordinal)));
            foreach (string replacement in new[] { "int Value", "IntPtr Other" })
            {
                var incompatible = trees.Select(tree => tree == nominal ? CSharpSyntaxTree.ParseText(
                    tree.GetText().ToString().Replace("IntPtr Value", replacement, StringComparison.Ordinal),
                    path: tree.FilePath) : tree).ToArray();
                var incompatibleValidation = new GenerationValidation();
                var retained = CoalesceNativeDeclarations(incompatible, incompatibleValidation);
                Assert.IsTrue(DeclarationRecords(retained).Any(record =>
                    NativeDeclarationSourceProvenance.Read(record)?.Name == "CGpEffect"));
            }
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        public void SingleCommonDeclarationsRequireTheirActualProducingTarget(string architecture, bool includeArchitecture)
        {
            using var fixture = DeclarationFixture("crossarch");
            string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
            File.WriteAllText(Path.Combine(common, "Owner.cs"),
                IncompleteProvider(fixture, architecture, "Owner", true, includeArchitecture: includeArchitecture));
            var validation = new GenerationValidation();
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(validation: validation));
            StringAssert.Contains(error.Message, "requires its actual x86 producing target");
            Assert.IsTrue(validation.Errors.Any(item => item.Stage == "emitter.source-family-preflight"));
            Assert.IsTrue(validation.BlockedStages.Any(item => item.Stage == "emitter.source-transformation"));
        }

        [DataTestMethod]
        [DataRow("x86", false)]
        [DataRow("x64", false)]
        [DataRow("arm64", false)]
        [DataRow("x86", true)]
        [DataRow("x64", true)]
        [DataRow("arm64", true)]
        public void SingleCommonForwardsRequireCompleteProviderCoverage(string missingTarget, bool commonObservation)
        {
            var inputs = OriginalCommonNativeInputs();
            var trees = inputs.Where(tree =>
                Path.GetFileName(Path.GetDirectoryName(tree.FilePath)) != missingTarget ||
                Path.GetFileName(tree.FilePath) != "Debug.cs").ToArray();
            if (commonObservation)
            {
                var x86 = inputs.Single(tree => Path.GetFileName(Path.GetDirectoryName(tree.FilePath)) == "x86" &&
                    Path.GetFileName(tree.FilePath) == "Debug.cs");
                var observed = CSharpSyntaxTree.ParseText(x86.GetText(),
                    path: Path.Combine(Path.GetDirectoryName(Path.GetDirectoryName(x86.FilePath))!, "common", "ObservedDebug.cs"));
                trees = trees.Append(observed).ToArray();
            }
            var validation = new GenerationValidation();
            var composed = CoalesceNativeDeclarations(trees, validation);
            Assert.AreEqual(2, validation.BlockingErrorCount, validation.Format());
            Assert.IsTrue(validation.Errors.All(error => error.Code == "CSSW005" &&
                error.Stage == "emitter.declaration-composition" &&
                error.Message.Contains("complete providers for all three architectures", StringComparison.Ordinal)));
            Assert.AreEqual(1433, DeclarationRecords(composed).Count(record =>
                NativeDeclarationSourceProvenance.Read(record) != null));
        }

        [TestMethod]
        public void SingleCommonForwardDoesNotAcceptManagedSpellingAsDefinition()
        {
            using var fixture = DeclarationFixture("crossarch");
            string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
            File.WriteAllText(Path.Combine(common, "Forward.cs"), IncompleteProvider(fixture, "x86", "Owner", true));
            fixture.Write("Unproven.cs", "namespace Owner { public partial struct VALUE { public int Field; } }");
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "Conflicting incomplete native declarations");
        }

        private static SyntaxTree[] OriginalCommonNativeInputs()
        {
            using var stream = File.OpenRead(Path.Combine(AppContext.BaseDirectory, "assets", "CommonNativeDeclarations.original9f.json"));
            using var document = JsonDocument.Parse(stream);
            var root = document.RootElement;
            Assert.AreEqual(1, root.GetProperty("Version").GetInt32());
            Assert.AreEqual(1435, root.GetProperty("DeclarationCount").GetInt32());
            Assert.AreEqual(8, root.GetProperty("CompleteProviderCount").GetInt32());
            string directory = Path.Combine(Path.GetTempPath(), "original-common-native-" + Guid.NewGuid().ToString("N"));
            return root.GetProperty("Inputs").EnumerateArray().GroupBy(input => input.GetProperty("Path").GetString()!)
                .Select(group =>
                {
                    string text = string.Join(Environment.NewLine, group.Select(input =>
                    {
                        string declaration = input.GetProperty("Declaration").GetString()!;
                        Assert.AreEqual(input.GetProperty("Sha256").GetString(),
                            Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(declaration))));
                        return $"namespace {input.GetProperty("Namespace").GetString()} {{\n{declaration}\n}}";
                    }));
                    var tree = CSharpSyntaxTree.ParseText(text, path: Path.Combine(directory, group.Key));
                    Assert.AreEqual(0, tree.GetDiagnostics().Count(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
                    return tree;
                }).ToArray();
        }

        private static IEnumerable<StructDeclarationSyntax> DeclarationRecords(IEnumerable<SyntaxTree> trees) =>
            trees.SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Where(record => record.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax);

        private static SyntaxTree[] CoalesceNativeDeclarations(SyntaxTree[] trees, GenerationValidation validation)
        {
            var method = typeof(ClangSharpSourceCompilation).GetMethod("CoalesceCommonNativeDeclarations",
                BindingFlags.NonPublic | BindingFlags.Static);
            Assert.IsNotNull(method);
            return (SyntaxTree[])method!.Invoke(null, new object[] { trees, Array.Empty<MetadataReference>(), validation })!;
        }

        private static void AssertOriginalLegacyManualSourceRoles(StructDeclarationSyntax[] forwards)
        {
            var sourceTrees = forwards.GroupBy(record => record.SyntaxTree.FilePath).Select(group =>
                CSharpSyntaxTree.ParseText(string.Join(Environment.NewLine, group.Select(record =>
                    $"namespace {SyntaxUtils.GetEnclosingNamespace(record)} {{\n{record.ToFullString()}\n}}")),
                    path: group.Key)).ToArray();
            var originalSources = DeclarationRecords(sourceTrees).Select(record =>
                NativeDeclarationSourceProvenance.Read(record)!).ToArray();
            using var stream = File.OpenRead(Path.Combine(AppContext.BaseDirectory, "assets", "CommonNativeDeclarations.original9f.json"));
            using var document = JsonDocument.Parse(stream);
            var inputs = document.RootElement.GetProperty("LegacyManualSources").EnumerateArray().ToArray();
            Assert.AreEqual(1, inputs.Length);
            foreach (var input in inputs)
            {
                string text = input.GetProperty("Content").GetString()!;
                var bytes = Encoding.UTF8.GetBytes(text);
                Assert.AreEqual(input.GetProperty("Bytes").GetInt32(), bytes.Length);
                Assert.AreEqual(input.GetProperty("Sha256").GetString(), Convert.ToHexString(SHA256.HashData(bytes)));
                Assert.AreEqual(41333182677L, input.GetProperty("Run").GetInt64());
                string directory = Path.GetDirectoryName(sourceTrees[0].FilePath)!;
                string name = input.GetProperty("Path").GetString()!;
                var original = CSharpSyntaxTree.ParseText(text, path: Path.Combine(directory, name));
                var cleaning = new GenerationValidation();
                var cleaned = MetadataSyntaxTreeCleaner.CleanSyntaxTree(original, new(), new(), new(),
                    new(), new(), new(), new(), new(),
                    Path.Combine(directory, Path.GetFileNameWithoutExtension(name) + ".modified.cs"),
                    validation: cleaning);
                Assert.AreEqual(0, cleaning.BlockingErrorCount, cleaning.Format());
                var manualDeclarations = DeclarationRecords(new[] { cleaned }).ToArray();
                Assert.AreEqual(24, manualDeclarations.Length);
                Assert.IsTrue(manualDeclarations.All(record => record.Modifiers.Any(SyntaxKind.PartialKeyword) &&
                    NativeDeclarationSourceProvenance.Read(record) == null &&
                    NativeRecordSourceProvenance.Read(record) == null));
                foreach (string fileName in new[] { name, Path.GetFileName(cleaned.FilePath),
                    Path.GetFileName(cleaned.FilePath).ToUpperInvariant() })
                {
                    var manual = cleaned.WithFilePath(Path.Combine(directory, fileName));
                    var validation = new GenerationValidation();
                    var composed = ComposeRepeatedDeclarations(sourceTrees.Append(manual).ToArray(), validation);
                    Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
                    Assert.AreEqual(manual.GetRoot().ToFullString(),
                        composed.SyntaxTrees.Single(tree => tree.FilePath == manual.FilePath).GetRoot().ToFullString());
                    CollectionAssert.AreEquivalent(originalSources, DeclarationRecords(composed.SyntaxTrees)
                        .Select(NativeDeclarationSourceProvenance.Read).Where(source => source != null).ToArray());

                    var unproved = manual.WithFilePath(Path.Combine(directory, "Ordinary.generated.modified.cs"));
                    var rejected = new GenerationValidation();
                    ComposeRepeatedDeclarations(sourceTrees.Append(unproved).ToArray(), rejected);
                    Assert.AreEqual(1, rejected.BlockingErrorCount, rejected.Format());
                    Assert.IsTrue(rejected.Errors.All(error => error.Code == "CSSW005" &&
                        error.Stage == "emitter.record-composition" &&
                        error.Message.Contains("Conflicting incomplete native declarations", StringComparison.Ordinal)));
                }
            }
        }

        private static CSharpCompilation ComposeRepeatedDeclarations(SyntaxTree[] trees, GenerationValidation validation)
        {
            var method = typeof(ClangSharpSourceCompilation).GetMethod("MergeRepeatedStructs",
                BindingFlags.NonPublic | BindingFlags.Static);
            Assert.IsNotNull(method);
            var compilation = CSharpCompilation.Create("OriginalNativeDeclarationPolicy", trees,
                options: new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
            return (CSharpCompilation)method!.Invoke(null, new object[] { compilation, validation })!;
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
            string headerName = "native-shared.h", string identity = "c:@S@VALUE", bool includeArchitecture = true)
        {
            string header = DeclarationHeader(fixture, headerName, "struct VALUE;\n");
            var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                "public partial struct VALUE { }")!;
            declaration = NativeDeclarationSourceProvenance.Attach(declaration,
                new NativeDeclarationSource(identity, identity.Contains("@N@", StringComparison.Ordinal) ? "Other::VALUE" : "VALUE",
                    header, NativeConstantGroupProvenance.HashFile(header), 1, 1, "VALUE", ns, owner,
                    NativeDeclarationKind.IncompleteRecord) { SourceArchitecture = includeArchitecture ? DeclarationArchitecture(architecture) : null });
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
