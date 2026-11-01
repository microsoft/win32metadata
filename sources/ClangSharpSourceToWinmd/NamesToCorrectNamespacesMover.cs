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
            IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces = null,
            ISet<(string Namespace, string Name)> nativeEnumTypes = null,
            IReadOnlyList<SemanticModel> nativeReferenceModels = null)
        {
            if (MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath))
            {
                return tree;
            }

            var nativeNames = nativeRecordNamespaces?.Keys.Select(key => key.Name)
                .ToHashSet(System.StringComparer.Ordinal);

            if (nativeReferenceModels?.Count > 0)
            {
                if (nativeReferenceModels.Any(model => model.SyntaxTree != tree))
                    throw new System.ArgumentException("Native references require models of the original source tree.",
                        nameof(nativeReferenceModels));
                tree = tree.WithRootAndOptions(new NativeReferenceRewriter(
                    nativeRecordNamespaces, nativeEnumTypes, nativeReferenceModels, nativeNames).Visit(tree.GetRoot()), tree.Options);
            }
            else if (nativeEnumTypes?.Count > 0)
                throw new System.ArgumentException("Source-bound enum references require original compiler bindings.",
                    nameof(nativeReferenceModels));

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
                root = new TypeQualificationRewriter(fields.Select(field => field.Declaration.Type),
                    original => Qualify(original, SyntaxUtils.GetEnclosingNamespace(original))).Visit(root);
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
                        nativeRecordNamespaces?.ContainsKey((ns, qualified.Right.Identifier.ValueText)) != true &&
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
                var movedMembers = new Dictionary<MemberDeclarationSyntax, bool>();
                var shadowedTypes = new Dictionary<SyntaxNode, HashSet<string>>();
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
                    SizeOfExpressionSyntax sizeOf => sizeOf.Type,
                    BaseTypeSyntax baseType => baseType.Type,
                    _ => null,
                }).Where(type => type != null && (type.Ancestors().OfType<StructDeclarationSyntax>().Any(nativeRecords.Contains) ||
                    type.Ancestors().OfType<MemberDeclarationSyntax>().Any(IsMoved) ||
                    RefersToRelocatedNativeType(type)))
                    .Distinct().ToArray();
                root = new TypeQualificationRewriter(types,
                    original => Qualify(original, SyntaxUtils.GetEnclosingNamespace(original))).Visit(root);
                tree = tree.WithRootAndOptions(root, tree.Options);

                bool IsMoved(MemberDeclarationSyntax declaration)
                {
                    if (movedMembers.TryGetValue(declaration, out bool moved))
                        return moved;
                    string name = declaration switch
                    {
                        StructDeclarationSyntax record => record.Identifier.ValueText,
                        EnumDeclarationSyntax enumeration => enumeration.Identifier.ValueText,
                        DelegateDeclarationSyntax callback => callback.Identifier.ValueText,
                        MethodDeclarationSyntax method when method.AttributeLists.ToString().Contains("[DllImport(") =>
                            method.Identifier.ValueText,
                        _ => null,
                    };
                    string ns = SyntaxUtils.GetEnclosingNamespace(declaration);
                    moved = name != null && TryGetNamespace(ns, name, out string owner) && owner != ns;
                    movedMembers.Add(declaration, moved);
                    return moved;
                }

                bool RefersToRelocatedNativeType(TypeSyntax type)
                {
                    if (nativeRecordNamespaces == null || nativeRecordNamespaces.Count == 0)
                        return false;
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
                            sourceTypes.Contains((ns, identifier.Identifier.ValueText)) &&
                            !IsShadowedType(identifier) =>
                            QualifiedAlias(TryGetNamespace(ns, identifier.Identifier.ValueText, out string owner)
                                ? owner : ns, identifier.Identifier.Text),
                        _ => type,
                    };
                }

                bool IsShadowedType(IdentifierNameSyntax identifier)
                {
                    string name = identifier.Identifier.ValueText;
                    foreach (var scope in identifier.Ancestors().Where(ancestor =>
                        ancestor is TypeDeclarationSyntax or MethodDeclarationSyntax))
                    {
                        if (!shadowedTypes.TryGetValue(scope, out var names))
                        {
                            names = new HashSet<string>(System.StringComparer.Ordinal);
                            if (scope is TypeDeclarationSyntax declaration)
                            {
                                if (declaration.TypeParameterList != null)
                                    names.UnionWith(declaration.TypeParameterList.Parameters.Select(parameter => parameter.Identifier.ValueText));
                                if (declaration.Parent is TypeDeclarationSyntax)
                                    names.Add(declaration.Identifier.ValueText);
                                names.UnionWith(declaration.Members.OfType<BaseTypeDeclarationSyntax>()
                                    .Select(member => member.Identifier.ValueText));
                                names.UnionWith(declaration.Members.OfType<DelegateDeclarationSyntax>()
                                    .Select(member => member.Identifier.ValueText));
                            }
                            else if (scope is MethodDeclarationSyntax { TypeParameterList: { } parameters })
                                names.UnionWith(parameters.Parameters.Select(parameter => parameter.Identifier.ValueText));
                            shadowedTypes.Add(scope, names);
                        }
                        if (names.Contains(name))
                            return true;
                    }
                    return false;
                }
            }

            var nameFixer = new NameFixer(namesToNamespaces, nativeRecordNamespaces, nativeNames);
            var newTree = nameFixer.FixNames(tree);
            return CSharpSyntaxTree.ParseText(newTree.GetText(), null, tree.FilePath);

            bool TryGetNamespace(string ns, string name, out string owner)
            {
                if (name.EndsWith(MetadataSyntaxTreeCleaner.RevertToTypeSuffix, System.StringComparison.Ordinal) &&
                    namesToNamespaces.TryGetValue(name[..^MetadataSyntaxTreeCleaner.RevertToTypeSuffix.Length], out owner))
                    return true;
                return TryResolveNamespace(ns, name, namesToNamespaces, nativeRecordNamespaces, nativeNames, out owner);
            }
        }

        private static bool TryResolveNamespace(string ns, string name,
            IReadOnlyDictionary<string, string> namesToNamespaces,
            IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces,
            ISet<string> nativeNames, out string owner)
        {
            if (nativeRecordNamespaces?.TryGetValue((ns, name), out owner) == true)
                return true;
            if (nativeNames?.Contains(name) == true)
            {
                owner = null;
                return false;
            }
            return namesToNamespaces.TryGetValue(name, out owner);
        }

        private static TypeSyntax QualifiedAlias(string ns, string name) =>
            SyntaxFactory.ParseTypeName($"global::{(string.IsNullOrEmpty(ns) ? "" : ns + ".")}{name}");

        private sealed class TypeQualificationRewriter : CSharpSyntaxRewriter
        {
            private readonly HashSet<TypeSyntax> types;
            private readonly System.Func<TypeSyntax, TypeSyntax> qualify;

            internal TypeQualificationRewriter(IEnumerable<TypeSyntax> types, System.Func<TypeSyntax, TypeSyntax> qualify)
            {
                this.types = types.ToHashSet();
                this.qualify = qualify;
            }

            // Composite types are qualified from their original node, including their children.
            public override SyntaxNode Visit(SyntaxNode node) =>
                node is TypeSyntax type && types.Contains(type)
                    ? qualify(type).WithTriviaFrom(type)
                    : base.Visit(node);
        }

        private sealed class NativeReferenceRewriter : CSharpSyntaxRewriter
        {
            private readonly IReadOnlyDictionary<(string Namespace, string Name), string> routes;
            private readonly ISet<(string Namespace, string Name)> enums;
            private readonly IReadOnlyList<SemanticModel> models;
            private readonly ISet<string> candidateNames;

            internal NativeReferenceRewriter(
                IReadOnlyDictionary<(string Namespace, string Name), string> routes,
                ISet<(string Namespace, string Name)> enums,
                IReadOnlyList<SemanticModel> models,
                ISet<string> candidateNames)
            {
                this.routes = routes;
                this.enums = enums;
                this.models = models;
                this.candidateNames = candidateNames;
            }

            public override SyntaxNode VisitQualifiedName(QualifiedNameSyntax node) =>
                !PreservesHandleStorage(node) && TryTypeRoute(node, out string name)
                    ? SyntaxFactory.ParseName(name).WithTriviaFrom(node)
                    : base.VisitQualifiedName(node);

            public override SyntaxNode VisitAliasQualifiedName(AliasQualifiedNameSyntax node) =>
                !PreservesHandleStorage(node) && TryTypeRoute(node, out string name)
                    ? SyntaxFactory.ParseName(name).WithTriviaFrom(node)
                    : base.VisitAliasQualifiedName(node);

            public override SyntaxNode VisitMemberAccessExpression(MemberAccessExpressionSyntax node)
            {
                if (CouldReferenceRoutedType(node.Expression) &&
                    (node.Expression is not IdentifierNameSyntax identifier ||
                        !models.Any(model => model.GetAliasInfo(identifier) != null)))
                {
                    if (TryTypeRoute(node.Expression, out string name))
                        return node.WithExpression(SyntaxFactory.ParseExpression(name).WithTriviaFrom(node.Expression));
                }
                return base.VisitMemberAccessExpression(node);
            }

            public override SyntaxNode VisitIdentifierName(IdentifierNameSyntax node)
            {
                if (!PreservesHandleStorage(node) && CouldReferenceRoutedType(node) &&
                    !models.Any(model => model.GetAliasInfo(node) != null) && TryTypeRoute(node, out string name))
                    return SyntaxFactory.ParseName(name).WithTriviaFrom(node);
                return base.VisitIdentifierName(node);
            }

            public override SyntaxNode VisitAttribute(AttributeSyntax node)
            {
                if (enums?.Count > 0 && node.ArgumentList?.Arguments.Count == 1 &&
                    node.ArgumentList.Arguments[0].Expression is LiteralExpressionSyntax literal &&
                    literal.IsKind(SyntaxKind.StringLiteralExpression))
                {
                    var replacements = models.Select(model =>
                    {
                        if (model.GetSymbolInfo(node).Symbol is not IMethodSymbol constructor ||
                            constructor.ContainingType.ToDisplayString() !=
                                "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute")
                            return null;
                        string value = literal.Token.ValueText;
                        var candidates = value.Contains('.', System.StringComparison.Ordinal)
                            ? new[] { model.Compilation.GetTypeByMetadataName(value) }
                            : model.LookupNamespacesAndTypes(literal.SpanStart, name: value)
                                .OfType<INamedTypeSymbol>().Where(type => type.TypeKind == TypeKind.Enum).ToArray();
                        if (candidates.Length != 1 || candidates[0] == null)
                            return null;
                        var type = candidates[0];
                        var key = (Namespace: type.ContainingNamespace.ToDisplayString(), type.Name);
                        return enums.Contains(key) ? GetTypeRoute(type, model)?.Substring("global::".Length) : null;
                    }).ToArray();
                    string name = ConsistentRoute(replacements, node);
                    if (name != null)
                        return node.WithArgumentList(node.ArgumentList.WithArguments(
                            SyntaxFactory.SingletonSeparatedList(node.ArgumentList.Arguments[0].WithExpression(
                                SyntaxFactory.LiteralExpression(SyntaxKind.StringLiteralExpression,
                                    SyntaxFactory.Literal(name)).WithTriviaFrom(literal)))));
                }
                return base.VisitAttribute(node);
            }

            private bool TryTypeRoute(SyntaxNode node, out string replacement)
            {
                replacement = null;
                if (!CouldReferenceRoutedType(node))
                    return false;
                replacement = ConsistentRoute(models.Select(model => GetTypeRoute(node, model)).ToArray(), node);
                return replacement != null;
            }

            private string GetTypeRoute(SyntaxNode node, SemanticModel model)
            {
                var binding = model.GetSymbolInfo(node);
                if (binding.Symbol is INamedTypeSymbol resolved)
                    return GetTypeRoute(resolved, model);
                if (binding.CandidateReason != CandidateReason.Ambiguous ||
                    binding.CandidateSymbols.Length == 0 ||
                    binding.CandidateSymbols.Any(symbol => symbol is not INamedTypeSymbol))
                    return null;
                var candidates = binding.CandidateSymbols.Cast<INamedTypeSymbol>().ToArray();
                var identities = candidates.Select(NativeIdentity).ToArray();
                if (identities.Any(identity => identity == null) || identities.Distinct().Count() != 1)
                    return null;
                var candidateRoutes = candidates.Select(type => GetTypeRoute(type, model)).ToArray();
                return candidateRoutes.All(route => route != null) && candidateRoutes.Distinct().Count() == 1
                    ? candidateRoutes[0] : null;
            }

            private static (string Identity, string NativeName)? NativeIdentity(INamedTypeSymbol type)
            {
                var identities = type.DeclaringSyntaxReferences.Select(reference =>
                {
                    if (reference.GetSyntax() is not StructDeclarationSyntax declaration)
                        return ((string Identity, string NativeName)?)null;
                    var record = NativeRecordSourceProvenance.Read(declaration);
                    if (record != null)
                        return (NativeRecordSourceProvenance.GetIdentityKey(record), record.NativeName);
                    var forward = NativeDeclarationSourceProvenance.Read(declaration);
                    return forward?.Kind == NativeDeclarationKind.IncompleteRecord
                        ? (NativeDeclarationSourceProvenance.GetIdentityKey(forward), forward.NativeName)
                        : ((string Identity, string NativeName)?)null;
                }).ToArray();
                return identities.Length != 0 && identities.All(identity => identity != null) &&
                    identities.Distinct().Count() == 1 ? identities[0] : null;
            }

            private bool CouldReferenceRoutedType(SyntaxNode node)
            {
                string name = node switch
                {
                    IdentifierNameSyntax identifier => identifier.Identifier.ValueText,
                    QualifiedNameSyntax { Right: IdentifierNameSyntax identifier } => identifier.Identifier.ValueText,
                    AliasQualifiedNameSyntax { Name: IdentifierNameSyntax identifier } => identifier.Identifier.ValueText,
                    MemberAccessExpressionSyntax { Name: IdentifierNameSyntax identifier } => identifier.Identifier.ValueText,
                    _ => null,
                };
                return name != null && candidateNames?.Contains(name) == true;
            }

            private string GetTypeRoute(INamedTypeSymbol type, SemanticModel model)
            {
                if (type == null || type.ContainingType != null || type.Arity != 0 ||
                    !SymbolEqualityComparer.Default.Equals(type.ContainingAssembly, model.Compilation.Assembly) ||
                    routes == null || !routes.TryGetValue(
                        (type.ContainingNamespace.ToDisplayString(), type.Name), out string owner))
                    return null;
                string name = type.Name;
                if (name.EndsWith(MetadataSyntaxTreeCleaner.RevertToTypeSuffix, System.StringComparison.Ordinal))
                {
                    string projectedName = name[..^MetadataSyntaxTreeCleaner.RevertToTypeSuffix.Length];
                    var target = model.Compilation.GetTypeByMetadataName(
                        owner.Length == 0 ? projectedName : owner + "." + projectedName);
                    if (target?.TypeKind == TypeKind.Struct && target.DeclaringSyntaxReferences.Length != 0 &&
                        target.DeclaringSyntaxReferences.All(reference =>
                            MetadataSyntaxTreeCleaner.IsLegacyManualSource(reference.SyntaxTree.FilePath) &&
                            reference.GetSyntax() is StructDeclarationSyntax { Members: { Count: > 0 } }))
                        name = projectedName;
                }
                string identifier = SyntaxFacts.GetKeywordKind(name) == SyntaxKind.None ? name : "@" + name;
                return "global::" + (owner.Length == 0 ? "" : owner + ".") + identifier;
            }

            private static string ConsistentRoute(string[] routes, SyntaxNode context)
            {
                if (routes.All(route => route == null))
                    return null;
                if (routes.Any(route => route == null) || routes.Distinct(System.StringComparer.Ordinal).Count() != 1)
                    throw new System.IO.InvalidDataException(
                        $"Native reference '{context}' does not have one compiler-bound owner across its source targets.");
                return routes[0];
            }

            private static bool PreservesHandleStorage(SyntaxNode context) =>
                context.Ancestors().OfType<FieldDeclarationSyntax>().Any(field =>
                    field.Parent is StructDeclarationSyntax declaration &&
                    NativeHandleSourceProvenance.TryRead(declaration, out _));

        }

        private class MovedData
        {
            public List<MemberDeclarationSyntax> Methods { get; } = new List<MemberDeclarationSyntax>();

            public List<MemberDeclarationSyntax> Others { get; } = new List<MemberDeclarationSyntax>();
        }

        private class NameFixer
        {
            Dictionary<string, string> namesToNamespaces;
            private readonly IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces;
            private readonly ISet<string> nativeNames;

            public NameFixer(Dictionary<string, string> namesToNamespaces,
                IReadOnlyDictionary<(string Namespace, string Name), string> nativeRecordNamespaces,
                ISet<string> nativeNames)
            {
                this.namesToNamespaces = namesToNamespaces;
                this.nativeRecordNamespaces = nativeRecordNamespaces;
                this.nativeNames = nativeNames;
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
                    if (TryResolveNamespace(currentNamespace, name, this.parent.namesToNamespaces,
                        this.parent.nativeRecordNamespaces, this.parent.nativeNames, out var requiredNamespace))
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
