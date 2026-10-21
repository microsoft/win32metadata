using System;
using System.IO;
using System.Linq;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationCommentTests
    {
        [Theory]
        [InlineData("/* Win32Metadata: record Missing => SupportedOSPlatform(\"windows6.1\") */", "Malformed")]
        [InlineData("/* Win32Metadata: interface ::Missing => SupportedOSPlatform(\"windows6.1\") */", "found 0")]
        [InlineData("/* Win32Metadata: variable ::S => SupportedOSPlatform(\"windows6.1\") */", "Malformed")]
        [InlineData("/* Win32Metadata: record ::S => Unknown */", "Unknown")]
        [InlineData("/* Win32Metadata: record ::S => SupportedOSPlatform(\"windows999\") */", "Unsupported OS")]
        [InlineData("/* Win32Metadata: record ::S => */", "Unknown")]
        [InlineData("/* Win32Metadata: field ::S::shared => AssociatedEnum(E) */", "native field")]
        [InlineData("/* Win32Metadata: function ::S => RAIIFree(CloseThing) */", "native function")]
        [InlineData("/* Win32Metadata: parameter ::F::missing => AssociatedEnum(E) */", "named native parameter")]
        [InlineData("/* Win32Metadata: field ::S::flags => AssociatedEnum(Native::Missing) */", "found 0")]
        [InlineData("/* Win32Metadata: field ::S::flags => AssociatedEnum(NOT_ENUM) */", "requires a native enum")]
        [InlineData("/* Win32Metadata: field ::S::flags => AssociatedEnum(S) */", "requires a native enum")]
        [InlineData("/* Win32Metadata: field ::S::flags => AssociatedEnum(unsigned) */", "native enum or metadata group name")]
        [InlineData("/* Win32Metadata: field ::S::flags => SetLastError */", "not valid")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(Missing) */", "declared native cleanup")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, INVALID) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, 0x0) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, (0)) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, 1 << 2) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, 0U) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: function ::Open => RAIIFree(CloseThing, 9223372036854775808) */", "signed decimal Int64")]
        [InlineData("/* Win32Metadata: field ::S::flags => AssociatedEnum(E) */\n/* Win32Metadata: field ::S::flags => AssociatedEnum(E) */", "Duplicate")]
        [InlineData("/* Win32Metadata: record ::S => SupportedOSPlatform(\"windows6.1\") */\n/* Win32Metadata: record ::S => SupportedOSPlatform(\"windows8.0\") */", "Conflicting")]
        [InlineData("#define UNUSED /* Win32Metadata: field ::S::flags => AssociatedEnum(E) */", "preprocessor directive")]
        [InlineData("#define UNUSED \\\n /* Win32Metadata: field ::S::flags => AssociatedEnum(E) */", "preprocessor directive")]
        [InlineData("// Win32Metadata: record ::S => SupportedOSPlatform(\"windows6.1\")", "Malformed")]
        [InlineData("/* Win32Metadata: return ::Open => PreserveResult */", "not a return annotation")]
        [InlineData("/* Win32Metadata: type ::NOT_ENUM => AlsoUsableFor(Missing) */", "one native type")]
        [InlineData("/* Win32Metadata: enum ::E => AssociatedConstant(Missing) */", "one native constant")]
        [InlineData("/* Win32Metadata: enum ::E => AssociatedConstant(S) */", "one native constant")]
        [InlineData("/* Win32Metadata: type ::NOT_ENUM => FlagsEnum(ONE) */", "compiled native values")]
        [InlineData("/* Win32Metadata: parameter ::F::value => Optional(maybe) */", "true or false")]
        [InlineData("/* Win32Metadata: function ::F => ImportLibrary(kernel32) */", "quoted string")]
        [InlineData("/* Win32Metadata: record ::S => SupportedOSPlatform(\"windows6.1\") */\n/* Win32Metadata: type ::S => SupportedOSPlatform(\"windows8.0\") */", "Conflicting")]
        public void CommentsRejectInvalidGrammarTargetsAndValues(string comment, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum E { ONE = 1 };
typedef unsigned NOT_ENUM;
struct S { unsigned flags; static unsigned shared; };
void F(unsigned value);
void* Open();
" + comment);
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ScalarForwardAliasesDoNotBecomeEnumsThroughEitherAnnotationChannel(bool comment)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#if defined(WIN32METADATA) && defined(__clang__) && !defined(MIDL_PASS)
typedef unsigned long STGM;
#endif
struct STATSTG { " + (comment ? "" : "_Win32_AssociatedEnum_(STGM) ") + @"unsigned long grfMode; };
" + (comment ? "/* Win32Metadata: field ::STATSTG::grfMode => AssociatedEnum(STGM) */" : ""));
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("AssociatedEnum requires a native enum or a _Win32_Enum_/_Win32_FlagsEnum_ group.", fixture.Diagnostics);
            Assert.Contains("STATSTG::grfMode", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("int Close(void*); int Close(int);", "function ::Open => RAIIFree(Close)", "found 2")]
        [InlineData("int Overloaded(int); int Overloaded(long);", "function ::Overloaded => RAIIFree(CloseThing)", "found 2")]
        [InlineData("struct I { virtual int F(int) = 0; virtual int F(long) = 0; };", "method ::I::F => PreserveResult", "found 2")]
        [InlineData("struct I { virtual int F(int value) = 0; virtual int F(long value) = 0; };", "parameter ::I::F::value => Optional(true)", "found 2")]
        [InlineData("namespace A { enum E { A = 1 }; } namespace B { enum E { B = 2 }; } using namespace A; using namespace B;", "field ::S::flags => AssociatedEnum(E)", "found 2")]
        public void CommentsRejectAmbiguousNativeBindings(string native, string payload, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "struct S { unsigned flags; }; void* Open();\n" + native +
                "\n/* Win32Metadata: " + payload + " */");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void CommentsIgnoreInactiveBranchesAndStringLiterals()
        {
            const string source = @"
#if 0
/* Win32Metadata: not even grammatical */
#elif defined(NOT_DEFINED)
/* Win32Metadata: record ::Missing => SupportedOSPlatform(""windows6.1"") */
#else
struct Active { int value; };
/* Win32Metadata: interface ::Active => SupportedOSPlatform(""windows6.1"") */
#endif
const char* Message = ""/* Win32Metadata: malformed */"";
";
            using var disabled = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", source,
                annotationsEnabled: false);
            Assert.True(disabled.Run() == 0, disabled.Diagnostics);
            Assert.DoesNotContain("SupportedOSPlatform", disabled.ReadSource());
            using var enabled = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", source);
            Assert.True(enabled.Run() == 0, enabled.Diagnostics);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", enabled.ReadSource());
        }

        [Fact]
        public void CommentsResolveIncludedDeclarationsInNormalProjectionScope()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""included.h""
