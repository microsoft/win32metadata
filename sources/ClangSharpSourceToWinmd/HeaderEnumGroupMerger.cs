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
        internal static void Merge(List<string> files, string objDir, string architecture)
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
                    string ns = string.Join(".", declaration.Ancestors().OfType<BaseNamespaceDeclarationSyntax>()
                        .Reverse().Select(parent => parent.Name.ToString()));
                    if (!identities.Add((ns, declaration.Identifier.ValueText)))
                        throw Error(file, declaration.Identifier.ValueText, "Distinct native declarations project to the same logical group in one translation unit.");
                    fragments.Add(new Fragment(file, ns, declaration,
                        architecture == "crossarch" ? GetArchitectures(file, fileSet) : Architecture.All));
                }
            }

            var targets = new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 };
            var groups = fragments.GroupBy(fragment => (fragment.Namespace, fragment.Declaration.Identifier.ValueText))
                .Where(group => targets.Any(target => group.Count(fragment => fragment.Architectures.HasFlag(target)) > 1))
                .OrderBy(group => group.Key.Namespace, StringComparer.Ordinal)
                .ThenBy(group => group.Key.ValueText, StringComparer.Ordinal).ToArray();
            if (groups.Length == 0)
                return;

            var removed = groups.SelectMany(group => group).Select(fragment => fragment.Declaration).ToHashSet();
            foreach (var pair in roots)
            {
                var declarations = pair.Value.DescendantNodes().OfType<EnumDeclarationSyntax>().Where(removed.Contains).ToArray();
                if (declarations.Length != 0)
                    File.WriteAllText(pair.Key, pair.Value.RemoveNodes(declarations, SyntaxRemoveOptions.KeepExteriorTrivia).ToFullString());
            }

            foreach (var target in architecture == "crossarch" ? targets : new[] { Architecture.All })
            {
                var members = new List<MemberDeclarationSyntax>();
                foreach (var ns in groups.GroupBy(group => group.Key.Namespace))
                {
                    var declarations = ns.Select(group => group.Where(fragment =>
                            target == Architecture.All || fragment.Architectures.HasFlag(target))
                        .OrderBy(fragment => fragment.Architectures == Architecture.All ? 0 : 1).ToArray())
                        .Where(group => group.Length != 0).Select(MergeGroup).ToArray();
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

        internal static CSharpCompilation ConvertPrimitiveConstantAliases(CSharpCompilation compilation)
        {
            var groups = new HashSet<INamedTypeSymbol>(SymbolEqualityComparer.Default);
            foreach (var tree in compilation.SyntaxTrees.Where(tree => IsHeaderTypesFile(tree.FilePath) ||
                Path.GetFileName(tree.FilePath) == "header-enum-groups.modified.cs"))
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                    if (model.GetDeclaredSymbol(declaration) is INamedTypeSymbol symbol)
                        groups.Add(symbol);
            }
            if (groups.Count == 0)
                return compilation;

            var members = groups.SelectMany(group => group.GetMembers().OfType<IFieldSymbol>())
                .Where(member => member.HasConstantValue).ToLookup(member => member.Name, StringComparer.Ordinal);
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
                    if (model.GetDeclaredSymbol(alias) is not IFieldSymbol field ||
                        field.Type.SpecialType is not (SpecialType.System_SByte or SpecialType.System_Byte or
                            SpecialType.System_Int16 or SpecialType.System_UInt16 or SpecialType.System_Char or
                            SpecialType.System_Int32 or SpecialType.System_UInt32 or
                            SpecialType.System_Int64 or SpecialType.System_UInt64))
                        continue;
                    var value = alias.Initializer.Value;
                    var expression = value;
                    if (model.GetTypeInfo(value).Type is not INamedTypeSymbol source || !groups.Contains(source) ||
                        !model.GetConstantValue(value).HasValue)
                    {
                        while (expression is ParenthesizedExpressionSyntax parenthesized)
                            expression = parenthesized.Expression;
                        if (expression is not IdentifierNameSyntax identifier)
                            continue;
                        var info = model.GetSymbolInfo(identifier);
                        var matches = members[identifier.Identifier.ValueText].ToArray();
                        if (matches.Length != 1)
                            continue;

                        // The cleaner removed the loose copy of this uniquely owned group member.
                        var member = matches[0];
                        var namedType = info.Symbol as INamedTypeSymbol;
                        if (namedType == null && info.CandidateReason == CandidateReason.NotAValue && info.CandidateSymbols.Length == 1)
                            namedType = info.CandidateSymbols[0] as INamedTypeSymbol;
                        bool enumNameInValueContext = namedType?.TypeKind == TypeKind.Enum &&
                            SymbolEqualityComparer.Default.Equals(namedType.ContainingNamespace, member.ContainingNamespace);
                        if ((info.Symbol != null || info.CandidateSymbols.Length != 0) && !enumNameInValueContext)
                            continue;
                        string name = SyntaxFacts.GetKeywordKind(member.Name) == SyntaxKind.None ? member.Name : "@" + member.Name;
                        expression = value.ReplaceNode(identifier, SyntaxFactory.ParseExpression(
                            member.ContainingType.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat) + "." + name)
                            .WithTriviaFrom(identifier));
                    }
                    var type = ((VariableDeclarationSyntax)alias.Parent).Type.WithoutTrivia();
                    // Metadata-only groups must not change scalar types or hide constant overflow.
                    replacements.Add(value, SyntaxFactory.CheckedExpression(SyntaxKind.CheckedExpression,
                        SyntaxFactory.CastExpression(type, SyntaxFactory.ParenthesizedExpression(expression.WithoutTrivia())))
                        .WithTriviaFrom(value));
                }
                if (replacements.Count == 0)
                    continue;

                var rewritten = tree.WithRootAndOptions(root.ReplaceNodes(replacements.Keys,
                    (original, _) => replacements[original]), tree.Options);
                File.WriteAllText(tree.FilePath, rewritten.GetText().ToString());
                converted = converted.ReplaceSyntaxTree(tree, rewritten);
            }
            return converted;
        }

        private static Architecture GetArchitectures(string file, HashSet<string> files)
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

        private static EnumDeclarationSyntax MergeGroup(Fragment[] fragments)
        {
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

        private static bool HasFlags(EnumDeclarationSyntax declaration)
            => declaration.AttributeLists.SelectMany(list => list.Attributes).Any(attribute =>
                attribute.Name.ToString() is "global::System.Flags" or "System.Flags" or "Flags");

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

        private sealed record Fragment(string File, string Namespace, EnumDeclarationSyntax Declaration, Architecture Architectures);
    }
}
