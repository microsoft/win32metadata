using System;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
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
        [InlineData("ImportLibrary(\"x.dll\", \"#0\")")]
        [InlineData("ImportLibrary(\"x.dll\", \"#65536\")")]
        [InlineData("ImportLibrary(\"x.dll\", \"#not-an-ordinal\")")]
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
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        public void LogicalEnumGroupsUseCompiledValuesAndNativeSignatures(string architecture, string target, string language, string standard)
        {
            using var fixture = new NativeFixture(architecture, target, @"
#define FIRST 0x80000000U
#define SECOND (FIRST | 2U)
#define ALIAS SECOND
_Win32_Enum_(MODE, unsigned, FIRST, SECOND, ALIAS);
_Win32_FlagsEnum_(FLAGS, unsigned, FIRST, SECOND);
_Win32_AssociatedEnum_(MODE) unsigned ReturnMode();
void SetMode(_Win32_AssociatedEnum_(MODE) unsigned value);
struct S { _Win32_AssociatedEnum_(FLAGS) unsigned flags; };
#undef FIRST
#define FIRST 7
", extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string additional = fixture.ReadAdditionalTypes();
            Assert.Contains("enum MODE : uint", additional);
            Assert.Contains("FIRST = unchecked((uint)2147483648UL)", additional);
            Assert.Contains("SECOND = unchecked((uint)2147483650UL)", additional);
            Assert.Contains("ALIAS = unchecked((uint)2147483650UL)", additional);
            Assert.Contains("enum FLAGS : uint", additional);
            Assert.Contains("global::System.Flags", additional);
            Assert.DoesNotContain("struct MODE", additional);
            string source = fixture.ReadSource();
            Assert.Contains("uint ReturnMode()", source);
            Assert.Contains("SetMode(", source);
            Assert.Contains("uint value", source);
            Assert.Contains("AssociatedEnum(\"MODE\")", source);
            Assert.DoesNotContain("NativeAnnotation(", source + additional);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void LogicalEnumGroupRedeclarationsUnionCompiledMembers(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new NativeFixture(architecture, target, @"
#define FIRST 0x80000000U
#define SHARED (-1)
_Win32_Enum_(ERROR_GROUP, unsigned, FIRST, SHARED);
_Win32_AssociatedEnum_(ERROR_GROUP) unsigned GetError();
#include ""extra-errors.h""
", extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "extra-errors.h"), @"
#undef SHARED
#define SHARED 0xFFFFFFFFU
#define EXTRA (FIRST | 4U)
_Win32_Enum_(ERROR_GROUP, unsigned, SHARED, EXTRA);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var group = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>().Single();
            Assert.Equal("ERROR_GROUP", group.Identifier.ValueText);
            Assert.Equal(new[] { "FIRST", "SHARED", "EXTRA" },
                group.Members.Select(member => member.Identifier.ValueText));
            Assert.Contains("EXTRA = unchecked((uint)2147483652UL)", group.ToString());
            Assert.Contains("uint GetError()", fixture.ReadSource());
            Assert.Contains("AssociatedEnum(\"ERROR_GROUP\")", fixture.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void LogicalEnumForwardDeclarationsProjectTraversedCanonicalGroups(
            string architecture, string target, string language, string standard)
        {
            using var fixture = new NativeFixture(architecture, target, @"
typedef unsigned OPTIONS;
typedef unsigned FLAGS;
typedef unsigned EXCLUDED;
_Win32_AssociatedEnum_(OPTIONS) unsigned GetOptions();
void SetOptions(_Win32_AssociatedEnum_(FLAGS) unsigned flags);
#include ""group-values.h""
#include ""group-more.h""
", extraSettings: $"--language\n{language}\n--std\n{standard}\n--exclude\nEXCLUDED\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "group-values.h"), @"
#define FIRST 1U
#define HIGH 0x80000000U
_Win32_Enum_(OPTIONS, unsigned, FIRST);
_Win32_FlagsEnum_(FLAGS, unsigned, FIRST, HIGH);
_Win32_Enum_(EXCLUDED, unsigned, FIRST);
_Win32_Enum_(UNTRAVERSED, unsigned, FIRST);
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "group-more.h"), @"
#define EXTRA (HIGH | FIRST)
_Win32_Enum_(OPTIONS, unsigned, FIRST, EXTRA);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var groups = CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>()
                .ToDictionary(group => group.Identifier.ValueText);
            Assert.Equal(new[] { "FLAGS", "OPTIONS" }, groups.Keys.OrderBy(name => name));
            Assert.Equal(new[] { "FIRST", "EXTRA" },
                groups["OPTIONS"].Members.Select(member => member.Identifier.ValueText));
            Assert.Contains("EXTRA = unchecked((uint)2147483649UL)", groups["OPTIONS"].ToString());
            Assert.Contains("global::System.Flags", groups["FLAGS"].ToString());
            Assert.DoesNotContain("global::System.Flags", groups["OPTIONS"].ToString());
            Assert.All(groups.Values, group => Assert.Contains(": uint", group.ToString()));
            string source = fixture.ReadSource();
            Assert.Contains("uint GetOptions()", source);
            Assert.Contains("uint flags", source);
            Assert.Contains("AssociatedEnum(\"OPTIONS\")", source);
            Assert.Contains("AssociatedEnum(\"FLAGS\")", source);
            Assert.DoesNotContain("NativeAnnotation(", source + fixture.ReadAdditionalTypes());
        }

        [Fact]
        public void LogicalEnumForwardDeclarationsDoNotBorrowUnrelatedGroupIdentities()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef unsigned OPTIONS;
_Win32_AssociatedEnum_(OPTIONS) unsigned GetOptions();
#include ""other-group.h""
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "other-group.h"), @"
namespace Other
{
#define FIRST 1U
_Win32_Enum_(OPTIONS, unsigned, FIRST);
}
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("AssociatedEnum requires a native enum or a _Win32_Enum_/_Win32_FlagsEnum_ group.", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("_Win32_FlagsEnum_(ERROR_GROUP, unsigned, FIRST);", "Conflicting enum group kinds")]
        [InlineData("#undef FIRST\n#define FIRST 2U\n_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);", "Conflicting enum group values")]
        public void LogicalEnumGroupRedeclarationsRejectContradictions(string redeclaration, string diagnostic)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define FIRST 1U\n_Win32_Enum_(ERROR_GROUP, unsigned, FIRST);\n" + redeclaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void NativeEnumFlagsPragmaKeepsTheOriginalEnumDefinitions(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
#pragma clang attribute push (__attribute__((flag_enum)), apply_to = enum)
typedef enum { AnonymousNone = 0, AnonymousFirst = 1, AnonymousSecond = 2 } AnonymousFlags;
enum NamedFlags { NamedNone = 0, NamedFirst = 1, NamedSecond = 2 };
#pragma clang attribute pop
enum Ordinary { OrdinaryFirst = 1 };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var enums = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>().ToArray();
            foreach (string name in new[] { "AnonymousFlags", "NamedFlags" })
                Assert.Contains(Assert.Single(enums.Where(value => value.Identifier.ValueText == name))
                    .AttributeLists.SelectMany(list => list.Attributes),
                    attribute => attribute.Name.ToString().EndsWith("Flags", StringComparison.Ordinal));
            Assert.Empty(Assert.Single(enums.Where(value => value.Identifier.ValueText == "Ordinary")).AttributeLists);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void LogicalEnumGroupsBindAnExistingNativeScalarAlias(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
typedef unsigned EXISTING;
#define FIRST 0x1001U
#define SECOND 0x1002U
_Win32_Enum_(EXISTING, unsigned, FIRST, SECOND);
void Use(EXISTING value);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var group = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadAdditionalTypes()).GetRoot()
                .DescendantNodes().OfType<EnumDeclarationSyntax>());
            Assert.Equal("EXISTING", group.Identifier.ValueText);
            Assert.Equal(new[] { "FIRST", "SECOND" }, group.Members.Select(member => member.Identifier.ValueText));
            Assert.Contains("uint value", fixture.ReadSource());
        }

        [Theory]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::value, _Win32_PreserveResult_);", "declared native interface method")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(Free, _Win32_PreserveResult_);", "declared native interface method")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_SetLastError_);", "not valid on")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_Retained_);", "not valid on")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::Run, );", "at least one metadata annotation")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_PreserveResult_);\n_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_PreserveResult_);", "Duplicate")]
        [InlineData("_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_SupportedOS_Windows7_);\n_WIN32META_ANNOTATE_METHOD_(S::Run, _Win32_SupportedOS_Windows8_);", "Conflicting")]
        [InlineData("_WIN32META_ANNOTATION_(\"Method\", sizeof(&S::Run)) _Win32_PreserveResult_ int NotACarrier;", "metadata-only")]
        [InlineData("_WIN32META_ANNOTATION_(\"Method\") _Win32_PreserveResult_ static const unsigned char _WIN32META_METHOD_bad = 0;", "one compiler-parsed")]
        public void MethodCarriersRejectInvalidFactsAndReferences(string declaration, string diagnostic)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Free();
