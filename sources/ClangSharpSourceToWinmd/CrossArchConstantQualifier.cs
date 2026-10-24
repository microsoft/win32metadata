using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using MetadataUtils;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using Microsoft.CodeAnalysis.Text;

namespace ClangSharpSourceToWinmd
{
    internal static class CrossArchConstantQualifier
    {
        internal static IEnumerable<SyntaxTree> Qualify(SyntaxTree[] trees, IEnumerable<MetadataReference> references)
        {
            var paths = new HashSet<string>(trees.Select(tree => tree.FilePath), StringComparer.OrdinalIgnoreCase);
            var fields = trees.ToDictionary(tree => tree, tree => GetFields(tree).ToArray());
            if (!fields.Values.Any(values => values.Length != 0))
                return trees;

            var originals = trees.ToDictionary(tree => tree.FilePath, StringComparer.OrdinalIgnoreCase);
            var values = new Dictionary<VariableDeclaratorSyntax, (string Identity, string Expression)>();
            var types = new Dictionary<FieldDeclarationSyntax, string>();
            var enumStorage = new Dictionary<string, SpecialType>(StringComparer.Ordinal);
            var varyingEnums = new HashSet<string>(StringComparer.Ordinal);
            var enumUses = new List<(SyntaxTree Tree, VariableDeclaratorSyntax Variable, Architecture Architecture, string Name)>();
            foreach (var architecture in new[] { Architecture.X86, Architecture.X64, Architecture.Arm64 })
            {
                var inputs = trees.Where(tree => HeaderEnumGroupMerger.GetArchitectures(tree.FilePath, paths).HasFlag(architecture)).ToArray();
                var compilation = ClangSharpSourceCompilation.AddNetstandardReference(CSharpCompilation.Create(
                    "CrossArchConstants", inputs, references,
                    new CSharpCompilationOptions(OutputKind.DynamicallyLinkedLibrary, allowUnsafe: true)));
                // Common trees must not be overwritten by another profile's intermediate lowering.
                compilation = HeaderTypedefMerger.LowerConstants(compilation, writeModifiedFiles: false);
                compilation = HeaderEnumGroupMerger.ConvertPrimitiveConstantAliases(compilation, writeModifiedFiles: false);
                foreach (var tree in compilation.SyntaxTrees)
                {
                    var model = compilation.GetSemanticModel(tree);
                    TextSpan[] errorSpans = null;
                    // A profile may define the enum without defining a constant that uses it.
                    foreach (var declaration in tree.GetRoot().DescendantNodes().OfType<EnumDeclarationSyntax>())
                        if (model.GetDeclaredSymbol(declaration) is INamedTypeSymbol declared)
                            RecordEnumStorage(declared, enumStorage, varyingEnums);
                    var original = originals[tree.FilePath];
                    var lowered = GetFields(tree).ToLookup(CrossArchSyntaxMap.GetFullName, StringComparer.Ordinal);
                    foreach (var field in fields[original])
                    {
                        var candidates = lowered[CrossArchSyntaxMap.GetFullName(field)].ToArray();
                        if (candidates.Length != 1)
                            throw Error(original, field.Declaration.Variables.First(), architecture,
                                "The lowered constant does not have a unique original qualified identity.");
                        foreach (var variable in field.Declaration.Variables)
                        {
                            var binding = candidates[0].Declaration.Variables.Single(candidate =>
                                candidate.Identifier.ValueText == variable.Identifier.ValueText);
                            var symbol = model.GetDeclaredSymbol(binding) as IFieldSymbol;
                            if (symbol == null || !symbol.HasConstantValue || binding.Initializer == null ||
                                HasError(binding.Initializer.Span, errorSpans ??= GetErrorSpans(model)))
                                throw Error(original, variable, architecture, "The constant or its dependencies could not be evaluated in this profile.");
                            string type = symbol.Type.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
                            if (symbol.Type is INamedTypeSymbol enumType && enumType.EnumUnderlyingType != null)
                                enumUses.Add((original, variable, architecture, RecordEnumStorage(enumType, enumStorage, varyingEnums)));
                            string expression = GetLiteral(symbol.ConstantValue, symbol.Type, type, original, variable, architecture);
                            string identity = type + ":" + (symbol.Type as INamedTypeSymbol)?.EnumUnderlyingType?.SpecialType + ":" + expression;
                            if (values.TryGetValue(variable, out var existing) && existing.Identity != identity)
                                throw Error(original, variable, architecture,
                                    "A common source constant has architecture-dependent storage or value; provide an architecture-qualified source family.");
                            values[variable] = (identity, expression);
                            types[field] = type;
                        }
                    }
                }
            }

            foreach (var use in enumUses)
                if (varyingEnums.Contains(use.Name))
                    throw Error(use.Tree, use.Variable, use.Architecture,
                        $"Enum '{use.Name}' has architecture-dependent underlying storage; enum-typed constants cannot preserve that identity through composition.");

            return trees.Select(tree => tree.WithRootAndOptions(tree.GetRoot().ReplaceNodes(fields[tree], (field, _) =>
            {
                var variables = field.Declaration.Variables.Select(variable => variable.WithInitializer(
                    variable.Initializer.WithValue(SyntaxFactory.ParseExpression(values[variable].Expression)
                        .WithTriviaFrom(variable.Initializer.Value))));
                return field.WithDeclaration(field.Declaration
                    .WithType(SyntaxFactory.ParseTypeName(types[field]).WithTriviaFrom(field.Declaration.Type))
                    .WithVariables(SyntaxFactory.SeparatedList(variables)));
            }), tree.Options)).ToArray();
        }

