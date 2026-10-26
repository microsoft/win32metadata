using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;

namespace Win32MetadataScraper
{
    internal static unsafe class NativeConstantExtractor
    {
        internal static NativeConstantValues Extract(TranslationUnit original, string sourceFile,
            NativeConstantProbePlan probes, PInvokeGeneratorConfiguration configuration,
            IReadOnlyCollection<string> requestedNames = null)
        {
            using var timing = GenerationTiming.BeginSpan("native-constants.extract");
            using var collectionTiming = GenerationTiming.BeginSpan("native-constants.collect-candidates");
            long compilerEvaluations = 0;
            long scannerIntegers = 0;
            var exactExcludes = configuration.ExcludedNames.ToHashSet(StringComparer.Ordinal);
            string[] wildcardExcludes = exactExcludes.Where(name => name.IndexOfAny(new[] { '*', '?' }) >= 0).ToArray();
            var result = new NativeConstantValues
            {
                BindingSource = configuration.OutputLocation,
                SourceFile = Path.GetFullPath(sourceFile),
                SourceHash = NativeConstantGroupProvenance.HashFile(sourceFile),
                Namespace = configuration.DefaultNamespace,
                Routes = probes.PreparedNames.OrderBy(name => name, StringComparer.Ordinal)
                    .Select(name => probes.Routes[name]).ToList(),
            };
            using (var target = original.Handle.TargetInfo)
            using (var triple = target.Triple)
                result.Architecture = triple.ToString().Split('-')[0] switch
                {
                    "i386" or "i486" or "i586" or "i686" => Architecture.X86,
                    "x86_64" => Architecture.X64,
                    "aarch64" => Architecture.Arm64,
                    _ => throw new InvalidOperationException($"Unsupported constant target '{triple}'."),
                };

            var definitions = original.TranslationUnitDecl.CursorChildren.OfType<MacroDefinitionRecord>()
                .Select(macro => (Macro: macro, Location: GetLocation(macro.Location)))
                .Where(value => value.Location.File.Length != 0 && !value.Location.File.StartsWith("<", StringComparison.Ordinal))
                .ToArray();
            result.Headers = definitions.Where(value => IsTraversed(value.Location.File, sourceFile, configuration.TraversalNames))
                .Select(value => value.Location.File).Distinct(StringComparer.OrdinalIgnoreCase).ToArray();
            var requested = requestedNames == null ? null : new HashSet<string>(requestedNames, StringComparer.Ordinal);
            var headerHashes = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            var eligible = definitions.Where(value => !value.Macro.IsFunctionLike &&
                    (requested != null ? requested.Contains(value.Macro.Name) :
                        IsTraversed(value.Location.File, sourceFile, configuration.TraversalNames)) &&
                    !IsExcluded(value.Macro.Name))
                .GroupBy(value => value.Macro.Name, StringComparer.Ordinal)
                .ToDictionary(group => group.Key, group => group.First().Location, StringComparer.Ordinal);
            var scanned = new HashSet<string>(probes.Names, StringComparer.Ordinal);
            string[] unscanned = eligible.Keys.Where(name => !scanned.Contains(name))
                .OrderBy(name => name, StringComparer.Ordinal).ToArray();
            if (unscanned.Length != 0)
                throw new InvalidOperationException("Object-like macros were not included in the pre-compile name scan: " +
                    string.Join(", ", unscanned));
            var candidates = probes.Names.Where(eligible.ContainsKey)
                .Select(name => new Candidate(name, eligible[name])).ToArray();
            if (requested != null)
                foreach (string name in requested.Except(candidates.Select(candidate => candidate.Name), StringComparer.Ordinal))
                    result.Issues.Add(new NativeConstantIssue(name, sourceFile,
                        IsExcluded(name) ? "excluded by configuration" : "no object-like macro definition", Array.Empty<string>()));
            collectionTiming?.SetCounter("definitionCount", definitions.Length);
            collectionTiming?.SetCounter("candidateCount", candidates.Length);
            collectionTiming?.SetCounter("requestedCount", requested?.Count ?? 0);
            collectionTiming?.Dispose();
            using var extractionTiming = GenerationTiming.BeginSpan("native-constants.hybrid-value-extraction");
            foreach (var candidate in candidates)
            {
                probes.Variables.TryGetValue(candidate.Name, out var variable);
                var owner = probes.ActiveDefinition(candidate.Name);
                if (owner != null &&
                    requested == null && !IsTraversed(owner.File, sourceFile, configuration.TraversalNames))
                {
                    Reject(candidate, "active definition is outside traversed headers");
                    continue;
                }
                if (!probes.IsDefined(candidate.Name))
                {
                    Reject(candidate, "undefined in the final header environment");
                    continue;
                }
                if (owner == null)
                {
                    Reject(candidate, "active macro definition is not recorded by Clang");
                    continue;
                }
                if (!probes.Routes.TryGetValue(candidate.Name, out var route))
                    throw new InvalidOperationException($"Native constant '{candidate.Name}' was not scheduled before binding generation.");
                if (route.Route == "NonValue")
                {
                    Reject(candidate, "non-value macro: " + route.Reason);
                    continue;
                }
                if (probes.SimpleValues.TryGetValue(candidate.Name, out var simple))
                {
                    if (simple.Kind == "Integer")
                    {
                        string simpleName = configuration.RemappedNames.GetValueOrDefault(candidate.Name) ?? candidate.Name;
                        result.Constants.Add(new NativeConstantValue(candidate.Name, simpleName, owner.File, owner.Line,
                            simple.NativeType, simple.StorageType, simple.Value)
                        {
                            Column = owner.Column,
                            HeaderHash = HeaderHash(owner.File),
                            Evaluation = "Scanner",
                        });
                        scannerIntegers++;
                    }
                    else
                        Reject(candidate, simple.Kind is "String" or "Pointer" ? "pointer constant" :
                            simple.Kind == "Floating" ? "not a supported integer type" : "scanner-resolved non-integer constant");
                    continue;
                }
                if (variable?.Init?.Type.Handle.CanonicalType.kind == CXTypeKind.CXType_Pointer)
                {
                    Reject(candidate, "pointer constant",
                        probes.Errors.GetValueOrDefault(candidate.Name)?.ToArray() ?? Array.Empty<string>());
                    continue;
                }
                if (probes.Errors.TryGetValue(candidate.Name, out var messages))
                {
                    Reject(candidate, "native diagnostic", messages.ToArray());
                    continue;
                }
                if (variable == null)
                {
                    throw new InvalidOperationException($"Complex macro value probe for '{candidate.Name}' is missing.");
                }
                if (variable.Init == null)
                {
                    Reject(candidate, "no native initializer");
                    continue;
                }
                var type = variable.Init.Type.Handle.CanonicalType;
                if (type.kind == CXTypeKind.CXType_Enum)
                    type = clang.getEnumDeclIntegerType(clang.getTypeDeclaration(type)).CanonicalType;
                string storage = GetStorage(type);
                if (storage == null)
                {
                    Reject(candidate, type.kind == CXTypeKind.CXType_Pointer ? "pointer constant" : "not a supported integer type");
                    continue;
                }
                route.CompilerEvaluated = true;
                compilerEvaluations++;
                using var value = variable.Handle.Evaluate;
                if (value.Handle == IntPtr.Zero || value.Kind != CXEvalResultKind.CXEval_Int)
                {
                    Reject(candidate, "not a native integer constant");
                    continue;
                }
                string number = value.IsUnsignedInt
                    ? value.AsUnsigned.ToString(CultureInfo.InvariantCulture)
                    : value.AsLongLong.ToString(CultureInfo.InvariantCulture);
                string literal = storage switch
                {
                    "uint" => number + "U",
                    "long" => number + "L",
                    "ulong" => number + "UL",
                    "bool" => number == "0" ? "false" : "true",
                    "char" => SymbolDisplay.FormatLiteral((char)value.AsUnsigned, quote: true),
                    _ => number,
                };
                string name = configuration.RemappedNames.GetValueOrDefault(candidate.Name) ?? candidate.Name;
                result.Constants.Add(new NativeConstantValue(candidate.Name, name, owner.File, owner.Line,
                    variable.Init.Type.AsString, storage, literal)
                {
                    Column = owner.Column,
                    HeaderHash = HeaderHash(owner.File),
                    AliasTarget = ReadAliasTarget(variable.Init),
                    Evaluation = "Clang",
                });
            }
            timing?.SetCounter("candidateCount", candidates.Length);
            timing?.SetCounter("parseCount", 0);
            timing?.SetCounter("retrySplitCount", 0);
            timing?.SetCounter("errorDiagnosticCount", candidates.Sum(candidate =>
                (long)(probes.Errors.GetValueOrDefault(candidate.Name)?.Count ?? 0)));
            timing?.SetCounter("acceptedCount", result.Constants.Count);
            timing?.SetCounter("rejectedCount", result.Issues.Count);
            timing?.SetCounter("clangValueEvaluateCount", compilerEvaluations);
            timing?.SetCounter("scannerResolvedIntegerCount", scannerIntegers);
            return result;

            NativeConstantBinding ReadAliasTarget(Expr expression)
            {
                while (expression is ParenExpr or ImplicitCastExpr or ChooseExpr)
                {
                    if (expression is ChooseExpr choice)
                    {
                        // ClangSharp 21 exposes a null ChosenSubExpr for this builtin.
                        expression = choice.IsConditionTrue ? choice.LHS : choice.RHS;
                        continue;
                    }
                    var children = expression.CursorChildren.OfType<Expr>().ToArray();
                    if (children.Length != 1 || expression.Type.CanonicalType != children[0].Type.CanonicalType)
                        return null;
                    expression = children[0];
                }
                if (expression is not DeclRefExpr reference ||
                    reference.Handle.Referenced.Kind != CXCursorKind.CXCursor_EnumConstantDecl)
                    return null;
                return ReadEnumConstantBinding(reference.Handle.Referenced, HeaderHash);
            }

            string HeaderHash(string header)
            {
                if (!headerHashes.TryGetValue(header, out string hash))
                    headerHashes[header] = hash = NativeConstantGroupProvenance.HashFile(header);
                return hash;
            }

            void Reject(Candidate candidate, string reason, params string[] diagnostics) =>
                result.Issues.Add(new NativeConstantIssue(candidate.Name, candidate.Owner.File, reason, diagnostics));

            bool IsExcluded(string name) => exactExcludes.Contains(name) || wildcardExcludes.Any(pattern =>
                System.IO.Enumeration.FileSystemName.MatchesSimpleExpression(pattern, name, ignoreCase: false));
        }

