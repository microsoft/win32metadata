using System;
using System.Collections.Generic;
using System.Linq;
using Xunit;

namespace Windows.Win32.Tests
{
    internal static class NativeConstantContractAssertions
    {
        internal static void Verify(
            string name,
            IReadOnlyList<(int Architectures, long Value)> members,
            IReadOnlyList<(int Architectures, long Value)> macros)
        {
            Assert.NotEmpty(members);
            Assert.All(members, member => Assert.InRange(member.Architectures, 1, 7));
            Assert.Equal(7, members.Aggregate(0, (mask, member) => mask | member.Architectures));
            foreach (var architecture in new[] { 1, 2, 4 })
            {
                var member = Assert.Single(members.Where(item => (item.Architectures & architecture) != 0));
                Assert.Equal(ExpectedValue(name, architecture), member.Value);
            }

            foreach (var macro in macros)
            {
                Assert.InRange(macro.Architectures, 1, 7);
                foreach (var architecture in new[] { 1, 2, 4 }.Where(architecture => (macro.Architectures & architecture) != 0))
                {
                    Assert.Equal(ExpectedValue(name, architecture), macro.Value);
                }
            }
        }

        private static long ExpectedValue(string name, int architecture)
        {
            // The normal product uses the SDK's ANSI aliases and Windows 10 queue-input terms.
            return name switch
            {
                "IMAGE_NT_OPTIONAL_HDR_MAGIC" => architecture == 1 ? 267 : 523,
                "SHCNF_PATH" => 1,
                "SHCNF_PRINTER" => 2,
                "QS_INPUT" => 7175,
                "QS_ALLEVENTS" => 7359,
                "QS_ALLINPUT" => 7423,
                "PM_QS_INPUT" => 470220800,
                _ => throw new ArgumentOutOfRangeException(nameof(name), name, "No native contract was admitted for this constant."),
            };
        }
    }

    public class NativeConstantContractAssertionTests
    {
        [Theory]
        [InlineData("IMAGE_NT_OPTIONAL_HDR_MAGIC", new[] { 1, 6 }, new long[] { 267, 523 })]
        [InlineData("SHCNF_PATH", new[] { 7 }, new long[] { 1 })]
        [InlineData("SHCNF_PRINTER", new[] { 7 }, new long[] { 2 })]
        [InlineData("QS_INPUT", new[] { 7 }, new long[] { 7175 })]
        [InlineData("QS_ALLEVENTS", new[] { 7 }, new long[] { 7359 })]
        [InlineData("QS_ALLINPUT", new[] { 7 }, new long[] { 7423 })]
        [InlineData("PM_QS_INPUT", new[] { 7 }, new long[] { 470220800 })]
        public void CorrectEnumOnlyRepresentationPasses(string name, int[] architectures, long[] values)
        {
            NativeConstantContractAssertions.Verify(name, architectures.Zip(values, (mask, value) => (mask, value)).ToArray(), Array.Empty<(int, long)>());
        }

        [Theory]
        [InlineData("IMAGE_NT_OPTIONAL_HDR_MAGIC", 523)]
        [InlineData("SHCNF_PATH", 5)]
        [InlineData("SHCNF_PRINTER", 6)]
        [InlineData("QS_INPUT", 1031)]
        [InlineData("QS_ALLEVENTS", 1215)]
        [InlineData("QS_ALLINPUT", 1279)]
        [InlineData("PM_QS_INPUT", 67567616)]
        public void WrongEnumOnlyRepresentationFails(string name, long value)
        {
            Assert.Throws<Xunit.Sdk.EqualException>(() =>
                NativeConstantContractAssertions.Verify(name, new[] { (7, value) }, Array.Empty<(int, long)>()));
        }

        [Fact]
        public void MissingEnumArchitectureFailsWithoutMacroFallback()
        {
            Assert.Throws<Xunit.Sdk.EqualException>(() =>
                NativeConstantContractAssertions.Verify("SHCNF_PATH", new[] { (2, 1L) }, Array.Empty<(int, long)>()));
        }

        [Fact]
        public void WrongOptionalMacroRepresentationStillFails()
        {
            Assert.Throws<Xunit.Sdk.EqualException>(() =>
                NativeConstantContractAssertions.Verify("SHCNF_PATH", new[] { (7, 1L) }, new[] { (7, 5L) }));
        }
    }
}
