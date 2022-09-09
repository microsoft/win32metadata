using System.Collections.Generic;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class NamesToCorrectNamespacesMover
    {
        public static SyntaxTree MoveNamesToCorrectNamespaces(SyntaxTree tree, Dictionary<string, string> namesToNamespaces)
        {
            if (tree.FilePath.EndsWith("manual.cs"))
            {
                return tree;
            }

            var nameFixer = new NameFixer(namesToNamespaces);
            var newTree = nameFixer.FixNames(tree);
            return CSharpSyntaxTree.ParseText(newTree.GetText(), null, tree.FilePath);
        }

        private class MovedData
        {
            public List<MemberDeclarationSyntax> Methods { get; } = new List<MemberDeclarationSyntax>();

            public List<MemberDeclarationSyntax> Others { get; } = new List<MemberDeclarationSyntax>();
        }

        private class NameFixer
        {
            Dictionary<string, string> namesToNamespaces;

            public NameFixer(Dictionary<string, string> namesToNamespaces)
            {
                this.namesToNamespaces = namesToNamespaces;
            }

            public SyntaxTree FixNames(SyntaxTree tree)
            {
                string filePath = tree.FilePath;
                Dictionary<string, MovedData> namespaceToMovedData = new Dictionary<string, MovedData>();
                tree = this.RemoveNames(tree, namespaceToMovedData);
                tree = this.AddNames(tree, namespaceToMovedData);
                
                var ret = tree.WithFilePath(filePath);
                return ret;
            }

            private SyntaxTree RemoveNames(SyntaxTree tree, Dictionary<string, MovedData> namespaceToMovedData)
            {
                TreeRewriterForRemoval treeRewriter = new TreeRewriterForRemoval(this, namespaceToMovedData);
                var newRoot = (CSharpSyntaxNode)treeRewriter.Visit(tree.GetRoot());
                return CSharpSyntaxTree.Create(newRoot, null);
            }

            private SyntaxTree AddNames(SyntaxTree tree, Dictionary<string, MovedData> namespaceToMovedData)
            {
                TreeRewriterForAdding treeRewriter = new TreeRewriterForAdding(namespaceToMovedData);
                var newRoot = (CSharpSyntaxNode)treeRewriter.Visit(tree.GetRoot());
                return CSharpSyntaxTree.Create(newRoot, null);
            }

            private class TreeRewriterForAdding : CSharpSyntaxRewriter
            {
                private Dictionary<string, MovedData> namespaceToMovedData;

                public TreeRewriterForAdding(Dictionary<string, MovedData> namespaceToMovedData)
                {
                    this.namespaceToMovedData = namespaceToMovedData;
                }

                public override SyntaxNode VisitCompilationUnit(CompilationUnitSyntax node)
                {
                    node = (CompilationUnitSyntax)base.VisitCompilationUnit(node);

                    if (this.namespaceToMovedData.Count != 0)
                    {
                        List<MemberDeclarationSyntax> newNamespaces = new List<MemberDeclarationSyntax>();
                        foreach (var pair in this.namespaceToMovedData)
                        {
                            var newNamespace = pair.Key;
                            var moveData = pair.Value;

                            var namespaceNode = SyntaxFactory.NamespaceDeclaration(SyntaxFactory.IdentifierName(newNamespace));
                            if (moveData.Others.Count != 0)
                            {
                                namespaceNode = namespaceNode.AddMembers(moveData.Others.ToArray());
                            }

                            if (moveData.Methods.Count != 0)
                            {
                                var apisClassDef = SyntaxFactory.ClassDeclaration("Apis").AddModifiers(
                                    SyntaxFactory.ParseToken("public"), SyntaxFactory.ParseToken("static"), SyntaxFactory.ParseToken("unsafe"), SyntaxFactory.ParseToken("partial")).
                                    AddMembers(moveData.Methods.ToArray());

                                namespaceNode = namespaceNode.AddMembers(apisClassDef);
                            }

                            namespaceNode =
                                namespaceNode.NormalizeWhitespace().WithLeadingTrivia(SyntaxFactory.Whitespace("\r\n")).WithTrailingTrivia(SyntaxFactory.Whitespace("\r\n"));

                            newNamespaces.Add(namespaceNode);
                        }

                        node = node.AddMembers(newNamespaces.ToArray());
                    }

                    return node;
                }
            }

            private class TreeRewriterForRemoval : CSharpSyntaxRewriter
            {
                private NameFixer parent;
                private Dictionary<string, MovedData> namespaceToMovedData;

                public TreeRewriterForRemoval(NameFixer parent, Dictionary<string, MovedData> namespaceToMovedData)
                {
                    this.parent = parent;
                    this.namespaceToMovedData = namespaceToMovedData;
                }

                private SyntaxNode VisitDeclarationSyntax(MemberDeclarationSyntax node, string name)
                {
                    if (this.parent.namesToNamespaces.TryGetValue(name, out var requiredNamespace))
                    {
                        var currentNamespace = SyntaxUtils.GetEnclosingNamespace(node);
                        if (requiredNamespace != currentNamespace)
                        {
                            if (!this.namespaceToMovedData.TryGetValue(requiredNamespace, out var movedData))
                            {
                                movedData = new MovedData();
                                this.namespaceToMovedData[requiredNamespace] = movedData;
                            }

                            movedData.Others.Add(node);
                            return null;
                        }
                    }

                    return node;
                }

                public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node)
                {
                    node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);

                    return this.VisitDeclarationSyntax(node, node.Identifier.ValueText);
                }

                public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
                {
                    node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);

                    return this.VisitDeclarationSyntax(node, node.Identifier.ValueText);
                }

                public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
                {
                    node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);
                    return this.VisitDeclarationSyntax(node, node.Identifier.ValueText);
                }

                public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
                {
                    node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);
                    var attributes = node.AttributeLists.ToString();
                    if (attributes.Contains("[DllImport("))
                    {
                        if (attributes.Contains("[DllImport(\"\""))
                        {
                            return null;
                        }

                        var methodName = node.Identifier.ValueText;
                        if (this.parent.namesToNamespaces.TryGetValue(methodName, out var requiredNamespace))
                        {
                            var currentNamespace = SyntaxUtils.GetEnclosingNamespace(node);
                            if (requiredNamespace != currentNamespace)
                            {
                                if (!this.namespaceToMovedData.TryGetValue(requiredNamespace, out var movedData))
                                {
                                    movedData = new MovedData();
                                    this.namespaceToMovedData[requiredNamespace] = movedData;
                                }

                                movedData.Methods.Add(node);
                                return null;
                            }
                        }
                    }

                    return node;
                }
            }
        }
    }
}
