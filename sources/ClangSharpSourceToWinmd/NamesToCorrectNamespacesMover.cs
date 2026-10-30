using System.Collections.Generic;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;

namespace ClangSharpSourceToWinmd
{
    public class NamesToCorrectNamespacesMover
    {
        public static SyntaxTree MoveNamesToCorrectNamespaces(SyntaxTree tree, Dictionary<string, string> namesToNamespaces,
            ISet<(string Namespace, string Name)> sourceTypes = null,
            IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces = null)
        {
            if (tree.FilePath.EndsWith("manual.cs"))
            {
                return tree;
            }

            if (HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath))
            {
                var root = tree.GetRoot();
                var declarations = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                    .ToLookup(declaration => (SyntaxUtils.GetEnclosingNamespace(declaration), declaration.Identifier.ValueText));
                var aliases = root.DescendantNodes().OfType<UsingDirectiveSyntax>()
                    .Where(directive => directive.Alias != null)
                    .Select(directive => directive.Alias.Name.Identifier.ValueText).ToHashSet();
                var fields = declarations.SelectMany(group => group)
                    // Proven handles retain their exact producer storage spelling until composition validates it.
                    .Where(declaration => !NativeHandleSourceProvenance.TryRead(declaration, out _))
                    .SelectMany(declaration => declaration.Members.OfType<FieldDeclarationSyntax>()).ToArray();
                root = root.ReplaceNodes(fields.Select(field => field.Declaration.Type),
                    (original, _) => Qualify(original, SyntaxUtils.GetEnclosingNamespace(original)).WithTriviaFrom(original));
                tree = tree.WithRootAndOptions(root, tree.Options);

                TypeSyntax Qualify(TypeSyntax type, string ns)
                {
                    if (type is PointerTypeSyntax pointer)
                        return pointer.WithElementType(Qualify(pointer.ElementType, ns));
                    if (type is IdentifierNameSyntax identifier)
                    {
                        string name = identifier.Identifier.ValueText;
                        if (aliases.Contains(name))
                            return type;
                        if (TryGetNamespace(ns, name, out string owner))
                            return QualifiedAlias(owner, identifier.Identifier.Text);
                        if (declarations.Contains((ns, name)))
                            return QualifiedAlias(ns, identifier.Identifier.Text);
                    }
                    else if (type is QualifiedNameSyntax qualified &&
                        TryGetNamespace(ns, qualified.Right.Identifier.ValueText, out string owner))
                        return QualifiedAlias(owner, qualified.Right.Identifier.Text);
                    return type;
                }
            }
            else if (sourceTypes?.Count > 0)
            {
                var root = tree.GetRoot();
                var nativeRecords = root.DescendantNodes().OfType<StructDeclarationSyntax>()
                    .Where(record => NativeRecordSourceProvenance.Read(record) != null).ToHashSet();
                var aliases = root.DescendantNodes().OfType<UsingDirectiveSyntax>()
                    .Where(directive => directive.Alias != null)
                    .Select(directive => directive.Alias.Name.Identifier.ValueText).ToHashSet();
                var types = root.DescendantNodes().Select(node => node switch
                {
                    VariableDeclarationSyntax variable => variable.Type,
                    MethodDeclarationSyntax method => method.ReturnType,
                    DelegateDeclarationSyntax callback => callback.ReturnType,
                    ParameterSyntax parameter => parameter.Type,
                    PropertyDeclarationSyntax property => property.Type,
                    IndexerDeclarationSyntax indexer => indexer.Type,
                    CastExpressionSyntax cast => cast.Type,
                    TypeOfExpressionSyntax typeOf => typeOf.Type,
                    BaseTypeSyntax baseType => baseType.Type,
                    _ => null,
                }).Where(type => type != null && (type.Ancestors().OfType<MemberDeclarationSyntax>().Any(IsMoved) ||
                    type.Ancestors().OfType<StructDeclarationSyntax>().Any(nativeRecords.Contains) ||
                    RefersToRelocatedNativeType(type)))
                    .Distinct().ToArray();
                root = root.ReplaceNodes(types,
                    (original, _) => Qualify(original, SyntaxUtils.GetEnclosingNamespace(original)).WithTriviaFrom(original));
                tree = tree.WithRootAndOptions(root, tree.Options);

                bool IsMoved(MemberDeclarationSyntax declaration)
                {
                    string name = declaration switch
                    {
                        StructDeclarationSyntax record => record.Identifier.ValueText,
                        EnumDeclarationSyntax enumeration => enumeration.Identifier.ValueText,
                        DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                        MethodDeclarationSyntax method when method.AttributeLists.ToString().Contains("[DllImport(") =>
                            method.Identifier.ValueText,
                        _ => null,
                    };
                    return name != null && TryGetNamespace(SyntaxUtils.GetEnclosingNamespace(declaration), name, out string owner) &&
                        owner != SyntaxUtils.GetEnclosingNamespace(declaration);
                }

                bool RefersToRelocatedNativeType(TypeSyntax type)
                {
                    string ns = SyntaxUtils.GetEnclosingNamespace(type);
                    return type.DescendantNodesAndSelf().OfType<IdentifierNameSyntax>().Any(identifier =>
                        sourceTypes.Contains((ns, identifier.Identifier.ValueText)) &&
                        nativeRecordNamespaces?.TryGetValue((ns, identifier.Identifier.ValueText), out string owner) == true &&
                        owner != ns);
                }

                TypeSyntax Qualify(TypeSyntax type, string ns)
                {
                    return type switch
                    {
                        PointerTypeSyntax pointer => pointer.WithElementType(Qualify(pointer.ElementType, ns)),
                        ArrayTypeSyntax array => array.WithElementType(Qualify(array.ElementType, ns)),
                        NullableTypeSyntax nullable => nullable.WithElementType(Qualify(nullable.ElementType, ns)),
                        RefTypeSyntax reference => reference.WithType(Qualify(reference.Type, ns)),
                        GenericNameSyntax generic => generic.WithTypeArgumentList(generic.TypeArgumentList.WithArguments(
                            SyntaxFactory.SeparatedList(generic.TypeArgumentList.Arguments.Select(argument => Qualify(argument, ns))))),
                        FunctionPointerTypeSyntax function => function.WithParameterList(function.ParameterList.WithParameters(
                            SyntaxFactory.SeparatedList(function.ParameterList.Parameters.Select(parameter =>
                                parameter.WithType(Qualify(parameter.Type, ns)))))),
                        IdentifierNameSyntax identifier when !aliases.Contains(identifier.Identifier.ValueText) &&
                            !IsShadowedType(identifier) &&
                            sourceTypes.Contains((ns, identifier.Identifier.ValueText)) =>
                            QualifiedAlias(TryGetNamespace(ns, identifier.Identifier.ValueText, out string owner)
                                ? owner : ns, identifier.Identifier.Text),
                        _ => type,
                    };
                }

                static bool IsShadowedType(IdentifierNameSyntax identifier)
                {
                    string name = identifier.Identifier.ValueText;
                    return identifier.Ancestors().OfType<TypeDeclarationSyntax>().Any(declaration =>
                        declaration.TypeParameterList?.Parameters.Any(parameter => parameter.Identifier.ValueText == name) == true ||
                        declaration.Parent is TypeDeclarationSyntax && declaration.Identifier.ValueText == name ||
                        declaration.Members.OfType<BaseTypeDeclarationSyntax>().Any(member => member.Identifier.ValueText == name) ||
                        declaration.Members.OfType<DelegateDeclarationSyntax>().Any(member => member.Identifier.ValueText == name)) ||
                        identifier.Ancestors().OfType<MethodDeclarationSyntax>().Any(method =>
                            method.TypeParameterList?.Parameters.Any(parameter => parameter.Identifier.ValueText == name) == true);
                }
            }

