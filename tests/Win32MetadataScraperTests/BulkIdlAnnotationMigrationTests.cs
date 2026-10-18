using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
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

        [Theory]
        [InlineData("\r\n")]
        [InlineData("\n")]
        public void RecipeAdmissionRequiresRealNormalParserActivation(string newline)
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            string settings = Path.Combine(fixture.Project, "Partitions", "Sample", "settings.rsp");
            string original = "--namespace\nTest\n--traverse\n<IncludeRoot>/um/sample.h\n--config\ngenerate-compatible-codegen\n"
                .Replace("\n", newline, StringComparison.Ordinal);
            File.WriteAllText(settings, original);
            string untouched = Path.Combine(fixture.Project, "Partitions", "Other", "settings.rsp");
            Directory.CreateDirectory(Path.GetDirectoryName(untouched));
            File.WriteAllText(untouched, "--namespace\nOther\n");
            byte[] untouchedBytes = File.ReadAllBytes(untouched);
            byte[] source = File.ReadAllBytes(fixture.Source);
            var proposal = fixture.Run();
            Assert.True(proposal.ExitCode == 0, proposal.Error);
            using (var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(proposal.OutputDirectory, "report.json"))))
                Assert.False(report.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            Assert.Equal(original, File.ReadAllText(settings));
            var applied = fixture.Run(apply: true);
            Assert.True(applied.ExitCode == 0, applied.Error);
            using (var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(applied.OutputDirectory, "report.json"))))
                Assert.True(report.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            Assert.Equal(original + "--config" + newline + "parse-win32-annotations" + newline, File.ReadAllText(settings));
            byte[] activated = File.ReadAllBytes(settings);
            Assert.True(fixture.Run(apply: true).ExitCode == 0);
            Assert.Equal(activated, File.ReadAllBytes(settings));
            Assert.Equal(untouchedBytes, File.ReadAllBytes(untouched));
            Assert.Equal(source, File.ReadAllBytes(fixture.Source));
        }

        [Fact]
        public void ApplyRejectsAnUnconfiguredNormalOwnerWithoutCreatingSpeculativeSettings()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            string settings = Path.Combine(fixture.Project, "Partitions", "Sample", "settings.rsp");
            File.Delete(settings);
            var result = fixture.Run(apply: true);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("actual configured normal traverse owners", result.Error);
            Assert.False(File.Exists(settings));
            Assert.False(Directory.Exists(result.OutputDirectory));
        }

        [MigrationTheory("WIN32METADATA_WMI_GENERATED_SOURCE", "WIN32METADATA_WMI_DISABLED_SOURCE")]
        [InlineData("IEnumWbemClassObject", "windows6.0.6000")]
        public void ActualNormalWmiSourceProjectsTheOwnedFloorWithoutLegacyFallback(string target, string floor)
        {
            string source = Environment.GetEnvironmentVariable("WIN32METADATA_WMI_GENERATED_SOURCE");
            string disabled = Environment.GetEnvironmentVariable("WIN32METADATA_WMI_DISABLED_SOURCE");
            Assert.True(!string.IsNullOrEmpty(disabled) && File.Exists(disabled), "Supply the actual normal disabled-parser control.");
            Assert.Empty(Floors(disabled));
            Assert.Equal(new[] { floor }, Floors(source));
            Assert.DoesNotContain(target + "=SupportedOSPlatform(\"" + floor + "\")",
                File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "supportedOS.rsp")));
            string obj = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(source)));
            string settings = File.ReadAllText(Path.Combine(obj, "scratch", "common", "Wmi.settings.rsp"));
            Assert.Contains("parse-win32-annotations", settings);
            Assert.DoesNotContain("--nativeFieldArrayInfo", settings);

            string[] Floors(string path)
            {
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path));
                var declaration = Assert.Single(tree.GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>()
                    .Where(node => node.Identifier.ValueText == target));
                return declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => attribute.Name.ToString() ==
                        "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform")
                    .Select(attribute => Assert.IsType<LiteralExpressionSyntax>(
                        Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText).ToArray();
            }
        }

        [MigrationTheory("WIN32METADATA_CLU_GENERATED_SOURCE")]
        [InlineData("MsCs", "cluadmex.h")]
        public void ActualNormalCluSourceProjectsAllOwnedFloorsWithoutLegacyFallback(string partition, string header)
        {
            string source = Environment.GetEnvironmentVariable("WIN32METADATA_CLU_GENERATED_SOURCE");
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(source));
            var declarations = tree.GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>().ToArray();
            string[] expected = (string[])OriginalIdlNativeSamples().First(row =>
                (string)row[0] == partition && (string)row[1] == header && (string)row[4] == "c++")[7];
            Assert.Equal(17, expected.Length);
            string[] legacy = File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "supportedOS.rsp"));
            foreach (string fact in expected)
            {
                string[] parts = fact.Split('|');
                var declaration = Assert.Single(declarations.Where(node => node.Identifier.ValueText == parts[0]));
                var attribute = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(value => value.Name.ToString() ==
                        "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform"));
                string floor = Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                Assert.Equal(parts[1], "SupportedOSPlatform(\"" + floor + "\")");
                Assert.DoesNotContain(parts[0] + "=" + parts[1], legacy);
            }
            string obj = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(source)));
            string settings = File.ReadAllText(Path.Combine(obj, "scratch", "common", partition + ".settings.rsp"));
            Assert.Contains("parse-win32-annotations", settings);
            Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
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
                ("Media.DShow", "videoacc.h", new[]
                {
                    "IAMVideoAccelerator|SupportedOSPlatform(\"windows5.0\")",
                    "IAMVideoAcceleratorNotify|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("VSS", "vss.h", new[]
                {
                    "IVssAsync|SupportedOSPlatform(\"windows5.1.2600\")",
                    "IVssEnumObject|SupportedOSPlatform(\"windows5.1.2600\")",
                }),
                ("Xps", "xpsobjectmodel_2.h", new[]
                {
                    "IXpsDocumentPackageTarget3D|SupportedOSPlatform(\"windows8.1\")",
                    "IXpsOMPackageWriter3D|SupportedOSPlatform(\"windows8.1\")",
                }),
                ("Audio.Endpoints", "audioendpoints.h", new[]
                {
                    "IAudioEndpointFormatControl|SupportedOSPlatform(\"windows6.1\")",
                }),
                ("Bits", "bits1_5.h", new[]
                {
                    "IBackgroundCopyJob2|SupportedOSPlatform(\"windows6.0.6000\")",
                }),
                ("Certificates", "certmod.h", new[]
                {
                    "ICertManageModule|SupportedOSPlatform(\"windowsserver2003\")",
                }),
                ("Tsf", "ctfspui.h", new[]
                {
                    "ITfSpeechUIServer|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("Com", "ctxtcall.h", new[]
                {
                    "IContextCallback|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("Direct3D11", "d3d11_4.h", new[]
                {
                    "ID3D11VideoContext2|SupportedOSPlatform(\"windows10.0.10240\")",
                }),
                ("DirectComp", "dcompanimation.h", new[]
                {
                    "IDCompositionAnimation|SupportedOSPlatform(\"windows8.0\")",
                }),
                ("Media.DShow", "dmodshow.h", new[]
                {
                    "IDMOWrapperFilter|SupportedOSPlatform(\"windows5.1.2600\")",
                }),
                ("WinProg", "editionupgradehelper.h", new[]
                {
                    "IEditionUpgradeHelper|SupportedOSPlatform(\"windows10.0.10240\")",
                }),
                ("IndexSrv", "filter.h", new[]
                {
                    "IFilter|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("MsCs", "cluadmex.h", new[]
                {
                    "IGetClusterDataInfo", "IGetClusterGroupInfo", "IGetClusterNetInterfaceInfo",
                    "IGetClusterNetworkInfo", "IGetClusterNodeInfo", "IGetClusterObjectInfo",
                    "IGetClusterResourceInfo", "IGetClusterUIInfo", "IWCContextMenuCallback",
                    "IWCWizard97Callback", "IWCWizardCallback", "IWEExtendContextMenu",
                    "IWEExtendWizard", "IWEExtendWizard97", "IWEInvokeCommand",
                }.Select(name => name + "|SupportedOSPlatform(\"windowsserver2003\")").Concat(new[]
                {
                    "IWCPropertySheetCallback", "IWEExtendPropertySheet",
                }.Select(name => name + "|SupportedOSPlatform(\"windowsserver2008\")")).ToArray()),
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

        [NativeMigrationTheory("BULK_SYSTEM_IDL_MIGRATION_ROOT")]
        [MemberData(nameof(SystemOriginalIdlNativeSamples))]
        public void SystemOriginalIdlBatchKeepsNativeSurfaceWithExactInterfaceFloors(
            string partition, string header, string architecture, string target, bool enabled, string[] expected) =>
            new WinHttpNativeControlTests(this.output).OriginalIdlBatchPreservesNativeAbiAndSalWithExactMetadata(
                partition, header, architecture, target, "c++", false, enabled, expected);

        public static IEnumerable<object[]> SystemOriginalIdlNativeSamples()
        {
            string root = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_MIGRATION_ROOT");
            if (string.IsNullOrEmpty(root))
            {
                yield return new object[] { "", "", "x64", "x86_64-pc-windows-msvc", true, Array.Empty<string>() };
                yield break;
            }

            string results = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_COMPILE_RESULTS");
            if (string.IsNullOrEmpty(results))
                throw new InvalidOperationException("A real system IDL fixture requires its actual MIDL compile results.");
            using var compiled = JsonDocument.Parse(File.ReadAllText(results));
            var successful = compiled.RootElement.EnumerateArray()
                .Where(result => result.GetProperty("success").GetBoolean())
                .ToDictionary(result => result.GetProperty("original").GetString(),
                    result => result.GetProperty("generatedHeader").GetString(), StringComparer.OrdinalIgnoreCase);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "report.json")));
            foreach (var owner in report.RootElement.GetProperty("owners").EnumerateArray())
            {
                string original = owner.GetProperty("original").GetString();
                if (!successful.TryGetValue(original, out string header))
                    continue;
                string partition = owner.GetProperty("partitionCandidates").EnumerateArray()
                    .Select(value => value.GetString()).First();
                string[] expected = owner.GetProperty("dispositions").EnumerateArray()
                    .Where(row => row.GetProperty("disposition").GetString() == "authored-original-idl")
                    .Select(row => row.GetProperty("fact"))
                    .Select(fact =>
                    {
                        string value = fact.GetProperty("value").GetString();
                        return fact.GetProperty("symbol").GetString() + "|" + value[(value.IndexOf('=') + 1)..];
                    }).ToArray();
                if (expected.Length == 0)
                    throw new InvalidOperationException($"No authored semantic facts for {original}.");
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                {
                    yield return new object[]
                    {
                        partition, Path.GetFileName(header), architecture.Item1, architecture.Item2, true, expected,
                    };
                    if (architecture.Item1 == "x64")
                        yield return new object[]
                        {
                            partition, Path.GetFileName(header), architecture.Item1, architecture.Item2, false, expected,
                        };
                }
            }
        }

        [NativeMigrationTheory("BULK_SYSTEM_IDL_BINDINGS")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SystemOriginalIdlProjectionContainsExactInterfaceFloors(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_MIGRATION_ROOT");
            string generated = Path.Combine(Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_BINDINGS"), architecture);
            using var compiled = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_COMPILE_RESULTS")));
            var successful = compiled.RootElement.EnumerateArray()
                .Where(result => result.GetProperty("success").GetBoolean())
                .Select(result => result.GetProperty("original").GetString()).ToHashSet(StringComparer.OrdinalIgnoreCase);
            using var bindings = JsonDocument.Parse(File.ReadAllText(Path.Combine(generated, "results.json")));
            var outputs = bindings.RootElement.EnumerateArray()
                .ToDictionary(result => result.GetProperty("original").GetString(), StringComparer.OrdinalIgnoreCase);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "report.json")));
            int checkedFacts = 0;
            foreach (var owner in report.RootElement.GetProperty("owners").EnumerateArray())
            {
                string original = owner.GetProperty("original").GetString();
                if (!successful.Contains(original))
                    continue;
                Assert.True(outputs.TryGetValue(original, out var result), $"Missing actual binding output for {original}.");
                Assert.True(result.GetProperty("success").GetBoolean(), $"Binding generation failed for {original}.");
                var declarations = CSharpSyntaxTree.ParseText(File.ReadAllText(result.GetProperty("generatedSource").GetString()))
                    .GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>()
                    .ToLookup(declaration => declaration.Identifier.ValueText, StringComparer.Ordinal);
                foreach (var row in owner.GetProperty("dispositions").EnumerateArray()
                    .Where(row => row.GetProperty("disposition").GetString() == "authored-original-idl"))
                {
                    var fact = row.GetProperty("fact");
                    string symbol = fact.GetProperty("symbol").GetString();
                    var declaration = Assert.Single(declarations[symbol]);
                    string expected = Regex.Match(fact.GetProperty("value").GetString(),
                        "SupportedOSPlatform\\(\"([^\"]+)\"\\)").Groups[1].Value;
                    string[] actual = declaration.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(attribute => attribute.Name.ToString().Split('.').Last()
                            is "SupportedOSPlatform" or "SupportedOSPlatformAttribute")
                        .Select(attribute => Assert.IsType<LiteralExpressionSyntax>(
                            Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText).ToArray();
                    Assert.True(actual.SequenceEqual(new[] { expected }),
                        $"{architecture}/{original}/{symbol}: expected '{expected}', actual [{string.Join(", ", actual)}].");
                    checkedFacts++;
                }
            }
            Assert.True(checkedFacts > 0, "The readback requires actual projected original-IDL interface facts.");
            this.output.WriteLine($"{architecture}: {checkedFacts} exact source-authored interface floors in real generated bindings.");
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
                this.Project = Path.Combine(this.directory, "Project");
                Directory.CreateDirectory(Path.Combine(this.Project, "Partitions", "Sample"));
                Directory.CreateDirectory(Path.Combine(this.Project, "patches"));
                File.WriteAllText(Path.Combine(this.Project, "Partitions", "Sample", "main.cpp"), "#include <sample.h>\n");
                File.WriteAllText(Path.Combine(this.Project, "Partitions", "Sample", "settings.rsp"),
                    "--namespace\nTest\n--traverse\n<IncludeRoot>/um/sample.h\n");
                File.WriteAllText(Path.Combine(this.Project, "patches", "SdkHeaders.json"), JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    partitions = new[] { "Sample" },
                    midl = new { outputs = new[] { new { source = @"um\sample.idl", path = @"um\sample.h" } } },
                }));
            }

            public string RepositoryRoot => WinHttpMigrationTests.RepositoryRoot;
            public string Sdk { get; }
            public string Source { get; }
            public string Project { get; }

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

            public (int ExitCode, string Error, string OutputDirectory) Run(string output = null, bool apply = false)
            {
                output ??= Path.Combine(this.directory, "result-" + this.runs++);
                var arguments = new List<string> { "-NoProfile", "-File",
                    Path.Combine(this.RepositoryRoot, "scripts", "Convert-SdkIdlAnnotations.ps1"),
                    "-InputMap", Path.Combine(this.directory, "owners.json"), "-SdkIncludeRoot", this.Sdk,
                    "-OutputDirectory", output, "-SdkProjectRoot", this.Project };
                if (apply)
                    arguments.Add("-Apply");
                var result = Command("pwsh", this.RepositoryRoot, arguments.ToArray());
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
