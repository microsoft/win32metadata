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
        [Theory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SdkBuildFramesRetainedNativeDiagnosticsWithoutReclassifyingThem(string architecture)
        {
            using var fixture = new Fixture();
            fixture.UsePrivatePreparationScripts();
            string diagnostic = "Retained categorized diagnostics:\n" + string.Join("\n",
                Enumerable.Range(0, 13).Select(index =>
                    $"native.idl({index + 1}): error MIDL2337 : unsatisfied forward declaration : FORWARD_{index}"));
            fixture.InsertPreparationDiagnostic("Write-Warning '" + diagnostic + "'");

            var result = fixture.RunSdkBuild("ScrapeConstants", "Sample", architecture);

            Assert.True(result.ExitCode == 0, result.Error + result.Output);
            Assert.Contains("retained non-blocking diagnostic output", result.Output);
            string[][] events = File.ReadAllLines(fixture.BuildEvents).Select(line => line.Split('|')).ToArray();
            Assert.Equal(new[] { "prepare", "idl", "headers", "constants" }, events.Select(entry => entry[0]));
            Assert.All(events, entry => Assert.Equal(events[0][1], entry[1]));
            string retained = File.ReadAllText(fixture.PreparationWarnings(architecture));
            Assert.Contains(diagnostic, retained.Replace("\r\n", "\n"));
            fixture.AssertPublishedProvenance(events[0][1], hasMidl: false, architecture);
        }

        [Theory]
        [InlineData("Write-Error 'native.idl(1): error MIDL2025 : actual native failure'; exit 1", "MIDL2025")]
        [InlineData("[Console]::Error.WriteLine('native.idl(1): error MIDL2025 : actual native failure')", "MIDL2025")]
        [InlineData("throw 'native input hash changed'", "native input hash changed")]
        public void SdkBuildStillRejectsErrorsAndNativeFailureWithTheDiagnosticEnvelope(string command, string diagnostic)
        {
            using var fixture = new Fixture();
            fixture.UsePrivatePreparationScripts();
            fixture.InsertPreparationDiagnostic(command);

            var result = fixture.RunSdkBuild("ScrapeConstants", "Sample");

            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(diagnostic, result.Output + result.Error);
            Assert.False(File.Exists(fixture.BuildEvents));
        }

        [Fact]
        public void SdkBuildStillRequiresExactlyOnePreparedIncludeRoot()
        {
            using var fixture = new Fixture();
            fixture.UsePrivatePreparationScripts();
            fixture.InsertPreparationDiagnostic("[pscustomobject]@{ IncludeRoot = 'another-root' }");

            var result = fixture.RunSdkBuild("ScrapeConstants", "Sample");

            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("did not return exactly one private include root", result.Output + result.Error);
            Assert.False(File.Exists(fixture.BuildEvents));
        }

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

        [Fact]
        public void FailedAtomicPublicationRetainsDiagnosticsWithoutPublishingOrReusingTheTree()
        {
            using var fixture = new Fixture();
            fixture.UsePrivatePreparationScripts();
            string script = fixture.PreparationScript("Prepare-SdkHeaders.ps1");
            string original = File.ReadAllText(script);
            const string move = "[IO.Directory]::Move($staging, $destination)";
            Assert.Contains(move, original);
            File.WriteAllText(script, original.Replace(move,
                "$publicationTestHandle = [IO.File]::Open(\"$staging\\headers\\um\\sample.h\", " +
                "[IO.FileMode]::Open, [IO.FileAccess]::Read, [IO.FileShare]::Read)\n        " + move));

            var failed = fixture.Run();
            Assert.NotEqual(0, failed.ExitCode);
            Assert.Contains("Atomic publication failed (0x80070005)", failed.Output);
            Assert.Contains("It is not a valid prepared-header cache", failed.Output);
            string staging = Assert.Single(Directory.GetDirectories(fixture.Output));
            Assert.StartsWith("staging-", Path.GetFileName(staging));
            Assert.True(File.Exists(Path.Combine(staging, "manifest.json")));
            using var diagnostic = JsonDocument.Parse(File.ReadAllText(Path.Combine(staging, "publication-failure.json")));
            Assert.Equal("failed-unpublished", diagnostic.RootElement.GetProperty("status").GetString());
            Assert.Equal("0x80070005", diagnostic.RootElement.GetProperty("hResult").GetString());
            Assert.Equal(staging, diagnostic.RootElement.GetProperty("staging").GetString());
            Assert.False(diagnostic.RootElement.GetProperty("destinationExists").GetBoolean());
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
            byte[] failedHeader = File.ReadAllBytes(Path.Combine(staging, "headers", "um", "sample.h"));
            Assert.Equal(Encoding.ASCII.GetBytes(Fixture.Before.Replace("VALUE 1", "VALUE 2")), failedHeader);

            File.WriteAllText(script, original);
            var prepared = fixture.Prepare();
            Assert.False(prepared.Reused);
            Assert.NotEqual(Path.Combine(staging, "headers"), prepared.IncludeRoot);
            Assert.Equal(failedHeader, File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "um", "sample.h")));
            Assert.Equal(failedHeader, File.ReadAllBytes(Path.Combine(staging, "headers", "um", "sample.h")));
            Assert.True(fixture.Prepare().Reused);
        }

        [Theory]
        [InlineData("// annotation", true)]
        [InlineData("// annotation ", false)]
        [InlineData("// annotation\t", false)]
        [InlineData(" \t// annotation", false)]
        public void FirstLineCrLfInsertionsKeepStrictWhitespaceValidation(string firstLine, bool accepted)
        {
            using var fixture = new Fixture();
            fixture.WriteFirstLinePatch(firstLine);
            var result = fixture.Run();
            if (accepted)
            {
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                var prepared = JsonSerializer.Deserialize<PreparationResult>(result.Output);
                Assert.Equal(Encoding.ASCII.GetBytes(firstLine + "\r\n" + Fixture.Before),
                    File.ReadAllBytes(Path.Combine(prepared.IncludeRoot, "um", "sample.h")));
            }
            else
            {
                Assert.NotEqual(0, result.ExitCode);
                Assert.Contains("Patch preflight failed", result.Error);
                Assert.Contains("whitespace", result.Error);
                Assert.Empty(Directory.GetDirectories(fixture.Output));
            }
            Assert.Equal(Encoding.ASCII.GetBytes(Fixture.Before), File.ReadAllBytes(fixture.Header));
            Assert.Equal(Encoding.ASCII.GetBytes(Fixture.Before), File.ReadAllBytes(fixture.SdkHeader));
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

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void SdkBuildPreservesTheActualMidlClosureBesideGeneratedAssets(bool reuseMidl)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            PreparationResult first = null;
            if (reuseMidl)
            {
                first = fixture.Prepare();
                fixture.WritePatch(3);
            }
            var result = fixture.RunSdkBuild("ScrapeConstants", "Sample");
            Assert.True(result.ExitCode == 0, result.Error + result.Output);
            string includeRoot = File.ReadAllLines(fixture.BuildEvents)[0].Split('|')[1];
            fixture.AssertPublishedProvenance(includeRoot, hasMidl: true);
            using var manifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(includeRoot), "manifest.json")));
            Assert.Equal(reuseMidl, manifest.RootElement.GetProperty("midlReusedFrom").ValueKind != JsonValueKind.Null);
            Assert.Equal(reuseMidl ? first.Identity : Path.GetFileName(Path.GetDirectoryName(includeRoot)),
                manifest.RootElement.GetProperty("midlProducerIdentity").GetString());
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
            AssertRemoteRetvalParameter(File.ReadAllText(header));
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

        [Theory]
        [InlineData("GeNeRaTeD.idl", "GeNeRaTeD.h")]
        [InlineData("GeNeRaTeD.idl", "generated.h")]
        [InlineData("generated.idl", "GeNeRaTeD.h")]
        public void MidlCommandSpellingsPreserveTheOriginalRecompiledMirror(string input, string output)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            File.AppendAllText(fixture.MidlInput, "\r\ntypedef struct { long code; } ANONYMOUS_RECORD;\r\n");
            fixture.MutateRecipe(recipe =>
            {
                string hash = Fixture.Hash(File.ReadAllBytes(fixture.MidlInput));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var original = fixture.Prepare();
            byte[] header = File.ReadAllBytes(Path.Combine(original.IncludeRoot, "um", "generated.h"));
            Assert.Contains("__MIDL___MIDL_itf_generated_", Encoding.UTF8.GetString(header));
            fixture.MutateRecipe(recipe =>
            {
                recipe["midl"]["outputs"][1]["source"] = @"um\" + input;
                recipe["midl"]["outputs"][1]["path"] = @"um\" + output;
            });
            var current = fixture.Prepare();
            Assert.False(current.Reused);
            Assert.False(current.MidlReused);
            Assert.NotEqual(original.Identity, current.Identity);
            Assert.Equal(header, File.ReadAllBytes(Path.Combine(current.IncludeRoot, "um", output)));
            using var commands = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(current.IncludeRoot), "midl", "commands.json")));
            var command = commands.RootElement.EnumerateArray().Single(item =>
                item.GetProperty("source").GetString() == @"um\" + input);
            string[] arguments = command.GetProperty("arguments").EnumerateArray().Select(value => value.GetString()).ToArray();
            Assert.EndsWith(@"\generated.idl", arguments[0], StringComparison.Ordinal);
            Assert.StartsWith("<prepared>", arguments[0], StringComparison.Ordinal);
            Assert.EndsWith(@"\generated.h", arguments[Array.IndexOf(arguments, "/header") + 1], StringComparison.Ordinal);
            Assert.DoesNotContain("staging-", command.GetRawText(), StringComparison.OrdinalIgnoreCase);
            Assert.Equal(0, command.GetProperty("exitCode").GetInt32());
            Assert.Equal(Fixture.Hash(header), command.GetProperty("headerSha256").GetString());
            Assert.True(fixture.Prepare().Reused);
        }

        [Theory]
        [InlineData("inputs")]
        [InlineData("outputs")]
        public void MidlCaseOnlyClosureAmbiguitiesFailBeforeProduction(string collection)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.MutateRecipe(recipe =>
            {
                var entries = recipe["midl"][collection].AsArray();
                var duplicate = JsonNode.Parse(entries[0].ToJsonString());
                duplicate["path"] = duplicate["path"].GetValue<string>().ToUpperInvariant();
                entries.Add(duplicate);
            });
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("MIDL", result.Error);
            Assert.Empty(Directory.GetDirectories(fixture.Output));
        }

        [Theory]
        [InlineData("tagSTGC")]
        [InlineData("STGC")]
        public void ExistingEnumFlagsCommentsSurviveOriginalIdlAndInvalidatePreparation(string stgc)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            string declarations = HeaderAnnotationWinmdTests.ExistingEnumFlagDeclarations
                .Replace("ENUM_FLAGS", "").Split("struct ENUM_STORAGE", StringSplitOptions.None)[0];
            File.AppendAllText(fixture.MidlInput, declarations);
            fixture.MutateRecipe(recipe =>
            {
                string hash = Fixture.Hash(File.ReadAllBytes(fixture.MidlInput));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var before = fixture.Prepare();
            string[] facts = { $"/* Win32Metadata: enum ::{stgc} => Flags */", "/* Win32Metadata: enum ::VARENUM => Flags */" };
            File.AppendAllText(fixture.MidlInput, string.Join("\r\n", facts.Select(fact => "cpp_quote(\"" + fact + "\")")) + "\r\n");
            fixture.MutateRecipe(recipe =>
            {
                string hash = Fixture.Hash(File.ReadAllBytes(fixture.MidlInput));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var after = fixture.Prepare();
            Assert.False(after.Reused);
            Assert.False(after.MidlReused);
            Assert.NotEqual(before.Identity, after.Identity);
            string header = File.ReadAllText(Path.Combine(after.IncludeRoot, "um", "generated.h"));
            Assert.All(facts, fact => Assert.Contains(fact, header));
            Assert.DoesNotContain("flag_enum", header);
            Assert.Contains("enum tagSTGC", header);
            Assert.Contains("enum VARENUM", header);
            Assert.Contains("VT_TYPEMASK", header);
        }

        [Theory]
        [InlineData(1)]
        [InlineData(2)]
        public void Midl2337PublishesVisibleCategorizedDiagnosticsWithoutAFileSpecificBaseline(int count)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl2337(count);
            var first = fixture.Prepare(captureMidlWarnings: true);
            Assert.Contains("Non-blocking MIDL2337", File.ReadAllText(fixture.MidlWarnings));
            Assert.Contains($"count {count}", File.ReadAllText(fixture.MidlWarnings));
            string cache = Path.GetDirectoryName(first.IncludeRoot);
            using var manifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(cache, "manifest.json")));
            Assert.Equal(count, manifest.RootElement.GetProperty("midlNonBlockingErrorCount").GetInt32());
            Assert.Equal(count, manifest.RootElement.GetProperty("midlNonBlockingErrorCounts")
                .GetProperty("MIDL2337").GetInt32());
            using var diagnostics = JsonDocument.Parse(File.ReadAllText(Path.Combine(cache, "midl", "categorized-diagnostics.json")));
            Assert.Equal(count, diagnostics.RootElement.GetProperty("count").GetInt32());
            var command = Assert.Single(diagnostics.RootElement.GetProperty("commands").EnumerateArray());
            Assert.Equal(@"um\generated.idl", command.GetProperty("source").GetString());
            Assert.Equal(0, command.GetProperty("exitCode").GetInt32());
            Assert.Equal(count, command.GetProperty("nonBlockingErrorCount").GetInt32());
            Assert.Equal(count, command.GetProperty("nonBlockingErrors").GetArrayLength());
            Assert.All(command.GetProperty("nonBlockingErrors").EnumerateArray(),
                diagnostic => Assert.Contains("error MIDL2337", diagnostic.GetString()));
            string log = Path.Combine(cache, "midl", "generated", "generated.log");
            Assert.Contains("error MIDL2337", File.ReadAllText(log));
            Assert.Equal(Fixture.Hash(File.ReadAllBytes(log)), command.GetProperty("logSha256").GetString());
            Assert.False(Directory.Exists(Path.Combine(cache, "midl", "baseline-propsys")));
            Assert.False(File.Exists(Path.Combine(cache, "midl", "baseline-errors.json")));

            Assert.True(fixture.Prepare(captureMidlWarnings: true).Reused);
            fixture.WritePatch(3);
            var reused = fixture.Prepare(captureMidlWarnings: true);
            Assert.True(reused.MidlReused);
            AssertMidlProductionEqual(first, reused);
        }

        [Theory]
        [InlineData("native-patch")]
        [InlineData("unrelated-mirror")]
        [InlineData("unrelated-admission")]
        public void UnrelatedNativeChangesReuseTheExactMidlProduction(string mutation)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            byte[] original = File.ReadAllBytes(fixture.MidlInput);
            var first = fixture.Prepare();
            Assert.False(first.MidlReused);
            switch (mutation)
            {
                case "native-patch":
                    fixture.WritePatch(3);
                    break;
                case "unrelated-mirror":
                    File.AppendAllText(fixture.Unrelated, "// unrelated\r\n");
                    break;
                case "unrelated-admission":
                    fixture.AddUnrelatedIdlBackedHeader();
                    break;
            }

            var changed = fixture.Prepare();
            Assert.False(changed.Reused);
            Assert.True(changed.MidlReused);
            Assert.NotEqual(first.Identity, changed.Identity);
            AssertMidlProductionEqual(first, changed);
            using (var manifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(changed.IncludeRoot), "manifest.json"))))
            {
                Assert.Equal(first.Identity, manifest.RootElement.GetProperty("midlReusedFrom").GetString());
                Assert.Equal(first.Identity, manifest.RootElement.GetProperty("midlProducerIdentity").GetString());
            }

            fixture.WritePatch(4);
            var third = fixture.Prepare();
            Assert.False(third.Reused);
            Assert.True(third.MidlReused);
            AssertMidlProductionEqual(first, third);
            using var thirdManifest = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(third.IncludeRoot), "manifest.json")));
            Assert.Equal(first.Identity, thirdManifest.RootElement.GetProperty("midlProducerIdentity").GetString());
            Assert.Contains("VALUE 4", File.ReadAllText(Path.Combine(third.IncludeRoot, "um", "sample.h")));
            Assert.Contains("VALUE 2", File.ReadAllText(Path.Combine(first.IncludeRoot, "um", "sample.h")));
            Assert.Equal(original, File.ReadAllBytes(fixture.MidlInput));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
            Assert.True(fixture.Prepare().MidlReused);
        }

        [Theory]
        [InlineData("idl-patch")]
        [InlineData("dependency")]
        [InlineData("repository-helper")]
        [InlineData("shared-header-patch")]
        [InlineData("output-closure")]
        [InlineData("compiler-path")]
        public void ChangedMidlInputsAndOutputContractsRequireNewProduction(string mutation)
        {
            using var fixture = new Fixture();
            if (mutation == "repository-helper")
                fixture.EnableMidlAnnotationHeader();
            else if (mutation == "shared-header-patch")
                fixture.EnableMidlSharedHeader();
            else
                fixture.EnableMidl();
            var first = fixture.Prepare();
            switch (mutation)
            {
                case "idl-patch":
                    fixture.ReplacePatchText(Fixture.IdlPatchPath,
                        "+cpp_quote(\"#define IDL_VALUE 2\")", "+cpp_quote(\"#define IDL_VALUE 3\")");
                    break;
                case "dependency":
                    File.AppendAllText(fixture.MidlDependency, "typedef unsigned long NEW_DEPENDENCY;\r\n");
                    fixture.MutateRecipe(recipe =>
                    {
                        string hash = Fixture.Hash(File.ReadAllBytes(fixture.MidlDependency));
                        recipe["midl"]["inputs"][1]["sdkSha256"] = hash;
                        recipe["headers"][2]["sdkSha256"] = hash;
                    });
                    break;
                case "repository-helper":
                    File.AppendAllText(fixture.AnnotationHeader, "\r\n// changed helper\r\n");
                    fixture.MutateRecipe(recipe => recipe["midl"]["inputs"][2]["sourceSha256"] =
                        Fixture.Hash(File.ReadAllBytes(fixture.AnnotationHeader)));
                    break;
                case "shared-header-patch":
                    fixture.ReplacePatchText(Fixture.PatchPath, "+#define VALUE 2\r\n",
                        "+#define VALUE 2 // changed closure input\r\n");
                    break;
                case "output-closure":
                    fixture.EnableIncludedMidl();
                    break;
                case "compiler-path":
                    string tools = Path.Combine(Path.GetDirectoryName(fixture.MidlCompiler), "alternate");
                    Directory.CreateDirectory(tools);
                    foreach (string name in new[] { "midl.exe", "midlc.exe" })
                        File.Copy(Path.Combine(Path.GetDirectoryName(fixture.MidlCompiler), name), Path.Combine(tools, name));
                    fixture.MutateRecipe(recipe =>
                    {
                        recipe["midl"]["tools"][0]["sdkPath"] = @"c\bin\x64\alternate\midl.exe";
                        recipe["midl"]["tools"][1]["sdkPath"] = @"c\bin\x64\alternate\midlc.exe";
                    });
                    break;
            }

            var changed = fixture.Prepare();
            Assert.False(changed.Reused);
            Assert.False(changed.MidlReused);
            Assert.NotEqual(first.Identity, changed.Identity);
            using var before = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(first.IncludeRoot), "manifest.json")));
            using var after = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Path.GetDirectoryName(changed.IncludeRoot), "manifest.json")));
            Assert.NotEqual(before.RootElement.GetProperty("midlIdentity").GetString(),
                after.RootElement.GetProperty("midlIdentity").GetString());
            Assert.Equal(JsonValueKind.Null, after.RootElement.GetProperty("midlReusedFrom").ValueKind);
            Assert.Equal(changed.Identity, after.RootElement.GetProperty("midlProducerIdentity").GetString());
            if (mutation == "idl-patch")
                Assert.Contains("IDL_VALUE 3", File.ReadAllText(Path.Combine(changed.IncludeRoot, "um", "generated.h")));
            if (mutation == "dependency")
                Assert.Contains("NEW_DEPENDENCY", File.ReadAllText(Path.Combine(changed.IncludeRoot, "um", "dependency.h")));
            if (mutation == "output-closure")
                Assert.Contains("IDL_VALUE 2", File.ReadAllText(Path.Combine(changed.IncludeRoot, "um", "including.h")));
        }

        [Theory]
        [InlineData("Prepare-SdkHeaders.ps1")]
        [InlineData("MidlHeaderUtils.ps1")]
        [InlineData("ConvertMidlAttributesToSalAnnotations.ps1")]
        public void ChangedMidlScriptsAndArgumentsRequireNewProduction(string script)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.UsePrivatePreparationScripts();
            var first = fixture.Prepare();
            string path = fixture.PreparationScript(script);
            if (script == "MidlHeaderUtils.ps1")
                File.WriteAllText(path, File.ReadAllText(path).Replace("'/DUNICODE'", "'/DTEST_MIDL_REUSE=1', '/DUNICODE'"));
            else
                File.AppendAllText(path, "\r\n# Changed producer script\r\n");

            var changed = fixture.Prepare();
            Assert.False(changed.Reused);
            Assert.False(changed.MidlReused);
            Assert.NotEqual(first.Identity, changed.Identity);
            if (script == "MidlHeaderUtils.ps1")
                Assert.Contains("/DTEST_MIDL_REUSE=1", File.ReadAllText(Path.Combine(
                    Path.GetDirectoryName(changed.IncludeRoot), "midl", "commands.json")));
        }

        [Theory]
        [InlineData("generated-header")]
        [InlineData("commands")]
        [InlineData("preprocessed-inputs")]
        [InlineData("missing-midl")]
        public void NativeChangesCannotReuseTamperedOrIncompleteMidlProduction(string mutation)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            var first = fixture.Prepare();
            string midl = Path.Combine(Path.GetDirectoryName(first.IncludeRoot), "midl");
            if (mutation == "missing-midl")
                Directory.Move(midl, midl + "-moved");
            else
            {
                string path = mutation == "generated-header" ? Path.Combine("generated", "um", "generated.h") :
                    mutation == "commands" ? "commands.json" : "preprocessed-inputs.json";
                File.AppendAllText(Path.Combine(midl, path), "\r\nchanged\r\n");
            }
            fixture.WritePatch(3);
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(mutation == "missing-midl" ? "Incomplete published MIDL cache" :
                "Published MIDL cache was modified", result.Error);
            Assert.Single(Directory.GetDirectories(fixture.Output));
            Assert.Contains("VALUE 2", File.ReadAllText(Path.Combine(first.IncludeRoot, "um", "sample.h")));
            Assert.Equal(Fixture.Before, File.ReadAllText(fixture.Header));
        }

        [Fact]
        public void UnkeyedLegacyMidlProductionIsNotAssumedReusable()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            var first = fixture.Prepare();
            string path = Path.Combine(Path.GetDirectoryName(first.IncludeRoot), "manifest.json");
            var manifest = JsonNode.Parse(File.ReadAllText(path)).AsObject();
            manifest.Remove("midlIdentity");
            manifest.Remove("midlProducerIdentity");
            manifest.Remove("midlReusedFrom");
            File.WriteAllText(path, manifest.ToJsonString());
            fixture.WritePatch(3);
            var changed = fixture.Prepare();
            Assert.False(changed.Reused);
            Assert.False(changed.MidlReused);
            Assert.NotEqual(first.Identity, changed.Identity);
        }

        private static void AssertMidlProductionEqual(PreparationResult first, PreparationResult second)
        {
            string before = Path.Combine(Path.GetDirectoryName(first.IncludeRoot), "midl");
            string after = Path.Combine(Path.GetDirectoryName(second.IncludeRoot), "midl");
            string[] files = Directory.GetFiles(before, "*", SearchOption.AllDirectories)
                .Select(path => Path.GetRelativePath(before, path)).OrderBy(path => path, StringComparer.Ordinal).ToArray();
            Assert.Contains("commands.json", files);
            Assert.Contains("preprocessed-inputs.json", files);
            Assert.Contains(Path.Combine("generated", "generated.log"), files);
            Assert.Equal(files, Directory.GetFiles(after, "*", SearchOption.AllDirectories)
                .Select(path => Path.GetRelativePath(after, path)).OrderBy(path => path, StringComparer.Ordinal));
            foreach (string path in files)
                Assert.Equal(File.ReadAllBytes(Path.Combine(before, path)), File.ReadAllBytes(Path.Combine(after, path)));
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
                AssertRemoteRetvalParameter(header);
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

        [Theory]
        [InlineData(@"um\dependency.idl", true)]
        [InlineData(@"um\..\um\dependency.idl", false)]
        [InlineData(@"um\unbound.idl", false)]
        [InlineData(@"..\other\dependency.idl", false)]
        public void RepeatedMidlPreprocessorPathsRequireExactCanonicalDeclaredInputs(string path, bool accepted)
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            fixture.AddMidlPreprocessorTrace(path);
            var result = fixture.Run();
            if (accepted)
            {
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                var prepared = JsonSerializer.Deserialize<PreparationResult>(result.Output);
                using var inputs = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                    Path.GetDirectoryName(prepared.IncludeRoot), "midl", "preprocessed-inputs.json")));
                Assert.Equal(new[] { @"um\dependency.idl", @"um\generated.idl" },
                    inputs.RootElement.EnumerateArray().Select(value => value.GetString()));
            }
            else
            {
                Assert.NotEqual(0, result.ExitCode);
                Assert.Contains("MIDL preprocessing read an unpinned input", result.Error);
                Assert.Empty(Directory.GetDirectories(fixture.Output));
            }
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
            const string expected = "void F([out, retval][annotation(\"_Out_ _Win32_Retval_\")] long* value, [in][annotation(\"_In_\")] long count);\n" +
                "void G([out, retval][annotation(\"_Out_retval_\")] long* value, [in][annotation(\"_In_\")] long count);\n" +
                "void H([out, retval][annotation(\"_Out_ _Win32_Retval_\")] long* value);\n" +
                "cpp_quote(\"void Native([out] long* value);\")\n";
            Assert.Equal(expected, converted.Replace("\r\n", "\n"));
            Assert.Equal(1, converted.Split("_Out_retval_").Length - 1);
            Assert.DoesNotContain("_COM_Outptr_retval_", converted);
            Assert.Equal(2, converted.Split("[annotation(\"_In_\")]").Length - 1);
            Assert.Contains("cpp_quote(\"void Native([out] long* value);\")", converted);
        }

        private static void AssertRemoteRetvalParameter(string header)
        {
            Assert.Contains("/* [annotation][out] */ \n    _Win32_Retval_  DEPENDENCY *result);",
                header.Replace("\r\n", "\n"));
            Assert.DoesNotContain("_Out_", header);
            Assert.DoesNotContain("_Out_retval_", header);
            Assert.DoesNotContain("_COM_Outptr_retval_", header);
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
            private string scripts;

            internal Fixture()
            {
                var directory = new DirectoryInfo(AppContext.BaseDirectory);
                while (directory != null && !File.Exists(Path.Combine(directory.FullName, "scripts", "Prepare-SdkHeaders.ps1")))
                {
                    directory = directory.Parent;
                }

                RepositoryRoot = directory?.FullName ?? throw new InvalidOperationException("Repository scripts were not found.");
                this.scripts = Path.Combine(RepositoryRoot, "scripts");
                // Native process launch fails when nested snapshots push MIDL's working directory past MAX_PATH.
                this.root = Path.Combine(Path.GetTempPath(), "prepared-header-tests-" + Guid.NewGuid().ToString("N"));
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
            internal string MidlWarnings => Path.Combine(this.root, "midl-warnings.log");
            internal string PreparationWarnings(string architecture) => Path.Combine(this.root,
                "obj", "prepared-sdk-provenance", architecture, "preparation.warnings.log");
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

            internal void WriteFirstLinePatch(string firstLine)
            {
                string text = "diff --git a/um/sample.h b/um/sample.h\n" +
                    "--- a/um/sample.h\n+++ b/um/sample.h\n@@ -1,4 +1,5 @@\n" +
                    "+" + firstLine + "\r\n #ifndef SAMPLE_H\r\n #define SAMPLE_H\r\n" +
                    " #define VALUE 1\r\n #endif\r\n";
                File.WriteAllText(this.patch, text, new UTF8Encoding(false));
            }

            internal void CopyPatch(string source, string target)
            {
                string path = Path.Combine(this.root, target);
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.Copy(Path.Combine(this.root, source), path);
            }

            internal void ReplacePatchText(string path, string before, string after)
            {
                string file = Path.Combine(this.root, path);
                string text = File.ReadAllText(file);
                Assert.Contains(before, text);
                File.WriteAllText(file, text.Replace(before, after));
            }

            internal string PreparationScript(string name) => Path.Combine(this.scripts, name);

            internal void UsePrivatePreparationScripts()
            {
                this.scripts = Path.Combine(this.root, "preparation", "scripts");
                Directory.CreateDirectory(this.scripts);
                foreach (string name in new[] { "Prepare-SdkHeaders.ps1", "MidlHeaderUtils.ps1",
                    "ConvertMidlAttributesToSalAnnotations.ps1", "CommonUtils.ps1", "Get-VSPath.ps1",
                    "Get-RequiredWorkloads.ps1", "Get-VSWhereBaseArgs.ps1" })
                    File.Copy(Path.Combine(RepositoryRoot, "scripts", name), PreparationScript(name));
                var start = new ProcessStartInfo("git")
                {
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                foreach (string argument in new[] { "init", "--quiet", Path.GetDirectoryName(this.scripts) })
                    start.ArgumentList.Add(argument);
                var result = Execute(start);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
            }

            internal void InsertPreparationDiagnostic(string command)
            {
                string path = PreparationScript("Prepare-SdkHeaders.ps1");
                string text = File.ReadAllText(path);
                string newline = text.Contains("\r\n", StringComparison.Ordinal) ? "\r\n" : "\n";
                string result = "    [pscustomobject]@{" + newline + "        IncludeRoot = \"$destination\\headers\"";
                Assert.Contains(result, text);
                File.WriteAllText(path, text.Replace(result, command + "\n" + result));
            }

            internal void AddMidlPreprocessorTrace(string relative)
            {
                UsePrivatePreparationScripts();
                string path = PreparationScript("Prepare-SdkHeaders.ps1");
                string text = File.ReadAllText(path);
                const string before = "foreach ($file in @(Get-ChildItem -LiteralPath $generated -Filter '*.tmp' -File)) {";
                const string after = "if (!$usedInputs.SetEquals([string[]]$midlInputs.path)) {";
                Assert.Contains(before, text);
                Assert.Contains(after, text);
                text = text.Replace(before, @"
                    $tracePath = $sal + '\' + " + Quote(relative) + @"
                    $line = '#line 1 ""' + $tracePath.Replace('\', '\\') + '""'
                    [IO.File]::WriteAllText(""$generated\repeated-input.tmp"", ($line + ""`n"") * 10000)
                    $originalResolver = ${function:Resolve-Child}
                    $script:traceResolutions = 0
                    function Resolve-Child([string]$Root, [string]$RelativePath) {
                        $script:traceResolutions++
                        & $originalResolver $Root $RelativePath
                    }
                    " + before);
                text = text.Replace(after, @"
                    if ($script:traceResolutions -gt $midlInputs.Count) {
                        throw 'MIDL path validation repeats filesystem resolution for the same declared inputs.'
                    }
                    " + after);
                File.WriteAllText(path, text);
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
                string compilerDirectory = Directory.GetDirectories(Path.Combine(package, "c", "bin"))
                    .Select(directory => Path.Combine(directory, "x64"))
                    .Single(directory => File.Exists(Path.Combine(directory, "midl.exe")));
                foreach (string name in new[] { "midl.exe", "midlc.exe" })
                    File.Copy(Path.Combine(compilerDirectory, name),
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

            internal void EnableMidl2337(int count)
            {
                EnableMidl();
                for (int i = 0; i < count; i++)
                {
                    File.AppendAllText(MidlInput, $"\r\ntypedef struct OPAQUE_{i}_ OPAQUE_{i};\r\n" +
                        $"typedef struct USE_{i}_ {{ [unique] OPAQUE_{i}* value; }} USE_{i};\r\n");
                }
                MutateRecipe(recipe =>
                {
                    string hash = Hash(File.ReadAllBytes(MidlInput));
                    recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                    recipe["headers"][1]["sdkSha256"] = hash;
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

            internal void AssertPublishedProvenance(string includeRoot, bool hasMidl = false, string architecture = "crossarch")
            {
                string cache = Path.GetDirectoryName(includeRoot);
                string published = Path.Combine(this.root, "obj", "prepared-sdk-provenance", architecture, Path.GetFileName(cache));
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

            internal PreparationResult Prepare(string workingDirectory = null, string outputRoot = null,
                bool captureMidlWarnings = false)
            {
                var result = Run(workingDirectory, outputRoot: outputRoot, captureMidlWarnings: captureMidlWarnings);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return JsonSerializer.Deserialize<PreparationResult>(result.Output);
            }

            internal ProcessResult Run(string workingDirectory = null, string ambientInclude = null, string outputRoot = null,
                bool captureMidlWarnings = false)
            {
                return RunPowerShell("$ErrorActionPreference = 'Stop'; & " +
                    Quote(PreparationScript("Prepare-SdkHeaders.ps1")) +
                    " -Recipe " + Quote(this.recipe) + " -SourceRoot " + Quote(this.source) +
                    " -SdkPackageRoot " + Quote(this.sdk) + " -OutputRoot " + Quote(outputRoot ?? Output) +
                    (captureMidlWarnings ? " 3> " + Quote(MidlWarnings) : "") +
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

            internal ProcessResult RunSdkBuild(string target, string filter, string architecture = "crossarch")
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
                    "-p:PartitionFilter=" + filter, "-p:ScanArch=" + architecture })
                    start.ArgumentList.Add(argument);
                if (this.scripts != Path.Combine(RepositoryRoot, "scripts"))
                    start.ArgumentList.Add("-p:RepoRootPath=" + Path.GetDirectoryName(this.scripts) + Path.DirectorySeparatorChar);
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

            internal static string Hash(byte[] bytes) => Convert.ToHexString(System.Security.Cryptography.SHA256.HashData(bytes));
            private static string Quote(string value) => "'" + value.Replace("'", "''") + "'";
        }

        public sealed class PreparationResult
        {
            public string IncludeRoot { get; set; }
            public string Identity { get; set; }
            public bool Reused { get; set; }
            public bool MidlReused { get; set; }
        }

        private sealed record ProcessResult(int ExitCode, string Output, string Error);
    }

    public sealed class MidlDiagnosticCategoryTests
    {
        [Theory]
        [InlineData(@"um\propsys.idl", " : error MIDL2337 : unsatisfied forward declaration : tagSERIALIZEDPROPSTORAGE", 1)]
        [InlineData(@"shared\iketypes.idl", " : error MIDL2337 : unsatisfied forward declaration : IPSEC_V4_UDP_ENCAPSULATION0_", 1)]
        [InlineData(@"winrt\another.idl", " : error MIDL2337 : another native forward declaration", 1)]
        [InlineData(@"um\new.idl", "error MIDL2337 : first\nerror MIDL2337 : second", 2)]
        [InlineData(@"um\new.idl", "error MIDL2337 : first; error MIDL2337 : second", 2)]
        [InlineData(@"um\new.idl", "midl : error MIDL2337 : native forward declaration", 1)]
        [InlineData(@"um\new.idl", "error midl2337 : native forward declaration", 1)]
        [InlineData(@"um\new.idl", "warning MIDL2495 : native warning", 0)]
        [InlineData(@"um\new.idl", "", 0)]
        public void OnlyTheCategoryAndSuccessfulCompleteOutputDetermineAdmission(string source, string text, int count)
        {
            using var fixture = new Fixture();
            var result = fixture.Check(source, 0, text);
            Assert.True(result.ExitCode == 0, result.Error + result.Output);
            using var diagnostics = JsonDocument.Parse(result.Output);
            Assert.Equal(count, diagnostics.RootElement.GetProperty("nonBlockingErrorCount").GetInt32());
            Assert.Equal(count, diagnostics.RootElement.GetProperty("nonBlockingErrorCounts")
                .GetProperty("MIDL2337").GetInt32());
            if (count != 0)
                Assert.Contains("2337", diagnostics.RootElement.GetProperty("nonBlockingErrors").ToString());
        }

        [Theory]
        [InlineData("error MIDL2025 : syntax error")]
        [InlineData("error MIDL23370 : another category")]
        [InlineData("error C1083 : missing include")]
        [InlineData("fatal error : native compiler failure")]
        [InlineData("fatal error C1001 : native compiler failure")]
        [InlineData("fatal error MIDL2337 : fatal compiler failure")]
        [InlineData("midl : error : native compiler failure")]
        [InlineData("error MIDL2337 : forward\nerror MIDL2025 : new error")]
        [InlineData("error MIDL2337 : forward\nerror C1083 : missing include")]
        [InlineData("error MIDL2337 : forward\nfatal error : native compiler failure")]
        [InlineData("error MIDL2337 : forward; error MIDL2025 : new error")]
        [InlineData("error C1083 : missing include; error MIDL2337 : forward")]
        [InlineData("error MIDL2337 : forward; midl : error : compiler failure")]
        public void EveryOtherErrorAndMixedErrorLogRemainBlocking(string text)
        {
            using var fixture = new Fixture();
            var result = fixture.Check(@"um\any.idl", 0, text);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("MIDL failed", result.Error);
            Assert.False(string.IsNullOrWhiteSpace(result.Error));
        }

        [Theory]
        [InlineData(1, "error MIDL2337 : forward")]
        [InlineData(2, "")]
        [InlineData(-1, "error MIDL2337 : forward")]
        public void NonzeroNativeExitsAlwaysFail(int exitCode, string text)
        {
            using var fixture = new Fixture();
            var result = fixture.Check(@"um\any.idl", exitCode, text);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains($"exit {exitCode}", result.Error);
        }

        [Theory]
        [InlineData("missing", true)]
        [InlineData("empty", true)]
        [InlineData("truncated", true)]
        [InlineData("missing-footer", true)]
        [InlineData("missing-cpp-close", true)]
        [InlineData("missing-extern", true)]
        [InlineData("missing-opening-guard", true)]
        [InlineData("mismatched-define", true)]
        [InlineData("missing-banner", true)]
        [InlineData("missing", false)]
        [InlineData("empty", false)]
        [InlineData("truncated", false)]
        public void MissingOrIncompleteHeadersFailEvenWithOnlyTheNonBlockingCategory(string mutation, bool diagnostic)
        {
            using var fixture = new Fixture();
            var result = fixture.Check(@"um\any.idl", 0, diagnostic ? "error MIDL2337 : forward" : "", mutation);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("header", result.Error);
        }

        private sealed class Fixture : IDisposable
        {
            private const string CompleteHeader = "/* File created by MIDL compiler */\n" +
                "#ifndef __sample_h__\n#define __sample_h__\n" +
                "#ifdef __cplusplus\nextern \"C\" {\n#endif\n" +
                "typedef long SAMPLE;\n#ifdef __cplusplus\n}\n#endif\n#endif\n";
            private readonly string repository;
            private readonly string root;

            internal Fixture()
            {
                var directory = new DirectoryInfo(AppContext.BaseDirectory);
                while (directory != null && !File.Exists(Path.Combine(directory.FullName, "scripts", "MidlHeaderUtils.ps1")))
                    directory = directory.Parent;
                this.repository = directory?.FullName ?? throw new InvalidOperationException("Repository scripts were not found.");
                this.root = Path.Combine(this.repository, "artifacts", "prepared-header-tests", "diagnostics-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(this.root);
            }

            internal ProcessResult Check(string source, int exitCode, string text, string mutation = null)
            {
                string header = Path.Combine(this.root, "sample.h");
                string value = CompleteHeader;
                switch (mutation)
                {
                    case "empty": value = ""; break;
                    case "truncated": value = value.Substring(0, value.Length / 2); break;
                    case "missing-footer": value = value.Substring(0, value.LastIndexOf("#endif", StringComparison.Ordinal)); break;
                    case "missing-cpp-close": value = value.Replace("}\n#endif\n#endif", "#endif\n#endif"); break;
                    case "missing-extern": value = value.Replace("extern \"C\" {", ""); break;
                    case "missing-opening-guard": value = value.Replace("#ifndef __sample_h__", "#if 1"); break;
                    case "mismatched-define": value = value.Replace("#define __sample_h__", "#define __other_h__"); break;
                    case "missing-banner": value = value.Replace("File created by MIDL compiler", "Other generated file"); break;
                }
                if (mutation != "missing")
                    File.WriteAllText(header, value);
                string inputs = Path.Combine(this.root, "inputs.json");
                File.WriteAllText(inputs, JsonSerializer.Serialize(new { source, exitCode, text, header }));
                var start = new ProcessStartInfo("pwsh")
                {
                    WorkingDirectory = this.repository,
                    UseShellExecute = false,
                    CreateNoWindow = true,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                string command = "$ErrorActionPreference='Stop'; Set-StrictMode -Version Latest; . " +
                    Quote(Path.Combine(this.repository, "scripts", "MidlHeaderUtils.ps1")) +
                    "; $input=Get-Content -LiteralPath " + Quote(inputs) + " -Raw | ConvertFrom-Json; " +
                    "Assert-MidlHeaderResult $input.source $input.exitCode $input.text $input.header | ConvertTo-Json -Depth 5 -Compress";
                foreach (string argument in new[] { "-NoLogo", "-NoProfile", "-NonInteractive", "-Command", command })
                    start.ArgumentList.Add(argument);
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                if (!process.WaitForExit(30000))
                {
                    process.Kill(entireProcessTree: true);
                    throw new TimeoutException("The bounded MIDL diagnostic check did not terminate.");
                }
                return new ProcessResult(process.ExitCode, output.GetAwaiter().GetResult(), error.GetAwaiter().GetResult());
            }

            private static string Quote(string value) => "'" + value.Replace("'", "''") + "'";
            public void Dispose() => Directory.Delete(this.root, recursive: true);
        }

        private sealed record ProcessResult(int ExitCode, string Output, string Error);
    }
}
