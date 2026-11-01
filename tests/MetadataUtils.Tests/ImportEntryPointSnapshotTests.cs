using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using TestCommon;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ImportEntryPointSnapshotTests
    {
        [Theory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void PrivateSnapshot_UsesSuppliedLibraryMappingsAndOnlyUnnamedOrdinals(string arch)
        {
            string root = Path.Combine(Path.GetTempPath(), $"private-snapshot-{Guid.NewGuid():N}");
            Directory.CreateDirectory(root);
            try
            {
                string mappings = Path.Combine(root, "private.libMappings.rsp");
                string output = Path.Combine(root, "private.importEntryPoints.rsp");
                File.WriteAllText(mappings, "--with-librarypath\nFixtureByName=OrdinalFixture.dll\nFixtureByOrdinal=OrdinalFixture.dll\nFixtureNamedWithOrdinal=OrdinalFixture.dll\n");
                var startInfo = new ProcessStartInfo("pwsh")
                {
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                    CreateNoWindow = true,
                };
                foreach (string argument in new[]
                {
                    "-NoProfile", "-NonInteractive", "-File",
                    Path.Combine(AppContext.BaseDirectory, "CreateImportEntryPoints.ps1"),
                    "-LibDirectories", Path.Combine(TestUtils.GetAssetDir(), arch),
                    "-DllDirectories", Path.Combine(TestUtils.GetAssetDir(), "x64"),
                    "-LibraryMappings", mappings,
                    "-SdkVersion", "private-fixture",
                    "-OutputFile", output,
                    "-MetadataUtilsPath", typeof(LibScraper).Assembly.Location,
                })
                {
                    startInfo.ArgumentList.Add(argument);
                }

                using var process = Process.Start(startInfo)!;
                var stdout = process.StandardOutput.ReadToEndAsync();
                var stderr = process.StandardError.ReadToEndAsync();
                if (!process.WaitForExit(60000))
                {
                    process.Kill(entireProcessTree: true);
                    throw new TimeoutException("Snapshot generation exceeded one minute.");
                }

                Assert.True(process.ExitCode == 0, stdout.GetAwaiter().GetResult() + stderr.GetAwaiter().GetResult());
                string[] lines = File.ReadAllLines(output);
                Assert.Contains(lines, line => line.Contains("SDK private-fixture"));
                Assert.Contains(lines, line => line.Contains("SHA256"));
                Assert.Equal(new[] { "--importEntryPoint", "FixtureByOrdinal=#7" },
                    lines.Where(line => !line.StartsWith("#")));
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }
    }
}
