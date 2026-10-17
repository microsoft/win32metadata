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
        public void AuthoredAvailabilityHeadersPreserveNativeAbiAndSalWithExactMetadata(
            string partition, string header, string architecture, string target, string language, bool enabled, string[] expected)
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Path.Combine(root, "generation", "WinSDK", "RecompiledIdlHeaders");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var annotations = new List<string>();
            string[] headers = header == "devfiltertypes.h" ? new[] { header, "devquery.h", "devquerydef.h" } : new[] { header };
            var before = Surface(root, original, partition, architecture, target, headers, "",
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            var after = Surface(root, prepared, partition, architecture, target, headers, "", metadataEnabled: enabled,
                annotations: annotations, salAnnotations: afterSal, diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
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

        public static IEnumerable<object[]> AuthoredAvailabilityHeaderControls()
        {
            foreach (string partition in new[]
            {
                "MdmReg", "Media.DShow", "Media.DShow.Xml", "FileHistory", "SecurityCenter", "DirectML", "wnv", "Wsb",
                "Wec", "Tbs", "WebDav", "NetBios", "NetShell", "Eap", "DeviceQuery", "Dwm",
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
                "#include <ntdef.h>\n#include <winerror.h>\n#include <ntstatus.h>\n#include <rpcnterr.h>\n";
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
        {
            string root = WinHttpMigrationTests.RepositoryRoot;
            string original = Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS");
            string prepared = Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS");
            string source = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                (cInterface ? "#define CINTERFACE 1\n" : "") +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n#include <" + header + ">\n";
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
            Assert.Equal(before, after);
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
                $"{facts.Length} exact availability/result annotation facts.");
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

        private static unsafe string[] Surface(string root, string includeRoot, string partition, string architecture,
            string target, string[] headers, string checks, bool metadataEnabled = false, List<string> annotations = null,
            string sourceText = null, List<string> salAnnotations = null, List<string> diagnostics = null,
            string language = "c++", bool cInterface = false)
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
            const string anonymousLocationPattern = @"\((?:anonymous|unnamed)(?: (?:struct|union|enum))? at (?<location>[^)]+:\d+:\d+)\)";
            var anonymous = new Dictionary<string, string>(StringComparer.Ordinal);
            var ordinals = new Dictionary<string, int>(StringComparer.Ordinal);
            Walk(unit.Cursor, "");
            return result.Select(value => Regex.Replace(value, anonymousLocationPattern,
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
                    if (cursor.IsAnonymousRecordDecl || name.Length == 0 || name.StartsWith("(", StringComparison.Ordinal) ||
                        Regex.IsMatch(Text(cursor.Type.Spelling), anonymousLocationPattern))
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
        public NativeMigrationTheoryAttribute(string additionalFixture = null)
        {
            if (Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS") == null)
                Skip = "Set WINHTTP_PREPARED_HEADERS to the pinned private prepared-header tree.";
            else if (additionalFixture != null && Environment.GetEnvironmentVariable(additionalFixture) == null)
                Skip = "Set " + additionalFixture + " to the pinned private prepared-header tree.";
        }
    }
}
