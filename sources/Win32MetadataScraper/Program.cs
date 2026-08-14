// Win32MetadataScraper: Single-pass scraper that wraps ClangSharp PInvokeGenerator.
//
// Hosts PInvokeGenerator as a library (via NuGet package references). Parses the
// translation unit, walks the AST to discover typedef-tag remappings, merges them
// with the configured --remap entries, then runs PInvokeGenerator.GenerateBindings
// with the full merged remap set — all in a single parse pass.
//
// Usage: dotnet Win32MetadataScraper.dll <remapsOutputPath> @rsp1 @rsp2 ...

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using ClangSharp;
using ClangSharp.Interop;
using Win32MetadataScraper;
using static ClangSharp.Interop.CXDiagnosticSeverity;
using static ClangSharp.Interop.CXErrorCode;
using static ClangSharp.Interop.CXTranslationUnit_Flags;

class Program
{
    static readonly Dictionary<string, string> OptionAliases = new(StringComparer.Ordinal)
    {
        ["-a"] = "--additional",
        ["-c"] = "--config",
        ["-e"] = "--exclude",
        ["-f"] = "--file",
        ["-hf"] = "--headerFile",
        ["--header-file"] = "--headerFile",
        ["-I"] = "--include-directory",
        ["-x"] = "--language",
        ["-l"] = "--libraryPath",
        ["--library-path"] = "--libraryPath",
        ["-m"] = "--methodClassName",
        ["--method-class-name"] = "--methodClassName",
        ["-n"] = "--namespace",
        ["-o"] = "--output",
        ["-r"] = "--remap",
        ["-std"] = "--std",
        ["-t"] = "--traverse",
        ["-wa"] = "--with-attribute",
        ["-wcc"] = "--with-callconv",
        ["-wlb"] = "--with-librarypath",
        ["--with-library-path"] = "--with-librarypath",
        ["-wsle"] = "--with-setlasterror",
        ["--with-set-last-error"] = "--with-setlasterror",
        ["-wsgct"] = "--with-suppressgctransition",
        ["--with-suppress-gc-transition"] = "--with-suppressgctransition",
        ["-wt"] = "--with-type",
        ["-wu"] = "--with-using",
    };

    static readonly HashSet<string> SupportedOptions = new(StringComparer.OrdinalIgnoreCase)
    {
        "--additional",
        "--config",
        "--exclude",
        "--exclude-auto-remap",
        "--file",
        "--headerFile",
        "--include-directory",
        "--language",
        "--libraryPath",
        "--methodClassName",
        "--namespace",
        "--output",
        "--preserve-auto-fnptr-level",
        "--remap",
        "--std",
        "--traverse",
        "--with-attribute",
        "--with-callconv",
        "--with-librarypath",
        "--with-setlasterror",
        "--with-suppressgctransition",
        "--with-type",
        "--with-using",
    };

