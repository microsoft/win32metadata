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
        private const string NativeTypeNameName = "global::Windows.Win32.Foundation.Metadata.NativeTypeNameAttribute";
        private const string InvalidHandleValueName = "global::Windows.Win32.Foundation.Metadata.InvalidHandleValueAttribute";
        private const string RaiiFreeName = "global::Windows.Win32.Foundation.Metadata.RAIIFreeAttribute";
        private const string ArchitectureName = "global::Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute";

        internal static CSharpCompilation LowerConstants(CSharpCompilation compilation, bool writeModifiedFiles = true)
        {
            var validation = new GenerationValidation();
            var result = LowerConstantsWithDiagnostics(compilation, writeModifiedFiles, validation);
            validation.ThrowIfAny();
            return result;
        }

        internal static CSharpCompilation LowerConstantsWithDiagnostics(CSharpCompilation compilation,
            bool writeModifiedFiles, GenerationValidation validation)
        {
            int previousErrors = validation.Errors.Count;
            var storageTypes = new Dictionary<ITypeSymbol, ITypeSymbol>(SymbolEqualityComparer.Default);
            var rewritten = compilation;
            foreach (var tree in compilation.SyntaxTrees)
            {
                var model = compilation.GetSemanticModel(tree);
                var replacements = new Dictionary<TypeSyntax, TypeSyntax>();
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
                        LowerCasts(member.EqualsValue?.Value);
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-constant-lowering", tree.FilePath,
                            member.Identifier.ValueText,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
                if (replacements.Count == 0)
                    continue;
                var replacement = tree.WithRootAndOptions(tree.GetRoot().ReplaceNodes(replacements.Keys,
                    (original, _) => replacements[original]), tree.Options);
                rewritten = rewritten.ReplaceSyntaxTree(tree, replacement);

                void LowerCasts(ExpressionSyntax expression)
                {
                    if (expression == null)
                        return;
                    foreach (var cast in expression.DescendantNodesAndSelf().OfType<CastExpressionSyntax>())
                    {
                        var storage = GetStorage(cast.Type);
                        if (storage != null)
                            replacements.Add(cast.Type, StorageSyntax(storage, cast.Type));
                    }
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
                    if (!declarations.Any(declaration => HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath)))
                        return null;
                    ITypeSymbol valueType = null;
                    foreach (var declaration in declarations)
                    {
                        var attributes = type.GetAttributes().Where(attribute =>
                            attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                            declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                        var fragment = new Fragment(declaration.SyntaxTree, declaration, type, attributes);
                        var incoming = GetHeaderBackingStorage(compilation,
                            GetValueType(fragment, compilation.GetSemanticModel(declaration.SyntaxTree)),
                            new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
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
        }

        private static TypeSyntax StorageSyntax(ITypeSymbol storage, TypeSyntax original) =>
            SyntaxFactory.ParseTypeName(storage.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat)).WithTriviaFrom(original);

        internal static CSharpCompilation Merge(CSharpCompilation compilation)
        {
            var validation = new GenerationValidation();
            var result = MergeWithDiagnostics(compilation, validation);
            validation.ThrowIfAny();
            return result;
        }

        internal static CSharpCompilation MergeWithDiagnostics(CSharpCompilation compilation, GenerationValidation validation)
        {
            int previousErrors = validation.Errors.Count;
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
                    if (!attributes.Any(attribute => AttributeName(attribute) == NativeTypedefName))
                        continue;
                    fragments.Add(new Fragment(tree, declaration, symbol, attributes));
                    }
                    catch (InvalidDataException error)
                    {
                        validation.Add(error, "CSSW005", "emitter.typedef-input", tree.FilePath,
                            declaration.Identifier.ValueText,
                            architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(tree.FilePath).ToString());
                    }
                }
            }

            var replacements = new Dictionary<StructDeclarationSyntax, StructDeclarationSyntax>();
            foreach (var group in fragments.GroupBy(GetIdentity,
                StringComparer.Ordinal).Where(group => group.Any(fragment => HeaderEnumGroupMerger.IsHeaderTypesFile(fragment.Tree.FilePath))))
            {
                var aliases = group.OrderBy(fragment => IsAutoTypesFile(fragment.Tree.FilePath) ? 0 : 1)
                    .ThenBy(fragment => fragment.Tree.FilePath, StringComparer.Ordinal).ToArray();
                var first = aliases[0];
                try
                {
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
                catch (InvalidDataException error)
                {
                    validation.Add(error, "CSSW005", "emitter.typedef-composition", first.Tree.FilePath,
                        first.Symbol.ToDisplayString(),
                        architecture: ClangSharpSourceCompilation.GetArchitectureForFileName(first.Tree.FilePath).ToString());
                }
            }

            if (validation.Errors.Count != previousErrors)
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
            var valueTypes = aliases.ToDictionary(alias => alias,
                alias => GetValueType(alias, compilation.GetSemanticModel(alias.Tree)));
            var valueType = valueTypes[storageOwner];
            bool? provenNativeStorage = null;
            foreach (var alias in aliases)
            {
                var incomingType = valueTypes[alias];
                // Compare native backing without flattening the emitted nominal aliases.
                if (retained != null && alias != retained && !SymbolEqualityComparer.Default.Equals(valueType, incomingType))
                    incomingType = GetHeaderBackingStorage(compilation, incomingType, new HashSet<ITypeSymbol>(SymbolEqualityComparer.Default));
                if (!SymbolEqualityComparer.Default.Equals(valueType, incomingType) &&
                    !(retained != null && IsEquivalentNativePointerStorage(valueType, incomingType)))
                {
                    provenNativeStorage ??= CanPreserveDeclaredHandleStorage(compilation, aliases, retained, valueTypes) ||
                        CanPreserveOpaqueStructPointerStorage(compilation, aliases, retained, valueTypes) ||
                        CanPreserveIntegralResourceStorage(compilation, aliases, retained, valueTypes);
                    if (!provenNativeStorage.Value)
                        throw Error(alias, "Conflicting native typedef Value storage types.");
                }
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
            declaration = declaration.AddAttributeLists(added.ToArray());
            return provenNativeStorage == true ? NativeHandleSourceProvenance.Remove(declaration) : declaration;
        }

        private static ITypeSymbol GetHeaderBackingStorage(CSharpCompilation compilation, ITypeSymbol type,
            HashSet<ITypeSymbol> resolving)
        {
            if (type is not INamedTypeSymbol named || named.TypeKind != TypeKind.Struct ||
                !named.GetAttributes().Any(attribute => AttributeName(attribute) == NativeTypedefName))
                return type;
            var declarations = named.DeclaringSyntaxReferences.Select(reference => reference.GetSyntax())
                .OfType<StructDeclarationSyntax>().Where(declaration =>
                    HeaderEnumGroupMerger.IsHeaderTypesFile(declaration.SyntaxTree.FilePath)).ToArray();
            if (declarations.Length == 0)
                return type;
            if (!resolving.Add(type))
                throw new InvalidDataException($"Cyclic header native typedef storage for '{type.ToDisplayString()}'.");
            ITypeSymbol storage = null;
            foreach (var declaration in declarations)
            {
                var attributes = named.GetAttributes().Where(attribute =>
                    attribute.ApplicationSyntaxReference?.SyntaxTree == declaration.SyntaxTree &&
                    declaration.AttributeLists.Any(list => list.Span.Contains(attribute.ApplicationSyntaxReference.Span))).ToArray();
                var fragment = new Fragment(declaration.SyntaxTree, declaration, named, attributes);
                var incoming = GetHeaderBackingStorage(compilation,
                    GetValueType(fragment, compilation.GetSemanticModel(declaration.SyntaxTree)), resolving);
                if (storage != null && !SymbolEqualityComparer.Default.Equals(storage, incoming))
                    throw Error(fragment, "Conflicting native typedef backing storage types.");
                storage = incoming;
            }
            resolving.Remove(type);
            return storage;
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
                var model = compilation.GetSemanticModel(alias.Tree);
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
                fragment.Attributes.Count(attribute => AttributeName(attribute) == NativeTypedefName) != 1)
                throw Error(fragment, "Expected a namespace-level native typedef wrapper containing one public instance Value field.");
            if (model.GetDeclaredSymbol(field.Declaration.Variables[0]) is not IFieldSymbol valueField)
                throw Error(fragment, "Cannot resolve native typedef Value storage.");
            var fieldAttributes = valueField.GetAttributes();
            if (fieldAttributes.Length > 1 || fieldAttributes.Any(attribute => AttributeName(attribute) != NativeTypeNameName ||
                attribute.ConstructorArguments.Length != 1 || attribute.ConstructorArguments[0].Value is not string ||
                attribute.NamedArguments.Length != 0))
                throw Error(fragment, "Native typedef Value fields only support one NativeTypeName source-transport attribute.");
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
