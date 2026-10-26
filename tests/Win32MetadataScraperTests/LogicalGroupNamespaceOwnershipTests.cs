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
    public abstract partial class HeaderAnnotationWinmdTests
    {
        internal const string NamespaceOwnedMacro = "#define MEMBER (1U << 2)\n_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\nint F();";

        internal static HeaderAnnotationTests.NativeFixture NewNamespaceOwnershipFixture(
            string architecture, string target, string declarations, string settings = "") =>
            new(architecture, target, declarations, extraSettings: "--config\nnative-constant-values\n" + settings);

        internal static void ScrapeNamespaceOwnership(string directory, Dictionary<string, string> headers) =>
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory,
                "using System; using Windows.Win32.Foundation.Metadata;", new(), headers,
                new() { ["SOURCE_GROUP"] = "Canonical" }, new(), new(), new());

        internal static void AssertNamespaceOwnershipSource(HeaderAnnotationTests.NativeFixture fixture)
        {
            string source = fixture.ReadAdditionalTypes();
            Assert.StartsWith(HeaderTypesSourceFamily.SuccessMarker, source);
            var group = Assert.Single(CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>());
            Assert.Equal("SOURCE_GROUP", group.Identifier.ValueText);
            var member = Assert.Single(group.Members);
            Assert.Equal("MEMBER", member.Identifier.ValueText);
            Assert.Equal("unchecked((uint)4UL)", member.EqualsValue.Value.ToString());
            Assert.NotNull(NativeConstantGroupProvenance.Read(group));
        }

        internal static NativeConstantBinding GroupMemberBinding(HeaderAnnotationTests.NativeFixture fixture) =>
            Assert.Single(Assert.Single(NativeConstantGroupProvenance.Read(Assert.Single(
                CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>()))
                .Group.Members).Bindings);

        internal static JsonDocument ReadNamespaceOwnershipReport(HeaderAnnotationTests.NativeFixture fixture) =>
            JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.DirectoryPath, "native-constant-conflicts.json")));

        internal static string[] NamespaceMacroOwners(MetadataReader reader) =>
            reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => type.GetFields().Select(reader.GetFieldDefinition).Any(field => reader.GetString(field.Name) == "MEMBER"))
                .Select(type => reader.GetString(type.Namespace) + "." + reader.GetString(type.Name))
                .OrderBy(name => name, StringComparer.Ordinal).ToArray();

        internal static void RecordNamespaceOwnership(string directory, MetadataReader reader)
        {
            var records = reader.TypeDefinitions.Select(reader.GetTypeDefinition).SelectMany(type =>
                type.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => reader.GetString(field.Name) == "MEMBER")
                    .Select(field => new
                    {
                        Owner = reader.GetString(type.Namespace) + "." + reader.GetString(type.Name),
                        TypeAttributes = ReadAttributes(type.GetCustomAttributes()),
                        FieldAttributes = ReadAttributes(field.GetCustomAttributes()),
                        Signature = Convert.ToHexString(reader.GetBlobBytes(field.Signature)),
                        ConstantType = reader.GetConstant(field.GetDefaultValue()).TypeCode.ToString(),
                        ConstantValue = Convert.ToHexString(reader.GetBlobBytes(reader.GetConstant(field.GetDefaultValue()).Value)),
                    })).ToArray();
            File.WriteAllText(Path.Combine(directory, "namespace-ownership-physical.json"),
                JsonSerializer.Serialize(records, new JsonSerializerOptions { WriteIndented = true }));

            object[] ReadAttributes(CustomAttributeHandleCollection attributes) => attributes.Select(handle => new
            {
                Name = AttributeName(reader, handle),
                Value = Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value)),
            }).Cast<object>().ToArray();
        }
    }
    public class LogicalGroupNamespaceOwnershipTests : HeaderAnnotationWinmdTests
    {

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void RelocatedLogicalGroupMustConsumeItsCompilerBoundMacro(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target, NamespaceOwnedMacro);
            try
            {
                fixture.AssertSuccess();
                AssertNamespaceOwnershipSource(fixture);
                ScrapeNamespaceOwnership(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" });
                using var image = Emit(fixture.DirectoryPath, architecture,
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
                RecordNamespaceOwnership(fixture.DirectoryPath, image.Reader);
                Assert.Equal("Canonical", image.Reader.GetString(FindType(image.Reader, "SOURCE_GROUP").Namespace));
                Assert.DoesNotContain(NamespaceMacroOwners(image.Reader), owner => owner == "Origin.Apis");
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "relocated-owned-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SameProducerAndMemberValueCannotBindAnUnrelatedNativeScope(string architecture, string target)
        {
            const string unrelated = "namespace Scoped {\nconstexpr unsigned MEMBER = 4U;\n" +
                "_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\n}\n#define MEMBER (1U << 2)\nint F();";
            using var owned = NewNamespaceOwnershipFixture(architecture, target, NamespaceOwnedMacro);
            using var foreign = NewNamespaceOwnershipFixture(architecture, target, unrelated,
                "--exclude\nScoped::MEMBER\n");
            try
            {
                owned.AssertSuccess();
                foreign.AssertSuccess();
                AssertNamespaceOwnershipSource(owned);
                AssertNamespaceOwnershipSource(foreign);
                Assert.NotEqual(owned.ReadAdditionalTypes(), foreign.ReadAdditionalTypes());
                Assert.Equal("Macro", GroupMemberBinding(owned).Kind);
                Assert.Equal("CXCursor_VarDecl", GroupMemberBinding(foreign).Kind);
                Assert.Equal("::Scoped::MEMBER", GroupMemberBinding(foreign).NativeName);
                var ownedFact = Assert.Single(NativeConstantExtractionTests.Read(owned).Constants.Where(value => value.NativeName == "MEMBER"));
                var foreignFact = Assert.Single(NativeConstantExtractionTests.Read(foreign).Constants.Where(value => value.NativeName == "MEMBER"));
                Assert.Equal(ownedFact.Name, foreignFact.Name);
                Assert.Equal(ownedFact.StorageType, foreignFact.StorageType);
                Assert.Equal(ownedFact.NativeType, foreignFact.NativeType);
                Assert.Equal(ownedFact.Value, foreignFact.Value);
                Assert.NotEqual(ownedFact.Line, foreignFact.Line);
                ScrapeNamespaceOwnership(foreign.DirectoryPath, new() { [foreign.Header] = "Origin" });
                using var image = Emit(foreign.DirectoryPath, architecture,
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
                RecordNamespaceOwnership(foreign.DirectoryPath, image.Reader);
                Assert.Equal(new[] { "Canonical.SOURCE_GROUP" }, NamespaceMacroOwners(image.Reader));
                using var report = ReadNamespaceOwnershipReport(foreign);
                var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
                var candidate = Assert.Single(decision.GetProperty("Candidates").EnumerateArray());
                Assert.Equal("discarded-by-policy", candidate.GetProperty("Disposition").GetString());
                Assert.True(decision.GetProperty("UnrelatedProtectedDefinition").GetBoolean());
            }
            finally
            {
                SaveOpaqueRecordArtifacts(owned, "native-scope-owned-" + architecture);
                SaveOpaqueRecordArtifacts(foreign, "native-scope-unrelated-" + architecture);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ManagedMemberRenameDoesNotIdentifyTheNativeMacroBinding(string architecture, string target)
        {
            const string unrelated = "#define OTHER_NATIVE (1U << 2)\n" +
                "_Win32_Enum_(SOURCE_GROUP, unsigned, OTHER_NATIVE);\n#define MEMBER (1U << 2)\nint F();";
            using var owned = NewNamespaceOwnershipFixture(architecture, target, NamespaceOwnedMacro);
            using var foreign = NewNamespaceOwnershipFixture(architecture, target, unrelated,
                "--remap\nOTHER_NATIVE=MEMBER\n");
            try
            {
                owned.AssertSuccess();
                foreign.AssertSuccess();
                AssertNamespaceOwnershipSource(owned);
                AssertNamespaceOwnershipSource(foreign);
                Assert.NotEqual(owned.ReadAdditionalTypes(), foreign.ReadAdditionalTypes());
                Assert.Equal("MEMBER", GroupMemberBinding(owned).NativeName);
                Assert.Equal("OTHER_NATIVE", GroupMemberBinding(foreign).NativeName);
                var facts = NativeConstantExtractionTests.Read(foreign).Constants.Where(value => value.Name == "MEMBER").ToArray();
                Assert.Equal(new[] { "MEMBER", "OTHER_NATIVE" }, facts.Select(value => value.NativeName).OrderBy(name => name));
                Assert.Single(facts.Select(value => (value.NativeType, value.StorageType, value.Value)).Distinct());
                Assert.Equal(2, facts.Select(value => value.Line).Distinct().Count());
                ScrapeNamespaceOwnership(foreign.DirectoryPath, new() { [foreign.Header] = "Origin" });
                using var image = Emit(foreign.DirectoryPath, architecture,
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
                RecordNamespaceOwnership(foreign.DirectoryPath, image.Reader);
                Assert.Equal(new[] { "Canonical.SOURCE_GROUP" }, NamespaceMacroOwners(image.Reader));
                using var report = ReadNamespaceOwnershipReport(foreign);
                var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
                var reported = decision.GetProperty("Candidates").EnumerateArray()
                    .ToDictionary(value => value.GetProperty("NativeName").GetString());
                Assert.Equal("compiler-bound-group-consumption", reported["OTHER_NATIVE"].GetProperty("Disposition").GetString());
                Assert.Equal("discarded-by-policy", reported["MEMBER"].GetProperty("Disposition").GetString());
                Assert.True(decision.GetProperty("DistinctNativeDefinitions").GetBoolean());
            }
            finally
            {
                SaveOpaqueRecordArtifacts(owned, "native-rename-owned-" + architecture);
                SaveOpaqueRecordArtifacts(foreign, "native-rename-unrelated-" + architecture);
            }
        }

        [Fact]
        public void RelocatedLogicalGroupOwnershipMustNotCrossArchitectures()
        {
            const string source = "#define MEMBER (1U << 2)\n#if defined(_M_IX86)\n" +
                "_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\n#endif\nint F();";
            using var x86 = NewNamespaceOwnershipFixture("x86", "i686-pc-windows-msvc", source);
            using var x64 = NewNamespaceOwnershipFixture("x64", "x86_64-pc-windows-msvc", source);
            using var arm64 = NewNamespaceOwnershipFixture("arm64", "aarch64-pc-windows-msvc", source);
            var fixtures = new[] { x86, x64, arm64 };
            try
            {
                foreach (var fixture in fixtures)
                {
                    fixture.AssertSuccess();
                    if (fixture == x86)
                        continue;
                    string directory = Path.Combine(x86.DirectoryPath,
                        NativeConstantExtractionTests.Read(fixture).Architecture.ToString().ToLowerInvariant());
                    Directory.CreateDirectory(directory);
                    foreach (string file in Directory.GetFiles(Path.GetDirectoryName(fixture.Output)))
                        if (file.EndsWith(".cs", StringComparison.Ordinal) || file.EndsWith(".native-constants.json", StringComparison.Ordinal))
                            File.Copy(file, Path.Combine(directory, Path.GetFileName(file)));
                }
                ScrapeNamespaceOwnership(x86.DirectoryPath, fixtures.ToDictionary(fixture => fixture.Header, _ => "Origin"));
                using var image = Emit(x86.DirectoryPath, "crossarch",
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
                var reader = image.Reader;
                RecordNamespaceOwnership(x86.DirectoryPath, reader);
                var api = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Single(type => reader.GetString(type.Name) == "Apis" && reader.GetString(type.Namespace) == "Origin");
                var fields = api.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => reader.GetString(field.Name) == "MEMBER").ToArray();
                var field = Assert.Single(fields);
                var attribute = reader.GetCustomAttribute(Assert.Single(field.GetCustomAttributes().Where(handle =>
                    AttributeName(reader, handle) == "SupportedArchitectureAttribute")));
                var blob = reader.GetBlobReader(attribute.Value);
                Assert.Equal(1, blob.ReadUInt16());
                Assert.Equal((int)(Architecture.X64 | Architecture.Arm64), blob.ReadInt32());
                Assert.Equal(0, blob.ReadUInt16());
                Assert.Equal(0, blob.RemainingBytes);
            }
            finally
            {
                foreach (var fixture in fixtures)
                    SaveOpaqueRecordArtifacts(fixture, "architecture-ownership-" +
                        Path.GetFileName(Path.GetDirectoryName(fixture.Output)));
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NamespaceOwnershipMustNotHideConflictingNativeBindingFacts(string architecture, string target)
        {
            using var fixture = NewNamespaceOwnershipFixture(architecture, target, NamespaceOwnedMacro);
            try
            {
                fixture.AssertSuccess();
                var values = NativeConstantExtractionTests.Read(fixture);
                var value = Assert.Single(values.Constants.Where(value => value.NativeName == "MEMBER"));
                values.Constants = new() { value with { Value = "5U" } };
                string conflict = Path.Combine(Path.GetDirectoryName(fixture.Output), "Conflicting.native-constants.json");
                File.WriteAllText(conflict, JsonSerializer.Serialize(values));
                ScrapeNamespaceOwnership(fixture.DirectoryPath, new() { [fixture.Header] = "Origin" });
                using var report = ReadNamespaceOwnershipReport(fixture);
                var decision = Assert.Single(report.RootElement.GetProperty("Decisions").EnumerateArray());
                Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
                Assert.Equal(new[] { "4U", "5U" }, decision.GetProperty("Candidates").EnumerateArray()
                    .Select(value => value.GetProperty("Value").GetString()).OrderBy(value => value));
                using var image = Emit(fixture.DirectoryPath, architecture,
                    requiredNamespaces: new() { ["SOURCE_GROUP"] = "Canonical" });
                Assert.Equal(new[] { "Canonical.SOURCE_GROUP" }, NamespaceMacroOwners(image.Reader));
            }
            finally
            {
                SaveOpaqueRecordArtifacts(fixture, "conflicting-binding-" + architecture);
            }
        }
    }
}
