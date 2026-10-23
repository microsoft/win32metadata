using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using ClangSharp;
using ClangSharp.Interop;
using MetadataUtils;
using Microsoft.CodeAnalysis.CSharp;

namespace Win32MetadataScraper
{
    internal static unsafe class NativeConstantExtractor
    {
        private const string ProbePrefix = "__Win32MetadataConstant_";
        private const int BatchSize = 512;

        internal static NativeConstantValues Extract(TranslationUnit original, string sourceFile,
            string[] arguments, PInvokeGeneratorConfiguration configuration, HashSet<string> reportedDiagnostics,
            IReadOnlyCollection<string> requestedNames = null)
        {
            var result = new NativeConstantValues
            {
                BindingSource = configuration.OutputLocation,
                Namespace = configuration.DefaultNamespace,
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
            var candidates = definitions.Where(value => !value.Macro.IsFunctionLike &&
                    (requested != null ? requested.Contains(value.Macro.Name) :
                        IsTraversed(value.Location.File, sourceFile, configuration.TraversalNames)) &&
                    !IsExcluded(value.Macro.Name))
                .GroupBy(value => value.Macro.Name, StringComparer.Ordinal)
                .Select(group => new Candidate(group.Key, group.First().Location))
                .OrderBy(value => value.Name, StringComparer.Ordinal).ToArray();
            if (requested != null)
                foreach (string name in requested.Except(candidates.Select(candidate => candidate.Name), StringComparer.Ordinal))
                    result.Issues.Add(new NativeConstantIssue(name, sourceFile,
                        IsExcluded(name) ? "excluded by configuration" : "no object-like macro definition", Array.Empty<string>()));
            string source = File.ReadAllText(sourceFile);
            string declaration = arguments.Contains("--language=c", StringComparer.Ordinal) ? "const __auto_type " : "constexpr auto ";
            using var index = CXIndex.Create();
            for (int offset = 0; offset < candidates.Length; offset += BatchSize)
                Evaluate(candidates.Skip(offset).Take(BatchSize).ToArray());
            return result;

            void Evaluate(Candidate[] batch)
            {
                var text = new StringBuilder(source).AppendLine().AppendLine();
                uint line = (uint)text.ToString().Count(character => character == '\n') + 1;
                var byLine = new Dictionary<uint, Candidate>();
                var byProbe = new Dictionary<string, Candidate>(StringComparer.Ordinal);
                for (int i = 0; i < batch.Length; i++)
                {
                    string probe = ProbePrefix + i.ToString(CultureInfo.InvariantCulture);
                    text.Append("#if defined(").Append(batch[i].Name).AppendLine(")");
                    byLine.Add(line + 1, batch[i]);
                    byProbe.Add(probe, batch[i]);
                    text.Append(declaration).Append(probe).Append(" = (").Append(batch[i].Name).AppendLine(");");
                    text.AppendLine("#endif");
                    line += 3;
                }
                using var unsaved = CXUnsavedFile.Create(sourceFile, text.ToString());
                var error = CXTranslationUnit.TryParse(index, sourceFile,
                    arguments.Concat(new[] { "-ferror-limit=0" }).ToArray(), new[] { unsaved },
                    CXTranslationUnit_Flags.CXTranslationUnit_DetailedPreprocessingRecord |
                    CXTranslationUnit_Flags.CXTranslationUnit_IncludeAttributedTypes |
                    CXTranslationUnit_Flags.CXTranslationUnit_VisitImplicitAttributes, out var handle);
                if (error != CXErrorCode.CXError_Success)
                    throw new InvalidOperationException($"Cannot parse native constant probes for '{sourceFile}': {error}.");
                using var unit = TranslationUnit.GetOrCreate(handle);
                var errors = new Dictionary<Candidate, List<string>>();
                var unassignedErrors = new List<string>();
                for (uint i = 0; i < handle.NumDiagnostics; i++)
                {
                    using var diagnostic = handle.GetDiagnostic(i);
                    using var formatted = diagnostic.Format(CXDiagnostic.DefaultDisplayOptions);
                    string message = formatted.ToString();
                    if (diagnostic.Severity is CXDiagnosticSeverity.CXDiagnostic_Error or CXDiagnosticSeverity.CXDiagnostic_Fatal)
                    {
                        var location = GetLocation(diagnostic.Location);
                        if (string.Equals(location.File, sourceFile, StringComparison.OrdinalIgnoreCase) &&
                            byLine.TryGetValue(location.Line, out var candidate))
                        {
                            if (!errors.TryGetValue(candidate, out var messages))
                                errors[candidate] = messages = new();
                            messages.Add(message);
                        }
                        else
                            unassignedErrors.Add(message);
                    }
                    else if (diagnostic.Severity == CXDiagnosticSeverity.CXDiagnostic_Warning && reportedDiagnostics.Add(message))
                        Console.WriteLine($"    {message}");
                }
                if (unassignedErrors.Count != 0)
                {
                    if (batch.Length > 1)
                    {
                        Evaluate(batch.Take(batch.Length / 2).ToArray());
                        Evaluate(batch.Skip(batch.Length / 2).ToArray());
                    }
                    else
                        Reject(batch[0], "native diagnostic", unassignedErrors.Concat(errors.Values.SelectMany(value => value)).ToArray());
                    return;
                }

                var activeDefinitions = new Dictionary<Candidate, Location>();
                _ = handle.Cursor.VisitChildren((cursor, _, _) =>
                {
                    if (cursor.Kind == CXCursorKind.CXCursor_MacroExpansion)
                    {
                        var location = GetLocation(cursor.Location);
                        using var spelling = cursor.Spelling;
                        if (byLine.TryGetValue(location.Line, out var candidate) && spelling.ToString() == candidate.Name &&
                            string.Equals(location.File, sourceFile, StringComparison.OrdinalIgnoreCase))
                            activeDefinitions[candidate] = GetLocation(clang.getCursorReferenced(cursor).Location);
                    }
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
                var variables = unit.TranslationUnitDecl.Decls.OfType<VarDecl>()
                    .Where(variable => byProbe.ContainsKey(variable.Name)).ToDictionary(variable => byProbe[variable.Name]);
                foreach (var candidate in batch)
                {
                    variables.TryGetValue(candidate, out var variable);
                    if (activeDefinitions.TryGetValue(candidate, out var owner) &&
                        requested == null && !IsTraversed(owner.File, sourceFile, configuration.TraversalNames))
                    {
                        Reject(candidate, "active definition is outside traversed headers");
                        continue;
                    }
                    if (variable?.Init?.Type.Handle.CanonicalType.kind == CXTypeKind.CXType_Pointer)
                    {
                        Reject(candidate, "pointer constant", errors.GetValueOrDefault(candidate)?.ToArray() ?? Array.Empty<string>());
                        continue;
                    }
                    if (errors.TryGetValue(candidate, out var messages))
                    {
                        Reject(candidate, "native diagnostic", messages.ToArray());
                        continue;
                    }
                    if (variable == null)
                    {
                        Reject(candidate, "undefined in the final header environment");
                        continue;
                    }
                    if (owner == null)
                    {
                        Reject(candidate, "active macro definition is not recorded by Clang");
                        continue;
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
                        variable.Init.Type.AsString, storage, literal));
                }
            }

            void Reject(Candidate candidate, string reason, params string[] diagnostics) =>
                result.Issues.Add(new NativeConstantIssue(candidate.Name, candidate.Owner.File, reason, diagnostics));

            bool IsExcluded(string name) => configuration.ExcludedNames.Any(pattern =>
                System.IO.Enumeration.FileSystemName.MatchesSimpleExpression(pattern, name, ignoreCase: false));
        }

        private static string GetStorage(CXType type)
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

        private static bool IsTraversed(string file, string source, IReadOnlyCollection<string> traversal) =>
            traversal.Count == 0 ? string.Equals(file, source, StringComparison.OrdinalIgnoreCase) :
            traversal.Any(path => string.Equals(Path.GetFullPath(path), Path.GetFullPath(file), StringComparison.OrdinalIgnoreCase) ||
                Path.GetFileName(path) == path && string.Equals(path, Path.GetFileName(file), StringComparison.OrdinalIgnoreCase));

        private static Location GetLocation(CXSourceLocation location)
        {
            location.GetFileLocation(out var file, out uint line, out _, out _);
            return new Location(file.ToString(), line);
        }

        private sealed record Location(string File, uint Line);
        private sealed record Candidate(string Name, Location Owner);
    }
}
