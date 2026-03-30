// ClangSharpWorker: Process-isolated wrapper around PInvokeGenerator.
//
// Two-phase operation in a single process:
//   Phase 1 (Discovery): Runs PInvokeGenerator to discover typedef-tag remaps
//     from _allValidNameRemappings. Output is discarded.
//   Phase 2 (Generation): Runs PInvokeGenerator again with discovered remaps
//     injected into RemappedNames. Produces final C# output with correct names.
//
// Usage: dotnet ClangSharpWorker.dll <toolDir> <remapsOutputPath> @rsp1 @rsp2 ...

using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Reflection.Emit;
using System.Runtime.InteropServices;

class Program
{
    static Assembly s_interopAsm;
    static Assembly s_clangSharpAsm;
    static Assembly s_pinvokeGenAsm;
    static Func<object, string, string[], int, object[]> s_tryParseDelegate;

    static int Main(string[] args)
    {
        if (args.Length < 3)
        {
            Console.Error.WriteLine("Usage: dotnet ClangSharpWorker.dll <toolDir> <remapsOutputPath> @rsp1 @rsp2 ...");
            return 1;
        }

        string toolDir = args[0];
        string remapsOutputPath = args[1];
        string[] rspArgs = args.Skip(2).ToArray();

        try
        {
            // Load assemblies and native libraries once
            s_interopAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.Interop.dll"));
            s_clangSharpAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.dll"));
            s_pinvokeGenAsm = Assembly.LoadFrom(Path.Combine(toolDir, "ClangSharp.PInvokeGenerator.dll"));
            NativeLibrary.Load(Path.Combine(toolDir, "libclang.dll"));
            NativeLibrary.Load(Path.Combine(toolDir, "libClangSharp.dll"));
            s_tryParseDelegate = BuildTryParseDelegate(s_interopAsm);

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
            long optionsValue = BuildOptionsFlags(settings);
            var configuredRemaps = ParseKeyValuePairs(settings.GetValueOrDefault("--remap"));

            // === Phase 1: Discovery ===
            // Run PInvokeGenerator with existing remaps to discover typedef-tag relationships.
            // Output is discarded (written to MemoryStream but not saved to disk).
            var discoveredRemaps = RunDiscoveryPhase(
                settings, sourceFile, outputFile, ns, headerFile,
                clangArgs, optionsValue, configuredRemaps);

            // Filter discovered remaps using heuristic and merge with configured remaps
            var autoRemaps = FilterRemaps(discoveredRemaps, configuredRemaps);

            // Merge: auto-discovered remaps + original configured remaps
            // Configured remaps take priority (they may have semantic overrides)
            var mergedRemaps = new Dictionary<string, string>(autoRemaps);
            foreach (var kv in configuredRemaps)
                mergedRemaps[kv.Key] = kv.Value;

            // === Phase 2: Generation ===
            // Run PInvokeGenerator again with the full merged remap set.
            // This time output IS written to disk.
            int exitCode = RunGenerationPhase(
                settings, sourceFile, outputFile, ns, headerFile,
                clangArgs, optionsValue, mergedRemaps);

            // Write discovered remaps to sidecar file
            if (autoRemaps.Count > 0)
            {
                var remapDir = Path.GetDirectoryName(remapsOutputPath);
                if (!string.IsNullOrEmpty(remapDir))
                    Directory.CreateDirectory(remapDir);

                using var writer = new StreamWriter(remapsOutputPath);
                foreach (var kv in autoRemaps.OrderBy(kv => kv.Key, StringComparer.OrdinalIgnoreCase))
                    writer.WriteLine($"{kv.Key}={kv.Value}");
            }

            return exitCode;
        }
        catch (Exception ex)
        {
            var inner = ex is TargetInvocationException tie ? tie.InnerException : ex;
            Console.Error.WriteLine($"Error: {inner?.Message ?? ex.Message}");
            return 1;
        }
    }