struct Local { unsigned flags; };
/* Win32Metadata: field ::Local::flags => AssociatedEnum(Native::FLAGS) */
", extraSettings: "--traverse\nincluded.h\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "included.h"), @"
#pragma once
namespace Native { enum FLAGS { FIRST = 1, SECOND = 4 }; }
struct Included { int value; };
/* Win32Metadata: type ::Included => SupportedOSPlatform(""windows6.1"") */
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("AssociatedEnum(\"FLAGS\")", fixture.ReadSource());
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", fixture.ReadSource());
        }

        [Fact]
        public void CommentsReuseScopeSensitiveCleanupResolution()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int Close(void*);
namespace Inner {
void* Open();
int Close(void*);
}
/* Win32Metadata: return ::Inner::Open => RAIIFree(Close, 0, -1) */
", extraSettings: "--remap\nInner::Open=Open\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("RAIIFree(\"Close\")", fixture.ReadSource());
            Assert.Contains("InvalidHandleValue(0L)", fixture.ReadSource());
            Assert.Contains("InvalidHandleValue(-1L)", fixture.ReadSource());
        }

        [Fact]
        public void CommentsKeepNativeDirectionAndRetvalAcrossAdjacentBlocks()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum E { FIRST = 1 };
int F(/* [in] */ /* Win32Metadata: parameter ::F::flags => AssociatedEnum(E) */ unsigned flags,
      /* [out] */ /* [retval] */ /* ordinary intervening comment */ unsigned* result);
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var method = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == "F");
            Assert.Contains("InteropServices.In", method.ParameterList.Parameters[0].AttributeLists.ToString());
            Assert.Contains("AssociatedEnum", method.ParameterList.Parameters[0].AttributeLists.ToString());
            Assert.Contains("InteropServices.Out", method.ParameterList.Parameters[1].AttributeLists.ToString());
            Assert.Contains("Metadata.RetVal", method.ParameterList.Parameters[1].AttributeLists.ToString());
        }

        [Theory]
        [InlineData("field ::ALIAS::flags")]
        [InlineData("field ::tagRECORD::flags")]
        [InlineData("field ::ALIAS::nested::value")]
        [InlineData("field ::ALIAS::injected")]
        public void CommentsResolveRecordAliasesNestedAndAnonymousFields(string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum __MIDL___MIDL_itf_owner_0000_0000_0001 { FIRST = 1 };
typedef struct tagRECORD {
    unsigned flags;
    struct nested { unsigned value; };
    union { unsigned injected; int other; };
} ALIAS;
/* Win32Metadata: " + target + @" => AssociatedEnum(__MIDL___MIDL_itf_owner_0000_0000_0001) */
", extraSettings: "--remap\ntagRECORD=ALIAS\n__MIDL___MIDL_itf_owner_0000_0000_0001=FLAGS\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("AssociatedEnum(\"FLAGS\")", fixture.ReadSource());
        }

        [Theory]
        [InlineData("FlagsEnum", "System.Flags")]
        [InlineData("Enum", "enum MODES")]
        public void CommentsAssociateCompiledLogicalGroups(string macro, string expected)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#define FIRST 1U
