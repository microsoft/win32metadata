using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using TestCommon;
using WinmdUtilsProgram;
using Xunit;

namespace MetadataUtils.Tests
{
    public class WinmdReviewBatchTests
    {
        [Theory]
        [InlineData("Fixture.Apis.Compute : parameter 1 (value) : [In] => [In,Optional]", "direction-sal", "[In]", "[In,Optional]")]
        [InlineData("Fixture.Apis.Compute : parameter 1 (value) : [Out] => [NativeArrayInfo(CountParamIndex=2),Out]", "association-array", "[Out]", "[NativeArrayInfo(CountParamIndex=2),Out]")]
        [InlineData("Fixture.Apis.Compute : return :  => [RAIIFree(Close)]", "availability-ownership", "", "[RAIIFree(Close)]")]
        [InlineData("Fixture.Apis.Compute : [SupportedOSPlatform(windows8.0)] => [SupportedOSPlatform(windows10.0)]", "availability-ownership", "[SupportedOSPlatform(windows8.0)]", "[SupportedOSPlatform(windows10.0)]")]
        [InlineData("Fixture.Apis.Compute : parameter 1 (value)...Fixture.Handle => System.IntPtr", "type-signature-enum-identity", "Fixture.Handle", "System.IntPtr")]
        [InlineData("winmd1: Fixture.Apis.VALUE = -1, winmd2 = 2", "values", "-1", "2")]
        [InlineData("Fixture.Handle removed", "removals", "Fixture.Handle", null)]
        [InlineData("Fixture.Handle added", "additions", null, "Fixture.Handle")]
        [InlineData("Fixture.Apis.VALUE value init changed Int32->UInt32", "type-signature-enum-identity", "Int32", "UInt32")]
        [InlineData("Fixture.Handle => Other.Handle", "type-signature-enum-identity", "Fixture.Handle", "Other.Handle")]
        public void ClassifiesWithoutChangingRawValues(string raw, string family, string oldText, string newText)
        {
            var row = Assert.Single(WinmdReviewBatch.Parse("Unknown differences found:\r\n" + raw + "\r\n"));
            Assert.Equal(raw, row.RawLine);
            Assert.Equal(2, row.RawLineNumber);
            Assert.Equal(family, row.Family);
            Assert.Equal(oldText, row.OldText);
            Assert.Equal(newText, row.NewText);
        }

        [Theory]
        [InlineData("")]
        [InlineData("Unknown differences found:")]
        [InlineData("Unknown differences found:\n\n")]
        [InlineData("Unhandled exception: bad metadata")]
        [InlineData("Items from the known differences file that were not used:\nwaiver\nUnknown differences found:\nchange")]
        [InlineData("Unknown differences found:\nchange\nNo unknown differences found.")]
        public void RejectsIncompleteErrorsOrWaiverReports(string raw)
        {
            Assert.Throws<InvalidDataException>(() => WinmdReviewBatch.Parse(raw));
        }

        [Fact]
        public void StableIdsPreserveDuplicateMultiplicityAcrossShardsAndUnrelatedReordering()
        {
            const string first = "winmd1: Fixture.Apis.VALUE = 1, winmd2 = 2";
            const string second = "Fixture.Apis.Compute : parameter 1 (value) : [In] => [In,Optional]";
            var before = WinmdReviewBatch.Parse("Unknown differences found:\n" + first + "\n" + second + "\n" + first);
            var after = WinmdReviewBatch.Parse("Unknown differences found:\n" + second + "\n" + first + "\n" + first);
            Assert.Equal(before.Select(d => d.Id).OrderBy(s => s), after.Select(d => d.Id).OrderBy(s => s));
            Assert.Equal(3, before.Select(d => d.Id).Distinct().Count());
            Assert.Equal(new[] { 1, 2 }, before.Where(d => d.RawLine == first).Select(d => d.DuplicateOrdinal));
        }

