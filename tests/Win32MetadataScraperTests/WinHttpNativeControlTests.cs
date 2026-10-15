using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
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
            var before = Surface(original);
            var after = Surface(prepared);
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

            string[] Surface(string includeRoot)
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
                using var unsaved = CXUnsavedFile.Create(source, File.ReadAllText(source) + @"
static_assert(INTERNET_SCHEME_HTTP == 1);
static_assert(INTERNET_SCHEME_HTTPS == 2);
static_assert(INTERNET_SCHEME_FTP == 3);
static_assert(INTERNET_SCHEME_SOCKS == 4);
");
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
                    if (header is "winhttp.h" or "httprequest.h" || (partition == "HttpServer" && header == "http.h"))
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
