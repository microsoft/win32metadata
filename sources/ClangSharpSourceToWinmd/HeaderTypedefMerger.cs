using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    internal static class HeaderTypedefMerger
    {
        private const string NativeTypedefName = "global::Windows.Win32.Foundation.Metadata.NativeTypedefAttribute";
        private const string ArchitectureName = "global::Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute";

        internal static CSharpCompilation Merge(CSharpCompilation compilation)
        {
            var fragments = new List<Fragment>();
            foreach (var tree in compilation.SyntaxTrees.Where(tree => IsGeneratedAliasFile(tree.FilePath)))
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                {
                    if (model.GetDeclaredSymbol(declaration) is not INamedTypeSymbol symbol)
                        continue;
                    var attributes = symbol.GetAttributes().Where(attribute =>
                        attribute.ApplicationSyntaxReference?.SyntaxTree == tree &&
                        declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                    if (!attributes.Any(attribute => AttributeName(attribute) == NativeTypedefName))
                        continue;
                    fragments.Add(new Fragment(tree, declaration, symbol, attributes));
                }
            }

            var replacements = new Dictionary<StructDeclarationSyntax, StructDeclarationSyntax>();
            foreach (var group in fragments.GroupBy(GetIdentity,
                StringComparer.Ordinal).Where(group => group.Any(fragment => HeaderEnumGroupMerger.IsHeaderTypesFile(fragment.Tree.FilePath))))
            {
                var aliases = group.OrderBy(fragment => IsAutoTypesFile(fragment.Tree.FilePath) ? 0 : 1)
                    .ThenBy(fragment => fragment.Tree.FilePath, StringComparer.Ordinal).ToArray();
                var first = aliases[0];
                if (aliases.Any(alias => alias.Symbol.DeclaringSyntaxReferences.Any(reference => !aliases.Any(fragment =>
                    fragment.Tree == reference.SyntaxTree && fragment.Declaration.Span == reference.Span))))
                    throw Error(first, "A header alias overlaps a declaration outside generated header-types/autotypes inputs.");
                if (aliases.Length < 2)
                    continue;
                if (aliases.GroupBy(alias => (alias.Tree, alias.Symbol.Name)).Any(declarations => declarations.Count() != 1))
                    throw Error(first, "Multiple native aliases in one input project to the same type.");

                var variants = aliases.Where(alias => GetArchitecture(alias) != 0).ToArray();
                if (variants.Length != 0)
                {
                    var retained = aliases.Where(alias => IsAutoTypesFile(alias.Tree.FilePath) && GetArchitecture(alias) == 0).ToArray();
                    bool headerOnly = aliases.Length == variants.Length;
                    if (!headerOnly && (retained.Length != 1 || aliases.Length != variants.Length + 1 ||
                        variants.Aggregate(0, (mask, alias) => mask | GetArchitecture(alias)) != (int)Architecture.All))
                        throw Error(first, "Architecture-specific aliases require one retained wrapper and complete x86/x64/arm64 coverage.");
                    foreach (var variantGroup in variants.GroupBy(alias => alias.Symbol.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)))
                    {
                        var copies = variantGroup.ToArray();
                        if (copies.Length == 1 && headerOnly)
                            continue;
                        replacements.Add(copies[0].Declaration, MergeAliases(compilation, headerOnly ? copies : copies.Append(retained[0]).ToArray()));
                        foreach (var copy in copies.Skip(1))
                            replacements.Add(copy.Declaration, null);
                    }
                    if (!headerOnly)
                        replacements.Add(retained[0].Declaration, null);
                }
                else
                {
                    replacements.Add(first.Declaration, MergeAliases(compilation, aliases));
                    foreach (var alias in aliases.Skip(1))
                        replacements.Add(alias.Declaration, null);
                }
            }

            if (replacements.Count == 0)
                return compilation;
            var rewritten = compilation;
            var rewriter = new Rewriter(replacements);
            foreach (var tree in compilation.SyntaxTrees)
            {
                if (!replacements.Keys.Any(declaration => declaration.SyntaxTree == tree))
                    continue;
                var replacement = tree.WithRootAndOptions(rewriter.Visit(tree.GetRoot()), tree.Options);
                File.WriteAllText(tree.FilePath, replacement.GetText().ToString());
                rewritten = rewritten.ReplaceSyntaxTree(tree, replacement);
            }
            return rewritten;
        }

        private static StructDeclarationSyntax MergeAliases(CSharpCompilation compilation, Fragment[] aliases)
        {
            var first = aliases[0];
            // Keep the retained field encoding when header bindings spell void-pointer storage as IntPtr.
            var retained = aliases.FirstOrDefault(alias => IsAutoTypesFile(alias.Tree.FilePath));
            var storageOwner = retained ?? first;
            var valueType = GetValueType(storageOwner, compilation.GetSemanticModel(storageOwner.Tree));
            foreach (var alias in aliases)
            {
                var incomingType = GetValueType(alias, compilation.GetSemanticModel(alias.Tree));
                if (!SymbolEqualityComparer.Default.Equals(valueType, incomingType) &&
                    !(retained != null && IsEquivalentNativePointerStorage(valueType, incomingType)))
                    throw Error(alias, "Conflicting native typedef Value storage types.");
            }
            var attributesByType = first.Attributes.GroupBy(AttributeName, StringComparer.Ordinal)
                .ToDictionary(attributes => attributes.Key, attributes => attributes.ToArray(), StringComparer.Ordinal);
            var added = new List<AttributeListSyntax>();
            foreach (var alias in aliases.Skip(1))
            {
                foreach (var attributes in alias.Attributes.GroupBy(AttributeName, StringComparer.Ordinal))
                {
                    var incoming = attributes.ToArray();
                    if (attributesByType.TryGetValue(attributes.Key, out var existing))
                    {
                        if (!existing.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)
                            .SequenceEqual(incoming.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)))
                            throw Error(alias, $"Conflicting '{attributes.Key}' annotations.");
                    }
                    else
                    {
                        attributesByType.Add(attributes.Key, incoming);
                        added.AddRange(incoming.Select(ToAttributeList));
                    }
                }
            }
            var declaration = first.Declaration;
            if (storageOwner != first)
            {
                var field = (FieldDeclarationSyntax)declaration.Members.Single();
                declaration = declaration.ReplaceNode(field.Declaration.Type,
                    SyntaxFactory.ParseTypeName(valueType.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat))
                        .WithTriviaFrom(field.Declaration.Type));
            }
            return declaration.AddAttributeLists(added.ToArray());
        }

        private static bool IsEquivalentNativePointerStorage(ITypeSymbol left, ITypeSymbol right) =>
            IsVoidPointer(left) && right.SpecialType == SpecialType.System_IntPtr ||
            IsVoidPointer(right) && left.SpecialType == SpecialType.System_IntPtr;

        private static bool IsVoidPointer(ITypeSymbol type) =>
            type is IPointerTypeSymbol pointer && pointer.PointedAtType.SpecialType == SpecialType.System_Void;

        private static int GetArchitecture(Fragment fragment)
        {
            if (!HeaderEnumGroupMerger.IsHeaderTypesFile(fragment.Tree.FilePath))
                return 0;
            var architecture = fragment.Attributes.SingleOrDefault(attribute => AttributeName(attribute) == ArchitectureName);
            if (architecture == null)
                return 0;
            int mask = Convert.ToInt32(architecture.ConstructorArguments.Single().Value, System.Globalization.CultureInfo.InvariantCulture);
            if (mask <= 0 || (mask & ~(int)Architecture.All) != 0)
                throw Error(fragment, "Invalid supported architecture mask.");
            return mask;
        }

        private static string GetIdentity(Fragment fragment)
        {
            string name = fragment.Symbol.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
            int architecture = GetArchitecture(fragment);
            if (architecture == 0)
                return name;
            int suffix = name.LastIndexOf("____", StringComparison.Ordinal);
            if (suffix < 0)
                return name;
            // CrossArchTreeMerger suffixes are variant ordinals, not architecture masks.
            if (!int.TryParse(name.Substring(suffix + 4), System.Globalization.NumberStyles.None,
                System.Globalization.CultureInfo.InvariantCulture, out int ordinal) || ordinal <= 0)
                throw Error(fragment, "Invalid architecture-specific alias suffix.");
            return name.Substring(0, suffix);
        }

        private static ITypeSymbol GetValueType(Fragment fragment, SemanticModel model)
        {
            var declaration = fragment.Declaration;
            if (declaration.Parent is not BaseNamespaceDeclarationSyntax and not CompilationUnitSyntax ||
                !declaration.Modifiers.Any(SyntaxKind.PublicKeyword) ||
                declaration.Modifiers.Any(modifier => !modifier.IsKind(SyntaxKind.PublicKeyword) &&
                    !modifier.IsKind(SyntaxKind.PartialKeyword) && !modifier.IsKind(SyntaxKind.UnsafeKeyword)) ||
                declaration.TypeParameterList != null || declaration.BaseList != null ||
                declaration.Members.Count != 1 || declaration.Members[0] is not FieldDeclarationSyntax field ||
                field.Declaration.Variables.Count != 1 || field.Declaration.Variables[0].Identifier.ValueText != "Value" ||
                field.Declaration.Variables[0].Initializer != null || field.AttributeLists.Count != 0 ||
                !field.Modifiers.Any(SyntaxKind.PublicKeyword) || field.Modifiers.Any(modifier =>
                    modifier.IsKind(SyntaxKind.StaticKeyword) || modifier.IsKind(SyntaxKind.ConstKeyword) ||
                    modifier.IsKind(SyntaxKind.ReadOnlyKeyword) || modifier.IsKind(SyntaxKind.VolatileKeyword)) ||
                fragment.Attributes.Count(attribute => AttributeName(attribute) == NativeTypedefName) != 1)
                throw Error(fragment, "Expected a namespace-level native typedef wrapper containing one public instance Value field.");
            var type = model.GetTypeInfo(field.Declaration.Type).Type;
            if (type == null || type.TypeKind == TypeKind.Error || !type.IsUnmanagedType)
                throw Error(fragment, "Cannot resolve native typedef Value storage.");
            return type;
        }

        private static string AttributeName(AttributeData attribute) =>
            attribute.AttributeClass?.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat) ??
                throw new InvalidDataException("Cannot resolve a generated native typedef annotation.");

        private static AttributeListSyntax ToAttributeList(AttributeData attribute)
        {
            if (attribute.ConstructorArguments.Concat(attribute.NamedArguments.Select(argument => argument.Value))
                .Any(argument => argument.Kind == TypedConstantKind.Error))
                throw new InvalidDataException($"Cannot resolve arguments of '{AttributeName(attribute)}'.");
            var arguments = attribute.ConstructorArguments.Select(argument =>
                SyntaxFactory.AttributeArgument(SyntaxFactory.ParseExpression(argument.ToCSharpString())))
                .Concat(attribute.NamedArguments.Select(argument => SyntaxFactory.AttributeArgument(
                    SyntaxFactory.ParseExpression(argument.Value.ToCSharpString()))
                    .WithNameEquals(SyntaxFactory.NameEquals(argument.Key)))).ToArray();
            var syntax = SyntaxFactory.Attribute(SyntaxFactory.ParseName(AttributeName(attribute)));
            if (arguments.Length != 0)
                syntax = syntax.WithArgumentList(SyntaxFactory.AttributeArgumentList(SyntaxFactory.SeparatedList(arguments)));
            return SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(syntax));
        }

        private static string AttributeKey(AttributeData attribute) =>
            ToAttributeList(attribute).WithoutTrivia().NormalizeWhitespace().ToFullString();

        private static bool IsAutoTypesFile(string path) =>
            string.Equals(Path.GetFileName(path), "autotypes.modified.cs", StringComparison.OrdinalIgnoreCase);

        private static bool IsGeneratedAliasFile(string path) =>
            IsAutoTypesFile(path) || HeaderEnumGroupMerger.IsHeaderTypesFile(path);

        private static InvalidDataException Error(Fragment fragment, string message) => new(
            $"Header native typedef '{fragment.Symbol.ToDisplayString()}' in '{fragment.Tree.FilePath}': {message}");

        private sealed record Fragment(SyntaxTree Tree, StructDeclarationSyntax Declaration, INamedTypeSymbol Symbol, AttributeData[] Attributes);

        private sealed class Rewriter : CSharpSyntaxRewriter
        {
            private readonly Dictionary<StructDeclarationSyntax, StructDeclarationSyntax> replacements;

            internal Rewriter(Dictionary<StructDeclarationSyntax, StructDeclarationSyntax> replacements) => this.replacements = replacements;

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node) =>
                replacements.TryGetValue(node, out var replacement) ? replacement : base.VisitStructDeclaration(node);
        }
    }
}
