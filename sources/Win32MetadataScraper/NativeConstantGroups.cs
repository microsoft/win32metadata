using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;

namespace Win32MetadataScraper
{
    internal sealed partial class HeaderAnnotationProcessor
    {
        private ILookup<(string File, uint Offset), Cursor> constantMacroExpansions;
        private readonly Dictionary<string, (NativeLocation Start, NativeLocation End)[]> constantMacroRanges =
            new(StringComparer.OrdinalIgnoreCase);
        private readonly Dictionary<string, string> constantHeaderHashes = new(StringComparer.OrdinalIgnoreCase);
        private string constantSourceFile;
        private string constantSourceHash;
        private Architecture constantArchitecture;
        private TranslationUnit constantTranslationUnit;
        private readonly HashSet<string> nativeAliasTargets = new(StringComparer.Ordinal);
        private readonly Dictionary<string, NativeConstantGroup> nativeEnumGroups = new(StringComparer.Ordinal);

        private void InitializeConstantGroups(TranslationUnit unit) => constantTranslationUnit = unit;

        internal void SetNativeConstantAliases(NativeConstantValues values)
        {
            if (values != null)
                nativeAliasTargets.UnionWith(values.Constants.Where(value => value.AliasTarget != null)
                    .Select(value => value.AliasTarget.NativeName));
        }

        private bool HasNativeConstantAliases(EnumDecl declaration) => declaration.CursorChildren.OfType<EnumConstantDecl>()
            .Any(member => nativeAliasTargets.Contains(GetNativeTarget(member.Handle)));

        private NativeConstantGroupSource GetNativeEnumSource(
            DeclarationFacts facts, EnumDeclarationSyntax declaration, string ns, NativeConstantBinding[] bindings)
        {
            EnsureConstantGroups();
            var group = new NativeConstantGroup(GetNativeTarget(facts.Declaration.Handle), declaration.Identifier.ValueText, ns,
                declaration.BaseList?.Types.Single().Type.ToString() ?? "int", facts.Location.File, facts.Location.Line,
                declaration.Members.Select((member, index) => new NativeConstantGroupMember(
                    member.Identifier.ValueText, member.EqualsValue?.Value.ToString(), new[] { bindings[index] })).ToArray())
            {
                Kind = "NativeEnum",
            };
            nativeEnumGroups[group.NativeName] = group;
            return new NativeConstantGroupSource(constantSourceFile, constantSourceHash, constantArchitecture, group);
        }

        private NativeConstantBinding ReadNativeEnumBinding(DeclarationFacts facts)
        {
            if (facts?.Declaration is not EnumConstantDecl)
                throw new InvalidOperationException("A projected native enum alias has no compiler-bound member declaration.");
            return NativeConstantExtractor.ReadEnumConstantBinding(facts.Declaration.Handle, header =>
            {
                if (!constantHeaderHashes.TryGetValue(header, out string hash))
                    constantHeaderHashes[header] = hash = NativeConstantGroupProvenance.HashFile(header);
                return hash;
            });
        }

        private void EnsureConstantGroups()
        {
            if (constantMacroExpansions != null)
                return;
            var unit = constantTranslationUnit;
            constantSourceFile = Path.GetFullPath(unit.Handle.Spelling.ToString());
            constantSourceHash = NativeConstantGroupProvenance.HashFile(constantSourceFile);
            using (var target = unit.Handle.TargetInfo)
            using (var triple = target.Triple)
                constantArchitecture = triple.ToString().Split('-')[0] switch
                {
                    "i386" or "i486" or "i586" or "i686" => Architecture.X86,
                    "x86_64" => Architecture.X64,
                    "aarch64" => Architecture.Arm64,
                    _ => throw new InvalidOperationException($"Unsupported constant group target '{triple}'."),
                };
            constantMacroExpansions = unit.TranslationUnitDecl.CursorChildren
                .Where(cursor => cursor.CursorKind == CXCursorKind.CXCursor_MacroExpansion)
                .ToLookup(cursor =>
                {
                    var location = GetLocation(cursor.Location);
                    return (location.File, location.Offset);
                });
        }

