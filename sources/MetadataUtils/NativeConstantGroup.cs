using System;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    public sealed record NativeConstantBinding(
        string Kind, string NativeName, string Header, uint Line, uint Column, string HeaderHash,
        string NativeType, string StorageType, string Value);

    public sealed record NativeConstantGroupMember(
        string Name, string Expression, NativeConstantBinding[] Bindings);

    public sealed record NativeConstantGroup(
        string NativeName, string Name, string Namespace, string StorageType,
        string Header, uint Line, NativeConstantGroupMember[] Members)
    {
        public string Kind { get; init; } = "LogicalGroup";
    }

    public sealed record NativeConstantGroupSource(
        string SourceFile, string SourceHash, Architecture Architecture, NativeConstantGroup Group);

    public static class NativeConstantGroupProvenance
    {
        private const string Family = "/* Win32Metadata.NativeConstantGroup.";
        private const string Prefix = Family + "v1 ";
        private const string Suffix = " */";

        public static string HashFile(string path)
        {
            using var stream = File.OpenRead(path);
            return Convert.ToHexString(SHA256.HashData(stream));
        }

        public static EnumDeclarationSyntax Attach(EnumDeclarationSyntax declaration, NativeConstantGroupSource source)
        {
            Validate(declaration, source);
            if (declaration.GetLeadingTrivia().Any(IsMarker))
                throw new ArgumentException("A logical group already has native constant provenance.", nameof(declaration));
            string json = JsonConvert.SerializeObject(source).Replace("*/", "*\\u002F");
            return declaration.WithLeadingTrivia(declaration.GetLeadingTrivia()
                .Add(SyntaxFactory.Comment(Prefix + json + Suffix)).Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        public static NativeConstantGroupSource Read(EnumDeclarationSyntax declaration)
        {
            var markers = declaration.GetLeadingTrivia().Where(IsMarker).ToArray();
            if (markers.Length == 0)
                return null;
            if (markers.Length != 1)
                throw new InvalidDataException("Expected one compiler-bound native constant group proof.");
            string text = markers[0].ToString();
            if (!text.StartsWith(Prefix, StringComparison.Ordinal) || !text.EndsWith(Suffix, StringComparison.Ordinal))
                throw new InvalidDataException("Unsupported native constant group proof version.");
            try
            {
                var json = JObject.Parse(text.Substring(Prefix.Length, text.Length - Prefix.Length - Suffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                var source = json.ToObject<NativeConstantGroupSource>(JsonSerializer.Create(
                    new JsonSerializerSettings { MissingMemberHandling = MissingMemberHandling.Error }));
                Validate(declaration, source);
                return source;
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native constant group proof.", error);
            }
        }

        private static void Validate(EnumDeclarationSyntax declaration, NativeConstantGroupSource source)
        {
            var group = source?.Group;
            bool nativeEnum = group?.Kind == "NativeEnum";
            if (group == null || string.IsNullOrEmpty(source.SourceFile) || !IsHash(source.SourceHash) ||
                source.Architecture is not (Architecture.X86 or Architecture.X64 or Architecture.Arm64) ||
                string.IsNullOrEmpty(group.NativeName) || string.IsNullOrEmpty(group.Header) || group.Line == 0 ||
                group.Name != declaration.Identifier.ValueText || group.Members == null ||
                group.Members.Length != declaration.Members.Count ||
                group.Kind is not ("LogicalGroup" or "NativeEnum") ||
                (declaration.BaseList == null ? !nativeEnum || group.StorageType != "int" :
                    declaration.BaseList.Types.Count != 1 || declaration.BaseList.Types[0].Type.ToString() != group.StorageType))
                throw new InvalidDataException("Native constant group proof does not match its emitted declaration.");
            for (int i = 0; i < group.Members.Length; i++)
            {
                var member = group.Members[i];
                var emitted = declaration.Members[i];
                if (member == null || member.Name != emitted.Identifier.ValueText ||
                    (emitted.EqualsValue == null ? !nativeEnum || member.Expression != null :
                        !SyntaxFactory.AreEquivalent(SyntaxFactory.ParseExpression(member.Expression ?? ""), emitted.EqualsValue.Value)) ||
                    member.Bindings == null || member.Bindings.Length == 0 ||
                    member.Bindings.Any(binding => binding == null ||
                        binding.Kind != "Expression" && string.IsNullOrEmpty(binding.NativeName) ||
                        binding.Kind is not ("Macro" or "CXCursor_VarDecl" or "CXCursor_EnumConstantDecl" or "Expression") ||
                        string.IsNullOrEmpty(binding.Header) ||
                        binding.Line == 0 || binding.Column == 0 || !IsHash(binding.HeaderHash) ||
                        string.IsNullOrEmpty(binding.NativeType) || string.IsNullOrEmpty(binding.StorageType) ||
                        string.IsNullOrEmpty(binding.Value)))
                    throw new InvalidDataException($"Native constant group proof does not match member '{emitted.Identifier.ValueText}'.");
            }
        }

        private static bool IsMarker(SyntaxTrivia trivia) => trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) &&
            trivia.ToString().StartsWith(Family, StringComparison.Ordinal);

        private static bool IsHash(string value) => value?.Length == 64 && value.All(Uri.IsHexDigit);
    }
}
