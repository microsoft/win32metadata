using System.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        private const string ExplicitAliasProjection = @"
namespace NativeMath { struct NativeVector { float x, y, z; }; }
struct ProjectedVector { float x, y, z; };
typedef NativeMath::NativeVector VECTOR_ALIAS;
struct Payload { VECTOR_ALIAS value; };
";

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ExplicitAliasProjectionKeepsItsExistingTypeWithoutSuggestingAnUnusedTagRename(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, ExplicitAliasProjection,
                extraSettings: "--config\nlog-potential-typedef-remappings\n--remap\nVECTOR_ALIAS=ProjectedVector\n");
            fixture.AssertSuccess();
            Assert.DoesNotContain("Potential missing remapping 'NativeMath::NativeVector'", fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            Assert.Equal("ProjectedVector", reader.GetFieldDefinition(
                Assert.Single(FindType(reader, "Payload").GetFields())).DecodeSignature(new SignatureNames(), null));
            Assert.Equal(new[] { "Single", "Single", "Single" }, FindType(reader, "NativeVector").GetFields()
                .Select(reader.GetFieldDefinition).Select(field => field.DecodeSignature(new SignatureNames(), null)));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("", "")]
        [InlineData("--remap\nVECTOR_ALIAS=VECTOR_ALIAS\n", "")]
        [InlineData("--remap\nOther::VECTOR_ALIAS=ProjectedVector\n", "")]
        [InlineData("--remap\nVECTOR_ALIAS=ProjectedVector\n",
            "typedef NativeMath::NativeVector OTHER_ALIAS; struct OtherPayload { OTHER_ALIAS value; };")]
        public void ExplicitAliasProjectionDoesNotHideUndecidedNativeAliases(string settings, string extraDeclaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                ExplicitAliasProjection + extraDeclaration,
                extraSettings: "--config\nlog-potential-typedef-remappings\n" + settings);
            fixture.AssertSuccess();
            Assert.Contains("Potential missing remapping 'NativeMath::NativeVector'", fixture.Diagnostics);
        }
    }
}
