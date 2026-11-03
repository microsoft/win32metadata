using System;
using System.IO;
using System.Linq;
using System.Text;
using ClangSharpSourceToWinmd;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace ClangSharpSourceToWinmdTests
{
    [TestClass]
    public class OpaqueStructPointerSourceProvenanceTests
    {
        [DataTestMethod]
        [DataRow(false)]
        [DataRow(true)]
        public void ExactOpaqueProofRoundTripsAsSourceTrivia(bool retained)
        {
            var declaration = Declaration(retained ? "IntPtr" : "REMAPPED_TAG*");
            declaration = retained
                ? NativeHandleSourceProvenance.AttachRetainedOpaqueStructPointer(
                    declaration, "Native::COOKIE", "Native::RecordTag", explicitWrapperIntent: true)
                : NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                    declaration, "Native::COOKIE", "Native::RecordTag", "REMAPPED_TAG*", explicitWrapperIntent: true);
            declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                declaration.NormalizeWhitespace().ToFullString())!;
            Assert.IsTrue(NativeHandleSourceProvenance.TryRead(declaration, out var proof));
            Assert.AreEqual(retained ? NativeHandleSourceProvider.Retained : NativeHandleSourceProvider.Header, proof.Provider);
            Assert.AreEqual(NativeHandleSourceProvenance.OpaqueStructPointerKind, proof.Kind);
            Assert.AreEqual("::Native::COOKIE", proof.NativeAlias);
            Assert.AreEqual("::Native::RecordTag", proof.NativeTag);
            Assert.AreEqual("COOKIE", proof.GeneratedAlias);
            Assert.AreEqual(retained ? "IntPtr" : "REMAPPED_TAG*", proof.StorageType);
            Assert.IsTrue(proof.WrapperIntent);
            Assert.AreEqual(1, proof.PointerDepth);
            Assert.AreEqual(1, declaration.AttributeLists.SelectMany(list => list.Attributes).Count());
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(NativeHandleSourceProvenance.Remove(declaration), out _));
            Assert.AreEqual("", NativeHandleSourceProvenance.GetSignature(NativeHandleSourceProvenance.Remove(declaration)));
        }

        [DataTestMethod]
        [DataRow("typedef struct RecordTag", "::RecordTag")]
        [DataRow("typedef struct Native::RecordTag", "::Native::RecordTag")]
        [DataRow("typedef struct ::Native::RecordTag", "::Native::RecordTag")]
        public void FactoryRecordsTheExactQualifiedNativeTag(string valueType, string nativeTag)
        {
            var declaration = GenerateRetained(valueType, explicitWrapperIntent: true);
            Assert.IsTrue(NativeHandleSourceProvenance.TryRead(declaration, out var proof));
            Assert.AreEqual(NativeHandleSourceProvider.Retained, proof.Provider);
            Assert.AreEqual(NativeHandleSourceProvenance.OpaqueStructPointerKind, proof.Kind);
            Assert.AreEqual("::COOKIE", proof.NativeAlias);
            Assert.AreEqual(nativeTag, proof.NativeTag);
            Assert.AreEqual("IntPtr", declaration.Members.OfType<FieldDeclarationSyntax>().Single().Declaration.Type.ToString());
            Assert.AreEqual(2, declaration.AttributeLists.SelectMany(list => list.Attributes)
                .Count(attribute => attribute.Name.ToString() == "InvalidHandleValue"));
        }

        [DataTestMethod]
        [DataRow("typedef struct RecordTag*")]
        [DataRow("typedef struct RecordTag const")]
        [DataRow("typedef struct const RecordTag")]
        [DataRow("typedef struct RecordTag extra")]
        [DataRow("typedef struct RecordTag::")]
        [DataRow("typedef struct ")]
        [DataRow("IntPtr")]
        [DataRow("void*")]
        public void OtherFactoriesCannotClaimOpaqueStructPointerOrigin(string valueType)
        {
            Assert.IsFalse(NativeHandleSourceProvenance.TryParseRetainedOpaqueStructFactory(valueType, out _));
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(GenerateRetained(valueType, explicitWrapperIntent: true), out _));
        }

        [TestMethod]
        public void ImplicitNativeTypedefFactoryBehaviorDoesNotProveExplicitIntent()
        {
            var declaration = GenerateRetained("typedef struct RecordTag", explicitWrapperIntent: false);
            Assert.IsTrue(declaration.AttributeLists.SelectMany(list => list.Attributes)
                .Any(attribute => attribute.Name.ToString() == "NativeTypedef"));
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(declaration, out _));
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachRetainedOpaqueStructPointer(
                    Declaration("IntPtr"), "COOKIE", "RecordTag", explicitWrapperIntent: false));
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                    Declaration("RecordTag*"), "COOKIE", "RecordTag", "RecordTag*", explicitWrapperIntent: false));
        }

        [TestMethod]
        public void RepeatedGenerationDoesNotUpgradeImplicitFactoryIntentToAnAuthoredProof()
        {
            var item = new AutoType
            {
                Name = "COOKIE", Namespace = "Test", ValueType = "typedef struct RecordTag",
                NativeTypedef = false, InvalidHandleValues = new long[] { 0 },
            };
            for (int pass = 0; pass < 2; pass++)
            {
                using var output = new MemoryStream();
                NativeTypedefStructsCreator.WriteToStream(new(), new[] { item }, output);
                var declaration = CSharpSyntaxTree.ParseText(Encoding.UTF8.GetString(output.ToArray())).GetRoot()
                    .DescendantNodes().OfType<StructDeclarationSyntax>().Single();
                Assert.IsFalse(NativeHandleSourceProvenance.TryRead(declaration, out _));
                Assert.IsTrue(declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Any(attribute => attribute.Name.ToString() == "NativeTypedef"));
                Assert.IsFalse(item.NativeTypedef);
            }
        }

        [DataTestMethod]
        [DataRow("RecordTag**")]
        [DataRow("void*")]
        [DataRow("int*")]
        [DataRow("IntPtr")]
        public void HeaderOpaqueProofRequiresSingleNamedPointerStorage(string storage)
        {
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                    Declaration(storage), "COOKIE", "RecordTag", storage, explicitWrapperIntent: true));
        }

        [DataTestMethod]
        [DataRow("void*")]
        [DataRow("IntPtr*")]
        [DataRow("UIntPtr")]
        [DataRow("RecordTag*")]
        public void RetainedOpaqueProofRequiresFactoryIntPtrStorage(string storage)
        {
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachRetainedOpaqueStructPointer(
                    Declaration(storage), "COOKIE", "RecordTag", explicitWrapperIntent: true));
        }

        [DataTestMethod]
        [DataRow("\"nativeTag\":\"::RecordTag\"", "\"nativeTag\":\"\"")]
        [DataRow("\"nativeTag\":\"::RecordTag\"", "\"nativeTag\":\"RecordTag\"")]
        [DataRow("\"nativeTag\":\"::RecordTag\"", "\"nativeTag\":\"::RecordTag*\"")]
        [DataRow("\"nativeTag\":\"::RecordTag\",", "")]
        [DataRow("\"wrapperIntent\":true", "\"wrapperIntent\":false")]
        [DataRow("\"wrapperIntent\":true", "\"wrapperIntent\":\"true\"")]
        [DataRow("\"wrapperIntent\":true,", "")]
        [DataRow("\"pointerDepth\":1", "\"pointerDepth\":2")]
        [DataRow("\"pointerDepth\":1", "\"pointerDepth\":1.0")]
        [DataRow("\"pointerDepth\":1", "\"pointerDepth\":18446744073709551616")]
        [DataRow("\"pointerDepth\":1", "\"pointerDepth\":1,\"pointerDepth\":1")]
        [DataRow("\"kind\":\"TYPEDEF_STRUCT_POINTER\"", "\"kind\":\"DECLARE_HANDLE\"")]
        [DataRow("\"provider\":\"header\"", "\"provider\":\"retained\"")]
        [DataRow("\"storage\":\"RecordTag*\"", "\"storage\":\"RecordTag**\"")]
        [DataRow(".v2 ", ".v1 ")]
        [DataRow(".v2 ", ".v3 ")]
        public void OpaqueProofsFailClosedForMissingStaleOrSemanticFields(string original, string replacement)
        {
            string source = NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                Declaration("RecordTag*"), "COOKIE", "RecordTag", "RecordTag*", explicitWrapperIntent: true)
                .NormalizeWhitespace().ToFullString().Replace(original, replacement, StringComparison.Ordinal);
            var declaration = (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(source)!;
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(declaration, out _));
            Assert.AreNotEqual("", NativeHandleSourceProvenance.GetSignature(declaration));
        }

        [TestMethod]
        public void OpaqueProofCannotBeDuplicatedOrReadFromADifferentDeclaration()
        {
            var declaration = NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                Declaration("RecordTag*"), "COOKIE", "RecordTag", "RecordTag*", explicitWrapperIntent: true);
            Assert.ThrowsException<ArgumentException>(() =>
                NativeHandleSourceProvenance.AttachHeaderOpaqueStructPointer(
                    declaration, "COOKIE", "RecordTag", "RecordTag*", explicitWrapperIntent: true));
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(
                declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().AddRange(declaration.GetLeadingTrivia())), out _));
            var root = CSharpSyntaxTree.ParseText(declaration.GetLeadingTrivia().ToFullString() +
                "namespace Test { " + Declaration("RecordTag*").ToFullString() + " }").GetRoot();
            Assert.IsFalse(NativeHandleSourceProvenance.TryRead(
                root.DescendantNodes().OfType<StructDeclarationSyntax>().Single(), out _));
        }

        private static StructDeclarationSyntax GenerateRetained(string valueType, bool explicitWrapperIntent)
        {
            using var output = new MemoryStream();
            NativeTypedefStructsCreator.WriteToStream(new(), new[]
            {
                new AutoType
                {
                    Name = "COOKIE", Namespace = "Test", ValueType = valueType,
                    NativeTypedef = explicitWrapperIntent, InvalidHandleValues = new long[] { -1, 0 },
                },
            }, output);
            return CSharpSyntaxTree.ParseText(Encoding.UTF8.GetString(output.ToArray())).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single();
        }

        private static StructDeclarationSyntax Declaration(string storage) =>
            (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(
                "[global::Windows.Win32.Foundation.Metadata.NativeTypedef] public unsafe partial struct COOKIE " +
                $"{{ public {storage} Value; }}")!;
    }
}
