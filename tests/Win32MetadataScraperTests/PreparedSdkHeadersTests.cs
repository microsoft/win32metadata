using System;
using System.Diagnostics;
using System.IO;
using System.Text;
using System.Text.Json;
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

            internal PreparationResult Prepare(string workingDirectory = null)
            {
                var result = Run(workingDirectory);
                Assert.True(result.ExitCode == 0, result.Error + result.Output);
                return JsonSerializer.Deserialize<PreparationResult>(result.Output);
            }

            internal ProcessResult Run(string workingDirectory = null)
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
                foreach (string argument in new[] { "-NoLogo", "-NoProfile", "-NonInteractive", "-Command" })
                {
                    start.ArgumentList.Add(argument);
                }

                start.ArgumentList.Add("$ErrorActionPreference = 'Stop'; & " +
                    Quote(Path.Combine(RepositoryRoot, "scripts", "Prepare-SdkHeaders.ps1")) +
                    " -Recipe " + Quote(this.recipe) + " -SourceRoot " + Quote(this.source) +
                    " -SdkPackageRoot " + Quote(this.sdk) + " -OutputRoot " + Quote(Output) +
                    " | ConvertTo-Json -Compress");
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                if (!process.WaitForExit(30000))
                {
                    process.Kill(entireProcessTree: true);
                    throw new TimeoutException("Header preparation did not terminate.");
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
