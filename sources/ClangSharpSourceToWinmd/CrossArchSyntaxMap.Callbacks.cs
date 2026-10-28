using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.RegularExpressions;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace ClangSharpSourceToWinmd
{
    public partial class CrossArchSyntaxMap
    {
        private readonly Dictionary<(string Path, Architecture Architecture, int Position), string> callbackReferences = new();
        private readonly HashSet<string> callbackDependentTrees = new(StringComparer.OrdinalIgnoreCase);

        internal bool HasCallbackDependencies(string path) => this.callbackDependentTrees.Contains(path);

        internal string GetCallbackReference(SyntaxTree tree, Architecture architecture, int position)
            => this.callbackReferences.TryGetValue((tree.FilePath, architecture, position), out string name) ? name : null;

        internal void BindCallbackReferences(IEnumerable<SyntaxTree> additionalTrees, IEnumerable<MetadataReference> references)
        {
            SyntaxTree[] trees = this.sourceTrees.Values.Concat(additionalTrees ?? Array.Empty<SyntaxTree>())
                .GroupBy(tree => tree.FilePath, StringComparer.OrdinalIgnoreCase).Select(group => group.Last()).ToArray();
            var affected = new HashSet<string>(trees.SelectMany(tree => tree.GetRoot().DescendantNodes()
                    .Where(node => node is DelegateDeclarationSyntax or StructDeclarationSyntax)).Select(GetFullName)
                .Where(name => this.namesToInfos.TryGetValue(name, out var groups) && groups.Count > 1),
                StringComparer.Ordinal);
            if (affected.Count == 0)
                return;

            var paths = new HashSet<string>(trees.Select(tree => tree.FilePath), StringComparer.OrdinalIgnoreCase);
            var declarations = trees.Where(IsCrossArchTree).Where(tree => GetArchForTree(tree) != Architecture.None)
                .SelectMany(tree => tree.GetRoot().DescendantNodes().Where(IsDeclaration))
                .Where(node => this.namesToInfos.ContainsKey(GetFullName(node))).ToArray();
            var aliases = new HashSet<string>(trees.SelectMany(tree => tree.GetRoot().DescendantNodes()
                .OfType<UsingDirectiveSyntax>()).Where(directive => directive.Alias != null)
                .Select(directive => directive.Alias.Name.Identifier.ValueText), StringComparer.Ordinal);
            var compilations = new Dictionary<Architecture, CSharpCompilation>();
            var models = new Dictionary<SyntaxTree, SemanticModel>();
            var dependencies = new Dictionary<(string Name, Architecture Architecture), HashSet<string>>();
            var bindings = new Dictionary<SimpleNameSyntax, (string Target, bool Alias, string QualifiedName)>();
            bool added;
            do
            {
                added = false;
                var candidates = new HashSet<string>(affected.Select(name => name.Split("::").Last()), StringComparer.Ordinal);
                candidates.UnionWith(aliases);
                foreach (SyntaxNode declaration in declarations)
                {
                    string owner = GetFullName(declaration);
                    Architecture architecture = GetArchForTree(declaration.SyntaxTree);
                    foreach (SimpleNameSyntax reference in declaration.DescendantNodes().OfType<SimpleNameSyntax>()
                        .Where(reference => candidates.Contains(reference.Identifier.ValueText)))
                    {
                        SemanticModel model = Model(declaration.SyntaxTree);
                        var alias = reference is IdentifierNameSyntax identifier ? model.GetAliasInfo(identifier) : null;
                        var type = (alias?.Target ?? model.GetSymbolInfo(reference).Symbol) as INamedTypeSymbol;
                        string target = Target(type);
                        if (target == null)
                            continue;
                        AddDependency(target);
                        bindings[reference] = (target, alias != null,
                            type.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat));
                    }

                    foreach (AttributeSyntax attribute in declaration.DescendantNodes().OfType<AttributeSyntax>()
                        .Where(attribute => attribute.Name.ToString().Split('.').Last() is "NativeTypeName" or "NativeTypeNameAttribute"))
                    {
                        if (attribute.ArgumentList?.Arguments.FirstOrDefault()?.Expression is not LiteralExpressionSyntax literal ||
                            literal.Token.Value is not string nativeName)
                            continue;
                        Match match = Regex.Match(nativeName,
                            @"^\s*(?:(?:const|volatile|struct|union|enum)\s+)*(?<name>[A-Za-z_]\w*(?:(?:::|\.)[A-Za-z_]\w*)*)");
                        string name = match.Groups["name"].Value.Replace("::", ".");
                        if (!candidates.Contains(name.Split('.').Last()))
                            continue;
                        var type = Model(declaration.SyntaxTree).GetSpeculativeTypeInfo(attribute.SpanStart,
                            SyntaxFactory.ParseTypeName(name), SpeculativeBindingOption.BindAsTypeOrNamespace).Type as INamedTypeSymbol;
                        string target = Target(type);
                        if (target != null)
                            AddDependency(target);
                    }

                    void AddDependency(string target)
                    {
                        var key = (owner, architecture);
                        if (!dependencies.TryGetValue(key, out var targets))
                            dependencies.Add(key, targets = new HashSet<string>(StringComparer.Ordinal));
                        targets.Add(target);
                        added |= affected.Add(owner);
                        this.callbackDependentTrees.Add(declaration.SyntaxTree.FilePath);
                    }
                }
            }
            while (added);

            var seeds = affected.ToDictionary(name => name, name => this.namesToInfos[name].ToArray(), StringComparer.Ordinal);
            var current = seeds;
            bool changed;
            do
            {
                changed = false;
                var next = new Dictionary<string, CrossArchInfo[]>(StringComparer.Ordinal);
                foreach (string name in affected)
                {
                    var groups = new List<CrossArchInfo>();
                    for (int seed = 0; seed < seeds[name].Length; seed++)
                    {
                        var fingerprints = new Dictionary<string, CrossArchInfo>(StringComparer.Ordinal);
                        foreach (Architecture architecture in new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
                        {
                            if (!seeds[name][seed].Arch.HasFlag(architecture))
                                continue;
                            string fingerprint = dependencies.TryGetValue((name, architecture), out var targets)
                                ? string.Join(";", targets.OrderBy(target => target, StringComparer.Ordinal)
                                    .Select(target => target + "=" + current[target].Single(group => group.Arch.HasFlag(architecture)).Arch))
                                : string.Empty;
                            if (!fingerprints.TryGetValue(fingerprint, out var group))
                            {
                                group = new CrossArchInfo { FullSignature = seeds[name][seed].FullSignature };
                                fingerprints.Add(fingerprint, group);
                                groups.Add(group);
                            }
                            group.Arch |= architecture;
                        }
                    }
                    next.Add(name, groups.ToArray());
                    changed |= !groups.Select(group => group.Arch).SequenceEqual(current[name].Select(group => group.Arch));
                }
                current = next;
            }
            while (changed);

            foreach (var pair in current)
                this.namesToInfos[pair.Key] = pair.Value.ToList();
            foreach (var pair in bindings)
            {
                Architecture architecture = GetArchForTree(pair.Key.SyntaxTree);
                int ordinal = Array.FindIndex(current[pair.Value.Target], group => group.Arch.HasFlag(architecture));
                if (ordinal <= 0)
                    continue;
                string suffix = "____" + ordinal;
                string replacement = pair.Value.Alias ? pair.Value.QualifiedName + suffix : pair.Key.Identifier.ValueText + suffix;
                this.callbackReferences[(pair.Key.SyntaxTree.FilePath, architecture, pair.Key.SpanStart)] = replacement;
            }

            SemanticModel Model(SyntaxTree tree)
            {
                if (!models.TryGetValue(tree, out var model))
                {
                    Architecture architecture = GetArchForTree(tree);
                    if (!compilations.TryGetValue(architecture, out var compilation))
                    {
                        compilation = ClangSharpSourceCompilation.AddNetstandardReference(CSharpCompilation.Create(
                            "CrossArchCallbacks", trees.Where(candidate =>
                                HeaderEnumGroupMerger.GetArchitectures(candidate.FilePath, paths).HasFlag(architecture)),
                            references ?? new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                            new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true)));
                        compilations.Add(architecture, compilation);
                    }
                    models.Add(tree, model = compilation.GetSemanticModel(tree));
                }
                return model;
            }

            string Target(INamedTypeSymbol type)
            {
                SyntaxNode declaration = type?.OriginalDefinition.DeclaringSyntaxReferences.FirstOrDefault()?.GetSyntax();
                if (declaration == null || !IsDeclaration(declaration))
                    return null;
                string name = GetFullName(declaration);
                return affected.Contains(name) ? name : null;
            }
        }

        private static bool IsDeclaration(SyntaxNode node) => node switch
        {
            StructDeclarationSyntax value => IsPotentialCrossArch(value),
            DelegateDeclarationSyntax value => IsPotentialCrossArch(value),
            EnumDeclarationSyntax value => IsPotentialCrossArch(value),
            MethodDeclarationSyntax value => IsPotentialCrossArch(value),
            FieldDeclarationSyntax value => IsPotentialCrossArch(value),
            _ => false,
        };
    }
}
