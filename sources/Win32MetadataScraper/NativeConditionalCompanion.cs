using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.Json;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;

namespace Win32MetadataScraper
{
    internal sealed class NativeConditionalCompanion : IDisposable
    {
        private readonly Func<string[], CXTranslationUnit_Flags, TranslationUnit> parse;
        private readonly CXTranslationUnit_Flags flags;
        private readonly List<TranslationUnit> ownedUnits = new();
        private readonly List<object> evidence = new();
        private readonly List<ParseAttempt> parseAttempts = new();
        private readonly List<NativeLegacyMember> legacyMembers = new();
        private readonly Dictionary<string, string> sourceHashes = new(StringComparer.OrdinalIgnoreCase);
        private readonly string evidencePath;
        private readonly string[] primaryArguments;
        private TranslationUnit bindingUnit;
        private bool ansiAttempted;
        private bool projectionCompleted;

        private NativeConditionalCompanion(string[] arguments, CXTranslationUnit_Flags flags,
            Func<string[], CXTranslationUnit_Flags, TranslationUnit> parse, string evidencePath)
        {
            primaryArguments = arguments;
            Arguments = arguments.Concat(new[] { "-UUNICODE" }).ToArray();
            this.flags = flags;
            this.parse = parse;
            this.evidencePath = evidencePath;
        }

        internal string[] Arguments { get; }
        internal TranslationUnit Unit { get; private set; }
        internal IReadOnlyList<FunctionDecl> Functions { get; private set; } = Array.Empty<FunctionDecl>();
        internal Dictionary<string, string> ScopedRemaps { get; } = new(StringComparer.Ordinal);
        internal IReadOnlyList<NativeLegacyMember> LegacyMembers => legacyMembers;

        internal TranslationUnit BindingUnit
        {
            get
            {
                if (Unit == null)
                    return null;
                if (!flags.HasFlag(CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord))
                    return Unit;
                if (bindingUnit == null)
                {
                    bindingUnit = Parse(Arguments, flags & ~CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord);
                    WriteEvidence();
                }
                return bindingUnit;
            }
        }

        internal static NativeConditionalCompanion Create(TranslationUnit primary, string[] arguments,
            CXTranslationUnit_Flags flags, IReadOnlyCollection<string> traversalFiles,
            IReadOnlyDictionary<string, string> libraries, IReadOnlyDictionary<string, string> authoredRemaps,
            IReadOnlySet<string> excludes, Func<string[], CXTranslationUnit_Flags, TranslationUnit> parse, string evidencePath)
        {
            using var timing = GenerationTiming.BeginSpan("companion.discover-and-recover");
            var result = new NativeConditionalCompanion(arguments, flags, parse, evidencePath);
            try
            {
                if (!HasUnicodeDefinition(arguments))
                    return result;
                result.Discover(primary, traversalFiles, libraries, authoredRemaps, excludes);
                timing?.SetCounter("functionCount", result.Functions.Count);
                timing?.SetCounter("legacyMemberCount", result.LegacyMembers.Count);
                timing?.SetCounter("scopedRemapCount", result.ScopedRemaps.Count);
                timing?.SetCounter("supplementalParseCount", result.parseAttempts.Count);
                result.WriteEvidence();
                return result;
            }
            catch (Exception error)
            {
                result.evidence.Add(new { kind = "failure", error = error.Message });
                result.WriteEvidence();
                result.Dispose();
                throw;
            }
        }