        private unsafe NativeConstantOccurrence ReadConstantOccurrence(Attr attribute, string name, Cursor argument, NativeLocation location)
        {
            EnsureConstantGroups();
            var start = GetLocation(attribute.Extent.Start);
            var end = GetLocation(attribute.Extent.End);
            var argumentLocation = ConstantFileLocation(argument.Extent.Start);
            var expansions = constantMacroExpansions[(argumentLocation.File, argumentLocation.Offset)].Where(macro =>
            {
                var use = GetLocation(macro.Location);
                return string.Equals(use.File, start.File, StringComparison.OrdinalIgnoreCase) &&
                    use.Offset >= start.Offset && use.Offset < end.Offset;
            }).ToArray();
            var macros = expansions.Select(macro => macro.Handle.Referenced).Distinct().ToArray();
            CXCursor declaration;
            string kind, identity;
            if (macros.Length == 1)
            {
                declaration = macros[0];
                kind = "Macro";
                identity = declaration.Spelling.ToString();
            }
            else
            {
                var references = GetDeclarationReferences(argument).Where(reference =>
                    reference.Kind is CXCursorKind.CXCursor_VarDecl or CXCursorKind.CXCursor_EnumConstantDecl).ToArray();
                declaration = references.Length == 1 ? references[0] : default;
                kind = macros.Length == 0 && references.Length == 1 ? declaration.Kind.ToString() : "Expression";
                identity = kind == "Expression" ? null : GetNativeTarget(declaration);
            }
            var definition = kind == "Expression" ? argumentLocation : GetLocation(declaration.Location);
            if (!constantHeaderHashes.TryGetValue(definition.File, out string hash))
                constantHeaderHashes[definition.File] = hash = NativeConstantGroupProvenance.HashFile(definition.File);
            var expression = (Expr)argument;
            var type = expression.Type.Handle.CanonicalType;
            if (type.kind == CXTypeKind.CXType_Enum)
                type = clang.getEnumDeclIntegerType(clang.getTypeDeclaration(type)).CanonicalType;
            string storage = NativeConstantExtractor.GetStorage(type);
            if (storage == null)
                throw Error(location, $"Unsupported native integer storage for group member '{name}'.");
            using var value = argument.Handle.Evaluate;
            string number = value.IsUnsignedInt ? value.AsUnsigned.ToString(CultureInfo.InvariantCulture) :
                value.AsLongLong.ToString(CultureInfo.InvariantCulture);
            string literal = storage switch
            {
                "uint" => number + "U", "long" => number + "L", "ulong" => number + "UL",
                "bool" => number == "0" ? "false" : "true",
                "char" => SymbolDisplay.FormatLiteral((char)value.AsUnsigned, quote: true),
                _ => number,
            };
            var binding = new NativeConstantBinding(kind, identity, definition.File, definition.Line, definition.Column,
                hash, expression.Type.AsString, storage, literal);
            var argumentRange = ReadArgumentFileRange(attribute, argument);
            var occurrence = new NativeConstantOccurrence(binding, ReadSite(attribute.Extent.Start),
                ReadSite(attribute.Extent.End), ReadSite(argumentRange.Start), ReadSite(argumentRange.End));
            if (kind == "Macro" && expansions.Length == 1)
                occurrence = occurrence with { Literal = ReadLiteralMacro(expansions[0].Handle, argument, argumentRange, occurrence) };
            return occurrence;
        }

        private CXSourceRange ReadArgumentFileRange(Attr attribute, Cursor argument)
        {
            var attributeStart = ConstantFileLocation(attribute.Extent.Start);
            var attributeEnd = ConstantFileLocation(attribute.Extent.End);
            var originalStart = ConstantFileLocation(argument.Extent.Start);
            var originalEnd = ConstantFileLocation(argument.Extent.End);
            var start = originalStart;
            var end = originalEnd;
            if (!constantMacroRanges.TryGetValue(attributeStart.File, out var ranges))
            {
                ranges = constantMacroExpansions
                    .Where(group => string.Equals(group.Key.File, attributeStart.File, StringComparison.OrdinalIgnoreCase))
                    .SelectMany(group => group)
                    .Select(macro => (Start: ConstantFileLocation(macro.Extent.Start), End: ConstantFileLocation(macro.Extent.End)))
                    .Where(range => string.Equals(range.Start.File, range.End.File, StringComparison.OrdinalIgnoreCase) &&
                        range.Start.Offset < range.End.Offset)
                    .Distinct().ToArray();
                constantMacroRanges.Add(attributeStart.File, ranges);
            }
            // Macro-argument file locations can collapse an expansion to its first offset.
            foreach (var range in ranges.Where(range =>
                range.Start.Offset >= attributeStart.Offset && range.End.Offset <= attributeEnd.Offset &&
                (range.Start.Offset > attributeStart.Offset || range.End.Offset < attributeEnd.Offset)))
            {
                if (Contains(range, originalStart) && range.Start.Offset < start.Offset)
                    start = range.Start;
                if (Contains(range, originalEnd) && range.End.Offset > end.Offset)
                    end = range.End;
            }
            var unit = constantTranslationUnit.Handle;
            return CXSourceRange.Create(unit.GetLocationForOffset(unit.GetFile(start.File), start.Offset),
                unit.GetLocationForOffset(unit.GetFile(end.File), end.Offset));

            static bool Contains((NativeLocation Start, NativeLocation End) range, NativeLocation point) =>
                string.Equals(range.Start.File, point.File, StringComparison.OrdinalIgnoreCase) &&
                range.Start.Offset <= point.Offset && point.Offset < range.End.Offset;
        }

