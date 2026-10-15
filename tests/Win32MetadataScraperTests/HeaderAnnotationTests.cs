using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationTests
    {
        [Theory]
        [InlineData("SetLastError()")]
        [InlineData("Retained(1)")]
        [InlineData("ContainsInteriorPointers=value")]
        [InlineData("RAIIFree()")]
        [InlineData("RAIIFree(Close, )")]
        [InlineData("RAIIFree(Close, (0)")]
        [InlineData("RAIIFree(Close, [))")]
        [InlineData("AssociatedEnum")]
        [InlineData("ImportLibrary(\"\")")]
        [InlineData("SupportedOSPlatform(\"windows10.0.99999\")")]
        [InlineData("Unsupported")]
        public void RejectsMalformedPayload(string payload)
        {
            Assert.Throws<FormatException>(() => HeaderAnnotation.Parse(payload));
        }

        [Fact]
        public void ParsesNestedInvalidExpressionsWithoutSplittingTheirCommas()
        {
            var annotation = HeaderAnnotation.Parse("RAIIFree(CloseThing, 0, ((HANDLE)(long long)-1))");
            Assert.Equal("RAIIFree", annotation.Name);
            Assert.Equal(new[] { "CloseThing", "0", "((HANDLE)(long long)-1)" }, annotation.Arguments);
        }

        [Fact]
        public void TransportSeparatorsInsideExpressionsAreNotAttributeSeparators()
        {
            Assert.Equal(new[] { "RAIIFree(Free, (1 ^ 2), ',')", "Name=SAL_name;p1=\"_Out_\"" },
                HeaderAnnotation.SplitAttributeTransport("RAIIFree(Free, (1 ^ 2), ',')^Name=SAL_name;p1=\"_Out_\""));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeAnnotationsReachProjectedTargets(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
typedef void* HANDLE;
#define INVALID_HANDLE_VALUE ((HANDLE)(long long)-1)
_Win32_ImportLibrary_(""header.dll"") _Win32_SetLastError_ _Win32_SupportedOS_10240_
int __stdcall Imported(_Win32_Retained_ void* input, _Win32_ContainsInteriorPointers_ void* output);
_Win32_RAIIFree_(CloseThing, 0, INVALID_HANDLE_VALUE) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_PreserveResult_ int __stdcall Result();
_Win32_AssociatedEnum_(Flags) unsigned __stdcall AssociatedReturn();
struct _Win32_SupportedOS_10240_ Record { _Win32_AssociatedEnum_(Flags) unsigned flags; };
enum _Win32_SupportedOS_10240_ _Win32_AssociatedConstant_(LOOSE_A) _Win32_AssociatedConstant_(LOOSE_B) Flags : unsigned { FlagA = 1 };
enum class [[clang::flag_enum]] ScopedFlags : unsigned { None = 0, A = 1 };
_Win32_SupportedOS_10240_ typedef unsigned NATIVE_ALIAS;
int __stdcall Retval(_Win32_Retval_ int* result);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("DllImport(\"header.dll\"", source);
            Assert.Contains("SetLastError = true", source);
            Assert.Contains("return: global::Windows.Win32.Foundation.Metadata.RAIIFree(\"CloseThing\")", source);
            Assert.Contains("return: global::Windows.Win32.Foundation.Metadata.InvalidHandleValue(-1L)", source);
            Assert.Contains("global::Windows.Win32.Foundation.Metadata.ContainsInteriorPointers", source);
            Assert.Contains("global::Windows.Win32.Foundation.Metadata.Retained", source);
            Assert.Contains("global::System.Runtime.InteropServices.PreserveSig", source);
            Assert.Contains("return: global::Windows.Win32.Foundation.Metadata.AssociatedEnum(\"Flags\")", source);
            Assert.Contains("global::Windows.Win32.Foundation.Metadata.RetVal", source);
            Assert.Contains("AssociatedConstant(\"LOOSE_A\")", source);
            Assert.Contains("AssociatedConstant(\"LOOSE_B\")", source);
            Assert.Contains("ScopedEnum", source);
            Assert.Contains("global::System.Flags", source);
            Assert.Contains("struct NATIVE_ALIAS", fixture.ReadAdditionalTypes());
            Assert.DoesNotContain("SourceLocation(", source);
            Assert.DoesNotContain("NativeAnnotation(", source);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SupportedOSScopesChooseLexicalDefaults(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
int Before();
_Win32_SupportedOS_BEGIN_(WindowsVista)
int Vista();
_Win32_SupportedOS_BEGIN_(Windows7)
int Seven();
_Win32_SupportedOS_Windows8_ int ExplicitLater();
_Win32_SupportedOS_Windows7_ int ExplicitEqual();
_Win32_SupportedOS_Windows2000_ int ExplicitEarlier();
_Win32_SupportedOS_BEGIN_(Windows2000)
int OlderNested();
_Win32_SupportedOS_END_()
int SevenAgain();
_Win32_SupportedOS_END_()
int VistaAgain();
_Win32_SupportedOS_END_()
int After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            AssertSupportedOS(source, "Before", null);
            AssertSupportedOS(source, "Vista", "windows6.0.6000");
            AssertSupportedOS(source, "Seven", "windows6.1");
            AssertSupportedOS(source, "ExplicitLater", "windows8.0");
            AssertSupportedOS(source, "ExplicitEqual", "windows6.1");
            AssertSupportedOS(source, "ExplicitEarlier", "windows5.0");
            AssertSupportedOS(source, "OlderNested", "windows5.0");
            AssertSupportedOS(source, "SevenAgain", "windows6.1");
            AssertSupportedOS(source, "VistaAgain", "windows6.0.6000");
            AssertSupportedOS(source, "After", null);
        }

        [Fact]
        public void SupportedOSScopeAliasesFollowTheActivePreprocessingPath()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FLOOR Windows7
#define BEGIN(os) _Win32_SupportedOS_BEGIN_(os)
#define END() _Win32_SupportedOS_END_()
#define NESTED_BEGIN BEGIN
#define NESTED_END END
#if 0
_Win32_SupportedOS_BEGIN_(UnknownVersion)
_Win32_SupportedOS_END_()
_Win32_SupportedOS_END_()
#endif
#if defined(_M_X64)
NESTED_BEGIN(FLOOR)
#else
_Win32_SupportedOS_BEGIN_(WindowsVista)
#endif
int Scoped();
NESTED_END()
#undef BEGIN
#define BEGIN(os)
#undef END
#define END()
BEGIN(Windows8)
int Unscoped();
END()
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "Scoped", "windows6.1");
            AssertSupportedOS(fixture.ReadSource(), "Unscoped", null);
        }

        [Fact]
        public void SupportedOSControlAliasesKeepExplicitFactsAndDeclarationTiming()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define BEGIN_WITH_OVERRIDE(os) _Win32_SupportedOS_BEGIN_(os) _Win32_SupportedOS_Windows7_
#define END_AFTER_DECLARATION(name) int name(); _Win32_SupportedOS_END_()
BEGIN_WITH_OVERRIDE(WindowsVista) int Explicit();
END_AFTER_DECLARATION(Within)
int After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "Explicit", "windows6.1");
            AssertSupportedOS(fixture.ReadSource(), "Within", "windows6.0.6000");
            AssertSupportedOS(fixture.ReadSource(), "After", null);
        }

        [Fact]
        public void SupportedOSScopesStayInTheirExpansionFile()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""macros.h""
