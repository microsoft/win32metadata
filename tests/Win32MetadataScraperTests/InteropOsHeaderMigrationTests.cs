using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharpSourceToWinmd;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class InteropOsHeaderMigrationTests
    {
        private static readonly string[] Partitions = { "Eap", "Media.DShow.Xml", "Win32_Tile_Badge_Notif", "wnv" };
        private static readonly string[] ProviderExports =
        {
            "RasEapFreeMemory", "RasEapGetIdentity", "RasEapGetInfo", "RasEapInvokeConfigUI", "RasEapInvokeInteractiveUI",
        };
        private readonly ITestOutputHelper output;

        public InteropOsHeaderMigrationTests(ITestOutputHelper output) => this.output = output;

        [HeaderMigrationDataFact]
        public void RelocatedOsFactsHaveNoAuthoredFallback()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "supportedOS.rsp");
            var targets = Partitions.SelectMany(ExpectedFloors).Select(value => value.Split('=')[0]).ToHashSet(StringComparer.Ordinal);
            Assert.DoesNotContain(File.ReadLines(path), line => targets.Contains(line.Split('=')[0]));
        }

        [InteropOsSourceTheory]
        [MemberData(nameof(SourceCases))]
        public void ActualHeaderSourcesPreserveOwnedContracts(string partition, string architecture, string target)
        {
            string controls = Environment.GetEnvironmentVariable("INTEROP_OS_SOURCE_CONTROLS");
            string original = Environment.GetEnvironmentVariable("INTEROP_OS_OLD_GENERATED");
            string[] expectedFloors = ExpectedFloors(partition).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            var cleaned = new Dictionary<string, SyntaxTree>(StringComparer.Ordinal);
            foreach (string phase in new[] { "legacy", "activation", "prepared" })
            {
                string path = Path.Combine(controls, phase, "obj", "generated", architecture, partition + ".cs");
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path), path: path);
                Assert.Empty(tree.GetDiagnostics().Where(value => value.Severity == DiagnosticSeverity.Error));
                Assert.Equal(expectedFloors, Floors(tree));
                if (partition == "Eap")
                {
                    foreach (string provider in ProviderExports)
                    {
                        var method = Assert.Single(tree.GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>()
                            .Where(value => value.Identifier.ValueText == provider));
                        var import = Assert.Single(method.AttributeLists.SelectMany(list => list.Attributes)
                            .Where(value => value.Name.ToString() == "DllImport"));
                        Assert.Equal(string.Empty, Assert.IsType<LiteralExpressionSyntax>(import.ArgumentList.Arguments[0].Expression).Token.ValueText);
                    }
                }
                cleaned.Add(phase, Clean(tree));
                Assert.DoesNotContain("CountFieldName", cleaned[phase].ToString());
            }

            var originalTree = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(original, "common", partition + ".cs")));
            Assert.Equal(expectedFloors, Floors(originalTree));
            var old = Clean(originalTree);
            Assert.Equal(DeclarationTokens(old), DeclarationTokens(cleaned["legacy"]));
            Assert.Equal(DeclarationTokens(cleaned["legacy"]), DeclarationTokens(cleaned["activation"]));
            string expected = Declarations(cleaned["activation"]);
            if (partition == "wnv")
            {
                foreach (var shift in new[]
                {
                    (Owner: "WNV_IP_ADDRESS", Field: "IP", Before: "__AnonymousRecord_wnvapi_L64_C5", After: "__AnonymousRecord_wnvapi_L65_C5"),
                    (Owner: "WNV_OBJECT_CHANGE_PARAM", Field: "ObjectParam", Before: "__AnonymousRecord_wnvapi_L97_C5", After: "__AnonymousRecord_wnvapi_L98_C5"),
                })
                {
                    Assert.Equal(shift.Before, NativeFieldName(cleaned["activation"], shift.Owner, shift.Field));
                    Assert.Equal(shift.After, NativeFieldName(cleaned["prepared"], shift.Owner, shift.Field));
                    expected = expected.Replace("\"" + shift.Before + "\"", "\"" + shift.After + "\"", StringComparison.Ordinal);
                    this.output.WriteLine($"{partition}/{architecture}: {shift.Owner}.{shift.Field} NativeTypeName {shift.Before} -> {shift.After} (source coordinates only).");
                }
            }
            Assert.Equal(Tokens(expected), DeclarationTokens(cleaned["prepared"]));

            string[] emittedFloors = partition == "Eap" ? new[] { "IEAPProviderConfig=windows5.0" } : expectedFloors;
            Assert.Equal(emittedFloors, Floors(cleaned["prepared"]));
            if (partition == "Eap")
            {
                var methods = cleaned["prepared"].GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>();
                Assert.DoesNotContain(methods, method => ProviderExports.Contains(method.Identifier.ValueText, StringComparer.Ordinal));
            }
            this.output.WriteLine($"{partition}/{architecture} ({target}): original OLD = matched legacy = parser activation = prepared cleaned declarations, except the two explicitly checked WNV source-coordinate strings; exact OS targets/payloads preserved.");
        }

        [NativeMigrationTheory]
        [MemberData(nameof(NativeCases))]
        public void MetadataDisabledOwnersAndDirectDependentPreserveNativeAbi(string partition, string architecture, string target)
            => new WinHttpNativeControlTests(this.output).AdditionalPreparedPartitionsKeepOrdinaryNativeAbi(partition, architecture, target);

        public static IEnumerable<object[]> SourceCases() => Cases(Partitions);

        public static IEnumerable<object[]> NativeCases() => Cases(Partitions.Concat(new[] { "Media.DShow" }));

        private static IEnumerable<object[]> Cases(IEnumerable<string> partitions)
        {
            foreach (string partition in partitions)
            {
                yield return new object[] { partition, "x86", "i686-pc-windows-msvc" };
                yield return new object[] { partition, "x64", "x86_64-pc-windows-msvc" };
                yield return new object[] { partition, "arm64", "aarch64-pc-windows-msvc" };
            }
        }

        private static IEnumerable<string> ExpectedFloors(string partition) => partition switch
        {
            "Eap" => ProviderExports.Concat(new[] { "IEAPProviderConfig" }).Select(name => name + "=windows5.0"),
            "Media.DShow.Xml" => new[] { "IXMLGraphBuilder=windows5.0" },
            "Win32_Tile_Badge_Notif" => new[] { "INotificationActivationCallback=windows10.0.10240" },
            "wnv" => new[] { "WnvOpen=windowsserver2012", "WnvRequestNotification=windowsserver2012" },
            _ => throw new ArgumentException("Unknown interop OS owner.", nameof(partition)),
        };

        private static string[] Floors(SyntaxTree tree) => tree.GetRoot().DescendantNodes().OfType<AttributeSyntax>()
            .Where(attribute => attribute.Name.ToString().EndsWith("SupportedOSPlatform", StringComparison.Ordinal))
            .Select(attribute =>
            {
                var list = Assert.IsType<AttributeListSyntax>(attribute.Parent);
                Assert.Null(list.Target);
                string owner = list.Parent switch
                {
                    BaseTypeDeclarationSyntax type => type.Identifier.ValueText,
                    MethodDeclarationSyntax method => method.Identifier.ValueText,
                    _ => throw new InvalidOperationException("Unexpected OS attribute target: " + list.Parent.Kind()),
                };
                var value = Assert.IsType<LiteralExpressionSyntax>(Assert.Single(attribute.ArgumentList.Arguments).Expression);
                return owner + "=" + value.Token.ValueText;
            }).OrderBy(value => value, StringComparer.Ordinal).ToArray();

        private static string NativeFieldName(SyntaxTree tree, string owner, string field)
        {
            var declaration = tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()
                .Single(type => type.Identifier.ValueText == owner).Members.OfType<FieldDeclarationSyntax>()
                .Single(value => value.Declaration.Variables.Single().Identifier.ValueText == field);
            var attribute = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes)
                .Where(value => value.Name.ToString() == "NativeTypeName"));
            return Assert.IsType<LiteralExpressionSyntax>(Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
        }

        private static SyntaxTree Clean(SyntaxTree tree) => MetadataSyntaxTreeCleaner.CleanSyntaxTree(tree,
            new Dictionary<string, string>(), new Dictionary<string, Dictionary<string, string>>(), new HashSet<string>(),
            new Dictionary<string, string>(), new Dictionary<string, string>(), new Dictionary<string, string>(),
            new HashSet<string>(), new HashSet<string>(), tree.FilePath);

        private static string Declarations(SyntaxTree tree) => tree.GetRoot().DescendantNodes().OfType<NamespaceDeclarationSyntax>()
            .Single().ToFullString().Replace("global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform", "SupportedOSPlatform", StringComparison.Ordinal);

        private static string[] DeclarationTokens(SyntaxTree tree) => Tokens(Declarations(tree));

        private static string[] Tokens(string source) => CSharpSyntaxTree.ParseText(source).GetRoot().DescendantTokens()
            .Select(token => token.Text).ToArray();
    }

    public sealed class InteropOsSourceTheoryAttribute : HeaderMigrationDataTheoryAttribute
    {
        public InteropOsSourceTheoryAttribute()
        {
            if (Skip != null)
                return;
            if (Environment.GetEnvironmentVariable("INTEROP_OS_SOURCE_CONTROLS") == null ||
                Environment.GetEnvironmentVariable("INTEROP_OS_OLD_GENERATED") == null)
                Skip = "Set INTEROP_OS_SOURCE_CONTROLS and INTEROP_OS_OLD_GENERATED to the bounded actual-header controls.";
        }
    }
}
