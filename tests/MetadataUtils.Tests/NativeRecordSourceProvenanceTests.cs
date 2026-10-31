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
    public class NativeRecordSourceProvenanceTests
    {
        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ReusesOnlyTheSameImmutableDeclarationProof(bool typedef)
        {
            var declaration = Attach(Declaration(), Source(), typedef);
            var first = Read(declaration, typedef);
            Assert.Same(first, Read(declaration, typedef));
            var reparsed = CSharpSyntaxTree.ParseText(declaration.ToFullString()).GetRoot()
                .DescendantNodes().OfType<StructDeclarationSyntax>().Single();
            Assert.Equal(first, Read(reparsed, typedef));
            Assert.NotSame(first, Read(reparsed, typedef));

            var variant = declaration.WithIdentifier(SyntaxFactory.Identifier("VALUE____1"));
            Assert.Equal(first, Read(variant, typedef));
            Assert.NotSame(first, Read(variant, typedef));
            Assert.Throws<InvalidDataException>(() =>
                Read(declaration.WithIdentifier(SyntaxFactory.Identifier("OTHER")), typedef));
            Assert.Same(first, Read(declaration, typedef));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void RechecksChangedMissingDuplicateAndMalformedProofs(bool typedef)
        {
            var empty = Declaration();
            Assert.Null(Read(empty, typedef));
            var declaration = Attach(empty, Source(), typedef);
            var first = Read(declaration, typedef);
            Assert.NotNull(first);
            Assert.Null(Read(declaration.WithTrailingTrivia(default(SyntaxTriviaList)), typedef));

            var changed = Attach(empty, Source() with { HeaderHash = new string('b', 64) }, typedef);
            Assert.NotEqual(first, Read(changed, typedef));
            var duplicate = declaration.WithLeadingTrivia(declaration.GetTrailingTrivia());
            var malformed = declaration.WithTrailingTrivia(SyntaxFactory.Comment(
                declaration.GetTrailingTrivia().Single(trivia =>
                    trivia.IsKind(SyntaxKind.MultiLineCommentTrivia)).ToString()
                    .Replace("\"Size\":4", "\"Size\":\"4\"", StringComparison.Ordinal)));
            foreach (var invalid in new[] { duplicate, malformed })
                for (int repeat = 0; repeat < 2; repeat++)
                    Assert.Throws<InvalidDataException>(() => Read(invalid, typedef));
            Assert.Same(first, Read(declaration, typedef));
        }

        [Fact]
        public void KeepsRecordTypedefAndConfiguredBindingProofsSeparate()
        {
            var declaration = Declaration();
            Assert.Null(NativeRecordSourceProvenance.Read(declaration));
            Assert.Null(NativeTypedefSourceProvenance.Read(declaration));
            Assert.False(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));
            var source = Source() with { SourceArchitecture = Architecture.X86 };
            declaration = NativeTypedefSourceProvenance.Attach(declaration, source);
            declaration = NativeTypedefProjectionProvenance.WithPolicy(declaration, false);
            Assert.Equal(source, NativeTypedefSourceProvenance.Read(declaration));
            Assert.Null(NativeRecordSourceProvenance.Read(declaration));
            Assert.False(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));
            declaration = NativeTypedefProjectionProvenance.WithConfiguredNominalBinding(declaration);
            Assert.Equal(source, NativeTypedefSourceProvenance.Read(declaration));
            Assert.Null(NativeRecordSourceProvenance.Read(declaration));
            Assert.True(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));

            var inferred = NativeTypedefProjectionProvenance.WithPolicy(declaration, true);
            Assert.Throws<InvalidDataException>(() =>
                NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(inferred));
            Assert.True(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration));
        }

        [Theory]
        [InlineData(false)]
        [InlineData(true)]
        public void ConcurrentReadersShareTheValidatedProof(bool typedef)
        {
            var declaration = Attach(Declaration(), Source(), typedef);
            var results = new NativeRecordSource[64];
            Parallel.For(0, results.Length, index => results[index] = Read(declaration, typedef));
            Assert.All(results, source => Assert.Same(results[0], source));
            Assert.Equal(Source(), results[0]);
        }

        private static StructDeclarationSyntax Declaration() =>
            (StructDeclarationSyntax)SyntaxFactory.ParseMemberDeclaration("public struct VALUE { public int Value; }");

        private static NativeRecordSource Source() => new(
            "c:@S@VALUE", "VALUE", Path.GetFullPath("native-source.h"), new string('a', 64),
            1, 1, "VALUE", "Test", true, 4, 4);

        private static StructDeclarationSyntax Attach(StructDeclarationSyntax declaration,
            NativeRecordSource source, bool typedef) => typedef
                ? NativeTypedefSourceProvenance.Attach(declaration, source)
                : NativeRecordSourceProvenance.Attach(declaration, source);

        private static NativeRecordSource Read(StructDeclarationSyntax declaration, bool typedef) => typedef
            ? NativeTypedefSourceProvenance.Read(declaration)
            : NativeRecordSourceProvenance.Read(declaration);
    }
}