_Win32_SupportedOS_BEGIN_(WindowsVista)
PRODUCE(Parent)
#include ""child.h""
int ParentAgain();
_Win32_SupportedOS_END_()
PRODUCE(After)
", extraSettings: "--traverse\nchild.h\ngrandchild.h\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "macros.h"), @"
#define PRODUCE(name) int name();
#define EXPLICIT(name) _Win32_SupportedOS_Windows7_ _Win32_SetLastError_ int name();
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "child.h"), @"
PRODUCE(Child)
EXPLICIT(ExplicitChild)
_Win32_SupportedOS_BEGIN_(Windows8)
PRODUCE(ChildScoped)
#include ""grandchild.h""
_Win32_SupportedOS_END_()
PRODUCE(ChildAfter)
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "grandchild.h"), @"
PRODUCE(Grandchild)
EXPLICIT(ExplicitGrandchild)
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            AssertSupportedOS(source, "Parent", "windows6.0.6000");
            AssertSupportedOS(source, "ParentAgain", "windows6.0.6000");
            AssertSupportedOS(source, "After", null);
            AssertSupportedOS(source, "Child", null);
            AssertSupportedOS(source, "ExplicitChild", "windows6.1");
            AssertSupportedOS(source, "ChildScoped", "windows8.0");
            AssertSupportedOS(source, "ChildAfter", null);
            AssertSupportedOS(source, "Grandchild", null);
            AssertSupportedOS(source, "ExplicitGrandchild", "windows6.1");
            Assert.Equal(2, source.Split("SetLastError = true").Length - 1);
        }

        [Fact]
        public void SupportedOSScopesDistinguishRepeatedIncludeInstances()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FLOOR Windows7
