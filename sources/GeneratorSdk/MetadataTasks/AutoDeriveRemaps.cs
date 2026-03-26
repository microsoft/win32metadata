using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using Microsoft.Build.Framework;
using Microsoft.Build.Utilities;

namespace MetadataTasks
{
    /// <summary>
    /// MSBuild task that scans SDK header files to auto-derive:
    /// 1. Typedef-tag remaps (e.g., _FOO=FOO, tagBar=Bar, __MIDL_xxx=RealName)
    /// 2. Function pointer fixups (exclude, remap, reducePointerLevel)
    ///
    /// This replaces the manual entries in scraper.settings.rsp --remap,
    /// functionPointerFixups.json, and emitter.settings.rsp --reducePointerLevel.
    /// </summary>
    public class AutoDeriveRemaps : Task
    {
        [Required]
        public string SdkIncRoot { get; set; }

        public string AdditionalIncludes { get; set; }

        [Required]
        public string ScraperAutoRemapsRsp { get; set; }

        /// <summary>
        /// Semicolon-delimited list of RSP files whose --remap keys should be excluded
        /// from the auto-derived output (to avoid duplicate key errors in ClangSharp).
        /// </summary>
        public string ExcludeRemapKeysFromRsp { get; set; }

        /// <summary>
        /// Semicolon-delimited list of directories to scan for .rsp files whose --remap
        /// keys should also be excluded (e.g., partition settings directories).
        /// </summary>
        public string ExcludeRemapKeysFromDirs { get; set; }

        public override bool Execute()
        {
#if DEBUG
            if (Environment.GetEnvironmentVariable("DEBUG_AUTO_DERIVE_REMAPS_TASK") == "1")
            {
                System.Diagnostics.Debugger.Launch();
            }
#endif

            var headerDirs = new List<string>
            {
                Path.Combine(this.SdkIncRoot, "shared"),
                Path.Combine(this.SdkIncRoot, "um"),
                Path.Combine(this.SdkIncRoot, "ucrt"),
                Path.Combine(this.SdkIncRoot, "winrt"),
            };

            if (!string.IsNullOrEmpty(this.AdditionalIncludes))
            {
                foreach (var dir in this.AdditionalIncludes.Split(';', StringSplitOptions.RemoveEmptyEntries))
                {
                    if (Directory.Exists(dir) && !headerDirs.Contains(dir))
                    {
                        headerDirs.Add(dir);
                    }
                }
            }

            var headerFiles = headerDirs
                .Where(Directory.Exists)
                .SelectMany(d => Directory.EnumerateFiles(d, "*.h", SearchOption.AllDirectories))
                .ToList();

            this.Log.LogMessage(MessageImportance.High, $"AutoDeriveRemaps: Scanning {headerFiles.Count} header files...");

            // Data structures for collecting results
            var typedefTagRemaps = new Dictionary<string, string>(StringComparer.Ordinal);

            foreach (var file in headerFiles)
            {
                try
                {
                    ParseHeaderFile(file, typedefTagRemaps);
                }
                catch (Exception ex)
                {
                    this.Log.LogWarning($"AutoDeriveRemaps: Error parsing {file}: {ex.Message}");
                }
            }

            this.Log.LogMessage(MessageImportance.High,
                $"AutoDeriveRemaps: Found {typedefTagRemaps.Count} typedef-tag remaps");

            // Exclude remap keys that appear in other RSP files to avoid duplicates
            var excludedKeys = LoadExcludedRemapKeys();
            if (excludedKeys.Count > 0)
            {
                int beforeCount = typedefTagRemaps.Count;
                foreach (var key in excludedKeys)
                {
                    typedefTagRemaps.Remove(key);
                }

                this.Log.LogMessage(MessageImportance.High,
                    $"AutoDeriveRemaps: Excluded {beforeCount - typedefTagRemaps.Count} keys " +
                    $"already defined in other RSP files ({typedefTagRemaps.Count} remaining)");
            }

            // Write output RSP file
            WriteTypedefRemapsRsp(typedefTagRemaps);

            return true;
        }

        private void ParseHeaderFile(
            string filePath,
            Dictionary<string, string> typedefTagRemaps)
        {
            string content = File.ReadAllText(filePath);
            content = StripComments(content);

            int declCount = 0;
            int remapCount = 0;
            foreach (string decl in ExtractTypedefDeclarations(content))
            {
                declCount++;
                string normalized = NormalizeWhitespace(decl);

                if (TryParseStructEnumUnionTypedef(normalized, out string tagName, out string typedefName))
                {
                    if (!string.IsNullOrEmpty(tagName) && !string.IsNullOrEmpty(typedefName) && tagName != typedefName)
                    {
                        if (!typedefTagRemaps.ContainsKey(tagName))
                        {
                            typedefTagRemaps[tagName] = typedefName;
                            remapCount++;
                        }
                    }
                }
            }

            // Log files with many typedefs for diagnostic purposes
            if (declCount > 100)
            {
                this.Log.LogMessage(MessageImportance.Normal,
                    $"AutoDeriveRemaps: {Path.GetFileName(filePath)}: {declCount} declarations, {remapCount} remaps");
            }
        }