        private static IEnumerable<FieldDeclarationSyntax> GetFields(SyntaxTree tree)
            => tree.GetRoot().DescendantNodes().OfType<FieldDeclarationSyntax>().Where(field =>
                CrossArchSyntaxMap.IsPotentialCrossArch(field) && field.Modifiers.Any(SyntaxKind.ConstKeyword));

        private static TextSpan[] GetErrorSpans(SemanticModel model)
        {
            var ordered = model.GetDiagnostics()
                .Where(diagnostic => diagnostic.Severity == DiagnosticSeverity.Error &&
                    diagnostic.Location.SourceTree == model.SyntaxTree)
                .Select(diagnostic => diagnostic.Location.SourceSpan)
                .OrderBy(span => span.Start);
            var spans = new List<TextSpan>();
            foreach (var span in ordered)
            {
                // Merge overlaps so a binary search cannot overlook an enclosing diagnostic.
                int last = spans.Count - 1;
                if (last >= 0 && spans[last].IntersectsWith(span))
                    spans[last] = TextSpan.FromBounds(spans[last].Start, Math.Max(spans[last].End, span.End));
                else
                    spans.Add(span);
            }
            return spans.ToArray();
        }

        private static bool HasError(TextSpan initializer, TextSpan[] errors)
        {
            int low = 0;
            int high = errors.Length;
            while (low < high)
            {
                int middle = low + (high - low) / 2;
                if (errors[middle].Start <= initializer.End)
                    low = middle + 1;
                else
                    high = middle;
            }
            return low > 0 && errors[low - 1].IntersectsWith(initializer);
        }

        private static string RecordEnumStorage(INamedTypeSymbol type, Dictionary<string, SpecialType> storage,
            HashSet<string> varying)
        {
            string name = type.OriginalDefinition.ToDisplayString(SymbolDisplayFormat.FullyQualifiedFormat);
            var underlying = type.EnumUnderlyingType.SpecialType;
            if (storage.TryGetValue(name, out var existing) && existing != underlying)
                varying.Add(name);
            storage[name] = underlying;
            return name;
        }

        private static string GetLiteral(object value, ITypeSymbol symbolType, string type, SyntaxTree tree,
            VariableDeclaratorSyntax variable, Architecture architecture)
        {
            if (value == null)
                return "null";
            if (value is bool boolean)
                return boolean ? "true" : "false";
            if (value is string text)
                return Microsoft.CodeAnalysis.CSharp.SymbolDisplay.FormatLiteral(text, quote: true);
            if (value is char character)
                return Microsoft.CodeAnalysis.CSharp.SymbolDisplay.FormatLiteral(character, quote: true);
            if (value is float single)
            {
                if (float.IsNaN(single)) return "global::System.Single.NaN";
                if (float.IsPositiveInfinity(single)) return "global::System.Single.PositiveInfinity";
                if (float.IsNegativeInfinity(single)) return "global::System.Single.NegativeInfinity";
                return single.ToString("R", CultureInfo.InvariantCulture) + "F";
            }
            if (value is double number)
            {
                if (double.IsNaN(number)) return "global::System.Double.NaN";
                if (double.IsPositiveInfinity(number)) return "global::System.Double.PositiveInfinity";
                if (double.IsNegativeInfinity(number)) return "global::System.Double.NegativeInfinity";
                return number.ToString("R", CultureInfo.InvariantCulture) + "D";
            }
            ulong bits;
            switch (value)
            {
                case sbyte integer: bits = unchecked((ulong)integer); break;
                case byte integer: bits = integer; break;
                case short integer: bits = unchecked((ulong)integer); break;
                case ushort integer: bits = integer; break;
                case int integer: bits = unchecked((ulong)integer); break;
                case uint integer: bits = integer; break;
                case long integer: bits = unchecked((ulong)integer); break;
                case ulong integer: bits = integer; break;
                default:
                    throw Error(tree, variable, architecture,
                        $"Unsupported constant storage '{symbolType.ToDisplayString()}'; no cross-profile fallback is permitted.");
            }
            return $"unchecked(({type}){bits.ToString(CultureInfo.InvariantCulture)}UL)";
        }

        private static InvalidOperationException Error(SyntaxTree tree, VariableDeclaratorSyntax variable,
            Architecture architecture, string message)
            => new InvalidOperationException($"CSSW003: Cannot qualify '{variable.Identifier.ValueText}' in '{tree.FilePath}' for {architecture}. {message}");
    }
}
