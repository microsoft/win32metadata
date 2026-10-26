// RemapDiscovery: AST-based discovery of typedef-tag and function pointer remappings.
//
// This class walks a ClangSharp TranslationUnit AST to find:
// 1. Tag-typedef pairs (struct _FOO → FOO)
// 2. Function pointer prototype/alias pairs (TIMECALLBACK → LPTIMECALLBACK)
//
// The discovery results can be used to auto-generate --remap, --exclude, and
// --reducePointerLevel entries for PInvokeGenerator.

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;

namespace Win32MetadataScraper
{

/// <summary>
/// Results from walking a translation unit's AST for typedef-tag and
/// function pointer relationships.
/// </summary>
public class DiscoveryResult
{
    /// <summary>Tag name → list of typedef names. One tag may have multiple typedefs.</summary>
    public Dictionary<string, List<string>> TagToTypedefs { get; } = new();

    /// <summary>Qualified typedef name to its canonical tag, including same-level aliases.</summary>
    public Dictionary<string, string> NativeTypedefTags { get; } = new();

    /// <summary>Names of tags that are enums.</summary>
    public HashSet<string> EnumTags { get; } = new();

    /// <summary>Tag name → header file where the typedef was found.</summary>
    public Dictionary<string, string> TagToHeaderFile { get; } = new();

    /// <summary>
    /// Function typedef name → list of pointer-adding alias names.
    /// These are aliases declared as <c>typedef NAME *ALIAS;</c> (adds one level of pointer).
    /// </summary>
    public Dictionary<string, List<string>> FnProtoToPointerTypedefs { get; } = new();

    /// <summary>
    /// Function typedef name → list of same-level alias names.
    /// These are aliases declared as <c>typedef NAME ALIAS;</c> (no added pointer).
    /// </summary>
    public Dictionary<string, List<string>> FnSameLevelAliases { get; } = new();

    /// <summary>Names of typedefs whose underlying type is a bare FunctionProtoType (no pointer).</summary>
    public HashSet<string> FnBareFunctionTypedefs { get; } = new();

    /// <summary>Names of typedefs whose underlying type is PointerType → FunctionProtoType (already a pointer).</summary>
    public HashSet<string> FnPointerFunctionTypedefs { get; } = new();

    /// <summary>All fn proto typedef names (bare + pointer). Convenience accessor.</summary>
    public IEnumerable<string> FnProtoTypedefNames => FnBareFunctionTypedefs.Concat(FnPointerFunctionTypedefs);
}

/// <summary>
/// Resolved remap entries ready for use with PInvokeGenerator.
/// </summary>
public class ResolvedRemaps
{
    /// <summary>Tag → typedef remaps (e.g., _FOO=FOO).</summary>
    public Dictionary<string, string> TagRemaps { get; set; } = new();

    /// <summary>Function pointer prototype → pointer typedef remaps (e.g., TIMECALLBACK=LPTIMECALLBACK).</summary>
    public Dictionary<string, string> FnPtrRemaps { get; set; } = new();

    /// <summary>Function pointer typedef names to exclude from generation.</summary>
    public HashSet<string> FnPtrExcludes { get; set; } = new();

    /// <summary>Function pointer typedef names that need pointer level reduction in the emitter.</summary>
    public HashSet<string> ReducePointerLevel { get; set; } = new();
}

public static class RemapDiscovery
{
    /// <summary>
    /// Walks the AST starting from the given declaration to collect all typedef-tag
    /// relationships and function pointer typedef pairs.
    /// </summary>
    public static DiscoveryResult WalkTranslationUnit(Decl rootDecl)
    {
        var result = new DiscoveryResult();
        WalkDecl(rootDecl, result);
        return result;
    }

