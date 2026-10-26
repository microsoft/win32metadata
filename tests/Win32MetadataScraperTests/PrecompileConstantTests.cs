using System;
using System.IO;
using System.Linq;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class PrecompileConstantTests
    {
        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "4U")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "8UL")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "8UL")]
        public void PrecompileNamesUseActiveScannerValuesAndComplexClangExpressions(
            string architecture, string target, string pointerSize)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
                #define A 7U
                #define MULTILINE \
                    (A + 2U)
                #if 0
                #define INACTIVE (missing + tokens)
                #endif
                #define REMOVED 23U
                #undef REMOVED
                #define RESTORED 31U
                #pragma push_macro(""RESTORED"")
                #undef RESTORED
                #pragma pop_macro(""RESTORED"")
                #define REDEFINED 1U
                #undef REDEFINED
                #define REDEFINED 5U
                #define POINTER_SIZE sizeof(void*)
                #define FUNCTION(value) ((value) + 1U)
                #define EMPTY
                #define EXCLUDED (not_valid + )
                #define FOREIGN 3U
                #include ""foreign.h""
                enum OWNER : unsigned { Enumerator = 11U };
                #define ENUM_ALIAS Enumerator
                #define BAD_TEMPLATE Bad<-1>()
                template<int N> constexpr int Bad() { static_assert(N > 0, ""precompile probe failure""); return N; }
                int NativeDeclaration();
                ", annotationsEnabled: false,
                extraSettings: "--config\nnative-constant-values\n--exclude\nEXCLUDED\n");
            string foreign = Path.Combine(fixture.DirectoryPath, "foreign.h");
            File.WriteAllText(foreign, "#undef FOREIGN\n#define FOREIGN 9U\n");
            fixture.AssertSuccess();
            var values = NativeConstantExtractionTests.Read(fixture);
            var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
            Assert.Equal("7U", constants["A"].Value);
            Assert.Equal("9U", constants["MULTILINE"].Value);
            Assert.Equal("5U", constants["REDEFINED"].Value);
            Assert.Equal(pointerSize, constants["POINTER_SIZE"].Value);
            Assert.Equal("OWNER", constants["ENUM_ALIAS"].NativeType);
            Assert.NotNull(constants["ENUM_ALIAS"].AliasTarget);
            Assert.Contains(values.Issues, issue => issue.Name == "REMOVED" &&
                issue.Reason == "undefined in the final header environment" && issue.Diagnostics.Length == 0);
            Assert.Contains(values.Issues, issue => issue.Name == "RESTORED" &&
                issue.Reason == "active macro definition is not recorded by Clang");
            Assert.Contains(values.Issues, issue => issue.Name == "FOREIGN" &&
                issue.Reason == "active definition is outside traversed headers");
            Assert.Contains(values.Issues, issue => issue.Name == "EMPTY" &&
                issue.Reason == "non-value macro: empty macro replacement" && issue.Diagnostics.Length == 0);
            Assert.Contains(values.Issues, issue => issue.Name == "BAD_TEMPLATE" && issue.Reason == "native diagnostic" &&
                issue.Diagnostics.Any(diagnostic => diagnostic.Contains("precompile probe failure", StringComparison.Ordinal)));
            foreach (string name in new[] { "INACTIVE", "FUNCTION", "EXCLUDED" })
            {
                Assert.DoesNotContain(values.Constants, value => value.NativeName == name);
                Assert.DoesNotContain(values.Issues, issue => issue.Name == name);
            }
            string source = fixture.ReadSource();
            Assert.Contains("NativeDeclaration", source);
            Assert.DoesNotContain("__Win32MetadataConstant_", source);
        }

        [Fact]
        public void SharedPrecompileIndexCoversLateAssociatedConstantsOutsidePartitionTraversal()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", @"
#include ""provider.h""
#define OWN_VALUE 7U
enum _Win32_AssociatedConstant_(SERVICE_NO_CHANGE) MODE : unsigned { Any = 0 };
int NativeDeclaration(MODE mode);
", extraSettings: "--config\nnative-constant-values\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "provider.h"),
                "#define SERVICE_NO_CHANGE 0xffffffff\n");
            string index = Path.Combine(fixture.DirectoryPath, "names.txt");
            File.WriteAllLines(index, new[] { "OWN_VALUE", "SERVICE_NO_CHANGE" });
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--constant-names-file\n" + index + "\n");
            fixture.AssertSuccess();
            Assert.Equal("OWN_VALUE", Assert.Single(NativeConstantExtractionTests.Read(fixture).Constants).NativeName);
            string source = fixture.ReadAdditionalTypes();
            Assert.Contains("AssociatedConstant(\"SERVICE_NO_CHANGE\")", fixture.ReadSource());
            Assert.Contains("public const uint SERVICE_NO_CHANGE = 4294967295U;", source);
            Assert.DoesNotContain("__Win32MetadataConstant_", fixture.ReadSource());
        }

        [Theory]
        [InlineData("OWN_VALUE\nOWN_VALUE\n", "unique sorted identifiers")]
        [InlineData("OWN_VALUE; bad tokens\n", "unique sorted identifiers")]
        [InlineData("SOME_OTHER_NAME\n", "not included in the pre-compile name scan")]
        public void InvalidOrIncompletePrecompileIndexesFailWithoutDiscoveryFallback(string contents, string error)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define OWN_VALUE 7U\nint F();",
                annotationsEnabled: false, extraSettings: "--config\nnative-constant-values\n");
            string index = Path.Combine(fixture.DirectoryPath, "names.txt");
            File.WriteAllText(index, contents);
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "--constant-names-file\n" + index + "\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains(error, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".native-constants.json")));
        }
    }
}
