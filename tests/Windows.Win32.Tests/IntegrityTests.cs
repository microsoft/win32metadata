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
        public void Direct3D12IsDefinedInWindowsMetadata()
        {
            using var stream = File.OpenRead(TestUtils.Win32WinmdPath);
            using var pe = new PEReader(stream);
            MetadataReader reader = pe.GetMetadataReader(MetadataReaderOptions.None);
            var types = reader.TypeDefinitions.Select(reader.GetTypeDefinition)
                .Where(type => reader.GetString(type.Namespace) == "Windows.Win32.Graphics.Direct3D12")
                .Select(type => reader.GetString(type.Name)).ToArray();

            Assert.Contains("ID3D12Device", types);
            Assert.Contains("ID3D12Resource", types);
            Assert.Contains("D3D12_RESOURCE_DESC", types);
            Assert.DoesNotContain(reader.AssemblyReferences.Select(reader.GetAssemblyReference),
                reference => reader.GetString(reference.Name) == "Microsoft.Direct3D.D3D12.winmd");
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
            string fullArgs = $"\"{winmdUtilsDll}\" {args}";
            int ret = TestUtils.ExecuteCmd("dotnet", fullArgs, out var outputText, this.outputHelper);
            this.outputHelper.WriteLine(outputText);
            Assert.Equal(0, ret);
        }
    }
}
