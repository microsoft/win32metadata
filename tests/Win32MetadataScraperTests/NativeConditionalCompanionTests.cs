using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class NativeConditionalCompanionTests
    {
        [Theory]
        [InlineData("struct Payload { const char* text; };", true)]
        [InlineData("struct Payload {};", true)]
        [InlineData("struct Payload { CHARACTER* text; };", false)]
        [InlineData("typedef CHARACTER TEXT; struct Payload { TEXT* text; };", false)]
        [InlineData("typedef CHARACTER (*CALLBACK)(int); struct Payload { CALLBACK call; };", false)]
        [InlineData("struct Payload;", true)]
        [InlineData("enum Kind { Selection = sizeof(CHARACTER) }; struct Payload { Kind kind; };", false)]
        [InlineData("struct Payload { const char* text __attribute__((annotate(\"capacity\", sizeof(CHARACTER)))); };", false)]
        [InlineData("#ifdef UNICODE\n#define CONTRACT _Nonnull\n#else\n#define CONTRACT _Nullable\n#endif\nstruct Payload { char* CONTRACT text; };", false)]
        [InlineData("using Text = char* [[clang::annotate_type(\"capacity\", sizeof(CHARACTER))]]; struct Payload { Text text; };", false)]
        [InlineData("struct Payload { int value; void Method(); };", false)]
        [InlineData("struct Payload {\n#ifndef UNICODE\nint value;\n#endif\n};", false)]
        public void CompanionDependenciesCompareResolvedContractsNotJustStorage(string declaration, bool compatible)
        {
            using var fixture = new NativeFixture(@"
#ifdef UNICODE
#define CHARACTER unsigned short
#else
#define CHARACTER char
#endif
" + declaration + @"
#ifndef UNICODE
int Recovered(Payload* value);
#endif
", detailed: false);
            using var companion = fixture.Parse(false, "-UUNICODE");
            var function = Declarations(companion.TranslationUnitDecl).OfType<FunctionDecl>()
                .Single(function => function.Name == "Recovered");
            var validator = new NativeTypeCompatibility(Declarations(fixture.Unit.TranslationUnitDecl));
            if (compatible)
                validator.Validate(function);
            else
                Assert.Contains("Primary Unicode declarations remain authoritative",
                    Assert.Throws<InvalidOperationException>(() => validator.Validate(function)).Message);
        }

        [Fact]
        public void CompanionRejectsSameStorageWithDifferentPointeeSemantics()
        {
            using var fixture = new NativeFixture(@"
#ifdef UNICODE
#define CHARACTER_TYPE unsigned short
#else
#define CHARACTER_TYPE char
#endif
typedef CHARACTER_TYPE CHARACTER;
struct Payload { CHARACTER* text; };
#ifndef UNICODE
int Recovered(Payload* value);
#endif
", detailed: false);
            using var companion = fixture.Parse(false, "-UUNICODE");
            var before = Declarations(fixture.Unit.TranslationUnitDecl).OfType<RecordDecl>()
                .Single(record => record.Name == "Payload");
            var after = Declarations(companion.TranslationUnitDecl).OfType<RecordDecl>()
                .Single(record => record.Name == "Payload");
            Assert.Equal(before.TypeForDecl.Handle.SizeOf, after.TypeForDecl.Handle.SizeOf);
            Assert.Equal(before.TypeForDecl.Handle.AlignOf, after.TypeForDecl.Handle.AlignOf);
            Assert.Equal(before.CursorChildren.OfType<FieldDecl>().Single().Handle.OffsetOfField,
                after.CursorChildren.OfType<FieldDecl>().Single().Handle.OffsetOfField);
            var function = Declarations(companion.TranslationUnitDecl).OfType<FunctionDecl>().Single();
            var validator = new NativeTypeCompatibility(Declarations(fixture.Unit.TranslationUnitDecl));
            Assert.Contains("typedef(CHARACTER)", Assert.Throws<InvalidOperationException>(() => validator.Validate(function)).Message);
        }

        [Fact]
        public void CompanionRejectsIncompleteByValueDependencies()
        {
            using var fixture = new NativeFixture(@"
struct Payload;
#ifndef UNICODE
int Recovered(Payload value);
#endif
", detailed: false);
            using var companion = fixture.Parse(false, "-UUNICODE");
            var function = Declarations(companion.TranslationUnitDecl).OfType<FunctionDecl>().Single();
            var validator = new NativeTypeCompatibility(Declarations(fixture.Unit.TranslationUnitDecl));
            Assert.Contains("incomplete by-value", Assert.Throws<InvalidOperationException>(() => validator.Validate(function)).Message);
        }

        [Fact]
        public void CompanionRejectsSameStorageWithDifferentCallbackCallingConventions()
        {
            using var fixture = new NativeFixture(@"
#ifdef UNICODE
#define NATIVE_CALL __stdcall
#else
#define NATIVE_CALL __cdecl
#endif
typedef int (NATIVE_CALL *CALLBACK)(unsigned value);
struct Payload { CALLBACK call; };
#ifndef UNICODE
int Recovered(Payload* value);
#endif
", detailed: false, target: "i686-pc-windows-msvc");
            using var companion = fixture.Parse(false, "-UUNICODE");
            var before = Declarations(fixture.Unit.TranslationUnitDecl).OfType<RecordDecl>()
                .Single(record => record.Name == "Payload");
            var after = Declarations(companion.TranslationUnitDecl).OfType<RecordDecl>()
                .Single(record => record.Name == "Payload");
            Assert.Equal(before.TypeForDecl.Handle.SizeOf, after.TypeForDecl.Handle.SizeOf);
            Assert.Equal(before.TypeForDecl.Handle.AlignOf, after.TypeForDecl.Handle.AlignOf);
            var validator = new NativeTypeCompatibility(Declarations(fixture.Unit.TranslationUnitDecl));
            var function = Declarations(companion.TranslationUnitDecl).OfType<FunctionDecl>()
                .Single(function => function.Name == "Recovered");
            Assert.Contains("typedef(CALLBACK)", Assert.Throws<InvalidOperationException>(() => validator.Validate(function)).Message);
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void DirectMacroNamesHaveExactCompilerSourceProofWithoutRequiringARecord(bool detailed)
        {
            using var fixture = new NativeFixture(@"
#define Selected SelectedW
struct Owner { int Selected(char* text); int (*SelectedField)(char* text); };
int Selected(char* text);
int SelectedW(unsigned count);
#define SelectedField SelectedFieldW
struct FieldOwner { int (*SelectedField)(char* text); };
#define Nested Selected
int Nested(char* text, unsigned count);
#define Factory(name) int name(char* text, unsigned count, unsigned other)
Factory(Selected);
", detailed);
            var declarations = Declarations(fixture.Unit.TranslationUnitDecl).OfType<NamedDecl>().ToArray();
            var method = declarations.OfType<CXXMethodDecl>().Single();
            Assert.Equal("Selected", NativeMacroNames.GetWrittenName(method));
            Assert.Equal(detailed ? "Selected" : null,
                NativeMacroNames.GetWrittenName(method, requireRecordedExpansion: true));
            var field = declarations.OfType<FieldDecl>().Single(value => value.Name == "SelectedFieldW");
            Assert.Equal("SelectedField", NativeMacroNames.GetWrittenName(field));
            var functions = declarations.OfType<FunctionDecl>().Where(value => value is not CXXMethodDecl)
                .OrderBy(value => value.Parameters.Count).ToArray();
            Assert.Equal(4, functions.Length);
            Assert.Equal("Selected", NativeMacroNames.GetWrittenName(functions[0]));
            Assert.All(functions.Skip(1), value => Assert.Null(NativeMacroNames.GetWrittenName(value)));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void AuthoredMemberMacroProofRetainsTheCompilerArgumentOrigin(bool detailed)
        {
            using var fixture = new NativeFixture(@"
#define Selected SelectedW
#define STDMETHOD(name) virtual int __stdcall name
struct Owner { STDMETHOD(Selected)(char* text) = 0; };
", detailed);
            var method = Declarations(fixture.Unit.TranslationUnitDecl).OfType<CXXMethodDecl>().Single();
            Assert.Null(NativeMacroNames.GetWrittenName(method, requireRecordedExpansion: true));
            Assert.Equal("Selected", NativeMacroNames.GetWrittenMemberName(method));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public unsafe void CompilerSkippedRangesRequireAPreprocessingRecord(bool detailed)
        {
            using var fixture = new NativeFixture(@"
#ifdef UNICODE
int OnlyWide();
#else
int OnlyAnsi();
#endif
", detailed);
            var ranges = fixture.Unit.Handle.GetSkippedRanges(fixture.Unit.Handle.GetFile(fixture.Source));
            try
            {
                Assert.Equal(detailed, ranges != null && ranges->count > 0);
            }
            finally
            {
                if (ranges != null)
                    ranges->Dispose();
            }
        }

        private static IEnumerable<Decl> Declarations(Decl root)
        {
            yield return root;
            foreach (var child in root.CursorChildren.OfType<Decl>())
                foreach (var declaration in Declarations(child))
                    yield return declaration;
        }

        private sealed class NativeFixture : IDisposable
        {
            private readonly CXIndex index;
            private readonly string directory;
            private readonly string target;

            internal NativeFixture(string source, bool detailed, string target = "x86_64-pc-windows-msvc")
            {
                this.target = target;
                this.directory = Path.Combine(Path.GetTempPath(), "native-companion-" + Guid.NewGuid().ToString("N"));
                Directory.CreateDirectory(this.directory);
                Source = Path.Combine(this.directory, "test.cpp");
                File.WriteAllText(Source, source);
                this.index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
                Unit = Parse(detailed);
            }

            internal TranslationUnit Parse(bool detailed, params string[] additional)
            {
                var flags = CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes |
                    CXTranslationUnit_Flags.CXTranslationUnit_VisitImplicitAttributes;
                if (detailed)
                    flags |= CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord;
                var error = CXTranslationUnit.TryParse(this.index, Source,
                    new[] { "--language=c++", "--std=c++17", "--target=" + this.target, "-DUNICODE" }.Concat(additional).ToArray(),
                    ReadOnlySpan<CXUnsavedFile>.Empty, flags, out var handle);
                Assert.Equal(CXErrorCode.CXError_Success, error);
                for (uint diagnosticIndex = 0; diagnosticIndex < handle.NumDiagnostics; diagnosticIndex++)
                {
                    using var diagnostic = handle.GetDiagnostic(diagnosticIndex);
                    using var message = diagnostic.Spelling;
                    Assert.True(diagnostic.Severity < CXDiagnosticSeverity.CXDiagnostic_Warning, message.ToString());
                }
                return TranslationUnit.GetOrCreate(handle);
            }

            internal string Source { get; }
            internal TranslationUnit Unit { get; }

            public void Dispose()
            {
                Unit.Dispose();
                this.index.Dispose();
                Directory.Delete(this.directory, recursive: true);
            }
        }
    }
}
