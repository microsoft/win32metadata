using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void ExplicitHeaderPrioritySelectsTheCompilerEvaluatedHresult(
            string architecture, string target, bool preferredHeaderFirst)
        {
            VerifyNativeHeaderPriority(architecture, target, preferredHeaderFirst, explicitPriority: true);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void UnlistedHeadersRetainActualTraversalFirstWins(
            string architecture, string target, bool preferredHeaderFirst)
        {
            VerifyNativeHeaderPriority(architecture, target, preferredHeaderFirst, explicitPriority: false);
        }

        private static void VerifyNativeHeaderPriority(
            string architecture, string target, bool preferredHeaderFirst, bool explicitPriority)
        {
            using var first = NewNamespaceOwnershipFixture(architecture, target,
                "#include \"sdk\\um\\infotech.h\"\nint F();");
            string sdk = Path.Combine(first.DirectoryPath, "sdk");
            string original = Path.Combine(sdk, "um", "infotech.h");
            string preferred = Path.Combine(sdk, "um", "devicetopology.h");
            Directory.CreateDirectory(Path.GetDirectoryName(original));
            File.WriteAllText(original, "typedef long HRESULT;\n#define _HRESULT_TYPEDEF_(value) ((HRESULT)(value))\n" +
                "#define E_NOTFOUND _HRESULT_TYPEDEF_(0x8000100DL)\n");
            File.WriteAllText(preferred, "typedef long HRESULT;\n#define ERROR_NOT_FOUND 1168L\n" +
                "#define HRESULT_FROM_WIN32(value) ((HRESULT)((value) <= 0 ? (value) : (((value) & 0xffff) | 0x80070000)))\n" +
                "#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)\n");
            using var second = NewNamespaceOwnershipFixture(architecture, target,
                "#include \"" + preferred + "\"\nint G();");
            AppendNativeTraversal(first, original);
            AppendNativeTraversal(second, preferred);
            try
            {
                first.AssertSuccess();
                second.AssertSuccess();
                string additional = Path.Combine(Path.GetDirectoryName(first.Output), "Other.native-constants.json");
                File.Copy(Path.ChangeExtension(second.Output, ".native-constants.json"), additional);
                var native = new[] { first, second }.Select(fixture => Assert.Single(
                    NativeConstantExtractionTests.Read(fixture).Constants.Where(value => value.Name == "E_NOTFOUND"))).ToArray();
                Assert.Equal(new[] { original, preferred }, native.Select(value => value.Header));
                Assert.Equal(2, native.Select(value => value.Value).Distinct().Count());
                Assert.All(native, value =>
                {
                    Assert.Equal("HRESULT", value.NativeType);
                    Assert.Equal(NativeConstantGroupProvenance.HashFile(value.Header), value.HeaderHash);
                    Assert.True(value.Line > 0 && value.Column > 0);
                });
                var headers = preferredHeaderFirst
                    ? new Dictionary<string, string> { [preferred] = "Audio", [original] = "HtmlHelp" }
                    : new Dictionary<string, string> { [original] = "HtmlHelp", [preferred] = "Audio" };
                var result = SelectNativeConstants(first.DirectoryPath, headers, new ConstantSelectionOptions
                {
                    SdkRoot = sdk,
                    HeaderPriority = explicitPriority ? new[] { @"um\devicetopology.h" } : Array.Empty<string>(),
                    NativeInputs = new[] { additional, Path.ChangeExtension(first.Output, ".native-constants.json") },
                });
                bool canonical = explicitPriority || preferredHeaderFirst;
                string expectedHeader = canonical ? preferred : original;
                Assert.Contains(result.Output, message => message.StartsWith("warning WMC001:") &&
                    message.Contains("E_NOTFOUND") && message.Contains("TYPE/VALUE CONFLICT"));
                using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
                var decision = report.RootElement.GetProperty("Decisions").EnumerateArray()
                    .Single(value => value.GetProperty("Name").GetString() == "E_NOTFOUND");
                Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
                Assert.True(decision.GetProperty("DistinctNativeDefinitions").GetBoolean());
                Assert.Equal(expectedHeader, decision.GetProperty("Selected").GetProperty("RawHeader").GetString());
                var candidates = decision.GetProperty("Candidates").EnumerateArray().ToArray();
                Assert.Equal(2, candidates.Length);
                Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "selected"));
                Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "discarded-by-policy"));
                Assert.All(candidates, value =>
                {
                    Assert.Equal("E_NOTFOUND", value.GetProperty("NativeName").GetString());
                    Assert.Equal("HRESULT", value.GetProperty("NativeType").GetString());
                    Assert.True(value.GetProperty("Line").GetUInt32() > 0);
                    Assert.True(value.GetProperty("Column").GetUInt32() > 0);
                    Assert.False(string.IsNullOrEmpty(value.GetProperty("Reason").GetString()));
                });
                using var image = Emit(first.DirectoryPath, architecture);
                var owner = image.Reader.TypeDefinitions.Select(image.Reader.GetTypeDefinition).Single(type =>
                    type.GetFields().Select(image.Reader.GetFieldDefinition).Any(field => image.Reader.GetString(field.Name) == "E_NOTFOUND"));
                Assert.Equal(canonical ? "Audio" : "HtmlHelp", image.Reader.GetString(owner.Namespace));
                var field = owner.GetFields().Select(image.Reader.GetFieldDefinition)
                    .Single(field => image.Reader.GetString(field.Name) == "E_NOTFOUND");
                var constant = image.Reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(ConstantTypeCode.Int32, constant.TypeCode);
                Assert.Equal(unchecked((int)(canonical ? 0x80070490 : 0x8000100D)),
                    image.Reader.GetBlobReader(constant.Value).ReadInt32());
                string rawFacts = File.ReadAllText(additional);
                string before = File.ReadAllText(result.ConflictReport);
                SelectNativeConstants(first.DirectoryPath, headers, new ConstantSelectionOptions
                {
                    SdkRoot = sdk,
                    HeaderPriority = explicitPriority ? new[] { @"um\devicetopology.h" } : Array.Empty<string>(),
                    NativeInputs = new[] { additional, Path.ChangeExtension(first.Output, ".native-constants.json") },
                });
                Assert.Equal(rawFacts, File.ReadAllText(additional));
                Assert.Equal(before, File.ReadAllText(result.ConflictReport));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(first, $"priority-{architecture}-{preferredHeaderFirst}-{explicitPriority}");
                SaveOpaqueRecordArtifacts(second, $"priority-other-{architecture}-{preferredHeaderFirst}-{explicitPriority}");
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void AbsentPriorityHeaderDoesNotMatchAForeignSameBasename(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#include \"foreign\\um\\devicetopology.h\"\nint F();");
            string sdk = Path.Combine(fixture.DirectoryPath, "sdk");
            string foreign = Path.Combine(fixture.DirectoryPath, "foreign", "um", "devicetopology.h");
            Directory.CreateDirectory(Path.GetDirectoryName(foreign));
            Directory.CreateDirectory(sdk);
            File.WriteAllText(foreign, "#define FOREIGN_VALUE 9U\n");
            AppendNativeTraversal(fixture, foreign);
            fixture.AssertSuccess();
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [foreign] = "Foreign" },
                new ConstantSelectionOptions { SdkRoot = sdk, HeaderPriority = new[] { @"um\devicetopology.h" } });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            Assert.False(Assert.Single(report.RootElement.GetProperty("HeaderPriority").EnumerateArray())
                .GetProperty("Applicable").GetBoolean());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(9U, ReadUInt32Field(image.Reader, "Apis", "FOREIGN_VALUE"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void WithinHeaderPriorityUsesNativeLocationsRatherThanFactOrder(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define FIRST_NATIVE 1U\n#define SECOND_NATIVE 2U\nint F();",
                "--remap\nFIRST_NATIVE=MEMBER\nSECOND_NATIVE=MEMBER\n");
            fixture.AssertSuccess();
            var facts = NativeConstantExtractionTests.Read(fixture);
            facts.Constants.Reverse();
            File.WriteAllText(Path.ChangeExtension(fixture.Output, ".native-constants.json"), JsonSerializer.Serialize(facts));
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Native" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
            Assert.Equal("FIRST_NATIVE", decision.GetProperty("Selected").GetProperty("NativeName").GetString());
            Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(1U, ReadUInt32Field(image.Reader, "Apis", "MEMBER"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void MetadataHelperScopePreservesNativeAllAndLeavesSdkEnumsUnscoped(
            string architecture, string target, bool scopedHelper)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "enum PIPE_TYPE { ALL_PIPE = 3 };\n#define ALL ALL_PIPE\nint F();");
            fixture.AssertSuccess();
            var native = Assert.Single(NativeConstantExtractionTests.Read(fixture).Constants.Where(value => value.Name == "ALL"));
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Windows.Win32.Devices.Usb" });
            string helper = null;
            if (!scopedHelper)
            {
                var root = CSharpSyntaxTree.ParseText(File.ReadAllText(
                    Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"))).GetRoot();
                var architectureType = root.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Single(type => type.Identifier.ValueText == "Architecture");
                var attributes = architectureType.AttributeLists.Select(list => list.WithAttributes(
                    Microsoft.CodeAnalysis.CSharp.SyntaxFactory.SeparatedList(list.Attributes
                        .Where(attribute => attribute.Name.ToString() != "ScopedEnum"))));
                helper = root.ReplaceNode(architectureType, architectureType.WithAttributeLists(
                    Microsoft.CodeAnalysis.CSharp.SyntaxFactory.List(attributes.Where(list => list.Attributes.Count != 0)))).ToFullString();
            }
            using var image = Emit(fixture.DirectoryPath, architecture, metadataSource: helper);
            var metadataArchitecture = FindType(image.Reader, "Architecture");
            if (scopedHelper)
                AssertHasAttribute(image.Reader, metadataArchitecture.GetCustomAttributes(), "ScopedEnumAttribute");
            else
                AssertDoesNotHaveAttribute(image.Reader, metadataArchitecture.GetCustomAttributes(), "ScopedEnumAttribute");
            var all = metadataArchitecture.GetFields().Select(image.Reader.GetFieldDefinition)
                .Single(field => image.Reader.GetString(field.Name) == "All");
            Assert.Equal(7, image.Reader.GetBlobReader(image.Reader.GetConstant(all.GetDefaultValue()).Value).ReadInt32());
            var pipe = FindType(image.Reader, "PIPE_TYPE");
            AssertDoesNotHaveAttribute(image.Reader, pipe.GetCustomAttributes(), "ScopedEnumAttribute");
            var apis = image.Reader.TypeDefinitions.Select(image.Reader.GetTypeDefinition).Single(type =>
                image.Reader.GetString(type.Name) == "Apis" &&
                image.Reader.GetString(type.Namespace) == "Windows.Win32.Devices.Usb");
            var usb = apis.GetFields().Select(image.Reader.GetFieldDefinition)
                .Single(field => image.Reader.GetString(field.Name) == "ALL");
            Assert.Equal(3, image.Reader.GetBlobReader(image.Reader.GetConstant(usb.GetDefaultValue()).Value).ReadInt32());
            Assert.Equal("PIPE_TYPE", native.NativeType);
            var signature = image.Reader.GetBlobReader(usb.Signature);
            Assert.Equal(0x06, signature.ReadByte());
            Assert.Equal(0x11, signature.ReadByte());
            var pipeHandle = signature.ReadTypeHandle();
            Assert.Equal(HandleKind.TypeReference, pipeHandle.Kind);
            var pipeReference = image.Reader.GetTypeReference((TypeReferenceHandle)pipeHandle);
            Assert.Equal("PIPE_TYPE", image.Reader.GetString(pipeReference.Name));
            Assert.Equal(image.Reader.GetString(pipe.Namespace), image.Reader.GetString(pipeReference.Namespace));
            Assert.Equal(0, signature.RemainingBytes);
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), scopedHelper ? 0 : -1);
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            Assert.Equal("Ordinal", report.RootElement.GetProperty("NameComparison").GetString());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CaseSensitiveNativeNamesRemainDistinctWithoutWeakeningTheDuplicateGate(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define ALL 3U\n#define All 7U\nint F();");
            fixture.AssertSuccess();
            SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Native" });
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(3U, ReadUInt32Field(image.Reader, "Apis", "ALL"));
            Assert.Equal(7U, ReadUInt32Field(image.Reader, "Apis", "All"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), -1);
        }

        [Theory]
        [InlineData("source-hash")]
        [InlineData("group-binding")]
        [InlineData("definition-hash")]
        [InlineData("producer-marker")]
        [InlineData("proof-version")]
        [InlineData("proof-namespace")]
        [InlineData("proof-target")]
        public void NativeGroupDriftFailsWithRawFactsRetained(string mutation)
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc", NamespaceOwnedMacro);
            fixture.AssertSuccess();
            string path = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            var values = NativeConstantExtractionTests.Read(fixture);
            string sourcePath = Path.ChangeExtension(fixture.Output, ".header-types.cs");
            if (mutation == "source-hash")
                values.SourceHash = new string('0', 64);
            else if (mutation == "definition-hash")
                values.Constants = values.Constants.Select(value => value with { HeaderHash = new string('0', 64) }).ToList();
            else if (mutation == "group-binding")
            {
                var group = Assert.Single(values.Groups);
                var member = Assert.Single(group.Members);
                values.Groups = new() { group with { Members = new[] { member with
                {
                    Bindings = new[] { Assert.Single(member.Bindings) with { NativeName = "UNRELATED" } },
                } } } };
            }
            else
            {
                string source = File.ReadAllText(sourcePath);
                source = mutation switch
                {
                    "producer-marker" => source.Replace(HeaderTypesSourceFamily.SuccessMarker, "// missing-success-marker"),
                    "proof-version" => source.Replace("Win32Metadata.NativeConstantGroup.v1 ", "Win32Metadata.NativeConstantGroup.v2 "),
                    "proof-namespace" => source.Replace("\"Namespace\":\"Test\"", "\"Namespace\":\"Other\""),
                    "proof-target" => source.Replace("\"Architecture\":1", "\"Architecture\":2"),
                    _ => throw new ArgumentException(nameof(mutation)),
                };
                File.WriteAllText(sourcePath, source);
            }
            File.WriteAllText(path, JsonSerializer.Serialize(values));
            string raw = File.ReadAllText(path);
            Assert.Throws<InvalidDataException>(() =>
                SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" },
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" }));
            Assert.Equal(raw, File.ReadAllText(path));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "native-constant-conflicts.json")));
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
            Assert.Contains(report.RootElement.GetProperty("RawInputs").EnumerateArray(),
                value => value.GetProperty("Contents").GetString() == raw);
        }

        [Fact]
        public void AProtectedNativeBindingValueConflictIsReportedEvenWithOneLooseCandidate()
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc", NamespaceOwnedMacro);
            fixture.AssertSuccess();
            var values = NativeConstantExtractionTests.Read(fixture);
            values.Constants = values.Constants.Select(value => value with { Value = "5U" }).ToList();
            File.WriteAllText(Path.ChangeExtension(fixture.Output, ".native-constants.json"), JsonSerializer.Serialize(values));
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            Assert.Contains(result.Output, value => value.Contains("TYPE/VALUE CONFLICT"));
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
            Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
            Assert.Equal("discarded-by-policy", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                .GetProperty("Disposition").GetString());
            using var image = Emit(fixture.DirectoryPath, "x86", requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            Assert.Equal(new[] { "Canonical.SOURCE_GROUP" }, NamespaceMacroOwners(image.Reader));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "4U")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "8U")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "8U")]
        public void ConstantsOnlyTargetsRetainTheirOwnCompilerGroupBindings(string architecture, string target, string expected)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define MEMBER ((unsigned)sizeof(void*))\n_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\nint F();",
                "--config\nnative-constants-only\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var values = NativeConstantExtractionTests.Read(fixture);
            Assert.Equal(architecture, values.Architecture.ToString().ToLowerInvariant());
            var group = Assert.Single(values.Groups);
            Assert.Equal("SOURCE_GROUP", group.Name);
            var binding = Assert.Single(Assert.Single(group.Members).Bindings);
            Assert.Equal("Macro", binding.Kind);
            Assert.Equal(expected, binding.Value);
            Assert.Equal(expected, Assert.Single(values.Constants).Value);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
        }

        [Fact]
        public void GroupBindingsUseNativeArgumentsRatherThanProjectedLabels()
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc", @"
#define FIRST 4U
#define SECOND 8U
typedef _WIN32META_ANNOTATION_(""Enum(SECOND, FIRST, ZERO)"", FIRST, SECOND, 0U) unsigned SOURCE_GROUP;
int F();
");
            fixture.AssertSuccess();
            var members = Assert.Single(NativeConstantExtractionTests.Read(fixture).Groups).Members;
            Assert.Equal(new[] { "SECOND", "FIRST", "ZERO" }, members.Select(member => member.Name));
            Assert.Equal(new[] { "FIRST", "SECOND", null },
                members.Select(member => Assert.Single(member.Bindings).NativeName));
            Assert.Equal(new[] { "Macro", "Macro", "Expression" },
                members.Select(member => Assert.Single(member.Bindings).Kind));
            SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "native-constant-conflicts.json")));
            Assert.Single(report.RootElement.GetProperty("SourceGroups").EnumerateArray());
            foreach (var decision in report.RootElement.GetProperty("Decisions").EnumerateArray())
            {
                Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
                var candidate = Assert.Single(decision.GetProperty("Candidates").EnumerateArray());
                Assert.Equal("compiler-bound-group-consumption", candidate.GetProperty("Disposition").GetString());
                Assert.Equal("exact-native-member-binding", candidate.GetProperty("Reason").GetString());
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void OldSchemaForeignFactsRemainPolicyDecisionsWithOwnerTargetConflictEvidence(string architecture, string target)
        {
            using var owner = NewNamespaceOwnershipFixture(architecture, target, NamespaceOwnedMacro, "--exclude\nMEMBER\n");
            using var foreign = NewNamespaceOwnershipFixture(architecture, target, "#define MEMBER 5U\nint G();");
            owner.AssertSuccess();
            foreign.AssertSuccess();
            Assert.Empty(NativeConstantExtractionTests.Read(owner).Constants);
            var facts = NativeConstantExtractionTests.Read(foreign);
            string oldPath = Path.Combine(Path.GetDirectoryName(owner.Output), "Other.native-constants.json");
            string oldJson = JsonSerializer.Serialize(new
            {
                facts.Architecture, facts.BindingSource, facts.Namespace, facts.Headers, facts.Issues,
                Constants = facts.Constants.Select(value => new
                {
                    value.NativeName, value.Name, value.Header, value.Line, value.NativeType, value.StorageType, value.Value,
                }).ToArray(),
            });
            File.WriteAllText(oldPath, oldJson);
            var result = SelectNativeConstants(owner.DirectoryPath, new() { [owner.Header] = "Owner", [foreign.Header] = "Foreign" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
            Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
            Assert.Equal("discarded-by-policy", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                .GetProperty("Disposition").GetString());
            var binding = Assert.Single(Assert.Single(decision.GetProperty("Protected").EnumerateArray())
                .GetProperty("NativeBindings").EnumerateArray()).GetProperty("Binding");
            Assert.Equal("4U", binding.GetProperty("Value").GetString());
            Assert.Equal(owner.Header, binding.GetProperty("Header").GetString());
            Assert.Equal(oldJson, File.ReadAllText(oldPath));
            Assert.Contains(result.Output, value => value.Contains("TYPE/VALUE CONFLICT"));
        }

        [Fact]
        public void LargeGroupReportStoresFullProvenanceOnceRatherThanOncePerMember()
        {
            const int count = 256;
            string[] names = Enumerable.Range(0, count).Select(index => $"MEMBER_{index:D4}").ToArray();
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                string.Join("\n", names.Select((name, index) => $"#define {name} {index}U")) +
                $"\n_Win32_Enum_(SOURCE_GROUP, unsigned, {string.Join(", ", names)});\nint F();");
            fixture.AssertSuccess();
            string facts = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            Assert.Single(report.RootElement.GetProperty("SourceGroups").EnumerateArray());
            var decisions = report.RootElement.GetProperty("Decisions").EnumerateArray().ToArray();
            Assert.Equal(count, decisions.Length);
            Assert.All(decisions, decision =>
            {
                Assert.False(decision.GetProperty("TypeValueConflict").GetBoolean());
                Assert.Equal(0, Assert.Single(decision.GetProperty("Protected").EnumerateArray())
                    .GetProperty("Provenance").GetInt32());
                Assert.Equal("compiler-bound-group-consumption", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                    .GetProperty("Disposition").GetString());
            });
            Assert.True(new FileInfo(result.ConflictReport).Length < 16 * new FileInfo(facts).Length,
                "Conflict output must not repeat a complete group proof for each member.");
        }

        [Theory]
        [InlineData("c", "c11", "enum NATIVE { MEMBER = 4 };\n_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\nint F(void);")]
        [InlineData("c++", "c++17", "namespace Scoped { enum NATIVE { MEMBER = 4 }; _Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER); }\nint F();")]
        public void NativeEnumBindingsRetainTheirCompilerIdentity(string language, string standard, string declarations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations,
                extraSettings: $"--language\n{language}\n--std\n{standard}\n--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            var group = Assert.Single(NativeConstantExtractionTests.Read(fixture).Groups);
            Assert.Equal("CXCursor_EnumConstantDecl", Assert.Single(Assert.Single(group.Members).Bindings).Kind);
            Assert.Contains("MEMBER", Assert.Single(Assert.Single(group.Members).Bindings).NativeName);
        }

        private static ScraperResults SelectNativeConstants(string directory, Dictionary<string, string> headers,
            ConstantSelectionOptions selection = null, Dictionary<string, string> requiredNamespaces = null) =>
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory,
                "using System; using Windows.Win32.Foundation.Metadata;", new(), headers,
                requiredNamespaces ?? new(), new(), new(), new(), selection);

        private static void AppendNativeTraversal(HeaderAnnotationTests.NativeFixture fixture, string header) =>
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--traverse\n" + header + "\n");

        private static uint ReadUInt32Field(MetadataReader reader, string type, string name)
        {
            var field = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(value => reader.GetString(value.Name) == type).SelectMany(value => value.GetFields())
                .Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == name);
            var value = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.UInt32, value.TypeCode);
            return reader.GetBlobReader(value.Value).ReadUInt32();
        }

        private static void AssertDuplicateConstantTool(string winmd, int expected)
        {
            using var process = new Process();
            process.StartInfo = new ProcessStartInfo("dotnet")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            process.StartInfo.ArgumentList.Add(Path.Combine(AppContext.BaseDirectory, "WinmdUtils.dll"));
            process.StartInfo.ArgumentList.Add("showDuplicateConstants");
            process.StartInfo.ArgumentList.Add("--winmd");
            process.StartInfo.ArgumentList.Add(winmd);
            process.Start();
            var output = process.StandardOutput.ReadToEndAsync();
            var error = process.StandardError.ReadToEndAsync();
            bool completed = process.WaitForExit(30000);
            if (!completed)
                process.Kill(entireProcessTree: true);
            Assert.True(completed, "Duplicate constant gate did not finish.");
            string stdout = output.GetAwaiter().GetResult();
            string stderr = error.GetAwaiter().GetResult();
            Assert.True(expected == process.ExitCode, stdout + stderr);
            Assert.Equal(expected == 0, stdout.Contains("No duplicate constants/enum names found."));
            Assert.True(string.IsNullOrEmpty(stderr), stderr);
        }
    }
}
