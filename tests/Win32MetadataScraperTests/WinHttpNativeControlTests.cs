using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using ClangSharp.Interop;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class WinHttpNativeControlTests
    {
        private readonly ITestOutputHelper output;

        public WinHttpNativeControlTests(ITestOutputHelper output) => this.output = output;

        [NativeMigrationTheory]
        [InlineData("WinHttp", "x86", "i686-pc-windows-msvc")]
        [InlineData("WinHttp", "x64", "x86_64-pc-windows-msvc")]
        [InlineData("WinHttp", "arm64", "aarch64-pc-windows-msvc")]
        [InlineData("HttpServer", "x86", "i686-pc-windows-msvc")]
        [InlineData("HttpServer", "x64", "x86_64-pc-windows-msvc")]
        [InlineData("HttpServer", "arm64", "aarch64-pc-windows-msvc")]
        public unsafe void MetadataDisabledHeadersCompileWithIdenticalNativeAbi(string partition, string architecture, string target)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] headers = partition == "WinHttp" ? new[] { "winhttp.h", "httprequest.h" } : new[] { "winhttp.h", "httprequest.h", "http.h" };
            // Reusing group names rejects metadata-only types or symbols leaking into ordinary headers.
            const string checks = @"
static_assert(INTERNET_SCHEME_HTTP == 1);
static_assert(INTERNET_SCHEME_HTTPS == 2);
static_assert(INTERNET_SCHEME_FTP == 3);
static_assert(INTERNET_SCHEME_SOCKS == 4);
using WINHTTP_OPEN_REQUEST_FLAGS = void;
using WIN_HTTP_CREATE_URL_FLAGS = void;
using WINHTTP_ACCESS_TYPE = void;
using WINHTTP_CREDS_AUTHSCHEME = void;
using WINHTTP_INTERNET_SCHEME = void;
";
            var originalDiagnostics = new List<string>();
            var preparedDiagnostics = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, checks, diagnostics: originalDiagnostics);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks, diagnostics: preparedDiagnostics);
            Assert.Equal(originalDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                preparedDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(61, before.Count(value => value.StartsWith("function WinHttp", StringComparison.Ordinal)));
            Assert.True(before.Count(value => value.StartsWith("field ", StringComparison.Ordinal)) > 50);
            Assert.Contains(before, value => value.StartsWith("typedef LPWINHTTP_STATUS_CALLBACK ", StringComparison.Ordinal));
            Assert.Equal(before, after);
            Assert.Equal(partition == "WinHttp" ? 969 : 3669, before.Length);
            string hash = Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join("\n", before))));
            string expectedHash = (partition, architecture) switch
            {
                ("WinHttp", "x86") => "2EBA4C00D2659F0483069DEDD1E6713E667DAD712033EBACC10A8B439D0CAE70",
                ("WinHttp", _) => "65657F305A625A871548097056B261FA9C0CF614BD2F239CB5F1AA45F65F8999",
                ("HttpServer", "x86") => "ED7B558D353ABE4804EA02499E0215E6F14E2505A7D9327B981C978F60444FFA",
                ("HttpServer", _) => "00AB5370D2F85FCE39CF33FB98168A7E6861B5DE57A9E8EF08EFB76CB3411CB0",
                _ => throw new ArgumentException("Unknown native control partition.", nameof(partition)),
            };
            Assert.Equal(expectedHash, hash);
            this.output.WriteLine($"{partition}/{architecture}: {before.Length} native facts; OLD=NEW SHA256 " +
                hash);
        }

        [NativeMigrationTheory]
        [MemberData(nameof(AdditionalPartitions))]
        public void AdditionalPreparedPartitionsKeepOrdinaryNativeAbi(string partition, string architecture, string target)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "SdkHeaders.json")));
            var patched = recipe.RootElement.GetProperty("headers").EnumerateArray()
                .Select(value => Path.GetFileName(value.GetProperty("path").GetString()));
            var headers = File.ReadLines(Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "settings.rsp"))
                .Where(line => line.StartsWith("<IncludeRoot>/", StringComparison.Ordinal))
                .Select(line => Path.GetFileName(line.Replace('/', '\\'))).Concat(patched).Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            Assert.NotEmpty(headers);
            string checks = partition switch
            {
                "ApplicationVerifier" => @"
static_assert(AVRF_ENUM_RESOURCES_FLAGS_DONT_RESOLVE_TRACES == 2);
static_assert(AVRF_ENUM_RESOURCES_FLAGS_SUSPEND == 1);
using VERIFIER_ENUM_RESOURCE_FLAGS = void;
",
                "MagApi" => @"
static_assert(MW_FILTERMODE_EXCLUDE == 0);
static_assert(MW_FILTERMODE_INCLUDE == 1);
using MW_FILTERMODE = void;
",
                "PsApi1" or "PsApi2" => @"
static_assert(LIST_MODULES_ALL == 3);
static_assert(LIST_MODULES_DEFAULT == 0);
static_assert(LIST_MODULES_32BIT == 1);
static_assert(LIST_MODULES_64BIT == 2);
using ENUM_PROCESS_MODULES_EX_FLAGS = void;
",
                "ToolHelp" => @"
static_assert(TH32CS_INHERIT == 0x80000000u);
static_assert(TH32CS_SNAPALL == 15);
static_assert(TH32CS_SNAPHEAPLIST == 1);
static_assert(TH32CS_SNAPMODULE == 8);
static_assert(TH32CS_SNAPMODULE32 == 16);
static_assert(TH32CS_SNAPPROCESS == 2);
static_assert(TH32CS_SNAPTHREAD == 4);
static_assert(LF32_FIXED == 1);
static_assert(LF32_FREE == 2);
static_assert(LF32_MOVEABLE == 4);
using CREATE_TOOLHELP_SNAPSHOT_FLAGS = void;
using HEAPENTRY32_FLAGS = void;
",
                "Wsl" => @"
static_assert(WSL_DISTRIBUTION_FLAGS_NONE == 0);
static_assert(WSL_DISTRIBUTION_FLAGS_ENABLE_INTEROP == 1);
static_assert(WSL_DISTRIBUTION_FLAGS_APPEND_NT_PATH == 2);
static_assert(WSL_DISTRIBUTION_FLAGS_ENABLE_DRIVE_MOUNTING == 4);
",
                "Xinput" => @"
#ifdef XINPUT_FLAG_ALL
#error Metadata-only XINPUT_FLAG_ALL must not become a native macro
#endif
static_assert(VK_PAD_A == 22528);
static_assert(VK_PAD_B == 22529);
static_assert(VK_PAD_X == 22530);
static_assert(VK_PAD_Y == 22531);
static_assert(VK_PAD_RSHOULDER == 22532);
static_assert(VK_PAD_LSHOULDER == 22533);
static_assert(VK_PAD_LTRIGGER == 22534);
static_assert(VK_PAD_RTRIGGER == 22535);
static_assert(VK_PAD_DPAD_UP == 22544);
static_assert(VK_PAD_DPAD_DOWN == 22545);
static_assert(VK_PAD_DPAD_LEFT == 22546);
static_assert(VK_PAD_DPAD_RIGHT == 22547);
static_assert(VK_PAD_START == 22548);
static_assert(VK_PAD_BACK == 22549);
static_assert(VK_PAD_LTHUMB_PRESS == 22550);
static_assert(VK_PAD_RTHUMB_PRESS == 22551);
static_assert(VK_PAD_LTHUMB_UP == 22560);
static_assert(VK_PAD_LTHUMB_DOWN == 22561);
static_assert(VK_PAD_LTHUMB_RIGHT == 22562);
static_assert(VK_PAD_LTHUMB_LEFT == 22563);
static_assert(VK_PAD_LTHUMB_UPLEFT == 22564);
static_assert(VK_PAD_LTHUMB_UPRIGHT == 22565);
static_assert(VK_PAD_LTHUMB_DOWNRIGHT == 22566);
static_assert(VK_PAD_LTHUMB_DOWNLEFT == 22567);
static_assert(VK_PAD_RTHUMB_UP == 22576);
static_assert(VK_PAD_RTHUMB_DOWN == 22577);
static_assert(VK_PAD_RTHUMB_RIGHT == 22578);
static_assert(VK_PAD_RTHUMB_LEFT == 22579);
static_assert(VK_PAD_RTHUMB_UPLEFT == 22580);
static_assert(VK_PAD_RTHUMB_UPRIGHT == 22581);
static_assert(VK_PAD_RTHUMB_DOWNRIGHT == 22582);
static_assert(VK_PAD_RTHUMB_DOWNLEFT == 22583);
static_assert(BATTERY_TYPE_DISCONNECTED == 0);
static_assert(BATTERY_TYPE_WIRED == 1);
static_assert(BATTERY_TYPE_ALKALINE == 2);
static_assert(BATTERY_TYPE_NIMH == 3);
static_assert(BATTERY_TYPE_UNKNOWN == 255);
static_assert(BATTERY_LEVEL_EMPTY == 0);
static_assert(BATTERY_LEVEL_LOW == 1);
static_assert(BATTERY_LEVEL_MEDIUM == 2);
static_assert(BATTERY_LEVEL_FULL == 3);
static_assert(BATTERY_DEVTYPE_GAMEPAD == 0);
static_assert(BATTERY_DEVTYPE_HEADSET == 1);
static_assert(XINPUT_DEVTYPE_GAMEPAD == 1);
static_assert(XINPUT_DEVSUBTYPE_GAMEPAD == 1);
static_assert(XINPUT_DEVSUBTYPE_UNKNOWN == 0);
static_assert(XINPUT_DEVSUBTYPE_WHEEL == 2);
static_assert(XINPUT_DEVSUBTYPE_ARCADE_STICK == 3);
static_assert(XINPUT_DEVSUBTYPE_FLIGHT_STICK == 4);
static_assert(XINPUT_DEVSUBTYPE_DANCE_PAD == 5);
static_assert(XINPUT_DEVSUBTYPE_GUITAR == 6);
static_assert(XINPUT_DEVSUBTYPE_GUITAR_ALTERNATE == 7);
static_assert(XINPUT_DEVSUBTYPE_DRUM_KIT == 8);
static_assert(XINPUT_DEVSUBTYPE_GUITAR_BASS == 11);
static_assert(XINPUT_DEVSUBTYPE_ARCADE_PAD == 19);
static_assert(XINPUT_CAPS_VOICE_SUPPORTED == 4);
static_assert(XINPUT_CAPS_FFB_SUPPORTED == 1);
static_assert(XINPUT_CAPS_WIRELESS == 2);
static_assert(XINPUT_CAPS_PMD_SUPPORTED == 8);
static_assert(XINPUT_CAPS_NO_NAVIGATION == 16);
static_assert(XINPUT_GAMEPAD_DPAD_UP == 1);
static_assert(XINPUT_GAMEPAD_DPAD_DOWN == 2);
static_assert(XINPUT_GAMEPAD_DPAD_LEFT == 4);
static_assert(XINPUT_GAMEPAD_DPAD_RIGHT == 8);
static_assert(XINPUT_GAMEPAD_START == 16);
static_assert(XINPUT_GAMEPAD_BACK == 32);
static_assert(XINPUT_GAMEPAD_LEFT_THUMB == 64);
static_assert(XINPUT_GAMEPAD_RIGHT_THUMB == 128);
static_assert(XINPUT_GAMEPAD_LEFT_SHOULDER == 256);
static_assert(XINPUT_GAMEPAD_RIGHT_SHOULDER == 512);
static_assert(XINPUT_GAMEPAD_A == 4096);
static_assert(XINPUT_GAMEPAD_B == 8192);
static_assert(XINPUT_GAMEPAD_X == 16384);
static_assert(XINPUT_GAMEPAD_Y == 32768);
static_assert(XINPUT_GAMEPAD_LEFT_THUMB_DEADZONE == 7849);
static_assert(XINPUT_GAMEPAD_RIGHT_THUMB_DEADZONE == 8689);
static_assert(XINPUT_GAMEPAD_TRIGGER_THRESHOLD == 30);
static_assert(XINPUT_KEYSTROKE_KEYDOWN == 1);
static_assert(XINPUT_KEYSTROKE_KEYUP == 2);
static_assert(XINPUT_KEYSTROKE_REPEAT == 4);
static_assert(XINPUT_FLAG_GAMEPAD == 1);
using XINPUT_VIRTUAL_KEY = void;
using BATTERY_TYPE = void;
using BATTERY_LEVEL = void;
using BATTERY_DEVTYPE = void;
using XINPUT_DEVTYPE = void;
using XINPUT_DEVSUBTYPE = void;
using XINPUT_CAPABILITIES_FLAGS = void;
using XINPUT_GAMEPAD_BUTTON_FLAGS = void;
using XINPUT_KEYSTROKE_FLAGS = void;
using XINPUT_FLAG = void;
",
                _ => "",
            };
            var originalDiagnostics = new List<string>();
            var preparedDiagnostics = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, checks, diagnostics: originalDiagnostics);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks, diagnostics: preparedDiagnostics);
            Assert.Equal(originalDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                preparedDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.NotEmpty(before);
            Assert.Contains(before, value => value.StartsWith("function ", StringComparison.Ordinal) || value.StartsWith("record ", StringComparison.Ordinal));
            Assert.Equal(before, after);
            this.output.WriteLine($"{partition}/{architecture}: {before.Length} native facts; OLD=NEW SHA256 " +
                Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join("\n", before)))));
        }

        public static IEnumerable<object[]> AdditionalPartitions()
        {
            using var recipe = JsonDocument.Parse(File.ReadAllText(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "patches", "SdkHeaders.json")));
            foreach (string partition in recipe.RootElement.GetProperty("partitions").EnumerateArray().Select(value => value.GetString())
                .Where(value => value != "WinHttp" && value != "HttpServer"))
            {
                yield return new object[] { partition, "x86", "i686-pc-windows-msvc" };
                yield return new object[] { partition, "x64", "x86_64-pc-windows-msvc" };
                yield return new object[] { partition, "arm64", "aarch64-pc-windows-msvc" };
            }
        }

        [NativeMigrationTheory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void RegeneratedSdkIdlKeepsNativeAbiAndOnlyTheIntendedAnnotation(string architecture, string target, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string[] headers = { "waasapi.h", "waasapitypes.h" };
            var annotations = new List<string>();
            var originalDiagnostics = new List<string>();
            var preparedDiagnostics = new List<string>();
            var before = Surface(root, original, "UpdateAssessment", architecture, target, headers, "", diagnostics: originalDiagnostics);
            var after = Surface(root, prepared, "UpdateAssessment", architecture, target, headers, "",
                metadataEnabled: enabled, annotations: annotations, diagnostics: preparedDiagnostics);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.Equal(originalDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                preparedDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(enabled ? new[] { "IWaaSAssessor|SupportedOSPlatform(\"windows10.0.15063\")" } :
                Array.Empty<string>(), annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            Assert.Contains("_Out_retval_  OSUpdateAssessment *result", File.ReadAllText(Path.Combine(prepared, "um", "waasapi.h")));
            this.output.WriteLine($"Regenerated waasapi/{architecture}/metadata={enabled}: {after.Length} unchanged native facts; " +
                $"{annotations.Distinct(StringComparer.Ordinal).Count()} exact type-only OS annotation.");
        }

        [NativeMigrationTheory]
        [MemberData(nameof(PropertyStorageIdlControls))]
        public void RegeneratedPropertyStorageIdlKeepsNativeLayoutsSalAndRpc(string header, string architecture,
            string target, bool enabled, string language, bool cInterface)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            // Make either generated artifact the first owner, then include the other guarded declaration copy.
            string otherHeader = header == "PropIdl.h" ? "PropIdlBase.h" : "PropIdl.h";
            string source = "#define WIN32_LEAN_AND_MEAN 1\n#define COM_NO_WINDOWS_H 1\n" +
                "#include <intrinfix.h>\n#include <windows.fixed.h>\n#include <sdkddkver.h>\n" +
                "#include <wtypes.h>\n#include <objidl.h>\n#include <oaidl.h>\n" +
                "#include <" + header + ">\n#include <" + otherHeader + ">\n";
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string checks = $@"
{assertion}(PRSPEC_INVALID == 0xffffffffu, ""PRSPEC_INVALID"");
{assertion}(PRSPEC_LPWSTR == 0, ""PRSPEC_LPWSTR"");
{assertion}(PRSPEC_PROPID == 1, ""PRSPEC_PROPID"");
{assertion}(sizeof(((PROPSPEC*)0)->ulKind) == 4, ""PROPSPEC::ulKind"");
{assertion}(sizeof(((STATPROPSTG*)0)->vt) == 2, ""STATPROPSTG::vt"");
{assertion}(sizeof(((PROPVARIANT*)0)->vt) == 2, ""PROPVARIANT::vt"");
{assertion}(sizeof(enum VARENUM) == 4, ""native enum VARENUM"");
";
            string[] headers = { header, otherHeader };
            var annotations = new List<string>();
            var originalSal = new List<string>();
            var preparedSal = new List<string>();
            var originalDiagnostics = new List<string>();
            var preparedDiagnostics = new List<string>();
            var before = Surface(root, original, "Com.StructuredStorage", architecture, target, headers, checks,
                sourceText: source, salAnnotations: originalSal, diagnostics: originalDiagnostics,
                language: language, cInterface: cInterface);
            var after = Surface(root, prepared, "Com.StructuredStorage", architecture, target, headers,
                checks + (enabled ? "" : language == "c" ? "\ntypedef void PROPSPEC_KIND;\n" : "\nusing PROPSPEC_KIND = void;\n"),
                metadataEnabled: enabled, annotations: annotations, sourceText: source, salAnnotations: preparedSal,
                diagnostics: preparedDiagnostics, language: language, cInterface: cInterface);
            const string group = "typedef PROPSPEC_KIND unsigned long";
            Assert.Equal(enabled ? new[] { group } : Array.Empty<string>(), after.Where(value => value == group));
            Assert.Equal(before, after.Where(value => value != group));
            Assert.Equal(originalSal.OrderBy(value => value, StringComparer.Ordinal),
                preparedSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(originalDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                preparedDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Contains(before, value => value.StartsWith("field ", StringComparison.Ordinal) &&
                value.Contains("::wReserved1 unsigned short ", StringComparison.Ordinal));
            Assert.Contains(before, value => value.StartsWith("field ", StringComparison.Ordinal) &&
                value.Contains("::wReserved3 unsigned short ", StringComparison.Ordinal));
            foreach (string name in new[] { "IEnumSTATPROPSTG", "IEnumSTATPROPSETSTG" })
            {
                string skip = language == "c++" && !cInterface ? "function " + name + "::Skip " :
                    "field " + name + "Vtbl::Skip ";
                Assert.Contains(before, value => value.StartsWith(skip, StringComparison.Ordinal));
                Assert.Contains(before, value => value.StartsWith("function " + name + "_Next_Proxy ", StringComparison.Ordinal));
                Assert.Contains(before, value => value.StartsWith("function " + name + "_Next_Stub ", StringComparison.Ordinal));
            }

            string[] facts = annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            if (!enabled)
                Assert.Empty(facts);
            else
            {
                Assert.Equal(language == "c++" ? new[]
                {
                    "IEnumSTATPROPSETSTG|SupportedOSPlatform(\"windows5.0\")",
                    "IEnumSTATPROPSTG|SupportedOSPlatform(\"windows5.0\")",
                    "IPropertySetStorage|SupportedOSPlatform(\"windows5.0\")",
                    "IPropertyStorage|SupportedOSPlatform(\"windows5.0\")",
                } : Array.Empty<string>(), facts.Where(value => value.Contains("|SupportedOSPlatform(", StringComparison.Ordinal)));
                Assert.Contains("PROPSPEC_KIND|Enum(PRSPEC_LPWSTR, PRSPEC_PROPID)", facts);
                string[] associations = facts.Where(value => value.EndsWith("|AssociatedEnum", StringComparison.Ordinal)).ToArray();
                Assert.Equal(3, associations.Length);
                Assert.Contains("tagPROPSPEC::ulKind|AssociatedEnum", associations);
                Assert.Contains("tagSTATPROPSTG::vt|AssociatedEnum", associations);
                Assert.Single(associations.Where(value => value.Contains("PROPVARIANT::", StringComparison.Ordinal) &&
                    value.EndsWith("::vt|AssociatedEnum", StringComparison.Ordinal)));
                Assert.Equal(language == "c++" ? 8 : 4, facts.Count(value => value.Contains("|SupportedOSPlatform(", StringComparison.Ordinal) ||
                    value.EndsWith("|AssociatedEnum", StringComparison.Ordinal) || value.Contains("|Enum(", StringComparison.Ordinal)));
                foreach (string name in new[] { "IEnumSTATPROPSTG", "IEnumSTATPROPSETSTG" })
                    Assert.DoesNotContain(facts, value => value.StartsWith(name + "_Next_Proxy|", StringComparison.Ordinal));
            }
            this.output.WriteLine($"{header} then {otherHeader}/{architecture}/{language}/CINTERFACE={cInterface}/metadata={enabled}: " +
                $"{before.Length} identical native/layout/RPC facts, {originalSal.Count} unchanged SAL attributes, " +
                $"{facts.Length} native AST metadata facts; method targets are checked in the physical winmd.");
        }

        public static IEnumerable<object[]> PropertyStorageIdlControls()
        {
            foreach (string header in new[] { "PropIdl.h", "PropIdlBase.h" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (bool enabled in new[] { false, true })
                        foreach (var mode in new[] { ("c++", false), ("c++", true), ("c", false) })
                            yield return new object[] { header, architecture.Item1, architecture.Item2, enabled, mode.Item1, mode.Item2 };
        }

        private static unsafe string[] Surface(string root, string includeRoot, string partition, string architecture,
            string target, string[] headers, string checks, bool metadataEnabled = false, List<string> annotations = null,
            string sourceText = null, List<string> salAnnotations = null, List<string> diagnostics = null,
            string language = "c++", bool cInterface = false)
        {
            string source = Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "main.cpp");
            var arguments = new List<string>
                {
                    "--language=" + language, "--std=" + (language == "c" ? "c11" : "c++17"), "--target=" + target,
                    "--include-directory=" + Path.Combine(root, "generation", "WinSDK", "inc"),
                };
            arguments.AddRange(new[] { "shared", "um", "ucrt", "winrt" }
                .Select(directory => "--include-directory=" + Path.Combine(includeRoot, directory)));
            string toolsetInclude = Environment.GetEnvironmentVariable("WINHTTP_NATIVE_TOOLSET_INCLUDE");
            Assert.True(!string.IsNullOrEmpty(toolsetInclude) && Directory.Exists(toolsetInclude),
                "Set WINHTTP_NATIVE_TOOLSET_INCLUDE to the pinned MSVC include directory; ambient INCLUDE is not used.");
            arguments.Add("--include-directory=" + toolsetInclude);
            if (cInterface)
                arguments.Add("-DCINTERFACE=1");
            string settings = Path.Combine(root, "sources", "GeneratorSdk", "tools", "assets", "scraper");
            foreach (string path in new[] { Path.Combine(settings, "baseSettings.rsp"), Path.Combine(settings, "baseSettings." + architecture + ".rsp") })
            {
                bool additional = false;
                foreach (string line in File.ReadLines(path).Select(value => value.Trim()).Where(value => value.Length != 0))
                {
                    if (line.StartsWith("--", StringComparison.Ordinal))
                        additional = line == "--additional";
                    else if (additional)
                        arguments.Add(line);
                }
            }
            Assert.DoesNotContain(arguments, argument => argument.Contains("WIN32METADATA", StringComparison.Ordinal));
            if (metadataEnabled)
                arguments.Add("-DWIN32METADATA=1");
            using var unsaved = CXUnsavedFile.Create(source, (sourceText ?? File.ReadAllText(source)) + checks);
            using var index = CXIndex.Create(false, false);
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, source, arguments.ToArray(),
                new[] { unsaved }, CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
            // Own raw cursors so earlier generator fixtures cannot supply a cached managed AST wrapper.
            using var unit = handle;
            for (uint i = 0; i < handle.NumDiagnostics; i++)
            {
                using var diagnostic = handle.GetDiagnostic(i);
                string text = Text(diagnostic.Format(CXDiagnostic.DefaultDisplayOptions));
                Assert.True(diagnostic.Severity < CXDiagnosticSeverity.CXDiagnostic_Error, text);
                diagnostics?.Add(Regex.Replace(text.Replace(includeRoot, "<headers>", StringComparison.OrdinalIgnoreCase),
                    @":\d+:\d+:", ":<source-location>:"));
            }
            var result = new List<string>();
            // Clang's anonymous names embed paths and line numbers; retain declaration identity without those incidental coordinates.
            var anonymous = new Dictionary<string, string>(StringComparer.Ordinal);
            var ordinals = new Dictionary<string, int>(StringComparer.Ordinal);
            Walk(unit.Cursor, "");
            return result.Select(value => Regex.Replace(value,
                @"\((?:anonymous|unnamed)(?: (?:struct|union|enum))? at (?<location>[^)]+:\d+:\d+)\)",
                match => anonymous[match.Groups["location"].Value.Replace('\\', '/')]))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();

            void Walk(CXCursor cursor, string owner)
            {
                cursor.Location.GetExpansionLocation(out var file, out var line, out var column, out _);
                string header = Path.GetFileName(file.ToString());
                string childOwner = owner;
                var kind = cursor.DeclKind;
                bool record = kind is CX_DeclKind.CX_DeclKind_Record or CX_DeclKind.CX_DeclKind_CXXRecord;
                bool enumeration = kind == CX_DeclKind.CX_DeclKind_Enum;
                string name = Text(cursor.Spelling);
                if (record || enumeration)
                {
                    if (name.Length == 0 || name.StartsWith("(", StringComparison.Ordinal))
                    {
                        ordinals.TryGetValue(header, out int ordinal);
                        ordinals[header] = ordinal + 1;
                        anonymous[file.ToString().Replace('\\', '/') + ":" + line + ":" + column] = header + ":anonymous#" + ordinal;
                    }
                    childOwner = owner + name + "::";
                }
                if (headers.Contains(header, StringComparer.OrdinalIgnoreCase))
                {
                    if (kind is CX_DeclKind.CX_DeclKind_Function or CX_DeclKind.CX_DeclKind_CXXMethod or
                        CX_DeclKind.CX_DeclKind_CXXConstructor or CX_DeclKind.CX_DeclKind_CXXDestructor or
                        CX_DeclKind.CX_DeclKind_CXXConversion or CX_DeclKind.CX_DeclKind_CXXDeductionGuide)
                        result.Add("function " + owner + name + " " + Text(cursor.Type.CanonicalType.Spelling));
                    else if (kind is CX_DeclKind.CX_DeclKind_Field or CX_DeclKind.CX_DeclKind_ObjCAtDefsField)
                        result.Add("field " + owner + name + " " + Text(cursor.Type.CanonicalType.Spelling) + " " + cursor.OffsetOfField);
                    else if (record && cursor.IsCompleteDefinition)
                        result.Add("record " + owner + name + " " + cursor.Type.SizeOf + " " + cursor.Type.AlignOf);
                    else if (kind == CX_DeclKind.CX_DeclKind_Typedef)
                        result.Add("typedef " + owner + name + " " + Text(cursor.TypedefDeclUnderlyingType.CanonicalType.Spelling));
                    else if (enumeration)
                        result.Add("enum " + owner + name + " " + Text(cursor.EnumDecl_IntegerType.Spelling));
                    else if (kind == CX_DeclKind.CX_DeclKind_EnumConstant)
                        result.Add("value " + owner + name + " " + cursor.EnumConstantDeclValue);
                }
                cursor.VisitChildren((child, parent, data) =>
                {
                    if ((annotations != null || salAnnotations != null) && headers.Contains(header, StringComparer.OrdinalIgnoreCase) &&
                        child.Kind == CXCursorKind.CXCursor_AnnotateAttr)
                    {
                        string value = Text(child.Spelling);
                        const string prefix = "Win32Metadata.";
                        if (value.StartsWith(prefix, StringComparison.Ordinal))
                            annotations?.Add(owner + name + "|" + value.Substring(prefix.Length));
                        else
                            salAnnotations?.Add(owner + name + "|" + value);
                    }
                    if (child.IsDeclaration || child.IsTranslationUnit)
                        Walk(child, childOwner);
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
            }
            static string Text(CXString text)
            {
                using (text) return text.ToString();
            }
        }
    }

    // Keep SDK-sized AST ownership separate from the generator fixtures.
    [CollectionDefinition(nameof(WinHttpNativeControlCollection), DisableParallelization = true)]
    public sealed class WinHttpNativeControlCollection
    {
    }

    public sealed class NativeMigrationTheoryAttribute : TheoryAttribute
    {
        public NativeMigrationTheoryAttribute()
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS") == null)
                Skip = "Set WINHTTP_PREPARED_HEADERS to the pinned private prepared-header tree.";
        }
    }
}
