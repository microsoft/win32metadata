using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;

namespace Win32MetadataScraper
{
    internal sealed unsafe class NativeConstantProbePlan
    {
        internal const string ProbePrefix = "__Win32MetadataConstant_";
        private readonly string sourceFile;
        private readonly string originalSource;
        private readonly bool cplusplus;
        private readonly bool unsignedChar;
        private readonly Dictionary<uint, string> presenceLines = new();
        private readonly Dictionary<uint, string> probeLines = new();
        private readonly Dictionary<string, List<string>> errors = new(StringComparer.Ordinal);
        private readonly Dictionary<string, Macro> active = new(StringComparer.Ordinal);
        private readonly HashSet<string> defined = new(StringComparer.Ordinal);
        private readonly Dictionary<string, NativeConstantRoute> routes = new(StringComparer.Ordinal);
        private readonly Dictionary<string, SimpleMacroValue> simple = new(StringComparer.Ordinal);
        private readonly Dictionary<string, VarDecl> variables = new(StringComparer.Ordinal);
        private readonly Dictionary<string, string> typeStorage = new(StringComparer.Ordinal);
        private readonly HashSet<string> resolving = new(StringComparer.Ordinal);
        private TranslationUnit original;
        private bool windowsTarget;
        private uint valueSourceStart;

        private NativeConstantProbePlan(string sourceFile, string[] names, bool cplusplus, bool unsignedChar)
        {
            this.sourceFile = Path.GetFullPath(sourceFile);
            this.cplusplus = cplusplus;
            this.unsignedChar = unsignedChar;
            Names = names;
            originalSource = File.ReadAllText(sourceFile);
            var text = new StringBuilder(originalSource).AppendLine().AppendLine();
            uint line = (uint)text.ToString().Count(character => character == '\n') + 1;
            foreach (string name in names)
            {
                presenceLines.Add(line, name);
                text.Append("#if defined(").Append(name).AppendLine(")").AppendLine("#endif");
                line += 2;
            }
            Source = text.ToString();
            ValueSource = originalSource;
        }

        internal string Source { get; }
        internal string ValueSource { get; private set; }
        internal string[] Names { get; }
        internal Dictionary<string, string> ProbeNames { get; } = new(StringComparer.Ordinal);
        internal IReadOnlyDictionary<string, List<string>> Errors => errors;
        internal IReadOnlyDictionary<string, NativeConstantRoute> Routes => routes;
        internal IReadOnlyDictionary<string, SimpleMacroValue> SimpleValues => simple;
        internal IReadOnlyDictionary<string, VarDecl> Variables => variables;
        internal HashSet<string> PreparedNames { get; } = new(StringComparer.Ordinal);
        internal bool HasValueProbes => ProbeNames.Count != 0;
        internal bool IsDefined(string name) => defined.Contains(name);
        internal Macro ActiveDefinition(string name) => active.GetValueOrDefault(name);

        internal static NativeConstantProbePlan Create(string sourceFile, string[] arguments,
            IReadOnlyCollection<string> traversal, string namesFile)
        {
            using var timing = GenerationTiming.BeginSpan("native-constants.scan-names");
            string sourceDirectory = Path.GetDirectoryName(Path.GetFullPath(sourceFile));
            var roots = new[] { sourceDirectory, Directory.GetCurrentDirectory() }
                .Concat(arguments.Where(argument => argument.StartsWith("--include-directory=", StringComparison.Ordinal))
                    .Select(argument => argument.Substring("--include-directory=".Length)))
                .Concat((Environment.GetEnvironmentVariable("INCLUDE") ?? "").Split(Path.PathSeparator,
                    StringSplitOptions.RemoveEmptyEntries))
                .Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            string[] names;
            if (namesFile != null)
            {
                names = File.ReadAllLines(namesFile);
                if (names.Any(name => !Regex.IsMatch(name, @"\A[_A-Za-z][\dA-Za-z_]*\z")) ||
                    !names.SequenceEqual(names.Distinct(StringComparer.Ordinal).OrderBy(name => name, StringComparer.Ordinal)))
                    throw new InvalidDataException($"Native constant names must be unique sorted identifiers: '{namesFile}'.");
                timing?.SetCounter("sharedNameIndex", 1);
            }
            else
            {
                var headers = (traversal.Count == 0 ? new[] { sourceFile } : traversal)
                    .Concat(roots.Where(Directory.Exists).SelectMany(root => Directory.EnumerateFiles(root))
                        .Where(path => Path.GetExtension(path) is ".h" or ".hpp" or ".inc" or ".inl"));
                names = ConstantsScraper.ScanConstantMacroNames(headers, roots);
                timing?.SetCounter("sharedNameIndex", 0);
            }
            timing?.SetCounter("candidateCount", names.Length);
            return new NativeConstantProbePlan(sourceFile, names,
                !arguments.Contains("--language=c", StringComparer.Ordinal),
                arguments.LastOrDefault(argument => argument is "-funsigned-char" or "-fsigned-char") == "-funsigned-char");
        }