        private void Discover(TranslationUnit primary, IReadOnlyCollection<string> traversalFiles,
            IReadOnlyDictionary<string, string> libraries, IReadOnlyDictionary<string, string> authoredRemaps,
            IReadOnlySet<string> excludes)
        {
            var declarations = Declarations(primary.TranslationUnitDecl).ToArray();
            var nativeFunctions = declarations.OfType<FunctionDecl>().Where(IsGlobalFunction).ToArray();
            var existing = nativeFunctions.Select(function => function.Name).ToHashSet(StringComparer.Ordinal);
            var mapped = libraries.Keys.Where(name => Regex.IsMatch(name, @"\A[A-Za-z_][A-Za-z_0-9]*\z") &&
                !existing.Contains(name) && !excludes.Contains(name) && !string.IsNullOrWhiteSpace(libraries[name]))
                .ToHashSet(StringComparer.Ordinal);
            var files = ResolveFiles(primary, traversalFiles, out var includedFiles);
            var declarationFiles = new Dictionary<CXFile, string>();
            var qualifiedNames = new Dictionary<CXCursor, string>();
            foreach (string path in files)
            {
                var file = primary.Handle.GetFile(path);
                if (!file.Equals(default(CXFile)))
                    sourceHashes[path] = Convert.ToHexString(SHA256.HashData(primary.Handle.GetFileContents(file, out _)));
            }
            var candidates = FindCandidates(primary, files, mapped);
            if (candidates.Count != 0)
            {
                var conditions = new UnicodeConditions(primary, includedFiles.Concat(files));
                candidates = candidates.Where(candidate => conditions.Contains(candidate)).ToList();
                foreach (string path in conditions.SupportFiles)
                    sourceHashes[path] = Convert.ToHexString(SHA256.HashData(primary.Handle.GetFileContents(primary.Handle.GetFile(path), out _)));
            }
            var inheritedMethods = new HashSet<CXCursor>();
            var records = new Stack<CXXRecordDecl>(declarations.OfType<CXXRecordDecl>()
                .Where(IsTraversalDeclaration));
            var visitedRecords = new HashSet<CXCursor>();
            while (records.TryPop(out var record))
            {
                record = (CXXRecordDecl)(record.Definition ?? record);
                if (!visitedRecords.Add(record.Handle.CanonicalCursor))
                    continue;
                inheritedMethods.UnionWith(record.CursorChildren.OfType<CXXMethodDecl>()
                    .Select(method => method.Handle.CanonicalCursor));
                foreach (var basis in record.Bases)
                    if (basis.Type.CanonicalType is RecordType baseType && baseType.Decl is CXXRecordDecl parent)
                        records.Push(parent);
            }
            var macroMembers = declarations.OfType<NamedDecl>()
                .Where(declaration => declaration is FunctionDecl or FieldDecl)
                .Where(declaration => IsTraversalDeclaration(declaration) ||
                    inheritedMethods.Contains(declaration.Handle.CanonicalCursor))
                .Where(declaration => !excludes.Contains(declaration.Name) &&
                !excludes.Contains(QualifiedName(declaration)) &&
                !authoredRemaps.ContainsKey(declaration.Name) &&
                !authoredRemaps.ContainsKey(QualifiedName(declaration)))
                .Select(declaration => (Declaration: declaration, Written: NativeMacroNames.GetWrittenMemberName(declaration)))
                .Where(value => value.Written != null && (IsLegacyMember(value.Declaration) ||
                    HasAuthoredAlternative(value.Declaration, value.Written, authoredRemaps)))
                .ToArray();
            if (candidates.Count == 0 && macroMembers.Length == 0)
                return;
            TranslationUnit detailed = primary;
            if (candidates.Count != 0 && !flags.HasFlag(CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord))
                detailed = Parse(primaryArguments, flags | CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord);
            var skipped = ReadSkippedRanges(detailed, candidates);
            if (skipped.Count == 0 && macroMembers.Length == 0)
                return;

            ansiAttempted = true;
            Unit = Parse(Arguments, flags);
            var alternateDeclarations = Declarations(Unit.TranslationUnitDecl).ToArray();
            var recovered = alternateDeclarations.OfType<FunctionDecl>()
                .Where(function => IsGlobalFunction(function) && !function.Handle.IsDefinition &&
                    mapped.Contains(function.Name) && skipped.Any(range => range.Name == function.Name &&
                        range.Contains(NativeSourceIdentity.Of(function))))
                .GroupBy(function => function.Name, StringComparer.Ordinal).Select(group =>
                {
                    var functions = group.DistinctBy(function => function.Handle.CanonicalCursor).ToArray();
                    if (functions.Length != 1)
                        throw new InvalidOperationException($"ANSI companion export '{group.Key}' has ambiguous native declarations.");
                    return functions[0];
                }).ToArray();
            var compatibility = new NativeTypeCompatibility(declarations);
            foreach (var function in recovered)
            {
                try
                {
                    compatibility.Validate(function);
                }
                catch (InvalidOperationException error)
                {
                    evidence.Add(new { kind = "incompatible-export", function.Name,
                        source = NativeSourceIdentity.Of(function).ToString(), error = error.Message,
                        dependencies = compatibility.Witnesses.ToArray() });
                    throw;
                }
                evidence.Add(new { kind = "recovered-export", function.Name, library = libraries[function.Name],
                    source = NativeSourceIdentity.Of(function).ToString(), signature = function.Type.AsString,
                    dependencies = compatibility.Witnesses.ToArray() });
            }
            Functions = recovered;

            var alternates = alternateDeclarations.OfType<NamedDecl>().ToLookup(NativeSourceIdentity.Of);
            foreach (var member in macroMembers)
            {
                var corresponding = alternates[NativeSourceIdentity.Of(member.Declaration)]
                    .Where(declaration => NativeMacroNames.GetWrittenMemberName(declaration) == member.Written)
                    .DistinctBy(declaration => declaration.Handle.CanonicalCursor).ToArray();
                if (corresponding.Length == 0)
                {
                    evidence.Add(new { kind = "remap-candidate-not-applicable",
                        source = NativeSourceIdentity.Of(member.Declaration).ToString(), written = member.Written,
                        reason = "No ANSI declaration exists at the primary source identity." });
                    continue;
                }
                if (corresponding.Length != 1)
                    throw new InvalidOperationException($"Authored macro remap for '{member.Written}' requires one ANSI declaration " +
                        $"at {NativeSourceIdentity.Of(member.Declaration)}; found {corresponding.Length}.");
                var alternate = corresponding[0];
                string alternateName = DeclarationSourceMap.QualifiedName(alternate.Handle);
                if (IsLegacyMember(member.Declaration) &&
                    NativeMemberNameProjection.ParentIdentity(member.Declaration) != NativeMemberNameProjection.ParentIdentity(alternate))
                    throw new InvalidOperationException($"Macro-selected member '{member.Written}' has different native parents " +
                        $"at {NativeSourceIdentity.Of(member.Declaration)}.");
                if (!authoredRemaps.TryGetValue(alternateName, out string target) &&
                    !authoredRemaps.TryGetValue(alternate.Name, out target))
                {
                    if (IsLegacyMember(member.Declaration) && member.Declaration.Name != alternate.Name &&
                        !excludes.Contains(alternate.Name) && !excludes.Contains(alternateName))
                    {
                        legacyMembers.Add(new NativeLegacyMember(member.Declaration, alternate.Name));
                        member.Declaration.Location.GetFileLocation(out var declarationFile, out _, out _, out _);
                        RememberSource(primary, declarationFile);
                        evidence.Add(new
                        {
                            kind = "legacy-member-name",
                            source = NativeSourceIdentity.Of(member.Declaration).ToString(),
                            parent = NativeMemberNameProjection.ParentIdentity(member.Declaration),
                            written = member.Written,
                            primaryName = DeclarationSourceMap.QualifiedName(member.Declaration.Handle),
                            alternateName,
                            primarySignature = ((ValueDecl)member.Declaration).Type.AsString,
                            alternateSignature = ((ValueDecl)alternate).Type.AsString,
                            primaryMacroReplacement = RememberMacroReplacement(member.Declaration),
                            alternateMacroReplacement = RememberMacroReplacement(alternate),
                        });
                        continue;
                    }
                    evidence.Add(new { kind = "remap-candidate-not-applicable",
                        source = NativeSourceIdentity.Of(alternate).ToString(), written = member.Written,
                        alternateName, reason = "The compiler-selected ANSI declaration has no authored remap." });
                    continue;
                }
                string primaryName = DeclarationSourceMap.QualifiedName(member.Declaration.Handle);
                if (primaryName == member.Declaration.Name)
                    throw new InvalidOperationException($"Preserving authored macro remap '{alternateName}={target}' requires a declaration-scoped native owner at {NativeSourceIdentity.Of(member.Declaration)}.");
                var proved = macroMembers.Where(value =>
                    DeclarationSourceMap.QualifiedName(value.Declaration.Handle) == primaryName)
                    .Select(value => value.Declaration.Handle.CanonicalCursor).ToHashSet();
                var conflicts = declarations.OfType<NamedDecl>().Where(declaration =>
                    declaration is FunctionDecl or FieldDecl &&
                    DeclarationSourceMap.QualifiedName(declaration.Handle) == primaryName &&
                    !proved.Contains(declaration.Handle.CanonicalCursor)).ToArray();
                if (conflicts.Length != 0)
                    throw new InvalidOperationException($"Authored macro remap for '{primaryName}' cannot rename unproven native overloads at " +
                        string.Join(", ", conflicts.Select(value => NativeSourceIdentity.Of(value))) + ".");
                if (!ScopedRemaps.TryAdd(primaryName, target) && ScopedRemaps[primaryName] != target)
                    throw new InvalidOperationException($"Authored companion remaps disagree for '{primaryName}'.");
                member.Declaration.Location.GetSpellingLocation(out var macroFile, out uint macroLine, out uint macroColumn, out uint macroOffset);
                string macroPath = System.IO.Path.GetFullPath(macroFile.ToString());
                sourceHashes[macroPath] = Convert.ToHexString(SHA256.HashData(primary.Handle.GetFileContents(macroFile, out _)));
                evidence.Add(new { kind = "authored-remap", source = NativeSourceIdentity.Of(member.Declaration).ToString(),
                    written = member.Written, primaryName, alternateName, target,
                    macroReplacement = new { file = macroPath, line = macroLine, column = macroColumn, offset = macroOffset } });
            }

            bool IsTraversalDeclaration(Decl declaration)
            {
                declaration.Location.GetExpansionLocation(out var file, out _, out _, out _);
                if (!declarationFiles.TryGetValue(file, out string path))
                {
                    path = file.ToString();
                    if (path.Length != 0)
                        path = Path.GetFullPath(path);
                    declarationFiles.Add(file, path);
                }
                return files.Contains(path);
            }

            string QualifiedName(NamedDecl declaration)
            {
                if (!qualifiedNames.TryGetValue(declaration.Handle, out string name))
                {
                    name = DeclarationSourceMap.QualifiedName(declaration.Handle);
                    qualifiedNames.Add(declaration.Handle, name);
                }
                return name;
            }
        }

