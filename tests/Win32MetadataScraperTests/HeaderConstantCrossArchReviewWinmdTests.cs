using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Xunit;

namespace Win32MetadataScraperTests
{
    public abstract partial class HeaderAnnotationWinmdTests
    {

        internal const string ReviewEmpty = "enum BASE_E { BASE_ZERO=0 };";
        internal const string ReviewMacro = ReviewEmpty + "\n#define EXTRA 1U\nenum _Win32_AssociatedConstant_(EXTRA) E { E_ZERO=0 };";

        internal static string ReviewFixtureDirectory() => Path.Combine(
            Environment.GetEnvironmentVariable("WIN32_CROSSARCH_REVIEW_ARTIFACTS") ?? AppContext.BaseDirectory, "native-review-fixtures");

        internal static HeaderAnnotationTests.NativeFixture ReviewFixture(string architecture, string declarations)
            => new HeaderAnnotationTests.NativeFixture(architecture, architecture switch
            {
                "x86" => "i686-pc-windows-msvc",
                "x64" => "x86_64-pc-windows-msvc",
                _ => "aarch64-pc-windows-msvc",
            }, declarations, directoryRoot: ReviewFixtureDirectory());

        internal static void ArchiveReviewOutputs(string name, HeaderAnnotationTests.NativeFixture fixture)
        {
            string artifacts = Environment.GetEnvironmentVariable("WIN32_CROSSARCH_REVIEW_ARTIFACTS");
            if (artifacts == null)
                return;
            string destination = Path.Combine(artifacts, name);
            CopyReviewDirectory(fixture.DirectoryPath, destination);
            File.WriteAllText(Path.Combine(destination, "diagnostics.txt"), fixture.Diagnostics);
        }

        internal static void ArchiveReviewImage(string name, HeaderAnnotationTests.NativeFixture fixture, MetadataReader reader)
        {
            string artifacts = Environment.GetEnvironmentVariable("WIN32_CROSSARCH_REVIEW_ARTIFACTS");
            if (artifacts != null)
                ArchiveCombinedHeaderConstants(artifacts, name, fixture.DirectoryPath, reader);
        }

        internal static void CopyActualReviewOutputs(HeaderAnnotationTests.NativeFixture fixture, string destination)
        {
            string source = Path.GetDirectoryName(fixture.Output);
            string architecture = Path.GetFileName(source);
            if (!Directory.Exists(source))
                return;
            foreach (string file in Directory.GetFiles(source, "*.cs", SearchOption.AllDirectories))
            {
                string target = Path.Combine(destination, architecture, Path.GetRelativePath(source, file));
                Directory.CreateDirectory(Path.GetDirectoryName(target));
                File.Copy(file, target, overwrite: true);
            }
        }

