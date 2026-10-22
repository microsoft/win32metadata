using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Text.RegularExpressions;
using Xunit;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class HeaderManualProviderOwnershipTests
    {
        private static readonly (string Partition, string[] Headers)[] NativeOwners =
        {
            ("WinProg", new[] { "winbase.h", "winternl.h" }),
            ("WinRT", new[] { "hstring.h", "eventtoken.h" }),
            ("MsCs", new[] { "clusapi.h" }),
            ("MenuRc", new[] { "winuser.h", "winnt.h" }),
        };

        [Fact]
        public void EventTokenUsesTheSelectedNativeProvider()
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string partition = Path.Combine(root, "generation", "WinSDK", "Partitions", "WinRT");
            Assert.Contains("#include <eventtoken.h>", File.ReadAllLines(Path.Combine(partition, "main.cpp")));
            Assert.Contains("<IncludeRoot>/winrt/eventtoken.h", File.ReadAllLines(Path.Combine(partition, "settings.rsp")));
        }

        [Fact]
        public void HStringIdentityCommentsAnnotateOnlyNativePointerAliasesInOriginalIdl()
        {
            string patch = Patch("winrt", "hstring.idl");
            Assert.Equal(new[]
            {
                "cpp_quote(\"/* Win32Metadata: type ::HSTRING => NativeTypedef */\")",
                "cpp_quote(\"/* Win32Metadata: type ::HSTRING_BUFFER => NativeTypedef */\")",
            }, Added(patch));
            Assert.Contains("cpp_quote(\"typedef __RPC_unique_pointer HSTRING__* HSTRING;\")", patch);
            Assert.Contains("cpp_quote(\"DECLARE_HANDLE(HSTRING_BUFFER);\")", patch);
            Assert.DoesNotContain("::HSTRING_HEADER => NativeTypedef", patch);
            Assert.DoesNotContain(patch.Split('\n'), line => line.StartsWith("-", StringComparison.Ordinal)
                && !line.StartsWith("---", StringComparison.Ordinal));
            Assert.False(File.Exists(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "patches", "winrt", "hstring.h.patch")));
        }

        [Fact]
        public void PrivateVdsProvidersComeFromOriginalIdlAndSharedNativeIncludeGuards()
        {
            string partition = Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "Partitions", "VirtualDiskService", "main.cpp");
            string source = File.ReadAllText(partition);
            Assert.Contains("#include <vds.h>", source);
            Assert.Contains("#include <vdshwprv.h>", source);
            Assert.DoesNotContain("//#include <vdshwprv.h>", source);
            foreach (var (file, guard) in new[]
            {
                ("vdscmmn.idl", "__VDSCMMN_NATIVE_DECLARATIONS_DEFINED__"),
                ("vdshp.idl", "__VDSHP_NATIVE_DECLARATIONS_DEFINED__"),
            })
            {
                string[] added = Added(Patch("um", file));
                Assert.Contains("cpp_quote(\"#ifndef " + guard + "\")", added);
                Assert.Contains("cpp_quote(\"#define " + guard + "\")", added);
                Assert.Contains("cpp_quote(\"#endif /* " + guard + " */\")", added);
            }
            foreach (var (file, name) in new[]
            {
                ("vdsprvcm.idl", "IVdsProviderPrivate"),
                ("vdshpcm.idl", "IVdsHwProviderPrivate"),
                ("vdshpcm.idl", "IVdsHwProviderPrivateMpio"),
                ("vdscmprv.idl", "IVdsAdmin"),
            })
            {
                string patch = Patch("um", file);
                Assert.Contains("cpp_quote(\"/* Win32Metadata: interface ::" + name +
                    " => SupportedOSPlatform(\\\"windows6.0.6000\\\") */\")", Added(patch));
                Assert.DoesNotContain(patch.Split('\n'), line => line.StartsWith("-", StringComparison.Ordinal)
                    && !line.StartsWith("---", StringComparison.Ordinal));
            }
        }

        [Fact]
        public void RetiredReplacementSuppressionsDoNotHideSelectedWinProgAndClusterRecords()
        {
            string root = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK");
            string[] winProg = File.ReadAllLines(Path.Combine(root, "Partitions", "WinProg", "settings.rsp"));
            Assert.DoesNotContain("_FILE_DISPOSITION_INFO", winProg);
            Assert.DoesNotContain("_PROCESS_BASIC_INFORMATION", winProg);
            string[] cluster = File.ReadAllLines(Path.Combine(root, "Partitions", "MsCs", "settings.rsp"));
            foreach (string name in new[]
            {
                "CLUSPROP_RESOURCE_CLASS_INFO", "_CLUSTER_SHARED_VOLUME_RENAME_INPUT",
                "_CLUSTER_SHARED_VOLUME_RENAME_GUID_INPUT", "CLUSPROP_PARTITION_INFO",
                "CLUSPROP_PARTITION_INFO_EX", "CLUSPROP_PARTITION_INFO_EX2",
                "CLUSPROP_FTSET_INFO", "CLUSPROP_SCSI_ADDRESS",
            })
                Assert.DoesNotContain(name, cluster);
            Assert.Contains("exclude-empty-records", File.ReadAllLines(Path.Combine(root, "scraper.settings.rsp")));
        }

        [NativeMigrationTheory("HEADER_MANUAL_PROVIDER_LEDGER")]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void ActualNativeRecordOwnersPreserveTheirContracts(string architecture, string target, string language)
        {
            using var ledger = JsonDocument.Parse(File.ReadAllText(Required("HEADER_MANUAL_PROVIDER_LEDGER")));
            Assert.Equal("10.0.26100.7705", ledger.RootElement.GetProperty("selectedSdkPackageVersion").GetString());
            Assert.Equal(49, ledger.RootElement.GetProperty("types").GetArrayLength());
            string root = WinHttpMigrationTests.RepositoryRoot;
            string before = Required("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string after = Required("WINHTTP_PREPARED_HEADERS");
            foreach (var owner in NativeOwners)
            {
                string source = NativeSource(owner.Headers);
                string checks = NativeChecks(owner.Partition);
                string[] expected = WinHttpNativeControlTests.Surface(root, before, owner.Partition,
                    architecture, target, owner.Headers, checks, sourceText: source,
                    language: language, cInterface: language == "c");
                Assert.NotEmpty(expected);
                foreach (bool enabled in new[] { false, true })
                {
                    var annotations = new List<string>();
                    string[] actual = WinHttpNativeControlTests.Surface(root, after, owner.Partition,
                        architecture, target, owner.Headers, checks, metadataEnabled: enabled,
                        annotations: annotations, sourceText: source, language: language, cInterface: language == "c");
                    Assert.Equal(Native(expected, annotations), Native(actual, annotations));
                }
            }
        }

        [NativeMigrationTheory("HEADER_MANUAL_PROVIDER_LEDGER")]
        [InlineData("x86", "i686-pc-windows-msvc", "c")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++")]
        public void VdsHeadersInEitherOrderPreserveTheUnionOfBothNativeContracts(
            string architecture, string target, string language)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string before = Required("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string after = Required("WINHTTP_PREPARED_HEADERS");
            string[] headers = { "vds.h", "vdshwprv.h" };
            string[] expected = headers.SelectMany(header => WinHttpNativeControlTests.Surface(root,
                before, "VirtualDiskService", architecture, target, headers, "", sourceText: NativeSource(new[] { header }),
                language: language, cInterface: language == "c")).Distinct(StringComparer.Ordinal)
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.NotEmpty(expected);
            foreach (string header in headers)
            {
                string[] original = WinHttpNativeControlTests.Surface(root, before, "VirtualDiskService",
                    architecture, target, headers, "", sourceText: NativeSource(new[] { header }),
                    language: language, cInterface: language == "c");
                string[] candidate = WinHttpNativeControlTests.Surface(root, after, "VirtualDiskService",
                    architecture, target, headers, "", sourceText: NativeSource(new[] { header }),
                    language: language, cInterface: language == "c");
                Assert.Equal(VdsNative(original, Array.Empty<string>()), VdsNative(candidate, Array.Empty<string>()));
            }
            foreach (string[] order in new[] { headers, headers.Reverse().ToArray() })
                foreach (bool enabled in new[] { false, true })
                {
                    var annotations = new List<string>();
                    string[] actual = WinHttpNativeControlTests.Surface(root, after, "VirtualDiskService",
                        architecture, target, headers, "", metadataEnabled: enabled,
                        annotations: annotations, sourceText: NativeSource(order),
                        language: language, cInterface: language == "c");
                    Assert.Equal(VdsNative(expected, annotations), VdsNative(actual, annotations));
                    foreach (string name in new[]
                    {
                        "IVdsProviderPrivate", "IVdsHwProviderPrivate", "IVdsHwProviderPrivateMpio", "IVdsAdmin",
                    })
                        Assert.Contains(actual, value => value.StartsWith("record " + name + " ", StringComparison.Ordinal));
                }
        }

        private static string[] VdsNative(IEnumerable<string> surface, IEnumerable<string> annotations) =>
            Native(surface.Select(value => Regex.Replace(value,
                @"(?:vds|vdshwprv)\.h:anonymous#\d+", "<native-anonymous>")), annotations);

        private static string[] Native(IEnumerable<string> surface, IEnumerable<string> annotations)
        {
            var carriers = annotations.Where(value => value.Contains("|Enum(", StringComparison.Ordinal)
                || value.Contains("|FlagsEnum(", StringComparison.Ordinal))
                .Select(value => value.Substring(0, value.IndexOf('|'))).ToHashSet(StringComparer.Ordinal);
            return surface.Where(value => !carriers.Any(name =>
                value.StartsWith("typedef " + name + " ", StringComparison.Ordinal)))
                .Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        private static string NativeSource(IEnumerable<string> headers) =>
            "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
            "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n#include <stddef.h>\n" +
            string.Join("\n", headers.Select(header => "#include <" + header + ">")) + "\n";

        private static string NativeChecks(string partition) => partition switch
        {
            "WinProg" => @"
typedef char ManualFileDispositionNativeBoolean[(sizeof(((FILE_DISPOSITION_INFO*)0)->DeleteFile) == 1) ? 1 : -1];
typedef char ManualProcessBasicNativeSize[(sizeof(PROCESS_BASIC_INFORMATION) == 6 * sizeof(void*)) ? 1 : -1];
typedef char ManualProcessBasicNativeArray[(sizeof(((PROCESS_BASIC_INFORMATION*)0)->Reserved2) == 2 * sizeof(void*)) ? 1 : -1];
typedef char ManualProcessBasicNativePid[(offsetof(PROCESS_BASIC_INFORMATION, UniqueProcessId) == 4 * sizeof(void*)) ? 1 : -1];
",
            "WinRT" => @"
typedef char ManualEventTokenNativeValue[(sizeof(((EventRegistrationToken*)0)->value) == 8) ? 1 : -1];
#if defined(_WIN64)
typedef char ManualHStringHeaderNativeSize[(sizeof(HSTRING_HEADER) == 24) ? 1 : -1];
typedef char ManualHStringHeaderNativeBytes[(sizeof(((HSTRING_HEADER*)0)->Reserved.Reserved2) == 24) ? 1 : -1];
#else
typedef char ManualHStringHeaderNativeSize[(sizeof(HSTRING_HEADER) == 20) ? 1 : -1];
typedef char ManualHStringHeaderNativeBytes[(sizeof(((HSTRING_HEADER*)0)->Reserved.Reserved2) == 20) ? 1 : -1];
#endif
",
            "MenuRc" => @"
typedef char ManualMonitorInfoANativeSize[(sizeof(MONITORINFOEXA) == sizeof(MONITORINFO) + CCHDEVICENAME * sizeof(CHAR)) ? 1 : -1];
typedef char ManualMonitorInfoWNativeSize[(sizeof(MONITORINFOEXW) == sizeof(MONITORINFO) + CCHDEVICENAME * sizeof(WCHAR)) ? 1 : -1];
#if defined(_WIN64)
typedef char ManualSListNativeSize[(sizeof(SLIST_ENTRY) == 16) ? 1 : -1];
#else
typedef char ManualSListNativeSize[(sizeof(SLIST_ENTRY) == sizeof(void*)) ? 1 : -1];
#endif
",
            "MsCs" => string.Join("\n", new[]
            {
                "CLUSPROP_RESOURCE_CLASS_INFO", "CLUSTER_SHARED_VOLUME_RENAME_INPUT",
                "CLUSTER_SHARED_VOLUME_RENAME_GUID_INPUT", "CLUSPROP_PARTITION_INFO",
                "CLUSPROP_PARTITION_INFO_EX", "CLUSPROP_PARTITION_INFO_EX2",
                "CLUSPROP_FTSET_INFO", "CLUSPROP_SCSI_ADDRESS",
            }.Select((name, index) => "typedef char ManualClusterNativeRecord" + index + "[(sizeof(" + name + ") > 0) ? 1 : -1];")) + "\n",
            _ => throw new ArgumentOutOfRangeException(nameof(partition)),
        };

        private static string Required(string name)
        {
            string value = Environment.GetEnvironmentVariable(name);
            Assert.False(string.IsNullOrEmpty(value), "Set " + name + " to the exact prepared-source qualification input.");
            return value;
        }

        private static string Patch(string directory, string original) => File.ReadAllText(Path.Combine(
            WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "patches", directory, original + ".patch"));

        private static string[] Added(string patch) => patch.Replace("\r\n", "\n", StringComparison.Ordinal).Split('\n')
            .Where(line => line.StartsWith("+", StringComparison.Ordinal) && !line.StartsWith("+++", StringComparison.Ordinal))
            .Select(line => line.Substring(1)).ToArray();
    }
}