        /// <summary>
        /// Strips C-style comments (// and /* */) from the content.
        /// Handles string literals ("...") and character literals ('...') to avoid
        /// treating comment-like sequences inside them as actual comments.
        /// </summary>
        private static string StripComments(string content)
        {
            var sb = new StringBuilder(content.Length);
            int i = 0;
            while (i < content.Length)
            {
                if (i + 1 < content.Length && content[i] == '/' && content[i + 1] == '/')
                {
                    // Line comment — skip to end of line
                    while (i < content.Length && content[i] != '\n')
                        i++;
                }
                else if (i + 1 < content.Length && content[i] == '/' && content[i + 1] == '*')
                {
                    // Block comment — skip to */
                    i += 2;
                    while (i + 1 < content.Length && !(content[i] == '*' && content[i + 1] == '/'))
                        i++;
                    if (i + 1 < content.Length)
                        i += 2; // skip */
                }
                else if (content[i] == '\'')
                {
                    // Character literal — copy as-is to avoid '"' inside char literals
                    // confusing the string literal handler
                    sb.Append(content[i++]);
                    while (i < content.Length && content[i] != '\'')
                    {
                        if (content[i] == '\\' && i + 1 < content.Length)
                        {
                            sb.Append(content[i++]);
                        }
                        sb.Append(content[i++]);
                    }
                    if (i < content.Length)
                        sb.Append(content[i++]);
                }
                else if (content[i] == '"')
                {
                    // String literal — copy as-is, skip escaped chars
                    sb.Append(content[i++]);
                    while (i < content.Length && content[i] != '"')
                    {
                        if (content[i] == '\\' && i + 1 < content.Length)
                        {
                            sb.Append(content[i++]);
                        }
                        sb.Append(content[i++]);
                    }
                    if (i < content.Length)
                        sb.Append(content[i++]);
                }
                else
                {
                    sb.Append(content[i++]);
                }
            }

            return sb.ToString();
        }

        /// <summary>
        /// Extracts complete typedef declarations from comment-stripped content.
        /// A typedef starts with the "typedef" keyword and ends at ";" when
        /// brace/paren depth is zero.
        /// </summary>
        private static IEnumerable<string> ExtractTypedefDeclarations(string content)
        {
            var results = new List<string>();
            int i = 0;
            int len = content.Length;

            while (i < len)
            {
                int typedefStart = FindTypedefKeyword(content, i);
                if (typedefStart < 0)
                    break;

                // Collect characters until we hit ';' at depth 0
                int braceDepth = 0;
                int parenDepth = 0;
                int j = typedefStart + 7; // length of "typedef"

                while (j < len)
                {
                    char c = content[j];
                    if (c == '{') braceDepth++;
                    else if (c == '}') braceDepth--;
                    else if (c == '(') parenDepth++;
                    else if (c == ')') parenDepth--;
                    else if (c == ';' && braceDepth == 0 && parenDepth == 0)
                    {
                        results.Add(content.Substring(typedefStart, j - typedefStart + 1));
                        break;
                    }
                    // Handle preprocessor directives inside typedefs (skip to end of line)
                    else if (c == '#' && braceDepth > 0)
                    {
                        while (j < len && content[j] != '\n')
                            j++;
                    }
                    j++;
                }

                i = j + 1;
            }

            return results;
        }

        /// <summary>
        /// Finds the next "typedef" keyword that appears as a standalone word.
        /// Skips preprocessor lines (#define, #ifdef, etc.).
        /// </summary>
        private static int FindTypedefKeyword(string content, int startIndex)
        {
            int idx = startIndex;
            while (true)
            {
                idx = content.IndexOf("typedef", idx, StringComparison.Ordinal);
                if (idx < 0)
                    return -1;

                // Check that it's a word boundary (not part of a larger identifier)
                bool validStart = (idx == 0 || !char.IsLetterOrDigit(content[idx - 1]) && content[idx - 1] != '_');
                int endIdx = idx + 7;
                bool validEnd = (endIdx >= content.Length || !char.IsLetterOrDigit(content[endIdx]) && content[endIdx] != '_');

                if (validStart && validEnd)
                {
                    // Check we're not inside a preprocessor directive
                    // (scan backward to see if this line starts with #)
                    int lineStart = content.LastIndexOf('\n', Math.Max(0, idx - 1));
                    if (lineStart < 0) lineStart = 0;
                    string linePrefix = content.Substring(lineStart, idx - lineStart).TrimStart();
                    if (!linePrefix.StartsWith("#"))
                    {
                        return idx;
                    }
                }

                idx = endIdx;
            }
        }

        // Regex patterns for classification
        private static readonly Regex StructEnumUnionTypedefStart =
            new Regex(@"^typedef\s+(struct|enum|union)\s+(\w+)", RegexOptions.Compiled);

