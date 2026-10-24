using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Metadata;
using System.Runtime.InteropServices;
using System.Runtime.Loader;
using System.Text.Json;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NonfloorIdlMigrationTests
    {
        [NonfloorIdlSourceTheory("SDK_NONFLOOR_ROWSET_RECORD_ROOT", "SDK_BULK_NATIVE_OBSERVATIONS")]
        [InlineData("x86", 4)]
        [InlineData("x64", 8)]
        [InlineData("arm64", 8)]
        public void ActualReturnedBufferRecordReachesPhysicalWinmdWithoutLegacyOverlays(string architecture, int nativeOrdinalBytes)
        {
            string frozen = Path.Combine(Environment.GetEnvironmentVariable("SDK_NONFLOOR_ROWSET_RECORD_ROOT"),
                "bulk-idl-nonfloor-rowsetkeys-failure-" + architecture + ".cs");
            string source = File.ReadAllText(frozen);
            var tree = CSharpSyntaxTree.ParseText(source);
            var record = Assert.Single(tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()
                .Where(value => value.Identifier.ValueText == "IRowsetKeys"));
            var method = record.Members.OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == "ListKeys");
            string[] originalTypes = method.ParameterList.Parameters.Select(value => value.Type.ToString()).ToArray();
            Assert.Equal(new[] { "UIntPtr*", "UIntPtr**" }, originalTypes);
            Assert.Equal(new[] { "DBORDINAL *", "DBORDINAL **" }, method.ParameterList.Parameters.Select(parameter =>
                Assert.IsType<LiteralExpressionSyntax>(AssertAttribute(parameter, "NativeTypeName").ArgumentList.Arguments.Single().Expression).Token.ValueText));
            var clean = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree,
                new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), new HashSet<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                new HashSet<string>(), new HashSet<string>(), frozen).GetRoot();
            var columns = clean.DescendantNodes().OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == "ListKeys")
                .ParameterList.Parameters.Single(value => value.Identifier.ValueText == "prgColumns");
            AssertCount(columns, 0);
            AssertAttribute(columns, "Out");
            Assert.DoesNotContain(Attributes(columns), attribute => Name(attribute) == "In");

            // The frozen diagnostic packet omitted only the native record's three outer attributes.
            source = source.Replace("    public unsafe partial struct IRowsetKeys",
                "    [Guid(\"0C733A12-2A1C-11CE-ADE5-00AA0044773D\")]\n" +
                "    [NativeTypeName(\"struct IRowsetKeys : IUnknown\")]\n" +
                "    [NativeInheritance(\"IUnknown\")]\n    public unsafe partial struct IRowsetKeys", StringComparison.Ordinal);
            string directory = Path.Combine(Path.GetTempPath(), "nonfloor-rowset-" + Guid.NewGuid().ToString("N"));
            try
            {
                Directory.CreateDirectory(Path.Combine(directory, architecture));
                File.WriteAllText(Path.Combine(directory, architecture, "Actual.cs"), source);
                var inherited = record.Members.OfType<MethodDeclarationSyntax>()
                    .Where(value => new[] { "QueryInterface", "AddRef", "Release" }.Contains(value.Identifier.ValueText)).ToArray();
                Assert.Equal(3, inherited.Length);
                var vtable = Assert.Single(record.Members.OfType<FieldDeclarationSyntax>().Where(value =>
                    value.Declaration.Variables.Single().Identifier.ValueText == "lpVtbl"));
                var delegates = record.Members.OfType<DelegateDeclarationSyntax>()
                    .Where(value => new[] { "_QueryInterface", "_AddRef", "_Release" }.Contains(value.Identifier.ValueText))
                    .Select(value => value.ReplaceNodes(value.DescendantNodes().OfType<IdentifierNameSyntax>()
                        .Where(name => name.Identifier.ValueText == "IRowsetKeys"),
                        (_, _) => SyntaxFactory.IdentifierName("IUnknown"))).ToArray();
                Assert.Equal(3, delegates.Length);
                var body = SyntaxFactory.Block(SyntaxFactory.ThrowStatement(SyntaxFactory.ObjectCreationExpression(
                    SyntaxFactory.IdentifierName("NotImplementedException")).WithArgumentList(SyntaxFactory.ArgumentList())));
                string baseSource = "using System;\nusing System.Runtime.InteropServices;\nusing Windows.Win32.Foundation.Metadata;\n" +
                    "namespace " + record.Ancestors().OfType<NamespaceDeclarationSyntax>().Single().Name + " {\n" +
                    "[Guid(\"00000000-0000-0000-C000-000000000046\")] public unsafe partial struct IUnknown {\n" +
                    vtable.ToFullString() + string.Join("\n", delegates.Select(value => value.ToFullString())) +
                    string.Join("\n", inherited.Select(value => value.WithBody(body).NormalizeWhitespace().ToFullString())) + "\n}\n}";
                File.WriteAllText(Path.Combine(directory, architecture, "IUnknown.cs"), baseSource);
                using var image = HeaderAnnotationWinmdTests.Emit(directory, architecture, nativeFieldArrayInfo: false);
                var reader = image.Reader;
                var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(value => reader.GetString(value.Name) == "IRowsetKeys")
                    .GetMethods().Select(reader.GetMethodDefinition).Single(value => reader.GetString(value.Name) == "ListKeys");
                var signature = physical.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null);
                Assert.Equal("Int32", signature.ReturnType);
                Assert.Equal(originalTypes, signature.ParameterTypes);
                var parameters = physical.GetParameters().Select(reader.GetParameter).ToArray();
                Assert.Equal(ParameterAttributes.In | ParameterAttributes.Out,
                    parameters.Single(value => reader.GetString(value.Name) == "pcColumns").Attributes);
                var output = parameters.Single(value => reader.GetString(value.Name) == "prgColumns");
                Assert.Equal(ParameterAttributes.Out, output.Attributes);
                var attribute = reader.GetCustomAttribute(Assert.Single(output.GetCustomAttributes().Where(handle =>
                    HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "NativeArrayInfoAttribute")));
                var blob = reader.GetBlobReader(attribute.Value);
                Assert.Equal(1, blob.ReadUInt16());
                Assert.Equal(1, blob.ReadUInt16());
                Assert.Equal(0x53, blob.ReadByte());
                Assert.Equal((byte)SignatureTypeCode.Int16, blob.ReadByte());
                Assert.Equal("CountParamIndex", blob.ReadSerializedString());
                Assert.Equal(0, blob.ReadInt16());
                Assert.Equal(0, blob.RemainingBytes);
                string observations = Environment.GetEnvironmentVariable("SDK_BULK_NATIVE_OBSERVATIONS");
                Directory.CreateDirectory(observations);
                File.WriteAllText(Path.Combine(observations, "rowset-fixed-" + architecture + ".json"),
                    JsonSerializer.Serialize(new
                    {
                        architecture, frozenActualRecord = frozen, nativeOrdinalBytes,
                        nativeOrdinalMetadataType = "UIntPtr", originalTypes, physicalTypes = signature.ParameterTypes,
                        countParamIndex = (short)0, outputFlags = output.Attributes.ToString(),
                        outputArrayAttributes = 1, legacyOverlays = 0, nativeFieldArrayInfo = false,
                    }, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                if (Directory.Exists(directory))
                    Directory.Delete(directory, recursive: true);
            }
        }

        [NonfloorIdlSourceTheory("SDK_NONFLOOR_FRAGMENT_GENERATED_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ActualScopedOperationsFragmentReachesNormalGenerationWithoutLegacyOverlays(string architecture)
        {
            string generated = Environment.GetEnvironmentVariable("SDK_NONFLOOR_FRAGMENT_GENERATED_ROOT");
            Assert.False(string.IsNullOrEmpty(generated));
            string path = Path.Combine(generated, architecture, "Search.cs");
            if (!File.Exists(path))
                path = Path.Combine(generated, "common", "Search.cs");
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path);
            Assert.Empty(tree.GetDiagnostics().Where(value => value.Severity == DiagnosticSeverity.Error));
            var actual = MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree,
                new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), new HashSet<string>(),
                new Dictionary<string, string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                new HashSet<string>(), new HashSet<string>(), path).GetRoot();
            foreach (string method in new[] { "Copy", "Move" })
                AssertAttribute(Parameter("IScopedOperations", method, "pAuthenticate"), "Optional");
            ParameterSyntax Parameter(string owner, string method, string parameter) => Assert.Single(
                actual.DescendantNodes().OfType<TypeDeclarationSyntax>().Single(value => value.Identifier.ValueText == owner)
                    .Members.OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == method)
                    .ParameterList.Parameters.Where(value => value.Identifier.ValueText == parameter));
        }

        [NonfloorIdlSourceTheory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void ActualOriginalIdlFactsReachNormalGenerationWithoutLegacyOverlays(string architecture)
        {
            string generated = Environment.GetEnvironmentVariable("SDK_NONFLOOR_GENERATED_ROOT");
            var trees = new Dictionary<string, SyntaxNode>(StringComparer.Ordinal);
            foreach (string route in new[]
            {
                "Base", "WindowsFilteringPlatform", "Shell", "XmlLite", "Debug.ActiveScript", "MsHtml",
                "Audio.Apo", "Debug", "CompositionSwapchain", "ComOle", "NetMgmt", "MsTv", "Shell.Common",
            })
            {
                foreach (string suffix in new[] { ".cs", ".header-types.cs" })
                {
                    string path = Path.Combine(generated, architecture, route + suffix);
                    if (!File.Exists(path))
                        path = Path.Combine(generated, "common", route + suffix);
                    if (!File.Exists(path))
                    {
                        Assert.Equal(".header-types.cs", suffix);
                        continue;
                    }
                    var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path);
                    Assert.Empty(tree.GetDiagnostics().Where(value => value.Severity == DiagnosticSeverity.Error));
                    trees.Add(route + suffix, MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree,
                        new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), new HashSet<string>(),
                        new Dictionary<string, string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
                        new HashSet<string>(), new HashSet<string>(), path).GetRoot());
                }
            }

            foreach (var owner in new[]
            {
                ("Base", "STGC"), ("Base", "VARENUM"), ("Shell", "HLFNAMEF"), ("Shell", "HLNF"),
                ("Debug.ActiveScript", "PROFILER_HEAP_ENUM_FLAGS"),
                ("Debug.ActiveScript", "PROFILER_HEAP_OBJECT_FLAGS"),
                ("Debug.ActiveScript", "PROFILER_HEAP_OBJECT_RELATIONSHIP_FLAGS"),
            })
                AssertAttribute(Enum(owner.Item1, owner.Item2), "Flags");
            foreach (var owner in new[] { ("Base", "ROT_FLAGS"), ("ComOle", "FDEX_PROP_FLAGS"), ("Debug", "DBGPROP_ATTRIB_FLAGS") })
                AssertAttribute(Enum(owner.Item1, owner.Item2, true), "Flags");

            Assert.Equal(new ulong[] { 4097, 4098, 20483, 24580, 16389, 8198, 7, 8 },
                Values(Enum("WindowsFilteringPlatform", "FWP_ACTION_TYPE", true)));
            Assert.Equal(new ulong[] { 1, 2 }, Values(Enum("Base", "ROT_FLAGS", true)));
            Assert.Equal(Enumerable.Range(0, 14).Select(index => 1UL << index),
                Values(Enum("ComOle", "FDEX_PROP_FLAGS", true)));
            foreach (string function in new[]
            {
                "HlinkCreateFromMoniker", "HlinkCreateFromString", "HlinkCreateFromData", "HlinkClone",
                "HlinkCreateBrowseContext", "HlinkCreateExtensionServices",
            })
                AssertAttribute(Parameter("Shell", "Apis", function, "ppvObj"), "ComOutPtr");
            foreach (string method in new[]
            {
                "MoveToAttributeByName", "MoveToNextAttribute", "MoveToFirstAttribute", "Read", "ReadValueChunk",
            })
                AssertAttribute(Method("XmlLite", "IXmlReader", method), "PreserveSig");
            AssertAttribute(Parameter("MsHtml", "IClassFactoryEx", "CreateInstanceWithContext", "ppv"), "ComOutPtr");
            AssertAttribute(Parameter("CompositionSwapchain", "Apis", "CreatePresentationFactory", "presentationFactory"), "ComOutPtr");
            AssertAttribute(Parameter("CompositionSwapchain", "IPresentationManager", "GetPresentRetiringFence", "fence"), "ComOutPtr");
            foreach (var field in new[] { ("dwFlags", "DOCHOSTUIFLAG"), ("dwDoubleClick", "DOCHOSTUIDBLCLK") })
            {
                var declaration = Type("MsHtml", "DOCHOSTUIINFO").Members.OfType<FieldDeclarationSyntax>()
                    .Single(value => value.Declaration.Variables.Single().Identifier.ValueText == field.Item1);
                var attribute = AssertAttribute(declaration, "AssociatedEnum");
                Assert.Equal(field.Item2, Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText);
            }
            foreach (var parameter in new[] { ("ppInputConnections", 0), ("ppOutputConnections", 2) })
                AssertCount(Parameter("Audio.Apo", "IAudioProcessingObjectConfiguration", "LockForProcess", parameter.Item1), parameter.Item2);
            AssertCount(Parameter("Debug", "IEnumDebugPropertyInfo", "Next", "pi"), 0);
            Assert.DoesNotContain(Attributes(Parameter("NetMgmt", "INetCfgComponentUpperEdge", "AddInterfacesToAdapter", "pAdapter")),
                attribute => Name(attribute) == "NativeArrayInfo");
            Assert.DoesNotContain(Attributes(Enum("Debug.ActiveScript", "JsDebugReadMemoryFlags")), attribute => Name(attribute) == "ScopedEnum");

            TypeDeclarationSyntax Type(string route, string name) => Assert.Single(trees[route + ".cs"].DescendantNodes()
                .OfType<TypeDeclarationSyntax>().Where(value => value.Identifier.ValueText == name));
            EnumDeclarationSyntax Enum(string route, string name, bool logical = false) => Assert.Single(
                trees[route + (logical ? ".header-types.cs" : ".cs")].DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Where(value => value.Identifier.ValueText == name));
            MethodDeclarationSyntax Method(string route, string owner, string name) => Assert.Single(
                Type(route, owner).Members.OfType<MethodDeclarationSyntax>().Where(value => value.Identifier.ValueText == name));
            ParameterSyntax Parameter(string route, string owner, string method, string name) => Assert.Single(
                Method(route, owner, method).ParameterList.Parameters.Where(value => value.Identifier.ValueText == name));
        }

        [NonfloorIdlSourceTheory("SDK_NONFLOOR_GENERATED_ROOT", "SDK_BULK_HEADER_BASELINE", "SDK_BULK_NATIVE_OBSERVATIONS")]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativePackedChildrenPreserveTheFourPhysicalOuterLayouts(string architecture, string target)
        {
            string generated = Environment.GetEnvironmentVariable("SDK_NONFLOOR_GENERATED_ROOT");
            string nativeBaseline = Environment.GetEnvironmentVariable("SDK_BULK_HEADER_BASELINE");
            Assert.False(string.IsNullOrEmpty(nativeBaseline));
            var expected = new[]
            {
                (Name: "MPEG_TIME", Size: 3, Fields: new[] { ("Hours", 0), ("Minutes", 1), ("Seconds", 2) }),
                (Name: "SECTION", Size: 4, Fields: new[] { ("TableId", 0), ("Header", 1), ("SectionData", 3) }),
                (Name: "MPEG_DATE_AND_TIME", Size: 7, Fields: new[] { ("D", 0), ("T", 4) }),
                (Name: "ITEMIDLIST", Size: 3, Fields: new[] { ("mkid", 0) }),
            };
            string checks = string.Join("\n", expected.SelectMany(item => new[]
            {
                $"static_assert(sizeof({item.Name}) == {item.Size}, \"same-MIDL native size\");",
                $"static_assert(alignof({item.Name}) == 1, \"same-MIDL native alignment\");",
            }.Concat(item.Fields.Select(field =>
                $"static_assert(__builtin_offsetof({item.Name}, {field.Item1}) == {field.Item2}, \"same-MIDL native field offset\");"))));
            WinHttpNativeControlTests.Surface(WinHttpMigrationTests.RepositoryRoot, nativeBaseline, "MenuRc",
                architecture, target, new[] { "mpeg2structs.h", "shtypes.h" }, checks,
                sourceText: "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <mpeg2structs.h>\n#include <shtypes.h>\n");

            var records = new List<StructDeclarationSyntax>();
            foreach (var input in new[]
            {
                (Route: "MsTv", Names: new[] { "MPEG_TIME", "MPEG_DATE", "MPEG_DATE_AND_TIME", "MPEG_HEADER_BITS_MIDL", "SECTION" }),
                (Route: "Shell.Common", Names: new[] { "SHITEMID", "ITEMIDLIST" }),
            })
            {
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(generated, "common", input.Route + ".cs")));
                foreach (string name in input.Names)
                    records.Add(Assert.Single(tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()
                        .Where(record => record.Identifier.ValueText == name)));
            }
            var namespaces = records.ToDictionary(record => record.Identifier.ValueText,
                record => record.Ancestors().OfType<BaseNamespaceDeclarationSyntax>().Single().Name.ToString(), StringComparer.Ordinal);
            string source = "using System;\nusing System.Runtime.InteropServices;\nusing Windows.Win32.Foundation.Metadata;\n" +
                string.Join("\n", records.GroupBy(record => namespaces[record.Identifier.ValueText]).Select(group =>
                    "namespace " + group.Key + " {\n" + string.Join("\n", group.Select(record => record.ToFullString())) +
                    string.Join("\n", expected.Where(item => namespaces[item.Name] == group.Key).Select(item =>
                        $"public struct Align_{item.Name} {{ public byte prefix; public {item.Name} value; }}")) + "\n}"));
            string directory = Path.Combine(Path.GetTempPath(), "nonfloor-layout-" + Guid.NewGuid().ToString("N"));
            var observations = new List<object>();
            var legacyFields = new Dictionary<string, string[]>(StringComparer.Ordinal);
            try
            {
                foreach (bool legacy in new[] { true, false })
                {
                    string phase = Path.Combine(directory, legacy ? "legacy" : "native");
                    Directory.CreateDirectory(Path.Combine(phase, architecture));
                    File.WriteAllText(Path.Combine(phase, architecture, "Actual.cs"), source);
                    var remaps = legacy ? expected.ToDictionary(item => item.Name,
                        _ => "[StructLayout(LayoutKind.Sequential, Pack = 1)]", StringComparer.Ordinal) : new Dictionary<string, string>();
                    using var image = HeaderAnnotationWinmdTests.Emit(phase, architecture, memberRemaps: remaps);
                    var reader = image.Reader;
                    var compilation = ClangSharpSourceCompilation.Create(phase, architecture, remaps,
                        new Dictionary<string, Dictionary<string, string>>(), Array.Empty<string>(),
                        new Dictionary<string, string>(), new Dictionary<string, string>(), new HashSet<string>(),
                        Array.Empty<string>(), new Dictionary<string, string>(), new Dictionary<string, string>()).CSharpCompilation;
                    using var stream = new MemoryStream();
                    var result = compilation.WithAssemblyName("NonfloorLayout" + Guid.NewGuid().ToString("N"))
                        .WithOptions(compilation.Options.WithOutputKind(OutputKind.DynamicallyLinkedLibrary).WithPlatform(Platform.AnyCpu))
                        .Emit(stream);
                    Assert.True(result.Success, string.Join("\n", result.Diagnostics));
                    stream.Position = 0;
                    var context = new AssemblyLoadContext("nonfloor-layout", isCollectible: true);
                    try
                    {
                        var assembly = context.LoadFromStream(stream);
                        foreach (var item in expected)
                        {
                            var physical = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                                .Single(type => reader.GetString(type.Name) == item.Name);
                            string fullName = namespaces[item.Name] + "." + item.Name;
                            Assert.Equal(namespaces[item.Name], reader.GetString(physical.Namespace));
                            Assert.Equal(legacy ? 1 : 0, physical.GetLayout().PackingSize);
                            string[] fieldSignatures = physical.GetFields().Select(reader.GetFieldDefinition).Select(field =>
                                reader.GetString(field.Name) + ":" + field.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null) +
                                ":offset=" + field.GetOffset() + ":attributes=" + string.Join(",", field.GetCustomAttributes()
                                    .Select(handle => Convert.ToHexString(reader.GetBlobBytes(reader.GetCustomAttribute(handle).Value))))).ToArray();
                            if (legacy)
                                legacyFields.Add(item.Name, fieldSignatures);
                            else
                                Assert.Equal(legacyFields[item.Name], fieldSignatures);
                            var managed = assembly.GetType(fullName, throwOnError: true);
                            Assert.Equal(item.Size, Marshal.SizeOf(managed));
                            var alignment = assembly.GetType(namespaces[item.Name] + ".Align_" + item.Name, throwOnError: true);
                            Assert.Equal(1, Marshal.OffsetOf(alignment, "value").ToInt32());
                            foreach (var field in item.Fields)
                                Assert.Equal(field.Item2, Marshal.OffsetOf(managed, field.Item1).ToInt32());
                            observations.Add(new
                            {
                                fullName, architecture, nativeTarget = target, clrHostArchitecture = RuntimeInformation.ProcessArchitecture.ToString(),
                                legacy, physicalPack = physical.GetLayout().PackingSize,
                                size = item.Size, alignment = 1,
                                fields = item.Fields.Select(field => new { name = field.Item1, offset = field.Item2 }).ToArray(),
                                fieldSignatures,
                            });
                        }
                    }
                    finally
                    {
                        context.Unload();
                    }
                }
                string output = Environment.GetEnvironmentVariable("SDK_BULK_NATIVE_OBSERVATIONS");
                Assert.False(string.IsNullOrEmpty(output));
                Directory.CreateDirectory(output);
                File.WriteAllText(Path.Combine(output, "outer-layouts-" + architecture + ".json"),
                    JsonSerializer.Serialize(observations, new JsonSerializerOptions { WriteIndented = true }));
            }
            finally
            {
                if (Directory.Exists(directory))
                    Directory.Delete(directory, recursive: true);
            }
        }

        private static void AssertCount(ParameterSyntax parameter, int expected)
        {
            var attribute = AssertAttribute(parameter, "NativeArrayInfo");
            var count = Assert.Single(attribute.ArgumentList.Arguments.Where(value => value.NameEquals?.Name.Identifier.ValueText == "CountParamIndex"));
            Assert.Equal(expected.ToString(), count.Expression.ToString());
        }

        private static ulong[] Values(EnumDeclarationSyntax declaration)
        {
            var tree = CSharpSyntaxTree.ParseText(declaration.ToFullString());
            var compilation = CSharpCompilation.Create("nonfloor-values", new[] { tree },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) });
            var model = compilation.GetSemanticModel(tree);
            return tree.GetRoot().DescendantNodes().OfType<EnumMemberDeclarationSyntax>()
                .Select(member =>
                {
                    var value = model.GetConstantValue(member.EqualsValue.Value);
                    Assert.True(value.HasValue, member.ToString());
                    return Convert.ToUInt64(value.Value);
                }).ToArray();
        }

        private static string Name(AttributeSyntax attribute) => attribute.Name.ToString().Split('.').Last().Replace("Attribute", "", StringComparison.Ordinal);

        private static IEnumerable<AttributeSyntax> Attributes(SyntaxNode declaration) => declaration.ChildNodes()
            .OfType<AttributeListSyntax>().SelectMany(list => list.Attributes);

        private static AttributeSyntax AssertAttribute(SyntaxNode declaration, string name) => Assert.Single(
            Attributes(declaration).Where(value => Name(value) == name));
    }

    public sealed class NonfloorIdlSourceTheoryAttribute : TheoryAttribute
    {
        public NonfloorIdlSourceTheoryAttribute(params string[] requiredVariables)
        {
            if (requiredVariables.Length == 0)
                requiredVariables = new[] { "SDK_NONFLOOR_GENERATED_ROOT" };
            foreach (string variable in requiredVariables)
                if (Environment.GetEnvironmentVariable(variable) == null)
                    Skip = "Set " + variable + " to the bounded original-IDL validation inputs.";
        }
    }
}
