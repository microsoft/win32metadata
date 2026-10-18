using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using MetadataTasks;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class NativeEnumBroadMigrationTests
    {
        [NativeMigrationTheory("SDK_NATIVE_ENUM_BROAD_BATCH")]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void BroadOriginalAnnotationsPreserveNativeDeclarations(string architecture, string target, string language)
        {
            string batch = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BROAD_BATCH");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(batch, "report.json")));
            string source = NativeSource(report.RootElement);
            var headers = report.RootElement.GetProperty("originals").EnumerateArray()
                .Select(value => Path.GetFileName(value.GetString())).ToArray();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var before = WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot,
                Path.Combine(batch, "before"), "MenuRc", architecture, target, headers, "",
                sourceText: source, language: language, diagnostics: beforeDiagnostics);
            var after = WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot,
                Path.Combine(batch, "after"), "MenuRc", architecture, target, headers, "",
                sourceText: source, language: language, diagnostics: afterDiagnostics);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.Equal(beforeDiagnostics, afterDiagnostics);
            string output = Path.Combine(batch, "observations");
            Directory.CreateDirectory(output);
            File.WriteAllText(Path.Combine(output, "native-" + architecture + "-" + (language == "c" ? "c17" : "cpp17") + ".json"),
                JsonSerializer.Serialize(new
                {
                    architecture, language, target, headers, declarationsCompared = before.Length,
                    categories = before.GroupBy(value => value.Substring(0, value.IndexOf(' ')))
                        .ToDictionary(group => group.Key, group => group.Count()),
                    nativeDeclarationsEqual = true, diagnosticsEqual = true, diagnostics = beforeDiagnostics,
                }, new JsonSerializerOptions { WriteIndented = true }));
        }

        [NativeMigrationTheory("SDK_NATIVE_ENUM_BROAD_BATCH")]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void BroadGroupsAndOwnedUsesReachExactPhysicalIdentities(string architecture, string target)
        {
            string batch = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BROAD_BATCH");
            string baseline = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BASELINE_WINMD");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(batch, "report.json")));
            var groups = report.RootElement.GetProperty("groups").EnumerateArray().ToArray();
            var names = groups.Select(group => group.GetProperty("name").GetString()).ToHashSet(StringComparer.Ordinal);
            var roots = Directory.GetFiles(Path.Combine(batch, "normal", architecture), "*.cs")
                .Select(path => CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path).GetRoot()).ToArray();
            var enums = roots.SelectMany(root => root.DescendantNodes().OfType<EnumDeclarationSyntax>())
                .Where(value => names.Contains(value.Identifier.ValueText)).ToArray();
            Assert.Equal(names.OrderBy(value => value), enums.Select(value => value.Identifier.ValueText).Distinct().OrderBy(value => value));
            var methods = new Dictionary<string, MethodDeclarationSyntax>(StringComparer.Ordinal);
            var records = new Dictionary<string, StructDeclarationSyntax>(StringComparer.Ordinal);
            var uses = new List<(string Group, string Owner, string Slot, string NativeSlot, string RawType, AttributeSyntax Attribute)>();
            foreach (var group in groups)
                foreach (var converted in group.GetProperty("convertedUses").EnumerateArray())
                {
                    string name = group.GetProperty("name").GetString();
                    var use = converted.GetProperty("use");
                    string owner = use.TryGetProperty("struct", out var structure) ? structure.GetString() : use.GetProperty("method").GetString();
                    string slot = use.TryGetProperty("field", out var field) ? field.GetString() : use.GetProperty("parameter").GetString();
                    bool nativeField = converted.GetProperty("sites").EnumerateArray()
                        .All(site => site.GetProperty("kind").GetString() == "CXCursor_FieldDecl");
                    if (nativeField)
                    {
                        Assert.All(converted.GetProperty("sites").EnumerateArray(), site =>
                            Assert.Contains("@FI@" + slot, site.GetProperty("id").GetString()));
                        var candidates = roots.SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>())
                            .Where(value => value.Identifier.ValueText == owner).ToArray();
                        Assert.NotEmpty(candidates);
                        foreach (var candidate in candidates)
                        {
                            var actual = Assert.Single(candidate.Members.OfType<FieldDeclarationSyntax>()
                                .Where(value => value.Declaration.Variables.Any(variable => variable.Identifier.ValueText == slot)));
                            Association(actual.AttributeLists, name);
                        }
                        var selected = candidates.OrderBy(value => value.SyntaxTree.FilePath, StringComparer.Ordinal).First();
                        records[owner] = selected;
                        var selectedField = selected.Members.OfType<FieldDeclarationSyntax>()
                            .Single(value => value.Declaration.Variables.Any(variable => variable.Identifier.ValueText == slot));
                        uses.Add((name, owner, slot, slot, selectedField.Declaration.Type.ToString(), Association(selectedField.AttributeLists, name)));
                    }
                    else
                    {
                        var candidates = roots.SelectMany(root => root.DescendantNodes().OfType<MethodDeclarationSyntax>())
                            .Where(value => value.Identifier.ValueText == owner && value.Parent is ClassDeclarationSyntax).ToArray();
                        Assert.True(candidates.Length != 0, name + ": no actual normal method " + owner + "::" + slot);
                        foreach (var candidate in candidates)
                            Association(Lists(candidate, slot), name);
                        Assert.Single(candidates.Select(value => value.ReturnType + "(" +
                            string.Join(",", value.ParameterList.Parameters.Select(parameter => parameter.Type + " " + parameter.Identifier.ValueText)) + ")").Distinct());
                        var selected = candidates.OrderBy(value => value.SyntaxTree.FilePath, StringComparer.Ordinal).First();
                        methods[owner] = selected;
                        var parameter = slot == "return" ? null : Parameter(selected, slot);
                        uses.Add((name, owner, slot, parameter?.Identifier.ValueText,
                            parameter?.Type.ToString() ?? selected.ReturnType.ToString(), Association(Lists(selected, slot), name)));
                    }
                }
            Assert.Equal(report.RootElement.GetProperty("convertedUseFacts").GetInt32(), uses.Count);
            string controls = "";
            var probes = new Dictionary<string, (string Group, string Member)>(StringComparer.Ordinal);
            foreach (var group in groups)
                foreach (string member in group.GetProperty("sourceMembers").EnumerateArray().Select(value => value.GetString()))
                {
                    string probe = "BroadNativeEnumProbe" + probes.Count;
                    probes.Add(probe + "::" + probe + "_Value", (group.GetProperty("name").GetString(), member));
                    // Widen the carrier's actual C++ conversion so libclang's signed accessor preserves UInt32 high bits.
                    controls += "\n#ifdef " + member + "\nenum " + probe + " : long long { " + probe +
                        "_Value = static_cast<long long>(static_cast<" + group.GetProperty("storage").GetString() +
                        ">(" + member + ")) };\n#endif\n";
                }
            var native = WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot,
                Path.Combine(batch, "before"), "MenuRc", architecture, target, new[] { "main.cpp" }, controls,
                sourceText: NativeSource(report.RootElement));
            var values = names.ToDictionary(name => name, _ => new Dictionary<string, long>(StringComparer.Ordinal), StringComparer.Ordinal);
            foreach (string value in native.Where(value => value.StartsWith("value BroadNativeEnumProbe", StringComparison.Ordinal)))
            {
                int end = value.LastIndexOf(' ');
                var probe = probes[value.Substring(6, end - 6)];
                values[probe.Group].Add(probe.Member, long.Parse(value.Substring(end + 1), CultureInfo.InvariantCulture));
            }
            var namespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Where(line => !line.StartsWith("#", StringComparison.Ordinal)).Select(line => line.Split('=', 2))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            foreach (var group in groups)
            {
                string name = group.GetProperty("name").GetString();
                string fullName = group.GetProperty("baseline").GetProperty("fullName").GetString();
                string ns = fullName.Substring(0, fullName.Length - name.Length - 1);
                if (namespaces.TryGetValue(name, out string existing))
                    Assert.Equal(ns, existing);
                else
                    namespaces.Add(name, ns);
            }
            string directory = Path.Combine(Path.GetTempPath(), "native-broad-winmd-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(Path.Combine(directory, architecture));
            try
            {
                foreach (var source in enums.GroupBy(value => value.SyntaxTree.FilePath, StringComparer.Ordinal))
                    NativeEnumMigrationTests.Write(directory, architecture, Path.GetFileName(source.Key), source);
                NativeEnumMigrationTests.Write(directory, architecture, "ActualRecords.cs", records.Values);
                NativeEnumMigrationTests.Write(directory, architecture, "ActualMethods.cs", methods.Values);
                using var image = HeaderAnnotationWinmdTests.Emit(directory, architecture, references: new[] { baseline },
                    requiredNamespaces: namespaces, nativeFieldArrayInfo: false);
                var reader = image.Reader;
                var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type => names.Contains(reader.GetString(type.Name))).ToArray();
                Assert.Equal(groups.Length, types.Length);
                var groupObservations = new List<object>();
                foreach (var group in groups)
                {
                    string name = group.GetProperty("name").GetString();
                    var type = Assert.Single(types.Where(value => reader.GetString(value.Name) == name));
                    string fullName = reader.GetString(type.Namespace) + "." + name;
                    Assert.Equal(group.GetProperty("baseline").GetProperty("fullName").GetString(), fullName);
                    var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                    string storage = fields.Single(field => reader.GetString(field.Name) == "value__")
                        .DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null);
                    string expectedStorage = group.GetProperty("baseline").GetProperty("storage").GetString() switch
                    {
                        "unsigned char" => "Byte", "unsigned short" => "UInt16", "short" => "Int16",
                        "unsigned int" => "UInt32", "int" => "Int32",
                        var unknown => throw new InvalidOperationException(unknown),
                    };
                    Assert.Equal(expectedStorage, storage);
                    var physical = fields.Where(field => reader.GetString(field.Name) != "value__").ToDictionary(
                        field => reader.GetString(field.Name), field => NativeEnumMigrationTests.ReadValue(
                            reader.GetBlobReader(reader.GetConstant(field.GetDefaultValue()).Value), storage), StringComparer.Ordinal);
                    Assert.Equal(values[name].OrderBy(pair => pair.Key), physical.OrderBy(pair => pair.Key));
                    var oldValues = group.GetProperty("baseline").GetProperty("values").EnumerateObject().ToDictionary(
                        value => value.Name, value => long.Parse(value.Value.GetString(), CultureInfo.InvariantCulture), StringComparer.Ordinal);
                    Assert.Equal(oldValues.OrderBy(pair => pair.Key), physical.OrderBy(pair => pair.Key));
                    Assert.Equal(group.GetProperty("flags").GetBoolean(), type.GetCustomAttributes()
                        .Any(handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "FlagsAttribute"));
                    Assert.DoesNotContain(type.GetCustomAttributes(),
                        handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "ScopedEnumAttribute");
                    groupObservations.Add(new { fullName, storage, nativeCarrierStorage = group.GetProperty("storage").GetString(), values = physical });
                }
                var observations = new List<object>();
                foreach (var use in uses)
                {
                    CustomAttributeHandleCollection attributes;
                    string storage;
                    if (records.ContainsKey(use.Owner))
                    {
                        var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                            .Single(value => reader.GetString(value.Name) == use.Owner);
                        var field = type.GetFields().Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == use.Slot);
                        storage = field.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(qualifiedNames: true), null);
                        attributes = field.GetCustomAttributes();
                    }
                    else
                    {
                        var method = reader.TypeDefinitions.Select(reader.GetTypeDefinition).SelectMany(type => type.GetMethods())
                            .Select(reader.GetMethodDefinition).Single(value => reader.GetString(value.Name) == use.Owner);
                        var parameter = method.GetParameters().Select(reader.GetParameter)
                            .Single(value => use.Slot == "return" ? value.SequenceNumber == 0 : reader.GetString(value.Name) == use.NativeSlot);
                        attributes = parameter.GetCustomAttributes();
                        var signature = method.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(qualifiedNames: true), null);
                        storage = use.Slot == "return" ? signature.ReturnType : signature.ParameterTypes[parameter.SequenceNumber - 1];
                    }
                    NativeEnumMigrationTests.AssertAssociation(reader, attributes, use.Attribute);
                    string primitive = use.RawType switch
                    {
                        "byte" => "Byte", "sbyte" => "SByte", "short" => "Int16", "ushort" => "UInt16",
                        "int" => "Int32", "uint" => "UInt32", "long" => "Int64", "ulong" => "UInt64",
                        _ => null,
                    };
                    if (primitive != null)
                        Assert.Equal(primitive, storage);
                    observations.Add(new { use.Group, use.Owner, use.Slot, use.NativeSlot, use.RawType, physicalType = storage });
                }
                string output = Path.Combine(batch, "observations");
                Directory.CreateDirectory(output);
                File.WriteAllText(Path.Combine(output, "actual-" + architecture + ".json"), JsonSerializer.Serialize(new
                {
                    architecture, groupObservations, useObservations = observations, physicalUseCount = observations.Count,
                    legacyEnumOverlays = 0, nativeFieldArrayInfo = false, consumerCompatibility = "not measured",
                    namespaceOrganization = groups.ToDictionary(group => group.GetProperty("name").GetString(),
                        group => namespaces[group.GetProperty("name").GetString()], StringComparer.Ordinal),
                }, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        private static string NativeSource(JsonElement report) =>
            "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n" +
            "#include <sdkddkver.h>\n#include <wincrypt.h>\n" +
            string.Join("\n", report.GetProperty("sourceContextOriginals").EnumerateArray()
                .Select(value => "#include <" + Path.GetFileName(value.GetString()) + ">"));

        private static ParameterSyntax Parameter(MethodDeclarationSyntax method, string slot) =>
            slot.StartsWith("param", StringComparison.Ordinal) ? method.ParameterList.Parameters[int.Parse(slot.Substring(5), CultureInfo.InvariantCulture)]
                : method.ParameterList.Parameters.Single(parameter => parameter.Identifier.ValueText == slot);

        private static IEnumerable<AttributeListSyntax> Lists(MethodDeclarationSyntax method, string slot) =>
            slot == "return" ? method.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return")
                : Parameter(method, slot).AttributeLists;

        private static AttributeSyntax Association(IEnumerable<AttributeListSyntax> lists, string name)
        {
            var attribute = Assert.Single(lists.SelectMany(list => list.Attributes)
                .Where(value => value.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal)));
            Assert.Equal(name, Assert.IsType<LiteralExpressionSyntax>(attribute.ArgumentList.Arguments.Single().Expression).Token.ValueText);
            return attribute;
        }
    }
}
