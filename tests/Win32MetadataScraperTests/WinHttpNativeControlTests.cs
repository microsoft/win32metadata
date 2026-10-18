using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
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

        [NativeMigrationTheory("POWER_RESTART_MIGRATION_ROOT")]
        [MemberData(nameof(PowerRestartModes))]
        public void OriginalPowerAndRestartManagerKeepNativeContracts(
            string partition, string architecture, string target, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] headers = partition == "Power"
                ? new[] { "powrprof.h", "powerbase.h", "powersetting.h" }
                : new[] { "RestartManager.h" };
            var originalSal = new List<string>();
            var disabledSal = new List<string>();
            var enabledSal = new List<string>();
            var annotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, "",
                salAnnotations: originalSal, language: language);
            var disabled = Surface(root, prepared, partition, architecture, target, headers, "",
                salAnnotations: disabledSal, language: language);
            var enabled = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: true, annotations: annotations, salAnnotations: enabledSal, language: language);
            Assert.NotEmpty(before);
            Assert.Equal(before, disabled);
            const string group = "typedef DEVICE_POWER_CAPABILITIES unsigned long";
            if (partition == "Power")
                Assert.Single(enabled.Where(value => value == group));
            else
                Assert.DoesNotContain(group, enabled);
            Assert.Equal(before, enabled.Where(value => value != group));
            Assert.Equal(originalSal, disabledSal);
            Assert.Equal(originalSal, enabledSal);
            Assert.Equal(partition == "Power" ? 81 : 11,
                annotations.Count(value => value.Contains("|SupportedOSPlatform(", StringComparison.Ordinal)));
            Assert.Equal(partition == "Power" ? 16 : 0,
                annotations.Count(value => value.EndsWith("|SetLastError", StringComparison.Ordinal)));
            this.output.WriteLine($"{partition}/{architecture}/{language}: native declarations/layout/SAL unchanged; " +
                "only the compiled-native logical group is metadata-only.");
        }

        public static IEnumerable<object[]> PowerRestartModes()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (string partition in new[] { "Power", "RstMgr" })
                    foreach (string language in new[] { "c", "c++" })
                        yield return new object[] { partition, architecture.Item1, architecture.Item2, language };
        }

        [NativeMigrationTheory("SYSTEM_ENUM_MIGRATION_ROOT")]
        [MemberData(nameof(SystemEnumNativeModes))]
        public void SystemLogicalGroupsKeepNativeValuesTypesAndSurface(
            string original, string partition, string architecture, string target, bool metadataEnabled)
        {
            this.VerifySystemLogicalGroupsNativeSurface(original, partition, architecture, target, metadataEnabled, "c++");
        }

        [NativeMigrationTheory("SYSTEM_ENUM_C_MIGRATION_ROOT")]
        [MemberData(nameof(SystemEnumCNativeModes))]
        public void SystemLogicalGroupsKeepCNativeValuesTypesAndSurface(
            string original, string partition, string architecture, string target, bool metadataEnabled)
        {
            Assert.Equal(Environment.GetEnvironmentVariable("SYSTEM_ENUM_MIGRATION_ROOT"),
                Environment.GetEnvironmentVariable("SYSTEM_ENUM_C_MIGRATION_ROOT"));
            this.VerifySystemLogicalGroupsNativeSurface(original, partition, architecture, target, metadataEnabled, "c");
        }

        private void VerifySystemLogicalGroupsNativeSurface(
            string original, string partition, string architecture, string target, bool metadataEnabled, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                Environment.GetEnvironmentVariable("SYSTEM_ENUM_MIGRATION_ROOT"), "report.json")));
            var owner = report.RootElement.GetProperty("owners").EnumerateArray()
                .Single(value => value.GetProperty("original").GetString() == original);
            var groups = owner.GetProperty("groups").EnumerateArray().ToArray();
            var fieldAssociations = owner.GetProperty("associations").EnumerateArray()
                .Where(value => value.TryGetProperty("kind", out var kind) && kind.GetString() == "field").ToArray();
            string[] headers = { Path.GetFileName(original) };
            var nativeMembers = groups.SelectMany(group => group.GetProperty("Members").EnumerateArray())
                .Concat(owner.TryGetProperty("additionalNativeMembers", out var additionalMembers)
                    ? additionalMembers.EnumerateArray() : Enumerable.Empty<JsonElement>());
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string checks = string.Join("\n", nativeMembers
                .Select(member => assertion + "((unsigned long long)(" +
                    (member.TryGetProperty("NativeExpression", out var expression) ? expression.GetString() : member.GetProperty("Name").GetString()) +
                    ") == " + member.GetProperty("Value").GetRawText() + "ULL, \"native value\");")
                .Concat(fieldAssociations.Select(value => language == "c"
                    ? "_Static_assert(_Generic(((" + value.GetProperty("nativeType").GetString() + "*)0)->" +
                        value.GetProperty("symbol").GetString().Split("::").Last() + ", DWORD: 1, default: 0), \"native DWORD field\");"
                    : "static_assert(__is_same(decltype(((" + value.GetProperty("nativeType").GetString() + "*)nullptr)->" +
                        value.GetProperty("symbol").GetString().Split("::").Last() + "), DWORD));")));
            if (owner.TryGetProperty("nativeChecks", out var nativeChecks))
                checks += "\n" + nativeChecks.GetString();
            string[] carriers = groups.Select(group => "typedef " + group.GetProperty("Group").GetString() + " " +
                (group.GetProperty("Storage").GetString() switch
                {
                    "UInt16" => "unsigned short",
                    "UInt32" => "unsigned long",
                    "Int32" => "int",
                    var storage => throw new InvalidOperationException("Unexpected exact logical-group storage: " + storage),
                })).ToArray();
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var annotations = new List<string>();
            bool compareAnnotations = owner.TryGetProperty("expectedAddedAnnotations", out var expectedAddedAnnotations);
            string sourceText = language == "c"
                ? "#define SECURITY_WIN32\n#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n" +
                    "#include <sdkddkver.h>\n#include <ntsecapi.h>\n#include <sspi.h>\n#include <" +
                    Path.GetFileName(original) + ">\n"
                : null;
            var before = Surface(root, Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS"),
                partition, architecture, target, headers, checks, metadataEnabled: metadataEnabled && compareAnnotations,
                annotations: beforeAnnotations, sourceText: sourceText, salAnnotations: beforeSal,
                diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS"),
                partition, architecture, target, headers, checks, metadataEnabled: metadataEnabled,
                annotations: annotations, sourceText: sourceText, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            int producerCount = owner.TryGetProperty("producers", out var producers) ? producers.GetArrayLength() : 0;
            Assert.True(groups.Length > 0 || fieldAssociations.Length > 0 || producerCount > 0);
            Assert.NotEmpty(checks);
            Assert.Equal(before.Concat(metadataEnabled ? carriers : Array.Empty<string>())
                .OrderBy(value => value, StringComparer.Ordinal), after);
            Assert.Equal(beforeSal, afterSal);
            Assert.Equal(beforeDiagnostics, afterDiagnostics);
            if (compareAnnotations)
                Assert.Equal(beforeAnnotations.Concat(metadataEnabled
                    ? expectedAddedAnnotations.EnumerateArray().Select(value => value.GetString())
                    : Array.Empty<string>()).OrderBy(value => value, StringComparer.Ordinal),
                    annotations.OrderBy(value => value, StringComparer.Ordinal));
            if (owner.TryGetProperty("expectedGroupAnnotations", out var expectedAnnotations))
            {
                var roles = expectedAnnotations.EnumerateArray().ToArray();
                Assert.Equal(groups.Length, roles.Count(value => value.GetProperty("role").GetString() == "local"));
                foreach (var role in roles)
                {
                    string source = role.GetProperty("original").GetString();
                    Assert.Contains(source, report.RootElement.GetProperty("owners").EnumerateArray()
                        .Select(value => value.GetProperty("original").GetString()));
                    Assert.True(role.GetProperty("role").GetString() is "local" or "inherited");
                    Assert.Equal(source == original, role.GetProperty("role").GetString() == "local");
                }
                var actual = annotations.Where(value => groups.Any(group =>
                    value.StartsWith(group.GetProperty("Group").GetString() + "|Enum(", StringComparison.Ordinal) ||
                    value.StartsWith(group.GetProperty("Group").GetString() + "|FlagsEnum(", StringComparison.Ordinal)));
                Assert.Equal((metadataEnabled
                    ? roles.Select(value => value.GetProperty("payload").GetString())
                    : Array.Empty<string>()).OrderBy(value => value, StringComparer.Ordinal),
                    actual.OrderBy(value => value, StringComparer.Ordinal));
            }
            else if (metadataEnabled)
            {
                foreach (var group in groups)
                {
                    string name = group.GetProperty("Group").GetString();
                    Assert.Single(annotations.Where(value =>
                        value.StartsWith(name + "|Enum(", StringComparison.Ordinal) ||
                        value.StartsWith(name + "|FlagsEnum(", StringComparison.Ordinal)));
                }
            }
            this.output.WriteLine($"{original}/{architecture}/{language}: {groups.Length} exact metadata-only group aliases, {producerCount} producer contracts; " +
                $"compiled native value/type checks, declaration multiplicities, ABI and SAL preserved; " +
                $"{beforeAnnotations.Count} prior Win32 annotation payloads preserved.");
        }

        public static IEnumerable<object[]> SystemEnumCNativeModes()
            => SystemEnumNativeModes().Where(value => (string)value[2] == "x64");

        public static IEnumerable<object[]> SystemEnumNativeModes()
        {
            string artifacts = Environment.GetEnvironmentVariable("SYSTEM_ENUM_MIGRATION_ROOT");
            if (artifacts == null)
            {
                yield return new object[] { "", "", "x64", "x86_64-pc-windows-msvc", true };
                yield break;
            }
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(artifacts, "report.json")));
            foreach (var owner in report.RootElement.GetProperty("owners").EnumerateArray())
            {
                string original = owner.GetProperty("original").GetString();
                string partition = owner.GetProperty("partitionCandidates").EnumerateArray()
                    .Select(value => value.GetString()).First();
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                {
                    yield return new object[] { original, partition, architecture.Item1, architecture.Item2, true };
                    if (architecture.Item1 == "x64")
                        yield return new object[] { original, partition, architecture.Item1, architecture.Item2, false };
                }
            }
        }

        [NativeMigrationTheory("BULK_SYSTEM_MIGRATION_ROOT")]
        [MemberData(nameof(BulkSystemNativeModes))]
        public void BulkSystemHeaderFloorsAndErrorsKeepNativeContracts(
            string partition, string architecture, string target, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string artifacts = Environment.GetEnvironmentVariable("BULK_SYSTEM_MIGRATION_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(artifacts, "report.json")));
            string[] headers = report.RootElement.GetProperty("originals").EnumerateArray()
                .Select(value => Path.GetFileName(value.GetString())).ToArray();
            string sourceText = language == "c" && partition is "Identity" or "Setup" or "Registry"
                ? "#define SECURITY_WIN32\n#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n" +
                    (partition == "Identity" ? "#include <NTSecAPI.h>\n#include <sspi.h>\n#include <wincred.h>\n"
                        : partition == "Setup" ? "#include <msi.h>\n#include <msiquery.h>\n"
                        : "#include <winreg.h>\n")
                : null;
            var beforeSal = new List<string>();
            var disabledSal = new List<string>();
            var enabledSal = new List<string>();
            var annotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, "",
                sourceText: sourceText, salAnnotations: beforeSal, language: language);
            var disabled = Surface(root, prepared, partition, architecture, target, headers, "",
                sourceText: sourceText, salAnnotations: disabledSal, language: language);
            var enabled = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: true, annotations: annotations, sourceText: sourceText, salAnnotations: enabledSal, language: language);
            Assert.NotEmpty(before);
            Assert.Equal(before, disabled);
            Assert.Equal(before, enabled);
            Assert.Equal(beforeSal, disabledSal);
            Assert.Equal(beforeSal, enabledSal);
            int checkedFacts = 0;
            foreach (var fact in report.RootElement.GetProperty("facts").EnumerateArray()
                .Where(value => value.GetProperty("status").GetString() == "converted"))
            {
                string symbol = fact.GetProperty("symbol").GetString();
                if (!before.Any(value => value.StartsWith("function " + symbol + " ", StringComparison.Ordinal)))
                    continue;
                string payload = fact.GetProperty("category").GetString() == "setLastError" ? "SetLastError"
                    : fact.GetProperty("value").GetString().Split('=', 2)[1];
                Assert.Contains(symbol + "|" + payload, annotations);
                checkedFacts++;
            }
            Assert.True(checkedFacts > 0, "The native control must exercise actual converted facts.");
            this.output.WriteLine($"{partition}/{architecture}/{language}: {checkedFacts} authored facts; " +
                "ordinary and metadata native declarations/layout/SAL unchanged.");
        }

        public static IEnumerable<object[]> BulkSystemNativeModes()
        {
            string[] partitions =
            {
                "AppxPackaging", "Authorization", "Com", "ComOle", "Credentials", "DataXchg", "Etw", "Fs",
                "Identity", "Mf", "Mi", "Perf", "Registry", "Security.Cryptography", "Setup", "TermServ",
            };
            string artifacts = Environment.GetEnvironmentVariable("BULK_SYSTEM_MIGRATION_ROOT");
            if (artifacts != null)
            {
                using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(artifacts, "report.json")));
                var traversals = report.RootElement.GetProperty("originals").EnumerateArray()
                    .Select(value => "<IncludeRoot>/" + value.GetString().Replace('\\', '/'))
                    .ToHashSet(StringComparer.OrdinalIgnoreCase);
                partitions = Directory.EnumerateDirectories(Path.Combine(
                        WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "Partitions"))
                    .Where(path => File.Exists(Path.Combine(path, "settings.rsp")) &&
                        File.ReadLines(Path.Combine(path, "settings.rsp")).Any(line => traversals.Contains(line.Trim())))
                    .Select(Path.GetFileName).OrderBy(value => value, StringComparer.Ordinal).ToArray();
                if (partitions.Length == 0)
                    throw new InvalidOperationException("The source batch must have an actual owning traversal.");
            }
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
            {
                foreach (string partition in partitions)
                    yield return new object[] { partition, architecture.Item1, architecture.Item2, "c++" };
                foreach (string partition in new[] { "Identity", "Setup", "Security.Cryptography", "Registry" }.Intersect(partitions))
                    yield return new object[] { partition, architecture.Item1, architecture.Item2, "c" };
            }
        }

        [NativeMigrationTheory("BULK_SYSTEM_MIGRATION_ROOT")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void BulkSystemProjectionPreservesAuthoredFloorsAndErrors(string architecture)
        {
            string artifacts = Environment.GetEnvironmentVariable("BULK_SYSTEM_MIGRATION_ROOT");
            string generated = Environment.GetEnvironmentVariable("BULK_SYSTEM_GENERATED_ROOT");
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(artifacts, "report.json")));
            var methods = Directory.EnumerateFiles(Path.Combine(generated, architecture), "*.cs")
                .SelectMany(path => CSharpSyntaxTree.ParseText(File.ReadAllText(path)).GetRoot().DescendantNodes()
                    .OfType<MethodDeclarationSyntax>())
                .Where(method => method.AttributeLists.SelectMany(list => list.Attributes)
                    .Any(attribute => attribute.Name.ToString().Split('.').Last() is "DllImport" or "DllImportAttribute"))
                .ToLookup(method => method.Identifier.ValueText, StringComparer.Ordinal);
            int checkedFacts = 0;
            int nativeOnly = 0;
            foreach (var fact in report.RootElement.GetProperty("facts").EnumerateArray()
                .Where(value => value.GetProperty("status").GetString() == "converted"))
            {
                var projected = methods[fact.GetProperty("symbol").GetString()].ToArray();
                if (projected.Length == 0)
                {
                    nativeOnly++;
                    continue;
                }
                foreach (var method in projected)
                {
                    var attributes = method.AttributeLists.SelectMany(list => list.Attributes).ToArray();
                    if (fact.GetProperty("category").GetString() == "setLastError")
                    {
                        var import = Assert.Single(attributes.Where(attribute => attribute.Name.ToString().Split('.').Last()
                            is "DllImport" or "DllImportAttribute"));
                        Assert.Contains(import.ArgumentList.Arguments, argument =>
                            argument.NameEquals?.Name.Identifier.ValueText == "SetLastError" && argument.Expression.ToString() == "true");
                    }
                    else
                    {
                        string os = Regex.Match(fact.GetProperty("value").GetString(),
                            "SupportedOSPlatform\\(\"([^\"]+)\"\\)").Groups[1].Value;
                        var actual = attributes.Where(attribute => attribute.Name.ToString().Split('.').Last()
                                is "SupportedOSPlatform" or "SupportedOSPlatformAttribute")
                            .Select(attribute => Assert.IsType<LiteralExpressionSyntax>(
                                Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText).ToArray();
                        Assert.True(actual.SequenceEqual(new[] { os }),
                            $"{architecture}/{method.Identifier}: expected '{os}', actual [{string.Join(", ", actual)}].");
                    }
                }
                checkedFacts++;
            }
            Assert.True(checkedFacts > 0, "The readback must exercise actual emitted native functions.");
            this.output.WriteLine($"{architecture}: {checkedFacts} exact authored payloads read back from generated declarations; " +
                $"{nativeOnly} source facts are outside these selected generated declarations, not claimed as emitted APIs.");
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
                "RstMgr" => @"
static_assert(sizeof(DWORD) == 4);
static_assert(sizeof(((RM_PROCESS_INFO*)nullptr)->AppStatus) == 4);
static_assert(RmStatusUnknown == 0);
static_assert(RmStatusRunning == 1);
static_assert(RmStatusStopped == 2);
static_assert(RmStatusStoppedOther == 4);
static_assert(RmStatusRestarted == 8);
static_assert(RmStatusErrorOnStop == 0x10);
static_assert(RmStatusErrorOnRestart == 0x20);
static_assert(RmStatusShutdownMasked == 0x40);
static_assert(RmStatusRestartMasked == 0x80);
",
                "Cabinets" => @"
static_assert(cpuUNKNOWN == -1);
static_assert(cpu80286 == 0);
static_assert(cpu80386 == 1);
static_assert(sizeof(int) == 4);
",
                "Proc_Snap" => @"
static_assert(sizeof(HPSS) == sizeof(void*));
static_assert(sizeof(HPSSWALK) == sizeof(void*));
static_assert(sizeof(PSS_CAPTURE_FLAGS) == sizeof(DWORD));
static_assert(PSS_CREATE_RELEASE_SECTION == 0x80000000u);
static_assert(PSS_CREATE_MEASURE_PERFORMANCE == 0x40000000);
",
                "Monitor" => @"
static_assert(sizeof(_BOOL) == sizeof(BOOL));
static_assert(sizeof(PHYSICAL_MONITOR) == sizeof(HANDLE) + 128 * sizeof(WCHAR));
static_assert(sizeof(MC_TIMING_REPORT) == 9);
static_assert(MC_CAPS_NONE == 0);
static_assert(MC_RESTORE_FACTORY_DEFAULTS_ENABLES_MONITOR_SETTINGS == 0x1000);
static_assert(MC_SUPPORTED_COLOR_TEMPERATURE_11500K == 0x80);
static_assert(GETCONNECTEDIDS_TARGET == 0);
static_assert(GETCONNECTEDIDS_SOURCE == 1);
static_assert(SETCONFIGURATION_STATUS_APPLIED == 0);
static_assert(SETCONFIGURATION_STATUS_ADDITIONAL == 1);
static_assert(SETCONFIGURATION_STATUS_OVERRIDDEN == 2);
",
                "IdentityProvider" => @"
static_assert(IDENTITIES_ALL == 0);
static_assert(IDENTITIES_ME_ONLY == 1);
static_assert(sizeof(tag_IdentityUpdateEvent) == sizeof(DWORD));
static_assert(IDENTITY_ASSOCIATED == 1);
static_assert(IDENTITY_DISASSOCIATED == 2);
static_assert(IDENTITY_CREATED == 4);
static_assert(IDENTITY_IMPORTED == 8);
static_assert(IDENTITY_DELETED == 16);
static_assert(IDENTITY_PROPCHANGED == 32);
static_assert(IDENTITY_CONNECTED == 64);
static_assert(IDENTITY_DISCONNECTED == 128);
",
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
                "Dwm" => @"
static_assert(__is_same(__underlying_type(DWM_SHOWCONTACT), int));
static_assert(sizeof(DWM_SHOWCONTACT) == 4);
static_assert(DWMSC_DOWN == 1);
static_assert(DWMSC_UP == 2);
static_assert(DWMSC_DRAG == 4);
static_assert(DWMSC_HOLD == 8);
static_assert(DWMSC_PENBARREL == 16);
static_assert(DWMSC_NONE == 0);
static_assert(static_cast<unsigned int>(DWMSC_ALL) == 0xFFFFFFFFu);
",
                "Wer" => @"
static_assert(__is_same(HREPORT, HANDLE));
static_assert(__is_same(HREPORTSTORE, void*));
static_assert(WER_FILE_ANONYMOUS_DATA == 2);
static_assert(WER_FILE_DELETE_WHEN_DONE == 1);
static_assert(WER_SUBMIT_ADD_REGISTERED_DATA == 16);
static_assert(WER_SUBMIT_HONOR_RECOVERY == 1);
static_assert(WER_SUBMIT_HONOR_RESTART == 2);
static_assert(WER_SUBMIT_NO_ARCHIVE == 256);
static_assert(WER_SUBMIT_NO_CLOSE_UI == 64);
static_assert(WER_SUBMIT_NO_QUEUE == 128);
static_assert(WER_SUBMIT_OUTOFPROCESS == 32);
static_assert(WER_SUBMIT_OUTOFPROCESS_ASYNC == 1024);
static_assert(WER_SUBMIT_QUEUE == 4);
static_assert(WER_SUBMIT_SHOW_DEBUG == 8);
static_assert(WER_SUBMIT_START_MINIMIZED == 512);
static_assert(WER_SUBMIT_BYPASS_DATA_THROTTLING == 2048);
static_assert(WER_SUBMIT_ARCHIVE_PARAMETERS_ONLY == 4096);
static_assert(WER_SUBMIT_REPORT_MACHINE_ID == 8192);
static_assert(WER_FAULT_REPORTING_FLAG_DISABLE_THREAD_SUSPENSION == 4);
static_assert(WER_FAULT_REPORTING_FLAG_NOHEAP == 1);
static_assert(WER_FAULT_REPORTING_FLAG_QUEUE == 2);
static_assert(WER_FAULT_REPORTING_FLAG_QUEUE_UPLOAD == 8);
static_assert(WER_FAULT_REPORTING_ALWAYS_SHOW_UI == 16);
",
                "Power" => @"
static_assert(PDCAP_D0_SUPPORTED == 0x00000001);
static_assert(PDCAP_D1_SUPPORTED == 0x00000002);
static_assert(PDCAP_D2_SUPPORTED == 0x00000004);
static_assert(PDCAP_D3_SUPPORTED == 0x00000008);
static_assert(PDCAP_WAKE_FROM_D0_SUPPORTED == 0x00000010);
static_assert(PDCAP_WAKE_FROM_D1_SUPPORTED == 0x00000020);
static_assert(PDCAP_WAKE_FROM_D2_SUPPORTED == 0x00000040);
static_assert(PDCAP_WAKE_FROM_D3_SUPPORTED == 0x00000080);
static_assert(PDCAP_WARM_EJECT_SUPPORTED == 0x00000100);
static_assert(PDCAP_S0_SUPPORTED == 0x00010000);
static_assert(PDCAP_S1_SUPPORTED == 0x00020000);
static_assert(PDCAP_S2_SUPPORTED == 0x00040000);
static_assert(PDCAP_S3_SUPPORTED == 0x00080000);
static_assert(PDCAP_WAKE_FROM_S0_SUPPORTED == 0x00100000);
static_assert(PDCAP_WAKE_FROM_S1_SUPPORTED == 0x00200000);
static_assert(PDCAP_WAKE_FROM_S2_SUPPORTED == 0x00400000);
static_assert(PDCAP_WAKE_FROM_S3_SUPPORTED == 0x00800000);
static_assert(PDCAP_S4_SUPPORTED == 0x01000000);
static_assert(PDCAP_S5_SUPPORTED == 0x02000000);
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
                "Wnet" => @"
#ifdef RESOURCEUSAGE_NONE
#error Metadata-only RESOURCEUSAGE_NONE must not become a native macro
#endif
static_assert(UNIVERSAL_NAME_INFO_LEVEL == 1u);
static_assert(REMOTE_NAME_INFO_LEVEL == 2u);
static_assert(WNPERM_DLG_PERM == 0u);
static_assert(WNPERM_DLG_AUDIT == 1u);
static_assert(WNPERM_DLG_OWNER == 2u);
static_assert(RESOURCEUSAGE_CONNECTABLE == 1u);
static_assert(RESOURCEUSAGE_CONTAINER == 2u);
static_assert(RESOURCEUSAGE_ATTACHED == 16u);
static_assert(RESOURCEUSAGE_ALL == 19u);
static_assert(CONNECT_UPDATE_PROFILE == 1u);
static_assert(CONNECT_UPDATE_RECENT == 2u);
static_assert(CONNECT_TEMPORARY == 4u);
static_assert(CONNECT_INTERACTIVE == 8u);
static_assert(CONNECT_PROMPT == 16u);
static_assert(CONNECT_NEED_DRIVE == 32u);
static_assert(CONNECT_REFCOUNT == 64u);
static_assert(CONNECT_REDIRECT == 128u);
static_assert(CONNECT_LOCALDRIVE == 256u);
static_assert(CONNECT_CURRENT_MEDIA == 512u);
static_assert(CONNECT_DEFERRED == 1024u);
static_assert(CONNECT_RESERVED == 4278190080u);
static_assert(CONNECT_COMMANDLINE == 2048u);
static_assert(CONNECT_CMD_SAVECRED == 4096u);
static_assert(CONNECT_CRED_RESET == 8192u);
static_assert(CONNECT_REQUIRE_INTEGRITY == 16384u);
static_assert(CONNECT_REQUIRE_PRIVACY == 32768u);
static_assert(CONNECT_WRITE_THROUGH_SEMANTICS == 65536u);
static_assert(CONNECT_GLOBAL_MAPPING == 262144u);
static_assert(WNPS_FILE == 0u);
static_assert(WNPS_DIR == 1u);
static_assert(WNPS_MULT == 2u);
static_assert(WNDN_MKDIR == 1u);
static_assert(WNDN_RMDIR == 2u);
static_assert(WNDN_MVDIR == 3u);
static_assert(RESOURCETYPE_ANY == 0u);
static_assert(RESOURCETYPE_DISK == 1u);
static_assert(RESOURCETYPE_PRINT == 2u);
static_assert(WNFMT_MULTILINE == 1u);
static_assert(WNFMT_ABBREVIATED == 2u);
static_assert(RESOURCE_CONNECTED == 1u);
static_assert(RESOURCE_CONTEXT == 5u);
static_assert(RESOURCE_GLOBALNET == 2u);
static_assert(RESOURCE_REMEMBERED == 3u);
static_assert(NETINFO_DLL16 == 1u);
static_assert(NETINFO_DISKRED == 4u);
static_assert(NETINFO_PRINTERRED == 8u);
static_assert(CONNDLG_RO_PATH == 1u);
static_assert(CONNDLG_CONN_POINT == 2u);
static_assert(CONNDLG_USE_MRU == 4u);
static_assert(CONNDLG_HIDE_BOX == 8u);
static_assert(CONNDLG_PERSIST == 16u);
static_assert(CONNDLG_NOT_PERSIST == 32u);
static_assert(DISC_UPDATE_PROFILE == 1u);
static_assert(DISC_NO_FORCE == 64u);
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
        [MemberData(nameof(AuthoredAvailabilityHeaderControls))]
        [MemberData(nameof(AuthoredMonitorHeaderControls))]
        [MemberData(nameof(AuthoredDhcpHeaderControls))]
        public void AuthoredAvailabilityHeadersPreserveNativeAbiAndSalWithExactMetadata(
            string partition, string header, string architecture, string target, string language, bool enabled, string[] expected)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeRawSal = new List<string>();
            var afterRawSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string[] headers = header switch
            {
                "devfiltertypes.h" => new[] { header, "devquery.h", "devquerydef.h" },
                "fdi.h" => new[] { "fci.h", "fdi_fci_types.h", header },
                "bluetoothapis.h" => new[]
                {
                    header, "bluetoothleapis.h", "bthdef.h", "bthledef.h", "ws2bth.h", "bthsdpdef.h",
                },
                "dinput.h" => new[]
                {
                    header, "dinputd.h", "hidclass.h", "hidpi.h", "hidsdi.h", "hidusage.h",
                    "ntddkbd.h", "ntddmou.h", "gpiobuttontypes.h",
                },
                _ => new[] { header },
            };
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string checks = header == "fdi.h" ?
                $"{assertion}(cpuUNKNOWN == -1 && cpu80286 == 0 && cpu80386 == 1 && sizeof(int) == 4, \"native FDI CPU contract\");" : "";
            if (header == "bluetoothapis.h")
            {
                string macroType = language == "c"
                    ? "_Generic((AF_BTH), int: 1, default: 0)"
                    : "__is_same(decltype(AF_BTH), int)";
                string fieldType = language == "c"
                    ? "_Generic(((SOCKADDR_BTH*)0)->addressFamily, unsigned short: 1, default: 0)"
                    : "__is_same(decltype(((SOCKADDR_BTH*)0)->addressFamily), unsigned short)";
                checks = $"{assertion}(AF_BTH == 32 && PF_BTH == 32 && sizeof(AF_BTH) == 4 && {macroType}, \"original Bluetooth address-family macros\");\n" +
                    $"{assertion}({fieldType} && sizeof(((SOCKADDR_BTH*)0)->addressFamily) == 2 && sizeof(SOCKADDR_BTH) == 30, \"original narrow packed Bluetooth address\");";
            }
            if (header == "dinput.h")
            {
                string statusType = language == "c"
                    ? "_Generic((HIDP_STATUS_I8242_TRANS_UNKNOWN), NTSTATUS: 1, default: 0)"
                    : "__is_same(decltype(HIDP_STATUS_I8242_TRANS_UNKNOWN), NTSTATUS)";
                checks = $"{assertion}({statusType} && sizeof(HIDP_STATUS_I8242_TRANS_UNKNOWN) == 4, \"native HID NTSTATUS alias type\");\n" +
                    $"{assertion}(HIDP_STATUS_I8242_TRANS_UNKNOWN == HIDP_STATUS_I8042_TRANS_UNKNOWN && " +
                    $"HIDP_STATUS_I8242_TRANS_UNKNOWN < 0 && (unsigned long)HIDP_STATUS_I8242_TRANS_UNKNOWN == 0xC0110009UL, \"native HID status alias value and bits\");";
            }
            var before = Surface(root, original, partition, architecture, target, headers, checks,
                salAnnotations: beforeSal, rawSalAnnotations: beforeRawSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks, metadataEnabled: enabled,
                annotations: annotations, salAnnotations: afterSal, rawSalAnnotations: afterRawSal,
                diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            if (header == "fdi.h")
            {
                const string carrier = "typedef FDICREATE_CPU_TYPE int";
                Assert.Equal(enabled ? new[] { carrier } : Array.Empty<string>(), after.Except(before));
                Assert.Equal(before, after.Where(value => value != carrier));
            }
            else
                Assert.Equal(before, after);
            if (header is "amxmlgraphbuilder.h" or "wnvapi.h" or "nb30.h")
                Assert.Empty(beforeSal);
            else
                Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal((enabled ? expected : Array.Empty<string>()).OrderBy(value => value, StringComparer.Ordinal),
                annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            if (header == "devfiltertypes.h")
            {
                Assert.Contains("enum _DEVPROP_OPERATOR int", before);
                Assert.Contains(before, value => value.StartsWith("field _DEVPROP_FILTER_EXPRESSION::Operator ",
                    StringComparison.Ordinal) && value.Contains("_DEVPROP_OPERATOR", StringComparison.Ordinal) &&
                    value.EndsWith(" 0", StringComparison.Ordinal));
                foreach (string name in WinHttpMigrationTests.DeviceQueryFilterMethods)
                {
                    var functions = before.Where(value => value.StartsWith("function " + name + " ",
                        StringComparison.Ordinal)).ToArray();
                    Assert.NotEmpty(functions);
                    Assert.All(functions, value => Assert.True(
                        value.Contains("const struct _DEVPROP_FILTER_EXPRESSION *", StringComparison.Ordinal) ||
                        value.Contains("const _DEVPROP_FILTER_EXPRESSION *", StringComparison.Ordinal), value));
                    foreach (string fact in functions)
                        this.output.WriteLine("native-filter-api " + fact);
                }
                foreach (var side in new[] { ("before", before), ("after", after) })
                    foreach (string fact in side.Item2.Where(value =>
                        value.StartsWith("enum ", StringComparison.Ordinal) || value.StartsWith("value ", StringComparison.Ordinal) ||
                        value.StartsWith("field _DEVPROP_FILTER_EXPRESSION::Operator ", StringComparison.Ordinal)))
                    {
                        string detail = fact;
                        if (fact.StartsWith("value ", StringComparison.Ordinal))
                        {
                            long value = long.Parse(fact.Substring(fact.LastIndexOf(' ') + 1),
                                System.Globalization.CultureInfo.InvariantCulture);
                            detail += " bitPattern32=0x" + (value & 0xFFFFFFFFL)
                                .ToString("X8", System.Globalization.CultureInfo.InvariantCulture);
                        }
                        this.output.WriteLine(side.Item1 + " " + detail);
                    }
            }
            if (header == "dwmapi.h")
            {
                Assert.Contains("enum DWM_SHOWCONTACT int", before);
                Assert.Equal(enabled ? 2 : 0, annotations.Count(value => value == "dwAttribute|AssociatedEnum"));
                foreach (string name in new[] { "DwmGetWindowAttribute", "DwmSetWindowAttribute" })
                    Assert.Contains(before, value => value.StartsWith("function " + name + " ", StringComparison.Ordinal) &&
                        value.Contains("unsigned long", StringComparison.Ordinal));
                Assert.Contains(before, value => value.StartsWith("function DwmShowContact ", StringComparison.Ordinal) &&
                    value.Contains("DWM_SHOWCONTACT", StringComparison.Ordinal));
                foreach (var side in new[] { ("before", before), ("after", after) })
                    foreach (string fact in side.Item2.Where(value =>
                        value.StartsWith("enum DWM_SHOWCONTACT ", StringComparison.Ordinal) ||
                        value.StartsWith("value DWM_SHOWCONTACT::", StringComparison.Ordinal) ||
                        value.StartsWith("function DwmGetWindowAttribute ", StringComparison.Ordinal) ||
                        value.StartsWith("function DwmSetWindowAttribute ", StringComparison.Ordinal) ||
                        value.StartsWith("function DwmShowContact ", StringComparison.Ordinal)))
                        this.output.WriteLine(side.Item1 + " " + fact);
            }
            if (header is "fdi.h" or "ProcessSnapshot.h" or "bluetoothapis.h" or "dinput.h")
            {
                Assert.Equal(enabled ? expected.Length : 0, annotations.Count);
                foreach (var side in new[]
                {
                    ("before", before), ("after", after),
                    ("before-sal", beforeSal.ToArray()), ("after-sal", afterSal.ToArray()),
                    ("before-raw-sal", beforeRawSal.ToArray()), ("after-raw-sal", afterRawSal.ToArray()),
                })
                    foreach (string fact in side.Item2)
                        this.output.WriteLine(side.Item1 + " " + fact);
            }
            if (header == "bluetoothapis.h")
                this.output.WriteLine("Original AF_BTH/PF_BTH=32 are signed four-byte int macros; " +
                    "SOCKADDR_BTH.addressFamily remains unsigned two-byte storage and the packed native structure remains 30 bytes. " +
                    "Native macro assertions do not choose a metadata scalar projection.");
            if (header == "dinput.h")
                this.output.WriteLine("The original HID typo macro retains its native signed four-byte NTSTATUS type, " +
                    "canonical alias value and 0xC0110009 bits in both languages and metadata modes; " +
                    "the complete nine-header owner retains every recorded native/layout/SAL fact.");
            this.output.WriteLine($"{partition}/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} identical native facts, {beforeSal.Count} unchanged SAL attributes, " +
                $"{annotations.Distinct(StringComparer.Ordinal).Count()} exact metadata facts.");
        }

        [NativeMigrationTheory]
        [MemberData(nameof(WerOriginalHeaderControls))]
        public void OriginalWerHeadersPreserveNativeAbiAndSalWithExactMetadata(
            string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] headers = { "WerApi.h", "ErrorRep.h" };
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string checks = string.Join("\n", WinHttpMigrationTests.AuthoredWerEnumGroups()
                .SelectMany(group => group.Members)
                .Select(member => $"{assertion}({member.Name} == {member.Value}, \"{member.Name}\");"));
            var before = Surface(root, original, "Wer", architecture, target, headers, checks,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, "Wer", architecture, target, headers, checks,
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            string[] carriers =
            {
                "typedef WER_FAULT_REPORTING unsigned long", "typedef WER_FILE unsigned long",
                "typedef WER_SUBMIT_FLAGS unsigned long",
            };
            Assert.NotEmpty(before);
            Assert.Equal(enabled ? carriers : Array.Empty<string>(), after.Where(value => carriers.Contains(value, StringComparer.Ordinal)));
            Assert.Equal(before, after.Where(value => !carriers.Contains(value, StringComparer.Ordinal)));
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] expected = WinHttpMigrationTests.AuthoredWerHeaderContracts()
                .SelectMany(contract => contract.Functions.Select(name =>
                    name + "|SupportedOSPlatform(\"" + contract.OS + "\")"))
                .Concat(WinHttpMigrationTests.AuthoredWerEnumGroups().Select(group =>
                    group.Name + "|FlagsEnum(" + string.Join(", ", group.Members.Select(member => member.Name)) + ")"))
                .Concat(new[]
                {
                    "dwFlags|AssociatedEnum", "dwFileFlags|AssociatedEnum", "pdwFlags|AssociatedEnum",
                    "phReportHandle|RAIIFree", "phReportStore|RAIIFree",
                    "AddERExcludedApplicationA|SetLastError", "AddERExcludedApplicationW|SetLastError",
                }).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal((enabled ? expected : Array.Empty<string>()),
                annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(enabled ? 47 : 0, annotations.Count);
            foreach (string name in new[] { "WerRegisterFile", "WerReportAddFile", "WerReportSubmit", "WerSetFlags", "WerGetFlags" })
                Assert.Contains(before, value => value.StartsWith("function " + name + " ", StringComparison.Ordinal) &&
                    value.Contains("unsigned long", StringComparison.Ordinal));
            foreach (var side in new[] { ("before", before), ("after", after) })
                foreach (string fact in side.Item2.Where(value => value.StartsWith("function ", StringComparison.Ordinal) ||
                    carriers.Contains(value, StringComparer.Ordinal)))
                    this.output.WriteLine(side.Item1 + " " + fact);
            this.output.WriteLine($"Wer/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} unchanged complete native facts, {beforeSal.Count} unchanged SAL attributes, " +
                "21 original macro values, exactly three metadata-only uint32 typedef carriers when enabled; " +
                $"{annotations.Count} exact metadata occurrences.");
        }

        public static IEnumerable<object[]> WerOriginalHeaderControls()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (string language in new[] { "c", "c++" })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { architecture.Item1, architecture.Item2, language, enabled };
        }

        [NativeMigrationTheory]
        [MemberData(nameof(WebSocketOriginalHeaderControls))]
        public void OriginalWebSocketHeaderPreservesNativeAbiAndSalWithExactMetadata(
            string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeRawSal = new List<string>();
            var afterRawSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string checks = string.Join("\n", new[]
            {
                "sizeof(WEB_SOCKET_HANDLE) == sizeof(void*)", "WEB_SOCKET_MAX_CLOSE_REASON_LENGTH == 123",
                "sizeof(WEB_SOCKET_CLOSE_STATUS) == 4", "sizeof(WEB_SOCKET_PROPERTY_TYPE) == 4",
                "sizeof(WEB_SOCKET_ACTION_QUEUE) == 4", "sizeof(WEB_SOCKET_BUFFER_TYPE) == 4",
                "sizeof(WEB_SOCKET_ACTION) == 4", "WEB_SOCKET_ALL_ACTION_QUEUE == 3",
                "WEB_SOCKET_UTF8_MESSAGE_BUFFER_TYPE == 0x80000000U",
                "WEB_SOCKET_UNSOLICITED_PONG_BUFFER_TYPE == 0x80000006U",
            }.Select(check => $"{assertion}({check}, \"original WebSocket contract\");"));
            var before = Surface(root, original, "WebSock", architecture, target, new[] { "websocket.h" }, checks,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language,
                rawSalAnnotations: beforeRawSal);
            var after = Surface(root, prepared, "WebSock", architecture, target, new[] { "websocket.h" }, checks,
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language, rawSalAnnotations: afterRawSal);
            foreach (var side in new[] { ("before", beforeRawSal), ("after", afterRawSal) })
                foreach (string fact in side.Item2)
                    this.output.WriteLine(side.Item1 + " raw SAL " + fact);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.Equal(13, before.Count(value => value.StartsWith("function WebSocket", StringComparison.Ordinal)));
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeRawSal.Count, beforeSal.Count);
            Assert.Equal(afterRawSal.Count, afterSal.Count);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] expected = WinHttpMigrationTests.WebSocketFunctions
                .Select(name => name + "|SupportedOSPlatform(\"windows8.0\")")
                .Append("phWebSocket|RAIIFree").OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(enabled ? expected : Array.Empty<string>(),
                annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(enabled ? 15 : 0, annotations.Count);
            foreach (var side in new[] { ("before", before), ("after", after) })
                foreach (string fact in side.Item2)
                    this.output.WriteLine(side.Item1 + " " + fact);
            this.output.WriteLine($"WebSock/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} identical complete native facts, {beforeSal.Count} unchanged SAL attributes, " +
                $"all five original enums and native handle widths; {annotations.Count} exact metadata occurrences.");
        }

        public static IEnumerable<object[]> WebSocketOriginalHeaderControls()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (string language in new[] { "c", "c++" })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { architecture.Item1, architecture.Item2, language, enabled };
        }

        public static IEnumerable<object[]> AuthoredAvailabilityHeaderControls()
        {
            foreach (string partition in new[]
            {
                "MdmReg", "Media.DShow", "Media.DShow.Xml", "FileHistory", "SecurityCenter", "DirectML", "wnv", "Wsb",
                "Wec", "Tbs", "WebDav", "NetBios", "NetShell", "Eap", "DeviceQuery", "Dwm", "Cabinets", "Proc_Snap", "Bluetooth", "Hid",
            })
            {
                string[] expected = partition switch
                {
                    "MdmReg" => new[]
                    {
                        "DiscoverManagementService", "DiscoverManagementServiceEx", "GetDeviceRegistrationInfo",
                        "GetManagementAppHyperlink", "IsDeviceRegisteredWithManagement", "IsManagementRegistrationAllowed",
                        "RegisterDeviceWithManagement", "RegisterDeviceWithManagementUsingAADCredentials",
                        "RegisterDeviceWithManagementUsingAADDeviceCredentials", "SetManagedExternally", "UnregisterDeviceWithManagement",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows8.1\")").ToArray(),
                    "FileHistory" => new[]
                    {
                        "FhServiceOpenPipe", "FhServiceClosePipe", "FhServiceStartBackup", "FhServiceStopBackup",
                        "FhServiceReloadConfiguration", "FhServiceBlockBackup", "FhServiceUnblockBackup",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows8.0\")")
                        .Append("Pipe|RAIIFree").ToArray(),
                    "SecurityCenter" => new[]
                    {
                        "WscRegisterForChanges", "WscUnRegisterChanges", "WscGetSecurityProviderHealth",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").ToArray(),
                    "DirectML" => new[] { "DMLCreateDevice|SupportedOSPlatform(\"windows10.0.10240\")" },
                    "wnv" => new[] { "WnvOpen", "WnvRequestNotification" }
                        .Select(name => name + "|SupportedOSPlatform(\"windowsserver2012\")").ToArray(),
                    "Wsb" => new[]
                    {
                        "RegisterOnlineBackupWithWindowsServerBackup", "DeregisterOnlineBackupFromWindowsServerBackup",
                        "UpdateOBStatusInWindowsServerBackup",
                    }.Select(name => name + "|SupportedOSPlatform(\"windowsserver2012\")").ToArray(),
                    "Wec" => new[]
                    {
                        "EcOpenSubscriptionEnum", "EcEnumNextSubscription", "EcOpenSubscription",
                        "EcSetSubscriptionProperty", "EcGetSubscriptionProperty", "EcSaveSubscription",
                        "EcDeleteSubscription", "EcGetObjectArraySize", "EcSetObjectArrayProperty",
                        "EcGetObjectArrayProperty", "EcInsertObjectArrayElement", "EcRemoveObjectArrayElement",
                        "EcGetSubscriptionRunTimeStatus", "EcRetrySubscription", "EcClose",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")")
                        .Append("EcOpenSubscriptionEnum|SetLastError").Append("EcOpenSubscription|SetLastError").ToArray(),
                    "Tbs" => new[]
                    {
                        "Tbsi_Context_Create", "Tbsip_Context_Close", "Tbsip_Submit_Command",
                        "Tbsip_Cancel_Commands", "Tbsi_Physical_Presence_Command",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")")
                        .Concat(new[] { "Tbsi_GetDeviceInfo", "Tbsi_Get_OwnerAuth", "Tbsi_Revoke_Attestation" }
                            .Select(name => name + "|SupportedOSPlatform(\"windows8.0\")"))
                        .Append("Tbsi_Get_TCG_Log_Ex|SupportedOSPlatform(\"windows10.0.17134\")")
                        .Append("GetDeviceID|ImportLibrary").ToArray(),
                    "WebDav" => new[]
                    {
                        "DavAddConnection", "DavDeleteConnection", "DavGetUNCFromHTTPPath", "DavGetHTTPFromUNCPath",
                        "DavGetTheLockOwnerOfTheFile", "DavGetExtendedError", "DavFlushFile", "DavInvalidateCache",
                        "DavCancelConnectionsToServer", "DavRegisterAuthCallback", "DavUnregisterAuthCallback",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").ToArray(),
                    "NetBios" => new[] { "Netbios|SupportedOSPlatform(\"windows5.0\")" },
                    "NetShell" => new[]
                    {
                        "MatchEnumTag", "MatchToken", "PreprocessCommand", "PrintError", "PrintMessageFromModule",
                        "PrintMessage", "RegisterContext", "RegisterHelper",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows5.1.2600\")").ToArray(),
                    "Eap" => new[]
                    {
                        "RasEapGetInfo", "RasEapFreeMemory", "RasEapInvokeInteractiveUI",
                        "RasEapInvokeConfigUI", "RasEapGetIdentity",
                    }.Select(name => name + "|SupportedOSPlatform(\"windows5.0\")").ToArray(),
                    "DeviceQuery" => Array.Empty<string>(),
                    "Dwm" => WinHttpMigrationTests.AuthoredDwmHeaderContracts()
                        .SelectMany(contract => contract.Functions.Select(name =>
                            name + "|SupportedOSPlatform(\"" + contract.OS + "\")"))
                        .Append("dwAttribute|AssociatedEnum").ToArray(),
                    "Cabinets" => WinHttpMigrationTests.AuthoredFdiFunctions
                        .Select(name => name + "|SupportedOSPlatform(\"windows5.0\")")
                        .Concat(new[] { "FDICREATE_CPU_TYPE|Enum(cpuUNKNOWN, cpu80286, cpu80386)", "cpuType|AssociatedEnum" }).ToArray(),
                    "Proc_Snap" => WinHttpMigrationTests.AuthoredProcessSnapshotFunctions
                        .Select(name => name + "|SupportedOSPlatform(\"windows8.1\")")
                        .Append("WalkMarkerHandle|RAIIFree").ToArray(),
                    "Bluetooth" => WinHttpMigrationTests.AuthoredBluetoothHeaderContracts()
                        .SelectMany(contract => contract.Functions.Select(name =>
                            name + "|SupportedOSPlatform(\"" + contract.OS + "\")"))
                        .Concat(WinHttpMigrationTests.AuthoredBluetoothLastErrorFunctions.Select(name => name + "|SetLastError"))
                        .Concat(new[] { "BluetoothFindFirstRadio|RAIIFree", "BluetoothFindFirstDevice|RAIIFree" }).ToArray(),
                    "Hid" => new[] { "joyConfigChanged|SupportedOSPlatform(\"windows5.0\")" },
                    _ => new[] { "IXMLGraphBuilder|SupportedOSPlatform(\"windows5.0\")" },
                };
                string header = partition switch
                {
                    "MdmReg" => "MDMRegistration.h",
                    "FileHistory" => "FhSvcCtl.h",
                    "SecurityCenter" => "Wscapi.h",
                    "DirectML" => "DirectML.h",
                    "wnv" => "wnvapi.h",
                    "Wsb" => "wsbonline.h",
                    "Wec" => "EvColl.h",
                    "Tbs" => "tbs.h",
                    "WebDav" => "davclnt.h",
                    "NetBios" => "nb30.h",
                    "NetShell" => "NetSh.h",
                    "Eap" => "Raseapif.h",
                    "DeviceQuery" => "devfiltertypes.h",
                    "Dwm" => "dwmapi.h",
                    "Cabinets" => "fdi.h",
                    "Proc_Snap" => "ProcessSnapshot.h",
                    "Bluetooth" => "bluetoothapis.h",
                    "Hid" => "dinput.h",
                    _ => "amxmlgraphbuilder.h",
                };
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (string language in partition == "DirectML" || partition.StartsWith("Media.", StringComparison.Ordinal) ?
                        new[] { "c++" } : new[] { "c", "c++" })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                partition, header,
                                architecture.Item1, architecture.Item2, language, enabled, expected,
                            };
            }
        }

        public static IEnumerable<object[]> AuthoredDhcpHeaderControls()
        {
            foreach (var header in DhcpMigrationTests.HeaderContracts().GroupBy(contract => contract.Header))
            {
                string[] expected = header.SelectMany(contract => contract.Functions.Select(name =>
                    name + "|SupportedOSPlatform(\"" + contract.OS + "\")")).ToArray();
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (string language in new[] { "c", "c++" })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                "Dhcp", header.Key, architecture.Item1, architecture.Item2, language, enabled, expected,
                            };
            }
        }

        public static IEnumerable<object[]> AuthoredMonitorHeaderControls()
        {
            foreach (var contract in WinHttpMigrationTests.AuthoredMonitorHeaderContracts())
            {
                string[] expected = contract.Functions
                    .Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")")
                    .Concat(contract.Functions.Except(contract.WithoutLastError, StringComparer.Ordinal)
                        .Select(name => name + "|SetLastError")).ToArray();
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (string language in new[] { "c", "c++" })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                "Monitor", contract.Header,
                                architecture.Item1, architecture.Item2, language, enabled, expected,
                            };
            }
        }

        [NativeMigrationTheory]
        [MemberData(nameof(OriginalWnetHeaderControls))]
        public void OriginalWnetHeadersPreserveNativeAbiAndSalWithSourceBackedGroups(
            string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] headers = { "winnetwk.h", "Npapi.h" };
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            const string checks = @"
#ifdef RESOURCEUSAGE_NONE
#error The existing metadata-only zero member must not become a native macro
#endif
";
            var before = Surface(root, original, "Wnet", architecture, target, headers, checks,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, "Wnet", architecture, target, headers, checks,
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            string[] carriers = enabled
                ? new[]
                {
                    "NET_RESOURCE_SCOPE", "NET_RESOURCE_SCOPE", "NET_RESOURCE_TYPE",
                    "WNET_OPEN_ENUM_USAGE", "WNET_OPEN_ENUM_USAGE",
                    "NET_CONNECT_FLAGS", "NET_CONNECT_FLAGS", "NET_CONNECT_FLAGS", "NET_CONNECT_FLAGS", "NET_CONNECT_FLAGS",
                    "CONNECTDLGSTRUCT_FLAGS", "DISCDLGSTRUCT_FLAGS", "UNC_INFO_LEVEL",
                    "NETWORK_NAME_FORMAT_FLAGS", "NETINFOSTRUCT_CHARACTERISTICS",
                    "NP_PROPERTY_DIALOG_SELECTION", "NPDIRECTORY_NOTIFY_OPERATION", "WNPERM_DLG",
                }.Select(name => "typedef " + name + " unsigned long").ToArray()
                : Array.Empty<string>();
            Assert.NotEmpty(before);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(before.Concat(carriers).OrderBy(value => value, StringComparer.Ordinal), after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            if (enabled)
            {
                var groups = annotations.Select(value => Regex.Match(value,
                    @"^(?<name>[^|]+)\|(?:Flags)?Enum\((?<members>[^)]+)\)$"))
                    .Where(match => match.Success)
                    .GroupBy(match => match.Groups["name"].Value, StringComparer.Ordinal)
                    .ToDictionary(group => group.Key, group => group.SelectMany(match =>
                        match.Groups["members"].Value.Split(',').Select(member => member.Trim()))
                        .Distinct(StringComparer.Ordinal).ToArray(), StringComparer.Ordinal);
                Assert.Equal(WinHttpMigrationTests.NetworkLogicalEnums.OrderBy(value => value, StringComparer.Ordinal),
                    groups.Keys.OrderBy(value => value, StringComparer.Ordinal));
                Assert.Equal(55, groups.Values.Sum(members => members.Length));
                Assert.Contains("RESOURCEUSAGE_NONE", groups["WNET_OPEN_ENUM_USAGE"]);
                Assert.Equal(57, annotations.Distinct(StringComparer.Ordinal)
                    .Count(value => value.Contains("|SupportedOSPlatform(", StringComparison.Ordinal)));
                var associations = annotations.Where(value => value.EndsWith("|AssociatedEnum", StringComparison.Ordinal)).ToArray();
                // Record fields are revisited through the native A/W pointer typedefs.
                Assert.Equal(11, associations.Where(value => value.Contains("::", StringComparison.Ordinal))
                    .Distinct(StringComparer.Ordinal).Count());
                Assert.Equal(69, associations.Count(value => !value.Contains("::", StringComparison.Ordinal)));
                Assert.Equal(2, annotations.Count(value => value.EndsWith("|RAIIFree", StringComparison.Ordinal)));
                Assert.Equal(8, annotations.Count(value => value.EndsWith("|ContainsInteriorPointers", StringComparison.Ordinal)));
                Assert.Equal(2, annotations.Count(value => value.EndsWith("|SetLastError", StringComparison.Ordinal)));
            }
            else
                Assert.Empty(annotations);
            this.output.WriteLine($"{architecture}/{language}/metadata={enabled}: {before.Length} unchanged WNet/Npapi native facts, " +
                $"{beforeSal.Count} unchanged SAL attributes; 12 logical groups/55 members and native DWORD associations when enabled.");
        }

        [NativeMigrationTheory("WINHTTP_DEVICE_PRODUCER_BEFORE")]
        [MemberData(nameof(DeviceProducerHeaderControls))]
        public void DeviceProducerCleanupPreservesActualNativeAbiSalAndAllOtherAnnotations(
            string partition, string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("WINHTTP_DEVICE_PRODUCER_BEFORE");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var transfers = WinHttpMigrationTests.DeviceProducerTransfers.Where(value => value.Partition == partition).ToArray();
            string[] headers = transfers.Select(value => value.Header).Distinct(StringComparer.Ordinal).ToArray();
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: beforeAnnotations, salAnnotations: beforeSal,
                diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: afterAnnotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(before, after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var expected = beforeAnnotations.Concat(enabled
                ? transfers.Select(value => value.Parameter + "|RAIIFree") : Array.Empty<string>());
            Assert.Equal(expected.OrderBy(value => value, StringComparer.Ordinal),
                afterAnnotations.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} unchanged native facts, {beforeSal.Count} unchanged SAL occurrences, " +
                $"{(enabled ? transfers.Length : 0)} exact producer-output cleanup sites; all prior metadata and diagnostics unchanged.");
        }

        public static IEnumerable<object[]> DeviceProducerHeaderControls()
        {
            foreach (string partition in WinHttpMigrationTests.DeviceProducerTransfers.Select(value => value.Partition)
                .Distinct(StringComparer.Ordinal))
                foreach (object[] mode in OriginalErrorOwnerControls())
                    yield return new object[] { partition }.Concat(mode).ToArray();
        }

        [NativeMigrationTheory("WINHTTP_DEVICE_UI_PRODUCER_BEFORE")]
        [MemberData(nameof(DeviceUiProducerHeaderControls))]
        public void DeviceUiProducerCleanupPreservesActualNativeAbiSalAndBorrowedConsumers(
            string partition, string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("WINHTTP_DEVICE_UI_PRODUCER_BEFORE");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var transfers = WinHttpMigrationTests.DeviceUiProducerTransfers.Where(value => value.Partition == partition).ToArray();
            string[] headers = transfers.Select(value => value.Header).Distinct(StringComparer.Ordinal).ToArray();
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: beforeAnnotations, salAnnotations: beforeSal,
                diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: afterAnnotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(before, after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var expected = beforeAnnotations.Concat(enabled
                ? transfers.Select(value => (value.Parameter == "return" ? value.Method : value.Parameter) + "|RAIIFree")
                : Array.Empty<string>());
            Assert.Equal(expected.OrderBy(value => value, StringComparer.Ordinal),
                afterAnnotations.OrderBy(value => value, StringComparer.Ordinal));
            Assert.DoesNotContain(afterAnnotations, value => value == "GetWindowTheme|RAIIFree");
            this.output.WriteLine($"{partition}/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} unchanged native facts, {beforeSal.Count} unchanged SAL occurrences, " +
                $"{(enabled ? transfers.Length : 0)} exact producer return/output sites; borrowed consumers and all prior facts unchanged.");
        }

        public static IEnumerable<object[]> DeviceUiProducerHeaderControls()
        {
            foreach (string partition in WinHttpMigrationTests.DeviceUiProducerTransfers.Select(value => value.Partition)
                .Distinct(StringComparer.Ordinal))
                foreach (object[] mode in OriginalErrorOwnerControls())
                    yield return new object[] { partition }.Concat(mode).ToArray();
        }

        private static readonly string[] MmeapiOpenFragmentMembers =
        {
            "WAVE_FORMAT_QUERY", "WAVE_ALLOWSYNC", "WAVE_MAPPED", "WAVE_FORMAT_DIRECT",
            "WAVE_FORMAT_DIRECT_QUERY", "WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE", "MIDI_IO_STATUS",
        };

        [Fact]
        public void MmeapiOpenFragmentContainsOnlyTheSevenAllocatedNativeNamesInsideTheCompleteMetadataGuard()
        {
            string patch = File.ReadAllText(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "patches", "um", "mmeapi.h.patch"));
            string additions = string.Join("\n", patch.Split('\n')
                .Where(line => line.StartsWith("+", StringComparison.Ordinal) && !line.StartsWith("+++", StringComparison.Ordinal))
                .Select(line => line.Substring(1).TrimEnd('\r')));
            var group = Assert.Single(Regex.Matches(additions,
                @"(?m)^#if defined\(WIN32METADATA\) && !defined\(MIDL_PASS\)\n" +
                @"_Win32_FlagsEnum_\(MIDI_WAVE_OPEN_TYPE, unsigned long,\n(?<members>[^)]+)\);\n#endif$"));
            Assert.Equal(MmeapiOpenFragmentMembers, group.Groups["members"].Value.Split(',').Select(member => member.Trim()));
            Assert.Single(Regex.Matches(additions, "_Win32_FlagsEnum_"));
            Assert.DoesNotContain("_Win32_AssociatedEnum_", additions);
            Assert.DoesNotContain("CALLBACK_", group.Value);
        }

        [NativeMigrationTheory("WINHTTP_MMEAPI_FRAGMENT_CONTROL_HEADERS")]
        [MemberData(nameof(OriginalErrorOwnerControls))]
        public void MmeapiOpenFragmentPreservesAcceptedNativeAbiSalAvailabilityAndSevenCompiledValues(
            string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("WINHTTP_MMEAPI_FRAGMENT_CONTROL_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string main = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", "Audio", "main.cpp"));
            const string lastPrefixInclude = "#include <sdkddkver.h>";
            int prefix = main.IndexOf(lastPrefixInclude, StringComparison.Ordinal);
            Assert.InRange(prefix, 0, main.Length - lastPrefixInclude.Length);
            string source = main.Substring(0, prefix + lastPrefixInclude.Length) +
                "\n#include <mmsystem.h>\n#include <mmreg.h>\n#include <mmeapi.h>\n";
            const string checks = @"
#ifdef __cplusplus
#define MIDI_FRAGMENT_ASSERT static_assert
#else
#define MIDI_FRAGMENT_ASSERT _Static_assert
#endif
MIDI_FRAGMENT_ASSERT(WAVE_FORMAT_QUERY == 1UL, ""native WAVE_FORMAT_QUERY"");
MIDI_FRAGMENT_ASSERT(WAVE_ALLOWSYNC == 2UL, ""native WAVE_ALLOWSYNC"");
MIDI_FRAGMENT_ASSERT(WAVE_MAPPED == 4UL, ""native WAVE_MAPPED"");
MIDI_FRAGMENT_ASSERT(WAVE_FORMAT_DIRECT == 8UL, ""native WAVE_FORMAT_DIRECT"");
MIDI_FRAGMENT_ASSERT(WAVE_FORMAT_DIRECT_QUERY == (WAVE_FORMAT_QUERY | WAVE_FORMAT_DIRECT), ""native WAVE_FORMAT_DIRECT_QUERY expression"");
MIDI_FRAGMENT_ASSERT(WAVE_FORMAT_DIRECT_QUERY == 9UL, ""native WAVE_FORMAT_DIRECT_QUERY value"");
MIDI_FRAGMENT_ASSERT(WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE == 16UL, ""native default communication device"");
MIDI_FRAGMENT_ASSERT(MIDI_IO_STATUS == 32UL, ""native MIDI_IO_STATUS"");
";
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            string[] headers = { "mmeapi.h" };
            var before = Surface(root, original, "Audio", architecture, target, headers, checks,
                metadataEnabled: enabled, sourceText: source, annotations: beforeAnnotations,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, "Audio", architecture, target, headers, checks,
                metadataEnabled: enabled, sourceText: source, annotations: afterAnnotations,
                salAnnotations: afterSal, diagnostics: afterDiagnostics, language: language).ToList();
            Assert.NotEmpty(before);
            Assert.NotEmpty(beforeSal);
            if (enabled)
            {
                Assert.True(after.Remove("typedef MIDI_WAVE_OPEN_TYPE unsigned long"));
                string contribution = Assert.Single(afterAnnotations.Where(value =>
                    value.StartsWith("MIDI_WAVE_OPEN_TYPE|FlagsEnum(", StringComparison.Ordinal)));
                Assert.Equal(MmeapiOpenFragmentMembers, Regex.Match(contribution, @"FlagsEnum\(([^)]+)\)")
                    .Groups[1].Value.Split(',').Select(member => member.Trim()));
                Assert.True(afterAnnotations.Remove(contribution));
            }
            Assert.Equal(before, after);
            Assert.Equal(beforeAnnotations.OrderBy(value => value, StringComparer.Ordinal),
                afterAnnotations.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{architecture}/{language}/metadata={enabled}: seven actual compiled native constants; " +
                "accepted mmeapi ABI, SAL, diagnostics and availability unchanged; fragment only, not full14 union qualification.");
        }

        public static IEnumerable<object[]> OriginalWnetHeaderControls() => OriginalErrorOwnerControls();

        [Fact]
        public void NetworkEnumSourcePatchesRemoveOnlyCoveredLegacyFacts()
        {
            string root = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            string[] headers =
            {
                "ras", "mprapi", "snmp", "winsnmp", "windns", "wlanapi",
                "http", "lmshare", "srrestoreptapi", "rasshost", "certbcli", "peerdist", "mgmtapi", "l2cmn",
            };
            string additions = string.Join("\n", headers.SelectMany(header =>
                File.ReadLines(Path.Combine(root, "patches", "um", header + ".h.patch"))
                    .Where(line => line.StartsWith("+", StringComparison.Ordinal) && !line.StartsWith("+++", StringComparison.Ordinal))
                    .Select(line => line.Substring(1).TrimEnd('\r'))));
            var groups = Regex.Matches(additions,
                @"_Win32_(?<kind>FlagsEnum|Enum)_\((?<name>\w+),\s*(?<storage>\w+),\s*(?<members>[^)]+)\);");
            Assert.Equal(28, groups.Count);
            Assert.Equal(28, groups.Select(group => group.Groups["name"].Value).Distinct(StringComparer.Ordinal).Count());
            Assert.Equal(132, groups.Sum(group => group.Groups["members"].Value.Split(',').Length));
            Assert.Equal(new[]
            {
                "FILE_INFO_FLAGS_PERMISSIONS", "HTTP_INITIALIZE", "RASIKEV_PROJECTION_INFO_FLAGS", "WLAN_NOTIFICATION_SOURCES",
            }, groups.Where(group => group.Groups["kind"].Value == "FlagsEnum")
                .Select(group => group.Groups["name"].Value).OrderBy(value => value, StringComparer.Ordinal));
            foreach (Match group in groups)
            {
                string storage = group.Groups["name"].Value switch
                {
                    "SNMP_LOG" => "int",
                    "HTTP_RECEIVE_HTTP_REQUEST_FLAGS" => "ULONG",
                    _ => "DWORD",
                };
                Assert.Equal(storage, group.Groups["storage"].Value);
                foreach (string member in group.Groups["members"].Value.Split(',').Select(value => value.Trim()))
                    Assert.Matches(@"^[A-Za-z_]\w*$", member);
            }
            Assert.Equal(66, Regex.Matches(additions, @"_Win32_AssociatedEnum_\(").Count);
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "enums.json")));
            foreach (Match group in groups)
            {
                string name = group.Groups["name"].Value;
                var legacy = enums.RootElement.GetProperty("items").EnumerateArray().Where(item =>
                    item.TryGetProperty("name", out var value) && value.GetString() == name ||
                    item.TryGetProperty("addUsesTo", out var additional) && additional.GetString() == name).ToArray();
                Assert.Empty(legacy);
            }
            string[] overrides = File.ReadAllLines(Path.Combine(root, "emitter.settings.rsp"));
            foreach (string row in new[]
            {
                "DnsQuery_A::return=WIN32_ERROR", "DnsQuery_W::return=WIN32_ERROR",
                "DnsQuery_UTF8::return=WIN32_ERROR", "STATEMGRSTATUS::nStatus=WIN32_ERROR",
                "SnmpSvcSetLogType::nLogType=[AssociatedEnum(\"SNMP_OUTPUT_LOG_TYPE\")]",
            })
                Assert.DoesNotContain(row, overrides);
        }

        [NativeMigrationTheory]
        [MemberData(nameof(NetworkEnumOwnerControls))]
        public void OriginalNetworkEnumOwnersPreserveNativeAbiSalAndTypedefMultiplicity(
            string partition, string architecture, string target, bool enabled)
        {
            var (headers, groups, forwards) = partition switch
            {
                "RRas" => (new[] { "ras.h", "mprapi.h", "rasshost.h" },
                    new[]
                    {
                        "RASPPP_PROJECTION_INFO_SERVER_AUTH_PROTOCOL", "RASPPP_PROJECTION_INFO_SERVER_AUTH_DATA",
                        "RASIKEV_PROJECTION_INFO_FLAGS", "MPR_INTERFACE_DIAL_MODE", "MPR_ET", "MPR_VS",
                        "PPP_LCP", "PPP_LCP_INFO_AUTH_DATA", "SECURITY_MESSAGE_MSG_ID",
                    }, new[] { "SECURITY_MESSAGE_MSG_ID" }),
                "Snmp" => (new[] { "snmp.h", "winsnmp.h" },
                    new[]
                    {
                        "SNMP_ERROR_STATUS", "SNMP_GENERICTRAP", "SNMP_LOG", "SNMP_EXTENSION_REQUEST_TYPE",
                        "SNMP_OUTPUT_LOG_TYPE", "SNMP_ERROR", "SNMP_API_TRANSLATE_MODE", "SNMP_STATUS",
                    }, new[] { "SNMP_LOG", "SNMP_OUTPUT_LOG_TYPE" }),
                "Dns" => (new[] { "windns.h" }, Array.Empty<string>(), Array.Empty<string>()),
                "NWifi" => (new[] { "wlanapi.h" },
                    new[] { "WLAN_NOTIFICATION_SOURCES", "WLAN_CONNECTION_NOTIFICATION_FLAGS", "WLAN_SET_EAPHOST_FLAGS" },
                    Array.Empty<string>()),
                "HttpServer" => (new[] { "http.h" },
                    new[] { "HTTP_INITIALIZE", "HTTP_RECEIVE_HTTP_REQUEST_FLAGS" }, Array.Empty<string>()),
                "Fs" => (new[] { "lmshare.h" },
                    new[] { "FILE_INFO_FLAGS_PERMISSIONS", "SESSION_INFO_USER_FLAGS" },
                    new[] { "FILE_INFO_FLAGS_PERMISSIONS", "SESSION_INFO_USER_FLAGS" }),
                "Sr" => (new[] { "srrestoreptapi.h" },
                    new[] { "RESTOREPOINTINFO_TYPE", "RESTOREPOINTINFO_EVENT_TYPE" }, Array.Empty<string>()),
                "Certificates" => (new[] { "certbcli.h" }, new[] { "CSBACKUP_TYPE" }, Array.Empty<string>()),
                "P2p" => (new[] { "peerdist.h" },
                    new[] { "PEERDIST_RETRIEVAL_OPTIONS_CONTENTINFO_VERSION_VALUE" }, Array.Empty<string>()),
                _ => throw new ArgumentException("Unknown network enum owner.", nameof(partition)),
            };
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeRawSal = new List<string>();
            var afterRawSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string checks = enabled ? "" : string.Join("\n", groups.Select(name => "using " + name + " = void;"));
            bool legacySalEnriched = partition is "HttpServer" or "Certificates";
            if (legacySalEnriched)
            {
                headers = headers.Append("main.cpp").ToArray();
                checks += BroadSourceSalProbe;
            }
            var before = Surface(root, original, partition, architecture, target, headers, checks,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, rawSalAnnotations: beforeRawSal);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks,
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, rawSalAnnotations: afterRawSal);
            string[] carriers = enabled ? groups.Concat(forwards).Select(name =>
                "typedef " + name + (name == "SNMP_LOG" ? " int" : " unsigned long")).ToArray() : Array.Empty<string>();
            Assert.NotEmpty(before);
            Assert.Equal(before.Concat(carriers).OrderBy(value => value, StringComparer.Ordinal), after);
            Assert.Equal(beforeSal.Concat(legacySalEnriched ? BroadSourceSalAdditions(beforeSal, partition) :
                    Enumerable.Empty<string>()).OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeRawSal.Count, beforeSal.Count);
            Assert.Equal(afterRawSal.Count, afterSal.Count);
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var actualGroups = annotations.Select(value => Regex.Match(value, @"^(?<name>[^|]+)\|(?:Flags)?Enum\("))
                .Where(match => match.Success).Select(match => match.Groups["name"].Value)
                .Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(enabled ? groups.OrderBy(value => value, StringComparer.Ordinal) : Array.Empty<string>(), actualGroups);
            if (!enabled)
                Assert.Empty(annotations);
            this.output.WriteLine($"{partition}/{architecture}/metadata={enabled}: " +
                $"{before.Length} unchanged native signature/type/layout/value/typedef facts; " +
                $"{beforeSal.Count} unchanged SAL attributes and matched diagnostics; " +
                $"{carriers.Length} exact metadata-only typedef occurrences, {actualGroups.Length} logical groups.");
        }

        public static IEnumerable<object[]> NetworkEnumOwnerControls()
        {
            foreach (string partition in new[] { "RRas", "Snmp", "Dns", "NWifi", "HttpServer", "Fs", "Sr", "Certificates", "P2p" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { partition, architecture.Item1, architecture.Item2, enabled };
        }

        [Fact]
        public void NetworkCategorySourcePatchesRetainCrossingGroupsAndHandleContracts()
        {
            string root = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            string[] originals =
            {
                @"shared\rpcdce", @"shared\rpcdcep", @"um\wininet", @"um\gpedit", @"um\winsafer",
                @"um\winwlx", @"um\iphlpapi", @"um\winldap", @"um\ws2spi", @"um\clfsmgmtw32",
            };
            string additions = string.Join("\n", originals.SelectMany(original =>
                File.ReadLines(Path.Combine(root, "patches", original.Replace('\\', Path.DirectorySeparatorChar) + ".h.patch"))
                    .Where(line => line.StartsWith("+", StringComparison.Ordinal) && !line.StartsWith("+++", StringComparison.Ordinal))
                    .Select(line => line.Substring(1).TrimEnd('\r'))));
            var groups = Regex.Matches(additions,
                @"_Win32_(?<kind>FlagsEnum|Enum)_\((?<name>\w+),\s*(?<storage>\w+),\s*(?<members>[^)]+)\);");
            string[] expectedGroups =
            {
                "FTP_FLAGS", "GOPHER_TYPE", "GPO_OPEN_FLAGS", "GPO_OPTIONS", "GPO_SECTION", "HTTP_ADDREQ_FLAG",
                "INTERNET_ACCESS_TYPE", "INTERNET_PER_CONN", "RPC_BINDING_HANDLE_OPTIONS_FLAGS", "RPC_C_HTTP_AUTHN_TARGET",
                "RPC_C_HTTP_FLAGS", "RPC_C_QOS_CAPABILITIES", "RPC_C_QOS_IDENTITY",
                "SAFER_COMPUTE_TOKEN_FROM_LEVEL_FLAGS", "WLX_SHUTDOWN_TYPE",
            };
            Assert.Equal(expectedGroups, groups.Select(group => group.Groups["name"].Value)
                .OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(78, groups.Sum(group => group.Groups["members"].Value.Split(',').Length));
            Assert.Equal(new[]
            {
                "GPO_OPTIONS", "HTTP_ADDREQ_FLAG", "RPC_BINDING_HANDLE_OPTIONS_FLAGS", "RPC_C_HTTP_AUTHN_TARGET",
                "RPC_C_HTTP_FLAGS", "RPC_C_QOS_CAPABILITIES", "SAFER_COMPUTE_TOKEN_FROM_LEVEL_FLAGS",
            }, groups.Where(group => group.Groups["kind"].Value == "FlagsEnum")
                .Select(group => group.Groups["name"].Value).OrderBy(value => value, StringComparer.Ordinal));
            foreach (Match group in groups)
            {
                Assert.Equal("DWORD", group.Groups["storage"].Value);
                foreach (string member in group.Groups["members"].Value.Split(',').Select(value => value.Trim()))
                    Assert.Matches(@"^[A-Za-z_]\w*$", member);
            }
            Assert.Equal(55, Regex.Matches(additions, @"_Win32_AssociatedEnum_\(").Count);
            Assert.Equal(27, Regex.Matches(additions, @"_Win32_ContainsInteriorPointers_").Count);
            Assert.Equal(4, Regex.Matches(additions, @"(?m)^typedef DWORD (?:INTERNET_ACCESS_TYPE|INTERNET_PER_CONN|GOPHER_TYPE|HTTP_ADDREQ_FLAG);$").Count);
            Assert.Contains("_In_ unsigned short *EntryName", additions);
            Assert.Contains("_In_ RPC_SERVER_INTERFACE * RpcInterfaceInformation", additions);
            Assert.Contains("_In_  PULONGLONG pDesiredSize", additions);
            Assert.Contains("_Out_ PULONGLONG pResultingSize", additions);
            using var enums = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "enums.json")));
            var retained = enums.RootElement.GetProperty("items").EnumerateArray().ToArray();
            foreach (string name in expectedGroups)
                Assert.DoesNotContain(retained, item =>
                    item.TryGetProperty("name", out var value) && value.GetString() == name ||
                    item.TryGetProperty("addUsesTo", out var additional) && additional.GetString() == name);
            foreach (string name in new[]
            {
                "RPC_C_AUTHN_LEVEL", "RPC_C_IMP_LEVEL", "RPC_C_AUTHN_INFO_TYPE", "INTERNET_COOKIE_FLAGS",
                "INTERNET_STATE", "PROXY_AUTO_DETECT_TYPE",
            })
                Assert.Contains(retained, item => item.TryGetProperty("name", out var value) && value.GetString() == name);
            Assert.DoesNotContain(retained, item =>
                item.TryGetProperty("name", out var value) && value.GetString() == "GET_ADAPTERS_ADDRESSES_FLAGS");
            Assert.Contains("_Win32_FlagsEnum_(GET_ADAPTERS_ADDRESSES_FLAGS, unsigned long,",
                File.ReadAllText(Path.Combine(root, "patches", "um", "iptypes.h.patch")));
            string[] overrides = File.ReadAllLines(Path.Combine(root, "emitter.settings.rsp"));
            foreach (string row in new[]
            {
                "GetNetworkParams::return=WIN32_ERROR", "LdapMapErrorToWin32::return=WIN32_ERROR",
                "LdapMapErrorToWin32::LdapError=[AssociatedEnum(\"LDAP_RETCODE\")]",
                "I_RpcNsInterfaceExported::EntryName=[In]", "I_RpcNsInterfaceExported::RpcInterfaceInformation=[In]",
                "SetLogFileSizeWithPolicy::pDesiredSize=[In]", "SetLogFileSizeWithPolicy::pResultingSize=[Out]",
            })
                Assert.DoesNotContain(row, overrides);
            var heldUrlUses = Assert.Single(retained.Where(item =>
                item.TryGetProperty("addUsesTo", out var additional) && additional.GetString() == "WIN_HTTP_CREATE_URL_FLAGS"));
            Assert.Equal(new[] { "InternetCrackUrlA::dwFlags", "InternetCrackUrlW::dwFlags" },
                heldUrlUses.GetProperty("uses").EnumerateArray().Select(use =>
                    use.GetProperty("method").GetString() + "::" + use.GetProperty("parameter").GetString()));
            Assert.DoesNotContain("_Win32_RAIIFree_", additions);
        }

        [NativeMigrationTheory]
        [MemberData(nameof(NetworkCategoryOwnerControls))]
        public void OriginalNetworkCategoryOwnersPreserveNativeSurfaceAndExactSalEnrichments(
            string partition, string architecture, string target, bool enabled, bool cInterface)
        {
            var (headers, groups, forwards) = partition switch
            {
                "Rpc" => (new[] { "rpcdce.h", "rpcdcep.h" },
                    new[] { "RPC_C_QOS_CAPABILITIES", "RPC_C_QOS_IDENTITY", "RPC_C_HTTP_FLAGS",
                        "RPC_C_HTTP_AUTHN_TARGET", "RPC_BINDING_HANDLE_OPTIONS_FLAGS" }, Array.Empty<string>()),
                "WinInet" => (new[] { "wininet.h" },
                    new[] { "FTP_FLAGS", "HTTP_ADDREQ_FLAG", "GOPHER_TYPE", "INTERNET_PER_CONN", "INTERNET_ACCESS_TYPE" },
                    new[] { "INTERNET_ACCESS_TYPE", "INTERNET_PER_CONN", "GOPHER_TYPE", "HTTP_ADDREQ_FLAG" }),
                "Policy" => (new[] { "gpedit.h" }, new[] { "GPO_OPEN_FLAGS", "GPO_OPTIONS", "GPO_SECTION" }, Array.Empty<string>()),
                "Security.AppLocker" => (new[] { "winsafer.h" }, new[] { "SAFER_COMPUTE_TOKEN_FROM_LEVEL_FLAGS" }, Array.Empty<string>()),
                "Security.WinWlx" => (new[] { "winwlx.h" }, new[] { "WLX_SHUTDOWN_TYPE" }, Array.Empty<string>()),
                "IpHlp" => (new[] { "iphlpapi.h" }, Array.Empty<string>(), Array.Empty<string>()),
                "Ldap" => (new[] { "winldap.h" }, Array.Empty<string>(), Array.Empty<string>()),
                "WinSock" => (new[] { "ws2spi.h" }, Array.Empty<string>(), Array.Empty<string>()),
                "Fs" => (new[] { "clfsmgmtw32.h" }, Array.Empty<string>(), Array.Empty<string>()),
                _ => throw new ArgumentException("Unknown network category owner.", nameof(partition)),
            };
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeRawSal = new List<string>();
            var afterRawSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string checks = enabled ? "" : string.Join("\n", groups.Select(name => "using " + name + " = void;"));
            var before = Surface(root, original, partition, architecture, target, headers, checks,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, cInterface: cInterface, rawSalAnnotations: beforeRawSal);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks,
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, cInterface: cInterface, rawSalAnnotations: afterRawSal);
            string[] carriers = enabled ? groups.Concat(forwards).Select(name => "typedef " + name + " unsigned long").ToArray() : Array.Empty<string>();
            Assert.NotEmpty(before);
            Assert.Equal(before.Concat(carriers).OrderBy(value => value, StringComparer.Ordinal), after);
            var addedSal = new List<string>();
            string directionProbe = partition switch
            {
                "Rpc" => "\nvoid NativeDirectionProbe(_In_ unsigned short *EntryName, _In_ RPC_SERVER_INTERFACE *RpcInterfaceInformation);",
                "Fs" => "\nvoid NativeDirectionProbe(_In_ PULONGLONG pDesiredSize, _Out_ PULONGLONG pResultingSize);",
                _ => "",
            };
            if (directionProbe.Length != 0)
            {
                Surface(root, original, partition, architecture, target, new[] { "main.cpp" }, directionProbe,
                    salAnnotations: addedSal, cInterface: cInterface);
                Assert.NotEmpty(addedSal);
            }
            Assert.Equal(beforeSal.Concat(addedSal).OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeRawSal.Count, beforeSal.Count);
            Assert.Equal(afterRawSal.Count, afterSal.Count);
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var actualGroups = annotations.Select(value => Regex.Match(value, @"^(?<name>[^|]+)\|(?:Flags)?Enum\("))
                .Where(match => match.Success).Select(match => match.Groups["name"].Value)
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(enabled ? groups.OrderBy(value => value, StringComparer.Ordinal) : Array.Empty<string>(), actualGroups);
            int buffers = partition switch
            {
                "WinInet" => 18,
                "IpHlp" => 7,
                "WinSock" => architecture == "x86" ? 0 : 2,
                _ => 0,
            };
            Assert.Equal(enabled ? buffers : 0, annotations.Count(value => value.EndsWith("|ContainsInteriorPointers", StringComparison.Ordinal)));
            if (!enabled)
                Assert.Empty(annotations);
            this.output.WriteLine($"{partition}/{architecture}/metadata={enabled}/CINTERFACE={cInterface}: " +
                $"{before.Length} unchanged native signature/type/layout/value/typedef facts; " +
                $"{beforeSal.Count} unchanged SAL attributes plus {addedSal.Count} exact native direction attributes; " +
                $"matched diagnostics, {carriers.Length} exact metadata-only typedef occurrences, {actualGroups.Length} logical groups.");
        }

        public static IEnumerable<object[]> NetworkCategoryOwnerControls()
        {
            foreach (string partition in new[] { "Rpc", "WinInet", "Policy", "Security.AppLocker", "Security.WinWlx", "IpHlp", "Ldap", "WinSock", "Fs" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (bool enabled in new[] { false, true })
                        foreach (bool cInterface in partition == "Policy" ? new[] { false, true } : new[] { false })
                            yield return new object[] { partition, architecture.Item1, architecture.Item2, enabled, cInterface };
        }

        [NativeMigrationTheory]
        [MemberData(nameof(OriginalErrorOwnerControls))]
        public void OriginalErrorOwnersPreserveNativeAbiAndSalWithCompleteGroupContributions(
            string architecture, string target, string language, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string[] headers = { "winerror.h", "SetupAPI.h" };
            var before = Surface(root, original, "DevInst", architecture, target, headers, "",
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, "DevInst", architecture, target, headers, "", metadataEnabled: enabled,
                annotations: annotations, salAnnotations: afterSal, diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            Assert.NotEmpty(beforeSal);
            string[] carriers = enabled ? new[]
            {
                "typedef WIN32_ERROR unsigned long", "typedef WIN32_ERROR unsigned long",
            } : Array.Empty<string>();
            Assert.Equal(before.Concat(carriers).OrderBy(value => value, StringComparer.Ordinal), after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            const string prefix = "WIN32_ERROR|Enum(";
            foreach (string annotation in annotations)
            {
                Assert.StartsWith(prefix, annotation);
                Assert.EndsWith(")", annotation);
            }
            Assert.Equal(enabled ? new[] { 90, 3288, 3288 } : Array.Empty<int>(),
                annotations.Select(value => value.Substring(prefix.Length, value.Length - prefix.Length - 1)
                    .Split(',').Length).OrderBy(value => value));
            if (enabled)
            {
                var inherited = annotations.Where(value => value.Substring(prefix.Length, value.Length - prefix.Length - 1)
                    .Split(',').Length == 3288).ToArray();
                Assert.Equal(inherited[0], inherited[1]);
            }
            this.output.WriteLine($"{architecture}/{language}/metadata={enabled}: {before.Length} unchanged native facts, " +
                $"{beforeSal.Count} unchanged SAL attributes; two UInt32 group carriers and one exact inherited annotation when enabled.");
        }

        public static IEnumerable<object[]> OriginalErrorOwnerControls()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (string language in new[] { "c", "c++" })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { architecture.Item1, architecture.Item2, language, enabled };
        }

        [NativeMigrationTheory]
        [MemberData(nameof(OriginalRpcAliasControls))]
        public void OriginalRpcAliasesHaveExplicitSignedUserAndKernelContracts(
            string architecture, string target, string language, bool kernel, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string assertion = language == "c" ? "_Static_assert" : "static_assert";
            string source = (kernel ? "#define _KRPCENV_ 1\n" : "") +
                "#define WIN32_LEAN_AND_MEAN 1\n#include <windows.h>\n#include <winternl.h>\n#include <ntstatus.h>\n#include <rpcnterr.h>\n";
            var aliases = new[]
            {
                ("RPC_X_SS_CONTEXT_MISMATCH", kernel ? unchecked((int)0xC0030005) : 6),
                ("RPC_X_INVALID_BUFFER", kernel ? unchecked((int)0xC0000206) : 1784),
                ("RPC_X_PIPE_APP_MEMORY", kernel ? unchecked((int)0xC0000017) : 14),
            };
            foreach (var alias in aliases)
            {
                string signedLong = language == "c"
                    ? $"_Generic(({alias.Item1}), long: 1, default: 0)"
                    : $"__is_same(decltype({alias.Item1}), long)";
                source += $"{assertion}({alias.Item1} == {alias.Item2.ToString(System.Globalization.CultureInfo.InvariantCulture)}L, \"exact native alias value\");\n" +
                    $"{assertion}(sizeof({alias.Item1}) == 4 && {signedLong}, \"native signed Windows LONG, not unsigned enum storage\");\n";
            }
            // This original header is macro-only; the compiler assertions, not invented declarations, witness its contracts.
            Assert.Empty(Surface(root, original, "Foundation", architecture, target, new[] { "rpcnterr.h" }, "",
                sourceText: source, language: language));
            Assert.Empty(Surface(root, prepared, "Foundation", architecture, target, new[] { "rpcnterr.h" }, "",
                sourceText: source, language: language, metadataEnabled: enabled));
            this.output.WriteLine($"{architecture}/{language}/kernel={kernel}/metadata={enabled}: " +
                string.Join(", ", aliases.Select(alias => alias.Item1 + "=" +
                    alias.Item2.ToString(System.Globalization.CultureInfo.InvariantCulture))) +
                "; all three original macros are signed 32-bit Windows LONG in both native branches. " +
                "This source witness does not admit a metadata value/type change or choose a projection for both branches.");
        }

        public static IEnumerable<object[]> OriginalRpcAliasControls()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (string language in new[] { "c", "c++" })
                    foreach (bool kernel in new[] { false, true })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[] { architecture.Item1, architecture.Item2, language, kernel, enabled };
        }

        [NativeMigrationTheory("WINHTTP_PRISTINE_PREPARED_HEADERS")]
        [MemberData(nameof(OriginalIdlHeaderControls))]
        public void OriginalIdlBatchPreservesNativeAbiAndSalWithExactMetadata(
            string partition, string header, string architecture, string target, string language,
            bool cInterface, bool enabled, string[] expected)
            => this.AssertOriginalIdlHeaderControl(partition, header, architecture, target, language, cInterface, enabled, expected);

        [NativeMigrationTheory("WINHTTP_PRISTINE_PREPARED_HEADERS")]
        [MemberData(nameof(DeviceOriginalIdlHeaderControls))]
        public void OriginalDeviceIdlHeadersPreserveNativeAbiAndSalWithExactMetadata(
            string partition, string header, string architecture, string target, string language,
            bool cInterface, bool enabled, string[] expected)
            => this.AssertOriginalIdlHeaderControl(partition, header, architecture, target, language, cInterface, enabled, expected);

        private void AssertOriginalIdlHeaderControl(string partition, string header, string architecture,
            string target, string language, bool cInterface, bool enabled, string[] expected)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string source = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                (cInterface ? "#define CINTERFACE 1\n" : "") +
                (cInterface && header == "d3d11_4.h" ? "#define D3D11_NO_HELPERS 1\n" : "") +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n" +
                (header == "videoacc.h" ? "#include <strmif.h>\n" : "") +
                (header.Equals("commoncontrols.h", StringComparison.OrdinalIgnoreCase) ? "#include <commctrl.h>\n" : "") +
                "#include <" + header + ">\n";
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, new[] { header }, "",
                sourceText: source, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, new[] { header }, "", metadataEnabled: enabled,
                annotations: annotations, sourceText: source, salAnnotations: afterSal, diagnostics: afterDiagnostics,
                language: language);
            Assert.NotEmpty(before);
            string[] nativeAfter = NormalizeInterfaceCarrierTypedefs(before, after, enabled ? expected : Array.Empty<string>());
            Assert.Equal(before, nativeAfter);
            int typeCarriers = after.Length - nativeAfter.Length;
            if (language == "c++" && !cInterface &&
               (header == "dcompanimation.h" ||
                   (partition == "Shell" && header.Equals("inputpanelconfiguration.h", StringComparison.OrdinalIgnoreCase))))
                Assert.Empty(beforeSal);
            else
                Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] facts = annotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            string[] resultCarriers = facts.Where(value => value.StartsWith("_WIN32META_METHOD_", StringComparison.Ordinal)).ToArray();
            if (partition == "Com.Events" && enabled && language == "c++" && !cInterface)
            {
                string carrier = Assert.Single(resultCarriers.Select(value => value.Split('|')[0]).Distinct(StringComparer.Ordinal));
                Assert.Equal(new[] { carrier + "|Method", carrier + "|PreserveResult" }, resultCarriers);
            }
            else
                Assert.Empty(resultCarriers);
            Assert.Equal((enabled ? expected : Array.Empty<string>()).OrderBy(value => value, StringComparer.Ordinal),
                facts.Except(resultCarriers, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}/{language}/CINTERFACE={cInterface}/metadata={enabled}: " +
                $"{before.Length} identical native facts, {beforeSal.Count} unchanged SAL attributes, " +
                $"{typeCarriers} exact same-name type-carrier redeclarations, {facts.Length} exact availability/result annotation facts.");
        }

        internal static string[] NormalizeInterfaceCarrierTypedefs(
            string[] original, string[] prepared, string[] expectedAnnotations)
        {
            var originalCounts = original.GroupBy(value => value, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.Count(), StringComparer.Ordinal);
            var preparedCounts = prepared.GroupBy(value => value, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.Count(), StringComparer.Ordinal);
            // The named MIDL carrier repeats an existing same-name typedef, not a new native type.
            var carriers = expectedAnnotations.Select(value => value.Split('|')[0])
                .Select(name => $"typedef {name} {name}")
                .Where(value => originalCounts.TryGetValue(value, out int before) && before > 0 &&
                    preparedCounts.TryGetValue(value, out int after) && after == before + 1)
                .ToHashSet(StringComparer.Ordinal);
            return prepared.Where(value => !carriers.Remove(value)).ToArray();
        }

        public static IEnumerable<object[]> OriginalIdlHeaderControls()
        {
            var owners = new[]
            {
                ("InputRadial", "RadialControllerInterop.h", new[]
                {
                    "IRadialControllerConfigurationInterop|SupportedOSPlatform(\"windows10.0.14393\")",
                    "IRadialControllerInterop|SupportedOSPlatform(\"windows10.0.14393\")",
                }),
                ("Dedup", "ddpbackup.h", new[]
                {
                    "IDedupBackupSupport|SupportedOSPlatform(\"windowsserver2012\")",
                    "IDedupReadFileCallback|SupportedOSPlatform(\"windowsserver2012\")",
                }),
                ("Win32_Tile_Badge_Notif", "NotificationActivationCallback.h", new[]
                {
                    "INotificationActivationCallback|SupportedOSPlatform(\"windows10.0.10240\")",
                }),
                ("Wsb", "wsbapp.h", new[]
                {
                    "IWsbApplicationAsync|SupportedOSPlatform(\"windowsserver2008\")",
                    "IWsbApplicationBackupSupport|SupportedOSPlatform(\"windowsserver2008\")",
                    "IWsbApplicationRestoreSupport|SupportedOSPlatform(\"windowsserver2008\")",
                }),
                ("WinContacts", "IContact.h", new[]
                {
                    "IContactManager", "IContactCollection", "IContactProperties", "IContact", "IContactPropertyCollection",
                }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").ToArray()),
                ("FileHistory", "FhCfg.h", new[]
                {
                    "IFhTarget", "IFhScopeIterator", "IFhConfigMgr", "IFhReassociation",
                }.Select(name => name + "|SupportedOSPlatform(\"windows8.0\")").ToArray()),
                ("Nla", "netlistmgr.h", new[]
                {
                    "INetworkListManager", "INetworkListManagerEvents", "INetwork", "IEnumNetworks", "INetworkEvents",
                    "INetworkConnection", "IEnumNetworkConnections", "INetworkConnectionEvents",
                }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").Concat(new[]
                {
                    "INetworkCostManager", "INetworkCostManagerEvents", "INetworkConnectionCost", "INetworkConnectionCostEvents",
                }.Select(name => name + "|SupportedOSPlatform(\"windows8.0\")")).ToArray()),
                ("Rdc", "msrdc.h", new[]
                {
                    "IRdcGeneratorParameters", "IRdcGeneratorFilterMaxParameters", "IRdcGenerator",
                    "IRdcFileReader", "IRdcFileWriter", "IRdcSignatureReader", "IRdcComparator", "IRdcLibrary",
                    "ISimilarityReportProgress", "ISimilarityTableDumpState", "ISimilarityTraitsMappedView",
                    "ISimilarityTraitsMapping", "ISimilarityTraitsTable", "ISimilarityFileIdTable",
                    "IRdcSimilarityGenerator", "IFindSimilarResults", "ISimilarity",
                }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").ToArray()),
                ("Com.CallObj", "callobj.h", new[]
                {
                    "ICallFrame", "ICallIndirect", "ICallInterceptor", "ICallFrameEvents", "ICallUnmarshal", "ICallFrameWalker",
                }.Select(name => name + "|SupportedOSPlatform(\"windows5.0\")").ToArray()),
                ("Com.Events", "EventSys.h", new[]
                {
                    "IEventSystem", "IEventPublisher", "IEventClass", "IEventClass2", "IEventSubscription", "IFiringControl",
                    "IPublisherFilter", "IMultiInterfacePublisherFilter", "IEventObjectChange", "IEventObjectChange2",
                    "IEnumEventObject", "IEventObjectCollection", "IEventProperty", "IEventControl", "IMultiInterfaceEventControl",
                }.Select(name => name + "|SupportedOSPlatform(\"windows5.0\")").ToArray()),
                ("Antimalware", "amsi.h", new[]
                {
                    "IAmsiStream", "IAntimalwareProvider", "IAntimalware",
                }.Select(name => name + "|SupportedOSPlatform(\"windows10.0.10240\")").ToArray()),
                ("Eap", "RrasCfg.h", new[]
                {
                    "IEAPProviderConfig|SupportedOSPlatform(\"windows5.0\")",
                }),
            };
            foreach (var owner in owners)
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (var mode in new[] { ("c", false), ("c++", false), ("c++", true) })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                owner.Item1, owner.Item2, architecture.Item1, architecture.Item2,
                                mode.Item1, mode.Item2, enabled,
                                (mode.Item1 == "c++" ? owner.Item3 : Array.Empty<string>()).Concat(owner.Item1 switch
                                {
                                    "Com.CallObj" => new[] { "CoGetInterceptor|SupportedOSPlatform(\"windows5.0\")" },
                                    "Antimalware" => new[]
                                    {
                                        "AmsiInitialize", "AmsiUninitialize", "AmsiOpenSession", "AmsiCloseSession",
                                        "AmsiScanBuffer", "AmsiScanString",
                                    }.Select(name => name + "|SupportedOSPlatform(\"windows10.0.10240\")"),
                                    _ => Array.Empty<string>(),
                                }).ToArray(),
                            };
        }

        public static IEnumerable<object[]> DeviceOriginalIdlHeaderControls()
        {
            foreach (var owner in WinHttpMigrationTests.DeviceIdlOriginalHeaderContracts())
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (var mode in new[] { ("c", false), ("c++", false), ("c++", true) })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                owner.Partition, owner.Header, architecture.Item1, architecture.Item2,
                                mode.Item1, mode.Item2, enabled, mode.Item1 == "c++"
                                    ? owner.Interfaces.Select(name => name + "|SupportedOSPlatform(\"" + owner.OS + "\")").ToArray()
                                    : Array.Empty<string>(),
                            };
        }

        [NativeMigrationTheory]
        [MemberData(nameof(WcmOriginalHeaderControls))]
        public void OriginalWcmHeaderPreservesNativeAbiAndSalWithExactMetadata(
            string architecture, string target, string language, bool cInterface, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string source = (cInterface ? "#define CINTERFACE 1\n" : "") +
                File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", "Wcm", "main.cpp"));
            string[] headers = { "wcmapi.h" };
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            var before = Surface(root, original, "Wcm", architecture, target, headers, "",
                sourceText: source, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, "Wcm", architecture, target, headers, "", metadataEnabled: enabled,
                annotations: annotations, sourceText: source, salAnnotations: afterSal, diagnostics: afterDiagnostics,
                language: language);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] expected = enabled ? new[]
            {
                "WcmFreeMemory|SupportedOSPlatform(\"windows8.0\")",
                "WcmGetProfileList|SupportedOSPlatform(\"windows8.0\")",
                "WcmQueryProperty|SupportedOSPlatform(\"windows8.0\")",
                "WcmSetProfileList|SupportedOSPlatform(\"windows8.0\")",
                "WcmSetProperty|SupportedOSPlatform(\"windows8.0\")",
            } : Array.Empty<string>();
            Assert.Equal(expected, annotations.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{architecture}/{language}/CINTERFACE={cInterface}/metadata={enabled}: " +
                $"{before.Length} identical native facts, {beforeSal.Count} unchanged SAL attributes, " +
                $"{expected.Length} exact availability facts.");
        }

        public static IEnumerable<object[]> WcmOriginalHeaderControls()
        {
            foreach (var architecture in new[]
            {
                ("x86", "i686-pc-windows-msvc"),
                ("x64", "x86_64-pc-windows-msvc"),
                ("arm64", "aarch64-pc-windows-msvc"),
            })
                foreach (var mode in new[] { ("c", false), ("c++", false), ("c++", true) })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { architecture.Item1, architecture.Item2, mode.Item1, mode.Item2, enabled };
        }

        [NativeMigrationTheory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void ApplicationVerifierNativeEnumTagCompilesInCWithoutChangingAbiOrSal(
            string architecture, string target, bool enabled)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string[] headers = { "avrfsdk.h" };
            var originalSal = new List<string>();
            var preparedSal = new List<string>();
            var originalDiagnostics = new List<string>();
            var preparedDiagnostics = new List<string>();
            var before = Surface(root, original, "ApplicationVerifier", architecture, target, headers, "",
                salAnnotations: originalSal, diagnostics: originalDiagnostics, language: "c");
            var after = Surface(root, prepared, "ApplicationVerifier", architecture, target, headers, "",
                metadataEnabled: enabled, salAnnotations: preparedSal, diagnostics: preparedDiagnostics, language: "c");
            const string metadataCarrier = "typedef VERIFIER_ENUM_RESOURCE_FLAGS unsigned long";
            Assert.Equal(enabled ? new[] { metadataCarrier } : Array.Empty<string>(), after.Except(before));
            Assert.Equal(before, after.Where(value => value != metadataCarrier));
            Assert.Equal(originalSal.OrderBy(value => value, StringComparer.Ordinal),
                preparedSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(originalDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                preparedDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Contains("value eAvrfResourceTypes::AvrfResourceHeapAllocation 0", before);
            Assert.Contains("value eAvrfResourceTypes::AvrfResourceHandleTrace 1", before);
            Assert.Contains("value eAvrfResourceTypes::AvrfResourceMax 2", before);
            this.output.WriteLine($"ApplicationVerifier/{architecture}/C/metadata={enabled}: " +
                $"{before.Length} unchanged native facts, {originalSal.Count} unchanged SAL facts.");
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

        [NativeMigrationTheory]
        [MemberData(nameof(DeviceFamilyOriginalHeaderControls))]
        public void OriginalDeviceFamilyHeadersPreserveNativeAbiSalAndExactMetadata(
            string partition, string architecture, string target, string language, bool enabled)
            => this.AssertDeviceFamilyHeaderControl(partition, architecture, target, language, enabled);

        [NativeMigrationTheory]
        [MemberData(nameof(OriginalErrorOwnerControls))]
        public void OriginalDeviceInstallationProcessorGroupsPreserveNativeAbiSalAndExactMetadata(
            string architecture, string target, string language, bool enabled)
            => this.AssertDeviceFamilyHeaderControl("DevInst", architecture, target, language, enabled, processorGroups: true);

        private void AssertDeviceFamilyHeaderControl(
            string partition, string architecture, string target, string language, bool enabled, bool processorGroups = false)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var availability = WinHttpMigrationTests.AuthoredDeviceFamilyHeaderContracts()
                .Where(contract => contract.Partition == partition).ToArray();
            var errors = WinHttpMigrationTests.AuthoredDeviceFamilyLastErrorContracts()
                .Where(contract => contract.Partition == partition).ToArray();
            string[] headers = availability.Select(contract => contract.Header).Distinct(StringComparer.Ordinal).ToArray();
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string sourceText = processorGroups ? "#define NT_PROCESSOR_GROUPS 1\n" +
                File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "main.cpp")) : null;
            var before = Surface(root, original, partition, architecture, target, headers, "",
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language, sourceText: sourceText);
            var after = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: annotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language, sourceText: sourceText);
            Assert.NotEmpty(before);
            if (processorGroups)
                Assert.Equal(3, before.Where(value => Regex.IsMatch(value,
                    @"^field \w+::(?:IRQD_Flags|IRQR_Flags) unsigned short \d+$")).Distinct(StringComparer.Ordinal).Count());
            var native = after.ToList();
            if (partition == "DevInst" && enabled)
                AssertDeviceInstallationGroupContributions(native, annotations);
            Assert.Equal(before, native);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] expected = availability.SelectMany(contract => contract.Functions
                .Select(name => NativeName(name) + "|SupportedOSPlatform(\"" + contract.OS + "\")"))
                .Concat(errors.SelectMany(contract => contract.Functions.Select(name => NativeName(name) + "|SetLastError")))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            foreach (string name in availability.SelectMany(contract => contract.Functions)
                .Concat(errors.SelectMany(contract => contract.Functions)).Distinct(StringComparer.Ordinal))
                Assert.Contains(before, value => value.StartsWith("function " + NativeName(name) + " ", StringComparison.Ordinal));
            Assert.Equal(enabled ? expected : Array.Empty<string>(),
                annotations.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} unchanged native facts, {beforeSal.Count} unchanged SAL occurrences, " +
                $"{annotations.Count} exact availability/last-error facts; the original CM_Wait alias remains CMP_Wait.");

            static string NativeName(string name) => name == "CM_WaitNoPendingInstallEvents" ? "CMP_WaitNoPendingInstallEvents" : name;
        }

        private static void AssertDeviceInstallationGroupContributions(List<string> native, List<string> annotations)
        {
            string[] configurations = annotations.Where(value => value.StartsWith("CM_LOG_CONF|Enum(", StringComparison.Ordinal)).ToArray();
            Assert.NotEmpty(configurations);
            foreach (string configuration in configurations)
                Assert.Equal(new[] { "BASIC_LOG_CONF", "FILTERED_LOG_CONF", "ALLOC_LOG_CONF", "BOOT_LOG_CONF",
                    "FORCED_LOG_CONF", "OVERRIDE_LOG_CONF", "NUM_LOG_CONF" },
                    configuration[(configuration.IndexOf('(') + 1)..^1].Split(',').Select(value => value.Trim()));
            annotations.RemoveAll(configurations.Contains);
            Assert.Equal(2, native.RemoveAll(value => value == "typedef CM_LOG_CONF unsigned long"));
            Assert.True(annotations.Remove("ulFlags|AssociatedEnum"));
            Assert.True(annotations.Remove("ulFlags|AssociatedEnum"));
            var groupAnnotations = annotations.Select(value => Regex.Match(value,
                @"^(?<name>[^|]+)\|(?<flags>Flags)?Enum\((?<members>[^)]+)\)$"))
                .Where(match => match.Success).ToArray();
            Assert.Equal(33, groupAnnotations.Length);
            Assert.Equal(26, groupAnnotations.Select(match => match.Value).Distinct(StringComparer.Ordinal).Count());
            var groups = groupAnnotations.GroupBy(match => match.Groups["name"].Value, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.ToArray(), StringComparer.Ordinal);
            Assert.Equal(WinHttpMigrationTests.DeviceInstallationGroups.Select(group => group.Name).OrderBy(name => name, StringComparer.Ordinal),
                groups.Keys.OrderBy(name => name, StringComparer.Ordinal));
            foreach (var group in WinHttpMigrationTests.DeviceInstallationGroups)
            {
                var contributions = groups[group.Name];
                int occurrences = group.Name is "DIINSTALLDRIVER_FLAGS" or "CM_REENUMERATE_FLAGS" ? 6 :
                    group.Name == "CM_RESTYPE" ? 3 : 1;
                Assert.Equal(occurrences, contributions.Length);
                Assert.All(contributions, match => Assert.Equal(group.Flags, match.Groups["flags"].Success));
                Assert.Equal(group.Members, contributions.SelectMany(match => match.Groups["members"].Value
                    .Split(',').Select(member => member.Trim())).Distinct(StringComparer.Ordinal).Count());
            }
            string[] carriers = WinHttpMigrationTests.DeviceInstallationGroups.Select(group => group.Name)
                .Concat(new[] { "DIINSTALLDRIVER_FLAGS", "DIINSTALLDRIVER_FLAGS", "CM_RESTYPE",
                    "CM_REENUMERATE_FLAGS", "CM_REENUMERATE_FLAGS", "CM_CDMASK", "CM_CDFLAGS" })
                .Select(name => "typedef " + name + " unsigned long").ToArray();
            Assert.Equal(28, carriers.Length);
            foreach (string carrier in carriers)
                Assert.True(native.Remove(carrier), "Missing exact metadata-only integral typedef: " + carrier);
            var associations = annotations.Where(value => value.EndsWith("|AssociatedEnum", StringComparison.Ordinal)).ToArray();
            Assert.Equal(26, associations.Count(value => !value.Contains("::", StringComparison.Ordinal)));
            Assert.Equal(15, associations.Where(value => value.Contains("::", StringComparison.Ordinal))
                .Distinct(StringComparer.Ordinal).Count());
            var known = groupAnnotations.Select(match => match.Value).Concat(associations).ToHashSet(StringComparer.Ordinal);
            annotations.RemoveAll(known.Contains);
        }

        public static IEnumerable<object[]> DeviceFamilyOriginalHeaderControls()
        {
            foreach (string partition in new[] { "DevInst", "Buses", "SwDevice" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (string language in new[] { "c", "c++" })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[] { partition, architecture.Item1, architecture.Item2, language, enabled };
        }

        [NativeMigrationTheory("WINHTTP_DEVICE_BATCH_CONTRACTS")]
        [MemberData(nameof(DeviceBulkOriginalHeaderControls))]
        public void OriginalDeviceBulkHeadersPreserveNativeAbiSalAndBoundMetadata(
            string partition, string architecture, string target, string language, bool enabled)
            => this.AssertOriginalDeviceHeaderControl(partition, architecture, target, language, enabled,
                WinHttpMigrationTests.DeviceBulkOriginalHeaders().Single(owner => owner.Partition == partition).Headers);

        [NativeMigrationTheory("WINHTTP_DEVICE_BATCH_CONTRACTS")]
        [MemberData(nameof(DeviceContinuationOriginalHeaderControls))]
        public void OriginalDeviceContinuationHeadersPreserveNativeAbiSalAndBoundMetadata(
            string partition, string architecture, string target, string language, bool enabled)
            => this.AssertOriginalDeviceHeaderControl(partition, architecture, target, language, enabled,
                WinHttpMigrationTests.DeviceContinuationOriginalHeaders().Single(owner => owner.Partition == partition)
                    .Headers.Select(Path.GetFileName).ToArray());

        [NativeMigrationTheory("WINHTTP_DEVICE_BATCH_CONTRACTS")]
        [MemberData(nameof(DeviceFollowingOriginalHeaderControls))]
        public void OriginalDeviceRecordHeadersPreserveNativeAbiSalAndBoundMetadata(
            string partition, string architecture, string target, string language, bool enabled)
            => this.AssertOriginalDeviceHeaderControl(partition, architecture, target, language, enabled,
                WinHttpMigrationTests.DeviceFollowingOriginalHeaders().Single(owner => owner.Partition == partition)
                    .Headers.Select(Path.GetFileName).ToArray());

        private void AssertOriginalDeviceHeaderControl(string partition, string architecture, string target,
            string language, bool enabled, string[] headers)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string sourceText = null;
            if (language == "c")
            {
                string main = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "main.cpp"));
                string lastPrefixInclude = partition == "SecBitomet" ? "#include <winbio.h>" : "#include <sdkddkver.h>";
                int prefixEnd = main.IndexOf(lastPrefixInclude, StringComparison.Ordinal);
                Assert.InRange(prefixEnd, 0, main.Length - lastPrefixInclude.Length);
                if (partition != "SecBitomet")
                    prefixEnd += lastPrefixInclude.Length;
                sourceText = main.Substring(0, prefixEnd) + "\n";
                if (Regex.IsMatch(main, @"(?m)^#define\s+UNICODE\b"))
                    sourceText += "#define UNICODE\n";
                if (partition == "Audio")
                    sourceText += "#include <mmsystem.h>\n#include <mmreg.h>\n";
                if (partition == "Fax")
                    sourceText += "#define WIN32 1\n#define IN _In_\n#define OUT _Out_\n";
                if (partition == "WebServicesOnDevices")
                    sourceText += "#include <wsdxml.h>\n#include <wsdtypes.h>\n";
                if (partition == "WinAuto")
                    sourceText += "#include <uiautomationcore.h>\n";
                sourceText += string.Join("\n", headers.Select(header => "#include <" + header + ">")) + "\n";
            }
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            var before = Surface(root, original, partition, architecture, target, headers, "",
                sourceText: sourceText, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, headers, "",
                metadataEnabled: enabled, annotations: annotations, sourceText: sourceText, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            using var contracts = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WINHTTP_DEVICE_BATCH_CONTRACTS")));
            var boundFacts = contracts.RootElement.GetProperty("facts").EnumerateArray().ToArray();
            var withoutCarriers = after.ToList();
            int recordCarriers = 0;
            if (enabled && language == "c++")
            {
                foreach (string header in headers)
                {
                    string path = new[] { "shared", "um", "winrt", "ucrt" }
                        .Select(directory => Path.Combine(prepared, directory, header)).Single(File.Exists);
                    foreach (Match carrier in Regex.Matches(File.ReadAllText(path),
                        @"(?m)^[ \t]*#if defined\(WIN32METADATA\) && defined\(__clang__\) && defined\(__cplusplus\)\r?\n" +
                        @"[ \t]*typedef _Win32_SupportedOS_\w+_ (?:struct|class) (?<name>\w+) \k<name>;\r?\n" +
                        @"[ \t]*#endif\r?\n"))
                    {
                        string name = carrier.Groups["name"].Value;
                        Assert.Single(boundFacts.Where(fact =>
                            Path.GetFileName(fact.GetProperty("original").GetString()) == header &&
                            fact.GetProperty("symbol").GetString() == name &&
                            fact.GetProperty("category").GetString() == "supportedOS" &&
                            fact.GetProperty("status").GetString() == "converted"));
                        Assert.Contains(before, declaration => declaration.StartsWith("record " + name + " ", StringComparison.Ordinal));
                        string native = "typedef " + name + " " + name;
                        Assert.Equal(before.Count(declaration => declaration == native) + 1,
                            withoutCarriers.Count(declaration => declaration == native));
                        Assert.True(withoutCarriers.Remove(native));
                        recordCarriers++;
                    }
                }
            }
            Assert.Equal(before, withoutCarriers);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var expected = new List<string>();
            foreach (var fact in boundFacts)
            {
                if (!headers.Contains(Path.GetFileName(fact.GetProperty("original").GetString()), StringComparer.OrdinalIgnoreCase))
                    continue;
                string status = fact.GetProperty("status").GetString();
                Assert.Contains(status, new[] { "converted", "retained" });
                if (status == "retained")
                {
                    Assert.Equal(0, fact.GetProperty("annotationCount").GetInt32());
                    continue;
                }
                Assert.True(fact.GetProperty("annotationCount").GetInt32() > 0);
                string name = fact.GetProperty("symbol").GetString();
                string category = fact.GetProperty("category").GetString();
                Assert.Contains(category, new[] { "supportedOS", "setLastError" });
                string value = "SetLastError";
                if (category == "supportedOS")
                {
                    string row = fact.GetProperty("value").GetString();
                    Assert.StartsWith(name + "=SupportedOSPlatform(", row);
                    value = row.Substring(name.Length + 1);
                }
                int occurrences = before.Count(declaration =>
                    declaration.StartsWith("function " + name + " ", StringComparison.Ordinal));
                if (category == "supportedOS")
                    occurrences += before.Count(declaration =>
                        declaration.StartsWith("record " + name + " ", StringComparison.Ordinal));
                for (int i = 0; i < occurrences; i++)
                    expected.Add(name + "|" + value);
            }
            Assert.NotEmpty(expected);
            string[] expectedAnnotations = expected.OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(enabled ? expectedAnnotations : Array.Empty<string>(),
                annotations.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}/{language}/metadata={enabled}: " +
                $"{before.Length} unchanged native facts, {beforeSal.Count} unchanged SAL occurrences, " +
                $"{recordCarriers} exact metadata-only same-name record aliases, " +
                $"{annotations.Count} exact source-bound availability/last-error facts; " +
                (language == "c" ? "owned-header C17 context" : "complete owner C++ context") + ".");
        }

        public static IEnumerable<object[]> DeviceBulkOriginalHeaderControls()
        {
            foreach (var owner in WinHttpMigrationTests.DeviceBulkOriginalHeaders())
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (string language in new[] { "c", "c++" })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[] { owner.Partition, architecture.Item1, architecture.Item2, language, enabled };
        }

        public static IEnumerable<object[]> DeviceContinuationOriginalHeaderControls()
        {
            foreach (var owner in WinHttpMigrationTests.DeviceContinuationOriginalHeaders())
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { owner.Partition, architecture.Item1, architecture.Item2, "c++", enabled };
        }

        public static IEnumerable<object[]> DeviceFollowingOriginalHeaderControls()
        {
            foreach (var owner in WinHttpMigrationTests.DeviceFollowingOriginalHeaders())
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (bool enabled in new[] { false, true })
                        yield return new object[] { owner.Partition, architecture.Item1, architecture.Item2, "c++", enabled };
        }

        [NativeMigrationTheory("NETWORK_BROAD_CONTROL_HEADERS")]
        [MemberData(nameof(NetworkBroadSourceControls))]
        public void NetworkBroadSourceContractsPreserveNativeAbiAndExactSalChanges(
            string partition, string architecture, string target, string language, bool cInterface, bool enabled)
        {
            string header = partition switch
            {
                "HttpServer" => "http.h",
                "Certificates" => "certbcli.h",
                "Dns" => "windns.h",
                "NWifi" => "wlanapi.h",
                "Policy" => "gpedit.h",
                "ActiveDirectory" => "dsclient.h",
                "RRas" => "mprapi.h",
                "MsCs" => "resapi.h",
                "Printing" => "winspool.h",
                _ => throw new ArgumentException("Unknown broad source owner.", nameof(partition)),
            };
            string root = WinHttpMigrationTests.RepositoryRoot;
            string control = Environment.GetEnvironmentVariable("NETWORK_BROAD_CONTROL_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            string[] headers = { header, "main.cpp" };
            // The unrelated WinHTTP include contains C++ helpers; the owned HTTP header also supports C.
            string sourceText = partition == "HttpServer" && language == "c" ?
                "#include \"intrinfix.h\"\n#define IN _In_\n#define OUT _Out_\n#include <WinSock2.h>\n#include <http.h>\n" : null;
            if (language == "c" && partition is "RRas" or "MsCs")
                sourceText = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n#include \"intrinfix.h\"\n" +
                    "#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n#include <" + header + ">\n";
            string controlSourceText = sourceText;
            string controlHeader = null;
            if (partition == "Printing")
            {
                controlHeader = Environment.GetEnvironmentVariable("NETWORK_WINSPOOL_CONTROL_HEADER");
                Assert.True(!string.IsNullOrEmpty(controlHeader) && File.Exists(controlHeader),
                    "Set NETWORK_WINSPOOL_CONTROL_HEADER to the complete inherited Winspool source before this batch.");
                string prefix = "#define SECURITY_WIN32\n#include \"intrinfix.h\"\n" +
                    "#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n";
                controlSourceText = prefix + "#include \"" + controlHeader + "\"\n";
                sourceText = prefix + "#include <winspool.h>\n";
            }
            var before = Surface(root, control, partition, architecture, target, headers, BroadSourceSalProbe,
                metadataEnabled: enabled, annotations: beforeAnnotations, salAnnotations: beforeSal,
                diagnostics: beforeDiagnostics, language: language, cInterface: cInterface, sourceText: controlSourceText);
            var after = Surface(root, prepared, partition, architecture, target, headers, BroadSourceSalProbe,
                metadataEnabled: enabled, annotations: afterAnnotations, salAnnotations: afterSal,
                diagnostics: afterDiagnostics, language: language, cInterface: cInterface, sourceText: sourceText);
            string[] carriers = enabled && partition == "HttpServer" ?
                new[] { "typedef HTTP_RECEIVE_HTTP_REQUEST_FLAGS unsigned long" } : Array.Empty<string>();
            Assert.NotEmpty(before);
            Assert.Equal(before.Concat(carriers).OrderBy(value => value, StringComparer.Ordinal), after);
            if (controlHeader != null)
                beforeDiagnostics = beforeDiagnostics.Select(value => value.Replace(controlHeader,
                    Path.Combine("<headers>", "um", "winspool.h"), StringComparison.OrdinalIgnoreCase)).ToList();
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            var addedSal = BroadSourceSalAdditions(beforeSal, partition);
            Assert.Equal(beforeSal.Concat(addedSal).OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            var addedAnnotations = new List<string>();
            if (enabled)
            {
                switch (partition)
                {
                    case "HttpServer":
                        addedAnnotations.AddRange(new[]
                        {
                            "HTTP_RECEIVE_HTTP_REQUEST_FLAGS|Enum(HTTP_RECEIVE_REQUEST_FLAG_COPY_BODY, HTTP_RECEIVE_REQUEST_FLAG_FLUSH_BODY)",
                            "Flags|AssociatedEnum",
                            "RequestBuffer|ContainsInteriorPointers", "pOutput|ContainsInteriorPointers",
                            "SslClientCertInfo|ContainsInteriorPointers",
                            "HttpSendHttpResponse|SupportedOSPlatform(\"windows6.0.6000\")",
                            "HttpSendResponseEntityBody|SupportedOSPlatform(\"windows6.0.6000\")",
                        });
                        addedAnnotations.AddRange(Enumerable.Repeat("Overlapped|Retained", 12));
                        break;
                    case "Dns":
                        addedAnnotations.AddRange(Enumerable.Repeat("pContext|RAIIFree", 2));
                        break;
                    case "NWifi":
                        addedAnnotations.Add("phClientHandle|RAIIFree");
                        break;
                    case "RRas":
                        addedAnnotations.Add("MprInfoBlockFind|SupportedOSPlatform(\"windowsserver2000\")");
                        break;
                    case "MsCs":
                        addedAnnotations.Add("ResUtilGetBinaryValue|SupportedOSPlatform(\"windowsserver2008\")");
                        break;
                    case "Printing":
                        foreach (string name in new[] { "_PRINTER_OPTIONSA", "_PRINTER_OPTIONSW" })
                        {
                            int occurrences = before.Count(value => value.StartsWith("field " + name + "::dwFlags ",
                                StringComparison.Ordinal));
                            Assert.True(occurrences > 0, "Missing inherited native printer option field: " + name);
                            Assert.Contains("field " + name + "::dwFlags unsigned long 32", before);
                            addedAnnotations.AddRange(Enumerable.Repeat(name + "::dwFlags|AssociatedEnum", occurrences));
                        }
                        break;
                    case "Policy":
                    case "ActiveDirectory":
                        bool cStyle = language == "c" || cInterface;
                        foreach (string name in partition == "Policy" ?
                            new[] { "IGPEInformation", "IGroupPolicyObject", "IRSOPInformation" } :
                            new[] { "IDsBrowseDomainTree", "IDsDisplaySpecifier" })
                        {
                            int occurrences = (cStyle ? 3 : 2) +
                                (name == "IDsDisplaySpecifier" && language == "c++" ? 1 : 0);
                            addedAnnotations.AddRange(Enumerable.Repeat(
                                name + "|SupportedOSPlatform(\"windows6.0.6000\")", occurrences));
                        }
                        break;
                }
            }
            Assert.Equal(beforeAnnotations.Concat(addedAnnotations).OrderBy(value => value, StringComparer.Ordinal),
                afterAnnotations.OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}/{language}/CINTERFACE={cInterface}/metadata={enabled}: " +
                $"{before.Length} unchanged native signature/type/layout/value/typedef facts; " +
                $"{addedSal.Count} exact legacy-SAL enrichments, {addedAnnotations.Count} exact source annotations; matched diagnostics.");
        }

        public static IEnumerable<object[]> NetworkBroadSourceControls()
        {
            foreach (string partition in new[] { "HttpServer", "Certificates", "Dns", "NWifi", "Policy", "ActiveDirectory", "RRas", "MsCs", "Printing" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (var mode in partition is "Policy" or "ActiveDirectory" ?
                        new[] { ("c++", false), ("c++", true), ("c", false) } :
                        new[] { ("c++", false), ("c", false) })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                partition, architecture.Item1, architecture.Item2, mode.Item1, mode.Item2, enabled,
                            };
        }

        [NativeMigrationTheory("WINHTTP_DEVICE_POSITIVE_BEFORE")]
        [MemberData(nameof(DevicePositiveEnumNativeControls))]
        public void DevicePositiveEnumCarriersPreserveOriginalNativeAbiAndSal(string partition, string architecture, string target)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            using var report = System.Text.Json.JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WINHTTP_DEVICE_POSITIVE_ENUM_CONTRACTS")));
            var groups = report.RootElement.GetProperty("selected").EnumerateArray().ToArray();
            string[] headers = report.RootElement.GetProperty("authoredHeaders").EnumerateArray()
                .Select(header => Path.GetFileName(header.GetString())).ToArray();
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            var before = Surface(root, Environment.GetEnvironmentVariable("WINHTTP_DEVICE_POSITIVE_BEFORE"), partition,
                architecture, target, headers, "", metadataEnabled: true, annotations: beforeAnnotations,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics);
            var after = Surface(root, Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS"), partition,
                architecture, target, headers, "", metadataEnabled: true, annotations: afterAnnotations,
                salAnnotations: afterSal, diagnostics: afterDiagnostics).ToList();
            Assert.NotEmpty(before);
            foreach (var group in groups)
            {
                string carrier = "typedef " + group.GetProperty("name").GetString() + " " + group.GetProperty("nativeStorage").GetString();
                Assert.DoesNotContain(carrier, before);
                after.RemoveAll(fact => fact == carrier);
            }
            Assert.Equal(before, after);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            foreach (var use in groups.SelectMany(group => group.GetProperty("uses").EnumerateArray()))
            {
                if (!use.TryGetProperty("nativeRoute", out var route) || route.GetProperty("partition").GetString() != partition)
                    continue;
                string[] targetParts = use.GetProperty("symbol").GetString().Split("::", StringSplitOptions.None);
                string function = "function " + string.Join("::", targetParts[..^1]) + " ";
                bool present = route.GetProperty("architectures").EnumerateArray().Any(value => value.GetString() == architecture);
                Assert.Equal(present, before.Any(fact => fact.StartsWith(function, StringComparison.Ordinal)));
                Assert.Equal(present, after.Any(fact => fact.StartsWith(function, StringComparison.Ordinal)));
            }
            foreach (string annotation in beforeAnnotations)
                Assert.True(afterAnnotations.Remove(annotation), "Lost an existing native metadata fact: " + annotation);
            foreach (string annotation in afterAnnotations)
            {
                if (annotation.EndsWith("|AssociatedEnum", StringComparison.Ordinal))
                    continue;
                var match = Regex.Match(annotation, @"^(?<name>[^|]+)\|(?<flags>Flags)?Enum\((?<members>[^)]+)\)$");
                Assert.True(match.Success, "Unexpected new native metadata fact: " + annotation);
                var group = Assert.Single(groups.Where(item => item.GetProperty("name").GetString() == match.Groups["name"].Value));
                Assert.Equal(group.GetProperty("flags").GetBoolean(), match.Groups["flags"].Success);
                Assert.Equal(group.GetProperty("members").EnumerateArray().Select(member => member.GetProperty("name").GetString()),
                    match.Groups["members"].Value.Split(',').Select(member => member.Trim()));
            }
            Assert.NotEmpty(afterAnnotations);
            this.output.WriteLine($"{partition}/{architecture}: {before.Length} unchanged native/layout facts, " +
                $"{beforeSal.Count} unchanged SAL occurrences, all prior metadata retained; " +
                $"{afterAnnotations.Count} new group/use AST annotations checked by normal exact-value/use projection.");
        }

        public static IEnumerable<object[]> DevicePositiveEnumNativeControls()
        {
            foreach (string partition in new[] { "Controls", "Controls.RichEdit", "Debug", "DevInst", "DlgBox", "Fs", "Gdi", "Shell", "Wds" })
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    yield return new object[] { partition, architecture.Item1, architecture.Item2 };
        }

        private const string BroadSourceSalProbe = @"
void NetworkBroadSourceSalProbe(
    _In_ void *networkProbeInput,
    _Out_ void *networkProbeOutput,
    _In_opt_ void *networkProbeOptionalInput,
    _Out_opt_ void *networkProbeOptionalOutput,
    _Inout_opt_ void *networkProbeOptionalInOut);
";

        private static List<string> BroadSourceSalAdditions(List<string> control, string partition)
        {
            var added = new List<string>();
            void Add(string parameter, string probe, int count = 1)
            {
                string[] values = control.Where(value =>
                    value.StartsWith(probe + "|", StringComparison.Ordinal)).ToArray();
                Assert.NotEmpty(values);
                foreach (string value in values)
                {
                    string payload = value.Substring(value.IndexOf('|') + 1);
                    added.AddRange(Enumerable.Repeat(parameter + "|" + payload, count));
                }
            }
            if (partition == "HttpServer")
            {
                Add("Overlapped", "networkProbeOptionalInOut", 12);
                foreach (string name in new[]
                {
                    "Name", "SecurityAttributes", "Flags", "ByteRange", "CachePolicy",
                    "EntityChunkCount", "Reserved1", "Reserved2", "Reserved",
                })
                    Add(name, "networkProbeOptionalInput");
                Add("LogData", "networkProbeOptionalInput", 2);
                Add("BytesSent", "networkProbeOptionalOutput", 2);
            }
            else if (partition == "Certificates")
            {
                Add("hbc", "networkProbeInput");
                Add("ppwszzFileList", "networkProbeOutput");
                Add("pcbSize", "networkProbeOutput");
            }
            return added;
        }

        internal static unsafe string[] Surface(string root, string includeRoot, string partition, string architecture,
            string target, string[] headers, string checks, bool metadataEnabled = false, List<string> annotations = null,
            string sourceText = null, List<string> salAnnotations = null, List<string> diagnostics = null,
            string language = "c++", bool cInterface = false, List<string> rawSalAnnotations = null,
            bool includeCallableOwners = false)
        {
            string source = Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "main.cpp");
            string[] partitionOptions = File.ReadAllLines(Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "settings.rsp"));
            int standardIndex = Array.IndexOf(partitionOptions, "--std");
            string standard = language == "c" ? "c17" : standardIndex < 0 ? "c++17" : partitionOptions[standardIndex + 1];
            var arguments = new List<string>
                {
                    "--language=" + language, "--std=" + standard, "--target=" + target,
                    "--include-directory=" + Path.Combine(root, "generation", "WinSDK", "inc"),
                };
            string toolsetInclude = Environment.GetEnvironmentVariable("WINHTTP_NATIVE_TOOLSET_INCLUDE");
            Assert.True(!string.IsNullOrEmpty(toolsetInclude) && Directory.Exists(toolsetInclude),
                "Set WINHTTP_NATIVE_TOOLSET_INCLUDE to the pinned MSVC include directory; ambient INCLUDE is not used.");
            arguments.Add("--include-directory=" + toolsetInclude);
            string[] defaultIncludes = new[] { "shared", "um", "winrt", "ucrt" }
                .Select(directory => Path.Combine(includeRoot, directory)).ToArray();
            bool traverse = false;
            foreach (string line in partitionOptions.Select(value => value.Trim()))
            {
                if (line.StartsWith("--", StringComparison.Ordinal))
                    traverse = line == "--traverse";
                else if (traverse && line.StartsWith("<IncludeRoot>", StringComparison.Ordinal))
                {
                    string parent = Path.GetDirectoryName(line.Replace("<IncludeRoot>", includeRoot, StringComparison.Ordinal)
                        .Replace('/', Path.DirectorySeparatorChar));
                    string option = "--include-directory=" + parent;
                    if (!defaultIncludes.Contains(parent, StringComparer.OrdinalIgnoreCase) &&
                        !arguments.Contains(option, StringComparer.OrdinalIgnoreCase))
                        arguments.Add(option);
                }
            }
            arguments.AddRange(defaultIncludes.Select(directory => "--include-directory=" + directory));
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
            const string anonymousLocationPattern = @"\((?:anonymous|unnamed)(?: (?:struct|union|enum))? at (?<location>[^)]+:\d+:\d+)\)";
            var anonymous = new Dictionary<string, string>(StringComparer.Ordinal);
            var ordinals = new Dictionary<string, int>(StringComparer.Ordinal);
            Walk(unit.Cursor, "");
            return result.Select(DeclarationIdentity)
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();

            string DeclarationIdentity(string value) => Regex.Replace(value, anonymousLocationPattern,
                match => anonymous[match.Groups["location"].Value.Replace('\\', '/')]);

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
                    if (cursor.IsAnonymousRecordDecl || name.Length == 0 || name.StartsWith("(", StringComparison.Ordinal) ||
                        Regex.IsMatch(Text(cursor.Type.Spelling), anonymousLocationPattern))
                    {
                        ordinals.TryGetValue(header, out int ordinal);
                        ordinals[header] = ordinal + 1;
                        anonymous[file.ToString().Replace('\\', '/') + ":" + line + ":" + column] = header + ":anonymous#" + ordinal;
                    }
                    childOwner = owner + name + "::";
                }
                else if (includeCallableOwners && kind is CX_DeclKind.CX_DeclKind_Function or CX_DeclKind.CX_DeclKind_CXXMethod)
                    childOwner = owner + name + "::";
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
                        {
                            rawSalAnnotations?.Add(owner + name + "|" + value);
                            salAnnotations?.Add(DeclarationIdentity(owner + name) + "|" + value);
                        }
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
        public NativeMigrationTheoryAttribute(string additionalFixture = null)
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS") == null)
                Skip = "Set WINHTTP_PREPARED_HEADERS to the pinned private prepared-header tree.";
            else if (additionalFixture != null && Environment.GetEnvironmentVariable(additionalFixture) == null)
                Skip = "Set " + additionalFixture + " to the pinned private prepared-header tree.";
        }
    }
}
