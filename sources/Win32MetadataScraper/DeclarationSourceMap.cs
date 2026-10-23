using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text.Json;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis;

namespace Win32MetadataScraper
{
    internal static class DeclarationSourceMap
    {
        internal static unsafe void Write(CXCursor root, string sourceFile, string[] arguments, string outputPath,
            IReadOnlyCollection<string> symbols = null)
        {
            var declarations = new List<Declaration>();
            var files = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            var selected = symbols == null ? null : new HashSet<string>(symbols, StringComparer.Ordinal);
            var visited = selected == null ? null : new HashSet<CXCursor>();
            var kinds = new HashSet<CXCursorKind>
            {
                CXCursorKind.CXCursor_FunctionDecl, CXCursorKind.CXCursor_StructDecl, CXCursorKind.CXCursor_ClassDecl,
            };
            if (selected != null)
                kinds.UnionWith(new[]
                {
                    CXCursorKind.CXCursor_ParmDecl, CXCursorKind.CXCursor_FieldDecl,
                    CXCursorKind.CXCursor_TypedefDecl, CXCursorKind.CXCursor_EnumDecl, CXCursorKind.CXCursor_EnumConstantDecl,
                });
            Walk(root);
            Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(outputPath)));
            File.WriteAllText(outputPath, JsonSerializer.Serialize(new
            {
                schemaVersion = 1,
                translationUnit = Path.GetFullPath(sourceFile),
                partition = Path.GetFileName(Path.GetDirectoryName(Path.GetFullPath(sourceFile))),
                arguments,
                declarationKinds = kinds.Select(kind => kind.ToString()).OrderBy(kind => kind, StringComparer.Ordinal),
                selectedSymbols = symbols ?? Array.Empty<string>(),
                files,
                declarations = declarations.OrderBy(value => value.File, StringComparer.OrdinalIgnoreCase)
                    .ThenBy(value => value.Start).ThenBy(value => value.Id, StringComparer.Ordinal),
            }, new JsonSerializerOptions { WriteIndented = true, PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));

            bool IsSelected(CXCursor cursor)
            {
                if (selected == null)
                    return true;
                for (var current = cursor; !current.IsTranslationUnit && !current.Equals(default(CXCursor));
                    current = current.SemanticParent)
                {
                    using var name = current.Spelling;
                    if (selected.Contains(name.ToString()) || selected.Contains(QualifiedName(current)))
                        return true;
                }
                return false;
            }

            void Walk(CXCursor cursor, int? parameterIndex = null)
            {
                if (visited != null && !visited.Add(cursor))
                    return;
                if (kinds.Contains(cursor.Kind) && IsSelected(cursor))
                {
                    cursor.Location.GetExpansionLocation(out var file, out uint line, out uint column, out uint offset);
                    cursor.Location.GetSpellingLocation(out var spellingFile, out _, out _, out uint spellingOffset);
                    cursor.Extent.Start.GetExpansionLocation(out var startFile, out _, out _, out uint start);
                    cursor.Extent.End.GetExpansionLocation(out var endFile, out _, out _, out uint end);
                    string path = file.ToString();
                    if (path.Length != 0 && File.Exists(path))
                    {
                        if (!files.ContainsKey(path))
                            files.Add(path, Convert.ToHexString(SHA256.HashData(File.ReadAllBytes(path))));
                        using var spelling = cursor.Spelling;
                        using var identity = cursor.Usr;
                        using var type = cursor.Type.Spelling;
                        using var parentIdentity = cursor.SemanticParent.Usr;
                        using var typeIdentity = cursor.Type.CanonicalType.Declaration.Usr;
                        declarations.Add(new Declaration(
                            identity.ToString(), spelling.ToString(), QualifiedName(cursor),
                            cursor.Kind.ToString(), type.ToString(), path,
                            line, column, offset, start, end, cursor.IsDefinition,
                            spellingFile.ToString(), spellingOffset, startFile.ToString(), endFile.ToString(),
                            parentIdentity.ToString(), QualifiedName(cursor.SemanticParent), parameterIndex, typeIdentity.ToString()));
                    }
                }
                int nextParameter = 0;
                cursor.VisitChildren((child, parent, data) =>
                {
                    if (child.IsDeclaration || child.IsTranslationUnit)
                        Walk(child, child.Kind == CXCursorKind.CXCursor_ParmDecl ? nextParameter++ : null);
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
            }
        }

        internal static string QualifiedName(CXCursor cursor)
        {
            var names = new List<string>();
            for (var current = cursor; !current.IsTranslationUnit && !current.Equals(default(CXCursor));
                current = current.SemanticParent)
            {
                using var spelling = current.Spelling;
                string name = spelling.ToString();
                if (name.Length != 0)
                    names.Add(name);
            }
            names.Reverse();
            return string.Join("::", names);
        }

        internal static string ReadFilePath(SyntaxToken fileToken)
        {
            // ClangSharp 21 inconsistently escapes the final Windows path separator.
            return OperatingSystem.IsWindows()
                ? fileToken.Text[1..^1].Replace(@"\\", @"\", StringComparison.Ordinal)
                : fileToken.ValueText;
        }

        private sealed record Declaration(
            string Id, string Name, string QualifiedName, string Kind, string Type, string File, uint Line, uint Column, uint Offset,
            uint Start, uint End, bool IsDefinition, string SpellingFile, uint SpellingOffset,
            string StartFile, string EndFile, string ParentId, string ParentQualifiedName, int? ParameterIndex, string TypeDeclarationId);
    }
}