        [Theory]
        [InlineData(0)]
        [InlineData(1)]
        [InlineData(499)]
        [InlineData(500)]
        [InlineData(1000)]
        [InlineData(1001)]
        [InlineData(8843)]
        public void BalancedShardsAreDisjointLosslessAndNeverAcceptDifferences(int count)
        {
            using var fixture = new Fixture();
            string[] raw = Enumerable.Range(1, count).Select(n =>
                $"Fixture.Apis.Compute : parameter {n} (value) : [In] => [In,Optional]").ToArray();
            fixture.WriteLog(count == 0 ? "No unknown differences found.\r\n" :
                "Unknown differences found:\r\n" + string.Join("\r\n", raw) + "\r\n");
            var options = fixture.Options();
            string manifestPath = WinmdReviewBatch.Create(options);
            using var manifest = JsonDocument.Parse(File.ReadAllText(manifestPath));
            Assert.Equal(count, manifest.RootElement.GetProperty("rawDifferences").GetInt32());
            Assert.False(manifest.RootElement.GetProperty("imageAcceptance").GetBoolean());
            Assert.Equal(0, manifest.RootElement.GetProperty("normalizedOrDroppedDifferences").GetInt32());
            Assert.Equal(File.ReadAllBytes(fixture.Log),
                File.ReadAllBytes(Path.Combine(options.OutputDirectory, "comparison.raw.log")));
            var inventory = ReadJsonLines(Path.Combine(options.OutputDirectory, "inventory.jsonl"));
            try
            {
                Assert.Equal(raw, inventory.Select(d => d.RootElement.GetProperty("rawLine").GetString()));
                string[] inventoryIds = inventory.Select(d => d.RootElement.GetProperty("id").GetString()).ToArray();
                var sharded = Directory.GetFiles(Path.Combine(options.OutputDirectory, "shards"), "*.jsonl")
                    .SelectMany(ReadJsonLines).ToArray();
                try
                {
                    Assert.Equal(count, sharded.Length);
                    Assert.Equal(count, sharded.Select(d => d.RootElement.GetProperty("id").GetString()).Distinct().Count());
                    Assert.Equal(inventoryIds.OrderBy(s => s),
                        sharded.Select(d => d.RootElement.GetProperty("id").GetString()).OrderBy(s => s));
                    foreach (var shard in manifest.RootElement.GetProperty("shards").EnumerateArray())
                        Assert.InRange(shard.GetProperty("count").GetInt32(), count < 500 ? 1 : 500, 1000);
                    Assert.All(sharded, d => Assert.Equal("unreviewed", d.RootElement.GetProperty("reviewStatus").GetString()));
                }
                finally
                {
                    foreach (var item in sharded)
                        item.Dispose();
                }
                Assert.All(inventory, d => Assert.NotEmpty(d.RootElement.GetProperty("oldMetadataKeys").EnumerateArray()));
            }
            finally
            {
                foreach (var item in inventory)
                    item.Dispose();
            }
        }

        [Fact]
        public void PhysicalAndSourceEvidenceRetainOrderedCompleteSlotsAndMissingEvidence()
        {
            using var fixture = new Fixture();
            fixture.WriteLog("Unknown differences found:\nFixture.Apis.Compute : parameter 1 (value) : [In] => [In,Optional]\nFixture.Missing removed\n");
            var options = fixture.Options();
            WinmdReviewBatch.Create(options);
            var old = ReadJsonLines(Path.Combine(options.OutputDirectory, "metadata-old.jsonl"));
            var sources = ReadJsonLines(Path.Combine(options.OutputDirectory, "source-index.jsonl"));
            try
            {
                var method = Assert.Single(old).RootElement.GetProperty("methods")[0];
                Assert.Equal("Compute", method.GetProperty("name").GetString());
                Assert.Equal("fixture.dll", method.GetProperty("import").GetProperty("module").GetString());
                var parameters = method.GetProperty("parameters").EnumerateArray().ToArray();
                Assert.Equal(new[] { 1, 2 }, parameters.Select(p => p.GetProperty("sequence").GetInt32()));
                Assert.Equal(new[] { "value", "size" }, parameters.Select(p => p.GetProperty("name").GetString()));
                Assert.NotEmpty(method.GetProperty("signature").GetString());
                Assert.Equal(2, sources.Length);
                Assert.Equal("missing", sources.Single(s => s.RootElement.GetProperty("key").GetString() == "Fixture.Missing")
                    .RootElement.GetProperty("generatedResolution").GetString());
                var found = sources.Single(s => s.RootElement.GetProperty("key").GetString() == "Fixture.Apis.Compute").RootElement;
                Assert.Equal("exact-syntax-identity", found.GetProperty("generatedResolution").GetString());
                var header = Assert.Single(found.GetProperty("nativeHeaderCandidates").EnumerateArray());
                Assert.Equal(WinmdReviewBatch.HashFile(fixture.Header), header.GetProperty("sha256").GetString());
                Assert.Contains("not-declaration-proof", found.GetProperty("nativeResolution").GetString());
            }
            finally
            {
                foreach (var item in old.Concat(sources))
                    item.Dispose();
            }
        }

