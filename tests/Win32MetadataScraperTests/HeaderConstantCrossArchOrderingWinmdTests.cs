using System;
using System.IO;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        private static MetadataImage EmitPrimitiveAliasesWithEvidence(HeaderAnnotationTests.NativeFixture first,
            HeaderAnnotationTests.NativeFixture extra, string architecture, bool includeGroupImport)
        {
            string artifacts = Environment.GetEnvironmentVariable("WIN32_PRIMITIVE_ALIAS_CROSSARCH_ARTIFACTS");
            string name = "primitive-alias-" + architecture + "-" + includeGroupImport;
            MetadataImage image = null;
            try
            {
                image = Emit(first, architecture);
                if (artifacts != null)
                    ArchiveCombinedHeaderConstants(artifacts, name, first.DirectoryPath, image.Reader);
                return image;
            }
            catch (Exception error)
            {
                image?.Dispose();
                if (artifacts != null)
                {
                    string destination = Path.Combine(artifacts, name);
                    if (!Directory.Exists(destination))
                        CopyReviewDirectory(first.DirectoryPath, destination);
                    File.WriteAllText(Path.Combine(destination, "failure.txt"), error.ToString());
                }
                throw;
            }
            finally
            {
                if (artifacts != null)
                {
                    string destination = Path.Combine(artifacts, name, "native-extra-provider");
                    Directory.CreateDirectory(destination);
                    foreach (string file in Directory.GetFiles(extra.DirectoryPath))
                        File.Copy(file, Path.Combine(destination, Path.GetFileName(file)), overwrite: true);
                    File.WriteAllText(Path.Combine(destination, "diagnostics.txt"), extra.Diagnostics);
                }
            }
        }

        [Theory]
        [InlineData(false, "uint", "UNDECLARED")]
        [InlineData(true, "uint", "UNDECLARED")]
        [InlineData(false, "uint", "FIRST")]
        [InlineData(true, "uint", "FIRST")]
        [InlineData(false, "byte", "TOO_LARGE")]
        [InlineData(true, "byte", "TOO_LARGE")]
        public void ReviewPrimitiveAliasQualificationKeepsMissingAmbiguousAndOutOfRangeErrors(bool includeGroupImport, string type, string value)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", @"
#define FIRST 1U
#define TOO_LARGE 256U
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST, TOO_LARGE);
_Win32_Enum_(SECOND_GROUP, unsigned, FIRST);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string file = Path.Combine(fixture.DirectoryPath, "Rejected.constants.cs");
            string source = (includeGroupImport ? "using static Test.ERROR_GROUP;\n" +
                (value == "FIRST" ? "using static Test.SECOND_GROUP;\n" : "") : "") +
                $"namespace Test {{ public static partial class Apis {{ public const {type} Rejected = {value}; }} }}";
            File.WriteAllText(file, source);
            byte[] original = File.ReadAllBytes(file);
            var error = Assert.Throws<InvalidOperationException>(() => { using var image = Emit(fixture, "crossarch"); });
            Assert.Contains("CSSW003", error.Message);
            Assert.Equal(original, File.ReadAllBytes(file));
            Assert.False(File.Exists(Path.Combine(fixture.DirectoryPath, "Test.winmd")));
        }
    }
}
