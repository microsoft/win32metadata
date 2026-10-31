using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    public sealed record NativeRecordSource(
        string Identity, string NativeName, string Header, string HeaderHash, uint Line, uint Column,
        string Name, string Namespace, bool TraversedHeader, long Size, long Alignment)
    {
        [JsonProperty(Order = 1, NullValueHandling = NullValueHandling.Ignore)]
        public Architecture? SourceArchitecture { get; init; }
    }

    public static class NativeRecordSourceProvenance
    {
        private const string Family = "/* Win32Metadata.NativeRecordSource.";
        private const string Suffix = " */";
        private static readonly ConditionalWeakTable<StructDeclarationSyntax, Dictionary<string, NativeRecordSource>> sources = new();
        private static readonly string[] Properties =
        {
            "Identity", "NativeName", "Header", "HeaderHash", "Line", "Column", "Name", "Namespace",
            "TraversedHeader", "Size", "Alignment",
        };

        public static StructDeclarationSyntax Attach(StructDeclarationSyntax declaration, NativeRecordSource source)
            => Attach(declaration, source, Family);

        internal static StructDeclarationSyntax Attach(StructDeclarationSyntax declaration, NativeRecordSource source,
            string family)
        {
            Validate(declaration, source);
            if (Markers(declaration, family).Any())
                throw new InvalidDataException("A native provider already has source provenance.");
            string json = JsonConvert.SerializeObject(source).Replace("*/", "*\\u002F");
            string version = source.SourceArchitecture.HasValue ? "v2 " : "v1 ";
            return declaration.WithTrailingTrivia(declaration.GetTrailingTrivia()
                .Add(SyntaxFactory.Space).Add(SyntaxFactory.Comment(family + version + json + Suffix))
                .Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        public static NativeRecordSource Read(StructDeclarationSyntax declaration)
            => Read(declaration, Family);

        internal static NativeRecordSource Read(StructDeclarationSyntax declaration, string family)
        {
            var cache = sources.GetValue(declaration, static _ => new(StringComparer.Ordinal));
            lock (cache)
            {
                if (!cache.TryGetValue(family, out var source))
                {
                    source = ReadCore(declaration, family);
                    cache.Add(family, source);
                }
                return source;
            }
        }

        private static NativeRecordSource ReadCore(StructDeclarationSyntax declaration, string family)
        {
            var markers = Markers(declaration, family).ToArray();
            if (markers.Length == 0)
                return null;
            if (markers.Length != 1)
                throw new InvalidDataException("Expected one native provider source proof.");
            string text = markers[0].ToString();
            bool hasArchitecture = text.StartsWith(family + "v2 ", StringComparison.Ordinal);
            string prefix = family + (hasArchitecture ? "v2 " : "v1 ");
            if (!text.StartsWith(prefix, StringComparison.Ordinal) || !text.EndsWith(Suffix, StringComparison.Ordinal))
                throw new InvalidDataException("Unsupported native provider source proof version.");
            try
            {
                var json = JObject.Parse(text.Substring(prefix.Length, text.Length - prefix.Length - Suffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                var properties = hasArchitecture ? Properties.Append("SourceArchitecture") : Properties;
                if (!json.Properties().Select(property => property.Name).SequenceEqual(properties, StringComparer.Ordinal) ||
                    Properties.Take(4).Concat(new[] { "Name", "Namespace" }).Any(name => json[name].Type != JTokenType.String) ||
                    new[] { "Line", "Column", "Size", "Alignment" }.Any(name => json[name].Type != JTokenType.Integer) ||
                    json["TraversedHeader"].Type != JTokenType.Boolean ||
                    hasArchitecture && json["SourceArchitecture"].Type != JTokenType.Integer)
                    throw new InvalidDataException("Malformed native provider source proof.");
                var source = json.ToObject<NativeRecordSource>();
                Validate(declaration, source);
                return source;
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native provider source proof.", error);
            }
        }

        public static string GetIdentityKey(NativeRecordSource source)
        {
            if (source == null)
                return null;
            string file = Path.GetFileName(source.Header);
            string prefix = "c:" + file + "@";
            // File-local USRs contain only a basename; distinct physical declarations need their full header path.
            return source.Identity.StartsWith("c:", StringComparison.Ordinal) &&
                source.Identity.StartsWith(prefix, StringComparison.OrdinalIgnoreCase)
                ? "c:" + source.Header.ToUpperInvariant() + source.Identity.Substring(2 + file.Length)
                : source.Identity;
        }

        public static bool SameDeclaration(NativeRecordSource left, NativeRecordSource right) =>
            left != null && right != null && GetIdentityKey(left) == GetIdentityKey(right) &&
            left.NativeName == right.NativeName && left.Name == right.Name &&
            string.Equals(left.Header, right.Header, StringComparison.OrdinalIgnoreCase) &&
            left.HeaderHash == right.HeaderHash && left.Line == right.Line && left.Column == right.Column;

        private static System.Collections.Generic.IEnumerable<SyntaxTrivia> Markers(StructDeclarationSyntax declaration,
            string family) =>
            declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Where(trivia =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) && trivia.ToString().StartsWith(family, StringComparison.Ordinal));

        private static void Validate(StructDeclarationSyntax declaration, NativeRecordSource source)
        {
            if (source == null || string.IsNullOrEmpty(source.Identity) || string.IsNullOrEmpty(source.NativeName) ||
                string.IsNullOrEmpty(source.Header) || !Path.IsPathFullyQualified(source.Header) ||
                source.HeaderHash == null || source.HeaderHash.Length != 64 ||
                source.HeaderHash.Any(character => !Uri.IsHexDigit(character)) ||
                source.SourceArchitecture.HasValue &&
                    source.SourceArchitecture.Value is not (Architecture.X86 or Architecture.X64 or Architecture.Arm64) ||
                source.Line == 0 || source.Column == 0 || string.IsNullOrEmpty(source.Name) ||
                string.IsNullOrEmpty(source.Namespace) || source.Size < 0 || source.Alignment <= 0 ||
                (source.Alignment & (source.Alignment - 1)) != 0 ||
                declaration.Identifier.ValueText != source.Name &&
                    !IsVariant(declaration.Identifier.ValueText, source.Name))
                throw new InvalidDataException("Native provider source proof does not match its emitted declaration.");
        }

        private static bool IsVariant(string name, string original) =>
            name.StartsWith(original + "____", StringComparison.Ordinal) &&
            int.TryParse(name.Substring(original.Length + 4), System.Globalization.NumberStyles.None,
                System.Globalization.CultureInfo.InvariantCulture, out int ordinal) && ordinal > 0;
    }

    public static class NativeTypedefSourceProvenance
    {
        private const string Family = "/* Win32Metadata.NativeTypedefSource.";

        public static StructDeclarationSyntax Attach(StructDeclarationSyntax declaration, NativeRecordSource source) =>
            NativeRecordSourceProvenance.Attach(declaration, source, Family);

        public static NativeRecordSource Read(StructDeclarationSyntax declaration) =>
            NativeRecordSourceProvenance.Read(declaration, Family);
    }

    public static class NativeTypedefProjectionProvenance
    {
        private const string Prefix = "/* Win32Metadata.NativeTypedefProjection.v1 ";
        private const string Family = "/* Win32Metadata.NativeTypedefProjection.";
        private const string Suffix = " */";
        private const string BindingFamily = "/* Win32Metadata.NativeTypedefBinding.";

        public static bool? IsInferred(StructDeclarationSyntax declaration)
        {
            var markers = declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia())
                .Where(trivia => trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) &&
                    trivia.ToString().StartsWith(Family, StringComparison.Ordinal)).ToArray();
            if (markers.Length == 0)
                return null;
            if (markers.Length != 1 || NativeTypedefSourceProvenance.Read(declaration) == null)
                throw new InvalidDataException("A native typedef projection requires one source-bound policy.");
            return markers[0].ToString() switch
            {
                Prefix + "Inferred" + Suffix => true,
                Prefix + "Nominal" + Suffix => false,
                _ => throw new InvalidDataException("Unsupported native typedef projection policy."),
            };
        }

        public static StructDeclarationSyntax WithPolicy(StructDeclarationSyntax declaration, bool inferred)
        {
            _ = IsInferred(declaration);
            if (NativeTypedefSourceProvenance.Read(declaration) == null)
                throw new InvalidDataException("A native typedef projection requires native source provenance.");
            SyntaxTrivia Keep(SyntaxTrivia trivia) =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) &&
                    trivia.ToString().StartsWith(Family, StringComparison.Ordinal)
                ? SyntaxFactory.Whitespace("") : trivia;
            return declaration.WithLeadingTrivia(
                    new[] { SyntaxFactory.ElasticCarriageReturnLineFeed,
                        SyntaxFactory.Comment(Prefix + (inferred ? "Inferred" : "Nominal") + Suffix),
                        SyntaxFactory.ElasticCarriageReturnLineFeed }
                        .Concat(declaration.GetLeadingTrivia().Select(Keep)))
                .WithTrailingTrivia(declaration.GetTrailingTrivia().Select(Keep));
        }

        public static bool HasConfiguredNominalBinding(StructDeclarationSyntax declaration)
        {
            var binding = NativeRecordSourceProvenance.Read(declaration, BindingFamily);
            if (binding == null)
                return false;
            if (IsInferred(declaration) != false || binding != NativeTypedefSourceProvenance.Read(declaration))
                throw new InvalidDataException("A configured native typedef binding requires one source-bound nominal projection.");
            return true;
        }

        public static StructDeclarationSyntax WithConfiguredNominalBinding(StructDeclarationSyntax declaration)
        {
            if (IsInferred(declaration) != false || HasConfiguredNominalBinding(declaration))
                throw new InvalidDataException("A configured native typedef binding requires a new source-bound nominal projection.");
            var attached = NativeRecordSourceProvenance.Attach(declaration,
                NativeTypedefSourceProvenance.Read(declaration), BindingFamily);
            var binding = attached.GetTrailingTrivia().Single(trivia =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) &&
                trivia.ToString().StartsWith(BindingFamily, StringComparison.Ordinal));
            return declaration.WithLeadingTrivia(new[]
            {
                SyntaxFactory.ElasticCarriageReturnLineFeed, binding, SyntaxFactory.ElasticCarriageReturnLineFeed,
            }.Concat(declaration.GetLeadingTrivia()));
        }
    }
}