        internal static void CopyReviewDirectory(string source, string destination)
        {
            Assert.False(Directory.Exists(destination), "Keep prior attempts immutable.");
            Directory.CreateDirectory(destination);
            foreach (string file in Directory.GetFiles(source, "*", SearchOption.AllDirectories))
            {
                string target = Path.Combine(destination, Path.GetRelativePath(source, file));
                Directory.CreateDirectory(Path.GetDirectoryName(target));
                File.Copy(file, target);
            }
        }
    }
    public class HeaderConstantCrossArchReviewWinmdTests : HeaderAnnotationWinmdTests
    {
        [Theory]
        [InlineData(0)]
        [InlineData(1)]
        [InlineData(2)]
        [InlineData(3)]
        public void ReviewNativeConstantSuffixIdentityAndSparseAvailability(int scenario)
        {
            string declarations = scenario switch
            {
                0 => @"
#define EXTRA 3U
#define EXTRA____1 7U
#define EXTRA____2 9U
enum _Win32_AssociatedConstant_(EXTRA) E0 { ZERO0=0 };
enum _Win32_AssociatedConstant_(EXTRA____1) E1 { ZERO1=0 };
enum _Win32_AssociatedConstant_(EXTRA____2) E2 { ZERO2=0 };
",
                1 => @"
#define EXTRA 3U
#ifdef _WIN64
#define EXTRA____1 2U
#else
#define EXTRA____1 1U
#endif
enum _Win32_AssociatedConstant_(EXTRA) E0 { ZERO0=0 };
enum _Win32_AssociatedConstant_(EXTRA____1) E1 { ZERO1=0 };
",
                _ => @"
enum BASE_E { BASE_ZERO=0 };
" + (scenario == 2 ? "#ifndef _WIN64" : "#ifdef _WIN64") + @"
#define EXTRA 1U
enum _Win32_AssociatedConstant_(EXTRA) E { E_ZERO=0 };
#endif
",
            };
            string artifacts = Environment.GetEnvironmentVariable("WIN32_CROSSARCH_REVIEW_ARTIFACTS");
            string fixtures = Path.Combine(artifacts ?? AppContext.BaseDirectory, "native-review-fixtures");
            using var x86 = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", declarations, directoryRoot: fixtures);
            using var x64 = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", declarations, directoryRoot: fixtures);
            using var arm64 = new HeaderAnnotationTests.NativeFixture("arm64", "aarch64-pc-windows-msvc", declarations, directoryRoot: fixtures);
            foreach (var fixture in new[] { x86, x64, arm64 })
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                if (fixture != x86)
                    CopyActualReviewOutputs(fixture, x86.DirectoryPath);
            }
            try
            {
                using var image = Emit(x86, "crossarch");
                var reader = image.Reader;
                if (artifacts != null)
                    ArchiveCombinedHeaderConstants(artifacts, "review-native-" + scenario, x86.DirectoryPath, reader);
                var fields = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition).ToArray();
                if (scenario < 2)
                {
                    Assert.Equal(3, fields.Length);
                    var suffixes = fields.Where(field => reader.GetString(field.Name) == "EXTRA____1")
                        .OrderBy(field => ReadCombinedHeaderConstant(reader, field)).ToArray();
                    Assert.Equal(scenario == 0 ? 1 : 2, suffixes.Length);
                    Assert.Equal(scenario == 0 ? new uint[] { 7 } : new uint[] { 1, 2 },
                        suffixes.Select(field => ReadCombinedHeaderConstant(reader, field)));
                    Assert.Equal(scenario == 0 ? new int?[] { null } : new int?[] { 1, 6 },
                        suffixes.Select(field => ReadCombinedHeaderConstantArchitectures(reader, field.GetCustomAttributes())));
                    AssertStringAttribute(reader, FindType(reader, "E1").GetCustomAttributes(), "AssociatedConstantAttribute", "EXTRA____1");
                    Assert.Equal(3U, ReadCombinedHeaderConstant(reader,
                        Assert.Single(fields.Where(field => reader.GetString(field.Name) == "EXTRA"))));
                    if (scenario == 0)
                    {
                        Assert.Equal(9U, ReadCombinedHeaderConstant(reader,
                            Assert.Single(fields.Where(field => reader.GetString(field.Name) == "EXTRA____2"))));
                        AssertStringAttribute(reader, FindType(reader, "E2").GetCustomAttributes(), "AssociatedConstantAttribute", "EXTRA____2");
                    }
                }
                else
                {
                    var extra = Assert.Single(fields);
                    Assert.Equal("EXTRA", reader.GetString(extra.Name));
                    Assert.Equal(1U, ReadCombinedHeaderConstant(reader, extra));
                    Assert.Equal(scenario == 2 ? 1 : 6,
                        ReadCombinedHeaderConstantArchitectures(reader, extra.GetCustomAttributes()));
                    AssertStringAttribute(reader, FindType(reader, "E").GetCustomAttributes(), "AssociatedConstantAttribute", "EXTRA");
                }
                AssertMetadataClosure(reader);
            }
            catch (Exception error)
            {
                if (artifacts != null)
                {
                    string destination = Path.Combine(artifacts, "review-native-" + scenario + "-failure");
                    CopyReviewDirectory(x86.DirectoryPath, destination);
                    File.WriteAllText(Path.Combine(destination, "failure.txt"), error.ToString());
                }
                throw;
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void ReviewNativeSuccessfulEmptyCompanionHasNoInventedDeclarations(string architecture, string target, bool multipleFiles)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                "enum BASE_E { BASE_ZERO=0 };", multipleFiles: multipleFiles, directoryRoot: ReviewFixtureDirectory());
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string companion = multipleFiles ? Path.Combine(fixture.Output, "header-types.cs")
                : Path.ChangeExtension(fixture.Output, ".header-types.cs");
            Assert.True(File.Exists(companion));
            string source = File.ReadAllText(companion);
            Assert.StartsWith(HeaderTypesSourceFamily.SuccessMarker, source);
            Assert.Empty(CSharpSyntaxTree.ParseText(source).GetCompilationUnitRoot().Members);
            ArchiveReviewOutputs("empty-" + architecture + "-" + multipleFiles, fixture);
        }

        [Fact]
        public void ReviewNativeCommonOnlyX86PartitionRemainsAllArchitecture()
        {
            using var fixture = ReviewFixture("x86", ReviewMacro);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, "crossarch");
            var reader = image.Reader;
            var field = reader.GetFieldDefinition(Assert.Single(FindType(reader, "Apis").GetFields()));
            Assert.Equal("EXTRA", reader.GetString(field.Name));
            Assert.Equal(1U, ReadCombinedHeaderConstant(reader, field));
            AssertDoesNotHaveAttribute(reader, field.GetCustomAttributes(), "SupportedArchitectureAttribute");
            AssertStringAttribute(reader, FindType(reader, "E").GetCustomAttributes(), "AssociatedConstantAttribute", "EXTRA");
            ArchiveReviewImage("common-x86", fixture, reader);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ReviewNativeLastFactRemovalMatchesFreshSparseComposition(bool only64Bit)
        {
            string[][] observed = new string[2][];
            for (int run = 0; run < 2; run++)
            {
                using var x86 = ReviewFixture("x86", run == 0 || !only64Bit ? ReviewMacro : ReviewEmpty);
                using var x64 = ReviewFixture("x64", run == 0 || only64Bit ? ReviewMacro : ReviewEmpty);
                using var arm64 = ReviewFixture("arm64", run == 0 || only64Bit ? ReviewMacro : ReviewEmpty);
                foreach (var fixture in new[] { x86, x64, arm64 })
                {
                    Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                    bool remove = (fixture == x86) == only64Bit;
                    if (run == 0 && remove)
                    {
                        Assert.Contains("const uint EXTRA", fixture.ReadAdditionalTypes());
                        File.WriteAllText(fixture.Header, ReviewEmpty);
                        Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                    }
                    Assert.StartsWith(HeaderTypesSourceFamily.SuccessMarker, fixture.ReadAdditionalTypes());
                    if (remove)
                        Assert.Empty(CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetCompilationUnitRoot().Members);
                    if (fixture != x86)
                        CopyActualReviewOutputs(fixture, x86.DirectoryPath);
                }
                using var image = Emit(x86, "crossarch");
                var reader = image.Reader;
                var field = reader.GetFieldDefinition(Assert.Single(FindType(reader, "Apis").GetFields()));
                Assert.Equal("EXTRA", reader.GetString(field.Name));
                Assert.Equal(1U, ReadCombinedHeaderConstant(reader, field));
                Assert.Equal(only64Bit ? 6 : 1, ReadCombinedHeaderConstantArchitectures(reader, field.GetCustomAttributes()));
                observed[run] = FindType(reader, "Apis").GetFields().Select(reader.GetFieldDefinition)
                    .Select(value => reader.GetString(value.Name) + ":" + ReadCombinedHeaderConstant(reader, value) + ":" +
                        ReadCombinedHeaderConstantArchitectures(reader, value.GetCustomAttributes())).OrderBy(value => value).ToArray();
                ArchiveReviewImage("removal-" + only64Bit + "-" + (run == 0 ? "incremental" : "fresh"), x86, reader);
                AssertMetadataClosure(reader);
            }
            Assert.Equal(observed[0], observed[1]);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ReviewNativeFailedProfileIsNotASuccessfulEmpty(bool incremental)
        {
            using var x86 = ReviewFixture("x86", ReviewMacro);
            using var x64 = ReviewFixture("x64", incremental ? ReviewEmpty : "#error intentional failed profile\n");
            using var arm64 = ReviewFixture("arm64", ReviewMacro);
            Assert.True(x86.Run() == 0, x86.Diagnostics);
            Assert.True(arm64.Run() == 0, arm64.Diagnostics);
            if (incremental)
            {
                Assert.True(x64.Run() == 0, x64.Diagnostics);
                Assert.StartsWith(HeaderTypesSourceFamily.SuccessMarker, x64.ReadAdditionalTypes());
                File.WriteAllText(x64.Header, "#error intentional failed profile\n");
            }
            Assert.NotEqual(0, x64.Run());
            Assert.False(File.Exists(Path.ChangeExtension(x64.Output, ".header-types.cs")));
            CopyActualReviewOutputs(x64, x86.DirectoryPath);
            CopyActualReviewOutputs(arm64, x86.DirectoryPath);
            var error = Assert.Throws<InvalidOperationException>(() => { using var image = Emit(x86, "crossarch"); });
            Assert.Contains("CSSW004", error.Message);
            Assert.False(File.Exists(Path.Combine(x86.DirectoryPath, "Test.winmd")));
            ArchiveReviewOutputs("failed-" + incremental, x86);
            ArchiveReviewOutputs("failed-profile-" + incremental, x64);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ReviewNativeMissingOrUnqualifiedCompanionFailsClosed(bool unqualified)
        {
            using var x86 = ReviewFixture("x86", ReviewMacro);
            using var x64 = ReviewFixture("x64", ReviewEmpty);
            using var arm64 = ReviewFixture("arm64", ReviewMacro);
            foreach (var fixture in new[] { x86, x64, arm64 })
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string companion = Path.ChangeExtension(x64.Output, ".header-types.cs");
            if (unqualified)
                File.WriteAllText(companion, File.ReadAllText(companion).Replace(HeaderTypesSourceFamily.SuccessMarker, ""));
            else
                File.Delete(companion);
            CopyActualReviewOutputs(x64, x86.DirectoryPath);
            CopyActualReviewOutputs(arm64, x86.DirectoryPath);
            var error = Assert.Throws<InvalidOperationException>(() => { using var image = Emit(x86, "crossarch"); });
            Assert.Contains("CSSW004", error.Message);
            Assert.False(File.Exists(Path.Combine(x86.DirectoryPath, "Test.winmd")));
            ArchiveReviewOutputs("incomplete-" + unqualified, x86);
        }
    }
}