    internal static Dictionary<string, string> CreateBindingRemaps(
        DiscoveryResult discovery, IReadOnlyDictionary<string, string> remaps, ISet<string> autoRemapExcludes)
    {
        var result = new Dictionary<string, string>(remaps);
        // Native identity and existing no-rename choices are binding decisions.
        foreach (var pair in discovery.TagToTypedefs)
            if (pair.Value.Contains(pair.Key, StringComparer.Ordinal) ||
                autoRemapExcludes.Contains(pair.Key) || IsLikelyComInterfaceTag(pair.Key))
                result.TryAdd(pair.Key, pair.Key);

        foreach (var group in discovery.NativeTypedefTags.GroupBy(pair => pair.Value, StringComparer.Ordinal))
        {
            string tag = group.Key;
            string tagName = SimpleName(tag);
            var aliases = group.Where(pair => pair.Key != tag).ToArray();
            if (aliases.Length == 0 || result.ContainsKey(tag) || result.ContainsKey(tagName) ||
                !aliases.All(pair => HasExplicitProjection(pair.Key, tag, tagName)))
                continue;
            // Explicit alias projections do not rename the underlying native tag.
            result.Add(tag, tagName);
        }

        foreach (var pair in remaps)
        {
            if (pair.Value.EndsWith("___", StringComparison.Ordinal) &&
                discovery.NativeTypedefTags.TryGetValue(pair.Value[..^3], out string tag) &&
                tag == pair.Key)
            {
                // ClangSharp's force marker preserves the authored temporary name;
                // the native alias proof does not authorize an arbitrary remap.
                result[pair.Key] = "@" + pair.Value;
            }
        }
        return result;

        static string SimpleName(string name)
        {
            int separator = name.LastIndexOf("::", StringComparison.Ordinal);
            return separator < 0 ? name : name.Substring(separator + 2);
        }

        bool HasExplicitProjection(string alias, string tag, string tagName)
        {
            string aliasName = SimpleName(alias);
            return (remaps.TryGetValue(alias, out string target) || remaps.TryGetValue(aliasName, out target)) &&
                target != alias && target != aliasName && target != tag && target != tagName;
        }
    }

