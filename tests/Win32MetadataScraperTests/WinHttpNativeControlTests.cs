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
            const string checks = @"
static_assert(INTERNET_SCHEME_HTTP == 1);
static_assert(INTERNET_SCHEME_HTTPS == 2);
static_assert(INTERNET_SCHEME_FTP == 3);
static_assert(INTERNET_SCHEME_SOCKS == 4);
";
            var before = Surface(root, original, partition, architecture, target, headers, checks);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks);
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
",
                "MagApi" => @"
static_assert(MW_FILTERMODE_EXCLUDE == 0);
static_assert(MW_FILTERMODE_INCLUDE == 1);
",
                "PsApi1" or "PsApi2" => @"
static_assert(LIST_MODULES_ALL == 3);
static_assert(LIST_MODULES_DEFAULT == 0);
static_assert(LIST_MODULES_32BIT == 1);
static_assert(LIST_MODULES_64BIT == 2);
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
            var before = Surface(root, original, partition, architecture, target, headers, checks);
            var after = Surface(root, prepared, partition, architecture, target, headers, checks);
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

        private static unsafe string[] Surface(string root, string includeRoot, string partition, string architecture,
            string target, string[] headers, string checks)
        {
            string source = Path.Combine(root, "generation", "WinSDK", "Partitions", partition, "main.cpp");
            var arguments = new List<string>
                {
                    "--language=c++", "--std=c++17", "--target=" + target,
                    "--include-directory=" + Path.Combine(root, "generation", "WinSDK", "inc"),
                };
            arguments.AddRange(new[] { "shared", "um", "ucrt", "winrt" }
                .Select(directory => "--include-directory=" + Path.Combine(includeRoot, directory)));
            arguments.AddRange((Environment.GetEnvironmentVariable("INCLUDE") ?? "").Split(';', StringSplitOptions.RemoveEmptyEntries)
                .Select(directory => "--include-directory=" + directory));
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
            using var unsaved = CXUnsavedFile.Create(source, File.ReadAllText(source) + checks);
            using var index = CXIndex.Create(false, false);
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, source, arguments.ToArray(),
                new[] { unsaved }, CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
            // Own raw cursors so earlier generator fixtures cannot supply a cached managed AST wrapper.
            using var unit = handle;
            for (uint i = 0; i < handle.NumDiagnostics; i++)
            {
                using var diagnostic = handle.GetDiagnostic(i);
                Assert.True(diagnostic.Severity < CXDiagnosticSeverity.CXDiagnostic_Error,
                    diagnostic.Format(CXDiagnostic.DefaultDisplayOptions).ToString());
            }
            var result = new List<string>();
            // Clang's anonymous names embed paths and line numbers; retain declaration identity without those incidental coordinates.
            var anonymous = new Dictionary<string, string>(StringComparer.Ordinal);
            var ordinals = new Dictionary<string, int>(StringComparer.Ordinal);
            Walk(unit.Cursor, "");
            return result.Select(value => Regex.Replace(value,
                @"\((?:anonymous|unnamed) (?:struct|union|enum) at (?<location>[^)]+:\d+:\d+)\)",
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