        internal void Prepare(TranslationUnit unit, PInvokeGeneratorConfiguration configuration,
            bool collectTraversalConstants, IEnumerable<string> associatedNames)
        {
            using var timing = GenerationTiming.BeginSpan("native-constants.hybrid-route");
            original = unit;
            using (var target = unit.Handle.TargetInfo)
            using (var triple = target.Triple)
                windowsTarget = triple.ToString().Contains("windows", StringComparison.Ordinal);
            ReadActiveDefinitions(unit);
            var excluded = new HashSet<string>(configuration.ExcludedNames, StringComparer.Ordinal);
            var wildcards = excluded.Where(name => name.IndexOfAny(new[] { '*', '?' }) >= 0).ToArray();
            bool IsExcluded(string name) => excluded.Contains(name) || wildcards.Any(pattern =>
                System.IO.Enumeration.FileSystemName.MatchesSimpleExpression(pattern, name, ignoreCase: false));
            var definitions = unit.TranslationUnitDecl.CursorChildren.OfType<MacroDefinitionRecord>()
                .Where(macro => !macro.IsFunctionLike)
                .Select(macro =>
                {
                    macro.Location.GetFileLocation(out var file, out uint line, out _, out _);
                    return (macro.Name, Header: file.ToString(), Line: line);
                })
                .Where(macro => macro.Header.Length != 0 && !macro.Header.StartsWith("<", StringComparison.Ordinal))
                .ToArray();
            var requested = associatedNames.ToHashSet(StringComparer.Ordinal);
            var eligible = definitions.Where(macro => !IsExcluded(macro.Name) &&
                    (requested.Contains(macro.Name) || collectTraversalConstants &&
                        NativeConstantExtractor.IsTraversed(macro.Header, sourceFile, configuration.TraversalNames)))
                .Select(macro => macro.Name).Distinct(StringComparer.Ordinal).ToHashSet(StringComparer.Ordinal);
            PreparedNames.UnionWith(eligible);
            var scanned = Names.ToHashSet(StringComparer.Ordinal);
            string[] unscanned = eligible.Except(scanned, StringComparer.Ordinal).OrderBy(name => name, StringComparer.Ordinal).ToArray();
            if (unscanned.Length != 0)
                throw new InvalidOperationException("Object-like macros were not included in the pre-compile name scan: " +
                    string.Join(", ", unscanned));
            foreach (string name in Names.Where(eligible.Contains))
                Resolve(name);
            foreach (string name in Names.Where(eligible.Contains))
            {
                if (!requested.Contains(name) && active.TryGetValue(name, out var owner) &&
                    !NativeConstantExtractor.IsTraversed(owner.Header, sourceFile, configuration.TraversalNames))
                    routes[name] = new NativeConstantRoute(name, "NotOwned", "active definition is outside traversed headers");
            }
            using (GenerationTiming.BeginSpan("native-constants.build-probe-source"))
            {
                var text = new StringBuilder(originalSource).AppendLine().AppendLine();
                uint line = (uint)text.ToString().Count(character => character == '\n') + 1;
                valueSourceStart = line;
                foreach (string name in Names.Where(name => eligible.Contains(name) && routes[name].Route == "UnresolvedValue"))
                {
                    string probe = ProbePrefix + ProbeNames.Count.ToString(CultureInfo.InvariantCulture);
                    ProbeNames.Add(probe, name);
                    probeLines.Add(line + 1, name);
                    routes[name].ValueProbed = true;
                    text.Append("#if defined(").Append(name).AppendLine(")");
                    text.Append(cplusplus ? "constexpr auto " : "const __auto_type ").Append(probe)
                        .Append(" = __builtin_choose_expr(1, (").Append(name).AppendLine("), 0);");
                    text.AppendLine("#endif");
                    line += 3;
                }
                ValueSource = text.ToString();
            }
            timing?.SetCounter("presenceQueryCount", Names.Length);
            timing?.SetCounter("resolvedSimpleCount", eligible.Count(name => routes[name].Route == "ScannerResolved"));
            timing?.SetCounter("unresolvedValueCount", ProbeNames.Count);
            timing?.SetCounter("nonValueCount", eligible.Count(name => routes[name].Route == "NonValue"));
            timing?.SetCounter("valueProbeCount", ProbeNames.Count);
        }

