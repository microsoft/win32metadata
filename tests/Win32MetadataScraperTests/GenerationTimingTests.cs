using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    [CollectionDefinition(nameof(GenerationTimingCollection), DisableParallelization = true)]
    public sealed class GenerationTimingCollection
    {
    }

    [Collection(nameof(GenerationTimingCollection))]
    public sealed class GenerationTimingTests : IDisposable
    {
        private readonly string previousDirectory = Environment.GetEnvironmentVariable(GenerationTiming.EnvironmentVariable);
        private readonly string directory = Path.Combine(Path.GetTempPath(), "win32-timing-" + Guid.NewGuid().ToString("N"));

        public GenerationTimingTests()
        {
            Directory.CreateDirectory(directory);
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, null);
        }

        [Fact]
        public void DisabledTimingDoesNotCreateAnOutputOrASession()
        {
            Assert.Null(GenerationTiming.StartFromEnvironment("test"));
            Assert.Null(GenerationTiming.BeginSpan("unused"));
            GenerationTiming.SetContext("unused", "unused");
            Assert.Empty(Directory.EnumerateFileSystemEntries(directory));
        }

        [Theory]
        [InlineData("public class Uses { public int Read(uint value) => 1; }")]
        [InlineData("public unsafe class Uses { public int* Read(byte** value) => null; }")]
        [InlineData("public class Uses { public int[,] Read(bool[] value) => null; }")]
        [InlineData("public class Uses { public ulong Read(string value) => (ulong)42; }")]
        public void PredefinedTypeUsesDoNotCreateNativeProviderSemanticWork(string text)
        {
            string reports = Path.Combine(directory, "reports");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            using (var session = GenerationTiming.StartFromEnvironment("predefined-type-test"))
            {
                var source = GeneratedSource.FromText(text);
                var projection = new OpaqueRecordProjection(null, new[] { source }, new Dictionary<string, string>());
                Assert.Empty(projection.IncludedNames);
                Assert.Empty(projection.RecordAliases);
                session.Complete(0);
            }
            using var report = ReadSingleReport(reports);
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            var counters = discovery.GetProperty("counters");
            Assert.Equal(0, counters.GetProperty("semanticQueryCount").GetInt32());
            Assert.True(counters.GetProperty("predefinedTypeUseCount").GetInt32() > 0);
            Assert.DoesNotContain(spans, span => Name(span) == "native-providers.create-compilation");
        }

        [Fact]
        public void NamedPrimitiveTypeUsesStillRetainSemanticValidation()
        {
            string reports = Path.Combine(directory, "reports");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            using (var session = GenerationTiming.StartFromEnvironment("named-primitive-test"))
            {
                var source = GeneratedSource.FromText("public class Uses { public System.Int32 Read() => 1; }");
                var projection = new OpaqueRecordProjection(null, new[] { source }, new Dictionary<string, string>());
                Assert.Empty(projection.IncludedNames);
                session.Complete(0);
            }
            using var report = ReadSingleReport(reports);
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            Assert.Equal(1, discovery.GetProperty("counters").GetProperty("semanticQueryCount").GetInt32());
            Assert.Single(spans.Where(span => Name(span) == "native-providers.create-compilation"));
        }

        [Fact]
        public void PredefinedTypeFilteringStillBindsAndValidatesCustomAliasPointees()
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords("namespace Test { struct Opaque; }\n");
            string reports = Path.Combine(directory, "reports");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            using (var session = GenerationTiming.StartFromEnvironment("mixed-type-test"))
            {
                var source = GeneratedSource.FromText(@"
using Reference = global::Test.Opaque;
namespace Test
{
    public static unsafe class Apis
    {
        public static Reference* Read(int* value, byte[] bytes) => null;
    }
}");
                var projection = new OpaqueRecordProjection(native.Unit, new[] { source }, new Dictionary<string, string>());
                Assert.Equal(new[] { "Test::Opaque" }, projection.IncludedNames);
                var declaration = NativeConditionalCompanion.Declarations(native.Unit.TranslationUnitDecl)
                    .OfType<ClangSharp.RecordDecl>().Single(record => record.Name == "Opaque");
                declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                string provider = "namespace Test { [SourceLocation(" +
                    SyntaxFactory.Literal(file.ToString()).ToFullString() +
                    $", {line}, {column})] public partial struct Opaque {{ }} }}";
                var retained = projection.SelectRequiredBindings(new Dictionary<string, string> { ["Opaque.cs"] = provider });
                Assert.Contains("struct Opaque", Assert.Single(retained).Value);
                session.Complete(0);
            }
            using var report = ReadSingleReport(reports);
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            var counters = discovery.GetProperty("counters");
            Assert.Equal(1, counters.GetProperty("semanticQueryCount").GetInt32());
            Assert.Equal(2, counters.GetProperty("predefinedTypeUseCount").GetInt32());
            Assert.Single(spans.Where(span => Name(span) == "native-providers.create-compilation"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", 16)]
        [InlineData("x64", "x86_64-pc-windows-msvc", 512)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", 128)]
        public void GeneratedSourcePassesShareOneParseAndOneFinalFormat(string architecture, string target, int count)
        {
            string declarations = string.Join("\n", Enumerable.Range(0, count).Select(index =>
                $"struct Record{index} {{ int value; }};\n" +
                $"_Win32_SetLastError_ int Read{index}(/* [in] */ Record{index}* value);"));
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, declarations,
                directoryRoot: directory);
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, Path.Combine(directory, "reports"));
            fixture.AssertSuccess();
            using var report = ReadSingleReport(Path.Combine(directory, "reports"));
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var parse = Assert.Single(spans.Where(span => Name(span) == "projection.parse-generated-source"));
            Assert.Equal(1, parse.GetProperty("counters").GetProperty("parseCount").GetInt32());
            var format = Assert.Single(spans.Where(span => Name(span) == "projection.format-generated-source"));
            Assert.Equal(1, format.GetProperty("counters").GetProperty("formatCount").GetInt32());
            Assert.Contains(spans, span => Name(span) == "native-providers.recover");
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            var counters = discovery.GetProperty("counters");
            Assert.Equal(count, counters.GetProperty("semanticQueryCount").GetInt32());
            Assert.Equal(count * 2, counters.GetProperty("predefinedTypeUseCount").GetInt32());
            var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            var methods = root.DescendantNodes().OfType<MethodDeclarationSyntax>().ToArray();
            Assert.Equal(count, methods.Length);
            Assert.Equal(count, root.DescendantNodes().OfType<StructDeclarationSyntax>().Count());
            foreach (var method in methods)
            {
                Assert.Contains("SetLastError = true", method.AttributeLists.ToString());
                Assert.Contains("InteropServices.In", Assert.Single(method.ParameterList.Parameters).AttributeLists.ToString());
            }
            Assert.DoesNotContain(root.DescendantNodes().OfType<AttributeSyntax>(),
                attribute => attribute.Name.ToString() is "SourceLocation" or "NativeAnnotation");
        }

        [Fact]
        public void InferredTypeUsesRetainSemanticValidation()
        {
            using var native = new OpaqueRecordProjectionTests.NativeRecords("struct Unmentioned;\n");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, Path.Combine(directory, "reports"));
            using (var session = GenerationTiming.StartFromEnvironment("inferred-type-test"))
            {
                var source = GeneratedSource.FromText("public class Uses { public void Read() { var value = 1; } }");
                var projection = new OpaqueRecordProjection(native.Unit, new[] { source }, new Dictionary<string, string>());
                Assert.Empty(projection.IncludedNames);
                session.Complete(0);
            }
            using var report = ReadSingleReport(Path.Combine(directory, "reports"));
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            var counters = discovery.GetProperty("counters");
            Assert.True(counters.GetProperty("semanticQueryCount").GetInt32() > 0);
            Assert.Single(spans.Where(span => Name(span) == "native-providers.create-compilation"));
        }

        [Fact]
        public void RequiredOpaqueProvidersRetainSemanticValidationAndSharedSourceParsing()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "struct Opaque;\nOpaque* Read();\n", extraSettings: "--config\nexclude-empty-records\n",
                directoryRoot: directory);
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, Path.Combine(directory, "reports"));
            fixture.AssertSuccess();
            using var report = ReadSingleReport(Path.Combine(directory, "reports"));
            ValidateReport(report.RootElement);
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var discovery = Assert.Single(spans.Where(span => Name(span) == "native-providers.discover"));
            Assert.True(discovery.GetProperty("counters").GetProperty("semanticQueryCount").GetInt32() > 0);
            Assert.Single(spans.Where(span => Name(span) == "native-providers.create-compilation"));
            Assert.Equal(2, spans.Count(span => Name(span) == "projection.parse-generated-source"));
            var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            Assert.Equal("Opaque", Assert.Single(root.DescendantNodes().OfType<StructDeclarationSyntax>()).Identifier.ValueText);
            Assert.Equal("Opaque*", Assert.Single(root.DescendantNodes().OfType<MethodDeclarationSyntax>()).ReturnType.ToString());
        }

        [Fact]
        public void ReportPreservesHierarchyRawCountersAndExclusiveTimes()
        {
            string reports = Path.Combine(directory, "reports");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            string path;
            using (var session = GenerationTiming.StartFromEnvironment("timing-test"))
            {
                path = session.OutputPath;
                GenerationTiming.SetContext("target", "x64");
                using (var batch = GenerationTiming.BeginSpan("batch"))
                {
                    batch.SetCounter("candidateCount", 4097);
                    for (int i = 0; i < 2; i++)
                    {
                        using var parse = GenerationTiming.BeginSpan("parse");
                        parse.SetCounter("parseCount", 1);
                        Thread.SpinWait(100000);
                        Thread.Sleep(1);
                    }
                }
                session.Complete(0);
            }
            using var report = JsonDocument.Parse(File.ReadAllText(path));
            ValidateReport(report.RootElement);
            Assert.Equal(0, report.RootElement.GetProperty("exitCode").GetInt32());
            Assert.Equal("x64", report.RootElement.GetProperty("context").GetProperty("target").GetString());
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            Assert.Equal(4, spans.Length);
            Assert.Equal(4097, spans.Single(span => Name(span) == "batch")
                .GetProperty("counters").GetProperty("candidateCount").GetInt32());
        }

        [Theory]
        [InlineData("relative-timing")]
        [InlineData(" ")]
        [InlineData(@"\\server\share\timing")]
        public void InvalidOptInIsRejectedWithoutOutput(string path)
        {
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, path);
            Assert.Throws<ArgumentException>(() => GenerationTiming.StartFromEnvironment("test"));
            Assert.Null(GenerationTiming.BeginSpan("unused"));
            Assert.Empty(Directory.EnumerateFileSystemEntries(directory));
        }

        [Fact]
        public void NestedSessionsAndOutOfOrderSpansFailExplicitly()
        {
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, directory);
            using var session = GenerationTiming.StartFromEnvironment("test");
            Assert.Throws<InvalidOperationException>(() => GenerationTiming.StartFromEnvironment("other"));
            using var parent = GenerationTiming.BeginSpan("parent");
            using var child = GenerationTiming.BeginSpan("child");
            Assert.Throws<InvalidOperationException>(() => parent.Dispose());
            child.Dispose();
            parent.Dispose();
            session.Complete(0);
        }

        [Fact]
        public void ExceptionUnwindingRetainsAValidIncompleteTrace()
        {
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, directory);
            Assert.Throws<InvalidOperationException>(Fail);
            using var report = ReadSingleReport(directory);
            ValidateReport(report.RootElement);
            Assert.Equal(JsonValueKind.Null, report.RootElement.GetProperty("exitCode").ValueKind);
            Assert.Null(GenerationTiming.BeginSpan("unused"));

            static void Fail()
            {
                using var session = GenerationTiming.StartFromEnvironment("test");
                using var span = GenerationTiming.BeginSpan("failure");
                throw new InvalidOperationException("fixture");
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void NativeTimingPreservesEveryOutputDiagnosticAndProbePolicy(string architecture, string target, bool recursive)
        {
            string source = recursive ? @"
template<int N> constexpr int Poison() { static_assert(N > 0, ""timing probe rejection""); return N; }
#define TIMING_VALUE 4U
#define TIMING_POISON Poison<-1>()
" : @"
#define TIMING_VALUE 4U
#define TIMING_BAD MISSING_TIMING_VALUE
#define TIMING_TEXT ""text""
enum _Win32_AssociatedConstant_(TIMING_VALUE) TIMING_FLAGS { TIMING_FIRST = 1 };
struct NativeHandle__;
_Win32_NativeTypedef_ typedef struct NativeHandle__* NATIVE_HANDLE;
[[nodiscard]] NATIVE_HANDLE TimingProbe();
#ifndef UNICODE
extern ""C"" int TimingAnsi(char* text);
#endif
";
            string settings = recursive ? "--config\nnative-constants-only\n" :
                "--config\nnative-constant-values\nexclude-empty-records\n--additional\n-DUNICODE\n" +
                "--with-librarypath\nTimingAnsi=scan.dll\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, source,
                extraSettings: settings, directoryRoot: directory);
            int baseline = fixture.Run();
            if (recursive)
                Assert.True(baseline == 0, fixture.Diagnostics);
            else
                fixture.AssertGeneratorWarnings(baseline, "WarnUnusedResult");
            string diagnostics = fixture.Diagnostics;
            var outputs = ReadOutputs(fixture.DirectoryPath);
            string reports = Path.Combine(directory, "reports");
            Assert.False(Directory.Exists(reports));
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            Assert.Equal(baseline, fixture.Run());
            Assert.Equal(diagnostics, fixture.Diagnostics);
            AssertSameOutputs(outputs, ReadOutputs(fixture.DirectoryPath));
            using var report = ReadSingleReport(reports);
            ValidateReport(report.RootElement);
            Assert.Equal(baseline, report.RootElement.GetProperty("exitCode").GetInt32());
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            var extraction = Assert.Single(spans.Where(span => Name(span) == "native-constants.extract"));
            var counters = extraction.GetProperty("counters");
            Assert.Equal(recursive ? 2 : 3, counters.GetProperty("candidateCount").GetInt32());
            Assert.Equal(1, counters.GetProperty("acceptedCount").GetInt32());
            Assert.Equal(recursive ? 1 : 2, counters.GetProperty("rejectedCount").GetInt32());
            Assert.Equal(0, counters.GetProperty("parseCount").GetInt32());
            Assert.Equal(0, counters.GetProperty("retrySplitCount").GetInt32());
            Assert.Contains(spans, span => Name(span) == "native-constants.scan-names");
            Assert.Contains(spans, span => Name(span) == "native-constants.build-probe-source");
            Assert.DoesNotContain(spans, span => Name(span) == "native-constants.probe-parse" ||
                Name(span) == "native-constants.recursive-retry");
            Assert.True(spans.Length < 256);
            if (recursive)
            {
                var issue = Assert.Single(NativeConstantExtractionTests.Read(fixture).Issues);
                Assert.Equal("native diagnostic", issue.Reason);
                Assert.NotEmpty(issue.Diagnostics);
            }
            else
                foreach (string name in new[] { "translation-unit.original", "translation-unit.declarations",
                    "remap-discovery", "annotations.discovery", "annotations.apply-to-source",
                    "annotations.native-type-providers", "companion.parse", "translation-unit.companion",
                    "pinvoke.bindings", "pinvoke.companion-bindings", "native-providers.recover",
                    "output.serialize-native-constants", "output.generated-files" })
                    Assert.Contains(spans, span => Name(span) == name);
        }

        [Fact]
        public void AggregationTimingPreservesNativeAndLegacyOutputs()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define TIMING_VALUE (1U << 4)
