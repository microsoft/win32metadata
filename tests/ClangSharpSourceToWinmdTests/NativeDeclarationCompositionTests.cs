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
using Newtonsoft.Json.Linq;

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
using HintAttribute = Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute;
using Metadata = Windows.Win32.Foundation.Metadata;
using @event = Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute;
namespace Observer {
    using NestedHint = Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute;
    public partial struct Carrier {
        public GROUP Value;
        [AssociatedEnum(""Observer.GROUP"")] public uint Code;
        [Hint(""Observer.GROUP"")] public uint AliasCode;
        [HintAttribute(""Observer.GROUP"")] public uint FullAliasCode;
        [Metadata.AssociatedEnum(""Observer.GROUP"")] public uint NamespaceAliasCode;
        [Metadata::AssociatedEnum(""Observer.GROUP"")] public uint NamespaceQualifiedAliasCode;
        [global::Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute(""Observer.GROUP"")] public uint QualifiedCode;
        [@event(""Observer.GROUP"")] public uint EscapedAliasCode;
        [NestedHint(""Observer.GROUP"")] public uint NestedAliasCode;
        [GlobalHint(""Observer.GROUP"")] public uint GlobalAliasCode;
        [GlobalHintAttribute(""Observer.GROUP"")] public uint FullGlobalAliasCode;
        [GlobalMetadata.AssociatedEnum(""Observer.GROUP"")] public uint GlobalNamespaceAliasCode;
        public uint Read() => (uint)GROUP.FIRST;
    }
    public static partial class Apis { public const uint Alias = (uint)GROUP.FIRST; }
}");
                WriteDeclaration(fixture, target, "Observer.constants.cs",
                    "namespace Observer { public static partial class Apis { public const uint FIRST = 1; } }");
                WriteDeclaration(fixture, target, "Foreign.constants.cs",
                    @"global using GlobalHintAttribute = Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute;
global using GlobalMetadata = Windows.Win32.Foundation.Metadata;
namespace Foreign {
    using AssociatedEnumAttribute = global::System.ObsoleteAttribute;
    public static partial class Apis {
        [AssociatedEnum(""Observer.GROUP"")] public const uint FIRST = 9;
    }
}");
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
            foreach (string fieldName in new[] { "AliasCode", "FullAliasCode", "NamespaceAliasCode", "QualifiedCode",
                "NamespaceQualifiedAliasCode", "EscapedAliasCode", "NestedAliasCode", "GlobalAliasCode",
                "FullGlobalAliasCode", "GlobalNamespaceAliasCode" })
                Assert.AreEqual("Owner.GROUP", carrier.GetMembers(fieldName).OfType<IFieldSymbol>().Single()
                    .GetAttributes().Single(attribute => attribute.AttributeClass?.ToDisplayString() ==
                        "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute").ConstructorArguments.Single().Value,
                    fieldName);
            var originalConstants = compilation.CSharpCompilation.GetTypeByMetadataName("Observer.Apis")!;
            Assert.AreEqual(0, originalConstants.GetMembers("FIRST").Length);
            Assert.AreEqual(1U, originalConstants.GetMembers("Alias").OfType<IFieldSymbol>().Single().ConstantValue);
            Assert.AreEqual(9U, compilation.CSharpCompilation.GetTypeByMetadataName("Foreign.Apis")!
                .GetMembers("FIRST").OfType<IFieldSymbol>().Single().ConstantValue);
            Assert.AreEqual("Observer.GROUP", compilation.CSharpCompilation.GetTypeByMetadataName("Foreign.Apis")!
                .GetMembers("FIRST").OfType<IFieldSymbol>().Single().GetAttributes()
                .Single(attribute => attribute.AttributeClass?.ToDisplayString() == "System.ObsoleteAttribute")
                .ConstructorArguments.Single().Value);
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
        public void SourceBoundLogicalContributionsComposeAcrossCommonAndTargetInputs()
        {
            foreach (string architecture in new[] { "x86", "x64", "arm64", "crossarch" })
            {
                using var fixture = DeclarationFixture(architecture);
                string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
                File.WriteAllText(Path.Combine(common, "Owner.header-types.cs"),
                    LogicalProvider(fixture, "x86", "Owner", true, includeSecond: true));
                foreach (string target in DeclarationTargets(architecture))
                {
                    WriteDeclaration(fixture, target, "First.header-types.cs",
                        LogicalProvider(fixture, target, "Observer", false));
                    WriteDeclaration(fixture, target, "Consumer.cs",
                        "namespace Observer { public partial struct Carrier { public GROUP Value; } }");
                }
                var compilation = fixture.Compile();
                AssertDeclarationCompilation(compilation);
                var group = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.GROUP")!;
                Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Observer.GROUP"));
                Assert.AreEqual(0, group.ContainingNamespace.GetTypeMembers().Count(type =>
                    type.Name.StartsWith("GROUP____", StringComparison.Ordinal)), architecture);
                CollectionAssert.AreEquivalent(new[] { "FIRST", "SECOND" }, group.GetMembers().OfType<IFieldSymbol>()
                    .Where(field => field.HasConstantValue).Select(field => field.Name).ToArray());
                Assert.AreEqual(1U, group.GetMembers("FIRST").OfType<IFieldSymbol>().Single().ConstantValue);
                Assert.AreEqual(2U, group.GetMembers("SECOND").OfType<IFieldSymbol>().Single().ConstantValue);
                Assert.AreEqual(0, group.GetAttributes().Length, architecture);
                Assert.AreEqual(0, group.GetMembers("SECOND").OfType<IFieldSymbol>().Single().GetAttributes().Length, architecture);
                var declaration = (EnumDeclarationSyntax)group.DeclaringSyntaxReferences.Single().GetSyntax();
                var source = NativeDeclarationSourceProvenance.Read(declaration)!;
                Assert.AreEqual(Architecture.X86, source.SourceArchitecture, architecture);
                Assert.IsTrue(source.TraversedHeader, architecture);
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(group, compilation.CSharpCompilation
                    .GetTypeByMetadataName("Observer.Carrier")!.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
                AssertDeclarationImage(fixture, compilation, "GROUP", "Owner", "Observer");
                using var pe = new PEReader(File.OpenRead(Path.Combine(fixture.DirectoryPath, "NativeDeclaration.winmd")));
                var reader = pe.GetMetadataReader();
                var metadata = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == "Owner" && reader.GetString(type.Name) == "GROUP");
                Assert.AreEqual(0, metadata.GetCustomAttributes().Count, architecture);
                var fields = metadata.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => !field.GetDefaultValue().IsNil).ToArray();
                CollectionAssert.AreEquivalent(new[] { "FIRST", "SECOND" },
                    fields.Select(field => reader.GetString(field.Name)).ToArray(), architecture);
                foreach (var field in fields)
                {
                    Assert.AreEqual(0, field.GetCustomAttributes().Count, architecture);
                    var value = reader.GetConstant(field.GetDefaultValue());
                    Assert.AreEqual(ConstantTypeCode.UInt32, value.TypeCode, architecture);
                    Assert.AreEqual(reader.GetString(field.Name) == "FIRST" ? 1U : 2U,
                        reader.GetBlobReader(value.Value).ReadUInt32(), architecture);
                }
            }
        }

        [TestMethod]
        public void LogicalContributionAdmissionKeepsNativeEnumsAndUnprovenInputsBlocking()
        {
            foreach (bool nativeEnum in new[] { true, false })
            {
                using var fixture = DeclarationFixture("crossarch");
                string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
                string kind = nativeEnum ? "NativeEnum" : "LogicalGroup";
                string text = LogicalProvider(fixture, "x86", "Owner", true, groupKind: kind);
                if (!nativeEnum)
                {
                    var root = CSharpSyntaxTree.ParseText(text).GetRoot();
                    var declaration = root.DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
                    text = root.ReplaceNode(declaration, declaration.WithLeadingTrivia(declaration.GetLeadingTrivia()
                        .Where(trivia => !trivia.ToString().StartsWith("/* Win32Metadata.NativeConstantGroup.",
                            StringComparison.Ordinal)))).ToFullString();
                }
                File.WriteAllText(Path.Combine(common, "Owner.header-types.cs"), text);
                foreach (string target in DeclarationTargets("crossarch"))
                    WriteDeclaration(fixture, target, "Observer.header-types.cs",
                        LogicalProvider(fixture, target, "Observer", false, groupKind: kind));
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message,
                    "error CSSW005: Logical group ownership requires its compiler-bound native constant proof.");
                StringAssert.Contains(error.Message,
                    "Blocked stage 'emitter.namespace-routing': requires valid native provider ownership.");
            }
        }

        [TestMethod]
        public void SourceBoundLogicalContributionsKeepDifferentNativeMemberBindingsBlocking()
        {
            using var fixture = DeclarationFixture("crossarch");
            string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
            File.WriteAllText(Path.Combine(common, "Owner.header-types.cs"),
                LogicalProvider(fixture, "x86", "Owner", true));
            foreach (string target in DeclarationTargets("crossarch"))
                WriteDeclaration(fixture, target, "Observer.header-types.cs",
                    LogicalProvider(fixture, target, "Observer", false, constantsHeaderName: "other-constants.h"));
            var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
            StringAssert.Contains(error.Message, "error WMA003:");
            StringAssert.Contains(error.Message, "Conflicting native constant bindings for 'FIRST'.");
            StringAssert.Contains(error.Message, "Blocked stage 'emitter.source-cleaning': requires valid logical enum composition.");
        }

        [TestMethod]
        public void LiteralAlternativesKeepOriginalContributionsAndCommonOnlyApplicability()
        {
            foreach (string architecture in new[] { "x86", "x64", "arm64", "crossarch" })
            {
                using var fixture = DeclarationFixture(architecture);
                var originals = new List<NativeLogicalGroupInput>();
                string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
                string text = LiteralLogicalProvider(fixture, "x86", "Common", false,
                    "common-constants.h", includeSecond: true);
                File.WriteAllText(Path.Combine(common, "Common.header-types.cs"), text);
                SaveOriginal(text, Architecture.All, commonProjection: true);
                foreach (string target in DeclarationTargets(architecture))
                {
                    foreach (var (ns, owner, header) in new[]
                    {
                        ("Owner", true, "common-constants.h"), ("Observer", false, "other-constants.h"),
                    })
                    {
                        text = LiteralLogicalProvider(fixture, target, ns, owner, header);
                        WriteDeclaration(fixture, target, ns + ".header-types.cs", text);
                        SaveOriginal(text, DeclarationArchitecture(target));
                    }
                    WriteDeclaration(fixture, target, "Consumer.cs",
                        "namespace Observer { public partial struct Carrier { public GROUP Value; } }");
                }
                var compilation = fixture.Compile();
                AssertDeclarationCompilation(compilation);
                var group = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.GROUP")!;
                Assert.AreEqual(SpecialType.System_UInt16, group.EnumUnderlyingType!.SpecialType);
                CollectionAssert.AreEquivalent(new[] { "FIRST", "SECOND" }, group.GetMembers().OfType<IFieldSymbol>()
                    .Where(field => field.HasConstantValue).Select(field => field.Name).ToArray());
                Assert.AreEqual((ushort)1, group.GetMembers("FIRST").OfType<IFieldSymbol>().Single().ConstantValue);
                Assert.AreEqual((ushort)2, group.GetMembers("SECOND").OfType<IFieldSymbol>().Single().ConstantValue);
                Assert.IsTrue(SymbolEqualityComparer.Default.Equals(group, compilation.CSharpCompilation
                    .GetTypeByMetadataName("Observer.Carrier")!.GetMembers("Value").OfType<IFieldSymbol>().Single().Type));
                Assert.AreEqual(0, group.ContainingNamespace.GetTypeMembers().Count(type =>
                    type.Name.StartsWith("GROUP____", StringComparison.Ordinal)));
                var declaration = (EnumDeclarationSyntax)group.DeclaringSyntaxReferences.Single().GetSyntax();
                var composition = NativeLogicalGroupCompositionProvenance.Read(declaration)!;
                Assert.IsNotNull(composition);
                Assert.IsNull(NativeDeclarationSourceProvenance.Read(declaration));
                Assert.IsNull(NativeConstantGroupProvenance.Read(declaration));
                CollectionAssert.AreEquivalent(originals.Select(input => JsonSerializer.Serialize(input)).ToArray(),
                    composition.Inputs.Select(input => JsonSerializer.Serialize(input)).ToArray(), architecture);
                Assert.AreEqual(1 + 2 * DeclarationTargets(architecture).Length, composition.Inputs.Length);
                Assert.IsTrue(composition.Inputs.All(input => input.Source.SourceArchitecture != Architecture.All));
                var commonInput = composition.Inputs.Single(input => input.Source.Namespace == "Common");
                Assert.AreEqual(Architecture.X86, commonInput.Source.SourceArchitecture);
                Assert.AreEqual(Architecture.All, commonInput.ProjectedArchitectures);
                Assert.IsTrue(commonInput.CommonProjection);
                Assert.AreEqual(2, commonInput.Constants.Group.Members.Length);
                var alternative = composition.Alternatives.Single();
                Assert.AreEqual("FIRST", alternative.Member);
                Assert.AreEqual(2, alternative.Definitions.Length);
                Assert.AreEqual(composition.Inputs.Length, alternative.Occurrences.Length);
                Assert.AreEqual(composition.Inputs.Length + 1, composition.Inputs.Sum(input =>
                    input.Constants.Group.Members.Sum(member => member.Occurrences.Length)));
                Assert.IsTrue(composition.Inputs.SelectMany(input => input.Constants.Group.Members)
                    .All(member => member.Bindings.Length == 1));
                string signature = NativeLogicalGroupCompositionProvenance.GetSignature(declaration);
                var renamed = declaration.WithIdentifier(SyntaxFactory.Identifier("GROUP____1"));
                foreach (var target in new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
                    Assert.AreEqual(signature, NativeLogicalGroupCompositionProvenance.GetSignature(renamed, target));
                var reparsed = CSharpSyntaxTree.ParseText("namespace Owner {\n" + renamed.ToFullString() + "\n}")
                    .GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
                Assert.AreEqual(JsonSerializer.Serialize(composition),
                    JsonSerializer.Serialize(NativeLogicalGroupCompositionProvenance.Read(reparsed)));
                var donor = NativeDeclarationSourceProvenance.Attach(renamed, originals[0].Source);
                Assert.ThrowsException<InvalidDataException>(() => NativeLogicalGroupCompositionProvenance.Read(donor));
                var missingCommonMember = renamed.WithMembers(SyntaxFactory.SeparatedList(renamed.Members
                    .Where(member => member.Identifier.ValueText != "SECOND")));
                Assert.ThrowsException<InvalidDataException>(() => NativeLogicalGroupCompositionProvenance.Read(missingCommonMember));
                if (architecture == "crossarch")
                    foreach (string control in new[] { "missing-occurrence", "missing-input", "duplicate-input", "projection", "unknown" })
                    {
                        var json = JObject.FromObject(composition);
                        if (control == "missing-occurrence")
                            ((JArray)json["Alternatives"]![0]!["Occurrences"]!).RemoveAt(0);
                        else if (control == "missing-input")
                            ((JArray)json["Inputs"]!).RemoveAt(0);
                        else if (control == "duplicate-input")
                            ((JArray)json["Inputs"]!).Add(json["Inputs"]![0]!.DeepClone());
                        else if (control == "projection")
                            ((JArray)json["Inputs"]!).OfType<JObject>().First(input => !input["CommonProjection"]!.Value<bool>())
                                ["ProjectedArchitectures"] = (int)Architecture.All;
                        else
                            json["Unknown"] = true;
                        var malformed = renamed.WithLeadingTrivia(renamed.GetLeadingTrivia().Select(trivia =>
                            trivia.ToString().StartsWith("/* Win32Metadata.NativeLogicalGroupComposition.", StringComparison.Ordinal)
                                ? SyntaxFactory.Comment("/* Win32Metadata.NativeLogicalGroupComposition.v1 " +
                                    json.ToString(Newtonsoft.Json.Formatting.None) + " */") : trivia));
                        Assert.ThrowsException<InvalidDataException>(() => NativeLogicalGroupCompositionProvenance.Read(malformed), control);
                    }
                AssertDeclarationImage(fixture, compilation, "GROUP", "Owner", "Observer");
                using var pe = new PEReader(File.OpenRead(Path.Combine(fixture.DirectoryPath, "NativeDeclaration.winmd")));
                var reader = pe.GetMetadataReader();
                var metadata = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == "Owner" && reader.GetString(type.Name) == "GROUP");
                Assert.AreEqual(0, metadata.GetCustomAttributes().Count);
                var fields = metadata.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => !field.GetDefaultValue().IsNil).ToArray();
                CollectionAssert.AreEquivalent(new[] { "FIRST", "SECOND" },
                    fields.Select(field => reader.GetString(field.Name)).ToArray());
                foreach (var field in fields)
                {
                    var value = reader.GetConstant(field.GetDefaultValue());
                    Assert.AreEqual(ConstantTypeCode.UInt16, value.TypeCode);
                    Assert.AreEqual(reader.GetString(field.Name) == "FIRST" ? (ushort)1 : (ushort)2,
                        reader.GetBlobReader(value.Value).ReadUInt16());
                }
                var consumer = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                    reader.GetString(type.Namespace) == "Observer" && reader.GetString(type.Name) == "Carrier");
                var signatureReader = reader.GetBlobReader(reader.GetFieldDefinition(consumer.GetFields().Single()).Signature);
                Assert.AreEqual(SignatureKind.Field, signatureReader.ReadSignatureHeader().Kind);
                Assert.AreEqual(SignatureTypeCode.TypeHandle, signatureReader.ReadSignatureTypeCode());
                var referenced = signatureReader.ReadTypeHandle();
                if (referenced.Kind == HandleKind.TypeDefinition)
                {
                    var type = reader.GetTypeDefinition((TypeDefinitionHandle)referenced);
                    Assert.AreEqual("Owner.GROUP", reader.GetString(type.Namespace) + "." + reader.GetString(type.Name));
                }
                else
                {
                    Assert.AreEqual(HandleKind.TypeReference, referenced.Kind);
                    var type = reader.GetTypeReference((TypeReferenceHandle)referenced);
                    Assert.AreEqual("Owner.GROUP", reader.GetString(type.Namespace) + "." + reader.GetString(type.Name));
                }

                void SaveOriginal(string source, Architecture projected, bool commonProjection = false)
                {
                    var original = CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes()
                        .OfType<EnumDeclarationSyntax>().Single();
                    originals.Add(new NativeLogicalGroupInput(NativeDeclarationSourceProvenance.Read(original)!,
                        NativeConstantGroupProvenance.Read(original)!, projected, commonProjection));
                }
            }
        }

        [TestMethod]
        public void LiteralAlternativesRejectUnclaimedMixedForeignAndFoldedProofs()
        {
            foreach (string control in new[] { "unclaimed", "mixed", "foreign", "folded" })
            {
                using var fixture = DeclarationFixture("crossarch");
                string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
                File.WriteAllText(Path.Combine(common, "Owner.header-types.cs"),
                    LiteralLogicalProvider(fixture, "x86", "Owner", true, "common-constants.h"));
                foreach (string target in DeclarationTargets("crossarch"))
                {
                    string ns = control == "foreign" ? "Owner" : "Observer";
                    string text = LiteralLogicalProvider(fixture, target, ns, control == "foreign",
                        "other-constants.h", proveLiteral: control != "unclaimed",
                        folded: control == "folded", carrierHeader: control == "foreign" ? "foreign-native.h" : "literal-native.h");
                    if (control == "mixed")
                    {
                        text = RewriteLiteralProof(text, json =>
                        {
                            ((JObject)json["Group"]!).Remove("DefinitionEvidence");
                            foreach (JObject member in (JArray)json["Group"]!["Members"]!)
                                member.Remove("Occurrences");
                        }, "v1");
                    }
                    WriteDeclaration(fixture, target, "Target.header-types.cs", text);
                }
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile(), control);
                StringAssert.Contains(error.Message, "error WMA003:");
                StringAssert.Contains(error.Message, "Conflicting native constant bindings for 'FIRST'.");
            }
        }

        [TestMethod]
        public void ClaimedLiteralEvidenceIsValidatedInBothTransportsEvenForEqualBindings()
        {
            using (var legacy = DeclarationFixture("x86"))
            {
                var declaration = CSharpSyntaxTree.ParseText(LogicalProvider(legacy, "x86", "Owner", true))
                    .GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
                var source = NativeConstantGroupProvenance.Read(declaration)!;
                foreach (string path in new[] { "", "Group", "Group.Members[0].Bindings[0]" })
                {
                    var json = JObject.FromObject(source);
                    var target = path.Length == 0 ? json : (JObject)json.SelectToken(path)!;
                    target["Unknown"] = true;
                    Assert.ThrowsException<InvalidDataException>(() => NativeConstantGroupProvenance.Read(
                        ReplaceLiteralProof(declaration, json.ToString(Newtonsoft.Json.Formatting.None), "v1")), path);
                }
            }
            foreach (string control in new[] { "version", "unknown", "duplicate", "missing", "null-occurrences",
                "duplicate-occurrence", "carrier", "operand", "compound-zero", "compound-one", "literal", "typed-number",
                "nonliteral-valid", "nonliteral-empty-argument", "nonliteral-reversed-argument",
                "nonliteral-empty-attribute", "nonliteral-reversed-attribute", "nonliteral-outside-attribute" })
            {
                using var fixture = DeclarationFixture("x86");
                string text = LiteralLogicalProvider(fixture, "x86", "Owner", true, "same-constants.h");
                string peer = LiteralLogicalProvider(fixture, "x86", "Observer", false, "same-constants.h");
                var original = CSharpSyntaxTree.ParseText(text).GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
                var peerDeclaration = CSharpSyntaxTree.ParseText(peer).GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
                var source = NativeConstantGroupProvenance.Read(original)!;
                Assert.IsTrue(source.Group.Members.Single().Bindings.SequenceEqual(
                    NativeConstantGroupProvenance.Read(peerDeclaration)!.Group.Members.Single().Bindings));
                if (control == "carrier")
                {
                    var changed = JObject.FromObject(source);
                    changed["Group"]!["DefinitionEvidence"]!["Carrier"]!["HeaderHash"] = new string('B', 64);
                    Assert.ThrowsException<InvalidDataException>(() => NativeConstantGroupProvenance.Read(
                        ReplaceLiteralProof(original, changed.ToString(Newtonsoft.Json.Formatting.None), "v2")));
                }
                var json = JObject.FromObject(source);
                var group = (JObject)json["Group"]!;
                var member = (JObject)group["Members"]![0]!;
                var occurrence = (JObject)member["Occurrences"]![0]!;
                if (control.StartsWith("nonliteral-", StringComparison.Ordinal))
                {
                    occurrence.Remove("Literal");
                    if (control.Contains("-empty-", StringComparison.Ordinal))
                    {
                        string range = control.EndsWith("-argument", StringComparison.Ordinal) ? "Argument" : "Attribute";
                        occurrence[range + "End"] = occurrence[range + "Start"]!.DeepClone();
                    }
                    else if (control.Contains("-reversed-", StringComparison.Ordinal))
                    {
                        string range = control.EndsWith("-argument", StringComparison.Ordinal) ? "Argument" : "Attribute";
                        var start = occurrence[range + "Start"]!.DeepClone();
                        occurrence[range + "Start"] = occurrence[range + "End"]!.DeepClone();
                        occurrence[range + "End"] = start;
                    }
                    else if (control == "nonliteral-outside-attribute")
                    {
                        occurrence["ArgumentEnd"] = occurrence["AttributeEnd"]!.DeepClone();
                        occurrence["ArgumentEnd"]!["Offset"] = occurrence["AttributeEnd"]!["Offset"]!.Value<uint>() + 1;
                        occurrence["ArgumentEnd"]!["Column"] = occurrence["AttributeEnd"]!["Column"]!.Value<uint>() + 1;
                    }
                }
                switch (control)
                {
                    case "version": group["DefinitionEvidence"]!["Version"] = 99; break;
                    case "unknown": group["DefinitionEvidence"]!["Unknown"] = true; break;
                    case "missing": ((JObject)group["DefinitionEvidence"]!["Carrier"]!).Remove("TraversedHeader"); break;
                    case "null-occurrences":
                        group.Remove("DefinitionEvidence");
                        member["Occurrences"] = null;
                        break;
                    case "duplicate-occurrence": ((JArray)member["Occurrences"]!).Add(occurrence.DeepClone()); break;
                    case "carrier": group["DefinitionEvidence"]!["Carrier"]!["Namespace"] = "Foreign"; break;
                    case "operand": occurrence["Binding"]!["HeaderHash"] = new string('B', 64); break;
                    case "compound-zero":
                    case "compound-one":
                        occurrence["ArgumentEnd"]!["Offset"] = occurrence["ArgumentEnd"]!["Offset"]!.Value<uint>() + 2;
                        occurrence["ArgumentEnd"]!["Column"] = occurrence["ArgumentEnd"]!["Column"]!.Value<uint>() + 2;
                        break;
                    case "literal": occurrence["Literal"]!["Literal"] = "2"; break;
                    case "typed-number": occurrence["ArgumentStart"]!["Offset"] = "5"; break;
                }
                string privateJson = json.ToString(Newtonsoft.Json.Formatting.None);
                if (control == "duplicate")
                    privateJson = privateJson.Replace("\"Version\":1", "\"Version\":1,\"Version\":1", StringComparison.Ordinal);
                var malformed = ReplaceLiteralProof(original, privateJson, "v2");
                if (control == "nonliteral-valid")
                    Assert.IsNotNull(NativeConstantGroupProvenance.Read(malformed));
                else
                    AssertOccurrenceDiagnostic(Assert.ThrowsException<InvalidDataException>(
                        () => NativeConstantGroupProvenance.Read(malformed), control));
                var values = JObject.FromObject(new NativeConstantValues
                {
                    SourceFile = source.SourceFile, SourceHash = source.SourceHash, Architecture = source.Architecture,
                    Namespace = source.Group.Namespace, Groups = new() { source.Group },
                });
                values["Groups"]![0] = group.DeepClone();
                string nativeJson = values.ToString(Newtonsoft.Json.Formatting.None);
                if (control == "duplicate")
                    nativeJson = nativeJson.Replace("\"Version\":1", "\"Version\":1,\"Version\":1", StringComparison.Ordinal);
                if (control == "nonliteral-valid")
                    Assert.IsNotNull(NativeConstantGroupProvenance.ReadValues(nativeJson));
                else
                    AssertOccurrenceDiagnostic(Assert.ThrowsException<InvalidDataException>(
                        () => NativeConstantGroupProvenance.ReadValues(nativeJson), control));

                void AssertOccurrenceDiagnostic(InvalidDataException error)
                {
                    if (!control.StartsWith("nonliteral-", StringComparison.Ordinal))
                        return;
                    StringAssert.Contains(error.Message, $"'{source.Group.Namespace}.{source.Group.Name}'");
                    StringAssert.Contains(error.Message, $"({source.Architecture})");
                    const string marker = "Occurrence=";
                    int start = error.Message.IndexOf(marker, StringComparison.Ordinal);
                    Assert.IsTrue(start >= 0, error.Message);
                    Assert.IsTrue(JToken.DeepEquals(occurrence,
                        JObject.Parse(error.Message.Substring(start + marker.Length))), error.Message);
                }
            }
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
        public void SingleCommonNativeOwnerRemovesOnlyEquivalentIndirectForwards()
        {
            using var fixture = DeclarationFixture("crossarch");
            string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
            File.WriteAllText(Path.Combine(common, "Owner.cs"), IncompleteProvider(fixture, "x86", "Owner", true));
            foreach (string target in DeclarationTargets("crossarch"))
                WriteDeclaration(fixture, target, "Observer.cs", IncompleteProvider(fixture, target, "Observer", false) +
                    "namespace Observer { public unsafe partial struct Carrier { public VALUE* Pointer; } }");
            var compilation = fixture.Compile();
            AssertDeclarationCompilation(compilation);
            var record = compilation.CSharpCompilation.GetTypeByMetadataName("Owner.VALUE")!;
            Assert.IsNull(compilation.CSharpCompilation.GetTypeByMetadataName("Observer.VALUE"));
            var declaration = (StructDeclarationSyntax)record.DeclaringSyntaxReferences.Single().GetSyntax();
            Assert.AreEqual("common", Path.GetFileName(Path.GetDirectoryName(declaration.SyntaxTree.FilePath)));
            Assert.AreEqual(Architecture.X86, NativeDeclarationSourceProvenance.Read(declaration)!.SourceArchitecture);
            Assert.IsNull(NativeRecordSourceProvenance.Read(declaration));
            Assert.IsNull(NativeTypedefSourceProvenance.Read(declaration));
            Assert.AreEqual(0, declaration.Members.Count);
            Assert.IsFalse(declaration.DescendantNodes().Any(node => node is ExpressionSyntax or AttributeSyntax));
            Assert.AreEqual(0, record.GetAttributes().Count(attribute =>
                attribute.AttributeClass?.ToDisplayString() == "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute"));
            var carrier = compilation.CSharpCompilation.GetTypeByMetadataName("Observer.Carrier")!;
            var pointer = (IPointerTypeSymbol)carrier.GetMembers("Pointer").OfType<IFieldSymbol>().Single().Type;
            Assert.IsTrue(SymbolEqualityComparer.Default.Equals(record, pointer.PointedAtType));
            AssertDeclarationImage(fixture, compilation, "VALUE", "Owner", "Observer");
        }

        [TestMethod]
        public void SingleCommonNativeOwnerDoesNotAbsorbCompetingOrAnnotatedForwards()
        {
            foreach (bool competingOwner in new[] { true, false })
            {
                using var fixture = DeclarationFixture("crossarch");
                string common = Directory.CreateDirectory(Path.Combine(fixture.DirectoryPath, "common")).FullName;
                File.WriteAllText(Path.Combine(common, "Owner.cs"), IncompleteProvider(fixture, "x86", "Owner", true));
                if (competingOwner)
                    File.WriteAllText(Path.Combine(common, "SecondOwner.cs"), IncompleteProvider(fixture, "x86", "Owner", true));
                foreach (string target in DeclarationTargets("crossarch"))
                {
                    string observation = IncompleteProvider(fixture, target, "Observer", false);
                    if (!competingOwner)
                        observation = observation.Replace("public partial struct VALUE", "[global::System.Obsolete] public partial struct VALUE",
                            StringComparison.Ordinal);
                    WriteDeclaration(fixture, target, "Observer.cs", observation);
                }
                var error = Assert.ThrowsException<InvalidDataException>(() => fixture.Compile());
                StringAssert.Contains(error.Message, "direct providers for all three architectures");
            }
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
            Assert.AreEqual(1, root.GetProperty("AdditionalInputs").GetArrayLength());
            Assert.AreEqual(1, root.GetProperty("AdditionalConsumers").GetArrayLength());
            var required = root.GetProperty("NamespacePolicy").GetProperty("Lines").EnumerateArray()
                .Select(line => line.GetString()!.Split('=', 2))
                .ToDictionary(parts => parts[0], parts => parts[1]);
            var trees = root.GetProperty("Inputs").EnumerateArray()
                .Concat(root.GetProperty("AdditionalInputs").EnumerateArray()).Select(input =>
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
                ["D2D_COLOR_F___"] = required["D2D_COLOR_F"],
                ["D2D1_COLOR_F___"] = required["D2D1_COLOR_F"],
                ["CGpEffect"] = "Windows.Win32.Graphics.GdiPlus",
            };
            int index = 0;
            foreach (var consumer in root.GetProperty("Consumers").EnumerateArray()
                .Concat(root.GetProperty("AdditionalConsumers").EnumerateArray()))
            {
                string signature = consumer.GetProperty("Signature").GetString()!;
                Assert.AreEqual(consumer.GetProperty("Sha256").GetString(),
                    Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(signature))));
                var imports = consumer.TryGetProperty("Imports", out var retainedImports) ? retainedImports :
                    root.GetProperty("ImportsByOriginalEntry").GetProperty(consumer.GetProperty("OriginalEntry").GetString()!);
                string usings = string.Join("\n", imports.EnumerateArray()
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
            var rawRoutes = NativeNamespaceRoutes(trees.ToArray(), validation, required);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            trees = trees.Select(tree => tree.WithFilePath(Path.ChangeExtension(tree.FilePath, ".modified.cs"))).ToList();
            var recordRoutes = NativeNamespaceRoutes(trees.ToArray(), validation, required);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            CollectionAssert.AreEquivalent(rawRoutes.ToArray(), recordRoutes.ToArray());
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
            var sourceTypes = DeclarationRecords(trees).Where(record =>
                NativeRecordSourceProvenance.Read(record) != null ||
                NativeDeclarationSourceProvenance.Read(record) != null).Select(record =>
                (SyntaxUtils.GetEnclosingNamespace(record), record.Identifier.ValueText)).ToHashSet();
            var moved = trees.Select(tree =>
                NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, required, sourceTypes, recordRoutes,
                    nativeReferenceModels: new[] { original.GetSemanticModel(tree) })).ToArray();
            var processedRequired = new Dictionary<string, string>(required);
            foreach (var route in recordRoutes.GroupBy(route => route.Key.Name))
                if (route.Select(item => item.Value).Distinct().Count() == 1)
                    processedRequired[route.Key] = route.First().Value;
            var cleaned = moved.Select(tree => MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree, new(), new(), new(),
                processedRequired, new(), processedRequired, new(), new(), tree.FilePath, validation: validation)).ToArray();
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
            var final = (CSharpCompilation)mergeLegacy.Invoke(null, new object[] { beforeLegacy, processedRequired, validation })!;
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            foreach (string name in new[] { "D2D_COLOR_F", "D2D1_COLOR_F" })
            {
                Assert.IsNull(final.GetTypeByMetadataName(required[name] + "." + name + "___"));
                Assert.IsNull(final.GetTypeByMetadataName("Windows.Win32.Graphics.Direct2D." + name));
                Assert.IsNotNull(final.GetTypeByMetadataName(required[name] + "." + name));
            }
            Assert.IsNull(final.GetTypeByMetadataName("Windows.Win32.System.WinRT.Pdf.D2D_COLOR_F"));
            var expectedOwners = owners.ToDictionary(pair => pair.Key, pair => pair.Value);
            foreach (string name in required.Keys)
            {
                expectedOwners.Remove(name + "___");
                expectedOwners.Add(name, required[name]);
            }
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
            Assert.AreEqual(34, checkedReferences);
            var nominalType = final.GetTypeByMetadataName("Windows.Win32.Graphics.GdiPlus.CGpEffect")!;
            Assert.AreEqual(1, nominalType.DeclaringSyntaxReferences.Length);
            Assert.AreEqual(SpecialType.System_IntPtr, nominalType.GetMembers("Value").OfType<IFieldSymbol>().Single().Type.SpecialType);

            AssertNativeReferenceIsolation(trees, references, recordRoutes, required);
            AssertManualNamespacePolicyRequiresOneSourceOwner(trees, required);
            AssertRetainedOpaqueProjectionRequiresItsSourceRole(cleaned);
            var alteredManual = beforeLegacy.SyntaxTrees.Single(tree =>
                Path.GetFileName(tree.FilePath) == "Direct2D.manual.modified.cs");
            var mismatched = beforeLegacy.ReplaceSyntaxTree(alteredManual, CSharpSyntaxTree.ParseText(
                alteredManual.GetText().ToString().Replace("float a", "uint a", StringComparison.Ordinal),
                path: alteredManual.FilePath));
            var mismatchValidation = new GenerationValidation();
            mergeLegacy.Invoke(null, new object[] { mismatched, processedRequired, mismatchValidation });
            Assert.IsTrue(mismatchValidation.Errors.Any(error => error.Code == "CSSW005" &&
                error.Stage == "emitter.legacy-typedef-composition"));
        }

        private static CSharpCompilation ManagedNativeReferenceCompilation(IEnumerable<SyntaxTree> trees,
            IEnumerable<MetadataReference> references) => CSharpCompilation.Create("OriginalNativeReferenceHandoffs",
                trees, references, new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));

        private static Dictionary<(string Namespace, string Name), string> NativeNamespaceRoutes(
            SyntaxTree[] trees, GenerationValidation validation, Dictionary<string, string>? required = null)
        {
            required ??= new();
            var records = typeof(ClangSharpSourceCompilation).GetMethod("ResolveNativeNamespaces",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var declarations = typeof(ClangSharpSourceCompilation).GetMethod("ResolveNativeDeclarationNamespaces",
                BindingFlags.NonPublic | BindingFlags.Static)!;
            var routes = (Dictionary<(string Namespace, string Name), string>)records.Invoke(null,
                new object[] { trees, required, new Dictionary<string, string>(), validation })!;
            var forwards = (Dictionary<(string Namespace, string Name), string>)declarations.Invoke(null,
                new object[] { trees, required, routes, validation })!;
            foreach (var pair in forwards)
            {
                if (routes.TryGetValue(pair.Key, out string? previous))
                    Assert.AreEqual(previous, pair.Value);
                routes[pair.Key] = pair.Value;
            }
            return routes;
        }

        private static void AssertManualNamespacePolicyRequiresOneSourceOwner(IEnumerable<SyntaxTree> inputs,
            Dictionary<string, string> required)
        {
            var manual = inputs.Single(tree => Path.GetFileName(tree.FilePath) == "Direct2D.manual.modified.cs");
            var other = CSharpSyntaxTree.ParseText(manual.GetText().ToString()
                .Replace("Windows.Win32.Graphics.Direct2D", "ForeignManual", StringComparison.Ordinal),
                path: "Foreign.manual.modified.cs");
            var ambiguous = new GenerationValidation();
            NativeNamespaceRoutes(inputs.Append(other).ToArray(), ambiguous, required);
            foreach (string name in required.Keys)
                Assert.IsTrue(ambiguous.Errors.Any(error => error.Code == "CSSW005" &&
                    error.Stage == "emitter.record-ownership" && error.Symbol == name + "___"));
            var conflict = new GenerationValidation();
            NativeNamespaceRoutes(inputs.ToArray(), conflict, new Dictionary<string, string>(required)
            {
                ["D2D_COLOR_F___"] = "Foreign",
            });
            Assert.IsTrue(conflict.Errors.Any(error => error.Code == "CSSW005" &&
                error.Stage == "emitter.record-ownership"));
        }

        private static void AssertNativeReferenceIsolation(IEnumerable<SyntaxTree> inputs,
            IEnumerable<MetadataReference> references, Dictionary<(string Namespace, string Name), string> routes,
            Dictionary<string, string> required)
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
                var moved = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(tree, required,
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
            var nativeRoutes = NativeNamespaceRoutes(originalInputs, validation, required);
            Assert.AreEqual(0, validation.BlockingErrorCount, validation.Format());
            var nativeCompilation = ManagedNativeReferenceCompilation(originalInputs, references);
            var unchanged = NamesToCorrectNamespacesMover.MoveNamesToCorrectNamespaces(nativeAmbiguous, required,
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
            string member = "FIRST", uint value = 1, string headerName = "native-shared.h", string nativeName = "GROUP",
            string constantsHeaderName = "constants.h", string groupKind = "LogicalGroup", bool includeSecond = false)
        {
            string header = DeclarationHeader(fixture, headerName, "typedef unsigned int GROUP;\n");
            string constants = DeclarationHeader(fixture, constantsHeaderName, "#define FIRST 1\n#define SECOND 2\n");
            string main = DeclarationHeader(fixture, "main.cpp", "#include \"native-shared.h\"\n");
            string expression = $"unchecked((uint){value}UL)";
            var declaration = (EnumDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                $"public enum GROUP : uint {{ {member} = {expression} }}")!;
            var binding = new NativeConstantBinding("Macro", member, constants,
                member == "FIRST" ? 1U : 2U, 1, NativeConstantGroupProvenance.HashFile(constants),
                "int", "uint", value.ToString(System.Globalization.CultureInfo.InvariantCulture));
            var members = new[] { new NativeConstantGroupMember(member, expression, new[] { binding }) };
            if (includeSecond)
            {
                string second = "unchecked((uint)2UL)";
                declaration = declaration.AddMembers(SyntaxFactory.EnumMemberDeclaration("SECOND")
                    .WithEqualsValue(SyntaxFactory.EqualsValueClause(SyntaxFactory.ParseExpression(second))));
                members = members.Append(new NativeConstantGroupMember("SECOND", second,
                    new[] { binding with { NativeName = "SECOND", Line = 2, Value = "2" } })).ToArray();
            }
            var group = new NativeConstantGroup("::" + nativeName, "GROUP", ns, "uint", header, 1,
                members) { Kind = groupKind };
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

        private static string LiteralLogicalProvider(Fixture fixture, string architecture, string ns, bool owner,
            string constantsHeader, bool includeSecond = false, bool proveLiteral = true, bool folded = false,
            string carrierHeader = "literal-native.h")
        {
            string header = DeclarationHeader(fixture, carrierHeader, "typedef unsigned short GROUP;\n");
            string constants = DeclarationHeader(fixture, constantsHeader, "#define FIRST 1\n#define SECOND 2\n");
            string id = ns + "-" + architecture + "-" + constantsHeader + "-" + carrierHeader;
            string argument = DeclarationHeader(fixture, id + ".arguments.h",
                includeSecond ? "Enum(FIRST, SECOND)" : "Enum(FIRST)");
            string argumentText = File.ReadAllText(argument);
            string main = DeclarationHeader(fixture, id + ".cpp", "#include \"" + carrierHeader + "\"\n");
            var source = new NativeDeclarationSource("c:" + carrierHeader + "@T@GROUP", "GROUP", header,
                NativeConstantGroupProvenance.HashFile(header), 1, 23, "GROUP", ns, owner, NativeDeclarationKind.LogicalEnum)
                { SourceArchitecture = DeclarationArchitecture(architecture) };
            var members = new List<NativeConstantGroupMember>();
            foreach (string name in includeSecond ? new[] { "FIRST", "SECOND" } : new[] { "FIRST" })
            {
                string value = name == "FIRST" ? "1" : "2";
                var binding = new NativeConstantBinding("Macro", name, constants, name == "FIRST" ? 1U : 2U, 9,
                    NativeConstantGroupProvenance.HashFile(constants), "int", "int", value);
                var occurrence = Occurrence(binding, argument, argumentText);
                var bindings = new[] { binding };
                var occurrences = new[] { occurrence };
                if (folded)
                {
                    string other = DeclarationHeader(fixture, "folded-" + constantsHeader, "#define FIRST 1\n#define SECOND 2\n");
                    var second = binding with { Header = other, HeaderHash = NativeConstantGroupProvenance.HashFile(other) };
                    string foldedArgument = DeclarationHeader(fixture, "folded-" + id + ".arguments.h", "Enum(FIRST)");
                    bindings = bindings.Append(second).ToArray();
                    occurrences = occurrences.Append(Occurrence(second, foldedArgument, "Enum(FIRST)")).ToArray();
                }
                members.Add(new NativeConstantGroupMember(name, $"unchecked((ushort){value}UL)", bindings)
                    { Occurrences = occurrences });
            }
            var group = new NativeConstantGroup("::GROUP", "GROUP", ns, "ushort", argument, 1, members.ToArray())
                { DefinitionEvidence = new NativeLogicalGroupEvidence(1, source) };
            var declaration = (EnumDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration("public enum GROUP : ushort { }")!;
            declaration = declaration.WithMembers(SyntaxFactory.SeparatedList(members.Select(member =>
                SyntaxFactory.EnumMemberDeclaration(member.Name).WithEqualsValue(
                    SyntaxFactory.EqualsValueClause(SyntaxFactory.ParseExpression(member.Expression))))));
            declaration = NativeConstantGroupProvenance.Attach(declaration,
                new NativeConstantGroupSource(main, NativeConstantGroupProvenance.HashFile(main),
                    DeclarationArchitecture(architecture), group));
            declaration = NativeDeclarationSourceProvenance.Attach(declaration, source);
            return $"namespace {ns} {{\n{declaration.ToFullString()}\n}}";

            NativeConstantOccurrence Occurrence(NativeConstantBinding binding, string path, string contents)
            {
                string hash = NativeConstantGroupProvenance.HashFile(path);
                int start = contents.IndexOf(binding.NativeName, StringComparison.Ordinal);
                var argumentStart = new NativeConstantSite(path, hash, 1, (uint)start + 1, (uint)start);
                var argumentEnd = argumentStart with
                    { Column = argumentStart.Column + (uint)binding.NativeName.Length, Offset = argumentStart.Offset + (uint)binding.NativeName.Length };
                string definition = File.ReadAllText(binding.Header);
                int definitionStart = definition.IndexOf(binding.NativeName, StringComparison.Ordinal);
                int definitionEnd = definition.IndexOf('\n', definitionStart);
                var nativeStart = new NativeConstantSite(binding.Header, binding.HeaderHash, binding.Line,
                    binding.Column, (uint)definitionStart);
                var nativeEnd = nativeStart with
                    { Column = nativeStart.Column + (uint)(definitionEnd - definitionStart), Offset = (uint)definitionEnd };
                return new NativeConstantOccurrence(binding, new NativeConstantSite(path, hash, 1, 1, 0),
                    new NativeConstantSite(path, hash, 1, (uint)contents.Length + 1, (uint)contents.Length), argumentStart, argumentEnd)
                {
                    Literal = proveLiteral ? new NativeLiteralMacroProof(binding.Value,
                        argumentStart, argumentEnd, nativeStart, nativeEnd) : null,
                };
            }
        }

        private static string RewriteLiteralProof(string text, Action<JObject> edit, string version)
        {
            var root = CSharpSyntaxTree.ParseText(text).GetRoot();
            var declaration = root.DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            var json = JObject.FromObject(NativeConstantGroupProvenance.Read(declaration)!);
            edit(json);
            return root.ReplaceNode(declaration, ReplaceLiteralProof(declaration,
                json.ToString(Newtonsoft.Json.Formatting.None), version)).ToFullString();
        }

        private static EnumDeclarationSyntax ReplaceLiteralProof(EnumDeclarationSyntax declaration, string json, string version) =>
            declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Select(trivia =>
                trivia.ToString().StartsWith("/* Win32Metadata.NativeConstantGroup.", StringComparison.Ordinal)
                    ? SyntaxFactory.Comment("/* Win32Metadata.NativeConstantGroup." + version + " " + json + " */") : trivia));

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
