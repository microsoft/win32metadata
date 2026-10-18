using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class NativeEnumMigrationTests
    {
        [NativeMigrationTheory("SDK_NATIVE_ENUM_BATCH")]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ActualNativeGroupsAndUseSitesPreserveCompiledValuesAndStorage(string architecture, string target)
        {
            string batch = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BATCH");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(batch, "report.json")));
            var groups = report.RootElement.GetProperty("groups").EnumerateArray().ToArray();
            var groupNames = groups.Select(group => group.GetProperty("name").GetString()).ToHashSet(StringComparer.Ordinal);
            string sourceRoot = Path.Combine(batch, "normal", architecture);
            var rawSources = Directory.GetFiles(sourceRoot, "*.cs").Select(path =>
                CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path)).ToArray();
            var sources = rawSources.Select(tree =>
                MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree,
                    new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), new HashSet<string>(),
                    new Dictionary<string, string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                    new HashSet<string>(), new HashSet<string>(), tree.FilePath).GetRoot()).ToArray();
            var enums = sources.SelectMany(root => root.DescendantNodes().OfType<EnumDeclarationSyntax>())
                .Where(value => groupNames.Contains(value.Identifier.ValueText)).ToArray();
            Assert.Equal(groups.Length, enums.Length);

            string controls = "";
            var probeNames = new Dictionary<string, (string Group, string Member)>(StringComparer.Ordinal);
            foreach (var group in groups)
                foreach (var member in group.GetProperty("sourceMembers").EnumerateArray().Select(value => value.GetString()))
                {
                    string probe = "NativeEnumProbe" + probeNames.Count;
                    probeNames.Add(probe + "::" + probe + "_Value", (group.GetProperty("name").GetString(), member));
                    controls += "\n#ifdef " + member + "\nenum " + probe + " { " + probe + "_Value = " + member + " };\n#endif\n";
                }
            string[] originals = report.RootElement.GetProperty("originals").EnumerateArray().Select(value => value.GetString()).ToArray();
            string nativeSource = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n#include <wincrypt.h>\n" +
                string.Join("\n", originals.Select(owner => "#include <" + Path.GetFileName(owner) + ">"));
            var native = WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot,
                Path.Combine(batch, "before"), "MenuRc", architecture, target, new[] { "main.cpp" }, controls, sourceText: nativeSource);
            var expectedValues = groups.ToDictionary(group => group.GetProperty("name").GetString(),
                _ => new Dictionary<string, long>(StringComparer.Ordinal), StringComparer.Ordinal);
            foreach (string value in native.Where(value => value.StartsWith("value NativeEnumProbe", StringComparison.Ordinal)))
            {
                int end = value.LastIndexOf(' ');
                var probe = probeNames[value.Substring(6, end - 6)];
                expectedValues[probe.Group].Add(probe.Member, long.Parse(value.Substring(end + 1), CultureInfo.InvariantCulture));
            }

            var useObservations = new List<object>();
            foreach (var group in groups)
                foreach (var use in group.GetProperty("convertedUses").EnumerateArray())
                {
                    var identity = use.GetProperty("use");
                    string owner = identity.TryGetProperty("struct", out var structure)
                        ? structure.GetString() : identity.GetProperty("method").GetString();
                    string slot = identity.TryGetProperty("field", out var field)
                        ? field.GetString() : identity.GetProperty("parameter").GetString();
                    SyntaxNode declaration;
                    string actualType;
                    var record = sources.SelectMany(root => root.DescendantNodes().OfType<StructDeclarationSyntax>())
                        .SingleOrDefault(value => value.Identifier.ValueText == owner);
                    if (record != null)
                    {
                        var actual = Assert.Single(record.Members.OfType<FieldDeclarationSyntax>()
                            .Where(value => value.Declaration.Variables.Any(variable => variable.Identifier.ValueText == slot)));
                        declaration = actual;
                        actualType = actual.Declaration.Type.ToString();
                    }
                    else
                    {
                        var method = Assert.Single(sources.SelectMany(root => root.DescendantNodes().OfType<MethodDeclarationSyntax>())
                            .Where(value => value.Identifier.ValueText == owner));
                        var parameter = slot.StartsWith("param", StringComparison.Ordinal)
                            ? method.ParameterList.Parameters[int.Parse(slot.Substring(5), CultureInfo.InvariantCulture)]
                            : method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == slot);
                        declaration = parameter;
                        actualType = parameter.Type.ToString();
                        Assert.Contains(use.GetProperty("sites").EnumerateArray(),
                            site => site.GetProperty("name").GetString() == parameter.Identifier.ValueText);
                    }
                    string name = group.GetProperty("name").GetString();
                    Assert.Equal(name.StartsWith("PARAFORMAT_", StringComparison.Ordinal) ? "ushort" : "uint", actualType);
                    var attribute = Assert.Single(declaration.ChildNodes().OfType<AttributeListSyntax>().SelectMany(list => list.Attributes)
                        .Where(value => value.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal)));
                    Assert.Equal(name, Assert.IsType<LiteralExpressionSyntax>(attribute.ArgumentList.Arguments.Single().Expression).Token.ValueText);
                    useObservations.Add(new { owner, slot, actualType, associatedEnum = name });
                }
            Assert.Equal(report.RootElement.GetProperty("convertedUseFacts").GetInt32(), useObservations.Count);

            string directory = Path.Combine(Path.GetTempPath(), "native-enum-winmd-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(Path.Combine(directory, architecture));
            try
            {
                Write(directory, architecture, "Actual.header-types.cs", rawSources.SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                    .Where(value => groupNames.Contains(value.Identifier.ValueText)));
                string[] physicalRecords = { "LOGBRUSH", "LOGBRUSH32", "PARAFORMAT", "CRYPTCATATTRIBUTE", "FILE_DISPOSITION_INFO_EX" };
                var records = rawSources.SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                    .Where(value => physicalRecords.Contains(value.Identifier.ValueText, StringComparer.Ordinal)).ToArray();
                Assert.Equal(physicalRecords.Length, records.Length);
                Write(directory, architecture, "ActualRecords.cs", records);
                string[] physicalMethods =
                {
                    "CreateSymbolicLinkA", "CreateSymbolicLinkW", "CreateSymbolicLinkTransactedA", "CreateSymbolicLinkTransactedW",
                };
                var methods = rawSources.SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>())
                    .Where(value => physicalMethods.Contains(value.Identifier.ValueText, StringComparer.Ordinal)).ToArray();
                Assert.Equal(physicalMethods.Length, methods.Length);
                Write(directory, architecture, "ActualMethods.cs", methods);
                using var image = HeaderAnnotationWinmdTests.Emit(directory, architecture, nativeFieldArrayInfo: false);
                var reader = image.Reader;
                var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(value => groupNames.Contains(reader.GetString(value.Name))).ToDictionary(value => reader.GetString(value.Name));
                Assert.Equal(groups.Length, types.Count);
                var groupObservations = new List<object>();
                foreach (var group in groups)
                {
                    string name = group.GetProperty("name").GetString();
                    var type = types[name];
                    Assert.Equal(Namespace(enums.Single(value => value.Identifier.ValueText == name)), reader.GetString(type.Namespace));
                    var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                    string storage = fields.Single(value => reader.GetString(value.Name) == "value__")
                        .DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null);
                    Assert.Equal(group.GetProperty("storage").GetString() switch
                    {
                        "short" => "Int16",
                        "unsigned short" => "UInt16",
                        "unsigned int" => "UInt32",
                        var unknown => throw new InvalidOperationException(unknown),
                    }, storage);
                    var values = fields.Where(value => reader.GetString(value.Name) != "value__").ToDictionary(
                        value => reader.GetString(value.Name), value => ReadValue(reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value), storage));
                    Assert.Equal(expectedValues[name].OrderBy(value => value.Key), values.OrderBy(value => value.Key));
                    Assert.Equal(group.GetProperty("flags").GetBoolean(),
                        type.GetCustomAttributes().Any(handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "FlagsAttribute"));
                    Assert.DoesNotContain(type.GetCustomAttributes(),
                        handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "ScopedEnumAttribute");
                    groupObservations.Add(new { name, metadataNamespace = reader.GetString(type.Namespace), storage, values });
                }
                int physicalUseCount = 0;
                foreach (var record in records)
                {
                    var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                        .Single(value => reader.GetString(value.Name) == record.Identifier.ValueText);
                    foreach (var field in record.Members.OfType<FieldDeclarationSyntax>())
                    {
                        var association = field.AttributeLists.SelectMany(list => list.Attributes)
                            .SingleOrDefault(value => value.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal));
                        if (association == null)
                            continue;
                        var actual = type.GetFields().Select(reader.GetFieldDefinition)
                            .Single(value => reader.GetString(value.Name) == field.Declaration.Variables.Single().Identifier.ValueText);
                        Assert.Equal(field.Declaration.Type.ToString() == "ushort" ? "UInt16" : "UInt32",
                            actual.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null));
                        AssertAssociation(reader, actual.GetCustomAttributes(), association);
                        physicalUseCount++;
                    }
                }
                foreach (var method in methods)
                {
                    var actual = reader.TypeDefinitions.Select(reader.GetTypeDefinition).SelectMany(type => type.GetMethods())
                        .Select(reader.GetMethodDefinition).Single(value => reader.GetString(value.Name) == method.Identifier.ValueText);
                    var parameter = actual.GetParameters().Select(reader.GetParameter).Single(value => reader.GetString(value.Name) == "dwFlags");
                    var association = method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == "dwFlags")
                        .AttributeLists.SelectMany(list => list.Attributes)
                        .Single(value => value.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal));
                    Assert.Equal("UInt32", actual.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null).ParameterTypes[2]);
                    AssertAssociation(reader, parameter.GetCustomAttributes(), association);
                    physicalUseCount++;
                }
                Assert.Equal(10, physicalUseCount);
                string observations = Path.Combine(batch, "observations");
                Directory.CreateDirectory(observations);
                File.WriteAllText(Path.Combine(observations, "actual-" + architecture + ".json"),
                    JsonSerializer.Serialize(new { architecture, groupObservations, useObservations, physicalUseCount,
                        legacyEnumOverlays = 0, nativeFieldArrayInfo = false }, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        [NativeMigrationTheory("SDK_NATIVE_ENUM_FROZEN_FS")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ActualForwardGroupsReachFsWinmdWithNativeSignatures(string architecture)
        {
            string frozen = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_FROZEN_FS");
            string batch = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BATCH");
            Assert.False(string.IsNullOrEmpty(batch));
            string source = Path.Combine(frozen, "canonical-fs", architecture);
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(source, "Fs.cs"))).GetRoot();
            var groups = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(source, "Fs.header-types.cs"))).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>().ToArray();
            string[] groupNames = { "FILE_TYPE", "GETFINALPATHNAMEBYHANDLE_FLAGS" };
            Assert.Equal(groupNames.OrderBy(value => value), groups.Select(group => group.Identifier.ValueText).OrderBy(value => value));
            string[] names = { "GetFileType", "GetFinalPathNameByHandleA", "GetFinalPathNameByHandleW" };
            var methods = tree.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .Where(method => names.Contains(method.Identifier.ValueText, StringComparer.Ordinal)).ToArray();
            Assert.Equal(names.Length, methods.Length);
            using var control = JsonDocument.Parse(File.ReadAllText(Path.Combine(batch, "observations", "actual-" + architecture + ".json")));
            var nativeGroups = control.RootElement.GetProperty("groupObservations").EnumerateArray().ToDictionary(
                value => value.GetProperty("name").GetString());
            string directory = Path.Combine(Path.GetTempPath(), "native-forward-fs-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(Path.Combine(directory, architecture));
            try
            {
                Write(directory, architecture, "Fs.header-types.cs", groups);
                Write(directory, architecture, "Fs.cs", methods);
                using var image = HeaderAnnotationWinmdTests.Emit(directory, architecture, nativeFieldArrayInfo: false);
                var reader = image.Reader;
                var enumObservations = new List<object>();
                foreach (string name in groupNames)
                {
                    var type = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(value => reader.GetString(value.Name) == name);
                    Assert.Equal("Windows.Win32.Storage.FileSystem", reader.GetString(type.Namespace));
                    var fields = type.GetFields().Select(reader.GetFieldDefinition).ToArray();
                    Assert.Equal("UInt32", fields.Single(value => reader.GetString(value.Name) == "value__")
                        .DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null));
                    var values = fields.Where(value => reader.GetString(value.Name) != "value__").ToDictionary(
                        value => reader.GetString(value.Name), value => ReadValue(reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value), "UInt32"));
                    var expected = nativeGroups[name].GetProperty("values").EnumerateObject().ToDictionary(value => value.Name, value => value.Value.GetInt64());
                    Assert.Equal(expected.OrderBy(value => value.Key), values.OrderBy(value => value.Key));
                    Assert.DoesNotContain(type.GetCustomAttributes(), handle =>
                        new[] { "FlagsAttribute", "ScopedEnumAttribute" }.Contains(HeaderAnnotationWinmdTests.AttributeName(reader, handle)));
                    enumObservations.Add(new { fullName = reader.GetString(type.Namespace) + "." + name, storage = "UInt32", values });
                }
                var methodObservations = new List<object>();
                foreach (var method in methods)
                {
                    string name = method.Identifier.ValueText;
                    var actual = reader.TypeDefinitions.Select(reader.GetTypeDefinition).SelectMany(type => type.GetMethods())
                        .Select(reader.GetMethodDefinition).Single(value => reader.GetString(value.Name) == name);
                    var signature = actual.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null);
                    Assert.Equal("UInt32", signature.ReturnType);
                    bool returned = name == "GetFileType";
                    Assert.Equal(returned ? new[] { "IntPtr" } : new[] { "IntPtr", name.EndsWith("A", StringComparison.Ordinal)
                        ? "SByte*" : "UInt16*", "UInt32", "UInt32" }, signature.ParameterTypes);
                    var parameters = actual.GetParameters().Select(reader.GetParameter).ToArray();
                    var slot = returned ? parameters.Single(value => value.SequenceNumber == 0)
                        : parameters.Single(value => reader.GetString(value.Name) == "dwFlags");
                    var association = (returned ? method.AttributeLists.Where(list => list.Target?.Identifier.ValueText == "return")
                            : method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == "dwFlags").AttributeLists)
                        .SelectMany(list => list.Attributes).Single(value => value.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal));
                    AssertAssociation(reader, slot.GetCustomAttributes(), association);
                    Assert.Equal(returned ? "FILE_TYPE" : "GETFINALPATHNAMEBYHANDLE_FLAGS",
                        ((LiteralExpressionSyntax)association.ArgumentList.Arguments.Single().Expression).Token.ValueText);
                    Assert.Equal(1, parameters.Sum(parameter => parameter.GetCustomAttributes().Count(handle =>
                        HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "AssociatedEnumAttribute")));
                    methodObservations.Add(new { name, signature.ReturnType, signature.ParameterTypes,
                        associationSlot = returned ? "return" : "dwFlags" });
                }
                string observations = Path.Combine(frozen, "canonical-fs", "observations");
                Directory.CreateDirectory(observations);
                File.WriteAllText(Path.Combine(observations, "physical-" + architecture + ".json"),
                    JsonSerializer.Serialize(new { architecture, enumObservations, methodObservations,
                        legacyEnumOverlays = 0, nativeFieldArrayInfo = false }, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        private static void Write(string directory, string architecture, string name, IEnumerable<MemberDeclarationSyntax> members)
        {
            var namespaces = members.GroupBy(Namespace).Select(group =>
            {
                IEnumerable<MemberDeclarationSyntax> declarations = group;
                if (group.First() is MethodDeclarationSyntax)
                    declarations = new[] { ((ClassDeclarationSyntax)group.First().Parent)
                        .WithMembers(SyntaxFactory.List(group)) };
                return SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(group.Key))
                    .WithMembers(SyntaxFactory.List(declarations));
            });
            var unit = SyntaxFactory.CompilationUnit().AddUsings(
                SyntaxFactory.UsingDirective(SyntaxFactory.ParseName("System")),
                SyntaxFactory.UsingDirective(SyntaxFactory.ParseName("System.Runtime.InteropServices")),
                SyntaxFactory.UsingDirective(SyntaxFactory.ParseName("Windows.Win32.Foundation.Metadata")))
                .WithMembers(SyntaxFactory.List<MemberDeclarationSyntax>(namespaces));
            File.WriteAllText(Path.Combine(directory, architecture, name), unit.NormalizeWhitespace().ToFullString());
        }

        private static string Namespace(SyntaxNode declaration) =>
            declaration.Ancestors().OfType<NamespaceDeclarationSyntax>().Single().Name.ToString();

        private static long ReadValue(BlobReader reader, string storage) => storage switch
        {
            "UInt32" => reader.ReadUInt32(),
            "UInt16" => reader.ReadUInt16(),
            "Int16" => reader.ReadInt16(),
            var unknown => throw new InvalidOperationException(unknown),
        };

        private static void AssertAssociation(MetadataReader reader, CustomAttributeHandleCollection attributes, AttributeSyntax expected)
        {
            var handle = Assert.Single(attributes.Where(value =>
                HeaderAnnotationWinmdTests.AttributeName(reader, value) == "AssociatedEnumAttribute"));
            var blob = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
            Assert.Equal(1, blob.ReadUInt16());
            Assert.Equal(((LiteralExpressionSyntax)expected.ArgumentList.Arguments.Single().Expression).Token.ValueText, blob.ReadSerializedString());
            Assert.Equal(0, blob.ReadUInt16());
            Assert.Equal(0, blob.RemainingBytes);
        }
    }
}
