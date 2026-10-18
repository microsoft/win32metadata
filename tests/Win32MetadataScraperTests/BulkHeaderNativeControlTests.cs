using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Text.RegularExpressions;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class BulkHeaderNativeControlTests
    {
        private readonly ITestOutputHelper output;

        public BulkHeaderNativeControlTests(ITestOutputHelper output) => this.output = output;

        [BulkNativeTheory]
        [InlineData(false)]
        [InlineData(true)]
        public void HeaderLocalAnnotationsBootstrapInFreshMidlImportPreprocessing(bool metadataEnabled)
        {
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string include = Environment.GetEnvironmentVariable("WINHTTP_NATIVE_TOOLSET_INCLUDE");
            Assert.False(string.IsNullOrEmpty(include));
            string compiler = Path.GetFullPath(Path.Combine(include, "..", "bin", "Hostx64", "x64", "cl.exe"));
            Assert.True(File.Exists(compiler), compiler);
            string directory = Path.Combine(Path.GetTempPath(), "native-header-midl-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                foreach (string owner in Environment.GetEnvironmentVariable("SDK_BULK_HEADER_OWNERS")
                    .Split(';', StringSplitOptions.RemoveEmptyEntries))
                {
                    string header = Path.Combine(prepared, owner);
                    Assert.Contains("#include <sal.h>", File.ReadAllText(header));
                    string source = Path.Combine(directory, Path.GetFileName(owner) + ".c");
                    File.WriteAllText(source, "#include <sdkddkver.h>\n#include <" + Path.GetFileName(owner) + ">\n");
                    var start = new ProcessStartInfo(compiler)
                    {
                        WorkingDirectory = directory,
                        RedirectStandardOutput = true,
                        RedirectStandardError = true,
                        UseShellExecute = false,
                    };
                    foreach (string ambient in new[] { "INCLUDE", "CL", "_CL_" })
                        start.Environment.Remove(ambient);
                    foreach (string argument in new[]
                    {
                        "/nologo", "/EP", "/TC", "/DMIDL_PASS=1", "/D__midl=801",
                        "/D_AMD64_=1", "/DWINVER=0x0A00", "/D_WIN32_WINNT=0x0A00",
                    })
                        start.ArgumentList.Add(argument);
                    if (metadataEnabled)
                        start.ArgumentList.Add("/DWIN32METADATA=1");
                    foreach (string name in new[] { "shared", "um", "ucrt", "winrt" })
                        start.ArgumentList.Add("/I" + Path.Combine(prepared, name));
                    start.ArgumentList.Add("/I" + include);
                    start.ArgumentList.Add(source);
                    using var process = Process.Start(start);
                    var stdout = process.StandardOutput.ReadToEndAsync();
                    var stderr = process.StandardError.ReadToEndAsync();
                    process.WaitForExit();
                    string text = stdout.GetAwaiter().GetResult();
                    string errors = stderr.GetAwaiter().GetResult();
                    Assert.True(process.ExitCode == 0, owner + Environment.NewLine + errors);
                    var unexpanded = Regex.Match(text, @"\b(?:_Win32_|_WIN32META_)\w+");
                    Assert.False(unexpanded.Success, owner + ": unexpanded annotation " + unexpanded.Value);
                    this.output.WriteLine(owner + ": fresh MIDL-import preprocessor context; header-local sal.h; metadata=" + metadataEnabled);
                }
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        [BulkNativeTheory]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void SelectedOriginalHeadersPreserveNativeAbiAndSal(string architecture, string target, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] owners = Environment.GetEnvironmentVariable("SDK_BULK_HEADER_OWNERS")
                .Split(';', StringSplitOptions.RemoveEmptyEntries);
            Assert.NotEmpty(owners);
            foreach (string owner in owners)
            {
                Assert.False(Path.IsPathRooted(owner));
                Assert.DoesNotContain("..", owner.Split(Path.DirectorySeparatorChar));
                Assert.True(File.Exists(Path.Combine(original, owner)), owner);
                Assert.True(File.Exists(Path.Combine(prepared, owner)), owner);
            }
            string[] headers = owners.Select(Path.GetFileName).ToArray();
            string source = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n" +
                (headers.Contains("mscat.h", StringComparer.OrdinalIgnoreCase) ? "#include <wincrypt.h>\n" : "") +
                string.Join("\n", headers.Select(header => "#include <" + header + ">"));
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            var before = WinHttpNativeControlTests.Surface(root, original, "MenuRc", architecture, target,
                headers, "", sourceText: source, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = WinHttpNativeControlTests.Surface(root, prepared, "MenuRc", architecture, target,
                headers, "", sourceText: source, salAnnotations: afterSal, diagnostics: afterDiagnostics, language: language,
                annotations: annotations);
            Assert.NotEmpty(before);
            Assert.Contains(before, value => value.StartsWith("function ", StringComparison.Ordinal));
            Assert.Equal(before, after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Empty(annotations);
            this.output.WriteLine($"{owners.Length} original headers/{architecture}/{language}: " +
                $"{before.Length} identical native facts, {beforeSal.Count} identical SAL attributes; no metadata leakage.");
        }
    }

    public sealed class BulkNativeTheoryAttribute : TheoryAttribute
    {
        public BulkNativeTheoryAttribute()
        {
            if (Environment.GetEnvironmentVariable("SDK_BULK_HEADER_OWNERS") == null ||
                Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS") == null)
                Skip = "Set SDK_BULK_HEADER_OWNERS and WINHTTP_PREPARED_HEADERS to the selected original-source batch.";
        }
    }
}