#define SECOND 4U
_Win32_" + macro + @"_(MODES, unsigned, FIRST, SECOND);
struct RECORD { unsigned flags; };
/* Win32Metadata: field ::RECORD::flags => AssociatedEnum(MODES) */
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("AssociatedEnum(\"MODES\")", fixture.ReadSource());
            Assert.Contains(expected, fixture.ReadAdditionalTypes());
            Assert.Contains("FIRST =", fixture.ReadAdditionalTypes());
            Assert.Contains("SECOND =", fixture.ReadAdditionalTypes());
        }

        [Theory]
        [InlineData("PROPVARIANT")]
        [InlineData("tagPROPVARIANT")]
        public void CommentsBindMacroErasedPropVariantInnerTagThroughActualInjectedField(string owner)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum VARENUM { VT_EMPTY = 0, VT_I4 = 3 };
#define tag_inner_PROPVARIANT
typedef struct tagPROPVARIANT PROPVARIANT;
struct tagPROPVARIANT {
    union {
        struct tag_inner_PROPVARIANT {
            unsigned short vt;
            unsigned short reserved;
            union { long lVal; double dblVal; };
        };
        double decVal;
    };
};
/* Win32Metadata: field ::" + owner + @"::vt => AssociatedEnum(VARENUM) */
", extraSettings: "--remap\ntagPROPVARIANT=PROPVARIANT\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var field = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<FieldDeclarationSyntax>().Single(value => value.Declaration.Variables.Any(variable => variable.Identifier.ValueText == "vt"));
            Assert.Equal("ushort", field.Declaration.Type.ToString());
            Assert.Contains("AssociatedEnum(\"VARENUM\")", field.AttributeLists.ToString());
        }

        [Theory]
        [InlineData("RAIIFree(CloseThing)", "requires output/inout")]
        [InlineData("RetVal", "requires output/inout")]
        [InlineData("ContainsInteriorPointers", "requires output/inout")]
        [InlineData("ComOutPtr(true)", "input-only")]
        public void CommentsCannotInventOutputContractsOnNativeMidlInput(string annotation, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
int F(/* [in] */ void** value);
/* Win32Metadata: parameter ::F::value => " + annotation + @" */
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
        }

        [Fact]
        public void CommentRetvalDeduplicatesNativeMidlButRejectsTwoAuthoredComments()
        {
            const string source = @"
int F(/* [out][retval] */ int* value);
/* Win32Metadata: parameter ::F::value => RetVal */
";
            using var good = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", source);
            Assert.True(good.Run() == 0, good.Diagnostics);
            Assert.Single(CSharpSyntaxTree.ParseText(good.ReadSource()).GetRoot().DescendantNodes()
                .OfType<AttributeSyntax>().Where(attribute => attribute.Name.ToString().EndsWith(".RetVal", StringComparison.Ordinal)));
            using var bad = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", source +
                "\n/* Win32Metadata: parameter ::F::value => RetVal */");
            Assert.NotEqual(0, bad.Run());
            Assert.Contains("Duplicate 'RetVal'", bad.Diagnostics);
        }

        [Fact]
        public void ParameterSelectorsUseCanonicalOrdinalAcrossNativeRedeclarationNames()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
enum FLAGS { FIRST = 1 };
int F(unsigned original);
int F(unsigned renamed);
/* Win32Metadata: parameter ::F::renamed => AssociatedEnum(FLAGS) */
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("AssociatedEnum(\"FLAGS\")", fixture.ReadSource());
        }

        [Fact]
        public void CommentsBindActualPropertyNamesAndIgnoreTemplateHelpers()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
