using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Security.Cryptography;
using System.Text;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace MetadataUtils
{
    public sealed record NativeLogicalGroupInput(
        NativeDeclarationSource Source, NativeConstantGroupSource Constants, Architecture ProjectedArchitectures,
        bool CommonProjection = false);

    public sealed record NativeLogicalOccurrenceReference(int Input, int Occurrence);

    public sealed record NativeLogicalAlternative(
        string Member, NativeConstantBinding[] Definitions, NativeLogicalOccurrenceReference[] Occurrences);

    public sealed record NativeLogicalGroupComposition(
        string Name, string Namespace, string StorageType, NativeLogicalGroupInput[] Inputs,
        NativeLogicalAlternative[] Alternatives);

    public static class NativeLogicalGroupCompositionProvenance
    {
        private const string Family = "/* Win32Metadata.NativeLogicalGroupComposition.";
        private const string Prefix = Family + "v1 ";
        private const string Suffix = " */";
        private static readonly ConditionalWeakTable<EnumDeclarationSyntax, ParsedComposition> sources = new();
        private sealed record ParsedComposition(NativeLogicalGroupComposition Source, string Signature);

        public static NativeLogicalGroupComposition Create(
            string name, string ns, string storage, NativeLogicalGroupInput[] inputs)
        {
            if (inputs == null || inputs.Any(input => !CoherentInput(input)))
                throw new InvalidDataException("A literal composition requires source-bound logical contributions.");
            foreach (var input in inputs)
                NativeConstantGroupProvenance.ValidateSource(input.Constants);
            var alternatives = DifferingMembers(inputs).Select(member =>
                TryCreateAlternative(inputs, member, out var alternative) ? alternative :
                    throw new InvalidDataException($"Conflicting native constant bindings for '{member}'.")).ToArray();
            var source = new NativeLogicalGroupComposition(name, ns, storage, inputs, alternatives);
            Validate(source);
            return source;
        }

        private static bool TryCreateAlternative(
            NativeLogicalGroupInput[] inputs, string memberName, out NativeLogicalAlternative alternative)
        {
            alternative = null;
            if (inputs == null || inputs.Length < 2 || inputs.Any(input => !CoherentInput(input)) ||
                inputs.Any(input => !NativeDeclarationSourceProvenance.SameDeclaration(inputs[0].Source, input.Source)))
                return false;
            var members = inputs.Select((input, index) => (Input: input, Index: index,
                    Member: input.Constants.Group.Members.SingleOrDefault(member => member.Name == memberName)))
                .Where(item => item.Member != null).ToArray();
            if (members.Length < 2 || members.Any(item => item.Member.Bindings.Length != 1 ||
                item.Input.Constants.Group.DefinitionEvidence == null || item.Member.Occurrences == null ||
                item.Member.Occurrences.Length == 0 || item.Member.Occurrences.Any(occurrence => occurrence.Literal == null)))
                return false;
            var first = members[0].Member.Bindings[0];
            string literal = members[0].Member.Occurrences[0].Literal.Literal;
            if (members.Any(item => item.Member.Bindings[0] is var binding &&
                (binding.Kind != "Macro" || binding.NativeName != first.NativeName || binding.NativeType != first.NativeType ||
                    binding.StorageType != first.StorageType || binding.Value != first.Value ||
                    item.Member.Occurrences.Any(occurrence => occurrence.Literal.Literal != literal))))
                return false;
            var definitions = members.Select(item => item.Member.Bindings[0]).Distinct().ToArray();
            if (definitions.Length < 2 || definitions.Select(DefinitionIdentity).Distinct(StringComparer.Ordinal).Count() != definitions.Length)
                return false;
            alternative = new NativeLogicalAlternative(memberName, definitions, members.SelectMany(item =>
                item.Member.Occurrences.Select((_, occurrence) => new NativeLogicalOccurrenceReference(item.Index, occurrence))).ToArray());
            return true;
        }

        public static bool RequiresComposition(NativeLogicalGroupInput[] inputs) =>
            inputs.All(input => input?.Constants?.Group?.Members != null) && DifferingMembers(inputs).Any();

        public static EnumDeclarationSyntax Attach(EnumDeclarationSyntax declaration, NativeLogicalGroupComposition source,
            Architecture projectedTarget = Architecture.None)
        {
            Validate(source);
            ValidateProjection(declaration, source, projectedTarget);
            if (Markers(declaration).Any() || NativeDeclarationSourceProvenance.Read(declaration) != null ||
                NativeConstantGroupProvenance.Read(declaration) != null)
                throw new InvalidDataException("A composed logical group cannot substitute a contributor's source proof.");
            string json = JsonConvert.SerializeObject(source).Replace("*/", "*\\u002F");
            return declaration.WithLeadingTrivia(declaration.GetLeadingTrivia().Add(SyntaxFactory.Comment(Prefix + json + Suffix))
                .Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        public static NativeLogicalGroupComposition Read(EnumDeclarationSyntax declaration) =>
            Get(declaration)?.Source;

        public static string GetSignature(EnumDeclarationSyntax declaration, Architecture projectedTarget = Architecture.None)
        {
            var composition = Get(declaration);
            if (composition != null && projectedTarget is Architecture.X86 or Architecture.X64 or Architecture.Arm64)
                ValidateProjection(declaration, composition.Source, projectedTarget);
            return composition?.Signature ?? "";
        }

        private static ParsedComposition Get(EnumDeclarationSyntax declaration) =>
            Markers(declaration).Any() ? sources.GetValue(declaration, ReadCore) : null;

        private static ParsedComposition ReadCore(EnumDeclarationSyntax declaration)
        {
            var markers = Markers(declaration).ToArray();
            if (markers.Length != 1)
                throw new InvalidDataException("Expected one native logical composition proof.");
            string text = markers[0].ToString();
            if (!text.StartsWith(Prefix, StringComparison.Ordinal) || !text.EndsWith(Suffix, StringComparison.Ordinal))
                throw new InvalidDataException("Unsupported native logical composition proof version.");
            try
            {
                var json = JObject.Parse(text.Substring(Prefix.Length, text.Length - Prefix.Length - Suffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                NativeConstantGroupProvenance.RequireProperties(json, ("Name", JTokenType.String), ("Namespace", JTokenType.String),
                    ("StorageType", JTokenType.String), ("Inputs", JTokenType.Array), ("Alternatives", JTokenType.Array));
                foreach (var inputValue in (JArray)json["Inputs"])
                {
                    var input = NativeConstantGroupProvenance.RequireProperties(inputValue,
                        ("Source", JTokenType.Object), ("Constants", JTokenType.Object),
                        ("ProjectedArchitectures", JTokenType.Integer), ("CommonProjection", JTokenType.Boolean));
                    NativeConstantGroupProvenance.ValidateCarrierJson(input["Source"]);
                    NativeConstantGroupProvenance.ValidateSourceJson(input["Constants"]);
                }
                foreach (var alternativeValue in (JArray)json["Alternatives"])
                {
                    var alternative = NativeConstantGroupProvenance.RequireProperties(alternativeValue,
                        ("Member", JTokenType.String), ("Definitions", JTokenType.Array), ("Occurrences", JTokenType.Array));
                    foreach (var binding in (JArray)alternative["Definitions"])
                        NativeConstantGroupProvenance.ValidateBindingJson(binding);
                    foreach (var reference in (JArray)alternative["Occurrences"])
                        NativeConstantGroupProvenance.RequireProperties(reference,
                            ("Input", JTokenType.Integer), ("Occurrence", JTokenType.Integer));
                }
                var source = json.ToObject<NativeLogicalGroupComposition>(NativeConstantGroupProvenance.StrictSerializer());
                Validate(source);
                ValidateProjection(declaration, source);
                if (NativeDeclarationSourceProvenance.Read(declaration) != null ||
                    NativeConstantGroupProvenance.Read(declaration) != null)
                    throw new InvalidDataException("A logical composition cannot claim one contributor's native declaration.");
                string hash = Convert.ToHexString(SHA256.HashData(Encoding.UTF8.GetBytes(JsonConvert.SerializeObject(source))));
                return new ParsedComposition(source, "NativeLogicalComposition|" + hash + ":");
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native logical composition proof.", error);
            }
        }

        private static void Validate(NativeLogicalGroupComposition source)
        {
            if (source == null || string.IsNullOrEmpty(source.Name) || source.Namespace == null ||
                string.IsNullOrEmpty(source.StorageType) || source.Inputs == null || source.Inputs.Length < 2 ||
                source.Inputs.Any(input => !CoherentInput(input)) || source.Alternatives == null ||
                source.Alternatives.Length == 0)
                throw new InvalidDataException("Invalid native logical composition source.");
            foreach (var input in source.Inputs)
            {
                NativeConstantGroupProvenance.ValidateSource(input.Constants);
                if (input.Constants.Group.Name != source.Name || input.Constants.Group.StorageType != source.StorageType ||
                    !NativeDeclarationSourceProvenance.SameDeclaration(source.Inputs[0].Source, input.Source))
                    throw new InvalidDataException("A logical composition contains a foreign native carrier.");
            }
            var identities = source.Inputs.Select(input => (
                input.Constants.SourceFile, input.Constants.SourceHash, input.Constants.Architecture,
                input.Constants.Group.Namespace, input.Constants.Group.NativeName, input.Constants.Group.Header,
                input.Constants.Group.Line)).ToArray();
            if (identities.Distinct().Count() != identities.Length)
                throw new InvalidDataException("A logical composition repeats an original contribution.");
            var expected = new List<NativeLogicalAlternative>();
            foreach (string member in DifferingMembers(source.Inputs))
            {
                if (!TryCreateAlternative(source.Inputs, member, out var alternative))
                    throw new InvalidDataException($"Unproved native literal definition alternatives for '{member}'.");
                expected.Add(alternative);
            }
            if (JsonConvert.SerializeObject(expected) != JsonConvert.SerializeObject(source.Alternatives))
                throw new InvalidDataException("Native logical alternatives do not retain their complete original observations.");
        }

        private static bool CoherentInput(NativeLogicalGroupInput input)
        {
            var source = input?.Source;
            var constants = input?.Constants;
            var group = constants?.Group;
            return source != null && group != null && group.Kind == "LogicalGroup" &&
                source.Kind == NativeDeclarationKind.LogicalEnum &&
                NativeRecordSourceProvenance.IsValidIdentity(source.Identity, source.NativeName, source.Header,
                    source.HeaderHash, source.Line, source.Column, source.Name, source.Namespace, source.SourceArchitecture) &&
                source.SourceArchitecture == constants.Architecture && source.Name == group.Name &&
                source.Namespace == group.Namespace &&
                NativeConstantGroupProvenance.NativeName(source.NativeName) == NativeConstantGroupProvenance.NativeName(group.NativeName) &&
                input.ProjectedArchitectures != Architecture.None &&
                (input.ProjectedArchitectures & ~Architecture.All) == Architecture.None &&
                (input.CommonProjection ? source.SourceArchitecture == Architecture.X86 &&
                    input.ProjectedArchitectures == Architecture.All : input.ProjectedArchitectures == source.SourceArchitecture) &&
                group.Members != null && group.Members.All(member => member != null && member.Bindings != null) &&
                (group.DefinitionEvidence == null || group.DefinitionEvidence.Carrier == source);
        }

        private static IEnumerable<string> DifferingMembers(NativeLogicalGroupInput[] inputs) =>
            inputs.SelectMany(input => input.Constants.Group.Members.Select(member => (Input: input, Member: member)))
                .GroupBy(item => item.Member.Name, StringComparer.Ordinal)
                .Where(group => group.Any(left => group.Any(right =>
                    (left.Input.ProjectedArchitectures & right.Input.ProjectedArchitectures) != Architecture.None &&
                    !left.Member.Bindings.SequenceEqual(right.Member.Bindings))))
                .Select(group => group.Key).OrderBy(name => name, StringComparer.Ordinal);

        private static void ValidateProjection(EnumDeclarationSyntax declaration, NativeLogicalGroupComposition source,
            Architecture projectedTarget = Architecture.None)
        {
            if (!NativeRecordSourceProvenance.MatchesName(declaration.Identifier.ValueText, source.Name) ||
                declaration.BaseList?.Types.Count != 1 || declaration.BaseList.Types[0].Type.ToString() != source.StorageType ||
                declaration.Members.Any(member => member.EqualsValue == null) ||
                declaration.Members.Select(member => member.Identifier.ValueText).Distinct(StringComparer.Ordinal).Count() != declaration.Members.Count)
                throw new InvalidDataException("A native logical composition does not match its projected declaration.");
            foreach (var target in projectedTarget is Architecture.X86 or Architecture.X64 or Architecture.Arm64
                ? new[] { projectedTarget } : new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
            {
                var members = source.Inputs.Where(input => input.ProjectedArchitectures.HasFlag(target))
                    .SelectMany(input => input.Constants.Group.Members).GroupBy(member => member.Name, StringComparer.Ordinal)
                    .ToDictionary(group => group.Key, group => group.ToArray(), StringComparer.Ordinal);
                if (members.Count == declaration.Members.Count && declaration.Members.All(member =>
                    members.TryGetValue(member.Identifier.ValueText, out var originals) &&
                    originals.All(original => SyntaxFactory.AreEquivalent(
                        SyntaxFactory.ParseExpression(original.Expression ?? ""), member.EqualsValue.Value))))
                    return;
            }
            throw new InvalidDataException("A native logical composition lost or changed its projected member inventory.");
        }

        private static string DefinitionIdentity(NativeConstantBinding binding) => string.Join("|",
            binding.Kind, binding.NativeName, binding.Header.ToUpperInvariant(), binding.HeaderHash, binding.Line, binding.Column);

        private static IEnumerable<SyntaxTrivia> Markers(EnumDeclarationSyntax declaration) =>
            declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Where(trivia =>
                trivia.IsKind(SyntaxKind.MultiLineCommentTrivia) && trivia.ToString().StartsWith(Family, StringComparison.Ordinal));
    }
}
