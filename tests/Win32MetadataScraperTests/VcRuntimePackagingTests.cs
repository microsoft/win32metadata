using System;
using System.Diagnostics;
using System.IO;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class VcRuntimePackagingTests
    {
        [Theory]
        [InlineData("System32", "redistributable directory")]
        [InlineData("Microsoft.VC145.CRT", "Missing required VC runtime file")]
        public void ResolveRuntime_RejectsInvalidSource(string directoryName, string expectedError)
        {
            string root = Path.Combine(Path.GetTempPath(), "VcRuntimePackaging-" + Guid.NewGuid());
            string runtimeDirectory = Directory.CreateDirectory(Path.Combine(root, directoryName)).FullName;
            try
            {
                var result = ResolveRuntime(root, runtimeDirectory);
                Assert.NotEqual(0, result.ExitCode);
                Assert.Contains(expectedError, result.Error);
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }

        [Theory]
        [InlineData(false, "Expected an x64 PE binary")]
        [InlineData(true, "has no file version")]
        public void ResolveRuntime_RejectsInvalidRuntimeBinary(bool x64, string expectedError)
        {
            string root = Path.Combine(Path.GetTempPath(), "VcRuntimePackaging-" + Guid.NewGuid());
            string runtimeDirectory = Directory.CreateDirectory(Path.Combine(root, "Microsoft.VC145.CRT")).FullName;
            try
            {
                WritePeHeader(Path.Combine(root, "libclang.dll"), x64: true);
                WritePeHeader(Path.Combine(root, "libClangSharp.dll"), x64: true);
                foreach (string name in new[] { "MSVCP140.dll", "VCRUNTIME140.dll", "VCRUNTIME140_1.dll" })
                {
                    WritePeHeader(Path.Combine(runtimeDirectory, name), x64);
                }

                var result = ResolveRuntime(root, runtimeDirectory);
                Assert.NotEqual(0, result.ExitCode);
                Assert.Contains(expectedError, result.Error);
            }
            finally
            {
                Directory.Delete(root, recursive: true);
            }
        }

        private static void WritePeHeader(string path, bool x64)
        {
            using var writer = new BinaryWriter(File.Create(path));
            writer.Write(new byte[128]);
            writer.BaseStream.Position = 0;
            writer.Write((ushort)0x5a4d);
            writer.BaseStream.Position = 0x3c;
            writer.Write((uint)64);
            writer.BaseStream.Position = 64;
            writer.Write((uint)0x00004550);
            writer.Write((ushort)(x64 ? 0x8664 : 0x014c));
            writer.BaseStream.Position = 88;
            writer.Write((ushort)0x20b);
            writer.Write((byte)14);
            writer.Write((byte)50);
        }

        private static (int ExitCode, string Error) ResolveRuntime(string nativeDirectory, string runtimeDirectory)
        {
            DirectoryInfo directory = new DirectoryInfo(AppContext.BaseDirectory);
            while (directory != null && !File.Exists(Path.Combine(directory.FullName, "scripts", "Get-VcRuntimeDirectory.ps1")))
            {
                directory = directory.Parent;
            }

            Assert.NotNull(directory);
            string script = Path.Combine(directory.FullName, "scripts", "Get-VcRuntimeDirectory.ps1");
            var startInfo = new ProcessStartInfo("powershell.exe")
            {
                UseShellExecute = false,
                RedirectStandardOutput = true,
                RedirectStandardError = true,
                CreateNoWindow = true,
            };
            foreach (string argument in new[] { "-NoProfile", "-NonInteractive", "-ExecutionPolicy", "Bypass", "-File", script,
                "-NativeDirectory", nativeDirectory, "-RuntimeDirectory", runtimeDirectory })
            {
                startInfo.ArgumentList.Add(argument);
            }

            using var process = Process.Start(startInfo);
            var output = process.StandardOutput.ReadToEndAsync();
            var error = process.StandardError.ReadToEndAsync();
            if (!process.WaitForExit(30000))
            {
                process.Kill(entireProcessTree: true);
                process.WaitForExit();
                throw new TimeoutException("VC runtime validation did not exit.");
            }

            output.GetAwaiter().GetResult();
            return (process.ExitCode, error.GetAwaiter().GetResult());
        }
    }
}