        private NativeConstantRoute Resolve(string name)
        {
            if (routes.TryGetValue(name, out var existing))
                return existing;
            if (!defined.Contains(name))
                return routes[name] = new NativeConstantRoute(name, "Undefined", "undefined in the final header environment");
            if (!active.TryGetValue(name, out var macro))
                return routes[name] = new NativeConstantRoute(name, "Unrecorded", "active macro definition is not recorded by Clang");
            if (!resolving.Add(name))
                return new NativeConstantRoute(name, "UnresolvedValue", "recursive macro value");
            try
            {
                string body = ConstantsScraper.StripMacroParentheses(macro.Body);
                string nonValue = ConstantsScraper.GetNonValueMacroReason(body);
                if (nonValue != null)
                    return routes[name] = new NativeConstantRoute(name, "NonValue", nonValue);
                if (ConstantsScraper.TryReadSimpleMacroValue(body, cplusplus, windowsTarget, StorageOfType,
                    DirectCastWrapper, out var value))
                {
                    simple[name] = value;
                    return routes[name] = new NativeConstantRoute(name, "ScannerResolved", value.Kind);
                }
                if (Regex.IsMatch(body, @"\A[_A-Za-z]\w*\z"))
                {
                    if (active.TryGetValue(body, out var target) && !target.FunctionLike)
                    {
                        var targetRoute = Resolve(body);
                        if (targetRoute.Route == "ScannerResolved")
                        {
                            simple[name] = simple[body];
                            return routes[name] = new NativeConstantRoute(name, "ScannerResolved", "simple macro alias");
                        }
                        if (targetRoute.Route == "NonValue")
                            return routes[name] = new NativeConstantRoute(name, "NonValue", "alias of non-value macro " + body);
                    }
                    if (StorageOfType(body) != null)
                        return routes[name] = new NativeConstantRoute(name, "NonValue", "native type fragment");
                }
                string call = ConstantsScraper.GetWholeMacroInvocation(body);
                if (call != null && NonValueFunction(call, new HashSet<string>(StringComparer.Ordinal)) is string functionReason)
                    return routes[name] = new NativeConstantRoute(name, "NonValue", "non-value macro invocation: " + functionReason);
                return routes[name] = new NativeConstantRoute(name, "UnresolvedValue", "value expression requires Clang");
            }
            finally
            {
                resolving.Remove(name);
            }
        }

        private string NonValueFunction(string name, HashSet<string> visited)
        {
            if (!visited.Add(name) || !active.TryGetValue(name, out var macro) || !macro.FunctionLike)
                return null;
            string body = ConstantsScraper.StripMacroParentheses(macro.Body);
            if (macro.Parameters.Contains(body, StringComparer.Ordinal))
                return null;
            string reason = ConstantsScraper.GetNonValueMacroReason(body);
            if (reason != null)
                return reason;
            if (Regex.IsMatch(body, @"\A[_A-Za-z]\w*\z") &&
                active.TryGetValue(body, out var dependency) && !dependency.FunctionLike &&
                Resolve(body) is { Route: "NonValue" } route)
                return "alias of non-value macro " + body + ": " + route.Reason;
            string call = ConstantsScraper.GetWholeMacroInvocation(body);
            return call == null ? null : NonValueFunction(call, visited);
        }

        internal void AttachValueUnit(TranslationUnit unit)
        {
            if (!HasValueProbes)
                return;
            Decl[] declarations = unit.TranslationUnitDecl.Decls.ToArray();
            foreach (var variable in declarations.OfType<VarDecl>())
                if (ProbeNames.TryGetValue(variable.Name, out string name))
                    variables.Add(name, variable);
            string[] missing = ProbeNames.Values.Except(variables.Keys, StringComparer.Ordinal).ToArray();
            if (missing.Length != 0)
                throw new InvalidOperationException("Complex macro value probes escaped translation-unit scope: " + string.Join(", ", missing));
            foreach (Decl declaration in declarations)
            {
                if (IsBuiltinDeclaration(declaration) ||
                    declaration is VarDecl variable && ProbeNames.ContainsKey(variable.Name))
                    continue;
                declaration.Location.GetFileLocation(out var file, out uint line, out _, out _);
                if (string.Equals(file.ToString(), sourceFile, StringComparison.OrdinalIgnoreCase) && line >= valueSourceStart)
                {
                    if (declaration is TagDecl tag && probeLines.TryGetValue(line, out string macro) &&
                        variables.TryGetValue(macro, out var owner) &&
                        (InitializerReferences(owner, tag) ||
                            // Clang discards invalid __uuidof initializers but
                            // keeps their forward type and native diagnostics.
                            tag is RecordDecl { IsCompleteDefinition: false } && owner.Init == null &&
                            errors.ContainsKey(macro)))
                        continue;
                    throw new InvalidOperationException($"Unexpected {declaration.GetType().Name} " +
                        $"'{(declaration as NamedDecl)?.Name}' escaped complex macro value probe " +
                        $"'{probeLines.GetValueOrDefault(line)}' at {file}:{line}.");
                }
            }
        }

