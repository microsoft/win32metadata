using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed class OpaqueRecordProjection
    {
        private readonly Dictionary<(string File, uint Line, uint Column), NativeRecord> records = new();
        private readonly CSharpCompilation originalCompilation;
        private readonly SyntaxTree[] originalTrees;
        private readonly HashSet<string> includedNames = new(StringComparer.Ordinal);
        private readonly HashSet<string> traversalFiles = new(StringComparer.OrdinalIgnoreCase);
        private readonly List<RecordAlias> recordAliases = new();

        internal OpaqueRecordProjection(TranslationUnit unit, IEnumerable<string> sources, IReadOnlyDictionary<string, string> remaps,
            IReadOnlyCollection<string> excludedNames = null)
        {
            originalTrees = sources.Where(source => !string.IsNullOrEmpty(source))
                .Select(source => CSharpSyntaxTree.ParseText(source)).ToArray();
            originalCompilation = CSharpCompilation.Create("OpaqueRecordDiscovery", originalTrees,
                new[] { MetadataReference.CreateFromFile(typeof(object).Assembly.Location) },
                new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true));
            var missingNames = new HashSet<string>(StringComparer.Ordinal);
            foreach (var tree in originalTrees)
            {
                var model = originalCompilation.GetSemanticModel(tree);
                foreach (var use in TypeUses(tree.GetRoot()))
                    FindMissingTypes(model.GetTypeInfo(use).Type, missingNames);
            }
            if (missingNames.Count == 0)
                return;

            var visited = new HashSet<Cursor>();
            Walk(unit.TranslationUnitDecl);
            foreach (var group in recordAliases.GroupBy(alias => alias.ManagedName))
                if (group.Select(alias => alias.Declaration.Handle.CanonicalCursor).Distinct().Count() != 1)
                    throw new InvalidOperationException($"Distinct native record aliases project to '{group.Key}'.");
            var uniqueAliases = recordAliases.GroupBy(alias => alias.ManagedName).Select(group => group.First()).ToArray();
            recordAliases.Clear();
            recordAliases.AddRange(uniqueAliases);

            void Walk(Cursor cursor)
            {
                if (!visited.Add(cursor))
                    return;
                if (cursor is TypedefNameDecl alias && alias.UnderlyingType.CanonicalType is RecordType type)
                {
                    var declaration = type.Decl.Definition ?? type.Decl;
                    string qualifiedName = DeclarationSourceMap.QualifiedName(alias.Handle);
                    string managedName = ManagedName(alias.Name, qualifiedName, remaps);
                    string recordName = DeclarationSourceMap.QualifiedName(declaration.Handle);
                    if (declaration.IsCompleteDefinition && !string.IsNullOrEmpty(declaration.Name) &&
                        missingNames.Contains(managedName) &&
                        managedName != ManagedName(declaration.Name, recordName, remaps) &&
                        !new[] { alias.Name, qualifiedName, managedName, declaration.Name, recordName }
                            .Any(name => excludedNames?.Contains(name, StringComparer.Ordinal) == true))
                        recordAliases.Add(new RecordAlias(qualifiedName, managedName, declaration));
                }
                if (cursor is RecordDecl record && !string.IsNullOrEmpty(record.Name))
                {
                    string qualifiedName = DeclarationSourceMap.QualifiedName(record.Handle);
                    string managedName = ManagedName(record.Name, qualifiedName, remaps);
                    var declaration = record.Definition ?? record;
                    if (missingNames.Contains(managedName))
                    {
                        bool isIncomplete = !declaration.IsCompleteDefinition;
                        bool isNominalHandle = IsNominalHandleDefinition(declaration);
                        if (isIncomplete || isNominalHandle || IsEmptyDefinition(declaration, new HashSet<RecordDecl>()))
                        {
                            declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
                            if (file.ToString().Length != 0)
                            {
                                records[Location(file.ToString(), line, column)] = new NativeRecord(
                                    qualifiedName, declaration.Handle.CanonicalCursor, isIncomplete, isNominalHandle);
                                traversalFiles.Add(file.ToString());
                                includedNames.Add(qualifiedName);
                                for (var parent = declaration.SemanticParentCursor; parent is RecordDecl; parent = parent.SemanticParentCursor)
                                    includedNames.Add(DeclarationSourceMap.QualifiedName(parent.Handle));
                            }
                        }
                    }
                }
                foreach (var child in cursor.CursorChildren)
                    if (!child.Handle.IsAttribute && !child.Handle.IsReference && !child.Handle.IsExpression)
                        Walk(child);
            }
        }

        internal IReadOnlyCollection<string> IncludedNames => includedNames;
        internal IReadOnlyCollection<string> TraversalFiles => traversalFiles;
        internal IReadOnlyCollection<RecordAlias> RecordAliases => recordAliases;

        internal OpaqueRecordProjection ForAlias(RecordAlias alias)
            => new(originalTrees, originalCompilation, alias);

        private OpaqueRecordProjection(SyntaxTree[] originalTrees, CSharpCompilation originalCompilation, RecordAlias alias)
        {
            this.originalTrees = originalTrees;
            this.originalCompilation = originalCompilation;
            var declaration = alias.Declaration;
            declaration.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
            if (!declaration.IsCompleteDefinition || file.ToString().Length == 0)
                throw new InvalidOperationException($"Native record alias '{alias.Name}' needs an original complete definition and source coordinates.");
            records.Add(Location(file.ToString(), line, column),
                new NativeRecord(alias.Name, declaration.Handle.CanonicalCursor, false, false, IsRecordAlias: true));
            traversalFiles.Add(file.ToString());
            includedNames.Add(alias.RecordName);
            for (var parent = declaration.SemanticParentCursor; parent is RecordDecl; parent = parent.SemanticParentCursor)
                includedNames.Add(DeclarationSourceMap.QualifiedName(parent.Handle));
        }

        internal Dictionary<string, string> SelectRequiredBindings(IReadOnlyDictionary<string, string> generated)
        {
            var candidates = generated.Select(pair => (
                pair.Key,
                Root: Filter(SyntaxFactory.ParseCompilationUnit(pair.Value), node => NativeRecordFor(node) != null))).ToArray();
            var trees = candidates.Select(candidate => CSharpSyntaxTree.Create(candidate.Root)).ToArray();
            var compilation = originalCompilation.AddSyntaxTrees(trees);
            var providers = new Dictionary<INamedTypeSymbol, List<NativeRecord>>(SymbolEqualityComparer.Default);
            var nodes = new Dictionary<StructDeclarationSyntax, INamedTypeSymbol>();
            foreach (var tree in trees)
            {
                var model = compilation.GetSemanticModel(tree);
                foreach (var node in tree.GetRoot().DescendantNodes().OfType<StructDeclarationSyntax>())
                {
                    var native = NativeRecordFor(node);
                    if (native == null)
                        continue;
                    if (node.Members.Count != 0 && !native.IsNominalHandle && !native.IsRecordAlias)
                        throw new InvalidOperationException($"Opaque native record '{native.Name}' acquired a generated body.");
                    native = native with
                    {
                        AllowsByValue = native.IsRecordAlias && node.Members.OfType<FieldDeclarationSyntax>()
                            .Any(field => !field.Modifiers.Any(SyntaxKind.StaticKeyword) && !field.Modifiers.Any(SyntaxKind.ConstKeyword))
                    };
                    var symbol = model.GetDeclaredSymbol(node);
                    if (!providers.TryGetValue(symbol, out var declarations))
                        providers[symbol] = declarations = new();
                    declarations.Add(native);
                    nodes[node] = symbol;
                }
            }

            var required = new HashSet<INamedTypeSymbol>(SymbolEqualityComparer.Default);
            var shadowed = new HashSet<INamedTypeSymbol>(SymbolEqualityComparer.Default);
            foreach (var tree in originalTrees)
            {
                var before = originalCompilation.GetSemanticModel(tree);
                var after = compilation.GetSemanticModel(tree);
                foreach (var use in TypeUses(tree.GetRoot()))
                    Inspect(before.GetTypeInfo(use).Type, after.GetTypeInfo(use).Type, behindPointer: false);
            }
            foreach (var symbol in required)
            {
                if (shadowed.Contains(symbol))
                    throw new InvalidOperationException($"Retaining opaque native record '{symbol.ToDisplayString()}' would change an already resolved type reference.");
                for (var parent = symbol.ContainingType; parent != null; parent = parent.ContainingType)
                    if (!parent.DeclaringSyntaxReferences.Any(reference => originalTrees.Contains(reference.SyntaxTree)))
                        throw new InvalidOperationException($"Opaque native record '{symbol.ToDisplayString()}' requires an ordinary generated binding for its enclosing type '{parent.ToDisplayString()}'.");
            }
            var result = new Dictionary<string, string>();
            for (int index = 0; index < trees.Length; index++)
            {
                var root = Filter((CompilationUnitSyntax)trees[index].GetRoot(),
                    node => nodes.TryGetValue(node, out var symbol) && required.Contains(symbol));
                if (root.Members.Count != 0)
                    result[candidates[index].Key] = root.NormalizeWhitespace().ToFullString() + Environment.NewLine;
            }
            return result;

            void Inspect(ITypeSymbol before, ITypeSymbol after, bool behindPointer)
            {
                if (after is IPointerTypeSymbol pointer)
                    Inspect((before as IPointerTypeSymbol)?.PointedAtType, pointer.PointedAtType, behindPointer: true);
                else if (after is IArrayTypeSymbol array)
                    Inspect((before as IArrayTypeSymbol)?.ElementType, array.ElementType, behindPointer);
                else if (after is IFunctionPointerTypeSymbol function)
                {
                    var previous = (before as IFunctionPointerTypeSymbol)?.Signature;
                    Inspect(previous?.ReturnType, function.Signature.ReturnType, behindPointer: false);
                    for (int index = 0; index < function.Signature.Parameters.Length; index++)
                        Inspect(previous != null && index < previous.Parameters.Length ? previous.Parameters[index].Type : null,
                            function.Signature.Parameters[index].Type, behindPointer: false);
                }
                else if (after is INamedTypeSymbol named)
                {
                    if (providers.TryGetValue(named, out var declarations))
                    {
                        if (before != null && before.TypeKind != TypeKind.Error)
                            shadowed.Add(named);
                        else
                        {
                            if (declarations.Select(declaration => declaration.Identity).Distinct().Count() != 1)
                                throw new InvalidOperationException($"Distinct opaque native records project to '{named.ToDisplayString()}'.");
                            if (!behindPointer && !declarations.All(declaration => declaration.AllowsByValue))
                            {
                                if (declarations[0].IsRecordAlias)
                                    throw new InvalidOperationException($"Native record alias '{declarations[0].Name}' has no ordinary generated instance fields; by-value recovery cannot establish its storage.");
                                string kind = declarations[0].IsIncomplete ? "An incomplete" :
                                    declarations[0].IsNominalHandle ? "A nominal handle" : "An empty";
                                throw new InvalidOperationException($"{kind} native record '{declarations[0].Name}' is used by value; selective recovery only preserves pointee identity.");
                            }
                            required.Add(named);
                        }
                    }
                    for (int index = 0; index < named.TypeArguments.Length; index++)
                        Inspect(before is INamedTypeSymbol old && index < old.TypeArguments.Length ? old.TypeArguments[index] : null,
                            named.TypeArguments[index], behindPointer: false);
                }
            }
        }

        private NativeRecord NativeRecordFor(StructDeclarationSyntax declaration)
        {
            foreach (var attribute in declaration.AttributeLists.SelectMany(list => list.Attributes))
            {
                string name = attribute.Name.ToString().Split('.').Last();
                if (name is not "SourceLocation" and not "SourceLocationAttribute")
                    continue;
                var arguments = attribute.ArgumentList?.Arguments;
                if (arguments?.Count != 3 || arguments.Value[0].Expression is not LiteralExpressionSyntax file ||
                    arguments.Value[1].Expression is not LiteralExpressionSyntax line ||
                    arguments.Value[2].Expression is not LiteralExpressionSyntax column)
                    throw new InvalidOperationException("Opaque record discovery requires ClangSharp source-location coordinates.");
                return records.GetValueOrDefault(Location(DeclarationSourceMap.ReadFilePath(file.Token),
                    Convert.ToUInt32(line.Token.Value, CultureInfo.InvariantCulture),
                    Convert.ToUInt32(column.Token.Value, CultureInfo.InvariantCulture)));
            }
            return null;
        }

        private static CompilationUnitSyntax Filter(CompilationUnitSyntax root, Func<StructDeclarationSyntax, bool> keep)
            => root.WithMembers(SyntaxFactory.List(root.Members.Select(member => Member(member, keep)).Where(member => member != null)));

        private static MemberDeclarationSyntax Member(MemberDeclarationSyntax member, Func<StructDeclarationSyntax, bool> keep)
        {
            if (member is StructDeclarationSyntax record && keep(record))
                return record;
            if (member is BaseNamespaceDeclarationSyntax ns)
            {
                var members = SyntaxFactory.List(ns.Members.Select(child => Member(child, keep)).Where(child => child != null));
                return members.Count == 0 ? null : ns.WithMembers(members);
            }
            if (member is TypeDeclarationSyntax container)
            {
                var members = SyntaxFactory.List(container.Members.Select(child => Member(child, keep)).Where(child => child != null));
                return members.Count == 0 ? null : container.WithMembers(members).WithAttributeLists(default).WithBaseList(null);
            }
            return null;
        }

        private static IEnumerable<TypeSyntax> TypeUses(SyntaxNode root)
            => root.DescendantNodes().Select(node => node switch
            {
                MethodDeclarationSyntax method => method.ReturnType,
                DelegateDeclarationSyntax callback => callback.ReturnType,
                ParameterSyntax parameter => parameter.Type,
                VariableDeclarationSyntax variable => variable.Type,
                PropertyDeclarationSyntax property => property.Type,
                EventDeclarationSyntax @event => @event.Type,
                OperatorDeclarationSyntax @operator => @operator.ReturnType,
                ConversionOperatorDeclarationSyntax conversion => conversion.Type,
                CastExpressionSyntax cast => cast.Type,
                DefaultExpressionSyntax value => value.Type,
                ObjectCreationExpressionSyntax creation => creation.Type,
                SizeOfExpressionSyntax size => size.Type,
                BaseTypeSyntax parent => parent.Type,
                _ => null
            }).Where(type => type != null);

        private static void FindMissingTypes(ITypeSymbol type, ISet<string> names)
        {
            if (type is IPointerTypeSymbol pointer)
                FindMissingTypes(pointer.PointedAtType, names);
            else if (type is IArrayTypeSymbol array)
                FindMissingTypes(array.ElementType, names);
            else if (type is IFunctionPointerTypeSymbol function)
            {
                FindMissingTypes(function.Signature.ReturnType, names);
                foreach (var parameter in function.Signature.Parameters)
                    FindMissingTypes(parameter.Type, names);
            }
            else if (type is INamedTypeSymbol named)
            {
                if (named.TypeKind == TypeKind.Error)
                    names.Add(named.Name);
                foreach (var argument in named.TypeArguments)
                    FindMissingTypes(argument, names);
            }
        }

        private static (string File, uint Line, uint Column) Location(string file, uint line, uint column)
            => (Path.GetFullPath(file).ToUpperInvariant(), line, column);

        private static string ManagedName(string name, string qualifiedName, IReadOnlyDictionary<string, string> remaps)
            => (remaps.GetValueOrDefault(qualifiedName) ?? remaps.GetValueOrDefault(name) ?? name)
                .Split(new[] { "::", "." }, StringSplitOptions.None).Last().TrimStart('@');

        private static bool IsNominalHandleDefinition(RecordDecl record)
        {
            if (!record.IsCompleteDefinition || record.Handle.Kind != CXCursorKind.CXCursor_StructDecl ||
                !record.Name.EndsWith("__", StringComparison.Ordinal) ||
                record is CXXRecordDecl cpp && cpp.Bases.Any())
                return false;
            var declarations = record.CursorChildren.OfType<Decl>().Where(child => child is not AccessSpecDecl).ToArray();
            return declarations.Length == 1 && declarations[0] is FieldDecl field &&
                field.Name == "unused" && !field.IsBitField && field.Type.CanonicalType.Kind == CXTypeKind.CXType_Int;
        }

        private static bool IsEmptyDefinition(RecordDecl record, ISet<RecordDecl> visiting)
        {
            var definition = record.Definition ?? record;
            if (!definition.IsCompleteDefinition || !visiting.Add(definition))
                return false;
            try
            {
                if (definition.CursorChildren.OfType<Decl>().Any(child => child is not AccessSpecDecl))
                    return false;
                return definition is not CXXRecordDecl cpp || cpp.Bases.All(parent =>
                    !parent.IsVirtual && parent.Type.CanonicalType is RecordType type && IsEmptyDefinition(type.Decl, visiting));
            }
            finally
            {
                visiting.Remove(definition);
            }
        }

        internal sealed record RecordAlias(string Name, string ManagedName, RecordDecl Declaration)
        {
            internal string RecordName => DeclarationSourceMap.QualifiedName(Declaration.Handle);
        }

        private sealed record NativeRecord(string Name, CXCursor Identity, bool IsIncomplete, bool IsNominalHandle,
            bool IsRecordAlias = false, bool AllowsByValue = false);
    }
}
