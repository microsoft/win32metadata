using System;
using System.Collections.Generic;
using System.IO;
using System.IO.Abstractions.TestingHelpers;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Moq;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ConstantsScraperTests
    {
        [Theory]
        [InlineData("0x54F39980L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8")]
        [InlineData("0xE09C77E0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8")]
        [InlineData("842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113")]
        public void BareGuidInitializerListsAreStructuredValues(string expression)
        {
            Assert.True(ConstantsScraper.TryReadSimpleMacroValue(expression, true, true, _ => null, _ => null, out var value));
            Assert.Equal("Guid", value.Kind);
            Assert.Equal("GUID", value.NativeType);
            Assert.Null(value.StorageType);
            Assert.Equal(expression, value.Value);
            Assert.Equal(new[] { "GUID_VALUE" },
                ConstantsScraper.ReadObjectLikeMacroNames(new[] { "#define GUID_VALUE " + expression }));
        }

        [Theory]
        [InlineData("(1, (2, 3))")]
        [InlineData("(1,2,3,4,5,6,7,8,9,10,11)")]
        [InlineData("((1,2,3,4,5,6,7,8,9,10,11))")]
        [InlineData("CHOOSE(1, 2)")]
        [InlineData("CALL(1,2,3,4,5,6,7,8,9,10,11)")]
        [InlineData("1,2,3,4,5,6,7,8,9,CHOOSE(10,11)")]
        [InlineData("1,2,3,4,5,6,7,8,9,(10,11)")]
        [InlineData("1,2,3,4,5,6,7,8,9,10")]
        [InlineData("1,2,3,4,5,6,7,8,9,10,11,12")]
        public void OrdinaryCommaExpressionsAreNotGuidInitializerLists(string expression)
        {
            Assert.False(ConstantsScraper.TryReadSimpleMacroValue(expression, true, true, _ => null, _ => null, out _));
        }

        [Theory]
        [InlineData("((UCHAR)0)", 0)]
        [InlineData("((UCHAR)255)", 255)]
        [InlineData("((UCHAR)256)", 0)]
        [InlineData("((UCHAR)-1)", 255)]
        [InlineData("((UCHAR)-42)", 214)]
        public void LegacyUcharCastsPreserveNativeByteWidthAndWrapping(string expression, int expected)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\uchar.h"] = new MockFileData($"#define BYTE_VALUE {expression}\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\uchar.h"] = "Test.Namespace.Win32" });
            var compilation = CSharpCompilation.Create("LegacyUchar",
                new[] { CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var field = Assert.IsAssignableFrom<IFieldSymbol>(
                Assert.Single(compilation.GetTypeByMetadataName("Test.Namespace.Win32.Apis").GetMembers("BYTE_VALUE")));
            Assert.Equal(SpecialType.System_Byte, field.Type.SpecialType);
            Assert.Equal((byte)expected, Assert.IsType<byte>(field.ConstantValue));
        }

        [Fact]
        public void DuplicateGuidDefinitionsStillDeduplicate()
        {
            const string definition = "DEFINE_GUID(DDVPTYPE_E_HREFH_VREFH," +
                "0x54F39980L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8);\n";
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\first.h"] = new MockFileData(definition),
                [@"C:\second.h"] = new MockFileData(definition),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new()
                {
                    [@"C:\first.h"] = "Test.Namespace.Win32",
                    [@"C:\second.h"] = "Test.Namespace.Win32",
                });
            var field = Assert.Single(CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents)
                .GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>());
            Assert.Equal("Guid", field.Declaration.Type.ToString());
            Assert.Equal("DDVPTYPE_E_HREFH_VREFH__scanned__", Assert.Single(field.Declaration.Variables).Identifier.ValueText);
        }

        [Theory]
        [InlineData("DDVPTYPE_E_HREFH_VREFH", "0x54F39980L")]
        [InlineData("DDVPTYPE_E_HREFL_VREFL", "0xE09C77E0L")]
        public void SelectedNativeScalarCannotSilentlySuppressAGuid(string name, string firstComponent)
        {
            string directory = Path.Combine(Path.GetTempPath(), "native-guid-collision-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string tuple = firstComponent + ",0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8";
                string header = Path.Combine(directory, "ksmedia.h");
                string guidHeader = Path.Combine(directory, "dvp.h");
                string source = Path.Combine(directory, "main.cpp");
                File.WriteAllText(header, $"#define {name} {tuple}\n");
                File.WriteAllText(guidHeader, $"DEFINE_GUID({name},{tuple});\n");
                File.WriteAllText(source, "#include \"ksmedia.h\"\n");
                string input = Path.Combine(directory, "x64", "KernelStreaming.native-constants.json");
                Directory.CreateDirectory(Path.GetDirectoryName(input));
                File.WriteAllText(input, JsonSerializer.Serialize(new NativeConstantValues
                {
                    Architecture = Architecture.X64,
                    SourceFile = source,
                    SourceHash = NativeConstantGroupProvenance.HashFile(source),
                    BindingSource = Path.ChangeExtension(input.Replace(".native-constants.json", ""), ".cs"),
                    Namespace = "KernelStreaming",
                    Headers = new[] { header },
                    Constants = new()
                    {
                        new(name, name, header, 1, "int", "int", "184")
                        {
                            Column = 9,
                            HeaderHash = NativeConstantGroupProvenance.HashFile(header),
                            Evaluation = "Clang",
                        },
                    },
                }));
                var error = Assert.Throws<InvalidDataException>(() => ConstantsScraper.ScrapeConstants(
                    Array.Empty<string>(), "Test", directory, "", new(),
                    new() { [header] = "KernelStreaming", [guidHeader] = "DirectDraw" },
                    new(), new(), new(), new(), new ConstantSelectionOptions { NativeInputs = new[] { input } }));
                Assert.Contains(name, error.Message);
                Assert.Contains(header, error.Message);
                Assert.Contains(guidHeader, error.Message);
                Assert.Contains(source, error.Message);
                Assert.Contains("value 184", error.Message);
                using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(directory, "native-constant-conflicts.json")));
                Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
                var diagnostic = Assert.Single(report.RootElement.GetProperty("Errors").EnumerateArray());
                Assert.Equal("NATIVE_GUID_COLLISION", diagnostic.GetProperty("Code").GetString());
                Assert.Equal(input, diagnostic.GetProperty("Input").GetString());
                Assert.Equal(guidHeader, diagnostic.GetProperty("Header").GetString());
                Assert.Equal(1, diagnostic.GetProperty("Line").GetInt32());
                Assert.Equal("X64", diagnostic.GetProperty("Architecture").GetString());
                Assert.Empty(Directory.GetFiles(directory, "NativeConstants.*.header-types.cs", SearchOption.AllDirectories));
                Assert.Empty(Directory.GetFiles(directory, "*.constants.cs", SearchOption.AllDirectories));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        [Fact]
        public void ExternalToolchainTaskRequiresCurrentPhysicalHeaderAndPlan()
        {
            string directory = Path.Combine(AppContext.BaseDirectory, "toolchain-task-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string output = Path.Combine(directory, "consumer", "obj", "generated");
                string source = Path.Combine(directory, "consumer", "Partitions", "Test", "main.cpp");
                string root = Path.Combine(directory, "selected-toolchain", "include");
                string header = Path.Combine(root, "runtime", "control.h");
                const string headerText = "#define TOOLCHAIN_VALUE -7\n";
                Write(source, "#include <runtime/control.h>\n");
                Write(Path.Combine(Path.GetDirectoryName(source), "settings.rsp"), "--namespace\nSelected\n--traverse\nruntime/control.h\n");
                Write(header, headerText);
                string manual = Write(Path.Combine(directory, "manual.cs"), "namespace Selected { }\n");
                string input = Path.Combine(output, "common", "Test.native-constants.json");
                Write(input, JsonSerializer.Serialize(new NativeConstantValues
                {
                    Architecture = Architecture.X86,
                    SourceFile = source,
                    SourceHash = NativeConstantGroupProvenance.HashFile(source),
                    BindingSource = Path.ChangeExtension(input.Replace(".native-constants.json", ""), ".cs"),
                    Namespace = "NotAnOwnershipProof",
                    Headers = new[] { header },
                    Constants = new()
                    {
                        new("TOOLCHAIN_VALUE", "TOOLCHAIN_VALUE", header, 1, "int", "int", "-7")
                            { Column = 9, HeaderHash = NativeConstantGroupProvenance.HashFile(header) },
                    },
                }));
                string marker = Path.Combine(output, "bounded-managed-task-success.marker");
                string ownership = Path.Combine(output, "native-constant-header-ownership.json");
                string sdk = Path.Combine(directory, "unprepared-sdk", "include");
                Directory.CreateDirectory(sdk);
                string dotnet = Environment.GetEnvironmentVariable("DOTNET_HOST_PATH") ?? Path.GetFullPath(Path.Combine(
                    System.Runtime.InteropServices.RuntimeEnvironment.GetRuntimeDirectory(), "..", "..", "..",
                    OperatingSystem.IsWindows() ? "dotnet.exe" : "dotnet"));
                string project = Write(Path.Combine(directory, "isolated-task.proj"),
                    "<Project DefaultTargets=\"Run\">" +
                    $"<UsingTask TaskName=\"MetadataTasks.ScrapeConstants\" AssemblyFile=\"{Xml(Path.Combine(AppContext.BaseDirectory, "MetadataTasks.dll"))}\" />" +
                    $"<ItemGroup><Partition Include=\"{Xml(source)}\"><Name>Test</Name></Partition></ItemGroup>" +
                    "<Target Name=\"Run\">" +
                    $"<ScrapeConstants DefaultNamespace=\"Test\" ScraperOutputDir=\"{Xml(output)}\" Partitions=\"@(Partition)\" ManualCs=\"{Xml(manual)}\" " +
                    $"ToolsBinDir=\"{Xml(AppContext.BaseDirectory)}\" MSBuildProjectDirectory=\"{Xml(directory)}\" SdkIncRoot=\"{Xml(sdk)}\" " +
                    $"ToolchainIncludeRoots=\"{Xml(root)}\" MarkerFileName=\"{Xml(marker)}\" ToolExe=\"{Xml(dotnet)}\" />" +
                    "</Target></Project>");
                Run(success: true, cached: false);
                string plan = File.ReadAllText(ownership);
                DateTime markerTime = File.GetLastWriteTimeUtc(marker);
                Run(success: true, cached: true);
                Assert.Equal(markerTime, File.GetLastWriteTimeUtc(marker));

                DateTime headerTime = File.GetLastWriteTimeUtc(header);
                Write(header, headerText + "// changed bytes with the original timestamp\n");
                File.SetLastWriteTimeUtc(header, headerTime);
                Run(success: false, cached: false);
                AssertRejected();
                Write(header, headerText);
                Run(success: true, cached: false);

                File.Delete(header);
                Run(success: false, cached: false);
                AssertRejected();
                Write(header, headerText);
                Run(success: true, cached: false);

                DateTime planTime = File.GetLastWriteTimeUtc(ownership);
                Write(ownership, "{}");
                File.SetLastWriteTimeUtc(ownership, planTime);
                Run(success: true, cached: false);
                Assert.Equal(plan, File.ReadAllText(ownership));
                File.Delete(ownership);
                Run(success: true, cached: false);
                Assert.Equal(plan, File.ReadAllText(ownership));

                void Run(bool success, bool cached)
                {
                    string scratch = Path.Combine(directory, "process-files");
                    Directory.CreateDirectory(scratch);
                    var start = new System.Diagnostics.ProcessStartInfo(dotnet)
                    {
                        WorkingDirectory = directory, UseShellExecute = false,
                        RedirectStandardOutput = true, RedirectStandardError = true,
                    };
                    foreach (string argument in new[] { "msbuild", project, "-t:Run", "-m:1", "-nodeReuse:false", "-p:UseSharedCompilation=false", "-verbosity:normal" })
                        start.ArgumentList.Add(argument);
                    start.Environment["DOTNET_PROCESSOR_COUNT"] = "4";
                    start.Environment["TEMP"] = scratch;
                    start.Environment["TMP"] = scratch;
                    using var process = System.Diagnostics.Process.Start(start);
                    var stdout = process.StandardOutput.ReadToEndAsync();
                    var stderr = process.StandardError.ReadToEndAsync();
                    if (!process.WaitForExit(60000))
                    {
                        process.Kill(entireProcessTree: true);
                        throw new TimeoutException("Isolated managed constants task did not finish in 60 seconds.");
                    }
                    string log = stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult();
                    Assert.True(success == (process.ExitCode == 0), log);
                    Assert.Equal(!cached, log.Contains("Scraping constants and enums...", StringComparison.Ordinal));
                }

                void AssertRejected()
                {
                    Assert.False(File.Exists(marker));
                    using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-conflicts.json")));
                    Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
                    Assert.Equal("NATIVE_TOOLCHAIN_BINDING", report.RootElement.GetProperty("Errors")[0].GetProperty("Code").GetString());
                    Assert.Empty(Directory.GetFiles(output, "NativeConstants.*.header-types.cs", SearchOption.AllDirectories));
                }
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }

            static string Xml(string value) => System.Security.SecurityElement.Escape(value);
            static string Write(string path, string contents)
            {
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(path, contents);
                return path;
            }
        }

        [Theory]
        [InlineData("selected", null)]
        [InlineData("header-path-case", null)]
        [InlineData("missing-selection", "toolchain selection")]
        [InlineData("malformed-selection", "toolchain selection")]
        [InlineData("missing-roots", "toolchain selection")]
        [InlineData("missing-header", "toolchain header")]
        [InlineData("missing-proof", "native header proof")]
        [InlineData("hash-mismatch", "native header proof")]
        [InlineData("one-rejected-profile", "native header proof")]
        [InlineData("root-mismatch", "toolchain root")]
        [InlineData("unselected-traversal", "toolchain traversal")]
        [InlineData("unselected-input", "toolchain input owner")]
        [InlineData("architecture-mismatch", "toolchain architecture")]
        [InlineData("source-mismatch", "native source identity")]
        [InlineData("missing-source", "native source identity")]
        [InlineData("missing-source-hash", "native source identity")]
        [InlineData("source-path-mismatch", "native source identity")]
        [InlineData("ambiguous-owner", "toolchain input owner")]
        [InlineData("ambiguous-root", "toolchain traversal")]
        public void ExternalToolchainHeaderIdentity(string scenario, string expectedError)
        {
            string directory = Path.Combine(AppContext.BaseDirectory, "toolchain-header-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string output = Path.Combine(directory, "consumer", "generation", "WinSDK", "obj", "generated");
                string source = Path.Combine(directory, "consumer", "generation", "WinSDK", "Partitions", "Test", "main.cpp");
                string root = Path.Combine(directory, "selected-toolchain", "include");
                string selector = Path.Combine("runtime", "control.h");
                string header = Path.Combine(root, selector);
                Write(source, "#include <runtime/control.h>\n");
                Write(header, "#define TOOLCHAIN_VALUE -7\n#define TOOLCHAIN_OTHER 11\n");
                string headerHash = NativeConstantGroupProvenance.HashFile(header);
                string sourceHash = NativeConstantGroupProvenance.HashFile(source);
                string otherSource = Path.ChangeExtension(source, "unselected.cpp");
                if (scenario == "source-path-mismatch")
                    Write(otherSource, File.ReadAllText(source));
                var inputs = new List<string>();
                var owners = new List<object>();
                foreach (var target in new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
                {
                    string profile = target == Architecture.X86 ? "common" : target.ToString().ToLowerInvariant();
                    string input = Path.Combine(output, profile, "Test.native-constants.json");
                    var values = new NativeConstantValues
                    {
                        Architecture = target,
                        BindingSource = Path.Combine(directory, "producer", "generation", "WinSDK", "obj", "generated", profile, "Test.cs"),
                        SourceFile = Path.Combine(directory, "producer", "generation", "WinSDK", "Partitions", "Test", "main.cpp"),
                        SourceHash = scenario == "missing-source-hash" ? null : sourceHash,
                        Namespace = "NotAnOwnershipProof",
                        Headers = new[] { header },
                        Constants = new()
                        {
                            new("TOOLCHAIN_VALUE", "TOOLCHAIN_VALUE", header, 1, "int", "int", "-7")
                                { Column = 9, HeaderHash = headerHash },
                            new("TOOLCHAIN_OTHER", "TOOLCHAIN_OTHER", header, 2, "int", "int", "11")
                            {
                                Column = 9, HeaderHash = scenario == "missing-proof" ? null :
                                    scenario == "hash-mismatch" ||
                                        scenario == "one-rejected-profile" && target == Architecture.X64
                                        ? new string('F', 64) : headerHash,
                            },
                        },
                    };
                    if (scenario == "header-path-case")
                        values.Constants = values.Constants.Select(value => value with { Header = header.ToUpperInvariant() }).ToList();
                    Write(input, JsonSerializer.Serialize(values));
                    inputs.Add(input);
                    object owner = new
                    {
                        Input = scenario == "unselected-input" ? input + ".unselected" : input,
                        Architecture = scenario == "architecture-mismatch" ? Architecture.None : target,
                        SourceFile = scenario == "source-path-mismatch" ? otherSource : source,
                        Namespace = "Selected",
                        TraversedHeaders = new[] { scenario == "unselected-traversal" ? "elsewhere.h" : selector },
                    };
                    owners.Add(owner);
                    if (scenario == "ambiguous-owner")
                        owners.Add(owner);
                }
                string secondRoot = Path.Combine(directory, "other-toolchain", "include");
                if (scenario is "ambiguous-root" or "root-mismatch")
                    Write(Path.Combine(secondRoot, selector), File.ReadAllText(header));
                string ownership = Path.Combine(output, "native-constant-header-ownership.json");
                Write(ownership, JsonSerializer.Serialize(new
                {
                    Version = 1,
                    IncludeRoots = scenario == "missing-roots" ? Array.Empty<string>() :
                        scenario == "root-mismatch" ? new[] { secondRoot } :
                        scenario == "ambiguous-root" ? new[] { root, secondRoot } : new[] { root },
                    Inputs = owners,
                }));
                if (scenario == "missing-selection")
                    File.Delete(ownership);
                if (scenario == "malformed-selection")
                    Write(ownership, "{invalid");
                if (scenario == "missing-header")
                    File.Delete(header);
                if (scenario == "source-mismatch")
                    File.AppendAllText(source, "#define DIFFERENT_SOURCE 1\n");
                if (scenario == "missing-source")
                    File.Delete(source);
                var selection = JsonSerializer.Deserialize<ConstantSelectionOptions>(JsonSerializer.Serialize(new
                {
                    NativeInputs = inputs,
                    NativeHeaderOwnershipFile = ownership,
                }));
                Action scrape = () => ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", output, "",
                    new(), new() { [selector] = "Selected" }, new(), new(), new(), new(), selection);
                if (expectedError != null)
                {
                    var error = Assert.Throws<InvalidDataException>(scrape);
                    Assert.Contains(expectedError, error.Message, StringComparison.OrdinalIgnoreCase);
                    using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-conflicts.json")));
                    Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
                    Assert.Equal(3, report.RootElement.GetProperty("RawInputs").GetArrayLength());
                    Assert.Equal(3, report.RootElement.GetProperty("NativeInputReferences").GetArrayLength());
                    if (scenario == "one-rejected-profile")
                        Assert.Equal(1, report.RootElement.GetProperty("Errors").GetArrayLength());
                    foreach (var diagnostic in report.RootElement.GetProperty("Errors").EnumerateArray())
                    {
                        Assert.Equal("NATIVE_TOOLCHAIN_BINDING", diagnostic.GetProperty("Code").GetString());
                        Assert.Equal("constants.native-inputs", diagnostic.GetProperty("Stage").GetString());
                        Assert.Equal("selected-toolchain-header-binding", diagnostic.GetProperty("IdentityCategory").GetString());
                        Assert.Equal(header, diagnostic.GetProperty("Header").GetString());
                        Assert.False(string.IsNullOrEmpty(diagnostic.GetProperty("Architecture").GetString()));
                        Assert.Equal("Test", diagnostic.GetProperty("Partition").GetString());
                        Assert.False(string.IsNullOrEmpty(diagnostic.GetProperty("Cause").GetString()));
                    }
                    Assert.DoesNotContain(Directory.GetFiles(output, "*.header-types.cs", SearchOption.AllDirectories),
                        NativeConstantValues.IsGeneratedSource);
                    return;
                }
                scrape();
                foreach (string profile in new[] { "x86", "x64", "arm64" })
                {
                    string generated = File.ReadAllText(Path.Combine(output, profile, "NativeConstants.Selected.header-types.cs"));
                    Assert.Contains("TOOLCHAIN_VALUE = -7", generated);
                    Assert.Contains("TOOLCHAIN_OTHER = 11", generated);
                }
                using var completed = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-conflicts.json")));
                Assert.Equal("completed", completed.RootElement.GetProperty("Status").GetString());
                Assert.Equal(3, completed.RootElement.GetProperty("ToolchainHeaderOwnership").GetArrayLength());
                Assert.False(File.Exists(Path.Combine(output, "x64", "Test.cs")));
                Assert.False(File.Exists(Path.Combine(output, "arm64", "Test.cs")));
            }
            finally
            {
                Directory.Delete(directory, true);
            }

            static void Write(string path, string contents)
            {
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(path, contents);
            }
        }

        [Theory]
        [InlineData("equivalent-cache", null)]
        [InlineData("reversed-inputs", null)]
        [InlineData("same-path", null)]
        [InlineData("same-key", null)]
        [InlineData("cache-key-case", null)]
        [InlineData("binding-extension-case", null)]
        [InlineData("cross-drive", null)]
        [InlineData("cross-drive-sdk-header-source", null)]
        [InlineData("crossarch-producer", null)]
        [InlineData("missing-producer-manifest", "prepared SDK identity")]
        [InlineData("missing-selected-manifest", "prepared SDK identity")]
        [InlineData("malformed-producer-manifest", "prepared SDK identity")]
        [InlineData("same-path-missing-selected-manifest", "prepared SDK identity")]
        [InlineData("same-path-different-sdk", "prepared SDK identity")]
        [InlineData("same-path-missing-source-identity", "native source identity")]
        [InlineData("same-path-missing-native-binding", "native header proof")]
        [InlineData("same-key-missing-producer-manifest", "prepared SDK identity")]
        [InlineData("same-key-missing-source-identity", "native source identity")]
        [InlineData("unrelated-architecture-manifest", "prepared SDK identity")]
        [InlineData("crossarch-mismatch", "prepared SDK identity")]
        [InlineData("different-sdk", "prepared SDK identity")]
        [InlineData("different-prepared-headers", "prepared SDK identity")]
        [InlineData("missing-header-identity", "prepared SDK header identity")]
        [InlineData("different-header-bytes", "prepared SDK header hash")]
        [InlineData("different-native-binding", "native header proof")]
        [InlineData("missing-native-binding", "native header proof")]
        [InlineData("different-source-profile", "native source identity")]
        [InlineData("missing-source-identity", "native source identity")]
        [InlineData("missing-binding-source", "native source identity")]
        [InlineData("unrooted-source-identity", "native source identity")]
        [InlineData("missing-header-path", "native header identity")]
        [InlineData("unrecorded-sdk-root", "traversed header identity")]
        [InlineData("missing-traversed-owner", "traversed header identity")]
        [InlineData("authoritative-ambiguity", "conflicting authoritative source owners")]
        public void PreparedSdkRelocationRequiresTheRecordedSdkHeaderAndSourceIdentity(
            string scenario, string expectedError)
        {
            string directory = Path.Combine(Path.GetTempPath(), "prepared-native-identity-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string oldKey = new string('A', 64);
                string newKey = new string('B', 64);
                if (scenario == "cache-key-case")
                {
                    oldKey = oldKey.ToLowerInvariant();
                    newKey = newKey.ToLowerInvariant();
                }
                if (scenario.StartsWith("same-path", StringComparison.Ordinal))
                    oldKey = newKey;
                if (scenario.StartsWith("same-key", StringComparison.Ordinal))
                    newKey = oldKey;
                string output = Path.Combine(directory, "consumer", "generation", "WinSDK", "obj", "generated");
                string sourceRelative = Path.Combine("generation", "WinSDK", "Partitions", "Foundation", "main.cpp");
                string oldSource = Path.Combine(directory, "producer", sourceRelative);
                string currentSource = Path.Combine(directory, "consumer", sourceRelative);
                string relative = Path.Combine("shared", "rpcnterr.h");
                string oldHeader = Path.Combine(directory, "producer", "cache", oldKey, "headers", relative);
                if (scenario.StartsWith("cross-drive", StringComparison.Ordinal))
                    oldHeader = Path.Combine(Path.GetPathRoot(directory) == @"Z:\" ? @"Y:\" : @"Z:\",
                        "recorded-cache", oldKey, "headers", relative);
                if (scenario == "unrecorded-sdk-root")
                    oldHeader = Path.Combine(directory, "unrecorded-sdk", relative);
                if (scenario == "missing-header-path")
                    oldHeader = null;
                string sdk = scenario.StartsWith("same-key", StringComparison.Ordinal)
                    ? Path.Combine(directory, "consumer", "cache", newKey, "headers")
                    : Path.Combine(directory, "selected-cache", newKey, "headers");
                string header = Path.Combine(sdk, relative);
                if (scenario.StartsWith("same-path", StringComparison.Ordinal))
                    oldHeader = header;
                Write(currentSource, "#include <rpcnterr.h>\n");
                Write(header, "#define RPC_S_OUT_OF_MEMORY 14\n#define RPC_X_NO_MEMORY RPC_S_OUT_OF_MEMORY\n");
                string sourceHash = NativeConstantGroupProvenance.HashFile(currentSource);
                string headerHash = NativeConstantGroupProvenance.HashFile(header);
                Write(Path.Combine(output, "common", "Foundation.header-types.cs"),
                    HeaderTypesSourceFamily.SuccessMarker + "\n" +
                    "namespace Foundation { public enum RPC_STATUS : int { RPC_S_OUT_OF_MEMORY = 14 } }\n");
                Write(Path.Combine(output, "common", "Rpc.header-types.cs"),
                    HeaderTypesSourceFamily.SuccessMarker + "\n" +
                    "namespace Rpc { public enum RPC_STATUS : int { RPC_S_OUT_OF_MEMORY = 14 } }\n");
                var inputs = new List<string>();
                foreach (var architecture in new[] { Architecture.X86, Architecture.X64 })
                {
                    string arch = architecture.ToString().ToLowerInvariant();
                    string input = Path.Combine(output, arch, "Foundation.native-constants.json");
                    var values = new NativeConstantValues
                    {
                        Architecture = architecture,
                        BindingSource = scenario == "missing-binding-source" ? null :
                            Path.Combine(directory, "producer", "generation", "WinSDK", "obj",
                            "generated", arch, scenario == "binding-extension-case" ? "Foundation.CS" : "Foundation.cs"),
                        SourceFile = scenario == "unrooted-source-identity" ? sourceRelative :
                            scenario == "cross-drive-sdk-header-source" ? oldHeader : oldSource,
                        SourceHash = scenario.EndsWith("missing-source-identity", StringComparison.Ordinal) ? null :
                            scenario == "cross-drive-sdk-header-source" ? headerHash : sourceHash,
                        Namespace = "Foundation",
                        Headers = new[] { oldHeader },
                        Constants = new()
                        {
                            new("RPC_S_OUT_OF_MEMORY", "RPC_S_OUT_OF_MEMORY", oldHeader, 1, "int", "int", "14")
                            { Column = 9, HeaderHash = headerHash },
                            new("RPC_X_NO_MEMORY", "RPC_X_NO_MEMORY", oldHeader, 2, "int", "int", "14")
                            {
                                Column = 9, HeaderHash = scenario == "different-native-binding" ? new string('F', 64) :
                                    scenario.EndsWith("missing-native-binding", StringComparison.Ordinal) ? null : headerHash,
                            },
                        },
                    };
                    if (scenario == "authoritative-ambiguity")
                        values.Constants.RemoveAt(1);
                    Write(input, JsonSerializer.Serialize(values));
                    inputs.Add(input);
                    string producerArch = scenario.StartsWith("crossarch", StringComparison.Ordinal) ? "crossarch" :
                        scenario == "unrelated-architecture-manifest" ? "arm64" : arch;
                    if (!scenario.EndsWith("missing-producer-manifest", StringComparison.Ordinal))
                        Write(Path.Combine(Path.GetDirectoryName(output), "prepared-sdk-provenance", producerArch,
                            oldKey, "manifest.json"), scenario == "malformed-producer-manifest" ? "{invalid" :
                                Manifest(oldKey, producer: true));
                }
                if (!scenario.EndsWith("missing-selected-manifest", StringComparison.Ordinal))
                    Write(Path.Combine(Path.GetDirectoryName(sdk), "manifest.json"), Manifest(newKey, producer: false));
                if (scenario == "different-header-bytes")
                    File.AppendAllText(header, "#define CHANGED 1\n");
                if (scenario == "different-source-profile")
                    File.AppendAllText(currentSource, "#define DIFFERENT_PROFILE 1\n");
                if (scenario == "reversed-inputs")
                    inputs.Reverse();
                var headers = new Dictionary<string, string>();
                if (scenario != "missing-traversed-owner")
                    headers.Add(header, "Foundation");
                Action scrape = () => ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", output, "",
                    new(), headers, new(), new(), new(), new(),
                    new ConstantSelectionOptions { SdkRoot = sdk, NativeInputs = inputs });
                if (expectedError != null)
                {
                    var error = Assert.Throws<InvalidDataException>(scrape);
                    Assert.Contains(expectedError, error.Message, StringComparison.OrdinalIgnoreCase);
                    Assert.DoesNotContain(Directory.GetFiles(output, "*.header-types.cs", SearchOption.AllDirectories),
                        path => NativeConstantValues.IsGeneratedSource(path));
                    using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-conflicts.json")));
                    Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
                    return;
                }
                scrape();
                foreach (string arch in new[] { "x86", "x64" })
                {
                    string generated = File.ReadAllText(Path.Combine(output, arch, "NativeConstants.Foundation.header-types.cs"));
                    Assert.Contains("RPC_X_NO_MEMORY = 14", generated);
                    Assert.DoesNotContain("RPC_S_OUT_OF_MEMORY =", generated);
                }
                Assert.False(File.Exists(Path.Combine(output, "Foundation.constants.cs")));
                using var completed = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-conflicts.json")));
                Assert.Equal("completed", completed.RootElement.GetProperty("Status").GetString());

                string Manifest(string identity, bool producer) => JsonSerializer.Serialize(new
                {
                    schemaVersion = 1, identity = identity.ToUpperInvariant(),
                    sdkPackageVersion = !producer && (scenario.EndsWith("different-sdk", StringComparison.Ordinal) ||
                        scenario == "crossarch-mismatch")
                        ? "10.0.99999.1" : "10.0.28000.2705",
                    sourceStage = "post-midl", sourceGitTree = new string('C', 40),
                    sourceSha256 = new string('D', 64), recipeSha256 = new string('E', 64),
                    preparationSha256 = new string('F', 64),
                    preparedSha256 = !producer && scenario == "different-prepared-headers" ? new string('2', 64) : new string('1', 64),
                    files = producer && scenario == "missing-header-identity" ? Array.Empty<object>() :
                        new object[] { new { path = relative, sha256 = headerHash } },
                });
            }
            finally
            {
                Directory.Delete(directory, true);
            }

            static void Write(string path, string contents)
            {
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(path, contents);
            }
        }

        [Fact]
        public void ObjectLikeNameScanReusesDefineAndContinuationRulesWithoutEvaluatingValues()
        {
            string source = @"
                #define A 1
                # define EMPTY
                #define EXPRESSION (unknown_template<int>{} + invalid_value)
                #define FUNCTION(x) (x)
                #define OBJECT (x)
                #de\
fine CONTINUED \
                    (1 + 2)
                #if 0
                #define INACTIVE arbitrary tokens
                #endif
                /*
                #define COMMENTED_OUT 1
                */ #/**/define/**/AFTER_COMMENT/**/4
                #define TEXT ""/* not a comment */""
                #define LAST 'x' // trailing comment
                ";
            Assert.Equal(new[] { "A", "EMPTY", "EXPRESSION", "OBJECT", "CONTINUED", "INACTIVE",
                "AFTER_COMMENT", "TEXT", "LAST" },
                ConstantsScraper.ReadObjectLikeMacroNames(source.Split('\n').Select(line => line.TrimEnd('\r'))));
        }

        [Theory]
        [InlineData("ansi", true)]
        [InlineData("unicode", false)]
        [InlineData("", false)]
        public void StringConstantEncodingAttributesHaveValidSyntax(string context, bool hasEncodingAttribute)
        {
            using var stream = new MemoryStream();
            using (var writer = new ConstantWriter(stream, "Test", "", new()))
                writer.AddValue("string", "LIBRARY_NAME", "\"sample.dll\"", context);
            string output = System.Text.Encoding.UTF8.GetString(stream.ToArray());
            Assert.Empty(CSharpSyntaxTree.ParseText(output).GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            Assert.Equal(hasEncodingAttribute, output.Contains("[NativeEncoding(\"ansi\")]"));
            Assert.Contains("public const string LIBRARY_NAME = \"sample.dll\";", output);
        }

        [Theory]
        [InlineData("\"one\" \"two\"", "onetwo", true)]
        [InlineData("L\"one\" L\"two\"", "onetwo", false)]
        [InlineData("TEXT(\"one\") TEXT(\"two\")", "onetwo", false)]
        [InlineData("__TEXT(\"one\") NAME \"\\\\end\"", "oneUnit\\end", false)]
        [InlineData("_T(\"one\") NAME", "oneUnit", false)]
        [InlineData("NAME L\"\\\\sub\"", "Unit\\sub", false)]
        [InlineData("\"prefix\\\\\" NAME \"\\\\%s\"", "prefix\\Unit\\%s", true)]
        [InlineData("TEXT(\"prefix\\\\\") NAME", "prefix\\Unit", false)]
        [InlineData("(TEXT(\"one\") NAME)", "oneUnit", false)]
        [InlineData("TEXT(\"a\\\"b\") NAME", "a\"bUnit", false)]
        [InlineData("TEXT(\"\") NAME", "Unit", false)]
        [InlineData("\"{not a block}\"", "{not a block}", true)]
        [InlineData("TEXT(NAME)", "Unit", false)]
        [InlineData("TEXT ( NAME )", "Unit", false)]
        [InlineData("_T(NAME)", "Unit", false)]
        [InlineData("NAME TEXT(\"\\\\\") TEXT(NAME)", "Unit\\Unit", false)]
        public void AdjacentNativeStringTermsPreserveValueAndEncoding(string expression, string expected, bool ansi)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData(
                    $"#define VALUE {expression}\n#define NAME \"Unit\"\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            string output = files.GetFile("output.txt").TextContents;
            var compilation = CSharpCompilation.Create("AdjacentStrings", new[]
            {
                CSharpSyntaxTree.ParseText(output),
                CSharpSyntaxTree.ParseText(
                    "namespace Test.Namespace.Win32 { class NativeEncodingAttribute : System.Attribute { " +
                    "public NativeEncodingAttribute(string value) {} } }"),
            }, new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var field = Assert.IsAssignableFrom<IFieldSymbol>(
                Assert.Single(compilation.GetTypeByMetadataName("Test.Namespace.Win32.Apis").GetMembers("VALUE")));
            Assert.Equal(expected, field.ConstantValue);
            Assert.Equal(ansi, field.GetAttributes().Any(attribute => attribute.AttributeClass.Name == "NativeEncodingAttribute"));
        }

        [Fact]
        public void AdjacentStringTermsCannotFormatANumericOperandAsText()
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData(
                    "#define VALUE L\"prefix\" NUMBER\n#define NUMBER 7\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            var compilation = CSharpCompilation.Create("InvalidAdjacentStrings",
                new[] { CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Contains(compilation.GetDiagnostics(),
                diagnostic => diagnostic.Severity == DiagnosticSeverity.Error && diagnostic.Id == "CS0030");
        }

        [Theory]
        [InlineData("\"one\" + 1")]
        [InlineData("TEXT(\"one\")[0]")]
        public void StringArithmeticIsNotReinterpretedAsCSharpConcatenation(string expression)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData($"#define VALUE {expression}\n"),
            });
            using var scraper = new TestableConstantsScraper(files);
            var error = Assert.Throws<TargetInvocationException>(() =>
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" }));
            var cause = Assert.IsType<InvalidOperationException>(error.InnerException);
            Assert.Contains("'VALUE'", cause.Message);
            Assert.Contains(@"C:\strings.h", cause.Message);
            Assert.Contains(expression, cause.Message);
        }

        [Theory]
        [InlineData("extern \"C\" {")]
        [InlineData("extern \"C\"")]
        [InlineData("return \"value\"")]
        [InlineData("operator \"\" _suffix")]
        [InlineData("__declspec(uuid(\"example\"))")]
        [InlineData("__TEXT(NAME)")]
        public void QuotedTextInDeclarationAndStatementMacrosIsNotAStringConstant(string expression)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\strings.h"] = new MockFileData($"#define DECLARATION {expression}\n"),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\strings.h"] = "Test.Namespace.Win32" });
            Assert.DoesNotContain("DECLARATION =", files.GetFile("output.txt").TextContents);
        }

        [Theory]
        [InlineData("const")]
        [InlineData("static readonly")]
        [InlineData("static")]
        public void ExistingGlobalFieldBindingsOwnTheirConstantNames(string modifiers)
        {
            string directory = Path.Combine(Path.GetTempPath(), "existing-global-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                File.WriteAllText(Path.Combine(directory, "bindings.cs"),
                    "namespace Test { public static partial class Apis { public " + modifiers +
                    " string EXISTING=\"value\"; } }");
                var constants = ScraperUtils.GetConstants(directory, out var mutableGlobals);
                Assert.Equal("string", constants["EXISTING"]);
                Assert.Equal(modifiers == "static", mutableGlobals.Contains("EXISTING"));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData("ushort*", "(ushort*)-1")]
        [InlineData("string", "\"value\"")]
        [InlineData("int", "7")]
        public void MacroAliasesToMutableGlobalsAreNotInventedAsConstants(string type, string value)
        {
            string directory = Path.Combine(Path.GetTempPath(), "mutable-global-alias-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string bindings = Path.Combine(directory, "bindings.cs");
                File.WriteAllText(bindings, "namespace Test { public static unsafe partial class Apis { " +
                    $"public static {type} GLOBAL = {value}; public const int CONSTANT = 7; " + "} }");
                string header = Path.Combine(directory, "input.h");
                File.WriteAllText(header, "#define GLOBAL_ALIAS GLOBAL\n#define CONSTANT_ALIAS CONSTANT\n");
                var result = ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory, "",
                    new(), new() { [header] = "Test" }, new(), new(), new(), new());
                string output = File.ReadAllText(Path.Combine(directory, "Test.constants.cs"));
                Assert.DoesNotContain("GLOBAL_ALIAS =", output);
                Assert.Contains("public const int CONSTANT_ALIAS = CONSTANT;", output);
                Assert.Contains(result.Output, message => message.Contains("GLOBAL_ALIAS") &&
                    message.Contains("GLOBAL") && message.Contains("mutable") && message.Contains(header));
                var compilation = CSharpCompilation.Create("MutableAliases",
                    new[] { CSharpSyntaxTree.ParseText(File.ReadAllText(bindings)), CSharpSyntaxTree.ParseText(output) },
                    new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void ForwardMacroAliasesKeepCtlCodeValuesIndependentOfHeaderOrder(bool aliasesFirst)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\aliases.h"] = new MockFileData(
                    "#define DEVICE_BASE DEVICE_TYPE\n" +
                    "#define DEVICE_BASE_ALIAS DEVICE_BASE\n" +
                    "#define IOCTL_SAMPLE CTL_CODE(DEVICE_BASE_ALIAS, 3, METHOD_BUFFERED, FILE_READ_ACCESS)\n"),
                [@"C:\values.h"] = new MockFileData(
                    "#define DEVICE_TYPE 0x00000002\n#define METHOD_BUFFERED 0\n#define FILE_READ_ACCESS 0x0001\n"),
            });
            var headers = new Dictionary<string, string>();
            foreach (string name in aliasesFirst ? new[] { "aliases", "values" } : new[] { "values", "aliases" })
                headers.Add($@"C:\{name}.h", "Test.Namespace.Win32");
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(headers);

            var compilation = CSharpCompilation.Create("ForwardMacroAliases",
                new[] { CSharpSyntaxTree.ParseText(files.GetFile("output.txt").TextContents) },
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary));
            Assert.Empty(compilation.GetDiagnostics().Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error));
            var type = compilation.GetTypeByMetadataName("Test.Namespace.Win32.Apis");
            foreach (string name in new[] { "DEVICE_BASE", "DEVICE_BASE_ALIAS" })
            {
                var field = Assert.IsAssignableFrom<IFieldSymbol>(Assert.Single(type.GetMembers(name)));
                Assert.Equal(SpecialType.System_UInt32, field.Type.SpecialType);
                Assert.Equal(2u, field.ConstantValue);
            }
            var ioctl = Assert.IsAssignableFrom<IFieldSymbol>(Assert.Single(type.GetMembers("IOCTL_SAMPLE")));
            Assert.Equal(SpecialType.System_UInt32, ioctl.Type.SpecialType);
            Assert.Equal(0x2400Cu, ioctl.ConstantValue);
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void DeferredAliasesDoNotInventCyclicOrMissingProvidersOrReplaceExistingValues(bool providerFirst)
        {
            var files = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                [@"C:\aliases.h"] = new MockFileData(
                    "#define FIRST SECOND\n#define SECOND FIRST\n#define MISSING NOT_DEFINED\n" +
                    "#define PRESENT LATER\n" + (providerFirst
                        ? "#define LATER 0x00000002\n#define PRESENT 7\n"
                        : "#define PRESENT 7\n#define LATER 0x00000002\n")),
            });
            using (var scraper = new TestableConstantsScraper(files))
                scraper.ScrapeConstantsFromTraversedFiles(new() { [@"C:\aliases.h"] = "Test.Namespace.Win32" });

            string output = files.GetFile("output.txt").TextContents;
            Assert.Contains("PRESENT = 7;", output);
            Assert.DoesNotContain("FIRST =", output);
            Assert.DoesNotContain("SECOND =", output);
            Assert.DoesNotContain("MISSING =", output);
        }

        [Fact]
        public void DeferredAliasesDoNotStealResolvableDeclarationsFromAnotherHeader()
        {
            string directory = Path.Combine(Path.GetTempPath(), "header-aliases-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string early = Path.Combine(directory, "early.h");
                string later = Path.Combine(directory, "later.h");
                File.WriteAllText(early, "#define ALIAS PROVIDER\n");
                File.WriteAllText(later, "#define PROVIDER 0x00010000\n#define ALIAS PROVIDER\n");
                ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", directory, "",
                    new(), new() { [early] = "Early", [later] = "Later" }, new(), new(), new(), new());
                Assert.False(File.Exists(Path.Combine(directory, "Early.constants.cs")));
                Assert.Contains("public const uint ALIAS = PROVIDER;",
                    File.ReadAllText(Path.Combine(directory, "Later.constants.cs")));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]
        [InlineData(@"x86\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"x64\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"arm64\Group.header-types.cs", "Test", false, true, false)]
        [InlineData(@"common\header-types.cs", "Test", false, true, false)]
        [InlineData(@"x64\Group.cs", "Test", false, false, false)]
        [InlineData(@"x64\Group.header-types.modified.cs", "Test", false, false, false)]
        [InlineData(@"x64\Group.header-types.cs", "Foreign", false, false, false)]
        [InlineData(@"x64\Group.header-types.cs", "Foreign", true, true, false)]
        [InlineData(@"x64\Group.header-types.cs", "Test", false, true, true)]
        public void HeaderGroupMemberDoesNotCollideWithIndependentEnum(
            string sourceName, string sourceNamespace, bool routeNamespace, bool succeeds, bool omitLegacyNamespace)
        {
            string directory = Path.Combine(Path.GetTempPath(), "header-constants-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string source = Path.Combine(directory, sourceName);
                Directory.CreateDirectory(Path.GetDirectoryName(source));
                File.WriteAllText(source, $"namespace {sourceNamespace} {{ public enum SOURCE_GROUP : uint {{ MEMBER = 4 }} }}");
                string header = Path.Combine(directory, "test.h");
                File.WriteAllText(header, "#define MEMBER 4\n#define LEGACY_SINGLE 1\n#define LEGACY_DOUBLE 2\n");
                string enums = Path.Combine(directory, "enums.json");
                string legacy = @"{ ""items"": [{
                    ""name"": ""MEMBER"", ""namespace"": ""Test"", ""type"": ""uint"", ""flags"": true,
                    ""autoPopulate"": { ""filter"": ""LEGACY_"", ""header"": ""test.h"" }
                }] }";
                File.WriteAllText(enums, omitLegacyNamespace ? legacy.Replace(@"""namespace"": ""Test"",", "") : legacy);
                var namespaces = new Dictionary<string, string>();
                if (routeNamespace)
                    namespaces.Add("SOURCE_GROUP", "Test");
                Action scrape = () => ConstantsScraper.ScrapeConstants(new[] { enums }, "Test", directory, "",
                    new(), new() { [header] = "Test" }, namespaces, new(), new(), new());
                if (!succeeds)
                {
                    var error = Assert.Throws<InvalidOperationException>(scrape);
                    Assert.Contains("constant with the same name already exists", error.Message);
                    return;
                }
                scrape();
                string output = File.ReadAllText(Path.Combine(directory,
                    omitLegacyNamespace ? "System.SystemServices.enums.cs" : "Test.enums.cs"));
                Assert.Contains("enum MEMBER", output);
                Assert.Contains("LEGACY_SINGLE", output);
                Assert.Contains("LEGACY_DOUBLE", output);
                Assert.DoesNotContain("enum SOURCE_GROUP", output);
                Assert.Contains("MEMBER = 4", File.ReadAllText(Path.Combine(directory, "Test.constants.cs")));
            }
            finally
            {
                Directory.Delete(directory, true);
            }
        }

        [Theory]

        // No multicharacter literals = no change
        [InlineData(
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x3231564E, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113",
            "842094158, 0, 16, 128, 0, 0, 170, 0, 56, 155, 113"
        )]
        [InlineData(
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113",
            "0x3231564E, 0, 16, 128, 0, 0, 0xaa, 0, 56, 155, 113"
        )]

        // Multicharacter literals with varying amounts of leading/trailing space are
        // transformed into hexadecimal constants
        [InlineData(
            "'802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "'802P' , 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        [InlineData(
            "     '802P', 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71",
            "0x38303250, 0x0000, 0x0010, 0x80, 0x00, 0x00, 0xaa, 0x00, 0x38, 0x9b, 0x71"
        )]
        public void GetCanonicalGuidConstantIntegerArgs_VariousGuidConstantForms_CanonicalFormReturned(string actual, string expected)
        {
            // Arrange
            var implType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
            var implInstance = Activator.CreateInstance(implType, true);
            var method = implType.GetMethod("GetCanonicalGuidConstantIntegerArgs", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);

            // Act
            actual = method.Invoke(implInstance, new object[] { actual }) as string;

            // Assert
            Assert.Equal(expected, actual);
        }

        [Theory]
        [InlineData("MAKEINTRESOURCE(19)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 19;")]
        [InlineData("MAKEINTRESOURCE(0)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = 0;")]
        [InlineData("MAKEINTRESOURCE(-42)", "[NativeTypeName(\"LPCWSTR\")]", "public const ushort TEST_RESOURCE = unchecked((ushort) -42);")]
        [InlineData("MAKEINTRESOURCEA(1)", "[NativeTypeName(\"LPCSTR\")]", "public const ushort TEST_RESOURCE = 1;")]
        public void ScrapeConstantsFromTraversedFiles_MakeIntResourceConstantsPresent_UnsignedShortIntegersWritten(string actual, string expectedAttribute, string expectedConst)
        {
            // Arrange
            var mockFileSystem = new MockFileSystem(new Dictionary<string, MockFileData>
            {
                {
                    @"C:\test.h",
                    new MockFileData(
                        @$"
                        /* test.h */
                        #define TEST_RESOURCE {actual}
                        @"
                    )
                }
            });
            var fileMap = new Dictionary<string, string>(new[] {
                new KeyValuePair<string, string>("test.h", "Test.Namespace.Win32")
            });

            // Act
            {
                using var scraper = new TestableConstantsScraper(mockFileSystem);
                scraper.ScrapeConstantsFromTraversedFiles(fileMap);
            }

            // Assert
            Assert.Collection(mockFileSystem.GetFile("output.txt").TextContents.Split("\n"),
                e => { },
                e => { /* namespace */ },
                e => { /* { */ },
                e => { /*   class */ },
                e => { /*   { */ },
                e => Assert.Equal(expectedAttribute, e.Trim()),
                e => Assert.Equal(expectedConst, e.Trim()),
                e => { },
                e => { /*   } */ },
                e => { /* } */ },
                e => { }
            );
        }

        private class TestableConstantsScraper : IDisposable
        {
            private readonly object _instance;
            private readonly System.Reflection.MethodInfo _scrapeConstantsFromTraversedFiles;
            private bool _disposed;

            public TestableConstantsScraper(MockFileSystem mockFileSystem)
            {
                var scraperImplType = typeof(ConstantsScraper).GetNestedType("ConstantsScraperImpl", BindingFlags.NonPublic);
                this._scrapeConstantsFromTraversedFiles = scraperImplType.GetMethod("ScrapeConstantsFromTraversedFiles", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.InvokeMethod);
                this._instance = Activator.CreateInstance(scraperImplType, true);

                var fileSystemProperty = scraperImplType.GetProperty("_fileSystem", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetProperty);
                fileSystemProperty.SetValue(this._instance, mockFileSystem);

                var scraperOutputDirField = scraperImplType.GetField("scraperOutputDir", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scraperOutputDirField.SetValue(this._instance, @"C:\");

                var regexHelperField = scraperImplType.GetField("regexConstHelper", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                regexHelperField.SetValue(this._instance, Mock.Of<IRegexConstHelper>());

                var writtenConstants = new Dictionary<string, string>();
                var writtenConstantsField = scraperImplType.GetField("writtenConstants", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                writtenConstantsField.SetValue(this._instance, writtenConstants);

                var withTypesField = scraperImplType.GetField("withTypes", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                withTypesField.SetValue(this._instance, new Dictionary<string, string>());

                var requiredNamespaces = new WildcardDictionary(new());
                var requiredNamespacesField = scraperImplType.GetField("requiredNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                requiredNamespacesField.SetValue(this._instance, requiredNamespaces);

                var scannedNamesToNamespaces = new Dictionary<string, string>();
                var scannedNamesToNamespacesField = scraperImplType.GetField("scannedNamesToNamespaces", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                scannedNamesToNamespacesField.SetValue(this._instance, scannedNamesToNamespaces);

                var enumMemberNameToEnumObj = new Dictionary<string, List<EnumObject>>();
                var enumMemberNameToEnumObjField = scraperImplType.GetField("enumMemberNameToEnumObj", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                enumMemberNameToEnumObjField.SetValue(this._instance, enumMemberNameToEnumObj);

                var outputStream = mockFileSystem.File.OpenWrite("output.txt");
                var constantWriter = new ConstantWriter(outputStream, "Test.Namespace.Win32", "", new());
                var namespacesToConstantWriters = new Dictionary<string, IConstantWriter>()
                {
                    { "Test.Namespace.Win32", constantWriter }
                };
                var namespacesToConstantWritersField = scraperImplType.GetField("namespacesToConstantWriters", BindingFlags.NonPublic | BindingFlags.Instance | BindingFlags.SetField);
                namespacesToConstantWritersField.SetValue(this._instance, namespacesToConstantWriters);
            }

            public void ScrapeConstantsFromTraversedFiles(Dictionary<string, string> fileMap)
            {
                this._scrapeConstantsFromTraversedFiles.Invoke(this._instance, new[] { fileMap });
                var validation = this._instance.GetType().GetField("validation", BindingFlags.NonPublic | BindingFlags.Instance)
                    .GetValue(this._instance);
                typeof(GenerationValidation).GetMethod(nameof(GenerationValidation.ThrowIfAny))
                    .Invoke(validation, new object[] { null });
            }

            protected virtual void Dispose(bool disposing)
            {
                if (!this._disposed)
                {
                    if (disposing)
                    {
                        ((IDisposable)this._instance).Dispose();
                    }

                    this._disposed = true;
                }
            }

            public void Dispose()
            {
                this.Dispose(disposing: true);
                GC.SuppressFinalize(this);
            }
        }
    }
}