    static int Main(string[] args)
    {
        if (args.Length < 2)
        {
            Console.Error.WriteLine("Usage: dotnet Win32MetadataScraper.dll <remapsOutputPath> @rsp1 @rsp2 ...");
            return 1;
        }

        string remapsOutputPath = args[0];
        string[] rspArgs = args.Skip(1).ToArray();

        try
        {
            // Parse RSP files
            var settings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
            foreach (var arg in rspArgs)
            {
                string rspPath = arg.StartsWith("@") ? arg.Substring(1).Trim('"') : arg;
                ParseRspFile(rspPath, settings);
            }

            string[] unsupportedOptions = settings.Keys
                .Where(option => !SupportedOptions.Contains(option))
                .OrderBy(option => option, StringComparer.OrdinalIgnoreCase)
                .ToArray();
            if (unsupportedOptions.Length > 0)
            {
                Console.Error.WriteLine($"Error: Unsupported response-file option(s): {string.Join(", ", unsupportedOptions)}");
                return 1;
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
            var configuredAutoRemapExcludes = new HashSet<string>(
                settings.GetValueOrDefault("--exclude-auto-remap") ?? new List<string>(),
                StringComparer.Ordinal);
            var configuredExcludes = new HashSet<string>(
                settings.GetValueOrDefault("--exclude") ?? new List<string>(),
                StringComparer.Ordinal);

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
            var discovery = RemapDiscovery.WalkTranslationUnit(translationUnit.TranslationUnitDecl);

            // Resolve tag remaps using disambiguation, then apply opt-outs for
            // compatibility cases where we intentionally keep the historical public name.
            var resolvedTagRemaps = RemapDiscovery.ResolveTagRemaps(discovery.TagToTypedefs, configuredRemaps);
            var autoRemaps = RemapDiscovery.FilterTagRemaps(
                resolvedTagRemaps,
                configuredRemaps,
                discovery.EnumTags,
                configuredAutoRemapExcludes);

            // Resolve function pointer fixups
            var fnPtrResult = RemapDiscovery.ResolveFunctionPointerFixups(discovery, configuredExcludes);
            var preservedFnPtrLevels = settings.GetValueOrDefault("--preserve-auto-fnptr-level") ?? new List<string>();
            foreach (string name in preservedFnPtrLevels)
            {
                fnPtrResult.ReducePointerLevel.Remove(name);
            }

            // Merge all remaps: auto tag remaps + fn ptr remaps + configured (configured wins)
            var mergedRemaps = new Dictionary<string, string>(autoRemaps);
            foreach (var kv in fnPtrResult.FnPtrRemaps)
                mergedRemaps[kv.Key] = kv.Value;
            foreach (var kv in configuredRemaps)
                mergedRemaps[kv.Key] = kv.Value;

            // Merge excludes from function pointer fixups into the configured excludes
            var allExcludes = new List<string>(settings.GetValueOrDefault("--exclude") ?? new List<string>());
            foreach (var excl in fnPtrResult.FnPtrExcludes)
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

                    string generatedSource = Encoding.UTF8.GetString(kvp.Value.ToArray());
                    File.WriteAllText(kvp.Key, NormalizeGeneratedSource(generatedSource, kvp.Key), new UTF8Encoding(false));
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
            foreach (var kv in fnPtrResult.FnPtrRemaps)
                allAutoRemaps[kv.Key] = kv.Value;

            if (allAutoRemaps.Count > 0 || fnPtrResult.FnPtrExcludes.Count > 0 || fnPtrResult.ReducePointerLevel.Count > 0 || preservedFnPtrLevels.Count > 0)
            {
                var remapDir = Path.GetDirectoryName(remapsOutputPath);
                if (!string.IsNullOrEmpty(remapDir))
                    Directory.CreateDirectory(remapDir);

                using var writer = new StreamWriter(remapsOutputPath);

                // Tag remaps (with header file info)
                foreach (var kv in allAutoRemaps.OrderBy(kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                {
                    discovery.TagToHeaderFile.TryGetValue(kv.Key, out string srcHeader);
                    if (srcHeader != null)
                        writer.WriteLine($"{kv.Key}={kv.Value}|HEADER:{srcHeader}");
                    else
                        writer.WriteLine($"{kv.Key}={kv.Value}");
                }

                // Function pointer excludes (prefixed for downstream parsing)
                foreach (var excl in fnPtrResult.FnPtrExcludes.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"FNPTR_EXCLUDE:{excl}");

                // Reduce pointer level entries
                foreach (var rpl in fnPtrResult.ReducePointerLevel.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"REDUCE_PTR_LEVEL:{rpl}");

                foreach (var preserved in preservedFnPtrLevels.OrderBy(x => x, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"PRESERVE_PTR_LEVEL:{preserved}");
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

    static string NormalizeGeneratedSource(string source, string outputPath)
    {
        source = Regex.Replace(source, @"(?<=_Anonymous)-\d+(?=_e__Struct)", string.Empty);

        Dictionary<string, string[]> fieldDerivedAnonymousNames = new(StringComparer.OrdinalIgnoreCase)
        {
            ["Backup"] = new[] { "_ScopeRecord_e__Struct" },
            ["Buses"] = new[] { "_AlternateMode_e__Struct" },
            ["Display"] = new[] { "_Level_e__Struct", "_LookupTable_e__Union" },
            ["Ioctl"] = new[] { "_BootSectors_e__Struct", "_Extents_e__Struct" },
            ["NWifi"] = new[] { "_DataList_e__Struct" },
            ["RRas"] = new[] { "_ViewInfo_e__Struct" },
            ["Setup"] = new[] { "_Range_e__Struct" },
        };

        string partitionName = Path.GetFileNameWithoutExtension(outputPath);
        foreach (string name in fieldDerivedAnonymousNames.GetValueOrDefault(partitionName) ?? Array.Empty<string>())
        {
            string anonymousName = name.EndsWith("_e__Union", StringComparison.Ordinal)
                ? "_Anonymous_e__Union"
                : "_Anonymous_e__Struct";
            source = source.Replace(name, anonymousName, StringComparison.Ordinal);
        }

        // ClangSharp 21 confuses the LIBID with a later CLSID that shares its name suffix.
        return source.Replace(
            "public static readonly Guid LIBID_SystemMonitor = new Guid(0xC4D2D8E0, 0xD1DD, 0x11CE, 0x94, 0x0F, 0x00, 0x80, 0x29, 0x00, 0x43, 0x47);",
            "public static readonly Guid LIBID_SystemMonitor = new Guid(0x1B773E42, 0x2509, 0x11CF, 0x94, 0x2F, 0x00, 0x80, 0x29, 0x00, 0x43, 0x47);",
            StringComparison.Ordinal);
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

        string language = settings.GetValueOrDefault("--language")?.LastOrDefault() ?? "c++";
        string languageStandard = settings.GetValueOrDefault("--std")?.LastOrDefault() ?? "c++17";

        var config = new PInvokeGeneratorConfiguration(language, languageStandard, ns, outputFile, headerFile ?? string.Empty,
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

    static string[] BuildClangArgs(Dictionary<string, List<string>> settings)
    {
        string language = settings.GetValueOrDefault("--language")?.LastOrDefault() ?? "c++";
        string languageStandard = settings.GetValueOrDefault("--std")?.LastOrDefault() ?? "c++17";
        var clangArgs = new List<string> { $"--language={language}", $"--std={languageStandard}", "-Wno-pragma-once-outside-header" };
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
            if (line.StartsWith("#", StringComparison.Ordinal)) continue;

            if (line.StartsWith("@"))
            {
                string nestedPath = line.Substring(1).Trim('"');
                ParseRspFile(nestedPath, settings);
            }
            else if (TryParseOption(line, out string option, out string inlineValue))
            {
                currentSwitch = option;
                if (!settings.ContainsKey(currentSwitch))
                    settings[currentSwitch] = new List<string>();

                if (!string.IsNullOrEmpty(inlineValue))
                    settings[currentSwitch].Add(inlineValue);
            }
            else if (currentSwitch != null)
            {
                settings[currentSwitch].Add(line);
            }
        }

        static bool TryParseOption(string line, out string option, out string inlineValue)
        {
            option = null;
            inlineValue = null;

            int separatorIndex = line.IndexOf('=');
            string candidate = separatorIndex >= 0 ? line.Substring(0, separatorIndex) : line;
            bool isLongOption = candidate.StartsWith("--", StringComparison.Ordinal);
            if (!isLongOption && !OptionAliases.ContainsKey(candidate))
                return false;

            option = OptionAliases.GetValueOrDefault(candidate) ?? candidate;
            if (separatorIndex >= 0 && separatorIndex < line.Length - 1)
                inlineValue = line.Substring(separatorIndex + 1);

            return true;
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
