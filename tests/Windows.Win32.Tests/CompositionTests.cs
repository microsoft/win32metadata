using System;
using System.Linq;
using MetadataUtils;
using Xunit;

namespace Windows.Win32.Tests
{
    public class CompositionTests
    {
        [Fact]
        public void DCompositionGetStatisticsUsesCountParameter()
        {
            var typeSystem = DecompilerUtils.LoadDecompilerTypeSystem(TestCommon.TestUtils.Win32WinmdPath);
            var method = DecompilerUtils.GetSelfDefinedWinmdToplevelTypes(typeSystem)
                .SelectMany(type => type.Methods)
                .Single(method => method.Name == "DCompositionGetStatistics");
            var parameter = method.Parameters.Single(parameter => parameter.Name == "targetIds");
            var attribute = Assert.Single(parameter.GetAttributes()
                .Where(attribute => attribute.AttributeType.FullName == "Windows.Win32.Foundation.Metadata.NativeArrayInfoAttribute"));
            var countArgument = Assert.Single(attribute.NamedArguments
                .Where(argument => argument.Name == "CountParamIndex"));

            Assert.Equal(2, Convert.ToInt32(countArgument.Value));
            Assert.Equal("targetIdCount", method.Parameters[2].Name);
            Assert.DoesNotContain(attribute.NamedArguments, argument => argument.Name == "CountFieldName");
        }
    }
}
