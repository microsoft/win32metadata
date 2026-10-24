using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using MetadataTasks;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class NativeContractMigrationTests
    {
        [NativeMigrationTheory("SDK_NATIVE_CONTRACT_BATCH")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ActualResultAndPointerContractsReachPhysicalWinmdWithoutOverrides(string architecture)
        {
            string batch = Environment.GetEnvironmentVariable("SDK_NATIVE_CONTRACT_BATCH");
            string source = Path.Combine(batch, "normal", architecture);
            string baseline = Environment.GetEnvironmentVariable("SDK_NATIVE_ENUM_BASELINE_WINMD");
            Assert.False(string.IsNullOrEmpty(baseline));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(batch, "report.json")));
            var facts = report.RootElement.GetProperty("converted").EnumerateArray().ToArray();
            var roots = Directory.GetFiles(source, "*.cs").ToDictionary(Path.GetFileName,
                path => CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path).GetRoot(), StringComparer.Ordinal);
            var selected = new Dictionary<string, MethodDeclarationSyntax>(StringComparer.Ordinal);
            var observations = new List<object>();
            foreach (var fact in facts)
            {
                string name = fact.GetProperty("function").GetString();
                string parameter = fact.GetProperty("parameter").GetString();
                string attribute = Attribute(fact.GetProperty("macro").GetString());
                var candidates = roots.SelectMany(pair => pair.Value.DescendantNodes().OfType<MethodDeclarationSyntax>())
                    .Where(method => method.Identifier.ValueText == name).ToArray();
                Assert.NotEmpty(candidates);
                foreach (var method in candidates)
                {
                    var attributes = parameter == null ? method.AttributeLists.SelectMany(list => list.Attributes)
                        : method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == parameter)
                            .AttributeLists.SelectMany(list => list.Attributes);
                    Assert.True(attributes.Count(value => value.Name.ToString().EndsWith(attribute, StringComparison.Ordinal)) == 1,
                        fact.GetProperty("value").GetString() + " in " + method.SyntaxTree.FilePath + ": expected one " + attribute);
                }
                Assert.Single(candidates.Select(method => method.ReturnType + "(" + string.Join(",",
                    method.ParameterList.Parameters.Select(value => value.Type + " " + value.Identifier.ValueText)) + ")")
                    .Distinct(StringComparer.Ordinal));
                var primary = candidates.OrderBy(method => method.SyntaxTree.FilePath, StringComparer.Ordinal).First();
                if (selected.TryGetValue(name, out var existing))
                    Assert.Equal(existing.ToString(), primary.ToString());
                else
                    selected.Add(name, primary);
            }
            Assert.Equal(report.RootElement.GetProperty("convertedCount").GetInt32(), facts.Length);
            var namespaces = RspReader.GetSettingsValues(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "requiredNamespacesForNames.rsp"), "--requiredNamespaceForName")
                .Where(line => !line.StartsWith("#", StringComparison.Ordinal)).Select(line => line.Split('=', 2))
                .ToDictionary(parts => parts[0], parts => parts[1], StringComparer.Ordinal);
            string directory = Path.Combine(Path.GetTempPath(), "native-contract-winmd-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(Path.Combine(directory, architecture));
            try
            {
                NativeEnumMigrationTests.Write(directory, architecture, "ActualContracts.cs", selected.Values);
                using var image = HeaderAnnotationWinmdTests.Emit(directory, architecture, references: new[] { baseline },
                    requiredNamespaces: namespaces, nativeFieldArrayInfo: false);
                var reader = image.Reader;
                var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition).SelectMany(type => type.GetMethods())
                    .Select(reader.GetMethodDefinition).Where(method => selected.ContainsKey(reader.GetString(method.Name)))
                    .ToDictionary(method => reader.GetString(method.Name), StringComparer.Ordinal);
                Assert.Equal(selected.Count, physical.Count);
                foreach (var fact in facts)
                {
                    string name = fact.GetProperty("function").GetString();
                    string parameter = fact.GetProperty("parameter").GetString();
                    string attribute = Attribute(fact.GetProperty("macro").GetString());
                    var method = physical[name];
                    var attributes = parameter == null ? method.GetCustomAttributes()
                        : method.GetParameters().Select(reader.GetParameter)
                            .Single(value => reader.GetString(value.Name) == parameter).GetCustomAttributes();
                    if (attribute == "PreserveSig")
                        Assert.True(method.ImplAttributes.HasFlag(MethodImplAttributes.PreserveSig), name);
                    else
                    {
                        if (attribute == "RAIIFree" && parameter == null)
                            attributes = method.GetParameters().Select(reader.GetParameter)
                                .Single(value => value.SequenceNumber == 0).GetCustomAttributes();
                        var actual = Assert.Single(attributes.Where(handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == attribute + "Attribute"));
                        if (attribute == "RAIIFree")
                        {
                            var blob = reader.GetBlobReader(reader.GetCustomAttribute(actual).Value);
                            Assert.Equal(1, blob.ReadUInt16());
                            string macro = fact.GetProperty("macro").GetString();
                            Assert.Equal(macro.Substring("_Win32_RAIIFree_(".Length).TrimEnd(')'), blob.ReadSerializedString());
                            Assert.Equal(0, blob.ReadUInt16());
                        }
                    }
                    var signature = method.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(qualifiedNames: true), null);
                    var type = reader.GetTypeDefinition(method.GetDeclaringType());
                    observations.Add(new
                    {
                        original = fact.GetProperty("original").GetString(),
                        requiredOriginals = fact.GetProperty("requiredOriginals").EnumerateArray().Select(value => value.GetString()).ToArray(),
                        fullName = reader.GetString(type.Namespace) + "." + reader.GetString(type.Name) + "::" + name,
                        parameter,
                        attribute,
                        signature.ReturnType,
                        signature.ParameterTypes,
                        rawReturnType = selected[name].ReturnType.ToString(),
                        rawParameterTypes = selected[name].ParameterList.Parameters.Select(value => value.Type.ToString()).ToArray(),
                        actualSourceRoute = Path.GetFileNameWithoutExtension(selected[name].SyntaxTree.FilePath),
                        inventoryRouteCandidates = fact.GetProperty("partitionCandidates").EnumerateArray()
                            .Select(value => value.GetString()).ToArray(),
                    });
                }
                string output = Path.Combine(batch, "observations");
                Directory.CreateDirectory(output);
                File.WriteAllText(Path.Combine(output, "actual-" + architecture + ".json"), JsonSerializer.Serialize(new
                {
                    architecture,
                    sourceFactCount = facts.Length,
                    physicalFactCount = observations.Count,
                    methods = physical.Count,
                    observations,
                    legacyDeclarationOverrides = 0,
                    nativeFieldArrayInfo = false,
                    baselineSuppliesExternalTypesOnly = baseline,
                }, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        private static string Attribute(string macro)
        {
            if (macro.StartsWith("_Win32_RAIIFree_(", StringComparison.Ordinal))
                return "RAIIFree";
            return macro switch
            {
                "_Win32_PreserveResult_" => "PreserveSig",
                "_Win32_Retained_" => "Retained",
                "_Win32_ContainsInteriorPointers_" => "ContainsInteriorPointers",
                _ => throw new InvalidOperationException("Unexpected canonical contract: " + macro),
            };
        }
    }
}
