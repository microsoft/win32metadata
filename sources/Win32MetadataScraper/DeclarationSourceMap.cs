using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Security.Cryptography;
using System.Text.Json;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal static class DeclarationSourceMap
    {
        internal static unsafe void Write(CXCursor root, string sourceFile, string[] arguments, string outputPath)
        {
            var declarations = new List<Declaration>();
            var files = new Dictionary<string, string>(StringComparer.OrdinalIgnoreCase);
            Walk(root);
            Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(outputPath)));
            File.WriteAllText(outputPath, JsonSerializer.Serialize(new
            {
                schemaVersion = 1,
                translationUnit = Path.GetFullPath(sourceFile),
                partition = Path.GetFileName(Path.GetDirectoryName(Path.GetFullPath(sourceFile))),
                arguments,
                declarationKinds = new[] { "CXCursor_FunctionDecl", "CXCursor_StructDecl", "CXCursor_ClassDecl" },
                files,
                declarations = declarations.OrderBy(value => value.File, StringComparer.OrdinalIgnoreCase)
                    .ThenBy(value => value.Start).ThenBy(value => value.Id, StringComparer.Ordinal),
            }, new JsonSerializerOptions { WriteIndented = true, PropertyNamingPolicy = JsonNamingPolicy.CamelCase }));

            void Walk(CXCursor cursor)
            {
                if (cursor.Kind is CXCursorKind.CXCursor_FunctionDecl or CXCursorKind.CXCursor_StructDecl or CXCursorKind.CXCursor_ClassDecl)
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
                        declarations.Add(new Declaration(
                            identity.ToString(), spelling.ToString(), QualifiedName(cursor),
                            cursor.Kind.ToString(), type.ToString(), path,
                            line, column, offset, start, end, cursor.IsDefinition,
                            spellingFile.ToString(), spellingOffset, startFile.ToString(), endFile.ToString()));
                    }
                }
                cursor.VisitChildren((child, parent, data) =>
                {
                    if (child.IsDeclaration || child.IsTranslationUnit)
                        Walk(child);
                    return CXChildVisitResult.CXChildVisit_Continue;
                }, default);
            }
        }

        private static string QualifiedName(CXCursor cursor)
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

        private sealed record Declaration(
            string Id, string Name, string QualifiedName, string Kind, string Type, string File, uint Line, uint Column, uint Offset,
            uint Start, uint End, bool IsDefinition, string SpellingFile, uint SpellingOffset,
            string StartFile, string EndFile);
    }
}