        [Fact]
        public void KnownRepresentationHoldsAreNotWaiversAndKeepAllMatchingRawRecords()
        {
            using var fixture = new Fixture();
            fixture.WriteLog("Unknown differences found:\nFixture.Handle removed\nFixture.Apis.Compute : return...Fixture.Handle => System.IntPtr\n");
            string blockers = Path.Combine(fixture.Root, "blockers.json");
            File.WriteAllText(blockers, "[{\"id\":\"native-typedef-loss\",\"symbols\":[\"Fixture.Handle\"],\"reason\":\"Unaccepted native typedef identity loss\"}]");
            var options = fixture.Options();
            options.Blockers = blockers;
            WinmdReviewBatch.Create(options);
            using var holds = JsonDocument.Parse(File.ReadAllText(Path.Combine(options.OutputDirectory, "blockers.json")));
            Assert.Equal("unaccepted", holds.RootElement[0].GetProperty("status").GetString());
            Assert.Equal(2, holds.RootElement[0].GetProperty("deltaIds").GetArrayLength());
            Assert.Equal(2, File.ReadAllLines(Path.Combine(options.OutputDirectory, "inventory.jsonl")).Length);
        }

        [Fact]
        public void PrototypeCannotBecomeFinalReviewWithoutActualNewProducerBinding()
        {
            using var fixture = new Fixture();
            fixture.WriteLog("No unknown differences found.");
            var options = fixture.Options();
            options.Purpose = "conversion-wave";
            Assert.Throws<InvalidDataException>(() => WinmdReviewBatch.Create(options));
            string boundary = Path.Combine(fixture.Root, "boundary.json");
            File.WriteAllText(boundary, "{\"purpose\":\"prototype\",\"oldWinmdSha256\":\"wrong\",\"newWinmdSha256\":\"wrong\",\"comparisonLogSha256\":\"wrong\",\"producerCompleted\":true}");
            options.Boundary = boundary;
            Assert.Throws<InvalidDataException>(() => WinmdReviewBatch.Create(options));
            Assert.False(Directory.Exists(options.OutputDirectory));
        }

        [Fact]
        public void ExistingOrOverlappingOutputsAreRejectedWithoutWritingInputs()
        {
            using var fixture = new Fixture();
            fixture.WriteLog("No unknown differences found.");
            var options = fixture.Options();
            Directory.CreateDirectory(options.OutputDirectory);
            Assert.Throws<IOException>(() => WinmdReviewBatch.Create(options));
            options.OutputDirectory = Path.Combine(fixture.Generated, "new-review");
            Assert.Throws<IOException>(() => WinmdReviewBatch.Create(options));
            Assert.False(Directory.Exists(options.OutputDirectory));
        }