#define NAME First
#include ""repeat.h""
#undef NAME
#undef FLOOR
#define FLOOR WindowsVista
#define NAME Second
#include ""repeat.h""
", extraSettings: "--traverse\nrepeat.h\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "repeat.h"), @"
_Win32_SupportedOS_BEGIN_(FLOOR)
int NAME();
_Win32_SupportedOS_END_()
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "First", "windows6.1");
            AssertSupportedOS(fixture.ReadSource(), "Second", "windows6.0.6000");
        }

        [Theory]
        [InlineData("_Win32_SupportedOS_BEGIN_(UnknownVersion)\nint F();\n_Win32_SupportedOS_END_()", "expected string literal")]
        [InlineData("_Win32_SupportedOS_END_()", "with no matching")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();", "unterminated")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n#if 0\n_Win32_SupportedOS_END_()\n#endif", "unterminated")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows8_ int F();\n_Win32_SupportedOS_END_()", "Duplicate")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows7_ int F();\n_Win32_SupportedOS_END_()", "Duplicate")]
        public void MalformedSupportedOSScopesFail(string declarations, string diagnostic)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void SupportedOSScopesCannotCloseAnotherFilesOrIncludeInstancesScope(bool repeatedInclude)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", repeatedInclude ? @"
#define FIRST
#include ""pair.h""
#undef FIRST
#include ""pair.h""
" : @"
_Win32_SupportedOS_BEGIN_(Windows7)
#include ""pair.h""
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "pair.h"), repeatedInclude ? @"
#ifdef FIRST
_Win32_SupportedOS_BEGIN_(Windows7)
#else
_Win32_SupportedOS_END_()
#endif
" : "_Win32_SupportedOS_END_()\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("same file and include instance", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_END_()\nint F();")]
        [InlineData("int F();\n_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_END_()")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\nint F();\n_Win32_SupportedOS_END_()")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_BEGIN_(Windows8)\nint F();\n_Win32_SupportedOS_END_()\n_Win32_SupportedOS_END_()\n_Win32_SupportedOS_Windows7_ int F();")]
        [InlineData("_Win32_SupportedOS_Windows7_ int F();\n_Win32_SupportedOS_BEGIN_(Windows8)\nint F();\n_Win32_SupportedOS_END_()")]
        [InlineData("_Win32_SupportedOS_Windows7_ int F();\n_Win32_SupportedOS_Windows7_ int F();")]
        public void SupportedOSRedeclarationsResolveExplicitFactsBeforeDefaults(string declarations)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "F", "windows6.1");
        }

        [Theory]
        [InlineData("_Win32_SupportedOS_Windows7_ int F();\n_Win32_SupportedOS_Windows8_ int F();")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_BEGIN_(Windows8)\nint F();\n_Win32_SupportedOS_END_()\n_Win32_SupportedOS_END_()")]
        public void ConflictingSupportedOSRedeclarationsFail(string declarations)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("Conflicting 'SupportedOSPlatform'", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        internal static void AssertSupportedOS(string source, string name, string expected)
        {
            var members = CSharpSyntaxTree.ParseText(source).GetRoot().DescendantNodes().OfType<MemberDeclarationSyntax>()
                .Where(node => node switch
                {
                    MethodDeclarationSyntax method => method.Identifier.ValueText == name,
                    BaseTypeDeclarationSyntax type => type.Identifier.ValueText == name,
                    DelegateDeclarationSyntax callback => callback.Identifier.ValueText == name,
                    _ => false,
                }).ToArray();
            Assert.NotEmpty(members);
            foreach (var member in members)
            {
                var attributes = member.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => attribute.Name.ToString().EndsWith(".SupportedOSPlatform", StringComparison.Ordinal)).ToArray();
                if (expected == null)
                    Assert.Empty(attributes);
                else
                    Assert.Equal(expected, ((LiteralExpressionSyntax)Assert.Single(attributes).ArgumentList.Arguments.Single().Expression).Token.ValueText);
            }
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void SupportedOSScopesReachTypedefsAndCppAliases(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
_Win32_SupportedOS_BEGIN_(WindowsVista)
typedef unsigned TOKEN;
typedef int (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
using NUMBER = unsigned;
using CALLBACK = int (__stdcall*)(_Win32_Retained_ void* context, unsigned count);
using CALLBACK_ALIAS = PFN_BASE;
TOKEN UseToken(TOKEN value);
NUMBER UseNumber(NUMBER value);
void UseCallbacks(CALLBACK first, CALLBACK_ALIAS second);
_Win32_SupportedOS_END_()
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource() + fixture.ReadAdditionalTypes();
            foreach (string name in new[] { "TOKEN", "PFN_BASE", "NUMBER", "CALLBACK", "CALLBACK_ALIAS" })
                AssertSupportedOS(source, name, "windows6.0.6000");
            Assert.Contains("NUMBER UseNumber(NUMBER value)", source);
            Assert.Contains("CALLBACK first, CALLBACK_ALIAS second", source);
            Assert.Contains("Retained", source);
        }

        [Theory]
        [InlineData("_Win32_SetLastError_ typedef int Bad;")]
        [InlineData("_Win32_ContainsInteriorPointers_ int Bad(void* buffer);")]
        [InlineData("struct Bad { _Win32_ContainsInteriorPointers_ void* field; };")]
        [InlineData("int Bad(_Win32_ContainsInteriorPointers_ int value);")]
        [InlineData("int _Win32_SetLastError_ Bad();")]
        [InlineData("int __stdcall _Win32_SetLastError_ Bad();")]
        [InlineData("typedef _Win32_SupportedOS_10240_ int Bad;")]
        [InlineData("struct S { unsigned _Win32_AssociatedEnum_(E) value; };")]
        [InlineData("int Bad(_In_ _Win32_ContainsInteriorPointers_ void* value);")]
        [InlineData("int Bad(_In_reads_(count) _Win32_ContainsInteriorPointers_ void* value, unsigned count);")]
        [InlineData("int Bad(_Outptr_ _Win32_ContainsInteriorPointers_ void** value);")]
        [InlineData("int Bad(_Win32_ContainsInteriorPointers_ const void* value);")]
        [InlineData("int Bad(_Win32_ContainsInteriorPointers_ void** value);")]
        [InlineData("int Bad(_In_ _Win32_RAIIFree_(CloseThing) void** value);")]
        [InlineData("_Win32_RAIIFree_(CloseThing) void Bad();")]
        [InlineData("#define _Win32_Unknown_ _WIN32META_ANNOTATION_(\"Alien\")\n#define ALIAS _Win32_Unknown_\nALIAS int Bad();")]
        [InlineData("#define _Win32_Unknown_ _WIN32META_ANNOTATION_(\"Alien\")\n#define FIRST _Win32_Unknown_\n#define SECOND FIRST\nSECOND int Bad();")]
        [InlineData("_Win32_SupportedOS_10240_ typedef int VALUES[4];")]
        [InlineData("struct S { _Win32_SupportedOS_Windows7_ int field; };")]
        [InlineData("int Bad(_Win32_SupportedOS_Windows7_ int value);")]
        [InlineData("_Win32_SupportedOS_Windows7_ int variable;")]
        [InlineData("_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows7_ int Bad();")]
        [InlineData("int Bad(_Win32_Retained_ _Win32_Retained_ void* value);")]
        [InlineData("#define DOUBLE _Win32_Retained_ _Win32_Retained_\nint Bad(DOUBLE void* value);")]
        [InlineData("int Bad(_Win32_Retval_ _Win32_Retval_ int* value);")]
        [InlineData("#define DOUBLE _Win32_Retval_ _Win32_Retval_\nint Bad(DOUBLE int* value);")]
        [InlineData("int Bad(void*) _Win32_SetLastError_;")]
        [InlineData("#define _Win32_Unknown_ _WIN32META_ANNOTATION_(\"Alien\")\n_Win32_Unknown_ int Bad();")]
        [InlineData("_WIN32META_ANNOTATION_(\"Alien\") int Bad();")]
        public void NativeValidationFailsBeforeProjection(string declaration)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void InvalidMacrosUseDeclarationTimeExpansion()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define INVALID_VALUE (~0)
_Win32_RAIIFree_(CloseThing, INVALID_VALUE) long long Before();
#undef INVALID_VALUE
#define INVALID_VALUE 7
_Win32_RAIIFree_(CloseThing, INVALID_VALUE) long long After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("InvalidHandleValue(-1L)", source);
            Assert.Contains("InvalidHandleValue(7L)", source);
        }

        [Fact]
        public void RedefinedMacroAliasesDoNotInheritOldOwnership()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define CUSTOM _Win32_SetLastError_
#define ALIAS CUSTOM
ALIAS int Before();
#undef CUSTOM
#define CUSTOM
ALIAS int After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(1, fixture.ReadSource().Split("SetLastError = true").Length - 1);
        }

        [Theory]
        [InlineData(@"
#define PRODUCERS _Win32_RAIIFree_(CloseFirst, 0) void* First(); _Win32_RAIIFree_(CloseSecond, 7) void* Second();
PRODUCERS
")]
        [InlineData(@"
#define PRODUCER(name, cleanup, invalid) _Win32_RAIIFree_(cleanup, invalid) void* name();
PRODUCER(First, CloseFirst, 0)
PRODUCER(Second, CloseSecond, 7)
")]
        public void MacroDeclarationsKeepDistinctNativeOwners(string declarations)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().ToDictionary(method => method.Identifier.ValueText);
            Assert.Contains("RAIIFree(\"CloseFirst\")", methods["First"].ToString());
            Assert.Contains("InvalidHandleValue(0L)", methods["First"].ToString());
            Assert.Contains("RAIIFree(\"CloseSecond\")", methods["Second"].ToString());
            Assert.Contains("InvalidHandleValue(7L)", methods["Second"].ToString());
        }

        [Fact]
        public void MacroFieldsKeepDistinctNativeOwners()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIELDS _Win32_AssociatedEnum_(FirstEnum) unsigned first; _Win32_AssociatedEnum_(SecondEnum) unsigned second;
struct Record { FIELDS };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var fields = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<FieldDeclarationSyntax>().ToDictionary(field => field.Declaration.Variables.Single().Identifier.ValueText);
            Assert.Contains("AssociatedEnum(\"FirstEnum\")", fields["first"].ToString());
            Assert.Contains("AssociatedEnum(\"SecondEnum\")", fields["second"].ToString());
        }

        [Fact]
        public void LineDirectivesDoNotChangeNativeAnnotationOwnership()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#line 900 ""generated.idl""
_Win32_RAIIFree_(CloseThing, 0) void* Produce();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("RAIIFree(\"CloseThing\")", fixture.ReadSource());
            Assert.Contains("InvalidHandleValue(0L)", fixture.ReadSource());
        }

        [Theory]
        [InlineData("[[nodiscard]]")]
        [InlineData("[[deprecated(\"legacy\")]]")]
        [InlineData("__declspec(deprecated(\"legacy\"))")]
        [InlineData("__attribute__((warn_unused_result))")]
        public void OtherPrefixAttributesCanPrecedeMetadata(string prefix)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                $"{prefix} _Win32_RAIIFree_(CloseThing, 0) void* Produce();");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("RAIIFree(\"CloseThing\")", fixture.ReadSource());
        }

        [Fact]
        public void PrefixAttributeAtStartOfHeaderKeepsItsDeclaration()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "");
            string annotations = Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "test.cpp"),
                $"#include \"{annotations.Replace('\\', '/')}\"\n#include \"test.h\"\n");
            File.WriteAllText(fixture.Header, "[[nodiscard]] _Win32_RAIIFree_(CloseThing, 0) void* Produce();");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("InvalidHandleValue(0L)", fixture.ReadSource());
        }

        [Theory]
        [InlineData("_Win32_SetLastError_")]
        [InlineData("_Win32_ImportLibrary_(\"header.dll\")")]
        public void ImportFactsOnInlineDefinitionsFailRatherThanDisappear(string annotation)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                $"{annotation} inline int F() {{ return 0; }}");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("_Win32_SetLastError_ int F();\nint F();")]
        [InlineData("int F();\n_Win32_SetLastError_ int F();")]
        [InlineData("enum class E : unsigned;\nenum class E : unsigned { A = 1 };")]
        [InlineData("int F(_Win32_Retained_ void* value);\nint F(void* value);")]
        public void RedeclarationsKeepCanonicalAnnotationFacts(string declarations)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            if (declarations.Contains("enum class", StringComparison.Ordinal))
                Assert.Contains("ScopedEnum", source);
            else if (declarations.Contains("Retained", StringComparison.Ordinal))
                Assert.Contains("Retained", source);
            else
                Assert.Contains("SetLastError = true", source);
        }

        [Fact]
        public void InvalidValueEvaluationPreservesOriginalHeaderBytes()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_RAIIFree_(CloseThing, (1 ^ 2)) long long Produce();");
            byte[] original = Encoding.UTF8.GetBytes(File.ReadAllText(fixture.Header)).Concat(new byte[] { 10, 47, 47, 32, 0x82, 0xA0, 10 }).ToArray();
            File.WriteAllBytes(fixture.Header, original);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(original, File.ReadAllBytes(fixture.Header));
            Assert.Contains("InvalidHandleValue(3L)", fixture.ReadSource());
            Assert.DoesNotContain("CppAttributeList", fixture.ReadSource());
        }

        [Fact]
        public void UnresolvedInvalidValueFailsRatherThanDefaulting()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_RAIIFree_(CloseThing, UNKNOWN_VALUE) void* Bad();");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("1.5")]
        [InlineData("runtime_value()")]
        [InlineData("LATER_VALUE")]
        public void NonConstantOrLaterInvalidValuesFail(string invalid)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", $@"
