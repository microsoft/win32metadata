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
    public enum NativeDeclarationKind
    {
        IncompleteRecord,
        LogicalEnum,
    }

    public sealed record NativeDeclarationSource(
        string Identity, string NativeName, string Header, string HeaderHash, uint Line, uint Column,
        string Name, string Namespace, bool TraversedHeader, NativeDeclarationKind Kind)
    {
        [JsonProperty(Order = 1, NullValueHandling = NullValueHandling.Ignore)]
        public Architecture? SourceArchitecture { get; init; }
    }

    public static class NativeDeclarationSourceProvenance
    {
        private const string Family = "/* Win32Metadata.NativeDeclarationSource.";
        private const string Suffix = " */";
        private static readonly ConditionalWeakTable<BaseTypeDeclarationSyntax, Dictionary<string, NativeDeclarationSource>> sources = new();
        private static readonly string[] Properties =
        {
            "Identity", "NativeName", "Header", "HeaderHash", "Line", "Column", "Name", "Namespace",
            "TraversedHeader", "Kind",
        };

        public static TDeclaration Attach<TDeclaration>(TDeclaration declaration, NativeDeclarationSource source)
            where TDeclaration : BaseTypeDeclarationSyntax
        {
            Validate(declaration, source);
            if (Markers(declaration).Any())
                throw new InvalidDataException("A native declaration already has source provenance.");
            string json = JsonConvert.SerializeObject(source).Replace("*/", "*\\u002F");
            string version = source.SourceArchitecture.HasValue ? "v2 " : "v1 ";
            return declaration.WithTrailingTrivia(declaration.GetTrailingTrivia()
                .Add(SyntaxFactory.Space).Add(SyntaxFactory.Comment(Family + version + json + Suffix))
                .Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        public static NativeDeclarationSource Read(BaseTypeDeclarationSyntax declaration)
        {
            var cache = sources.GetValue(declaration, static _ => new(StringComparer.Ordinal));
            lock (cache)
            {
                if (!cache.TryGetValue(Family, out var source))
                {
                    source = ReadCore(declaration);
                    cache.Add(Family, source);
                }
                return source;
            }
        }

        private static NativeDeclarationSource ReadCore(BaseTypeDeclarationSyntax declaration)
        {
            var markers = Markers(declaration).ToArray();
            if (markers.Length == 0)
                return null;
            if (markers.Length != 1)
                throw new InvalidDataException("Expected one native declaration source proof.");
            string text = markers[0].ToString();
            bool hasArchitecture = text.StartsWith(Family + "v2 ", StringComparison.Ordinal);
            string prefix = Family + (hasArchitecture ? "v2 " : "v1 ");
            if (!text.StartsWith(prefix, StringComparison.Ordinal) || !text.EndsWith(Suffix, StringComparison.Ordinal))
                throw new InvalidDataException("Unsupported native declaration source proof version.");
            try
            {
                var json = JObject.Parse(text.Substring(prefix.Length, text.Length - prefix.Length - Suffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                var properties = hasArchitecture ? Properties.Append("SourceArchitecture") : Properties;
                if (!json.Properties().Select(property => property.Name).SequenceEqual(properties, StringComparer.Ordinal) ||
                    Properties.Take(4).Concat(new[] { "Name", "Namespace" }).Any(name => json[name].Type != JTokenType.String) ||
                    new[] { "Line", "Column", "Kind" }.Any(name => json[name].Type != JTokenType.Integer) ||
                    json["TraversedHeader"].Type != JTokenType.Boolean ||
                    hasArchitecture && json["SourceArchitecture"].Type != JTokenType.Integer)
                    throw new InvalidDataException("Malformed native declaration source proof.");
                var source = json.ToObject<NativeDeclarationSource>();
                Validate(declaration, source);
                return source;
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native declaration source proof.", error);
            }
        }

        public static string GetIdentityKey(NativeDeclarationSource source) =>
            source == null ? null : NativeRecordSourceProvenance.GetIdentityKey(source.Identity, source.Header);

        public static bool SameDeclaration(NativeDeclarationSource left, NativeDeclarationSource right) =>
            left != null && right != null && GetIdentityKey(left) == GetIdentityKey(right) &&
            left.Kind == right.Kind && left.NativeName == right.NativeName && left.Name == right.Name &&
            string.Equals(left.Header, right.Header, StringComparison.OrdinalIgnoreCase) &&
            left.HeaderHash == right.HeaderHash && left.Line == right.Line && left.Column == right.Column;

        private static IEnumerable<SyntaxTrivia> Markers(BaseTypeDeclarationSyntax declaration) =>
            declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Where(trivia =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) && trivia.ToString().StartsWith(Family, StringComparison.Ordinal));

        private static void Validate(BaseTypeDeclarationSyntax declaration, NativeDeclarationSource source)
        {
            if (source == null || !NativeRecordSourceProvenance.IsValidIdentity(source.Identity, source.NativeName,
                    source.Header, source.HeaderHash, source.Line, source.Column, source.Name, source.Namespace,
                    source.SourceArchitecture) ||
                !NativeRecordSourceProvenance.MatchesName(declaration.Identifier.ValueText, source.Name) ||
                (declaration switch
                {
                    StructDeclarationSyntax record => source.Kind != NativeDeclarationKind.IncompleteRecord ||
                        record.Members.Count != 0 || record.BaseList != null || record.TypeParameterList != null,
                    EnumDeclarationSyntax => source.Kind != NativeDeclarationKind.LogicalEnum,
                    _ => true,
                }))
                throw new InvalidDataException("Native declaration source proof does not match its emitted declaration.");
        }
    }
}
