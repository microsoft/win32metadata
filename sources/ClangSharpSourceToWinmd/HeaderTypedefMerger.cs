using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.RegularExpressions;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    internal static class HeaderTypedefMerger
    {
        private const string NativeTypedefName = "global::Windows.Win32.Foundation.Metadata.NativeTypedefAttribute";
        private const string MetadataTypedefName = "global::Windows.Win32.Foundation.Metadata.MetadataTypedefAttribute";
        private const string NativeTypeNameName = "global::Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute";
        private const string ConstName = "global::Windows.Win32.Foundation.Metadata.ConstAttribute";
        private const string NotNullTerminatedName = "global::Windows.Win32.Foundation.Metadata.NotNullTerminatedAttribute";
        private const string NullNullTerminatedName = "global::Windows.Win32.Foundation.Metadata.NullNullTerminatedAttribute";
        private const string DocumentationName = "global::Windows.Win32.Foundation.Metadata.DocumentationAttribute";
        private const string InvalidHandleValueName = "global::Windows.Win32.Foundation.Metadata.InvalidHandleValueAttribute";
        private const string RaiiFreeName = "global::Windows.Win32.Foundation.Metadata.RAIIFreeAttribute";
        private const string ArchitectureName = "global::Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute";
        private static readonly SyntaxAnnotation ComposedHeaderAlias = new SyntaxAnnotation();
        private static readonly SyntaxAnnotation ComposedNativeCharacterProjection = new SyntaxAnnotation();

        internal static Dictionary<string, NativeProjectionOwner> FindNativeProjectionOwners(
            IEnumerable<SyntaxTree> trees, IEnumerable<StructDeclarationSyntax> declarations,
            IReadOnlyDictionary<string, string> requiredNamespaces, GenerationValidation validation)
        {
            var sourceTrees = trees.ToArray();
            var retainedNames = sourceTrees.Where(tree => IsAutoTypesFile(tree.FilePath))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                .Select(declaration => declaration.Identifier.ValueText)
                .Concat(sourceTrees.Where(tree => MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath) ||
                    tree.FilePath.EndsWith(".enums.modified.cs", StringComparison.OrdinalIgnoreCase))
                    .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                    .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                    .Select(declaration => declaration.Identifier.ValueText)).ToHashSet(StringComparer.Ordinal);
            var aliases = new List<(StructDeclarationSyntax Declaration, NativeRecordSource Source,
                (string Identity, string Header, string Name) Family, bool? Inferred,
                bool Configured, string Cleanup, bool NativeHandle, bool CompatibleType)>();
            foreach (var declaration in declarations)
            {
                try
                {
                    var source = NativeTypedefSourceProvenance.Read(declaration);
                    if (source == null)
                        continue;
                    aliases.Add((declaration, source, ProjectionFamily(source),
                        NativeTypedefProjectionProvenance.IsInferred(declaration),
                        NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration),
                        CleanupApi(declaration), NativeHandleSourceProvenance.TryRead(declaration, out _),
                        declaration.AttributeLists.SelectMany(list => list.Attributes).Any(attribute =>
                                attribute.Name.ToString() is "global::Windows.Win32.Foundation.Metadata.AlsoUsableFor" or
                                    "global::Windows.Win32.Foundation.Metadata.AlsoUsableForAttribute")));
                }
                catch (InvalidDataException error)
                {
                    validation.Add(error, "CSSW005", "emitter.record-ownership", declaration.SyntaxTree.FilePath,
                        declaration.Identifier.ValueText);
                }
            }
            var witnesses = aliases.Where(alias => alias.Configured && alias.Source.NativeName != alias.Source.Name)
                .Select(alias => (alias.Declaration.SyntaxTree, alias.Source.Name, alias.Source.SourceArchitecture,
                    alias.Source.Size, alias.Source.Alignment)).ToHashSet();
            var byFamily = aliases.GroupBy(alias => alias.Family).ToDictionary(group => group.Key, group => group.ToArray());
            var candidates = aliases.Where(alias => !retainedNames.Contains(alias.Source.Name) &&
                alias.Source.NativeName == alias.Source.Name &&
                (alias.Inferred == false && (alias.Configured || alias.Cleanup != null || alias.NativeHandle || alias.CompatibleType) ||
                    witnesses.Contains((alias.Declaration.SyntaxTree, alias.Source.NativeName,
                        alias.Source.SourceArchitecture, alias.Source.Size, alias.Source.Alignment))))
                .GroupBy(alias => alias.Source.Name, StringComparer.Ordinal).ToArray();
            var cleanupNames = candidates.SelectMany(group => group.Select(alias => alias.Cleanup))
                .Where(name => name != null).ToHashSet(StringComparer.Ordinal);
            var cleanupOwners = (cleanupNames.Count == 0 ? Array.Empty<MethodDeclarationSyntax>() :
                sourceTrees.SelectMany(tree => tree.GetRoot().DescendantNodes(node =>
                    node is CompilationUnitSyntax or BaseNamespaceDeclarationSyntax or TypeDeclarationSyntax))
                .OfType<MethodDeclarationSyntax>().Where(method => cleanupNames.Contains(method.Identifier.ValueText) &&
                    method.Modifiers.Any(SyntaxKind.StaticKeyword) && method.Modifiers.Any(SyntaxKind.ExternKeyword)))
                .GroupBy(method => method.Identifier.ValueText, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.Select(SyntaxUtils.GetEnclosingNamespace)
                    .Distinct(StringComparer.Ordinal).ToArray(), StringComparer.Ordinal);
            var result = new Dictionary<string, NativeProjectionOwner>(StringComparer.Ordinal);
            foreach (var candidate in candidates)
            {
                var families = candidate.Select(alias => alias.Family).ToHashSet();
                var providers = families.SelectMany(family => byFamily[family]).ToArray();
                if (providers.GroupBy(alias => alias.Declaration.SyntaxTree).Any(input =>
                    input.Select(alias => alias.Family).Distinct().Skip(1).Any()))
                    continue;
                var cleanups = providers.Select(alias => alias.Cleanup)
                    .Where(name => name != null).Distinct(StringComparer.Ordinal).ToArray();
                if (cleanups.Length > 1)
                    continue;
                string owner = requiredNamespaces != null && requiredNamespaces.TryGetValue(candidate.Key, out string configured)
                    ? configured : null;
                if (cleanups.Length == 1)
                {
                    if (!cleanupOwners.TryGetValue(cleanups[0], out var namespaces) || namespaces.Length != 1)
                        continue;
                    owner ??= requiredNamespaces != null && requiredNamespaces.TryGetValue(cleanups[0], out string cleanupOwner)
                        ? cleanupOwner : namespaces[0];
                }
                var direct = providers.Where(alias => alias.Source.TraversedHeader).Select(alias => alias.Source.Namespace)
                    .Distinct(StringComparer.Ordinal).ToArray();
                var observed = providers.Select(alias => alias.Source.Namespace).Distinct(StringComparer.Ordinal).ToArray();
                owner ??= direct.Length == 1 ? direct[0] : observed.Length == 1 ? observed[0] : null;
                if (owner == null)
                    continue;
                result.Add(candidate.Key, new NativeProjectionOwner(owner,
                    providers.Select(alias => alias.Declaration).ToArray(), cleanups.Length == 1 ||
                        providers.Any(alias => alias.CompatibleType)));
            }
            return result;
        }

        private static (string Identity, string Header, string Name) ProjectionFamily(NativeRecordSource source) =>
            (NativeRecordSourceProvenance.GetIdentityKey(source), source.Header.ToUpperInvariant(), source.Name);

        private static string CleanupApi(StructDeclarationSyntax declaration)
        {
            var attributes = declaration.AttributeLists.SelectMany(list => list.Attributes).Where(attribute =>
                attribute.Name.ToString() is "global::Windows.Win32.Foundation.Metadata.RAIIFree" or
                    "global::Windows.Win32.Foundation.Metadata.RAIIFreeAttribute").ToArray();
            if (attributes.Length == 0)
                return null;
            if (attributes.Length != 1 || attributes[0].ArgumentList?.Arguments.Count != 1 ||
                attributes[0].ArgumentList.Arguments[0].Expression is not LiteralExpressionSyntax literal ||
                !literal.IsKind(SyntaxKind.StringLiteralExpression) || string.IsNullOrEmpty(literal.Token.ValueText))
                throw new InvalidDataException("A native cleanup owner requires one literal cleanup API.");
            return literal.Token.ValueText;
        }

        internal sealed class NativeProjectionOwner
        {
            internal NativeProjectionOwner(string ns, StructDeclarationSyntax[] providers,
                bool intentionalHandle)
            {
                Namespace = ns;
                Providers = providers;
                IntentionalHandle = intentionalHandle;
                ConfiguredTarget = providers.Any(NativeTypedefProjectionProvenance.HasConfiguredNominalBinding);
                Families = providers.Select(provider => ProjectionFamily(NativeTypedefSourceProvenance.Read(provider)))
                    .ToHashSet();
                Name = Families.First().Name;
            }

            internal string Namespace { get; }
            internal StructDeclarationSyntax[] Providers { get; }
            private bool IntentionalHandle { get; }
            private bool ConfiguredTarget { get; }
            private string Name { get; }
            private HashSet<(string Identity, string Header, string Name)> Families { get; }

            internal bool IsTarget(StructDeclarationSyntax declaration) =>
                NativeTypedefSourceProvenance.Read(declaration) is { } source &&
                    Families.Contains(ProjectionFamily(source));

            internal bool Authorizes(StructDeclarationSyntax declaration)
            {
                var source = NativeTypedefSourceProvenance.Read(declaration);
                return source != null && (IsTarget(declaration) ||
                    NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(declaration) &&
                        source.NativeName != source.Name && source.Name == Name &&
                        (ConfiguredTarget || Providers.Any(provider => provider.SyntaxTree == declaration.SyntaxTree)) ||
                    IntentionalHandle && source.NativeName == Name &&
                        NativeTypedefProjectionProvenance.IsInferred(declaration) == true);
            }
        }

        internal static CSharpCompilation LowerConstants(CSharpCompilation compilation, bool writeModifiedFiles = true)
        {
            var validation = new GenerationValidation();
            var result = LowerConstantsWithDiagnostics(compilation, writeModifiedFiles, validation);
            validation.ThrowIfAny();
            return result;
        }

        internal static CSharpCompilation LowerConstantsWithDiagnostics(CSharpCompilation compilation,
            bool writeModifiedFiles, GenerationValidation validation, bool canonicalContracts = false,
            IReadOnlyDictionary<string, string> requiredNamespaces = null)
        {
            int previousErrors = validation.Errors.Count;
            var storageTypes = new Dictionary<ITypeSymbol, ITypeSymbol>(SymbolEqualityComparer.Default);
            Dictionary<string, NativeProjectionOwner> nativeOwners = null;
            var rewritten = compilation;
            foreach (var tree in compilation.SyntaxTrees)
            {
                var model = compilation.GetSemanticModel(tree);
                var replacements = new Dictionary<TypeSyntax, TypeSyntax>();
                var enumStorageTypes = new Dictionary<EnumMemberDeclarationSyntax, ITypeSymbol>();
                foreach (var field in tree.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>()
                    .Where(field => field.Modifiers.Any(SyntaxKind.ConstKeyword)))
                {
                    try
                    {
                    var storage = GetStorage(field.Declaration.Type);
                    if (storage != null)
                    {
                        var symbol = model.GetDeclaredSymbol(field.Declaration.Variables.First());
                        if (!symbol.GetAttributes().Any(attribute => attribute.AttributeClass?.Name == "NativeTypeNameAttribute"))
                            throw new InvalidDataException($"Header native typedef constant '{symbol.ToDisplayString()}' " +
                                "requires NativeTypeName to preserve its declared metadata type.");
                        replacements.Add(field.Declaration.Type, StorageSyntax(storage, field.Declaration.Type));
                    }
                    foreach (var variable in field.Declaration.Variables)
                        LowerCasts(variable.Initializer?.Value);
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-constant-lowering", tree.FilePath,
                            string.Join(", ", field.Declaration.Variables.Select(variable => variable.Identifier.ValueText)),
                            line: field.GetLocation().GetLineSpan().StartLinePosition.Line + 1,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
                foreach (var member in tree.GetRoot().DescendantNodes().OfType<EnumMemberDeclarationSyntax>())
                {
                    try
                    {
                        var expression = member.EqualsValue?.Value;
                        if (LowerCasts(expression) && member.Parent is EnumDeclarationSyntax declaration)
                        {
                            var storage = declaration.BaseList?.Types.Count == 1
                                ? GetStorage(declaration.BaseList.Types[0].Type) ??
                                    model.GetTypeInfo(declaration.BaseList.Types[0].Type).Type
                                : compilation.GetSpecialType(SpecialType.System_Int32);
                            if (storage != null && IntegerWidth(storage.SpecialType) != 0 &&
                                model.GetTypeInfo(expression).Type?.SpecialType != storage.SpecialType)
                                enumStorageTypes.Add(member, storage);
                        }
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-constant-lowering", tree.FilePath,
                            member.Identifier.ValueText,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Where(declaration => declaration.BaseList?.Types.Count == 1))
                {
                    try
                    {
                        var type = declaration.BaseList.Types.Single().Type;
                        var storage = GetStorage(type);
                        if (storage != null)
                            replacements.Add(type, StorageSyntax(storage, type));
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-constant-lowering", tree.FilePath,
                            declaration.Identifier.ValueText,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
                if (replacements.Count == 0)
                    continue;
                var replacement = tree.WithRootAndOptions(tree.GetRoot().ReplaceNodes(
                    replacements.Keys.Cast<SyntaxNode>().Concat(enumStorageTypes.Keys),
                    (original, updated) =>
                    {
                        if (original is TypeSyntax type)
                            return replacements[type];
                        var member = (EnumMemberDeclarationSyntax)updated;
                        return member.WithEqualsValue(member.EqualsValue.WithValue(ConvertEnumInitializer(
                            member.EqualsValue.Value, StorageSyntax(enumStorageTypes[(EnumMemberDeclarationSyntax)original],
                                SyntaxFactory.PredefinedType(SyntaxFactory.Token(SyntaxKind.IntKeyword))))));
                    }), tree.Options);
                rewritten = rewritten.ReplaceSyntaxTree(tree, replacement);

                bool LowerCasts(ExpressionSyntax expression)
                {
                    if (expression == null)
                        return false;
                    bool lowered = false;
                    foreach (var cast in expression.DescendantNodesAndSelf().OfType<CastExpressionSyntax>())
                    {
                        var storage = GetStorage(cast.Type);
                        if (storage != null)
                        {
                            replacements.Add(cast.Type, StorageSyntax(storage, cast.Type));
                            lowered = true;
                        }
                    }
                    return lowered;
                }

                ITypeSymbol GetStorage(TypeSyntax syntax)
                {
                    if (model.GetTypeInfo(syntax).Type is not INamedTypeSymbol type || type.TypeKind != TypeKind.Struct ||
                        !type.GetAttributes().Any(attribute => AttributeName(attribute) == NativeTypedefName))
                        return null;
                    if (storageTypes.TryGetValue(type, out var cached))
                        return cached;
                    var declarations = type.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                        .OfType<StructDeclarationSyntax>().ToArray();
                    if (!declarations.Any(declaration => HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath) ||
                        declaration.HasAnnotation(ComposedHeaderAlias)))
                        return null;
                    ITypeSymbol valueType = null;
                    var fragments = declarations.Select(declaration =>
                    {
                        var attributes = type.GetAttributes().Where(attribute =>
                            attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                            declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                        return new Fragment(declaration.SyntaxTree, declaration, type, attributes,
                            compilation.GetSemanticModel(declaration.SyntaxTree));
                    }).ToArray();
                    foreach (var fragment in canonicalContracts ? SelectConstantProviders(fragments) : fragments)
                    {
                        var incoming = GetHeaderBackingStorage(compilation,
                            GetValueType(fragment, fragment.Model),
                            new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default),
                            selectProviders: canonicalContracts ? SelectConstantProviders : null);
                        if (valueType != null && !SymbolEqualityComparer.Default.Equals(valueType, incoming))
                            throw Error(fragment, "Conflicting native typedef constant storage types.");
                        valueType = incoming;
                    }
                    if (valueType?.SpecialType is not (SpecialType.System_SByte or SpecialType.System_Byte or
                        SpecialType.System_Int16 or SpecialType.System_UInt16 or SpecialType.System_Char or
                        SpecialType.System_Int32 or SpecialType.System_UInt32 or
                        SpecialType.System_Int64 or SpecialType.System_UInt64))
                        valueType = null;
                    storageTypes.Add(type, valueType);
                    return valueType;
                }
            }
            if (validation.Errors.Count != previousErrors)
                return compilation;
            if (writeModifiedFiles)
                foreach (var tree in rewritten.SyntaxTrees.Where(tree => !compilation.SyntaxTrees.Contains(tree)))
                    File.WriteAllText(tree.FilePath, tree.GetText().ToString());
            return rewritten;

            IEnumerable<Fragment> SelectConstantProviders(Fragment[] aliases)
            {
                if (aliases.Length < 2)
                    return aliases;
                bool retained = aliases.Any(alias => IsAutoTypesFile(alias.Tree.FilePath));
                NativeProjectionOwner owner = null;
                if (!retained && aliases.Any(alias => NativeTypedefSourceProvenance.Read(alias.Declaration) != null))
                {
                    nativeOwners ??= FindNativeProjectionOwners(compilation.SyntaxTrees,
                        compilation.SyntaxTrees.Where(tree => HeaderEnumGroupMerger.IsHeaderTypesFile(tree.FilePath))
                            .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>()),
                        requiredNamespaces, validation);
                    owner = GetNativeProjectionOwner(aliases, nativeOwners);
                }
                // This is a read-only constant view; full composition validates and reports every candidate.
                return retained || owner != null ? OrderProviders(compilation, aliases, owner).Take(1) : aliases;
            }
        }

        private static TypeSyntax StorageSyntax(ITypeSymbol storage, TypeSyntax original) =>
            SyntaxFactory.ParseTypeName(storage.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)).WithTriviaFrom(original);

        private static ExpressionSyntax ConvertEnumInitializer(ExpressionSyntax expression, TypeSyntax storage)
        {
            if (expression is ParenthesizedExpressionSyntax parentheses)
                return parentheses.WithExpression(ConvertEnumInitializer(parentheses.Expression, storage));
            if (expression is CheckedExpressionSyntax context)
                return context.WithExpression(ConvertEnumInitializer(context.Expression, storage));
            return SyntaxFactory.CastExpression(storage,
                SyntaxFactory.ParenthesizedExpression(expression.WithoutTrivia())).WithTriviaFrom(expression);
        }

        internal static CSharpCompilation Merge(CSharpCompilation compilation)
        {
            var validation = new GenerationValidation();
            var result = MergeWithDiagnostics(compilation, validation);
            validation.ThrowIfAny();
            return result;
        }

        internal static CSharpCompilation MergeWithDiagnostics(CSharpCompilation compilation, GenerationValidation validation,
            IReadOnlyDictionary<string, string> requiredNamespaces = null,
            IReadOnlyDictionary<string, string> recordFamilies = null,
            IReadOnlyDictionary<string, string> remaps = null, bool writeModifiedFiles = true)
            => MergeCore(compilation, validation, requiredNamespaces, recordFamilies, remaps, writeModifiedFiles,
                enumProjectionsOnly: false);

        internal static CSharpCompilation BindLegacyEnumProjectionsForComparison(CSharpCompilation compilation,
            GenerationValidation validation, IReadOnlyDictionary<string, string> requiredNamespaces,
            IReadOnlyDictionary<string, string> remaps)
            => MergeCore(compilation, validation, requiredNamespaces, null, remaps, writeModifiedFiles: false,
                enumProjectionsOnly: true);

        private static CSharpCompilation MergeCore(CSharpCompilation compilation, GenerationValidation validation,
            IReadOnlyDictionary<string, string> requiredNamespaces, IReadOnlyDictionary<string, string> recordFamilies,
            IReadOnlyDictionary<string, string> remaps, bool writeModifiedFiles, bool enumProjectionsOnly)
        {
            int previousErrors = validation.BlockingErrorCount;
            var fragments = ReadFragments(compilation, validation);
            var projections = FindLegacyEnumProjections(compilation, fragments, requiredNamespaces, remaps);
            if (projections.Count == 0)
                return enumProjectionsOnly ? compilation :
                    MergeNativeAliases(compilation, fragments, validation, requiredNamespaces, recordFamilies,
                        writeModifiedFiles: writeModifiedFiles);

            // Validate native providers against their original bindings, not the metadata enum's backing type.
            var nativeCompilation = compilation;
            var enumTrees = new Dictionary<SyntaxTree, SyntaxTree>();
            foreach (var group in projections.Values.GroupBy(projection => projection.Declaration.SyntaxTree))
            {
                var tree = group.Key;
                var replacement = tree.WithRootAndOptions(tree.GetRoot().RemoveNodes(
                    group.Select(projection => projection.Declaration), SyntaxRemoveOptions.KeepNoTrivia), tree.Options);
                enumTrees.Add(tree, replacement);
                nativeCompilation = nativeCompilation.ReplaceSyntaxTree(tree, replacement);
            }
            fragments = ReadFragments(nativeCompilation, validation);
            foreach (var fragment in fragments.Where(fragment => projections.ContainsKey(GetIdentity(fragment))))
            {
                try
                {
                    var projection = projections[GetIdentity(fragment)];
                    var storage = GetHeaderBackingStorage(nativeCompilation,
                        GetValueType(fragment, fragment.Model),
                        new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
                    var metadataStorage = projection.Symbol.EnumUnderlyingType.SpecialType;
                    int nativeWidth = IntegerWidth(storage.SpecialType);
                    if (nativeWidth == 0 || nativeWidth != IntegerWidth(metadataStorage) ||
                        storage.SpecialType != metadataStorage && !projection.HasExplicitProjection)
                        throw Error(fragment, "A legacy enum requires exact native integer storage or an independently bound explicit metadata projection with unchanged ABI size.");
                    if (fragment.Attributes.Any(attribute => AttributeName(attribute) is not
                        (NativeTypedefName or ArchitectureName or DocumentationName)) ||
                        GetFieldAttributes(fragment, fragment.Model)
                            .Any(attribute => AttributeName(attribute) != NativeTypeNameName) ||
                        fragment.Attributes.Where(attribute => AttributeName(attribute) == DocumentationName)
                            .Any(attribute => !projection.Symbol.GetAttributes().Any(owner =>
                                AttributeKey(owner) == AttributeKey(attribute))))
                        throw Error(fragment, "A legacy enum projection cannot discard native typedef annotations.");
                }
                catch (InvalidDataException error)
                {
                    validation.Add(error, "CSSW005", "emitter.typedef-enum-projection", fragment.Tree.FilePath,
                        fragment.Symbol.ToDisplayString(),
                        architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(fragment.Tree.FilePath).ToString());
                }
            }
            if (validation.BlockingErrorCount != previousErrors)
                return compilation;
            var rewritten = enumProjectionsOnly ? nativeCompilation :
                MergeNativeAliases(nativeCompilation, fragments, validation, requiredNamespaces, recordFamilies,
                    projections.Keys.ToHashSet(StringComparer.Ordinal), writeModifiedFiles);
            if (validation.BlockingErrorCount != previousErrors)
                return compilation;

            var removals = ReadFragments(rewritten, validation)
                .Where(fragment => projections.ContainsKey(GetIdentity(fragment))).Select(fragment => fragment.Declaration).ToArray();
            foreach (var pair in enumTrees)
                rewritten = rewritten.ReplaceSyntaxTree(pair.Value, pair.Key);
            var rewriter = new Rewriter(removals.ToDictionary(declaration => declaration,
                _ => (StructDeclarationSyntax)null));
            foreach (var tree in rewritten.SyntaxTrees.Where(tree => removals.Any(declaration => declaration.SyntaxTree == tree)).ToArray())
            {
                var replacement = tree.WithRootAndOptions(rewriter.Visit(tree.GetRoot()), tree.Options);
                if (writeModifiedFiles)
                    File.WriteAllText(tree.FilePath, replacement.GetText().ToString());
                rewritten = rewritten.ReplaceSyntaxTree(tree, replacement);
            }
            return rewritten;
        }

        private static Dictionary<string, EnumProjection> FindLegacyEnumProjections(CSharpCompilation compilation,
            List<Fragment> fragments, IReadOnlyDictionary<string, string> requiredNamespaces,
            IReadOnlyDictionary<string, string> remaps)
        {
            var aliases = fragments.GroupBy(GetIdentity, StringComparer.Ordinal).Where(group =>
                group.All(fragment => HeaderEnumGroupMerger.IsHeaderTypesFile(fragment.Tree.FilePath)))
                .ToDictionary(group => group.Key, group => group.ToArray(), StringComparer.Ordinal);
            var candidates = compilation.SyntaxTrees.Where(tree =>
                MetadataSyntaxTreeCleaner.IsLegacyManualSource(tree.FilePath) ||
                tree.FilePath.EndsWith(".enums.modified.cs", StringComparison.OrdinalIgnoreCase) ||
                HeaderEnumGroupMerger.IsHeaderEnumSourceFile(tree.FilePath))
                .SelectMany(tree => tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                .Where(declaration => declaration.Parent is BaseNamespaceDeclarationSyntax or CompilationUnitSyntax)
                .Select(declaration => new EnumProjection(declaration,
                    (INamedTypeSymbol)compilation.GetSemanticModel(declaration.SyntaxTree).GetDeclaredSymbol(declaration)))
                .Where(projection => projection.Symbol?.EnumUnderlyingType != null &&
                    aliases.ContainsKey(projection.Identity) &&
                    (requiredNamespaces == null ||
                        !requiredNamespaces.TryGetValue(projection.Symbol.Name, out string owner) ||
                        owner == projection.Symbol.ContainingNamespace.ToDisplayString()))
                .GroupBy(projection => projection.Identity, StringComparer.Ordinal).Where(group => group.Count() == 1)
                .ToDictionary(group => group.Key, group => group.Single(), StringComparer.Ordinal);
            if (candidates.Count == 0)
                return candidates;

            var metadataCompilation = compilation;
            foreach (var group in candidates.Keys.SelectMany(identity => aliases[identity])
                .GroupBy(fragment => fragment.Tree))
                metadataCompilation = metadataCompilation.ReplaceSyntaxTree(group.Key,
                    group.Key.WithRootAndOptions(group.Key.GetRoot().RemoveNodes(
                        group.Select(fragment => fragment.Declaration), SyntaxRemoveOptions.KeepNoTrivia), group.Key.Options));
            var names = candidates.Values.Select(projection => projection.Symbol.Name).ToHashSet(StringComparer.Ordinal);
            foreach (var tree in metadataCompilation.SyntaxTrees.Where(tree => !IsGeneratedAliasFile(tree.FilePath)))
            {
                var model = metadataCompilation.GetSemanticModel(tree);
                foreach (var node in tree.GetRoot().DescendantNodes())
                {
                    (TypeSyntax Type, string Key) use = node switch
                    {
                        FieldDeclarationSyntax field => (field.Declaration.Type, SyntaxUtils.GetFullName(field)),
                        ParameterSyntax parameter => (parameter.Type, SyntaxUtils.GetFullName(parameter)),
                        MethodDeclarationSyntax method => (method.ReturnType, SyntaxUtils.GetFullName(method) + "::return"),
                        DelegateDeclarationSyntax callback => (callback.ReturnType, SyntaxUtils.GetFullName(callback) + "::return"),
                        _ => (null, null),
                    };
                    if (use.Type == null || !use.Type.DescendantNodesAndSelf().OfType<IdentifierNameSyntax>()
                        .Any(identifier => names.Contains(identifier.Identifier.ValueText)))
                        continue;
                    var type = ReferencedType(model.GetTypeInfo(use.Type).Type);
                    if (type?.TypeKind != TypeKind.Enum ||
                        !candidates.TryGetValue(type.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat), out var projection) ||
                        type.DeclaringSyntaxReferences.Length != 1)
                        continue;
                    projection.HasUse = true;
                    if (use.Key != null && remaps?.TryGetValue(use.Key, out string target) == true)
                    {
                        var targetType = SyntaxFactory.ParseTypeName(target);
                        if (!targetType.ContainsDiagnostics && SymbolEqualityComparer.Default.Equals(type,
                            ReferencedType(model.GetSpeculativeTypeInfo(use.Type.SpanStart, targetType,
                                SpeculativeBindingOption.BindAsTypeOrNamespace).Type)))
                            projection.HasExplicitProjection = true;
                    }
                }
            }
            return candidates.Where(pair => pair.Value.HasUse).ToDictionary(pair => pair.Key, pair => pair.Value, StringComparer.Ordinal);
        }

        private static ITypeSymbol ReferencedType(ITypeSymbol type) => type switch
        {
            IPointerTypeSymbol pointer => ReferencedType(pointer.PointedAtType),
            IArrayTypeSymbol array => ReferencedType(array.ElementType),
            _ => type,
        };

        private static int IntegerWidth(SpecialType type) => type switch
        {
            SpecialType.System_SByte or SpecialType.System_Byte => 8,
            SpecialType.System_Int16 or SpecialType.System_UInt16 or SpecialType.System_Char => 16,
            SpecialType.System_Int32 or SpecialType.System_UInt32 => 32,
            SpecialType.System_Int64 or SpecialType.System_UInt64 => 64,
            _ => 0,
        };

        private static List<Fragment> ReadFragments(CSharpCompilation compilation, GenerationValidation validation)
        {
            var fragments = new List<Fragment>();
            foreach (var tree in compilation.SyntaxTrees.Where(tree => IsGeneratedAliasFile(tree.FilePath)))
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                {
                    try
                    {
                    if (model.GetDeclaredSymbol(declaration) is not INamedTypeSymbol symbol)
                        continue;
                    var attributes = symbol.GetAttributes().Where(attribute =>
                        attribute.ApplicationSyntaxReference?.SyntaxTree == tree &&
                        declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                    if (!attributes.Any(attribute => AttributeName(attribute) == NativeTypedefName ||
                        IsAutoTypesFile(tree.FilePath) && AttributeName(attribute) == MetadataTypedefName))
                        continue;
                    fragments.Add(new Fragment(tree, declaration, symbol, attributes, model));
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-input", tree.FilePath,
                            declaration.Identifier.ValueText,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
            }
            return fragments;
        }

        private static CSharpCompilation MergeNativeAliases(CSharpCompilation compilation, List<Fragment> fragments,
            GenerationValidation validation, IReadOnlyDictionary<string, string> requiredNamespaces,
            IReadOnlyDictionary<string, string> recordFamilies, IReadOnlySet<string> retainedEnumProjections = null,
            bool writeModifiedFiles = true)
        {
            int previousErrors = validation.BlockingErrorCount;
            var replacements = new Dictionary<StructDeclarationSyntax, StructDeclarationSyntax>();
            var nativeOwners = FindNativeProjectionOwners(compilation.SyntaxTrees,
                fragments.Select(fragment => fragment.Declaration), requiredNamespaces, validation);
            foreach (var group in fragments.GroupBy(GetIdentity,
                StringComparer.Ordinal).Where(group => group.Any(fragment => HeaderEnumGroupMerger.IsHeaderTypesFile(fragment.Tree.FilePath))))
            {
                var nativeOwner = GetNativeProjectionOwner(group.ToArray(), nativeOwners);
                var aliases = OrderProviders(compilation, group, nativeOwner);
                var first = aliases[0];
                bool recoverConflicts = nativeOwner != null || aliases.Any(alias => IsAutoTypesFile(alias.Tree.FilePath));
                try
                {
                var sources = aliases.Select(alias => (Source: NativeTypedefSourceProvenance.Read(alias.Declaration),
                    Architectures: (Architecture)GetArchitecture(alias)));
                bool retainedProjection = HasRoutedRetainedOwner(aliases, requiredNamespaces) ||
                    retainedEnumProjections?.Contains(group.Key) == true || nativeOwner != null;
                bool intrinsicProjection = aliases.All(alias =>
                    NativeTypedefSourceProvenance.Read(alias.Declaration) != null &&
                    NativeTypedefProjectionProvenance.IsInferred(alias.Declaration) == true) &&
                    aliases.Select(alias => ProjectionFamily(NativeTypedefSourceProvenance.Read(alias.Declaration)))
                        .Distinct().Skip(1).Any();
                bool conflictingSources = retainedProjection || intrinsicProjection
                    ? sources.GroupBy(source => (Identity: NativeRecordSourceProvenance.GetIdentityKey(source.Source),
                        Header: source.Source?.Header.ToUpperInvariant()))
                        .Any(ClangSharpSourceCompilation.HasConflictingNativeDeclarations)
                    : ClangSharpSourceCompilation.HasConflictingNativeDeclarations(sources);
                if (conflictingSources)
                    throw Error(first, "Conflicting native typedef declaration identities.");
                if (aliases.Any(alias => alias.Symbol.DeclaringSyntaxReferences.Any(reference => !aliases.Any(fragment =>
                    fragment.Tree == reference.SyntaxTree && fragment.Declaration.Span == reference.Span))))
                    throw Error(first, "A header alias overlaps a declaration outside generated header-types/autotypes inputs.");
                if (aliases.Length < 2 && nativeOwner == null)
                    continue;
                if (intrinsicProjection || nativeOwner != null)
                {
                    foreach (var alias in aliases)
                    {
                        var storage = GetHeaderBackingStorage(compilation,
                            GetValueType(alias, alias.Model),
                            new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default), recordFamilies);
                        if (!NativeStorageMatches(NativeTypedefSourceProvenance.Read(alias.Declaration), storage) ||
                            intrinsicProjection && (alias.Attributes.Any(attribute => AttributeName(attribute) is not
                                (NativeTypedefName or ArchitectureName or DocumentationName)) ||
                            GetFieldAttributes(alias, alias.Model)
                                .Any(attribute => AttributeName(attribute) != NativeTypeNameName)))
                            throw Error(alias, "Independent native projections require source-proven intrinsic storage and compatible nominal intent.");
                    }
                }
                var nativeCharacterTarget = nativeOwner == null || aliases.Any(alias => IsAutoTypesFile(alias.Tree.FilePath))
                    ? null : aliases.FirstOrDefault(alias => nativeOwner.IsTarget(alias.Declaration));
                var nativeCharacterStorage = nativeCharacterTarget == null ? null :
                    GetNativeCharacterPointerProjection(compilation, nativeCharacterTarget);
                if (aliases.Length < 2 && nativeCharacterStorage == null)
                    continue;
                if (aliases.GroupBy(alias => (alias.Tree, alias.Symbol.Name)).Any(declarations => declarations.Count() != 1) &&
                    !retainedProjection && !intrinsicProjection)
                    throw Error(first, "Multiple native aliases in one input project to the same type.");

                var variants = aliases.Where(alias => GetArchitecture(alias) != 0).ToArray();
                if (variants.Length != 0)
                {
                    var retained = aliases.Where(alias => IsAutoTypesFile(alias.Tree.FilePath) && GetArchitecture(alias) == 0).ToArray();
                    var commonHeaders = aliases.Where(alias => HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath) &&
                        GetArchitecture(alias) == 0).ToArray();
                    bool headerOnly = retained.Length == 0;
                    bool complete = variants.Aggregate(0, (mask, alias) => mask | GetArchitecture(alias)) == (int)Architecture.All;
                    var commonHeader = headerOnly ? commonHeaders.FirstOrDefault(common =>
                        CanKeepCommonHeaderCoverage(compilation, aliases, common)) : null;
                    if (commonHeader != null)
                    {
                        var copies = new[] { commonHeader }.Concat(aliases.Where(alias => alias != commonHeader)).ToArray();
                        replacements.Add(commonHeader.Declaration,
                            MergeAliases(compilation, copies, aliases, preserveRetainedCoverage: true,
                                nativeCharacterStorage: nativeCharacterStorage, validation: validation,
                                recoverConflicts: recoverConflicts));
                        foreach (var copy in copies.Skip(1))
                            replacements.Add(copy.Declaration, null);
                        continue;
                    }
                    if (!headerOnly && retained.Length == 1 && commonHeaders.Length == 0 &&
                        CanKeepCommonAliasCoverage(compilation, aliases, retained[0]))
                    {
                        replacements.Add(retained[0].Declaration,
                            MergeAliases(compilation, aliases, aliases, preserveRetainedCoverage: true,
                                nativeCharacterStorage: nativeCharacterStorage, validation: validation,
                                recoverConflicts: recoverConflicts));
                        foreach (var variant in variants)
                            replacements.Add(variant.Declaration, null);
                        continue;
                    }
                    if ((!headerOnly && (retained.Length != 1 || aliases.Length != variants.Length + 1 || !complete)) ||
                        headerOnly && commonHeaders.Length != 0 && !complete)
                        throw Error(first, "Architecture-specific aliases require one retained wrapper and complete x86/x64/arm64 coverage.");
                    foreach (var variantGroup in variants.GroupBy(alias => alias.Symbol.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)))
                    {
                        var copies = variantGroup.ToArray();
                        if (copies.Length == 1 && headerOnly && commonHeaders.Length == 0 && nativeCharacterStorage == null)
                            continue;
                        replacements.Add(copies[0].Declaration, MergeAliases(compilation,
                            headerOnly ? copies.Concat(commonHeaders).ToArray() : copies.Append(retained[0]).ToArray(),
                            aliases, compareArchitectureFamilies: headerOnly && commonHeaders.Length != 0,
                            recordFamilies: recordFamilies, nativeCharacterStorage: nativeCharacterStorage,
                            validation: validation, recoverConflicts: recoverConflicts));
                        foreach (var copy in copies.Skip(1))
                            replacements.Add(copy.Declaration, null);
                    }
                    if (!headerOnly)
                        replacements.Add(retained[0].Declaration, null);
                    foreach (var common in commonHeaders)
                        replacements.Add(common.Declaration, null);
                }
                else
                {
                    replacements.Add(first.Declaration, MergeAliases(compilation, aliases,
                        nativeCharacterStorage: nativeCharacterStorage, validation: validation,
                        recoverConflicts: recoverConflicts));
                    foreach (var alias in aliases.Skip(1))
                        replacements.Add(alias.Declaration, null);
                }
                }
                catch (InvalidDataException error)
                {
                    validation.Add(error, "CSSW005", "emitter.typedef-composition", first.Tree.FilePath,
                        first.Symbol.ToDisplayString(),
                        architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(first.Tree.FilePath).ToString());
                }
            }

            if (validation.BlockingErrorCount != previousErrors)
                return compilation;
            if (replacements.Count == 0)
                return compilation;
            var rewritten = compilation;
            var rewriter = new Rewriter(replacements);
            foreach (var tree in compilation.SyntaxTrees)
            {
                if (!replacements.Keys.Any(declaration => declaration.SyntaxTree == tree))
                    continue;
                var replacement = tree.WithRootAndOptions(rewriter.Visit(tree.GetRoot()), tree.Options);
                if (writeModifiedFiles)
                    File.WriteAllText(tree.FilePath, replacement.GetText().ToString());
                rewritten = rewritten.ReplaceSyntaxTree(tree, replacement);
            }
            return rewritten;
        }

        private static NativeProjectionOwner GetNativeProjectionOwner(Fragment[] aliases,
            IReadOnlyDictionary<string, NativeProjectionOwner> nativeOwners) =>
            nativeOwners.TryGetValue(aliases[0].Symbol.Name, out var candidate) &&
                candidate.Namespace == aliases[0].Symbol.ContainingNamespace.ToDisplayString() &&
                aliases.Any(alias => candidate.IsTarget(alias.Declaration)) &&
                aliases.All(alias => candidate.Authorizes(alias.Declaration)) ? candidate : null;

        private static Fragment[] OrderProviders(CSharpCompilation compilation, IEnumerable<Fragment> aliases,
            NativeProjectionOwner nativeOwner) =>
            aliases.Select(fragment =>
                {
                    var field = fragment.Declaration.Members.OfType<FieldDeclarationSyntax>().FirstOrDefault();
                    return (Fragment: fragment, Source: NativeTypedefSourceProvenance.Read(fragment.Declaration),
                        Storage: field == null ? null : fragment.Model.GetTypeInfo(field.Declaration.Type).Type);
                })
                .OrderBy(item => IsAutoTypesFile(item.Fragment.Tree.FilePath) ? 0 : 1)
                .ThenBy(item => nativeOwner?.IsTarget(item.Fragment.Declaration) == true ? 0 : 1)
                .ThenBy(item => item.Source?.TraversedHeader == true ? 0 : 1)
                .ThenBy(item => item.Source?.Header, StringComparer.OrdinalIgnoreCase)
                .ThenBy(item => item.Source?.Line)
                .ThenBy(item => item.Source?.Column)
                .ThenBy(item => item.Source?.HeaderHash, StringComparer.Ordinal)
                .ThenBy(item => item.Source?.Identity, StringComparer.Ordinal)
                .ThenBy(item => GetArchitecture(item.Fragment) == 0 ? 0 : 1)
                .ThenBy(item => item.Source?.SourceArchitecture)
                .ThenBy(item => item.Storage is INamedTypeSymbol named && named.TypeKind == TypeKind.Struct &&
                    named.GetAttributes().Any(attribute => AttributeName(attribute) == NativeTypedefName) ? 0 : 1)
                .ThenBy(item => item.Storage?.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat), StringComparer.Ordinal)
                .ThenBy(item => string.Join("|", item.Fragment.Attributes.Select(AttributeKey)
                    .OrderBy(key => key, StringComparer.Ordinal)), StringComparer.Ordinal)
                .ThenBy(item => item.Fragment.Declaration.WithoutTrivia().NormalizeWhitespace().ToFullString(),
                    StringComparer.Ordinal)
                .Select(item => item.Fragment).ToArray();

        private static StructDeclarationSyntax MergeAliases(CSharpCompilation compilation, Fragment[] aliases,
            Fragment[] architectureAliases = null, bool preserveRetainedCoverage = false, bool compareArchitectureFamilies = false,
            IReadOnlyDictionary<string, string> recordFamilies = null, ITypeSymbol nativeCharacterStorage = null,
            GenerationValidation validation = null, bool recoverConflicts = false)
        {
            var first = aliases[0];
            // Keep the retained field encoding when header bindings spell void-pointer storage as IntPtr.
            var retained = aliases.FirstOrDefault(alias => IsAutoTypesFile(alias.Tree.FilePath));
            var storageOwner = retained ?? first;
            var valueTypes = aliases.ToDictionary(alias => alias,
                alias => GetValueType(alias, alias.Model));
            var nativePointees = aliases.Where(alias => HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath))
                .Select(alias => GetFieldAttributes(alias, alias.Model)
                    .SingleOrDefault(attribute => AttributeName(attribute) == NativeTypeNameName)?.ConstructorArguments[0].Value as string)
                .Where(type => type != null && IsNativeRecordPointer(type)).Distinct(StringComparer.Ordinal).ToArray();
            if (nativePointees.Length > 1)
            {
                if (!recoverConflicts)
                    throw Error(first, "Conflicting native typedef pointee source identities.");
                string selectedNativeType = GetFieldAttributes(storageOwner, storageOwner.Model)
                    .SingleOrDefault(attribute => AttributeName(attribute) == NativeTypeNameName)?.ConstructorArguments[0].Value as string;
                foreach (var alias in aliases.Where(alias => alias != storageOwner))
                {
                    string incomingNativeType = GetFieldAttributes(alias, alias.Model)
                        .SingleOrDefault(attribute => AttributeName(attribute) == NativeTypeNameName)?.ConstructorArguments[0].Value as string;
                    if (incomingNativeType != selectedNativeType)
                        ReportCompositionConflict(validation, storageOwner, alias,
                            "Conflicting native typedef pointee source identities.", valueTypes[storageOwner], valueTypes[alias]);
                }
            }
            var valueType = nativeCharacterStorage ?? valueTypes[storageOwner];
            ITypeSymbol recordPointer = null;
            if (retained == null && TryGetHeaderRecordPointerStorage(compilation, aliases, valueTypes, out recordPointer))
                valueType = recordPointer;
            bool metadataOwner = retained?.Attributes.Any(attribute => AttributeName(attribute) == MetadataTypedefName) == true;
            bool? provenNativeStorage = null;
            foreach (var alias in aliases)
            {
                var incomingType = valueTypes[alias];
                // Compare native backing without flattening the emitted nominal aliases.
                if (alias != retained && !SymbolEqualityComparer.Default.Equals(valueType, incomingType))
                    incomingType = GetHeaderBackingStorage(compilation, incomingType,
                        new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default), recordFamilies);
                if (retained == null && !SymbolEqualityComparer.Default.Equals(valueType, incomingType))
                {
                    var storage = GetHeaderBackingStorage(compilation, valueType,
                        new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default), recordFamilies);
                    var incoming = GetHeaderBackingStorage(compilation, incomingType,
                        new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default), recordFamilies);
                    if ((storage.SpecialType is (SpecialType.System_SByte or SpecialType.System_Byte or
                        SpecialType.System_Int16 or SpecialType.System_UInt16 or SpecialType.System_Char or
                        SpecialType.System_Int32 or SpecialType.System_UInt32 or SpecialType.System_Int64 or SpecialType.System_UInt64) ||
                        storage is IPointerTypeSymbol) &&
                        (SymbolEqualityComparer.Default.Equals(storage, incoming) ||
                            compareArchitectureFamilies && IsSameArchitectureStorage(storage, incoming, recordFamilies)))
                        continue;
                }
                if ((retained != null || nativeCharacterStorage != null) && alias != retained &&
                    CanPreserveCharacterEncoding(compilation, alias, valueTypes[alias], valueType,
                        new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default)))
                    continue;
                if (compareArchitectureFamilies && IsSameArchitectureStorage(valueType, incomingType, recordFamilies))
                    continue;
                if (recordPointer != null && IsVoidPointer(incomingType))
                    continue;
                if (!SymbolEqualityComparer.Default.Equals(valueType, incomingType) &&
                    !(retained != null && IsEquivalentNativePointerStorage(valueType, incomingType)))
                {
                    provenNativeStorage ??= CanPreserveDeclaredHandleStorage(compilation, aliases, retained, valueTypes) ||
                        CanPreserveOpaqueStructPointerStorage(compilation, aliases, retained, valueTypes) ||
                        CanPreserveIntegralResourceStorage(compilation, aliases, retained, valueTypes) ||
                        CanPreserveNativeIntegerStorage(compilation, architectureAliases ?? aliases, retained);
                    if (!provenNativeStorage.Value)
                    {
                        if (!recoverConflicts)
                            throw Error(alias, "Conflicting native typedef Value storage types.");
                        ReportCompositionConflict(validation, storageOwner, alias,
                            "Conflicting native typedef Value storage types.", valueType, valueTypes[alias]);
                    }
                }
            }
            bool IncludeAttribute(AttributeData attribute) =>
                !(metadataOwner && AttributeName(attribute) == NativeTypedefName ||
                    preserveRetainedCoverage && AttributeName(attribute) == ArchitectureName);
            var attributesByType = first.Attributes.Where(IncludeAttribute).GroupBy(AttributeName, StringComparer.Ordinal)
                .ToDictionary(attributes => attributes.Key, attributes => attributes.ToArray(), StringComparer.Ordinal);
            var added = new List<AttributeListSyntax>();
            foreach (var alias in aliases.Skip(1))
            {
                foreach (var attributes in alias.Attributes.Where(IncludeAttribute).GroupBy(AttributeName, StringComparer.Ordinal))
                {
                    var incoming = attributes.ToArray();
                    if (attributesByType.TryGetValue(attributes.Key, out var existing))
                    {
                        if (!existing.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)
                            .SequenceEqual(incoming.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)))
                        {
                            if (!recoverConflicts)
                                throw Error(alias, $"Conflicting '{attributes.Key}' annotations.");
                            ReportCompositionConflict(validation, first, alias, $"Conflicting '{attributes.Key}' annotations.",
                                valueType, valueTypes[alias]);
                        }
                    }
                    else
                    {
                        attributesByType.Add(attributes.Key, incoming);
                        added.AddRange(incoming.Select(ToAttributeList));
                    }
                }
            }
            var declaration = first.Declaration;
            if (metadataOwner && first.Attributes.Any(attribute => AttributeName(attribute) == NativeTypedefName))
                declaration = declaration.WithAttributeLists(SyntaxFactory.List(first.Attributes.Where(IncludeAttribute)
                    .Select(ToAttributeList))).WithLeadingTrivia(declaration.GetLeadingTrivia());
            if (!SymbolEqualityComparer.Default.Equals(valueTypes[first], valueType))
            {
                var field = (FieldDeclarationSyntax)declaration.Members.Single();
                declaration = declaration.ReplaceNode(field.Declaration.Type,
                    SyntaxFactory.ParseTypeName(valueType.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat))
                        .WithTriviaFrom(field.Declaration.Type));
            }
            var fieldAttributes = aliases.Select(alias => GetFieldAttributes(alias, alias.Model))
                .ToArray();
            var existingFieldAttributes = fieldAttributes[0].Where(attribute => AttributeName(attribute) != NativeTypeNameName)
                .GroupBy(AttributeName).ToDictionary(group => group.Key, group => group.ToArray());
            var addedFieldAttributes = new List<AttributeListSyntax>();
            for (int index = 1; index < fieldAttributes.Length; index++)
            {
                var incomingAttributes = fieldAttributes[index];
                foreach (var attributes in incomingAttributes.Where(attribute => AttributeName(attribute) != NativeTypeNameName)
                    .GroupBy(AttributeName))
                {
                    var incoming = attributes.ToArray();
                    if (existingFieldAttributes.TryGetValue(attributes.Key, out var existing))
                    {
                        if (!existing.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)
                            .SequenceEqual(incoming.Select(AttributeKey).OrderBy(key => key, StringComparer.Ordinal)))
                        {
                            if (!recoverConflicts)
                                throw Error(first, $"Conflicting Value-field '{attributes.Key}' annotations.");
                            ReportCompositionConflict(validation, first, aliases[index],
                                $"Conflicting Value-field '{attributes.Key}' annotations.", valueType, valueTypes[aliases[index]]);
                        }
                    }
                    else
                    {
                        existingFieldAttributes.Add(attributes.Key, incoming);
                        addedFieldAttributes.AddRange(incoming.Select(ToAttributeList));
                    }
                }
            }
            var valueField = (FieldDeclarationSyntax)declaration.Members.Single();
            declaration = declaration.ReplaceNode(valueField, valueField.AddAttributeLists(addedFieldAttributes.ToArray()));
            declaration = declaration.AddAttributeLists(added.ToArray());
            if (NativeTypedefSourceProvenance.Read(declaration) != null &&
                (retained != null || aliases.Any(alias =>
                    NativeTypedefProjectionProvenance.IsInferred(alias.Declaration) == false)))
                declaration = NativeTypedefProjectionProvenance.WithPolicy(declaration, inferred: false);
            if (nativeCharacterStorage != null)
                declaration = declaration.WithAdditionalAnnotations(ComposedNativeCharacterProjection);
            return (provenNativeStorage == true ? NativeHandleSourceProvenance.Remove(declaration) : declaration)
                .WithAdditionalAnnotations(ComposedHeaderAlias);
        }

        private static void ReportCompositionConflict(GenerationValidation validation, Fragment selected, Fragment candidate,
            string message, ITypeSymbol selectedStorage, ITypeSymbol candidateStorage)
        {
            var selectedSource = NativeTypedefSourceProvenance.Read(selected.Declaration);
            var candidateSource = NativeTypedefSourceProvenance.Read(candidate.Declaration);
            var error = Error(candidate, message);
            validation.Add(new GenerationValidationError("CSSW005", "emitter.typedef-composition", error.Message)
            {
                BlocksEmission = false,
                Input = candidate.Tree.FilePath,
                Symbol = candidate.Symbol.ToDisplayString(),
                Header = candidateSource?.Header,
                Line = candidateSource?.Line is uint line && line <= int.MaxValue ? (int?)line : null,
                Architecture = ((Architecture)GetArchitecture(candidate)).ToString(),
                IdentityCategory = "selected-native-typedef-contract",
                Cause = error.ToString(),
                SelectedInput = selected.Tree.FilePath,
                SelectedStorage = selectedStorage.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat),
                CandidateStorage = candidateStorage.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat),
                SelectedSource = selectedSource,
                CandidateSource = candidateSource,
            });
        }

        internal static ITypeSymbol GetNativeRecordScalarStorage(CSharpCompilation compilation, ITypeSymbol type)
        {
            if (type is not INamedTypeSymbol named || named.TypeKind != TypeKind.Struct ||
                named.GetAttributes().Any(attribute => AttributeName(attribute) is not (NativeTypedefName or ArchitectureName)))
                return type;
            var declarations = named.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                .OfType<StructDeclarationSyntax>().ToArray();
            bool native = declarations.Length != 0 && declarations.All(declaration =>
                NativeTypedefSourceProvenance.Read(declaration) != null);
            bool retained = declarations.Length != 0 && declarations.All(declaration => IsAutoTypesFile(declaration.SyntaxTree.FilePath));
            if (!native && !retained || declarations.Any(declaration =>
                declaration.Members.OfType<FieldDeclarationSyntax>().SelectMany(field => field.AttributeLists)
                    .SelectMany(list => list.Attributes).Any(attribute =>
                        compilation.GetSemanticModel(declaration.SyntaxTree).GetSymbolInfo(attribute).Symbol is not IMethodSymbol constructor ||
                        constructor.ContainingType.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat) != NativeTypeNameName)))
                return type;
            var storage = GetHeaderBackingStorage(compilation, type, new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
            if (native && IntegerWidth(storage.SpecialType) != 0)
                return storage;
            if (retained)
            {
                var fields = named.GetMembers("Value").OfType<IFieldSymbol>().Where(field => !field.IsStatic).ToArray();
                if (fields.Length != 1)
                    return type;
                storage = fields[0].Type;
            }
            int depth = 0;
            var character = storage;
            while (character is IPointerTypeSymbol pointer)
            {
                depth++;
                character = pointer.PointedAtType;
            }
            if (native && depth != 0 && character.SpecialType == SpecialType.System_Char &&
                declarations.All(declaration => declaration.HasAnnotation(ComposedNativeCharacterProjection)))
                return storage;
            if (depth == 0 || character.SpecialType != (retained ? SpecialType.System_Char : SpecialType.System_UInt16))
                return type;
            ITypeSymbol projection = compilation.GetSpecialType(SpecialType.System_Char);
            for (int i = 0; i < depth; i++)
                projection = compilation.CreatePointerTypeSymbol(projection);
            if (retained)
                return projection;
            return declarations.All(declaration =>
            {
                var attributes = named.GetAttributes().Where(attribute =>
                    attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                    declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                var fragment = new Fragment(declaration.SyntaxTree, declaration, named, attributes,
                    compilation.GetSemanticModel(declaration.SyntaxTree));
                return CanPreserveCharacterEncoding(compilation, fragment,
                    GetValueType(fragment, fragment.Model), projection,
                    new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
            }) ? projection : type;
        }

        private static ITypeSymbol GetHeaderBackingStorage(CSharpCompilation compilation, ITypeSymbol type,
            HashSet<ITypeSymbol> resolving, IReadOnlyDictionary<string, string> recordFamilies = null,
            Func<Fragment[], IEnumerable<Fragment>> selectProviders = null)
        {
            if (type is IPointerTypeSymbol pointer)
                return compilation.CreatePointerTypeSymbol(GetHeaderBackingStorage(compilation, pointer.PointedAtType,
                    resolving, recordFamilies, selectProviders));
            if (type is not INamedTypeSymbol named || named.TypeKind != TypeKind.Struct ||
                !named.GetAttributes().Any(attribute => AttributeName(attribute) == NativeTypedefName))
                return type;
            var declarations = named.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                .OfType<StructDeclarationSyntax>().Where(declaration =>
                    HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath) ||
                    declaration.HasAnnotation(ComposedHeaderAlias) ||
                    selectProviders != null && IsAutoTypesFile(declaration.SyntaxTree.FilePath)).ToArray();
            if (declarations.Length == 0)
                return type;
            if (!resolving.Add(type))
                throw new InvalidDataException($"Cyclic header native typedef storage for '{type.ToDisplayString()}'.");
            ITypeSymbol storage = null;
            var fragments = declarations.Select(declaration =>
            {
                var attributes = named.GetAttributes().Where(attribute =>
                    attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                    declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                return new Fragment(declaration.SyntaxTree, declaration, named, attributes,
                    compilation.GetSemanticModel(declaration.SyntaxTree));
            }).OrderBy(fragment => GetArchitecture(fragment) == 0 ? 1 : 0).ToArray();
            foreach (var fragment in selectProviders != null ? selectProviders(fragments) : fragments)
            {
                var incoming = GetHeaderBackingStorage(compilation,
                    GetValueType(fragment, fragment.Model), resolving, recordFamilies, selectProviders);
                if (storage != null && !SymbolEqualityComparer.Default.Equals(storage, incoming) &&
                    !IsSameArchitectureStorage(storage, incoming, recordFamilies))
                    throw Error(fragment, "Conflicting native typedef backing storage types.");
                storage ??= incoming;
            }
            resolving.Remove(type);
            return storage;
        }

        private static bool HasRoutedRetainedOwner(Fragment[] aliases, IReadOnlyDictionary<string, string> requiredNamespaces)
        {
            var retained = aliases.Where(alias => IsAutoTypesFile(alias.Tree.FilePath)).ToArray();
            return retained.Length == 1 && requiredNamespaces != null &&
                requiredNamespaces.TryGetValue(retained[0].Symbol.Name, out string owner) &&
                owner == retained[0].Symbol.ContainingNamespace.ToDisplayString() &&
                aliases.Where(alias => alias != retained[0]).All(alias => HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath));
        }

        private static bool CanKeepCommonHeaderCoverage(CSharpCompilation compilation, Fragment[] aliases, Fragment common)
        {
            var source = NativeTypedefSourceProvenance.Read(common.Declaration);
            if (source == null || !CanKeepCommonAliasCoverage(compilation, aliases, common))
                return false;
            var storage = GetValueType(common, common.Model);
            return aliases.All(alias =>
            {
                var incoming = NativeTypedefSourceProvenance.Read(alias.Declaration);
                return (incoming == null || NativeRecordSourceProvenance.SameDeclaration(source, incoming)) &&
                    SymbolEqualityComparer.Default.Equals(storage,
                        GetValueType(alias, alias.Model));
            });
        }

        private static bool CanKeepCommonAliasCoverage(CSharpCompilation compilation, Fragment[] aliases, Fragment retained)
        {
            var attributes = retained.Attributes.Select(AttributeKey).ToHashSet(StringComparer.Ordinal);
            var fieldAttributes = GetFieldAttributes(retained, retained.Model)
                .Select(AttributeKey).ToHashSet(StringComparer.Ordinal);
            return aliases.Where(alias => alias != retained).All(alias =>
                SymbolEqualityComparer.Default.Equals(alias.Symbol, retained.Symbol) &&
                alias.Attributes.Where(attribute => AttributeName(attribute) != ArchitectureName)
                    .All(attribute => attributes.Contains(AttributeKey(attribute))) &&
                GetFieldAttributes(alias, alias.Model)
                    .Where(attribute => AttributeName(attribute) != NativeTypeNameName)
                    .All(attribute => fieldAttributes.Contains(AttributeKey(attribute))));
        }

        private static bool CanPreserveNativeIntegerStorage(CSharpCompilation compilation, Fragment[] aliases, Fragment retained)
        {
            if (retained == null || aliases.Count(alias => IsAutoTypesFile(alias.Tree.FilePath)) != 1)
                return false;
            var retainedType = GetValueType(retained, retained.Model).SpecialType;
            if (retainedType is not (SpecialType.System_IntPtr or SpecialType.System_UIntPtr))
                return false;
            var headers = aliases.Where(alias => alias != retained).ToArray();
            if (headers.Any(alias => !HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath) || GetArchitecture(alias) == 0) ||
                headers.Aggregate(0, (mask, alias) => mask | GetArchitecture(alias)) != (int)Architecture.All)
                return false;
            return headers.All(alias =>
            {
                var storage = GetHeaderBackingStorage(compilation,
                    GetValueType(alias, alias.Model),
                    new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default)).SpecialType;
                int mask = GetArchitecture(alias);
                return storage == (retainedType == SpecialType.System_UIntPtr ? SpecialType.System_UInt32 : SpecialType.System_Int32)
                    ? (mask & ~(int)Architecture.X86) == 0
                    : storage == (retainedType == SpecialType.System_UIntPtr ? SpecialType.System_UInt64 : SpecialType.System_Int64) &&
                        (mask & (int)Architecture.X86) == 0;
            });
        }

        private static ITypeSymbol GetNativeCharacterPointerProjection(CSharpCompilation compilation, Fragment target)
        {
            if (!NativeTypedefProjectionProvenance.HasConfiguredNominalBinding(target.Declaration))
                return null;
            var incoming = GetValueType(target, target.Model);
            var storage = GetHeaderBackingStorage(compilation, incoming,
                new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
            int depth = 0;
            while (storage is IPointerTypeSymbol pointer)
            {
                depth++;
                storage = pointer.PointedAtType;
            }
            if (depth == 0 || storage.SpecialType is not (SpecialType.System_SByte or SpecialType.System_UInt16))
                return null;
            ITypeSymbol projection = compilation.GetSpecialType(storage.SpecialType == SpecialType.System_SByte
                ? SpecialType.System_Byte : SpecialType.System_Char);
            for (int i = 0; i < depth; i++)
                projection = compilation.CreatePointerTypeSymbol(projection);
            return CanPreserveCharacterEncoding(compilation, target, incoming, projection,
                new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default),
                requireNativeCharacterSpelling: true) ? projection : null;
        }

        private static bool CanPreserveCharacterEncoding(CSharpCompilation compilation, Fragment source,
            ITypeSymbol incoming, ITypeSymbol retained, HashSet<ITypeSymbol> resolving, int pointerDepth = 0,
            bool requireNativeCharacterSpelling = false)
        {
            if (incoming is IPointerTypeSymbol pointer)
                return retained is IPointerTypeSymbol retainedPointer && CanPreserveCharacterEncoding(compilation,
                    source, pointer.PointedAtType, retainedPointer.PointedAtType, resolving, pointerDepth + 1,
                    requireNativeCharacterSpelling);
            if (incoming is INamedTypeSymbol named && named.GetAttributes().Any(attribute => AttributeName(attribute) == NativeTypedefName))
            {
                var declarations = named.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                    .OfType<StructDeclarationSyntax>().Where(declaration =>
                        HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath)).ToArray();
                if (declarations.Length == 0 || !resolving.Add(named))
                    return false;
                bool compatible = declarations.All(declaration =>
                {
                    var attributes = named.GetAttributes().Where(attribute =>
                        attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                        declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                    var fragment = new Fragment(declaration.SyntaxTree, declaration, named, attributes,
                        compilation.GetSemanticModel(declaration.SyntaxTree));
                    return CanPreserveCharacterEncoding(compilation, fragment,
                        GetValueType(fragment, fragment.Model), retained, resolving,
                        requireNativeCharacterSpelling: requireNativeCharacterSpelling);
                });
                resolving.Remove(named);
                return compatible;
            }
            string nativeType = GetFieldAttributes(source, source.Model)
                .SingleOrDefault(attribute => AttributeName(attribute) == NativeTypeNameName)?.ConstructorArguments[0].Value as string;
            string suffix = string.Concat(Enumerable.Repeat(" *", pointerDepth));
            return nativeType == "char" + suffix &&
                (incoming.SpecialType == SpecialType.System_SByte && retained.SpecialType == SpecialType.System_Byte ||
                    incoming.SpecialType == SpecialType.System_Byte && retained.SpecialType == SpecialType.System_SByte) ||
                nativeType is not null && (nativeType == "wchar_t" + suffix ||
                    !requireNativeCharacterSpelling && nativeType == "unsigned short" + suffix) &&
                incoming.SpecialType == SpecialType.System_UInt16 && retained.SpecialType == SpecialType.System_Char;
        }

        private static bool TryGetHeaderRecordPointerStorage(CSharpCompilation compilation, Fragment[] aliases,
            IReadOnlyDictionary<Fragment, ITypeSymbol> valueTypes, out ITypeSymbol storage)
        {
            storage = null;
            if (aliases.Length < 2 || !aliases.All(alias => HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath)) ||
                !valueTypes.Values.Any(IsVoidPointer))
                return false;
            string nativeType = null;
            foreach (var alias in aliases)
            {
                var field = (FieldDeclarationSyntax)alias.Declaration.Members.Single();
                var source = field.AttributeLists.SelectMany(list => list.Attributes)
                    .Where(attribute => attribute.Name.ToString() == "NativeTypeName")
                    .Select(attribute => attribute.ArgumentList?.Arguments.SingleOrDefault()?.Expression)
                    .OfType<LiteralExpressionSyntax>().Select(expression => expression.Token.ValueText).ToArray();
                if (source.Length != 1 || !Regex.IsMatch(source[0],
                    @"^(?:const )?(?:(?:struct|union) )?(?:::)?[A-Za-z_]\w*(?:::[A-Za-z_]\w*)* \*$") ||
                    nativeType != null && nativeType != source[0])
                    return false;
                nativeType = source[0];
                var type = valueTypes[alias];
                if (IsVoidPointer(type))
                    continue;
                if (type is not IPointerTypeSymbol pointer || pointer.PointedAtType is not INamedTypeSymbol record)
                    return false;
                bool intrinsicGuid = SymbolEqualityComparer.Default.Equals(record,
                    compilation.GetSpecialType(SpecialType.System_Object).ContainingAssembly.GetTypeByMetadataName("System.Guid"));
                if (record.TypeKind != TypeKind.Struct || !record.IsUnmanagedType || record.ContainingType != null ||
                    record.DeclaringSyntaxReferences.Length == 0 && !intrinsicGuid || record.GetAttributes().Any(attribute =>
                        AttributeName(attribute) is NativeTypedefName or MetadataTypedefName) ||
                    storage != null && !SymbolEqualityComparer.Default.Equals(storage, type))
                    return false;
                if (!IsNativeRecordPointer(nativeType) &&
                    Regex.Match(nativeType, @"([A-Za-z_]\w*) \*$").Groups[1].Value != record.Name &&
                    !(intrinsicGuid && Regex.Match(nativeType, @"([A-Za-z_]\w*) \*$").Groups[1].Value == "GUID"))
                    return false;
                storage = type;
            }
            return storage != null;
        }

        private static bool IsNativeRecordPointer(string type) =>
            Regex.IsMatch(type, @"^(?:const )?(?:struct|union) (?:::)?[A-Za-z_]\w*(?:::[A-Za-z_]\w*)* \*$");

        private static bool IsSameArchitectureStorage(ITypeSymbol left, ITypeSymbol right,
            IReadOnlyDictionary<string, string> recordFamilies)
        {
            if (SymbolEqualityComparer.Default.Equals(left, right))
                return true;
            if (left is IPointerTypeSymbol leftPointer && right is IPointerTypeSymbol rightPointer)
                return IsSameArchitectureStorage(leftPointer.PointedAtType, rightPointer.PointedAtType, recordFamilies);
            if (left is not INamedTypeSymbol leftRecord || right is not INamedTypeSymbol rightRecord)
                return false;
            foreach (var record in new[] { leftRecord, rightRecord })
                if (record.TypeKind != TypeKind.Struct || record.ContainingType != null ||
                    record.GetAttributes().Any(attribute => AttributeName(attribute) is NativeTypedefName or MetadataTypedefName))
                    return false;
            int leftMask = RecordMask(leftRecord), rightMask = RecordMask(rightRecord);
            return leftMask != 0 && rightMask != 0 && (leftMask & rightMask) == 0 &&
                recordFamilies != null &&
                recordFamilies.TryGetValue(leftRecord.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat), out string leftFamily) &&
                recordFamilies.TryGetValue(rightRecord.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat), out string rightFamily) &&
                leftFamily == rightFamily;

            static int RecordMask(INamedTypeSymbol record)
            {
                var attributes = record.GetAttributes().Where(attribute => AttributeName(attribute) == ArchitectureName).ToArray();
                if (attributes.Length == 0 || attributes.Any(attribute => attribute.ConstructorArguments.Length != 1 ||
                    attribute.ConstructorArguments[0].Value is not int mask || mask <= 0 || (mask & ~(int)Architecture.All) != 0))
                    return 0;
                var masks = attributes.Select(attribute => (int)attribute.ConstructorArguments[0].Value).Distinct().ToArray();
                return masks.Length == 1 ? masks[0] : 0;
            }
        }

        private static bool CanPreserveIntegralResourceStorage(CSharpCompilation compilation, Fragment[] aliases,
            Fragment retained, IReadOnlyDictionary<Fragment, ITypeSymbol> valueTypes)
        {
            if (retained == null || aliases.Count(alias => IsAutoTypesFile(alias.Tree.FilePath)) != 1 ||
                !retained.Attributes.Any(attribute => AttributeName(attribute) == InvalidHandleValueName) ||
                !retained.Attributes.Any(attribute => AttributeName(attribute) == RaiiFreeName &&
                    attribute.ConstructorArguments.Length == 1 &&
                    attribute.ConstructorArguments[0].Value is string closeApi && !string.IsNullOrWhiteSpace(closeApi)))
                return false;
            int size = GetIntegralStorageSize(valueTypes[retained].SpecialType);
            return size != 0 && aliases.Where(alias => alias != retained).All(alias =>
                HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath) &&
                GetIntegralStorageSize(GetHeaderBackingStorage(compilation, valueTypes[alias],
                    new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default)).SpecialType) == size);
        }

        private static int GetIntegralStorageSize(SpecialType type) => type switch
        {
            SpecialType.System_SByte or SpecialType.System_Byte => 1,
            SpecialType.System_Int16 or SpecialType.System_UInt16 => 2,
            SpecialType.System_Int32 or SpecialType.System_UInt32 => 4,
            SpecialType.System_Int64 or SpecialType.System_UInt64 => 8,
            _ => 0,
        };

        private static bool CanPreserveDeclaredHandleStorage(CSharpCompilation compilation, Fragment[] aliases, Fragment retained,
            IReadOnlyDictionary<Fragment, ITypeSymbol> valueTypes)
        {
            if (retained == null || aliases.Count(alias => IsAutoTypesFile(alias.Tree.FilePath)) != 1 ||
                !IsVoidPointer(valueTypes[retained]) ||
                !retained.Attributes.Any(attribute => AttributeName(attribute) == InvalidHandleValueName) ||
                !TryGetNativeHandleProof(retained, NativeHandleSourceProvider.Retained,
                    NativeHandleSourceProvenance.DeclareHandleKind, out var retainedProof))
                return false;
            return CanComposeProvenHeaderPointers(compilation, aliases, retained, valueTypes, retainedProof);
        }

        private static bool CanPreserveOpaqueStructPointerStorage(CSharpCompilation compilation, Fragment[] aliases,
            Fragment retained, IReadOnlyDictionary<Fragment, ITypeSymbol> valueTypes)
        {
            if (retained == null || aliases.Count(alias => IsAutoTypesFile(alias.Tree.FilePath)) != 1 ||
                valueTypes[retained].SpecialType != SpecialType.System_IntPtr ||
                !retained.Attributes.Any(attribute => AttributeName(attribute) == InvalidHandleValueName) ||
                !TryGetNativeHandleProof(retained, NativeHandleSourceProvider.Retained,
                    NativeHandleSourceProvenance.OpaqueStructPointerKind, out var retainedProof) ||
                !retainedProof.WrapperIntent || retainedProof.PointerDepth != 1)
                return false;
            return CanComposeProvenHeaderPointers(compilation, aliases, retained, valueTypes, retainedProof);
        }

        private static bool CanComposeProvenHeaderPointers(CSharpCompilation compilation, Fragment[] aliases,
            Fragment retained, IReadOnlyDictionary<Fragment, ITypeSymbol> valueTypes, NativeHandleSourceProof retainedProof)
        {
            if (aliases.Length < 2)
                return false;
            ITypeSymbol nativeStorage = null;
            string nativeStorageSyntax = null;
            foreach (var alias in aliases.Where(alias => alias != retained))
            {
                if (!HeaderEnumGroupMerger.IsHeaderTypesFile(alias.Tree.FilePath) ||
                    !TryGetNativeHandleProof(alias, NativeHandleSourceProvider.Header, retainedProof.Kind, out var headerProof) ||
                    !StringComparer.Ordinal.Equals(retainedProof.NativeAlias, headerProof.NativeAlias) ||
                    !StringComparer.Ordinal.Equals(retainedProof.NativeTag, headerProof.NativeTag) ||
                    retainedProof.WrapperIntent != headerProof.WrapperIntent ||
                    retainedProof.PointerDepth != headerProof.PointerDepth ||
                    valueTypes[alias] is not IPointerTypeSymbol pointer || !IsUnambiguousHandlePointee(pointer.PointedAtType))
                    return false;
                if (nativeStorage is IPointerTypeSymbol previous)
                {
                    if (previous.PointedAtType is IErrorTypeSymbol || pointer.PointedAtType is IErrorTypeSymbol)
                    {
                        if (previous.PointedAtType is not IErrorTypeSymbol || pointer.PointedAtType is not IErrorTypeSymbol ||
                            !SyntaxFactory.AreEquivalent(SyntaxFactory.ParseTypeName(nativeStorageSyntax),
                                SyntaxFactory.ParseTypeName(headerProof.StorageType)))
                            return false;
                    }
                    else if (!SymbolEqualityComparer.Default.Equals(previous, pointer))
                        return false;
                }
                var field = (FieldDeclarationSyntax)alias.Declaration.Members.Single();
                var model = alias.Model;
                if (field.Declaration.Type.DescendantNodesAndSelf().OfType<IdentifierNameSyntax>()
                    .Any(name => model.GetAliasInfo(name) is IAliasSymbol binding && binding.Name != "global"))
                    return false;
                nativeStorage = valueTypes[alias];
                nativeStorageSyntax = headerProof.StorageType;
            }
            return true;
        }

        private static bool IsUnambiguousHandlePointee(ITypeSymbol pointee)
        {
            // Retained auto-type preparation can intentionally exclude the proven native tag.
            if (pointee is IErrorTypeSymbol missing)
                return missing.CandidateReason == CandidateReason.None && missing.CandidateSymbols.IsEmpty;
            return pointee is INamedTypeSymbol record && record.TypeKind == TypeKind.Struct &&
                record.SpecialType == SpecialType.None && !record.IsGenericType && record.ContainingType == null &&
                record.IsUnmanagedType && record.DeclaringSyntaxReferences.Length == 1 &&
                !record.GetAttributes().Any(attribute => AttributeName(attribute) is NativeTypedefName or
                    "global::Windows.Win32.Foundation.Metadata.MetadataTypedefAttribute");
        }

        private static bool TryGetNativeHandleProof(Fragment fragment, NativeHandleSourceProvider provider,
            string kind, out NativeHandleSourceProof proof)
        {
            if (!NativeHandleSourceProvenance.TryRead(fragment.Declaration, out proof) ||
                proof.Provider != provider || proof.Kind != kind)
                return false;
            string fullName = fragment.Symbol.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
            string originalName = GetIdentity(fragment).Substring(fullName.Length - fragment.Symbol.Name.Length);
            return StringComparer.Ordinal.Equals(proof.GeneratedAlias, originalName);
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
                field.Declaration.Variables[0].Initializer != null ||
                !field.Modifiers.Any(SyntaxKind.PublicKeyword) || field.Modifiers.Any(modifier =>
                    modifier.IsKind(SyntaxKind.StaticKeyword) || modifier.IsKind(SyntaxKind.ConstKeyword) ||
                    modifier.IsKind(SyntaxKind.ReadOnlyKeyword) || modifier.IsKind(SyntaxKind.VolatileKeyword)) ||
                fragment.Attributes.Count(attribute => AttributeName(attribute) == NativeTypedefName ||
                    IsAutoTypesFile(fragment.Tree.FilePath) && AttributeName(attribute) == MetadataTypedefName) != 1)
                throw Error(fragment, "Expected a namespace-level native typedef wrapper containing one public instance Value field.");
            if (model.GetDeclaredSymbol(field.Declaration.Variables[0]) is not IFieldSymbol valueField)
                throw Error(fragment, "Cannot resolve native typedef Value storage.");
            var fieldAttributes = valueField.GetAttributes();
            if (fieldAttributes.GroupBy(AttributeName).Any(group => group.Count() != 1) ||
                fieldAttributes.Any(attribute => attribute.NamedArguments.Length != 0 ||
                    (AttributeName(attribute) is ConstName or NotNullTerminatedName or NullNullTerminatedName ?
                        attribute.ConstructorArguments.Length != 0 :
                        AttributeName(attribute) is not (NativeTypeNameName or DocumentationName) ||
                        attribute.ConstructorArguments.Length != 1 || attribute.ConstructorArguments[0].Value is not string)))
                throw Error(fragment, "Native typedef Value fields only support one NativeTypeName source-transport attribute " +
                    "and compatible Const/Documentation/string-termination metadata.");
            var type = model.GetTypeInfo(field.Declaration.Type).Type;
            if (type == null || type.TypeKind == TypeKind.Error || !type.IsUnmanagedType)
                throw Error(fragment, "Cannot resolve native typedef Value storage.");
            return type;
        }

        internal static bool NativeStorageMatches(NativeRecordSource source, ITypeSymbol storage)
        {
            if (source == null)
                return false;
            int pointerSize = source.SourceArchitecture switch
            {
                Architecture.X86 => 4,
                Architecture.X64 or Architecture.Arm64 => 8,
                _ => 0,
            };
            int size = StorageSize(storage, new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
            return size != 0 && source.Size == size && source.Alignment == size;

            int StorageSize(ITypeSymbol type, HashSet<ITypeSymbol> resolving)
            {
                if (type is INamedTypeSymbol { TypeKind: TypeKind.Enum } enumeration)
                    return StorageSize(enumeration.EnumUnderlyingType, resolving);
                int size = type.SpecialType switch
                {
                    SpecialType.System_Boolean or SpecialType.System_SByte or SpecialType.System_Byte => 1,
                    SpecialType.System_Char or SpecialType.System_Int16 or SpecialType.System_UInt16 => 2,
                    SpecialType.System_Int32 or SpecialType.System_UInt32 or SpecialType.System_Single => 4,
                    SpecialType.System_Int64 or SpecialType.System_UInt64 or SpecialType.System_Double => 8,
                    SpecialType.System_IntPtr or SpecialType.System_UIntPtr => pointerSize,
                    _ => type is IPointerTypeSymbol ? pointerSize : 0,
                };
                if (size != 0 || !resolving.Add(type))
                    return size;
                var attributes = type.GetAttributes();
                if (!attributes.Any(attribute => AttributeName(attribute) == NativeTypedefName) ||
                    attributes.Any(attribute => attribute.AttributeClass?.Name is
                        "StructLayoutAttribute" or "AlignmentAttribute"))
                    return 0;
                var fields = type.GetMembers().OfType<IFieldSymbol>().Where(field => !field.IsStatic).ToArray();
                return fields.Length == 1 && fields[0].Name == "Value" &&
                    !fields[0].GetAttributes().Any(attribute => attribute.AttributeClass?.Name == "FieldOffsetAttribute")
                    ? StorageSize(fields[0].Type, resolving) : 0;
            }
        }

        private static IEnumerable<AttributeData> GetFieldAttributes(Fragment fragment, SemanticModel model)
        {
            GetValueType(fragment, model);
            var field = (FieldDeclarationSyntax)fragment.Declaration.Members.Single();
            return ((IFieldSymbol)model.GetDeclaredSymbol(field.Declaration.Variables.Single())).GetAttributes();
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

        private sealed record Fragment(SyntaxTree Tree, StructDeclarationSyntax Declaration, INamedTypeSymbol Symbol,
            AttributeData[] Attributes, SemanticModel Model);

        private sealed class EnumProjection
        {
            internal EnumProjection(EnumDeclarationSyntax declaration, INamedTypeSymbol symbol)
            {
                Declaration = declaration;
                Symbol = symbol;
            }

            internal EnumDeclarationSyntax Declaration { get; }
            internal INamedTypeSymbol Symbol { get; }
            internal string Identity => Symbol.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
            internal bool HasUse { get; set; }
            internal bool HasExplicitProjection { get; set; }
        }

        private sealed class Rewriter : CSharpSyntaxRewriter
        {
            private readonly Dictionary<StructDeclarationSyntax, StructDeclarationSyntax> replacements;

            internal Rewriter(Dictionary<StructDeclarationSyntax, StructDeclarationSyntax> replacements) => this.replacements = replacements;

            public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node) =>
                replacements.TryGetValue(node, out var replacement) ? replacement : base.VisitStructDeclaration(node);
        }
    }
}