int runtime_value();
_Win32_RAIIFree_(CloseThing, {invalid}) long long Before();
const int LATER_VALUE = 7;
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
        }

        [Fact]
        public void TypedefFactsAndUseSitesSurvive()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_SupportedOS_10240_ _Win32_AlsoUsableFor_(OTHER_TOKEN)
typedef unsigned long TOKEN;
TOKEN UseToken(TOKEN value, TOKEN* output);
_Win32_SupportedOS_10240_
typedef int (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
_Win32_SupportedOS_Windows7_
typedef PFN_BASE PFN_ALIAS;
int UseCallback(PFN_ALIAS callback);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = File.ReadAllText(fixture.Output);
            string aliases = File.ReadAllText(Path.ChangeExtension(fixture.Output, ".header-types.cs"));
            Assert.Contains("TOKEN UseToken(TOKEN value", source);
            Assert.Contains("TOKEN* output", source);
            Assert.Contains("AlsoUsableFor(\"OTHER_TOKEN\")", aliases);
            Assert.Contains("uint Value", aliases);
            Assert.Contains("PFN_ALIAS(", source);
            Assert.Contains("void* context", source);
            Assert.Contains("uint count", source);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", source);
        }

        [Fact]
        public void RecordTypedefsKeepTheirOwnFacts()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_SupportedOS_10240_
