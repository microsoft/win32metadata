using System;
using System.Linq;
using ClangSharp;
using ClangSharp.Interop;

namespace Win32MetadataScraper
{
    internal static class NativeMacroNames
    {
        internal static string GetWrittenName(NamedDecl declaration, bool requireRecordedExpansion = false)
            => GetWrittenName(declaration, requireRecordedExpansion, useMemberArgument: false);

        internal static string GetWrittenMemberName(NamedDecl declaration)
            => GetWrittenName(declaration, requireRecordedExpansion: false,
                useMemberArgument: declaration is CXXMethodDecl or FieldDecl);

        private static string GetWrittenName(NamedDecl declaration, bool requireRecordedExpansion, bool useMemberArgument)
        {
            var unit = declaration.TranslationUnit.Handle;
            CXFile file;
            uint offset;
            if (useMemberArgument)
                declaration.Location.GetFileLocation(out file, out _, out _, out offset);
            else
                declaration.Location.GetExpansionLocation(out file, out _, out _, out offset);
            declaration.Location.GetSpellingLocation(out var spellingFile, out _, out _, out uint spellingOffset);
            if (file.Equals(default(CXFile)) || spellingFile.Equals(default(CXFile)) ||
                file.Equals(spellingFile) && offset == spellingOffset)
                return null;

            var expansion = unit.GetCursor(unit.GetLocationForOffset(file, offset));
            if (requireRecordedExpansion)
            {
                if (expansion.Kind != CXCursorKind.CXCursor_MacroExpansion)
                    return null;
                var definition = expansion.Referenced;
                if (definition.Kind != CXCursorKind.CXCursor_MacroDefinition || definition.IsMacroFunctionLike)
                    return null;
                var tokens = unit.Tokenize(definition.Extent);
                try
                {
                    using var expanded = expansion.Spelling;
                    return Validate(tokens, expanded.ToString());
                }
                finally
                {
                    unit.DisposeTokens(tokens);
                }
            }

            var contents = unit.GetFileContents(spellingFile, out _);
            if (spellingOffset >= contents.Length)
                return null;
            int start = checked((int)spellingOffset);
            int end = start;
            while (start > 0 && contents[start - 1] != '\n')
                start--;
            while (end < contents.Length && contents[end] != '\n')
                end++;
            var directive = unit.Tokenize(CXSourceRange.Create(unit.GetLocationForOffset(spellingFile, (uint)start),
                unit.GetLocationForOffset(spellingFile, (uint)end)));
            try
            {
                var tokens = directive.ToArray().Where(token =>
                {
                    token.GetLocation(unit).GetSpellingLocation(out var tokenFile, out _, out _, out uint tokenOffset);
                    return tokenFile.Equals(spellingFile) && tokenOffset >= start && tokenOffset < end &&
                        token.Kind != CXTokenKind.CXToken_Comment;
                }).ToArray();
                if (tokens.Length != 4 || TokenText(tokens[0]) != "#" || TokenText(tokens[1]) != "define")
                    return null;
                string written = TokenText(tokens[2]);
                var sourceTokens = unit.Tokenize(CXSourceRange.Create(unit.GetLocationForOffset(file, offset),
                    unit.GetLocationForOffset(file, checked(offset + (uint)written.Length))));
                try
                {
                    return sourceTokens.Length != 0 && TokenText(sourceTokens[0]) == written
                        ? Validate(tokens.AsSpan(2), written) : null;
                }
                finally
                {
                    unit.DisposeTokens(sourceTokens);
                }
            }
            finally
            {
                unit.DisposeTokens(directive);
            }

            string Validate(ReadOnlySpan<CXToken> source, string expanded)
            {
                var identifiers = source.ToArray().Where(token => token.Kind != CXTokenKind.CXToken_Comment).ToArray();
                if (identifiers.Length != 2 || identifiers.Any(token => token.Kind != CXTokenKind.CXToken_Identifier))
                    return null;
                identifiers[1].GetLocation(unit).GetSpellingLocation(out var replacementFile, out _, out _, out uint replacementOffset);
                string written = TokenText(identifiers[0]);
                return spellingFile.Equals(replacementFile) && spellingOffset == replacementOffset &&
                    written == expanded && written != declaration.Name && TokenText(identifiers[1]) == declaration.Name
                    ? written : null;
            }

            string TokenText(CXToken token)
            {
                using var spelling = token.GetSpelling(unit);
                return spelling.ToString();
            }
        }
    }
}
