using System;
using System.IO;
using System.Linq;
using System.Text.Json;
using MetadataUtils;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeConstantExtractionTests
    {
        [Theory]
        [InlineData("x86", "32", Architecture.X86, "1U", "uint", "4U")]
        [InlineData("x64", "64", Architecture.X64, "2U", "ulong", "8UL")]
        [InlineData("arm64", "64", Architecture.Arm64, "3U", "ulong", "8UL")]
        public void SdkResponseFilesSelectTheActualNativeCompilerArchitecture(
            string architecture, string width, Architecture expected, string identifier, string sizeType, string sizeValue)
        {
            string assets = Path.Combine(AppContext.BaseDirectory, "assets", "scraper");
            string settings = string.Join("\n", new[] { "baseSettings.rsp", $"baseSettings.{width}.rsp",
                $"baseSettings.{architecture}.rsp" }.Select(name => "@" + Path.Combine(assets, name)));
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, "x86_64-pc-windows-msvc", @"
#if defined(__aarch64__)
#define NATIVE_ARCHITECTURE 3U
#elif defined(__x86_64__)
#define NATIVE_ARCHITECTURE 2U
#elif defined(__i386__)
#define NATIVE_ARCHITECTURE 1U
#else
#error Unsupported native architecture
#endif
#define NATIVE_POINTER_SIZE sizeof(void*)
int F();
", extraSettings: "--config\nnative-constant-values\n" + settings);
            fixture.AssertSuccess();
            var values = Read(fixture);
            Assert.Equal(expected, values.Architecture);
            var nativeArchitecture = Assert.Single(values.Constants.Where(value => value.NativeName == "NATIVE_ARCHITECTURE"));
            Assert.Equal(identifier, nativeArchitecture.Value);
            var pointerSize = Assert.Single(values.Constants.Where(value => value.NativeName == "NATIVE_POINTER_SIZE"));
            Assert.Equal(sizeType, pointerSize.StorageType);
            Assert.Equal(sizeValue, pointerSize.Value);
        }

        [Fact]
        public void MissingResponseFilesCannotProduceAFalseSuccessfulRun()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define VALUE 42U\nint F();", extraSettings: "--config\nnative-constant-values\n");
            string missing = Path.Combine(fixture.DirectoryPath, "missing.rsp");
            File.AppendAllText(Path.Combine(fixture.DirectoryPath, "test.rsp"), "\n@" + missing + "\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Response file not found", fixture.Diagnostics);
            Assert.Contains(missing, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".native-constants.json")));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void RestoredMacrosReportMissingDefinitionRecordsWithoutLosingDeclarationProviders(bool hasDeclaration)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define RESTORED_VALUE 32U
#pragma push_macro(""RESTORED_VALUE"")
#undef RESTORED_VALUE
" + (hasDeclaration ? "const unsigned RESTORED_VALUE = 32U;\n" : "") + @"
#pragma pop_macro(""RESTORED_VALUE"")
int F();
", extraSettings: "--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            var values = Read(fixture);
            Assert.DoesNotContain(values.Constants, value => value.NativeName == "RESTORED_VALUE");
            Assert.Contains(values.Issues, value => value.Name == "RESTORED_VALUE" &&
                value.Reason == "active macro definition is not recorded by Clang");
            Assert.Equal(hasDeclaration, fixture.ReadSource().Contains("public const uint RESTORED_VALUE = 32U;"));
        }

        [Theory]
        [InlineData("int", "7", "RAW", "int", "7")]
        [InlineData("int", "7", "RAW + 1", "int", "8")]
        [InlineData("int", "7", "RAW * 2", "int", "14")]
        [InlineData("int", "7", "RAW | 8U", "uint", "15U")]
        [InlineData("unsigned", "7U", "RAW << 1", "uint", "14U")]
        [InlineData("long long", "-1LL", "RAW * 2LL", "long", "-2L")]
        [InlineData("unsigned long long", "0x8000000000000000ULL", "RAW | 1ULL", "ulong", "9223372036854775809UL")]
        [InlineData("unsigned", "0xffffffffU", "(unsigned)RAW + 1U", "uint", "0U")]
        public void EnumMacroExpressionsUseNativePromotionsAndValues(
            string underlying, string enumerator, string expression, string storage, string literal)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                $"enum RESOURCE : {underlying} {{ RAW = {enumerator} }};\n#define ENUM_EXPRESSION ({expression})\nint F();",
                extraSettings: "--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            var value = Assert.Single(Read(fixture).Constants.Where(value => value.NativeName == "ENUM_EXPRESSION"));
            Assert.Equal(storage, value.StorageType);
            Assert.Equal(literal, value.Value);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "uint", "4U")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "ulong", "8UL")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "ulong", "8UL")]
        public void IntegerMacrosUseNativeTypesValuesAndActiveDefinitions(
            string architecture, string target, string sizeType, string sizeValue)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef long HRESULT;
