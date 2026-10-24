using System;
using System.IO;
using System.Linq;
using System.Reflection.Metadata;
using System.Text.Json;
using Xunit;

namespace Win32MetadataScraperTests
{
    public partial class HeaderAnnotationWinmdTests
    {
        private const string ConditionalNativeExports = @"
extern ""C"" {
typedef unsigned short WCHAR;
struct Payload { const char* text; unsigned flags; };
int __stdcall NativeOpenA(const char* name, Payload* value);
int __stdcall NativeOpenW(const WCHAR* name, Payload* value);
#ifdef UNICODE
enum Selection { PrimarySelection = 5 };
#define NativeOpen NativeOpenW
#else
enum Selection { PrimarySelection = 1 };
struct AnsiOnlyRecord { unsigned flags; };
_Win32_SupportedOS_Windows7_ int __stdcall NativeOpen(const char* name, Payload* value);
int __stdcall ExcludedExport(AnsiOnlyRecord* value);
int __stdcall UnmappedExport(AnsiOnlyRecord* value);
#endif
}
";

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, false)]
        [InlineData("x86", "i686-pc-windows-msvc", false, false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false, false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false, false)]
        [InlineData("x86", "i686-pc-windows-msvc", true, true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true, true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true, true)]
        public void ConditionalCompanionRecoversOnlyMappedImportsAndKeepsUnicodeProviders(
            string architecture, string target, bool annotations, bool multipleFiles)
        {
            string defines = multipleFiles ? "-D\nUNICODE=1\n" : "-DUNICODE\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, ConditionalNativeExports,
                annotationsEnabled: annotations, multipleFiles: multipleFiles, extraSettings: "--additional\n" + defines + @"
--with-librarypath
NativeOpen=companion.dll
NativeOpenA=companion.dll
NativeOpenW=companion.dll
ExcludedExport=companion.dll
AbsentSdkExport=companion.dll
--exclude
ExcludedExport
");
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var methods = FindType(reader, "Apis").GetMethods().Select(reader.GetMethodDefinition)
                .ToDictionary(method => reader.GetString(method.Name));
            Assert.Equal(new[] { "NativeOpen", "NativeOpenA", "NativeOpenW" }, methods.Keys.OrderBy(name => name));
            foreach (var variant in new[]
            {
                (Name: "NativeOpen", Text: "SByte*"),
                (Name: "NativeOpenA", Text: "SByte*"),
                (Name: "NativeOpenW", Text: "UInt16*"),
            })
            {
                var method = methods[variant.Name];
                Assert.Equal(new[] { variant.Text, "Payload*" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
                var import = method.GetImport();
                Assert.Equal(variant.Name, reader.GetString(import.Name));
                Assert.Equal("companion.dll", reader.GetString(reader.GetModuleReference(import.Module).Name));
            }
            if (annotations)
                AssertStringAttribute(reader, methods["NativeOpen"].GetCustomAttributes(),
                    "SupportedOSPlatformAttribute", "windows6.1");
            var value = FindType(reader, "Selection").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "PrimarySelection");
            Assert.Equal(5, reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value).ReadInt32());
            Assert.DoesNotContain(reader.TypeDefinitions,
                handle => reader.GetString(reader.GetTypeDefinition(handle).Name) == "AnsiOnlyRecord");
            Assert.Equal("SByte*", reader.GetFieldDefinition(FindType(reader, "Payload").GetFields().First())
                .DecodeSignature(new SignatureNames(), null));
            AssertMetadataClosure(reader);
            string evidencePath = multipleFiles ? Path.Combine(fixture.Output, "Bindings.native-declarations.json")
                : Path.ChangeExtension(fixture.Output, ".native-declarations.json");
            using var evidence = JsonDocument.Parse(File.ReadAllText(evidencePath));
            Assert.Contains(multipleFiles ? "UNICODE=1" : "-DUNICODE", evidence.RootElement.GetProperty("primaryArguments").EnumerateArray()
                .Select(value => value.GetString()));
            string[] alternate = evidence.RootElement.GetProperty("companionArguments").EnumerateArray()
                .Select(value => value.GetString()).ToArray();
            Assert.Equal("-UUNICODE", alternate.Last());
            Assert.Equal(2, evidence.RootElement.GetProperty("supplementalParses").GetInt32());
            Assert.True(evidence.RootElement.GetProperty("projectionCompleted").GetBoolean());
            Assert.Single(evidence.RootElement.GetProperty("evidence").EnumerateArray()
                .Where(value => value.GetProperty("kind").GetString() == "recovered-export"));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", "-DUNICODE\n-UUNICODE\n")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "-DUNICODE\n-UUNICODE\n")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "-DUNICODE\n-UUNICODE\n")]
        [InlineData("x86", "i686-pc-windows-msvc", "-D\nUNICODE=1\n-U\nUNICODE\n")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "-D\nUNICODE=1\n-U\nUNICODE\n")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "-D\nUNICODE=1\n-U\nUNICODE\n")]
        [InlineData("x86", "i686-pc-windows-msvc", "")]
        [InlineData("x64", "x86_64-pc-windows-msvc", "")]
        [InlineData("arm64", "aarch64-pc-windows-msvc", "")]
        public void ConditionalCompanionHonorsDeliberateAnsiWithoutSupplementalParsing(
            string architecture, string target, string arguments)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, ConditionalNativeExports,
                extraSettings: arguments.Length == 0 ? null : "--additional\n" + arguments);
            fixture.AssertSuccess();
            Assert.False(File.Exists(Path.ChangeExtension(fixture.Output, ".native-declarations.json")));
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var value = FindType(reader, "Selection").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "PrimarySelection");
            Assert.Equal(1, reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value).ReadInt32());
            Assert.Equal(new[] { "SByte*", "Payload*" }, FindMethod(reader, "Apis", "NativeOpen")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void AuthoredMacroRemapsRemainScopedAndDoNotRenameOtherExpandedMembers(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#ifdef UNICODE
#define GetObject GetObjectW
#define GetClassName GetClassNameW
#else
#define GetObject GetObjectA
#define GetClassName GetClassNameA
#endif
#define STDMETHOD(name) virtual int __stdcall name
struct ConfiguredOwner { virtual int GetObject(char* text) = 0; };
struct MacroOwner { STDMETHOD(GetObject)(char* text) = 0; };
struct FieldOwner { int GetObject; };
struct UnconfiguredOwner { virtual int GetClassName(char* text) = 0; };
extern ""C"" int GetObjectA(const char* text);
extern ""C"" int GetObjectW(const unsigned short* text);
extern ""C"" int GetClassNameA(char* text, unsigned count);
extern ""C"" int GetClassNameW(unsigned short* text, unsigned count);
", extraSettings: "--additional\n-DUNICODE\n--remap\nGetObjectA=GetObject\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture.DirectoryPath, architecture, apiNamesToNamespaces:
                new System.Collections.Generic.Dictionary<string, string>
                {
                    ["GetClassNameA"] = "Test", ["GetClassNameW"] = "Test",
                    ["GetObjectA"] = "Test", ["GetObjectW"] = "Test",
                });
            var reader = image.Reader;
            Assert.Equal(new[] { "SByte*" }, FindMethod(reader, "ConfiguredOwner", "GetObject")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal(new[] { "SByte*" }, FindMethod(reader, "MacroOwner", "GetObject")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal("GetObject", reader.GetString(reader.GetFieldDefinition(
                Assert.Single(FindType(reader, "FieldOwner").GetFields())).Name));
            var unconfigured = FindMethod(reader, "UnconfiguredOwner", "GetClassNameW");
            Assert.Equal(new[] { "SByte*" }, unconfigured.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            AssertHasAttribute(reader, unconfigured.GetCustomAttributes(), "UnicodeAttribute");
            Assert.Equal("GetObjectA", reader.GetString(FindMethod(reader, "Apis", "GetObject").GetImport().Name));
            Assert.Equal("GetObjectW", reader.GetString(FindMethod(reader, "Apis", "GetObjectW").GetImport().Name));
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData("struct Owner { virtual int GetObject(char* text) = 0; virtual int GetObjectW(unsigned value) = 0; };",
            "cannot rename unproven native overloads")]
        [InlineData("int GetObject(char* text);", "requires a declaration-scoped native owner")]
        public void AuthoredMacroRemapsRejectUnprovenBindingScope(string declaration, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#ifdef UNICODE
#define GetObject GetObjectW
#else
#define GetObject GetObjectA
#endif
" + declaration, extraSettings: "--additional\n-DUNICODE\n--remap\nGetObjectA=GetObject\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void CompanionCannotInventAMappedUnmangledExportForACppFunction()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#ifndef UNICODE
int Recovered(unsigned value);
#endif
", extraSettings: "--additional\n-DUNICODE\n--with-librarypath\nRecovered=companion.dll\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("conflicting export identity", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void CompanionProviderFailureRetainsItsNativeContextAndSemanticEvidence()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#ifdef UNICODE
#define CHARACTER_TYPE unsigned short
#else
#define CHARACTER_TYPE char
#endif
typedef CHARACTER_TYPE CHARACTER;
struct Payload { CHARACTER* text; };
static_assert(sizeof(Payload) == sizeof(void*));
#ifndef UNICODE
extern ""C"" int Recovered(Payload* value);
#endif
", extraSettings: "--additional\n-DUNICODE\n--with-librarypath\nRecovered=companion.dll\n");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("Primary Unicode declarations remain authoritative", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
            using var evidence = JsonDocument.Parse(File.ReadAllText(Path.ChangeExtension(fixture.Output, ".native-declarations.json")));
            var failure = Assert.Single(evidence.RootElement.GetProperty("evidence").EnumerateArray()
                .Where(value => value.GetProperty("kind").GetString() == "incompatible-export"));
            Assert.Contains("typedef(CHARACTER)", failure.GetProperty("error").GetString());
            Assert.Equal("Recovered", failure.GetProperty("Name").GetString());
            Assert.NotEmpty(failure.GetProperty("dependencies").EnumerateArray());
            Assert.NotEmpty(evidence.RootElement.GetProperty("files").EnumerateObject());
        }

        [Fact]
        public void ConditionalCompanionCannotOverwriteAnExistingManagedImport()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", ConditionalNativeExports,
                extraSettings: @"
--additional
-DUNICODE
--with-librarypath
NativeOpen=companion.dll
--remap
NativeOpenA=NativeOpen
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("collides with another projected member", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ConditionalCompanionDoesNotReparseUnrelatedSkippedSdkDeclarations(bool annotations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
// UNICODE in a comment is not a mode dependency.
#if defined(FUTURE_VERSION) /* UNICODE */
extern ""C"" int FutureExport(unsigned value);
#endif
extern ""C"" int Existing(unsigned value);
", annotationsEnabled: annotations,
                extraSettings: "--additional\n-DUNICODE\n--with-librarypath\nFutureExport=future.dll\n");
            fixture.AssertSuccess();
            using var evidence = JsonDocument.Parse(File.ReadAllText(Path.ChangeExtension(fixture.Output, ".native-declarations.json")));
            Assert.Equal(0, evidence.RootElement.GetProperty("supplementalParses").GetInt32());
            Assert.Empty(evidence.RootElement.GetProperty("companionArguments").EnumerateArray());
            Assert.DoesNotContain(evidence.RootElement.GetProperty("evidence").EnumerateArray(),
                value => value.GetProperty("kind").GetString() == "recovered-export");
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void ConditionalCompanionFollowsSourceProvenUnicodeSelectorDependencies(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, @"
#include ""selector.h""
#if SELECTED_TEXT_MODE
enum Selection { PrimarySelection = 5 };
#else
enum Selection { PrimarySelection = 1 };
extern ""C"" int Recovered(unsigned value);
#endif
", extraSettings: "--additional\n-DUNICODE\n--with-librarypath\nRecovered=companion.dll\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "selector.h"), @"
#ifndef SELECTOR_HEADER
#define SELECTOR_HEADER
#ifdef UNICODE
#define COMPILED_TEXT_MODE 1
#else
#define COMPILED_TEXT_MODE 0
#endif
#define SELECTED_TEXT_MODE COMPILED_TEXT_MODE
#endif
");
            fixture.AssertSuccess();
            using var image = Emit(fixture, architecture);
            var reader = image.Reader;
            var method = FindMethod(reader, "Apis", "Recovered");
            Assert.Equal(new[] { "UInt32" }, method.DecodeSignature(new SignatureNames(), null).ParameterTypes);
            Assert.Equal("Recovered", reader.GetString(method.GetImport().Name));
            var value = FindType(reader, "Selection").GetFields().Select(reader.GetFieldDefinition)
                .Single(field => reader.GetString(field.Name) == "PrimarySelection");
            Assert.Equal(5, reader.GetBlobReader(reader.GetConstant(value.GetDefaultValue()).Value).ReadInt32());
            using var evidence = JsonDocument.Parse(File.ReadAllText(Path.ChangeExtension(fixture.Output, ".native-declarations.json")));
            Assert.Contains(evidence.RootElement.GetProperty("files").EnumerateObject(),
                file => Path.GetFileName(file.Name) == "selector.h" && file.Value.GetString().Length == 64);
            AssertMetadataClosure(reader);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AuthoredMacroRemapsPreserveMethodsInheritedFromUntraversedNativeProviders(bool annotations)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#include ""base.h""
struct Owned : Parent {};
", annotationsEnabled: annotations, extraSettings: "--additional\n-DUNICODE\n--remap\nGetObjectA=GetObject\n");
            File.WriteAllText(Path.Combine(fixture.DirectoryPath, "base.h"), @"
#ifdef UNICODE
#define GetObject GetObjectW
#else
#define GetObject GetObjectA
#endif
struct Parent { virtual int GetObject(char* text) = 0; };
");
            fixture.AssertSuccess();
            Assert.Contains("public int GetObject(", fixture.ReadSource());
            Assert.DoesNotContain("GetObjectW", fixture.ReadSource());
        }

        [Theory]
        [InlineData(false, false)]
        [InlineData(false, true)]
        [InlineData(true, false)]
        [InlineData(true, true)]
        public void AuthoredMacroRemapCandidatesRequireAnApplicableCompilerAlternative(bool annotations, bool unicodeOnly)
        {
            string declaration = "struct Owner { virtual int GetObject(char* text) = 0; };";
            if (unicodeOnly)
                declaration = "#ifdef UNICODE\n" + declaration + "\n#endif\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
#if 1
#define GetObject GetObjectW
#else
#define GetObject GetObjectA
#endif
" + declaration, annotationsEnabled: annotations,
                extraSettings: "--additional\n-DUNICODE\n--remap\nGetObjectA=GetObject\n");
            fixture.AssertSuccess();
            using var image = Emit(fixture, "x64");
            Assert.Equal(new[] { "SByte*" }, FindMethod(image.Reader, "Owner", "GetObjectW")
                .DecodeSignature(new SignatureNames(), null).ParameterTypes);
            using var evidence = JsonDocument.Parse(File.ReadAllText(Path.ChangeExtension(fixture.Output, ".native-declarations.json")));
            Assert.DoesNotContain(evidence.RootElement.GetProperty("evidence").EnumerateArray(),
                value => value.GetProperty("kind").GetString() == "authored-remap");
        }
    }
}
