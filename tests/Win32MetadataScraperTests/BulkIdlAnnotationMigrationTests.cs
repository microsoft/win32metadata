using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class BulkIdlAnnotationMigrationTests
    {
        private readonly ITestOutputHelper output;

        public BulkIdlAnnotationMigrationTests(ITestOutputHelper output) => this.output = output;

        private static string TransportComment(string kind, string target, string payload) =>
            "cpp_quote(\"/* Win32Metadata: " + kind + " ::" + target + " => " +
            payload.Replace("\\", "\\\\", StringComparison.Ordinal).Replace("\"", "\\\"", StringComparison.Ordinal) + " */\")";

        private static string WithoutTransportComments(string source, string kind = null) => Regex.Replace(source,
            "(?m)^[ \\t]*cpp_quote\\(\"/\\* Win32Metadata: " + (kind == null ? "\\w+" : Regex.Escape(kind)) +
            " [^\\r\\n]*\\*/\"\\)\\r?\\n", "");

        [Theory]
        [InlineData("\n")]
        [InlineData("\r\n")]
        public void ExistingTransportSweepRestoresPristineSalAndUsesNativeSelectors(string newline)
        {
            string pristine = ("typedef struct _RECORD {\n    unsigned flags;\n} RECORD;\n" +
                "[object, local]\ninterface INative : IUnknown {\n" +
                "HRESULT Read([out, annotation(\"_Out_\")] void **value, [out] long *result);\n" +
                "[propget] HRESULT Kind([out] unsigned *value);\n};\n" +
                "cpp_quote(\"STDAPI Native(_In_opt_ unsigned options);\")\n" +
                "cpp_quote(\"_Win32_Enum_(KIND, unsigned, KindOne);\")\n").Replace("\n", newline, StringComparison.Ordinal);
            string patched = pristine
                .Replace("[object, local]", "_Win32_AnnotateInterface_(INative, _Win32_SupportedOS_Windows7_)" + newline +
                    "[object, local]", StringComparison.Ordinal)
                .Replace("unsigned flags;", "[annotation(\"_Win32_AssociatedEnum_(KIND)\")] unsigned flags;", StringComparison.Ordinal)
                .Replace("annotation(\"_Out_\")", "annotation(\"_Out_ _Win32_ComOutPtr_(true)\")", StringComparison.Ordinal)
                .Replace("[out] long *result", "[out, annotation(\"_Out_ _Win32_Retval_\")] long *result", StringComparison.Ordinal)
                .Replace("[out] unsigned *value", "[annotation(\"_Win32_AssociatedEnum_(KIND)\")] [out] unsigned *value", StringComparison.Ordinal)
                .Replace("Native(_In_opt_", "Native(_Win32_Optional_(false) _In_opt_", StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.Latin1.GetBytes(pristine));
            var result = fixture.ConvertTransport(patched);
            Assert.True(result.ExitCode == 0, result.Error);
            string converted = File.ReadAllText(result.Output);
            Assert.Contains(TransportComment("interface", "INative", "SupportedOSPlatform(\"windows6.1\")"), converted);
            Assert.Contains(TransportComment("field", "RECORD::flags", "AssociatedEnum(KIND)"), converted);
            Assert.Contains(TransportComment("parameter", "INative::Read::value", "ComOutPtr(true)"), converted);
            Assert.Contains(TransportComment("parameter", "INative::Read::result", "RetVal"), converted);
            Assert.Contains(TransportComment("parameter", "INative::get_Kind::value", "AssociatedEnum(KIND)"), converted);
            Assert.Contains(TransportComment("parameter", "Native::options", "Optional(false)"), converted);
            Assert.Equal(pristine, WithoutTransportComments(converted));
            Assert.Equal(Encoding.Latin1.GetBytes(pristine), File.ReadAllBytes(fixture.Source));
            Assert.DoesNotContain("_Win32_Annotate", converted);
            Assert.DoesNotContain("_Out_retval_", converted);
        }

        [Fact]
        public void ExistingTransportSweepKeepsReturnInvalidsAndErasedTagAlias()
        {
            const string pristine = "typedef struct tag_inner_VALUE VALUE;\n" +
                "cpp_quote(\"typedef struct tagVALUE VALUE;\")\ncpp_quote(\"#define tag_inner_VALUE\")\n" +
                "struct tag_inner_VALUE {\n    unsigned kind;\n};\n" +
                "cpp_quote(\"HANDLE WINAPI Create(void);\")\n";
            string patched = pristine.Replace("unsigned kind;", "[annotation(\"_Win32_AssociatedEnum_(enum KIND)\")] unsigned kind;",
                StringComparison.Ordinal).Replace("WINAPI Create", "WINAPI _Win32_RAIIFree_(CloseHandle, -1, 0) Create",
                StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(pristine));
            var result = fixture.ConvertTransport(patched);
            Assert.True(result.ExitCode == 0, result.Error);
            string converted = File.ReadAllText(result.Output);
            Assert.Contains(TransportComment("field", "VALUE::kind", "AssociatedEnum(KIND)"), converted);
            Assert.Contains(TransportComment("return", "Create", "RAIIFree(CloseHandle, -1, 0)"), converted);
            Assert.DoesNotContain("::tag_inner_VALUE::", converted);
            Assert.Equal(pristine, WithoutTransportComments(converted));
        }

        [Fact]
        public void ExistingTransportSweepPreservesNativeAndQuotedBranchLocality()
        {
            const string pristine = "interface IReference : IUnknown {\n" +
                "cpp_quote(\"#if defined(__cplusplus) && !defined(CINTERFACE)\")\n" +
                "cpp_quote(\"MIDL_INTERFACE(\\\"00000000-0000-0000-0000-000000000001\\\")\")\n" +
                "cpp_quote(\"IReference : public IUnknown {\")\n" +
                "cpp_quote(\"virtual HRESULT Resolve(void **value) = 0;\")\ncpp_quote(\"};\")\n" +
                "cpp_quote(\"#else\")\nHRESULT Resolve([out] void **value);\n};\ncpp_quote(\"#endif\")\n";
            string patched = pristine.Replace("Resolve(void **value)", "Resolve(_Win32_ComOutPtr_(true) void **value)",
                StringComparison.Ordinal).Replace("[out] void **value",
                "[out, annotation(\"_Win32_ComOutPtr_(true)\")] void **value", StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(pristine));
            var result = fixture.ConvertTransport(patched);
            Assert.True(result.ExitCode == 0, result.Error);
            string converted = File.ReadAllText(result.Output);
            string comment = TransportComment("parameter", "IReference::Resolve::value", "ComOutPtr(true)");
            Assert.Equal(2, Regex.Matches(converted, Regex.Escape(comment)).Count);
            int split = converted.IndexOf("cpp_quote(\"#else\")", StringComparison.Ordinal);
            Assert.True(converted.IndexOf(comment, StringComparison.Ordinal) < split);
            Assert.True(converted.LastIndexOf(comment, StringComparison.Ordinal) > split);
            Assert.Equal(pristine, WithoutTransportComments(converted));
        }

        [Fact]
        public void ExistingTransportSweepIgnoresMacroSpellingsInCommentsAndQuotedData()
        {
            const string pristine = "/*\n_Win32_AnnotateInterface_(INotNative, _Win32_SupportedOS_Windows7_)\n*/\n" +
                "cpp_quote(\"// _Win32_Retval_ is documentation\")\n" +
                "cpp_quote(\"const char *text = \\\"_Win32_Retval_\\\";\")\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(pristine));
            var result = fixture.ConvertTransport(pristine);
            Assert.True(result.ExitCode == 0, result.Error);
            Assert.Equal(pristine, File.ReadAllText(result.Output));
        }

        [Fact]
        public void ExistingTransportSweepAcceptsOriginalOdlWithoutAdmittingNewRecipeInputs()
        {
            const string pristine = "interface INative : IUnknown {};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(pristine));
            var result = fixture.ConvertTransport("_Win32_AnnotateInterface_(INative, _Win32_SupportedOS_Windows7_)\n" +
                pristine, ".odl");
            Assert.True(result.ExitCode == 0, result.Error);
            string converted = File.ReadAllText(result.Output);
            Assert.Contains(TransportComment("interface", "INative", "SupportedOSPlatform(\"windows6.1\")"), converted);
            Assert.Equal(pristine, WithoutTransportComments(converted));
        }

        [Theory]
        [InlineData("missing")]
        [InlineData("conditional")]
        [InlineData("expression")]
        [InlineData("overflow")]
        public void ExistingTransportSweepRejectsUnboundOrUnsafeFactsBeforePublication(string form)
        {
            const string pristine = "interface INative : IUnknown {\nHRESULT Read([out] long *value);\n};\n";
            string patched = form == "missing" ? pristine + "[annotation(\"_Win32_Retval_\")] long missing;\n" :
                form == "conditional" ? pristine.Replace("[out] long *value",
                    "\n#if FEATURE\n[annotation(\"_Win32_Retval_\")] [out] long *value\n#endif\n", StringComparison.Ordinal) :
                pristine.Replace("[out] long *value", "[annotation(\"_Win32_RAIIFree_(FreeValue, " +
                    (form == "overflow" ? "9223372036854775808" : "INVALID_VALUE") + ")\")] [out] long *value",
                    StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(pristine));
            var result = fixture.ConvertTransport(patched);
            Assert.NotEqual(0, result.ExitCode);
            Assert.False(File.Exists(result.Output));
            Assert.Equal(pristine, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData("\r\n", false)]
        [InlineData("\n", true)]
        public void AuthoringPreservesOriginalBytesAttributesGuardsAndEncoding(string newline, bool bom)
        {
            string text = "// Copyright sample " + (char)0xA9 + "\n" +
                "#ifndef SAMPLE_IDL\n#define SAMPLE_IDL\n" +
                "#define UNUSED_DECLARATION interface IMacroBody : IUnknown {};\n" +
                "// interface IComment : IUnknown { };\n" +
                "cpp_quote(\"interface IQuoted : IUnknown { };\")\n" +
                "interface IMigrated;\n" +
                "[object, uuid(00000000-0000-0000-0000-000000000001)]\n" +
                "interface IMigrated : IUnknown\n{\n" +
                "    HRESULT Read([out, retval] long* result);\n};\n#endif\n";
            byte[] bytes = Encoding.Latin1.GetBytes(text.Replace("\n", newline));
            if (bom)
                bytes = new byte[] { 239, 187, 191 }.Concat(bytes).ToArray();
            using var fixture = new Fixture(bytes);
            fixture.WriteMap(new[]
            {
                Floor("IMigrated"), Floor("IComment"), Floor("IQuoted"), Floor("IOnlyForward"), Floor("IMacroBody"),
            });
            var result = fixture.Run();
            Assert.Equal(0, result.ExitCode);
            Assert.Equal(bytes, File.ReadAllBytes(fixture.Source));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(1, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(4, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.Single(report.RootElement.GetProperty("candidateGeneratedHeaders").EnumerateArray());
            byte[] authored = File.ReadAllBytes(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            string decoded = Encoding.Latin1.GetString(authored);
            Assert.Contains(TransportComment("interface", "IMigrated", "SupportedOSPlatform(\"windows6.1\")") + newline +
                "[object, uuid", decoded);
            decoded = decoded.Replace("#include <sal.h>" + newline, "", StringComparison.Ordinal)
                .Replace(TransportComment("interface", "IMigrated", "SupportedOSPlatform(\"windows6.1\")") + newline, "", StringComparison.Ordinal);
            Assert.Equal(bytes, Encoding.Latin1.GetBytes(decoded));
            var application = Fixture.Command("git", fixture.RepositoryRoot, "apply", "--unsafe-paths", "-p1",
                "--directory=" + fixture.Sdk, "--whitespace=error-all", "--check", "--",
                Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
            Assert.True(application.ExitCode == 0, application.Error);
        }

        [Fact]
        public void AmbiguousDefinitionsUnknownVocabularyAndNonInterfaceFactsRemainExactLegacyDebt()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(
                "#if FIRST\ninterface IDuplicate : IUnknown {};\n#else\ninterface IDuplicate : IUnknown {};\n#endif\n" +
                "interface IUnknownFloor : IUnknown {};\ninterface IMethod : IUnknown {};\n"));
            object[] facts =
            {
                Floor("IDuplicate"), Floor("IUnknownFloor", "windows11.0"),
                new { category = "setLastError", symbol = "IMethod", value = "IMethod" },
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.Equal(0, result.ExitCode);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(3, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            var dispositions = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions");
            Assert.All(dispositions.EnumerateArray(), item => Assert.Equal("retained-legacy", item.GetProperty("disposition").GetString()));
            Assert.Equal(JsonSerializer.Serialize(facts), JsonSerializer.Serialize(
                dispositions.EnumerateArray().Select(item => item.GetProperty("fact")).ToArray()));
        }

        [Theory]
        [InlineData("duplicate", "Duplicate fact identity")]
        [InlineData("stale", "preimage mismatch")]
        [InlineData("escape", "escapes the SDK")]
        [InlineData("header", "shipped IDL")]
        [InlineData("utf16", "encoding-aware owner review")]
        public void InvalidOrStaleOwnerInputsFailBeforePublication(string mutation, string diagnostic)
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};\n"));
            string original = mutation == "escape" ? @"..\outside.idl" : mutation == "header" ? @"um\sample.h" : @"um\sample.idl";
            if (mutation == "utf16")
                File.WriteAllBytes(fixture.Source, Encoding.Unicode.GetPreamble().Concat(Encoding.Unicode.GetBytes("interface IMigrated : IUnknown {};")).ToArray());
            fixture.WriteMap(mutation == "duplicate" ? new[] { Floor("IMigrated"), Floor("IMigrated") } : new[] { Floor("IMigrated") },
                original, stale: mutation == "stale");
            var result = fixture.Run();
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains(diagnostic, result.Error);
            Assert.False(Directory.Exists(result.OutputDirectory));
        }

        [Fact]
        public void UnsupportedOrNativeEquivalentMethodFactsRemainExactLegacyDebt()
        {
            const string source = "interface IAmbiguous : IUnknown {\n" +
                "HRESULT Read([out] long* result);\nHRESULT Read([out] long* result);\n};\n" +
                "interface IExisting : IUnknown {\nHRESULT Read([out, retval] long* result);\n" +
                "HRESULT NativeInline([out, annotation(\"_Out_retval_\")] long* result);\n" +
                "HRESULT AmbiguousInline([out, annotation(\"_Out_\")][annotation(\"_Out_\")] long* result);\n};\n" +
                "interface IOnlyForward;\n" +
                "cpp_quote(\"interface IQuoted : IUnknown { HRESULT Read(long* result); };\")\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            object[] facts =
            {
                new { category = "declaration-attribute-override", symbol = "IAmbiguous::Read",
                    value = "IAmbiguous::Read=[CanReturnMultipleSuccessValues]" },
                new { category = "declaration-attribute-override", symbol = "IAmbiguous::Read::result",
                    value = "IAmbiguous::Read::result=[RetVal]" },
                new { category = "declaration-attribute-override", symbol = "IExisting::Read::result",
                    value = "IExisting::Read::result=[RetVal]" },
                new { category = "declaration-attribute-override", symbol = "IExisting::NativeInline::result",
                    value = "IExisting::NativeInline::result=[RetVal]" },
                new { category = "declaration-attribute-override", symbol = "IExisting::AmbiguousInline::result",
                    value = "IExisting::AmbiguousInline::result=[RetVal]" },
                new { category = "declaration-attribute-override", symbol = "IOnlyForward::Read",
                    value = "IOnlyForward::Read=[CanReturnErrorsAsSuccess]" },
                new { category = "declaration-attribute-override", symbol = "IQuoted::Read",
                    value = "IQuoted::Read=[CanReturnMultipleSuccessValues]" },
                new { category = "declaration-attribute-override", symbol = "IExisting::Read::missing",
                    value = "IExisting::Read::missing=[RetVal]" },
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(8, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.Contains("native-retval-already-present", File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            fixture.WriteMap(new[]
            {
                new { category = "declaration-attribute-override", symbol = "IExisting::Read::result",
                    value = "IExisting::Read::result=[ComOutPtr]" },
            });
            var unsupported = fixture.Run();
            Assert.Equal(0, unsupported.ExitCode);
            using var unsupportedReport = JsonDocument.Parse(File.ReadAllText(Path.Combine(unsupported.OutputDirectory, "report.json")));
            Assert.Equal(1, unsupportedReport.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
        }

        [Theory]
        [InlineData("\r\n", true, false)]
        [InlineData("\n", true, false)]
        [InlineData("\r\n", false, false)]
        [InlineData("\n", false, false)]
        [InlineData("\r\n", true, true)]
        [InlineData("\n", true, true)]
        [InlineData("\r\n", false, true)]
        [InlineData("\n", false, true)]
        public void NativeMethodParameterAndLastErrorFactsPreserveAllOriginalSourceBytes(
            string newline, bool terminator, bool inlineAnnotation)
        {
            string parameterAttributes = inlineAnnotation ? "[out, annotation(\"_Out_\")]" : "[out]";
            string source = ("#ifndef SAMPLE_IDL\n#define SAMPLE_IDL\n" +
                "interface IExisting : IUnknown {\n" +
                "HRESULT Read([in, size_is(, count)] long** values, [in] long count,\n" +
                "    " + parameterAttributes + " long* result);\n}" + (terminator ? ";" : "") + " // native definition\n" +
                "cpp_quote(\"STDAPI_(UINT) Exported(_In_ long value);\")\n" +
                "cpp_quote(\"SHSTDAPI ShellNative(void);\")\n" +
                "cpp_quote(\"DWORD\")\ncpp_quote(\"WINAPI\")\ncpp_quote(\"NetworkNative(void);\")\n" +
                "#endif\n").Replace("\n", newline, StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            object[] facts =
            {
                Floor("IExisting"),
                new { category = "declaration-attribute-override", symbol = "IExisting::Read",
                    value = "IExisting::Read=[CanReturnMultipleSuccessValues]" },
                new { category = "declaration-attribute-override", symbol = "IExisting::Read::result",
                    value = "IExisting::Read::result=[RetVal]" },
                new { category = "setLastError", symbol = "Exported", value = "Exported" },
                Floor("ShellNative"), Floor("NetworkNative"),
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            string method = TransportComment("method", "IExisting::Read", "PreserveResult");
            Assert.Contains("}" + (terminator ? ";" : "") + " // native definition" + newline + method + newline, authored);
            Assert.Contains(TransportComment("parameter", "IExisting::Read::result", "RetVal"), authored);
            Assert.Contains(parameterAttributes + " long* result", authored);
            Assert.Contains(TransportComment("function", "Exported", "SetLastError"), authored);
            Assert.Contains(TransportComment("function", "ShellNative", "SupportedOSPlatform(\"windows6.1\")"), authored);
            Assert.Contains(TransportComment("function", "NetworkNative", "SupportedOSPlatform(\"windows6.1\")"), authored);
            Assert.Equal(source, WithoutTransportComments(authored).Replace("#include <sal.h>" + newline, "", StringComparison.Ordinal));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(6, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(0, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            var application = Fixture.Command("git", fixture.RepositoryRoot, "-c",
                "core.whitespace=blank-at-eol,blank-at-eof,space-before-tab,cr-at-eol", "apply", "--unsafe-paths", "-p1",
                "--directory=" + fixture.Sdk, "--whitespace=error-all", "--check", "--",
                Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
            Assert.True(application.ExitCode == 0, application.Error);
        }

        [Theory]
        [InlineData("\r\n", false)]
        [InlineData("\n", true)]
        public void NativeEnumAssociationsPreserveFieldsParameterSalAndAllOriginalBytes(string newline, bool inlineAnnotation)
        {
            string native = inlineAnnotation ? "[annotation(\"_Field_range_(0, 2)\")] " : "";
            string source = ("typedef enum NATIVE_KIND { First = 1, Second = 2 } NATIVE_KIND;\n" +
                "typedef struct _NATIVE_RECORD {\n" +
                "    " + native + "unsigned flags;\n" +
                "    struct { unsigned flags; } nested;\n" +
                "} NATIVE_RECORD;\n" +
                "interface IExisting : IUnknown {\n" +
                "    HRESULT Read([in] unsigned count, [out, annotation(\"_Out_\")] unsigned* result);\n" +
                "};\n").Replace("\n", newline, StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            object[] facts =
            {
                Association("NATIVE_RECORD::flags", "NATIVE_KIND"),
                Association("IExisting::Read::result", "NATIVE_KIND"),
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Contains(TransportComment("field", "NATIVE_RECORD::flags", "AssociatedEnum(NATIVE_KIND)"), authored);
            Assert.Contains(TransportComment("parameter", "IExisting::Read::result", "AssociatedEnum(NATIVE_KIND)"), authored);
            Assert.Contains(native + "unsigned flags", authored);
            Assert.Contains("[out, annotation(\"_Out_\")] unsigned* result", authored);
            Assert.Contains("struct { unsigned flags; } nested;", authored);
            Assert.Equal(source, WithoutTransportComments(authored).Replace("#include <sal.h>" + newline, "", StringComparison.Ordinal));
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(2, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(0, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            var field = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")[0];
            Assert.Equal("FieldDecl", field.GetProperty("declaration").GetProperty("kind").GetString());
            Assert.Equal("_NATIVE_RECORD::flags", field.GetProperty("declaration").GetProperty("nativeQualifiedName").GetString());
        }

        [Fact]
        public void AmbiguousImportedAndQuotedEnumAssociationsRemainExactLegacyDebt()
        {
            const string source = "typedef struct Duplicate { unsigned flags; unsigned flags; } Duplicate;\n" +
                "typedef struct Other { unsigned flags; } VariableNotType;\n" +
                "struct Forward;\n" +
                "cpp_quote(\"typedef struct Quoted { unsigned flags; } Quoted;\")\n" +
                "interface IExisting : IUnknown {\n" +
                "    HRESULT Read([out, annotation(\"_Out_\")][annotation(\"_Out_\")] unsigned* result);\n" +
                "};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            object[] facts =
            {
                Association("Duplicate::flags", "NATIVE_KIND"),
                Association("Forward::flags", "NATIVE_KIND"),
                Association("Quoted::flags", "NATIVE_KIND"),
                Association("Imported::flags", "NATIVE_KIND"),
                Association("IExisting::Read::result", "NATIVE_KIND"),
                new { category = "associated-enum-use", symbol = "Other::flags",
                    value = "Other::flags=[AssociatedEnum(\"invented::payload\")]"},
            };
            fixture.WriteMap(facts);
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(6, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        private static object Association(string symbol, string name) => new
        {
            category = "associated-enum-use", symbol, value = symbol + "=[AssociatedEnum(\"" + name + "\")]",
        };

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AnonymousEnumAssociationsUseOnlyUniqueExistingSameOriginalParserRemaps(bool ambiguous)
        {
            const string source = "enum { NativeChoice = 1 };\n" +
                "typedef struct HOLDER { unsigned flags; } HOLDER;\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            const string tag = "__MIDL___MIDL_itf_sample_0000_0000_0012";
            File.WriteAllText(Path.Combine(fixture.Project, "scraper.settings.rsp"),
                "--remap\n" + tag + "=NATIVE_GROUP\n" +
                "__MIDL___MIDL_itf_foreign_0000_0000_0012=NATIVE_GROUP\n" +
                (ambiguous ? "__MIDL___MIDL_itf_sample_0000_0000_0013=NATIVE_GROUP\n" : ""));
            fixture.WriteMap(new[] { Association("HOLDER::flags", "NATIVE_GROUP") });
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(ambiguous ? 0 : 1, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(ambiguous ? 1 : 0, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            if (!ambiguous)
            {
                string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
                Assert.Contains(TransportComment("field", "HOLDER::flags", "AssociatedEnum(" + tag + ")"), authored);
                Assert.Equal(source, WithoutTransportComments(authored).Replace("#include <sal.h>\n", "", StringComparison.Ordinal));
            }
        }

        [Fact]
        public void AuthoringIsRepeatableAndNeverOverwritesAPublishedResult()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};\r\n"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            var first = fixture.Run();
            var second = fixture.Run();
            Assert.Equal(0, first.ExitCode);
            Assert.Equal(0, second.ExitCode);
            foreach (string relative in new[] { @"source\um\sample.idl", @"patches\um\sample.idl.patch", "report.json" })
                Assert.Equal(File.ReadAllBytes(Path.Combine(first.OutputDirectory, relative)), File.ReadAllBytes(Path.Combine(second.OutputDirectory, relative)));
            var overwrite = fixture.Run(first.OutputDirectory);
            Assert.NotEqual(0, overwrite.ExitCode);
            Assert.Contains("do not overwrite", overwrite.Error);
        }

        [Fact]
        public void MultipleSourceOffsetsAreAppliedDescendingRatherThanInInventoryOrder()
        {
            const string source = "// before first\r\n[object]\r\ninterface IZFirst : IUnknown {};\r\n" +
                "// before second\r\n[object]\r\ninterface IASecond : IUnknown {};\r\n" +
                "// before third\r\n[object]\r\ninterface IMThird : IUnknown {};\r\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { Floor("IASecond"), Floor("IMThird"), Floor("IZFirst") });
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            foreach (string name in new[] { "IZFirst", "IASecond", "IMThird" })
            {
                string carrier = TransportComment("interface", name, "SupportedOSPlatform(\"windows6.1\")") + "\r\n";
                Assert.Contains(carrier + "[object]\r\ninterface " + name, authored);
                authored = authored.Replace(carrier, "", StringComparison.Ordinal);
            }
            Assert.Equal(source, authored.Replace("#include <sal.h>\r\n", "", StringComparison.Ordinal));
            string patch = File.ReadAllText(Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
            Assert.DoesNotContain("-interface", patch);
            Assert.DoesNotContain("-//", patch);
        }

        [Fact]
        public void CarriersPrecedeNativeMacroGeneratedAttributeLists()
        {
            const string source = "// native attributes\r\n" +
                "#define NATIVE_INTERFACE(id, description) \\\r\n" +
                "    [object, uuid(id), helpstring(description), local]\r\n" +
                "NATIVE_INTERFACE(00000000-0000-0000-0000-000000000001,\r\n" +
                "    \"native interface\")\r\n" +
                "interface IMigrated : IUnknown {};\r\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            string carrier = TransportComment("interface", "IMigrated", "SupportedOSPlatform(\"windows6.1\")") + "\r\n";
            Assert.Contains(carrier + "NATIVE_INTERFACE(00000000", authored);
            Assert.Equal(source, authored.Replace(carrier, "", StringComparison.Ordinal)
                .Replace("#include <sal.h>\r\n", "", StringComparison.Ordinal));
        }

        [Theory]
        [InlineData("\r\n")]
        [InlineData("\n")]
        public void QuotedNativePrototypesPreserveLinkageAndCumulativeInterfaceAnnotations(string newline)
        {
            string source = "interface IExisting : IUnknown {};\n" +
                "cpp_quote(\"STDAPI SingleLine(_Out_ long* result);\")\n" +
                "cpp_quote(\"STDAPI\")\ncpp_quote(\"SplitLine(\")\n" +
                "cpp_quote(\"    _In_reads_(count) const long* values, long count);\")\n" +
                "cpp_quote(\"EXTERN_C HRESULT STDAPICALLTYPE Linked(void);\")\n" +
                "cpp_quote(\"HRESULT STDMETHODCALLTYPE Stdcall(void);\")\n" +
                "cpp_quote(\"HRESULT WINAPI Winapi(void);\")\n" +
                "cpp_quote(\"EXTERN_C HRESULT WINAPI\")\ncpp_quote(\"SplitWinapi(void);\")\n" +
                "cpp_quote(\"STDAPI_(MFTIME)\")\ncpp_quote(\"Clock(void);\")\n" +
                "cpp_quote(\"STDAPI Trailing(\") \t\ncpp_quote(\"    _In_ long value);\")\n" +
                "cpp_quote(\"STDAPI Escaped(\") \t\n" +
                "cpp_quote(\"    long value __attribute__((annotate(\\\"(marker)\\\"))));\")\n";
            source = source.Replace("\n", newline, StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { Floor("IExisting") });
            var previous = fixture.Run();
            Assert.True(previous.ExitCode == 0, previous.Error);
            fixture.WriteMap(new[] { "IExisting", "SingleLine", "SplitLine", "Linked", "Stdcall", "Winapi", "SplitWinapi", "Clock", "Trailing", "Escaped" }
                .Select(name => Floor(name)).ToArray());
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Equal(File.ReadAllText(Path.Combine(previous.OutputDirectory, "source", "um", "sample.idl")),
                WithoutTransportComments(authored, "function"));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
            Assert.Contains("EXTERN_C HRESULT STDAPICALLTYPE Linked", authored);
            Assert.Contains("HRESULT WINAPI Winapi", authored);
            Assert.Contains("cpp_quote(\"EXTERN_C HRESULT WINAPI\")" + newline +
                "cpp_quote(\"SplitWinapi(", authored);
            Assert.Contains("cpp_quote(\"STDAPI\")" + newline + "cpp_quote(\"SplitLine(", authored);
            Assert.Contains("cpp_quote(\"STDAPI Trailing(\") \t" + newline +
                "cpp_quote(\"    _In_ long value);\")", authored);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Contains("annotate(\\\"(marker)\\\"))));", authored);
            Assert.Equal(10, report.RootElement.GetProperty("authoredFacts").GetInt32());
            var functions = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions").EnumerateArray()
                .Where(item => item.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl").ToArray();
            Assert.Equal(9, functions.Length);
            Assert.All(functions, item =>
            {
                Assert.Equal("cpp_quote-prototype", item.GetProperty("declaration").GetProperty("sourceForm").GetString());
                Assert.False(item.GetProperty("declaration").GetProperty("isDefinition").GetBoolean());
            });
        }

        [Fact]
        public void QuotedCallsCommentsIncompletePrototypesAndAmbiguousTargetsRemainLegacy()
        {
            const string source = "cpp_quote(\"// STDAPI Comment(void);\")\n" +
                "/*\ncpp_quote(\"STDAPI BlockComment(void);\")\n*/\n" +
                "cpp_quote(\"Invoke(Call());\")\n" +
                "cpp_quote(\"HRESULT STDMETHODCALLTYPE Invoke(NestedCall());\")\n" +
                "cpp_quote(\"typedef HRESULT (STDMETHODCALLTYPE *Pointer)(void);\")\n" +
                "cpp_quote(\"STDAPI (*ReturnedPointer(void))(void);\")\n" +
                "cpp_quote(\"STDAPI Whitespace(void);\") \t\n" +
                "cpp_quote(\"STDAPI Definition(void) { return 0; }\")\n" +
                "cpp_quote(\"STDAPI Duplicate(void);\")\ncpp_quote(\"STDAPI Duplicate(void);\")\n" +
                "cpp_quote(\"STDAPI Incomplete(void)\")\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { "Comment", "BlockComment", "Call", "NestedCall", "Pointer", "ReturnedPointer",
                "Whitespace", "Definition", "Duplicate", "Incomplete" }
                .Select(name => Floor(name)).ToArray());
            var result = fixture.Run();
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(10, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
        }

        [Fact]
        public void QuotedFunctionOnlyOwnersRequireAndApplyNormalParserActivation()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("cpp_quote(\"STDAPI Factory(void);\")\n"));
            fixture.WriteMap(new[] { Floor("Factory") });
            var proposal = fixture.Run();
            Assert.True(proposal.ExitCode == 0, proposal.Error);
            using var before = JsonDocument.Parse(File.ReadAllText(Path.Combine(proposal.OutputDirectory, "report.json")));
            Assert.False(before.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            var applied = fixture.Run(apply: true);
            Assert.True(applied.ExitCode == 0, applied.Error);
            using var after = JsonDocument.Parse(File.ReadAllText(Path.Combine(applied.OutputDirectory, "report.json")));
            Assert.True(after.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            Assert.Contains("parse-win32-annotations", File.ReadAllText(
                Path.Combine(fixture.Project, "Partitions", "Sample", "settings.rsp")));
            Assert.Equal(File.ReadAllBytes(Path.Combine(proposal.OutputDirectory, "source", "um", "sample.idl")),
                File.ReadAllBytes(Path.Combine(applied.OutputDirectory, "source", "um", "sample.idl")));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "c", "c11")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c", "c11")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c", "c11")]
        [InlineData("x86", "i686-pc-windows-msvc", "c++", "c++17")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "c++", "c++17")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "c++", "c++17")]
        public void QuotedPrototypeAvailabilityBindsToFunctionsInEitherNativePosition(
            string architecture, string target, string language, string standard)
        {
            string linkage = language == "c++" ? "extern \"C\" " : "extern ";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target,
                linkage + "int __stdcall _Win32_SupportedOS_Windows7_ Prefix(int value);\n" +
                linkage + "int __stdcall Postfix(int value) _Win32_SupportedOS_Windows8_;\n",
                extraSettings: $"--language\n{language}\n--std\n{standard}\n");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot()
                .DescendantNodes().OfType<MethodDeclarationSyntax>().ToArray();
            foreach (var expected in new[] { ("Prefix", "windows6.1"), ("Postfix", "windows8.0") })
            {
                var method = Assert.Single(methods.Where(value => value.Identifier.ValueText == expected.Item1));
                Assert.Equal("int", method.ReturnType.ToString());
                Assert.Equal("int", Assert.Single(method.ParameterList.Parameters).Type.ToString());
                Assert.Contains("DllImport(\"scan.dll\"", method.AttributeLists.ToString());
                var floor = Assert.Single(method.AttributeLists.SelectMany(list => list.Attributes).Where(value =>
                    value.Name.ToString() == "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform"));
                Assert.Equal(expected.Item2, Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(floor.ArgumentList.Arguments).Expression).Token.ValueText);
            }
        }

        [Fact]
        public void NativeControlsAccountForOneExistingInterfaceTypedefCarrier()
        {
            string[] original = { "record IExample 8 8", "typedef IExample IExample" };
            string[] prepared = { "record IExample 8 8", "typedef IExample IExample", "typedef IExample IExample" };
            Assert.Equal(original, WinHttpNativeControlTests.NormalizeInterfaceCarrierTypedefs(
                original, prepared, new[] { "IExample|SupportedOSPlatform(\"windows6.1\")" }));
        }

        [Theory]
        [InlineData("record IExample 16 8", "typedef IExample IExample", "typedef IExample IExample")]
        [InlineData("record IExample 8 8", "typedef IExample int", "typedef IExample int")]
        [InlineData("record IExample 8 8", "typedef IExample IExample", "typedef IExample IExample", "typedef IExample IExample")]
        [InlineData("record IExample 8 8", "typedef IExample IExample", "typedef INew INew")]
        public void NativeControlsRetainLayoutTypeAndUnexpectedDeclarationDifferences(params string[] prepared)
        {
            string[] original = { "record IExample 8 8", "typedef IExample IExample" };
            Assert.NotEqual<string>(original, WinHttpNativeControlTests.NormalizeInterfaceCarrierTypedefs(
                original, prepared, new[] { "IExample|SupportedOSPlatform(\"windows6.1\")" }));
        }

        [Theory]
        [InlineData("\r\n")]
        [InlineData("\n")]
        public void RecipeAdmissionRequiresRealNormalParserActivation(string newline)
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            string settings = Path.Combine(fixture.Project, "Partitions", "Sample", "settings.rsp");
            string original = "--namespace\nTest\n--traverse\n<IncludeRoot>/um/sample.h\n--config\ngenerate-compatible-codegen\n"
                .Replace("\n", newline, StringComparison.Ordinal);
            File.WriteAllText(settings, original);
            string untouched = Path.Combine(fixture.Project, "Partitions", "Other", "settings.rsp");
            Directory.CreateDirectory(Path.GetDirectoryName(untouched));
            File.WriteAllText(untouched, "--namespace\nOther\n");
            byte[] untouchedBytes = File.ReadAllBytes(untouched);
            byte[] source = File.ReadAllBytes(fixture.Source);
            var proposal = fixture.Run();
            Assert.True(proposal.ExitCode == 0, proposal.Error);
            using (var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(proposal.OutputDirectory, "report.json"))))
                Assert.False(report.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            Assert.Equal(original, File.ReadAllText(settings));
            var applied = fixture.Run(apply: true);
            Assert.True(applied.ExitCode == 0, applied.Error);
            using (var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(applied.OutputDirectory, "report.json"))))
                Assert.True(report.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            Assert.Equal(original + "--config" + newline + "parse-win32-annotations" + newline, File.ReadAllText(settings));
            byte[] activated = File.ReadAllBytes(settings);
            Assert.True(fixture.Run(apply: true).ExitCode == 0);
            Assert.Equal(activated, File.ReadAllBytes(settings));
            Assert.Equal(untouchedBytes, File.ReadAllBytes(untouched));
            Assert.Equal(source, File.ReadAllBytes(fixture.Source));
        }

        [Fact]
        public void ApplyRejectsAnUnconfiguredNormalOwnerWithoutCreatingSpeculativeSettings()
        {
            using var fixture = new Fixture(Encoding.ASCII.GetBytes("interface IMigrated : IUnknown {};"));
            fixture.WriteMap(new[] { Floor("IMigrated") });
            string settings = Path.Combine(fixture.Project, "Partitions", "Sample", "settings.rsp");
            File.Delete(settings);
            var result = fixture.Run(apply: true);
            Assert.NotEqual(0, result.ExitCode);
            Assert.Contains("actual configured normal traverse owners", result.Error);
            Assert.False(File.Exists(settings));
            Assert.False(Directory.Exists(result.OutputDirectory));
        }

        [HeaderMigrationDataTheory("WIN32METADATA_WMI_GENERATED_SOURCE", "WIN32METADATA_WMI_DISABLED_SOURCE")]
        [InlineData("IEnumWbemClassObject", "windows6.0.6000")]
        public void ActualNormalWmiSourceProjectsTheOwnedFloorWithoutLegacyFallback(string target, string floor)
        {
            string source = Environment.GetEnvironmentVariable("WIN32METADATA_WMI_GENERATED_SOURCE");
            string disabled = Environment.GetEnvironmentVariable("WIN32METADATA_WMI_DISABLED_SOURCE");
            Assert.True(!string.IsNullOrEmpty(disabled) && File.Exists(disabled), "Supply the actual normal disabled-parser control.");
            Assert.Empty(Floors(disabled));
            Assert.Equal(new[] { floor }, Floors(source));
            Assert.DoesNotContain(target + "=SupportedOSPlatform(\"" + floor + "\")",
                File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot, "generation", "WinSDK", "supportedOS.rsp")));
            string obj = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(source)));
            string settings = File.ReadAllText(Path.Combine(obj, "scratch", "common", "Wmi.settings.rsp"));
            Assert.Contains("parse-win32-annotations", settings);
            Assert.DoesNotContain("--nativeFieldArrayInfo", settings);

            string[] Floors(string path)
            {
                var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(path));
                var declaration = Assert.Single(tree.GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>()
                    .Where(node => node.Identifier.ValueText == target));
                return declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => attribute.Name.ToString() ==
                        "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform")
                    .Select(attribute => Assert.IsType<LiteralExpressionSyntax>(
                        Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText).ToArray();
            }
        }

        [HeaderMigrationDataTheory("WIN32METADATA_CLU_GENERATED_SOURCE")]
        [InlineData("MsCs", "cluadmex.h")]
        public void ActualNormalCluSourceProjectsAllOwnedFloorsWithoutLegacyFallback(string partition, string header)
        {
            string source = Environment.GetEnvironmentVariable("WIN32METADATA_CLU_GENERATED_SOURCE");
            var tree = CSharpSyntaxTree.ParseText(File.ReadAllText(source));
            var declarations = tree.GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>().ToArray();
            string[] expected = (string[])OriginalIdlNativeSamples().First(row =>
                (string)row[0] == partition && (string)row[1] == header && (string)row[4] == "c++")[7];
            Assert.Equal(17, expected.Length);
            string[] legacy = File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "supportedOS.rsp"));
            foreach (string fact in expected)
            {
                string[] parts = fact.Split('|');
                var declaration = Assert.Single(declarations.Where(node => node.Identifier.ValueText == parts[0]));
                var attribute = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(value => value.Name.ToString() ==
                        "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform"));
                string floor = Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                Assert.Equal(parts[1], "SupportedOSPlatform(\"" + floor + "\")");
                Assert.DoesNotContain(parts[0] + "=" + parts[1], legacy);
            }
            string obj = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(source)));
            string settings = File.ReadAllText(Path.Combine(obj, "scratch", "common", partition + ".settings.rsp"));
            Assert.Contains("parse-win32-annotations", settings);
            Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
        }

        [HeaderMigrationDataTheory("WINHTTP_PREPARED_HEADERS", "WINHTTP_PRISTINE_PREPARED_HEADERS",
            "WINHTTP_NATIVE_TOOLSET_INCLUDE", "WIN32METADATA_FACTORY_IDL_REPORT")]
        [MemberData(nameof(QuotedFactoryNativeSamples))]
        public void QuotedFactoriesPreservePublishedNativeAbiSalAndInterfaceFloors(
            string partition, string header, int functionCount, string architecture, string target,
            string language, bool cInterface, bool enabled)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_IDL_REPORT")));
            var owner = Assert.Single(report.RootElement.GetProperty("owners").EnumerateArray().Where(value =>
                value.GetProperty("generatedHeaders").EnumerateArray().Any(path =>
                    Path.GetFileName(path.GetString()).Equals(header, StringComparison.OrdinalIgnoreCase))));
            var dispositions = owner.GetProperty("dispositions").EnumerateArray().Where(value =>
                value.GetProperty("disposition").GetString() == "authored-original-idl").ToArray();
            Assert.Equal(functionCount, dispositions.Count(value =>
                value.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl"));
            string root = WinHttpMigrationTests.RepositoryRoot;
            string prerequisites = header switch
            {
                "dxva2api.h" or "dxvahd.h" or "opmapi.h" => "#include <d3d9.h>\n",
                "mfreadwrite.h" => "#include <mfidl.h>\n",
                _ => "",
            };
            string source = "#define SECURITY_WIN32\n#define QCC_OS_GROUP_WINDOWS\n" +
                (cInterface ? "#define CINTERFACE 1\n" : "") +
                "#include \"intrinfix.h\"\n#include \"windows.fixed.h\"\n#include <sdkddkver.h>\n" +
                prerequisites + "#include <" + header + ">\n";
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            string[] before = WinHttpNativeControlTests.Surface(root,
                Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS"), partition, architecture,
                target, new[] { header }, "", metadataEnabled: enabled, annotations: beforeAnnotations,
                sourceText: source, salAnnotations: beforeSal, diagnostics: beforeDiagnostics, language: language);
            string[] after = WinHttpNativeControlTests.Surface(root,
                Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS"), partition, architecture,
                target, new[] { header }, "", metadataEnabled: enabled, annotations: afterAnnotations,
                sourceText: source, salAnnotations: afterSal, diagnostics: afterDiagnostics, language: language);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            string[] interfaces = language == "c++" ? Facts("InterfaceDecl") : Array.Empty<string>();
            Assert.Equal(enabled ? interfaces : Array.Empty<string>(), AnnotationFacts(beforeAnnotations));
            Assert.Equal(enabled ? interfaces.Concat(Facts("FunctionDecl")).OrderBy(value => value, StringComparer.Ordinal)
                : Array.Empty<string>(), AnnotationFacts(afterAnnotations));
            this.output.WriteLine($"{partition}/{header}/{architecture}/{language}/CINTERFACE={cInterface}/metadata={enabled}: " +
                $"{before.Length} identical native facts without typedef normalization; {beforeSal.Count} identical SAL facts; " +
                $"{interfaces.Length} preserved interface floors and {functionCount} new exact factory floors when enabled.");

            string[] Facts(string kind) => dispositions.Where(value =>
                value.GetProperty("declaration").GetProperty("kind").GetString() == kind)
                .Select(value => value.GetProperty("fact").GetProperty("value").GetString().Replace('=', '|'))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            static string[] AnnotationFacts(IEnumerable<string> values) =>
                values.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal).ToArray();
        }

        public static IEnumerable<object[]> QuotedFactoryNativeSamples()
        {
            var owners = new[] { ("Mf", "mfidl.h", 72), ("Mf", "wmcontainer.h", 15), ("WmFormat", "wmsdkidl.h", 14) };
            string reportPath = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_IDL_REPORT");
            if (!string.IsNullOrEmpty(reportPath))
            {
                using var report = JsonDocument.Parse(File.ReadAllText(reportPath));
                owners = report.RootElement.GetProperty("owners").EnumerateArray()
                    .Where(owner => owner.GetProperty("changed").GetBoolean())
                    .Select(owner => (
                        Assert.Single(owner.GetProperty("partitionCandidates").EnumerateArray()).GetString(),
                        Path.GetFileName(Assert.Single(owner.GetProperty("generatedHeaders").EnumerateArray()).GetString()),
                        owner.GetProperty("dispositions").EnumerateArray().Count(value =>
                            value.GetProperty("disposition").GetString() == "authored-original-idl" &&
                            value.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl")))
                    .Where(owner => owner.Item3 != 0).ToArray();
                Assert.NotEmpty(owners);
            }
            foreach (var owner in owners)
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"), ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (var mode in new[] { ("c", false), ("c++", false), ("c++", true) })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[] { owner.Item1, owner.Item2, owner.Item3, architecture.Item1,
                                architecture.Item2, mode.Item1, mode.Item2, enabled };
        }

        [HeaderMigrationDataTheory("WINHTTP_PREPARED_HEADERS", "WINHTTP_PRISTINE_PREPARED_HEADERS",
            "WINHTTP_NATIVE_TOOLSET_INCLUDE", "WIN32METADATA_ORIGINAL_MEMBER_REPORT",
            "WIN32METADATA_ORIGINAL_MEMBER_BASE_REPORT")]
        [MemberData(nameof(PublishedMemberNativeSamples))]
        public void PublishedNativeMembersPreservePartitionAbiSalAndExactAnnotationPayloads(
            string partition, string architecture, string target)
        {
            using var current = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_REPORT")));
            using var baseline = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_BASE_REPORT")));
            var owners = Owners(current).ToArray();
            string[] headers = owners.SelectMany(owner => owner.GetProperty("generatedHeaders").EnumerateArray())
                .Select(value => Path.GetFileName(value.GetString())).Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            var newFacts = owners.SelectMany(owner => owner.GetProperty("dispositions").EnumerateArray()).ToArray();
            var originalFacts = Owners(baseline).SelectMany(owner =>
                owner.GetProperty("dispositions").EnumerateArray()).Where(value =>
                    value.GetProperty("disposition").GetString() == "authored-original-idl").ToArray();
            string root = WinHttpMigrationTests.RepositoryRoot;
            var beforeSal = new List<string>();
            var afterSal = new List<string>();
            var beforeDiagnostics = new List<string>();
            var afterDiagnostics = new List<string>();
            var beforeAnnotations = new List<string>();
            var afterAnnotations = new List<string>();
            string[] before = WinHttpNativeControlTests.Surface(root,
                Environment.GetEnvironmentVariable("WINHTTP_PRISTINE_PREPARED_HEADERS"), partition, architecture,
                target, headers, "", metadataEnabled: true, annotations: beforeAnnotations,
                salAnnotations: beforeSal, diagnostics: beforeDiagnostics, includeCallableOwners: true);
            string[] after = WinHttpNativeControlTests.Surface(root,
                Environment.GetEnvironmentVariable("WINHTTP_PREPARED_HEADERS"), partition, architecture,
                target, headers, "", metadataEnabled: true, annotations: afterAnnotations,
                salAnnotations: afterSal, diagnostics: afterDiagnostics, includeCallableOwners: true);
            Assert.NotEmpty(before);
            Assert.Equal(before, after);
            Assert.NotEmpty(beforeSal);
            Assert.Equal(beforeSal.OrderBy(value => value, StringComparer.Ordinal),
                afterSal.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Equal(beforeDiagnostics.OrderBy(value => value, StringComparer.Ordinal),
                afterDiagnostics.OrderBy(value => value, StringComparer.Ordinal));
            if (newFacts.All(value => value.GetProperty("fact").GetProperty("category").GetString() == "associated-enum-use"))
            {
                string[] expectedAssociations = newFacts.Select(value =>
                    value.GetProperty("declaration").GetProperty("nativeQualifiedName").GetString() + "|AssociatedEnum")
                    .OrderBy(value => value, StringComparer.Ordinal).ToArray();
                Assert.Equal(expectedAssociations, afterAnnotations.Except(beforeAnnotations, StringComparer.Ordinal)
                    .Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
                Assert.Equal(beforeAnnotations.OrderBy(value => value, StringComparer.Ordinal),
                    afterAnnotations.Where(value => !expectedAssociations.Contains(value, StringComparer.Ordinal))
                        .OrderBy(value => value, StringComparer.Ordinal));
                this.output.WriteLine($"{partition}/{architecture}: {before.Length} unchanged native ABI/value facts, " +
                    $"{beforeSal.Count} unchanged fully qualified SAL facts and all prior annotation multiplicities; " +
                    $"{newFacts.Length} exact new native association targets; actual normal controls check typed payloads.");
                return;
            }
            string[] expectedBefore = originalFacts.Select(Fact).OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(expectedBefore, beforeAnnotations.Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            string[] carriers = afterAnnotations.Where(value => value.StartsWith("_WIN32META_METHOD_", StringComparison.Ordinal)).ToArray();
            int methodCount = newFacts.Count(value =>
                value.GetProperty("declaration").GetProperty("kind").GetString() == "CXXMethodDecl");
            Assert.Equal(methodCount * 2, carriers.Length);
            foreach (var carrier in carriers.GroupBy(value => value.Split('|')[0], StringComparer.Ordinal))
                Assert.Equal(new[] { carrier.Key + "|Method", carrier.Key + "|PreserveResult" },
                    carrier.OrderBy(value => value, StringComparer.Ordinal));
            string[] expectedAfter = expectedBefore.Concat(newFacts.Where(value =>
                value.GetProperty("declaration").GetProperty("kind").GetString() != "CXXMethodDecl").Select(Fact))
                .OrderBy(value => value, StringComparer.Ordinal).ToArray();
            Assert.Equal(expectedAfter, afterAnnotations.Except(carriers, StringComparer.Ordinal)
                .Distinct(StringComparer.Ordinal).OrderBy(value => value, StringComparer.Ordinal));
            this.output.WriteLine($"{partition}/{architecture}: {before.Length} unchanged native ABI/value facts, " +
                $"{beforeSal.Count} unchanged fully qualified SAL facts, {newFacts.Length} exact new contracts; " +
                $"{methodCount} native method carriers also require the actual normal target assertion.");

            IEnumerable<JsonElement> Owners(JsonDocument document) => document.RootElement.GetProperty("owners").EnumerateArray()
                .Where(owner => owner.GetProperty("partitionCandidates").EnumerateArray().Any(value => value.GetString() == partition));
            static string Fact(JsonElement value)
            {
                var fact = value.GetProperty("fact");
                return fact.GetProperty("category").GetString() switch
                {
                    "supportedOS" => fact.GetProperty("value").GetString().Replace('=', '|'),
                    "setLastError" => fact.GetProperty("symbol").GetString() + "|SetLastError",
                    "declaration-attribute-override" when value.GetProperty("macro").GetString() == "_Win32_Retval_" =>
                        value.GetProperty("declaration").GetProperty("qualifiedName").GetString() + "|RetVal",
                    _ => throw new InvalidOperationException("Every raw native payload needs its exact declared contract."),
                };
            }
        }

        public static IEnumerable<object[]> PublishedMemberNativeSamples()
        {
            string path = Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_REPORT");
            if (string.IsNullOrEmpty(path))
            {
                yield return new object[] { "Dxgi", "x64", "x86_64-pc-windows-msvc" };
                yield break;
            }
            using var report = JsonDocument.Parse(File.ReadAllText(path));
            foreach (string partition in report.RootElement.GetProperty("owners").EnumerateArray()
                .SelectMany(owner => owner.GetProperty("partitionCandidates").EnumerateArray())
                .Select(value => value.GetString()).Distinct(StringComparer.Ordinal))
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"), ("x64", "x86_64-pc-windows-msvc"), ("arm64", "aarch64-pc-windows-msvc"),
                })
                    yield return new object[] { partition, architecture.Item1, architecture.Item2 };
        }

        [HeaderMigrationDataTheory("WIN32METADATA_ORIGINAL_MEMBER_REPORT", "WIN32METADATA_FACTORY_NORMAL_OBJ",
            "WIN32METADATA_FACTORY_PUBLISHED_OBJ")]
        [MemberData(nameof(PublishedMemberNormalSamples))]
        public void ActualNormalNativeMembersHaveExactPayloadsImportsAndCompleteInheritedProjection(
            string partition, string architecture, int factCount)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_REPORT")));
            var facts = report.RootElement.GetProperty("owners").EnumerateArray().Where(owner =>
                owner.GetProperty("partitionCandidates").EnumerateArray().Any(value => value.GetString() == partition))
                .SelectMany(owner => owner.GetProperty("dispositions").EnumerateArray()).ToArray();
            Assert.Equal(factCount, facts.Length);
            string positiveObj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_NORMAL_OBJ");
            string beforeObj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_PUBLISHED_OBJ");
            var positive = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(
                positiveObj, "generated", architecture, partition + ".cs"))).GetRoot();
            var before = CSharpSyntaxTree.ParseText(File.ReadAllText(Path.Combine(
                beforeObj, "generated", architecture, partition + ".cs"))).GetRoot();
            var added = new HashSet<SyntaxNode>();
            var projections = new List<object>();
            foreach (var disposition in facts)
            {
                var fact = disposition.GetProperty("fact");
                string category = fact.GetProperty("category").GetString();
                string symbol = fact.GetProperty("symbol").GetString();
                string kind = disposition.GetProperty("declaration").GetProperty("kind").GetString();
                string macro = disposition.GetProperty("macro").GetString();
                var oldTargets = Targets(before, kind, symbol).ToDictionary(Key, StringComparer.Ordinal);
                var newTargets = Targets(positive, kind, symbol).ToDictionary(Key, StringComparer.Ordinal);
                Assert.NotEmpty(newTargets);
                Assert.Equal(oldTargets.Keys.OrderBy(value => value, StringComparer.Ordinal),
                    newTargets.Keys.OrderBy(value => value, StringComparer.Ordinal));
                Assert.DoesNotContain(fact.GetProperty("value").GetString(), File.ReadAllLines(Path.Combine(
                    WinHttpMigrationTests.RepositoryRoot, fact.GetProperty("source").GetString())));
                foreach (var pair in newTargets)
                {
                    var attributes = Attributes(pair.Value).ToArray();
                    var oldAttributes = Attributes(oldTargets[pair.Key]).ToArray();
                    projections.Add(new
                    {
                        FactId = fact.GetProperty("factId").GetString(), Symbol = symbol,
                        Declaration = pair.Key, Kind = pair.Value.Kind().ToString(), Macro = macro,
                    });
                    if (kind == "FunctionDecl")
                    {
                        string library = fact.GetProperty("existingImportLibrary").GetString();
                        Assert.False(string.IsNullOrEmpty(library));
                        var import = Assert.Single(attributes.Where(IsImport));
                        Assert.Equal(library, Assert.IsType<LiteralExpressionSyntax>(
                            import.ArgumentList.Arguments[0].Expression).Token.ValueText);
                        if (category == "setLastError")
                        {
                            var flag = Assert.Single(import.ArgumentList.Arguments.Where(argument =>
                                argument.NameEquals?.Name.Identifier.ValueText == "SetLastError"));
                            Assert.Equal(SyntaxKind.TrueLiteralExpression, flag.Expression.Kind());
                            Assert.Empty(Assert.Single(oldAttributes.Where(IsImport)).ArgumentList.Arguments.Where(argument =>
                                argument.NameEquals?.Name.Identifier.ValueText == "SetLastError"));
                            added.Add(flag);
                            continue;
                        }
                    }
                    string name = macro switch
                    {
                        "_Win32_PreserveResult_" => "global::System.Runtime.InteropServices.PreserveSig",
                        "_Win32_Retval_" => "global::Windows.Win32.Foundation.Metadata.RetVal",
                        _ when category == "supportedOS" => "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform",
                        _ when category == "associated-enum-use" => "global::Windows.Win32.Foundation.Metadata.AssociatedEnum",
                        _ => throw new InvalidOperationException("Unknown native contract projection."),
                    };
                    var attribute = Assert.Single(attributes.Where(value => value.Name.ToString() == name));
                    Assert.Empty(oldAttributes.Where(value => value.Name.ToString() == name));
                    if (category == "supportedOS")
                    {
                        string payload = "SupportedOSPlatform(\"" + Assert.IsType<LiteralExpressionSyntax>(
                            Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText + "\")";
                        Assert.Equal(symbol + "=" + payload, fact.GetProperty("value").GetString());
                    }
                    else if (category == "associated-enum-use")
                    {
                        string payload = Assert.IsType<LiteralExpressionSyntax>(
                            Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                        Assert.Equal(symbol + "=[AssociatedEnum(\"" + payload + "\")]", fact.GetProperty("value").GetString());
                    }
                    var list = Assert.IsType<AttributeListSyntax>(attribute.Parent);
                    Assert.Single(list.Attributes);
                    added.Add(list);
                }
                this.output.WriteLine($"{symbol}: {newTargets.Count} exact native/derived projection sites.");
            }
            string evidenceDirectory = Path.GetDirectoryName(
                Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_REPORT"));
            File.WriteAllText(Path.Combine(evidenceDirectory,
                partition + "." + architecture + "." + Path.GetFileName(positiveObj) + ".projections.json"),
                JsonSerializer.Serialize(projections));
            var remaining = positive.RemoveNodes(added, SyntaxRemoveOptions.KeepNoTrivia);
            var coordinates = new List<object>();
            if (!SyntaxFactory.AreEquivalent(before, remaining))
            {
                var oldTokens = before.DescendantTokens().ToArray();
                var newTokens = remaining.DescendantTokens().ToArray();
                var replacements = new Dictionary<SyntaxToken, SyntaxToken>();
                if (oldTokens.Length == newTokens.Length)
                {
                    foreach (var pair in oldTokens.Zip(newTokens).Where(pair => pair.First.Text != pair.Second.Text))
                    {
                        const string pattern = @"^__AnonymousRecord_(?<header>.+)_L(?<line>\d+)_C(?<column>\d+)$";
                        var oldCoordinate = Regex.Match(pair.First.ValueText, pattern);
                        var newCoordinate = Regex.Match(pair.Second.ValueText, pattern);
                        if (!pair.First.IsKind(SyntaxKind.StringLiteralToken) ||
                            !pair.Second.IsKind(SyntaxKind.StringLiteralToken) ||
                            !oldCoordinate.Success || !newCoordinate.Success)
                            continue;
                        Assert.Equal("NativeTypeName", pair.First.Parent.AncestorsAndSelf()
                            .OfType<AttributeSyntax>().Single().Name.ToString());
                        Assert.Equal("NativeTypeName", pair.Second.Parent.AncestorsAndSelf()
                            .OfType<AttributeSyntax>().Single().Name.ToString());
                        Assert.Equal(Key(pair.First.Parent), Key(pair.Second.Parent));
                        Assert.Equal(oldCoordinate.Groups["header"].Value, newCoordinate.Groups["header"].Value);
                        Assert.Equal(oldCoordinate.Groups["column"].Value, newCoordinate.Groups["column"].Value);
                        var owner = Assert.Single(report.RootElement.GetProperty("owners").EnumerateArray().Where(value =>
                            string.Equals(Path.GetFileNameWithoutExtension(value.GetProperty("original").GetString()),
                                oldCoordinate.Groups["header"].Value, StringComparison.OrdinalIgnoreCase)));
                        string original = owner.GetProperty("original").GetString();
                        string oldInclude = File.ReadAllText(Path.Combine(beforeObj, "prepared-sdk.txt")).Trim();
                        string newInclude = File.ReadAllText(Path.Combine(positiveObj, "prepared-sdk.txt")).Trim();
                        using var oldCommands = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                            Path.GetDirectoryName(oldInclude), "midl", "commands.json")));
                        using var newCommands = JsonDocument.Parse(File.ReadAllText(Path.Combine(
                            Path.GetDirectoryName(newInclude), "midl", "commands.json")));
                        string oldHeader = Assert.Single(oldCommands.RootElement.EnumerateArray().Where(value =>
                            value.GetProperty("source").GetString() == original)).GetProperty("header").GetString();
                        string newHeader = Assert.Single(newCommands.RootElement.EnumerateArray().Where(value =>
                            value.GetProperty("source").GetString() == original)).GetProperty("header").GetString();
                        Assert.Equal(oldHeader, newHeader);
                        byte[] oldBytes = File.ReadAllBytes(Path.Combine(oldInclude, oldHeader));
                        byte[] newBytes = File.ReadAllBytes(Path.Combine(newInclude, newHeader));
                        string oldText = Encoding.Latin1.GetString(oldBytes);
                        string newText = Encoding.Latin1.GetString(newBytes);
                        string recovered = newText;
                        var carrierLines = new List<int>();
                        foreach (var disposition in owner.GetProperty("dispositions").EnumerateArray())
                        {
                            Assert.Equal("CXXMethodDecl", disposition.GetProperty("declaration").GetProperty("kind").GetString());
                            Assert.Equal("_Win32_PreserveResult_", disposition.GetProperty("macro").GetString());
                            string carrier = "/* Win32Metadata: method ::" +
                                disposition.GetProperty("fact").GetProperty("symbol").GetString() + " => PreserveResult */";
                            Assert.DoesNotContain(carrier, oldText);
                            string linePattern = @"(?m)^[\t ]*" + Regex.Escape(carrier) + @"\r?\n";
                            var line = Assert.Single(Regex.Matches(newText, linePattern).Cast<Match>());
                            carrierLines.Add(newText.Take(line.Index).Count(value => value == '\n') + 1);
                            recovered = Regex.Replace(recovered, linePattern, string.Empty);
                        }
                        Assert.Equal(oldText, recovered);
                        int oldLine = int.Parse(oldCoordinate.Groups["line"].Value);
                        int newLine = int.Parse(newCoordinate.Groups["line"].Value);
                        int insertedBeforeRecord = carrierLines.Count(line => line < newLine);
                        Assert.Equal(oldLine + insertedBeforeRecord, newLine);
                        Assert.Equal(oldText.Split('\n')[oldLine - 1], newText.Split('\n')[newLine - 1]);
                        replacements.Add(pair.Second, pair.First);
                        coordinates.Add(new
                        {
                            Declaration = Key(pair.Second.Parent), Original = original, Header = oldHeader,
                            Before = pair.First.ValueText, After = pair.Second.ValueText,
                            BeforeHeaderSha256 = Convert.ToHexString(SHA256.HashData(oldBytes)),
                            AfterHeaderSha256 = Convert.ToHexString(SHA256.HashData(newBytes)),
                            EveryNativeHeaderByteRecoveredByRemovingOnlyExactNewMethodCarriers = true,
                            NewCarrierLines = carrierLines, InsertedLinesBeforeRecord = insertedBeforeRecord,
                        });
                    }
                }
                remaining = remaining.ReplaceTokens(replacements.Keys, (token, _) =>
                    replacements[token].WithTriviaFrom(token));
            }
            File.WriteAllText(Path.Combine(evidenceDirectory,
                partition + "." + architecture + "." + Path.GetFileName(positiveObj) + ".coordinates.json"),
                JsonSerializer.Serialize(coordinates));
            if (!SyntaxFactory.AreEquivalent(before, remaining))
            {
                var oldTokens = before.DescendantTokens().ToArray();
                var newTokens = remaining.DescendantTokens().ToArray();
                var differences = oldTokens.Zip(newTokens).Select((pair, index) => new { pair.First, pair.Second, Index = index })
                    .Where(pair => pair.First.RawKind != pair.Second.RawKind || pair.First.Text != pair.Second.Text)
                    .Select(pair => new { pair.Index, Before = Describe(pair.First), After = Describe(pair.Second) }).ToArray();
                string directory = Path.Combine(Path.GetDirectoryName(
                    Environment.GetEnvironmentVariable("WIN32METADATA_ORIGINAL_MEMBER_REPORT")), "normal-differences");
                Directory.CreateDirectory(directory);
                string path = Path.Combine(directory, partition + "." + architecture + "." + Path.GetFileName(positiveObj) + ".json");
                File.WriteAllText(path, JsonSerializer.Serialize(new
                {
                    BeforeTokenCount = oldTokens.Length, AfterTokenCount = newTokens.Length, Differences = differences,
                }));
                Assert.True(false, "Actual normal source has unwaived differences beyond exact new contracts: " + path);
            }
            foreach (string directory in new[] { positiveObj, beforeObj })
            {
                string settings = File.ReadAllText(Path.Combine(directory, "scratch", architecture, partition + ".settings.rsp"));
                Assert.Contains("parse-win32-annotations", settings);
                Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
            }

            static IEnumerable<AttributeSyntax> Attributes(SyntaxNode node) => (node switch
            {
                MemberDeclarationSyntax member => member.AttributeLists,
                ParameterSyntax parameter => parameter.AttributeLists,
                _ => throw new InvalidOperationException("A native fact requires its exact declaration or parameter."),
            }).SelectMany(list => list.Attributes);
            static bool IsImport(AttributeSyntax value) => value.Name.ToString() is
                "DllImport" or "global::System.Runtime.InteropServices.DllImport";
            static string Key(SyntaxNode node) => string.Join("::", node.AncestorsAndSelf().Reverse().Select(value => value switch
            {
                TypeDeclarationSyntax type => type.Identifier.ValueText,
                MethodDeclarationSyntax method => method.Identifier.ValueText,
                DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                ParameterSyntax parameter => parameter.Identifier.ValueText,
                FieldDeclarationSyntax field => Assert.Single(field.Declaration.Variables).Identifier.ValueText,
                _ => null,
            }).Where(value => value != null));
            static object Describe(SyntaxToken token) => new
            {
                Kind = token.Kind().ToString(), token.Text, token.ValueText,
                Attribute = token.Parent.AncestorsAndSelf().OfType<AttributeSyntax>().FirstOrDefault()?.Name.ToString(),
                Declaration = Key(token.Parent),
            };
            static IEnumerable<SyntaxNode> Targets(SyntaxNode root, string kind, string symbol)
            {
                string[] parts = symbol.Split("::", StringSplitOptions.None);
                if (kind == "FunctionDecl")
                    return root.DescendantNodes().OfType<MethodDeclarationSyntax>().Where(method =>
                        method.Identifier.ValueText == symbol && method.AttributeLists.SelectMany(list => list.Attributes).Any(IsImport));
                var types = root.DescendantNodes().OfType<TypeDeclarationSyntax>().ToLookup(type =>
                    type.Identifier.ValueText, StringComparer.Ordinal);
                if (kind == "FieldDecl")
                    return types[parts[0]].SelectMany(type => type.Members.OfType<FieldDeclarationSyntax>())
                        .Where(field => field.Declaration.Variables.Any(variable => variable.Identifier.ValueText == parts[1]));
                var methods = types.SelectMany(group => group).Where(IsOwnerOrDerived)
                    .SelectMany(type => type.Members.OfType<MethodDeclarationSyntax>())
                    .Where(method => method.Identifier.ValueText == parts[1]).ToArray();
                var callables = methods.Cast<SyntaxNode>().Concat(methods.SelectMany(AssociatedDelegates)).ToArray();
                return kind switch
                {
                    "CXXMethodDecl" => callables,
                    "ParmVarDecl" => callables.SelectMany(callable => callable switch
                        {
                            MethodDeclarationSyntax method => method.ParameterList.Parameters,
                            DelegateDeclarationSyntax callback => callback.ParameterList.Parameters,
                            _ => throw new InvalidOperationException("A native callable requires its exact parameter list."),
                        })
                        .Where(parameter => parameter.Identifier.ValueText == parts[2]),
                    _ => throw new InvalidOperationException("Unknown native member kind."),
                };

                static IEnumerable<DelegateDeclarationSyntax> AssociatedDelegates(MethodDeclarationSyntax method)
                {
                    var owner = Assert.IsAssignableFrom<TypeDeclarationSyntax>(method.Parent);
                    foreach (var reference in method.DescendantNodes().OfType<GenericNameSyntax>()
                        .Where(value => value.Identifier.ValueText == "GetDelegateForFunctionPointer"))
                    {
                        string name = Assert.IsType<IdentifierNameSyntax>(
                            Assert.Single(reference.TypeArgumentList.Arguments)).Identifier.ValueText;
                        var callback = Assert.Single(owner.Members.OfType<DelegateDeclarationSyntax>()
                            .Where(value => value.Identifier.ValueText == name));
                        Assert.Equal(method.ReturnType.ToString(), callback.ReturnType.ToString());
                        Assert.Equal(method.ParameterList.Parameters.Count + 1, callback.ParameterList.Parameters.Count);
                        var receiver = Assert.IsType<PointerTypeSyntax>(callback.ParameterList.Parameters[0].Type);
                        Assert.Equal(owner.Identifier.ValueText, receiver.ElementType.ToString());
                        for (int index = 0; index < method.ParameterList.Parameters.Count; index++)
                            Assert.True(SyntaxFactory.AreEquivalent(method.ParameterList.Parameters[index],
                                callback.ParameterList.Parameters[index + 1]),
                                "The actual vtable delegate must preserve its native wrapper parameter exactly.");
                        yield return callback;
                    }
                }

                bool IsOwnerOrDerived(TypeDeclarationSyntax type)
                {
                    var visited = new HashSet<string>(StringComparer.Ordinal);
                    while (visited.Add(type.Identifier.ValueText))
                    {
                        if (type.Identifier.ValueText == parts[0])
                            return true;
                        var inheritance = type.AttributeLists.SelectMany(list => list.Attributes)
                            .SingleOrDefault(value => value.Name.ToString() == "NativeInheritance");
                        if (inheritance == null)
                            return false;
                        string parent = Assert.IsType<LiteralExpressionSyntax>(
                            Assert.Single(inheritance.ArgumentList.Arguments).Expression).Token.ValueText;
                        if (parent == parts[0])
                            return true;
                        if (!types.Contains(parent))
                            return false;
                        type = Assert.Single(types[parent]);
                    }
                    throw new InvalidOperationException("The actual normal native inheritance graph contains a cycle.");
                }
            }
        }

        public static IEnumerable<object[]> PublishedMemberNormalSamples() =>
            PublishedNormalSamples("WIN32METADATA_ORIGINAL_MEMBER_REPORT", functionsOnly: false);

        [HeaderMigrationDataTheory("WIN32METADATA_FACTORY_IDL_REPORT", "WIN32METADATA_FACTORY_NORMAL_OBJ",
            "WIN32METADATA_FACTORY_PUBLISHED_OBJ")]
        [MemberData(nameof(PublishedQuotedFactoryNormalSamples))]
        public void ActualNormalQuotedCallablesAddOnlyExactNewFloorsToPublishedSourcesWithoutLegacyFallback(
            string partition, string architecture, int functionCount)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_IDL_REPORT")));
            var dispositions = report.RootElement.GetProperty("owners").EnumerateArray().Where(owner =>
                owner.GetProperty("partitionCandidates").EnumerateArray().Any(value => value.GetString() == partition))
                .SelectMany(owner => owner.GetProperty("dispositions").EnumerateArray()).Where(value =>
                    value.GetProperty("disposition").GetString() == "authored-original-idl" &&
                    value.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl").ToArray();
            Assert.Equal(functionCount, dispositions.Length);
            string obj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_NORMAL_OBJ");
            string publishedObj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_PUBLISHED_OBJ");
            var positive = CSharpSyntaxTree.ParseText(File.ReadAllText(
                Path.Combine(obj, "generated", architecture, partition + ".cs"))).GetRoot();
            var published = CSharpSyntaxTree.ParseText(File.ReadAllText(
                Path.Combine(publishedObj, "generated", architecture, partition + ".cs"))).GetRoot();
            var positiveMethods = positive.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var publishedMethods = published.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var newFloors = new List<AttributeListSyntax>();
            string[] legacy = File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "supportedOS.rsp"));
            foreach (var disposition in dispositions)
            {
                var fact = disposition.GetProperty("fact");
                string symbol = fact.GetProperty("symbol").GetString();
                string payload = fact.GetProperty("value").GetString().Substring(symbol.Length + 1);
                var declaration = Assert.Single(positiveMethods[symbol]);
                if (fact.TryGetProperty("existingImportLibrary", out var library))
                {
                    Assert.False(string.IsNullOrEmpty(library.GetString()));
                    var import = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(value => value.Name.ToString() is "DllImport" or "global::System.Runtime.InteropServices.DllImport"));
                    Assert.Equal(library.GetString(), Assert.IsType<LiteralExpressionSyntax>(
                        import.ArgumentList.Arguments[0].Expression).Token.ValueText);
                }
                var attribute = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes).Where(IsFloor));
                string floor = Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                Assert.Equal(payload, "SupportedOSPlatform(\"" + floor + "\")");
                var list = Assert.IsType<AttributeListSyntax>(attribute.Parent);
                Assert.Single(list.Attributes);
                newFloors.Add(list);
                Assert.Empty(Assert.Single(publishedMethods[symbol]).AttributeLists
                    .SelectMany(value => value.Attributes).Where(IsFloor));
                Assert.DoesNotContain(symbol + "=" + payload, legacy);
            }
            Assert.True(SyntaxFactory.AreEquivalent(published,
                positive.RemoveNodes(newFloors, SyntaxRemoveOptions.KeepNoTrivia)),
                "The actual normal source changed beyond the exact new function floors.");
            foreach (string directory in new[] { obj, publishedObj })
            {
                string settings = File.ReadAllText(Path.Combine(directory, "scratch", architecture, partition + ".settings.rsp"));
                Assert.Contains("parse-win32-annotations", settings);
                Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
            }
            this.output.WriteLine($"{partition}/{architecture}: {functionCount} exact new function floors; " +
                "all published C# declarations, native return values, imports and unrelated syntax preserved.");

            static bool IsFloor(AttributeSyntax attribute) => attribute.Name.ToString() ==
                "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform";
        }

        public static IEnumerable<object[]> PublishedQuotedFactoryNormalSamples() =>
            PublishedNormalSamples("WIN32METADATA_FACTORY_IDL_REPORT", functionsOnly: true);

        private static IEnumerable<object[]> PublishedNormalSamples(string reportVariable, bool functionsOnly)
        {
            string reportPath = Environment.GetEnvironmentVariable(reportVariable);
            if (string.IsNullOrEmpty(reportPath))
            {
                yield return new object[] { "Mf", "x64", 13 };
                yield break;
            }
            using var report = JsonDocument.Parse(File.ReadAllText(reportPath));
            Assert.True(report.RootElement.GetProperty("normalParserActivation").GetProperty("ready").GetBoolean());
            var project = System.Xml.Linq.XDocument.Load(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "Windows.Win32.proj"));
            var common = new HashSet<string>(Assert.Single(project.Descendants().Where(element =>
                element.Name.LocalName == "ExcludeFromCrossarch")).Value.Split(';',
                    StringSplitOptions.RemoveEmptyEntries | StringSplitOptions.TrimEntries), StringComparer.Ordinal);
            foreach (var group in report.RootElement.GetProperty("owners").EnumerateArray()
                .SelectMany(owner => owner.GetProperty("partitionCandidates").EnumerateArray().Select(partition =>
                    (Partition: partition.GetString(), Owner: owner))).GroupBy(value => value.Partition, StringComparer.Ordinal))
            {
                int factCount = group.SelectMany(value => value.Owner.GetProperty("dispositions").EnumerateArray())
                    .Count(value => value.GetProperty("disposition").GetString() == "authored-original-idl" &&
                        (!functionsOnly || value.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl"));
                Assert.True(factCount > 0);
                foreach (string architecture in common.Contains(group.Key)
                    ? new[] { "common" } : new[] { "x86", "x64", "arm64" })
                    yield return new object[] { group.Key, architecture, factCount };
            }
        }

        [HeaderMigrationDataTheory("WIN32METADATA_FACTORY_IDL_REPORT", "WIN32METADATA_FACTORY_NORMAL_OBJ",
            "WIN32METADATA_FACTORY_DISABLED_OBJ")]
        [InlineData("Mf", "x86", 87)]
        [InlineData("Mf", "x64", 87)]
        [InlineData("Mf", "arm64", 87)]
        [InlineData("WmFormat", "common", 14)]
        public void ActualNormalFactorySourcesPreserveNativeReturnValuesAndExactOwnedFloorsWithoutLegacyFallback(
            string partition, string architecture, int functionCount)
        {
            using var report = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_IDL_REPORT")));
            var dispositions = report.RootElement.GetProperty("owners").EnumerateArray().Where(owner =>
                owner.GetProperty("partitionCandidates").EnumerateArray().Any(value => value.GetString() == partition))
                .SelectMany(owner => owner.GetProperty("dispositions").EnumerateArray()).ToArray();
            Assert.Equal(functionCount, dispositions.Count(value =>
                value.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl"));
            string obj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_NORMAL_OBJ");
            string disabledObj = Environment.GetEnvironmentVariable("WIN32METADATA_FACTORY_DISABLED_OBJ");
            var positive = CSharpSyntaxTree.ParseText(File.ReadAllText(
                Path.Combine(obj, "generated", architecture, partition + ".cs"))).GetRoot();
            var disabled = CSharpSyntaxTree.ParseText(File.ReadAllText(
                Path.Combine(disabledObj, "generated", architecture, partition + ".cs"))).GetRoot();
            var positiveMethods = positive.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var disabledMethods = disabled.DescendantNodes().OfType<MethodDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var positiveTypes = positive.DescendantNodes().OfType<TypeDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var disabledTypes = disabled.DescendantNodes().OfType<TypeDeclarationSyntax>()
                .ToLookup(node => node.Identifier.ValueText, StringComparer.Ordinal);
            var expectedLists = new List<AttributeListSyntax>();
            string[] legacy = File.ReadAllLines(Path.Combine(WinHttpMigrationTests.RepositoryRoot,
                "generation", "WinSDK", "supportedOS.rsp"));
            foreach (var disposition in dispositions)
            {
                var fact = disposition.GetProperty("fact");
                string symbol = fact.GetProperty("symbol").GetString();
                string payload = fact.GetProperty("value").GetString().Substring(symbol.Length + 1);
                bool function = disposition.GetProperty("declaration").GetProperty("kind").GetString() == "FunctionDecl";
                var declaration = Declaration(true);
                var attribute = Assert.Single(declaration.AttributeLists.SelectMany(list => list.Attributes).Where(IsFloor));
                string floor = Assert.IsType<LiteralExpressionSyntax>(
                    Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText;
                Assert.Equal(payload, "SupportedOSPlatform(\"" + floor + "\")");
                var list = Assert.IsType<AttributeListSyntax>(attribute.Parent);
                Assert.Single(list.Attributes);
                expectedLists.Add(list);
                Assert.Empty(Declaration(false).AttributeLists.SelectMany(value => value.Attributes).Where(IsFloor));
                Assert.DoesNotContain(symbol + "=" + payload, legacy);

                MemberDeclarationSyntax Declaration(bool enabled) => function
                    ? Assert.Single((enabled ? positiveMethods : disabledMethods)[symbol])
                    : Assert.Single((enabled ? positiveTypes : disabledTypes)[symbol]);
            }
            // The existing reader also preserves these unchanged native IDL retval contracts.
            string[] expectedReturnValues = partition == "Mf" ? new[]
            {
                "IMFActivate.ActivateObject.ppv",
                "IMFActivate._ActivateObject.ppv",
                "IMFVideoProcessorControl2.GetSupportedHardwareEffects.puiSupport",
                "IMFVideoProcessorControl2._GetSupportedHardwareEffects.puiSupport",
                "IMFVideoProcessorControl3.GetSupportedHardwareEffects.puiSupport",
                "IMFVideoProcessorControl3._GetSupportedHardwareEffects.puiSupport",
            } : Array.Empty<string>();
            var returnValues = new List<string>();
            foreach (var parameter in positive.DescendantNodes().OfType<ParameterSyntax>())
            {
                var attributes = parameter.AttributeLists.SelectMany(list => list.Attributes).Where(IsReturnValue).ToArray();
                if (attributes.Length == 0)
                    continue;
                var attribute = Assert.Single(attributes);
                Assert.Null(attribute.ArgumentList);
                var list = Assert.IsType<AttributeListSyntax>(attribute.Parent);
                Assert.Single(list.Attributes);
                expectedLists.Add(list);
                var member = parameter.Parent.Parent;
                string name = member switch
                {
                    MethodDeclarationSyntax method => method.Identifier.ValueText,
                    DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                    _ => throw new InvalidOperationException("An expected native retval requires a method or its delegate."),
                };
                var type = Assert.IsType<StructDeclarationSyntax>(member.Parent);
                returnValues.Add(type.Identifier.ValueText + "." + name + "." + parameter.Identifier.ValueText);
            }
            Assert.Equal(expectedReturnValues, returnValues.OrderBy(value => value, StringComparer.Ordinal));
            Assert.Empty(disabled.DescendantNodes().OfType<AttributeSyntax>().Where(IsReturnValue));
            Assert.True(SyntaxFactory.AreEquivalent(
                positive.RemoveNodes(expectedLists, SyntaxRemoveOptions.KeepNoTrivia), disabled),
                "Disabling annotation parsing must change only the exact owned floors and proven native retval attributes, not declarations, imports or native names.");
            string settings = File.ReadAllText(Path.Combine(obj, "scratch", architecture, partition + ".settings.rsp"));
            Assert.Contains("parse-win32-annotations", settings);
            Assert.DoesNotContain("--nativeFieldArrayInfo", settings);
            this.output.WriteLine($"{partition}/{architecture}: {dispositions.Length} exact owned floors " +
                $"({functionCount} factories), {returnValues.Count} exact existing native retval placements; " +
                "all remaining syntax, native names, SAL and imports unchanged.");

            static bool IsFloor(AttributeSyntax value) =>
                value.Name.ToString() == "global::Windows.Win32.Foundation.Metadata.SupportedOSPlatform";
            static bool IsReturnValue(AttributeSyntax value) =>
                value.Name.ToString() == "global::Windows.Win32.Foundation.Metadata.RetVal";
        }

        [HeaderMigrationDataTheory("WINHTTP_PREPARED_HEADERS", "WINHTTP_PRISTINE_PREPARED_HEADERS")]
        [MemberData(nameof(OriginalIdlNativeSamples))]
        public void OriginalIdlBatchKeepsNativeSurfaceWithExactInterfaceFloors(
            string partition, string header, string architecture, string target, string language,
            bool cInterface, bool enabled, string[] expected) =>
            new WinHttpNativeControlTests(this.output).OriginalIdlBatchPreservesNativeAbiAndSalWithExactMetadata(
                partition, header, architecture, target, language, cInterface, enabled, expected);

        public static IEnumerable<object[]> OriginalIdlNativeSamples()
        {
            var owners = new[]
            {
                ("Wmi", "wbemcli.h", new[]
                {
                    "IEnumWbemClassObject", "IMofCompiler", "IUnsecuredApartment", "IWbemBackupRestore",
                    "IWbemBackupRestoreEx", "IWbemCallResult", "IWbemClassObject", "IWbemConfigureRefresher",
                    "IWbemContext", "IWbemHiPerfEnum", "IWbemLocator", "IWbemObjectAccess", "IWbemObjectSink",
                    "IWbemObjectSinkEx", "IWbemObjectTextSrc", "IWbemQualifierSet", "IWbemRefresher",
                    "IWbemServices", "IWbemShutdown", "IWbemStatusCodeText",
                }.Select(name => name + "|SupportedOSPlatform(\"windows6.0.6000\")").Append(
                    "IWbemUnsecuredApartment|SupportedOSPlatform(\"windowsserver2008\")").ToArray()),
                ("Mbn", "mbnapi.h", new[]
                {
                    "IMbnConnection", "IMbnConnectionContext", "IMbnConnectionContextEvents",
                    "IMbnConnectionEvents", "IMbnConnectionManager", "IMbnConnectionManagerEvents",
                    "IMbnConnectionProfile", "IMbnConnectionProfileEvents", "IMbnConnectionProfileManager",
                    "IMbnConnectionProfileManagerEvents", "IMbnDeviceService", "IMbnDeviceServicesContext",
                    "IMbnDeviceServicesEvents", "IMbnDeviceServicesManager", "IMbnInterface",
                    "IMbnInterfaceEvents", "IMbnInterfaceManager", "IMbnInterfaceManagerEvents",
                    "IMbnMultiCarrier", "IMbnMultiCarrierEvents", "IMbnPin", "IMbnPinEvents", "IMbnPinManager",
                    "IMbnPinManagerEvents", "IMbnRadio", "IMbnRadioEvents", "IMbnRegistration",
                    "IMbnRegistrationEvents", "IMbnServiceActivation", "IMbnServiceActivationEvents",
                    "IMbnSignal", "IMbnSignalEvents", "IMbnSms", "IMbnSmsConfiguration", "IMbnSmsEvents",
                    "IMbnSmsReadMsgPdu", "IMbnSmsReadMsgTextCdma", "IMbnSubscriberInformation",
                    "IMbnVendorSpecificEvents", "IMbnVendorSpecificOperation",
                }.Select(name => name + "|SupportedOSPlatform(\"" + (name is
                    "IMbnDeviceService" or "IMbnDeviceServicesContext" or "IMbnDeviceServicesEvents" or
                    "IMbnDeviceServicesManager" or "IMbnMultiCarrier" or "IMbnMultiCarrierEvents"
                        ? "windows8.0" : "windows6.1") + "\")").ToArray()),
                ("Media.DShow", "videoacc.h", new[]
                {
                    "IAMVideoAccelerator|SupportedOSPlatform(\"windows5.0\")",
                    "IAMVideoAcceleratorNotify|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("VSS", "vss.h", new[]
                {
                    "IVssAsync|SupportedOSPlatform(\"windows5.1.2600\")",
                    "IVssEnumObject|SupportedOSPlatform(\"windows5.1.2600\")",
                }),
                ("Xps", "xpsobjectmodel_2.h", new[]
                {
                    "IXpsDocumentPackageTarget3D|SupportedOSPlatform(\"windows8.1\")",
                    "IXpsOMPackageWriter3D|SupportedOSPlatform(\"windows8.1\")",
                }),
                ("Audio.Endpoints", "audioendpoints.h", new[]
                {
                    "IAudioEndpointFormatControl|SupportedOSPlatform(\"windows6.1\")",
                }),
                ("Bits", "bits1_5.h", new[]
                {
                    "IBackgroundCopyJob2|SupportedOSPlatform(\"windows6.0.6000\")",
                }),
                ("Certificates", "certmod.h", new[]
                {
                    "ICertManageModule|SupportedOSPlatform(\"windowsserver2003\")",
                }),
                ("Tsf", "ctfspui.h", new[]
                {
                    "ITfSpeechUIServer|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("Com", "ctxtcall.h", new[]
                {
                    "IContextCallback|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("Direct3D11", "d3d11_4.h", new[]
                {
                    "ID3D11VideoContext2|SupportedOSPlatform(\"windows10.0.10240\")",
                }),
                ("DirectComp", "dcompanimation.h", new[]
                {
                    "IDCompositionAnimation|SupportedOSPlatform(\"windows8.0\")",
                }),
                ("Media.DShow", "dmodshow.h", new[]
                {
                    "IDMOWrapperFilter|SupportedOSPlatform(\"windows5.1.2600\")",
                }),
                ("WinProg", "editionupgradehelper.h", new[]
                {
                    "IEditionUpgradeHelper|SupportedOSPlatform(\"windows10.0.10240\")",
                }),
                ("IndexSrv", "filter.h", new[]
                {
                    "IFilter|SupportedOSPlatform(\"windows5.0\")",
                }),
                ("MsCs", "cluadmex.h", new[]
                {
                    "IGetClusterDataInfo", "IGetClusterGroupInfo", "IGetClusterNetInterfaceInfo",
                    "IGetClusterNetworkInfo", "IGetClusterNodeInfo", "IGetClusterObjectInfo",
                    "IGetClusterResourceInfo", "IGetClusterUIInfo", "IWCContextMenuCallback",
                    "IWCWizard97Callback", "IWCWizardCallback", "IWEExtendContextMenu",
                    "IWEExtendWizard", "IWEExtendWizard97", "IWEInvokeCommand",
                }.Select(name => name + "|SupportedOSPlatform(\"windowsserver2003\")").Concat(new[]
                {
                    "IWCPropertySheetCallback", "IWEExtendPropertySheet",
                }.Select(name => name + "|SupportedOSPlatform(\"windowsserver2008\")")).ToArray()),
            };
            foreach (var owner in owners)
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                    foreach (var mode in new[] { ("c", false), ("c++", false), ("c++", true) })
                        foreach (bool enabled in new[] { false, true })
                            yield return new object[]
                            {
                                owner.Item1, owner.Item2, architecture.Item1, architecture.Item2,
                                mode.Item1, mode.Item2, enabled,
                                mode.Item1 == "c++" ? owner.Item3 : Array.Empty<string>(),
                            };
        }

        [HeaderMigrationDataTheory("WINHTTP_PREPARED_HEADERS", "BULK_SYSTEM_IDL_MIGRATION_ROOT")]
        [MemberData(nameof(SystemOriginalIdlNativeSamples))]
        public void SystemOriginalIdlBatchKeepsNativeSurfaceWithExactInterfaceFloors(
            string partition, string header, string architecture, string target, bool enabled, string[] expected) =>
            new WinHttpNativeControlTests(this.output).OriginalIdlBatchPreservesNativeAbiAndSalWithExactMetadata(
                partition, header, architecture, target, "c++", false, enabled, expected);

        public static IEnumerable<object[]> SystemOriginalIdlNativeSamples()
        {
            string root = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_MIGRATION_ROOT");
            if (string.IsNullOrEmpty(root))
            {
                yield return new object[] { "", "", "x64", "x86_64-pc-windows-msvc", true, Array.Empty<string>() };
                yield break;
            }

            string results = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_COMPILE_RESULTS");
            if (string.IsNullOrEmpty(results))
                throw new InvalidOperationException("A real system IDL fixture requires its actual MIDL compile results.");
            using var compiled = JsonDocument.Parse(File.ReadAllText(results));
            var successful = compiled.RootElement.EnumerateArray()
                .Where(result => result.GetProperty("success").GetBoolean())
                .ToDictionary(result => result.GetProperty("original").GetString(),
                    result => result.GetProperty("generatedHeader").GetString(), StringComparer.OrdinalIgnoreCase);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "report.json")));
            foreach (var owner in report.RootElement.GetProperty("owners").EnumerateArray())
            {
                string original = owner.GetProperty("original").GetString();
                if (!successful.TryGetValue(original, out string header))
                    continue;
                string partition = owner.GetProperty("partitionCandidates").EnumerateArray()
                    .Select(value => value.GetString()).First();
                string[] expected = owner.GetProperty("dispositions").EnumerateArray()
                    .Where(row => row.GetProperty("disposition").GetString() == "authored-original-idl")
                    .Select(row => row.GetProperty("fact"))
                    .Select(fact =>
                    {
                        string value = fact.GetProperty("value").GetString();
                        return fact.GetProperty("symbol").GetString() + "|" + value[(value.IndexOf('=') + 1)..];
                    }).ToArray();
                if (expected.Length == 0)
                    throw new InvalidOperationException($"No authored semantic facts for {original}.");
                foreach (var architecture in new[]
                {
                    ("x86", "i686-pc-windows-msvc"),
                    ("x64", "x86_64-pc-windows-msvc"),
                    ("arm64", "aarch64-pc-windows-msvc"),
                })
                {
                    yield return new object[]
                    {
                        partition, Path.GetFileName(header), architecture.Item1, architecture.Item2, true, expected,
                    };
                    if (architecture.Item1 == "x64")
                        yield return new object[]
                        {
                            partition, Path.GetFileName(header), architecture.Item1, architecture.Item2, false, expected,
                        };
                }
            }
        }

        [HeaderMigrationDataTheory("WINHTTP_PREPARED_HEADERS", "BULK_SYSTEM_IDL_BINDINGS")]
        [InlineData("x86")]
        [InlineData("x64")]
        [InlineData("arm64")]
        public void SystemOriginalIdlProjectionContainsExactInterfaceFloors(string architecture)
        {
            string root = Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_MIGRATION_ROOT");
            string generated = Path.Combine(Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_BINDINGS"), architecture);
            using var compiled = JsonDocument.Parse(File.ReadAllText(
                Environment.GetEnvironmentVariable("BULK_SYSTEM_IDL_COMPILE_RESULTS")));
            var successful = compiled.RootElement.EnumerateArray()
                .Where(result => result.GetProperty("success").GetBoolean())
                .Select(result => result.GetProperty("original").GetString()).ToHashSet(StringComparer.OrdinalIgnoreCase);
            using var bindings = JsonDocument.Parse(File.ReadAllText(Path.Combine(generated, "results.json")));
            var outputs = bindings.RootElement.EnumerateArray()
                .ToDictionary(result => result.GetProperty("original").GetString(), StringComparer.OrdinalIgnoreCase);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(root, "report.json")));
            int checkedFacts = 0;
            foreach (var owner in report.RootElement.GetProperty("owners").EnumerateArray())
            {
                string original = owner.GetProperty("original").GetString();
                if (!successful.Contains(original))
                    continue;
                Assert.True(outputs.TryGetValue(original, out var result), $"Missing actual binding output for {original}.");
                Assert.True(result.GetProperty("success").GetBoolean(), $"Binding generation failed for {original}.");
                var declarations = CSharpSyntaxTree.ParseText(File.ReadAllText(result.GetProperty("generatedSource").GetString()))
                    .GetRoot().DescendantNodes().OfType<TypeDeclarationSyntax>()
                    .ToLookup(declaration => declaration.Identifier.ValueText, StringComparer.Ordinal);
                foreach (var row in owner.GetProperty("dispositions").EnumerateArray()
                    .Where(row => row.GetProperty("disposition").GetString() == "authored-original-idl"))
                {
                    var fact = row.GetProperty("fact");
                    string symbol = fact.GetProperty("symbol").GetString();
                    var declaration = Assert.Single(declarations[symbol]);
                    string expected = Regex.Match(fact.GetProperty("value").GetString(),
                        "SupportedOSPlatform\\(\"([^\"]+)\"\\)").Groups[1].Value;
                    string[] actual = declaration.AttributeLists.SelectMany(list => list.Attributes)
                        .Where(attribute => attribute.Name.ToString().Split('.').Last()
                            is "SupportedOSPlatform" or "SupportedOSPlatformAttribute")
                        .Select(attribute => Assert.IsType<LiteralExpressionSyntax>(
                            Assert.Single(attribute.ArgumentList.Arguments).Expression).Token.ValueText).ToArray();
                    Assert.True(actual.SequenceEqual(new[] { expected }),
                        $"{architecture}/{original}/{symbol}: expected '{expected}', actual [{string.Join(", ", actual)}].");
                    checkedFacts++;
                }
            }
            Assert.True(checkedFacts > 0, "The readback requires actual projected original-IDL interface facts.");
            this.output.WriteLine($"{architecture}: {checkedFacts} exact source-authored interface floors in real generated bindings.");
        }

        private static object Floor(string symbol, string version = "windows6.1") =>
            new { category = "supportedOS", symbol, value = symbol + "=SupportedOSPlatform(\"" + version + "\")" };

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterBatchPreservesActualDefaultAndNativeDeclarations(bool enabled)
        {
            (string Interface, string Method, string Parameter, string Attribute, string Prototype)[] parameters =
            {
                ("IAudioClient", "GetService", "ppv", "ComOutPtr",
                    "HRESULT GetService([in, annotation(\"_In_\")] REFIID riid, [out, iid_is(riid), annotation(\"_Out_\")] void **ppv);"),
                ("IMMDevice", "Activate", "ppInterface", "ComOutPtr",
                    "HRESULT Activate([in] REFIID iid, [in] DWORD dwClsCtx, [in, unique] PROPVARIANT *pActivationParams, [out, iid_is(iid), annotation(\"_Out_\")] void **ppInterface);"),
                ("ITfCandidateListUIElement", "GetPageIndex", "pIndex", "Optional",
                    "HRESULT GetPageIndex([out, size_is(uSize), length_is(*puPageCnt)] UINT *pIndex, [in] UINT uSize, [out] UINT *puPageCnt);"),
                ("IClassFactory2", "CreateInstanceLic", "ppvObj", "ComOutPtr",
                    "[local] HRESULT CreateInstanceLic([in, unique] IUnknown *pUnkOuter, [in, unique] IUnknown *pUnkReserved, [in] REFIID riid, [in] BSTR bstrKey, [out, iid_is(riid), annotation(\"__RPC__deref_out_opt\")] PVOID *ppvObj);"),
                ("IWICBitmapDecoderInfo", "CreateInstance", "ppIBitmapDecoder", "ComOutPtr",
                    "HRESULT CreateInstance([out] IWICBitmapDecoder **ppIBitmapDecoder);"),
                ("IWICBitmapEncoderInfo", "CreateInstance", "ppIBitmapEncoder", "ComOutPtr",
                    "HRESULT CreateInstance([out] IWICBitmapEncoder **ppIBitmapEncoder);"),
                ("IWICImagingFactory", "CreateDecoderFromFilename", "pguidVendor", "Optional",
                    "HRESULT CreateDecoderFromFilename([in, string] LPCWSTR wzFilename, [in, unique] const GUID *pguidVendor, [in, annotation(\"_In_\")] DWORD dwDesiredAccess, [in] WICDecodeOptions metadataOptions, [out] IWICBitmapDecoder **ppIDecoder);"),
                ("IWICBitmapSource", "CopyPixels", "prc", "Optional",
                    "HRESULT CopyPixels([in, unique] const WICRect *prc, [in] UINT cbStride, [in] UINT cbBufferSize, [out, size_is(cbBufferSize)] BYTE *pbBuffer);"),
            };
            string declarations = string.Concat(parameters.Select(value =>
                $"interface {value.Interface} : IUnknown {{\n{value.Prototype}\n}}\n"));
            string source = "#if FEATURE\ncpp_quote(\"#if NATIVE_FAMILY\")\n" + declarations +
                "cpp_quote(\"#endif\")\n#endif\n#ifdef SAPI_AUTOMATION\n#include \"sapiaut.idl\"\n#endif\ninterface IAfter : IUnknown {\n};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(parameters.Select(value => ParameterOverride(
                $"{value.Interface}::{value.Method}::{value.Parameter}", value.Attribute))
                .Append(ParameterOverride("ISpeechObjectToken::Object", "ComOutPtr")).ToArray());
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: enabled);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(enabled ? 8 : 0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(enabled ? 1 : 9, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.Equal(enabled ? "complete-top-level-interface" : "unchanged-default",
                report.RootElement.GetProperty("parameterCarrierPolicy").GetString());
            Assert.False(report.RootElement.GetProperty("normalParserActivation").GetProperty("applied").GetBoolean());
            if (enabled)
            {
                string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
                Assert.DoesNotContain("win32metadata_annotations.h", authored);
                foreach (var value in parameters)
                {
                    Assert.Contains(value.Prototype, authored);
                    string carrier = TransportComment("parameter", $"{value.Interface}::{value.Method}::{value.Parameter}",
                        value.Attribute + "(true)");
                    Assert.Contains(carrier, authored);
                    var declaration = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")
                        .EnumerateArray().Single(row => row.GetProperty("fact").GetProperty("symbol").GetString() ==
                            $"{value.Interface}::{value.Method}::{value.Parameter}").GetProperty("declaration");
                    Assert.Equal($"{value.Interface}::{value.Method}::{value.Parameter}",
                        declaration.GetProperty("nativeQualifiedName").GetString());
                }
                Assert.Equal(source, Regex.Replace(WithoutTransportComments(authored),
                    "(?m)^(?:#include <sal\\.h>|cpp_quote\\(\"#include <sal\\.h>\"\\))\\r?\\n", ""));
                var patch = Fixture.Command("git", fixture.RepositoryRoot, "apply", "--unsafe-paths", "-p1",
                    "--directory=" + fixture.Sdk, "--whitespace=error-all", "--check", "--",
                    Path.Combine(result.OutputDirectory, "patches", "um", "sample.idl.patch"));
                Assert.True(patch.ExitCode == 0, patch.Error);
            }
            else
                Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData("unique", 1, null)]
        [InlineData("ambiguous", 0, "requires-one-original-native-parameter-found-2")]
        [InlineData("property", 0, "requires-actual-native-property-method-identity")]
        [InlineData("qualified-property", 0, "requires-actual-native-property-method-identity")]
        [InlineData("missing", 0, "requires-one-original-native-parameter-found-0")]
        public void CompleteInterfaceShortSelectorsRequireActualUniqueNonPropertyIdentity(string form, int authored, string reason)
        {
            const string create = "[id(DISPID_SOTCreateInstance)] HRESULT CreateInstance([in, defaultvalue(NULL)] IUnknown *pUnkOuter, " +
                "[in, defaultvalue(STCAll)] SpeechTokenContext ClsContext, [out, retval] IUnknown **Object);\n";
            const string display = "[id(DISPID_SOTDisplayUI)] HRESULT DisplayUI([in] long hWnd, [in] BSTR Title, [in] const BSTR TypeOfUI, " +
                "[in, defaultvalue(NULL)] const VARIANT *ExtraData, [in, defaultvalue(NULL)] IUnknown *Object);\n";
            string methods = form.Contains("property", StringComparison.Ordinal)
                ? "[propget]\n#if FEATURE\nHRESULT Object([out, retval] IUnknown **Object);\n#endif\n"
                : form == "missing" ? "HRESULT Read([out] IUnknown **Other);\n" : create + (form == "ambiguous" ? display : "");
            string source = "interface ISpeechObjectToken : IDispatch {\n" + methods + "};\ninterface IAfter : IUnknown {\n};\n";
            string symbol = form == "qualified-property" ? "ISpeechObjectToken::Object::Object" : "ISpeechObjectToken::Object";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride(symbol, "ComOutPtr") });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(authored, report.RootElement.GetProperty("authoredFacts").GetInt32());
            var disposition = report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")[0];
            if (reason != null)
            {
                Assert.Equal(reason, disposition.GetProperty("reason").GetString());
                Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            }
            else
            {
                Assert.Equal("ISpeechObjectToken::CreateInstance::Object",
                    disposition.GetProperty("declaration").GetProperty("nativeQualifiedName").GetString());
                Assert.DoesNotContain("get_Object", File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl")));
            }
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData("library Context {\n", "};\n")]
        [InlineData("cpp_quote(\"namespace Context {\")\n", "cpp_quote(\"}\")\n")]
        [InlineData("cpp_quote(\"#if FEATURE\")\n", "")]
        [InlineData("cpp_quote(\"}\")\n", "")]
        public void CompleteInterfaceParameterPolicyRejectsOpenOrMismatchedScopes(string prefix, string suffix)
        {
            string source = prefix + "interface INative : IUnknown {\nHRESULT Read([out] void **value);\n};\n" +
                suffix + "interface IAfter : IUnknown {\n};\n";
            if (prefix.Contains("#if", StringComparison.Ordinal))
                source = source.Replace("HRESULT Read([out] void **value);\n", "HRESULT Read([out] void **value);\ncpp_quote(\"#endif\")\n", StringComparison.Ordinal);
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "ComOutPtr") });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal("requires-complete-interface-parameter-carrier-in-matching-global-conditional-scope",
                report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")[0].GetProperty("reason").GetString());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterPolicyChecksTheParameterConditionalFrame(bool trailingRegion)
        {
            string source = "interface INative : IUnknown {\nHRESULT Read(\n#if FEATURE\n[out] void **value,\n#endif\n[in] long other);\n};\n" +
                (trailingRegion ? "cpp_quote(\"/* existing global region */\")\n" : "");
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "ComOutPtr") });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal("requires-complete-interface-parameter-carrier-in-matching-global-conditional-scope",
                report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")[0].GetProperty("reason").GetString());
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterPolicyUsesAnExistingGlobalRegionAfterAClosedLibrary(bool trailingRegion)
        {
            string source = "library Context {\ninterface INative : IUnknown {\nHRESULT Read([out] void **value);\n};\n};\n" +
                (trailingRegion ? "cpp_quote(\"/* existing global region */\")\n" : "");
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "ComOutPtr") });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(trailingRegion ? 1 : 0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            if (trailingRegion)
                Assert.Contains("};\n};\n" + TransportComment("parameter", "INative::Read::value", "ComOutPtr(true)") + "\ncpp_quote(",
                    File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl")));
        }

        [Theory]
        [InlineData("Optional")]
        [InlineData("ComOutPtr")]
        [InlineData("AnnotateParameter")]
        public void CompleteInterfaceParameterPolicyRequiresTheRealSelectedVocabulary(string missing)
        {
            const string source = "interface INative : IUnknown {\nHRESULT Read([out, annotation(\"_COM_Outptr_\")] void **value);\n};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            string attribute = missing == "ComOutPtr" ? "ComOutPtr" : "Optional";
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", attribute) });
            string header = Path.Combine(fixture.RepositoryRoot, "generation", "WinSDK", "RecompiledIdlHeaders", "shared", "win32metadata_annotations.h");
            File.WriteAllText(fixture.AnnotationHeader, File.ReadAllText(header).Replace("_Win32_" + missing + "_",
                "_Unavailable_" + missing + "_", StringComparison.Ordinal));
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true, annotationHeader: fixture.AnnotationHeader);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(missing == "AnnotateParameter" ? 1 : 0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            if (missing == "AnnotateParameter")
            {
                string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
                Assert.Contains(TransportComment("parameter", "INative::Read::value", "Optional(true)"), authored);
                Assert.DoesNotContain("_Win32_AnnotateParameter_", authored);
            }
            else
            {
                Assert.Equal("parameter-override-not-in-selected-annotation-vocabulary",
                    report.RootElement.GetProperty("owners")[0].GetProperty("dispositions")[0].GetProperty("reason").GetString());
                Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
            }
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterPolicyLeavesFieldsReturnsAndUnknownTargetsResidual(bool trailingRegion)
        {
            string source = "typedef struct RECORD { long value; } RECORD;\ninterface INative : IUnknown {\nHRESULT Read([out] long *value);\n};\n" +
                (trailingRegion ? "cpp_quote(\"/* global region */\")\n" : "");
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            object[] facts =
            {
                ParameterOverride("RECORD::value", "Optional"),
                ParameterOverride("INative::Read::return", "Optional"),
                ParameterOverride("INative::Read::missing", "ComOutPtr"),
                ParameterOverride("INative::Missing::value", "Optional"),
                ParameterOverride("INative::Read::value", "UnknownAttribute"),
            };
            fixture.WriteMap(facts);
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(0, report.RootElement.GetProperty("authoredFacts").GetInt32());
            Assert.Equal(facts.Length, report.RootElement.GetProperty("retainedLegacyFacts").GetInt32());
            Assert.Equal(JsonSerializer.Serialize(facts), JsonSerializer.Serialize(report.RootElement.GetProperty("owners")[0]
                .GetProperty("dispositions").EnumerateArray().Select(row => row.GetProperty("fact")).ToArray()));
            Assert.False(Directory.Exists(Path.Combine(result.OutputDirectory, "patches")));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterPolicyPreservesExistingMethodAndRetvalBehavior(bool enabled)
        {
            const string source = "interface INative : IUnknown {\nHRESULT Read([out] long *value);\n};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[]
            {
                ParameterOverride("INative::Read", "CanReturnMultipleSuccessValues"),
                ParameterOverride("INative::Read::value", "RetVal"),
            });
            var result = fixture.Run(allowCompleteInterfaceParameterCarriers: enabled);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(2, report.RootElement.GetProperty("authoredFacts").GetInt32());
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Contains(TransportComment("method", "INative::Read", "PreserveResult"), authored);
            Assert.Contains(TransportComment("parameter", "INative::Read::value", "RetVal"), authored);
            Assert.Contains("[out] long *value", authored);
            Assert.DoesNotContain("[annotation(", authored);
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Fact]
        public void CompleteInterfaceParameterPolicyPreservesPositiveAndNegativeQuotedNativeOverrides()
        {
            const string source = "cpp_quote(\"STDAPI Native(_In_opt_ unsigned options, _Outptr_ void** output, _COM_Outptr_ void** nativeCom);\")\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[]
            {
                ParameterOverride("Native::options", "-Optional"),
                ParameterOverride("Native::output", "ComOutPtr"),
                ParameterOverride("Native::nativeCom", "-ComOutPtr"),
            });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(3, report.RootElement.GetProperty("authoredFacts").GetInt32());
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Contains(TransportComment("parameter", "Native::options", "Optional(false)"), authored);
            Assert.Contains(TransportComment("parameter", "Native::output", "ComOutPtr(true)"), authored);
            Assert.Contains(TransportComment("parameter", "Native::nativeCom", "ComOutPtr(false)"), authored);
            Assert.Contains(source, authored);
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceParameterPolicyPreservesCumulativeIncludesAndCarriers(bool sharedSal)
        {
            const string source = "#include <sal.h>\n#include <win32metadata_annotations.h>\n" +
                "cpp_quote(\"#include <sal.h>\")\ninterface INative : IUnknown {\nHRESULT Read([in] long value);\n};\n" +
                "cpp_quote(\"/* Win32Metadata: method ::INative::Read => PreserveResult */\")\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "Optional") });
            var result = fixture.Run(sharedSalBootstrap: sharedSal, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            using var report = JsonDocument.Parse(File.ReadAllText(Path.Combine(result.OutputDirectory, "report.json")));
            Assert.Equal(1, report.RootElement.GetProperty("authoredFacts").GetInt32());
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Equal(source, authored.Replace(TransportComment("parameter", "INative::Read::value", "Optional(true)") + "\n",
                "", StringComparison.Ordinal));
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompleteInterfaceSharedBootstrapReusesCumulativeSalAfterEarlierTokens(bool sharedSal)
        {
            const string source = "import \"unknwn.idl\";\n#include <sal.h>\ncpp_quote(\"#include \\\"sal.h\\\"\")\n" +
                "interface INative : IUnknown {\nHRESULT Read([in] long value);\n};\n";
            using var fixture = new Fixture(Encoding.ASCII.GetBytes(source));
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "Optional") });
            var result = fixture.Run(sharedSalBootstrap: sharedSal, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = File.ReadAllText(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl"));
            Assert.Equal(sharedSal ? 1 : 2, Regex.Matches(authored, "(?m)^#include <sal\\.h>$").Count);
            Assert.Single(Regex.Matches(authored, "(?m)^cpp_quote\\(\"#include"));
            Assert.Contains(source[..source.IndexOf("interface", StringComparison.Ordinal)], authored);
            Assert.Equal(source, File.ReadAllText(fixture.Source));
        }

        [Theory]
        [InlineData("\n", false)]
        [InlineData("\r\n", false)]
        [InlineData("\n", true)]
        [InlineData("\r\n", true)]
        public void CompleteInterfaceParameterPolicyPreservesEofEncodingAndOriginalBytes(string newline, bool bom)
        {
            string source = ("// Copyright sample " + (char)0xA9 + "\ninterface INative : IUnknown {\nHRESULT Read([out] void **value);\n}")
                .Replace("\n", newline, StringComparison.Ordinal);
            byte[] bytes = Encoding.Latin1.GetBytes(source);
            if (bom)
                bytes = new byte[] { 239, 187, 191 }.Concat(bytes).ToArray();
            using var fixture = new Fixture(bytes);
            fixture.WriteMap(new[] { ParameterOverride("INative::Read::value", "ComOutPtr") });
            var result = fixture.Run(sharedSalBootstrap: true, allowCompleteInterfaceParameterCarriers: true);
            Assert.True(result.ExitCode == 0, result.Error);
            string authored = Encoding.Latin1.GetString(File.ReadAllBytes(Path.Combine(result.OutputDirectory, "source", "um", "sample.idl")));
            string recovered = authored.Replace("#include <sal.h>" + newline, "", StringComparison.Ordinal)
                .Replace("cpp_quote(\"#include <sal.h>\")" + newline, "", StringComparison.Ordinal)
                .Replace(newline + TransportComment("parameter", "INative::Read::value", "ComOutPtr(true)") + newline, "", StringComparison.Ordinal);
            Assert.Equal(bytes, Encoding.Latin1.GetBytes(recovered));
            Assert.Equal(bytes, File.ReadAllBytes(fixture.Source));
        }

        [Fact]
        public void CompleteInterfaceParameterOptionsFollowEveryExistingPositionalParameter()
        {
            string script = Path.Combine(WinHttpMigrationTests.RepositoryRoot, "scripts", "Convert-SdkIdlAnnotations.ps1").Replace("'", "''", StringComparison.Ordinal);
            var result = Fixture.Command("pwsh", WinHttpMigrationTests.RepositoryRoot, "-NoProfile", "-NonInteractive", "-Command",
                "$tokens=$null; $errors=$null; $ast=[Management.Automation.Language.Parser]::ParseFile('" + script +
                "',[ref]$tokens,[ref]$errors); if($errors.Count){throw ($errors.Message -join '; ')}; " +
                "ConvertTo-Json -Compress -InputObject @($ast.ParamBlock.Parameters | ForEach-Object {$_.Name.VariablePath.UserPath})");
            Assert.True(result.ExitCode == 0, result.Error);
            Assert.Equal(new[]
            {
                "InputMap", "SdkIncludeRoot", "OutputDirectory", "Original", "SdkProjectRoot", "Apply", "AnnotationHeader",
                "SharedSalBootstrap", "AllowCompleteInterfaceParameterCarriers",
                "PatchedIdl", "PristineIdl", "TransportOutput",
            }, JsonSerializer.Deserialize<string[]>(result.Error));
        }

        private static object ParameterOverride(string symbol, string attribute) =>
            new { category = "declaration-attribute-override", symbol, value = symbol + "=[" + attribute + "]" };

        private sealed class Fixture : IDisposable
        {
            private readonly string directory = Path.Combine(Path.GetTempPath(), "Win32MetadataIdl-" + Guid.NewGuid().ToString("N"));
            private int runs;

            public Fixture(byte[] source)
            {
                this.Sdk = Path.Combine(this.directory, "SDK with spaces");
                Directory.CreateDirectory(Path.Combine(this.Sdk, "um"));
                this.Source = Path.Combine(this.Sdk, "um", "sample.idl");
                File.WriteAllBytes(this.Source, source);
                this.Project = Path.Combine(this.directory, "Project");
                Directory.CreateDirectory(Path.Combine(this.Project, "Partitions", "Sample"));
                Directory.CreateDirectory(Path.Combine(this.Project, "patches"));
                File.WriteAllText(Path.Combine(this.Project, "Partitions", "Sample", "main.cpp"), "#include <sample.h>\n");
                File.WriteAllText(Path.Combine(this.Project, "Partitions", "Sample", "settings.rsp"),
                    "--namespace\nTest\n--traverse\n<IncludeRoot>/um/sample.h\n");
                File.WriteAllText(Path.Combine(this.Project, "patches", "SdkHeaders.json"), JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    partitions = new[] { "Sample" },
                    midl = new { outputs = new[] { new { source = @"um\sample.idl", path = @"um\sample.h" } } },
                }));
            }

            public string RepositoryRoot => WinHttpMigrationTests.RepositoryRoot;
            public string Sdk { get; }
            public string Source { get; }
            public string Project { get; }
            public string AnnotationHeader => Path.Combine(this.directory, "annotation-input.h");

            public (int ExitCode, string Error, string Output) ConvertTransport(string patched, string extension = ".idl")
            {
                string input = Path.Combine(this.directory, "patched" + extension);
                string output = Path.Combine(this.directory, "transport-" + this.runs++ + ".idl");
                File.WriteAllBytes(input, Encoding.Latin1.GetBytes(patched));
                var result = Command("pwsh", this.RepositoryRoot, "-NoProfile", "-File",
                    Path.Combine(this.RepositoryRoot, "scripts", "Convert-SdkIdlAnnotations.ps1"),
                    "-PatchedIdl", input, "-PristineIdl", this.Source, "-TransportOutput", output);
                Assert.Equal(patched, Encoding.Latin1.GetString(File.ReadAllBytes(input)));
                return (result.ExitCode, result.Error, output);
            }

            public void WriteMap(object[] facts, string original = @"um\sample.idl", bool stale = false)
            {
                string hash = Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(this.Source)));
                File.WriteAllText(Path.Combine(this.directory, "owners.json"), JsonSerializer.Serialize(new
                {
                    schemaVersion = 1,
                    owners = new[] { new { original, sourceSha256 = stale ? new string('0', 64) : hash,
                        generatedHeaders = new[] { @"um\sample.h" }, partitionCandidates = new[] { "Sample" }, facts } },
                }));
            }

            public (int ExitCode, string Error, string OutputDirectory) Run(string output = null, bool apply = false,
                bool sharedSalBootstrap = false, bool allowCompleteInterfaceParameterCarriers = false, string annotationHeader = null)
            {
                output ??= Path.Combine(this.directory, "result-" + this.runs++);
                var arguments = new List<string> { "-NoProfile", "-File",
                    Path.Combine(this.RepositoryRoot, "scripts", "Convert-SdkIdlAnnotations.ps1"),
                    "-InputMap", Path.Combine(this.directory, "owners.json"), "-SdkIncludeRoot", this.Sdk,
                    "-OutputDirectory", output, "-SdkProjectRoot", this.Project };
                if (apply)
                    arguments.Add("-Apply");
                if (sharedSalBootstrap)
                    arguments.Add("-SharedSalBootstrap");
                if (allowCompleteInterfaceParameterCarriers)
                    arguments.Add("-AllowCompleteInterfaceParameterCarriers");
                if (annotationHeader != null)
                {
                    arguments.Add("-AnnotationHeader");
                    arguments.Add(annotationHeader);
                }
                var result = Command("pwsh", this.RepositoryRoot, arguments.ToArray());
                return (result.ExitCode, result.Error, output);
            }

            public static (int ExitCode, string Error) Command(string executable, string workingDirectory, params string[] arguments)
            {
                using var process = new Process { StartInfo = new ProcessStartInfo(executable)
                {
                    WorkingDirectory = workingDirectory, UseShellExecute = false, RedirectStandardOutput = true, RedirectStandardError = true,
                } };
                foreach (string argument in arguments)
                    process.StartInfo.ArgumentList.Add(argument);
                process.Start();
                var output = process.StandardOutput.ReadToEndAsync();
                var error = process.StandardError.ReadToEndAsync();
                process.WaitForExit();
                return (process.ExitCode, error.GetAwaiter().GetResult() + output.GetAwaiter().GetResult());
            }

            public void Dispose() => Directory.Delete(this.directory, recursive: true);
        }
    }
}
