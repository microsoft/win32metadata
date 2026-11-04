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

        private unsafe NativeConstantBinding ReadConstantBinding(Attr attribute, string name, Cursor argument, NativeLocation location)
        {
            EnsureConstantGroups();
            var start = GetLocation(attribute.Extent.Start);
            var end = GetLocation(attribute.Extent.End);
            var argumentLocation = FileLocation(argument.Extent.Start);
            var macros = constantMacroExpansions[(argumentLocation.File, argumentLocation.Offset)].Where(macro =>
            {
                var use = GetLocation(macro.Location);
                return string.Equals(use.File, start.File, StringComparison.OrdinalIgnoreCase) &&
                    use.Offset >= start.Offset && use.Offset < end.Offset;
            }).Select(macro => macro.Handle.Referenced).Distinct().ToArray();
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
            return new NativeConstantBinding(kind, identity, definition.File, definition.Line, definition.Column,
                hash, expression.Type.AsString, storage, literal);

            static NativeLocation FileLocation(CXSourceLocation source)
            {
                source.GetFileLocation(out var file, out uint line, out uint column, out uint offset);
                return new NativeLocation(file.ToString(), line, column, offset);
            }
        }

        private NativeConstantGroupSource GetConstantGroupSource(DeclarationFacts facts)
        {
            EnsureConstantGroups();
            var alias = (TypedefNameDecl)facts.Declaration;
            var group = new NativeConstantGroup(GetNativeTarget(alias.Handle), Remap(alias.Name), generatedNamespace,
                GetManagedType(alias.UnderlyingType, facts.Location), facts.Location.File, facts.Location.Line,
                facts.LogicalEnumMembers.Select(member => new NativeConstantGroupMember(
                    Remap(member.Name), member.Value, member.Bindings)).ToArray());
            return new NativeConstantGroupSource(constantSourceFile, constantSourceHash, constantArchitecture, group);
        }

        internal NativeConstantGroup[] GetConstantGroups() => annotatedTypedefs
            .Where(facts => facts.LogicalEnumMembers != null &&
                ShouldProjectTypedef((TypedefNameDecl)facts.Declaration, facts.Location))
            .GroupBy(facts => facts.AnnotationOwner).Select(group => GetConstantGroupSource(group.First()).Group)
            .Concat(nativeEnumGroups.Values).ToArray();
    }
}