        [Fact]
        public void FileScopedNamespacesRetainExactGeneratedIdentity()
        {
            using var fixture = new Fixture(@"
using System.Runtime.InteropServices;
namespace Fixture;
public static class Apis
{
    [DllImport(""fixture.dll"")]
    public static extern int Compute(int value);
}");
            fixture.WriteLog("Unknown differences found:\nFixture.Apis.Compute : parameter 1 (value) : [In] => [In,Optional]\n");
            var options = fixture.Options();
            WinmdReviewBatch.Create(options);
            using var source = Assert.Single(ReadJsonLines(Path.Combine(options.OutputDirectory, "source-index.jsonl")));
            Assert.Equal("exact-syntax-identity", source.RootElement.GetProperty("generatedResolution").GetString());
            Assert.Equal("Fixture.Apis.Compute",
                Assert.Single(source.RootElement.GetProperty("generatedDeclarations").EnumerateArray())
                    .GetProperty("identity").GetString());
        }

        [Theory]
        [InlineData(null)]
        [InlineData("")]
        public void UnselectedIntegrityImagePreservesExistingDefault(string path)
        {
            Assert.Equal(Path.GetFullPath(Path.Combine(TestUtils.BinPath, @"..\..\windows.win32.winmd")),
                TestUtils.GetWinmdPath(path));
        }

        [Fact]
        public void ExplicitIntegrityImageMustExistAndDoesNotFallBack()
        {
            using var fixture = new Fixture();
            Assert.Equal(Path.Combine(fixture.Root, "fixture.dll"), TestUtils.GetWinmdPath(Path.Combine(fixture.Root, "fixture.dll")));
            Assert.Throws<FileNotFoundException>(() => TestUtils.GetWinmdPath(Path.Combine(fixture.Root, "missing.winmd")));
        }

        private static JsonDocument[] ReadJsonLines(string path) =>
            File.ReadAllLines(path).Select(line => JsonDocument.Parse(line)).ToArray();

        private sealed class Fixture : IDisposable
        {
            private const string Source = @"
using System.Runtime.InteropServices;
namespace Fixture
{
    public struct Handle { public unsafe void* Value; }
    public static unsafe class Apis
    {
        public const int VALUE = 1;
        [DllImport(""fixture.dll"")]
        public static extern int Compute([In] int* value, uint size);
    }
}";
            internal string Root { get; } = Path.Combine(Path.GetTempPath(), "WinmdReviewBatch-" + Guid.NewGuid().ToString("N"));
            internal string Generated => Path.Combine(this.Root, "generated");
            internal string Log => Path.Combine(this.Root, "comparison.log");
            internal string Header => Path.Combine(this.Root, "fixture.h");

            internal Fixture(string source = Source)
            {
                Directory.CreateDirectory(Path.Combine(this.Generated, "common"));
                Directory.CreateDirectory(Path.Combine(this.Root, "scratch", "common"));
                File.WriteAllText(Path.Combine(this.Generated, "common", "Fixture.cs"), source);
                File.WriteAllText(this.Header, "int Compute(int *value, unsigned size);\n");
                File.WriteAllText(Path.Combine(this.Root, "scratch", "common", "Fixture.settings.rsp"),
                    "--traverse\n" + this.Header + "\n");
                string paths = (string)AppContext.GetData("TRUSTED_PLATFORM_ASSEMBLIES");
                var compilation = CSharpCompilation.Create("ReviewFixture", new[] { CSharpSyntaxTree.ParseText(source) },
                    paths.Split(Path.PathSeparator).Select(p => MetadataReference.CreateFromFile(p)),
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                using var output = File.Create(Path.Combine(this.Root, "fixture.dll"));
                var result = compilation.Emit(output);
                Assert.True(result.Success, string.Join(Environment.NewLine, result.Diagnostics));
            }

            internal void WriteLog(string text) => File.WriteAllText(this.Log, text, new UTF8Encoding(true));

            internal WinmdReviewBatch.Options Options() => new()
            {
                ComparisonLog = this.Log,
                First = Path.Combine(this.Root, "fixture.dll"),
                Second = Path.Combine(this.Root, "fixture.dll"),
                GeneratedDirectory = this.Generated,
                ScratchDirectories = new[] { Path.Combine(this.Root, "scratch") },
                OutputDirectory = Path.Combine(this.Root, "review"),
            };

            public void Dispose()
            {
                foreach (string path in Directory.GetFiles(this.Root, "*", SearchOption.AllDirectories))
                    File.SetAttributes(path, FileAttributes.Normal);
                Directory.Delete(this.Root, recursive: true);
            }
        }
    }
}