        internal static NativeConstantBinding ReadEnumConstantBinding(CXCursor declaration, Func<string, string> headerHash)
        {
            var nativeType = clang.getCursorType(declaration);
            var storageType = nativeType.CanonicalType;
            if (storageType.kind == CXTypeKind.CXType_Enum)
                storageType = clang.getEnumDeclIntegerType(clang.getTypeDeclaration(storageType)).CanonicalType;
            string storage = GetStorage(storageType) ??
                throw new InvalidOperationException("Unsupported native enum alias storage.");
            bool unsigned = storage is "byte" or "ushort" or "uint" or "ulong" or "char";
            ulong unsignedValue = clang.getEnumConstantDeclUnsignedValue(declaration);
            string number = unsigned ? unsignedValue.ToString(CultureInfo.InvariantCulture) :
                clang.getEnumConstantDeclValue(declaration).ToString(CultureInfo.InvariantCulture);
            string literal = storage switch
            {
                "uint" => number + "U", "long" => number + "L", "ulong" => number + "UL",
                "bool" => number == "0" ? "false" : "true",
                "char" => SymbolDisplay.FormatLiteral((char)unsignedValue, quote: true),
                _ => number,
            };
            var location = GetLocation(declaration.Location);
            using var spelling = nativeType.Spelling;
            return new NativeConstantBinding("CXCursor_EnumConstantDecl",
                HeaderAnnotationProcessor.GetNativeTarget(declaration), location.File, location.Line, location.Column,
                headerHash(location.File), spelling.ToString(), storage, literal);
        }