struct __declspec(uuid(""135cc76d-5edc-468c-b418-060f8c43435c"")) S
{
    int value;
    virtual int __stdcall Run() = 0;
};
" + declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void MethodReferencesAreResolvedByTheOriginalCompilerParse()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_WIN32META_ANNOTATE_METHOD_(Undeclared::Missing, _Win32_PreserveResult_);");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Undeclared", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, true)]
        [InlineData("x86", "i686-pc-windows-msvc", true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true)]
        public void MidlInterfaceTypedefRetainsAvailabilityBeforeAndAfterDefinition(
            string architecture, string target, bool cInterface, bool afterDefinition)
        {
            const string annotation = "typedef _Win32_SupportedOS_WindowsVista_ struct IHoisted IHoisted;\n";
            string definition = @"
struct __declspec(uuid(""9cfbc4aa-ae13-452e-b020-a9c40e99d34f"")) IHoisted
{
#if defined(CINTERFACE)
    void* lpVtbl;
#else
    virtual int __stdcall Run() = 0;
#endif
};
";
            using var fixture = new NativeFixture(architecture, target,
                "typedef struct IHoisted IHoisted;\n" +
                (afterDefinition ? definition + annotation : annotation + definition),
                extraSettings: cInterface ? "--additional=-DCINTERFACE\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "IHoisted", "windows6.0.6000");
        }

        [Fact]
        public void LateMidlRecordAttributeStillFailsInsteadOfSilentlyDroppingFacts()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct IHoisted { int value; };
struct _Win32_SupportedOS_WindowsVista_ IHoisted;
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("attribute declaration must precede definition", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void MidlInterfaceTypedefDoesNotAddFactsWithMetadataDisabled(bool cInterface)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct IHoisted IHoisted;
struct IHoisted { int value; };
typedef _Win32_SupportedOS_WindowsVista_ struct IHoisted IHoisted;
", annotationsEnabled: false, extraSettings: cInterface ? "--additional=-DCINTERFACE\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "IHoisted", null);
        }

        [Fact]
        public void MidlInterfaceTypedefDoesNotOverwriteConflictingRecordFacts()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct IHoisted IHoisted;
