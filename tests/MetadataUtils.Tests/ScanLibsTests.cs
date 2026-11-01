using System.IO;
using System.Linq;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;
using MetadataTasks;
using Moq;
using TestCommon;
using Xunit;

namespace MetadataUtils.Tests
{
    public class ScanLibsTests
    {
        [Theory]
        [InlineData("x86", false)]
        [InlineData("x64", false)]
        [InlineData("arm64", false)]
        [InlineData("x86", true)]
        [InlineData("x64", true)]
        [InlineData("arm64", true)]
        public void SystemProbe_IsOptInAndUsesHostExportNames(string arch, bool probeSystemDlls)
        {
            if (!System.OperatingSystem.IsWindows()) return;

            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);
            try
            {
                string libPath = Path.Combine(TestUtils.GetAssetDir(), arch, "cabinet.lib");
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");
                var engine = new Mock<IBuildEngine>();
                var task = new ScanLibs
                {
                    BuildEngine = engine.Object,
                    Libs = new ITaskItem[] { new TaskItem(libPath) },
                    DllSearchPaths = new ITaskItem[] { new TaskItem(tempDir) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                    ProbeSystemDlls = probeSystemDlls,
                };

                Assert.False(task.TrustImportLibOrdinals);
                Assert.True(task.Execute());
                if (!probeSystemDlls)
                {
                    Assert.False(File.Exists(entryPointsRsp));
                    engine.Verify(e => e.LogMessageEvent(It.IsAny<BuildMessageEventArgs>()), Times.Never);
                    return;
                }

                string systemDll = Path.Combine(System.Environment.SystemDirectory, "cabinet.dll");
                engine.Verify(e => e.LogMessageEvent(It.Is<BuildMessageEventArgs>(
                    message => string.Equals(message.Message, $"Checking host system DLL exports: {systemDll}",
                        System.StringComparison.OrdinalIgnoreCase))), Times.Once);
                var names = DllExports.GetNamedExports(systemDll);
                var ordinals = DllExports.GetOrdinalOnlyExports(systemDll);
                Assert.Contains("FCICreate", names);
                string[] expected = LibScraper.GetImportInfos(libPath)
                    .Where(info => info.Ordinal.HasValue && !names.Contains(info.ProcName) && ordinals.Contains(info.Ordinal.Value))
                    .Select(info => $"{info.ProcName}={info.EntryPoint}")
                    .ToArray();
                if (expected.Length == 0)
                {
                    Assert.False(File.Exists(entryPointsRsp));
                }
                else
                {
                    Assert.Equal(new[] { "--importEntryPoint" }.Concat(expected), File.ReadAllLines(entryPointsRsp));
                    Assert.DoesNotContain(File.ReadAllLines(entryPointsRsp), line => line.StartsWith("FCICreate="));
                }
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void SystemProbe_DoesNotOverrideExplicitDllSearchPaths()
        {
            if (!System.OperatingSystem.IsWindows()) return;

            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);
            try
            {
                // A fixture under a system DLL's name ensures both locations contain a candidate.
                File.Copy(Path.Combine(TestUtils.GetAssetDir(), "x64", "ordinalfixture.dll"), Path.Combine(tempDir, "cabinet.dll"));
                var engine = new Mock<IBuildEngine>();
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");
                var task = new ScanLibs
                {
                    BuildEngine = engine.Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64", "cabinet.lib")) },
                    DllSearchPaths = new ITaskItem[] { new TaskItem(tempDir) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                    ProbeSystemDlls = true,
                    TrustImportLibOrdinals = true,
                };

                Assert.True(task.Execute());
                Assert.False(File.Exists(entryPointsRsp));
                engine.Verify(e => e.LogMessageEvent(It.IsAny<BuildMessageEventArgs>()), Times.Never);
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void SystemProbe_MissingDllPreservesByNameImports()
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);
            try
            {
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");
                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64", "ordinalfixture.lib")) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                    ProbeSystemDlls = true,
                };

                Assert.True(task.Execute());
                Assert.False(File.Exists(entryPointsRsp));
                Assert.Contains("FixtureByOrdinal=OrdinalFixture", File.ReadAllLines(task.WithLibsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Theory]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void TrustingImportLib_AllOrdinalTypeImportsGetEntryPoints(string arch)
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);

            try
            {
                string withLibsRsp = Path.Combine(tempDir, "withLibs.rsp");
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");

                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), arch, "ordinalfixture.lib")) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = withLibsRsp,
                    ImportEntryPointsRsp = entryPointsRsp,
                    TrustImportLibOrdinals = true,
                };

                Assert.True(task.Execute());

                string[] libLines = File.ReadAllLines(withLibsRsp);
                Assert.Equal(new[] { "--with-librarypath", "FixtureByName=OrdinalFixture", "FixtureByOrdinal=OrdinalFixture", "FixtureNamedWithOrdinal=OrdinalFixture" }, libLines);
                Assert.Equal(new[] { "--importEntryPoint", "FixtureByOrdinal=#7", "FixtureNamedWithOrdinal=#9" }, File.ReadAllLines(entryPointsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void WithDll_OnlyTheOrdinalOnlyExportGetsAnEntryPoint()
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);

            try
            {
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");

                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64", "ordinalfixture.lib")) },
                    DllSearchPaths = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64")) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                };

                Assert.True(task.Execute());

                // Name only and name+ordinal import by name; only the NONAME export needs "#7".
                Assert.Equal(new[] { "--importEntryPoint", "FixtureByOrdinal=#7" }, File.ReadAllLines(entryPointsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void WithoutDll_ImportsStayByNameUnlessImportLibIsTrusted()
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);

            try
            {
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");

                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64", "ordinalfixture.lib")) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                };

                Assert.True(task.Execute());
                Assert.False(File.Exists(entryPointsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void OrdinalOnlyExport_IsEmittedByNameWhenPreservationDisabled()
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);

            try
            {
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");
                File.WriteAllText(entryPointsRsp, "stale");

                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64", "ordinalfixture.lib")) },
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                    DllSearchPaths = new ITaskItem[] { new TaskItem(Path.Combine(TestUtils.GetAssetDir(), "x64")) },
                    PreserveOrdinalImports = false,
                };

                Assert.True(task.Execute());
                Assert.False(File.Exists(entryPointsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }

        [Fact]
        public void NoOrdinalExports_DeletesStaleEntryPointRsp()
        {
            string tempDir = Path.Combine(Path.GetTempPath(), "scanlibs-" + System.Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(tempDir);

            try
            {
                string entryPointsRsp = Path.Combine(tempDir, "entryPoints.rsp");
                File.WriteAllText(entryPointsRsp, "stale");

                var task = new ScanLibs
                {
                    BuildEngine = new Mock<IBuildEngine>().Object,
                    Libs = new ITaskItem[0],
                    LibToolsBinDir = tempDir,
                    MSBuildProjectDirectory = tempDir,
                    WithLibsRsp = Path.Combine(tempDir, "withLibs.rsp"),
                    ImportEntryPointsRsp = entryPointsRsp,
                };

                Assert.True(task.Execute());
                Assert.False(File.Exists(entryPointsRsp));
            }
            finally
            {
                Directory.Delete(tempDir, true);
            }
        }
    }
}
