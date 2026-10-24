using System.Linq;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{
    public class HypervisorTests
    {
        [Theory]
        [InlineData("WHvGetCapability", Architecture.X64 | Architecture.Arm64)]
        [InlineData("WHvCreatePartition", Architecture.X64 | Architecture.Arm64)]
        [InlineData("WHvEmulatorCreateEmulator", Architecture.X64)]
        public void ApisRetainTheirSupportedArchitectures(string methodName, Architecture expected)
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            var apis = DecompilerUtils.GetSelfDefinedWinmdToplevelTypes(typeSystem)
                .Single(type => type.FullName == "Windows.Win32.System.Hypervisor.Apis");
            var method = apis.Methods.Single(method => method.Name == methodName);
            var attribute = method.GetAttributes()
                .Single(attribute => attribute.AttributeType.FullName == "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute");

            Assert.Equal(expected, (Architecture)attribute.FixedArguments[0].Value);
        }
    }
}