        private static bool IsGlobalFunction(FunctionDecl function)
            => function is not CXXMethodDecl && DeclarationSourceMap.QualifiedName(function.Handle) == function.Name;

        private static bool IsLegacyMember(NamedDecl declaration)
            => declaration is FieldDecl or CXXMethodDecl { IsVirtual: true };

        private object RememberMacroReplacement(NamedDecl declaration)
        {
            declaration.Location.GetSpellingLocation(out var file, out uint line, out uint column, out uint offset);
            return new { file = RememberSource(declaration.TranslationUnit, file), line, column, offset };
        }

        private string RememberSource(TranslationUnit unit, CXFile file)
        {
            string path = Path.GetFullPath(file.ToString());
            sourceHashes[path] = Convert.ToHexString(SHA256.HashData(unit.Handle.GetFileContents(file, out _)));
            return path;
        }

        private static unsafe HashSet<string> ResolveFiles(TranslationUnit unit, IEnumerable<string> configured,
            out HashSet<string> includedFiles)
        {
            var included = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            CXInclusionVisitor visitor = (file, _, _, _) => included.Add(Path.GetFullPath(((CXFile)file).ToString()));
            unit.Handle.GetInclusions(visitor, default);
            GC.KeepAlive(visitor);
            includedFiles = included;
            var result = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
            foreach (string path in configured)
            {
                if (Path.GetFileName(path) != path)
                    result.Add(Path.GetFullPath(path));
                else
                {
                    var matches = included.Where(file => string.Equals(Path.GetFileName(file), path,
                        StringComparison.OrdinalIgnoreCase)).ToArray();
                    if (matches.Length > 1)
                        throw new InvalidOperationException($"Companion traversal header '{path}' has ambiguous native inclusion providers.");
                    if (matches.Length == 1)
                        result.Add(matches[0]);
                }
            }
            return result;
        }

