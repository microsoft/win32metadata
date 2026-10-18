using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
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
