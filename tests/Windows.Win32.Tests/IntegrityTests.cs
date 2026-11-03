using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Reflection.PortableExecutable;
using TestCommon;
using Xunit;
using Xunit.Abstractions;

namespace Windows.Win32.Tests
{
    public class IntegrityTests
    {
        private ITestOutputHelper outputHelper;

        public IntegrityTests(ITestOutputHelper outputHelper)
        {
            this.outputHelper = outputHelper;
        }

        [Fact]
        public void Direct3D12IsDefinedInWindowsSdkBaseline()
        {
            var paths = TestUtils.Win32WinmdPaths;
            using var windowsStream = File.OpenRead(paths[0]);
            using var windowsPe = new PEReader(windowsStream);
            var windows = windowsPe.GetMetadataReader(MetadataReaderOptions.None);
            if (paths.Length == 1)
            {
                Assert.Contains(windows.TypeDefinitions.Select(windows.GetTypeDefinition),
                    type => windows.GetString(type.Namespace) == "Windows.Win32.Graphics.Direct3D12" &&
                            windows.GetString(type.Name) == "ID3D12Device");
                return;
            }

            using var d3dStream = File.OpenRead(paths[1]);
            using var d3dPe = new PEReader(d3dStream);
            var d3d = d3dPe.GetMetadataReader(MetadataReaderOptions.None);
            Assert.Equal(new System.Version(1, 0, 0, 0), windows.GetAssemblyDefinition().Version);
            Assert.Equal(new System.Version(1, 0, 0, 0), d3d.GetAssemblyDefinition().Version);
            Assert.DoesNotContain(windows.TypeDefinitions.Select(windows.GetTypeDefinition),
                type => windows.GetString(type.Namespace) == "Windows.Win32.Graphics.Direct3D12");
            foreach (string name in new[] { "ID3D12Device", "ID3D12Resource", "D3D12_RESOURCE_DESC" })
            {
                Assert.Contains(d3d.TypeDefinitions.Select(d3d.GetTypeDefinition),
                    type => d3d.GetString(type.Namespace) == "Windows.Win32.Graphics.Direct3D12" &&
                            d3d.GetString(type.Name) == name);
            }
            Assert.Contains(windows.AssemblyReferences.Select(windows.GetAssemblyReference),
                reference => windows.GetString(reference.Name) == "Microsoft.Direct3D.D3D12.winmd" &&
                             reference.Version == d3d.GetAssemblyDefinition().Version);
            Assert.Contains(d3d.AssemblyReferences.Select(d3d.GetAssemblyReference),
                reference => d3d.GetString(reference.Name) == "Windows.Win32.winmd" &&
                             reference.Version == windows.GetAssemblyDefinition().Version);
        }

        [Fact]
        public void NoDuplicateImports()
        {
            string allowedDuplicateImportsFileName = TestUtils.GetAssetFile("duplicateImportsAllowList.rsp");
            string args = $"showDuplicateImports --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedDuplicateImportsFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoDuplicateTypes()
        {
            string args = $"showDuplicateTypes --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoDuplicateConstants()
        {
            string allowedDuplicateConstantsFileName = TestUtils.GetAssetFile("duplicateConstantsAllowList.rsp");
            string args = $"showDuplicateConstants --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedDuplicateConstantsFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoInvalidEmptyDelegates()
        {
            string allowedEmptyDelegatesFileName = TestUtils.GetAssetFile("emptyDelegatesAllowList.rsp");
            string args = $"showEmptyDelegates --winmd \"{TestUtils.Win32WinmdPath}\" \"@{allowedEmptyDelegatesFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoInvalidPointersToDelegates()
        {
            string pointersToDelegatesFileName = TestUtils.GetAssetFile("pointersToDelegatesAllowList.rsp");
            string args = $"showPointersToDelegates --winmd \"{TestUtils.Win32WinmdPath}\" \"@{pointersToDelegatesFileName}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoSuggestedRemappings()
        {
            string suggestedRemappingsFileName = TestUtils.GetAssetFile("suggestedRemappingsAllowList.rsp");
            string projectRoot = Path.GetFullPath(Path.Combine(TestUtils.Win32WinmdPath, "../../generation/WinSDK"));
            string args = $"showSuggestedRemappings --winmd \"{TestUtils.Win32WinmdPath}\" \"@{suggestedRemappingsFileName}\" --projectRoot {projectRoot}";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoBrokenArchTypes()
        {
            string args = $"showBrokenArchTypes --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        [Fact]
        public void NoCyclicalNamespaces()
        {
            string args = $"showNamespaceCycles --winmd \"{TestUtils.Win32WinmdPath}\"";
            this.ExecWinmdUtils(args);
        }

        private void ExecWinmdUtils(string args)
        {
            string winmdUtilsDll = Path.Combine(TestUtils.BinPath, "winmdutils.dll");
            var paths = TestUtils.Win32WinmdPaths;
            foreach (string path in paths)
            {
                string selectedArgs = args.Replace($"\"{TestUtils.Win32WinmdPath}\"", $"\"{path}\"");
                if (args.StartsWith("showEmptyDelegates") || args.StartsWith("showPointersToDelegates"))
                {
                    var references = paths.Where(p => p != path).ToArray();
                    if (references.Length > 0)
                    {
                        selectedArgs += " --ref " + string.Join(" ", references.Select(p => $"\"{p}\""));
                    }
                }

                string fullArgs = $"\"{winmdUtilsDll}\" {selectedArgs}";
                int ret = TestUtils.ExecuteCmd("dotnet", fullArgs, out var outputText, this.outputHelper);
                this.outputHelper.WriteLine(outputText);
                Assert.Equal(0, ret);
            }
        }
    }
}