        internal static IEnumerable<Decl> Declarations(Decl root)
        {
            var visited = new HashSet<Cursor>();
            var pending = new Stack<Decl>();
            pending.Push(root);
            while (pending.Count != 0)
            {
                var declaration = pending.Pop();
                if (!visited.Add(declaration))
                    continue;
                yield return declaration;
                foreach (var child in declaration.CursorChildren.OfType<Decl>())
                    pending.Push(child);
            }
        }

        private static List<Candidate> FindCandidates(TranslationUnit unit, IReadOnlySet<string> files,
            IReadOnlySet<string> names)
        {
            var result = new List<Candidate>();
            if (names.Count == 0)
                return result;
            foreach (string path in files)
            {
                var file = unit.Handle.GetFile(path);
                if (file.Equals(default(CXFile)))
                    continue;
                var contents = unit.Handle.GetFileContents(file, out _);
                var tokens = unit.Handle.Tokenize(CXSourceRange.Create(unit.Handle.GetLocationForOffset(file, 0),
                    unit.Handle.GetLocationForOffset(file, checked((uint)contents.Length))));
                try
                {
                    for (int index = 0; index + 1 < tokens.Length; index++)
                    {
                        if (tokens[index].Kind != CXTokenKind.CXToken_Identifier)
                            continue;
                        using var spelling = tokens[index].GetSpelling(unit.Handle);
                        string name = spelling.ToString();
                        if (!names.Contains(name))
                            continue;
                        using var next = tokens[index + 1].GetSpelling(unit.Handle);
                        if (next.ToString() != "(")
                            continue;
                        tokens[index].GetLocation(unit.Handle).GetExpansionLocation(out _, out _, out _, out uint offset);
                        int start = checked((int)offset);
                        while (start > 0 && contents[start - 1] != '\n')
                            start--;
                        string prefix = Encoding.UTF8.GetString(contents.Slice(start, checked((int)offset) - start)).TrimStart();
                        if (!prefix.StartsWith("#", StringComparison.Ordinal))
                            result.Add(new Candidate(Path.GetFullPath(path), offset, name));
                    }
                }
                finally
                {
                    unit.Handle.DisposeTokens(tokens);
                }
            }
            return result;
        }

