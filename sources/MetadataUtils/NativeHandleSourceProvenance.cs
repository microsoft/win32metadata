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
        public string Kind => NativeHandleSourceProvenance.DeclareHandleKind;
    }

    public static class NativeHandleSourceProvenance
    {
        public const string DeclareHandleKind = "DECLARE_HANDLE";
        private const string MarkerFamily = "/* Win32Metadata.NativeHandleSource.";
        private const string MarkerPrefix = MarkerFamily + "v1 ";
        private const string MarkerSuffix = " */";
        private static readonly string[] PropertyNames = { "provider", "kind", "nativeAlias", "generatedAlias", "storage" };

        // The caller must prove the originating native DECLARE_HANDLE, not infer it from a tag's name or layout.
        public static StructDeclarationSyntax AttachHeaderDeclareHandle(
            StructDeclarationSyntax declaration, string nativeAlias, string generatedPointerStorage) =>
            Attach(declaration, NativeHandleSourceProvider.Header, nativeAlias, generatedPointerStorage);

        public static StructDeclarationSyntax AttachRetainedDeclareHandle(
            StructDeclarationSyntax declaration, string nativeAlias) =>
            Attach(declaration, NativeHandleSourceProvider.Retained, nativeAlias, "void*");

        public static bool TryRead(StructDeclarationSyntax declaration, out NativeHandleSourceProof proof)
        {
            proof = null;
            var markers = declaration.GetLeadingTrivia().Where(IsMarker).ToArray();
            if (markers.Length != 1)
                return false;
            string text = markers[0].ToString();
            if (!text.StartsWith(MarkerPrefix, StringComparison.Ordinal) || !text.EndsWith(MarkerSuffix, StringComparison.Ordinal))
                return false;
            try
            {
                var properties = JObject.Parse(text.Substring(MarkerPrefix.Length,
                    text.Length - MarkerPrefix.Length - MarkerSuffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                if (!properties.Properties().Select(property => property.Name).SequenceEqual(PropertyNames, StringComparer.Ordinal) ||
                    properties.Properties().Any(property => property.Value.Type != JTokenType.String) ||
                    (string)properties["kind"] != DeclareHandleKind)
                    return false;
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
                    !StorageMatches(declaration, provider, storage))
                    return false;
                proof = new NativeHandleSourceProof(provider, alias, generatedAlias, storage);
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
            NativeHandleSourceProvider provider, string nativeAlias, string storage)
        {
            if (declaration == null)
                throw new ArgumentNullException(nameof(declaration));
            if (declaration.Identifier.IsMissing || declaration.GetLeadingTrivia().Any(IsMarker) ||
                !StorageMatches(declaration, provider, storage))
                throw new ArgumentException("Native handle provenance requires one matching Value storage field and no existing proof.",
                    nameof(declaration));
            var properties = new JObject(
                new JProperty("provider", provider == NativeHandleSourceProvider.Header ? "header" : "retained"),
                new JProperty("kind", DeclareHandleKind),
                new JProperty("nativeAlias", NormalizeNativeAlias(nativeAlias)),
                new JProperty("generatedAlias", declaration.Identifier.ValueText),
                new JProperty("storage", storage));
            var comment = SyntaxFactory.Comment(MarkerPrefix + properties.ToString(Formatting.None) + MarkerSuffix);
            return declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Add(comment)
                .Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        private static bool StorageMatches(StructDeclarationSyntax declaration, NativeHandleSourceProvider provider, string storage)
        {
            if (string.IsNullOrEmpty(storage) || declaration.Members.Count != 1 ||
                declaration.Members[0] is not FieldDeclarationSyntax field ||
                field.Declaration.Variables.Count != 1 || field.Declaration.Variables[0].Identifier.ValueText != "Value")
                return false;
            var type = SyntaxFactory.ParseTypeName(storage);
            if (type.ContainsDiagnostics || !SyntaxFactory.AreEquivalent(type, field.Declaration.Type))
                return false;
            return provider == NativeHandleSourceProvider.Retained
                ? type is PointerTypeSyntax { ElementType: PredefinedTypeSyntax element } &&
                    element.Keyword.IsKind(SyntaxKind.VoidKeyword)
                : type is PointerTypeSyntax { ElementType: NameSyntax };
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
