using System;
using System.Collections.Generic;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal static class NativeHandleOrigins
    {
        internal static bool IsDeclareHandle(TypedefNameDecl alias, IEnumerable<Cursor> preprocessing)
        {
            if (alias.UnderlyingType.CanonicalType is not PointerType pointer ||
                pointer.PointeeType.CanonicalType is not RecordType record ||
                !(record.Decl.Definition ?? record.Decl).IsCompleteDefinition)
                return false;
            var visited = new HashSet<CXCursor>();
            for (var current = alias; current != null && visited.Add(current.Handle);)
            {
                if (current.Name == alias.Name && HasOrigin(current, record.Decl.Definition ?? record.Decl, preprocessing))
                    return true;
                current = RemapDiscovery.UnwrapType(current.UnderlyingType) is TypedefType type ? type.Decl : null;
            }
            return false;
        }

        private static bool HasOrigin(TypedefNameDecl alias, RecordDecl record, IEnumerable<Cursor> preprocessing)
        {
            alias.Location.GetExpansionLocation(out var file, out _, out _, out uint offset);
            record.Location.GetExpansionLocation(out var recordFile, out _, out _, out uint recordOffset);
            if (file.Equals(default(CXFile)) || !file.Equals(recordFile) || offset != recordOffset)
                return false;
            foreach (var cursor in preprocessing.Where(value => value.CursorKind == CXCursorKind.CXCursor_MacroExpansion))
            {
                cursor.Location.GetExpansionLocation(out var expansionFile, out _, out _, out uint expansionOffset);
                if (!file.Equals(expansionFile) || offset != expansionOffset)
                    continue;
                using var name = cursor.Handle.Spelling;
                var definition = cursor.Handle.Referenced;
                if (name.ToString() != "DECLARE_HANDLE" || definition.Kind != CXCursorKind.CXCursor_MacroDefinition ||
                    !definition.IsMacroFunctionLike)
                    continue;
                definition.Location.GetSpellingLocation(out var definitionFile, out _, out _, out _);
                if (definitionFile.Equals(default(CXFile)))
                    continue;
                var unit = alias.TranslationUnit.Handle;
                var tokens = unit.Tokenize(definition.Extent);
                try
                {
                    var text = tokens.ToArray().Where(token => token.Kind != CXTokenKind.CXToken_Comment).Select(token =>
                    {
                        using var spelling = token.GetSpelling(unit);
                        return spelling.ToString();
                    }).ToArray();
                    if (text.Length < 4 || text[0] != "DECLARE_HANDLE" || text[1] != "(" || text[3] != ")")
                        continue;
                    string parameter = text[2];
                    string body = string.Join(" ", text.Skip(4).Select(token => token == parameter ? "$name" : token));
                    if (body == "struct $name ## __ { int unused ; } ; typedef struct $name ## __ * $name")
                        return true;
                }
                finally
                {
                    unit.DisposeTokens(tokens);
                }
            }
            return false;
        }
    }
}