struct _Win32_SupportedOS_Windows7_ IHoisted { int value; };
typedef _Win32_SupportedOS_WindowsVista_ struct IHoisted IHoisted;
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Conflicting 'SupportedOSPlatform'", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("c++", "c++17", true, true, false, true)]
        [InlineData("c++", "c++17", true, true, true, true)]
        [InlineData("c++", "c++17", false, true, false, false)]
        [InlineData("c++", "c++17", false, true, true, false)]
        [InlineData("c++", "c++17", true, false, false, false)]
        [InlineData("c++", "c++17", true, false, true, false)]
        [InlineData("c", "c17", true, true, false, false)]
        [InlineData("c", "c17", false, true, false, false)]
        public void MidlInterfaceQuoteGuardKeepsCarrierMetadataOnly(
            string language, string standard, bool enabled, bool clang, bool cInterface, bool active)
        {
            string header = File.ReadAllText(Path.Combine(AppContext.BaseDirectory, "assets", "win32metadata_annotations.h"));
            var guard = Regex.Match(header,
                @"#define _Win32_AnnotateInterface_\(name, annotation\) \\\r?\n\s+cpp_quote\(""([^""]+)""\)");
            Assert.True(guard.Success, "The original-IDL interface carrier must emit an explicit metadata guard.");
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef struct IHoisted IHoisted;
struct IHoisted { int value; };
" + guard.Groups[1].Value + @"
typedef _Win32_SupportedOS_WindowsVista_ struct IHoisted IHoisted;
const int CARRIER_ACTIVE = 1;
#else
const int CARRIER_ACTIVE = 0;
#endif
", annotationsEnabled: enabled,
                extraSettings: $"--language\n{language}\n--std\n{standard}\n" +
                    (clang ? "" : "--additional=-U__clang__\n") +
                    (cInterface ? "--additional=-DCINTERFACE\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("CARRIER_ACTIVE = " + (active ? "1" : "0"), source);
            AssertSupportedOS(source, "IHoisted", active ? "windows6.0.6000" : null);
        }

        [Fact]
        public void HoistedMidlMethodAttributesDoNotAnnotateInterfaceIdentifiers()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_Win32_PreserveResult_
extern ""C"" const int IID_MidlMethod;
struct __declspec(uuid(""70873e41-fc54-4a7c-bf68-6f43263e6b81"")) IMidlMethod
{
    virtual int __stdcall Skip(unsigned count) = 0;
};
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("IID_MidlMethod", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("c", "c11", true, false)]
        [InlineData("c++", "c++17", false, false)]
        [InlineData("c++", "c++17", true, true)]
        public void InactiveMethodCarriersDoNotReferenceOrDeclareSymbols(
            string language, string standard, bool annotationsEnabled, bool cInterface)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
_WIN32META_ANNOTATE_METHOD_(Undeclared::Missing, _Win32_PreserveResult_);
enum { _WIN32META_METHOD_0 = 7 };
int F();
", annotationsEnabled: annotationsEnabled,
                extraSettings: $"--language\n{language}\n--std\n{standard}\n" + (cInterface ? "--additional=-DCINTERFACE\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
        }

        [Theory]
        [InlineData(true)]
        [InlineData(false)]
        public void LogicalGroupAnnotationsDoNotDependOnAttributeOrder(bool associationFirst)
        {
            string group = "_Win32_Enum_(OPTIONS, unsigned, FIRST, SECOND)";
            string declaration = associationFirst
                ? "_Win32_AssociatedConstant_(LOOSE) " + group + ";"
                : "typedef _WIN32META_ANNOTATION_(\"Enum(FIRST, SECOND)\", FIRST, SECOND) " +
                    "_Win32_AssociatedConstant_(LOOSE) unsigned OPTIONS;";
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define FIRST 1\n#define SECOND 2\n" + declaration);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadAdditionalTypes();
            Assert.Contains("enum OPTIONS : uint", source);
            Assert.Contains("AssociatedConstant(\"LOOSE\")", source);
        }

        [Fact]
        public void RemovingAGroupRemovesItsStaleGeneratedType()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#define FIRST 1\n_Win32_Enum_(OPTIONS, unsigned, FIRST);\nint F();");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("enum OPTIONS", fixture.ReadAdditionalTypes());
            File.WriteAllText(fixture.Header, "int F();\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
        }

        [Fact]
        public void WideEnumArgumentsAreNotSilentlyTruncated()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum class WIDE : unsigned __int128 { Invalid = (unsigned __int128)1 << 100 };
_Win32_RAIIFree_(CloseThing, WIDE::Invalid) void* Bad();
", extraSettings: "--exclude\nWIDE\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("at most 64 bits", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void DisabledGroupMacrosIntroduceNoSymbols(string architecture, string target, string language, string standard)
        {
            using var fixture = new NativeFixture(architecture, target, @"
#define FIRST 1
#define SECOND 2
_Win32_Enum_(MODE, unsigned, FIRST, SECOND);
_Win32_FlagsEnum_(FLAGS, unsigned, FIRST, SECOND);
enum { MODE = 3, FLAGS = 4 };
int F(_Win32_AssociatedEnum_(MODE) unsigned value);
", annotationsEnabled: false, extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("MODE = 3", source);
            Assert.Contains("FLAGS = 4", source);
            Assert.DoesNotContain("AssociatedEnum", source);
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".header-types.cs")));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void TypedRaiiReadsTheOriginalExpressionContext(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
namespace Values { constexpr int Invalid = (1 << 5) ^ 1; }
struct Limits { static constexpr int Invalid = -3; };
#define CLEANUP CloseThing
_Win32_RAIIFree_Handle_(CLEANUP) void* CommonHandle();
_Win32_RAIIFree_(CLEANUP, Values::Invalid, Limits::Invalid, ~0ULL) void* OtherHandle();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            Assert.Contains("RAIIFree(\"CloseThing\")", source);
            foreach (long value in new long[] { -1, 0, 33, -3 })
                Assert.Contains($"InvalidHandleValue({value}L)", source);
            Assert.DoesNotContain("expanded", source);
            Assert.DoesNotContain("CppAttributeList", source);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17", true)]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11", true)]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17", false)]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11", false)]
        public void ImportedCleanupReferencesPreserveNativeDiagnosticPolicy(string architecture, string target,
            string language, string standard, bool suppressNativeWarnings)
        {
            using var fixture = new NativeFixture(architecture, target, @"
__declspec(dllimport) int __stdcall ImportedCleanup(void*);
__attribute__((annotate(""NativeSAL""))) struct NATIVE_IGNORED { int value; };
_Win32_RAIIFree_Handle_(ImportedCleanup) void* CommonHandle(void);
_Win32_RAIIFree_(ImportedCleanup) void* WithoutInvalidValues(void);
__attribute__((annotate(""NativeSAL""))) struct NATIVE_IGNORED_AFTER { int value; };
", extraSettings: $"--language\n{language}\n--std\n{standard}\n" +
                (suppressNativeWarnings ? "--additional\n-Wno-ignored-attributes\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(suppressNativeWarnings ? 0 : 2,
                fixture.Diagnostics.Split("attribute 'annotate' is ignored").Length - 1);
            string source = fixture.ReadSource();
            Assert.Equal(2, source.Split("RAIIFree(\"ImportedCleanup\")").Length - 1);
            Assert.Contains("InvalidHandleValue(-1L)", source);
            Assert.Contains("InvalidHandleValue(0L)", source);
        }

        [Theory]
        [InlineData("_Win32_RAIIFree_(42, 0) void* Bad();")]
        [InlineData("_Win32_RAIIFree_(LaterCleanup, 0) void* Bad();\nint LaterCleanup(void*);")]
        [InlineData("_Win32_RAIIFree_(CloseThing, ((void*)-1)) void* Bad();")]
        [InlineData("_Win32_RAIIFree_(CloseThing, 1.5) void* Bad();")]
        [InlineData("int (*Cleanup)(void*) = CloseThing;\n_Win32_RAIIFree_(Cleanup, 0) void* Bad();")]
        [InlineData("_WIN32META_ANNOTATION_(\"RAIIFree(CloseThing, 0)\") void* Bad();")]
        [InlineData("_Win32_Enum_(E, float, VALUE);")]
        [InlineData("_Win32_Enum_(E, unsigned, VALUE, VALUE);")]
        [InlineData("_Win32_AlsoUsableFor_(OTHER) _Win32_Enum_(E, unsigned, VALUE);")]
        [InlineData("_WIN32META_ANNOTATION_(\"Enum(A, B)\", 1) typedef unsigned E;")]
        [InlineData("_WIN32META_ANNOTATION_(\"Enum(A)\", 1.5) typedef unsigned E;")]
        [InlineData("_Win32_AssociatedEnum_(unsigned) unsigned Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", 0) int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", 65536) int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", -1) int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", \"\") int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", \"#0\") int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", \"#65536\") int Bad();")]
        [InlineData("_Win32_ImportLibrary_(\"x.dll\", \"#bad\") int Bad();")]
        [InlineData("_Win32_ImportLibrary_(L\"x.dll\") int Bad();")]
        public void TypedAnnotationsRejectInvalidCompilerArguments(string declaration)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", "#define VALUE 1\n" + declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("int _Win32_SetLastError_ F();")]
        [InlineData("int __stdcall _Win32_SetLastError_ F();")]
        [InlineData("int F() _Win32_SetLastError_;")]
        public void ValidCompilerAttachmentDoesNotRequireSourceTokenParsing(string declaration)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declaration);
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("SetLastError = true", fixture.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void IgnoredMetadataAttributesFailThroughToolDiagnostics(string architecture, string target,
            string language, string standard)
        {
            using var fixture = new NativeFixture(architecture, target,
                "_Win32_SupportedOS_Windows7_ struct Bad { int value; };",
                extraSettings: $"--language\n{language}\n--std\n{standard}\n--additional\n-Wno-ignored-attributes\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error: attribute 'annotate' is ignored", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("_Win32_SupportedOS_Windows7_ struct Bad { int value; };", "-Wno-ignored-attributes")]
        [InlineData("_Win32_SupportedOS_Windows7_ union Bad { int value; };", "-Wno-everything")]
        [InlineData("_Win32_SupportedOS_Windows7_ enum Bad { Value };", "-Wno-ignored-attributes")]
        [InlineData("#define FIRST _Win32_SupportedOS_Windows7_\n#define SECOND FIRST\nSECOND struct Bad { int value; };", "-Wno-ignored-attributes")]
        public void ToolDiagnosticsRejectIgnoredAnnotationsDespiteWarningSuppression(string declaration, string warningOption)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declaration,
                extraSettings: $"--additional\n{warningOption}\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error: attribute 'annotate' is ignored", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void SharedHeaderLeavesIgnoredAttributePolicyToTheConsumer(bool suppressWarnings)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_SupportedOS_Windows7_ struct Bad { int value; };",
                annotationsEnabled: false,
                extraSettings: "--additional\n-DWIN32METADATA\n" +
                    (suppressWarnings ? "-Wno-ignored-attributes\n" : ""));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Equal(!suppressWarnings,
                fixture.Diagnostics.Contains("warning: attribute 'annotate' is ignored", StringComparison.Ordinal));
            Assert.DoesNotContain("error:", fixture.Diagnostics);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void GlobalWarningSuppressionIsRejectedOnlyForAnnotationParsing(bool annotationsEnabled)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc",
                "_Win32_SupportedOS_Windows7_ struct Bad { int value; };",
                annotationsEnabled: annotationsEnabled, extraSettings: "--additional\n-w\n");
            int exitCode = fixture.Run();
            if (annotationsEnabled)
            {
                Assert.NotEqual(0, exitCode);
                Assert.Contains("-w suppresses ignored metadata attribute diagnostics", fixture.Diagnostics);
                Assert.False(File.Exists(fixture.Output));
            }
            else
            {
                Assert.True(exitCode == 0, fixture.Diagnostics);
                Assert.True(File.Exists(fixture.Output));
            }
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
_Win32_RAIIFree_(CloseThing, 0, -1) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_PreserveResult_ int __stdcall Result();
enum _Win32_SupportedOS_10240_ _Win32_AssociatedConstant_(LOOSE_A) _Win32_AssociatedConstant_(LOOSE_B) Flags : unsigned { FlagA = 1 };
_Win32_AssociatedEnum_(Flags) unsigned __stdcall AssociatedReturn();
struct _Win32_SupportedOS_10240_ Record { _Win32_AssociatedEnum_(Flags) unsigned flags; };
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
        public void SupportedOSScopesAccumulateAndCollapseIdenticalFacts(string architecture, string target)
        {
            using var fixture = new NativeFixture(architecture, target, @"
int Before();
_Win32_SupportedOS_BEGIN_(WindowsVista)
int Vista();
_Win32_SupportedOS_BEGIN_(WindowsVista)
int VistaNested();
_Win32_SupportedOS_WindowsVista_ int VistaExplicit();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_END_()
_Win32_SupportedOS_BEGIN_(Windows7)
int Seven();
_Win32_SupportedOS_Windows7_ int ExplicitEqual();
_Win32_SupportedOS_BEGIN_(Windows7)
int SevenNested();
_Win32_SupportedOS_END_()
int SevenAgain();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_BEGIN_(WindowsVista)
int VistaAgain();
_Win32_SupportedOS_END_()
_Win32_SupportedOS_Windows8_ int ExplicitLater();
_Win32_SupportedOS_Windows2000_ int ExplicitEarlier();
int After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string source = fixture.ReadSource();
            AssertSupportedOS(source, "Before", null);
            AssertSupportedOS(source, "Vista", "windows6.0.6000");
            AssertSupportedOS(source, "VistaNested", "windows6.0.6000");
            AssertSupportedOS(source, "VistaExplicit", "windows6.0.6000");
            AssertSupportedOS(source, "Seven", "windows6.1");
            AssertSupportedOS(source, "ExplicitLater", "windows8.0");
            AssertSupportedOS(source, "ExplicitEqual", "windows6.1");
            AssertSupportedOS(source, "ExplicitEarlier", "windows5.0");
            AssertSupportedOS(source, "SevenNested", "windows6.1");
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
#define BEGIN_WITH_OVERRIDE(os) _Win32_SupportedOS_BEGIN_(os) _Win32_SupportedOS_WindowsVista_
#define END_AFTER_DECLARATION(name) int name(); _Win32_SupportedOS_END_()
BEGIN_WITH_OVERRIDE(WindowsVista) int Explicit();
END_AFTER_DECLARATION(Within)
int After();
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "Explicit", "windows6.0.6000");
            AssertSupportedOS(fixture.ReadSource(), "Within", "windows6.0.6000");
            AssertSupportedOS(fixture.ReadSource(), "After", null);
        }

        [Fact]
        public void SupportedOSScopesPropagateThroughIncludes()
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
#define EXPLICIT(name) _Win32_SupportedOS_WindowsVista_ _Win32_SetLastError_ int name();
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "child.h"), @"
PRODUCE(Child)
EXPLICIT(ExplicitChild)
_Win32_SupportedOS_BEGIN_(WindowsVista)
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
            AssertSupportedOS(source, "Child", "windows6.0.6000");
            AssertSupportedOS(source, "ExplicitChild", "windows6.0.6000");
            AssertSupportedOS(source, "ChildScoped", "windows6.0.6000");
            AssertSupportedOS(source, "ChildAfter", "windows6.0.6000");
            AssertSupportedOS(source, "Grandchild", "windows6.0.6000");
            AssertSupportedOS(source, "ExplicitGrandchild", "windows6.0.6000");
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
        [InlineData("_Win32_SupportedOS_BEGIN_(UnknownVersion)\nint F();\n_Win32_SupportedOS_END_()", "expected")]
        [InlineData("_Win32_SupportedOS_END_()", "with no matching")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();", "unterminated")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n#if 0\n_Win32_SupportedOS_END_()\n#endif", "unterminated")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows8_ int F();\n_Win32_SupportedOS_END_()", "Conflicting")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n_Win32_SupportedOS_BEGIN_(Windows8)\nint F();\n_Win32_SupportedOS_END_()\n_Win32_SupportedOS_END_()", "Conflicting")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\n_Win32_SupportedOS_Windows2000_ int F();\n_Win32_SupportedOS_END_()", "Conflicting")]
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
        public void ClangCanBalanceSupportedOSScopesAcrossIncludes(bool repeatedInclude)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", repeatedInclude ? @"
