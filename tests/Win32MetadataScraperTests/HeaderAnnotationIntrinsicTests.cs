using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class HeaderAnnotationIntrinsicTests
    {
        internal const string Declarations = @"
extern ""C"" {
_Win32_SupportedOS_WindowsVista_ void __builtin_trap(void);
void* __builtin_memcpy(_Win32_Retained_ void* destination, const void* source, __SIZE_TYPE__ size);
#if defined(_M_IX86) || defined(_M_X64)
_Win32_SupportedOS_WindowsVista_ void _mm_pause(void);
#pragma intrinsic(_mm_pause)
#endif
#if defined(_M_X64)
_Win32_SupportedOS_WindowsVista_ void __faststorefence(void);
#pragma intrinsic(__faststorefence)
#endif
_Win32_SupportedOS_Windows7_ int Ordinary(_Win32_Retained_ void* context);
}
";

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc", true)]
        [InlineData("x64", "x86_64-pc-windows-msvc", true)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", true)]
        [InlineData("x86", "i686-pc-windows-msvc", false)]
        [InlineData("x64", "x86_64-pc-windows-msvc", false)]
        [InlineData("arm64", "aarch64-pc-windows-msvc", false)]
        public void CompilerBuiltinsUseActualAttributesRatherThanNamesOrImports(string architecture, string target, bool annotated)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, Declarations + @"
namespace Client {
_Win32_SupportedOS_Windows7_ int _mm_pause(unsigned value);
_Win32_SupportedOS_Windows7_ int __faststorefence(unsigned value);
}
", annotationsEnabled: annotated);
            Inspect(fixture, target, annotated, (unit, functions) =>
            {
                var expected = new List<string> { "__builtin_trap", "__builtin_memcpy" };
                if (architecture != "arm64") expected.Add("_mm_pause");
                if (architecture == "x64") expected.Add("__faststorefence");
                foreach (string name in expected)
                {
                    var function = Assert.Single(functions.Where(function => function.Name == name &&
                        function.SemanticParentCursor is not NamespaceDecl));
                    Assert.False(function.HasBody);
                    Assert.Contains(function.Attrs, attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin);
                }
                Assert.All(functions.Where(function => function.SemanticParentCursor is NamespaceDecl), function =>
                    Assert.DoesNotContain(function.Attrs, attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin));
            });
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var methods = CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>().ToArray();
            Assert.Equal(new[] { "Ordinary", "__faststorefence", "_mm_pause" },
                methods.Select(method => method.Identifier.ValueText).OrderBy(name => name, StringComparer.Ordinal));
            Assert.All(methods, method =>
            {
                Assert.Contains("DllImport", method.ToString());
                Assert.Equal(annotated, method.ToString().Contains("SupportedOSPlatform(\"windows6.1\")", StringComparison.Ordinal));
            });
            var ordinary = Assert.Single(methods.Where(method => method.Identifier.ValueText == "Ordinary"));
            Assert.Equal(annotated, ordinary.ParameterList.ToString().Contains(".Retained", StringComparison.Ordinal));
        }

        [Theory]
        [InlineData("x86", "i686-pc-windows-msvc")]
        [InlineData("x64", "x86_64-pc-windows-msvc")]
        [InlineData("arm64", "aarch64-pc-windows-msvc")]
        public void CompilerBuiltinsDoNotWaiveEligibleUnprojectedFunctions(string architecture, string target)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture(architecture, target, Declarations);
            Inspect(fixture, target, annotated: true, (unit, functions) =>
            {
                var processor = new HeaderAnnotationProcessor(unit, new Dictionary<string, string>(), "Test",
                    new[] { fixture.Header }, new HashSet<string>(), excludeFunctionsWithBody: false);
                var error = Assert.Throws<HeaderAnnotationDiagnosticsException>(() => processor.ValidateProjection());
                var diagnostics = error.Message.Split(new[] { "\r\n", "\n" }, StringSplitOptions.RemoveEmptyEntries);
                Assert.Equal(2, diagnostics.Length);
                Assert.EndsWith("Annotation facts for 'Ordinary' were not projected by ClangSharp. [native target: ::Ordinary]",
                    diagnostics[0]);
                Assert.EndsWith("Annotation facts for 'context' were not projected by ClangSharp. [native target: ::Ordinary::context]",
                    diagnostics[1]);
                Assert.All(diagnostics, diagnostic => Assert.Contains("error WMA001:", diagnostic));
            });
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void CompilerBuiltinRedeclarationsKeepCanonicalAndOrdinaryOwnersDistinct(bool annotateFirst)
        {
            const string plain = "void _mm_pause(void);\n";
            const string annotated = "_Win32_SupportedOS_WindowsVista_ void _mm_pause(void);\n";
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                "extern \"C\" {\n" + (annotateFirst ? annotated + plain : plain + annotated) + @"
}
#pragma intrinsic(_mm_pause)
namespace Client {
_Win32_SupportedOS_Windows7_ int _mm_pause(unsigned value);
}
");
            Inspect(fixture, "x86_64-pc-windows-msvc", annotated: true, (unit, functions) =>
            {
                var builtins = functions.Where(function => function.Name == "_mm_pause" &&
                    function.SemanticParentCursor is not NamespaceDecl).ToArray();
                Assert.Equal(2, builtins.Length);
                Assert.Equal(builtins[0].Handle.CanonicalCursor, builtins[1].Handle.CanonicalCursor);
                Assert.All(builtins, function =>
                    Assert.Contains(function.Attrs, attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin));
                var ordinary = Assert.Single(functions.Where(function => function.Name == "_mm_pause" &&
                    function.SemanticParentCursor is NamespaceDecl));
                Assert.NotEqual(builtins[0].Handle.CanonicalCursor, ordinary.Handle.CanonicalCursor);
                Assert.DoesNotContain(ordinary.Attrs, attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin);
            });
            Assert.True(fixture.Run() == 0, fixture.Diagnostics);
            var method = Assert.Single(CSharpSyntaxTree.ParseText(fixture.ReadSource()).GetRoot().DescendantNodes()
                .OfType<MethodDeclarationSyntax>());
            Assert.Equal("_mm_pause", method.Identifier.ValueText);
            Assert.Contains("SupportedOSPlatform(\"windows6.1\")", method.ToString());
            Assert.DoesNotContain("SupportedOSPlatform(\"windows6.0.6000\")", method.ToString());
        }

        [Theory]
        [InlineData("_Win32_Optional_(true)", "not valid on")]
        [InlineData("_Win32_Optional_(1)", "exactly true or false")]
        [InlineData("_Win32_SupportedOS_Windows7_ _Win32_SupportedOS_Windows8_", "Conflicting")]
        [InlineData("_WIN32META_ANNOTATION_(\"RAIIFree(CloseThing, 0)\")", "compiler-parsed")]
        public void CompilerBuiltinSelectionStillParsesAndValidatesAnnotations(string annotation, string diagnostic)
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc",
                $"extern \"C\" {annotation} void _mm_pause(void);\n#pragma intrinsic(_mm_pause)\nint Ordinary();");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains(diagnostic, fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        [Fact]
        public void CompilerBuiltinRedeclarationConflictsStillFail()
        {
            using var fixture = new HeaderAnnotationTests.NativeFixture("x64", "x86_64-pc-windows-msvc", @"
extern ""C"" {
_Win32_SupportedOS_Windows7_ void _mm_pause(void);
_Win32_SupportedOS_Windows8_ void _mm_pause(void);
}
#pragma intrinsic(_mm_pause)
int Ordinary();
");
            Assert.NotEqual(0, fixture.Run());
            Assert.Contains("WMA001", fixture.Diagnostics);
            Assert.Contains("Conflicting", fixture.Diagnostics);
            Assert.False(File.Exists(fixture.Output));
        }

        private static void Inspect(HeaderAnnotationTests.NativeFixture fixture, string target, bool annotated,
            Action<TranslationUnit, IReadOnlyList<FunctionDecl>> inspect)
        {
            var arguments = new List<string>
            {
                "--language=c++", "--std=c++17", "--target=" + target,
                "--include-directory=" + Path.Combine(AppContext.BaseDirectory, "assets"),
                "-D_USE_DECLSPECS_FOR_SAL=1", "-D_PREFAST_=1",
            };
            if (annotated) arguments.Add("-DWIN32METADATA");
            using var index = CXIndex.Create(false, false);
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index,
                Path.Combine(fixture.DirectoryPath, "test.cpp"), arguments.ToArray(), ReadOnlySpan<CXUnsavedFile>.Empty,
                CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes |
                CXTranslationUnit_Flags.CXTranslationUnit_VisitImplicitAttributes, out var handle));
            using var unit = TranslationUnit.GetOrCreate(handle);
            for (uint i = 0; i < handle.NumDiagnostics; i++)
            {
                using var diagnostic = handle.GetDiagnostic(i);
                Assert.True(diagnostic.Severity < CXDiagnosticSeverity.CXDiagnostic_Error,
                    diagnostic.Format(CXDiagnostic.DefaultDisplayOptions).ToString());
            }
            var functions = new List<FunctionDecl>();
            Walk(unit.TranslationUnitDecl);
            inspect(unit, functions);

            void Walk(Cursor cursor)
            {
                cursor.Location.GetFileLocation(out var file, out _, out _, out _);
                if (cursor is FunctionDecl function && Path.GetFileName(file.ToString()) == "test.h")
                    functions.Add(function);
                foreach (var child in cursor.CursorChildren)
                    if (child.Handle.IsDeclaration || child.Handle.IsTranslationUnit)
                        Walk(child);
            }
        }
    }
}
