using System;
using System.IO;
using System.Linq;
using System.Text.Json;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(GenerationTimingCollection))]
    public sealed class HybridConstantTests
    {
        private readonly ITestOutputHelper output;

        public HybridConstantTests(ITestOutputHelper output) => this.output = output;

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        public void SimpleValuesNeverGenerateOrEvaluateClangMacroValueProbes(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef long HRESULT;
typedef unsigned long DWORD;
#define STATUS(value) ((HRESULT)(value))
#define SIMPLE_SIGNED 7
#define SIMPLE_HEX 0xffffffff
#define SIMPLE_LONG 4294967295UL
#define SIMPLE_64 18446744073709551615ULL
#define SIMPLE_NEGATIVE -1LL
#define SIMPLE_CAST ((DWORD)-1)
#define SIMPLE_STATUS STATUS(0x80004005L)
#define SIMPLE_ALIAS SIMPLE_HEX
#define SIMPLE_OCTAL 077U
#define SIMPLE_FLOAT -2.5f
#define SIMPLE_TEXT ""narrow""
#define SIMPLE_WIDE L""wide""
#define SIMPLE_WRAPPED TEXT(""wrapped"")
#define TEXT(value) L##value
", annotationsEnabled: false, extraSettings:
                "--config\nnative-constants-only\n--language\n" + language + "\n--std\n" + standard + "\n");
            RunWithTiming(fixture, (values, spans) =>
            {
                Assert.Equal(9, values.Constants.Count);
                Assert.All(values.Constants, value => Assert.Equal("Scanner", value.Evaluation));
                Assert.All(values.Routes, route =>
                {
                    Assert.Equal("ScannerResolved", route.Route);
                    Assert.False(route.ValueProbed);
                    Assert.False(route.CompilerEvaluated);
                });
                var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
                AssertValue("SIMPLE_SIGNED", "int", "int", "7");
                AssertValue("SIMPLE_HEX", "unsigned int", "uint", "4294967295U");
                AssertValue("SIMPLE_LONG", "unsigned long", "uint", "4294967295U");
                AssertValue("SIMPLE_64", "unsigned long long", "ulong", "18446744073709551615UL");
                AssertValue("SIMPLE_NEGATIVE", "long long", "long", "-1L");
                AssertValue("SIMPLE_CAST", "DWORD", "uint", "4294967295U");
                AssertValue("SIMPLE_STATUS", "HRESULT", "int", "-2147467259");
                AssertValue("SIMPLE_ALIAS", "unsigned int", "uint", "4294967295U");
                AssertValue("SIMPLE_OCTAL", "unsigned int", "uint", "63U");
                Assert.Equal(0, Counter(spans, "native-constants.hybrid-route", "valueProbeCount"));
                Assert.Equal(0, Counter(spans, "native-constants.extract", "clangValueEvaluateCount"));
                Assert.DoesNotContain(spans, span => span.GetProperty("name").GetString() == "translation-unit.constant-values");

                void AssertValue(string name, string nativeType, string storage, string value)
                {
                    Assert.Equal(nativeType, constants[name].NativeType);
                    Assert.Equal(storage, constants[name].StorageType);
                    Assert.Equal(value, constants[name].Value);
                    Assert.Equal(fixture.Header, constants[name].Header);
                    Assert.True(constants[name].Line > 0);
                    Assert.True(constants[name].Column > 0);
                    Assert.Equal(NativeConstantGroupProvenance.HashFile(fixture.Header), constants[name].HeaderHash);
                }
            }, constantsOnly: true);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        public void OnlyUnresolvedValueCandidatesReachClangAndStructuralMacrosCannotOwnDeclarations(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned long DWORD;
typedef enum TEST_FLAGS { FlagFirst = 1 } TEST_FLAGS;
#define BEFORE 5U
#ifdef __cplusplus
#define EXTERN_C_START extern ""C"" {
#define EXTERN_C_END }
#else
#define EXTERN_C_START
#define EXTERN_C_END
#endif
#define EXTERN_ALIAS EXTERN_C_START
#define FIELDS _Win32_AssociatedEnum_(TEST_FLAGS) unsigned first; _Win32_AssociatedEnum_(TEST_FLAGS) unsigned second;
typedef struct NativeRecord { FIELDS } NativeRecord;
#define TYPE_WORD unsigned long
#define TYPE_ALIAS DWORD
#define DECLARE_RECORD(name) struct name { int member; };
#define FORWARD_DECLARE(name) DECLARE_RECORD(name)
#define DECLARATION_CALL FORWARD_DECLARE(NotAConstant)
#define ESCAPED_FORWARD 0), 0); struct UnrelatedForward; (0
#define ESCAPED_FORWARD_ALIAS ESCAPED_FORWARD
#define FORWARD_ESCAPE(value) ESCAPED_FORWARD
#define ESCAPED_FORWARD_CALL FORWARD_ESCAPE(0)
#define ARGUMENT_VALUE(ESCAPED_FORWARD) ESCAPED_FORWARD
#define SHADOWED_ARGUMENT ARGUMENT_VALUE(19U)
#define NOTHING(value)
#define AFTER_EMPTY NOTHING(ignored) 13U
#define AFTER 7U
#define COMPLEX (__builtin_popcount(0xB5U) + (1U << 7))
#define ENUM_ALIAS FlagFirst
_Win32_SetLastError_ int NativePrefix(NativeRecord* record);
", extraSettings: "--config\nnative-constant-values\n--language\n" + language + "\n--std\n" + standard + "\n");
            RunWithTiming(fixture, (values, spans) =>
            {
                var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
                Assert.Equal("5U", constants["BEFORE"].Value);
                Assert.Equal("7U", constants["AFTER"].Value);
                Assert.Equal("Scanner", constants["BEFORE"].Evaluation);
                Assert.Equal("Scanner", constants["AFTER"].Evaluation);
                Assert.Equal("13U", constants["AFTER_EMPTY"].Value);
                Assert.Equal("133U", constants["COMPLEX"].Value);
                Assert.Equal("19U", constants["SHADOWED_ARGUMENT"].Value);
                Assert.NotNull(constants["ENUM_ALIAS"].AliasTarget);
                Assert.Equal(NativeConstantGroupProvenance.HashFile(fixture.Header),
                    constants["ENUM_ALIAS"].AliasTarget.HeaderHash);
                string[] dynamic = { "AFTER_EMPTY", "COMPLEX", "ENUM_ALIAS", "SHADOWED_ARGUMENT" };
                Assert.Equal(dynamic, values.Routes.Where(route => route.ValueProbed).Select(route => route.Name));
                Assert.All(values.Routes.Where(route => route.ValueProbed), route =>
                {
                    Assert.Equal("UnresolvedValue", route.Route);
                    Assert.True(route.CompilerEvaluated);
                    Assert.Equal("Clang", constants[route.Name].Evaluation);
                });
                foreach (string name in new[] { "EXTERN_C_START", "EXTERN_C_END", "EXTERN_ALIAS",
                    "FIELDS", "TYPE_WORD", "TYPE_ALIAS", "DECLARATION_CALL", "ESCAPED_FORWARD",
                    "ESCAPED_FORWARD_ALIAS", "ESCAPED_FORWARD_CALL" })
                {
                    var route = Assert.Single(values.Routes.Where(route => route.Name == name));
                    Assert.Equal("NonValue", route.Route);
                    Assert.False(route.ValueProbed);
                    Assert.False(route.CompilerEvaluated);
                    Assert.Contains(values.Issues, issue => issue.Name == name && issue.Diagnostics.Length == 0);
                }
                Assert.Equal(4, Counter(spans, "native-constants.hybrid-route", "valueProbeCount"));
                Assert.Equal(4, Counter(spans, "native-constants.extract", "clangValueEvaluateCount"));
                string source = fixture.ReadSource();
                Assert.Contains("SetLastError = true", source);
                Assert.Contains("NativePrefix", source);
                Assert.DoesNotContain("__Win32MetadataConstant_", source);
                Assert.DoesNotContain("UnrelatedForward", source);
                var root = CSharpSyntaxTree.ParseText(source).GetRoot();
                var record = Assert.Single(root.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(record => record.Identifier.ValueText == "NativeRecord"));
                var fields = record.Members.OfType<FieldDeclarationSyntax>().ToArray();
                Assert.Equal(new[] { "first", "second" }, fields.SelectMany(field => field.Declaration.Variables)
                    .Select(variable => variable.Identifier.ValueText));
                Assert.All(fields, field => Assert.Contains("AssociatedEnum", field.AttributeLists.ToString()));
            });
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        public void TypeOperandForwardDeclarationsPreserveValuesAndActualGuidRejections(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef struct _GUID { unsigned long Data1; unsigned short Data2, Data3; unsigned char Data4[8]; } GUID;
#define BEFORE 5U
_Win32_SetLastError_ int NativeBefore(void);
#define POINTER_SIZE sizeof(struct FreshNativeType*)
#ifdef __cplusplus
#define NAMED_GUID(name) __uuidof(struct name)
#define BAD_GUID_FIRST NAMED_GUID(FirstMissingGuid)
#define BAD_GUID_SECOND NAMED_GUID(SecondMissingGuid)
#else
#define INLINE_RECORD_SIZE sizeof(struct InlineNativeType { unsigned int member; })
#define INLINE_ENUM_SIZE sizeof(enum InlineNativeEnum { InlineNativeFirst = 1 })
#endif
#define AFTER 7U
int NativeAfter(void);
", extraSettings: "--config\nnative-constant-values\n--language\n" + language + "\n--std\n" + standard + "\n");
            RunWithTiming(fixture, (values, spans) =>
            {
                var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
                Assert.Equal(language == "c++" ? 3 : 5, constants.Count);
                Assert.Equal("5U", constants["BEFORE"].Value);
                Assert.Equal("7U", constants["AFTER"].Value);
                Assert.Equal(architecture == "x86" ? "4U" : "8UL", constants["POINTER_SIZE"].Value);
                Assert.Equal("Clang", constants["POINTER_SIZE"].Evaluation);
                Assert.All(values.Constants, value => Assert.Equal(
                    NativeConstantGroupProvenance.HashFile(fixture.Header), value.HeaderHash));
                if (language == "c++")
                    foreach (string name in new[] { "BAD_GUID_FIRST", "BAD_GUID_SECOND" })
                    {
                        var issue = Assert.Single(values.Issues.Where(issue => issue.Name == name));
                        Assert.Equal("native diagnostic", issue.Reason);
                        Assert.Contains(issue.Diagnostics, diagnostic =>
                            diagnostic.Contains("cannot call operator __uuidof on a type with no GUID", StringComparison.Ordinal));
                        var route = Assert.Single(values.Routes.Where(route => route.Name == name));
                        Assert.Equal("UnresolvedValue", route.Route);
                        Assert.True(route.ValueProbed);
                        Assert.False(route.CompilerEvaluated);
                    }
                else
                    foreach (string name in new[] { "INLINE_RECORD_SIZE", "INLINE_ENUM_SIZE" })
                    {
                        Assert.Equal(architecture == "x86" ? "4U" : "4UL", constants[name].Value);
                        Assert.Equal("Clang", constants[name].Evaluation);
                    }
                Assert.Equal(3, Counter(spans, "native-constants.hybrid-route", "valueProbeCount"));
                Assert.Equal(language == "c++" ? 1 : 3, Counter(spans, "native-constants.extract", "clangValueEvaluateCount"));
                string source = fixture.ReadSource();
                Assert.Contains("NativeBefore", source);
                Assert.Contains("NativeAfter", source);
                Assert.Contains("SetLastError = true", source);
                Assert.DoesNotContain("MissingGuid", source);
                Assert.DoesNotContain("FreshNativeType", source);
                Assert.DoesNotContain("InlineNative", source);
                Assert.DoesNotContain("__Win32MetadataConstant_", source);
            });
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        public void UnrelatedForwardDeclarationsFailContainmentEvenWhenEveryRootProbeSurvives(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#define BEFORE (1U + 2U)
#define HIDE_FORWARD(value) value), 0); struct UnrelatedForward; (0
#define HIDDEN_ESCAPE 0 + HIDE_FORWARD(1)
#define AFTER (3U + 4U)
", annotationsEnabled: false, extraSettings:
                "--config\nnative-constants-only\n--language\n" + language + "\n--std\n" + standard + "\n");
            Assert.True(fixture.Run() != 0, fixture.Diagnostics);
            Assert.Contains("Unexpected ", fixture.Diagnostics);
            Assert.Contains("'UnrelatedForward'", fixture.Diagnostics);
            Assert.Contains("'HIDDEN_ESCAPE'", fixture.Diagnostics);
            Assert.DoesNotContain("escaped translation-unit scope", fixture.Diagnostics);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SimpleCastsUseGlobalTypedefStorageAndCanonicalBuiltinSpelling(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
typedef unsigned long GLOBAL_WORD;
typedef double FLOAT_WORD;
namespace Detail {
    typedef unsigned long long GLOBAL_WORD;
    typedef unsigned int FLOAT_WORD;
}
#define GLOBAL_VALUE ((GLOBAL_WORD)-1)
#define FLOAT_VALUE ((FLOAT_WORD)1)
#define BUILTIN_VALUE ((unsigned long int)-1)
", annotationsEnabled: false, extraSettings: "--config\nnative-constants-only\n");
            RunWithTiming(fixture, (values, spans) =>
            {
                var constants = values.Constants.ToDictionary(value => value.NativeName, StringComparer.Ordinal);
                Assert.Equal(2, constants.Count);
                Assert.Equal("uint", constants["GLOBAL_VALUE"].StorageType);
                Assert.Equal("4294967295U", constants["GLOBAL_VALUE"].Value);
                Assert.Equal("GLOBAL_WORD", constants["GLOBAL_VALUE"].NativeType);
                Assert.Equal("unsigned long", constants["BUILTIN_VALUE"].NativeType);
                Assert.Equal("uint", constants["BUILTIN_VALUE"].StorageType);
                Assert.Equal("4294967295U", constants["BUILTIN_VALUE"].Value);
                Assert.DoesNotContain(values.Constants, value => value.NativeName == "FLOAT_VALUE");
                var floating = Assert.Single(values.Routes.Where(route => route.Name == "FLOAT_VALUE"));
                Assert.True(floating.ValueProbed);
                Assert.Equal("UnresolvedValue", floating.Route);
                Assert.Contains(values.Issues, issue => issue.Name == "FLOAT_VALUE" &&
                    issue.Reason == "not a supported integer type");
            }, constantsOnly: true);
        }

        private void RunWithTiming(HeaderAnnotationTests.NativeFixture fixture,
            Action<NativeConstantValues, JsonElement[]> check, bool constantsOnly = false)
        {
            string previous = Environment.GetEnvironmentVariable(GenerationTiming.EnvironmentVariable);
            string reports = Path.Combine(fixture.DirectoryPath, "timing");
            Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, reports);
            try
            {
                if (constantsOnly)
                    Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                else
                    fixture.AssertSuccess();
                var values = NativeConstantExtractionTests.Read(fixture);
                using var report = JsonDocument.Parse(File.ReadAllText(Assert.Single(Directory.GetFiles(reports, "*.json"))));
                var spans = report.RootElement.GetProperty("spans").EnumerateArray().ToArray();
                output.WriteLine(JsonSerializer.Serialize(new { values.Constants, values.Routes, Spans = spans }));
                check(values, spans);
            }
            finally
            {
                Environment.SetEnvironmentVariable(GenerationTiming.EnvironmentVariable, previous);
            }
        }

        private static int Counter(JsonElement[] spans, string name, string counter) =>
            Assert.Single(spans.Where(span => span.GetProperty("name").GetString() == name))
                .GetProperty("counters").GetProperty(counter).GetInt32();
    }
}
