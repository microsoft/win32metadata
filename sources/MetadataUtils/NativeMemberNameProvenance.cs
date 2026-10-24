using System;
using System.Linq;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    public static class NativeMemberNameProvenance
    {
        private const string MarkerFamily = "/* Win32Metadata.NativeMemberName.";
        private const string MarkerPrefix = MarkerFamily + "v1 ";
        private const string MarkerSuffix = " */";
        private static readonly string[] PropertyNames = { "kind", "source", "parent", "primaryName", "legacyName" };

        public static T Attach<T>(T declaration, string source, string parent, string primaryName, string legacyName)
            where T : MemberDeclarationSyntax
        {
            string kind = declaration switch
            {
                MethodDeclarationSyntax method when method.Identifier.ValueText == primaryName => "method",
                FieldDeclarationSyntax field when field.Declaration.Variables.Count == 1 &&
                    field.Declaration.Variables[0].Identifier.ValueText == primaryName => "field",
                _ => throw new ArgumentException("Native member-name proof requires one matching method or field.", nameof(declaration)),
            };
            if (declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Any(IsMarker) || string.IsNullOrEmpty(source) ||
                string.IsNullOrEmpty(parent) || !IsName(primaryName) || !IsName(legacyName) || primaryName == legacyName)
                throw new ArgumentException("Native member-name proof requires distinct valid names and exact source and parent identities.");
            var properties = new JObject(
                new JProperty("kind", kind),
                new JProperty("source", source),
                new JProperty("parent", parent),
                new JProperty("primaryName", primaryName),
                new JProperty("legacyName", legacyName));
            var comment = SyntaxFactory.Comment(MarkerPrefix + properties.ToString(Formatting.None) + MarkerSuffix);
            return declaration.WithTrailingTrivia(SyntaxFactory.TriviaList(SyntaxFactory.Space, comment)
                .AddRange(declaration.GetTrailingTrivia()).Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        // Apply after authored remaps and encoding inference, so a restored spelling supplies no encoding facts.
        public static CSharpSyntaxNode Project(CSharpSyntaxNode root) => (CSharpSyntaxNode)new Projector().Visit(root);

        public static string GetProjectedFieldName(FieldDeclarationSyntax declaration, string name)
        {
            var names = Projector.Read(declaration, "field");
            return names.HasValue && names.Value.Primary == name ? names.Value.Legacy : name;
        }

        private static bool IsName(string name) => !string.IsNullOrEmpty(name) &&
            (SyntaxFacts.IsValidIdentifier(name) || SyntaxFacts.IsValidIdentifier("@" + name));

        private static bool IsMarker(SyntaxTrivia trivia) => trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) &&
            trivia.ToString().StartsWith(MarkerFamily, StringComparison.Ordinal);

        private sealed class Projector : CSharpSyntaxRewriter
        {
            public override SyntaxNode VisitMethodDeclaration(MethodDeclarationSyntax node)
            {
                var names = Read(node, "method");
                node = (MethodDeclarationSyntax)base.VisitMethodDeclaration(node);
                if (names == null)
                    return node;
                if (node.AttributeLists.SelectMany(list => list.Attributes).Any(attribute =>
                    attribute.Name.ToString() is "DllImport" or "DllImportAttribute"))
                    throw new InvalidOperationException("Native member-name proof cannot rename a DLL export.");
                node = Remove(node);
                return node.WithIdentifier(Rename(node.Identifier, names.Value));
            }

            public override SyntaxNode VisitFieldDeclaration(FieldDeclarationSyntax node)
            {
                var names = Read(node, "field");
                node = (FieldDeclarationSyntax)base.VisitFieldDeclaration(node);
                if (names == null)
                    return node;
                if (node.Declaration.Variables.Count != 1)
                    throw new InvalidOperationException("Native member-name proof requires one field declarator.");
                var variable = node.Declaration.Variables[0];
                return Remove(node).WithDeclaration(node.Declaration.WithVariables(
                    SyntaxFactory.SingletonSeparatedList(variable.WithIdentifier(Rename(variable.Identifier, names.Value)))));
            }

            private static SyntaxToken Rename(SyntaxToken identifier, (string Primary, string Legacy) names)
            {
                if (identifier.ValueText != names.Primary)
                    return identifier;
                string text = SyntaxFacts.GetKeywordKind(names.Legacy) == SyntaxKind.None ? names.Legacy : "@" + names.Legacy;
                return SyntaxFactory.Identifier(identifier.LeadingTrivia, text, identifier.TrailingTrivia);
            }

            private static T Remove<T>(T declaration) where T : MemberDeclarationSyntax =>
                declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Where(trivia => !IsMarker(trivia)))
                    .WithTrailingTrivia(declaration.GetTrailingTrivia().Where(trivia => !IsMarker(trivia)));

            internal static (string Primary, string Legacy)? Read(MemberDeclarationSyntax declaration, string kind)
            {
                var markers = declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Where(IsMarker).ToArray();
                if (markers.Length == 0)
                    return null;
                try
                {
                    if (markers.Length != 1)
                        throw new InvalidOperationException("Expected one native member-name proof.");
                    string text = markers[0].ToString();
                    if (!text.StartsWith(MarkerPrefix, StringComparison.Ordinal) || !text.EndsWith(MarkerSuffix, StringComparison.Ordinal))
                        throw new InvalidOperationException("Unsupported native member-name proof version.");
                    var properties = JObject.Parse(text.Substring(MarkerPrefix.Length,
                        text.Length - MarkerPrefix.Length - MarkerSuffix.Length),
                        new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                    if (!properties.Properties().Select(property => property.Name).SequenceEqual(PropertyNames, StringComparer.Ordinal) ||
                        properties.Properties().Any(property => property.Value.Type != JTokenType.String))
                        throw new InvalidOperationException("Malformed native member-name proof.");
                    string primary = (string)properties["primaryName"];
                    string legacy = (string)properties["legacyName"];
                    if ((string)properties["kind"] != kind || string.IsNullOrEmpty((string)properties["source"]) ||
                        string.IsNullOrEmpty((string)properties["parent"]) || !IsName(primary) || !IsName(legacy) || primary == legacy)
                        throw new InvalidOperationException("Malformed native member-name proof.");
                    return (primary, legacy);
                }
                catch (JsonException error)
                {
                    throw new InvalidOperationException("Malformed native member-name proof.", error);
                }
            }
        }
    }
}