#define FIRST
#include ""pair.h""
#undef FIRST
#include ""pair.h""
int After();
" : @"
_Win32_SupportedOS_BEGIN_(Windows7)
int Within();
#include ""pair.h""
int After();
");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "pair.h"), repeatedInclude ? @"
#ifdef FIRST
_Win32_SupportedOS_BEGIN_(Windows7)
int Within();
#else
_Win32_SupportedOS_END_()
#endif
" : "_Win32_SupportedOS_END_()\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            AssertSupportedOS(fixture.ReadSource(), "After", null);
        }

        [Theory]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_END_()\nint F();")]
        [InlineData("int F();\n_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\n_Win32_SupportedOS_END_()")]
        [InlineData("_Win32_SupportedOS_BEGIN_(Windows7)\nint F();\nint F();\n_Win32_SupportedOS_END_()")]
        [InlineData("_Win32_SupportedOS_Windows7_ int F();\n_Win32_SupportedOS_Windows7_ int F();")]
        [InlineData("_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows7_ int F();")]
        public void SupportedOSRedeclarationsCollapseIdenticalFacts(string declarations)
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
        [InlineData("int Bad(_Win32_Retained_ _Win32_Retained_ void* value);")]
        [InlineData("#define DOUBLE _Win32_Retained_ _Win32_Retained_\nint Bad(DOUBLE void* value);")]
        [InlineData("int Bad(_Win32_Retval_ _Win32_Retval_ int* value);")]
        [InlineData("#define DOUBLE _Win32_Retval_ _Win32_Retval_\nint Bad(DOUBLE int* value);")]
        [InlineData("#define _Win32_Unknown_ _WIN32META_ANNOTATION_(\"Alien\")\n_Win32_Unknown_ int Bad();")]
        [InlineData("_WIN32META_ANNOTATION_(\"Alien\") int Bad();")]
        public void NativeValidationFailsBeforeProjection(string declaration)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declaration);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("error", fixture.Diagnostics);
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

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, true)]
        [InlineData("x86", "i686-pc-windows-msvc", true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true)]
        public void MacroCallbackParametersKeepTheirNativeMethodOwner(
            string architecture, string target, bool sharedRecordMacro, bool annotated)
        {
            string methods = @"
#define METHODS \
virtual int __stdcall First(FIRST_FACT void** value) = 0; \
virtual int __stdcall Second(SECOND_FACT void** value) = 0;
";
            methods = methods.Replace("FIRST_FACT", annotated ? "_Win32_RAIIFree_(CloseFirst, 0)" : "")
                .Replace("SECOND_FACT", annotated ? "_Win32_RAIIFree_(CloseSecond, 7)" : "");
            using var fixture = new NativeFixture(architecture, target,
                methods + (sharedRecordMacro ? @"
#define RECORDS struct IProbe { METHODS }; struct ISecondProbe { METHODS };
RECORDS
" : "\nstruct IProbe { METHODS };\n"));
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var callbacks = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<DelegateDeclarationSyntax>().ToArray();
            Assert.Equal(sharedRecordMacro ? 4 : 2, callbacks.Length);
            Assert.Contains(callbacks, callback => callback.Identifier.ValueText.EndsWith("First", StringComparison.Ordinal));
            Assert.Contains(callbacks, callback => callback.Identifier.ValueText.EndsWith("Second", StringComparison.Ordinal));
            foreach (var callback in callbacks)
            {
                bool first = callback.Identifier.ValueText.EndsWith("First", StringComparison.Ordinal);
                var parameter = callback.ParameterList.Parameters.Single(candidate => candidate.Identifier.ValueText == "value");
                Assert.Equal("int", callback.ReturnType.ToString());
                Assert.Equal("void**", parameter.Type.ToString());
                if (annotated)
                {
                    Assert.Contains(first ? "RAIIFree(\"CloseFirst\")" : "RAIIFree(\"CloseSecond\")", parameter.ToString());
                    Assert.Contains(first ? "InvalidHandleValue(0L)" : "InvalidHandleValue(7L)", parameter.ToString());
                }
                else
                    Assert.DoesNotContain("RAIIFree", parameter.ToString());
                Assert.DoesNotContain(first ? "CloseSecond" : "CloseFirst", parameter.ToString());
            }
        }

        [Fact]
        public void InheritedMacroCallbacksKeepTheirOriginalNativeMethodOwner()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define RECORDS \
struct IBase { virtual int __stdcall First(_Win32_RAIIFree_(CloseFirst, 0) void** value) = 0; }; \
struct IDerived : IBase { virtual int __stdcall Second(_Win32_RAIIFree_(CloseSecond, 7) void** value) = 0; };
RECORDS
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var callbacks = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<DelegateDeclarationSyntax>().ToArray();
            Assert.True(callbacks.Length >= 2);
            Assert.Contains(callbacks, callback => callback.Identifier.ValueText.EndsWith("First", StringComparison.Ordinal));
            Assert.Contains(callbacks, callback => callback.Identifier.ValueText.EndsWith("Second", StringComparison.Ordinal));
            foreach (var callback in callbacks)
            {
                bool first = callback.Identifier.ValueText.EndsWith("First", StringComparison.Ordinal);
                var parameter = callback.ParameterList.Parameters.Single(candidate => candidate.Identifier.ValueText == "value");
                Assert.Contains(first ? "RAIIFree(\"CloseFirst\")" : "RAIIFree(\"CloseSecond\")", parameter.ToString());
                Assert.DoesNotContain(first ? "CloseSecond" : "CloseFirst", parameter.ToString());
            }
        }

        [Fact]
        public void AmbiguousMacroCallbackNamesStillFail()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define METHODS \
virtual int __stdcall First(_Win32_RAIIFree_(CloseFirst, 0) void** value) = 0; \
virtual int __stdcall Second(_Win32_RAIIFree_(CloseSecond, 7) void** value) = 0;
struct IProbe { METHODS };
", extraSettings: "--remap\nFirst=Same\nSecond=Same\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Source-location transport is ambiguous", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void UnprojectedFunctionPointerFieldParametersStillFail()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define METHODS \
int (__stdcall* First)(_Win32_RAIIFree_(CloseFirst, 0) void** value); \
int (__stdcall* Second)(_Win32_RAIIFree_(CloseSecond, 7) void** value);
struct IProbe { METHODS };
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("were not projected", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void MacroFieldsKeepDistinctNativeOwners()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIELDS _Win32_AssociatedEnum_(FirstEnum) unsigned first; _Win32_AssociatedEnum_(SecondEnum) unsigned second;
enum FirstEnum { FirstValue = 1 };
enum SecondEnum { SecondValue = 2 };
struct Record { FIELDS };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var fields = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<FieldDeclarationSyntax>().ToDictionary(field => field.Declaration.Variables.Single().Identifier.ValueText);
            Assert.Contains("AssociatedEnum(\"FirstEnum\")", fields["first"].ToString());
            Assert.Contains("AssociatedEnum(\"SecondEnum\")", fields["second"].ToString());
        }

        [Fact]
        public void MacroConstantsKeepDistinctNativeOwners()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define CONSTANTS _Win32_SupportedOS_Windows7_ const unsigned FIRST = 1; _Win32_SupportedOS_Windows8_ const unsigned SECOND = 2;
CONSTANTS
#define MEMBERS FirstMember _Win32_SupportedOS_Windows7_ = 1, SecondMember _Win32_SupportedOS_Windows8_ = 2
enum Constants { MEMBERS };
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var root = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot();
            var fields = root.DescendantNodes().OfType<FieldDeclarationSyntax>()
                .ToDictionary(field => field.Declaration.Variables.Single().Identifier.ValueText);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fields["FIRST"].ToString());
            Assert.Contains("SupportedOSPlatform(\"windows8.0\")", fields["SECOND"].ToString());
            var members = root.DescendantNodes().OfType<EnumMemberDeclarationSyntax>()
                .ToDictionary(member => member.Identifier.ValueText);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", members["FirstMember"].ToString());
            Assert.Contains("SupportedOSPlatform(\"windows8.0\")", members["SecondMember"].ToString());
        }

        [Theory]
        [InlineData("enum E { Value _Win32_SetLastError_ = 1 };", "not valid")]
        [InlineData("_Win32_SupportedOS_Windows8_ int mutableValue;", "not valid")]
        [InlineData("int F(_Win32_SupportedOS_Windows8_ const int value);", "not valid")]
        [InlineData("void F() { _Win32_SupportedOS_Windows8_ const int localValue = 1; }", "not valid")]
        [InlineData("enum E { Value _Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows8_ = 1 };", "Conflicting")]
        public void ConstantTargetsDoNotRelaxOtherAnnotationRules(string declarations, string diagnostic)
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", declarations);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
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
                $"#include \"{annotations.Replace('\\', '/')}\"\n#include \"cleanup.h\"\n#include \"test.h\"\n");
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
            Assert.Contains("error", fixture.Diagnostics);
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
            Assert.Contains("error", fixture.Diagnostics);
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
            Assert.Contains("error", fixture.Diagnostics);
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

        [Fact]
        public void MidlParameterDirectionIsRetainedAcrossUnannotatedRedeclarations()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Repeated(/* [in] */ unsigned* value);
int Repeated(unsigned* value);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().Where(value => value.Identifier.ValueText == "Repeated").ToArray();
            Assert.Equal(2, methods.Length);
            foreach (var method in methods)
                Assert.Single(method.ParameterList.Parameters.Single().AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => attribute.Name.ToString() == "global::System.Runtime.InteropServices.In"));
        }

        [Fact]
        public void ConflictingMidlParameterDirectionsFailExplicitly()
        {
            using var fixture = new NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Conflicting(/* [in] */ unsigned* value);
int Conflicting(/* [out] */ unsigned* value);
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Conflicting MIDL parameter directions", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
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
                File.WriteAllText(Path.Combine(DirectoryPath, "cleanup.h"),
                    "int CloseThing(void*);\nint CloseFirst(void*);\nint CloseSecond(void*);\n");
                File.WriteAllText(Header, $"#include \"{sal.Replace('\\', '/')}\"\n#include \"cleanup.h\"\n" + declarations);
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