        private List<SkippedCandidate> ReadSkippedRanges(TranslationUnit unit, IEnumerable<Candidate> candidates)
        {
            var result = new List<SkippedCandidate>();
            foreach (var group in candidates.GroupBy(candidate => candidate.File, StringComparer.OrdinalIgnoreCase))
                ReadFile(group);
            return result;

            unsafe void ReadFile(IGrouping<string, Candidate> group)
            {
                var file = unit.Handle.GetFile(group.Key);
                var ranges = unit.Handle.GetSkippedRanges(file);
                try
                {
                    if (ranges == null)
                        throw new InvalidOperationException($"Compiler skipped ranges were unavailable for candidate header '{group.Key}'.");
                    for (uint index = 0; index < ranges->count; index++)
                    {
                        ranges->ranges[index].Start.GetExpansionLocation(out _, out _, out _, out uint start);
                        ranges->ranges[index].End.GetExpansionLocation(out _, out _, out _, out uint end);
                        foreach (var candidate in group.Where(candidate => candidate.Offset >= start && candidate.Offset < end))
                        {
                            result.Add(new SkippedCandidate(group.Key, start, end, candidate.Name));
                            evidence.Add(new { kind = "skipped-export-candidate", candidate.File, candidate.Name, start, end });
                        }
                    }
                }
                finally
                {
                    if (ranges != null)
                        ranges->Dispose();
                }
            }
        }