int F();
#define CONTROLS_BASE (CORE_BASE + DELTA)
#define CORE_BASE 0
#define DELTA 50
#define WLAN_BASE ((0x10000 + 0x10000) + 0x10000 / 2)
#define SQL_BASE (-1150)
#define SQL_SEVERITY (SQL_BASE - 1)
#define NM_CLICK (NM_FIRST - 2)
#define NM_FIRST (0U - 0U)
#define WRAP32 (0xffffffffU + 1U)
#define SIGNED64 (-1LL)
#define UNSIGNED64 0xffffffffffffffffULL
#define ONE_U 1U
#define HIGH_U 0x80000000U
#define ONE_ULL 1ULL
#define HIGH_ULL 0x8000000000000000ULL
#define ONE_LL 1LL
#define SIGNED_OVERFLOW (2147483647 + 1)
#define DIVIDE_BY_ZERO (1 / 0)
#define RESULT ((HRESULT)0x80004005L)
#define POINTER_SIZE sizeof(void*)
#define HELPER(x) ((x) * 2U)
#define ANSWER HELPER(21U)
#define ALIAS ANSWER
#define REMOVED 9
#undef REMOVED
#define REDEFINED 1
#undef REDEFINED
#define REDEFINED 7
#define MISSING (NOT_DEFINED + 1)
#define CYCLE_FIRST (CYCLE_SECOND + 1)
#define CYCLE_SECOND (CYCLE_FIRST + 1)
#define TEXT ""text""
#define POINTER ((void*)-1)
#define FLOATING 2.5F
", extraSettings: "--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            var values = Read(fixture);
            Assert.Equal(architecture.ToLowerInvariant(), values.Architecture.ToString().ToLowerInvariant());
            AssertValue("CONTROLS_BASE", "int", "50");
            AssertValue("WLAN_BASE", "int", "163840");
            AssertValue("SQL_SEVERITY", "int", "-1151");
            AssertValue("NM_FIRST", "uint", "0U");
            AssertValue("NM_CLICK", "uint", "4294967294U");
            AssertValue("WRAP32", "uint", "0U");
            AssertValue("SIGNED64", "long", "-1L");
            AssertValue("UNSIGNED64", "ulong", "18446744073709551615UL");
            AssertValue("ONE_U", "uint", "1U");
            AssertValue("HIGH_U", "uint", "2147483648U");
            AssertValue("ONE_ULL", "ulong", "1UL");
            AssertValue("HIGH_ULL", "ulong", "9223372036854775808UL");
            AssertValue("ONE_LL", "long", "1L");
            AssertValue("POINTER_SIZE", sizeType, sizeValue);
            AssertValue("ANSWER", "uint", "42U");
            AssertValue("ALIAS", "uint", "42U");
            AssertValue("REDEFINED", "int", "7");
            var result = AssertValue("RESULT", "int", "-2147467259");
            Assert.Contains("HRESULT", result.NativeType);
            Assert.Equal(Path.GetFullPath(fixture.Header), result.Header);
            Assert.True(result.Line > 0);
            foreach (string name in new[] { "REMOVED", "MISSING", "CYCLE_FIRST", "CYCLE_SECOND", "TEXT", "POINTER", "FLOATING", "SIGNED_OVERFLOW", "DIVIDE_BY_ZERO" })
            {
                Assert.DoesNotContain(values.Constants, value => value.NativeName == name);
                Assert.Contains(values.Issues, value => value.Name == name);
            }
            Assert.DoesNotContain(values.Constants, value => value.NativeName == "HELPER");
            Assert.DoesNotContain(values.Constants, value => value.Header.EndsWith("sal.h"));
            Assert.Contains(values.Issues, value => value.Name == "MISSING" && value.Diagnostics.Length > 0);
            Assert.Contains(values.Issues, value => value.Name == "POINTER" && value.Reason == "pointer constant");

            NativeConstantValue AssertValue(string name, string storage, string literal)
            {
                var value = Assert.Single(values.Constants.Where(value => value.NativeName == name));
                Assert.Equal(storage, value.StorageType);
                Assert.Equal(literal, value.Value);
                return value;
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompoundMacrosDoNotDependOnDefinitionOrHeaderOrder(bool expressionsFirst)
        {
            const string expressions = @"
#define CONTROLS_BASE CORE_BASE + DELTA
#define MEDIA_BASE CONTROLS_BASE + DELTA
#define AC_BASE GEN_BASE + SPAN
#define MSM_BASE AC_BASE + SPAN
#define CONNECT_BASE (MSM_BASE + SPAN / 2)
#define UNION_MASK (IN_MASK | OUT_MASK)
#define SIGNED_SQL_SEVERITY (SQL_BASE - 1)
";
            const string providers = @"
#define CORE_BASE 0
#define DELTA 50
#define GEN_BASE 0
#define SPAN 0x10000
#define IN_MASK 0x80000000U
#define OUT_MASK 0x40000000U
constexpr int SQL_BASE = -1150;
";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                (expressionsFirst ? expressions + providers : providers + expressions) + "\nint F();",
                extraSettings: "--config\nnative-constant-values\n");
            fixture.AssertSuccess();
            var values = Read(fixture);
            foreach (var expected in new[] {
                ("CONTROLS_BASE", "int", "50"), ("MEDIA_BASE", "int", "100"), ("AC_BASE", "int", "65536"),
                ("MSM_BASE", "int", "131072"), ("CONNECT_BASE", "int", "163840"),
                ("UNION_MASK", "uint", "3221225472U"), ("SIGNED_SQL_SEVERITY", "int", "-1151") })
            {
                var value = Assert.Single(values.Constants.Where(value => value.NativeName == expected.Item1));
                Assert.Equal(expected.Item2, value.StorageType);
                Assert.Equal(expected.Item3, value.Value);
            }
        }

        internal static NativeConstantValues Read(HeaderAnnotationTests.NativeFixture fixture) =>
            JsonSerializer.Deserialize<NativeConstantValues>(
                File.ReadAllText(Path.ChangeExtension(fixture.Output, ".native-constants.json")));
    }
}