    /// <summary>
    /// Phase 1: Run PInvokeGenerator to discover typedef-tag remaps.
    /// Output is discarded. Returns the discovered remaps dictionary.
    /// </summary>
    static Dictionary<string, string> RunDiscoveryPhase(
        Dictionary<string, List<string>> settings,
        string sourceFile, string outputFile, string ns, string headerFile,
        List<string> clangArgs, long optionsValue,
        Dictionary<string, string> configuredRemaps)
    {
        var result = new Dictionary<string, string>();
        var genType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGenerator");
        var configType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfiguration");

        var config = CreateConfig(settings, configType, ns, outputFile, headerFile, optionsValue, configuredRemaps);

        // Use /dev/null-style stream factory — discard all output
        Func<string, Stream> streamFactory = (_) => new MemoryStream();
        var generator = Activator.CreateInstance(genType, new object[] { config, streamFactory });

        try
        {
            if (!TryParseAndGenerate(generator, genType, sourceFile, clangArgs))
                return result;

            // Don't write output — just extract remaps
            genType.GetMethod("Close").Invoke(generator, null);

            // Read _allValidNameRemappings
            var remappingsField = genType.GetField("_allValidNameRemappings",
                BindingFlags.NonPublic | BindingFlags.Instance);
            if (remappingsField != null)
            {
                var allRemappings = remappingsField.GetValue(generator) as IDictionary;
                if (allRemappings != null)
                {
                    foreach (DictionaryEntry entry in allRemappings)
                    {
                        string tagName = (string)entry.Key;
                        var typedefNames = entry.Value as IEnumerable<string>;
                        string preferredName = typedefNames?.FirstOrDefault();
                        if (preferredName != null && tagName != preferredName)
                            result[tagName] = preferredName;
                    }
                }
            }
        }
        finally
        {
            if (generator is IDisposable disposable)
                disposable.Dispose();
        }

        return result;
    }

    /// <summary>
    /// Phase 2: Run PInvokeGenerator with merged remaps. Output IS written to disk.
    /// </summary>
    static int RunGenerationPhase(
        Dictionary<string, List<string>> settings,
        string sourceFile, string outputFile, string ns, string headerFile,
        List<string> clangArgs, long optionsValue,
        Dictionary<string, string> mergedRemaps)
    {
        var genType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGenerator");
        var configType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfiguration");

        var config = CreateConfig(settings, configType, ns, outputFile, headerFile, optionsValue, mergedRemaps);

        var capturedStreams = new Dictionary<string, MemoryStream>();
        Func<string, Stream> streamFactory = (path) =>
        {
            var ms = new MemoryStream();
            capturedStreams[path] = ms;
            return ms;
        };
        var generator = Activator.CreateInstance(genType, new object[] { config, streamFactory });

        try
        {
            if (!TryParseAndGenerate(generator, genType, sourceFile, clangArgs))
                return -1;

            genType.GetMethod("Close").Invoke(generator, null);

            // Write output to disk
            foreach (var kvp in capturedStreams)
            {
                var dir = Path.GetDirectoryName(kvp.Key);
                if (!string.IsNullOrEmpty(dir))
                    Directory.CreateDirectory(dir);
                File.WriteAllBytes(kvp.Key, kvp.Value.ToArray());
            }

            // Write diagnostics
            var diagnostics = (IEnumerable)genType.GetProperty("Diagnostics").GetValue(generator);
            foreach (var diag in diagnostics)
                Console.WriteLine($"    {diag}");

            return 0;
        }
        finally
        {
            if (generator is IDisposable disposable)
                disposable.Dispose();
        }
    }

