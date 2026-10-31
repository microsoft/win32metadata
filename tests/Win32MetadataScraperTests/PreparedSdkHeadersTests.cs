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
        public void SdkBuildFramesRetainedNativeDiagnosticsWithoutReclassifyingThem()
        {
            const string architecture = "x64";
            using var fixture = new Fixture();
            fixture.UsePrivatePreparationScripts();
            string diagnostic = "Retained categorized diagnostics:\n" + string.Join("\n", Enumerable.Range(0, 13).Select(index => $"native.idl({index + 1}): error MIDL2337 : unsatisfied forward declaration : FORWARD_{index}"));
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
            Assert.Equal(Encoding.ASCII.GetBytes(Fixture.Before.Replace("VALUE 1", "VALUE 2")), File.ReadAllBytes(Path.Combine(first.IncludeRoot, "um", "sample.h")));
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

        [Fact]
        public void RemoteMidlRegenerationPreservesSynthesizedDirectionsAndCounts()
        {
            using var fixture = new Fixture();
            fixture.EnableMidl();
            File.WriteAllText(fixture.MidlInput, File.ReadAllText(fixture.MidlInput).Replace("void Read([out][annotation(\"_Win32_Retval_\")] DEPENDENCY* result);", "void Read([in] long count, [out, size_is(count), length_is(*read)] DEPENDENCY* values, [out] long* read);"));
            fixture.MutateRecipe(recipe =>
            {
                string hash = Fixture.Hash(File.ReadAllBytes(fixture.MidlInput));
                recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                recipe["headers"][1]["sdkSha256"] = hash;
            });
            var prepared = fixture.Prepare();
            string root = Path.GetDirectoryName(prepared.IncludeRoot);
            string converted = File.ReadAllText(Path.Combine(root, "midl", "sal", "um", "generated.idl"));
            Assert.Contains("[in][annotation(\"_In_\")] long count", converted);
            Assert.Contains("[out, size_is(count), length_is(*read)][annotation(\"_Out_writes_to_(count,*read)\")]", converted);
            Assert.Contains("[out][annotation(\"_Out_\")] long* read", converted);
            string header = File.ReadAllText(Path.Combine(prepared.IncludeRoot, "um", "generated.h"));
            Assert.Contains("_In_  long count", header);
            Assert.Contains("_Out_writes_to_(count,*read)  DEPENDENCY *values", header);
            Assert.Contains("_Out_  long *read", header);
            Assert.DoesNotContain("__RPC__out_ecount_part", header);
            using var commands = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "midl", "commands.json")));
            var command = Assert.Single(commands.RootElement.EnumerateArray(), value => value.GetProperty("source").GetString() == @"um\generated.idl");
            Assert.Equal(0, command.GetProperty("exitCode").GetInt32());
            Assert.Contains(command.GetProperty("warnings").EnumerateArray(), value => value.GetString().Contains("MIDL2495", StringComparison.Ordinal));
            Assert.Equal(Fixture.Hash(File.ReadAllBytes(Path.Combine(root, "midl", "generated", "generated.log"))), command.GetProperty("logSha256").GetString());
            string[] arguments = command.GetProperty("arguments").EnumerateArray().Select(value => value.GetString()).ToArray();
            Assert.DoesNotContain("/no_warn", arguments);
            Assert.DoesNotContain("/WX", arguments);
        }

        [Fact]
        public void SalConversionDoesNotSkipParametersBesideMetadataOrOtherAnnotations()
        {
            using var fixture = new Fixture();
            const string input = "void F([out, retval][annotation(\"_Win32_Retval_\")] long* value, [in] long count);\r\n" + "void G([out][retval][annotation(\"_Out_retval_\")] long* value, [in] long count);\r\n" + "void H([annotation(\"_Win32_Retval_\")][out][retval] long* value);\r\n" + "cpp_quote(\"void Native([out] long* value);\")\r\n";
            string converted = fixture.ConvertSal(input);
            const string expected = "void F([out, retval][annotation(\"_Out_ _Win32_Retval_\")] long* value, [in][annotation(\"_In_\")] long count);\n" + "void G([out, retval][annotation(\"_Out_retval_\")] long* value, [in][annotation(\"_In_\")] long count);\n" + "void H([out, retval][annotation(\"_Out_ _Win32_Retval_\")] long* value);\n" + "cpp_quote(\"void Native([out] long* value);\")\n";
            Assert.Equal(expected, converted.Replace("\r\n", "\n"));
            Assert.Equal(1, converted.Split("_Out_retval_").Length - 1);
            Assert.DoesNotContain("_COM_Outptr_retval_", converted);
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
                File.WriteAllText(Path.Combine(this.sdk, "microsoft.windows.sdk.cpp.nuspec"), "<package><metadata><version>10.0.26100.7705</version></metadata></package>");
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
            internal string PreparationWarnings(string architecture) => Path.Combine(this.root, "obj", "prepared-sdk-provenance", architecture, "preparation.warnings.log");
            internal string[] ScrapeMarkers => new[] { "scannedheaders.crossarch.txt", "scannedheaders.x86.txt", "scannedheaders.x64.txt", "scannedheaders.arm64.txt", "constants.scraped.txt" }.Select(name => Path.Combine(this.root, "obj", "generated", name)).ToArray();
            internal void WritePatch(int after, int before = 1, string path = "um/sample.h", string metadata = null, string originalPath = null)
            {
                string oldPath = originalPath ?? path;
                string text = $"diff --git a/{oldPath} b/{path}\n{metadata}" + $"--- a/{oldPath}\n+++ b/{path}\n@@ -1,4 +1,4 @@\n #ifndef SAMPLE_H\r\n #define SAMPLE_H\r\n" + $"-#define VALUE {before}\r\n+#define VALUE {after}\r\n #endif\r\n";
                File.WriteAllText(this.patch, text, new UTF8Encoding(false));
            }

            internal void WriteFirstLinePatch(string firstLine)
            {
                string text = "diff --git a/um/sample.h b/um/sample.h\n" + "--- a/um/sample.h\n+++ b/um/sample.h\n@@ -1,4 +1,5 @@\n" + "+" + firstLine + "\r\n #ifndef SAMPLE_H\r\n #define SAMPLE_H\r\n" + " #define VALUE 1\r\n #endif\r\n";
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
                foreach (string name in new[] { "Prepare-SdkHeaders.ps1", "MidlHeaderUtils.ps1", "ConvertMidlAttributesToSalAnnotations.ps1", "CommonUtils.ps1", "Get-VSPath.ps1", "Get-RequiredWorkloads.ps1", "Get-VSWhereBaseArgs.ps1" })
                    File.Copy(Path.Combine(RepositoryRoot, "scripts", name), PreparationScript(name));
                var start = new ProcessStartInfo("git")
                { UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true, };
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
                    headers = new[]{new
                {
                path = @"um\sample.h", sourceSha256 = Hash(Encoding.ASCII.GetBytes(Before)), sdkPath = @"c\include\um\sample.h", sdkSha256 = Hash(Encoding.ASCII.GetBytes(Before)), }

                , },
                    patches = patches ?? new[] { PatchPath },
                }

                ));
            }

            internal void EnableMidl()
            {
                WriteRecipe();
                string input = "cpp_quote(\"#define IDL_VALUE 1\")\r\nimport \"dependency.idl\";\r\n" + "[uuid(7a22f761-442c-4260-9d80-4c937dce56b6), version(1.0), pointer_default(unique)]\r\n" + "interface IMidlFixture { void Read([out][annotation(\"_Win32_Retval_\")] DEPENDENCY* result); };\r\n";
                const string dependency = "typedef long DEPENDENCY;\r\n";
                foreach (string path in new[] { MidlInput, MidlCompiler })
                    Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllText(MidlInput, input, new UTF8Encoding(false));
                File.WriteAllText(MidlDependency, dependency, new UTF8Encoding(false));
                var props = XDocument.Load(Path.Combine(RepositoryRoot, "obj", "BuildTools", "BuildTools.proj.nuget.g.props"));
                string package = props.Descendants().Single(element => element.Name.LocalName == "PkgMicrosoft_Windows_SDK_CPP").Value;
                string compilerDirectory = Directory.GetDirectories(Path.Combine(package, "c", "bin")).Select(directory => Path.Combine(directory, "x64")).Single(directory => File.Exists(Path.Combine(directory, "midl.exe")));
                foreach (string name in new[] { "midl.exe", "midlc.exe" })
                    File.Copy(Path.Combine(compilerDirectory, name), Path.Combine(Path.GetDirectoryName(MidlCompiler), name), overwrite: true);
                const string beforeHeader = "/* File created by MIDL compiler */\r\n";
                foreach (string name in new[] { "generated", "dependency" })
                    File.WriteAllText(Path.Combine(this.source, "um", name + ".h"), beforeHeader);
                string patchFile = Path.Combine(this.root, IdlPatchPath);
                Directory.CreateDirectory(Path.GetDirectoryName(patchFile));
                File.WriteAllText(patchFile, "diff --git a/um/generated.idl b/um/generated.idl\n" + "--- a/um/generated.idl\n+++ b/um/generated.idl\n" + "@@ -1,3 +1,3 @@\n-cpp_quote(\"#define IDL_VALUE 1\")\r\n+cpp_quote(\"#define IDL_VALUE 2\")\r\n" + " import \"dependency.idl\";\r\n [uuid(7a22f761-442c-4260-9d80-4c937dce56b6), version(1.0), pointer_default(unique)]\r\n", new UTF8Encoding(false));
                MutateRecipe(recipe =>
                {
                    foreach (string name in new[] { "generated", "dependency" })
                        recipe["headers"].AsArray().Add(JsonSerializer.SerializeToNode(new
                        {
                            path = @"um\" + name + ".h",
                            sourceSha256 = Hash(Encoding.UTF8.GetBytes(beforeHeader)),
                            sdkPath = @"c\include\um\" + name + ".idl",
                            sdkSha256 = Hash(File.ReadAllBytes(Path.Combine(this.sdk, "c", "include", "um", name + ".idl"))),
                        }

                        ));
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
                    }

                    );
                    recipe["patches"] = JsonSerializer.SerializeToNode(new[] { IdlPatchPath, PatchPath });
                });
            }

            internal void EnableMidlSharedHeader()
            {
                EnableMidl();
                File.AppendAllText(MidlInput, "\r\n#include \"sample.h\"\r\n#if VALUE != 2\r\n" + "#error The shared SDK header patch did not reach MIDL preprocessing.\r\n#endif\r\n");
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
                    }

                    ));
                });
            }

            internal void EnableMidl2337(int count)
            {
                EnableMidl();
                for (int i = 0; i < count; i++)
                {
                    File.AppendAllText(MidlInput, $"\r\ntypedef struct OPAQUE_{i}_ OPAQUE_{i};\r\n" + $"typedef struct USE_{i}_ {{ [unique] OPAQUE_{i}* value; }} USE_{i};\r\n");
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
                File.Copy(Path.Combine(RepositoryRoot, "generation", "WinSDK", "RecompiledIdlHeaders", "shared", "win32metadata_annotations.h"), AnnotationHeader);
                File.AppendAllText(MidlInput, "\r\n#if !defined(MIDL_PASS) || MIDL_PASS != 1 || WINVER != 0x0A00 || !defined(UNICODE)\r\n" + "#error The pinned MIDL preprocessor definitions were not forwarded.\r\n#endif\r\n" + "#include <win32metadata_annotations.h>\r\n");
                MutateRecipe(recipe =>
                {
                    string hash = Hash(File.ReadAllBytes(MidlInput));
                    recipe["midl"]["inputs"][0]["sdkSha256"] = hash;
                    recipe["headers"][1]["sdkSha256"] = hash;
                    recipe["midl"]["inputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"shared\win32metadata_annotations.h",
                        sourceSha256 = Hash(File.ReadAllBytes(AnnotationHeader)),
                    }

                    ));
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
                    }

                    ));
                    recipe["midl"]["inputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        path = @"um\including.idl",
                        sdkPath = @"c\include\um\including.idl",
                        sdkSha256 = Hash(File.ReadAllBytes(path)),
                    }

                    ));
                    recipe["midl"]["outputs"].AsArray().Add(JsonSerializer.SerializeToNode(new
                    {
                        source = @"um\including.idl",
                        path = @"um\including.h",
                    }

                    ));
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
                }

                )));
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
                File.WriteAllText(Path.Combine(this.root, relative), "diff --git a/um/generated.h b/um/generated.h\n" + "--- a/um/generated.h\n+++ b/um/generated.h\n" + "@@ -1 +1,2 @@\n /* File created by MIDL compiler */\r\n+// annotation\r\n");
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
                var start = new ProcessStartInfo("pwsh")
                { UseShellExecute = false, RedirectStandardError = true, RedirectStandardOutput = true };
                foreach (string argument in new[] { "-NoProfile", "-NonInteractive", "-File", Path.Combine(RepositoryRoot, "scripts", "ConvertMidlAttributesToSalAnnotations.ps1"), source, target })
                    start.ArgumentList.Add(argument);
                var result = Execute(start);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return File.ReadAllText(target);
            }

            internal void AssertPublishedProvenance(string includeRoot, bool hasMidl = false, string architecture = "crossarch")
            {
                string cache = Path.GetDirectoryName(includeRoot);
                string published = Path.Combine(this.root, "obj", "prepared-sdk-provenance", architecture, Path.GetFileName(cache));
                Assert.Equal(File.ReadAllBytes(Path.Combine(cache, "manifest.json")), File.ReadAllBytes(Path.Combine(published, "manifest.json")));
                string source = Path.Combine(cache, "midl");
                string target = Path.Combine(published, "midl");
                Assert.Equal(hasMidl, Directory.Exists(target));
                if (!hasMidl)
                    return;
                string[] files = Directory.GetFiles(source, "*", SearchOption.AllDirectories).Select(path => Path.GetRelativePath(source, path)).OrderBy(path => path, StringComparer.Ordinal).ToArray();
                Assert.Contains(Path.Combine("sal", "um", "generated.idl"), files);
                Assert.Contains("commands.json", files);
                Assert.Equal(files, Directory.GetFiles(target, "*", SearchOption.AllDirectories).Select(path => Path.GetRelativePath(target, path)).OrderBy(path => path, StringComparer.Ordinal));
                foreach (string path in files)
                    Assert.Equal(File.ReadAllBytes(Path.Combine(source, path)), File.ReadAllBytes(Path.Combine(target, path)));
            }

            internal PreparationResult Prepare(string workingDirectory = null, string outputRoot = null, bool captureMidlWarnings = false)
            {
                var result = Run(workingDirectory, outputRoot: outputRoot, captureMidlWarnings: captureMidlWarnings);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return JsonSerializer.Deserialize<PreparationResult>(result.Output);
            }

            internal ProcessResult Run(string workingDirectory = null, string ambientInclude = null, string outputRoot = null, bool captureMidlWarnings = false)
            {
                return RunPowerShell("$ErrorActionPreference = 'Stop'; & " + Quote(PreparationScript("Prepare-SdkHeaders.ps1")) + " -Recipe " + Quote(this.recipe) + " -SourceRoot " + Quote(this.source) + " -SdkPackageRoot " + Quote(this.sdk) + " -OutputRoot " + Quote(outputRoot ?? Output) + (captureMidlWarnings ? " 3> " + Quote(MidlWarnings) : "") + " | ConvertTo-Json -Compress", workingDirectory, ambientInclude);
            }

            internal static void WriteGeneratedFile(string root, string relative, byte[] bytes)
            {
                string path = Path.Combine(root, relative);
                Directory.CreateDirectory(Path.GetDirectoryName(path));
                File.WriteAllBytes(path, bytes);
            }

            internal ProcessResult ReplaceSelectedHeaders(string[] partitions, string[] overlays, string selected = null, string assembled = null)
            {
                string inputs = Path.Combine(this.root, "source-replacement.json");
                File.WriteAllText(inputs, JsonSerializer.Serialize(new
                {
                    Selected = selected ?? SelectedSources,
                    Assembled = assembled ?? AssembledSources,
                    Partitions = partitions,
                    Overlays = overlays,
                }

                ));
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
                { WorkingDirectory = workingDirectory ?? RepositoryRoot, UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true, RedirectStandardError = true, };
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
                new XDocument(new XElement("Project", new XElement("PropertyGroup", new XElement("RepoRootPath", RepositoryRoot + Path.DirectorySeparatorChar), new XElement("ObjDir", Path.Combine(this.root, "obj"))), new XElement("Import", new XAttribute("Project", Path.Combine(RepositoryRoot, "generation", "WinSDK", "Windows.Win32.proj"))), new XElement("PropertyGroup", new XElement("SdkHeaderRecipe", this.recipe), new XElement("SdkHeaderSourceRoot", this.source), new XElement("SdkHeaderOutputRoot", Output), new XElement("SdkHeaderSdkPackageRoot", this.sdk)), Consumer("CompileIdls", "idl"), Consumer("ScrapeHeaders", "headers", "CompileIdls"), Consumer("ScrapeConstants", "constants", "ScrapeHeaders"), new XElement("Target", new XAttribute("Name", "RecordPreparation"), new XAttribute("AfterTargets", "PrepareSdkHeaders"), Record("prepare")))).Save(project);
                var start = new ProcessStartInfo("dotnet")
                { WorkingDirectory = RepositoryRoot, UseShellExecute = false, CreateNoWindow = true, RedirectStandardOutput = true, RedirectStandardError = true, };
                foreach (string argument in new[] { "msbuild", project, "-nologo", "-v:minimal", "-t:" + target, "-p:PartitionFilter=" + filter, "-p:ScanArch=" + architecture })
                    start.ArgumentList.Add(argument);
                if (this.scripts != Path.Combine(RepositoryRoot, "scripts"))
                    start.ArgumentList.Add("-p:RepoRootPath=" + Path.GetDirectoryName(this.scripts) + Path.DirectorySeparatorChar);
                return Execute(start);
                XElement Record(string name) => new XElement("WriteLinesToFile", new XAttribute("File", BuildEvents), new XAttribute("Lines", name + "|$(SdkIncRoot)"));
                XElement Consumer(string name, string label, string dependencies = "") => new XElement("Target", new XAttribute("Name", name), new XAttribute("DependsOnTargets", dependencies), Record(label));
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
}
