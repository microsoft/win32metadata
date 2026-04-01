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

    /// <summary>Function prototype typedef name → list of pointer-to-function typedef names.</summary>
    public Dictionary<string, List<string>> FnProtoToPointerTypedefs { get; } = new();

    /// <summary>Names of typedefs whose underlying type is a FunctionProtoType.</summary>
    public HashSet<string> FnProtoTypedefNames { get; } = new();
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
                result[tag] = typedefs[0];
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
        Dictionary<string, string> configuredRemaps)
    {
        var builtins = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
            { "intptr_t", "ptrdiff_t", "size_t", "uintptr_t", "_GUID" };
        var result = new Dictionary<string, string>();

        foreach (var kv in discovered)
        {
            string tag = kv.Key;
            string typedef = kv.Value;

            if (builtins.Contains(tag)) continue;
            if (tag == typedef) continue;
            if (configuredRemaps.TryGetValue(tag, out string configuredValue) && configuredValue != typedef)
                continue;

            result[tag] = typedef;
        }

        return result;
    }

    /// <summary>
    /// Resolves function pointer typedef pairs into remap, exclude, and
    /// reducePointerLevel entries.
    /// </summary>
    public static ResolvedRemaps ResolveFunctionPointerFixups(
        HashSet<string> fnProtoTypedefNames,
        Dictionary<string, List<string>> fnProtoToPointerTypedefs)
    {
        var result = new ResolvedRemaps();

        foreach (var protoName in fnProtoTypedefNames)
        {
            if (!fnProtoToPointerTypedefs.TryGetValue(protoName, out var pointerNames))
                continue;

            if (pointerNames.Count != 1)
                continue; // Ambiguous — skip

            string pointerName = pointerNames[0];

            bool looksLikePointerTypedef =
                pointerName.StartsWith("LP") ||
                pointerName.StartsWith("P") ||
                pointerName.StartsWith("PFN");

            if (!looksLikePointerTypedef)
                continue;

            result.FnPtrRemaps[protoName] = pointerName;
            result.FnPtrExcludes.Add(pointerName);
            result.ReducePointerLevel.Add(pointerName);
        }

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
                if (tagDecl != null)
                {
                    string tagName = tagDecl.Name;
                    if (tagDecl.DeclContext is NamedDecl parent)
                        tagName = $"{parent.Name}::{tagName}";

                    string typedefName = typedefDecl.Name;
                    if (!string.IsNullOrEmpty(tagName) && tagName != typedefName)
                    {
                        if (!result.TagToTypedefs.TryGetValue(tagName, out var list))
                            result.TagToTypedefs[tagName] = list = new List<string>();
                        if (!list.Contains(typedefName))
                            list.Add(typedefName);
                    }
                }
            }
            else if (underlyingType is FunctionProtoType)
            {
                result.FnProtoTypedefNames.Add(typedefDecl.Name);
            }
            else if (underlyingType is PointerType ptrType)
            {
                var pointee = UnwrapType(ptrType.PointeeType);

                if (pointee is FunctionProtoType)
                {
                    result.FnProtoTypedefNames.Add(typedefDecl.Name);
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
            foreach (var child in context.Decls)
            {
                WalkDecl(child, result);
            }
        }
    }
}
}
