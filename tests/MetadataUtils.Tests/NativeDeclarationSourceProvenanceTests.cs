using System;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Xunit;

namespace MetadataUtils.Tests
{
    public class NativeDeclarationSourceProvenanceTests
    {
        [Theory]
        [InlineData(NativeDeclarationKind.IncompleteRecord, false)]
        [InlineData(NativeDeclarationKind.IncompleteRecord, true)]
        [InlineData(NativeDeclarationKind.LogicalEnum, false)]
        [InlineData(NativeDeclarationKind.LogicalEnum, true)]
        public void RoundTripsOnlyDeclarationIdentity(NativeDeclarationKind kind, bool architecture)
        {
            var source = Source(kind) with { SourceArchitecture = architecture ? Architecture.X86 : null };
            var declaration = NativeDeclarationSourceProvenance.Attach(Declaration(kind), source);
            Assert.Equal(source, NativeDeclarationSourceProvenance.Read(declaration));
            Assert.Contains(architecture ? ".v2 " : ".v1 ", declaration.ToFullString());
            Assert.DoesNotContain("\"Size\"", declaration.ToFullString());
            Assert.DoesNotContain("\"Alignment\"", declaration.ToFullString());
            var reparsed = CSharpSyntaxTree.ParseText(declaration.ToFullString()).GetRoot()
                .DescendantNodes().OfType<BaseTypeDeclarationSyntax>().Single();
            Assert.Equal(source, NativeDeclarationSourceProvenance.Read(reparsed));
            if (declaration is StructDeclarationSyntax record)
            {
                Assert.Null(NativeRecordSourceProvenance.Read(record));
                Assert.Null(NativeTypedefSourceProvenance.Read(record));
            }
        }

        [Theory]
        [InlineData(NativeDeclarationKind.IncompleteRecord)]
        [InlineData(NativeDeclarationKind.LogicalEnum)]
        public void CacheRemainsBoundToTheExactImmutableNode(NativeDeclarationKind kind)
        {
            var empty = Declaration(kind);
            Assert.Null(NativeDeclarationSourceProvenance.Read(empty));
            var declaration = NativeDeclarationSourceProvenance.Attach(empty, Source(kind));
            var source = NativeDeclarationSourceProvenance.Read(declaration);
            Assert.Same(source, NativeDeclarationSourceProvenance.Read(declaration));
            var reparsed = CSharpSyntaxTree.ParseText(declaration.ToFullString()).GetRoot()
                .DescendantNodes().OfType<BaseTypeDeclarationSyntax>().Single();
            Assert.Equal(source, NativeDeclarationSourceProvenance.Read(reparsed));
            Assert.NotSame(source, NativeDeclarationSourceProvenance.Read(reparsed));
            Assert.Null(NativeDeclarationSourceProvenance.Read(
                declaration.WithTrailingTrivia(default(SyntaxTriviaList))));
            Assert.Throws<InvalidDataException>(() => NativeDeclarationSourceProvenance.Read(
                declaration.WithIdentifier(SyntaxFactory.Identifier("OTHER"))));
            var results = new NativeDeclarationSource[32];
            Parallel.For(0, results.Length, index =>
                results[index] = NativeDeclarationSourceProvenance.Read(declaration));
            Assert.All(results, result => Assert.Same(source, result));
        }

        [Theory]
        [InlineData("v1 ", "v3 ")]
        [InlineData("\"Line\":1", "\"Line\":\"1\"")]
        [InlineData("\"TraversedHeader\":true", "\"TraversedHeader\":1")]
        [InlineData("\"Kind\":0", "\"Kind\":\"IncompleteRecord\"")]
        [InlineData("\"Kind\":0", "\"Kind\":0,\"Size\":0")]
        [InlineData("\"Kind\":0", "\"Kind\":0,\"Identity\":\"duplicate\"")]
        public void RejectsMalformedOrLayoutBearingTransport(string original, string replacement)
        {
            var declaration = NativeDeclarationSourceProvenance.Attach(
                Declaration(NativeDeclarationKind.IncompleteRecord), Source(NativeDeclarationKind.IncompleteRecord));
            var comment = declaration.GetTrailingTrivia().Single(trivia =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia)).ToString();
            Assert.Contains(original, comment);
            var malformed = declaration.WithTrailingTrivia(SyntaxFactory.Comment(
                comment.Replace(original, replacement, StringComparison.Ordinal)));
            for (int repeat = 0; repeat < 2; repeat++)
                Assert.Throws<InvalidDataException>(() => NativeDeclarationSourceProvenance.Read(malformed));
            Assert.NotNull(NativeDeclarationSourceProvenance.Read(declaration));
            Assert.Throws<InvalidDataException>(() => NativeDeclarationSourceProvenance.Read(
                declaration.WithLeadingTrivia(declaration.GetTrailingTrivia())));
        }

        [Fact]
        public void DoesNotReplaceCompleteLayoutOrUnrelatedDeclarationIdentity()
        {
            var source = Source(NativeDeclarationKind.IncompleteRecord);
            foreach (string text in new[]
            {
                "public struct VALUE { public int field; }",
                "public struct VALUE<T> { }",
                "public struct VALUE : System.IDisposable { }",
                "public enum VALUE { First }",
            })
                Assert.Throws<InvalidDataException>(() => NativeDeclarationSourceProvenance.Attach(
                    (BaseTypeDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(text), source));
            Assert.False(NativeDeclarationSourceProvenance.SameDeclaration(source,
                source with { Identity = "c:@N@Other@S@VALUE", NativeName = "Other::VALUE" }));
            Assert.False(NativeDeclarationSourceProvenance.SameDeclaration(source,
                source with { HeaderHash = new string('b', 64) }));
            Assert.False(NativeDeclarationSourceProvenance.SameDeclaration(source,
                source with { Line = 2 }));
            Assert.True(NativeDeclarationSourceProvenance.SameDeclaration(source,
                source with { Namespace = "Another", TraversedHeader = false }));
            var local = source with { Identity = "c:declaration.h@S@VALUE" };
            Assert.NotEqual(NativeDeclarationSourceProvenance.GetIdentityKey(local),
                NativeDeclarationSourceProvenance.GetIdentityKey(
                    local with { Header = Path.GetFullPath(Path.Combine("other", "declaration.h")) }));
            Assert.Throws<InvalidDataException>(() => NativeDeclarationSourceProvenance.Attach(
                Declaration(NativeDeclarationKind.IncompleteRecord), source with { SourceArchitecture = Architecture.All }));
        }

        private static BaseTypeDeclarationSyntax Declaration(NativeDeclarationKind kind) =>
            (BaseTypeDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration(kind == NativeDeclarationKind.IncompleteRecord
                ? "public struct VALUE { }" : "public enum VALUE : uint { First = 1 }");

        private static NativeDeclarationSource Source(NativeDeclarationKind kind) => new(
            kind == NativeDeclarationKind.IncompleteRecord ? "c:@S@VALUE" : "c:declaration.h@T@VALUE",
            "VALUE", Path.GetFullPath("declaration.h"), new string('a', 64),
            1, 1, "VALUE", "Test", true, kind);
    }
}
