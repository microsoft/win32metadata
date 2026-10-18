using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class BulkHeaderAnnotationMigrationTests
    {
        [Fact]
        public void DeclarationMapHasNativeIdentitiesAndByteLocationsWithoutGeneratingBindings()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Plain(int value);
namespace Other { int Plain(float value); }
#define DECLARE(name) int name(void);
DECLARE(Expanded)
");
            string path = AddMapOption(fixture);
            byte[] before = File.ReadAllBytes(fixture.Header);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(before, File.ReadAllBytes(fixture.Header));
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "remaps.txt")));
            using var map = JsonDocument.Parse(File.ReadAllText(path));
            Assert.Equal(1, map.RootElement.GetProperty("schemaVersion").GetInt32());
            var declarations = map.RootElement.GetProperty("declarations").EnumerateArray().ToArray();
            var plain = Assert.Single(declarations.Where(row => row.GetProperty("qualifiedName").GetString() == "Plain"));
            var nested = Assert.Single(declarations.Where(row => row.GetProperty("qualifiedName").GetString() == "Other::Plain"));
            Assert.NotEqual(plain.GetProperty("id").GetString(), nested.GetProperty("id").GetString());
            Assert.Equal("CXCursor_FunctionDecl", plain.GetProperty("kind").GetString());
            int offset = plain.GetProperty("offset").GetInt32();
            Assert.Equal("Plain", Encoding.UTF8.GetString(before, offset, 5));
            Assert.True(plain.GetProperty("start").GetInt32() < offset);
            Assert.True(plain.GetProperty("end").GetInt32() > offset);
            Assert.Equal(Convert.ToHexString(SHA256.HashData(before)),
                map.RootElement.GetProperty("files").GetProperty(fixture.Header).GetString());
            Assert.Contains(declarations, row => row.GetProperty("name").GetString() == "Expanded");
        }

        [Fact]
        public void BulkAuthoringPreservesBytesCoversRedeclarationsAndRetainsUnboundFacts()
        {
            using var fixture = new AuthoringFixture(
                "// caf\u00e9\r\nint Unique(void);\r\nint Repeated(void);\r\nint Repeated(void);\r\n" +
                "#if defined(UNSEEN)\r\nint Conditional(void);\r\n#else\r\nint Conditional(int value);\r\n#endif\r\n" +
                "#define DECLARE(name) int name(void);\r\nDECLARE(Macro)\r\n" +
                "int Overloaded(int value);\r\nint Overloaded(float value);\r\n",
                new[] { "Unique", "Repeated", "Conditional", "Macro", "Overloaded" }, new[] { "Unique" });
            byte[] before = File.ReadAllBytes(fixture.Source);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            fixture.RemoveMapOption();
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string[] nativeBefore = Signatures(fixture.Native.ReadSource());
            Assert.NotEmpty(nativeBefore);

            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var counts = report.RootElement.GetProperty("counts");
            Assert.Equal(3, counts.GetProperty("converted").GetInt32());
            Assert.Equal(3, counts.GetProperty("retained").GetInt32());
            Assert.Equal(4, counts.GetProperty("annotations").GetInt32());
            string afterPath = Path.Combine(fixture.Output, "after", "um", "sample.h");
            byte[] after = File.ReadAllBytes(afterPath);
            string afterText = Encoding.UTF8.GetString(after);
            Assert.Equal(3, afterText.Split("_Win32_SupportedOS_Windows7_").Length - 1);
            Assert.Equal(1, afterText.Split("_Win32_SetLastError_").Length - 1);
            string stripped = string.Concat(afterText.Split("\r\n")
                .Where(line => !line.StartsWith("_Win32_", StringComparison.Ordinal)).Select(line => line + "\r\n"));
            Assert.Equal(Encoding.UTF8.GetString(before), stripped.Substring(0, stripped.Length - 2));
            Assert.Equal(before, File.ReadAllBytes(fixture.Source));
            string sidecar = File.ReadAllText(fixture.OSSidecar);
            Assert.DoesNotContain("Unique=", sidecar);
            Assert.DoesNotContain("Repeated=", sidecar);
            foreach (string name in new[] { "Conditional", "Macro", "Overloaded" })
                Assert.Contains(name + "=SupportedOSPlatform(\"windows6.1\")", sidecar);
            Assert.Equal("--with-setlasterror\r\n", File.ReadAllText(fixture.ErrorSidecar));
            Assert.Contains("parse-win32-annotations", File.ReadAllText(fixture.PartitionSettings));
            using var recipe = JsonDocument.Parse(File.ReadAllText(fixture.Recipe));
            Assert.Equal("Sample", Assert.Single(recipe.RootElement.GetProperty("partitions").EnumerateArray()).GetString());
            Assert.Equal("um\\sample.h.patch", Assert.Single(recipe.RootElement.GetProperty("patches").EnumerateArray()).GetString());

            File.WriteAllBytes(fixture.Mirror, after);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(nativeBefore, Signatures(fixture.Native.ReadSource()));
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fixture.Native.ReadSource());
            Assert.Contains("SetLastError = true", fixture.Native.ReadSource());
        }

        [Fact]
        public void StaleDeclarationMapCannotRemoveFactsOrWriteSourcePatches()
        {
            using var fixture = new AuthoringFixture("int Unique(void);\r\n", new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            foreach (string path in new[] { fixture.Source, fixture.Mirror })
                File.AppendAllText(path, "// changed\r\n");
            byte[] recipe = File.ReadAllBytes(fixture.Recipe);
            var result = fixture.Run(apply: true);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Stale parsed source bytes", result.Text);
            Assert.Equal(recipe, File.ReadAllBytes(fixture.Recipe));
            Assert.Contains("Unique=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "generation", "WinSDK", "patches", "um", "sample.h.patch")));
        }

        [Fact]
        public void AutomaticMapExportIncludesTraverseParentDirectoriesForEveryArchitecture()
        {
            using var fixture = new AuthoringFixture("// Native header\r\nint Unique(void);\r\n", new[] { "Unique" }, Array.Empty<string>());
            fixture.EnableAutomaticMapExport();
            var result = fixture.Run(apply: true, exportMaps: true);
            string diagnostics = result.Text + string.Concat(Directory.EnumerateFiles(fixture.Output, "*.log").Select(File.ReadAllText));
            Assert.True(result.ExitCode == 0, diagnostics);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            Assert.Empty(report.RootElement.GetProperty("parseFailures").EnumerateArray());
            Assert.Equal(1, report.RootElement.GetProperty("counts").GetProperty("converted").GetInt32());
            foreach (string architecture in new[] { "x86", "x64", "arm64" })
            {
                string path = Path.Combine(fixture.Output, $"Sample.{architecture}.declarations.json");
                using var map = JsonDocument.Parse(File.ReadAllText(path));
                Assert.Contains(map.RootElement.GetProperty("declarations").EnumerateArray(),
                    declaration => declaration.GetProperty("name").GetString() == "TraverseDependency");
                Assert.Contains("um\\cpdk",
                    File.ReadAllText(Path.Combine(fixture.Output, $"Sample.{architecture}.rsp")));
            }
        }

        [Fact]
        public void SelectedSymbolIndexStillRetainsAdditionalPhysicalDeclarationOwners()
        {
            using var fixture = new AuthoringFixture("// Native owner\r\nint Unique(void);\r\n",
                new[] { "Unique" }, Array.Empty<string>());
            string other = Path.Combine(Path.GetDirectoryName(fixture.Mirror), "other.h");
            File.WriteAllText(other, "int Unique(void);\nint Unselected(void);\n");
            File.AppendAllText(fixture.Native.Header, "#include \"" + other.Replace('\\', '/') + "\"\n");
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal("retained", fact.GetProperty("status").GetString());
            Assert.Equal("additional-declaration-owner", fact.GetProperty("reason").GetString());
            Assert.Equal(0, fact.GetProperty("annotationCount").GetInt32());
            Assert.Contains("Unique=SupportedOSPlatform(\"windows6.1\")", File.ReadAllText(fixture.OSSidecar));
            Assert.Empty(report.RootElement.GetProperty("originals").EnumerateArray());
            Assert.False(File.Exists(Path.Combine(fixture.Root, "generation", "WinSDK", "patches", "um", "sample.h.patch")));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "generation", "WinSDK", "patches", "um", "other.h.patch")));
            fixture.RemoveMapOption();
            File.AppendAllText(Path.Combine(fixture.Native.DirectoryPath, "test.rsp"),
                "--with-attribute\nUnique=SupportedOSPlatform(\"windows6.1\")\n");
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var method = Assert.Single(CSharpSyntaxTree.ParseText(fixture.Native.ReadSource()).GetRoot()
                .DescendantNodes().OfType<MethodDeclarationSyntax>().Where(method => method.Identifier.ValueText == "Unique"));
            Assert.Single(method.AttributeLists.SelectMany(list => list.Attributes)
                .Where(attribute => attribute.Name.ToString().EndsWith("SupportedOSPlatform", StringComparison.Ordinal)));
        }

        [Fact]
        public void UnroutedOwnersCannotRemoveFactsOrCreateParserOptIns()
        {
            using var fixture = new AuthoringFixture("// Native owner\r\nint Unique(void);\r\n",
                new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string path = Path.Combine(fixture.Native.DirectoryPath, "owners.json");
            var inventory = JsonNode.Parse(File.ReadAllText(path));
            inventory["readyOriginalOwners"][0]["partitionCandidates"] = new JsonArray();
            File.WriteAllText(path, inventory.ToJsonString());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal("retained", fact.GetProperty("status").GetString());
            Assert.Equal("no-configured-owning-partition", fact.GetProperty("reason").GetString());
            Assert.Equal(0, fact.GetProperty("annotationCount").GetInt32());
            Assert.Empty(report.RootElement.GetProperty("originals").EnumerateArray());
            Assert.Contains("Unique=SupportedOSPlatform(\"windows6.1\")", File.ReadAllText(fixture.OSSidecar));
            Assert.DoesNotContain("parse-win32-annotations", File.ReadAllText(fixture.PartitionSettings));
        }

        [Theory]
        [InlineData("c", "c17")]
        [InlineData("c++", "c++17")]
        public void ExternCPrefixAnnotationsStayAfterLinkageAndPreserveNativeSignatures(string language, string standard)
        {
            using var fixture = new AuthoringFixture("// Native linkage\r\n#if defined(__cplusplus)\r\n" +
                "#define EXTERN_C extern \"C\"\r\n#else\r\n#define EXTERN_C extern\r\n#endif\r\n" +
                "typedef long HRESULT;\r\n#define DWRITE_EXPORT __stdcall\r\n" +
                "EXTERN_C HRESULT DWRITE_EXPORT Unique(void);\r\n", new[] { "Unique" }, new[] { "Unique" });
            byte[] original = File.ReadAllBytes(fixture.Source);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            fixture.RemoveMapOption();
            File.AppendAllText(Path.Combine(fixture.Native.DirectoryPath, "test.rsp"),
                $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string[] before = Signatures(fixture.Native.ReadSource());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            string after = Path.Combine(fixture.Output, "after", "um", "sample.h");
            string text = File.ReadAllText(after);
            Assert.Contains("EXTERN_C _Win32_SetLastError_ _Win32_SupportedOS_Windows7_ HRESULT DWRITE_EXPORT Unique", text);
            Assert.Equal(original, Encoding.UTF8.GetBytes(text.Replace("_Win32_SetLastError_ ", "")
                .Replace("_Win32_SupportedOS_Windows7_ ", "")));
            File.Copy(after, fixture.Mirror, overwrite: true);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(before, Signatures(fixture.Native.ReadSource()));
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fixture.Native.ReadSource());
            Assert.Contains("SetLastError = true", fixture.Native.ReadSource());
        }

        private static string[] Signatures(string source)
            => CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes().OfType<MethodDeclarationSyntax>()
                .Select(method => method.ReturnType + " " + method.Identifier.ValueText + method.ParameterList)
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();

        private static string AddMapOption(HeaderAnnotationTests.NativeFixture fixture)
        {
            string map = Path.Combine(fixture.DirectoryPath, "declarations.json");
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--declaration-map\n" + map + "\n");
            return map;
        }

        private sealed class AuthoringFixture : IDisposable
        {
            internal AuthoringFixture(string source, string[] supportedOS, string[] errors)
            {
                Native = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", "");
                Root = Path.Combine(Native.DirectoryPath, "repo");
                string sdk = Path.Combine(Root, "generation", "WinSDK");
                Mirror = Path.Combine(sdk, "RecompiledIdlHeaders", "um", "sample.h");
                string package = Path.Combine(Native.DirectoryPath, "package");
                Source = Path.Combine(package, "c", "include", "10.0.26100.0", "um", "sample.h");
                foreach (string path in new[] { Source, Mirror })
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(path));
                    File.WriteAllText(path, source, new UTF8Encoding(false));
                }
                string canonical = Path.Combine(sdk, "RecompiledIdlHeaders", "shared", "win32metadata_annotations.h");
                Directory.CreateDirectory(Path.GetDirectoryName(canonical));
                File.Copy(Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h"), canonical);
                File.AppendAllText(Native.Header, "#include \"" + Mirror.Replace('\\', '/') + "\"\n");
                Map = AddMapOption(Native);
                File.AppendAllText(Path.Combine(Native.DirectoryPath, "test.rsp"), "--traverse\n" + Mirror + "\n");
                OSSidecar = Path.Combine(sdk, "supportedOS.rsp");
                ErrorSidecar = Path.Combine(sdk, "WithSetLastError.rsp");
                File.WriteAllText(OSSidecar, "--with-attribute\r\n" +
                    string.Concat(supportedOS.Select(name => name + "=SupportedOSPlatform(\"windows6.1\")\r\n")));
                File.WriteAllText(ErrorSidecar, "--with-setlasterror\r\n" + string.Concat(errors.Select(name => name + "\r\n")));
                PartitionSettings = Path.Combine(sdk, "Partitions", "Sample", "settings.rsp");
                Directory.CreateDirectory(Path.GetDirectoryName(PartitionSettings));
                File.WriteAllText(PartitionSettings, "--namespace\r\nTest\r\n");
                Recipe = Path.Combine(sdk, "patches", "SdkHeaders.json");
                Directory.CreateDirectory(Path.GetDirectoryName(Recipe));
                File.WriteAllText(Recipe, "{\"schemaVersion\":1,\"sdkPackageVersion\":\"10.0.26100.7705\"," +
                    "\"headers\":[],\"patches\":[],\"partitions\":[]}");
                OwnerMap = Path.Combine(Native.DirectoryPath, "owners.json");
                File.WriteAllText(OwnerMap, JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    snapshot = new { sdkPackageVersion = "10.0.26100.7705", sdkIncludeVersion = "10.0.26100.0", sdkPackageRoot = package },
                    readyOriginalOwners = new[] { new
                    {
                        original = "um\\sample.h", partitionCandidates = new[] { "Sample" },
                        supportedOS = supportedOS.Select(name => new { symbol = name, value = name + "=SupportedOSPlatform(\"windows6.1\")" }),
                        setLastError = errors.Select(name => new { symbol = name, value = name }),
                    } },
                }));
                Script = Path.Combine(Root, "scripts", "Convert-SdkHeaderAnnotations.ps1");
                Directory.CreateDirectory(Path.GetDirectoryName(Script));
                File.Copy(Path.Combine(WinHttpMigrationTests.RepositoryRoot, "scripts", "Convert-SdkHeaderAnnotations.ps1"), Script);
                Output = Path.Combine(Root, "artifacts", "batch");
            }

            internal HeaderAnnotationTests.NativeFixture Native { get; }
            internal string Root { get; }
            internal string Source { get; }
            internal string Mirror { get; }
            internal string OSSidecar { get; }
            internal string ErrorSidecar { get; }
            internal string PartitionSettings { get; }
            internal string Recipe { get; }
            internal string Output { get; }
            private string Map { get; }
            private string OwnerMap { get; }
            private string Script { get; }

            internal void EnableAutomaticMapExport()
            {
                string binaries = Path.Combine(Root, "bin", "Release", "net10.0", "win-x64");
                Directory.CreateDirectory(binaries);
                foreach (string path in Directory.EnumerateFiles(Path.GetDirectoryName(typeof(Win32MetadataScraper.RemapDiscovery).Assembly.Location))
                    .Where(path => Path.GetExtension(path) is ".dll" or ".json"))
                    File.Copy(path, Path.Combine(binaries, Path.GetFileName(path)));
                string assets = Path.Combine(Root, "sources", "GeneratorSdk", "tools", "assets", "scraper");
                Directory.CreateDirectory(assets);
                foreach (string name in new[] { "baseSettings.rsp", "baseSettings.x86.rsp", "baseSettings.x64.rsp", "baseSettings.arm64.rsp" })
                    File.Copy(Path.Combine(WinHttpMigrationTests.RepositoryRoot, "sources", "GeneratorSdk", "tools", "assets", "scraper", name),
                        Path.Combine(assets, name));
                string nested = Path.Combine(Path.GetDirectoryName(Mirror), "cpdk");
                Directory.CreateDirectory(nested);
                File.WriteAllText(Path.Combine(nested, "dependency.h"), "int TraverseDependency(void);\r\n");
                string main = Path.Combine(Path.GetDirectoryName(PartitionSettings), "main.cpp");
                File.WriteAllText(main, "#include <sample.h>\r\n#include <dependency.h>\r\n");
                File.AppendAllText(PartitionSettings, "--traverse\r\n<IncludeRoot>/um/cpdk/dependency.h\r\n<IncludeRoot>/um/sample.h\r\n");
                string toolset = Path.Combine(Root, "toolset");
                Directory.CreateDirectory(toolset);
                File.WriteAllText(Path.Combine(toolset, "vcruntime.h"), "");
            }

            internal void RemoveMapOption()
            {
                string path = Path.Combine(Native.DirectoryPath, "test.rsp");
                File.WriteAllText(path, File.ReadAllText(path).Replace("--declaration-map\n" + Map + "\n", ""));
            }

            internal (int ExitCode, string Text) Run(bool apply, bool exportMaps = false)
            {
                var start = new ProcessStartInfo("pwsh") { UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true };
                foreach (string argument in new[] { "-NoProfile", "-NonInteractive", "-File", Script,
                    "-OwnerMap", OwnerMap, "-Original", "um\\sample.h", "-OutputDirectory", Output })
                    start.ArgumentList.Add(argument);
                foreach (string argument in exportMaps
                    ? new[] { "-Partition", "Sample", "-ToolsetInclude", Path.Combine(Root, "toolset") }
                    : new[] { "-DeclarationMaps", Map })
                    start.ArgumentList.Add(argument);
                if (apply)
                    start.ArgumentList.Add("-Apply");
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                return (process.ExitCode, output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult());
            }

            public void Dispose() => Native.Dispose();
        }
    }
}