    internal static Dictionary<string, string> FindEmbeddedIncompleteRecordPointerRemaps(
        Decl rootDecl, NativeCursorIndex nativeDeclarations = null)
    {
        using var timing = GenerationTiming.BeginSpan("remap-discovery.embedded-type-uses");
        using var preparationTiming = GenerationTiming.BeginSpan("remap-discovery.embedded-prepare-declarations");
        var declarations = (nativeDeclarations ?? new NativeCursorIndex(rootDecl)).Cursors;
        var declaredRecords = declarations.Where(IsRecordDeclaration)
            .Where(record => !IsRecordDeclaration(record.LexicalParent) ||
                record.LexicalParent == record.SemanticParent)
            .Select(record => record.CanonicalCursor).ToHashSet();
        preparationTiming?.SetCounter("declarationCount", declarations.Count);
        preparationTiming?.SetCounter("declaredRecordCount", declaredRecords.Count);
        preparationTiming?.Dispose();
        using var seedTiming = GenerationTiming.BeginSpan("remap-discovery.embedded-seed-types");
        var pending = new Stack<(CXType Type, bool ValueUse, bool BehindPointer)>();
        var visited = new HashSet<(CXType Type, bool ValueUse, bool BehindPointer)>();
        var canonicalTypes = new Dictionary<CXType, CXType>();
        var byValue = new HashSet<string>(StringComparer.Ordinal);
        var result = new Dictionary<string, string>(StringComparer.Ordinal);
        foreach (var declaration in declarations)
        {
            var kind = declaration.DeclKind;
            if (kind is >= CX_DeclKind.CX_DeclKind_FirstValue and <= CX_DeclKind.CX_DeclKind_LastValue)
                pending.Push((declaration.Type, true, false));
            else if (kind is >= CX_DeclKind.CX_DeclKind_FirstTypedefName and <= CX_DeclKind.CX_DeclKind_LastTypedefName)
                pending.Push((declaration.TypedefDeclUnderlyingType, false, false));
        }
        timing?.SetCounter("declarationCount", declarations.Count);
        timing?.SetCounter("initialTypeUseCount", pending.Count);
        seedTiming?.SetCounter("initialTypeUseCount", pending.Count);
        seedTiming?.Dispose();
        using var visitTiming = GenerationTiming.BeginSpan("remap-discovery.embedded-visit-types");
        while (pending.Count != 0)
        {
            var (type, valueUse, behindPointer) = pending.Pop();
            if (!canonicalTypes.TryGetValue(type, out var canonical))
                canonicalTypes.Add(type, canonical = type.CanonicalType);
            type = canonical;
            if (!visited.Add((type, valueUse, behindPointer)))
                continue;
            switch (type.TypeClass)
            {
                case CX_TypeClass.CX_TypeClass_Pointer:
                    pending.Push((type.PointeeType, valueUse, true));
                    break;
                case CX_TypeClass.CX_TypeClass_Record:
                {
                    var record = type.Declaration;
                    var definition = record.Definition;
                    if ((!definition.IsNull ? definition : record).IsCompleteDefinition ||
                        declaredRecords.Contains(record.CanonicalCursor))
                        break;
                    // Keep the compiler record identity without constructing every managed type wrapper.
                    string name = DeclarationSourceMap.QualifiedName(record);
                    if (name.Length != 0)
                    {
                        if (behindPointer)
                            result.TryAdd(name, "void");
                        else if (valueUse)
                            byValue.Add(name);
                    }
                    break;
                }
                case CX_TypeClass.CX_TypeClass_FunctionProto:
                    pending.Push((type.ResultType, true, false));
                    for (uint index = 0; index < type.NumArgTypes; index++)
                        pending.Push((type.GetArgType(index), true, false));
                    break;
                case CX_TypeClass.CX_TypeClass_FunctionNoProto:
                    pending.Push((type.ResultType, true, false));
                    break;
                case CX_TypeClass.CX_TypeClass_ConstantArray:
                case CX_TypeClass.CX_TypeClass_ArrayParameter:
                case CX_TypeClass.CX_TypeClass_IncompleteArray:
                case CX_TypeClass.CX_TypeClass_VariableArray:
                case CX_TypeClass.CX_TypeClass_DependentSizedArray:
                    pending.Push((type.ArrayElementType, valueUse, behindPointer));
                    break;
                case CX_TypeClass.CX_TypeClass_LValueReference:
                case CX_TypeClass.CX_TypeClass_RValueReference:
                    pending.Push((type.PointeeType, valueUse, false));
                    break;
            }
        }
        timing?.SetCounter("canonicalTypeCount", canonicalTypes.Count);
        timing?.SetCounter("visitedTypeUseCount", visited.Count);
        timing?.SetCounter("pointerRemapCount", result.Count);
        foreach (string name in byValue)
            if (result.ContainsKey(name))
                throw new InvalidOperationException($"Incomplete native record '{name}' is used by value; opaque pointer storage cannot establish its layout.");
        return result;
    }

    private static bool IsRecordDeclaration(CXCursor cursor)
        => cursor.DeclKind is >= CX_DeclKind.CX_DeclKind_FirstRecord and <= CX_DeclKind.CX_DeclKind_LastRecord;

    public static HashSet<string> FindInaccessibleCopyMembers(Decl rootDecl, bool excludeFunctionsWithBody)
        => FindInaccessibleCopyMembers(new NativeCursorIndex(rootDecl), excludeFunctionsWithBody);