struct I {
    virtual int QueryInterface(void** result) = 0;
    template<typename T> int QueryInterface(T** result) { return 0; }
    virtual int get_Value(unsigned* value) = 0;
    virtual int put_Value(unsigned value) = 0;
};
/* Win32Metadata: method ::I::QueryInterface => PreserveResult */
/* Win32Metadata: parameter ::I::QueryInterface::result => ComOutPtr(true) */
/* Win32Metadata: parameter ::I::get_Value::value => RetVal */
/* Win32Metadata: parameter ::I::put_Value::value => Reserved */
", extraSettings: "--config\nexclude-funcs-with-body\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("PreserveSig", fixture.ReadSource());
            Assert.Contains("ComOutPtr(true)", fixture.ReadSource());
            Assert.Contains("Metadata.RetVal", fixture.ReadSource());
            Assert.Contains("Metadata.Reserved", fixture.ReadSource());
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        public void CommentsOnNativeDefinitionsHonorBodyProjectionExclusion(string architecture, string target, bool excluded)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
enum FLAGS { FIRST = 1 };
int Imported(unsigned flags);
/* Win32Metadata: parameter ::Imported::flags => AssociatedEnum(FLAGS) */
inline int BodyFunction(unsigned flags) { return 0; }
/* Win32Metadata: function ::BodyFunction => SupportedOSPlatform(""windows6.1"") */
/* Win32Metadata: parameter ::BodyFunction::flags => AssociatedEnum(FLAGS) */
inline unsigned BodyReturn() { return 1; }
/* Win32Metadata: return ::BodyReturn => AssociatedEnum(FLAGS) */
struct BODY_INTERFACE { virtual int BodyMethod(unsigned flags) { return 0; } };
/* Win32Metadata: method ::BODY_INTERFACE::BodyMethod => PreserveResult */
/* Win32Metadata: parameter ::BODY_INTERFACE::BodyMethod::flags => AssociatedEnum(FLAGS) */
", extraSettings: excluded ? "--config\nexclude-funcs-with-body\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().ToArray();
            var imported = Assert.Single(methods.Where(method => method.Identifier.ValueText == "Imported"));
            Assert.Contains("DllImport", imported.ToString());
            Assert.Contains("AssociatedEnum(\"FLAGS\")", Assert.Single(imported.ParameterList.Parameters).ToString());
            foreach (string name in new[] { "BodyFunction", "BodyReturn", "BodyMethod" })
            {
                if (excluded)
                    Assert.DoesNotContain(methods, method => method.Identifier.ValueText == name);
                else
                {
                    var method = Assert.Single(methods.Where(method => method.Identifier.ValueText == name));
                    Assert.DoesNotContain("DllImport", method.ToString());
                    Assert.Contains("AssociatedEnum(\"FLAGS\")", method.ToString());
                    Assert.Contains(name == "BodyFunction" ? "SupportedOSPlatform(\"windows6.1\")" :
                        name == "BodyMethod" ? "PreserveSig" : "return:", method.ToString());
                }
            }
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CommentsBindNativeDefinitionRedeclarationsCanonically(bool definitionFirst)
        {
            const string declaration = "int Body(unsigned original);\n";
            const string definition = "inline int Body(unsigned renamed) { return 0; }\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "enum FLAGS { FIRST = 1 };\n" + (definitionFirst ? definition + declaration : declaration + definition) + @"
/* Win32Metadata: function ::Body => SupportedOSPlatform(""windows6.1"") */
/* Win32Metadata: parameter ::Body::renamed => AssociatedEnum(FLAGS) */
int Imported();", extraSettings: "--config\nexclude-funcs-with-body\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().ToArray();
            Assert.Equal("Imported", Assert.Single(methods).Identifier.ValueText);
        }

        [Theory]
        [InlineData("function ::Body => Unknown", "Unknown")]
        [InlineData("parameter ::Body::flags => Retained", "pointer or reference")]
        [InlineData("parameter ::Body::flags => ComOutPtr(true)", "writable output pointer storage")]
        [InlineData("parameter ::Body::missing => Reserved", "named native parameter")]
        [InlineData("function ::Missing => PreserveResult", "found 0")]
        [InlineData("function ::RECORD => PreserveResult", "native function")]
        [InlineData("method ::Body => PreserveResult", "native method")]
        [InlineData("function ::RECORD::Method => PreserveResult", "native function")]
        [InlineData("return ::Body => PreserveResult", "not a return annotation")]
        [InlineData("function ::Overloaded => PreserveResult", "found 2")]
        [InlineData("parameter ::Overloaded::value => Reserved", "found 2")]
        public void NativeBodyCommentBindingRemainsStrict(string payload, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
inline int Body(unsigned flags) { return 0; }
struct RECORD { int Method(unsigned flags) { return 0; } };
int Overloaded(unsigned value);
inline int Overloaded(long value) { return 0; }
/* Win32Metadata: " + payload + " */", extraSettings: "--config\nexclude-funcs-with-body\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void ExcludedNativeDefinitionCommentErrorsAreCollectedTogether()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
inline int BadParameter(unsigned flags) { return 0; }
/* Win32Metadata: parameter ::BadParameter::flags => Retained */
inline void* BadCleanup() { return 0; }
/* Win32Metadata: return ::BadCleanup => RAIIFree(MissingCleanup, 0) */
struct BAD_METHOD { int BadStorage(unsigned flags) { return 0; } };
/* Win32Metadata: parameter ::BAD_METHOD::BadStorage::flags => ComOutPtr(true) */
int Imported();", extraSettings: "--config\nexclude-funcs-with-body\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Equal(3, fixture.Diagnostics.Split("WMA001").Length - 1);
            Assert.Contains("BadParameter::flags", fixture.Diagnostics);
            Assert.Contains("BadCleanup", fixture.Diagnostics);
            Assert.Contains("BAD_METHOD::BadStorage::flags", fixture.Diagnostics);
            Assert.Contains("pointer or reference", fixture.Diagnostics);
            Assert.Contains("declared native cleanup function", fixture.Diagnostics);
            Assert.Contains("writable output pointer storage", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData("IWeakReference", "objectReference", false)]
        [InlineData("IWeakReference", "objectReference", true)]
        [InlineData("IAgileReference", "ppvObjectReference", false)]
        [InlineData("IAgileReference", "ppvObjectReference", true)]
        public void CommentsBindResolveParametersOnlyInTheirActiveNativeHeaderBranch(
            string owner, string parameter, bool manualCpp)
        {
            string declaration = "struct __declspec(uuid(\"b2051485-7dfd-41a0-af5c-1b351bfb1297\")) " + owner +
                " { virtual int __stdcall Resolve(/* [in] */ const void* riid, /* [out] */ void** " + parameter + ") = 0; };\n";
            string comment = "/* Win32Metadata: parameter ::" + owner + "::Resolve::" + parameter + " => ComOutPtr(true) */\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "#if defined(MANUAL_CPP_BRANCH)\n" + declaration + comment + "#else\n" + declaration + comment + "#endif\n",
                extraSettings: manualCpp ? "--additional=-DMANUAL_CPP_BRANCH\n" : "");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var method = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().Single(value => value.Identifier.ValueText == "Resolve");
            var output = method.ParameterList.Parameters.Single(value => value.Identifier.ValueText == parameter);
            Assert.Contains("ComOutPtr(true)", output.AttributeLists.ToString());
            Assert.Contains("InteropServices.Out", output.AttributeLists.ToString());
        }

        [Fact]
        public void CommentsPreserveDistinctScalarAndCallbackAliases()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
