using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationTests
    {
        internal sealed class NativeFixture : IDisposable
        {
            internal NativeFixture(string architecture, string target, string declarations, bool annotationsEnabled = true, string libraryPath = "scan.dll", bool multipleFiles = false, string extraSettings = "", string directoryRoot = null, string namespaceName = "Test")
            {
                string annotations = Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h");
                if (!File.Exists(annotations))
                    throw new FileNotFoundException("Annotation header not found.", annotations);
                DirectoryPath = Path.Combine(directoryRoot ?? Path.GetTempPath(), "win32-annotations-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(DirectoryPath);
                Header = Path.Combine(DirectoryPath, "test.h");
                string sal = Path.Combine(AppContext.BaseDirectory, "assets", "sal.h");
                File.WriteAllText(Path.Combine(DirectoryPath, "cleanup.h"), "int CloseThing(void*);\nint CloseFirst(void*);\nint CloseSecond(void*);\n");
                File.WriteAllText(Header, $"#include \"{sal.Replace('\\', '/')}\"\n#include \"cleanup.h\"\n" + declarations);
                string main = Path.Combine(DirectoryPath, "test.cpp");
                File.WriteAllText(main, "#include \"test.h\"\n");
                Output = multipleFiles ? Path.Combine(DirectoryPath, architecture) : Path.Combine(DirectoryPath, architecture, "Bindings.cs");
                string rsp = Path.Combine(DirectoryPath, "test.rsp");
                File.WriteAllText(rsp, $@"--file
{main}
--output
{Output}
--namespace
{namespaceName}
--headerFile
{Path.Combine(AppContext.BaseDirectory, "assets", "scraper.header.txt")}
--include-directory
{Path.Combine(AppContext.BaseDirectory, "assets")}
--traverse
{Header}
--libraryPath
{libraryPath}
--methodClassName
Apis
--config
compatible-codegen
generate-cpp-attributes
{(multipleFiles ? "multi-file" : "")}
{(annotationsEnabled ? "parse-win32-annotations" : "")}
--additional=--target={target}
-D_USE_DECLSPECS_FOR_SAL=1
-D_PREFAST_=1
-Wno-pragma-once-outside-header
{extraSettings}
");
                Arguments = new[] { Path.Combine(DirectoryPath, "remaps.txt"), "@" + rsp };
            }

            internal string DirectoryPath { get; }

            internal string Header { get; }

            internal string Output { get; }

            private string[] Arguments { get; }

            internal string Diagnostics { get; private set; }
            internal int InvocationCount { get; private set; }

            internal void AssertSuccess(params string[] warnings) => AssertGeneratorWarnings(Run(), warnings);
            internal void AssertGeneratorWarnings(int exitCode, params string[] warnings)
            {
                Assert.True(exitCode == warnings.Length, Diagnostics);
                Assert.Equal(warnings.Select(warning => $"Unsupported attribute: '{warning}'. Generated bindings may be incomplete."), Regex.Matches(Diagnostics, @"(?m)^\s*Warning \([^\r\n]+\): ([^\r\n]+)").Select(match => match.Groups[1].Value.TrimEnd()));
                Assert.DoesNotContain("Error (", Diagnostics);
                Assert.DoesNotContain("error:", Diagnostics);
                Assert.True(File.Exists(Output), Diagnostics);
            }

            internal int Run()
            {
                var start = new ProcessStartInfo("dotnet")
                { WorkingDirectory = DirectoryPath, UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true, };
                start.ArgumentList.Add(typeof(RemapDiscovery).Assembly.Location);
                foreach (string argument in Arguments)
                    start.ArgumentList.Add(argument);
                using var process = Process.Start(start);
                InvocationCount++;
                Console.WriteLine($"TEST-TOOLCHAIN scraper pid={process.Id}");
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                Diagnostics = output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult();
                return process.ExitCode;
            }

            internal string ReadSource() => File.ReadAllText(Output);
            internal string ReadAdditionalTypes() => File.ReadAllText(Path.ChangeExtension(Output, ".header-types.cs"));
            public void Dispose() => Directory.Delete(DirectoryPath, recursive: true);
        }
    }
}