    internal static HashSet<string> FindInaccessibleCopyMembers(
        NativeCursorIndex nativeDeclarations, bool excludeFunctionsWithBody)
    {
        var result = new HashSet<string>(StringComparer.Ordinal);
        foreach (var record in nativeDeclarations.Cursors.Where(IsRecordDeclaration)
            .Select(nativeDeclarations.GetCursor).OfType<CXXRecordDecl>().Where(record => record.IsCompleteDefinition))
        {
            foreach (var group in record.Methods.GroupBy(method => method.Name))
            {
                // Exclusion keys do not distinguish overloads. Do not hide a
                // callable overload or change a virtual table to omit a private copy member.
                if (!record.CursorChildren.OfType<FunctionTemplateDecl>().Any(template => template.Name == group.Key) &&
                    group.Any(IsInaccessibleCopyMember) && group.All(method =>
                    !method.IsVirtual && (IsInaccessibleCopyMember(method) || excludeFunctionsWithBody && method.HasBody)))
                    result.Add(DeclarationSourceMap.QualifiedName(group.First().Handle));
            }
        }
        return result;

        static bool IsInaccessibleCopyMember(CXXMethodDecl method)
            => method.Access is CX_CXXAccessSpecifier.CX_CXXPrivate or CX_CXXAccessSpecifier.CX_CXXProtected &&
                (method is CXXConstructorDecl constructor && constructor.IsCopyOrMoveConstructor ||
                    method.IsCopyAssignmentOperator || method.IsMoveAssignmentOperator);
    }

    public static string[] ResolveTraversalFiles(Decl rootDecl, IEnumerable<string> configuredFiles)
    {
        var files = configuredFiles.ToArray();
        var unresolved = new HashSet<string>(files.Where(file =>
            Path.GetFileName(file) == file && !File.Exists(file)), StringComparer.OrdinalIgnoreCase);
        if (unresolved.Count == 0)
            return files;

        var candidates = new Dictionary<string, HashSet<string>>(StringComparer.OrdinalIgnoreCase);
        foreach (var declaration in EnumerateDeclarations(rootDecl))
        {
            declaration.Location.GetFileLocation(out var source, out _, out _, out _);
            string path = source.ToString();
            string name = Path.GetFileName(path);
            if (name != null && unresolved.Contains(name))
            {
                if (!candidates.TryGetValue(name, out var paths))
                    candidates[name] = paths = new HashSet<string>(StringComparer.OrdinalIgnoreCase);
                paths.Add(Path.GetFullPath(path));
            }
        }
        return files.Select(file =>
        {
            if (!unresolved.Contains(file) || !candidates.TryGetValue(file, out var paths))
                return file;
            if (paths.Count != 1)
                throw new InvalidOperationException($"Traversal header '{file}' matches distinct native source files: " +
                    string.Join(", ", paths.OrderBy(path => path, StringComparer.OrdinalIgnoreCase)));
            return paths.Single();
        }).ToArray();
    }

