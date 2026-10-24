using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Text.RegularExpressions;
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
        public void DeclarationMapSymbolSelectionRequiresAnOutputMap()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", "void Selected(int value);");
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--declaration-map-symbol\nSelected\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("--declaration-map-symbol requires --declaration-map", fixture.Diagnostics);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SelectedDeclarationMapBindsNamedAndUnnamedParametersAndRecordFields(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef struct Record { unsigned flags; short mode; } RecordAlias;
void Selected(unsigned flags, unsigned);
namespace Other { void Selected(float flags); }
void Unrelated(unsigned flags);
");
            string path = AddMapOption(fixture);
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--declaration-map-symbol\nRecord\nRecordAlias\nSelected\n");
            byte[] before = File.ReadAllBytes(fixture.Header);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(before, File.ReadAllBytes(fixture.Header));
            Assert.False(File.Exists(fixture.Output));
            using var map = JsonDocument.Parse(File.ReadAllText(path));
            var declarations = map.RootElement.GetProperty("declarations").EnumerateArray().ToArray();
            Assert.DoesNotContain(declarations, row => row.GetProperty("qualifiedName").GetString().Contains("Unrelated", StringComparison.Ordinal));
            var function = Assert.Single(declarations.Where(row => row.GetProperty("kind").GetString() == "CXCursor_FunctionDecl" &&
                row.GetProperty("qualifiedName").GetString() == "Selected"));
            var parameters = declarations.Where(row => row.GetProperty("kind").GetString() == "CXCursor_ParmDecl" &&
                row.GetProperty("parentId").GetString() == function.GetProperty("id").GetString()).ToArray();
            Assert.Equal(new[] { 0, 1 }, parameters.Select(row => row.GetProperty("parameterIndex").GetInt32()));
            Assert.Equal(new[] { "flags", "" }, parameters.Select(row => row.GetProperty("name").GetString()));
            var field = Assert.Single(declarations.Where(row => row.GetProperty("qualifiedName").GetString() == "Record::mode"));
            Assert.Equal("CXCursor_FieldDecl", field.GetProperty("kind").GetString());
            Assert.Equal("Record", field.GetProperty("parentQualifiedName").GetString());
            Assert.Equal("mode", Encoding.UTF8.GetString(before, field.GetProperty("spellingOffset").GetInt32(), 4));
            var aliases = declarations.Where(row => row.GetProperty("kind").GetString() == "CXCursor_TypedefDecl" &&
                row.GetProperty("name").GetString() == "RecordAlias").ToArray();
            Assert.NotEmpty(aliases);
            Assert.All(aliases, alias => Assert.Equal(field.GetProperty("parentId").GetString(),
                alias.GetProperty("typeDeclarationId").GetString()));
            Assert.Contains(declarations, row => row.GetProperty("qualifiedName").GetString() == "Other::Selected::flags");
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
            Assert.Equal(Encoding.UTF8.GetString(before), stripped.Substring(0, stripped.Length - 2)
                .Replace("#include <sal.h>\r\n", ""));
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

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void StaleDeclarationMapCannotRemoveFactsOrWriteSourcePatches(bool record)
        {
            using var fixture = new AuthoringFixture(record ? "struct Unique { int value; };\r\n" : "int Unique(void);\r\n",
                new[] { "Unique" }, Array.Empty<string>());
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

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CumulativeNativePatchesPreservePriorFactsAndBindReturnMacros(string architecture, string target)
        {
            const string original = "// caf\u00e9\r\nint Earlier(void);\r\n" +
                "#define _Check_return_\r\n#define WINOLEAPI extern \"C\" __declspec(dllimport) long __stdcall\r\n" +
                "#define COMBASEAPI extern \"C\" __declspec(dllimport) long __stdcall\r\n" +
                "#define PSSTDAPI extern \"C\" __declspec(dllimport) long __stdcall\r\n" +
                "#define PSSTDAPI_(type) extern \"C\" __declspec(dllimport) type __stdcall\r\n" +
                "_Check_return_ WINOLEAPI\r\nUnique(void);\r\nCOMBASEAPI Another(void);\r\n" +
                "_Check_return_ PSSTDAPI Property(void);\r\nPSSTDAPI_(unsigned int) PropertyCount(void);\r\n";
            using var fixture = new AuthoringFixture(original, new[] { "Unique", "Another", "Property", "PropertyCount" },
                new[] { "Unique" }, architecture, target);
            string cumulative = original.Replace("int Earlier", "_Win32_PreserveResult_\r\nint Earlier");
            fixture.InstallExistingPatch(cumulative);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            fixture.RemoveMapOption();
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string[] native = Signatures(fixture.Native.ReadSource());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            Assert.Equal(5, report.RootElement.GetProperty("counts").GetProperty("converted").GetInt32());
            Assert.Equal(0, report.RootElement.GetProperty("counts").GetProperty("retained").GetInt32());
            Assert.False(string.IsNullOrEmpty(Assert.Single(report.RootElement.GetProperty("sourceBindings").EnumerateArray())
                .GetProperty("existingPatchSha256").GetString()));
            string after = File.ReadAllText(Path.Combine(fixture.Output, "after", "um", "sample.h"));
            Assert.Contains("_Win32_PreserveResult_\r\nint Earlier", after);
            Assert.Contains("WINOLEAPI\r\n_Win32_SetLastError_ _Win32_SupportedOS_Windows7_ Unique", after);
            Assert.Contains("COMBASEAPI _Win32_SupportedOS_Windows7_ Another", after);
            Assert.Contains("_Check_return_ PSSTDAPI _Win32_SupportedOS_Windows7_ Property", after);
            Assert.Contains("PSSTDAPI_(unsigned int) _Win32_SupportedOS_Windows7_ PropertyCount", after);
            Assert.Equal(cumulative, after.Replace("#include <sal.h>\r\n", "")
                .Replace("_Win32_SetLastError_ ", "").Replace("_Win32_SupportedOS_Windows7_ ", ""));
            using var recipe = JsonDocument.Parse(File.ReadAllText(fixture.Recipe));
            Assert.Single(recipe.RootElement.GetProperty("headers").EnumerateArray());
            Assert.Single(recipe.RootElement.GetProperty("patches").EnumerateArray());
            File.WriteAllText(fixture.Mirror, after, new UTF8Encoding(false));
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(native, Signatures(fixture.Native.ReadSource()));
            Assert.Contains("PreserveSig", fixture.Native.ReadSource());
            Assert.Equal(4, fixture.Native.ReadSource().Split("SupportedOSPlatform(\"windows6.1\")").Length - 1);
            Assert.Contains("SetLastError = true", fixture.Native.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void VoidWinapiRequiresTheActualNativeVoidReturn(string architecture, string target, bool nativeVoid)
        {
            string original = "int Earlier(void);\r\n#define VOID " + (nativeVoid ? "void" : "int") +
                "\r\n#define WINAPI __stdcall\r\nVOID\r\nWINAPI\r\nUnique(void);\r\n";
            using var fixture = new AuthoringFixture(original, new[] { "Unique" }, Array.Empty<string>(), architecture, target);
            string cumulative = original.Replace("int Earlier", "_Win32_PreserveResult_\r\nint Earlier");
            fixture.InstallExistingPatch(cumulative);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            fixture.RemoveMapOption();
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string[] native = Signatures(fixture.Native.ReadSource());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal(nativeVoid ? "converted" : "retained", fact.GetProperty("status").GetString());
            if (!nativeVoid)
            {
                Assert.Equal("unsupported-function-declaration-macro", fact.GetProperty("reason").GetString());
                Assert.Contains("Unique=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
                return;
            }
            string after = File.ReadAllText(Path.Combine(fixture.Output, "after", "um", "sample.h"));
            Assert.Contains("_Win32_SupportedOS_Windows7_\r\nVOID\r\nWINAPI\r\nUnique", after);
            Assert.Equal(cumulative, after.Replace("#include <sal.h>\r\n", "")
                .Replace("_Win32_SupportedOS_Windows7_\r\n", ""));
            File.WriteAllText(fixture.Mirror, after, new UTF8Encoding(false));
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(native, Signatures(fixture.Native.ReadSource()));
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fixture.Native.ReadSource());
        }

        [Theory]
        [InlineData("stale-map")]
        [InlineData("changed-declaration")]
        [InlineData("unadmitted-patch")]
        [InlineData("stale-pin")]
        [InlineData("wrong-patch-base")]
        [InlineData("trailing-whitespace")]
        public void CumulativeAuthoringRejectsUnverifiedInputsWithoutRetiringFacts(string failure)
        {
            const string original = "// Native\r\nint Earlier(void);\r\nint Unique(void);\r\n";
            using var fixture = new AuthoringFixture(original, new[] { "Unique" }, Array.Empty<string>());
            string cumulative = original.Replace("int Earlier", "_Win32_PreserveResult_\r\nint Earlier");
            if (failure == "changed-declaration")
                cumulative = cumulative.Replace("int Unique", "long Unique");
            if (failure == "trailing-whitespace")
                cumulative += "// invalid trailing spaces   \r\n";
            fixture.InstallExistingPatch(cumulative);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            if (failure == "stale-map")
            {
                var map = JsonNode.Parse(File.ReadAllText(fixture.Map));
                foreach (string path in map["files"].AsObject().Select(pair => pair.Key).ToArray())
                    map["files"][path] = new string('0', 64);
                File.WriteAllText(fixture.Map, map.ToJsonString());
            }
            if (failure is "unadmitted-patch" or "stale-pin")
            {
                var recipe = JsonNode.Parse(File.ReadAllText(fixture.Recipe));
                if (failure == "unadmitted-patch")
                    recipe["patches"] = new JsonArray();
                else
                    recipe["headers"][0]["sdkSha256"] = new string('0', 64);
                File.WriteAllText(fixture.Recipe, recipe.ToJsonString());
            }
            if (failure == "wrong-patch-base")
                File.WriteAllText(fixture.ExistingPatch, File.ReadAllText(fixture.ExistingPatch).Replace("int Earlier", "int Missing"));
            byte[] recipeBefore = File.ReadAllBytes(fixture.Recipe);
            byte[] patchBefore = File.ReadAllBytes(fixture.ExistingPatch);
            var result = fixture.Run(apply: true);
            if (failure == "changed-declaration")
            {
                Assert.True(result.ExitCode == 0, result.Text);
                using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
                var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
                Assert.Equal("native-declaration-span-changed-by-existing-patch", fact.GetProperty("reason").GetString());
                Assert.Equal("retained", fact.GetProperty("status").GetString());
            }
            else
            {
                Assert.NotEqual(0, result.ExitCode);
                Assert.Equal(recipeBefore, File.ReadAllBytes(fixture.Recipe));
            }
            Assert.Equal(patchBefore, File.ReadAllBytes(fixture.ExistingPatch));
            Assert.Contains("Unique=SupportedOSPlatform(\"windows6.1\")", File.ReadAllText(fixture.OSSidecar));
        }

        [Theory]
        [InlineData("DECLARE(Unique)\r\n")]
        [InlineData("UNKNOWNAPI Unique(void);\r\n")]
        [InlineData("PSSTDAPI_UNKNOWN Unique(void);\r\n")]
        public void UnknownFunctionMacroExpansionsRemainLegacy(string declaration)
        {
            using var fixture = new AuthoringFixture(
                "#define DECLARE(name) int name(void);\r\n#define UNKNOWNAPI extern \"C\" int\r\n" +
                "#define PSSTDAPI_UNKNOWN extern \"C\" int\r\n" + declaration,
                new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            Assert.Equal("retained", Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray())
                .GetProperty("status").GetString());
            Assert.Contains("Unique=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
        }

        [Fact]
        public void AuthoredHeaderBootstrapsSalInAFreshMidlImportContext()
        {
            using var fixture = new AuthoringFixture("int Unique(void);\r\n", new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            File.Copy(Path.Combine(fixture.Output, "after", "um", "sample.h"), fixture.Mirror, overwrite: true);
            fixture.RemoveMapOption();
            File.WriteAllText(fixture.Native.Header, "#include \"" + fixture.Mirror.Replace('\\', '/') + "\"\n");
            string settings = Path.Combine(fixture.Native.DirectoryPath, "test.rsp");
            File.WriteAllText(settings, File.ReadAllText(settings).Replace("parse-win32-annotations", "") +
                "--language\nc\n--std\nc17\n--additional=-DMIDL_PASS\n");
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Contains("Unique", fixture.Native.ReadSource());
            Assert.DoesNotContain("SupportedOSPlatform", fixture.Native.ReadSource());
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

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void UnroutedOwnersCannotRemoveFactsOrCreateParserOptIns(bool record)
        {
            using var fixture = new AuthoringFixture("// Native owner\r\n" +
                (record ? "struct Unique { int value; };\r\n" : "int Unique(void);\r\n"),
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
                .Replace("_Win32_SupportedOS_Windows7_ ", "").Replace("#include <sal.h>\r\n", "")));
            File.Copy(after, fixture.Mirror, overwrite: true);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(before, Signatures(fixture.Native.ReadSource()));
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fixture.Native.ReadSource());
            Assert.Contains("SetLastError = true", fixture.Native.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void MacroRecordAvailabilityUsesTypedIdentityTransportWithoutChangingNativeDeclarations(string architecture, string target)
        {
            const string source = @"// Original native interfaces
#define interface struct
#if defined(__cplusplus)
#define DX_DECLARE_INTERFACE(iid) __declspec(uuid(iid))
#define DWRITE_DECLARE_INTERFACE(iid) __declspec(uuid(iid)) __declspec(novtable)
#else
#define DX_DECLARE_INTERFACE(iid)
#define DWRITE_DECLARE_INTERFACE(iid)
#endif
#if defined(__cplusplus) && !defined(CINTERFACE)
struct IBase { virtual int Base(void) = 0; };
#define DECLARE_INTERFACE_(name, base) struct name : public base
#define DECLARE_INTERFACE_IID_(name, base, iid) struct __declspec(uuid(iid)) name : public base
#define METHOD(name) virtual int name(void) = 0
#else
struct IBase { void **lpVtbl; };
#define DECLARE_INTERFACE_(name, base) typedef struct name name; struct name
#define DECLARE_INTERFACE_IID_(name, base, iid) DECLARE_INTERFACE_(name, base)
#define METHOD(name) void *name
#endif
#define DECLARE_MAPI_INTERFACE_(name, base) DECLARE_INTERFACE_(name, base)
#if defined(__cplusplus)
#define DECLARE_MAPI_INTERFACE_PTR(name, pointer) interface name; typedef name *pointer
#else
#define DECLARE_MAPI_INTERFACE_PTR(name, pointer) typedef interface name name, *pointer
#endif
DECLARE_INTERFACE_(IRichEditOleCallback, IBase) { METHOD(Edit); };
DECLARE_INTERFACE_IID_(IDiskQuotaControl, IBase, ""7988B572-EC89-11cf-9C00-00AA00A14F56"") { METHOD(Quota); };
interface DX_DECLARE_INTERFACE(""0359dc30-95e6-4568-9055-27720d130e93"") ID2D1AnalysisTransform { METHOD(Analyze); };
interface DWRITE_DECLARE_INTERFACE(""9A1B41C3-D3BB-466A-87FC-FE67556A3B65"") IDWriteFactory3 { METHOD(Write); };
DECLARE_MAPI_INTERFACE_(IAddrBook, IBase) { METHOD(Address); };
DECLARE_MAPI_INTERFACE_PTR(IAddrBook, LPADRBOOK);
";
            string[] names = { "IRichEditOleCallback", "IDiskQuotaControl", "ID2D1AnalysisTransform", "IAddrBook", "IDWriteFactory3" };
            using var fixture = new AuthoringFixture(source.ReplaceLineEndings("\r\n") + "\r\n",
                names, Array.Empty<string>(), architecture, target);
            byte[] original = File.ReadAllBytes(fixture.Source);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            using (var map = JsonDocument.Parse(File.ReadAllText(fixture.Map)))
            {
                Assert.Contains(map.RootElement.GetProperty("declarationKinds").EnumerateArray(),
                    kind => kind.GetString() == "CXCursor_StructDecl");
                foreach (string name in names)
                {
                    var definition = Assert.Single(map.RootElement.GetProperty("declarations").EnumerateArray()
                        .Where(declaration => declaration.GetProperty("name").GetString() == name &&
                            declaration.GetProperty("isDefinition").GetBoolean()));
                    Assert.Equal("c:@S@" + name, definition.GetProperty("id").GetString());
                    Assert.Equal(name, Encoding.UTF8.GetString(original,
                        definition.GetProperty("spellingOffset").GetInt32(), name.Length));
                }
            }
            fixture.RemoveMapOption();
            string settings = Path.Combine(fixture.Native.DirectoryPath, "test.rsp");
            string enabled = File.ReadAllText(settings);
            string disabled = enabled.Replace("parse-win32-annotations", "");
            File.WriteAllText(settings, disabled);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            string nativeBefore = fixture.Native.ReadSource();
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            Assert.Equal(5, report.RootElement.GetProperty("counts").GetProperty("converted").GetInt32());
            Assert.Equal(0, report.RootElement.GetProperty("counts").GetProperty("retained").GetInt32());
            string after = Path.Combine(fixture.Output, "after", "um", "sample.h");
            string afterText = File.ReadAllText(after);
            string stripped = afterText;
            foreach (string name in names)
            {
                string transport = "#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus)\r\n" +
                    $"typedef _Win32_SupportedOS_Windows7_ struct {name} {name};\r\n#endif\r\n";
                Assert.Contains(transport, afterText);
                stripped = stripped.Replace(transport, "");
            }
            Assert.Equal(original, Encoding.UTF8.GetBytes(stripped.Replace("#include <sal.h>\r\n", "")));
            File.Copy(after, fixture.Mirror, overwrite: true);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.Equal(nativeBefore, fixture.Native.ReadSource());
            foreach (string mode in new[] { "", "--additional=-DCINTERFACE\n" })
            {
                File.WriteAllText(settings, enabled + mode);
                Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
                var types = CSharpSyntaxTree.ParseText(fixture.Native.ReadSource()).GetRoot()
                    .DescendantNodes().OfType<TypeDeclarationSyntax>().ToArray();
                foreach (string name in names)
                {
                    var type = Assert.Single(types.Where(type => type.Identifier.ValueText == name));
                    var attribute = Assert.Single(type.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(attribute => attribute.Name.ToString().EndsWith("SupportedOSPlatform", StringComparison.Ordinal)));
                    Assert.Equal("\"windows6.1\"", Assert.Single(attribute.ArgumentList.Arguments).Expression.ToString());
                }
            }
            foreach (string mode in new[] { "--language\nc\n--std\nc17\n", "--additional=-DCINTERFACE\n" })
            {
                File.WriteAllText(settings, disabled + mode);
                File.WriteAllBytes(fixture.Mirror, original);
                Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
                nativeBefore = fixture.Native.ReadSource();
                File.Copy(after, fixture.Mirror, overwrite: true);
                Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
                Assert.Equal(nativeBefore, fixture.Native.ReadSource());
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void MapiPointerReferencesRequireTheParsedRecordIdentity(bool omitReference)
        {
            using var fixture = new AuthoringFixture(
                "#define DECLARE_MAPI_INTERFACE_(name, base) struct name\r\n" +
                "#define DECLARE_MAPI_INTERFACE_PTR(name, pointer) struct name; typedef name *pointer\r\n" +
                "DECLARE_MAPI_INTERFACE_(Unique, IBase) { int value; };\r\n" +
                "DECLARE_MAPI_INTERFACE_PTR(Unique, LPUNIQUE);\r\n",
                new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var map = JsonNode.Parse(File.ReadAllText(fixture.Map));
            var declarations = map["declarations"].AsArray();
            var reference = Assert.Single(declarations.Where(declaration =>
                declaration["name"].GetValue<string>() == "Unique" &&
                !declaration["isDefinition"].GetValue<bool>()));
            if (omitReference)
                declarations.Remove(reference);
            else
                reference["id"] = "c:@S@AnotherRecord";
            File.WriteAllText(fixture.Map, map.ToJsonString());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal("incomplete-record-source-coverage", fact.GetProperty("reason").GetString());
            Assert.Equal(0, fact.GetProperty("annotationCount").GetInt32());
            Assert.Empty(report.RootElement.GetProperty("originals").EnumerateArray());
            Assert.Contains("Unique=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
        }

        [Fact]
        public void ClassAvailabilityTransportKeepsTheNativeTagKind()
        {
            using var fixture = new AuthoringFixture("// Native class\r\nclass Unique { public: int value; };\r\n",
                new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            string after = Path.Combine(fixture.Output, "after", "um", "sample.h");
            Assert.Contains("typedef _Win32_SupportedOS_Windows7_ class Unique Unique;", File.ReadAllText(after));
            fixture.RemoveMapOption();
            File.Copy(after, fixture.Mirror, overwrite: true);
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            Assert.DoesNotContain("mismatched", fixture.Native.Diagnostics, StringComparison.OrdinalIgnoreCase);
            var type = Assert.Single(CSharpSyntaxTree.ParseText(fixture.Native.ReadSource()).GetRoot()
                .DescendantNodes().OfType<TypeDeclarationSyntax>().Where(type => type.Identifier.ValueText == "Unique"));
            Assert.Single(type.AttributeLists.SelectMany(list => list.Attributes)
                .Where(attribute => attribute.Name.ToString().EndsWith("SupportedOSPlatform", StringComparison.Ordinal)));
        }

        [Fact]
        public void RecordAuthoringRetainsConditionalUnknownMacroNestedAndLastErrorFacts()
        {
            using var fixture = new AuthoringFixture("// Native records\r\n" +
                "struct Unique { int value; };\r\n" +
                "#if defined(UNSEEN)\r\nstruct Conditional { int first; };\r\n" +
                "#else\r\nstruct Conditional { int second; };\r\n#endif\r\n" +
                "#define UNKNOWN_RECORD(name) struct name\r\nUNKNOWN_RECORD(Unknown) { int value; };\r\n" +
                "#if defined(UNSEEN)\r\nUNKNOWN_RECORD(Hidden) { int first; };\r\n" +
                "#else\r\nstruct Hidden { int second; };\r\n#endif\r\n" +
                "#if defined(UNSEEN)\r\nstruct UNKNOWN_UUID(\"unused\") HiddenPrefix { int first; };\r\n" +
                "#else\r\nstruct HiddenPrefix { int second; };\r\n#endif\r\n" +
                "#define DECLARE_MAPI_INTERFACE_PTR(name, pointer) struct name; typedef name *pointer\r\n" +
                "struct HiddenPointer { int value; };\r\n" +
                "#if defined(UNSEEN)\r\nDECLARE_MAPI_INTERFACE_PTR(HiddenPointer, LPHIDDEN);\r\n#endif\r\n" +
                "namespace Other { struct Nested { int value; }; }\r\n",
                new[] { "Unique", "Conditional", "Unknown", "Hidden", "HiddenPrefix", "HiddenPointer", "Nested" }, new[] { "Unique" });
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            Assert.Equal(1, report.RootElement.GetProperty("counts").GetProperty("converted").GetInt32());
            Assert.Equal(7, report.RootElement.GetProperty("counts").GetProperty("retained").GetInt32());
            Assert.Equal(1, report.RootElement.GetProperty("counts").GetProperty("annotations").GetInt32());
            Assert.Contains("Unique\r\n", File.ReadAllText(fixture.ErrorSidecar));
            foreach (string name in new[] { "Conditional", "Unknown", "Hidden", "HiddenPrefix", "HiddenPointer", "Nested" })
                Assert.Contains(name + "=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
        }

        [Fact]
        public void RecordDefinitionsInAnotherPhysicalOwnerRemainEntirelyLegacy()
        {
            using var fixture = new AuthoringFixture("// Native record\r\nstruct Unique { int value; };\r\n",
                new[] { "Unique" }, Array.Empty<string>());
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var first = JsonNode.Parse(File.ReadAllText(fixture.Map));
            string other = Path.Combine(Path.GetDirectoryName(fixture.Mirror), "other.h");
            File.Copy(fixture.Mirror, other);
            File.WriteAllText(fixture.Native.Header, File.ReadAllText(fixture.Native.Header)
                .Replace(fixture.Mirror.Replace('\\', '/'), other.Replace('\\', '/')));
            Assert.True(fixture.Native.Run() == 0, fixture.Native.Diagnostics);
            var second = JsonNode.Parse(File.ReadAllText(fixture.Map));
            foreach (var declaration in second["declarations"].AsArray())
                first["declarations"].AsArray().Add(declaration.DeepClone());
            foreach (var file in second["files"].AsObject())
                first["files"][file.Key] = file.Value.DeepClone();
            File.WriteAllText(fixture.Map, first.ToJsonString());
            var result = fixture.Run(apply: true);
            Assert.True(result.ExitCode == 0, result.Text);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(fixture.Output, "report.json")));
            var fact = Assert.Single(report.RootElement.GetProperty("facts").EnumerateArray());
            Assert.Equal("additional-declaration-owner", fact.GetProperty("reason").GetString());
            Assert.Equal(0, fact.GetProperty("annotationCount").GetInt32());
            Assert.Empty(report.RootElement.GetProperty("originals").EnumerateArray());
            Assert.Contains("Unique=SupportedOSPlatform", File.ReadAllText(fixture.OSSidecar));
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
            internal AuthoringFixture(string source, string[] supportedOS, string[] errors,
                string architecture = "x64", string target = "x86_64-pc-windows-msvc")
            {
                Native = new HeaderAnnotationTests.NativeFixture(architecture, target, "");
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
            internal string Map { get; }
            internal string ExistingPatch => Path.Combine(Root, "generation", "WinSDK", "patches", "um", "sample.h.patch");
            private string OwnerMap { get; }
            private string Script { get; }

            internal void InstallExistingPatch(string cumulative)
            {
                string before = Path.Combine(Native.DirectoryPath, "pristine.h");
                string after = Path.Combine(Native.DirectoryPath, "cumulative.h");
                File.Copy(Source, before);
                File.WriteAllText(after, cumulative, new UTF8Encoding(false));
                Directory.CreateDirectory(Path.GetDirectoryName(ExistingPatch));
                var start = new ProcessStartInfo("git") { UseShellExecute = false, RedirectStandardError = true };
                foreach (string argument in new[] { "-c", "core.autocrlf=false", "diff", "--no-index",
                    "--no-ext-diff", "--output=" + ExistingPatch, "--", before, after })
                    start.ArgumentList.Add(argument);
                using var process = Process.Start(start);
                string error = process.StandardError.ReadToEnd();
                process.WaitForExit();
                Assert.True(process.ExitCode == 1, error);
                string patch = Encoding.Latin1.GetString(File.ReadAllBytes(ExistingPatch));
                patch = Regex.Replace(patch, @"\Adiff --git [^\n]*", "diff --git a/um/sample.h b/um/sample.h");
                patch = Regex.Replace(patch, @"(?m)^--- [^\n]*", "--- a/um/sample.h");
                patch = Regex.Replace(patch, @"(?m)^\+\+\+ [^\n]*", "+++ b/um/sample.h");
                File.WriteAllBytes(ExistingPatch, Encoding.Latin1.GetBytes(patch));
                string hash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(Source)));
                var recipe = JsonNode.Parse(File.ReadAllText(Recipe));
                recipe["headers"].AsArray().Add(new JsonObject
                {
                    ["path"] = "um\\sample.h",
                    ["sourceSha256"] = hash,
                    ["sdkSha256"] = hash,
                    ["sdkPath"] = "c\\include\\10.0.26100.0\\um\\sample.h",
                });
                recipe["patches"].AsArray().Add("um\\sample.h.patch");
                File.WriteAllText(Recipe, recipe.ToJsonString());
            }

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
