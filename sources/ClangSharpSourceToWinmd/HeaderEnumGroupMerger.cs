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
    internal static class HeaderEnumGroupMerger
    {
        internal static void Merge(List<string> files, string objDir, string architecture, HashSet<string> sourceEnumMembers)
        {
            var fileSet = files.ToHashSet(StringComparer.OrdinalIgnoreCase);
            var roots = new Dictionary<string, SyntaxNode>(StringComparer.OrdinalIgnoreCase);
            var fragments = new List<Fragment>();
            foreach (string file in files.Where(IsHeaderTypesFile).OrderBy(file => file, StringComparer.OrdinalIgnoreCase))
            {
                var root = CSharpSyntaxTree.ParseText(File.ReadAllText(file), path: file).GetRoot();
                roots.Add(file, root);
                var identities = new HashSet<(string, string)>();
                foreach (var declaration in root.DescendantNodes().OfType<EnumDeclarationSyntax>())
                {
                    if (declaration.Parent is not BaseNamespaceDeclarationSyntax and not CompilationUnitSyntax)
                        throw Error(file, declaration.Identifier.ValueText, "Logical groups must be namespace-level declarations.");
                    string ns = GetNamespace(declaration);
                    if (!identities.Add((ns, declaration.Identifier.ValueText)))
                        throw Error(file, declaration.Identifier.ValueText, "Distinct native declarations project to the same logical group in one translation unit.");
                    fragments.Add(new Fragment(file, ns, declaration,
                        architecture == "crossarch" ? GetArchitectures(file, fileSet) : Architecture.All));
                }
            }

            if (fragments.Count == 0)
                return;

            var headerGroups = fragments.Select(fragment =>
                (fragment.Namespace, fragment.Declaration.Identifier.ValueText)).ToHashSet();
            foreach (string file in files.Where(file => !IsHeaderTypesFile(file))
                .OrderBy(file => file, StringComparer.OrdinalIgnoreCase))
            {
                string source = File.ReadAllText(file);
                if (!source.Contains("enum", StringComparison.Ordinal))
                    continue;
                var root = CSharpSyntaxTree.ParseText(source, path: file).GetRoot();
                var identities = new HashSet<(string, string)>();
                foreach (var declaration in root.DescendantNodes().OfType<EnumDeclarationSyntax>())
                {
                    if (declaration.Parent is not BaseNamespaceDeclarationSyntax and not CompilationUnitSyntax)
                        continue;
                    string ns = GetNamespace(declaration);
                    if (!headerGroups.Contains((ns, declaration.Identifier.ValueText)))
                        continue;
                    if (!identities.Add((ns, declaration.Identifier.ValueText)))
                        throw Error(file, declaration.Identifier.ValueText,
                            "Distinct declarations project to the same logical group in one source file.");
                    roots.TryAdd(file, root);
                    fragments.Add(new Fragment(file, ns, declaration,
                        architecture == "crossarch" ? GetArchitectures(file, fileSet) : Architecture.All, false));
                }
            }

            var targets = new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 };
            var groups = fragments.GroupBy(fragment => (fragment.Namespace, fragment.Declaration.Identifier.ValueText))
                .Where(group => targets.Any(target => group.Count(fragment => fragment.Architectures.HasFlag(target)) > 1))
                .OrderBy(group => group.Key.Namespace, StringComparer.Ordinal)
                .ThenBy(group => group.Key.ValueText, StringComparer.Ordinal).ToArray();
            if (groups.Length == 0)
                return;

            var legacySources = groups.Any(group => group.Any(fragment => !fragment.HeaderDefined))
                ? ReadLegacySources(files, roots, sourceEnumMembers) : null;
            var removed = groups.SelectMany(group => group).Select(fragment => fragment.Declaration).ToHashSet();
            foreach (var pair in roots)
            {
                var declarations = pair.Value.DescendantNodes().OfType<EnumDeclarationSyntax>().Where(removed.Contains).ToArray();
                if (declarations.Length != 0)
                    File.WriteAllText(pair.Key, pair.Value.RemoveNodes(declarations, SyntaxRemoveOptions.KeepExteriorTrivia).ToFullString());
            }

            foreach (var target in architecture == "crossarch" ? targets : new[] { Architecture.All })
            {
                var legacyCompilation = legacySources == null ? null : CSharpCompilation.Create("LegacyHeaderEnumGroups",
                    legacySources.Where(pair => target == Architecture.All || GetArchitectures(pair.Key, fileSet).HasFlag(target))
                        .Select(pair => pair.Value),
                    new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
                var pending = groups.Select(group => group.Where(fragment =>
                        target == Architecture.All || fragment.Architectures.HasFlag(target))
                    .OrderBy(fragment => fragment.HeaderDefined ? 0 : 1)
                    .ThenBy(fragment => fragment.Architectures == Architecture.All ? 0 : 1).ToArray())
                    .Where(group => group.Length != 0).ToList();
                var merged = new Dictionary<(string Namespace, string Name), EnumDeclarationSyntax>();
                while (pending.Count != 0)
                {
                    int countBefore = pending.Count;
                    var failures = new List<LegacyValueEvaluationException>();
                    foreach (var group in pending.ToArray())
                    {
                        EnumDeclarationSyntax declaration;
                        try
                        {
                            declaration = MergeGroup(group, legacyCompilation);
                        }
                        catch (LegacyValueEvaluationException failure)
                        {
                            // A referenced logical group may still need composition.
                            failures.Add(failure);
                            continue;
                        }
                        merged.Add((group[0].Namespace, declaration.Identifier.ValueText), declaration);
                        if (legacyCompilation != null)
                            legacyCompilation = ReplaceGroup(legacyCompilation, group, group[0], declaration);
                        pending.Remove(group);
                    }
                    if (pending.Count == countBefore)
                        throw new InvalidOperationException(string.Join(Environment.NewLine, failures.Select(failure => failure.Message)),
                            failures[0]);
                }
                var members = new List<MemberDeclarationSyntax>();
                foreach (var ns in groups.GroupBy(group => group.Key.Namespace))
                {
                    var declarations = ns.Where(group => merged.ContainsKey(group.Key))
                        .Select(group => merged[group.Key]).ToArray();
                    if (ns.Key.Length == 0)
                        members.AddRange(declarations);
                    else
                        members.Add(SyntaxFactory.NamespaceDeclaration(SyntaxFactory.ParseName(ns.Key)).AddMembers(declarations));
                }
                string directory = architecture == "crossarch" ? Path.Combine(objDir, target.ToString().ToLowerInvariant()) : objDir;
                Directory.CreateDirectory(directory);
                string path = Path.Combine(directory, "header-enum-groups.modified.cs");
                File.WriteAllText(path, SyntaxFactory.CompilationUnit().AddUsings(SyntaxFactory.UsingDirective(
                        SyntaxFactory.ParseName("Windows.Win32.Foundation.Metadata"))).AddMembers(members.ToArray())
                    .NormalizeWhitespace().ToFullString() + Environment.NewLine);
                files.Add(path);
            }
        }

        internal static bool IsHeaderTypesFile(string path)
        {
            string name = Path.GetFileName(path);
            return name == "header-types.modified.cs" || name.EndsWith(".header-types.modified.cs", StringComparison.Ordinal);
        }

        internal static bool IsHeaderEnumSourceFile(string path)
            => IsHeaderTypesFile(path) || Path.GetFileName(path) == "header-enum-groups.modified.cs";

        internal static void ValidateAssociations(CSharpCompilation compilation, string architecture)
        {
            var enums = new HashSet<INamedTypeSymbol>(SymbolEqualityComparer.Default);
            foreach (var tree in compilation.SyntaxTrees)
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                    if (model.GetDeclaredSymbol(declaration) is INamedTypeSymbol symbol)
                        enums.Add(symbol);
            }
            var simpleNames = enums.ToLookup(symbol => ClangSharpSourceWinmdGenerator.FixArchSpecificName(symbol.Name), StringComparer.Ordinal);
            var fullNames = enums.ToLookup(symbol => ClangSharpSourceWinmdGenerator.FixArchSpecificName(symbol.ToDisplayString()), StringComparer.Ordinal);
            var targets = architecture switch
            {
                "x86" => new[] { Architecture.X86 },
                "x64" => new[] { Architecture.X64 },
                "arm64" => new[] { Architecture.Arm64 },
                _ => new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 },
            };
            var errors = new List<string>();
            foreach (var tree in compilation.SyntaxTrees)
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var attribute in tree.GetRoot().DescendantNodes().OfType<AttributeSyntax>())
                {
                    if (attribute.Name.ToString().Split('.').Last() is not "AssociatedEnum" and not "AssociatedEnumAttribute" ||
                        model.GetSymbolInfo(attribute).Symbol is not IMethodSymbol constructor ||
                        constructor.ContainingType.ToDisplayString() != "Windows.Win32.Foundation.Metadata.AssociatedEnumAttribute")
                        continue;
                    var arguments = attribute.ArgumentList?.Arguments;
                    if (arguments?.Count != 1 || model.GetConstantValue(arguments.Value[0].Expression).Value is not string name ||
                        name.Length == 0)
                    {
                        errors.Add(Error(tree.FilePath, attribute.Parent.Parent.ToString(),
                            "AssociatedEnum requires one nonempty enum name.").Message);
                        continue;
                    }
                    var declaration = attribute.Parent.Parent;
                    var owner = declaration is FieldDeclarationSyntax field
                        ? model.GetDeclaredSymbol(field.Declaration.Variables.First()) : model.GetDeclaredSymbol(declaration);
                    if (owner == null)
                        throw Error(tree.FilePath, name, "Cannot resolve the native association's emitted owner.");
                    var candidates = (name.Contains('.', StringComparison.Ordinal) ? fullNames[name] : simpleNames[name]).ToArray();
                    var ownerArchitectures = GetSupportedArchitectures(owner);
                    foreach (var target in targets.Where(target => ownerArchitectures.HasFlag(target)))
                    {
                        var matching = candidates.Where(candidate => GetSupportedArchitectures(candidate).HasFlag(target)).ToArray();
                        if (matching.Length == 1)
                            continue;
                        var location = attribute.GetLocation().GetLineSpan().StartLinePosition;
                        string found = matching.Length == 0 ? "none" : string.Join(", ",
                            matching.Select(candidate => candidate.ToDisplayString()).OrderBy(value => value, StringComparer.Ordinal));
                        errors.Add(Error(tree.FilePath + $"({location.Line + 1},{location.Character + 1})", name,
                            $"AssociatedEnum must identify exactly one emitted enum after composition for {target}; found {matching.Length}: {found}.").Message);
                    }
                }
            }
            if (errors.Count != 0)
                throw new InvalidOperationException(string.Join(Environment.NewLine, errors));
        }

        private static Architecture GetSupportedArchitectures(ISymbol symbol)
        {
            var mask = Architecture.All;
            for (var current = symbol; current != null; current = current.ContainingSymbol)
                foreach (var attribute in current.GetAttributes().Where(attribute =>
                    attribute.AttributeClass?.ToDisplayString() == "Windows.Win32.Foundation.Metadata.SupportedArchitectureAttribute"))
                {
                    if (attribute.ConstructorArguments.Length != 1 || attribute.ConstructorArguments[0].Value is not int value ||
                        value <= 0 || (value & ~(int)Architecture.All) != 0)
                        throw Error(symbol.Locations.FirstOrDefault()?.SourceTree?.FilePath ?? "", symbol.Name,
                            "Invalid supported architecture mask on an enum association.");
                    mask &= (Architecture)value;
                }
            return mask;
        }

        internal static CSharpCompilation ConvertPrimitiveConstantAliases(CSharpCompilation compilation, bool writeModifiedFiles = true)
        {
            var groups = new HashSet<INamedTypeSymbol>(SymbolEqualityComparer.Default);
            var constants = new List<IFieldSymbol>();
            foreach (var tree in compilation.SyntaxTrees)
            {
                var model = compilation.GetSemanticModel(tree);
                bool headerGroup = IsHeaderEnumSourceFile(tree.FilePath);
                foreach (var node in tree.GetRoot().DescendantNodes())
                {
                    if (headerGroup && node is EnumDeclarationSyntax declaration &&
                        model.GetDeclaredSymbol(declaration) is INamedTypeSymbol symbol &&
                        !symbol.GetAttributes().Any(attribute =>
                            attribute.AttributeClass?.ToDisplayString() == "Windows.Win32.Foundation.Metadata.ScopedEnumAttribute"))
                        groups.Add(symbol);
                    if (node is FieldDeclarationSyntax field && field.Parent is ClassDeclarationSyntax owner &&
                        owner.Identifier.ValueText == "Apis" && field.Modifiers.Any(SyntaxKind.ConstKeyword))
                        foreach (var variable in field.Declaration.Variables)
                            if (model.GetDeclaredSymbol(variable) is IFieldSymbol constant)
                                constants.Add(constant);
                }
            }

            var members = constants.Concat(groups.SelectMany(type => type.GetMembers().OfType<IFieldSymbol>())
                .Where(member => member.HasConstantValue)).ToLookup(member => member.Name, StringComparer.Ordinal);
            var converted = compilation;
            foreach (var tree in compilation.SyntaxTrees)
            {
                var root = tree.GetRoot();
                var aliases = root.DescendantNodes().OfType<FieldDeclarationSyntax>()
                    .Where(field => field.Modifiers.Any(SyntaxKind.ConstKeyword))
                    .SelectMany(field => field.Declaration.Variables).Where(variable => variable.Initializer != null).ToArray();
                if (aliases.Length == 0)
                    continue;
                var model = compilation.GetSemanticModel(tree);
                var replacements = new Dictionary<ExpressionSyntax, ExpressionSyntax>();
                foreach (var alias in aliases)
                {
                    if (model.GetDeclaredSymbol(alias) is not IFieldSymbol field)
                        continue;
                    var value = alias.Initializer.Value;
                    bool integral = field.Type.SpecialType is SpecialType.System_SByte or SpecialType.System_Byte or
                        SpecialType.System_Int16 or SpecialType.System_UInt16 or SpecialType.System_Char or
                        SpecialType.System_Int32 or SpecialType.System_UInt32 or
                        SpecialType.System_Int64 or SpecialType.System_UInt64;
                    var operands = new Dictionary<ExpressionSyntax, ExpressionSyntax>();
                    bool enumOperand = false;
                    foreach (var operand in value.DescendantNodesAndSelf().OfType<ExpressionSyntax>()
                        .Where(node => node is IdentifierNameSyntax or MemberAccessExpressionSyntax))
                    {
                        if (operand is IdentifierNameSyntax name &&
                            (name.Parent is MemberAccessExpressionSyntax or QualifiedNameSyntax or AliasQualifiedNameSyntax or
                                TypeArgumentListSyntax or ArrayTypeSyntax or PointerTypeSyntax or NullableTypeSyntax or
                                TypeOfExpressionSyntax or SizeOfExpressionSyntax ||
                             name.Parent is CastExpressionSyntax cast && cast.Type == name))
                            continue;
                        var info = model.GetSymbolInfo(operand);
                        var member = info.Symbol as IFieldSymbol;
                        if (member == null)
                        {
                            if (operand is not IdentifierNameSyntax identifier)
                                continue;
                            var matches = members[identifier.Identifier.ValueText].ToArray();
                            if (matches.Length != 1)
                                continue;
                            member = matches[0];
                            var namedType = info.Symbol as INamedTypeSymbol;
                            if (namedType == null && info.CandidateReason == CandidateReason.NotAValue &&
                                info.CandidateSymbols.Length == 1)
                                namedType = info.CandidateSymbols[0] as INamedTypeSymbol;
                            bool groupNameInValueContext = groups.Contains(member.ContainingType) &&
                                namedType?.TypeKind == TypeKind.Enum &&
                                SymbolEqualityComparer.Default.Equals(namedType.ContainingNamespace, member.ContainingNamespace);
                            if ((info.Symbol != null || info.CandidateSymbols.Length != 0) && !groupNameInValueContext)
                                continue;
                        }
                        ExpressionSyntax replacement = SyntaxFactory.ParseExpression(QualifiedFieldName(member));
                        if (member.ContainingType.TypeKind == TypeKind.Enum)
                        {
                            if (!integral || !member.HasConstantValue || !groups.Contains(member.ContainingType))
                                continue;
                            // Header-defined logical groups preserve native scalar arithmetic.
                            var storage = SyntaxFactory.ParseTypeName(member.ContainingType.EnumUnderlyingType
                                .ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat));
                            replacement = SyntaxFactory.ParenthesizedExpression(SyntaxFactory.CastExpression(storage, replacement));
                            enumOperand = true;
                        }
                        else if (info.Symbol != null)
                            continue;
                        operands.Add(operand, replacement.WithTriviaFrom(operand));
                    }
                    if (operands.Count == 0)
                        continue;
                    var expression = value.ReplaceNodes(operands.Keys, (original, _) => operands[original]);
                    if (enumOperand)
                    {
                        var type = ((VariableDeclarationSyntax)alias.Parent).Type.WithoutTrivia();
                        // Lowering must not change scalar storage or hide constant overflow.
                        expression = SyntaxFactory.CheckedExpression(SyntaxKind.CheckedExpression,
                            SyntaxFactory.CastExpression(type, SyntaxFactory.ParenthesizedExpression(expression.WithoutTrivia())));
                    }
                    replacements.Add(value, expression.WithTriviaFrom(value));
                }
                if (replacements.Count == 0)
                    continue;

                var rewritten = tree.WithRootAndOptions(root.ReplaceNodes(replacements.Keys,
                    (original, _) => replacements[original]), tree.Options);
                if (writeModifiedFiles)
                    File.WriteAllText(tree.FilePath, rewritten.GetText().ToString());
                converted = converted.ReplaceSyntaxTree(tree, rewritten);
            }
            return converted;
        }

        private static string QualifiedFieldName(IFieldSymbol field)
        {
            string name = SyntaxFacts.GetKeywordKind(field.Name) == SyntaxKind.None ? field.Name : "@" + field.Name;
            return field.ContainingType.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat) + "." + name;
        }

        internal static Architecture GetArchitectures(string file, HashSet<string> files)
        {
            var architecture = ClangSharpSourceCompilation.GetArchitectureForFileName(file);
            if (architecture == Architecture.None)
                return Architecture.All;
            if (architecture != Architecture.X86)
                return architecture;

            // An x86-only partition is the pipeline's existing representation of common input.
            foreach (string other in new[] { "x64", "arm64" })
            {
                string sibling = file.Replace(@"\x86\", $@"\{other}\", StringComparison.OrdinalIgnoreCase);
                if (files.Contains(sibling))
                    return Architecture.X86;
                if (Path.GetFileName(file) == "header-types.modified.cs")
                {
                    if (files.Any(path => string.Equals(Path.GetDirectoryName(path), Path.GetDirectoryName(sibling), StringComparison.OrdinalIgnoreCase)))
                        return Architecture.X86;
                }
                else if (files.Contains(sibling.Replace(".header-types.modified.cs", ".modified.cs", StringComparison.Ordinal)))
                    return Architecture.X86;
            }
            return Architecture.All;
        }

        private static string GetNamespace(EnumDeclarationSyntax declaration)
            => string.Join(".", declaration.Ancestors().OfType<BaseNamespaceDeclarationSyntax>()
                .Reverse().Select(parent => parent.Name.ToString()));

        private static Dictionary<string, SyntaxTree> ReadLegacySources(List<string> files, Dictionary<string, SyntaxNode> roots,
            HashSet<string> sourceEnumMembers)
        {
            var sources = files.ToDictionary(file => file,
                file => roots.TryGetValue(file, out var root) ? root.SyntaxTree :
                    CSharpSyntaxTree.ParseText(File.ReadAllText(file), path: file),
                StringComparer.OrdinalIgnoreCase);
            var enumMembers = sources.Values.SelectMany(tree => tree.GetRoot().DescendantNodes()
                .OfType<EnumMemberDeclarationSyntax>()).Select(member =>
                    MetadataSyntaxTreeCleaner.GetEnumMemberIdentity(member, member.Identifier.ValueText)).ToHashSet(StringComparer.Ordinal);
            enumMembers.UnionWith(sourceEnumMembers);
            foreach (string file in files)
            {
                var tree = sources[file];
                var root = tree.GetRoot();
                var looseConstants = root.DescendantNodes().OfType<FieldDeclarationSyntax>()
                    .Where(field => MetadataSyntaxTreeCleaner.IsEnumMemberConstant(field, enumMembers)).ToArray();
                if (looseConstants.Length != 0)
                    sources[file] = tree.WithRootAndOptions(root.RemoveNodes(looseConstants, SyntaxRemoveOptions.KeepExteriorTrivia), tree.Options);
            }
            return sources;
        }

        private static EnumDeclarationSyntax MergeGroup(Fragment[] fragments, CSharpCompilation legacyCompilation)
        {
            fragments = fragments.Select(fragment => fragment.HeaderDefined ? fragment :
                ReadLegacyGroup(fragment, fragments, legacyCompilation)).ToArray();
            var first = fragments[0];
            string name = first.Declaration.Identifier.ValueText;
            string storage = first.Declaration.BaseList?.Types.Single().Type.WithoutTrivia().NormalizeWhitespace().ToFullString();
            bool flags = HasFlags(first.Declaration);
            var members = new Dictionary<string, EnumMemberDeclarationSyntax>(StringComparer.Ordinal);
            var attributes = new List<AttributeSyntax>();
            foreach (var fragment in fragments)
            {
                var declaration = fragment.Declaration;
                if (storage != declaration.BaseList?.Types.Single().Type.WithoutTrivia().NormalizeWhitespace().ToFullString())
                    throw Error(fragment.File, name, "Conflicting logical group storage types.");
                if (flags != HasFlags(declaration))
                    throw Error(fragment.File, name, "Conflicting logical group flags semantics.");
                foreach (var attributeGroup in declaration.AttributeLists.SelectMany(list => list.Attributes)
                    .Select(attribute => IsFlags(attribute) ?
                        attribute.WithName(SyntaxFactory.ParseName("global::System.Flags")) : attribute)
                    .GroupBy(AttributeText, StringComparer.Ordinal))
                {
                    var attribute = attributeGroup.First();
                    string attributeName = attribute.Name.ToString();
                    if (!attributeName.EndsWith(".AssociatedConstant", StringComparison.Ordinal) &&
                        attributes.Any(existing => existing.Name.ToString() == attributeName && AttributeText(existing) != attributeGroup.Key))
                        throw Error(fragment.File, name, $"Conflicting '{attributeName}' annotations.");
                    int count = attributes.Count(existing => AttributeText(existing) == attributeGroup.Key);
                    for (int i = count; i < attributeGroup.Count(); i++)
                        attributes.Add(attribute);
                }
                var names = new HashSet<string>(StringComparer.Ordinal);
                foreach (var member in declaration.Members)
                {
                    string memberName = member.Identifier.ValueText;
                    if (member.EqualsValue == null || !names.Add(memberName))
                        throw Error(fragment.File, name, $"Logical group member '{memberName}' requires one explicit compiled value.");
                    if (members.TryGetValue(memberName, out var existing))
                    {
                        if (ReadValue(existing, storage, fragment) != ReadValue(member, storage, fragment) ||
                            MemberText(existing) != MemberText(member))
                            throw Error(fragment.File, name, $"Conflicting logical group values for '{memberName}'.");
                    }
                    else
                    {
                        ReadValue(member, storage, fragment);
                        members.Add(memberName, member);
                    }
                }
            }
            return first.Declaration.WithoutTrivia().WithAttributeLists(SyntaxFactory.List(attributes.Select(attribute =>
                    SyntaxFactory.AttributeList(SyntaxFactory.SingletonSeparatedList(attribute.WithoutTrivia())))))
                .WithMembers(SyntaxFactory.SeparatedList(members.Values.Select(member => member.WithoutTrivia())));
        }

        private static CSharpCompilation ReplaceGroup(CSharpCompilation compilation, Fragment[] fragments,
            Fragment selected, EnumDeclarationSyntax declaration)
        {
            var groupFiles = fragments.Select(part => part.File).ToHashSet(StringComparer.OrdinalIgnoreCase);
            foreach (var source in compilation.SyntaxTrees.Where(source => groupFiles.Contains(source.FilePath)).ToArray())
            {
                var root = source.GetRoot();
                var declarations = root.DescendantNodes().OfType<EnumDeclarationSyntax>()
                    .Where(node => node.Identifier.ValueText == declaration.Identifier.ValueText &&
                        GetNamespace(node) == selected.Namespace).ToArray();
                bool keep = string.Equals(source.FilePath, selected.File, StringComparison.OrdinalIgnoreCase);
                var rewritten = source.WithRootAndOptions(keep ? root.ReplaceNode(declarations.Single(), declaration) :
                    root.RemoveNodes(declarations, SyntaxRemoveOptions.KeepExteriorTrivia), source.Options);
                compilation = compilation.ReplaceSyntaxTree(source, rewritten);
            }
            return compilation;
        }

        private static Fragment ReadLegacyGroup(Fragment fragment, Fragment[] fragments, CSharpCompilation compilation)
        {
            var declaration = fragment.Declaration;
            var probe = declaration.WithAttributeLists(SyntaxFactory.List(declaration.AttributeLists.Select(list =>
                    list.WithAttributes(SyntaxFactory.SeparatedList(list.Attributes.Where(IsFlags))))
                .Where(list => list.Attributes.Count != 0))).WithMembers(SyntaxFactory.SeparatedList(
                    declaration.Members.Select(member => member.WithAttributeLists(default))));
            compilation = ReplaceGroup(compilation, fragments, fragment, probe);
            var tree = compilation.SyntaxTrees.Single(source =>
                string.Equals(source.FilePath, fragment.File, StringComparison.OrdinalIgnoreCase));
            probe = tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>().Single(node =>
                node.Identifier.ValueText == declaration.Identifier.ValueText && GetNamespace(node) == fragment.Namespace);
            var model = compilation.GetSemanticModel(tree);
            var flags = probe.AttributeLists.SelectMany(list => list.Attributes).Where(IsFlags).ToArray();
            if (flags.Length != 0)
            {
                foreach (var attribute in flags)
                {
                    if (model.GetSymbolInfo(attribute).Symbol is not IMethodSymbol constructor ||
                        constructor.ContainingType.ToDisplayString() != "System.FlagsAttribute" ||
                        !SymbolEqualityComparer.Default.Equals(constructor.ContainingAssembly,
                            compilation.GetSpecialType(SpecialType.System_Object).ContainingAssembly))
                        throw Error(fragment.File, declaration.Identifier.ValueText,
                            "A legacy Flags annotation must resolve to System.FlagsAttribute.");
                }
            }
            // Other raw groups still need composition; the final compilation checks all source diagnostics.
            var error = model.GetDiagnostics(probe.Span).FirstOrDefault(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error);
            if (error != null)
                throw new LegacyValueEvaluationException(Error(fragment.File, declaration.Identifier.ValueText,
                    $"Legacy group values could not be evaluated: {error.GetMessage()}").Message);
            var symbol = model.GetDeclaredSymbol(probe) as INamedTypeSymbol;
            string storage = symbol?.EnumUnderlyingType?.SpecialType switch
            {
                SpecialType.System_SByte => "sbyte",
                SpecialType.System_Byte => "byte",
                SpecialType.System_Int16 => "short",
                SpecialType.System_UInt16 => "ushort",
                SpecialType.System_Int32 => "int",
                SpecialType.System_UInt32 => "uint",
                SpecialType.System_Int64 => "long",
                SpecialType.System_UInt64 => "ulong",
                _ => throw Error(fragment.File, declaration.Identifier.ValueText, "Invalid legacy group storage."),
            };
            var members = new List<EnumMemberDeclarationSyntax>();
            for (int i = 0; i < declaration.Members.Count; i++)
            {
                var member = declaration.Members[i];
                if (model.GetDeclaredSymbol(probe.Members[i]) is not IFieldSymbol { HasConstantValue: true } field)
                    throw new LegacyValueEvaluationException(Error(fragment.File, declaration.Identifier.ValueText,
                        $"Legacy group member '{member.Identifier.ValueText}' requires a compiled integral value.").Message);
                ulong value = field.ConstantValue switch
                {
                    sbyte number => unchecked((ulong)number),
                    byte number => number,
                    short number => unchecked((ulong)number),
                    ushort number => number,
                    int number => unchecked((ulong)number),
                    uint number => number,
                    long number => unchecked((ulong)number),
                    ulong number => number,
                    _ => throw Error(fragment.File, declaration.Identifier.ValueText,
                        $"Invalid legacy group value for '{member.Identifier.ValueText}'."),
                };
                members.Add(member.WithEqualsValue(SyntaxFactory.EqualsValueClause(
                    SyntaxFactory.CheckedExpression(SyntaxKind.UncheckedExpression,
                        SyntaxFactory.CastExpression(SyntaxFactory.ParseTypeName(storage),
                            SyntaxFactory.LiteralExpression(SyntaxKind.NumericLiteralExpression, SyntaxFactory.Literal(value)))))));
            }
            return fragment with
            {
                Declaration = declaration.WithBaseList(SyntaxFactory.BaseList(SyntaxFactory.SingletonSeparatedList<BaseTypeSyntax>(
                    SyntaxFactory.SimpleBaseType(SyntaxFactory.ParseTypeName(storage)))))
                    .WithMembers(SyntaxFactory.SeparatedList(members)),
            };
        }

        private static bool HasFlags(EnumDeclarationSyntax declaration)
            => declaration.AttributeLists.SelectMany(list => list.Attributes).Any(IsFlags);

        private static bool IsFlags(AttributeSyntax attribute)
            => attribute.Name.ToString() is "global::System.Flags" or "System.Flags" or "Flags" or
                "global::System.FlagsAttribute" or "System.FlagsAttribute" or "FlagsAttribute";

        private static string AttributeText(AttributeSyntax attribute)
            => attribute.WithoutTrivia().NormalizeWhitespace().ToFullString();

        private static string MemberText(EnumMemberDeclarationSyntax member)
            => member.WithEqualsValue(null).WithoutTrivia().NormalizeWhitespace().ToFullString();

        private static ulong ReadValue(EnumMemberDeclarationSyntax member, string storage, Fragment fragment)
        {
            if (member.EqualsValue?.Value is not CheckedExpressionSyntax expression ||
                !expression.IsKind(SyntaxKind.UncheckedExpression) ||
                expression.Expression is not CastExpressionSyntax cast || cast.Type.ToString() != storage ||
                cast.Expression is not LiteralExpressionSyntax literal || literal.Token.Value is not ulong value)
                throw Error(fragment.File, fragment.Declaration.Identifier.ValueText,
                    $"Logical group member '{member.Identifier.ValueText}' must retain its compiler-evaluated integral value.");
            int width = storage switch
            {
                "sbyte" or "byte" => 8,
                "short" or "ushort" or "char" => 16,
                "int" or "uint" => 32,
                "long" or "ulong" => 64,
                _ => throw Error(fragment.File, fragment.Declaration.Identifier.ValueText, $"Invalid logical group storage '{storage}'."),
            };
            return value & (ulong.MaxValue >> (64 - width));
        }

        private static InvalidOperationException Error(string file, string name, string message)
            => new($"{file}: error WMA003: Logical group '{name}': {message}");

        private sealed class LegacyValueEvaluationException : InvalidOperationException
        {
            internal LegacyValueEvaluationException(string message) : base(message) { }
        }

        private sealed record Fragment(string File, string Namespace, EnumDeclarationSyntax Declaration,
            Architecture Architectures, bool HeaderDefined = true);
    }
}
