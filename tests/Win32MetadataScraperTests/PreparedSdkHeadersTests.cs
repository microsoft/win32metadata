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

            fixture.WriteRecipe(patches: new[] { @"post-midl\..\..\outside.patch" });
            var escape = fixture.Run();
            Assert.NotEqual(0, escape.ExitCode);
            Assert.Contains("escapes its root", escape.Error);
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
                previous = includeRoot;
            }
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
        public void ShippedIdlPatchesCannotMoveBackAfterMidlOrFollowHeaderPatches()
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
            var ordering = fixture.Run();
            Assert.NotEqual(0, ordering.ExitCode);
            Assert.Contains("wrong side of the MIDL boundary", ordering.Error);

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
            internal const string PatchPath = @"post-midl\um\sample.patch";
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
                SdkHeader = Path.Combine(this.sdk, "c", "include", "sample.h");
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
            internal string MidlInput => Path.Combine(this.sdk, "c", "include", "um", "generated.idl");
            internal string MidlDependency => Path.Combine(this.sdk, "c", "include", "um", "dependency.idl");
            internal string MidlCompiler => Path.Combine(this.sdk, "c", "bin", "x64", "midl.exe");
            internal string BuildEvents => Path.Combine(this.root, "build-events.txt");
            internal string[] ScrapeMarkers => new[] { "scannedheaders.crossarch.txt", "scannedheaders.x86.txt",
                "scannedheaders.x64.txt", "scannedheaders.arm64.txt", "constants.scraped.txt" }
                .Select(name => Path.Combine(this.root, "obj", "generated", name)).ToArray();

            internal void WritePatch(int after, int before = 1, string path = "um/sample.h", string metadata = null, string originalPath = null)
            {
                string prefix = "generation/WinSDK/RecompiledIdlHeaders/" + path;
                string oldPrefix = "generation/WinSDK/RecompiledIdlHeaders/" + (originalPath ?? path);
                string text = $"diff --git a/{oldPrefix} b/{prefix}\n{metadata}" +
                    $"--- a/{oldPrefix}\n+++ b/{prefix}\n@@ -1,4 +1,4 @@\n #ifndef SAMPLE_H\r\n #define SAMPLE_H\r\n" +
                    $"-#define VALUE {before}\r\n+#define VALUE {after}\r\n #endif\r\n";
                File.WriteAllText(this.patch, text, new UTF8Encoding(false));
            }

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
                            sdkPath = @"c\include\sample.h",
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
                const string prePatch = @"pre-midl\um\generated.patch";
                string patchFile = Path.Combine(this.root, prePatch);
                Directory.CreateDirectory(Path.GetDirectoryName(patchFile));
                File.WriteAllText(patchFile,
                    "diff --git a/generation/WinSDK/RecompiledIdlHeaders/um/generated.idl b/generation/WinSDK/RecompiledIdlHeaders/um/generated.idl\n" +
                    "--- a/generation/WinSDK/RecompiledIdlHeaders/um/generated.idl\n+++ b/generation/WinSDK/RecompiledIdlHeaders/um/generated.idl\n" +
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
                    recipe["patches"] = JsonSerializer.SerializeToNode(new[] { prePatch, PatchPath });
                });
            }

            internal void MutateRecipe(Action<JsonObject> mutate)
            {
                var recipe = JsonNode.Parse(File.ReadAllText(this.recipe)).AsObject();
                mutate(recipe);
                File.WriteAllText(this.recipe, recipe.ToJsonString());
            }

            internal void WriteGeneratedHeaderPatch()
            {
                const string relative = @"post-midl\um\generated.patch";
                File.WriteAllText(Path.Combine(this.root, relative),
                    "diff --git a/generation/WinSDK/RecompiledIdlHeaders/um/generated.h b/generation/WinSDK/RecompiledIdlHeaders/um/generated.h\n" +
                    "--- a/generation/WinSDK/RecompiledIdlHeaders/um/generated.h\n+++ b/generation/WinSDK/RecompiledIdlHeaders/um/generated.h\n" +
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

            internal PreparationResult Prepare(string workingDirectory = null, string outputRoot = null)
            {
                var result = Run(workingDirectory, outputRoot: outputRoot);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return JsonSerializer.Deserialize<PreparationResult>(result.Output);
            }

            internal ProcessResult Run(string workingDirectory = null, string ambientInclude = null, string outputRoot = null)
            {
                static string Quote(string value) => "'" + value.Replace("'", "''") + "'";
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

                start.ArgumentList.Add("$ErrorActionPreference = 'Stop'; & " +
                    Quote(Path.Combine(RepositoryRoot, "scripts", "Prepare-SdkHeaders.ps1")) +
                    " -Recipe " + Quote(this.recipe) + " -SourceRoot " + Quote(this.source) +
                    " -SdkPackageRoot " + Quote(this.sdk) + " -OutputRoot " + Quote(outputRoot ?? Output) +
                    " | ConvertTo-Json -Compress");
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
