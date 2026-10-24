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

        [BulkNativeTheory]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void NonfloorOriginalIdlsPreserveNativeAbiWithExactSalChanges(
            string architecture, string target, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("SDK_BULK_HEADER_BASELINE");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] owners = Environment.GetEnvironmentVariable("SDK_BULK_HEADER_OWNERS")
                .Split(';', StringSplitOptions.RemoveEmptyEntries);
            Assert.False(string.IsNullOrEmpty(original));
            var expectedBefore = new List<string>();
            var expectedAfter = new List<string>();
            WinHttpNativeControlTests.Surface(root, original, "MenuRc", architecture, target, new[] { "main.cpp" }, "",
                sourceText: SalContract(false), salAnnotations: expectedBefore, language: language);
            WinHttpNativeControlTests.Surface(root, original, "MenuRc", architecture, target, new[] { "main.cpp" }, "",
                sourceText: SalContract(true), salAnnotations: expectedAfter, language: language);
            if (language == "c")
            {
                // MIDL carries each C-vtable parameter's SAL on both its native cursor occurrences.
                expectedBefore.AddRange(expectedBefore.Where(value => value.Split('|')[0].Contains("Vtbl::", StringComparison.Ordinal)).ToArray());
                expectedAfter.AddRange(expectedAfter.Where(value => value.Split('|')[0].Contains("Vtbl::", StringComparison.Ordinal)).ToArray());
            }
            var observations = new List<object>();
            foreach (string owner in owners)
            {
                string header = Path.GetFileName(owner);
                Assert.True(File.Exists(Path.Combine(original, owner)), owner);
                Assert.True(File.Exists(Path.Combine(prepared, owner)), owner);
                string source = "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <" + header + ">\n";
                var beforeSal = new List<string>();
                var afterSal = new List<string>();
                var beforeDiagnostics = new List<string>();
                var afterDiagnostics = new List<string>();
                var annotations = new List<string>();
                string[] before = WinHttpNativeControlTests.Surface(root, original, "MenuRc", architecture, target,
                    new[] { header }, "", sourceText: source, salAnnotations: beforeSal,
                    diagnostics: beforeDiagnostics, language: language);
                string[] after = WinHttpNativeControlTests.Surface(root, prepared, "MenuRc", architecture, target,
                    new[] { header }, "", sourceText: source, salAnnotations: afterSal,
                    diagnostics: afterDiagnostics, annotations: annotations, language: language);
                Assert.NotEmpty(before);
                Assert.Equal(before, after);
                Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                    afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
                Assert.Empty(annotations);
                string[] removed = Difference(beforeSal, afterSal);
                string[] added = Difference(afterSal, beforeSal);
                string[] targets = header.ToLowerInvariant() switch
                {
                    "hlink.h" => new[] { "ppvObj" },
                    "mshtmhst.h" => new[] { Interface("IClassFactoryEx") + "::ppv" },
                    "audioenginebaseapo.h" => new[]
                    {
                        Interface("IAudioProcessingObjectConfiguration") + "::ppInputConnections",
                        Interface("IAudioProcessingObjectConfiguration") + "::ppOutputConnections",
                    },
                    "dbgprop.h" => new[] { Interface("IEnumDebugPropertyInfo") + "::pi", "pi" },
                    "presentation.h" => new[] { Interface("IPresentationManager") + "::fence", "presentationFactory" },
                    "netcfgn.h" => new[] { Interface("INetCfgComponentUpperEdge") + "::pAdapter" },
                    "oledb.h" => new[] { Interface("IScopedOperations") + "::pAuthenticate", "pAuthenticate" },
                    "fwptypes.h" or "wtypes.h" or "xmllite.h" or "activprof.h" or "dispex.h" => Array.Empty<string>(),
                    _ => throw new ArgumentException("Unqualified nonfloor native-control header: " + header),
                };
                var beforeContract = expectedBefore.Where(value => targets.Contains(value.Split('|')[0], StringComparer.Ordinal)).ToList();
                var afterContract = expectedAfter.Where(value => targets.Contains(value.Split('|')[0], StringComparer.Ordinal)).ToList();
                Assert.Equal(Difference(beforeContract, afterContract), removed);
                Assert.Equal(Difference(afterContract, beforeContract), added);
                this.output.WriteLine(header + " removed SAL: " + JsonSerializer.Serialize(removed));
                this.output.WriteLine(header + " added SAL: " + JsonSerializer.Serialize(added));
                observations.Add(new { owner, nativeFacts = before.Length, beforeSal = beforeSal.Count,
                    afterSal = afterSal.Count, removed, added });
            }
            string outputDirectory = Environment.GetEnvironmentVariable("SDK_BULK_NATIVE_OBSERVATIONS");
            Assert.False(string.IsNullOrEmpty(outputDirectory));
            Directory.CreateDirectory(outputDirectory);
            File.WriteAllText(Path.Combine(outputDirectory, architecture + "-" + language.Replace("+", "p") + ".json"),
                JsonSerializer.Serialize(observations, new JsonSerializerOptions { WriteIndented = true }));

            string Interface(string name) => language == "c" ? name + "Vtbl" : name;

            string SalContract(bool authored)
            {
                string com = authored ? "_COM_Outptr_" : "";
                string countedInput = authored ? "_In_reads_(u32NumInputConnections)" : "_In_";
                string countedOutput = authored ? "_In_reads_(u32NumOutputConnections)" : "_In_";
                string debug = authored ? "_Out_writes_to_(celt, *pcEltsfetched)" : "_Out_";
                string fence = authored ? "_COM_Outptr_retval_" : "_Out_retval_";
                string factory = authored ? "_COM_Outptr_" : "_Outptr_";
                string adapter = authored ? "_In_" : "_In_reads_(dwNumInterfaces)";
                string authenticate = authored ? "_In_opt_" : "_In_";
                string Member(string owner, string parameters) => language == "c"
                    ? "struct " + Interface(owner) + " { void (__stdcall *Probe)(" + parameters + "); };\n"
                    : "struct " + owner + " { void Probe(" + parameters + "); };\n";
                return "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n" +
                    string.Join("\n", Enumerable.Range(0, 6).Select(index => "void Hlink" + index + "(" + com + " void** ppvObj);")) +
                    Member("IClassFactoryEx", (authored ? "_COM_Outptr_" : "_Out_") + " void** ppv") +
                    Member("IAudioProcessingObjectConfiguration", "unsigned u32NumInputConnections, " +
                        countedInput + " void** ppInputConnections, unsigned u32NumOutputConnections, " +
                        countedOutput + " void** ppOutputConnections") +
                    Member("IEnumDebugPropertyInfo", "unsigned celt, " + debug + " void* pi, unsigned* pcEltsfetched") +
                    "void NextProxy(unsigned celt, " + debug + " void* pi, unsigned* pcEltsfetched);\n" +
                    Member("IPresentationManager", fence + " void** fence") +
                    "void Factory(" + factory + " void** presentationFactory);\n" +
                    Member("INetCfgComponentUpperEdge", "unsigned dwNumInterfaces, " + adapter + " void* pAdapter") +
                    (language == "c"
                        ? "struct IScopedOperationsVtbl { void (__stdcall *Copy)(" + authenticate + " void* pAuthenticate); " +
                            "void (__stdcall *Move)(" + authenticate + " void* pAuthenticate); };\n"
                        : "struct IScopedOperations { void Copy(" + authenticate + " void* pAuthenticate); " +
                            "void Move(" + authenticate + " void* pAuthenticate); };\n") +
                    "void CopyProxy(" + authenticate + " void* pAuthenticate);\n" +
                    "void MoveProxy(" + authenticate + " void* pAuthenticate);\n";
            }

            static string[] Difference(List<string> left, List<string> right)
            {
                var remaining = new List<string>(right);
                var difference = new List<string>();
                foreach (string value in left)
                {
                    int index = remaining.IndexOf(value);
                    if (index < 0)
                        difference.Add(value);
                    else
                        remaining.RemoveAt(index);
                }
                return difference.OrderBy(value => value, StringComparer.Ordinal).ToArray();
            }
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