    static bool TryParseAndGenerate(object generator, Type genType, string sourceFile, List<string> clangArgs)
    {
        var indexHandle = genType.GetProperty("IndexHandle").GetValue(generator);

        var flagsType = s_interopAsm.GetType("ClangSharp.Interop.CXTranslationUnit_Flags");
        long flagsValue = Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_IncludeAttributedTypes"))
                        | Convert.ToInt64(Enum.Parse(flagsType, "CXTranslationUnit_VisitImplicitAttributes"));
        var flags = Enum.ToObject(flagsType, flagsValue);

        var tryParseResult = s_tryParseDelegate(
            indexHandle, sourceFile, clangArgs.ToArray(), (int)flagsValue);
        var parseResult = tryParseResult[0];
        var cxTU = tryParseResult[1];

        if (parseResult.ToString() != "CXError_Success")
        {
            Console.Error.WriteLine($"Error: Failed to parse {sourceFile}: {parseResult}");
            return false;
        }

        var tuType = s_clangSharpAsm.GetType("ClangSharp.TranslationUnit");
        var getOrCreate = tuType.GetMethod("GetOrCreate", BindingFlags.Public | BindingFlags.Static);
        var translationUnit = getOrCreate.Invoke(null, new[] { cxTU });

        try
        {
            genType.GetMethod("GenerateBindings").Invoke(generator, new[] {
                translationUnit, sourceFile, clangArgs.ToArray(), flags
            });
        }
        catch (TargetInvocationException tie) when (tie.InnerException is ArgumentException ae
            && ae.Message.Contains("diagnostics which prevent"))
        {
            Console.Error.WriteLine($"Error: {ae.Message}");
            return false;
        }

        return true;
    }

