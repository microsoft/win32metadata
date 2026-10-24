using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class HeaderEnumOwnershipRepairTests
    {
        private static readonly (string Partition, string[] Headers)[] NativeOwners =
        {
            ("WinProg", new[] { "winnt.h" }),
            ("Rpc", new[] { "rpcdce.h" }),
            ("Gdi", new[] { "wingdi.h" }),
            ("MenuRc", new[] { "winuser.h" }),
            ("Controls", new[] { "commctrl.h" }),
            ("Controls.RichEdit", new[] { "richedit.h" }),
            ("SystemInformation", new[] { "sysinfoapi.h" }),
            ("Tsf", new[] { "ctfutb.h", "msctf.h" }),
            ("ComOle", new[] { "wtypes.h", "ocidl.h", "oleidl.h" }),
            ("Shell", new[] { "shellapi.h", "shlobj_core.h" }),
        };

        [HeaderMigrationDataTheory]
        [InlineData("BOOL")]
        [InlineData("BOOLEAN")]
        [InlineData("CHAR")]
        [InlineData("HANDLE")]
        [InlineData("HRESULT")]
        [InlineData("NTSTATUS")]
        [InlineData("PSTR")]
        [InlineData("PWSTR")]
        public void SharedNativeTypedefsKeepOneFoundationIdentity(string name)
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "requiredNamespacesForNames.rsp");
            Assert.Equal(name + "=Windows.Win32.Foundation",
                Assert.Single(File.ReadAllLines(path).Where(line => line.StartsWith(name + "=", StringComparison.Ordinal))));
        }

        [HeaderMigrationDataTheory]
        [InlineData("HPROPSHEETPAGE", "Windows.Win32.UI.Controls")]
        [InlineData("SC_HANDLE", "Windows.Win32.System.Services")]
        public void SharedNativeHandlesKeepOneEstablishedNamespace(string name, string expectedNamespace)
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "requiredNamespacesForNames.rsp");
            Assert.Equal(name + "=" + expectedNamespace,
                Assert.Single(File.ReadAllLines(path).Where(line => line.StartsWith(name + "=", StringComparison.Ordinal))));
        }

        [HeaderMigrationDataFact]
        public void NativeNotificationBaseIsNotExcludedAfterManualProviderRetirement()
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string settings = Path.Combine(root, "generation", "WinSDK", "ConstantsScraper.settings.rsp");
            Assert.DoesNotContain("NM_FIRST", File.ReadAllLines(settings).Select(line => line.Trim()));
            Assert.False(File.Exists(Path.Combine(root, "generation", "WinSDK", "manual", "Controls.cs")));
        }

        [HeaderMigrationDataFact]
        public void SharedScraperImportsMatchTheSelectedSdkNamespaceSet()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "scraper.header.txt");
            AssertSelectedSdkImports(File.ReadAllLines(path));
        }

        [HeaderMigrationDataFact]
        public void ProcessAffinityForwardDeclarationKeepsItsNativeDwordStorage()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", "processthreadsapi.h.patch");
            string added = string.Join("\n", File.ReadAllLines(path).Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            Assert.Contains("typedef unsigned long PROCESS_AFFINITY_AUTO_UPDATE_FLAGS;", added);
            Assert.Contains("DWORD PROCESS_AFFINITY_AUTO_UPDATE_FLAGS;", added);
            Assert.DoesNotContain("typedef unsigned int PROCESS_AFFINITY_AUTO_UPDATE_FLAGS;", added);
        }

        [HeaderMigrationDataFact]
        public void VariantDiscriminatorAnnotatesTheActualIdlField()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", "oaidl.idl.patch");
            string patch = File.ReadAllText(path);
            Assert.Contains("+            [annotation(\"_Win32_AssociatedEnum_(VARENUM)\")] VARTYPE vt;", patch);
            Assert.DoesNotContain("field ::VARIANT::vt =>", patch);
        }

        [HeaderMigrationDataFact]
        public void X64HypervisorEmulationIsIncludedOnlyWithItsNativeArchitectureDefinitions()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "Partitions", "Hypervisor", "main.cpp");
            Assert.Matches(@"#if defined\(_AMD64_\)\s+#include <WinHvEmulation\.h>\s+#endif",
                File.ReadAllText(path));
        }

        [HeaderMigrationDataFact]
        public void TreeViewUsesAnOrderedLiteralCarrierWithoutInventingNativeConstants()
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string patch = File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "patches", "um", "commctrl.h.patch"));
            string added = string.Join("\n", patch.Split('\n').Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            Assert.Matches(
                "\"Enum\\(I_ZERO, I_ONE_OR_MORE, I_CHILDRENCALLBACK, I_CHILDRENAUTO\\)\",\\s*" +
                "0, 1, I_CHILDRENCALLBACK, I_CHILDRENAUTO\\)\\s+int TVITEMEXW_CHILDREN;", added);
            Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+(?:I_ZERO|I_ONE_OR_MORE)\b", added);
            Assert.Equal(4, Regex.Matches(added,
                @"_Win32_AssociatedEnum_\(TVITEMEXW_CHILDREN\)\s+int\s+cChildren\s*;").Count);
            using var retired = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "enums.json")));
            Assert.Empty(retired.RootElement.GetProperty("items").EnumerateArray());
            AssertInheritedAutoTypes(ReadAutoTypes(File.ReadAllText(Path.Combine(root, "generation", "WinSDK", "autoTypes.json"))));
        }

        [Fact]
        public void RetainedHeaderMetadataSnapshotKeepsTheFullInheritedRecordsAndSelectedSdkImports()
        {
            var snapshot = RetainedHeaderMetadata();
            AssertInheritedAutoTypes((JArray)snapshot["retained"]);
            AssertSelectedSdkImports(File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "scraper.header.txt")));
        }

        [Theory]
        [InlineData("empty")]
        [InlineData("missing")]
        [InlineData("extra")]
        [InlineData("retired")]
        [InlineData("duplicate")]
        [InlineData("namespace")]
        [InlineData("storage")]
        [InlineData("invalid")]
        [InlineData("nativeTypedef")]
        [InlineData("unknown")]
        public void RetainedHeaderMetadataRejectsMissingChangedOrRetiredRecords(string mutation)
        {
            var snapshot = RetainedHeaderMetadata();
            var records = (JArray)snapshot["retained"].DeepClone();
            switch (mutation)
            {
                case "empty": records.Clear(); break;
                case "missing": records.RemoveAt(0); break;
                case "extra": records.Add(new JObject { ["Name"] = "Unexpected", ["ValueType"] = "DECLARE_HANDLE" }); break;
                case "retired": records.Add(new JObject { ["Name"] = (string)snapshot["retired"][0], ["ValueType"] = "DECLARE_HANDLE" }); break;
                case "duplicate": records.Add(records[0].DeepClone()); break;
                case "namespace": records[0]["Namespace"] = "Wrong.Scope"; break;
                case "storage": records[0]["ValueType"] = "DECLARE_HANDLE"; break;
                case "invalid": records[0]["InvalidHandleValues"] = new JArray(-1); break;
                case "nativeTypedef": records[0]["NativeTypedef"] = false; break;
                case "unknown": records[0]["UnexpectedFact"] = true; break;
                default: throw new ArgumentOutOfRangeException(nameof(mutation));
            }
            Assert.ThrowsAny<Xunit.Sdk.XunitException>(() => AssertInheritedAutoTypes(records));
        }

        [Fact]
        public void HistoricalInheritedImportSnapshotRemainsPinned()
        {
            var imports = RetainedHeaderMetadata()["imports"];
            Assert.Equal("4a6dd2d5f8fc5bec7a9f093f98a6a3a7fb4bc8ef", (string)imports["blob"]);
            Assert.Equal(257, (int)imports["count"]);
            Assert.Equal("E4F134E519BFC202F103384C9AE0E24EF5DE1782A28889621905C73653390C09",
                (string)imports["sha256"]);
        }

        [Theory]
        [InlineData("missing")]
        [InlineData("duplicate")]
        [InlineData("added")]
        [InlineData("changed")]
        [InlineData("reordered")]
        [InlineData("removed-hlsl")]
        public void SelectedSdkImportsRejectMissingDuplicateChangedReorderedOrRemovedNamespaces(string mutation)
        {
            var imports = File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "scraper.header.txt"))
                .Where(line => Regex.IsMatch(line, @"^using\s+.+;$")).ToList();
            switch (mutation)
            {
                case "missing": imports.RemoveAt(0); break;
                case "duplicate": imports.Add(imports[0]); break;
                case "added": imports.Add("using Unexpected.Namespace;"); break;
                case "changed": imports[0] = "using Unexpected.Namespace;"; break;
                case "reordered": (imports[0], imports[1]) = (imports[1], imports[0]); break;
                case "removed-hlsl": imports.Add("using Windows.Win32.Graphics.Hlsl;"); break;
                default: throw new ArgumentOutOfRangeException(nameof(mutation));
            }
            Assert.ThrowsAny<Xunit.Sdk.XunitException>(() => AssertSelectedSdkImports(imports));
        }

        private static JObject RetainedHeaderMetadata() => JObject.Parse(File.ReadAllText(Path.Combine(
            WinHttpMigrationTests.RepositoryRoot, "tests", "Win32MetadataScraperTests", "RetainedHeaderMetadata.json")));

        private static JArray ReadAutoTypes(string text) => JArray.Parse(text,
            new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });

        private static void AssertSelectedSdkImports(IEnumerable<string> lines)
        {
            string[] imports = lines.Where(line => Regex.IsMatch(line, @"^using\s+.+;$")).ToArray();
            Assert.DoesNotContain("using Windows.Win32.Graphics.Hlsl;", imports);
            Assert.Equal(256, imports.Length);
            Assert.Equal("F2FBE5708B94D81A172AF9EBAB520A168A9D5CEC9F75F8AF31DDEE3378E911CC",
                Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join("\n", imports)))));
        }

        private static void AssertInheritedAutoTypes(JArray records)
        {
            var snapshot = RetainedHeaderMetadata();
            var retained = (JArray)snapshot["retained"];
            string[] retired = snapshot["retired"].Values<string>().ToArray();
            Assert.True(retained.Count == 8, "The inherited snapshot must preserve all eight full records.");
            Assert.True(retired.Length == 436, "The retirement snapshot must retain every exact original identity.");
            Assert.Equal(retired.Length, retired.Distinct(StringComparer.Ordinal).Count());
            Assert.Equal((int)snapshot["originalCount"], retained.Count + retired.Length);
            var expected = retained.ToDictionary(Identity, StringComparer.Ordinal);
            Assert.Empty(expected.Keys.Intersect(retired, StringComparer.Ordinal));
            Assert.Equal(records.Count, records.Select(Identity).Distinct(StringComparer.Ordinal).Count());
            var actual = records.ToDictionary(Identity, StringComparer.Ordinal);
            Assert.Equal(expected.Keys.OrderBy(value => value, StringComparer.Ordinal),
                actual.Keys.OrderBy(value => value, StringComparer.Ordinal));
            foreach (string identity in retired)
                Assert.DoesNotContain(identity, actual.Keys);
            foreach (var record in expected)
                Assert.True(JToken.DeepEquals(record.Value, actual[record.Key]),
                    "Retained native typedef facts changed: " + record.Key);

            static string Identity(JToken record)
            {
                Assert.IsType<JObject>(record);
                string name = (string)record["Name"];
                Assert.False(string.IsNullOrEmpty(name));
                return record["Namespace"] == null ? name : (string)record["Namespace"] + "." + name;
            }
        }

        [Theory]
        [InlineData("unchecked((int)18446744073709551615UL)", -1L)]
        [InlineData("unchecked((int)18446744073709551614UL)", -2L)]
        [InlineData("unchecked((int)-1L)", -1L)]
        public void ActualTreeViewRawLiteralSpellingsPreserveSignedBits(string expression, long expected)
        {
            Assert.Equal(expected, Normalize(RawValue(SyntaxFactory.ParseExpression(expression)), "Int32"));
        }

        [HeaderMigrationDataFact]
        public void PanoseCarriersKeepNativeValuesAndCompleteByteFieldAssociations()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", "wingdi.h.patch");
            string added = string.Join("\n", File.ReadAllLines(path).Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            var fields = new Dictionary<string, string>
            {
                ["bFamilyType"] = "PAN_FAMILY_TYPE",
                ["bSerifStyle"] = "PAN_SERIF_STYLE",
                ["bWeight"] = "PAN_WEIGHT",
                ["bProportion"] = "PAN_PROPORTION",
                ["bContrast"] = "PAN_CONTRAST",
                ["bStrokeVariation"] = "PAN_STROKE_VARIATION",
                ["bArmStyle"] = "PAN_ARM_STYLE",
                ["bLetterform"] = "PAN_LETT_FORM",
                ["bMidline"] = "PAN_MIDLINE",
                ["bXHeight"] = "PAN_XHEIGHT",
            };
            var carriers = Regex.Matches(added,
                @"typedef\s+_WIN32META_ANNOTATION_\(""Enum\(([^""]+)\)"",\s*([^)]+)\)\s+unsigned char (PAN_\w+);");
            Assert.Equal(fields.Count, carriers.Count);
            foreach (Match carrier in carriers)
            {
                string[] labels = carrier.Groups[1].Value.Split(',').Select(value => value.Trim()).ToArray();
                string[] expressions = carrier.Groups[2].Value.Split(',').Select(value => value.Trim()).ToArray();
                Assert.Equal(labels.Length, expressions.Length);
                Assert.Equal("PAN_ANY", expressions[0]);
                Assert.Equal("PAN_NO_FIT", expressions[1]);
                Assert.Equal(labels.Skip(2), expressions.Skip(2));
                Assert.Contains(carrier.Groups[3].Value, fields.Values);
            }
            foreach (var field in fields)
                Assert.Matches(@"_Win32_AssociatedEnum_\(" + field.Value + @"\)\s+BYTE\s+" + field.Key + ";", added);
            Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+PAN_\w+_(?:ANY|NO_FIT)\b", added);
            Assert.Equal(2, Regex.Matches(added, @"_Win32_AssociatedEnum_\(FONT_CLIP_PRECISION\)\s+BYTE\s+lfClipPrecision;").Count);
            Assert.Contains("\"FlagsEnum(CLIP_DFA_OVERRIDE)\",\n    CLIP_DFA_DISABLE", added.Replace("\r\n", "\n"));
            Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+CLIP_DFA_OVERRIDE\b", added);
        }

        [HeaderMigrationDataFact]
        public void ShareTypeKeepsPublicNativeModesAndAllTypeConsumers()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", "lmshare.h.patch");
            string added = string.Join("\n", File.ReadAllLines(path).Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            var provider = Regex.Match(added, @"_Win32_FlagsEnum_\(SHARE_TYPE,\s*DWORD,\s*([^)]+)\)");
            Assert.True(provider.Success);
            Assert.Equal(new[] { "STYPE_DISKTREE", "STYPE_PRINTQ", "STYPE_DEVICE", "STYPE_IPC", "STYPE_SPECIAL", "STYPE_TEMPORARY", "STYPE_MASK" },
                provider.Groups[1].Value.Split(',').Select(value => value.Trim()));
            foreach (string field in new[] { "shi1_type", "shi2_type", "shi501_type", "shi502_type", "shi503_type", "coni1_type" })
                Assert.Matches(@"_Win32_AssociatedEnum_\(SHARE_TYPE\)\s+DWORD\s+" + field + ";", added);
            Assert.Contains("_Out_ _Win32_AssociatedEnum_(SHARE_TYPE) LPDWORD type", added);
            Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+STYPE_\w+\b", added);
        }

        [HeaderMigrationDataFact]
        public void VirtualKeyContributionsKeepNativeWordStorageAndSharedDbeContract()
        {
            string Added(string header) => string.Join("\n", File.ReadAllLines(Path.Combine(
                WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", header + ".patch"))
                .Where(line => line.StartsWith("+", StringComparison.Ordinal) && !line.StartsWith("+++", StringComparison.Ordinal))
                .Select(line => line.Substring(1)));
            string keyboard = Added("kbd.h");
            string ime = Added("ime.h");
            var keyboardDbe = Regex.Match(keyboard,
                @"_Win32_Enum_\(VIRTUAL_KEY,\s*unsigned short,\s*(VK_DBE_\w+[^;]+)\);");
            var imeDbe = Regex.Match(ime,
                @"_Win32_Enum_\(VIRTUAL_KEY,\s*unsigned short,\s*(VK_DBE_\w+[^;]+)\);");
            Assert.True(keyboardDbe.Success);
            Assert.True(imeDbe.Success);
            string[] Labels(Match match) => match.Groups[1].Value.Split(',').Select(value => value.Trim()).ToArray();
            Assert.Equal(14, Labels(keyboardDbe).Length);
            Assert.Equal(Labels(keyboardDbe), Labels(imeDbe));
            Assert.Contains("_Win32_Enum_(VIRTUAL_KEY, unsigned short, VK_ABNT_C1, VK_ABNT_C2);", keyboard);
            Assert.Contains("_Win32_Enum_(VIRTUAL_KEY, unsigned short, VK__none_);", keyboard);
            Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+VK_", keyboard + "\n" + ime);
        }

        [HeaderMigrationDataFact]
        public void PrinterRightsMetadataLabelsReferToNativeStandardRights()
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", "winspool.h.patch");
            string added = string.Join("\n", File.ReadAllLines(path).Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            var provider = Regex.Match(added,
                @"typedef\s+_WIN32META_ANNOTATION_\(""FlagsEnum\(([^""]+)\)"",\s*(.*?)\)\s+ULONG PRINTER_ACCESS_RIGHTS;", RegexOptions.Singleline);
            Assert.True(provider.Success);
            string[] labels = provider.Groups[1].Value.Split(',').Select(value => value.Trim()).ToArray();
            string[] expressions = provider.Groups[2].Value.Split(',').Select(value => value.Trim()).ToArray();
            Assert.Equal(21, labels.Length);
            Assert.Equal(labels.Length, expressions.Length);
            foreach (string native in new[] { "DELETE", "READ_CONTROL", "WRITE_DAC", "WRITE_OWNER", "SYNCHRONIZE",
                "STANDARD_RIGHTS_REQUIRED", "STANDARD_RIGHTS_READ", "STANDARD_RIGHTS_WRITE", "STANDARD_RIGHTS_EXECUTE" })
            {
                string label = "PRINTER_" + native;
                Assert.Equal(native, expressions[Array.IndexOf(labels, label)]);
                Assert.DoesNotMatch(@"(?m)^\s*#\s*define\s+" + label + @"\b", added);
            }
            Assert.Contains("#if (NTDDI_VERSION >= NTDDI_WINBLUE)\n"
                + "_Win32_FlagsEnum_(PRINTER_ACCESS_RIGHTS, ULONG, PRINTER_ACCESS_MANAGE_LIMITED);", added);
        }

        [HeaderMigrationDataTheory]
        [InlineData("cfgmgr32.h", "HCMNOTIFICATION")]
        [InlineData("commctrl.h", "HIMAGELIST")]
        [InlineData("commctrl.h", "HTREEITEM")]
        [InlineData("shellapi.h", "HDROP")]
        [InlineData("shlobj_core.h", "HPSXA")]
        [InlineData("winnt.h", "PTP_CALLBACK_INSTANCE")]
        [InlineData("winnt.h", "PTP_POOL")]
        [InlineData("winnt.h", "PTP_CLEANUP_GROUP")]
        [InlineData("winnt.h", "PTP_WORK")]
        [InlineData("winnt.h", "PTP_TIMER")]
        [InlineData("winnt.h", "PTP_WAIT")]
        [InlineData("winnt.h", "PTP_IO")]
        [InlineData("winuser.h", "HTOUCHINPUT")]
        [InlineData("winuser.h", "HSYNTHETICPOINTERDEVICE")]
        [InlineData("winuser.h", "HRAWINPUT")]
        [InlineData("winuser.h", "HGESTUREINFO")]
        [InlineData("wtsapi32.h", "WTS_CLOUD_AUTH_HANDLE")]
        public void PointerAliasMarkersNameOnlyTheNativePointerDeclarator(string header, string name)
        {
            string path = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", "um", header + ".patch");
            string added = string.Join("\n", File.ReadAllLines(path).Where(line => line.StartsWith("+", StringComparison.Ordinal)
                && !line.StartsWith("+++", StringComparison.Ordinal)).Select(line => line.Substring(1)));
            string declaration = "_Win32_NativeTypedef_ typedef " + name + " " + name + ";";
            Assert.Equal(1, Regex.Matches(added, Regex.Escape(declaration)).Count);
            Assert.Contains("#if defined(WIN32METADATA) && defined(__clang__) && defined(__cplusplus) && !defined(MIDL_PASS)\n"
                + declaration + "\n#endif", added);
            if (name.StartsWith("PTP_", StringComparison.Ordinal))
            {
                string record = name.Substring(1);
                Assert.DoesNotContain("_Win32_NativeTypedef_ typedef " + record + " " + record + ";", added);
            }
        }

        [NativeMigrationTheory("HEADER_ENUM_REPAIR_LEDGER")]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void ActualNativeOwnersPreserveAbiMacrosAndCompiledValues(string architecture, string target, string language)
        {
            using var ledger = JsonDocument.Parse(File.ReadAllText(Required("HEADER_ENUM_REPAIR_LEDGER")));
            var groups = ledger.RootElement.GetProperty("groups").EnumerateArray().ToArray();
            string root = WinHttpMigrationTests.RepositoryRoot;
            string before = Required("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string after = Required("WINHTTP_PREPARED_HEADERS");
            foreach (var owner in NativeOwners)
            {
                var owned = groups.Where(group => group.GetProperty("providers").EnumerateArray().Any(provider =>
                    owner.Headers.Contains(Path.GetFileNameWithoutExtension(provider.GetProperty("owner").GetString()) + ".h",
                        StringComparer.OrdinalIgnoreCase))).ToArray();
                Assert.NotEmpty(owned);
                var probes = new Dictionary<string, (JsonElement Group, JsonElement Member)>(StringComparer.Ordinal);
                var checks = new StringBuilder();
                foreach (var group in owned)
                    foreach (var member in group.GetProperty("expectedMembersByArchitecture").GetProperty(architecture).EnumerateArray())
                    {
                        string probe = "HeaderEnumOwnershipProbe" + probes.Count;
                        string name = probe + "::" + probe + "_Value";
                        probes.Add(name, (group, member));
                        checks.Append("\nenum ").Append(probe).Append(" { ").Append(probe).Append("_Value = (")
                            .Append(member.GetProperty("expression").GetString()).Append(") };\n");
                    }
                string prefix = "#define OEMRESOURCE\n#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                    "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n";
                string source = prefix + string.Join("\n", owner.Headers.Select(header => "#include <" + header + ">")) + "\n";
                var surfaces = new List<string[]>();
                var annotations = new List<string>();
                foreach (var input in new[] { (Path: before, Enabled: false), (Path: before, Enabled: true),
                    (Path: after, Enabled: false), (Path: after, Enabled: true) })
                {
                    var observed = WinHttpNativeControlTests.Surface(root, input.Path, owner.Partition, architecture, target,
                        owner.Headers.Concat(new[] { "main.cpp" }).ToArray(), checks.ToString(),
                        metadataEnabled: input.Enabled, annotations: annotations, sourceText: source, language: language,
                        cInterface: language == "c");
                    Assert.NotEmpty(observed);
                    foreach (string value in observed.Where(value => value.StartsWith("value HeaderEnumOwnershipProbe", StringComparison.Ordinal)))
                    {
                        int separator = value.LastIndexOf(' ');
                        var probe = probes[value.Substring("value ".Length, separator - "value ".Length)];
                        long actual = long.Parse(value.Substring(separator + 1), CultureInfo.InvariantCulture);
                        Assert.Equal(probe.Member.GetProperty("value").GetInt64(),
                            Normalize(actual, probe.Group.GetProperty("storage").GetString()));
                    }
                    Assert.Equal(probes.Count, observed.Count(value => value.StartsWith("value HeaderEnumOwnershipProbe", StringComparison.Ordinal)));
                    surfaces.Add(observed);
                }
                var aliases = annotations.Where(value => value.Contains("|Enum(", StringComparison.Ordinal)
                        || value.Contains("|FlagsEnum(", StringComparison.Ordinal))
                    .Select(value => value.Substring(0, value.IndexOf('|'))).ToHashSet(StringComparer.Ordinal);
                string[] Native(string[] surface) => surface.Where(value =>
                {
                    if (!value.StartsWith("typedef ", StringComparison.Ordinal)) return true;
                    int separator = value.IndexOf(' ', "typedef ".Length);
                    return separator < 0 || !aliases.Contains(value.Substring("typedef ".Length, separator - "typedef ".Length));
                }).ToArray();
                foreach (var surface in surfaces.Skip(1))
                    Assert.Equal(Native(surfaces[0]), Native(surface));
                if (owner.Partition == "MenuRc")
                {
                    annotations.Clear();
                    string withoutOem = source.Replace("#define OEMRESOURCE\n", "", StringComparison.Ordinal);
                    WinHttpNativeControlTests.Surface(root, after, owner.Partition, architecture, target,
                        owner.Headers, "\n#ifdef OCR_NORMAL\n#error OEMRESOURCE guard was widened\n#endif\n",
                        metadataEnabled: true, annotations: annotations, sourceText: withoutOem, language: language,
                        cInterface: language == "c");
                    Assert.DoesNotContain(annotations, value => value.StartsWith("SYSTEM_CURSOR_ID|", StringComparison.Ordinal));
                }
            }
        }

        [NativeMigrationTheory("HEADER_ENUM_REPAIR_LEDGER")]
        [InlineData("x86", 1)]
        [InlineData("x64", 2)]
        [InlineData("arm64", 4)]
        public void ConfiguredNormalRawProvidersAndPhysicalImageKeepWholeContracts(string architecture, int mask)
        {
            using var ledger = JsonDocument.Parse(File.ReadAllText(Required("HEADER_ENUM_REPAIR_LEDGER")));
            var groups = ledger.RootElement.GetProperty("groups").EnumerateArray().ToArray();
            Assert.Equal(34, groups.Length);
            string generated = Required("HEADER_ENUM_REPAIR_RAW");
            var paths = Directory.GetFiles(generated, "*.cs").Concat(new[] { "common", architecture }
                .SelectMany(directory => Directory.GetFiles(Path.Combine(generated, directory), "*.cs"))).ToArray();
            Assert.DoesNotContain(paths, path => path.Contains(Path.Combine("generated", "obj") + Path.DirectorySeparatorChar,
                StringComparison.OrdinalIgnoreCase));
            var names = groups.Select(group => group.GetProperty("name").GetString()).ToHashSet(StringComparer.Ordinal);
            var providersByName = names.ToDictionary(name => name,
                _ => new List<(string Storage, bool Flags, Dictionary<string, long> Members)>(), StringComparer.Ordinal);
            var usesByKey = new Dictionary<string, HashSet<string>>(StringComparer.Ordinal);
            foreach (string path in paths)
            {
                string text = File.ReadAllText(path);
                if (!names.Any(name => text.Contains(name, StringComparison.Ordinal))) continue;
                var root = CSharpSyntaxTree.ParseText(text, path: path).GetRoot();
                foreach (var provider in root.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Where(provider => names.Contains(provider.Identifier.ValueText)))
                {
                    string storage = provider.BaseList?.Types.Single().Type.ToString() ?? "int";
                    bool flags = provider.AttributeLists.SelectMany(list => list.Attributes)
                        .Any(attribute => attribute.Name.ToString().EndsWith(".Flags", StringComparison.Ordinal)
                            || attribute.Name.ToString().EndsWith(".FlagsAttribute", StringComparison.Ordinal));
                    providersByName[provider.Identifier.ValueText].Add((storage, flags, provider.Members.ToDictionary(
                        member => member.Identifier.ValueText, member => RawValue(member.EqualsValue.Value), StringComparer.Ordinal)));
                }
                foreach (var attribute in root.DescendantNodes().OfType<AttributeSyntax>())
                {
                    string group = Association(attribute);
                    if (group == null || !names.Contains(group)) continue;
                    string key = group + "|" + UseKey(attribute);
                    if (!usesByKey.TryGetValue(key, out var storages))
                        usesByKey.Add(key, storages = new HashSet<string>(StringComparer.Ordinal));
                    storages.Add(UseStorage(attribute));
                }
            }
            using var stream = File.OpenRead(Required("HEADER_ENUM_REPAIR_WINMD"));
            using var image = new PEReader(stream);
            var reader = image.GetMetadataReader();
            foreach (var group in groups)
            {
                string name = group.GetProperty("name").GetString();
                string storage = group.GetProperty("storage").GetString();
                var expected = group.GetProperty("expectedMembersByArchitecture").GetProperty(architecture).EnumerateArray()
                    .ToDictionary(member => member.GetProperty("name").GetString(), member => member.GetProperty("value").GetInt64(),
                        StringComparer.Ordinal);
                var providers = providersByName[name];
                Assert.NotEmpty(providers);
                var rawMembers = new Dictionary<string, long>(StringComparer.Ordinal);
                foreach (var provider in providers)
                {
                    Assert.Equal(storage == "UInt16" ? "ushort" : storage == "UInt32" ? "uint" : "int", provider.Storage);
                    Assert.Equal(group.GetProperty("flags").GetBoolean(), provider.Flags);
                    foreach (var member in provider.Members)
                    {
                        string memberName = member.Key;
                        Assert.Contains(memberName, expected.Keys);
                        long value = Normalize(member.Value, storage);
                        Assert.Equal(expected[memberName], value);
                        if (rawMembers.TryGetValue(memberName, out long previous)) Assert.Equal(previous, value);
                        else rawMembers.Add(memberName, value);
                    }
                }
                Assert.Equal(expected.OrderBy(pair => pair.Key), rawMembers.OrderBy(pair => pair.Key));
                var type = Assert.Single(Types(reader, group.GetProperty("fullName").GetString(), mask));
                Assert.Equal(storage, reader.GetFieldDefinition(type.GetFields().Single(handle =>
                    reader.GetString(reader.GetFieldDefinition(handle).Name) == "value__"))
                    .DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null));
                Assert.Equal(group.GetProperty("flags").GetBoolean(), HasAttribute(reader, type.GetCustomAttributes(), "FlagsAttribute"));
                Assert.False(HasAttribute(reader, type.GetCustomAttributes(), "ScopedEnumAttribute"));
                var fields = type.GetFields().Select(reader.GetFieldDefinition)
                    .Where(field => reader.GetString(field.Name) != "value__" && Applies(reader, field.GetCustomAttributes(), mask)).ToArray();
                var actual = fields.ToDictionary(field => reader.GetString(field.Name), field => Constant(reader, field, storage), StringComparer.Ordinal);
                Assert.Equal(expected.OrderBy(pair => pair.Key), actual.OrderBy(pair => pair.Key));
                if (name == "TVITEMEXW_CHILDREN")
                {
                    Assert.Equal(new[] { "I_ZERO", "I_ONE_OR_MORE", "I_CHILDRENCALLBACK", "I_CHILDRENAUTO" },
                        fields.Select(field => reader.GetString(field.Name)));
                    Assert.Equal(new long[] { 0, 1, -1, -2 }, fields.Select(field => Constant(reader, field, "Int32")));
                }
                foreach (var use in group.GetProperty("knownRawUses").EnumerateArray().Where(use =>
                    use.GetProperty("profile").GetProperty("directory").GetString() is "common" ||
                    use.GetProperty("profile").GetProperty("directory").GetString() == architecture))
                {
                    string key = name + "|" + use.GetProperty("typeName").GetString().Split('.').Last() + "." +
                        use.GetProperty("member").GetString() + "::" + use.GetProperty("slot").GetString();
                    Assert.True(usesByKey.TryGetValue(key, out var storages), key);
                    Assert.Equal(new[] { use.GetProperty("nativeStorage").GetString() }, storages.OrderBy(value => value));
                }
            }
            foreach (string name in new[] { "TVITEMA", "TVITEMW", "TVITEMEXA", "TVITEMEXW" })
                AssertField(reader, "Windows.Win32.UI.Controls." + name, "cChildren", "Int32", "TVITEMEXW_CHILDREN", mask);
            AssertField(reader, "Windows.Win32.System.Diagnostics.Debug.CONTEXT", "ContextFlags", "UInt32", "CONTEXT_FLAGS", mask);
            AssertField(reader, "Windows.Win32.System.Rpc.RPC_SECURITY_QOS", "ImpersonationType", "UInt32", "RPC_C_IMP_LEVEL", mask);
            var view = Assert.Single(Types(reader, "Windows.Win32.System.Ole.IViewObject", mask));
            var method = view.GetMethods().Select(reader.GetMethodDefinition).Single(value => reader.GetString(value.Name) == "GetAdvise");
            var parameter = method.GetParameters().Select(reader.GetParameter).Single(value => reader.GetString(value.Name) == "pAspects");
            AssertAssociation(reader, parameter.GetCustomAttributes(), "DVASPECT");
        }

        private static string Required(string name)
        {
            string value = Environment.GetEnvironmentVariable(name);
            Assert.False(string.IsNullOrEmpty(value), "Set " + name + " to the fresh qualified execution artifact.");
            return value;
        }

        private static long Normalize(long value, string storage) => storage switch
        {
            "UInt16" => unchecked((ushort)value),
            "UInt32" => unchecked((uint)value),
            "Int32" => unchecked((int)value),
            _ => throw new InvalidOperationException(storage),
        };

        private static long RawValue(Microsoft.CodeAnalysis.CSharp.Syntax.ExpressionSyntax expression)
        {
            var token = Assert.Single(expression.DescendantTokens().Where(value => value.IsKind(SyntaxKind.NumericLiteralToken)));
            long value = token.Value is ulong unsigned ? unchecked((long)unsigned)
                : Convert.ToInt64(token.Value, CultureInfo.InvariantCulture);
            return expression.DescendantNodesAndSelf().OfType<PrefixUnaryExpressionSyntax>()
                .Any(unary => unary.IsKind(SyntaxKind.UnaryMinusExpression)) ? unchecked(-value) : value;
        }

        private static string Association(AttributeSyntax attribute) =>
            attribute.Name.ToString().EndsWith("AssociatedEnum", StringComparison.Ordinal) &&
            attribute.ArgumentList?.Arguments.Single().Expression is LiteralExpressionSyntax literal ? literal.Token.ValueText : null;

        private static string UseKey(AttributeSyntax attribute)
        {
            var declaration = attribute.Parent.Parent;
            var type = declaration.Ancestors().OfType<TypeDeclarationSyntax>().FirstOrDefault();
            string identity = declaration switch
            {
                ParameterSyntax parameter => (parameter.Parent.Parent switch
                {
                    MethodDeclarationSyntax method => method.Identifier.ValueText,
                    DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                    var unknown => throw new InvalidOperationException(unknown.GetType().Name),
                }) + "::" + parameter.Identifier.ValueText,
                FieldDeclarationSyntax field => field.Declaration.Variables.Single().Identifier.ValueText + "::" +
                    field.Declaration.Variables.Single().Identifier.ValueText,
                MethodDeclarationSyntax method => method.Identifier.ValueText + "::return",
                var unknown => throw new InvalidOperationException(unknown.GetType().Name),
            };
            return type?.Identifier.ValueText + "." + identity;
        }

        private static string UseStorage(AttributeSyntax attribute) => attribute.Parent.Parent switch
        {
            ParameterSyntax parameter => parameter.Type.ToString(),
            FieldDeclarationSyntax field => field.Declaration.Type.ToString(),
            MethodDeclarationSyntax method => method.ReturnType.ToString(),
            var unknown => throw new InvalidOperationException(unknown.GetType().Name),
        };

        private static IEnumerable<TypeDefinition> Types(MetadataReader reader, string fullName, int mask) =>
            reader.TypeDefinitions.Select(reader.GetTypeDefinition).Where(type =>
                reader.GetString(type.Namespace) + "." + reader.GetString(type.Name) == fullName &&
                Applies(reader, type.GetCustomAttributes(), mask));

        private static bool HasAttribute(MetadataReader reader, CustomAttributeHandleCollection attributes, string name) =>
            attributes.Any(handle => HeaderAnnotationWinmdTests.AttributeName(reader, handle) == name);

        private static bool Applies(MetadataReader reader, CustomAttributeHandleCollection attributes, int mask)
        {
            var architectures = attributes.Where(handle =>
                HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "SupportedArchitectureAttribute").ToArray();
            if (architectures.Length == 0) return true;
            var blob = reader.GetBlobReader(reader.GetCustomAttribute(Assert.Single(architectures)).Value);
            Assert.Equal(1, blob.ReadUInt16());
            return (blob.ReadInt32() & mask) != 0;
        }

        private static long Constant(MetadataReader reader, FieldDefinition field, string storage)
        {
            var constant = reader.GetConstant(field.GetDefaultValue());
            Assert.Equal(storage, constant.TypeCode.ToString());
            var value = reader.GetBlobReader(constant.Value);
            return storage switch
            {
                "UInt16" => value.ReadUInt16(),
                "UInt32" => value.ReadUInt32(),
                "Int32" => value.ReadInt32(),
                _ => throw new InvalidOperationException(storage),
            };
        }

        private static void AssertField(MetadataReader reader, string typeName, string fieldName, string storage, string group, int mask)
        {
            var type = Assert.Single(Types(reader, typeName, mask));
            var field = type.GetFields().Select(reader.GetFieldDefinition).Single(value => reader.GetString(value.Name) == fieldName);
            Assert.Equal(storage, field.DecodeSignature(new HeaderAnnotationWinmdTests.SignatureNames(), null));
            AssertAssociation(reader, field.GetCustomAttributes(), group);
        }

        private static void AssertAssociation(MetadataReader reader, CustomAttributeHandleCollection attributes, string group)
        {
            var handle = Assert.Single(attributes.Where(handle =>
                HeaderAnnotationWinmdTests.AttributeName(reader, handle) == "AssociatedEnumAttribute"));
            var value = reader.GetBlobReader(reader.GetCustomAttribute(handle).Value);
            Assert.Equal(1, value.ReadUInt16());
            Assert.Equal(group, value.ReadSerializedString());
        }
    }
}
