using System;
using System.Diagnostics;
using System.IO;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class MidlSalConversionTests
    {
        [Theory]
        [InlineData("void F([in] IDispatch* callback);")]
        [InlineData("void F([in, unique] long* value);")]
        [InlineData("void F([in] const unsigned long * value);")]
        [InlineData("void F([in] Sdk::Interface * value);")]
        public void PlainInputPointersKeepCompilerDerivedAnnotations(string input)
        {
            Assert.Equal(input, Convert(input));
        }

        [Theory]
        [InlineData("void F([in] long value);", "void F([in][annotation(\"_In_\")] long value);")]
        [InlineData("void F([out] long* value);", "void F([out][annotation(\"_Out_\")] long* value);")]
        [InlineData("void F([in, size_is(count)] long* values);",
            "void F([in, size_is(count)][annotation(\"_In_reads_(count)\")] long* values);")]
        [InlineData("void F([in][annotation(\"_In_opt_\")] IDispatch* callback);",
            "void F([in][annotation(\"_In_opt_\")] IDispatch* callback);")]
        [InlineData("void F([out, retval][annotation(\"_Win32_Retval_\")] long* value);",
            "void F([out, retval][annotation(\"_Out_retval_ _Win32_Retval_\")] long* value);")]
        [InlineData("void F([annotation(\"_Win32_Retained_\")][in] long* value);",
            "void F([in][annotation(\"_In_ _Win32_Retained_\")] long* value);")]
        [InlineData("void F([in] IDispatch* callback, [in] long count);",
            "void F([in] IDispatch* callback, [in][annotation(\"_In_\")] long count);")]
        [InlineData("cpp_quote(\"void Native([in] IDispatch* callback);\")",
            "cpp_quote(\"void Native([in] IDispatch* callback);\")")]
        public void RichAnnotationsScalarInputsAndQuotedTextRemainUnchanged(string input, string expected)
        {
            Assert.Equal(expected, Convert(input));
        }

        private static string Convert(string input)
        {
            var directory = new DirectoryInfo(AppContext.BaseDirectory);
            while (directory != null &&
                !File.Exists(Path.Combine(directory.FullName, "scripts", "ConvertMidlAttributesToSalAnnotations.ps1")))
                directory = directory.Parent;
            Assert.NotNull(directory);

            string root = Path.Combine(Path.GetTempPath(), "win32-midl-sal-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(root);
            try
            {
                string source = Path.Combine(root, "input.idl");
                string target = Path.Combine(root, "output.idl");
                File.WriteAllText(source, input + Environment.NewLine);
                var start = new ProcessStartInfo("pwsh")
                {
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                foreach (string argument in new[]
                {
                    "-NoProfile", "-NonInteractive", "-File",
                    Path.Combine(directory.FullName, "scripts", "ConvertMidlAttributesToSalAnnotations.ps1"),
                    source, target,
                })
                    start.ArgumentList.Add(argument);
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                Assert.True(process.ExitCode == 0, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
                return File.ReadAllText(target).TrimEnd('\r', '\n');
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }
    }
}