        private static NativeLocation ConstantFileLocation(CXSourceLocation source)
        {
            source.GetFileLocation(out var file, out uint line, out uint column, out uint offset);
            return new NativeLocation(file.ToString(), line, column, offset);
        }

        private NativeConstantSite ReadSite(CXSourceLocation source)
        {
            source.GetFileLocation(out var file, out uint line, out uint column, out uint offset);
            string header = Path.GetFullPath(file.ToString());
            if (!constantHeaderHashes.TryGetValue(header, out string hash))
                constantHeaderHashes[header] = hash = NativeConstantGroupProvenance.HashFile(header);
            return new NativeConstantSite(header, hash, line, column, offset);
        }

        private NativeLiteralMacroProof ReadLiteralMacro(
            CXCursor expansion, Cursor argument, CXSourceRange argumentRange, NativeConstantOccurrence occurrence)
        {
            var definition = expansion.Referenced;
            if (definition.Kind != CXCursorKind.CXCursor_MacroDefinition || definition.IsMacroFunctionLike)
                return null;
            var literalArgument = argument;
            while (literalArgument.CursorKind == CXCursorKind.CXCursor_UnexposedExpr)
            {
                var children = literalArgument.CursorChildren.ToArray();
                if (children.Length != 1)
                    return null;
                literalArgument = children[0];
            }
            if (literalArgument.CursorKind != CXCursorKind.CXCursor_IntegerLiteral)
                return null;
            var unit = constantTranslationUnit.Handle;
            var argumentTokens = unit.Tokenize(argumentRange);
            var definitionTokens = unit.Tokenize(definition.Extent);
            try
            {
                var use = argumentTokens.ToArray().Where(token => token.Kind != CXTokenKind.CXToken_Comment).ToArray();
                var body = definitionTokens.ToArray().Where(token => token.Kind != CXTokenKind.CXToken_Comment).ToArray();
                if (use.Length != 1 || use[0].Kind != CXTokenKind.CXToken_Identifier ||
                    body.Length != 2 || body[0].Kind != CXTokenKind.CXToken_Identifier ||
                    body[1].Kind != CXTokenKind.CXToken_Literal ||
                    TokenText(use[0]) != occurrence.Binding.NativeName ||
                    TokenText(body[0]) != occurrence.Binding.NativeName)
                    return null;
                string text = TokenText(body[1]);
                if (!NativeConstantGroupProvenance.IsSupportedIntegerLiteral(text, occurrence.Binding))
                    return null;
                var expansionStart = ReadSite(expansion.Extent.Start);
                var expansionEnd = ReadSite(expansion.Extent.End);
                if (occurrence.ArgumentStart != expansionStart || occurrence.ArgumentEnd != expansionEnd ||
                    occurrence.AttributeStart.Header != occurrence.ArgumentStart.Header ||
                    occurrence.AttributeStart.Offset > occurrence.ArgumentStart.Offset ||
                    occurrence.AttributeEnd.Offset < occurrence.ArgumentEnd.Offset)
                    return null;
                var proof = new NativeLiteralMacroProof(text, expansionStart, expansionEnd,
                    ReadSite(definition.Extent.Start), ReadSite(definition.Extent.End));
                return NativeConstantGroupProvenance.IsSupportedLiteralOccurrence(occurrence with { Literal = proof }) ? proof : null;
            }
            finally
            {
                unit.DisposeTokens(argumentTokens);
                unit.DisposeTokens(definitionTokens);
            }

            string TokenText(CXToken token)
            {
                using var spelling = token.GetSpelling(unit);
                return spelling.ToString();
            }
        }

        private NativeConstantGroupSource GetConstantGroupSource(DeclarationFacts facts)
        {
            EnsureConstantGroups();
            var alias = (TypedefNameDecl)facts.Declaration;
            var group = new NativeConstantGroup(GetNativeTarget(alias.Handle), Remap(alias.Name), generatedNamespace,
                GetManagedType(alias.UnderlyingType, facts.Location), facts.Location.File, facts.Location.Line,
                facts.LogicalEnumMembers.Select(member => new NativeConstantGroupMember(
                    Remap(member.Name), member.Value, member.Bindings) { Occurrences = member.Occurrences }).ToArray())
            {
                DefinitionEvidence = new NativeLogicalGroupEvidence(1,
                    GetNativeDeclarationSource(alias, Remap(alias.Name), generatedNamespace, NativeDeclarationKind.LogicalEnum)),
            };
            return new NativeConstantGroupSource(constantSourceFile, constantSourceHash, constantArchitecture, group);
        }

        internal NativeConstantGroup[] GetConstantGroups() => annotatedTypedefs
            .Where(facts => facts.LogicalEnumMembers != null &&
                ShouldProjectTypedef((TypedefNameDecl)facts.Declaration, facts.Location))
            .GroupBy(facts => facts.AnnotationOwner).Select(group => GetConstantGroupSource(group.First()).Group)
            .Concat(nativeEnumGroups.Values).ToArray();
    }
}
