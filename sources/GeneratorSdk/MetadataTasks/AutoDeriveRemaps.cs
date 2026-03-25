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

        [Required]
        public string ScraperAutoFuncPtrRsp { get; set; }

        [Required]
        public string EmitterAutoFuncPtrRsp { get; set; }

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
            var funcTypedefs = new Dictionary<string, FuncTypeInfo>(StringComparer.Ordinal);
            var simpleTypedefs = new List<SimpleTypedef>();

            foreach (var file in headerFiles)
            {
                try
                {
                    ParseHeaderFile(file, typedefTagRemaps, funcTypedefs, simpleTypedefs);
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

            // Write output RSP files
            WriteTypedefRemapsRsp(typedefTagRemaps);

            // Write empty function pointer RSP files — func ptr auto-derivation is
            // not yet enabled (too many false positives). The existing JSON-based
            // PrepSettingsForFunctionPointerFixups handles these.
            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperAutoFuncPtrRsp));
            File.WriteAllText(this.ScraperAutoFuncPtrRsp, string.Empty);
            Directory.CreateDirectory(Path.GetDirectoryName(this.EmitterAutoFuncPtrRsp));
            File.WriteAllText(this.EmitterAutoFuncPtrRsp, string.Empty);

            return true;
        }

        private void ParseHeaderFile(
            string filePath,
            Dictionary<string, string> typedefTagRemaps,
            Dictionary<string, FuncTypeInfo> funcTypedefs,
            List<SimpleTypedef> simpleTypedefs)
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
                        // Only add if not already present (first definition wins)
                        if (!typedefTagRemaps.ContainsKey(tagName))
                        {
                            typedefTagRemaps[tagName] = typedefName;
                            remapCount++;
                        }
                    }
                }
                else if (TryParseFunctionTypedef(normalized, out string funcName, out bool isPointer))
                {
                    if (!funcTypedefs.ContainsKey(funcName))
                    {
                        funcTypedefs[funcName] = new FuncTypeInfo { Name = funcName, IsPointer = isPointer };
                    }
                }
                else if (TryParseSimpleTypedef(normalized, out string srcType, out string destName, out bool addsPointer))
                {
                    simpleTypedefs.Add(new SimpleTypedef
                    {
                        SourceType = srcType,
                        DestName = destName,
                        AddsPointer = addsPointer
                    });
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

        // Matches the closing of a struct/enum/union typedef: } NAME [, *NAME2 ...] ;
        private static readonly Regex StructTypedefEnd =
            new Regex(@"\}\s*([\w\s,*]+);$", RegexOptions.Compiled);

        // Function typedef patterns:
        // Pattern 1: typedef RETURN (CALLCONV [*]NAME)(PARAMS);
        private static readonly Regex FuncTypedefWrapped =
            new Regex(@"typedef\s+.+?\(\s*(?:\w+\s+)?\*?\s*(\w+)\s*\)\s*\(", RegexOptions.Compiled | RegexOptions.Singleline);

        // Pattern 2: typedef RETURN [CALLCONV] NAME(PARAMS);  (bare name, multiline OK)
        // Matches name followed by ( that contains at least one parameter-like thing
        private static readonly Regex FuncTypedefBare =
            new Regex(@"typedef\s+(?!struct\b|enum\b|union\b)\S+.*?(\w+)\s*\([^)]*(?:void|int|char|UINT|DWORD|ULONG|LPVOID|HANDLE|PVOID|LPARAM|UUID|BOOL|SECURITY_STATUS|NTSTATUS|HRESULT|SIZE_T|LPBYTE|BYTE|WORD|LPCSTR|LPCWSTR|LPSTR|LPWSTR|LONG|WCHAR)", RegexOptions.Compiled | RegexOptions.Singleline);

        // Simple typedef: typedef A [FAR] [*] B ;
        private static readonly Regex SimpleTypedefPattern =
            new Regex(@"^typedef\s+(\w+)\s+(?:FAR\s+)?(\*?\s*)(\w+)\s*;$", RegexOptions.Compiled);

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
                // Pattern: typedef struct _FOO FOO;
                var forwardMatch = Regex.Match(decl,
                    @"^typedef\s+(?:struct|enum|union)\s+(\w+)\s+(\w+)\s*;$");
                if (forwardMatch.Success)
                {
                    tagName = forwardMatch.Groups[1].Value;
                    typedefName = forwardMatch.Groups[2].Value;
                    return tagName != typedefName;
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

        /// <summary>
        /// Tries to parse a function typedef declaration.
        /// Returns the function name and whether it's already a pointer type.
        /// </summary>
        private static bool TryParseFunctionTypedef(string decl, out string funcName, out bool isPointer)
        {
            funcName = null;
            isPointer = false;

            // Skip struct/enum/union typedefs
            if (StructEnumUnionTypedefStart.IsMatch(decl))
                return false;

            // Check for the wrapped pattern: typedef RETURN (CALLCONV [*]NAME)(PARAMS)
            // This covers: typedef void (CALLBACK TIMECALLBACK)(UINT, UINT, ...);
            //              typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID);
            //              typedef NTSTATUS (NTAPI SpInitializeFn)(...);
            var wrappedMatch = FuncTypedefWrapped.Match(decl);
            if (wrappedMatch.Success)
            {
                // Verify there's a second paren group (the parameter list)
                int firstParenClose = FindMatchingClose(decl, decl.IndexOf('(', 7));
                if (firstParenClose >= 0 && firstParenClose < decl.Length - 2)
                {
                    int nextParen = decl.IndexOf('(', firstParenClose + 1);
                    if (nextParen >= 0)
                    {
                        funcName = wrappedMatch.Groups[1].Value;

                        // Check if there's a * before the name in the first paren group
                        int firstParen = decl.IndexOf('(', 7);
                        int nameStart = decl.IndexOf(funcName, firstParen + 1);
                        if (nameStart > firstParen + 1)
                        {
                            int len = nameStart - firstParen - 1;
                            if (len > 0)
                            {
                                string beforeName = decl.Substring(firstParen + 1, len);
                                isPointer = beforeName.Contains('*');
                            }
                        }

                        return IsValidIdentifier(funcName);
                    }
                }
            }

            // Check for the bare pattern: typedef RETURN [CALLCONV] NAME(PARAMS);
            // This covers: typedef void __RPC_USER RPC_OBJECT_INQ_FN(PARAMS);
            //              typedef int32_t U_CALLCONV UCharIteratorGetIndex(...);
            // Must have parameters and NOT be a struct typedef
            if (!decl.Contains('{'))
            {
                // Find the last identifier before a top-level '(' that's followed by params
                int topParenStart = FindTopLevelParenStart(decl, 7);
                if (topParenStart > 0)
                {
                    // Check if this paren group contains parameter-like content
                    int parenEnd = FindMatchingClose(decl, topParenStart);
                    if (parenEnd > topParenStart + 1)
                    {
                        string parenContent = decl.Substring(topParenStart + 1, parenEnd - topParenStart - 1);
                        if (LooksLikeParameterList(parenContent))
                        {
                            // Extract the name before this paren
                            string beforeParen = decl.Substring(7, topParenStart - 7).TrimEnd();
                            var nameMatch = Regex.Match(beforeParen, @"(\w+)\s*$");
                            if (nameMatch.Success)
                            {
                                funcName = nameMatch.Groups[1].Value;

                                // Exclude common keywords that aren't function names
                                if (!IsCallingConvention(funcName) && !IsTypeKeyword(funcName) && IsValidIdentifier(funcName))
                                {
                                    isPointer = false;
                                    return true;
                                }
                            }
                        }
                    }
                }
            }

            return false;
        }

        /// <summary>
        /// Tries to parse a simple typedef: typedef A [FAR] [*] B;
        /// Used to find function pointer aliases.
        /// </summary>
        private static bool TryParseSimpleTypedef(string decl, out string srcType, out string destName, out bool addsPointer)
        {
            srcType = null;
            destName = null;
            addsPointer = false;

            // Skip struct/enum/union, function typedefs (those with inner braces or multiple paren groups)
            if (decl.Contains('{') || StructEnumUnionTypedefStart.IsMatch(decl))
                return false;

            // Count top-level paren groups — function typedefs have 2+
            int parenGroups = CountTopLevelParenGroups(decl);
            if (parenGroups >= 2)
                return false;

            // Simple pattern: typedef SRCTYPE [FAR|__RPC_FAR] [*] DESTNAME;
            var match = Regex.Match(decl,
                @"^typedef\s+(\w+)\s+(?:(?:FAR|__RPC_FAR|NEAR|WINAPI|CONST|const)\s+)*(\*?)\s*(\w+)\s*;$");

            if (match.Success)
            {
                srcType = match.Groups[1].Value;
                addsPointer = match.Groups[2].Value.Contains('*');
                destName = match.Groups[3].Value;
                return IsValidIdentifier(srcType) && IsValidIdentifier(destName) && srcType != destName;
            }

            return false;
        }

        /// <summary>
        /// After collecting all function typedefs and simple typedefs,
        /// match them up to produce function pointer fixup entries.
        /// </summary>
        private List<FunctionPointerFixup> MatchFunctionPointerChains(
            Dictionary<string, FuncTypeInfo> funcTypedefs,
            List<SimpleTypedef> simpleTypedefs)
        {
            var fixups = new List<FunctionPointerFixup>();
            var matched = new HashSet<string>(StringComparer.Ordinal);

            // For each simple typedef, check if it references a known function typedef
            foreach (var simple in simpleTypedefs)
            {
                if (funcTypedefs.TryGetValue(simple.SourceType, out var funcInfo))
                {
                    bool alreadyPointer = funcInfo.IsPointer;
                    bool needsReducePointerLevel = !alreadyPointer && simple.AddsPointer;

                    fixups.Add(new FunctionPointerFixup
                    {
                        PrototypeName = funcInfo.Name,
                        PointerTypeName = simple.DestName,
                        AlreadyPointer = alreadyPointer,
                        NeedsReducePointerLevel = needsReducePointerLevel
                    });

                    matched.Add(funcInfo.Name);
                }
            }

            // Function typedefs without a matching pointer typedef (Pattern 3)
            // These are used as *name in struct fields and need reducePointerLevel
            foreach (var funcInfo in funcTypedefs.Values)
            {
                if (!matched.Contains(funcInfo.Name) && !funcInfo.IsPointer)
                {
                    fixups.Add(new FunctionPointerFixup
                    {
                        PrototypeName = funcInfo.Name,
                        PointerTypeName = null,
                        AlreadyPointer = false,
                        NeedsReducePointerLevel = true
                    });
                }
            }

            return fixups;
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

        private void WriteFunctionPointerFixupsRsp(List<FunctionPointerFixup> fixups)
        {
            // Scraper RSP: --exclude and --remap for function pointer chains
            Directory.CreateDirectory(Path.GetDirectoryName(this.ScraperAutoFuncPtrRsp));
            using (var scraperWriter = new StreamWriter(this.ScraperAutoFuncPtrRsp))
            {
                var excludes = fixups.Where(f => f.PointerTypeName != null).Select(f => f.PointerTypeName).ToList();
                var remapEntries = fixups.Where(f => f.PointerTypeName != null)
                    .Select(f => $"{f.PrototypeName}={f.PointerTypeName}").ToList();

                if (excludes.Count > 0)
                {
                    scraperWriter.WriteLine("--exclude");
                    foreach (var exclude in excludes.OrderBy(s => s, StringComparer.OrdinalIgnoreCase))
                    {
                        scraperWriter.WriteLine(exclude);
                    }
                }

                if (remapEntries.Count > 0)
                {
                    scraperWriter.WriteLine("--remap");
                    foreach (var remap in remapEntries.OrderBy(s => s, StringComparer.OrdinalIgnoreCase))
                    {
                        scraperWriter.WriteLine(remap);
                    }
                }
            }

            // Emitter RSP: --reducePointerLevel for non-pointer function typedefs
            Directory.CreateDirectory(Path.GetDirectoryName(this.EmitterAutoFuncPtrRsp));
            using (var emitterWriter = new StreamWriter(this.EmitterAutoFuncPtrRsp))
            {
                var reduceEntries = fixups.Where(f => f.NeedsReducePointerLevel)
                    .Select(f => f.PointerTypeName ?? f.PrototypeName).ToList();

                if (reduceEntries.Count > 0)
                {
                    emitterWriter.WriteLine("--reducePointerLevel");
                    foreach (var entry in reduceEntries.OrderBy(s => s, StringComparer.OrdinalIgnoreCase))
                    {
                        emitterWriter.WriteLine(entry);
                    }
                }
            }

            int chainCount = fixups.Count(f => f.PointerTypeName != null);
            int reduceOnlyCount = fixups.Count(f => f.PointerTypeName == null);
            this.Log.LogMessage(MessageImportance.High,
                $"AutoDeriveRemaps: Wrote {chainCount} function pointer chains + {reduceOnlyCount} reduce-only entries");
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

        private static readonly HashSet<string> CallingConventions = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
        {
            "CALLBACK", "WINAPI", "NTAPI", "APIENTRY", "APIPRIVATE", "PASCAL",
            "__stdcall", "__cdecl", "__fastcall", "__thiscall", "__clrcall",
            "WINAPIV", "FAR", "NEAR", "__RPC_USER", "__RPC_STUB",
            "RPC_ENTRY", "RPCRTAPI", "U_CALLCONV", "DIAMONDAPI",
            "NET_API_FUNCTION", "WSPAPI", "WSAAPI", "EXPENTRY",
            "DECLSPEC_IMPORT", "VFWAPIV", "VFWAPI", "ACMAPI",
            "STDAPICALLTYPE", "STDAPIVCALLTYPE",
        };

        private static bool IsCallingConvention(string name)
        {
            return CallingConventions.Contains(name);
        }

        private static readonly HashSet<string> TypeKeywords = new HashSet<string>(StringComparer.Ordinal)
        {
            "void", "int", "char", "short", "long", "float", "double", "unsigned", "signed",
            "const", "volatile", "static", "extern", "inline", "register",
            "struct", "enum", "union", "typedef",
        };

        private static bool IsTypeKeyword(string name)
        {
            return TypeKeywords.Contains(name);
        }

        /// <summary>
        /// Finds the index of the matching closing paren/brace for the one at startIndex.
        /// </summary>
        private static int FindMatchingClose(string content, int startIndex)
        {
            if (startIndex < 0 || startIndex >= content.Length) return -1;
            char open = content[startIndex];
            char close = open == '(' ? ')' : open == '{' ? '}' : open == '[' ? ']' : '\0';
            if (close == '\0') return -1;

            int depth = 1;
            for (int i = startIndex + 1; i < content.Length; i++)
            {
                if (content[i] == open) depth++;
                else if (content[i] == close)
                {
                    depth--;
                    if (depth == 0) return i;
                }
            }
            return -1;
        }

        /// <summary>
        /// Finds the start of the first top-level parenthesized group after startIndex.
        /// Skips parenthesized groups that are inside other groups.
        /// </summary>
        private static int FindTopLevelParenStart(string content, int startIndex)
        {
            int depth = 0;
            for (int i = startIndex; i < content.Length; i++)
            {
                if (content[i] == '{') depth++;
                else if (content[i] == '}') depth--;
                else if (content[i] == '(' && depth == 0) return i;
            }
            return -1;
        }

        /// <summary>
        /// Counts the number of top-level parenthesized groups in a declaration.
        /// </summary>
        private static int CountTopLevelParenGroups(string decl)
        {
            int count = 0;
            int depth = 0;
            int braceDepth = 0;
            for (int i = 0; i < decl.Length; i++)
            {
                if (decl[i] == '{') braceDepth++;
                else if (decl[i] == '}') braceDepth--;
                else if (braceDepth == 0)
                {
                    if (decl[i] == '(' && depth == 0) count++;
                    if (decl[i] == '(') depth++;
                    else if (decl[i] == ')') depth--;
                }
            }
            return count;
        }

        /// <summary>
        /// Heuristic check: does this string look like a C function parameter list?
        /// This is intentionally permissive — any content that has identifier-like
        /// tokens (suggesting type names and parameter names) is considered a parameter list.
        /// </summary>
        private static bool LooksLikeParameterList(string content)
        {
            if (string.IsNullOrWhiteSpace(content))
                return false;

            string trimmed = content.Trim();

            // "void" alone is a parameter list for no-arg functions
            if (trimmed == "void")
                return true;

            // Contains commas (multiple params)
            if (trimmed.Contains(','))
                return true;

            // Contains at least one identifier-like word (type or parameter name).
            // Exclude bare numbers and simple expressions.
            if (Regex.IsMatch(trimmed, @"\b[A-Z_]\w{2,}\b"))
                return true;

            // Contains pointer syntax (* or []) which suggests typed parameters
            if (trimmed.Contains('*') || trimmed.Contains('['))
                return true;

            return false;
        }

        #endregion

        #region Data classes

        private class FuncTypeInfo
        {
            public string Name { get; set; }
            public bool IsPointer { get; set; }
        }

        private class SimpleTypedef
        {
            public string SourceType { get; set; }
            public string DestName { get; set; }
            public bool AddsPointer { get; set; }
        }

        private class FunctionPointerFixup
        {
            public string PrototypeName { get; set; }
            public string PointerTypeName { get; set; }
            public bool AlreadyPointer { get; set; }
            public bool NeedsReducePointerLevel { get; set; }
        }

        #endregion
    }
}