        private static bool InitializerReferences(VarDecl variable, TagDecl declaration)
        {
            if (variable.Init == null)
                return false;
            bool References(CXCursor cursor) => cursor == declaration.Handle ||
                clang.getCursorReferenced(cursor) == declaration.Handle ||
                clang.getTypeDeclaration(cursor.Type.CanonicalType) == declaration.Handle;
            if (References(variable.Init.Handle))
                return true;
            bool found = false;
            variable.Init.Handle.VisitChildren((cursor, _, _) =>
            {
                if (!References(cursor))
                    return CXChildVisitResult.CXChildVisit_Recurse;
                found = true;
                return CXChildVisitResult.CXChildVisit_Break;
            }, default);
            return found;
        }

        private static bool IsBuiltinDeclaration(Decl declaration)
        {
            if (declaration is FunctionDecl function)
                return function.Attrs.Any(attribute => attribute.Kind == CX_AttrKind.CX_AttrKind_Builtin);
            if (declaration is not LinkageSpecDecl linkage)
                return false;
            var children = linkage.Decls.ToArray();
            return children.Length != 0 && children.All(IsBuiltinDeclaration);
        }

        private void ReadActiveDefinitions(TranslationUnit unit)
        {
            var references = new Dictionary<string, CXCursor>(StringComparer.Ordinal);
            _ = unit.Handle.Cursor.VisitChildren((cursor, _, _) =>
            {
                if (cursor.Kind == CXCursorKind.CXCursor_MacroExpansion &&
                    AtLine(cursor.Location, presenceLines, out string name))
                {
                    using var spelling = cursor.Spelling;
                    var reference = clang.getCursorReferenced(cursor);
                    if (spelling.ToString() == name && reference.Kind == CXCursorKind.CXCursor_MacroDefinition)
                        references[name] = reference;
                }
                return CXChildVisitResult.CXChildVisit_Continue;
            }, default);
            var skipped = new List<(uint Start, uint End)>();
            var ranges = unit.Handle.GetSkippedRanges(unit.Handle.GetFile(sourceFile));
            if (ranges != null)
            {
                try
                {
                    uint count = ranges->count;
                    for (uint index = 0; index < count; index++)
                    {
                        ranges->ranges[index].Start.GetFileLocation(out _, out uint start, out _, out _);
                        ranges->ranges[index].End.GetFileLocation(out _, out uint end, out _, out _);
                        skipped.Add((start, end));
                    }
                }
                finally
                {
                    clang.disposeSourceRangeList(ranges);
                }
            }
            skipped.Sort((left, right) => left.Start.CompareTo(right.Start));
            int current = 0;
            foreach (var query in presenceLines)
            {
                while (current < skipped.Count && skipped[current].End < query.Key)
                    current++;
                if (current < skipped.Count && skipped[current].Start <= query.Key && query.Key <= skipped[current].End)
                    continue;
                defined.Add(query.Value);
                if (references.TryGetValue(query.Value, out var reference))
                    active[query.Value] = ReadMacro(reference);
            }
        }

        private Macro ReadMacro(CXCursor cursor)
        {
            cursor.Location.GetFileLocation(out var file, out uint line, out uint column, out _);
            CXToken* tokens;
            uint count;
            clang.tokenize(original.Handle, cursor.Extent, &tokens, &count);
            var text = new List<string>((int)count);
            try
            {
                for (uint index = 0; index < count; index++)
                {
                    if (tokens[index].Kind == CXTokenKind.CXToken_Comment)
                        continue;
                    using var spelling = clang.getTokenSpelling(original.Handle, tokens[index]);
                    text.Add(spelling.ToString());
                }
            }
            finally
            {
                clang.disposeTokens(original.Handle, tokens, count);
            }
            int body = 1;
            var parameters = new List<string>();
            bool functionLike = clang.Cursor_isMacroFunctionLike(cursor) != 0;
            if (functionLike)
            {
                body++;
                while (body < text.Count && text[body] != ")")
                {
                    if (text[body] != ",")
                        parameters.Add(text[body]);
                    body++;
                }
                body++;
            }
            return new Macro(file.ToString(), line, column, functionLike, parameters.ToArray(),
                string.Join(" ", text.Skip(body)));
        }

