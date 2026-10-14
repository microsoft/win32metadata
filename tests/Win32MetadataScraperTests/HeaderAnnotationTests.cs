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
_Win32_ImportLibrary_(""header.dll"") _Win32_SetLastError_ _Windows_SupportedOS_10240_
int __stdcall Imported(_Win32_Retained_ void* input, _Win32_ContainsInteriorPointers_ void* output);
_Win32_RAIIFree_(CloseThing, 0, INVALID_HANDLE_VALUE) HANDLE __stdcall OpenThing();
int __stdcall CreateThing(_Win32_RAIIFree_(CloseThing, 0) HANDLE* output);
_Win32_PreserveResult_ int __stdcall Result();
_Win32_AssociatedEnum_(Flags) unsigned __stdcall AssociatedReturn();
struct _Windows_SupportedOS_10240_ Record { _Win32_AssociatedEnum_(Flags) unsigned flags; };
enum _Windows_SupportedOS_10240_ _Win32_AssociatedConstant_(LOOSE_A) _Win32_AssociatedConstant_(LOOSE_B) Flags : unsigned { FlagA = 1 };
enum class [[clang::flag_enum]] ScopedFlags : unsigned { None = 0, A = 1 };
_Windows_SupportedOS_10240_ typedef unsigned NATIVE_ALIAS;
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
        [InlineData("_Win32_SetLastError_ typedef int Bad;")]
        [InlineData("_Win32_ContainsInteriorPointers_ int Bad(void* buffer);")]
        [InlineData("struct Bad { _Win32_ContainsInteriorPointers_ void* field; };")]
        [InlineData("int Bad(_Win32_ContainsInteriorPointers_ int value);")]
        [InlineData("int _Win32_SetLastError_ Bad();")]
        [InlineData("int __stdcall _Win32_SetLastError_ Bad();")]
        [InlineData("typedef _Windows_SupportedOS_10240_ int Bad;")]
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
        [InlineData("_Windows_SupportedOS_10240_ typedef int VALUES[4];")]
        [InlineData("int Bad(_Win32_Retained_ _Win32_Retained_ void* value);")]
        [InlineData("#define DOUBLE _Win32_Retained_ _Win32_Retained_\nint Bad(DOUBLE void* value);")]
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
_Windows_SupportedOS_10240_ _Win32_AlsoUsableFor_(OTHER_TOKEN)
typedef unsigned long TOKEN;
TOKEN UseToken(TOKEN value, TOKEN* output);
_Windows_SupportedOS_10240_
typedef int (__stdcall* PFN_BASE)(_Win32_Retained_ void* context, unsigned count);
_Windows_SupportedOS_Windows7_
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
_Windows_SupportedOS_10240_
typedef struct _PRIMARY { unsigned value; } PRIMARY;
_Windows_SupportedOS_Windows7_ _Win32_AlsoUsableFor_(PRIMARY)
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
