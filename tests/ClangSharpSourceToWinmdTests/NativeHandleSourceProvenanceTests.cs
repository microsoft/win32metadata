using System;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class NativeHandleSourceProvenanceTests
    {
        [TestMethod]
        public void HeaderProofRoundTripsAsAttachedSourceTriviaWithoutAddingAttributes()
        {
            var declaration = NativeHandleSourceProvenance.AttachHeaderDeclareHandle(Declaration(), "Native::TOKEN", "NativeTag*");
            declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(declaration.NormalizeWhitespace().ToFullString())!;
            Assert.IsTrue(NativeHandleSourceProvenance.TryRead(declaration, out var proof));
            Assert.AreEqual(NativeHandleSourceProvider.Header, proof.Provider);
            Assert.AreEqual("DECLARE_HANDLE", proof.Kind);
            Assert.AreEqual("::Native::TOKEN", proof.NativeAlias);
            Assert.AreEqual("TOKEN", proof.GeneratedAlias);
            Assert.AreEqual("NativeTag*", proof.StorageType);
            Assert.AreEqual(1, declaration.AttributeLists.SelectMany(list => list.Attributes).Count());
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(NativeHandleSourceProvenance.Remove(declaration), out _));
            Assert.AreEqual("", NativeHandleSourceProvenance.GetSignature(NativeHandleSourceProvenance.Remove(declaration)));
        }

        [DataTestMethod]
        [DataRow("OtherTag*")]
        [DataRow("NativeTag**")]
        [DataRow("void*")]
        [DataRow("int")]
        public void HeaderProofCannotDescribeDifferentOrAdditionalStorage(string storage)
        {
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachHeaderDeclareHandle(Declaration(), "TOKEN", storage));
        }

        [DataTestMethod]
        [DataRow("IntPtr")]
        [DataRow("NativeTag*")]
        [DataRow("void**")]
        public void RetainedProofRequiresActualVoidPointerStorage(string storage)
        {
            var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                $"public unsafe struct TOKEN {{ public {storage} Value; }}")!;
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachRetainedDeclareHandle(declaration, "TOKEN"));
        }

        [TestMethod]
        public void DuplicateProofsAreNotAcceptedOrAttachedAgain()
        {
            var declaration = NativeHandleSourceProvenance.AttachHeaderDeclareHandle(Declaration(), "TOKEN", "NativeTag*");
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachHeaderDeclareHandle(declaration, "TOKEN", "NativeTag*"));
            var duplicated = declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().AddRange(declaration.GetLeadingTrivia()));
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(duplicated, out _));
        }

        [DataTestMethod]
        [DataRow(".v1 ", ".v2 ")]
        [DataRow("\"DECLARE_HANDLE\"", "\"OTHER_KIND\"")]
        [DataRow("\"provider\":\"header\"", "\"provider\":\"retained\"")]
        [DataRow("\"storage\":\"NativeTag*\"", "\"storage\":\"OtherTag*\"")]
        [DataRow("\"kind\":\"DECLARE_HANDLE\"", "\"kind\":\"DECLARE_HANDLE\",\"kind\":\"DECLARE_HANDLE\"")]
        public void MalformedUnknownOrStaleProofsFailClosed(string original, string replacement)
        {
            string source = NativeHandleSourceProvenance.AttachHeaderDeclareHandle(Declaration(), "TOKEN", "NativeTag*")
                .NormalizeWhitespace().ToFullString().Replace(original, replacement, StringComparison.Ordinal);
            var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(source)!;
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(declaration, out _));
            Assert.AreNotEqual("", NativeHandleSourceProvenance.GetSignature(declaration));
        }

        [TestMethod]
        public void ProofsAreNotReadFromOtherDeclarationsOrCompilationUnitComments()
        {
            var proven = NativeHandleSourceProvenance.AttachHeaderDeclareHandle(Declaration(), "TOKEN", "NativeTag*");
            var root = CSharpSyntaxTree.ParseText(proven.GetLeadingTrivia().ToFullString() +
                "namespace Test { public unsafe struct TOKEN { public NativeTag* Value; } }").GetRoot();
            var declaration = root.DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(declaration, out _));
        }

        private static StructDeclarationSyntax Declaration() => (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
            "[global::Windows.Win32.Foundation.Metadata.NativeTypedef] public unsafe partial struct TOKEN { public NativeTag* Value; }")!;
    }
}
