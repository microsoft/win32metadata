using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.Json;
using System.Text.Json.Nodes;
using System.Xml.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class PreparedSdkHeadersTests
    {
        [Fact]
        public void PreparationPreservesBytesAndReusesAnImmutableCacheFromAnyWorkingDirectory()
        {
            using var fixture = new Fixture();
            byte[] original = File.ReadAllBytes(fixture.Header);
            byte[] unrelated = File.ReadAllBytes(fixture.Unrelated);
            var first = fixture.Prepare();
            Assert.False(first.Reused);
            Assert.Equal(original, File.ReadAllBytes(fixture.Header));
            Assert.Equal(unrelated, File.ReadAllBytes(Path.Combine(first.IncludeRoot, "shared", "unrelated.h")));
            Assert.Equal(Encoding.ASCII.GetBytes(Fixture.Before.Replace("VALUE 1", "VALUE 2")),
                File.ReadAllBytes(Path.Combine(first.IncludeRoot, "um", "sample.h")));

            var second = fixture.Prepare(Path.Combine(fixture.RepositoryRoot, "generation", "WinSDK"));
            Assert.True(second.Reused);
            Assert.Equal(first.Identity, second.Identity);
            Assert.Equal(first.IncludeRoot, second.IncludeRoot);

            fixture.WritePatch(3);
            var changed = fixture.Prepare();
            Assert.False(changed.Reused);
            Assert.NotEqual(first.Identity, changed.Identity);
            Assert.Contains("VALUE 2", File.ReadAllText(Path.Combine(first.IncludeRoot, "um", "sample.h")));
            Assert.Contains("VALUE 3", File.ReadAllText(Path.Combine(changed.IncludeRoot, "um", "sample.h")));
        }

        [Fact]
        public void PublishedCacheTamperingIsRejectedRatherThanRepaired()
        {
            using var fixture = new Fixture();
            var prepared = fixture.Prepare();
            string header = Path.Combine(prepared.IncludeRoot, "um", "sample.h");
            File.AppendAllText(header, "// changed\r\n");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Published header cache was modified", result.Error);
            Assert.EndsWith("// changed\r\n", File.ReadAllText(header));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
        }

        [Fact]
        public void FailedPatchApplicationPublishesNothingAndLeavesTheSourceAlone()
        {
            using var fixture = new Fixture();
            fixture.WritePatch(2, before: 99);
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Patch preflight failed", result.Error);
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Theory]
        [InlineData("stage", "MIDL")]
        [InlineData("sdk", "SDK package mismatch")]
        [InlineData("preimage", "preimage mismatch")]
        [InlineData("sdk-header", "Selected SDK input mismatch")]
        public void MismatchedInputsFailBeforePublication(string mutation, string diagnostic)
        {
            using var fixture = new Fixture();
            switch (mutation)
            {
                case "stage":
                    fixture.WriteRecipe(stage: "pre-midl");
                    break;
                case "sdk":
                    fixture.WriteRecipe(version: "0.0.0.0");
                    break;
                case "preimage":
                    File.AppendAllText(fixture.Header, "// changed\r\n");
                    break;
                case "sdk-header":
                    File.AppendAllText(fixture.SdkHeader, "// changed\r\n");
                    break;
            }

            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(diagnostic, result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Theory]
        [InlineData("um/other.h", null)]
        [InlineData("../outside.h", null)]
        [InlineData("um/sample.h", "new file mode 100644\n")]
        [InlineData("um/sample.h", "old mode 100644\nnew mode 100755\n")]
        [InlineData("um/sample.h", "rename from sample.h\nrename to other.h\n")]
        public void UnadmittedPatchPathsAndFileIdentityChangesAreRejected(string path, string metadata)
        {
            using var fixture = new Fixture();
            fixture.WritePatch(2, path: path, metadata: metadata);
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void DuplicatePatchesAndRecipePathEscapesAreRejected()
        {
            using var fixture = new Fixture();
            fixture.WriteRecipe(patches: new[] { Fixture.PatchPath, Fixture.PatchPath });
            var duplicate = fixture.Run();
            Assert.NotEqual(0, duplicate.ExitCode);
            Assert.Contains("more than once", duplicate.Error);

            fixture.WriteRecipe(patches: new[] { @"..\outside.patch" });
            var escape = fixture.Run();
            Assert.NotEqual(0, escape.ExitCode);
            Assert.Contains("escapes its root", escape.Error);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void DifferentPatchFilesCannotLayerChangesOnOneSdkArtifact(bool idl)
        {
            using var fixture = new Fixture();
            if (idl)
                fixture.EnableMidl();
            const string second = @"um\second.patch";
            fixture.CopyPatch(idl ? Fixture.IdlPatchPath : Fixture.PatchPath, second);
            fixture.MutateRecipe(recipe => recipe["patches"].AsArray().Add(second));
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("SDK artifact is patched more than once", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
        }

        [Theory]
        [InlineData(@"um\sample.patch")]
        [InlineData(@"post-midl\um\sample.h.patch")]
        [InlineData(@"um\um\sample.h.patch")]
        public void PatchFilenamesMustIdentifyTheirCanonicalSdkArtifact(string path)
        {
            using var fixture = new Fixture();
            fixture.CopyPatch(Fixture.PatchPath, path);
            fixture.WriteRecipe(patches: new[] { path });
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("must be named after its SDK artifact", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void OnePatchCannotContainRepeatedArtifactDiffs()
        {
            using var fixture = new Fixture();
            fixture.RepeatPatch();
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("exactly one SDK artifact", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void DirectHeaderPatchesCannotDependOnAnIntermediateMirrorPreimage()
        {
            using var fixture = new Fixture();
            File.AppendAllText(fixture.Header, "// intermediate\r\n");
            fixture.MutateRecipe(recipe => recipe["headers"][0]["sourceSha256"] =
                Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(File.ReadAllBytes(fixture.Header))));
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("requires the pristine SDK preimage", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void DifferentOldAndNewPatchTargetsAreRejected()
        {
            using var fixture = new Fixture();
            fixture.WritePatch(2, originalPath: "um/other.h");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("without changing its identity", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
        }

        [Fact]
        public void ConcurrentPreparationCannotMutateAnotherTransactionsTree()
        {
            using var fixture = new Fixture();
            using var heldLock = File.Open(Path.Combine(fixture.Output, "prepare.lock"),
                FileMode.OpenOrCreate, FileAccess.ReadWrite, FileShare.None);
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
        }

        [Theory]
        [InlineData("ScrapeHeaders", "")]
        [InlineData("ScrapeHeaders", "Sample")]
        [InlineData("ScrapeConstants", "")]
        [InlineData("ScrapeConstants", "Sample")]
        public void OneSdkPreparationPrecedesAllConsumersAndInvalidatesEveryArchitecture(string target, string filter)
        {
            using var fixture = new Fixture();
            string previous = null;
            for (int pass = 0; pass < 3; pass++)
            {
                foreach (string marker in fixture.ScrapeMarkers)
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(marker));
                    File.WriteAllText(marker, "old marker");
                }
                if (pass == 2)
                    fixture.WritePatch(3);

                var result = fixture.RunSdkBuild(target, filter);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                string[][] events = File.ReadAllLines(fixture.BuildEvents).Select(line => line.Split('|')).ToArray();
                Assert.Equal(target == "ScrapeConstants" ? new[] { "prepare", "idl", "headers", "constants" } :
                    new[] { "prepare", "idl", "headers" }, events.Select(entry => entry[0]));
                string includeRoot = events[0][1];
                Assert.All(events, entry => Assert.Equal(includeRoot, entry[1]));
                Assert.NotEqual(Path.GetDirectoryName(Path.GetDirectoryName(fixture.Header)), includeRoot);
                Assert.Contains(pass == 2 ? "VALUE 3" : "VALUE 2",
                    File.ReadAllText(Path.Combine(includeRoot, "um", "sample.h")));
                Assert.All(fixture.ScrapeMarkers, marker => Assert.Equal(pass == 1, File.Exists(marker)));
                if (pass == 1)
                    Assert.Equal(previous, includeRoot);
                if (pass == 2)
                    Assert.NotEqual(previous, includeRoot);
                fixture.AssertPublishedProvenance(includeRoot);
                previous = includeRoot;
            }
        }

        [Theory]
        [InlineData(new[] { @"common\Sample.cs" },
            new[] { @"x86\Sample.cs", @"x64\Sample.cs", @"arm64\Sample.cs" }, new[] { "Sample" })]
        [InlineData(new[] { @"x86\Sample.cs", @"x64\Sample.cs", @"arm64\Sample.cs" },
            new[] { @"common\Sample.cs" }, new[] { "Sample" })]
        [InlineData(new[] { @"x64\Sample.cs" }, new[] { @"x64\Sample.cs" }, new[] { "Sample" })]
        [InlineData(new string[0], new[] { @"arm64\Sample.cs" }, new[] { "Sample" })]
        [InlineData(new[] { @"common\Sample.cs", @"x86\Second.cs", @"x64\Second.cs" },
            new[] { @"x86\Sample.cs", @"x64\Sample.cs", @"arm64\Sample.cs", @"common\Second.cs" },
            new[] { "Sample", "Second" })]
        public void SelectedHeaderReplacementUsesTheCompleteFreshSetAndPreservesOtherInputs(
            string[] before, string[] after, string[] partitions)
        {
            using var fixture = new Fixture();
            string[] unrelated = { @"common\Other.cs", @"common\Manual.cs", "scraper.autoRemaps.generated.rsp" };
            byte[] frozen = { 0xff, 0xfe, 0x61, 0, 0x0d, 0, 0x0a, 0 };
            foreach (string relative in before.Concat(unrelated))
                Fixture.WriteGeneratedFile(fixture.AssembledSources, relative, frozen);
            foreach (string relative in after.Concat(new[] { @"common\Unselected.cs" }))
                Fixture.WriteGeneratedFile(fixture.SelectedSources, relative,
                    new byte[] { 0xef, 0xbb, 0xbf }.Concat(Encoding.UTF8.GetBytes("fresh:" + relative + "\r\n")).ToArray());

            var selected = Directory.GetFiles(fixture.SelectedSources, "*", SearchOption.AllDirectories)
                .ToDictionary(path => path, File.ReadAllBytes);
            var result = fixture.ReplaceSelectedHeaders(partitions, after);
            Assert.True(result.ExitCode == 0, result.Error + result.Output);
            string[] removed = JsonSerializer.Deserialize<string[]>(result.Output);
            Assert.NotNull(removed);
            Assert.Equal(before.OrderBy(path => path, StringComparer.Ordinal),
                removed.OrderBy(path => path, StringComparer.Ordinal));
            Assert.Equal(after.Concat(unrelated).OrderBy(path => path, StringComparer.Ordinal),
                Directory.GetFiles(fixture.AssembledSources, "*", SearchOption.AllDirectories)
                    .Select(path => Path.GetRelativePath(fixture.AssembledSources, path))
                    .OrderBy(path => path, StringComparer.Ordinal));
            Assert.All(after, relative => Assert.Equal(selected[Path.Combine(fixture.SelectedSources, relative)],
                File.ReadAllBytes(Path.Combine(fixture.AssembledSources, relative))));
            Assert.All(unrelated, relative => Assert.Equal(frozen,
                File.ReadAllBytes(Path.Combine(fixture.AssembledSources, relative))));
            Assert.Equal(selected.Count, Directory.GetFiles(fixture.SelectedSources, "*", SearchOption.AllDirectories).Length);
            Assert.All(selected, entry => Assert.Equal(entry.Value, File.ReadAllBytes(entry.Key)));
        }

        [Fact]
        public void MissingFreshHeaderFailsBeforeAnyFrozenSourceIsRemoved()
        {
            using var fixture = new Fixture();
            byte[] frozen = Encoding.ASCII.GetBytes("frozen\r\n");
            byte[] fresh = Encoding.ASCII.GetBytes("fresh\r\n");
            Fixture.WriteGeneratedFile(fixture.AssembledSources, @"common\Sample.cs", frozen);
            Fixture.WriteGeneratedFile(fixture.AssembledSources, @"common\Other.cs", frozen);
            Fixture.WriteGeneratedFile(fixture.SelectedSources, @"x86\Sample.cs", fresh);

            var result = fixture.ReplaceSelectedHeaders(new[] { "Sample" },
                new[] { @"x86\Sample.cs", @"x64\Sample.cs" });
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(@"The selected header source is missing: x64\Sample.cs", result.Error);
            Assert.Equal(2, Directory.GetFiles(fixture.AssembledSources, "*", SearchOption.AllDirectories).Length);
            Assert.Equal(frozen, File.ReadAllBytes(Path.Combine(fixture.AssembledSources, @"common\Sample.cs")));
            Assert.Equal(frozen, File.ReadAllBytes(Path.Combine(fixture.AssembledSources, @"common\Other.cs")));
            Assert.Equal(fresh, File.ReadAllBytes(Path.Combine(fixture.SelectedSources, @"x86\Sample.cs")));
        }

        [Theory]
        [InlineData("equal")]
        [InlineData("source-contains-destination")]
        [InlineData("destination-contains-source")]
        public void SelectedHeaderReplacementRejectsOverlappingRoots(string relationship)
        {
            using var fixture = new Fixture();
            string selected = relationship == "destination-contains-source"
                ? Path.Combine(fixture.SelectedSources, "child") : fixture.SelectedSources;
            string assembled = relationship == "source-contains-destination"
                ? Path.Combine(fixture.SelectedSources, "child") : fixture.SelectedSources;
            var result = fixture.ReplaceSelectedHeaders(new[] { "Sample" }, Array.Empty<string>(), selected, assembled);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Selected and assembled generated-source roots must not overlap.", result.Error);
            Assert.False(Directory.Exists(fixture.SelectedSources));
        }

        [Fact]
        public void SdkBuildPreservesTheActualMidlClosureBesideGeneratedAssets()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            var result = fixture.RunSdkBuild("ScrapeConstants", "Sample");
            Assert.True(result.ExitCode == 0, result.Error + result.Output);
            string includeRoot = File.ReadAllLines(fixture.BuildEvents)[0].Split('|')[1];
            fixture.AssertPublishedProvenance(includeRoot, hasMidl: true);
        }

        [Fact]
        public void PreMidlRegenerationPreservesSalImportsSourcesAndRepeatBytes()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            byte[] original = File.ReadAllBytes(fixture.MidlInput);
            var first = fixture.Prepare();
            string header = Path.Combine(first.IncludeRoot, "um", "generated.h");
            Assert.Contains("#define IDL_VALUE 2", File.ReadAllText(header));
            Assert.Contains("_Out_", File.ReadAllText(header));
            Assert.Contains("_Win32_Retval_", File.ReadAllText(header));
            Assert.Contains("typedef long DEPENDENCY", File.ReadAllText(Path.Combine(first.IncludeRoot, "um", "dependency.h")));
            Assert.Contains("VALUE 2", File.ReadAllText(Path.Combine(first.IncludeRoot, "um", "sample.h")));
            Assert.Equal(original, File.ReadAllBytes(fixture.MidlInput));
            Assert.True(fixture.Prepare().Reused);

            var repeated = fixture.Prepare(outputRoot: fixture.Output + "-repeat");
            Assert.False(repeated.Reused);
            Assert.Equal(first.Identity, repeated.Identity);
            foreach (string name in new[] { "generated.h", "dependency.h", "sample.h" })
                Assert.Equal(File.ReadAllBytes(Path.Combine(first.IncludeRoot, "um", name)),
                    File.ReadAllBytes(Path.Combine(repeated.IncludeRoot, "um", name)));
            string commands = File.ReadAllText(Path.Combine(Path.GetDirectoryName(first.IncludeRoot), "midl", "commands.json"));
            Assert.DoesNotContain("/no_warn", commands);
            Assert.DoesNotContain("/WX", commands);
            Assert.Contains("MIDL2495", commands);
            Assert.Contains("/X", commands);
        }

        [Fact]
        public void IncludedIdlPatchRegeneratesBothOriginalArtifactOwners()
        {
            using var fixture = new Fixture();
            fixture.EnableIncludedMidl();
            byte[] original = File.ReadAllBytes(fixture.MidlInput);
            var prepared = fixture.Prepare();
            foreach (string name in new[] { "generated", "including" })
            {
                string header = File.ReadAllText(Path.Combine(prepared.IncludeRoot, "um", name + ".h"));
                Assert.Contains("#define IDL_VALUE 2", header);
                Assert.Contains("_Out_", header);
                Assert.Contains("_Win32_Retval_", header);
            }
            using var inputs = JsonDocument.Parse(File.ReadAllText(Path.Combine(Path.GetDirectoryName(prepared.IncludeRoot),
                "midl", "preprocessed-inputs.json")));
            Assert.Equal(new[] { @"um\dependency.idl", @"um\generated.idl", @"um\including.idl" },
                inputs.RootElement.EnumerateArray().Select(value => value.GetString()));
            Assert.Equal(original, File.ReadAllBytes(fixture.MidlInput));
            Assert.True(fixture.Prepare().Reused);
            var repeated = fixture.Prepare(outputRoot: fixture.Output + "-repeat");
            Assert.False(repeated.Reused);
            Assert.Equal(prepared.Identity, repeated.Identity);
            foreach (string name in new[] { "generated", "including", "dependency" })
                Assert.Equal(File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "um", name + ".h")),
                    File.ReadAllBytes(Path.Combine(repeated.IncludeRoot, "um", name + ".h")));
        }

        [Fact]
        public void HeaderInTheMidlInputClosureCannotFallBackToItsMirrorWhenItsOutputIsMissing()
        {
            using var fixture = new Fixture();
            fixture.EnableIncludedMidl();
            fixture.MutateRecipe(recipe => recipe["midl"]["outputs"].AsArray().RemoveAt(2));
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("A header in the admitted MIDL input closure must have one pinned MIDL output: um\\including.h", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void UnrelatedIdlBackedHeaderRetainsItsPinnedMirrorWithoutExpandingTheMidlClosure()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            byte[] original = fixture.AddUnrelatedIdlBackedHeader();
            var prepared = fixture.Prepare();
            string header = Path.Combine(prepared.IncludeRoot, "um", "unrelated.h");
            Assert.Equal(original, File.ReadAllBytes(header));
            using var inputs = JsonDocument.Parse(File.ReadAllText(Path.Combine(Path.GetDirectoryName(prepared.IncludeRoot),
                "midl", "preprocessed-inputs.json")));
            Assert.Equal(new[] { @"um\dependency.idl", @"um\generated.idl" },
                inputs.RootElement.EnumerateArray().Select(value => value.GetString()));
            Assert.True(fixture.Prepare().Reused);
            var repeated = fixture.Prepare(outputRoot: fixture.Output + "-repeat");
            Assert.Equal(prepared.Identity, repeated.Identity);
            Assert.Equal(original, File.ReadAllBytes(Path.Combine(repeated.IncludeRoot, "um", "unrelated.h")));
        }

        [Fact]
        public void SharedSdkHeaderPatchReachesBothNativeAndMidlInputs()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlSharedHeader();
            byte[] original = File.ReadAllBytes(fixture.SdkHeader);
            var prepared = fixture.Prepare();
            byte[] header = File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "um", "sample.h"));
            Assert.Contains("#define VALUE 2", Encoding.UTF8.GetString(header));
            string midl = Path.Combine(Path.GetDirectoryName(prepared.IncludeRoot), "midl");
            foreach (string stage in new[] { "source", "sal" })
                Assert.Equal(header, File.ReadAllBytes(Path.Combine(midl, stage, "um", "sample.h")));
            Assert.Equal(original, File.ReadAllBytes(fixture.SdkHeader));
            Assert.Equal(original, File.ReadAllBytes(fixture.Header));
            using var inputs = JsonDocument.Parse(File.ReadAllText(Path.Combine(midl, "preprocessed-inputs.json")));
            Assert.Contains(@"um\sample.h", inputs.RootElement.EnumerateArray().Select(value => value.GetString()));
            Assert.True(fixture.Prepare().Reused);
        }

        [Fact]
        public void SharedSdkHeaderCannotBindDifferentNativeAndMidlArtifacts()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlSharedHeader();
            File.Copy(fixture.SdkHeader, Path.Combine(Path.GetDirectoryName(fixture.SdkHeader), "other.h"));
            fixture.MutateRecipe(recipe => recipe["midl"]["inputs"][2]["sdkPath"] = @"c\include\um\other.h");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("same pristine SDK input", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void SourcePinnedAnnotationHeaderAndMidlDefinesReachTheActualPreprocessor()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            byte[] original = File.ReadAllBytes(fixture.AnnotationHeader);
            var prepared = fixture.Prepare();
            string root = Path.GetDirectoryName(prepared.IncludeRoot);
            const string relative = @"shared\win32metadata_annotations.h";
            Assert.Equal(original, File.ReadAllBytes(Path.Combine(root, "midl", "source", relative)));
            Assert.Equal(original, File.ReadAllBytes(Path.Combine(root, "midl", "sal", relative)));
            Assert.Equal(original, File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, relative)));
            Assert.Contains("shared\\\\win32metadata_annotations.h",
                File.ReadAllText(Path.Combine(root, "midl", "preprocessed-inputs.json")));
            using var manifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "manifest.json")));
            var helper = manifest.RootElement.GetProperty("midlInputs").EnumerateArray()
                .Single(input => input.GetProperty("path").GetString() == relative);
            Assert.Equal("repository", helper.GetProperty("sourceKind").GetString());
            Assert.Equal(JsonValueKind.Null, helper.GetProperty("sdkPath").ValueKind);
            using var commands = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "midl", "commands.json")));
            foreach (var command in commands.RootElement.EnumerateArray())
            {
                string[] arguments = command.GetProperty("arguments").EnumerateArray().Select(value => value.GetString()).ToArray();
                string cpp = arguments[Array.IndexOf(arguments, "/cpp_opt") + 1];
                Assert.Contains("/DMIDL_PASS=1", cpp);
                Assert.Contains("/I\"<prepared>\\midl\\sal\\shared\"", cpp);
                foreach (string definition in arguments.Where(value => value.StartsWith("/D", StringComparison.Ordinal)))
                    Assert.Contains(definition, cpp);
            }
            Assert.True(fixture.Prepare().Reused);
            var repeated = fixture.Prepare(outputRoot: fixture.Output + "-repeat");
            Assert.Equal(prepared.Identity, repeated.Identity);
            Assert.Equal(File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "um", "generated.h")),
                File.ReadAllBytes(Path.Combine(repeated.IncludeRoot, "um", "generated.h")));
            Assert.Equal(original, File.ReadAllBytes(fixture.AnnotationHeader));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ChangedRepositoryAnnotationHeaderCannotFallBackOrReuseACache(bool publishFirst)
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            if (publishFirst) fixture.Prepare();
            File.AppendAllText(fixture.AnnotationHeader, "// changed");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Selected repository MIDL input mismatch", result.Error);
        }

        [Fact]
        public void SourcePinnedAnnotationHeaderUsesQuotedPrivateIncludePaths()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            var prepared = fixture.Prepare(outputRoot: fixture.Output + " with spaces");
            Assert.Contains("IDL_VALUE 2",
                File.ReadAllText(Path.Combine(prepared.IncludeRoot, "um", "generated.h")));
            Assert.Equal(File.ReadAllBytes(fixture.AnnotationHeader),
                File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "shared", "win32metadata_annotations.h")));
            Assert.True(fixture.Prepare(outputRoot: fixture.Output + " with spaces").Reused);
        }

        [Fact]
        public void AnUnusedRepositoryAnnotationHeaderCannotBeAdmittedAsAnActualInput()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            File.WriteAllText(fixture.MidlInput, File.ReadAllText(fixture.MidlInput)
                .Replace("#include <win32metadata_annotations.h>\r\n", ""));
            fixture.MutateRecipe(recipe =>
            {
                string hash = Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(File.ReadAllBytes(fixture.MidlInput)));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("declared MIDL input closure does not match the actual preprocessed inputs", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void UnpinnedRepositoryAnnotationHeaderCannotUseAmbientIncludes()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            fixture.MutateRecipe(recipe => recipe["midl"]["inputs"].AsArray().RemoveAt(2));
            var result = fixture.Run(ambientInclude: Path.GetDirectoryName(fixture.AnnotationHeader));
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("MIDL failed", result.Error);
            Assert.Contains("win32metadata_annotations.h", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Theory]
        [InlineData("path")]
        [InlineData("sdk")]
        public void RepositoryMidlInputsCannotDisguiseAnotherArtifactOrSdkBinding(string mutation)
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            fixture.MutateRecipe(recipe =>
            {
                var helper = recipe["midl"]["inputs"][2];
                if (mutation == "path") helper["path"] = @"shared\unrelated.h";
                else helper["sdkPath"] = @"c\include\um\sample.h";
            });
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Only the canonical repository annotation header", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void DuplicateRepositoryMidlInputsAreRejected()
        {
            using var fixture = new Fixture();
            fixture.EnableMidlAnnotationHeader();
            fixture.MutateRecipe(recipe =>
                recipe["midl"]["inputs"].AsArray().Add(recipe["midl"]["inputs"][2].DeepClone()));
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("contain no duplicate paths", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Theory]
        [InlineData("source", "Selected SDK input mismatch")]
        [InlineData("import", "Selected SDK input mismatch")]
        [InlineData("compiler", "Selected SDK MIDL compiler mismatch")]
        public void ChangedMidlInputsCannotReuseAPublishedCache(string mutation, string diagnostic)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.Prepare();
            File.AppendAllText(mutation == "source" ? fixture.MidlInput :
                mutation == "import" ? fixture.MidlDependency : fixture.MidlCompiler, "// changed");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(diagnostic, result.Error);
        }

        [Fact]
        public void UnpinnedMidlImportsCannotFallBackToAmbientSdkPaths()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.MutateRecipe(recipe =>
            {
                recipe["midl"]["inputs"].AsArray().RemoveAt(1);
                recipe["midl"]["outputs"].AsArray().RemoveAt(0);
            });
            var result = fixture.Run(ambientInclude: Path.GetDirectoryName(fixture.MidlDependency));
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("MIDL failed", result.Error);
            Assert.Contains("dependency.idl", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void SdkArtifactKindsDeterminePreparationOrderRatherThanRecipeOrder()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.MutateRecipe(recipe =>
            {
                var patches = recipe["patches"].AsArray();
                var first = patches[0].DeepClone();
                patches.RemoveAt(0);
                patches.Add(first);
            });
            var prepared = fixture.Prepare();
            Assert.Contains("#define IDL_VALUE 2",
                File.ReadAllText(Path.Combine(prepared.IncludeRoot, "um", "generated.h")));
            Assert.Contains("VALUE 2", File.ReadAllText(Path.Combine(prepared.IncludeRoot, "um", "sample.h")));
        }

        [Fact]
        public void ShippedIdlBackedHeadersCannotBeAnnotationPatchTargets()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.WriteGeneratedHeaderPatch();
            var stage = fixture.Run();
            Assert.NotEqual(0, stage.ExitCode);
            Assert.Contains("belongs before MIDL", stage.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void PublishedMidlClosureTamperingIsRejected()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            var prepared = fixture.Prepare();
            string converted = Path.Combine(Path.GetDirectoryName(prepared.IncludeRoot), "midl", "sal", "um", "generated.idl");
            File.AppendAllText(converted, "// changed");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("Published MIDL cache was modified", result.Error);
        }

        [Fact]
        public void MidlSyntaxFailurePublishesNothingAndDoesNotReuseMirrorHeaders()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            File.AppendAllText(fixture.MidlInput, "\r\nnot valid IDL;\r\n");
            fixture.MutateRecipe(recipe =>
            {
                string hash = Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(File.ReadAllBytes(fixture.MidlInput)));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("MIDL failed", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void GeneratedHeaderCannotHideItsShippedIdlBehindAHeaderSdkPath()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.DisguiseGeneratedHeaderAsSdkHeader();
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("belongs before MIDL", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Fact]
        public void SalConversionDoesNotSkipParametersBesideMetadataOrOtherAnnotations()
        {
            using var fixture = new Fixture();
            const string input = "void F([out, retval][annotation(\"_Win32_Retval_\")] long* value, [in] long count);\r\n" +
                "void G([out][retval][annotation(\"_Out_retval_\")] long* value, [in] long count);\r\n" +
                "void H([annotation(\"_Win32_Retval_\")][out][retval] long* value);\r\n" +
                "cpp_quote(\"void Native([out] long* value);\")\r\n";
            string converted = fixture.ConvertSal(input);
            Assert.Contains("[out, retval][annotation(\"_Out_retval_ _Win32_Retval_\")]", converted);
            Assert.Equal(3, converted.Split("_Out_retval_").Length - 1);
            Assert.Equal(2, converted.Split("[annotation(\"_In_\")]").Length - 1);
            Assert.Contains("cpp_quote(\"void Native([out] long* value);\")", converted);
        }

        private sealed class Fixture : IDisposable
        {
            internal const string Before = "#ifndef SAMPLE_H\r\n#define SAMPLE_H\r\n#define VALUE 1\r\n#endif\r\n";
            internal const string PatchPath = @"um\sample.h.patch";
            internal const string IdlPatchPath = @"um\generated.idl.patch";
            private readonly string root;
            private readonly string source;
            private readonly string sdk;
            private readonly string recipe;
            private readonly string patch;

            internal Fixture()
            {
                var directory = new DirectoryInfo(AppContext.BaseDirectory);
                while (directory != null && !File.Exists(Path.Combine(directory.FullName, "scripts", "Prepare-SdkHeaders.ps1")))
                {
                    directory = directory.Parent;
                }

                RepositoryRoot = directory?.FullName ?? throw new InvalidOperationException("Repository scripts were not found.");
                this.root = Path.Combine(RepositoryRoot, "artifacts", "prepared-header-tests", Guid.NewGuid().ToString("N"));
                this.source = Path.Combine(this.root, "source");
                this.sdk = Path.Combine(this.root, "sdk");
                this.recipe = Path.Combine(this.root, "recipe.json");
                this.patch = Path.Combine(this.root, PatchPath);
                Header = Path.Combine(this.source, "um", "sample.h");
                Unrelated = Path.Combine(this.source, "shared", "unrelated.h");
                SdkHeader = Path.Combine(this.sdk, "c", "include", "um", "sample.h");
                Output = Path.Combine(this.root, "output");
                foreach (string path in new[] { Header, Unrelated, SdkHeader, this.patch, Path.Combine(Output, "placeholder") })
                {
                    Directory.CreateDirectory(Path.GetDirectoryName(path));
                }

                File.WriteAllBytes(Header, Encoding.ASCII.GetBytes(Before));
                File.WriteAllBytes(Unrelated, new byte[] { 0xff, 0xfe, 0x61, 0, 0x0d, 0, 0x0a, 0 });
                File.WriteAllBytes(SdkHeader, Encoding.ASCII.GetBytes(Before));
                File.WriteAllText(Path.Combine(this.sdk, "microsoft.windows.sdk.cpp.nuspec"),
                    "<package><metadata><version>10.0.26100.7705</version></metadata></package>");
                WritePatch(2);
                WriteRecipe();
            }

            internal string RepositoryRoot { get; }
            internal string Header { get; }
            internal string Unrelated { get; }
            internal string SdkHeader { get; }
            internal string Output { get; }
            internal string SelectedSources => Path.Combine(this.root, "selected-sources");
            internal string AssembledSources => Path.Combine(this.root, "assembled-sources");
            internal string MidlInput => Path.Combine(this.sdk, "c", "include", "um", "generated.idl");
            internal string MidlDependency => Path.Combine(this.sdk, "c", "include", "um", "dependency.idl");
            internal string MidlCompiler => Path.Combine(this.sdk, "c", "bin", "x64", "midl.exe");
            internal string AnnotationHeader => Path.Combine(this.source, "shared", "win32metadata_annotations.h");
            internal string BuildEvents => Path.Combine(this.root, "build-events.txt");
            internal string[] ScrapeMarkers => new[] { "scannedheaders.crossarch.txt", "scannedheaders.x86.txt",
                "scannedheaders.x64.txt", "scannedheaders.arm64.txt", "constants.scraped.txt" }
                .Select(name => Path.Combine(this.root, "obj", "generated", name)).ToArray();

            internal void WritePatch(int after, int before = 1, string path = "um/sample.h", string metadata = null, string originalPath = null)
            {
                string oldPath = originalPath ?? path;
                string text = $"diff --git a/{oldPath} b/{path}\n{metadata}" +
                    $"--- a/{oldPath}\n+++ b/{path}\n@@ -1,4 +1,4 @@\n #ifndef SAMPLE_H\r\n #define SAMPLE_H\r\n" +
                    $"-#define VALUE {before}\r\n+#define VALUE {after}\r\n #endif\r\n";
                File.WriteAllText(this.patch, text, new UTF8Encoding(false));
            }

            internal void CopyPatch(string source, string target)
            {
                string path = Path.Combine(this.root, target);
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.Copy(Path.Combine(this.root, source), path);
            }

            internal void RepeatPatch() => File.AppendAllText(this.patch, File.ReadAllText(this.patch));

            internal void WriteRecipe(string stage = "post-midl", string version = "10.0.26100.7705", string[] patches = null)
            {
                File.WriteAllText(this.recipe, JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    sdkPackageVersion = version,
                    sourceStage = stage,
                    sourceGitTree = "",
                    headers = new[]
                    {
                        new
                        {
                            path = @"um\sample.h",
                            sourceSha256 = Hash(Encoding.ASCII.GetBytes(Before)),
                            sdkPath = @"c\include\um\sample.h",
                            sdkSha256 = Hash(Encoding.ASCII.GetBytes(Before)),
                        },
                    },
                    patches = patches ?? new[] { PatchPath },
                }));
            }

            internal void EnableMidl()
            {
                WriteRecipe();
                string input = "cpp_quote(\"#define IDL_VALUE 1\")\r\nimport \"dependency.idl\";\r\n" +
                    "[uuid(7a22f761-442c-4260-9d80-4c937dce56b6), version(1.0), pointer_default(unique)]\r\n" +
                    "interface IMidlFixture { void Read([out][annotation(\"_Win32_Retval_\")] DEPENDENCY* result); };\r\n";
                const string dependency = "typedef long DEPENDENCY;\r\n";
                foreach (string path in new[] { MidlInput, MidlCompiler })
                    Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(MidlInput, input, new UTF8Encoding(false));
                File.WriteAllText(MidlDependency, dependency, new UTF8Encoding(false));
                var props = XDocument.Load(Path.Combine(RepositoryRoot, "obj", "BuildTools", "BuildTools.proj.nuget.g.props"));
                string package = props.Descendants().Single(element => element.Name.LocalName == "PkgMicrosoft_Windows_SDK_CPP").Value;
                foreach (string name in new[] { "midl.exe", "midlc.exe" })
                    File.Copy(Path.Combine(package, "c", "bin", "10.0.26100.0", "x64", name),
                        Path.Combine(Path.GetDirectoryName(MidlCompiler), name), overwrite: true);

                const string beforeHeader = "/* File created by MIDL compiler */\r\n";
                foreach (string name in new[] { "generated", "dependency" })
                    File.WriteAllText(Path.Combine(this.source, "um", name + ".h"), beforeHeader);
                string patchFile = Path.Combine(this.root, IdlPatchPath);
                Directory.CreateDirectory(Path.GetDirectoryName(patchFile));
                File.WriteAllText(patchFile,
                    "diff --git a/um/generated.idl b/um/generated.idl\n" +
                    "--- a/um/generated.idl\n+++ b/um/generated.idl\n" +
                    "@@ -1,3 +1,3 @@\n-cpp_quote(\"#define IDL_VALUE 1\")\r\n+cpp_quote(\"#define IDL_VALUE 2\")\r\n" +
                    " import \"dependency.idl\";\r\n [uuid(7a22f761-442c-4260-9d80-4c937dce56b6), version(1.0), pointer_default(unique)]\r\n",
                    new UTF8Encoding(false));
                MutateRecipe(recipe =>
                {
                    foreach (string name in new[] { "generated", "dependency" })
                        recipe["headers"].AsArray().Add(JsonSerializer.SerializeToNode(new
                        {
                            path = @"um\" + name + ".h",
                            sourceSha256 = Hash(Encoding.UTF8.GetBytes(beforeHeader)),
                            sdkPath = @"c\include\um\" + name + ".idl",
                            sdkSha256 = Hash(File.ReadAllBytes(Path.Combine(this.sdk, "c", "include", "um", name + ".idl"))),
                        }));
                    recipe["midl"] = JsonSerializer.SerializeToNode(new
                    {
                        tools = new[] { "midl.exe", "midlc.exe" }.Select(name => new
                        {
                            sdkPath = @"c\bin\x64\" + name,
                            sha256 = Hash(File.ReadAllBytes(Path.Combine(Path.GetDirectoryName(MidlCompiler), name))),
                        }),
                        inputs = new[] { "generated", "dependency" }.Select(name => new
                        {
                            path = @"um\" + name + ".idl",
                            sdkPath = @"c\include\um\" + name + ".idl",
                            sdkSha256 = Hash(File.ReadAllBytes(Path.Combine(this.sdk, "c", "include", "um", name + ".idl"))),
                        }),
                        outputs = new[] { "dependency", "generated" }.Select(name => new
                        {
                            source = @"um\" + name + ".idl",
                            path = @"um\" + name + ".h",
                        }),
                    });
                    recipe["patches"] = JsonSerializer.SerializeToNode(new[] { IdlPatchPath, PatchPath });
                });
            }

            internal void EnableMidlSharedHeader()
            {
                EnableMidl();
                File.AppendAllText(MidlInput,
                    "\r\n#include \"sample.h\"\r\n#if VALUE != 2\r\n" +
                    "#error The shared SDK header patch did not reach MIDL preprocessing.\r\n#endif\r\n");
                MutateRecipe(recipe =>
                {
                    string hash = Hash(File.ReadAllBytes(MidlInput));
                    recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                    recipe["headers"][1]["sdkSha256"] = hash;
                    recipe["midl"]["inputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"um\sample.h",
                        sdkPath = @"c\include\um\sample.h",
                        sdkSha256 = Hash(File.ReadAllBytes(SdkHeader)),
                    }));
                });
            }

            internal void EnableMidlAnnotationHeader()
            {
                EnableMidl();
                File.Copy(Path.Combine(RepositoryRoot, "generation", "WinSDK", "RecompiledIdlHeaders",
                    "shared", "win32metadata_annotations.h"), AnnotationHeader);
                File.AppendAllText(MidlInput,
                    "\r\n#if !defined(MIDL_PASS) || MIDL_PASS != 1 || WINVER != 0x0A00 || !defined(UNICODE)\r\n" +
                    "#error The pinned MIDL preprocessor definitions were not forwarded.\r\n#endif\r\n" +
                    "#include <win32metadata_annotations.h>\r\n");
                MutateRecipe(recipe =>
                {
                    string hash = Hash(File.ReadAllBytes(MidlInput));
                    recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                    recipe["headers"][1]["sdkSha256"] = hash;
                    recipe["midl"]["inputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"shared\win32metadata_annotations.h",
                        sourceSha256 = Hash(File.ReadAllBytes(AnnotationHeader)),
                    }));
                });
            }

            internal void EnableIncludedMidl()
            {
                EnableMidl();
                const string input = "#include \"generated.idl\"\r\n";
                const string preimage = "/* File created by MIDL compiler */\r\n";
                string path = Path.Combine(this.sdk, "c", "include", "um", "including.idl");
                File.WriteAllText(path, input, new UTF8Encoding(false));
                File.WriteAllText(Path.Combine(this.source, "um", "including.h"), preimage, new UTF8Encoding(false));
                MutateRecipe(recipe =>
                {
                    recipe["headers"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"um\including.h",
                        sourceSha256 = Hash(Encoding.UTF8.GetBytes(preimage)),
                        sdkPath = @"c\include\um\including.idl",
                        sdkSha256 = Hash(File.ReadAllBytes(path)),
                    }));
                    recipe["midl"]["inputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"um\including.idl",
                        sdkPath = @"c\include\um\including.idl",
                        sdkSha256 = Hash(File.ReadAllBytes(path)),
                    }));
                    recipe["midl"]["outputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        source = @"um\including.idl",
                        path = @"um\including.h",
                    }));
                });
            }

            internal byte[] AddUnrelatedIdlBackedHeader()
            {
                string input = Path.Combine(this.sdk, "c", "include", "um", "unrelated.idl");
                const string idl = "typedef long UNRELATED;\r\n";
                byte[] header = Encoding.ASCII.GetBytes("/* File created by MIDL compiler */\r\ntypedef long UNRELATED;\r\n");
                File.WriteAllText(input, idl, new UTF8Encoding(false));
                File.WriteAllBytes(Path.Combine(this.source, "um", "unrelated.h"), header);
                MutateRecipe(recipe => recipe["headers"].AsArray().Add(JsonSerializer.SerializeToNode(new
                {
                    path = @"um\unrelated.h",
                    sourceSha256 = Hash(header),
                    sdkPath = @"c\include\um\unrelated.idl",
                    sdkSha256 = Hash(File.ReadAllBytes(input)),
                })));
                return header;
            }

            internal void MutateRecipe(Action<JsonObject> mutate)
            {
                var recipe = JsonNode.Parse(File.ReadAllText(this.recipe)).AsObject();
                mutate(recipe);
                File.WriteAllText(this.recipe, recipe.ToJsonString());
            }

            internal void WriteGeneratedHeaderPatch()
            {
                const string relative = @"um\generated.h.patch";
                File.WriteAllText(Path.Combine(this.root, relative),
                    "diff --git a/um/generated.h b/um/generated.h\n" +
                    "--- a/um/generated.h\n+++ b/um/generated.h\n" +
                    "@@ -1 +1,2 @@\n /* File created by MIDL compiler */\r\n+// annotation\r\n");
                MutateRecipe(recipe => recipe["patches"].AsArray().Add(relative));
            }

            internal void DisguiseGeneratedHeaderAsSdkHeader()
            {
                WriteGeneratedHeaderPatch();
                string target = Path.ChangeExtension(MidlInput, ".h");
                File.Copy(Path.Combine(this.source, "um", "generated.h"), target);
                MutateRecipe(recipe =>
                {
                    recipe.Remove("midl");
                    recipe["patches"].AsArray().RemoveAt(0);
                    recipe["headers"][1]["sdkPath"] = @"c\include\um\generated.h";
                    recipe["headers"][1]["sdkSha256"] = Hash(File.ReadAllBytes(target));
                });
            }

            internal string ConvertSal(string input)
            {
                string source = Path.Combine(this.root, "sal.idl");
                string target = Path.Combine(this.root, "sal-converted.idl");
                File.WriteAllText(source, input);
                var start = new ProcessStartInfo("pwsh") { UseShellExecute = false, RedirectStandardError = true, RedirectStandardOutput = true };
                foreach (string argument in new[] { "-NoProfile", "-NonInteractive", "-File",
                    Path.Combine(RepositoryRoot, "scripts", "ConvertMidlAttributesToSalAnnotations.ps1"), source, target })
                    start.ArgumentList.Add(argument);
                var result = Execute(start);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return File.ReadAllText(target);
            }

            internal void AssertPublishedProvenance(string includeRoot, bool hasMidl = false)
            {
                string cache = Path.GetDirectoryName(includeRoot);
                string published = Path.Combine(this.root, "obj", "prepared-sdk-provenance", "crossarch", Path.GetFileName(cache));
                Assert.Equal(File.ReadAllBytes(Path.Combine(cache, "manifest.json")),
                    File.ReadAllBytes(Path.Combine(published, "manifest.json")));
                string source = Path.Combine(cache, "midl");
                string target = Path.Combine(published, "midl");
                Assert.Equal(hasMidl, Directory.Exists(target));
                if (!hasMidl) return;
                string[] files = Directory.GetFiles(source, "*", SearchOption.AllDirectories)
                    .Select(path => Path.GetRelativePath(source, path)).OrderBy(path => path, StringComparer.Ordinal).ToArray();
                Assert.Contains(Path.Combine("sal", "um", "generated.idl"), files);
                Assert.Contains("commands.json", files);
                Assert.Equal(files, Directory.GetFiles(target, "*", SearchOption.AllDirectories)
                    .Select(path => Path.GetRelativePath(target, path)).OrderBy(path => path, StringComparer.Ordinal));
                foreach (string path in files)
                    Assert.Equal(File.ReadAllBytes(Path.Combine(source, path)), File.ReadAllBytes(Path.Combine(target, path)));
            }

            internal PreparationResult Prepare(string workingDirectory = null, string outputRoot = null)
            {
                var result = Run(workingDirectory, outputRoot: outputRoot);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return JsonSerializer.Deserialize<PreparationResult>(result.Output);
            }

            internal ProcessResult Run(string workingDirectory = null, string ambientInclude = null, string outputRoot = null)
            {
                return RunPowerShell("$ErrorActionPreference = 'Stop'; & " +
                    Quote(Path.Combine(RepositoryRoot, "scripts", "Prepare-SdkHeaders.ps1")) +
                    " -Recipe " + Quote(this.recipe) + " -SourceRoot " + Quote(this.source) +
                    " -SdkPackageRoot " + Quote(this.sdk) + " -OutputRoot " + Quote(outputRoot ?? Output) +
                    " | ConvertTo-Json -Compress", workingDirectory, ambientInclude);
            }

            internal static void WriteGeneratedFile(string root, string relative, byte[] bytes)
            {
                string path = Path.Combine(root, relative);
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllBytes(path, bytes);
            }

            internal ProcessResult ReplaceSelectedHeaders(string[] partitions, string[] overlays,
                string selected = null, string assembled = null)
            {
                string inputs = Path.Combine(this.root, "source-replacement.json");
                File.WriteAllText(inputs, JsonSerializer.Serialize(new
                {
                    Selected = selected ?? SelectedSources,
                    Assembled = assembled ?? AssembledSources,
                    Partitions = partitions,
                    Overlays = overlays,
                }));
                return RunPowerShell(@"
                    $ErrorActionPreference = 'Stop'
                    Set-StrictMode -Version Latest
                    $tokens = $null
                    $errors = $null
                    $ast = [Management.Automation.Language.Parser]::ParseFile(
                        " + Quote(Path.Combine(RepositoryRoot, "scripts", "Build-WinHttpMigrationImage.ps1")) + @",
                        [ref]$tokens, [ref]$errors)
                    if ($errors.Count) { throw ($errors.Message -join [Environment]::NewLine) }
                    $definitions = @($ast.FindAll({
                        param($node)
                        $node -is [Management.Automation.Language.FunctionDefinitionAst] -and
                            $node.Name -ceq 'Set-SelectedHeaderSources'
                    }, $true))
                    $calls = @($ast.FindAll({
                        param($node)
                        $node -is [Management.Automation.Language.CommandAst] -and
                            $node.GetCommandName() -ceq 'Set-SelectedHeaderSources'
                    }, $true))
                    if ($definitions.Count -ne 1 -or $calls.Count -ne 1) {
                        throw 'The image helper must define and invoke selected-source replacement exactly once.'
                    }
                    . ([ScriptBlock]::Create($definitions[0].Extent.Text))
                    $fixture = Get-Content -LiteralPath " + Quote(inputs) + @" -Raw | ConvertFrom-Json
                    $removed = Set-SelectedHeaderSources $fixture.Selected $fixture.Assembled `
                        @($fixture.Partitions) @($fixture.Overlays)
                    if ($null -eq $removed -or $removed.GetType() -ne [string[]]) {
                        throw 'Removed-source provenance must be a string array, including when empty.'
                    }
                    ConvertTo-Json -InputObject $removed -Compress
                    ");
            }

            private ProcessResult RunPowerShell(string command, string workingDirectory = null, string ambientInclude = null)
            {
                var start = new ProcessStartInfo("pwsh")
                {
                    WorkingDirectory = workingDirectory ?? RepositoryRoot,
                    UseShellExecute = false,
                    CreateNoWindow = true,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                if (ambientInclude != null)
                {
                    start.Environment["INCLUDE"] = ambientInclude;
                    start.Environment["CL"] = "/I\"" + ambientInclude + "\"";
                }
                foreach (string argument in new[] { "-NoLogo", "-NoProfile", "-NonInteractive", "-Command" })
                {
                    start.ArgumentList.Add(argument);
                }

                start.ArgumentList.Add(command);
                return Execute(start);
            }

            internal ProcessResult RunSdkBuild(string target, string filter)
            {
                File.Delete(BuildEvents);
                string project = Path.Combine(this.root, "fixture.proj");
                new XDocument(new XElement("Project",
                    new XElement("PropertyGroup",
                        new XElement("RepoRootPath", RepositoryRoot + Path.DirectorySeparatorChar),
                        new XElement("ObjDir", Path.Combine(this.root, "obj"))),
                    new XElement("Import", new XAttribute("Project",
                        Path.Combine(RepositoryRoot, "generation", "WinSDK", "Windows.Win32.proj"))),
                    new XElement("PropertyGroup",
                        new XElement("SdkHeaderRecipe", this.recipe),
                        new XElement("SdkHeaderSourceRoot", this.source),
                        new XElement("SdkHeaderOutputRoot", Output),
                        new XElement("SdkHeaderSdkPackageRoot", this.sdk)),
                    Consumer("CompileIdls", "idl"),
                    Consumer("ScrapeHeaders", "headers", "CompileIdls"),
                    Consumer("ScrapeConstants", "constants", "ScrapeHeaders"),
                    new XElement("Target", new XAttribute("Name", "RecordPreparation"),
                        new XAttribute("AfterTargets", "PrepareSdkHeaders"), Record("prepare")))).Save(project);
                var start = new ProcessStartInfo("dotnet")
                {
                    WorkingDirectory = RepositoryRoot,
                    UseShellExecute = false,
                    CreateNoWindow = true,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                foreach (string argument in new[] { "msbuild", project, "-nologo", "-v:minimal", "-t:" + target,
                    "-p:PartitionFilter=" + filter })
                    start.ArgumentList.Add(argument);
                return Execute(start);

                XElement Record(string name) => new XElement("WriteLinesToFile",
                    new XAttribute("File", BuildEvents), new XAttribute("Lines", name + "|$(SdkIncRoot)"));

                XElement Consumer(string name, string label, string dependencies = "") => new XElement("Target",
                    new XAttribute("Name", name), new XAttribute("DependsOnTargets", dependencies), Record(label));
            }

            private static ProcessResult Execute(ProcessStartInfo start)
            {
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                if (!process.WaitForExit(30000))
                {
                    process.Kill(entireProcessTree: true);
                    throw new TimeoutException("Header preparation/build did not terminate.");
                }

                return new ProcessResult(process.ExitCode, output.GetAwaiter().GetResult(), error.GetAwaiter().GetResult());
            }

            public void Dispose() => Directory.Delete(this.root, recursive: true);

            private static string Hash(byte[] bytes) => Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(bytes));
            private static string Quote(string value) => "'" + value.Replace("'", "''") + "'";
        }

        public sealed class PreparationResult
        {
            public string IncludeRoot { get; set; }
            public string Identity { get; set; }
            public bool Reused { get; set; }
        }

        private sealed record ProcessResult(int ExitCode, string Output, string Error);
    }
}
