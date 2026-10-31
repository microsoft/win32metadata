using System;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Win32MetadataScraper;
using Xunit;

namespace Win32MetadataScraperTests
{
    public class GeneratedSourceTests
    {
        [Theory]
        [InlineData("\n")]
        [InlineData("\r\n")]
        public void UnchangedSourcesPreserveExactTextAndReuseTheirTree(string newline)
        {
            string text = string.Join(newline, new[]
            {
                "#nullable enable",
                "// generated source",
                "namespace Test { public struct Record { public string? Text; } }",
                "",
            });
            var source = GeneratedSource.FromText(text);
            Assert.Same(text, source.Text);
            Assert.Same(source.Root, source.Root);
            Assert.Same(source.Tree, source.Tree);
            Assert.Same(source.Root, source.Tree.GetRoot());
            Assert.Same(text, source.Text);
            Assert.Equal(text, source.Root.ToFullString());
        }

        [Fact]
        public void RewrittenRootsRetainSyntaxIdentityAndFormatOnlyTheirOutput()
        {
            var marker = new SyntaxAnnotation("in-memory-projection");
            var root = SyntaxFactory.ParseCompilationUnit("namespace Test{public struct Record{public int Value;}}")
                .WithAdditionalAnnotations(marker);
            var source = GeneratedSource.FromRoot(root);
            Assert.Same(root, source.Root);
            Assert.True(source.Tree.GetRoot().HasAnnotation(marker));
            string expected = root.NormalizeWhitespace().ToFullString() + Environment.NewLine;
            Assert.Equal(expected, source.Text);
            Assert.Same(source.Text, source.Text);
            Assert.Same(root, source.Root);
            Assert.True(source.Tree.GetRoot().HasAnnotation(marker));
        }

        [Fact]
        public void RewritingDoesNotChangeTheOriginalSemanticSnapshot()
        {
            var original = GeneratedSource.FromText("public struct Record { public int Value; }");
            var type = original.Root.DescendantNodes().OfType<PredefinedTypeSyntax>().Single();
            var rewritten = GeneratedSource.FromRoot(original.Root.ReplaceNode(type,
                SyntaxFactory.PredefinedType(SyntaxFactory.Token(SyntaxKind.LongKeyword))));
            var references = new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) };
            var before = CSharpCompilation.Create("Before", new[] { original.Tree }, references);
            var after = CSharpCompilation.Create("After", new[] { rewritten.Tree }, references);
            Assert.Equal(SpecialType.System_Int32, before.GetSemanticModel(original.Tree)
                .GetTypeInfo(original.Root.DescendantNodes().OfType<PredefinedTypeSyntax>().Single()).Type.SpecialType);
            Assert.Equal(SpecialType.System_Int64, after.GetSemanticModel(rewritten.Tree)
                .GetTypeInfo(rewritten.Root.DescendantNodes().OfType<PredefinedTypeSyntax>().Single()).Type.SpecialType);
            Assert.Contains("int Value", original.Text);
            Assert.Contains("long Value", rewritten.Text);
            Assert.NotSame(original.Tree, rewritten.Tree);
        }
    }
}
