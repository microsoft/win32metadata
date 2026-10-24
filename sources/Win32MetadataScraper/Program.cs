// Win32MetadataScraper: Original-TU scraper that wraps ClangSharp PInvokeGenerator.
//
// Hosts PInvokeGenerator as a library (via NuGet package references). Parses the
// translation unit, walks the AST to discover typedef-tag remappings, merges them
// with the configured --remap entries, then runs PInvokeGenerator.GenerateBindings
// with the full merged remap set. Annotation facts use the original detailed TU;
// ordinary bindings use a declaration-only TU. Integer macros use native typed
// probes; general macro binding remains opt-in.
//
// Usage: dotnet Win32MetadataScraper.dll <remapsOutputPath> @rsp1 @rsp2 ...

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Text.RegularExpressions;
using System.Text.Json;
using ClangSharp;
using ClangSharp.Interop;
using Microsoft.CodeAnalysis;
using Microsoft.CodeAnalysis.CSharp;
using Microsoft.CodeAnalysis.CSharp.Syntax;
using MetadataUtils;
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
        "--auto-remaps-file",
        "--config",
        "--declaration-map",
        "--declaration-map-symbol",
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
            string declarationMap = settings.GetValueOrDefault("--declaration-map")?.SingleOrDefault();
            var declarationMapSymbols = settings.GetValueOrDefault("--declaration-map-symbol");

            if (declarationMapSymbols != null && (declarationMap == null || declarationMapSymbols.Count == 0))
            {
                Console.Error.WriteLine("Error: --declaration-map-symbol requires --declaration-map and at least one native symbol");
                return 1;
            }

            if (sourceFile == null || outputFile == null || ns == null)
            {
                Console.Error.WriteLine("Error: Missing required --file, --output, or --namespace in RSP files");
                return 1;
            }

            var clangArgs = BuildClangArgs(settings);
            bool parseHeaderAnnotations = settings.GetValueOrDefault("--config")?.Contains("parse-win32-annotations") == true;
            bool evaluateNativeConstants = settings.GetValueOrDefault("--config")?.Contains("native-constant-values") == true;
            bool constantsOnly = settings.GetValueOrDefault("--config")?.Contains("native-constants-only") == true;
            var derivedSettings = LoadAutoRemaps(settings, parseHeaderAnnotations);
            if (parseHeaderAnnotations)
            {
                if (clangArgs.Contains("-w", StringComparer.Ordinal))
                {
                    Console.Error.WriteLine("Error: -w suppresses ignored metadata attribute diagnostics and cannot be used with parse-win32-annotations. Use specific -Wno- options for native warnings.");
                    return 1;
                }
                clangArgs = clangArgs.Concat(new[]
                {
                    "-DWIN32METADATA",
                    "-D_WIN32META_ANNOTATION_(...)=_Pragma(\"clang diagnostic push\") " +
                        "_Pragma(\"clang diagnostic error \\\"-Wignored-attributes\\\"\") " +
                        $"__attribute__((annotate(\"{HeaderAnnotation.OwnerPrefix}\" __VA_ARGS__))) " +
                        "_Pragma(\"clang diagnostic pop\")",
                }).ToArray();
            }
            var configOptions = BuildOptionsFlags(settings);
            string additionalTypesPath = configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateMultipleFiles)
                ? Path.Combine(outputFile, "header-types.cs")
                : Path.ChangeExtension(outputFile, ".header-types.cs");
            string nativeConstantsPath = configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateMultipleFiles)
                ? Path.Combine(outputFile, "Bindings.native-constants.json")
                : Path.ChangeExtension(outputFile, ".native-constants.json");
            string nativeDeclarationsPath = configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateMultipleFiles)
                ? Path.Combine(outputFile, "Bindings.native-declarations.json")
                : Path.ChangeExtension(outputFile, ".native-declarations.json");
            if (declarationMap == null && File.Exists(nativeDeclarationsPath))
                File.Delete(nativeDeclarationsPath);
            if (declarationMap == null && File.Exists(nativeConstantsPath))
                File.Delete(nativeConstantsPath);
            if (parseHeaderAnnotations && declarationMap == null && File.Exists(additionalTypesPath))
                File.Delete(additionalTypesPath);
            bool generateAllMacros = configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateMacroBindings);
            var configuredRemaps = ParseKeyValuePairs(settings.GetValueOrDefault("--remap"));
            var configuredAutoRemapExcludes = new HashSet<string>(
                settings.GetValueOrDefault("--exclude-auto-remap") ?? new List<string>(),
                StringComparer.Ordinal);
            var configuredExcludes = new HashSet<string>(
                settings.GetValueOrDefault("--exclude") ?? new List<string>(),
                StringComparer.Ordinal);

            var translationFlags = CXTranslationUnit_IncludeAttributedTypes
                                 | CXTranslationUnit_VisitImplicitAttributes;
            if (parseHeaderAnnotations || generateAllMacros || evaluateNativeConstants || constantsOnly)
                translationFlags |= CXTranslationUnit_DetailedPreprocessingRecord;

            // Discovery and annotations need preprocessing records, but ordinary
            // binding generation must not evaluate unrelated SDK macros.
            using var index = CXIndex.Create(excludeDeclarationsFromPch: false, displayDiagnostics: false);
            var reportedNativeDiagnostics = new HashSet<string>(StringComparer.Ordinal);
            using var translationUnit = ParseTranslationUnit(index, sourceFile, clangArgs, translationFlags,
                reportedNativeDiagnostics);
            if (translationUnit == null)
                return -1;

            if (declarationMap != null)
            {
                DeclarationSourceMap.Write(translationUnit.Handle.Cursor, sourceFile, clangArgs, declarationMap, declarationMapSymbols);
                return 0;
            }
            if (settings.TryGetValue("--traverse", out var nativeTraversalFiles))
                settings["--traverse"] = RemapDiscovery.ResolveTraversalFiles(
                    translationUnit.TranslationUnitDecl, nativeTraversalFiles).ToList();
            if (constantsOnly)
            {
                var constantConfig = CreateConfig(settings, ns, outputFile, headerFile, configOptions,
                    configuredRemaps, configuredExcludes.ToList());
                var values = NativeConstantExtractor.Extract(translationUnit, sourceFile, clangArgs,
                    constantConfig, reportedNativeDiagnostics);
                Directory.CreateDirectory(Path.GetDirectoryName(Path.GetFullPath(nativeConstantsPath)));
                File.WriteAllText(nativeConstantsPath, JsonSerializer.Serialize(values), new UTF8Encoding(false));
                Console.WriteLine($"Native constants: {values.Constants.Count} integers; {values.Issues.Count} other definitions. Details: {nativeConstantsPath}");
                return 0;
            }

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

            // Cached settings affect bindings, not discovery; authored settings win.
            var mergedRemaps = new Dictionary<string, string>(autoRemaps);
            foreach (var kv in fnPtrResult.FnPtrRemaps)
                mergedRemaps[kv.Key] = kv.Value;
            foreach (var kv in RemapDiscovery.FindEmbeddedIncompleteRecordPointerRemaps(translationUnit.TranslationUnitDecl))
                mergedRemaps[kv.Key] = kv.Value;
            foreach (var kv in ParseKeyValuePairs(derivedSettings.GetValueOrDefault("--remap")))
                mergedRemaps[kv.Key] = kv.Value;
            foreach (var kv in configuredRemaps)
                mergedRemaps[kv.Key] = kv.Value;

            var allExcludes = (settings.GetValueOrDefault("--exclude") ?? new List<string>())
                .Concat(derivedSettings.GetValueOrDefault("--exclude") ?? new List<string>())
                .Concat(fnPtrResult.FnPtrExcludes).Distinct(StringComparer.Ordinal).ToList();
            allExcludes.AddRange(RemapDiscovery.FindInaccessibleCopyMembers(
                translationUnit.TranslationUnitDecl,
                configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.ExcludeFunctionsWithBody)));

            var annotations = parseHeaderAnnotations
                ? new HeaderAnnotationProcessor(translationUnit, mergedRemaps, ns,
                    settings.GetValueOrDefault("--traverse") ?? new List<string>(), new HashSet<string>(allExcludes),
                    configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.ExcludeFunctionsWithBody))
                : null;
            annotations?.PrepareTypedefs();
            if (annotations != null)
                allExcludes.AddRange(annotations.AnnotationCarrierNames);
            var config = CreateConfig(settings, ns, outputFile, headerFile, configOptions,
                RemapDiscovery.CreateBindingRemaps(discovery, mergedRemaps, configuredAutoRemapExcludes), allExcludes);
            using var companion = NativeConditionalCompanion.Create(translationUnit, clangArgs, translationFlags,
                config.TraversalNames, config.WithLibraryPaths, configuredRemaps,
                allExcludes.ToHashSet(StringComparer.Ordinal), (arguments, flags) =>
                    ParseTranslationUnit(index, sourceFile, arguments, flags, reportedNativeDiagnostics), nativeDeclarationsPath);
            foreach (var remap in companion.ScopedRemaps)
                mergedRemaps[remap.Key] = remap.Value;
            if (companion.ScopedRemaps.Count != 0)
                config = CreateConfig(settings, ns, outputFile, headerFile, configOptions,
                    RemapDiscovery.CreateBindingRemaps(discovery, mergedRemaps, configuredAutoRemapExcludes), allExcludes);
            var nativeConstants = evaluateNativeConstants
                ? NativeConstantExtractor.Extract(translationUnit, sourceFile, clangArgs, config, reportedNativeDiagnostics)
                : null;

            var capturedStreams = new Dictionary<string, MemoryStream>();
            Func<string, Stream> streamFactory = (path) =>
            {
                var ms = new MemoryStream();
                capturedStreams[path] = ms;
                return ms;
            };

            int exitCode = 0;
            bool separateDeclarations = (parseHeaderAnnotations || evaluateNativeConstants) && !generateAllMacros;
            var bindingFlags = separateDeclarations
                ? translationFlags & ~CXTranslationUnit_DetailedPreprocessingRecord
                : translationFlags;
            using var declarationUnit = separateDeclarations
                ? ParseTranslationUnit(index, sourceFile, clangArgs, bindingFlags, reportedNativeDiagnostics)
                : null;
            if (separateDeclarations && declarationUnit == null)
                return -1;
            using (var generator = new PInvokeGenerator(config, streamFactory))
            {
                Console.WriteLine($"Processing '{sourceFile}'");
                generator.GenerateBindings(declarationUnit ?? translationUnit, sourceFile, clangArgs, bindingFlags);

                var bindingDiagnostics = generator.Diagnostics.ToArray();
                generator.Close();

                var generatedFiles = new Dictionary<string, string>();
                foreach (var kvp in capturedStreams)
                {
                    string generatedSource = Encoding.UTF8.GetString(kvp.Value.ToArray());
                    generatedSource = NormalizeGeneratedSource(generatedSource, kvp.Key);
                    generatedFiles[kvp.Key] = generatedSource;
                }
                if (annotations != null)
                {
                    annotations.PrepareProjections(generatedFiles.Values, config.RemappedNames);
                    foreach (string path in generatedFiles.Keys.ToArray())
                        generatedFiles[path] = annotations.Rewrite(generatedFiles[path]);
                }
                string additionalTypes = annotations?.GetAdditionalTypes();
                if (companion.Functions.Count != 0)
                {
                    var companionRemaps = new Dictionary<string, string>(mergedRemaps);
                    var included = companion.Functions.Select(function => function.Handle.CanonicalCursor).ToHashSet();
                    var companionAnnotations = parseHeaderAnnotations
                        ? new HeaderAnnotationProcessor(companion.Unit, companionRemaps, ns,
                            config.TraversalNames.ToArray(), allExcludes.ToHashSet(StringComparer.Ordinal),
                            configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.ExcludeFunctionsWithBody), included)
                        : null;
                    companionAnnotations?.PrepareTypedefs();
                    var companionDiscovery = RemapDiscovery.WalkTranslationUnit(companion.Unit.TranslationUnitDecl);
                    var companionOptions = (configOptions & ~PInvokeGeneratorConfigurationOptions.GenerateMacroBindings)
                        | PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute;
                    var companionConfig = CreateConfig(settings, ns, outputFile, headerFile, companionOptions,
                        RemapDiscovery.CreateBindingRemaps(companionDiscovery, companionRemaps, configuredAutoRemapExcludes),
                        allExcludes, companion.Functions.Select(function => function.Name).ToArray());
                    var companionStreams = new Dictionary<string, MemoryStream>();
                    using var companionGenerator = new PInvokeGenerator(companionConfig, path =>
                    {
                        var stream = new MemoryStream();
                        companionStreams[path] = stream;
                        return stream;
                    });
                    companionGenerator.GenerateBindings(companion.BindingUnit, sourceFile, companion.Arguments,
                        translationFlags & ~CXTranslationUnit_DetailedPreprocessingRecord);
                    var companionDiagnostics = companionGenerator.Diagnostics.ToArray();
                    companionGenerator.Close();
                    bindingDiagnostics = bindingDiagnostics.Concat(companionDiagnostics).ToArray();
                    if (companionDiagnostics.Any(diagnostic => diagnostic.Level == DiagnosticLevel.Error))
                    {
                        foreach (var diagnostic in bindingDiagnostics)
                            Console.WriteLine($"    {diagnostic}");
                        return -1;
                    }
                    var companionSources = CompanionImportProjection.Select(companionStreams.ToDictionary(
                        pair => pair.Key, pair => NormalizeGeneratedSource(Encoding.UTF8.GetString(pair.Value.ToArray()), pair.Key)),
                        companion.Functions, config.WithLibraryPaths);
                    companionAnnotations?.PrepareProjections(companionSources.Values, companionConfig.RemappedNames);
                    foreach (string path in companionSources.Keys.ToArray())
                        companionSources[path] = companionAnnotations?.Rewrite(companionSources[path]) ?? companionSources[path];
                    CompanionImportProjection.ValidateNoCollisions(generatedFiles.Values, companionSources.Values);
                    foreach (var pair in companionSources)
                    {
                        string source = pair.Value;
                        if (!configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute))
                            source = new SourceLocationRemover().Visit(SyntaxFactory.ParseCompilationUnit(source))
                                .NormalizeWhitespace().ToFullString() + Environment.NewLine;
                        generatedFiles[pair.Key] = generatedFiles.TryGetValue(pair.Key, out string existing)
                            ? MergeGeneratedSources(existing, source) : source;
                    }
                    companionAnnotations?.ValidateProjection();
                }
                var nativeRecords = new OpaqueRecordProjection(translationUnit,
                    generatedFiles.Values.Append(additionalTypes), config.RemappedNames, allExcludes);
                var recordProjections = new List<(OpaqueRecordProjection Projection, Dictionary<string, string> Remaps)>();
                if (configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords) &&
                    nativeRecords.IncludedNames.Count != 0)
                    recordProjections.Add((nativeRecords, mergedRemaps));
                foreach (var alias in nativeRecords.RecordAliases)
                {
                    var aliasRemaps = new Dictionary<string, string>(mergedRemaps)
                    {
                        [alias.RecordName] = alias.ManagedName,
                        [alias.Name] = alias.ManagedName
                    };
                    recordProjections.Add((nativeRecords.ForAlias(alias), aliasRemaps));
                }
                foreach (var projection in recordProjections)
                {
                    var opaqueRecords = projection.Projection;
                    if (opaqueRecords.IncludedNames.Count != 0)
                    {
                        var opaqueOptions = (configOptions
                            & ~PInvokeGeneratorConfigurationOptions.ExcludeEmptyRecords
                            & ~PInvokeGeneratorConfigurationOptions.GenerateMacroBindings)
                            | PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute;
                        var opaqueConfig = CreateConfig(settings, ns, outputFile, headerFile,
                            opaqueOptions, RemapDiscovery.CreateBindingRemaps(discovery, projection.Remaps, configuredAutoRemapExcludes),
                            allExcludes, opaqueRecords.IncludedNames,
                            opaqueRecords.TraversalFiles.Concat(config.TraversalNames).Distinct(StringComparer.OrdinalIgnoreCase).ToArray());
                        var opaqueStreams = new Dictionary<string, MemoryStream>();
                        using var opaqueGenerator = new PInvokeGenerator(opaqueConfig, path =>
                        {
                            var stream = new MemoryStream();
                            opaqueStreams[path] = stream;
                            return stream;
                        });
                        opaqueGenerator.GenerateBindings(declarationUnit ?? translationUnit, sourceFile, clangArgs, bindingFlags);
                        var opaqueDiagnostics = opaqueGenerator.Diagnostics.ToArray();
                        opaqueGenerator.Close();
                        bindingDiagnostics = bindingDiagnostics.Concat(opaqueDiagnostics).ToArray();
                        if (opaqueDiagnostics.Any(diagnostic => diagnostic.Level == DiagnosticLevel.Error))
                        {
                            foreach (var diagnostic in bindingDiagnostics)
                                Console.WriteLine($"    {diagnostic}");
                            return -1;
                        }
                        var opaqueSources = opaqueRecords.SelectRequiredBindings(opaqueStreams.ToDictionary(
                            pair => pair.Key, pair => NormalizeGeneratedSource(Encoding.UTF8.GetString(pair.Value.ToArray()), pair.Key)));
                        foreach (var pair in opaqueSources)
                        {
                            string source = annotations != null ? annotations.Rewrite(pair.Value) : pair.Value;
                            if (!configOptions.HasFlag(PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute))
                                source = new SourceLocationRemover().Visit(SyntaxFactory.ParseCompilationUnit(source))
                                    .NormalizeWhitespace().ToFullString() + Environment.NewLine;
                            generatedFiles[pair.Key] = generatedFiles.TryGetValue(pair.Key, out var existing)
                                ? MergeGeneratedSources(existing, source) : source;
                        }
                    }
                }
                var associatedConstantSources = new List<string>();
                if (annotations != null && !generateAllMacros)
                {
                    var macros = annotations.GetAssociatedConstantMacros();
                    if (macros.Count != 0)
                    {
                        string[] names = macros.Select(macro => macro.Name).ToArray();
                        var recovered = nativeConstants?.Constants.Where(value => names.Contains(value.NativeName, StringComparer.Ordinal))
                            .ToList() ?? new List<NativeConstantValue>();
                        string[] missing = names.Except(recovered.Select(value => value.NativeName), StringComparer.Ordinal).ToArray();
                        if (missing.Length != 0)
                        {
                            var selected = NativeConstantExtractor.Extract(translationUnit, sourceFile, clangArgs, config,
                                reportedNativeDiagnostics, missing);
                            recovered.AddRange(selected.Constants);
                            missing = missing.Except(selected.Constants.Select(value => value.NativeName), StringComparer.Ordinal).ToArray();
                            if (missing.Length != 0)
                                throw new InvalidOperationException("Associated constants have no valid native integer value: " +
                                    string.Join("; ", missing.Select(name => name + ": " +
                                        string.Join(", ", selected.Issues.Where(issue => issue.Name == name)
                                            .Select(issue => issue.Reason + " " + string.Join(" ", issue.Diagnostics))))));
                        }
                        using var stream = new MemoryStream();
                        using (var writer = new ConstantWriter(stream, config.DefaultNamespace,
                            "using Windows.Win32.Foundation.Metadata;", new Dictionary<string, string>(), config.DefaultClass))
                            foreach (var value in recovered.OrderBy(value => value.Name, StringComparer.Ordinal))
                                writer.AddNativeInteger(value);
                        associatedConstantSources.Add(Encoding.UTF8.GetString(stream.ToArray()));
                    }
                    ValidateAssociatedConstantSources(associatedConstantSources, macros.Select(macro =>
                        mergedRemaps.GetValueOrDefault(macro.Name) ?? macro.Name).ToArray(), config.DefaultClass);
                }
                if (associatedConstantSources.Count != 0)
                {
                    if (!string.IsNullOrEmpty(additionalTypes))
                        associatedConstantSources.Insert(0, additionalTypes);
                    var units = associatedConstantSources.Select(source => SyntaxFactory.ParseCompilationUnit(source)).ToArray();
                    additionalTypes = SyntaxFactory.CompilationUnit()
                        .AddUsings(units.SelectMany(unit => unit.Usings).GroupBy(value => value.ToString())
                            .Select(group => group.First()).ToArray())
                        .AddMembers(units.SelectMany(unit => unit.Members).ToArray())
                        .NormalizeWhitespace().ToFullString() + Environment.NewLine;
                }
                annotations?.ValidateProjection();
                if (annotations != null)
                    generatedFiles[additionalTypesPath] = HeaderTypesSourceFamily.SuccessMarker + Environment.NewLine +
                        (additionalTypes ?? string.Empty);

                // Write diagnostics
                foreach (var diag in bindingDiagnostics)
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
                if (exitCode < 0)
                    return exitCode;

                if (nativeConstants != null)
                {
                    generatedFiles[nativeConstantsPath] = JsonSerializer.Serialize(nativeConstants);
                    Console.WriteLine($"Native constants: {nativeConstants.Constants.Count} integers; {nativeConstants.Issues.Count} other definitions. Details: {nativeConstantsPath}");
                }
                foreach (var file in generatedFiles)
                {
                    string directory = Path.GetDirectoryName(file.Key);
                    if (!string.IsNullOrEmpty(directory))
                        Directory.CreateDirectory(directory);
                    string temporaryPath = file.Key + "." + Guid.NewGuid().ToString("N") + ".tmp";
                    try
                    {
                        File.WriteAllText(temporaryPath, file.Value, new UTF8Encoding(false));
                        File.Move(temporaryPath, file.Key, overwrite: true);
                    }
                    finally
                    {
                        if (File.Exists(temporaryPath))
                            File.Delete(temporaryPath);
                    }
                }
                if (annotations == null && File.Exists(additionalTypesPath))
                    File.Delete(additionalTypesPath);
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
            else if (File.Exists(remapsOutputPath))
            {
                File.Delete(remapsOutputPath);
            }

            companion.CompleteProjection();
            return exitCode;
        }
        catch (HeaderAnnotationDiagnosticsException ex)
        {
            Console.Error.WriteLine(ex.Message);
            return -1;
        }
        catch (Exception ex)
        {
            Console.Error.WriteLine($"Error: {ex.Message}");
            Console.Error.WriteLine(ex.StackTrace);
            return -1;
        }
    }

    static TranslationUnit ParseTranslationUnit(CXIndex index, string sourceFile, string[] clangArgs,
        CXTranslationUnit_Flags flags, HashSet<string> reportedDiagnostics)
    {
        var parseError = CXTranslationUnit.TryParse(index, sourceFile, clangArgs,
            ReadOnlySpan<CXUnsavedFile>.Empty, flags, out var handle);
        if (parseError != CXError_Success)
        {
            Console.Error.WriteLine($"Error: Failed to parse '{sourceFile}': {parseError}");
            return null;
        }
        bool skipProcessing = false;
        var previousDiagnostics = new HashSet<string>(reportedDiagnostics, StringComparer.Ordinal);
        if (handle.NumDiagnostics != 0)
        {
            bool wroteHeading = false;
            for (uint i = 0; i < handle.NumDiagnostics; i++)
            {
                using var diagnostic = handle.GetDiagnostic(i);
                string text = diagnostic.Format(CXDiagnostic.DefaultDisplayOptions).ToString();
                // The declaration-only parse must still validate every diagnostic,
                // but must not report the same native warning a second time.
                if (!previousDiagnostics.Contains(text))
                {
                    if (!wroteHeading)
                    {
                        Console.WriteLine($"Diagnostics for '{sourceFile}':");
                        wroteHeading = true;
                    }
                    Console.WriteLine($"    {text}");
                }
                reportedDiagnostics.Add(text);
                skipProcessing |= diagnostic.Severity is CXDiagnostic_Error or CXDiagnostic_Fatal;
            }
        }
        if (skipProcessing)
        {
            Console.Error.WriteLine($"Skipping '{sourceFile}' due to one or more errors listed above.");
            handle.Dispose();
            return null;
        }
        return TranslationUnit.GetOrCreate(handle);
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
        List<string> excludes,
        IReadOnlyCollection<string> includedNames = null,
        IReadOnlyCollection<string> traversalNames = null)
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
            TraversalNames = traversalNames ?? settings.GetValueOrDefault("--traverse")?.ToArray() ?? Array.Empty<string>(),
            IncludedNames = includedNames ?? Array.Empty<string>(),
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

    static void ValidateAssociatedConstantSources(IEnumerable<string> sources, string[] expectedNames, string defaultClass)
    {
        if (expectedNames.Distinct(StringComparer.Ordinal).Count() != expectedNames.Length)
            throw new InvalidOperationException("AssociatedConstant macro remappings must preserve distinct constant names.");
        var roots = sources.Select(source => SyntaxFactory.ParseCompilationUnit(source)).ToArray();
        var fields = roots.SelectMany(root => root.DescendantNodes().OfType<FieldDeclarationSyntax>()).ToArray();
        var names = fields.SelectMany(field => field.Declaration.Variables.Select(variable => variable.Identifier.ValueText)).ToArray();
        if (!names.OrderBy(name => name, StringComparer.Ordinal).SequenceEqual(expectedNames.OrderBy(name => name, StringComparer.Ordinal)) ||
            roots.SelectMany(root => root.DescendantNodes().OfType<BaseTypeDeclarationSyntax>())
                .Any(type => type is not ClassDeclarationSyntax || type.Identifier.ValueText != defaultClass) ||
            roots.Any(root => root.DescendantNodes().OfType<BaseMethodDeclarationSyntax>().Any()))
            throw new InvalidOperationException("Selective AssociatedConstant macro binding must emit only the requested global fields.");
        foreach (var field in fields)
            if (!field.Modifiers.Any(SyntaxKind.ConstKeyword) || field.Declaration.Variables.Any(variable => variable.Initializer == null))
                throw new InvalidOperationException("An AssociatedConstant macro must project to a constant field; readonly or pointer bindings cannot suppress the existing constant fallback.");
    }

    static string MergeGeneratedSources(string first, string second)
    {
        var roots = new[] { first, second }.Select(source =>
            (CompilationUnitSyntax)new BlockNamespaceRewriter().Visit(SyntaxFactory.ParseCompilationUnit(source))).ToArray();
        return roots[0].WithUsings(SyntaxFactory.List(roots.SelectMany(root => root.Usings)
                .GroupBy(value => value.ToString()).Select(group => group.First())))
            .WithMembers(MergeMemberScopes(roots[0].Members, roots[1].Members))
            .NormalizeWhitespace().ToFullString() + Environment.NewLine;
    }

    static SyntaxList<MemberDeclarationSyntax> MergeMemberScopes(
        SyntaxList<MemberDeclarationSyntax> first, SyntaxList<MemberDeclarationSyntax> second)
    {
        var members = first.ToList();
        foreach (var addition in second)
        {
            int index = members.FindIndex(existing => (existing, addition) switch
            {
                (NamespaceDeclarationSyntax left, NamespaceDeclarationSyntax right) => left.Name.ToString() == right.Name.ToString(),
                (TypeDeclarationSyntax left, TypeDeclarationSyntax right) => left.Kind() == right.Kind() &&
                    left.Identifier.ValueText == right.Identifier.ValueText &&
                    (left.TypeParameterList?.Parameters.Count ?? 0) == (right.TypeParameterList?.Parameters.Count ?? 0),
                _ => false,
            });
            if (index < 0)
                members.Add(addition);
            else if (members[index] is NamespaceDeclarationSyntax ns && addition is NamespaceDeclarationSyntax addedNamespace)
                members[index] = ns.WithUsings(SyntaxFactory.List(ns.Usings.Concat(addedNamespace.Usings)
                        .GroupBy(value => value.ToString()).Select(group => group.First())))
                    .WithMembers(MergeMemberScopes(ns.Members, addedNamespace.Members));
            else if (members[index] is TypeDeclarationSyntax type && addition is TypeDeclarationSyntax addedType)
                members[index] = type.WithMembers(MergeMemberScopes(type.Members, addedType.Members));
        }
        return SyntaxFactory.List(members);
    }

    sealed class BlockNamespaceRewriter : CSharpSyntaxRewriter
    {
        public override SyntaxNode VisitFileScopedNamespaceDeclaration(FileScopedNamespaceDeclarationSyntax node)
            => SyntaxFactory.NamespaceDeclaration(node.Name).WithExterns(node.Externs).WithUsings(node.Usings)
                .WithMembers(node.Members).WithTriviaFrom(node);
    }

    sealed class SourceLocationRemover : CSharpSyntaxRewriter
    {
        public override SyntaxNode VisitAttributeList(AttributeListSyntax node)
        {
            var retained = SyntaxFactory.SeparatedList(node.Attributes.Where(attribute =>
                attribute.Name.ToString().Split('.').Last() is not "SourceLocation" and not "SourceLocationAttribute"));
            return retained.Count == 0 ? null : node.WithAttributes(retained);
        }
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
                    "parse-win32-annotations" => PInvokeGeneratorConfigurationOptions.GenerateSourceLocationAttribute,
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

    static Dictionary<string, List<string>> LoadAutoRemaps(Dictionary<string, List<string>> settings, bool parseHeaderAnnotations)
    {
        var derivedSettings = new Dictionary<string, List<string>>(StringComparer.OrdinalIgnoreCase);
        if (!settings.TryGetValue("--auto-remaps-file", out var paths))
            return derivedSettings;
        if (paths.Count == 0)
            throw new InvalidDataException("Missing path for --auto-remaps-file.");

        foreach (string value in paths)
        {
            string path = value.Trim('"');
            if (!File.Exists(path))
                throw new FileNotFoundException("Auto-remaps response file not found.", path);
            if (parseHeaderAnnotations)
            {
                Console.WriteLine($"Ignoring globally discovered remaps for annotated headers: {path}");
                continue;
            }
            ParseRspFile(path, derivedSettings);
        }

        foreach (var pair in derivedSettings)
        {
            if (!pair.Key.Equals("--remap", StringComparison.OrdinalIgnoreCase)
                && !pair.Key.Equals("--exclude", StringComparison.OrdinalIgnoreCase))
                throw new InvalidDataException($"Unsupported auto-remaps option: {pair.Key}");
        }
        return derivedSettings;
    }

    static void ParseRspFile(string path, Dictionary<string, List<string>> settings)
    {
        if (!File.Exists(path))
            throw new FileNotFoundException($"Response file not found: '{path}'.", path);
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
