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