        private static bool HasAuthoredAlternative(NamedDecl declaration, string written,
            IReadOnlyDictionary<string, string> remaps)
        {
            declaration.Location.GetSpellingLocation(out var file, out _, out _, out _);
            string source = Encoding.UTF8.GetString(declaration.TranslationUnit.Handle.GetFileContents(file, out _));
            string qualified = DeclarationSourceMap.QualifiedName(declaration.Handle);
            string scope = qualified[..^declaration.Name.Length];
            return Regex.Matches(source, @"(?m)^[ \t]*#[ \t]*define[ \t]+" + Regex.Escape(written) +
                @"[ \t]+(?<name>[A-Za-z_][A-Za-z_0-9]*)\b")
                .Any(match => remaps.ContainsKey(match.Groups["name"].Value) ||
                    remaps.ContainsKey(scope + match.Groups["name"].Value));
        }

        private static bool HasUnicodeDefinition(IEnumerable<string> arguments)
        {
            bool unicode = false;
            string pending = null;
            foreach (string argument in arguments)
            {
                string value = pending == null ? argument : pending + argument;
                pending = argument is "-D" or "-U" ? argument : null;
                if (value is "-DUNICODE" || value.StartsWith("-DUNICODE=", StringComparison.Ordinal))
                    unicode = true;
                else if (value == "-UUNICODE")
                    unicode = false;
            }
            return unicode;
        }

        private TranslationUnit Parse(string[] arguments, CXTranslationUnit_Flags flags)
        {
            using var timing = GenerationTiming.BeginSpan("companion.parse");
            timing?.SetCounter("detailedPreprocessingRecord",
                flags.HasFlag(CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord) ? 1 : 0);
            var attempt = new ParseAttempt(arguments, flags.ToString());
            parseAttempts.Add(attempt);
            var unit = parse(arguments, flags) ??
                throw new InvalidOperationException("Native conditional companion parsing failed; no supplemental declarations were emitted.");
            attempt.Succeeded = true;
            ownedUnits.Add(unit);
            return unit;
        }