        internal static string GetStorage(CXType type)
        {
            long size = type.SizeOf;
            if (size is < 1 or > 8)
                return null;
            return type.kind switch
            {
                CXTypeKind.CXType_Bool => "bool",
                CXTypeKind.CXType_Char_S or CXTypeKind.CXType_SChar => "sbyte",
                CXTypeKind.CXType_Char_U or CXTypeKind.CXType_UChar => "byte",
                CXTypeKind.CXType_Short => "short",
                CXTypeKind.CXType_UShort => "ushort",
                CXTypeKind.CXType_WChar or CXTypeKind.CXType_Char16 => size == 2 ? "char" : null,
                CXTypeKind.CXType_Int or CXTypeKind.CXType_Long => size == 4 ? "int" : size == 8 ? "long" : null,
                CXTypeKind.CXType_UInt or CXTypeKind.CXType_ULong => size == 4 ? "uint" : size == 8 ? "ulong" : null,
                CXTypeKind.CXType_LongLong => size == 8 ? "long" : null,
                CXTypeKind.CXType_ULongLong => size == 8 ? "ulong" : null,
                _ => null,
            };
        }

        internal static bool IsTraversed(string file, string source, IReadOnlyCollection<string> traversal) =>
            traversal.Count == 0 ? string.Equals(file, source, StringComparison.OrdinalIgnoreCase) :
            traversal.Any(path => string.Equals(Path.GetFullPath(path), Path.GetFullPath(file), StringComparison.OrdinalIgnoreCase) ||
                Path.GetFileName(path) == path && string.Equals(path, Path.GetFileName(file), StringComparison.OrdinalIgnoreCase));

        private static Location GetLocation(CXSourceLocation location)
        {
            location.GetFileLocation(out var file, out uint line, out uint column, out _);
            return new Location(file.ToString(), line, column);
        }

        private sealed record Location(string File, uint Line, uint Column);
        private sealed record Candidate(string Name, Location Owner);
    }
}
