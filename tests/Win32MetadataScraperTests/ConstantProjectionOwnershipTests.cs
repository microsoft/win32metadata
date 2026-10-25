using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void OrdinaryUnscopedEnumsProtectTheirPublishedMembersAcrossNamespaces(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "enum NATIVE { MEMBER = 4 };\n#define MEMBER 5U\nint F();");
            fixture.AssertSuccess();
            Assert.Contains("enum NATIVE", fixture.ReadSource());
            Assert.DoesNotContain("enum NATIVE", fixture.ReadAdditionalTypes());
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Decision(report, "MEMBER");
            var source = Assert.Single(decision.GetProperty("Protected").EnumerateArray());
            Assert.Equal("ordinary-unscoped-enum", source.GetProperty("SourceKind").GetString());
            Assert.Equal("Test", source.GetProperty("Namespace").GetString());
            Assert.Equal("NATIVE", source.GetProperty("Owner").GetString());
            Assert.Equal("discarded-by-policy", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                .GetProperty("Disposition").GetString());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(new[] { "Test.NATIVE" }, NamespaceMacroOwners(image.Reader));
            Assert.Equal(4, ReadInt32Member(image.Reader, "NATIVE", "MEMBER"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ScopedEnumsDoNotClaimGlobalMacroOwnership(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "enum class NATIVE { MEMBER = 4 };\n#define MEMBER 5U\nint F();");
            fixture.AssertSuccess();
            SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(5U, ReadUInt32Field(image.Reader, "Apis", "MEMBER"));
            Assert.Equal(4, ReadInt32Member(image.Reader, "NATIVE", "MEMBER"));
            AssertHasAttribute(image.Reader, FindType(image.Reader, "NATIVE").GetCustomAttributes(), "ScopedEnumAttribute");
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void ForceConstProtectionUsesTheActualPublishedNameAndRetainsTypeDifferences(
            string architecture, string target, bool readonlyTransport)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                readonlyTransport ? "#define MEMBER 4\nint F();" :
                "typedef unsigned long DWORD;\nconst DWORD __forceconst__MEMBER = 4U;\n#define MEMBER 4\nint F();");
            fixture.AssertSuccess();
            if (readonlyTransport)
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, "Provider.manual.cs"),
                    "namespace Test { public static partial class Apis { public static readonly uint __forceconst__MEMBER = 4U; } }");
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Decision(report, "MEMBER");
            Assert.True(decision.GetProperty("ProjectedTypeConflict").GetBoolean());
            Assert.Contains(result.Output, message => message.Contains("PROJECTED TYPE CONFLICT"));
            var source = Assert.Single(decision.GetProperty("Protected").EnumerateArray());
            Assert.Equal("__forceconst__MEMBER", source.GetProperty("DeclaredName").GetString());
            Assert.Equal("MEMBER", source.GetProperty("Name").GetString());
            Assert.Equal("uint", source.GetProperty("StorageType").GetString());
            var candidate = Assert.Single(decision.GetProperty("Candidates").EnumerateArray());
            Assert.Equal("int", candidate.GetProperty("StorageType").GetString());
            Assert.Equal("discarded-by-policy", candidate.GetProperty("Disposition").GetString());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(new[] { "Test.Apis" }, NamespaceMacroOwners(image.Reader));
            Assert.Equal(4U, ReadUInt32Field(image.Reader, "Apis", "MEMBER"));
            Assert.DoesNotContain(image.Reader.FieldDefinitions.Select(image.Reader.GetFieldDefinition),
                field => image.Reader.GetString(field.Name).StartsWith("__forceconst__", StringComparison.Ordinal));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
        }

        [Fact]
        public void TransportSpellingInTheMiddleOfANameDoesNotClaimAnUnrelatedMacro()
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "const unsigned UNRELATED__forceconst__MEMBER = 4U;\n#define MEMBER 5U\nint F();");
            fixture.AssertSuccess();
            SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var image = Emit(fixture.DirectoryPath, "x86");
            Assert.Equal(5U, ReadUInt32Field(image.Reader, "Apis", "MEMBER"));
            Assert.Equal(4U, ReadUInt32Field(image.Reader, "Apis", "UNRELATED__forceconst__MEMBER"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void DifferentlyNamedLogicalMembersConsumeOnlyTheirExactNativeMacroBindings(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define NATIVE_HTTP 1\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_HTTP)\", NATIVE_HTTP) int SOURCE_GROUP;\nint F();");
            fixture.AssertSuccess();
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Decision(report, "NATIVE_HTTP");
            Assert.Equal("PUBLISHED_HTTP", Assert.Single(decision.GetProperty("Protected").EnumerateArray())
                .GetProperty("Name").GetString());
            Assert.Equal("compiler-bound-group-consumption", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                .GetProperty("Disposition").GetString());
            using var image = Emit(fixture.DirectoryPath, architecture,
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            Assert.Equal(1, ReadInt32Member(image.Reader, "SOURCE_GROUP", "PUBLISHED_HTTP"));
            Assert.DoesNotContain(image.Reader.FieldDefinitions.Select(image.Reader.GetFieldDefinition),
                field => image.Reader.GetString(field.Name) == "NATIVE_HTTP");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void RenamedGroupMemberDoesNotConsumeAnUnrelatedSameBasenameDefinition(string architecture, string target)
        {
            using var owner = NewNamespaceOwnershipFixture(architecture, target,
                "#define NATIVE_HTTP 1\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_HTTP)\", NATIVE_HTTP) int SOURCE_GROUP;\nint F();",
                "--exclude\nNATIVE_HTTP\n");
            using var foreign = NewNamespaceOwnershipFixture(architecture, target, "#define NATIVE_HTTP 1\nint G();");
            owner.AssertSuccess();
            foreign.AssertSuccess();
            File.Copy(Path.ChangeExtension(foreign.Output, ".native-constants.json"),
                Path.Combine(Path.GetDirectoryName(owner.Output), "Foreign.native-constants.json"));
            SelectNativeConstants(owner.DirectoryPath, new() { [owner.Header] = "Owner", [foreign.Header] = "Foreign" },
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            using var image = Emit(owner.DirectoryPath, architecture,
                requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
            Assert.Equal(1, ReadInt32Member(image.Reader, "Apis", "NATIVE_HTTP"));
            Assert.Equal(1, ReadInt32Member(image.Reader, "SOURCE_GROUP", "PUBLISHED_HTTP"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void PureNativeEnumAliasesCarryExactCaseSensitiveCompilerAndSourceProof(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "enum NATIVE { KEEPUser = 0 };\n#define KeepUser KEEPUser\nint F();");
            fixture.AssertSuccess();
            var values = NativeConstantExtractionTests.Read(fixture);
            var native = Assert.Single(values.Constants.Where(value => value.NativeName == "KeepUser"));
            Assert.Equal("::NATIVE::KEEPUser", native.AliasTarget.NativeName);
            Assert.Equal("CXCursor_EnumConstantDecl", native.AliasTarget.Kind);
            Assert.Equal(NativeConstantGroupProvenance.HashFile(fixture.Header), native.AliasTarget.HeaderHash);
            var declaration = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>());
            var proof = NativeConstantGroupProvenance.Read(declaration);
            Assert.Equal("NativeEnum", proof.Group.Kind);
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Decision(report, "KeepUser");
            Assert.True(decision.GetProperty("DistinctNativeDefinitions").GetBoolean());
            var candidate = Assert.Single(decision.GetProperty("Candidates").EnumerateArray());
            Assert.Equal("KeepUser", candidate.GetProperty("NativeName").GetString());
            Assert.Equal("::NATIVE::KEEPUser", candidate.GetProperty("AliasTarget").GetProperty("NativeName").GetString());
            Assert.Equal("compiler-bound-native-alias", candidate.GetProperty("Disposition").GetString());
            Assert.Equal("KEEPUser", Assert.Single(decision.GetProperty("Protected").EnumerateArray())
                .GetProperty("Name").GetString());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(0, ReadInt32Member(image.Reader, "NATIVE", "KEEPUser"));
            Assert.DoesNotContain(image.Reader.FieldDefinitions.Select(image.Reader.GetFieldDefinition),
                field => image.Reader.GetString(field.Name) == "KeepUser");
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
            SaveOpaqueRecordArtifacts(fixture, "projection-native-alias-" + architecture);
        }

        [Theory]
        [InlineData("KEEPUser + 0")]
        [InlineData("(int)KEEPUser")]
        [InlineData("(NATIVE)KEEPUser")]
        [InlineData("0")]
        public void EqualNativeValuesOrExplicitConversionsAreNotDeclarationAliases(string expression)
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                $"enum NATIVE {{ KEEPUser = 0 }};\n#define KeepUser ({expression})\nint F();");
            fixture.AssertSuccess();
            Assert.Null(Assert.Single(NativeConstantExtractionTests.Read(fixture).Constants).AliasTarget);
            SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var image = Emit(fixture.DirectoryPath, "x86");
            Assert.Equal(0, ReadInt32Member(image.Reader, "Apis", "KeepUser"));
            Assert.Equal(0, ReadInt32Member(image.Reader, "NATIVE", "KEEPUser"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), -1);
        }

        [Fact]
        public void NativeAliasProofDoesNotBindADifferentNativeScopeWithIdenticalProjection()
        {
            using var owner = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "enum NATIVE { KEEPUser = 0 };\n#define KeepUser KEEPUser\nint F();");
            using var foreign = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "namespace Foreign { enum NATIVE { KEEPUser = 0 }; }\n#define KeepUser Foreign::KEEPUser\nint G();");
            owner.AssertSuccess();
            foreign.AssertSuccess();
            File.Delete(Path.ChangeExtension(owner.Output, ".native-constants.json"));
            File.Copy(Path.ChangeExtension(foreign.Output, ".native-constants.json"),
                Path.Combine(Path.GetDirectoryName(owner.Output), "Foreign.native-constants.json"));
            var result = SelectNativeConstants(owner.DirectoryPath, new() { [foreign.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var candidate = Assert.Single(Decision(report, "KeepUser").GetProperty("Candidates").EnumerateArray());
            Assert.Equal("selected", candidate.GetProperty("Disposition").GetString());
            Assert.Equal("::Foreign::NATIVE::KEEPUser", candidate.GetProperty("AliasTarget").GetProperty("NativeName").GetString());
            using var image = Emit(owner.DirectoryPath, "x86");
            Assert.Equal(0, ReadInt32Member(image.Reader, "Apis", "KeepUser"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NonCollidingNativeEnumAliasesRetainTheirDistinctPublishedNames(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "enum PIPE_TYPE { ALL_PIPE = 3 };\n#define ALL ALL_PIPE\nint F();");
            fixture.AssertSuccess();
            Assert.Equal("::PIPE_TYPE::ALL_PIPE", Assert.Single(
                NativeConstantExtractionTests.Read(fixture).Constants).AliasTarget.NativeName);
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            var decision = Decision(report, "ALL");
            Assert.Empty(decision.GetProperty("Protected").EnumerateArray());
            Assert.Equal("selected", Assert.Single(decision.GetProperty("Candidates").EnumerateArray())
                .GetProperty("Disposition").GetString());
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(3, ReadInt32Member(image.Reader, "PIPE_TYPE", "ALL_PIPE"));
            Assert.Equal(3, ReadInt32Member(image.Reader, "Apis", "ALL"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
        }

        [Theory]
        [InlineData("source-hash")]
        [InlineData("alias-header-hash")]
        [InlineData("alias-location")]
        [InlineData("alias-type")]
        [InlineData("alias-storage")]
        [InlineData("alias-value")]
        [InlineData("macro-value")]
        [InlineData("source-member")]
        [InlineData("source-target")]
        public void NativeAliasDriftRejectsWithoutAlteringTheRawFact(string mutation)
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "enum NATIVE { KEEPUser = 0 };\n#define KeepUser KEEPUser\nint F();");
            fixture.AssertSuccess();
            string path = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            var values = NativeConstantExtractionTests.Read(fixture);
            var constant = Assert.Single(values.Constants);
            switch (mutation)
            {
                case "source-hash":
                    values.SourceHash = new string('0', 64);
                    break;
                case "alias-header-hash":
                    constant = constant with { AliasTarget = constant.AliasTarget with { HeaderHash = new string('0', 64) } };
                    break;
                case "alias-location":
                    constant = constant with { AliasTarget = constant.AliasTarget with { Line = constant.AliasTarget.Line + 1 } };
                    break;
                case "alias-type":
                    constant = constant with { AliasTarget = constant.AliasTarget with { NativeType = "unsigned int" } };
                    break;
                case "alias-storage":
                    constant = constant with { AliasTarget = constant.AliasTarget with { StorageType = "uint" } };
                    break;
                case "alias-value":
                    constant = constant with { AliasTarget = constant.AliasTarget with { Value = "1" } };
                    break;
                case "macro-value":
                    constant = constant with { Value = "1" };
                    break;
                case "source-member":
                    File.WriteAllText(fixture.Output, File.ReadAllText(fixture.Output).Replace("KEEPUser = 0", "KEEPUser = 1"));
                    break;
                case "source-target":
                    File.WriteAllText(fixture.Output, File.ReadAllText(fixture.Output)
                        .Replace("\"Architecture\":1", "\"Architecture\":2"));
                    break;
                default:
                    throw new ArgumentException(nameof(mutation));
            }
            values.Constants = new() { constant };
            string raw = JsonSerializer.Serialize(values);
            File.WriteAllText(path, raw);
            Assert.Throws<InvalidDataException>(() =>
                SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" }));
            Assert.Equal(raw, File.ReadAllText(path));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "native-constant-conflicts.json")));
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
            SaveOpaqueRecordArtifacts(fixture, "projection-alias-rejected-" + mutation);
        }

        [Fact]
        public void LogicalGroupProofsWithoutTheNewKindFieldRemainCompilerBound()
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc", NamespaceOwnedMacro);
            fixture.AssertSuccess();
            string sourcePath = Path.ChangeExtension(fixture.Output, ".header-types.cs");
            string factPath = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            foreach (string path in new[] { sourcePath, factPath })
                File.WriteAllText(path, File.ReadAllText(path).Replace("\"Kind\":\"LogicalGroup\",", "")
                    .Replace(",\"Kind\":\"LogicalGroup\"", ""));
            Assert.DoesNotContain("\"Kind\":\"LogicalGroup\"", File.ReadAllText(sourcePath));
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Foreign" });
            using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
            Assert.Equal("compiler-bound-group-consumption", Assert.Single(
                Decision(report, "MEMBER").GetProperty("Candidates").EnumerateArray()).GetProperty("Disposition").GetString());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false, false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, false, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false, true)]
        [InlineData("x86", "i686-pc-windows-msvc", true, false, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false, true)]
        [InlineData("x86", "i686-pc-windows-msvc", false, true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, true, true)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true, true)]
        public void LegacyAliasesKeepAuthoritativeSourceStorageWithoutRecreatingEnumMembers(
            string architecture, string target, bool logicalGroup, bool unsigned, bool removeNativeFacts)
        {
            string integer = unsigned ? "unsigned" : "int";
            string declaration = logicalGroup ?
                $"#define NATIVE_ERROR 10048{(unsigned ? "U" : "")}\n_Win32_Enum_(SOURCE_GROUP, {integer}, NATIVE_ERROR);\nint F();" :
                $"enum SOURCE_GROUP : {integer} {{ NATIVE_ERROR = 10048 }};\nint F();";
            using var fixture = NewNamespaceOwnershipFixture(architecture, target, declaration);
            fixture.AssertSuccess();
            if (removeNativeFacts)
                File.Delete(Path.ChangeExtension(fixture.Output, ".native-constants.json"));
            string legacy = Path.Combine(fixture.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, "#define BASE_ERROR 10000\n#define NATIVE_ERROR BASE_ERROR+48\n#define LEGACY_ALIAS NATIVE_ERROR\n");
            var result = SelectNativeConstants(fixture.DirectoryPath,
                new() { [fixture.Header] = "Origin", [legacy] = "Legacy" });
            var members = Directory.GetFiles(fixture.DirectoryPath, "*.constants.cs").Select(File.ReadAllText).ToArray();
            Assert.DoesNotContain(members, text => text.Contains(" NATIVE_ERROR ="));
            Assert.Contains(members, text => text.Contains($"public const {(unsigned ? "uint" : "int")} LEGACY_ALIAS = ") &&
                text.Contains("global::Test.SOURCE_GROUP.NATIVE_ERROR"));
            if (!removeNativeFacts)
            {
                using var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport));
                var dependency = report.RootElement.GetProperty("SourceDependencies").EnumerateArray().Single(value =>
                    value.GetProperty("Name").GetString() == "NATIVE_ERROR");
                Assert.Equal("authoritative-managed-declaration-storage-not-native-consumption",
                    dependency.GetProperty("Reason").GetString());
                Assert.Equal(unsigned ? "uint" : "int", Assert.Single(dependency.GetProperty("StorageTypes").EnumerateArray()).GetString());
            }
            using var image = Emit(fixture.DirectoryPath, architecture);
            if (unsigned)
                Assert.Equal(10048U, ReadUInt32Field(image.Reader, "Apis", "LEGACY_ALIAS"));
            else
                Assert.Equal(10048, ReadInt32Member(image.Reader, "Apis", "LEGACY_ALIAS"));
            Assert.Single(image.Reader.FieldDefinitions.Select(image.Reader.GetFieldDefinition)
                .Where(field => image.Reader.GetString(field.Name) == "NATIVE_ERROR"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
            SaveOpaqueRecordArtifacts(fixture,
                $"projection-source-dependency-{architecture}-{logicalGroup}-{unsigned}-{removeNativeFacts}");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void LegacyLogicalAliasesRetainCompilerPrimitiveAcrossProjectedStorage(
            string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define NATIVE_ERROR 10048L\n_Win32_Enum_(SOURCE_GROUP, unsigned, NATIVE_ERROR);\nint F();");
            fixture.AssertSuccess();
            string legacy = Path.Combine(fixture.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, "#define LEGACY_ALIAS NATIVE_ERROR\n");
            var result = SelectNativeConstants(fixture.DirectoryPath,
                new() { [fixture.Header] = "Origin", [legacy] = "Legacy" });
            using (var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport)))
            {
                var dependency = report.RootElement.GetProperty("SourceDependencies").EnumerateArray().Single(value =>
                    value.GetProperty("Name").GetString() == "NATIVE_ERROR");
                Assert.Equal("compiler-bound-logical-member-primitive-storage-not-native-consumption",
                    dependency.GetProperty("Reason").GetString());
                Assert.Equal("int", Assert.Single(dependency.GetProperty("StorageTypes").EnumerateArray()).GetString());
                var declaration = Assert.Single(dependency.GetProperty("Declarations").EnumerateArray());
                Assert.Equal("uint", declaration.GetProperty("StorageType").GetString());
                Assert.Equal("int", declaration.GetProperty("DependencyStorageType").GetString());
            }
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(10048, ReadInt32Member(image.Reader, "Apis", "LEGACY_ALIAS"));
            var groupStorage = FindType(image.Reader, "SOURCE_GROUP").GetFields().Select(image.Reader.GetFieldDefinition)
                .Single(field => image.Reader.GetString(field.Name) == "value__");
            Assert.Equal("UInt32", groupStorage.DecodeSignature(new SignatureNames(), null));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
            SaveOpaqueRecordArtifacts(fixture, "projection-logical-primitive-storage-" + architecture);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void RenamedLogicalMembersRetainPrimitiveStorageThroughLegacyFallback(
            string architecture, string target, bool legacyDefinition)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define NATIVE_ERROR 0x00000004\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_ERROR)\", NATIVE_ERROR) unsigned SOURCE_GROUP;\nint F();");
            fixture.AssertSuccess();
            string legacy = Path.Combine(fixture.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, (legacyDefinition ? "#define NATIVE_ERROR 0x00000004\n" : "") +
                "#define LEGACY_NATIVE_ALIAS NATIVE_ERROR\n#define LEGACY_PROJECTED_ALIAS PUBLISHED_ERROR\n" +
                "#define LOOKALIKE_ERROR 0x00000004\n" + (legacyDefinition ? "" : "#define native_error 0x00000004\n"));
            var result = SelectNativeConstants(fixture.DirectoryPath, new() { [fixture.Header] = "Test", [legacy] = "Test" });
            using (var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport)))
            {
                var dependency = Assert.Single(report.RootElement.GetProperty("NativeDependencies").EnumerateArray());
                Assert.Equal("NATIVE_ERROR", dependency.GetProperty("NativeName").GetString());
                Assert.Equal("int", Assert.Single(dependency.GetProperty("StorageTypes").EnumerateArray()).GetString());
                var source = Assert.Single(dependency.GetProperty("Definitions").EnumerateArray());
                Assert.Equal("PUBLISHED_ERROR", source.GetProperty("DeclaredName").GetString());
                Assert.Equal("uint", source.GetProperty("StorageType").GetString());
                Assert.Equal("int", source.GetProperty("Candidate").GetProperty("StorageType").GetString());
                Assert.Equal("compiler-bound-group-consumption", Assert.Single(Decision(report, "NATIVE_ERROR")
                    .GetProperty("Candidates").EnumerateArray()).GetProperty("Disposition").GetString());
                Assert.Contains(report.RootElement.GetProperty("LegacyDependencyPolicies").EnumerateArray(),
                    policy => policy.GetProperty("Header").GetString() == legacy &&
                        policy.GetProperty("NativeName").GetString() == "NATIVE_ERROR" &&
                        policy.GetProperty("StorageType").GetString() == "int");
            }
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(4, ReadInt32Member(image.Reader, "Apis", "LEGACY_NATIVE_ALIAS"));
            Assert.Equal(4, ReadInt32Member(image.Reader, "Apis", "LEGACY_PROJECTED_ALIAS"));
            Assert.Equal(4U, ReadUInt32Field(image.Reader, "Apis", "LOOKALIKE_ERROR"));
            if (!legacyDefinition)
                Assert.Equal(4U, ReadUInt32Field(image.Reader, "Apis", "native_error"));
            Assert.Equal(4U, ReadUInt32Field(image.Reader, "SOURCE_GROUP", "PUBLISHED_ERROR"));
            if (legacyDefinition)
                Assert.Equal(4, ReadInt32Member(image.Reader, "Apis", "NATIVE_ERROR"));
            else
                Assert.DoesNotContain(image.Reader.FieldDefinitions.Select(image.Reader.GetFieldDefinition),
                    field => image.Reader.GetString(field.Name) == "NATIVE_ERROR");
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
            SaveOpaqueRecordArtifacts(fixture, $"projection-renamed-primitive-{architecture}-{legacyDefinition}");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void RenamedPrimitiveStorageDoesNotEquateAnIndependentLegacyDefinition(
            string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target,
                "#define NATIVE_ERROR 0x00000004\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_ERROR)\", NATIVE_ERROR) unsigned SOURCE_GROUP;\nint F();");
            fixture.AssertSuccess();
            string legacy = Path.Combine(fixture.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, "#define LEGACY_ALIAS NATIVE_ERROR\n#define NATIVE_ERROR 0x00000008\n");
            var result = SelectNativeConstants(fixture.DirectoryPath,
                new() { [fixture.Header] = "Origin", [legacy] = "Legacy" });
            using (var report = JsonDocument.Parse(File.ReadAllText(result.ConflictReport)))
            {
                var candidate = Assert.Single(Decision(report, "NATIVE_ERROR").GetProperty("Candidates").EnumerateArray());
                Assert.Equal("4", candidate.GetProperty("Value").GetString());
                var policy = report.RootElement.GetProperty("LegacyDependencyPolicies").EnumerateArray().Single(value =>
                    value.GetProperty("Name").GetString() == "NATIVE_ERROR");
                Assert.Equal(legacy, policy.GetProperty("Header").GetString());
                Assert.Equal(2, policy.GetProperty("Line").GetInt32());
                Assert.Equal("0x00000008", policy.GetProperty("Expression").GetString());
                Assert.Equal("retained-compiler-primitive-storage-not-legacy-native-binding-or-value-equivalence",
                    policy.GetProperty("Reason").GetString());
            }
            using var image = Emit(fixture.DirectoryPath, architecture);
            Assert.Equal(8, ReadInt32Member(image.Reader, "Apis", "NATIVE_ERROR"));
            Assert.Equal(8, ReadInt32Member(image.Reader, "Apis", "LEGACY_ALIAS"));
            Assert.Equal(4U, ReadUInt32Field(image.Reader, "SOURCE_GROUP", "PUBLISHED_ERROR"));
            AssertDuplicateConstantTool(Path.Combine(fixture.DirectoryPath, "Test.winmd"), 0);
        }

        [Fact]
        public void RenamedNativeDependenciesRejectConflictingCompilerPrimitiveStorage()
        {
            using var first = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "#define NATIVE_ERROR 4\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_ERROR)\", NATIVE_ERROR) unsigned SOURCE_GROUP;\nint F();");
            using var second = NewNamespaceOwnershipFixture("x64", "x86_64-pc-windows-msvc",
                "#define NATIVE_ERROR 4U\n" +
                "typedef _WIN32META_ANNOTATION_(\"Enum(PUBLISHED_ERROR)\", NATIVE_ERROR) unsigned SOURCE_GROUP;\nint F();");
            first.AssertSuccess();
            second.AssertSuccess();
            string x64 = Path.Combine(first.DirectoryPath, "x64");
            Directory.CreateDirectory(x64);
            File.Copy(Path.ChangeExtension(second.Output, ".native-constants.json"),
                Path.Combine(x64, "Foreign.native-constants.json"));
            File.Copy(Path.ChangeExtension(second.Output, ".header-types.cs"),
                Path.Combine(x64, "Foreign.header-types.cs"));
            string legacy = Path.Combine(first.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, "#define NATIVE_ERROR 0x00000004\n");
            var error = Assert.Throws<InvalidDataException>(() => SelectNativeConstants(first.DirectoryPath,
                new() { [first.Header] = "Origin", [second.Header] = "Other", [legacy] = "Legacy" }));
            Assert.Contains("conflicting compiler primitive storage types", error.Message);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(first.DirectoryPath, "native-constant-conflicts.json")));
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
            Assert.Contains("NATIVE_ERROR", report.RootElement.GetProperty("Error").GetString());
        }

        [Fact]
        public void LegacyAliasesDoNotGuessBetweenConflictingAuthoritativeSourceTypes()
        {
            using var fixture = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc",
                "enum SOURCE_GROUP { NATIVE_ERROR = 4 };\nint F();");
            fixture.AssertSuccess();
            string x64 = Path.Combine(fixture.DirectoryPath, "x64");
            Directory.CreateDirectory(x64);
            File.WriteAllText(Path.Combine(x64, "Different.cs"),
                "namespace Test { public enum SOURCE_GROUP : uint { NATIVE_ERROR = 4U } }");
            string legacy = Path.Combine(fixture.DirectoryPath, "legacy.h");
            File.WriteAllText(legacy, "#define LEGACY_ALIAS NATIVE_ERROR\n");
            var error = Assert.Throws<InvalidDataException>(() => SelectNativeConstants(fixture.DirectoryPath,
                new() { [fixture.Header] = "Origin", [legacy] = "Legacy" }));
            Assert.Contains("conflicting authoritative storage types", error.Message);
            Assert.Contains("NATIVE_ERROR", error.Message);
        }

        private static JsonElement Decision(JsonDocument report, string name) =>
            report.RootElement.GetProperty("Decisions").EnumerateArray().Single(value =>
                value.GetProperty("Name").GetString() == name);

        private static int ReadInt32Member(MetadataReader reader, string type, string name)
        {
            var field = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(value => reader.GetString(value.Name) == type).SelectMany(value => value.GetFields())
                .Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == name);
            var constant = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(ConstantTypeCode.Int32, constant.TypeCode);
            return reader.GetBlobReader(constant.Value).ReadInt32();
        }
    }
}
