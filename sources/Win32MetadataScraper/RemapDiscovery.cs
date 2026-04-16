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
using System.Linq;
using ClangSharp;

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

    /// <summary>Names of tags that are enums.</summary>
    public HashSet<string> EnumTags { get; } = new();

    /// <summary>Tag name → header file where the typedef was found.</summary>
    public Dictionary<string, string> TagToHeaderFile { get; } = new();

    /// <summary>Function prototype typedef name → list of pointer-to-function typedef names.</summary>
    public Dictionary<string, List<string>> FnProtoToPointerTypedefs { get; } = new();

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
    /// Only the "bare function + pointer alias" pattern generates fixups:
    ///   typedef void CALLBACK(int x);      // bare function proto
    ///   typedef CALLBACK *LPCALLBACK;      // pointer alias (adds *)
    /// → remap proto→alias, exclude alias, reducePointerLevel alias
    ///
    /// "Already-pointer" typedef aliases (typedef PFOO LPFOO) are skipped —
    /// both names are valid and may be referenced independently. Likewise, if the
    /// pointer alias is already excluded by existing settings, auto-discovery defers
    /// to that manual fixup rather than emitting a duplicate.
    /// </summary>
    public static ResolvedRemaps ResolveFunctionPointerFixups(
        DiscoveryResult discovery,
        ISet<string> configuredExcludes = null)
    {
        configuredExcludes ??= new HashSet<string>(StringComparer.Ordinal);
        var result = new ResolvedRemaps();

        // Only process bare function typedefs — these are the ones that need
        // fixups when they have a pointer alias (the alias adds * indirection).
        foreach (var protoName in discovery.FnBareFunctionTypedefs)
        {
            if (!discovery.FnProtoToPointerTypedefs.TryGetValue(protoName, out var aliasNames))
                continue;

            if (aliasNames.Count != 1)
                continue; // Ambiguous — skip

            string aliasName = aliasNames[0];

            if (configuredExcludes.Contains(aliasName))
                continue;

            // Bare function proto + pointer alias → standard fixup
            // e.g., typedef void TIMECALLBACK(UINT, ...); typedef TIMECALLBACK *LPTIMECALLBACK;
            result.FnPtrRemaps[protoName] = aliasName;
            result.FnPtrExcludes.Add(aliasName);
            result.ReducePointerLevel.Add(aliasName);
        }

        // For already-pointer typedefs (typedef DWORD (*PFOO)(...); typedef PFOO LPFOO;)
        // we do NOT generate fixups. Both names are valid typedef aliases for the
        // same pointer-to-function type, and code may reference either name.
        // The old functionPointerFixups.json had curated entries for specific cases,
        // but auto-excluding all aliases is too aggressive.

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
                string sourceTypedefName = tdType2.Decl?.Name;
                if (sourceTypedefName != null)
                {
                    if (!result.FnProtoToPointerTypedefs.TryGetValue(sourceTypedefName, out var aliasList))
                        result.FnProtoToPointerTypedefs[sourceTypedefName] = aliasList = new List<string>();
                    if (!aliasList.Contains(typedefDecl.Name))
                        aliasList.Add(typedefDecl.Name);
                }
            }
        }

        if (decl is IDeclContext context)
        {
            // Walk Decls first (direct declarations)
            foreach (var child in context.Decls)
            {
                WalkDecl(child, result);
            }

            // Also walk CursorChildren to find typedefs from transitively included
            // headers that don't appear in Decls. PInvokeGenerator uses both traversals.
            foreach (var cursor in decl.CursorChildren)
            {
                if (cursor is TypedefDecl && !context.Decls.Contains((Decl)cursor))
                {
                    WalkDecl((Decl)cursor, result);
                }
            }
        }
    }
}
}


