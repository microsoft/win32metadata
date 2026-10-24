using System;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    public enum NativeHandleSourceProvider
    {
        Retained,
        Header,
    }

    public sealed record NativeHandleSourceProof(
        NativeHandleSourceProvider Provider,
        string NativeAlias,
        string GeneratedAlias,
        string StorageType)
    {
        public string Kind { get; init; } = NativeHandleSourceProvenance.DeclareHandleKind;
        public string NativeTag { get; init; }
        public bool WrapperIntent { get; init; }
        public int PointerDepth { get; init; }
    }

    public static class NativeHandleSourceProvenance
    {
        public const string DeclareHandleKind = "DECLARE_HANDLE";
        public const string OpaqueStructPointerKind = "TYPEDEF_STRUCT_POINTER";
        private const string MarkerFamily = "/* Win32Metadata.NativeHandleSource.";
        private const string MarkerPrefix = MarkerFamily + "v1 ";
        private const string OpaqueMarkerPrefix = MarkerFamily + "v2 ";
        private const string MarkerSuffix = " */";
        private static readonly string[] PropertyNames = { "provider", "kind", "nativeAlias", "generatedAlias", "storage" };
        private static readonly string[] OpaquePropertyNames = PropertyNames
            .Concat(new[] { "nativeTag", "wrapperIntent", "pointerDepth" }).ToArray();

        // The caller must prove the originating native DECLARE_HANDLE, not infer it from a tag's name or layout.
        public static StructDeclarationSyntax AttachHeaderDeclareHandle(
            StructDeclarationSyntax declaration, string nativeAlias, string generatedPointerStorage) =>
            Attach(declaration, NativeHandleSourceProvider.Header, nativeAlias, generatedPointerStorage);

        public static StructDeclarationSyntax AttachRetainedDeclareHandle(
            StructDeclarationSyntax declaration, string nativeAlias) =>
            Attach(declaration, NativeHandleSourceProvider.Retained, nativeAlias, "void*");

        // The caller must prove an unqualified native struct pointer and explicit native wrapper intent.
        public static StructDeclarationSyntax AttachHeaderOpaqueStructPointer(StructDeclarationSyntax declaration,
            string nativeAlias, string nativeTag, string generatedPointerStorage, bool explicitWrapperIntent) =>
            Attach(declaration, NativeHandleSourceProvider.Header, nativeAlias, generatedPointerStorage,
                OpaqueStructPointerKind, nativeTag, explicitWrapperIntent);

        public static StructDeclarationSyntax AttachRetainedOpaqueStructPointer(StructDeclarationSyntax declaration,
            string nativeAlias, string nativeTag, bool explicitWrapperIntent) =>
            Attach(declaration, NativeHandleSourceProvider.Retained, nativeAlias, "IntPtr",
                OpaqueStructPointerKind, nativeTag, explicitWrapperIntent);

        public static bool TryParseRetainedOpaqueStructFactory(string valueType, out string nativeTag)
        {
            nativeTag = null;
            const string prefix = "typedef struct ";
            if (valueType == null || !valueType.StartsWith(prefix, StringComparison.Ordinal))
                return false;
            try
            {
                nativeTag = NormalizeNativeAlias(valueType.Substring(prefix.Length));
                return true;
            }
            catch (ArgumentException)
            {
                return false;
            }
        }

        public static bool TryRead(StructDeclarationSyntax declaration, out NativeHandleSourceProof proof)
        {
            proof = null;
            var markers = declaration.GetLeadingTrivia().Where(IsMarker).ToArray();
            if (markers.Length != 1)
                return false;
            string text = markers[0].ToString();
            bool opaque = text.StartsWith(OpaqueMarkerPrefix, StringComparison.Ordinal);
            string prefix = opaque ? OpaqueMarkerPrefix : MarkerPrefix;
            if (!text.StartsWith(prefix, StringComparison.Ordinal) || !text.EndsWith(MarkerSuffix, StringComparison.Ordinal))
                return false;
            try
            {
                var properties = JObject.Parse(text.Substring(prefix.Length,
                    text.Length - prefix.Length - MarkerSuffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                if (!properties.Properties().Select(property => property.Name)
                    .SequenceEqual(opaque ? OpaquePropertyNames : PropertyNames, StringComparer.Ordinal) ||
                    properties.Properties().Any(property => property.Name is not ("wrapperIntent" or "pointerDepth") &&
                        property.Value.Type != JTokenType.String) ||
                    (string)properties["kind"] != (opaque ? OpaqueStructPointerKind : DeclareHandleKind))
                    return false;
                string tag = null;
                if (opaque)
                {
                    tag = (string)properties["nativeTag"];
                    if (NormalizeNativeAlias(tag) != tag ||
                        properties["wrapperIntent"].Type != JTokenType.Boolean || !(bool)properties["wrapperIntent"] ||
                        properties["pointerDepth"].Type != JTokenType.Integer ||
                        properties["pointerDepth"].ToString(Formatting.None) != "1")
                        return false;
                }
                var provider = (string)properties["provider"] switch
                {
                    "retained" => NativeHandleSourceProvider.Retained,
                    "header" => NativeHandleSourceProvider.Header,
                    _ => (NativeHandleSourceProvider)(-1),
                };
                string alias = (string)properties["nativeAlias"];
                string generatedAlias = (string)properties["generatedAlias"];
                string storage = (string)properties["storage"];
                if (provider is not (NativeHandleSourceProvider.Retained or NativeHandleSourceProvider.Header) ||
                    NormalizeNativeAlias(alias) != alias || string.IsNullOrEmpty(generatedAlias) ||
                    !StorageMatches(declaration, provider, storage, opaque ? OpaqueStructPointerKind : DeclareHandleKind))
                    return false;
                proof = new NativeHandleSourceProof(provider, alias, generatedAlias, storage)
                {
                    Kind = opaque ? OpaqueStructPointerKind : DeclareHandleKind,
                    NativeTag = tag,
                    WrapperIntent = opaque,
                    PointerDepth = opaque ? 1 : 0,
                };
                return true;
            }
            catch (JsonException)
            {
                return false;
            }
            catch (ArgumentException)
            {
                return false;
            }
        }

        public static string GetSignature(StructDeclarationSyntax declaration) =>
            string.Join("\n", declaration.GetLeadingTrivia().Where(IsMarker).Select(trivia => trivia.ToString()));

        public static StructDeclarationSyntax Remove(StructDeclarationSyntax declaration) =>
            declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Where(trivia => !IsMarker(trivia)));

        private static StructDeclarationSyntax Attach(StructDeclarationSyntax declaration,
            NativeHandleSourceProvider provider, string nativeAlias, string storage, string kind = DeclareHandleKind,
            string nativeTag = null, bool explicitWrapperIntent = false)
        {
            if (declaration == null)
                throw new ArgumentNullException(nameof(declaration));
            if (declaration.Identifier.IsMissing || declaration.GetLeadingTrivia().Any(IsMarker) ||
                !StorageMatches(declaration, provider, storage, kind) ||
                kind == OpaqueStructPointerKind && !explicitWrapperIntent)
                throw new ArgumentException("Native handle provenance requires one matching Value storage field and no existing proof.",
                    nameof(declaration));
            var properties = new JObject(
                new JProperty("provider", provider == NativeHandleSourceProvider.Header ? "header" : "retained"),
                new JProperty("kind", kind),
                new JProperty("nativeAlias", NormalizeNativeAlias(nativeAlias)),
                new JProperty("generatedAlias", declaration.Identifier.ValueText),
                new JProperty("storage", storage));
            if (kind == OpaqueStructPointerKind)
            {
                properties.Add("nativeTag", NormalizeNativeAlias(nativeTag));
                properties.Add("wrapperIntent", true);
                properties.Add("pointerDepth", 1);
            }
            var comment = SyntaxFactory.Comment((kind == OpaqueStructPointerKind ? OpaqueMarkerPrefix : MarkerPrefix) +
                properties.ToString(Formatting.None) + MarkerSuffix);
            return declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Add(comment)
                .Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        private static bool StorageMatches(StructDeclarationSyntax declaration, NativeHandleSourceProvider provider,
            string storage, string kind)
        {
            if (string.IsNullOrEmpty(storage) || declaration.Members.Count != 1 ||
                declaration.Members[0] is not FieldDeclarationSyntax field ||
                field.Declaration.Variables.Count != 1 || field.Declaration.Variables[0].Identifier.ValueText != "Value")
                return false;
            var type = SyntaxFactory.ParseTypeName(storage);
            if (type.ContainsDiagnostics || !SyntaxFactory.AreEquivalent(type, field.Declaration.Type))
                return false;
            if (provider == NativeHandleSourceProvider.Header)
                return type is PointerTypeSyntax { ElementType: NameSyntax };
            return kind == OpaqueStructPointerKind ? type.ToString() == "IntPtr" :
                type is PointerTypeSyntax { ElementType: PredefinedTypeSyntax element } &&
                    element.Keyword.IsKind(SyntaxKind.VoidKeyword);
        }

        private static string NormalizeNativeAlias(string alias)
        {
            if (string.IsNullOrEmpty(alias))
                throw new ArgumentException("A native alias identity is required.", nameof(alias));
            string name = alias.StartsWith("::", StringComparison.Ordinal) ? alias.Substring(2) : alias;
            if (name.Split(new[] { "::" }, StringSplitOptions.None).Any(part => part.Length == 0 ||
                !(part[0] == '_' || char.IsLetter(part[0])) || part.Skip(1).Any(character =>
                    character != '_' && !char.IsLetterOrDigit(character))))
                throw new ArgumentException("Expected an exact qualified native alias identity.", nameof(alias));
            return "::" + name;
        }

        private static bool IsMarker(SyntaxTrivia trivia) =>
            trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) && trivia.ToString().StartsWith(MarkerFamily, StringComparison.Ordinal);
    }
}