        /// <summary>
        /// Tries to parse a struct/enum/union typedef and extract tag→typedef name mapping.
        /// </summary>
        private static bool TryParseStructEnumUnionTypedef(string decl, out string tagName, out string typedefName)
        {
            tagName = null;
            typedefName = null;

            var startMatch = StructEnumUnionTypedefStart.Match(decl);
            if (!startMatch.Success)
                return false;

            tagName = startMatch.Groups[2].Value;

            // Find the closing brace and extract typedef names
            int closeBrace = decl.LastIndexOf('}');
            if (closeBrace < 0)
            {
                // Forward declaration: typedef struct TAG NAME;
                // Only generate a remap when the tag looks like an internal name
                // (has _ prefix, tag prefix, __MIDL prefix, or _tag suffix).
                // Forward declarations like "typedef struct GLUquadric GLUquadricObj;"
                // are backwards-compat aliases where the TAG is the preferred name.
                var forwardMatch = Regex.Match(decl,
                    @"^typedef\s+(?:struct|enum|union|class)\s+(\w+)\s+(\w+)\s*;$");
                if (forwardMatch.Success)
                {
                    tagName = forwardMatch.Groups[1].Value;
                    typedefName = forwardMatch.Groups[2].Value;
                    if (tagName == typedefName)
                        return false;
                    // Only remap if the tag name looks like an internal/prefixed name
                    return tagName.StartsWith("_") || tagName.StartsWith("tag") || tagName.StartsWith("__MIDL") || tagName.EndsWith("_tag");
                }
                return false;
            }

            // Extract typedef names after the closing brace
            string afterBrace = decl.Substring(closeBrace + 1).TrimEnd(';').Trim();
            if (string.IsNullOrEmpty(afterBrace))
                return false;

            // Parse comma-separated names, skipping pointer declarations
            // e.g., "FOO, *PFOO, FAR *LPFOO" → we want "FOO"
            foreach (string part in afterBrace.Split(','))
            {
                string name = part.Trim();
                // Skip pointer typedefs (contain *)
                if (name.Contains('*'))
                    continue;
                // Skip empty
                if (string.IsNullOrWhiteSpace(name))
                    continue;
                // Remove FAR/NEAR qualifiers
                name = name.Replace("FAR", "").Replace("NEAR", "").Trim();

                if (IsValidIdentifier(name))
                {
                    typedefName = name;
                    return true;
                }
            }

            return false;
        }

        #region Helpers

        /// <summary>
        /// Reads remap keys from the RSP files specified in ExcludeRemapKeysFromRsp.
        /// These keys are excluded from the auto-derived output to avoid duplicate
        /// key errors when multiple RSP files are combined.
        /// </summary>
        private HashSet<string> LoadExcludedRemapKeys()
        {
            var excluded = new HashSet<string>(StringComparer.Ordinal);

            // Collect RSP files to scan for exclusions
            var rspFiles = new List<string>();

            if (!string.IsNullOrEmpty(this.ExcludeRemapKeysFromRsp))
            {
                rspFiles.AddRange(this.ExcludeRemapKeysFromRsp.Split(';', StringSplitOptions.RemoveEmptyEntries));
            }

            if (!string.IsNullOrEmpty(this.ExcludeRemapKeysFromDirs))
            {
                foreach (var dir in this.ExcludeRemapKeysFromDirs.Split(';', StringSplitOptions.RemoveEmptyEntries))
                {
                    if (Directory.Exists(dir))
                    {
                        rspFiles.AddRange(Directory.EnumerateFiles(dir, "*.rsp", SearchOption.AllDirectories));
                    }
                }
            }

            foreach (var rspPath in rspFiles)
            {
                if (!File.Exists(rspPath))
                    continue;

                bool inRemap = false;
                foreach (var line in File.ReadLines(rspPath))
                {
                    if (line.StartsWith("--remap")) { inRemap = true; continue; }
                    if (line.StartsWith("--")) { inRemap = false; continue; }
                    if (inRemap && line.Contains('='))
                    {
                        string key = line.Split('=', 2)[0].Trim();
                        if (!string.IsNullOrEmpty(key))
                            excluded.Add(key);
                    }
                }
            }

            return excluded;
        }

        private void WriteTypedefRemapsRsp(Dictionary<string, string> remaps)
        {
            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperAutoRemapsRsp));
            using var writer = new StreamWriter(this.ScraperAutoRemapsRsp);
            if (remaps.Count > 0)
            {
                writer.WriteLine("--remap");
                foreach (var kvp in remaps.OrderBy(k => k.Key, StringComparer.OrdinalIgnoreCase))
                {
                    writer.WriteLine($"{kvp.Key}={kvp.Value}");
                }
            }

            this.Log.LogMessage(MessageImportance.High,
                $"AutoDeriveRemaps: Wrote {remaps.Count} typedef-tag remaps to {this.ScraperAutoRemapsRsp}");
        }

        private static string NormalizeWhitespace(string text)
        {
            // Collapse runs of whitespace (including newlines) to single spaces
            return Regex.Replace(text.Trim(), @"\s+", " ");
        }

        private static bool IsValidIdentifier(string name)
        {
            if (string.IsNullOrEmpty(name)) return false;
            if (!char.IsLetter(name[0]) && name[0] != '_') return false;
            return name.All(c => char.IsLetterOrDigit(c) || c == '_');
        }

        #endregion
    }
}