        private string DirectCastWrapper(string name)
        {
            if (!active.TryGetValue(name, out var macro) || !macro.FunctionLike || macro.Parameters.Length != 1)
                return null;
            string body = ConstantsScraper.StripMacroParentheses(macro.Body);
            Match cast = Regex.Match(body, @"\A\(\s*([_A-Za-z][\w: ]*)\s*\)\s*(.+)\z");
            return cast.Success && ConstantsScraper.StripMacroParentheses(cast.Groups[2].Value) == macro.Parameters[0] &&
                StorageOfType(cast.Groups[1].Value.Trim()) != null ? cast.Groups[1].Value.Trim() : null;
        }

        private string StorageOfType(string name)
        {
            if (typeStorage.Count == 0)
            {
                typeStorage["bool"] = typeStorage["_Bool"] = "bool";
                typeStorage["char"] = unsignedChar ? "byte" : "sbyte";
                foreach (var pair in new[]
                {
                    ("signed char", "sbyte"), ("unsigned char", "byte"), ("short", "short"),
                    ("short int", "short"), ("signed short", "short"), ("unsigned short", "ushort"),
                    ("unsigned short int", "ushort"), ("int", "int"), ("signed", "int"), ("signed int", "int"),
                    ("unsigned", "uint"), ("unsigned int", "uint"), ("long", "int"), ("long int", "int"),
                    ("signed long", "int"), ("unsigned long", "uint"), ("unsigned long int", "uint"),
                    ("long long", "long"), ("long long int", "long"), ("unsigned long long", "ulong"),
                    ("unsigned long long int", "ulong"), ("__int64", "long"), ("unsigned __int64", "ulong"),
                    ("wchar_t", "char"), ("char16_t", "char"),
                })
                    typeStorage[pair.Item1] = pair.Item2;
                _ = original.Handle.Cursor.VisitChildren((cursor, _, _) =>
                {
                    if (cursor.Kind == CXCursorKind.CXCursor_TypedefDecl)
                    {
                        using var spelling = cursor.Spelling;
                        var type = clang.getTypedefDeclUnderlyingType(cursor).CanonicalType;
                        string storage = type.kind == CXTypeKind.CXType_Pointer ? "pointer" : NativeConstantExtractor.GetStorage(type);
                        if (storage != null)
                            typeStorage[spelling.ToString()] = storage;
                    }
                    return cursor.Kind == CXCursorKind.CXCursor_LinkageSpec
                        ? CXChildVisitResult.CXChildVisit_Recurse : CXChildVisitResult.CXChildVisit_Continue;
                }, default);
            }
            return typeStorage.GetValueOrDefault(name);
        }

        internal bool RecordDiagnostic(CXDiagnostic diagnostic, string message)
        {
            var names = new HashSet<string>(StringComparer.Ordinal);
            Collect(diagnostic);
            if (names.Count == 0)
                return false;
            if (diagnostic.Severity is CXDiagnosticSeverity.CXDiagnostic_Error or CXDiagnosticSeverity.CXDiagnostic_Fatal)
                foreach (string name in names)
                {
                    if (!errors.TryGetValue(name, out var messages))
                        errors[name] = messages = new();
                    messages.Add(message);
                }
            return true;

            void Collect(CXDiagnostic current)
            {
                if (AtLine(current.Location, probeLines, out string name))
                    names.Add(name);
                var children = current.ChildDiagnostics;
                uint count = children.NumDiagnostics;
                for (uint index = 0; index < count; index++)
                {
                    using var child = children.GetDiagnostic(index);
                    Collect(child);
                }
            }
        }

        private bool AtLine(CXSourceLocation location, Dictionary<uint, string> lines, out string name)
        {
            location.GetFileLocation(out var file, out uint line, out _, out _);
            name = null;
            return string.Equals(file.ToString(), sourceFile, StringComparison.OrdinalIgnoreCase) &&
                lines.TryGetValue(line, out name);
        }

        internal sealed record Macro(string Header, uint Line, uint Column, bool FunctionLike, string[] Parameters, string Body)
        {
            internal string File => Header;
        }
    }
}
