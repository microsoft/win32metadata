using System.IO;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeTypedefAnnotationRetirementTests
    {
        [Theory]
        [InlineData("_WIN32META_ANNOTATION_(\"NativeTypedef\") typedef int REJECTED;")]
        [InlineData("/* Win32Metadata: type ::REJECTED => NativeTypedef */\ntypedef int REJECTED;")]
        [InlineData("_WIN32META_ANNOTATION_(\"NativeTypedef\", 0) typedef int REJECTED;")]
        public void AuthoredTypedefIdentityFactsAreRejected(string declaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(
                "x64", "x86_64-pc-windows-msvc", declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("Unknown Win32 metadata annotation 'NativeTypedef'", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }
    }
}
