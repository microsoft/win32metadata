using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class MmcInterfaceFloorMigrationTests
    {
        private const string TargetFloor = "IComponent|SupportedOSPlatform(\"windows6.0.6000\")";
        private readonly ITestOutputHelper output;

        public MmcInterfaceFloorMigrationTests(ITestOutputHelper output) => this.output = output;

        [MigrationTheory("WINHTTP_PREPARED_HEADERS", "WINHTTP_PRISTINE_PREPARED_HEADERS",
            "WINHTTP_NATIVE_TOOLSET_INCLUDE", "WIN32METADATA_MMC_CORRECTIVE_REPORT")]
        [MemberData(nameof(NativeModes))]
        public void ExactMmcCarrierPreservesPublishedNativeSurfaceAndAllOtherFloors(
            string architecture, string target, bool cInterface, bool enabled)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_MMC_CORRECTIVE_REPORT")));
            var owner = Assert.Single(report.RootElement.GetProperty("owners").EnumerateArray());
            Assert.Equal(@"um\mmc.idl", owner.GetProperty("original").GetString());
            string[] expected = owner.GetProperty("dispositions").EnumerateArray()
                .Where(value => value.GetProperty("disposition").GetString() == "authored-original-idl")
                .Select(value => value.GetProperty("fact").GetProperty("value").GetString().Replace('=', '|'))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(49, expected.Length);
            Assert.Contains(TargetFloor, expected);
            string original = Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string source = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                (cInterface ? "#define CINTERFACE 1\n" : "") +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n#include <mmc.h>\n";
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            string root = WinHttpMigrationTests.RepositoryRoot;
            string[] before = WinHttpNativeControlTests.Surface(root,
                original, "Mmc", architecture,
                target, new[] { "mmc.h" }, "", metadataEnabled: enabled, annotations: beforeAnnotations,
                sourceText: source, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: "c++");
            string[] after = WinHttpNativeControlTests.Surface(root,
                prepared, "Mmc", architecture,
                target, new[] { "mmc.h" }, "", metadataEnabled: enabled, annotations: afterAnnotations,
                sourceText: source, salAnnotations: afterSal, diagnostics: afterDiagnostics, language: "c++");
            Assert.NotEmpty(before);
            string[] normalized = WinHttpNativeControlTests.NormalizeInterfaceCarrierTypedefs(
                before, after, enabled ? new[] { TargetFloor } : Array.Empty<string>());
            Assert.Equal(enabled ? 1 : 0, after.Length - normalized.Length);
            Assert.Equal(before, normalized);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(enabled ? expected.Where(value => value != TargetFloor) : Array.Empty<string>(),
                beforeAnnotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(enabled ? expected : Array.Empty<string>(),
                afterAnnotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{architecture}/CINTERFACE={cInterface}/metadata={enabled}: " +
                "one exact MMC type floor; 44 existing interface and four factory floors, native ABI, SAL and diagnostics preserved.");
        }

        [MigrationTheory("WINHTTP_PREPARED_HEADERS", "WINHTTP_PRISTINE_PREPARED_HEADERS")]
        [InlineData("mmc.h")]
        public void ExactMmcCarrierAddsOnlyItsGuardedTypedefToThePublishedHeader(string header)
        {
            string original = Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string before = Encoding.Latin1.GetString(File.ReadAllBytes(Path.Combine(original, "um", header)));
            string after = Encoding.Latin1.GetString(File.ReadAllBytes(Path.Combine(prepared, "um", header)));
            const string carrier = "#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus)\r\n" +
                "typedef _Win32_SupportedOS_WindowsVista_ struct IComponent IComponent;\r\n#endif\r\n";
            Assert.DoesNotContain(carrier, before);
            Assert.Equal(carrier.Length, after.Length - before.Length);
            Assert.Equal(before, after.Replace(carrier, "", StringComparison.Ordinal));
        }

        public static IEnumerable<object[]> NativeModes()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"), ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (bool cInterface in new[] { false, true })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { architecture.Item1, architecture.Item2, cInterface, enabled };
        }

        [MigrationTheory("WIN32METADATA_MMC_NORMAL_OBJ", "WIN32METADATA_MMC_PUBLISHED_OBJ")]
        [InlineData("common")]
        public void ActualNormalMmcRestoresOnlyTheExactOldTypeFloorAndEnumeratedAnonymousCoordinates(string architecture)
        {
            string positiveObj = Environment.GetEnvironmentVariable("WIN32METADATA_MMC_NORMAL_OBJ");
            string publishedObj = Environment.GetEnvironmentVariable("WIN32METADATA_MMC_PUBLISHED_OBJ");
            var positive = Read(positiveObj);
            var published = Read(publishedObj);
            var target = Component(positive);
            Assert.Equal("Windows.Win32.System.Mmc", Assert.IsType<NamespaceDeclarationSyntax>(target.Parent).Name.ToString());
            var guid = Assert.Single(target.AttributeLists.SelectMany(list => list.Attributes)
                .Where(attribute => attribute.Name.ToString() == "Guid"));
            Assert.Equal("43136EB2-D36C-11CF-ADBC-00AA00A80033", Literal(guid).Token.ValueText);
            Assert.Empty(Component(published).AttributeLists.SelectMany(list => list.Attributes).Where(IsFloor));
            var floor = Assert.Single(target.AttributeLists.SelectMany(list => list.Attributes).Where(IsFloor));
            Assert.Equal("windows6.0.6000", Literal(floor).Token.ValueText);
            Assert.DoesNotContain("IComponent=SupportedOSPlatform(\"windows6.0.6000\")",
                File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                    "generation", "WinSDK", "supportedOS.rsp")));

            var beforeNames = NativeNames(published);
            var afterNames = NativeNames(positive);
            Assert.Equal(beforeNames.Length, afterNames.Length);
            var changes = beforeNames.Zip(afterNames).Where(pair =>
                pair.First.Token.ValueText != pair.Second.Token.ValueText).ToArray();
            var coordinates = new Dictionary<string, string>(StringComparer.Ordinal)
            {
                ["__AnonymousRecord_mmc_L5337_C36"] = "__AnonymousRecord_mmc_L5340_C36",
                ["__AnonymousRecord_mmc_L5360_C5"] = "__AnonymousRecord_mmc_L5363_C5",
                ["__AnonymousRecord_mmc_L6858_C36"] = "__AnonymousRecord_mmc_L6861_C36",
                ["__AnonymousRecord_mmc_L6861_C24"] = "__AnonymousRecord_mmc_L6864_C24",
                ["__AnonymousRecord_mmc_L6866_C24"] = "__AnonymousRecord_mmc_L6869_C24",
            };
            Assert.Equal(coordinates.Keys.OrderBy(value => value, StringComparer.Ordinal),
                changes.Select(pair => pair.First.Token.ValueText).OrderBy(value => value, StringComparer.Ordinal));
            foreach (var pair in changes)
            {
                Assert.Equal(coordinates[pair.First.Token.ValueText], pair.Second.Token.ValueText);
                this.output.WriteLine($"{pair.First.Token.ValueText} -> {pair.Second.Token.ValueText}");
            }
            var originalLiterals = changes.ToDictionary(pair => pair.Second, pair => pair.First);
            var normalized = positive.ReplaceNodes(originalLiterals.Keys,
                (node, rewritten) => originalLiterals[node].WithTriviaFrom(rewritten));
            var floorList = Assert.IsType<AttributeListSyntax>(Assert.Single(
                Component(normalized).AttributeLists.SelectMany(list => list.Attributes).Where(IsFloor)).Parent);
            Assert.Single(floorList.Attributes);
            Assert.True(SyntaxFactory.AreEquivalent(published,
                normalized.RemoveNode(floorList, SyntaxRemoveOptions.KeepNoTrivia)),
                "Only the exact restored MMC floor and the five enumerated three-line anonymous coordinate shifts may differ.");
            foreach (string obj in new[] { positiveObj, publishedObj })
            {
                string settings = File.ReadAllText(Path.Combine(obj, "scratch", architecture, "Mmc.settings.rsp"));
                Assert.Contains("parse-win32-annotations", settings);
                Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
            }
            this.output.WriteLine("MMC IComponent GUID, complete source declarations, values, imports and all other annotations preserved.");

            SyntaxNode Read(string obj) => CSharpSyntaxTree.ParseText(File.ReadAllText(
                Path.Combine(obj, "generated", architecture, "Mmc.cs"))).GetRoot();
            static StructDeclarationSyntax Component(SyntaxNode node) =>
                Assert.Single(node.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(type => type.Identifier.ValueText == "IComponent"));
            static LiteralExpressionSyntax Literal(AttributeSyntax attribute) =>
                Assert.IsType<LiteralExpressionSyntax>(Assert.Single(attribute.ArgumentList.Arguments).Expression);
            static LiteralExpressionSyntax[] NativeNames(SyntaxNode node) =>
                node.DescendantNodes().OfType<AttributeSyntax>()
                    .Where(attribute => attribute.Name.ToString() == "NativeTypeName").Select(Literal).ToArray();
            static bool IsFloor(AttributeSyntax attribute) => attribute.Name.ToString() ==
                "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform";
        }
    }
}
