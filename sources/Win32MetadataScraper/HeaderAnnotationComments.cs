using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal sealed partial class HeaderAnnotationProcessor
    {
        private const string CommentPrefix = "Win32Metadata";
        private const string QualifiedNativeName = @"[A-Za-z_][A-Za-z_0-9]*(?:::[A-Za-z_][A-Za-z_0-9]*)*";

        private unsafe void ApplyCommentAnnotations(TranslationUnit unit)
        {
            var files = new HashSet<CXFile>();
            CXInclusionVisitor visitor = (file, _, _, _) => files.Add((CXFile)file);
            unit.Handle.GetInclusions(visitor, default);
            GC.KeepAlive(visitor);
            Dictionary<(CXCursor Declaration, int Parameter), DeclarationFacts> nativeFacts = null;
            foreach (var file in files)
            {
                var contents = unit.Handle.GetFileContents(file, out _);
                if (!Encoding.UTF8.GetString(contents).Contains(CommentPrefix, StringComparison.Ordinal))
                    continue;
                var skipped = unit.Handle.GetSkippedRanges(file);
                var tokens = unit.Handle.Tokenize(CXSourceRange.Create(
                    unit.Handle.GetLocationForOffset(file, 0),
                    unit.Handle.GetLocationForOffset(file, checked((uint)contents.Length))));
                try
                {
                    foreach (var token in tokens)
                    {
                        if (token.Kind != CXTokenKind.CXToken_Comment)
                            continue;
                        var location = GetLocation(token.GetLocation(unit.Handle));
                        bool inactive = false;
                        if (skipped != null)
                            for (uint i = 0; i < skipped->count; i++)
                            {
                                var range = skipped->ranges[i];
                                inactive |= location.Offset >= GetLocation(range.Start).Offset &&
                                    location.Offset < GetLocation(range.End).Offset;
                            }
                        if (inactive)
                            continue;
                        using var spelling = token.GetSpelling(unit.Handle);
                        string text = spelling.ToString();
                        if (!Regex.IsMatch(text, @"\A(?:/\*|//)\s*Win32Metadata\b"))
                            continue;
                        int lineStart = checked((int)location.Offset);
                        do
                        {
                            while (lineStart > 0 && contents[lineStart - 1] != '\n')
                                lineStart--;
                            int previous = lineStart - 1;
                            if (previous > 0 && contents[previous - 1] == '\r')
                                previous--;
                            if (previous <= 0 || contents[previous - 1] != '\\')
                                break;
                            lineStart = previous - 1;
                        } while (lineStart > 0);
                        string prefix = Encoding.UTF8.GetString(contents.Slice(lineStart, checked((int)location.Offset) - lineStart)).TrimStart();
                        CollectAnnotationErrors(null, () =>
                        {
                            if (prefix.StartsWith("#", StringComparison.Ordinal))
                                throw Error(location, "Metadata comments cannot be defined inside a preprocessor directive or macro.");
                            nativeNames ??= new NativeNameLookup(visited);
                            nativeFacts ??= declarations.Values.GroupBy(value => GetNativeIdentity(value.Declaration))
                                .ToDictionary(group => group.Key, group => group.First());
                            ApplyCommentAnnotation(text, location, unit.TranslationUnitDecl, nativeFacts);
                        }, () => Regex.Match(text, @"\b(?:interface|record|method|function|return|parameter|field|type|enum|enumerator|constant)\s+::[^\s]+").Value);
                    }
                }
                finally
                {
                    unit.Handle.DisposeTokens(tokens);
                    if (skipped != null)
                        skipped->Dispose();
                }
            }
        }

        private void ApplyCommentAnnotation(string text, NativeLocation location, TranslationUnitDecl root,
            IReadOnlyDictionary<(CXCursor Declaration, int Parameter), DeclarationFacts> nativeFacts)
        {
            var match = Regex.Match(text, @"\A/\*\s*Win32Metadata:\s*" +
                @"(?<kind>interface|record|method|function|return|parameter|field|type|enum|enumerator|constant)\s+(?<target>::" + QualifiedNativeName +
                @")\s*=>\s*(?<annotation>.*?)\s*\*/\z", RegexOptions.Singleline);
            if (!match.Success)
                throw Error(location, "Malformed metadata comment; expected " +
                    "'/* Win32Metadata: interface|record|method|function|return|parameter|field|type|enum|enumerator|constant ::Native::Target => Annotation(...) */'.");
            string kind = match.Groups["kind"].Value;
            string name = match.Groups["target"].Value;
            var target = ResolveCommentTarget(root, kind, name, location);
            if (invalidDeclarations.Contains(GetNativeIdentity(target)))
                return;
            if (!declarations.TryGetValue(target, out var facts) &&
                !nativeFacts.TryGetValue(GetNativeIdentity(target), out facts))
                throw Error(location, $"Metadata target '{name}' has no original declaration facts.");
            CollectAnnotationErrors(target, () => ApplyResolvedCommentAnnotation(match.Groups["annotation"].Value,
                kind, target, facts, location));
        }

        private void ApplyResolvedCommentAnnotation(string payload, string kind, NamedDecl target, DeclarationFacts facts,
            NativeLocation location)
        {
            HeaderAnnotation annotation;
            try
            {
                annotation = HeaderAnnotation.Parse(payload.Trim());
            }
            catch (FormatException exception)
            {
                throw Error(location, exception.Message);
            }
            if (kind == "return" && annotation.Name is not "RAIIFree" and not "AssociatedEnum")
                throw Error(location, $"'{annotation.Name}' is not a return annotation; use the native function or method selector.");
            if (annotation.Name == "RAIIFree")
            {
                var values = new List<long>();
                foreach (string argument in annotation.Arguments.Skip(1))
                {
                    if (!Regex.IsMatch(argument, @"\A-?(?:0|[1-9][0-9]*)\z") ||
                        !long.TryParse(argument, NumberStyles.AllowLeadingSign, CultureInfo.InvariantCulture, out long value))
                        throw Error(location, "Comment RAIIFree invalid values support signed decimal Int64 literals only; " +
                            $"'{argument}' is symbolic, an expression, or out of range. Keep its compiled native annotation.");
                    values.Add(value);
                }
                if (!Regex.IsMatch(annotation.Arguments[0], @"\A" + QualifiedNativeName + @"\z"))
                    throw Error(location, "Comment RAIIFree cleanup requires a native ::-qualified name, not a macro or expression.");
                var arguments = new[] { annotation.Arguments[0] }.Concat(values.Select(value =>
                    value.ToString(CultureInfo.InvariantCulture))).ToArray();
                AddAnnotation(facts, new HeaderAnnotation("RAIIFree", arguments), location);
                facts.InvalidValues.AddRange(values);
                cleanupReferences.Add((target, facts.Declaration, arguments[0], arguments, location));
            }
            else if (annotation.Name == "AssociatedEnum")
            {
                if (!Regex.IsMatch(annotation.Arguments[0], @"\A" + QualifiedNativeName + @"\z"))
                    throw Error(location, "Comment AssociatedEnum requires a native ::-qualified enum name.");
                AddAnnotation(facts, ReadEnumNameReference(target, facts, annotation.Arguments[0], location), location);
            }
            else if (annotation.Name is "AlsoUsableFor" or "AssociatedConstant")
            {
                var candidates = nativeNames.Resolve(target, annotation.Arguments[0], location);
                bool valid = candidates.Length == 1 && (annotation.Name == "AlsoUsableFor"
                    ? candidates[0] is TypedefNameDecl or RecordDecl or EnumDecl
                    : candidates[0] is EnumConstantDecl || IsConstantVariable(candidates[0]));
                if (!valid)
                    throw Error(location, $"{annotation.Name} reference '{annotation.Arguments[0]}' must identify one native " +
                        (annotation.Name == "AlsoUsableFor" ? "type" : "constant") + $"; found {candidates.Length} candidates.");
                AddAnnotation(facts, new HeaderAnnotation(annotation.Name, new[] { Remap(candidates[0].Name) }), location);
            }
            else if (annotation.Name is "Enum" or "FlagsEnum")
                throw Error(location, $"'{annotation.Name}' groups require compiled native values; retain the _Win32_Enum_/_Win32_FlagsEnum_ macro.");
            else
            {
                if (annotation.Name == "ImportLibrary")
                    try
                    {
                        HeaderAnnotation.ReadString(annotation.Arguments[0], requireQuotes: true);
                    }
                    catch (FormatException exception)
                    {
                        throw Error(location, exception.Message);
                    }
                AddAnnotation(facts, annotation, location);
            }
            if (facts.Declaration is TypedefNameDecl && !annotatedTypedefs.Contains(facts))
                annotatedTypedefs.Add(facts);
        }

        private NamedDecl ResolveCommentTarget(TranslationUnitDecl root, string kind, string name, NativeLocation location)
        {
            if (kind == "parameter")
            {
                int separator = name.LastIndexOf("::", StringComparison.Ordinal);
                var functions = nativeNames.Resolve(root, name[..separator], location, writtenFunctionNames: true);
                functions = functions.Where(value => value is FunctionDecl).ToArray();
                if (functions.Length != 1 || functions[0] is not FunctionDecl function)
                    throw Error(location, $"Parameter target '{name}' must identify one native function or method before its parameter name; found {functions.Length} candidates.");
                var parameters = nativeNames.ResolveParameters(function, name[(separator + 2)..]);
                if (parameters.Length != 1)
                    throw Error(location, $"Parameter target '{name}' must identify one named native parameter; found {parameters.Length} candidates.");
                return parameters[0];
            }
            var candidates = nativeNames.Resolve(root, name, location,
                writtenFunctionNames: kind is "function" or "method" or "return");
            if (kind is "record" or "interface" or "enum")
                candidates = candidates.Select(UnwrapTypeDeclaration).ToArray();
            else if (kind == "type")
                candidates = candidates.Select(value => value is TypedefNameDecl alias &&
                    UnwrapTypeDeclaration(alias) is NamedDecl underlying && alias.Name == underlying.Name ? underlying : value).ToArray();
            candidates = candidates.Where(value => kind switch
            {
                "method" => value is CXXMethodDecl,
                "function" => value is FunctionDecl and not CXXMethodDecl,
                "return" => value is FunctionDecl,
                _ => true,
            }).GroupBy(value => value.Handle.CanonicalCursor).Select(group => group.First()).ToArray();
            if (candidates.Length != 1 || !(kind switch
            {
                "record" or "interface" => candidates[0] is RecordDecl,
                "type" => candidates[0] is TypedefNameDecl or RecordDecl or EnumDecl,
                "enum" => candidates[0] is EnumDecl,
                "enumerator" => candidates[0] is EnumConstantDecl,
                "constant" => IsConstantVariable(candidates[0]),
                "function" or "method" or "return" => candidates[0] is FunctionDecl,
                "field" => candidates[0] is FieldDecl,
                _ => false,
            }))
                throw Error(location, $"Metadata {kind} target '{name}' must identify one native {kind} declaration; found {candidates.Length} candidates.");
            return candidates[0];
        }

        private static NamedDecl UnwrapTypeDeclaration(NamedDecl declaration)
            => declaration is TypedefNameDecl alias ? alias.UnderlyingType.CanonicalType switch
            {
                RecordType record => record.Decl,
                EnumType enumeration => enumeration.Decl,
                _ => declaration,
            } : declaration;

        private sealed class NativeNameLookup
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
                foreach (var expansion in visited.Where(cursor => cursor.CursorKind == CXCursorKind.CXCursor_MacroExpansion))
                {
                    expansion.Location.GetExpansionLocation(out var file, out _, out _, out uint offset);
                    macroExpansionLocations.Add((file, offset));
                }
                var named = visited.OfType<NamedDecl>().Where(declaration => declaration is not IndirectFieldDecl &&
                    declaration.SemanticParentCursor != null &&
                    (declaration is ParmVarDecl || declaration.SemanticParentCursor is not FunctionDecl)).ToArray();
                declarationsByScope = named.Where(declaration => declaration.Name.Length != 0)
                    .ToLookup(declaration => (GetScope(declaration), declaration.Name));
                functionsByScope = named.OfType<FunctionDecl>().ToLookup(GetScope);
                parametersByFunction = named.OfType<ParmVarDecl>()
                    .Where(parameter => parameter.SemanticParentCursor is FunctionDecl)
                    .ToLookup(parameter => (parameter.SemanticParentCursor.Handle.CanonicalCursor, parameter.Name));
                foreach (var record in named.OfType<RecordDecl>())
                    records.TryAdd(record.Handle.CanonicalCursor, record);
                namespaceImports = named.OfType<UsingDirectiveDecl>()
                    .ToLookup(declaration => declaration.SemanticParentCursor.Handle.CanonicalCursor);
                implicitNamespaces = named.OfType<NamespaceDecl>()
                    .Where(declaration => declaration.IsInline || declaration.IsAnonymousNamespace)
                    .ToLookup(declaration => declaration.SemanticParentCursor.Handle.CanonicalCursor);
            }

            internal NamedDecl[] Resolve(Cursor owner, string name, NativeLocation location, bool writtenFunctionNames = false)
            {
                bool absolute = name.StartsWith("::", StringComparison.Ordinal);
                string[] parts = (absolute ? name[2..] : name).Split(new[] { "::" }, StringSplitOptions.None);
                Cursor scope = absolute ? owner.TranslationUnit.TranslationUnitDecl : owner.SemanticParentCursor;
                NamedDecl[] candidates = Array.Empty<NamedDecl>();
                while (scope != null)
                {
                    candidates = Lookup(scope is FunctionDecl ? scope.Handle : scope.Handle.CanonicalCursor,
                        parts[0], location, writtenFunctionNames);
                    if (candidates.Length != 0 || absolute)
                        break;
                    scope = scope.SemanticParentCursor;
                }
                foreach (string part in parts.Skip(1))
                    candidates = candidates.Select(UnwrapTypeDeclaration)
                        .SelectMany(declaration => declaration is EnumDecl enumeration
                            ? enumeration.Enumerators.Where(value => value.Name == part).Cast<NamedDecl>()
                            : declaration is NamespaceDecl or RecordDecl
                                ? Lookup(declaration.Handle.CanonicalCursor, part, location, writtenFunctionNames) : Array.Empty<NamedDecl>()).ToArray();
                return candidates.GroupBy(declaration => declaration.Handle.CanonicalCursor).Select(group => group.First()).ToArray();
            }

            internal ParmVarDecl[] ResolveParameters(FunctionDecl function, string name)
                => parametersByFunction[(function.Handle.CanonicalCursor, name)]
                    .GroupBy(GetNativeIdentity).Select(group => group.First()).ToArray();

            private static CXCursor GetScope(NamedDecl declaration)
            {
                Cursor scope = declaration.SemanticParentCursor;
                if (declaration is EnumConstantDecl && scope is EnumDecl enumeration && !enumeration.IsScoped)
                    scope = enumeration.SemanticParentCursor;
                while (scope is LinkageSpecDecl)
                    scope = scope.SemanticParentCursor;
                return scope is FunctionDecl ? scope.Handle : scope.Handle.CanonicalCursor;
            }

            private string GetWrittenFunctionName(FunctionDecl function)
            {
                var unit = function.TranslationUnit.Handle;
                function.Handle.Location.GetExpansionLocation(out var file, out _, out _, out var offset);
                if (file.Equals(default(CXFile)) || !macroExpansionLocations.Contains((file, offset)))
                    return null;
                var expansion = unit.GetCursor(unit.GetLocationForOffset(file, offset));
                if (expansion.Kind != CXCursorKind.CXCursor_MacroExpansion)
                    return null;
                var definition = expansion.Referenced;
                if (definition.Kind != CXCursorKind.CXCursor_MacroDefinition || definition.IsMacroFunctionLike)
                    return null;
                var tokens = unit.Tokenize(definition.Extent);
                try
                {
                    var identifiers = tokens.ToArray().Where(token => token.Kind != CXTokenKind.CXToken_Comment).ToArray();
                    if (identifiers.Length != 2 || identifiers.Any(token => token.Kind != CXTokenKind.CXToken_Identifier))
                        return null;
                    function.Handle.Location.GetSpellingLocation(out var spellingFile, out _, out _, out var spellingOffset);
                    identifiers[1].GetLocation(unit).GetSpellingLocation(out var replacementFile, out _, out _, out var replacementOffset);
                    if (!spellingFile.Equals(replacementFile) || spellingOffset != replacementOffset)
                        return null;
                    using var name = identifiers[0].GetSpelling(unit);
                    using var nativeName = identifiers[1].GetSpelling(unit);
                    using var expanded = expansion.Spelling;
                    string written = name.ToString();
                    // Both compiler locations must identify this exact renamer, not a nested factory or later macro state.
                    return written == expanded.ToString() && written != function.Name && nativeName.ToString() == function.Name
                        ? written : null;
                }
                finally
                {
                    unit.DisposeTokens(tokens);
                }
            }

            private IEnumerable<FunctionDecl> WrittenFunctions(CXCursor scope, string name)
            {
                if (!writtenFunctionsByScope.TryGetValue(scope, out var names))
                {
                    names = functionsByScope[scope].Select(function => (Function: function, Name: GetWrittenFunctionName(function)))
                        .Where(value => value.Name != null).ToLookup(value => value.Name, value => value.Function);
                    writtenFunctionsByScope.Add(scope, names);
                }
                return names[name];
            }

            private NamedDecl[] Lookup(CXCursor scope, string name, NativeLocation location, bool writtenFunctionNames)
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
                                    throw Error(location, "Native metadata reference lookup requires a resolved native base declaration.");
                                scopes.Push(type.Decl.Handle.CanonicalCursor);
                            }
                    }
                    foreach (var declaration in implicitNamespaces[scope])
                        scopes.Push(declaration.Handle.CanonicalCursor);
                    foreach (var directive in namespaceImports[scope])
                    {
                        var target = directive.CursorChildren.LastOrDefault(child => child.Handle.Kind == CXCursorKind.CXCursor_NamespaceRef);
                        if (target == null)
                            throw Error(location, "A metadata namespace import requires a native namespace reference.");
                        var handle = target.Handle.Referenced;
                        if (handle.Kind == CXCursorKind.CXCursor_NamespaceAlias)
                            handle = handle.Referenced;
                        if (handle.Kind != CXCursorKind.CXCursor_Namespace)
                            throw Error(location, "A metadata namespace import must resolve to a native namespace.");
                        scopes.Push(handle.CanonicalCursor);
                    }
                }
                return candidates.ToArray();
            }
        }
    }
}
