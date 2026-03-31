// Win32MetadataScraper: Single-pass scraper that wraps ClangSharp PInvokeGenerator.
//
// Hosts PInvokeGenerator as a library (via NuGet package references). Parses the
// translation unit, walks the AST to discover typedef-tag remappings, merges them
// with the configured --remap entries, then runs PInvokeGenerator.GenerateBindings
// with the full merged remap set — all in a single parse pass.
//
// Usage: dotnet Win32MetadataScraper.dll <nativeLibDir> <remapsOutputPath> [--remap-exclusions <file>] @rsp1 @rsp2 ...

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using ClangSharp;
using ClangSharp.Interop;
using static ClangSharp.Interop.CXDiagnosticSeverity;
using static ClangSharp.Interop.CXErrorCode;
using static ClangSharp.Interop.CXTranslationUnit_Flags;

class Program
{
    static int Main(string[] args)
    {
        if (args.Length < 3)
        {
            Console.Error.WriteLine("Usage: dotnet Win32MetadataScraper.dll <nativeLibDir> <remapsOutputPath> @rsp1 @rsp2 ...");
            return 1;
        }

        // Pre-load native libraries from the specified directory (the ClangSharp tool store)
        string nativeLibDir = args[0];
        string remapsOutputPath = args[1];

        NativeLibrary.Load(Path.Combine(nativeLibDir, "libclang.dll"));
        NativeLibrary.Load(Path.Combine(nativeLibDir, "libClangSharp.dll"));

        string[] rspArgs = args.Skip(2).ToArray();

        try
        {
            // Parse RSP files
            var settings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
            foreach (var arg in rspArgs)
            {
                string rspPath = arg.StartsWith("@") ? arg.Substring(1).Trim('"') : arg;
                ParseRspFile(rspPath, settings);
            }

            string sourceFile = settings.GetValueOrDefault("--file")?.LastOrDefault();
            string outputFile = settings.GetValueOrDefault("--output")?.LastOrDefault();
            string ns = settings.GetValueOrDefault("--namespace")?.LastOrDefault();
            string headerFile = settings.GetValueOrDefault("--headerFile")?.LastOrDefault();

            if (sourceFile == null || outputFile == null || ns == null)
            {
                Console.Error.WriteLine("Error: Missing required --file, --output, or --namespace in RSP files");
                return 1;
            }

            var clangArgs = BuildClangArgs(settings);
            var configOptions = BuildOptionsFlags(settings);
            var configuredRemaps = ParseKeyValuePairs(settings.GetValueOrDefault("--remap"));

            var translationFlags = CXTranslationUnit_IncludeAttributedTypes
                                 | CXTranslationUnit_VisitImplicitAttributes;

            // ── Parse translation unit ──
            // We parse once with our own CXIndex, walk the AST to discover remaps,
            // then pass the same TranslationUnit to PInvokeGenerator.GenerateBindings.
            using var index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
            var parseError = CXTranslationUnit.TryParse(
                index, sourceFile, clangArgs, ReadOnlySpan<CXUnsavedFile>.Empty,
                translationFlags, out var cxHandle);

            if (parseError != CXError_Success)
            {
                Console.Error.WriteLine($"Error: Failed to parse '{sourceFile}': {parseError}");
                return -1;
            }

            bool skipProcessing = false;
            if (cxHandle.NumDiagnostics != 0)
            {
                Console.WriteLine($"Diagnostics for '{sourceFile}':");
                for (uint i = 0; i < cxHandle.NumDiagnostics; i++)
                {
                    using var diag = cxHandle.GetDiagnostic(i);
                    Console.Write("    ");
                    Console.WriteLine(diag.Format(CXDiagnostic.DefaultDisplayOptions).ToString());
                    skipProcessing |= diag.Severity == CXDiagnostic_Error;
                    skipProcessing |= diag.Severity == CXDiagnostic_Fatal;
                }
            }

            if (skipProcessing)
            {
                Console.Error.WriteLine($"Skipping '{sourceFile}' due to one or more errors listed above.");
                return -1;
            }

            using var translationUnit = TranslationUnit.GetOrCreate(cxHandle);
            Debug.Assert(translationUnit is not null);

            // ── Walk AST to discover all typedef-tag and function pointer relationships ──
            var tagToTypedefs = new Dictionary<string, List<string>>();
            var fnProtoToPointerTypedefs = new Dictionary<string, List<string>>();
            var fnProtoTypedefNames = new HashSet<string>();
            WalkForTypedefRemaps(translationUnit.TranslationUnitDecl, tagToTypedefs, fnProtoToPointerTypedefs, fnProtoTypedefNames);

            // Resolve tag remaps using disambiguation (no exclusion list needed)
            var resolvedTagRemaps = ResolveTagRemaps(tagToTypedefs, configuredRemaps);
            var autoRemaps = FilterRemaps(resolvedTagRemaps, configuredRemaps);

            // Resolve function pointer fixups
            var fnPtrRemaps = new Dictionary<string, string>();
            var fnPtrExcludes = new HashSet<string>();
            var reducePointerLevel = new HashSet<string>();
            ResolveFunctionPointerFixups(fnProtoTypedefNames, fnProtoToPointerTypedefs, fnPtrRemaps, fnPtrExcludes, reducePointerLevel);

            // Merge all remaps: auto tag remaps + fn ptr remaps + configured (configured wins)
            var mergedRemaps = new Dictionary<string, string>(autoRemaps);
            foreach (var kv in fnPtrRemaps)
                mergedRemaps[kv.Key] = kv.Value;
            foreach (var kv in configuredRemaps)
                mergedRemaps[kv.Key] = kv.Value;

            // Merge excludes from function pointer fixups into the configured excludes
            var allExcludes = new List<string>(settings.GetValueOrDefault("--exclude") ?? new List<string>());
            foreach (var excl in fnPtrExcludes)
            {
                if (!allExcludes.Contains(excl))
                    allExcludes.Add(excl);
            }

            // ── Run PInvokeGenerator with merged remaps on the same TranslationUnit ──
            var config = CreateConfig(settings, ns, outputFile, headerFile, configOptions, mergedRemaps, allExcludes);

            var capturedStreams = new Dictionary<string, MemoryStream>();
            Func<string, Stream> streamFactory = (path) =>
            {
                var ms = new MemoryStream();
                capturedStreams[path] = ms;
                return ms;
            };

            int exitCode = 0;
            using (var generator = new PInvokeGenerator(config, streamFactory))
            {
                Console.WriteLine($"Processing '{sourceFile}'");
                generator.GenerateBindings(translationUnit, sourceFile, clangArgs, translationFlags);

                generator.Close();

                // Write output to disk
                foreach (var kvp in capturedStreams)
                {
                    var dir = Path.GetDirectoryName(kvp.Key);
                    if (!string.IsNullOrEmpty(dir))
                        Directory.CreateDirectory(dir);
                    File.WriteAllBytes(kvp.Key, kvp.Value.ToArray());
                }

                // Write diagnostics
                foreach (var diag in generator.Diagnostics)
                {
                    Console.WriteLine($"    {diag}");
                    if (diag.Level == DiagnosticLevel.Warning && exitCode >= 0)
                        exitCode++;
                    else if (diag.Level == DiagnosticLevel.Error)
                    {
                        if (exitCode >= 0) exitCode = -1;
                        else exitCode--;
                    }
                }
            }

            // Write auto-discovered remaps + fn ptr remaps to sidecar file
            var allAutoRemaps = new Dictionary<string, string>(autoRemaps);
            foreach (var kv in fnPtrRemaps)
                allAutoRemaps[kv.Key] = kv.Value;

            if (allAutoRemaps.Count > 0 || fnPtrExcludes.Count > 0 || reducePointerLevel.Count > 0)
            {
                var remapDir = Path.GetDirectoryName(remapsOutputPath);
                if (!string.IsNullOrEmpty(remapDir))
                    Directory.CreateDirectory(remapDir);

                using var writer = new StreamWriter(remapsOutputPath);

                // Tag remaps
                foreach (var kv in allAutoRemaps.OrderBy(kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"{kv.Key}={kv.Value}");

                // Function pointer excludes (prefixed for downstream parsing)
                foreach (var excl in fnPtrExcludes.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"FNPTR_EXCLUDE:{excl}");

                // Reduce pointer level entries
                foreach (var rpl in reducePointerLevel.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"REDUCE_PTR_LEVEL:{rpl}");
            }

            return exitCode;
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine($"Error: {ex.Message}");
            Console.Error.WriteLine(ex.StackTrace);
            return 1;
        }
    }

    /// <summary>
    /// Recursively walks the AST to collect all typedef-tag relationships and
    /// function pointer typedef pairs.
    /// </summary>
    static void WalkForTypedefRemaps(Decl decl,
        Dictionary<string, List<string>> tagToTypedefs,
        Dictionary<string, List<string>> fnProtoToPointerTypedefs,
        HashSet<string> fnProtoTypedefNames)
    {
        if (decl is TypedefDecl typedefDecl)
        {
            var underlyingType = UnwrapType(typedefDecl.UnderlyingType);

            if (underlyingType is TagType tagType)
            {
                // Direct tag-typedef pair (struct _FOO → FOO)
                var tagDecl = tagType.Decl;
                if (tagDecl != null)
                {
                    string tagName = tagDecl.Name;
                    if (tagDecl.DeclContext is NamedDecl parent)
                        tagName = $"{parent.Name}::{tagName}";

                    string typedefName = typedefDecl.Name;
                    if (!string.IsNullOrEmpty(tagName) && tagName != typedefName)
                    {
                        if (!tagToTypedefs.TryGetValue(tagName, out var list))
                            tagToTypedefs[tagName] = list = new List<string>();
                        if (!list.Contains(typedefName))
                            list.Add(typedefName);
                    }
                }
            }
            else if (underlyingType is FunctionProtoType)
            {
                // Function prototype typedef (e.g., TIMECALLBACK)
                fnProtoTypedefNames.Add(typedefDecl.Name);
            }
            else if (underlyingType is PointerType ptrType)
            {
                var pointee = UnwrapType(ptrType.PointeeType);

                if (pointee is FunctionProtoType)
                {
                    // Direct pointer-to-function typedef (e.g., typedef void (*LPFOO)(...))
                    fnProtoTypedefNames.Add(typedefDecl.Name);
                }
                else if (pointee is TypedefType tdType)
                {
                    // Pointer to a typedef — might be a fn ptr alias
                    // e.g., typedef TIMECALLBACK *LPTIMECALLBACK
                    string pointedTypedefName = tdType.Decl?.Name;
                    if (pointedTypedefName != null)
                    {
                        if (!fnProtoToPointerTypedefs.TryGetValue(pointedTypedefName, out var ptrList))
                            fnProtoToPointerTypedefs[pointedTypedefName] = ptrList = new List<string>();
                        if (!ptrList.Contains(typedefDecl.Name))
                            ptrList.Add(typedefDecl.Name);
                    }
                }
            }
            else if (underlyingType is TypedefType tdType2)
            {
                // Typedef-to-typedef alias (e.g., typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE)
                string sourceTypedefName = tdType2.Decl?.Name;
                if (sourceTypedefName != null)
                {
                    if (!fnProtoToPointerTypedefs.TryGetValue(sourceTypedefName, out var aliasList))
                        fnProtoToPointerTypedefs[sourceTypedefName] = aliasList = new List<string>();
                    if (!aliasList.Contains(typedefDecl.Name))
                        aliasList.Add(typedefDecl.Name);
                }
            }
        }

        if (decl is IDeclContext context)
        {
            foreach (var child in context.Decls)
            {
                WalkForTypedefRemaps(child, tagToTypedefs, fnProtoToPointerTypedefs, fnProtoTypedefNames);
            }
        }
    }

    /// <summary>
    /// Unwraps sugar types (ElaboratedType, AttributedType, ParenType) to get to
    /// the semantically meaningful type underneath.
    /// </summary>
    static ClangSharp.Type UnwrapType(ClangSharp.Type type)
    {
        while (true)
        {
            if (type is ElaboratedType elab)
                type = elab.NamedType;
            else if (type is AttributedType attr)
                type = attr.ModifiedType;
            else if (type is ParenType paren)
                type = paren.InnerType;
            else
                return type;
        }
    }

    /// <summary>
    /// Resolves discovered tag-typedef mappings into a flat remap dictionary.
    /// For tags with multiple typedefs, uses disambiguation rules to pick the best one,
    /// or skips the tag if ambiguous (requiring manual override).
    /// </summary>
    static Dictionary<string, string> ResolveTagRemaps(
        Dictionary<string, List<string>> tagToTypedefs,
        Dictionary<string, string> configuredRemaps)
    {
        var result = new Dictionary<string, string>();

        foreach (var kv in tagToTypedefs)
        {
            string tag = kv.Key;
            var typedefs = kv.Value;

            if (typedefs.Count == 1)
            {
                // Unambiguous — single typedef for this tag
                result[tag] = typedefs[0];
            }
            else
            {
                // Multiple typedefs — try to disambiguate

                // If one of them matches what manual config says, use that
                if (configuredRemaps.TryGetValue(tag, out string manualValue) && typedefs.Contains(manualValue))
                {
                    result[tag] = manualValue;
                    continue;
                }

                // Heuristic: prefer the typedef that is the "cleaned" version of the tag
                // e.g., _FOO → FOO (strip leading underscore)
                // e.g., tagFOO → FOO (strip "tag" prefix)
                string stripped = null;
                if (tag.StartsWith("_") && tag.Length > 1)
                    stripped = tag.Substring(1);
                else if (tag.StartsWith("tag") && tag.Length > 3 && char.IsUpper(tag[3]))
                    stripped = tag.Substring(3);

                if (stripped != null)
                {
                    var match = typedefs.FirstOrDefault(t => string.Equals(t, stripped, StringComparison.OrdinalIgnoreCase));
                    if (match != null)
                    {
                        result[tag] = match;
                        continue;
                    }
                }

                // Can't disambiguate — skip (requires manual override)
                // This is the conservative choice: no auto-remap for ambiguous tags
            }
        }

        return result;
    }

    /// <summary>
    /// Resolves function pointer typedef pairs into remap + exclude + reducePointerLevel entries.
    /// </summary>
    static void ResolveFunctionPointerFixups(
        HashSet<string> fnProtoTypedefNames,
        Dictionary<string, List<string>> fnProtoToPointerTypedefs,
        Dictionary<string, string> fnPtrRemaps,
        HashSet<string> fnPtrExcludes,
        HashSet<string> reducePointerLevel)
    {
        foreach (var protoName in fnProtoTypedefNames)
        {
            if (!fnProtoToPointerTypedefs.TryGetValue(protoName, out var pointerNames))
                continue;

            if (pointerNames.Count != 1)
                continue; // Ambiguous — skip

            string pointerName = pointerNames[0];

            // Validate the naming convention looks right
            bool looksLikePointerTypedef =
                pointerName.StartsWith("LP") ||
                pointerName.StartsWith("P") ||
                pointerName.StartsWith("PFN");

            if (!looksLikePointerTypedef)
                continue; // Conservative — skip non-standard naming

            fnPtrRemaps[protoName] = pointerName;
            fnPtrExcludes.Add(pointerName);
            reducePointerLevel.Add(pointerName);
        }
    }

    static PInvokeGeneratorConfiguration CreateConfig(
        Dictionary<string, List<string>> settings,
        string ns, string outputFile, string headerFile,
        PInvokeGeneratorConfigurationOptions options,
        Dictionary<string, string> remaps,
        List<string> excludes)
    {
        string defaultClass = null;
        if (settings.TryGetValue("--methodClassName", out var classNames) && classNames.Count > 0)
            defaultClass = classNames.Last();

        string libraryPath = null;
        if (settings.TryGetValue("--libraryPath", out var libPaths) && libPaths.Count > 0)
            libraryPath = libPaths.Last();

        var config = new PInvokeGeneratorConfiguration("c++", "c++17", ns, outputFile, headerFile ?? string.Empty,
            PInvokeGeneratorOutputMode.CSharp, options)
        {
            DefaultClass = defaultClass ?? "Methods",
            TraversalNames = settings.GetValueOrDefault("--traverse")?.ToArray() ?? Array.Empty<string>(),
            ExcludedNames = excludes.ToArray(),
            RemappedNames = remaps,
            WithAttributes = ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-attribute")),
            WithTypes = ParseKeyValuePairs(settings.GetValueOrDefault("--with-type")),
            WithLibraryPaths = ParseKeyValuePairs(settings.GetValueOrDefault("--with-librarypath")),
            WithCallConvs = ParseKeyValuePairs(settings.GetValueOrDefault("--with-callconv")),
            WithUsings = ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-using")),
            WithSetLastErrors = settings.GetValueOrDefault("--with-setlasterror")?.ToArray() ?? Array.Empty<string>(),
            WithSuppressGCTransitions = settings.GetValueOrDefault("--with-suppressgctransition")?.ToArray() ?? Array.Empty<string>(),
            LibraryPath = libraryPath ?? string.Empty,
        };

        return config;
    }

    /// <summary>
    /// Filters discovered remaps using structural signals only — no exclusion list needed.
    /// Ambiguous tags (multiple typedefs) are already handled by ResolveTagRemaps.
    /// This filter only removes entries that are clearly NOT tag-typedef pairs.
    /// </summary>
    static Dictionary<string, string> FilterRemaps(
        Dictionary<string, string> discovered,
        Dictionary<string, string> configuredRemaps)
    {
        var builtins = new HashSet<string>(StringComparer.OrdinalIgnoreCase)
            { "intptr_t", "ptrdiff_t", "size_t", "uintptr_t", "_GUID" };
        var result = new Dictionary<string, string>();

        foreach (var kv in discovered)
        {
            string tag = kv.Key;
            string typedef = kv.Value;

            // Skip built-in Clang defaults
            if (builtins.Contains(tag)) continue;

            // Skip identity remaps
            if (tag == typedef) continue;

            // Skip if configured remap has a different value (semantic override wins)
            if (configuredRemaps.TryGetValue(tag, out string configuredValue) && configuredValue != typedef)
                continue;

            result[tag] = typedef;
        }

        return result;
    }

    static string[] BuildClangArgs(Dictionary<string, List<string>> settings)
    {
        var clangArgs = new List<string> { "--language=c++", "--std=c++17", "-Wno-pragma-once-outside-header" };
        if (settings.TryGetValue("--include-directory", out var incDirs))
            foreach (var dir in incDirs)
                clangArgs.Add($"--include-directory={dir}");
        if (settings.TryGetValue("--additional", out var additionals))
            clangArgs.AddRange(additionals);
        return clangArgs.ToArray();
    }

    static PInvokeGeneratorConfigurationOptions BuildOptionsFlags(Dictionary<string, List<string>> settings)
    {
        var options = RuntimeInformation.IsOSPlatform(OSPlatform.Windows)
            ? PInvokeGeneratorConfigurationOptions.None
            : PInvokeGeneratorConfigurationOptions.GenerateUnixTypes;

        if (settings.TryGetValue("--config", out var configs))
        {
            foreach (var cfg in configs)
            {
                options |= cfg switch
                {
                    "compatible-codegen" => PInvokeGeneratorConfigurationOptions.GenerateCompatibleCode,
                    "log-visited-files" => PInvokeGeneratorConfigurationOptions.LogVisitedFiles,
                    "log-exclusions" => PInvokeGeneratorConfigurationOptions.LogExclusions,
                    "log-potential-typedef-remappings" => PInvokeGeneratorConfigurationOptions.LogPotentialTypedefRemappings,
                    "exclude-funcs-with-body" => PInvokeGeneratorConfigurationOptions.ExcludeFunctionsWithBody,
                    "generate-cpp-attributes" => PInvokeGeneratorConfigurationOptions.GenerateCppAttributes,
                    "generate-native-bitfield-attribute" => PInvokeGeneratorConfigurationOptions.GenerateNativeBitfieldAttribute,
                    "generate-native-inheritance-attribute" => PInvokeGeneratorConfigurationOptions.GenerateNativeInheritanceAttribute,
                    "dont-use-using-statics-for-enums" or
                    "exclude-using-statics-for-enums" => PInvokeGeneratorConfigurationOptions.DontUseUsingStaticsForEnums,
                    "exclude-anonymous-field-helpers" => PInvokeGeneratorConfigurationOptions.ExcludeAnonymousFieldHelpers,
                    "exclude-empty-records" => PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords,
                    "exclude-enum-operators" => PInvokeGeneratorConfigurationOptions.ExcludeEnumOperators,
                    "exclude-com-proxies" => PInvokeGeneratorConfigurationOptions.ExcludeComProxies,
                    "generate-marker-interfaces" => PInvokeGeneratorConfigurationOptions.GenerateMarkerInterfaces,
                    "generate-explicit-vtbls" => PInvokeGeneratorConfigurationOptions.GenerateExplicitVtbls,
                    "generate-trimmable-vtbls" => PInvokeGeneratorConfigurationOptions.GenerateTrimmableVtbls,
                    "generate-aggressive-inlining" => PInvokeGeneratorConfigurationOptions.GenerateAggressiveInlining,
                    "multi-file" => PInvokeGeneratorConfigurationOptions.GenerateMultipleFiles,
                    "generate-macro-bindings" => PInvokeGeneratorConfigurationOptions.GenerateMacroBindings,
                    "generate-file-scoped-namespaces" => PInvokeGeneratorConfigurationOptions.GenerateFileScopedNamespaces,
                    "generate-disable-runtime-marshalling" => PInvokeGeneratorConfigurationOptions.GenerateDisableRuntimeMarshalling,
                    "generate-guid-member" => PInvokeGeneratorConfigurationOptions.GenerateGuidMember,
                    "generate-helper-types" => PInvokeGeneratorConfigurationOptions.GenerateHelperTypes,
                    "generate-vtbl-index-attribute" => PInvokeGeneratorConfigurationOptions.GenerateVtblIndexAttribute,
                    "generate-setslasterror-attribute" or
                    "generate-sets-last-system-error-attribute" => PInvokeGeneratorConfigurationOptions.GenerateSetsLastSystemErrorAttribute,
                    "generate-unmanaged-constants" => PInvokeGeneratorConfigurationOptions.GenerateUnmanagedConstants,
                    "generate-latest-code" => PInvokeGeneratorConfigurationOptions.GenerateLatestCode,
                    "generate-template-bindings" => PInvokeGeneratorConfigurationOptions.GenerateTemplateBindings,
                    "generate-source-location-attribute" => PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute,
                    "generate-callconv-member-function" => PInvokeGeneratorConfigurationOptions.GenerateCallConvMemberFunction,
                    "generate-doc-includes" => PInvokeGeneratorConfigurationOptions.GenerateDocIncludes,
                    "preview-codegen" => PInvokeGeneratorConfigurationOptions.GeneratePreviewCode,
                    "unix-types" => PInvokeGeneratorConfigurationOptions.GenerateUnixTypes,
                    _ => PInvokeGeneratorConfigurationOptions.None
                };
            }
        }
        return options;
    }

    static void ParseRspFile(string path, Dictionary<string, List<string>> settings)
    {
        if (!File.Exists(path)) return;
        string currentSwitch = null;
        foreach (var rawLine in File.ReadLines(path))
        {
            string line = rawLine.Trim();
            if (string.IsNullOrEmpty(line)) continue;

            if (line.StartsWith("@"))
            {
                string nestedPath = line.Substring(1).Trim('"');
                ParseRspFile(nestedPath, settings);
            }
            else if (line.StartsWith("--"))
            {
                currentSwitch = line;
                if (!settings.ContainsKey(currentSwitch))
                    settings[currentSwitch] = new List<string>();
            }
            else if (currentSwitch != null)
            {
                settings[currentSwitch].Add(line);
            }
        }
    }

    static Dictionary<string, string> ParseKeyValuePairs(List<string> items)
    {
        var dict = new Dictionary<string, string>();
        if (items == null) return dict;
        foreach (var item in items)
        {
            int eq = item.IndexOf('=');
            if (eq > 0)
                dict[item.Substring(0, eq)] = item.Substring(eq + 1);
        }
        return dict;
    }

    static Dictionary<string, IReadOnlyList<string>> ParseKeyValueMultiPairs(List<string> items)
    {
        var dict = new Dictionary<string, IReadOnlyList<string>>();
        if (items == null) return dict;
        var temp = new Dictionary<string, List<string>>();
        foreach (var item in items)
        {
            int eq = item.IndexOf('=');
            if (eq > 0)
            {
                string key = item.Substring(0, eq);
                string val = item.Substring(eq + 1);
                if (!temp.TryGetValue(key, out var list))
                    temp[key] = list = new List<string>();
                list.Add(val);
            }
        }
        foreach (var kv in temp)
            dict[kv.Key] = kv.Value;
        return dict;
    }
}
