using System;
using System.IO;
using System.Reflection;
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
            string projectRoot = Environment.GetEnvironmentVariable("WIN32_METADATA_TEST_PROJECT");
            if (string.IsNullOrEmpty(projectRoot))
                projectRoot = Path.GetFullPath(Path.Combine(TestUtils.Win32WinmdPath, "../../generation/WinSDK"));
            if (!Directory.Exists(projectRoot))
                throw new DirectoryNotFoundException("The explicitly selected integrity-test SDK project does not exist: " + projectRoot);
            string args = $"showSuggestedRemappings --winmd \"{TestUtils.Win32WinmdPath}\" \"@{suggestedRemappingsFileName}\" --projectRoot \"{projectRoot}\"";
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

        [Fact]
        public void ConstructorsHaveInstanceSignatures()
        {
            using var image = new PEReader(File.OpenRead(TestUtils.Win32WinmdPath));
            var reader = image.GetMetadataReader(MetadataReaderOptions.None);
            int constructorCount = 0;
            foreach (var handle in reader.MethodDefinitions)
            {
                var method = reader.GetMethodDefinition(handle);
                if (reader.GetString(method.Name) != ".ctor")
                    continue;
                constructorCount++;
                var signature = reader.GetBlobReader(method.Signature);
                string typeName = reader.GetString(reader.GetTypeDefinition(method.GetDeclaringType()).Name);
                Assert.True(signature.ReadSignatureHeader().IsInstance, $"Constructor of '{typeName}' lacks HASTHIS.");
                Assert.False(method.Attributes.HasFlag(MethodAttributes.Static));
            }
            Assert.True(constructorCount > 0);
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
