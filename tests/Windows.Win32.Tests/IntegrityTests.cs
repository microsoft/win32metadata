using System.IO;
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
            string args = $"showDuplicateImports --winmd \"{TestUtils.Win32WinmdPath}\"";
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
            string args = $"showDuplicateConstants --winmd \"{TestUtils.Win32WinmdPath}\"";
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
