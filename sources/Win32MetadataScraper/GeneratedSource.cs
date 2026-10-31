using System;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed class GeneratedSource
    {
        private string text;
        private CompilationUnitSyntax root;

        private GeneratedSource(string text, CompilationUnitSyntax root)
        {
            this.text = text;
            this.root = root;
        }

        internal static GeneratedSource FromText(string text)
            => new(text ?? throw new ArgumentNullException(nameof(text)), null);

        internal static GeneratedSource FromRoot(CompilationUnitSyntax root)
            => new(null, root ?? throw new ArgumentNullException(nameof(root)));

        internal CompilationUnitSyntax Root
        {
            get
            {
                if (root == null)
                {
                    using var timing = GenerationTiming.BeginSpan("projection.parse-generated-source");
                    timing?.SetCounter("sourceCharacters", text.Length);
                    timing?.SetCounter("parseCount", 1);
                    root = (CompilationUnitSyntax)CSharpSyntaxTree.ParseText(text).GetRoot();
                }
                return root;
            }
        }

        internal SyntaxTree Tree => Root.SyntaxTree;

        internal string Text
        {
            get
            {
                if (text == null)
                {
                    using var timing = GenerationTiming.BeginSpan("projection.format-generated-source");
                    text = Root.NormalizeWhitespace().ToFullString() + Environment.NewLine;
                    timing?.SetCounter("sourceCharacters", text.Length);
                    timing?.SetCounter("formatCount", 1);
                }
                return text;
            }
        }
    }
}
