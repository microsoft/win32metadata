using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text.Json;
using MetadataTasks;
using MetadataUtils;
using Microsoft.Build.Framework;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    public class ConstantSelectionBatchTests : HeaderAnnotationWinmdTests
    {
        private readonly ITestOutputHelper output;

        public ConstantSelectionBatchTests(ITestOutputHelper output) => this.output = output;

        [Fact]
        public void GuidInitializerTuplesPreserveGuidDefinitionsAndNestedCommaScalars()
        {
            const string high = "0x54F39980L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8";
            const string low = "0xE09C77E0L,0xDA60,0x11CF,0x9B,0x06,0x00,0xA0,0xC9,0x03,0xA3,0xB8";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define DDVPTYPE_E_HREFH_VREFH " + high + "\n" +
                "#define DDVPTYPE_E_HREFL_VREFL " + low + "\n" +
                "#define BARE_GUID_ALIAS DDVPTYPE_E_HREFH_VREFH\n" +
                "#define PAREN_GUID_ALIAS (DDVPTYPE_E_HREFH_VREFH)\n" +
                "#define NESTED_COMMA (1, (2, 3))\n" +
                "#define ELEVEN_COMMA (1,2,3,4,5,6,7,8,9,10,11)\n" +
                "#define NESTED_ELEVEN_COMMA ((1,2,3,4,5,6,7,8,9,10,11))\n" +
                "#define NESTED_CALL __builtin_choose_expr(1, (4, 5), 0)\nint F();",
                extraSettings: "--config\nnative-constant-values\n", namespaceName: "KernelStreaming");
            fixture.AssertSuccess();
            string input = Path.ChangeExtension(fixture.Output, ".native-constants.json");
            var values = JsonSerializer.Deserialize<NativeConstantValues>(File.ReadAllText(input));
            var scalars = new[]
            {
                (Name: "ELEVEN_COMMA", Value: 11),
                (Name: "NESTED_ELEVEN_COMMA", Value: 11),
                (Name: "PAREN_GUID_ALIAS", Value: 184),
            };
            foreach (string name in new[] { "DDVPTYPE_E_HREFH_VREFH", "DDVPTYPE_E_HREFL_VREFL" })
            {
                Assert.DoesNotContain(values.Constants, value => value.Name == name);
                var route = Assert.Single(values.Routes.Where(value => value.Name == name));
                Assert.Equal("ScannerResolved", route.Route);
                Assert.Equal("Guid", route.Reason);
                Assert.False(route.ValueProbed);
                Assert.False(route.CompilerEvaluated);
            }
            Assert.Equal("3", Assert.Single(values.Constants.Where(value => value.Name == "NESTED_COMMA")).Value);
            Assert.Equal("5", Assert.Single(values.Constants.Where(value => value.Name == "NESTED_CALL")).Value);
            Assert.DoesNotContain(values.Constants, value => value.Name == "BARE_GUID_ALIAS");
            var bareAlias = Assert.Single(values.Routes.Where(value => value.Name == "BARE_GUID_ALIAS"));
            Assert.Equal("ScannerResolved", bareAlias.Route);
            Assert.Equal("simple macro alias", bareAlias.Reason);
            Assert.False(bareAlias.ValueProbed);
            Assert.False(bareAlias.CompilerEvaluated);
            foreach (var scalar in scalars)
            {
                Assert.Equal(scalar.Value.ToString(System.Globalization.CultureInfo.InvariantCulture),
                    Assert.Single(values.Constants.Where(value => value.Name == scalar.Name)).Value);
                var route = Assert.Single(values.Routes.Where(value => value.Name == scalar.Name));
                Assert.Equal("UnresolvedValue", route.Route);
                Assert.NotEqual("Guid", route.Reason);
                Assert.True(route.ValueProbed);
                Assert.True(route.CompilerEvaluated);
            }

            string guidHeader = Path.Combine(fixture.DirectoryPath, "dvp.h");
            File.WriteAllText(guidHeader, "DEFINE_GUID(DDVPTYPE_E_HREFH_VREFH," + high + ");\n" +
                "DEFINE_GUID(DDVPTYPE_E_HREFL_VREFL," + low + ");\n");
            ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", fixture.DirectoryPath,
                "using System; using Windows.Win32.Foundation.Metadata;", new(),
                new() { [fixture.Header] = "KernelStreaming", [guidHeader] = "DirectDraw" },
                new(), new(), new(), new(), new ConstantSelectionOptions { NativeInputs = new[] { input } });
            using var image = Emit(fixture, "x64");
            var reader = image.Reader;
            foreach (var expected in new[]
            {
                (Name: "DDVPTYPE_E_HREFH_VREFH", Guid: "54F39980-DA60-11CF-9B06-00A0C903A3B8"),
                (Name: "DDVPTYPE_E_HREFL_VREFL", Guid: "E09C77E0-DA60-11CF-9B06-00A0C903A3B8"),
            })
            {
                var owner = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                        .Any(field => reader.GetString(field.Name) == expected.Name)));
                Assert.Equal("DirectDraw", reader.GetString(owner.Namespace));
                var field = Assert.Single(owner.GetFields().Select(reader.GetFieldDefinition)
                    .Where(value => reader.GetString(value.Name) == expected.Name));
                Assert.Equal((FieldAttributes)0, field.Attributes & FieldAttributes.Literal);
                Assert.True(field.GetDefaultValue().IsNil);
                var attribute = reader.GetCustomAttribute(Assert.Single(field.GetCustomAttributes()
                    .Where(handle => AttributeName(reader, handle) == "GuidAttribute")));
                Assert.Equal("0100" + Convert.ToHexString(new Guid(expected.Guid).ToByteArray()) + "0000",
                    Convert.ToHexString(reader.GetBlobBytes(attribute.Value)));
            }
            foreach (var scalar in scalars)
            {
                var owner = Assert.Single(reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                    .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                        .Any(field => reader.GetString(field.Name) == scalar.Name)));
                Assert.Equal("KernelStreaming", reader.GetString(owner.Namespace));
                var field = Assert.Single(owner.GetFields().Select(reader.GetFieldDefinition)
                    .Where(value => reader.GetString(value.Name) == scalar.Name));
                Assert.NotEqual((FieldAttributes)0, field.Attributes & FieldAttributes.Literal);
                var constant = reader.GetConstant(field.GetDefaultValue());
                Assert.Equal(System.Reflection.Metadata.ConstantTypeCode.Int32, constant.TypeCode);
                Assert.Equal(scalar.Value, reader.GetBlobReader(constant.Value).ReadInt32());
                Assert.DoesNotContain(field.GetCustomAttributes(), handle => AttributeName(reader, handle) == "GuidAttribute");
            }
            AssertMetadataClosure(reader);
            this.output.WriteLine($"GUID tuple regression: scraper={fixture.InvocationCount}; physical WinMD emissions=1");
        }

        [Fact]
        public void TwoNativeInputsServeAllSelectionPoliciesAndLogicalOwnershipAssertions()
        {
            using var first = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"sdk/um/infotech.h\"\n#define MEMBER (1U << 2)\n" +
                "#include \"group-owner.h\"\ntypedef unsigned SOURCE_GROUP;\nSOURCE_GROUP F(SOURCE_GROUP value);",
                extraSettings: "--config\nnative-constant-values\n");
            string groupOwner = Path.Combine(first.DirectoryPath, "group-owner.h");
            File.WriteAllText(groupOwner, "_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\n");
            string sdk = Path.Combine(first.DirectoryPath, "sdk");
            string original = Path.Combine(sdk, "um", "infotech.h");
            string preferred = Path.Combine(sdk, "um", "devicetopology.h");
            Directory.CreateDirectory(Path.GetDirectoryName(original));
            File.WriteAllText(original, "typedef long HRESULT;\n#define _HRESULT_TYPEDEF_(value) ((HRESULT)(value))\n" +
                "#define E_NOTFOUND _HRESULT_TYPEDEF_(0x8000100DL)\n");
            File.WriteAllText(preferred, "typedef long HRESULT;\n#define ERROR_NOT_FOUND 1168L\n" +
                "#define HRESULT_FROM_WIN32(value) ((HRESULT)((value) <= 0 ? (value) : (((value) & 0xffff) | 0x80070000)))\n" +
                "#define E_NOTFOUND HRESULT_FROM_WIN32(ERROR_NOT_FOUND)\n");
            using var second = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"" + preferred.Replace('\\', '/') + "\"\nint G();",
                extraSettings: "--config\nnative-constant-values\n");
            File.AppendAllText(Path.Combine(first.DirectoryPath, "test.rsp"), "--traverse\n" + original + "\n");
            File.AppendAllText(Path.Combine(second.DirectoryPath, "test.rsp"), "--traverse\n" + preferred + "\n");
            first.AssertSuccess();
            second.AssertSuccess();
            var group = Assert.Single(CSharpSyntaxTree.ParseText(first.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>());
            Assert.Equal("SOURCE_GROUP", group.Identifier.ValueText);
            var proof = NativeConstantGroupProvenance.Read(group);
            var values = JsonSerializer.Deserialize<NativeConstantValues>(
                File.ReadAllText(Path.ChangeExtension(first.Output, ".native-constants.json")));
            var exported = Assert.Single(values.Groups);
            this.output.WriteLine("Projected group: " + JsonSerializer.Serialize(proof.Group));
            this.output.WriteLine("Exported group: " + JsonSerializer.Serialize(exported));
            Retain(first.DirectoryPath, "logical-group-native");
            Assert.Equal(groupOwner, proof.Group.Header);
            Assert.Equal(JsonSerializer.Serialize(proof.Group), JsonSerializer.Serialize(exported));
            var binding = Assert.Single(Assert.Single(proof.Group.Members).Bindings);
            Assert.Equal("Macro", binding.Kind);
            Assert.Equal("MEMBER", binding.NativeName);
            int constantsOnlyInvocations = 0;
            foreach (bool redeclare in new[] { true, false })
            {
                using var constantsOnly = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                    "#define MEMBER (1U << 2)\n#include \"group-owner.h\"\n" +
                    (redeclare ? "typedef unsigned SOURCE_GROUP;\n" : "") + "SOURCE_GROUP F(SOURCE_GROUP value);",
                    extraSettings: "--config\nnative-constant-values\nnative-constants-only\n");
                string owner = Path.Combine(constantsOnly.DirectoryPath, "group-owner.h");
                File.WriteAllText(owner, "_Win32_Enum_(SOURCE_GROUP, unsigned, MEMBER);\n");
                int exitCode = constantsOnly.Run();
                this.output.WriteLine(constantsOnly.Diagnostics);
                constantsOnlyInvocations += constantsOnly.InvocationCount;
                Retain(constantsOnly.DirectoryPath, redeclare ? "logical-group-constants-only-redeclared" : "logical-group-constants-only-required");
                Assert.True(exitCode == 0, constantsOnly.Diagnostics);
                var facts = JsonSerializer.Deserialize<NativeConstantValues>(
                    File.ReadAllText(Path.ChangeExtension(constantsOnly.Output, ".native-constants.json")));
                var exportedGroup = Assert.Single(facts.Groups);
                this.output.WriteLine("Constants-only group: " + JsonSerializer.Serialize(exportedGroup));
                Assert.Equal(owner, exportedGroup.Header);
                Assert.Equal(proof.Group.Line, exportedGroup.Line);
                Assert.Equal(proof.Group.Name, exportedGroup.Name);
                Assert.Equal(proof.Group.NativeName, exportedGroup.NativeName);
                Assert.Equal(proof.Group.StorageType, exportedGroup.StorageType);
                Assert.Equal(proof.Group.Namespace, exportedGroup.Namespace);
                Assert.Equal("MEMBER", Assert.Single(exportedGroup.Members).Name);
            }
            string extraInput = Path.Combine(Path.GetDirectoryName(first.Output), "Other.native-constants.json");
            File.Copy(Path.ChangeExtension(second.Output, ".native-constants.json"), extraInput);
            var namespaces = new Dictionary<string, string> { ["SOURCE_GROUP"] = "Canonical" };
            foreach (bool explicitPriority in new[] { false, true })
                foreach (bool preferredFirst in new[] { false, true })
                {
                    this.output.WriteLine($"Constant selection policy: explicitPriority={explicitPriority}; preferredFirst={preferredFirst}");
                    var headers = preferredFirst
                        ? new Dictionary<string, string> { [preferred] = "Audio", [original] = "HtmlHelp", [first.Header] = "Origin", [groupOwner] = "Origin" }
                        : new Dictionary<string, string> { [original] = "HtmlHelp", [preferred] = "Audio", [first.Header] = "Origin", [groupOwner] = "Origin" };
                    var options = new ConstantSelectionOptions
                    {
                        SdkRoot = sdk,
                        HeaderPriority = explicitPriority ? new[] { @"um\devicetopology.h" } : Array.Empty<string>(),
                        NativeInputs = new[] { extraInput, Path.ChangeExtension(first.Output, ".native-constants.json") },
                    };
                    var result = Select();
                    Assert.Contains(result.Output, message => message.StartsWith("warning WMC001:", StringComparison.Ordinal) &&
                        message.Contains("E_NOTFOUND") && message.Contains("TYPE/VALUE CONFLICT"));
                    string reportPath = Path.Combine(first.DirectoryPath, "native-constant-conflicts.json");
                    string reportBytes = File.ReadAllText(reportPath);
                    using var report = JsonDocument.Parse(reportBytes);
                    var decision = report.RootElement.GetProperty("Decisions").EnumerateArray()
                        .Single(value => value.GetProperty("Name").GetString() == "E_NOTFOUND");
                    bool canonical = explicitPriority || preferredFirst;
                    Assert.True(decision.GetProperty("TypeValueConflict").GetBoolean());
                    Assert.True(decision.GetProperty("DistinctNativeDefinitions").GetBoolean());
                    Assert.Equal(canonical ? preferred : original,
                        Path.GetFullPath(decision.GetProperty("Selected").GetProperty("RawHeader").GetString()));
                    var candidates = decision.GetProperty("Candidates").EnumerateArray().ToArray();
                    Assert.Equal(2, candidates.Length);
                    Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "selected"));
                    Assert.Single(candidates.Where(value => value.GetProperty("Disposition").GetString() == "discarded-by-policy"));
                    Assert.All(candidates, value =>
                    {
                        Assert.Equal("HRESULT", value.GetProperty("NativeType").GetString());
                        Assert.True(value.GetProperty("Line").GetUInt32() > 0);
                        Assert.True(value.GetProperty("Column").GetUInt32() > 0);
                        Assert.False(string.IsNullOrEmpty(value.GetProperty("Reason").GetString()));
                    });
                    Select();
                    Assert.Equal(reportBytes, File.ReadAllText(reportPath));
                    if (!explicitPriority)
                    {
                        using var image = Emit(first.DirectoryPath, "x64", requiredNamespaces: namespaces);
                        var reader = image.Reader;
                        Assert.Equal("Canonical", reader.GetString(FindType(reader, "SOURCE_GROUP").Namespace));
                        var owners = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                            .Where(type => type.GetFields().Select(reader.GetFieldDefinition)
                                .Any(field => reader.GetString(field.Name) == "MEMBER")).ToArray();
                        Assert.Equal("SOURCE_GROUP", reader.GetString(Assert.Single(owners).Name));
                        var owner = reader.TypeDefinitions.Select(reader.GetTypeDefinition).Single(type =>
                            type.GetFields().Select(reader.GetFieldDefinition).Any(field => reader.GetString(field.Name) == "E_NOTFOUND"));
                        Assert.Equal(canonical ? "Audio" : "HtmlHelp", reader.GetString(owner.Namespace));
                        var field = owner.GetFields().Select(reader.GetFieldDefinition)
                            .Single(value => reader.GetString(value.Name) == "E_NOTFOUND");
                        var value = reader.GetConstant(field.GetDefaultValue());
                        Assert.Equal(System.Reflection.Metadata.ConstantTypeCode.Int32, value.TypeCode);
                        Assert.Equal(unchecked((int)(canonical ? 0x80070490 : 0x8000100D)),
                            reader.GetBlobReader(value.Value).ReadInt32());
                        AssertMetadataClosure(reader);
                        Retain(first.DirectoryPath, preferredFirst ? "logical-group-preferred-image" : "logical-group-original-image");
                    }
                    ScraperResults Select() => ConstantsScraper.ScrapeConstants(Array.Empty<string>(), "Test", first.DirectoryPath,
                        "using System; using Windows.Win32.Foundation.Metadata;", new(), headers, namespaces, new(), new(), new(), options);
                }
            this.output.WriteLine($"TOOLCHAIN constant selection: scraper={first.InvocationCount + second.InvocationCount + constantsOnlyInvocations}; physical WinMD emissions=2; managed policy selections=8");
        }

        [Fact]
        public void SelectedCompilerHeadersReachNativeInvocationAndConstantOwnership()
        {
            string directory = Path.Combine(Path.GetTempPath(), "selected-compiler-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string include = Path.Combine(directory, "selected", "include");
                string bin = Path.Combine(directory, "selected", "bin", "Hostx86", "x86");
                Directory.CreateDirectory(bin);
                string header = Write(Path.Combine(include, "toolchain.h"), "#define TOOLCHAIN_VALUE -7\nint F();\n");
                string source = Write(Path.Combine(directory, "Partitions", "Test", "main.cpp"), "#include <toolchain.h>\n");
                Write(Path.Combine(Path.GetDirectoryName(source), "settings.rsp"), "--namespace\nSelected\n--traverse\ntoolchain.h\n");
                string sdk = Path.Combine(directory, "unprepared-sdk");
                Directory.CreateDirectory(sdk);
                string obj = Path.Combine(directory, "obj");
                string output = Path.Combine(obj, "generated");
                string scratch = Path.Combine(obj, "scratch");
                string scripts = Path.Combine(directory, "scripts");
                string selectorCalls = Path.Combine(directory, "selector-calls.txt");
                string selector = Write(Path.Combine(scripts, "GetVcDirPath.ps1"),
                    "param($Arch, $HostArch)\nAdd-Content -LiteralPath '" +
                    selectorCalls.Replace("'", "''") + "' -Value $PID\n'" + bin.Replace("'", "''") + "'\n");
                string rsp = Write(Path.Combine(directory, "scraper.rsp"),
                    "--libraryPath\nscan.dll\n--config\ncompatible-codegen\ngenerate-cpp-attributes\n--additional=--target=i686-pc-windows-msvc\n");
                string assets = Path.Combine(directory, "assets");
                string prelude = Write(Path.Combine(assets, "scraper", "scraper.header.txt"),
                    "using System; using System.Runtime.InteropServices; using Windows.Win32.Foundation.Metadata;\n");
                Write(Path.Combine(assets, "scraper", "ConstantsScraper.header.txt"), File.ReadAllText(prelude));
                Write(Path.Combine(assets, "scraper", "baseSettings.rsp"), "");
                Write(Path.Combine(assets, "scraper", "baseSettings.ConstantsScraper.rsp"), "");
                Write(Path.Combine(directory, "manual.cs"),
                    File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
                string dotnet = Environment.GetEnvironmentVariable("DOTNET_HOST_PATH") ?? Path.GetFullPath(Path.Combine(
                    System.Runtime.InteropServices.RuntimeEnvironment.GetRuntimeDirectory(), "..", "..", "..",
                    OperatingSystem.IsWindows() ? "dotnet.exe" : "dotnet"));
                string project = Write(Path.Combine(directory, "selection.proj"),
                    "<Project><PropertyGroup><UsingMicrosoftNoTargetsSdk>true</UsingMicrosoftNoTargetsSdk></PropertyGroup>" +
                    $"<Import Project=\"{Xml(Path.Combine(AppContext.BaseDirectory, "assets", "scraper.sdk.props"))}\" />" +
                    "<PropertyGroup><UseWinSDKAssets>false</UseWinSDKAssets><EvaluateNativeConstants>true</EvaluateNativeConstants>" +
                    $"<ObjDir>{Xml(obj)}</ObjDir><SdkIncRoot>{Xml(sdk)}</SdkIncRoot>" +
                    $"<TargetPlatformSdkRootOverride>{Xml(sdk)}</TargetPlatformSdkRootOverride>" +
                    $"<TaskBinDir>{Xml(Path.GetDirectoryName(typeof(ScrapeHeaders).Assembly.Location))}</TaskBinDir>" +
                    $"<ToolsBinDir>{Xml(AppContext.BaseDirectory)}</ToolsBinDir><ScriptsDir>{Xml(scripts)}</ScriptsDir>" +
                    $"<Win32WinmdBinDir>{Xml(directory)}</Win32WinmdBinDir><WinmdVersion>1.0.0.0</WinmdVersion>" +
                    $"<OutputWinmd>{Xml(Path.Combine(directory, "output.winmd"))}</OutputWinmd>" +
                    $"<Win32MetadataAssetsDir>{Xml(assets)}</Win32MetadataAssetsDir><ScanArch>x86</ScanArch></PropertyGroup>" +
                    $"<ItemGroup><ScraperRsp Include=\"{Xml(rsp)}\" /></ItemGroup>" +
                    $"<ItemGroup><Partition Include=\"{Xml(source)}\"><Name>Test</Name><ExcludeFromCrossarch>true</ExcludeFromCrossarch></Partition></ItemGroup>" +
                    $"<Import Project=\"{Xml(Path.Combine(AppContext.BaseDirectory, "assets", "scraper.sdk.targets"))}\" /></Project>");
                Run(success: true, target: "ScrapeHeaders");
                string nativeInput = Path.Combine(output, "common", "Test.native-constants.json");
                string nativeHash = NativeConstantGroupProvenance.HashFile(nativeInput);
                var values = JsonSerializer.Deserialize<NativeConstantValues>(File.ReadAllText(nativeInput));
                var constant = Assert.Single(values.Constants.Where(value => value.Name == "TOOLCHAIN_VALUE"));
                Assert.Equal(header, constant.Header);
                Assert.Equal(NativeConstantGroupProvenance.HashFile(header), constant.HeaderHash);
                Assert.Equal("-7", constant.Value);
                Assert.Contains(include, File.ReadAllText(Path.Combine(scratch, "common", "Test.settings.rsp")));
                string ownership = Path.Combine(output, "native-constant-header-ownership.json");
                Write(ownership, "retained producer content is not independent consumer authority");
                Run(success: true, skipScraping: true);
                Assert.Equal(nativeHash, NativeConstantGroupProvenance.HashFile(nativeInput));
                string[] selectors = File.ReadAllLines(selectorCalls);
                Assert.Equal(2, selectors.Length);
                Assert.NotEqual(selectors[0], selectors[1]);
                using (var plan = JsonDocument.Parse(File.ReadAllText(Path.Combine(output, "native-constant-header-ownership.json"))))
                {
                    Assert.Equal(include, plan.RootElement.GetProperty("IncludeRoots")[0].GetString());
                    Assert.Equal(source, plan.RootElement.GetProperty("Inputs")[0].GetProperty("SourceFile").GetString());
                }
                Assert.True(File.Exists(Path.Combine(output, "constants.scraped.txt")));
                Retain(directory, "selected-compiler-positive");
                File.WriteAllText(selector, "param($Arch, $HostArch)\n'not-an-absolute-tools-directory'\n");
                foreach (bool skip in new[] { false, true })
                {
                    Run(success: false, skipScraping: skip, expectedError: "selected Visual C++ tools directory");
                    Run(success: true, skipScraping: skip, explicitRoot: include);
                    Run(success: false, skipScraping: skip, explicitRoot: "relative-include", expectedError: "compiler include root");
                }

                void Run(bool success, string target = "ScrapeConstants", bool skipScraping = false,
                    string explicitRoot = null, string expectedError = null)
                {
                    var start = new System.Diagnostics.ProcessStartInfo(dotnet)
                    {
                        WorkingDirectory = directory, UseShellExecute = false,
                        RedirectStandardOutput = true, RedirectStandardError = true,
                    };
                    foreach (string argument in new[] { "msbuild", project, "-t:" + target, "-m:1", "-nodeReuse:false",
                        "-verbosity:normal", "-p:SkipScraping=" + skipScraping })
                        start.ArgumentList.Add(argument);
                    if (explicitRoot != null)
                        start.ArgumentList.Add("-p:NativeConstantToolchainIncludeRoots=" + explicitRoot);
                    start.Environment["DOTNET_PROCESSOR_COUNT"] = "4";
                    start.Environment["INCLUDE"] = "";
                    start.Environment.Remove("NativeConstantToolchainIncludeRoots");
                    using var process = System.Diagnostics.Process.Start(start);
                    this.output.WriteLine($"Actual SDK target: pid={process.Id}; target={target}; SkipScraping={skipScraping}; explicitRoot={explicitRoot}");
                    var stdout = process.StandardOutput.ReadToEndAsync();
                    var stderr = process.StandardError.ReadToEndAsync();
                    if (!process.WaitForExit(60000))
                    {
                        process.Kill(entireProcessTree: true);
                        throw new TimeoutException("Selected compiler-header SDK target did not finish in 60 seconds.");
                    }
                    string log = stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult();
                    this.output.WriteLine(log);
                    Assert.True(success == (process.ExitCode == 0), log);
                    if (expectedError != null)
                        Assert.Contains(expectedError, log);
                }
            }
            finally
            {
                Retain(directory, "selected-compiler-final");
                Directory.Delete(directory, recursive: true);
            }

            static string Xml(string value) => System.Security.SecurityElement.Escape(value);
            static string Write(string path, string content)
            {
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(path, content);
                return path;
            }
        }

        private static void Retain(string directory, string name)
        {
            string root = Environment.GetEnvironmentVariable("WIN32_TYPEDEF_PROTOTYPE_EVIDENCE_ROOT");
            if (root == null)
                return;
            string destination = Path.Combine(root, name);
            foreach (string file in Directory.EnumerateFiles(directory, "*", SearchOption.AllDirectories))
            {
                string output = Path.Combine(destination, Path.GetRelativePath(directory, file));
                Directory.CreateDirectory(Path.GetDirectoryName(output));
                File.Copy(file, output, overwrite: true);
            }
        }

        [Fact]
        public void ChangedOrMissingConstantProducerInputsInvalidateTheCache()
        {
            foreach (string inputName in new[] { "ConstantsScraper.dll", "MetadataUtils.dll", "constants.header.txt" })
                foreach (bool remove in new[] { false, true })
                {
                    string directory = Path.Combine(Path.GetTempPath(), "constant-inputs-" + Guid.NewGuid().ToString("N"));
                    Directory.CreateDirectory(directory);
                    try
                    {
                        string tools = Path.Combine(directory, "tools");
                        Directory.CreateDirectory(tools);
                        string header = Path.Combine(directory, "constants.header.txt");
                        string marker = Path.Combine(directory, "constants.scraped.txt");
                        foreach (string input in new[] { Path.Combine(tools, "ConstantsScraper.dll"), Path.Combine(tools, "MetadataUtils.dll"), header })
                        {
                            File.WriteAllText(input, "");
                            File.SetLastWriteTimeUtc(input, DateTime.UtcNow.AddMinutes(-1));
                        }
                        File.WriteAllText(marker, "");
                        var task = new ScrapeConstants
                        {
                            ToolsBinDir = tools,
                            HeaderTextFile = header,
                            MarkerFileName = marker,
                            ScraperOutputDir = directory,
                            MSBuildProjectDirectory = directory,
                            SdkIncRoot = directory,
                            ResponseFiles = Array.Empty<ITaskItem>(),
                            ManualCs = Array.Empty<ITaskItem>(),
                        };
                        var check = typeof(ScrapeConstants).GetMethod("AreNonPartitionFilesUpToDate", BindingFlags.Instance | BindingFlags.NonPublic);
                        typeof(ScrapeConstants).GetField("loadedPartitions", BindingFlags.Instance | BindingFlags.NonPublic)
                            .SetValue(task, Array.Empty<Partition>());
                        File.WriteAllLines(Path.Combine(directory, "constant-selection-inputs.txt"),
                            new[] { "sdkRoot=" + Path.GetFullPath(directory) });
                        Assert.True(Assert.IsType<bool>(check.Invoke(task, null)));
                        string changed = inputName.EndsWith(".dll", StringComparison.Ordinal) ? Path.Combine(tools, inputName) : header;
                        if (remove)
                            File.Delete(changed);
                        else
                            File.SetLastWriteTimeUtc(changed, File.GetLastWriteTimeUtc(marker).AddSeconds(1));
                        Assert.False(Assert.IsType<bool>(check.Invoke(task, null)));
                    }
                    finally
                    {
                        Directory.Delete(directory, recursive: true);
                    }
                }
        }
    }
}