typedef unsigned BASE_TOKEN;
typedef unsigned TOKEN;
typedef int (__stdcall *CALLBACK)(unsigned flags);
/* Win32Metadata: type ::TOKEN => SupportedOSPlatform(""windows6.1"") */
/* Win32Metadata: type ::TOKEN => AlsoUsableFor(BASE_TOKEN) */
/* Win32Metadata: type ::CALLBACK => SupportedOSPlatform(""windows8.0"") */
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            string aliases = fixture.ReadAdditionalTypes();
            Assert.Contains("struct TOKEN", aliases);
            Assert.Contains("AlsoUsableFor(\"BASE_TOKEN\")", aliases);
            Assert.Contains("windows6.1", aliases);
            Assert.Contains("delegate int CALLBACK", aliases + fixture.ReadSource());
            Assert.Contains("windows8.0", aliases + fixture.ReadSource());
        }

        [Fact]
        public void CommentsResolveNativeEnumConstantsAndQuotedPayloadRegions()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
const unsigned EXTRA = 8;
enum FLAGS { FIRST = 1 };
int F();
/* Win32Metadata: enum ::FLAGS => AssociatedConstant(EXTRA) */
/* Win32Metadata: enumerator ::FLAGS::FIRST => SupportedOSPlatform(""windows6.1"") */
/* Win32Metadata: constant ::EXTRA => SupportedOSPlatform(""windows8.0"") */
/* Win32Metadata: function ::F => ImportLibrary(""source.dll"", ""Name,With\""Quote"") */
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            Assert.Contains("AssociatedConstant(\"EXTRA\")", fixture.ReadSource());
            Assert.Contains("windows6.1", fixture.ReadSource());
            Assert.Contains("windows8.0", fixture.ReadSource());
            Assert.Contains("source.dll", fixture.ReadSource());
            Assert.Contains("Name,With\\\"Quote", fixture.ReadSource());
        }
    }
}
