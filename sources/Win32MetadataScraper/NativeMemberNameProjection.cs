using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using ClangSharp;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed record NativeLegacyMember(NamedDecl Declaration, string LegacyName);

    internal sealed class NativeMemberNameProjection : CSharpSyntaxRewriter
    {
        private readonly ILookup<(string File, uint Line, uint Column), NativeLegacyMember> members;

        internal NativeMemberNameProjection(IEnumerable<NativeLegacyMember> members)
        {
            this.members = members.ToLookup(member =>
            {
                member.Declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                return (Path.GetFullPath(file.ToString()).ToUpperInvariant(), line, column);
            });
        }

        internal string Attach(string source) =>
            GeneratedSource.FromRoot(Attach(GeneratedSource.FromText(source).Root)).Text;

        internal CompilationUnitSyntax Attach(CompilationUnitSyntax root) => (CompilationUnitSyntax)Visit(root);

        internal static string ParentIdentity(NamedDecl declaration)
        {
            var parents = new List<string>();
            var visited = new HashSet<Cursor>();
            for (var parent = declaration.SemanticParentCursor; parent is not null and not TranslationUnitDecl;
                parent = parent.SemanticParentCursor)
            {
                if (!visited.Add(parent))
                    throw new InvalidOperationException("Native member-name proof encountered a cyclic semantic parent.");
                parents.Add(NativeSourceIdentity.Of(parent).ToString());
            }
            if (parents.Count == 0)
                throw new InvalidOperationException("Native member-name proof requires a native record parent.");
            return string.Join(" <- ", parents);
        }

        public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
        {
            var member = Find(node, node.AttributeLists, node.Identifier.ValueText);
            node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);
            return member == null ? node : Attach(node, member);
        }

        public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
        {
            if (node.Declaration.Variables.Count != 1)
                return base.VisitFieldDeclaration(node);
            var member = Find(node, node.AttributeLists, node.Declaration.Variables[0].Identifier.ValueText);
            node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
            return member == null ? node : Attach(node, member);
        }

        private NativeLegacyMember Find(MemberDeclarationSyntax node, SyntaxList<AttributeListSyntax> attributes, string name)
        {
            var location = attributes.SelectMany(list => list.Attributes)
                .SingleOrDefault(attribute => attribute.Name.ToString() == "SourceLocation");
            if (location?.ArgumentList?.Arguments.Count != 3)
                return null;
            var arguments = location.ArgumentList.Arguments;
            string file = DeclarationSourceMap.ReadFilePath(((LiteralExpressionSyntax)arguments[0].Expression).Token);
            uint line = uint.Parse(arguments[1].Expression.ToString(), CultureInfo.InvariantCulture);
            uint column = uint.Parse(arguments[2].Expression.ToString(), CultureInfo.InvariantCulture);
            var matching = members[(file.ToUpperInvariant(), line, column)].Where(member =>
                member.Declaration.Name == name && (node is MethodDeclarationSyntax && member.Declaration is CXXMethodDecl ||
                    node is FieldDeclarationSyntax && member.Declaration is FieldDecl))
                .DistinctBy(member => member.Declaration.Handle.CanonicalCursor).ToArray();
            if (matching.Length > 1)
                throw new InvalidOperationException($"Native member-name transport is ambiguous at {file}:{line}:{column}.");
            return matching.SingleOrDefault();
        }

        private static T Attach<T>(T node, NativeLegacyMember member) where T : MemberDeclarationSyntax =>
            NativeMemberNameProvenance.Attach(node, NativeSourceIdentity.Of(member.Declaration).ToString(),
                ParentIdentity(member.Declaration),
                member.Declaration.Name, member.LegacyName);
    }
}