typedef struct _PRIMARY { unsigned value; } PRIMARY;
_Win32_SupportedOS_Windows7_ _Win32_AlsoUsableFor_(PRIMARY)
typedef PRIMARY DISTINCT;
DISTINCT UseAlias(DISTINCT value, DISTINCT* output);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = File.ReadAllText(fixture.Output);
            string aliases = File.ReadAllText(Path.ChangeExtension(fixture.Output, ".header-types.cs"));
            Assert.Contains("DISTINCT UseAlias(DISTINCT value", source);
            Assert.Contains("DISTINCT* output", source);
            Assert.Contains("struct DISTINCT", aliases);
            Assert.Contains("PRIMARY Value", aliases);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", aliases);
            Assert.Contains("AlsoUsableFor(\"PRIMARY\")", aliases);
        }

        [Theory]
        [InlineData("_Inout_")]
        [InlineData("_Out_writes_(count)")]
        public void CallerOwnedBufferSalIsPreserved(string sal)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                $"int Buffer({sal} _Win32_ContainsInteriorPointers_ void* value, unsigned count);");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = File.ReadAllText(fixture.Output);
            Assert.Contains("ContainsInteriorPointers", source);
            Assert.Contains("CppAttributeList", source);
            Assert.Contains("Name=SAL_name", source);
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void DerivedRemapsDoNotOverrideAuthoredSettings(bool annotationsEnabled)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct _PRIVATE_RECORD { int value; };
struct EXCLUDED_RECORD { int value; };
struct DERIVED_ONLY_RECORD { int value; };
typedef struct _CURRENT_RECORD { int value; } CURRENT_RECORD;
", annotationsEnabled: annotationsEnabled, extraSettings: @"--auto-remaps-file
derived.rsp
--remap
_PRIVATE_RECORD=AUTHORED_RECORD
--exclude
EXCLUDED_RECORD
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "derived.rsp"), @"--remap
_PRIVATE_RECORD=DERIVED_RECORD
--exclude
DERIVED_ONLY_RECORD
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var names = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<StructDeclarationSyntax>().Select(node => node.Identifier.ValueText).ToArray();
            Assert.Contains("AUTHORED_RECORD", names);
            Assert.Contains("CURRENT_RECORD", names);
            Assert.DoesNotContain("DERIVED_RECORD", names);
            Assert.DoesNotContain("EXCLUDED_RECORD", names);
            Assert.Equal(annotationsEnabled, names.Contains("DERIVED_ONLY_RECORD"));
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void MissingDerivedRemapsFailExplicitly(bool annotationsEnabled)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "int F();",
                annotationsEnabled: annotationsEnabled, extraSettings: "--auto-remaps-file\nmissing.rsp\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Auto-remaps response file not found.", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void SuccessfulScrapeRemovesObsoleteDiscoveries()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "int F();",
                extraSettings: "--exclude-auto-remap\n__NSConstantString_tag\n");
            string remaps = Path.Combine(fixture.DirectoryPath, "remaps.txt");
            File.WriteAllText(remaps, "OLD_CALLBACK=LPOLD_CALLBACK\nREDUCE_PTR_LEVEL:LPOLD_CALLBACK\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.False(File.Exists(remaps), File.Exists(remaps) ? File.ReadAllText(remaps) : "");
        }

        [Theory]
        [InlineData("--config\nparse-win32-annotations\n")]
        [InlineData("--with-type\nTYPE=uint\n")]
        public void DerivedRemapsCannotSupplyOtherConfiguration(string settings)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "int F();",
                annotationsEnabled: false, extraSettings: "--auto-remaps-file\nderived.rsp\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "derived.rsp"), settings);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Unsupported auto-remaps option:", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void MissingDerivedRemapsPathFailsExplicitly()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "int F();",
                extraSettings: "--auto-remaps-file\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Missing path for --auto-remaps-file.", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void DiscoveryUsesAuthoredSettingsNotCachedBindingSettings(bool authoredAliasExcluded)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct _RECORD { int value; } RECORD;