            var nameFixer = new NameFixer(namesToNamespaces, nativeRecordNamespaces);
            var newTree = nameFixer.FixNames(tree);
            return CSharpSyntaxTree.ParseText(newTree.GetText(), null, tree.FilePath);

            bool TryGetNamespace(string ns, string name, out string owner)
            {
                if (name.EndsWith(MetadataSyntaxTreeCleaner.RevertToTypeSuffix, System.StringComparison.Ordinal) &&
                    namesToNamespaces.TryGetValue(name[..^MetadataSyntaxTreeCleaner.RevertToTypeSuffix.Length], out owner))
                    return true;
                return nativeRecordNamespaces?.TryGetValue((ns, name), out owner) == true ||
                    namesToNamespaces.TryGetValue(name, out owner);
            }
        }

        private static TypeSyntax QualifiedAlias(string ns, string name) =>
            SyntaxFactory.ParseTypeName($"global::{(string.IsNullOrEmpty(ns) ? "" : ns + ".")}{name}");

        private class MovedData
        {
            public List<MemberDeclarationSyntax> Methods { get; } = new List<MemberDeclarationSyntax>();

            public List<MemberDeclarationSyntax> Others { get; } = new List<MemberDeclarationSyntax>();
        }

        private class NameFixer
        {
            Dictionary<string, string> namesToNamespaces;
            private readonly IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces;

            public NameFixer(Dictionary<string, string> namesToNamespaces,
                IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces)
            {
                this.namesToNamespaces = namesToNamespaces;
                this.nativeRecordNamespaces = nativeRecordNamespaces;
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
                    string currentNamespace = SyntaxUtils.GetEnclosingNamespace(node);
                    if (this.parent.nativeRecordNamespaces?.TryGetValue((currentNamespace, name), out var requiredNamespace) == true ||
                        this.parent.namesToNamespaces.TryGetValue(name, out requiredNamespace))
                    {
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
                    bool namespaceType = node.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax;
                    node = (EnumDeclarationSyntax)base.VisitEnumDeclaration(node);

                    return namespaceType ? this.VisitDeclarationSyntax(node, node.Identifier.ValueText) : node;
                }

                public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node)
                {
                    bool namespaceType = node.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax;
                    node = (StructDeclarationSyntax)base.VisitStructDeclaration(node);

                    return namespaceType ? this.VisitDeclarationSyntax(node, node.Identifier.ValueText) : node;
                }

                public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node)
                {
                    bool namespaceType = node.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax;
                    node = (DelegateDeclarationSyntax)base.VisitDelegateDeclaration(node);
                    return namespaceType ? this.VisitDeclarationSyntax(node, node.Identifier.ValueText) : node;
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
