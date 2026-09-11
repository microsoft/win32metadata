using System;
using System.Collections.Generic;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    /// <summary>
    /// Qualifies references to generated types whose simple name matches a top-level namespace.
    /// C# binds such a name to the namespace before it considers types brought in by using
    /// directives, so an unqualified reference from another namespace fails to compile even though
    /// the type is imported.
    /// </summary>
    public static class ShadowedTypeNameQualifier
    {
        public static CSharpCompilation QualifyShadowedTypeNames(CSharpCompilation compilation, Action<SyntaxTree> treeChangedCallback = null)
        {
            var shadowedTypes = GetShadowedTypes(compilation);
            if (shadowedTypes.Count == 0)
            {
                return compilation;
            }

            foreach (var tree in compilation.SyntaxTrees.ToArray())
            {
                var rewriter = new TreeRewriter(compilation.GetSemanticModel(tree), shadowedTypes);
                var root = tree.GetRoot();
                var newRoot = rewriter.Visit(root);
                if (newRoot != root)
                {
                    var newTree = tree.WithRootAndOptions(newRoot, tree.Options);
                    compilation = compilation.ReplaceSyntaxTree(tree, newTree);

                    treeChangedCallback?.Invoke(newTree);
                }
            }

            return compilation;
        }

        private static Dictionary<string, string> GetShadowedTypes(CSharpCompilation compilation)
        {
            // Namespaces from references count too. The generated sources are usually the only
            // place a type shares a name with a namespace defined by something they reference.
            var namespaceNames = new HashSet<string>(compilation.GlobalNamespace.GetNamespaceMembers().Select(n => n.Name), StringComparer.Ordinal);

            var ambiguousNames = new HashSet<string>(StringComparer.Ordinal);
            var shadowedTypes = new Dictionary<string, string>(StringComparer.Ordinal);

            foreach (var type in GetTypes(compilation.Assembly.GlobalNamespace))
            {
                if (!namespaceNames.Contains(type.Name))
                {
                    continue;
                }

                string qualifiedName = type.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
                if (shadowedTypes.TryGetValue(type.Name, out string existingName) && existingName != qualifiedName)
                {
                    // More than one generated type carries the shadowed name, so no single
                    // qualified name can replace an unqualified reference to it.
                    ambiguousNames.Add(type.Name);
                }
                else
                {
                    shadowedTypes[type.Name] = qualifiedName;
                }
            }

            foreach (string ambiguousName in ambiguousNames)
            {
                shadowedTypes.Remove(ambiguousName);
            }

            return shadowedTypes;
        }

        private static IEnumerable<INamedTypeSymbol> GetTypes(INamespaceSymbol namespaceSymbol)
        {
            foreach (var type in namespaceSymbol.GetTypeMembers())
            {
                yield return type;
            }

            foreach (var childNamespace in namespaceSymbol.GetNamespaceMembers())
            {
                foreach (var type in GetTypes(childNamespace))
                {
                    yield return type;
                }
            }
        }

        private class TreeRewriter : CSharpSyntaxRewriter
        {
            private SemanticModel model;
            private Dictionary<string, string> shadowedTypes;

            public TreeRewriter(SemanticModel model, Dictionary<string, string> shadowedTypes)
            {
                this.model = model;
                this.shadowedTypes = shadowedTypes;
            }

            public override SyntaxNode VisitIdentifierName(IdentifierNameSyntax node)
            {
                if (!this.shadowedTypes.TryGetValue(node.Identifier.ValueText, out string qualifiedName) ||
                    !IsPotentialTypeReference(node) ||
                    !this.BoundToNamespace(node))
                {
                    return base.VisitIdentifierName(node);
                }

                return SyntaxFactory.ParseName(qualifiedName).WithTriviaFrom(node);
            }

            private static bool IsPotentialTypeReference(IdentifierNameSyntax node)
            {
                // The left-most name of a dotted name refers to the namespace, not the type.
                if (node.Parent is QualifiedNameSyntax qualifiedName && qualifiedName.Left == node)
                {
                    return false;
                }

                if (node.Parent is MemberAccessExpressionSyntax memberAccess && memberAccess.Expression == node)
                {
                    return false;
                }

                // Using and namespace declarations always name a namespace.
                SyntaxNode outerName = node;
                while (outerName.Parent is NameSyntax)
                {
                    outerName = outerName.Parent;
                }

                return !(outerName.Parent is UsingDirectiveSyntax || outerName.Parent is BaseNamespaceDeclarationSyntax);
            }

            private bool BoundToNamespace(IdentifierNameSyntax node)
            {
                var symbolInfo = this.model.GetSymbolInfo(node);
                return symbolInfo.Symbol is INamespaceSymbol || symbolInfo.CandidateSymbols.Any(symbol => symbol is INamespaceSymbol);
            }
        }
    }
}
