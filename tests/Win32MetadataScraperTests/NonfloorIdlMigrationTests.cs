using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NonfloorIdlMigrationTests
    {
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
        public NonfloorIdlSourceTheoryAttribute()
        {
            if (Environment.GetEnvironmentVariable("SDK_NONFLOOR_GENERATED_ROOT") == null)
                Skip = "Set SDK_NONFLOOR_GENERATED_ROOT to the bounded normal original-IDL scrape outputs.";
        }
    }
}