        private void WriteEvidence()
        {
            using var timing = GenerationTiming.BeginSpan("output.companion-evidence");
            Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(evidencePath)));
            File.WriteAllText(evidencePath, JsonSerializer.Serialize(new
            {
                schemaVersion = 1,
                primaryArguments,
                primaryFlags = flags.ToString(),
                companionArguments = ansiAttempted ? Arguments : Array.Empty<string>(),
                supplementalParses = parseAttempts.Count,
                parseAttempts,
                projectionCompleted,
                files = sourceHashes,
                evidence,
            }, new JsonSerializerOptions { WriteIndented = true }), new UTF8Encoding(false));
        }

        internal void CompleteProjection()
        {
            if (!File.Exists(evidencePath))
                return;
            projectionCompleted = true;
            WriteEvidence();
        }

        public void Dispose()
        {
            foreach (var unit in ownedUnits.AsEnumerable().Reverse())
                unit.Dispose();
        }

        private sealed record Candidate(string File, uint Offset, string Name);

        private sealed record ParseAttempt(string[] Arguments, string Flags)
        {
            public bool Succeeded { get; set; }
        }

        private sealed class UnicodeConditions
        {
            private readonly Dictionary<string, List<ConditionalRange>> ranges = new(StringComparer.OrdinalIgnoreCase);
            private readonly HashSet<string> dependentNames = new(StringComparer.Ordinal) { "UNICODE" };
            internal HashSet<string> SupportFiles { get; } = new(StringComparer.OrdinalIgnoreCase);

            internal UnicodeConditions(TranslationUnit unit, IEnumerable<string> files)
            {
                var definitions = new List<(string Name, string File, string[] Dependencies)>();
                foreach (string path in files.Distinct(StringComparer.OrdinalIgnoreCase))
                {
                    var file = unit.Handle.GetFile(path);
                    if (file.Equals(default(CXFile)))
                        continue;
                    string source = Encoding.Latin1.GetString(unit.Handle.GetFileContents(file, out _));
                    source = Regex.Replace(source, @"/\*.*?\*/|//[^\r\n]*|""(?:\\.|[^""\\])*""|'(?:\\.|[^'\\])*'",
                        match => new string(match.Value.Select(value => value is '\r' or '\n' ? value : ' ').ToArray()),
                        RegexOptions.Singleline);
                    var stack = new Stack<HashSet<string>>();
                    var scopes = new List<ConditionalRange>();
                    int previous = 0;
                    foreach (Match directive in Regex.Matches(source,
                        @"(?m)^[ \t]*#[ \t]*(?<kind>if|ifdef|ifndef|elif|else|endif|define)\b(?<body>(?:[^\r\n]*\\\r?\n)*[^\r\n]*)"))
                    {
                        if (stack.Count != 0 && directive.Index > previous)
                            scopes.Add(new ConditionalRange((uint)previous, (uint)directive.Index,
                                stack.SelectMany(frame => frame).Distinct(StringComparer.Ordinal).ToArray()));
                        string[] names = Regex.Matches(directive.Groups["body"].Value, @"[A-Za-z_][A-Za-z_0-9]*")
                            .Select(match => match.Value).ToArray();
                        switch (directive.Groups["kind"].Value)
                        {
                            case "if":
                            case "ifdef":
                            case "ifndef":
                                stack.Push(names.ToHashSet(StringComparer.Ordinal));
                                break;
                            case "elif" when stack.Count != 0:
                                stack.Peek().UnionWith(names);
                                break;
                            case "endif" when stack.Count != 0:
                                stack.Pop();
                                break;
                            case "define" when names.Length != 0:
                                definitions.Add((names[0], path, names.Skip(1).Concat(stack.SelectMany(frame => frame))
                                    .Distinct(StringComparer.Ordinal).ToArray()));
                                break;
                        }
                        previous = directive.Index + directive.Length;
                    }
                    if (stack.Count != 0 && previous < source.Length)
                        scopes.Add(new ConditionalRange((uint)previous, (uint)source.Length,
                            stack.SelectMany(frame => frame).Distinct(StringComparer.Ordinal).ToArray()));
                    ranges[path] = scopes;
                }
                bool changed;
                do
                {
                    changed = false;
                    foreach (var definition in definitions.Where(definition => definition.Dependencies.Any(dependentNames.Contains)))
                    {
                        SupportFiles.Add(definition.File);
                        changed |= dependentNames.Add(definition.Name);
                    }
                }
                while (changed);
            }

            internal bool Contains(Candidate candidate) => ranges.TryGetValue(candidate.File, out var fileRanges) &&
                fileRanges.Any(range => candidate.Offset >= range.Start && candidate.Offset < range.End &&
                    range.Dependencies.Any(dependentNames.Contains));

            private sealed record ConditionalRange(uint Start, uint End, string[] Dependencies);
        }

        private sealed record SkippedCandidate(string File, uint Start, uint End, string Name)
        {
            internal bool Contains(NativeSourceIdentity identity)
                => string.Equals(File, identity.File, StringComparison.OrdinalIgnoreCase) &&
                    identity.Offset >= Start && identity.Offset < End;
        }
    }
}