typedef int (__stdcall SIMPLE_CALLBACK)(int value);
typedef SIMPLE_CALLBACK* LPSIMPLE_CALLBACK;
int __stdcall UseCallback(LPSIMPLE_CALLBACK callback);
", annotationsEnabled: false, extraSettings: "--auto-remaps-file\nderived.rsp\n"
                + (authoredAliasExcluded ? "--exclude\nLPSIMPLE_CALLBACK\n" : ""));
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "derived.rsp"), @"--remap
_RECORD=RECORD
SIMPLE_CALLBACK=LPSIMPLE_CALLBACK
--exclude
LPSIMPLE_CALLBACK
");
            string firstDiscovery = null;
            for (int repeat = 0; repeat < 2; repeat++)
            {
                Assert.True(fixture.Run() == 0, fixture.Diagnostics);
                string discovery = File.ReadAllText(Path.Combine(fixture.DirectoryPath, "remaps.txt"));
                Assert.Contains("_RECORD=RECORD|HEADER:", discovery);
                foreach (string row in new[] { "SIMPLE_CALLBACK=LPSIMPLE_CALLBACK", "FNPTR_EXCLUDE:LPSIMPLE_CALLBACK", "REDUCE_PTR_LEVEL:LPSIMPLE_CALLBACK" })
                    Assert.Equal(!authoredAliasExcluded, discovery.Contains(row, StringComparison.Ordinal));
                if (repeat == 0)
                    firstDiscovery = discovery;
                else
                    Assert.Equal(firstDiscovery, discovery);
            }
        }

        internal sealed class NativeFixture : IDisposable
        {
            internal NativeFixture(string architecture, string target, string declarations, bool annotationsEnabled = true,
                string libraryPath = "scan.dll", bool multipleFiles = false, string extraSettings = "")
            {
                string annotations = Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h");
                if (!File.Exists(annotations))
                    throw new FileNotFoundException("Annotation header not found.", annotations);
                DirectoryPath = Path.Combine(Path.GetTempPath(), "win32-annotations-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(DirectoryPath);
                Header = Path.Combine(DirectoryPath, "test.h");
                string sal = Path.Combine(AppContext.BaseDirectory, "assets", "sal.h");
                File.WriteAllText(Header, $"#include \"{annotations.Replace('\\', '/')}\"\n#include \"{sal.Replace('\\', '/')}\"\n" + declarations);
                string main = Path.Combine(DirectoryPath, "test.cpp");
                File.WriteAllText(main, "#include \"test.h\"\n");
                Output = multipleFiles ? Path.Combine(DirectoryPath, architecture) : Path.Combine(DirectoryPath, architecture, "Bindings.cs");
                string rsp = Path.Combine(DirectoryPath, "test.rsp");
                File.WriteAllText(rsp, $@"--file
{main}
--output
{Output}
--namespace
Test
--headerFile
{Path.Combine(AppContext.BaseDirectory, "assets", "scraper.header.txt")}
--include-directory
{Path.Combine(AppContext.BaseDirectory, "assets")}
--traverse
{Header}
--libraryPath
{libraryPath}
--methodClassName
Apis
--config
compatible-codegen
generate-cpp-attributes
{(multipleFiles ? "multi-file" : "")}
{(annotationsEnabled ? "parse-win32-annotations" : "")}
--additional=--target={target}
-D_USE_DECLSPECS_FOR_SAL=1
-D_PREFAST_=1
-Wno-pragma-once-outside-header
{extraSettings}
");
                Arguments = new[] { Path.Combine(DirectoryPath, "remaps.txt"), "@" + rsp };
            }

            internal string DirectoryPath { get; }
            internal string Header { get; }
            internal string Output { get; }
            private string[] Arguments { get; }
            internal string Diagnostics { get; private set; }
            internal int Run()
            {
                var start = new ProcessStartInfo("dotnet")
                {
                    WorkingDirectory = DirectoryPath,
                    UseShellExecute = false,
                    RedirectStandardOutput = true,
                    RedirectStandardError = true,
                };
                start.ArgumentList.Add(typeof(RemapDiscovery).Assembly.Location);
                foreach (string argument in Arguments)
                    start.ArgumentList.Add(argument);
                using var process = Process.Start(start);
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                Diagnostics = output.GetAwaiter().GetResult() + error.GetAwaiter().GetResult();
                return process.ExitCode;
            }
            internal string ReadSource() => File.ReadAllText(Output);
            internal string ReadAdditionalTypes() => File.ReadAllText(Path.ChangeExtension(Output, ".header-types.cs"));

            public void Dispose() => Directory.Delete(DirectoryPath, recursive: true);
        }
    }
}
