using System;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Text.RegularExpressions;
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
        string Name, string Expression, NativeConstantBinding[] Bindings)
    {
        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
        public NativeConstantOccurrence[] Occurrences { get; init; }
    }

    public sealed record NativeConstantSite(
        string Header, string HeaderHash, uint Line, uint Column, uint Offset);

    public sealed record NativeLiteralMacroProof(
        string Literal, NativeConstantSite ExpansionStart, NativeConstantSite ExpansionEnd,
        NativeConstantSite DefinitionStart, NativeConstantSite DefinitionEnd);

    public sealed record NativeConstantOccurrence(
        NativeConstantBinding Binding, NativeConstantSite AttributeStart, NativeConstantSite AttributeEnd,
        NativeConstantSite ArgumentStart, NativeConstantSite ArgumentEnd)
    {
        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
        public NativeLiteralMacroProof Literal { get; init; }
    }

    public sealed record NativeLogicalGroupEvidence(int Version, NativeDeclarationSource Carrier);

    public sealed record NativeConstantGroup(
        string NativeName, string Name, string Namespace, string StorageType,
        string Header, uint Line, NativeConstantGroupMember[] Members)
    {
        public string Kind { get; init; } = "LogicalGroup";

        [JsonProperty(NullValueHandling = NullValueHandling.Ignore)]
        [System.Text.Json.Serialization.JsonIgnore(Condition = System.Text.Json.Serialization.JsonIgnoreCondition.WhenWritingNull)]
        public NativeLogicalGroupEvidence DefinitionEvidence { get; init; }
    }

    public sealed record NativeConstantGroupSource(
        string SourceFile, string SourceHash, Architecture Architecture, NativeConstantGroup Group);

    public static class NativeConstantGroupProvenance
    {
        private const string Family = "/* Win32Metadata.NativeConstantGroup.";
        private const string Suffix = " */";
        private static readonly Regex IntegerToken = new(
            @"\A(?:0[xX][0-9a-fA-F]+|0|[1-9][0-9]*)(?:[uU](?:[lL]|ll|LL)?|(?:[lL]|ll|LL)[uU]?)?\z");

        public static string HashFile(string path)
        {
            using var stream = File.OpenRead(path);
            return Convert.ToHexString(SHA256.HashData(stream));
        }

        public static EnumDeclarationSyntax Attach(EnumDeclarationSyntax declaration, NativeConstantGroupSource source)
        {
            Validate(declaration, source);
            if (Markers(declaration).Any())
                throw new ArgumentException("A logical group already has native constant provenance.", nameof(declaration));
            string json = JsonConvert.SerializeObject(source).Replace("*/", "*\\u002F");
            string prefix = Family + (source.Group.DefinitionEvidence == null ? "v1 " : "v2 ");
            return declaration.WithLeadingTrivia(declaration.GetLeadingTrivia()
                .Add(SyntaxFactory.Comment(prefix + json + Suffix)).Add(SyntaxFactory.ElasticCarriageReturnLineFeed));
        }

        public static NativeConstantGroupSource Read(EnumDeclarationSyntax declaration)
        {
            var markers = Markers(declaration).ToArray();
            if (markers.Length == 0)
                return null;
            if (markers.Length != 1)
                throw new InvalidDataException("Expected one compiler-bound native constant group proof.");
            string text = markers[0].ToString();
            bool version2 = text.StartsWith(Family + "v2 ", StringComparison.Ordinal);
            string prefix = Family + (version2 ? "v2 " : "v1 ");
            if (!text.StartsWith(prefix, StringComparison.Ordinal) || !text.EndsWith(Suffix, StringComparison.Ordinal))
                throw new InvalidDataException("Unsupported native constant group proof version.");
            try
            {
                var json = JObject.Parse(text.Substring(prefix.Length, text.Length - prefix.Length - Suffix.Length),
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                var group = json["Group"] as JObject;
                bool claimsEvidence = ClaimsEvidence(group);
                if (version2 != claimsEvidence)
                    throw new InvalidDataException("Native constant group proof version does not match its definition evidence.");
                if (version2)
                    ValidateSourceJson(json);
                var source = json.ToObject<NativeConstantGroupSource>(StrictSerializer());
                if (version2 && source?.Group?.DefinitionEvidence == null)
                    throw new InvalidDataException("Native constant group v2 requires definition evidence.");
                Validate(declaration, source);
                if (version2 && NativeDeclarationSourceProvenance.Read(declaration) != source.Group.DefinitionEvidence.Carrier)
                    throw new InvalidDataException("Native constant definition evidence disagrees with its declaration source.");
                return source;
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native constant group proof.", error);
            }
        }

        public static NativeConstantValues ReadValues(string text)
        {
            try
            {
                var json = JObject.Parse(text,
                    new JsonLoadSettings { DuplicatePropertyNameHandling = DuplicatePropertyNameHandling.Error });
                var rawGroups = json["Groups"] as JArray;
                if (rawGroups == null || !rawGroups.OfType<JObject>().Any(ClaimsEvidence))
                    return System.Text.Json.JsonSerializer.Deserialize<NativeConstantValues>(text);
                var values = System.Text.Json.JsonSerializer.Deserialize<NativeConstantValues>(text);
                if (values?.Groups == null)
                    throw new InvalidDataException("Missing native constant groups.");
                for (int i = 0; i < values.Groups.Count; i++)
                {
                    var group = values.Groups[i];
                    if (ClaimsEvidence(rawGroups[i] as JObject))
                    {
                        RequireProperties(json, ("SourceFile", JTokenType.String), ("SourceHash", JTokenType.String),
                            ("Architecture", JTokenType.Integer));
                        ValidateGroupJson(rawGroups[i], requireEvidence: true);
                        rawGroups[i].ToObject<NativeConstantGroup>(StrictSerializer());
                        ValidateSource(new NativeConstantGroupSource(values.SourceFile, values.SourceHash, values.Architecture, group));
                    }
                }
                return values;
            }
            catch (JsonException error)
            {
                throw new InvalidDataException("Malformed native constant definition evidence.", error);
            }
            catch (System.Text.Json.JsonException error)
            {
                throw new InvalidDataException("Malformed native constant definition evidence.", error);
            }
        }

        internal static JsonSerializer StrictSerializer() => JsonSerializer.Create(
            new JsonSerializerSettings { MissingMemberHandling = MissingMemberHandling.Error });

        internal static JObject RequireProperties(JToken value, params (string Name, JTokenType Type)[] properties)
        {
            if (value is not JObject json || properties.Any(property => json[property.Name]?.Type != property.Type))
                throw new InvalidDataException("Missing or incorrectly typed native proof fields.");
            return json;
        }

        internal static void ValidateSourceJson(JToken value)
        {
            var json = RequireProperties(value, ("SourceFile", JTokenType.String), ("SourceHash", JTokenType.String),
                ("Architecture", JTokenType.Integer), ("Group", JTokenType.Object));
            ValidateGroupJson(json["Group"], ClaimsEvidence(json["Group"] as JObject));
        }

        private static bool ClaimsEvidence(JObject group) => group?.Property("DefinitionEvidence") != null ||
            (group?["Members"] as JArray)?.OfType<JObject>().Any(member => member.Property("Occurrences") != null) == true;

        internal static void ValidateCarrierJson(JToken value) => RequireProperties(value,
            ("Identity", JTokenType.String), ("NativeName", JTokenType.String), ("Header", JTokenType.String),
            ("HeaderHash", JTokenType.String), ("Line", JTokenType.Integer), ("Column", JTokenType.Integer),
            ("Name", JTokenType.String), ("Namespace", JTokenType.String), ("TraversedHeader", JTokenType.Boolean),
            ("Kind", JTokenType.Integer), ("SourceArchitecture", JTokenType.Integer));

        private static void ValidateGroupJson(JToken value, bool requireEvidence)
        {
            var group = RequireProperties(value, ("NativeName", JTokenType.String), ("Name", JTokenType.String),
                ("Namespace", JTokenType.String), ("StorageType", JTokenType.String), ("Header", JTokenType.String),
                ("Line", JTokenType.Integer), ("Kind", JTokenType.String), ("Members", JTokenType.Array));
            if (requireEvidence)
            {
                var evidence = RequireProperties(group["DefinitionEvidence"],
                    ("Version", JTokenType.Integer), ("Carrier", JTokenType.Object));
                ValidateCarrierJson(evidence["Carrier"]);
            }
            foreach (var memberValue in (JArray)group["Members"])
            {
                var member = RequireProperties(memberValue, ("Name", JTokenType.String),
                    ("Expression", JTokenType.String), ("Bindings", JTokenType.Array));
                foreach (var binding in (JArray)member["Bindings"])
                    ValidateBindingJson(binding);
                if (!requireEvidence)
                    continue;
                RequireProperties(member, ("Occurrences", JTokenType.Array));
                foreach (var occurrenceValue in (JArray)member["Occurrences"])
                {
                    var occurrence = RequireProperties(occurrenceValue, ("Binding", JTokenType.Object),
                        ("AttributeStart", JTokenType.Object), ("AttributeEnd", JTokenType.Object),
                        ("ArgumentStart", JTokenType.Object), ("ArgumentEnd", JTokenType.Object));
                    ValidateBindingJson(occurrence["Binding"]);
                    foreach (string site in new[] { "AttributeStart", "AttributeEnd", "ArgumentStart", "ArgumentEnd" })
                        ValidateSiteJson(occurrence[site]);
                    if (occurrence["Literal"] == null || occurrence["Literal"].Type == JTokenType.Null)
                        continue;
                    var literal = RequireProperties(occurrence["Literal"], ("Literal", JTokenType.String),
                        ("ExpansionStart", JTokenType.Object), ("ExpansionEnd", JTokenType.Object),
                        ("DefinitionStart", JTokenType.Object), ("DefinitionEnd", JTokenType.Object));
                    foreach (string site in new[] { "ExpansionStart", "ExpansionEnd", "DefinitionStart", "DefinitionEnd" })
                        ValidateSiteJson(literal[site]);
                }
            }
        }

        internal static void ValidateBindingJson(JToken value)
        {
            var binding = RequireProperties(value, ("Kind", JTokenType.String), ("Header", JTokenType.String),
                ("Line", JTokenType.Integer), ("Column", JTokenType.Integer), ("HeaderHash", JTokenType.String),
                ("NativeType", JTokenType.String), ("StorageType", JTokenType.String), ("Value", JTokenType.String));
            RequireProperties(binding, ("NativeName", binding["Kind"].Value<string>() == "Expression" &&
                binding["NativeName"]?.Type == JTokenType.Null ? JTokenType.Null : JTokenType.String));
        }

        private static void ValidateSiteJson(JToken value) => RequireProperties(value,
            ("Header", JTokenType.String), ("HeaderHash", JTokenType.String), ("Line", JTokenType.Integer),
            ("Column", JTokenType.Integer), ("Offset", JTokenType.Integer));

        public static void ValidateSource(NativeConstantGroupSource source)
        {
            var group = source?.Group;
            if (group == null || string.IsNullOrEmpty(source.SourceFile) || !IsHash(source.SourceHash) ||
                source.Architecture is not (Architecture.X86 or Architecture.X64 or Architecture.Arm64) ||
                string.IsNullOrEmpty(group.NativeName) || string.IsNullOrEmpty(group.Name) ||
                string.IsNullOrEmpty(group.Header) || group.Line == 0 || group.Members == null ||
                group.Members.Select(member => member?.Name).Distinct(StringComparer.Ordinal).Count() != group.Members.Length ||
                group.Kind is not ("LogicalGroup" or "NativeEnum"))
                throw new InvalidDataException("Invalid native constant group source.");
            foreach (var member in group.Members)
            {
                if (member == null || string.IsNullOrEmpty(member.Name) || member.Bindings == null ||
                    member.Bindings.Length == 0 || member.Bindings.Any(binding => !ValidBinding(binding)) ||
                    group.Kind == "LogicalGroup" && (string.IsNullOrEmpty(member.Expression) ||
                        SyntaxFactory.ParseExpression(member.Expression).ContainsDiagnostics))
                    throw new InvalidDataException("Invalid native constant group member binding.");
            }
            if (group.DefinitionEvidence == null)
            {
                if (group.Members.Any(member => member.Occurrences != null))
                    throw new InvalidDataException("Native constant occurrences require versioned definition evidence.");
                return;
            }
            var carrier = group.DefinitionEvidence.Carrier;
            if (group.DefinitionEvidence.Version != 1 || group.Kind != "LogicalGroup" ||
                carrier == null || carrier.Kind != NativeDeclarationKind.LogicalEnum ||
                !NativeRecordSourceProvenance.IsValidIdentity(carrier.Identity, carrier.NativeName, carrier.Header,
                    carrier.HeaderHash, carrier.Line, carrier.Column, carrier.Name, carrier.Namespace, carrier.SourceArchitecture) ||
                carrier.Name != group.Name || carrier.Namespace != group.Namespace ||
                carrier.SourceArchitecture != source.Architecture ||
                NativeName(carrier.NativeName) != NativeName(group.NativeName))
                throw new InvalidDataException("Native logical carrier does not match its original constant contribution.");
            foreach (var member in group.Members)
            {
                if (member.Occurrences == null || member.Occurrences.Length == 0 ||
                    member.Occurrences.Any(occurrence => occurrence == null) ||
                    !member.Bindings.SequenceEqual(member.Occurrences.Select(occurrence => occurrence.Binding).Distinct()) ||
                    member.Occurrences.Select(occurrence => (occurrence.AttributeStart, occurrence.ArgumentStart))
                        .Distinct().Count() != member.Occurrences.Length)
                    throw new InvalidDataException($"Native occurrence inventory does not match member '{member.Name}'.");
                foreach (var occurrence in member.Occurrences)
                {
                    if (!ValidBinding(occurrence.Binding) || !ValidOccurrenceRange(occurrence))
                        throw new InvalidDataException(
                            $"Invalid native occurrence site for '{member.Name}' in '{group.Namespace}.{group.Name}' " +
                            $"({source.Architecture}). Occurrence={JsonConvert.SerializeObject(occurrence)}");
                    if (occurrence.Literal != null)
                    {
                        ValidateLiteral(occurrence);
                        if (!MatchesProjectedLiteral(member.Expression, group.StorageType, occurrence.Binding.Value))
                            throw new InvalidDataException($"Native literal value does not match projected member '{member.Name}'.");
                    }
                }
            }
        }

        public static bool IsSupportedIntegerLiteral(string text, NativeConstantBinding binding) =>
            text != null && binding != null && IntegerToken.IsMatch(text) &&
            ConstantsScraper.TryReadSimpleMacroValue(text, cplusplus: true, windowsTarget: true,
                _ => null, _ => null, out var value) &&
            value.Kind == "Integer" && value.NativeType == binding.NativeType &&
            value.StorageType == binding.StorageType && value.Value == binding.Value;

        internal static string NativeName(string name) =>
            name?.StartsWith("::", StringComparison.Ordinal) == true ? name.Substring(2) : name;

        public static bool IsSupportedLiteralOccurrence(NativeConstantOccurrence occurrence)
        {
            var binding = occurrence?.Binding;
            var proof = occurrence?.Literal;
            return binding != null && proof != null && binding.Kind == "Macro" && !string.IsNullOrEmpty(binding.NativeName) &&
                IsSupportedIntegerLiteral(proof.Literal, binding) &&
                ValidOccurrenceRange(occurrence) &&
                ValidRange(proof.ExpansionStart, proof.ExpansionEnd) &&
                ValidRange(proof.DefinitionStart, proof.DefinitionEnd) &&
                SameSite(occurrence.ArgumentStart, proof.ExpansionStart) &&
                SameSite(occurrence.ArgumentEnd, proof.ExpansionEnd) &&
                proof.ExpansionEnd.Offset - proof.ExpansionStart.Offset == Encoding.UTF8.GetByteCount(binding.NativeName) &&
                string.Equals(proof.DefinitionStart.Header, binding.Header, StringComparison.OrdinalIgnoreCase) &&
                proof.DefinitionStart.HeaderHash == binding.HeaderHash &&
                proof.DefinitionStart.Line == binding.Line && proof.DefinitionStart.Column == binding.Column;
        }

        private static void ValidateLiteral(NativeConstantOccurrence occurrence)
        {
            if (!IsSupportedLiteralOccurrence(occurrence))
                throw new InvalidDataException("Native whole-argument literal macro evidence is inconsistent.");
        }

        private static bool MatchesProjectedLiteral(string expression, string storage, string value)
        {
            int width = storage switch
            {
                "byte" or "sbyte" => 8, "short" or "ushort" => 16,
                "int" or "uint" => 32, "long" or "ulong" => 64, _ => 0,
            };
            if (width == 0 || !ulong.TryParse(value.TrimEnd('U', 'L'), NumberStyles.None,
                CultureInfo.InvariantCulture, out ulong bits))
                return false;
            return SyntaxFactory.AreEquivalent(SyntaxFactory.ParseExpression(expression),
                SyntaxFactory.ParseExpression($"unchecked(({storage}){bits.ToString(CultureInfo.InvariantCulture)}UL)"));
        }

        private static bool ValidBinding(NativeConstantBinding binding) => binding != null &&
            (binding.Kind == "Expression" || !string.IsNullOrEmpty(binding.NativeName)) &&
            binding.Kind is "Macro" or "CXCursor_VarDecl" or "CXCursor_EnumConstantDecl" or "Expression" &&
            !string.IsNullOrEmpty(binding.Header) && binding.Line != 0 && binding.Column != 0 &&
            IsHash(binding.HeaderHash) && !string.IsNullOrEmpty(binding.NativeType) &&
            !string.IsNullOrEmpty(binding.StorageType) && !string.IsNullOrEmpty(binding.Value);

        private static bool ValidSite(NativeConstantSite site) => site != null &&
            !string.IsNullOrEmpty(site.Header) && IsHash(site.HeaderHash) && site.Line != 0 && site.Column != 0;

        private static bool SameHeader(NativeConstantSite left, NativeConstantSite right) =>
            string.Equals(left.Header, right.Header, StringComparison.OrdinalIgnoreCase) && left.HeaderHash == right.HeaderHash;

        private static bool SameSite(NativeConstantSite left, NativeConstantSite right) =>
            SameHeader(left, right) && left.Line == right.Line && left.Column == right.Column && left.Offset == right.Offset;

        private static bool ValidRange(NativeConstantSite start, NativeConstantSite end) =>
            ValidSite(start) && ValidSite(end) && SameHeader(start, end) && end.Offset > start.Offset &&
            (end.Line > start.Line || end.Line == start.Line && end.Column > start.Column);

        private static bool ValidOccurrenceRange(NativeConstantOccurrence occurrence) =>
            ValidRange(occurrence.AttributeStart, occurrence.AttributeEnd) &&
            ValidRange(occurrence.ArgumentStart, occurrence.ArgumentEnd) &&
            SameHeader(occurrence.AttributeStart, occurrence.ArgumentStart) &&
            AtOrBefore(occurrence.AttributeStart, occurrence.ArgumentStart) &&
            AtOrBefore(occurrence.ArgumentEnd, occurrence.AttributeEnd);

        private static bool AtOrBefore(NativeConstantSite start, NativeConstantSite end) =>
            start.Offset <= end.Offset && (start.Line < end.Line || start.Line == end.Line && start.Column <= end.Column);

        private static void Validate(EnumDeclarationSyntax declaration, NativeConstantGroupSource source)
        {
            ValidateSource(source);
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

        private static System.Collections.Generic.IEnumerable<SyntaxTrivia> Markers(EnumDeclarationSyntax declaration) =>
            declaration.GetLeadingTrivia().Concat(declaration.GetTrailingTrivia()).Where(IsMarker);

        private static bool IsHash(string value) => value?.Length == 64 && value.All(Uri.IsHexDigit);
    }
}
