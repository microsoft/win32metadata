using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
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
        public void MetadataDisabledHeadersCompileWithIdenticalNativeAbi(string partition, string architecture, string target)
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
            this.output.WriteLine($"{partition}/{architecture}: {before.Length} native facts; OLD=NEW SHA256 " +
                Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(string.Join("\n", before)))));

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
                using var index = CXIndex.Create(false, false);
                Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, source, arguments.ToArray(),
                    ReadOnlySpan<CXUnsavedFile>.Empty, CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
                using var unit = TranslationUnit.GetOrCreate(handle);
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
                Walk(unit.TranslationUnitDecl, "");
                return result.Select(value => Regex.Replace(value,
                    @"\((?:anonymous|unnamed) (?:struct|union|enum) at (?<location>[^)]+:\d+:\d+)\)",
                    match => anonymous[match.Groups["location"].Value.Replace('\\', '/')]))
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();

                void Walk(Cursor cursor, string owner)
                {
                    cursor.Location.GetExpansionLocation(out var file, out var line, out var column, out _);
                    string header = Path.GetFileName(file.ToString());
                    string childOwner = owner;
                    if (cursor is RecordDecl or EnumDecl)
                    {
                        string name = ((NamedDecl)cursor).Name;
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
                        if (cursor is FunctionDecl function)
                            result.Add("function " + owner + function.Name + " " + function.Type.CanonicalType.AsString);
                        else if (cursor is FieldDecl field)
                            result.Add("field " + owner + field.Name + " " + field.Type.CanonicalType.AsString + " " + field.Handle.OffsetOfField);
                        else if (cursor is RecordDecl record && record.IsCompleteDefinition)
                            result.Add("record " + owner + record.Name + " " + record.Handle.Type.SizeOf + " " + record.Handle.Type.AlignOf);
                        else if (cursor is TypedefDecl typedef)
                            result.Add("typedef " + owner + typedef.Name + " " + typedef.UnderlyingType.CanonicalType.AsString);
                        else if (cursor is EnumDecl enumeration)
                            result.Add("enum " + owner + enumeration.Name + " " + enumeration.IntegerType.AsString);
                        else if (cursor is EnumConstantDecl value)
                            result.Add("value " + owner + value.Name + " " + value.Handle.EnumConstantDeclValue);
                    }
                    foreach (var child in cursor.CursorChildren)
                        if (child.Handle.IsDeclaration || child.Handle.IsTranslationUnit)
                            Walk(child, childOwner);
                }
            }
        }
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
