using System;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationPerformanceTests
    {
        [Fact]
        public void ParameterCommentLookupPreservesIncludedFileIdentityAndUtf8Offsets()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#include \"input.h\"\n#include \"output.h\"\n",
                extraSettings: "--traverse\ninput.h\noutput.h\n");
            foreach (bool input in new[] { true, false })
            {
                string declarations = "// \u00e9\n" + string.Join("\n", Enumerable.Range(0, 500).Select(index =>
                    $"int {(input ? "Read" : "Save")}{index:D4}(/* [{(input ? "in " : "out")}] */ unsigned* value);"));
                File.WriteAllText(Path.Combine(fixture.DirectoryPath, input ? "input.h" : "output.h"), declarations);
            }
            File.AppendAllText(fixture.Header, "/* Win32Metadata: function ::Read0499 => SetLastError */\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().ToArray();
            Assert.Equal(1000, methods.Length);
            foreach (var method in methods)
            {
                bool input = method.Identifier.ValueText.StartsWith("Read", StringComparison.Ordinal);
                string attributes = Assert.Single(method.ParameterList.Parameters).AttributeLists.ToString();
                Assert.Contains(input ? "InteropServices.In" : "InteropServices.Out", attributes);
                Assert.DoesNotContain(input ? "InteropServices.Out" : "InteropServices.In", attributes);
            }
            Assert.Contains("SetLastError = true", methods.Single(method => method.Identifier.ValueText == "Read0499")
                .AttributeLists.ToString());
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AnnotationBindingPreservesOnlyRequestedMacroConstants(bool associatedMacro)
        {
            string macros = string.Join("\n", Enumerable.Range(0, 2000)
                .Select(index => $"#define PROBE_{index} {index}"));
            string association = associatedMacro ? @"
#define EXTRA_PROBE_FLAG 4U
enum _Win32_AssociatedConstant_(EXTRA_PROBE_FLAG) PROBE_FLAGS { PROBE_FIRST = 1 };
" : "";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                macros + association + "\n_Win32_SetLastError_ int Probe();\n");
            int exitCode = fixture.Run();
            string firstError = fixture.Diagnostics.Split(new[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries)
                .FirstOrDefault(line => line.Contains("Error", StringComparison.Ordinal));
            Assert.True(exitCode == 0, $"Exit {exitCode}; first generator error: {firstError ?? fixture.Diagnostics}");
            Assert.DoesNotContain("Unsupported cursor", fixture.Diagnostics);
            Assert.Contains("SetLastError = true", fixture.ReadSource());
            Assert.DoesNotContain("PROBE_1999", fixture.ReadSource());
            if (associatedMacro)
            {
                Assert.Contains("AssociatedConstant(\"EXTRA_PROBE_FLAG\")", fixture.ReadSource());
                string additionalTypes = fixture.ReadAdditionalTypes();
                Assert.Contains("EXTRA_PROBE_FLAG", additionalTypes);
                Assert.DoesNotContain("PROBE_1999", additionalTypes);
            }
        }

        [Theory]
        [InlineData("#define __unaligned\n")]
        [InlineData("#define __inline inline\n")]
        public void AnnotationBindingDoesNotEvaluateUnrequestedKeywordMacros(string macro)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x86", "i686-pc-windows-msvc", macro + @"
#define EXTRA_PROBE_FLAG 4U
enum _Win32_AssociatedConstant_(EXTRA_PROBE_FLAG) PROBE_FLAGS { PROBE_FIRST = 1 };
_Win32_SetLastError_ int Probe();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("SetLastError = true", fixture.ReadSource());
            Assert.Contains("EXTRA_PROBE_FLAG", fixture.ReadAdditionalTypes());
            Assert.DoesNotContain("Unsupported macro definition record", fixture.Diagnostics);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ExplicitMacroBindingRecordsMacrosWithOrWithoutAnnotations(bool annotationsEnabled)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define PROBE_VALUE (1U << 5)
int Probe();
", annotationsEnabled: annotationsEnabled, extraSettings: "--config\ngenerate-macro-bindings\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var field = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot()
                .DescendantNodes().OfType<FieldDeclarationSyntax>());
            Assert.Equal("PROBE_VALUE", Assert.Single(field.Declaration.Variables).Identifier.ValueText);
            Assert.True(field.Modifiers.Any(SyntaxKind.ConstKeyword));
            Assert.DoesNotContain("Unsupported cursor", fixture.Diagnostics);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void MacroSelectionDoesNotExcludeSameNamedNativeMembers(bool remap)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum NATIVE_FLAGS { NATIVE_VALUE = 1 };
#define NATIVE_VALUE NATIVE_VALUE
#define REQUESTED_FLAG 4U
enum _Win32_AssociatedConstant_(REQUESTED_FLAG) PROBE_FLAGS { PROBE_FIRST = 1 };
int Probe();
", extraSettings: remap ? "--remap\nNATIVE_VALUE=RENAMED_VALUE\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            Assert.Contains(root.DescendantNodes().OfType<EnumMemberDeclarationSyntax>(),
                member => member.Identifier.ValueText == (remap ? "RENAMED_VALUE" : "NATIVE_VALUE"));
            Assert.Empty(root.DescendantNodes().OfType<FieldDeclarationSyntax>());
            var field = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<FieldDeclarationSyntax>());
            Assert.Equal("REQUESTED_FLAG", Assert.Single(field.Declaration.Variables).Identifier.ValueText);
        }

        [Fact]
        public void GeneratorWarningsRemainVisibleWithoutPreventingOutput()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "[[nodiscard]] int WarningProbe();\n", annotationsEnabled: false);
            Assert.True(fixture.Run() > 0, fixture.Diagnostics);
            Assert.Contains("Unsupported attribute: 'WarnUnusedResult'", fixture.Diagnostics);
            Assert.Contains("WarningProbe", fixture.ReadSource());
        }

        [Theory]
        [InlineData("enum __attribute__((flag_enum)) NativeFlags { First = 1, Second = 2 };", "FlagEnum")]
        [InlineData("struct NativeRecord { unsigned flags; }; static_assert(sizeof(&NativeRecord::flags) > 0);", "MSInheritance")]
        [InlineData("[[nodiscard]] int WarnUnused();", "WarnUnusedResult")]
        public void NativeAttributeWarningsHaveTheSameExactPolicyWithoutTheAnnotationReader(string declaration, string warning)
        {
            foreach (bool annotationsEnabled in new[] { false, true })
            {
                using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                    declaration + "\nint WarningProbe();", annotationsEnabled: annotationsEnabled);
                fixture.AssertSuccess(warning);
                Assert.Contains("WarningProbe", fixture.ReadSource());
            }
        }

        [Theory]
        [InlineData(false, false)]
        [InlineData(false, true)]
        [InlineData(true, false)]
        [InlineData(true, true)]
        public void NativeWarningsAreReportedOnceWithSelectiveAndExplicitMacroGeneration(bool allMacros, bool suppressWarnings)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
