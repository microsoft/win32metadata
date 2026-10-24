using System;
using System.Collections.Generic;
using System.IO;
using ClangSharp.Interop;
using Xunit;
using Xunit.Abstractions;

namespace Win32MetadataScraperTests
{
    [Collection(nameof(WinHttpNativeControlCollection))]
    public class NativeMetadataSelfTypedefTests
    {
        private readonly ITestOutputHelper output;

        public NativeMetadataSelfTypedefTests(ITestOutputHelper output) => this.output = output;

        private const string Prefix = @"
#define _Win32_NativeTypedef_ __attribute__((annotate(""Win32Metadata.NativeTypedef"")))
#define DECLARE_HANDLE(name) typedef struct name##__ { int unused; } *name
DECLARE_HANDLE(HANDLE_VALUE);
";

        [Theory]
        [InlineData("i686-pc-windows-msvc", "c")]
        [InlineData("x86_64-pc-windows-msvc", "c")]
        [InlineData("aarch64-pc-windows-msvc", "c")]
        [InlineData("i686-pc-windows-msvc", "c++")]
        [InlineData("x86_64-pc-windows-msvc", "c++")]
        [InlineData("aarch64-pc-windows-msvc", "c++")]
        public void OnlyCompilerLinkedAnnotatedSelfTypedefsProduceProof(string target, string language)
        {
            var proofs = Prove(Prefix + "_Win32_NativeTypedef_ typedef HANDLE_VALUE HANDLE_VALUE;", target, language);
            var proof = Assert.Single(proofs);
            Assert.Equal("HANDLE_VALUE", proof.Alias);
            Assert.Equal("::", proof.Scope);
            Assert.Equal(1, proof.PointerDepth);
            Assert.Contains("HANDLE_VALUE__", proof.CanonicalType);
            Assert.NotEmpty(proof.CanonicalDeclaration);
            Assert.NotEqual(proof.OriginalSource, proof.MetadataSource);
        }

        [Theory]
        [InlineData("i686-pc-windows-msvc")]
        [InlineData("x86_64-pc-windows-msvc")]
        [InlineData("aarch64-pc-windows-msvc")]
        public void MatchingQualifiedScopeRetainsItsCompilerDeclarationIdentity(string target)
        {
            var proof = Assert.Single(Prove("namespace Handles {" + Prefix +
                "_Win32_NativeTypedef_ typedef HANDLE_VALUE HANDLE_VALUE; }", target, "c++"));
            Assert.Equal("::Handles", proof.Scope);
            Assert.Equal(1, proof.PointerDepth);
            Assert.Contains("Handles", proof.CanonicalDeclaration);
        }

        [Theory]
        [InlineData("c")]
        [InlineData("c++")]
        public void ALinkedAliasFromAnotherProviderIsNotTheSameSourceRedeclaration(string language)
        {
            string directory = Path.Combine(Path.GetTempPath(), "native-self-provider-" + Guid.NewGuid().ToString("N"));
            Directory.CreateDirectory(directory);
            try
            {
                string header = Path.Combine(directory, "native-self-base.h");
                File.WriteAllText(header, Prefix);
                Assert.Empty(Prove("#include \"" + header + "\"\n" +
                    "_Win32_NativeTypedef_ typedef HANDLE_VALUE HANDLE_VALUE;",
                    "x86_64-pc-windows-msvc", language));
            }
            finally
            {
                Directory.Delete(directory, recursive: true);
            }
        }

        [Theory]
        [InlineData("typedef HANDLE_VALUE HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef HANDLE_VALUE OTHER;")]
        [InlineData("namespace Other { _Win32_NativeTypedef_ typedef ::HANDLE_VALUE HANDLE_VALUE; }")]
        [InlineData("_Win32_NativeTypedef_ typedef struct HANDLE_VALUE__ *HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef decltype(HANDLE_VALUE{}) HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ _Win32_NativeTypedef_ typedef HANDLE_VALUE HANDLE_VALUE;")]
        public void MissingIntentWrongScopeOrUnlinkedTypeSpellingCannotBecomeMetadataOnly(string declaration)
        {
            Assert.Empty(Prove(Prefix + declaration, "x86_64-pc-windows-msvc", "c++"));
        }

        [Theory]
        [InlineData("_Win32_NativeTypedef_ typedef int HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef HANDLE_VALUE *HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef const HANDLE_VALUE HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef HANDLE_VALUE const HANDLE_VALUE;")]
        [InlineData("_Win32_NativeTypedef_ typedef const struct HANDLE_VALUE__ *HANDLE_VALUE;")]
        public void TypeDepthAndQualifierChangesRetainTheirNativeErrors(string declaration)
        {
            Assert.Empty(Prove(Prefix + declaration, "x86_64-pc-windows-msvc", "c++", expectError: true));
        }

        private unsafe NativeMetadataSelfTypedefProof[] Prove(
            string source, string target, string language, bool expectError = false)
        {
            using var index = CXIndex.Create(false, false);
            using var input = CXUnsavedFile.Create("native-self-typedef.h", source);
            string standard = language == "c" ? "c17" : "c++17";
            Assert.Equal(CXErrorCode.CXError_Success, CXTranslationUnit.TryParse(index, "native-self-typedef.h",
                new[] { "-x", language, "-std=" + standard, "--target=" + target }, new[] { input },
                CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes, out var handle));
            using var unit = handle;
            bool error = false;
            for (uint i = 0; i < unit.NumDiagnostics; i++)
            {
                using var diagnostic = unit.GetDiagnostic(i);
                error |= diagnostic.Severity >= CXDiagnosticSeverity.CXDiagnostic_Error;
                using var text = diagnostic.Format(CXDiagnostic.DefaultDisplayOptions);
                this.output.WriteLine(text.ToString());
            }
            Assert.Equal(expectError, error);
            var proofs = new List<NativeMetadataSelfTypedefProof>();
            if (!error)
                Walk(unit.Cursor);
            return proofs.ToArray();

            void Walk(CXCursor cursor)
            {
                if (cursor.Kind == CXCursorKind.CXCursor_TypedefDecl)
                {
                    using var name = cursor.Spelling;
                    using var native = cursor.TypedefDeclUnderlyingType.Spelling;
                    cursor.Location.GetExpansionLocation(out var file, out var line, out var column, out _);
                    this.output.WriteLine($"{name}: {cursor.TypedefDeclUnderlyingType.kind} {native}; canonical={cursor.IsCanonical}; {file}:{line}:{column}");
                    cursor.VisitChildren((child, _, _) =>
                    {
                        using var childName = child.Spelling;
                        using var reference = child.Referenced.Spelling;
                        this.output.WriteLine($"  {child.Kind} {childName}; ref={child.Referenced.Kind} {reference}; canonical-link={child.Referenced.CanonicalCursor == cursor.CanonicalCursor}");
                        return CXChildVisitResult.CXChildVisit_Continue;
                    }, default);
                }
                if (NativeMetadataSelfTypedef.TryProve(cursor, out var proof))
                    proofs.Add(proof);
                cursor.VisitChildren((child, _, _) =>
                {
                    if (child.IsDeclaration || child.IsTranslationUnit)
                        Walk(child);
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
            }
        }
    }
}