    static object CreateConfig(
        Dictionary<string, List<string>> settings,
        Type configType, string ns, string outputFile, string headerFile,
        long optionsValue, Dictionary<string, string> remaps)
    {
        var outputModeType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorOutputMode");
        var optionsType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfigurationOptions");

        var config = Activator.CreateInstance(configType, new object[] {
            "c++", "c++17", ns, outputFile, headerFile ?? string.Empty,
            Enum.Parse(outputModeType, "CSharp"),
            Enum.ToObject(optionsType, optionsValue)
        });

        SetProperty(configType, config, "TraversalNames",
            (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--traverse")?.ToArray() ?? Array.Empty<string>()));
        SetProperty(configType, config, "ExcludedNames",
            (IReadOnlyCollection<string>)(settings.GetValueOrDefault("--exclude")?.ToArray() ?? Array.Empty<string>()));
        SetProperty(configType, config, "RemappedNames",
            (IReadOnlyDictionary<string, string>)remaps);
        SetProperty(configType, config, "WithAttributes",
            ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-attribute")));
        SetProperty(configType, config, "WithTypes",
            ParseKeyValuePairs(settings.GetValueOrDefault("--with-type")));
        SetProperty(configType, config, "WithLibraryPaths",
            ParseKeyValuePairs(settings.GetValueOrDefault("--with-librarypath")));
        SetProperty(configType, config, "WithCallConvs",
            ParseKeyValuePairs(settings.GetValueOrDefault("--with-callconv")));
        SetProperty(configType, config, "WithUsings",
            ParseKeyValueMultiPairs(settings.GetValueOrDefault("--with-using")));

        if (settings.TryGetValue("--methodClassName", out var classNames) && classNames.Count > 0)
            configType.GetProperty("DefaultClass").SetValue(config, classNames.Last());

        return config;
    }

    static List<string> BuildClangArgs(Dictionary<string, List<string>> settings)
    {
        var clangArgs = new List<string> { "--language=c++", "--std=c++17" };
        if (settings.TryGetValue("--include-directory", out var incDirs))
            foreach (var dir in incDirs)
                clangArgs.Add($"--include-directory={dir}");
        if (settings.TryGetValue("--additional", out var additionals))
            clangArgs.AddRange(additionals);
        return clangArgs;
    }

    static long BuildOptionsFlags(Dictionary<string, List<string>> settings)
    {
        var optionsType = s_pinvokeGenAsm.GetType("ClangSharp.PInvokeGeneratorConfigurationOptions");
        long optionsValue = 0;
        if (settings.TryGetValue("--config", out var configs))
        {
            foreach (var cfg in configs)
            {
                string fieldName = MapConfigToFieldName(cfg);
                if (fieldName != null)
                {
                    var field = optionsType.GetField(fieldName);
                    if (field != null)
                        optionsValue |= Convert.ToInt64(field.GetValue(null));
                }
            }
        }
        return optionsValue;
    }

    /// <summary>
    /// Filters discovered remaps using heuristic rules:
    /// 1. Skip built-in defaults (intptr_t, _GUID, etc.)
    /// 2. Skip identity remaps (tag == typedef)
    /// 3. Skip if typedef looks worse than tag (adds _ prefix)
    /// 4. Tag must look internal: starts with _, tag, __MIDL, ABI::, lowercase, or ends with _
    /// 5. Skip entries where configured --remap has a DIFFERENT value (semantic override)
    /// </summary>
    static Dictionary<string, string> FilterRemaps(
        Dictionary<string, string> discovered,
        Dictionary<string, string> configuredRemaps)
    {
        var builtins = new HashSet<string> { "intptr_t", "ptrdiff_t", "size_t", "uintptr_t", "_GUID" };
        var result = new Dictionary<string, string>();

        foreach (var kv in discovered)
        {
            string tag = kv.Key;
            string typedef = kv.Value;

            if (builtins.Contains(tag)) continue;
            if (tag == typedef) continue;
            if (!tag.StartsWith("_") && typedef.StartsWith("_")) continue;

            // Skip if configured remap has a different value (semantic override wins)
            if (configuredRemaps.TryGetValue(tag, out string configuredValue) && configuredValue != typedef)
                continue;

            // Tag must look like an internal/compiler-generated name
            bool looksInternal =
                (tag.Length > 1 && tag[0] == '_' && (char.IsUpper(tag[1]) || tag[1] == '_')) ||
                (tag.StartsWith("tag") && tag.Length > 3 && char.IsUpper(tag[3])) ||
                tag.StartsWith("__MIDL") || tag.StartsWith("__Anonymous") ||
                tag.StartsWith("ABI::") ||
                (tag.Length > 0 && char.IsLower(tag[0])) ||
                tag.EndsWith("_");

            if (!looksInternal) continue;

            result[tag] = typedef;
        }

        return result;
    }

    static void ParseRspFile(string path, Dictionary<string, List<string>> settings)
    {
        if (!File.Exists(path)) return;
        string currentSwitch = null;
        foreach (var rawLine in File.ReadLines(path))
        {
            string line = rawLine.Trim();
            if (string.IsNullOrEmpty(line)) continue;
            if (line.StartsWith("--"))
            {
                currentSwitch = line;
                if (!settings.ContainsKey(currentSwitch))
                    settings[currentSwitch] = new List<string>();
            }
            else if (currentSwitch != null)
                settings[currentSwitch].Add(line);
        }
    }

    static void SetProperty(Type type, object obj, string name, object value)
    {
        var prop = type.GetProperty(name);
        if (prop != null && prop.CanWrite)
            prop.SetValue(obj, value);
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
                {
                    list = new List<string>();
                    temp[key] = list;
                }
                list.Add(val);
            }
        }
        foreach (var kv in temp)
            dict[kv.Key] = kv.Value;
        return dict;
    }

    static string MapConfigToFieldName(string configName) => configName switch
    {
        "compatible-codegen" => "GenerateCompatibleCode",
        "log-visited-files" => "LogVisitedFiles",
        "log-exclusions" => "LogExclusions",
        "log-potential-typedef-remappings" => "LogPotentialTypedefRemappings",
        "exclude-funcs-with-body" => "ExcludeFunctionsWithBody",
        "generate-cpp-attributes" => "GenerateCppAttributes",
        "generate-native-bitfield-attribute" => "GenerateNativeBitfieldAttribute",
        "generate-native-inheritance-attribute" => "GenerateNativeInheritanceAttribute",
        "dont-use-using-statics-for-enums" => "DontUseUsingStaticsForEnums",
        "exclude-anonymous-field-helpers" => "ExcludeAnonymousFieldHelpers",
        "exclude-empty-records" => "ExcludeEmptyRecords",
        "exclude-enum-operators" => "ExcludeEnumOperators",
        "exclude-com-proxies" => "ExcludeComProxies",
        "generate-marker-interfaces" => "GenerateMarkerInterfaces",
        "generate-explicit-vtbls" => "GenerateExplicitVtbls",
        "generate-trimmable-vtbls" => "GenerateTrimmableVtbls",
        "generate-aggressive-inlining" => "GenerateAggressiveInlining",
        "multi-file" => "GenerateMultipleFiles",
        "generate-macro-bindings" => "GenerateMacroBindings",
        "generate-file-scoped-namespaces" => "GenerateFileScopedNamespaces",
        "generate-disable-runtime-marshalling" => "GenerateDisableRuntimeMarshalling",
        "generate-guid-member" => "GenerateGuidMember",
        "generate-helper-types" => "GenerateHelperTypes",
        "generate-vtbl-index-attribute" => "GenerateVtblIndexAttribute",
        "generate-setslasterror-attribute" => "GenerateSetsLastSystemErrorAttribute",
        "generate-unmanaged-constants" => "GenerateUnmanagedConstants",
        "generate-latest-code" => "GenerateLatestCode",
        "generate-template-bindings" => "GenerateTemplateBindings",
        "generate-source-location-attribute" => "GenerateSourceLocationAttribute",
        "generate-callconv-member-function" => "GenerateCallConvMemberFunction",
        "generate-doc-includes" => "GenerateDocIncludes",
        "preview-codegen" => "GeneratePreviewCode",
        "unix-types" => "GenerateUnixTypes",
        _ => null
    };

    static Func<object, string, string[], int, object[]> BuildTryParseDelegate(Assembly interopAsm)
    {
        var cxIndexType = interopAsm.GetType("ClangSharp.Interop.CXIndex");
        var cxTUType = interopAsm.GetType("ClangSharp.Interop.CXTranslationUnit");
        var errorCodeType = interopAsm.GetType("ClangSharp.Interop.CXErrorCode");
        var unsavedFileType = interopAsm.GetType("ClangSharp.Interop.CXUnsavedFile");

        var spanStringType = typeof(ReadOnlySpan<>).MakeGenericType(typeof(string));
        var spanUnsavedType = typeof(ReadOnlySpan<>).MakeGenericType(unsavedFileType);
        var tryParseMethod = cxTUType.GetMethod("TryParse", BindingFlags.Public | BindingFlags.Static);
        var opImplicitString = spanStringType.GetMethod("op_Implicit",
            BindingFlags.Public | BindingFlags.Static, null, new[] { typeof(string[]) }, null);
        var emptyUnsavedGetter = spanUnsavedType.GetProperty("Empty",
            BindingFlags.Public | BindingFlags.Static).GetGetMethod();

        var dm = new DynamicMethod("CallTryParse", typeof(object[]),
            new[] { typeof(object), typeof(string), typeof(string[]), typeof(int) },
            typeof(Program).Module, true);
        var il = dm.GetILGenerator();
        var cxTULocal = il.DeclareLocal(cxTUType);
        var errorLocal = il.DeclareLocal(errorCodeType);
        var resultLocal = il.DeclareLocal(typeof(object[]));

        il.Emit(OpCodes.Ldarg_0); il.Emit(OpCodes.Unbox_Any, cxIndexType);
        il.Emit(OpCodes.Ldarg_1);
        il.Emit(OpCodes.Ldarg_2); il.EmitCall(OpCodes.Call, opImplicitString, null);
        il.EmitCall(OpCodes.Call, emptyUnsavedGetter, null);
        il.Emit(OpCodes.Ldarg_3);
        il.Emit(OpCodes.Ldloca_S, cxTULocal);
        il.EmitCall(OpCodes.Call, tryParseMethod, null);
        il.Emit(OpCodes.Stloc, errorLocal);

        il.Emit(OpCodes.Ldc_I4_2); il.Emit(OpCodes.Newarr, typeof(object)); il.Emit(OpCodes.Stloc, resultLocal);
        il.Emit(OpCodes.Ldloc, resultLocal); il.Emit(OpCodes.Ldc_I4_0);
        il.Emit(OpCodes.Ldloc, errorLocal); il.Emit(OpCodes.Box, errorCodeType); il.Emit(OpCodes.Stelem_Ref);
        il.Emit(OpCodes.Ldloc, resultLocal); il.Emit(OpCodes.Ldc_I4_1);
        il.Emit(OpCodes.Ldloc, cxTULocal); il.Emit(OpCodes.Box, cxTUType); il.Emit(OpCodes.Stelem_Ref);
        il.Emit(OpCodes.Ldloc, resultLocal); il.Emit(OpCodes.Ret);

        return (Func<object, string, string[], int, object[]>)dm.CreateDelegate(
            typeof(Func<object, string, string[], int, object[]>));
    }
}