__attribute__((annotate(""NativeSAL""))) struct IGNORED_BEFORE { int value; };
#define REQUESTED_VALUE 2U
enum _Win32_AssociatedConstant_(REQUESTED_VALUE) E { FIRST = 1 };
__attribute__((annotate(""NativeSAL""))) struct IGNORED_AFTER { int value; };
int Probe();
", extraSettings: (allMacros ? "--config\ngenerate-macro-bindings\n" : "") +
                (suppressWarnings ? "--additional\n-Wno-ignored-attributes\n" : ""));
            fixture.AssertSuccess();
            Assert.Equal(suppressWarnings ? 0 : 2,
                fixture.Diagnostics.Split("attribute 'annotate' is ignored").Length - 1);
            string source = allMacros ? fixture.ReadSource() : fixture.ReadAdditionalTypes();
            var field = Assert.Single(CSharpSyntaxTree.ParseText(source).GetRoot()
                .DescendantNodes().OfType<FieldDeclarationSyntax>()
                .Where(value => value.Declaration.Variables.Any(variable =>
                    variable.Identifier.ValueText == "REQUESTED_VALUE")));
            Assert.Equal("uint", field.Declaration.Type.ToString());
            var value = Assert.IsType<LiteralExpressionSyntax>(
                Assert.Single(field.Declaration.Variables).Initializer.Value);
            Assert.Equal(2U, Convert.ToUInt32(value.Token.Value));
        }

        [Fact]
        public void GeneratorErrorsRemainVisibleAndPreventOutput()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "namespace { int NamespaceProbe(); }\n", annotationsEnabled: false);
            Assert.True(fixture.Run() < 0, fixture.Diagnostics);
            Assert.Contains("Unsupported anonymous named declaration: 'Namespace'", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void InvalidSelectiveMacrosDoNotPublishOutput()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define EXTRA_PROBE_FLAG MISSING_PROBE_VALUE
enum _Win32_AssociatedConstant_(EXTRA_PROBE_FLAG) PROBE_FLAGS { PROBE_FIRST = 1 };
int Probe();
");
            Assert.True(fixture.Run() < 0, fixture.Diagnostics);
            Assert.Contains("Selective AssociatedConstant macro binding", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }
    }
}