#define TIMING_ALIAS TIMING_VALUE
#define TIMING_TEXT ""timing""
int TimingProbe();
", extraSettings: "--config\nnative-constant-values\n", directoryRoot: directory);
            fixture.AssertSuccess();
            var baseline = RunConstants(fixture);
            Assert.True(baseline.ExitCode == 0, baseline.Output);
            var outputs = ReadOutputs(fixture.DirectoryPath);
            string reports = Path.Combine(directory, "reports");
            Assert.False(Directory.Exists(reports));
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            Assert.Equal(baseline, RunConstants(fixture));
            AssertSameOutputs(outputs, ReadOutputs(fixture.DirectoryPath));
            using var report = ReadSingleReport(reports);
            ValidateReport(report.RootElement);
            Assert.Equal("constants-scraper", report.RootElement.GetProperty("tool").GetString());
            var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
            foreach (string name in new[] { "constants.aggregate", "constants.load-existing-source",
                "constants.load-native-facts", "constants.load-source-owners", "constants.resolve-ownership-types-aliases",
                "constants.write-native-csharp", "constants.legacy-text-and-streaming-csharp",
                "constants.resolve-legacy-aliases", "constants.write-conflict-report",
                "constants.write-enums-remaps", "constants.flush-csharp-writers" })
                Assert.Contains(spans, span => Name(span) == name);
            Assert.DoesNotContain(spans, span => Name(span).Contains("probe-parse", StringComparison.Ordinal));
        }

        [Fact]
        public void UnwritableOptInFailsBothCommandsBeforeProducingNativeOutputs()
        {
            string file = Path.Combine(directory, "not-a-directory");
            File.WriteAllText(file, "fixture");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, file);
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define TIMING_VALUE 4U\nint TimingProbe();",
                extraSettings: "--config\nnative-constant-values\n", directoryRoot: directory);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Local generation timing failed", fixture.Diagnostics);
            Assert.Contains("not-a-directory", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".native-constants.json")));
            var constants = RunConstants(fixture);
            Assert.NotEqual(0, constants.ExitCode);
            Assert.Contains("Failed to record local generation timing", constants.Output);
            Assert.Contains("not-a-directory", constants.Output);
        }

        private static (int ExitCode, string Output) RunConstants(HeaderAnnotationTests.NativeFixture fixture)
        {
            var start = new ProcessStartInfo("dotnet")
            {
                WorkingDirectory = fixture.DirectoryPath,
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
            };
            foreach (string argument in new[] { Path.Combine(AppContext.BaseDirectory, "ConstantsScraper.dll"),
                "--defaultNamespace", "Test", "--scraperOutputDir", fixture.DirectoryPath,
                "--headerTextFile", Path.Combine(AppContext.BaseDirectory, "assets", "scraper.header.txt"),
                "--traversedFileToNamespace", fixture.Header + "=Test" })
                start.ArgumentList.Add(argument);
            using var process = Process.Start(start);
            var stdout = process.StandardOutput.ReadToEndAsync();
            var stderr = process.StandardError.ReadToEndAsync();
            process.WaitForExit();
            return (process.ExitCode, stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult());
        }

        private static Dictionary<string, byte[]> ReadOutputs(string root) =>
            Directory.GetFiles(root, "*", SearchOption.AllDirectories)
                .Where(path => path.EndsWith(".cs", StringComparison.Ordinal) ||
                    path.EndsWith(".json", StringComparison.Ordinal) || path.EndsWith(".rsp", StringComparison.Ordinal) ||
                    Path.GetFileName(path) == "remaps.txt")
                .ToDictionary(path => Path.GetRelativePath(root, path), File.ReadAllBytes, StringComparer.Ordinal);

        private static void AssertSameOutputs(Dictionary<string, byte[]> first, Dictionary<string, byte[]> second)
        {
            Assert.Equal(first.Keys.OrderBy(value => value, StringComparer.Ordinal),
                second.Keys.OrderBy(value => value, StringComparer.Ordinal));
            foreach (var pair in first)
                Assert.Equal(pair.Value, second[pair.Key]);
        }

        private static JsonDocument ReadSingleReport(string reports) =>
            JsonDocument.Parse(File.ReadAllText(Assert.Single(Directory.GetFiles(reports, "*.timing.json"))));

        private static string Name(JsonElement span) => span.GetProperty("name").GetString();

        private static void ValidateReport(JsonElement report)
        {
            Assert.Equal(1, report.GetProperty("schemaVersion").GetInt32());
            Assert.Equal("all-process-threads", report.GetProperty("cpuScope").GetString());
            Assert.True(report.GetProperty("processId").GetInt32() > 0);
            _ = report.GetProperty("startedUtc").GetDateTime();
            var spans = report.GetProperty("spans").EnumerateArray().ToArray();
            Assert.NotEmpty(spans);
            Assert.Equal(JsonValueKind.Null, spans[0].GetProperty("parentId").ValueKind);
            Assert.Equal(Enumerable.Range(1, spans.Length), spans.Select(span => span.GetProperty("id").GetInt32()));
            foreach (var span in spans)
            {
                int id = span.GetProperty("id").GetInt32();
                double start = span.GetProperty("startedMilliseconds").GetDouble();
                double wall = span.GetProperty("wallMilliseconds").GetDouble();
                double cpu = span.GetProperty("processCpuMilliseconds").GetDouble();
                foreach (string name in new[] { "startedMilliseconds", "wallMilliseconds", "processCpuMilliseconds",
                    "childWallMilliseconds", "selfWallMilliseconds", "selfProcessCpuMilliseconds" })
                {
                    double value = span.GetProperty(name).GetDouble();
                    Assert.True(double.IsFinite(value) && value >= 0, name + ": " + value);
                }
                var children = spans.Where(child => child.GetProperty("parentId").ValueKind != JsonValueKind.Null &&
                    child.GetProperty("parentId").GetInt32() == id).ToArray();
                double childWall = children.Sum(child => child.GetProperty("wallMilliseconds").GetDouble());
                double childCpu = children.Sum(child => child.GetProperty("processCpuMilliseconds").GetDouble());
                Assert.InRange(Math.Abs(childWall - span.GetProperty("childWallMilliseconds").GetDouble()), 0, 0.001);
                Assert.InRange(Math.Abs(wall - childWall - span.GetProperty("selfWallMilliseconds").GetDouble()), 0, 0.001);
                Assert.InRange(Math.Abs(cpu - childCpu - span.GetProperty("selfProcessCpuMilliseconds").GetDouble()), 0, 0.001);
                if (id != 1)
                {
                    int parentId = span.GetProperty("parentId").GetInt32();
                    Assert.InRange(parentId, 1, id - 1);
                    var parent = spans[parentId - 1];
                    Assert.True(start >= parent.GetProperty("startedMilliseconds").GetDouble());
                    Assert.True(start + wall <= parent.GetProperty("startedMilliseconds").GetDouble() +
                        parent.GetProperty("wallMilliseconds").GetDouble() + 0.001);
                }
                foreach (var counter in span.GetProperty("counters").EnumerateObject())
                    Assert.True(counter.Value.GetInt64() >= 0);
            }
        }

        public void Dispose()
        {
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, previousDirectory);
            Directory.Delete(directory, recursive: true);
        }
    }
}