    private static IEnumerable<Decl> EnumerateDeclarations(Decl rootDecl)
    {
        var visited = new HashSet<Cursor>();
        var pending = new Stack<Decl>();
        pending.Push(rootDecl);
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

    /// <summary>
    /// Resolves discovered tag-typedef mappings into a flat remap dictionary.
    /// For tags with multiple typedefs, uses disambiguation rules to pick the best one,
    /// or skips the tag if ambiguous (requiring manual override).
    /// </summary>
    public static Dictionary<string, string> ResolveTagRemaps(
        Dictionary<string, List<string>> tagToTypedefs,
        Dictionary<string, string> configuredRemaps)
    {
        var result = new Dictionary<string, string>();

        foreach (var kv in tagToTypedefs)
        {
            string tag = kv.Key;
            var typedefs = kv.Value;

            if (typedefs.Count == 1)
            {
                if (!string.Equals(tag, typedefs[0], StringComparison.Ordinal))
                {
                    result[tag] = typedefs[0];
                }
            }
            else
            {
                // Multiple typedefs — try to disambiguate

                // If one matches the manual config, use that
                if (configuredRemaps.TryGetValue(tag, out string manualValue) && typedefs.Contains(manualValue))
                {
                    result[tag] = manualValue;
                    continue;
                }

                // Heuristic: prefer the typedef that is the "cleaned" version of the tag
                string stripped = null;
                if (tag.StartsWith("_") && tag.Length > 1)
                    stripped = tag.Substring(1);
                else if (tag.StartsWith("tag") && tag.Length > 3 && char.IsUpper(tag[3]))
                    stripped = tag.Substring(3);

                if (stripped != null)
                {
                    var match = typedefs.FirstOrDefault(t => string.Equals(t, stripped, StringComparison.OrdinalIgnoreCase));
                    if (match != null)
                    {
                        result[tag] = match;
                        continue;
                    }
                }

                // Try case-insensitive match of the tag name itself (e.g., in6_addr → IN6_ADDR)
                {
                    var match = typedefs.FirstOrDefault(t => string.Equals(t, tag, StringComparison.OrdinalIgnoreCase));
                    if (match != null)
                    {
                        result[tag] = match;
                        continue;
                    }
                }

                // Can't disambiguate — skip (conservative: no auto-remap for ambiguous tags)
            }
        }

        return result;
    }

    /// <summary>
    /// Filters resolved tag remaps, removing built-in defaults and entries that
    /// conflict with configured manual remaps.
    /// </summary>
    public static Dictionary<string, string> FilterTagRemaps(
        Dictionary<string, string> discovered,
        Dictionary<string, string> configuredRemaps,
        ISet<string> enumTags = null,
        ISet<string> autoRemapExcludes = null)
    {
        autoRemapExcludes ??= new HashSet<string>(StringComparer.Ordinal);
        var builtins = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
            { "intptr_t", "ptrdiff_t", "size_t", "uintptr_t", "_GUID" };
        var result = new Dictionary<string, string>();

        foreach (var kv in discovered)
        {
            string tag = kv.Key;
            string typedef = kv.Value;

            if (builtins.Contains(tag)) continue;
            if (tag == typedef) continue;
            if (autoRemapExcludes.Contains(tag)) continue;
            if (configuredRemaps.TryGetValue(tag, out string configuredValue) && configuredValue != typedef)
                continue;
            if (IsLikelyComInterfaceTag(tag))
                continue;

            // Skip remaps where the typedef is LONGER than the tag (adds a suffix).
            // Normal remaps strip prefixes (_FOO→FOO, tagFOO→FOO).
            // Suffix-adding remaps (GLUnurbs→GLUnurbsObj) indicate the tag name
            // is already the canonical name used in function signatures.
            // A small exception is warranted for enum aliases like
            // ADS_USER_FLAG→ADS_USER_FLAG_ENUM and
            // D3D11_SHADER_TRACKING_OPTION→D3D11_SHADER_TRACKING_OPTIONS.
            if (ShouldSkipSuffixAddingRemap(tag, typedef, enumTags))
                continue;

            result[tag] = typedef;
        }

        return result;
    }

    private static bool IsLikelyComInterfaceTag(string name)
    {
        if (string.IsNullOrEmpty(name) || name.Length < 2)
        {
            return false;
        }

        if (name[0] != 'I' || !char.IsUpper(name[1]))
        {
            return false;
        }

        if (name.EndsWith("Vtbl", StringComparison.Ordinal) || name.Contains('_'))
        {
            return false;
        }

        return name.Any(char.IsLower);
    }

    private static bool ShouldSkipSuffixAddingRemap(string tag, string typedef, ISet<string> enumTags)
    {
        if (typedef.Length <= tag.Length || !typedef.StartsWith(tag, StringComparison.Ordinal))
        {
            return false;
        }

        if (enumTags?.Contains(tag) == true)
        {
            string suffix = typedef.Substring(tag.Length);
            if (suffix == "S" || suffix == "_ENUM")
            {
                return false;
            }
        }

        return true;
    }

    /// <summary>
    /// Resolves function pointer typedef pairs into remap, exclude, and
    /// reducePointerLevel entries. Uses AST structure (bare vs pointer-to-function)
    /// to determine direction, replacing the old name-prefix heuristic.
    ///
    /// Bare function typedefs need pointer reduction even without a named pointer alias.
    /// The "bare function + pointer alias" pattern also chooses the pointer alias:
    ///   typedef void CALLBACK(int x);      // bare function proto
    ///   typedef CALLBACK *LPCALLBACK;      // pointer alias (adds *)
    /// → remap proto→alias, exclude alias, reducePointerLevel alias
    ///
    /// Already-pointer typedefs with a pointer-adding alias also generate fixups:
    ///   typedef DWORD (*ACMDRIVERPROC)(...);  // already a pointer
    ///   typedef ACMDRIVERPROC *LPACMDRIVERPROC; // adds another *
    /// → remap proto→alias, exclude alias, reducePointerLevel alias
    ///
    /// Already-pointer typedefs with same-level aliases (typedef PFOO LPFOO) are
    /// left to manual configuration — the AST alone cannot determine which name
    /// should be canonical.
    /// </summary>
    public static ResolvedRemaps ResolveFunctionPointerFixups(
        DiscoveryResult discovery,
        ISet<string> configuredExcludes = null)
    {
        configuredExcludes ??= new HashSet<string>(StringComparer.Ordinal);
        var result = new ResolvedRemaps();

        // Pass 1: bare function typedefs with pointer aliases
        foreach (var protoName in discovery.FnBareFunctionTypedefs)
        {
            if (!discovery.FnProtoToPointerTypedefs.TryGetValue(protoName, out var aliasNames))
            {
                // A delegate already represents the first native function pointer.
                result.ReducePointerLevel.Add(protoName);
                continue;
            }

            // Filter out aliases that are already manually excluded
            var candidates = aliasNames.Where(a => !configuredExcludes.Contains(a)).ToList();

            if (candidates.Count != 1)
                continue; // Ambiguous or all excluded — skip

            string aliasName = candidates[0];

            // Bare function proto + pointer alias → standard fixup
            result.FnPtrRemaps[protoName] = aliasName;
            result.FnPtrExcludes.Add(aliasName);
            result.ReducePointerLevel.Add(aliasName);
        }

        // Pass 2: already-pointer typedefs with pointer-adding aliases
        // e.g., typedef LRESULT (*ACMDRIVERPROC)(...); typedef ACMDRIVERPROC *LPACMDRIVERPROC;
        // The alias adds another *, so reducePointerLevel is needed.
        foreach (var protoName in discovery.FnPointerFunctionTypedefs)
        {
            if (!discovery.FnProtoToPointerTypedefs.TryGetValue(protoName, out var ptrAliasNames))
                continue;

            var candidates = ptrAliasNames.Where(a => !configuredExcludes.Contains(a)).ToList();

            if (candidates.Count != 1)
                continue;

            string aliasName = candidates[0];

            result.FnPtrRemaps[protoName] = aliasName;
            result.FnPtrExcludes.Add(aliasName);
            result.ReducePointerLevel.Add(aliasName);
        }

        // Already-pointer typedefs with same-level aliases (typedef PFOO LPFOO)
        // are NOT auto-discovered — left to manual configuration.

        return result;
    }

    /// <summary>
    /// Unwraps sugar types (ElaboratedType, AttributedType, ParenType) to get to
    /// the semantically meaningful type underneath.
    /// </summary>
    public static ClangSharp.Type UnwrapType(ClangSharp.Type type)
    {
        while (true)
        {
            if (type is ElaboratedType elab)
                type = elab.NamedType;
            else if (type is AttributedType attr)
                type = attr.ModifiedType;
            else if (type is ParenType paren)
                type = paren.InnerType;
            else
                return type;
        }
    }

    private static void WalkDecl(Decl decl, DiscoveryResult result)
    {
        if (decl is TypedefDecl typedefDecl)
        {
            if (typedefDecl.UnderlyingType.CanonicalType is TagType canonicalTag &&
                !string.IsNullOrEmpty(canonicalTag.Decl.Name))
            {
                result.NativeTypedefTags[DeclarationSourceMap.QualifiedName(typedefDecl.Handle)] =
                    DeclarationSourceMap.QualifiedName(canonicalTag.Decl.Handle);
            }
            var underlyingType = UnwrapType(typedefDecl.UnderlyingType);

            if (underlyingType is TagType tagType)
            {
                var tagDecl = tagType.Decl;
                // Skip tags inside C++ namespaces — PInvokeGenerator handles
                // namespace-qualified types (Gdiplus::, ABI::) internally.
                // Only discover remaps for top-level tags.
                if (tagDecl != null && tagDecl.DeclContext is not NamespaceDecl)
                {
                    string tagName = tagDecl.Name;
                    if (tagDecl.DeclContext is NamedDecl parent)
                        tagName = $"{parent.Name}::{tagName}";

                    string typedefName = typedefDecl.Name;
                    if (!string.IsNullOrEmpty(tagName))
                    {
                        if (tagDecl is EnumDecl)
                        {
                            result.EnumTags.Add(tagName);
                        }

                        if (!result.TagToTypedefs.TryGetValue(tagName, out var list))
                            result.TagToTypedefs[tagName] = list = new List<string>();

                        // Anonymous tags can inherit their first typedef name as a
                        // synthesized tag name. Preserve that identity typedef so a
                        // later alias does not become the auto-selected canonical name.
                        if (!list.Contains(typedefName))
                        {
                            list.Add(typedefName);
                        }

                        if (!result.TagToHeaderFile.ContainsKey(tagName))
                        {
                            var location = typedefDecl.Location;
                            location.GetPresumedLocation(out var fileName, out _, out _);
                            string headerPath = fileName.ToString();
                            if (!string.IsNullOrEmpty(headerPath))
                            {
                                result.TagToHeaderFile[tagName] = headerPath;
                            }
                        }
                    }
                }
            }
            else if (underlyingType is FunctionProtoType)
            {
                result.FnBareFunctionTypedefs.Add(typedefDecl.Name);
            }
            else if (underlyingType is PointerType ptrType)
            {
                var pointee = UnwrapType(ptrType.PointeeType);

                if (pointee is FunctionProtoType)
                {
                    result.FnPointerFunctionTypedefs.Add(typedefDecl.Name);
                }
                else if (pointee is TypedefType tdType)
                {
                    string pointedTypedefName = tdType.Decl?.Name;
                    if (pointedTypedefName != null)
                    {
                        if (!result.FnProtoToPointerTypedefs.TryGetValue(pointedTypedefName, out var ptrList))
                            result.FnProtoToPointerTypedefs[pointedTypedefName] = ptrList = new List<string>();
                        if (!ptrList.Contains(typedefDecl.Name))
                            ptrList.Add(typedefDecl.Name);
                    }
                }
            }
            else if (underlyingType is TypedefType tdType2)
            {
                // Same-level alias: typedef EXISTING_NAME NEW_ALIAS;
                string sourceTypedefName = tdType2.Decl?.Name;
                if (sourceTypedefName != null)
                {
                    if (!result.FnSameLevelAliases.TryGetValue(sourceTypedefName, out var aliasList))
                        result.FnSameLevelAliases[sourceTypedefName] = aliasList = new List<string>();
                    if (!aliasList.Contains(typedefDecl.Name))
                        aliasList.Add(typedefDecl.Name);
                }
            }
        }

        if (decl is IDeclContext context)
        {
            var directDeclarations = new HashSet<Decl>(context.Decls);
            // Walk Decls first (direct declarations)
            foreach (var child in context.Decls)
            {
                WalkDecl(child, result);
            }

            // Also walk CursorChildren to find typedefs from transitively included
            // headers that don't appear in Decls. PInvokeGenerator uses both traversals.
            foreach (var cursor in decl.CursorChildren)
            {
                if (cursor is TypedefDecl && !directDeclarations.Contains((Decl)cursor))
                {
                    WalkDecl((Decl)cursor, result);
                }
            }
        }
    }
}
}
