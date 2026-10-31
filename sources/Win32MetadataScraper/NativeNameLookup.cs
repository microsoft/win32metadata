#nullable enable
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal sealed class NativeNameLookup
    {
        private readonly ILookup<(CXCursor Scope, string Name), NamedDecl> declarationsByScope;
        private readonly Dictionary<CXCursor, RecordDecl> records = new();
        private readonly ILookup<CXCursor, UsingDirectiveDecl> namespaceImports;
        private readonly ILookup<CXCursor, NamespaceDecl> implicitNamespaces;
        private readonly ILookup<(CXCursor Function, string Name), ParmVarDecl> parametersByFunction;
        private readonly ILookup<CXCursor, FunctionDecl> functionsByScope;
        private readonly Dictionary<CXCursor, ILookup<string, FunctionDecl>> writtenFunctionsByScope = new();
        private readonly HashSet<(CXFile File, uint Offset)> macroExpansionLocations = new();

        internal NativeNameLookup(IEnumerable<Cursor> visited)
        {
            var cursors = visited.ToArray();
            foreach (var expansion in cursors.Where(cursor => cursor.CursorKind == CXCursorKind.CXCursor_MacroExpansion))
            {
                expansion.Location.GetExpansionLocation(out var file, out _, out _, out uint offset);
                macroExpansionLocations.Add((file, offset));
            }
            var named = cursors.OfType<NamedDecl>().Where(declaration => declaration is not IndirectFieldDecl &&
                declaration.SemanticParentCursor != null &&
                (declaration is ParmVarDecl || declaration.SemanticParentCursor is not FunctionDecl)).ToArray();
            declarationsByScope = named.Where(declaration => declaration.Name.Length != 0)
                .ToLookup(declaration => (GetScope(declaration), declaration.Name));
            functionsByScope = named.OfType<FunctionDecl>().ToLookup(GetScope);
            parametersByFunction = named.OfType<ParmVarDecl>()
                .Where(parameter => parameter.SemanticParentCursor is FunctionDecl)
                .ToLookup(parameter => (RequireParent(parameter).Handle.CanonicalCursor, parameter.Name));
            foreach (var record in named.OfType<RecordDecl>())
                records.TryAdd(record.Handle.CanonicalCursor, record);
            namespaceImports = named.OfType<UsingDirectiveDecl>()
                .ToLookup(declaration => RequireParent(declaration).Handle.CanonicalCursor);
            implicitNamespaces = named.OfType<NamespaceDecl>()
                .Where(declaration => declaration.IsInline || declaration.IsAnonymousNamespace)
                .ToLookup(declaration => RequireParent(declaration).Handle.CanonicalCursor);
        }

        internal NamedDecl[] Resolve(Cursor owner, string name, Func<string, Exception> error, bool writtenFunctionNames = false)
        {
            bool absolute = name.StartsWith("::", StringComparison.Ordinal);
            string[] parts = (absolute ? name[2..] : name).Split(new[] { "::" }, StringSplitOptions.None);
            Cursor? scope = absolute ? owner.TranslationUnit.TranslationUnitDecl : owner.SemanticParentCursor;
            NamedDecl[] candidates = Array.Empty<NamedDecl>();
            while (scope != null)
            {
                candidates = Lookup(scope is FunctionDecl ? scope.Handle : scope.Handle.CanonicalCursor,
                    parts[0], error, writtenFunctionNames);
                if (candidates.Length != 0 || absolute)
                    break;
                scope = scope.SemanticParentCursor;
            }
            foreach (string part in parts.Skip(1))
                candidates = candidates.Select(UnwrapTypeDeclaration)
                    .SelectMany(declaration => declaration is EnumDecl enumeration
                        ? enumeration.Enumerators.Where(value => value.Name == part).Cast<NamedDecl>()
                        : declaration is NamespaceDecl or RecordDecl
                            ? Lookup(declaration.Handle.CanonicalCursor, part, error, writtenFunctionNames) : Array.Empty<NamedDecl>()).ToArray();
            return candidates.GroupBy(declaration => declaration.Handle.CanonicalCursor).Select(group => group.First()).ToArray();
        }

        internal ParmVarDecl[] ResolveParameters(FunctionDecl function, string name)
            => parametersByFunction[(function.Handle.CanonicalCursor, name)]
                .GroupBy(ParameterIdentity).Select(group => group.First()).ToArray();

        internal static NamedDecl UnwrapTypeDeclaration(NamedDecl declaration)
            => declaration is TypedefNameDecl alias ? alias.UnderlyingType.CanonicalType switch
            {
                RecordType record => record.Decl,
                EnumType enumeration => enumeration.Decl,
                _ => declaration,
            } : declaration;

        private static (CXCursor Function, int Index) ParameterIdentity(ParmVarDecl parameter)
        {
            if (parameter.SemanticParentCursor is FunctionDecl function)
                for (int position = 0; position < function.Parameters.Count; position++)
                    if (function.Parameters[position].Handle == parameter.Handle)
                        return (function.Handle.CanonicalCursor, position);
            throw new InvalidDataException("A native lookup parameter has no ordinal in its declaring function.");
        }

        private static CXCursor GetScope(NamedDecl declaration)
        {
            Cursor scope = RequireParent(declaration);
            if (declaration is EnumConstantDecl && scope is EnumDecl enumeration && !enumeration.IsScoped)
                scope = RequireParent(enumeration);
            while (scope is LinkageSpecDecl)
                scope = RequireParent(scope);
            return scope is FunctionDecl ? scope.Handle : scope.Handle.CanonicalCursor;
        }

        private static Cursor RequireParent(Cursor declaration)
            => declaration.SemanticParentCursor ??
                throw new InvalidDataException("A native lookup declaration has no semantic parent scope.");

        private string? GetWrittenFunctionName(FunctionDecl function)
        {
            function.Handle.Location.GetExpansionLocation(out var file, out _, out _, out var offset);
            if (file.Equals(default(CXFile)) || !macroExpansionLocations.Contains((file, offset)))
                return null;
            return NativeMacroNames.GetWrittenName(function, requireRecordedExpansion: true);
        }

        private IEnumerable<FunctionDecl> WrittenFunctions(CXCursor scope, string name)
        {
            if (!writtenFunctionsByScope.TryGetValue(scope, out var names))
            {
                names = functionsByScope[scope].Select(function => (Function: function, Name: GetWrittenFunctionName(function)))
                    .Where(value => value.Name != null).ToLookup(value => value.Name!, value => value.Function);
                writtenFunctionsByScope.Add(scope, names);
            }
            return names[name];
        }

        private NamedDecl[] Lookup(CXCursor scope, string name, Func<string, Exception> error, bool writtenFunctionNames)
        {
            var candidates = new List<NamedDecl>();
            var searched = new HashSet<CXCursor>();
            var scopes = new Stack<CXCursor>();
            scopes.Push(scope);
            while (scopes.TryPop(out scope))
            {
                if (!searched.Add(scope))
                    continue;
                var direct = declarationsByScope[(scope, name)]
                    .Concat(writtenFunctionNames ? WrittenFunctions(scope, name) : Enumerable.Empty<NamedDecl>()).ToArray();
                candidates.AddRange(direct.Select(declaration => declaration.UnderlyingDecl));
                if (direct.Length == 0 && records.TryGetValue(scope, out var record))
                {
                    record = record.Definition as RecordDecl ?? record;
                    foreach (var anonymous in record.AnonymousRecords)
                        scopes.Push(anonymous.Handle.CanonicalCursor);
                    if (record is CXXRecordDecl cppRecord)
                        foreach (var parent in cppRecord.Bases)
                        {
                            if (parent.Type.CanonicalType is not RecordType type)
                                throw error("Native metadata reference lookup requires a resolved native base declaration.");
                            scopes.Push(type.Decl.Handle.CanonicalCursor);
                        }
                }
                foreach (var declaration in implicitNamespaces[scope])
                    scopes.Push(declaration.Handle.CanonicalCursor);
                foreach (var directive in namespaceImports[scope])
                {
                    var target = directive.CursorChildren.LastOrDefault(child => child.Handle.Kind == CXCursorKind.CXCursor_NamespaceRef);
                    if (target == null)
                        throw error("A metadata namespace import requires a native namespace reference.");
                    var handle = target.Handle.Referenced;
                    if (handle.Kind == CXCursorKind.CXCursor_NamespaceAlias)
                        handle = handle.Referenced;
                    if (handle.Kind != CXCursorKind.CXCursor_Namespace)
                        throw error("A metadata namespace import must resolve to a native namespace.");
                    scopes.Push(handle.CanonicalCursor);
                }
            }
            return candidates.ToArray();
        }
    }
}
