using System;
using System.IO;
using ClangSharpSourceToWinmd;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class EmitterIntegrationTests
    {
        [TestMethod]
        public void Main_EnvDteWindowsInterface_EmitsWinmd()
        {
            string sourceDirectory = Path.Combine(Path.GetTempPath(), $"ClangSharpSourceToWinmd-{Guid.NewGuid():N}");
            string outputFileName = Path.Combine(sourceDirectory, "Test.winmd");
            Directory.CreateDirectory(sourceDirectory);

            try
            {
                File.WriteAllText(
                    Path.Combine(sourceDirectory, "Foundation.cs"),
                    @"
namespace Windows.Win32.Foundation
{
    public partial struct BOOL
    {
        public int Value;
    }
}");

                File.WriteAllText(
                    Path.Combine(sourceDirectory, "EnvDTE.cs"),
                    @"
namespace EnvDTE
{
    public partial struct Windows
    {
        public int Value;
    }
}");

                File.WriteAllText(
                    Path.Combine(sourceDirectory, "ShellInterop.cs"),
                    @"
using EnvDTE;

namespace Microsoft.VisualStudio.Shell.Interop
{
    public partial struct IVsUIShell
    {
        public Windows ActiveWindow;
    }
}");

                int exitCode = Program.Main(
                    new[]
                    {
                        "--sourceDir", sourceDirectory,
                        "--outputFileName", outputFileName,
                        "--version", "1.0.0.0",
                    });

                Assert.AreEqual(0, exitCode);
                Assert.IsTrue(File.Exists(outputFileName));
                Assert.IsTrue(new FileInfo(outputFileName).Length > 0);
            }
            finally
            {
                Directory.Delete(sourceDirectory, recursive: true);
            }
        }
    }
}
