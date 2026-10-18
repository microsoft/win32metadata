using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class BulkIdlAnnotationMigrationTests
    {
        private readonly ITestOutputHelper output;

        public BulkIdlAnnotationMigrationTests(ITestOutputHelper output) => this.output = output;

        [Theory]
        [InlineData("\r\n", false)]
        [InlineData("\n", true)]
        public void AuthoringPreservesOriginalBytesAttributesGuardsAndEncoding(string newline, bool bom)
        {
            string text = "// Copyright sample " + (char)0xA9 + "\n" +
                "#ifndef SAMPLE_IDL\n#define SAMPLE_IDL\n" +
                "#define UNUSED_DECLARATION interface IMacroBody : IUnknown {};\n" +
                "// interface IComment : IUnknown { };\n" +
                "cpp_quote(\"interface IQuoted : IUnknown { };\")\n" +
                "interface IMigrated;\n" +
                "[object, uuid(00000000-0000-0000-0000-000000000001)]\n" +
                "interface IMigrated : IUnknown\n{\n" +
                "    HRESULT Read([out, retval] long* result);\n};\n#endif\n";
            byte[] bytes = Encoding.Latin1.GetBytes(text.Replace("\n", newline));
            if (bom)
                bytes = new byte[] { 239, 187, 191 }.Concat(bytes).ToArray();
            using var fixture = new Fixture(bytes);
            fixture.WriteMap(new[]
            {
                Floor("IMigrated"), Floor("IComment"), Floor("IQuoted"), Floor("IOnlyForward"), Floor("IMacroBody"),
            });
            var result = fixture.Run();
            Assert.Equal(0, result.ExitCode);
            Assert.Equal(bytes, File.ReadAllBytes(fixture.Source));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(1, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(4, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.Single(report.RootElement.GetProperty("candidateGeneratedHeaders").EnumerateArray());
            byte[] authored = File.ReadAllBytes(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            string decoded = Encoding.Latin1.GetString(authored);
            Assert.Contains("_Win32_AnnotateInterface_(IMigrated, _Win32_SupportedOS_Windows7_)" + newline +
                "[object, uuid", decoded);
            decoded = decoded.Replace("#include <sal.h>" + newline, "", StringComparison.Ordinal)
                .Replace("_Win32_AnnotateInterface_(IMigrated, _Win32_SupportedOS_Windows7_)" + newline, "", StringComparison.Ordinal);
            Assert.Equal(bytes, Encoding.Latin1.GetBytes(decoded));
            var application = Fixture.Command("git", fixture.RepositoryRoot, "apply", "--unsafe-paths", "-p1",
                "--directory=" + fixture.Sdk, "--whitespace=error-all", "--check", "--",
                Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
            Assert.True(application.ExitCode == 0, application.Error);
        }

        [Fact]
        public void AmbiguousDefinitionsUnknownVocabularyAndNonInterfaceFactsRemainExactLegacyDebt()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(
                "#if FIRST\ninterface IDuplicate : IUnknown {};\n#else\ninterface IDuplicate : IUnknown {};\n#endif\n" +
                "interface IUnknownFloor : IUnknown {};\ninterface IMethod : IUnknown {};\n"));
            object[] facts =
            {
                Floor("IDuplicate"), Floor("IUnknownFloor", "windows11.0"),
                new { category = "setLastError", symbol = "IMethod", value = "IMethod" },
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.Equal(0, result.ExitCode);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(3, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            var dispositions = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions");
            Assert.All(dispositions.EnumerateArray(), item => Assert.Equal("retained-legacy", item.GetProperty("disposition").GetString()));
            Assert.Equal(JsonSerializer.Serialize(facts), JsonSerializer.Serialize(
                dispositions.EnumerateArray().Select(item => item.GetProperty("fact")).ToArray()));
        }

        [Theory]
        [InlineData("duplicate", "Duplicate fact identity")]
        [InlineData("stale", "preimage mismatch")]
        [InlineData("escape", "escapes the SDK")]
        [InlineData("header", "shipped IDL")]
        [InlineData("utf16", "encoding-aware owner review")]
        public void InvalidOrStaleOwnerInputsFailBeforePublication(string mutation, string diagnostic)
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};\n"));
            string original = mutation == "escape" ? @"..\outside.idl" : mutation == "header" ? @"um\sample.h" : @"um\sample.idl";
            if (mutation == "utf16")
                File.WriteAllBytes(fixture.Source, Encoding.Unicode.GetPreamble().Concat(Encoding.Unicode.GetBytes("interface IMigrated : IUnknown {};")).ToArray());
            fixture.WriteMap(mutation == "duplicate" ? new[] { Floor("IMigrated"), Floor("IMigrated") } : new[] { Floor("IMigrated") },
                original, stale: mutation == "stale");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(diagnostic, result.Error);
            Assert.False(Directory.Exists(result.OutputDirectory));
        }

        [Fact]
        public void AuthoringIsRepeatableAndNeverOverwritesAPublishedResult()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};\r\n"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            var first = fixture.Run();
            var second = fixture.Run();
            Assert.Equal(0, first.ExitCode);
            Assert.Equal(0, second.ExitCode);
            foreach (string relative in new[] { @"source\um\sample.idl", @"patches\um\sample.idl.patch", "report.json" })
                Assert.Equal(File.ReadAllBytes(Path.Combine(first.OutputDirectory, relative)), File.ReadAllBytes(Path.Combine(second.OutputDirectory, relative)));
            var overwrite = fixture.Run(first.OutputDirectory);
            Assert.NotEqual(0, overwrite.ExitCode);
            Assert.Contains("do not overwrite", overwrite.Error);
        }

        [Fact]
        public void MultipleSourceOffsetsAreAppliedDescendingRatherThanInInventoryOrder()
        {
            const string source = "// before first\r\n[object]\r\ninterface IZFirst : IUnknown {};\r\n" +
                "// before second\r\n[object]\r\ninterface IASecond : IUnknown {};\r\n" +
                "// before third\r\n[object]\r\ninterface IMThird : IUnknown {};\r\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { Floor("IASecond"), Floor("IMThird"), Floor("IZFirst") });
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            foreach (string name in new[] { "IZFirst", "IASecond", "IMThird" })
            {
                string carrier = "_Win32_AnnotateInterface_(" + name + ", _Win32_SupportedOS_Windows7_)\r\n";
                Assert.Contains(carrier + "[object]\r\ninterface " + name, authored);
                authored = authored.Replace(carrier, "", StringComparison.Ordinal);
            }
            Assert.Equal(source, authored.Replace("#include <sal.h>\r\n", "", StringComparison.Ordinal));
            string patch = File.ReadAllText(Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
            Assert.DoesNotContain("-interface", patch);
            Assert.DoesNotContain("-//", patch);
        }

        [Fact]
        public void CarriersPrecedeNativeMacroGeneratedAttributeLists()
        {
            const string source = "// native attributes\r\n" +
                "#define NATIVE_INTERFACE(id, description) \\\r\n" +
                "    [object, uuid(id), helpstring(description), local]\r\n" +
                "NATIVE_INTERFACE(00000000-0000-0000-0000-000000000001,\r\n" +
                "    \"native interface\")\r\n" +
                "interface IMigrated : IUnknown {};\r\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            const string carrier = "_Win32_AnnotateInterface_(IMigrated, _Win32_SupportedOS_Windows7_)\r\n";
            Assert.Contains(carrier + "NATIVE_INTERFACE(00000000", authored);
            Assert.Equal(source, authored.Replace(carrier, "", StringComparison.Ordinal)
                .Replace("#include <sal.h>\r\n", "", StringComparison.Ordinal));
        }

        [Fact]
        public void NativeControlsAccountForOneExistingInterfaceTypedefCarrier()
        {
            string[] original = { "record IExample 8 8", "typedef IExample IExample" };
            string[] prepared = { "record IExample 8 8", "typedef IExample IExample", "typedef IExample IExample" };
            Assert.Equal(original, WinHttpNativeControlTests.NormalizeInterfaceCarrierTypedefs(
                original, prepared, new[] { "IExample|SupportedOSPlatform(\"windows6.1\")" }));
        }

        [Theory]
        [InlineData("record IExample 16 8", "typedef IExample IExample", "typedef IExample IExample")]
        [InlineData("record IExample 8 8", "typedef IExample int", "typedef IExample int")]
        [InlineData("record IExample 8 8", "typedef IExample IExample", "typedef IExample IExample", "typedef IExample IExample")]
        [InlineData("record IExample 8 8", "typedef IExample IExample", "typedef INew INew")]
        public void NativeControlsRetainLayoutTypeAndUnexpectedDeclarationDifferences(params string[] prepared)
        {
            string[] original = { "record IExample 8 8", "typedef IExample IExample" };
            Assert.NotEqual<string>(original, WinHttpNativeControlTests.NormalizeInterfaceCarrierTypedefs(
                original, prepared, new[] { "IExample|SupportedOSPlatform(\"windows6.1\")" }));
        }

        [NativeMigrationTheory("WINHTTP_PRISTINE_PREPARED_HEADERS")]
        [MemberData(nameof(OriginalIdlNativeSamples))]
        public void OriginalIdlBatchKeepsNativeSurfaceWithExactInterfaceFloors(
            string partition, string header, string architecture, string target, string language,
            bool cInterface, bool enabled, string[] expected) =>
            new WinHttpNativeControlTests(this.output).OriginalIdlBatchPreservesNativeAbiAndSalWithExactMetadata(
                partition, header, architecture, target, language, cInterface, enabled, expected);

        public static IEnumerable<object[]> OriginalIdlNativeSamples()
        {
            var owners = new[]
            {
                ("Wmi", "wbemcli.h", new[]
                {
                    "IEnumWbemClassObject", "IMofCompiler", "IUnsecuredApartment", "IWbemBackupRestore",
                    "IWbemBackupRestoreEx", "IWbemCallResult", "IWbemClassObject", "IWbemConfigureRefresher",
                    "IWbemContext", "IWbemHiPerfEnum", "IWbemLocator", "IWbemObjectAccess", "IWbemObjectSink",
                    "IWbemObjectSinkEx", "IWbemObjectTextSrc", "IWbemQualifierSet", "IWbemRefresher",
                    "IWbemServices", "IWbemShutdown", "IWbemStatusCodeText",
                }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").Append(
                    "IWbemUnsecuredApartment|SupportedOSPlatform(\"windowsserver2008\")").ToArray()),
                ("Mbn", "mbnapi.h", new[]
                {
                    "IMbnConnection", "IMbnConnectionContext", "IMbnConnectionContextEvents",
                    "IMbnConnectionEvents", "IMbnConnectionManager", "IMbnConnectionManagerEvents",
                    "IMbnConnectionProfile", "IMbnConnectionProfileEvents", "IMbnConnectionProfileManager",
                    "IMbnConnectionProfileManagerEvents", "IMbnDeviceService", "IMbnDeviceServicesContext",
                    "IMbnDeviceServicesEvents", "IMbnDeviceServicesManager", "IMbnInterface",
                    "IMbnInterfaceEvents", "IMbnInterfaceManager", "IMbnInterfaceManagerEvents",
                    "IMbnMultiCarrier", "IMbnMultiCarrierEvents", "IMbnPin", "IMbnPinEvents", "IMbnPinManager",
                    "IMbnPinManagerEvents", "IMbnRadio", "IMbnRadioEvents", "IMbnRegistration",
                    "IMbnRegistrationEvents", "IMbnServiceActivation", "IMbnServiceActivationEvents",
                    "IMbnSignal", "IMbnSignalEvents", "IMbnSms", "IMbnSmsConfiguration", "IMbnSmsEvents",
                    "IMbnSmsReadMsgPdu", "IMbnSmsReadMsgTextCdma", "IMbnSubscriberInformation",
                    "IMbnVendorSpecificEvents", "IMbnVendorSpecificOperation",
                }.Select(name => name + "|SupportedOSPlatform(\"" + (name is
                    "IMbnDeviceService" or "IMbnDeviceServicesContext" or "IMbnDeviceServicesEvents" or
                    "IMbnDeviceServicesManager" or "IMbnMultiCarrier" or "IMbnMultiCarrierEvents"
                        ? "windows8.0" : "windows6.1") + "\")").ToArray()),
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
                                mode.Item1 == "c++" ? owner.Item3 : Array.Empty<string>(),
                            };
        }

        private static object Floor(string symbol, string version = "windows6.1") =>
            new { category = "supportedOS", symbol, value = symbol + "=SupportedOSPlatform(\"" + version + "\")" };

        private sealed class Fixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataIdl-" + Guid.NewGuid().ToString("N"));
            private int runs;

            public Fixture(byte[] source)
            {
                this.Sdk = Path.Combine(this.directory, "SDK with spaces");
                Directory.CreateDirectory(Path.Combine(this.Sdk, "um"));
                this.Source = Path.Combine(this.Sdk, "um", "sample.idl");
                File.WriteAllBytes(this.Source, source);
            }

            public string RepositoryRoot => WinHttpMigrationTests.RepositoryRoot;
            public string Sdk { get; }
            public string Source { get; }

            public void WriteMap(object[] facts, string original = @"um\sample.idl", bool stale = false)
            {
                string hash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(this.Source)));
                File.WriteAllText(Path.Combine(this.directory, "owners.json"), JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    owners = new[] { new { original, sourceSha256 = stale ? new string('0', 64) : hash,
                        generatedHeaders = new[] { @"um\sample.h" }, partitionCandidates = new[] { "Sample" }, facts } },
                }));
            }

            public (int ExitCode, string Error, string OutputDirectory) Run(string output = null)
            {
                output ??= Path.Combine(this.directory, "result-" + this.runs++);
                var result = Command("pwsh", this.RepositoryRoot, "-NoProfile", "-File",
                    Path.Combine(this.RepositoryRoot, "scripts", "Convert-SdkIdlAnnotations.ps1"),
                    "-InputMap", Path.Combine(this.directory, "owners.json"), "-SdkIncludeRoot", this.Sdk, "-OutputDirectory", output);
                return (result.ExitCode, result.Error, output);
            }

            public static (int ExitCode, string Error) Command(string executable, string workingDirectory, params string[] arguments)
            {
                using var process = new Process { StartInfo = new ProcessStartInfo(executable)
                {
                    WorkingDirectory = workingDirectory, UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true,
                } };
                foreach (string argument in arguments)
                    process.StartInfo.ArgumentList.Add(argument);
                process.Start();
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                return (process.ExitCode, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
            }

            public void Dispose() => Directory.Delete(this.directory, recursive: true);
        }
    }
}
