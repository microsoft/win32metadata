using System;
using System.Collections;
using System.Collections.Concurrent;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Text.Json;
using System.Xml.Linq;
using ClangSharpSourceToWinmd;
using MetadataTasks;
using MetadataUtils;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class GenerationDiagnosticCollectionTests
    {
        [Fact]
        public void ConstantsCollectDeclarationFailuresAndVisitLaterEnumFinalization()
        {
            using var fixture = new Fixture();
            string header = fixture.Write("input.h",
                "#define FIRST_ALIAS OWNER\n#define TYPE_ALIAS STORAGE\n#define BAD_STRING \"prefix\" + 1\n" +
                "#define ENUM_ONE 1\n#define ENUM_TWO 2\n#define LATER_VISITED GLOBAL\n");
            fixture.Write("owners.cs", "namespace First { public enum A : uint { OWNER=1, STORAGE=1 } }\n" +
                "namespace Second { public enum B : uint { OWNER=2 } public enum C : int { STORAGE=2 } }\n" +
                "namespace Test { public static partial class Apis { public static int GLOBAL; } }");
            fixture.Write(@"x64\Gate.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n");
            string enums = fixture.Write("enums.json", "{\"items\":[" +
                "{\"name\":\"ENUM_ONE\",\"type\":\"uint\",\"members\":[{\"name\":\"ONE\",\"value\":\"1\"}]}," +
                "{\"name\":\"ENUM_TWO\",\"type\":\"uint\",\"members\":[{\"name\":\"TWO\",\"value\":\"2\"}]}," +
                "{\"name\":\"LaterEnum\",\"type\":\"uint\",\"members\":[{\"name\":\"LAST\",\"value\":\"3\"}]}]}");

            var error = Assert.Throws<InvalidDataException>(() => ConstantsScraper.ScrapeConstants(new[] { enums },
                "Test", fixture.Root, "", new(), new() { [header] = "Test" }, new(), new(), new(), new()));
            foreach (string symbol in new[] { "FIRST_ALIAS", "TYPE_ALIAS", "BAD_STRING", "ENUM_ONE", "ENUM_TWO" })
                Assert.Contains(symbol, error.Message);
            using var report = fixture.Report("native-constant-conflicts.json");
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
            Assert.Equal(5, errors.Length);
            Assert.All(errors, failure => Assert.False(string.IsNullOrEmpty(failure.GetProperty("Cause").GetString())));
            Assert.Contains(errors, failure => failure.GetProperty("Symbol").GetString() == "FIRST_ALIAS" &&
                failure.GetProperty("Header").GetString() == header && failure.GetProperty("Line").GetInt32() == 1);
            Assert.Contains(report.RootElement.GetProperty("Output").EnumerateArray(),
                message => message.GetString().Contains("LATER_VISITED"));
            Assert.Contains(report.RootElement.GetProperty("Output").EnumerateArray(),
                message => message.GetString().Contains("LaterEnum"));
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.constants.cs"));
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.enums.cs"));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "enumsRemap.rsp")));
        }

        [Fact]
        public void ConstantsCliCollectsMalformedProfilesAndLaterBindingFailure()
        {
            using var fixture = new Fixture();
            string header = fixture.Write("input.h", "#define VALID 1\n");
            string malformed = fixture.Write(@"x86\First.native-constants.json", "{");
            fixture.Write(@"x64\Second.native-constants.json", "{\"Architecture\":0,\"Headers\":null}");
            var input = new NativeConstantValues
            {
                Architecture = Architecture.Arm64, BindingSource = fixture.Root, Headers = new[] { header },
                Constants = new() {
                new NativeConstantValue("FIRST_ALIAS", "FIRST_ALIAS", header, 1, "int", "int", "1")
                {
                    AliasTarget = new NativeConstantBinding("invalid", "Target", header, 1, 1, "bad", "int", "int", "1"),
                },
                new NativeConstantValue("LAST_ALIAS", "LAST_ALIAS", header, 2, "int", "int", "1")
                {
                    AliasTarget = new NativeConstantBinding("invalid", "Target", header, 1, 1, "bad", "int", "int", "1"),
                } },
            };
            string last = fixture.Write(@"arm64\Last.native-constants.json", JsonSerializer.Serialize(input));
            var result = Run(typeof(ConstantsScraperApp.Program).Assembly.Location, "--scraperOutputDir", fixture.Root,
                "--defaultNamespace", "Test", "--traversedFileToNamespace", header + "=Test");
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(malformed, result.Output);
            Assert.Contains(last, result.Output);
            Assert.Contains("Invalid native constant architecture", result.Output);
            Assert.Contains("Invalid compiler-bound native alias", result.Output);
            Assert.Contains("Blocked stage", result.Output);
            using var report = fixture.Report("native-constant-conflicts.json");
            Assert.Equal(3, report.RootElement.GetProperty("RawInputs").GetArrayLength());
            Assert.All(report.RootElement.GetProperty("RawInputs").EnumerateArray(), input =>
            {
                Assert.False(input.TryGetProperty("Contents", out _));
                Assert.Equal(64, input.GetProperty("Sha256").GetString().Length);
                Assert.True(input.GetProperty("Length").GetInt64() > 0);
            });
            Assert.True(report.RootElement.GetProperty("Errors").GetArrayLength() >= 4);
            foreach (string symbol in new[] { "FIRST_ALIAS", "LAST_ALIAS" })
            {
                var failure = report.RootElement.GetProperty("Errors").EnumerateArray()
                    .Single(error => error.GetProperty("Symbol").GetString() == symbol);
                Assert.Equal("Arm64", failure.GetProperty("Architecture").GetString());
                Assert.Equal(header, failure.GetProperty("Header").GetString());
                Assert.Equal(last, failure.GetProperty("Input").GetString());
                Assert.Equal("native-constant-proof", failure.GetProperty("IdentityCategory").GetString());
                Assert.False(string.IsNullOrEmpty(failure.GetProperty("Cause").GetString()));
            }
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.constants.cs", SearchOption.AllDirectories));
            Assert.Empty(Directory.GetFiles(fixture.Root, "NativeConstants.*.header-types.cs", SearchOption.AllDirectories));
        }

        [Fact]
        public void RejectedSdkHeadersRetainEveryBindingContextAndLaterInputStillDiagnoses()
        {
            using var fixture = new Fixture();
            string validHeader = fixture.Write("input.h", "#define VALID 1\n");
            string oldRoot = Path.Combine(fixture.Root, "old-sdk", new string('A', 64), "headers");
            string sdkRoot = Path.Combine(fixture.Root, "new-sdk", new string('B', 64), "headers");
            string[] rawHeaders = { Path.Combine(oldRoot, "shared", "first.h"), Path.Combine(oldRoot, "um", "last.h") };
            string failedInput = fixture.Write(@"x86\Rejected.native-constants.json", JsonSerializer.Serialize(new NativeConstantValues
            {
                Architecture = Architecture.X86, BindingSource = fixture.Root, Headers = rawHeaders,
            }));
            fixture.Write(@"arm64\Later.native-constants.json", JsonSerializer.Serialize(new NativeConstantValues
            {
                Architecture = Architecture.Arm64, BindingSource = fixture.Root, Headers = new[] { validHeader },
                Constants = new() { new NativeConstantValue("LATER_ALIAS", "LATER_ALIAS", validHeader, 1, "int", "int", "1")
                {
                    AliasTarget = new NativeConstantBinding("invalid", "Target", validHeader, 1, 1, "bad", "int", "int", "1"),
                } },
            }));
            var result = Run(typeof(ConstantsScraperApp.Program).Assembly.Location, "--scraperOutputDir", fixture.Root,
                "--sdkRoot", sdkRoot, "--defaultNamespace", "Test", "--traversedFileToNamespace", validHeader + "=Test");
            Assert.NotEqual(0, result.ExitCode);
            Assert.DoesNotContain("fatal WMG999", result.Output);
            using var report = fixture.Report("native-constant-conflicts.json");
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
            foreach (string header in rawHeaders)
                Assert.Contains(errors, error => error.GetProperty("Code").GetString() == "NATIVE_SDK_BINDING" &&
                    error.GetProperty("Stage").GetString() == "constants.native-inputs" &&
                    error.GetProperty("IdentityCategory").GetString() == "prepared-sdk-header-binding" &&
                    error.GetProperty("Input").GetString() == failedInput &&
                    error.GetProperty("Architecture").GetString() == "X86" &&
                    error.GetProperty("Header").GetString() == header &&
                    error.GetProperty("SelectedSdkRoot").GetString() == sdkRoot);
            Assert.Contains(errors, error => error.GetProperty("Symbol").GetString() == "LATER_ALIAS");
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.constants.cs", SearchOption.AllDirectories));
            Assert.Empty(Directory.GetFiles(fixture.Root, "NativeConstants.*.header-types.cs", SearchOption.AllDirectories));
        }

        [Fact]
        public void EmitterPreflightCollectsIndependentInputsWithoutReplacingExistingWinmd()
        {
            using var fixture = new Fixture();
            fixture.Write(@"x64\First.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n");
            fixture.Write(@"arm64\Last.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n");
            string malformed = fixture.Write("malformed.json", "{");
            string declarations = fixture.Write("types.json",
                "[{\"Name\":\"NO_NAMESPACE\",\"ValueType\":\"int\"},{\"Name\":\"NO_VALUE\",\"Namespace\":\"Test\"}]");
            byte[] baseline = { 7, 8, 9 };
            string output = Path.Combine(fixture.Root, "output.winmd");
            File.WriteAllBytes(output, baseline);
            var result = Run(typeof(ClangSharpSourceToWinmd.Program).Assembly.Location,
                "--sourceDir", fixture.Root, "--arch", "crossarch", "--outputFileName", output,
                "--autoTypes", malformed, declarations);
            Assert.NotEqual(0, result.ExitCode);
            foreach (string text in new[] { "malformed.json", "NO_NAMESPACE", "NO_VALUE", "First.header-types", "Last.header-types", "Blocked stage" })
                Assert.Contains(text, result.Output);
            Assert.Equal(baseline, File.ReadAllBytes(output));
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.pending"));
            using var report = fixture.Report("generation-diagnostics.json");
            Assert.True(report.RootElement.GetProperty("Errors").GetArrayLength() >= 5);
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
        }

        [Fact]
        public void ReferencePreflightCollectsEveryBadReferenceAndIndependentSourceSyntax()
        {
            using var fixture = new Fixture();
            string source = fixture.Write(@"common\Broken.cs",
                "namespace Test { public static class Apis { public const int FIRST = ; public const int LAST = ; } }");
            string missing = Path.Combine(fixture.Root, "missing.dll");
            string missingDirectory = Path.Combine(fixture.Root, "missing", "last.dll");
            string invalid = fixture.Write("invalid.dll", "not a metadata image");
            string producer = fixture.Write("scrape-diagnostics.json", "[]");
            string retained = fixture.Write(@"obj\failed\source.modified.cs", "retained failed source");
            string output = fixture.Write("output.winmd", "previous-valid-image");
            var result = Run(typeof(ClangSharpSourceToWinmd.Program).Assembly.Location,
                "--sourceDir", fixture.Root, "--arch", "crossarch", "--outputFileName", output,
                "--preflightOnly", "--blockedBy", "ScrapeHeaders",
                "--ref", missing, invalid, missingDirectory);
            Assert.NotEqual(0, result.ExitCode);
            Assert.True(File.Exists(Path.Combine(fixture.Root, "emitter-preflight-diagnostics.json")), result.Output);
            using var report = fixture.Report("emitter-preflight-diagnostics.json");
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
            Assert.Contains(errors, error => error.GetProperty("Stage").GetString() == "emitter.producer-preflight" &&
                error.GetProperty("Input").GetString() == producer &&
                error.GetProperty("Cause").GetString().Contains("JsonException"));
            Assert.Equal(3, errors.Count(error => error.GetProperty("Stage").GetString() == "emitter.reference-preflight"));
            foreach (string reference in new[] { missing, invalid, missingDirectory })
                Assert.Contains(errors, error => error.GetProperty("Input").GetString() == reference &&
                    !string.IsNullOrEmpty(error.GetProperty("Cause").GetString()));
            Assert.Contains(errors, error => error.GetProperty("Stage").GetString() == "emitter.source-syntax-preflight" &&
                error.GetProperty("Input").GetString() == source);
            Assert.Equal(2, errors.Count(error => error.GetProperty("Stage").GetString() == "emitter.source-syntax-preflight"));
            Assert.Equal("retained failed source", File.ReadAllText(retained));
            Assert.Equal("previous-valid-image", File.ReadAllText(output));
            Assert.DoesNotContain("fatal WMG999", result.Output);
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.pending", SearchOption.AllDirectories));

            string metadata = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs"));
            string[] invalidReceipts =
            {
                "{\"Version\":1,\"Status\":\"blocked\",\"Errors\":[],\"BlockedStages\":[{\"Stage\":\"ScrapeHeaders\",\"Dependency\":\"inputs\"}]}",
                "{\"Version\":1,\"Status\":\"unknown\"}",
                "{\"Version\":2,\"Status\":\"completed\"}",
                "{\"Version\":1,\"Status\":\"completed\",\"Errors\":[{\"Code\":\"BAD\",\"Stage\":\"native\",\"Message\":\"invalid\",\"Cause\":\"original cause\"}]}",
                "{\"Version\":1,\"Status\":\"completed\",\"BlockedStages\":[{\"Stage\":\"native\",\"Dependency\":\"inputs\"}]}",
                "{\"Version\":1,\"Status\":\"completed\",\"Errors\":{}}",
                "{\"Version\":1,\"Status\":\"completed\",\"BlockedStages\":{}}",
                "{\"Version\":1,\"Status\":{}}",
            };
            foreach (string contents in invalidReceipts)
            {
                using var edge = new Fixture();
                edge.Write("Metadata.manual.cs", metadata);
                edge.Write(@"common\Valid.cs", "namespace Test { public static class Apis { public const int READY = 7; } }");
                string receipt = edge.Write("native-constant-conflicts.json", contents);
                string evidence = edge.Write(@"obj\failed\source.modified.cs", "retained producer failure evidence");
                string image = Path.Combine(edge.Root, "output.winmd");
                var rejected = Run(typeof(ClangSharpSourceToWinmd.Program).Assembly.Location,
                    "--sourceDir", edge.Root, "--arch", "crossarch", "--outputFileName", image);
                Assert.NotEqual(0, rejected.ExitCode);
                Assert.False(File.Exists(image));
                Assert.Equal("retained producer failure evidence", File.ReadAllText(evidence));
                using var rejectedReport = edge.Report("generation-diagnostics.json");
                Assert.Contains(rejectedReport.RootElement.GetProperty("Errors").EnumerateArray(),
                    error => error.GetProperty("Stage").GetString() == "emitter.producer-preflight" &&
                        error.GetProperty("Input").GetString() == receipt &&
                        !string.IsNullOrEmpty(error.GetProperty("Cause").GetString()));
                Assert.Contains(rejectedReport.RootElement.GetProperty("Reports").EnumerateArray(),
                    reference => reference.GetString() == receipt);
                Assert.DoesNotContain("fatal WMG999", rejected.Output);
                Assert.Empty(Directory.GetFiles(edge.Root, "*.pending", SearchOption.AllDirectories));
            }

            using var legacy = new Fixture();
            legacy.Write("Metadata.manual.cs", metadata);
            legacy.Write(@"common\Valid.cs", "namespace Test { public static class Apis { public const int READY = 7; } }");
            legacy.Write("native-constant-conflicts.json",
                "{\"Version\":1,\"Status\":\"completed\",\"NativeInputs\":[],\"SourceGroups\":[],\"Decisions\":[]}");
            string acceptedImage = Path.Combine(legacy.Root, "output.winmd");
            var accepted = Run(typeof(ClangSharpSourceToWinmd.Program).Assembly.Location,
                "--sourceDir", legacy.Root, "--arch", "crossarch", "--outputFileName", acceptedImage);
            Assert.True(accepted.ExitCode == 0, accepted.Output);
            using var pe = new PEReader(File.OpenRead(acceptedImage));
            Assert.True(pe.HasMetadata);
            Assert.False(File.Exists(Path.Combine(legacy.Root, "generation-diagnostics.json")));
        }

        [Fact]
        public void ReadOnlyPreflightPreservesFailedTransformedSourcesAndPriorReport()
        {
            using var fixture = new Fixture();
            fixture.Write("Metadata.manual.cs", File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
            fixture.Write(@"common\Broken.cs", "namespace Test { public static class Apis { public const int BAD = Missing; } }");
            string output = fixture.Write("output.winmd", "previous-valid-image");
            string tool = typeof(ClangSharpSourceToWinmd.Program).Assembly.Location;
            Assert.NotEqual(0, Run(tool, "--sourceDir", fixture.Root, "--arch", "crossarch", "--outputFileName", output).ExitCode);
            string failedTree = Path.Combine(fixture.Root, "obj", "crossarch", "common", "Broken.modified.cs");
            Assert.True(File.Exists(failedTree));
            File.AppendAllText(failedTree, "\n// retained failure evidence\n");
            fixture.Write(@"obj\failure-evidence.bin", "failed-stage bytes");
            var evidence = Directory.GetFiles(Path.Combine(fixture.Root, "obj"), "*", SearchOption.AllDirectories)
                .ToDictionary(path => path, File.ReadAllBytes);
            byte[] originalReport = File.ReadAllBytes(Path.Combine(fixture.Root, "generation-diagnostics.json"));
            var preflight = Run(tool, "--sourceDir", fixture.Root, "--arch", "crossarch", "--outputFileName", output,
                "--preflightOnly", "--blockedBy", "test producer");
            Assert.NotEqual(0, preflight.ExitCode);
            foreach (var file in evidence)
                Assert.Equal(file.Value, File.ReadAllBytes(file.Key));
            Assert.Equal(originalReport, File.ReadAllBytes(Path.Combine(fixture.Root, "generation-diagnostics.json")));
            using var report = fixture.Report("emitter-preflight-diagnostics.json");
            Assert.Equal("blocked", report.RootElement.GetProperty("Status").GetString());
            Assert.Equal("previous-valid-image", File.ReadAllText(output));
            var targets = XDocument.Load(Path.Combine(AppContext.BaseDirectory, "assets", "scraper.sdk.targets"));
            var emitter = targets.Root.Elements("Target").Single(target => (string)target.Attribute("Name") == "EmitWinmd");
            Assert.Equal("CollectFinalGenerationDiagnostics", (string)emitter.Element("OnError").Attribute("ExecuteTargets"));
        }

        [Fact]
        public void QualificationCollectsAllDeclarationsAndArchitecturesBeforeBlockingComposition()
        {
            using var fixture = new Fixture();
            fixture.Write(@"common\Constants.cs", "namespace Test { public static partial class Apis { " +
                "public const int FIRST = MissingFirst; public const int LAST = MissingLast; public const int GOOD = 7; } }");
            Assert.Throws<InvalidOperationException>(() => Compile(fixture.Root, "crossarch"));
            using var report = fixture.Report("generation-diagnostics.json");
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray()
                .Where(error => error.GetProperty("Stage").GetString() == "emitter.constant-qualification").ToArray();
            Assert.Equal(6, errors.Length);
            foreach (string arch in new[] { "X86", "X64", "Arm64" })
                foreach (string symbol in new[] { "FIRST", "LAST" })
                    Assert.Contains(errors, error => error.GetProperty("Architecture").GetString() == arch &&
                        error.GetProperty("Symbol").GetString() == symbol);
            Assert.Contains(report.RootElement.GetProperty("Errors").EnumerateArray(),
                error => error.GetProperty("Stage").GetString() == "emitter.constant-binding" &&
                    error.GetProperty("Message").GetString().Contains("CS0103"));
        }

        [Fact]
        public void FinalizationCollectsTypedefConflictsAndIndependentAssociations()
        {
            using var fixture = new Fixture();
            fixture.Write("Metadata.manual.cs", File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
            const string imports = "using Windows.Win32.Foundation.Metadata; namespace Test { ";
            fixture.Write(@"common\autotypes.cs", imports +
                "[NativeTypedef] public partial struct FIRST { public int Value; } " +
                "[NativeTypedef] public partial struct LAST { public int Value; } }");
            fixture.Write(@"x64\Types.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n" + imports +
                "[NativeTypedef] public partial struct FIRST { public long Value; } " +
                "[NativeTypedef] public partial struct LAST { public long Value; } }");
            fixture.Write(@"common\Associations.cs", imports + "public static class Apis { " +
                "[AssociatedEnum(\"MISSING_FIRST\")] public static int First; " +
                "[AssociatedEnum(\"MISSING_LAST\")] public static int Last; } }");
            Assert.Throws<InvalidDataException>(() => Compile(fixture.Root, "x64"));
            using var report = fixture.Report("generation-diagnostics.json");
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
            Assert.Equal(2, errors.Count(error => error.GetProperty("Stage").GetString() == "emitter.typedef-composition"));
            foreach (string name in new[] { "MISSING_FIRST", "MISSING_LAST" })
                Assert.Contains(errors, error => error.GetProperty("Message").GetString().Contains(name));
            Assert.Contains(report.RootElement.GetProperty("BlockedStages").EnumerateArray(),
                stage => stage.GetProperty("Stage").GetString() == "emitter.typedef-constant-lowering");
        }

        [Fact]
        public void NativeJobBoundaryContinuesAfterValidationAndProcessFailuresButNotUnknownFailures()
        {
            using var fixture = new Fixture();
            var task = new JobTask { GeneratedDir = fixture.Root, ScratchDir = fixture.Root, SdkIncRoot = fixture.Root,
                BuildEngine = new BuildEngine() };
            Assert.False(task.Run(fixture.Root, "Validation", "Process", "Later"));
            Assert.Equal(new[] { "Validation", "Process", "Later" }, task.Visited.ToArray());
            using (var report = fixture.Report("scrape-diagnostics.json"))
            {
                var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                Assert.Equal(2, errors.Length);
                Assert.All(errors, error => Assert.Equal("x64", error.GetProperty("Architecture").GetString()));
                Assert.Contains(errors, error => error.GetProperty("Cause").GetString().Contains("RAW_NATIVE_ERROR"));
                Assert.NotEmpty(report.RootElement.GetProperty("BlockedStages").EnumerateArray());
            }
            Assert.True(task.Run(fixture.Root, "Valid"));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "scrape-diagnostics.json")));
            Assert.Throws<AggregateException>(() => task.Run(fixture.Root, "Unexpected"));
            using var fatal = fixture.Report("scrape-diagnostics.json");
            Assert.Contains(fatal.RootElement.GetProperty("Errors").EnumerateArray(),
                error => error.GetProperty("Code").GetString() == "WMG999");
            Assert.False(task.RunInvalidPlanning(fixture.Root));
            Assert.Equal(new[] { "Later" }, task.Visited.ToArray());
            using var planning = fixture.Report("scrape-diagnostics.json");
            Assert.Equal(2, planning.RootElement.GetProperty("Errors").GetArrayLength());
        }

        [Theory]
        [InlineData("native")]
        [InlineData("constants")]
        [InlineData("settings")]
        public void DefaultMsbuildDependenciesRunIndependentPreflightsAndRejectImage(string failedStage)
        {
            using var fixture = new Fixture();
            string generated = Path.Combine(fixture.Root, "obj", "generated");
            string header = fixture.Write("input.h", "#define VALID 1\n");
            fixture.Write("Metadata.cs", File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
            fixture.Write("enums.json", "{");
            string badAutoType = fixture.Write("auto-types.json", "{");
            string laterAutoType = fixture.Write("later-auto-types.json",
                "[{\"Name\":\"LATER_TYPE\",\"ValueType\":\"int\"},{\"Name\":\"LAST_TYPE\",\"Namespace\":\"Test\"}]");
            string pointerFixups = fixture.Write("fixups.json", "[{}]");
            fixture.Write(@"obj\generated\x64\First.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n");
            fixture.Write(@"obj\generated\arm64\Last.header-types.cs", HeaderTypesSourceFamily.SuccessMarker + "\n");
            fixture.Write(@"obj\generated\x86\First.native-constants.json", "{");
            var laterInput = new NativeConstantValues
            {
                Architecture = Architecture.Arm64, BindingSource = generated, Headers = new[] { header },
                Constants = new() { new NativeConstantValue("LAST_ALIAS", "LAST_ALIAS", header, 1, "int", "int", "1")
                {
                    AliasTarget = new NativeConstantBinding("invalid", "Target", header, 1, 1, "bad", "int", "int", "1"),
                } },
            };
            fixture.Write(@"obj\generated\arm64\Last.native-constants.json", JsonSerializer.Serialize(laterInput));
            fixture.Write(@"obj\generated\filtered.constants.generated.rsp", "");
            fixture.Write(@"obj\generated\filtered.emitter.generated.rsp", "");
            fixture.Write(@"obj\generated\ConstantsScraper.header.generated.txt", "");
            fixture.Write(@"assets\scraper\baseSettings.ConstantsScraper.rsp", "");
            fixture.Write(@"obj\generated\unrelated\Old.cs.generation-diagnostics.json", OldReport());
            fixture.Write(@"obj\generated\generation-diagnostics.json", OldReport());
            fixture.Write(@"obj\generated\native-constant-conflicts.json", OldReport());
            string marker = fixture.Write(@"obj\generated\constants.scraped.txt", "stale");
            string headerMarker = fixture.Write(@"obj\generated\scannedheaders.crossarch.txt", "stale");
            string output = fixture.Write("Windows.Win32.winmd", "previous-valid-image");
            var properties = new XElement("PropertyGroup",
                new XElement("ObjDir", Path.Combine(fixture.Root, "obj")),
                new XElement("ToolsBinDir", Path.GetDirectoryName(typeof(ConstantsScraperApp.Program).Assembly.Location)),
                new XElement("TaskBinDir", Path.GetDirectoryName(typeof(ScrapeHeaders).Assembly.Location)),
                new XElement("SdkIncRoot", fixture.Root),
                new XElement("TargetPlatformSdkRootOverride", fixture.Root),
                new XElement("ScriptsDir", fixture.Root),
                new XElement("Win32MetadataAssetsDir", Path.Combine(fixture.Root, "assets")),
                new XElement("Win32WinmdBinDir", fixture.Root),
                new XElement("WinmdVersion", "1.0.0.0"),
                new XElement("OutputWinmd", output),
                new XElement("ScanArch", "crossarch"));
            var items = new XElement("ItemGroup",
                new XElement("ManualCs", new XAttribute("Include", Path.Combine(fixture.Root, "Metadata.cs"))),
                new XElement("AutoType", new XAttribute("Include", badAutoType)),
                new XElement("AutoType", new XAttribute("Include", laterAutoType)),
                new XElement("FunctionPointerFixup", new XAttribute("Include", pointerFixups)),
                new XElement("ImportLibs", new XAttribute("Include", Path.Combine(fixture.Root, "unused.lib"))));
            foreach (string name in new[] { "First", "Last" })
            {
                string main = fixture.Write(name + @"\main.cpp", "");
                var partition = new XElement("Partition", new XAttribute("Include", main),
                    new XElement("Name", name), new XElement("TraverseFiles", header));
                if (failedStage != "native")
                    partition.Add(new XElement("Namespace", "Test"));
                items.Add(partition);
            }
            var project = new XElement("Project", properties,
                new XElement("Import", new XAttribute("Project", Path.Combine(AppContext.BaseDirectory, "assets", "scraper.sdk.targets"))),
                items);
            // Only infrastructure prerequisites are stubbed; the production targets, tasks and failure bridge run unchanged.
            foreach (string name in new[] { "PrepScraperHeader", "PrepConstantsScraperHeader", "TrackGeneratedSourceInputs",
                "PrepSettingsForFunctionPointerFixups", "CompileIdls", "PrepareWithLibsRsp", "FilterRsps" })
                project.Add(new XElement("Target", new XAttribute("Name", name)));
            if (failedStage != "settings")
                project.Add(new XElement("Target", new XAttribute("Name", "PrepSettingsForAutoTypes")));
            if (failedStage == "constants")
                project.Add(new XElement("Target", new XAttribute("Name", "ScrapeHeaders")));
            string projectPath = fixture.Write("diagnostic-census.proj", project.ToString());
            var result = Run("msbuild", projectPath, "-nologo", "-verbosity:minimal", "-maxcpucount:1", "-target:ScrapeConstants");
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Validating independent emitter inputs", result.Output);
            Assert.True(File.Exists(Path.Combine(generated, "generation-failures.json")), result.Output);
            using var report = fixture.Report(@"obj\generated\generation-failures.json");
            Assert.Equal("rejected", report.RootElement.GetProperty("Status").GetString());
            var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
            Assert.DoesNotContain(errors, error => error.GetProperty("Code").GetString() == "OLD");
            foreach (string name in new[] { "LATER_TYPE", "LAST_TYPE" })
                Assert.Contains(errors, error => (error.GetProperty("Message").GetString() +
                    error.GetProperty("Symbol").GetString()).Contains(name));
            Assert.True(errors.Any(error => error.GetProperty("Stage").GetString() == (failedStage switch
            {
                "native" => "ScrapeHeaders.partition-plan",
                "settings" => "PrepSettingsForAutoTypes",
                _ => "constants.native-input",
            })), result.Output);
            Assert.Contains(errors, error => error.GetProperty("Stage").GetString() == "emitter.source-family-preflight");
            Assert.Contains(errors, error => error.GetProperty("Input").GetString()?.EndsWith("enums.json") == true);
            Assert.All(errors, error => Assert.False(string.IsNullOrEmpty(error.GetProperty("Cause").GetString())));
            Assert.Contains(report.RootElement.GetProperty("BlockedStages").EnumerateArray(),
                stage => stage.GetProperty("Stage").GetString() == "default tests");
            Assert.True(report.RootElement.GetProperty("Reports").GetArrayLength() >= 3);
            Assert.Equal("previous-valid-image", File.ReadAllText(output));
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.pending", SearchOption.AllDirectories));
            Assert.False(File.Exists(marker));
            Assert.False(File.Exists(headerMarker));
        }

        [Fact]
        public void ManagedOnlyFailureWritesCurrentRootReportAndGoodIncrementalRunRetiresIt()
        {
            using var fixture = new Fixture();
            string generated = Path.Combine(fixture.Root, "obj", "generated");
            string broken = fixture.Write(@"obj\generated\common\Broken.cs",
                "namespace Test { public static class Apis { public const int BAD = Missing; public const int GOOD = 7; } }");
            fixture.Write(@"obj\generated\Metadata.manual.cs",
                File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
            string unrelated = fixture.Write(@"obj\generated\unrelated\Old.cs.generation-diagnostics.json", OldReport());
            string oldPreflight = fixture.Write(@"obj\generated\emitter-preflight-diagnostics.json", OldReport());
            string output = fixture.Write("Windows.Win32.winmd", "previous-valid-image");
            var project = new XElement("Project",
                new XElement("PropertyGroup",
                    new XElement("ObjDir", Path.Combine(fixture.Root, "obj")),
                    new XElement("ToolsBinDir", Path.GetDirectoryName(typeof(ConstantsScraperApp.Program).Assembly.Location)),
                    new XElement("TaskBinDir", Path.GetDirectoryName(typeof(ScrapeHeaders).Assembly.Location)),
                    new XElement("Win32WinmdBinDir", fixture.Root),
                    new XElement("WinmdVersion", "1.0.0.0"),
                    new XElement("OutputWinmd", output),
                    new XElement("ScanArch", "crossarch")),
                new XElement("Import", new XAttribute("Project", Path.Combine(AppContext.BaseDirectory, "assets", "scraper.sdk.targets"))),
                new XElement("ItemGroup", new XElement("ImportLibs", new XAttribute("Include", Path.Combine(fixture.Root, "unused.lib")))),
                new XElement("Target", new XAttribute("Name", "ScrapeConstants")));
            string path = fixture.Write("emitter-only.proj", project.ToString());
            string[] args = { path, "-nologo", "-verbosity:minimal", "-maxcpucount:1", "-target:EmitWinmd" };
            var rejected = Run("msbuild", args);
            Assert.NotEqual(0, rejected.ExitCode);
            Assert.True(File.Exists(Path.Combine(generated, "generation-failures.json")), rejected.Output);
            using (var report = fixture.Report(@"obj\generated\generation-failures.json"))
            {
                var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                Assert.Contains(errors, error => error.GetProperty("Stage").GetString() == "emitter.constant-qualification");
                Assert.DoesNotContain(errors, error => error.GetProperty("Code").GetString() == "OLD");
                Assert.Contains(report.RootElement.GetProperty("BlockedStages").EnumerateArray(),
                    stage => stage.GetProperty("Stage").GetString() == "default tests");
            }
            Assert.Equal(OldReport(), File.ReadAllText(oldPreflight));
            Assert.False(File.Exists(Path.Combine(generated, "constants-preflight-diagnostics.json")));
            string failedSource = Path.Combine(generated, "obj", "crossarch", "common", "Broken.modified.cs");
            Assert.True(File.Exists(failedSource));
            byte[] failedSourceBytes = File.ReadAllBytes(failedSource);
            Assert.Equal("previous-valid-image", File.ReadAllText(output));
            string unavailableTools = Directory.CreateDirectory(Path.Combine(fixture.Root, "unavailable-tools")).FullName;
            var infrastructureFailure = Run("msbuild", args.Append("-p:ToolsBinDir=" + unavailableTools).ToArray());
            Assert.NotEqual(0, infrastructureFailure.ExitCode);
            using (var report = fixture.Report(@"obj\generated\generation-failures.json"))
            {
                var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                Assert.Single(errors);
                Assert.Equal("WMG999", errors[0].GetProperty("Code").GetString());
                Assert.Equal("EmitWinmd", errors[0].GetProperty("Stage").GetString());
            }
            Assert.Equal(failedSourceBytes, File.ReadAllBytes(failedSource));
            Assert.Equal("previous-valid-image", File.ReadAllText(output));
            File.WriteAllText(broken, "namespace Test { public static class Apis { public const int BAD = 9; public const int GOOD = 7; } }");
            var accepted = Run("msbuild", args);
            Assert.True(accepted.ExitCode == 0, accepted.Output);
            Assert.False(File.Exists(Path.Combine(generated, "generation-failures.json")));
            Assert.False(File.Exists(Path.Combine(generated, "generation-diagnostics.json")));
            Assert.False(File.Exists(oldPreflight));
            Assert.True(File.Exists(unrelated));
            using var image = new PEReader(File.OpenRead(output));
            var reader = image.GetMetadataReader();
            Assert.Contains(reader.FieldDefinitions, field => reader.GetString(reader.GetFieldDefinition(field).Name) == "BAD");
            Assert.Empty(Directory.GetFiles(fixture.Root, "*.pending", SearchOption.AllDirectories));
            string marker = fixture.Write(@"obj\generated\constants.scraped.txt", "current valid inputs");
            File.SetLastWriteTimeUtc(marker, File.GetLastWriteTimeUtc(output).AddMinutes(-1));
            fixture.Write(@"obj\generated\generation-failures.json", OldReport());
            fixture.Write(@"obj\generated\emitter-preflight-diagnostics.json", OldReport());
            var unchanged = Run("msbuild", args);
            Assert.True(unchanged.ExitCode == 0, unchanged.Output);
            Assert.DoesNotContain("Writing winmd", unchanged.Output);
            Assert.False(File.Exists(Path.Combine(generated, "generation-failures.json")));
            Assert.False(File.Exists(oldPreflight));
            Assert.True(File.Exists(unrelated));
        }

        [Fact]
        public void MalformedReportSchemasDoNotAbortLaterIndependentImports()
        {
            using var fixture = new Fixture();
            string valid = JsonSerializer.Serialize(new
            {
                Version = 1, Status = "rejected",
                Errors = new[] { new GenerationValidationError("LATER", "emitter.preflight", "later independent error") { Cause = "retained later cause" } },
                BlockedStages = Array.Empty<BlockedGenerationStage>(),
            });
            fixture.Write("emitter-preflight-diagnostics.json", valid);
            string[] malformed =
            {
                "[]",
                "{\"Version\":1,\"Errors\":[],\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":{},\"Errors\":[],\"BlockedStages\":[]}",
                valid.Replace("\"Version\":1", "\"Version\":2"),
                valid.Replace("\"Status\":\"rejected\"", "\"Status\":\"unknown\""),
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":{},\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[false],\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[{\"Code\":7}],\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[],\"Reports\":{},\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[],\"Reports\":[false],\"BlockedStages\":[]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[],\"BlockedStages\":{}}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[],\"BlockedStages\":[false]}",
                "{\"Version\":1,\"Status\":\"rejected\",\"Errors\":[],\"BlockedStages\":[{\"Stage\":1,\"Dependency\":\"input\"}]}",
                valid.Replace("\"Line\":null", "\"Line\":{}"),
                valid.Replace("\"Status\":\"rejected\"", "\"Status\":\"completed\""),
            };
            foreach (string contents in malformed)
            {
                string input = fixture.Write("scrape-diagnostics.json", contents);
                var task = new CollectGenerationDiagnostics { BuildEngine = new BuildEngine(),
                    GeneratedDir = fixture.Root, FailedStage = "ScrapeHeaders" };
                Assert.False(task.Execute());
                using var report = fixture.Report("generation-failures.json");
                var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                Assert.Contains(errors, error => error.GetProperty("Code").GetString() == "WMG999" &&
                    error.GetProperty("Input").GetString() == input &&
                    error.GetProperty("Cause").GetString().Contains("JsonException"));
                Assert.Contains(errors, error => error.GetProperty("Code").GetString() == "LATER" &&
                    error.GetProperty("Cause").GetString() == "retained later cause");
                Assert.Contains(report.RootElement.GetProperty("Reports").EnumerateArray(),
                    reference => reference.GetString() == input);
            }
        }

        [Fact]
        public void LibraryInputsCollectIndependentFailuresWithoutPublishingPartialSettings()
        {
            using var fixture = new Fixture();
            string truncated = fixture.Write("first.lib", "short");
            string invalid = fixture.Write("second.lib", "not a library archive");
            string missing = Path.Combine(fixture.Root, "last-missing.lib");
            string valid = fixture.Write("valid.lib", "!<arch>\n");
            string output = fixture.Write("withLibs.rsp", "previous settings");
            var task = new ScanLibs { BuildEngine = new BuildEngine(), WithLibsRsp = output,
                MSBuildProjectDirectory = fixture.Root, LibToolsBinDir = fixture.Root,
                Libs = new[] { truncated, invalid, missing, valid }.Select(path => (ITaskItem)new TaskItem(path)).ToArray() };
            Assert.False(task.Execute());
            Assert.False(File.Exists(output));
            using (var report = fixture.Report("library-input-diagnostics.json"))
            {
                var errors = report.RootElement.GetProperty("Errors").EnumerateArray().ToArray();
                Assert.Equal(3, errors.Length);
                foreach (string input in new[] { truncated, invalid, missing })
                    Assert.Contains(errors, error => error.GetProperty("Input").GetString() == input);
            }
            task.Libs = new[] { new TaskItem(valid) };
            Assert.True(task.Execute());
            Assert.False(File.Exists(Path.Combine(fixture.Root, "library-input-diagnostics.json")));
        }

        [Fact]
        public void ValidDefaultCliStillWritesAllConstantsAndPhysicalMetadata()
        {
            using var fixture = new Fixture();
            string header = fixture.Write("input.h", "#define FIRST 1\n#define LAST 9\n");
            fixture.Write("Metadata.manual.cs", File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "Metadata.cs")));
            string[] arguments = { "--scraperOutputDir", fixture.Root, "--defaultNamespace", "Test",
                "--traversedFileToNamespace", header + "=Test" };
            Assert.Equal(0, Run(typeof(ConstantsScraperApp.Program).Assembly.Location, arguments).ExitCode);
            string source = File.ReadAllText(Path.Combine(fixture.Root, "Test.constants.cs"));
            Assert.Contains("FIRST = 1", source);
            Assert.Contains("LAST = 9", source);
            Assert.Equal(0, Run(typeof(ConstantsScraperApp.Program).Assembly.Location, arguments).ExitCode);
            Assert.Equal(source, File.ReadAllText(Path.Combine(fixture.Root, "Test.constants.cs")));
            fixture.Write("generation-failures.json", "previous rejected generation");
            string output = Path.Combine(fixture.Root, "output.winmd");
            var result = Run(typeof(ClangSharpSourceToWinmd.Program).Assembly.Location,
                "--sourceDir", fixture.Root, "--arch", "x64", "--outputFileName", output);
            Assert.True(result.ExitCode == 0, result.Output);
            using var image = new PEReader(File.OpenRead(output));
            var reader = image.GetMetadataReader();
            var fields = reader.FieldDefinitions.Select(reader.GetFieldDefinition)
                .Where(field => reader.GetString(field.Name) is "FIRST" or "LAST").ToArray();
            Assert.Equal(2, fields.Length);
            Assert.All(fields, field => Assert.False(field.GetDefaultValue().IsNil));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "generation-diagnostics.json")));
            Assert.False(File.Exists(Path.Combine(fixture.Root, "generation-failures.json")));
        }

        private static ClangSharpSourceCompilation Compile(string root, string arch) => ClangSharpSourceCompilation.Create(
            root, arch, new(), new(), Array.Empty<string>(), new(), new(), new(), Array.Empty<string>(), new(), new());

        private static string OldReport() => JsonSerializer.Serialize(new
        {
            Version = 1, Status = "rejected",
            Errors = new[] { new GenerationValidationError("OLD", "old invocation", "unrelated retained failure") { Cause = "retained cause" } },
            BlockedStages = Array.Empty<BlockedGenerationStage>(),
        });

        private static (int ExitCode, string Output) Run(string tool, params string[] arguments)
        {
            var start = new ProcessStartInfo("dotnet") { UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true };
            start.ArgumentList.Add(tool);
            foreach (string argument in arguments)
                start.ArgumentList.Add(argument);
            using var process = Process.Start(start);
            var stdout = process.StandardOutput.ReadToEndAsync();
            var stderr = process.StandardError.ReadToEndAsync();
            if (!process.WaitForExit(30000))
            {
                process.Kill(entireProcessTree: true);
                throw new TimeoutException("Compact diagnostic CLI fixture did not finish in 30 seconds.");
            }
            return (process.ExitCode, stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult());
        }

        private sealed class Fixture : IDisposable
        {
            internal string Root { get; } = Path.Combine(Environment.CurrentDirectory, ".diagnostic-tests", Guid.NewGuid().ToString("N"));
            internal Fixture() => Directory.CreateDirectory(Root);
            internal string Write(string path, string content)
            {
                path = Path.Combine(Root, path);
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(path, content);
                return path;
            }
            internal JsonDocument Report(string path) => JsonDocument.Parse(File.ReadAllText(Path.Combine(Root, path)));
            public void Dispose() => Directory.Delete(Root, recursive: true);
        }

        private sealed class JobTask : ScrapeHeaders
        {
            internal ConcurrentQueue<string> Visited { get; } = new();
            internal bool Run(string root, params string[] names)
            {
                Visited.Clear();
                var jobs = names.Select(name =>
                {
                    var item = new TaskItem(name + ".cpp");
                    item.SetMetadata("Name", name);
                    item.SetMetadata("Namespace", "Test");
                    return (Partition.FromTaskItem(item, root, root), "x64");
                });
                return ProcessPartitionJobs(jobs, new System.Threading.Tasks.ParallelOptions { MaxDegreeOfParallelism = 1 });
            }
            internal bool RunInvalidPlanning(string root)
            {
                Visited.Clear();
                MSBuildProjectDirectory = root;
                Partitions = new[] { "InvalidFirst", "InvalidLast", "Later" }.Select(name =>
                {
                    var item = new TaskItem(name + ".cpp");
                    item.SetMetadata("Name", name);
                    if (name == "Later")
                        item.SetMetadata("Namespace", "Test");
                    return (ITaskItem)item;
                }).ToArray();
                var validation = new GenerationValidation();
                var jobs = GetPartitions(validation).Select(partition => (partition, "x64"));
                return ProcessPartitionJobs(jobs, new System.Threading.Tasks.ParallelOptions { MaxDegreeOfParallelism = 1 }, validation);
            }
            protected override bool ProcessPartition(Partition partition, string arch)
            {
                Visited.Enqueue(partition.Name);
                if (partition.Name == "Validation")
                    throw new InvalidDataException("Independent partition input validation failed.");
                if (partition.Name == "Unexpected")
                    throw new ApplicationException("Unexpected infrastructure failure.");
                if (partition.Name != "Process")
                    return true;
                Directory.CreateDirectory(Path.Combine(ScratchDir, arch));
                File.WriteAllText(Path.Combine(ScratchDir, arch, "Process.generation.output.txt"), "RAW_NATIVE_ERROR\n");
                return false;
            }
        }

        private sealed class BuildEngine : IBuildEngine
        {
            public bool ContinueOnError => false;
            public int LineNumberOfTaskNode => 0;
            public int ColumnNumberOfTaskNode => 0;
            public string ProjectFileOfTaskNode => "";
            public void LogErrorEvent(BuildErrorEventArgs e) { }
            public void LogWarningEvent(BuildWarningEventArgs e) { }
            public void LogMessageEvent(BuildMessageEventArgs e) { }
            public void LogCustomEvent(CustomBuildEventArgs e) { }
            public bool BuildProjectFile(string projectFileName, string[] targetNames, IDictionary globalProperties,
                IDictionary targetOutputs) => throw new NotSupportedException();
        }
    }
}
