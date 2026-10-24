using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using ClangSharp;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed class CompanionImportProjection : CSharpSyntaxRewriter
    {
        private readonly Dictionary<(string File, uint Line, uint Column), FunctionDecl> required = new();
        private readonly HashSet<FunctionDecl> found = new();
        private readonly IReadOnlyDictionary<string, string> libraries;

        private CompanionImportProjection(IEnumerable<FunctionDecl> functions, IReadOnlyDictionary<string, string> libraries)
        {
            this.libraries = libraries;
            foreach (var function in functions)
            {
                function.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                if (!required.TryAdd((file.ToString().ToUpperInvariant(), line, column), function))
                    throw new InvalidOperationException($"ANSI companion imports share an ambiguous native source location: {file}:{line}:{column}.");
            }
        }

        internal static Dictionary<string, string> Select(IReadOnlyDictionary<string, string> sources,
            IEnumerable<FunctionDecl> functions, IReadOnlyDictionary<string, string> libraries)
        {
            var filter = new CompanionImportProjection(functions, libraries);
            var result = new Dictionary<string, string>();
            foreach (var pair in sources)
            {
                var root = (CompilationUnitSyntax)filter.Visit(SyntaxFactory.ParseCompilationUnit(pair.Value));
                if (root.DescendantNodes().OfType<MemberDeclarationSyntax>().Any(member =>
                    member is not MethodDeclarationSyntax and not ClassDeclarationSyntax and
                        not BaseNamespaceDeclarationSyntax))
                    throw new InvalidOperationException("ANSI companion projection contains an unproved non-import declaration.");
                if (root.Members.Count != 0)
                    result.Add(pair.Key, root.NormalizeWhitespace().ToFullString() + Environment.NewLine);
            }
            var missing = filter.required.Values.Except(filter.found).Select(function => function.Name).ToArray();
            if (missing.Length != 0)
                throw new InvalidOperationException("ANSI companion native imports were not projected: " + string.Join(", ", missing));
            return result;
        }

        internal static void ValidateNoCollisions(IEnumerable<string> primarySources, IEnumerable<string> companionSources)
        {
            var primaryMembers = primarySources.Select(source => SyntaxFactory.ParseCompilationUnit(source))
                .SelectMany(root => root.DescendantNodes().OfType<MemberDeclarationSyntax>()).ToArray();
            var primary = primaryMembers
                .SelectMany(member => MemberNames(member).Select(name => (Owner: Owner(member), Name: name)))
                .ToHashSet();
            var nonClassOwners = primaryMembers.OfType<BaseTypeDeclarationSyntax>()
                .Where(type => type is not ClassDeclarationSyntax)
                .Select(type => Owner(type) + "." + type.Identifier.ValueText).ToHashSet(StringComparer.Ordinal);
            var recovered = new HashSet<(string Owner, string Name)>();
            foreach (var method in companionSources.Select(source => SyntaxFactory.ParseCompilationUnit(source))
                .SelectMany(root => root.DescendantNodes().OfType<MethodDeclarationSyntax>()))
            {
                var key = (Owner: Owner(method), Name: method.Identifier.ValueText);
                if (nonClassOwners.Contains(key.Owner) || primary.Contains(key) || !recovered.Add(key))
                    throw new InvalidOperationException($"ANSI companion managed import '{key.Owner}.{key.Name}' " +
                        "collides with another projected member; primary Unicode declarations remain authoritative.");
            }

            static string Owner(SyntaxNode node) => string.Join(".", node.Ancestors().Reverse().Select(ancestor => ancestor switch
            {
                BaseNamespaceDeclarationSyntax space => space.Name.ToString(),
                TypeDeclarationSyntax type => type.Identifier.ValueText,
                _ => null,
            }).Where(name => name != null));

            static IEnumerable<string> MemberNames(MemberDeclarationSyntax member) => member switch
            {
                BaseFieldDeclarationSyntax field => field.Declaration.Variables.Select(variable => variable.Identifier.ValueText),
                BaseTypeDeclarationSyntax type => new[] { type.Identifier.ValueText },
                MethodDeclarationSyntax method => new[] { method.Identifier.ValueText },
                PropertyDeclarationSyntax property => new[] { property.Identifier.ValueText },
                DelegateDeclarationSyntax callable => new[] { callable.Identifier.ValueText },
                EventDeclarationSyntax notification => new[] { notification.Identifier.ValueText },
                _ => Array.Empty<string>(),
            };
        }

        public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
        {
            var location = node.AttributeLists.SelectMany(list => list.Attributes)
                .SingleOrDefault(attribute => attribute.Name.ToString().Split('.').Last() is "SourceLocation" or "SourceLocationAttribute");
            if (location?.ArgumentList?.Arguments.Count != 3)
                return null;
            var arguments = location.ArgumentList.Arguments;
            if (arguments[0].Expression is not LiteralExpressionSyntax file ||
                arguments[1].Expression is not LiteralExpressionSyntax line ||
                arguments[2].Expression is not LiteralExpressionSyntax column)
                throw new InvalidOperationException("ANSI companion binding has invalid native source coordinates.");
            var key = (DeclarationSourceMap.ReadFilePath(file.Token).ToUpperInvariant(),
                uint.Parse(line.Token.ValueText, CultureInfo.InvariantCulture),
                uint.Parse(column.Token.ValueText, CultureInfo.InvariantCulture));
            if (!required.TryGetValue(key, out var function))
                return null;
            var import = node.AttributeLists.SelectMany(list => list.Attributes)
                .SingleOrDefault(attribute => attribute.Name.ToString().Split('.').Last() is "DllImport" or "DllImportAttribute");
            if (import == null || node.Body != null || node.ExpressionBody != null || !node.Modifiers.Any(SyntaxKind.ExternKeyword))
                throw new InvalidOperationException($"ANSI companion declaration '{function.Name}' was not emitted as a native import.");
            string module = (import.ArgumentList?.Arguments.FirstOrDefault()?.Expression as LiteralExpressionSyntax)?.Token.ValueText;
            if (!string.Equals(module, libraries[function.Name], StringComparison.OrdinalIgnoreCase))
                throw new InvalidOperationException($"ANSI companion import '{function.Name}' has library '{module}' instead of its mapped '{libraries[function.Name]}'.");
            string entryPoint = import.ArgumentList?.Arguments
                .Where(argument => argument.NameEquals?.Name.Identifier.ValueText == "EntryPoint")
                .Select(argument => (argument.Expression as LiteralExpressionSyntax)?.Token.ValueText).SingleOrDefault()
                ?? node.Identifier.ValueText;
            if (entryPoint != function.Name || !found.Add(function))
                throw new InvalidOperationException($"ANSI companion import '{function.Name}' at {NativeSourceIdentity.Of(function)} " +
                    $"has conflicting export identity '{entryPoint}' or duplicate bindings.");
            return node;
        }

        public override SyntaxNode VisitStructDeclaration(StructDeclarationSyntax node) => null;
        public override SyntaxNode VisitEnumDeclaration(EnumDeclarationSyntax node) => null;
        public override SyntaxNode VisitDelegateDeclaration(DelegateDeclarationSyntax node) => null;
        public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node) => null;
        public override SyntaxNode VisitPropertyDeclaration(PropertyDeclarationSyntax node) => null;

        public override SyntaxNode VisitClassDeclaration(ClassDeclarationSyntax node)
        {
            var rewritten = (ClassDeclarationSyntax)base.VisitClassDeclaration(node);
            return rewritten.Members.Count == 0 ? null : rewritten;
        }

        public override SyntaxNode VisitNamespaceDeclaration(NamespaceDeclarationSyntax node)
        {
            var rewritten = (NamespaceDeclarationSyntax)base.VisitNamespaceDeclaration(node);
            return rewritten.Members.Count == 0 ? null : rewritten;
        }

        public override SyntaxNode VisitFileScopedNamespaceDeclaration(FileScopedNamespaceDeclarationSyntax node)
        {
            var rewritten = (FileScopedNamespaceDeclarationSyntax)base.VisitFileScopedNamespaceDeclaration(node);
            return rewritten.Members.Count == 0 ? null : rewritten;
        }
    }
}
